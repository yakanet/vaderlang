// Drives compile-time evaluation: resolves @comptime decls in dependency
// order, runs each through the bytecode VM, and bakes @file decorators
// (file reads happen outside the VM since they're decorator-only).

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type * as A from "../parser/ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
import type { Substitution, Type } from "../typecheck/types.ts";
import { CORE_STRUCTS, TY, canonicalArgsKey, substitute } from "../typecheck/types.ts";
import { buildStructSubst } from "../typecheck/ctx.ts";
import type { ResolvedProgram } from "../resolver/resolved-ast.ts";
import type { ImplRegistry } from "../typecheck/impls.ts";

import { staticStringValue, UNASSIGNED_NODE_ID } from "../parser/ast.ts";

import { err } from "./diag.ts";
import type { EvaluatedProgram, EvaluatedProject, IntoMemberObservation } from "./evaluated-ast.ts";
import { InstanceRegistry } from "./instances.ts";
import { planComptimeOrder } from "./deps.ts";
import { runComptimeDecl } from "./run.ts";
import { buildImplRegistry } from "../typecheck/impls.ts";
import { isSpecialized, monomorphizeProject } from "./specialize.ts";
import type { MonoProject } from "./specialize.ts";
import { erasureDedupe } from "./erasure-dedupe.ts";
import { COMPTIME_BUILTIN, callBuiltin, type SandboxOptions } from "./sandbox.ts";
import type { ComptimeValue } from "./value.ts";
import { stringVal, typeVal } from "./value.ts";

export interface EvaluateOptions {
  readonly diags: DiagnosticCollector;
  readonly sandbox: SandboxOptions;
}

