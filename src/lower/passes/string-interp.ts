// Lowers string literals with `${...}` segments into a sequence of
// concatenated parts using the Display intrinsic — each segment becomes a
// builder.append call, and the trailing builder.finish yields the result.

import type * as A from "../../parser/ast.ts";
import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Type } from "../../typecheck/types.ts";
import { TY } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredExpr, LoweredStmt } from "../lowered-ast.ts";
import { INTRINSICS } from "../lowered-ast.ts";

import { lowerExpr } from "./expr.ts";
import { freshSyntheticSymbol } from "./helpers.ts";

export function lowerStringLit(ctx: FnLowerCtx, expr: A.StringLitExpr): LoweredExpr {
  if (expr.parts.every((p) => p.kind === "text")) {
    let value = "";
    for (const part of expr.parts) if (part.kind === "text") value += part.value;
    return { kind: "LoweredStringLit", span: expr.span, type: TY.string, value };
  }

  // Build a chain of @builder.* intrinsics. The StringBuilder runtime type
  // isn't modelled in the type system yet; the bytecode emitter resolves the
  // concrete type when wiring `std/builder`.
  const sbSym = freshSyntheticSymbol(ctx, "sb");
  const sbType: Type = TY.unresolved;
  const sbRef = (span: Span): LoweredExpr =>
    ({ kind: "LoweredIdent", span, type: sbType, symbol: sbSym });

  const stmts: LoweredStmt[] = [{
    kind: "LoweredLet", span: expr.span, name: sbSym.name, symbol: sbSym, type: sbType,
    value: { kind: "LoweredIntrinsicCall", span: expr.span, type: sbType, name: INTRINSICS.builderNew, args: [] },
  }];

  for (const part of expr.parts) {
    if (part.kind === "text") {
      const lit: LoweredExpr = { kind: "LoweredStringLit", span: part.span, type: TY.string, value: part.value };
      stmts.push({
        kind: "LoweredExprStmt", span: part.span,
        expr: {
          kind: "LoweredIntrinsicCall", span: part.span, type: TY.void,
          name: INTRINSICS.builderAppendStr,
          args: [sbRef(part.span), lit],
        },
      });
    } else {
      const inner = lowerExpr(ctx, part.expr);
      stmts.push({
        kind: "LoweredExprStmt", span: part.span,
        expr: {
          kind: "LoweredIntrinsicCall", span: part.span, type: TY.void,
          name: INTRINSICS.builderAppendDisplay,
          args: [sbRef(part.span), inner],
          displayFor: inner.type,
        },
      });
    }
  }

  return {
    kind: "LoweredBlock", span: expr.span, type: TY.string,
    stmts,
    trailing: {
      kind: "LoweredIntrinsicCall", span: expr.span, type: TY.string,
      name: INTRINSICS.builderFinish, args: [sbRef(expr.span)],
    },
  };
}
