// tests/vader_lint — end-to-end coverage for `vader lint` (the unused-export
// lint, W0012). The name-reachability engine (`dead_exports`) is exercised in
// full here through the native CLI: `load_project` → merge non-stdlib module
// decls → `dead_exports`. Colocated `vader/typecheck` @tests cover the W0007
// half of the shared engine; this drives the W0012 half end to end.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, spawnCapture, MEDIUM_BUILD } from "./cli-bin.ts";
import { withStagedLibraryRoot } from "./lib-probe.ts";
import { writeFileSync } from "node:fs";
import { join } from "node:path";

ensureCliBuilt();

const DEAD = "tests/lint_fixtures/dead_export/_main.vader";
const CLEAN = "tests/lint_fixtures/all_reached/_main.vader";

function countW0012(out: string): number {
  return (out.match(/W0012/g) ?? []).length;
}

test("vader lint flags an export unreachable from the roots", async () => {
  const { stdout, stderr, exit } = await runCli(["lint", DEAD]);
  const out = `${stdout}\n${stderr}`;
  // Exactly the one dead export — `orphan`. `reached` (called by main) and the
  // dead PRIVATE fn (W0007's job) must not surface here.
  expect(countW0012(out)).toBe(1);
  expect(out).toContain("orphan");
  expect(out).not.toContain("private_dead");
  expect(exit).toBe(1);
}, MEDIUM_BUILD);

test("vader lint is silent when every export is reached", async () => {
  const { stdout, stderr, exit } = await runCli(["lint", CLEAN]);
  const out = `${stdout}\n${stderr}`;
  expect(countW0012(out)).toBe(0);
  expect(exit).toBe(0);
}, MEDIUM_BUILD);

test("vader build never runs the unused-export lint (P-lean)", async () => {
  // The default build must not gain the lint : building the dead-export fixture
  // to C emits no W0012 (and succeeds — a dead export is not an error).
  const { stdout, stderr, exit } = await runCli(["build", "--target=c", "--out=-", DEAD]);
  const out = `${stdout}\n${stderr}`;
  expect(countW0012(out)).toBe(0);
  expect(exit).toBe(0);
}, MEDIUM_BUILD);

test("vader lint reports a usage error when no file is given", async () => {
  const { stderr, exit } = await runCli(["lint"]);
  expect(stderr).toContain("expected a file");
  expect(exit).toBe(1);
}, MEDIUM_BUILD);

test("vader lint scopes by provenance, not by a `std/` name", async () => {
  // REASON: this replaced a name test (`display_path.starts_with("std/")`) with a
  // provenance test, and the difference only shows on a shipped namespace that is
  // NOT called `std/…`. Before the library split there was none, so a fixture
  // would have passed against the old code too and pinned nothing. `lib/` now
  // hosts json, regex, toolchain and the rest — get this wrong and every user
  // project is told the toolchain's own exports are unused.
  await withStagedLibraryRoot({
    lintprobe: {
      "lintprobe.vader":
        'module "lintprobe"\n\n'
        + '/// Reached by nothing. Shipped, so out of a project\'s scope.\n'
        + 'export never_used_in_probe :: fn() -> i32 = 1\n',
    },
  }, async (dir) => {
    writeFileSync(join(dir, "app.vader"),
      'module "app"\n\nimport "std/io"\nimport "lintprobe"\n\n'
      + '/// Reached by nothing, and the project\'s own — so it IS in scope.\n'
      + 'export never_used_in_app :: fn() -> i32 = 2\n\n'
      + 'main :: fn() -> i32 {\n    println("${never_used_in_probe()}")\n    return 0\n}\n');
    // `cwd: dir` makes `<dir>/lib` the library root — that is the whole setup.
    const rel = await spawnCapture(["lint", "app.vader"], { cwd: dir });
    const relOut = rel.stdout + rel.stderr;
    expect(relOut).toContain("never_used_in_app");
    expect(relOut).not.toContain("never_used_in_probe");

    // BY ABSOLUTE PATH, from elsewhere — the case a review reproduced and this
    // test originally missed. The library root is then `<dir>/lib`, an absolute
    // path, where the first cut of `library_roots()` returned a fixed list
    // containing only the bare `"lib"`: provenance matched nothing, the whole
    // stdlib was classified as the project's own, and the run reported 24 W0012
    // naming `print`, `eprintln`, `assert_ne`… The two invocations must agree.
    writeFileSync(join(dir, "vader.json"), '{ "name": "p", "includePaths": ["lib"] }\n');
    const abs = await spawnCapture(["lint", join(dir, "app.vader")]);
    const absOut = abs.stdout + abs.stderr;
    expect(absOut).toContain("never_used_in_app");
    expect(absOut).not.toContain("never_used_in_probe");
    expect(absOut).not.toContain("eprintln");
  });
}, MEDIUM_BUILD);

test("vader lint flags a `build` that is not a driver entry", async () => {
  // REASON: W0007 roots `build` in the `build` module, as an entry point. W0012's
  // project-wide walk MERGES every module's decls, so it has no per-decl module —
  // and passing it `DRIVER_MODULE` rooted a fn named `build` ANYWHERE, silently.
  // Reproduced by a review: an unreached `export build` in `module "app"` went
  // unreported, and its refs were seeded live, hiding dead exports behind it.
  await withStagedLibraryRoot({}, async (dir) => {
    writeFileSync(join(dir, "app.vader"),
      'module "app"\n\nimport "std/io"\n\n'
      + '/// Reached by nothing, and NOT a driver entry — `app` is not `build`.\n'
      + 'export build :: fn(args: string[]) -> i32 = 7\n\n'
      + 'main :: fn() -> i32 {\n    println("x")\n    return 0\n}\n');
    const { stdout, stderr } = await spawnCapture(["lint", "app.vader"], { cwd: dir });
    expect(stdout + stderr).toContain("`build` is never used");
  });
}, MEDIUM_BUILD);
