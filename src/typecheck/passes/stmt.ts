// Statement and block checking. Walks every statement of a fn body, checks
// each against its expected type (where applicable), and tracks loop depth /
// `Self` substitution / for-in narrowing through the FnContext.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";

import { err, warn } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { Type, TupleType } from "../types.ts";
import { CORE_TRAITS, TY, defaultIfFree, displayType, isAssignable, mkTuple, substitute } from "../types.ts";

import { buildStructSubst, tryStructSubst, type FnContext, type MutableTyped } from "../ctx.ts";
import { sourceStructDecl } from "../../resolver/symbol.ts";
import { findIteratorIntoTarget, recordIntoCoercion, tryInto } from "./coerce.ts";
import { looksLikeTypeExpression } from "./decl.ts";
import { checkExpr, resolveIndexTrait } from "./expr.ts";
import type { NarrowingScope } from "./narrow.ts";
import { popSplit, postStmtNarrowing, pushSplit } from "./narrow.ts";
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
    if (!tryInto(got, ctx.returnType, body.trailing, t, impls)) {
      err(diags, "T3020", body.trailing.span,
        `expected ${displayType(ctx.returnType)}, got ${displayType(got)}`);
    }
  }
}

export function checkBlock(
  block: A.BlockExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Narrowings that should persist across the rest of this block, applied
  // after a divergent if-guard (`if x == null { return }` ⇒ subsequent
  // statements see x narrowed). Popped in reverse at block exit so they
  // don't leak into the parent scope.
  const persistedNarrowings: { split: NarrowingScope; prev: Type | undefined }[] = [];
  // Track the first divergent statement encountered so subsequent stmts
  // (and any trailing expr) can be flagged W0002 "unreachable code". We
  // emit the warning at most ONCE per block, on the first dead stmt,
  // mirroring the conventional rustc / tsc surface.
  let firstUnreachable: A.Stmt | A.Expr | null = null;
  let diverged = false;
  for (const stmt of block.stmts) {
    if (diverged && firstUnreachable === null) firstUnreachable = stmt;
    checkStmt(stmt, t, impls, diags, fn);
    if (!diverged && divergesStmt(stmt)) diverged = true;
    const post = postStmtNarrowing(stmt, t);
    if (post !== null) {
      const split: NarrowingScope = { symId: post.symId, path: post.path };
      persistedNarrowings.push({ split, prev: pushSplit(t, split, post.type) });
    }
  }
  if (diverged && firstUnreachable === null && block.trailing !== null) {
    firstUnreachable = block.trailing;
  }
  if (firstUnreachable !== null) {
    warn(diags, "W0002", firstUnreachable.span, "code after a divergent statement");
  }
  let result: Type = TY.void;
  if (block.trailing !== null) {
    result = checkExpr(block.trailing, expected, t, impls, diags, fn);
  } else if (block.stmts.some(divergesStmt)) {
    // No trailing AND some statement diverges (return / break / continue
    // on every path, or a divergent nested match / if). The block never
    // produces a value — its type is `never`, which is assignable to any
    // return-position annotation. Lets `fn() -> T { match v { … is X →
    // return … } }` type-check without a dead `return …` after the match.
    result = TY.never;
  }
  for (let i = persistedNarrowings.length - 1; i >= 0; i--) {
    const p = persistedNarrowings[i]!;
    popSplit(t, p.split, p.prev);
  }
  t.exprTypes.set(block, result);
  return result;
}

/** True iff the expression always diverges — every control-flow path
 *  through it terminates via `return` / `break` / `continue` instead of
 *  yielding a value. Used by `checkBlock` to type a trailing-less block
 *  as `never` when its last statements never fall through. */
export function divergesExpr(expr: A.Expr): boolean {
  switch (expr.kind) {
    case "BlockExpr":  return divergesBlock(expr);
    case "IfExpr":     return expr.else !== null
      && divergesBlock(expr.then) && divergesExpr(expr.else);
    case "MatchExpr":  return expr.arms.length > 0
      && expr.arms.every((a) => divergesExpr(a.body));
    default:           return false;
  }
}

export function divergesBlock(block: A.BlockExpr): boolean {
  if (block.trailing !== null) return divergesExpr(block.trailing);
  return block.stmts.some(divergesStmt);
}

