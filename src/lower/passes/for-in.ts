// Desugars `for x in iter` into the Iterator-step loop. Auto-wraps `[T]`
// arrays into `ArrayIter(T)` and resolves the matching `step` impl via the
// ImplRegistry. Also lowers `RangeExpr` into a `Range` struct literal so
// for-in can dispatch through the same Iterator path.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { ImplEntry } from "../../typecheck/impls.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_STRUCTS, CORE_TRAITS, TY, canonicalArgsKey, displayType, isInteger, mkArray, mkStruct, mkUnion, substitute } from "../../typecheck/types.ts";
import { ERASED_KEY, type MonoEntry } from "../../comptime/specialize.ts";

import type { FnLowerCtx, LowerProjectCtx } from "../ctx.ts";
import { err } from "../diag.ts";
import type { LoweredBinaryOp, LoweredBlock, LoweredExpr, LoweredStmt } from "../lowered-ast.ts";

import { lowerBlock } from "./block.ts";
import { findCoreTrait, findCoreType, unionOfYieldNull } from "./core.ts";
import { lowerExpr } from "./expr.ts";
import { blockStmtsWithTrailing, freshSyntheticSymbol, wrapStmts } from "./helpers.ts";

/** Desugar `RangeExpr` (`a..<b` / `a..=b`) into a `Range` struct literal so
 *  `for-in` can dispatch through the standard Iterator impl rather than a
 *  bespoke fast path. The struct's fields mirror `std/core::Range`. */
export function lowerRangeExpr(ctx: FnLowerCtx, expr: A.RangeExpr, exprType: Type): LoweredExpr {
  const span = expr.span;
  const lower = lowerExpr(ctx, expr.lower);
  const upper = lowerExpr(ctx, expr.upper);
  const inclusive: LoweredExpr = {
    kind: "LoweredBoolLit", span, type: TY.bool, value: expr.inclusive,
  };
  // `cursor` starts at the lower bound — same expression literal, lowered
  // a second time so the two emit independent slot reads when the bound is
  // an ident. The previous form initialised cursor to `0_i32` which only
  // worked when iteration started at zero ; generic Range[T] (e.g.
  // `Range[char]`) needs the bound type's value here.
  const cursor = lowerExpr(ctx, expr.lower);
  return {
    kind: "LoweredStructLit", span, type: exprType,
    fields: [
      { name: "start",     value: lower },
      { name: "end",       value: upper },
      { name: "inclusive", value: inclusive },
      { name: "cursor",    value: cursor },
    ],
  };
}

/** Desugar `for x in <iter>` into a step-loop dispatched through the
 *  Iterator impl on `iter`'s static type. Range and other iterables share
 *  this path; the caller-side iter is lowered first so `RangeExpr` becomes a
 *  `Range` struct literal before we look up its Iterator impl.
 */
const COMPTIME_FOR_MAX_ITERS = 256;

/** `@comptime for` unroll. Threads the per-iter substitution through
 *  `ctx.comptimeBindings` so `lowerIdent` folds loop-var reads to their
 *  literal even inside lambdas / nested blocks the body re-enters. */

export function lowerComptimeForIn(
  ctx: FnLowerCtx, stmt: A.ForStmt,
  iterExpr: A.Expr, _bindingName: string, bindingSym: Symbol | undefined,
): LoweredStmt {
  const span = stmt.span;
  if (bindingSym === undefined) {
    err(ctx.project.diags, "B5001", span, "@comptime for binding not resolved");
    return { kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredUnreachable", span, type: TY.void, reason: "missing comptime-for binding",
    } };
  }
  const iterLowered = lowerExpr(ctx, iterExpr);
  if (iterLowered.kind !== "LoweredArrayLit") {
    err(ctx.project.diags, "B5001", iterExpr.span,
      `@comptime for requires a compile-time-known array literal ; got ${iterLowered.kind}`);
    return { kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredUnreachable", span, type: TY.void, reason: "non-literal @comptime iter",
    } };
  }
  // Soft cap : the intended use is `@fields(T)` / `@type_args(T)` over
  // small struct signatures (N <= ~16). A literal `[0..1000]` would
  // silently emit 1000× the body — surface a diagnostic instead so the
  // footgun is loud.
  if (iterLowered.elements.length > COMPTIME_FOR_MAX_ITERS) {
    err(ctx.project.diags, "B5001", iterExpr.span,
      `@comptime for over ${iterLowered.elements.length} elements exceeds the unroll cap (${COMPTIME_FOR_MAX_ITERS})`);
    return { kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredUnreachable", span, type: TY.void, reason: "@comptime iter too large",
    } };
  }

  const unrolled: LoweredStmt[] = [];
  // Save/restore the prior binding for this symbol id so nested
  // `@comptime for` over the same name (or any other reentrancy) doesn't
  // silently clobber an outer scope's substitution.
  const prior = ctx.comptimeBindings.get(bindingSym.id);
  for (const elt of iterLowered.elements) {
    ctx.comptimeBindings.set(bindingSym.id, elt);
    const body = lowerBlock(ctx, stmt.body, /*isFnRoot*/ false, /*isLoopBody*/ false);
    unrolled.push(...blockStmtsWithTrailing(body));
  }
  if (prior === undefined) ctx.comptimeBindings.delete(bindingSym.id);
  else ctx.comptimeBindings.set(bindingSym.id, prior);
  return wrapStmts(span, unrolled);
}

