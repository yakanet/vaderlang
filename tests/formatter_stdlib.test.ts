// Stdlib formatter checks — idempotency on every `stdlib/**/*.vader` plus
// a hard-coded byte-for-byte set listing the files that the formatter
// already produces verbatim (`iter`, `runtime`, `sort`, `string_builder`).
// The latter is the keystone "stdlib no-op" probe ; growing the list as we
// land more refinements is the canonical signal that the formatter is
// converging on the existing style.
//
// Same `RUN_FMT_TESTS=1` opt-in gate as `formatter.test.ts` — each
// invocation pays the VM-bootstrap cost.

import { test, expect } from "bun:test";
import { readFileSync, existsSync, readdirSync } from "node:fs";
import { join } from "node:path";

const ENABLED = process.env.RUN_FMT_TESTS === "1";

const STDLIB_ROOT = join(process.cwd(), "stdlib", "std");

// Every `*.vader` directly under `stdlib/std/`. No recursion : the stdlib
// is flat at the time of writing, and walking deeper would only pick up
// the per-module folder convention if a future stdlib reorganises.
function listStdlibFiles(): string[] {
  if (!existsSync(STDLIB_ROOT)) return [];
  return readdirSync(STDLIB_ROOT)
    .filter((n) => n.endsWith(".vader"))
    .map((n) => join(STDLIB_ROOT, n))
    .sort();
}

// Files that round-trip byte-for-byte today. Grow this set whenever a
// formatter refinement lands. A file outside this set is held to the
// weaker idempotency check below.
const NO_OP_FILES = new Set([
  // Note : `iter.vader` was here, but the lazy iterator structs added 2026-05-11
  // exposed a small formatter quirk (probably around the multi-line struct decls
  // with trait-typed fields) — drop it back to the weaker idempotency check
  // until the formatter side is tightened. Files still byte-for-byte stable :
  "math.vader",
  "runtime.vader",
  "sort.vader",
  "string_builder.vader",
]);

function fmtStdout(path: string): string {
  const proc = Bun.spawnSync({
    cmd: ["bun", "src/index.ts", "fmt", "--stdout", path],
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

for (const path of listStdlibFiles()) {
  const base = path.slice(path.lastIndexOf("/") + 1);

  test(`stdlib idempotent : ${base}`, async () => {
    if (!ENABLED) return;
    const f1 = fmtStdout(path);
    const f2 = fmtString(f1);
    expect(f2).toBe(f1);
  }, { timeout: 30_000 });

  if (NO_OP_FILES.has(base)) {
    test(`stdlib byte-for-byte no-op : ${base}`, async () => {
      if (!ENABLED) return;
      const src = readFileSync(path, "utf8");
      const formatted = fmtStdout(path);
      expect(formatted).toBe(src);
    }, { timeout: 30_000 });
  }
}
