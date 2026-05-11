// Call-site checking. Handles three forms:
//   1. `Type(value)` constructor / cast — the callee resolves to a type symbol.
//   2. `obj.method(args)` UFCS — the FieldExpr callee resolves through
//      `findImplMethod`, which records the resolution into `methodResolutions`
//      so the lowerer can rewrite the call into a direct call of the impl fn.
//   3. Plain `f(args)` — fn-typed callee, regular arity / argument check.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf, sourceStructDecl, sourceTraitDecl } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplEntry, ImplRegistry } from "../impls.ts";
import type {MethodResolution, TraitMethodResolution, UnionFieldResolution} from "../typed-ast.ts";
import type { Substitution, Type } from "../types.ts";
import { CORE_TRAITS, TY, defaultIfFree, displayType, isAssignable, isNumeric, isPrimitive, substitute, unionOf } from "../types.ts";

import { buildStructSubst, tryStructSubst } from "../ctx.ts";
import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkEnumVariant } from "./enum.ts";
import { checkExpr, typeOfSymbol } from "./expr.ts";
import { findGlobalTrait } from "./traits.ts";
import { primitiveFromName } from "./type-expr.ts";

export function inferCall(
  expr: A.CallExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Cast form: `Type(value)` — the callee is an ident resolving to a type symbol.
  if (expr.callee.kind === "IdentExpr") {
    const sym = t.resolved.idents.get(expr.callee);
    if (sym !== undefined && (sym.kind === "builtin-type" || sym.kind === "struct" || sym.kind === "type-alias")) {
      return inferTypeConstructorCall(expr, t, impls, diags, fn);
    }
    // Direct-call overload resolution: a fn name that resolves to multiple
    // sibling overloads needs the right candidate picked by the first arg's
    // type before we infer the callee's fn type. Matches the UFCS dispatch
    // policy (concrete > symbol-match > wildcard).
    if (sym !== undefined && sym.kind === "fn") {
      const overloads = fnOverloadsForSymbol(sym, t);
      if (overloads.length > 1 && expr.args.length > 0) {
        // Default free numeric literals to their canonical type (i32 / f64)
        // before ranking — otherwise `abs(-7)` matches both `abs(i32)` and
        // `abs(f64)` and silently picks the first declared overload.
        const firstArgTy = defaultIfFree(checkExpr(expr.args[0]!.value, null, t, impls, diags, fn));
        const chosen = pickDirectCallOverload(overloads, firstArgTy, t);
        if (chosen !== null && chosen !== sym) {
          t.directCallOverloads.set(expr, chosen);
        } else if (chosen === null) {
          err(diags, "T3032", expr.callee.span,
            `no overload of \`${sym.name}\` matches receiver ${displayType(firstArgTy)}`);
        }
      }
    }
  }

  const calleeType = chooseCalleeType(expr, t, impls, diags, fn);

  if (calleeType.kind !== "Fn") {
    if (calleeType.kind !== "Unresolved") err(diags, "T3007", expr.callee.span, displayType(calleeType));
    for (const a of expr.args) checkExpr(a.value, null, t, impls, diags, fn);
    return TY.unresolved;
  }

  // Generic UFCS free fn call: callee is `receiver.fn(args)` where `fn` is a
  // generic free function. The bound calleeType has the receiver param dropped,
  // so we must use the full fn type (with receiver as params[0]) to infer T.
  if (expr.callee.kind === "FieldExpr") {
    const freeSym = t.ufcsFreeResolutions.get(expr.callee);
    if (freeSym !== undefined) {
      const ufcsDecl = declOf(freeSym);
      const fullFnType = ufcsDecl !== null ? t.globals.declTypes.get(ufcsDecl) : undefined;
      if (fullFnType !== undefined && fullFnType.kind === "Fn" && fullFnType.params.some(typeContainsTypeParam)) {
        return inferGenericUfcsCall(expr, expr.callee, fullFnType, freeSym, t, impls, diags, fn);
      }
    }
  }

  // Generic fn call: at least one param type contains a TypeParam.
  // Infer the substitution from argument types, then re-check under it.
  if (calleeType.params.some(typeContainsTypeParam)) {
    return inferGenericFnCall(expr, calleeType, t, impls, diags, fn);
  }

  // Arity check.
  const positionals = expr.args.filter((a) => a.name === null);
  if (positionals.length !== calleeType.params.length) {
    // Allow named args: total count must match for now (named-only resolution deferred to MVP+).
    if (expr.args.length !== calleeType.params.length) {
      err(diags, "T3003", expr.span,
        `expected ${calleeType.params.length}, got ${expr.args.length}`);
    }
  }
  for (let i = 0; i < expr.args.length; i++) {
    const arg = expr.args[i]!;
    const expectedTy = i < calleeType.params.length ? calleeType.params[i]! : null;
    const got = checkExpr(arg.value, expectedTy, t, impls, diags, fn);
    if (expectedTy !== null && !isAssignable(got, expectedTy, impls)) {
      err(diags, "T3001", arg.value.span,
        `expected ${displayType(expectedTy)}, got ${displayType(got)}`);
    }
    if (expectedTy !== null) {
      recordIterCoercion(arg.value, got, expectedTy, t);
      recordDisplayCoercion(arg.value, got, expectedTy, t);
    }
  }
  return calleeType.returnType;
}

