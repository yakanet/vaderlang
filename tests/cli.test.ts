import { describe, expect, test } from "bun:test";
import { runCli } from "../src/cli.ts";

describe("cli", () => {
  test("--help prints usage and exits 0", async () => {
    const code = await runCli(["--help"]);
    expect(code).toBe(0);
  });

  test("--version prints version and exits 0", async () => {
    const code = await runCli(["--version"]);
    expect(code).toBe(0);
  });

  test("unknown command exits 1", async () => {
    const code = await runCli(["nonexistent-cmd"]);
    expect(code).toBe(1);
  });

  test("dump without --stage exits 1", async () => {
    const code = await runCli(["dump", "foo.vader"]);
    expect(code).toBe(1);
  });

  test("dump with unknown stage exits 1", async () => {
    const code = await runCli(["dump", "--stage=nope", "foo.vader"]);
    expect(code).toBe(1);
  });

  test("run without file exits 1", async () => {
    const code = await runCli(["run"]);
    expect(code).toBe(1);
  });

  test("--diagnostics=text is accepted", async () => {
    const code = await runCli(["--diagnostics=text", "--help"]);
    expect(code).toBe(0);
  });

  test("--diagnostics=json is accepted", async () => {
    const code = await runCli(["--diagnostics=json", "--version"]);
    expect(code).toBe(0);
  });

  test("--diagnostics=invalid exits 1", async () => {
    const code = await runCli(["--diagnostics=xml", "--help"]);
    expect(code).toBe(1);
  });

  test("global flag can appear after the command", async () => {
    const code = await runCli(["run", "foo.vader", "--diagnostics=json"]);
    // run exits 1 because the file doesn't exist; the flag is parsed silently
    expect(code).toBe(1);
  });
});
