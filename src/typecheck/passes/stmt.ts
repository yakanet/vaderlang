// Statement and block checking. Walks every statement of a fn body, checks
// each against its expected type (where applicable), and tracks loop depth /
// `Self` substitution / for-in narrowing through the FnContext.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Type } from "../types.ts";
import { CORE_TRAITS, TY, defaultIfFree, displayType, isAssignable, substitute } from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkExpr } from "./expr.ts";
import { lowerTypeExpr } from "./type-expr.ts";

export function checkFnBody(
  fn: A.FnDecl, body: A.BlockExpr, selfType: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector,
): void {
  // Substitute `Self` in this fn's declared param/return types now that we know
  // the surrounding impl's target type. Also bind unannotated `self` parameters.
  if (selfType !== null) {
    for (const p of fn.params) {
      if (p.name === "self" && p.type === null) {
        t.globals.paramTypes.set(p, selfType);
      } else {
        const declared = t.globals.paramTypes.get(p);
        if (declared !== undefined) {
          t.globals.paramTypes.set(p, substitute(declared, { self: selfType }));
        }
      }
    }
    const declaredFn = t.globals.declTypes.get(fn);
    if (declaredFn !== undefined) {
      t.globals.declTypes.set(fn, substitute(declaredFn, { self: selfType }));
    }
  }
  const fnType = t.globals.declTypes.get(fn);
  const ctx: FnContext = {
    returnType: fnType?.kind === "Fn" ? fnType.returnType : TY.unresolved,
    selfType,
    loopDepth: 0,
  };
  const got = checkBlock(body, ctx.returnType, t, impls, diags, ctx);
  // Implicit return: if the block has no trailing expr the body type is void
  // (already handled). If the trailing expr is incompatible the diagnostic
  // already fired.
  if (body.trailing !== null && !isAssignable(got, ctx.returnType, impls)) {
    err(diags, "T3020", body.trailing.span,
      `expected ${displayType(ctx.returnType)}, got ${displayType(got)}`);
  }
}

export function checkBlock(
  block: A.BlockExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  for (const stmt of block.stmts) checkStmt(stmt, t, impls, diags, fn);
  let result: Type = TY.void;
  if (block.trailing !== null) {
    result = checkExpr(block.trailing, expected, t, impls, diags, fn);
  }
  t.exprTypes.set(block, result);
  return result;
}

function checkStmt(
  stmt: A.Stmt, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): void {
  switch (stmt.kind) {
    case "LetStmt": {
      const expected = stmt.type !== null ? lowerTypeExpr(stmt.type, t, diags) : null;
      const got = checkExpr(stmt.value, expected, t, impls, diags, fn);
      const declared = expected ?? defaultIfFree(got);
      if (expected !== null && !isAssignable(got, expected, impls)) {
        err(diags, "T3001", stmt.span,
          `expected ${displayType(expected)}, got ${displayType(got)}`);
      }
      t.localTypes.set(stmt, declared);
      return;
    }
    case "AssignStmt": {
      const targetType = checkExpr(stmt.target, null, t, impls, diags, fn);
      // Pass the target's type as expected so free numeric literals adopt it
      // (e.g. `v: u64; v = 5` → `5: u64`, not `5: i32`).
      const valueCtx = targetType.kind === "Unresolved" ? null : targetType;
      checkExpr(stmt.value, valueCtx, t, impls, diags, fn);
      return;
    }
    case "ExprStmt":
      checkExpr(stmt.expr, null, t, impls, diags, fn);
      return;
    case "ReturnStmt": {
      if (fn === null) return;
      if (stmt.value === null) {
        if (!isAssignable(TY.void, fn.returnType)) {
          err(diags, "T3020", stmt.span,
            `expected ${displayType(fn.returnType)}, got void`);
        }
        return;
      }
      const got = checkExpr(stmt.value, fn.returnType, t, impls, diags, fn);
      if (!isAssignable(got, fn.returnType, impls)) {
        err(diags, "T3020", stmt.span,
          `expected ${displayType(fn.returnType)}, got ${displayType(got)}`);
      }
      return;
    }
    case "ForStmt":
      checkForStmt(stmt, t, impls, diags, fn);
      return;
    case "BreakStmt":
    case "ContinueStmt":
      if (fn === null || fn.loopDepth === 0) err(diags, "T3015", stmt.span);
      return;
    case "DeferStmt":
      if (stmt.body.kind === "BlockExpr") checkBlock(stmt.body, null, t, impls, diags, fn);
      else checkStmt(stmt.body, t, impls, diags, fn);
      return;
  }
}

function checkForStmt(
  stmt: A.ForStmt, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): void {
  switch (stmt.form.kind) {
    case "infinite":
      break;
    case "while": {
      const got = checkExpr(stmt.form.cond, TY.bool, t, impls, diags, fn);
      if (!isAssignable(got, TY.bool)) err(diags, "T3019", stmt.form.cond.span);
      break;
    }
    case "in": {
      checkExpr(stmt.form.iter, null, t, impls, diags, fn);
      // MVP: only `RangeExpr` iters are supported (1.5b-A1). Full Iterator
      // dispatch is deferred — the lowerer emits B5001 if it sees anything
      // else, so the typecheck just narrows the binding when we recognise
      // the range form.
      const bindingSym = t.resolved.forIns.get(stmt);
      const elementTy = forInElementType(stmt.form.iter, t);
      if (bindingSym !== undefined && elementTy !== null) {
        t.narrowed.set(bindingSym.id, elementTy);
      }
      const newFn = fn !== null ? { ...fn, loopDepth: fn.loopDepth + 1 } : null;
      checkBlock(stmt.body, null, t, impls, diags, newFn);
      if (bindingSym !== undefined) t.narrowed.delete(bindingSym.id);
      return;
    }
  }
  const newFn = fn !== null ? { ...fn, loopDepth: fn.loopDepth + 1 } : null;
  checkBlock(stmt.body, null, t, impls, diags, newFn);
}

function forInElementType(iter: A.Expr, t: MutableTyped): Type | null {
  // Range has a known element type by construction.
  if (iter.kind === "RangeExpr") return TY.i32;
  // Other iterables: query the Iterator impl on the iter's static type and
  // pull the element type from its trait args.
  const iterType = t.exprTypes.get(iter);
  if (iterType === undefined) return null;
  if (iterType.kind === "Array") return iterType.element;
  const iteratorSym = t.globals.coreSymbols?.get(CORE_TRAITS.Iterator);
  if (iteratorSym === undefined) return null;
  return null;     // user-defined iterators handled when we wire a richer trait lookup
}
