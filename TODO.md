# Vader — TODO

Implementation roadmap for the Vader compiler and standard library, derived from `SPEC.md`:

- **Phase 1** — MVP compiler in TypeScript, plus stdlib in Vader.
- **Phase 2** — Self-hosting (port the compiler to Vader).
- **Phase 3** — Post-MVP language features and tooling.

Completed items (`[x]`) are kept as one-liners — see git history for implementation notes, commit hashes, migration steps. Open (`[ ]`) and in-progress (`[~]`) items keep the full context needed to act on them.

**Completed work — Phase 0, the done Phase 1 subsections, and the long-form detail of finished "Priority" items — lives in [`docs/HISTORY.md`](./docs/HISTORY.md).** This file tracks open + in-progress work only.

---

## Priority — next up

- [ ] **Generic arithmetic operator traits (`Add` / `Sub` / `Mul` / `Div` / `Rem`)** (added 2026-06-01). Today these traits are homogeneous (`add :: fn(self, other: Self) -> Self`). Make them generic over the right-hand operand and result, à la Rust's `Add<Rhs> { type Output }` — e.g. `trait Sub<Rhs, Out> { sub :: fn(self, rhs: Rhs) -> Out }`. Unlocks heterogeneous operators: `a -= b` where `a: MutableMap<K, V>` and `b: K` (remove a key by `-=`), or `Path implements Div<string, Path>` so `path / "chemin"` builds a child path. Touches the trait defs (`std/core`), the operator-desugar in typecheck/lower (currently assumes a `Self`-homogeneous signature), and overload resolution at operator call sites.

- [ ] **W0004 ambiguous-loop-jump : drop the entry-module scope** (added 2026-05-30). W0004 (unlabeled `break`/`continue` inside 2+ nested loops) currently fires only for the **entry module** — gated on `t.isEntryModule` in TS (`src/typecheck/passes/stmt.ts`) ; Vader gets it for free since `check_project_with_bodies` only body-checks the entry. The scope was added so importing the stdlib / the `vader/` compiler tree (which have unlabeled nested-loop jumps, e.g. `std/regex`'s matcher, `vader/lower/closure_analysis::walk_stmt`) doesn't surface W0004 from library internals **and** so TS↔Vader diag-parity holds (TS body-checks imports, Vader doesn't). Eventually W0004 should fire on **any** module : (1) make the stdlib + `vader/` tree W0004-clean (label the nested-loop jumps), (2) reconcile the import-body-check asymmetry (either Vader body-checks imports too, or both restrict body diagnostics consistently) so diag-parity stays clean, (3) remove the `isEntryModule` gate. Threading lives in `LoadedProject.entryModuleId` → `ResolvedProject.entryModuleId` → `checkProgram(…, isEntryModule)` → `MutableTyped.isEntryModule`. Related cleanup : Vader now carries **two** loop-nesting counters — `FnContext.loop_depth` (T3015 break-outside-loop) and the walk-global `TypedProgram.loop_depth` (W0004), because `FnContext` isn't threaded through the expression checker (so its depth is lost inside `if`/`match` blocks — T3015 has the same blind spot). Unify on the walk-global once that's reconciled (would also close T3015's if-nested gap).

- [ ] **Resolver lazy index** — the strict resolver's `discoverModules` currently scans every `.vader` file under the scoped roots up-front (stdlib + `vader.json::modules` + entry's folder via CLI fallback). For a tiny snippet like `arith` that only imports `std/io`, the Vader CLI walks ~170 file headers per invocation — ~660 ms per `dump` call vs. ~100 ms under the legacy depth-1 BFS. The full scan only earns its keep on cross-module entries (`namespace_alias_dedupe`, broad-parity). **Idea** : lazy discovery — start with an empty index, populate stdlib + the entry's folder eagerly, then on `index.get(name)` miss, expand the search by walking the next scoped root. Same final state, but small snippets pay only for what they actually import. The TS counterpart in `src/resolver/loader.ts` likely benefits too. Affects every `bun test` that touches the snapshot pipeline (which spawns the Vader CLI ~250 × per stage).
  - **Attempted 2026-05-26, reverted**. Initial implementation partitioned roots into eager (stdlib + entry) / lazy (manifest), walked lazy on demand from the BFS lookup in `vader/resolver/loader.vader::load_loaded_project`. Perf win measured : 660 ms → ~30 ms on `arith`. **Blocker** : `diagnose_import_path` is called from inside `collect_module` and fires R2001 the moment it can't find an import target in the *current* index. Lazy expansion in the BFS happens *after* collect runs, so multi-module entries (e.g. `namespace_alias_dedupe`) saw spurious R2001 on `vader/parser`. **Proper fix** requires either : (a) plumb lazy-expansion-on-miss through the collect call chain so `diagnose_import_path` can trigger a walk, or (b) cheap pre-scan of the entry's source for `import "..."` lines to seed expansion before collect runs. Both are larger than the original ~2-3 h estimate (~1 day with care). Deferred until perf becomes a real bottleneck again.

- [~] **`vader fmt` MVP** (first pass 2026-05-11) — written in Vader under `vader/fmt/`, exercises the self-host parser end-to-end. Idempotency + parse round-trip green on the stdlib ; byte-for-byte no-op pending on three stylistic gaps : (a) `::` column alignment in decl groups, (b) per-line grouping inside multi-line imports, (c) cap at 1 blank line between decls vs the stdlib's occasional double-blank. Tests : `tests/formatter*.test.ts` (gated `RUN_FMT_TESTS=1`). Open : column alignment decision, hand-curated snapshot scenarios, growing `NO_OP_FILES`.

---

## Phase 1 — MVP compiler in TypeScript

> Completed subsections (see the note above): §1.0 Diagnostics, §1.1 Lexer, §1.2 Parser, §1.3 Resolver, §1.4 Type-checker, §1.7 Bytecode emitter, §1.13b Self-hosting prerequisites, §1.13c Bugs, §1.14 Snapshot infra, §1.17 Enums, §1.18c-bis / §1.18c Overloading, §1.18 Built-in aliases. The subsections kept below still carry open `[ ]` / `[~]` items.

### 1.5 Comptime engine + monomorphizer

**Decision:** AST-walking interpreter at first, then ported to the bytecode VM in 1.5b. No separate comptime VM — the engine and the runtime VM share `src/bytecode/ops.ts`.

> Shipped 1.5a + 1.5b: AST-walker → bytecode-VM comptime engine, `@comptime` cycle detection + topo eval, generic-fn instance registry + monomorphization, `std/iter` eager + lazy + short-circuiting combinators, transitive mono, first-class trait-method dispatch, generic `len`, `T[]`→`Iterator(T)` auto-coerce.
- [ ] **Default-init for generic typeParam** — `acc: T = T()` style, needed by `sum(it)` over an iterator. Either a `Default` trait + auto-impl on numerics, or a `zero<T>()` intrinsic. Currently blocks iterator-driven `sum`, `min`, `max`. Requires either (a) explicit type-args at call sites (`default[T]()`) or (b) `T()` constructor syntax for type-params. Recommendation : start with (a). `Default` trait can wait until a dispatch path exists.
- [ ] `for x in iter` / `MutableList(u32){}.add(...)` inside `@comptime` — needs arena allocation for transient collections.

### 1.6 Lowerer — partial
> Shipped: lowered AST, match → if/else chain, `expr?` + interpolation + `defer` + trait-call lowering, lambda lifting / closure conversion, `RangeExpr`/`T[]` → `Iterator` for-in.
- [ ] Match decision-tree compilation (Maranget). Naive chain is enough for MVP.

### 1.7b IR text emitter / reader (`--target=ir-text` → `.virt`) — partial
> Shipped: line-oriented `.virt` grammar, `writeVir`/`parseVir` round-trip, `vader run program.virt`.
- [ ] Manifest mode for multi-module bytecode merge.

### 1.7c Bytecode format refresh — partial

**Two-format split — done**
- [x] Renamed textual format to `.virt` (CLI `--target=ir-text`).
- [x] Binary `.vir` format (`src/bytecode/binary.ts`) — magic `"VADR"`, version `BYTECODE_VERSION = 0.1.1` (hard error on mismatch), `FLAG_HAS_DEBUG`, 9 length-prefixed sections, both formats round-trip the same `BytecodeModule`. `vader run` extension-sniffs `.vader` / `.vir` / `.virt`.
- [~] Header flags — `has_debug_info` ✓. `target` and `module_id` deferred until WASM emitter / cache work lands.

**"Plus IR-like" — open architecture question**

Three variants on the table for the WASM-mimicking structured-control form vs midir's CFG/SSA :
  (a) **Drop the WASM mimicry, keep stack-machine.** `block`/`loop`/`if`/`else`/`end` + `br <depth>` → `goto label` + `branch_if cond label`. ~3-4 days. Saves ~200 lines.
  (b) **Bytecode adopts midir's CFG shape.** `BasicBlock { instrs, terminator }`. VM consumes a CFG. ~1-2 weeks.
  (c) **Promote midir directly — bytecode and midir merge.** `BytecodeModule` becomes `IRModule`. `.vir` serialises the CFG. ~2-3 weeks.

Bias : (a) is a fast win that keeps options open ; (c) is the right long-term destination ; (b) awkward intermediate. **Do not implement until discussed.**

**LoweredAST ↔ CFG seam — decided**

Keep LoweredAST distinct. Tree rewrites (match/try/for-in/range desugar) are cleaner over expression trees ; `midir/build.ts` is a thin, cheap-to-maintain seam ; line savings from a merge would be ~250-400 (not the 1500 headline). Reopen only when : §1.7c above ships, a second CFG consumer appears without a matching LoweredAST consumer, or a new desugar pass naturally wants CFG shape (e.g. async/yield).

### 1.8 VM — done
- [x] Tagged value model, stack-based interpreter (structured control + jump tables + intrinsics + `type_check` + `ref.cast` no-op), host bindings for `std/io`, `vader run file.{vader,vir,virt}`, 7 snapshot scenarios.
- [ ] **REPL** — needs incremental compilation across phases. Punt until after the C/WASM emitters.
- [ ] **Real impl table for trait `type_check`.** Today's heuristic covers host-driven I/O ; a user struct `Foo implements MyTrait` won't match `type_check MyTrait` in the VM until the bytecode emitter materialises an impl-table side-section. Picked up alongside generic-fn dispatch.
- [ ] **Slot-typed numeric promotion verifier** — add debug-only verifier when the WASM target lands.

### 1.9 C emitter (Iter-ready) — partial
> Shipped: full `src/c_emit/emit.ts` (type repr γ, `std/io` shims, `vader build --target=native`, VM-parity tests), `--release` / `--cc` / `CC` / `--ldflags`, struct-field unbox after `is`, Windows cross-compile (mingw-w64 + Wine), `#line` debug directives, stable `@extern` ABI (T3050/T3051).
- [ ] Manifest mode (`vader build --target=native --manifest`).
- [ ] i32/i64 overflow handling per SPEC §4 (panic in debug). Wraps silently today.

### 1.10 WASM emitter — moved to Phase 3 (§3.10)

### 1.11 C runtime — partial
- [x] **GC** : Cheney semi-space copying GC (`runtime/c/vader_runtime.c`). Precise roots via shadow stack + emitted `vader_gc_frame_t`s ; per-type pointer maps from C-emit. Knobs : `VADER_GC_ARENA_BYTES`. Stress tests under `tests/snippets/gc_*`.
- [x] **Arrays GC-tracked** — `vader_array_t` carries a header with single ref to a separately-allocated `vader_array_buf_t` ; Cheney scan dispatches on sentinel `0xFFFFFFFE`.
- [x] **Strings off the GC arena** — string buffers `malloc`'d outside the arena. Strings leak for the program's lifetime ; fine for MVP.
- [ ] **Array `pop` intrinsic** — O(1) pop is trivially `vader_array_t.length-- ; buf->length--` (both `length` fields are mirrored ; capacity is preserved so the slot is GC-collectable on the next sweep via the new length). No primitive today : `vader/lower/lower_expr.vader::lower_block` had to skip its `ctx.blocks` frame pop entirely because the only available shape was rebuild-array-minus-last (O(N) per pop). Self-host sites that want a real LIFO stack (lowerer block frames, future defer-replay walker, parser look-ahead buffers) need this. Implementation surface : add `vader_array_pop(vader_array_t*)` in `runtime/c/vader_runtime.c`, a `@array_pop` intrinsic + `LoweredArrayPop` opcode, and a stdlib `pop :: fn(arr: T[]) -> T | null` wrapper.
- [ ] String runtime polish, array runtime polish, StringBuilder support consolidation, panic handler.
- [ ] libc-backed I/O glue for `std/io`.

### 1.12 CLI — partial
> Shipped: `vader run` + `vader build` single-file, `--target=ir` (`.vir`/`.virt`), `vader test`, `vader dump --stage=<ast|typed-ast|bytecode|c|…>`, `--allow-env`.
- [~] **`vader fmt [path]`** — see top "Priority — next up".
- [ ] Manifest-driven build (`vader.json`) — single-file works ; manifest mode still gated "not yet implemented".
- [ ] `vader build --target=wasm` — see §3.10.

