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
  // own param + local scope. We recurse into nested LambdaExprs from here.
  const ownedFnScope = collectOwnedScopeForFn(fn, program.resolved);
  walkForLambdas(fn.body!, ownedFnScope, program, captured, lambdaCaptures);
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
// We use two passes per lambda body:
//   1. `walkForLambdas` discovers and processes inner LambdaExprs (post-order),
//      computing their capture sets.
//   2. `walkForCaptures` collects this lambda's own captures by walking its
//      body for IdentExprs and folding inner-lambda captures.
//
// The two-pass split lets captures bubble outward correctly without needing
// fixpoint iteration — by the time we collect `L`'s captures, every lambda
// nested inside `L` already has its captures recorded.

function walkForLambdas(
  body: A.BlockExpr,
  outerOwned: Set<number>,
  program: TypedProgram,
  captured: Set<number>,
  lambdaCaptures: Map<A.LambdaExpr, Capture[]>,
): void {
  walkBlockForLambdas(body, outerOwned, program, captured, lambdaCaptures);
}

function walkBlockForLambdas(
  block: A.BlockExpr,
  owned: Set<number>,
  program: TypedProgram,
  captured: Set<number>,
  lambdaCaptures: Map<A.LambdaExpr, Capture[]>,
): void {
  // Mutable scope as we descend through `let`s declared in this block.
  const scope = new Set(owned);
  for (const stmt of block.stmts) {
    walkStmtForLambdas(stmt, scope, program, captured, lambdaCaptures);
  }
  if (block.trailing !== null) walkExprForLambdas(block.trailing, scope, program, captured, lambdaCaptures);
}

function walkStmtForLambdas(
  stmt: A.Stmt,
  scope: Set<number>,
  program: TypedProgram,
  captured: Set<number>,
  lambdaCaptures: Map<A.LambdaExpr, Capture[]>,
): void {
  switch (stmt.kind) {
    case "LetStmt":
      walkExprForLambdas(stmt.value, scope, program, captured, lambdaCaptures);
      addLocalToScope(stmt, scope, program.resolved);
      return;
    case "AssignStmt":
      walkExprForLambdas(stmt.target, scope, program, captured, lambdaCaptures);
      walkExprForLambdas(stmt.value, scope, program, captured, lambdaCaptures);
      return;
    case "ExprStmt":
      walkExprForLambdas(stmt.expr, scope, program, captured, lambdaCaptures);
      return;
    case "ReturnStmt":
      if (stmt.value !== null) walkExprForLambdas(stmt.value, scope, program, captured, lambdaCaptures);
      return;
    case "ForStmt": {
      // The body opens a fresh scope; for-in adds the binding into it.
      const inner = new Set(scope);
      if (stmt.form.kind === "while") {
        walkExprForLambdas(stmt.form.cond, inner, program, captured, lambdaCaptures);
      } else if (stmt.form.kind === "in") {
        walkExprForLambdas(stmt.form.iter, inner, program, captured, lambdaCaptures);
        const bindingSym = program.resolved.forIns.get(stmt);
        if (bindingSym !== undefined) inner.add(bindingSym.id);
      }
      walkBlockForLambdas(stmt.body, inner, program, captured, lambdaCaptures);
      return;
    }
    case "BreakStmt":
    case "ContinueStmt":
      return;
    case "DeferStmt":
      if (stmt.body.kind === "BlockExpr") {
        walkBlockForLambdas(stmt.body, scope, program, captured, lambdaCaptures);
      } else {
        walkStmtForLambdas(stmt.body, scope, program, captured, lambdaCaptures);
      }
      return;
  }
}

