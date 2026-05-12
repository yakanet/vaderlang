// Flow-sensitive narrowing — the type a symbol carries inside a particular
// branch may be more specific than its declared type. Today this fires in two
// places :
//   1. `match` arms — `is T -> body` narrows the scrutinee symbol to `T`
//      inside `body` (handled by `match.ts`, this module exports the shared
//      push/pop helpers).
//   2. `if` conditions on `x == null` / `x != null` (here) — the matching
//      branch sees `x` with the `null` variant removed, and a sibling
//      statement after a divergent if (`if x == null { return }`) sees the
//      complement narrowing too.
//
// The narrowing map (`MutableTyped.narrowed`) is a flat `Map<symbolId, Type>` ;
// nesting works because push returns the prior entry and pop restores it.

import type * as A from "../../parser/ast.ts";
import type { MutableTyped } from "../ctx.ts";
import { typeOfSymbol } from "./expr.ts";
import type { Type } from "../types.ts";
import { TY, equalsType, unionOf } from "../types.ts";

function isNullType(t: Type): boolean {
  return equalsType(t, TY.null);
}

export function pushNarrowing(t: MutableTyped, symId: number, narrow: Type): Type | undefined {
  const prev = t.narrowed.get(symId);
  t.narrowed.set(symId, narrow);
  return prev;
}

export function popNarrowing(t: MutableTyped, symId: number, prev: Type | undefined): void {
  if (prev === undefined) t.narrowed.delete(symId);
  else t.narrowed.set(symId, prev);
}

/** Detect an `ident == null` / `ident != null` condition on a narrowable
 *  scrutinee (param/local/binding) whose current type is `T | null`. Returns
 *  the symbol id, the comparison op, and the union with the `null` variant
 *  removed — that's what flows into the matching branch. Returns null when
 *  the shape doesn't match (non-Binary, non-null operand, non-union type,
 *  union without a `null` variant, etc.). */
export function detectNullCheck(
  cond: A.Expr, t: MutableTyped,
): { symId: number; op: "eq" | "neq"; nonNull: Type } | null {
  if (cond.kind !== "BinaryExpr") return null;
  if (cond.op !== "eq" && cond.op !== "neq") return null;
  const { left, right } = cond;
  const ident = left.kind === "IdentExpr" && right.kind === "NullLitExpr" ? left
              : right.kind === "IdentExpr" && left.kind === "NullLitExpr" ? right
              : null;
  if (ident === null) return null;
  const sym = t.resolved.idents.get(ident);
  if (sym === undefined) return null;
  if (sym.kind !== "local" && sym.kind !== "param" && sym.kind !== "binding") return null;
  const current = typeOfSymbol(sym, t);
  if (current.kind !== "Union") return null;
  const nonNullVariants = current.variants.filter((v) => !isNullType(v));
  if (nonNullVariants.length === current.variants.length) return null;
  if (nonNullVariants.length === 0) return null;
  return { symId: sym.id, op: cond.op, nonNull: unionOf(nonNullVariants) };
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

/** When a block-level `if x == null { return … }` (or any null-check whose
 *  divergent branch escapes the enclosing fn) precedes other statements,
 *  the subsequent code is reachable only when the condition was false ;
 *  push the complementary narrowing so `x.field` after the guard sees the
 *  narrowed type. Returns the narrowing to apply to the *rest* of the
 *  enclosing block, or null when the shape doesn't qualify. */
export function postStmtNullNarrowing(
  stmt: A.Stmt, t: MutableTyped,
): { symId: number; type: Type } | null {
  if (stmt.kind !== "ExprStmt" || stmt.expr.kind !== "IfExpr") return null;
  const ifExpr = stmt.expr;
  const nullCheck = detectNullCheck(ifExpr.cond, t);
  if (nullCheck === null) return null;
  const thenDiverges = blockDiverges(ifExpr.then);
  const elseBlock = ifExpr.else;
  const elseDiverges = elseBlock !== null && elseBlock.kind === "BlockExpr" && blockDiverges(elseBlock);
  if (thenDiverges && !elseDiverges) {
    // `if a == null { return }` ⇒ after the stmt, a is nonNull
    // `if a != null { return }` ⇒ after the stmt, a is null
    const narrow = nullCheck.op === "eq" ? nullCheck.nonNull : TY.null;
    return { symId: nullCheck.symId, type: narrow };
  }
  if (elseDiverges && !thenDiverges) {
    // `if a == null { x } else { return }` ⇒ after, a is null
    // `if a != null { x } else { return }` ⇒ after, a is nonNull
    const narrow = nullCheck.op === "eq" ? TY.null : nullCheck.nonNull;
    return { symId: nullCheck.symId, type: narrow };
  }
  return null;
}
