// Scoped-root scanner that builds the module index : every `.vader` file
// in a whitelisted root has its `module "..."` declaration extracted and
// indexed under the declared name. Mirrors §1.4 of docs/MODULE_SYSTEM.md.
//
// The index is the source of truth for Phase 7's strict resolver — import
// paths become name-lookups (`import "std/string"` → index["std/string"]),
// not filesystem walks. Scan-time validations live here :
//   §1.2 "same folder = same module name"      → R2022
//   §1.3 "no two folders share a name globally" → R2023
//   §1.1 "module decl present on each file"    → R2020
//   (P1028 "invalid name grammar" already fired by the parser)
//
// Symlinks are not followed (decision #39). Scan order is not guaranteed
// deterministic across platforms (decision #38) ; tests must not rely on
// which of two conflicting folders is "first".

import { lstatSync, readdirSync, readFileSync, statSync } from "node:fs";
import { join, resolve as resolvePath } from "node:path";

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import { zeroSpan } from "../diagnostics/diagnostic.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import { parseSource } from "../parser/pipeline.ts";

import { err } from "./diag.ts";
import type { SourceFile } from "./module.ts";

export interface DiscoveredModule {
  readonly name: string;
  /** Absolute path of the folder containing this module's files. */
  readonly folder: string;
  readonly files: readonly SourceFile[];
}

export type ModuleIndex = ReadonlyMap<string, DiscoveredModule>;

/** Walk each scoped root recursively (symlinks excluded), parse every
 *  `.vader` file, and bucket by `module "..."` declaration. Emits
 *  R2020/R2022/R2023 along the way. Returns the unified index.
 *
 *  A folder is the colocation unit : its direct `.vader` files must all
 *  declare the same module name. Sub-folders are walked independently
 *  and form their own modules (decision #6 — sub-modules are unrelated).
 */
export function discoverModules(
  roots: readonly string[],
  diags: DiagnosticCollector,
): ModuleIndex {
  const folderModules = new Map<string, FolderBucket>();
  for (const root of roots) walkRoot(resolvePath(root), folderModules, diags);

  const index = new Map<string, DiscoveredModule>();
  const firstSeenAt = new Map<string, Span>();
  for (const [folder, bucket] of folderModules) {
    if (bucket.name === null) continue; // already emitted R2020 for every file
    const existing = index.get(bucket.name);
    if (existing !== undefined) {
      err(diags, "R2023", bucket.firstDeclSpan,
        `module \`${bucket.name}\` already declared by another folder`,
        [{ span: firstSeenAt.get(bucket.name)!, label: "previously declared here" }]);
      continue;
    }
    index.set(bucket.name, { name: bucket.name, folder, files: bucket.files });
    firstSeenAt.set(bucket.name, bucket.firstDeclSpan);
  }
  return index;
}

interface FolderBucket {
  /** Resolved module name. Null when no file in the folder declared one
   *  (every file in the bucket already raised R2020). */
  name: string | null;
  firstDeclSpan: Span;
  files: SourceFile[];
}

function walkRoot(
  root: string,
  buckets: Map<string, FolderBucket>,
  diags: DiagnosticCollector,
): void {
  let st;
  try { st = lstatSync(root); } catch { return; }
  if (st.isSymbolicLink()) return;
  if (!st.isDirectory()) return;
  walkDir(root, buckets, diags);
}

function walkDir(
  dir: string,
  buckets: Map<string, FolderBucket>,
  diags: DiagnosticCollector,
): void {
  const filesHere: string[] = [];
  let entries: string[];
  try { entries = readdirSync(dir).sort(); } catch { return; }

  for (const name of entries) {
    const full = join(dir, name);
    let st;
    try { st = lstatSync(full); } catch { continue; }
    if (st.isSymbolicLink()) continue;
    if (st.isDirectory()) {
      walkDir(full, buckets, diags);
      continue;
    }
    if (st.isFile() && name.endsWith(".vader")) {
      filesHere.push(full);
    }
  }

  if (filesHere.length === 0) return;

  const bucket: FolderBucket = { name: null, firstDeclSpan: zeroSpan(dir), files: [] };
  for (const path of filesHere) {
    const content = readFileSync(path, "utf8");
    const parsed = parseSource(content, path);
    for (const d of parsed.diagnostics.sorted()) diags.emit(d);
    const source: SourceFile = { path: resolvePath(path), content, program: parsed.program };
    bucket.files.push(source);

    const decl = parsed.program.module;
    if (decl === null) {
      err(diags, "R2020", zeroSpan(path), `\`${relativeForMessage(path)}\``);
      continue;
    }
    if (bucket.name === null) {
      bucket.name = decl.name;
      bucket.firstDeclSpan = decl.nameSpan;
      continue;
    }
    if (decl.name !== bucket.name) {
      err(diags, "R2022", decl.nameSpan,
        `\`${decl.name}\` declared here, but \`${bucket.name}\` was declared earlier in this folder`,
        [{ span: bucket.firstDeclSpan, label: "first declaration in this folder" }]);
    }
  }

  buckets.set(dir, bucket);
}

/** Format a path for inclusion in a diagnostic message. The resolver
 *  already strips the project root in its diagnostic emitter — this
 *  helper just normalises the separator so the message reads well on
 *  Windows-style paths if we ever land there. */
function relativeForMessage(path: string): string {
  return path.split("\\").join("/");
}
