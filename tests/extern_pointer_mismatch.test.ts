// A pointer argument the header's prototype does not accept fails the build, on
// each path that compiles the call against the header: the split build (the
// default), the single-unit one, and the adapter `vader run` calls a function
// returning a struct through. A matching declaration passes the same paths, so a
// failure is the mismatch and nothing else.
import { expect, test } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { EXE_SUFFIX, LONG_BUILD, haveCc, runCli } from "./cli-bin.ts";
import type { CliResult } from "./cli-bin.ts";

const HEADER = `typedef struct { int value; } first_t;

static inline first_t first_cell(int *cells) {
    first_t first = { cells[0] };
    return first;
}
`;

// How `first_cell` is declared: its parameter, and the elements of the array the
// program lends it.
interface Declaration {
  readonly parameter: string;
  readonly element: string;
}

interface Mismatch extends Declaration {
  readonly name: string;
  readonly message: RegExp;
}

const MISMATCHES: Mismatch[] = [
  {
    name: "an element @c_type names at another width",
    parameter: `@c_type("short") @c_out cells: i16[]`,
    element: "i16",
    message: /incompatible pointer type/,
  },
  {
    name: "an array lent without @c_out to a parameter C writes",
    parameter: "cells: i32[]",
    element: "i32",
    message: /discards/,
  },
];

const MATCH: Declaration = { parameter: `@c_type("int") @c_out cells: i32[]`, element: "i32" };

function source(d: Declaration): string {
  return `module "main"

import "std/console"

@c_struct("first_t")
First :: struct { value: i32 }

@c_header("first.h")
@extern("first_cell")
first_cell :: fn(${d.parameter}) -> First

main :: fn() -> i32 {
    cells: ${d.element}[]: [7, 8]
    println("\${first_cell(cells).value}")
    return 0
}
`;
}

function binaryIn(root: string): string {
  return `--out=${join(root, `app${EXE_SUFFIX}`)}`;
}

// Each path, as the command line it runs in the project folder `root`.
const PATHS: [string, (root: string) => string[]][] = [
  ["split build", (root) => ["build", binaryIn(root)]],
  ["single-unit build", (root) => ["build", "--no-split", binaryIn(root)]],
  ["vader run", () => ["run"]],
];

async function compile(command: (root: string) => string[], d: Declaration): Promise<CliResult> {
  const root = mkdtempSync(join(tmpdir(), "vader-extern-pointer-mismatch-"));
  try {
    writeFileSync(join(root, "first.h"), HEADER);
    const entry = join(root, "main.vader");
    writeFileSync(entry, source(d));
    return await runCli([...command(root), entry], undefined, LONG_BUILD);
  } finally {
    rmSync(root, { recursive: true, force: true });
  }
}

for (const [path, command] of PATHS) {
  for (const mismatch of MISMATCHES) {
    test(`${mismatch.name} fails the ${path}`, async () => {
      if (!(await haveCc())) return;
      const r = await compile(command, mismatch);
      expect(r.stderr).toMatch(mismatch.message);
      expect(r.exit).not.toBe(0);
    }, LONG_BUILD);
  }

  test(`a parameter the header accepts passes the ${path}`, async () => {
    if (!(await haveCc())) return;
    const r = await compile(command, MATCH);
    expect(r.exit).toBe(0);
  }, LONG_BUILD);
}
