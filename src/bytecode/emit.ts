// Bytecode emitter — LoweredProject → BytecodeModule. See SPEC §2 ("Lowered
// AST" → bytecode) and §17 (canonical IR).

import type { Span } from "../diagnostics/diagnostic.ts";
import { DEC, hasDecorator } from "../parser/decorators.ts";
import type * as L from "../lower/lowered-ast.ts";
import type { LoweredProject } from "../lower/index.ts";
import type { PrimitiveName, Type } from "../typecheck/types.ts";
import { displayType } from "../typecheck/types.ts";
import type { ImplRegistry } from "../typecheck/impls.ts";

import {
  intrinsicIdByName,
  type ArithOpKind, type BitNotOpKind, type BitOpKind, type CmpOpKind,
  type ConvertOpKind, type IntrinsicId, type NegOpKind, type Op,
} from "./ops.ts";
import type {
  BcImport, BcLocal, BcSignature, BytecodeModule, DebugPos,
} from "./module.ts";
import { runPeepholes } from "./peephole.ts";
import type { BcType, ValType } from "./types.ts";
import { isIntegerVal, isNumericVal } from "./types.ts";

/** Stdlib `@intrinsic` impl methods that map to a dedicated bytecode op
 *  rather than to a host-provided import. Keyed by the impl-method mangled
 *  name (`<module>$<type>$<trait>$<method>`) so the lookup happens after
 *  name-mangling and skips the `call.import` indirection — `s1 + s2` and
 *  `"a".add("b")` both emit the same `string.concat` op. */
/** The 11 numeric primitive types whose Add/Sub/Mul/Div impls are
 *  `@intrinsic`-declared in `std/core` and routed here to the matching
 *  WASM-style numeric op. Mirrors the `NumWidth` set in `bytecode/ops.ts`. */
const NUMERIC_INTRINSIC_TYPES: readonly string[] = [
  "i8", "i16", "i32", "i64",
  "u8", "u16", "u32", "u64", "usize",
  "f32", "f64",
];

const NUMERIC_INTRINSIC_OPS: ReadonlyArray<[string, "add" | "sub" | "mul" | "div"]> = [
  ["Add", "add"], ["Sub", "sub"], ["Mul", "mul"], ["Div", "div"],
];

function buildNumericIntrinsicMap(): ReadonlyMap<string, () => Op> {
  const map = new Map<string, () => Op>();
  map.set("std_core$string$Add$add", () => ({ kind: "string.concat" }));
  for (const ty of NUMERIC_INTRINSIC_TYPES) {
    for (const [trait, method] of NUMERIC_INTRINSIC_OPS) {
      const opKind = `${ty}.${method}` as Op["kind"];
      map.set(`std_core$${ty}$${trait}$${method}`, () => ({ kind: opKind } as Op));
    }
  }
  return map;
}

export const OP_INTRINSIC_BY_MANGLED: ReadonlyMap<string, () => Op> = buildNumericIntrinsicMap();

/** Knobs for the bytecode emitter. Today this only toggles the peephole
 *  pass; future codegen-time options (e.g. inline-thresholds, bound checks)
 *  belong here. */
export interface EmitOptions {
  /** Run peephole optimisations on every function body. Default: `true`. */
  readonly optimize?: boolean;
  /** When provided, trait impl information is recorded in the module's
   *  `implTable` so consumers (VM, C emit) can resolve `match val { is Trait -> … }`. */
  readonly implRegistry?: ImplRegistry;
}

/** Translate the lowerer's pre-flattened vtable entries into per-(trait,
 *  method) tables keyed by the receiver's type index. Shared between the
 *  legacy `LoweredAST → bytecode` path and the CFG-based emitter. */
export function buildVtables(
  ctx: EmitterCtx, entries: readonly L.VtableEntry[],
): Map<string, Map<number, number>> {
  const vtables = new Map<string, Map<number, number>>();
  for (const e of entries) {
    const fnIdx = ctx.fnIndexBySymId.get(e.fnSymbol.id);
    if (fnIdx === undefined) continue;
    const typeIdx = internType(ctx, e.structType);
    const key = `${e.traitName}.${e.methodName}`;
    let table = vtables.get(key);
    if (table === undefined) { table = new Map(); vtables.set(key, table); }
    table.set(typeIdx, fnIdx);
  }
  return vtables;
}

