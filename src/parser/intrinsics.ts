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
 *  `resolveExpr`. The intrinsic's return type is fixed per-name and decided
 *  by the typechecker. */
export type IntrinsicArgKind = "type" | "value";

export interface IntrinsicSpec {
  readonly name: string;
  readonly args: readonly IntrinsicArgKind[];
}

/** Full set of recognised intrinsics. New entries land here ; the typechecker
 *  and lower passes implement the per-name semantics. */
export const INTRINSICS: readonly IntrinsicSpec[] = [
  { name: "size_of",       args: ["type"] },
  { name: "align_of",      args: ["type"] },
  { name: "type_name",     args: ["type"] },
  { name: "type_kind",     args: ["type"] },
  { name: "field_count",   args: ["type"] },
  { name: "variant_count", args: ["type"] },
  { name: "field_index",   args: ["type", "value"] },
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
