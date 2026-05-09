// Statement and block checking. Walks every statement of a fn body, checks
// each against its expected type (where applicable), and tracks loop depth /
// `Self` substitution / for-in narrowing through the FnContext.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Type, TupleType } from "../types.ts";
import { CORE_TRAITS, TY, defaultIfFree, displayType, isAssignable, substitute } from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { recordIterCoercion } from "./call.ts";
import { looksLikeTypeExpression } from "./decl.ts";
import { checkExpr, resolveIndexTrait } from "./expr.ts";
import { lowerExprAsType } from "./type-expr.ts";

/** Substitute `Self` in this fn's param/return types now that we know the
 *  surrounding impl's target type, and bind unannotated `self` parameters.
 *  Shared between `checkFnBody` (impls with source bodies) and the body-less
 *  intrinsic-impl path (no body to walk, but the signature still needs the
 *  Self → forType substitution to flow through). */
export function bindSelfTypes(fn: A.FnDecl, selfType: Type | null, t: MutableTyped): void {
  if (selfType === null) return;
  for (const p of fn.params) {
    if (p.name === "self" && p.type === null) {
      t.globals.paramTypes.set(p, selfType);
    } else {
      const declared = t.globals.paramTypes.get(p);
      if (declared !== undefined) {
        t.globals.paramTypes.set(p, substitute(declared, { self: selfType }));
      }
    }
  }
  const declaredFn = t.globals.declTypes.get(fn);
  if (declaredFn !== undefined) {
    t.globals.declTypes.set(fn, substitute(declaredFn, { self: selfType }));
  }
}

export function checkFnBody(
  fn: A.FnDecl, body: A.BlockExpr, selfType: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector,
): void {
  bindSelfTypes(fn, selfType, t);
  const fnType = t.globals.declTypes.get(fn);
  const ctx: FnContext = {
    returnType: fnType?.kind === "Fn" ? fnType.returnType : TY.unresolved,
    selfType,
    loopDepth: 0,
  };
  const got = checkBlock(body, ctx.returnType, t, impls, diags, ctx);
  // Implicit return: if the block has no trailing expr the body type is void
  // (already handled). If the trailing expr is incompatible the diagnostic
  // already fired.
  if (body.trailing !== null && !isAssignable(got, ctx.returnType, impls)) {
    err(diags, "T3020", body.trailing.span,
      `expected ${displayType(ctx.returnType)}, got ${displayType(got)}`);
  }
  if (body.trailing !== null) recordIterCoercion(body.trailing, got, ctx.returnType, t);
}

export function checkBlock(
  block: A.BlockExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  for (const stmt of block.stmts) checkStmt(stmt, t, impls, diags, fn);
  let result: Type = TY.void;
  if (block.trailing !== null) {
    result = checkExpr(block.trailing, expected, t, impls, diags, fn);
  }
  t.exprTypes.set(block, result);
  return result;
}

