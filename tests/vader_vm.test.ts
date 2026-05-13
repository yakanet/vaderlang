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

import { test, beforeAll } from "bun:test";
import { existsSync, readdirSync, readFileSync, statSync } from "node:fs";
import { join } from "node:path";

import { formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";

const CLI_BIN = `build/vader${process.platform === "win32" ? ".exe" : ""}`;

// Rebuild the Vader CLI if any tracked source is newer than the binary.
// Same trigger as `tests/parity.test.ts` so the two parity tests share
// one rebuild path.
function newestSourceMtime(): number {
  let max = 0;
  const exts = [".vader", ".ts"];
  const walk = (dir: string): void => {
    for (const ent of readdirSync(dir, { withFileTypes: true })) {
      const p = join(dir, ent.name);
      if (ent.isDirectory()) walk(p);
      else if (exts.some((e) => ent.name.endsWith(e))) {
        const m = statSync(p).mtimeMs;
        if (m > max) max = m;
      }
    }
  };
  walk("vader");
  walk("stdlib");
  walk("src");
  return max;
}

beforeAll(async () => {
  const stale = !existsSync(CLI_BIN) || statSync(CLI_BIN).mtimeMs < newestSourceMtime();
  if (!stale) return;
  const proc = Bun.spawn(
    ["bun", "src/index.ts", "build", "vader/cli/main.vader", "--target=native", `--out=${CLI_BIN}`],
    { stdout: "pipe", stderr: "pipe" },
  );
  const code = await proc.exited;
  if (code !== 0) {
    const err = await new Response(proc.stderr).text();
    throw new Error(`vader CLI build failed (exit ${code}):
${err}`);
  }
});

// Snippets that the Vader VM can't yet run end-to-end — typically due to
// missing op support that lands in Sprint 5+. Each entry stays only as
// long as the corresponding op is unimplemented ; remove the line once
// the snippet runs through cleanly.
//
// To regenerate the list : run this test with all entries removed,
// `bun test tests/vader_vm.test.ts`, and copy the failing names back.
const KNOWN_DIVERGENT = new Set<string>([
  // Post Sprint 12 (2026-05-13). Four trait-dispatch and host gaps
  // closed in one batch :
  //   - `.virt` writer now emits `impl TYPE_ID TRAIT_NAME` directives
  //     from the bytecode `implTable` (was internal-only) ; the Vader
  //     VM parser registers them on `op.Module.impls`. `ref_type_matches`
  //     consults this table to answer `is Trait` patterns where the
  //     trait method got stripped by DCE — fixes `vm_trait_dispatch`,
  //     `dot_variant_in_union`.
  //   - `receiver_type_id_of` now looks up `PrimitiveType.kind` in the
  //     module type table so primitive trait receivers (e.g. `i32
  //     implements Doubler`) resolve a real type_id ; `find_struct_type_id`
  //     gained a primitive-name fallback so `build_vtables` registers
  //     `<module>$i32$Trait$method` against the i32 PrimitiveType entry.
  //     Fixes `trait_box_range_iter`.
  //   - New `std_process$spawn_run` / `spawn_last_stdout` /
  //     `spawn_last_stderr` host arms call into the native stdlib
  //     intrinsics. Fixes `process_spawn`.
  // 4 snippets unblock — 176 / 179 = 98 % acceptance. Remaining 3 :
  //   - Integer width truncation : `enum_to_repr_cast`,
  //     `numeric_context_sensitivity`, `type_aliases`. The Vader VM
  //     aliases every integer width onto `I32Val` ; values above 2^31
  //     wrap. Adding an `I64Val` (or `U64Val`) variant is the next
  //     sprint.
  //
  // Post Sprint 11 (2026-05-13). `ErrorVal` added to the `Value` union :
  // `RefType` learns its `trait_name` (was empty placeholder), and the
  // new `ref_type_matches` routes `is Error` to `op.ErrorVal` checks (and
  // the bare `ref _` to "any heap variant" per `src/vm/exec.ts:matchTo`).
  // `parse_int` / `parse_float` host arms now return `op.ErrorVal` on
  // failure instead of trapping the whole VM. `read_file` / `write_file`
  // / `exists` host arms land, each wired through the native stdlib
  // intrinsic with `Error` propagation. `STDIO_PRINTLN` / `STDIO_PRINT`
  // / `STDIO_EPRINTLN` constants inlined at their three call sites.
  // 3 snippets unblock (`parse_int_match`, `io_roundtrip`, `try_op`) —
  // 172 / 179 = 96 % acceptance. Remaining 7 :
  //   - `is Trait` impl table (non-`Error` traits, no .virt directive
  //     for it yet) — `vm_trait_dispatch`.
  //   - Primitive trait receivers — `trait_box_range_iter`.
  //   - Width truncation (no `u32`-typed `Value`) — `enum_to_repr_cast`,
  //     `numeric_context_sensitivity`, `type_aliases`.
  //   - Misc : `dot_variant_in_union`, `process_spawn`.
  //
  // Post Sprint 10 (2026-05-13). f64 support added : `F64Val` value
  // variant, every `f64.<op>` parser + exec arm, `parse_decimal_f64`
  // for the `f64.const` literal, and `std/math` host arms (`sqrt` /
  // `pow` / `floor` / `ceil` / `round` / `abs` / `min` / `max` /
  // `clamp` + the integer-typed `_` variants). `parse_float` host
  // and the `std_core$f64$Display$to_string` mangling are routed too.
  // 7 snippets unblock (`expr_bodied_fn`, `json_basics`,
  // `overload_first_param`, `std_math`, `tuple_comptime`,
  // `tuple_struct_field`, `tuple_triple_quad`). 166 / 176 = 94 %.
  // Remaining 10 failures cluster around :
  //   - `ErrorVal` value variant (not yet added) — `parse_int_match`,
  //     `io_roundtrip`, `try_op`.
  //   - `is Trait` impl table (.virt format gap) — `vm_trait_dispatch`,
  //     `trait_box_range_iter`.
  //   - Width truncation (no `u32`-typed `Value`) —
  //     `enum_to_repr_cast`, `numeric_context_sensitivity`, `type_aliases`.
  //   - Misc : `dot_variant_in_union`, `process_spawn` (spawn host).
  // Post Sprint 9 (2026-05-13). Multi-front widening of the Vader VM :
  //   - String `Hash$hash` host (FNV-1a-32-low) + `parse_int` /
  //     `panic` / `<width>$Display$to_string` (every primitive) hosts.
  //   - `std/runtime` collection-counter hosts (boxed via `gc_state`
  //     threaded through `dispatch_import`).
  //   - `i32.rem` parser fix (was looking for `mod`, the bytecode
  //     emits `rem`) — unblocks every `% capacity` bucket op.
  //   - `IntToChar` / `CharToInt` ops re-tag the Value across the
  //     no-op `Convert` boundary so `${char_val}` interpolation hits
  //     the UTF-8 char printer instead of the i32 decimal one.
  //   - `strip_comment` honours `"..."` string-literal boundaries
  //     (Sprint 8 string-escape decoding surfaced the latent bug —
  //     `"...GC; sum=..."` had the `;` swallowed as a comment marker).
  //   - `read_i32` / `read_char` accept the cross-tag variant so a
  //     no-op `Convert` doesn't leak `CharVal` into integer arms or
  //     vice versa.
  //   - `I32ShrU` op variant for unsigned (`u32.shr` / ...) shifts.
  //   - `main` is now passed a 1-element `argv` array when its
  //     signature requires one (`runtime_argv`).
  // 24 snippets unblock (`bound_enforced`, `char_range_contains`,
  // `collection_index_sugar`, `format_helpers`, `gc_*` (3), `iter_*` (3),
  // `map_set_iter`, `mutable_*` (3), `parse_int_match`-ish, `path_basics`,
  // `regex_helpers`, `runtime_argv`, `std_cli_basic`, `string_chars`,
  // `string_codepoints`, `trait_dispatch_bounded`, `u32_bitops`,
  // `op_overload_*`). 159 / 176 = 90 % acceptance.
  // Remaining 17 failures :
  //   - Float / math support — std_math, expr_bodied_fn, overload_first_param,
  //     tuple_struct_field, json_basics (parse_float).
  //   - Enum dispatch — dot_variant_in_union, enum_to_repr_cast.
  //   - Tuple destructure — tuple_comptime, tuple_triple_quad.
  //   - `is Trait` pattern matching needs an impl table (.virt format gap)
  //     — vm_trait_dispatch, parse_int_match (Error union), io_roundtrip,
  //     try_op.
  //   - Primitive trait receivers (i32 / usize as `self`) — trait_box_range_iter.
  //   - Width truncation (u32 wrap missing) — numeric_context_sensitivity,
  //     enum_to_repr_cast, type_aliases.
  //   - Misc : process_spawn (spawn_run host).
  "enum_to_repr_cast",
  "numeric_context_sensitivity",
  "type_aliases",
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
    const proc = Bun.spawn(
      [CLI_BIN, "run", virtPath],
      { stdout: "pipe", stderr: "pipe" },
    );
    const [stdout, stderr] = await Promise.all([
      new Response(proc.stdout).text(),
      new Response(proc.stderr).text(),
    ]);
    const exit = await proc.exited;
    const actual = formatRun(stdout, stderr, exit);
    const cmp = snapshotEquals(s.dir, "vm.snapshot", actual);
    if (!cmp.ok) {
      throw new Error(
        `vader-vm parity mismatch: ${s.name}
` +
        `  snap: ${cmp.snapPath}

` +
        snapshotDiff(cmp.snapPath, cmp.expected, actual),
      );
    }
  }, { timeout: 30_000 });
}
