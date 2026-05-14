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
import type { Symbol } from "../../resolver/symbol.ts";
import type { MutableTyped } from "../ctx.ts";
import { typeOfSymbol } from "./expr.ts";
import type { Type } from "../types.ts";
import { TY, equalsType, unionOf } from "../types.ts";

/** Resolve a plain `IdentExpr` to its symbol *only* when that symbol is a
 *  flow-narrowable kind (local / param / binding). Shared between match's
 *  scrutinee detection (`match.ts`) and the if-condition flow detector
 *  (`detectVariantNarrowing` below) — both reject anything else. */
export function resolveNarrowableIdent(
  ident: A.IdentExpr, t: MutableTyped,
): Symbol | null {
  const sym = t.resolved.idents.get(ident);
  if (sym === undefined) return null;
  if (sym.kind !== "local" && sym.kind !== "param" && sym.kind !== "binding") return null;
  return sym;
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

export function fieldNarrowKey(symId: number, fieldName: string): string {
  return `${symId}#${fieldName}`;
}

/** Field narrowing mirrors the symbol-id flavour : a push registers a more
 *  specific type for `targetSym.field` reads inside the scope, a pop
 *  restores the prior entry. Same staleness caveat as `pushNarrowing` —
 *  a mutation of `targetSym.field` inside the scope isn't observed ;
 *  Vader's MVP idiom doesn't reassign fields mid-match. */
export function pushFieldNarrowing(
  t: MutableTyped, symId: number, fieldName: string, narrow: Type,
): Type | undefined {
  const k = fieldNarrowKey(symId, fieldName);
  const prev = t.narrowedFields.get(k);
  t.narrowedFields.set(k, narrow);
  return prev;
}

export function popFieldNarrowing(
  t: MutableTyped, symId: number, fieldName: string, prev: Type | undefined,
): void {
  const k = fieldNarrowKey(symId, fieldName);
  if (prev === undefined) t.narrowedFields.delete(k);
  else t.narrowedFields.set(k, prev);
}

/** Subset of `NarrowingSplit` carrying only the scrutinee identity — what
 *  `pushSplit` / `popSplit` need to route to the right (symbol vs field)
 *  narrowing map. Lets callers persist narrowings without dragging the
 *  then/else types around (e.g. the `postStmtNarrowing` flow in
 *  `stmt.ts` keeps only one of the two types per branch). */
export interface NarrowingScope {
  readonly symId: number;
  readonly fieldName: string | null;
}

/** Push `type` into whichever narrowing slot `split` describes (symbol-id
 *  or `(symId, fieldName)` field). Mirror `popSplit` below. Returns the
 *  prior entry the pop should restore. */
export function pushSplit(
  t: MutableTyped, split: NarrowingScope, type: Type,
): Type | undefined {
  return split.fieldName === null
    ? pushNarrowing(t, split.symId, type)
    : pushFieldNarrowing(t, split.symId, split.fieldName, type);
}

export function popSplit(
  t: MutableTyped, split: NarrowingScope, prev: Type | undefined,
): void {
  if (split.fieldName === null) popNarrowing(t, split.symId, prev);
  else popFieldNarrowing(t, split.symId, split.fieldName, prev);
}

/** Result of a flow-narrowing detection. `fieldName === null` means the
 *  scrutinee was a plain ident — push through `pushNarrowing` on
 *  `symId`. When `fieldName` is set, the scrutinee was `ident.field` —
 *  push through `pushFieldNarrowing` on the `(symId, fieldName)` pair. */
export interface NarrowingSplit {
  readonly symId: number;
  readonly fieldName: string | null;
  readonly thenType: Type;
  readonly elseType: Type;
}

/** Detect a variant-narrowing condition on a single scrutinee. Scrutinee
 *  shapes accepted : a plain ident (`x`) or a one-level field access
 *  (`x.field`) where the ident binds a local / param / binding. Three
 *  comparison shapes :
 *    1. `scrut is T`              ⇒ then = T ; else = current minus T
 *    2. `scrut == null`           ⇒ then = null ; else = current minus null
 *    3. `scrut != null`           ⇒ then = current minus null ; else = null
 *  Plus leading `!` flips then/else. Bails (returns null) when the
 *  scrutinee isn't narrowable, the static type isn't a Union, or the
 *  check is statically vacuous. */
export function detectVariantNarrowing(
  cond: A.Expr, t: MutableTyped,
): NarrowingSplit | null {
  if (cond.kind === "UnaryExpr" && cond.op === "not") {
    const inner = detectVariantNarrowing(cond.operand, t);
    if (inner === null) return null;
    return { ...inner, thenType: inner.elseType, elseType: inner.thenType };
  }
  if (cond.kind !== "BinaryExpr") return null;
  if (cond.op === "is") {
    const checkType = t.binaryIsCheckTypes.get(cond);
    if (checkType === undefined) return null;
    return narrowFromScrutinee(cond.left, checkType, t);
  }
  if (cond.op === "eq" || cond.op === "neq") {
    const { left, right } = cond;
    const scrut = right.kind === "NullLitExpr" ? left
                : left.kind === "NullLitExpr"  ? right
                : null;
    if (scrut === null) return null;
    const split = narrowFromScrutinee(scrut, TY.null, t);
    if (split === null) return null;
    if (cond.op === "neq") {
      return { ...split, thenType: split.elseType, elseType: split.thenType };
    }
    return split;
  }
  return null;
}

/** Compute the matching / complementary pair for a narrowable scrutinee
 *  (plain ident or `ident.field`) against `checkType`. Returns null on
 *  any of the bail conditions documented on `detectVariantNarrowing`. */
function narrowFromScrutinee(
  scrut: A.Expr, checkType: Type, t: MutableTyped,
): NarrowingSplit | null {
  if (scrut.kind === "IdentExpr") {
    const sym = resolveNarrowableIdent(scrut, t);
    if (sym === null) return null;
    return splitUnion(typeOfSymbol(sym, t), checkType, sym.id, null);
  }
  if (scrut.kind === "FieldExpr" && scrut.target.kind === "IdentExpr") {
    const sym = resolveNarrowableIdent(scrut.target, t);
    if (sym === null) return null;
    // The condition expression has already been type-checked, so the
    // field expression's type sits in `exprTypes`. The `?? TY.unresolved`
    // is defensive — a missing entry means a preceding pass failed to
    // type the cond, in which case `splitUnion` bails on the non-union
    // type below and no narrowing fires.
    const current = t.exprTypes.get(scrut) ?? TY.unresolved;
    return splitUnion(current, checkType, sym.id, scrut.field);
  }
  // Nested paths (`a.b.c`) and non-Ident bases are deferred — the
  // narrowing map keys on a single `(symId, fieldName)` pair.
  return null;
}

function splitUnion(
  current: Type, checkType: Type, symId: number, fieldName: string | null,
): NarrowingSplit | null {
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
  return { symId, fieldName, thenType, elseType };
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
 *  block, or null when the shape doesn't qualify. `fieldName` mirrors
 *  `NarrowingSplit` — null for symbol scrutinees, set for `ident.field`. */
export function postStmtNarrowing(
  stmt: A.Stmt, t: MutableTyped,
): { symId: number; fieldName: string | null; type: Type } | null {
  if (stmt.kind !== "ExprStmt" || stmt.expr.kind !== "IfExpr") return null;
  const ifExpr = stmt.expr;
  const split = detectVariantNarrowing(ifExpr.cond, t);
  if (split === null) return null;
  const thenDiverges = blockDiverges(ifExpr.then);
  const elseBlock = ifExpr.else;
  const elseDiverges = elseBlock !== null && elseBlock.kind === "BlockExpr" && blockDiverges(elseBlock);
  if (thenDiverges && !elseDiverges) {
    return { symId: split.symId, fieldName: split.fieldName, type: split.elseType };
  }
  if (elseDiverges && !thenDiverges) {
    return { symId: split.symId, fieldName: split.fieldName, type: split.thenType };
  }
  return null;
}
