// Project-level orchestration. Walks every MonoEntry, dispatches to the
// per-decl-kind lowerer, and bakes ComptimeValues into LoweredExpr leaves.
// All expression / statement / iterator / match / try desugar lives in
// `./passes/*.ts`.

import type * as A from "../parser/ast.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { EvaluatedProject } from "../comptime/evaluated-ast.ts";
import type { ComptimeValue } from "../comptime/value.ts";
import { analyzeClosures } from "./passes/closures.ts";
import type { ClosureAnalysis } from "./passes/closures.ts";
import type { Symbol } from "../resolver/symbol.ts";
import {buildImplRegistry, ImplRegistry} from "../typecheck/impls.ts";
import type { Type } from "../typecheck/types.ts";
import { TY, defaultIfFree } from "../typecheck/types.ts";
import { primitiveFromName } from "../typecheck/passes/type-expr.ts";

import type {MonoEntry, MonoProject} from "../comptime/specialize.ts";

import type { LowerProjectCtx } from "./ctx.ts";
import { makeEntryTypes } from "./entry-types.ts";
import type {
  LoweredDecl, LoweredExpr, LoweredFnDecl, LoweredModule, LoweredParam, LoweredProject, VtableEntry,
} from "./lowered-ast.ts";

import { lowerBlock } from "./passes/block.ts";
import { lowerExpr } from "./passes/expr.ts";

const STD_CORE_PATH = "std/core";

export function lowerProject(
  evaluated: EvaluatedProject,
  diags?: DiagnosticCollector,
  closures?: ClosureAnalysis,
): LoweredProject {
  const mono = evaluated.mono;
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
  return { modules, vtableEntries: collectVtableEntries(impls, mono) };
}

/** Flatten the impl registry × mono entries into one entry per
 *  `(trait, method, struct instance, impl fn)`. The bytecode emitter walks
 *  the result to populate `BytecodeModule.vtables` once both type-table and
 *  fn-table indices are known. */
function collectVtableEntries(
  impls: ImplRegistry,
  mono: MonoProject,
): VtableEntry[] {
  const out: VtableEntry[] = [];
  for (const impl of impls.entries()) {
    if (impl.traitSymbol === null) continue;
    const recvType = vtableReceiverType(impl);
    if (recvType === null) continue;
    for (const member of impl.decl.members) {
      const perArgs = mono.implMethodEntries.get(member);
      if (perArgs === undefined) continue;
      for (const entry of perArgs.values()) {
        if (entry.symbol === null) continue;
        out.push({
          traitName: impl.traitSymbol.name,
          methodName: member.name,
          structType: impl.forSymbol !== null
            ? { kind: "Struct", symbol: impl.forSymbol, args: entry.typeArgs }
            : recvType,
          fnSymbol: entry.symbol,
        });
      }
    }
  }
  return out;
}

/** Receiver type for a vtable entry. Returns the impl's target as a `Type`
 *  so the bytecode emitter can intern it and key the vtable by its type index.
 *  Supports struct impls (with optional generic args filled in per entry) and
 *  primitive impls (`i32 implements Doubler(i32)`). Returns null for shapes
 *  we can't dispatch through (type aliases of non-struct things, etc.). */
function vtableReceiverType(impl: { forSymbol: Symbol | null; decl: A.ImplDecl }): Type | null {
  if (impl.forSymbol !== null) {
    if (impl.forSymbol.source.kind !== "struct") return null;
    return { kind: "Struct", symbol: impl.forSymbol, args: [] };
  }
  if (impl.decl.forType.kind !== "IdentExpr") return null;
  const prim = primitiveFromName(impl.decl.forType.name);
  return prim;
}

function lowerEntry(entry: MonoEntry, ctx: LowerProjectCtx): LoweredDecl | null {
  switch (entry.decl.kind) {
    case "FnDecl":     return lowerFnEntry(entry, entry.decl, ctx, /*selfType*/ null);
    case "StructDecl": return lowerStructEntry(entry, entry.decl, ctx);
    case "ConstDecl":  return lowerConstEntry(entry, entry.decl, ctx);
    case "ImplDecl":   return null;       // members surface via the per-member entries
  }
}

export function lowerFnEntry(
  entry: MonoEntry, fn: A.FnDecl, ctx: LowerProjectCtx, selfType: Type | null,
): LoweredFnDecl | null {
  const typed = ctx.evaluated.typed.modules.get(entry.module.module.id);
  if (typed === undefined) return null;
  const subst = entry.subst;
  const types = makeEntryTypes(typed, subst);

  const params: LoweredParam[] = [];
  for (const p of fn.params) {
    const sym = typed.resolved.params.get(p);
    if (sym === undefined) continue;
    params.push({ name: p.name, symbol: sym, type: types.paramType(p) });
  }

  const fnType = typed.declTypes.get(fn);
  const returnType = fnType?.kind === "Fn" ? types.apply(fnType.returnType) : TY.unresolved;

  const body = fn.body === null ? null : lowerBlock({
    project: ctx, entry, typed, subst, types,
    returnType, selfType, blocks: [], uniq: 0,
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
  const types = makeEntryTypes(typed, entry.subst);
  return {
    kind: "LoweredStructDecl",
    mangled: entry.mangled,
    fields: struct.fields.map((f) => ({
      name: f.name,
      type: types.typeExprType(f.type),
    })),
    origin: entry,
  };
}

export function lowerConstEntry(entry: MonoEntry, decl: A.ConstDecl, ctx: LowerProjectCtx): LoweredDecl | null {
  const typed = ctx.evaluated.typed.modules.get(entry.module.module.id);
  const evaled = ctx.evaluated.modules.get(entry.module.module.id);
  if (typed === undefined) return null;
  // Layer 4-sugar — a const whose value is structurally a type expression
  // (`Mixed :: i32 | string`) is an implicit type alias. Skip emission :
  // there is no runtime slot to populate, the metatype value is comptime-only.
  // Type-position users of `Mixed` already resolved through `typeFromSymbol`
  // via the `constTypeAliases` table.
  if (typed.constTypeAliases.has(decl)) return null;
  const types = makeEntryTypes(typed, entry.subst);
  const type = types.exprType(decl.value);

  // @comptime / @file values were already baked by the comptime pass — emit
  // the literal directly so downstream phases see the materialized constant
  // rather than re-running the AST.
  const baked = evaled?.comptimeDecls.get(decl) ?? evaled?.fileDecls.get(decl);
  const value: LoweredExpr = baked !== undefined
    ? comptimeValueToLowered(baked, defaultIfFree(type), decl.span)
    : lowerExpr({
        project: ctx, entry, typed, subst: entry.subst, types,
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
export function comptimeValueToLowered(v: ComptimeValue, typeHint: Type, span: Span): LoweredExpr {
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
    case "type":
      // Type-valued comptime values stay comptime — lowering them to a
      // runtime expression is the proper Layer 4 milestone B.1 work
      // (TypeValue end-to-end). Today every `ComptimeValue.type` consumer
      // is a const decl that's already short-circuited via the
      // `constTypeAliases` path in `lowerConstEntry`, so reaching here
      // means a non-const slot held a type — surface as unreachable so
      // the bug is visible.
      return {
        kind: "LoweredUnreachable", span, type: typeHint,
        reason: "comptime type value reached lowering — TypeValue end-to-end is not yet implemented (B.1)",
      };
  }
}
