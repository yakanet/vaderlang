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

  /** Symbols introduced for `:=` / `::` locals (one per leaf `SimpleBinding`,
   *  so a destructured `[a, b] := …` produces two entries — one for `a`, one
   *  for `b`). */
  readonly locals: ReadonlyMap<A.SimpleBinding, Symbol>;

  /** Symbols introduced by `for x in iter` — keyed by the ForStmt so the
   *  typechecker / lowerer can resolve `x` from the form alone. */
  readonly forIns: ReadonlyMap<A.ForStmt, Symbol>;

  /** Symbols introduced by match-arm bindings. Keyed by the AST node that
   *  *introduces* the binding (`BindingPattern`, `IsPattern` with `bindAs`,
   *  or a `StructPatternField` whose value is `binding`). The lowerer reads
   *  this map so its `LoweredLet` uses the same Symbol id that the body's
   *  `IdentExpr` resolves to via `idents` — without it, the binding's slot
   *  would be unreachable from the body. */
  readonly patternBindings: ReadonlyMap<A.IsPattern | A.BindingPattern | A.StructPatternField, Symbol>;

  /** Symbols introduced by `$T` heads on struct/trait declarations. */
  readonly typeParams: ReadonlyMap<A.TypeParam, Symbol>;

  /** Resolution of inline `$T` type-param references in fn param positions.
   *  Keyed by the `TypeParamType` AST node; value is the same symbol as the
   *  matching entry in `typeParams`. */
  readonly typeParamTypes: ReadonlyMap<A.TypeParamType, Symbol>;

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
  /** Trait bounds declared on each type parameter, keyed by its Symbol id.
   *  Populated from `where T: Trait` clauses on FnDecls and StructDecls.
   *  Consumed by the type-checker (and downstream phases) to resolve
   *  `t.method()` calls when `t` has a TypeParam type — the bound traits
   *  determine which methods are visible on a generic param. */
  readonly typeParamBounds: ReadonlyMap<number, readonly Symbol[]>;
}
