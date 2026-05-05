// Native build parity — Phase §1.9.
//
// For every snapshot under tests/snapshots/vm/, build a native binary via the
// C emitter and assert its stdout matches the VM-recorded snapshot. Skipped
// silently when `cc` is unavailable so CI on hosts without a C toolchain still
// passes.

import { test, expect } from "bun:test";
import { mkdtempSync } from "node:fs";
import { tmpdir } from "node:os";
import { dirname, join, resolve } from "node:path";

import { listScenarios } from "./snapshot.ts";
import { pipelineBytecode } from "../src/pipeline.ts";
import { emitC } from "../src/c_emit/emit.ts";

const RUNTIME_ROOT = resolve(import.meta.dir, "../runtime/c");

async function ccAvailable(): Promise<boolean> {
  try {
    const proc = Bun.spawn(["cc", "--version"], { stdout: "ignore", stderr: "ignore" });
    return (await proc.exited) === 0;
  } catch {
    return false;
  }
}

test("native: snapshot parity", async () => {
  if (!(await ccAvailable())) {
    console.warn("native test: cc not available, skipping");
    return;
  }

  const scenarios = listScenarios("tests/snapshots/vm");
  expect(scenarios.length).toBeGreaterThan(0);

  for (const s of scenarios) {
    const r = await pipelineBytecode(s.inputPath);
    const errors = r.diagnostics.sorted().filter((d) => d.severity === "error");
    expect(errors).toEqual([]);

    const tmp = mkdtempSync(join(tmpdir(), "vader-native-"));
    const cFile = join(tmp, "program.c");
    const binFile = join(tmp, "program");
    await Bun.write(cFile, emitC(r.bytecode));

    const buildProc = Bun.spawn([
      "cc", "-std=c11", "-O0", "-I", RUNTIME_ROOT,
      cFile, join(RUNTIME_ROOT, "vader_runtime.c"), "-o", binFile,
    ], { stderr: "pipe", stdout: "pipe" });
    const buildExit = await buildProc.exited;
    if (buildExit !== 0) {
      const stderr = await new Response(buildProc.stderr).text();
      throw new Error(`native build failed for ${s.name}: cc exit ${buildExit}\n${stderr}\nC source: ${cFile}`);
    }

    // Run from project root so relative paths in the source (e.g.
    // tests/snapshots/vm/try_op/data.txt) resolve like in the VM run.
    const runProc = Bun.spawn([binFile], {
      cwd: process.cwd(),
      stdout: "pipe", stderr: "pipe",
    });
    const stdout = await new Response(runProc.stdout).text();
    const stderr = await new Response(runProc.stderr).text();
    const runExit = await runProc.exited;

    const expected = await Bun.file(join(s.dir, "stdout.snap")).text();
    const actual = formatRun(stdout, stderr, runExit);
    if (actual !== expected) {
      throw new Error(
        `native parity mismatch: ${s.name}\n` +
        `  binary: ${binFile}\n` +
        `  expected:\n${expected}\n  actual:\n${actual}`,
      );
    }
    void dirname;
  }
});

function formatRun(stdout: string, stderr: string, exit: number): string {
  const parts: string[] = [];
  if (stdout.length > 0) parts.push("# stdout\n" + stdout);
  if (stderr.length > 0) parts.push("# stderr\n" + stderr);
  parts.push(`# exit\n${exit}\n`);
  return parts.join("");
}
