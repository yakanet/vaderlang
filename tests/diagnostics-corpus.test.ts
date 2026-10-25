// tests/diagnostics-corpus: native diagnostic-code corpus (no TS parity).
//
// Negative fixtures under tests/diag_corpus/<bucket>/<name>/ each provoke a
// specific compiler diagnostic. This suite dumps the native Vader compiler at
// the `lowered-ast` stage — which accumulates every front-end diagnostic
// (lexer → parser → resolver → typecheck → comptime) — and snapshots every
// emitted `[span] severity[CODE] message` line per fixture. The self-hosted
// compiler is the oracle; the former TS↔Vader set-parity was dropped with the TS
// reference.
//
// Positive snippets under tests/snippets/ already carry their diagnostics in
// the snapshot.test.ts stage snapshots, so they are not duplicated here.
//
// A fixture is named after the code its rule calls for (`t3001_type_mismatch`).
// When the compiler reports another one (`c4006_file_not_found` reports C4001),
// the committed snapshot records the code actually emitted, which keeps the gap
// visible.
// Refresh with UPDATE_SNAPSHOTS=1.

import { test, expect } from "bun:test";
import { readdirSync } from "node:fs";
import { join } from "node:path";

import { SNAPSHOT_TARGET, listSnippets, snapshotEquals, type Scenario } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { MEDIUM_BUILD, runCli } from "./cli-bin.ts";

// `[L:C] error[XXXX] message` / `[L:C] warning[XXXX] message`, one per line.
const DIAG_RE = /^\[(\d+:\d+)\]\s+(error|warning)\[([A-Z]\d{4})\](.*)$/gm;

// Sorted diagnostic lines, message included, stable across decl-walk order.
function diagSet(output: string): string {
  const refs = Array.from(output.matchAll(DIAG_RE), m => `[${m[1]}] ${m[2]}[${m[3]}]${m[4]!.trimEnd()}`).sort();
  return refs.length > 0 ? refs.join("\n") + "\n" : "# (no diagnostics)\n";
}

// diag_corpus/<bucket>/<name>/ fixtures, surfaced as `<bucket>/<name>`.
function corpusScenarios(): Scenario[] {
  try {
    return readdirSync("tests/diag_corpus", { withFileTypes: true })
      .filter(b => b.isDirectory())
      .flatMap(b => listSnippets(join("tests/diag_corpus", b.name))
        .map(s => ({ ...s, name: `${b.name}/${s.name}` })));
  } catch { return []; /* corpus dir optional */ }
}

const scenarios = corpusScenarios();

test("diag-corpus: at least one fixture discovered", () => {
  expect(scenarios.length).toBeGreaterThan(0);
});

for (const s of scenarios) {
  test.concurrent(`diag-corpus: ${s.name}`, async () => {
    // Pinned to one target, as every snippet stage is: a `@target` group picks
    // its body by platform, so what is checked, and reported, can differ by host.
    const { stdout, stderr } = await runCli(["dump", "--stage=lowered-ast", `--target=${SNAPSHOT_TARGET}`, s.mainPath]);
    const actual = diagSet(`${stdout}\n${stderr}`);
    const cmp = snapshotEquals(s.dir, "diagnostics.snapshot", actual);
    if (!cmp.ok) {
      throw new Error(
        `diag-corpus mismatch: ${s.name}\n  snap: ${cmp.snapPath}\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected, actual),
      );
    }
  }, { timeout: MEDIUM_BUILD });
}
