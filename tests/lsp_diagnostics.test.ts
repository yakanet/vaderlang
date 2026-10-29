// LSP diagnostics end-to-end: verifies the server pushes, as
// `textDocument/publishDiagnostics` on didOpen, the dead-code lints W0007 (a
// private declaration) and the opt-in project-wide `unused-export` (W0012),
// scoped to the open document by the per-file filter and faded, and what the
// comptime tree-walk reports. Kept separate from lsp.test.ts (which drives
// request/response queries) because these assert on server-INITIATED
// notifications, which that harness discards.

import { test, expect } from "bun:test";
import { mkdtempSync, writeFileSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

import { MEDIUM_BUILD, ensureCliBuilt } from "./cli-bin.ts";
import { pathToUri } from "./lsp-uri.ts";
import { exchangeFrames } from "./rpc-frames.ts";

ensureCliBuilt();

interface Diag {
  code: string;
  message: string;
  severity: number;
  range: { start: { line: number; character: number } };
  tags?: number[];
}

// Spawn `vader lsp`, open `source` as a document, and return the diagnostics of
// the last `publishDiagnostics` notification the server pushes for it.
async function diagnosticsFor(source: string): Promise<Diag[]> {
  const dir = mkdtempSync(join(tmpdir(), "vlspdiag-"));
  const file = join(dir, "lint-me.vader");
  writeFileSync(file, source);
  const uri = pathToUri(file);
  const requests: object[] = [
    { jsonrpc: "2.0", id: 1, method: "initialize", params: { rootUri: pathToUri(dir), capabilities: {} } },
    { jsonrpc: "2.0", method: "initialized", params: {} },
    { jsonrpc: "2.0", method: "textDocument/didOpen",
      params: { textDocument: { uri, languageId: "vader", version: 1, text: source } } },
    { jsonrpc: "2.0", id: 999, method: "shutdown", params: null },
    { jsonrpc: "2.0", method: "exit", params: null },
  ];
  const messages = await exchangeFrames(
    ["lsp", `--library-root=${process.cwd()}/lib`], requests, MEDIUM_BUILD,
  );
  rmSync(dir, { recursive: true, force: true });

  const latest = messages.findLast(
    (m) => m.method === "textDocument/publishDiagnostics" && m.params.uri === uri,
  );
  return latest?.params.diagnostics ?? [];
}

test("LSP surfaces W0012 (unused-export) on a dead exported fn, faded", async () => {
  const source = [
    `module "snippet"`,
    `export used :: fn() -> i32 = 1`,
    `export orphan :: fn() -> i32 = 2`,
    `main :: fn() -> i32 = used()`,
    ``,
  ].join("\n");
  const diags = await diagnosticsFor(source);
  const w0012 = diags.filter(d => d.code === "W0012");
  // Exactly one W0012, and it names `orphan`, so `used` (reached from main)
  // is not flagged. (The message "`orphan` is never used" contains the word
  // "used", so assert on the count + the flagged name, not a substring.)
  expect(w0012.length).toBe(1);
  expect(w0012[0]!.message).toContain("orphan");
  expect(w0012[0]!.severity).toBe(2);        // Warning
  expect(w0012[0]!.tags).toEqual([1]);       // Unnecessary → rendered faded
}, MEDIUM_BUILD);

test("LSP emits no W0012 when every export is reached", async () => {
  const source = [
    `module "snippet"`,
    `export twice :: fn(n: i32) -> i32 = n * 2`,
    `main :: fn() -> i32 = twice(21)`,
    ``,
  ].join("\n");
  const diags = await diagnosticsFor(source);
  expect(diags.some(d => d.code === "W0012")).toBe(false);
}, MEDIUM_BUILD);

test("LSP surfaces W0007 (dead code) on an unused private fn, faded", async () => {
  const source = [
    `module "snippet"`,
    `helper :: fn() -> i32 = 3`,
    `main :: fn() -> i32 = 0`,
    ``,
  ].join("\n");
  const diags = await diagnosticsFor(source);
  const w0007 = diags.filter(d => d.code === "W0007");
  expect(w0007.length).toBe(1);
  expect(w0007[0]!.message).toContain("helper");
  expect(w0007[0]!.severity).toBe(2);        // Warning
  expect(w0007[0]!.tags).toEqual([1]);       // Unnecessary → rendered faded
}, MEDIUM_BUILD);

test("LSP surfaces a comptime division by zero (C4005) and a cycle (C4009)", async () => {
  const source = [
    `module "snippet"`,
    `@comptime`,
    `export BOOM :: 10 / 0`,
    `@comptime`,
    `export A: i32: B + 1`,
    `@comptime`,
    `export B: i32: A + 1`,
    ``,
  ].join("\n");
  const codes = (await diagnosticsFor(source)).map(d => d.code).filter(c => c.startsWith("C"));
  expect(codes.sort()).toEqual(["C4005", "C4009"]);
}, MEDIUM_BUILD);

test("LSP publishes each diagnostic once, as the CLI prints it", async () => {
  // An `implements` naming an unknown type reports some of its spans twice.
  const source = [
    `module "snippet"`,
    `Vector2 implements Add<Vector2> -> Vector2 { .x = self.x + other.x }`,
    ``,
  ].join("\n");
  const diags = await diagnosticsFor(source);
  const keys = diags.map(d => `${d.code}@${d.range.start.line}:${d.range.start.character}`);
  expect(keys.length).toBeGreaterThan(0);
  expect(new Set(keys).size).toBe(keys.length);
}, MEDIUM_BUILD);
