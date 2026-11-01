// Each part of the C runtime (`runtime/c/rt/*.c`) parses on its own. The parts
// build as ONE translation unit, `vader_runtime.c` including them in turn, so a
// part reaching a static of an earlier one compiles there without any
// declaration, and breaks only the day the order of the includes changes.
// Parsed alone, a part sees nothing but `rt/internal.h`: what crosses between
// parts has to be declared there, which keeps that header the complete list.
// A part named after an OS (`os_posix.c`, `os_windows.c`) is parsed only on a
// host of that OS, the one where the unity includes it.

import { expect, test } from "bun:test";
import { readdirSync } from "node:fs";
import { join } from "node:path";
import { HOST_CC, haveCc } from "./cli-bin.ts";

const RT = join(import.meta.dir, "../runtime/c/rt");

const CC_AVAILABLE = await haveCc();

const ON_WINDOWS = process.platform === "win32";

function builtOnThisHost(part: string): boolean {
  if (part.endsWith("_windows.c")) return ON_WINDOWS;
  if (part.endsWith("_posix.c")) return !ON_WINDOWS;
  return true;
}

const PARTS = readdirSync(RT)
  .filter((f) => f.endsWith(".c") && builtOnThisHost(f))
  .sort();

test("the runtime has parts to check", () => {
  expect(PARTS.length).toBeGreaterThan(0);
});

for (const part of PARTS) {
  test.concurrent(`runtime part parses on its own: ${part}`, async () => {
    if (!CC_AVAILABLE) return;
    // An implicit declaration is only a warning on an older GCC, and it is
    // exactly what a missing declaration in `rt/internal.h` produces.
    const proc = Bun.spawn(
      [HOST_CC, "-std=c11", "-fsyntax-only", "-Werror=implicit-function-declaration", join(RT, part)],
      { stdout: "pipe", stderr: "pipe" },
    );
    const stderr = await new Response(proc.stderr).text();
    const exit = await proc.exited;
    expect(exit === 0 ? "" : stderr).toBe("");
  });
}