export function lowerForIn(
  ctx: FnLowerCtx, stmt: A.ForStmt,
  iterExpr: A.Expr, bindingName: string, bindingSym: Symbol | undefined,
): LoweredStmt {
  const span = stmt.span;

  // Fast path : `for x in <lo>..<hi>` over an integer-typed range lowers to
  // a direct counter loop, skipping the Range struct allocation and the
  // per-iter `Iterator.next()` dispatch entirely. The slow path below stays
  // in place for non-literal ranges, ranges over non-integer Step types
  // (chars / user types), and any other iterable.
  if (iterExpr.kind === "RangeExpr") {
    const fast = tryLowerForInIntRange(ctx, stmt, iterExpr, bindingName, bindingSym);
    if (fast !== null) return fast;
  }

  // Fast path : `for x in <chain>` where `<chain>` is a vertical chain of
  // `std/iter` lazy combinators (struct literals or fluent
  // `it.map(f).filter(p)` calls) bottoming out in a `RangeExpr`. Fuses
  // the entire pipeline into a single counter loop — no Range / Yielded
  // / Done allocations, no virtual dispatch through `Iterator.next()`.
  // Falls back to the generic path when the pattern doesn't match
  // (chain source via a variable, pred/f that isn't a bare fn ref, …).
  if (iterExpr.kind === "StructLitExpr" || iterExpr.kind === "CallExpr") {
    const fused = tryLowerForInIterChainFusion(ctx, stmt, iterExpr, bindingName, bindingSym);
    if (fused !== null) return fused;
  }

  // Fast path : `for entry in m` over `MutableMap(K, V)` (or `for v in s`
  // over `MutableSet(T)`). Inlines the bucket-walk + chain-traversal that
  // `MapIterator.next()` / `SetIterator.next()` would do per call, so the
  // loop body sees the entry directly — no per-iter `Yield(...)` alloc, no
  // direct call, no MapIterator struct alloc. Mirrors the `Range` fast path's
  // role in avoiding the generic Iterator dispatch for a well-known shape.
  const mapSetInline = tryLowerForInMapSetIterInline(ctx, stmt, iterExpr, bindingName, bindingSym);
  if (mapSetInline !== null) return mapSetInline;

  let iterLowered = lowerExpr(ctx, iterExpr);
  let iterType = iterLowered.type;

  // Fast path : `for x in arr` over a raw `T[]` lowers to a direct counter
  // loop over indices — no `ArrayIterator(T)` wrapper, no per-iter
  // `Iterator.next()` dispatch, no `Yield(T)` allocation. Replaces the
  // older `wrapArrayAsIter` approach which broke under post-typecheck
  // erasure (the wrapped `ArrayIterator(T)` query would need an
  // Iterator impl entry for every Any-bearing T-shape reachable from an
  // erased decl). See `docs/STDLIB_GENERIC_COLLAPSE_PHASE2.md` §9
  // Issue 6.
  if (iterType.kind === "Array") {
    const inlined = lowerForInRawArray(
      ctx, stmt, iterLowered, iterType.element, bindingName, bindingSym, span,
    );
    if (inlined !== null) return inlined;
  }

  // Two dispatch paths :
  //   - concrete iter (e.g. `Range[i32]`, `ArrayIter[T]`) → look up the
  //     Iterator impl statically and emit a direct `LoweredCall`.
  //   - trait-typed iter (`Iterator(T)` itself, as produced by trait-arg
  //     coercion or an `Iterator(T)`-typed local) → emit `LoweredVirtualCall`
  //     so the runtime dispatches through the per-(trait, method) vtable
  //     by the receiver's concrete tag.
  const iteratorSym = findCoreTrait(ctx.project, CORE_TRAITS.Iterator);
  const traitTypedElement = iteratorSym !== null
    && iterType.kind === "Trait"
    && iterType.symbol.id === iteratorSym.id
    && iterType.args.length > 0
    ? iterType.args[0]!
    : null;
  const stepInfo = traitTypedElement === null ? findIteratorStepImpl(ctx, iterType) : null;
  if (traitTypedElement === null && stepInfo === null) {
    err(ctx.project.diags, "B5001", span,
      `\`for x in iter\` requires Iterator impl on ${displayType(iterType)} (deferred — see TODO §1.5b iterators)`);
    return { kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredUnreachable", span, type: TY.void,
      reason: `no Iterator impl on ${displayType(iterType)}`,
    } };
  }
  const elementType = traitTypedElement ?? stepInfo!.elementType;

  const yieldType = findCoreType(ctx, CORE_STRUCTS.Yield, [elementType]);
  if (yieldType === null) {
    err(ctx.project.diags, "B5001", span, "Yield missing from std/core");
    return { kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredUnreachable", span, type: TY.void, reason: "stdlib types missing",
    } };
  }

  if (bindingSym === undefined) {
    err(ctx.project.diags, "B5001", span, "for-in binding not resolved");
    return { kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredUnreachable", span, type: TY.void, reason: "missing binding",
    } };
  }

  const iterSym = freshSyntheticSymbol(ctx, "iter");
  const stepSym = freshSyntheticSymbol(ctx, "step");
  const stepUnion = unionOfYieldNull(yieldType);

  const setupStmts: LoweredStmt[] = [
    { kind: "LoweredLet", span, name: iterSym.name, symbol: iterSym, type: iterType, value: iterLowered },
  ];

  // next(__iter) — direct call for concrete iter, virtual dispatch for trait-typed.
  const iterRef: LoweredExpr = { kind: "LoweredIdent", span, type: iterType, symbol: iterSym };
  const stepCall: LoweredExpr = traitTypedElement !== null
    ? {
        kind: "LoweredVirtualCall", span, type: stepUnion,
        traitName: iteratorSym!.name, method: "next",
        receiver: iterRef, args: [],
      }
    : {
        kind: "LoweredCall", span, type: stepUnion,
        callee: { kind: "LoweredIdent", span, type: TY.unresolved, symbol: stepInfo!.fnSymbol },
        args: [iterRef],
      };

  // if (step is null) { break } else { x = step.value; <body> }
  const stepRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: stepUnion, symbol: stepSym,
  });
  const isDone: LoweredExpr = {
    kind: "LoweredTypeCheck", span, type: TY.bool, value: stepRef(), checkType: TY.null,
  };
  const breakStmt: LoweredStmt = { kind: "LoweredBreak", span, label: null };

  // Body branch: bind x = ((Yield*) __step).value, then run user body.
  const yieldCast: LoweredExpr = {
    kind: "LoweredCast", span, type: yieldType, value: stepRef(),
  };
  const valueAccess: LoweredExpr = {
    kind: "LoweredFieldAccess", span, type: elementType, target: yieldCast, field: "value",
  };
  const bindLet: LoweredStmt = {
    kind: "LoweredLet", span, name: bindingName, symbol: bindingSym,
    type: elementType, value: valueAccess,
  };
  const userBody = lowerBlock(ctx, stmt.body, /*isFnRoot*/ false, /*isLoopBody*/ true);

  const branchIf: LoweredStmt = {
    kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredIf", span, type: TY.void, cond: isDone,
      then: { kind: "LoweredBlock", span, type: TY.void, stmts: [breakStmt], trailing: null },
      else: {
        kind: "LoweredBlock", span, type: TY.void,
        stmts: [bindLet, ...blockStmtsWithTrailing(userBody)],
        trailing: null,
      },
    },
  };

  const stepLet: LoweredStmt = {
    kind: "LoweredLet", span, name: stepSym.name, symbol: stepSym,
    type: stepUnion, value: stepCall,
  };

  const loop: LoweredStmt = {
    kind: "LoweredLoop", span, label: stmt.label, cond: null,
    body: { kind: "LoweredBlock", span, type: TY.void, stmts: [stepLet, branchIf], trailing: null },
  };

  return wrapStmts(span, [...setupStmts, loop]);
}

