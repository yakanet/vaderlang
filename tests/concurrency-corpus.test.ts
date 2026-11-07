// tests/concurrency-corpus: the task check held to the concurrency model's corpus.
//
// Each fixture under tests/concurrency_corpus/<name>/ is a program of the corpus
// the model was designed against (`cNN`), or a probe of its edges (`pNN`). Its
// header says what the task check answers: `// expect: accepted`, or the codes it
// reports (`// expect: T3128 T3129`). A probe the check answers wrongly says what
// it should answer on a `// gap:` line, and its `expect` keeps the wrong answer,
// so that closing the gap shows in the diff. Every diagnostic line is also pinned
// in `diagnostics.snapshot`, as the diagnostics corpus does.
// Refresh with UPDATE_SNAPSHOTS=1.

import { test, expect } from "bun:test";
import { readFileSync } from "node:fs";

import { SNAPSHOT_TARGET, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { MEDIUM_BUILD, runCli } from "./cli-bin.ts";

// `[L:C] error[XXXX] message` / `[L:C] warning[XXXX] message`, one per line.
const DIAG_RE = /^\[(\d+:\d+)\]\s+(error|warning)\[([A-Z]\d{4})\](.*)$/gm;

// The codes of the task check (`vader/front/effects/task_errors.vader`).
const TASK_CODES = new Set(["T3128", "T3129", "T3130", "T3131", "T3132", "T3133", "T3134"]);

const EXPECT_RE = /^\/\/ expect: (.*)$/m;

// Sorted diagnostic lines, message included, stable across decl-walk order.
function diagSet(output: string): string {
  const refs = Array.from(output.matchAll(DIAG_RE), m => `[${m[1]}] ${m[2]}[${m[3]}]${m[4]!.trimEnd()}`).sort();
  return refs.length > 0 ? refs.join("\n") + "\n" : "# (no diagnostics)\n";
}

// The task codes `output` reports, as a header writes them.
function verdict(output: string): string {
  const codes = new Set(Array.from(output.matchAll(DIAG_RE), m => m[3]!).filter(c => TASK_CODES.has(c)));
  return codes.size > 0 ? [...codes].sort().join(" ") : "accepted";
}

const scenarios = listSnippets("tests/concurrency_corpus");

test("concurrency-corpus: at least one fixture discovered", () => {
  expect(scenarios.length).toBeGreaterThan(0);
});

for (const s of scenarios) {
  test.concurrent(`concurrency-corpus: ${s.name}`, async () => {
    const expected = EXPECT_RE.exec(readFileSync(s.mainPath, "utf8"))?.[1]?.trim();
    if (expected === undefined) throw new Error(`${s.name}: no \`// expect:\` line in its header`);
    const { stdout, stderr } = await runCli(["dump", "--stage=lowered-ast", `--target=${SNAPSHOT_TARGET}`, s.mainPath]);
    const output = `${stdout}\n${stderr}`;
    expect(verdict(output)).toBe(expected);
    const actual = diagSet(output);
    const cmp = snapshotEquals(s.dir, "diagnostics.snapshot", actual);
    if (!cmp.ok) {
      throw new Error(
        `concurrency-corpus mismatch: ${s.name}\n  snap: ${cmp.snapPath}\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected, actual),
      );
    }
  }, { timeout: MEDIUM_BUILD });
}