export function evaluateProject(project: TypedProject, opts: EvaluateOptions): EvaluatedProject {
  const instances = new InstanceRegistry();
  collectInstances(project, instances, opts.diags);

  // 1. Plan @comptime evaluation order (topological sort + cycle detection).
  // 2. Evaluate @comptime decls in that order, accumulating values into a
  //    shared map so later decls can inline earlier ones.
  // 3. Walk every IntrinsicCallExpr `@file("path")` and bake its result —
  //    the path expression may reference @comptime-baked values, hence
  //    after step 2.
  const comptimeByDecl = new Map<A.ConstDecl, ComptimeValue>();
  const comptimeOwner = new Map<A.ConstDecl, TypedProgram>();
  const order = planComptimeOrder(project, opts.diags);
  // Project-wide invariants the per-decl loop needs — built once. The "live"
  // EvaluatedProject shares the comptimeByDecl map across every module's
  // overlay so each iteration sees the latest baked values without
  // rebuilding the wrapper.
  const liveEvaluated = makeLiveEvaluatedProject(project, comptimeByDecl);
  const projectImpls = buildImplRegistry(project.resolved);
  for (const { decl, program } of order.entries) {
    // Layer 4 milestone B.0 — `@comptime t :: i32` (a const whose RHS is
    // structurally a type expression) doesn't need VM evaluation : the
    // typechecker already pre-resolved the underlying Type into the
    // `constTypeAliases` table. Synthesise a `ComptimeValue.type` directly
    // and skip the bake — the bytecode VM has no representation for type
    // values yet (proper end-to-end TypeValue plumbing is the rest of B.1).
    const aliased = program.constTypeAliases.get(decl);
    if (aliased !== undefined) {
      comptimeByDecl.set(decl, typeVal(aliased));
      comptimeOwner.set(decl, program);
      continue;
    }
    const value = runComptimeDecl({
      decl, project, callerProgram: program, evaluated: comptimeByDecl,
      callerFile: program.resolved.source.file, diags: opts.diags, sandbox: opts.sandbox,
      liveEvaluated, projectImpls,
    });
    if (value !== null) { comptimeByDecl.set(decl, value); comptimeOwner.set(decl, program); }
  }

  const fileExprs = new Map<A.IntrinsicCallExpr, string>();
  for (const typed of project.modules.values()) {
    walkProgramExprs(typed.resolved.source.decls, (e) => {
      if (e.kind !== "IntrinsicCallExpr" || e.name !== "file") return;
      const value = evalFileExpr(e, typed, opts, project, comptimeByDecl, liveEvaluated, projectImpls);
      if (value !== null) fileExprs.set(e, value);
    });
  }

  // `@assert(cond)` decls — evaluate each condition through the same
  // comptime VM by wrapping it in a synthetic ConstDecl, then surface
  // C4015 on a `false` result. Cycles aren't possible (asserts can't
  // reference each other and the user can't take the address of one), so
  // we skip the topo-sort and run them in source order.
  let assertSeq = 0;
  for (const typed of project.modules.values()) {
    for (const decl of typed.resolved.source.decls) {
      if (decl.kind !== "AssertDecl") continue;
      const fake: A.ConstDecl = {
        kind: "ConstDecl",
        id: UNASSIGNED_NODE_ID, span: decl.span,
        name: `__assert_${assertSeq++}`,
        nameSpan: decl.span,
        visibility: "private",
        type: null,
        value: decl.condition,
        decorators: [],
      };
      const value = runComptimeDecl({
        decl: fake, project, callerProgram: typed, evaluated: comptimeByDecl,
        callerFile: typed.resolved.source.file, diags: opts.diags, sandbox: opts.sandbox,
        liveEvaluated, projectImpls,
      });
      if (value !== null && value.kind === "bool" && value.value === false) {
        const detail = decl.message !== null
          ? `condition evaluated to \`false\` : ${decl.message}`
          : "condition evaluated to `false`";
        err(opts.diags, "C4015", decl.span, detail);
      }
    }
  }

  // Group per-module overlays.
  const modules = new Map<string, EvaluatedProgram>();
  for (const [id, typed] of project.modules) {
    const ct = new Map<A.ConstDecl, ComptimeValue>();
    for (const [decl, value] of comptimeByDecl) {
      if (comptimeOwner.get(decl) === typed) ct.set(decl, value);
    }
    modules.set(id, { typed, comptimeDecls: ct });
  }
  // Drive specialisation through the comptime engine — the registry built
  // above is the single source of generic instances, and `monomorphizeProject`
  // flattens it into the mono entry table consumed by the lowerer. Layer 2
  // of the type-first redesign relocates this call out of `lowerProject`.
  // `erasureDedupe` then collapses per-decl groups of non-`@specialize`d
  // generics into a single Any-substituted representative (see
  // `docs/STDLIB_GENERIC_COLLAPSE_PHASE2.md` §11).
  const intoMembers = collectIntoMembers(project);
  const evaluatedCore = {
    typed: project, modules, instances: instances.entries(),
    mono: EMPTY_MONO, fileExprs, intoMembers,
  };
  // Path (γ) progressive infrastructure shipped but gated off by default.
  // With erasureDedupe enabled, 7/252 native tests fail (down from 31/252
  // pre-γ). The remaining 7 each surface a distinct cascade pattern (tuple
  // field layout, match-arm tag check on Any, multi-level inline-box
  // boundary, …) tracked in PHASE2.md §9. Flip the call here to expose
  // them ; the boundary conversion / wrappers / synthesis stay correct
  // for the baseline (252/252 with erasure off).
  // Path (γ) progressive infrastructure — see prior commit message.
  // Flip `mono` between `monoRaw` and `erasureDedupe(monoRaw, project)`
  // to gate erasure on/off ; gated off by default so baseline stays
  // 252/252 green while the remaining 6 cascade patterns get fixed.
  const monoRaw = monomorphizeProject(evaluatedCore);
  const mono = erasureDedupe(monoRaw, project);
  return { ...evaluatedCore, mono };
}

/** Walk every `intoCoercions` site recorded by the typer and emit one
 *  `IntoMemberObservation` per (impl member, concrete typeArgs) pair.
 *  Deduplicates structurally-identical observations so the mono pass
 *  doesn't materialise the same specialisation twice. The typeArgs are
 *  derived from `coercion.implSubst` in `decl.typeParams` order, which
 *  is also what `lookupImplEntry` queries with. */