/** Counter-loop lowering for `for x in <int_range>`. Returns null when the
 *  range's bound type isn't an integer ; caller falls back to the standard
 *  Iterator-dispatch path. The lower bound becomes the counter's initial
 *  value ; the upper bound is hoisted to a synthetic local if it isn't a
 *  cheap idempotent read (avoids recomputing a method call per iter). */
function tryLowerForInIntRange(
  ctx: FnLowerCtx, stmt: A.ForStmt, range: A.RangeExpr,
  bindingName: string, bindingSym: Symbol | undefined,
): LoweredStmt | null {
  if (bindingSym === undefined) return null;
  const loType = ctx.typed.exprTypes.get(range.lower);
  if (loType === undefined || !isInteger(loType)) return null;

  const span = stmt.span;
  const lo = lowerExpr(ctx, range.lower);
  const hi = lowerExpr(ctx, range.upper);

  const hoistStmts: LoweredStmt[] = [];
  let hiExpr: LoweredExpr = hi;
  if (!isCheapInvariant(hi)) {
    const hiSym = freshSyntheticSymbol(ctx, "for_hi");
    hoistStmts.push({
      kind: "LoweredLet", span, name: hiSym.name, symbol: hiSym,
      type: loType, value: hi,
    });
    hiExpr = { kind: "LoweredIdent", span, type: loType, symbol: hiSym };
  }

  const counterInit: LoweredStmt = {
    kind: "LoweredLet", span, name: bindingName, symbol: bindingSym,
    type: loType, value: lo,
  };
  const counterRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: loType, symbol: bindingSym,
  });
  const cmpOp: LoweredBinaryOp = range.inclusive ? "lte" : "lt";
  const cond: LoweredExpr = {
    kind: "LoweredBinary", span, type: TY.bool, op: cmpOp,
    left: counterRef(), right: hiExpr,
  };
  const incStmt: LoweredStmt = {
    kind: "LoweredAssign", span,
    target: counterRef(),
    value: {
      kind: "LoweredBinary", span, type: loType, op: "add",
      left: counterRef(),
      right: { kind: "LoweredIntLit", span, type: loType, value: 1n },
    },
  };

  const userBody = lowerBlock(ctx, stmt.body, /*isFnRoot*/ false, /*isLoopBody*/ true);
  // `continue` would otherwise skip the increment and spin on the same
  // counter value. Rewrite each `continue` that targets this loop to
  // `{ counter += 1 ; continue }` so the next iteration sees the next
  // value. Continues in nested loops keep their original target.
  const advancedBody = prependIncBeforeMatchingContinue(userBody, incStmt, stmt.label);

  const loopBody: LoweredBlock = {
    kind: "LoweredBlock", span, type: TY.void,
    stmts: [...blockStmtsWithTrailing(advancedBody), incStmt],
    trailing: null,
  };
  const loop: LoweredStmt = {
    kind: "LoweredLoop", span, label: stmt.label, cond, body: loopBody,
  };

  return wrapStmts(span, [...hoistStmts, counterInit, loop]);
}

/** Lower `for x in arr` over a raw `T[]` to a counter loop over indices.
 *  Equivalent to `for i in 0..<arr.len { let x = arr[i] ; <body> }`
 *  without ever materialising an `ArrayIterator(T)` struct. Saves an
 *  allocation per loop and — critically — removes a brittle dependency
 *  on `ArrayIterator(T)` having a registered Iterator impl for every
 *  Any-bearing `T` reachable from an erased decl. */
function lowerForInRawArray(
  ctx: FnLowerCtx, stmt: A.ForStmt,
  arrayLowered: LoweredExpr, elementType: Type,
  bindingName: string, bindingSym: Symbol | undefined,
  span: Span,
): LoweredStmt | null {
  if (bindingSym === undefined) return null;
  const arrayType = arrayLowered.type;
  if (arrayType.kind !== "Array") return null;

  const arrSym = freshSyntheticSymbol(ctx, "for_arr");
  const lenSym = freshSyntheticSymbol(ctx, "for_len");
  const idxSym = freshSyntheticSymbol(ctx, "for_i");

  const arrRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: arrayType, symbol: arrSym,
  });
  const lenRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: TY.usize, symbol: lenSym,
  });
  const idxRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: TY.usize, symbol: idxSym,
  });

  const setupStmts: LoweredStmt[] = [
    { kind: "LoweredLet", span, name: arrSym.name, symbol: arrSym, type: arrayType, value: arrayLowered },
    {
      kind: "LoweredLet", span, name: lenSym.name, symbol: lenSym, type: TY.usize,
      value: { kind: "LoweredArrayLen", span, type: TY.usize, target: arrRef() },
    },
    {
      kind: "LoweredLet", span, name: idxSym.name, symbol: idxSym, type: TY.usize,
      value: { kind: "LoweredIntLit", span, type: TY.usize, value: 0n },
    },
  ];

  const cond: LoweredExpr = {
    kind: "LoweredBinary", span, type: TY.bool, op: "lt",
    left: idxRef(), right: lenRef(),
  };

  const bindStmt: LoweredStmt = {
    kind: "LoweredLet", span, name: bindingName, symbol: bindingSym,
    type: elementType,
    value: { kind: "LoweredIndex", span, type: elementType, target: arrRef(), index: idxRef() },
  };

  const incStmt: LoweredStmt = {
    kind: "LoweredAssign", span,
    target: idxRef(),
    value: {
      kind: "LoweredBinary", span, type: TY.usize, op: "add",
      left: idxRef(),
      right: { kind: "LoweredIntLit", span, type: TY.usize, value: 1n },
    },
  };

  const userBody = lowerBlock(ctx, stmt.body, /*isFnRoot*/ false, /*isLoopBody*/ true);
  const advancedBody = prependIncBeforeMatchingContinue(userBody, incStmt, stmt.label);

  const loopBody: LoweredBlock = {
    kind: "LoweredBlock", span, type: TY.void,
    stmts: [bindStmt, ...blockStmtsWithTrailing(advancedBody), incStmt],
    trailing: null,
  };
  const loop: LoweredStmt = {
    kind: "LoweredLoop", span, label: stmt.label, cond, body: loopBody,
  };

  return wrapStmts(span, [...setupStmts, loop]);
}

