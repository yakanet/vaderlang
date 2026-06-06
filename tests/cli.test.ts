// NOTE: still drives the TS CLI in-process. The `test` subcommand cases below
// depend on a working test runner, and native `vader test` is a stub today
// (vader/cli/main.vader::cmd_test → "not yet implemented", exit 2). Flip the
// whole file to spawn build/vader (via cli-bin's runCli) once cmd_test lands.
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

  test("test: all passing tests exit 0", async () => {
    const code = await runCli(["test", "tests/fixtures/test_cmd/passing"]);
    expect(code).toBe(0);
  });

  test("test: any failure exits 1", async () => {
    const code = await runCli(["test", "tests/fixtures/test_cmd/failing"]);
    expect(code).toBe(1);
  });

  test("test: empty / no-@test directory exits 2", async () => {
    const code = await runCli(["test", "tests/fixtures/test_cmd/empty"]);
    expect(code).toBe(2);
  });

  test("test: nonexistent path exits 2", async () => {
    const code = await runCli(["test", "tests/fixtures/test_cmd/__not_a_dir__"]);
    expect(code).toBe(2);
  });
});
