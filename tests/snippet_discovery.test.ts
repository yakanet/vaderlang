// Unit tests for `listSnippets`' helper-C detection — the one piece of the
// harness whose misbehaviour is SILENT.
//
// `vader_vm.test.ts` skips any snippet that `listSnippets` reports a helper `.c`
// for, since the interpreter resolves `@extern` by `dlsym` on the running process
// and cannot reach a symbol linked into some other executable. So a false
// positive there does not fail anything — it removes a parity test and the suite
// still prints green, one test lighter. That is exactly what a stray
// `vader build --split` output in a snippet directory used to do, and the files
// are gitignored, so `git status` showed nothing either.
//
// These tests run against a temp directory rather than the real corpus: the
// point is what `listSnippets` does with a given set of files, and a corpus that
// happens to hold none of them today would pin nothing tomorrow.

import { afterAll, beforeAll, expect, test } from "bun:test";
import { mkdirSync, mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { basename, join } from "node:path";

import { listSnippets, MAIN_FILE } from "./snapshot.ts";

let root: string;

/** A snippet directory holding `_main.vader` plus `files`. */
function snippet(name: string, files: readonly string[]): void {
  const dir = join(root, name);
  mkdirSync(dir, { recursive: true });
  writeFileSync(join(dir, MAIN_FILE), 'module "snippet"\n\nmain :: fn() -> i32 {\n    return 0\n}\n');
  for (const f of files) writeFileSync(join(dir, f), "/* fixture */\n");
}

function helpersOf(name: string): string[] {
  const s = listSnippets(root).find((x) => x.name === name);
  if (!s) throw new Error(`snippet ${name} was not discovered`);
  return s.helperCFiles.map((p) => basename(p));
}

beforeAll(() => {
  root = mkdtempSync(join(tmpdir(), "vader-snippet-discovery-"));
  snippet("plain", []);
  snippet("with_helper", ["helper.c"]);
  snippet("mono_build", ["native.c", "_main.c"]);
  // What `vader build --split` — the DEFAULT — leaves behind.
  snippet("split_build", ["_main-_glue.c", "_main-_root.c", "_main-snippet.c", "_main.split.g.c"]);
  snippet("helper_and_split", ["helper.c", "_main-_root.c", "native.c"]);
});

afterAll(() => {
  rmSync(root, { recursive: true, force: true });
});

test("a snippet with no .c files reports no helpers", () => {
  expect(helpersOf("plain")).toEqual([]);
});

test("a real helper.c is reported", () => {
  expect(helpersOf("with_helper")).toEqual(["helper.c"]);
});

test("mono build artefacts are not helpers", () => {
  expect(helpersOf("mono_build")).toEqual([]);
});

test("--split build artefacts are not helpers", () => {
  // The regression: these counted as helpers and silently turned the snippet's
  // `vader-vm` parity test into a skip.
  expect(helpersOf("split_build")).toEqual([]);
});

test("a real helper survives alongside build artefacts", () => {
  // The failure mode that matters in the other direction: over-filtering would
  // drop a genuine `@extern` helper and break the native run instead.
  expect(helpersOf("helper_and_split")).toEqual(["helper.c"]);
});
