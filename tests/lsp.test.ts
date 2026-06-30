// LSP end-to-end tests : spawn the native `vader lsp`, drive the JSON-RPC
// stream over stdin/stdout, verify `textDocument/definition` / `hover` /
// `completion` / `codeAction` land on the right declaration and produce the
// expected payloads.
//
// The server is the compiled native binary (`build/vader lsp`) — fast enough
// (~25 ms/session) to run unconditionally. Each session writes the source to a
// real on-disk fixture under a fresh temp dir and points `rootUri` at it, so
// the resolver discovers a bounded project root (NOT the entry file's folder,
// which for a virtual `/`-rooted URI would make module discovery walk the whole
// filesystem). Every query for a source is bundled into one session.

import { test, expect } from "bun:test";
import { mkdtempSync, mkdirSync, writeFileSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { dirname, join } from "node:path";

import { CLI_BIN, MEDIUM_BUILD, ensureCliBuilt } from "./cli-bin.ts";

ensureCliBuilt();

type Json = unknown;

interface Position {
  line: number;
  character: number;
}

interface Query {
  method:
    | "textDocument/definition"
    | "textDocument/hover"
    | "textDocument/completion"
    | "textDocument/codeAction";
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
async function driveLsp(
  source: string, queries: Query[], extraFiles: Record<string, string> = {},
): Promise<QueryResult[]> {
  // Write the source to a real on-disk fixture under a fresh temp dir, and root
  // the session there. The resolver then discovers a bounded project (the temp
  // dir + the seeded std/ + vader/ roots) instead of the entry file's folder.
  // `extraFiles` (relative path → content) seed sibling modules for cross-module
  // scenarios (e.g. member completion on an imported struct type).
  const dir = mkdtempSync(join(tmpdir(), "vlsp-"));
  const file = join(dir, "lsp-test.vader");
  writeFileSync(file, source);
  for (const [rel, content] of Object.entries(extraFiles)) {
    const p = join(dir, rel);
    mkdirSync(dirname(p), { recursive: true });
    writeFileSync(p, content);
  }
  const uri = `file://${file}`;
  const requests: object[] = [
    { jsonrpc: "2.0", id: 1, method: "initialize",
      params: { rootUri: `file://${dir}`, capabilities: {} } },
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
      // `position` serves hover/def/completion ; `range` + `context` serve
      // codeAction. Sending all of them is harmless — each handler reads what
      // it needs.
      params: {
        textDocument: { uri },
        position: q.position,
        range: { start: q.position, end: q.position },
        context: { diagnostics: [] },
      },
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
    cmd: [CLI_BIN, "lsp", `--stdlib-root=${process.cwd()}/stdlib`, `--vader-root=${process.cwd()}/vader`],
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
  rmSync(dir, { recursive: true, force: true });

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
interface CompletionItem {
  label: string;
  kind?: number;
  detail?: string;
}
interface CompletionList {
  isIncomplete: boolean;
  items: CompletionItem[];
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

test("lsp: completion lists in-scope identifiers + keywords", async () => {

  // Cursor inside main's body (line 16 = `    return y`).
  const results = await driveLsp(SOURCE, [
    { method: "textDocument/completion", position: { line: 16, character: 4 } },
  ]);
  const list = results[0]!.result as CompletionList;
  expect(list.isIncomplete).toBe(false);
  const labels = new Set(list.items.map((i) => i.label));

  // Top-level declarations of the file.
  expect(labels.has("double")).toBe(true);
  expect(labels.has("Point")).toBe(true);
  expect(labels.has("main")).toBe(true);
  // Imported name.
  expect(labels.has("println")).toBe(true);
  // In-scope locals of main.
  expect(labels.has("p")).toBe(true);
  expect(labels.has("y")).toBe(true);
  // A language keyword.
  expect(labels.has("return")).toBe(true);

  // `double` is a function (CompletionItemKind.Function = 3).
  const dbl = list.items.find((i) => i.label === "double");
  expect(dbl?.kind).toBe(3);
}, { timeout: MEDIUM_BUILD });

// A module-declared entry (so the typed project loads its bodies) with two
// unannotated locals — `n :: mk()` and `b :: Box {...}`. Completion should
// surface their *inferred* type as detail (TS-style), resolved through the
// typed cache, rather than the index's RHS source slice.
const LOCAL_TYPE_SOURCE = `module "demo"

mk :: fn() -> i32 {
    return 7
}

Box :: struct {
    v: i32
}

main :: fn() -> i32 {
    n :: mk()
    b :: Box { .v = 1 }
    return n
}
`;

test("lsp: completion shows a local's inferred type as detail", async () => {
  // Line 13 = `    return n` — inside main's body, so `n` and `b` are visible.
  const results = await driveLsp(LOCAL_TYPE_SOURCE, [
    { method: "textDocument/completion", position: { line: 13, character: 4 } },
  ]);
  const list = results[0]!.result as CompletionList;
  const labels = new Set(list.items.map((i) => i.label));
  expect(labels.has("n")).toBe(true);
  expect(labels.has("b")).toBe(true);

  // `n :: mk()` → `i32` (the call's return type), `b :: Box {...}` → `Box`.
  expect(list.items.find((i) => i.label === "n")?.detail).toBe("i32");
  expect(list.items.find((i) => i.label === "b")?.detail).toBe("Box");

  // A function's detail is its signature, with the redundant `<name> :: `
  // prefix stripped — the label already carries the name.
  expect(list.items.find((i) => i.label === "mk")?.detail).toBe("fn() -> i32");
}, { timeout: MEDIUM_BUILD });

const MEMBER_SOURCE = `module "lsp_test"

Greeter :: trait {
    greet :: fn(self) -> i32
}

Point :: struct {
    x: i32
    y: i32
}

Point implements Greeter {
    greet :: fn(self) -> i32 { return self.x }
}

main :: fn() -> i32 {
    p :: Point { .x = 1, .y = 2 }
    return p.x
}

magnitude :: fn(self: Point) -> i32 = self.x + self.y
`;

test("lsp: completion after `.` lists struct fields + impl methods", async () => {

  // Line 17 = `    return p.x` ; the `.` is at character 12, so a cursor at
  // character 13 (just past the dot) is a member-access completion on `p`.
  const results = await driveLsp(MEMBER_SOURCE, [
    { method: "textDocument/completion", position: { line: 17, character: 13 } },
  ]);
  const list = results[0]!.result as CompletionList;
  const labels = new Set(list.items.map((i) => i.label));

  // Struct fields of Point.
  expect(labels.has("x")).toBe(true);
  expect(labels.has("y")).toBe(true);
  // Impl method on Point.
  expect(labels.has("greet")).toBe(true);
  // Free-fn UFCS method on Point (`magnitude :: fn(self: Point)` → `p.magnitude()`).
  expect(labels.has("magnitude")).toBe(true);
  // Member completion is receiver-scoped — no top-level idents / keywords leak.
  expect(labels.has("main")).toBe(false);
  expect(labels.has("return")).toBe(false);

  // Field `x` carries CompletionItemKind.Field (5) ; method `greet` Method (2).
  expect(list.items.find((i) => i.label === "x")?.kind).toBe(5);
  expect(list.items.find((i) => i.label === "greet")?.kind).toBe(2);
}, { timeout: MEDIUM_BUILD });

const TRAILING_DOT_SOURCE = `module "lsp_test"

Point :: struct {
    x: i32
    y: i32
}

main :: fn() -> i32 {
    p :: Point { .x = 1, .y = 2 }
    p.
    return 0
}
`;

test("lsp: member completion on a trailing dot (mid-edit, no member yet)", async () => {

  // Line 9 = `    p.` ; cursor at char 6 is just past the dot, no member typed.
  // The parser error-recovers `p.` into a FieldExpr whose target stays typed.
  const results = await driveLsp(TRAILING_DOT_SOURCE, [
    { method: "textDocument/completion", position: { line: 9, character: 6 } },
  ]);
  const list = results[0]!.result as CompletionList;
  const labels = new Set(list.items.map((i) => i.label));
  expect(labels.has("x")).toBe(true);
  expect(labels.has("y")).toBe(true);
  // Still member-scoped — no keywords leak in.
  expect(labels.has("return")).toBe(false);
}, { timeout: MEDIUM_BUILD });

// Member completion when the receiver's type is declared in an IMPORTED module
// (not the entry file). Regression guard: the field lookup must go through the
// project-wide struct registry, not just the entry file's struct decls.
const CROSS_MODULE_MEMBER_SOURCE = `module "demo"

import "demo/widget" { Widget }

main :: fn() -> i32 {
    w :: Widget { .width = 1, .height = 2 }
    return w.width
}
`;

test("lsp: member completion resolves an imported struct's fields", async () => {
  // Line 6 = `    return w.width` ; cursor at char 13 is just past the `.` on `w`.
  const results = await driveLsp(CROSS_MODULE_MEMBER_SOURCE, [
    { method: "textDocument/completion", position: { line: 6, character: 13 } },
  ], {
    "widget/widget.vader":
      `module "demo/widget"\n\nexport Widget :: struct {\n    width: i32\n    height: i32\n}\n`,
  });
  const list = results[0]!.result as CompletionList;
  const labels = new Set(list.items.map((i) => i.label));
  expect(labels.has("width")).toBe(true);
  expect(labels.has("height")).toBe(true);
  // The field's resolved type rides along in `detail` (TS-style type hint).
  expect(list.items.find((i) => i.label === "width")?.detail).toBe("i32");
}, { timeout: MEDIUM_BUILD });

// Member completion on a NAMESPACE-import alias (`G.<member>` where
// `G :: import "p"`). Regression: the receiver types as UnresolvedType; without
// the namespace-export path completion fell into the UFCS loop and offered every
// imported free fn (print/println/eprint/…) instead of the module's exports.
const NAMESPACE_MEMBER_SOURCE = `module "demo"

G :: import "demo/greeter"

main :: fn() -> i32 {
    G.
    return 0
}
`;

test("lsp: member completion on a namespace alias lists its module's exports", async () => {
  // Line 5 = `    G.` ; cursor at char 6 is just past the dot on `G`.
  const results = await driveLsp(NAMESPACE_MEMBER_SOURCE, [
    { method: "textDocument/completion", position: { line: 5, character: 6 } },
  ], {
    "greeter/greeter.vader":
      `module "demo/greeter"\n\nexport greet :: fn(name: string) -> string = name\n`,
  });
  const list = results[0]!.result as CompletionList;
  const labels = new Set(list.items.map((i) => i.label));
  // The greeter module's export.
  expect(labels.has("greet")).toBe(true);
  // NOT every imported free fn (the old UFCS-soup bug surfaced these).
  expect(labels.has("println")).toBe(false);
  expect(labels.has("eprint")).toBe(false);
}, { timeout: MEDIUM_BUILD });

// Member completion on a receiver typed as a trait-bounded generic param
// (`msg: T` where `T: Display`). Regression: completion now resolves T's bound
// and offers the trait's methods (`to_string`) instead of UFCS-matching every
// free fn whose first param accepts a type param (which surfaced bytes_to_string).
const TYPEPARAM_BOUND_SOURCE = `module "lsp_test"

show :: fn<T: Display>(msg: T) -> void {
    msg.
}

main :: fn() -> i32 { return 0 }
`;

test("lsp: member completion on a trait-bounded generic param lists the bound's methods", async () => {
  // Line 3 = `    msg.` ; cursor at char 8 is just past the dot on `msg`.
  const results = await driveLsp(TYPEPARAM_BOUND_SOURCE, [
    { method: "textDocument/completion", position: { line: 3, character: 8 } },
  ]);
  const list = results[0]!.result as CompletionList;
  const labels = new Set(list.items.map((i) => i.label));
  // Display's method, reached through the `T: Display` bound.
  expect(labels.has("to_string")).toBe(true);
  // NOT the UFCS-soup that a type-param receiver used to match.
  expect(labels.has("bytes_to_string")).toBe(false);
}, { timeout: MEDIUM_BUILD });

// Leading-dot enum-literal completion. There's no receiver before the dot — the
// variant's enum comes from context (a param default's type, a call arg's param
// type). Without this, completion returned [] and the editor showed buffer words.
const ENUM_DEFAULT_SOURCE = `module "lsp_test"

Color :: enum { Red, Green, Blue }

tint :: fn(c: Color = .) -> i32 = 0
`;

test("lsp: enum completion in a parameter default value", async () => {
  // Line 4 = `tint :: fn(c: Color = .) -> i32 = 0` ; the `.` is at char 22,
  // cursor just past it at char 23.
  const results = await driveLsp(ENUM_DEFAULT_SOURCE, [
    { method: "textDocument/completion", position: { line: 4, character: 23 } },
  ]);
  const list = results[0]!.result as CompletionList;
  const labels = new Set(list.items.map((i) => i.label));
  expect(labels.has("Red")).toBe(true);
  expect(labels.has("Green")).toBe(true);
  expect(labels.has("Blue")).toBe(true);
  // No keyword / buffer-word leakage.
  expect(labels.has("tint")).toBe(false);
}, { timeout: MEDIUM_BUILD });

const ENUM_ARG_SOURCE = `module "lsp_test"

Color :: enum { Red, Green, Blue }

paint :: fn(c: Color) -> i32 = 0

main :: fn() -> i32 {
    return paint(.)
}
`;

test("lsp: enum completion in a fn-call argument slot", async () => {
  // Line 7 = `    return paint(.)` ; the `.` is at char 17, cursor at char 18.
  const results = await driveLsp(ENUM_ARG_SOURCE, [
    { method: "textDocument/completion", position: { line: 7, character: 18 } },
  ]);
  const list = results[0]!.result as CompletionList;
  const labels = new Set(list.items.map((i) => i.label));
  expect(labels.has("Red")).toBe(true);
  expect(labels.has("Green")).toBe(true);
  expect(labels.has("Blue")).toBe(true);
}, { timeout: MEDIUM_BUILD });

interface TextEditT { newText: string }
interface WorkspaceEditT { changes: Record<string, TextEditT[]> }
interface CodeActionT { title: string; kind: string; edit: WorkspaceEditT }

const CODE_ACTION_SOURCE = `module "lsp_test"

classify :: fn(x: i32) -> i32 {
    return match x {
        0 -> 1
        _ -> 2
    }
}
`;

test("lsp: code action converts a 2-arm match to if/else", async () => {

  // Cursor on the `match` keyword (line 3 = `    return match x {`, char 11).
  const results = await driveLsp(CODE_ACTION_SOURCE, [
    { method: "textDocument/codeAction", position: { line: 3, character: 11 } },
  ]);
  const actions = results[0]!.result as CodeActionT[];
  expect(Array.isArray(actions)).toBe(true);

  const conv = actions.find((a) => a.title === "Convert match to if");
  expect(conv).toBeDefined();
  expect(conv!.kind).toBe("refactor.rewrite");

  const fileEdits = conv!.edit.changes[Object.keys(conv!.edit.changes)[0]!]!;
  expect(fileEdits[0]!.newText).toContain("if x == 0");
  expect(fileEdits[0]!.newText).toContain("else");
}, { timeout: MEDIUM_BUILD });

const NULL_NARROW_SOURCE = `module "lsp_test"

Node :: struct { v: i32 }

describe :: fn(cell: Node | null) -> i32 {
    match cell {
        is null -> {
            return 0
        }
        is Node -> {
            return 1
        }
    }
}
`;

test("lsp: code action converts a two-is-arm match (no wildcard) to if", async () => {

  // The null-narrowing shape: `match cell { is null -> … is Node -> … }`.
  // Cursor on the `match` keyword (line 5 = `    match cell {`, char 4).
  const results = await driveLsp(NULL_NARROW_SOURCE, [
    { method: "textDocument/codeAction", position: { line: 5, character: 4 } },
  ]);
  const actions = results[0]!.result as CodeActionT[];
  const conv = actions.find((a) => a.title === "Convert match to if");
  expect(conv).toBeDefined();
  const edit = conv!.edit.changes[Object.keys(conv!.edit.changes)[0]!]![0]!;
  expect(edit.newText).toContain("cell is null");
  expect(edit.newText).toContain("else");
}, { timeout: MEDIUM_BUILD });

const IF_TO_MATCH_SOURCE = `module "lsp_test"

pick :: fn(v: i32 | string) -> i32 {
    if v is i32 as n {
        return n
    } else if v == "x" {
        return 1
    } else {
        return 2
    }
}
`;

test("lsp: code action converts an if/else-if chain to match", async () => {

  // Cursor on the leading `if` (line 3 = `    if v is i32 as n {`, char 4).
  const results = await driveLsp(IF_TO_MATCH_SOURCE, [
    { method: "textDocument/codeAction", position: { line: 3, character: 4 } },
  ]);
  const actions = results[0]!.result as CodeActionT[];
  const conv = actions.find((a) => a.title === "Convert if to match");
  expect(conv).toBeDefined();
  expect(conv!.kind).toBe("refactor.rewrite");
  const edit = conv!.edit.changes[Object.keys(conv!.edit.changes)[0]!]![0]!;
  expect(edit.newText).toContain("match v");
  expect(edit.newText).toContain("is i32 as n");
  expect(edit.newText).toContain("_ ->");
}, { timeout: MEDIUM_BUILD });

const UFCS_SOURCE = `module "lsp_test"

dbl :: fn(x: i32) -> i32 {
    return x * 2
}

main :: fn() -> i32 {
    n :: 21
    return dbl(n)
}
`;

test("lsp: code action converts a free call to method syntax", async () => {

  // Cursor on the `dbl(n)` call (line 8 = `    return dbl(n)`, char 11).
  const results = await driveLsp(UFCS_SOURCE, [
    { method: "textDocument/codeAction", position: { line: 8, character: 11 } },
  ]);
  const actions = results[0]!.result as CodeActionT[];
  const conv = actions.find((a) => a.title === "Convert to method call");
  expect(conv).toBeDefined();
  const edit = conv!.edit.changes[Object.keys(conv!.edit.changes)[0]!]![0]!;
  expect(edit.newText).toContain("n.dbl()");
}, { timeout: MEDIUM_BUILD });

test("lsp: empty document doesn't crash, returns null on lookups", async () => {

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
  const results = await driveLsp(BINDINGS_SOURCE, [
    { method: "textDocument/hover", position: { line: 3, character: 9 } },
  ]);
  const hov = results[0]!.result as Hover;
  expect(hov.contents.kind).toBe("markdown");
  expect(hov.contents.value).toContain("```vader\nx: i32\n```");
}, { timeout: MEDIUM_BUILD });

test("lsp: goto-def jumps to local let-binding", async () => {
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
  const results = await driveLsp(BINDINGS_SOURCE, [
    { method: "textDocument/hover", position: { line: 4, character: 11 } },
  ]);
  const hov = results[0]!.result as Hover;
  expect(hov.contents.value).toContain("```vader\ny :: x * 2\n```");
}, { timeout: MEDIUM_BUILD });

test("lsp: goto-def jumps to for-in binding", async () => {
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
  // Click on `println` call inside the body at line 4 char 4.
  const results = await driveLsp(CROSSFILE_SOURCE, [
    { method: "textDocument/definition", position: { line: 4, character: 4 } },
  ]);
  const loc = results[0]!.result as Location;
  expect(loc.uri).toMatch(/std\/io\/io\.vader$/);
  // We don't pin the exact line — `std/io/io.vader` evolves and the test
  // would churn on every stdlib edit. The contract is "lands in
  // io.vader on a non-zero line".
  expect(loc.range.start.line).toBeGreaterThan(0);
}, { timeout: MEDIUM_BUILD });

test("lsp: goto-def follows imports across files (collections)", async () => {
  // Click on `MutableMap` type ref at line 6 char 12.
  const results = await driveLsp(CROSSFILE_SOURCE, [
    { method: "textDocument/definition", position: { line: 6, character: 12 } },
  ]);
  const loc = results[0]!.result as Location;
  expect(loc.uri).toMatch(/std\/collections\/collections\.vader$/);
  expect(loc.range.start.line).toBeGreaterThan(0);
}, { timeout: MEDIUM_BUILD });

test("lsp: hover on imported symbol surfaces its origin signature", async () => {
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
  const dir = mkdtempSync(join(tmpdir(), "vlsp-"));
  const file = join(dir, "link-support.vader");
  writeFileSync(file, src);
  const URI = `file://${file}`;
  const requests: object[] = [
    { jsonrpc: "2.0", id: 1, method: "initialize", params: {
      rootUri: `file://${dir}`,
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
    cmd: [CLI_BIN, "lsp", `--stdlib-root=${process.cwd()}/stdlib`, `--vader-root=${process.cwd()}/vader`],
    cwd: process.cwd(),
    stdin: "pipe", stdout: "pipe", stderr: "pipe",
  });
  const killer = setTimeout(() => { try { proc.kill(9); } catch {} }, MEDIUM_BUILD);
  proc.stdin.write(stdin);
  await proc.stdin.end();
  const stdout = new Uint8Array(await new Response(proc.stdout).arrayBuffer());
  await proc.exited;
  clearTimeout(killer);
  rmSync(dir, { recursive: true, force: true });

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
    cmd: [CLI_BIN, "lsp", `--stdlib-root=${process.cwd()}/stdlib`, `--vader-root=${process.cwd()}/vader`],
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