export function divergesStmt(stmt: A.Stmt): boolean {
  switch (stmt.kind) {
    case "ReturnStmt":
    case "BreakStmt":
    case "ContinueStmt": return true;
    case "ExprStmt":     return divergesExpr(stmt.expr);
    default:             return false;
  }
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
        if (!tryInto(got, expectedAnn, stmt.value, t, impls)) {
          err(diags, "T3001", stmt.span,
            `expected ${displayType(expectedAnn)}, got ${displayType(got)}`);
        }
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
      assignBindingTypes(stmt.binding, declared, t, diags);
      return;
    }
    case "AssignStmt": {
      // Bare-ident assignment to a `::`-bound local is rejected — the
      // binding form is the user's mutability contract, silently
      // re-binding has produced miscompiles in self-host code. Compound
      // assigns desugar to a plain `x = x op v` upstream, so this one
      // check covers `=`, `+=`, `-=`, ... uniformly. Field / index
      // writes (`s.f = v`, `a[i] = v`) stay allowed — a const binding
      // pins the slot identity, not the slot contents' interior
      // mutability.
      if (stmt.target.kind === "IdentExpr") {
        const targetSym = t.resolved.idents.get(stmt.target);
        if (targetSym !== undefined && targetSym.kind === "local"
            && targetSym.source.kind === "local"
            && targetSym.source.stmt.mutable === false) {
          err(diags, "T3041", stmt.target.span,
            `\`${stmt.target.name}\` is declared with \`::\` — use \`:=\` to allow mutation`,
            targetSym.definedAt !== null
              ? [{ span: targetSym.definedAt, label: "declared here" }]
              : undefined);
          return;
        }
      }
      // `a[i] = v` on a non-array target dispatches through `IndexSet($I, $T)`.
      // The trait's `set_at` consumes the value's type as `T` ; we resolve the
      // impl on the target's static type and surface the value's expected type
      // before checking the RHS.
      if (stmt.target.kind === "IndexExpr") {
        const indexed = stmt.target;
        const target = checkExpr(indexed.target, null, t, impls, diags, fn);
        const indexTy = checkExpr(indexed.index, null, t, impls, diags, fn);
        // Reject `arr[i] = v` when arr is statically `const T[]`. The runtime
        // can't honour the write either (the buf may live in .rodata) ; T3042
        // surfaces the contract at compile time.
        if (target.kind === "Array" && target.immutable) {
          err(diags, "T3042", indexed.target.span,
            `cannot mutate \`${displayType(target)}\` — declared with \`const\``);
          return;
        }
        if (target.kind === "Struct") {
          const result = resolveIndexTrait(
            indexed, target, indexTy, CORE_TRAITS.IndexSet, "set_at", "write", t, impls, diags,
          );
          if (result !== null) {
            t.indexResolutions.set(indexed, result.resolution);
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
        if (!tryInto(got, fn.returnType, stmt.value, t, impls)) {
          err(diags, "T3020", stmt.span,
            `expected ${displayType(fn.returnType)}, got ${displayType(got)}`);
        }
      }
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
      // The cond may be `bool` (true while-loop) or an iterable (sugar for
      // `for _ in <iter>`) — infer freely and dispatch on the result.
      const got = checkExpr(stmt.form.cond, null, t, impls, diags, fn);
      if (isIterableType(got, t, impls)) {
        t.whileAsForIn.set(stmt, makeDiscardSymbol(stmt, t));
      } else if (!isAssignable(got, TY.bool)) {
        err(diags, "T3019", stmt.form.cond.span);
      }
      break;
    }
    case "in": {
      const iterType = checkExpr(stmt.form.iter, null, t, impls, diags, fn);
      const bindingSym = t.resolved.forIns.get(stmt);
      let elementTy = forInElementType(stmt.form.iter, t, impls);
      // Fallback: target reaches `Iterator(T)` via `Into`. Mirrors the
      // array auto-wrap path, routed through the general Into machinery.
      if (elementTy === null) {
        const match = findIteratorIntoTarget(iterType, t, impls);
        if (match !== null) {
          recordIntoCoercion(stmt.form.iter, iterType, match.entry, match.implSubst, t);
          elementTy = match.elementType;
        }
      }
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

function isIterableType(t: Type, ctx: MutableTyped, impls: ImplRegistry): boolean {
  if (t.kind === "Array") return true;
  if (t.kind !== "Struct") return false;
  const iteratorSym = ctx.globals.coreSymbols?.get(CORE_TRAITS.Iterator);
  if (iteratorSym === undefined) return false;
  return impls.findFor(t, iteratorSym) !== null;
}

function makeDiscardSymbol(stmt: A.ForStmt, t: MutableTyped): Symbol {
  return t.globals.factory.make({
    kind: "synthetic",
    name: "_",
    module: t.resolved.module.id,
    visibility: "private",
    definedAt: stmt.span,
    source: { kind: "synthetic", origin: "for-discard" },
  });
}

function forInElementType(iter: A.Expr, t: MutableTyped, impls: ImplRegistry): Type | null {
  // Range has a known element type by construction — pull it from the
  // resolved Range[T] struct args so usize / char / i32 ranges all narrow
  // their binding to the right type.
  if (iter.kind === "RangeExpr") {
    const rangeTy = t.exprTypes.get(iter);
    if (rangeTy !== undefined && rangeTy.kind === "Struct" && rangeTy.args.length === 1) {
      return rangeTy.args[0]!;
    }
    return TY.i32;
  }
  const iterType = t.exprTypes.get(iter);
  if (iterType === undefined) return null;
  if (iterType.kind === "Array") return iterType.element;
  // Other iterables: query the `Iterator` impl on the iter's static type and
  // pull the element type from its trait args. Handles user iterators like
  // `MapIterator(i32, i32) implements Iterator(i32)` — the trait-arg `i32`
  // becomes the binding's narrowed type so `${v}` inside the body sees
  // `Primitive(i32)` rather than `Unresolved` (which would default the
  // `${…}` lowering to `append_str` and trap at runtime).
  const iteratorSym = t.globals.coreSymbols?.get(CORE_TRAITS.Iterator);
  if (iteratorSym === undefined) return null;
  const impl = impls.findFor(iterType, iteratorSym);
  if (impl === null) return null;
  if (impl.decl.traitArgs.length === 0) return null;
  const rawElement = t.globals.typeExprTypes.get(impl.decl.traitArgs[0]!);
  if (rawElement === undefined) return null;
  // The impl is generic in the receiver's typeParams (e.g. `MapIterator[T,
  // U] implements Iterator[U]`). Substitute the impl's typeParams against
  // the iter's concrete args so `Iterator[U]` resolves to `Iterator[i32]`.
  if (iterType.kind !== "Struct") return rawElement;
  const implDecl = impl.decl;
  const subst = implDecl.typeParams.length > 0
    ? buildStructSubst(implDecl.typeParams, iterType.args, t.globals.typeParamSymbols)
    : (() => {
        const structDecl = sourceStructDecl(iterType.symbol);
        if (structDecl === null) return null;
        return tryStructSubst(structDecl, iterType.args, t.globals);
      })();
  if (subst === null) return rawElement;
  return substitute(rawElement, subst);
}

/** Synthesise a TupleType skeleton with Unresolved slots for a tuple-shaped
 *  binding so the value side can fill it in. Returns null when no shape
 *  constraint applies — including the `...rest` form, where the value is
 *  array-typed and inferred freely. */
function expectedFromBinding(b: A.LetBinding): TupleType | null {
  if (b.kind !== "TupleBinding") return null;
  if (b.elements.some((e) => e.kind === "RestBinding")) return null;
  const elements: Type[] = b.elements.map((e) => {
    if (e.kind === "TupleBinding") return expectedFromBinding(e) ?? TY.unresolved;
    return TY.unresolved;
  });
  return mkTuple(elements);
}

/** After inferring the value's type, walk the let-binding tree and record a
 *  type for each leaf so downstream phases can query `localTypes.get(binding)`. */
function assignBindingTypes(
  b: A.LetBinding, declared: Type, t: MutableTyped, diags: DiagnosticCollector,
): void {
  switch (b.kind) {
    case "SimpleBinding":
    case "RestBinding":
      t.localTypes.set(b, declared);
      return;
    case "WildcardBinding":
      return;
    case "TupleBinding": {
      const restIdx = b.elements.findIndex((e) => e.kind === "RestBinding");
      const lastIdx = b.elements.length - 1;
      if (restIdx >= 0) {
        if (restIdx !== lastIdx) {
          err(diags, "T3001", b.elements[restIdx]!.span,
            "`...rest` must be the last element of a destructuring pattern");
        }
        const extraRest = b.elements.slice(restIdx + 1).find((e) => e.kind === "RestBinding");
        if (extraRest !== undefined) {
          err(diags, "T3001", extraRest.span,
            "only one `...rest` is allowed per destructuring pattern");
        }
        if (declared.kind === "Array") {
          const elemTy = declared.element;
          for (let i = 0; i < b.elements.length; i++) {
            const leaf = b.elements[i]!;
            if (leaf.kind === "RestBinding") assignBindingTypes(leaf, declared, t, diags);
            else assignBindingTypes(leaf, elemTy, t, diags);
          }
          return;
        }
        if (declared.kind === "Unresolved") {
          for (const leaf of b.elements) assignBindingTypes(leaf, TY.unresolved, t, diags);
          return;
        }
        err(diags, "T3001", b.span,
          `cannot destructure ${displayType(declared)} with a \`...rest\` pattern (only arrays support spread destructure)`);
        for (const leaf of b.elements) assignBindingTypes(leaf, TY.unresolved, t, diags);
        return;
      }
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
