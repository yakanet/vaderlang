// VM parity — Vader CLI's bytecode interpreter vs the TS VM's `vm.snapshot`.
//
// Each snippet that produces a `bytecode.snapshot.virt` (the `.virt` text-IR
// dump emitted by the bytecode phase in `tests/snapshot.test.ts`) is fed
// directly to the Vader CLI (`./build/vader run`). The captured stdout +
// stderr + exit are formatted via `formatRun` and compared to the same
// `vm.snapshot` the TS VM is checked against — both VMs share one oracle.
//
// Vader-VM coverage grows sprint by sprint (docs/SELFHOST_VM.md) ; ops
// that the Vader VM doesn't yet implement (`bool.*`, `null.const`,
// `virtual.call`, `type_check`, host imports beyond `std_io$println` /
// `print` / `eprintln`, etc.) cause snippets to trap or diverge. Those
// are listed in `KNOWN_DIVERGENT` and skipped — entries should be
// removed as Sprint 5+ lands.

import { test } from "bun:test";
import { existsSync, readFileSync } from "node:fs";

import { formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { ensureCliBuilt, runCli } from "./cli-bin.ts";

ensureCliBuilt();

// Snippets that the self-host VM can't yet run end-to-end. New entries
// should carry a one-line explanation + a link to the issue / commit
// blocking them.
//
// To regenerate the list : run this test with all entries removed,
// `bun test tests/vader_vm.test.ts`, and copy the failing names back.
const KNOWN_DIVERGENT = new Set<string>([
  // Layer 4 §1.19 B.1 — `type.const` op is wired in the TS VM but not yet
  // in `vader/vm/exec.vader`. Unblocks once the Vader VM port adds the
  // matching op handler + `Value.type` variant.
  "comptime_type_value",
]);

const scenarios = listSnippets("tests/snippets");

for (const s of scenarios) {
  if (KNOWN_DIVERGENT.has(s.name)) {
    test.skip(`vader-vm: ${s.name}`, () => {});
    continue;
  }
  const virtPath = `${s.dir}/bytecode.snapshot.virt`;
  if (!existsSync(virtPath)) {
    // No bytecode emitted — typically compile-error tests. Skip.
    continue;
  }
  const vmSnapPath = `${s.dir}/vm.snapshot`;
  if (existsSync(vmSnapPath)) {
    const vmSnap = readFileSync(vmSnapPath, "utf8");
    // Compile-error tests : bytecode phase still emits a `.virt`
    // (typecheck failures don't halt the pipeline before bytecode),
    // but the snippet is a diagnostic test — the TS VM never runs it.
    // Skip cleanly rather than report a spurious parity failure.
    if (vmSnap.startsWith("# compile errors")
        || vmSnap.startsWith("# pipeline error")
        || vmSnap.startsWith("# internal error")
        || vmSnap.startsWith("# no main function")) {
      continue;
    }
  }
  test.concurrent(`vader-vm: ${s.name}`, async () => {
    const { stdout, stderr, exit } = await runCli(["run", virtPath]);
    const actual = formatRun(stdout, stderr, exit);
    const cmp = snapshotEquals(s.dir, "vm.snapshot", actual);
    if (!cmp.ok) {
      throw new Error(
        `vader-vm parity mismatch: ${s.name}\n` +
        `  snap: ${cmp.snapPath}\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected, actual),
      );
    }
  }, { timeout: 30_000 });
}
