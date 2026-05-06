// Call-site checking. Handles three forms:
//   1. `Type(value)` constructor / cast — the callee resolves to a type symbol.
//   2. `obj.method(args)` UFCS — the FieldExpr callee resolves through
//      `findImplMethod`, which records the resolution into `methodResolutions`
//      so the lowerer can rewrite the call into a direct call of the impl fn.
//   3. Plain `f(args)` — fn-typed callee, regular arity / argument check.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf, sourceStructDecl } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplEntry, ImplRegistry } from "../impls.ts";
import type { MethodResolution } from "../typed-ast.ts";
import type { Substitution, Type } from "../types.ts";
import { TY, defaultIfFree, displayType, isAssignable, isNumeric, substitute } from "../types.ts";

import { tryStructSubst } from "../ctx.ts";
import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkEnumVariant } from "./enum.ts";
import { checkExpr, typeOfSymbol } from "./expr.ts";
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
  }

  const calleeType = checkExpr(expr.callee, null, t, impls, diags, fn);

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
    if (expectedTy !== null && !isAssignable(got, expectedTy)) {
      err(diags, "T3001", arg.value.span,
        `expected ${displayType(expectedTy)}, got ${displayType(got)}`);
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
    unifyTypeParam(calleeType.params[i]!, defaultIfFree(argTypes[i]!), bindings);
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
    if (!typeContainsTypeParam(expectedTy) && !isAssignable(argTypes[i]!, expectedTy)) {
      err(diags, "T3001", expr.args[i]!.value.span,
        `expected ${displayType(expectedTy)}, got ${displayType(argTypes[i]!)}`);
    }
  }

  if (expr.callee.kind === "IdentExpr") {
    const sym = t.resolved.idents.get(expr.callee);
    if (sym !== undefined) recordGenericCallSite(expr, declOf(sym), bindings, t);
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

  // Numeric cast `i32(x)` etc. — primitive numeric source + target only in MVP.
  if (expr.args.length !== 1) {
    err(diags, "T3010", expr.span, "cast takes exactly one argument");
    for (const a of expr.args) checkExpr(a.value, null, t, impls, diags, fn);
    return TY.unresolved;
  }
  const arg = expr.args[0]!.value;
  const argType = checkExpr(arg, null, t, impls, diags, fn);
  if (!isNumeric(target)) {
    err(diags, "T3010", expr.callee.span,
      `cast target must be a primitive numeric type, got ${displayType(target)}`);
    return target;
  }
  if (!isNumeric(argType) && argType.kind !== "Unresolved" && argType.kind !== "FreeInt" && argType.kind !== "FreeFloat") {
    err(diags, "T3010", arg.span,
      `cast source must be numeric, got ${displayType(argType)}`);
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
      return { kind: "Fn", params: [], returnType: TY.i32 };
    }
    if (expr.field === "push") {
      t.arrayOps.set(expr, "push");
      return { kind: "Fn", params: [targetType.element], returnType: TY.void };
    }
  }
  if (targetType.kind === "Enum") {
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

  // No struct field — try impl-method lookup. Records into `methodResolutions`
  // so the lowerer can rewrite `obj.method(args)` into a direct call of the
  // specialised impl fn with `obj` as the first arg.
  const method = findImplMethod(impls, targetType, expr.field, t);
  if (method !== null) {
    t.methodResolutions.set(expr, method);
    return methodBoundFnType(method, t);
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

/** Validate that `freeSym` (or one of its sibling overloads) is a fn whose
 *  first param accepts `targetType`, record the chosen resolution, and return
 *  the bound fn type (params without the first). Returns null when no
 *  candidate matches — caller emits T3009.
 *
 *  Match-rank ladder (best wins; ties at the *concrete* tier emit T3032) :
 *    1. Concrete `isAssignable` (no TypeParams in first-param at all).
 *    2. Generic struct/trait of same symbol as receiver (e.g. first-param
 *       `MutableList($T)` matches receiver `MutableList(i32)` by symbol.id).
 *    3. Pure type-param wildcard (`fn(self: $T, ...)`) — accepts anything.
 */
function inferUfcsFreeBound(
  expr: A.FieldExpr, freeSym: Symbol, targetType: Type, t: MutableTyped,
  diags: DiagnosticCollector,
): Type | null {
  const overloads = fnOverloadsForSymbol(freeSym, t);

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
    if (matchesByStructSymbol(firstParam, targetType)) {
      if (symMatch === null) symMatch = cand;
      continue;
    }
    if (firstParam.kind === "TypeParam") {
      if (wildcard === null) wildcard = cand;
      continue;
    }
    if (typeContainsTypeParam(firstParam)) continue;     // already handled by symbol-match
    if (!isAssignable(targetType, firstParam)) continue;
    if (concrete === null) concrete = cand;
    else if (concreteOther === null) concreteOther = cand;
  }

  if (concrete !== null && concreteOther !== null) {
    err(diags, "T3032", expr.fieldSpan,
      `multiple concrete candidates for \`${expr.field}\` on ${displayType(targetType)}`);
  }

  const chosen = concrete ?? symMatch ?? wildcard;
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
  return false;
}

/** Sibling overloads for `sym` in its source module. Returns at least `[sym]`
 *  if no overload set exists (callers can iterate uniformly). */
function fnOverloadsForSymbol(sym: Symbol, t: MutableTyped): readonly Symbol[] {
  if (sym.kind !== "fn") return [sym];
  const bucket = t.globals.modules?.get(sym.module)?.fnOverloads.get(sym.name);
  return bucket !== undefined && bucket.length > 0 ? bucket : [sym];
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
  unifyTypeParam(fullFnType.params[0]!, receiverType, bindings);
  for (let i = 0; i < explicitArgTypes.length && i + 1 < fullFnType.params.length; i++) {
    unifyTypeParam(fullFnType.params[i + 1]!, defaultIfFree(explicitArgTypes[i]!), bindings);
  }
  const subst: Substitution = { typeParams: bindings };

  for (let i = 0; i < expr.args.length; i++) {
    const paramIdx = i + 1;
    if (paramIdx >= fullFnType.params.length) break;
    const expectedTy = substitute(fullFnType.params[paramIdx]!, subst);
    if (!typeContainsTypeParam(expectedTy) && !isAssignable(explicitArgTypes[i]!, expectedTy)) {
      err(diags, "T3001", expr.args[i]!.value.span,
        `expected ${displayType(expectedTy)}, got ${displayType(explicitArgTypes[i]!)}`);
    }
  }

  recordGenericCallSite(expr, declOf(freeSym), bindings, t);

  return substitute(fullFnType.returnType, subst);
}

function recordGenericCallSite(
  expr: A.CallExpr, decl: ReturnType<typeof declOf>,
  bindings: ReadonlyMap<number, Type>, t: MutableTyped,
): void {
  if (decl === null || decl.kind !== "FnDecl" || decl.typeParams.length === 0) return;
  const typeArgs = decl.typeParams.map((tp) => {
    const tpSym = t.globals.typeParamSymbols.get(tp);
    return tpSym !== undefined ? (bindings.get(tpSym.id) ?? TY.unresolved) : TY.unresolved;
  });
  if (typeArgs.every((a) => a.kind !== "Unresolved" && a.kind !== "TypeParam")) {
    t.genericFnCalls.set(expr, typeArgs);
  }
}

/** Walk the impl registry for a method matching the target type + name. */
function findImplMethod(
  impls: ImplRegistry, targetType: Type, name: string, t: MutableTyped,
): MethodResolution | null {
  for (const entry of impls.entries()) {
    if (!implMatchesTarget(entry, targetType)) continue;
    const member = entry.decl.members.find((m) => m.name === name);
    if (member === undefined) continue;
    const traitArgs: Type[] = [];
    for (const ta of entry.decl.traitArgs) {
      const arg = t.globals.typeExprTypes.get(ta);
      if (arg !== undefined) traitArgs.push(arg);
    }
    return { impl: entry, member, receiverType: targetType, traitArgs };
  }
  return null;
}

function implMatchesTarget(entry: ImplEntry, target: Type): boolean {
  if (target.kind === "Struct") {
    return entry.forSymbol !== null && entry.forSymbol.id === target.symbol.id;
  }
  if (target.kind === "Primitive") {
    return entry.forSymbol === null
      && entry.decl.forType.kind === "NamedType"
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
    const subst = structDecl !== null ? tryStructSubst(structDecl, recv.args, t.globals) : null;
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

/** True if `t` contains at least one `TypeParam` node. */
function typeContainsTypeParam(t: Type): boolean {
  switch (t.kind) {
    case "TypeParam": return true;
    case "Array":     return typeContainsTypeParam(t.element);
    case "Struct":
    case "Trait":     return t.args.some(typeContainsTypeParam);
    case "Fn":        return t.params.some(typeContainsTypeParam) || typeContainsTypeParam(t.returnType);
    case "Union":     return t.variants.some(typeContainsTypeParam);
    default:          return false;
  }
}

/** Structural unification: extract TypeParam-symbol-id → concrete-type bindings
 *  by matching the shape of `paramType` against `argType`. Does not overwrite
 *  an already-bound symbol (first binding wins). */
function unifyTypeParam(paramType: Type, argType: Type, out: Map<number, Type>): void {
  if (paramType.kind === "TypeParam") {
    if (!out.has(paramType.symbol.id)) out.set(paramType.symbol.id, argType);
    return;
  }
  if (paramType.kind === "Array" && argType.kind === "Array") {
    unifyTypeParam(paramType.element, argType.element, out);
    return;
  }
  if ((paramType.kind === "Struct" || paramType.kind === "Trait")
      && argType.kind === paramType.kind
      && paramType.symbol.id === argType.symbol.id) {
    for (let i = 0; i < paramType.args.length && i < argType.args.length; i++) {
      unifyTypeParam(paramType.args[i]!, argType.args[i]!, out);
    }
    return;
  }
  if (paramType.kind === "Fn" && argType.kind === "Fn") {
    for (let i = 0; i < paramType.params.length && i < argType.params.length; i++) {
      unifyTypeParam(paramType.params[i]!, argType.params[i]!, out);
    }
    unifyTypeParam(paramType.returnType, argType.returnType, out);
  }
}
