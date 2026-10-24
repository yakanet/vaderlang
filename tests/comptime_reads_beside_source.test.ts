// tests/comptime_reads_beside_source: a `@comptime` value is evaluated in the
// folder of the file that declares it, so a relative path it reads names a file
// beside that source, wherever the compiler was started, and the compiler's own
// working directory comes back afterwards.
//
// The source sits in `src/`, the compiler runs from the folder above, and the
// output path is relative: a working directory left in `src/` would put the
// binary in the wrong place. The data holds what a text path would mangle (a
// NUL, 0xFF, a byte the C emitter escapes before a hex digit, CR, LF, a quote, a
// backslash), printed as numbers so the comparison never reads it as text.

import { afterAll, expect, test } from "bun:test";
import { mkdirSync, mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { EXE_SUFFIX, LONG_BUILD, MEDIUM_BUILD, spawnCapture, TOOLCHAIN_ENV } from "./cli-bin.ts";

const DATA = [0x00, 0xff, 0x01, 0x61, 0x0d, 0x0a, 0x22, 0x5c];
const EXPECTED = `${DATA.length} bytes\n${DATA.map((b) => `${b}\n`).join("")}`;

const dir = mkdtempSync(join(tmpdir(), "vader-comptime-reads-"));
mkdirSync(join(dir, "src"));
writeFileSync(join(dir, "src", "data.bin"), Uint8Array.from(DATA));
writeFileSync(
  join(dir, "src", "main.vader"),
  `module "main"\n\nimport "std/abort"\nimport "std/io"\n\n`
    + `DATA :: @comptime {\n    read :: read_file_bytes("data.bin", 1024)\n`
    + `    if read is IOError {\n        panic("cannot read \`data.bin\`: \${read.message()}")\n    }\n`
    + `    return read\n}\n\n`
    + `main :: fn() -> i32 {\n    println("\${DATA.len()} bytes")\n`
    + `    for b in DATA {\n        println("\${b}")\n    }\n    return 0\n}\n`,
);

afterAll(() => {
  rmSync(dir, { recursive: true, force: true });
});

test("a @comptime read names a file beside its source, on the interpreter", async () => {
  const run = await spawnCapture(["run", join("src", "main.vader")], {
    cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD,
  });
  expect(run.stderr).toBe("");
  expect(run.stdout).toBe(EXPECTED);
}, LONG_BUILD);

test("a @comptime read names a file beside its source, in a native build", async () => {
  const out = join("out", "main");
  const build = await spawnCapture(["build", `--out=${out}`, join("src", "main.vader")], {
    cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD,
  });
  expect(build.stderr).not.toContain("error");
  expect(build.exit).toBe(0);
  const run = await spawnCapture([], { bin: join(dir, out + EXE_SUFFIX), cwd: dir });
  expect(run.stdout).toBe(EXPECTED);
}, LONG_BUILD);

// The comptime VM runs on the build machine, so in a build for another OS a
// value runs the host's `@target` bodies: the target's would call into a library
// this machine does not have (`kernel32` from a Mac).
const OTHER_OS = process.platform === "win32" ? "linux-x86_64" : "windows-x86_64";

test("a @comptime read runs the build machine's bodies in a build for another OS", async () => {
  const dump = await spawnCapture(["dump", "--stage=evaluated-ast", `--target=${OTHER_OS}`, join("src", "main.vader")], {
    cwd: dir, env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD,
  });
  expect(dump.stdout).toContain(`@comptime DATA = [${DATA.map((b) => `${b}_u8`).join(", ")}]`);
}, LONG_BUILD);
