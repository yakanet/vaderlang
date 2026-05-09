// Free-variable analysis for closures.
//
// For every `LambdaExpr` in the program, computes the ordered list of
// captures — symbols defined in an enclosing scope that the lambda's body
// references. The lowerer (Phase 3.2 + 3.3) consumes this to:
//   - Heap-promote captured locals into `Cell<T>` (so multiple closures can
//     share a mutable binding — the by-reference semantics of Vader closures).
//   - Lift each lambda to a top-level fn taking an `env` struct, and rewrite
//     the call site into `make_closure { fnIndex, captures }`.
//
// Nested lambdas: an outer lambda's captures include any of its inner
// lambdas' captures that originate outside the outer lambda's own scope.
// Otherwise the outer would have no way to pass them to the inner closure.

import type * as A from "../parser/ast.ts";
import { forEachPatternBindingKey, unreachableTypeExprInValuePosition } from "../parser/ast.ts";
import type { ResolvedProgram } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { Type } from "../typecheck/types.ts";
import type { TypedProject, TypedProgram } from "../typecheck/typed-ast.ts";
import { TY } from "../typecheck/types.ts";

export interface Capture {
  readonly symbol: Symbol;
  readonly type: Type;
}

export interface ClosureAnalysis {
  /** Symbol IDs (param/local/binding) that are captured by at least one
   *  inner lambda. The lowerer must heap-promote these via `Cell<T>`. */
  readonly capturedSymbols: ReadonlySet<number>;
  /** Per-LambdaExpr capture list. Field order in the generated env struct
   *  mirrors this order; `make_closure` consumes captures in the same order. */
  readonly lambdaCaptures: ReadonlyMap<A.LambdaExpr, readonly Capture[]>;
}

export function analyzeClosures(project: TypedProject): ClosureAnalysis {
  const captured = new Set<number>();
  const lambdaCaptures = new Map<A.LambdaExpr, Capture[]>();

  for (const program of project.modules.values()) {
    analyzeProgram(program, captured, lambdaCaptures);
  }

  return { capturedSymbols: captured, lambdaCaptures };
}

function analyzeProgram(
  program: TypedProgram,
  captured: Set<number>,
  lambdaCaptures: Map<A.LambdaExpr, Capture[]>,
): void {
  for (const decl of program.resolved.source.decls) {
    if (decl.kind === "FnDecl" && decl.body !== null) {
      analyzeFnBody(decl, program, captured, lambdaCaptures);
    } else if (decl.kind === "ImplDecl") {
      for (const member of decl.members) {
        if (member.body !== null) analyzeFnBody(member, program, captured, lambdaCaptures);
      }
    }
  }
}

function analyzeFnBody(
  fn: A.FnDecl,
  program: TypedProgram,
  captured: Set<number>,
  lambdaCaptures: Map<A.LambdaExpr, Capture[]>,
): void {
  // Top-level fns / impl members: their body's lambdas capture from the fn's
  // own param + local scope. We pass `outCaptures = null` so the walker only
  // discovers nested lambdas (it doesn't have an enclosing capture set to
  // collect into — top-level fns don't capture).
  const ownedFnScope = collectOwnedScopeForFn(fn, program.resolved);
  walkBody(fn.body!, ownedFnScope, null, null, { program, captured, lambdaCaptures });
}

// ---------------------------------------------------------------- owned scope

function collectOwnedScopeForFn(fn: A.FnDecl, resolved: ResolvedProgram): Set<number> {
  const owned = new Set<number>();
  for (const p of fn.params) {
    const sym = resolved.params.get(p);
    if (sym !== undefined) owned.add(sym.id);
  }
  return owned;
}

function collectOwnedScopeForLambda(lambda: A.LambdaExpr, resolved: ResolvedProgram): Set<number> {
  const owned = new Set<number>();
  for (const p of lambda.params) {
    const sym = resolved.params.get(p);
    if (sym !== undefined) owned.add(sym.id);
  }
  return owned;
}

// ---------------------------------------------------------------- traversal
// Single fused walker: visits each AST node once, optionally collecting
// captures for the current lambda. `outCaptures === null` means we're
// walking the top-level fn body (no captures to collect — just descend
// into nested lambdas). The captures of nested lambdas are computed
// recursively (post-order), then folded into the enclosing lambda's
// captures by skipping any symbol already in the enclosing scope.

interface WalkCtx {
  readonly program: TypedProgram;
  readonly captured: Set<number>;
  readonly lambdaCaptures: Map<A.LambdaExpr, Capture[]>;
}

function walkBody(
  body: A.BlockExpr, scope: Set<number>,
  outCaptures: Capture[] | null, outSeen: Set<number> | null,
  ctx: WalkCtx,
): void {
  for (const stmt of body.stmts) walkStmt(stmt, scope, outCaptures, outSeen, ctx);
  if (body.trailing !== null) walkExpr(body.trailing, scope, outCaptures, outSeen, ctx);
}

