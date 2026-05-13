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
  // Post Sprint 8 (2026-05-13). String op completion : `string.eq` /
  // `string.ne` / `string.concat` + decoded backslash escapes in the
  // `.virt` string table (`\n` / `\t` / `\r` / `\"` / `\\` / `\0`) +
  // `print` (no newline) routed through `std/io.print` instead of
  // collapsed onto `println`. 4 snippets unblock (`intrinsic_type_kind`,
  // `multiline_string`, `op_overload_index`, `tuple_match_union`) —
  // 135 / 176 = 77 % acceptance. Remaining failures :
  //   - Float / math support — std_math, expr_bodied_fn, f64.* ops, tuple_struct_field.
  //   - Enum dispatch — enum_to_repr_cast, dot_variant_in_union.
  //   - Tuple destructure — tuple_comptime, tuple_triple_quad.
  //   - GC root intrinsics + std_runtime$collections — gc_*, mutable_*.
  //   - `is Trait` pattern matching needs an impl table (.virt format gap)
  //     — vm_trait_dispatch, op_overload_arith, op_overload_compound, trait_dispatch_bounded.
  //   - Primitive trait receivers (i32 / usize as `self`) — trait_box_range_iter.
  //   - `u32.shr` signed-vs-unsigned shift semantics — u32_bitops.
  //   - Misc : io_roundtrip, regex_helpers, runtime_argv, etc.
  "bound_enforced",
  "char_range_contains",
  "collection_index_sugar",
  "dot_variant_in_union",
  "enum_to_repr_cast",
  "expr_bodied_fn",
  "format_helpers",
  "gc_array_survive",
  "gc_chain_survive",
  "gc_multi_collect",
  "io_roundtrip",
  "iter_combinators",
  "iter_defaults",
  "iter_lazy",
  "json_basics",
  "map_set_iter",
  "mutable_map",
  "mutable_map_string",
  "mutable_set",
  "numeric_context_sensitivity",
  "op_overload_arith",
  "op_overload_compound",
  "overload_first_param",
  "parse_int_match",
  "path_basics",
  "process_spawn",
  "regex_helpers",
  "runtime_argv",
  "std_cli_basic",
  "std_math",
  "string_chars",
  "string_codepoints",
  "trait_box_range_iter",
  "trait_dispatch_bounded",
  "try_op",
  "tuple_comptime",
  "tuple_struct_field",
  "tuple_triple_quad",
  "type_aliases",
  "u32_bitops",
  "vm_trait_dispatch",
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
