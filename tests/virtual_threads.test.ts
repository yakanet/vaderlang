// Virtual threads (`runtime/c/rt/vthreads.c`, `std/runtime/threads`) on the
// native backend and under the VM. A parked thread's shadow-stack frames, stack
// objects, atoms and pending defers stay rooted under every diagnostic mode of
// the collector, in a debug and a release build; a thread that runs past its
// stack stops; each thread unwinds its own defers; a switch inside a call to C
// stops the program.
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
  });
}

// Under `vader run`, a thread of the program is a thread of the host
// (`vader/vm/guest_threads.vader`), and the collector's modes act on the host.
// `VADER_GC_STRESS` and `VADER_GC_STRESS_MAJOR` are left out: they act on the
// compile that precedes the run as well.
const VM_GC_MODES = ["", "VADER_GC_STRESS_SWITCH", "VADER_GC_CHECK_BOX", "VADER_GC_NO_CSTACK_SCAN"];

async function runOnVm(threadsCase: string, gcMode = "") {
  return runCli(["run", FIXTURE], caseEnv(threadsCase, gcMode), LONG_BUILD);
}

describe("virtual threads under the VM", () => {
  for (const gcMode of VM_GC_MODES) {
    test(`parked threads stay rooted${underMode(gcMode)}`, async () => {
      const r = await runOnVm("parked_roots", gcMode);
      expect(r.stderr).toBe("");
      expect(r.stdout).toBe(PARKED_ROOTS);
      expect(r.exit).toBe(0);
    }, LONG_BUILD);
  }

  test("a thread past the VM's call depth stops", async () => {
    const r = await runOnVm("overflow");
    expect(r.stdout).toBe("depth 1000: 3893\n");
    expect(r.stderr).toContain("call stack overflow");
    expect(r.exit).not.toBe(0);
  }, LONG_BUILD);

  test("each thread runs its own defers when it panics", async () => {
    const r = await runOnVm("two_panics");
    expect(r.stdout).toBe("defer of first, before the yield\ndefer of second\n");
    expect(r.stderr).toContain("panic: second");
    expect(r.exit).not.toBe(0);
  }, LONG_BUILD);
});
