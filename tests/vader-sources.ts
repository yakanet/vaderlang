// tests/vader-sources — shared questions about a tree of `.vader` sources.
//
// Small on purpose. It exists because two suites ask the same question and the
// second one got it wrong when it asked alone: `hook_driver` searched for the
// substring `@test`, which `std/testing`'s own doc-comment defeats. The answer
// below is the one `vader_e2e` had already paid for.

import { readdirSync, readFileSync, statSync } from "node:fs";
import { join } from "node:path";

// Anchor on `^@test\s` rather than a substring search : `std/testing` itself
// only mentions `@test` in its module-level doc-comment, which would otherwise
// look like a test-bearing module to the walker. Decorators are always at
// column 0 (no Vader file uses indented `@test`).
export const TEST_DECORATOR_RE = /^@test\s/m;

/** Every `.vader` file under `dir`, recursively, in `readdir` order. `dir` may
 *  also BE a `.vader` file, in which case the answer is just that file — which is
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

/** True when `dir` ITSELF holds a test-bearing `.vader` — no recursion.
 *
 *  DIRECTLY is the load-bearing word. A walker looking for module directories
 *  needs this question and not the subtree-shaped one: `lib/std` and
 *  `lib/toolchain` hold no `.vader` of their own, and answering "yes, something
 *  under me has tests" would register them as modules and re-run their whole
 *  subtree. */
export function holdsTestFile(dir: string): boolean {
  for (const ent of readdirSync(dir, { withFileTypes: true })) {
    if (ent.isDirectory() || !ent.name.endsWith(".vader")) continue;
    if (TEST_DECORATOR_RE.test(readFileSync(join(dir, ent.name), "utf8"))) return true;
  }
  return false;
}

/** True when any `.vader` file under `dir` declares a `@test` fn. */
export function containsTestFn(dir: string): boolean {
  return listVaderFiles(dir).some((p) => TEST_DECORATOR_RE.test(readFileSync(p, "utf8")));
}

/** Every module directory under `root` that carries a `@test`, sorted.
 *
 *  One walker for every root, and it names no level: descend until a directory
 *  holds a test file, register it, and stop there. Naming levels is how discovery
 *  silently loses modules — first `lib/std` by name when the build contract moved
 *  out of `vader/` (33 tests, no warning), then `lib/<ns>` when the libraries left
 *  `std/` and each became a leaf (25 more). An undiscovered module is simply
 *  skipped (CLAUDE §11.1), so nothing reports the loss.
 *
 *  Verified to reproduce, exactly, the two hand-tuned walkers it replaces: 15
 *  modules under `vader/` (where holding a test directly and holding one deeply
 *  coincide for all 22 subdirs) and 22 under `lib/` (where no test-bearing
 *  directory has a subdirectory at all).
 *
 *  Paths are normalised to `/` : these are Vader module paths, and `join` yields
 *  `\` on Windows — which would miss a caller's skip-list lookup and run a
 *  skipped-everywhere-else module to a CI timeout. */
export function findTestModules(root: string): string[] {
  const dirs: string[] = [];
  const visit = (dir: string) => {
    const norm = dir.replaceAll("\\", "/");
    if (holdsTestFile(norm)) {
      dirs.push(norm);
      return;
    }
    for (const ent of readdirSync(dir, { withFileTypes: true })) {
      if (ent.isDirectory()) visit(join(dir, ent.name));
    }
  };
  for (const ent of readdirSync(root, { withFileTypes: true })) {
    if (ent.isDirectory()) visit(join(root, ent.name));
  }
  return dirs.sort();
}
