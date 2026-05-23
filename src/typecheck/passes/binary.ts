// Binary operator type-checking. Dispatches by operator kind to the matching
// rule (numeric / integer-bitwise / equality / comparison / boolean-logic /
// `is`) and emits T3017 when the operands aren't compatible.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";

import { err, warn } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { BinaryOpResolution } from "../typed-ast.ts";
import type { Type } from "../types.ts";
import {
  CORE_TRAITS, TY, defaultIfFree, displayType, equalsType, intersects, isAssignable, isFloat,
  isInteger, isNumeric, isPrimitive,
} from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkExpr } from "./expr.ts";
import { findGlobalTrait } from "./traits.ts";
import { lowerExprAsType } from "./type-expr.ts";

export function inferBinary(
  expr: A.BinaryExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const left = checkExpr(expr.left, null, t, impls, diags, fn);
  // `is` is special : the RHS is parsed as a value expression but
  // interpreted as a type. Route through `lowerExprAsType` so primitive
  // names (`i32`, `string`) resolve to their actual primitive type
  // instead of `TypeMeta`, and record the resolved type for the lowerer
  // and the narrowing detector.
  if (expr.op === "is") {
    const checkType = lowerExprAsType(expr.right, t, diags);
    t.binaryIsCheckTypes.set(expr, checkType);
    // Mirror to exprTypes for legacy consumers ; new code reads from
    // `binaryIsCheckTypes`.
    t.exprTypes.set(expr.right, checkType);
    // `is` checks the concrete runtime struct-tag, not a "union tag" — so
    // `x is Union(A, B, ...)` always returns false at runtime. (Match arms
    // are checked separately in `match.ts`.)
    if (checkType.kind === "Union") {
      warn(diags, "W0003", expr.right.span,
        `match against each variant of \`${displayType(checkType)}\` instead`);
    }
    // Soundness check : `x is T` where T can never be a runtime value of
    // x's static type is dead code — e.g. `if p is null` when `p: Pet`
    // and Pet doesn't include null. Suppress for trivial `is Error` on a
    // generic `?`-shaped union (the typer's free / unresolved arms have
    // already been flagged elsewhere).
    if (!intersects(checkType, left, impls)) {
      err(diags, "T3040", expr.right.span,
        `\`${displayType(checkType)}\` is never a value of \`${displayType(left)}\``);
    }
    return TY.bool;
  }
  // For arithmetic / comparison / equality, pass left's concrete type as expected
  // context so free numeric literals on the right adopt it (e.g. `self.size + 1`
  // → `1: usize`, `if u64_var == 0` → `0: u64`).
  const propagatesLeft = expr.op === "add" || expr.op === "sub" || expr.op === "mul"
                      || expr.op === "div" || expr.op === "mod"
                      || expr.op === "lt"  || expr.op === "lte"
                      || expr.op === "gt"  || expr.op === "gte"
                      || expr.op === "eq"  || expr.op === "neq";
  const rightCtx = propagatesLeft && isNumeric(left) ? left
                 : (expr.op === "eq" || expr.op === "neq") && expr.right.kind === "DotVariantExpr" ? left
                 : null;
  const right = checkExpr(expr.right, rightCtx, t, impls, diags, fn);
  switch (expr.op) {
    case "add": case "sub": case "mul": case "div": case "mod":
      return binaryArith(expr, left, right, t, impls, diags);
    case "bitor": case "bitand":
      // Layer 4-sugar : `T | U` and `T & U` on type-meta operands produce
      // the union / intersection type as a value of type `type`. The actual
      // Type-domain construction (Union / intersection) happens when the
      // const-decl recogniser promotes the host expression to a type alias.
      if (left.kind === "TypeMeta" && right.kind === "TypeMeta") return TY.type;
      return binaryInteger(expr, left, right, diags);
    case "shl": case "shr": case "bitxor":
      return binaryInteger(expr, left, right, diags);
    case "eq": case "neq":
      return binaryEquality(expr, left, right, t, impls, diags);
    case "lt": case "lte": case "gt": case "gte":
      return binaryComparison(expr, left, right, t, impls, diags);
    case "and": case "or":
      if (!isPrimitive(left, "bool") && left.kind !== "Unresolved") err(diags, "T3017", expr.left.span);
      if (!isPrimitive(right, "bool") && right.kind !== "Unresolved") err(diags, "T3017", expr.right.span);
      return TY.bool;
    case "in": case "not_in":
      // `x in coll` / `x !in coll`: collection-side must implement Contains($T)
      // where $T accepts the element's type. Returns bool. Validation happens
      // in the lowerer when the call gets resolved against the impl registry —
      // here we just report the result type.
      return TY.bool;
  }
}

