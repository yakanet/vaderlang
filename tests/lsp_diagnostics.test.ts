// LSP diagnostics end-to-end — verifies the server pushes the opt-in
// project-wide `unused-export` lint (W0012) as `textDocument/publishDiagnostics`
// on didOpen, scoped to the open document by the per-file filter. Kept separate
// from lsp.test.ts (which drives request/response queries) because these assert
// on server-INITIATED notifications, which that harness discards.

import { test, expect } from "bun:test";
import { mkdtempSync, writeFileSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

import { CLI_BIN, MEDIUM_BUILD, ensureCliBuilt } from "./cli-bin.ts";

ensureCliBuilt();

interface Diag {
  code: string;
  message: string;
  severity: number;
  tags?: number[];
}

function frame(obj: object): Uint8Array {
  const body = new TextEncoder().encode(JSON.stringify(obj));
  const header = new TextEncoder().encode(`Content-Length: ${body.byteLength}\r\n\r\n`);
  const out = new Uint8Array(header.byteLength + body.byteLength);
  out.set(header, 0);
  out.set(body, header.byteLength);
  return out;
}

function sepIndex(buf: Uint8Array): number {
  for (let i = 0; i + 3 < buf.byteLength; i++) {
    if (buf[i] === 0x0d && buf[i + 1] === 0x0a && buf[i + 2] === 0x0d && buf[i + 3] === 0x0a) return i;
  }
  return -1;
}

// Mirror the server's `path_to_uri` (vader/lsp/protocol/uri.vader): forward-slash
// the path, and give a Windows drive path (`C:\...`) the extra leading slash so it
// becomes `file:///C:/...`. On POSIX the path already starts with `/`, so this is
// byte-identical to the old `file://${p}`. A naive `file://${p}` on Windows yields
// the malformed `file://C:\...`, which `uri_to_path` leaves with `\` separators
// while the loader normalises spans to `/` (to_posix) — so the publish filter drops
// every diagnostic and the server looks silent.
function pathToUri(p: string): string {
  const posix = p.replace(/\\/g, "/");
  return posix.startsWith("/") ? `file://${posix}` : `file:///${posix}`;
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
  const stdin = new Uint8Array(requests.reduce<number>((n, r) => n + frame(r).byteLength, 0));
  let off = 0;
  for (const r of requests) { const f = frame(r); stdin.set(f, off); off += f.byteLength; }

  const proc = Bun.spawn({
    cmd: [CLI_BIN, "lsp", `--stdlib-root=${process.cwd()}/stdlib`, `--vader-root=${process.cwd()}/vader`],
    cwd: process.cwd(), stdin: "pipe", stdout: "pipe", stderr: "pipe",
  });
  const killer = setTimeout(() => { try { proc.kill(9); } catch {} }, MEDIUM_BUILD);
  proc.stdin.write(stdin);
  await proc.stdin.end();
  const stdout = new Uint8Array(await new Response(proc.stdout).arrayBuffer());
  await proc.exited;
  clearTimeout(killer);
  rmSync(dir, { recursive: true, force: true });

  // Walk every frame, keep the latest publishDiagnostics for our uri.
  let latest: Diag[] = [];
  let cursor = 0;
  while (cursor < stdout.byteLength) {
    const view = stdout.subarray(cursor);
    const sep = sepIndex(view);
    if (sep < 0) break;
    const header = new TextDecoder().decode(view.subarray(0, sep));
    const m = /^content-length:\s*(\d+)$/im.exec(header);
    if (!m) break;
    const len = Number(m[1]);
    const bodyStart = cursor + sep + 4;
    const bodyEnd = bodyStart + len;
    if (stdout.byteLength < bodyEnd) break;
    const body = JSON.parse(new TextDecoder().decode(stdout.subarray(bodyStart, bodyEnd)));
    cursor = bodyEnd;
    if (body?.method === "textDocument/publishDiagnostics" && body?.params?.uri === uri) {
      latest = body.params.diagnostics as Diag[];
    }
  }
  return latest;
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
  // Exactly one W0012, and it names `orphan` — so `used` (reached from main)
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
