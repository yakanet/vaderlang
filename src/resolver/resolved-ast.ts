// ResolvedProgram — the source AST plus the resolution side-tables produced
// by the name-resolution pass.
//
// We don't deep-clone the AST. Instead, every reference-bearing node is keyed
// by identity into the side-tables below. This keeps the source AST immutable
// (we never write back into it), keeps memory linear, and gives downstream
// phases (type-check, comptime, lowerer) O(1) lookup of the resolved symbol
// for any reference node they hold.

import type * as A from "../parser/ast.ts";
import type { Module } from "./module.ts";
import type { Symbol } from "./symbol.ts";
import type { ImportTargetTable } from "./wire.ts";

export interface ResolvedProgram {
  readonly module: Module;
  readonly source: A.Program;

  /** Resolution of every value-position identifier. */
  readonly idents: ReadonlyMap<A.IdentExpr, Symbol>;

  /** Resolution of every named type. */
  readonly types: ReadonlyMap<A.NamedType, Symbol>;

  /** Symbols introduced for fn params (incl. lambda params). */
  readonly params: ReadonlyMap<A.FnParam, Symbol>;

  /** Symbols introduced for `:=` / `::` locals. */
  readonly locals: ReadonlyMap<A.LetStmt, Symbol>;

  /** Symbols introduced by `for x in iter` — keyed by the ForStmt so the
   *  typechecker / lowerer can resolve `x` from the form alone. */
  readonly forIns: ReadonlyMap<A.ForStmt, Symbol>;

  /** Symbols introduced by `$T` and struct/trait `(T: type)` heads. */
  readonly typeParams: ReadonlyMap<A.TypeParam, Symbol>;

  /** When `obj.field` resolves through a module import, the field is bound here. */
  readonly fields: ReadonlyMap<A.FieldExpr, Symbol>;

  /** When `obj.method(args)` is UFCS on a free imported function, the resolved
   *  function symbol is recorded here (after import-redirect). The typechecker
   *  validates first-param compatibility and records into `MutableTyped.ufcsFreeResolutions`. */
  readonly ufcsFreeResolutions: ReadonlyMap<A.FieldExpr, Symbol>;
}

export interface ResolvedProject {
  readonly modules: ReadonlyMap<string, ResolvedProgram>;     // keyed by ModuleId
  readonly importTargets: ImportTargetTable;
  /** Cross-module typeParam table — every TypeParam AST node maps to its
   *  canonical Symbol regardless of which module declared the type. */
  readonly typeParamSymbols: ReadonlyMap<A.TypeParam, Symbol>;
}
