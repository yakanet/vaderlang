// Module graph loader. Discovers every module under the scoped roots
// upfront (via `discover.ts`), then BFS-walks the import graph by
// name-lookup against that index. No filesystem fallbacks.

import { dirname, join, resolve as resolvePath, sep } from "node:path";

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import { zeroSpan } from "../diagnostics/diagnostic.ts";

import { collectModuleSymbols } from "./collect.ts";
import { err } from "./diag.ts";
import { discoverModules, type DiscoveredModule } from "./discover.ts";
import { computeModuleFingerprints } from "./fingerprint.ts";
import {
  findManifestRoot, pathKind, readManifest, resolveStdlibRoot,
} from "./module.ts";
import type { LoadedProject, Module, ProjectLayout } from "./module.ts";
import type { ModuleId } from "./symbol.ts";
import { SymbolFactory } from "./symbol.ts";

export interface LoadOptions {
  readonly entryPath: string;
  readonly diags: DiagnosticCollector;
  /** When false, std/core is *not* preloaded. Used by stdlib's own tests. */
  readonly autoloadCore?: boolean;
}

/** Discover the project layout for an arbitrary entry path. */
export function discoverLayout(entryPath: string): ProjectLayout {
  const abs = resolvePath(entryPath);
  const projectRoot = findManifestRoot(abs);
  const manifest = projectRoot !== null ? readManifest(projectRoot) : null;
  const stdlibRoot = resolveStdlibRoot(projectRoot, manifest);
  return { projectRoot, stdlibRoot, entryFile: pathKind(abs) === "file" ? abs : null };
}

export function loadProject(opts: LoadOptions): LoadedProject {
  const layout = discoverLayout(opts.entryPath);
  const factory = new SymbolFactory();

  // Scoped roots : stdlib (always) + vader.json::modules (when present) +
  // the entry file's containing folder when it lies outside the whitelist
  // (CLI fallback). Single-folder repos rely entirely on the fallback ;
  // manifest-driven projects pin down what to scan.
  const manifest = layout.projectRoot !== null ? readManifest(layout.projectRoot) : null;
  const scopedRoots: string[] = [layout.stdlibRoot];
  if (manifest?.modules !== undefined && layout.projectRoot !== null) {
    for (const m of manifest.modules) {
      scopedRoots.push(resolvePath(join(layout.projectRoot, m)));
    }
  }
  const entryAbs = resolvePath(opts.entryPath);
  const entryFolder = layout.entryFile !== null ? dirname(entryAbs) : entryAbs;
  if (!isUnderAnyRoot(entryFolder, scopedRoots)) {
    scopedRoots.push(entryFolder);
  }

  // Scan scoped roots into a name-indexed module table + a parallel
  // folder→module reverse map for O(1) lookups during BFS.
  const index = discoverModules(scopedRoots, opts.diags);
  const byFolder = new Map<string, DiscoveredModule>();
  for (const m of index.values()) byFolder.set(m.folder, m);

  const entryModule = byFolder.get(resolvePath(entryFolder)) ?? null;
  const modules = new Map<ModuleId, Module>();
  if (entryModule === null) {
    err(opts.diags, "R2001", zeroSpan(entryAbs),
      `entry file's containing folder is not in any scanned root`);
    return { layout, modules, factory };
  }

  const queue: DiscoveredModule[] = [entryModule];
  const coreModule = opts.autoloadCore !== false ? index.get("std/core") : undefined;
  if (coreModule !== undefined && coreModule !== entryModule) {
    queue.push(coreModule);
  }

  while (queue.length > 0) {
    const m = queue.shift()!;
    const id = moduleIdFromDiscovered(m);
    if (modules.has(id)) continue;

    const collected = collectModuleSymbols({
      moduleId: id,
      moduleName: m.name,
      files: m.files,
      factory,
      diags: opts.diags,
      index,
    });

    modules.set(id, {
      id,
      displayPath: m.name,
      rootDir: m.folder,
      files: m.files,
      symbols: collected.symbols,
      fnOverloads: collected.fnOverloads,
      imports: collected.imports,
      fingerprint: "",
    });

    for (const imp of collected.imports) {
      if (imp.resolvedTo === null) continue;
      const target = byFolder.get(imp.resolvedTo);
      if (target !== undefined && !modules.has(moduleIdFromDiscovered(target))) {
        queue.push(target);
      }
    }
  }

  detectCycles(modules, opts.diags);
  computeModuleFingerprints(modules);

  return { layout, modules, factory };
}

/** Resolved folder path as the canonical module identifier — downstream
 *  side-tables key on absolute paths, not on module names. */
function moduleIdFromDiscovered(m: DiscoveredModule): ModuleId {
  return m.folder;
}

function isUnderAnyRoot(folder: string, roots: readonly string[]): boolean {
  const canonical = resolvePath(folder);
  for (const root of roots) {
    const rootAbs = resolvePath(root);
    if (canonical === rootAbs) return true;
    if (canonical.startsWith(rootAbs + sep)) return true;
  }
  return false;
}

function detectCycles(modules: ReadonlyMap<ModuleId, Module>, diags: DiagnosticCollector): void {
  // Iterative tri-color DFS — recursive form would blow the JS stack on deep
  // import chains (~10k frames is the typical V8/Bun limit). Each frame keeps
  // an index into its module's import list so we can resume after recursing.
  const WHITE = 0, GRAY = 1, BLACK = 2;
  const color = new Map<ModuleId, number>();
  for (const id of modules.keys()) color.set(id, WHITE);

  interface Frame {
    readonly id: ModuleId;
    readonly imports: readonly Module["imports"][number][];
    cursor: number;
  }
  const path: ModuleId[] = [];

  const visit = (start: ModuleId): void => {
    const startMod = modules.get(start);
    if (startMod === undefined) { color.set(start, BLACK); return; }
    color.set(start, GRAY);
    path.push(start);
    const stack: Frame[] = [{ id: start, imports: startMod.imports, cursor: 0 }];

    while (stack.length > 0) {
      const top = stack[stack.length - 1]!;
      if (top.cursor >= top.imports.length) {
        stack.pop();
        path.pop();
        color.set(top.id, BLACK);
        continue;
      }
      const imp = top.imports[top.cursor++]!;
      if (imp.resolvedTo === null) continue;
      const c = color.get(imp.resolvedTo) ?? WHITE;
      if (c === GRAY) {
        const cycleStart = path.indexOf(imp.resolvedTo);
        const cycle = path.slice(cycleStart).concat([imp.resolvedTo]);
        err(diags, "R2005", imp.span,
          cycle.map((m) => modules.get(m)?.displayPath ?? m).join(" → "));
      } else if (c === WHITE) {
        const childMod = modules.get(imp.resolvedTo);
        if (childMod === undefined) {
          color.set(imp.resolvedTo, BLACK);
          continue;
        }
        color.set(imp.resolvedTo, GRAY);
        path.push(imp.resolvedTo);
        stack.push({ id: imp.resolvedTo, imports: childMod.imports, cursor: 0 });
      }
    }
  };

  for (const id of modules.keys()) {
    if (color.get(id) === WHITE) visit(id);
  }
}
