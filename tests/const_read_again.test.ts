// The message that names the constant or the singleton, on the VM and from a
// native build: the snippet harness runs the `.virt`, which drops the reason of
// an `unreachable`.
import { expect, test } from "bun:test";
import { tmpdir } from "node:os";
import { basename, dirname, join } from "node:path";
import { type CliResult, EXE_SUFFIX, LONG_BUILD, MEDIUM_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const MAIN = "tests/snippets/const_read_again_by_its_function/_main.vader";
// A program whose threads may share a constant guards it with a gate instead.
const GATED_MAIN = "tests/snippets/singleton_and_constant_across_tasks/_main.vader";
// A singleton its own body calls again stops the same way.
const SELFISH_MAIN = "tests/snippets/singleton_calls_itself_in_a_task/_main.vader";

const LOOP_STOP = "constant `LOOP` read while its value is computed";
const SELFISH_STOP = "singleton `selfish` called while it initialises";

// What a run shows: the line printed before the read, then the stop.
function outcome(run: CliResult, message: string) {
  return {
    stdout: run.stdout,
    said: run.stderr.includes(message),
    stopped: run.exit !== 0,
  };
}

// Build `main` natively, then run the binary with `args`.
async function runNative(main: string, args: string[]): Promise<CliResult> {
  const out = join(tmpdir(), `vader-${basename(dirname(main))}-${process.pid}${EXE_SUFFIX}`);
  const built = await runCli(["build", `--out=${out}`, main], undefined, LONG_BUILD);
  expect(built.exit).toBe(0);
  return spawnCapture(args, { bin: out, timeoutMs: 10_000 });
}

const STOPPED = { stdout: "42 42 126\n", said: true, stopped: true };

test("a constant read again by its function stops the VM", async () => {
  expect(outcome(await runCli(["run", MAIN, "cycle"], undefined, MEDIUM_BUILD), LOOP_STOP)).toEqual(STOPPED);
}, MEDIUM_BUILD);

test("a constant read again by its function stops a native build", async () => {
  if (!(await haveCc())) return;
  expect(outcome(await runNative(MAIN, ["cycle"]), LOOP_STOP)).toEqual(STOPPED);
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
  expect(outcome(run, LOOP_STOP)).toEqual(GATED_STOPPED);
}, MEDIUM_BUILD);

test("a gated constant read again by its function stops a native build", async () => {
  if (!(await haveCc())) return;
  expect(outcome(await runNative(GATED_MAIN, ["again"]), LOOP_STOP)).toEqual(GATED_STOPPED);
}, LONG_BUILD);

const SELFISH_STOPPED = { stdout: "selfish starts\n", said: true, stopped: true };

test("a singleton called again by its own body stops the VM", async () => {
  const run = await runCli(["run", SELFISH_MAIN], undefined, MEDIUM_BUILD);
  expect(outcome(run, SELFISH_STOP)).toEqual(SELFISH_STOPPED);
}, MEDIUM_BUILD);

test("a singleton called again by its own body stops a native build", async () => {
  if (!(await haveCc())) return;
  expect(outcome(await runNative(SELFISH_MAIN, []), SELFISH_STOP)).toEqual(SELFISH_STOPPED);
}, LONG_BUILD);
