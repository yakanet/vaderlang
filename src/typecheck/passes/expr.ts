// Top-level expression checker. Dispatches by AST kind to the relevant
// inference rule and writes the result into `MutableTyped.exprTypes`. Simple
// inference rules (ident, string-lit, index, unary, if, lambda, array-lit,
// range, cast) live here; the larger ones (binary, call/field, match, struct
// literal, try) are exported from sibling pass modules.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Type } from "../types.ts";
import {
  CORE_STRUCTS, TY, defaultIfFree, displayType, isAssignable, isInteger, isNumeric, isPrimitive, unionOf,
} from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { inferBinary } from "./binary.ts";
import { inferCall, inferField } from "./call.ts";
import { inferMatch } from "./match.ts";
import { checkBlock } from "./stmt.ts";
import { inferStructLit } from "./struct-lit.ts";
import { inferTry } from "./try.ts";
import { lowerTypeExpr, primitiveFromName } from "./type-expr.ts";
import { implementsDisplay } from "./traits.ts";

export function checkExpr(
  expr: A.Expr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const got = inferExpr(expr, expected, t, impls, diags, fn);
  // If the caller wanted a specific type and we produced a free numeric, default
  // it now (so `let x: i64 = 5` works without a synthetic node).
  let final = got;
  if (expected !== null) {
    if (got.kind === "FreeInt" && isAssignable(TY.i32, expected)) final = expected;
    else if (got.kind === "FreeFloat" && isAssignable(TY.f64, expected)) final = expected;
  }
  t.exprTypes.set(expr, final);
  return final;
}

function inferExpr(
  expr: A.Expr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  switch (expr.kind) {
    case "IntLitExpr":
      return expr.suffix !== null ? primitiveFromName(expr.suffix) ?? TY.unresolved : TY.freeInt;
    case "FloatLitExpr":
      return expr.suffix !== null ? primitiveFromName(expr.suffix) ?? TY.unresolved : TY.freeFloat;
    case "BoolLitExpr":   return TY.bool;
    case "NullLitExpr":   return TY.null;
    case "CharLitExpr":   return TY.char;
    case "StringLitExpr": return inferStringLit(expr, t, impls, diags, fn);
    case "IdentExpr":     return inferIdent(expr, t);
    case "CallExpr":      return inferCall(expr, t, impls, diags, fn);
    case "FieldExpr":     return inferField(expr, t, impls, diags, fn);
    case "IndexExpr":     return inferIndex(expr, t, impls, diags, fn);
    case "UnaryExpr":     return inferUnary(expr, t, impls, diags, fn);
    case "BinaryExpr":    return inferBinary(expr, t, impls, diags, fn);
    case "IfExpr":        return inferIf(expr, expected, t, impls, diags, fn);
    case "MatchExpr":     return inferMatch(expr, expected, t, impls, diags, fn);
    case "BlockExpr":     return checkBlock(expr, expected, t, impls, diags, fn);
    case "LambdaExpr":    return inferLambda(expr, expected, t, impls, diags, fn);
    case "StructLitExpr": return inferStructLit(expr, t, impls, diags, fn);
    case "ArrayLitExpr":  return inferArrayLit(expr, expected, t, impls, diags, fn);
    case "RangeExpr":     return inferRange(expr, t, impls, diags, fn);
    case "TryExpr":       return inferTry(expr, t, impls, diags, fn);
    case "CastExpr":      return inferCast(expr, t, impls, diags, fn);
    case "GenericInstExpr": {
      checkExpr(expr.callee, null, t, impls, diags, fn);
      for (const a of expr.typeArgs) lowerTypeExpr(a, t, diags);
      return TY.unresolved;
    }
  }
}

function inferStringLit(
  expr: A.StringLitExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  for (const part of expr.parts) {
    if (part.kind !== "interp") continue;
    const inner = checkExpr(part.expr, null, t, impls, diags, fn);
    if (!implementsDisplay(inner, t, impls)) {
      err(diags, "T3018", part.expr.span, displayType(inner));
    }
  }
  return TY.string;
}

function inferIdent(expr: A.IdentExpr, t: MutableTyped): Type {
  const sym = t.resolved.idents.get(expr);
  if (sym === undefined) return TY.unresolved;
  return typeOfSymbol(sym, t);
}

export function typeOfSymbol(sym: Symbol, t: MutableTyped): Type {
  const narrow = t.narrowed.get(sym.id);
  if (narrow !== undefined) return narrow;
  switch (sym.kind) {
    case "fn":
    case "const":
    case "type-alias":
    case "struct":
    case "trait": {
      const decl = declOf(sym);
      return decl !== null ? t.globals.declTypes.get(decl) ?? TY.unresolved : TY.unresolved;
    }
    case "param":
      return sym.source.kind === "param"
        ? t.globals.paramTypes.get(sym.source.param) ?? TY.unresolved
        : TY.unresolved;
    case "local":
      return sym.source.kind === "local"
        ? t.localTypes.get(sym.source.stmt) ?? TY.unresolved
        : TY.unresolved;
    case "type-param":
      return { kind: "TypeParam", symbol: sym };
    case "builtin-type":
      return primitiveFromName(sym.name) ?? TY.unresolved;
    case "import-binding":
      // Resolver redirects most uses through `resolveImportRedirect` to the
      // concrete export; if we still see the binding here it's the namespace
      // form (`import "std/io"` → `io.println()`) — typing it requires the
      // module-as-value notion that we don't model in MVP. Leave Unresolved,
      // and tolerate it in field-resolution callers.
      return TY.unresolved;
    case "binding":
    case "builtin-fn":
      // Pattern bindings, for-in vars: type narrows from context (not yet tracked).
      // builtin-fn: reserved for future intrinsics.
      return TY.unresolved;
  }
}

