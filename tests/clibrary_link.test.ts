// tests/clibrary_link.test.ts: a program calling a C library through a
// `CLibrary` constant (`std/ffi`) builds and runs with no flag from the user.
//
// The fixture's binding names its header folder, its archive under
// `lib/<os>-<arch>/` and a platform library. The test compiles the archive for
// this machine, then checks that `vader build` adds the `-I`, links the archive
// and evaluates the paths for the target, in both the split and the single-TU
// builds, and through a `.virt`. A missing archive is reported by the build,
// before `cc`, and the interpreter, which opens no archive, says the program
// needs a native build.

import { afterAll, expect, test } from "bun:test";
import { cpSync, mkdirSync, mkdtempSync, readFileSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join, resolve } from "node:path";
import { EXE_SUFFIX, HOST_TARGET, LONG_BUILD, spawnCapture, TOOLCHAIN_ENV } from "./cli-bin.ts";

const FIXTURE = resolve(import.meta.dir, "fixtures/clibrary");
// `$CC` first, as `vader build` reads it.
const CC = process.env.CC || "cc";

const staged: string[] = [];

afterAll(() => {
  for (const dir of staged) {
    rmSync(dir, { recursive: true, force: true });
  }
});

// A copy of the fixture, with the greeter archive compiled for this machine when
// `withArchive` holds.
async function stage(withArchive: boolean): Promise<string> {
  const dir = mkdtempSync(join(tmpdir(), "vader-clibrary-"));
  staged.push(dir);
  cpSync(FIXTURE, dir, { recursive: true });
  if (!withArchive) {
    return dir;
  }
  const greeter = join(dir, "vendor/greeter");
  const libDir = join(greeter, "lib", HOST_TARGET);
  mkdirSync(libDir, { recursive: true });
  const object = join(libDir, "greeter.o");
  const compile = Bun.spawnSync([CC, "-c", "-I", join(greeter, "include"), join(greeter, "greeter.c"), "-o", object]);
  expect(compile.exitCode).toBe(0);
  const archive = Bun.spawnSync(["ar", "rcs", join(libDir, "libgreeter.a"), object]);
  expect(archive.exitCode).toBe(0);
  return dir;
}

for (const split of [true, false]) {
  const mode = split ? "split" : "single TU";
  test(`a CLibrary links by itself (${mode})`, async () => {
    const dir = await stage(true);
    const out = join(dir, "main");
    const flags = split ? [] : ["--no-split"];
    const build = await spawnCapture(
      ["build", ...flags, `--out=${out}`, dir],
      { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
    );
    expect(build.stderr).not.toContain("error");
    expect(build.exit).toBe(0);
    const run = await spawnCapture([], { bin: out + EXE_SUFFIX, cwd: dir });
    expect(run.stdout).toBe("hello from C: 42\n");
    expect(run.exit).toBe(0);
  }, LONG_BUILD);
}

test("a CLibrary's calls compile in a unit of their own", async () => {
  // Two libraries' headers need not agree (`raylib.h` and `<windows.h>` do
  // not), so a library's header is included by its unit alone; every other
  // unit reaches its shims through prototypes.
  const dir = await stage(false);
  const split = join(dir, "split", "main");
  const emitted = await spawnCapture(
    ["build", "--emit=c", `--out=${split}`, dir],
    { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
  );
  expect(emitted.exit).toBe(0);
  const unit = readFileSync(`${split}-_ffi_greeter.c`, "utf8");
  expect(unit).toContain('#include "greeter.h"');
  const imports = readFileSync(`${split}.imports.h`, "utf8");
  expect(imports).not.toContain("greeter.h");
  expect(imports).toContain("extern");

  const single = join(dir, "single", "main.c");
  const mono = await spawnCapture(
    ["build", "--emit=c", "--no-split", `--out=${single}`, dir],
    { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
  );
  expect(mono.exit).toBe(0);
  expect(readFileSync(single, "utf8")).not.toContain("greeter.h");
  expect(readFileSync(join(dir, "single", "main-_ffi_greeter.c"), "utf8")).toContain('#include "greeter.h"');

  // One stream holds one unit, every shim in it.
  const stream = await spawnCapture(
    ["build", "--emit=c", "--out=-", dir],
    { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
  );
  expect(stream.exit).toBe(0);
  expect(stream.stdout).toContain('#include "greeter.h"');
}, LONG_BUILD);

test("a `.virt` carries the library to a native build", async () => {
  const dir = await stage(true);
  const virt = join(dir, "main.virt");
  const dump = await spawnCapture(
    ["build", "--emit=bytecode-text", `--out=${virt}`, dir],
    { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
  );
  expect(dump.exit).toBe(0);
  const out = join(dir, "from-virt");
  const build = await spawnCapture(
    ["build", `--out=${out}`, virt],
    { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
  );
  expect(build.stderr).not.toContain("error");
  expect(build.exit).toBe(0);
  const run = await spawnCapture([], { bin: out + EXE_SUFFIX, cwd: dir });
  expect(run.stdout).toBe("hello from C: 42\n");
}, LONG_BUILD);

test("a missing archive stops the build and names the path", async () => {
  const dir = await stage(false);
  const build = await spawnCapture(
    ["build", `--out=${join(dir, "main")}`, dir],
    { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
  );
  expect(build.exit).toBe(1);
  expect(build.stderr).toContain("library `greeter` has no archive for this target");
  expect(build.stderr).toContain(`lib/${HOST_TARGET}/libgreeter.a`);
}, LONG_BUILD);

test("the interpreter says a library shipped as archives needs a native build", async () => {
  const dir = await stage(false);
  const run = await spawnCapture(
    ["run", dir],
    { cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD },
  );
  expect(run.exit).toBe(1);
  expect(run.stderr).toContain("cannot open `greeter`: its binding ships static archives");
  expect(run.stderr).toContain("build the program with `vader build`");
}, LONG_BUILD);
