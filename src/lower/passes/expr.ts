// Top-level expression lowerer. Dispatches by AST kind and delegates string
// interp, match, try, range, and for-in to their dedicated passes.

import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf } from "../../resolver/symbol.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_TRAITS, TY, defaultIfFree, displayType } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredBlock, LoweredExpr, LoweredIf, LoweredStructLitField } from "../lowered-ast.ts";
import { err } from "../diag.ts";

import { lowerBlock } from "./block.ts";
import { findCoreTrait } from "./core.ts";
import { lookupImplEntry, lookupImplFor, lowerRangeExpr } from "./for-in.ts";
import { applySubst, loweredEnumVariant, wrapAsBlock } from "./helpers.ts";
import { lowerLambda } from "./lambda.ts";
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
      if (expr.callee.kind === "IdentExpr") {
        const calleeSym = ctx.typed.resolved.idents.get(expr.callee);
        // Cast call `Type(value)` — lower to a `LoweredCast` so the bytecode
        // emitter inserts a convert op (otherwise it'd treat the type symbol
        // as a callable and emit `unreachable`).
        if (calleeSym !== undefined
            && (calleeSym.kind === "builtin-type" || calleeSym.kind === "struct" || calleeSym.kind === "type-alias")
            && expr.args.length === 1) {
          return {
            kind: "LoweredCast", span: expr.span, type: exprType,
            value: lowerExpr(ctx, expr.args[0]!.value),
          };
        }
        const typeArgs = ctx.typed.genericFnCalls.get(expr);
        if (typeArgs !== undefined && calleeSym !== undefined) {
          const fnDecl = declOf(calleeSym);
          if (fnDecl !== null && fnDecl.kind === "FnDecl") {
            const entry = lookupFnInstance(ctx, fnDecl, typeArgs);
            if (entry !== null) {
              return {
                kind: "LoweredCall", span: expr.span, type: exprType,
                callee: { kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: entry.symbol! },
                args: expr.args.map((a) => lowerExpr(ctx, a.value)),
              };
            }
          }
        }
      }
      // GenericInstExpr callee (explicit `foo(T)(args)` form, if the parser ever produces it).
      if (expr.callee.kind === "GenericInstExpr" && expr.callee.callee.kind === "IdentExpr") {
        const innerSym = ctx.typed.resolved.idents.get(expr.callee.callee);
        if (innerSym !== undefined) {
          const fnDecl = declOf(innerSym);
          if (fnDecl !== null && fnDecl.kind === "FnDecl" && fnDecl.typeParams.length > 0) {
            const typeArgs = expr.callee.typeArgs.map((ta) =>
              applySubst(ctx.typed.typeExprTypes.get(ta) ?? TY.unresolved, ctx.subst),
            );
            const entry = lookupFnInstance(ctx, fnDecl, typeArgs);
            if (entry !== null) {
              return {
                kind: "LoweredCall", span: expr.span, type: exprType,
                callee: { kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: entry.symbol! },
                args: expr.args.map((a) => lowerExpr(ctx, a.value)),
              };
            }
          }
        }
      }
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
            return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol);
          }
        }
        // Trait-method dispatch on a generic TypeParam — the typechecker
        // recorded `(trait, method)` ; we apply the call-site substitution
        // to the receiver type-param to get the concrete receiver, then
        // resolve the impl member just like a regular method call.
        const traitMethod = ctx.typed.traitMethodResolutions.get(expr.callee);
        if (traitMethod !== undefined) {
          const concreteRecv = applySubst(traitMethod.receiverParam, ctx.subst);
          const impl = lookupImplFor(ctx.project, concreteRecv, traitMethod.trait);
          if (impl !== null) {
            const member = impl.decl.members.find((m) => m.name === traitMethod.member.name);
            if (member !== undefined) {
              const structArgs = concreteRecv.kind === "Struct" ? concreteRecv.args : [];
              const entry = lookupImplEntry(ctx, member, structArgs);
              if (entry !== null && entry.symbol !== null) {
                return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol);
              }
            }
          }
        }
        const freeSym = ctx.typed.ufcsFreeResolutions.get(expr.callee);
        if (freeSym !== undefined) {
          const ufcsTypeArgs = ctx.typed.genericFnCalls.get(expr);
          if (ufcsTypeArgs !== undefined) {
            const fnDecl = declOf(freeSym);
            if (fnDecl !== null && fnDecl.kind === "FnDecl") {
              const entry = lookupFnInstance(ctx, fnDecl, ufcsTypeArgs);
              if (entry !== null) return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol!);
            }
          }
          return lowerUfcsCall(ctx, expr, expr.callee, exprType, freeSym);
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
      return lowerLambda(ctx, expr);
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
  // Lifted-fn context: an outer-captured symbol referenced inside the body
  // is reached through `env.cap_X` (yielding the cell), then CellGet for the
  // value. We never resolve to the bare outer symbol here — the lifted fn
  // has no access to it.
  if (ctx.liftedContext !== null) {
    const fieldName = ctx.liftedContext.captureFields.get(sym.id);
    if (fieldName !== undefined) {
      const envIdent: LoweredExpr = {
        kind: "LoweredIdent", span: expr.span, type: ctx.liftedContext.envType,
        symbol: ctx.liftedContext.envSymbol,
      };
      const cellRef: LoweredExpr = {
        kind: "LoweredFieldAccess", span: expr.span, type,
        target: envIdent, field: fieldName,
      };
      return { kind: "LoweredCellGet", span: expr.span, type, target: cellRef, valueType: type };
    }
  }
  // Captured local in the current scope — read through the cell.
  if (ctx.project.closures.capturedSymbols.has(sym.id)) {
    const cellRef: LoweredExpr = { kind: "LoweredIdent", span: expr.span, type, symbol: sym };
    return { kind: "LoweredCellGet", span: expr.span, type, target: cellRef, valueType: type };
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
  if (expr.op === "in" || expr.op === "not_in") {
    return lowerInOp(ctx, expr);
  }
  return {
    kind: "LoweredBinary", span: expr.span, type: exprType,
    op: expr.op,
    left: lowerExpr(ctx, expr.left),
    right: lowerExpr(ctx, expr.right),
  };
}

