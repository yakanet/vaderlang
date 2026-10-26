// tests/cli_doc: `vader doc`, the data of the API documentation.
//
// `shapes` is a project with two modules under `shapes/`, each over two
// files, beside a `main` the path leaves out. What the command writes under
// `build/doc/` is pinned file by file by `shapes.expected/`, which mirrors it,
// but for the `stamp` that says what the data was written from.
// `left_out` holds a `json` module, which the toolchain's own `json` shadows.

import { test, expect, afterAll } from "bun:test";
import { cpSync, existsSync, mkdirSync, mkdtempSync, readdirSync, readFileSync, rmSync, statSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { basename, dirname, join } from "node:path";
import { ensureCliBuilt, spawnCapture, MEDIUM_BUILD, TOOLCHAIN_ENV } from "./cli-bin.ts";
import { snapshotDiff } from "./diff.ts";
import { snapshotEquals } from "./snapshot.ts";

ensureCliBuilt();

const FIXTURES = join(import.meta.dir, "fixtures", "doc");
const UPDATE = process.env["UPDATE_SNAPSHOTS"] === "1";
const staged: string[] = [];

afterAll(() => {
  for (const dir of staged) rmSync(dir, { recursive: true, force: true });
});

// A copy of the fixture, since the command writes into the project's `build/`,
// without the `build/` a run inside the fixture itself would have left.
function stage(name: string): string {
  const dir = mkdtempSync(join(tmpdir(), "vader-doc-"));
  cpSync(join(FIXTURES, name), dir, { recursive: true });
  rmSync(join(dir, "build"), { recursive: true, force: true });
  staged.push(dir);
  return dir;
}

// `vader doc shapes` in the staged copy `dir`.
function docShapes(dir: string) {
  return spawnCapture(["doc", "shapes"], { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD });
}

// Every file under `root`, relative to it, `/`-separated and sorted.
function filesUnder(root: string): string[] {
  if (!existsSync(root)) return [];
  return (readdirSync(root, { recursive: true }) as string[])
    .filter((path) => statSync(join(root, path)).isFile())
    .map((path) => path.split("\\").join("/"))
    .sort();
}

test("doc writes the data of every module under its path", async () => {
  const dir = stage("shapes");
  const r = await docShapes(dir);
  expect(r.stderr).toBe("");
  expect(r.exit).toBe(0);
  const data = join(dir, "build", "doc");
  const expected = join(FIXTURES, "shapes.expected");
  // The stamp holds the absolute folders of the staged copy: it is checked by
  // the tests of freshness below.
  expect(existsSync(join(data, "stamp"))).toBe(true);
  const written = filesUnder(data).filter((file) => file !== "stamp");
  if (UPDATE) {
    rmSync(expected, { recursive: true, force: true });
  } else {
    expect(written).toEqual(filesUnder(expected));
  }
  for (const file of written) {
    const actual = readFileSync(join(data, file), "utf8");
    const snap = snapshotEquals(dirname(join(expected, file)), basename(file), actual);
    if (!snap.ok) {
      throw new Error(
        `Snapshot mismatch: ${snap.snapPath}\nRun with UPDATE_SNAPSHOTS=1 to refresh.\n\n` +
        snapshotDiff(snap.snapPath, snap.expected, actual),
      );
    }
  }
}, MEDIUM_BUILD);

// Run from elsewhere, `--project` gives the folder the path is read from, the
// data is written to and the files are named from: the same data.
test("doc reads the project --project names as if it ran there", async () => {
  const dir = stage("shapes");
  const r = await spawnCapture(["doc", `--project=${dir}`], { cwd: tmpdir(), env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD });
  expect(r.stderr).toBe("");
  expect(r.exit).toBe(0);
  const index = JSON.parse(readFileSync(join(dir, "build", "doc", "index.json"), "utf8"));
  expect(index.modules.map((m: { files: string[] }) => m.files).flat()).toEqual([
    "main.vader",
    "shapes/geometry/area.vader",
    "shapes/geometry/geometry.vader",
    "shapes/text/pin.vader",
    "shapes/text/text.vader",
  ]);
}, MEDIUM_BUILD);

// A module left out writes no stamp: the next run reads the modules again and
// says it again.
test("doc names a module another folder shadows, and leaves it out", async () => {
  const dir = stage("left_out");
  for (let run = 0; run < 2; run++) {
    const r = await spawnCapture(["doc", "apps"], { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD });
    expect(r.exit).toBe(0);
    expect(r.stderr).toContain("`json` (`apps/json`) is shadowed by the module of ");
  }
  expect(existsSync(join(dir, "build", "doc", "stamp"))).toBe(false);
  const index = JSON.parse(readFileSync(join(dir, "build", "doc", "index.json"), "utf8"));
  expect(index.modules.map((m: { path: string }) => m.path)).toEqual(["apps/app"]);
}, MEDIUM_BUILD);

// The stamp holds what the data was written from: the files the load read. A
// second run with none of them changed rewrites nothing, even when a module no
// load reaches appears.
test("doc leaves data that is up to date alone", async () => {
  const dir = stage("shapes");
  expect((await docShapes(dir)).stdout).toContain("modules written");
  expect((await docShapes(dir)).stdout).toContain("is up to date");
  mkdirSync(join(dir, "notes"));
  writeFileSync(join(dir, "notes", "notes.vader"), 'module "notes"\n');
  const again = await docShapes(dir);
  expect(again.exit).toBe(0);
  expect(again.stdout).toContain("is up to date");
}, MEDIUM_BUILD);

// A file the load read changes, or one joins a folder it read: the data is
// written again, and shows it.
test("doc writes the data again when what the load read changes", async () => {
  const dir = stage("shapes");
  await docShapes(dir);
  const area = join(dir, "shapes", "geometry", "area.vader");
  writeFileSync(area, readFileSync(area, "utf8") + "\n/// One.\nexport ONE :: 1\n");
  expect((await docShapes(dir)).stdout).toContain("modules written");
  writeFileSync(join(dir, "shapes", "geometry", "zero.vader"), 'module "shapes/geometry"\n\n/// Zero.\nexport ZERO :: 0\n');
  expect((await docShapes(dir)).stdout).toContain("modules written");
  const geometry = JSON.parse(readFileSync(join(dir, "build", "doc", "modules", "shapes", "geometry.json"), "utf8"));
  expect(geometry.decls.map((d: { name: string }) => d.name)).toEqual(expect.arrayContaining(["ONE", "ZERO"]));
}, MEDIUM_BUILD);

// The roots the load searches are part of what the data comes from: the
// generated tree appearing is one more, whose files join the module they
// declare, and a change to such a file is a change to what the load read.
test("doc writes the data again when a root appears or a generated file changes", async () => {
  const dir = stage("shapes");
  await docShapes(dir);
  const generated = join(dir, "build", "generated", "shapes", "geometry");
  mkdirSync(generated, { recursive: true });
  const gen = join(generated, "gen.vader");
  writeFileSync(gen, 'module "shapes/geometry"\n\n/// One, generated.\nexport GEN_ONE :: 1\n');
  expect((await docShapes(dir)).stdout).toContain("modules written");
  writeFileSync(gen, 'module "shapes/geometry"\n\n/// Two, generated.\nexport GEN_TWO :: 2\n');
  expect((await docShapes(dir)).stdout).toContain("modules written");
  const geometry = JSON.parse(readFileSync(join(dir, "build", "doc", "modules", "shapes", "geometry.json"), "utf8"));
  const names = geometry.decls.map((d: { name: string }) => d.name);
  expect(names).toContain("GEN_TWO");
  expect(names).not.toContain("GEN_ONE");
}, MEDIUM_BUILD);

// The load starts from the project's entry, as `vader lint` takes it: with two,
// `--entry` chooses.
test("doc asks which entry to start from when the project declares two", async () => {
  const dir = stage("shapes");
  writeFileSync(join(dir, "vader.json"), '{ "name": "shapes", "entries": { "a": "main.vader", "b": "main.vader" } }');
  const both = await docShapes(dir);
  expect(both.exit).toBe(2);
  expect(both.stderr).toContain("choose one with `--entry=<name>`");
  const chosen = await spawnCapture(["doc", "--entry=b", "shapes"], { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD });
  expect(chosen.stderr).toBe("");
  expect(chosen.exit).toBe(0);
}, MEDIUM_BUILD);

test("doc refuses a project its build.vader describes, for now", async () => {
  const dir = stage("shapes");
  rmSync(join(dir, "vader.json"));
  writeFileSync(join(dir, "build.vader"), "module \"build\"\n");
  const r = await docShapes(dir);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("which `vader doc` does not run yet");
}, MEDIUM_BUILD);

// A documented module is type-checked as a build checks it: its errors are
// shown, and its data is written all the same, with no stamp so that the next
// run shows them again.
test("doc shows a type error of a module it documents, and writes its data", async () => {
  const dir = stage("shapes");
  const file = join(dir, "shapes", "text", "text.vader");
  writeFileSync(file, readFileSync(file, "utf8") + "\nexport broken :: fn() -> i32 = \"not a number\"\n");
  const r = await docShapes(dir);
  expect(r.exit).toBe(0);
  expect(r.stderr).toContain("error[T3020]");
  expect(existsSync(join(dir, "build", "doc", "stamp"))).toBe(false);
  const text = JSON.parse(readFileSync(join(dir, "build", "doc", "modules", "shapes", "text.json"), "utf8"));
  expect(text.decls.map((d: { name: string }) => d.name)).toContain("broken");
}, MEDIUM_BUILD);

// Without a project, only the toolchain's roots are read: the folder's own
// modules are out of reach, and the command says why.
test("doc says that a folder without a project documents nothing", async () => {
  const dir = stage("shapes");
  rmSync(join(dir, "vader.json"));
  const r = await docShapes(dir);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("the working directory holds no project");
}, MEDIUM_BUILD);

test("doc refuses a path that holds no module", async () => {
  const dir = stage("shapes");
  const r = await spawnCapture(["doc", "nowhere"], { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD });
  expect(r.exit).toBe(2);
  expect(r.stderr).toContain("`nowhere` does not exist");
}, MEDIUM_BUILD);
