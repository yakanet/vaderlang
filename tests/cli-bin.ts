// Shared presence check + spawn wrapper for the Vader CLI native binary.
// The harness does NOT build the compiler — it asserts a prebuilt `build/vader`
// exists and is up to date vs the .vader sources, failing loudly otherwise.
// This severs the test suite from the TS compiler in src/ (the §2.8 path): the
// binary is provided by `bun run build:cli` (while src/ exists) or from the
// committed C seed (see bootstrap/README.md).

import { beforeAll } from "bun:test";
import { statSync } from "node:fs";
import { resolve } from "node:path";
import { listVaderFiles } from "./vader-sources.ts";

// The suffix a LINKER appends to an executable name. `cc -o hello` writes
// `hello` on Unix and `hello.exe` on Windows — verified with mingw-w64: gcc
// appends it when `-o` carries no extension. Every path to a BUILT binary goes
// through `exePath`, or the assertion passes on one OS and fails on the other.
export const EXE_SUFFIX = process.platform === "win32" ? ".exe" : "";

export const exePath = (base: string) => `${base}${EXE_SUFFIX}`;

export const CLI_BIN = exePath("build/vader");

// Per-test timeout budgets shared across the CLI / VM / format suites.
export const MEDIUM_BUILD = 30_000;
export const LONG_BUILD = 120_000;
// For a test that compiles a driver. A driver compile pulls the whole `vader/`
// closure at -O0 — the same order of work as the CI step that builds the CLI from
// the seed. Measured: 7 s locally, and 139-272 s per driven build on a Windows
// runner (job log, run #224), the spread being the wait for a slot in
// `hook_driver`'s four-deep gate. 300 s left the slowest of those 30 s from the
// cap, which is a flake waiting to happen — hence twice that. This is a KILL
// CEILING, not a target: raising it costs nothing until something hangs.
export const HEAVY_BUILD = 600_000;

// Newest mtime across the .vader sources the compiler is built from. src/ (the
// TS compiler) is intentionally excluded — the binary is produced from these
// .vader sources, not TS, so a TS edit must not flag the binary stale. Post-§2.8
// src/ is gone entirely.
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
// gone — that was the TypeScript compiler, deleted when the tree started
// self-hosting from the seed, and `src/` now means something else entirely (the
// compiler's own sources inside a dist bundle).
const BUILD_HINT =
  `  bun run build                                  # 3-stage bootstrap from the committed C seed\n` +
  `  bun run build:cli                              # the same, plus a dist/ bundle\n` +
  `  # equivalently, without Bun (see bootstrap/README.md):\n` +
  `  bash bootstrap/build.sh                         # → ${CLI_BIN}`;

// Assert a prebuilt, up-to-date compiler binary is present — never build it.
// Missing or stale-vs-sources is a hard failure with rebuild instructions, so
// the suite never silently runs against a stale binary. The N test files that
// load this share one check via the global beforeAll.
export function ensureCliBuilt(): void {
  beforeAll(() => {
    const bin = binaryMtime();
    if (bin === 0) {
      throw new Error(`${CLI_BIN} not found — build the compiler first:\n${BUILD_HINT}`);
    }
    if (bin < newestSourceMtime()) {
      throw new Error(`${CLI_BIN} is stale (older than vader/ or lib/ sources) — rebuild it:\n${BUILD_HINT}`);
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

// Both pipes are drained concurrently — leaving stderr unread can deadlock
// the child once the 64 KB pipe buffer fills on a verbose trap.
export interface SpawnOptions {
  /** Binary to run. Defaults to the CLI — override for a `dist/` bundle's own
   *  `vader`, or for a binary the CLI just produced. */
  readonly bin?: string;
  /** Working directory. Load bearing for a driven build: `build.vader` is
   *  discovered relative to the INVOCATION directory, not to the binary. */
  readonly cwd?: string;
  readonly env?: Record<string, string>;
  readonly timeoutMs?: number;
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
    stdout: "pipe",
    stderr: "pipe",
    env: { ...process.env, ...(opts.env ?? {}) },
  });
  const killTimer = setTimeout(() => proc.kill("SIGKILL"), opts.timeoutMs ?? DEFAULT_CLI_TIMEOUT_MS);
  try {
    const [stdout, stderr, exit] = await Promise.all([
      new Response(proc.stdout).text(),
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
