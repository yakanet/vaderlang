// Stack-based bytecode op table. WASM-aligned for the eventual 1:1 WASM
// emitter (§1.10), but trimmed to what the lowered IR needs.
//
// Conventions:
//   - Every op consumes some types from the stack and pushes some types.
//     The (types-in → types-out) signature is documented per kind below.
//   - Control-flow ops use the WASM "structured" model: `block`/`loop`/`if`
//     open scopes that `end` closes. `br <depth>` jumps to the start of the
//     `loop` at that depth or to the end of the `block`/`if` at that depth.
//   - Type indices reference `BytecodeModule.types`; string indices reference
//     `BytecodeModule.strings`; function indices reference `BytecodeModule.functions`;
//     intrinsic IDs reference the fixed `INTRINSIC_TABLE` below.

import type { ValType } from "./types.ts";

// =========================================================================
// Op discriminated union
// =========================================================================

export type Op =
  // -- Stack manipulation -------------------------------------------------
  | { readonly kind: "drop" }                                  // pop one
  | { readonly kind: "dup" }                                   // duplicate top

  // -- Locals -------------------------------------------------------------
  | { readonly kind: "local.get"; readonly slot: number }      // ⇒ T
  | { readonly kind: "local.set"; readonly slot: number }      // T ⇒
  | { readonly kind: "local.tee"; readonly slot: number }      // T ⇒ T  (set + leave)

  // -- Constants ----------------------------------------------------------
  | { readonly kind: "i32.const";    readonly value: number }
  | { readonly kind: "i64.const";    readonly value: bigint }
  | { readonly kind: "f32.const";    readonly value: number }
  | { readonly kind: "f64.const";    readonly value: number }
  | { readonly kind: "bool.const";   readonly value: boolean }
  | { readonly kind: "char.const";   readonly value: number }   // u32 codepoint
  | { readonly kind: "null.const" }
  | { readonly kind: "string.const"; readonly index: number }   // string-pool idx

  // -- Arithmetic — typed ------------------------------------------------
  | { readonly kind: ArithOpKind }

  // -- Bitwise / shifts (integer types only) -----------------------------
  | { readonly kind: BitOpKind }

  // -- Comparison — typed ------------------------------------------------
  | { readonly kind: CmpOpKind }

  // -- Logical (bool inputs/outputs; non-short-circuit; lowerer emits
  //    short-circuit forms via if/else where it matters) -----------------
  | { readonly kind: "bool.and" }
  | { readonly kind: "bool.or" }
  | { readonly kind: "bool.not" }

  // -- Unary numeric ------------------------------------------------------
  | { readonly kind: NegOpKind }
  | { readonly kind: BitNotOpKind }

  // -- Numeric conversions -----------------------------------------------
  | { readonly kind: ConvertOpKind }

  // -- Reference cast (no runtime effect; used after a type_check) -------
  | { readonly kind: "ref.cast"; readonly typeIndex: number }

  // -- Control flow (structured) -----------------------------------------
  | { readonly kind: "block"; readonly result: ValType }        // void = no result
  | { readonly kind: "loop";  readonly result: ValType }
  | { readonly kind: "if";    readonly result: ValType }
  | { readonly kind: "else" }
  | { readonly kind: "end" }
  | { readonly kind: "br";    readonly depth: number }
  | { readonly kind: "br_if"; readonly depth: number }
  | { readonly kind: "return" }
  // Fused `<T>.const X ; return` — the inner const stays as a typed
  // value so every backend inlines the literal in its own dialect
  // without re-detecting the pattern.
  | { readonly kind: "return.lit"; readonly value: ConstOp }
  | { readonly kind: "unreachable" }

  // -- Calls --------------------------------------------------------------
  /** Direct call to a bytecode fn. `expectedResultType` is the BcType
   *  index of the destination local's static type at the call site ;
   *  the C-emit consults it to detect erasure-induced layout mismatch
   *  (callee's body returns the Any-substituted heap form while the
   *  caller expects the concrete inline form) and insert a boundary
   *  conversion. `argTypeIndices` is the per-arg BcType index of the
   *  caller's static argument type — symmetric purpose, the C-emit
   *  reshapes a concrete-shape arg into the callee's expected Any
   *  layout before the call when they diverge. */
  | { readonly kind: "call"; readonly fnIndex: number; readonly expectedResultType?: number; readonly argTypeIndices?: readonly number[] }
  | { readonly kind: "call.import"; readonly importIndex: number }
  | { readonly kind: "call.indirect"; readonly typeIndex: number }   // …args, fn ref ⇒ result
  | { readonly kind: "fn.ref"; readonly fnIndex: number; readonly typeIndex: number }  // ⇒ fn ref
  | { readonly kind: "make_closure"; readonly fnIndex: number; readonly typeIndex: number }   // env ⇒ closure (fn ref + env)
  | { readonly kind: "intrinsic";   readonly id: IntrinsicId }
  /** Virtual dispatch through the module's vtable. Stack: …args, receiver ⇒ result.
   *  `vtableKey` keys `BytecodeModule.vtables`; the runtime indexes by the
   *  receiver's type tag to pick the impl fn. `paramCount` includes the
   *  receiver — matches the impl fn's arity. `resultTypeIndex` is the
   *  BcType index of the destination local's static type (when known) ;
   *  the C-emit consults it after the helper call to detect erasure-
   *  layout mismatch (body returns `Yield(Any)` heap-form while the call
   *  site expects `Yield(i32)` inline-form) and insert an unbox+repack
   *  conversion. The VM ignores it (values are dynamically typed). */
  | { readonly kind: "virtual.call"; readonly vtableKey: string; readonly paramCount: number; readonly resultTypeIndex?: number }

  // -- Struct (GC-style) --------------------------------------------------
  | { readonly kind: "struct.new"; readonly typeIndex: number }
  // Stack-allocated struct — emitted when escape analysis proves the value
  // can't outlive the fn. The C-emit allocates the storage on the C stack
  // (avoids GC pressure); the VM treats it as a regular heap struct.
  | { readonly kind: "struct.new_stack"; readonly typeIndex: number }
  | { readonly kind: "struct.get"; readonly typeIndex: number; readonly fieldIndex: number }
  | { readonly kind: "struct.set"; readonly typeIndex: number; readonly fieldIndex: number }
  // Field write to a target the escape analysis proved stack-allocated. The
  // C-emit skips the `VADER_WRITE_BARRIER` macro it would otherwise emit
  // after the store ; runtime semantics are identical to `struct.set`.
  | { readonly kind: "struct.set_stack"; readonly typeIndex: number; readonly fieldIndex: number }

  // -- Array --------------------------------------------------------------
  | { readonly kind: "array.new"; readonly typeIndex: number; readonly length: number }
  | { readonly kind: "array.get"; readonly typeIndex: number }
  | { readonly kind: "array.set"; readonly typeIndex: number }
  | { readonly kind: "array.len" }
  | { readonly kind: "array.push"; readonly typeIndex: number }
  /* Zero-copy slice : pops `arr`, `lo`, `hi` (in that order on the stack);
   * pushes a fresh array header sharing `arr->buf`. Bounds are clamped at
   * runtime so out-of-range indices yield a shorter view rather than trap. */
  | { readonly kind: "array.slice"; readonly typeIndex: number }

  // -- Data pool (module-level static array) -----------------------------
  /** Push a ref to the module's `dataPool[poolIndex]` entry. `typeIndex` is
   *  the BcType index of the `const T[]` so the resulting box carries the
   *  right tag. The runtime points at static `.rodata` storage ; the GC
   *  scanner's arena bound checks leave it untouched. */
  | { readonly kind: "data.const"; readonly poolIndex: number; readonly typeIndex: number }

  // -- String arithmetic (`string.eq`/`string.ne` live in CmpOpKind above) --
  | { readonly kind: "string.concat" }

  // -- Type tag check (returns bool; for `is T` patterns) ----------------
  | { readonly kind: "type_check"; readonly typeIndex: number }

  // -- Type as a first-class value ---------------------------------------
  // Pushes a `TypeValue` carrying `typeIndex` so a `t :: TypeMeta` alias
  // used in value position flows through the VM. Round-trips with
  // `ComptimeValue.type`.
  | { readonly kind: "type.const"; readonly typeIndex: number };

