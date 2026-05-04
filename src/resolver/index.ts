import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import { makeBuiltinScope, BUILTIN_MODULE_ID, BUILTIN_TYPE_NAMES, isBuiltinTypeName } from "./builtins.ts";
import { discoverLayout, loadProject } from "./loader.ts";
import { resolveModule } from "./resolve.ts";
import { wireImports } from "./wire.ts";
import { SymbolFactory } from "./symbol.ts";
import type { LoadedProject, Module, ModuleId } from "./module.ts";
import type { ResolvedProgram, ResolvedProject } from "./resolved-ast.ts";

export type { LoadedProject, Module, SourceFile, ImportEntry, ProjectLayout } from "./module.ts";
export type { Symbol, SymbolKind, SymbolId } from "./symbol.ts";
export type { ModuleId } from "./symbol.ts";
export type { ResolvedProgram, ResolvedProject } from "./resolved-ast.ts";
export type { ImportTarget, ImportTargetTable } from "./wire.ts";
export { discoverLayout, loadProject };
export { wireImports };
export { resolveModule };
export { SymbolFactory };
export { BUILTIN_MODULE_ID, BUILTIN_TYPE_NAMES, isBuiltinTypeName };

export interface ResolveProjectOptions {
  readonly entryPath: string;
  readonly diags: DiagnosticCollector;
}

export function resolveProject(opts: ResolveProjectOptions): ResolvedProject {
  const project = loadProject({ entryPath: opts.entryPath, diags: opts.diags });
  return resolveLoadedProject(project, opts.diags);
}

export function resolveLoadedProject(project: LoadedProject, diags: DiagnosticCollector): ResolvedProject {
  const builtins = makeBuiltinScope(project.factory);
  const importTargets = wireImports(project.modules, diags);
  const coreModule = findCoreModule(project.modules);

  const resolved = new Map<ModuleId, ResolvedProgram>();
  for (const [id, mod] of project.modules) {
    const programs = resolveModule({
      module: mod,
      modules: project.modules,
      importTargets,
      builtins,
      coreModule: id === coreModule?.id ? null : coreModule,
      factory: project.factory,
      diags,
    });
    // TODO: expose per-file ResolvedPrograms once any consumer needs them;
    // for now we surface only the first file's program per module.
    if (programs.length > 0) resolved.set(id, programs[0]!);
  }
  return { modules: resolved, importTargets };
}

function findCoreModule(modules: ReadonlyMap<ModuleId, Module>): Module | null {
  for (const m of modules.values()) {
    if (m.displayPath === "std/core") return m;
  }
  return null;
}
