// tests/extern_by_value_vm.test.ts: under `vader run`, a struct crossing an
// `@extern` by value stops the program with a message that names `vader build`.
//
// The interpreter calls C through trampolines that pass words and addresses,
// while where a struct travels depends on the ABI, which only `cc` applies. The
// fixtures hold one program per direction: a program stops at its first such
// call.

import { expect, test } from "bun:test";
import { join } from "node:path";
import { runCli, MEDIUM_BUILD, LONG_BUILD } from "./cli-bin.ts";

const FIXTURES = join(import.meta.dir, "fixtures/ffi_by_value");

test("a struct returned by value stops vader run", async () => {
  const r = await runCli(["run", join(FIXTURES, "result/_main.vader")], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("extern `div`");
  expect(r.stderr).toContain("returns a struct by value, which only a native build can do");
}, LONG_BUILD);

test("a struct passed by value stops vader run", async () => {
  const r = await runCli(["run", join(FIXTURES, "argument/_main.vader")], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("argument 0 passes a struct by value, which only a native build can do");
}, LONG_BUILD);