function collectIntoMembers(project: TypedProject): IntoMemberObservation[] {
  const out: IntoMemberObservation[] = [];
  const seen = new Set<string>();
  const typeParamSymbols = project.resolved.typeParamSymbols;
  for (const typed of project.modules.values()) {
    for (const coercion of typed.intoCoercions.values()) {
      // Only blanket impls need a dedicated observation : their members
      // aren't anchored to a registered struct instance, so the regular
      // mono pass can't reach them. Concrete-source impls (e.g.
      // `UserId implements Into(i32)`) are already materialised by the
      // standard non-generic impl path.
      if (coercion.entry.decl.typeParams.length === 0) continue;
      const member = coercion.entry.decl.members.find((m) => m.name === "into");
      if (member === undefined) continue;
      const typeArgs: Type[] = [];
      let ok = true;
      for (const tp of coercion.entry.decl.typeParams) {
        const sym = typeParamSymbols.get(tp);
        if (sym === undefined) { ok = false; break; }
        const ty = coercion.implSubst.typeParams?.get(sym.id);
        if (ty === undefined) { ok = false; break; }
        typeArgs.push(ty);
      }
      if (!ok) continue;
      const ownerProgram = project.modules.get(coercion.entry.module.id);
      if (ownerProgram === undefined) continue;
      const key = `${coercion.entry.decl.span.start.offset}:${canonicalArgsKey(typeArgs)}`;
      if (seen.has(key)) continue;
      seen.add(key);
      out.push({ member, program: ownerProgram, typeArgs });
    }
    // Blanket array `Contains` : same shape as the `Into` observation, but the
    // typer pre-resolved (member, element) at each `v in arr` site — no
    // implSubst to unpack. Materialise one `contains` per distinct element.
    for (const use of typed.arrayContainsUses) {
      const ownerProgram = project.modules.get(use.moduleId);
      if (ownerProgram === undefined) continue;
      const key = `contains:${use.member.span.start.offset}:${canonicalArgsKey(use.typeArgs)}`;
      if (seen.has(key)) continue;
      seen.add(key);
      out.push({ member: use.member, program: ownerProgram, typeArgs: use.typeArgs });
    }
  }
  return out;
}

const EMPTY_MONO: MonoProject = {
  entries: [],
  lookupByInstance: new Map(),
  implMethodEntries: new Map(),
  fnInstanceEntries: new Map(),
  symbolRedirects: new Map(),
};

/** Build a synthetic EvaluatedProject whose per-module overlays all alias
 *  the same shared `comptimeDecls` Map. Lookups inside the comptime loop
 *  hit it as new decls bake — no per-module duplication. The final,
 *  properly per-module-scoped EvaluatedProject is rebuilt once after the
 *  loop completes. */
function makeLiveEvaluatedProject(
  project: TypedProject,
  comptimeDecls: ReadonlyMap<A.ConstDecl, ComptimeValue>,
): EvaluatedProject {
  const modules = new Map<string, EvaluatedProgram>();
  for (const [id, typed] of project.modules) {
    modules.set(id, { typed, comptimeDecls });
  }
  return { typed: project, modules, instances: [], mono: EMPTY_MONO, fileExprs: new Map(), intoMembers: [] };
}

/** Bake an expression-position `@file("path")` call. The arg is comptime-
 *  evaluated through the same VM that runs `@comptime` decls — literals
 *  and const-ident chains take a fast path ; anything else (concat,
 *  comptime fn calls, …) goes through the VM. Returns the file's contents
 *  on success ; surfaces C4002/C4006/C4011 on failure. */
function evalFileExpr(
  expr: A.IntrinsicCallExpr, typed: TypedProgram, opts: EvaluateOptions,
  project: TypedProject, comptimeByDecl: ReadonlyMap<A.ConstDecl, ComptimeValue>,
  liveEvaluated: EvaluatedProject, projectImpls: ImplRegistry,
): string | null {
  const arg = expr.args[0];
  if (arg === undefined) return null;
  let path = staticStringFromExpr(arg, typed.resolved);
  if (path === null) {
    const fake: A.ConstDecl = {
      kind: "ConstDecl", id: UNASSIGNED_NODE_ID, span: expr.span, name: `__file_arg`, nameSpan: expr.span,
      visibility: "private", type: null, value: arg, decorators: [],
    };
    const value = runComptimeDecl({
      decl: fake, project, callerProgram: typed, evaluated: comptimeByDecl,
      callerFile: typed.resolved.source.file, diags: opts.diags, sandbox: opts.sandbox,
      liveEvaluated, projectImpls,
    });
    if (value === null || value.kind !== "string") return null;
    path = value.value;
  }
  const result = callBuiltin(
    { fnName: COMPTIME_BUILTIN.file, args: [stringVal(path)], callerFile: typed.resolved.source.file },
    opts.sandbox,
  );
  if (result === null) return null;
  if (!result.ok) {
    err(opts.diags, result.code, expr.span, result.message);
    return null;
  }
  if (result.value.kind !== "string") return null;
  return result.value.value;
}

/** Fast path for `@file("lit")` and `@file(IDENT)` where IDENT points at
 *  a const whose value is itself one of those — saves a VM round-trip
 *  when the path is statically resolvable from the AST. */
function staticStringFromExpr(expr: A.Expr, resolved: ResolvedProgram): string | null {
  if (expr.kind === "StringLitExpr") return staticStringValue(expr);
  if (expr.kind !== "IdentExpr") return null;
  const sym = resolved.idents.get(expr);
  if (sym === undefined || sym.source.kind !== "const") return null;
  return staticStringFromExpr(sym.source.decl.value, resolved);
}