export interface EmitterCtx {
  readonly types: BcType[];
  readonly typeKey: Map<string, number>;          // displayType(t) → index
  readonly strings: string[];
  readonly stringKey: Map<string, number>;
  readonly functions: MutableFn[];
  readonly fnIndexBySymId: Map<number, number>;
  readonly imports: BcImport[];
  readonly importIndexBySymId: Map<number, number>;
  readonly exports: { externName: string; fnIndex: number }[];
  /** Const decls inlined at every use site by `emitIdent`. */
  readonly constDecls: Map<number, L.LoweredConstDecl>;
  readonly optimize: boolean;
  /** Impl table being built: structTypeIndex → set of trait names. */
  readonly implTable: Map<number, string[]>;
  /** Pre-built index: struct symbol id → trait names it implements. Empty when
   *  no `ImplRegistry` was provided. Avoids O(structs × impls) at intern time. */
  readonly traitsBySymbolId: Map<number, string[]>;
}

/** Writable shadow of `BcFunction` — populated during pass 2, returned as the
 *  readonly external shape via covariant assignment. */
interface MutableFn {
  readonly name: string;
  readonly signature: BcSignature;
  locals: BcLocal[];
  body: Op[];
  debug: (DebugPos | null)[];
}

export function newEmitterCtx(optimize: boolean, implRegistry: ImplRegistry | null): EmitterCtx {
  const traitsBySymbolId = new Map<number, string[]>();
  if (implRegistry !== null) {
    for (const entry of implRegistry.entries()) {
      if (entry.forSymbol === null) continue;
      const list = traitsBySymbolId.get(entry.forSymbol.id);
      if (list !== undefined) list.push(entry.traitSymbol.name);
      else traitsBySymbolId.set(entry.forSymbol.id, [entry.traitSymbol.name]);
    }
  }
  return {
    types: [], typeKey: new Map(),
    strings: [], stringKey: new Map(),
    functions: [], fnIndexBySymId: new Map(),
    imports: [], importIndexBySymId: new Map(),
    exports: [],
    constDecls: new Map(),
    optimize,
    implTable: new Map(),
    traitsBySymbolId,
  };
}

// ----------------------------------------------------------- pass 1: reserve

export function reserveDecl(d: L.LoweredDecl, ctx: EmitterCtx): void {
  switch (d.kind) {
    case "LoweredFnDecl":   reserveFn(d, ctx); return;
    case "LoweredStructDecl": internStructDecl(d, ctx); return;
    case "LoweredConstDecl":
      if (d.origin.symbol !== null) ctx.constDecls.set(d.origin.symbol.id, d);
      return;
  }
}

function reserveFn(d: L.LoweredFnDecl, ctx: EmitterCtx): void {
  const sig = signatureOf(d);
  const decoratorList = d.origin.decl.kind === "FnDecl" ? d.origin.decl.decorators : [];
  const externName = d.origin.decl.kind === "FnDecl" ? d.origin.decl.name : d.mangled;
  const isExtern = d.body === null || hasDecorator(decoratorList, DEC.extern);

  if (isExtern) {
    if (d.origin.symbol !== null) ctx.importIndexBySymId.set(d.origin.symbol.id, ctx.imports.length);
    ctx.imports.push({ externName, mangledName: d.mangled, signature: sig });
    return;
  }

  const fnIndex = ctx.functions.length;
  if (d.origin.symbol !== null) ctx.fnIndexBySymId.set(d.origin.symbol.id, fnIndex);
  ctx.functions.push({
    name: d.mangled, signature: sig, locals: [], body: [], debug: [],
  });
  if (hasDecorator(decoratorList, DEC.export)) {
    ctx.exports.push({ externName, fnIndex });
  }
}

// ------------------------------------------------------- pass 2: emit bodies

// ----------------------------------------------------------- per-fn state

export interface FnEmitCtx {
  readonly project: EmitterCtx;
  readonly signature: BcSignature;
  readonly locals: BcLocal[];
  readonly body: Op[];
  readonly debug: (DebugPos | null)[];
  readonly slotBySymbolId: Map<number, number>;
}

export function pushOp(fn: FnEmitCtx, op: Op, span?: Span): void {
  fn.body.push(op);
  fn.debug.push(span === undefined ? null : {
    file: span.start.file, line: span.start.line, column: span.start.column,
  });
}

export function declareLocal(fn: FnEmitCtx, name: string, val: ValType): number {
  const slot = fn.signature.params.length + fn.locals.length;
  fn.locals.push({ name, val });
  return slot;
}