function inferIndex(
  expr: A.IndexExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const target = checkExpr(expr.target, null, t, impls, diags, fn);
  checkExpr(expr.index, null, t, impls, diags, fn);
  if (target.kind === "Array") return target.element;
  if (target.kind !== "Unresolved") err(diags, "T3008", expr.target.span, displayType(target));
  return TY.unresolved;
}

function inferUnary(
  expr: A.UnaryExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const operand = checkExpr(expr.operand, null, t, impls, diags, fn);
  switch (expr.op) {
    case "neg":
      if (operand.kind === "FreeInt" || operand.kind === "FreeFloat") return operand;
      if (isNumeric(operand) || operand.kind === "Unresolved") return operand;
      err(diags, "T3017", expr.span, `unary - on ${displayType(operand)}`);
      return TY.unresolved;
    case "not":
      if (isPrimitive(operand, "bool") || operand.kind === "Unresolved") return TY.bool;
      err(diags, "T3017", expr.span, `! on ${displayType(operand)}`);
      return TY.unresolved;
    case "bitnot":
      if (isInteger(operand) || operand.kind === "FreeInt" || operand.kind === "Unresolved") return operand;
      err(diags, "T3017", expr.span, `~ on ${displayType(operand)}`);
      return TY.unresolved;
  }
}

function inferIf(
  expr: A.IfExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const cond = checkExpr(expr.cond, TY.bool, t, impls, diags, fn);
  if (!isAssignable(cond, TY.bool)) err(diags, "T3019", expr.cond.span);
  const thenT = checkBlock(expr.then, expected, t, impls, diags, fn);
  if (expr.else === null) return thenT.kind === "Never" ? TY.void : unionOf([thenT, TY.void]);
  const elseT = expr.else.kind === "IfExpr"
    ? checkExpr(expr.else, expected, t, impls, diags, fn)
    : checkBlock(expr.else, expected, t, impls, diags, fn);
  return unionOf([thenT, elseT]);
}

function inferLambda(
  expr: A.LambdaExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const expectedFn = expected?.kind === "Fn" ? expected : null;
  const paramTypes: Type[] = [];
  for (let i = 0; i < expr.params.length; i++) {
    const p = expr.params[i]!;
    let pt: Type;
    if (p.type !== null) {
      pt = lowerTypeExpr(p.type, t, diags);
    } else if (expectedFn !== null && i < expectedFn.params.length) {
      pt = expectedFn.params[i]!;
    } else {
      err(diags, "T3024", p.span, `lambda parameter \`${p.name}\` cannot be inferred`);
      pt = TY.unresolved;
    }
    paramTypes.push(pt);
    t.globals.paramTypes.set(p, pt);
  }
  const expectedRet = expr.returnType !== null
    ? lowerTypeExpr(expr.returnType, t, diags)
    : expectedFn?.returnType ?? null;
  const innerFn: FnContext = { returnType: expectedRet ?? TY.unresolved, selfType: fn?.selfType ?? null, loopDepth: 0 };
  const bodyType = checkBlock(expr.body, expectedRet, t, impls, diags, innerFn);
  return { kind: "Fn", params: paramTypes, returnType: expectedRet ?? bodyType };
}

function inferArrayLit(
  expr: A.ArrayLitExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const elemExpected = expected?.kind === "Array" ? expected.element : null;
  const elemTypes: Type[] = expr.elements.map((e) => checkExpr(e, elemExpected, t, impls, diags, fn));
  if (elemTypes.length === 0) return { kind: "Array", element: elemExpected ?? TY.unresolved };
  return { kind: "Array", element: unionOf(elemTypes.map(defaultIfFree)) };
}

function inferRange(
  expr: A.RangeExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  checkExpr(expr.lower, TY.i32, t, impls, diags, fn);
  checkExpr(expr.upper, TY.i32, t, impls, diags, fn);
  const rangeSym = t.globals.coreSymbols?.get(CORE_STRUCTS.Range);
  if (rangeSym === undefined || rangeSym.kind !== "struct") return TY.unresolved;
  return { kind: "Struct", symbol: rangeSym, args: [] };
}

function inferCast(
  expr: A.CastExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Parser doesn't currently emit CastExpr (Type(value) → CallExpr); branch unused.
  const target = lowerTypeExpr(expr.target, t, diags);
  checkExpr(expr.value, null, t, impls, diags, fn);
  return target;
}
