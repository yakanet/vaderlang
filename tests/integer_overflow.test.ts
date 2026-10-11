// An integer `+`, `-`, `*` or unary `-` stops the run on overflow outside
// `--release`, and wraps in it. The `integer_overflow_traps` snippet pins the VM
// in its `vm.snapshot` ; this file builds it natively both ways: a debug build
// prints the same lines, then stops on the overflow the VM stops on, and a release
// build prints the wrapped value instead.
import { expect, test } from "bun:test";
import { readFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { EXE_SUFFIX, LONG_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const SNIPPET_DIR = "tests/snippets/integer_overflow_traps";

// The lines the VM prints before it stops: the `# stdout` section of `vm.snapshot`.
function vmStdout(): string[] {
  const snapshot = readFileSync(join(SNIPPET_DIR, "vm.snapshot"), "utf8");
  return snapshot.split("# stdout\n")[1]!.split("\n# ")[0]!.trimEnd().split("\n");
}

// Build the snippet with `flags` into a binary named after `mode`, and run it.
async function buildAndRun(mode: string, flags: string[]) {
  const bin = join(tmpdir(), `vader-integer-overflow-${mode}-${process.pid}${EXE_SUFFIX}`);
  const main = join(SNIPPET_DIR, "_main.vader");
  const build = await runCli(["build", ...flags, `--out=${bin}`, main], undefined, LONG_BUILD);
  expect(build.exit).toBe(0);
  return spawnCapture([], { bin, timeoutMs: 10_000 });
}

test("a debug build stops on an integer overflow, as the VM does", async () => {
  if (!(await haveCc())) return;
  const run = await buildAndRun("debug", []);
  expect(run.stdout.trimEnd().split("\n")).toEqual(vmStdout());
  expect(run.stderr).toContain("i32.add overflow");
  expect(run.exit).not.toBe(0);
}, LONG_BUILD);

test("a release build wraps an integer overflow", async () => {
  if (!(await haveCc())) return;
  const run = await buildAndRun("release", ["--release"]);
  expect(run.stdout.trimEnd().split("\n")).toEqual([...vmStdout(), "i32 past its maximum: -2147483648"]);
  expect(run.exit).toBe(0);
}, LONG_BUILD);
