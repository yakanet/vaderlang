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
import type { Symbol, SymbolFactory } from "./symbol.ts";
import type { ImportTargetTable } from "./wire.ts";

export interface ResolvedProgram {
  readonly module: Module;
  readonly source: A.Program;

  /** Resolution of every value-position identifier. */
  readonly idents: ReadonlyMap<A.IdentExpr, Symbol>;

  /** Resolution of every name-reference appearing in type position
   *  (`StructField.type`, fn param/return types, `where` clauses, …).
   *  Keyed by node identity ; does not collide with `idents` even though
   *  both maps now use `IdentExpr` keys, because the parser produces
   *  distinct objects for type-position vs value-position references. */
  readonly types: ReadonlyMap<A.IdentExpr, Symbol>;

  /** Symbols introduced for fn params (incl. lambda params). */
  readonly params: ReadonlyMap<A.FnParam, Symbol>;

  /** Symbols introduced for `:=` / `::` locals (one per leaf `SimpleBinding`
   *  or `RestBinding`, so a destructured `[a, ...rest] := …` produces two
   *  entries — one for `a`, one for `rest`). */
  readonly locals: ReadonlyMap<A.SimpleBinding | A.RestBinding, Symbol>;

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
   *  Keyed by the `IdentExpr` AST node (carrying `isTypeParamIntro: true`) ;
   *  value is the same symbol as the matching entry in `typeParams`. */
  readonly typeParamTypes: ReadonlyMap<A.IdentExpr, Symbol>;

  /** Per-`FieldExpr` resolution — exactly one of the two kinds holds for
   *  any given node, by construction of the resolver (namespace exports
   *  and UFCS-free-fn candidates are matched in different code paths and
   *  never both populate the same node). Replaces the former two parallel
   *  Maps (`fields` + `ufcsFreeResolutions`). */
  readonly fieldRefs: ReadonlyMap<A.FieldExpr, FieldRef>;
}

/** Resolution recorded by the name-resolver for a `FieldExpr`. The typer
 *  reads this to decide whether `obj.x` is a re-exported namespace member
 *  (rewrite to a direct reference) or a UFCS candidate against a free fn
 *  (validate first-param compatibility, then rewrite the call). */
export type FieldRef =
  | { readonly kind: "namespace"; readonly symbol: Symbol }
  | { readonly kind: "ufcs-free"; readonly symbol: Symbol };

export interface ResolvedProject {
  readonly modules: ReadonlyMap<string, ResolvedProgram>;     // keyed by ModuleId
  readonly importTargets: ImportTargetTable;
  /** Shared symbol id allocator — downstream phases that mint synthetic
   *  symbols (typecheck, lower) must use this so ids stay globally unique. */
  readonly factory: SymbolFactory;
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
