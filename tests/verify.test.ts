// tests/verify — `--verify`, the cross-pass IR self-check.
//
// `I7xxx` reports a malformed IR, which is a compiler bug and not something a
// program can provoke — so the family takes the same no-fixture exception
// `H6xxx` takes and is pinned here rather than under `tests/diag_corpus/`.
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
import { mkdtempSync, readdirSync, readFileSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

ensureCliBuilt();

const ROOT = join(import.meta.dir, "..");
const EXAMPLES = join(ROOT, "examples");
const COMPILER_ENTRY = join(ROOT, "vader", "cli", "main.vader");

// The self-host case compiles ~105k lines of Vader, an order of magnitude past
// anything else in the suite, and under `--parallel` it exceeds the per-test
// budget on a loaded machine. Same bargain `parity-broad` takes.
const RUN_SELF_HOST = process.env["RUN_VERIFY_SELFHOST"] === "1";

// `--out` into a scratch dir: the sweep runs on every example, and `--out=-`
// would drop a file named `-` in the repo root each time.
const buildVerify = (entry: string, timeout: number, out: string) =>
  runCli(
    ["build", "--emit=bytecode-text", `--out=${out}`, "--verify", entry], undefined, timeout);

const exampleEntries = (): string[] =>
  readdirSync(EXAMPLES, { withFileTypes: true })
    .filter((d) => d.isDirectory())
    .map((d) => join(EXAMPLES, d.name, `${d.name}.vader`));

// A finding on any of these is a false positive by construction: they are the
// programs the repo ships as correct. An `I7xxx` here means a check is wrong,
// not that the example is.
test("verify finds nothing in the examples", async () => {
  const dir = mkdtempSync(join(tmpdir(), "vader-verify-"));
  try {
    for (const entry of exampleEntries()) {
      // LONG_BUILD, matching this test's own declared budget rather than the
      // 30 s one: `examples/brainfuck` imports `vader/vm` + `vader/bytecode`,
      // so it type-checks 40 modules where the other seven load 12. That is
      // ~2 s locally against ~85 ms, and on a 4-core runner with the suite at
      // 4× parallel it reached the 30 s spawn kill and came back as exit 137.
      const r = await buildVerify(entry, LONG_BUILD, join(dir, "out.virt"));
      // A verifier finding is error-severity, so it also fails the build —
      // asserting the exit code catches a check that fires without us having
      // to match on the text.
      expect({ entry, exit: r.exit }).toEqual({ entry, exit: 0 });
      expect(r.stdout + r.stderr).not.toContain("error[I7");
    }
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}, LONG_BUILD);

test("verify changes nothing about the emitted bytecode", async () => {
  // The verifiers are pure reads. If `--verify` perturbed the IR the checks
  // would be measuring their own effect, which is the one way a self-check can
  // be worse than no check at all.
  //
  // Compare the EMITTED FILES, not the two runs' stdout: `--out` names a file
  // (`--out=-` writes one called `-`), so both runs print the same one-line
  // "wrote …" whatever the bytecode holds.
  const entry = join(EXAMPLES, "mandelbrot", "mandelbrot.vader");
  const dir = mkdtempSync(join(tmpdir(), "vader-verify-"));
  try {
    const plain = join(dir, "plain.virt");
    const checked = join(dir, "checked.virt");
    const a = await runCli(
      ["build", "--emit=bytecode-text", `--out=${plain}`, entry], undefined, MEDIUM_BUILD);
    const b = await runCli(
      ["build", "--emit=bytecode-text", `--out=${checked}`, "--verify", entry],
      undefined, MEDIUM_BUILD);
    expect(a.exit).toBe(0);
    expect(b.exit).toBe(0);
    const emitted = readFileSync(plain, "utf8");
    // Guard the guard: an empty or near-empty emission would make the
    // comparison below hold for the wrong reason.
    expect(emitted.length).toBeGreaterThan(10_000);
    expect(readFileSync(checked, "utf8")).toBe(emitted);
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
});

// The compiler compiling itself is the broadest IR corpus in the tree — every
// lowering, every generic flavour. A check that starts reporting sound IR
// fails here rather than in someone's build.
test.skipIf(!RUN_SELF_HOST)("self-host: verify finds nothing", async () => {
  const dir = mkdtempSync(join(tmpdir(), "vader-verify-"));
  try {
    const r = await buildVerify(COMPILER_ENTRY, LONG_BUILD, join(dir, "self.virt"));
    expect(r.exit).toBe(0);
    expect(r.stdout + r.stderr).not.toContain("error[I7");
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}, LONG_BUILD);
