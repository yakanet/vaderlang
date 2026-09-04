// The CLI's argument boundary and its strictness, end to end.
//
// One rule: an action's options come before its first positional argument, and
// everything after that belongs to whatever the action hands it to. That is what
// lets the CLI be strict — before it, the boundary depended on flag
// *recognition*, so `vader run` could never reject an unknown token (it might
// have been meant for the program) and `vader build --releaze` fell through to a
// default debug build, exit 0, typo swallowed.
//
// Covers, per test below: unknown flags on both dash lengths, options written
// after the file, the forwarding boundary on `run`, and the generated help.
// The parser's own unit tests live in `lib/std/cli/cli.vader`.

import { test, expect } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { runCli, MEDIUM_BUILD } from "./cli-bin.ts";

const TRIVIAL = `module "scratch"\nmain :: fn() -> i32 {\n    return 0\n}\n`;

const ECHO_ARGV = `module "scratch"

import "std/io"

main :: fn(argv: string[]) -> i32 {
    for i in 1..<argv.len() {
        println(argv[i])
    }
    return 0
}
`;

function withScratch<T>(body: (file: string) => Promise<T>): Promise<T> {
  const dir = mkdtempSync(join(tmpdir(), "vader-cli-flag-"));
  const file = join(dir, "prog.vader");
  writeFileSync(file, TRIVIAL);
  return body(file).finally(() => rmSync(dir, { recursive: true, force: true }));
}

test("an unknown flag is rejected, a correct one still works", async () => {
  await withScratch(async (file) => {
    const badBuild = await runCli(["build", "--releaze", "--emit=c", "--out=-", file], undefined, MEDIUM_BUILD);
    expect(badBuild.exit).not.toBe(0);
    expect(badBuild.stderr).toContain("unknown flag --releaze");

    const badDump = await runCli(["dump", "--stagee=lexer", file], undefined, MEDIUM_BUILD);
    expect(badDump.exit).not.toBe(0);
    expect(badDump.stderr).toContain("unknown flag --stagee");

    // No over-rejection.
    const okBuild = await runCli(["build", "--release", "--emit=c", "--out=-", file], undefined, MEDIUM_BUILD);
    expect(okBuild.exit).toBe(0);
    const okDump = await runCli(["dump", "--stage=lexer", file], undefined, MEDIUM_BUILD);
    expect(okDump.exit).toBe(0);
  });
}, MEDIUM_BUILD);

test("a single-dash token is rejected too, not taken for a filename", async () => {
  await withScratch(async (file) => {
    // The gap that littered 384 stray `.c` files across the snippet corpus:
    // `-o` is not a flag `build` knows (its alias is, but `-q` isn't), and a
    // single-dash token used to be assumed positional and dropped in silence.
    const bad = await runCli(["build", "-q", "--emit=c", "--out=-", file], undefined, MEDIUM_BUILD);
    expect(bad.exit).not.toBe(0);
    expect(bad.stderr).toContain("unknown flag -q");
  });
}, MEDIUM_BUILD);

test("an option written after the file says so", async () => {
  await withScratch(async (file) => {
    // The boundary leaves it in the tail rather than reading it, and `build`
    // takes one positional — so the message names the likely cause instead of
    // reporting a mysterious extra argument.
    const late = await runCli(["build", file, "--release", "--emit=c", "--out=-"], undefined, MEDIUM_BUILD);
    expect(late.exit).not.toBe(0);
    expect(late.stderr).toContain("options must come before the file");
  });
}, MEDIUM_BUILD);

test("an unknown value names the accepted set", async () => {
  await withScratch(async (file) => {
    // `--stage`'s twelve values live in one array in `vader/cli/spec.vader`,
    // which drives the validation, this message and the help alike.
    const bad = await runCli(["dump", "--stage=nope", file], undefined, MEDIUM_BUILD);
    expect(bad.exit).not.toBe(0);
    expect(bad.stderr).toContain('unknown value "nope"');
    expect(bad.stderr).toContain("bytecode");
  });
}, MEDIUM_BUILD);

