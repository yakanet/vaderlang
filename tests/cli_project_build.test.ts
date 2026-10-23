// tests/cli_project_build: `vader build`, `run` and `check` given a project folder.
//
// A folder is described by its `build.vader` or by the `entries` of its
// `vader.json`, never by both, and a project's binaries go to
// `build/<profile>-<target>/`. The driven half has its own suite
// (`hook_driver.test.ts`); this one stages a manifest project in a temp folder.

import { afterEach, expect, test } from "bun:test";
import { existsSync, mkdirSync, mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { EXE_SUFFIX, HOST_TARGET, MEDIUM_BUILD, spawnCapture, TOOLCHAIN_ENV } from "./cli-bin.ts";

const staged: string[] = [];

afterEach(() => {
  for (const dir of staged.splice(0)) rmSync(dir, { recursive: true, force: true });
});

// A project of two programs, `app` and `tool`, each printing its name, plus a
// `data/greeting.txt` asset. `manifest` replaces the `vader.json`, or leaves the
// folder without one when null.
function stage(manifest: string | null): string {
  const dir = mkdtempSync(join(tmpdir(), "vader-project-"));
  staged.push(dir);
  mkdirSync(join(dir, "src"));
  mkdirSync(join(dir, "data"));
  writeFileSync(join(dir, "src/main.vader"), program("src", "app"));
  writeFileSync(join(dir, "tool.vader"), program("tool", "tool"));
  writeFileSync(join(dir, "data/greeting.txt"), "hello\n");
  if (manifest !== null) writeFileSync(join(dir, "vader.json"), manifest);
  return dir;
}

function program(module: string, says: string): string {
  return `module "${module}"\n\nimport "std/io"\n\nmain :: fn() -> i32 {\n    println("${says}")\n    return 0\n}\n`;
}

const TWO_ENTRIES = JSON.stringify({
  entries: { app: "src/main.vader", tool: "tool.vader" },
  assets: ["data"],
});

const vader = (args: string[], cwd?: string) =>
  spawnCapture(args, { cwd, env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD });

test("a project folder builds every entry into build/<profile>-<target>/", async () => {
  const dir = stage(TWO_ENTRIES);
  const r = await vader(["build", dir]);
  expect(r.stderr).not.toContain("error");
  expect(r.exit).toBe(0);
  const out = join(dir, "build", `debug-${HOST_TARGET}`);
  expect(existsSync(join(out, `app${EXE_SUFFIX}`))).toBe(true);
  expect(existsSync(join(out, `tool${EXE_SUFFIX}`))).toBe(true);
  // The C units sit in `c/` beside the binaries, not in the project folder.
  expect(existsSync(join(out, "c"))).toBe(true);
  // A folder asset is copied with what it holds.
  expect(existsSync(join(out, "data/greeting.txt"))).toBe(true);
}, MEDIUM_BUILD * 2);

test("--entry builds one entry, and --out needs exactly one", async () => {
  const dir = stage(TWO_ENTRIES);
  const both = await vader(["build", `--out=${join(dir, "x")}`, dir]);
  expect(both.exit).toBe(2);
  expect(both.stderr).toContain("choose one with `--entry=<name>`");

  const one = await vader(["build", "--entry=tool", `--out=${join(dir, "out/tool")}`, dir]);
  expect(one.exit).toBe(0);
  expect(existsSync(join(dir, `out/tool${EXE_SUFFIX}`))).toBe(true);
  expect(existsSync(join(dir, "out/data/greeting.txt"))).toBe(true);
  expect(existsSync(join(dir, "build"))).toBe(false);

  const unknown = await vader(["build", "--entry=nope", dir]);
  expect(unknown.exit).toBe(1);
  expect(unknown.stderr).toContain("declares no entry `nope`");
}, MEDIUM_BUILD * 2);

test("run takes one entry, and check takes them all", async () => {
  const dir = stage(TWO_ENTRIES);
  const ambiguous = await vader(["run", dir]);
  expect(ambiguous.exit).toBe(2);
  expect(ambiguous.stderr).toContain("`vader run` works on one program");

  const ran = await vader(["run", "--entry=tool", dir]);
  expect(ran.exit).toBe(0);
  expect(ran.stdout).toBe("tool\n");

  const checked = await vader(["check", dir]);
  expect(checked.exit).toBe(0);
}, MEDIUM_BUILD);

test("no argument builds the current folder", async () => {
  const dir = stage(JSON.stringify({ entries: { app: "src/main.vader" } }));
  const r = await vader(["build"], dir);
  expect(r.exit).toBe(0);
  expect(existsSync(join(dir, "build", `debug-${HOST_TARGET}`, `app${EXE_SUFFIX}`))).toBe(true);
}, MEDIUM_BUILD);

test("a folder that does not say what to build is refused", async () => {
  const bare = await vader(["build", stage(null)]);
  expect(bare.exit).toBe(1);
  expect(bare.stderr).toContain("holds neither a `build.vader` nor a `vader.json`");

  const empty = await vader(["build", stage(JSON.stringify({ name: "p" }))]);
  expect(empty.exit).toBe(1);
  expect(empty.stderr).toContain("declares no entry");

  const malformed = await vader(["build", stage(JSON.stringify({ entries: { app: 42 } }))]);
  expect(malformed.exit).toBe(1);
  expect(malformed.stderr).toContain("entry `app` is not the path of its entry file");

  const both = stage(TWO_ENTRIES);
  writeFileSync(join(both, "build.vader"), 'module "build"\n');
  const twice = await vader(["build", both]);
  expect(twice.exit).toBe(1);
  expect(twice.stderr).toContain("holds both a `build.vader` and a `vader.json`");
}, MEDIUM_BUILD);

test("an asset outside the project is refused", async () => {
  const dir = stage(JSON.stringify({ entries: { app: "src/main.vader" }, assets: ["../elsewhere"] }));
  const r = await vader(["build", dir]);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("asset `../elsewhere` is not inside the project");
}, MEDIUM_BUILD);

test("a file builds as it is, its C units in c/ beside the binary", async () => {
  const dir = stage(TWO_ENTRIES);
  const r = await vader(["build", join(dir, "tool.vader")]);
  expect(r.exit).toBe(0);
  expect(existsSync(join(dir, `tool${EXE_SUFFIX}`))).toBe(true);
  expect(existsSync(join(dir, "c"))).toBe(true);
  expect(existsSync(join(dir, "tool-_root.c"))).toBe(false);
}, MEDIUM_BUILD);