/** Walk every expression node reachable from a list of top-level decls.
 *  Used by the `@file` pre-pass — we don't care about block / stmt
 *  structure, only the set of expressions present in fn / impl member
 *  bodies and const RHS. */
function walkProgramExprs(decls: readonly A.Decl[], visit: (e: A.Expr) => void): void {
  const visitor: BlockVisitor = { expr: visit };
  for (const decl of decls) {
    if (decl.kind === "FnDecl" && decl.body !== null) walkBlock(decl.body, visitor);
    else if (decl.kind === "ImplDecl") {
      for (const m of decl.members) if (m.body !== null) walkBlock(m.body, visitor);
    } else if (decl.kind === "ConstDecl") walkExpr(decl.value, visitor);
    else if (decl.kind === "AssertDecl") walkExpr(decl.condition, visitor);
  }
}

/** Tree walker over a fn body. Surfaces three event kinds — every expression,
 *  every CallExpr (so callers can peek at `genericFnCalls`), and every
 *  `for x in iter` iter expr. Lets `closeOverGenericImpls` collect everything
 *  it needs in one pass over each generic fn instance. Each callback is
 *  optional. */
interface BlockVisitor {
  expr?: (e: A.Expr) => void;
  call?: (e: A.CallExpr) => void;
  forInIter?: (iter: A.Expr) => void;
}

function walkBlock(block: A.BlockExpr, v: BlockVisitor): void {
  for (const stmt of block.stmts) walkStmt(stmt, v);
  if (block.trailing !== null) walkExpr(block.trailing, v);
}

function walkStmt(stmt: A.Stmt, v: BlockVisitor): void {
  switch (stmt.kind) {
    case "ForStmt":
      if (stmt.form.kind === "in") {
        v.forInIter?.(stmt.form.iter);
        walkExpr(stmt.form.iter, v);
      } else if (stmt.form.kind === "while") {
        // `for <iter> { body }` surfaces the iter as the while cond ; the
        // visitor's array-only filter makes true bool conds inert.
        v.forInIter?.(stmt.form.cond);
        walkExpr(stmt.form.cond, v);
      }
      walkBlock(stmt.body, v);
      return;
    case "LetStmt":     walkExpr(stmt.value, v); return;
    case "AssignStmt":  walkExpr(stmt.target, v); walkExpr(stmt.value, v); return;
    case "ExprStmt":    walkExpr(stmt.expr, v); return;
    case "ReturnStmt":  if (stmt.value !== null) walkExpr(stmt.value, v); return;
    case "DeferStmt":
      if ("kind" in stmt.body && stmt.body.kind === "BlockExpr") walkBlock(stmt.body, v);
      else walkStmt(stmt.body as A.Stmt, v);
      return;
    default: return;
  }
}

function walkExpr(expr: A.Expr, v: BlockVisitor): void {
  v.expr?.(expr);
  if (expr.kind === "CallExpr") v.call?.(expr);
  switch (expr.kind) {
    case "BlockExpr": walkBlock(expr, v); return;
    case "IfExpr":
      walkExpr(expr.cond, v);
      walkBlock(expr.then, v);
      if (expr.else !== null) walkExpr(expr.else, v);
      return;
    case "MatchExpr":
      walkExpr(expr.scrutinee, v);
      for (const arm of expr.arms) {
        if (arm.guard !== null) walkExpr(arm.guard, v);
        walkExpr(arm.body, v);
      }
      return;
    case "CallExpr":
      walkExpr(expr.callee, v);
      for (const a of expr.args) walkExpr(a.value, v);
      return;
    case "BinaryExpr": walkExpr(expr.left, v); walkExpr(expr.right, v); return;
    case "UnaryExpr":  walkExpr(expr.operand, v); return;
    case "FieldExpr":  walkExpr(expr.target, v); return;
    case "IndexExpr":  walkExpr(expr.target, v); walkExpr(expr.index, v); return;
    case "RangeExpr":  walkExpr(expr.lower, v); walkExpr(expr.upper, v); return;
    case "TryExpr":    walkExpr(expr.inner, v); return;
    case "CastExpr":   walkExpr(expr.value, v); return;
    case "LambdaExpr":
      if (expr.body !== null) {
        if (expr.body.kind === "BlockExpr") walkBlock(expr.body, v);
        else walkExpr(expr.body, v);
      }
      return;
    case "SeqLitExpr":    for (const e of expr.elements) walkExpr(e, v); return;
    case "StructLitExpr":
      for (const item of expr.items) {
        if (item.kind === "field") walkExpr(item.value, v);
        else walkExpr(item.expr, v);
      }
      return;
    case "GenericInstExpr": walkExpr(expr.callee, v); return;
    case "IntrinsicCallExpr":
      for (const a of expr.args) walkExpr(a, v);
      return;
    case "StringLitExpr":
      for (const part of expr.parts) {
        if (part.kind === "interp") walkExpr(part.expr, v);
      }
      return;
    default: return;
  }
}