function inferGenericFnCall(
  expr: A.CallExpr,
  calleeType: Extract<Type, { kind: "Fn" }>,
  t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Step 1: collect arg types without type-param expected context.
  const argTypes: Type[] = expr.args.map((a) => checkExpr(a.value, null, t, impls, diags, fn));

  // Step 2: unify param types with (defaulted) arg types to build the substitution.
  const bindings = new Map<number, Type>();
  for (let i = 0; i < calleeType.params.length && i < argTypes.length; i++) {
    unifyTypeParam(calleeType.params[i]!, defaultIfFree(argTypes[i]!), bindings, impls, t);
  }
  const subst: Substitution = { typeParams: bindings };

  // Step 3: arity check.
  if (expr.args.length !== calleeType.params.length) {
    err(diags, "T3003", expr.span,
      `expected ${calleeType.params.length}, got ${expr.args.length}`);
  }

  // Step 4: assignability check against the substituted param types.
  for (let i = 0; i < calleeType.params.length && i < argTypes.length; i++) {
    const expectedTy = substitute(calleeType.params[i]!, subst);
    if (!typeContainsTypeParam(expectedTy) && !isAssignable(argTypes[i]!, expectedTy, impls)) {
      err(diags, "T3001", expr.args[i]!.value.span,
        `expected ${displayType(expectedTy)}, got ${displayType(argTypes[i]!)}`);
    }
    if (!typeContainsTypeParam(expectedTy)) {
      // Pin FreeInt/FreeFloat arg literals to the substituted expected type so
      // the lowerer emits the right width (`take(nums, 3)` with `n: usize`
      // → 3 must lower as `i64.const`, not `i32.const`). Mirrors the
      // bidirectional defaulting in `checkExpr` ; step 1's `checkExpr(.., null)`
      // couldn't apply it yet because the substitution wasn't built.
      const got = argTypes[i]!;
      if ((got.kind === "FreeInt" && isAssignable(got, expectedTy, impls))
       || (got.kind === "FreeFloat" && isAssignable(got, expectedTy, impls))) {
        t.exprTypes.set(expr.args[i]!.value, expectedTy);
      }
      recordIterCoercion(expr.args[i]!.value, argTypes[i]!, expectedTy, t);
      recordDisplayCoercion(expr.args[i]!.value, argTypes[i]!, expectedTy, t);
    }
  }

  if (expr.callee.kind === "IdentExpr") {
    const sym = t.resolved.idents.get(expr.callee);
    if (sym !== undefined) recordGenericCallSite(expr, declOf(sym), bindings, t, impls, diags);
  }

  return substitute(calleeType.returnType, subst);
}

