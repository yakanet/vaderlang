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
import { rmSync, writeFileSync, readFileSync, readdirSync, mkdirSync, cpSync, mkdtempSync, symlinkSync, existsSync } from "node:fs";
import { basename, resolve } from "node:path";
import { tmpdir } from "node:os";
import { ensureCliBuilt, CLI_BIN, LONG_BUILD, HEAVY_BUILD } from "./cli-bin.ts";

ensureCliBuilt();

const CLI = resolve(CLI_BIN);
const FIXTURES = "tests/hook_fixtures";
const LINT = `${FIXTURES}/pascal_case_lint`;
const GENERATE = `${FIXTURES}/generate_module`;
const JSON_DERIVE = `${FIXTURES}/json_derive`;

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

// A linked executable as the LINKER named it. `cc -o hello` writes `hello` on
// Unix and `hello.exe` on Windows — verified with mingw-w64: gcc appends the
// suffix when `-o` carries no extension. Every assertion about a built binary has
// to go through this, or it passes on one OS and fails on the other.
const exeName = (base: string) => (process.platform === "win32" ? `${base}.exe` : base);

const staged: string[] = [];

// A `dist/` bundle is a LAYOUT, not a build: binary at the root, `stdlib/`,
// `runtime/c/` and `lib/vader/` beside it. Assembling one by copy + symlink costs
// nothing, and it is the only way to exercise what a real install does — the
// staged-project symlinks the other tests use are exactly what masked the gap
// this pins.
//
// The binary is COPIED, not symlinked: `current_executable_location()` resolves
// through a symlink (realpath), which would report the repo's `build/` as the
// toolchain root and defeat the point. Copying an arm64 binary invalidates its
// signature on macOS, hence the ad-hoc re-sign.
function stageBundle(): string {
  const dir = mkdtempSync(`${tmpdir()}/vader-bundle-`);
  mkdirSync(`${dir}/runtime`);
  mkdirSync(`${dir}/lib`);
  // Keep the platform's executable NAME: on Windows it is `vader.exe`, and a
  // bundle holding a `vader` cannot be spawned (`ENOENT` from `uv_spawn`).
  const exe = `${dir}/${basename(CLI_BIN)}`;
  cpSync(CLI, exe);
  if (process.platform === "darwin") {
    Bun.spawnSync(["codesign", "-s", "-", exe]);
  }
  symlinkSync(`${REPO}/stdlib`, `${dir}/stdlib`);
  symlinkSync(`${REPO}/runtime/c`, `${dir}/runtime/c`);
  symlinkSync(`${REPO}/vader`, `${dir}/lib/vader`);
  return dir;
}

// The bundle's own executable, by the platform's name for it.
function bundleExe(bundle: string): string {
  return `${bundle}/${basename(CLI_BIN)}`;
}

