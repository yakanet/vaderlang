// Lowers the `?` operator. Splits the operand's type into error / ok variants
// and emits an early-return for the error half.

import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { ImplRegistry } from "../../typecheck/impls.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_TRAITS, TY } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredExpr, LoweredIf } from "../lowered-ast.ts";

import { findCoreTrait } from "./core.ts";
import { lowerExpr } from "./expr.ts";
import { freshSyntheticSymbol, orAll, wrapAsBlock } from "./helpers.ts";

export function lowerTry(ctx: FnLowerCtx, expr: A.TryExpr, exprType: Type): LoweredExpr {
  const inner = lowerExpr(ctx, expr.inner);
  const innerSym = freshSyntheticSymbol(ctx, "try");
  const idRef: LoweredExpr = { kind: "LoweredIdent", span: expr.span, type: inner.type, symbol: innerSym };

  const errorVariants = errorVariantsOf(inner.type, ctx);
  const errorPredicate = orAll(expr.span, errorVariants.map((v): LoweredExpr => ({
    kind: "LoweredTypeCheck", span: expr.span, type: TY.bool,
    value: idRef, checkType: v,
  })));

  const ifNode: LoweredIf = {
    kind: "LoweredIf", span: expr.span, type: exprType,
    cond: errorPredicate,
    then: {
      kind: "LoweredBlock", span: expr.span, type: TY.never,
      stmts: [{ kind: "LoweredReturn", span: expr.span, value: idRef }],
      trailing: null,
    },
    else: wrapAsBlock(
      { kind: "LoweredCast", span: expr.span, type: exprType, value: idRef },
      expr.span),
  };

  return {
    kind: "LoweredBlock", span: expr.span, type: exprType,
    stmts: [{
      kind: "LoweredLet", span: expr.span, name: innerSym.name, symbol: innerSym,
      type: inner.type, value: inner,
    }],
    trailing: ifNode,
  };
}

function errorVariantsOf(t: Type, ctx: FnLowerCtx): readonly Type[] {
  const variants: readonly Type[] = t.kind === "Union" ? t.variants : [t];
  const errorSym = findCoreTrait(ctx.project, CORE_TRAITS.Error);
  if (errorSym === null) return variants;
  return variants.filter((v) => satisfiesError(v, errorSym, ctx.project.impls));
}

function satisfiesError(v: Type, errorSym: Symbol, impls: ImplRegistry): boolean {
  // The trait type itself counts: `string!` desugars to `Error | string` where
  // `Error` is the trait — any value of that variant is by definition an error.
  if (v.kind === "Trait") return v.symbol.id === errorSym.id;
  if (v.kind === "Struct") return impls.hasUser(v.symbol, errorSym);
  if (v.kind === "Primitive") return impls.forPrimitive(v.name, errorSym) !== null;
  return false;
}
