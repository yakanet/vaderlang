import { existsSync, mkdirSync, readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { join } from "node:path";

import { runCli } from "./cli-bin.ts";

// The native, self-hosted Vader CLI (`./build/vader dump --stage=…`) is the
// snapshot oracle for every pipeline stage. The legacy TypeScript pipeline that
// once produced these dumps in-process was removed with `src/` (§2.8) — its
// final state is preserved under the `v0.0.0-pre-mvp-final-ts` tag.

export const MAIN_FILE = "_main.vader";
export const CONFIG_FILE = "_config.json";

export const VM_ERROR_PREFIXES = ["# pipeline error", "# compile errors", "# no main function", "# runtime error"] as const;

type PhaseName = "lexer" | "parser" | "resolver" | "typecheck" | "comptime" | "lower" | "cfg" | "bytecode";

export interface TestConfig {
  readonly phases?: readonly PhaseName[];
  /** Modules rendered by the module-filtered dumps (typecheck / comptime /
   *  lower), passed through as `--module`. Defaults to the entry module's
   *  subtree when absent — set this only for a snippet whose modules fall
   *  outside the entry module's display-path prefix. */
  readonly modules?: readonly string[];
}

export function loadConfig(dir: string): TestConfig {
  const configPath = join(dir, CONFIG_FILE);
  if (!existsSync(configPath)) return {};
  try {
    return JSON.parse(readFileSync(configPath, "utf8")) as TestConfig;
  } catch {
    return {};
  }
}

export interface Scenario {
  readonly name: string;
  readonly dir: string;
  readonly mainPath: string;
  readonly source: string;
  /** Adjacent `*.c` files (excluding the auto-generated `native.c`) that
   *  the native runner pre-compiles to `.o` and passes through to the
   *  cc invocation via `--ldflags`. Used by `@extern` end-to-end
   *  snippets that wire a Vader signature to a foreign symbol. */
  readonly helperCFiles: readonly string[];
}

const UPDATE = process.env["UPDATE_SNAPSHOTS"] === "1";

export function errMsg(e: unknown): string {
  return e instanceof Error ? e.message : String(e);
}

export function formatRun(stdout: string, stderr: string, exit: number): string {
  const parts: string[] = [];
  if (stdout.length > 0) parts.push("# stdout\n" + stdout);
  if (stderr.length > 0) parts.push("# stderr\n" + stderr);
  parts.push(`# exit\n${exit}\n`);
  return parts.join("");
}

export function listSnippets(snippetsDir: string): Scenario[] {
  const out: Scenario[] = [];
  let entries: string[];
  try { entries = readdirSync(snippetsDir); } catch { return []; }
  for (const name of entries) {
    const dir = join(snippetsDir, name);
    if (!statSync(dir).isDirectory()) continue;
    const mainPath = join(dir, MAIN_FILE);
    let source: string;
    try { source = readFileSync(mainPath, "utf8"); } catch { continue; }
    // `native.c` is the c-emit output written by `tests/native.test.ts` ;
    // `_main.c` is the c-emit output written by a `vader build` invocation
    // on the snippet (left behind when a dev ran the CLI directly on a
    // snippet). Neither defines `@extern` symbols, so neither should
    // count as a host-fn helper — anything else `.c` in the snippet
    // directory is a user helper for an `@extern` test.
    const helperCFiles = readdirSync(dir)
      .filter((f) => f.endsWith(".c") && f !== "native.c" && f !== "_main.c")
      .map((f) => join(dir, f))
      .sort();
    out.push({ name, dir, mainPath, source, helperCFiles });
  }
  out.sort((a, b) => (a.name < b.name ? -1 : 1));
  return out;
}

interface SnapshotResult {
  readonly ok: boolean;
  readonly expected: string | null;
  readonly snapPath: string;
}

/**
 * Compare an actual dump against a `.snap` file in the scenario dir.
 * Writes the snap if it doesn't exist or if `UPDATE_SNAPSHOTS=1`.
 */
export function snapshotEquals(scenarioDir: string, snapName: string, actual: string): SnapshotResult {
  if (!existsSync(scenarioDir)) mkdirSync(scenarioDir, { recursive: true });
  const snapPath = join(scenarioDir, snapName);

  if (!existsSync(snapPath)) {
    if (UPDATE) {
      writeFileSync(snapPath, actual);
      return { ok: true, expected: actual, snapPath };
    }
    return { ok: false, expected: null, snapPath };
  }

  const expected = readFileSync(snapPath, "utf8");
  if (expected === actual) return { ok: true, expected, snapPath };

  if (UPDATE) {
    writeFileSync(snapPath, actual);
    return { ok: true, expected: actual, snapPath };
  }

  return { ok: false, expected, snapPath };
}

// ----------------------------------------------------------- ViaVader dumps

// Each `dump*ViaVader` shells out (via `cli-bin.ts::runCli`) to
// `./build/vader dump --stage=<S> <file>`, the self-hosted compiler being the
// snapshot oracle for every stage.

// Extra GC arenas for the one snippet that needs them : under the strict
// resolver the typecheck stage loads the full transitive closure of every
// visited module, which the default young/old can't hold for the heaviest
// cross-module entry (`namespace_alias_dedupe` walks the full `vader/parser`
// closure). Scope the bump to that snippet so we don't pay the GC cost (and
// OOM risk under `--parallel`) on every spawn. `runCli` merges these over
// `process.env`, so only the overrides live here.
const SLOW_TYPECHECK_SNIPPETS = new Set(["namespace_alias_dedupe"]);
const SLOW_TYPECHECK_ENV: Record<string, string> = {
  VADER_GC_YOUNG_BYTES: String(16 * 1024 * 1024),
  VADER_GC_OLD_BYTES:   String(128 * 1024 * 1024),
};

function envForSnippet(entryPath: string): Record<string, string> | undefined {
  const name = entryPath.split("/").slice(-2, -1)[0] ?? "";
  return SLOW_TYPECHECK_SNIPPETS.has(name) ? SLOW_TYPECHECK_ENV : undefined;
}

export async function dumpTypecheckViaVader(_source: string, entryPath: string, modules?: readonly string[]): Promise<string> {
  return runVaderDump("typed-ast", entryPath, modules);
}

export async function dumpComptimeViaVader(_source: string, entryPath: string, modules?: readonly string[]): Promise<string> {
  return runVaderDump("evaluated-ast", entryPath, modules);
}

export async function dumpLexerViaVader(_source: string, entryPath: string, _modules?: readonly string[]): Promise<string> {
  return runVaderDump("lexer", entryPath);
}

export async function dumpParserViaVader(_source: string, entryPath: string, _modules?: readonly string[]): Promise<string> {
  return runVaderDump("ast", entryPath);
}

export async function dumpLowerViaVader(_source: string, entryPath: string, modules?: readonly string[]): Promise<string> {
  return runVaderDump("lowered-ast", entryPath, modules);
}

export async function dumpBytecodeViaVader(_source: string, entryPath: string, _modules?: readonly string[]): Promise<string> {
  return runVaderDump("bytecode", entryPath);
}

// Drive `./build/vader dump --stage=<S> <file>` through the shared `runCli`
// spawn wrapper, which drains both pipes concurrently and enforces a SIGKILL
// wall-clock budget (a regressed stage can otherwise pin a CPU for hours —
// see `cli-bin.ts`). A non-zero exit is surfaced inline so snapshot diffs are
// debuggable rather than mysteriously empty.
async function runVaderDump(stage: string, entryPath: string, modules?: readonly string[]): Promise<string> {
  const args = ["dump", `--stage=${stage}`, entryPath];
  if (modules && modules.length > 0) args.push(`--module=${modules.join(",")}`);
  const { stdout, stderr, exit } = await runCli(args, envForSnippet(entryPath));
  if (exit !== 0) return `# vader CLI failed (exit ${canonicalExit(exit)})\n${stderr}${stdout}`;
  return stdout;
}

// A vader panic calls abort(). POSIX surfaces that to Bun as exit 134
// (128 + SIGABRT) — what the crash snapshots bake — while Windows/MSVCRT
// surfaces the same abort() as exit 3. Canonicalize the Windows code so a
// snippet that aborts the compiler (e.g. for_in_iter_trait's midir ICE) yields
// one portable `# vader CLI failed (exit 134)` line on every OS.
const WINDOWS_ABORT_EXIT = 3;
function canonicalExit(exit: number): number {
  return process.platform === "win32" && exit === WINDOWS_ABORT_EXIT ? 134 : exit;
}