function walkExprForLambdas(
  expr: A.Expr,
  scope: Set<number>,
  program: TypedProgram,
  captured: Set<number>,
  lambdaCaptures: Map<A.LambdaExpr, Capture[]>,
): void {
  switch (expr.kind) {
    case "IntLitExpr": case "FloatLitExpr": case "BoolLitExpr":
    case "NullLitExpr": case "CharLitExpr": case "DotVariantExpr":
    case "IdentExpr":
      return;
    case "StringLitExpr":
      for (const part of expr.parts) {
        if (part.kind === "interp") walkExprForLambdas(part.expr, scope, program, captured, lambdaCaptures);
      }
      return;
    case "CallExpr":
      walkExprForLambdas(expr.callee, scope, program, captured, lambdaCaptures);
      for (const a of expr.args) walkExprForLambdas(a.value, scope, program, captured, lambdaCaptures);
      return;
    case "FieldExpr":
      walkExprForLambdas(expr.target, scope, program, captured, lambdaCaptures);
      return;
    case "IndexExpr":
      walkExprForLambdas(expr.target, scope, program, captured, lambdaCaptures);
      walkExprForLambdas(expr.index, scope, program, captured, lambdaCaptures);
      return;
    case "UnaryExpr":
      walkExprForLambdas(expr.operand, scope, program, captured, lambdaCaptures);
      return;
    case "BinaryExpr":
      walkExprForLambdas(expr.left,  scope, program, captured, lambdaCaptures);
      walkExprForLambdas(expr.right, scope, program, captured, lambdaCaptures);
      return;
    case "IfExpr":
      walkExprForLambdas(expr.cond, scope, program, captured, lambdaCaptures);
      walkBlockForLambdas(expr.then, scope, program, captured, lambdaCaptures);
      if (expr.else !== null) {
        if (expr.else.kind === "BlockExpr") walkBlockForLambdas(expr.else, scope, program, captured, lambdaCaptures);
        else walkExprForLambdas(expr.else, scope, program, captured, lambdaCaptures);
      }
      return;
    case "MatchExpr":
      walkExprForLambdas(expr.scrutinee, scope, program, captured, lambdaCaptures);
      for (const arm of expr.arms) {
        // Patterns can bind names — for simplicity we assume the typechecker
        // wires the binding into resolved.idents at use-site time. We don't
        // pre-extend `scope` with pattern bindings here; if a body refers to
        // such a binding, the IdentExpr's symbol will resolve to a "binding"
        // kind whose definition site is the pattern, and it will appear in
        // the lambda's owned scope when we walk for captures.
        if (arm.guard !== null) walkExprForLambdas(arm.guard, scope, program, captured, lambdaCaptures);
        walkExprForLambdas(arm.body, scope, program, captured, lambdaCaptures);
      }
      return;
    case "BlockExpr":
      walkBlockForLambdas(expr, scope, program, captured, lambdaCaptures);
      return;
    case "LambdaExpr":
      processLambda(expr, scope, program, captured, lambdaCaptures);
      return;
    case "StructLitExpr":
      for (const f of expr.fields) walkExprForLambdas(f.value, scope, program, captured, lambdaCaptures);
      return;
    case "ArrayLitExpr":
      for (const e of expr.elements) walkExprForLambdas(e, scope, program, captured, lambdaCaptures);
      return;
    case "RangeExpr":
      walkExprForLambdas(expr.lower, scope, program, captured, lambdaCaptures);
      walkExprForLambdas(expr.upper, scope, program, captured, lambdaCaptures);
      return;
    case "TryExpr":
      walkExprForLambdas(expr.inner, scope, program, captured, lambdaCaptures);
      return;
    case "CastExpr":
      walkExprForLambdas(expr.value, scope, program, captured, lambdaCaptures);
      return;
    case "GenericInstExpr":
      walkExprForLambdas(expr.callee, scope, program, captured, lambdaCaptures);
      return;
  }
}

// ---------------------------------------------------------------- per-lambda

function processLambda(
  lambda: A.LambdaExpr,
  _outerScope: Set<number>,
  program: TypedProgram,
  captured: Set<number>,
  lambdaCaptures: Map<A.LambdaExpr, Capture[]>,
): void {
  // Recurse into nested lambdas first so their captures are recorded before
  // we fold them into ours.
  const ownScope = collectOwnedScopeForLambda(lambda, program.resolved);
  walkBlockForLambdas(lambda.body, ownScope, program, captured, lambdaCaptures);

  // Compute THIS lambda's captures — each entry refers, by construction, to
  // a symbol defined outside the lambda's own scope (param/local/binding).
  const captures: Capture[] = [];
  const seen = new Set<number>();
  collectCapturesInBlock(lambda.body, ownScope, captures, seen, program, lambdaCaptures);

  for (const c of captures) captured.add(c.symbol.id);
  lambdaCaptures.set(lambda, captures);
}

