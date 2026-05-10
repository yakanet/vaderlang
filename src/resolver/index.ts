import type {DiagnosticCollector} from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";
import {BUILTIN_MODULE_ID, BUILTIN_TYPE_NAMES, isBuiltinTypeName, makeBuiltinScope} from "./builtins.ts";
import {discoverLayout, loadProject} from "./loader.ts";
import {resolveModule} from "./resolve.ts";
import {wireImports} from "./wire.ts";
import type {ImportTargetTable} from "./wire.ts";
import type {ModuleId, Symbol} from "./symbol.ts";
import {SymbolFactory} from "./symbol.ts";
import type {LoadedProject, Module} from "./module.ts";
import type {ResolvedProgram, ResolvedProject} from "./resolved-ast.ts";

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
  // Now that imports are wired, follow each import-binding in every module's
  // fnOverloads bucket to its concrete fn target. Lets UFCS dispatch see
  // imported fns alongside local ones for overload-by-receiver-type ; in
  // particular, `std/path::is_empty(self: Path)` and the imported
  // `std/string::is_empty(s: string)` end up as two entries in path's
  // `is_empty` overload set, and `self.repr.is_empty()` picks the string
  // version while `path.is_empty()` picks the local one.
  resolveImportOverloads(project.modules, importTargets);
  const coreModule = findCoreModule(project.modules);
  // Shared cross-module typeParam table — populated as each module's
  // resolver binds its struct/fn typeParams. Generic impls need this to
  // reuse the canonical typeParam symbol of the base struct (potentially
  // declared in another module, e.g. `std/core::ArrayIter`).
  const typeParamSymbols = new Map<A.TypeParam, Symbol>();
  // Cross-module table of trait bounds per TypeParam — populated by every
  // `where T: Trait` clause encountered during resolution. Keyed by the
  // TypeParam Symbol's id so an impl method's body can find the bounds
  // declared on the surrounding struct without duplicating the lookup logic.
  const typeParamBounds = new Map<number, Symbol[]>();

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
      typeParamSymbols,
      typeParamBounds,
    });
    const merged = mergeFilePrograms(programs);
    if (merged !== null) resolved.set(id, merged);
  }
  return { modules: resolved, importTargets, typeParamSymbols, typeParamBounds, factory: project.factory };
}

/** Walk every module's `fnOverloads` map and replace any import-binding
 *  entries with their resolved fn target (when the target is a fn). Lets
 *  UFCS dispatch in the typechecker treat imported fns as overloads of
 *  same-named local fns — `std/path::is_empty(self: Path)` and the
 *  imported `std/string::is_empty(s: string)` end up sitting side-by-side
 *  in path's `is_empty` overload set, ranked by receiver type at every
 *  use site. Entries whose target isn't a fn (missing imports, struct or
 *  trait imports under the same name, …) are dropped from the bucket — the
 *  original errors still flow through `wireImports`'s diagnostics. */
function resolveImportOverloads(
  modules: ReadonlyMap<ModuleId, Module>,
  importTargets: ImportTargetTable,
): void {
  for (const mod of modules.values()) {
    const buckets = mod.fnOverloads as Map<string, Symbol[]>;
    for (const [name, bucket] of buckets) {
      let changed = false;
      const next: Symbol[] = [];
      for (const sym of bucket) {
        if (sym.kind !== "import-binding") {
          next.push(sym);
          continue;
        }
        const target = importTargets.get(sym.id);
        if (target?.kind === "symbol" && target.symbol.kind === "fn") {
          next.push(target.symbol);
          changed = true;
        } else {
          // Unwireable / non-fn import — drop from the overload set. The
          // import-target diagnostic was already emitted.
          changed = true;
        }
      }
      if (changed) buckets.set(name, next);
    }
  }
}

/** Fold the per-file `ResolvedProgram`s of a multi-file module into one.
 *  All resolution side-tables are keyed by AST node identity, so a flat
 *  `Map.set(...)` merge is enough. The synthetic `source.decls` concatenates
 *  every file's top-level decls in load order; per-decl spans still carry
 *  their original file path, so diagnostics aren't affected. */
function mergeFilePrograms(programs: readonly ResolvedProgram[]): ResolvedProgram | null {
  if (programs.length === 0) return null;
  if (programs.length === 1) return programs[0]!;
  const first = programs[0]!;
  const allDecls: A.Decl[] = [];
  for (const p of programs) allDecls.push(...p.source.decls);
  const source: A.Program = {
    kind: "Program",
    file: first.module.rootDir,
    span: first.source.span,
    decls: allDecls,
  };
  const merge = <K, V>(maps: ReadonlyArray<ReadonlyMap<K, V>>): Map<K, V> => {
    const out = new Map<K, V>();
    for (const m of maps) for (const [k, v] of m) out.set(k, v);
    return out;
  };
  return {
    module: first.module,
    source,
    idents: merge(programs.map((p) => p.idents)),
    types: merge(programs.map((p) => p.types)),
    params: merge(programs.map((p) => p.params)),
    locals: merge(programs.map((p) => p.locals)),
    forIns: merge(programs.map((p) => p.forIns)),
    typeParams: merge(programs.map((p) => p.typeParams)),
    typeParamTypes: merge(programs.map((p) => p.typeParamTypes)),
    fields: merge(programs.map((p) => p.fields)),
    ufcsFreeResolutions: merge(programs.map((p) => p.ufcsFreeResolutions)),
    patternBindings: merge(programs.map((p) => p.patternBindings)),
  };
}

function findCoreModule(modules: ReadonlyMap<ModuleId, Module>): Module | null {
  for (const m of modules.values()) {
    if (m.displayPath === "std/core") return m;
  }
  return null;
}