// =========================================================================
// Iterator-chain fusion — `for x in MapIterator/FilterIterator { … }` over
// a literal Range bottom collapses into a single counter loop.
// =========================================================================

type IterChain =
  | { kind: "range"; lower: A.Expr; upper: A.Expr; inclusive: boolean; elementType: Type; span: Span }
  | { kind: "map"; source: IterChain; mapFn: A.Expr; outputType: Type; span: Span }
  | { kind: "filter"; source: IterChain; predFn: A.Expr; span: Span };

/** Recognise `for x in <chain> { body }` where `<chain>` is one or more
 *  std/iter lazy combinators (MapIterator / FilterIterator) wrapping a
 *  literal integer range, and fuse the whole pipeline into a single counter
 *  loop. Returns null whenever any layer of the pattern doesn't match :
 *
 *   - source field accessed via a variable (we only fuse when the source is
 *     written inline so we know its shape without dataflow),
 *   - pred / f field that isn't a bare fn reference (a lambda or arbitrary
 *     expression evaluated per call is correct on the slow path but expands
 *     to a closure with captures that the simple emission below can't unwrap),
 *   - bottom that isn't a `RangeExpr` of integer type (the simple range case
 *     is what Phase A already optimises ; arrays + custom iterators are
 *     future extensions).
 *
 *  Pattern that triggers the win :
 *      for x in MapIterator(i32, i64) {
 *          .source = FilterIterator(i32) { .source = 0..<N, .pred = is_even },
 *          .f      = square_i64,
 *      } { … }
 */
function tryLowerForInIterChainFusion(
  ctx: FnLowerCtx, stmt: A.ForStmt, iterExpr: A.Expr,
  bindingName: string, bindingSym: Symbol | undefined,
): LoweredStmt | null {
  if (bindingSym === undefined) return null;
  const chain = descendChain(ctx, iterExpr);
  if (chain === null) return null;
  // Only fire when there's at least one combinator above the range bottom.
  // A bare `for x in <range>` already hits Phase A ; emitting through the
  // chain path would just be slower (extra symbol allocations, hoists, …).
  if (chain.kind === "range") return null;

  const span = stmt.span;
  const userBody = lowerBlock(ctx, stmt.body, /*isFnRoot*/ false, /*isLoopBody*/ true);

  // The outermost binding receives the final element value (whatever type
  // came out of the topmost map). We declare it inline within the deepest
  // body so each fused iter rebinds.
  const elementType = chainElementType(chain);
  const makeBody = (valueSym: Symbol, _: Type): readonly LoweredStmt[] => {
    const bind: LoweredStmt = {
      kind: "LoweredLet", span, name: bindingName, symbol: bindingSym,
      type: elementType,
      value: { kind: "LoweredIdent", span, type: elementType, symbol: valueSym },
    };
    return [bind, ...blockStmtsWithTrailing(userBody)];
  };

  const stmts = emitFusedChain(ctx, chain, stmt.label, span, makeBody);
  return wrapStmts(span, stmts);
}

/** Step through the chain AST top-down. Each layer either matches a known
 *  std/iter combinator (struct lit with the source field inline OR a
 *  fluent `it.map(f)` / `it.filter(p)` call) or bottoms out at a Phase-A-
 *  eligible RangeExpr ; anything else returns null. */
function descendChain(ctx: FnLowerCtx, expr: A.Expr): IterChain | null {
  if (expr.kind === "RangeExpr") {
    const loType = ctx.typed.exprTypes.get(expr.lower);
    if (loType === undefined || !isInteger(loType)) return null;
    return { kind: "range", lower: expr.lower, upper: expr.upper, inclusive: expr.inclusive, elementType: loType, span: expr.span };
  }
  const iterSyms = ctx.project.iterSymbols;
  if (iterSyms === null) return null;
  const mapSym = iterSyms.get("MapIterator");
  const filterSym = iterSyms.get("FilterIterator");
  const exprType = ctx.typed.exprTypes.get(expr);
  if (exprType === undefined || exprType.kind !== "Struct") return null;

  if (expr.kind === "StructLitExpr") {
    if (mapSym !== undefined && exprType.symbol.id === mapSym.id) {
      const source = findInlineField(expr, "source");
      const mapFn = findInlineField(expr, "f");
      if (source === null || mapFn === null) return null;
      const inner = descendChain(ctx, source);
      if (inner === null) return null;
      const outputType = exprType.args[1];
      if (outputType === undefined) return null;
      return { kind: "map", source: inner, mapFn, outputType, span: expr.span };
    }
    if (filterSym !== undefined && exprType.symbol.id === filterSym.id) {
      const source = findInlineField(expr, "source");
      const predFn = findInlineField(expr, "pred");
      if (source === null || predFn === null) return null;
      const inner = descendChain(ctx, source);
      if (inner === null) return null;
      return { kind: "filter", source: inner, predFn, span: expr.span };
    }
    return null;
  }

  if (expr.kind === "CallExpr") {
    const fluent = unpackFluentCombinator(ctx, expr);
    if (fluent === null) return null;
    const inner = descendChain(ctx, fluent.receiver);
    if (inner === null) return null;
    if (mapSym !== undefined && exprType.symbol.id === mapSym.id) {
      const outputType = exprType.args[1];
      if (outputType === undefined) return null;
      return { kind: "map", source: inner, mapFn: fluent.fnArg, outputType, span: expr.span };
    }
    if (filterSym !== undefined && exprType.symbol.id === filterSym.id) {
      return { kind: "filter", source: inner, predFn: fluent.fnArg, span: expr.span };
    }
  }
  return null;
}

