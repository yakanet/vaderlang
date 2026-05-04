// Type IR. Every Vader value gets one of these. Discriminated union; structural
// equality via `equalsType`; canonical forms via `unionOf` (sort + dedup) so
// `A | B | A` and `B | A` collapse to the same Type.

import type { Symbol } from "../resolver/symbol.ts";

export type Type =
  | PrimitiveType
  | StructType
  | TraitType
  | UnionType
  | FnType
  | ArrayType
  | TypeParamType
  | TypeMetaType
  | SelfType
  | UnresolvedType
  | FreeIntType
  | FreeFloatType
  | NeverType;

export type PrimitiveName =
  | "i8" | "i16" | "i32" | "i64"
  | "u8" | "u16" | "u32" | "u64"
  | "f32" | "f64"
  | "bool" | "char" | "string" | "void" | "null";

export const PRIMITIVE_NAMES: readonly PrimitiveName[] = [
  "i8", "i16", "i32", "i64",
  "u8", "u16", "u32", "u64",
  "f32", "f64",
  "bool", "char", "string", "void", "null",
];

export function isPrimitiveName(name: string): name is PrimitiveName {
  return (PRIMITIVE_NAMES as readonly string[]).includes(name);
}

/** Names of stdlib core traits used for compiler-driven dispatch. */
export const CORE_TRAITS = {
  Display: "Display",
  Error:   "Error",
  Eq:      "Eq",
  Ord:     "Ord",
  Add:     "Add",
  Sub:     "Sub",
  Mul:     "Mul",
  Div:     "Div",
  Hash:    "Hash",
  Clone:   "Clone",
  Iterator: "Iterator",
  Iterable: "Iterable",
} as const;

export interface PrimitiveType {
  readonly kind: "Primitive";
  readonly name: PrimitiveName;
}

export interface StructType {
  readonly kind: "Struct";
  readonly symbol: Symbol;
  readonly args: readonly Type[];
}

export interface TraitType {
  readonly kind: "Trait";
  readonly symbol: Symbol;
  readonly args: readonly Type[];
}

export interface UnionType {
  readonly kind: "Union";
  readonly variants: readonly Type[];   // canonical: sorted by display, deduped
}

export interface FnType {
  readonly kind: "Fn";
  readonly params: readonly Type[];
  readonly returnType: Type;
}

export interface ArrayType {
  readonly kind: "Array";
  readonly element: Type;
}

export interface TypeParamType {
  readonly kind: "TypeParam";
  readonly symbol: Symbol;
}

export interface TypeMetaType {
  readonly kind: "TypeMeta";
}

/** The `Self` type — substituted by the surrounding impl's target type at body-check time. */
export interface SelfType {
  readonly kind: "Self";
}

export interface UnresolvedType {
  readonly kind: "Unresolved";
}

/** Untyped integer literal — flexible until placed in a typed context. */
export interface FreeIntType {
  readonly kind: "FreeInt";
}

/** Untyped float literal — flexible until placed in a typed context. */
export interface FreeFloatType {
  readonly kind: "FreeFloat";
}

/** Bottom type for `return` / `panic` etc. — assignable to anything. */
export interface NeverType {
  readonly kind: "Never";
}

// ---------------------------------------------------------------- constants

const primitive = (name: PrimitiveName): PrimitiveType => ({ kind: "Primitive", name });

export const TY = {
  i8:     primitive("i8"),
  i16:    primitive("i16"),
  i32:    primitive("i32"),
  i64:    primitive("i64"),
  u8:     primitive("u8"),
  u16:    primitive("u16"),
  u32:    primitive("u32"),
  u64:    primitive("u64"),
  f32:    primitive("f32"),
  f64:    primitive("f64"),
  bool:   primitive("bool"),
  char:   primitive("char"),
  string: primitive("string"),
  void:   primitive("void"),
  null:   primitive("null"),
  type:   { kind: "TypeMeta" } as TypeMetaType,
  self:   { kind: "Self" } as SelfType,
  unresolved: { kind: "Unresolved" } as UnresolvedType,
  never:  { kind: "Never" } as NeverType,
  freeInt:   { kind: "FreeInt" } as FreeIntType,
  freeFloat: { kind: "FreeFloat" } as FreeFloatType,
} as const;

