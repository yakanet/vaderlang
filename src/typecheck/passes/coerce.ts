// User-defined `Into(Target)` coercion lookup.
//
// When a value of type `S` reaches a slot expecting `T` and `S != T` :
//   1. If `isAssignable(S, T)` already accepts the flow (subtype / trait
//      widening / numeric defaulting), nothing happens — `S` flows in
//      directly.
//   2. Otherwise the caller invokes `tryInto(S, T, expr, …)`. If an impl
//      `S implements Into(T)` is registered, the site is recorded into
//      `t.intoCoercions` ; the lowerer rewrites the lowered expression
//      into `value.into()` before the consumer sees it.
//
// Rules (mirrors SPEC §11 *Type coercion*) :
//   - **Concrete target only.** `T` must be a Struct, Enum, or Primitive
//     (`Trait`-typed slots use virtual dispatch ; `TypeParam` slots wait
//     for monomorphisation ; `Union` slots are too ambiguous to safely
//     coerce into).
//   - **No identity.** Impls of the form `T implements Into(T)` are
//     rejected at resolve time ; this lookup also skips them.
//   - **No chains.** Lookup is a single registry probe — `S → U → T`
//     never auto-composes (Rust-style strictness).
//
// The companion `LoweredInto` node + lowerer insertion live in
// `src/lower/passes/coerce.ts`.
import type * as A from "../../parser/ast.ts";
import type { ImplEntry, ImplRegistry } from "../impls.ts";
import { CORE_TRAITS, equalsType, type Type } from "../types.ts";
import type { MutableTyped } from "../ctx.ts";

/** True iff `target` is the kind of type we'll attempt an `Into` lookup
 *  against. Union / TypeParam / Trait / Unresolved are excluded — see the
 *  rules at the top of this file. */
function isCoercionTarget(target: Type): boolean {
  switch (target.kind) {
    case "Struct":
    case "Enum":
    case "Primitive":
      return true;
    default:
      return false;
  }
}

/** True iff this impl's for-type matches `source` structurally. Mirrors
 *  the receiver check in `findImplMethod` but specialised for the three
 *  shapes we accept as coercion sources today. */
function implMatchesSource(entry: ImplEntry, source: Type): boolean {
  if (source.kind === "Struct" || source.kind === "Enum") {
    return entry.forSymbol !== null && entry.forSymbol.id === source.symbol.id;
  }
  if (source.kind === "Primitive") {
    return entry.forSymbol === null
      && entry.decl.forType.kind === "IdentExpr"
      && entry.decl.forType.name === source.name;
  }
  return false;
}

/** Probe the impl registry for `source implements Into(target)`. Returns
 *  the matching `ImplEntry` or null. Caller is responsible for excluding
 *  the trivial case where `source == target` (no coercion needed). */
export function findIntoImpl(
  source: Type, target: Type, t: MutableTyped, impls: ImplRegistry,
): ImplEntry | null {
  if (!isCoercionTarget(target)) return null;
  if (equalsType(source, target)) return null;
  const intoSym = impls.coreTrait(CORE_TRAITS.Into);
  if (intoSym === null) return null;
  const candidates = impls.forTrait(intoSym);
  for (const entry of candidates) {
    if (!implMatchesSource(entry, source)) continue;
    if (entry.decl.traitArgs.length !== 1) continue;
    const implTarget = t.globals.typeExprTypes.get(entry.decl.traitArgs[0]!);
    if (implTarget === undefined) continue;
    if (equalsType(implTarget, target)) return entry;
  }
  return null;
}

/** Try to insert an `Into(target)` coercion at `expr`. Returns `true` on
 *  success (and records the site into `t.intoCoercions`), `false`
 *  otherwise — the caller can then surface its own mismatch diagnostic. */
export function tryInto(
  source: Type, target: Type, expr: A.Expr,
  t: MutableTyped, impls: ImplRegistry,
): boolean {
  const entry = findIntoImpl(source, target, t, impls);
  if (entry === null) return false;
  t.intoCoercions.set(expr, { entry, sourceType: source });
  return true;
}
