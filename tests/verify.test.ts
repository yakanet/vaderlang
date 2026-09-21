// tests/verify — `--verify`, the cross-pass IR self-check.
//
// `I7xxx` reports a malformed IR, which is a compiler bug and not something a
// program can provoke — so the family takes the same no-fixture exception
// `H6xxx` takes (`.claude/CLAUDE.md` §12) and is pinned here rather than under
// `tests/diag_corpus/`.
//
// `build` is the only action carrying `--verify`, and that is deliberate:
// `dump` renders diagnostics through `filter_diags_in_scope`
// (`cmd_dump.vader:535`), which drops everything outside the entry module's
// subtree, so a dump-based assertion reports clean whatever the verifiers
// found. `flush_build_diags` shows the full set.
//
// These pin the outer contract only. Asserting that a broken CFG is CAUGHT
// needs a hand-built `CFGFunction`, and `MonoEntry.module` is a `TypedProgram`
// with no cheap constructor; until that fixture factory exists, detection is
// exercised only by the corpus below.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD, LONG_BUILD } from "./cli-bin.ts";
import { readdirSync } from "node:fs";
import { join } from "node:path";

ensureCliBuilt();

const ROOT = join(import.meta.dir, "..");
const EXAMPLES = join(ROOT, "examples");
const COMPILER_ENTRY = join(ROOT, "vader", "cli", "main.vader");

// The self-host case compiles ~105k lines of Vader, an order of magnitude past
// anything else in the suite, and under `--parallel` it exceeds the per-test
// budget on a loaded machine. Same bargain `parity-broad` takes.
const RUN_SELF_HOST = process.env["RUN_VERIFY_SELFHOST"] === "1";

const buildVerify = (entry: string, timeout: number) =>
  runCli(["build", "--emit=bytecode-text", "--out=-", "--verify", entry], undefined, timeout);

const exampleEntries = (): string[] =>
  readdirSync(EXAMPLES, { withFileTypes: true })
    .filter((d) => d.isDirectory())
    .map((d) => join(EXAMPLES, d.name, `${d.name}.vader`));

// A finding on any of these is a false positive by construction: they are the
// programs the repo ships as correct. An `I7xxx` here means a check is wrong,
// not that the example is.
test("verify finds nothing in the examples", async () => {
  for (const entry of exampleEntries()) {
    const r = await buildVerify(entry, MEDIUM_BUILD);
    // A verifier finding is error-severity, so it also fails the build —
    // asserting the exit code catches a check that fires without us having to
    // match on the text.
    expect({ entry, exit: r.exit }).toEqual({ entry, exit: 0 });
    expect(r.stdout + r.stderr).not.toContain("error[I7");
  }
}, LONG_BUILD);

test("verify changes nothing about the emitted bytecode", async () => {
  // The verifiers are pure reads. If `--verify` perturbed the IR the checks
  // would be measuring their own effect, which is the one way a self-check can
  // be worse than no check at all.
  const entry = join(EXAMPLES, "fizzbuzz", "fizzbuzz.vader");
  const plain = await runCli(
    ["build", "--emit=bytecode-text", "--out=-", entry], undefined, MEDIUM_BUILD);
  const checked = await buildVerify(entry, MEDIUM_BUILD);
  expect(checked.stdout).toBe(plain.stdout);
});

// The compiler compiling itself is the broadest IR corpus in the tree — every
// lowering, every generic flavour. A check that starts reporting sound IR
// fails here rather than in someone's build.
test.skipIf(!RUN_SELF_HOST)("self-host: verify finds nothing", async () => {
  const r = await buildVerify(COMPILER_ENTRY, LONG_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout + r.stderr).not.toContain("error[I7");
}, LONG_BUILD);
