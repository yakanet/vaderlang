// Lowers match expressions to a chain of `if (predicate) <arm>` over
// introduced pattern bindings. Handles type tests, struct destructuring, and
// binding scoping.

import type * as A from "../../parser/ast.ts";
import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { Type } from "../../typecheck/types.ts";
import { TY } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredBlock, LoweredExpr, LoweredIf, LoweredStmt } from "../lowered-ast.ts";

import { lowerExpr } from "./expr.ts";
import { freshSyntheticSymbol, loweredEnumVariant, lowerCellInit, wrapAsBlock } from "./helpers.ts";

export function lowerMatch(ctx: FnLowerCtx, expr: A.MatchExpr, exprType: Type): LoweredExpr {
  const scrutType = ctx.types.exprType(expr.scrutinee);
  const scrutSym = freshSyntheticSymbol(ctx, "scrut");

  const stmts: LoweredStmt[] = [{
    kind: "LoweredLet", span: expr.scrutinee.span, name: scrutSym.name, symbol: scrutSym,
    type: scrutType, value: lowerExpr(ctx, expr.scrutinee),
  }];

  // T3013 catches non-exhaustive scrutinees in the typechecker; this fallback
  // is defensive for cases where typecheck recovered past the error.
  let chain: LoweredBlock = wrapAsBlock(
    { kind: "LoweredUnreachable", span: expr.span, type: exprType,
      reason: "non-exhaustive match (T3013 should have caught this)" },
    expr.span);

  for (let i = expr.arms.length - 1; i >= 0; i--) {
    const arm = expr.arms[i]!;
    const armBlock = lowerArm(ctx, arm, scrutSym, scrutType);
    const predicate = armPredicate(ctx, arm, scrutSym, scrutType);
    if (predicate === null) {
      chain = armBlock;     // wildcard/binding pattern: always matches, drop predecessors
    } else {
      const ifNode: LoweredIf = {
        kind: "LoweredIf", span: arm.span, type: exprType,
        cond: predicate, then: armBlock, else: chain,
      };
      chain = wrapAsBlock(ifNode, arm.span);
    }
  }

  // Append the chain block's stmts so any bindings introduced by an
  // irrefutable arm (binding/wildcard/all-binding-tuple) reach the body.
  // Refutable arms wrap their stmts inside a LoweredBlock under the if's
  // `then`, so this only fires when the predicate-less chain hoisted the
  // arm block directly.
  for (const s of chain.stmts) stmts.push(s);
  return {
    kind: "LoweredBlock", span: expr.span, type: exprType,
    stmts, trailing: chain.trailing,
  };
}

function lowerArm(
  ctx: FnLowerCtx, arm: A.MatchArm, scrutSym: Symbol, scrutType: Type,
): LoweredBlock {
  const stmts: LoweredStmt[] = [];
  introducePatternBindings(ctx, arm.pattern, scrutSym, scrutType, stmts, arm.span);
  const bodyExpr = lowerExpr(ctx, arm.body);
  return { kind: "LoweredBlock", span: arm.span, type: bodyExpr.type, stmts, trailing: bodyExpr };
}

function armPredicate(
  ctx: FnLowerCtx, arm: A.MatchArm, scrutSym: Symbol, scrutType: Type,
): LoweredExpr | null {
  const span = arm.pattern.span;
  const ident: LoweredExpr =
    { kind: "LoweredIdent", span, type: scrutType, symbol: scrutSym };

  const core = patternPredicate(ctx, arm.pattern, ident, scrutType, span);

  if (arm.guard === null) return core;
  const guard = lowerExpr(ctx, arm.guard);
  if (core === null) return guard;
  return { kind: "LoweredBinary", span: arm.span, type: TY.bool, op: "and", left: core, right: guard };
}

/** Build the boolean predicate that decides whether `pattern` matches the
 *  value of `target` at runtime. Returns `null` when the predicate is
 *  trivially true (binding or wildcard). Recurses for tuple patterns. */
function patternPredicate(
  ctx: FnLowerCtx, pattern: A.Pattern, target: LoweredExpr, targetType: Type, span: Span,
): LoweredExpr | null {
  switch (pattern.kind) {
    case "WildcardPattern":
    case "BindingPattern":
      return null;
    case "IsPattern":
      return {
        kind: "LoweredTypeCheck", span, type: TY.bool,
        value: target,
        checkType: ctx.types.typeExprType(pattern.type),
      };
    case "StructPattern":
      return lowerStructPattern(ctx, pattern, target, span);
    case "EnumVariantPattern": {
      const variantLit = loweredEnumVariant(targetType, pattern.variant, span);
      return { kind: "LoweredBinary", span, type: TY.bool, op: "eq", left: target, right: variantLit };
    }
    case "TuplePattern": {
      // Tuple types are static — arity is guaranteed by typecheck. The
      // predicate is the AND of element-pattern predicates over `target._N`.
      let acc: LoweredExpr | null = null;
      for (let i = 0; i < pattern.elements.length; i++) {
        const elem = pattern.elements[i]!;
        const elemType = targetType.kind === "Tuple"
          ? ctx.types.apply(targetType.elements[i] ?? TY.unresolved)
          : TY.unresolved;
        const elemTarget: LoweredExpr = {
          kind: "LoweredFieldAccess", span: elem.span, type: elemType,
          target, field: `_${i}`,
        };
        const sub = patternPredicate(ctx, elem, elemTarget, elemType, elem.span);
        if (sub === null) continue;
        acc = acc === null
          ? sub
          : { kind: "LoweredBinary", span: elem.span, type: TY.bool, op: "and", left: acc, right: sub };
      }
      return acc;
    }
  }
}

