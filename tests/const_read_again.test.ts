// The message that names the constant, on the VM and from a native build: the
// snippet harness runs the `.virt`, which drops the reason of an `unreachable`.
import { expect, test } from "bun:test";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { type CliResult, EXE_SUFFIX, LONG_BUILD, MEDIUM_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const MAIN = "tests/snippets/const_read_again_by_its_function/_main.vader";

// What a run shows: the line printed before the read, then the stop.
function outcome(run: CliResult) {
  return {
    stdout: run.stdout,
    said: run.stderr.includes("constant `LOOP` read while its value is computed"),
    stopped: run.exit !== 0,
  };
}

const STOPPED = { stdout: "42 42 126\n", said: true, stopped: true };

test("a constant read again by its function stops the VM", async () => {
  expect(outcome(await runCli(["run", MAIN, "cycle"], undefined, MEDIUM_BUILD))).toEqual(STOPPED);
}, MEDIUM_BUILD);

test("a constant read again by its function stops a native build", async () => {
  if (!(await haveCc())) return;
  const out = join(tmpdir(), `vader-const-read-again-${process.pid}${EXE_SUFFIX}`);
  const built = await runCli(["build", `--out=${out}`, MAIN], undefined, LONG_BUILD);
  expect(built.exit).toBe(0);
  expect(outcome(await spawnCapture(["cycle"], { bin: out, timeoutMs: 10_000 }))).toEqual(STOPPED);
}, LONG_BUILD);
