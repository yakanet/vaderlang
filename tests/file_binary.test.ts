// tests/file_binary: `@file` bakes a binary file byte for byte, on the
// interpreter and in a native build alike.
//
// The data holds what a text path would mangle: a NUL, 0xFF (no UTF-8), a byte
// the C emitter escapes followed by a hex digit, CR, LF, a quote and a
// backslash. The program prints each byte as a number, so the comparison never
// reads the bytes as text. Not a snippet: the snippet harness captures a dump as
// text, which turns 0xFF into U+FFFD before the interpreter runs it.

import { afterAll, expect, test } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { EXE_SUFFIX, LONG_BUILD, MEDIUM_BUILD, spawnCapture, TOOLCHAIN_ENV } from "./cli-bin.ts";

const DATA = [0x00, 0xff, 0x01, 0x61, 0x0d, 0x0a, 0x22, 0x5c];
const EXPECTED = `${DATA.length} bytes\n${DATA.map((b) => `${b}\n`).join("")}`;

const dir = mkdtempSync(join(tmpdir(), "vader-file-binary-"));
writeFileSync(join(dir, "data.bin"), Uint8Array.from(DATA));
writeFileSync(
  join(dir, "main.vader"),
  `module "main"\n\nimport "std/io"\n\nDATA :: @file("data.bin")\n\n`
    + `main :: fn() -> i32 {\n    bytes :: DATA.bytes()\n    println("\${bytes.len()} bytes")\n`
    + `    for b in bytes {\n        println("\${b}")\n    }\n    return 0\n}\n`,
);

afterAll(() => {
  rmSync(dir, { recursive: true, force: true });
});

test("@file keeps a binary file's bytes on the interpreter", async () => {
  const run = await spawnCapture(["run", join(dir, "main.vader")], { env: TOOLCHAIN_ENV, timeoutMs: MEDIUM_BUILD });
  expect(run.stderr).toBe("");
  expect(run.stdout).toBe(EXPECTED);
}, LONG_BUILD);

test("@file keeps a binary file's bytes in a native build", async () => {
  const out = join(dir, "main");
  const build = await spawnCapture(["build", `--out=${out}`, join(dir, "main.vader")], { env: TOOLCHAIN_ENV, timeoutMs: LONG_BUILD });
  expect(build.exit).toBe(0);
  const run = await spawnCapture([], { bin: out + EXE_SUFFIX, cwd: dir });
  expect(run.stdout).toBe(EXPECTED);
}, LONG_BUILD);
