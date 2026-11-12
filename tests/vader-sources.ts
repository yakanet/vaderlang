// tests/vader-sources: shared questions about a tree of `.vader` sources: the
// compiler's entry, the examples, the `.vader` files under a folder.

import { existsSync, readdirSync, statSync } from "node:fs";
import { join } from "node:path";

const ROOT = join(import.meta.dir, "..");

/** The compiler's own entry, the program every whole-compiler suite runs on. */
export const COMPILER_ENTRY = join(ROOT, "vader", "tools", "cli", "main.vader");

/** The examples the repo ships, by name, sorted. */
export function exampleNames(): string[] {
  return readdirSync(join(ROOT, "examples"), { withFileTypes: true })
    .filter((d) => d.isDirectory())
    .map((d) => d.name)
    .sort();
}

/** The entry of example `name`: `examples/<name>/<name>.vader`. */
export const exampleEntry = (name: string): string => join(ROOT, "examples", name, `${name}.vader`);

/** What a command is handed to work on example `name`: its folder when a
 *  `vader.json` makes it a project (a file reads none), its entry otherwise. */
export const exampleInput = (name: string): string => {
  const dir = join(ROOT, "examples", name);
  if (existsSync(join(dir, "vader.json"))) return dir;
  return exampleEntry(name);
};

/** Every `.vader` file under `dir`, recursively, in `readdir` order. `dir` may
 *  also BE a `.vader` file, in which case the answer is just that file, which is
 *  what an import path resolving to a file-form module needs.
 *
 *  The one recursion. Three hand-written copies of it lived in as many test files
 *  before this, and two of them were edited past each other. */
export function listVaderFiles(dir: string): string[] {
  let st;
  try {
    st = statSync(dir);
  } catch {
    return [];
  }
  if (st.isFile()) return dir.endsWith(".vader") ? [dir] : [];
  const out: string[] = [];
  for (const ent of readdirSync(dir, { withFileTypes: true })) {
    const p = join(dir, ent.name);
    if (ent.isDirectory()) out.push(...listVaderFiles(p));
    else if (ent.name.endsWith(".vader")) out.push(p);
  }
  return out;
}
