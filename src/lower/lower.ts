// Project-level orchestration. Walks every MonoEntry, dispatches to the
// per-decl-kind lowerer, and bakes ComptimeValues into LoweredExpr leaves.
// All expression / statement / iterator / match / try desugar lives in
// `./passes/*.ts`.

import type * as A from "../parser/ast.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { EvaluatedProject } from "../comptime/evaluated-ast.ts";
import type { ComptimeValue } from "../comptime/value.ts";
import { analyzeClosures } from "../closures/analyze.ts";
import type { ClosureAnalysis } from "../closures/analyze.ts";
import type { Symbol } from "../resolver/symbol.ts";
import { buildImplRegistry } from "../typecheck/impls.ts";
import type { Type } from "../typecheck/types.ts";
import { TY, defaultIfFree } from "../typecheck/types.ts";

import type { MonoEntry } from "../monomorphize/index.ts";
import { monomorphizeProject } from "../monomorphize/index.ts";

import type { LowerProjectCtx } from "./ctx.ts";
import type {
  LoweredDecl, LoweredExpr, LoweredFnDecl, LoweredModule, LoweredParam, LoweredProject,
} from "./lowered-ast.ts";

import { lowerBlock } from "./passes/block.ts";
import { lowerExpr } from "./passes/expr.ts";
import { applySubst } from "./passes/helpers.ts";

const STD_CORE_PATH = "std/core";

export function lowerProject(
  evaluated: EvaluatedProject,
  diags?: DiagnosticCollector,
  closures?: ClosureAnalysis,
): LoweredProject {
  const mono = monomorphizeProject(evaluated);
  const impls = buildImplRegistry(evaluated.typed.resolved);
  let coreSymbols: ReadonlyMap<string, Symbol> | null = null;
  for (const program of evaluated.typed.modules.values()) {
    if (program.resolved.module.displayPath === STD_CORE_PATH) {
      coreSymbols = program.resolved.module.symbols;
      break;
    }
  }
  const ctx: LowerProjectCtx = {
    evaluated, mono, impls,
    coreTraitCache: new Map(),
    coreSymbols,
    closures: closures ?? analyzeClosures(evaluated.typed),
    synthDecls: [],
    nextSyntheticId: 1,
    diags: diags ?? new DiagnosticCollector(),
  };

  const byModule = new Map<string, LoweredDecl[]>();
  for (const entry of mono.entries) {
    const mid = entry.module.module.id;
    let bucket = byModule.get(mid);
    if (bucket === undefined) { bucket = []; byModule.set(mid, bucket); }
    const decl = lowerEntry(entry, ctx);
    if (decl !== null) bucket.push(decl);
  }

  // Distribute lambda-lifting synthDecls — they piggy-back on the module
  // their containing fn lived in (recovered from the synth entry's module).
  for (const synth of ctx.synthDecls) {
    const mid = synth.origin.module.module.id;
    let bucket = byModule.get(mid);
    if (bucket === undefined) { bucket = []; byModule.set(mid, bucket); }
    bucket.push(synth);
  }

  const modules = new Map<string, LoweredModule>();
  for (const [mid, decls] of byModule) {
    const program = ctx.evaluated.typed.modules.get(mid);
    if (program === undefined) continue;
    modules.set(mid, {
      moduleId: mid,
      displayPath: program.resolved.module.displayPath,
      decls,
    });
  }
  return { modules };
}

function lowerEntry(entry: MonoEntry, ctx: LowerProjectCtx): LoweredDecl | null {
  switch (entry.decl.kind) {
    case "FnDecl":     return lowerFnEntry(entry, entry.decl, ctx, /*selfType*/ null);
    case "StructDecl": return lowerStructEntry(entry, entry.decl, ctx);
    case "ConstDecl":  return lowerConstEntry(entry, entry.decl, ctx);
    case "ImplDecl":   return null;       // members surface via the per-member entries
  }
}

