// The two project-level commands, end to end: `vader new` writes a project, and
// `vader doctor` says whether one can be built here.
//
// They are pinned together because they are two halves of one answer — one says
// the toolchain is sound, the other that the project is — and because a scaffold
// is only worth anything if what it writes RUNS. That is the first test below,
// and it is the reason this file spawns rather than unit-tests: the per-file
// pieces (the templates, the target rules, the environment parsing) are covered
// by colocated `@test`s in `vader/cli/cmd_new.vader` and `cmd_doctor.vader`.
// What only a spawn can show is the three files reaching the compiler.
//
// NOT in `cli_unknown_flag.test.ts`: that file pins the ARGUMENT BOUNDARY — one
// rule, applied to every action. This one pins what two actions do.

import { test, expect } from "bun:test";
import { mkdirSync, mkdtempSync, rmSync, existsSync, readFileSync, symlinkSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join, resolve } from "node:path";
import { spawnCapture, MEDIUM_BUILD } from "./cli-bin.ts";

const REPO = resolve(".");

// What a project needs beside it to resolve `std/…` when the binary is not part
// of a `dist/` bundle: the library root and the C runtime, found relative to the
// invocation directory. Symlinked into the staged project rather than copied —
// the same trick `hook_driver.test.ts` uses, and for the same reason: it
// reproduces an installed layout without touching the checkout.
const TOOLCHAIN_LINKS = ["lib", "runtime"] as const;

function withTempDir<T>(body: (dir: string) => Promise<T>): Promise<T> {
  const dir = mkdtempSync(join(tmpdir(), "vader-scaffold-"));
  return body(dir).finally(() => rmSync(dir, { recursive: true, force: true }));
}

test("`vader new` writes a project that runs", async () => {
  await withTempDir(async (workspace) => {
    const created = await spawnCapture(["new", "my-app"], { cwd: workspace });
    expect(created.exit).toBe(0);

    // The three files, and what each is for — the report is part of the
    // deliverable, since a scaffold nobody can read teaches nothing.
    const project = join(workspace, "my-app");
    expect(existsSync(join(project, "vader.json"))).toBe(true);
    expect(existsSync(join(project, "src/main.vader"))).toBe(true);
    expect(existsSync(join(project, ".gitignore"))).toBe(true);
    expect(created.stdout).toContain("vader run src/main.vader");

    // The manifest carries the directory's name, and the entry declares the
    // module its folder is called — the one rule about the layout that nothing
    // else in the toolchain states.
    expect(readFileSync(join(project, "vader.json"), "utf8")).toContain('"name": "my-app"');
    expect(readFileSync(join(project, "src/main.vader"), "utf8")).toContain('module "src"');

    for (const name of TOOLCHAIN_LINKS) {
      symlinkSync(`${REPO}/${name}`, join(project, name));
    }
    const ran = await spawnCapture(["run", "src/main.vader"], { cwd: project, timeoutMs: MEDIUM_BUILD });
    expect(ran.exit).toBe(0);
    expect(ran.stdout).toContain("hello from my-app");
  });
}, MEDIUM_BUILD);

test("the two modes refuse different things", async () => {
  await withTempDir(async (workspace) => {
    // NAMING a target that already holds something is refused: writing into a
    // directory the user did not mean to name is the mistake that cannot be
    // undone.
    mkdirSync(join(workspace, "taken"));
    writeFileSync(join(workspace, "taken/notes.md"), "");
    const named = await spawnCapture(["new", "taken"], { cwd: workspace });
    expect(named.exit).toBe(1);
    expect(named.stderr).toContain("not empty");

    // IN PLACE, a non-empty directory is the normal case — you are adding a
    // manifest to work already started.
    writeFileSync(join(workspace, "started.vader"), "");
    const inPlace = await spawnCapture(["new"], { cwd: workspace });
    expect(inPlace.exit).toBe(0);
    expect(existsSync(join(workspace, "vader.json"))).toBe(true);

    // Only an existing manifest stops it, and the message says why.
    const again = await spawnCapture(["new"], { cwd: workspace });
    expect(again.exit).toBe(1);
    expect(again.stderr).toContain("already a project");
  });
}, MEDIUM_BUILD);

test("`vader doctor` reports a working toolchain, and its JSON is the documented shape", async () => {
  // Run at the repo root, which is a checkout: the library root resolves through
  // the cwd-relative fallback and every other piece is in place.
  const text = await spawnCapture(["doctor"]);
  expect(text.exit).toBe(0);
  expect(text.stdout).toContain("library-root");
  expect(text.stdout).toContain("all clear");

  const json = await spawnCapture(["doctor", "--json"]);
  expect(json.exit).toBe(0);
  const report = JSON.parse(json.stdout);
  expect(report.ok).toBe(true);
  expect(Array.isArray(report.checks)).toBe(true);
  // `name` is the stable key — the summaries are prose and will drift.
  const names = report.checks.map((c: { name: string }) => c.name);
  expect(names).toContain("cc");
  expect(names).toContain("library-root");
  expect(names).toContain("runtime-c");
  for (const check of report.checks) {
    expect(["ok", "warn", "fail"]).toContain(check.status);
    expect(typeof check.summary).toBe("string");
    expect(typeof check.detail).toBe("string");
  }
}, MEDIUM_BUILD);