function checkStmt(
  stmt: A.Stmt, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): void {
  switch (stmt.kind) {
    case "LetStmt": {
      const expectedAnn = stmt.type !== null ? lowerExprAsType(stmt.type, t, diags) : null;
      // Hint for value inference : the annotation when present, otherwise a
      // synthetic tuple shape derived from the binding tree (so `[a, b] := pair()`
      // disambiguates a SeqLit RHS as a tuple of the right arity). The hint
      // does NOT replace the inferred type at let-binding time — the *declared*
      // type below uses the explicit annotation or `got` (inference) directly.
      const valueHint = expectedAnn ?? expectedFromBinding(stmt.binding);
      const got = checkExpr(stmt.value, valueHint, t, impls, diags, fn);
      const declared = expectedAnn ?? defaultIfFree(got);
      if (expectedAnn !== null && !isAssignable(got, expectedAnn, impls)) {
        err(diags, "T3001", stmt.span,
          `expected ${displayType(expectedAnn)}, got ${displayType(got)}`);
      }
      // Layer 5b — `t :: <type-expr>` inside a fn body is an in-fn type
      // alias : pre-resolve the underlying Type and stash it ; lower will
      // skip emitting a runtime slot, downstream type-position references
      // see the resolved type via `letTypeAliases`. Mirrors the top-level
      // `constTypeAliases` mechanism, keyed by the local symbol since
      // let-stmts have no decl AST node.
      let isLetTypeAlias = false;
      if (declared.kind === "TypeMeta" && !stmt.mutable
          && stmt.binding.kind === "SimpleBinding"
          && looksLikeTypeExpression(stmt.value, t)) {
        const resolved = lowerExprAsType(stmt.value, t, diags);
        const sym = t.resolved.locals.get(stmt.binding);
        if (sym !== undefined) {
          t.globals.letTypeAliases.set(sym, resolved);
          isLetTypeAlias = true;
        }
      }
      // Any other `type`-valued local can't be lowered today (the VM has
      // no Type-value representation — Layer 4 milestone B.1 pending) ;
      // reject at typecheck with T3035 so the user sees a clear diag
      // instead of `reached unreachable` at runtime.
      if (declared.kind === "TypeMeta" && !isLetTypeAlias) {
        err(diags, "T3035", stmt.span,
          "`type`-valued locals are not yet supported (Layer 4 milestone B.1) ; "
          + "use the immutable form `name :: <type-expr>` for an in-fn type alias, "
          + "or a top-level alias `Name :: type[T] ...`");
      }
      if (expectedAnn !== null) recordIterCoercion(stmt.value, got, expectedAnn, t);
      assignBindingTypes(stmt.binding, declared, t, diags);
      return;
    }
    case "AssignStmt": {
      // `a[i] = v` on a non-array target dispatches through `IndexSet($I, $T)`.
      // The trait's `set_at` consumes the value's type as `T` ; we resolve the
      // impl on the target's static type and surface the value's expected type
      // before checking the RHS.
      if (stmt.target.kind === "IndexExpr") {
        const indexed = stmt.target;
        const target = checkExpr(indexed.target, null, t, impls, diags, fn);
        const indexTy = checkExpr(indexed.index, null, t, impls, diags, fn);
        if (target.kind === "Struct") {
          const result = resolveIndexTrait(
            indexed, target, indexTy, CORE_TRAITS.IndexSet, "set_at", t, impls, diags,
          );
          if (result !== null) {
            t.indexSetResolutions.set(indexed, result.resolution);
            checkExpr(stmt.value, result.elementType, t, impls, diags, fn);
            return;
          }
        }
      }
      const targetType = checkExpr(stmt.target, null, t, impls, diags, fn);
      // Pass the target's type as expected so free numeric literals adopt it
      // (e.g. `v: u64; v = 5` → `5: u64`, not `5: i32`).
      const valueCtx = targetType.kind === "Unresolved" ? null : targetType;
      checkExpr(stmt.value, valueCtx, t, impls, diags, fn);
      return;
    }
    case "ExprStmt":
      checkExpr(stmt.expr, null, t, impls, diags, fn);
      return;
    case "ReturnStmt": {
      if (fn === null) return;
      if (stmt.value === null) {
        if (!isAssignable(TY.void, fn.returnType)) {
          err(diags, "T3020", stmt.span,
            `expected ${displayType(fn.returnType)}, got void`);
        }
        return;
      }
      const got = checkExpr(stmt.value, fn.returnType, t, impls, diags, fn);
      if (!isAssignable(got, fn.returnType, impls)) {
        err(diags, "T3020", stmt.span,
          `expected ${displayType(fn.returnType)}, got ${displayType(got)}`);
      }
      recordIterCoercion(stmt.value, got, fn.returnType, t);
      return;
    }
    case "ForStmt":
      checkForStmt(stmt, t, impls, diags, fn);
      return;
    case "BreakStmt":
    case "ContinueStmt":
      if (fn === null || fn.loopDepth === 0) err(diags, "T3015", stmt.span);
      return;
    case "DeferStmt":
      if (stmt.body.kind === "BlockExpr") checkBlock(stmt.body, null, t, impls, diags, fn);
      else checkStmt(stmt.body, t, impls, diags, fn);
      return;
  }
}

