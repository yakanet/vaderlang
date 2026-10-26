// tests/raycaster: the raycaster's frames, built natively.
//
// `examples_run.test.ts` runs the example's `frames` entry on the VM and pins
// what it prints in `tests/fixtures/examples/raycaster.run.snapshot`. Here the
// same entry is built natively and run: it must print the same frames, checksum
// for checksum, which is a VM/native parity check over a whole renderer. The
// snapshot is only read here, never written: `UPDATE_SNAPSHOTS` refreshes it from
// the VM run.

import { afterAll, expect, test } from "bun:test";
import { mkdtempSync, readFileSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join, resolve } from "node:path";
import { LONG_BUILD, spawnCapture, TOOLCHAIN_ENV } from "./cli-bin.ts";
import { snapshotDiff } from "./diff.ts";
import { formatRun } from "./snapshot.ts";
import { exampleInput } from "./vader-sources.ts";

const SNAPSHOT = resolve(import.meta.dir, "fixtures/examples/raycaster.run.snapshot");
const out = mkdtempSync(join(tmpdir(), "vader-raycaster-"));

afterAll(() => {
  rmSync(out, { recursive: true, force: true });
});

test(
  "the raycaster's frames are the same built natively as on the VM",
  async () => {
    const binary = join(out, "frames");
    const build = await spawnCapture(
      ["build", "--entry=frames", `--out=${binary}`, exampleInput("raycaster")],
      { env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
    );
    expect(build.stderr).not.toContain("error");
    expect(build.exit).toBe(0);
    const run = await spawnCapture([], { bin: binary, timeoutMs: LONG_BUILD });
    const expected = readFileSync(SNAPSHOT, "utf8");
    const actual = formatRun(run.stdout, run.stderr, run.exit);
    if (actual !== expected) {
      throw new Error(`native frames differ from the VM's\n\n${snapshotDiff(SNAPSHOT, expected, actual)}`);
    }
  },
  LONG_BUILD,
);