test("an alias and a spaced value are the same flag", async () => {
  await withScratch(async (file) => {
    const spelled = await runCli(["dump", "--stage=lexer", file], undefined, MEDIUM_BUILD);
    const aliased = await runCli(["dump", "-s", "lexer", file], undefined, MEDIUM_BUILD);
    const spaced = await runCli(["dump", "--stage", "lexer", file], undefined, MEDIUM_BUILD);
    expect(aliased.exit).toBe(0);
    expect(aliased.stdout).toBe(spelled.stdout);
    expect(spaced.stdout).toBe(spelled.stdout);
  });
}, MEDIUM_BUILD);

test("run forwards everything past the path, flags included", async () => {
  const dir = mkdtempSync(join(tmpdir(), "vader-cli-fwd-"));
  try {
    const file = join(dir, "echo.vader");
    writeFileSync(file, ECHO_ARGV);

    // `--allow-env` is a flag the CLI itself declares, and it must still reach
    // the program: past the path, the CLI reads nothing. It used to be stripped
    // wherever it appeared, so the program never saw it.
    const { stdout, exit } = await runCli(
      ["run", file, "--allow-env", "-o", "out.txt", "extra"],
      undefined,
      MEDIUM_BUILD,
    );
    expect(exit).toBe(0);
    expect(stdout.trim().split("\n")).toEqual(["--allow-env", "-o", "out.txt", "extra"]);
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}, MEDIUM_BUILD);

test("--help on an action prints that action's options", async () => {
  // What anyone types. `vader help build` works too, but this is the reflex, and
  // it exits 0 — asking for help is a success, not a usage error.
  const viaFlag = await runCli(["build", "--help"], undefined, MEDIUM_BUILD);
  expect(viaFlag.exit).toBe(0);
  expect(viaFlag.stdout).toContain("vader build <file>");
  expect(viaFlag.stdout).toContain("-o, --out=<path>");

  // The alias, and the same text either way.
  const viaAlias = await runCli(["build", "-h"], undefined, MEDIUM_BUILD);
  expect(viaAlias.stdout).toBe(viaFlag.stdout);
  const viaAction = await runCli(["help", "build"], undefined, MEDIUM_BUILD);
  expect(viaAction.stdout).toBe(viaFlag.stdout);

  // A typo alongside `--help` gets the help, not the complaint: that is what
  // the person is asking for.
  const withTypo = await runCli(["build", "--nope", "--help"], undefined, MEDIUM_BUILD);
  expect(withTypo.exit).toBe(0);
  expect(withTypo.stdout).toContain("vader build <file>");
}, MEDIUM_BUILD);

test("--help past a run path belongs to the program", async () => {
  const dir = mkdtempSync(join(tmpdir(), "vader-cli-help-fwd-"));
  try {
    const file = join(dir, "echo.vader");
    writeFileSync(file, ECHO_ARGV);

    // The boundary's payoff: a program run under `vader run` keeps its own
    // `--help`. Before the zone existed, the CLI would have had to choose.
    const { stdout, exit } = await runCli(["run", file, "--help"], undefined, MEDIUM_BUILD);
    expect(exit).toBe(0);
    expect(stdout.trim()).toBe("--help");
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}, MEDIUM_BUILD);

test("help is generated per action, not one flat string", async () => {
  // `vader build --help` had no answer at all before: a single hand-written
  // help string can't render one action in isolation.
  const overview = await runCli(["help"], undefined, MEDIUM_BUILD);
  expect(overview.exit).toBe(0);
  expect(overview.stdout).toContain("ACTIONS:");
  expect(overview.stdout).toContain("build <file>");

  const perAction = await runCli(["help", "build"], undefined, MEDIUM_BUILD);
  expect(perAction.exit).toBe(0);
  expect(perAction.stdout).toContain("-o, --out=<path>");
  // A flag's declared default is surfaced rather than described in prose.
  expect(perAction.stdout).toContain("(default: cc, or gcc on Windows)");
  // The overview stays an overview: it points at this view instead of inlining
  // every flag of every action.
  expect(overview.stdout).not.toContain("--ldflags");

  const unknown = await runCli(["help", "nope"], undefined, MEDIUM_BUILD);
  expect(unknown.exit).not.toBe(0);
}, MEDIUM_BUILD);
