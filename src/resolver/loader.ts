// Module graph loader. Starts from an entry path (file or folder), walks
// imports transitively, and returns the full ModuleGraph. Detects cycles.

import { dirname, relative, resolve as resolvePath, sep } from "node:path";

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import { zeroSpan } from "../diagnostics/diagnostic.ts";

import { collectModuleSymbols } from "./collect.ts";
import { err } from "./diag.ts";
import { computeModuleFingerprints } from "./fingerprint.ts";
import {
  findManifestRoot, loadModuleSourceFiles, moduleIdFromRoot, pathKind,
  readManifest, resolveImportPath, resolveStdlibRoot,
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
  const modules = new Map<ModuleId, Module>();

  // When the entry is a single `.vader` file living inside a folder that
  // contains other `.vader` files (e.g. `vader/lexer/lexer.vader` next to
  // `token.vader` + `keywords.vader`), the file is part of a folder-module.
  // Promote the entry to the parent dir so the whole module loads —
  // otherwise cross-file references inside the same logical module surface
  // as R2006 / cascading `?` types. Mirrors Vader's `promote_to_folder_module`
  // in `vader/resolver/loader.vader`.
  const entryRoot = resolvePath(promoteToFolderModule(opts.entryPath));
  const queue: string[] = [entryRoot];
  if (opts.autoloadCore !== false) {
    const corePath = resolveImportPath("std/core", {
      fromFile: layout.entryFile ?? entryRoot,
      projectRoot: layout.projectRoot,
      stdlibRoot: layout.stdlibRoot,
    });
    if (corePath !== null) queue.push(corePath);
  }

  while (queue.length > 0) {
    const root = queue.shift()!;
    const id = moduleIdFromRoot(root);
    if (modules.has(id)) continue;

    const files = loadModuleSourceFiles(root, opts.diags);
    if (files.length === 0) {
      err(opts.diags, "R2015", zeroSpan(root), `\`${root}\``);
      continue;
    }

    const collected = collectModuleSymbols({
      moduleId: id,
      files,
      factory,
      diags: opts.diags,
      projectRoot: layout.projectRoot,
      stdlibRoot: layout.stdlibRoot,
    });

    modules.set(id, {
      id,
      displayPath: displayPathFor(root, layout),
      rootDir: root,
      files,
      symbols: collected.symbols,
      fnOverloads: collected.fnOverloads,
      imports: collected.imports,
      fingerprint: "",     // populated by computeModuleFingerprints below
    });

    for (const imp of collected.imports) {
      if (imp.resolvedTo !== null && !modules.has(imp.resolvedTo)) {
        queue.push(imp.resolvedTo);
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

/** If `entryPath` is a `.vader` file inside a folder with sibling `.vader`
 *  files, return the parent folder so the loader treats them as one module.
 *  Single-file folders (e.g. `stdlib/std/json.vader`) keep file-as-module
 *  semantics. */
const VADER_SIBLING_GLOB = new Bun.Glob("*.vader");

function promoteToFolderModule(entryPath: string): string {
  if (!entryPath.endsWith(".vader")) return entryPath;
  if (pathKind(entryPath) !== "file") return entryPath;
  const parent = dirname(entryPath);
  let count = 0;
  try {
    for (const _ of VADER_SIBLING_GLOB.scanSync({ cwd: parent, onlyFiles: true })) {
      if (++count > 1) return parent;
    }
  } catch { return entryPath; }
  return entryPath;
}

function displayPathFor(root: string, layout: ProjectLayout): string {
  const fromStdlib = relativeUnder(root, layout.stdlibRoot);
  if (fromStdlib !== null) return fromStdlib.replace(/\.vader$/, "");
  if (layout.projectRoot !== null) {
    const fromProject = relativeUnder(root, layout.projectRoot);
    if (fromProject !== null) return fromProject.length > 0 ? fromProject : ".";
  }
  return root;
}

/** Return `path` relative to `base` iff `path` is `base` or under it; null otherwise. */
function relativeUnder(path: string, base: string): string | null {
  if (path === base) return "";
  if (!path.startsWith(base + sep)) return null;
  return relative(base, path).split(sep).join("/");
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

