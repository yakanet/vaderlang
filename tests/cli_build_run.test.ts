// tests/cli_build_run: `vader build --run` builds, then runs the program on the
// command's own standard streams, hands it what follows the path, and exits with
// its code.
//
// The program writes to stdout and stderr, which the harness captures through
// pipes: what it reads here is what the child wrote to the streams it inherited.
// Project folders are tested with the other project commands, in
// `cli_project_build.test.ts` and `hook_driver.test.ts`.

import { afterEach, expect, test } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { MEDIUM_BUILD, spawnCapture, TOOLCHAIN_ENV } from "./cli-bin.ts";

const staged: string[] = [];

afterEach(() => {
  for (const dir of staged.splice(0)) rmSync(dir, { recursive: true, force: true });
});

function stagedDir(): string {
  const dir = mkdtempSync(join(tmpdir(), "vader-build-run-"));
  staged.push(dir);
  return dir;
}

// Prints `says`, then each argument on a line, a line on stderr, and exits with
// `code`.
function program(says: string, code: number): string {
  return `module "main"\n\nimport "std/io"\n\n`
    + `main :: fn(argv: string[]) -> i32 {\n    println("${says}")\n`
    + `    for i in 1..<argv.len() {\n        println(argv[i])\n    }\n`
    + `    eprintln("${says} on stderr")\n    return ${code}\n}\n`;
}

const vader = (args: string[], cwd: string) =>
  spawnCapture(args, { cwd, env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD });

test("a file is built, then run with what follows its path, and its code is the exit code", async () => {
  const dir = stagedDir();
  writeFileSync(join(dir, "main.vader"), program("app", 7));
  const r = await vader(["build", "--run", "main.vader", "--verbose", "two words"], dir);
  expect(r.stdout).toBe("app\n--verbose\ntwo words\n");
  expect(r.stderr).toContain("app on stderr");
  expect(r.exit).toBe(7);
}, MEDIUM_BUILD * 2);

test("a build that fails runs nothing", async () => {
  const dir = stagedDir();
  writeFileSync(join(dir, "main.vader"), `module "main"\n\nmain :: fn() -> i32 {\n    return "no"\n}\n`);
  const r = await vader(["build", "--run", "main.vader"], dir);
  expect(r.stdout).toBe("");
  expect(r.stderr).toContain("error[");
  expect(r.exit).toBe(1);
}, MEDIUM_BUILD);

test("an executable for another platform needs a C compiler for it", async () => {
  const dir = stagedDir();
  writeFileSync(join(dir, "main.vader"), program("app", 0));
  const other = process.platform === "win32" ? "linux-x86_64" : "windows-x86_64";
  // `CC` emptied: a machine that exports one (the Windows CI does) would pass the check.
  const env = { ...TOOLCHAIN_ENV, CC: "" };
  const run = (args: string[]) => spawnCapture(args, { cwd: dir, env, timeoutMs: MEDIUM_BUILD });
  for (const target of [other, "browser-wasm32"]) {
    const cross = await run(["build", `--target=${target}`, "main.vader"]);
    expect({ target, exit: cross.exit }).toEqual({ target, exit: 2 });
    expect(cross.stderr).toContain(`name a compiler for \`${target}\` with \`--cc\``);
  }
  // The C needs no compiler, whatever the target.
  const c = await run(["build", "--emit=c", `--target=${other}`, `--out=${join(dir, "main.c")}`, "main.vader"]);
  expect(c.exit).toBe(0);
}, MEDIUM_BUILD);

test("--run refuses a build that produces no program for this machine", async () => {
  const dir = stagedDir();
  writeFileSync(join(dir, "main.vader"), program("app", 0));
  const c = await vader(["build", "--run", "--emit=c", "main.vader"], dir);
  expect(c.exit).toBe(2);
  expect(c.stderr).toContain("`--emit=c` produces no program to run");

  const other = process.platform === "win32" ? "linux-x86_64" : "windows-x86_64";
  const cross = await vader(["build", "--run", `--target=${other}`, "main.vader"], dir);
  expect(cross.exit).toBe(2);
  expect(cross.stderr).toContain(`a program built for \`${other}\` does not run on this`);
}, MEDIUM_BUILD);