// ----------------------------------------------------- instance walker

function collectInstances(project: TypedProject, registry: InstanceRegistry, diags: DiagnosticCollector): void {
  // Locate `std/core::ArrayIter` once so the for-in walker below can register
  // an `ArrayIter(T)` instance whenever user code iterates a `[T]` array.
  let arrayIterSymbol: Symbol | null = null;
  for (const m of project.modules.values()) {
    if (m.resolved.module.displayPath === "std/core") {
      const s = m.resolved.module.symbols.get(CORE_STRUCTS.ArrayIterator);
      if (s !== undefined) arrayIterSymbol = s;
      break;
    }
  }

  for (const typed of project.modules.values()) {
    for (const ty of typed.declTypes.values()) registry.observe(ty);
    for (const ty of typed.paramTypes.values()) registry.observe(ty);
    for (const ty of typed.typeExprTypes.values()) registry.observe(ty);
    for (const ty of typed.exprTypes.values()) registry.observe(ty);
    for (const ty of typed.localTypes.values()) registry.observe(ty);

    // `for x in arr` over a `[T]` triggers an auto-wrap into `ArrayIter(T)`
    // at lower time. Register that instance here so mono materialises the
    // specialised impl members; the lowerer can't add to the registry
    // because it runs after mono.
    if (arrayIterSymbol !== null) {
      const onForIn = (iter: A.Expr): void => {
        const iterType = typed.exprTypes.get(iter);
        if (iterType !== undefined && iterType.kind === "Array") {
          registry.add(arrayIterSymbol!, [iterType.element]);
        }
      };
      for (const decl of typed.resolved.source.decls) {
        if (decl.kind === "FnDecl" && decl.body !== null) {
          walkBlock(decl.body, { forInIter: onForIn });
        } else if (decl.kind === "ImplDecl") {
          for (const member of decl.members) {
            if (member.body !== null) walkBlock(member.body, { forInIter: onForIn });
          }
        }
      }
    }
    // Each `Into` coercion site needs the corresponding impl member body
    // observed so transitive types (e.g. `ArrayIterator(T)` inside the
    // `T[] implements[T] Into(Iterator(T))` blanket) get registered.
    // Mirrors `observeImplMembers` but uses the impl's typeParam binding
    // from `coercion.implSubst` rather than a struct instance. The walk
    // uses the impl's *owning* module's TypedProgram — the coercion may
    // be recorded at a use site in module A while the impl lives in B
    // (e.g. std/core's blanket impls).
    for (const coercion of typed.intoCoercions.values()) {
      if (coercion.entry.decl.typeParams.length === 0) continue;
      const member = coercion.entry.decl.members.find((m) => m.name === "into");
      if (member === undefined || member.body === null) continue;
      const ownerTyped = project.modules.get(coercion.entry.module.id);
      if (ownerTyped === undefined) continue;
      walkImplBodyForCalls(member.body, ownerTyped, registry, coercion.implSubst);
    }
    // Inferred generic-fn call sites: the typechecker records (CallExpr → typeArgs)
    // for each call site where it successfully unified the fn's type params.
    for (const [callExpr, typeArgs] of typed.genericFnCalls) {
      if (callExpr.callee.kind === "IdentExpr") {
        // Honor any overload-resolution override before falling back to the
        // resolver's primary symbol.
        const sym = typed.directCallOverloads.get(callExpr)
                 ?? typed.resolved.idents.get(callExpr.callee);
        if (sym !== undefined) registry.observeFnCall(sym, typeArgs);
      } else if (callExpr.callee.kind === "FieldExpr") {
        // UFCS generic call — pull the chosen free-fn symbol from the
        // discriminated FieldResolution.
        const fr = typed.fieldResolutions.get(callExpr.callee);
        const sym = fr?.kind === "ufcs-free" ? fr.symbol : undefined;
        if (sym !== undefined) registry.observeFnCall(sym, typeArgs);
        else {
          // Namespace-aliased generic call (`fs.println(...)` after
          // `fs :: import "std/io"`) : the resolver records the
          // exported symbol on `fieldRefs`, not `fieldResolutions`.
          const fieldRef = typed.resolved.fieldRefs.get(callExpr.callee);
          if (fieldRef?.kind === "namespace") {
            registry.observeFnCall(fieldRef.symbol, typeArgs);
          }
        }
      } else if (callExpr.callee.kind === "GenericInstExpr" && callExpr.callee.callee.kind === "IdentExpr") {
        // Explicit-args generic call : `foo<T1, T2>(args)`. The inner
        // IdentExpr carries the symbol binding (`recordGenericCallSite`
        // ran via `recordExplicitGenericCallSite` in typecheck).
        const sym = typed.resolved.idents.get(callExpr.callee.callee);
        if (sym !== undefined) registry.observeFnCall(sym, typeArgs);
      }
    }
  }

  // Erasure cascade (Issue 9 path γ) : every `@specialize`d generic struct
  // /trait may be reached from an erased decl with Any-bearing type args
  // (e.g. `ArrayIterator(Entry(Any, Any) | null)` after `MutableMap` is
  // erased). Pre-register the all-Any view of each `@specialize`d generic
  // so `closeOverGenericImpls` materialises its impl members with Any-arg
  // substitutions. Over-registration is benign — DCE drops unused mono
  // entries downstream ; under-registration crashes with `vader_unreachable`
  // at the vtable miss.
  synthesiseErasedSpecializedInstances(project, registry);

  // Transitive closure: when `ArrayIter(string)` is registered, the impl `step`
  // returns `Done | Yielded(T)`. Substituting T=string yields `Yielded(string)`,
  // which must also be observed so mono materialises it. Without this sweep the
  // bytecode emit would only see a `ref Yielded` placeholder for the Yielded
  // struct in `step__string` — and crash with `unreachable` at the StructLit.
  // Same idea propagates to generic fn instances: `hashed_count<i32>`'s body
  // contains `for x in items` (items: [T]) and inner generic call sites — both
  // need their substituted types/instances observed to materialise the right
  // mono entries downstream.
  closeOverGenericImpls(project, registry, arrayIterSymbol, diags);
}

