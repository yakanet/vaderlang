// Top-level expression lowerer. Dispatches by AST kind and delegates string
// interp, match, try, range, and for-in to their dedicated passes.

import type * as A from "../../parser/ast.ts";
import type { Type } from "../../typecheck/types.ts";
import { TY, defaultIfFree } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredBlock, LoweredExpr, LoweredIf, LoweredStructLitField } from "../lowered-ast.ts";
import { err } from "../diag.ts";

import { lowerBlock } from "./block.ts";
import { lookupImplEntry, lowerRangeExpr } from "./for-in.ts";
import { applySubst, loweredEnumVariant, wrapAsBlock } from "./helpers.ts";
import { lowerMatch } from "./match.ts";
import { lowerStringLit } from "./string-interp.ts";
import { lowerTry } from "./try.ts";

export function lowerExpr(ctx: FnLowerCtx, expr: A.Expr): LoweredExpr {
  const exprType = applySubst(ctx.typed.exprTypes.get(expr) ?? TY.unresolved, ctx.subst);
  switch (expr.kind) {
    case "IntLitExpr":
      return { kind: "LoweredIntLit", span: expr.span, type: defaultIfFree(exprType), value: expr.value };
    case "FloatLitExpr":
      return { kind: "LoweredFloatLit", span: expr.span, type: defaultIfFree(exprType), value: expr.value };
    case "BoolLitExpr":
      return { kind: "LoweredBoolLit", span: expr.span, type: TY.bool, value: expr.value };
    case "NullLitExpr":
      return { kind: "LoweredNullLit", span: expr.span, type: TY.null };
    case "CharLitExpr":
      return { kind: "LoweredCharLit", span: expr.span, type: TY.char, value: expr.value };
    case "StringLitExpr":
      return lowerStringLit(ctx, expr);
    case "IdentExpr":
      return lowerIdent(ctx, expr, exprType);
    case "CallExpr": {
      // Trait method via UFCS: typecheck recorded a MethodResolution on the
      // FieldExpr callee. Rewrite into a direct call of the impl's specialised
      // fn with the receiver as the first argument. For generic impls, the
      // right specialisation is keyed by the receiver's struct args.
      if (expr.callee.kind === "FieldExpr") {
        const arrayOp = ctx.typed.arrayOps.get(expr.callee);
        if (arrayOp === "len") {
          return {
            kind: "LoweredArrayLen", span: expr.span, type: TY.i32,
            target: lowerExpr(ctx, expr.callee.target),
          };
        }
        if (arrayOp === "push") {
          return {
            kind: "LoweredArrayPush", span: expr.span, type: TY.void,
            target: lowerExpr(ctx, expr.callee.target),
            value: lowerExpr(ctx, expr.args[0]!.value),
          };
        }
        const method = ctx.typed.methodResolutions.get(expr.callee);
        if (method !== undefined) {
          const recv = method.receiverType;
          const args = recv.kind === "Struct" ? recv.args : [];
          const entry = lookupImplEntry(ctx, method.member, args);
          if (entry !== null && entry.symbol !== null) {
            const sym = entry.symbol;
            const calleeIdent: LoweredExpr = {
              kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: sym,
            };
            return {
              kind: "LoweredCall", span: expr.span, type: exprType,
              callee: calleeIdent,
              args: [
                lowerExpr(ctx, expr.callee.target),
                ...expr.args.map((a) => lowerExpr(ctx, a.value)),
              ],
            };
          }
        }
        const freeSym = ctx.typed.ufcsFreeResolutions.get(expr.callee);
        if (freeSym !== undefined) {
          const calleeIdent: LoweredExpr = {
            kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: freeSym,
          };
          return {
            kind: "LoweredCall", span: expr.span, type: exprType,
            callee: calleeIdent,
            args: [
              lowerExpr(ctx, expr.callee.target),
              ...expr.args.map((a) => lowerExpr(ctx, a.value)),
            ],
          };
        }
      }
      return {
        kind: "LoweredCall", span: expr.span, type: exprType,
        callee: lowerExpr(ctx, expr.callee),
        args: expr.args.map((a) => lowerExpr(ctx, a.value)),
      };
    }
    case "FieldExpr": {
      if (exprType.kind === "Enum") return loweredEnumVariant(exprType, expr.field, expr.span);
      return {
        kind: "LoweredFieldAccess", span: expr.span, type: exprType,
        target: lowerExpr(ctx, expr.target), field: expr.field,
      };
    }
    case "IndexExpr":
      return {
        kind: "LoweredIndex", span: expr.span, type: exprType,
        target: lowerExpr(ctx, expr.target),
        index: lowerExpr(ctx, expr.index),
      };
    case "UnaryExpr":
      return {
        kind: "LoweredUnary", span: expr.span, type: exprType,
        op: expr.op, operand: lowerExpr(ctx, expr.operand),
      };
    case "BinaryExpr":
      return lowerBinary(ctx, expr, exprType);
    case "IfExpr":
      return lowerIf(ctx, expr, exprType);
    case "MatchExpr":
      return lowerMatch(ctx, expr, exprType);
    case "BlockExpr":
      return lowerBlock(ctx, expr, /*isFnRoot*/ false, /*isLoopBody*/ false);
    case "LambdaExpr":
      err(ctx.project.diags, "B5001", expr.span,
        "lambdas / closures are not yet supported (lambda lifting deferred — see TODO §1.6)");
      return { kind: "LoweredUnreachable", span: expr.span, type: exprType,
               reason: "lambda lifting not yet implemented" };
    case "StructLitExpr":
      return {
        kind: "LoweredStructLit", span: expr.span, type: exprType,
        fields: expr.fields.map<LoweredStructLitField>((f) => ({
          name: f.name, value: lowerExpr(ctx, f.value),
        })),
      };
    case "ArrayLitExpr":
      return {
        kind: "LoweredArrayLit", span: expr.span, type: exprType,
        elements: expr.elements.map((e) => lowerExpr(ctx, e)),
      };
    case "RangeExpr":
      return lowerRangeExpr(ctx, expr, exprType);
    case "TryExpr":
      return lowerTry(ctx, expr, exprType);
    case "DotVariantExpr":
      return loweredEnumVariant(exprType, expr.variant, expr.span);
    case "CastExpr":
      return {
        kind: "LoweredCast", span: expr.span, type: exprType,
        value: lowerExpr(ctx, expr.value),
      };
    case "GenericInstExpr":
      return lowerExpr(ctx, expr.callee);     // type-args baked in post-mono
  }
}

