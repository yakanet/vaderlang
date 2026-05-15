// Type IR. Every Vader value gets one of these. Discriminated union; structural
// equality via `equalsType`; canonical forms via `unionOf` (sort + dedup) so
// `A | B | A` and `B | A` collapse to the same Type.

import type { Symbol } from "../resolver/symbol.ts";

export type Type =
  | PrimitiveType
  | StructType
  | EnumType
  | TraitType
  | UnionType
  | FnType
  | ArrayType
  | TupleType
  | TypeParamType
  | TypeMetaType
  | SelfType
  | UnresolvedType
  | FreeIntType
  | FreeFloatType
  | NeverType;

export type PrimitiveName =
  | "i8" | "i16" | "i32" | "i64" | "isize"
  | "u8" | "u16" | "u32" | "u64" | "usize"
  | "f32" | "f64"
  | "bool" | "char" | "string" | "void" | "null";

export const PRIMITIVE_NAMES: readonly PrimitiveName[] = [
  "i8", "i16", "i32", "i64", "isize",
  "u8", "u16", "u32", "u64", "usize",
  "f32", "f64",
  "bool", "char", "string", "void", "null",
];

export function isPrimitiveName(name: string): name is PrimitiveName {
  return (PRIMITIVE_NAMES as readonly string[]).includes(name);
}

/** Names of stdlib core traits used for compiler-driven dispatch. */
export const CORE_TRAITS = {
  Display:    "Display",
  Error:      "Error",
  Equals:     "Equals",
  Comparable: "Comparable",
  Add:        "Add",
  Sub:        "Sub",
  Mul:        "Mul",
  Div:        "Div",
  Rem:        "Rem",
  Hash:       "Hash",
  Clone:      "Clone",
  Step:       "Step",
  Into:       "Into",
  Iterator:   "Iterator",
  Iterable:   "Iterable",
  Contains:   "Contains",
  Index:      "Index",
  IndexSet:   "IndexSet",
} as const;