/** Path (γ) — register an Any-bearing instance for every `@specialize`d
 *  generic struct/trait declared in the project. The reasoning : when the
 *  erasure pass collapses N concrete instantiations of a non-`@specialize`d
 *  decl into one Any-substituted representative, that representative's
 *  body / field types may reference a `@specialize`d generic with Any-bearing
 *  args (e.g. `MutableMap` erased → `Entry(Any, Any)`, with `Entry` /
 *  `ArrayIterator(Entry(...))` being `@specialize`d and needing the Any-arg
 *  instance materialised for virtual dispatch to land somewhere).
 *
 *  The simplest sound approach : register every `@specialize`d generic with
 *  all-Any args (`Self(Any, Any, ...)`). Transitive observation in
 *  `closeOverGenericImpls` materialises the impl members against the new
 *  instance ; DCE prunes anything actually unused. */
function synthesiseErasedSpecializedInstances(
  project: TypedProject, registry: InstanceRegistry,
): void {
  for (const m of project.modules.values()) {
    for (const decl of m.resolved.source.decls) {
      if (decl.kind !== "StructDecl" && decl.kind !== "TraitDecl") continue;
      if (decl.typeParams.length === 0) continue;
      if (!isSpecialized(decl)) continue;
      const sym = m.resolved.module.symbols.get(decl.name);
      if (sym === undefined) continue;
      const anyArgs: Type[] = decl.typeParams.map(() => TY.any);
      registry.add(sym, anyArgs);
    }
  }
}

interface ImplSite {
  readonly impl: A.ImplDecl;
  readonly program: ResolvedProgram;
  readonly structDecl: A.StructDecl;
}

