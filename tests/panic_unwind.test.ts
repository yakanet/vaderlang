// Panic-unwind: a `panic()` runs the pending `defer`s of every frame it
// unwinds through (LIFO, innermost frame first) before the process aborts, on
// BOTH backends. The `panic_runs_defers` snippet's cleanup lines must appear on
// stdout even though the program aborts. A failed run-time check
// (tests/fixtures/unwind/out_of_range.vader) runs them too.
//
// The VM side is also pinned by that snippet's `vm.snapshot` (the `vm` stage of
// the test runner);
// this file adds the NATIVE assertion, which the C-emit parity suite cannot
// make: it compares stderr and the exit code verbatim, and a VM trap and a
// native abort differ in both. It also re-checks the VM stdout explicitly so
// both backends are asserted side by side.
import { expect, test } from "bun:test";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { LONG_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const SNIPPET = "tests/snippets/panic_runs_defers/_main.vader";
// Innermost frame's defer first (refund), then the caller's (release hold).
const EXPECTED_STDOUT = "reserve inventory\ncharging 500\nrefund 500\nrelease hold\n";
const OUT_OF_RANGE = "tests/fixtures/unwind/out_of_range.vader";
const OUT_OF_RANGE_STDOUT = "7\ndefer of main\n";

test("panic runs pending defers on the VM before aborting", async () => {
  const { stdout, exit } = await runCli(["run", SNIPPET]);
  expect(stdout).toBe(EXPECTED_STDOUT);
  expect(exit).not.toBe(0);
});

test("panic runs pending defers on native before aborting", async () => {
  if (!(await haveCc())) return; // native path needs a C toolchain
  const bin = join(tmpdir(), `vader-panic-unwind-${process.pid}`);
  const build = await runCli(["build", `--out=${bin}`, SNIPPET], undefined, LONG_BUILD);
  expect(build.exit).toBe(0);

  const proc = Bun.spawn([bin], { stdout: "pipe", stderr: "pipe" });
  const stdout = await new Response(proc.stdout).text();
  const exit = await proc.exited;
  expect(stdout).toBe(EXPECTED_STDOUT);
  expect(exit).not.toBe(0); // SIGABRT (134): the panic still aborts
}, LONG_BUILD); // native path shells out to `cc`: slow CI runners blow the 5s default

test("a failed run-time check runs pending defers on the VM", async () => {
  const { stdout, exit } = await runCli(["run", OUT_OF_RANGE]);
  expect(stdout).toBe(OUT_OF_RANGE_STDOUT);
  expect(exit).not.toBe(0);
});

test("a failed run-time check runs pending defers on native", async () => {
  if (!(await haveCc())) return;
  const bin = join(tmpdir(), `vader-out-of-range-${process.pid}`);
  const build = await runCli(["build", `--out=${bin}`, OUT_OF_RANGE], undefined, LONG_BUILD);
  expect(build.exit).toBe(0);

  const r = await spawnCapture([], { bin });
  expect(r.stdout).toBe(OUT_OF_RANGE_STDOUT);
  expect(r.stderr).toContain("value out of range");
  expect(r.exit).not.toBe(0);
}, LONG_BUILD);
