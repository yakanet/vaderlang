// Virtual threads (`runtime/c/rt/vthreads.c`, `runtime/c/rt/sched.c`,
// `std/runtime/scheduler`) on the native backend and the VM. A parked thread's
// shadow-stack frames, stack objects, atoms and pending defers stay rooted under
// every diagnostic mode of the collector, in a debug and a release build; a
// thread that runs past its stack stops; each thread unwinds its own defers; a
// switch inside a call to C stops the program. The ready threads run in turn,
// the shortest sleep ends first and of two that end together the older, a
// cancelled thread runs its defers, a deadlock stops the program, and `main`
// returning while threads run cancels them and names them in the order they
// started.
//
// The fixture (tests/fixtures/virtual_threads/main.vader) is built once per
// profile, and each case is a run of it with `THREADS_CASE` set; on the VM, each
// case is a `vader run` of it.
import { beforeAll, describe, expect, test } from "bun:test";
import { mkdtempSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { LONG_BUILD, exePath, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const FIXTURE = "tests/fixtures/virtual_threads/main.vader";
const TESTS_FIXTURE = "tests/fixtures/test_cmd/threads/threads.vader";

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

// The fields of a run the cases read.
interface Outcome {
  stdout: string;
  stderr: string;
  exit: number;
}

// Run the fixture under `env`, or report that this backend cannot run here.
type Runner = (env: Record<string, string>) => Promise<Outcome | null>;

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
  [
    "main returning waits for a thread it cancelled, and names nothing",
    "exit_after_cancel",
    "main returns\ndefer of the cancelled thread\n",
  ],
];

// The cases every backend runs, the collector under each of `gcModes`; a run of
// `switch_in_callback` only where a Vader function can be handed to C.
function threadCases(run: Runner, gcModes: string[], callsIntoC: boolean) {
  const runCase = (threadsCase: string, gcMode = "") => run(caseEnv(threadsCase, gcMode));

  for (const gcMode of gcModes) {
    test(`parked threads stay rooted${underMode(gcMode)}`, async () => {
      const r = await runCase("parked_roots", gcMode);
      if (r === null) return;
      expect(r.stderr).toBe("");
      expect(r.stdout).toBe(PARKED_ROOTS);
      expect(r.exit).toBe(0);
    }, LONG_BUILD);
  }

  test("a thread past the end of its stack stops", async () => {
    const r = await runCase("overflow");
    if (r === null) return;
    expect(r.stdout).toBe("depth 1000: 3893\n");
    expect(r.exit).not.toBe(0);
  }, LONG_BUILD);

  test("each thread runs its own defers when it panics", async () => {
    const r = await runCase("two_panics");
    if (r === null) return;
    expect(r.stdout).toBe("defer of first, before the yield\ndefer of second\n");
    expect(r.stderr).toContain("panic: second");
    expect(r.exit).not.toBe(0);
  }, LONG_BUILD);

  if (callsIntoC) {
    test("a switch inside a call to C stops the program", async () => {
      const r = await runCase("switch_in_callback");
      if (r === null) return;
      expect(r.stdout).toBe("back from qsort\n");
      expect(r.stderr).toContain("a switch inside a call to C");
      expect(r.exit).not.toBe(0);
    }, LONG_BUILD);
  }

  for (const [name, threadsCase, stdout] of CLEAN_CASES) {
    test(name, async () => {
      const r = await runCase(threadsCase);
      if (r === null) return;
      expect(r).toMatchObject({ stdout, stderr: "", exit: 0 });
    }, LONG_BUILD);
  }

  test("under the virtual clock, the shortest sleep ends first", async () => {
    const r = await run({ ...caseEnv("sleep_order", ""), VADER_VIRTUAL_CLOCK: "1" });
    if (r === null) return;
    expect(r).toMatchObject({ stdout: "slept 10 ms\nslept 20 ms\nslept 30 ms\n", stderr: "", exit: 0 });
  }, LONG_BUILD);

  test("under the virtual clock, sleeps that end together end in the order they began", async () => {
    const r = await run({ ...caseEnv("sleep_ties", ""), VADER_VIRTUAL_CLOCK: "1" });
    if (r === null) return;
    expect(r).toMatchObject({ stdout: "a woke\nb woke\nc woke\n", stderr: "", exit: 0 });
  }, LONG_BUILD);

  test("the main thread cannot be cancelled", async () => {
    const r = await runCase("cancel_main");
    if (r === null) return;
    expect(r.stdout).toBe("");
    expect(r.stderr).toContain("the main thread cannot be cancelled");
    expect(r.exit).not.toBe(0);
  }, LONG_BUILD);

  test("a deadlock stops the program and names the threads", async () => {
    const r = await runCase("deadlock");
    if (r === null) return;
    expect(r.stdout).toBe("");
    expect(r.stderr).toContain("a deadlock, every task waits and nothing will wake one: main, task #1\n");
    expect(r.exit).not.toBe(0);
  }, LONG_BUILD);

  test("main returning cancels the threads still running", async () => {
    const r = await runCase("exit_with_live_thread");
    if (r === null) return;
    expect(r).toMatchObject({
      stdout: "main returns\ndefer of the forgotten thread\n",
      stderr: "vader: task #1 still runs when main returns: cancelled\n",
      exit: 1,
    });
  }, LONG_BUILD);

  test("main returning names the threads still running in the order they started", async () => {
    const r = await runCase("exit_names_in_order");
    if (r === null) return;
    expect(r).toMatchObject({
      stdout: "the first thread ends\nmain returns\n",
      stderr: [
        "vader: task #2 still runs when main returns: cancelled",
        "vader: task #3 still runs when main returns: cancelled",
        "",
      ].join("\n"),
      exit: 1,
    });
  }, LONG_BUILD);
}

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

    const run: Runner = async (env) => {
      if (bin === "") return null;
      return spawnCapture([], { bin, env });
    };
    threadCases(run, GC_MODES, true);
  });
}

// The stress modes collect inside the compile that precedes each run too, which
// takes minutes under `vader run`.
const VM_GC_MODES = ["", "VADER_GC_STRESS_SWITCH", "VADER_GC_CHECK_BOX", "VADER_GC_NO_CSTACK_SCAN"];

// The VM runs a guest thread on a thread of the host (`vader/vm/guest_threads.vader`).
// It hands no Vader function to C, so `switch_in_callback` is native only.
describe("virtual threads, VM", () => {
  threadCases((env) => runCli(["run", FIXTURE], env, LONG_BUILD), VM_GC_MODES, false);

  test("a test that leaves a thread fails, and the thread ends before the next test; one it cancelled passes", async () => {
    const r = await runCli(["test", TESTS_FIXTURE], undefined, LONG_BUILD);
    expect(r.stdout).toContain("FAIL test_leaves_a_thread");
    expect(r.stdout).toContain("task #1 still running when the test returns: cancelled");
    expect(r.stdout).toContain("ok test_after_the_left_thread");
    expect(r.stdout).toContain("ok test_cancels_its_thread");
    expect(r.exit).toBe(1);
  }, LONG_BUILD);
});
