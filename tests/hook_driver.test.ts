// tests/hook_driver — end-to-end coverage for the build driver: `vader build`
// with no file argument, finding and running a project's own `build.vader`.
//
// A driven project is a whole-project shape, not a pipeline-stage snapshot, so
// it belongs beside `lint_fixtures/` rather than in `snippets/` — hence a corpus
// of its own under `tests/hook_fixtures/`. Each fixture is a real project
// directory the CLI is run *inside*, since the driver is discovered relative to
// the invocation directory.
//
// CORPUS-DRIVEN, in the shape of `snapshot.test.ts`: what a fixture asserts lives
// BESIDE it, not in this file.
//
//   <fixture>/build.vader          the driver under test
//   <fixture>/src/*.vader          the project — and its `@test` fns
//   <fixture>/build.snapshot       the driven build's output + exit status
//   <fixture>/generated.snapshot   the text the driver GENERATED, where it does
//
// The `@test` half is what makes generated code provable in Vader instead of by
// string-matching a binary's stdout from TypeScript: once `build/generated/`
// exists it becomes a MERGE ROOT for the resolver
// (`vader/resolver/module.vader::GENERATED_ROOT_DIR`), so a hand-written test
// calls generated functions like any other — in both shapes, an imported
// generated module and one that joined the entry module. Run `vader test src`
// WITHOUT building first and the same test fails `R2006`, which is what makes the
// ordering a proof rather than a convention.
//
// The driver compiles itself before running, so these are the slowest tests in
// the suite by a wide margin: budget accordingly rather than trimming coverage.
//
// Every test here is `test.concurrent`, and that is not a per-test call: Bun
// overlaps a RUN of adjacent concurrent tests, so one plain `test` left between
// two of them is a barrier that serialises the whole file again. With the driver
// builds overlapping instead of queueing, the file goes from 57 s to 18 s
// locally. Two consequences, both load bearing: every run goes through `gated()`
// below, and every budget is `HEAVY_BUILD` — a test's wall clock now includes its
// wait for a slot.