/** Recognise the fluent `it.map(f)` / `map(it, f)` / `it.filter(p)` /
 *  `filter(it, p)` shapes. Returns the receiver expr (the chain source)
 *  and the transform / predicate arg, or null when the call isn't one
 *  of the two fluent combinators we can fuse. The caller checks the
 *  call's return type to pick which combinator it is. */
function unpackFluentCombinator(
  ctx: FnLowerCtx, expr: A.CallExpr,
): { receiver: A.Expr; fnArg: A.Expr } | null {
  // UFCS form : `it.map(f)`. The callee is a FieldExpr whose target is
  // the receiver ; remaining args carry the transform / predicate.
  if (expr.callee.kind === "FieldExpr") {
    const fr = ctx.typed.fieldResolutions.get(expr.callee);
    if (fr?.kind !== "ufcs-free") return null;
    if (expr.args.length < 1) return null;
    return { receiver: expr.callee.target, fnArg: expr.args[0]!.value };
  }
  // Direct-call form : `map(it, f)`. The first arg is the receiver,
  // the second is the transform / predicate.
  if (expr.callee.kind === "IdentExpr") {
    if (expr.args.length < 2) return null;
    return { receiver: expr.args[0]!.value, fnArg: expr.args[1]!.value };
  }
  return null;
}

/** Look up a named field in a struct literal. Returns the field's value
 *  expression iff the entry is a plain field (no spread) — we don't try to
 *  reason about spreads here, so any spread aborts fusion. */
function findInlineField(lit: A.StructLitExpr, name: string): A.Expr | null {
  for (const item of lit.items) {
    if (item.kind === "spread") return null;
    if (item.name === name) return item.value;
  }
  return null;
}

function chainElementType(chain: IterChain): Type {
  switch (chain.kind) {
    case "range":  return chain.elementType;
    case "map":    return chain.outputType;
    case "filter": return chainElementType(chain.source);
  }
}

/** Emit a fused chain by recursively wrapping the body : the deepest source
 *  (a Range) yields values directly via a counter loop ; each map layer
 *  binds a `let mapped = f(prev)` ahead of the body it wraps ; each filter
 *  layer guards the body with `if pred(prev)`. */
function emitFusedChain(
  ctx: FnLowerCtx, chain: IterChain, loopLabel: string | null, outerSpan: Span,
  makeBody: (valueSym: Symbol, valueType: Type) => readonly LoweredStmt[],
): LoweredStmt[] {
  switch (chain.kind) {
    case "range":
      return emitFusedRange(ctx, chain, loopLabel, outerSpan, makeBody);
    case "map":
      return emitFusedChain(ctx, chain.source, loopLabel, outerSpan, (innerSym, innerType) => {
        const mapFnExpr = lowerExpr(ctx, chain.mapFn);
        const mappedSym = freshSyntheticSymbol(ctx, "mapped");
        const mapped: LoweredStmt = {
          kind: "LoweredLet", span: chain.span, name: mappedSym.name, symbol: mappedSym,
          type: chain.outputType,
          value: {
            kind: "LoweredCall", span: chain.span, type: chain.outputType,
            callee: mapFnExpr,
            args: [{ kind: "LoweredIdent", span: chain.span, type: innerType, symbol: innerSym }],
          },
        };
        return [mapped, ...makeBody(mappedSym, chain.outputType)];
      });
    case "filter":
      return emitFusedChain(ctx, chain.source, loopLabel, outerSpan, (innerSym, innerType) => {
        const predFnExpr = lowerExpr(ctx, chain.predFn);
        const cond: LoweredExpr = {
          kind: "LoweredCall", span: chain.span, type: TY.bool,
          callee: predFnExpr,
          args: [{ kind: "LoweredIdent", span: chain.span, type: innerType, symbol: innerSym }],
        };
        const inner = makeBody(innerSym, innerType);
        const ifStmt: LoweredStmt = {
          kind: "LoweredExprStmt", span: chain.span, expr: {
            kind: "LoweredIf", span: chain.span, type: TY.void, cond,
            then: { kind: "LoweredBlock", span: chain.span, type: TY.void, stmts: inner, trailing: null },
            else: null,
          },
        };
        return [ifStmt];
      });
  }
}

function emitFusedRange(
  ctx: FnLowerCtx, range: Extract<IterChain, { kind: "range" }>,
  loopLabel: string | null, outerSpan: Span,
  makeBody: (valueSym: Symbol, valueType: Type) => readonly LoweredStmt[],
): LoweredStmt[] {
  const span = range.span;
  const intType = range.elementType;
  const lo = lowerExpr(ctx, range.lower);
  const hi = lowerExpr(ctx, range.upper);

  const hoistStmts: LoweredStmt[] = [];
  let hiExpr: LoweredExpr = hi;
  if (!isCheapInvariant(hi)) {
    const hiSym = freshSyntheticSymbol(ctx, "for_hi");
    hoistStmts.push({
      kind: "LoweredLet", span, name: hiSym.name, symbol: hiSym, type: intType, value: hi,
    });
    hiExpr = { kind: "LoweredIdent", span, type: intType, symbol: hiSym };
  }

  const counterSym = freshSyntheticSymbol(ctx, "counter");
  const counterInit: LoweredStmt = {
    kind: "LoweredLet", span, name: counterSym.name, symbol: counterSym,
    type: intType, value: lo,
  };
  const counterRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: intType, symbol: counterSym,
  });
  const cmpOp: LoweredBinaryOp = range.inclusive ? "lte" : "lt";
  const cond: LoweredExpr = {
    kind: "LoweredBinary", span, type: TY.bool, op: cmpOp,
    left: counterRef(), right: hiExpr,
  };
  const incStmt: LoweredStmt = {
    kind: "LoweredAssign", span,
    target: counterRef(),
    value: {
      kind: "LoweredBinary", span, type: intType, op: "add",
      left: counterRef(),
      right: { kind: "LoweredIntLit", span, type: intType, value: 1n },
    },
  };

  const innerStmts = makeBody(counterSym, intType);
  const innerBlock: LoweredBlock = {
    kind: "LoweredBlock", span, type: TY.void,
    stmts: [...innerStmts], trailing: null,
  };
  // `continue` inside the user body would skip the increment without this
  // rewrite. The walker descends through the chain's synthetic if / block
  // wrappers and stops at any nested loop, matching Phase A's semantics.
  const advancedInner = prependIncBeforeMatchingContinue(innerBlock, incStmt, loopLabel);

  const loopBody: LoweredBlock = {
    kind: "LoweredBlock", span, type: TY.void,
    stmts: [...blockStmtsWithTrailing(advancedInner), incStmt], trailing: null,
  };
  const loop: LoweredStmt = {
    kind: "LoweredLoop", span: outerSpan, label: loopLabel, cond, body: loopBody,
  };

  return [...hoistStmts, counterInit, loop];
}