function closeOverGenericImpls(
  project: TypedProject, registry: InstanceRegistry, arrayIterSymbol: Symbol | null,
  diags: DiagnosticCollector,
): void {
  // Index generic impls by the symbol id of their target struct.
  const implsByStructId = new Map<number, ImplSite[]>();
  // Index generic fn decls by their symbol id, with the program they live in.
  const genericFnsBySymId = new Map<number, { fn: A.FnDecl; program: ResolvedProgram }>();
  for (const m of project.modules.values()) {
    for (const d of m.resolved.source.decls) {
      if (d.kind === "ImplDecl") {
        if (d.forType.kind !== "GenericInstExpr") continue;
        if (d.forType.callee.kind !== "IdentExpr") continue;
        const sym = m.resolved.module.symbols.get(d.forType.callee.name);
        if (sym === undefined || sym.source.kind !== "struct") continue;
        const list = implsByStructId.get(sym.id) ?? [];
        list.push({ impl: d, program: m.resolved, structDecl: sym.source.decl });
        implsByStructId.set(sym.id, list);
      } else if (d.kind === "FnDecl" && d.typeParams.length > 0) {
        // Overloaded fn names share the same `module.symbols` slot for the
        // primary — match the exact `decl` via the overload bucket so we
        // don't conflate `len(MutableMap)` with `len(MutableSet)`.
        const bucket = m.resolved.module.fnOverloads.get(d.name);
        const sym = bucket?.find((s) => s.source.kind === "fn" && s.source.decl === d);
        if (sym !== undefined) {
          genericFnsBySymId.set(sym.id, { fn: d, program: m.resolved });
        }
      }
    }
  }

  // Worklist-driven discovery: each instance is processed exactly once. New
  // instances added by `observe...` helpers (via the registry's listener) are
  // pushed onto the worklist and drained in turn. Convergence is O(reachable
  // instances) — no fixpoint, no per-iteration snapshot.
  //
  // The `MAX_INSTANCES` cap is the safety net for the pathological case where
  // a generic decl strictly grows the type at each instantiation (e.g. a
  // `wrap<T>` that recurses into `wrap<List(T)>`); without the cap the
  // registry would grow unboundedly. C4014 surfaces the bug.
  const MAX_INSTANCES = 4096;
  const worklist: { symbol: Symbol; args: readonly Type[] }[] = [];
  worklist.push(...registry.entries());
  const unsubscribe = registry.onNewInstance((inst) => {
    if (registry.size() <= MAX_INSTANCES) worklist.push(inst);
  });

  // `try / finally` so a panicking `observe...` helper doesn't leave the
  // listener registered on the (long-lived) `InstanceRegistry`. Without
  // this, an LSP/watch host that reuses the registry would accumulate
  // dead listeners across crash recovery and slow `add()` linearly.
  try {
    while (worklist.length > 0 && registry.size() <= MAX_INSTANCES) {
      const inst = worklist.pop()!;
      const sites = implsByStructId.get(inst.symbol.id);
      if (sites !== undefined) {
        for (const site of sites) observeImplMembers(project, registry, inst, site);
      }
      if (inst.symbol.kind === "fn") {
        const entry = genericFnsBySymId.get(inst.symbol.id);
        if (entry !== undefined) {
          observeFnBody(project, registry, inst, entry.fn, entry.program, arrayIterSymbol);
        }
      }
    }
  } finally {
    unsubscribe();
  }

  if (registry.size() > MAX_INSTANCES) {
    err(diags, "C4014", pickAnchorSpan(genericFnsBySymId, implsByStructId, project),
        `generic instance discovery exceeded ${MAX_INSTANCES} instances. ` +
        `A generic fn or impl is recursively expanding into ever-larger types; ` +
        `consider breaking the recursion or specialising manually.`);
  }
}

/** Pick a user-visible anchor for a project-wide diagnostic: prefer a generic
 *  fn decl, fall back to an impl decl, then synthesise a span at the first
 *  module's file. */
function pickAnchorSpan(
  genericFns: Map<number, { fn: A.FnDecl; program: ResolvedProgram }>,
  implsByStructId: Map<number, ImplSite[]>,
  project: TypedProject,
): Span {
  const fn = genericFns.values().next().value;
  if (fn !== undefined) return fn.fn.span;
  for (const list of implsByStructId.values()) {
    if (list[0] !== undefined) return list[0].impl.span;
  }
  const firstModule = project.modules.values().next().value;
  const file = firstModule?.resolved.source.file ?? "<unknown>";
  const pos = { file, offset: 0, line: 1, column: 1 };
  return { start: pos, end: pos };
}

