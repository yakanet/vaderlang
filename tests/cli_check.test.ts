// tests/cli_check: `vader check`, the compensation for compile-time target
// selection.
//
// A body whose `@target` does not match is never resolved or typed, so on any
// one machine the code for every OTHER platform is unchecked — the same blind
// spot the `#ifdef` walls in `runtime/c/` had, and the source of the two Windows
// bugs that started the work on targets. `check` closes it without a toolchain:
// these tests type-check Windows code from whatever machine runs them.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, LONG_BUILD, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";
import { COMPILER_ENTRY } from "./vader-sources.ts";

ensureCliBuilt();

const FIXTURES = join(import.meta.dir, "fixtures", "target");
const BROKEN_ON_WINDOWS = join(FIXTURES, "discarded_body_not_typed", "main.vader");

// The property the whole mechanism rests on, from the outside: the error is in a
// body only Windows compiles, and it is reported here without a Windows machine.
test("check reports an error in a foreign target's body", async () => {
  const r = await runCli(
    ["check", "--target=windows-x86_64", BROKEN_ON_WINDOWS], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("T3020");
  expect(r.stderr).toContain("main-windows.vader");
});

test("check is silent and zero for a target whose bodies are sound", async () => {
  const r = await runCli(
    ["check", "--target=darwin-arm64", BROKEN_ON_WINDOWS], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  // Nothing on stdout: a gate is read by a script before it is read by a person.
  expect(r.stdout.trim()).toBe("");
});

test("check rejects a malformed target and names the fragment", async () => {
  const r = await runCli(
    ["check", "--target=drawin-arm64", BROKEN_ON_WINDOWS], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(2);
  expect(r.stderr).toContain("drawin");
});

// `VADER_OS` is the "lightweight" half of the target model: a value, reachable
// from a file that imports nothing, foldable at comptime. It needs a target, and
// an explicit `--target=` is one — the DEFAULT is what waits on the reseed.
test("VADER_OS resolves and folds under an explicit target", async () => {
  const probe = join(FIXTURES, "baked_constant", "main.vader");
  const win = await runCli(
    ["check", "--target=windows-x86_64", probe], undefined, MEDIUM_BUILD);
  expect(win.exit).toBe(0);
  const mac = await runCli(
    ["check", "--target=darwin-arm64", probe], undefined, MEDIUM_BUILD);
  expect(mac.exit).toBe(0);
});

// With no `--target=`, the target is this machine — so the constant is baked all
// the same. This assertion used to be its opposite ("VADER_OS is absent when no
// target is given"), which failed the moment the default landed. That was its
// purpose: a limitation worth asserting is a limitation that tells you when it
// stops being one.
test("VADER_OS is baked with no target given, from the host", async () => {
  const r = await runCli(
    ["check", join(FIXTURES, "baked_constant", "main.vader")], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stderr.trim()).toBe("");
});

// The compiler's own `@target` bodies, checked from whatever machine runs the
// suite: a Windows body broken on a Mac would otherwise surface only in the
// Windows CI job. `Arch` selects no code, so one target per OS reaches them all.
for (const target of ["windows-x86_64", "linux-x86_64", "darwin-arm64"]) {
  test.concurrent(`the compiler checks clean for ${target}`, async () => {
    const r = await runCli(["check", `--target=${target}`, COMPILER_ENTRY], undefined, LONG_BUILD);
    expect(r.stderr).toBe("");
    expect(r.exit).toBe(0);
  }, LONG_BUILD);
}