/** Reads cheap enough to inline into the loop condition (one read per iter).
 *  IntLit/CharLit are constants ; Idents and FieldAccesses are single memory
 *  loads with no side effect. Everything else hoists. */
function isCheapInvariant(e: LoweredExpr): boolean {
  return e.kind === "LoweredIdent"
    || e.kind === "LoweredFieldAccess"
    || e.kind === "LoweredIntLit"
    || e.kind === "LoweredCharLit";
}

/** Walks a block and prefixes `inc` before every `LoweredContinue` whose
 *  target is the loop we're emitting (matches when both labels are null, or
 *  when the continue's label matches `loopLabel`). Nested loops with their
 *  own labels intercept unlabeled continues, so we stop the rewrite at their
 *  body unless `loopLabel` is set and a labeled `continue loopLabel` could
 *  still target us through them. */
function prependIncBeforeMatchingContinue(
  block: LoweredBlock, inc: LoweredStmt, loopLabel: string | null,
): LoweredBlock {
  function matchesContinue(cLabel: string | null, insideNestedLoop: boolean): boolean {
    if (cLabel === null) return !insideNestedLoop && loopLabel === null;
    return cLabel === loopLabel;
  }

  function rewriteStmt(s: LoweredStmt, insideNestedLoop: boolean): LoweredStmt {
    switch (s.kind) {
      case "LoweredContinue":
        if (matchesContinue(s.label, insideNestedLoop)) {
          return {
            kind: "LoweredExprStmt", span: s.span,
            expr: {
              kind: "LoweredBlock", span: s.span, type: TY.void,
              stmts: [inc, s], trailing: null,
            },
          };
        }
        return s;
      case "LoweredLoop": {
        if (loopLabel === null) return s;       // no label → no labeled continue can target us
        return { ...s, body: rewriteBlock(s.body, /*insideNestedLoop*/ true) };
      }
      case "LoweredExprStmt":
        return { ...s, expr: rewriteExpr(s.expr, insideNestedLoop) };
      case "LoweredLet":
        return { ...s, value: rewriteExpr(s.value, insideNestedLoop) };
      case "LoweredAssign":
        return { ...s, target: rewriteExpr(s.target, insideNestedLoop), value: rewriteExpr(s.value, insideNestedLoop) };
      case "LoweredReturn":
        return s.value === null ? s : { ...s, value: rewriteExpr(s.value, insideNestedLoop) };
      case "LoweredCellSet":
        return { ...s, target: rewriteExpr(s.target, insideNestedLoop), value: rewriteExpr(s.value, insideNestedLoop) };
      case "LoweredBreak":
        return s;
      case "LoweredDeferPush":
        return { ...s, thunk: rewriteExpr(s.thunk, insideNestedLoop) };
      case "LoweredDeferPopExec":
        return s;
    }
  }

  function rewriteBlock(b: LoweredBlock, insideNestedLoop: boolean): LoweredBlock {
    return {
      ...b,
      stmts: b.stmts.map((s) => rewriteStmt(s, insideNestedLoop)),
      trailing: b.trailing === null ? null : rewriteExpr(b.trailing, insideNestedLoop),
    };
  }

  function rewriteExpr(e: LoweredExpr, insideNestedLoop: boolean): LoweredExpr {
    switch (e.kind) {
      case "LoweredBlock":
        return rewriteBlock(e, insideNestedLoop);
      case "LoweredIf":
        return {
          ...e,
          then: rewriteBlock(e.then, insideNestedLoop),
          else: e.else === null ? null : rewriteBlock(e.else, insideNestedLoop),
        };
      // Other expression kinds only contain sub-expressions, not stmts that
      // could carry a LoweredContinue — they don't need walking here.
      default:
        return e;
    }
  }

  return rewriteBlock(block, false);
}

// =========================================================================
// MutableMap / MutableSet iter inline — `for entry in m` / `for v in s` over
// a known map/set type emits a flat bucket-walk + chain-traversal loop
// instead of going through the generic `Iterator(...).next()` path.
// =========================================================================

/** Recognise `for entry in m { body }` where `m`'s static type is
 *  `MutableMap(K, V)` (or `MutableSet(T)` for the symmetric case) and
 *  emit the bucket / chain walk inline. Skips :
 *   - the `MapIterator(K, V)` struct allocation,
 *   - the per-iter `MapIterator.next()` call,
 *   - the per-iter `Yield(Entry(K, V))` allocation,
 *  collapsing the whole loop body into a single hot path.
 *
 *  Returns null when the source isn't a recognised map/set, or when
 *  std/collections / `Entry` aren't reachable in the project. */
