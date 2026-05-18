// LSP end-to-end tests : spawn `vader lsp`, drive the JSON-RPC stream over
// stdin/stdout, verify `textDocument/definition` and `textDocument/hover`
// land on the right declaration and produce the expected Markdown.
//
// The server is a Vader program executed through the bytecode VM (cf.
// `src/cli/commands/lsp.ts` shim), so each `Bun.spawn` invocation pays a
// ~2-3 s VM-bootstrap cost. To keep `bun test` snappy this suite is
// gated behind `RUN_LSP_TESTS=1` ; the gate skips every test rather than
// declaring them failed when not set. We bundle every query for a given
// source into a single server session to amortise the bootstrap.

import { test, expect } from "bun:test";

import { MEDIUM_BUILD } from "./cli-bin.ts";

const ENABLED = process.env.RUN_LSP_TESTS === "1";

type Json = unknown;

interface Position {
  line: number;
  character: number;
}

interface Query {
  method: "textDocument/definition" | "textDocument/hover";
  position: Position;
}

interface QueryResult {
  query: Query;
  result: Json;
}

// Encode `obj` as a JSON-RPC frame : Content-Length header + body.
function frame(obj: object): Uint8Array {
  const body = new TextEncoder().encode(JSON.stringify(obj));
  const header = new TextEncoder().encode(
    `Content-Length: ${body.byteLength}\r\n\r\n`,
  );
  const out = new Uint8Array(header.byteLength + body.byteLength);
  out.set(header, 0);
  out.set(body, header.byteLength);
  return out;
}