export const SIGNED_INTS: readonly PrimitiveName[]   = ["i8", "i16", "i32", "i64"];
export const UNSIGNED_INTS: readonly PrimitiveName[] = ["u8", "u16", "u32", "u64"];
export const ALL_INTS: readonly PrimitiveName[]      = [...SIGNED_INTS, ...UNSIGNED_INTS];
export const FLOATS: readonly PrimitiveName[]        = ["f32", "f64"];
export const NUMERICS: readonly PrimitiveName[]      = [...ALL_INTS, ...FLOATS];

export function isInteger(t: Type): boolean {
  return t.kind === "Primitive" && (ALL_INTS as readonly string[]).includes(t.name);
}
export function isFloat(t: Type): boolean {
  return t.kind === "Primitive" && (FLOATS as readonly string[]).includes(t.name);
}
export function isNumeric(t: Type): boolean {
  return t.kind === "Primitive" && (NUMERICS as readonly string[]).includes(t.name);
}
export function isPrimitive(t: Type, name: PrimitiveName): boolean {
  return t.kind === "Primitive" && t.name === name;
}

// ----------------------------------------------------------------- display

export function displayType(t: Type): string {
  switch (t.kind) {
    case "Primitive":  return t.name;
    case "Struct":     return formatNamed(t.symbol.name, t.args);
    case "Trait":      return formatNamed(t.symbol.name, t.args);
    case "TypeParam":  return `$${t.symbol.name}`;
    case "TypeMeta":   return "type";
    case "Self":       return "Self";
    case "Unresolved": return "?";
    case "Never":      return "never";
    case "FreeInt":    return "{integer}";
    case "FreeFloat":  return "{float}";
    case "Array":      return `[${displayType(t.element)}]`;
    case "Fn": {
      const ps = t.params.map(displayType).join(", ");
      return `fn(${ps}) -> ${displayType(t.returnType)}`;
    }
    case "Union":      return t.variants.map(displayType).join(" | ");
  }
}

function formatNamed(name: string, args: readonly Type[]): string {
  if (args.length === 0) return name;
  return `${name}(${args.map(displayType).join(", ")})`;
}

// ---------------------------------------------------------------- equality

export function equalsType(a: Type, b: Type): boolean {
  if (a === b) return true;
  if (a.kind !== b.kind) return false;
  switch (a.kind) {
    case "Primitive":  return a.name === (b as PrimitiveType).name;
    case "TypeMeta":
    case "Self":
    case "Unresolved":
    case "Never":
    case "FreeInt":
    case "FreeFloat":
      return true;
    case "TypeParam":
      return a.symbol.id === (b as TypeParamType).symbol.id;
    case "Struct":
    case "Trait": {
      const o = b as StructType | TraitType;
      return a.symbol.id === o.symbol.id && argListEquals(a.args, o.args);
    }
    case "Array":
      return equalsType(a.element, (b as ArrayType).element);
    case "Fn": {
      const o = b as FnType;
      return argListEquals(a.params, o.params) && equalsType(a.returnType, o.returnType);
    }
    case "Union": {
      const o = b as UnionType;
      if (a.variants.length !== o.variants.length) return false;
      for (let i = 0; i < a.variants.length; i++) {
        if (!equalsType(a.variants[i]!, o.variants[i]!)) return false;
      }
      return true;
    }
  }
}

function argListEquals(a: readonly Type[], b: readonly Type[]): boolean {
  if (a.length !== b.length) return false;
  for (let i = 0; i < a.length; i++) if (!equalsType(a[i]!, b[i]!)) return false;
  return true;
}

