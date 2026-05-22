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

import { listSnippets, loadConfig } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { LONG_BUILD, MEDIUM_BUILD, runCli } from "./cli-bin.ts";

// Snippets whose Vader-CLI typecheck runs longer than `MEDIUM_BUILD`.
// `namespace_alias_dedupe` exercises the cross-module folder-alias
// resolution path (`P :: import "vader/parser"` plus an explicit
// `import "vader/parser/ast"` over the full vader/* tree) — that's
// ~40s on the Vader self-host today vs ~0.3s on TS. The slowness is a
// known typecheck-pass O(n²) on multi-module unions ; not blocking
// parity, just budget.
const SLOW_TYPECHECK_SNIPPETS = new Set(["namespace_alias_dedupe"]);

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
  { label: "typecheck", dumpStage: "typed-ast", snapshotFile: "typecheck.snapshot", skip: new Set() },
  { label: "comptime", dumpStage: "evaluated-ast", snapshotFile: "comptime.snapshot", skip: new Set() },
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
    // Honour `_config.json`'s `phases` allow-list — matches `snapshot.test.ts`.
    // Without this, a stage excluded from the snapshot-regeneration loop
    // (whose `.snapshot` file is therefore frozen and possibly stale) would
    // still be parity-checked here, producing false failures.
    const config = loadConfig(s.dir);
    if (config.phases && !config.phases.includes(stage.label as never)) continue;

    const timeout = SLOW_TYPECHECK_SNIPPETS.has(s.name) ? LONG_BUILD : MEDIUM_BUILD;
    // The cross-module `namespace_alias_dedupe` snippet pulls in the
    // full `vader/parser` transitive closure under the strict resolver
    // (~50 modules). The compiled Vader CLI's 4M / 16M default GC
    // arenas can't hold that much typecheck state in flight ; bump for
    // this case only.
    const env = SLOW_TYPECHECK_SNIPPETS.has(s.name)
      ? { VADER_GC_YOUNG_BYTES: String(16 * 1024 * 1024), VADER_GC_OLD_BYTES: String(128 * 1024 * 1024) }
      : undefined;
    test.concurrent(`${stage.label}: ${s.name}`, async () => {
      const snapPath = `${s.dir}/${stage.snapshotFile}`;
      let expected: string;
      try { expected = await Bun.file(snapPath).text(); } catch { return; }

      const { stdout } = await runCli(["dump", `--stage=${stage.dumpStage}`, s.mainPath], env);

      if (stdout !== expected) {
        throw new Error(
          `${stage.label}-dump parity mismatch: ${s.name}\n\n` +
          snapshotDiff(snapPath, expected, stdout),
        );
      }
    }, { timeout });
  }
}
