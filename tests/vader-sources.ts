// tests/vader-sources — shared questions about a tree of `.vader` sources.
//
// Small on purpose. It exists because two suites ask the same question and the
// second one got it wrong when it asked alone: `hook_driver` searched for the
// substring `@test`, which `std/testing`'s own doc-comment defeats. The answer
// below is the one `vader_e2e` had already paid for.

import { readdirSync, readFileSync } from "node:fs";
import { join } from "node:path";

// Anchor on `^@test\s` rather than a substring search : `std/testing` itself
// only mentions `@test` in its module-level doc-comment, which would otherwise
// look like a test-bearing module to the walker. Decorators are always at
// column 0 (no Vader file uses indented `@test`).
export const TEST_DECORATOR_RE = /^@test\s/m;

/** True when `dir` ITSELF holds a test-bearing `.vader` — no recursion.
 *
 *  The module-shaped question, where `containsTestFn` asks the subtree-shaped
 *  one. A walker looking for module directories needs this: `lib/std` and
 *  `lib/toolchain` hold no `.vader` of their own, and answering "yes, something
 *  under me has tests" would register them as modules and re-run their whole
 *  subtree. Same regex, deliberately — a third caller inventing its own
 *  substring check is exactly what this file exists to prevent. */
export function holdsTestFile(dir: string): boolean {
  for (const ent of readdirSync(dir, { withFileTypes: true })) {
    if (ent.isDirectory() || !ent.name.endsWith(".vader")) continue;
    if (TEST_DECORATOR_RE.test(readFileSync(join(dir, ent.name), "utf8"))) return true;
  }
  return false;
}

/** True when any `.vader` file under `dir` declares a `@test` fn. */
export function containsTestFn(dir: string): boolean {
  for (const ent of readdirSync(dir, { withFileTypes: true })) {
    const p = join(dir, ent.name);
    if (ent.isDirectory()) {
      if (containsTestFn(p)) return true;
      continue;
    }
    if (!ent.name.endsWith(".vader")) continue;
    if (TEST_DECORATOR_RE.test(readFileSync(p, "utf8"))) return true;
  }
  return false;
}
