// tests/examples_run: every example runs, and prints what it printed before.
//
// `verify.test.ts` builds the examples with `--verify`, which proves their IR is
// well formed and nothing about what they do: an example can build and then
// print the wrong thing, or stop on a trap. Each one runs here from the repo
// root, with the arguments `RUN_ARGS` gives it (none for most), and its output is
// pinned in `tests/fixtures/examples/<name>.run.snapshot`.
// Refresh with UPDATE_SNAPSHOTS=1.

import { expect, test } from "bun:test";
import { join } from "node:path";
import { ensureCliBuilt, LONG_BUILD, runCli } from "./cli-bin.ts";
import { snapshotDiff } from "./diff.ts";
import { formatRun, snapshotEquals } from "./snapshot.ts";
import { exampleInput, exampleNames } from "./vader-sources.ts";

ensureCliBuilt();

const SNAPSHOTS = join(import.meta.dir, "fixtures", "examples");
// What runs for an example whose default program opens a window: nothing for
// `raylib_sprite` (`raylib_examples.test.ts` builds it natively instead), the
// `frames` entry for `raycaster`, which draws the game's views with no window
// (`raycaster.test.ts` runs it natively against the same snapshot).
const RUN_FLAGS: Record<string, string[] | null> = {
  raylib_sprite: null,
  raycaster: ["--entry=frames"],
};
// What an example runs on, past its path: `brainfuck` needs a program to run,
// named relative to the repo root.
const RUN_ARGS: Record<string, string[]> = {
  brainfuck: ["examples/brainfuck/hello.bf"],
};
const examples = exampleNames().filter((name) => RUN_FLAGS[name] !== null);

test("examples: at least one discovered", () => {
  expect(examples.length).toBeGreaterThan(0);
});

for (const name of examples) {
  // LONG_BUILD: `brainfuck` imports `vader/vm`, so it loads about 40 modules
  // where the others load 12 (see `verify.test.ts`).
  test.concurrent(`example runs: ${name}`, async () => {
    const args = ["run", ...(RUN_FLAGS[name] ?? []), exampleInput(name), ...(RUN_ARGS[name] ?? [])];
    const r = await runCli(args, undefined, LONG_BUILD);
    const actual = formatRun(r.stdout, r.stderr, r.exit);
    const snap = snapshotEquals(SNAPSHOTS, `${name}.run.snapshot`, actual);
    if (!snap.ok) {
      throw new Error(
        `Snapshot mismatch: ${name} (${snap.snapPath})\n` +
        `Run with UPDATE_SNAPSHOTS=1 to refresh.\n\n` +
        snapshotDiff(snap.snapPath, snap.expected, actual),
      );
    }
    expect(r.exit).toBe(0);
  }, LONG_BUILD);
}
