// Shared presence check + spawn wrapper for the Vader CLI native binary.
// The harness does NOT build the compiler: it asserts a prebuilt `build/vader`
// exists and is up to date vs the .vader sources, failing loudly otherwise.
// The binary is provided by `bun run build:cli`, which builds it from the
// committed C seed (see bootstrap/README.md).

import type { FileSink } from "bun";
import { beforeAll } from "bun:test";
import { statSync } from "node:fs";
import { resolve } from "node:path";
import { listVaderFiles } from "./vader-sources.ts";

// The suffix a LINKER appends to an executable name. `cc -o hello` writes
// `hello` on Unix and `hello.exe` on Windows, verified with mingw-w64: gcc
// appends it when `-o` carries no extension. Every path to a BUILT binary goes
// through `exePath`, or the assertion passes on one OS and fails on the other.
export const EXE_SUFFIX = process.platform === "win32" ? ".exe" : "";

export const exePath = (base: string) => `${base}${EXE_SUFFIX}`;

export const CLI_BIN = exePath("build/vader");

// The per-test timeout of the suite, see tests/setup.ts.
export const MEDIUM_BUILD = 30_000;

// Newest mtime across the .vader sources the compiler is built from: `vader/`
// and `lib/`.
//
// Called once per test FILE, not once per worker: bun gives each `*.test.ts` its
// own realm, so the `--preload` module is re-evaluated per file and neither a
// module-level nor a `globalThis` cache survives. Measured: 19 files × 285 stats
// ≈ 20-67 ms across a ~6 min suite, which is why there is no memoization rather
// than a cheap one.
function newestSourceMtime(): number {
  let max = 0;
  for (const p of [...listVaderFiles("vader"), ...listVaderFiles("lib")]) {
    const m = statSync(p).mtimeMs;
    if (m > max) max = m;
  }
  return max;
}

function binaryMtime(): number {
  try { return statSync(CLI_BIN).mtimeMs; } catch { return 0; }
}

// Build instructions surfaced when the binary is missing or stale. The seed
// path needs only a C compiler. The `src/`-based shortcut this used to name is
// gone: that was the TypeScript compiler, deleted when the tree started
// self-hosting from the seed, and `src/` now means something else entirely (the
// compiler's own sources inside a dist bundle).
const BUILD_HINT =
  `  bun run build                                  # 3-stage bootstrap from the committed C seed\n` +
  `  bun run build:cli                              # the same, plus a dist/ bundle\n` +
  `  # equivalently, without Bun (see bootstrap/README.md):\n` +
  `  bash bootstrap/build.sh                         # → ${CLI_BIN}`;

// Assert a prebuilt, up-to-date compiler binary is present, never build it.
// Missing or stale-vs-sources is a hard failure with rebuild instructions, so
// the suite never silently runs against a stale binary. The N test files that
// load this share one check via the global beforeAll.
export function ensureCliBuilt(): void {
  beforeAll(() => {
    const bin = binaryMtime();
    if (bin === 0) {
      throw new Error(`${CLI_BIN} not found: build the compiler first:\n${BUILD_HINT}`);
    }
    if (bin < newestSourceMtime()) {
      throw new Error(`${CLI_BIN} is stale (older than vader/ or lib/ sources): rebuild it:\n${BUILD_HINT}`);
    }
  });
}

export interface CliResult {
  stdout: string;
  stderr: string;
  exit: number;
}

// Hard wall-clock budget that survives Bun test-driver bailouts. When a
// `test()` exceeds its declared timeout the driver marks it failed but
// does NOT cancel the in-flight spawn, so a looping `build/vader run`
// can pin a CPU indefinitely (seen at 33+ h on a stuck custom_iter VM
// loop). The kill timer below makes the wrapper self-cleaning regardless
// of what the test driver does : when the budget expires we SIGKILL the
// child, its `exited` promise resolves, and the test returns.
//
// 90 s default ; the parity suites declare a 30 s test timeout so this
// is a generous margin for cold rebuilds without giving stuck VM loops
// a free pass.
const DEFAULT_CLI_TIMEOUT_MS = 90_000;

