// tests/hook_driver: a language-server session over a project its
// `build.vader` describes. The rest of the build driver is tested by the `hook`
// family of the test runner and by tools/cli_tests (driver, bundle, library,
// new); this one waits for a client of the server in Vader.

import { test, expect, afterAll } from "bun:test";
import { rmSync, writeFileSync, readFileSync, mkdirSync, mkdtempSync } from "node:fs";
import { join, resolve } from "node:path";
import { tmpdir } from "node:os";
import { ensureCliBuilt, CLI_BIN, HEAVY_BUILD, hermeticEnv, spawnCapture } from "./cli-bin.ts";
import { pathToUri } from "./lsp-uri.ts";
import { encodeFrame, readFrames } from "./rpc-frames.ts";

ensureCliBuilt();

// The toolchain a staged project builds against.
const TOOLCHAIN_ENV = { VADER_HOME: resolve(".") };

const staged: string[] = [];

afterAll(() => {
  for (const dir of staged) {
    rmSync(dir, { recursive: true, force: true });
  }
});

// One language-server session driven message by message: the server answers a
// driven project on its own schedule, which a write-everything-then-read client
// cannot wait for.
function lspSession(cwd: string) {
  const proc = Bun.spawn({
    cmd: [resolve(CLI_BIN), "lsp"],
    cwd,
    env: hermeticEnv(TOOLCHAIN_ENV),
    stdin: "pipe",
    stdout: "pipe",
    stderr: "ignore",
  });
  const frames = readFrames(proc.stdout);
  const send = (message: object) => {
    proc.stdin.write(encodeFrame(message));
    proc.stdin.flush();
  };
  // The next message the server sends, or null once it closed its output.
  const next = async (): Promise<any> => (await frames.next()).value ?? null;
  return { proc, send, next };
}

test("the language server reads the search roots a driver declares", async () => {
  // REASON: a whole language-server session over a driven project. The server
  // has the driver describe itself through `vader info --json`, without waiting
  // on it and without ever compiling it, and holds the document's diagnostics
  // back until the roots are known: the import of a module under a root the
  // driver declares never shows as unresolved.
  {
    const dir = mkdtempSync(`${tmpdir()}/vader-lsp-driven-`);
    staged.push(dir);
    mkdirSync(join(dir, "src"));
    mkdirSync(join(dir, "vendor/greet"), { recursive: true });
    writeFileSync(join(dir, "build.vader"), [
      'module "build"', "", 'import "std/console"', 'import "toolchain/build"', "",
      "build :: fn(args: string[]) -> i32 {",
      "    ctx :: new_build_context(args)",
      '    ctx.include_paths.push("vendor")',
      '    ctx.add_entry("app", "src/main.vader")',
      "    code :: ctx.emit_native()",
      "    if code == 0 && ctx.mode() == .Build {",
      '        println("packaged")',
      "    }",
      "    return code",
      "}", "",
    ].join("\n"));
    const main = 'module "src"\n\nimport "greet"\nimport "std/console"\n\nmain :: fn() -> i32 {\n    println(greeting())\n    return 0\n}\n';
    writeFileSync(join(dir, "src/main.vader"), main);
    writeFileSync(join(dir, "vendor/greet/greet.vader"), 'module "greet"\n\nexport greeting :: fn() -> string = "hi"\n');

    // The server never compiles the driver: a build typed in a terminal does,
    // as this `info` does here. Run to describe, the driver skips its packaging.
    const compiled = await spawnCapture(["info", "."], { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: HEAVY_BUILD });
    expect(compiled.exit).toBe(0);
    expect(compiled.stderr).not.toContain("packaged");

    const lsp = lspSession(dir);
    try {
      const uri = pathToUri(join(dir, "src/main.vader"));
      lsp.send({ jsonrpc: "2.0", id: 1, method: "initialize", params: { rootUri: pathToUri(dir), capabilities: {} } });
      lsp.send({ jsonrpc: "2.0", method: "initialized", params: {} });
      lsp.send({
        jsonrpc: "2.0", method: "textDocument/didOpen",
        params: { textDocument: { uri, languageId: "vader", version: 1, text: main } },
      });
      // The next diagnostics the server publishes for the document.
      const nextPublished = async (): Promise<string | null> => {
        for (;;) {
          const message = await lsp.next();
          if (message === null) return null;
          if (message.method === "textDocument/publishDiagnostics" && message.params.uri === uri) {
            return JSON.stringify(message.params.diagnostics);
          }
        }
      };
      const first = await nextPublished();

      // A saved `build.vader` that no longer declares the root, compiled again
      // from a terminal: the project describes itself again, and the import no
      // longer resolves.
      const driver = join(dir, "build.vader");
      writeFileSync(driver, readFileSync(driver, "utf8").replace('    ctx.include_paths.push("vendor")\n', ""));
      const recompiled = await spawnCapture(["info", "."], { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: HEAVY_BUILD });
      expect(recompiled.exit).toBe(0);
      lsp.send({ jsonrpc: "2.0", method: "textDocument/didSave", params: { textDocument: { uri: pathToUri(driver) } } });
      const second = await nextPublished();

      lsp.send({ jsonrpc: "2.0", id: 2, method: "shutdown", params: null });
      lsp.send({ jsonrpc: "2.0", method: "exit", params: null });
      await lsp.proc.exited;

      expect(first).not.toBeNull();
      expect(first).not.toContain("R2001");
      expect(first).not.toContain("R2006");
      expect(second).toContain("R2001");
    } finally {
      // A failed assertion or a hang must not leave the server running.
      lsp.proc.kill();
    }
  }
}, HEAVY_BUILD);
