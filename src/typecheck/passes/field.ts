// Field-access checking (`obj.field` / `obj.method`). The most complex of
// the call-shaped passes — six mutually-exclusive resolution kinds
// (collapsed into one `FieldResolution` Map, see `typed-ast.ts`) and the
// generic-UFCS code path. Lives outside `call.ts` because it's its own
// universe of helpers (impl-method lookup, trait-method on TypeParam
// receivers, union-common-field, struct/tuple/enum/array-method dispatch).
//
// Re-exports `inferGenericUfcsCall` + `recordGenericCallSite` because they
// belong logically with UFCS dispatch and unblock the cycle with `call.ts`.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type { Span } from "../../diagnostics/diagnostic.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf, sourceStructDecl, sourceTraitDecl } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplEntry, ImplRegistry } from "../impls.ts";
import type { MethodResolution, TraitMethodResolution } from "../typed-ast.ts";
import type { Substitution, Type } from "../types.ts";
import { CORE_TRAITS, TY, defaultIfFree, displayType, isAssignable, substitute, unionOf } from "../types.ts";

import { buildStructSubst, tryStructSubst } from "../ctx.ts";
import { findIntoImpl, tryInto } from "./coerce.ts";
import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkEnumVariant } from "./enum.ts";
import { checkExpr, typeOfSymbol } from "./expr.ts";
import { extractFieldPath, fieldNarrowKey } from "./narrow.ts";
import { mergeSubst, typeContainsTypeParam, unifyTypeParam } from "./unify.ts";

