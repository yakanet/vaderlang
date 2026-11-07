// The message that names the constant, on the VM and from a native build: the
// snippet harness runs the `.virt`, which drops the reason of an `unreachable`.
import { expect, test } from "bun:test";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { type CliResult, EXE_SUFFIX, LONG_BUILD, MEDIUM_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const MAIN = "tests/snippets/const_read_again_by_its_function/_main.vader";
// A program whose threads may share a constant guards it with a gate instead.
const GATED_MAIN = "tests/snippets/singleton_and_constant_across_tasks/_main.vader";

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

const GATED_STDOUT = [
  "config starts",
  "config done",
  "cfg cfg cfg",
  "pool starts",
  "pool starts",
  "pool done",
  "cancelled pool",
  "answer computed",
  "answer computed",
  "42 42",
  "warming",
  "7 7",
  "",
].join("\n");

const GATED_STOPPED = { stdout: GATED_STDOUT, said: true, stopped: true };

test("a gated constant read again by its function stops the VM", async () => {
  const run = await runCli(["run", GATED_MAIN, "again"], undefined, MEDIUM_BUILD);
  expect(outcome(run)).toEqual(GATED_STOPPED);
}, MEDIUM_BUILD);

test("a gated constant read again by its function stops a native build", async () => {
  if (!(await haveCc())) return;
  const out = join(tmpdir(), `vader-gated-read-again-${process.pid}${EXE_SUFFIX}`);
  const built = await runCli(["build", `--out=${out}`, GATED_MAIN], undefined, LONG_BUILD);
  expect(built.exit).toBe(0);
  const run = await spawnCapture(["again"], { bin: out, timeoutMs: 10_000 });
  expect(outcome(run)).toEqual(GATED_STOPPED);
}, LONG_BUILD);
