// Desugars `for x in iter` into the Iterator-step loop. Auto-wraps `[T]`
// arrays into `ArrayIter(T)` and resolves the matching `step` impl via the
// ImplRegistry. Also lowers `RangeExpr` into a `Range` struct literal so
// for-in can dispatch through the same Iterator path.

import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { ImplEntry } from "../../typecheck/impls.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_STRUCTS, CORE_TRAITS, TY, displayType, substitute } from "../../typecheck/types.ts";
import type { MonoEntry } from "../../monomorphize/index.ts";

import type { FnLowerCtx, LowerProjectCtx } from "../ctx.ts";
import { err } from "../diag.ts";
import type { LoweredExpr, LoweredStmt } from "../lowered-ast.ts";

import { lowerBlock } from "./block.ts";
import { findCoreTrait, findCoreType, unionOfDoneYielded } from "./core.ts";
import { lowerExpr } from "./expr.ts";
import { blockStmtsWithTrailing, freshSyntheticSymbol, wrapStmts } from "./helpers.ts";

/** Desugar `RangeExpr` (`a..<b` / `a..=b`) into a `Range` struct literal so
 *  `for-in` can dispatch through the standard Iterator impl rather than a
 *  bespoke fast path. The struct's fields mirror `std/core::Range`. */
export function lowerRangeExpr(ctx: FnLowerCtx, expr: A.RangeExpr, exprType: Type): LoweredExpr {
  const span = expr.span;
  const lower = lowerExpr(ctx, expr.lower);
  const upper = lowerExpr(ctx, expr.upper);
  const zero: LoweredExpr = { kind: "LoweredIntLit", span, type: TY.i32, value: 0n };
  const inclusive: LoweredExpr = {
    kind: "LoweredBoolLit", span, type: TY.bool, value: expr.inclusive,
  };
  return {
    kind: "LoweredStructLit", span, type: exprType,
    fields: [
      { name: "start",     value: lower },
      { name: "end",       value: upper },
      { name: "inclusive", value: inclusive },
      { name: "cursor",    value: zero },
    ],
  };
}

/** Desugar `for x in <iter>` into a step-loop dispatched through the
 *  Iterator impl on `iter`'s static type. Range and other iterables share
 *  this path; the caller-side iter is lowered first so `RangeExpr` becomes a
 *  `Range` struct literal before we look up its Iterator impl.
 */
export function lowerForIn(ctx: FnLowerCtx, stmt: A.ForStmt): LoweredStmt {
  if (stmt.form.kind !== "in") throw new Error("lowerForIn called on non-`in` form");
  const span = stmt.span;
  const iterExpr = stmt.form.iter;
  let iterLowered = lowerExpr(ctx, iterExpr);
  let iterType = iterLowered.type;

  // Auto-wrap raw arrays into `ArrayIter(T)` so users can write
  // `for x in arr` without an explicit `.iter()`. The struct literal
  // captures the array, sets cursor=0, and pre-computes the length via the
  // `array.len` op (no generic `len(arr)` fn needed).
  if (iterType.kind === "Array") {
    const arrayIterType = findCoreType(ctx, CORE_STRUCTS.ArrayIter, [iterType.element]);
    if (arrayIterType !== null) {
      iterLowered = {
        kind: "LoweredStructLit", span: iterExpr.span, type: arrayIterType,
        fields: [
          { name: "arr",    value: iterLowered },
          { name: "cursor", value: { kind: "LoweredIntLit", span, type: TY.i32, value: 0n } },
          { name: "length", value: {
            kind: "LoweredArrayLen", span, type: TY.i32, target: iterLowered,
          } },
        ],
      };
      iterType = arrayIterType;
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

  const bindingSym = ctx.typed.resolved.forIns.get(stmt);
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
    kind: "LoweredLet", span, name: stmt.form.binding, symbol: bindingSym,
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
  const stepDecl = entry.decl.members.find((m) => m.name === "step");
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

/** O(1) lookup of an impl entry by `(forType, traitSym)`. Returns null when
 *  no matching impl exists. */
export function lookupImplFor(
  ctx: LowerProjectCtx, forType: Type, traitSym: Symbol,
): ImplEntry | null {
  if (forType.kind === "Struct") return ctx.impls.findUser(forType.symbol, traitSym);
  if (forType.kind === "Primitive") return ctx.impls.forPrimitive(forType.name, traitSym);
  return null;
}

export function lookupImplEntry(ctx: FnLowerCtx, member: A.FnDecl, args: readonly Type[]): MonoEntry | null {
  const inner = ctx.project.mono.implMethodEntries.get(member);
  if (inner === undefined) return null;
  const key = args.map(displayType).join(",");
  return inner.get(key) ?? null;
}