function inferTypeConstructorCall(
  expr: A.CallExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Record the callee's type-meta nature in the side-table for later tooling.
  t.exprTypes.set(expr.callee, TY.type);
  const target = identTargetType(expr.callee, t);
  if (target === null) {
    err(diags, "T3010", expr.callee.span, "cannot determine target type");
    return TY.unresolved;
  }

  // Generic instantiation `Foo(T1, T2)` — record but keep MVP-simple: produce the
  // base type unchanged. Real generics flow through the comptime engine in 1.5.
  if (target.kind === "Struct" && expr.args.length > 0) {
    for (const a of expr.args) checkExpr(a.value, null, t, impls, diags, fn);
    return target;
  }

  // Numeric cast `i32(x)` etc. + char ↔ integer casts. The MVP allows numeric
  // primitives both ways, plus `char` on either side (treated as a u32
  // codepoint at the wire level).
  if (expr.args.length !== 1) {
    err(diags, "T3010", expr.span, "cast takes exactly one argument");
    for (const a of expr.args) checkExpr(a.value, null, t, impls, diags, fn);
    return TY.unresolved;
  }
  const arg = expr.args[0]!.value;
  const argType = checkExpr(arg, null, t, impls, diags, fn);
  const targetOk = isNumeric(target) || isPrimitive(target, "char");
  if (!targetOk) {
    err(diags, "T3010", expr.callee.span,
      `cast target must be a primitive numeric type or char, got ${displayType(target)}`);
    return target;
  }
  const sourceOk = isNumeric(argType)
    || isPrimitive(argType, "char")
    || argType.kind === "Unresolved"
    || argType.kind === "FreeInt"
    || argType.kind === "FreeFloat";
  if (!sourceOk) {
    err(diags, "T3010", arg.span,
      `cast source must be numeric or char, got ${displayType(argType)}`);
  }
  // Casting char → float or float → char is rejected — chars are integral.
  if (isPrimitive(target, "char") && argType.kind === "Primitive"
      && (argType.name === "f32" || argType.name === "f64")) {
    err(diags, "T3010", arg.span, "cannot cast float to char");
  }
  if (isPrimitive(argType, "char") && isPrimitive(target, "f32")) {
    err(diags, "T3010", expr.callee.span, "cannot cast char to f32 (use u32 first)");
  }
  if (isPrimitive(argType, "char") && isPrimitive(target, "f64")) {
    err(diags, "T3010", expr.callee.span, "cannot cast char to f64 (use u32 first)");
  }
  return target;
}

function identTargetType(callee: A.Expr, t: MutableTyped): Type | null {
  if (callee.kind !== "IdentExpr") return null;
  const sym = t.resolved.idents.get(callee);
  if (sym === undefined) return null;
  if (sym.kind === "builtin-type") return primitiveFromName(sym.name);
  if (sym.kind === "struct" || sym.kind === "type-alias") {
    const decl = declOf(sym);
    return decl !== null ? t.globals.declTypes.get(decl) ?? null : null;
  }
  return null;
}

