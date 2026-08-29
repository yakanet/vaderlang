// tests/target_model — coverage for the `@target` mechanism: one declaration,
// several bodies, one chosen per compilation target.
//
// The fixtures ran skipped while the mechanism was being built, guarded by a test
// that FAILED the day `dump --stage=targets` started working — which is how they
// came to be un-skipped rather than forgotten. The tree has already paid for
// tests that silently did not run (152 gated formatter tests that REGISTERED and
// PASSED while asserting nothing, TODO §"tests/ is a catch-all"), and a skip
// nobody removes is the same failure wearing a different hat.
//
// WHY A CORPUS OF ITS OWN, and not one of the five in CLAUDE §11:
//
//   - not `diag_corpus/` — that harness provokes a diagnostic by dumping ONE
//     file (`vader dump --stage=lowered-ast <file>`). `@target` is multi-file by
//     nature: a declaration in one file, a body in another. This is the exact
//     argument CLAUDE §12 already makes for the `H6xxx` family living in
//     `hook_fixtures/`.
//   - not `snippets/` — a snippet carries a `c.snapshot` and a `vm.snapshot` per
//     pipeline stage, and those would become target-dependent. The plan pins the
//     invariant "no snippet in the corpus reaches a module that selects"; putting
//     these here would break it on the first fixture.
//
// CORPUS-DRIVEN, in the shape of `hook_driver.test.ts`: what a fixture asserts
// lives BESIDE it, not in this file.
//
//   <fixture>/*.vader                  the project — declaration and bodies
//   <fixture>/<os>-<arch>.snapshot     what that target produces
//   <fixture>/all.snapshot             same output on every target (diagnostics
//                                      that do not depend on the selection)
//   <fixture>/_diag_*                  prefix for diagnostic-only fixtures,
//                                      borrowed from `snippets/`
//
// A snapshot has three sections, and the middle one is why this corpus needs a
// dedicated dump stage rather than reading the emitted C:
//
//   # Diagnostics     what the compiler reported
//   # Selected body   `<module>$<fn> <- <file>:<line>` — one line per group
//   # Run             stdout, only where the target is executable HERE
//
// ORACLES. `# Selected body` comes from `vader dump --stage=targets --target=X`,
// which needs no toolchain and therefore answers for EVERY target from ANY
// machine — that is what makes this corpus runnable in CI as it stands. `# Run`
// cannot: it needs the real platform. Linux comes from a throwaway container
// (`docker run --rm -v "$PWD:/w" -w /w debian:bookworm-slim` — bookworm and not
// alpine, because the CI is glibc and an oracle that diverges from CI on the libc
// is not an oracle), Windows from `tools/windows-vm` (`vwin build`, `vwin test`).
// Neither is wired here yet; `# Run` is asserted only for the host target.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { snapshotDiff } from "./diff.ts";
import { readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { join } from "node:path";

// Registers a `beforeAll`, so it belongs at module scope — calling it inside a
// test is a hard error in Bun.
ensureCliBuilt();

const CORPUS = join(import.meta.dir, "target_fixtures");

/** A target triple a snapshot may be named after. Mirrors the plan's §2 table. */
const KNOWN_TARGETS = new Set([
  "darwin-arm64",
  "darwin-x86_64",
  "linux-x86_64",
  "linux-arm64",
  "windows-x86_64",
  "wasi-wasm32",
  "browser-wasm32",
]);

type Fixture = {
  name: string;
  dir: string;
  /** Target name → snapshot path. `all` means "every target, same output". */
  snapshots: Map<string, string>;
};

function discoverFixtures(): Fixture[] {
  return readdirSync(CORPUS)
    .filter((n) => statSync(join(CORPUS, n)).isDirectory())
    .sort()
    .map((name) => {
      const dir = join(CORPUS, name);
      const snapshots = new Map<string, string>();
      for (const f of readdirSync(dir)) {
        if (!f.endsWith(".snapshot")) continue;
        snapshots.set(f.slice(0, -".snapshot".length), join(dir, f));
      }
      return { name, dir, snapshots };
    });
}

const FIXTURES = discoverFixtures();

// ---- the two tests that must never be skipped -----------------------------

// Pins the corpus against the mistakes nothing else can catch while the fixture
// tests are skipped: a fixture with no snapshot at all, a snapshot named after a
// target that does not exist (a typo in `windows-x86_64` would otherwise sit
// there for months), and a snapshot missing a section the driver will read.
test("corpus is well-formed", () => {
  expect(FIXTURES.length).toBeGreaterThan(0);
  const problems: string[] = [];

  for (const fx of FIXTURES) {
    const sources = readdirSync(fx.dir).filter((f) => f.endsWith(".vader"));
    if (sources.length === 0) problems.push(`${fx.name}: no .vader source`);
    if (fx.snapshots.size === 0) problems.push(`${fx.name}: no snapshot`);

    for (const [target, path] of fx.snapshots) {
      if (target !== "all" && !KNOWN_TARGETS.has(target)) {
        problems.push(`${fx.name}: snapshot names an unknown target '${target}'`);
      }
      const body = readFileSync(path, "utf8");
      for (const section of ["# Diagnostics", "# Selected body", "# Baked"]) {
        if (!body.includes(section)) {
          problems.push(`${fx.name}/${target}: snapshot has no '${section}' section`);
        }
      }
    }
    // `all.snapshot` is "same on every target" — mixing it with per-target ones
    // would leave which wins undefined.
    if (fx.snapshots.has("all") && fx.snapshots.size > 1) {
      problems.push(`${fx.name}: has both all.snapshot and per-target snapshots`);
    }
  }

  expect(problems).toEqual([]);
});

// The oracle answers for a platform it is not running on — that is the property
// the whole corpus depends on, so it is asserted directly rather than assumed by
// every fixture below.
test("the oracle answers for a foreign target", async () => {
  const probe = await runCli(
    ["dump", "--stage=targets", "--target=windows-x86_64",
     join(CORPUS, "body_selection", "main.vader")],
    undefined,
    MEDIUM_BUILD,
  );
  expect(probe.exit).toBe(0);
  expect(probe.stdout).toContain("main-windows.vader");
});

// ---- the fixture tests -----------------------------------------------------

for (const fx of FIXTURES) {
  for (const [target, snapshotPath] of fx.snapshots) {
    const label = target === "all" ? "every target" : target;

    test(`${fx.name} — ${label}`, async () => {
      const expected = readFileSync(snapshotPath, "utf8");
      // Options BEFORE the positional: the CLI has one boundary rule and a flag
      // after the file is rejected, not ignored.
      const entry = join(fx.dir, "main.vader");
      const args = ["dump", "--stage=targets"];
      if (target !== "all") args.push(`--target=${target}`);
      args.push(entry);

      const { stdout, exit } = await runCli(args, undefined, MEDIUM_BUILD);
      expect(exit).toBe(0);

      // Diagnostics come from a SECOND run that actually type-checks. The
      // `targets` stage stops at load — it answers "which body", not "is it
      // well-typed" — so asking it for diagnostics would report `(none)` for a
      // body with a deliberate type error, which is precisely what
      // `discarded_body_not_typed` exists to catch.
      const checkArgs = ["build", "--emit=c", "--out=-"];
      if (target !== "all") checkArgs.push(`--target=${target}`);
      checkArgs.push(entry);
      const checked = await runCli(checkArgs, undefined, MEDIUM_BUILD);

      const actual = renderSections(stdout, checked.stderr, fx.dir);
      if (process.env["UPDATE_SNAPSHOTS"] === "1") {
        writeFileSync(snapshotPath, actual);
        return;
      }
      if (actual !== expected) {
        throw new Error(snapshotDiff(`${fx.name}/${label}`, expected, actual));
      }
    });
  }
}

/**
 * Assemble the snapshot text from a run. Kept here rather than in the fixtures
 * so the SHAPE of a snapshot is defined once; what each fixture asserts still
 * lives beside it.
 */
function renderSections(stdout: string, stderr: string, fixtureDir: string): string {
  // The compiler reports the path it was GIVEN, which the driver passes
  // absolute. Snapshots have to be portable, so the fixture directory is
  // stripped here rather than having the stage lie about what it read.
  //
  // Both separators, and that is not defensive coding: `join()` yields
  // `C:\vader\tests\…` on Windows while the compiler normalises every path it
  // reports to `/` (the resolver keeps one internal separator). Matching only
  // the platform form left absolute paths in the snapshots — a failure invisible
  // on macOS and caught on the Windows guest.
  const posixDir = fixtureDir.split("\\").join("/");
  // Diagnostics now name a path RELATIVE to the working directory when the file
  // is under it (`vader/diagnostics/render.vader`), so the repo-relative form
  // has to be stripped as well — without it these snapshots grew a
  // `tests/target_fixtures/<name>/` prefix on every line.
  const relDir = posixDir.split("/").slice(-3).join("/");
  const strip = (s: string) =>
    s
      .split(`${fixtureDir}/`).join("")
      .split(`${posixDir}/`).join("")
      .split(`${relDir}/`).join("");
  // `build` prints its own `# Diagnostics` banner; the section header belongs to
  // the snapshot format, so the banner is dropped rather than nested.
  const raw = strip(stderr.trim()).replace(/^# Diagnostics\n?/, "").trim();
  const diagnostics = raw === "" ? "(none)" : raw;
  return `# Diagnostics\n${diagnostics}\n\n${strip(stdout.trim())}\n`;
}