function binaryArith(
  expr: A.BinaryExpr, left: Type, right: Type,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector,
): Type {
  // `string + string` is a dedicated bytecode op, not a fn call (see
  // `OP_INTRINSIC_BY_MANGLED` in bytecode/emit.ts) ; numerics use the
  // matching primitive op. Anything else falls through to trait dispatch.
  if (expr.op === "add" && isPrimitive(left, "string") && isPrimitive(right, "string")) return TY.string;
  if (canBuiltinNumeric(left) && canBuiltinNumeric(right)) {
    return numericResult(expr, left, right, diags);
  }
  const dispatch = ARITH_DISPATCH[expr.op as ArithOp];
  if (dispatch !== undefined) {
    const resolved = resolveBinaryDirect(expr, left, right, dispatch, t, impls, diags);
    if (resolved !== null) return resolved;
  }
  return numericResult(expr, left, right, diags);
}

type ArithOp = "add" | "sub" | "mul" | "div" | "mod";

const ARITH_DISPATCH: Record<ArithOp, { trait: string; method: string }> = {
  add: { trait: CORE_TRAITS.Add, method: "add" },
  sub: { trait: CORE_TRAITS.Sub, method: "sub" },
  mul: { trait: CORE_TRAITS.Mul, method: "mul" },
  div: { trait: CORE_TRAITS.Div, method: "div" },
  mod: { trait: CORE_TRAITS.Rem, method: "rem" },
};

function canBuiltinNumeric(t: Type): boolean {
  return isNumeric(t) || t.kind === "FreeInt" || t.kind === "FreeFloat" || t.kind === "Unresolved";
}

function resolveBinaryDirect(
  expr: A.BinaryExpr, left: Type, right: Type,
  dispatch: { trait: string; method: string },
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector,
): Type | null {
  if (left.kind === "Unresolved") return TY.unresolved;
  const found = findTraitOpMember(t, impls, left, dispatch.trait, dispatch.method);
  if (found === null) return null;
  if (!isAssignable(right, left, impls)) {
    err(diags, "T3017", expr.span,
      `${expr.op} on ${displayType(left)} expects right operand assignable to ${displayType(left)}, got ${displayType(right)}`);
    return left;
  }
  t.binaryOpResolutions.set(expr, { kind: "direct", ...found, receiverType: left });
  return left;     // method returns `Self`
}

/** Look up an impl of `traitName` on `forType` and return the member fn
 *  matching `methodName`. The trait/member pair is the common shape consumed
 *  by every operator-overload resolution (`Add`, `Equals`, `Comparable`, …). */
function findTraitOpMember(
  t: MutableTyped, impls: ImplRegistry, forType: Type,
  traitName: string, methodName: string,
): { trait: Symbol; member: A.FnDecl } | null {
  const trait = findGlobalTrait(t, traitName);
  if (trait === null) return null;
  const entry = impls.findFor(forType, trait);
  if (entry === null) return null;
  const member = entry.decl.members.find((m) => m.name === methodName);
  if (member === undefined) return null;
  return { trait, member };
}

