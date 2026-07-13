// Panic-unwind — a `panic()` runs the pending `defer`s of every frame it
// unwinds through (LIFO, innermost frame first) before the process aborts, on
// BOTH backends. The `panic_runs_defers` snippet's cleanup lines must appear on
// stdout even though the program aborts.
//
// The VM side is also pinned by that snippet's `vm.snapshot` (vader_vm.test.ts);
// this file adds the NATIVE assertion — the C-emit parity suite skips the
// output check for programs that exit non-zero — and re-checks the VM stdout
// explicitly so both backends are asserted side by side.
import { expect, test } from "bun:test";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { LONG_BUILD, runCli } from "./cli-bin.ts";

const SNIPPET = "tests/snippets/panic_runs_defers/_main.vader";
// Innermost frame's defer first (refund), then the caller's (release hold).
const EXPECTED_STDOUT = "reserve inventory\ncharging 500\nrefund 500\nrelease hold\n";

async function haveCc(): Promise<boolean> {
  const proc = Bun.spawn(["cc", "--version"], { stdout: "ignore", stderr: "ignore" });
  return (await proc.exited) === 0;
}

test("panic runs pending defers on the VM before aborting", async () => {
  const { stdout, exit } = await runCli(["run", SNIPPET]);
  expect(stdout).toBe(EXPECTED_STDOUT);
  expect(exit).not.toBe(0);
});

test("panic runs pending defers on native before aborting", async () => {
  if (!(await haveCc())) return; // native path needs a C toolchain
  const bin = join(tmpdir(), `vader-panic-unwind-${process.pid}`);
  const build = await runCli(["build", SNIPPET, `--out=${bin}`], undefined, LONG_BUILD);
  expect(build.exit).toBe(0);

  const proc = Bun.spawn([bin], { stdout: "pipe", stderr: "pipe" });
  const stdout = await new Response(proc.stdout).text();
  const exit = await proc.exited;
  expect(stdout).toBe(EXPECTED_STDOUT);
  expect(exit).not.toBe(0); // SIGABRT (134) — the panic still aborts
}, LONG_BUILD); // native path shells out to `cc` — slow CI runners blow the 5s default
