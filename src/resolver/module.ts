// Module graph: each module = one folder of .vader files (per SPEC §11) OR a
// single-file module (used in stdlib and `vader run hello.vader`).
//
// Module IDs are canonicalized absolute paths so the same physical location
// always maps to the same ID across resolution passes.

import { existsSync, readdirSync, readFileSync, statSync } from "node:fs";
import { dirname, isAbsolute, join, resolve as resolvePath } from "node:path";

import type { Span } from "../diagnostics/diagnostic.ts";
import type { Program } from "../parser/ast.ts";
import { parseSource } from "../parser/pipeline.ts";
import type { DiagnosticCollector } from "../diagnostics/collector.ts";

import type { ModuleId, Symbol, SymbolFactory } from "./symbol.ts";

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
  readonly symbols: ReadonlyMap<string, Symbol>;
  readonly imports: readonly ImportEntry[];
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
}

// ---------------------------------------------------------------- path setup

export interface VaderManifest {
  readonly name?: string;
  readonly version?: string;
  readonly entries?: Record<string, string>;
  readonly stdlib?: string;
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
  // Fallback: <repo-root>/stdlib (where the compiler lives) — works during dev.
  // import.meta.dir points at this source file's directory: src/resolver/
  // Repo root is two levels up.
  const compilerRoot = resolvePath(import.meta.dir, "..", "..");
  const candidate = join(compilerRoot, "stdlib");
  if (existsSync(candidate)) return candidate;
  // Last resort: cwd/stdlib.
  return resolvePath(process.cwd(), "stdlib");
}

// -------------------------------------------------------- module discovery

export interface ResolveImportOptions {
  readonly fromFile: string;        // absolute path of the file containing the import
  readonly projectRoot: string | null;
  readonly stdlibRoot: string;
}

/** Resolve a raw `import "path"` string to an on-disk module location, or null. */
export function resolveImportPath(rawPath: string, opts: ResolveImportOptions): string | null {
  if (rawPath.startsWith("std/")) {
    return resolveStdlibImport(rawPath, opts.stdlibRoot);
  }
  if (rawPath.startsWith("./") || rawPath.startsWith("../")) {
    return resolveOnDisk(join(dirname(opts.fromFile), rawPath));
  }
  if (opts.projectRoot !== null) {
    return resolveOnDisk(join(opts.projectRoot, rawPath));
  }
  // Single-file mode: try relative to fromFile.
  return resolveOnDisk(join(dirname(opts.fromFile), rawPath));
}

function resolveStdlibImport(path: string, stdlibRoot: string): string | null {
  return resolveOnDisk(join(stdlibRoot, path));
}

export function pathKind(p: string): "dir" | "file" | null {
  if (!existsSync(p)) return null;
  const s = statSync(p);
  return s.isDirectory() ? "dir" : s.isFile() ? "file" : null;
}

function resolveOnDisk(path: string): string | null {
  if (pathKind(path) === "dir") return resolvePath(path);
  const withExt = path.endsWith(".vader") ? path : `${path}.vader`;
  if (pathKind(withExt) === "file") return resolvePath(withExt);
  return null;
}

// ----------------------------------------------------- single-module loading

/** Load a single module's source files (folder → all *.vader, file → just that file). */
export function loadModuleSourceFiles(rootPath: string, diags: DiagnosticCollector): SourceFile[] {
  const out: SourceFile[] = [];
  const stat = statSync(rootPath);
  const files = stat.isDirectory()
    ? readdirSync(rootPath)
        .filter((n) => n.endsWith(".vader"))
        .map((n) => join(rootPath, n))
        .sort()
    : [rootPath];

  for (const file of files) {
    const content = readFileSync(file, "utf8");
    const { program, diagnostics } = parseSource(content, file);
    for (const d of diagnostics.sorted()) diags.emit(d);
    out.push({ path: resolvePath(file), content, program });
  }
  return out;
}

export function moduleIdFromRoot(rootPath: string): ModuleId {
  return resolvePath(rootPath);
}
