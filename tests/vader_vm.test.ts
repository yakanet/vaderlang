// VM parity — Vader CLI's bytecode interpreter vs the TS VM's `vm.snapshot`.
//
// Each snippet that produces a `bytecode.snapshot.virt` (the `.virt` text-IR
// dump emitted by the bytecode phase in `tests/snapshot.test.ts`) is fed
// directly to the Vader CLI (`./build/vader run`). The captured stdout +
// stderr + exit are formatted via `formatRun` and compared to the same
// `vm.snapshot` the TS VM is checked against — both VMs share one oracle.
//
// Vader-VM coverage grows sprint by sprint (docs/SELFHOST_VM.md). The VM
// implements `bool.*`, `null.const`, `virtual.call`, `type_check` (verified
// in `vader/vm/exec.vader`) ; snippets still trap or diverge for narrower
// reasons — host imports beyond `std_io$write` (no host-fn registry),
// panic-unwind defers, and `virtual.call` whose receiver is an *erased*
// type (`ref _`) for which the vtable lookup finds no impl (the mode-a
// erasure gap — fixed by monomorphising/devirtualising in the Vader emit,
// tracked in the §9 audit). Those are listed in `KNOWN_DIVERGENT` and
// skipped — entries should be removed as the gaps close.

import { test } from "bun:test";
import { existsSync, readFileSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

import { formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { MEDIUM_BUILD, runCli } from "./cli-bin.ts";

// Snippets where Vader's self-emitted bytecode INTENTIONALLY diverges from
// the TS snapshot (mode-a GATE A : concrete devirt instead of erased
// `virtual.call`) AND is more correct — TS's erased form returns the wrong
// result on the VM. For these we don't run the committed (TS) `.virt` ;
// instead we dump Vader's OWN bytecode and run that against `vm.snapshot`.
// This is the real self-host oracle (Vader compiles → Vader VM runs →
// correct output) and the validation that will let TS be removed.
const VADER_SELF_EMIT = new Set<string>([
  "trait_dispatch_struct",
  // GATE B : `println<string>` keeps `msg` concrete (GATE A), `msg.to_string()`
  // resolves to the intrinsic `string` Display impl surfaced as an import, and
  // the Vader VM dispatches it via `host.vader`. Vader self-emit prints
  // "Hello, World!" where the erased TS path can't.
  "hello",
  // Same GATE A+B path (concrete Display dispatch on primitives / interp) —
  // Vader self-emit runs these to their vm.snapshot oracle where the erased
  // TS bytecode diverges. Each verified: dump-with-Vader → run → matches.
  "squares",
  "vm_hello",
  "interpolation",
  "vm_interp_basic",
  "vm_arith",
  "for_range",
  "loop",
  "vm_interp_mixed",
  "vm_interp_loop",
  "enum_typed",
  "enum_match",
  "match_union",
  "if_field_narrow",
  "vm_struct_nested",
  "vm_array_mutate",
  "vm_for",
  "vm_if",
  "if_is_narrow",
]);

// Snippets that the self-host VM can't yet run end-to-end. New entries
// should carry a one-line explanation + a link to the issue / commit
// blocking them.
//
// To regenerate the list : run this test with all entries removed,
// `bun test tests/vader_vm.test.ts`, and copy the failing names back.
const KNOWN_DIVERGENT = new Set<string>([
  // A8 single-track defer — panic-unwind not yet wired in the Vader self-
  // host VM ; `defer.push` / `defer.pop_exec` (normal exits) work but a
  // trapped op exits via the regular `Trap` path without draining the
  // frame's defer-stack. Tracked alongside the C-emit setjmp/longjmp
  // chantier in TODO §3.8. `defer_in_lambda` exercises a panic inside
  // a lambda ; same root cause.
  "defer_on_panic",
  "defer_in_lambda",
  // `for x in <string>` → codepoint iter requires the `Iterator(char)`
  // impl on `string` to lower without B5001. The arr/map/set legs of
  // this snippet run, but the `chars=…` line is never emitted because
  // the chars leg traps. Tracked alongside TODO §1.5b iterators.
  "for_in_into_iter",
]);

const scenarios = listSnippets("tests/snippets");

for (const s of scenarios) {
  if (KNOWN_DIVERGENT.has(s.name)) {
    test.skip(`vader-vm: ${s.name}`, () => {});
    continue;
  }
  // Self-emit snippets : compile with Vader, run Vader's OWN bytecode (not
  // the committed TS `.virt`), and compare to the same `vm.snapshot` oracle.
  if (VADER_SELF_EMIT.has(s.name)) {
    test.concurrent(`vader-vm-self: ${s.name}`, async () => {
      const dump = await runCli(["dump", "--stage=bytecode", s.mainPath]);
      const tmp = join(tmpdir(), `vader-self-${s.name}.virt`);
      writeFileSync(tmp, dump.stdout);
      const { stdout, stderr, exit } = await runCli(["run", tmp]);
      const actual = formatRun(stdout, stderr, exit);
      const cmp = snapshotEquals(s.dir, "vm.snapshot", actual);
      if (!cmp.ok) {
        throw new Error(
          `vader-vm-self mismatch: ${s.name}\n` +
          `  snap: ${cmp.snapPath}\n\n` +
          snapshotDiff(cmp.snapPath, cmp.expected, actual),
        );
      }
    }, { timeout: MEDIUM_BUILD });
    continue;
  }
  // Native-only snippets — `@extern` user imports trap in the Vader VM
  // for the same reason they trap in the TS VM (no host-fn registry).
  if (s.helperCFiles.length > 0) {
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
  }, { timeout: MEDIUM_BUILD });
}
