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

// Batch-drive one DAP session over `program` and return every frame the server
// emitted, in order.
async function driveDap(program: string): Promise<Json[]> {
  const requests: object[] = [
    { seq: 1, type: "request", command: "initialize", arguments: { adapterID: "vader" } },
    { seq: 2, type: "request", command: "launch", arguments: { program } },
    { seq: 3, type: "request", command: "configurationDone" },
    { seq: 4, type: "request", command: "threads" },
    { seq: 5, type: "request", command: "disconnect" },
  ];
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
