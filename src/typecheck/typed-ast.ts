import type * as A from "../parser/ast.ts";
import type { ResolvedProgram, ResolvedProject } from "../resolver/resolved-ast.ts";
import type { Type } from "./types.ts";

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
}

export interface TypedProject {
  readonly resolved: ResolvedProject;
  readonly modules: ReadonlyMap<string, TypedProgram>;
}
