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

/** Native-runtime element-storage discriminator. Mirrors the
 *  `vader_array_kind_t` enum in `runtime/c/vader.h` ; the bytecode emitter
 *  + VMs compute this once per array type and pass it to the runtime so
 *  primitive arrays store raw values instead of boxed slots. */
export type ArrayKind =
  | "boxed"
  | "u8" | "u16" | "u32" | "u64"
  | "i8" | "i16" | "i32" | "i64"
  | "f32" | "f64"
  | "char" | "bool";

const ARRAY_KIND_INDEX: Record<ArrayKind, number> = {
  boxed: 0,
  u8: 1, u16: 2, u32: 3, u64: 4,
  i8: 5, i16: 6, i32: 7, i64: 8,
  f32: 9, f64: 10,
  char: 11, bool: 12,
};

export function arrayKindIndex(k: ArrayKind): number {
  return ARRAY_KIND_INDEX[k];
}

/** Map a BcType (the element of an array) to its native storage class.
 *  Anything that's not a small fixed-width primitive collapses to `boxed`
 *  — strings, structs, unions, refs, fns all live in a `vader_box_t` slot. */
export function arrayKindOf(element: BcType): ArrayKind {
  if (element.kind !== "primitive") return "boxed";
  switch (element.val) {
    case "u8":    return "u8";
    case "u16":   return "u16";
    case "u32":   return "u32";
    case "u64":   case "usize":  return "u64";
    case "i8":    return "i8";
    case "i16":   return "i16";
    case "i32":   return "i32";
    case "i64":   case "isize":  return "i64";
    case "f32":   return "f32";
    case "f64":   return "f64";
    case "char":  return "char";
    case "bool":  return "bool";
    default:      return "boxed";  // string, null, void, ref, any
  }
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
  // T must be a heap-allocated struct here. If it's an inline-variant struct
  // (representable in vader_box_t.payload, see `inlineVariantPayload` below),
  // skip B1 — the value is already inline so there's no heap pointer to fold
  // into a raw void* slot.
  const isHeapRef = (t: BcType): boolean => {
    if (t.kind === "array") return true;
    if (t.kind === "struct") return inlineVariantPayload(t, types) === null;
    return false;
  };
  if (isNullPrim(ta) && isHeapRef(tb)) return b;
  if (isNullPrim(tb) && isHeapRef(ta)) return a;
  return null;
}

/** Classify a struct as an "inline-variant" — every instance fits entirely
 *  in `vader_box_t`'s tag + payload, so the c-emit can encode it as a bare
 *  `vader_box_t` with no heap allocation. Two shapes match :
 *
 *    - empty struct (e.g. `Done {}`) → tag alone identifies the value
 *    - one-field struct whose field is a primitive (`Yielded { value: i32 }`,
 *      `Some { value: f64 }`, …) → the field's value rides in `payload.i` /
 *      `payload.f` / `payload.b` / `payload.s`
 *
 *  Multi-field structs and structs holding a heap ref / nested box return
 *  null — those payloads don't fit in a single `vader_box_t.payload` slot.
 *
 *  Returned value :
 *    - `null` — not inline-variant, heap-allocated as before
 *    - `"void"` — empty struct ; `vader_box_obj(tag, NULL)` encodes it
 *    - the field's `ValType` (a primitive name) — the field's value goes
 *      into the matching payload slot
 */
export function inlineVariantPayload(t: BcStruct, types: readonly BcType[]): ValType | "void" | null {
  if (t.fields.length === 0) return "void";
  if (t.fields.length > 1) return null;
  const fieldType = types[t.fields[0]!.typeIndex];
  if (fieldType === undefined || fieldType.kind !== "primitive") return null;
  // `void` and `null` aren't legitimate single-field types ; everything else
  // (ints, floats, bool, char, string) fits in vader_box_t.payload.
  if (fieldType.val === "void" || fieldType.val === "null") return null;
  return fieldType.val;
}