### 1.13 Stdlib (in Vader) — partial
- [ ] `std/core` finalisation, `std/io`, `std/string`, `std/math`.
- [x] `std/collections` — `MutableMap(K, V)` + `MutableSet(T)` chaining HashMap with FNV-1a string hash. Shared `len` / `is_empty` / `put` / `get` / `contains_key` / `add` / `contains` via first-param overloading.
- [ ] **Immutable `Map`/`Set` ops + `to_immutable`** — re-add the struct decls when there's a real read-only-view design.
- [x] Iterator impls for `MutableMap` / `MutableSet`.
- [ ] **Restore `MutableList(T)` once immutable `List<T>` lands** — raw `T[]` already covers push/len/indexing.
- [ ] **Audit `std/iter` and `std/string` surfaces** — surfaced 2026-05-20 during SPEC vs stdlib sweep. Two threads to follow up : (a) `std/iter` is missing an explicit `into_iter()` helper (SPEC previously referenced one) — decide between adding `arr.into_iter()` as an explicit form or relying solely on the `T[] implements Into(Iterator(T))` coercion ; (b) `std/string` exports drifted from SPEC (added `index_of`, `compare_ascending`, `compare_ascending_ci`, `decode_escapes` ; missing `is_hex_digit` / `is_digit_in_base` — now placed under `std/numbers`). Pass to settle on one canonical surface per module and align SPEC + stdlib + ports.
- [x] `std/string_builder` — `StringBuilder`.
- [x] `std/iter` — eager `T[]` combinators (`map`, `filter`, `fold`, `sum`, `take`, `skip`, `collect`, `count`, `zip`, `chain`, `enumerate`, `flat_map`).
- [x] `std/iter` lazy combinators — `MapIterator`, `FilterIterator`, `TakeIterator`, `SkipIterator` (struct-literal construction).
- [x] `std/runtime` — `collect()`, `collections()`, `bytes_used()`, `bytes_copied()`.
- [x] `std/sort` — `sort(arr, less)` stable merge-sort with insertion-sort cutoff. Returns a new array.
- [~] **`std/cli`** (initial 2026-05-11) — minimal declarative `FlagSpec` + `parse(args, specs) -> ParsedArgs` + accessors. Supports `--name`, `--name=value`, `--`. Open : subcommands, `--help`/`--version`, short flags `-v`, `--name value` form, rewriting `vader/cli/main.vader` on top once subcommands land.

### 1.13d Stdlib consolidation — partial
> Shipped: hex/base helpers centralised in `std/numbers`, `std/json` char-predicate duplicates removed.
- [ ] **Future audits** — revisit when new stdlib modules land. A shared `Cursor(T)` trait could unify `std/json` and `vader/lexer`'s hand-rolled cursors when a real need arises.

### 1.13e Language ergonomics surfaced by self-host port — partial

Patterns counted on the existing Vader code that paid an outsized boilerplate cost. Each item is additive, back-compat by construction.

> Shipped: `usize` literal context-sensitivity, `T | null` flow-narrowing, divergence → `never` (blocks / infinite loops), W0002 unreachable-code, enum-to-repr cast, const-binding mutation reject (T3041), field-expr + `is T` narrowing, tuple-destructure-after-narrow, byte literals `b'X'`, free type-alias order, namespace-alias unification, `MatchResult` cleanup, self-host lexer u64, `if x is T as binding`, lambda `fn`-keyword drop, `for <range>` shorthand.
- [ ] **AST node id boilerplate** — re-audited 2026-05-15 ; deferred. ~11 self-host fields + ~117 TS construction sites with `id: UNASSIGNED_NODE_ID`. All three resolution shapes (decorator, mixin, marker) need new compiler infrastructure that's bigger than the 128 lines it would save. Revisit if decorator infra lands for other reasons.
- [~] **Normalise generic syntax to `<T>` across stdlib + self-host** —
  both parsers now accept `<T>` (canonical), `[T]` (legacy bracket) and
  `(T)` (legacy paren) ; SPEC §10 leads with `<T>`. **Parser support
  done** (TS `src/parser/passes/type.ts`, self-host
  `vader/parser/parser.vader` `parse_angle_type_params`, incl. `shr`
  split-on-demand). Remaining :
  - **Migration** : rewrite every `[T]` / `(T)` generic site under
    `stdlib/`, `vader/`, `tests/`, `examples/` to `<T>` (~515 legacy
    sites remain vs ~84 `<T>`). Best done with a parser-aware AST walker.
    The `vader fmt` rewrite is a separate chantier — fmt still emits
    `[T]`, so a fmt pass post-migration would revert it unless fmt is
    updated first (or in parallel).
  - **Drop legacy parser paths** : once everything is migrated, remove
    the `[T]` and `(T)` openers from `parse_bracketed_type_params` /
    `parse_struct_type_param_list` / `parse_generic_arg_list` in both
    parsers. Pre-MVP, no back-compat (CLAUDE.md).

### 1.15 Formatter
- [ ] Define formatting rules (one canonical layout — no options).
- [ ] AST → formatted source.
- [ ] Idempotency check.

(Status update : a first cut already shipped in Vader ; see top "Priority — next up" `vader fmt` MVP. This section tracks the design freeze separately.)

### 1.16 Examples — partial
> Shipped: `hello`, `fibonacci`, `fizzbuzz`, `rule110`, `primes` (+ `brainfuck`, `mandelbrot`, `mowitnow` — see git).
- [ ] `aoc_2024_day1.vader` — validate I/O + parsing + collections.
- [ ] `wasm_browser/` — moved to Phase 3 (§3.10).

### 1.18b Generics & primitive type ergonomics — partial
> Shipped: `usize`/`isize` first-class + migrated across `arr.len()` / `std/iter` / `std/string`, deduped bounded `Range[T] implements Iterator[T]` + `Step`, generic `Range` with per-width `Contains`/`Iterator`, first-class fn values, `void!` desugar, struct-level bound enforcement (T3006) + auto-inherit onto methods.
- [ ] **Decide `usize` width on the WASM target** — moved to §3.10.

### 1.18d Common-field access on discriminated unions — partial
> Shipped: typecheck + lowerer + same-offset shortcut, peephole spread-bug fix, divergent-type policy (`unionOf` + caller narrows).
- [ ] **Methods (deferred)** — extend to UFCS calls (`e.method()` valid when every variant has a callable `method`). Invasive : overload resolution × variant set.
- [ ] **Nullable receivers** — `(T | null).f` follows the gate today (`null` lacks the field → T3009). Decide later whether to special-case optional-chaining.

### 1.19 Type-first design — remaining layers

Per `docs/DESIGN_TYPE_FIRST.md`. Surface layers (1.A–1.D, 2.A, 2.B, 3.A–3.F, 7b/7c/7e, 8a) all landed. Remaining work targets the architectural depth.

#### Layer 2 (full) — monomorphisation as comptime evaluation

The mono pass dissolves into the comptime engine : `fn[T](...)` is partially evaluated with `T` bound.

- [ ] Identify the mono surface — catalog every consumer of `MonoProject`.
- [ ] Extend the comptime engine so `call_generic_fn(fn, type_args, value_args)` returns memoised entries from a `(fn-id, hash(type-args))` cache or clones+type-checks+registers.
- [ ] Cache shape — `Map<string, MonoEntry>` keyed by mangled name. Reuse `mangleName(fn, type-args)`.
- [ ] Replace the standalone mono pass — once every generic instantiation flows through the comptime engine, delete `src/monomorphize/`.
- [ ] Test plan — snapshot bytecode for `tests/snippets/generic_*` + `iter_combinators` before/after ; bytes should be byte-identical post-rewire.
- [ ] Preserve T3033 bound-violation diagnostics — fire from the comptime engine post-rewire.

#### Layer 4 — `type` as a first-class comptime value

Architectural prerequisite for full mono → comptime migration. Built bottom-up via milestones B.0 → B.6.

##### B.0 — `@comptime` type-alias decls (DONE)
- [x] Short-circuit `@comptime t :: i32` via `constTypeAliases` lookup ; synthesises a `ComptimeValue.type` directly. `comptimeToValue` traps for now.

##### B.1 — Type as a VM Value (DONE 2026-05-16)
- [x] VM `TypeValue { tag: "type", typeIndex: i32 }` (`src/vm/value.ts`) keyed into the module type table.
- [x] Bytecode op `type.const` — `src/bytecode/ops.ts` + `.virt` round-trip (`src/bytecode/text.ts`) + `.vir` binary round-trip (`src/bytecode/binary.ts`).
- [x] Reuses existing `BytecodeModule.types` interning via `internType` — no new table.
- [x] `LoweredTypeConst` in `src/lower/lowered-ast.ts` + lowered by `lowerIdent` when an ident's type is `TypeMeta` (`src/lower/passes/expr.ts`).
- [x] CFG `InstrTypeConst` + bytecode emit (`src/midir/{cfg,build,emit}.ts`).
- [x] VM op handler (`src/vm/exec.ts`).
- [x] `ComptimeValue.type` ↔ VM `TypeValue` round-trip (`src/comptime/run.ts`) — comptime→VM uses `-1` placeholder since the comptime carrier already holds the static `Type` ; VM→comptime errors with C4011 until B.2 brings a static-`Type` source through `@type_of`.
- [x] Test snippet `tests/snippets/comptime_type_value/` — exercises a TypeMeta ident in an arg of `fn accept_type(t: type)`. The c-emit emits a tagged-null placeholder + a `uintptr_t`-encoded `typeIndex` to keep the C stack consistent ; the Vader VM lacks the op and is in `KNOWN_DIVERGENT` until `vader/vm/exec.vader` ports it.

##### B.2 — Type values flow through intrinsics (DONE 2026-05-16)
- [x] `@type_of(x)` — reifies the static type of `x` as a `type` value ; lowers to `LoweredTypeConst` (no arg evaluation, Zig-style).
- [x] `@size_of(t)` runtime path — when `t` is a TypeMeta-typed value, lowers to a new `size_of.type` intrinsic that pops a TypeValue and pushes its size as usize. Wired in TS VM, c-emit (via a generated `vader_type_size[]` table), and Vader VM. Static path (`@size_of(i32)`) continues to fold to an IntLit at compile time.
- [x] Test snippet `tests/snippets/comptime_type_value/` exercises both intrinsics.

##### Vader VM port of Layer 4 ops (DONE 2026-05-16)
- [x] `type.const` op + `TypeVal` variant in `vader/vm/op.vader`, `parser.vader`, `exec.vader`, `value.vader`, `builder.vader`.
- [x] `SizeOfType` intrinsic op in the Vader VM ; `size_of_bc_type` helper in `vader/vm/value.vader`.
- [x] `comptime_type_value` removed from `KNOWN_DIVERGENT` in `tests/vader_vm.test.ts`.

##### B.3 — Type-typed bindings in comptime
- [ ] Resolver, typechecker, lower for `let T: type = i32` in comptime context.
- [ ] T3035 "type expression must be comptime-evaluable" (closes Layer 5b).

##### B.4 — Type-yielding operations
- [ ] `GenericInstExpr` in value position → `LoweredTypeConst`.
- [ ] `BinaryExpr(.BitOr/.BitAnd)` in value position with TypeMeta operands → union/intersection Type value.
- [ ] Memoisation by `(generator-symbol, type-args)`.

##### B.5 — fn-form type aliases
- [ ] Comptime engine drives evaluation of `boxed :: fn[T]() = if @size_of(T) > 16 { Heap[T] } else { Stack[T] }`.
- [ ] Typechecker recognises a type-yielding fn signature.
- [ ] Layer 2 Phase 3 (partial eval per call site) unblocked.

##### B.6 — Computed type aliases via `type` keyword
- [x] `Maybe :: type[T] T | null` and `Pair :: type[A, B] A | B` verified.
- [ ] Struct-literal-as-type-expression — `Pair :: type[A, B] struct { first: A, second: B }`.

#### Layer 5a — uniform `[]` for type-args at call sites
- [ ] Verify call-site override `sum[i64](arr)`.
- [ ] Decide whether `MutableMap(K, V)` at call sites (still accepted) emits a deprecation warning.

