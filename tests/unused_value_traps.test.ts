// A run-time check runs even when nothing reads the value it guards. The
// `unused_value_still_traps` snippet pins its first case on the VM; this file
// runs every case on the VM and from a debug build, where each stops the
// program, and from a release build, where an overflow wraps and the other
// checks still stop it.
import { expect, test } from "bun:test";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { type CliResult, EXE_SUFFIX, LONG_BUILD, MEDIUM_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const MAIN = "tests/snippets/unused_value_still_traps/_main.vader";

// Each case the program takes on its command line, and what both backends say
// when it stops.
const CASES: Record<string, string> = {
  index: "out of bounds",
  divide: "i32.div by zero",
  remainder: "i32.mod by zero",
  add: "i32.add overflow",
  negate: "i32.neg overflow",
  loop: "out of bounds",
};

const NONE = new Set<string>();

// What a run shows of a case, labelled with it so a failure names it.
function outcome(name: string, run: CliResult) {
  return { name, stdout: run.stdout, said: run.stderr.includes(CASES[name]!), stopped: run.exit !== 0 };
}

// A case in `wraps` runs to its end; any other stops after its first line.
function expected(name: string, wraps: Set<string>) {
  if (wraps.has(name)) return { name, stdout: "before\nafter\n", said: false, stopped: false };
  return { name, stdout: "before\n", said: true, stopped: true };
}

async function expectEveryCase(run: (name: string) => Promise<CliResult>, wraps: Set<string>) {
  for (const name of Object.keys(CASES)) {
    expect(outcome(name, await run(name))).toEqual(expected(name, wraps));
  }
}

// Build the program with `flags` into a file named after `stem`, in the temp directory.
async function build(stem: string, flags: string[]): Promise<string> {
  const out = join(tmpdir(), `vader-unused-value-${process.pid}-${stem}`);
  const r = await runCli(["build", ...flags, `--out=${out}`, MAIN], undefined, LONG_BUILD);
  expect(r.exit).toBe(0);
  return out;
}

const runBinary = (bin: string) => (name: string) => spawnCapture([name], { bin, timeoutMs: 10_000 });

test("every unread check stops the program on the VM", async () => {
  const virt = await build("vm.virt", ["--emit=bytecode-text"]);
  await expectEveryCase((name) => runCli(["run", virt, name]), NONE);
}, MEDIUM_BUILD);

test("every unread check stops a debug build", async () => {
  if (!(await haveCc())) return;
  await expectEveryCase(runBinary(await build(`debug${EXE_SUFFIX}`, [])), NONE);
}, LONG_BUILD);

test("a release build wraps an unread overflow, and stops on the other checks", async () => {
  if (!(await haveCc())) return;
  await expectEveryCase(runBinary(await build(`release${EXE_SUFFIX}`, ["--release"])), new Set(["add", "negate"]));
}, LONG_BUILD);