function lowerStructPattern(
  ctx: FnLowerCtx, pattern: A.StructPattern, ident: LoweredExpr, span: Span,
): LoweredExpr {
  let acc: LoweredExpr = { kind: "LoweredBoolLit", span, type: TY.bool, value: true };
  for (const f of pattern.fields) {
    if (f.value.kind !== "literal") continue;
    const lit = lowerExpr(ctx, f.value.value);
    const eq: LoweredExpr = {
      kind: "LoweredBinary", span: f.span, type: TY.bool, op: "eq",
      left: { kind: "LoweredFieldAccess", span: f.span, type: lit.type, target: ident, field: f.name },
      right: lit,
    };
    acc = { kind: "LoweredBinary", span: f.span, type: TY.bool, op: "and", left: acc, right: eq };
  }
  return acc;
}

function introducePatternBindings(
  ctx: FnLowerCtx, pattern: A.Pattern, scrutSym: Symbol, scrutType: Type,
  out: LoweredStmt[], span: Span,
): void {
  const scrutRef: LoweredExpr =
    { kind: "LoweredIdent", span, type: scrutType, symbol: scrutSym };
  walkPatternBindings(ctx, pattern, scrutRef, scrutType, out, span);
}

/** Recursive variant of pattern-binding emission. Tracks the per-element
 *  target so nested patterns (tuples currently) read from the right slot. */
function walkPatternBindings(
  ctx: FnLowerCtx, pattern: A.Pattern, target: LoweredExpr, targetType: Type,
  out: LoweredStmt[], span: Span,
): void {
  switch (pattern.kind) {
    case "BindingPattern": {
      const sym = ctx.typed.resolved.patternBindings.get(pattern)
        ?? freshSyntheticSymbol(ctx, pattern.name);
      const init = lowerCellInit(ctx, sym, target, targetType, span);
      out.push({
        kind: "LoweredLet", span, name: pattern.name, symbol: sym,
        type: init.slotType, value: init.value,
      });
      return;
    }
    case "IsPattern": {
      if (pattern.bindAs !== null) {
        const cast: LoweredExpr = {
          kind: "LoweredCast", span,
          type: ctx.types.typeExprType(pattern.type), value: target,
        };
        const sym = ctx.typed.resolved.patternBindings.get(pattern)
          ?? freshSyntheticSymbol(ctx, pattern.bindAs);
        const init = lowerCellInit(ctx, sym, cast, cast.type, span);
        out.push({
          kind: "LoweredLet", span, name: pattern.bindAs, symbol: sym,
          type: init.slotType, value: init.value,
        });
      }
      if (pattern.inner !== null) {
        const innerType = ctx.types.typeExprType(pattern.type);
        walkPatternBindings(ctx, pattern.inner, target, innerType, out, span);
      }
      return;
    }
    case "StructPattern": {
      for (const f of pattern.fields) {
        if (f.value.kind !== "binding") continue;
        const fieldAccess: LoweredExpr = {
          kind: "LoweredFieldAccess", span: f.span, type: TY.unresolved,
          target, field: f.name,
        };
        const sym = ctx.typed.resolved.patternBindings.get(f)
          ?? freshSyntheticSymbol(ctx, f.value.name);
        const init = lowerCellInit(ctx, sym, fieldAccess, TY.unresolved, f.span);
        out.push({
          kind: "LoweredLet", span: f.span, name: f.value.name, symbol: sym,
          type: init.slotType, value: init.value,
        });
      }
      return;
    }
    case "TuplePattern": {
      for (let i = 0; i < pattern.elements.length; i++) {
        const elem = pattern.elements[i]!;
        const elemType = targetType.kind === "Tuple"
          ? ctx.types.apply(targetType.elements[i] ?? TY.unresolved)
          : TY.unresolved;
        const elemTarget: LoweredExpr = {
          kind: "LoweredFieldAccess", span: elem.span, type: elemType,
          target, field: `_${i}`,
        };
        walkPatternBindings(ctx, elem, elemTarget, elemType, out, elem.span);
      }
      return;
    }
    case "WildcardPattern":
    case "EnumVariantPattern":
      return;
  }
}

