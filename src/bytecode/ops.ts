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
  | { readonly kind: "unreachable" }

  // -- Calls --------------------------------------------------------------
  | { readonly kind: "call"; readonly fnIndex: number }
  | { readonly kind: "call.import"; readonly importIndex: number }
  | { readonly kind: "call.indirect"; readonly typeIndex: number }   // …args, fn ref ⇒ result
  | { readonly kind: "fn.ref"; readonly fnIndex: number; readonly typeIndex: number }  // ⇒ fn ref
  | { readonly kind: "make_closure"; readonly fnIndex: number; readonly typeIndex: number }   // env ⇒ closure (fn ref + env)
  | { readonly kind: "intrinsic";   readonly id: IntrinsicId }

  // -- Struct (GC-style) --------------------------------------------------
  | { readonly kind: "struct.new"; readonly typeIndex: number }
  | { readonly kind: "struct.get"; readonly typeIndex: number; readonly fieldIndex: number }
  | { readonly kind: "struct.set"; readonly typeIndex: number; readonly fieldIndex: number }

  // -- Array --------------------------------------------------------------
  | { readonly kind: "array.new"; readonly typeIndex: number; readonly length: number }
  | { readonly kind: "array.get"; readonly typeIndex: number }
  | { readonly kind: "array.set"; readonly typeIndex: number }
  | { readonly kind: "array.len" }
  | { readonly kind: "array.push"; readonly typeIndex: number }

  // -- String arithmetic (`string.eq`/`string.ne` live in CmpOpKind above) --
  | { readonly kind: "string.concat" }

  // -- Type tag check (returns bool; for `is T` patterns) ----------------
  | { readonly kind: "type_check"; readonly typeIndex: number };

// =========================================================================
// Per-type op-kind families (kept as string unions so we don't repeat
// the same shape line for every primitive width)
// =========================================================================

type IntWidth   = "i8" | "i16" | "i32" | "i64" | "u8" | "u16" | "u32" | "u64" | "usize";
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
  | "ref.eq" | "ref.ne";

export type NegOpKind    = `${NumWidth}.neg`;
export type BitNotOpKind = `${IntWidth}.bitnot`;

/** Reflexive (e.g. `i32.to_i32`) ops are a no-op but kept to keep the
 *  emitter uniform. The `from`/`to` widths are independent. */
export type ConvertOpKind = `${NumWidth}.to_${NumWidth}`;

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
