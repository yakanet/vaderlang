// Virtual threads (`runtime/c/rt/vthreads.c`, `runtime/c/rt/sched.c`,
// `std/runtime/scheduler`) on the native backend. A parked thread's
// shadow-stack frames, stack objects, atoms and pending defers stay rooted under
// every diagnostic mode of the collector, in a debug and a release build; a
// thread that runs past its stack stops; each thread unwinds its own defers; a
// switch inside a call to C stops the program. The ready threads run in turn,
// the shortest sleep ends first, a cancelled thread runs its defers, a deadlock
// stops the program, and so does `main` returning while a thread runs.
//
// The fixture (tests/fixtures/virtual_threads/main.vader) is built once per
// profile, and each case is a run of it with `THREADS_CASE` set.
import { beforeAll, describe, expect, test } from "bun:test";
import { mkdtempSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { LONG_BUILD, exePath, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const FIXTURE = "tests/fixtures/virtual_threads/main.vader";

const PARKED_ROOTS = [
  "thread-0 ok",
  "defer of thread-0",
  "thread-1 ok",
  "defer of thread-1",
  "thread-2 ok",
  "defer of thread-2",
  "garbage 2000800000",
  "",
].join("\n");

// Each runs with `VADER_GC_POISON`, so a semi-space a parked frame still points
// into reads as garbage instead of as its old contents.
const GC_MODES = [
  "",
  "VADER_GC_STRESS",
  "VADER_GC_STRESS_MAJOR",
  "VADER_GC_STRESS_SWITCH",
  "VADER_GC_CHECK_BOX",
  "VADER_GC_NO_CSTACK_SCAN",
];

// The words a test name adds for `gcMode`.
function underMode(gcMode: string): string {
  if (gcMode === "") return "";
  return ` under ${gcMode}`;
}

function profileFlags(profile: string): string[] {
  if (profile === "release") return ["--release"];
  return [];
}

function caseEnv(threadsCase: string, gcMode: string): Record<string, string> {
  const env: Record<string, string> = { THREADS_CASE: threadsCase, VADER_GC_POISON: "1" };
  if (gcMode !== "") env[gcMode] = "1";
  return env;
}

async function runCase(bin: string, threadsCase: string, gcMode = "") {
  return spawnCapture([], { bin, env: caseEnv(threadsCase, gcMode) });
}

// The cases that end well, and what each prints.
const CLEAN_CASES: [string, string, string][] = [
  ["the ready threads run in turn", "take_turns", "a0\nb0\nc0\na1\nb1\nc1\njoined\n"],
  ["a wake does not end a sleep", "real_sleep", "slept at least 20 ms\n"],
  ["a cancelled thread runs its defers", "cancel_parked", "defer of the parked thread\njoined\n"],
  ["a thread cancelled before it ran runs nothing", "cancel_unstarted", "cancelled before it ran\n"],
  ["a thread that cancels itself does not come back", "cancel_self", "defer of the thread\njoined\n"],
  [
    "the defer of a cancelled thread may park",
    "cancel_defer_parks",
    "defer starts\nmain between\ndefer ends\njoined\n",
  ],
  ["the stacks freed during a sleep are taken again", "bursts", "three bursts of 200 threads\n"],
];

for (const profile of ["debug", "release"]) {
  describe(`virtual threads, ${profile} build`, () => {
    let bin = "";

    beforeAll(async () => {
      if (!(await haveCc())) return;
      bin = join(mkdtempSync(join(tmpdir(), "vader-vthreads-")), exePath("threads"));
      const build = await runCli(["build", ...profileFlags(profile), `--out=${bin}`, FIXTURE], undefined, LONG_BUILD);
      // The whole result, so that a failed build shows its diagnostics.
      expect(build).toMatchObject({ exit: 0 });
    }, LONG_BUILD);

    for (const gcMode of GC_MODES) {
      test(`parked threads stay rooted${underMode(gcMode)}`, async () => {
        if (bin === "") return;
        const r = await runCase(bin, "parked_roots", gcMode);
        expect(r.stderr).toBe("");
        expect(r.stdout).toBe(PARKED_ROOTS);
        expect(r.exit).toBe(0);
      }, LONG_BUILD);
    }

    test("a thread past the end of its stack stops on the guard zone", async () => {
      if (bin === "") return;
      const r = await runCase(bin, "overflow");
      expect(r.stdout).toBe("depth 1000: 3893\n");
      expect(r.exit).not.toBe(0);
    }, LONG_BUILD);

    test("each thread runs its own defers when it panics", async () => {
      if (bin === "") return;
      const r = await runCase(bin, "two_panics");
      expect(r.stdout).toBe("defer of first, before the yield\ndefer of second\n");
      expect(r.stderr).toContain("panic: second");
      expect(r.exit).not.toBe(0);
    }, LONG_BUILD);

    test("a switch inside a call to C stops the program", async () => {
      if (bin === "") return;
      const r = await runCase(bin, "switch_in_callback");
      expect(r.stdout).toBe("back from qsort\n");
      expect(r.stderr).toContain("a switch inside a call to C");
      expect(r.exit).not.toBe(0);
    }, LONG_BUILD);

    for (const [name, threadsCase, stdout] of CLEAN_CASES) {
      test(name, async () => {
        if (bin === "") return;
        const r = await runCase(bin, threadsCase);
        expect(r).toMatchObject({ stdout, stderr: "", exit: 0 });
      }, LONG_BUILD);
    }

    test("under the virtual clock, the shortest sleep ends first", async () => {
      if (bin === "") return;
      const env = { ...caseEnv("sleep_order", ""), VADER_ASYNC_VIRTUAL_CLOCK: "1" };
      const r = await spawnCapture([], { bin, env });
      expect(r).toMatchObject({ stdout: "slept 10 ms\nslept 20 ms\nslept 30 ms\n", stderr: "", exit: 0 });
    }, LONG_BUILD);

    test("the main thread cannot be cancelled", async () => {
      if (bin === "") return;
      const r = await runCase(bin, "cancel_main");
      expect(r.stdout).toBe("");
      expect(r.stderr).toContain("the main thread cannot be cancelled");
      expect(r.exit).not.toBe(0);
    }, LONG_BUILD);

    test("a deadlock stops the program and names the threads", async () => {
      if (bin === "") return;
      const r = await runCase(bin, "deadlock");
      expect(r.stdout).toBe("");
      expect(r.stderr).toContain("a deadlock, every thread waits and nothing will wake one: main, thread #1\n");
      expect(r.exit).not.toBe(0);
    }, LONG_BUILD);

    test("main returning cancels the threads still running", async () => {
      if (bin === "") return;
      const r = await runCase(bin, "exit_with_live_thread");
      expect(r).toMatchObject({
        stdout: "main returns\ndefer of the forgotten thread\n",
        stderr: "vader: thread #1 still runs when main returns: cancelled\n",
        exit: 1,
      });
    }, LONG_BUILD);
  });
}

// The VM serves no virtual thread yet: a program that starts one stops.
test("the VM refuses to run a virtual thread", async () => {
  const r = await runCli(["run", FIXTURE], caseEnv("take_turns", ""), LONG_BUILD);
  expect(r.stdout).toBe("");
  expect(r.stderr).toContain("the VM runs no virtual thread yet");
  expect(r.exit).not.toBe(0);
}, LONG_BUILD);