import { test, expect, afterAll } from "bun:test";
import { rmSync, writeFileSync, readFileSync, readdirSync, mkdirSync, cpSync, mkdtempSync, symlinkSync, existsSync, realpathSync } from "node:fs";
import { withStagedLibraryRoot } from "./lib-probe.ts";
import { basename, join, resolve } from "node:path";
import { tmpdir } from "node:os";
import { ensureCliBuilt, CLI_BIN, EXE_SUFFIX, HEAVY_BUILD, exePath, spawnCapture } from "./cli-bin.ts";
import type { CliResult, SpawnOptions } from "./cli-bin.ts";
import { formatRun, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { containsTestFn } from "./vader-sources.ts";

ensureCliBuilt();

const FIXTURES = "tests/hook_fixtures";
const LINT = `${FIXTURES}/pascal_case_lint`;
const GENERATE = `${FIXTURES}/generate_module`;
const JSON_DERIVE = `${FIXTURES}/json_derive`;

// A driven build needs `lib/`, `runtime/c/` and `vader/` reachable from the
// project: the first two because the compiler resolves them beside the binary or
// relative to the invocation directory, the third because a driver imports
// `toolchain/build`. That is the layout a `dist/` bundle ships, so each run stages
// the fixture into a temp directory and symlinks the three in — reproducing an
// installed toolchain without polluting the checkout, and without touching
// `resolve_sidecar`, which the rest of the suite depends on.
const REPO = resolve(".");

// What a driven build needs beside the project. Named once because two places
// read it in opposite directions: `stage()` links these in, and the bundle test
// asserts their ABSENCE — a drift between the two would quietly weaken the very
// thing that test pins.
const TOOLCHAIN_LINKS = ["lib", "runtime", "vader"] as const;

// The staged copy starts CLEAN. Nothing under `build/` is committed, but a dev who
// ran `vader build` inside a fixture leaves a driver binary and its C there, and
// copying that in would have the build reuse a stale driver — and would give the
// sweep something to sweep in every fixture instead of only where one is planted
// deliberately.
function copyFixture(fixture: string, dir: string): void {
  cpSync(fixture, dir, { recursive: true });
  rmSync(join(dir, "build"), { recursive: true, force: true });
}

function stage(fixture: string): string {
  const dir = mkdtempSync(`${tmpdir()}/vader-hook-`);
  copyFixture(fixture, dir);
  for (const name of TOOLCHAIN_LINKS) {
    symlinkSync(`${REPO}/${name}`, `${dir}/${name}`);
  }
  return dir;
}

const staged: string[] = [];

afterAll(() => {
  for (const dir of staged) {
    rmSync(dir, { recursive: true, force: true });
  }
});

// ---- the gate --------------------------------------------------------------

// Slots for driver builds in flight. Measured on this file, 14-core Mac:
//
//   cap=1   56,1 s wall / 75,1 s CPU      cap=4   18,4 s / 85,8 s
//   cap=2   29,3 s      / 77,4 s          cap=8   14,3 s / 86,3 s
//
// So oversubscription costs ~15 % CPU and buys back near-linear wall time: the
// cap is about MEMORY, not scheduling. One driver build peaks at 815 MB RSS
// (`VADER_PROFILE=1`, `pascal_case_lint`) and fans out to `DRIVER_CC_UNITS` = 8
// parallel `cc` — so four in flight is already ~3 GB and ~40 processes, which is
// as far as a 16 GB CI runner should be pushed. Bun applies no cap of its own.
//
// `VADER_TEST_GATE` overrides it — that is how the table above was taken, and
// how to retake it on another machine.
//
// FIFO, and `while` rather than `if` on the check: a waiter woken by the
// `finally` resolves on a microtask, so a caller arriving synchronously in
// between can take the freed slot first. Re-checking is what keeps the cap
// honest.
const MAX_DRIVER_BUILDS = gateSize();

function gateSize(): number {
  const raw = Number(process.env["VADER_TEST_GATE"]);
  return Number.isInteger(raw) && raw > 0 ? raw : 4;
}
let inFlight = 0;
const waiting: (() => void)[] = [];

async function gated<T>(work: () => Promise<T>): Promise<T> {
  while (inFlight >= MAX_DRIVER_BUILDS) {
    await new Promise<void>(resolve => waiting.push(resolve));
  }
  inFlight++;
  try {
    return await work();
  } finally {
    inFlight--;
    waiting.shift()?.();
  }
}

// Every binary this file drives goes through `cli-bin.ts::spawnCapture` — one
// pipe drain, one kill timer — with the budget a driver build needs rather than
// the 90 s default.
//
// `run` is for anything that COMPILES, and takes a gate slot. `runBinary` is for
// executing something already linked: milliseconds and no memory to speak of, so
// making it queue behind four whole-compiler builds would impose a latency the
// gate exists to prevent, not to cause.
type RunOptions = Omit<SpawnOptions, "timeoutMs"> & { cwd: string };

function run(args: string[], opts: RunOptions) {
  return gated(() => spawnCapture(args, { ...opts, timeoutMs: HEAVY_BUILD }));
}

function runBinary(bin: string, cwd: string, env?: Record<string, string>) {
  return spawnCapture([], { bin, cwd, env, timeoutMs: HEAVY_BUILD });
}

// ---- the corpus ------------------------------------------------------------

interface Built extends CliResult {
  readonly dir: string;
}

// One driven build per fixture, started lazily and shared: the corpus test
// asserts on its output, and a hand-written test below can await the same build
// by name instead of paying a second whole-compiler compile.
//
// ⚠️ Everything awaiting a shared build only READS the staged tree. A test that
// WRITES there stages privately (the stale-sweep one does) — otherwise the
// failure surfaces in a neighbour that did nothing wrong.
const builds = new Map<string, Promise<Built>>();

function drivenBuild(name: string): Promise<Built> {
  let pending = builds.get(name);
  if (pending === undefined) {
    pending = (async () => {
      const dir = stage(`${FIXTURES}/${name}`);
      staged.push(dir);
      const r = await run(["build"], { cwd: dir });
      return { dir, ...r };
    })();
    builds.set(name, pending);
  }
  return pending;
}

// Neither the staged directory nor a generated filename can appear in a committed
// expectation: the first is a fresh `mkdtemp` per run, the second carries a
// content hash. `realpathSync` too — macOS reports `/private/var/…` for the
// `/var/…` that `mkdtemp` handed back, and the CLI prints the resolved form.
function normalise(text: string, dir: string): string {
  // One spelling before any matching. Windows prints `\`, and `mkdtemp` hands
  // back a MIX (`C:\…\Temp/vader-hook-x`), so converting both sides first is
  // what keeps the substitution from missing entirely and leaving a
  // machine-specific path in a committed expectation.
  const slash = (p: string) => p.replaceAll("\\", "/");
  // Longest path FIRST: macOS hands back `/var/folders/…` and reports
  // `/private/var/folders/…`, so replacing the short form first would leave
  // `/private<project>` behind.
  const real = slash(realpathSync(dir));
  let out = slash(text).replaceAll(real, "<project>");
  out = out.replaceAll(slash(dir), "<project>");
  if (EXE_SUFFIX !== "") {
    // The LINKER names the binary, so a `wrote <project>/hello` line reads
    // `hello.exe` on Windows. One spelling in the expectation, and a no-op off
    // Windows since the suffix is empty there.
    out = out.replaceAll(EXE_SUFFIX, "");
  }
  return out
    .replace(/_[0-9a-f]{8,}\.vader/g, "_<hash>.vader")
    // How the driver's own binary got linked is machine-dependent: the split
    // count follows the core count, and a single-unit build words the line
    // differently. What the expectation is about is that it was written at all.
    .replace(/^(vader build: wrote <project>\/build\/driver\/driver).*$/gm, "$1");
}

// Where a driven build writes its generated modules, relative to the project —
// `vader/resolver/module.vader::GENERATED_ROOT_DIR`, which the resolver reads.
const GENERATED = "build/generated";

// A generated tree as one text blob: sorted `--- <relpath>` headers plus each
// file's contents. Names carry a content hash, so a changed generator shows up
// twice over — in the name and in the body.
function readGeneratedTree(root: string): string {
  const base = join(root, GENERATED);
  if (!existsSync(base)) {
    return "";
  }
  return (readdirSync(base, { recursive: true }) as string[])
    .filter(p => p.endsWith(".vader"))
    .map(p => p.replaceAll("\\", "/"))
    .sort()
    .map(p => `--- ${p}\n${readFileSync(join(base, p), "utf8")}`)
    .join("");
}

// What the driver GENERATED, pinned as text beside the fixture rather than as
// files inside it: nothing that comes out of a build belongs in git, and
// `build/generated/` is build output. The snapshot keeps what mattered anyway —
// the generator's own text, reviewable in a diff instead of only its stdout.
//
// The cost, stated because it will bite the next reader: an editor flags the
// fixtures' calls into generated code as unresolved. Resolving them needs the
// tree ON DISK (the resolver treats `build/generated/` as a merge root when it
// exists), and it only ever exists inside a staged build.
//
// Only for a build that SUCCEEDED: a failed build's tree is whatever its last
// round happened to write (`generation_never_settles`), which is noise. And only
// where there is something to say — an empty expectation in the fixtures that
// generate nothing would be eight files saying nothing.
function expectGeneratedTree(fixture: string, dir: string): void {
  const actual = readGeneratedTree(dir);
  const snapName = "generated.snapshot";
  if (actual === "" && !existsSync(join(fixture, snapName))) {
    return;
  }
  const snap = snapshotEquals(fixture, snapName, actual);
  if (!snap.ok) {
    throw new Error(
      `Generated text differs from ${snap.snapPath}\n` +
      `Run with UPDATE_SNAPSHOTS=1 to refresh — and READ the diff: this is the ` +
      `generator's own output.\n\n` +
      snapshotDiff(snap.snapPath, snap.expected, actual),
    );
  }
}

// Does the fixture's own source assert anything? A fixture with no `@test` is a
// diagnostic case: its build fails, so there is no program to run tests in.
function declaresTests(fixture: string): boolean {
  const src = join(fixture, "src");
  return existsSync(src) && containsTestFn(src);
}

const fixtures = readdirSync(FIXTURES, { withFileTypes: true })
  .filter(e => e.isDirectory())
  .map(e => e.name)
  .sort();

test.concurrent("hook fixtures: at least one discovered", () => {
  expect(fixtures.length).toBeGreaterThan(0);
});

for (const name of fixtures) {
  test.concurrent(`driven build: ${name}`, async () => {
    const b = await drivenBuild(name);
    const actual = normalise(formatRun(b.stdout, b.stderr, b.exit), b.dir);
    const snap = snapshotEquals(`${FIXTURES}/${name}`, "build.snapshot", actual);
    if (!snap.ok) {
      throw new Error(
        `Snapshot mismatch: ${name} (${snap.snapPath})\n` +
        `Run with UPDATE_SNAPSHOTS=1 to refresh.\n\n` +
        snapshotDiff(snap.snapPath, snap.expected, actual),
      );
    }
    if (b.exit === 0) {
      expectGeneratedTree(`${FIXTURES}/${name}`, b.dir);
    }
    // Universal to every driven build, so it belongs here rather than in one
    // hand-written test: artefacts go under `build/`, and the generated entry
    // shim is UNLINKED rather than blanked — a leftover `.vader` declaring
    // nothing would break the next run.
    expect(existsSync(`${b.dir}/vader_build_entry.vader`)).toBe(false);
    expect(existsSync(`${b.dir}/vader_build_driver`)).toBe(false);
    // The fixture's own `@test` fns are what prove the GENERATED code correct.
    // They run after the build on purpose: without `build/generated/` they fail
    // `R2006`, so a green run says the generated declarations were really there.
    if (declaresTests(`${FIXTURES}/${name}`)) {
      const t = await run(["test", "src"], { cwd: b.dir });
      if (t.exit !== 0) {
        throw new Error(
          `${name}: \`vader test src\` failed after the driven build — the ` +
          `fixture's own @test fns are what assert the generated code.\n` +
          `${t.stdout}${t.stderr}`,
        );
      }
    }
  }, HEAVY_BUILD);
}

// ---- what a corpus entry cannot carry --------------------------------------

// Everything below is hand-written, each for a stated reason. A corpus entry is
// one `vader build` in a clean project, its output compared to a committed
// expectation, and the project's own tests run afterwards. These are the
// properties that do not fit that shape.

// A `dist/` bundle is a LAYOUT, not a project — binary at the root, then ONE
// module root `lib/` (holding `std/` and the compiler's `vader/`) plus
// `runtime/c/` beside it. Assembling one by copy + symlink costs
// nothing, and it is the only way to exercise what a real install does: the
// staged-project symlinks every other test uses are exactly what masked the gap
// this pins.
//
// The binary is COPIED, not symlinked: `current_executable_location()` resolves
// through a symlink (realpath), which would report the repo's `build/` as the
// toolchain root and defeat the point. Copying an arm64 binary invalidates its
// signature on macOS, hence the ad-hoc re-sign.
function stageBundle(): string {
  const dir = mkdtempSync(`${tmpdir()}/vader-bundle-`);
  mkdirSync(`${dir}/runtime`);
  // `lib/` is a real directory, not a link to the repo's: the bundle puts the
  // checkout's own namespaces under it AND the compiler's sources, which come
  // from different places in the tree.
  mkdirSync(`${dir}/lib`);
  // Keep the platform's executable NAME: on Windows it is `vader.exe`, and a
  // bundle holding a `vader` cannot be spawned (`ENOENT` from `uv_spawn`).
  const exe = `${dir}/${basename(CLI_BIN)}`;
  cpSync(CLI_BIN, exe);
  if (process.platform === "darwin") {
    Bun.spawnSync(["codesign", "-s", "-", exe]);
  }
  // Every namespace the checkout ships, not a named list: a list silently stops
  // staging the next namespace added, and the bundle then fails on a module the
  // checkout resolves fine.
  for (const ns of readdirSync(`${REPO}/lib`)) {
    symlinkSync(`${REPO}/lib/${ns}`, `${dir}/lib/${ns}`);
  }
  // Mirror the dist trim rather than linking `vader/` whole: the point of this
  // staging is to exercise what a real install HAS, and a bundle drops the human
  // front-ends. Linking everything would make the test pass on a bundle that
  // cannot build — which is the only failure this staging exists to catch.
  const excluded = new Set(
    readFileSync(`${REPO}/bootstrap/dist-exclude.txt`, "utf8")
      .split("\n").map((l) => l.trim()).filter((l) => l && !l.startsWith("#")),
  );
  mkdirSync(`${dir}/src/vader`, { recursive: true });
  for (const sub of readdirSync(`${REPO}/vader`)) {
    if (excluded.has(sub)) continue;
    symlinkSync(`${REPO}/vader/${sub}`, `${dir}/src/vader/${sub}`);
  }
  symlinkSync(`${REPO}/runtime/c`, `${dir}/runtime/c`);
  return dir;
}

test.concurrent("a bundle drives a build with nothing beside the project", async () => {
  // REASON: a bundle is not a staged project, and three separate lookups have to
  // land: the driver's own `import "toolchain/build"` (bundle `lib/toolchain/`), the
  // project's `std/*` (bundle `lib/std/`), and `vader_runtime.c` at the link step
  // (bundle `runtime/c/`). The project directory has NO symlinks — the driver
  // runs as `<project>/build/driver/driver`, so every probe relative to ITSELF
  // looks inside the project and finds nothing.
  const bundle = stageBundle();
  staged.push(bundle);
  const dir = mkdtempSync(`${tmpdir()}/vader-bundleproj-`);
  staged.push(dir);
  copyFixture(JSON_DERIVE, dir);
  // The canary: NO toolchain beside this project, so everything the build needs
  // has to come from the bundle. Stated as absences rather than as a directory
  // listing — the fixture also holds its committed expectation, and a listing
  // would then depend on whether the corpus test had written it yet.
  for (const beside of TOOLCHAIN_LINKS) {
    expect(existsSync(`${dir}/${beside}`)).toBe(false);
  }

  const built = await run(["build"], { bin: `${bundle}/${basename(CLI_BIN)}`, cwd: dir });
  expect(built.stderr).not.toContain("R2001");
  expect(built.stderr).not.toContain("error[");
  expect(built.exit).toBe(0);

  const ran = await runBinary(exePath(`${dir}/app`), dir);
  expect(ran.stdout).toContain('"home":{"city":"Lyon","zip":69001}');
}, HEAVY_BUILD);

test.concurrent("a shipped library cannot import the compiler (R2034)", async () => {
  // REASON: the layering invariant, and it needs a file UNDER the library root to
  // state it — which no diag_corpus fixture can be (that harness dumps a single
  // file wherever it sits) and no snippet either. Same reason the H6xxx family
  // lives in this file: a uniform harness cannot reach the shape.
  //
  // What it pins: `lib/` holds what the toolchain ships, and none of it may depend
  // on what INTERPRETS Vader, or a program importing a library would drag the
  // compiler into its runtime closure. `toolchain/build` is the sole exemption,
  // because a driver LINKS the compiler by design.
  //
  // The probe is a library root staged in /tmp, not a directory written into the
  // checkout — see tests/lib-probe.ts for why that distinction broke the suite
  // once. Which also means this test is parallel-safe.
  await withStagedLibraryRoot({
    r2034probe: {
      "r2034probe.vader":
        'module "r2034probe"\n\nimport "vader/lexer"\n\nexport peek :: fn() -> i32 = 1\n',
    },
  }, async (dir) => {
    writeFileSync(
      `${dir}/app.vader`,
      'module "app"\n\nimport "std/io"\nimport "r2034probe"\n\n'
        + 'main :: fn() -> i32 {\n    println("${peek()}")\n    return 0\n}\n',
    );
    // `cwd: dir` is what makes `<dir>/lib` the library root, and so what puts the
    // probe under it. R2034 is checked before the module-not-found lookup, so it
    // fires whether or not `vader/lexer` resolves from here — the rule is about
    // the attempt.
    const ran = await run(["run", "app.vader"], { cwd: dir });
    expect(ran.stderr).toContain("R2034");
    expect(ran.stderr).toContain("only `toolchain/build` may");
  });
}, HEAVY_BUILD);

test.concurrent("a bundled namespace outranks a project module of the same name", async () => {
  // REASON: `lib/` hosts every namespace the toolchain ships, and those are
  // ORDINARY directory names — `std` today, `json` / `cli` / `images` once the
  // library split lands. Include-paths are first-match-wins, so with the project
  // searched first a project declaring `module "cli"` silently wins over the
  // shipped one. Bad alone, worse in a driven build: the compiler's sources are
  // compiled in the SAME unit as the project, so `vader/cli` would be built
  // against the user's module. Reproduced before the fix, pinned here.
  //
  // A bundle is the shape where it bites — that is where a library root is
  // authoritative. Only the BUNDLED root is promoted ahead of the project; the
  // cwd-relative fallback stays last, so a project keeping its own code under
  // `lib/` is unaffected. Hence a staged bundle rather than a staged project.
  const bundle = stageBundle();
  staged.push(bundle);
  // A top-level namespace in the bundle, standing in for the post-split layout.
  mkdirSync(`${bundle}/lib/reserved`, { recursive: true });
  writeFileSync(
    `${bundle}/lib/reserved/reserved.vader`,
    'module "reserved"\n\nexport who :: fn() -> i32 = 1\n',
  );

  const dir = mkdtempSync(`${tmpdir()}/vader-reserved-`);
  staged.push(dir);
  // The manifest is what makes the project root a search root at all — without
  // one, only the entry's own folder is searched and the clash cannot arise.
  writeFileSync(`${dir}/vader.json`, '{ "name": "reserved-clash" }\n');
  mkdirSync(`${dir}/reserved`, { recursive: true });
  writeFileSync(
    `${dir}/reserved/reserved.vader`,
    'module "reserved"\n\nexport who :: fn() -> i32 = 999\n',
  );
  writeFileSync(
    `${dir}/app.vader`,
    'module "app"\n\nimport "std/io"\nimport "reserved"\n\n'
      + 'main :: fn() -> i32 {\n    println("who=${who()}")\n    return 0\n}\n',
  );

  const ran = await run(["run", "app.vader"], { bin: `${bundle}/${basename(CLI_BIN)}`, cwd: dir });
  expect(ran.stdout).toContain("who=1");
  expect(ran.stdout).not.toContain("who=999");
}, HEAVY_BUILD);

test.concurrent("a driven build sweeps the previous build's generated modules", async () => {
  // REASON: the only TWO-BUILD property in the corpus. Generated names are
  // content hashes, so a module whose text CHANGED leaves its old file in the
  // same folder — where it still compiles, declaring the same symbol twice
  // (T3053, fatal). A clean project can never exhibit that state: a fresh build
  // leaves exactly one file and the sweep has nothing to sweep. So the leftover
  // has to be PLANTED, which is setup no corpus entry can express — and it writes
  // into the staged tree, hence a private stage.
  const dir = stage(GENERATE);
  staged.push(dir);
  const genDir = `${dir}/build/generated/gen/describe`;
  mkdirSync(genDir, { recursive: true });
  const stale = `${genDir}/describe_deadbeefdeadbeef.vader`;
  writeFileSync(stale,
    '// Generated by `vader build` — do not edit.\n\nmodule "gen/describe"\n\n' +
    'export describe_Point :: fn() -> string = "STALE"\n');

  const built = await run(["build"], { cwd: dir });
  expect(built.stderr).not.toContain("error[");
  expect(built.exit).toBe(0);
  expect(existsSync(stale)).toBe(false);
  expect(readdirSync(genDir).length).toBe(1);

  const ran = await runBinary(exePath(`${dir}/app`), dir);
  expect(ran.stdout).toContain("Point(x, y) /");
  expect(ran.stdout).not.toContain("STALE");
}, HEAVY_BUILD);

test.concurrent("the driver produces a working binary", async () => {
  // REASON: it RUNS what the build produced. A committed expectation covers the
  // build's output, and the corpus loop covers the project root staying clean —
  // neither can say the binary works.
  const { dir } = await drivenBuild("pascal_case_lint");
  expect(existsSync(exePath(`${dir}/build/driver/driver`))).toBe(true);

  // The whole point of decision 13: a driver is a build system, not an observer.
  // It compiles the project and the result runs — even though the driver went on
  // to report a rule violation.
  const ran = await runBinary(exePath(`${dir}/hello`), dir);
  expect(ran.stdout).toContain("hello");
  expect(ran.exit).toBe(0);
}, HEAVY_BUILD);

test.concurrent("the front end runs ONCE for a driver that observes and builds", async () => {
  // REASON: asserts on a PROFILE of the driver's own process, not on the build.
  // Observing used to re-run the front end, which is ~45% of a build. Profiled on
  // the DRIVER's process on purpose — a `vader build` profile also contains the
  // compiler's pass over the driver itself, which would make the count
  // meaningless.
  const { dir } = await drivenBuild("pascal_case_lint");
  const profiled = await runBinary(
    exePath(`${dir}/build/driver/driver`), dir, { VADER_PROFILE: "1" });
  const typechecks = (profiled.stderr.match(/^\s+typecheck\s/gm) ?? []).length;
  expect(typechecks).toBe(1);
}, HEAVY_BUILD);

test.concurrent("a named file bypasses the driver, and says so", async () => {
  // REASON: not a driven build — the CLI is given a file, which is the path
  // `bootstrap/build.sh` takes to compile the compiler, so it has to win. But
  // silently dropping a project's rules would make them untrustworthy.
  const dir = stage(LINT);
  staged.push(dir);
  const r = await run(["build", "--target=c", "--out=-", "src/main.vader"], { cwd: dir });
  expect(r.stderr).toContain("not applied");
  expect(r.exit).toBe(0);
}, HEAVY_BUILD);

test.concurrent("--no-hooks silences that, and skips the driver entirely", async () => {
  // REASON: same — a flag's effect on the non-driven path.
  const dir = stage(LINT);
  staged.push(dir);
  const quiet =
    await run(["build", "--target=c", "--out=-", "--no-hooks", "src/main.vader"], { cwd: dir });
  expect(quiet.stderr).not.toContain("not applied");

  // With no file either, --no-hooks means the driver is not even looked for.
  const bare = await run(["build", "--no-hooks"], { cwd: dir });
  expect(bare.stderr).toContain("expected a file");
  expect(bare.exit).toBe(1);
}, HEAVY_BUILD);