function tryLowerForInMapSetIterInline(
  ctx: FnLowerCtx, stmt: A.ForStmt, iterExpr: A.Expr,
  bindingName: string, bindingSym: Symbol | undefined,
): LoweredStmt | null {
  if (bindingSym === undefined) return null;
  const collSyms = ctx.project.collectionsSymbols;
  if (collSyms === null) return null;

  // The into-coercion records both the source type (the user's map/set) and
  // the target trait — its presence tells us we're at a for-in site that
  // would otherwise route through the auto-wrap into-iterator path.
  const coercion = ctx.typed.intoCoercions.get(iterExpr);
  if (coercion === undefined) return null;
  const sourceType = ctx.types.apply(coercion.sourceType);
  if (sourceType.kind !== "Struct") return null;

  const mapStructSym = collSyms.get("MutableMap");
  const setStructSym = collSyms.get("MutableSet");
  const entrySym = collSyms.get("Entry");
  if (entrySym === undefined) return null;
  const isMap = mapStructSym !== undefined && sourceType.symbol.id === mapStructSym.id;
  const isSet = setStructSym !== undefined && sourceType.symbol.id === setStructSym.id;
  if (!isMap && !isSet) return null;

  // Resolve the type-param fillings for the Entry instantiation :
  //   - Map(K, V)  → Entry(K, V)  ; user binding ← entry
  //   - Set(T)     → Entry(T, bool); user binding ← entry.key
  const entryArgs: readonly Type[] = isMap
    ? sourceType.args
    : [sourceType.args[0]!, TY.bool];
  if (entryArgs.length !== 2) return null;
  const entryType = mkStruct(entrySym, entryArgs);
  const entryOrNull = mkUnion([entryType, TY.null]);
  const bucketsArrayType = mkArray(entryOrNull);
  const bindingValueType: Type = isMap ? entryType : sourceType.args[0]!;

  const span = stmt.span;

  // All bailout conditions cleared above — commit to the inline. The iter
  // expr is lowered exactly once here (would be re-lowered by the standard
  // path if we returned null after this point, doubling capture-analysis
  // side effects). The `intoCoercion` we verified means `wrapAsInto` will
  // produce `LoweredCall { callee, args: [src] }` — peel `args[0]` to get
  // the bare `MutableMap` / `MutableSet` value.
  const wrappedIter = lowerExpr(ctx, iterExpr);
  const srcLowered: LoweredExpr =
    wrappedIter.kind === "LoweredCall" && wrappedIter.args.length === 1
      ? wrappedIter.args[0]!
      : wrappedIter;

  // Hoist the source value once. Avoids re-evaluating `iterExpr` (which
  // could be a call) every time we read .buckets / .inner.buckets below,
  // and gives the bucket array its own slot for fast indexing.
  const srcSym = freshSyntheticSymbol(ctx, "iter_src");
  const srcRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: sourceType, symbol: srcSym,
  });
  const srcLet: LoweredStmt = {
    kind: "LoweredLet", span, name: srcSym.name, symbol: srcSym,
    type: sourceType, value: srcLowered,
  };

  let bucketsExpr: LoweredExpr;
  if (isMap) {
    bucketsExpr = {
      kind: "LoweredFieldAccess", span, type: bucketsArrayType,
      target: srcRef(), field: "buckets",
    };
  } else {
    const innerMapType = mapStructSym !== undefined
      ? mkStruct(mapStructSym, entryArgs)
      : TY.unresolved;
    const innerAccess: LoweredExpr = {
      kind: "LoweredFieldAccess", span, type: innerMapType,
      target: srcRef(), field: "inner",
    };
    bucketsExpr = {
      kind: "LoweredFieldAccess", span, type: bucketsArrayType,
      target: innerAccess, field: "buckets",
    };
  }
  const bucketsSym = freshSyntheticSymbol(ctx, "iter_buckets");
  const bucketsRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: bucketsArrayType, symbol: bucketsSym,
  });
  const bucketsLet: LoweredStmt = {
    kind: "LoweredLet", span, name: bucketsSym.name, symbol: bucketsSym,
    type: bucketsArrayType, value: bucketsExpr,
  };

  const bucketsLenSym = freshSyntheticSymbol(ctx, "iter_buckets_len");
  const bucketsLenRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: TY.usize, symbol: bucketsLenSym,
  });
  const bucketsLenLet: LoweredStmt = {
    kind: "LoweredLet", span, name: bucketsLenSym.name, symbol: bucketsLenSym,
    type: TY.usize,
    value: { kind: "LoweredArrayLen", span, type: TY.usize, target: bucketsRef() },
  };

  const bucketCursorSym = freshSyntheticSymbol(ctx, "iter_bucket");
  const bucketCursorRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: TY.usize, symbol: bucketCursorSym,
  });
  const bucketCursorLet: LoweredStmt = {
    kind: "LoweredLet", span, name: bucketCursorSym.name, symbol: bucketCursorSym,
    type: TY.usize,
    value: { kind: "LoweredIntLit", span, type: TY.usize, value: 0n },
  };

  const chainCursorSym = freshSyntheticSymbol(ctx, "iter_chain");
  const chainCursorRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: entryOrNull, symbol: chainCursorSym,
  });
  const chainCursorLet: LoweredStmt = {
    kind: "LoweredLet", span, name: chainCursorSym.name, symbol: chainCursorSym,
    type: entryOrNull,
    value: { kind: "LoweredNullLit", span, type: TY.null },
  };

  const chainIsNull: LoweredExpr = {
    kind: "LoweredTypeCheck", span, type: TY.bool, value: chainCursorRef(), checkType: TY.null,
  };

  const bucketOob: LoweredExpr = {
    kind: "LoweredBinary", span, type: TY.bool, op: "gte",
    left: bucketCursorRef(), right: bucketsLenRef(),
  };
  const breakStmt: LoweredStmt = { kind: "LoweredBreak", span, label: null };
  const oobIf: LoweredStmt = {
    kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredIf", span, type: TY.void, cond: bucketOob,
      then: { kind: "LoweredBlock", span, type: TY.void, stmts: [breakStmt], trailing: null },
      else: null,
    },
  };
  const chainAdvance: LoweredStmt = {
    kind: "LoweredAssign", span, target: chainCursorRef(),
    value: {
      kind: "LoweredIndex", span, type: entryOrNull,
      target: bucketsRef(), index: bucketCursorRef(),
    },
  };
  const bucketInc: LoweredStmt = {
    kind: "LoweredAssign", span, target: bucketCursorRef(),
    value: {
      kind: "LoweredBinary", span, type: TY.usize, op: "add",
      left: bucketCursorRef(),
      right: { kind: "LoweredIntLit", span, type: TY.usize, value: 1n },
    },
  };
  const advanceBranch: LoweredBlock = {
    kind: "LoweredBlock", span, type: TY.void,
    stmts: [oobIf, chainAdvance, bucketInc], trailing: null,
  };

  // Step the chain cursor BEFORE running the user body so a `continue`
  // inside the body doesn't strand us re-reading the same node forever.
  const entryTmpSym = freshSyntheticSymbol(ctx, "iter_entry");
  const entryTmpRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: entryType, symbol: entryTmpSym,
  });
  const entryCast: LoweredExpr = {
    kind: "LoweredCast", span, type: entryType, value: chainCursorRef(),
  };
  const entryTmpLet: LoweredStmt = {
    kind: "LoweredLet", span, name: entryTmpSym.name, symbol: entryTmpSym,
    type: entryType, value: entryCast,
  };
  const chainStep: LoweredStmt = {
    kind: "LoweredAssign", span, target: chainCursorRef(),
    value: {
      kind: "LoweredFieldAccess", span, type: entryOrNull,
      target: entryTmpRef(), field: "next",
    },
  };
  const bindValue: LoweredExpr = isMap
    ? entryTmpRef()
    : { kind: "LoweredFieldAccess", span, type: bindingValueType, target: entryTmpRef(), field: "key" };
  const bindingLet: LoweredStmt = {
    kind: "LoweredLet", span, name: bindingName, symbol: bindingSym,
    type: bindingValueType, value: bindValue,
  };
  const userBody = lowerBlock(ctx, stmt.body, /*isFnRoot*/ false, /*isLoopBody*/ true);
  const bodyBranch: LoweredBlock = {
    kind: "LoweredBlock", span, type: TY.void,
    stmts: [entryTmpLet, chainStep, bindingLet, ...blockStmtsWithTrailing(userBody)],
    trailing: null,
  };

  const stepIf: LoweredStmt = {
    kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredIf", span, type: TY.void, cond: chainIsNull,
      then: advanceBranch, else: bodyBranch,
    },
  };

  const loop: LoweredStmt = {
    kind: "LoweredLoop", span, label: stmt.label, cond: null,
    body: { kind: "LoweredBlock", span, type: TY.void, stmts: [stepIf], trailing: null },
  };

  return wrapStmts(span, [
    srcLet, bucketsLet, bucketsLenLet, bucketCursorLet, chainCursorLet, loop,
  ]);
}

