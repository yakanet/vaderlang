// `vader run <file>` runs the `main` DECLARED in the named file — not an
// arbitrary entry from the containing folder. Sibling files in one folder merge
// into a single module (folder = module), so a folder can hold several `main`
// fns; the VM's default entry is the first `is_main` fn, which is blind to which
// file was named. The regression: `vader run dir/b.vader` silently ran
// `dir/a.vader`'s `main`. See `vader/cli/main.vader::entry_index_for_file`.
//
// A module that declares no `main` has nothing to start at: `run` and `build`
// refuse it, naming the file.
//
// Each `main` returns a DISTINCT exit code so the assertion needs no stdlib
// (no `std/io`/`std/core` resolution from a tmp dir outside the project
// manifest) — the process exit code is the entry fn's return value.

import { test, expect } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { runCli, MEDIUM_BUILD, LONG_BUILD } from "./cli-bin.ts";

// Two programs in one folder-module, each with its own `main`. `alpha.vader`'s
// no-arg `main` sorts first (the entry the old default would always pick);
// `zeta.vader`'s `argv` `main` has a different signature, so the duplicate-fn
// check (T3053, signature-keyed) does NOT collapse them — both stay `is_main`.
const ALPHA = `module "scratch"\nmain :: fn() -> i32 {\n    return 7\n}\n`;
const ZETA = `module "scratch"\nmain :: fn(argv: string[]) -> i32 {\n    return 9\n}\n`;

test("run picks the main of the named file, not the folder's first", async () => {
  const dir = mkdtempSync(join(tmpdir(), "vader-run-entry-"));
  try {
    writeFileSync(join(dir, "alpha.vader"), ALPHA);
    writeFileSync(join(dir, "zeta.vader"), ZETA);

    // Naming the alphabetically-LATER file must run ITS main (exit 9), not the
    // first-declared `alpha` main (exit 7) the VM default would pick.
    const zeta = await runCli(["run", join(dir, "zeta.vader")], undefined, MEDIUM_BUILD);
    expect(zeta.exit).toBe(9);

    // Naming the first file still runs its own main (exit 7).
    const alpha = await runCli(["run", join(dir, "alpha.vader")], undefined, MEDIUM_BUILD);
    expect(alpha.exit).toBe(7);
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}, LONG_BUILD);

const NO_MAIN = `module "scratch"\nshout :: fn() -> i32 {\n    return 3\n}\n`;

test("run and build refuse a module that declares no main", async () => {
  const dir = mkdtempSync(join(tmpdir(), "vader-no-main-"));
  try {
    const file = join(dir, "lib.vader");
    writeFileSync(file, NO_MAIN);
    const run = await runCli(["run", file], undefined, MEDIUM_BUILD);
    expect(run.exit).toBe(1);
    expect(run.stderr).toContain("declares no `main`");
    const build = await runCli(["build", "--emit=c", "--out=-", file], undefined, MEDIUM_BUILD);
    expect(build.exit).toBe(1);
    expect(build.stdout).toBe("");
    expect(build.stderr).toContain("declares no `main`");
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}, LONG_BUILD);