export function inferField(
  expr: A.FieldExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Module-namespace field: resolver already wired the export.
  const fieldRef = t.resolved.fieldRefs.get(expr);
  if (fieldRef?.kind === "namespace") return typeOfSymbol(fieldRef.symbol, t);

  const targetType = checkExpr(expr.target, null, t, impls, diags, fn);
  // Field-expr flow narrowing : when an enclosing `match foo.bar.baz { ... }`
  // has pushed a narrowing for this exact `(rootSym, path)` chain, return
  // the narrowed type. Gated on `narrowedFields.size` to keep the
  // alloc-free hot path (most field reads aren't inside a narrowed scope).
  if (t.narrowedFields.size !== 0) {
    const fp = extractFieldPath(expr, t);
    if (fp !== null) {
      const narrowed = t.narrowedFields.get(fieldNarrowKey(fp.symId, fp.path));
      if (narrowed !== undefined) return narrowed;
    }
  }
  if (targetType.kind === "Array") {
    if (expr.field === "len") {
      t.fieldResolutions.set(expr, { kind: "array-op", op: "len" });
      return { kind: "Fn", params: [], returnType: TY.usize };
    }
    if (expr.field === "push") {
      t.fieldResolutions.set(expr, { kind: "array-op", op: "push" });
      return { kind: "Fn", params: [targetType.element], returnType: TY.void };
    }
  }
  if (targetType.kind === "Tuple") {
    // Numeric tuple-element access `t.0`, `t.1`, ... The parser sets
    // `isNumeric = true` and stores the index as a decimal string in `field`.
    if (expr.isNumeric === true) {
      const idx = Number.parseInt(expr.field, 10);
      if (Number.isFinite(idx) && idx >= 0 && idx < targetType.elements.length) {
        return targetType.elements[idx]!;
      }
      err(diags, "T3001", expr.fieldSpan,
        `tuple ${displayType(targetType)} has no element at index ${idx}`);
      return TY.unresolved;
    }
    err(diags, "T3001", expr.fieldSpan,
      `tuple ${displayType(targetType)} has no field \`${expr.field}\` (use numeric access \`.0\`, \`.1\`, ...)`);
    return TY.unresolved;
  }
  if (targetType.kind === "Enum" && targetType.indices.has(expr.field)) {
    // `Enum.Variant` form: target is the enum *type*. For an enum *value*
    // (`e.method`), fall through to UFCS so a free fn whose first param is
    // the enum can be called via dot-notation.
    checkEnumVariant(targetType, expr.field, expr.fieldSpan, diags);
    return targetType;
  }
  if (targetType.kind === "Struct") {
    const decl = sourceStructDecl(targetType.symbol);
    if (decl !== null) {
      const field = decl.fields.find((f) => f.name === expr.field);
      if (field !== undefined) {
        const raw = t.globals.typeExprTypes.get(field.type) ?? TY.unresolved;
        const subst = tryStructSubst(decl, targetType.args, t.globals);
        return subst !== null ? substitute(raw, subst) : raw;
      }
    }
  }

  // Common-field access on discriminated unions (§1.18d) : `e.f` where
  // `e` is `A | B | C` succeeds when every variant carries a field
  // named `f`. The result type is the union of each variant's field
  // type (canonicalised by `unionOf` so identical types collapse).
  //
  // Three outcomes :
  //   - every variant has the field           → record `union-field`, return the union of field types.
  //   - some variants have it, others don't   → emit T3009 (likely a typo, list the offenders).
  //   - no variant has it                     → fall through (a free fn with this union as first
  //                                              param can pick it up via UFCS below).
  if (targetType.kind === "Union") {
    const fieldTypes: Type[] = [];
    const missing: string[] = [];
    for (const variant of targetType.variants) {
      const ft = fieldTypeOnType(variant, expr.field, t);
      if (ft === null) {
        missing.push(displayType(variant));
      } else {
        fieldTypes.push(ft);
      }
    }
    if (missing.length === 0 && fieldTypes.length > 0) {
      // The lowerer reads this resolution from `unionFieldResolutions` to
      // synthesise the variant-dispatch cascade ; record per-variant
      // types so the cast in each arm has the right narrowing.
      t.fieldResolutions.set(expr, {
        kind: "union-field",
        resolution: {
          variants: targetType.variants.map((v, i) => ({ type: v, fieldType: fieldTypes[i]! })),
        },
      });
      return unionOf(fieldTypes);
    }
    if (fieldTypes.length > 0) {
      err(diags, "T3009", expr.fieldSpan,
        `\`${expr.field}\` not on every variant of ${displayType(targetType)}: missing on ${missing.join(", ")}`);
      return TY.unresolved;
    }
    // No variant has the field — fall through to UFCS/impl-method lookup
    // so a free fn `name(v: ThisUnion, ...)` can match via dot-notation.
  }

  // No struct field — try impl-method lookup. Records into `methodResolutions`
  // so the lowerer can rewrite `obj.method(args)` into a direct call of the
  // specialised impl fn with `obj` as the first arg. Emits T3032 when two
  // distinct traits' impls each provide the requested method on this type.
  const method = findImplMethod(impls, targetType, expr.field, t, expr.fieldSpan, diags);
  if (method !== null) {
    t.fieldResolutions.set(expr, { kind: "method", resolution: method });
    return methodBoundFnType(method, t);
  }

  // Trait receiver: `t: Some Trait; t.method()`. The runtime knows the actual
  // struct via the box tag, so the lowerer emits a chain of `is X -> X_method`
  // dispatches over every known impl of the trait. Type-check side just
  // returns the method's bound fn type (with Self → trait receiver).
  if (targetType.kind === "Trait") {
    const traitDecl = sourceTraitDecl(targetType.symbol);
    if (traitDecl !== null) {
      const member = traitDecl.members.find((m) => m.name === expr.field);
      if (member !== undefined) {
        const fnType = t.globals.declTypes.get(member);
        if (fnType !== undefined && fnType.kind === "Fn") {
          t.fieldResolutions.set(expr, {
            kind: "trait-virtual",
            resolution: { trait: targetType.symbol, member },
          });
          // Drop the receiver param (params[0] is `self`); substitute Self with
          // the trait type and the trait's own type-params with the receiver's
          // concrete args so e.g. `it: Iterator(i32); it.step()` returns
          // `Done | Yielded(i32)` instead of `Done | Yielded($T)`.
          const traitSubst = buildStructSubst(
            traitDecl.typeParams, targetType.args, t.globals.typeParamSymbols,
          );
          const subst: Substitution = { self: targetType, typeParams: traitSubst.typeParams };
          return {
            kind: "Fn",
            params: fnType.params.slice(1).map((p) => substitute(p, subst)),
            returnType: substitute(fnType.returnType, subst),
          };
        }
      }
    }
  }

  // Trait-method dispatch on a generic type parameter — receiver type is a
  // bare `$T`; we look up its bounds via the resolver's `typeParamBounds`,
  // then for each bound trait check whether it owns the requested method.
  // Resolution recorded so the mono pass can look up the concrete impl
  // member once the call-site substitution is known.
  if (targetType.kind === "TypeParam") {
    const traitMethod = findTraitMethodOnParam(targetType, expr.field, t);
    if (traitMethod !== null) {
      t.fieldResolutions.set(expr, { kind: "trait-method", resolution: traitMethod });
      return traitMethodBoundFnType(traitMethod, targetType, t);
    }
  }

  // UFCS for free functions: resolver recorded a candidate if the name was in scope.
  const ufcsRef = t.resolved.fieldRefs.get(expr);
  if (ufcsRef?.kind === "ufcs-free") {
    const boundType = inferUfcsFreeBound(expr, ufcsRef.symbol, targetType, t, impls, diags);
    if (boundType !== null) return boundType;
  }

  if (targetType.kind !== "Unresolved") {
    err(diags, "T3009", expr.fieldSpan, `\`${expr.field}\` on ${displayType(targetType)}`);
  }
  return TY.unresolved;
}