function checkForStmt(
  stmt: A.ForStmt, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): void {
  switch (stmt.form.kind) {
    case "infinite":
      break;
    case "while": {
      const got = checkExpr(stmt.form.cond, TY.bool, t, impls, diags, fn);
      if (!isAssignable(got, TY.bool)) err(diags, "T3019", stmt.form.cond.span);
      break;
    }
    case "in": {
      checkExpr(stmt.form.iter, null, t, impls, diags, fn);
      // MVP: only `RangeExpr` iters are supported (1.5b-A1). Full Iterator
      // dispatch is deferred — the lowerer emits B5001 if it sees anything
      // else, so the typecheck just narrows the binding when we recognise
      // the range form.
      const bindingSym = t.resolved.forIns.get(stmt);
      const elementTy = forInElementType(stmt.form.iter, t);
      if (bindingSym !== undefined && elementTy !== null) {
        t.narrowed.set(bindingSym.id, elementTy);
      }
      const newFn = fn !== null ? { ...fn, loopDepth: fn.loopDepth + 1 } : null;
      checkBlock(stmt.body, null, t, impls, diags, newFn);
      if (bindingSym !== undefined) t.narrowed.delete(bindingSym.id);
      return;
    }
  }
  const newFn = fn !== null ? { ...fn, loopDepth: fn.loopDepth + 1 } : null;
  checkBlock(stmt.body, null, t, impls, diags, newFn);
}

function forInElementType(iter: A.Expr, t: MutableTyped): Type | null {
  // Range has a known element type by construction.
  if (iter.kind === "RangeExpr") return TY.i32;
  // Other iterables: query the Iterator impl on the iter's static type and
  // pull the element type from its trait args.
  const iterType = t.exprTypes.get(iter);
  if (iterType === undefined) return null;
  if (iterType.kind === "Array") return iterType.element;
  const iteratorSym = t.globals.coreSymbols?.get(CORE_TRAITS.Iterator);
  if (iteratorSym === undefined) return null;
  return null;     // user-defined iterators handled when we wire a richer trait lookup
}

/** When a let-binding is destructuring (TupleBinding), synthesise a TupleType
 *  shape with `Unresolved` slots — the inferSeqLit / value-side check fills
 *  them in. Returns null for SimpleBinding (let inferSeqLit infer freely)
 *  and for fully-wildcard tuples. */
function expectedFromBinding(b: A.LetBinding): TupleType | null {
  if (b.kind !== "TupleBinding") return null;
  const elements: Type[] = b.elements.map((e) => {
    if (e.kind === "TupleBinding") return expectedFromBinding(e) ?? TY.unresolved;
    return TY.unresolved;
  });
  return { kind: "Tuple", elements };
}

/** After inferring the value's type, walk the let-binding tree and record a
 *  type for each leaf SimpleBinding so downstream phases (lower, c-emit) can
 *  query `localTypes.get(binding)`. */
function assignBindingTypes(
  b: A.LetBinding, declared: Type, t: MutableTyped, diags: DiagnosticCollector,
): void {
  switch (b.kind) {
    case "SimpleBinding":
      t.localTypes.set(b, declared);
      return;
    case "WildcardBinding":
      return;
    case "TupleBinding": {
      if (declared.kind === "Tuple") {
        if (declared.elements.length !== b.elements.length) {
          err(diags, "T3001", b.span,
            `tuple destructure expects ${b.elements.length} element(s), got ${declared.elements.length}`);
          // Best-effort : assign Unresolved to remaining leaves.
          for (const leaf of b.elements) assignBindingTypes(leaf, TY.unresolved, t, diags);
          return;
        }
        for (let i = 0; i < b.elements.length; i++) {
          assignBindingTypes(b.elements[i]!, declared.elements[i]!, t, diags);
        }
        return;
      }
      if (declared.kind === "Unresolved") {
        // Don't cascade — just propagate Unresolved to leaves.
        for (const leaf of b.elements) assignBindingTypes(leaf, TY.unresolved, t, diags);
        return;
      }
      err(diags, "T3001", b.span,
        `cannot destructure ${displayType(declared)} as a tuple`);
      for (const leaf of b.elements) assignBindingTypes(leaf, TY.unresolved, t, diags);
      return;
    }
  }
}
