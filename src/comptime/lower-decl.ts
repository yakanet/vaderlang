// Compile a single `@comptime` decl to a self-contained `BytecodeModule` by
// reusing the regular pipeline's `lowerExpr` / `lowerBlock` / `emitBytecode`
// passes. The result feeds directly into `runComptimeDecl`, which runs the
// module on the host VM and converts the resulting Value back into a
// ComptimeValue.
//
// Reachability: `lowerExpr` produces a `LoweredFnDecl` for the synthetic
// `__comptime_main` whose body wraps `decl.value`. We then walk the body to
// discover user fns and cross-`@comptime` const refs, lower each, and bundle
// them into a synthetic `LoweredProject` for `emitBytecode`.

import type * as A from "../parser/ast.ts";
import { UNASSIGNED_NODE_ID } from "../parser/ast.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
import type { ImplRegistry } from "../typecheck/impls.ts";
import type { Type } from "../typecheck/types.ts";
import { TY, defaultIfFree } from "../typecheck/types.ts";

import type {
  LoweredBlock, LoweredDecl, LoweredExpr, LoweredFnDecl, LoweredModule,
  LoweredProject, LoweredStmt,
} from "../lower/lowered-ast.ts";
import type { FnLowerCtx, LowerProjectCtx } from "../lower/ctx.ts";
import { makeEntryTypes } from "../lower/entry-types.ts";
import { lowerExpr } from "../lower/passes/expr.ts";
import { inlineConsts } from "../lower/passes/inline-consts.ts";
import { lowerConstEntry, lowerFnEntry } from "../lower/lower.ts";

import type { MonoEntry, MonoProject } from "./specialize.ts";
import { mangle } from "./specialize.ts";

import type { BytecodeModule } from "../bytecode/module.ts";
import { emitBytecodeFromCFG } from "../midir/emit.ts";
import { buildCFGProject } from "../midir/build.ts";
import { eliminateDeadCFG } from "../midir/dce.ts";
import { annotateEscape } from "../midir/escape.ts";

import type { EvaluatedProject } from "./evaluated-ast.ts";
import type { ComptimeValue } from "./value.ts";

const SYNTH_MAIN_NAME = "__comptime_main";
const EMPTY_SUBST = Object.freeze({ typeParams: undefined, self: undefined });

export interface CompileInput {
  readonly decl: A.ConstDecl;
  readonly project: TypedProject;
  readonly callerProgram: TypedProgram;
  readonly evaluated: ReadonlyMap<A.ConstDecl, ComptimeValue>;
  readonly diags: DiagnosticCollector;
  /** Live overlay of baked comptime/file values, shared across modules and
   *  updated as the comptime loop progresses. Built once by `evaluateProject`. */
  readonly liveEvaluated: EvaluatedProject;
  /** Whole-project impl registry, built once by `evaluateProject`. */
  readonly projectImpls: ImplRegistry;
}

export interface CompileOutput {
  readonly module: BytecodeModule;
  readonly mainFnIndex: number;
  readonly resultType: Type;
  /** `${fnIndex}:${opIndex}` → Span for VM trap reporting. Empty until the
   *  emitter exposes its debug map across the boundary. */
  readonly spanByOp: ReadonlyMap<string, Span>;
}

export function lowerComptimeDecl(input: CompileInput): CompileOutput | null {
  const decl = input.decl;
  const callerProgram = input.callerProgram;
  const resultType = callerProgram.exprTypes.get(decl.value)
    ?? callerProgram.declTypes.get(decl)
    ?? TY.unresolved;

  const projectCtx = newLowerProjectCtx(input);
  const synthFn = synthMainFnDecl(decl);
  const synthSym = synthSymbol(synthFn, projectCtx);
  const mainEntry = makeMonoEntry(SYNTH_MAIN_NAME, synthFn, synthSym, callerProgram);
  const fnCtx: FnLowerCtx = {
    project: projectCtx, entry: mainEntry, typed: callerProgram, subst: EMPTY_SUBST,
    types: makeEntryTypes(callerProgram, EMPTY_SUBST),
    returnType: defaultIfFree(resultType), selfType: null,
    blocks: [], uniq: 0, liftedContext: null,
  };

  const value = lowerExpr(fnCtx, decl.value);
  const mainFnDecl: LoweredFnDecl = {
    kind: "LoweredFnDecl", mangled: SYNTH_MAIN_NAME, params: [],
    returnType: defaultIfFree(resultType),
    body: { kind: "LoweredBlock", span: decl.value.span, type: value.type, stmts: [], trailing: value },
    origin: mainEntry,
  };

  const reachable = lowerReachableDecls(mainFnDecl, projectCtx, input);
  if (reachable === null) return null;

  const project = inlineConsts(
    bundleProject(input, callerProgram.resolved.module.id, mainFnDecl, reachable),
  ).project;
  const cfg = annotateEscape(eliminateDeadCFG(buildCFGProject(project))).project;
  const bytecodeModule = emitBytecodeFromCFG(cfg, "__comptime__", {
    optimize: true, implRegistry: projectCtx.impls,
  });
  const mainFnIndex = bytecodeModule.functions.findIndex((f) => f.name === SYNTH_MAIN_NAME);
  if (mainFnIndex < 0) return null;

  return { module: bytecodeModule, mainFnIndex, resultType, spanByOp: new Map() };
}

