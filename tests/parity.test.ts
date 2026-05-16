// CLI parity — Vader CLI dumps vs TS-generated snapshots.
//
// For each snippet under `tests/snippets/`, spawns the Vader CLI in lexer
// and parser modes and asserts the stdout matches the corresponding
// snapshot byte-for-byte. Snapshots are produced by the in-process TS
// pipeline (`tests/snapshot.ts`).
//
// Eventually (post-bootstrap) the snapshot producers flip to the Vader CLI
// and this test collapses into `tests/snapshot.test.ts`.

import { test, expect } from "bun:test";

import { listSnippets } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { ensureCliBuilt, runCli } from "./cli-bin.ts";

ensureCliBuilt();

interface Stage {
  label: string;
  dumpStage: string;
  snapshotFile: string;
  // Snippet names exempt from parity. Reintroduce an entry here when a
  // regression surfaces ; both sets are intentionally empty today.
  skip: Set<string>;
}

// `dumpStage` is the CLI flag value ; `label` is what appears in test
// names. Both stages map 1:1 onto a snapshot file produced by `tests/
// snapshot.ts`. The label / dumpStage divergence (`parser` vs `ast`)
// preserves the historical snapshot filename.
const STAGES: Stage[] = [
  { label: "lexer", dumpStage: "lexer", snapshotFile: "lexer.snapshot", skip: new Set() },
  { label: "parser", dumpStage: "ast", snapshotFile: "parser.snapshot", skip: new Set() },
  { label: "resolver", dumpStage: "resolved-ast", snapshotFile: "resolver.snapshot", skip: new Set() },
];

const scenarios = listSnippets("tests/snippets");

test("parity: at least one snippet", () => {
  expect(scenarios.length).toBeGreaterThan(0);
});

for (const stage of STAGES) {
  for (const s of scenarios) {
    if (stage.skip.has(s.name)) {
      test.skip(`${stage.label}: ${s.name}`, () => {});
      continue;
    }
    test.concurrent(`${stage.label}: ${s.name}`, async () => {
      const snapPath = `${s.dir}/${stage.snapshotFile}`;
      let expected: string;
      try { expected = await Bun.file(snapPath).text(); } catch { return; }

      const { stdout } = await runCli(["dump", `--stage=${stage.dumpStage}`, s.mainPath]);

      if (stdout !== expected) {
        throw new Error(
          `${stage.label}-dump parity mismatch: ${s.name}\n\n` +
          snapshotDiff(snapPath, expected, stdout),
        );
      }
    }, { timeout: 30_000 });
  }
}
