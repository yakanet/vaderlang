// Lexer-dump parity — Vader CLI vs the TS-generated `lexer.snapshot`.
//
// Each snippet under `tests/snippets/` ships a `lexer.snapshot` produced by
// the in-process TS lexer (`tests/snapshot.ts:formatTokens`). This test
// spawns the Vader CLI (`vader/cli/main.vader`) on the same `_main.vader`
// and asserts the stdout matches the snapshot byte-for-byte. The snapshot
// format was simplified so the Vader CLI emits its natural output without
// JS-mimicry — see `vader/cli/main.vader` for the producer side.
//
// Eventually (post-bootstrap) the snapshot producer flips to the Vader CLI
// and this test collapses into `tests/snapshot.test.ts`.

import { test, expect } from "bun:test";

import { listSnippets } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";

// Snippets whose source has non-ASCII chars hit the `std/string.char_at`
// byte-indexing limitation differently between the two lexers (TS reads
// UTF-16 code units, Vader byte-walks UTF-8 with no codepoint reassembly),
// so the dumps don't agree. Skip until the byte-vs-codepoint divergence is
// fixed in `std/string`.
const UTF8_KNOWN_DIVERGENT = new Set([
  "std_string",
  "std_string_builder",
]);

const scenarios = listSnippets("tests/snippets");

test("parity: at least one snippet", () => {
  expect(scenarios.length).toBeGreaterThan(0);
});

for (const s of scenarios) {
  if (UTF8_KNOWN_DIVERGENT.has(s.name)) {
    test.skip(`parity: ${s.name}`, () => {});
    continue;
  }
  test.concurrent(`parity: ${s.name}`, async () => {
    const snapPath = `${s.dir}/lexer.snapshot`;
    let expected: string;
    try { expected = await Bun.file(snapPath).text(); } catch { return; }

    // Drive the Vader CLI through the TS compiler's `vader run` ; once we
    // ship a native `vader-cli` binary, swap this for a direct invocation.
    const proc = Bun.spawn(
      ["bun", "src/index.ts", "run", "vader/cli/main.vader", "dump", "--stage=lexer", s.mainPath],
      { stdout: "pipe", stderr: "pipe" },
    );
    const stdout = await new Response(proc.stdout).text();
    await proc.exited;

    if (stdout !== expected) {
      throw new Error(
        `lexer-dump parity mismatch: ${s.name}\n\n` +
        snapshotDiff(snapPath, expected, stdout),
      );
    }
  });
}