// ---------------------------------------------------------- reachability walk

/** Walk the synthetic main body for fn callees and const refs, lower each
 *  one (delegating to `lowerFnEntry` / `lowerConstEntry`), then walk new fn
 *  bodies too — until convergence. Each result is tagged with its source
 *  module id for per-module grouping in the LoweredProject. */
function lowerReachableDecls(
  mainDecl: LoweredFnDecl, projectCtx: LowerProjectCtx, input: CompileInput,
): { moduleId: string; decl: LoweredDecl }[] | null {
  const result: { moduleId: string; decl: LoweredDecl }[] = [];
  const seen = new Set<number>();
  const worklist: Symbol[] = [];
  if (mainDecl.body !== null) collectRefs(mainDecl.body, seen, worklist);

  while (worklist.length > 0) {
    const sym = worklist.pop()!;          // order doesn't matter; `seen` enforces uniqueness
    const owner = input.project.modules.get(sym.module);
    if (owner === undefined) continue;
    const entry = entryFor(sym, owner);
    if (entry === null) continue;
    const decl = sym.source.kind === "fn"
      ? lowerFnEntry(entry, sym.source.decl, projectCtx, /*selfType*/ null)
      : lowerConstEntry(entry, entry.decl as A.ConstDecl, projectCtx);
    if (decl === null) continue;
    result.push({ moduleId: owner.resolved.module.id, decl });
    if (decl.kind === "LoweredFnDecl" && decl.body !== null) collectRefs(decl.body, seen, worklist);
  }
  return result;
}

function entryFor(sym: Symbol, owner: TypedProgram): MonoEntry | null {
  if (sym.source.kind === "fn") {
    if (sym.source.decl.body === null) return null;
    return makeMonoEntry(mangle(sym.source.decl.name, owner.resolved, []), sym.source.decl, sym, owner);
  }
  if (sym.source.kind === "const") {
    return makeMonoEntry(mangle(sym.source.decl.name, owner.resolved, []), sym.source.decl, sym, owner);
  }
  return null;
}

function makeMonoEntry(
  mangled: string, decl: MonoEntry["decl"], symbol: Symbol, owner: TypedProgram,
): MonoEntry {
  // Synthetic entries scoped to a comptime sub-pipeline ; they live in
  // their own bytecode module separate from the main `MonoProject`, so
  // `id` collisions with the project's entries are impossible. The id
  // counter (`synthEntryId`) is per-process — safe even across multiple
  // comptime invocations.
  return {
    id: synthEntryId++,
    isMain: false,
    mangled, decl, symbol, subst: EMPTY_SUBST, typeArgs: [], module: owner.resolved,
  };
}

let synthEntryId = 1_000_000_000;

// ---------------------------------------------------------- LoweredProject build

function bundleProject(
  input: CompileInput, mainModuleId: string,
  mainFnDecl: LoweredFnDecl, reachable: readonly { moduleId: string; decl: LoweredDecl }[],
): LoweredProject {
  const decls = new Map<string, LoweredDecl[]>();
  const push = (mid: string, d: LoweredDecl): void => {
    let bucket = decls.get(mid);
    if (bucket === undefined) { bucket = []; decls.set(mid, bucket); }
    bucket.push(d);
  };
  push(mainModuleId, mainFnDecl);
  for (const r of reachable) push(r.moduleId, r.decl);

  const modules = new Map<string, LoweredModule>();
  for (const [mid, list] of decls) {
    const program = input.project.modules.get(mid);
    modules.set(mid, {
      moduleId: mid,
      displayPath: program?.resolved.module.displayPath ?? mid,
      decls: list,
    });
  }
  // Comptime virtual dispatch isn't yet supported — emit an empty vtable list.
  return { modules, vtableEntries: [] };
}

function newLowerProjectCtx(input: CompileInput): LowerProjectCtx {
  // std/core symbols — looked up once per pipeline, not per decl. We could
  // cache further upstream alongside the impl registry, but the lookup is one
  // pass over ≤ stdlib-module-count and `lowerProject` itself does this too.
  let coreSymbols: ReadonlyMap<string, Symbol> | null = null;
  let iterSymbols: ReadonlyMap<string, Symbol> | null = null;
  for (const program of input.project.modules.values()) {
    const path = program.resolved.module.displayPath;
    if (path === "std/core") coreSymbols = program.resolved.module.symbols;
    else if (path === "std/iter") iterSymbols = program.resolved.module.symbols;
  }
  const mono: MonoProject = {
    entries: [], lookupByInstance: new Map(),
    implMethodEntries: new Map(), fnInstanceEntries: new Map(),
  };
  return {
    evaluated: input.liveEvaluated,
    mono,
    impls: input.projectImpls,
    coreTraitCache: new Map(),
    coreSymbols,
    iterSymbols,
    closures: { capturedSymbols: new Set(), lambdaCaptures: new Map() },
    synthDecls: [],
    nextSyntheticId: 1,
    diags: input.diags,
  };
}

