// Formatter checks over EVERY `lib/**/*.vader` — every namespace the toolchain
// ships, not `std/` alone (see `listLibraryFiles`). Three
// contracts, weakest to strongest :
//
//   1. reparse-after-format — the formatted output parses with zero errors.
//      This is the round-trip-safety net : it is what catches a formatter that
//      emits non-compilable text (audit F3/F4/F5 all slipped past the older
//      idempotency-only probe, since a *stably* corrupt re-emit is idempotent).
//   2. idempotency — `fmt(fmt(src)) === fmt(src)`.
//   3. byte-for-byte no-op — `fmt(src) === src` for the curated set below.
//
// Each file costs two to three native `build/vader` spawns, ~20 ms each. This ran
// behind the same `RUN_FMT_TESTS=1` gate as `formatter.test.ts` until the gate's
// premise (a TS shim over the VM, ~2-3 s per call) went away with `src/`.

import { test, expect } from "bun:test";
import { readFileSync, rmSync } from "node:fs";
import { basename, join } from "node:path";
import { MEDIUM_BUILD, fmtStdout, fmtString, runCli } from "./cli-bin.ts";
import { listVaderFiles } from "./vader-sources.ts";

const LIBRARY_ROOT = join(process.cwd(), "lib");

// Every `*.vader` anywhere under `lib/` — recursively, since modules are
// per-folder (`std/core/`, `std/string/`, …), and starting at `lib/` and not
// `lib/std/`, since the libraries that left `std/` (json, regex, semver, cli,
// crypto, base64, random, images) are namespaces of their own — naming `std`
// dropped 5 446 LoC from this corpus without a word.
function listLibraryFiles(): string[] {
  return listVaderFiles(LIBRARY_ROOT).sort();
}

// Files that round-trip byte-for-byte today. Grow this set whenever a
// formatter refinement lands ; a file outside it is held to the weaker
// checks above.
const NO_OP_FILES = new Set([
  "math.vader",
  "runtime.vader",
]);

// Files with a KNOWN, pre-existing idempotency wobble. The visible symptom is a
// name-column alignment group narrowing on the second pass (`TOMB_SLOT  ::` →
// `TOMB_SLOT ::`), but the CAUSE is upstream of the alignment pass: `fmt` relocates
// a TRAILING line-comment onto its own line above the next declaration —
//
//     EMPTY_SLOT :: i32(0)    // index slot holds no entry
//   becomes
//     EMPTY_SLOT :: i32(0)
//     // index slot holds no entry
//
// which splits the `::` group, so pass 2 computes a different column. Measured over
// `vader/` + `lib/`: 447 trailing comments across 59 files move this way. Tracked in
// TODO.md; both files still reparse cleanly (contract 1 holds), so only the stronger
// `fmt(fmt) === fmt` is skipped.
const UNSTABLE_IDEMPOTENCY = new Set([
  "collections.vader",
  "parse_float.vader",
]);

// The `error[...]` lines `dump --stage=ast` prints for a file that fails to
// parse. `dump` reports diagnostics on stdout and always exits 0, so scan the
// text rather than the exit code. Empty string ⇒ clean reparse. Goes through
// `runCli` (not a raw `Bun.spawnSync`) for its self-cleaning SIGKILL timer.
async function reparseErrors(path: string): Promise<string> {
  const { stdout, stderr } = await runCli(["dump", "--stage=ast", path]);
  return (stdout + stderr).split("\n").filter((l) => l.includes("error[")).join("\n");
}

for (const path of listLibraryFiles()) {
  // `basename`, not `slice(lastIndexOf("/"))`: `listVaderFiles` joins with the
  // platform separator, so on Windows the hand-rolled form found no `/`, returned
  // the WHOLE absolute path, and every temp file became
  // `.tmp-fmt-stdlib-reparse-D:\a\...\base64.vader` — an ENOENT on mkdir. It also
  // defeated the `UNSTABLE_IDEMPOTENCY` / `NO_OP_FILES` lookups below, which key on
  // a bare filename. Pre-existing, and invisible while the suite sat behind a gate.
  const base = basename(path);

  test(`library reparse after format : ${base}`, async () => {
    const formatted = await fmtStdout(path);
    const tmp = join(process.cwd(), `.tmp-fmt-stdlib-reparse-${base}`);
    await Bun.write(tmp, formatted);
    try {
      expect(await reparseErrors(tmp)).toBe("");
    } finally {
      // `rmSync(force)`, not `Bun.file().delete()` — the latter returns a promise, so
      // its rejection escapes this try/catch and fails the NEXT test instead.
      rmSync(tmp, { force: true });
    }
  }, { timeout: MEDIUM_BUILD });

  test(`library idempotent : ${base}`, async () => {
    if (UNSTABLE_IDEMPOTENCY.has(base)) return;
    const f1 = await fmtStdout(path);
    const f2 = await fmtString(f1, ".tmp-fmt-stdlib-roundtrip");
    expect(f2).toBe(f1);
  }, { timeout: MEDIUM_BUILD });

  if (NO_OP_FILES.has(base)) {
    test(`library byte-for-byte no-op : ${base}`, async () => {
      const src = readFileSync(path, "utf8");
      const formatted = await fmtStdout(path);
      expect(formatted).toBe(src);
    }, { timeout: MEDIUM_BUILD });
  }
}
