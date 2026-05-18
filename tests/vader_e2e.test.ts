// End-to-end `vader test` smoke tests. Each `@test` fn is appended at the
// bottom of its own stdlib / self-host module (Rust-style colocation) ;
// the runner walks the target directory, builds each entry through the
// normal pipeline, and runs the discovered tests via the bytecode VM.

import { test, expect } from "bun:test";
import { runCli } from "../src/cli.ts";
import { LONG_BUILD } from "./cli-bin.ts";

test("vader test stdlib — every @test fn in the stdlib passes", async () => {
  const code = await runCli(["test", "stdlib"]);
  expect(code).toBe(0);
});

test("vader test vader — every @test fn in the self-host tree passes", async () => {
  const code = await runCli(["test", "vader"]);
  expect(code).toBe(0);
}, { timeout: LONG_BUILD });
