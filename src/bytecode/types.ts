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

const ARRAY_KIND_BY_INDEX: ArrayKind[] = (() => {
  const out: ArrayKind[] = new Array(13);
  for (const [name, idx] of Object.entries(ARRAY_KIND_INDEX)) out[idx] = name as ArrayKind;
  return out;
})();

export function arrayKindIndex(k: ArrayKind): number {
  return ARRAY_KIND_INDEX[k];
}

export function arrayKindFromIndex(idx: number): ArrayKind | null {
  return ARRAY_KIND_BY_INDEX[idx] ?? null;
}

/** Byte width per slot of a primitive array kind. `boxed` is the size of
 *  `vader_box_t` (24 B) on native but pool entries never use it — primitive
 *  arrays only. Returns 0 for unrecognised kinds so callers can guard. */
export function arrayKindElementSize(k: ArrayKind): number {
  switch (k) {
    case "u8":   case "i8":   case "bool": return 1;
    case "u16":  case "i16":               return 2;
    case "u32":  case "i32":  case "f32":  case "char": return 4;
    case "u64":  case "i64":  case "f64":  return 8;
    case "boxed":                          return 0;
  }
}

/** Size in bytes of a `BcType` — primitives use their native widths, every
 *  reference shape (struct, array, union, ref, fn) fits in `vader_box_t`
 *  (16 bytes) at the boxed boundary. Backs the `@size_of(t)` runtime path
 *  (TS VM `runIntrinsic`, c-emit `vader_type_size[]` table) ; the Vader VM
 *  carries a parallel `size_of_bc_type` in `vader/vm/value.vader`. */
export function sizeOfBcType(t: BcType): number {
  if (t.kind !== "primitive") return 16;
  switch (t.val) {
    case "i8": case "u8": case "bool":  return 1;
    case "i16": case "u16":              return 2;
    case "i32": case "u32": case "f32":
    case "char":                          return 4;
    case "i64": case "u64": case "f64":
    case "isize": case "usize":           return 8;
    case "string":                        return 16;
    case "void": case "null":             return 0;
    default:                              return 0;
  }
}

/** Pack a bigint payload into `dv` at `offset` using the LE byte image for
 *  `kind`. Shared between `bytecode/text.ts` and `bytecode/binary.ts` ;
 *  `data N <kind> hex"..."` text + binary section encode the same bytes. */
export function writeArrayKindLE(dv: DataView, offset: number, kind: ArrayKind, v: bigint): void {
  switch (kind) {
    case "u8":   dv.setUint8(offset, Number(BigInt.asUintN(8, v))); return;
    case "i8":   dv.setInt8(offset, Number(BigInt.asIntN(8, v))); return;
    case "bool": dv.setUint8(offset, v === 0n ? 0 : 1); return;
    case "u16":  dv.setUint16(offset, Number(BigInt.asUintN(16, v)), true); return;
    case "i16":  dv.setInt16(offset, Number(BigInt.asIntN(16, v)), true); return;
    case "u32":  dv.setUint32(offset, Number(BigInt.asUintN(32, v)), true); return;
    case "i32":  dv.setInt32(offset, Number(BigInt.asIntN(32, v)), true); return;
    case "char": dv.setUint32(offset, Number(BigInt.asUintN(32, v)), true); return;
    case "f32":  dv.setUint32(offset, Number(BigInt.asUintN(32, v)), true); return;
    case "u64":  dv.setBigUint64(offset, BigInt.asUintN(64, v), true); return;
    case "i64":  dv.setBigInt64(offset, BigInt.asIntN(64, v), true); return;
    case "f64":  dv.setBigUint64(offset, BigInt.asUintN(64, v), true); return;
    case "boxed": throw new Error("bytecode: data pool kind 'boxed' not allowed");
  }
}

/** Inverse of `writeArrayKindLE`. Returns the element as a bigint payload
 *  (IEEE 754 bit pattern for floats). */