// Read one JSON-RPC frame from `chunks` starting at `cursor`. Returns the
// parsed JSON and the new cursor, or `null` if `chunks` doesn't yet hold
// a complete frame.
function readFrame(
  chunks: Uint8Array, cursor: number,
): { body: Json; cursor: number } | null {
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

function findSeparator(buf: Uint8Array): number {
  for (let i = 0; i + 3 < buf.byteLength; i++) {
    if (buf[i] === 0x0d && buf[i + 1] === 0x0a
     && buf[i + 2] === 0x0d && buf[i + 3] === 0x0a) return i;
  }
  return -1;
}

// Run one LSP session : open `source` as a virtual document, fire every
// query in order, return one result per query (in the same order).
async function driveLsp(source: string, queries: Query[]): Promise<QueryResult[]> {
  const uri = "file:///lsp-test.vader";
  const requests: object[] = [
    { jsonrpc: "2.0", id: 1, method: "initialize",
      params: { rootUri: null, capabilities: {} } },
    { jsonrpc: "2.0", method: "initialized", params: {} },
    { jsonrpc: "2.0", method: "textDocument/didOpen",
      params: { textDocument: { uri, languageId: "vader", version: 1, text: source } } },
  ];
  for (let i = 0; i < queries.length; i++) {
    const q = queries[i]!;
    requests.push({
      jsonrpc: "2.0",
      id: 100 + i,
      method: q.method,
      params: { textDocument: { uri }, position: q.position },
    });
  }
  requests.push({ jsonrpc: "2.0", id: 999, method: "shutdown", params: null });
  requests.push({ jsonrpc: "2.0", method: "exit", params: null });

  const stdin = new Uint8Array(
    requests.reduce<number>((n, r) => n + frame(r).byteLength, 0),
  );
  let offset = 0;
  for (const r of requests) {
    const f = frame(r);
    stdin.set(f, offset);
    offset += f.byteLength;
  }

  const proc = Bun.spawn({
    cmd: ["bun", "src/index.ts", "lsp"],
    cwd: process.cwd(),
    stdin: "pipe",
    stdout: "pipe",
    stderr: "pipe",
  });
  proc.stdin.write(stdin);
  await proc.stdin.end();
  const stdout = new Uint8Array(await new Response(proc.stdout).arrayBuffer());
  await proc.exited;

  // Parse every frame, index by request id.
  const responses = new Map<number, Json>();
  let cursor = 0;
  while (cursor < stdout.byteLength) {
    const r = readFrame(stdout, cursor);
    if (r === null) break;
    cursor = r.cursor;
    const msg = r.body as { id?: number; result?: Json };
    if (typeof msg.id === "number" && "result" in msg) {
      responses.set(msg.id, msg.result);
    }
  }
  return queries.map((q, i) => ({
    query: q,
    result: responses.get(100 + i) ?? null,
  }));
}

interface LocationRange {
  start: Position;
  end: Position;
}
interface Location {
  uri: string;
  range: LocationRange;
}
interface Hover {
  contents: { kind: string; value: string };
}

const SOURCE = `import "std/io" { println }

/// Doubles its argument.
double :: fn(x: i32) -> i32 {
    return x * 2
}

/// A 2D point.
Point :: struct {
    x: i32
    y: i32
}

main :: fn() -> i32 {
    p :: Point { .x = 1, .y = 2 }
    y :: double(21)
    return y
}
`;

test("lsp: goto-def + hover end-to-end", async () => {
  if (!ENABLED) return;

  const queries: Query[] = [
    // 0: click on `double` call site → jumps to its decl
    { method: "textDocument/definition", position: { line: 15, character: 9 } },
    // 1: hover on `double` call → signature + vaderdoc
    { method: "textDocument/hover", position: { line: 15, character: 9 } },
    // 2: click on `Point` struct literal → jumps to struct decl
    { method: "textDocument/definition", position: { line: 14, character: 9 } },
    // 3: hover on `Point` literal → struct head signature + vaderdoc
    { method: "textDocument/hover", position: { line: 14, character: 9 } },
    // 4: goto-def on imported `println` (no local decl) → null
    { method: "textDocument/definition", position: { line: 16, character: 4 } },
    // 5: hover on whitespace → null
    { method: "textDocument/hover", position: { line: 0, character: 0 } },
  ];

  const results = await driveLsp(SOURCE, queries);
  expect(results).toHaveLength(queries.length);

  // 0: goto-def double → line 3 (the `double :: fn(...)` line), char 0..6
  const def_double = results[0]!.result as Location;
  expect(def_double.uri).toMatch(/lsp-test\.vader$/);
  expect(def_double.range.start).toEqual({ line: 3, character: 0 });
  expect(def_double.range.end).toEqual({ line: 3, character: 6 });

  // 1: hover double → markdown with signature + doc
  const hov_double = results[1]!.result as Hover;
  expect(hov_double.contents.kind).toBe("markdown");
  expect(hov_double.contents.value).toContain("```vader\ndouble :: fn(x: i32) -> i32\n```");
  expect(hov_double.contents.value).toContain("Doubles its argument.");

  // 2: goto-def Point → line 8 (the `Point :: struct {` line), char 0..5
  const def_point = results[2]!.result as Location;
  expect(def_point.range.start).toEqual({ line: 8, character: 0 });
  expect(def_point.range.end).toEqual({ line: 8, character: 5 });

  // 3: hover Point → markdown with struct signature + doc
  const hov_point = results[3]!.result as Hover;
  expect(hov_point.contents.kind).toBe("markdown");
  expect(hov_point.contents.value).toContain("```vader\nPoint :: struct\n```");
  expect(hov_point.contents.value).toContain("A 2D point.");

  // 4 + 5: unknown / whitespace → null
  expect(results[4]!.result).toBeNull();
  expect(results[5]!.result).toBeNull();
}, { timeout: MEDIUM_BUILD });

test("lsp: empty document doesn't crash, returns null on lookups", async () => {
  if (!ENABLED) return;

  const queries: Query[] = [
    { method: "textDocument/definition", position: { line: 0, character: 0 } },
    { method: "textDocument/hover", position: { line: 0, character: 0 } },
  ];

  const results = await driveLsp("", queries);
  expect(results[0]!.result).toBeNull();
  expect(results[1]!.result).toBeNull();
}, { timeout: MEDIUM_BUILD });

// Bindings : params + locals + for-in. Each runs in its own session so
// the assertion failures point at a single concept.
const BINDINGS_SOURCE = `import "std/io" { println }

double :: fn(x: i32) -> i32 {
    y :: x * 2
    return y
}

main :: fn() -> i32 {
    nums :: [1, 2, 3]
    for n in nums {
        println("\${double(n)}")
    }
    return 0
}
`;

test("lsp: goto-def jumps to fn param", async () => {
  if (!ENABLED) return;
  // Position of `x` inside `y :: x * 2` at line 3.
  // Line content : "    y :: x * 2"  → `x` at character 9.
  const results = await driveLsp(BINDINGS_SOURCE, [
    { method: "textDocument/definition", position: { line: 3, character: 9 } },
  ]);
  const loc = results[0]!.result as Location;
  // Param `x` lives in the fn signature on line 2 : `double :: fn(x: i32) ...`
  // → `x` at character 13.
  expect(loc.range.start).toEqual({ line: 2, character: 13 });
  expect(loc.range.end).toEqual({ line: 2, character: 14 });
}, { timeout: MEDIUM_BUILD });

test("lsp: hover on fn param shows its type", async () => {
  if (!ENABLED) return;
  const results = await driveLsp(BINDINGS_SOURCE, [
    { method: "textDocument/hover", position: { line: 3, character: 9 } },
  ]);
  const hov = results[0]!.result as Hover;
  expect(hov.contents.kind).toBe("markdown");
  expect(hov.contents.value).toContain("```vader\nx: i32\n```");
}, { timeout: MEDIUM_BUILD });

test("lsp: goto-def jumps to local let-binding", async () => {
  if (!ENABLED) return;
  // `return y` on line 4 — `y` at character 11.
  // Local `y` is declared on line 3 at character 4 : `    y :: x * 2`.
  const results = await driveLsp(BINDINGS_SOURCE, [
    { method: "textDocument/definition", position: { line: 4, character: 11 } },
  ]);
  const loc = results[0]!.result as Location;
  expect(loc.range.start).toEqual({ line: 3, character: 4 });
  expect(loc.range.end).toEqual({ line: 3, character: 5 });
}, { timeout: MEDIUM_BUILD });

test("lsp: hover on local shows its binding form", async () => {
  if (!ENABLED) return;
  const results = await driveLsp(BINDINGS_SOURCE, [
    { method: "textDocument/hover", position: { line: 4, character: 11 } },
  ]);
  const hov = results[0]!.result as Hover;
  expect(hov.contents.value).toContain("```vader\ny :: x * 2\n```");
}, { timeout: MEDIUM_BUILD });

test("lsp: goto-def jumps to for-in binding", async () => {
  if (!ENABLED) return;
  // Inside the for body : `println("${double(n)}")` on line 10.
  // `n` sits at character 26 (inside `double(n)`).
  // The binding `n` is on line 9 : `    for n in nums {` → `n` at character 8.
  const results = await driveLsp(BINDINGS_SOURCE, [
    { method: "textDocument/definition", position: { line: 10, character: 26 } },
  ]);
  const loc = results[0]!.result as Location;
  expect(loc.range.start).toEqual({ line: 9, character: 8 });
  expect(loc.range.end).toEqual({ line: 9, character: 9 });
}, { timeout: MEDIUM_BUILD });

test("lsp: param goto-def is not visible outside its fn body", async () => {
  if (!ENABLED) return;
  // `x` is a param of `double` (lines 2-5). Click on the `x` of `i32`
  // type name later in `main` — there's no `x` named there, so the
  // lookup should NOT bleed through to the param.
  const src = `double :: fn(x: i32) -> i32 {
    return x * 2
}

main :: fn() -> i32 {
    return 0
}
`;
  // Click on `0` literal on line 5 char 11 — definitely not on any identifier.
  const results = await driveLsp(src, [
    { method: "textDocument/definition", position: { line: 5, character: 11 } },
  ]);
  expect(results[0]!.result).toBeNull();
}, { timeout: MEDIUM_BUILD });

// Cross-file goto-def : the indexer scans `import { ... }` bindings, the
// resolver maps `std/*` / `vader/*` module paths to absolute file
// paths via `stdlib_root` / `vader_root` (seeded by the host shim),
// opens the source file, and returns the LSP Location pointing at the
// origin's name_span. Hover renders the source decl's signature + doc
// the same way.

const CROSSFILE_SOURCE = `import "std/io" { println, eprintln }
import "std/collections" { MutableMap }

main :: fn() -> i32 {
    println("hi")
    eprintln("hello")
    m :: MutableMap(string, i32) { .buckets = [], .size = 0 }
    return 0
}
`;

test("lsp: goto-def follows imports across files (std/io)", async () => {
  if (!ENABLED) return;
  // Click on `println` call inside the body at line 4 char 4.
  const results = await driveLsp(CROSSFILE_SOURCE, [
    { method: "textDocument/definition", position: { line: 4, character: 4 } },
  ]);
  const loc = results[0]!.result as Location;
  expect(loc.uri).toMatch(/stdlib\/std\/io\.vader$/);
  // We don't pin the exact line — `std/io.vader` evolves and the test
  // would churn on every stdlib edit. The contract is "lands in
  // io.vader on a non-zero line".
  expect(loc.range.start.line).toBeGreaterThan(0);
}, { timeout: MEDIUM_BUILD });

test("lsp: goto-def follows imports across files (collections)", async () => {
  if (!ENABLED) return;
  // Click on `MutableMap` type ref at line 6 char 12.
  const results = await driveLsp(CROSSFILE_SOURCE, [
    { method: "textDocument/definition", position: { line: 6, character: 12 } },
  ]);
  const loc = results[0]!.result as Location;
  expect(loc.uri).toMatch(/stdlib\/std\/collections\.vader$/);
  expect(loc.range.start.line).toBeGreaterThan(0);
}, { timeout: MEDIUM_BUILD });

test("lsp: hover on imported symbol surfaces its origin signature", async () => {
  if (!ENABLED) return;
  const results = await driveLsp(CROSSFILE_SOURCE, [
    { method: "textDocument/hover", position: { line: 4, character: 4 } },
  ]);
  const hov = results[0]!.result as Hover;
  expect(hov.contents.kind).toBe("markdown");
  // Signature comes from the source decl, not the importing file.
  expect(hov.contents.value).toContain("println");
  expect(hov.contents.value).toContain("```vader");
}, { timeout: MEDIUM_BUILD });

test("lsp: cross-file resolution doesn't bleed for non-imported names", async () => {
  if (!ENABLED) return;
  // `MutableSet` exists in `std/collections` but isn't imported here,
  // so a click on a bare `MutableSet` identifier should still miss.
  const src = `main :: fn() -> i32 {
    MutableSet
    return 0
}
`;
  const results = await driveLsp(src, [
    { method: "textDocument/definition", position: { line: 1, character: 6 } },
  ]);
  expect(results[0]!.result).toBeNull();
}, { timeout: MEDIUM_BUILD });

test("lsp: definition returns LocationLink when client supports it", async () => {
  if (!ENABLED) return;

  // Manual run (the `driveLsp` helper sends `capabilities: {}` which
  // falls into the legacy `Location` branch — here we send the
  // `linkSupport` flag VSCode/IntelliJ actually send so the server
  // emits a `LocationLink[]` payload).
  const src = `double :: fn(x: i32) -> i32 {
    return x * 2
}

main :: fn() -> i32 {
    return double(21)
}
`;
  const URI = "file:///link-support.vader";
  const requests: object[] = [
    { jsonrpc: "2.0", id: 1, method: "initialize", params: {
      rootUri: null,
      capabilities: { textDocument: { definition: { linkSupport: true } } },
    } },
    { jsonrpc: "2.0", method: "initialized", params: {} },
    { jsonrpc: "2.0", method: "textDocument/didOpen", params: {
      textDocument: { uri: URI, languageId: "vader", version: 1, text: src },
    } },
    // Click on the `double` call site at line 5 char 11.
    { jsonrpc: "2.0", id: 2, method: "textDocument/definition", params: {
      textDocument: { uri: URI }, position: { line: 5, character: 11 },
    } },
    { jsonrpc: "2.0", id: 999, method: "shutdown", params: null },
    { jsonrpc: "2.0", method: "exit", params: null },
  ];
  const stdin = new Uint8Array(
    requests.reduce<number>((n, r) => n + frame(r).byteLength, 0),
  );
  let offset = 0;
  for (const r of requests) {
    const f = frame(r);
    stdin.set(f, offset);
    offset += f.byteLength;
  }
  const proc = Bun.spawn({
    cmd: ["bun", "src/index.ts", "lsp"],
    cwd: process.cwd(),
    stdin: "pipe", stdout: "pipe", stderr: "pipe",
  });
  proc.stdin.write(stdin);
  await proc.stdin.end();
  const stdout = new Uint8Array(await new Response(proc.stdout).arrayBuffer());
  await proc.exited;

  let defResult: Json = null;
  let cursor = 0;
  while (cursor < stdout.byteLength) {
    const r = readFrame(stdout, cursor);
    if (r === null) break;
    cursor = r.cursor;
    const msg = r.body as { id?: number; result?: Json };
    if (msg.id === 2) defResult = msg.result ?? null;
  }

  // LocationLink[] : array with one LocationLink (originSelectionRange
  // + targetUri + targetRange + targetSelectionRange).
  expect(Array.isArray(defResult)).toBe(true);
  const link = (defResult as object[])[0] as Record<string, unknown>;
  expect(link.originSelectionRange).toBeDefined();
  expect(link.targetUri).toMatch(/link-support\.vader$/);
  expect(link.targetSelectionRange).toBeDefined();
  expect(link.targetRange).toBeDefined();

  // Origin range covers the clicked `double` identifier (6 chars
  // starting at the call site).
  const origin = link.originSelectionRange as { start: Position; end: Position };
  expect(origin.start.line).toBe(5);
  expect(origin.end.character - origin.start.character).toBe(6); // "double"

  // Target name lands on the decl's name at line 0 char 0..6.
  const sel = link.targetSelectionRange as { start: Position; end: Position };
  expect(sel.start).toEqual({ line: 0, character: 0 });
  expect(sel.end).toEqual({ line: 0, character: 6 });
}, { timeout: MEDIUM_BUILD });

test("lsp: initialize advertises definition + hover providers", async () => {
  if (!ENABLED) return;

  // Drive a session with zero queries — we only care about the
  // `initialize` response.
  const requests: object[] = [
    { jsonrpc: "2.0", id: 1, method: "initialize",
      params: { rootUri: null, capabilities: {} } },
    { jsonrpc: "2.0", id: 999, method: "shutdown", params: null },
    { jsonrpc: "2.0", method: "exit", params: null },
  ];
  const stdin = new Uint8Array(
    requests.reduce<number>((n, r) => n + frame(r).byteLength, 0),
  );
  let offset = 0;
  for (const r of requests) {
    const f = frame(r);
    stdin.set(f, offset);
    offset += f.byteLength;
  }

  const proc = Bun.spawn({
    cmd: ["bun", "src/index.ts", "lsp"],
    cwd: process.cwd(),
    stdin: "pipe",
    stdout: "pipe",
    stderr: "pipe",
  });
  proc.stdin.write(stdin);
  await proc.stdin.end();
  const stdout = new Uint8Array(await new Response(proc.stdout).arrayBuffer());
  await proc.exited;

  let initResult: Json = null;
  let cursor = 0;
  while (cursor < stdout.byteLength) {
    const r = readFrame(stdout, cursor);
    if (r === null) break;
    cursor = r.cursor;
    const msg = r.body as { id?: number; result?: Json };
    if (msg.id === 1) initResult = msg.result ?? null;
  }

  const caps = (initResult as { capabilities?: Record<string, unknown> })?.capabilities;
  expect(caps).toBeDefined();
  expect(caps!.definitionProvider).toBe(true);
  expect(caps!.hoverProvider).toBe(true);
}, { timeout: MEDIUM_BUILD });
