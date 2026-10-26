// End-to-end `vader test` smoke tests. Each `@test` fn is appended at the
// bottom of its own stdlib / self-host module (Rust-style colocation) ;
// the runner walks the target directory, builds each entry through the
// normal pipeline, and runs the discovered tests via the bytecode VM.
//
// One Bun test per top-level module (`lib/std/<name>` and `vader/<name>`)
// rather than a single aggregated `vader test lib` call : the per-test
// timeout budget then applies to one module instead of the full transitive
// closure, and a failure names its module.

import { test, expect } from "bun:test";

// Drives the NATIVE `vader test` (build/vader): native `cmd_test` runs the
// discovered `@test` fns on the bytecode VM. The TS CLI is decommissioned and
// cannot compile the Target-ABI stdlib (the byte-Buffer StringBuilder, the
// `std/core` `bytes` primitive, the memory opcodes), so this suite must spawn
// the self-hosted binary, which is the snapshot/run oracle everywhere else.
import { runCli, LONG_BUILD } from "./cli-bin.ts";
import { findTestModules, listVaderFiles } from "./vader-sources.ts";
import { readFileSync } from "fs";

const TEST_DECORATORS_RE = /^@test\s/gm;

// Filtering keeps `vader test <dir>` from failing with "no @test functions found"
// (exit 2) on modules that have none yet (`lib/std/core`, `lib/std/runtime`).
//
// Serial (not `test.concurrent`) : each module spawns the native build/vader
// (compile + VM-run its @tests), far heavier than the former in-process TS CLI:
// 30+ concurrent spawns starve the CPU and trip the per-run kill timer. Bun still
// parallelises across test FILES, so this only serialises modules within this file.
for (const dir of [...findTestModules("lib"), ...findTestModules("vader")]) {
  test(`vader test ${dir}`, async () => {
    const { exit, stdout, stderr } = await runCli(["test", dir], undefined, LONG_BUILD);
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
    const declared = listVaderFiles(dir)
      .map((f) => readFileSync(f, "utf8").match(TEST_DECORATORS_RE)?.length ?? 0)
      .reduce((a, b) => a + b, 0);
    expect(Number(/(\d+) tests \|/.exec(stdout)?.[1])).toBe(declared);
  }, { timeout: LONG_BUILD });
}
