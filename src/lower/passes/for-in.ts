// Desugars `for x in iter` into the Iterator-step loop. Auto-wraps `[T]`
// arrays into `ArrayIter(T)` and resolves the matching `step` impl via the
// ImplRegistry. Also lowers `RangeExpr` into a `Range` struct literal so
// for-in can dispatch through the same Iterator path.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { ImplEntry } from "../../typecheck/impls.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_STRUCTS, CORE_TRAITS, TY, canonicalArgsKey, displayType, isInteger, substitute } from "../../typecheck/types.ts";
import type { MonoEntry } from "../../comptime/specialize.ts";

import type { FnLowerCtx, LowerProjectCtx } from "../ctx.ts";
import { err } from "../diag.ts";
import type { LoweredBinaryOp, LoweredBlock, LoweredExpr, LoweredStmt } from "../lowered-ast.ts";

import { lowerBlock } from "./block.ts";
import { findCoreTrait, findCoreType, unionOfDoneYielded } from "./core.ts";
import { lowerExpr } from "./expr.ts";
import { blockStmtsWithTrailing, freshSyntheticSymbol, wrapStmts } from "./helpers.ts";

/** Pure reads — referencing them twice is a no-op at the bytecode level
 *  (`local.get` / `struct.get` etc.). Anything else (calls, allocations,
 *  arithmetic) must be hoisted to a temp before being shared. */
function isIdempotentRead(e: LoweredExpr): boolean {
  return e.kind === "LoweredIdent" || e.kind === "LoweredFieldAccess";
}

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

  let iterLowered = lowerExpr(ctx, iterExpr);
  let iterType = iterLowered.type;

  // Auto-wrap raw arrays into `ArrayIter(T)` so users can write
  // `for x in arr` without an explicit `.iter()`. The struct literal
  // captures the array, sets cursor=0, and pre-computes the length via the
  // `array.len` op (no generic `len(arr)` fn needed).
  if (iterType.kind === "Array") {
    const wrapped = wrapArrayAsIter(ctx, iterLowered, iterType.element, iterExpr.span, span);
    if (wrapped !== null) {
      iterLowered = wrapped;
      iterType = wrapped.type;
    }
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

  const doneType = findCoreType(ctx, CORE_STRUCTS.Done, []);
  const yieldedType = findCoreType(ctx, CORE_STRUCTS.Yielded, [elementType]);
  if (doneType === null || yieldedType === null) {
    err(ctx.project.diags, "B5001", span, "Done / Yielded missing from std/core");
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
  const stepUnion = unionOfDoneYielded(doneType, yieldedType);

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

  // if (step is Done) { break } else { x = step.value; <body> }
  const stepRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span, type: stepUnion, symbol: stepSym,
  });
  const isDone: LoweredExpr = {
    kind: "LoweredTypeCheck", span, type: TY.bool, value: stepRef(), checkType: doneType,
  };
  const breakStmt: LoweredStmt = { kind: "LoweredBreak", span, label: null };

  // Body branch: bind x = ((Yielded*) __step).value, then run user body.
  const yieldedCast: LoweredExpr = {
    kind: "LoweredCast", span, type: yieldedType, value: stepRef(),
  };
  const valueAccess: LoweredExpr = {
    kind: "LoweredFieldAccess", span, type: elementType, target: yieldedCast, field: "value",
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
  return inner.get(canonicalArgsKey(args)) ?? null;
}

/** Wrap a `[T]`-typed lowered expression into an `ArrayIter(T)` struct
 *  literal. Returns `null` when std/core's `ArrayIter` can't be located —
 *  caller falls back to the unwrapped expression. Shared between for-in's
 *  iter auto-wrap and the `arrayIterCoercions` site (call args, let / return
 *  slots typed as `Iterator(T)`).
 *
 *  Why hoist : the struct lit needs the array as both a field value and the
 *  target of an `array.len`. Letting the same node appear twice would emit
 *  the source expression twice — fine for a `LoweredIdent` read, but a
 *  function call or fresh `[…]` literal would run twice and the iterator
 *  would point at a different array than its `length` was computed from.
 *
 *  Two spans are accepted so call sites can attribute the synthetic struct
 *  lit to the original array expression (`outerSpan`) while the synthetic
 *  cursor/length sub-nodes stay attached to the surrounding stmt (`innerSpan`)
 *  — matches the for-in lowering's existing diagnostic anchoring. */
export function wrapArrayAsIter(
  ctx: FnLowerCtx, arrLowered: LoweredExpr, element: Type,
  outerSpan: Span, innerSpan: Span = outerSpan,
): LoweredExpr | null {
  const arrayIterType = findCoreType(ctx, CORE_STRUCTS.ArrayIterator, [element]);
  if (arrayIterType === null) return null;
  const ref = isIdempotentRead(arrLowered) ? arrLowered : null;
  if (ref !== null) return buildArrayIterLit(arrayIterType, ref, ref, outerSpan, innerSpan);
  const tmp = freshSyntheticSymbol(ctx, "arr");
  const tmpRef = (): LoweredExpr => ({
    kind: "LoweredIdent", span: outerSpan, type: arrLowered.type, symbol: tmp,
  });
  return {
    kind: "LoweredBlock", span: outerSpan, type: arrayIterType,
    stmts: [{
      kind: "LoweredLet", span: outerSpan, name: tmp.name, symbol: tmp,
      type: arrLowered.type, value: arrLowered,
    }],
    trailing: buildArrayIterLit(arrayIterType, tmpRef(), tmpRef(), outerSpan, innerSpan),
  };
}

function buildArrayIterLit(
  arrayIterType: Type, arrField: LoweredExpr, arrForLen: LoweredExpr,
  outerSpan: Span, innerSpan: Span,
): LoweredExpr {
  return {
    kind: "LoweredStructLit", span: outerSpan, type: arrayIterType,
    fields: [
      { name: "arr",    value: arrField },
      { name: "cursor", value: { kind: "LoweredIntLit", span: innerSpan, type: TY.usize, value: 0n } },
      { name: "length", value: {
        kind: "LoweredArrayLen", span: innerSpan, type: TY.usize, target: arrForLen,
      } },
    ],
  };
}