function walkStmt(
  stmt: A.Stmt, scope: Set<number>,
  outCaptures: Capture[] | null, outSeen: Set<number> | null,
  ctx: WalkCtx,
): void {
  switch (stmt.kind) {
    case "LetStmt":
      walkExpr(stmt.value, scope, outCaptures, outSeen, ctx);
      addLocalToScope(stmt, scope, ctx.program.resolved);
      return;
    case "AssignStmt":
      walkExpr(stmt.target, scope, outCaptures, outSeen, ctx);
      walkExpr(stmt.value,  scope, outCaptures, outSeen, ctx);
      return;
    case "ExprStmt":
      walkExpr(stmt.expr, scope, outCaptures, outSeen, ctx);
      return;
    case "ReturnStmt":
      if (stmt.value !== null) walkExpr(stmt.value, scope, outCaptures, outSeen, ctx);
      return;
    case "ForStmt": {
      const inner = new Set(scope);
      if (stmt.form.kind === "while") {
        walkExpr(stmt.form.cond, inner, outCaptures, outSeen, ctx);
      } else if (stmt.form.kind === "in") {
        walkExpr(stmt.form.iter, inner, outCaptures, outSeen, ctx);
        const bindingSym = ctx.program.resolved.forIns.get(stmt);
        if (bindingSym !== undefined) inner.add(bindingSym.id);
      }
      walkBody(stmt.body, inner, outCaptures, outSeen, ctx);
      return;
    }
    case "BreakStmt":
    case "ContinueStmt":
      return;
    case "DeferStmt":
      if (stmt.body.kind === "BlockExpr") walkBody(stmt.body, new Set(scope), outCaptures, outSeen, ctx);
      else walkStmt(stmt.body, scope, outCaptures, outSeen, ctx);
      return;
  }
}

function walkExpr(
  expr: A.Expr, scope: Set<number>,
  outCaptures: Capture[] | null, outSeen: Set<number> | null,
  ctx: WalkCtx,
): void {
  switch (expr.kind) {
    case "IntLitExpr": case "FloatLitExpr": case "BoolLitExpr":
    case "NullLitExpr": case "CharLitExpr": case "DotVariantExpr":
      return;
    case "IdentExpr": {
      if (outCaptures === null || outSeen === null) return;
      const sym = ctx.program.resolved.idents.get(expr);
      if (sym === undefined || !isCapturable(sym) || scope.has(sym.id)) return;
      addCapture(sym, expr, outCaptures, outSeen, ctx.program);
      return;
    }
    case "StringLitExpr":
      for (const part of expr.parts) {
        if (part.kind === "interp") walkExpr(part.expr, scope, outCaptures, outSeen, ctx);
      }
      return;
    case "CallExpr":
      walkExpr(expr.callee, scope, outCaptures, outSeen, ctx);
      for (const a of expr.args) walkExpr(a.value, scope, outCaptures, outSeen, ctx);
      return;
    case "FieldExpr":
      walkExpr(expr.target, scope, outCaptures, outSeen, ctx);
      return;
    case "IndexExpr":
      walkExpr(expr.target, scope, outCaptures, outSeen, ctx);
      walkExpr(expr.index,  scope, outCaptures, outSeen, ctx);
      return;
    case "UnaryExpr":
      walkExpr(expr.operand, scope, outCaptures, outSeen, ctx);
      return;
    case "BinaryExpr":
      walkExpr(expr.left,  scope, outCaptures, outSeen, ctx);
      walkExpr(expr.right, scope, outCaptures, outSeen, ctx);
      return;
    case "IfExpr":
      walkExpr(expr.cond, scope, outCaptures, outSeen, ctx);
      walkBody(expr.then, new Set(scope), outCaptures, outSeen, ctx);
      if (expr.else !== null) {
        if (expr.else.kind === "BlockExpr") walkBody(expr.else, new Set(scope), outCaptures, outSeen, ctx);
        else walkExpr(expr.else, scope, outCaptures, outSeen, ctx);
      }
      return;
    case "MatchExpr":
      walkExpr(expr.scrutinee, scope, outCaptures, outSeen, ctx);
      for (const arm of expr.arms) {
        const added = pushPatternBindings(arm.pattern, ctx.program, scope);
        if (arm.guard !== null) walkExpr(arm.guard, scope, outCaptures, outSeen, ctx);
        walkExpr(arm.body, scope, outCaptures, outSeen, ctx);
        for (const id of added) scope.delete(id);
      }
      return;
    case "BlockExpr":
      walkBody(expr, new Set(scope), outCaptures, outSeen, ctx);
      return;
    case "LambdaExpr":
      processLambda(expr, scope, outCaptures, outSeen, ctx);
      return;
    case "StructLitExpr":
      for (const f of expr.fields) walkExpr(f.value, scope, outCaptures, outSeen, ctx);
      return;
    case "SeqLitExpr":
      for (const e of expr.elements) walkExpr(e, scope, outCaptures, outSeen, ctx);
      return;
    case "RangeExpr":
      walkExpr(expr.lower, scope, outCaptures, outSeen, ctx);
      walkExpr(expr.upper, scope, outCaptures, outSeen, ctx);
      return;
    case "TryExpr":
      walkExpr(expr.inner, scope, outCaptures, outSeen, ctx);
      return;
    case "CastExpr":
      walkExpr(expr.value, scope, outCaptures, outSeen, ctx);
      return;
    case "GenericInstExpr":
      walkExpr(expr.callee, scope, outCaptures, outSeen, ctx);
      return;
    case "UnionType":
    case "FnTypeExpr":
    case "ArrayTypeExpr":
      unreachableTypeExprInValuePosition(expr);
  }
}

