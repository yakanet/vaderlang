// tests/lsp_open_documents: the language server sees the documents an editor
// holds open as it sees the disk. A document never saved belongs to the module
// of its folder, a file with no `module` line is told so on itself, no request
// answers with another file's data, a file changed outside the editor
// reaches the open documents once the client reports it, an open document
// whose file is deleted leaves its module, changes batched in one
// notification leave the document at the last one, and a document is the same
// whichever way the client spells its URI.
//
// The session is driven one message at a time, since what the test sends next
// depends on what the server has already answered.

import { afterAll, expect, test } from "bun:test";
import { mkdirSync, mkdtempSync, renameSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

import { CLI_BIN, MEDIUM_BUILD, ensureCliBuilt, hermeticEnv } from "./cli-bin.ts";
import { pathToUri } from "./lsp-uri.ts";
import { encodeFrame, readFrames } from "./rpc-frames.ts";

ensureCliBuilt();

interface Message {
  id?: number;
  method?: string;
  params?: any;
  result?: any;
  error?: any;
}

interface Diag {
  code: string;
  range: { start: { line: number } };
}

// How long one awaited message may take: a typecheck of a small project, well
// under a second, and a debounce. Below the test's own timeout, so that a miss
// reports what did arrive.
const WAIT_MS = 15_000;

class Session {
  readonly messages: Message[] = [];
  private nextId = 1;
  private readonly proc;

  constructor(dir: string, capabilities: object) {
    this.proc = Bun.spawn({
      cmd: [CLI_BIN, "lsp", `--library-root=${process.cwd()}/lib`],
      cwd: process.cwd(), env: hermeticEnv(), stdin: "pipe", stdout: "pipe", stderr: "ignore",
    });
    void this.pump();
    this.send({ id: this.nextId++, method: "initialize", params: { rootUri: pathToUri(dir), capabilities } });
    this.send({ method: "initialized", params: {} });
  }

  private async pump(): Promise<void> {
    for await (const message of readFrames(this.proc.stdout)) {
      this.messages.push(message);
    }
  }

  send(obj: object): void {
    this.proc.stdin.write(encodeFrame({ jsonrpc: "2.0", ...obj }));
    this.proc.stdin.flush();
  }

  open(uri: string, text: string): void {
    this.send({
      method: "textDocument/didOpen",
      params: { textDocument: { uri, languageId: "vader", version: 1, text } },
    });
  }

  // The first message from position `from` on that `matches` accepts.
  async waitFor(matches: (m: Message) => boolean, from = 0): Promise<Message> {
    const deadline = Date.now() + WAIT_MS;
    while (Date.now() < deadline) {
      const found = this.messages.slice(from).find(matches);
      if (found !== undefined) {
        return found;
      }
      await Bun.sleep(10);
    }
    throw new Error(`no matching message; received:\n${JSON.stringify(this.messages, null, 1)}`);
  }

  async request(method: string, params: object): Promise<any> {
    const id = this.nextId++;
    this.send({ id, method, params });
    return (await this.waitFor(m => m.id === id && m.method === undefined)).result;
  }

  // The diagnostics of the first publication for `uri` from position `from` on.
  async diagnosticsOf(uri: string, from = 0): Promise<Diag[]> {
    const published = await this.waitFor(
      m => m.method === "textDocument/publishDiagnostics" && m.params.uri === uri, from);
    return published.params.diagnostics;
  }

  async close(): Promise<void> {
    await this.request("shutdown", {});
    this.send({ method: "exit" });
    this.proc.stdin.end();
    await this.proc.exited;
  }
}

const dirs: string[] = [];

afterAll(() => {
  for (const dir of dirs) {
    rmSync(dir, { recursive: true, force: true });
  }
});

function project(files: Record<string, string>): string {
  const dir = mkdtempSync(join(tmpdir(), "vlsp-open-"));
  dirs.push(dir);
  for (const [name, text] of Object.entries(files)) {
    writeFileSync(join(dir, name), text);
  }
  return dir;
}

const errors = (diags: Diag[]) => diags.filter(d => d.code.startsWith("R") || d.code.startsWith("T"));

const SIBLING = 'module "demo"\n\nANSWER :: 40 + 2\n';

const WHOLE_FILE = { start: { line: 0, character: 0 }, end: { line: 100, character: 0 } };

test("an open document never saved belongs to the module of its folder", async () => {
  // A typed constant: the sibling has no hint of its own to stand in for b's.
  const dir = project({ "a.vader": 'module "demo"\n\nANSWER: i64: 42\n' });
  const session = new Session(dir, {});
  const uri = pathToUri(join(dir, "b.vader"));
  session.open(uri, 'module "demo"\n\nexport TWICE :: ANSWER * 2\n');
  expect(errors(await session.diagnosticsOf(uri))).toEqual([]);
  const hints = await session.request("textDocument/inlayHint", { textDocument: { uri }, range: WHOLE_FILE });
  expect(hints.map((h: any) => [h.label, h.position.line])).toEqual([["i64", 2]]);
  await session.close();
}, MEDIUM_BUILD);

test("a file with no module line is told so on itself, and shows no other file's hints", async () => {
  // Empty on the disk, as an editor creates a file before its first save.
  const dir = project({ "a.vader": SIBLING, "b.vader": "" });
  const session = new Session(dir, {});
  const uri = pathToUri(join(dir, "b.vader"));
  session.open(uri, "\nrun :: fn() -> void {}\n");
  const missing = (await session.diagnosticsOf(uri)).filter(d => d.code === "R2020");
  expect(missing.map(d => d.range.start.line)).toEqual([0]);
  expect(await session.request("textDocument/inlayHint", { textDocument: { uri }, range: WHOLE_FILE })).toEqual([]);
  await session.close();
}, MEDIUM_BUILD);

test("the server asks to watch files only when the client can register for it", async () => {
  const dir = project({ "a.vader": SIBLING });
  const watching = new Session(dir, { workspace: { didChangeWatchedFiles: { dynamicRegistration: true } } });
  const registration = await watching.waitFor(m => m.method === "client/registerCapability");
  const [watched] = registration.params.registrations;
  expect(watched.method).toBe("workspace/didChangeWatchedFiles");
  expect(watched.registerOptions.watchers.map((w: any) => w.globPattern)).toEqual(["**/*.vader", "**/vader.json"]);
  // The client's answer is a response, not a request to refuse.
  watching.send({ id: registration.id, result: null });
  await watching.close();
  expect(watching.messages.filter(m => m.id === registration.id && m.error !== undefined)).toEqual([]);

  const silent = new Session(dir, {});
  await silent.close();
  expect(silent.messages.filter(m => m.method === "client/registerCapability")).toEqual([]);
}, MEDIUM_BUILD);

test("a sibling written outside the editor reaches the open document once reported", async () => {
  const dir = project({ "a.vader": 'module "demo"\n', "b.vader": "" });
  const session = new Session(dir, {});
  const uri = pathToUri(join(dir, "b.vader"));
  session.open(uri, 'module "demo"\n\nexport TWICE :: ANSWER * 2\n');
  expect(errors(await session.diagnosticsOf(uri)).map(d => d.code)).toContain("R2006");
  writeFileSync(join(dir, "a.vader"), SIBLING);
  const reported = session.messages.length;
  session.send({
    method: "workspace/didChangeWatchedFiles",
    params: { changes: [{ uri: pathToUri(join(dir, "a.vader")), type: 2 }] },
  });
  expect(errors(await session.diagnosticsOf(uri, reported))).toEqual([]);
  await session.close();
}, MEDIUM_BUILD);

test("a document renamed outside the editor leaves its module under the old name", async () => {
  const dir = project({ "old.vader": SIBLING });
  const session = new Session(dir, {});
  const oldUri = pathToUri(join(dir, "old.vader"));
  const newUri = pathToUri(join(dir, "new.vader"));
  session.open(oldUri, SIBLING);
  expect(errors(await session.diagnosticsOf(oldUri))).toEqual([]);
  // As `git mv` reaches an editor that keeps the old document open: a deletion
  // and a creation, and no didClose.
  renameSync(join(dir, "old.vader"), join(dir, "new.vader"));
  const renamed = session.messages.length;
  session.send({
    method: "workspace/didChangeWatchedFiles",
    params: { changes: [{ uri: oldUri, type: 3 }, { uri: newUri, type: 1 }] },
  });
  session.open(newUri, SIBLING);
  expect(await session.diagnosticsOf(oldUri, renamed)).toEqual([]);
  expect(errors(await session.diagnosticsOf(newUri, renamed))).toEqual([]);
  await session.close();
}, MEDIUM_BUILD);

test("a deletion reported for a file still on the disk keeps the open document", async () => {
  // A save that renames a copy over the file can be reported as a deletion.
  const dir = project({ "a.vader": 'module "demo"\n\nANSWER: i64: 42\n', "b.vader": "" });
  const session = new Session(dir, {});
  const uri = pathToUri(join(dir, "b.vader"));
  session.open(uri, 'module "demo"\n\nexport TWICE :: ANSWER * 2\n');
  expect(errors(await session.diagnosticsOf(uri))).toEqual([]);
  session.send({ method: "workspace/didChangeWatchedFiles", params: { changes: [{ uri, type: 3 }] } });
  const hints = await session.request("textDocument/inlayHint", { textDocument: { uri }, range: WHOLE_FILE });
  expect(hints.map((h: any) => [h.label, h.position.line])).toEqual([["i64", 2]]);
  await session.close();
}, MEDIUM_BUILD);

test("changes batched in one notification leave the document at the last one", async () => {
  const dir = project({ "a.vader": SIBLING });
  const session = new Session(dir, {});
  const uri = pathToUri(join(dir, "b.vader"));
  session.open(uri, 'module "demo"\n\nTWICE :: ANSWER * 2\n');
  expect(errors(await session.diagnosticsOf(uri))).toEqual([]);
  const changed = session.messages.length;
  session.send({
    method: "textDocument/didChange",
    params: {
      textDocument: { uri, version: 2 },
      contentChanges: [
        { text: 'module "demo"\n\nTWICE :: MISSING * 2\n' },
        { text: 'module "demo"\n\nTWICE :: ANSWER * 2\n\nTHRICE :: GONE * 3\n' },
      ],
    },
  });
  const unresolved = errors(await session.diagnosticsOf(uri, changed));
  expect(unresolved.map(d => [d.code, d.range.start.line])).toEqual([["R2006", 4]]);
  await session.close();
}, MEDIUM_BUILD);

test("an open document is found again whichever way the client spells its URI", async () => {
  // A folder whose name the server's URIs and VS Code's spell apart: VS Code
  // escapes every byte but the unreserved ones, so `+` reaches the server as
  // `%2B`, where the server's own URI keeps it bare.
  const dir = join(project({}), "a+b c");
  mkdirSync(dir);
  writeFileSync(join(dir, "a.vader"), 'module "demo"\n');
  writeFileSync(join(dir, "b.vader"), "");
  const session = new Session(dir, {});
  const spelled = (name: string) => {
    let path = join(dir, name).replace(/\\/g, "/");
    // A Windows drive path, `C:/...`, takes the `/` a URI path opens with.
    if (!path.startsWith("/")) {
      path = `/${path}`;
    }
    return `file://${path.split("/").map(encodeURIComponent).join("/")}`;
  };
  // The sibling's declaration exists only in its unsaved text.
  session.open(spelled("a.vader"), SIBLING);
  const uri = spelled("b.vader");
  session.open(uri, 'module "demo"\n\nexport TWICE :: ANSWER * 2\n');
  expect(errors(await session.diagnosticsOf(pathToUri(join(dir, "b.vader"))))).toEqual([]);
  const found = await session.request("textDocument/definition", {
    textDocument: { uri }, position: { line: 2, character: 17 },
  });
  expect([found?.uri, found?.range.start.line]).toEqual([pathToUri(join(dir, "a.vader")), 2]);
  await session.close();
}, MEDIUM_BUILD);
