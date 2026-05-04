// Module graph loader. Starts from an entry path (file or folder), walks
// imports transitively, and returns the full ModuleGraph. Detects cycles.

import { relative, resolve as resolvePath, sep } from "node:path";

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";

import { collectModuleSymbols } from "./collect.ts";
import { err } from "./diag.ts";
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

  const entryRoot = resolvePath(opts.entryPath);
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
      imports: collected.imports,
    });

    for (const imp of collected.imports) {
      if (imp.resolvedTo !== null && !modules.has(imp.resolvedTo)) {
        queue.push(imp.resolvedTo);
      }
    }
  }

  detectCycles(modules, opts.diags);

  return { layout, modules, factory };
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
  const WHITE = 0, GRAY = 1, BLACK = 2;
  const color = new Map<ModuleId, number>();
  for (const id of modules.keys()) color.set(id, WHITE);

  const stack: ModuleId[] = [];
  const visit = (id: ModuleId): void => {
    color.set(id, GRAY);
    stack.push(id);
    const mod = modules.get(id);
    if (mod === undefined) { stack.pop(); color.set(id, BLACK); return; }
    for (const imp of mod.imports) {
      if (imp.resolvedTo === null) continue;
      const c = color.get(imp.resolvedTo) ?? WHITE;
      if (c === GRAY) {
        const cycleStart = stack.indexOf(imp.resolvedTo);
        const cycle = stack.slice(cycleStart).concat([imp.resolvedTo]);
        err(diags, "R2005", imp.span,
          cycle.map((m) => modules.get(m)?.displayPath ?? m).join(" → "));
      } else if (c === WHITE) {
        visit(imp.resolvedTo);
      }
    }
    stack.pop();
    color.set(id, BLACK);
  };

  for (const id of modules.keys()) {
    if (color.get(id) === WHITE) visit(id);
  }
}

function zeroSpan(file: string): Span {
  const p = { file, offset: 0, line: 1, column: 1 };
  return { start: p, end: p };
}
