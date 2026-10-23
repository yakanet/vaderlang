// tests/raylib_sprite: the raylib example builds natively, against the archive
// `third_party/raylib` ships for this machine.
//
// It is not run: it opens a window. A machine with no archive in
// `third_party/raylib/lib/` is skipped, which Windows is for now (see
// `third_party/raylib/README.md`).

import { afterAll, expect, test } from "bun:test";
import { existsSync, mkdtempSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join, resolve } from "node:path";
import { HOST_TARGET, LONG_BUILD, spawnCapture, TOOLCHAIN_ENV } from "./cli-bin.ts";
import { exampleEntry } from "./vader-sources.ts";

const ARCHIVE = resolve(import.meta.dir, `../third_party/raylib/lib/${HOST_TARGET}/libraylib.a`);
const out = mkdtempSync(join(tmpdir(), "vader-raylib-"));

afterAll(() => {
  rmSync(out, { recursive: true, force: true });
});

test.skipIf(!existsSync(ARCHIVE))(
  "the raylib example builds natively",
  async () => {
    const build = await spawnCapture(
      ["build", `--out=${join(out, "raylib_sprite")}`, exampleEntry("raylib_sprite")],
      { env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
    );
    expect(build.stderr).not.toContain("error");
    expect(build.exit).toBe(0);
  },
  LONG_BUILD,
);