function collectCapturesInBlock(
  block: A.BlockExpr,
  ownScope: Set<number>,
  captures: Capture[],
  seen: Set<number>,
  program: TypedProgram,
  lambdaCaptures: ReadonlyMap<A.LambdaExpr, readonly Capture[]>,
): void {
  const scope = new Set(ownScope);
  for (const stmt of block.stmts) {
    collectCapturesInStmt(stmt, scope, captures, seen, program, lambdaCaptures);
  }
  if (block.trailing !== null) {
    collectCapturesInExpr(block.trailing, scope, captures, seen, program, lambdaCaptures);
  }
}

function collectCapturesInStmt(
  stmt: A.Stmt,
  scope: Set<number>,
  captures: Capture[],
  seen: Set<number>,
  program: TypedProgram,
  lambdaCaptures: ReadonlyMap<A.LambdaExpr, readonly Capture[]>,
): void {
  switch (stmt.kind) {
    case "LetStmt":
      collectCapturesInExpr(stmt.value, scope, captures, seen, program, lambdaCaptures);
      addLocalToScope(stmt, scope, program.resolved);
      return;
    case "AssignStmt":
      collectCapturesInExpr(stmt.target, scope, captures, seen, program, lambdaCaptures);
      collectCapturesInExpr(stmt.value,  scope, captures, seen, program, lambdaCaptures);
      return;
    case "ExprStmt":
      collectCapturesInExpr(stmt.expr, scope, captures, seen, program, lambdaCaptures);
      return;
    case "ReturnStmt":
      if (stmt.value !== null) collectCapturesInExpr(stmt.value, scope, captures, seen, program, lambdaCaptures);
      return;
    case "ForStmt": {
      const inner = new Set(scope);
      if (stmt.form.kind === "while") {
        collectCapturesInExpr(stmt.form.cond, inner, captures, seen, program, lambdaCaptures);
      } else if (stmt.form.kind === "in") {
        collectCapturesInExpr(stmt.form.iter, inner, captures, seen, program, lambdaCaptures);
        const bindingSym = program.resolved.forIns.get(stmt);
        if (bindingSym !== undefined) inner.add(bindingSym.id);
      }
      collectCapturesInBlock(stmt.body, inner, captures, seen, program, lambdaCaptures);
      return;
    }
    case "BreakStmt":
    case "ContinueStmt":
      return;
    case "DeferStmt":
      if (stmt.body.kind === "BlockExpr") {
        collectCapturesInBlock(stmt.body, scope, captures, seen, program, lambdaCaptures);
      } else {
        collectCapturesInStmt(stmt.body, scope, captures, seen, program, lambdaCaptures);
      }
      return;
  }
}

