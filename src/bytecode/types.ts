// Bytecode-level type primitives.
//   - `ValType` — stack-machine value type, à la WASM, plus Vader's `ref`/`any`.
//   - `BcType`  — type-table entries referenced by index from struct/array/
//                 type_check ops.

import type { PrimitiveName } from "../typecheck/types.ts";
import { ALL_INTS, FLOATS, NUMERICS } from "../typecheck/types.ts";

export type ValType =
  | PrimitiveName
  | "ref"
  | "any";

const VAL_TYPE_SET = new Set<ValType>([
  "i8", "i16", "i32", "i64", "isize",
  "u8", "u16", "u32", "u64", "usize",
  "f32", "f64",
  "bool", "char", "string", "null", "void", "ref", "any",
]);

export function isValType(s: string): s is ValType {
  return VAL_TYPE_SET.has(s as ValType);
}

export function isIntegerVal(t: ValType): boolean {
  return (ALL_INTS as readonly string[]).includes(t);
}

export function isFloatVal(t: ValType): boolean {
  return (FLOATS as readonly string[]).includes(t);
}

export function isNumericVal(t: ValType): boolean {
  return (NUMERICS as readonly string[]).includes(t);
}

// =========================================================================
// Type-table entries
// =========================================================================

export type BcType =
  | BcPrimitive
  | BcStruct
  | BcArray
  | BcUnion
  | BcRef
  | BcFn;

/** Plain primitive — wraps a `ValType` with a stable index. */
export interface BcPrimitive {
  readonly kind: "primitive";
  readonly val: ValType;
}

/** Concrete struct, post-monomorphization. Field order is significant. */
export interface BcStruct {
  readonly kind: "struct";
  readonly name: string;          // mangled name from the lowerer
  readonly fields: readonly BcField[];
}

export interface BcField {
  readonly name: string;
  readonly typeIndex: number;     // index into BytecodeModule.types
}

export interface BcArray {
  readonly kind: "array";
  readonly element: number;       // type index of element
}

/** Union of variants, each variant referenced by type index. The runtime
 *  representation uses a tag (the variant's index in this list) plus a
 *  payload slot wide enough for the largest variant. */
export interface BcUnion {
  readonly kind: "union";
  readonly variants: readonly number[];   // type indices
}

/** Open reference type — used only for traits-as-values that escaped mono.
 *  Effectively `ref any` from the verifier's point of view. */
export interface BcRef {
  readonly kind: "ref";
  readonly traitName: string | null;       // for diagnostics; not load-bearing
}

/** Function-value signature. Referenced by `call.indirect` to validate the
 *  call site's stack shape and (in C-emit) to pick the right function-pointer
 *  cast. Param/return slots are type indices into the same type table. */
export interface BcFn {
  readonly kind: "fn";
  readonly params: readonly number[];
  readonly returnType: number;
}

/** Recognise the `T | null` pattern where `T` is a single heap-allocated
 *  type (struct or array). When this fires, the c-emit stores the field as
 *  a raw `void*` (NULL = the null variant, non-null = the `T` payload) — 8
 *  bytes vs 24 for a full `vader_box_t`. Returns the type index of the `T`
 *  variant, or `null` when the union doesn't match. */
export function nullableRefVariant(union: BcUnion, types: readonly BcType[]): number | null {
  if (union.variants.length !== 2) return null;
  const [a, b] = union.variants as readonly [number, number];
  const ta = types[a], tb = types[b];
  if (ta === undefined || tb === undefined) return null;
  const isNullPrim = (t: BcType): boolean => t.kind === "primitive" && t.val === "null";
  const isHeapRef = (t: BcType): boolean => t.kind === "struct" || t.kind === "array";
  if (isNullPrim(ta) && isHeapRef(tb)) return b;
  if (isNullPrim(tb) && isHeapRef(ta)) return a;
  return null;
}
