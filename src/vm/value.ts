// Runtime value representation for the VM. Every value carries its tag so
// `type_check` works uniformly for primitives flowing through `ref` slots
// (union variants) without explicit box/unbox ops in the bytecode.

export type Value =
  | NumValue
  | I64Value
  | BoolValue
  | CharValue
  | StringValue
  | NullValue
  | StructValue
  | ArrayValue
  | ErrorValue
  | BuilderValue
  | FnValue
  | VoidValue;

export type ValueTag = Value["tag"];

export type NumTag = NumValue["tag"];

export interface NumValue    { readonly tag: "i8" | "i16" | "i32" | "u8" | "u16" | "u32" | "f32" | "f64"; readonly n: number }
export interface I64Value    { readonly tag: "i64" | "u64" | "usize"; readonly n: bigint }
export interface BoolValue   { readonly tag: "bool"; readonly n: boolean }
export interface CharValue   { readonly tag: "char"; readonly n: number }
export interface StringValue { readonly tag: "string"; readonly n: string }
export interface NullValue   { readonly tag: "null" }
export interface VoidValue   { readonly tag: "void" }

export interface StructValue {
  readonly tag: "struct";
  readonly typeIndex: number;
  readonly fields: Value[];
}

export interface ArrayValue {
  readonly tag: "array";
  readonly typeIndex: number;
  readonly elements: Value[];
}

/** Host-produced error sentinel — passes `type_check` against any `ref Error`
 *  slot. User-defined Error structs use `StructValue` and route via the impl
 *  table (deferred — see TODO §1.8). */
export interface ErrorValue {
  readonly tag: "error";
  readonly message: string;
}

/** StringBuilder backing for the `builder.*` intrinsics. Lives on the value
 *  stack so the bytecode can pass it around as a normal value (the lowerer
 *  emits `local.set/get` on `any`-typed slots). */
export interface BuilderValue {
  readonly tag: "builder";
  readonly parts: string[];
}

/** Function value — fat pointer `{ code, env }`. `fnIndex` selects the bytecode
 *  function to invoke; `env` is null for non-capturing globals and a struct
 *  value for closures (Phase 3). Pushed by `fn.ref`, consumed by `call.indirect`. */
export interface FnValue {
  readonly tag: "fn";
  readonly fnIndex: number;
  readonly env: Value | null;
}

export const VOID: VoidValue = { tag: "void" };
export const NULL: NullValue = { tag: "null" };
export const TRUE:  BoolValue = { tag: "bool", n: true };
export const FALSE: BoolValue = { tag: "bool", n: false };

export function num(tag: NumTag, n: number): NumValue { return { tag, n }; }
export function i64(tag: I64Value["tag"], n: bigint): I64Value { return { tag, n }; }
export function str(s: string): StringValue { return { tag: "string", n: s }; }
export function ch(cp: number): CharValue { return { tag: "char", n: cp }; }
export function bool(b: boolean): BoolValue { return b ? TRUE : FALSE; }
export function err(message: string): ErrorValue { return { tag: "error", message }; }
export function builder(): BuilderValue { return { tag: "builder", parts: [] }; }
export function fnRef(fnIndex: number, env: Value | null = null): FnValue { return { tag: "fn", fnIndex, env }; }

export function asNum(v: Value): number {
  if (v.tag === "i8" || v.tag === "i16" || v.tag === "i32"
   || v.tag === "u8" || v.tag === "u16" || v.tag === "u32"
   || v.tag === "f32" || v.tag === "f64") return v.n;
  throw new Error(`vm: expected numeric, got ${v.tag}`);
}

export function asBig(v: Value): bigint {
  if (v.tag === "i64" || v.tag === "u64" || v.tag === "usize") return v.n;
  throw new Error(`vm: expected i64/u64/usize, got ${v.tag}`);
}

/** Accepts any int-tagged value and projects to a JS number. Used for array
 *  indexes and array lengths, where the source type may be `i32`, `usize`, etc. */
export function asIndex(v: Value): number {
  if (v.tag === "i64" || v.tag === "u64" || v.tag === "usize") return Number(v.n);
  return asNum(v);
}

export function asBool(v: Value): boolean {
  if (v.tag === "bool") return v.n;
  throw new Error(`vm: expected bool, got ${v.tag}`);
}

export function asString(v: Value): string {
  if (v.tag === "string") return v.n;
  throw new Error(`vm: expected string, got ${v.tag}`);
}

export function asChar(v: Value): number {
  if (v.tag === "char") return v.n;
  throw new Error(`vm: expected char, got ${v.tag}`);
}

export function asStruct(v: Value): StructValue {
  if (v.tag === "struct") return v;
  throw new Error(`vm: expected struct, got ${v.tag}`);
}

export function asArray(v: Value): ArrayValue {
  if (v.tag === "array") return v;
  throw new Error(`vm: expected array, got ${v.tag}`);
}

export function asBuilder(v: Value): BuilderValue {
  if (v.tag === "builder") return v;
  throw new Error(`vm: expected builder, got ${v.tag}`);
}

export function asFn(v: Value): FnValue {
  if (v.tag === "fn") return v;
  throw new Error(`vm: expected fn, got ${v.tag}`);
}

/** Implements the `Display` trait per SPEC §9: integers/floats print decimal
 *  (floats get a trailing `.0` when integral, à la Go `%v`), booleans
 *  `true`/`false`, chars print the codepoint as a string, null is `null`,
 *  strings print verbatim. */
export function displayValue(v: Value): string {
  switch (v.tag) {
    case "string":  return v.n;
    case "bool":    return v.n ? "true" : "false";
    case "null":    return "null";
    case "char":    return String.fromCodePoint(v.n);
    case "void":    return "()";
    case "i8":  case "i16": case "i32":
    case "u8":  case "u16": case "u32":
      return Math.trunc(v.n).toString();
    case "f32": case "f64":
      if (Number.isInteger(v.n) && Number.isFinite(v.n)) return `${v.n.toString()}.0`;
      return v.n.toString();
    case "i64": case "u64": case "usize":
      return v.n.toString();
    case "error":   return `Error("${v.message}")`;
    case "struct":
      return `${v.typeIndex}{ ${v.fields.map(displayValue).join(", ")} }`;
    case "array":
      return `[${v.elements.map(displayValue).join(", ")}]`;
    case "builder":
      return `<builder len=${v.parts.length}>`;
    case "fn":
      return `<fn ${v.fnIndex}${v.env === null ? "" : "+env"}>`;
  }
}
