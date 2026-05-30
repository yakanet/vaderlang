import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Module } from "../resolver/module.ts";
import type { ResolvedProject } from "../resolver/resolved-ast.ts";
import type { ModuleId } from "../resolver/symbol.ts";

import { checkProgram, declareModule, inferExprBodiedReturns, newGlobals } from "./check.ts";
import { findCoreSymbols } from "./ctx.ts";
import { buildImplRegistry } from "./impls.ts";
import { inheritStructBounds } from "./passes/inherit-bounds.ts";
import { validateStructBounds } from "./passes/struct-bounds.ts";
import { buildSlotRegistry } from "./trait-slots.ts";
import type { TypedProject, TypedProgram } from "./typed-ast.ts";

export type { TypedProgram, TypedProject } from "./typed-ast.ts";
export type { Type } from "./types.ts";
export { displayType } from "./types.ts";
export { checkProgram };

export function checkProject(project: ResolvedProject, diags: DiagnosticCollector): TypedProject {
  const impls = buildImplRegistry(project);
  const globals = newGlobals(project.typeParamSymbols, project.typeParamBounds, project.factory);
  globals.coreSymbols = findCoreSymbols(project);
  const moduleMap = new Map<ModuleId, Module>();
  for (const program of project.modules.values()) moduleMap.set(program.module.id, program.module);
  globals.modules = moduleMap;

  // Pass 1: declare every module's top-level types into shared globals so that
  // cross-module references (calls into std/io, generic instantiations, etc.)
  // see concrete types when bodies are checked. Split in three so that:
  //   - enums : any struct field / fn signature referencing an enum sees the
  //     fully-populated `Enum` type (with its `indices` map) regardless of
  //     decl order across modules.
  //   - type-aliases (TypeAliasDecl + ConstDecl-as-implicit-alias) : cross-
  //     module use of `T[]` / `T | U` etc. in a fn signature needs the alias
  //     resolved before the consumer module's `declareFn` runs, otherwise
  //     `typeFromSymbol` returns Unresolved and the param shows up as `?[]`.
  //   - rest : fn signatures, impls, structs/traits, regular consts.
  for (const program of project.modules.values()) declareModule(program, globals, diags, "enums");
  for (const program of project.modules.values()) declareModule(program, globals, diags, "type-aliases");
  for (const program of project.modules.values()) declareModule(program, globals, diags, "rest");

  // Pass 1.5: infer return types for expression-bodied fns (`fn(...) = expr`).
  // Runs as a fixpoint so forward references between one-liners resolve.
  inferExprBodiedReturns(project.modules, globals, impls, diags);

  // Pass 1.6: auto-inherit struct-level type-param bounds onto fn type-params.
  // Lets methods drop the `[K: Hash & Equals, V]` repetition when the struct
  // already declares the bound. Must run before `checkProgram` so trait-bound
  // dispatch inside method bodies (e.g. `key.hash()`) sees the inherited
  // bound and resolves statically.
  inheritStructBounds(project, globals, diags);

  // Pass 2: check expression bodies.
  const modules = new Map<string, TypedProgram>();
  for (const [id, resolved] of project.modules) {
    modules.set(id, checkProgram(resolved, globals, impls, diags, id === project.entryModuleId));
  }

  // Pass 3: validate struct-level bounds at every instantiation site.
  // Runs once per project ; reads `globals.typeExprTypes` to find every
  // struct-with-args reference (annotations, struct lits, generic-impl
  // for-types, …) and emits T3006 when a concrete arg doesn't satisfy
  // the declared bound on its formal type-param.
  validateStructBounds(globals, impls, diags);

  // Pass 4: build the trait-method slot registry (Phase 0 of the erasure
  // plan). Pinned slots for the std/core traits are assigned at construction;
  // user-defined trait methods get slots after sorting alphabetically.
  const traitSlots = buildSlotRegistry(project);

  return { resolved: project, modules, traitSlots };
}
