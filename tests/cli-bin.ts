// Shared presence check + spawn wrapper for the Vader CLI native binary.
// The harness does NOT build the compiler — it asserts a prebuilt `build/vader`
// exists and is up to date vs the .vader sources, failing loudly otherwise.
// This severs the test suite from the TS compiler in src/ (the §2.8 path): the
// binary is provided by `bun run build:cli` (while src/ exists) or from the
// committed C seed (see bootstrap/README.md).

import { beforeAll } from "bun:test";
import { readdirSync, statSync } from "node:fs";
import { join } from "node:path";

export const CLI_BIN = `build/vader${process.platform === "win32" ? ".exe" : ""}`;

// Per-test timeout budgets shared across the CLI / VM / format suites.
export const MEDIUM_BUILD = 30_000;
export const LONG_BUILD = 120_000;

// Newest mtime across the .vader sources the compiler is built from. src/ (the
// TS compiler) is intentionally excluded — the binary is produced from these
// .vader sources, not TS, so a TS edit must not flag the binary stale. Post-§2.8
// src/ is gone entirely. Called once per worker (from the global beforeAll), so
// no memoization.
function newestSourceMtime(): number {
  let max = 0;
  const walk = (dir: string): void => {
    for (const ent of readdirSync(dir, { withFileTypes: true })) {
      const p = join(dir, ent.name);
      if (ent.isDirectory()) walk(p);
      else if (ent.name.endsWith(".vader")) {
        const m = statSync(p).mtimeMs;
        if (m > max) max = m;
      }
    }
  };
  walk("vader");
  walk("stdlib");
  return max;
}

function binaryMtime(): number {
  try { return statSync(CLI_BIN).mtimeMs; } catch { return 0; }
}

// Build instructions surfaced when the binary is missing or stale. The seed
// path needs only a C compiler + gzip (no TS); `build:cli` is the fast local
// shortcut while src/ still exists.
const BUILD_HINT =
  `  bun run build:cli                              # fast, while src/ exists\n` +
  `  # or from the committed C seed (no TS — see bootstrap/README.md):\n` +
  `  bash bootstrap/build.sh                         # 3-stage bootstrap → ${CLI_BIN}`;

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
      throw new Error(`${CLI_BIN} is stale (older than vader/ or stdlib/ sources) — rebuild it:\n${BUILD_HINT}`);
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
export async function runCli(
  args: string[],
  env?: Record<string, string>,
  timeoutMs: number = DEFAULT_CLI_TIMEOUT_MS,
): Promise<CliResult> {
  const proc = Bun.spawn([CLI_BIN, ...args], {
    stdout: "pipe",
    stderr: "pipe",
    env: { ...process.env, ...(env ?? {}) },
  });
  const killTimer = setTimeout(() => proc.kill("SIGKILL"), timeoutMs);
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
