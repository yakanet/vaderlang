// Flow-sensitive narrowing — the type a symbol carries inside a particular
// branch may be more specific than its declared type. Three sites fire today :
//   1. `match` arms — `is T -> body` narrows the scrutinee symbol to `T`
//      inside `body` (handled by `match.ts`, this module exports the shared
//      push/pop helpers).
//   2. `if` conditions on `x is T` (variant test) or `x == null` / `x != null`
//      (null specialisation) — the matching branch sees `x` with the matching
//      variants kept ; the other branch sees the complement.
//   3. A divergent `if` (`if x is T { return }`) preceding sibling statements
//      pushes the complementary narrowing forward.
//
// The narrowing map (`MutableTyped.narrowed`) is a flat `Map<symbolId, Type>` ;
// nesting works because push returns the prior entry and pop restores it.

import type * as A from "../../parser/ast.ts";
import type { MutableTyped } from "../ctx.ts";
import { typeOfSymbol } from "./expr.ts";
import type { Type } from "../types.ts";
import { TY, equalsType, unionOf } from "../types.ts";

export function pushNarrowing(t: MutableTyped, symId: number, narrow: Type): Type | undefined {
  const prev = t.narrowed.get(symId);
  t.narrowed.set(symId, narrow);
  return prev;
}

export function popNarrowing(t: MutableTyped, symId: number, prev: Type | undefined): void {
  if (prev === undefined) t.narrowed.delete(symId);
  else t.narrowed.set(symId, prev);
}

/** Detect a variant-narrowing condition on a single ident scrutinee.
 *  Three shapes are recognised :
 *    1. `ident is T`              ⇒ then = T ; else = current minus T
 *    2. `ident == null`           ⇒ then = null ; else = current minus null
 *    3. `ident != null`           ⇒ then = current minus null ; else = null
 *  Plus leading `!` flips then/else. Bails (returns null) when the ident
 *  isn't a narrowable scrutinee (local/param/binding), when its type isn't
 *  a Union, or when the check is statically vacuous (variant absent or sole
 *  member of the union). */
export function detectVariantNarrowing(
  cond: A.Expr, t: MutableTyped,
): { symId: number; thenType: Type; elseType: Type } | null {
  if (cond.kind === "UnaryExpr" && cond.op === "not") {
    const inner = detectVariantNarrowing(cond.operand, t);
    if (inner === null) return null;
    return { symId: inner.symId, thenType: inner.elseType, elseType: inner.thenType };
  }
  if (cond.kind !== "BinaryExpr") return null;
  if (cond.op === "is") {
    if (cond.left.kind !== "IdentExpr") return null;
    const checkType = t.binaryIsCheckTypes.get(cond);
    if (checkType === undefined) return null;
    return narrowFromIdent(cond.left, checkType, t);
  }
  if (cond.op === "eq" || cond.op === "neq") {
    const { left, right } = cond;
    const ident = left.kind === "IdentExpr" && right.kind === "NullLitExpr" ? left
                : right.kind === "IdentExpr" && left.kind === "NullLitExpr" ? right
                : null;
    if (ident === null) return null;
    const split = narrowFromIdent(ident, TY.null, t);
    if (split === null) return null;
    if (cond.op === "neq") {
      return { symId: split.symId, thenType: split.elseType, elseType: split.thenType };
    }
    return split;
  }
  return null;
}

function narrowFromIdent(
  ident: A.IdentExpr, checkType: Type, t: MutableTyped,
): { symId: number; thenType: Type; elseType: Type } | null {
  const sym = t.resolved.idents.get(ident);
  if (sym === undefined) return null;
  if (sym.kind !== "local" && sym.kind !== "param" && sym.kind !== "binding") return null;
  const current = typeOfSymbol(sym, t);
  if (current.kind !== "Union") return null;
  const matching: Type[] = [];
  const remaining: Type[] = [];
  for (const v of current.variants) {
    if (equalsType(v, checkType)) matching.push(v);
    else remaining.push(v);
  }
  if (matching.length === 0) return null;     // checkType not a variant
  if (remaining.length === 0) return null;    // would collapse to Never
  const thenType = matching.length === 1 ? matching[0]! : unionOf(matching);
  const elseType = unionOf(remaining);
  return { symId: sym.id, thenType, elseType };
}

/** True when every control-flow path through this block ends in a
 *  return / break / continue. Today we only inspect the *last* statement —
 *  enough to handle the dominant pattern `if guard { return }` ; richer
 *  exhaustiveness (match arms that all return, nested if-else-divergent)
 *  is deferred until a real reachability pass replaces this heuristic. */
export function blockDiverges(block: A.BlockExpr): boolean {
  if (block.trailing !== null) return false;
  if (block.stmts.length === 0) return false;
  const last = block.stmts[block.stmts.length - 1]!;
  return last.kind === "ReturnStmt" || last.kind === "BreakStmt" || last.kind === "ContinueStmt";
}

/** When a block-level `if <guard> { return … }` (any narrowing guard whose
 *  divergent branch escapes the enclosing fn) precedes other statements,
 *  the subsequent code is reachable only when the guard was false ; push
 *  the complementary narrowing so subsequent references see the narrowed
 *  type. Returns the narrowing to apply to the *rest* of the enclosing
 *  block, or null when the shape doesn't qualify. */
export function postStmtNarrowing(
  stmt: A.Stmt, t: MutableTyped,
): { symId: number; type: Type } | null {
  if (stmt.kind !== "ExprStmt" || stmt.expr.kind !== "IfExpr") return null;
  const ifExpr = stmt.expr;
  const split = detectVariantNarrowing(ifExpr.cond, t);
  if (split === null) return null;
  const thenDiverges = blockDiverges(ifExpr.then);
  const elseBlock = ifExpr.else;
  const elseDiverges = elseBlock !== null && elseBlock.kind === "BlockExpr" && blockDiverges(elseBlock);
  if (thenDiverges && !elseDiverges) {
    return { symId: split.symId, type: split.elseType };
  }
  if (elseDiverges && !thenDiverges) {
    return { symId: split.symId, type: split.thenType };
  }
  return null;
}
