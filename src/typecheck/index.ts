import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { ResolvedProject } from "../resolver/resolved-ast.ts";

import { checkProgram, declareModule, newGlobals } from "./check.ts";
import { buildImplRegistry } from "./impls.ts";
import type { TypedProject, TypedProgram } from "./typed-ast.ts";

export type { TypedProgram, TypedProject } from "./typed-ast.ts";
export type { Type } from "./types.ts";
export { displayType } from "./types.ts";
export { checkProgram };

export function checkProject(project: ResolvedProject, diags: DiagnosticCollector): TypedProject {
  const impls = buildImplRegistry(project);
  const globals = newGlobals(project.typeParamSymbols);
  for (const program of project.modules.values()) {
    if (program.module.displayPath === "std/core") {
      globals.coreSymbols = program.module.symbols;
      break;
    }
  }

  // Pass 1: declare every module's top-level types into shared globals so that
  // cross-module references (calls into std/io, generic instantiations, etc.)
  // see concrete types when bodies are checked.
  for (const program of project.modules.values()) declareModule(program, globals, diags);

  // Pass 2: check expression bodies.
  const modules = new Map<string, TypedProgram>();
  for (const [id, resolved] of project.modules) {
    modules.set(id, checkProgram(resolved, globals, impls, diags));
  }
  return { resolved: project, modules };
}