/** Resolve `t.field` for a non-union receiver. Returns null when the
 *  field doesn't exist on `t`. Used by the union common-field path :
 *  walks every variant, asks this helper, unions the results.
 *
 *  Mirrors the field lookup branches in `inferField` for Struct and
 *  Tuple types — the cases that have a static field set. Other shapes
 *  (Enum, Trait, Primitive, Array, Fn, …) fall through to null since
 *  none of them carry a named-field surface that's meaningful inside
 *  a union mix. */
export function fieldTypeOnType(target: Type, fieldName: string, t: MutableTyped): Type | null {
  if (target.kind === "Struct") {
    const decl = sourceStructDecl(target.symbol);
    if (decl === null) return null;
    const field = decl.fields.find((f) => f.name === fieldName);
    if (field === undefined) return null;
    const raw = t.globals.typeExprTypes.get(field.type) ?? TY.unresolved;
    const subst = tryStructSubst(decl, target.args, t.globals);
    return subst !== null ? substitute(raw, subst) : raw;
  }
  if (target.kind === "Tuple") {
    const idx = Number.parseInt(fieldName, 10);
    if (Number.isFinite(idx) && idx >= 0 && idx < target.elements.length) {
      return target.elements[idx]!;
    }
    return null;
  }
  return null;
}

/** Walk the trait bounds of `param`'s symbol — declared via a `where T: …`
 *  clause — and return the first one that owns a method named `name`. */
function findTraitMethodOnParam(
  param: Extract<Type, { kind: "TypeParam" }>,
  name: string,
  t: MutableTyped,
): TraitMethodResolution | null {
  const traitBounds = t.globals.typeParamBounds.get(param.symbol.id);
  if (traitBounds === undefined) return null;
  for (const traitSym of traitBounds) {
    if (traitSym.source.kind !== "trait") continue;
    const member = traitSym.source.decl.members.find((m) => m.name === name);
    if (member !== undefined) {
      return { trait: traitSym, member, receiverParam: param };
    }
  }
  return null;
}

/** The fn type a `t.method` access exposes when `t` has TypeParam type and
 *  the method comes from a trait bound. The trait declares `fn method(self, …)`
 *  with `Self` substituted by the TypeParam at the call site; we drop the
 *  receiver param to mirror UFCS bound-method shape. */
function traitMethodBoundFnType(
  resolution: TraitMethodResolution,
  receiverParam: Type,
  t: MutableTyped,
): Type {
  const fnType = t.globals.declTypes.get(resolution.member);
  if (fnType === undefined || fnType.kind !== "Fn") return TY.unresolved;
  const subst: Substitution = { typeParams: new Map(), self: receiverParam };
  const boundParams = fnType.params.length > 0 ? fnType.params.slice(1) : fnType.params;
  return {
    kind: "Fn",
    params: boundParams.map((p) => substitute(p, subst)),
    returnType: substitute(fnType.returnType, subst),
  };
}

