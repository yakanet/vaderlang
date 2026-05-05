// Shared context types threaded through every typecheck pass.
//
// `Globals` is built once per project (newGlobals) and accumulates the
// declared types of every top-level decl. `MutableTyped` is built once per
// module and carries the per-expression / per-local maps the pass writes.
// `FnContext` tracks per-fn-body state (return type, self type, loop depth)
// while statements / expressions inside that body are checked.

import type * as A from "../parser/ast.ts";
import type { ResolvedProgram } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { MethodResolution } from "./typed-ast.ts";
import type { Type } from "./types.ts";

/** Tables shared across modules — populated by declareTypes, consumed by check bodies. */
export interface Globals {
  readonly declTypes: Map<A.Decl, Type>;
  readonly paramTypes: Map<A.FnParam, Type>;
  readonly typeExprTypes: Map<A.TypeExpr, Type>;
  /** Auto-imported std/core symbols, looked up for Display / Error / Iterator etc. */
  coreSymbols: ReadonlyMap<string, Symbol> | null;
  /** Cross-module typeParam table from the resolver — used for O(1) lookup
   *  when user code instantiates a generic stdlib struct and we need its
   *  typeParam symbols. */
  typeParamSymbols: ReadonlyMap<A.TypeParam, Symbol>;
}

export function newGlobals(typeParamSymbols: ReadonlyMap<A.TypeParam, Symbol>): Globals {
  return {
    declTypes: new Map(), paramTypes: new Map(), typeExprTypes: new Map(),
    coreSymbols: null,
    typeParamSymbols,
  };
}

export interface MutableTyped {
  readonly resolved: ResolvedProgram;
  readonly globals: Globals;
  readonly exprTypes: Map<A.Expr, Type>;
  readonly localTypes: Map<A.LetStmt, Type>;
  /** Active narrowings keyed by symbol.id. Push/pop-managed by `inferMatch`
   *  so that references to a scrutinee symbol inside an `is T -> body` arm
   *  see `T` instead of the full union. Nested matches stack naturally. */
  readonly narrowed: Map<number, Type>;
  /** UFCS-resolved trait method calls. Populated by `inferField`, consumed
   *  by `inferCall` and the lowerer. */
  readonly methodResolutions: Map<A.FieldExpr, MethodResolution>;
  /** Built-in array method calls (`len`, `push`). Populated by `inferField`,
   *  consumed by the lowerer to emit `LoweredArrayLen`/`LoweredArrayPush`. */
  readonly arrayOps: Map<A.FieldExpr, "len" | "push">;
}

export interface FnContext {
  readonly returnType: Type;
  /** Self type when type-checking a method body inside an impl block. */
  readonly selfType: Type | null;
  loopDepth: number;
}
