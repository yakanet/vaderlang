// Broad-corpus parity — stress the Vader self-host typechecker against
// the real `vader/` and `stdlib/` source tree. The 251 snippet-based
// tests give isolated coverage ; this suite ensures the typechecker
// survives the codebase it's meant to self-compile.
//
// What we check, per module folder (one pivot file per dir) :
//   1. Vader CLI `dump --stage=typed-ast <file>` exits 0 (no SIGABRT /
//      OOM / runtime trap).
//   2. stderr does not contain any `error[` diagnostic (warnings are
//      tolerated). The folder-module promotion (§2.6) loads every
//      sibling `.vader`, so unresolved-name errors here would point at
//      real bugs.
//
// We do NOT diff Vader's stdout against TS's because invoking TS on a
// single file inside a multi-file folder doesn't trigger folder-module
// promotion on the TS side, making the comparison structurally unfair.
//
// Gated by `RUN_BROAD_PARITY=1` — heavy (Vader self-host is slow on
// large modules).

import { test, expect } from "bun:test";
import { readdirSync, type Dirent } from "node:fs";
import { join } from "node:path";

import { LONG_BUILD, runCli } from "./cli-bin.ts";

const RUN_BROAD = process.env["RUN_BROAD_PARITY"] === "1";

function pickModulePivot(dir: string): string | null {
  let entries: Dirent[];
  try { entries = readdirSync(dir, { withFileTypes: true }); } catch { return null; /* unreadable dir, skip */ }
  const vaderFiles = entries
    .filter((e) => e.isFile() && e.name.endsWith(".vader"))
    .map((e) => join(dir, e.name))
    .sort();
  return vaderFiles[0] ?? null;
}

function collectModuleDirs(root: string): string[] {
  const out: string[] = [];
  const walk = (dir: string): void => {
    let entries: Dirent[];
    try { entries = readdirSync(dir, { withFileTypes: true }); } catch { return; /* unreadable dir, skip */ }
    let hasVader = false;
    for (const ent of entries) {
      if (ent.isDirectory()) walk(join(dir, ent.name));
      else if (ent.isFile() && ent.name.endsWith(".vader")) hasVader = true;
    }
    if (hasVader) out.push(dir);
  };
  walk(root);
  out.sort();
  return out;
}

const modules: string[] = RUN_BROAD
  ? [...collectModuleDirs("vader"), ...collectModuleDirs("stdlib")]
  : [];

test("broad-parity: gated by RUN_BROAD_PARITY=1", () => {
  if (!RUN_BROAD) {
    expect(modules.length).toBe(0);
    return;
  }
  expect(modules.length).toBeGreaterThan(0);
});

// The self-host typechecker legitimately needs more than the default
// 4MB young / 16MB old GC arena when transitively loading a real folder
// module (eval_types.vader pulls in ~30K LoC of imports). 16M old → OOM,
// 32M old → OK on every module tested so far. Bumping young helps the
// throughput too — minor collects dominate hot paths.
const BOOTSTRAP_ENV: Record<string, string> = {
  VADER_GC_YOUNG_BYTES: String(16 * 1024 * 1024),
  VADER_GC_OLD_BYTES:   String(128 * 1024 * 1024),
};

// Serial, not `test.concurrent` : each invocation pegs one core for tens of
// seconds, so launching all ~17 in parallel oversubscribes and pushes every
// run past the 120s timeout.
for (const dir of modules) {
  const pivot = pickModulePivot(dir);
  if (pivot === null) continue;
  test(`broad-parity: ${dir}`, async () => {
    const res = await runCli(["dump", "--stage=typed-ast", pivot], BOOTSTRAP_ENV);
    if (res.exit !== 0) {
      throw new Error(
        `Vader self-host crashed on ${pivot} (exit ${res.exit}):\n` +
        `--- stderr ---\n${res.stderr.slice(-2000)}`,
      );
    }
    const errorLines = res.stderr
      .split("\n")
      .filter((l) => l.startsWith("error["));
    if (errorLines.length > 0) {
      throw new Error(
        `Vader self-host emitted ${errorLines.length} typecheck errors on ${pivot}:\n` +
        errorLines.slice(0, 10).join("\n"),
      );
    }
  }, { timeout: LONG_BUILD });
}