function collectCapturesInExpr(
  expr: A.Expr,
  scope: Set<number>,
  captures: Capture[],
  seen: Set<number>,
  program: TypedProgram,
  lambdaCaptures: ReadonlyMap<A.LambdaExpr, readonly Capture[]>,
): void {
  switch (expr.kind) {
    case "IntLitExpr": case "FloatLitExpr": case "BoolLitExpr":
    case "NullLitExpr": case "CharLitExpr": case "DotVariantExpr":
      return;
    case "IdentExpr": {
      const sym = program.resolved.idents.get(expr);
      if (sym === undefined) return;
      if (!isCapturable(sym)) return;
      if (scope.has(sym.id)) return;
      // Out-of-scope local/param/binding → captured.
      addCapture(sym, expr, captures, seen, program);
      return;
    }
    case "StringLitExpr":
      for (const part of expr.parts) {
        if (part.kind === "interp") collectCapturesInExpr(part.expr, scope, captures, seen, program, lambdaCaptures);
      }
      return;
    case "CallExpr":
      collectCapturesInExpr(expr.callee, scope, captures, seen, program, lambdaCaptures);
      for (const a of expr.args) collectCapturesInExpr(a.value, scope, captures, seen, program, lambdaCaptures);
      return;
    case "FieldExpr":
      collectCapturesInExpr(expr.target, scope, captures, seen, program, lambdaCaptures);
      return;
    case "IndexExpr":
      collectCapturesInExpr(expr.target, scope, captures, seen, program, lambdaCaptures);
      collectCapturesInExpr(expr.index,  scope, captures, seen, program, lambdaCaptures);
      return;
    case "UnaryExpr":
      collectCapturesInExpr(expr.operand, scope, captures, seen, program, lambdaCaptures);
      return;
    case "BinaryExpr":
      collectCapturesInExpr(expr.left,  scope, captures, seen, program, lambdaCaptures);
      collectCapturesInExpr(expr.right, scope, captures, seen, program, lambdaCaptures);
      return;
    case "IfExpr":
      collectCapturesInExpr(expr.cond, scope, captures, seen, program, lambdaCaptures);
      collectCapturesInBlock(expr.then, scope, captures, seen, program, lambdaCaptures);
      if (expr.else !== null) {
        if (expr.else.kind === "BlockExpr") collectCapturesInBlock(expr.else, scope, captures, seen, program, lambdaCaptures);
        else collectCapturesInExpr(expr.else, scope, captures, seen, program, lambdaCaptures);
      }
      return;
    case "MatchExpr":
      collectCapturesInExpr(expr.scrutinee, scope, captures, seen, program, lambdaCaptures);
      for (const arm of expr.arms) {
        if (arm.guard !== null) collectCapturesInExpr(arm.guard, scope, captures, seen, program, lambdaCaptures);
        collectCapturesInExpr(arm.body, scope, captures, seen, program, lambdaCaptures);
      }
      return;
    case "BlockExpr":
      collectCapturesInBlock(expr, scope, captures, seen, program, lambdaCaptures);
      return;
    case "LambdaExpr": {
      // For an inner lambda, fold its captures into ours — minus any symbol
      // that's already in our own scope (i.e. defined inside us).
      const innerCaps = lambdaCaptures.get(expr);
      if (innerCaps !== undefined) {
        for (const c of innerCaps) {
          if (!scope.has(c.symbol.id)) addCaptureValue(c, captures, seen);
        }
      }
      return;
    }
    case "StructLitExpr":
      for (const f of expr.fields) collectCapturesInExpr(f.value, scope, captures, seen, program, lambdaCaptures);
      return;
    case "ArrayLitExpr":
      for (const e of expr.elements) collectCapturesInExpr(e, scope, captures, seen, program, lambdaCaptures);
      return;
    case "RangeExpr":
      collectCapturesInExpr(expr.lower, scope, captures, seen, program, lambdaCaptures);
      collectCapturesInExpr(expr.upper, scope, captures, seen, program, lambdaCaptures);
      return;
    case "TryExpr":
      collectCapturesInExpr(expr.inner, scope, captures, seen, program, lambdaCaptures);
      return;
    case "CastExpr":
      collectCapturesInExpr(expr.value, scope, captures, seen, program, lambdaCaptures);
      return;
    case "GenericInstExpr":
      collectCapturesInExpr(expr.callee, scope, captures, seen, program, lambdaCaptures);
      return;
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
    const t = program.localTypes.get(sym.source.stmt);
    if (t !== undefined) return t;
  } else if (sym.source.kind === "param") {
    const t = program.paramTypes.get(sym.source.param);
    if (t !== undefined) return t;
  }
  return program.exprTypes.get(identExpr) ?? TY.unresolved;
}

function addLocalToScope(stmt: A.LetStmt, scope: Set<number>, resolved: ResolvedProgram): void {
  const sym = resolved.locals.get(stmt);
  if (sym !== undefined) scope.add(sym.id);
}
