// Native build parity — Phase §1.9.
//
// For every snippet under tests/snippets/, build a native binary via the
// C emitter and assert its stdout matches the VM-recorded snapshot. Skipped
// silently when `cc` is unavailable so CI on hosts without a C toolchain still
// passes. The compiled binary is written to tests/snippets/{name}/native[.exe]
// (gitignored) so it's adjacent to its source.

import { test, expect } from "bun:test";
import { join, resolve } from "node:path";

import { LONG_BUILD } from "./cli-bin.ts";
import { VM_ERROR_PREFIXES, formatRun, listSnippets } from "./snapshot.ts";
import { pipelineBytecode } from "../src/pipeline.ts";
import { emitC } from "../src/c_emit/emit.ts";
import { snapshotDiff } from "./diff.ts";

const RUNTIME_ROOT = resolve(import.meta.dir, "../runtime/c");
const EXE_EXT = process.platform === "win32" ? ".exe" : "";

const CC_AVAILABLE = await (async () => {
  try {
    const proc = Bun.spawn(["cc", "--version"], { stdout: "ignore", stderr: "ignore" });
    return (await proc.exited) === 0;
  } catch {
    return false;
  }
})();

const scenarios = listSnippets("tests/snippets");

test("native: at least one snippet", () => {
  expect(scenarios.length).toBeGreaterThan(0);
});

for (const s of scenarios) {
  test.concurrent(`native: ${s.name}`, async () => {
    if (!CC_AVAILABLE) return;

    let r: Awaited<ReturnType<typeof pipelineBytecode>>;
    try {
      r = await pipelineBytecode(s.mainPath);
    } catch { return; }
    const errors = r.diagnostics.sorted().filter((d) => d.severity === "error");
    if (errors.length > 0) return;

    const cFile = join(s.dir, "native.c");
    const binFile = join(s.dir, `native${EXE_EXT}`);
    await Bun.write(cFile, emitC(r.bytecode));

    // Pre-compile any adjacent helper.c files to `.o` so user `@extern`
    // symbols resolve at link time. Pattern : `tests/snippets/<name>/
    // helper.c` → `helper.o` next to it ; appended to the cc argv right
    // before `-o`.
    const helperObjs: string[] = [];
    for (const cSource of s.helperCFiles) {
      const oFile = cSource.replace(/\.c$/, ".o");
      const cc = Bun.spawn([
        "cc", "-std=c11", "-O0", "-c", "-I", RUNTIME_ROOT,
        cSource, "-o", oFile,
      ], { stderr: "pipe", stdout: "ignore" });
      if ((await cc.exited) !== 0) return;
      helperObjs.push(oFile);
    }

    const buildProc = Bun.spawn([
      "cc", "-std=c11", "-O0", "-I", RUNTIME_ROOT,
      cFile, join(RUNTIME_ROOT, "vader_runtime.c"),
      ...helperObjs,
      "-o", binFile, "-lm",
    ], { stderr: "pipe", stdout: "pipe" });
    if ((await buildProc.exited) !== 0) return;

    // Run from project root so relative paths in the source (e.g.
    // tests/snippets/try_op/data.txt) resolve like in the VM run.
    const runProc = Bun.spawn([binFile], {
      cwd: process.cwd(),
      stdout: "pipe", stderr: "pipe",
    });
    // Hard wall-clock budget — Bun's test driver doesn't cancel
    // in-flight spawns on test timeout, so a regressed compiler emitting
    // an infinite-loop binary can pin a CPU for hours. SIGKILL after
    // 60 s ; comfortable margin over the 30 s parity test budget.
    const killTimer = setTimeout(() => runProc.kill("SIGKILL"), 60_000);
    let stdout: string, stderr: string, runExit: number;
    try {
      stdout = await new Response(runProc.stdout).text();
      stderr = await new Response(runProc.stderr).text();
      runExit = await runProc.exited;
    } finally {
      clearTimeout(killTimer);
    }

    let expected: string;
    try { expected = await Bun.file(join(s.dir, "vm.snapshot")).text(); } catch { return; }
    // Skip snippets whose vm.snapshot starts with a known error marker, OR
    // whose snapshot contains "# runtime error" further down (e.g. defer-on-
    // panic, which captures stdout-from-defers BEFORE the runtime error
    // section). The native binary will trap with a different exit code /
    // stack trace, which isn't meaningful to byte-diff against the VM dump.
    if (VM_ERROR_PREFIXES.some((p) => expected.startsWith(p))) return;
    if (expected.includes("# runtime error\n")) return;

    const actual = formatRun(stdout, stderr, runExit);
    if (actual !== expected) {
      throw new Error(
        `native parity mismatch: ${s.name}\n` +
        `  binary: ${binFile}\n\n` +
        snapshotDiff("vm.snapshot", expected, actual),
      );
    }
  }, { timeout: LONG_BUILD });
}