// Both pipes are drained concurrently: leaving stderr unread can deadlock
// the child once the 64 KB pipe buffer fills on a verbose trap.
export interface SpawnOptions {
  /** Binary to run. Defaults to the CLI: override for a `dist/` bundle's own
   *  `vader`, or for a binary the CLI just produced. */
  readonly bin?: string;
  /** Working directory. Load bearing for a driven build: `build.vader` is
   *  discovered relative to the INVOCATION directory, not to the binary. */
  readonly cwd?: string;
  readonly env?: Record<string, string>;
  readonly timeoutMs?: number;
  /** Bytes for the child's standard input, closed after them. */
  readonly stdin?: Uint8Array;
  /** A line for the child's standard input, written once its stdout holds the
   *  cue, then closed: for a child that must be waiting when its input comes.
   *  Not with `stdin`. */
  readonly feed?: Feed;
}

/** A line written to a child's stdin once its stdout holds `cue`. */
export interface Feed {
  readonly cue: string;
  readonly line: string;
}

// The `stdin` option of a spawn for `opts`: a pipe when the input waits for a cue.
function stdinOption(opts: SpawnOptions): { stdin?: Uint8Array | "pipe" } {
  if (opts.feed !== undefined) return { stdin: "pipe" };
  if (opts.stdin !== undefined) return { stdin: opts.stdin };
  return {};
}

// The child's stdout, read to its end; with `feed`, its line goes to `stdin` once
// the output read so far holds the cue.
async function readStdout(stdout: ReadableStream<Uint8Array>, stdin: unknown, feed?: Feed): Promise<string> {
  if (feed === undefined) return new Response(stdout).text();
  const sink = stdin as FileSink;
  const decoder = new TextDecoder();
  let text = "";
  let fed = false;
  for await (const chunk of stdout) {
    text += decoder.decode(chunk, { stream: true });
    if (!fed && text.includes(feed.cue)) {
      fed = true;
      sink.write(feed.line);
      sink.end();
    }
  }
  return text + decoder.decode();
}

/// The process environment a spawned `build/vader` should see, plus `extra`.
///
/// `VADER_HOME` is CLEARED. It outranks every other toolchain probe, so a
/// developer who has it exported would silently run the whole corpus against a
/// different `lib/`, and, being absolute, against different module ids, which is
/// snapshot drift with no visible cause. `extra` is applied last, so a test that
/// sets it deliberately still wins.
///
/// Exported because `spawnCapture` is not the only way the suite starts the
/// compiler: the LSP and DAP suites drive it through their own `Bun.spawn` to
/// keep stdin open, and they need the same hermeticity.
export function hermeticEnv(extra: Record<string, string> = {}): Record<string, string | undefined> {
  const overrides = { VADER_HOME: undefined, ...extra };
  const env: Record<string, string | undefined> = { ...process.env };
  if (process.platform === "win32") deleteSpellingsOf(env, Object.keys(overrides));
  return { ...env, ...overrides };
}

// Windows reads a variable whatever its case, and its `process.env` spells the
// path `Path`: a `PATH` added beside it would leave the inherited one in force.
function deleteSpellingsOf(env: Record<string, string | undefined>, names: string[]): void {
  const spelled = new Set(names.map((name) => name.toUpperCase()));
  for (const key of Object.keys(env)) {
    if (spelled.has(key.toUpperCase())) delete env[key];
  }
}

// One spawn implementation for every test that drives a binary, so the pipe
// drain and the kill timer below are written once. `runCli` is the positional
// shorthand over it, kept for the suites that only ever run the CLI in place.
export async function spawnCapture(args: string[], opts: SpawnOptions = {}): Promise<CliResult> {
  // Resolved against the TEST PROCESS's cwd (the repo root), never against
  // `opts.cwd`: `CLI_BIN` is repo-relative, so a `cwd` override would otherwise
  // look for `build/vader` inside the staged project and fail with ENOENT.
  const bin = resolve(opts.bin ?? CLI_BIN);
  const proc = Bun.spawn([bin, ...args], {
    cwd: opts.cwd,
    ...stdinOption(opts),
    stdout: "pipe",
    stderr: "pipe",
    env: hermeticEnv(opts.env),
  });
  const killTimer = setTimeout(() => proc.kill("SIGKILL"), opts.timeoutMs ?? DEFAULT_CLI_TIMEOUT_MS);
  try {
    const [stdout, stderr, exit] = await Promise.all([
      readStdout(proc.stdout, proc.stdin, opts.feed),
      new Response(proc.stderr).text(),
      proc.exited,
    ]);
    return { stdout, stderr, exit };
  } finally {
    clearTimeout(killTimer);
  }
}

export async function runCli(
  args: string[],
  env?: Record<string, string>,
  timeoutMs: number = DEFAULT_CLI_TIMEOUT_MS,
): Promise<CliResult> {
  return spawnCapture(args, { env, timeoutMs });
}
