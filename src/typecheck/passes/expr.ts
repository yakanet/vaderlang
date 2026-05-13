// Top-level expression checker. Dispatches by AST kind to the relevant
// inference rule and writes the result into `MutableTyped.exprTypes`. Simple
// inference rules (ident, string-lit, index, unary, if, lambda, array-lit,
// range, cast) live here; the larger ones (binary, call/field, match, struct
// literal, try) are exported from sibling pass modules.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import { staticStringValue, unreachableTypeExprInValuePosition } from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf } from "../../resolver/symbol.ts";

import { err, warn } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { EnumType, Type } from "../types.ts";
import {
  ALL_INTS, CORE_STRUCTS, CORE_TRAITS, TY, defaultIfFree, displayType, isAssignable, isFloat, isInteger, isNumeric, isPrimitive, substitute, unionOf,
} from "../types.ts";
import { buildStructSubst } from "../ctx.ts";
import type { ImplEntry } from "../impls.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { inferBinary } from "./binary.ts";
import { inferCall, inferField } from "./call.ts";
import { checkEnumVariant } from "./enum.ts";
import { inferMatch } from "./match.ts";
import { detectVariantNarrowing, popNarrowing, pushNarrowing } from "./narrow.ts";
import { checkBlock } from "./stmt.ts";
import { inferStructLit } from "./struct-lit.ts";
import { inferTry } from "./try.ts";
import { lowerExprAsType, primitiveFromName } from "./type-expr.ts";
import { intrinsicSpec, type IntrinsicResultKind } from "../../parser/intrinsics.ts";
import { findGlobalTrait, implementsDisplay } from "./traits.ts";
import type {IndexResolution} from "../typed-ast.ts";

