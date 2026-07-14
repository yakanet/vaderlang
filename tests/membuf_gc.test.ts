// S2b — Target ABI byte-buffer GC proof (G1).
//
// The 12 memory opcodes are consumer-inert (no .vader source lowers to them
// until the Buffer type lands), so this exercises them through a hand-authored
// .virt op stream (tests/fixtures/membuf_gc.virt) compiled via the new
// `vader build x.virt --target=c/native` path. It asserts two things the unit
// suite cannot: (1) the c-emit arms emit the real `vader_buffer_*` helpers, not
// `todo()` stubs; (2) a buffer's stored bytes survive a forced *moving*
// collection — G1, the interior-pointer re-derivation discipline. The fixture
// roots one buffer, stores 42, then allocates dead garbage in a callee to force
// minor collections that relocate the rooted buffer, and reads 42 back (as the
// process exit code). Run under a tight young arena + VADER_GC_SCAN_ALL_OLD so
// the move actually happens. A regression in the buffer's GC handling (e.g. the
// box-scanner skipping the BUFFER sentinel tag) reads back 0, failing here.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, LONG_BUILD } from "./cli-bin.ts";
import { readFileSync, mkdtempSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

ensureCliBuilt();

const FIXTURE = "tests/fixtures/membuf_gc.virt";

test("membuf .virt -> C emits the buffer ABI helpers (not stubs)", async () => {
  const dir = mkdtempSync(join(tmpdir(), "membuf-"));
  const cpath = join(dir, "membuf.c");
  const r = await runCli(
    ["build", FIXTURE, "--target=c", "--release", `--out=${cpath}`],
    {},
    LONG_BUILD,
  );
  expect(r.exit).toBe(0);
  const c = readFileSync(cpath, "utf8");
  // T12: a buffer is a concrete heap ref, so it rides as a raw `void*` (not a
  // tagged box) — its object header carries the BUFFER sentinel, so the GC
  // forwards it via the raw-ref scan (exercised behaviourally by the
  // "survives a forced moving collection" test below). Construction + the typed
  // ops still go through the inline byte helpers.
  expect(c).toContain("(void*) vader_buffer_new(");
  expect(c).toContain("vader_buffer_store_i32(");
  expect(c).toContain("vader_buffer_load_i32(");
});

test("membuf survives a forced moving collection (G1)", async () => {
  const dir = mkdtempSync(join(tmpdir(), "membuf-"));
  const bin = join(dir, "membuf");
  const b = await runCli(
    ["build", FIXTURE, "--target=native", "--release", `--out=${bin}`],
    {},
    LONG_BUILD,
  );
  expect(b.exit).toBe(0);

  // Tight young arena + SCAN_ALL_OLD: the 64 garbage allocations (256 KB)
  // overflow young many times over, so the rooted buffer is actually relocated
  // by minor collections. The stored 42 must read back through the forwarded
  // box (G1) with its bytes copied intact.
  for (const youngKb of [16, 32, 64, 128]) {
    const proc = Bun.spawn([bin], {
      env: {
        ...process.env,
        VADER_GC_YOUNG_BYTES: String(youngKb * 1024),
        VADER_GC_SCAN_ALL_OLD: "1",
      },
      stdout: "pipe",
      stderr: "pipe",
    });
    const exit = await proc.exited;
    expect(exit).toBe(42);
  }
}, LONG_BUILD);
