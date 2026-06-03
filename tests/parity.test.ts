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
  // regression surfaces.
  skip: Set<string>;
}

// Snippets that exercise the `<T>` angle-bracket generic syntax. Now
// supported by both parsers ; kept here as an explicit anchor in case
// the angle form ever needs targeted skips during cleanup. Empty today.
const ANGLE_GENERIC_SNIPPETS: ReadonlySet<string> = new Set<string>([]);

// §9 audit baseline — snippets where Vader's self-emitted bytecode
// currently diverges from the TS snapshot. Each remaining entry is a
// known gap in Vader's lower/emit pipeline (see
// `project_selfhost_bytecode_audit.md` in memory). Remove a name as
// its fix lands so the parity test catches future regressions.
// Goal : empty set ⇒ §9 done.
const BYTECODE_DIVERGENT_SNIPPETS: ReadonlySet<string> = new Set<string>([
  "_diag_const_string", "_diag_generic_map_param", "_diag_stdlib_struct_instance",
  // Native Vader's CFG→bytecode structurer (emit_range) infinitely recurses on
  // this snippet's match-merge + nested-loop-with-continue CFG and segfaults —
  // a Vader-side structurer bug (TS emits it fine). Skip the bytecode-parity
  // dim until emit_range is fixed ; the snippet is the regression repro.
  "_diag_structurer_overflow",
  "alias_import", "alias_union_in_array", "array_iter",
  "array_of_union", "array_push", "array_slice", "array_view_aliasing",
  "b1_fn_boundary", "bound_enforced", "byte_len_fold", "byte_literal", "cast_test",
  // Chained divergent `is`-guards + field access : accessor body matches TS, but
  // emitting it shifts the type/string interning order (§9 class). Self-host
  // correctness via VADER_SELF_EMIT.
  "chained_divergent_narrow",
  "char_range_contains",
  // GATE A/B divergence : Vader monomorphises `run_id`/`apply` to concrete
  // bodies + materialises `println` as a real fn (TS erases to `ref _`), so
  // the type-table / fn ordering differs. The lifted closure itself emits
  // correctly (validated via VADER_SELF_EMIT in vader_vm.test.ts → 7).
  "closure_in_generic_fn",
  "closure_pattern_binding",
  "coerce_into_basic", "coerce_into_chain_no",
  "coerce_into_explicit", "coerce_into_overload",
  "coerce_into_union_target_no", "collection_index_sugar", "comptime_for",
  "comptime_type_alias", "comptime_type_value",
  "const_array_basic",
  // The module-level struct-array const lowers (via `inline_consts`) to a
  // synthetic `__const_SPECS` accessor fn ; its BODY matches TS byte-for-byte,
  // but emitting it shifts the type-table / string-pool interning ORDER vs TS
  // (the dominant pre-existing §9 divergence class, not the const mechanism).
  // Self-host correctness validated via VADER_SELF_EMIT in vader_vm.test.ts.
  "const_fn_wrap",
  "contains_op", "custom_iter", "custom_iter_generic",
  "decorator_deprecated", "defer_block", "defer_in_lambda",
  "defer_on_panic", "dot_variant_in_union", "enum_basic", "enum_implements_trait",
  "enum_match", "enum_to_repr_cast", "enum_trait_self_return", "enum_typed",
  "expr_bodied_fn", "expr_bodied_recursive_typed",
  "expressions", "extern_native_basic", "file_decorator",
  // Field-chain `is`-narrowing : accessor body matches TS, but emitting it
  // shifts the type/string interning order (§9 class). Self-host correctness
  // via VADER_SELF_EMIT.
  "field_is_narrow", "field_not_null_narrow",
  "as_string_roundtrip",
  "for_in_into_iter", "for_in_iter_trait", "for_range",
  "for_range_sugar", "format_helpers", "gc_array_survive", "gc_chain_survive",
  "gc_multi_collect", "generic_angle_decl",
  "generic_eq", "generic_fn", "generic_helper_chain",
  "generic_struct", "generic_type_alias", "hello",
  // 64-bit int literals >= 2^31 : `i64.const` values match TS, only the
  // string/import interning order diverges (§9 class). Self-host correctness
  // via VADER_SELF_EMIT.
  "i64_const_width",
  "if_field_narrow", "if_is_as_bind", "if_is_field_after_narrow", "if_is_narrow",
  "if_null_narrow", "if_without_else_stmt", "impl_bounded_typeparam",
  "implicit_dot_variant", "implicit_type_alias",
  "interpolation", "interpolation_tokens",
  // is-T-as binding off a field-chain scrutinee : the accessor body matches TS,
  // but emitting it shifts the type-table / string-pool interning order (the
  // pre-existing §9 class). Self-host correctness via VADER_SELF_EMIT.
  "is_as_field_narrow",
  "intrinsic_field_access", "intrinsic_fields",
  "intrinsic_size_of", "intrinsic_type_args",
  "io_roundtrip", "is_union_alias_warn",
  "iter_coerce_array", "iter_combinators", "iter_defaults", "iter_lazy",
  "iter_zip_chain", "json_basics", "lambda_no_fn", "let_type_alias", "loop",
  "map_set_iter", "match_field_narrow", "match_is_as_binding",
  "match_literal_patterns", "match_partial",
  "match_struct_pattern_binding", "match_struct_pattern_in_union", "match_union",
  "match_wildcard_narrow", "multiline_string", "mutable_map", "mutable_map_string",
  "mutable_set", "namespace_call_nongeneric",
  // Namespace-qualified enum-variant + const access : the accessor body matches
  // TS, but emitting it shifts the type/string interning order (the §9 class).
  // Self-host correctness via VADER_SELF_EMIT.
  "namespace_const", "namespace_enum_variant", "namespace_import",
  "nested_field_narrow", "null_blockres",
  "numeric_add_trait", "numeric_context_sensitivity", "numerics", "op_not_is",
  "op_overload_arith", "op_overload_compound", "op_overload_eq_ord",
  "op_overload_index", "overload_first_param", "parse_int_match", "path_basics",
  "primitive_hash_eq", "primitive_impl", "process_spawn", "range_widths",
  "regex_helpers", "runtime_argv", "sam_impl", "self_ref_struct", "semver_basic",
  "seq_lit_inference", "spread_destructure", "squares", "std_base64",
  "std_cli_basic", "std_crypto", "std_math", "std_random", "std_regex",
  "std_sort", "std_string", "std_string_builder", "std_time", "string_bytes",
  "string_bytes_const_write", "string_bytes_gc",
  "string_chars", "string_codepoint_slice", "string_codepoints", "strings",
  "struct_decl",
  // Cross-module struct default (const from the owning module) : accessor body
  // matches TS, only the type/string interning order diverges (§9 class). Self-host
  // correctness via VADER_SELF_EMIT.
  "struct_default_cross_module",
  "struct_defaults", "struct_lit_field_order",
  "struct_name_collision", "struct_spread",
  // Standard string-pool / import interning-order divergence (the dominant
  // §9 class), not a `todo`-specific gap — todo_stub uses `println` + string
  // interpolation like dozens of entries above. Its committed bytecode.snapshot
  // still validates the `todo` → `std_abort$panic` wiring.
  "todo_stub",
  "trait_box_range_iter",
  "trait_dispatch_bounded", "trait_dispatch_eq", "trait_dispatch_generic_iter",
  "trait_dispatch_param",
  // INTENTIONAL divergence (mode-a GATE A) : Vader now keeps trait-dispatching
  // generic instances CONCRETE (`apply_tag__i32 (i32)` + direct `call`) instead
  // of erasing to `(ref)` + `virtual.call`. Vader's form runs to the correct
  // result on the VM (vm.snapshot = 140) ; the TS snapshot's erased
  // `virtual.call` on a `ref _` primitive receiver returns 0 (wrong on the VM —
  // TS only works via native devirt). Verified instead by `vader_vm.test.ts`'s
  // VADER_SELF_EMIT path, which runs Vader's OWN bytecode against vm.snapshot.
  "trait_dispatch_struct",
  "trait_method_ambig", "trait_virtual_dispatch", "transitive_mono", "try_op",
  "tuple_comptime", "tuple_destructure_after_narrow", "tuple_destructure_let",
  "tuple_destructure_nested", "tuple_destructure_wildcard", "tuple_for_destructure",
  "tuple_generic_swap", "tuple_in_array", "tuple_match_nested",
  "tuple_match_pattern", "tuple_match_union", "tuple_pair_return",
  "tuple_struct_field", "tuple_triple_quad", "type_aliases", "u32_bitops",
  "ufcs_overload", "ufcs_union_receiver", "union_common_field",
  // Computed-u64-in-union match : accessor body matches TS, but emitting it
  // shifts the type/string interning order (§9 class). Self-host correctness
  // via VADER_SELF_EMIT.
  "union_computed_u64", "usize_arith",
  "usize_basic",
  "vm_hello",
  "vm_interp_basic", "vm_interp_loop", "vm_interp_mixed",
  "vm_trait_dispatch", "void_ident_rejected",
]);

