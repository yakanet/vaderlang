// Lowers blocks and statements. Threads the defer stack so that every block
// exit (return, break, continue, fallthrough) replays its registered defers
// in reverse order.

import type * as A from "../../parser/ast.ts";
import {TY, defaultIfFree, type Type} from "../../typecheck/types.ts";

import type { BlockCtx, FnLowerCtx } from "../ctx.ts";
import type { LoweredBlock, LoweredExpr, LoweredStmt } from "../lowered-ast.ts";

import { lowerExpr, lowerIndexTraitCall } from "./expr.ts";
import { lowerForIn } from "./for-in.ts";
import { freshSyntheticSymbol, lowerCellInit, wrapStmts } from "./helpers.ts";
import type {Span} from "../../diagnostics/diagnostic.ts";
import type { Symbol } from "../../resolver/symbol.ts";

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
    if (lowered !== null) {
      if (Array.isArray(lowered)) stmts.push(...lowered);
      else stmts.push(lowered);
    }
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
    if (d === null) continue;
    if (Array.isArray(d)) out.push(...d);
    else out.push(d);
  }
}

export function lowerStmt(ctx: FnLowerCtx, stmt: A.Stmt): LoweredStmt | LoweredStmt[] | null {
  switch (stmt.kind) {
    case "LetStmt": {
      // Layer 5b — `t :: <type-expr>` in-fn type alias : the typechecker
      // pre-resolved the underlying Type into `letTypeAliases`. There is
      // no runtime slot — type-position users already resolved through
      // `typeFromSymbol` ; skip emission entirely.
      if (stmt.binding.kind === "SimpleBinding") {
        const sym = ctx.typed.resolved.locals.get(stmt.binding);
        if (sym !== undefined && ctx.typed.letTypeAliases.has(sym)) return null;
      }
      const value = lowerExpr(ctx, stmt.value);
      if (stmt.binding.kind === "SimpleBinding") {
        const leaf = stmt.binding;
        const type = ctx.types.apply(ctx.typed.localTypes.get(leaf) ?? defaultIfFree(value.type));
        const sym = ctx.typed.resolved.locals.get(leaf);
        if (sym === undefined) return null;
        const init = lowerCellInit(ctx, sym, value, type, stmt.span);
        return { kind: "LoweredLet", span: stmt.span, name: leaf.name, symbol: sym,
                 type: init.slotType, value: init.value };
      }
      // Tuple/wildcard destructure : evaluate the value once into a synthetic
      // temp, then emit one LoweredLet per leaf reading `__tup._N`.
      return lowerLetDestructure(ctx, stmt, stmt.binding, value);
    }
    case "AssignStmt": {
      // `a[i] = v` on a non-array target — typecheck recorded an IndexSet
      // dispatch ; rewrite into a `set_at(self, i, v)` call.
      if (stmt.target.kind === "IndexExpr") {
        const indexSet = ctx.typed.indexSetResolutions.get(stmt.target);
        if (indexSet !== undefined) {
          const value = lowerExpr(ctx, stmt.value);
          const call = lowerIndexTraitCall(ctx, stmt.target, TY.void, indexSet, [value]);
          return { kind: "LoweredExprStmt", span: stmt.span, expr: call };
        }
      }
      // Reassignment to a captured local: write into its cell rather than
      // overwriting the slot. Other targets (struct fields, indexed elements,
      // non-captured locals) keep the regular LoweredAssign path.
      if (stmt.target.kind === "IdentExpr") {
        const targetSym = ctx.typed.resolved.idents.get(stmt.target);
        if (targetSym !== undefined) {
          const valueType = ctx.types.exprType(stmt.target);
          // Inside a lifted fn: outer captured symbol → cell ref via env.cap_X.
          if (ctx.liftedContext !== null) {
            const fieldName = ctx.liftedContext.captureFields.get(targetSym.id);
            if (fieldName !== undefined) {
              const envIdent: LoweredExpr = {
                kind: "LoweredIdent", span: stmt.target.span,
                type: ctx.liftedContext.envType, symbol: ctx.liftedContext.envSymbol,
              };
              const cellRef: LoweredExpr = {
                // FieldAccess yields the cell ref, not the value — see lowerIdent.
                kind: "LoweredFieldAccess", span: stmt.target.span, type: TY.unresolved,
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
      // Assignment targets need the raw (un-narrowed) lvalue so the bytecode
      // emitter can resolve the slot/field. lowerExpr would wrap a narrowed
      // ident in a LoweredCast (for match-arm reads), which breaks
      // emitAssign's pattern-match on target.kind. Build the target manually
      // for IdentExpr.
      const target: LoweredExpr = stmt.target.kind === "IdentExpr"
        ? rawIdentTarget(ctx, stmt.target)
        : lowerExpr(ctx, stmt.target);
      return {
        kind: "LoweredAssign", span: stmt.span,
        target,
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
      if (stmt.form.kind === "in") {
        return lowerForIn(
          ctx, stmt, stmt.form.iter, stmt.form.binding,
          ctx.typed.resolved.forIns.get(stmt),
        );
      }
      if (stmt.form.kind === "while") {
        // `for <iter> { body }` sugar — typecheck flags it via whileAsForIn.
        const discardSym = ctx.typed.whileAsForIn.get(stmt);
        if (discardSym !== undefined) {
          return lowerForIn(ctx, stmt, stmt.form.cond, "_", discardSym);
        }
      }
      const cond = stmt.form.kind === "while" ? lowerExpr(ctx, stmt.form.cond) : null;
      const body = lowerBlock(ctx, stmt.body, /*isFnRoot*/ false, /*isLoopBody*/ true);
      return { kind: "LoweredLoop", span: stmt.span, label: stmt.label, cond, body };
    }
    case "DeferStmt":
      return null;     // registered in lowerBlock, never emitted in place
  }
}

/** Build an assignment target ident without applying match-arm narrowing.
 *  `lowerExpr` would wrap the narrowed lvalue in a LoweredCast, which
 *  emitAssign can't pattern-match on. */
function rawIdentTarget(ctx: FnLowerCtx, expr: A.IdentExpr): LoweredExpr {
  const sym = ctx.typed.resolved.idents.get(expr);
  if (sym === undefined) return lowerExpr(ctx, expr);
  const type = ctx.types.exprType(expr);
  return { kind: "LoweredIdent", span: expr.span, type, symbol: sym };
}

/** Desugar `let [a, b, ...] := value` into a chain :
 *    let __tup = value
 *    let a    = __tup._0
 *    let b    = __tup._1
 *    ...
 *  Recurses for nested tuple bindings ; skips emission for `WildcardBinding`. */
function lowerLetDestructure(
  ctx: FnLowerCtx, stmt: A.LetStmt, binding: A.LetBinding, value: LoweredExpr,
): LoweredStmt[] {
  const out: LoweredStmt[] = [];
  const tupleType = value.type;
  const tmpSym = freshSyntheticSymbol(ctx, "tup");
  out.push({
    kind: "LoweredLet", span: stmt.span, name: tmpSym.name, symbol: tmpSym,
    type: tupleType, value,
  });
  const tmpRef: LoweredExpr = {
    kind: "LoweredIdent", span: stmt.span, type: tupleType, symbol: tmpSym,
  };
  emitLetBindingLeaves(ctx, binding, tmpRef, tupleType, stmt.span, out);
  return out;
}

function emitLetBindingLeaves(
  ctx: FnLowerCtx, binding: A.LetBinding, target: LoweredExpr,
  targetType: Type, span: Span,
  out: LoweredStmt[],
): void {
  if (binding.kind === "WildcardBinding") return;
  if (binding.kind === "SimpleBinding") {
    const sym = ctx.typed.resolved.locals.get(binding);
    if (sym === undefined) return;
    const slotType = ctx.types.apply(ctx.typed.localTypes.get(binding) ?? targetType);
    const init = lowerCellInit(ctx, sym, target, slotType, span);
    out.push({
      kind: "LoweredLet", span, name: binding.name, symbol: sym,
      type: init.slotType, value: init.value,
    });
    return;
  }
  if (binding.kind === "RestBinding") {
    throw new Error("lower: RestBinding reached emitLetBindingLeaves outside its TupleBinding parent");
  }
  const restIdx = binding.elements.findIndex((e) => e.kind === "RestBinding");
  if (restIdx >= 0 && targetType.kind === "Array") {
    emitArrayDestructure(ctx, binding, target, targetType, span, out);
    return;
  }
  for (let i = 0; i < binding.elements.length; i++) {
    const leaf = binding.elements[i]!;
    if (leaf.kind === "WildcardBinding") continue;
    if (leaf.kind === "RestBinding") continue;  // typecheck already errored
    const elemType = targetType.kind === "Tuple"
      ? ctx.types.apply(targetType.elements[i] ?? TY.unresolved)
      : TY.unresolved;
    const access: LoweredExpr = {
      kind: "LoweredFieldAccess", span: leaf.span, type: elemType,
      target, field: `_${i}`,
    };
    emitLetBindingLeaves(ctx, leaf, access, elemType, leaf.span, out);
  }
}

/** Desugar `let [a, b, ...rest] = arr` into N direct index reads for the
 *  fixed leaves followed by a fresh-array + loop-push for the rest leaf.
 *  `rest` is routed through `lowerCellInit` so capture by an inner closure
 *  promotes the slot to a heap cell ; reads inside our synthetic loop
 *  become CellGet automatically. */
function emitArrayDestructure(
  ctx: FnLowerCtx, binding: A.TupleBinding, target: LoweredExpr,
  targetType: Type & { kind: "Array" }, span: Span,
  out: LoweredStmt[],
): void {
  const elemType = ctx.types.apply(targetType.element);
  const restIdx = binding.elements.findIndex((e) => e.kind === "RestBinding");
  for (let i = 0; i < restIdx; i++) {
    const leaf = binding.elements[i]!;
    if (leaf.kind === "WildcardBinding") continue;
    const access: LoweredExpr = {
      kind: "LoweredIndex", span: leaf.span, type: elemType,
      target, index: { kind: "LoweredIntLit", span: leaf.span, type: TY.i32, value: BigInt(i) },
    };
    emitLetBindingLeaves(ctx, leaf, access, elemType, leaf.span, out);
  }
  const restLeaf = binding.elements[restIdx] as A.RestBinding;
  const restSym = ctx.typed.resolved.locals.get(restLeaf);
  if (restSym === undefined) return;
  const emptyArr: LoweredExpr = {
    kind: "LoweredArrayLit", span: restLeaf.span, type: targetType, elements: [],
  };
  const restInit = lowerCellInit(ctx, restSym, emptyArr, targetType, restLeaf.span);
  out.push({
    kind: "LoweredLet", span: restLeaf.span, name: restLeaf.name, symbol: restSym,
    type: restInit.slotType, value: restInit.value,
  });
  const idxSym = freshSyntheticSymbol(ctx, "i");
  out.push({
    kind: "LoweredLet", span, name: idxSym.name, symbol: idxSym, type: TY.i32,
    value: { kind: "LoweredIntLit", span, type: TY.i32, value: BigInt(restIdx) },
  });
  const idxRef: LoweredExpr = { kind: "LoweredIdent", span, type: TY.i32, symbol: idxSym };
  const restRef = readLocal(ctx, restSym, targetType, span);
  const pushStmt: LoweredStmt = {
    kind: "LoweredExprStmt", span,
    expr: {
      kind: "LoweredArrayPush", span, type: TY.void, target: restRef,
      value: { kind: "LoweredIndex", span, type: elemType, target, index: idxRef },
    },
  };
  const incStmt: LoweredStmt = {
    kind: "LoweredAssign", span, target: idxRef,
    value: {
      kind: "LoweredBinary", span, type: TY.i32, op: "add",
      left: idxRef,
      right: { kind: "LoweredIntLit", span, type: TY.i32, value: 1n },
    },
  };
  out.push({
    kind: "LoweredLoop", span, label: null, cond: {
      kind: "LoweredBinary", span, type: TY.bool, op: "lt",
      left: idxRef,
      right: { kind: "LoweredArrayLen", span, type: TY.i32, target },
    },
    body: { kind: "LoweredBlock", span, type: TY.void, stmts: [pushStmt, incStmt], trailing: null },
  });
}

/** Read a local symbol respecting closure-cell promotion. Mirrors the read
 *  path in `lowerIdent` but for synthetic call sites that don't have an
 *  IdentExpr to dispatch from. */
function readLocal(ctx: FnLowerCtx, sym: Symbol, type: Type, span: Span): LoweredExpr {
  if (ctx.project.closures.capturedSymbols.has(sym.id)) {
    const cellRef: LoweredExpr = {
      kind: "LoweredIdent", span, type: TY.unresolved, symbol: sym,
    };
    return { kind: "LoweredCellGet", span, type, target: cellRef, valueType: type };
  }
  return { kind: "LoweredIdent", span, type, symbol: sym };
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