// ----------------------------------------------------------- interning

export function internType(ctx: EmitterCtx, t: Type): number {
  const key = displayType(t);
  const cached = ctx.typeKey.get(key);
  if (cached !== undefined) return cached;
  // Reserve placeholder so recursive/self types don't loop.
  const idx = ctx.types.length;
  ctx.types.push({ kind: "ref", traitName: null });
  ctx.typeKey.set(key, idx);
  ctx.types[idx] = bcTypeOf(t, ctx, idx);
  return idx;
}

function bcTypeOf(t: Type, ctx: EmitterCtx, slotIdx: number): BcType {
  switch (t.kind) {
    case "Primitive": return { kind: "primitive", val: primitiveToVal(t.name) };
    case "Enum":      return { kind: "primitive", val: primitiveToVal(t.repr) };
    case "Struct": {
      // Pass 1 keys interned structs by displayType — same key we'd use here.
      // If it's not present, this is an opaque struct (foreign module / no body).
      return { kind: "ref", traitName: t.symbol.name };
    }
    case "Trait": return { kind: "ref", traitName: t.symbol.name };
    case "Array": return { kind: "array", element: internType(ctx, t.element) };
    case "Tuple": {
      // Synthesise an anonymous struct with fields `_0`, `_1`, ... in element
      // order. The C-emit treats it like any other struct ; the GC scan walks
      // ref-typed slots via the per-type pointer map. The mangled name uses
      // the slot index so two distinct tuple shapes never share a C struct
      // (`[i32, string]` and `[bool, string]` both have arity 2 but emit
      // different `__Tuple_<idx>` types).
      const fields = t.elements.map((e, i) => ({
        name: `_${i}`,
        typeIndex: internType(ctx, e),
      }));
      return { kind: "struct", name: `__Tuple_${slotIdx}`, fields };
    }
    case "Union": return { kind: "union", variants: t.variants.map((v) => internType(ctx, v)) };
    case "Fn":    return {
      kind: "fn",
      params: t.params.map((p) => internType(ctx, p)),
      returnType: internType(ctx, t.returnType),
    };
    default:      return { kind: "ref", traitName: null };
  }
}

/** Synthesise (or look up) a single-slot struct type used by closure cells.
 *  Each cell holds a slot of `slotType`, so we materialise one struct per
 *  distinct slot type — kept distinct from user structs by the `$Cell_…`
 *  name prefix. The C emit treats it like any other struct (it gets a
 *  type-info entry, the GC scans the slot if it's a ref). */
export function internCellType(ctx: EmitterCtx, slotType: Type): number {
  const slotIdx = internType(ctx, slotType);
  const key = `$Cell<${displayType(slotType)}>`;
  const cached = ctx.typeKey.get(key);
  if (cached !== undefined) return cached;
  const idx = ctx.types.length;
  ctx.typeKey.set(key, idx);
  ctx.types.push({
    kind: "struct",
    name: `$Cell_${idx}`,
    fields: [{ name: "value", typeIndex: slotIdx }],
  });
  return idx;
}

function internStructDecl(d: L.LoweredStructDecl, ctx: EmitterCtx): number {
  // Key by the same displayType form `internType` uses for Struct types so a
  // generic instantiation `List(i32)` doesn't collide with `List(i64)`.
  if (d.origin.symbol === null) return -1;
  const structType: Type = { kind: "Struct", symbol: d.origin.symbol, args: d.origin.typeArgs };
  const key = displayType(structType);
  const cached = ctx.typeKey.get(key);
  if (cached !== undefined && ctx.types[cached]?.kind === "struct") return cached;

  const idx = ctx.types.length;
  ctx.typeKey.set(key, idx);
  // Reserve before recursing into field types so self-referential structs
  // (linked-list nodes etc.) terminate.
  ctx.types.push({ kind: "ref", traitName: d.mangled });

  const fields = d.fields.map((f) => ({
    name: f.name, typeIndex: internType(ctx, f.type),
  }));
  ctx.types[idx] = { kind: "struct", name: d.mangled, fields };

  const traits = ctx.traitsBySymbolId.get(d.origin.symbol.id);
  if (traits !== undefined && traits.length > 0) ctx.implTable.set(idx, traits);

  return idx;
}

function primitiveToVal(name: PrimitiveName): ValType {
  // PrimitiveName ⊂ ValType: every primitive is also a stack-machine value type.
  return name;
}

