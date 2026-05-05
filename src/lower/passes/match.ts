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
import { applySubst, freshSyntheticSymbol, loweredEnumVariant, wrapAsBlock } from "./helpers.ts";

export function lowerMatch(ctx: FnLowerCtx, expr: A.MatchExpr, exprType: Type): LoweredExpr {
  const scrutType = applySubst(ctx.typed.exprTypes.get(expr.scrutinee) ?? TY.unresolved, ctx.subst);
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
  const ident = (): LoweredExpr =>
    ({ kind: "LoweredIdent", span, type: scrutType, symbol: scrutSym });

  let core: LoweredExpr | null;
  switch (arm.pattern.kind) {
    case "WildcardPattern":
    case "BindingPattern":
      core = null;
      break;
    case "IsPattern":
      core = {
        kind: "LoweredTypeCheck", span, type: TY.bool,
        value: ident(),
        checkType: applySubst(ctx.typed.typeExprTypes.get(arm.pattern.type) ?? TY.unresolved, ctx.subst),
      };
      break;
    case "StructPattern":
      core = lowerStructPattern(ctx, arm.pattern, ident(), span);
      break;
    case "EnumVariantPattern": {
      const variantLit = loweredEnumVariant(scrutType, arm.pattern.variant, span);
      core = { kind: "LoweredBinary", span, type: TY.bool, op: "eq", left: ident(), right: variantLit };
      break;
    }
  }

  if (arm.guard === null) return core;
  const guard = lowerExpr(ctx, arm.guard);
  if (core === null) return guard;
  return { kind: "LoweredBinary", span: arm.span, type: TY.bool, op: "and", left: core, right: guard };
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
  const scrutRef = (): LoweredExpr =>
    ({ kind: "LoweredIdent", span, type: scrutType, symbol: scrutSym });
  switch (pattern.kind) {
    case "BindingPattern": {
      const sym = freshSyntheticSymbol(ctx, pattern.name);
      out.push({ kind: "LoweredLet", span, name: pattern.name, symbol: sym,
                 type: scrutType, value: scrutRef() });
      return;
    }
    case "IsPattern": {
      if (pattern.bindAs === null) return;
      const targetType = applySubst(
        ctx.typed.typeExprTypes.get(pattern.type) ?? TY.unresolved, ctx.subst);
      const sym = freshSyntheticSymbol(ctx, pattern.bindAs);
      out.push({
        kind: "LoweredLet", span, name: pattern.bindAs, symbol: sym, type: targetType,
        value: { kind: "LoweredCast", span, type: targetType, value: scrutRef() },
      });
      return;
    }
    case "StructPattern":
      for (const f of pattern.fields) {
        if (f.value.kind !== "binding") continue;
        const sym = freshSyntheticSymbol(ctx, f.value.name);
        out.push({
          kind: "LoweredLet", span: f.span, name: f.value.name, symbol: sym, type: TY.unresolved,
          value: {
            kind: "LoweredFieldAccess", span: f.span, type: TY.unresolved,
            target: { kind: "LoweredIdent", span: f.span, type: scrutType, symbol: scrutSym },
            field: f.name,
          },
        });
      }
      return;
    case "EnumVariantPattern":
    case "WildcardPattern":
      return;
  }
}