export function readArrayKindLE(dv: DataView, offset: number, kind: ArrayKind): bigint {
  switch (kind) {
    case "u8":   return BigInt(dv.getUint8(offset));
    case "i8":   return BigInt(dv.getInt8(offset));
    case "bool": return BigInt(dv.getUint8(offset) !== 0 ? 1 : 0);
    case "u16":  return BigInt(dv.getUint16(offset, true));
    case "i16":  return BigInt(dv.getInt16(offset, true));
    case "u32":  return BigInt(dv.getUint32(offset, true));
    case "i32":  return BigInt(dv.getInt32(offset, true));
    case "char": return BigInt(dv.getUint32(offset, true));
    case "f32":  return BigInt(dv.getUint32(offset, true));
    case "u64":  return dv.getBigUint64(offset, true);
    case "i64":  return dv.getBigInt64(offset, true);
    case "f64":  return dv.getBigUint64(offset, true);
    case "boxed": throw new Error("bytecode: data pool kind 'boxed' not allowed");
  }
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
// Data pool — module-level static arrays of primitive elements that the
// runtime materialises once (`.rodata` on native, pre-built `ArrayVal` in
// the VM). Lowered AST routes eligible `const T[]` decls here ; references
// resolve via the `data.const` op.
// =========================================================================

export interface BcDataEntry {
  readonly kind: ArrayKind;          // never "boxed" — primitive arrays only
  /** One entry per array element. bigint covers every integer width without
   *  precision loss ; for f32/f64 entries it carries the IEEE 754 bit pattern. */
  readonly items: readonly bigint[];
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
  // T must be representable as a single heap pointer. Three cases qualify :
  //   - array : always heap-backed by its `vader_array_t` body.
  //   - heap struct : full allocation, the pointer is the obj header.
  //   - inline-ref struct (`Yield(Entry)` shape) : the wrapper has zero
  //     storage of its own ; its `payload.obj` is the referent's pointer.
  //     Folding this slot to `void*` works because the consumer rewraps the
  //     pointer with the wrapper's type tag, and `struct.get` on the
  //     wrapper's single field reads `payload.obj` and re-tags with the
  //     field type (cf. `emitStructGet` inline-ref branch).
  //
  // The primitive-payload inline-variant (`Yielded(i32)` shape) is excluded :
  // the value lives in `payload.i` / `payload.f`, not in a pointer slot.
  const isHeapRef = (t: BcType): boolean => {
    if (t.kind === "array") return true;
    if (t.kind === "struct") {
      const inline = inlineVariantPayload(t, types);
      return inline === null || inline === "ref";
    }
    return false;
  };
  if (isNullPrim(ta) && isHeapRef(tb)) return b;
  if (isNullPrim(tb) && isHeapRef(ta)) return a;
  return null;
}

/** Classify a struct as an "inline-variant" — every instance fits entirely
 *  in `vader_box_t`'s tag + payload, so the c-emit can encode it as a bare
 *  `vader_box_t` with no heap allocation. Three shapes match :
 *
 *    - empty struct (e.g. `null { … }` style) → tag alone identifies the value
 *    - one-field struct whose field is a primitive (`Yield { value: i32 }`,
 *      `Some { value: f64 }`, …) → the field's value rides in `payload.i` /
 *      `payload.f` / `payload.b` / `payload.s`
 *    - one-field struct whose field is a heap ref (`Yield { value: Entry }`,
 *      `Some { value: SomeStruct }`, …) → the field's obj pointer rides in
 *      `payload.obj` directly. The wrapper disappears at runtime ; the GC
 *      must recognise this tag and trace `payload.obj` as a ref to a
 *      different-tagged object (see `VADER_TYPE_KIND_INLINE_REF`).
 *
 *  Multi-field structs and structs holding a union / fn / Yield-of-Yield
 *  return null — those payloads don't fit a single `vader_box_t.payload`.
 *
 *  Returned value :
 *    - `null` — not inline-variant, heap-allocated as before
 *    - `"void"` — empty struct ; `vader_box_obj(tag, NULL)` encodes it
 *    - the field's `ValType` (a primitive name) — the field's value goes
 *      into the matching payload slot
 *    - `"ref"` — single-ref-field shape ; `payload.obj` is the field's
 *      obj pointer, the wrapper struct is never allocated
 */
export function inlineVariantPayload(t: BcStruct, types: readonly BcType[]): ValType | "void" | "ref" | null {
  if (t.fields.length === 0) return "void";
  if (t.fields.length > 1) return null;
  // Closure-cell wrapper structs (`$Cell_N`) are designed for cross-closure
  // sharing : a captured local is held in the cell and every closure
  // referencing it reads/writes through the *same* cell. Inlining would
  // break that aliasing — two cell values with the same primitive payload
  // would be observationally equal, but each closure expects an
  // independent cell to write into. The `struct.set` detection in
  // `computeMutatedStructs` catches cells that are actually mutated in
  // the current module, but a cell that's only `CellNew + CellGet` in
  // this module would slip through ; closures still treat it as a mutable
  // box. Cheaper to exclude every Cell type up-front than to detect
  // late-bound writes.
  if (t.name.startsWith("$Cell_")) return null;
  const fieldType = types[t.fields[0]!.typeIndex];
  if (fieldType === undefined) return null;
  if (fieldType.kind === "primitive") {
    // `void` and `null` aren't legitimate single-field types ; everything else
    // (ints, floats, bool, char, string) fits in vader_box_t.payload.
    if (fieldType.val === "void" || fieldType.val === "null") return null;
    return fieldType.val;
  }
  // Heap-ref single field — struct or array. The wrapper struct itself
  // never allocates ; the field's obj pointer IS the inline-variant's
  // payload. Skip when the field's own type is *also* inline-variant
  // (e.g. `Box(Box(i32))`) — the inner box doesn't carry a heap pointer
  // we could borrow, just a primitive payload overlapping the `obj` slot
  // of the union. Arrays are always heap-backed by their `vader_array_t`,
  // so the `payload.obj` slot is always a real pointer.
  if (fieldType.kind === "array") return "ref";
  if (fieldType.kind === "struct" && inlineVariantPayload(fieldType, types) === null) return "ref";
  return null;
}