/** Rank fn overloads by their first parameter's compatibility with `recvType`,
 *  returning the best of three tiers (best wins) and a runner-up at the
 *  concrete tier so callers can flag ambiguity (T3032).
 *
 *    1. Concrete `isAssignable` (no TypeParams in first-param at all).
 *    2. Generic struct/trait of same symbol as receiver (e.g. first-param
 *       `MutableList($T)` matches receiver `MutableList(i32)` by symbol.id).
 *    3. Pure type-param wildcard (`fn(self: $T, ...)`) — accepts anything.
 */
export function rankOverloadsByFirstParam(
  overloads: readonly Symbol[], recvType: Type, t: MutableTyped,
  impls?: ImplRegistry,
): { concrete: Symbol | null; concreteOther: Symbol | null; symMatch: Symbol | null; wildcard: Symbol | null; intoMatch: Symbol | null } {
  let concrete: Symbol | null = null;
  let concreteOther: Symbol | null = null;
  let symMatch: Symbol | null = null;
  let wildcard: Symbol | null = null;
  let intoMatch: Symbol | null = null;
  for (const cand of overloads) {
    const decl = declOf(cand);
    const fnType = decl !== null ? t.globals.declTypes.get(decl) : undefined;
    if (fnType === undefined || fnType.kind !== "Fn") continue;
    const firstParam = fnType.params[0];
    if (firstParam === undefined) continue;
    if (matchesByStructSymbol(firstParam, recvType)) {
      if (symMatch === null) symMatch = cand;
      continue;
    }
    if (firstParam.kind === "TypeParam") {
      if (wildcard === null) wildcard = cand;
      continue;
    }
    // Trait-typed first param like `Iterator(T)` : accept the candidate
    // when the receiver implements the trait. Unification of the trait's
    // typeparam(s) against the receiver's impl happens later in
    // `inferGenericUfcsCall` via `unifyTraitParamWithConcrete`. Classified
    // alongside `symMatch` (sibling-symbol match) since both are
    // "structurally compatible with type-param holes still open" matches —
    // strictly weaker than a fully concrete `isAssignable` hit.
    if (firstParam.kind === "Trait" && impls !== undefined
        && (recvType.kind === "Struct" || recvType.kind === "Primitive" || recvType.kind === "Array")
        && receiverImplementsTrait(recvType, firstParam.symbol, impls)) {
      if (symMatch === null) symMatch = cand;
      continue;
    }
    if (typeContainsTypeParam(firstParam)) continue;
    if (!isAssignable(recvType, firstParam)) {
      // No direct flow ; probe `Into(firstParam)` as a last-resort fallback.
      // Strictly weaker than every other rank — only fires when neither
      // concrete/symMatch/wildcard has a candidate. `findIntoImpl` is the
      // pure-read variant of `tryInto` (no state mutation here ; the
      // chosen overload will run `tryInto` per-arg later).
      if (intoMatch === null && impls !== undefined
          && findIntoImpl(recvType, firstParam, t, impls) !== null) {
        intoMatch = cand;
      }
      continue;
    }
    if (concrete === null) concrete = cand;
    else if (concreteOther === null) concreteOther = cand;
  }
  return { concrete, concreteOther, symMatch, wildcard, intoMatch };
}

/** Validate that `freeSym` (or one of its sibling overloads) is a fn whose
 *  first param accepts `targetType`, record the chosen resolution, and return
 *  the bound fn type (params without the first). Returns null when no
 *  candidate matches — caller emits T3009. */
function inferUfcsFreeBound(
  expr: A.FieldExpr, freeSym: Symbol, targetType: Type, t: MutableTyped,
  impls: ImplRegistry, diags: DiagnosticCollector,
): Type | null {
  const ranked = rankOverloadsByFirstParam(fnOverloadsForSymbol(freeSym, t), targetType, t, impls);
  if (ranked.concrete !== null && ranked.concreteOther !== null) {
    err(diags, "T3032", expr.fieldSpan,
      `multiple concrete candidates for \`${expr.field}\` on ${displayType(targetType)}`);
  }
  const chosen = ranked.concrete ?? ranked.symMatch ?? ranked.wildcard ?? ranked.intoMatch;
  if (chosen === null) return null;
  const decl = declOf(chosen);
  const fnType = decl !== null ? t.globals.declTypes.get(decl) : undefined;
  if (fnType === undefined || fnType.kind !== "Fn") return null;
  t.fieldResolutions.set(expr, { kind: "ufcs-free", symbol: chosen });
  return { kind: "Fn", params: fnType.params.slice(1), returnType: fnType.returnType };
}