/** Primitive literal-producing ops. Carried by `return.lit` so the
 *  fused op stays self-describing for every backend. */
export type ConstOp = Extract<Op, {
  readonly kind:
    | "i32.const" | "i64.const" | "f32.const" | "f64.const"
    | "bool.const" | "char.const" | "null.const" | "string.const";
}>;

export function isConstOp(op: Op): op is ConstOp {
  switch (op.kind) {
    case "i32.const": case "i64.const": case "f32.const": case "f64.const":
    case "bool.const": case "char.const": case "null.const": case "string.const":
      return true;
    default:
      return false;
  }
}

// =========================================================================
// Per-type op-kind families (kept as string unions so we don't repeat
// the same shape line for every primitive width)
// =========================================================================

type IntWidth   = "i8" | "i16" | "i32" | "i64" | "isize" | "u8" | "u16" | "u32" | "u64" | "usize";
type FloatWidth = "f32" | "f64";
type NumWidth   = IntWidth | FloatWidth;

export type ArithOpKind =
  | `${NumWidth}.add` | `${NumWidth}.sub` | `${NumWidth}.mul`
  | `${NumWidth}.div` | `${NumWidth}.rem`;

export type BitOpKind =
  | `${IntWidth}.bitand` | `${IntWidth}.bitor` | `${IntWidth}.bitxor`
  | `${IntWidth}.shl` | `${IntWidth}.shr`;

