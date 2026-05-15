// TypeParam unification — extract `($T → concreteType)` bindings by walking
// the structural shape of a parameter type against an argument type. Used
// by generic fn dispatch (`inferGenericFnCall`, `inferGenericUfcsCall`) and
// by the impl-method resolver to bind trait args at call sites.

import type { ImplRegistry } from "../impls.ts";
import type { MutableTyped } from "../ctx.ts";
import type { Substitution, Type } from "../types.ts";
import { CORE_TRAITS, TY, equalsType, substitute } from "../types.ts";

/** Merge two substitutions ; right wins on `self` if both supply one. */
export function mergeSubst(a: Substitution | null, b: Substitution | null): Substitution | null {
  if (a === null) return b;
  if (b === null) return a;
  const map = new Map<number, Type>();
  if (a.typeParams !== undefined) for (const [k, v] of a.typeParams) map.set(k, v);
  if (b.typeParams !== undefined) for (const [k, v] of b.typeParams) map.set(k, v);
  return { typeParams: map, self: a.self ?? b.self };
}

/** True if `t` contains at least one `TypeParam` node. */
export function typeContainsTypeParam(t: Type): boolean {
  switch (t.kind) {
    case "TypeParam": return true;
    case "Array":     return typeContainsTypeParam(t.element);
    case "Tuple":     return t.elements.some(typeContainsTypeParam);
    case "Struct":
    case "Trait":     return t.args.some(typeContainsTypeParam);
    case "Fn":        return t.params.some(typeContainsTypeParam) || typeContainsTypeParam(t.returnType);
    case "Union":     return t.variants.some(typeContainsTypeParam);
    default:          return false;
  }
}

/** Structural unification: extract TypeParam-symbol-id → concrete-type bindings
 *  by matching the shape of `paramType` against `argType`. Does not overwrite
 *  an already-bound symbol (first binding wins).
 *
 *  When `impls` and `t` are supplied, also unifies a trait param against a
 *  concrete arg by walking the impl's declared trait args : e.g. paramType =
 *  `Iterator($T)`, argType = `Range`, and `Range implements Iterator(i32)` →
 *  bind `T → i32`. This mirrors the trait-widening branch of `isAssignable`. */
export function unifyTypeParam(
  paramType: Type, argType: Type, out: Map<number, Type>,
  impls?: ImplRegistry, t?: MutableTyped,
): void {
  if (paramType.kind === "TypeParam") {
    if (!out.has(paramType.symbol.id)) out.set(paramType.symbol.id, argType);
    return;
  }
  if (paramType.kind === "Array" && argType.kind === "Array") {
    unifyTypeParam(paramType.element, argType.element, out, impls, t);
    return;
  }
  if (paramType.kind === "Tuple" && argType.kind === "Tuple"
      && paramType.elements.length === argType.elements.length) {
    for (let i = 0; i < paramType.elements.length; i++) {
      unifyTypeParam(paramType.elements[i]!, argType.elements[i]!, out, impls, t);
    }
    return;
  }
  if ((paramType.kind === "Struct" || paramType.kind === "Trait")
      && argType.kind === paramType.kind
      && paramType.symbol.id === argType.symbol.id) {
    for (let i = 0; i < paramType.args.length && i < argType.args.length; i++) {
      unifyTypeParam(paramType.args[i]!, argType.args[i]!, out, impls, t);
    }
    return;
  }
  if (paramType.kind === "Fn" && argType.kind === "Fn") {
    for (let i = 0; i < paramType.params.length && i < argType.params.length; i++) {
      unifyTypeParam(paramType.params[i]!, argType.params[i]!, out, impls, t);
    }
    unifyTypeParam(paramType.returnType, argType.returnType, out, impls, t);
    return;
  }
  // Union vs Union : pair off concrete variants first (e.g. `null`), then
  // unify the leftovers position-by-position. Handles the common
  // `T | null` ↔ `concrete | null` shape : `null` pairs off, `T` binds to
  // `concrete`. The "concrete first" pass matters — without it `T | null`
  // could spuriously bind `T = null` when `null` is itself a variant.
  if (paramType.kind === "Union" && argType.kind === "Union") {
    const remainingArg: Type[] = [...argType.variants];
    const remainingParam: Type[] = [];
    for (const pv of paramType.variants) {
      const idx = remainingArg.findIndex((av) => equalsType(av, pv));
      if (idx >= 0) remainingArg.splice(idx, 1);
      else remainingParam.push(pv);
    }
    for (let i = 0; i < remainingParam.length && i < remainingArg.length; i++) {
      unifyTypeParam(remainingParam[i]!, remainingArg[i]!, out, impls, t);
    }
    return;
  }
  // Trait param vs concrete arg : look up the impl to extract the trait's
  // generic args. Mirrors the trait-widening path of `isAssignable`.
  if (paramType.kind === "Trait" && impls !== undefined && t !== undefined) {
    unifyTraitParamWithConcrete(paramType, argType, out, impls, t);
  }
}

function unifyTraitParamWithConcrete(
  paramType: Extract<Type, { kind: "Trait" }>, argType: Type,
  out: Map<number, Type>, impls: ImplRegistry, t: MutableTyped,
): void {
  // Struct / primitive source : direct impl lookup.
  if (argType.kind === "Struct" || argType.kind === "Primitive") {
    const entry = impls.findFor(argType, paramType.symbol);
    if (entry === null) return;
    const implTraitArgs: Type[] = entry.decl.traitArgs.map(
      (ta) => t.globals.typeExprTypes.get(ta) ?? TY.unresolved,
    );
    // Resolve the impl's own typeParams (e.g. `Range[T] implements Iterator(T)`
    // — the `T` in `Iterator(T)` references the impl block's typeParam, NOT
    // the struct's). Match the impl's `forType` against the concrete argType
    // to bind each impl typeParam, then substitute the trait args before
    // unifying with the caller's param.
    const implTypeParams = new Map<number, Type>();
    const implForType = t.globals.typeExprTypes.get(entry.decl.forType);
    if (implForType !== undefined) {
      unifyTypeParam(implForType, argType, implTypeParams, impls, t);
    }
    const implSubst: Substitution = { typeParams: implTypeParams };
    for (let i = 0; i < paramType.args.length && i < implTraitArgs.length; i++) {
      unifyTypeParam(paramType.args[i]!, substitute(implTraitArgs[i]!, implSubst), out, impls, t);
    }
    return;
  }
  // Array source : `T[]` → `Iterator(T)` is a built-in coercion (no impl decl).
  // Bind paramType.args[0] = element when the trait is the canonical Iterator.
  if (argType.kind === "Array" && paramType.args.length === 1) {
    const iter = impls.coreTrait(CORE_TRAITS.Iterator);
    if (iter !== null && iter.id === paramType.symbol.id) {
      unifyTypeParam(paramType.args[0]!, argType.element, out, impls, t);
    }
    return;
  }
  // Union source : isAssignable requires every variant to satisfy the trait,
  // so unify against each variant ; first binding per typeParam wins.
  if (argType.kind === "Union") {
    for (const v of argType.variants) {
      unifyTraitParamWithConcrete(paramType, v, out, impls, t);
    }
  }
}