#### Layer 5b — comptime contagion
- [x] Accept `t :: <structural-type-expr>` as in-fn type alias.
- [x] Reject other `type`-valued locals at typecheck (T3035).
- [ ] **Accept conditional type expressions** — `t :: if @size_of(i32) > 16 { i64 } else { i32 }`. Blocked by Layer 4 B.1.
- [x] `i32[]` in let-stmt value position. Caveat : `fn(i32) -> i32` in value position still fails (parser's `parseFnSignatureParams` expects `name: type`). Tracked separately.

#### Layer 6 — reflection iteration
- [x] `@type_of(x)` — value's static type as `type` (shipped with Layer 4 B.2).
- [x] `@fields(T) -> Field[]` (landed 2026-05-16). `Field` lives in `std/core` (auto-imported), exposes `name: string` and `type: type`. Static `T` only — lowers to a `LoweredArrayLit` of `Field { .name = …, .type = … }` literals at lower time ; field types flow through the call-site's substitution so `@fields(Pair(string, i64))` reports `value` as `i64`. Snippet `intrinsic_fields` covers Map(K, V)-style generic and non-generic structs across VM / native / Vader VM. Runtime `T` (when `t: type` is a fn param) deferred — needs a runtime struct-field table.
- [x] `@type_args(T)` — generic args of a generic instance (landed 2026-05-16). Returns `type[]` ; non-generic types yield `[]`. Sibling of `@fields(T)`, same lowering pattern (LoweredArrayLit of LoweredTypeConst per arg). Snippet `intrinsic_type_args` covers Struct + non-generic + cross-module via std/collections.
- [x] `@field(x, "name")` (landed 2026-05-16). Dynamic field access keyed by comptime string. Two typecheck paths : (1) bare string literal at call site → resolves field type immediately + T3009 on unknown ; (2) deferred path → returns Unresolved, lower-pass re-validates after `@comptime for` substitution turns `f.name` into a `LoweredStringLit`. Lowers to `LoweredFieldAccess`. Closes Layer 6 reflection : `@comptime for f in @fields(T) { … @field(self, f.name) … }` works end-to-end for derive macros.
- [x] `@comptime for f in @fields(T) { ... }` (landed 2026-05-16). Unrolls at lower time : the iter expression must lower to a `LoweredArrayLit` of compile-time-known elements, and the body is emitted N times with the loop-var substituted by each element's literal. `lowerIdent` checks a per-fn `comptimeBindings` map ; field access on a `LoweredStructLit` target folds to the field's value, so `f.name` / `f.type` become straight string / type literals — `@size_of(t)` folds to a constant per iter. Snippet `comptime_for` covers `@type_args` + `@fields` over a generic struct. Forbids `LoweredIdent` / non-array iters with B5001. Follow-ups : (a) reject `break` / `continue` in the body (today they bind to the nearest real outer loop), (b) reject `@comptime for` on `while` / infinite forms at parse time.

#### Layer 7d — non-trait predicates on generics
- Open question. `where` was removed entirely ; decide whether to re-introduce it as a keyword, expose predicates via `[T satisfies @size_of(T) <= 64]`, or forgo non-trait predicates until a real use case surfaces.

#### Layer 7a/7e — bounds as comptime predicates
- [ ] Rewrite `[T: Trait]` enforcement to `@satisfies(T, Trait)` via the comptime engine.
- [ ] Trait method dispatch on bounded type-param via comptime predicates.

#### Layer 8 — impl & coherence — mostly done
- [x] 8b — `implements` verifies inherent methods (T3036).
- [x] 8c — explicit conformance, no structural inference (T3006).
- [x] 8d — default-method injection at `implements` site.
- [x] 8e — orphan rule (light, R2018, primitives exempt).
- [x] 8f — ambiguous trait-method dispatch (T3032).

#### Open questions deferred
- Q8 — comptime evaluation budget (decide once Layer 2 lands).
- Q10 — hygienic macros vs `@comptime for`-only (`@comptime for` covers ~95 %).
- Q11 — migration phasing (layer-by-layer is the plan).

---

## Phase 2 — Self-hosting

Begins as soon as the TS compiler can compile a non-trivial subset. Goal : validate the design as we go.

### 2.0 Vader CLI minimal — partial
> Shipped: argv parsing + stage dispatch, snapshot parity rig (`tests/parity/`), native CLI build via `tests/cli-bin.ts`.
- [ ] Future stages plug in as parser / typechecker / lowerer get ported.

### 2.1 Port the parser to Vader — partial
> Shipped: lexer (`vader/lexer/`), diagnostics (`codes`/`diagnostic`), parser (`vader/parser/`, ~2200 LoC recursive-descent + Pratt), AST→JSON dumper, `vader dump --stage=ast`, byte-for-byte lexer + parser parity (~240/245), porting bugs all closed.
- [ ] **Diagnostics folder-module migration** — today `vader/diagnostics/{codes,diagnostic}.vader` resolve as separate single-file modules, so `private` doesn't survive cross-file. Migrate to folder-module to hide internals.

### 2.2 Port the C emitter — NATIVE FIXED POINT REACHED (2026-06-05)
- [x] **Native self-host fixed point** (2026-06-05). The cc-built
      (Vader-emitted-C) compiler re-emits the whole compiler's C and
      `stage1.c == stage2.c` **byte-identical** (208 678 lines). Pipeline:
      `bun run build:cli` → build/vader ; `./build/vader dump --stage=c
      vader/cli/main.vader` → stage1.c (raise GC, e.g. 512M/2G) ; `cc -std=c11
      -I runtime/c stage1.c runtime/c/vader_runtime.c` → stage1 ; `stage1 dump
      --stage=c vader/cli/main.vader` (GC 4G/8G) → stage2.c ; `diff` identical.
      Four native-fixed-point frontiers cleared en route: (1) entry-main
      resolution by name (`7202609b`-era), (2) erased-struct `type_check`
      sibling-tag disjunction (`51fcfe7e`), (3) primitive-trait vtable for
      erased generic dispatch (`560a4ab4`), (4) `is`-check operand
      union-narrowing constant-fold (`d77f5bc4`). Walker lives under
      `vader/c_emit/` (walker / dispatch / body / host / stack / emit).
- [x] Port to Vader — per-op walker + vtable dispatcher + helpers ported.
- [x] Snapshot-test parity — `c.snapshot` goldens + compile/run vs
      `vm.snapshot` (gate: `tests/parity-cemit.test.ts`, C_PARITY allowlist).
- [ ] **Deferred follow-ups** (do NOT block the byte-correct fixed point):
      - **resolver StampCtx for `@intrinsic` impl-member param spans** —
        `materialize_intrinsic_members` (`vader/resolver/materialize.vader`)
        reuses the trait method's param span, collapsing the span-keyed
        `param_types` table across primitive implementors. `560a4ab4`'s
        `impl_member_param_type` is a lower-site workaround ; the deeper fix
        is `StampCtx` (as `materialize_default_members` already uses).
      - **typer over-narrows the `is`-operand** — `d77f5bc4` strips the
        narrowing cast at the lowerer ; cleaner would be the typer not
        narrowing the operand, optionally + a C-emit `emit_type_check`
        no-fold-after-`ref.cast` hardening as a second defense.
      - **2 pre-existing stale bytecode snapshots** (`io_println`,
        `string_ops`) — drifted from the `dump --stage=bytecode --annotate`
        work, never regenerated ; regenerate (proven not caused by §2.2).
      - **Vader bytecode emitter drops `defer`** (`emit_body.vader` stub) —
        separate self-host correctness gap surfaced by the C-emit T7 tranche.
- [ ] **Carry the C-emit codegen pistes into the Vader walker port** (perf,
      separate from the byte-correct fixed point above).
      `vader/c_emit/body.vader` currently holds helpers only ; when the
      per-op walker is ported, it must include :
      - **Piste 5.a** — `local.get` / `local.tee` for ref/any route
        through `push_local_ref` (no refTmp snapshot ; locals are
        already pinned via `gc_roots[]`). See plan §8.
      - **Piste 1** — per-pool tmp recycling (free-list + refcount on
        `dup`) with prelude-declared tmps and aux scratch vars from a
        monotone `auxCounter`. See plan §9.
      - **Piste 5.c** — `expr`-kind StackVal for `type_check` ; the
        consumer inlines via `nameOf`. `materializeStackForSlot`
        materialises every in-flight expr at any `local.set/tee`.
        `dup` materialises expr first. See plan §10.
      - **Piste 5.d** — `expr`-kind for pure binops / cmps / unary /
        casts ; `div` / `rem` stay eager. Equality (`==` / `!=`)
        stores text paren-free ; every other op wraps for precedence.
        `pushUnop` parenthesises its operand. See plan §11.
      Cumulative gain on the TS side : -10.5 % file size, -77.4 % cc
      time (-O0), -86.6 % cc time (-O3).

### 2.3 Port the bytecode emitter — feature-complete on current LoweredAST, plumbing dormant (2026-05-21)

The emit walker covers all 29 `LoweredExpr` variants + all `LoweredStmt`
shapes. `vader dump --stage=bytecode` runs through the Vader-side
pipeline (`./build/vader`). The CLI binary builds in ~2:30 local /
~3-4 min on CI Ubuntu.

Files :
- `vader/bytecode/emit.vader` (561 LoC) — top-level orchestration
  (Pass 1 reservation → Pass 1.5 intrinsic-wrapper synth → Pass 2
  body emit → assemble), `reserve_fn` / `reserve_extern` /
  `emit_fn_body`, `synthesise_intrinsic_wrappers`, `translate_vtables`,
  `translate_data_pool`, `assemble_module`.
- `vader/bytecode/emit_body.vader` (725 LoC, ≈90 % of 800 cap) —
  every per-shape `emit_<X>` for stmts + exprs. Not splittable
  because of Vader's mutual-import constraint (same as
  `lower_expr.vader`'s doc note).
- `vader/bytecode/emit_ctx.vader` — `EmitterCtx`, `intern_type`,
  `intern_string`, `intern_cell_type` ($Cell\<T\> synth struct).
- `vader/bytecode/emit_state.vader` — per-fn `FnEmitState` + scope
  stack + jump_table.
- `vader/bytecode/op_select.vader` (~290 LoC) — `binary_op_for(op,
  lhs_val)` / `unary_op_for(op, operand_val)` selectors covering
  I32X / I64X / U32X / U64X / F64X / Bool / Char / String op
  families with width-aliasing rules.
- `vader/bytecode/dump.vader` (~300 LoC) — `dump_bytecode :
  BytecodeModule → string`, `.virt`-style text writer (covers all
  ops emitted today ; minor spelling drift from `text.vader`'s
  canonical writer).
- `vader/bytecode/intrinsics.vader` — `intrinsic_op_for_mangled`
  table (raw-string keys).

What works end-to-end :
- [x] All LoweredExpr variants (literals, ident, call, binary, unary,
      if, block-as-value, struct lit, field access, array lit/len/
      push/slice, index, cast, type_check, type_const, data_const,
      make_closure, virtual_call, intrinsic_call, cell_new/get/set).
- [x] All LoweredStmt variants (return, expr_stmt, let, assign,
      loop, break, continue, cell_set).
- [x] Static + intrinsic + import call dispatch
      (`emit_call_to_symbol` cascade).
- [x] Indirect calls (`CallIndirect` via fn-typed local slot or
      complex callee expression). `FnRef` for fn taken in value
      position.
- [x] Vtable translation (`translate_vtables` groups
      `LoweredProject.vtable_entries` by (trait, method) into
      `VtableRow[]`).
- [x] $Cell\<T\> synth struct for closure cells
      (`intern_cell_type` materialises a `BcStruct { fields:
      [value: T] }` ; cell_new/get/set use StructNew/Get/Set).
- [x] Stage wired into CLI (`vader dump --stage=bytecode` produces
      `.virt`-style text). Validated on `tests/snippets/arith`,
      `tests/snippets/closure_counter`.

Plumbed but DORMANT (require lower-side changes first) :
- [~] `synthesise_intrinsic_wrappers` — implementation matches
      `src/bytecode/emit.ts::synthesiseIntrinsicWrappers`. Walks
      imports for `@intrinsic` entries, creates `<mangled>$vt`
      wrapper fns so virtual.call on primitive receivers can land
      on a real fn-index. **Inactive today** because the Vader-side
      lower explicitly skips stdlib paths
      (`lower.vader:87 is_stdlib_path`) so `@intrinsic` decls never
      reach reservation. Activates automatically once stdlib externs
      surface (likely via a separate emit-side enumeration pass to
      keep the lambda counter clean).
- [~] `translate_data_pool` — empty pass-through. The lower never
      populates `DataPoolEntry`. The string-element parser would
      duplicate `parse_<type>` logic ; consider mirroring the TS
      shape (have the lower produce `u64[]` items directly) and
      delete this fn rather than implementing the parser.

Known gaps vs TS-side emit :
- [ ] Mid-IR (CFG/DCE/escape) — not ported. Vader uses direct
      LoweredAST → bytecode (no peephole / no slot-coalesce / no
      DCE on the bytecode side).
- [ ] **Lower-side stdlib surface** — the `is_stdlib_path` skip
      (lower.vader:87) keeps stdlib `@intrinsic` / `@extern` decls
      out of `LoweredProject.modules`. Either drop the skip (would
      pollute the synthetic-id counter — see existing comment
      rationale), or add a separate "enumerate-stdlib-externs" pass
      that surfaces imports on-demand at emit time. Until then,
      every Vader-side dump misses the import table + stdlib
      vtable rows + intrinsic wrappers.
- [ ] **emit_body.vader file split** — blocked by Vader's
      mutual-import limitation. `emit_block ↔ emit_stmt ↔ emit_expr
      ↔ emit_if / emit_loop` form a cycle ; no seam is viable
      without cyclic imports. Same constraint forces
      `lower_expr.vader` to live as a single 1300+ LoC file. When
      Phase 8+ piles on more emit_* helpers, either add Vader
      forward-decls or bump the per-file cap for this file
      specifically.
- [ ] **Performance** : reviewers flagged the 4-map cascade in
      `emit_call_to_symbol` (slot → intrinsic → fn-table → import)
      and the per-call string allocation in `intern_cell_type`.
      Refactor candidate : a single `MutableMap(symbol_id,
      CallTarget)` keyed at registration time. Deferred until
      bytecode emit shows up on a profiler.
- [ ] Snapshot-test parity (Vader-emit `.virt` vs TS-emit `.virt`).
      Spelling drift remains in `dump.vader::format_op` (e.g.
      `i32.mod` vs `i32.rem`, `i32.shr_u` vs `u32.shr`) ; reconcile
      first, then byte-diff.

Recent commits (this work) :
- `5c52f364` — port synthesise_intrinsic_wrappers + extern→imports routing
- `bb5c77a2` — Phase 7+ : CallIndirect/Import + FnRef + vtable wiring + $Cell synth struct
- `86ec9013` — Phase 8 : LoweredBlock-as-value emit
- `99c3c5aa` — Phase 7 : LoweredBinary + LoweredUnary emit
- `395a1f9b` — Phase 6b : wire bytecode stage end-to-end
- `54bdb551` — Phase 6a : closures + intrinsics + VirtualCall
- earlier Phases 1-5 already in history.

Tests : `bun src/index.ts test vader` = 314/314 pass.

Pick-up checklist for next session :
1. Decide on lower-side stdlib surface strategy (drop the skip vs
   on-demand enumeration). Without it, every wiring downstream
   misses externs.
2. Once externs surface, validate intrinsic wrappers actually
   generate, then verify VirtualCall on primitive receivers lands
   on the wrapper fn-index.
3. Reconcile `dump.vader::format_op` spellings with
   `text.vader::write_op_line`, then enable per-snippet
   bytecode parity tests (Vader-emit vs TS-emit).
4. Split `emit_body.vader` only when forced (cap bump or Vader
   forward-decls).

### 2.4 Port the VM

Sprint plan : [`docs/SELFHOST_VM.md`](./docs/SELFHOST_VM.md). The Vader VM reads `.virt` so each sprint validates against the live TS pipeline.

- [ ] Sprint 1 — `i32.const` + `return` ; `vader run return_42.virt` exits 42.
- [ ] Sprints 2-5 — locals, binops, control flow, strings, structs, arrays, calls, type checks.
- [ ] Sprint 6 — binary `.vir` loader (optional).
- [ ] Verify `examples/` runs against the TS VM.

### 2.5 Port the WASM emitter — gated on §3.10
(Empty until the TS WASM emitter lands.)

### 2.5b Port the comptime engine — partial (tree-walk MVP, 2026-05-18)

Tree-walk evaluator covering the subset of comptime expressions the
lowerer + bytecode emitter port haven't unlocked yet. General
Turing-complete `@comptime fn` bodies (loops, function calls) defer
until the full VM-round-trip path is online.

- [x] **Phase 1** — `ComptimeValue` IR + `EvaluatedProject` shapes +
      C4xxx codes (`vader/comptime/value.vader`,
      `vader/comptime/evaluated_ast.vader`, `vader/comptime/mono_ast.vader`,
      `vader/diagnostics/codes.vader`).
- [x] **Phase 2** — Dependency graph + topological sort + cycle
      detection (`vader/comptime/deps.vader`).
- [x] **Phase 3** — `# Comptime` dump + CLI `--stage=evaluated-ast`
      handler + orchestrator skeleton (`vader/comptime/dump.vader`,
      `vader/comptime/check.vader`).
- [x] **Phase 4** — Tree-walk evaluator covering literals, binary +
      unary ops, ident lookup, nominal type values
      (`vader/comptime/eval*.vader`).
- [x] **Phase 5** — Minimal `@intrinsic` evaluator
      (`@size_of` / `@align_of` / `@type_name` / `@type_kind`) in
      `vader/comptime/intrinsic.vader`.
- [x] **Phase 6** — Instance registry + `## generic instances`
      dump section (`vader/comptime/instances.vader`).
- [x] **Phase 7** — `@assert` walker + cleanup
      (`vader/comptime/assert.vader`).

#### Deferred until lowerer + bytecode emit port

- [ ] **Generic fn-instance harvest** — TS uses
      `typed.genericFnCalls` to detect every `identity(i32)` /
      `map(i32, i32)` call site at comptime. Vader's typechecker
      doesn't maintain this side-table yet ; without it the
      `## generic instances` section omits fn instances. Closing the
      gap requires adding `generic_fn_calls: MutableMap(usize,
      Type[])` to `TypedProgram` and populating it at every
      generic-fn call resolution in `call.vader`.
- [ ] **for-in ArrayIterator detection** — `for x in arr` auto-wraps
      into `ArrayIterator(T)`. TS scans every fn / impl body for `for
      x in <Array>` and registers the wrap. Mirrors TODO above ; same
      walker shape applies.
- [ ] **Into-coercion materialisation** — blanket `T[] implements[T]
      Into(Iterator(T))` impls contribute their member specialisations
      to the registry. TS's `walkImplBodyForCalls` drives this.
- [ ] **Transitive closure** — `closeOverGenericImpls` worklist that
      re-observes the substituted return types of every newly-added
      impl member instance.
- [ ] **Bytecode-driven comptime evaluation** — `@comptime fn` bodies
      with loops, function calls, mutation. TS routes through
      `lower-decl.ts` → `bytecode/emit/` → `vm/exec.ts`. Vader has
      the VM (`vader/vm/`) but not the lowerer or the bytecode emitter
      yet — `vader run main.vader` still reports "not yet implemented
      (only .virt for now)".
- [ ] **`@field` / `@fields` / `@file` / `@env` intrinsics** — Phase
      5 ships only the four type-reflection intrinsics. The richer
      coverage lands when downstream consumers (lower-time field
      access, `@file` content baking) need them.

#### TS divergences (Vader is correct)

(none recorded yet)

### 2.5c Port the lowerer — partial (basic + match + interp + range, 2026-05-18)

Lowerer port covering the subset the comptime + typecheck side-tables
already expose. Lambda lifting, for-in / Iterator, try, display-coerce,
and the inline-consts pass defer until the missing impl-by-trait
queries + closure-analysis pass land on the typechecker side.

- [x] **Phase 1** — Foundations : `LoweredProject` / `LoweredDecl` /
      `LoweredExpr` / `LoweredStmt` shapes, `LowerProjectCtx` +
      `FnLowerCtx` + `BlockCtx` + `LiftedFnContext` +
      `ClosureAnalysis`, `EntryTypes` accessor, `std/core` symbol
      lookups, helpers + L5xxx codes
      (`vader/lower/{lowered_ast,ctx,entry_types,core_symbols,helpers}.vader`,
      `vader/typecheck/substitution.vader`).
- [x] **Phase 2** — Orchestrator skeleton + `# Lower` dump + CLI
      `--stage=lowered-ast` handler
      (`vader/lower/{lower,dump}.vader`).
- [x] **Phase 3** — Basic expression + block / stmt lowering : every
      literal, ident, binop, unop, field, index, cast, if-expr,
      block, struct lit, array lit, intrinsic call, plain string lit ;
      `let` / `assign` / `return` / `expr-stmt` / `break` / `continue` ;
      infinite + `while`-style `for` loops
      (`vader/lower/lower_expr.vader`).
- [x] **Phase 4** — `match` lowering + string-interp builder chain +
      `is T` runtime tag check (`vader/lower/lower_match.vader`).
- [x] **Phase 5** — `a..<b` / `a..=b` range desugaring to `Range`
      struct literals (`vader/lower/lower_range.vader`).
- [x] **Phase 5b** — Lambda lifting (no-capture MVP) :
      `LambdaExpr → LoweredMakeClosure` with a synthesised lifted fn
      + an empty env struct, both appended to the owning module's
      decl list. The previous crash was a Vader codegen quirk when
      relying on struct-field default values inside the synthesised
      `Decl` ; every field on the stub `FnDecl` / `StructDecl` is
      now initialised explicitly (`vader/lower/lower_lambda.vader`,
      `vader/lower/lower.vader::lower_module`).
- [x] **Phase 5c** — Convergence with TS `lower.snapshot` : seven
      incremental fixes — module-path mangling, `struct_field_types`
      lookup, `type_from_expr` fallback for `IsPattern`, tuple-typed
      `SeqLitExpr → LoweredStructLit` with `_N` fields, `arr.push(x)`
      / `arr.len()` → dedicated array ops, `ImplDecl` members emitted
      as fns with `<module>$<for-type>$<trait>$<method>` mangling,
      struct lit defaults filled in decl order, `EnumDecl → EnumType`
      unwrap for `DotVariantExpr` + match-arm predicates. The lowered
      dump now byte-matches **60 / 226** TS-sourced fixtures (was
      0 / 226 before mangling).

- [x] **Phase 5d** — Closure analysis : free-variable walker
      (`vader/lower/closure_analysis.vader`) + capture-routing in
      lambda lift. `analyze_closures(loaded, typed)` runs once at
      project entry and populates `ClosureAnalysis.lambda_captures`
      keyed by `LambdaExpr.id`. `lower_lambda` reads the captures,
      builds the env struct with `cap_<N>` fields, and threads a
      `LiftedFnContext` so captured idents inside the body route
      through `env.cap_N` via `LoweredFieldAccess`. Cell promotion
      (`LoweredCellNew` / `LoweredCellGet` for by-reference closure
      semantics) stays a follow-up — the dump shape now mirrors TS
      except for the cell ops on captured-mutables.
- [x] **Phase 5e** — Project-wide impl-by-trait registry +
      `find_impl_for(ctx, for_type, trait_name)` query in
      `vader/lower/core_symbols.vader`. Multi-module aggregation
      happens at lower entry via `populate_impls`. First consumers :
      - `lower_try.vader` : `expr?` splits the operand into error /
        ok variants using `find_impl_for(.., "Error")` per variant,
        emits `let __try_n :: <inner>` + an if whose error branch
        returns the bound ident.
      - `lower_string_lit` : non-primitive interp segments now
        route through `<T>.Display.to_string(value)` +
        `builder.append_str` (was : always `builder.append_display`).
- [x] **Phase 5f** — Match-count chantier : raised lower.snapshot
      byte-match rate from 60 / 226 to 67 / 226 across seven fixes :
      - `for-in` slow path (Iterator step loop + ArrayIterator
        auto-wrap) + int-range fast path (counter loop) +
        for-binding synth fallback (`vader/lower/lower_for_in.vader`).
      - `core_symbols` populated at lower entry from every module's
        `resolved.core_symbols` so `find_core_type("Yield", [T])`
        etc. resolve.
      - Wide-unsigned widths (u32 / u64 / usize) route through
        `<T>.Display.to_string` (signed-carrier VM workaround).
      - `CheckResult.all_modules` exposes std-module typed views so
        the project-wide impl registry sees
        `MutableMap[K,V] implements IndexSet[K, V]` etc.
      - `m[k] = v` IndexSet sugar rewrites to direct `set_at(m, k, v)`.
      - `arr[lo..<hi]` / `arr[lo..=hi]` literal-range slicing emits
        `LoweredArraySlice` (zero-copy view).
      - `<namespace>.foo(args)` collapses to direct `foo(args)` call.

- [x] **Phase 5g** — Continued byte-match chantier (2026-05-19) : raised
      lower.snapshot byte-match rate from 67 / 226 to 181 / 226 over
      ~25 commits, then settled at **148 / 226** after the typecheck /
      midir / c-emit perf chantiers reshaped surrounding stages. Major
      pieces in order :
      - Iter-chain fusion (`arr.map(f).filter(p)` collapses to a single
        loop), virtual-call dispatch on trait-typed receivers, free-fn
        UFCS detection, monomorphizer port + per-call generic instance
        registration, monomorphized struct decl emission.
      - Literal context-typing for union annotations, generic-fn
        unification through tuple types, `@size_of` / `@align_of` /
        `@type_name` / `@type_kind` static folds, Into coercion at
        return + struct-lit field sites.
      - Final 2026-05-19 batch in commit `70a904ef` : `BinaryOp.Mod`
        routes to the `Rem.rem` trait method, `@satisfies(T, Trait)`
        folds to a literal bool, TypeMeta-typed idents reify via
        `alias_types` + `primitive_from_name` to `LoweredTypeConst`,
        `@type_of` / `@type_args` fold at lower time, runtime
        `@size_of(x: type)` routes through the dedicated
        `size_of.type` intrinsic, else-less `if` voidifies the then
        block (trailing → stmt), `find_free_fn_ufcs` scans aliased
        imports + cross-module `fn_overloads`, `lower_ident` follows
        named import-bindings to their target symbol, `type_surface_name`
        canonicalises array (`[]`) / tuple (`()`) and treats a
        TypeParam first param as a wildcard receiver, unsigned literal
        widths print non-negated in the dump.

#### Closed by 5g + downstream chantiers

- [x] **for-in / Iterator step loop** — landed in Phase 5e/5g via
      `vader/lower/lower_for_in.vader` + `impl_by_trait` queries on
      the entry typed program. Raw-array for-in skips `ArrayIterator`
      entirely (commit `aa2dc5ce`).
- [x] **try** — `expr?` lowering in `vader/lower/lower_try.vader`
      consumes the `Error`-trait impl set via `find_impl_for`.
- [x] **Display / Into coercion** — non-primitive interpolation
      segments route through `<T>.Display.to_string` ; Into coercions
      fire at let / return / struct-lit / call-arg sites
      (`try_emit_into_coercion` in `lower_expr.vader`).

#### Still open

- [x] **`Cell(T)` heap promotion** (verified 2026-05-26). Already
      wired end-to-end :
      - `lower_let` (`lower_expr.vader:2262`) wraps the initialiser via
        `lower_cell_init` ; ditto `lower_match.vader` pattern bindings
        (lines 322 / 335 / 359).
      - `lower_ident` (`lower_expr.vader:196-204`) emits
        `LoweredCellGet` on captured-symbol reads ; lifted-lambda body
        routes through `env.cap_N` via `try_route_through_env`
        (`lower_expr.vader:380-398`).
      - Assignment through a captured slot lands as `LoweredCellSet`
        via `try_lower_cell_set_assign` (`lower_expr.vader:2496-2517`).
      `vm_closure_mutating` runs cleanly through the Vader VM ;
      snapshot bytecode shows the cell ops.
- [ ] **Inline-consts pass** — post-lowering const substitution +
      data-pool routing. No upstream blocker, but lands alongside the
      bytecode-emit chantier where the data pool actually matters.
- [ ] **Snapshot flip** — `tests/snapshot.test.ts:22` still consumes
      TS's `dumpLower`. Current byte-match is 148 / 226 ; the
      remaining diffs cluster around comptime VM execution
      (`square_call`, `interp_string_comptime`, `file_decorator`),
      `let t :: i32` in-fn type aliases (no `let_type_aliases` table
      ported yet), defer in nested blocks, and a handful of
      direct-call-overload retypings. Flip when this rate climbs into
      the 200+ range, regenerate the ~226 `lower.snapshot` fixtures
      from `dumpLowerViaVader`, and document any TS-correct
      divergences in the section below.

#### TS divergences (Vader is correct)

(none recorded yet)

### 2.6 Port the type-checker (last)
- [x] Port to Vader.
- [ ] Snapshot-test parity on every sample.

#### Bugs surfaced while porting the typechecker — open
- [ ] **`if cond { i32_expr } else { 0 }` doesn't collapse `i32 | {integer}` to `i32`** (surfaced 2026-05-26 by the LSP on `stdlib/std/semver/semver.vader::caret_upper`). When one branch of an `if`-expression has a concrete numeric type (`p.major: i32`) and the other branch is a free-integer literal (`0`), the Vader self-host typer joins them as a union `i32 | {integer}` instead of promoting the free int to the concrete width. The LSP then flags downstream uses with T3017 (`operator not defined for these operand types: i32 | {integer} and {integer}`) on `maj + 1`. TS-side `dump --stage=typed-ast` reports zero errors on the same source, so it's a Vader-only regression — likely a missing case in `join_types` / `merge_branches` where one operand is `FreeInt` and the other is a concrete primitive width. Workaround at user level : explicit cast (`{ i32(0) }`) in the partial-default branch, but that defeats the point of free-numeric defaulting. Fix probably one-liner in `vader/typecheck/{join,merge}.vader` (mirror what `is_assignable` does for FreeInt → concrete).
- [ ] **`is Type` antipattern in union-typed values** — `match expected { is Type | null }` etc. `expected is Type` against the closed `Type` union always returns false (the runtime tag is the variant tag, not the union tag). Bit me twice : `seq_lit.vader::infer_seq_lit` ignored every union-shaped expected slot ; `infer_seq_lit`'s "`picked is Type`" branch never fired. Fix is `match { is null -> {} _ -> ... }`. Search the codebase for other `is <UnionAlias>` checks (none found via grep on the typecheck dir, but worth a pass over `vader/resolver/` and `vader/lower/`). Either lint this at the compiler level or rename the patterns to avoid the trap.
- [x] **`vader build -o <path>` honored** (2026-05-17) — `cmdBuild` now pre-strips `-o <path>` POSIX-style and treats it as `--out=<path>`. Earlier the `--`-prefix filter dropped both `-o` and its value into positionals ; `outFlag` stayed undefined and the binary landed at the default location.
- [ ] **`settle_external_expr_bodied_returns` walks every non-entry module's body** (added 2026-05-17, `vader/typecheck/orchestrate.vader`). Runs the full `walk_bodies` pass (FnDecl + ImplDecl + ConstDecl + AssertDecl) instead of just the expression-bodied fns whose returns need patching. Triggers on any module that has *one* expr-bodied fn ; for std/iter etc this can multiply typecheck time. Scope it down to expr-bodied FnDecls + impl methods only.
- [x] **Code-size explosion when adding a small branch to `is_assignable`** (mitigated 2026-05-21 via Phase B of `CC_COMPILE_TIME_REDUCTION.md`, verified 2026-05-26). `is_assignable` moved from `vader/typecheck/type_ops.vader` to its own file `vader/typecheck/type_assign.vader` and was split into one helper per source variant (`is_assignable_struct`, `is_assignable_array`, `is_assignable_fn`, `is_assignable_union`, `is_assignable_tuple`, `is_assignable_trait_from`, `is_assignable_freeint`, `is_assignable_freefloat`) plus a shared `check_common` for primitive / enum / never / type-meta / type-param fast paths. The dispatcher (`is_assignable` itself) is now ~25 LoC of `match from { ... }`. Measured 2026-05-26 on `vader/cli/main.c` : `is_assignable` C body is **80 lines** (down from 51 536 pre-split, -99.85 %). Adding a new arm goes into one of the per-variant helpers ; the old monolithic explosion can't recur because there's no monolith to inline-clone. Cause-root (c) from the mitigations list — c-emit's match-arm cloning behaviour — turned out to be irrelevant once the monolith was broken up.
- [ ] **`build/vader` background processes don't get killed when typechecker / VM regresses** (2026-05-17). Found 3 `build/vader run tests/snippets/custom_iter/bytecode.snapshot.virt` + 1 `bun src/index.ts run bench/map_iter.vader` processes pinning 100% CPU for **33+ hours**, residue of sessions where custom_iter's bytecode VM execution actually did loop forever (since fixed). `parity.test.ts` has a 30s per-test timeout but the native runner spawned from it doesn't inherit that — once Bun's test driver bails on timeout, the spawned VM keeps running. Add a `kill` step to the native test driver's cleanup, OR run each child under a hard wall-clock budget (`timeout 30s build/vader run ...`).

- [ ] **DCE primitive trait-impl entries via "primitive-as-value" usage tracking** (2026-05-25). `src/midir/dce.ts::drainPending` at line 156 explicitly punts on primitive receivers : `if (e.structSymId !== null && !reachable.has(e.structSymId)) continue` — every primitive impl skips the gating, so the full `Display` / `Equals` / `Add` / `Sub` / `Mul` / `Div` vtable survives as soon as any `virtual.call` against the trait survives. Concrete cost on a generic `[T: Display]` fn lowered via erasure : 15 `to_string` imports + 15 `_vt` trampolines + 15 vtable rows for *one* `println(some_i32)` call. Stop-gap landed 2026-05-25 : `@specialize` on the four `std/io` wrappers (sidesteps virtual.call entirely for the common case). Proper fix : track which primitives are actually materialised in reachable code (literal consts, casts, fn signatures' param/return types, struct field types) and gate primitive-receiver impls on that set. Implementation surface : (a) add a `usedPrimitives: Set<PrimitiveName>` populated during the worklist walk in `pruneUnreachable` (visit `LoweredIntLit` / `LoweredFloatLit` / `LoweredCast` / `LoweredFieldAccess` / fn-decl param-types) ; (b) extend the `pendingVirtual` drain with a primitive-aware gate analogous to the existing struct gate ; (c) verify the change doesn't break tag-aware paths in trait_box_range_iter / json_basics. Earns the win for *every* generic `[T: Display]`-shaped user code, not just the stdlib wrappers — `@specialize` is the local opt-in, this is the global default.

- [ ] **Self-host closure capturing two free vars segfaults at runtime** (2026-05-25). While simplifying `vader/typecheck/orchestrate.vader::pull_referenced_external_types` to route through the canonical `for_each_type` walker, replacing the explicit recursion with `for_each_type(t, (sub: Type) -> register_named_external(sub, entry, per_module))` made the self-host binary SIGSEGV (exit 139) at the first call. The only prior closure-with-capture in the tree (`vader/midir/lowered_walk.vader:222`) captures a single `ctx` struct ; my version captures two free vars (`entry: TypedProgram` and `per_module: MutableMap(string, TypedProgram)`). Reverted to explicit per-variant recursion with a code comment pointing at this entry. Probable root cause : `vader/lower/closure_analysis.vader` + `LoweredMakeClosure` emit doesn't handle the second captured slot correctly, or the `$Cell_T` synthesis miscomputes the layout. Repro path : restore the `for_each_type` form at `orchestrate.vader:758` (see git history of the 2026-05-25 fix commit), rebuild, run `./build/vader dump --stage=typed-ast vader/cli/main.vader`. Until fixed, prefer the explicit walker shape OR bundle captured state into a single struct (the lowered_walk.vader pattern).

#### Language ergonomics surfaced while porting the typechecker — open
- [x] **`!is` (negated type-test) operator** — landed via commit `03525c1f` ("feat(parser): add `!is` operator and `for <range>` shorthand"). Both Vader self-host parser (`vader/parser/parser.vader:2392-2418`) and TS parser (`src/parser/passes/expr.ts:122`) desugar `x !is Y` to `Not(BinaryOp.Is(x, Y))`. Formatter restores the spelling (`vader/fmt/printer.vader:1276-1284`). SPEC.md §"operator precedence" documents the form (lines 299, 330, 335).
- [ ] **`if a is X { a.field }` doesn't narrow `a` across statements** — single-expression guards work but `if a is X { for v in a.variants { … } }` requires a `match a { is X as ax -> { for v in ax.variants { … } } _ -> {} }` rewrite. Bit me in `vader/typecheck/binary.vader::types_overlap` ; eventually settled on a tiny `union_variants :: fn(t) -> Type[] | null` helper to dodge the narrow. Either tighten the flow analysis so `a.variants` inside the if-then sees the narrowed type, or document the rewrite + add it to the formatter's lint pass.

#### Typechecker port follow-ups — open
- [x] **Cross-module folder modules** — landed 2026-05-17. Root cause was a runtime UAF : `vader_read_dir` stored `ent->d_name` (DIR-owned, reused on next readdir) without copying. `mod_a` was the first user-folder ; by the time its name was read back, the buffer pointed at garbage so `load_module_files` saw an empty entry and skipped the module. `vader_string_alloc` + memcpy in `vader_runtime.c`. Also `join_path` now strips leading `./`, `dump_program_with_others` writes one section per loaded module (sorted), and `settle_external_expr_bodied_returns` walks every non-entry module's bodies so per-module `expr_types` populate for the dump.
- [x] **Generic trait method substitution** (2026-05-17) — landed via `trait_decl_owners` side-table + `substitute_by_name` over `Yield(T)` etc. `try_default_trait_method` for inherited Iterator defaults landed too. Unblocked iter_coerce_array (with `try_array_to_iter` in coerce.vader), iter_combinators, iter_zip_chain, trait_box_range_iter, string_codepoints. Still blocked on default-method *materialize-into-impl-with-original-line:col* (separate item below).
- [x] **Generic fn-call argument inference back-propagation** (2026-05-17) — `call.vader::infer_call` now substitutes bindings into each param BEFORE typing it (so lambda's expected fn-type reflects already-bound type-params), and `unify_type_param` tightens Free* bindings when a later arg pins the same TypeParam to a concrete numeric. `expr_lambda.vader::pick_final_return` falls back to body's defaulted type when expected is TypeParam-bearing.

- [x] **Default-method materialize into impls with original line:col** (verified 2026-05-26). Landed via commit `5e4c1b84` (`feat(resolver): default-method body materialization`) with follow-ups `2b8ddab4` (substitute_by_name walks TraitType args), `cded9837` (skip walk_fn_body for materialized clones), `d9303880` (chain struct→trait→receiver substitution). The full expression walker lives in `vader/resolver/substitute_body.vader::substitute_expr_full` (291 LoC), called from `vader/resolver/materialize.vader::materialize_default_members`. All 5 previously blocked snippets pass parity : `custom_iter`, `custom_iter_generic`, `iter_defaults`, `trait_dispatch_generic_iter`, `for_in_iter_trait`.
- [x] **T3006 (trait bound not satisfied) at call sites** (2026-05-17) — landed via `fn_decls: i32 → FnDecl` side-table (cross-published across modules), idents-write on type-param decl sites in the resolver, and `check_typeparam_bounds` post-pass in `call.vader::infer_call`. Closed `conformance_explicit`.
- [ ] **`a == b` on user structs → `a.equals(b)` lowering at typecheck** — TS records the synthesised CallExpr / FieldExpr in `expr_types` at the BinaryExpr's span so the dump shows `bool` / `fn(Money) -> bool` / `Money` entries even though the source is just `a == b`. Self-host returns plain `bool` without the synth entries. Blocks `op_overload_eq_ord` parity.
  - **Investigation 2026-05-26** : the visible divergence is downstream of a deeper issue. Vader's `materialize_default_members` runs at typecheck time (`vader/typecheck/orchestrate.vader:513`) AFTER the resolver, so cloned `self` / `other` IdentExprs in the materialised body keep trait-source spans that aren't bound in the impl module's `resolved.idents`. TS structures this differently — `materializeDefaultMembers` runs INSIDE `resolveImplDecl` (`src/resolver/resolve.ts:257`), so the cloned body gets walked + bound at resolver time. Effect : Vader's `lower_ident` hits `unresolved ident self` on every cloned receiver, the materialised fn dumps as `:?` everywhere, and the `a == b` → `a.equals(b)` rewrite degrades to a `.equals` FieldExpr call against an unreachable `self`. **Same root cause also blocks `custom_iter` / `custom_iter_generic` / `iter_defaults` / `trait_dispatch_generic_iter` / `for_in_iter_trait` lower-parity** (those pass typecheck-snapshot parity per the row above, but their lower.snapshot still diverges on the materialised-body `:?` entries). Proper fix : move `materialize_default_members` to a project-level resolver post-pass that knows the trait_decl (cross-module lookup) and walks the cloned bodies through the resolver to mint Local symbols + bind their cloned spans. Add a Vader-side `find_foreign_ident_sym` mirroring `src/lower/passes/expr.ts:602` so lower can fall back to the trait module's `idents` when the impl's map misses. Multi-day chantier. A local fix attempt (walk materialised body silently at typecheck) regressed 5 tests with bogus `:?` entries — reverted.
- [x] **Namespace-alias struct-literal field resolution + multi-file cross-file decls** (landed 2026-05-24). Root cause : `decl_types` was span-keyed (`(line << 32) | column`), which collided across files in multi-file modules (e.g. `vader/vm/builder.vader::drop` at `(575, 8)` clobbered `vader/vm/exec.vader::exec` at `(575, 8)`). Fix : re-keyed `decl_types` to `MutableMap(i32, Type)` using `Symbol.id` (globally unique per `LoadedProject`). Touched ~30 read/write sites across `vader/typecheck` (decl, orchestrate, expr_ident, stmt, field, dump, call, expr_dot_variant), `vader/lower` (entry_types, lower_expr, lower_match), and `vader/comptime/check`. Impl-method types — which have no resolver Symbol — moved to a separate `impl_method_decl_types: MutableMap(i64, Type)` (still span-keyed but per-file is enough). `harvest_instances` now also walks `impl_methods` + `impl_method_decl_types` so generic instances surfacing only through impl-method signatures (e.g. `Iterator(T)` via `MapIterator implements Iterator[U]`) aren't lost. `declare_extra_file_type_decls` now calls full `declare_decl` for every kind in sibling files. `builder_roundtrip` + `peephole_rules` + the `op.PrimitiveType { .kind = "i32" }` repro all typecheck cleanly ; removed from `KNOWN_DIVERGENCES`.
- [x] **Cross-module type alias unions** — collateral win from the cross-module folder-module fix (2026-05-17). `alias_union_in_array` passes ; `namespace_alias_dedupe` still fails on a separate issue (see below).
- [x] **Project-root resolution for `import "vader/parser/ast"`** (2026-05-17) — landed via `find_manifest_root(start)` + `project_root: string | null` field on `LoadedProject` + new param on `resolve_import_path`. Walks upward from entry until it finds `vader.json`. `via_file (fn(d: Decl))` from `namespace_alias_dedupe` now typechecks correctly.
- [x] **Namespace-FieldExpr in type position (`P.Decl`)** (2026-05-17) — landed via `namespace_member_types: i32 → string → Type` on `ResolvedModule`. `prepopulate_namespace_member_types` runs BEFORE `declare_module` so fn signatures see it ; merges each namespace target's alias_types + nominal Symbol kinds (struct/enum/trait/builtin). The FieldExpr arm in `type_from_expr` now tries this first — the previous `resolved.idents[span_key(e.span)]` lookup was accidentally collision-matching the target IdentExpr's start-only key. `via_folder (fn(d: P.Decl))` in `namespace_alias_dedupe` now typechecks correctly.
- [x] **Folder-module promotion for single-file entries** (2026-05-18, commit `6fb42f4f`) — what was originally framed as a "transitive module loading" problem turned out to be a folder-module loading bug. When the CLI is invoked on a single `.vader` file (e.g. `./build/vader dump vader/lexer/lexer.vader`), `load_project` used to load that file alone, leaving sibling files in the same folder (`token.vader`, `keywords.vader`, …) unresolved → cascading R2006/T3028/T3001. `load_project` now detects "file inside multi-file folder" and promotes the load root to the parent directory ; `collect_files` merges every file's `CollectedModule` view (previously processed `files[0]` only). Lone-file folders like `stdlib/std/json.vader` keep file-as-module semantics. Wiped ~113 of the 147 errors from the 2026-05-18 audit. Three earlier attempts at transitive eager / on-demand / worklist loading are preserved below for historical record — they're no longer needed for the single-file CLI / LSP use case ; transitive load remains a separate concern for whole-project compile (currently scoped via the snippet harness).
  - **Attempt 1 (2026-05-18)** : naive worklist-based transitive load OOMs the self-host GC on the ~150-module `vader/*` source tree.
  - **Attempt 2 (2026-05-18)** : on-demand wire-time loading (`wire_module` calls `load_one` just-in-time when target absent). Also OOMs — even when only 7 mid-graph modules get loaded for a small entry like `vader/lsp/state.vader`.
  - **Attempt 3 (2026-05-18)** : BFS worklist transitive load. Works on subgraphs up to ~30 modules. OOMs on the full `vader/*` tree (~150 modules) **even with 2 GB old-generation budget**.
  - **Workaround retained from Attempt 3** : `VADER_GC_YOUNG_BYTES` / `VADER_GC_OLD_BYTES` env-vars override the compile-time default (`runtime/c/vader_runtime.c::vader_gc_env_bytes`). **Defaults bumped 2026-05-24** to 16 MB young / 64 MB old so `./build/vader dump --stage=typed-ast vader/cli/main.vader` (and every other big self-host source) works out of the box. Surfaced 4 latent self-host diagnostic divergences (namespace-alias `op.PrimitiveType` resolution) that were hidden by silent OOM ; added to `KNOWN_DIVERGENCES`.
  - **Caveat on the original audit methodology** : the "TS-side dump emits 0 errors" comparison was misleading. Running `bun src/index.ts dump --stage=typed-ast <file>` on a single stdlib file silently bails before typecheck because the resolver can't find the project root from a single-file path — TS emits an empty `# Typecheck` header and 0 diagnostics regardless of whether the code is well-formed. Future audits should drive both compilers from the snippet/parity infrastructure (which sets up the project context correctly) or run TS with an equivalent project-root resolution.
- [x] **Empty-array backwidth from first use** (2026-05-17) — `arr := []` then `arr.push(1)` retroactively types `arr` as `i32[]`. Landed via `widen_empty_array_on_push` in `call.vader::infer_call` : after each call, if callee is `arr.push(elem)`, `arr` is a Local with `?[]`, and `elem` has a concrete `expr_types` entry, patch `local_types[arr_binding_key] = T[]` in place. Matches TS's incremental in-place widening (the current call's `arr` IdentExpr stays at `?[]` ; subsequent uses see widened). No re-walk needed. Closed `array_push`.

#### Bugs surfaced by exhaustive CLI dump 2026-05-18 — closed

Audit summary : ran `./build/vader dump --stage=typed-ast` on every `.vader` file under `stdlib/` + `vader/` (118 files). Initial sweep showed 147 errors across 6 files (much was cascade noise from a single root cause). Eleven commits across the day closed the lot ; the final post-fix sweep showed 0 errors across all 118 files. Bucket ledger :

- [x] **`?` strips struct-typed Error implementers** (commit `f65283b7`) — `is_error_like` now also recognises any nominal type whose `struct_implemented_traits` bucket contains `"Error"`. Cleared 2 T3001s in `stdlib/std/json.vader::parse_array` + `parse_value`.
- [x] **`for <range>` shorthand bug in stdlib** (commit `9f4b06b3`) — `append_repeated` wrote `for 0..<count { … }` which Vader parses as a while-loop with a `Range(i32)` condition (T3019). Switched to `for _ in 0..<count`. Underlying `for <range>` sugar still tracked in §1.13e.
- [x] **Runtime GC env-vars** (commit `c4168623`) — `VADER_GC_YOUNG_BYTES` / `VADER_GC_OLD_BYTES` runtime overrides for tuning the heap without recompiling. Used during the transitive-load attempts ; retained.
- [x] **`substitute_by_name` missed `TraitType` args** (commit `2b8ddab4`) — the variant match in `field.vader` lacked an `is TraitType` arm, so a struct field of `Iterator(T)` shape kept the struct decl's `T` symbol instead of substituting to the impl's. Pattern `is Yield(T)` no longer matched the substituted scrutinee `Yield(T)`. Closed 10 of the 16 TypeParam-unification errors (every `is Yield(T)` arm in `stdlib/std/iter.vader`'s TakeIterator / FilterIterator / SkipIterator / chain / zip combinators).
- [x] **UFCS dispatch on Array → Iterator receiver** (commit `db055dc2`) — `try_curry_receiver` now mirrors TS's `rankOverloadsByFirstParam` flexibility : direct `is_assignable`, wildcard TypeParam, or trait widening (incl. the hardcoded `Array(T) → Iterator(T)`). Closed 8 errors in `stdlib/std/iter.vader` test_any/test_all/test_find/test_find_map ; regenerated `for_in_iter_trait` snapshot.
- [x] **Missing bounds on `MutableMap` accessors** (commit `b5044edb`) — `put` / `get` / `contains_key` declared `fn[K, V](...)` without `K: Hash & Equals`, so their bodies' `key.hash()` / `key.equals(...)` correctly errored T3008. Added the bounds. Both TS and Vader emit T3008/T3009 on bound-less `T.method()`.
- [x] **Lambda body doesn't push fn-ctx** (commit `f9804d0c`) — `infer_lambda` built a `FnContext` but never wrote it to `typed.current_fn_ctx`, so a `return` inside a nested `if` / `match` arm reached `check_return` via the recursive `check_expr_fn` path with `ctx=null` and fell back to the *enclosing* fn's return type. A nested `fn(x: i32) -> i32 | null { if x > 0 { return x * 10 } … }` inside `fn() -> void` reported "expected void, got i32" against the outer fn. Mirrors `check_fn_body`.
- [x] **Cross-module decl_types span-keyed collision** (commit `815c1b9f`) — `lookup_decl` consulted the entry's `decl_types` first, falling back to `external_types` only when the local lookup returned Unresolved. Two top-level decls in *different* files sharing the same line:col collided : `expect_string` calling the imported `test_fail` (alias for `std/testing::fail`, defined L30:8) got `JsonNumber` back (json.vader's struct at L30:8). Fix : when `sym.module ≠ entry's module`, go straight to `external_types`. Cleared 4 T3007s in `stdlib/std/json.vader`. Proper fix is rekeying `decl_types` from span-string to Symbol.id (mirroring the `expr_types` flip) ; the file-match gate is a single-edit workaround.
- [x] **`struct_implemented_traits` pre-pass across all impls** (commit `f98af266`) — `walk_bodies` recorded each impl's metadata and walked its body in the same per-impl iteration. An impl earlier in source order whose body returned a struct declared to implement a trait later in the file lost trait-widening. Concrete case : `MutableMap implements Into(Iterator(Entry(K,V)))`'s `into` body returned `MapIterator`, which only got registered ~6 lines later. Added a tiny pre-pass that seeds `struct_implemented_traits` for every impl before any body-checking starts. Closed 2 T3020s.
- [x] **Skip body-walk for materialized default-method clones** (commit `cded9837`) — trait default methods are cloned into every impl by `materialize_default_members`, preserving the trait source's spans (`std/core.vader:138` for `Iterator.is_empty`). Re-typechecking the clone in the impl context emitted duplicate diagnostics at unhelpful spans for a body the trait itself already validated. Added a `materialized: bool` flag on `FnDecl`, set true in `synth_with_body` / `synth_signature`, early-exit in `walk_fn_body`. Closed 2 T3013s in `collections.vader` and cleaned ~80 dead dump entries out of 5 snapshots (custom_iter, custom_iter_generic, iter_defaults, op_overload_eq_ord, trait_dispatch_generic_iter, namespace_alias_dedupe).
- [x] **Single-file entry inside multi-file folder loads the whole module** (commit `6fb42f4f`) — `vader/lexer/lexer.vader` typechecked in isolation didn't see `make_token` (`token.vader`), `lookup_keyword` (`keywords.vader`), `new_builder` (`dump.vader`) as in-module references → R2006 cascade → ~96 cascading T3028 / T3001 / T3020 / T3034. `load_project` now detects single-file inside multi-`.vader` folder and promotes to folder-module ; `collect_files` walks every file (was `files[0]` only). Cleared 103 errors on `vader/lexer/lexer.vader` alone. Regenerated `namespace_alias_dedupe` typecheck snapshot.

### 2.6b Self-host perf — pistes restantes (post-2026-05-22)

Four perf landings in the 2026-05-22 session brought the typecheck-port
bootstrap from "unusable" (eval_types.vader OOM, 9/17 broad-parity modules
timeout) to working in 3.2 s for the full broad-parity suite. Remaining
pistes, ranked by likely payoff. **Reprofile first** (`/tmp/vader_perf`
with -O2 -g + `sample`) — the hot path has moved several times already.

#### Runtime GC

- [ ] **Specialized pointer sort in `vader_string_prepare_marks`** —
      `runtime/c/vader_runtime.c:753-769` calls libc `qsort` on the
      sorted-string-headers array. After the throttle landed in
      `3b983d97`, the post-throttle profile still shows ~5-10 % of
      total runtime in `qsort` (`_qsort` in `libsystem_c.dylib`).
      A specialized introsort/heapsort over `uintptr_t` (no
      function-pointer indirection) would beat qsort 2-3× on this
      workload. Localised change, no API impact.
- [ ] **Tune `VADER_STRING_SWEEP_MINOR_INTERVAL`** — currently `8`
      (`runtime/c/vader_runtime.c:242`). Try `16` / `32` against
      `RUN_BROAD_PARITY=1` ; higher values defer sweeps further but
      let the adaptive `g_string_gc_threshold` trigger fire sooner.
      May be a net win if mark cost is now low.
- [ ] **Array `pop` intrinsic** — see §1.11.
- [ ] **GC arenas don't grow — hard OOM ceiling on large inputs**
      (2026-06-04). The Cheney collector (`runtime/c/vader_runtime.c:878`)
      allocates fixed semi-spaces (`VADER_GC_YOUNG_BYTES` 32 MB,
      `VADER_GC_OLD_BYTES` 256 MB) and on overflow does
      minor → major → **trap** (`:906`), never growing. Self-compiling
      `vader/cli/main.vader` has a ~252 MB live set, so the default
      256 MB old arena OOMs on *every* platform — it only "works" when
      the env knobs are raised (`VADER_GC_OLD_BYTES=$((1024*1024*1024))`,
      per SPEC §9). Surfaced as a hard blocker on Windows (native `.exe`,
      no env var set ; not a platform bug — macOS native OOMs identically
      at the default). Proper fix : grow the semi-spaces (realloc /
      mmap-backed) so the heap adapts to input size instead of trapping
      at a compile-time constant. Stopgap : raise the default old arena.
      See §1.11.
- [ ] **Shrink the self-compile live set** (2026-06-04). At OOM,
      `VADER_GC_PROFILE=1` shows the ~252 MB live set dominated by
      `MutableMap` entries — `Entry<Any, Any>` : 1.25 M live × 72 B =
      90 MB — plus 451 k array/map backing buffers (61 MB), the rest
      compiler IR (CFG / symbols / type caches). These are interning /
      symbol-table / monomorphization caches held live across the whole
      compile. Investigate tearing per-pass / per-module caches down
      earlier (or whether something over-retains). Ties into the
      compiler-memory-profile work (CFG-analysis churn).

#### Lower

- [ ] **Replace `span_key`'s string interpolation with an i64 key**
      (`vader/lower/entry_types.vader:127`). Every lookup against
      `idents` / `expr_types` / `local_types` / `narrowed_bindings`
      / the new `local_symbol_indices` / etc. mints a fresh
      `"${line}:${column}"` string. Profile-confirmed hot allocator
      site. Encode as `(line << 32) | column` ; flip every
      `MutableMap(string, …)` keyed by span to `MutableMap(i64, …)`.
      Touch points : every typecheck / lower / comptime side-table.
      Invasive but the alloc reduction would cascade into less GC
      pressure across the whole pipeline.
- [ ] **Pre-allocate `stmts: LoweredStmt[]` in `lower_block`**
      (`vader/lower/lower_expr.vader:1929`). The `[] = []` + repeated
      `out.push` pattern grows by doubling, causing log-N realloc
      copies per block. Knowing `block.stmts.len()` upfront lets the
      caller reserve capacity. Requires either a stdlib `with_capacity`
      helper or a runtime intrinsic — same surface as the `pop` note
      in §1.11. ~187 sites in the lower/typecheck use the
      `T[] = []` shape ; this one fires per-block.
- [ ] **Reprofile after these land** — the d467d5b1 lookup_local_symbol
      fix cut 49 % off `orchestrate.vader` lowered-ast on its own.
      Each fix shifts the next hot path, so the order matters less
      than re-sampling between rounds.

#### Typecheck

- [ ] **Scope-down `settle_external_expr_bodied_returns`** — already
      listed in §2.6 follow-ups but quoted here for cross-reference :
      `vader/typecheck/orchestrate.vader:695-707` walks every non-entry
      module's bodies even when none have expr-bodied fns. Limit to
      modules where `has_expr_bodied_fn` returns true. Profile-side
      this hasn't shown up as dominant (the lowered-ast path was way
      lower-bound), but the savings stack with the lower perf chantier.

#### Algorithmic / data-structure

- [ ] **MutableMap small-map specialisation** — `std/collections.vader`
      uses chained HashMap with fixed bucket count. For the many
      maps that hold < 8 entries (per-module symbol caches, narrowing
      bindings, …) the bucket array + chain is overkill. A "small
      map" inline-array variant (linear scan up to N entries before
      switching to buckets) cuts allocation count.