export type CmpOpKind =
  | `${NumWidth}.eq` | `${NumWidth}.ne`
  | `${NumWidth}.lt` | `${NumWidth}.le`
  | `${NumWidth}.gt` | `${NumWidth}.ge`
  | "bool.eq" | "bool.ne"
  | "string.eq" | "string.ne"
  | "char.eq" | "char.ne"
  | "char.lt" | "char.le" | "char.gt" | "char.ge"
  | "ref.eq" | "ref.ne";

export type NegOpKind    = `${NumWidth}.neg`;
export type BitNotOpKind = `${IntWidth}.bitnot`;

/** Reflexive (e.g. `i32.to_i32`) ops are a no-op but kept to keep the
 *  emitter uniform. The `from`/`to` widths are independent. `char` participates
 *  on both sides — its wire format is u32 but the value tag must be retagged. */
type ConvertWidth = NumWidth | "char";
export type ConvertOpKind = `${ConvertWidth}.to_${ConvertWidth}`;

// =========================================================================
// Intrinsics
//
// IDs are stable so `.vir` round-trips don't need to re-resolve them. Adding
// an intrinsic is append-only; never reuse an ID. Names are sourced from
// `src/lower/lowered-ast.ts` so the lowerer and the bytecode share one
// source of truth.
// =========================================================================

import type { IntrinsicName } from "../lower/lowered-ast.ts";
import { INTRINSICS } from "../lower/lowered-ast.ts";

export type { IntrinsicName };

export const INTRINSIC_TABLE = {
  builderNew:           { id: 0, name: INTRINSICS.builderNew,           inArity: 0, hasResult: true  },
  builderAppendStr:     { id: 1, name: INTRINSICS.builderAppendStr,     inArity: 2, hasResult: false },
  builderAppendDisplay: { id: 2, name: INTRINSICS.builderAppendDisplay, inArity: 2, hasResult: false },
  builderFinish:        { id: 3, name: INTRINSICS.builderFinish,        inArity: 1, hasResult: true  },
  // Layer 4 §1.19 B.2 — pop a TypeValue, look up `module.types[typeIndex]`,
  // push usize size. The static-type path of `@size_of(T)` stays an inline
  // IntLit ; this intrinsic only fires when the arg is a runtime-resolved
  // `type` value (e.g. an `t: type` fn param).
  sizeOfType:           { id: 4, name: INTRINSICS.sizeOfType,           inArity: 1, hasResult: true  },
} as const;

export type IntrinsicId = typeof INTRINSIC_TABLE[keyof typeof INTRINSIC_TABLE]["id"];

const INTRINSIC_BY_ID = new Map<number, IntrinsicName>(
  Object.values(INTRINSIC_TABLE).map((e) => [e.id, e.name]),
);
const INTRINSIC_BY_NAME = new Map<string, IntrinsicId>(
  Object.values(INTRINSIC_TABLE).map((e) => [e.name, e.id as IntrinsicId]),
);

export function intrinsicNameById(id: number): IntrinsicName | null {
  return INTRINSIC_BY_ID.get(id) ?? null;
}

export function intrinsicIdByName(name: string): IntrinsicId | null {
  return INTRINSIC_BY_NAME.get(name) ?? null;
}
