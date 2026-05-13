# Self-host VM — incremental port plan

The `src/vm/` interpreter is the next compiler component scheduled for
self-host port (TODO §2.4). This document tracks the **incremental
strategy** — instead of porting the whole 1300-LoC TS VM (plus the
~2300 LoC `src/bytecode/` reader stack) in one shot, we bootstrap on
the existing TS-produced `.virt` text dump and grow the Vader-side
reader + executor sprint by sprint.

The key insight: the `.virt` text format is already the supported pivot
between the TS toolchain and end-users (`vader build --target=ir-text`
produces it ; `vader run` already accepts `.virt`/`.vir`). The Vader VM
can therefore validate end-to-end against the TS compiler **before**
the typer / lower / bytecode emit are ported. Reading `.vir` (binary)
comes later — it's cosmetic until ship-size matters.

## Sprint 1 — Minimum vital

**Goal**: `vader run trivial.virt` exits with the user code's return
value, on a snippet shaped `main :: fn() -> i32 { return 42 }`.

**Acceptance**:
- `vader build --target=ir-text tests/snippets/return_42/_main.vader` produces a `.virt`.
- `vader run <that-virt>` exits 42.
- Behaviour matches `bun src/index.ts run …`.

**Scope** (only what the trivial snippet exercises):
- `.virt` parser: `module <name>`, `fn N name (params) -> ret`, op
  lines, `end`. Reject unknown directives loudly so missing coverage
  surfaces as a diag not a silent miss.
- Op coverage: `i32.const`, `return`.
- Value repr: `i32` only.
- Host: none (no `println`, no I/O — exit code is enough).
- Bytecode shape: minimal `BytecodeModule` Vader-side — name + a single
  `BcFunction { name, ret, body: Op[] }`.

**Layout** (start consolidated, split when it grows):
- `vader/vm/exec.vader` — value type, parser, exec loop, all in one
  for sprint 1.
- `vader/cli/main.vader cmd_run` — dispatch on `.virt` extension to
  the new module.

**Out of scope for sprint 1**: locals, control flow, binops, strings,
println, structs, arrays, calls, type checks, imports, intrinsics,
traits/vtables, binary `.vir`.

## Subsequent sprints (rough scope, may be revised)