function observeImplMembers(
  project: TypedProject, registry: InstanceRegistry,
  inst: { args: readonly Type[] }, site: ImplSite,
): void {
  // Bounded-generic impls (`[T: Bound] Foo[T] implements ...`) declare
  // their own type-params with local bounds. Member bodies reference
  // those impl-side symbols ; substituting via the struct's typeParams
  // misses them entirely (e.g. `Yielded(T)` in `Range[T]`'s step body
  // would stay un-substituted, and `Yielded(i32)` never gets registered
  // as an instance). Mirror `monomorphizeProject`'s pass-2 routing.
  const subst = site.impl.typeParams.length > 0
    ? buildStructSubst(site.impl.typeParams, inst.args, site.program.typeParams)
    : buildStructSubst(site.structDecl.typeParams, inst.args, site.program.typeParams);
  if (subst.typeParams === undefined || subst.typeParams.size === 0) return;
  const typed = project.modules.get(site.program.module.id);
  if (typed === undefined) return;
  for (const member of site.impl.members) {
    const fnType = typed.declTypes.get(member);
    if (fnType !== undefined) registry.observe(substitute(fnType, subst));
    for (const p of member.params) {
      const pt = typed.paramTypes.get(p);
      if (pt !== undefined) registry.observe(substitute(pt, subst));
    }
    // Walk the body to chain transitive monomorphisation : when the impl
    // member calls a generic fn (`self.put(key, v)` from `IndexSet.set_at`),
    // the inner call site's typeArgs need to be substituted from the impl's
    // own type-args and observed so the called fn gets materialised at the
    // matching instance. Without this, generic-impl members that nest
    // generic calls hit `unreachable` at the un-mono'd call.
    if (member.body !== null) walkImplBodyForCalls(member.body, typed, registry, subst);
  }
}

function walkImplBodyForCalls(
  body: A.BlockExpr, typed: TypedProgram,
  registry: InstanceRegistry, subst: Substitution,
): void {
  walkBlock(body, {
    expr(e) {
      const ty = typed.exprTypes.get(e);
      if (ty !== undefined) registry.observe(substitute(ty, subst));
    },
    call(callExpr) {
      const innerArgs = typed.genericFnCalls.get(callExpr);
      if (innerArgs === undefined) return;
      const sub = innerArgs.map((a) => substitute(a, subst));
      let calleeSym: Symbol | undefined;
      if (callExpr.callee.kind === "IdentExpr") {
        calleeSym = typed.directCallOverloads.get(callExpr)
                 ?? typed.resolved.idents.get(callExpr.callee);
      } else if (callExpr.callee.kind === "FieldExpr") {
        const fr = typed.fieldResolutions.get(callExpr.callee);
        calleeSym = fr?.kind === "ufcs-free" ? fr.symbol : undefined;
      } else if (callExpr.callee.kind === "GenericInstExpr" && callExpr.callee.callee.kind === "IdentExpr") {
        calleeSym = typed.resolved.idents.get(callExpr.callee.callee);
      }
      if (calleeSym !== undefined) registry.observeFnCall(calleeSym, sub);
    },
  });
}

/** Walk a generic fn instance's body once, dispatching three observation
 *  tasks per visited node : substitute the iter's element type for `for x in
 *  iter` (registers `ArrayIter(elem)`), substitute inner generic call sites'
 *  typeArgs (transitive monomorphisation), and observe every expression's
 *  substituted type (catches struct/trait instances buried in matches). */
function observeFnBody(
  project: TypedProject, registry: InstanceRegistry,
  inst: { args: readonly Type[] }, fn: A.FnDecl, program: ResolvedProgram,
  arrayIterSymbol: Symbol | null,
): void {
  if (fn.body === null) return;
  const subst = buildStructSubst(fn.typeParams, inst.args, program.typeParams);
  if (subst.typeParams === undefined || subst.typeParams.size === 0) return;
  const typed = project.modules.get(program.module.id);
  if (typed === undefined) return;

  walkBlock(fn.body, {
    expr(e) {
      const ty = typed.exprTypes.get(e);
      if (ty !== undefined) registry.observe(substitute(ty, subst));
    },
    call(callExpr) {
      const innerArgs = typed.genericFnCalls.get(callExpr);
      if (innerArgs === undefined) return;
      const sub = innerArgs.map((a) => substitute(a, subst));
      let calleeSym: Symbol | undefined;
      if (callExpr.callee.kind === "IdentExpr") {
        calleeSym = typed.directCallOverloads.get(callExpr)
                 ?? typed.resolved.idents.get(callExpr.callee);
      } else if (callExpr.callee.kind === "FieldExpr") {
        const fr = typed.fieldResolutions.get(callExpr.callee);
        calleeSym = fr?.kind === "ufcs-free" ? fr.symbol : undefined;
      } else if (callExpr.callee.kind === "GenericInstExpr" && callExpr.callee.callee.kind === "IdentExpr") {
        calleeSym = typed.resolved.idents.get(callExpr.callee.callee);
      }
      if (calleeSym !== undefined) registry.observeFnCall(calleeSym, sub);
    },
    forInIter: arrayIterSymbol === null ? undefined : (iter) => {
      const iterType = typed.exprTypes.get(iter);
      if (iterType === undefined) return;
      const sub = substitute(iterType, subst);
      if (sub.kind === "Array") registry.add(arrayIterSymbol, [sub.element]);
    },
  });
}