interface StepImpl {
  readonly fnSymbol: Symbol;
  readonly elementType: Type;
}

/** Locate the `Iterator(T)::step` impl on the iter's static type and pull out
 *  the materialised fn symbol + element type. Walks the impl registry for an
 *  impl whose forSymbol matches and whose trait is `Iterator`. */
function findIteratorStepImpl(ctx: FnLowerCtx, iterType: Type): StepImpl | null {
  const iteratorSym = findCoreTrait(ctx.project, CORE_TRAITS.Iterator);
  if (iteratorSym === null) return null;
  const structArgs = iterType.kind === "Struct" ? iterType.args : [];
  const entry = lookupImplFor(ctx.project, iterType, iteratorSym);
  if (entry === null) return null;
  const stepDecl = entry.decl.members.find((m) => m.name === "next");
  if (stepDecl === undefined) return null;
  const monoEntry = lookupImplEntry(ctx, stepDecl, structArgs);
  if (monoEntry === null || monoEntry.symbol === null) return null;
  let elementType: Type = TY.unresolved;
  if (entry.decl.traitArgs.length > 0) {
    const arg = ctx.typed.typeExprTypes.get(entry.decl.traitArgs[0]!);
    if (arg !== undefined) elementType = substitute(arg, monoEntry.subst);
  }
  return { fnSymbol: monoEntry.symbol, elementType };
}

/** Thin alias kept so for-in callers don't reach into `ctx.impls` directly.
 *  Identity is `ImplRegistry.findFor` ; the wrapper is here to absorb the
 *  `LowerProjectCtx` indirection at call sites. */
export function lookupImplFor(
  ctx: LowerProjectCtx, forType: Type, traitSym: Symbol,
): ImplEntry | null {
  return ctx.impls.findFor(forType, traitSym);
}

export function lookupImplEntry(ctx: FnLowerCtx, member: A.FnDecl, args: readonly Type[]): MonoEntry | null {
  const inner = ctx.project.mono.implMethodEntries.get(member);
  if (inner === undefined) return null;
  // First try the per-args specialised entry. If the impl's host struct is
  // erased (no `@specialize`), the entry was emitted under `ERASED_KEY`
  // instead — fall back to that.
  return inner.get(canonicalArgsKey(args)) ?? inner.get(ERASED_KEY) ?? null;
}

/** Wrap a `[T]`-typed lowered expression into an `ArrayIterator(T)` struct
 *  literal. Returns `null` when std/core's `ArrayIterator` can't be located —
 *  caller falls back to the unwrapped expression. Shared between for-in's
 *  iter auto-wrap and the `arrayIterCoercions` site (call args, let / return
 *  slots typed as `Iterator(T)`).
 *
 *  Two spans are accepted so call sites can attribute the synthetic struct
 *  lit to the original array expression (`outerSpan`) while the synthetic
 *  cursor sub-node stays attached to the surrounding stmt (`innerSpan`)
 *  — matches the for-in lowering's existing diagnostic anchoring. */
export function wrapArrayAsIter(
  ctx: FnLowerCtx, arrLowered: LoweredExpr, element: Type,
  outerSpan: Span, innerSpan: Span = outerSpan,
): LoweredExpr | null {
  const arrayIterType = findCoreType(ctx, CORE_STRUCTS.ArrayIterator, [element]);
  if (arrayIterType === null) return null;
  return {
    kind: "LoweredStructLit", span: outerSpan, type: arrayIterType,
    fields: [
      { name: "arr",    value: arrLowered },
      { name: "cursor", value: { kind: "LoweredIntLit", span: innerSpan, type: TY.usize, value: 0n } },
    ],
  };
}
