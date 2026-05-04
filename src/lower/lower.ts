// Lowering pass — implements SPEC §2 "Lowered AST".

import type * as A from "../parser/ast.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type { EvaluatedProject } from "../comptime/evaluated-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProgram } from "../typecheck/typed-ast.ts";
import type { ImplRegistry } from "../typecheck/impls.ts";
import { buildImplRegistry } from "../typecheck/impls.ts";
import type { Substitution, Type } from "../typecheck/types.ts";
import { CORE_TRAITS, TY, defaultIfFree, substitute } from "../typecheck/types.ts";

import type { MonoEntry, MonoProject } from "../monomorphize/index.ts";
import { monomorphizeProject } from "../monomorphize/index.ts";

import type {
  LoweredBlock, LoweredDecl, LoweredExpr, LoweredFnDecl, LoweredIf,
  LoweredModule, LoweredParam, LoweredProject, LoweredStmt, LoweredStructLitField,
} from "./lowered-ast.ts";
import { INTRINSICS } from "./lowered-ast.ts";

const STD_CORE_PATH = "std/core";

export function lowerProject(evaluated: EvaluatedProject): LoweredProject {
  const mono = monomorphizeProject(evaluated);
  const impls = buildImplRegistry(evaluated.typed.resolved);
  const ctx: LowerProjectCtx = {
    evaluated, mono, impls,
    coreTraitCache: new Map(),
    nextSyntheticId: 1,
  };

  const byModule = new Map<string, LoweredDecl[]>();
  for (const entry of mono.entries) {
    const mid = entry.module.module.id;
    let bucket = byModule.get(mid);
    if (bucket === undefined) { bucket = []; byModule.set(mid, bucket); }
    const decl = lowerEntry(entry, ctx);
    if (decl !== null) bucket.push(decl);
  }

  const modules = new Map<string, LoweredModule>();
  for (const [mid, decls] of byModule) {
    const program = ctx.evaluated.typed.modules.get(mid);
    if (program === undefined) continue;
    modules.set(mid, {
      moduleId: mid,
      displayPath: program.resolved.module.displayPath,
      decls,
    });
  }
  return { modules };
}

interface LowerProjectCtx {
  readonly evaluated: EvaluatedProject;
  readonly mono: MonoProject;
  readonly impls: ImplRegistry;
  readonly coreTraitCache: Map<string, Symbol | null>;
  nextSyntheticId: number;
}

interface BlockCtx {
  /** Defers registered in this block, in encounter order. Re-emitted in reverse at every exit. */
  readonly defers: A.Stmt[];
  readonly isFnRoot: boolean;
  readonly isLoopBody: boolean;
}

interface FnLowerCtx {
  readonly project: LowerProjectCtx;
  readonly entry: MonoEntry;
  readonly typed: TypedProgram;
  readonly subst: Substitution;
  readonly returnType: Type;
  readonly selfType: Type | null;
  readonly blocks: BlockCtx[];
  uniq: number;
}

// ---------------------------------------------------------------- decls

function lowerEntry(entry: MonoEntry, ctx: LowerProjectCtx): LoweredDecl | null {
  switch (entry.decl.kind) {
    case "FnDecl":     return lowerFnEntry(entry, entry.decl, ctx, /*selfType*/ null);
    case "StructDecl": return lowerStructEntry(entry, entry.decl, ctx);
    case "ConstDecl":  return lowerConstEntry(entry, entry.decl, ctx);
    case "ImplDecl":   return null;       // members surface via the per-member entries
  }
}

function lowerFnEntry(
  entry: MonoEntry, fn: A.FnDecl, ctx: LowerProjectCtx, selfType: Type | null,
): LoweredFnDecl | null {
  const typed = ctx.evaluated.typed.modules.get(entry.module.module.id);
  if (typed === undefined) return null;
  const subst = entry.subst;

  const params: LoweredParam[] = [];
  for (const p of fn.params) {
    const declared = typed.paramTypes.get(p) ?? TY.unresolved;
    const sym = typed.resolved.params.get(p);
    if (sym === undefined) continue;
    params.push({ name: p.name, symbol: sym, type: applySubst(declared, subst) });
  }

  const fnType = typed.declTypes.get(fn);
  const returnType = fnType?.kind === "Fn" ? applySubst(fnType.returnType, subst) : TY.unresolved;

  const body = fn.body === null ? null : lowerBlock({
    project: ctx, entry, typed, subst, returnType, selfType, blocks: [], uniq: 0,
  }, fn.body, /*isFnRoot*/ true, /*isLoopBody*/ false);

  return {
    kind: "LoweredFnDecl",
    mangled: entry.mangled,
    params, returnType, body,
    origin: entry,
  };
}

