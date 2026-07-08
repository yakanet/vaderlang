// `vader build` / `vader dump` reject an unknown `--flag` instead of silently
// ignoring it. Regression for the audit's LC3: `vader build --releaze` used to
// fall through to a default (debug) build and exit 0, swallowing the typo. The
// sub-commands now parse strictly (std/cli::parse), so an unrecognised flag is
// an error — global options are stripped before dispatch, so nothing valid
// leaks into the sub-command parser.

import { test, expect } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { runCli, MEDIUM_BUILD } from "./cli-bin.ts";

const TRIVIAL = `module "scratch"\nmain :: fn() -> i32 {\n    return 0\n}\n`;

test("build/dump reject an unknown flag; valid flags still work", async () => {
  const dir = mkdtempSync(join(tmpdir(), "vader-cli-flag-"));
  try {
    const file = join(dir, "prog.vader");
    writeFileSync(file, TRIVIAL);

    // A typo'd flag on `build` is an error, not a silent debug build.
    const badBuild = await runCli(["build", file, "--releaze", "--target=c", "--out=-"], undefined, MEDIUM_BUILD);
    expect(badBuild.exit).not.toBe(0);
    expect(badBuild.stderr).toContain("unknown flag --releaze");

    // A typo'd flag on `dump` is an error too.
    const badDump = await runCli(["dump", "--stagee=lexer", file], undefined, MEDIUM_BUILD);
    expect(badDump.exit).not.toBe(0);
    expect(badDump.stderr).toContain("unknown flag --stagee");

    // The correctly-spelled flags still work (no over-rejection).
    const okBuild = await runCli(["build", file, "--release", "--target=c", "--out=-"], undefined, MEDIUM_BUILD);
    expect(okBuild.exit).toBe(0);

    const okDump = await runCli(["dump", "--stage=lexer", file], undefined, MEDIUM_BUILD);
    expect(okDump.exit).toBe(0);
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}, MEDIUM_BUILD);