export function checkExpr(
  expr: A.Expr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const got = inferExpr(expr, expected, t, impls, diags, fn);
  // If the caller wanted a specific type and we produced a free numeric, default
  // it now (so `let x: i64 = 5` works without a synthetic node).
  let final = got;
  if (expected !== null) {
    if (got.kind === "FreeInt" && (isInteger(expected) || isAssignable(TY.i32, expected, impls))) final = expected;
    else if (got.kind === "FreeFloat" && (isFloat(expected) || isAssignable(TY.f64, expected, impls))) final = expected;
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
    case "IdentExpr":     return inferIdent(expr, t, diags);
    case "CallExpr":      return inferCall(expr, t, impls, diags, fn);
    case "FieldExpr":     return inferField(expr, t, impls, diags, fn);
    case "IndexExpr":     return inferIndex(expr, t, impls, diags, fn);
    case "UnaryExpr":     return inferUnary(expr, expected, t, impls, diags, fn);
    case "BinaryExpr":    return inferBinary(expr, t, impls, diags, fn);
    case "IfExpr":        return inferIf(expr, expected, t, impls, diags, fn);
    case "MatchExpr":     return inferMatch(expr, expected, t, impls, diags, fn);
    case "BlockExpr":     return checkBlock(expr, expected, t, impls, diags, fn);
    case "LambdaExpr":    return inferLambda(expr, expected, t, impls, diags, fn);
    case "StructLitExpr": return inferStructLit(expr, t, impls, diags, fn);
    case "SeqLitExpr":    return inferSeqLit(expr, expected, t, impls, diags, fn);
    case "RangeExpr":     return inferRange(expr, t, impls, diags, fn);
    case "TryExpr":       return inferTry(expr, t, impls, diags, fn);
    case "CastExpr":      return inferCast(expr, t, impls, diags, fn);
    case "DotVariantExpr": return inferDotVariant(expr, expected, t, diags);
    case "IntrinsicCallExpr": return inferIntrinsic(expr, t, impls, diags, fn);
    case "GenericInstExpr": {
      const innerType = checkExpr(expr.callee, null, t, impls, diags, fn);
      for (const a of expr.typeArgs) lowerExprAsType(a, t, diags);
      if (innerType.kind !== "Fn") return TY.unresolved;
      // Specialize the fn type by substituting typeParams with the resolved args
      // so inferCall can type-check the arguments and return type correctly.
      const innerSym = expr.callee.kind === "IdentExpr" ? t.resolved.idents.get(expr.callee) : undefined;
      if (innerSym === undefined) return TY.unresolved;
      const fnDecl = declOf(innerSym);
      if (fnDecl === null || fnDecl.kind !== "FnDecl" || fnDecl.typeParams.length === 0) return innerType;
      const typeParamMap = new Map<number, Type>();
      for (let i = 0; i < fnDecl.typeParams.length; i++) {
        const tpSym = t.globals.typeParamSymbols.get(fnDecl.typeParams[i]!);
        const concreteArg = t.globals.typeExprTypes.get(expr.typeArgs[i]!);
        if (tpSym !== undefined && concreteArg !== undefined) typeParamMap.set(tpSym.id, concreteArg);
      }
      return substitute(innerType, { typeParams: typeParamMap });
    }
    case "FnTypeExpr":
    case "ArrayTypeExpr":
      // `fn(T) -> R` and `T[]` are type-shaped expressions ; in value
      // position they still carry the metatype as their static type.
      // The Layer 5b in-fn alias path (`t :: i32[]`) and the implicit
      // alias path (`Foo :: i32[]`) downstream pick them up via
      // `looksLikeTypeExpression`.
      return TY.type;
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

function inferIdent(expr: A.IdentExpr, t: MutableTyped, diags: DiagnosticCollector): Type {
  const sym = t.resolved.idents.get(expr);
  if (sym === undefined) return TY.unresolved;
  checkDeprecated(expr, sym, diags);
  return typeOfSymbol(sym, t);
}

/** Type-check a reflection / introspection call (`@size_of(T)`, etc.).
 *  Validates argument arity, walks each arg through `lowerExprAsType`
 *  (type-shape args) or `checkExpr` (value-shape args) per its
 *  `IntrinsicSpec`, runs intrinsic-specific validations (e.g. the
 *  string-literal-only second arg of `@field_index`), and returns the
 *  intrinsic's static result type. */
function inferIntrinsic(
  expr: A.IntrinsicCallExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const spec = intrinsicSpec(expr.name);
  if (spec === null) {
    // Parser only emits IntrinsicCallExpr for known names ; reaching here
    // means the registry and parser drifted. Surface an internal-bug-style
    // diag rather than a confusing typecheck mismatch.
    err(diags, "T3002", expr.span, `unknown intrinsic \`@${expr.name}\``);
    return TY.unresolved;
  }
  if (expr.args.length !== spec.args.length) {
    err(diags, "T3003", expr.span,
      `\`@${expr.name}\` expects ${spec.args.length} arg(s), got ${expr.args.length}`);
    return intrinsicResultType(spec.result);
  }
  for (let i = 0; i < expr.args.length; i++) {
    const arg = expr.args[i]!;
    const kind = spec.args[i]!;
    if (kind === "type") {
      lowerExprAsType(arg, t, diags);
    } else {
      checkExpr(arg, null, t, impls, diags, fn);
    }
  }
  // Per-intrinsic validation : `@field_index(T, name)` requires `name` to
  // be a static string literal AND a member of the struct `T`.
  if (spec.name === "field_index") {
    validateFieldIndex(expr, t, diags);
  }
  // `@file("path")` requires the arg to be a string at typecheck — the
  // comptime stage decides whether it's actually comptime-evaluable
  // (literal, const ident, concat of either, …). Anything dynamic
  // surfaces C4002 then.
  if (spec.name === "file") {
    const arg = expr.args[0];
    const argTy = arg !== undefined ? t.exprTypes.get(arg) : undefined;
    if (argTy !== undefined && !isAssignable(argTy, TY.string)) {
      err(diags, "T3001", arg!.span,
        `\`@file(...)\` expects \`string\`, got ${displayType(argTy)}`);
    }
  }
  return intrinsicResultType(spec.result);
}

function intrinsicResultType(result: IntrinsicResultKind): Type {
  switch (result) {
    case "usize":  return { kind: "Primitive", name: "usize" };
    case "string": return TY.string;
    case "bool":   return TY.bool;
  }
}

function validateFieldIndex(
  expr: A.IntrinsicCallExpr, t: MutableTyped, diags: DiagnosticCollector,
): void {
  const nameArg = expr.args[1];
  const fieldName = nameArg !== undefined && nameArg.kind === "StringLitExpr"
    ? staticStringValue(nameArg) : null;
  if (fieldName === null) {
    err(diags, "T3002", nameArg?.span ?? expr.span,
      "`@field_index` second argument must be a static string literal");
    return;
  }
  const targetTy = t.globals.typeExprTypes.get(expr.args[0]!);
  if (targetTy === undefined || targetTy.kind !== "Struct") {
    err(diags, "T3002", expr.args[0]!.span,
      `\`@field_index\` first argument must be a struct type, got ${targetTy !== undefined ? displayType(targetTy) : "?"}`);
    return;
  }
  const decl = targetTy.symbol.source.kind === "struct" ? targetTy.symbol.source.decl : null;
  if (decl === null) return;
  const idx = decl.fields.findIndex((f) => f.name === fieldName);
  if (idx < 0) {
    err(diags, "T3009", nameArg!.span,
      `field \`${fieldName}\` does not exist on ${displayType(targetTy)}`);
  }
}


/** Walk the resolved decl's decorators ; emit W0001 if `@deprecated(...)` is
 *  present. The decorator's first argument is taken as the human-readable
 *  reason ; it must be a static string literal — interpolation or other
 *  expressions silently produce a generic warning. The collector dedupes by
 *  (code, span, message), so a single deprecated reference emits one diag
 *  even if it's revisited (e.g. through generic instantiation). */
function checkDeprecated(expr: A.IdentExpr, sym: Symbol, diags: DiagnosticCollector): void {
  const decl = declOf(sym);
  if (decl === null) return;
  const dec = decl.decorators.find((d) => d.name === "deprecated");
  if (dec === undefined) return;
  let reason = "";
  const first = dec.args[0];
  if (first !== undefined && first.kind === "StringLitExpr") {
    reason = staticStringValue(first) ?? "";
  }
  const detail = reason !== "" ? `\`${expr.name}\`: ${reason}` : `\`${expr.name}\``;
  warn(diags, "W0001", expr.span, detail);
}

export function typeOfSymbol(sym: Symbol, t: MutableTyped): Type {
  const narrow = t.narrowed.get(sym.id);
  if (narrow !== undefined) return narrow;
  switch (sym.kind) {
    case "fn":
    case "const":
    case "type-alias":
    case "struct":
    case "enum":
    case "trait": {
      const decl = declOf(sym);
      return decl !== null ? t.globals.declTypes.get(decl) ?? TY.unresolved : TY.unresolved;
    }
    case "param":
      return sym.source.kind === "param"
        ? t.globals.paramTypes.get(sym.source.param) ?? TY.unresolved
        : TY.unresolved;
    case "local":
      // Layer 5b — let-stmt locals tagged as in-fn type aliases
      // (`t :: <type-expr>`) statically have type `type`. The underlying
      // resolved type is served through `typeFromSymbol` for type-position
      // references ; here in value-position we just report the metatype.
      if (t.globals.letTypeAliases.has(sym)) return TY.type;
      return sym.source.kind === "local"
        ? t.localTypes.get(sym.source.binding) ?? TY.unresolved
        : TY.unresolved;
    case "type-param":
      return { kind: "TypeParam", symbol: sym };
    case "builtin-type":
      // Layer 4-sugar : a *bare* type-name reference in value position is a
      // value of static type `type` (the metatype). The actual primitive
      // shape is recovered when the typechecker descends into a type-demanding
      // slot via `lowerExprAsType` / `typeFromSymbol`. Treating the bare
      // reference as `type` lets `Foo :: i32 | i64` parse as a const decl
      // whose value is a union *type*, which the next phase recognises as
      // an implicit type alias.
      return TY.type;
    case "import-binding":
      // Resolver redirects most uses through `resolveImportRedirect` to the
      // concrete export; if we still see the binding here it's the namespace
      // form (`import "std/io"` → `io.println()`) — typing it requires the
      // module-as-value notion that we don't model in MVP. Leave Unresolved,
      // and tolerate it in field-resolution callers.
      return TY.unresolved;
    case "binding":
    case "builtin-fn":
    case "synthetic":
      return TY.unresolved;
  }
}

/** True when `t` is a `std/core.Range[*]` struct type. Used by `inferIndex`
 *  to route `arr[r]` to the slice path when `r` has range type. */
function isRangeType(ty: Type, t: MutableTyped): ty is Type & { kind: "Struct"; args: readonly Type[] } {
  if (ty.kind !== "Struct") return false;
  const rangeSym = t.globals.coreSymbols?.get(CORE_STRUCTS.Range);
  return rangeSym !== undefined && ty.symbol.id === rangeSym.id;
}

function inferIndex(
  expr: A.IndexExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const target = checkExpr(expr.target, null, t, impls, diags, fn);
  const indexTy = checkExpr(expr.index, null, t, impls, diags, fn);
  // Slice : `arr[r]` where `r : Range[<integer>]` returns a fresh `T[]`
  // with the elements in `[r.start, r.end)` (or `..=` for inclusive).
  // Detect on the index *type*, not on `RangeExpr` AST kind, so a value
  // of Range type held in a local works too (`s :: 0..<3 ; arr[s]`). Any
  // integer-bounded range is accepted ; the lowerer casts to `usize` at
  // the use site since array indexing is usize-typed at the runtime level.
  if (target.kind === "Array" && isRangeType(indexTy, t)) {
    const bound = indexTy.args[0];
    if (bound === undefined || !isInteger(defaultIfFree(bound))) {
      err(diags, "T3001", expr.index.span,
        `slice index must be a Range over an integer type, got ${displayType(indexTy)}`);
    }
    return target;
  }
  if (target.kind === "Array") return target.element;
  // Trait dispatch via `Index($I, $T)` when the target isn't a built-in array.
  // Both struct receivers and primitive receivers (e.g. `string implements
  // Index(i32, char)`) flow through the same path ; `resolveIndexTrait`
  // handles both shapes.
  if (target.kind === "Struct" || target.kind === "Primitive") {
    const result = resolveIndexTrait(expr, target, indexTy, CORE_TRAITS.Index, "at", "read", t, impls, diags);
    if (result !== null) {
      t.indexResolutions.set(expr, result.resolution);
      return result.elementType;
    }
  }
  if (target.kind !== "Unresolved") err(diags, "T3008", expr.target.span, displayType(target));
  return TY.unresolved;
}



/** Look up an `Index($I, $T)` or `IndexSet($I, $T)` impl on `target` and
 *  build the substitution that pins the trait's `I` and `T` parameters to
 *  the impl's declared trait args. Returns the resolution + the element
 *  type at the use site. Accepts struct receivers and primitive receivers
 *  (the `string implements Index(i32, char)` shape) ; for primitives there
 *  is no struct-typeParam substitution to apply. */
export function resolveIndexTrait(
  expr: A.Expr, target: Type, indexTy: Type,
  traitName: string, methodName: string, mode: "read" | "write",
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector,
): { resolution: IndexResolution; elementType: Type } | null {
  const trait = findGlobalTrait(t, traitName);
  if (trait === null) return null;
  const entry: ImplEntry | null = impls.findFor(target, trait);
  if (entry === null) return null;
  const member = entry.decl.members.find((m) => m.name === methodName);
  if (member === undefined) return null;
  // Element type comes from the impl's trait args (`Index(K, V)` → at returns V).
  const traitArgs: Type[] = entry.decl.traitArgs.map(
    (ta) => t.globals.typeExprTypes.get(ta) ?? TY.unresolved,
  );
  if (traitArgs.length < 2) return null;
  // Substitute the struct's typeParams using the receiver's concrete args so
  // generic containers resolve correctly (e.g. `Cell(T)::at` indexed by string).
  // Primitives carry no typeParams ; the substitution is identity.
  const subst = target.kind === "Struct" && target.symbol.source.kind === "struct"
    ? buildStructSubst(target.symbol.source.decl.typeParams, target.args, t.globals.typeParamSymbols)
    : { typeParams: new Map() };
  const expectedIndex = substitute(traitArgs[0]!, subst);
  const elementType  = substitute(traitArgs[1]!, subst);
  if (!isAssignable(indexTy, expectedIndex, impls)) {
    err(diags, "T3017", expr.span,
      `${traitName} on ${displayType(target)} expects index ${displayType(expectedIndex)}, got ${displayType(indexTy)}`);
  }
  return {
    resolution: { mode, trait, member, receiverType: target },
    elementType,
  };
}

function inferUnary(
  expr: A.UnaryExpr, expected: Type | null, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // `neg` / `bitnot` preserve the operand type, so an integer `expected`
  // forwarded down repins a FreeInt operand to that width (`g: i64 = -50`
  // → the `50` must lower as `i64.const`, not `i32.const`).
  const operandCtx = (expr.op === "neg" && expected !== null && (isNumeric(expected) || expected.kind === "Unresolved")) ? expected
                   : (expr.op === "bitnot" && expected !== null && (isInteger(expected) || expected.kind === "Unresolved")) ? expected
                   : null;
  const operand = checkExpr(expr.operand, operandCtx, t, impls, diags, fn);
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

  const split = detectVariantNarrowing(expr.cond, t);

  let prevThen: Type | undefined;
  if (split !== null) prevThen = pushNarrowing(t, split.symId, split.thenType);
  const thenT = checkBlock(expr.then, expected, t, impls, diags, fn);
  if (split !== null) popNarrowing(t, split.symId, prevThen);

  if (expr.else === null) return thenT.kind === "Never" ? TY.void : unionOf([thenT, TY.void]);

  // If one branch types concrete numeric and the other is FreeInt/FreeFloat,
  // hint the else with the then's type so trailing literals adopt it (and
  // vice-versa after both branches, via the trailing repin below).
  const elseExpected = expected ?? (isNumeric(thenT) ? thenT : null);

  let prevElse: Type | undefined;
  if (split !== null) prevElse = pushNarrowing(t, split.symId, split.elseType);
  const elseT = expr.else.kind === "IfExpr"
    ? checkExpr(expr.else, elseExpected, t, impls, diags, fn)
    : checkBlock(expr.else, elseExpected, t, impls, diags, fn);
  if (split !== null) popNarrowing(t, split.symId, prevElse);

  if (expected === null && (thenT.kind === "FreeInt" || thenT.kind === "FreeFloat") && isNumeric(elseT)) {
    const trailing = expr.then.trailing;
    if (trailing !== null) {
      t.exprTypes.set(trailing, elseT);
      t.exprTypes.set(expr.then, elseT);
      return elseT;
    }
  }

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
      pt = lowerExprAsType(p.type, t, diags);
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
    ? lowerExprAsType(expr.returnType, t, diags)
    : expectedFn?.returnType ?? null;
  const innerFn: FnContext = { returnType: expectedRet ?? TY.unresolved, selfType: fn?.selfType ?? null, loopDepth: 0 };
  const bodyType = checkBlock(expr.body, expectedRet, t, impls, diags, innerFn);
  return { kind: "Fn", params: paramTypes, returnType: expectedRet ?? bodyType };
}

function inferSeqLit(
  expr: A.SeqLitExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Contextual disambiguation between array and tuple :
  //   - expected is `Tuple([T0..Tn-1])`  → tuple, element-wise (arity must match)
  //   - expected is `Array(T)`           → array, all elements check against T
  //   - expected is a union              → pick a Tuple variant whose arity
  //                                        matches the literal, else an Array
  //                                        variant ; recurse with that
  //   - no useful expected type          → array-first when elements unify under
  //                                        unionOf to a single type, otherwise tuple
  if (expected?.kind === "Union") {
    const tupleVariant = expected.variants.find(
      (v) => v.kind === "Tuple" && v.elements.length === expr.elements.length);
    const arrayVariant = expected.variants.find((v) => v.kind === "Array");
    const picked = tupleVariant ?? arrayVariant ?? null;
    if (picked !== null) {
      return inferSeqLit(expr, picked, t, impls, diags, fn);
    }
    // No tuple/array variant in the union — fall through to default inference.
  }
  if (expected?.kind === "Tuple") {
    if (expected.elements.length !== expr.elements.length) {
      err(diags, "T3001", expr.span,
        `expected ${displayType(expected)} (${expected.elements.length} element(s)), got ${expr.elements.length}`);
      // Best-effort : check elements against their per-slot expected types
      // up to the shorter length so cascading errors are minimised.
      const n = Math.min(expected.elements.length, expr.elements.length);
      const elemTypes: Type[] = [];
      for (let i = 0; i < n; i++) {
        elemTypes.push(checkExpr(expr.elements[i]!, expected.elements[i]!, t, impls, diags, fn));
      }
      for (let i = n; i < expr.elements.length; i++) {
        elemTypes.push(checkExpr(expr.elements[i]!, null, t, impls, diags, fn));
      }
      return { kind: "Tuple", elements: elemTypes.map(defaultIfFree) };
    }
    const elemTypes = expr.elements.map((e, i) =>
      checkExpr(e, expected.elements[i]!, t, impls, diags, fn));
    return { kind: "Tuple", elements: elemTypes };
  }
  const elemExpected = expected?.kind === "Array" ? expected.element : null;
  const elemTypes: Type[] = expr.elements.map((e) => checkExpr(e, elemExpected, t, impls, diags, fn));
  if (elemTypes.length === 0) return { kind: "Array", element: elemExpected ?? TY.unresolved };
  // No explicit annotation : default to array when elements unify ; tuple
  // when they don't. `unionOf` returns a non-Union result iff all variants
  // are equal post-dedup (a single homogeneous type).
  if (expected === null || expected.kind === "Unresolved") {
    const widened = elemTypes.map(defaultIfFree);
    const merged = unionOf(widened);
    if (merged.kind !== "Union") return { kind: "Array", element: merged };
    return { kind: "Tuple", elements: widened };
  }
  return { kind: "Array", element: unionOf(elemTypes.map(defaultIfFree)) };
}

function inferRange(
  expr: A.RangeExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Range is generic over the bound type since std/core's `Range :: struct[T]`.
  // i32, char, and usize ship Iterator/Contains impls today. Other widths
  // (i64/u64/...) parse syntactically but emit T3001 since no impl backs
  // them yet.
  // Bound type is driven by the lower bound when concrete ; if lower is a
  // free literal we probe the upper to pick up a non-i32 width (e.g.
  // `0..<arr.len()` where arr.len() is usize).
  const lower = checkExpr(expr.lower, null, t, impls, diags, fn);
  let elementType: Type = pickRangeBound(lower) ?? TY.i32;
  let upper: Type;
  if (lower.kind === "FreeInt") {
    const upperProbe = checkExpr(expr.upper, null, t, impls, diags, fn);
    elementType = pickRangeBound(upperProbe) ?? TY.i32;
    upper = upperProbe.kind === "FreeInt" && elementType !== upperProbe
      ? (t.exprTypes.set(expr.upper, elementType), elementType)
      : upperProbe;
    if (isAssignable(lower, elementType, impls)) t.exprTypes.set(expr.lower, elementType);
  } else {
    upper = checkExpr(expr.upper, elementType, t, impls, diags, fn);
  }
  if (!isAssignable(lower, elementType, impls)) {
    err(diags, "T3001", expr.lower.span,
      `range bounds must be \`${displayType(elementType)}\`, got ${displayType(lower)}`);
  }
  if (!isAssignable(upper, elementType, impls)) {
    err(diags, "T3001", expr.upper.span,
      `range bounds must be \`${displayType(elementType)}\`, got ${displayType(upper)}`);
  }
  const rangeSym = t.globals.coreSymbols?.get(CORE_STRUCTS.Range);
  if (rangeSym === undefined || rangeSym.kind !== "struct") return TY.unresolved;
  return { kind: "Struct", symbol: rangeSym, args: [elementType] };
}

function pickRangeBound(t: Type): Type | null {
  // Any concrete integer width or `char` is a valid Range bound — std/core
  // ships a Contains+Iterator impl for each of `i8`/`i16`/`i32`/`i64`/`isize`/
  // `u8`/`u16`/`u32`/`u64`/`usize`/`char`. FreeInt operands fall through to
  // the i32 default chosen by the caller.
  if (t.kind !== "Primitive") return null;
  if (t.name === "char") return t;
  return (ALL_INTS as readonly string[]).includes(t.name) ? t : null;
}

function inferCast(
  expr: A.CastExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Parser doesn't currently emit CastExpr (Type(value) → CallExpr); branch unused.
  const target = lowerExprAsType(expr.target, t, diags);
  checkExpr(expr.value, null, t, impls, diags, fn);
  return target;
}

function inferDotVariant(
  expr: A.DotVariantExpr, expected: Type | null,
  t: MutableTyped, diags: DiagnosticCollector,
): Type {
  if (expected !== null) {
    if (expected.kind === "Enum") {
      checkEnumVariant(expected, expr.variant, expr.variantSpan, diags);
      return expected;
    }
    // Union expected (e.g. `Direction!` = `Direction | Error`) : pick the
    // unique enum variant carrying this name ; two matches → ambiguous.
    if (expected.kind === "Union") {
      const matches: EnumType[] = [];
      for (const v of expected.variants) {
        if (v.kind === "Enum" && v.indices.has(expr.variant)) matches.push(v);
      }
      if (matches.length === 1) {
        const enumTy = matches[0]!;
        checkEnumVariant(enumTy, expr.variant, expr.variantSpan, diags);
        return enumTy;
      }
      if (matches.length > 1) {
        err(diags, "T3028", expr.span,
          `\`.${expr.variant}\` is ambiguous : ${matches.map(displayType).join(" or ")}`);
        return TY.unresolved;
      }
    }
  }
  err(diags, "T3028", expr.span, `\`.${expr.variant}\``);
  return TY.unresolved;
}
