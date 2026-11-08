// DAP end-to-end test : spawn the native `vader dap`, drive the Debug Adapter
// Protocol handshake over stdin/stdout, verify the Phase-1 proof-of-life flow:
// initialize → launch → configurationDone runs the program, its output surfaces
// as `output` events (NOT on the raw stdout channel, which would corrupt the
// protocol), and the session ends with `exited` + `terminated`.
//
// The adapter is the compiled native binary (`build/vader dap`) driving the
// bytecode VM. The DAP message order is deterministic (the server processes
// frames sequentially and each command's effect doesn't depend on the previous
// response's contents), so every request is batch-written up front: the server
// reads them in order off the pipe, exactly like the LSP e2e test.

import { test, expect } from "bun:test";
import { join } from "node:path";
import { mkdtempSync, writeFileSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";

import { MEDIUM_BUILD, ensureCliBuilt } from "./cli-bin.ts";
import { exchangeFrames } from "./rpc-frames.ts";

ensureCliBuilt();

type Json = { seq: number; type: string; command?: string; event?: string; body?: any; success?: boolean };

// Every frame a fresh `vader dap` emits for `requests`. The server reads frames
// in order, the paused-state loop included, so a pre-built request list drives
// the whole session.
async function sendDap(requests: object[]): Promise<Json[]> {
  return exchangeFrames(["dap"], requests, MEDIUM_BUILD);
}

// The proof-of-life flow : run to completion, no breakpoints.
async function driveDap(program: string): Promise<Json[]> {
  return sendDap([
    { seq: 1, type: "request", command: "initialize", arguments: { adapterID: "vader" } },
    { seq: 2, type: "request", command: "launch", arguments: { program } },
    // VSCode sends setBreakpoints between `initialized` and configurationDone,
    // and gates configurationDone (the run trigger) on a well-formed response:
    // it MUST echo one breakpoint object per requested line. Line 1 is a
    // comment (no op), so this exercises the response shape without stopping the
    // run-to-completion flow: the dedicated test below covers an actual stop.
    { seq: 3, type: "request", command: "setBreakpoints",
      arguments: { source: { path: program }, breakpoints: [{ line: 1 }], lines: [1] } },
    { seq: 4, type: "request", command: "configurationDone" },
    { seq: 5, type: "request", command: "threads" },
    { seq: 6, type: "request", command: "disconnect" },
  ]);
}

// The frames of a session on `source`, written to a fresh directory, stopping at
// `lines` and sending `during` once it runs.
async function debugSource(source: string, lines: number[], during: object[]): Promise<Json[]> {
  const dir = mkdtempSync(join(tmpdir(), "vdap-"));
  const program = join(dir, "_main.vader");
  writeFileSync(program, source);
  try {
    return await sendDap([
      { seq: 1, type: "request", command: "initialize", arguments: { adapterID: "vader" } },
      { seq: 2, type: "request", command: "launch", arguments: { program } },
      { seq: 3, type: "request", command: "setBreakpoints",
        arguments: { source: { path: program }, breakpoints: lines.map((line) => ({ line })) } },
      { seq: 4, type: "request", command: "configurationDone" },
      ...during.map((request, i) => ({ seq: 5 + i, type: "request", ...request })),
      { seq: 99, type: "request", command: "disconnect" },
    ]);
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}

test("dap: proof of life, initialize, launch, run, capture output, terminate", async () => {
  // io_println prints "hello\n" then "42\n": imports std/console, resolved relative
  // to the repo cwd (same as `vader run`).
  const program = join(process.cwd(), "tests/snippets/io_println/_main.vader");
  const frames = await driveDap(program);

  const responses = frames.filter((f) => f.type === "response");
  const events = frames.filter((f) => f.type === "event");
  const respFor = (cmd: string) => responses.find((r) => r.command === cmd);
  const eventNames = events.map((e) => e.event);

  // initialize response advertises the configurationDone capability (our run
  // trigger), and every request gets a successful response.
  const init = respFor("initialize");
  expect(init?.success).toBe(true);
  expect(init?.body?.supportsConfigurationDoneRequest).toBe(true);
  expect(respFor("launch")?.success).toBe(true);
  expect(respFor("configurationDone")?.success).toBe(true);
  expect(respFor("disconnect")?.success).toBe(true);

  // setBreakpoints MUST return a `breakpoints` array (one per requested line):
  // VSCode stalls (never sends configurationDone, so the program never runs) on
  // a malformed response.
  const bpResp = respFor("setBreakpoints");
  expect(bpResp?.success).toBe(true);
  expect(Array.isArray(bpResp?.body?.breakpoints)).toBe(true);
  expect(bpResp?.body?.breakpoints.length).toBe(1);
  expect(bpResp?.body?.breakpoints[0].verified).toBe(true);

  // The handshake fires an `initialized` event, and the run ends with
  // `exited` + `terminated`.
  expect(eventNames).toContain("initialized");
  expect(eventNames).toContain("exited");
  expect(eventNames).toContain("terminated");

  // Program output rides on `output` events (category stdout), NOT the raw
  // stdout channel, which is reserved for the DAP protocol.
  const stdout = events
    .filter((e) => e.event === "output" && e.body?.category === "stdout")
    .map((e) => e.body.output)
    .join("");
  expect(stdout).toContain("hello");
  expect(stdout).toContain("42");

  // Clean exit code (io_println returns 0).
  const exited = events.find((e) => e.event === "exited");
  expect(exited?.body?.exitCode).toBe(0);
}, { timeout: MEDIUM_BUILD });

test("dap: breakpoint stops the program and continue resumes it", async () => {
  // io_println: line 13 `main :: fn() -> i32 {`, line 14 `println("hello")`.
  // Breakpoint on line 14 (the first body statement: a signature line carries
  // no op) must fire `stopped`, `stackTrace` must place the top frame at line 14,
  // and `continue` must run it to completion. The pause loop reads the queued
  // stackTrace/continue frames off the same pipe, so one batched request list
  // drives the whole flow.
  const program = join(process.cwd(), "tests/snippets/io_println/_main.vader");
  const requests = [
    { seq: 1, type: "request", command: "initialize", arguments: { adapterID: "vader" } },
    { seq: 2, type: "request", command: "launch", arguments: { program } },
    { seq: 3, type: "request", command: "setBreakpoints",
      arguments: { source: { path: program }, breakpoints: [{ line: 14 }] } },
    { seq: 4, type: "request", command: "configurationDone" },
    // Consumed by the pause loop once the breakpoint fires.
    { seq: 5, type: "request", command: "stackTrace", arguments: { threadId: 1 } },
    { seq: 6, type: "request", command: "continue", arguments: { threadId: 1 } },
    { seq: 7, type: "request", command: "disconnect" },
  ];
  const frames = await sendDap(requests);

  // The breakpoint fired.
  const stopped = frames.find((f) => f.event === "stopped");
  expect(stopped).toBeDefined();
  expect(stopped?.body?.reason).toBe("breakpoint");

  // stackTrace placed the top frame at line 14, in `main`.
  const st = frames.find((f) => f.type === "response" && f.command === "stackTrace");
  expect(st?.success).toBe(true);
  const top = st?.body?.stackFrames?.[0];
  expect(top?.line).toBe(14);
  expect(top?.name).toBe("main");

  // continue ran it to completion: output surfaced + terminated.
  expect(frames.some((f) => f.event === "terminated")).toBe(true);
  const stdout = frames
    .filter((f) => f.event === "output" && f.body?.category === "stdout")
    .map((f) => f.body.output).join("");
  expect(stdout).toContain("hello");
}, { timeout: MEDIUM_BUILD });

test("dap: step over advances the line, and Variables shows source locals with values", async () => {
  // array_slice: line 13 `arr: i32[] = [10, 20, 30, 40, 50]` (breakpoint),
  // line 16 the next statement. Stopping BEFORE line 13 runs, `arr` is 0 ;
  // after a step over it holds the array. The Variables view must show source
  // locals (arr, s1, …), NOT the compiler's `$…` / `__…` temporaries.
  const program = join(process.cwd(), "tests/snippets/array_slice/_main.vader");
  const requests = [
    { seq: 1, type: "request", command: "initialize", arguments: { adapterID: "vader" } },
    { seq: 2, type: "request", command: "launch", arguments: { program } },
    { seq: 3, type: "request", command: "setBreakpoints",
      arguments: { source: { path: program }, breakpoints: [{ line: 13 }] } },
    { seq: 4, type: "request", command: "configurationDone" },
    // Stop #1 (breakpoint, line 13): inspect, then step over.
    { seq: 5, type: "request", command: "stackTrace", arguments: { threadId: 1 } },
    { seq: 6, type: "request", command: "scopes", arguments: { frameId: 1 } },
    { seq: 7, type: "request", command: "variables", arguments: { variablesReference: 1 } },
    { seq: 8, type: "request", command: "next", arguments: { threadId: 1 } },
    // Stop #2 (step, past line 13): `arr` is now materialised.
    { seq: 9, type: "request", command: "stackTrace", arguments: { threadId: 1 } },
    { seq: 10, type: "request", command: "variables", arguments: { variablesReference: 1 } },
    // Expand `arr` (an array → expandable). With one frame, the scope ref is 1
    // and `arr` (the first expandable local) is minted ref 2: deterministic for
    // this fixed program.
    { seq: 11, type: "request", command: "variables", arguments: { variablesReference: 2 } },
    // Hover / Watch : a known local resolves, an unknown one fails cleanly.
    { seq: 12, type: "request", command: "evaluate", arguments: { expression: "arr", frameId: 1, context: "hover" } },
    { seq: 13, type: "request", command: "evaluate", arguments: { expression: "no_such_var", frameId: 1, context: "hover" } },
    { seq: 14, type: "request", command: "continue", arguments: { threadId: 1 } },
    { seq: 15, type: "request", command: "disconnect" },
  ];
  const frames = await sendDap(requests);

  // Two stops : the breakpoint, then the step.
  const stops = frames.filter((f) => f.event === "stopped");
  expect(stops.length).toBeGreaterThanOrEqual(2);
  expect(stops[0]?.body?.reason).toBe("breakpoint");
  expect(stops[1]?.body?.reason).toBe("step");

  // The step advanced the line past the breakpoint.
  const stackTraces = frames.filter((f) => f.type === "response" && f.command === "stackTrace");
  const line1 = stackTraces[0]?.body?.stackFrames?.[0]?.line;
  const line2 = stackTraces[1]?.body?.stackFrames?.[0]?.line;
  expect(line1).toBe(13);
  expect(line2).toBeGreaterThan(13);

  // Variables: `arr` is present, holds the array after the step, and NO
  // compiler temp (`$…` / `__…`) leaks into the view.
  const varsResponses = frames.filter((f) => f.type === "response" && f.command === "variables");
  const allNames = varsResponses.flatMap((r) => (r.body?.variables ?? []).map((v: any) => v.name));
  expect(allNames).toContain("arr");
  expect(allNames.some((n: string) => n.startsWith("$") || n.startsWith("__"))).toBe(false);
  const arrAfterStep = (varsResponses[1]?.body?.variables ?? []).find((v: any) => v.name === "arr");
  expect(arrAfterStep?.value).toContain("10");
  // Scope filter : at line 16 only `arr` is live, the later locals (s1…s5, n)
  // and the loops' `v` aren't in scope yet, so they don't clutter the view.
  const line16Names = (varsResponses[1]?.body?.variables ?? []).map((v: any) => v.name);
  expect(line16Names).not.toContain("s5");
  expect(line16Names.filter((n: string) => n === "v").length).toBe(0);
  // `arr` is an array → expandable (non-zero variablesReference), and expanding
  // it (varsResponses[2]) yields its elements as indexed children.
  expect(arrAfterStep?.variablesReference).toBeGreaterThan(0);
  const arrElements = varsResponses[2]?.body?.variables ?? [];
  const elem0 = arrElements.find((v: any) => v.name === "[0]");
  expect(elem0?.value).toBe("10");

  // evaluate (hover/watch): a known local resolves to its value, an unknown
  // identifier fails cleanly (so the editor shows nothing).
  const evals = frames.filter((f) => f.type === "response" && f.command === "evaluate");
  const arrEval = evals.find((e) => e.success === true);
  expect(arrEval?.body?.result).toContain("10");
  expect(evals.some((e) => e.success === false)).toBe(true);
}, { timeout: MEDIUM_BUILD });

test("dap: a runtime trap stops on the exception with its message", async () => {
  // defer_on_panic's main runs, then divides by zero: a runtime trap. Under
  // the debugger it must surface a `stopped {reason:"exception"}` carrying the
  // trap message (so VSCode shows "Paused on exception"), then exit 1 on resume.
  const program = join(process.cwd(), "tests/snippets/defer_on_panic/_main.vader");
  const frames = await sendDap([
    { seq: 1, type: "request", command: "initialize", arguments: { adapterID: "vader" } },
    { seq: 2, type: "request", command: "launch", arguments: { program } },
    { seq: 3, type: "request", command: "configurationDone" },
    // Consumed by the exception pause loop once the trap fires.
    { seq: 4, type: "request", command: "stackTrace", arguments: { threadId: 1 } },
    { seq: 5, type: "request", command: "continue", arguments: { threadId: 1 } },
    { seq: 6, type: "request", command: "disconnect" },
  ]);

  const stopped = frames.find((f) => f.event === "stopped");
  expect(stopped?.body?.reason).toBe("exception");
  expect(stopped?.body?.text).toContain("zero");
  const exited = frames.find((f) => f.event === "exited");
  expect(exited?.body?.exitCode).toBe(1);
  expect(frames.some((f) => f.event === "terminated")).toBe(true);
}, { timeout: MEDIUM_BUILD });

test("dap: the Variables view names function parameters from source", async () => {
  // A breakpoint inside `add(x, y)` must show the params by their source names
  // (x, y), not `arg0`/`arg1`, and hide `sum`, not yet assigned on its line.
  const source = [
    `module "snippet"`,
    ``,
    `import "std/console"`,
    ``,
    `add :: fn(x: i32, y: i32) -> i32 {`,
    `    sum :: x + y`,
    `    return sum`,
    `}`,
    ``,
    `main :: fn() -> i32 {`,
    `    r :: add(3, 4)`,
    `    println("\${r}")`,
    `    return 0`,
    `}`,
    ``,
  ].join("\n");
  // Line 6 = `    sum :: x + y`, the first statement inside `add`.
  const frames = await debugSource(source, [6], [
    { command: "variables", arguments: { variablesReference: 1 } },
    { command: "continue", arguments: { threadId: 1 } },
  ]);
  const vars = frames.find((f) => f.type === "response" && f.command === "variables")?.body?.variables ?? [];
  const names = vars.map((v: any) => v.name);
  expect(names).toContain("x");
  expect(names).toContain("y");
  expect(names).not.toContain("arg0");
  expect(vars.find((v: any) => v.name === "x")?.value).toBe("3");
  expect(vars.find((v: any) => v.name === "y")?.value).toBe("4");
  // `sum` isn't assigned yet at line 6 → not in scope.
  expect(names).not.toContain("sum");
}, { timeout: MEDIUM_BUILD });

test("dap: threads request returns the single VM thread", async () => {
  const program = join(process.cwd(), "tests/snippets/io_println/_main.vader");
  const frames = await driveDap(program);
  const threads = frames.find((f) => f.type === "response" && f.command === "threads");
  expect(threads?.success).toBe(true);
  const list = threads?.body?.threads as Array<{ id: number; name: string }>;
  expect(Array.isArray(list)).toBe(true);
  expect(list.length).toBe(1);
  expect(list[0]!.id).toBe(1);
}, { timeout: MEDIUM_BUILD });

// ---- tasks ------------------------------------------------------------------

// The lines the tests below stop at, in `TASK_PROGRAM`.
const TASK_LOCAL = 7;
const TASK_PRINT = 8;
const MAIN_PRINT = 15;
const MAIN_JOIN = 16;

const TASK_PROGRAM = [
  `module "snippet"`,
  ``,
  `import "std/console"`,
  `import "std/task"`,
  ``,
  `work :: fn() -> i32 {`,
  `    answer :: 7`,
  `    println("from the task")`,
  `    return answer`,
  `}`,
  ``,
  `main :: fn() -> i32 {`,
  `    label :: "done"`,
  `    t :: launch(work)`,
  `    println("from main")`,
  `    println("\${t.join()}")`,
  `    println(label)`,
  `    return 0`,
  `}`,
  ``,
].join("\n");

const responsesTo = (frames: Json[], command: string) =>
  frames.filter((f) => f.type === "response" && f.command === command);
const written = (frames: Json[], category: string) =>
  frames.filter((f) => f.event === "output" && f.body?.category === category).map((f) => f.body.output).join("");

test("dap: what a task writes rides on output events", async () => {
  const frames = await debugSource(TASK_PROGRAM, [], []);
  expect(written(frames, "stdout")).toContain("from the task");
  expect(frames.find((f) => f.event === "exited")?.body?.exitCode).toBe(0);
}, { timeout: MEDIUM_BUILD });

test("dap: a breakpoint in a task stops that thread, and each thread shows its stack", async () => {
  const frames = await debugSource(TASK_PROGRAM, [TASK_PRINT], [
    { command: "threads" },
    { command: "stackTrace", arguments: { threadId: 2 } },
    { command: "stackTrace", arguments: { threadId: 1 } },
    { command: "stackTrace", arguments: { threadId: 2 } },
    { command: "continue", arguments: { threadId: 2 } },
  ]);
  const stopped = frames.find((f) => f.event === "stopped");
  expect(stopped?.body?.reason).toBe("breakpoint");
  expect(stopped?.body?.threadId).toBe(2);
  expect(stopped?.body?.allThreadsStopped).toBe(true);

  const threads = responsesTo(frames, "threads")[0]?.body?.threads;
  expect(threads).toEqual([{ id: 1, name: "main" }, { id: 2, name: "task #1" }]);

  const [task, main, again] = responsesTo(frames, "stackTrace");
  expect(task?.body?.stackFrames?.[0]?.name).toBe("work");
  expect(task?.body?.stackFrames?.[0]?.line).toBe(TASK_PRINT);
  // Main waits for the task inside `join`, which its own frames lead to.
  const mainFrames = main?.body?.stackFrames as Array<{ id: number; name: string; line: number }>;
  expect(mainFrames.at(-1)?.name).toBe("main");
  expect(mainFrames.at(-1)?.line).toBe(MAIN_JOIN);
  // Asking twice names the same frames, and no two frames of a pause share an id.
  expect(again?.body?.stackFrames?.map((f: any) => f.id)).toEqual(task?.body?.stackFrames?.map((f: any) => f.id));
  const ids = [...task!.body.stackFrames, ...mainFrames].map((f: any) => f.id);
  expect(new Set(ids).size).toBe(ids.length);
  expect(frames.some((f) => f.event === "terminated")).toBe(true);
}, { timeout: MEDIUM_BUILD });

test("dap: the frames of a thread that did not stop have scopes, variables and hovers", async () => {
  // Main parks at `t.join()` with `label` in scope. Requests are written ahead of the
  // answers and main's frames get their ids once asked for, so a first run reads
  // the id a second one asks about.
  const stop = [
    { command: "stackTrace", arguments: { threadId: 2 } },
    { command: "stackTrace", arguments: { threadId: 1 } },
  ];
  const first = await debugSource(TASK_PROGRAM, [TASK_PRINT], [...stop, { command: "continue" }]);
  const mainFrames = responsesTo(first, "stackTrace")[1]?.body?.stackFrames as Array<{ id: number; name: string }>;
  const frameId = mainFrames.at(-1)!.id;

  const frames = await debugSource(TASK_PROGRAM, [TASK_PRINT], [
    ...stop,
    { command: "scopes", arguments: { frameId } },
    { command: "evaluate", arguments: { expression: "label", frameId, context: "hover" } },
    { command: "evaluate", arguments: { expression: "answer", frameId, context: "hover" } },
    { command: "variables", arguments: { variablesReference: frameId } },
    { command: "continue" },
  ]);
  const reference = responsesTo(frames, "scopes")[0]?.body?.scopes?.[0]?.variablesReference;
  expect(reference).toBe(frameId);
  const variables = responsesTo(frames, "variables")[0]?.body?.variables as Array<{ name: string; value: string }>;
  expect(variables.find((v) => v.name === "label")?.value).toContain("done");
  const hovers = responsesTo(frames, "evaluate");
  expect(hovers[0]?.body?.result).toContain("done");
  // `answer` is a local of the task, not of main.
  expect(hovers[1]?.success).toBe(false);
}, { timeout: MEDIUM_BUILD });

test("dap: a task that has not begun is listed, with an empty stack", async () => {
  const frames = await debugSource(TASK_PROGRAM, [MAIN_PRINT], [
    { command: "threads" },
    { command: "stackTrace", arguments: { threadId: 2 } },
    { command: "continue", arguments: { threadId: 1 } },
  ]);
  expect(frames.find((f) => f.event === "stopped")?.body?.threadId).toBe(1);
  expect(responsesTo(frames, "threads")[0]?.body?.threads?.length).toBe(2);
  const stack = responsesTo(frames, "stackTrace")[0];
  expect(stack?.success).toBe(true);
  expect(stack?.body?.stackFrames).toEqual([]);
}, { timeout: MEDIUM_BUILD });

test("dap: a step stays in the thread that took it", async () => {
  const frames = await debugSource(TASK_PROGRAM, [TASK_LOCAL], [
    { command: "next", arguments: { threadId: 2 } },
    { command: "stackTrace", arguments: { threadId: 2 } },
    { command: "continue", arguments: { threadId: 2 } },
  ]);
  const stops = frames.filter((f) => f.event === "stopped");
  expect(stops.map((f) => [f.body.reason, f.body.threadId])).toEqual([["breakpoint", 2], ["step", 2]]);
  expect(responsesTo(frames, "stackTrace")[0]?.body?.stackFrames?.[0]?.line).toBe(TASK_PRINT);
}, { timeout: MEDIUM_BUILD });

test("dap: a trap in a task stops that thread, then closes the session", async () => {
  const source = [
    `module "snippet"`,
    ``,
    `import "std/console"`,
    `import "std/task"`,
    ``,
    `divide :: fn(a: i32, b: i32) -> i32 = a / b`,
    ``,
    `work :: fn() -> i32 = divide(1, 0)`,
    ``,
    `main :: fn() -> i32 {`,
    `    t :: launch(work)`,
    `    println("\${t.join()}")`,
    `    return 0`,
    `}`,
    ``,
  ].join("\n");
  const frames = await debugSource(source, [], [
    { command: "threads" },
    { command: "stackTrace", arguments: { threadId: 1 } },
    { command: "continue", arguments: { threadId: 2 } },
  ]);
  const stopped = frames.find((f) => f.event === "stopped");
  expect(stopped?.body?.reason).toBe("exception");
  expect(stopped?.body?.threadId).toBe(2);
  expect(stopped?.body?.text).toContain("zero");
  expect(written(frames, "stderr")).toContain("zero");
  // The other threads can still be read at that stop.
  expect(responsesTo(frames, "threads")[0]?.body?.threads?.length).toBe(2);
  expect(responsesTo(frames, "stackTrace")[0]?.body?.stackFrames?.at(-1)?.name).toBe("main");
  expect(frames.find((f) => f.event === "exited")?.body?.exitCode).toBe(1);
  expect(frames.some((f) => f.event === "terminated")).toBe(true);
  // The client's goodbye is still answered.
  expect(responsesTo(frames, "disconnect")[0]?.success).toBe(true);
}, { timeout: MEDIUM_BUILD });

test("dap: a task cancelled when main returns is announced through the session", async () => {
  const source = [
    `module "snippet"`,
    ``,
    `import "std/task"`,
    ``,
    `work :: fn() -> i32 = 1`,
    ``,
    `main :: fn() -> i32 {`,
    `    launch(work)`,
    `    return 0`,
    `}`,
    ``,
  ].join("\n");
  const frames = await debugSource(source, [], []);
  expect(written(frames, "stderr")).toContain("task #1 still runs when main returns");
  expect(frames.find((f) => f.event === "exited")?.body?.exitCode).toBe(1);
}, { timeout: MEDIUM_BUILD });