function lowerIdent(ctx: FnLowerCtx, expr: A.IdentExpr, type: Type): LoweredExpr {
  const sym = ctx.typed.resolved.idents.get(expr);
  if (sym === undefined) {
    return { kind: "LoweredUnreachable", span: expr.span, type, reason: `unresolved ident ${expr.name}` };
  }
  return { kind: "LoweredIdent", span: expr.span, type, symbol: sym };
}

function lowerBinary(ctx: FnLowerCtx, expr: A.BinaryExpr, exprType: Type): LoweredExpr {
  if (expr.op === "is") {
    const checkType = applySubst(ctx.typed.exprTypes.get(expr.right) ?? TY.unresolved, ctx.subst);
    return {
      kind: "LoweredTypeCheck", span: expr.span, type: TY.bool,
      value: lowerExpr(ctx, expr.left), checkType,
    };
  }
  return {
    kind: "LoweredBinary", span: expr.span, type: exprType,
    op: expr.op,
    left: lowerExpr(ctx, expr.left),
    right: lowerExpr(ctx, expr.right),
  };
}

export function lowerIf(ctx: FnLowerCtx, expr: A.IfExpr, exprType: Type): LoweredIf {
  const cond = lowerExpr(ctx, expr.cond);
  const then = lowerBlock(ctx, expr.then, false, false);
  let elseBlock: LoweredBlock | null = null;
  if (expr.else !== null) {
    elseBlock = expr.else.kind === "BlockExpr"
      ? lowerBlock(ctx, expr.else, false, false)
      : wrapAsBlock(lowerIf(ctx, expr.else, exprType), expr.else.span);
  }
  return { kind: "LoweredIf", span: expr.span, type: exprType, cond, then, else: elseBlock };
}