function lowerStructEntry(entry: MonoEntry, struct: A.StructDecl, ctx: LowerProjectCtx): LoweredDecl | null {
  const typed = ctx.evaluated.typed.modules.get(entry.module.module.id);
  if (typed === undefined) return null;
  return {
    kind: "LoweredStructDecl",
    mangled: entry.mangled,
    fields: struct.fields.map((f) => ({
      name: f.name,
      type: applySubst(typed.typeExprTypes.get(f.type) ?? TY.unresolved, entry.subst),
    })),
    origin: entry,
  };
}

function lowerConstEntry(entry: MonoEntry, decl: A.ConstDecl, ctx: LowerProjectCtx): LoweredDecl | null {
  const typed = ctx.evaluated.typed.modules.get(entry.module.module.id);
  if (typed === undefined) return null;
  const type = applySubst(typed.exprTypes.get(decl.value) ?? TY.unresolved, entry.subst);
  const fnCtx: FnLowerCtx = {
    project: ctx, entry, typed, subst: entry.subst,
    returnType: type, selfType: null, blocks: [], uniq: 0,
  };
  return {
    kind: "LoweredConstDecl",
    mangled: entry.mangled,
    type,
    value: lowerExpr(fnCtx, decl.value),
    origin: entry,
  };
}

// ---------------------------------------------------------------- blocks & defers

