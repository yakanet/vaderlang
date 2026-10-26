// An array literal becomes bytecode that pushes every element, then builds the
// array: as many constants, and as deep a stack, as the literal has elements.
// A copy of a `@comptime` table is built that way too, by its accessor. The
// register engine runs both, and the array is the program's own to write.
import { expect, test } from "bun:test";
import { mkdtempSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { MEDIUM_BUILD, runCli } from "./cli-bin.ts";

const ELEMENTS = 200_000;

const TABLE_SOURCE = `module "main"

import "std/io"

multiples :: fn(n: i32) -> i32[] {
    out: i32[]: [] * i64(n)
    for i in 0..<n {
        out.push(i * 3)
    }
    return out
}

TABLE: i32[]: @comptime multiples(${ELEMENTS})

main :: fn() -> i32 {
    copy :: TABLE
    copy[0] = -1
    println("\${copy.len()} \${copy[0]} \${copy[${ELEMENTS - 1}]} \${TABLE[0]}")
    return 0
}
`;

const multiples = Array.from({ length: ELEMENTS }, (_, i) => i * 3).join(", ");

const LITERAL_SOURCE = `module "main"

import "std/io"

main :: fn() -> i32 {
    xs :: [${multiples}]
    xs[0] = -1
    println("\${xs.len()} \${xs[0]} \${xs[${ELEMENTS - 1}]} 0")
    return 0
}
`;

const EXPECTED = `${ELEMENTS} -1 ${(ELEMENTS - 1) * 3} 0\n`;

async function runSource(source: string) {
  const dir = mkdtempSync(join(tmpdir(), "vader-constant-table-"));
  const src = join(dir, "main.vader");
  writeFileSync(src, source);
  return runCli(["run", src], undefined, MEDIUM_BUILD);
}

test(
  "vader run copies a comptime table of 200 000 elements",
  async () => {
    const run = await runSource(TABLE_SOURCE);
    expect(run.stderr).toBe("");
    expect(run.stdout).toBe(EXPECTED);
    expect(run.exit).toBe(0);
  },
  MEDIUM_BUILD,
);

test(
  "vader run builds an array literal of 200 000 elements",
  async () => {
    const run = await runSource(LITERAL_SOURCE);
    expect(run.stderr).toBe("");
    expect(run.stdout).toBe(EXPECTED);
    expect(run.exit).toBe(0);
  },
  MEDIUM_BUILD,
);