function binaryInteger(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.unresolved;
  if ((isInteger(left) || left.kind === "FreeInt") && (isInteger(right) || right.kind === "FreeInt")) {
    return left.kind === "FreeInt" ? right : left;
  }
  err(diags, "T3017", expr.span, `bitwise op on ${displayType(left)} / ${displayType(right)}`);
  return TY.unresolved;
}

function binaryEquality(
  expr: A.BinaryExpr, left: Type, right: Type,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector,
): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.bool;
  // Statically-unreachable comparison : when the operands' types can't
  // overlap at runtime, the test is always false (or always true for
  // `!=`). Mirrors the `is T` reachability check in `inferBinary` —
  // surfaces `n: i32 == null` and similar with a clear T3040 instead of
  // a misleading "no Eq impl" T3017. Free numeric literals are deferred
  // since their final type is set by the bidirectional infer.
  if (left.kind !== "FreeInt" && left.kind !== "FreeFloat"
      && right.kind !== "FreeInt" && right.kind !== "FreeFloat"
      && !intersects(left, right, impls)) {
    err(diags, "T3040", expr.span,
      `\`${displayType(left)}\` and \`${displayType(right)}\` have no overlapping values`);
    return TY.bool;
  }
  // Union ↔ variant: `(T | U) == T` / `(T | null) != null` etc. Accepted as
  // long as one side is a union and the other is structurally one of its
  // variants. Lets flow narrowing on null-checks (and discriminated-union
  // equality) type-check without spurious T3017s.
  if (left.kind === "Union" && left.variants.some((v) => equalsType(v, right))) return TY.bool;
  if (right.kind === "Union" && right.variants.some((v) => equalsType(v, left))) return TY.bool;
  if (equalsType(defaultIfFree(left), defaultIfFree(right))) {
    // Same-type equality. Primitives + strings get the built-in path ;
    // user structs with an `Equals` impl route through trait dispatch ;
    // without an impl they fall back to reference identity (SPEC §4 memory
    // model).
    if (left.kind === "Struct") {
      const found = findTraitOpMember(t, impls, left, CORE_TRAITS.Equals, "equals");
      if (found !== null) {
        t.binaryOpResolutions.set(expr, {
          kind: "eq", negate: expr.op === "neq", ...found, receiverType: left,
        });
      }
    }
    return TY.bool;
  }
  if (left.kind === "FreeInt" && isNumeric(right)) return TY.bool;
  if (right.kind === "FreeInt" && isNumeric(left)) return TY.bool;
  if (left.kind === "FreeFloat" && isFloat(right)) return TY.bool;
  if (right.kind === "FreeFloat" && isFloat(left)) return TY.bool;
  err(diags, "T3017", expr.span,
    `${expr.op} between ${displayType(left)} and ${displayType(right)}`);
  return TY.bool;
}

function binaryComparison(
  expr: A.BinaryExpr, left: Type, right: Type,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector,
): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.bool;
  const okPair =
    (isNumeric(left) || left.kind === "FreeInt" || left.kind === "FreeFloat") &&
    (isNumeric(right) || right.kind === "FreeInt" || right.kind === "FreeFloat");
  if (okPair) return TY.bool;
  if (isPrimitive(left, "string") && isPrimitive(right, "string")) return TY.bool;
  if (isPrimitive(left, "char") && isPrimitive(right, "char")) return TY.bool;
  // User-type fallback via `Comparable::compare` — lowerer rewrites to
  // `compare(a, b) <op> 0`.
  if (left.kind === "Struct" && equalsType(defaultIfFree(left), defaultIfFree(right))) {
    const found = findTraitOpMember(t, impls, left, CORE_TRAITS.Comparable, "compare");
    if (found !== null) {
      t.binaryOpResolutions.set(expr, {
        kind: "ord", cmp: expr.op as "lt" | "lte" | "gt" | "gte",
        ...found, receiverType: left,
      });
      return TY.bool;
    }
  }
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