export function inferField(
  expr: A.FieldExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Module-namespace field: resolver already wired the export.
  const exported = t.resolved.fields.get(expr);
  if (exported !== undefined) return typeOfSymbol(exported, t);

  const targetType = checkExpr(expr.target, null, t, impls, diags, fn);
  if (targetType.kind === "Array") {
    if (expr.field === "len") {
      t.arrayOps.set(expr, "len");
      return { kind: "Fn", params: [], returnType: TY.usize };
    }
    if (expr.field === "push") {
      t.arrayOps.set(expr, "push");
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
  // Hints if any variant is missing the field, listing the offenders.
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
      t.unionFieldResolutions.set(expr, {
        variants: targetType.variants.map((v, i) => ({ type: v, fieldType: fieldTypes[i]! })),
      });
      return unionOf(fieldTypes);
    }
    if (missing.length > 0) {
      err(diags, "T3009", expr.fieldSpan,
        `\`${expr.field}\` not on every variant of ${displayType(targetType)}: missing on ${missing.join(", ")}`);
      return TY.unresolved;
    }
  }

  // No struct field — try impl-method lookup. Records into `methodResolutions`
  // so the lowerer can rewrite `obj.method(args)` into a direct call of the
  // specialised impl fn with `obj` as the first arg. Emits T3032 when two
  // distinct traits' impls each provide the requested method on this type.
  const method = findImplMethod(impls, targetType, expr.field, t, expr.fieldSpan, diags);
  if (method !== null) {
    t.methodResolutions.set(expr, method);
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
          t.traitVirtualResolutions.set(expr, { trait: targetType.symbol, member });
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
      t.traitMethodResolutions.set(expr, traitMethod);
      return traitMethodBoundFnType(traitMethod, targetType, t);
    }
  }

  // UFCS for free functions: resolver recorded a candidate if the name was in scope.
  const freeSym = t.resolved.ufcsFreeResolutions.get(expr);
  if (freeSym !== undefined) {
    const boundType = inferUfcsFreeBound(expr, freeSym, targetType, t, diags);
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
function fieldTypeOnType(target: Type, fieldName: string, t: MutableTyped): Type | null {
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
function rankOverloadsByFirstParam(
  overloads: readonly Symbol[], recvType: Type, t: MutableTyped,
): { concrete: Symbol | null; concreteOther: Symbol | null; symMatch: Symbol | null; wildcard: Symbol | null } {
  let concrete: Symbol | null = null;
  let concreteOther: Symbol | null = null;
  let symMatch: Symbol | null = null;
  let wildcard: Symbol | null = null;
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
    if (typeContainsTypeParam(firstParam)) continue;
    if (!isAssignable(recvType, firstParam)) continue;
    if (concrete === null) concrete = cand;
    else if (concreteOther === null) concreteOther = cand;
  }
  return { concrete, concreteOther, symMatch, wildcard };
}

/** Validate that `freeSym` (or one of its sibling overloads) is a fn whose
 *  first param accepts `targetType`, record the chosen resolution, and return
 *  the bound fn type (params without the first). Returns null when no
 *  candidate matches — caller emits T3009. */
function inferUfcsFreeBound(
  expr: A.FieldExpr, freeSym: Symbol, targetType: Type, t: MutableTyped,
  diags: DiagnosticCollector,
): Type | null {
  const ranked = rankOverloadsByFirstParam(fnOverloadsForSymbol(freeSym, t), targetType, t);
  if (ranked.concrete !== null && ranked.concreteOther !== null) {
    err(diags, "T3032", expr.fieldSpan,
      `multiple concrete candidates for \`${expr.field}\` on ${displayType(targetType)}`);
  }
  const chosen = ranked.concrete ?? ranked.symMatch ?? ranked.wildcard;
  if (chosen === null) return null;
  const decl = declOf(chosen);
  const fnType = decl !== null ? t.globals.declTypes.get(decl) : undefined;
  if (fnType === undefined || fnType.kind !== "Fn") return null;
  t.ufcsFreeResolutions.set(expr, chosen);
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

/** Sibling overloads for `sym` in its source module. Returns at least `[sym]`
 *  if no overload set exists (callers can iterate uniformly). */
function fnOverloadsForSymbol(sym: Symbol, t: MutableTyped): readonly Symbol[] {
  if (sym.kind !== "fn") return [sym];
  const bucket = t.globals.modules?.get(sym.module)?.fnOverloads.get(sym.name);
  return bucket !== undefined && bucket.length > 0 ? bucket : [sym];
}

/** Pick the best overload for a direct `f(arg, …)` call by matching the
 *  first argument's type. Mirrors UFCS dispatch policy. Returns null when no
 *  candidate matches. */
function pickDirectCallOverload(
  overloads: readonly Symbol[], firstArgTy: Type, t: MutableTyped,
): Symbol | null {
  const ranked = rankOverloadsByFirstParam(overloads, firstArgTy, t);
  return ranked.concrete ?? ranked.symMatch ?? ranked.wildcard;
}

/** Build the fn-typed `calleeType` for an inferCall, honoring the chosen
 *  overload when overload resolution picked a non-primary symbol. Falls back to
 *  the resolver's primary by running `checkExpr(expr.callee, …)` as before. */
function chooseCalleeType(
  expr: A.CallExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const chosen = t.directCallOverloads.get(expr);
  if (chosen !== undefined) {
    const decl = declOf(chosen);
    const fnType = decl !== null ? t.globals.declTypes.get(decl) : undefined;
    if (fnType !== undefined && fnType.kind === "Fn") {
      // Record the chosen fn type on the callee so downstream consumers
      // (lower's emit-by-type heuristics, dump tooling) see the picked overload.
      t.exprTypes.set(expr.callee, fnType);
      return fnType;
    }
  }
  return checkExpr(expr.callee, null, t, impls, diags, fn);
}

/** Generic UFCS free-fn call. Uses the full fn type (receiver as params[0]) to
 *  infer type-param bindings from both the receiver and the explicit arguments. */
function inferGenericUfcsCall(
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
      recordIterCoercion(expr.args[i]!.value, explicitArgTypes[i]!, expectedTy, t);
      recordDisplayCoercion(expr.args[i]!.value, explicitArgTypes[i]!, expectedTy, t);
    }
  }

  recordGenericCallSite(expr, declOf(freeSym), bindings, t, impls, diags);

  return substitute(fullFnType.returnType, subst);
}

