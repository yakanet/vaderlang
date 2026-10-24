// tests/extern_by_value_vm.test.ts: under `vader run`, a struct crossing an
// `@extern` by value goes through an adapter the run builds with `cc`.
//
// The interpreter calls C through trampolines that pass words and addresses,
// while where a struct travels depends on the ABI, which only `cc` applies. So
// the run compiles an adapter for each such call into a shared library, kept
// under the program's `build/ffi/`. The fixtures are copied to a folder of their
// own first, so that library lands there and not in the checkout.

import { afterAll, expect, test } from "bun:test";
import { cpSync, existsSync, mkdtempSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { LONG_BUILD, MEDIUM_BUILD, spawnCapture } from "./cli-bin.ts";

const FIXTURES = join(import.meta.dir, "fixtures/ffi_by_value");

const staged: string[] = [];

afterAll(() => {
  for (const dir of staged) {
    rmSync(dir, { recursive: true, force: true });
  }
});

// A copy of the fixture `name`, in a folder of its own.
function stage(name: string): string {
  const dir = mkdtempSync(join(tmpdir(), "vader-by-value-"));
  staged.push(dir);
  cpSync(join(FIXTURES, name), dir, { recursive: true });
  return dir;
}

test("a struct returned by value crosses under vader run", async () => {
  const dir = stage("result");
  const r = await spawnCapture(["run", join(dir, "_main.vader")], { timeoutMs: MEDIUM_BUILD });
  expect(r.stderr).toBe("");
  expect(r.exit).toBe(0);
  expect(r.stdout).toBe("quot=3\n");
  expect(existsSync(join(dir, "build/ffi"))).toBe(true);
}, LONG_BUILD);

test("an adapter that does not link stops vader run and names the extern", async () => {
  const dir = stage("argument");
  const r = await spawnCapture(["run", join(dir, "_main.vader")], { timeoutMs: MEDIUM_BUILD });
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("extern `takes_div` is called through an adapter (argument 0 passes a struct by value)");
  expect(r.stderr).toContain("build the program with `vader build`");
}, LONG_BUILD);

test("without a C compiler, vader run says the adapters need one", async () => {
  const dir = stage("result");
  const r = await spawnCapture(
    ["run", join(dir, "_main.vader")],
    { env: { CC: join(dir, "no-such-cc") }, timeoutMs: MEDIUM_BUILD },
  );
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("extern `div` is called through an adapter (it returns a struct by value)");
  expect(r.stderr).toContain("need a C compiler");
}, LONG_BUILD);