/** Names of stdlib core structs the compiler refers to by symbol. */
export const CORE_STRUCTS = {
  Range:          "Range",
  ArrayIterator:  "ArrayIterator",
  Done:           "Done",
  Yielded:        "Yielded",
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

export interface EnumType {
  readonly kind: "Enum";
  readonly symbol: Symbol;
  /** Backing integer type. Set in `declareEnum` from `EnumDecl.repr` (default
   *  `i32`). Read by the lowerer / bytecode emit / C-emit so variant literals
   *  flow as the right primitive width. */
  readonly repr: PrimitiveName;
  /** Resolved variant indices keyed by variant name. Computed in
   *  `declareEnum` from explicit `= N` annotations + auto-increment, and
   *  bounds-checked against `repr`. */
  readonly indices: ReadonlyMap<string, bigint>;
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
  /** When true, mutation through values of this type is rejected at
   *  typecheck (`arr[i] = v`, `arr.push(v)` etc.). `T[] <: const T[]`
   *  by subtyping, never the reverse. Module-level `K :: [...]` array
   *  literals get inferred as `const T[]` ; locals stay mutable for
   *  ascending compat. */
  readonly immutable: boolean;
}

/** Tuple type — heterogeneous fixed-arity sequence (≥ 2 elements). Lowered
 *  to an anonymous struct with synthetic fields `_0`, `_1`, ... */
export interface TupleType {
  readonly kind: "Tuple";
  readonly elements: readonly Type[];
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

// ---------------------------------------------------------------- interning
//
// Composite Type constructors below funnel through a global cache so two
// structurally-equal types share one JS reference (`Type` hash-consing).
// Side-benefits :
//   - `equalsType(a, b)` short-circuits on `a === b` for interned types.
//   - Maps keyed by Type / Type[] become O(1) via reference identity
//     (used by `specialize.ts`'s `implMethodEntries` post-Phase-B).
//
// Each interned Type carries a monotone `internId: number` (via WeakMap)
// so composite keys can be built from arg ids — avoids re-walking the
// tree at every lookup site.
//
// Convention : every Type production in the typecheck / lower phases
// should go through `mkStruct` / `mkArray` / etc. Direct object literals
// (`{ kind: "Struct", ... }`) bypass the cache and break reference
// equality. The migration is staged — `src/typecheck/types.ts` itself
// is fully interned ; hot consumers (`passes/call.ts`, `passes/expr.ts`,
// `specialize.ts`) flip to constructors as they're touched.

const internIds = new WeakMap<object, number>();
let nextInternId = 0;

/** Lazily assign a monotone id to `t`. Idempotent — once a Type is
 *  cached, its id never changes. Anchored on the JS reference, so
 *  un-interned types still get an id, but they won't share it with their
 *  structural siblings. */
export function internId(t: Type): number {
  let id = internIds.get(t);
  if (id === undefined) { id = nextInternId++; internIds.set(t, id); }
  return id;
}

/** Structurally-stable key for use as a Map key (or argsKey component).
 *  Two `equalsType`-equal types always produce the same key, regardless
 *  of whether they were interned. Distinct from `displayType` :
 *  user-facing rendering can be rewritten without breaking lookups, and
 *  the symbol id (not the name) anchors struct / enum / typeParam
 *  identity so name collisions in different modules are safely
 *  distinguished. */
export function canonicalKey(t: Type): string {
  switch (t.kind) {
    case "Primitive":  return `p${t.name}`;
    case "Struct":     return `s${t.symbol.id}<${t.args.map(canonicalKey).join(",")}>`;
    case "Trait":      return `t${t.symbol.id}<${t.args.map(canonicalKey).join(",")}>`;
    case "Array":      return `a${t.immutable ? "c" : "m"}(${canonicalKey(t.element)})`;
    case "Tuple":      return `T<${t.elements.map(canonicalKey).join(",")}>`;
    case "Fn":         return `F<${t.params.map(canonicalKey).join(",")}>>${canonicalKey(t.returnType)}`;
    case "Union":      return `U<${t.variants.map(canonicalKey).join(",")}>`;
    case "TypeParam":  return `P${t.symbol.id}`;
    case "Enum":       return `e${t.symbol.id}`;
    case "TypeMeta":   return "M";
    case "Self":       return "S";
    case "Unresolved": return "?";
    case "Never":      return "!";
    case "FreeInt":    return "FI";
    case "FreeFloat":  return "FF";
  }
}

/** Compose an arg-list canonical key — used as the inner key in
 *  `specialize.ts:implMethodEntries` etc. */
export function canonicalArgsKey(args: readonly Type[]): string {
  if (args.length === 0) return "";
  return args.map(canonicalKey).join(",");
}

const primitive = (name: PrimitiveName): PrimitiveType => {
  const t: PrimitiveType = { kind: "Primitive", name };
  internId(t);
  return t;
};

const structCache = new Map<string, StructType>();
const traitCache  = new Map<string, TraitType>();
const arrayCache  = new Map<number, ArrayType>();
const tupleCache  = new Map<string, TupleType>();
const fnCache     = new Map<string, FnType>();
const unionCache  = new Map<string, UnionType>();
const typeParamCache = new Map<number, TypeParamType>();
const enumCache   = new Map<number, EnumType>();

/** Hash-cons a Struct type. Args must themselves be interned (or
 *  singletons from `TY`) so their `internId`s are stable. */
export function mkStruct(symbol: Symbol, args: readonly Type[]): StructType {
  const key = `${symbol.id}:${args.map(internId).join(",")}`;
  const cached = structCache.get(key);
  if (cached !== undefined) return cached;
  const t: StructType = { kind: "Struct", symbol, args };
  structCache.set(key, t);
  internId(t);
  return t;
}

export function mkTrait(symbol: Symbol, args: readonly Type[]): TraitType {
  const key = `${symbol.id}:${args.map(internId).join(",")}`;
  const cached = traitCache.get(key);
  if (cached !== undefined) return cached;
  const t: TraitType = { kind: "Trait", symbol, args };
  traitCache.set(key, t);
  internId(t);
  return t;
}

/** Intern an Array type. Default `immutable = false` — only pass `true`
 *  for the `const T[]` parse path and the module-level array-literal
 *  promotion in `checkProgram`. */
export function mkArray(element: Type, immutable: boolean = false): ArrayType {
  // Pack (elementId, immutable) into one int so the Map stays
  // number-keyed — string keys allocate per lookup.
  const key = (internId(element) << 1) | (immutable ? 1 : 0);
  const cached = arrayCache.get(key);
  if (cached !== undefined) return cached;
  const t: ArrayType = { kind: "Array", element, immutable };
  arrayCache.set(key, t);
  internId(t);
  return t;
}

export function mkTuple(elements: readonly Type[]): TupleType {
  const key = elements.map(internId).join(",");
  const cached = tupleCache.get(key);
  if (cached !== undefined) return cached;
  const t: TupleType = { kind: "Tuple", elements };
  tupleCache.set(key, t);
  internId(t);
  return t;
}

export function mkFn(params: readonly Type[], returnType: Type): FnType {
  const key = `${params.map(internId).join(",")}>${internId(returnType)}`;
  const cached = fnCache.get(key);
  if (cached !== undefined) return cached;
  const t: FnType = { kind: "Fn", params, returnType };
  fnCache.set(key, t);
  internId(t);
  return t;
}

/** Hash-cons a Union from already-canonicalised variants. Callers that
 *  need flattening + dedup go through `unionOf` (which calls this). */
export function mkUnion(variants: readonly Type[]): UnionType {
  const key = variants.map(internId).join(",");
  const cached = unionCache.get(key);
  if (cached !== undefined) return cached;
  const t: UnionType = { kind: "Union", variants };
  unionCache.set(key, t);
  internId(t);
  return t;
}

export function mkTypeParam(symbol: Symbol): TypeParamType {
  const cached = typeParamCache.get(symbol.id);
  if (cached !== undefined) return cached;
  const t: TypeParamType = { kind: "TypeParam", symbol };
  typeParamCache.set(symbol.id, t);
  internId(t);
  return t;
}

export function mkEnum(symbol: Symbol, repr: PrimitiveName, indices: ReadonlyMap<string, bigint>): EnumType {
  // Enum identity is by symbol — `repr`/`indices` are properties of the
  // decl, not part of the cache key. Re-declaring an enum is a resolver
  // error elsewhere, so a single cache entry per symbol is safe.
  const cached = enumCache.get(symbol.id);
  if (cached !== undefined) return cached;
  const t: EnumType = { kind: "Enum", symbol, repr, indices };
  enumCache.set(symbol.id, t);
  internId(t);
  return t;
}

// ---------------------------------------------------------------- constants


export const TY = {
  i8:     primitive("i8"),
  i16:    primitive("i16"),
  i32:    primitive("i32"),
  i64:    primitive("i64"),
  isize:  primitive("isize"),
  u8:     primitive("u8"),
  u16:    primitive("u16"),
  u32:    primitive("u32"),
  u64:    primitive("u64"),
  usize:  primitive("usize"),
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

export const SIGNED_INTS: readonly PrimitiveName[]   = ["i8", "i16", "i32", "i64", "isize"];
export const UNSIGNED_INTS: readonly PrimitiveName[] = ["u8", "u16", "u32", "u64", "usize"];
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

// ----------------------------------------------------------------- layout

/** Byte size of `t` as a runtime value. Used by `@size_of(T)` (Layer 6
 *  reflection intrinsic). For primitives the size is fixed by Vader's ABI ;
 *  for aggregates and reference types it is the size of the heap pointer
 *  (`vader_box_t`, currently 16 bytes — tag + payload). Returns 0 for
 *  comptime-only types or anything we cannot lay out at compile time
 *  (TypeParam, Unresolved, Free*) — the typechecker emits a diagnostic at
 *  the call site if the result is meaningless. */
export function sizeOfType(t: Type): number {
  switch (t.kind) {
    case "Primitive":
      switch (t.name) {
        case "i8": case "u8": case "bool":      return 1;
        case "i16": case "u16":                 return 2;
        case "i32": case "u32": case "f32":
        case "char":                            return 4;     // char is u32 in Vader
        case "i64": case "isize":
        case "u64": case "usize":
        case "f64":                             return 8;
        case "string":                          return 16;    // vader_string_t {data, len}
        case "null":                            return 16;    // tagged box
        case "void":                            return 0;
      }
      return 0;
    case "Struct":
    case "Enum":
    case "Array":
    case "Tuple":
    case "Union":
    case "Trait":
    case "Fn":
      return 16;     // vader_box_t (tag + payload)
    case "TypeMeta":
    case "TypeParam":
    case "Self":
    case "Unresolved":
    case "FreeInt":
    case "FreeFloat":
    case "Never":
      return 0;
  }
}

/** Number of *fields* on a Struct or *elements* on a Tuple ; 0 for any other
 *  type. Backs `@field_count(T)`. The compiler resolves the underlying decl
 *  to read the count — it does not materialise the field list, which is
 *  cheaper and avoids alignment / layout concerns. */
export function fieldCountOfType(t: Type): number {
  switch (t.kind) {
    case "Struct":
      return t.symbol.source.kind === "struct"
        ? t.symbol.source.decl.fields.length
        : 0;
    case "Tuple":
      return t.elements.length;
    default:
      return 0;
  }
}

/** Number of *variants* on a Union (set-theoretic OR) or an Enum (named
 *  variants). 0 for anything else. Backs `@variant_count(T)`. Notably, a
 *  union of unions is already flattened by `unionOf` so the count reflects
 *  the canonicalised shape. */
export function variantCountOfType(t: Type): number {
  switch (t.kind) {
    case "Union":
      return t.variants.length;
    case "Enum": {
      const decl = t.symbol.source.kind === "enum" ? t.symbol.source.decl : null;
      return decl !== null ? decl.variants.length : 0;
    }
    default:
      return 0;
  }
}

/** Discriminator string for `@type_kind(T)` (Layer 6 reflection intrinsic).
 *  Returns one of `"primitive"`, `"struct"`, `"enum"`, `"union"`, `"array"`,
 *  `"tuple"`, `"fn"`, `"trait"`, `"type"` (metatype), or `"unknown"` for
 *  shapes a user shouldn't encounter (TypeParam, Self, Unresolved, Free*).
 *  Strings are stable identifiers — user code is expected to compare on
 *  exact match (`if @type_kind(T) == "struct"`). */
export function kindStringOfType(t: Type): string {
  switch (t.kind) {
    case "Primitive": return "primitive";
    case "Struct":    return "struct";
    case "Enum":      return "enum";
    case "Union":     return "union";
    case "Array":     return "array";
    case "Tuple":     return "tuple";
    case "Fn":        return "fn";
    case "Trait":     return "trait";
    case "TypeMeta":  return "type";
    case "TypeParam":
    case "Self":
    case "Unresolved":
    case "FreeInt":
    case "FreeFloat":
    case "Never":
      return "unknown";
  }
}

/** Alignment in bytes for `t`. Mirrors `sizeOfType` for primitives ; aggregate
 *  and reference types align to pointer boundary (8 bytes). */
export function alignOfType(t: Type): number {
  switch (t.kind) {
    case "Primitive":
      switch (t.name) {
        case "i8": case "u8": case "bool":      return 1;
        case "i16": case "u16":                 return 2;
        case "i32": case "u32": case "f32":
        case "char":                            return 4;
        case "i64": case "isize":
        case "u64": case "usize":
        case "f64":                             return 8;
        case "string": case "null":             return 8;
        case "void":                            return 1;
      }
      return 1;
    case "Struct":
    case "Enum":
    case "Array":
    case "Tuple":
    case "Union":
    case "Trait":
    case "Fn":
      return 8;
    case "TypeMeta":
    case "TypeParam":
    case "Self":
    case "Unresolved":
    case "FreeInt":
    case "FreeFloat":
    case "Never":
      return 1;
  }
}

// ----------------------------------------------------------------- display

export function displayType(t: Type): string {
  switch (t.kind) {
    case "Primitive":  return t.name;
    case "Struct":     return formatNamed(t.symbol.name, t.args);
    case "Enum":       return t.symbol.name;
    case "Trait":      return formatNamed(t.symbol.name, t.args);
    case "TypeParam":  return `$${t.symbol.name}`;
    case "TypeMeta":   return "type";
    case "Self":       return "Self";
    case "Unresolved": return "?";
    case "Never":      return "never";
    case "FreeInt":    return "{integer}";
    case "FreeFloat":  return "{float}";
    case "Array":      return t.immutable ? `const ${displayType(t.element)}[]` : `${displayType(t.element)}[]`;
    case "Tuple":      return `[${t.elements.map(displayType).join(", ")}]`;
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

/** Two declaration symbols denote the same source declaration. Used to
 *  fall back from `id` equality when a single source file gets loaded
 *  twice (e.g. once as a standalone file module and once as part of a
 *  folder module that aggregates the same file). Compares by source
 *  position rather than `Symbol.id`. */
function sameSourceDecl(a: Symbol, b: Symbol): boolean {
  const sa = a.definedAt, sb = b.definedAt;
  if (sa === null || sb === null) return false;
  return sa.start.file === sb.start.file && sa.start.offset === sb.start.offset;
}

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
    case "Enum": {
      const o = b as EnumType;
      return a.symbol.id === o.symbol.id || sameSourceDecl(a.symbol, o.symbol);
    }
    case "Struct":
    case "Trait": {
      const o = b as StructType | TraitType;
      const idsMatch = a.symbol.id === o.symbol.id || sameSourceDecl(a.symbol, o.symbol);
      return idsMatch && argListEquals(a.args, o.args);
    }
    case "Array": {
      const o = b as ArrayType;
      return a.immutable === o.immutable && equalsType(a.element, o.element);
    }
    case "Tuple": {
      const o = b as TupleType;
      return argListEquals(a.elements, o.elements);
    }
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

/** Minimal duck-typed view of `ImplRegistry` consumed by `isAssignable`'s
 *  trait-widening branch. The full registry lives in `./impls.ts`; redeclaring
 *  the surface here avoids a circular import. */
export interface TraitOracle {
  hasUser(forSymbol: Symbol, trait: Symbol): boolean;
  forPrimitive(name: string, trait: Symbol): unknown | null;
  /** Resolves a core trait by its canonical name. Returns null when the
   *  caller couldn't locate std/core (e.g. dump-only pipelines). */
  coreTrait(name: string): Symbol | null;
}

/**
 * Whether `from` can flow into a slot expecting `to` without an explicit cast.
 *
 * - Identity: T → T
 * - Never: never → T (always)
 * - Unresolved: error already reported, treat as compatible to suppress cascading errors
 * - Free numeric literals: FreeInt → any integer type; FreeFloat → any float type
 * - Union widening: T → A|B|C if T is one of {A, B, C}
 * - Union → Union: every variant of `from` must be assignable to `to`
 * - Trait widening (only when `impls` is supplied): struct/primitive → Trait
 *   when the source implements the trait.
 *
 * No implicit numeric widening (i32 → i64): explicit cast required (per SPEC §4).
 */
export function isAssignable(from: Type, to: Type, impls?: TraitOracle): boolean {
  if (from.kind === "Unresolved" || to.kind === "Unresolved") return true;
  if (from.kind === "Never") return true;
  if (equalsType(from, to)) return true;

  if (from.kind === "FreeInt" && to.kind === "Primitive") return (NUMERICS as readonly string[]).includes(to.name);
  if (from.kind === "FreeFloat" && to.kind === "Primitive") return (FLOATS as readonly string[]).includes(to.name);

  if (impls !== undefined && to.kind === "Trait") {
    if (from.kind === "Struct") return impls.hasUser(from.symbol, to.symbol);
    if (from.kind === "Primitive") return impls.forPrimitive(from.name, to.symbol) !== null;
    // Free numeric literals: default to canonical (i32 / f64) and re-check.
    // Lets `7` flow into `Doubler($T)` via `i32 implements Doubler(i32)`.
    if (from.kind === "FreeInt") return isAssignable(TY.i32, to, impls);
    if (from.kind === "FreeFloat") return isAssignable(TY.f64, to, impls);
    if (from.kind === "Union") return from.variants.every((v) => isAssignable(v, to, impls));
  }

  // Tuple → Tuple : element-wise structural assignability with matching arity.
  // No assignability between Tuple and Array even when elements coincide —
  // the contextual disambiguation in `inferSeqLit` relies on the distinction.
  if (from.kind === "Tuple" && to.kind === "Tuple") {
    if (from.elements.length !== to.elements.length) return false;
    for (let i = 0; i < from.elements.length; i++) {
      if (!isAssignable(from.elements[i]!, to.elements[i]!, impls)) return false;
    }
    return true;
  }

  // Array → Array : `T[] <: const T[]` (mutable usable wherever const is
  // expected ; reverse forbidden — a const array can't be passed to a
  // slot that may mutate it). Elements stay invariant for simplicity.
  if (from.kind === "Array" && to.kind === "Array") {
    if (from.immutable && !to.immutable) return false;
    return equalsType(from.element, to.element);
  }

  if (to.kind === "Union") {
    if (from.kind === "Union") return from.variants.every((v) => isAssignable(v, to, impls));
    return to.variants.some((v) => isAssignable(from, v, impls));
  }
  return false;
}

/** True iff some value can be of both type `a` and type `b` at runtime.
 *  Used by `is`-pattern checks (match arm + `expr is T` binary) to flag
 *  arms that are statically unreachable — e.g. `match p: Pet { is Bird }`
 *  when `Bird` is not part of `Pet`'s union.
 *
 *  Conservative on unknowns : `Unresolved` and unresolved `TypeParam`
 *  intersect anything (we already errored elsewhere ; cascading is noise).
 *  For traits, "intersects" means the other side implements the trait —
 *  same direction as `isAssignable`'s trait-widening rule. The two
 *  trait branches below are *commutative in result* (a Struct intersects
 *  a Trait iff it implements it, regardless of argument order) even
 *  though the impl lookup is directional.
 */
export function intersects(a: Type, b: Type, impls?: TraitOracle): boolean {
  if (a.kind === "Unresolved" || b.kind === "Unresolved") return true;
  if (a.kind === "Never" || b.kind === "Never") return false;
  if (a.kind === "TypeParam" || b.kind === "TypeParam") return true;
  // Free numeric literals intersect any numeric type, and intersect
  // another free literal of the same kind (FreeInt ∩ FreeInt, etc.).
  // Order-sensitive : the `b.kind === a.kind` test on line 1 catches
  // the equal-kind case before TS narrows `a` away on line 2.
  if (a.kind === "FreeInt" || a.kind === "FreeFloat") return isNumeric(b) || b.kind === a.kind;
  if (b.kind === "FreeInt" || b.kind === "FreeFloat") return isNumeric(a);
  if (equalsType(a, b)) return true;
  // Union ∩ anything : some variant of the union must intersect.
  if (a.kind === "Union") return a.variants.some((v) => intersects(v, b, impls));
  if (b.kind === "Union") return b.variants.some((v) => intersects(a, v, impls));
  // Trait : the non-trait side must implement the trait, mirroring the
  // assignability rule. Two distinct traits without a shared
  // implementor are deemed non-intersecting — coherent with the rest of
  // the trait-typed checking surface.
  if (a.kind === "Trait" && impls !== undefined) {
    if (b.kind === "Struct")    return impls.hasUser(b.symbol, a.symbol);
    if (b.kind === "Primitive") return impls.forPrimitive(b.name, a.symbol) !== null;
    if (b.kind === "Trait")     return false;
    return false;
  }
  if (b.kind === "Trait" && impls !== undefined) {
    if (a.kind === "Struct")    return impls.hasUser(a.symbol, b.symbol);
    if (a.kind === "Primitive") return impls.forPrimitive(a.name, b.symbol) !== null;
    return false;
  }
  // Distinct concrete shapes never intersect : a value is exactly one
  // kind at runtime.
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
    case "Tuple":
      for (const e of t.elements) forEachType(e, visit);
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
      return mkArray(substitute(t.element, subst), t.immutable);
    case "Tuple":
      return { kind: "Tuple", elements: t.elements.map((e) => substitute(e, subst)) };
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
