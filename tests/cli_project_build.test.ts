// tests/cli_project_build: `vader build`, `run` and `check` given a project folder,
// and `vader run` given a file within the project `--project` names.
//
// A folder is described by its `build.vader` or by the `entries` of its
// `vader.json`, never by both, and a project's binaries go to
// `build/<profile>-<target>/`. The driven half has its own suite
// (`hook_driver.test.ts`); this one stages a manifest project in a temp folder.

import { afterEach, expect, test } from "bun:test";
import { existsSync, mkdirSync, mkdtempSync, readFileSync, rmSync, writeFileSync } from "node:fs";
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
  // The C units sit in `c/` beside the binaries, their objects in `obj/`, not
  // in the project folder.
  expect(existsSync(join(out, "c", "app.split.h"))).toBe(true);
  expect(existsSync(join(out, "obj", "app.split.runtime.o"))).toBe(true);
  expect(existsSync(join(out, "c", "app.split.runtime.o"))).toBe(false);
  // A folder asset is copied with what it holds.
  expect(existsSync(join(out, "data/greeting.txt"))).toBe(true);
}, MEDIUM_BUILD * 2);

test("--entry builds one entry, and --out needs exactly one", async () => {
  const dir = stage(TWO_ENTRIES);
  const both = await vader(["build", `--out=${join(dir, "x")}`, dir]);
  expect(both.exit).toBe(1);
  expect(both.stderr).toContain("vader.json:1:1] error[H6011]");

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

test("--project runs one file of a project with the project's search roots", async () => {
  const dir = stage(JSON.stringify({ includePaths: ["libs"], entries: { app: "src/main.vader" } }));
  mkdirSync(join(dir, "libs/greet"), { recursive: true });
  writeFileSync(
    join(dir, "libs/greet/greet.vader"),
    `module "greet"\n\n/// The word the program prints.\nexport word :: fn() -> string = "greeted"\n`,
  );
  const file = join(dir, "src/main.vader");
  writeFileSync(
    file,
    `module "src"\n\nimport "greet"\nimport "std/io"\n\nmain :: fn() -> i32 {\n    println(word())\n    return 0\n}\n`,
  );

  const alone = await vader(["run", file]);
  expect(alone.exit).toBe(1);
  expect(alone.stdout + alone.stderr).toContain("module not found: `greet`");

  const within = await vader(["run", `--project=${dir}`, file]);
  expect(within.stderr).toBe("");
  expect(within.exit).toBe(0);
  expect(within.stdout).toBe("greeted\n");

  const folder = await vader(["run", `--project=${dir}`, dir]);
  expect(folder.exit).toBe(2);
  expect(folder.stderr).toContain("`--project` names the project of a file");
}, MEDIUM_BUILD);

test("info describes a project folder and builds nothing", async () => {
  const dir = stage(TWO_ENTRIES);
  const text = await vader(["info", dir]);
  expect(text.exit).toBe(0);
  expect(text.stdout).toContain("(vader.json)");
  expect(text.stdout).toContain("entry    tool → tool.vader");

  const json = await vader(["info", "--json", dir]);
  expect(json.exit).toBe(0);
  const described = JSON.parse(json.stdout);
  expect(described.kind).toBe("manifest");
  expect(described.entries).toEqual({ app: "src/main.vader", tool: "tool.vader" });
  expect(described.assets).toEqual(["data"]);
  expect(described.includePaths).toEqual([]);
  expect(existsSync(join(dir, "build"))).toBe(false);

  const file = await vader(["info", join(dir, "tool.vader")]);
  expect(file.exit).toBe(1);
  expect(file.stderr).toContain("is a file; name a project folder");

  const missing = await vader(["info", join(dir, "nope")]);
  expect(missing.exit).toBe(1);
  expect(missing.stderr).toContain("does not exist");
}, MEDIUM_BUILD);

test("eject writes the build.vader a vader.json stands for", async () => {
  const dir = stage(JSON.stringify({
    includePaths: ["$VADER_HOME/third_party"],
    entries: { app: "src/main.vader" },
    assets: ["data"],
  }));
  rmSync(join(dir, "tool.vader"));
  const kept = await vader(["eject", "--preserve-manifest", dir]);
  expect(kept.exit).toBe(0);
  const driver = readFileSync(join(dir, "build.vader"), "utf8");
  expect(driver).toContain('ctx.include_paths.push(r"$VADER_HOME/third_party")');
  expect(driver).toContain('ctx.add_entry("app", "src/main.vader")');
  expect(driver).toContain('ctx.add_asset("data")');
  expect(existsSync(join(dir, "vader.json"))).toBe(true);

  // The kept vader.json is the user's to remove: until then the folder holds both.
  const both = await vader(["eject", dir]);
  expect(both.exit).toBe(1);
  expect(both.stderr).toContain("holds both a `build.vader` and a `vader.json`");

  rmSync(join(dir, "build.vader"));
  const ejected = await vader(["eject", dir]);
  expect(ejected.exit).toBe(0);
  expect(existsSync(join(dir, "vader.json"))).toBe(false);

  const again = await vader(["eject", dir]);
  expect(again.exit).toBe(1);
  expect(again.stderr).toContain("is already built by its `build.vader`");
}, MEDIUM_BUILD);

test("eject asks to move the sources out of the project root first", async () => {
  const dir = stage(TWO_ENTRIES);
  const r = await vader(["eject", dir]);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("move the sources at the root");
  expect(r.stderr).toContain("(`tool.vader`)");
  expect(existsSync(join(dir, "build.vader"))).toBe(false);
  expect(existsSync(join(dir, "vader.json"))).toBe(true);
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

  const misspelt = await vader(["build", stage(JSON.stringify({ entries: { app: "src/main.vader" }, asset: ["data"] }))]);
  expect(misspelt.exit).toBe(1);
  expect(misspelt.stderr).toContain("unknown key `asset`");

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

test("a file builds as it is, its C units in c/ and its objects in obj/ beside the binary", async () => {
  const dir = stage(TWO_ENTRIES);
  const r = await vader(["build", join(dir, "tool.vader")]);
  expect(r.exit).toBe(0);
  expect(existsSync(join(dir, `tool${EXE_SUFFIX}`))).toBe(true);
  expect(existsSync(join(dir, "c"))).toBe(true);
  expect(existsSync(join(dir, "obj"))).toBe(true);
  expect(existsSync(join(dir, "tool-_root.c"))).toBe(false);
}, MEDIUM_BUILD);