- [ ] **String interning for hot identifiers** — names like
      `"self"`, `"Iterator"`, `"next"`, `"to_string"` are repeatedly
      compared / allocated. An interning table would replace string
      equality with identity comparison and drop the per-mention
      alloc. Surface : `vader/resolver/symbol.vader` for the canonical
      home ; consumers in lower / typecheck switch to comparing
      interned ids.

### 2.7 Bootstrap success check
- [ ] Compile Vader compiler with TS compiler → `compiler_v1`.
- [ ] Compile Vader compiler with `compiler_v1` → `compiler_v2`.
- [ ] Verify identical outputs.
- [ ] Verify idempotence : `compiler_v2 == compiler_v3`.

### 2.8 Freeze the TS compiler
- [ ] Tag final TS compiler release, move to `archive/`, write `BOOTSTRAP.md`.

---

## Phase 3 — Post-MVP

### 3.1 Concurrency
- [ ] `async` / `await` keywords + state-machine lowering.
- [ ] Cooperative scheduler in the runtime (single-threaded).
- [ ] (Stretch) Kotlin-style coroutines.

### 3.2 Native threads
- [ ] `std/thread` — `spawn`, `join`, atomics, channels.
- [ ] Compile-time error if imported on the WASM target.

### 3.3 Networking & web
- [ ] `std/net` — TCP, UDP, HTTP client.
- [ ] WASI target support.
- [ ] Auto string marshalling between Vader and JS.
- [ ] Browser-side runtime helpers (small JS package).

