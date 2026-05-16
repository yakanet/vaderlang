// Compiler-built intrinsic functions invoked with the `@name(args)` syntax in
// expression position (Layer 6 of the type-first design — reflection scope,
// DESIGN_TYPE_FIRST.md §12). Distinct from decorators (`@derive`, `@partial`,
// `@assert`, …) and from comptime-host builtins (`@file`, `@env`).
//
// The parser uses this set to decide whether `@name(...)` is an
// IntrinsicCallExpr or an unknown decorator-in-expression-position (P1014).
// The typechecker, lower, and (eventually) comptime engine each have their
// own dispatch table keyed on the same names.

/** Intrinsic-call argument shape — drives parser dispatch and typechecker
 *  validation. `type` args are walked by `resolveType` ; `value` args by
 *  `resolveExpr`. */
export type IntrinsicArgKind = "type" | "value";

/** Result-type tag — the typechecker maps this to a concrete `Type`. Kept as
 *  a small enum so the registry stays the single source of truth for every
 *  intrinsic's signature ; downstream passes look it up rather than mirror
 *  a per-name switch. */
export type IntrinsicResultKind = "usize" | "string" | "bool" | "type";

export interface IntrinsicSpec {
  readonly name: string;
  readonly args: readonly IntrinsicArgKind[];
  readonly result: IntrinsicResultKind;
}

/** Full set of recognised intrinsics. New entries land here ; the typechecker
 *  and lower passes implement the per-name semantics. */
export const INTRINSICS: readonly IntrinsicSpec[] = [
  // `@size_of(t)` — arg is a `TypeMeta`-typed *value* (a bare type name
  // like `i32` is a `TypeMeta` value in value position, by Layer 4
  // design). The lowerer folds the static case to a literal and routes
  // the runtime case (e.g. `fn(t: type)` param) through the
  // `size_of.type` intrinsic.
  { name: "size_of",       args: ["value"],         result: "usize"  },
  { name: "align_of",      args: ["type"],          result: "usize"  },
  { name: "type_name",     args: ["type"],          result: "string" },
  { name: "type_kind",     args: ["type"],          result: "string" },
  { name: "field_count",   args: ["type"],          result: "usize"  },
  { name: "variant_count", args: ["type"],          result: "usize"  },
  { name: "field_index",   args: ["type", "value"], result: "usize"  },
  { name: "satisfies",     args: ["type", "type"],  result: "bool"   },
  // Reifies the static type of a value as a `type` runtime value. The
  // argument is NOT evaluated (Zig-style) — only its static type is
  // read. Layer 4 §1.19 B.2.
  { name: "type_of",       args: ["value"],         result: "type"   },
  // `@file("path")` reads the file at compile time and bakes its UTF-8
  // contents as a string literal. The sandbox confines the path to the
  // project root (same rule as the legacy `@file` decorator).
  { name: "file",          args: ["value"],         result: "string" },
];

const INTRINSIC_BY_NAME: ReadonlyMap<string, IntrinsicSpec> = new Map(
  INTRINSICS.map((spec) => [spec.name, spec]),
);

/** Returns the intrinsic spec for `name`, or `null` if `@name(...)` should be
 *  treated as a non-intrinsic at the parser level. */
export function intrinsicSpec(name: string): IntrinsicSpec | null {
  return INTRINSIC_BY_NAME.get(name) ?? null;
}

export function isIntrinsicName(name: string): boolean {
  return INTRINSIC_BY_NAME.has(name);
}
