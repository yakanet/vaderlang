// Lowers blocks and statements. Threads the defer stack so that every block
// exit (return, break, continue, fallthrough) replays its registered defers
// in reverse order.

import type * as A from "../../parser/ast.ts";
import { TY, defaultIfFree } from "../../typecheck/types.ts";

import type { BlockCtx, FnLowerCtx } from "../ctx.ts";
import type { LoweredBlock, LoweredExpr, LoweredStmt } from "../lowered-ast.ts";

import { lowerExpr } from "./expr.ts";
import { lowerForIn } from "./for-in.ts";
import { applySubst, freshSyntheticSymbol, wrapStmts } from "./helpers.ts";

export function lowerBlock(
  ctx: FnLowerCtx, block: A.BlockExpr, isFnRoot: boolean, isLoopBody: boolean,
): LoweredBlock {
  const blockCtx: BlockCtx = { defers: [], isFnRoot, isLoopBody };
  ctx.blocks.push(blockCtx);

  const stmts: LoweredStmt[] = [];
  let diverged = false;
  for (const s of block.stmts) {
    if (s.kind === "DeferStmt") {
      blockCtx.defers.push(s.body.kind === "BlockExpr"
        ? { kind: "ExprStmt", span: s.body.span, expr: s.body }
        : s.body);
      continue;
    }
    if (diverged) continue;
    const lowered = lowerStmt(ctx, s);
    if (lowered !== null) stmts.push(lowered);
    if (s.kind === "ReturnStmt" || s.kind === "BreakStmt" || s.kind === "ContinueStmt") {
      diverged = true;
    }
  }

  if (diverged) {
    ctx.blocks.pop();
    return { kind: "LoweredBlock", span: block.span, type: TY.void, stmts, trailing: null };
  }

  const trailing = block.trailing === null
    ? emitTrailingDefersOnly(ctx, blockCtx, stmts)
    : emitTrailingValueWithDefers(ctx, blockCtx, stmts, block.trailing);

  ctx.blocks.pop();
  return {
    kind: "LoweredBlock", span: block.span,
    type: trailing?.type ?? TY.void,
    stmts, trailing,
  };
}

function emitTrailingDefersOnly(
  ctx: FnLowerCtx, blockCtx: BlockCtx, stmts: LoweredStmt[],
): LoweredExpr | null {
  emitDefersInto(ctx, blockCtx.defers, stmts);
  return null;
}

function emitTrailingValueWithDefers(
  ctx: FnLowerCtx, blockCtx: BlockCtx, stmts: LoweredStmt[], trailing: A.Expr,
): LoweredExpr {
  const value = lowerExpr(ctx, trailing);
  if (blockCtx.defers.length === 0) return value;

  // Save the trailing value to a temp, run defers, then yield the temp.
  const tmpSym = freshSyntheticSymbol(ctx, "block");
  stmts.push({
    kind: "LoweredLet", span: trailing.span, name: tmpSym.name, symbol: tmpSym,
    type: value.type, value,
  });
  emitDefersInto(ctx, blockCtx.defers, stmts);
  return { kind: "LoweredIdent", span: trailing.span, type: value.type, symbol: tmpSym };
}

function emitDefersInto(ctx: FnLowerCtx, defers: readonly A.Stmt[], out: LoweredStmt[]): void {
  for (let i = defers.length - 1; i >= 0; i--) {
    const d = lowerStmt(ctx, defers[i]!);
    if (d !== null) out.push(d);
  }
}