export function internString(ctx: EmitterCtx, s: string): number {
  const cached = ctx.stringKey.get(s);
  if (cached !== undefined) return cached;
  const idx = ctx.strings.length;
  ctx.strings.push(s);
  ctx.stringKey.set(s, idx);
  return idx;
}

// ----------------------------------------------------------- Type → ValType

export function valTypeOf(t: Type): ValType {
  switch (t.kind) {
    case "Primitive": return primitiveToVal(t.name);
    case "Never":     return "void";
    case "FreeInt":   return "i32";
    case "FreeFloat": return "f64";
    case "Unresolved": return "any";
    case "Union":     return "ref";
    case "Enum":    return primitiveToVal(t.repr);
    case "Struct":
    case "Trait":
    case "Array":
    case "Tuple":
    case "Fn":
    case "TypeParam":
    case "TypeMeta":
    case "Self":
      return "ref";
  }
}

/** Coerce to a numeric ValType, defaulting to i32 when the input isn't typed
 *  numerically (e.g. `Unresolved` after recovered errors). Lets the emitter
 *  produce a balanced op stream even when typecheck didn't fully resolve. */
export function asNumeric(t: ValType): ValType {
  return isNumericVal(t) ? t : "i32";
}

export function asInt(t: ValType): ValType {
  return isIntegerVal(t) ? t : "i32";
}

/** Pick the bytecode op for a `LoweredBinaryOp` over operands of `lhsVal`.
 *  Excludes `and` / `or` (those need short-circuit control flow, not a single
 *  op). Shared between the legacy LoweredAST → bytecode emit and the CFG
 *  emit ; the converter lowers `and`/`or` into if/else explicitly so this fn
 *  never sees them. */
export function binaryOpFor(op: L.LoweredBinaryOp, lhsVal: ValType): Op {
  switch (op) {
    case "add": case "sub": case "mul": case "div":
      if (op === "add" && lhsVal === "string") return { kind: "string.concat" };
      return { kind: `${asNumeric(lhsVal)}.${op}` as ArithOpKind };
    case "mod":    return { kind: `${asNumeric(lhsVal)}.rem` as ArithOpKind };
    case "shl":
    case "shr":    return { kind: `${asInt(lhsVal)}.${op}` as BitOpKind };
    case "bitand":
    case "bitor":
    case "bitxor": return { kind: `${asInt(lhsVal)}.${op}` as BitOpKind };
    case "and":    return { kind: "bool.and" };
    case "or":     return { kind: "bool.or" };
    case "eq":     return { kind: cmpKind(lhsVal, "eq") };
    case "neq":    return { kind: cmpKind(lhsVal, "ne") };
    case "lt":     return { kind: cmpKind(lhsVal, "lt") };
    case "lte":    return { kind: cmpKind(lhsVal, "le") };
    case "gt":     return { kind: cmpKind(lhsVal, "gt") };
    case "gte":    return { kind: cmpKind(lhsVal, "ge") };
  }
}

export function cmpKind(lt: ValType, op: "eq" | "ne" | "lt" | "le" | "gt" | "ge"): CmpOpKind {
  if (isNumericVal(lt)) return `${lt}.${op}` as CmpOpKind;
  if (op === "eq" || op === "ne") {
    if (lt === "bool")   return `bool.${op}`;
    if (lt === "string") return `string.${op}`;
    if (lt === "char")   return `char.${op}`;
    return `ref.${op}`;       // ref / any / null / void
  }
  if (lt === "char")   return `char.${op}` as CmpOpKind;
  return `${asNumeric(lt)}.${op}` as CmpOpKind;
}

export function emitIntConst(fn: FnEmitCtx, value: bigint, t: ValType, span: Span): void {
  if (t === "i64" || t === "u64" || t === "usize") {
    pushOp(fn, { kind: "i64.const", value }, span);
  } else {
    pushOp(fn, { kind: "i32.const", value: Number(value) }, span);
  }
}

export function emitFloatConst(fn: FnEmitCtx, value: number, t: ValType, span: Span): void {
  pushOp(fn, { kind: t === "f32" ? "f32.const" : "f64.const", value }, span);
}

function signatureOf(d: L.LoweredFnDecl): BcSignature {
  return {
    params: d.params.map((p) => valTypeOf(p.type)),
    result: valTypeOf(d.returnType),
  };
}