test("a bundle drives a build with nothing beside the project", async () => {
  // The whole point of shipping `vader/` in `--dist`, and of passing the
  // toolchain root to the driver. Three separate lookups have to land: the
  // driver's own `import "vader/hooks"` (bundle `lib/vader/`), the project's
  // `std/*` (bundle `stdlib/`), and `vader_runtime.c` at the link step (bundle
  // `runtime/c/`). The project directory has NO symlinks — the driver runs as
  // `<project>/build/driver/driver`, so every probe relative to ITSELF looks
  // inside the project and finds nothing.
  const bundle = stageBundle();
  staged.push(bundle);
  const dir = mkdtempSync(`${tmpdir()}/vader-bundleproj-`);
  staged.push(dir);
  cpSync(JSON_DERIVE, dir, { recursive: true });
  expect(readdirSync(dir).sort()).toEqual(["build.vader", "src"]);

  const proc = Bun.spawn([bundleExe(bundle), "build"], { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [err, exit] = await Promise.all([new Response(proc.stderr).text(), proc.exited]);
  expect(err).not.toContain("R2001");
  expect(err).not.toContain("error[");
  expect(exit).toBe(0);

  const ran = Bun.spawn([exeName(`${dir}/app`)], { stdout: "pipe", stderr: "pipe" });
  const [ranOut] = await Promise.all([new Response(ran.stdout).text(), ran.exited]);
  expect(ranOut).toContain('"home":{"city":"Lyon","zip":69001}');
}, HEAVY_BUILD);

async function runIn(fixture: string, args: string[]) {
  const dir = stage(fixture);
  staged.push(dir);
  const proc = Bun.spawn([CLI, ...args], { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [stdout, stderr, exit] = await Promise.all([
    new Response(proc.stdout).text(),
    new Response(proc.stderr).text(),
    proc.exited,
  ]);
  return { out: `${stdout}\n${stderr}`, exit, dir };
}

// Five tests below drive the SAME build of the same fixture and only differ in
// what they inspect. Running it once and sharing the result cuts four full
// compiler builds — each compiles the driver, which pulls the whole `vader/`
// closure at -O0 — taking this file from ~160 s to ~69 s.
//
// ⚠️ THREE WAYS THIS BITES, if you touch it:
//   1. The five share a staged directory and only READ from it. A test that
//      writes there breaks its neighbours, and the failure surfaces in a test
//      that did nothing wrong. Tests needing clean state (driver replacement,
//      `observe_only`, `no_driver`) stage privately — keep that split.
//   2. If the shared build fails, FIVE tests fail at once and none says which
//      is at fault: one broken `lintBuild()` reads as five regressions.
//   3. The first test to call `lintBuild()` pays the compile, so its
//      `LONG_BUILD` budget must stay sized for a full build even though the
//      other four are instant. Reordering the file moves that cost.
//
// If this becomes a nuisance, switch to an explicit `beforeAll`: the cost
// becomes visible and a failure is attributable to setup, not to a test.
let sharedLint: Promise<{ out: string; exit: number; dir: string }> | null = null;

function lintBuild() {
  if (sharedLint === null) {
    sharedLint = runIn(LINT, ["build"]);
  }
  return sharedLint;
}

// The generation fixture gets its own shared build, for the same reason and with
// the same three hazards as `lintBuild`: the tests below only READ the staged
// tree. A test that needs to edit it (the stale-sweep one) stages privately.
let sharedGenerate: Promise<{ out: string; exit: number; dir: string }> | null = null;

function generateBuild() {
  if (sharedGenerate === null) {
    sharedGenerate = runIn(GENERATE, ["build"]);
  }
  return sharedGenerate;
}

afterAll(() => {
  for (const dir of staged) {
    rmSync(dir, { recursive: true, force: true });
  }
});

// The first real CLIENT of generation, so it gets its own shared build — same
// reasoning and same three hazards as `lintBuild`; these tests only read.
let sharedJson: Promise<{ out: string; exit: number; dir: string }> | null = null;

function jsonBuild() {
  if (sharedJson === null) {
    sharedJson = runIn(JSON_DERIVE, ["build"]);
  }
  return sharedJson;
}

test("a driver derives JSON serialisers from the structs' field types", async () => {
  // The dogfood test: no `to_json` exists anywhere in the fixture's tree. The
  // driver walked each struct's FIELD TYPES and wrote one serialiser per struct,
  // and the assertion is the running binary's output — so the generated code is
  // proven correct, not merely proven to compile.
  const { out, exit, dir } = await jsonBuild();
  expect(out).not.toContain("error[");
  expect(exit).toBe(0);

  const ran = Bun.spawn([exeName(`${dir}/app`)], { stdout: "pipe", stderr: "pipe" });
  const [ranOut, ranExit] = await Promise.all([new Response(ran.stdout).text(), ran.exited]);
  expect(ranExit).toBe(0);
  // Every mapping the generator makes, in one line: a string with a quote in it
  // (escaped by `std/json`, not by hand), an i32 as a bare number, a bool, a
  // NESTED struct recursed through its own generated overload, and an array.
  expect(ranOut.trim()).toBe(
    '{"name":"A\\"B","age":41,"active":true,"home":{"city":"Lyon","zip":69001},"tags":["x","y"]}');
}, LONG_BUILD);

test("the derived serialisers are overloads in the struct's own module", async () => {
  // Why they must live there: `to_json_value(v: Person)` names `Person`. A
  // separate module could not — it would have to import `app`, which imports it.
  // And one module holds one serialiser per struct because they are overloads on
  // the parameter type.
  const { dir } = await jsonBuild();
  const files = readdirSync(`${dir}/build/generated/app`);
  expect(files.length).toBe(1);
  const text = readFileSync(`${dir}/build/generated/app/${files[0]}`, "utf8");
  expect(text).toContain('module "app"');
  expect(text).toContain("to_json_value :: fn(v: Address)");
  expect(text).toContain("to_json_value :: fn(v: Person)");
  // The nested field recursed rather than being skipped or stringified.
  expect(text).toContain('entries["home"] = to_json_value(v.home)');
}, LONG_BUILD);

function generatedFiles(dir: string, module = "gen/describe") {
  return readdirSync(`${dir}/build/generated/${module}`);
}

function generatedText(dir: string, module: string) {
  const files = generatedFiles(dir, module);
  expect(files.length).toBe(1);
  return { name: files[0], text: readFileSync(`${dir}/build/generated/${module}/${files[0]}`, "utf8") };
}

test("a driver generates a module, and the built binary runs it", async () => {
  // The original ask: generate code inside the compilation unit. Neither
  // `describe_Point` nor `describe` exists anywhere in the tree — the driver
  // wrote both, mid-build.
  const { out, exit, dir } = await generateBuild();
  expect(exit).toBe(0);
  // Two rounds: one to see `Point`, one to compile what seeing it produced. A
  // third would mean the driver is not idempotent.
  expect(out).toContain("driver: 2 round(s), 2 generated file(s)");
  // The delivery contract, in one line. `struct seen 1x` is the sharp half: the
  // driver emits INTO `app`, so `app` IS delivered again on round 2 — but
  // carrying only the generated file's declarations, never `Point` a second
  // time. That is what keeps a lint rule from firing twice. `generated decls
  // back 2` is the other half: generated code re-enters the stream, so a driver
  // can derive from it — transitive generation, with no mechanism of its own.
  expect(out).toContain("driver: struct seen 1x, generated decls back 2");

  // Shape 1: a module of its own, which `src/main.vader` imports.
  const own = generatedText(dir, "gen/describe");
  // `<leaf>_<content hash>.vader` — the naming that makes re-emission a no-op.
  expect(own.name).toMatch(/^describe_[0-9a-f]+\.vader$/);
  // The banner is load-bearing: the stale sweep deletes on it.
  expect(own.text.startsWith("// Generated by `vader build`")).toBe(true);
  // The compiler writes the header, not the driver, so name and path cannot drift.
  expect(own.text).toContain('module "gen/describe"');
  expect(own.text).toContain("describe_Point");

  // Shape 2: a file that JOINED the entry module, whose own folder is `src/`.
  // It declares `module "app"` from outside `src/` — the merge-root exception —
  // and that is what lets it take `Point` by type. An imported module could not:
  // it would have to import `app` back, which is a cycle.
  const joined = generatedText(dir, "app");
  expect(joined.text).toContain('module "app"');
  expect(joined.text).toContain("describe :: fn(p: Point)");
  // …and it stayed out of the source tree.
  expect(readdirSync(`${dir}/src`)).toEqual(["main.vader"]);

  const ran = Bun.spawn([exeName(`${dir}/app`)], { stdout: "pipe", stderr: "pipe" });
  const [ranOut, ranExit] = await Promise.all([new Response(ran.stdout).text(), ran.exited]);
  // Left of the slash: the imported module. Right: the file that joined `app`
  // and read the struct's fields.
  expect(ranOut).toContain("Point(x, y) / Point = 1 + 2");
  expect(ranExit).toBe(0);
}, LONG_BUILD);

test("`vader run` sees the generated code the build produced", async () => {
  // The hole this closes: generated modules used to be visible ONLY to the driven
  // build, so a project that generated compiled green under `vader build` and
  // failed under every other command. The generated root is derived by the LOADER
  // from the project root now, not threaded from the driver, so `run` / `test` /
  // `lint` / `dump` and the LSP all see it.
  //
  // Safe on the shared staged tree: `vader run` executes through the VM and
  // writes nothing.
  const { dir } = await generateBuild();
  const proc = Bun.spawn([CLI, "run", "src/main.vader"], { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [out, err, exit] = await Promise.all([
    new Response(proc.stdout).text(),
    new Response(proc.stderr).text(),
    proc.exited,
  ]);
  expect(err).not.toContain("R2001");
  expect(out).toContain("Point(x, y) / Point = 1 + 2");
  expect(exit).toBe(0);
}, LONG_BUILD);

test("the round where the generated import could not resolve reports nothing", async () => {
  // `src/main.vader` imports `gen/describe`, which cannot exist on round 1: only
  // the LAST round's diagnostics are surfaced. Without that, every generating
  // project would report a module-not-found on every build — which is what makes
  // this the materialised equivalent of Jai's `#placeholder`.
  const { out } = await generateBuild();
  expect(out).not.toContain("error[");
  expect(out).not.toContain("warning[");
}, LONG_BUILD);

test("a driven build sweeps the previous build's generated modules", async () => {
  // Why the sweep is not optional: names are content hashes, so a module whose
  // text CHANGED leaves its old file in the same folder — where it still
  // compiles. Plant exactly that leftover, declaring the same symbol the driver
  // is about to generate. Unswept, the build dies on a duplicate declaration;
  // swept, it produces the real thing.
  //
  // It writes into the staged tree, so it stages privately (see `lintBuild`).
  const dir = stage(GENERATE);
  staged.push(dir);
  const genDir = `${dir}/build/generated/gen/describe`;
  mkdirSync(genDir, { recursive: true });
  const stale = `${genDir}/describe_deadbeefdeadbeef.vader`;
  writeFileSync(stale,
    '// Generated by `vader build` — do not edit.\n\nmodule "gen/describe"\n\n' +
    'export describe_Point :: fn() -> string = "STALE"\n');

  const proc = Bun.spawn([CLI, "build"], { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [err, exit] = await Promise.all([new Response(proc.stderr).text(), proc.exited]);
  expect(err).not.toContain("error[");
  expect(exit).toBe(0);
  expect(existsSync(stale)).toBe(false);
  expect(generatedFiles(dir).length).toBe(1);

  const ran = Bun.spawn([exeName(`${dir}/app`)], { stdout: "pipe", stderr: "pipe" });
  const [ranOut] = await Promise.all([new Response(ran.stdout).text(), ran.exited]);
  expect(ranOut).toContain("Point(x, y) /");
  expect(ranOut).not.toContain("STALE");
}, LONG_BUILD);

test("generation that never settles is reported as H6006", async () => {
  // A driver whose emitted text changes every round. Not a hang — the round cap
  // turns it into a diagnostic naming what kept moving.
  const { out, exit } = await runWithDriver(LINT, `module "build"

import "std/io"
import "vader/hooks"

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_build_file("src/main.vader")
    ctx.out = "app"
    rounds := 0
    for msg in ctx.messages() {
        if msg is PhaseMessage as p {
            if p.phase == .Typechecked {
                rounds += 1
                ctx.emit_module("gen/tick", "export tick_\${rounds} :: fn() -> i32 = \${rounds}")
            }
        }
    }
    if ctx.flush_reports() {
        return 1
    }
    return 0
}
`, ["build"]);
  expect(out).toContain("H6006");
  expect(out).toContain("gen/tick");
  expect(out).toMatch(/build\.vader:\d+:\d+\] error\[H6006\]/);
  expect(exit).not.toBe(0);
}, LONG_BUILD);

test("the driver produces a working binary", async () => {
  // The whole point of decision 13: a driver is a build system, not an
  // observer. It compiles the project and the result runs.
  const { dir } = await lintBuild();
  expect(existsSync(exeName(`${dir}/hello`))).toBe(true);
  const ran = Bun.spawn([exeName(`${dir}/hello`)], { stdout: "pipe", stderr: "pipe" });
  const [out, exit] = await Promise.all([new Response(ran.stdout).text(), ran.exited]);
  expect(out).toContain("hello");
  expect(exit).toBe(0);
}, LONG_BUILD);

test("the driven build leaves no artefact in the project root", async () => {
  // Artefacts belong under `build/`, and the entry shim must be unlinked rather
  // than blanked — a leftover `.vader` declaring nothing would break the next run.
  const { dir } = await lintBuild();
  expect(existsSync(`${dir}/vader_build_entry.vader`)).toBe(false);
  expect(existsSync(`${dir}/vader_build_driver`)).toBe(false);
  expect(existsSync(exeName(`${dir}/build/driver/driver`))).toBe(true);
}, LONG_BUILD);

test("a project's build.vader runs and reports its own rule", async () => {
  const { out, exit } = await lintBuild();
  // Exactly one H6004, on the offending struct, anchored in the project's
  // source rather than in the generated entry.
  const rule = out.split("\n").filter(l => l.includes("H6004"));
  expect(rule.length).toBe(1);
  // A reported rule violation must FAIL the build — it used to exit 0.
  expect(exit).not.toBe(0);
  expect(rule[0]).toContain("badlyNamed");
  expect(rule[0]).toMatch(/src\/main\.vader:\d+:\d+/);
  // …and discriminates: the compliant struct is not what the rule reported.
  expect(rule[0]).not.toContain("WellNamed");
}, LONG_BUILD);

test("the driver sees project modules, not just the stdlib", async () => {
  // `messages()` yields every typed module; the fixture filters on
  // `module_name`. If that field carried the loader's filesystem key instead of
  // the declared name, the filter would match nothing and the rule would run
  // over the stdlib too — which is exactly the bug this pins.
  const { out } = await lintBuild();
  expect(out).not.toContain("std/io");
  expect(out).toContain("badlyNamed");
}, LONG_BUILD);

// Run with the fixture's driver REPLACED, writing to the staged copy rather
// than to the checkout. Editing the tracked fixture and restoring it in
// `finally` leaves the repo dirty whenever a 120 s test is killed — and every
// later test staging that fixture then fails for an unrelated reason.
async function runWithDriver(fixture: string, source: string, args: string[]) {
  const dir = stage(fixture);
  staged.push(dir);
  writeFileSync(`${dir}/build.vader`, source);
  const proc = Bun.spawn([CLI, ...args], { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [stdout, stderr, exit] = await Promise.all([
    new Response(proc.stdout).text(),
    new Response(proc.stderr).text(),
    proc.exited,
  ]);
  return { out: `${stdout}\n${stderr}`, exit, dir };
}

test("a build.vader with no `build` fn is rejected as H6001", async () => {
  const { out, exit } = await runWithDriver(LINT,
    'module "build"\n\nother :: fn() -> void {}\n', ["build"]);
  expect(out).toContain("H6001");
  // Anchored on the driver itself, not on the generated entry.
  expect(out).toMatch(/build\.vader:\d+:\d+/);
  expect(out).not.toContain("vader_build_entry");
  expect(exit).not.toBe(0);
}, LONG_BUILD);

test("a `build` of the wrong arity is rejected as H6002", async () => {
  const { out, exit } = await runWithDriver(LINT,
    'module "build"\n\nbuild :: fn() -> i32 { return 0 }\n', ["build"]);
  expect(out).toContain("H6002");
  expect(exit).not.toBe(0);
}, LONG_BUILD);

test("a `void` build is rejected as H6002 — it could not carry an exit status", async () => {
  const { out, exit } = await runWithDriver(LINT,
    'module "build"\n\nbuild :: fn(args: string[]) -> void {}\n', ["build"]);
  expect(out).toContain("H6002");
  expect(exit).not.toBe(0);
}, LONG_BUILD);

test("a driver that queues nothing is reported as H6003", async () => {
  // Draining an empty stream used to finish cleanly: a build that compiled
  // nothing while reporting no problem.
  const { out, exit } = await runIn(`${FIXTURES}/no_entry_queued`, ["build"]);
  expect(out).toContain("H6003");
  expect(out).toContain("add_build_file");
  // Anchored on the driver, not on `<synthetic>`: the faulty line is unknown (it
  // is a behaviour, not a statement) but the faulty FILE never is.
  expect(out).toMatch(/build\.vader:\d+:\d+\] error\[H6003\]/);
  // …and fails: compiling nothing while exiting 0 was the original bug.
  expect(exit).not.toBe(0);
}, LONG_BUILD);

test("leaving the stream at BeforeEmit builds nothing", async () => {
  // The property that lets a lint-only driver exist without an opt-out flag:
  // `BeforeEmit` is the last point at which declining is clean.
  const { out, dir } = await runIn(`${FIXTURES}/observe_only`, ["build"]);
  expect(out).toContain("built nothing");
  expect(out).toMatch(/observed [1-9]\d* module/);
  // The property the test is named for: the fixture plants this name as a
  // canary. Without the assertion, moving emission above `BeforeEmit` would
  // write the binary and the test would still pass.
  expect(existsSync(`${dir}/should-not-exist`)).toBe(false);
  expect(existsSync(exeName(`${dir}/should-not-exist`))).toBe(false);
}, LONG_BUILD);

test("the front end runs ONCE for a driver that observes and builds", async () => {
  // The whole point of the single stream: observing used to re-run the front
  // end, which is ~45% of a build. Profiled on the DRIVER's own process — a
  // `vader build` profile also contains the compiler's pass over the driver
  // itself, which would make the count meaningless.
  const { dir } = await lintBuild();
  const driver = Bun.spawn([exeName(`${dir}/build/driver/driver`), dir], {
    cwd: dir, stdout: "pipe", stderr: "pipe", env: { ...process.env, VADER_PROFILE: "1" },
  });
  const [err] = await Promise.all([new Response(driver.stderr).text(), driver.exited]);
  const typechecks = (err.match(/^\s+typecheck\s/gm) ?? []).length;
  expect(typechecks).toBe(1);
}, LONG_BUILD);

test("a named file bypasses the driver, and says so", async () => {
  // `bootstrap/build.sh` compiles the compiler by name, so a named file has to
  // win — but silently dropping a project's rules would make them untrustworthy.
  const dir = stage(LINT);
  staged.push(dir);
  const proc = Bun.spawn([CLI, "build", "--target=c", "--out=-", "src/main.vader"],
    { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [err, exit] = await Promise.all([new Response(proc.stderr).text(), proc.exited]);
  expect(err).toContain("not applied");
  expect(exit).toBe(0);
}, LONG_BUILD);

test("--no-hooks silences that, and skips the driver entirely", async () => {
  const dir = stage(LINT);
  staged.push(dir);
  const quiet = Bun.spawn([CLI, "build", "--target=c", "--out=-", "--no-hooks", "src/main.vader"],
    { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [err] = await Promise.all([new Response(quiet.stderr).text(), quiet.exited]);
  expect(err).not.toContain("not applied");

  // With no file either, --no-hooks means the driver is not even looked for.
  const bare = Bun.spawn([CLI, "build", "--no-hooks"], { cwd: dir, stdout: "pipe", stderr: "pipe" });
  const [bareErr, bareExit] = await Promise.all([new Response(bare.stderr).text(), bare.exited]);
  expect(bareErr).toContain("expected a file");
  expect(bareExit).toBe(1);
}, LONG_BUILD);

test("`vader build` without a driver still asks for a file", async () => {
  // The default path must be untouched: no `build.vader` in this fixture, so the
  // CLI keeps its own error — now naming the driver as a third option.
  const { out, exit } = await runIn(`${FIXTURES}/no_driver`, ["build"]);
  expect(out).toContain("expected a file");
  expect(out).toContain("build.vader");
  expect(exit).toBe(1);
}, LONG_BUILD);
