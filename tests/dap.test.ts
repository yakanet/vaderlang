// DAP end-to-end test : spawn the native `vader dap`, drive the Debug Adapter
// Protocol handshake over stdin/stdout, verify the Phase-1 proof-of-life flow —
// initialize → launch → configurationDone runs the program, its output surfaces
// as `output` events (NOT on the raw stdout channel, which would corrupt the
// protocol), and the session ends with `exited` + `terminated`.
//
// The adapter is the compiled native binary (`build/vader dap`) driving the
// bytecode VM. The DAP message order is deterministic (the server processes
// frames sequentially and each command's effect doesn't depend on the previous
// response's contents), so every request is batch-written up front — the server
// reads them in order off the pipe, exactly like the LSP e2e test.

import { test, expect } from "bun:test";
import { join } from "node:path";

import { CLI_BIN, MEDIUM_BUILD, ensureCliBuilt } from "./cli-bin.ts";

ensureCliBuilt();

type Json = { seq: number; type: string; command?: string; event?: string; body?: any; success?: boolean };

// Encode `obj` as a DAP frame : Content-Length header + JSON body (same framing
// as LSP).
function frame(obj: object): Uint8Array {
  const body = new TextEncoder().encode(JSON.stringify(obj));
  const header = new TextEncoder().encode(`Content-Length: ${body.byteLength}\r\n\r\n`);
  const out = new Uint8Array(header.byteLength + body.byteLength);
  out.set(header, 0);
  out.set(body, header.byteLength);
  return out;
}

function findSeparator(buf: Uint8Array): number {
  for (let i = 0; i + 3 < buf.byteLength; i++) {
    if (buf[i] === 0x0d && buf[i + 1] === 0x0a && buf[i + 2] === 0x0d && buf[i + 3] === 0x0a) return i;
  }
  return -1;
}

function readFrame(chunks: Uint8Array, cursor: number): { body: Json; cursor: number } | null {
  const view = chunks.subarray(cursor);
  const sep = findSeparator(view);
  if (sep < 0) return null;
  const headerText = new TextDecoder().decode(view.subarray(0, sep));
  let length = -1;
  for (const line of headerText.split("\r\n")) {
    const m = /^content-length:\s*(\d+)$/i.exec(line);
    if (m) length = Number(m[1]);
  }
  if (length < 0) throw new Error(`no Content-Length in header: ${headerText}`);
  const bodyStart = cursor + sep + 4;
  const bodyEnd = bodyStart + length;
  if (chunks.byteLength < bodyEnd) return null;
  const bodyText = new TextDecoder().decode(chunks.subarray(bodyStart, bodyEnd));
  return { body: JSON.parse(bodyText), cursor: bodyEnd };
}

// Batch-write `requests` to a fresh `vader dap` over stdio and return every
// frame it emitted, in order. The DAP flow is deterministic and the server
// (incl. the paused-state loop) reads frames sequentially off the pipe, so a
// pre-built request list drives the whole session — no reactive client needed.
async function sendDap(_program: string, requests: object[]): Promise<Json[]> {
  const total = requests.reduce<number>((n, r) => n + frame(r).byteLength, 0);
  const stdin = new Uint8Array(total);
  let offset = 0;
  for (const r of requests) {
    const f = frame(r);
    stdin.set(f, offset);
    offset += f.byteLength;
  }

  const proc = Bun.spawn({
    cmd: [CLI_BIN, "dap"],
    cwd: process.cwd(),
    stdin: "pipe",
    stdout: "pipe",
    stderr: "pipe",
  });
  const killer = setTimeout(() => { try { proc.kill(9); } catch {} }, MEDIUM_BUILD);
  proc.stdin.write(stdin);
  await proc.stdin.end();
  const stdout = new Uint8Array(await new Response(proc.stdout).arrayBuffer());
  await proc.exited;
  clearTimeout(killer);

  const frames: Json[] = [];
  let cursor = 0;
  while (cursor < stdout.byteLength) {
    const r = readFrame(stdout, cursor);
    if (r === null) break;
    cursor = r.cursor;
    frames.push(r.body);
  }
  return frames;
}

// The proof-of-life flow : run to completion, no breakpoints.
async function driveDap(program: string): Promise<Json[]> {
  return sendDap(program, [
    { seq: 1, type: "request", command: "initialize", arguments: { adapterID: "vader" } },
    { seq: 2, type: "request", command: "launch", arguments: { program } },
    // VSCode sends setBreakpoints between `initialized` and configurationDone,
    // and gates configurationDone (the run trigger) on a well-formed response —
    // it MUST echo one breakpoint object per requested line. Line 1 is a
    // comment (no op), so this exercises the response shape without stopping the
    // run-to-completion flow — the dedicated test below covers an actual stop.
    { seq: 3, type: "request", command: "setBreakpoints",
      arguments: { source: { path: program }, breakpoints: [{ line: 1 }], lines: [1] } },
    { seq: 4, type: "request", command: "configurationDone" },
    { seq: 5, type: "request", command: "threads" },
    { seq: 6, type: "request", command: "disconnect" },
  ]);
}

test("dap: proof of life — initialize, launch, run, capture output, terminate", async () => {
  // io_println prints "hello\n" then "42\n" — imports std/io, resolved relative
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

  // setBreakpoints MUST return a `breakpoints` array (one per requested line) —
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

  // Program output rides on `output` events (category stdout) — NOT the raw
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
  // Breakpoint on line 14 (the first body statement — a signature line carries
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
  const frames = await sendDap(program, requests);

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

  // continue ran it to completion — output surfaced + terminated.
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
  // locals (arr, s1, …) — NOT the compiler's `$…` / `__…` temporaries.
  const program = join(process.cwd(), "tests/snippets/array_slice/_main.vader");
  const requests = [
    { seq: 1, type: "request", command: "initialize", arguments: { adapterID: "vader" } },
    { seq: 2, type: "request", command: "launch", arguments: { program } },
    { seq: 3, type: "request", command: "setBreakpoints",
      arguments: { source: { path: program }, breakpoints: [{ line: 13 }] } },
    { seq: 4, type: "request", command: "configurationDone" },
    // Stop #1 (breakpoint, line 13) — inspect, then step over.
    { seq: 5, type: "request", command: "stackTrace", arguments: { threadId: 1 } },
    { seq: 6, type: "request", command: "scopes", arguments: { frameId: 0 } },
    { seq: 7, type: "request", command: "variables", arguments: { variablesReference: 1 } },
    { seq: 8, type: "request", command: "next", arguments: { threadId: 1 } },
    // Stop #2 (step, past line 13) — `arr` is now materialised.
    { seq: 9, type: "request", command: "stackTrace", arguments: { threadId: 1 } },
    { seq: 10, type: "request", command: "variables", arguments: { variablesReference: 1 } },
    { seq: 11, type: "request", command: "continue", arguments: { threadId: 1 } },
    { seq: 12, type: "request", command: "disconnect" },
  ];
  const frames = await sendDap(program, requests);

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
