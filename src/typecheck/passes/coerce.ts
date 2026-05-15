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
// Two kinds of impls are recognised today :
//   - **Concrete-source impls** : `UserId implements Into(i32)` — forType
//     is a Struct/Enum/Primitive, no impl-level typeParams. Substitution
//     map is empty.
//   - **Blanket impls** : `T[] implements[T] Into(Iterator(T))` and
//     `T implements[T: Display] Into(string)` — forType references the
//     impl's own typeParams. The matcher unifies the source against the
//     forType, binding impl typeParams as it goes. The resulting
//     substitution is recorded so the lowerer can route to the right
//     monomorphised entry.
//
// Rules (mirrors SPEC §11 *Type coercion*) :
//   - **Concrete target only.** `T` must be a Struct, Enum, or Primitive
//     (`Trait`-typed slots use virtual dispatch ; `TypeParam` slots wait
//     for monomorphisation ; `Union` slots are too ambiguous to safely
//     coerce into).
//   - **No identity.** Impls of the form `T implements Into(T)` are
//     rejected at typecheck (T3039) ; this lookup also skips them.
//   - **No chains.** Lookup is a single registry probe — `S → U → T`
//     never auto-composes (Rust-style strictness).
//   - **Bound check for blanket impls.** When the matched impl typeParam
//     has bounds (`[T: Display]`), `source` must satisfy each bound trait
//     before the impl applies.
//
// The companion `LoweredInto` node + lowerer insertion live in
// `src/lower/passes/coerce.ts`.
import type * as A from "../../parser/ast.ts";
import type { ImplEntry, ImplRegistry } from "../impls.ts";
import type { Substitution } from "../types.ts";
import { CORE_TRAITS, TY, equalsType, isAssignable, mkTrait, substitute, type Type } from "../types.ts";
import type { MutableTyped } from "../ctx.ts";
import { unifyTypeParam } from "./unify.ts";

/** True iff `target` is the kind of type we'll attempt an `Into` lookup
 *  against. Union / TypeParam / Unresolved are excluded — see the rules
 *  at the top of this file. `Trait` is allowed so that blanket impls
 *  into core traits work (e.g. `T[] implements[T] Into(Iterator(T))`) ;
 *  the direct trait-widening path in `isAssignable` runs first, so a
 *  type that already implements the trait flows through without ever
 *  reaching `tryInto`. */
function isCoercionTarget(target: Type): boolean {
  switch (target.kind) {
    case "Struct":
    case "Enum":
    case "Primitive":
    case "Trait":
      return true;
    default:
      return false;
  }
}

/** Concrete-source match : the impl has no typeParams of its own and its
 *  forType points at `source`'s defining symbol (struct/enum) or primitive
 *  name. Returns an empty substitution on success ; the lowerer feeds
 *  `source.args` for generic-struct sources separately. */
function implMatchesConcreteSource(entry: ImplEntry, source: Type): boolean {
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

/** Verify every impl typeParam binding satisfies its declared bounds. For
 *  `T implements[T: Display] Into(string)` and source `i32`, this checks
 *  `i32 implements Display`. Empty bounds always succeed. */
function checkImplTypeParamBounds(
  entry: ImplEntry, subst: Map<number, Type>,
  t: MutableTyped, impls: ImplRegistry,
): boolean {
  for (const tp of entry.decl.typeParams) {
    const tpSym = t.globals.typeParamSymbols.get(tp);
    if (tpSym === undefined) continue;
    const bound = subst.get(tpSym.id);
    if (bound === undefined) continue;
    const traitSyms = t.globals.typeParamBounds.get(tpSym.id) ?? [];
    for (const traitSym of traitSyms) {
      // Reuse `isAssignable(source, Trait, impls)` — same machinery used
      // for `fn[T: Trait]` bound enforcement at call sites.
      const traitType: Type = mkTrait(traitSym, []);
      if (!isAssignable(bound, traitType, impls)) return false;
    }
  }
  return true;
}

/** Single-step structural unification between the impl's forType and the
 *  call-site source. Returns the substitution (impl typeParam id →
 *  concrete type) on a match, or null when the shapes diverge. Blanket
 *  impls with zero typeParams short-circuit through `implMatchesConcrete
 *  Source`. */
function matchSourceAgainstImpl(
  entry: ImplEntry, source: Type, t: MutableTyped, impls: ImplRegistry,
): Substitution | null {
  if (entry.decl.typeParams.length === 0) {
    return implMatchesConcreteSource(entry, source)
      ? { typeParams: new Map() }
      : null;
  }
  const forType = t.globals.typeExprTypes.get(entry.decl.forType);
  if (forType === undefined || forType.kind === "Unresolved") return null;
  const out = new Map<number, Type>();
  unifyTypeParam(forType, source, out, impls, t);
  // Validation : every impl typeParam must have been bound by the
  // unification (otherwise the forType didn't actually consume `source`).
  for (const tp of entry.decl.typeParams) {
    const sym = t.globals.typeParamSymbols.get(tp);
    if (sym === undefined) return null;
    if (!out.has(sym.id)) return null;
  }
  if (!checkImplTypeParamBounds(entry, out, t, impls)) return null;
  return { typeParams: out };
}

/** Probe the impl registry for `source implements Into(target)`. Returns
 *  the matching `ImplEntry` + the substitution that maps the impl's own
 *  typeParams to concrete pieces of `source`. Caller is responsible for
 *  excluding the trivial case where `source == target` (no coercion
 *  needed). */
export function findIntoImpl(
  source: Type, target: Type, t: MutableTyped, impls: ImplRegistry,
): { entry: ImplEntry; implSubst: Substitution } | null {
  if (!isCoercionTarget(target)) return null;
  if (equalsType(source, target)) return null;
  const intoSym = impls.coreTrait(CORE_TRAITS.Into);
  if (intoSym === null) return null;
  const candidates = impls.forTrait(intoSym);
  for (const entry of candidates) {
    if (entry.decl.traitArgs.length !== 1) continue;
    const implSubst = matchSourceAgainstImpl(entry, source, t, impls);
    if (implSubst === null) continue;
    const implTargetRaw = t.globals.typeExprTypes.get(entry.decl.traitArgs[0]!);
    if (implTargetRaw === undefined) continue;
    const implTarget = substitute(implTargetRaw, implSubst);
    if (!equalsType(implTarget, target)) continue;
    return { entry, implSubst };
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
  const found = findIntoImpl(source, target, t, impls);
  if (found === null) return false;
  t.intoCoercions.set(expr, {
    entry: found.entry,
    sourceType: source,
    implSubst: found.implSubst,
  });
  return true;
}
