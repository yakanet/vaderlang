// tests/vader-sources: shared questions about a tree of `.vader` sources.
//
// Small on purpose. It exists because two suites ask the same question and the
// second one got it wrong when it asked alone: `hook_driver` searched for the
// substring `@test`, which `std/testing`'s own doc-comment defeats.

import { existsSync, readdirSync, readFileSync, statSync } from "node:fs";
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

// Anchor on `^@test\s` rather than a substring search : `std/testing` itself
// only mentions `@test` in its module-level doc-comment, which would otherwise
// look like a test-bearing module to the walker. Decorators are always at
// column 0 (no Vader file uses indented `@test`).
const TEST_DECORATOR_RE = /^@test\s/m;

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

/** True when any `.vader` file under `dir` declares a `@test` fn. */
export function containsTestFn(dir: string): boolean {
  return listVaderFiles(dir).some((p) => TEST_DECORATOR_RE.test(readFileSync(p, "utf8")));
}
