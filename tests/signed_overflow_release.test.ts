// The wrapping operators wrap in a release build, as on the VM. The
// `signed_overflow_wraps` snippet pins the VM in its `vm.snapshot`, and the C-emit
// parity suite runs its C at -O0. This file builds it with `--release` and compares
// the two: without `-fwrapv`, clang at -O3 folds `x +% 1 > x` to `true` and turns the
// snippet's loop into an endless one.
import { expect, test } from "bun:test";
import { readFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { EXE_SUFFIX, LONG_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";
import { formatRun } from "./snapshot.ts";

const SNIPPET_DIR = "tests/snippets/signed_overflow_wraps";

test("a release build wraps the wrapping operators like the VM", async () => {
  if (!(await haveCc())) return;
  const bin = join(tmpdir(), `vader-signed-overflow-${process.pid}${EXE_SUFFIX}`);
  const build = await runCli(
    ["build", "--release", `--out=${bin}`, join(SNIPPET_DIR, "_main.vader")],
    undefined,
    LONG_BUILD,
  );
  expect(build.exit).toBe(0);

  const run = await spawnCapture([], { bin, timeoutMs: 10_000 });
  const expected = readFileSync(join(SNIPPET_DIR, "vm.snapshot"), "utf8");
  expect(formatRun(run.stdout, run.stderr, run.exit)).toBe(expected);
}, LONG_BUILD);
