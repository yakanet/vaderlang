// End-to-end `vader test` smoke tests. Each `@test` fn is appended at the
// bottom of its own stdlib / self-host module (Rust-style colocation) ;
// the runner walks the target directory, builds each entry through the
// normal pipeline, and runs the discovered tests via the bytecode VM.
//
// One Bun test per directory `findTestModules` yields (`lib/std/<name>`,
// `vader/<name>`) rather than a single aggregated `vader test lib` call : the
// timeout budget then covers the modules of one run instead of the whole tree,
// and a failure names its directory.

import { test, expect } from "bun:test";

// Drives the NATIVE `vader test` (build/vader): native `cmd_test` runs the
// discovered `@test` fns on the bytecode VM. The TS CLI is decommissioned and
// cannot compile the Target-ABI stdlib (the byte-Buffer StringBuilder, the
// `std/core` `bytes` primitive, the memory opcodes), so this suite must spawn
// the self-hosted binary, which is the snapshot/run oracle everywhere else.
import { runCli, LONG_BUILD } from "./cli-bin.ts";
import { findTestModules, listVaderFiles } from "./vader-sources.ts";
import { readFileSync } from "fs";
import { dirname } from "path";

const TEST_DECORATORS_RE = /^@test\s/gm;

// Filtering keeps `vader test <dir>` from failing with "no @test functions found"
// (exit 2) on modules that have none yet (`lib/std/core`, `lib/std/runtime`).
//
// Serial (not `test.concurrent`) : each module spawns the native build/vader
// (compile + VM-run its @tests), far heavier than the former in-process TS CLI:
// 30+ concurrent spawns starve the CPU and trip the per-run kill timer. Bun still
// parallelises across test FILES, so this only serialises modules within this file.
for (const dir of [...findTestModules("lib"), ...findTestModules("vader")]) {
  const testCounts = listVaderFiles(dir).map(
    (f) => [f, readFileSync(f, "utf8").match(TEST_DECORATORS_RE)?.length ?? 0] as const,
  );
  const declared = testCounts.reduce((sum, [, n]) => sum + n, 0);
  // `findTestModules` stops at the first directory holding a `@test`, which folds
  // the modules below it into this run, and `vader test` compiles them one after
  // the other: one `LONG_BUILD` per module that declares a test.
  const modules = new Set(testCounts.filter(([, n]) => n > 0).map(([f]) => dirname(f))).size;
  const budget = LONG_BUILD * modules;
  test(`vader test ${dir}`, async () => {
    const { exit, stdout, stderr } = await runCli(["test", dir], undefined, budget);
    // Surface the subprocess output on failure. Asserting the exit code alone
    // made a red CI say only "expected 0, received 1" for a run of dozens of
    // module tests: the one that actually failed, and its trap message, were
    // thrown away. Diagnosing it then needed a machine of that OS.
    if (exit !== 0) {
      throw new Error(`vader test ${dir} exited ${exit}\n--- stdout ---\n${stdout}\n--- stderr ---\n${stderr}`);
    }
    // Every `@test` declared under the module ran : a subtree the runner skips
    // (a directory name it ignores, a module folded into another) shows here
    // instead of passing in silence.
    expect(Number(/(\d+) tests \|/.exec(stdout)?.[1])).toBe(declared);
  }, { timeout: budget });
}
