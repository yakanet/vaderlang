// `Type(value)` constructor / cast call-form. The callee is an identifier
// that resolves to a type symbol (builtin primitive, user struct, or type
// alias). Two flavours collapse here :
//
//   - Numeric / char cast : `i32(x)`, `char(u32(c))`, etc. Bidirectional
//     between any numeric primitive (with the `char` family overlapping the
//     integer side). Float ↔ char is rejected explicitly.
//   - User-defined conversion : `Target(value)` for any non-primitive target
//     routes through an `Into(Target)` impl. The implicit Into path used by
//     parameter passing shares this code path so the explicit and implicit
//     forms always agree on which impl wins.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import { declOf } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Type } from "../types.ts";
import { TY, displayType, isInteger, isNumeric, isPrimitive } from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { tryInto } from "./coerce.ts";
import { checkExpr } from "./expr.ts";
import { primitiveFromName } from "./type-expr.ts";

export function inferTypeConstructorCall(
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
  // Pin a FreeInt / FreeFloat source to the target's width when the target
  // is an integer / char (FreeInt → no precision loss vs the i32 default)
  // or a float (FreeFloat → ditto vs f64 default). Otherwise the literal
  // would default to its base width before the cast op picked it up, and
  // hex literals past INT32_MAX (e.g. `usize(0xFFFFFFFFFFFFFFFF)`) lost
  // their high bits at the `i32.const` step.
  const hint = (isInteger(target) || isPrimitive(target, "char")
                || isPrimitive(target, "f32") || isPrimitive(target, "f64"))
    ? target : null;
  const argType = checkExpr(arg, hint, t, impls, diags, fn);
  const targetOk = isNumeric(target) || isPrimitive(target, "char");
  if (!targetOk) {
    // Non-numeric target : route through `Into(target)`. `Target(value)`
    // for a user struct/enum lowers to the matching `into` member call.
    if (tryInto(argType, target, arg, t, impls)) return target;
    err(diags, "T3010", expr.callee.span,
      `cast target must be a primitive numeric type, char, or have an \`Into(${displayType(target)})\` impl, got ${displayType(target)}`);
    return target;
  }
  // Enum source : `targetOk` already gated `target` to numeric/char, and
  // the enum's wire value is its declared repr — let it ride the regular
  // repr → target cast op. Mirrors Rust `as` / Zig `@intFromEnum`.
  if (argType.kind === "Enum") return target;
  const sourceOk = isNumeric(argType)
    || isPrimitive(argType, "char")
    || argType.kind === "Unresolved"
    || argType.kind === "FreeInt"
    || argType.kind === "FreeFloat";
  if (!sourceOk) {
    // Non-numeric source with a numeric/char target : try `Into(target)`.
    // The explicit form (`i32(my_user_id)`) shares the implicit Into path
    // — same impl, same routing.
    if (tryInto(argType, target, arg, t, impls)) return target;
    err(diags, "T3010", arg.span,
      `cast source must be numeric, char, or have an \`Into(${displayType(target)})\` impl, got ${displayType(argType)}`);
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

/** Resolve `Type(...)`-shaped callee to its target type, or null when the
 *  ident doesn't actually name a type. Exported so the call dispatcher can
 *  pre-route to `inferTypeConstructorCall` before the fn-callee fall-through. */
export function identTargetType(callee: A.Expr, t: MutableTyped): Type | null {
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