// `dumpStage` is the CLI flag value ; `label` is what appears in test
// names. Both stages map 1:1 onto a snapshot file produced by `tests/
// snapshot.ts`. The label / dumpStage divergence (`parser` vs `ast`)
// preserves the historical snapshot filename.
const STAGES: Stage[] = [
  { label: "lexer", dumpStage: "lexer", snapshotFile: "lexer.snapshot", skip: new Set(ANGLE_GENERIC_SNIPPETS) },
  { label: "parser", dumpStage: "ast", snapshotFile: "parser.snapshot", skip: new Set(ANGLE_GENERIC_SNIPPETS) },
  { label: "resolver", dumpStage: "resolved-ast", snapshotFile: "resolver.snapshot", skip: new Set(ANGLE_GENERIC_SNIPPETS) },
  { label: "typecheck", dumpStage: "typed-ast", snapshotFile: "typecheck.snapshot", skip: new Set(ANGLE_GENERIC_SNIPPETS) },
  { label: "comptime", dumpStage: "evaluated-ast", snapshotFile: "comptime.snapshot", skip: new Set(ANGLE_GENERIC_SNIPPETS) },
  { label: "bytecode", dumpStage: "bytecode", snapshotFile: "bytecode.snapshot.virt", skip: new Set(BYTECODE_DIVERGENT_SNIPPETS) },
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
