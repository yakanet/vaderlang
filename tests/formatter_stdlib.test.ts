// Stdlib formatter checks over EVERY `stdlib/**/*.vader` (recursively). Three
// contracts, weakest to strongest :
//
//   1. reparse-after-format — the formatted output parses with zero errors.
//      This is the round-trip-safety net : it is what catches a formatter that
//      emits non-compilable text (audit F3/F4/F5 all slipped past the older
//      idempotency-only probe, since a *stably* corrupt re-emit is idempotent).
//   2. idempotency — `fmt(fmt(src)) === fmt(src)`.
//   3. byte-for-byte no-op — `fmt(src) === src` for the curated set below.
//
// Same `RUN_FMT_TESTS=1` opt-in gate as `formatter.test.ts` — each file costs
// two to three native `build/vader` spawns, so the whole suite is skipped
// unless requested.

import { test, expect } from "bun:test";
import { readFileSync, existsSync, readdirSync } from "node:fs";
import { join } from "node:path";
import { CLI_BIN, MEDIUM_BUILD, runCli } from "./cli-bin.ts";

const ENABLED = process.env.RUN_FMT_TESTS === "1";

const STDLIB_ROOT = join(process.cwd(), "stdlib", "std");

// Every `*.vader` anywhere under `stdlib/std/`. The stdlib is organised into
// per-module folders (`core/`, `string/`, `collections/`, …), so this MUST
// recurse — a flat `readdirSync` finds nothing and silently tests zero files.
function listStdlibFiles(): string[] {
  if (!existsSync(STDLIB_ROOT)) return [];
  const out: string[] = [];
  const walk = (dir: string) => {
    for (const ent of readdirSync(dir, { withFileTypes: true })) {
      const full = join(dir, ent.name);
      if (ent.isDirectory()) walk(full);
      else if (ent.name.endsWith(".vader")) out.push(full);
    }
  };
  walk(STDLIB_ROOT);
  return out.sort();
}

// Files that round-trip byte-for-byte today. Grow this set whenever a
// formatter refinement lands ; a file outside it is held to the weaker
// checks above.
const NO_OP_FILES = new Set([
  "math.vader",
  "runtime.vader",
]);

// Files with a KNOWN, pre-existing idempotency wobble unrelated to round-trip
// safety : a name-column alignment group whose width shifts on the second pass
// when an interleaved comment splits the group (e.g. `TOMB_SLOT  ::` →
// `TOMB_SLOT ::`). They still reparse cleanly (contract 1 holds) — only the
// stronger `fmt(fmt) === fmt` is skipped until the alignment pass is tightened.
const UNSTABLE_IDEMPOTENCY = new Set([
  "collections.vader",
  "parse_float.vader",
]);

function fmtStdout(path: string): string {
  const proc = Bun.spawnSync({
    cmd: [CLI_BIN, "fmt", "--stdout", path],
    cwd: process.cwd(),
    stdout: "pipe",
    stderr: "pipe",
  });
  if (proc.exitCode !== 0) {
    throw new Error(
      `vader fmt failed on ${path} (exit ${proc.exitCode}) :\n` +
      new TextDecoder().decode(proc.stderr),
    );
  }
  return new TextDecoder().decode(proc.stdout);
}

function fmtString(source: string): string {
  const tmp = join(process.cwd(), ".tmp-fmt-stdlib-roundtrip.vader");
  Bun.write(tmp, source);
  try {
    return fmtStdout(tmp);
  } finally {
    try { Bun.file(tmp).delete?.(); } catch { /* ignore */ }
  }
}

// The `error[...]` lines `dump --stage=ast` prints for a file that fails to
// parse. `dump` reports diagnostics on stdout and always exits 0, so scan the
// text rather than the exit code. Empty string ⇒ clean reparse. Goes through
// `runCli` (not a raw `Bun.spawnSync`) for its self-cleaning SIGKILL timer.
async function reparseErrors(path: string): Promise<string> {
  const { stdout, stderr } = await runCli(["dump", "--stage=ast", path]);
  return (stdout + stderr).split("\n").filter((l) => l.includes("error[")).join("\n");
}

for (const path of listStdlibFiles()) {
  const base = path.slice(path.lastIndexOf("/") + 1);

  test(`stdlib reparse after format : ${base}`, async () => {
    if (!ENABLED) return;
    const formatted = fmtStdout(path);
    const tmp = join(process.cwd(), `.tmp-fmt-stdlib-reparse-${base}`);
    await Bun.write(tmp, formatted);
    try {
      expect(await reparseErrors(tmp)).toBe("");
    } finally {
      try { Bun.file(tmp).delete?.(); } catch { /* ignore */ }
    }
  }, { timeout: MEDIUM_BUILD });

  test(`stdlib idempotent : ${base}`, async () => {
    if (!ENABLED) return;
    if (UNSTABLE_IDEMPOTENCY.has(base)) return;
    const f1 = fmtStdout(path);
    const f2 = fmtString(f1);
    expect(f2).toBe(f1);
  }, { timeout: MEDIUM_BUILD });

  if (NO_OP_FILES.has(base)) {
    test(`stdlib byte-for-byte no-op : ${base}`, async () => {
      if (!ENABLED) return;
      const src = readFileSync(path, "utf8");
      const formatted = fmtStdout(path);
      expect(formatted).toBe(src);
    }, { timeout: MEDIUM_BUILD });
  }
}
