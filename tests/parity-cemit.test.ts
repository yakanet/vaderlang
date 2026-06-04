// CLI C-emit parity (TODO §2.2) — Vader's `dump --stage=c` output.
//
// Two oracles per allowlisted snippet (see
// `.claude/plans/cemit-body-walker.md` §1) :
//   1. regression  — `dump --stage=c` matches the Vader-generated
//                    `c.snapshot` golden (catches unintended drift).
//   2. behavioural — the emitted C compiles with `cc` and runs, matching
//                    the VM-recorded `vm.snapshot` (the correctness oracle
//                    that survives the TS compiler's deletion).
//
// TS is a diagnostic reference only, never a gate here — the TS compiler
// is disposable, and on any divergence we keep the cleaner Vader output.
// The allowlist grows tranche by tranche (see the plan's §9). T0 covers
// the constant-return path only.

import { test, expect } from "bun:test";
import { join, resolve } from "node:path";
import { tmpdir } from "node:os";
import { writeFileSync } from "node:fs";

import { LONG_BUILD, runCli } from "./cli-bin.ts";
import { VM_ERROR_PREFIXES, formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
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

// Snippets whose Vader-emitted C is at parity. Grows tranche by tranche
// (see the plan's §9). T0 : the constant-return path.
const C_PARITY = new Set<string>([
  "return_42",
  // T1 scalar core : params + local.get + i32 binop + non-lit return.
  // No main (library) → the compile/run oracle skips the run, the
  // snapshot + cc-compile oracles still apply.
  "fn_decl",
  // T1b : local.set / local.tee, the prelude (local + temp decls),
  // operand materialisation, i32 add/sub/mul.
  "scalar_locals",
  // T1c : the rest of the i32 expr family — cmp (eq/ne/lt/le/gt/ge),
  // bitwise (and/or/xor), shifts (shl/shr), unary (neg/bitnot). Temp-free
  // (expression-bodied single-op fns) so byte-parity holds vs TS.
  "scalar_arith",
  // T1d : i64 / u32 / u64 / f64 families, eager integer + f64 div/rem,
  // bool.not, i32<->i64 / i32<->char conversions.
  "scalar_wide",
]);

const scenarios = listSnippets("tests/snippets").filter((s) => C_PARITY.has(s.name));

test("c-emit: allowlist resolves to real snippets", () => {
  expect(scenarios.length).toBe(C_PARITY.size);
});

for (const s of scenarios) {
  // Oracle 1 — regression vs the Vader-generated golden.
  test.concurrent(`c-emit-snapshot: ${s.name}`, async () => {
    const dump = await runCli(["dump", "--stage=c", s.mainPath]);
    const cmp = snapshotEquals(s.dir, "c.snapshot", dump.stdout);
    if (!cmp.ok) {
      throw new Error(
        `c.snapshot mismatch: ${s.name}\n  snap: ${cmp.snapPath}\n` +
        `  Run with UPDATE_SNAPSHOTS=1 to refresh.\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected ?? "", dump.stdout),
      );
    }
  }, { timeout: LONG_BUILD });

  // Oracle 2 — the emitted C compiles + runs, matching vm.snapshot.
  test.concurrent(`c-emit-run: ${s.name}`, async () => {
    if (!CC_AVAILABLE) return;
    const dump = await runCli(["dump", "--stage=c", s.mainPath]);
    const cFile = join(tmpdir(), `vader-cemit-${s.name}.c`);
    const binFile = join(tmpdir(), `vader-cemit-${s.name}${EXE_EXT}`);
    writeFileSync(cFile, dump.stdout);

    const build = Bun.spawn([
      "cc", "-std=c11", "-O0", "-I", RUNTIME_ROOT,
      cFile, join(RUNTIME_ROOT, "vader_runtime.c"),
      "-o", binFile, "-lm",
    ], { stderr: "pipe", stdout: "pipe" });
    const buildErr = await new Response(build.stderr).text();
    if ((await build.exited) !== 0) {
      throw new Error(`c-emit-run: cc failed for ${s.name}\n${buildErr}`);
    }

    const runProc = Bun.spawn([binFile], { cwd: process.cwd(), stdout: "pipe", stderr: "pipe" });
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
    try {
      expected = await Bun.file(join(s.dir, "vm.snapshot")).text();
    } catch {
      return;
    }
    if (VM_ERROR_PREFIXES.some((p) => expected.startsWith(p))) return;
    if (expected.includes("# runtime error\n")) return;

    const actual = formatRun(stdout, stderr, runExit);
    if (actual !== expected) {
      throw new Error(
        `c-emit run mismatch: ${s.name}\n  bin: ${binFile}\n\n` +
        snapshotDiff("vm.snapshot", expected, actual),
      );
    }
  }, { timeout: LONG_BUILD });
}