function lowerBlock(
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

// ---------------------------------------------------------------- statements

function lowerStmt(ctx: FnLowerCtx, stmt: A.Stmt): LoweredStmt | null {
  switch (stmt.kind) {
    case "LetStmt": {
      const value = lowerExpr(ctx, stmt.value);
      const type = applySubst(ctx.typed.localTypes.get(stmt) ?? defaultIfFree(value.type), ctx.subst);
      const sym = ctx.typed.resolved.locals.get(stmt);
      if (sym === undefined) return null;
      return { kind: "LoweredLet", span: stmt.span, name: stmt.name, symbol: sym, type, value };
    }
    case "AssignStmt":
      return {
        kind: "LoweredAssign", span: stmt.span,
        target: lowerExpr(ctx, stmt.target),
        value: lowerExpr(ctx, stmt.value),
      };
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
      const cond = stmt.form.kind === "while" ? lowerExpr(ctx, stmt.form.cond) : null;
      // for-x-in / range loops require Iterator dispatch (deferred — see TODO §1.5b).
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

/** Pack a sequence of statements into a single statement, transparent to control flow. */
function wrapStmts(span: Span, stmts: readonly LoweredStmt[]): LoweredStmt {
  if (stmts.length === 1) return stmts[0]!;
  return {
    kind: "LoweredExprStmt", span,
    expr: { kind: "LoweredBlock", span, type: TY.void, stmts, trailing: null },
  };
}

// ---------------------------------------------------------------- expressions

function lowerExpr(ctx: FnLowerCtx, expr: A.Expr): LoweredExpr {
  const exprType = applySubst(ctx.typed.exprTypes.get(expr) ?? TY.unresolved, ctx.subst);
  switch (expr.kind) {
    case "IntLitExpr":
      return { kind: "LoweredIntLit", span: expr.span, type: defaultIfFree(exprType), value: expr.value };
    case "FloatLitExpr":
      return { kind: "LoweredFloatLit", span: expr.span, type: defaultIfFree(exprType), value: expr.value };
    case "BoolLitExpr":
      return { kind: "LoweredBoolLit", span: expr.span, type: TY.bool, value: expr.value };
    case "NullLitExpr":
      return { kind: "LoweredNullLit", span: expr.span, type: TY.null };
    case "CharLitExpr":
      return { kind: "LoweredCharLit", span: expr.span, type: TY.char, value: expr.value };
    case "StringLitExpr":
      return lowerStringLit(ctx, expr);
    case "IdentExpr":
      return lowerIdent(ctx, expr, exprType);
    case "CallExpr":
      return {
        kind: "LoweredCall", span: expr.span, type: exprType,
        callee: lowerExpr(ctx, expr.callee),
        args: expr.args.map((a) => lowerExpr(ctx, a.value)),
      };
    case "FieldExpr":
      return {
        kind: "LoweredFieldAccess", span: expr.span, type: exprType,
        target: lowerExpr(ctx, expr.target), field: expr.field,
      };
    case "IndexExpr":
      return {
        kind: "LoweredIndex", span: expr.span, type: exprType,
        target: lowerExpr(ctx, expr.target),
        index: lowerExpr(ctx, expr.index),
      };
    case "UnaryExpr":
      return {
        kind: "LoweredUnary", span: expr.span, type: exprType,
        op: expr.op, operand: lowerExpr(ctx, expr.operand),
      };
    case "BinaryExpr":
      return lowerBinary(ctx, expr, exprType);
    case "IfExpr":
      return lowerIf(ctx, expr, exprType);
    case "MatchExpr":
      return lowerMatch(ctx, expr, exprType);
    case "BlockExpr":
      return lowerBlock(ctx, expr, /*isFnRoot*/ false, /*isLoopBody*/ false);
    case "LambdaExpr":
      return { kind: "LoweredUnreachable", span: expr.span, type: exprType,
               reason: "lambda lifting not yet implemented" };
    case "StructLitExpr":
      return {
        kind: "LoweredStructLit", span: expr.span, type: exprType,
        fields: expr.fields.map<LoweredStructLitField>((f) => ({
          name: f.name, value: lowerExpr(ctx, f.value),
        })),
      };
    case "ArrayLitExpr":
      return {
        kind: "LoweredArrayLit", span: expr.span, type: exprType,
        elements: expr.elements.map((e) => lowerExpr(ctx, e)),
      };
    case "RangeExpr":
      return { kind: "LoweredUnreachable", span: expr.span, type: exprType,
               reason: "range expressions deferred until Iterator dispatch" };
    case "TryExpr":
      return lowerTry(ctx, expr, exprType);
    case "CastExpr":
      return {
        kind: "LoweredCast", span: expr.span, type: exprType,
        value: lowerExpr(ctx, expr.value),
      };
    case "GenericInstExpr":
      return lowerExpr(ctx, expr.callee);     // type-args baked in post-mono
  }
}

function lowerIdent(ctx: FnLowerCtx, expr: A.IdentExpr, type: Type): LoweredExpr {
  const sym = ctx.typed.resolved.idents.get(expr);
  if (sym === undefined) {
    return { kind: "LoweredUnreachable", span: expr.span, type, reason: `unresolved ident ${expr.name}` };
  }
  return { kind: "LoweredIdent", span: expr.span, type, symbol: sym };
}

function lowerBinary(ctx: FnLowerCtx, expr: A.BinaryExpr, exprType: Type): LoweredExpr {
  if (expr.op === "is") {
    const checkType = applySubst(ctx.typed.exprTypes.get(expr.right) ?? TY.unresolved, ctx.subst);
    return {
      kind: "LoweredTypeCheck", span: expr.span, type: TY.bool,
      value: lowerExpr(ctx, expr.left), checkType,
    };
  }
  return {
    kind: "LoweredBinary", span: expr.span, type: exprType,
    op: expr.op,
    left: lowerExpr(ctx, expr.left),
    right: lowerExpr(ctx, expr.right),
  };
}

function lowerIf(ctx: FnLowerCtx, expr: A.IfExpr, exprType: Type): LoweredIf {
  const cond = lowerExpr(ctx, expr.cond);
  const then = lowerBlock(ctx, expr.then, false, false);
  let elseBlock: LoweredBlock | null = null;
  if (expr.else !== null) {
    elseBlock = expr.else.kind === "BlockExpr"
      ? lowerBlock(ctx, expr.else, false, false)
      : wrapAsBlock(lowerIf(ctx, expr.else, exprType), expr.else.span);
  }
  return { kind: "LoweredIf", span: expr.span, type: exprType, cond, then, else: elseBlock };
}

function wrapAsBlock(e: LoweredExpr, span: Span): LoweredBlock {
  return { kind: "LoweredBlock", span, type: e.type, stmts: [], trailing: e };
}

// ---------------------------------------------------------------- string interp

function lowerStringLit(ctx: FnLowerCtx, expr: A.StringLitExpr): LoweredExpr {
  if (expr.parts.every((p) => p.kind === "text")) {
    let value = "";
    for (const part of expr.parts) if (part.kind === "text") value += part.value;
    return { kind: "LoweredStringLit", span: expr.span, type: TY.string, value };
  }

  // Build a chain of @builder.* intrinsics. The StringBuilder runtime type
  // isn't modelled in the type system yet; the bytecode emitter resolves the
  // concrete type when wiring `std/builder`.
  const sbSym = freshSyntheticSymbol(ctx, "sb");
  const sbType: Type = TY.unresolved;
  const sbRef = (span: Span): LoweredExpr =>
    ({ kind: "LoweredIdent", span, type: sbType, symbol: sbSym });

  const stmts: LoweredStmt[] = [{
    kind: "LoweredLet", span: expr.span, name: sbSym.name, symbol: sbSym, type: sbType,
    value: { kind: "LoweredIntrinsicCall", span: expr.span, type: sbType, name: INTRINSICS.builderNew, args: [] },
  }];

  for (const part of expr.parts) {
    if (part.kind === "text") {
      const lit: LoweredExpr = { kind: "LoweredStringLit", span: part.span, type: TY.string, value: part.value };
      stmts.push({
        kind: "LoweredExprStmt", span: part.span,
        expr: {
          kind: "LoweredIntrinsicCall", span: part.span, type: TY.void,
          name: INTRINSICS.builderAppendStr,
          args: [sbRef(part.span), lit],
        },
      });
    } else {
      const inner = lowerExpr(ctx, part.expr);
      stmts.push({
        kind: "LoweredExprStmt", span: part.span,
        expr: {
          kind: "LoweredIntrinsicCall", span: part.span, type: TY.void,
          name: INTRINSICS.builderAppendDisplay,
          args: [sbRef(part.span), inner],
          displayFor: inner.type,
        },
      });
    }
  }

  return {
    kind: "LoweredBlock", span: expr.span, type: TY.string,
    stmts,
    trailing: {
      kind: "LoweredIntrinsicCall", span: expr.span, type: TY.string,
      name: INTRINSICS.builderFinish, args: [sbRef(expr.span)],
    },
  };
}

// ---------------------------------------------------------------- match

function lowerMatch(ctx: FnLowerCtx, expr: A.MatchExpr, exprType: Type): LoweredExpr {
  const scrutType = applySubst(ctx.typed.exprTypes.get(expr.scrutinee) ?? TY.unresolved, ctx.subst);
  const scrutSym = freshSyntheticSymbol(ctx, "scrut");

  const stmts: LoweredStmt[] = [{
    kind: "LoweredLet", span: expr.scrutinee.span, name: scrutSym.name, symbol: scrutSym,
    type: scrutType, value: lowerExpr(ctx, expr.scrutinee),
  }];

  // T3013 catches non-exhaustive scrutinees in the typechecker; this fallback
  // is defensive for cases where typecheck recovered past the error.
  let chain: LoweredBlock = wrapAsBlock(
    { kind: "LoweredUnreachable", span: expr.span, type: exprType,
      reason: "non-exhaustive match (T3013 should have caught this)" },
    expr.span);

  for (let i = expr.arms.length - 1; i >= 0; i--) {
    const arm = expr.arms[i]!;
    const armBlock = lowerArm(ctx, arm, scrutSym, scrutType);
    const predicate = armPredicate(ctx, arm, scrutSym, scrutType);
    if (predicate === null) {
      chain = armBlock;     // wildcard/binding pattern: always matches, drop predecessors
    } else {
      const ifNode: LoweredIf = {
        kind: "LoweredIf", span: arm.span, type: exprType,
        cond: predicate, then: armBlock, else: chain,
      };
      chain = wrapAsBlock(ifNode, arm.span);
    }
  }

  return {
    kind: "LoweredBlock", span: expr.span, type: exprType,
    stmts, trailing: chain.trailing,
  };
}

function lowerArm(
  ctx: FnLowerCtx, arm: A.MatchArm, scrutSym: Symbol, scrutType: Type,
): LoweredBlock {
  const stmts: LoweredStmt[] = [];
  introducePatternBindings(ctx, arm.pattern, scrutSym, scrutType, stmts, arm.span);
  const bodyExpr = lowerExpr(ctx, arm.body);
  return { kind: "LoweredBlock", span: arm.span, type: bodyExpr.type, stmts, trailing: bodyExpr };
}

function armPredicate(
  ctx: FnLowerCtx, arm: A.MatchArm, scrutSym: Symbol, scrutType: Type,
): LoweredExpr | null {
  const span = arm.pattern.span;
  const ident = (): LoweredExpr =>
    ({ kind: "LoweredIdent", span, type: scrutType, symbol: scrutSym });

  let core: LoweredExpr | null;
  switch (arm.pattern.kind) {
    case "WildcardPattern":
    case "BindingPattern":
      core = null;
      break;
    case "IsPattern":
      core = {
        kind: "LoweredTypeCheck", span, type: TY.bool,
        value: ident(),
        checkType: applySubst(ctx.typed.typeExprTypes.get(arm.pattern.type) ?? TY.unresolved, ctx.subst),
      };
      break;
    case "StructPattern":
      core = lowerStructPattern(ctx, arm.pattern, ident(), span);
      break;
  }

  if (arm.guard === null) return core;
  const guard = lowerExpr(ctx, arm.guard);
  if (core === null) return guard;
  return { kind: "LoweredBinary", span: arm.span, type: TY.bool, op: "and", left: core, right: guard };
}

function lowerStructPattern(
  ctx: FnLowerCtx, pattern: A.StructPattern, ident: LoweredExpr, span: Span,
): LoweredExpr {
  let acc: LoweredExpr = { kind: "LoweredBoolLit", span, type: TY.bool, value: true };
  for (const f of pattern.fields) {
    if (f.value.kind !== "literal") continue;
    const lit = lowerExpr(ctx, f.value.value);
    const eq: LoweredExpr = {
      kind: "LoweredBinary", span: f.span, type: TY.bool, op: "eq",
      left: { kind: "LoweredFieldAccess", span: f.span, type: lit.type, target: ident, field: f.name },
      right: lit,
    };
    acc = { kind: "LoweredBinary", span: f.span, type: TY.bool, op: "and", left: acc, right: eq };
  }
  return acc;
}

function introducePatternBindings(
  ctx: FnLowerCtx, pattern: A.Pattern, scrutSym: Symbol, scrutType: Type,
  out: LoweredStmt[], span: Span,
): void {
  const scrutRef = (): LoweredExpr =>
    ({ kind: "LoweredIdent", span, type: scrutType, symbol: scrutSym });
  switch (pattern.kind) {
    case "BindingPattern": {
      const sym = freshSyntheticSymbol(ctx, pattern.name);
      out.push({ kind: "LoweredLet", span, name: pattern.name, symbol: sym,
                 type: scrutType, value: scrutRef() });
      return;
    }
    case "IsPattern": {
      if (pattern.bindAs === null) return;
      const targetType = applySubst(
        ctx.typed.typeExprTypes.get(pattern.type) ?? TY.unresolved, ctx.subst);
      const sym = freshSyntheticSymbol(ctx, pattern.bindAs);
      out.push({
        kind: "LoweredLet", span, name: pattern.bindAs, symbol: sym, type: targetType,
        value: { kind: "LoweredCast", span, type: targetType, value: scrutRef() },
      });
      return;
    }
    case "StructPattern":
      for (const f of pattern.fields) {
        if (f.value.kind !== "binding") continue;
        const sym = freshSyntheticSymbol(ctx, f.value.name);
        out.push({
          kind: "LoweredLet", span: f.span, name: f.value.name, symbol: sym, type: TY.unresolved,
          value: {
            kind: "LoweredFieldAccess", span: f.span, type: TY.unresolved,
            target: { kind: "LoweredIdent", span: f.span, type: scrutType, symbol: scrutSym },
            field: f.name,
          },
        });
      }
      return;
    case "WildcardPattern":
      return;
  }
}

// ---------------------------------------------------------------- try

function lowerTry(ctx: FnLowerCtx, expr: A.TryExpr, exprType: Type): LoweredExpr {
  const inner = lowerExpr(ctx, expr.inner);
  const innerSym = freshSyntheticSymbol(ctx, "try");
  const idRef: LoweredExpr = { kind: "LoweredIdent", span: expr.span, type: inner.type, symbol: innerSym };

  const errorVariants = errorVariantsOf(inner.type, ctx);
  const errorPredicate = orAll(expr.span, errorVariants.map((v): LoweredExpr => ({
    kind: "LoweredTypeCheck", span: expr.span, type: TY.bool,
    value: idRef, checkType: v,
  })));

  const ifNode: LoweredIf = {
    kind: "LoweredIf", span: expr.span, type: exprType,
    cond: errorPredicate,
    then: {
      kind: "LoweredBlock", span: expr.span, type: TY.never,
      stmts: [{ kind: "LoweredReturn", span: expr.span, value: idRef }],
      trailing: null,
    },
    else: wrapAsBlock(
      { kind: "LoweredCast", span: expr.span, type: exprType, value: idRef },
      expr.span),
  };

  return {
    kind: "LoweredBlock", span: expr.span, type: exprType,
    stmts: [{
      kind: "LoweredLet", span: expr.span, name: innerSym.name, symbol: innerSym,
      type: inner.type, value: inner,
    }],
    trailing: ifNode,
  };
}

function errorVariantsOf(t: Type, ctx: FnLowerCtx): readonly Type[] {
  const variants: readonly Type[] = t.kind === "Union" ? t.variants : [t];
  const errorSym = findCoreTrait(ctx.project, CORE_TRAITS.Error);
  if (errorSym === null) return variants;
  return variants.filter((v) => satisfiesError(v, errorSym, ctx.project.impls));
}

function findCoreTrait(ctx: LowerProjectCtx, name: string): Symbol | null {
  const cached = ctx.coreTraitCache.get(name);
  if (cached !== undefined) return cached;
  let found: Symbol | null = null;
  for (const program of ctx.evaluated.typed.resolved.modules.values()) {
    if (program.module.displayPath !== STD_CORE_PATH) continue;
    const sym = program.module.symbols.get(name);
    if (sym !== undefined && sym.kind === "trait") { found = sym; break; }
  }
  ctx.coreTraitCache.set(name, found);
  return found;
}

function satisfiesError(v: Type, errorSym: Symbol, impls: ImplRegistry): boolean {
  // The trait type itself counts: `string!` desugars to `Error | string` where
  // `Error` is the trait — any value of that variant is by definition an error.
  if (v.kind === "Trait") return v.symbol.id === errorSym.id;
  if (v.kind === "Struct") return impls.hasUser(v.symbol, errorSym);
  if (v.kind === "Primitive") return impls.forPrimitive(v.name, errorSym) !== null;
  return false;
}

function orAll(span: Span, parts: readonly LoweredExpr[]): LoweredExpr {
  if (parts.length === 0) return { kind: "LoweredBoolLit", span, type: TY.bool, value: false };
  let acc = parts[0]!;
  for (let i = 1; i < parts.length; i++) {
    acc = { kind: "LoweredBinary", span, type: TY.bool, op: "or", left: acc, right: parts[i]! };
  }
  return acc;
}

// ---------------------------------------------------------------- helpers

function applySubst(t: Type, subst: Substitution): Type {
  // Skip the recursive Type walk when the subst is empty — common for non-generic decls.
  if ((subst.typeParams === undefined || subst.typeParams.size === 0) && subst.self === undefined) {
    return t;
  }
  return substitute(t, subst);
}

function freshSyntheticSymbol(ctx: FnLowerCtx, hint: string): Symbol {
  const n = ctx.uniq++;
  const name = `__${hint}_${n}`;
  return {
    id: -ctx.project.nextSyntheticId++,
    kind: "synthetic",
    name,
    module: ctx.entry.module.module.id,
    visibility: "private",
    definedAt: null,
    source: { kind: "synthetic", origin: hint },
  };
}
