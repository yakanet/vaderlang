// Binary operator type-checking. Dispatches by operator kind to the matching
// rule (numeric / integer-bitwise / equality / comparison / boolean-logic /
// `is`) and emits T3017 when the operands aren't compatible.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Type } from "../types.ts";
import {
  TY, defaultIfFree, displayType, equalsType, isFloat,
  isInteger, isNumeric, isPrimitive,
} from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkExpr } from "./expr.ts";

export function inferBinary(
  expr: A.BinaryExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const left = checkExpr(expr.left, null, t, impls, diags, fn);
  // For arithmetic / comparison, pass left's concrete type as expected context so
  // free numeric literals on the right adopt it (e.g. `self.size + 1` → `1: usize`).
  // For eq/neq with `.Variant` shorthand, do the same so the variant resolves.
  const numericOp = expr.op === "add" || expr.op === "sub" || expr.op === "mul"
                 || expr.op === "div" || expr.op === "mod"
                 || expr.op === "lt"  || expr.op === "lte"
                 || expr.op === "gt"  || expr.op === "gte";
  const rightCtx = numericOp && isNumeric(left) ? left
                 : (expr.op === "eq" || expr.op === "neq") && expr.right.kind === "DotVariantExpr" ? left
                 : null;
  const right = checkExpr(expr.right, rightCtx, t, impls, diags, fn);
  switch (expr.op) {
    case "add": case "sub": case "mul": case "div": case "mod":
      return binaryNumeric(expr, left, right, diags);
    case "shl": case "shr": case "bitand": case "bitor": case "bitxor":
      return binaryInteger(expr, left, right, diags);
    case "eq": case "neq":
      return binaryEquality(expr, left, right, diags);
    case "lt": case "lte": case "gt": case "gte":
      return binaryComparison(expr, left, right, diags);
    case "and": case "or":
      if (!isPrimitive(left, "bool") && left.kind !== "Unresolved") err(diags, "T3017", expr.left.span);
      if (!isPrimitive(right, "bool") && right.kind !== "Unresolved") err(diags, "T3017", expr.right.span);
      return TY.bool;
    case "is":
      // `lhs is RHS`: lhs is a value, rhs would be a type ident; MVP accepts.
      return TY.bool;
  }
}

function binaryNumeric(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  // Special case: `string + string` is concatenation.
  if (expr.op === "add" && isPrimitive(left, "string") && isPrimitive(right, "string")) return TY.string;
  return numericResult(expr, left, right, diags);
}

function binaryInteger(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.unresolved;
  if ((isInteger(left) || left.kind === "FreeInt") && (isInteger(right) || right.kind === "FreeInt")) {
    return left.kind === "FreeInt" ? right : left;
  }
  err(diags, "T3017", expr.span, `bitwise op on ${displayType(left)} / ${displayType(right)}`);
  return TY.unresolved;
}

function binaryEquality(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.bool;
  if (equalsType(defaultIfFree(left), defaultIfFree(right))) return TY.bool;
  if (left.kind === "FreeInt" && isNumeric(right)) return TY.bool;
  if (right.kind === "FreeInt" && isNumeric(left)) return TY.bool;
  if (left.kind === "FreeFloat" && isFloat(right)) return TY.bool;
  if (right.kind === "FreeFloat" && isFloat(left)) return TY.bool;
  err(diags, "T3017", expr.span,
    `${expr.op} between ${displayType(left)} and ${displayType(right)}`);
  return TY.bool;
}

function binaryComparison(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.bool;
  const okPair =
    (isNumeric(left) || left.kind === "FreeInt" || left.kind === "FreeFloat") &&
    (isNumeric(right) || right.kind === "FreeInt" || right.kind === "FreeFloat");
  if (okPair) return TY.bool;
  if (isPrimitive(left, "string") && isPrimitive(right, "string")) return TY.bool;
  err(diags, "T3017", expr.span, `comparison ${displayType(left)} vs ${displayType(right)}`);
  return TY.bool;
}

function numericResult(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.unresolved;
  const lf = left.kind === "FreeInt" || left.kind === "FreeFloat";
  const rf = right.kind === "FreeInt" || right.kind === "FreeFloat";
  if (lf && rf) return left.kind === "FreeFloat" || right.kind === "FreeFloat" ? TY.freeFloat : TY.freeInt;
  if (lf && isNumeric(right)) return right;
  if (rf && isNumeric(left)) return left;
  if (isNumeric(left) && isNumeric(right) && equalsType(left, right)) return left;
  err(diags, "T3017", expr.span,
    `${expr.op} between ${displayType(left)} and ${displayType(right)}`);
  return TY.unresolved;
}