export function lowerStmt(ctx: FnLowerCtx, stmt: A.Stmt): LoweredStmt | null {
  switch (stmt.kind) {
    case "LetStmt": {
      const value = lowerExpr(ctx, stmt.value);
      const type = applySubst(ctx.typed.localTypes.get(stmt) ?? defaultIfFree(value.type), ctx.subst);
      const sym = ctx.typed.resolved.locals.get(stmt);
      if (sym === undefined) return null;
      // Captured local: heap-promote into a closure cell. The local slot now
      // holds a *cell ref* (always boxed) instead of the original value, so
      // the slot's lowered type widens to opaque ref. CellGet/CellSet drive
      // the actual value access.
      if (ctx.project.closures.capturedSymbols.has(sym.id)) {
        const cellInit: LoweredExpr = {
          kind: "LoweredCellNew", span: stmt.span, type: TY.unresolved, value, valueType: type,
        };
        return { kind: "LoweredLet", span: stmt.span, name: stmt.name, symbol: sym, type: TY.unresolved, value: cellInit };
      }
      return { kind: "LoweredLet", span: stmt.span, name: stmt.name, symbol: sym, type, value };
    }
    case "AssignStmt": {
      // Reassignment to a captured local: write into its cell rather than
      // overwriting the slot. Other targets (struct fields, indexed elements,
      // non-captured locals) keep the regular LoweredAssign path.
      if (stmt.target.kind === "IdentExpr") {
        const targetSym = ctx.typed.resolved.idents.get(stmt.target);
        if (targetSym !== undefined) {
          const valueType = applySubst(
            ctx.typed.exprTypes.get(stmt.target) ?? TY.unresolved,
            ctx.subst,
          );
          // Inside a lifted fn: outer captured symbol → cell ref via env.cap_X.
          if (ctx.liftedContext !== null) {
            const fieldName = ctx.liftedContext.captureFields.get(targetSym.id);
            if (fieldName !== undefined) {
              const envIdent: LoweredExpr = {
                kind: "LoweredIdent", span: stmt.target.span,
                type: ctx.liftedContext.envType, symbol: ctx.liftedContext.envSymbol,
              };
              const cellRef: LoweredExpr = {
                kind: "LoweredFieldAccess", span: stmt.target.span, type: valueType,
                target: envIdent, field: fieldName,
              };
              return {
                kind: "LoweredCellSet", span: stmt.span,
                target: cellRef,
                value: lowerExpr(ctx, stmt.value),
                valueType,
              };
            }
          }
          // Direct captured local in the current scope.
          if (ctx.project.closures.capturedSymbols.has(targetSym.id)) {
            const cellRef: LoweredExpr = {
              kind: "LoweredIdent", span: stmt.target.span, type: valueType, symbol: targetSym,
            };
            return {
              kind: "LoweredCellSet", span: stmt.span,
              target: cellRef,
              value: lowerExpr(ctx, stmt.value),
              valueType,
            };
          }
        }
      }
      return {
        kind: "LoweredAssign", span: stmt.span,
        target: lowerExpr(ctx, stmt.target),
        value: lowerExpr(ctx, stmt.value),
      };
    }
    case "ExprStmt":
      return { kind: "LoweredExprStmt", span: stmt.span, expr: lowerExpr(ctx, stmt.expr) };
    case "ReturnStmt": {
      const cleanups = collectDefersUpTo(ctx, /*stopOnLoop*/ false);
      const value = stmt.value === null ? null : lowerExpr(ctx, stmt.value);
      return wrapStmts(stmt.span, [...cleanups, { kind: "LoweredReturn", span: stmt.span, value }]);
    }
    case "BreakStmt": {
      const cleanups = collectDefersUpTo(ctx, /*stopOnLoop*/ true);
      return wrapStmts(stmt.span, [...cleanups,
        { kind: "LoweredBreak", span: stmt.span, label: stmt.label }]);
    }
    case "ContinueStmt": {
      const cleanups = collectDefersUpTo(ctx, /*stopOnLoop*/ true);
      return wrapStmts(stmt.span, [...cleanups,
        { kind: "LoweredContinue", span: stmt.span, label: stmt.label }]);
    }
    case "ForStmt": {
      if (stmt.form.kind === "in") return lowerForIn(ctx, stmt);
      const cond = stmt.form.kind === "while" ? lowerExpr(ctx, stmt.form.cond) : null;
      const body = lowerBlock(ctx, stmt.body, /*isFnRoot*/ false, /*isLoopBody*/ true);
      return { kind: "LoweredLoop", span: stmt.span, label: stmt.label, cond, body };
    }
    case "DeferStmt":
      return null;     // registered in lowerBlock, never emitted in place
  }
}

/** Collect defers from the current block out to either the fn root (for return)
 *  or the innermost loop body (for break/continue), innermost-first, LIFO. */
function collectDefersUpTo(ctx: FnLowerCtx, stopOnLoop: boolean): LoweredStmt[] {
  const out: LoweredStmt[] = [];
  for (let i = ctx.blocks.length - 1; i >= 0; i--) {
    const b = ctx.blocks[i]!;
    emitDefersInto(ctx, b.defers, out);
    if (stopOnLoop && b.isLoopBody) break;
  }
  return out;
}