### 3.4 Stdlib expansion
> Shipped: `std/regex`, `std/time`, `std/random`, `std/crypto`, `std/base64`.
- [ ] **`std/json` v2 — compile-time-generated parsers** (kotlinx-serialization style) via `@derive(Json)`. Requires `@derive` machinery (§3.8).
- [ ] **`std/bignum` — `BigInteger` / `BigDecimal`** — arbitrary precision. Use cases : JSON parsing without precision loss past 2^53, money/financial DSLs, crypto bignums. Pure Vader ~600-1000 LoC each. BigInteger first.

### 3.5 Performance
> Shipped: generational GC + card table, GC robustness under string-alloc / array-doubling pressure, whole-program DCE, `match enum → switch` static lookup tables, peephole temp-elimination, hash-cons `Type` + WeakMap registries, iterator-chain fusion, inline small tagged unions, inline `MutableMap`/`MutableSet` for-in.
- [ ] Direct-ASM backend for one native target (validate the design).
- [ ] Escape analysis enabled (lower allocations on stack when proven safe).
- [ ] **Bytecode cache on disk** — to discuss / dimension. Today every `vader run` / `vader fmt` / `vader-lsp` re-parses + typechecks + lowers the full stdlib (~30 modules) before the VM executes a single instruction (~2-3 s for the formatter). Proposal : serialise per-module `LoweredModule` to a `.vbc` sidecar keyed by `(source_hash, compiler_version)`. Open questions : (a) serialisation format (binary vs MessagePack vs IR text), (b) cache invalidation across transitive deps (changing `std/core` busts every consumer), (c) interaction with `--target=native` C-emit, (d) interaction with comptime values (memoise too?). Stay VM-only for now — AOT is deliberately out of scope.
- [ ] **Lazy-materialise stack values in C-emit** (companion to DCE). Today's wins target primitives ; `local.get`/`local.tee` of ref/any still snapshot eagerly into a refTmp for GC-precision. Future : (1) detect call-arg pairs with no allocation, (2) skip explicit zero-init for primitives, (3) pre-declare blockres slots on first use. Each ~½ day.
- [ ] **Value-type structs (`CodeInfo`-style)** — open discussion. Today every struct is heap-allocated + boxed. For small immutable structs never trait-boxed (e.g. `CodeInfo { id: string, message: string }`), a register-by-value pass would be free. Trade-offs : (a) syntactic distinction (`value struct` keyword? `@value` decorator? auto-detect?) ; (b) interaction with `is Trait` (value-types can't downcast — compile error?) ; (c) match patterns binding by reference ; (d) multi-register return ABI ; (e) escape analysis as a downgrade path. Decision needed before implementation.
- [ ] **Inline trivial trait-method impls before bytecode emit** (deferred 2026-05-14). Methods like `i32.gt :: fn(a, b) -> bool { return a > b }` and one-arm vtable dispatchers emit a `Call` op each ; clang `-O3` inlines them in native, the VM doesn't. Plan : classify inlinable `LoweredFnDecl`s (single `LoweredReturn` of a pure expression, ≤ N midir ops, no recursion) + midir pass that replaces `Call(callee=inlinable)` with the substituted body + `pruneUnreachable` drops dead callees. **Why deferred** : current bench workloads (mandelbrot, primes) have no fn calls in hot paths ; VM bottleneck is parse + typecheck + lower (3.5+ s per invocation), not exec. Revisit when (a) bytecode-cache lands and (b) a bench workload shows fn-call density as a hot spot. ~1 day.
- [ ] **Open-addressed hash table for `MutableMap`** — **disqualified by bench, 2026-05-16**. 4 attempts, 5 compiler bugs surfaced + all fixed (commits `12a8de68`, `9489305d`, `4d43ecb2`, `52164253`, `28947e27`) : dedup struct/trait types by source position, cross-module ident resolution, cross-module typed-program swap for foreign sub-trees, FreeInt source pinning to cast target width, struct-instance subst threaded through foreign defaults. Robin Hood impl works end-to-end (VM + native, all tests green). **Bench result : map_iter regressed +59 % (36 ms vs 22.6 ms baseline)** — Vader's array runtime stores struct elements as heap-allocated `vader_box_t` pointers, so Robin Hood's main perf advantage (cache-friendly inline storage) is not realised. Iteration cost dominates : scan 2048-slot flat array (~25 % empty) vs walk 16 chained buckets that touch only filled entries. Reverted. **To make this worth shipping** : (a) inline-stored struct arrays at the runtime level (large c-emit + GC scan change), OR (b) the workload mix shifts toward lookup-heavy. Filed under "design constraint" rather than "follow-up" — the chaining design is the right call for the current runtime.
- [ ] **Self-host typecheck working-set reduction** (profiled 2026-05-25). `VADER_GC_PROFILE=1 ./build/vader dump --stage=typed-ast vader/cli/main.vader` over the full self-host project (170+ modules transitively imported) reports an **81 MB live set** dominated by :
  - `vader_diagnostics_Position` (48 B × 345k = **16.5 MB**) — 16 B header + 16 B `file: string` + 16 B (offset / line / column).
  - `vader_diagnostics_Span` (64 B × 240k = **15.4 MB**) — each holds two `Position` refs.
  - `ARRAY_BUF` (15.4 MB) — variable-sized array storage.
  - `std_collections_Entry(Any, Any)` (72 B × 132k = **9.5 MB**) — sum of every `MutableMap` entry across `TypedProgram` side-tables, `ResolvedModule` maps, and comptime/lower internal tables. After erasure-dedupe (`b528d2bc`, `b85f1ce5`) all `MutableMap(K, V).Entry` variants collapse to a single C type at codegen, so every map entry shows up under one index. The count is real data, not erasure-dedupe overshoot.

  Two parallel work-streams to reclaim memory :

  **(I) String interning via `Atom` type — ~13 MB.** Full plan in [`docs/ATOM_INTERNING.md`](./docs/ATOM_INTERNING.md). Introduces `Atom = u32` + project-wide `AtomTable` ; replaces high-cardinality `string` fields (`Position.file`, `Token.text`, `IdentExpr.name`, `FieldExpr.name`, decl names, `Symbol.name`) with a 4 B atom index. O(1) equality + hash on names as a side benefit. 5 phases (plumbing → FileId → Token/Ident/Field → decl + Symbol → cleanup), 5-7 days total. Phase-by-phase mergeable.

  **(II) `MutableMap` entry footprint — ~5 MB.** Three orthogonal pistes :
  - **(a) Flat `Type[]` for dense int-keyed maps** — `decl_types : MutableMap(i32, Type)` is keyed by `Symbol.id`, minted sequentially → quasi-dense. Replace with `Type[]` indexed by id : ~17k symbols × 8 B ref slot = ~136 KB vs 17k entries × 72 B = ~1.2 MB. Saves ~1 MB and turns the lookup into O(1) array-get (no hash). Most-consulted side-table per resolve, so latency win on top of memory. Applies similarly to `struct_decls`, `trait_decls` (also `Symbol.id`-keyed). Touches `vader/typecheck/typed_ast.vader` + every reader. ~½ day.
  - **(b) Fuse the three `Type`-by-int side-tables** — `expr_types: MutableMap(usize, Type)`, `local_types: MutableMap(i64, Type)`, `type_expr_types: MutableMap(i64, Type)` all store `Type` keyed by a numeric id. One `MutableMap(i64, Type)` with the discriminator packed into the key (top 2 bits = source family) halves the bucket count and the Entry allocations. Estimated ~3 MB saved if these three account for ~half the 132k entries. Touches all callers ; needs an accessor layer to keep the readers explicit about which family they're querying. ~1 day.
  - **(c) Specialised `IntMap(V)` stdlib type** — `MutableMap` keys go through `key: Any`, paying 16 B per entry even when the source type is `i32` / `i64` / `usize`. An `IntMap(V) :: struct[V]` storing `key: i64` raw (8 B) saves 8 B × ~80k int-keyed entries = ~640 KB. New stdlib struct in `stdlib/std/collections/`. ~1 day including tests.

  **(III) Flatten `Position` into `Span` — ~16 MB (subsumes part of (I)).** Open architectural choice. Span becomes `{ file_id, start_offset, start_line, start_col, end_offset, end_line, end_col }` inlined ; kills the 345k Position heap allocs entirely (their headers alone are 5.5 MB). Larger refactor — touches every span-construction site across the parser, typecheck, lower, diagnostics. Synergy with (I) Phase 1 : do them together once Atom is in place. To document if pursued.
- [ ] **Native build wall-time — `cc` dominates** (measured 2026-05-19). Self-host CLI : Vader→C emit **2.3 s** ; then sequential `cc` on `build/vader.c` (39 MB / ~400 k LoC TU) : `-O0 -ggdb` **30.6 s** / `-O1` 169 s / `-O2` **161 s** / `-O3` **161.6 s** ; Homebrew clang 22 `-O3` 156 s ; zig cc 0.16.0 `-O3` **204 s** (+26 % vs Apple clang, same bundled LLVM but cross-platform sysroot adds per-TU overhead) ; gcc-15 `-O3` > 200 s (interrupted). Two non-levers confirmed : (1) **changing compiler family doesn't help** — Apple clang / Homebrew clang within 3 %, zig cc / gcc-15 slower ; (2) **dropping `-O3` → `-O2` is a wash** — both ~161 s, `-O1` is even *worse* (169 s). On a 400 k-LoC TU the structural passes (parsing, mem2reg, SROA, simplifycfg) dominate ; the inliner-heavy `-O3`-only passes add < 1 %. Root cause is structural : 1 monolithic TU, 1 732 static fns, 714 structs, heavy generic monomorphisation (62× `ArrayIterator<T>`, 63× `Yield<T>`, 45× `MutableMap<K,V>` / 45× `Entry<K,V>`, 82× `MutableMap.put` / `ensure_buckets` / `set_at`). One TU → no `cc` parallelism. Levers, by expected gain (arbitrate at pick-up time) :
  - **(a) Split C emission per Vader module + drive `cc -j`** — unlocks parallelism and `ccache` for iterative rebuilds. Biggest expected win. Touches `src/c_emit/emit.ts` + `src/cli/commands/build.ts` (N `cc` calls + final link).
  - **(b) Pre-compile stdlib monomorphisations to `.o`** — once-per-toolchain artefact cached on disk ; user-CLI rebuilds only re-cc user TUs. Depends on (a) for the TU split.
  - **(c) Type-erase non-perf-critical generic containers** — **paused 2026-05-19 via option (Φ)**, see `docs/STDLIB_GENERIC_COLLAPSE.md` Decision log. Shipped sub-deliverables : Phase 0 (`4f639e99`) vtable runtime + slot registry + internal `Any` Type kind ; Phase 1 (`0d9ebc80`) packed inline-box multi-field POD ≤ 16 B ; β raw-array for-in fix (`aa2dc5ce`) ; Phase 2 plumbing (`9b38e860`, `ef76fe6f`) committed but gated off. Phase 2 §9 documents 9 cascade issues encountered ; the cascade is fundamental (Any-bearing queries against `@specialize`d types' concrete-arg registries), so full automatic erasure deferred to a future investigation with a different design (option (γ) "synthesise Any-bearing instances for every `@specialize`d reachable type" estimated 3-5 d, worth pursuing only when cc -O3 baseline becomes a workflow blocker). Iterator-skip `@specialize` decorator landed in the same arc.
  - **(d) `__attribute__((cold))` on rarely-hit generated fns** — calms the inliner / frees IPSCCP budget. Candidates : error paths, diagnostic builders, init-only helpers. Touches `src/c_emit/emit.ts`. Smallest expected win — measure on a smaller TU first since the structural-pass dominance pattern caps the ceiling.

### 3.6 Memory model extensions
- [ ] Explicit allocator API (arenas, pools) for perf-critical paths.
- [ ] `unsafe { }` blocks for low-level FFI.

### 3.7 Tooling
- [ ] LSP server (in Vader) — diagnostics, hover, go-to-def, completion.
- [ ] **LSP : revisit hover signatures once the typechecker is self-host.** Today the indexer is AST-only ; hover on local bindings falls back to source slice + literal-suffix heuristics. When the typechecker lands in Vader (§2.6), consult its inferred-type table directly for proper `name: T` rendering. Same upgrade fixes param hover under generics + match-arm pattern bindings.
- [~] **LSP : inlay hints for inferred types** (LSP 3.17 `textDocument/inlayHint`). Landed in `vader/lsp/inlay_hint.vader` (steps 1-3 from the original plan : capability advertised, request routed, types pulled from `typed.local_types[span_key(sb.name_span)]` and `typed.decl_types[sym.id]`, defaulting + UnresolvedType / FreeInt / FreeFloat / TypeMeta filters in place). **Open bug (2026-05-26)** : on `stdlib/std/semver/semver.vader::parse` (and likely any large fn body), VS Code agglutinates every fn-body hint into a single visual cluster at one line instead of laying them out per-binding. Suspect either (a) `name_span.end.line` is identical across many `SimpleBinding`s — bug in the parser's span tracking for grouped lets, (b) `collect_from_stmt` runs more than once per binding, or (c) the position-calculation `sb.name_span.end.column + 1` is wrong for the actual one-space `name :: …` layout and crowds them onto a single column. Repro : open `stdlib/std/semver/semver.vader` in VS Code with the Vader extension active ; scroll to line 110-145 ; observe the cluster `u8 usize string string string i32[] usize string Er…` glued to the front of line 111. Investigation needed before declaring this closed.
- [ ] VS Code extension.
- [ ] **`vader doctor --json`** — environment + toolchain sanity check emitting a structured report : `bun` / `cc` / stdlib paths discoverable, `runtime/c/` present, `vader.json` schema valid, GC env-vars in range, comptime cache writable. Two output modes : human-readable text (default) and `--json` for agent / CI consumption. Lives in `vader/cli/doctor.vader`. Cheap to ship and pays for itself the first time a fresh clone fails opaquely.
- [ ] **Structured `repair.id` field on diagnostics** — every entry in `vader/diagnostics/codes.vader` gains an optional `repair: { id: string, ... }` describing a deterministic fix that an LSP code-action or an LLM can apply. Examples : `R2003 unknown identifier → repair.id = "declare-missing-symbol"`, `T3007 missing field → repair.id = "add-field-default"`, `T3019 wrong arity → repair.id = "insert-trailing-arg"`. Surface in both `--diagnostics=json` output and `textDocument/codeAction` LSP responses. Start with the 5-10 highest-frequency codes ; the repair *implementation* can land later — the *contract* is the value. Cross-ref §1.0.
- [ ] **LSP code actions framework** — general refactoring infrastructure on top of the LSP. Components : `codeActionProvider` capability in `vader/lsp/lifecycle.vader` ; new `vader/lsp/expr_at.vader` position → `Expr` walker ; `vader/lsp/code_actions.vader` registry of `{ kind, title, is_applicable, apply }` records ; expose `emit_expr(e: Expr) -> string` out of `vader/fmt/printer.vader`. First three actions : `match → if` (≤ 2 arms reducible to booleans), `if-chain → match` (≥ 3 branches on same scrutinee), null-narrow rewrite. Reuses the same scaffolding for future refactorings (extract-fn, inline-let, rename). Design + open architectural questions captured in [`docs/LSP_CODE_ACTIONS.md`](./docs/LSP_CODE_ACTIONS.md). Deferred until self-host MVP closes ; cross-ref the `repair.id` entry above for the diagnostic-driven companion.
- [ ] Programmable build API (`build.vader` instead of `vader.json`).
- [ ] **Multi-library namespaces** — `STDLIB_PATH_PREFIX = "std/"` is hard-coded today. Generalise to a registry of `prefix → on-disk root` fed by `vader.json` (e.g. `{ "libraries": { "web": "./vendor/vader-web", "experimental": "./libs/exp" } }`). Use cases : (a) third-party libs via a package manager, (b) compiler-private namespace (`internal/`) with a "stdlib + compiler only" rule, (c) workspace monorepos. Touches `resolveImportPath`, `isStdlibModule`, DCE filter, dump-stage filters. ~150 lines + manifest schema bump.
- [ ] External package manager + central registry (much later).
- [ ] `man` page for `vader`.
- [ ] **GitHub Release on tag push** — attach `dist/vader-*.tar.gz` and `dist/vader-*.zip` to a release on `v*` tag push (`softprops/action-gh-release` or `gh release create`). `permissions: contents: write`. Auto-generate notes from commit log between tags.
- [ ] **GitHub Actions matrix per OS** (post self-host) — fan out to `ubuntu`/`macos`/`windows` runners that each run `bun test` on their native binary and assemble locally.

### 3.8 Language ergonomics
> Shipped: UFCS on union receivers, cross-module type-alias unions, codepoint-first `string` model + non-owning array slice views, literal-value match patterns, `enum`→int cast, implicit `void` return, auto-`.iter()` for-in, trait-object boxing + dynamic dispatch, operator overloading via traits, `Into[Target]` auto-coerce, expression-bodied fns, struct spread / field defaults, tuples + destructuring, comptime tuple/struct/array values, spread destructuring, `std/process.spawn`, inline `@file`, implicit selector expressions, `@assert` / `@partial` / `@deprecated`.
- [ ] **`defer` unwinds on panic** (gap surfaced 2026-05-19) — today defers are lowered as straight-line statements at `return` / `break` / `continue` exits (`src/lower/passes/block.ts:188-202`) ; a runtime panic (uncaught error, OOB, null deref) throws `VmError` directly (`src/vm/exec.ts:35`) and **skips every pending defer in the current frame and frames above**. Files left open, locks held, transactions dangling. Fix : (a) emit defers into a per-frame defer-list opcode (`DEFER_PUSH` / `DEFER_POP`) instead of inlining them, OR keep the inline form but maintain a parallel runtime stack tracked at frame entry ; (b) on panic, walk frames bottom-up and run each frame's pending defers before propagating ; (c) mirror in the C-emit (longjmp-based unwind or sentinel-checked epilogue). Same fix unlocks a future `recover` / `rescue` primitive. Cross-ref §3.1 Concurrency (panic propagation across spawned tasks).
- [ ] Static-size arrays `[T; N]`.
- [ ] Pattern matching extensions — or-patterns (`'a' | 'b'`), range-patterns (`'a'..='z'`).
- [ ] `@derive(Eq, Display)` to auto-generate trivial impls.
- [ ] **Function overloading by full signature** (post-MVP elevation of receiver-only overloading) — pick the candidate whose *all* parameter types match. Generalises the resolver's overload table + typechecker's call resolution.

### 3.9 Companion projects
> Shipped: Brainfuck compiler in Vader (`examples/brainfuck.vader`), targeting the Vader VM + native. BF `,` not wired.

### 3.10 WASM target

Moved out of MVP (was §1.10). C backend already covers native deployment.

- [ ] Bytecode → WASM binary (minimal wasm encoder or vendor binaryen-js).
- [ ] WASM GC types for structs + arrays.
- [ ] Imports/exports via `@extern` / `@export`.
- [ ] DWARF emission.
- [ ] Tests : emit + run with wasmtime `--wasm=gc` + compare stdout to VM snapshot.
- [ ] CLI : `vader build --target=wasm` + `vader dump --stage=wasm`.
- [ ] **Decide `usize` width** : WASM64 only vs supporting WASM32 (`usize → i32`). Affects the C-emit too if one binary should share logic.
- [ ] **`examples/wasm_browser/`** — minimal HTML + Vader calling JS via `@extern`. End-to-end smoke test.
- [ ] **Slot-typed numeric promotion verifier** — debug-only ; enforces op/slot agreement before emission (cf. §1.8 note).

---

## Reference

- `SPEC.md` — language specification (target reference)
- `examples/` — working programs
- `stdlib/` — standard library source (Vader)
- `src/` — TypeScript compiler
- `tests/` — snapshot tests
- `docs/IMPROVEMENT.md` — review-driven improvement plan (2026-05-11)