/** True when both the candidate's first param and the receiver are generic
 *  struct (or trait) types with the same backing symbol. Lets `MutableList($T)`
 *  match `MutableList(i32)` even though `isAssignable` rejects the type-arg
 *  pair (TypeParam ≠ concrete). The actual T = i32 binding flows through the
 *  generic-fn dispatch downstream. */
function matchesByStructSymbol(firstParam: Type, receiver: Type): boolean {
  if (firstParam.kind === "Struct" && receiver.kind === "Struct") {
    return firstParam.symbol.id === receiver.symbol.id;
  }
  if (firstParam.kind === "Trait" && receiver.kind === "Trait") {
    return firstParam.symbol.id === receiver.symbol.id;
  }
  if (firstParam.kind === "Array" && receiver.kind === "Array") {
    return typeContainsTypeParam(firstParam.element);
  }
  return false;
}

/** True when `recvType` can flow into a trait-typed slot of `traitSym`
 *  — either through an explicit impl entry (struct / primitive / enum)
 *  or via the built-in `T[]` → `Iterator(T)` widening (which has no
 *  user-declared impl decl). Mirrors `isAssignable`'s trait-widening
 *  branch ; used by `rankOverloadsByFirstParam` to accept overloads
 *  whose first parameter is a trait with open type-params. */
function receiverImplementsTrait(
  recvType: Type, traitSym: Symbol, impls: ImplRegistry,
): boolean {
  if (recvType.kind === "Struct" || recvType.kind === "Primitive" || recvType.kind === "Enum") {
    return impls.findFor(recvType, traitSym) !== null;
  }
  if (recvType.kind === "Array") {
    const iter = impls.coreTrait(CORE_TRAITS.Iterator);
    return iter !== null && iter.id === traitSym.id;
  }
  return false;
}

/** Sibling overloads for `sym` in its source module. Returns at least `[sym]`
 *  if no overload set exists (callers can iterate uniformly). */
export function fnOverloadsForSymbol(sym: Symbol, t: MutableTyped): readonly Symbol[] {
  if (sym.kind !== "fn") return [sym];
  const bucket = t.globals.modules?.get(sym.module)?.fnOverloads.get(sym.name);
  return bucket !== undefined && bucket.length > 0 ? bucket : [sym];
}

/** Generic UFCS free-fn call. Uses the full fn type (receiver as params[0]) to
 *  infer type-param bindings from both the receiver and the explicit arguments. */
export function inferGenericUfcsCall(
  expr: A.CallExpr, callee: A.FieldExpr,
  fullFnType: Extract<Type, { kind: "Fn" }>,
  freeSym: Symbol,
  t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const receiverType = defaultIfFree(t.exprTypes.get(callee.target) ?? TY.unresolved);
  const explicitArgTypes = expr.args.map((a) => checkExpr(a.value, null, t, impls, diags, fn));

  const expectedExplicit = fullFnType.params.length - 1;
  if (expr.args.length !== expectedExplicit) {
    err(diags, "T3003", expr.span, `expected ${expectedExplicit}, got ${expr.args.length}`);
  }

  const bindings = new Map<number, Type>();
  unifyTypeParam(fullFnType.params[0]!, receiverType, bindings, impls, t);
  for (let i = 0; i < explicitArgTypes.length && i + 1 < fullFnType.params.length; i++) {
    unifyTypeParam(fullFnType.params[i + 1]!, defaultIfFree(explicitArgTypes[i]!), bindings, impls, t);
  }
  const subst: Substitution = { typeParams: bindings };

  for (let i = 0; i < expr.args.length; i++) {
    const paramIdx = i + 1;
    if (paramIdx >= fullFnType.params.length) break;
    const expectedTy = substitute(fullFnType.params[paramIdx]!, subst);
    if (!typeContainsTypeParam(expectedTy) && !isAssignable(explicitArgTypes[i]!, expectedTy, impls)) {
      err(diags, "T3001", expr.args[i]!.value.span,
        `expected ${displayType(expectedTy)}, got ${displayType(explicitArgTypes[i]!)}`);
    }
    if (!typeContainsTypeParam(expectedTy)) {
      pinFreeNumericArg(explicitArgTypes[i]!, expectedTy, expr.args[i]!.value, t, impls);
    }
  }

  recordGenericCallSite(expr, declOf(freeSym), bindings, t, impls, diags);

  return substitute(fullFnType.returnType, subst);
}

