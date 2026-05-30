// Module graph: each module = one folder of .vader files (per SPEC §11) OR a
// single-file module (used in stdlib and `vader run hello.vader`).
//
// Module IDs are canonicalized absolute paths so the same physical location
// always maps to the same ID across resolution passes.

import { existsSync, readFileSync, statSync } from "node:fs";
import { dirname, isAbsolute, join, resolve as resolvePath } from "node:path";

import type { Span } from "../diagnostics/diagnostic.ts";
import type { Program } from "../parser/ast.ts";
import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import { runtimeRoots } from "../runtime-resources.ts";

import { err } from "./diag.ts";
import type { ModuleIndex } from "./discover.ts";
import type { ModuleId, Symbol, SymbolFactory } from "./symbol.ts";

/** `import "std/…"` and the `displayPath` of any stdlib module both start
 *  with this prefix. Centralised so DCE / dump filtering / import resolution
 *  agree on what counts as stdlib. */
export const STDLIB_PATH_PREFIX = "std/";

export function isStdlibModule(displayPath: string): boolean {
  return displayPath.startsWith(STDLIB_PATH_PREFIX);
}

export interface SourceFile {
  readonly path: string;
  readonly content: string;
  readonly program: Program;
}

export interface Module {
  readonly id: ModuleId;
  readonly displayPath: string;          // e.g. "std/io" or "./local"
  readonly rootDir: string;              // canonical absolute folder path
  readonly files: readonly SourceFile[];
  /** Primary symbol per name. For an overloaded fn name (e.g. `get` declared
   *  multiple times with different first-param types), this holds the first
   *  declaration. Most callers want this — for overload-aware dispatch query
   *  `fnOverloads` instead. */
  readonly symbols: ReadonlyMap<string, Symbol>;
  /** All fn-kind decls grouped by name (overload set). Each entry has at
   *  least one symbol — its `[0]` is the same Symbol as `symbols.get(name)`.
   *  Length > 1 only for overloaded names. Populated by the resolver's
   *  `collect` pass. */
  readonly fnOverloads: ReadonlyMap<string, readonly Symbol[]>;
  readonly imports: readonly ImportEntry[];
  /** Hex SHA-256 of `(displayPath + sorted file contents + sorted dep
   *  fingerprints)`. Same source + same deps → same fingerprint, so a
   *  future caching layer can skip re-typecheck/re-lower when this hasn't
   *  changed. Computed by the loader in topological order; the empty
   *  string is a "not yet computed" sentinel that should never be
   *  observed by downstream passes. */
  readonly fingerprint: string;
}

export interface ImportEntry {
  readonly span: Span;
  readonly fromFile: string;
  readonly path: string;                 // raw `import "path"` text
  readonly resolvedTo: ModuleId | null;  // null if path could not be resolved
}

export interface ProjectLayout {
  readonly projectRoot: string | null;   // null in pure single-file mode
  readonly stdlibRoot: string;
  readonly entryFile: string | null;     // single-file entry, when used
}

export interface LoadedProject {
  readonly layout: ProjectLayout;
  readonly modules: ReadonlyMap<ModuleId, Module>;
  readonly factory: SymbolFactory;        // shared across passes; one ID space
  /** Module id of the entry file's module — the code under compilation, as
   *  opposed to imported libraries. `null` when the entry couldn't be located.
   *  Threaded to typecheck so user-facing body diagnostics (e.g. W0004) fire
   *  only for the entry module. */
  readonly entryModuleId: ModuleId | null;
}

// ---------------------------------------------------------------- path setup

export interface VaderManifest {
  readonly name?: string;
  readonly version?: string;
  readonly entries?: Record<string, string>;
  readonly stdlib?: string;
  /** Explicit list of source roots to scan for module declarations.
   *  Stdlib resolution is independent (see `resolveStdlibRoot`).
   *  Paths are literal folders ; glob patterns are not supported. */
  readonly modules?: readonly string[];
}

export function findManifestRoot(start: string): string | null {
  let dir = isAbsolute(start) ? start : resolvePath(start);
  if (!existsSync(dir)) return null;
  if (!statSync(dir).isDirectory()) dir = dirname(dir);
  // Walk upward until we hit a vader.json (or the filesystem root).
  while (true) {
    if (existsSync(join(dir, "vader.json"))) return dir;
    const parent = dirname(dir);
    if (parent === dir) return null;
    dir = parent;
  }
}

/** Trust boundary anchor for the comptime sandbox's `@file` containment.
 *  Prefers the nearest `vader.json` directory; falls back to the entry
 *  file's dir when no manifest exists (e.g. ad-hoc snippets, tests). */
export function defaultProjectRoot(entryFile: string): string {
  return findManifestRoot(entryFile) ?? resolvePath(dirname(entryFile));
}

export function readManifest(projectRoot: string): VaderManifest | null {
  const manifestPath = join(projectRoot, "vader.json");
  if (!existsSync(manifestPath)) return null;
  try {
    return JSON.parse(readFileSync(manifestPath, "utf8")) as VaderManifest;
  } catch {
    return null;
  }
}

export function resolveStdlibRoot(projectRoot: string | null, manifest: VaderManifest | null): string {
  if (manifest?.stdlib !== undefined && projectRoot !== null) {
    const p = isAbsolute(manifest.stdlib) ? manifest.stdlib : join(projectRoot, manifest.stdlib);
    if (existsSync(p)) return resolvePath(p);
  }
  // The helper probes sidecar (compiled binary) and dev layouts, with a
  // cwd-relative fallback as a last resort.
  return runtimeRoots().stdlibRoot;
}

// -------------------------------------------------------- module discovery

export interface ResolveImportOptions {
  /** Module index built by `discoverModules` — the strict resolver's
   *  source of truth. Import paths are resolved by name-lookup against
   *  this index ; there is no filesystem fallback. */
  readonly index: ModuleIndex;
  /** Module name of the file containing the import, used for self-import
   *  detection and for the std/core-redundancy check. Null only at the
   *  bootstrap step that locates the entry module. */
  readonly fromModuleName: string | null;
  /** Span of the offending `import "..."` literal — used as the primary
   *  span for any diagnostic the lookup emits. */
  readonly span: Span;
  readonly diags: DiagnosticCollector;
}

/** Resolve `import "name"` to the target module's folder via the
 *  project-wide module index. Emits R2025 / R2024 / R2028 / R2001
 *  on the respective failure paths. */
export function resolveImportPath(rawPath: string, opts: ResolveImportOptions): string | null {
  if (rawPath.startsWith("./") || rawPath.startsWith("../")) {
    err(opts.diags, "R2025", opts.span, `\`${rawPath}\``);
    return null;
  }
  if (opts.fromModuleName !== null && rawPath === opts.fromModuleName) {
    err(opts.diags, "R2024", opts.span, `\`${rawPath}\``);
    return null;
  }
  if (rawPath === "std/core" && opts.fromModuleName !== "std/core") {
    err(opts.diags, "R2028", opts.span);
    return null;
  }
  const target = opts.index.get(rawPath);
  if (target === undefined) {
    err(opts.diags, "R2001", opts.span, `\`${rawPath}\``);
    return null;
  }
  return target.folder;
}

export function pathKind(p: string): "dir" | "file" | null {
  if (!existsSync(p)) return null;
  const s = statSync(p);
  return s.isDirectory() ? "dir" : s.isFile() ? "file" : null;
}

export function moduleIdFromRoot(rootPath: string): ModuleId {
  return resolvePath(rootPath);
}