// ---------------------------------------------------------- synthesised pieces

let _synthIdCounter = -2;     // -1 reserved by older callers; bump downward.
function nextSynthId(): number { return _synthIdCounter--; }

function synthMainFnDecl(decl: A.ConstDecl): A.FnDecl {
  return {
    kind: "FnDecl", id: UNASSIGNED_NODE_ID, span: decl.span, name: SYNTH_MAIN_NAME,
    nameSpan: decl.span, visibility: "public",
    typeParams: [], params: [], returnType: null,
    body: null, decorators: [],
  };
}

function synthSymbol(fnDecl: A.FnDecl, projectCtx: LowerProjectCtx): Symbol {
  return {
    id: nextSynthId(),
    kind: "fn",
    name: SYNTH_MAIN_NAME,
    module: "__comptime__",
    visibility: "private",
    definedAt: fnDecl.nameSpan,
    source: { kind: "fn", decl: fnDecl },
  };
}

// ---------------------------------------------------------- LoweredAST walker
// No generic visitor exists in lower/passes/* — the bytecode emitter's switch
// is intertwined with codegen. Inline traversal here.

function collectRefs(block: LoweredBlock, seen: Set<number>, out: Symbol[]): void {
  for (const stmt of block.stmts) walkStmt(stmt, seen, out);
  if (block.trailing !== null) walkExpr(block.trailing, seen, out);
}

function walkStmt(stmt: LoweredStmt, seen: Set<number>, out: Symbol[]): void {
  switch (stmt.kind) {
    case "LoweredLet":      walkExpr(stmt.value, seen, out); return;
    case "LoweredAssign":   walkExpr(stmt.target, seen, out); walkExpr(stmt.value, seen, out); return;
    case "LoweredCellSet":  walkExpr(stmt.target, seen, out); walkExpr(stmt.value, seen, out); return;
    case "LoweredExprStmt": walkExpr(stmt.expr, seen, out); return;
    case "LoweredReturn":   if (stmt.value !== null) walkExpr(stmt.value, seen, out); return;
    case "LoweredLoop":
      if (stmt.cond !== null) walkExpr(stmt.cond, seen, out);
      collectRefs(stmt.body, seen, out);
      return;
    case "LoweredBreak":
    case "LoweredContinue":
      return;
  }
}

function walkExpr(expr: LoweredExpr, seen: Set<number>, out: Symbol[]): void {
  switch (expr.kind) {
    case "LoweredIntLit": case "LoweredFloatLit": case "LoweredBoolLit":
    case "LoweredNullLit": case "LoweredCharLit": case "LoweredStringLit":
      return;
    case "LoweredIdent":
      if ((expr.symbol.kind === "fn" || expr.symbol.kind === "const")
          && !seen.has(expr.symbol.id)) {
        seen.add(expr.symbol.id);
        out.push(expr.symbol);
      }
      return;
    case "LoweredCall":
      walkExpr(expr.callee, seen, out);
      for (const a of expr.args) walkExpr(a, seen, out);
      return;
    case "LoweredFieldAccess": walkExpr(expr.target, seen, out); return;
    case "LoweredIndex":      walkExpr(expr.target, seen, out); walkExpr(expr.index, seen, out); return;
    case "LoweredUnary":      walkExpr(expr.operand, seen, out); return;
    case "LoweredBinary":     walkExpr(expr.left, seen, out); walkExpr(expr.right, seen, out); return;
    case "LoweredIf":
      walkExpr(expr.cond, seen, out);
      collectRefs(expr.then, seen, out);
      if (expr.else !== null) collectRefs(expr.else, seen, out);
      return;
    case "LoweredBlock":      collectRefs(expr, seen, out); return;
    case "LoweredStructLit":  for (const f of expr.fields) walkExpr(f.value, seen, out); return;
    case "LoweredArrayLit":   for (const e of expr.elements) walkExpr(e, seen, out); return;
    case "LoweredCast":       walkExpr(expr.value, seen, out); return;
    case "LoweredTypeCheck":  walkExpr(expr.value, seen, out); return;
    case "LoweredUnreachable":
      return;
    case "LoweredIntrinsicCall": for (const a of expr.args) walkExpr(a, seen, out); return;
    case "LoweredArrayLen":      walkExpr(expr.target, seen, out); return;
    case "LoweredArrayPush":     walkExpr(expr.target, seen, out); walkExpr(expr.value, seen, out); return;
    case "LoweredArraySlice":    walkExpr(expr.target, seen, out); walkExpr(expr.lo, seen, out); walkExpr(expr.hi, seen, out); return;
    case "LoweredCellNew":       walkExpr(expr.value, seen, out); return;
    case "LoweredCellGet":       walkExpr(expr.target, seen, out); return;
    case "LoweredMakeClosure":
      // Captures live in surrounding fn's locals. The lifted fn itself is
      // registered separately via `synthDecls` by the lambda pass.
      return;
  }
}

