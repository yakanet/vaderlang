// Type-table accessor for a lowering pass — hides the (typed, subst) pair
// behind a single object. Lower passes call `ctx.types.exprType(e)` etc.
// instead of `applySubst(ctx.typed.exprTypes.get(e) ?? TY.unresolved,
// ctx.subst)`. The internals stay lazy (no pre-substitution) — but the
// boundary is now isolated, so a future change to materialise typed
// substituted bodies in MonoEntry only touches this file.

import type * as A from "../parser/ast.ts";
import type { Substitution, Type } from "../typecheck/types.ts";
import { TY, substitute } from "../typecheck/types.ts";
import type { TypedProgram } from "../typecheck/typed-ast.ts";

function isEmptySubst(s: Substitution): boolean {
  return (s.typeParams === undefined || s.typeParams.size === 0) && s.self === undefined;
}

/** Per-entry view over the underlying TypedProgram, with the entry's
 *  substitution already applied at every read. Lower passes consume this
 *  API and never reference `subst` directly. */
export interface EntryTypes {
  /** Apply the entry's substitution to an arbitrary Type. */
  apply(t: Type): Type;
  /** Per-table accessors. Each falls back to `TY.unresolved` when the node
   *  has no recorded type — same convention as the inline lookups they
   *  replaced. */
  exprType(expr: A.Expr): Type;
  localType(binding: A.SimpleBinding): Type;
  paramType(param: A.FnParam): Type;
  typeExprType(typeExpr: A.TypeExpr): Type;
  declType(decl: A.FnDecl | A.StructDecl | A.ConstDecl | A.EnumDecl | A.TypeAliasDecl): Type;
}

export function makeEntryTypes(typed: TypedProgram, subst: Substitution): EntryTypes {
  // Empty subst: every accessor is a Map.get + nullish — no substitution
  // ever runs, no caching needed. Hot for non-generic decls (the common case).
  if (isEmptySubst(subst)) {
    return {
      apply:        (t) => t,
      exprType:     (e) => typed.exprTypes.get(e)     ?? TY.unresolved,
      localType:    (s) => typed.localTypes.get(s)    ?? TY.unresolved,
      paramType:    (p) => typed.paramTypes.get(p)    ?? TY.unresolved,
      typeExprType: (e) => typed.typeExprTypes.get(e) ?? TY.unresolved,
      declType:     (d) => typed.declTypes.get(d)     ?? TY.unresolved,
    };
  }
  // Non-empty subst: `substitute(t, subst)` walks the Type tree and rebuilds
  // it via `.map`. The same Type can be read 2-3× per AST node during
  // lowering — memoise per-Type to avoid redundant rebuilds. WeakMap so the
  // cache GC's with the EntryTypes instance (one cache per fn lowering).
  const cache = new WeakMap<object, Type>();
  const a = (t: Type): Type => {
    const cached = cache.get(t as unknown as object);
    if (cached !== undefined) return cached;
    const out = substitute(t, subst);
    cache.set(t as unknown as object, out);
    return out;
  };
  return {
    apply:        a,
    exprType:     (e) => a(typed.exprTypes.get(e)     ?? TY.unresolved),
    localType:    (s) => a(typed.localTypes.get(s)    ?? TY.unresolved),
    paramType:    (p) => a(typed.paramTypes.get(p)    ?? TY.unresolved),
    typeExprType: (e) => a(typed.typeExprTypes.get(e) ?? TY.unresolved),
    declType:     (d) => a(typed.declTypes.get(d)     ?? TY.unresolved),
  };
}
