import type * as A from "../parser/ast.ts";
import type { ResolvedProgram, ResolvedProject } from "../resolver/resolved-ast.ts";
import type { ImplEntry } from "./impls.ts";
import type { Type } from "./types.ts";

export interface MethodResolution {
  /** The impl block that owns this method. */
  readonly impl: ImplEntry;
  /** The fn decl inside the impl block. */
  readonly member: A.FnDecl;
  /** Receiver type — what `self` was bound to when the method was looked up.
   *  Used by the lowerer to materialise the right impl specialisation. */
  readonly receiverType: Type;
  /** Trait args at the use site (e.g. `[i32]` for `iter` of `Iterator(i32)`). */
  readonly traitArgs: readonly Type[];
}

export interface TypedProgram {
  readonly resolved: ResolvedProgram;

  /** Type of every value-position expression in this module. */
  readonly exprTypes: ReadonlyMap<A.Expr, Type>;

  /** Type of every `:=` / `::` local in this module. */
  readonly localTypes: ReadonlyMap<A.LetStmt, Type>;

  /** Globally-shared decl/param/type-expr tables; lookup works cross-module. */
  readonly declTypes: ReadonlyMap<A.Decl, Type>;
  readonly paramTypes: ReadonlyMap<A.FnParam, Type>;
  readonly typeExprTypes: ReadonlyMap<A.TypeExpr, Type>;

  /** `obj.method` field accesses that resolved to a trait-impl method via
   *  UFCS. The lowerer reads this to rewrite `obj.method(args)` into a
   *  direct call of the impl's specialised fn with `obj` as the first arg. */
  readonly methodResolutions: ReadonlyMap<A.FieldExpr, MethodResolution>;
}

export interface TypedProject {
  readonly resolved: ResolvedProject;
  readonly modules: ReadonlyMap<string, TypedProgram>;
}
