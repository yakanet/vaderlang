// Desugars `for x in iter` into the Iterator-step loop. Auto-wraps `[T]`
// arrays into `ArrayIter(T)` and resolves the matching `step` impl via the
// ImplRegistry. Also lowers `RangeExpr` into a `Range` struct literal so
// for-in can dispatch through the same Iterator path.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { ImplEntry } from "../../typecheck/impls.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_STRUCTS, CORE_TRAITS, TY, displayType, substitute } from "../../typecheck/types.ts";
import type { MonoEntry } from "../../comptime/specialize.ts";

import type { FnLowerCtx, LowerProjectCtx } from "../ctx.ts";
import { err } from "../diag.ts";
import type { LoweredExpr, LoweredStmt } from "../lowered-ast.ts";

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

  const stepInfo = findIteratorStepImpl(ctx, iterType);
  if (stepInfo === null) {
    err(ctx.project.diags, "B5001", span,
      `\`for x in iter\` requires Iterator impl on ${displayType(iterType)} (deferred — see TODO §1.5b iterators)`);
    return { kind: "LoweredExprStmt", span, expr: {
      kind: "LoweredUnreachable", span, type: TY.void,
      reason: `no Iterator impl on ${displayType(iterType)}`,
    } };
  }

  const elementType = stepInfo.elementType;
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

  // step(__iter)
  const stepCall: LoweredExpr = {
    kind: "LoweredCall", span, type: stepUnion,
    callee: {
      kind: "LoweredIdent", span, type: TY.unresolved, symbol: stepInfo.fnSymbol,
    },
    args: [{ kind: "LoweredIdent", span, type: iterType, symbol: iterSym }],
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
  const key = args.map(displayType).join(",");
  return inner.get(key) ?? null;
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
