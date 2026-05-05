// Call-site checking. Handles three forms:
//   1. `Type(value)` constructor / cast — the callee resolves to a type symbol.
//   2. `obj.method(args)` UFCS — the FieldExpr callee resolves through
//      `findImplMethod`, which records the resolution into `methodResolutions`
//      so the lowerer can rewrite the call into a direct call of the impl fn.
//   3. Plain `f(args)` — fn-typed callee, regular arity / argument check.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import { declOf, sourceStructDecl } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplEntry, ImplRegistry } from "../impls.ts";
import type { MethodResolution } from "../typed-ast.ts";
import type { Type } from "../types.ts";
import { TY, displayType, isAssignable, isNumeric } from "../types.ts";

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
  if (targetType.kind === "Enum") {
    checkEnumVariant(targetType, expr.field, expr.fieldSpan, diags);
    return targetType;
  }
  if (targetType.kind === "Struct") {
    const decl = sourceStructDecl(targetType.symbol);
    if (decl !== null) {
      const field = decl.fields.find((f) => f.name === expr.field);
      if (field !== undefined) return t.globals.typeExprTypes.get(field.type) ?? TY.unresolved;
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

  if (targetType.kind !== "Unresolved") {
    err(diags, "T3009", expr.fieldSpan, `\`${expr.field}\` on ${displayType(targetType)}`);
  }
  return TY.unresolved;
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
 *  fn type minus its `self` parameter (since the receiver is implicit). */
function methodBoundFnType(method: MethodResolution, t: MutableTyped): Type {
  const fnType = t.globals.declTypes.get(method.member);
  if (fnType === undefined || fnType.kind !== "Fn") return TY.unresolved;
  // Methods take `self` as the first param; drop it from the bound type.
  const params = fnType.params.length > 0 ? fnType.params.slice(1) : fnType.params;
  return { kind: "Fn", params, returnType: fnType.returnType };
}
