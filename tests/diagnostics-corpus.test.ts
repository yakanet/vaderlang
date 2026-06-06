// tests/diagnostics-corpus — native diagnostic-code corpus (no TS parity).
//
// Negative fixtures under tests/diag_corpus/<bucket>/<name>/ each provoke a
// specific compiler diagnostic. This suite dumps the native Vader compiler at
// the `lowered-ast` stage — which accumulates every front-end diagnostic
// (lexer → parser → resolver → typecheck → comptime) — and snapshots the
// emitted `[span] severity[CODE]` set per fixture. The self-hosted compiler is
// the oracle; the former TS↔Vader set-parity was dropped with the TS reference.
//
// Positive snippets under tests/snippets/ already carry their diagnostics in
// the snapshot.test.ts stage snapshots, so they are not duplicated here.
//
// Fixture dir names (e.g. `t3001_type_mismatch`) are historical labels from the
// TS reference codes. Where the native compiler emits a renumbered code
// (e.g. C4006→C4001, P1013→P1006, R2007→R2006) the committed snapshot records
// the actual native code, making the divergence visible rather than hidden.
// Refresh with UPDATE_SNAPSHOTS=1.

import { test, expect } from "bun:test";
import { readdirSync } from "node:fs";
import { join } from "node:path";

import { listSnippets, snapshotEquals, type Scenario } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { MEDIUM_BUILD, runCli } from "./cli-bin.ts";

// `[L:C]  error[XXXX]` / `[L:C]  warning[XXXX]` — code + span, message-agnostic.
const DIAG_RE = /\[(\d+:\d+)\]\s+(error|warning)\[([A-Z]\d{4})\]/g;

// Sorted, message-free diagnostic set — stable across decl-walk order and
// immune to wording churn.
function diagSet(output: string): string {
  const refs = Array.from(output.matchAll(DIAG_RE), m => `[${m[1]}] ${m[2]}[${m[3]}]`).sort();
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
    const { stdout, stderr } = await runCli(["dump", "--stage=lowered-ast", s.mainPath]);
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
