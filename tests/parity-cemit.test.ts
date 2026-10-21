// CLI C-emit parity: the emitted C (`dump --stage=c`) compiles with `cc` and
// runs, matching the VM-recorded `vm.snapshot`, for every snippet that records a
// run, but those its `_config.json` excludes with a reason
// (`"native": { "skip" | "skip_on" }`). The C itself is pinned as a stage
// snapshot, `emit-c.snapshot.c`, by `snapshot.test.ts`.

import { test } from "bun:test";
import { join, resolve } from "node:path";
import { tmpdir } from "node:os";
import { existsSync, mkdtempSync, readFileSync, rmSync, writeFileSync } from "node:fs";

import { EXE_SUFFIX, LONG_BUILD, runCli } from "./cli-bin.ts";
import { VM_SNAPSHOT, exclusionReason, formatRun, listSnippets } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";

const RUNTIME_ROOT = resolve(import.meta.dir, "../runtime/c");

// `$CC` first, as `vader build` reads it (`vader/pipeline/emit.vader::default_cc`).
const CC = process.env.CC || "cc";

const CC_AVAILABLE = await (async () => {
  try {
    const proc = Bun.spawn([CC, "--version"], { stdout: "ignore", stderr: "ignore" });
    return (await proc.exited) === 0;
  } catch {
    return false;
  }
})();

const snippets = listSnippets("tests/snippets");

for (const s of snippets.filter((x) => existsSync(join(x.dir, VM_SNAPSHOT)))) {
  const excluded = exclusionReason(s.config.native);
  if (excluded !== null) {
    test.skip(`c-emit-run: ${s.name} (${excluded})`, () => {});
    continue;
  }
  // The emitted C compiles + runs, matching vm.snapshot. It is dumped for the
  // host, not for the snapshot's pinned target: it has to run here. Under
  // `VADER_VERIFY_BOUNDS` the build runs the range analysis and an access it
  // proves in bounds keeps its check under a message of its own, so a wrong
  // proof fails here instead of reading out of bounds in a release build.
  test.concurrent(`c-emit-run: ${s.name}`, async () => {
    if (!CC_AVAILABLE) return;
    const dump = await runCli(["dump", "--stage=c", s.mainPath], { VADER_VERIFY_BOUNDS: "1" });
    const cFile = join(tmpdir(), `vader-cemit-${s.name}.c`);
    const binFile = join(tmpdir(), `vader-cemit-${s.name}${EXE_SUFFIX}`);
    writeFileSync(cFile, dump.stdout);

    const build = Bun.spawn([
      // The include flags `vader build` passes (`push_include_flags`): a quoted
      // `@c_header` resolves beside the snippet's `_main.vader`.
      CC, "-std=c11", "-O0", "-fwrapv", "-I", RUNTIME_ROOT, "-iquote", RUNTIME_ROOT, "-iquote", s.dir,
      cFile, join(RUNTIME_ROOT, "vader_runtime.c"),
      // `@extern` snippets carry their foreign symbols in helper `.c`
      // files next to `_main.vader` — compile them into the binary.
      ...s.helperCFiles,
      "-o", binFile, "-lm",
    ], { stderr: "pipe", stdout: "pipe" });
    const buildErr = await new Response(build.stderr).text();
    if ((await build.exited) !== 0) {
      throw new Error(`c-emit-run: cc failed for ${s.name}\n${buildErr}`);
    }

    // The run writes its temp files in a directory of its own: the VM run of the
    // same snippet goes at the same time and writes under the same names.
    const runTmp = mkdtempSync(join(tmpdir(), `vader-cemit-${s.name}-`));
    const runEnv = { ...process.env, TMPDIR: runTmp, TMP: runTmp, TEMP: runTmp };
    const runProc = Bun.spawn([binFile], { cwd: process.cwd(), env: runEnv, stdout: "pipe", stderr: "pipe" });
    const killTimer = setTimeout(() => runProc.kill("SIGKILL"), 60_000);
    let stdout: string, stderr: string, runExit: number;
    try {
      stdout = await new Response(runProc.stdout).text();
      stderr = await new Response(runProc.stderr).text();
      runExit = await runProc.exited;
    } finally {
      clearTimeout(killTimer);
      rmSync(runTmp, { recursive: true, force: true });
    }

    const expected = readFileSync(join(s.dir, VM_SNAPSHOT), "utf8");

    const actual = formatRun(stdout, stderr, runExit);
    if (actual !== expected) {
      throw new Error(
        `c-emit run mismatch: ${s.name}\n  bin: ${binFile}\n\n` +
        snapshotDiff(VM_SNAPSHOT, expected, actual),
      );
    }
  }, { timeout: LONG_BUILD });
}