test("a failed check exits 1 and says which one", async () => {
  const { exit, stdout } = await spawnCapture(["doctor", "--json", "--cc=definitely-not-a-compiler"]);
  expect(exit).toBe(1);
  const report = JSON.parse(stdout);
  expect(report.ok).toBe(false);
  const cc = report.checks.find((c: { name: string }) => c.name === "cc");
  expect(cc.status).toBe("fail");
  expect(cc.detail).toContain("definitely-not-a-compiler");
}, MEDIUM_BUILD);

test("a GC size written with a suffix is reported as the bytes it really means", async () => {
  // `vader_gc_env_bytes` is a plain `strtoull`: it keeps the digits and drops the
  // rest, so `512M` is a 512-BYTE arena and nothing anywhere says so. This is the
  // check the command earns its keep on, so it is pinned end to end.
  const { exit, stdout } = await spawnCapture(["doctor", "--json"], {
    env: { VADER_GC_OLD_MAX: "512M" },
  });
  expect(exit).toBe(1);
  const report = JSON.parse(stdout);
  const knob = report.checks.find((c: { name: string }) => c.name === "vader_gc_old_max");
  expect(knob.status).toBe("fail");
  expect(knob.summary).toContain("512");
}, MEDIUM_BUILD);

test("$VADER_HOME points a binary at a toolchain that is not beside it", async () => {
  // The reason the variable exists. Without it a bare binary resolves `std/…`
  // only from a directory that happens to hold a `lib/`, which is why running a
  // project from anywhere needs a `dist/` bundle. Here the project is in a temp
  // directory with no toolchain in sight, and the build works anyway.
  await withTempDir(async (workspace) => {
    const created = await spawnCapture(["new", "elsewhere"], { cwd: workspace });
    expect(created.exit).toBe(0);
    const project = join(workspace, "elsewhere");

    // No symlinks this time — nothing beside the project, nothing beside the
    // binary. Only the variable.
    const ran = await spawnCapture(["run", "src/main.vader"], {
      cwd: project,
      env: { VADER_HOME: REPO },
      timeoutMs: MEDIUM_BUILD,
    });
    expect(ran.exit).toBe(0);
    expect(ran.stdout).toContain("hello from elsewhere");

    // And doctor says which probe answered, rather than reporting a
    // home-provided root as "beside the binary".
    const { exit, stdout } = await spawnCapture(["doctor", "--json"], {
      cwd: project,
      env: { VADER_HOME: REPO },
    });
    expect(exit).toBe(0);
    const report = JSON.parse(stdout);
    const home = report.checks.find((c: { name: string }) => c.name === "toolchain-home");
    expect(home.status).toBe("ok");
    const lib = report.checks.find((c: { name: string }) => c.name === "library-root");
    expect(lib.summary).toContain("VADER_HOME");
  });
}, MEDIUM_BUILD);

test("a stale $VADER_HOME is ignored, and doctor is what says so", async () => {
  // Ignoring it is the deliberate choice: a value left over from a moved install
  // must not brick every invocation. The cost is that a typo looks like nothing
  // happened, which is why the warning has to exist.
  await withTempDir(async (workspace) => {
    const { exit, stdout } = await spawnCapture(["doctor", "--json"], {
      env: { VADER_HOME: workspace },
    });
    // Still exits 0: the build works, it just works the ordinary way.
    expect(exit).toBe(0);
    const report = JSON.parse(stdout);
    const home = report.checks.find((c: { name: string }) => c.name === "toolchain-home");
    expect(home.status).toBe("warn");
    expect(home.detail).toContain(workspace);
    // The ordinary probe still answered, so nothing is broken.
    const lib = report.checks.find((c: { name: string }) => c.name === "library-root");
    expect(lib.status).toBe("ok");
    expect(lib.summary).not.toContain("VADER_HOME");
  });
}, MEDIUM_BUILD);

test("a $VADER_HOME that is only a string PREFIX of the real root is not credited", async () => {
  // The report says which probe answered, and it must ask the resolver rather
  // than compare paths as text: with the variable at `…/vaderlang` and the
  // sources at `…/vaderlang2`, a `startsWith` test claims the sources came
  // through the variable when they did not. That is the same "guess by name"
  // mistake `ModuleOrigin` exists to end, and it was live for one commit.
  await withTempDir(async (workspace) => {
    const project = join(workspace, "proj");
    mkdirSync(join(project, "vader/pipeline"), { recursive: true });

    const { stdout } = await spawnCapture(["doctor", "--json"], {
      cwd: project,
      // Never created, and a strict string prefix of `project`.
      env: { VADER_HOME: join(workspace, "pro") },
    });
    const report = JSON.parse(stdout);
    const sources = report.checks.find((c: { name: string }) => c.name === "compiler-sources");
    expect(sources.status).toBe("ok");
    expect(sources.summary).not.toContain("VADER_HOME");

    const home = report.checks.find((c: { name: string }) => c.name === "toolchain-home");
    expect(home.status).toBe("warn");
  });
}, MEDIUM_BUILD);
