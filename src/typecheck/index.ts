import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Module } from "../resolver/module.ts";
import type { ResolvedProject } from "../resolver/resolved-ast.ts";
import type { ModuleId } from "../resolver/symbol.ts";

import { checkProgram, declareModule, inferExprBodiedReturns, newGlobals } from "./check.ts";
import { findCoreSymbols } from "./ctx.ts";
import { buildImplRegistry } from "./impls.ts";
import type { TypedProject, TypedProgram } from "./typed-ast.ts";

export type { TypedProgram, TypedProject } from "./typed-ast.ts";
export type { Type } from "./types.ts";
export { displayType } from "./types.ts";
export { checkProgram };

export function checkProject(project: ResolvedProject, diags: DiagnosticCollector): TypedProject {
  const impls = buildImplRegistry(project);
  const globals = newGlobals(project.typeParamSymbols, project.typeParamBounds);
  globals.coreSymbols = findCoreSymbols(project);
  const moduleMap = new Map<ModuleId, Module>();
  for (const program of project.modules.values()) moduleMap.set(program.module.id, program.module);
  globals.modules = moduleMap;

  // Pass 1: declare every module's top-level types into shared globals so that
  // cross-module references (calls into std/io, generic instantiations, etc.)
  // see concrete types when bodies are checked. Split in two so that any
  // struct field / fn signature referencing an enum sees the fully-populated
  // `Enum` type (with its `indices` map) regardless of decl order across
  // modules.
  for (const program of project.modules.values()) declareModule(program, globals, diags, "enums");
  for (const program of project.modules.values()) declareModule(program, globals, diags, "rest");

  // Pass 1.5: infer return types for expression-bodied fns (`fn(...) = expr`).
  // Runs as a fixpoint so forward references between one-liners resolve.
  inferExprBodiedReturns(project.modules, globals, impls, diags);

  // Pass 2: check expression bodies.
  const modules = new Map<string, TypedProgram>();
  for (const [id, resolved] of project.modules) {
    modules.set(id, checkProgram(resolved, globals, impls, diags));
  }
  return { resolved: project, modules };
}