/** Desugar `x in coll` to `coll.contains(x)`, or `x !in coll` to `!coll.contains(x)`.
 *  Resolves the `Contains($T)::contains` impl on `coll`'s static type and emits a
 *  direct call to the monomorphised symbol. */
function lowerInOp(ctx: FnLowerCtx, expr: A.BinaryExpr): LoweredExpr {
  const collType = applySubst(ctx.typed.exprTypes.get(expr.right) ?? TY.unresolved, ctx.subst);
  const fail = (msg: string): LoweredExpr => {
    err(ctx.project.diags, "B5001", expr.span, msg);
    return { kind: "LoweredBoolLit", span: expr.span, type: TY.bool, value: false };
  };
  const containsTrait = findCoreTrait(ctx.project, CORE_TRAITS.Contains);
  if (containsTrait === null) return fail("Contains trait not found in std/core");
  const entry = lookupImplFor(ctx.project, collType, containsTrait);
  if (entry === null) {
    return fail(`\`${expr.op === "in" ? "in" : "!in"}\` requires Contains impl on ${displayType(collType)}`);
  }
  const containsDecl = entry.decl.members.find((m) => m.name === "contains");
  if (containsDecl === undefined) return fail("Contains impl missing `contains` member");
  const structArgs = collType.kind === "Struct" ? collType.args : [];
  const monoEntry = lookupImplEntry(ctx, containsDecl, structArgs);
  if (monoEntry === null || monoEntry.symbol === null) {
    return fail("Contains.contains has no monomorphised instance");
  }
  const call: LoweredExpr = {
    kind: "LoweredCall", span: expr.span, type: TY.bool,
    callee: { kind: "LoweredIdent", span: expr.span, type: TY.bool, symbol: monoEntry.symbol },
    args: [lowerExpr(ctx, expr.right), lowerExpr(ctx, expr.left)],
  };
  if (expr.op === "not_in") {
    return { kind: "LoweredUnary", span: expr.span, type: TY.bool, op: "not", operand: call };
  }
  return call;
}

import type { MonoEntry } from "../../monomorphize/mono-ast.ts";

function lookupFnInstance(ctx: FnLowerCtx, fnDecl: A.FnDecl, typeArgs: readonly Type[]): MonoEntry | null {
  const key = typeArgs.map((ta) => displayType(applySubst(ta, ctx.subst))).join(",");
  const entry = ctx.project.mono.fnInstanceEntries.get(fnDecl)?.get(key) ?? null;
  return entry !== null && entry.symbol !== null ? entry : null;
}

function lowerUfcsCall(
  ctx: FnLowerCtx, expr: A.CallExpr, callee: A.FieldExpr, exprType: Type, sym: Symbol,
): LoweredExpr {
  return {
    kind: "LoweredCall", span: expr.span, type: exprType,
    callee: { kind: "LoweredIdent", span: callee.span, type: exprType, symbol: sym },
    args: [
      lowerExpr(ctx, callee.target),
      ...expr.args.map((a) => lowerExpr(ctx, a.value)),
    ],
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