// --------------------------------------------------------- canonical union

/** Build a union from variants — flattens nested unions, dedupes, sorts by display. */
export function unionOf(variants: readonly Type[]): Type {
  const flat: Type[] = [];
  for (const v of variants) {
    if (v.kind === "Union") flat.push(...v.variants);
    else flat.push(v);
  }
  const dedup: Type[] = [];
  for (const t of flat) {
    if (!dedup.some((u) => equalsType(u, t))) dedup.push(t);
  }
  dedup.sort((x, y) => displayType(x).localeCompare(displayType(y)));
  if (dedup.length === 1) return dedup[0]!;
  if (dedup.length === 0) return TY.never;
  return { kind: "Union", variants: dedup };
}

// --------------------------------------------------------- assignability

/**
 * Whether `from` can flow into a slot expecting `to` without an explicit cast.
 *
 * - Identity: T → T
 * - Never: never → T (always)
 * - Unresolved: error already reported, treat as compatible to suppress cascading errors
 * - Free numeric literals: FreeInt → any integer type; FreeFloat → any float type
 * - Union widening: T → A|B|C if T is one of {A, B, C}
 * - Union → Union: every variant of `from` must be assignable to `to`
 *
 * No implicit numeric widening (i32 → i64): explicit cast required (per SPEC §4).
 */
export function isAssignable(from: Type, to: Type): boolean {
  if (from.kind === "Unresolved" || to.kind === "Unresolved") return true;
  if (from.kind === "Never") return true;
  if (equalsType(from, to)) return true;

  if (from.kind === "FreeInt") return to.kind === "Primitive" && (NUMERICS as readonly string[]).includes(to.name);
  if (from.kind === "FreeFloat") return to.kind === "Primitive" && (FLOATS as readonly string[]).includes(to.name);

  if (to.kind === "Union") {
    if (from.kind === "Union") return from.variants.every((v) => isAssignable(v, to));
    return to.variants.some((v) => isAssignable(from, v));
  }
  return false;
}

// --------------------------------------------------------------- visit

/** Visit a Type and all its structural children (post-order traversal). */
export function forEachType(t: Type, visit: (t: Type) => void): void {
  visit(t);
  switch (t.kind) {
    case "Struct":
    case "Trait":
      for (const a of t.args) forEachType(a, visit);
      return;
    case "Array":
      forEachType(t.element, visit);
      return;
    case "Fn":
      for (const p of t.params) forEachType(p, visit);
      forEachType(t.returnType, visit);
      return;
    case "Union":
      for (const v of t.variants) forEachType(v, visit);
      return;
    default:
      return;
  }
}

// --------------------------------------------------------------- substitute

export interface Substitution {
  readonly typeParams?: ReadonlyMap<number, Type>;
  readonly self?: Type;
}

/** Replace `TypeParam` and `Self` occurrences according to the substitution. */
export function substitute(t: Type, subst: Substitution): Type {
  switch (t.kind) {
    case "TypeParam": {
      const repl = subst.typeParams?.get(t.symbol.id);
      return repl ?? t;
    }
    case "Self":
      return subst.self ?? t;
    case "Struct":
    case "Trait": {
      const args = t.args.map((a) => substitute(a, subst));
      return { ...t, args };
    }
    case "Array":
      return { kind: "Array", element: substitute(t.element, subst) };
    case "Fn":
      return {
        kind: "Fn",
        params: t.params.map((p) => substitute(p, subst)),
        returnType: substitute(t.returnType, subst),
      };
    case "Union":
      return unionOf(t.variants.map((v) => substitute(v, subst)));
    default:
      return t;
  }
}

/** Default the free numeric literal types per SPEC §4 ("Default integer", "Float"). */
export function defaultIfFree(t: Type): Type {
  if (t.kind === "FreeInt") return TY.i32;
  if (t.kind === "FreeFloat") return TY.f64;
  return t;
}
