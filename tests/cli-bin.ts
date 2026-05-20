// Shared rebuild hook + spawn wrapper for the Vader CLI native binary.
// Idempotent — the mtime check short-circuits when the binary is fresh,
// so the N test files that load this share one actual rebuild.

import { beforeAll } from "bun:test";
import { readdirSync, statSync } from "node:fs";
import { join } from "node:path";

export const CLI_BIN = `build/vader${process.platform === "win32" ? ".exe" : ""}`;

// Per-test timeout budgets shared across the CLI / VM / format suites.
export const MEDIUM_BUILD = 30_000;
export const LONG_BUILD = 120_000;

let cachedSourceMtime: number | undefined;

function newestSourceMtime(): number {
  if (cachedSourceMtime !== undefined) return cachedSourceMtime;
  let max = 0;
  const exts = [".vader", ".ts"];
  const walk = (dir: string): void => {
    for (const ent of readdirSync(dir, { withFileTypes: true })) {
      const p = join(dir, ent.name);
      if (ent.isDirectory()) walk(p);
      else if (exts.some((e) => ent.name.endsWith(e))) {
        const m = statSync(p).mtimeMs;
        if (m > max) max = m;
      }
    }
  };
  walk("vader");
  walk("stdlib");
  walk("src");
  cachedSourceMtime = max;
  return max;
}

function binaryMtime(): number {
  try { return statSync(CLI_BIN).mtimeMs; } catch { return 0; }
}

// 5-minute timeout covers cold-CI builds. `--release` keeps per-test parse
// latency below the parity suite's 30 s per-test timeout.
export function ensureCliBuilt(): void {
  beforeAll(async () => {
    if (binaryMtime() >= newestSourceMtime()) return;
    const proc = Bun.spawn(
      ["bun", "src/index.ts", "build", "vader/cli/main.vader", "--target=native", "--release", `--out=${CLI_BIN}`],
      { stdout: "pipe", stderr: "pipe" },
    );
    const code = await proc.exited;
    if (code !== 0) {
      const err = await new Response(proc.stderr).text();
      throw new Error(`vader CLI build failed (exit ${code}):\n${err}`);
    }
  }, 600_000);
}

export interface CliResult {
  stdout: string;
  stderr: string;
  exit: number;
}

// Both pipes are drained concurrently — leaving stderr unread can deadlock
// the child once the 64 KB pipe buffer fills on a verbose trap.
export async function runCli(args: string[]): Promise<CliResult> {
  const proc = Bun.spawn([CLI_BIN, ...args], { stdout: "pipe", stderr: "pipe" });
  const [stdout, stderr, exit] = await Promise.all([
    new Response(proc.stdout).text(),
    new Response(proc.stderr).text(),
    proc.exited,
  ]);
  return { stdout, stderr, exit };
}