| Sprint | Adds | Snippets unlocked |
|---|---|---|
| 2 | locals, binops (i32 arith + cmp), `if`/`block`/`loop`/`br`/`br_if` | most numeric snippets |
| 3 | strings + `vader_println` host fn → "hello world" | `hello_world`, `interp_string` |
| 4 (a) | direct `call` + Frame stack — multi-fn modules ✅ | `vm_call_simple`, `vm_call_chain`, `vm_call_recursive` |
| 4 (b1) | type table + struct ops (`struct.new(_stack)`, `struct.get`, `struct.set(_stack)`, `local.tee`) ✅ | `vm_struct_point`, `vm_struct_nested`, `vm_struct_mutate` |
| 4 (b2) | array ops (`array.new`, `array.push`, `array.get`, `array.set`, `array.len`) + no-op `ref.cast` / `*.to_*` conversions ✅ | `vm_array_basic`, `vm_array_push_len`, `vm_array_mutate` |
| 4 (b3) | `intrinsic builder.*` (`new` / `append_str` / `append_display` / `finish`) — unblocks `"${…}"` interpolation ✅ | `vm_interp_basic`, `vm_interp_mixed`, `vm_interp_loop` |
| 4 (b4) | `fn.ref` + `call.indirect` — plain fn-values (no env capture yet) ✅ | `vm_fn_value_local`, `vm_fn_value_callback`, `vm_fn_value_struct` |
| 4 (b5) | `make_closure` + env capture — closures with captured locals ✅ | `vm_closure_capture`, `vm_closure_mutating`, `vm_closure_as_arg` |
| 5a | `null.const` / `bool.const(true|false)` / `bool.{eq,ne,and,or,not}` / `char.const N` / `char.{eq,ne,lt,le,gt,ge}` / `drop` / `ref.{eq,ne}` + `i32.*` cmp ops push `BoolVal` ; `if` / `br_if` accept both `BoolVal` and `I32Val` via `read_truthy` ✅ | unblocks 8 snippets (90 / 176 = 51% acceptance) |
| 5b | `type_check N` op (PrimitiveType / StructType / ArrayType / UnionType) ✅ | +12 snippets (`closure_pattern_binding`, `if_is_narrow`, `if_null_narrow`, `match_*`, `null_blockres`, `array_of_union`, `custom_iter*`, `generic_type_alias`) — 102/176 = 58 % |
| 5c | extended host imports : `std/string` family (`byte_len` / `byte_at` / `slice` / `starts_with` / `ends_with` / `contains` / `trim` / `to_upper` / `to_lower` / `index_of` / `last_index_of` / `split`) + `std_core$string$Index$at` + `StringBuilder.to_string` ; width-suffixed integer const ops (`i64.const` / `u32.const` / `usize.const` / etc.) ✅ | +5 snippets (`primitive_hash_eq`, `sam_impl`, `std_string`, `std_string_builder`, `comptime_type_alias`) — 107/176 = 61 % |
| 5c | extended `call.import` host surface (`string.*`, hash, file I/O, `std_runtime$collections`) | unblocks ~15 stdlib-heavy snippets |
| 5d | missing intrinsics (`size_of`, `type_kind`, `satisfies`) | unblocks `intrinsic_*` |
| 6 | `virtual.call` + trait vtables synthesised from fn-name mangling (`<Type>$<Trait>$<method>[__T…]`) — receiver `type_id` looked up in per-`(Trait, method)` vtable, dispatched through `dispatch_call_into`. ✅ | +2 snippets (`trait_virtual_dispatch`, `trait_dispatch_generic_iter`) — 109/176 = 62 % |
| 7 | Integer arithmetic completion : `<width>.neg` / `<width>.bitnot` / `<width>.bitand` / `<width>.bitor` / `<width>.bitxor` / `<width>.shl` / `<width>.shr` + width-aliased arithmetic + comparison ops (i8 / i16 / i64 / isize / u8 / u16 / u32 / u64 / usize all collapse onto `I32X` since the VM aliases every integer width to `I32Val`). Previously the parser silently dropped these, which made `std_core$i32$Comparable$compare` return `1` instead of `-1` and cascaded into broken `Range`-driven loops. ✅ | +22 snippets (`for_range`, `iter_coerce_array`, `iter_zip_chain`, `range_widths`, `usize_basic`, `usize_arith`, `string_bytes`, `array_iter`, `contains_op`, `enum_match`, `enum_typed`, `generic_fn`, `implicit_dot_variant`, `intrinsic_size_of`, `seq_lit_inference`, `spread_destructure`, `std_sort`, `trait_dispatch_param`, `transitive_mono`, `tuple_for_destructure`, `tuple_in_array`, plus one more) — 131/176 = 74 % |
| 8 | String op completion : `string.eq` / `string.ne` / `string.concat` (+ shared `apply_string_cmp` helper) + decoded backslash escapes in the `.virt` string table (`\n` / `\t` / `\r` / `\"` / `\\` / `\0`) + `print` routed through `std/io.print` (no newline) instead of being collapsed onto `println`. ✅ | +4 snippets (`intrinsic_type_kind`, `multiline_string`, `op_overload_index`, `tuple_match_union`) — 135/176 = 77 % |
| 9 | Host-import widening + cross-tag conversions : `string.Hash.hash` (FNV-1a-32-low) ; `<width>.Display.to_string` for every primitive ; `parse_int` / `panic` / `std/runtime` collection-counter hosts (boxed `gc_state`) ; `i32.rem` parser fix (bytecode emits `rem`, not `mod`) ; `IntToChar` / `CharToInt` ops re-tag values across the no-op `Convert` boundary so `${char_val}` interpolation hits the UTF-8 path ; `strip_comment` honours `"..."` boundaries (a literal `;` inside `"...GC; sum=..."` was swallowed) ; `read_i32` / `read_char` accept the cross-tag variant ; `I32ShrU` op for unsigned shifts (`u32.shr`) ; `main` receives a 1-element `argv` array when its signature requires one. ✅ | +24 snippets (`bound_enforced`, `char_range_contains`, `collection_index_sugar`, `format_helpers`, `gc_*` (3), `iter_*` (3), `map_set_iter`, `mutable_*` (3), `path_basics`, `regex_helpers`, `runtime_argv`, `std_cli_basic`, `string_chars`, `string_codepoints`, `trait_dispatch_bounded`, `u32_bitops`, `op_overload_arith`, `op_overload_compound`) — 159/176 = 90 % |
| 5 | `type_check`, `ref.cast`, virtual.call, intrinsics, traits/vtables | nearly all snippets |
| 6 | binary `.vir` loader (alternative to text) | shipping-perf gains |
| 7 | Split `vader/vm/exec.vader` into `vader/bytecode/{types,ops,module,text}.vader` + `vader/vm/{value,exec,host}.vader` once the single file becomes unwieldy (probably mid-sprint 3 or 4). |

## Validation strategy

Each sprint adds a small **VM snippet test set** under `tests/snippets/`
guarded by a new `tests/vader_vm.test.ts` (parallel to the existing
`tests/vm.test.ts` which runs the TS VM). The test compiles each
snippet via the TS toolchain to `.virt`, then runs it through the
Vader-built `vader run`, then asserts the exit code + stdout match the
TS-VM-recorded `vm.snapshot`.

This piggybacks on the existing `vader build --target=native` build
chain (the Vader CLI ships as a native binary), so the harness can
spawn `./build/vader run <snippet>.virt` and compare against the TS
baseline without rebuilding the world.

## Bootstrap-check connection

This effort is the first half of TODO §2.4 ("Port the VM"). It doesn't
yet touch §2.6 (typer port) — the Vader VM stays parasitic on the TS
typer/lower/bytecode emit through sprint 5. Once those three are also
ported, `compiler_v2 (TS)` vs `compiler_v3 (Vader)` differ only in the
bytecode emit driver, which is the bootstrap-check (§2 phase-end goal).
