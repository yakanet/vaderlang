// Module graph loader. Phase 7 of the module-system rollout : the
// strict resolver discovers every module under the scoped roots
// upfront (via `discover.ts`), then BFS-walks the import graph by
// name-lookup against that index. No filesystem fallbacks.

import { dirname, join, resolve as resolvePath, sep } from "node:path";

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import { zeroSpan } from "../diagnostics/diagnostic.ts";

import { collectModuleSymbols } from "./collect.ts";
import { err } from "./diag.ts";
import { discoverModules, type DiscoveredModule, type ModuleIndex } from "./discover.ts";
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

  // 1. Build the scoped-roots list per §2 of docs/MODULE_SYSTEM.md :
  //    stdlib (always) + vader.json::modules (when present) + the entry
  //    file's containing folder when it lies outside the whitelist
  //    (CLI fallback, §2.3). Single-folder repos rely entirely on the
  //    fallback ; manifest-driven projects pin down what to scan.
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

  // 2. Scan + validate (R2020/R2022/R2023) → name-indexed module table.
  const index = discoverModules(scopedRoots, opts.diags);

  // 3. Locate the entry's module via folder-match. The discover scan
  //    bucketed every .vader file by its containing folder, so a single
  //    lookup is enough.
  const entryModule = findModuleByFolder(entryFolder, index);
  const modules = new Map<ModuleId, Module>();
  if (entryModule === null) {
    err(opts.diags, "R2001", zeroSpan(entryAbs),
      `entry file's containing folder is not in any scanned root`);
    return { layout, modules, factory };
  }

  // 4. Pre-load std/core so the prelude (§1.5) is reachable from every
  //    other module. The loader doesn't yet *inject* its exports into
  //    every scope — that's the resolver's job downstream — but it must
  //    at least make the module known.
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
      const target = findModuleByFolder(imp.resolvedTo, index);
      if (target !== null && !modules.has(moduleIdFromDiscovered(target))) {
        queue.push(target);
      }
    }
  }

  detectCycles(modules, opts.diags);
  // Compute fingerprints in topological order so each module's hash sees
  // its dependencies' final fingerprints. Phase 1 only exposes the value;
  // phase 2 wires it into the parser cache.
  computeModuleFingerprints(modules);

  return { layout, modules, factory };
}

/** Use the resolved folder path as the canonical module identifier, so
 *  `Module.id` keeps the same shape as the pre-Phase-7 loader (downstream
 *  side-tables key on absolute paths). */
function moduleIdFromDiscovered(m: DiscoveredModule): ModuleId {
  return m.folder;
}

function findModuleByFolder(folder: string, index: ModuleIndex): DiscoveredModule | null {
  const canonical = resolvePath(folder);
  for (const m of index.values()) {
    if (m.folder === canonical) return m;
  }
  return null;
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