// ---------------------------------------------------------------- per-lambda

function processLambda(
  lambda: A.LambdaExpr, outerScope: Set<number>,
  outCaptures: Capture[] | null, outSeen: Set<number> | null,
  ctx: WalkCtx,
): void {
  // Recurse into the lambda's body with its own scope, computing its captures
  // in a single pass (free-vars are detected at IdentExprs; nested lambdas
  // recurse and fold). Post-order: by the time we return, every nested
  // lambda already has its captures recorded in `lambdaCaptures`.
  const ownScope = collectOwnedScopeForLambda(lambda, ctx.program.resolved);
  const captures: Capture[] = [];
  const seen = new Set<number>();
  walkBody(lambda.body, ownScope, captures, seen, ctx);

  for (const c of captures) ctx.captured.add(c.symbol.id);
  ctx.lambdaCaptures.set(lambda, captures);

  // Fold this lambda's captures into the enclosing lambda's, skipping any
  // symbol already defined in the enclosing scope (i.e. shared with us).
  if (outCaptures !== null && outSeen !== null) {
    for (const c of captures) {
      if (!outerScope.has(c.symbol.id)) addCaptureValue(c, outCaptures, outSeen);
    }
  }
}

function isCapturable(sym: Symbol): boolean {
  return sym.kind === "param" || sym.kind === "local" || sym.kind === "binding";
}

function addCapture(
  sym: Symbol,
  identExpr: A.IdentExpr,
  captures: Capture[],
  seen: Set<number>,
  program: TypedProgram,
): void {
  if (seen.has(sym.id)) return;
  seen.add(sym.id);
  const type = typeOfCapturedSymbol(sym, identExpr, program);
  captures.push({ symbol: sym, type });
}

function addCaptureValue(c: Capture, captures: Capture[], seen: Set<number>): void {
  if (seen.has(c.symbol.id)) return;
  seen.add(c.symbol.id);
  captures.push(c);
}

function typeOfCapturedSymbol(sym: Symbol, identExpr: A.IdentExpr, program: TypedProgram): Type {
  // Prefer the type recorded at the symbol's binding site (more precise than
  // the use-site narrowing). Falls back to the IdentExpr's exprType then
  // Unresolved.
  if (sym.source.kind === "local") {
    const t = program.localTypes.get(sym.source.binding);
    if (t !== undefined) return t;
  } else if (sym.source.kind === "param") {
    const t = program.paramTypes.get(sym.source.param);
    if (t !== undefined) return t;
  }
  return program.exprTypes.get(identExpr) ?? TY.unresolved;
}

function addLocalToScope(stmt: A.LetStmt, scope: Set<number>, resolved: ResolvedProgram): void {
  // Walk the let-binding tree so destructured leaves all join the scope.
  visitLetLeaves(stmt.binding, (leaf) => {
    const sym = resolved.locals.get(leaf);
    if (sym !== undefined) scope.add(sym.id);
  });
}

function visitLetLeaves(b: A.LetBinding, visit: (leaf: A.SimpleBinding) => void): void {
  switch (b.kind) {
    case "SimpleBinding": visit(b); return;
    case "TupleBinding":
      for (const e of b.elements) visitLetLeaves(e, visit);
      return;
    case "WildcardBinding": return;
  }
}

/** Add the pattern's bindings to `scope` and return the list of ids actually
 *  added (i.e. not already present). Caller is expected to `scope.delete(id)`
 *  for each returned id once the arm is processed — preserves outer scope
 *  intact while avoiding a fresh `new Set(scope)` per arm. */
function pushPatternBindings(
  pat: A.Pattern, program: TypedProgram, scope: Set<number>,
): readonly number[] {
  const added: number[] = [];
  forEachPatternBindingKey(pat, (key) => {
    const s = program.resolved.patternBindings.get(key);
    if (s !== undefined && !scope.has(s.id)) { scope.add(s.id); added.push(s.id); }
  });
  return added;
}