/** Repin a Free* arg literal to the substituted expected type so the lowerer
 *  emits the right width — `take(nums, 3)` with `n: usize` ⇒ `3` lowers as
 *  `i64.const`. Mirrors `checkExpr`'s bidirectional defaulting, deferred
 *  here because generic call sites need the substitution before pinning. */
export function pinFreeNumericArg(
  got: Type, expectedTy: Type, argExpr: A.Expr,
  t: MutableTyped, impls: ImplRegistry,
): void {
  if (got.kind !== "FreeInt" && got.kind !== "FreeFloat") return;
  if (!isAssignable(got, expectedTy, impls)) return;
  t.exprTypes.set(argExpr, expectedTy);
}

export function recordGenericCallSite(
  expr: A.CallExpr, decl: ReturnType<typeof declOf>,
  bindings: ReadonlyMap<number, Type>, t: MutableTyped,
  impls: ImplRegistry, diags: DiagnosticCollector,
): void {
  if (decl === null || decl.kind !== "FnDecl" || decl.typeParams.length === 0) return;
  const typeArgs = decl.typeParams.map((tp) => {
    const tpSym = t.globals.typeParamSymbols.get(tp);
    return tpSym !== undefined ? (bindings.get(tpSym.id) ?? TY.unresolved) : TY.unresolved;
  });
  // Record even when args still contain TypeParams — the comptime
  // closeOverGenericImpls pass substitutes them at each enclosing instance to
  // observe transitive generic call sites (e.g. inner_fn called from
  // outer_fn<T>'s body materialises `inner_fn<i32>` once outer_fn<i32> is
  // observed). Unresolved entries are still skipped — those signal a real
  // unification failure already reported elsewhere.
  if (typeArgs.every((a) => a.kind !== "Unresolved")) {
    t.genericFnCalls.set(expr, typeArgs);
  }
  // Layer 7e — auto-enforce bracketed `[T: Trait]` and `where T: Trait`
  // bounds. For every fully-resolved type-arg, look up the trait bounds
  // attached to its formal type-param and emit T3006 if the concrete type
  // has no impl. TypeParam-typed args (from inside another generic body)
  // are skipped — they propagate to the outer instance which checks at
  // its own call site once it's monomorphised.
  for (let i = 0; i < decl.typeParams.length; i++) {
    const concrete = typeArgs[i]!;
    if (concrete.kind === "Unresolved" || concrete.kind === "TypeParam") continue;
    const tpSym = t.globals.typeParamSymbols.get(decl.typeParams[i]!);
    if (tpSym === undefined) continue;
    const bounds = t.globals.typeParamBounds.get(tpSym.id);
    if (bounds === undefined) continue;
    for (const traitSym of bounds) {
      if (impls.findFor(concrete, traitSym) === null) {
        err(diags, "T3006", expr.span,
          `\`${displayType(concrete)}\` does not implement \`${traitSym.name}\` (required by type parameter \`${decl.typeParams[i]!.name}\` of \`${decl.name}\`)`);
      }
    }
  }
}

