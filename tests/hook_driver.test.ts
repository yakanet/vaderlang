// tests/hook_driver — end-to-end coverage for the build driver: `vader build`
// with no file argument, finding and running a project's own `build.vader`.
//
// A driven project is a whole-project shape, not a pipeline-stage snapshot, so
// it belongs beside `lint_fixtures/` rather than in `snippets/` — hence a corpus
// of its own under `tests/hook_fixtures/`. Each fixture is a real project
// directory the CLI is run *inside*, since the driver is discovered relative to
// the invocation directory.
//
// The driver compiles itself before running, so these are the slowest tests in
// the suite by a wide margin: budget accordingly rather than trimming coverage.

import { test, expect, afterAll } from "bun:test";
import { rmSync, writeFileSync, readFileSync, cpSync, mkdtempSync, symlinkSync, existsSync } from "node:fs";
import { resolve } from "node:path";
import { tmpdir } from "node:os";
import { ensureCliBuilt, CLI_BIN, LONG_BUILD } from "./cli-bin.ts";

ensureCliBuilt();

const CLI = resolve(CLI_BIN);
const FIXTURES = "tests/hook_fixtures";
const LINT = `${FIXTURES}/pascal_case_lint`;

// A driven build needs `stdlib/`, `runtime/c/` and `vader/` reachable from the
// project: the first two because the compiler resolves them beside the binary or
// relative to the invocation directory, the third because a driver imports
// `vader/hooks`. That is the layout a `dist/` bundle ships, so each run stages
// the fixture into a temp directory and symlinks the three in — reproducing an
// installed toolchain without polluting the checkout, and without touching
// `resolve_sidecar`, which the rest of the suite depends on.
const REPO = resolve(".");

function stage(fixture: string): string {
  const dir = mkdtempSync(`${tmpdir()}/vader-hook-`);
  cpSync(fixture, dir, { recursive: true });
  for (const name of ["stdlib", "runtime", "vader"]) {
    symlinkSync(`${REPO}/${name}`, `${dir}/${name}`);
  }
  return dir;
}

const staged: string[] = [];

async function runIn(fixture: string, args: string[]) {
  const dir = stage(fixture);
  staged.push(dir);
  const proc = Bun.spawn([CLI, ...args], { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [stdout, stderr, exit] = await Promise.all([
    new Response(proc.stdout).text(),
    new Response(proc.stderr).text(),
    proc.exited,
  ]);
  return { out: `${stdout}\n${stderr}`, exit };
}

afterAll(() => {
  for (const dir of staged) {
    rmSync(dir, { recursive: true, force: true });
  }
});

test("the driven build leaves no artefact in the project root", async () => {
  // Artefacts belong under `build/`, and the entry shim must be unlinked rather
  // than blanked — a leftover `.vader` declaring nothing would break the next run.
  const dir = stage(LINT);
  staged.push(dir);
  const proc = Bun.spawn([CLI, "build"], { cwd: dir, stdout: "pipe", stderr: "pipe" });
  await proc.exited;
  expect(existsSync(`${dir}/vader_build_entry.vader`)).toBe(false);
  expect(existsSync(`${dir}/vader_build_driver`)).toBe(false);
  expect(existsSync(`${dir}/build/driver/driver`)).toBe(true);
}, LONG_BUILD);

test("a project's build.vader runs and reports its own rule", async () => {
  const { out } = await runIn(LINT, ["build"]);
  // The rule fired on the offending struct, anchored in the project's source
  // rather than in the generated entry.
  expect(out).toContain("H6004");
  expect(out).toContain("badlyNamed");
  expect(out).toMatch(/src\/main\.vader:\d+:\d+/);
  // …and discriminates: the compliant struct is not reported.
  expect(out).not.toContain("WellNamed");
  expect(out).toContain("1 rule violation(s)");
}, LONG_BUILD);

test("the driver sees project modules, not just the stdlib", async () => {
  // `messages()` yields every typed module; the fixture filters on
  // `module_name`. If that field carried the loader's filesystem key instead of
  // the declared name, the filter would match nothing and the rule would run
  // over the stdlib too — which is exactly the bug this pins.
  const { out } = await runIn(LINT, ["build"]);
  expect(out).not.toContain("std/io");
  expect(out).toContain("badlyNamed");
}, LONG_BUILD);

test("a build.vader with no `build` fn is rejected as H6001", async () => {
  const driver = `${LINT}/build.vader`;
  const original = readFileSync(driver, "utf8");
  writeFileSync(driver, 'module "build"\n\nother :: fn() -> void {}\n');
  try {
    const { out, exit } = await runIn(LINT, ["build"]);
    expect(out).toContain("H6001");
    // Anchored on the driver itself, not on the generated entry.
    expect(out).toMatch(/build\.vader:\d+:\d+/);
    expect(out).not.toContain("vader_build_entry");
    expect(exit).not.toBe(0);
  } finally {
    writeFileSync(driver, original);
  }
}, LONG_BUILD);

test("a `build` of the wrong arity is rejected as H6002", async () => {
  const driver = `${LINT}/build.vader`;
  const original = readFileSync(driver, "utf8");
  writeFileSync(driver, 'module "build"\n\nbuild :: fn() -> void {}\n');
  try {
    const { out, exit } = await runIn(LINT, ["build"]);
    expect(out).toContain("H6002");
    expect(exit).not.toBe(0);
  } finally {
    writeFileSync(driver, original);
  }
}, LONG_BUILD);

test("`vader build` without a driver still asks for a file", async () => {
  // The default path must be untouched: no `build.vader` in this fixture, so the
  // CLI keeps its own error — now naming the driver as a third option.
  const { out, exit } = await runIn(`${FIXTURES}/no_driver`, ["build"]);
  expect(out).toContain("expected a file");
  expect(out).toContain("build.vader");
  expect(exit).toBe(1);
}, LONG_BUILD);
