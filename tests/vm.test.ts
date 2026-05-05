// VM snapshot tests — Phase §1.8.
//
// Each scenario lives in tests/snapshots/vm/<name>/input.vader, optionally
// alongside fixture files (e.g. data.txt for try_op). The driver compiles
// the input via the full TS pipeline, runs `main` with a captured `HostIO`
// (stdout in memory, file ops on disk so fixtures work), and asserts the
// captured stdout/exit pair matches stdout.snap.
//
// Refresh snapshots with `UPDATE_SNAPSHOTS=1 bun test`.

import { test, expect } from "bun:test";
import { readFileSync, writeFileSync } from "node:fs";

import { listScenarios, snapshotEquals } from "./snapshot.ts";
import { pipelineBytecode } from "../src/pipeline.ts";
import { runProgram, makeBindings, type HostIO } from "../src/vm/index.ts";

interface Captured {
  readonly out: string[];
  readonly err: string[];
  readonly io: HostIO;
}

function captureIO(): Captured {
  const out: string[] = [];
  const err: string[] = [];
  return {
    out, err,
    io: {
      write(s)         { out.push(s); },
      writeError(s)    { err.push(s); },
      readLine()       { return null; },
      readFile(path)   { return readFileSync(path, "utf8"); },
      writeFile(p, c)  { writeFileSync(p, c, "utf8"); },
      exists(p) {
        try { readFileSync(p); return true; } catch { return false; }
      },
    },
  };
}

test("vm: snapshots", async () => {
  const scenarios = listScenarios("tests/snapshots/vm");
  expect(scenarios.length).toBeGreaterThan(0);

  for (const s of scenarios) {
    const r = await pipelineBytecode(s.inputPath);
    const diags = r.diagnostics.sorted();
    const errors = diags.filter((d) => d.severity === "error");
    expect(errors.map((d) => `[${d.code}] ${d.message}`)).toEqual([]);

    const cap = captureIO();
    const result = runProgram(r.bytecode, { host: makeBindings(cap.io), opLimit: 1_000_000 });

    const actual = formatRun(cap.out.join(""), cap.err.join(""), result.exitCode);
    const cmp = snapshotEquals(s.dir, "stdout.snap", actual);
    if (!cmp.ok) {
      throw new Error(
        `vm snapshot mismatch: ${s.name}\n` +
        `  snap: ${cmp.snapPath}\n` +
        `  expected:\n${cmp.expected ?? "<missing>"}\n` +
        `  actual:\n${actual}`,
      );
    }
  }
});

function formatRun(stdout: string, stderr: string, exit: number): string {
  const parts: string[] = [];
  if (stdout.length > 0) parts.push("# stdout\n" + stdout);
  if (stderr.length > 0) parts.push("# stderr\n" + stderr);
  parts.push(`# exit\n${exit}\n`);
  return parts.join("");
}
