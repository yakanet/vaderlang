// End-to-end `vader test` smoke tests. Each `@test` fn is appended at the
// bottom of its own stdlib / self-host module (Rust-style colocation) ;
// the runner walks the target directory, builds each entry through the
// normal pipeline, and runs the discovered tests via the bytecode VM.
//
// One Bun test per top-level module (`stdlib/std/<name>` and `vader/<name>`)
// rather than a single aggregated `vader test stdlib` call : the per-test
// timeout budget then applies to one module instead of the full transitive
// closure, and `test.concurrent` parallelises modules through Bun's worker
// rather than serialising them inside the CLI.

import { test, expect } from "bun:test";
import { readdirSync, readFileSync } from "node:fs";
import { join } from "node:path";

// NOTE: still drives the TS CLI in-process. This suite is entirely `vader test
// <dir>`, and native `vader test` is a stub today (vader/cli/main.vader::
// cmd_test → "not yet implemented", exit 2). Flip to spawn build/vader (via
// cli-bin's runCli) once cmd_test is implemented natively.
import { runCli } from "../src/cli.ts";
import { LONG_BUILD } from "./cli-bin.ts";

/** Top-level subdirs of `root` that contain at least one `.vader` file
 *  carrying a `@test` decorator. Filtering keeps `vader test <dir>` from
 *  failing with "no @test functions found" (exit 2) on modules that have
 *  no tests yet (e.g. `stdlib/std/core`, `stdlib/std/runtime`). */
function findTestModules(root: string): string[] {
  const dirs: string[] = [];
  for (const ent of readdirSync(root, { withFileTypes: true })) {
    if (!ent.isDirectory()) continue;
    const sub = join(root, ent.name);
    if (containsTestFn(sub)) dirs.push(sub);
  }
  return dirs.sort();
}

// Anchor on `^@test\s` rather than a substring search : `std/testing` itself
// only mentions `@test` in its module-level doc-comment, which would
// otherwise look like a test-bearing module to the walker. Decorators are
// always at column 0 (no Vader file uses indented `@test`).
const TEST_DECORATOR_RE = /^@test\s/m;

function containsTestFn(dir: string): boolean {
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

for (const dir of findTestModules("stdlib/std")) {
  test.concurrent(`vader test ${dir}`, async () => {
    const code = await runCli(["test", dir]);
    expect(code).toBe(0);
  }, { timeout: LONG_BUILD });
}

for (const dir of findTestModules("vader")) {
  test.concurrent(`vader test ${dir}`, async () => {
    const code = await runCli(["test", dir]);
    expect(code).toBe(0);
  }, { timeout: LONG_BUILD });
}
