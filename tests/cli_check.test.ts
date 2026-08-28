// tests/cli_check — `vader check`, the compensation for compile-time target
// selection.
//
// A body whose `@target` does not match is never resolved or typed, so on any
// one machine the code for every OTHER platform is unchecked — the same blind
// spot the `#ifdef` walls in `runtime/c/` had, and the source of the two Windows
// bugs that started the target chantier. `check` closes it without a toolchain:
// these tests type-check Windows code from whatever machine runs them.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const FIXTURES = join(import.meta.dir, "target_fixtures");
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

// Without a target nothing bakes, so the constant does not exist. Asserted
// rather than left implicit: it is the visible half of the reseed debt, and it
// should start passing differently the day the default lands.
test("VADER_OS is absent when no target is given", async () => {
  const r = await runCli(
    ["check", join(FIXTURES, "baked_constant", "main.vader")], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("VADER_OS");
});