/** Record an `[T]` → `Iterator(T)` coercion when the assignability check
 *  matched the trait-typed slot but the source expression is a raw array.
 *  The lowerer reads `arrayIterCoercions` to wrap the lowered expression
 *  in an `ArrayIter(T)` struct literal at the use site. */
export function recordIterCoercion(
  src: A.Expr, got: Type, expected: Type, t: MutableTyped,
): void {
  if (got.kind !== "Array") return;
  if (expected.kind !== "Trait" || expected.args.length !== 1) return;
  const iter = findGlobalTrait(t, CORE_TRAITS.Iterator);
  if (iter === null || iter.id !== expected.symbol.id) return;
  t.arrayIterCoercions.set(src, got.element);
}

/** Record a `T` → `Display` coercion at a use site where the parameter slot
 *  is `Display`-typed and the source has a concrete type implementing it.
 *  The lowerer reads `displayCoercions` to rewrite the argument into a
 *  static call to the `<T>.Display.to_string` impl member, so the host hook
 *  receives a flat string. Free-numeric sources are defaulted to their
 *  canonical type (`i32` / `f64`) before recording. */
export function recordDisplayCoercion(
  src: A.Expr, got: Type, expected: Type, t: MutableTyped,
): void {
  if (expected.kind !== "Trait") return;
  const display = findGlobalTrait(t, CORE_TRAITS.Display);
  if (display === null || display.id !== expected.symbol.id) return;
  // Already a Display value (or the param itself is Display) — nothing to do,
  // the existing virtual dispatch path handles trait-typed sources.
  if (got.kind === "Trait" && got.symbol.id === display.id) return;
  const concrete = defaultIfFree(got);
  // The lowerer needs a concrete impl member to dispatch to ; trait-typed
  // sources we can't statically resolve are left to the virtual path.
  if (concrete.kind !== "Primitive" && concrete.kind !== "Struct") return;
  t.displayCoercions.set(src, concrete);
}

function recordGenericCallSite(
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
  fieldSpan: import("../../diagnostics/diagnostic.ts").Span | null,
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

function mergeSubst(a: Substitution | null, b: Substitution | null): Substitution | null {
  if (a === null) return b;
  if (b === null) return a;
  const map = new Map<number, Type>();
  if (a.typeParams !== undefined) for (const [k, v] of a.typeParams) map.set(k, v);
  if (b.typeParams !== undefined) for (const [k, v] of b.typeParams) map.set(k, v);
  return { typeParams: map, self: a.self ?? b.self };
}

/** True if `t` contains at least one `TypeParam` node. */
function typeContainsTypeParam(t: Type): boolean {
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
function unifyTypeParam(
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
    // Generic struct receiver (`Foo($T) implements Iterator(T)`) : substitute
    // the struct's typeParams with the receiver's concrete args before unifying.
    const subst: Substitution = argType.kind === "Struct" && argType.symbol.source.kind === "struct"
      ? buildStructSubst(argType.symbol.source.decl.typeParams, argType.args, t.globals.typeParamSymbols)
      : { typeParams: new Map() };
    for (let i = 0; i < paramType.args.length && i < implTraitArgs.length; i++) {
      unifyTypeParam(paramType.args[i]!, substitute(implTraitArgs[i]!, subst), out, impls, t);
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
