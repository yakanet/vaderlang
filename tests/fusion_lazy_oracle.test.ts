// The `_diag_fusion_*` snippets print every chain twice: fused where it is
// written, then bound to a local first — the lazy reference. The reference only
// holds while that local stays a state machine: a pass that fused through the
// local would make both halves agree on the wrong answer, and the snippets would
// pin nothing without a single snapshot line saying so. So every lazy local must
// survive lowering as a `let` holding a `__genstate_` value; a local fused
// through vanishes from the lowered form, so the check counts them.
//
// The lazy locals are the ones the snippets name `it`, `outer` and `inner`. An
// async fn's lazy local takes another name: the coroutine transform turns its
// `let` into a frame store, which no pattern here can see.

import { expect, test } from "bun:test";
import { readFileSync } from "node:fs";
import { join } from "node:path";
import { CLI_FAILED_PREFIX, listSnippets } from "./snapshot.ts";

const SOURCE_LAZY = /^\s*(it|outer|inner) ::/gm;
const LOWERED_LAZY = /^\s*let (it|outer|inner): __genstate_/gm;

test("the lazy half of every fusion diagnostic stays a state machine", () => {
  const problems: string[] = [];
  for (const s of listSnippets("tests/snippets")) {
    if (!s.name.startsWith("_diag_fusion_")) continue;
    const lowered = readFileSync(join(s.dir, "lower.snapshot"), "utf8");
    // A snippet pinning a compiler crash has no lowered form to check.
    if (lowered.startsWith(CLI_FAILED_PREFIX)) continue;
    const written = [...s.source.matchAll(SOURCE_LAZY)].length;
    const kept = [...lowered.matchAll(LOWERED_LAZY)].length;
    if (written === 0 || kept !== written) {
      problems.push(`${s.name}: ${written} lazy locals written, ${kept} lowered to a state machine`);
    }
  }
  expect(problems).toEqual([]);
});