/** Walk the impl registry for a method matching the target type + name. */
function findImplMethod(
  impls: ImplRegistry, targetType: Type, name: string, t: MutableTyped,
  fieldSpan: Span | null,
  diags: DiagnosticCollector | null,
): MethodResolution | null {
  // Walk every distinct trait that any impl on `targetType`'s symbol claims,
  // and ask the registry for the canonical impl for `(targetType, trait)` —
  // `findFor` already disambiguates concrete instances (Range[i32] vs
  // Range[char]) via the args key. Any trait whose canonical impl declares
  // a member named `name` contributes a match. Ambiguous when ≥ 2 distinct
  // traits provide the same method on the same type — emit T3032 ; pick
  // the first to keep the AST resolvable.
  const matches: { entry: ImplEntry; member: A.FnDecl }[] = [];
  const seenTraits = new Set<number>();
  for (const entry of impls.entries()) {
    if (entry.traitSymbol === null) continue;
    if (!implMatchesTarget(entry, targetType)) continue;
    if (seenTraits.has(entry.traitSymbol.id)) continue;
    seenTraits.add(entry.traitSymbol.id);
    const concrete = impls.findFor(targetType, entry.traitSymbol) ?? entry;
    const member = concrete.decl.members.find((m) => m.name === name);
    if (member === undefined) continue;
    matches.push({ entry: concrete, member });
  }
  if (matches.length === 0) return null;
  // Only flag when the matches come from *different* trait symbols. Multiple
  // impls of the same trait on the same type is a separate (coherence) issue
  // — user re-impls of e.g. `i32 implements Display` already happen in
  // tests/snippets/primitive_impl. The first declared one wins for this
  // dispatch path ; coherence diagnostics are tracked elsewhere.
  if (fieldSpan !== null && diags !== null) {
    const traitIds = new Set<number>();
    for (const m of matches) {
      const sym = m.entry.traitSymbol;
      if (sym !== null) traitIds.add(sym.id);
    }
    if (traitIds.size > 1) {
      const seen = new Set<string>();
      const names: string[] = [];
      for (const m of matches) {
        const n = m.entry.traitSymbol?.name ?? "<unknown>";
        if (!seen.has(n)) { seen.add(n); names.push(n); }
      }
      err(diags, "T3032", fieldSpan,
        `\`${name}\` on ${displayType(targetType)} is ambiguous between traits: ${names.join(", ")}`);
    }
  }
  const { entry, member } = matches[0]!;
  const traitArgs: Type[] = [];
  for (const ta of entry.decl.traitArgs) {
    const arg = t.globals.typeExprTypes.get(ta);
    if (arg !== undefined) traitArgs.push(arg);
  }
  return { impl: entry, member, receiverType: targetType, traitArgs };
}

function implMatchesTarget(entry: ImplEntry, target: Type): boolean {
  if (target.kind === "Struct" || target.kind === "Enum") {
    return entry.forSymbol !== null && entry.forSymbol.id === target.symbol.id;
  }
  if (target.kind === "Primitive") {
    return entry.forSymbol === null
      && entry.decl.forType.kind === "IdentExpr"
      && entry.decl.forType.name === target.name;
  }
  return false;
}

/** The fn type a bound method `obj.method` exposes — i.e. the impl member's
 *  fn type minus its `self` parameter (since the receiver is implicit).
 *  For generic structs, substitutes the struct's type params with the
 *  receiver's concrete args (e.g. Stack(i32) → T=i32). `Self` is already
 *  substituted at materialisation / declareImpl time, so no `self` subst here. */
function methodBoundFnType(method: MethodResolution, t: MutableTyped): Type {
  const fnType = t.globals.declTypes.get(method.member);
  if (fnType === undefined || fnType.kind !== "Fn") return TY.unresolved;
  const params = fnType.params.length > 0 ? fnType.params.slice(1) : fnType.params;

  const recv = method.receiverType;
  if (recv.kind === "Struct") {
    const structDecl = sourceStructDecl(recv.symbol);
    const structSubst = structDecl !== null
      ? tryStructSubst(structDecl, recv.args, t.globals) : null;
    // Bounded-generic impl bodies reference the impl's own type-params,
    // not the struct's. Layer the impl-side substitution on top so signature
    // / return types written in terms of impl-T (e.g. `Range[T]`'s default
    // `last(self) -> T | null` after trait-arg propagation) resolve to the
    // concrete struct args at the call site.
    const implDecl = method.impl.decl;
    let implSubst: Substitution | null = null;
    if (implDecl.typeParams.length > 0) {
      implSubst = buildStructSubst(implDecl.typeParams, recv.args, t.globals.typeParamSymbols);
    }
    const subst = mergeSubst(structSubst, implSubst);
    if (subst !== null) {
      return {
        kind: "Fn",
        params: params.map((p) => substitute(p, subst)),
        returnType: substitute(fnType.returnType, subst),
      };
    }
  }

  return { kind: "Fn", params, returnType: fnType.returnType };
}