function lowerFnEntry(
  entry: MonoEntry, fn: A.FnDecl, ctx: LowerProjectCtx, selfType: Type | null,
): LoweredFnDecl | null {
  const typed = ctx.evaluated.typed.modules.get(entry.module.module.id);
  if (typed === undefined) return null;
  const subst = entry.subst;

  const params: LoweredParam[] = [];
  for (const p of fn.params) {
    const declared = typed.paramTypes.get(p) ?? TY.unresolved;
    const sym = typed.resolved.params.get(p);
    if (sym === undefined) continue;
    params.push({ name: p.name, symbol: sym, type: applySubst(declared, subst) });
  }

  const fnType = typed.declTypes.get(fn);
  const returnType = fnType?.kind === "Fn" ? applySubst(fnType.returnType, subst) : TY.unresolved;

  const body = fn.body === null ? null : lowerBlock({
    project: ctx, entry, typed, subst, returnType, selfType, blocks: [], uniq: 0,
    liftedContext: null,
  }, fn.body, /*isFnRoot*/ true, /*isLoopBody*/ false);

  return {
    kind: "LoweredFnDecl",
    mangled: entry.mangled,
    params, returnType, body,
    origin: entry,
  };
}

function lowerStructEntry(entry: MonoEntry, struct: A.StructDecl, ctx: LowerProjectCtx): LoweredDecl | null {
  const typed = ctx.evaluated.typed.modules.get(entry.module.module.id);
  if (typed === undefined) return null;
  return {
    kind: "LoweredStructDecl",
    mangled: entry.mangled,
    fields: struct.fields.map((f) => ({
      name: f.name,
      type: applySubst(typed.typeExprTypes.get(f.type) ?? TY.unresolved, entry.subst),
    })),
    origin: entry,
  };
}

function lowerConstEntry(entry: MonoEntry, decl: A.ConstDecl, ctx: LowerProjectCtx): LoweredDecl | null {
  const typed = ctx.evaluated.typed.modules.get(entry.module.module.id);
  const evaled = ctx.evaluated.modules.get(entry.module.module.id);
  if (typed === undefined) return null;
  const type = applySubst(typed.exprTypes.get(decl.value) ?? TY.unresolved, entry.subst);

  // @comptime / @file values were already baked by the comptime pass — emit
  // the literal directly so downstream phases see the materialized constant
  // rather than re-running the AST.
  const baked = evaled?.comptimeDecls.get(decl) ?? evaled?.fileDecls.get(decl);
  const value: LoweredExpr = baked !== undefined
    ? comptimeValueToLowered(baked, defaultIfFree(type), decl.span)
    : lowerExpr({
        project: ctx, entry, typed, subst: entry.subst,
        returnType: type, selfType: null, blocks: [], uniq: 0,
        liftedContext: null,
      }, decl.value);

  return {
    kind: "LoweredConstDecl",
    mangled: entry.mangled,
    type: defaultIfFree(type),
    value,
    origin: entry,
  };
}

/** Materialize a comptime value as a Lowered AST literal. Compound values
 *  (arrays, structs) are recursively lowered field-by-field. */
function comptimeValueToLowered(v: ComptimeValue, typeHint: Type, span: Span): LoweredExpr {
  switch (v.kind) {
    case "int":    return { kind: "LoweredIntLit",   span, type: typeHint, value: v.value };
    case "float":  return { kind: "LoweredFloatLit", span, type: typeHint, value: v.value };
    case "bool":   return { kind: "LoweredBoolLit",  span, type: TY.bool,  value: v.value };
    case "char":   return { kind: "LoweredCharLit",  span, type: TY.char,  value: v.value };
    case "string": return { kind: "LoweredStringLit", span, type: TY.string, value: v.value };
    case "null":   return { kind: "LoweredNullLit",  span, type: TY.null };
    case "void":
      return { kind: "LoweredUnreachable", span, type: typeHint, reason: "comptime void value" };
    case "array": {
      const elementType: Type = typeHint.kind === "Array" ? typeHint.element : TY.unresolved;
      return {
        kind: "LoweredArrayLit", span, type: typeHint,
        elements: v.elements.map((e) => comptimeValueToLowered(e, elementType, span)),
      };
    }
    case "struct":
      return {
        kind: "LoweredStructLit", span, type: typeHint,
        fields: [...v.fields].map(([name, val]) => ({
          name, value: comptimeValueToLowered(val, TY.unresolved, span),
        })),
      };
  }
}
