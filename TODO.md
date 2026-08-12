# Vader — TODO

Implementation roadmap for the Vader compiler and standard library, derived from `SPEC.md`:

- **Phase 1** — MVP compiler in TypeScript, plus stdlib in Vader.
- **Phase 2** — Self-hosting (port the compiler to Vader).
- **Phase 3** — Post-MVP language features and tooling.

Completed items (`[x]`) are kept as one-liners — see git history for implementation notes, commit hashes, migration steps. Open (`[ ]`) and in-progress (`[~]`) items keep the full context needed to act on them.

**Completed work — Phase 0, the done Phase 1 subsections, and the long-form detail of finished "Priority" items — lives in [`docs/HISTORY.md`](./docs/HISTORY.md).** This file tracks open + in-progress work only.

---

## Priority — next up

- [ ] **`T[]` should satisfy a `[C: Index]` / `[C: IndexSet]` bound — DEFERRED, a dynamic-dispatch feature, not a perf one** (revisited 2026-07-20). Direct `arr[i]` / `arr[i] = v` lower to the built-in fast op (concrete `ArrayGet`/`ArraySet`, 0 alloc) and STAY that way regardless of this item — nothing here touches the array fast path. The only thing an array-`Index` impl adds is letting an array satisfy a **generic** `[C: Index]` bound; since generics are erased (.NET model), that path is *inherently* a runtime vtable dispatch (slow, rare) — not something the fast array machinery can be "moved into". Prereq **(1) — SHIPPED** (`272af6472`, snippet `generic_index_dispatch`): the index OPERATOR `c[0]` / `c[0] = v` now dispatches through a `TypeParam` `Index`/`IndexSet` bound for user **struct** implementors (`infer_index` / `check_assign` record `bounded_dispatch_trait`; `lower_index` / `lower_assign` emit a vcall). Remaining blockers, both on the **erased array receiver** (found 2026-07-20, `@intrinsic T[] implements Index/IndexSet` attempted + fully reverted): **(a) vtable key** — a concrete `i32[]` carries its element-specific type id (header `type_index`, e.g. 2) but the single materialised row is keyed on the erased `Any[]` (e.g. 8), so both the VM (`receiver_type_id_of` → `a.type_id`) and native (`switch(recv.tag)`) miss; **(b) erased primitive read/write** — the erased body emits `array.get <ref>`, whose native path (`vader_array_ref_load_box`) only handles `element_kind ∈ {REF, BOXED}`, NOT a primitive-packed buffer (`i32[]` = 4-byte slots) → would read a 24-byte box from a 4-byte slot (the VM escapes via uniform boxing). Two design options if ever needed: **A. full erasure** — extend the runtime ref-load/store helpers to box/unbox primitive elements via `element_kind` + `element_tag`, and expand the one erased row over every array type in the table (generalises to any `T[] implements Trait` virtual dispatch); **B. per-element monomorphisation** — materialise concrete `at__<elem>` / `set_at__<elem>` keyed on the concrete array type (fast reads, no runtime change, more plumbing to track which element types reach the bound). Defer until there's a real caller passing an array to a `[C: Index]` generic.

- [x] **`for x in self` over an abstract `Iterator<T>` typed the loop var `?`, not `T`** (found 2026-07-24, fixed 2026-08-13). Inside a generic combinator's own body — `my_map :: fn<T, U>(self: Iterator<T>, …) { for x in self { … } }` — every loop variable recorded as `?`, visible in `tests/snippets/fuse_generator_chain/typecheck.snapshot` and in LSP hover. Now `T`.

  **The 2026-07-24 write-up had the cause wrong on both halves, which is why it looked unfixable.** `for_in_element` did NOT lack a `TraitType` arm — the arm was there, and deliberately returned `TY_UNRESOLVED` for any type-param-bearing element. And the blocker was never "generator-state materialisation under erasure": it was one line further downstream, in the LOWERER. `local_types` is keyed by SPAN, so a generic combinator's loop var has exactly ONE entry, shared by every instance lowered from that body — it can only ever hold the declared `T`. Both readers took it RAW: `lower_for_in.vader::resolve_element_type` and `lower_iter_fusion.vader::fused_loop_element_type`. So the moment the typer told the truth, `T` flowed into `find_core_type("Yield", [T])` and midir went looking for `value` on a `Yield<T>` no instance ever materialised. The typer's guard was compensating for that, at the cost of a type that lies.

  `FnLowerCtx` already carries the fix: `ctx.types` is an `EntryTypes` view whose stated contract is "substitution applied at every read — lower passes consume this instead of reaching into `typed` / `subst` directly". Both sites were bypassing it. The rule now lives once, as `entry_types.vader::concrete_local_type`: read the span-keyed slot, apply the entry's substitution, and answer **null** for the three cases a caller must handle itself (no entry, an unresolved slot, a param that outlived the substitution — i.e. a body lowered generically rather than as an instance). Each caller keeps its own fallback: the iterator type for the un-fused path, the fused chain element for the fused one. The typer's arm is now a one-liner returning the element as written.

  **Measured, not assumed.** 22 snapshots moved, every one of them a type that stopped lying: 69 `?` became `i32` / `Any` / `T` / `char` / `string`, plus 3 `ref.cast` where the concrete type is now known. Not one `vm.snapshot` moved — all 18 affected snippets produce byte-identical output — and the bytecode sizes stayed put (`iter_zip_chain` 1290 → 1289 lines), which is the opposite of the ~1300-line collapse the old note reported as the failure signature. `iter_zip_chain`'s C got strictly better: it was emitting TWO tuple types for one `[i32, string]` — one with `f__1` scanned as a generic pointer because the element was `?`, one concrete — and they now dedup to a single row, taking the type-info table from 28 entries to 26. Covered by four colocated tests on `concrete_local_type`.

- [ ] **`is` on a width-mixed integer union narrows wrong (both backends, divergent) — PARKED** (found 2026-07-16). For `x: i32 | i64 | u8`, the VM matches the first `is <intType>` for any integer (`1 1 1`) and native never matches `is u8` (`3 2 3`); neither is `1 2 3`. Integer analog of the f32-union `is` fix (`e29891685`). Design question: reject width-mixed integer unions at the typer, alias all widths for `is` (as f32≡f64), or carry precise primitive box tags. Repro: `tests/snippets/int_width_union_is/` (documented, not in the parity allowlist — kept green while parked). Deprioritized behind the narrow-int truncation bug above.


- [ ] **Allocation-use analysis → stack-alloc / interning / value-structs** (escape analysis, broadened 2026-06-20). One whole-program dataflow over midir (`vader/midir/`) computes, per allocation site / per type, *how the value is used*: does it **escape** its creating fn (return / store-to-heap / capture), is it **mutated** after construction (a `struct.set` scan — the lowered IR makes this a direct walk), is it **compared by reference identity**. Those facts feed THREE complementary GC-pressure optimisations, each attacking a different slice of the self-compile memory profile (the two halves measured by `bun run bench:profile`: ~986 MB GC-copied / 32 cycles of **churn** + ~512 MB **retained** live-set, ARRAY_BUF/`MutableMap`-dominated):
  - **Stack-allocation** — allocations that provably don't escape go on the stack (or are freed eagerly) instead of the Cheney arena. Attacks the **churn** half (short-lived CFG-node / temp traffic). Caveat: a stack slot must not be a GC root the moving collector tries to relocate.
  - **Interning (hash-consing)** — immutable, duplicated, long-lived values are deduplicated to one shared instance. Attacks the **retained** half (Type IR, `Symbol`, `BcType`, `MutableMap` entries held across passes) — note this is the INVERSE class to stack-alloc: the escaping, long-lived values stack-alloc can't touch are exactly interning's target. **Vader soundness condition**: `==` on a struct without an `Equals` impl is *reference identity* (SPEC §"Memory Model"), so interning is sound only for a type that is immutable AND never identity-compared (has `Equals`, or is never `==`-ed — e.g. `PrimitiveType`, compared via `equals_type`/`canonical_key`, qualifies). Proving "never identity-compared" automatically must bail in erased generic/union contexts, so the realistic form is an opt-in **`@intern` decorator the compiler *verifies*** (immutability + Equals/no-identity-compare → error if violated) then generates the content-keyed construction — the Rust `Ty` / LLVM type-uniquing / GHC model (always annotated, never auto-derived, for exactly this reason). Profitability caveat: intern only bounded-value-set types (few distinct values), else the intern table itself retains everything → a leak.
  - **Value-type structs** — small immutable never-trait-boxed structs passed by register instead of heap-boxed. Shares the same immutability fact; see the §3.5 "Value-type structs" item for its open trade-offs (`@value` vs auto-detect, `is Trait` interaction, multi-register ABI).
  The first concrete interning win — `mk_primitive` singletons (`vader/types/types.vader`, 17 primitive names incl. `null`) — is a safe MANUAL instance (never `==`-compared, 17 bounded values); doing it generically is this chantier. **When generic `@intern` lands, REVERT that manual interning**: replace the hand-rolled `mk_primitive` singleton table with `@intern` on `PrimitiveType`, so there's one mechanism — the manual table would otherwise duplicate (and could conflict with) the generic pass's content-keyed construction. Architecture-level → explore-before-commit + review. Related §3.5 items: escape (stack-alloc), value-structs, self-host typecheck working-set.


- [~] **`vader fmt` MVP** (first pass 2026-05-11) — written in Vader under `vader/fmt/`, exercises the self-host parser end-to-end. Idempotency + parse round-trip green on the stdlib ; byte-for-byte no-op pending on three stylistic gaps : (a) `::` column alignment in decl groups, (b) per-line grouping inside multi-line imports, (c) cap at 1 blank line between decls vs the stdlib's occasional double-blank. Tests : `tests/formatter*.test.ts` (gated `RUN_FMT_TESTS=1`). Open : column alignment decision, hand-curated snapshot scenarios, growing `NO_OP_FILES`.
  - **Shipped 2026-07-18 (`fb2b10960`) — control-flow block expansion.** A statement-position `if` / `for` / `while` body always renders multi-line (no inline `if cond { return x }`) ; a run of ≥2 aligned `if <cond> { <stmt> }` (lookup table) stays inline with `{`-column alignment ; value-position `if` (`x :: if c { a } else { b }`) stays inline. `BlockLayout` enum in `printer.vader`. Wired into the LSP (`textDocument/formatting`).
  - **Blocker for a clean-tree mass-reformat — formatter over-collapses.** Running `vader fmt` on the whole tree is a ~36k-line delta today, but MOST of it is pre-existing aggressiveness UNRELATED to the block-expansion change: the formatter collapses hand-wrapped multi-line **struct literals / fn signatures / array literals** into a single line **even when that line exceeds the 100-col soft-wrap** (`MAX_LINE`). The codebase deliberately avoids `fmt` because of this. Fix : make the collapse-to-one-line paths (struct-lit, fn signature, seq-lit) *length-aware* — keep the multi-line layout when the collapsed form would exceed `MAX_LINE`. Once fixed, a whole-tree reformat becomes reviewable + the tree can be made `fmt`-clean.


- [~] **Reject private types in a public signature — return + params + exported struct fields DONE (T3052), type-alias RHS open** (`e12cde15`, params+fields 2026-07-24). `first_unexported_type` (`vader/typecheck/decl.vader`) fires **T3052** when an `export`ed fn's **return type OR any parameter type** names a non-`export`ed type (`check_public_fn_visibility`), and when a **public field of an exported struct** exposes one (`report_private_leak`, called from the `StructDecl` arm — an `@internal` field opts out). A single T3052 with a context-specific message ("returns" / "takes a parameter of type" / "exposes a field of type"). Fixtures: `tests/diag_corpus/typecheck/t3052_private_type_in_public_{return,param,field}/`. Real leaks the field check surfaced and fixed in the same landing: `Printer.block_mode` / `LowerProjectCtx.generic_collected` / `FunctionBuilder.scopes`+`pending` → `@internal` (internal state), `std/regex::InstClass.ranges` → export `CharRange` (public semantic content), `std/semver::VersionRange.clauses` → `@internal` (RangeClause deliberately private). **Remaining call sites, both natural pass-throughs of `report_private_leak`:** (1) **type-alias RHS** (`export Foo :: PrivateType`) — the debatable case: fire (Rust E0446 does) or treat as a sanctioned re-export of a private impl type ; hook `declare_type_alias` ; decide before implementing. (2) **trait method signatures** — `check_public_fn_visibility` is only called from `declare_fn`, which trait-method sigs never reach, so a public trait's method params/returns over a private type go unchecked ; hook wherever trait members are declared. Mirrors Rust's `private_interfaces` (E0446).


- [x] **LSP semantic tokens override TextMate for strings — escapes lose their colour** (fixed 2026-07-26). Option B: `classify_token` returns `-1` for `CharLit` / `StringBegin` / `StringPart` / `StringEnd`, so the shared TextMate grammar keeps painting literals *and* their escapes. `TokenType.String` stays in the legend (index stability) but is never emitted. Tests: `test_literals_emit_no_token`; the multi-byte length guard moved onto a comment token.


- [x] **Call-site function names lose their color under the LSP** (fixed 2026-07-26). Server side was already right — both callee shapes are tagged `Function` (asserted end-to-end by `test_call_sites_are_tagged_function`). The cause was the COLOUR KEY, not a missing mapping: LSP4IJ's `DefaultSemanticTokensColorsProvider` maps `function` → `LSP_FUNCTION`, whose fallback is `DefaultLanguageHighlighterColors.FUNCTION_CALL` — a key themes leave at the default foreground, while the TextMate scope `entity.name.function.call.vader` IS coloured. So the semantic token replaced a coloured scope with an uncoloured key (tell-tale: the same call inside a string interpolation, where no AST token is emitted, stayed blue). Fix: `VaderSemanticTokensFeature` returns `null` for `function` — LSP4IJ null-checks the key and skips the highlight, leaving the grammar's colour in place. Everything else delegates to LSP4IJ's default, so its user-configurable `LSP_*` colour keys are preserved.


- [ ] **Warn on unused imports** (added 2026-06-07). An imported name that's never referenced in the file earns a compilation warning (new W-code). Covers both import forms : `import "path" { Name1, Name2 }` — each destructured name must be used at least once — and the namespace form `xx :: import "path"` — the binding `xx` must be referenced at least once (e.g. `xx.Member`), else the whole import is dead. Emit one warning per unused name, pointing at its import-list span. Update `SPEC.md` (imports section) in the same commit.
  - **Attempted 2026-06-17, reverted — blocked on reference-tracking.** First cut scanned `resolved.idents` (span→Symbol) for `ImportBinding`-kind values to build the "used" set, emitting W0006 for every unreferenced import binding in `resolved.symbols`. Minimal snippets passed (an unused `eprintln` flagged, a used `println` not — across value position, let-binding RHS, and type position). But on the real tree it **systematically false-positives** : `vader/lexer/keywords.vader` (40 LoC, **zero own imports**) reported 16 W0006 — they were `vader/lexer`'s **sibling-file** imports, whose uses the resolver never recorded because **its body walker is structurally `files[0]`-only** (TODO §1.13d, `resolver/resolve.vader:153`). Worse, single-file `vader/cli/main.vader` reported 24 W0006 for top-of-file imports that are obviously used (`keys`, `values`, `resolve_module`, …) — so `resolved.idents` is **not a reliable record of every use** even within one file (some expr/type positions never land there ; root not fully pinned). **Conclusion :** a sound W0006 needs comprehensive, **symbol-id-keyed** (not span-hashed) reference tracking that covers *every* file of a (folder) module and *every* reference position. That is the same gap as **"Harden multi-file module support" (§1.13d, the `files[0]`-only body walker)**. Do this **after** §1.13d lands, or as a dedicated full-AST name-collection walk (params/return/fields/alias-RHS/const-types/all bodies, across all files) — not by scanning `resolved.idents`. Reverted cleanly (no W0006 in the tree).


- [x] **UFCS resolves *through* a namespace alias — `x.f()` compiles where the bare `f(x)` is R2006** (found 2026-07-28, fixed 2026-08-02). `populate_imported_fn_overloads` now feeds the UFCS table from `CollectedModule.wildcard_paths` instead of `import_paths` — the collector already separated the two, and only the forms that put names in UNQUALIFIED scope (bare `import "p"`, `import "p" { … }`) belong in that table. A namespace alias contributes nothing, so `x.f()` now fails exactly where `f(x)` does. The miss reports **T3078** (`vader/typecheck/field.vader::report_namespace_alias_method`), checked ahead of both shape-based exits of `resolve_struct_field` so it covers a struct receiver and a scalar one; it spells the repair (`write `P.bump(c)``) but does NOT name the target module — `namespace_targets` carries the module's FOLDER, not the name the import spelled, and R2008 on a namespace member is likewise module-free. Fixture `tests/diag_corpus/typecheck/t3078_ufcs_through_namespace_alias/` (struct receiver + scalar receiver + a negative where the alias exports the name but no overload takes the receiver). SPEC §UFCS "Import requirement" now states that "same rule" includes the import form.

  **The predicted blast radius was wrong, and in the harmless direction: zero sites.** `vader/resolver/materialize.vader:156` was a false positive — that file imports `vader/parser` BOTH as a wildcard and as `AST ::`, so `factory.mint()` was always legal there (a style defect under `.claude/CLAUDE.md` §6, not a resolution one). The self-compile is clean with no source change, which is the only measurement that counts here; re-derive it that way rather than by grepping.

- [x] **A modifier list's exclusions don't reach the UFCS table — `import "p" { x as _ }` leaves `recv.x()` callable** (found + fixed 2026-08-02, split out of the alias fix above). Closed by giving the table the granularity SPEC already specifies: `TypedProgram.imported_fn_overloads` is now keyed **by source file** then by name, built from `CollectedModule.wildcards` — one `FileWildcards` entry per file, appended by `merge_collected` instead of unioned. Consumers pass the call site's own file (`Span.start.file`): `field.vader::{ufcs_name_has_candidates, try_free_fn_ufcs_with_first, ufcs_methods_for}`, `call.vader::{primary_overload_ft, collect_overload_candidates}`, and the LSP completion handler (which passes `sf.program.file` — the path the parser stamped into the spans, not the URI-derived one). Reads go through `imported_overloads_in` / `has_imported_overload_in`.

  **A materialised trait-default body has no file of its own** — `resolver/materialize.vader` stamps it `<clone>:<impl file>` so sibling impls don't collide their span keys. Each table is therefore registered under both spellings (maps hold references, so the alias is one entry, not a copy); the shared `CLONE_FILE_PREFIX` lives next to `StampCtx` rather than being spelled twice. Miss this and every cloned default-method body loses its imported UFCS candidates at once.

  **The tree was leaning on the bug in 15 files.** Switching to file scope surfaced them all as hard errors: `core_seed.vader` used `.ends_with` without importing `std/string`, nine `vader/lower` + `c_emit` files used `.add`/`.len`/`.is_empty` without `std/collections` or `std/iter`, `parser.vader` and `lexer/dump.vader` used `.append` without `std/string_builder`, and `lower_iter_fusion.vader` used `span_of(AST.Expr)` — which lives in `vader/comptime`, not in its own module — while importing `vader/parser` under an alias only. Each was borrowing a sibling file's import, which SPEC §"Modules" forbids; each got the import it actually depends on. Cost measured on a full self-typecheck: 8.88 s → 8.92 s, RSS unchanged (~340 MB) — the per-file tables are ~30 prelude entries plus that file's imports, so the duplication is noise.

  **Still open, and now the only side that diverges: the RESOLVER's unqualified seed.** `build_wildcard_seed` is still fed the module-wide union (`all_wildcard_paths` / `all_wildcard_excludes`), so in a multi-file module the BARE form is refused where the UFCS form now resolves — the mirror image of the bug just closed. `vader/lsp/main_entry.vader` is the live instance: its sibling drops `std/cli`'s `parse` to keep `std/json`'s, so the bare `parse(argv, LSP_FLAGS)` cannot resolve there and the call is now written `CLI.parse(...)` through an alias. Pinned by `tests/diag_corpus/typecheck/t3009_ufcs_import_modifier_is_file_scoped/`, whose snapshot deliberately records that R2006 — when the seed goes per-file (§1.13d, the same chantier as the `files[0]`-only body walker and W0006 unused-imports), the entry disappears and the snapshot moves, which is the signal.

---

## Phase 1 — MVP compiler in TypeScript

> Completed subsections (see the note above): §1.0 Diagnostics, §1.1 Lexer, §1.2 Parser, §1.3 Resolver, §1.4 Type-checker, §1.7 Bytecode emitter, §1.13b Self-hosting prerequisites, §1.13c Bugs, §1.14 Snapshot infra, §1.17 Enums, §1.18c-bis / §1.18c Overloading, §1.18 Built-in aliases. The subsections kept below still carry open `[ ]` / `[~]` items.

### 1.5 Comptime engine + monomorphizer

**Decision:** AST-walking interpreter at first, then ported to the bytecode VM in 1.5b. No separate comptime VM — the engine and the runtime VM share `src/bytecode/ops.ts`.

> Shipped 1.5a + 1.5b: AST-walker → bytecode-VM comptime engine, `@comptime` cycle detection + topo eval, generic-fn instance registry + monomorphization, `std/iter` eager + lazy + short-circuiting combinators, transitive mono, first-class trait-method dispatch, generic `len`, `T[]`→`Iterator(T)` auto-coerce, `for x in iter` / `MutableList` inside `@comptime` (VM-backed staging).
- [ ] **Default-init for generic typeParam** — `acc: T = T()` style, needed by `sum(it)` over an iterator. Either a `Default` trait + auto-impl on numerics, or a `zero<T>()` intrinsic. Currently blocks iterator-driven `sum`, `min`, `max`. Requires either (a) explicit type-args at call sites (`default[T]()`) or (b) `T()` constructor syntax for type-params. Recommendation : start with (a). `Default` trait can wait until a dispatch path exists.

### 1.6 Lowerer — partial
> Shipped: lowered AST, match → if/else chain, `expr?` + interpolation + `defer` + trait-call lowering, lambda lifting / closure conversion, `RangeExpr`/`T[]` → `Iterator` for-in.
- [ ] Match decision-tree compilation (Maranget). Naive chain is enough for MVP.

### 1.7b IR text emitter / reader (`--target=ir-text` → `.virt`) — partial
> Shipped: line-oriented `.virt` grammar, `writeVir`/`parseVir` round-trip, `vader run program.virt`.
- [ ] Manifest mode for multi-module bytecode merge.

### 1.7c Bytecode format refresh — partial

**Two-format split — done**
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
- [ ] **REPL** — needs incremental compilation across phases. Punt until after the C/WASM emitters.
- [ ] **Slot-typed numeric promotion verifier** — add debug-only verifier when the WASM target lands.

### 1.9 C emitter (Iter-ready) — partial
> Shipped: full `src/c_emit/emit.ts` (type repr γ, `std/io` shims, `vader build --target=native`, VM-parity tests), `--release` / `--cc` / `CC` / `--ldflags`, struct-field unbox after `is`, Windows cross-compile (mingw-w64 + Wine), `#line` debug directives, stable `@extern` ABI (T3050/T3051).
- [ ] Manifest mode (`vader build --target=native --manifest`).
- [ ] i32/i64 overflow handling per SPEC §4 (panic in debug). Wraps silently today.

### 1.10 WASM emitter — moved to Phase 3 (§3.10)

### 1.11 C runtime — done
> Shipped: string + array runtime, StringBuilder consolidation (`stdlib/std/string_builder/`), panic handler (`vader_panic` / `vader_trap`, drain-defers-then-abort), libc-backed I/O for `std/io` (`vader_read_file_bytes` / `vader_write_file_bytes` / `fgets`). Full setjmp/longjmp panic-unwind on the C target is tracked under §3.8 `defer` unwinds on panic.

### 1.12 CLI — partial
> Shipped: `vader run` + `vader build` single-file, `--target=ir` (`.vir`/`.virt`), `vader test`, `vader dump --stage=<ast|typed-ast|bytecode|c|…>`, `--allow-env`.
- [~] **`vader fmt [path]`** — see top "Priority — next up".
- [ ] Manifest-driven build (`vader.json`) — single-file works ; manifest mode still gated "not yet implemented".
- [ ] `vader build --target=wasm` — see §3.10.

### 1.13 Stdlib (in Vader) — partial
- [~] `std/core` finalisation, `std/io`, `std/string`, `std/math`.
- [ ] **Immutable `Map`/`Set` ops + `to_immutable`** — re-add the struct decls when there's a real read-only-view design.
- [ ] **Restore `MutableList(T)` once immutable `List<T>` lands** — raw `T[]` already covers push/len/indexing.
- [~] **`std/cli`** (initial 2026-05-11) — minimal declarative `FlagSpec` + `parse(args, specs) -> ParsedArgs` + accessors. Supports `--name`, `--name=value`, `--`. Open : subcommands, `--help`/`--version`, short flags `-v`, `--name value` form, rewriting `vader/cli/main.vader` on top once subcommands land.

### 1.13d Stdlib consolidation — partial
> Shipped: hex/base helpers centralised in `std/numbers`, `std/json` char-predicate duplicates removed.

  - **Promoted to a dedicated plan (2026-06-16): [`.claude/plans/2026-06-19-core-string-utf8-reorg.md`](.claude/plans/2026-06-19-core-string-utf8-reorg.md).** It folds in the `string.len()` miscompile (UFCS to a non-imported, non-`core` free fn → invalid C), the **frozen import policy** (using a non-imported fn — except `std/core` the prelude — is a compilation error), the prelude/layering rule, and the emitter ICE backstop. The `bytes_to_string` reconciliation item below is folded into that plan's Phase 3.
- [ ] **Future audits** — revisit when new stdlib modules land. A shared `Cursor(T)` trait could unify `std/json` and `vader/lexer`'s hand-rolled cursors when a real need arises.
- [x] **`.virt` reader silently drops unknown opcodes** (found + fixed 2026-07-27). `try_push_op` returned `false` for any line it couldn't parse and the caller `continue`d, so a dump carrying an instruction the reader didn't know ran with that op MISSING — unbalanced stack, plausible wrong output, no diagnostic. Found by removing an opcode while a stale `.virt` still used it: `path_basics` printed empty filenames rather than failing, and a subsequent `UPDATE_SNAPSHOTS=1` overwrote nine correct `vm.snapshot` oracles with the wrong output. **The premise of the tolerance was false**: a body holds no non-instruction lines (comments and blanks are gone by then, `local` and the closing `end` are taken earlier), and the directive vocabulary outside a body is closed at ten heads — so position alone tells an instruction from anything else, no heuristic needed. `parse_virt_bc` now returns `BytecodeModule | VirtParseError` (line number + line + reason) and stops at the first line it can't read, covering all three silent paths: unknown instruction, unknown directive, and a known head whose operands don't parse (each shifts every following pc against an already-built jump table). The one line that legitimately isn't bytecode — the terminal `# Diagnostics` report `vader dump` appends after a warning-raising compile — ends the stream instead. Callers mirror their existing `is IOError` arm (`run_virt`, `emit_c_source_from_virt`). Verified against all 387 `.virt` dumps in the corpus: zero traps, i.e. no writer→reader gap was hiding behind the tolerance. Cross-ref the snapshot-regeneration order trap — regenerate `bytecode.snapshot.virt` BEFORE the vm oracles, or `vader_vm.test.ts` measures the old dump. **This closes the silence at LINE level only** — the same degrade-quietly pattern survives inside the recognised directives, see the entry below.
- [x] **The `.virt` directive parsers degraded quietly** (found 2026-07-27, fixed 2026-07-28). Each dropped or substituted on malformed input and returned as if it had succeeded. `parse_type_decl_bc` fell through to `bc.BcRef { .trait_name = "" }` for any kind it didn't recognise — the `BcStruct`→`BcRef` placeholder that is blocker #1 of the self-host bytecode audit, where an opaque ref makes every downstream field access a miss. `parse_struct_type_bc` skipped a field whose `name:tid` didn't split or whose tid wasn't numeric, silently renumbering every later field. `parse_import_decl_bc` / `parse_impl_decl_bc` / `parse_vtable_decl_bc` / `parse_data_decl_bc` each returned mute on a malformed line, dropping a whole pool entry and shifting every index after it.

  All five now report. They return a `DirectiveError` — a named type rather than a bare `string | null`, because a string says nothing about whether it is a value or a complaint — carrying the reason without the position; `parse_virt_bc` holds the line number and pairs the two into the `VirtParseError` added for the line level. Verified against all 390 `.virt` dumps in the corpus: 385 read unchanged, **zero new refusals**, so nothing valid was tightened out. Covered by three colocated tests, one per failure family.

  The remaining 5 are a **separate, pre-existing** limit, confirmed by rebuilding without these changes: `c_emit: baked struct symbol_id N not in the module type table`. The `.virt` text carries no struct `symbol_id` (the reader's header says so and falls back to `-1`), but a struct baked into `.rodata` needs one C-side. Affects `_diag_comptime_struct{,_nested}`, `module_const_mutability`, `array_add_concat`, `array_push_all_const` — all of them dumps holding a module const of structs. Either the dump must carry the symbol id, or `c_emit` must key baked structs on something the text preserves.

- [x] **A distinct-type cast lost its type when a method was chained onto it** (found + fixed 2026-07-27). `string(n).trim()` on a `string`-backed distinct panicked in midir — `no field 'trim' on 'Name' — a method reference on a primitive isn't a first-class value` — while binding the cast to a local first, or calling `trim(string(n))`, both worked. Cause: `emit_value_cast` (`vader/lower/lower_impl_member.vader`) returned the argument VERBATIM for a `string` / `bool` / `void` / `null` target, so the lowered tree kept carrying the distinct and any read of the result's type resolved against it. The numeric arm and the WRAP direction both stamped their target already; this was the missing half, and the fix is to stamp unless the cast is a true identity. Free at runtime — `bc_type_of(distinct) == bc_type_of(backing)`, so the emitted cast is a no-op. **Two things my first write-up got wrong**: it is not limited to the isolated per-module compile (a plain `vader run` reproduces in twenty lines — `to_posix` only surfaced there because that was its only caller), and it is not about lambdas or `replace_chars_where` (`string(n).trim()` breaks identically, so it is any method on any such unwrap). Same panic site as defect (c) of `.claude/plans/2026-07-27-ufcs-dispatch-elaboration.md`, and a fourth member of the two-priority-ladder family that plan describes, but independently fixable. Pinned by `tests/snippets/distinct_unwrap_method_chain`, which covers all three backing families plus the identity cast and the two forms that already worked.
- [ ] **`is` on an instantiated generic struct ignores the type argument — silently wrong** (found 2026-07-27 evaluating whether `FlagSpec` could be generic over its kind). A test against one instantiation matches *every* instantiation, and the narrowed binding then reads the field at the wrong type, with no diagnostic. Repro (no snippet on purpose — its snapshots would enshrine the wrong output):

      Spec :: struct<T> { name: string, dflt: T }

      main :: fn() -> i32 {
          xs: (Spec<bool> | Spec<string>)[] = [
              Spec<bool>   { .name = "release", .dflt = false },
              Spec<string> { .name = "cc",      .dflt = "cc" },
          ]
          for s in xs {
              if s is Spec<bool> as b {
                  println("${b.name} bool ${b.dflt}")
              } else if s is Spec<string> as t {
                  println("${t.name} str ${t.dflt}")
              }
          }
          return 0
      }

  Prints `release bool false` then **`cc bool true`** — the `Spec<string>` took the `Spec<bool>` arm, and its `string` field was read as a `bool`. Identical under `match`, identical for a local array and a module const, so it is neither the const path nor the match lowering: the `is` test compares the struct's *shape* and never looks at the type argument. Same family as the erased-vs-packed bugs (`docs/HISTORY.md` §3.8) — generics are erased, so `Spec<bool>` and `Spec<string>` share one runtime tag. **Two defensible fixes, to decide before coding:** carry the type arguments in the runtime tag so the test can discriminate (costs a wider tag, helps every `is` on a generic), or have the typechecker REJECT a union that mixes instantiations of one generic — the narrowing it would need is unimplementable under erasure, so promising it is the actual defect. The second is cheaper and honest; the first is what a user expects. Until then, a heterogeneous table of `Spec<T>` is unusable, which is why `FlagSpec` keeps a `kind` field instead of a type parameter.
- [x] **`push_all` copied between arrays without checking their element kinds** (found + fixed 2026-07-27). `vader_array_push_all` ended in a memcpy sized by the SOURCE's element width and never compared the two buffers' `element_kind`. A module const materialises BOXED (24-byte `vader_box_t` slots), a freshly allocated `T[]!` is KIND_REF (8-byte raw pointers) — so `dst.push_all(SOME_CONST)` wrote 24-byte boxes at 24-byte strides into an 8-byte-stride buffer and died reading them back as pointers. Native only; the VM boxes uniformly. Surfaced as `vader lsp --stdlib-root=…` exiting 139 with no diagnostic, because `command_specs` used `push_all` on a flag-spec const. **Two wrong guesses, recorded because they cost time**: it is not the cross-module hop (a same-module copy of the same const still crashes), and it is not the removal of a nearby function (the first bisection blamed a deleted `basename`, and putting it back did not fix it — the lesson being that removing the supposed cause is the only test that counts). What settled it: the C dump with `#line`, where the `push` loop emits `vader_ref_box` per element and `push_all` emits a bare memcpy. Matching kinds keep the memcpy; differing kinds go through the boxed form element by element via a `vader_array_load_slot` extracted as the symmetric read of `vader_array_store_slot`. Pinned by `tests/snippets/array_push_all_const` — note the nested array field, without which the const materialises REF and nothing reproduces.
- [x] **A single-dash CLI token is swallowed instead of rejected** (found + fixed 2026-07-27). Closed by the declarative-CLI work: `std/cli`'s single parser inspects a `-x` token instead of assuming it positional, so an unrecognised short flag is an error like an unrecognised long one. `vader build x.virt --target=c -o out` no longer exits 0 having ignored the `-o` — which is what littered 384 stray `.c` files across the snippet corpus. Short aliases are now real (`-o`, `-t`, `-r`, `-s`, `-h`, `-v`), so `-o` means `--out`. See `.claude/plans/2026-07-27-cli-arg-boundary-and-aliases.md`.
- [x] **Minify the C that becomes `bootstrap.c` — DROPPED 2026-07-28**, the same day it was measured, because the seed-size chantier removed its entire justification. Kept below as record: the measurements are sound, the prototype works, and the reasoning is what stops this being picked up again.

  **Why it is dead.** The original headline — 1064 KB → 950 KB gzipped, "114 KB per reseed" — measured the *compressed artefact*, which no longer exists. `.claude/plans/2026-07-28-seed-size.md` stored the seed raw (Phase 1), moved reseeds to one per push (Phase 2) and converted the 400 historical seeds (Phase 3), taking `.git` from 535 MB to 61 MB. What is left for minification to win: ~12 % of the per-reseed delta (measured on four real consecutive seeds packed both ways, 1.6 MB → 1.4 MB), so roughly **6 MB a year** at ~46 reseeds/month — against a repository that is now 61 MB, and after paying ~2 MB up front for the first minified reseed rewriting every line's indentation. Break-even around four months, for a rounding error.

  Against that: a `minify_c` function, a CLI flag, **two** emit sites to keep in lockstep, and the permanent trap documented below — get the `cmp` sides out of sync and `verify.sh` is red in CI forever. The two secondary arguments went too: the seed is not distributed separately (a fresh clone is 83 MB), and a 20 %-smaller translation unit is noise against the 1 min 40 bootstrap, since lexing is a tiny fraction of it.

  **If it is ever revived, the reason will not be size.** It would be readability of the emitted C, or a target where the artefact ships on its own.

  **It does NOT produce enormous lines** — worth stating because the name suggests otherwise. `minify_c` trims each line and drops the empty ones; it never fuses two lines. Measured on the seed: 215 444 lines → 212 846 (−1.2 %, exactly the blank lines), mean line length 52.4 → 42.0 chars, and the **longest line is unchanged at ~55 000 characters** (a `UINT64_C` comptime table, one of 6 lines already past 10 000 chars). The byte win comes entirely from the indentation, not from removing lines.

  **Shape: a `--pretty` flag on `build --target=c` (default true), applied to the WHOLE emitted string at the end — not threaded through the emitter.** Conditioning each site is what makes this sound expensive: `c_emit` has 48 places emitting hard-coded indentation and 141 emitting a newline, none of it behind a shared `indent()` helper. But nothing requires touching them. `build_c` already holds the finished C as one string before `write_out`; running it through a `minify_c(source) -> string` there costs one call site, leaves the emitter untouched, and makes the transform a testable Vader function rather than a shell filter duplicated across scripts.

  Only the seed uses it. `regenerate.sh:31` and `verify.sh:26` emit the seed with the *same* command, so adding the flag to both keeps `verify.sh:27`'s byte-for-byte `cmp` valid with no filter of its own — the freshness guard stays exactly as it is. stage1 / stage2 (`build.sh`, `verify.sh`'s `fp1.c` / `fp2.c`) don't pass it and stay readable, which is what `--target=c` exists for.

  **`--pretty=false` and `--release` are independent, and it is worth not conflating them.** The worry that minifying a debug build would wreck the `#line` directives does not hold: all 48 844 of them sit in column 0, so stripping indentation leaves them untouched — checked, the minified debug C still compiles and keeps them. The gain is comparable either way (9.5 % debug, 10.6 % release). What `--release` removes is the `#line` lines themselves, which are worth 1.2× on their own; what `--pretty=false` removes is whitespace. Different axes.

  So don't make the flag *require* `--release`. Combining them is simply what the seed wants — a minified debug C has no use, since debug info exists to be read and minification is for what isn't. Document the pairing rather than enforcing it; `--annotate` is the precedent for a flag that is documented as belonging to one stage without the parser policing it.

  **`minify_c` itself is ~20 lines — prototyped and run against the real seed.** Split on newline, `trim()` each line, drop the empties, re-join. Two details are the whole difficulty, and both are cheap:

  - **Continuation lines.** A line ending in `\` means the next line's leading whitespace belongs to a string literal or macro body, so both must pass through untouched. The emitter produces **zero** of them today (checked across all 215k lines of the seed), which is why the crude `sed` measurement was safe — but the guard is four lines and makes the function correct regardless of what the emitter does later. Verified on a `#define A(x) \` / indented body pair: preserved intact.
  - **The trailing newline.** `join("\n")` drops the file's final newline, so the output differs from the source by exactly that one byte. Re-add it when the input had one, or the artefact churns for no reason.

  Measured on the 11.6 MB seed: **0.39 s**, output identical to the `sed` reference modulo that trailing newline. Cost is negligible at reseed.

  Going further than indentation + blank lines (collapsing statements onto one line, spaces around operators) buys the rest of the 20 % but needs real C tokenisation to stay safe inside string literals — a different project. Stripping leading whitespace is safe as-is: C has no literal newline inside a string.

  **The trap, whichever shape is chosen: the minified form must appear on BOTH sides of every comparison.** `verify.sh` does `cmp -s build/bootstrap.new.c bootstrap/bootstrap.c` — freshly-emitted C against the committed seed. Minify only the seed and it reports **STALE SEED on every run**, forever; `verify.sh` runs in CI, so that is a permanently red job, and the likely reaction — muting the check — costs far more than the bytes saved. Passing the flag at both emit sites is what avoids this, and is the reason the flag beats an external filter: there is nothing to keep in sync.

  One residual cost: `regenerate.sh` suggests reviewing `diff <(git show HEAD:bootstrap/bootstrap.c) bootstrap/bootstrap.c`, and both sides would now be minified — so the diff still works, just unreadable line-by-line. Arguably it already is at 215k lines of generated C; what gets checked in practice is the byte delta and the fixed point. Reword the suggestion rather than leave one that misleads.

  A second, one-off cost: the first minified reseed rewrites the leading whitespace of essentially every line, so **that single commit gets a near-full-size delta** (~2 MB rather than ~60 KB). Reseeds after it delta normally. Worth knowing so the numstat spike is not read as a regression.

- [ ] **`std/encoding` over `Buffer` — the consumer the multi-byte memory opcodes are waiting for** (noted 2026-07-27). `LoadI32`/`I64`/`F64` and their `Store*` twins are implemented end to end — VM (`vm/exec.vader`), C emit (`c_emit/walker.vader` → `vader_buffer_load_i32`), dump, `.virt` reader — but NOTHING can mint them: a memory op only comes from a mangle match in `bytecode/intrinsics.vader`, and `std/core/buffer.vader`'s `ByteAccess` declares only `load_u8` / `store_u8` / `memory_copy` / `intern_string` / `write_string`. They are an ABI landed ahead of its surface; do not prune them as unreachable (an audit nearly did). Two constraints to settle before exposing anything:
  - **Name the endianness** (`load_i32_le` / `_be`), never leave it "native". WASM defines its linear memory little-endian NORMATIVELY, while the C backend's `memcpy` follows the machine — so a single "native" accessor means two different things across backends on a big-endian target. An explicit `_le` is one instruction on both (`i32.load` / `memcpy`).
  - **`_be` is cheap natively, expensive in WASM**: `__builtin_bswap32` is one instruction, but WASM has NO byteswap instruction, so it costs shifts + masks — roughly what the existing pure-Vader shift loop costs. Consequence for the obvious candidates: MD5 (little-endian) would gain on both backends, **SHA-256 (big-endian) gains nothing in WASM**. Measure before promising a crypto speed-up. Note also that `crypto.vader` works on `u8[]`, not `Buffer`, so it would first have to move onto a `Buffer`.
  - Reference implementation of the byte semantics already exists in `vader/vm/byte_codec.vader`, which explicitly names `std/encoding` as its successor — and which cannot itself use the opcodes it implements.

### 1.13e Language ergonomics surfaced by self-host port — partial

Patterns counted on the existing Vader code that paid an outsized boilerplate cost. Each item is additive, back-compat by construction.

> Shipped: `usize` literal context-sensitivity, `T | null` flow-narrowing, divergence → `never` (blocks / infinite loops), W0002 unreachable-code, enum-to-repr cast, const-binding mutation reject (T3041), field-expr + `is T` narrowing, tuple-destructure-after-narrow, byte literals `b'X'`, free type-alias order, namespace-alias unification, `MatchResult` cleanup, self-host lexer u64, `if x is T as binding`, lambda `fn`-keyword drop, `for <range>` shorthand, generic-syntax normalisation to `<T>` (full migration — 0 real code sites left in legacy `[T]`/`(T)` form ; fmt emits `<T>` ; legacy parser openers `parse_bracketed_type_params` / `parse_generic_arg_list` removed ; the surviving `($N: i32)` head is the intentional comptime-value surface, not legacy generics).
- [ ] **AST node id boilerplate** — re-audited 2026-05-15 ; deferred. ~11 self-host fields carrying `id: UNASSIGNED_NODE_ID`. All three resolution shapes (decorator, mixin, marker) need new compiler infrastructure that's bigger than the 128 lines it would save. Revisit if decorator infra lands for other reasons.

### 1.15 Formatter — partial
> Shipped: AST → formatted source + idempotency check (`vader/fmt/printer.vader` + `format.vader`, `vader fmt --check`). The canonical no-options layout is codified in `vader/fmt/style.vader`.
- [ ] Define formatting rules — write up the canonical layout as a design-freeze doc (the layout already ships in `style.vader`; this tracks the written spec). See the `vader fmt` MVP under "Priority — next up".

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

- [ ] **Direction A — mono dissolves into the comptime engine** (deferred). `fn[T](...)` partially evaluated with `T` bound, comptime engine owns instantiation. Only worth it if the type-first milestone (Layer 4/5) needs it. The old dormant scaffolding is gone, so this is now a from-scratch build ; Direction B closed no doors (the harvest + lower-side erasure stay).

#### Layer 4 — `type` as a first-class comptime value

Architectural prerequisite for full mono → comptime migration. Built bottom-up via milestones B.0 → B.6.

##### B.0 — `@comptime` type-alias decls (DONE)

##### B.1 — Type as a VM Value (DONE 2026-05-16)

##### B.2 — Type values flow through intrinsics (DONE 2026-05-16)

##### Vader VM port of Layer 4 ops (DONE 2026-05-16)

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
- [ ] Struct-literal-as-type-expression — `Pair :: type[A, B] struct { first: A, second: B }`.

#### Layer 5a — uniform `[]` for type-args at call sites
- [ ] Decide whether `MutableMap(K, V)` at call sites (still accepted) emits a deprecation warning.

#### Layer 5b — comptime contagion
- [ ] **Accept conditional type expressions** — `t :: if @size_of(i32) > 16 { i64 } else { i32 }`. Blocked by Layer 4 B.1.

#### Layer 6 — reflection iteration

#### Layer 7d — non-trait predicates on generics
- Open question. `where` was removed entirely ; decide whether to re-introduce it as a keyword, expose predicates via `[T satisfies @size_of(T) <= 64]`, or forgo non-trait predicates until a real use case surfaces.

#### Layer 7a/7e — bounds as comptime predicates
- [~] Rewrite `[T: Trait]` enforcement to `@satisfies(T, Trait)` via the comptime engine.
- [ ] Trait method dispatch on bounded type-param via comptime predicates.

#### Layer 8 — impl & coherence — mostly done

#### Open questions deferred
- Q8 — comptime evaluation budget (decide once Layer 2 lands).
- Q10 — hygienic macros vs `@comptime for`-only (`@comptime for` covers ~95 %).
- Q11 — migration phasing (layer-by-layer is the plan).

---

## Phase 2 — Self-hosting

Began once the TS compiler could compile a non-trivial subset. Goal : validate the design as we go.

### 2.0 Vader CLI minimal — done
> Shipped: argv parsing + stage dispatch, snapshot parity rig (`tests/parity/`), native CLI build via `tests/cli-bin.ts`; all stages ported — `run` + every `dump --stage=` self-hosts.

### 2.1 Port the parser to Vader — done
> Shipped: lexer (`vader/lexer/`), diagnostics (`codes`/`diagnostic`/`render`, now a `vader/diagnostics` folder-module so `private` survives cross-file), parser (`vader/parser/`, ~2200 LoC recursive-descent + Pratt), AST→JSON dumper, `vader dump --stage=ast`, byte-for-byte lexer + parser parity (~240/245), porting bugs all closed.

### 2.2 Port the C emitter — NATIVE FIXED POINT REACHED (2026-06-05)
> Shipped (deferred follow-ups closed): resolver `StampCtx` for `@intrinsic` impl-member param spans (`vader/resolver/materialize.vader`; the `impl_member_param_type` workaround is gone); stale `io_println` / `string_ops` bytecode snapshots regenerated (Vader is the oracle now); the bytecode emitter emits `defer` (`DeferPush` / `DeferPopExec` — the `emit_body.vader` stub is gone); and the C-emit codegen pistes carried into the Vader walker (`vader/c_emit/walker.vader` + `stack.vader`: piste 5.a `push_local_ref`, 5.c/5.d `StackExpr` for `type_check` + pure binops/cmps — piste 1 tmp-recycling intentionally skipped, monotone allocation suffices under the run-oracle gate).
- [ ] **typer over-narrows the `is`-operand** (non-blocking cleanup) — `d77f5bc4` strips the narrowing cast at the lowerer ; cleaner would be the typer not narrowing the operand, optionally + a C-emit `emit_type_check` no-fold-after-`ref.cast` hardening as a second defense.

### 2.3 Port the bytecode emitter — DONE, the active self-host path (fixed point 2026-06-05)

The Vader-side bytecode emitter (`vader/bytecode/` + `vader/midir/emit.vader`) is the only active path — it compiles the whole compiler to a byte-identical native fixed point (see §2.2). Full detail (emit path, file layout, snapshot-oracle model) archived in [`docs/HISTORY.md`](./docs/HISTORY.md) (§2.3).

Open (low priority) :
- [ ] **Dispatch-cascade perf** — `emit_call_to_symbol` walks a 4-way
      cascade (slot → intrinsic → fn-table → import) and
      `intern_cell_type` allocates a string per call. Refactor candidate :
      a single `MutableMap(symbol_id, CallTarget)` keyed at registration
      time. Deferred until bytecode emit shows on a profiler.

### 2.4 Port the VM — done

Sprint plan : [`docs/SELFHOST_VM.md`](./docs/SELFHOST_VM.md) — "essentially done, Sprints 1–12 shipped".

> Shipped: full Vader VM (`vader/vm/exec.vader`, ~3000 LoC) — locals, binops, control flow, strings, structs, arrays, calls, type checks; binary `.vir` loader (`vader/vm/virt_reader_bc.vader`); `vader run <file.vader>` compiles + executes source through the VM; `examples/` run on the Vader VM (416 `vm.snapshot` files).

### 2.5 Port the WASM emitter — gated on §3.10
(Empty until a WASM emitter lands — see §3.10.)

### 2.5b Port the comptime engine — partial (tree-walk MVP, 2026-05-18)

Tree-walk evaluator covering the subset of comptime expressions the
lowerer + bytecode emitter port haven't unlocked yet. General
Turing-complete `@comptime fn` bodies (loops, function calls) defer
until the full VM-round-trip path is online.


#### Closed / superseded

Archived in [`docs/HISTORY.md`](./docs/HISTORY.md) (§2.5b) — bytecode-driven comptime eval + `@file` / `@field` / `@fields` shipped; the TS-premised harvest / ArrayIterator / into-coercion / transitive-closure items are obsolete (monomorphisation now lives in the lowerer).

#### Divergences from the reference impl (Vader is correct)

(none recorded yet)

### 2.5c Port the lowerer — partial (basic + match + interp + range, 2026-05-18)

Lowerer port covering the subset the comptime + typecheck side-tables
already expose. Lambda lifting, for-in / Iterator, try, display-coerce,
and the inline-consts pass defer until the missing impl-by-trait
queries + closure-analysis pass land on the typechecker side.


#### Closed by 5g + downstream chantiers


#### Still open

(none — the inline-consts pass shipped as `vader/lower/inline_consts.vader`.)

### 2.6 Port the type-checker (last)
> Shipped: snapshot-test parity on every sample — Vader is the snapshot oracle; the compiler self-hosts to a byte-identical fixed point.

#### Bugs surfaced while porting the typechecker — open
- [ ] **DCE primitive trait-impl entries via "primitive-as-value" usage tracking** (2026-05-25). `vader/midir/emit.vader::build_vtables_from_entries` (the live vtable-reachability gate ; TS's whole-program `drainPending` DCE was never ported) punts on primitive receivers — a `struct_sym_id != null && !reachable` skip — every primitive impl skips the gating, so the full `Display` / `Equals` / `Add` / `Sub` / `Mul` / `Div` vtable survives as soon as any `virtual.call` against the trait survives. Concrete cost on a generic `[T: Display]` fn lowered via erasure : 15 `to_string` imports + 15 `_vt` trampolines + 15 vtable rows for *one* `println(some_i32)` call. Stop-gap landed 2026-05-25 : `@specialize` on the four `std/io` wrappers (sidesteps virtual.call entirely for the common case). Proper fix : track which primitives are actually materialised in reachable code (literal consts, casts, fn signatures' param/return types, struct field types) and gate primitive-receiver impls on that set. Implementation surface : (a) add a `usedPrimitives: Set<PrimitiveName>` populated during the worklist walk in `pruneUnreachable` (visit `LoweredIntLit` / `LoweredFloatLit` / `LoweredCast` / `LoweredFieldAccess` / fn-decl param-types) ; (b) extend the `pendingVirtual` drain with a primitive-aware gate analogous to the existing struct gate ; (c) verify the change doesn't break tag-aware paths in trait_box_range_iter / json_basics. Earns the win for *every* generic `[T: Display]`-shaped user code, not just the stdlib wrappers — `@specialize` is the local opt-in, this is the global default.

- [~] **(orig) Self-host closure capturing two free vars segfaults at runtime** (2026-05-25). While simplifying `vader/typecheck/orchestrate.vader::pull_referenced_external_types` to route through the canonical `for_each_type` walker, replacing the explicit recursion with `for_each_type(t, (sub: Type) -> register_named_external(sub, entry, per_module))` made the self-host binary SIGSEGV (exit 139) at the first call. The only prior closure-with-capture in the tree (`vader/midir/lowered_walk.vader:222`) captures a single `ctx` struct ; my version captures two free vars (`entry: TypedProgram` and `per_module: MutableMap(string, TypedProgram)`). Reverted to explicit per-variant recursion with a code comment pointing at this entry. Probable root cause : `vader/lower/closure_analysis.vader` + `LoweredMakeClosure` emit doesn't handle the second captured slot correctly, or the `$Cell_T` synthesis miscomputes the layout. Repro path : restore the `for_each_type` form at `orchestrate.vader:758` (see git history of the 2026-05-25 fix commit), rebuild, run `./build/vader dump --stage=typed-ast vader/cli/main.vader`. Until fixed, prefer the explicit walker shape OR bundle captured state into a single struct (the lowered_walk.vader pattern).

#### Language ergonomics surfaced while porting the typechecker — open

#### Typechecker port follow-ups — open
- [~] **(orig) Codegen: narrowed scrutinee miscompiles when an arm writes through it
      AND reassigns it** (2026-06-05). In `match cur { is Entry<K, V> -> { … } }`
      where the arm BOTH writes through the narrowed node (`cur.next = x`) AND
      reassigns the scrutinee (`cur = nxt`) in the same arm, a read of the
      narrowed `cur` (e.g. `cur.key`) compiles to a null deref — the emitted box
      reads the wrong field (observed tag = pointer low bits). Surfaced writing
      `MutableMap.grow` (the resize chantier) ; worked around with an `as e`
      alias (`stdlib/std/collections/collections.vader`), reading/writing through
      the stable binding instead of `cur`. The sibling walks (`put` / `get` /
      `remove`) are unaffected — they reassign `cur` only after the last read.
      Real fix is in the narrowing → c_emit path : a flow-narrowed local that is
      reassigned later in its block must keep the narrowed representation for the
      reads that precede the reassignment.

#### Vader-as-test-oracle migration follow-ups — open
- [ ] **`dump --stage=cfg` elides stdlib by default — revisit** (2026-06-05).
      The oracle migration made the native CLI the snapshot source for cfg ;
      `run_cfg_stage` (`vader/cli/main.vader`) now bakes in a stdlib-excluding
      `include_module` + `include_strings=false` so cfg snapshots stay focused
      (else stdlib CFG bloats them ~10×). PROVISIONAL : decide whether stdlib
      elision should be a `--stdlib` opt-in flag on `dump` rather than the baked
      default, so the CLI can still show the full CFG when wanted.

- [ ] **`a == b` on user structs → `a.equals(b)` lowering at typecheck** — the expected lowering records the synthesised CallExpr / FieldExpr in `expr_types` at the BinaryExpr's span so the dump shows `bool` / `fn(Money) -> bool` / `Money` entries even though the source is just `a == b` (the TS reference impl did this). Self-host returns plain `bool` without the synth entries. Blocks `op_overload_eq_ord` lower-parity.
  - **Investigation 2026-05-26** : the visible divergence is downstream of a deeper issue. Vader's `materialize_default_members` runs at typecheck time (`vader/typecheck/orchestrate.vader:513`) AFTER the resolver, so cloned `self` / `other` IdentExprs in the materialised body keep trait-source spans that aren't bound in the impl module's `resolved.idents`. The fix shape : run materialization at resolver time, INSIDE impl resolution (a `resolve_impl_decl`-time hook in `vader/resolver/resolve.vader`), so the cloned body gets walked + bound there. Effect : Vader's `lower_ident` hits `unresolved ident self` on every cloned receiver, the materialised fn dumps as `:?` everywhere, and the `a == b` → `a.equals(b)` rewrite degrades to a `.equals` FieldExpr call against an unreachable `self`. **Same root cause also blocks `custom_iter` / `custom_iter_generic` / `iter_defaults` / `trait_dispatch_generic_iter` / `for_in_iter_trait` lower-parity** (those pass typecheck-snapshot parity per the row above, but their lower.snapshot still diverges on the materialised-body `:?` entries). Proper fix : move `materialize_default_members` to a project-level resolver post-pass that knows the trait_decl (cross-module lookup) and walks the cloned bodies through the resolver to mint Local symbols + bind their cloned spans. Add a `find_foreign_ident_sym` in `vader/lower/lower_expr.vader` so lower can fall back to the trait module's `idents` when the impl's map misses. Multi-day chantier. A local fix attempt (walk materialised body silently at typecheck) regressed 5 tests with bogus `:?` entries — reverted.

#### Bugs surfaced by exhaustive CLI dump 2026-05-18 — closed

Audit summary : ran `./build/vader dump --stage=typed-ast` on every `.vader` file under `stdlib/` + `vader/` (118 files). Initial sweep showed 147 errors across 6 files (much was cascade noise from a single root cause). Eleven commits across the day closed the lot ; the final post-fix sweep showed 0 errors across all 118 files. Bucket ledger :


### 2.6b Self-host perf — pistes restantes (post-2026-05-22)

Four perf landings in the 2026-05-22 session brought the typecheck-port
bootstrap from "unusable" (eval_types.vader OOM, 9/17 broad-parity modules
timeout) to working in 3.2 s for the full broad-parity suite. Remaining
pistes, ranked by likely payoff. **Reprofile first** (`/tmp/vader_perf`
with -O2 -g + `sample`) — the hot path has moved several times already.

#### Reprofile 2026-06-17 (`dump --stage=c vader/cli/main.vader`, `-O2 -g` + `sample`, 256/512 MB)

Wall ~8 s, peak RSS 1.12 GB. Self-time is **~74 % substrate, not pass logic**: **GC+alloc
~34 %** (`vader_minor_collect` 14.7 %), **string Hash + atoms ~27 %** (`string_Hash_hash`
11.8 %, `atom_intern` 8.3 %), **MutableMap ~13.5 %** (keys()/values() materialize). Live-set:
**ARRAY_BUF 266 MB / 937k = 42 %** (MutableMap backing), 72-B structs ~120 MB, atom table
249k / 39 MB. Four optimization tracks (ideas 1-4):


- [ ] **(idea 3) Int-keyed side-tables → flat array / `IntMap`** (**to discuss**). Dense
      `Symbol.id`-keyed maps want a flat `T[]` (or `IntMap` for sparse) — cheaper CPU + RAM.
      Crux from `project_compiler_intmap_b`: does the value de-erase. Overlaps the "shrink
      live-set" lever (b).

- [~] **(idea 4 — umbrella) Cut allocation volume → shrink the GC ~34 %** — ~37M objects/build;
      `minor_collect` 14.7 % even at big arenas. Driven by ideas 1/2/3 + `span_key` minting +
      per-block `out.push`. No single fix; landing 1/2/3 reduces it. Reprofile between rounds.

#### Runtime GC


- [~] **Shrink the self-compile live set** (re-profiled 2026-06-05). At the
      **bytecode stage** (`VADER_GC_PROFILE=1 … dump --stage=bytecode
      vader/cli/main.vader`, arenas young 256 MB / old 1536 MB) the live set is
      **~498 MB** (122 MB young + 376 MB old) — the pipeline's high-water mark,
      vs **81 MB** at typed-ast (the working-set item in §3.5). **71 %** of it
      is `MutableMap` machinery :
      - **ARRAY_BUF — 776 k buffers / 236.7 MB** (#1, 47 %) : variable-sized
        backing storage — `MutableMap` bucket arrays + arrays + string bytes.
        (The profiler mislabeled this bucket `?` / `type_index 1343` — the
        ARRAY_BUF sentinel sits at index `vader_type_info_count` and the display
        only matched the `VADER_TYPE_INDEX_ARRAY_BUF` header tag. Fixed in
        `runtime/c/vader_runtime.c::vader_gc_profile_dump`.)
      - **`Entry<Any, Any>` — 1.61 M × 72 B / 116 MB** (#2) : every `MutableMap`
        entry node, erasure-deduped to a single C type.
      - rest (~145 MB) : compiler IR (Position / Span / Type / CFG).

      Root cause is **cross-pass retention**, not the emitter : `run_source`
      (`vader/cli/main.vader:248-264`), `run_cfg_stage` and
      `run_legacy_bytecode_stage` keep the whole `pipeline`
      (`loaded` + `typed` + `evaluated` — every per-module side-table
      `MutableMap`) live through the entire lower → cfg → dce → escape → emit
      tail ; its only post-lower use is `entry_main_name(pipeline.typed,
      pipeline.loaded.entry)` at `:257`. So the typecheck-era maps coexist with
      the emitter's own tables at the peak. Candidate levers : (a) **DONE** — `run_source` now calls `lower_to_entry`,
      which drops the `typed` / `evaluated` / `loaded` pipeline before the
      CFG→emit tail ;
      (b) shrink the maps — span-key→i64, flat `Type[]` for dense `Symbol.id`-
      keyed maps, `IntMap(V)`, small-map specialisation (detailed under the §3.5
      working-set-reduction item). Orthogonal to the GC-arena-growth item above
      (that fixes the OOM trap, this shrinks what's retained).

#### Lower

- [ ] **Pre-allocate `stmts: LoweredStmt[]` in `lower_block`**
      (`vader/lower/lower_expr.vader:1929`). The `[] = []` + repeated
      `out.push` pattern grows by doubling, causing log-N realloc
      copies per block. Knowing `block.stmts.len()` upfront lets the
      caller reserve capacity. Requires either a stdlib `with_capacity`
      helper or a runtime intrinsic — same surface as the `pop` note
      in §1.11. ~187 sites in the lower/typecheck use the
      `T[] = []` shape ; this one fires per-block.

#### Typecheck


#### Algorithmic / data-structure

- [ ] **MutableMap small-map specialisation** — `std/collections.vader`
      uses chained HashMap with fixed bucket count. For the many
      maps that hold < 8 entries (per-module symbol caches, narrowing
      bindings, …) the bucket array + chain is overkill. A "small
      map" inline-array variant (linear scan up to N entries before
      switching to buckets) cuts allocation count.

### 2.7 Bootstrap success check — done (C-seed fixed point)
The original TS-compiler bootstrap path was superseded by the C seed.

### 2.8 Freeze the TS compiler — done

---

## Phase 3 — Post-MVP

### 3.1 Concurrency — partial
> Shipped: `async` / `await` keywords + state-machine lowering (`vader/lower/lower_async.vader`, `__asyncstate_<n>`; 20+ `async_*` snippets); cooperative single-threaded scheduler (`stdlib/std/async/async.vader`, strict-FIFO ready queue + timer min-heap).
- [ ] (Stretch) Kotlin-style coroutines — user-visible CPS coroutines (`lower_coroutine.vader` today is internal shared infra only).

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
> Shipped: generational GC + card table, GC robustness under string-alloc / array-doubling pressure, whole-program DCE, `match enum → switch` static lookup tables, peephole temp-elimination, hash-cons `Type` + WeakMap registries, iterator-chain fusion, inline small tagged unions, inline `MutableMap`/`MutableSet` for-in, inline trivial trait-method impls (`vader/lower/inline.vader`).
- [ ] Direct-ASM backend for one native target (validate the design).
- [ ] Escape analysis enabled (lower allocations on stack when proven safe).
- [ ] **Bytecode cache on disk** — to discuss / dimension. Today every `vader run` / `vader fmt` / `vader-lsp` re-parses + typechecks + lowers the full stdlib (~30 modules) before the VM executes a single instruction (~2-3 s for the formatter). Proposal : serialise per-module `LoweredModule` to a `.vbc` sidecar keyed by `(source_hash, compiler_version)`. Open questions : (a) serialisation format (binary vs MessagePack vs IR text), (b) cache invalidation across transitive deps (changing `std/core` busts every consumer), (c) interaction with `--target=native` C-emit, (d) interaction with comptime values (memoise too?). Stay VM-only for now — AOT is deliberately out of scope.
- [~] **Lazy-materialise stack values in C-emit** (companion to DCE). Today's wins target primitives ; `local.get`/`local.tee` of ref/any still snapshot eagerly into a refTmp for GC-precision. Future : (1) detect call-arg pairs with no allocation, (2) skip explicit zero-init for primitives, (3) pre-declare blockres slots on first use. Each ~½ day.
- [ ] **Value-type structs (`CodeInfo`-style)** — open discussion. Today every struct is heap-allocated + boxed. For small immutable structs never trait-boxed (e.g. `CodeInfo { id: string, message: string }`), a register-by-value pass would be free. Trade-offs : (a) syntactic distinction (`value struct` keyword? `@value` decorator? auto-detect?) ; (b) interaction with `is Trait` (value-types can't downcast — compile error?) ; (c) match patterns binding by reference ; (d) multi-register return ABI ; (e) escape analysis as a downgrade path. Decision needed before implementation.
- [~] **Self-host typecheck working-set reduction** (profiled 2026-05-25). `VADER_GC_PROFILE=1 ./build/vader dump --stage=typed-ast vader/cli/main.vader` over the full self-host project (170+ modules transitively imported) reports an **81 MB live set** dominated by :
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
  - **(a) Split C emission per Vader module + drive `cc -j`** — **DONE** as the opt-in `--parallel[=N]` multi-TU emit (`vader/cli/main.vader`; 29.9→9.0 s locally). Default mono build stays byte-identical. Unlocked parallelism + `ccache` for iterative rebuilds; levers (b)/(c)/(d) below remain.
  - **(b) Pre-compile stdlib monomorphisations to `.o`** — once-per-toolchain artefact cached on disk ; user-CLI rebuilds only re-cc user TUs. Depends on (a) for the TU split.
  - **(c) Type-erase non-perf-critical generic containers** — **paused 2026-05-19 via option (Φ)**, see `docs/STDLIB_GENERIC_COLLAPSE.md` Decision log. Shipped sub-deliverables : Phase 0 (`4f639e99`) vtable runtime + slot registry + internal `Any` Type kind ; Phase 1 (`0d9ebc80`) packed inline-box multi-field POD ≤ 16 B ; β raw-array for-in fix (`aa2dc5ce`) ; Phase 2 plumbing (`9b38e860`, `ef76fe6f`) committed but gated off. Phase 2 §9 documents 9 cascade issues encountered ; the cascade is fundamental (Any-bearing queries against `@specialize`d types' concrete-arg registries), so full automatic erasure deferred to a future investigation with a different design (option (γ) "synthesise Any-bearing instances for every `@specialize`d reachable type" estimated 3-5 d, worth pursuing only when cc -O3 baseline becomes a workflow blocker). Iterator-skip `@specialize` decorator landed in the same arc.
  - **(d) `__attribute__((cold))` on rarely-hit generated fns** — calms the inliner / frees IPSCCP budget. Candidates : error paths, diagnostic builders, init-only helpers. Touches `vader/c_emit/emit.vader`. Smallest expected win — measure on a smaller TU first since the structural-pass dominance pattern caps the ceiling.

### 3.6 Memory model extensions
- [ ] Explicit allocator API (arenas, pools) for perf-critical paths.
- [ ] `unsafe { }` blocks for low-level FFI.

### 3.7 Tooling
> Shipped: LSP server in Vader (`vader/lsp/`) — diagnostics, hover, go-to-def, completion, references, typeDefinition, documentSymbol, documentHighlight, foldingRange, documentLink, signatureHelp, inlayHint, formatting; VS Code extension (`editors/vscode/`).
- [~] **LSP completeness roadmap** (added 2026-06-07) — plan in [`docs/LSP_COMPLETENESS.md`](./docs/LSP_COMPLETENESS.md). Takes the server from core navigation to feature-complete : shared infra (project-wide reference index, workspace-symbol index, cross-file diagnostics, file-watch, incremental analysis) then the feature tiers — quick wins (`documentSymbol`, `formatting` via the existing `vader/fmt`, `documentHighlight`, `foldingRange`, `documentLink`), navigation (`references`, `workspace/symbol`, `typeDefinition`, `implementation`, `callHierarchy`), productivity (`codeLens` run-test, completion docs, `linkedEditingRange`), and protocol modernization (pull diagnostics, incremental sync). Sequencing + per-feature code hooks in the doc. Cross-ref the `LSP code actions framework`, completion, rename, and find-references items.
- [i] **LSP : spurious L0005 "character literal must contain exactly one codepoint" on `'é'`** (investigated 2026-06-17, *not a current-compiler bug*). Reported on `stdlib/std/string/string.vader:907` (`assert_eq(byte_decode_at("héllo", usize(1)), 'é')`). The on-disk literal is precomposed é — bytes `27 c3 a9 27` = `'` + U+00E9 + `'`, a single codepoint — and the current compiler accepts it : `dump --stage=ast` reports **zero** `error[L0005]` on the file, the isolated literal lexes clean, and the full suite (which runs `test_byte_decode_at`) is green. `lex_char` advances by `codepoint_byte_len` (since 2026-05-15, `dc457047`), so multi-byte single-codepoint literals have always been valid. The live editor error is therefore either (a) a **stale LSP server** running an older in-memory binary — reload the window so it picks up the freshly-built dist binary, or (b) the unsaved buffer holds a **decomposed** é (NFD : `65 cc 81` = `e` + combining U+0301 = *two* codepoints), which the lexer correctly rejects even though it renders as one grapheme. **Optional UX follow-up** : when a char literal is a base char + ≥1 combining mark, emit a clearer L0005 hint ("looks like one character but is N codepoints (NFD); use the precomposed form or a string") instead of the bare codepoint-count message.
- [~] **LSP : inconsistent semantic highlighting** (noted 2026-06-15) — the syntax/semantic colouring isn't always consistent ; observed on `self` in `stdlib/std/core/primitives.vader`'s `Hash` impl block (`i8 implements Hash -> u64(self)` etc.) — `self` is highlighted/underlined inconsistently across otherwise-identical lines, and `isize` picks up a spurious squiggle. Revisit when reworking the LSP (likely the semantic-tokens classifier mis-scoping `self` / a stale diagnostic on `isize`).
- [ ] **LSP : index fn-param + type-param *declarations* for rename / references** (noted 2026-06-17). The reference index (`vader/lsp/analysis/reference_index.vader::build_reference_index`) collects fn-param and type-param **uses** but not their **declarations** : `FnParam.span` / `TypeParam.span` cover the whole `name: Type` slot, too wide to use as a precise rename target or reference range (collecting them would make prepareRename select `a: i32` and rename's text-guard skip them anyway). Consequence : renaming from a parameter (or type param) rewrites its uses but leaves the `name` in the declaration untouched ; references on a param decl name finds nothing. Locals / for-/match-bindings already work (their `SimpleBinding.name_span` is name-only). Fix : derive a name-only span for the param/type-param (the name sits at `span.start`, length `len(name)`) — but the body-walker keys `idents` by the wide `p.span` (`vader/resolver/body.vader`, `bind_fn_param` / `mint_local` on the TypeParam path), so either re-key that `idents` entry by the name-only span, or record the name-only span and reconcile at lookup. Until then, param/type-param rename is uses-only. Cross-ref the reference-index + rename items above.
- [~] **LSP : reconcile semantic tokens with the TextMate grammar** (added 2026-06-07). Opening a `.vader` file shows a visible color flash : the editor first paints from the static TextMate grammar (`editors/common/vader.tmLanguage.json`), then the LSP's semantic tokens (`vader/lsp/handlers/semantic_tokens.vader` /
`handlers/ast_tokens.vader`) arrive a beat later and recolor. Root cause : the grammar classifies by **syntactic shape** (everything gets a colour on open), while the LSP classifies by the **resolved Symbol kind** (`handlers/ast_tokens.vader::token_type_of_symbol`) and falls back to `Variable` whenever a name doesn't resolve — so anything the resolver misses degrades to the variable colour (and LSP4IJ underlines it). Concrete divergences observed on `vader/lower/lower_intrinsic.vader` :
  - **Three divergences closed 2026-07-26.** (a) String / char literals emit no semantic token, so TextMate keeps them *and* their escapes (`classify_token` → `-1`). (b) `function` and `type` also yield to the grammar (`VaderSemanticTokensFeature` returns `null`): LSP4IJ's default maps them to `FUNCTION_CALL` / `CLASS_NAME`, keys themes leave at the plain foreground, whereas the grammar's `entity.name.function.call.vader` / `entity.name.type.vader` / `support.type.primitive.vader` ARE coloured — so call sites and type names went white while the grammar could paint them. (c) Struct fields are their own `Property` token and module consts carry `static readonly`, instead of both falling into the `Variable` catch-all whose LSP4IJ fallback is `REASSIGNED_LOCAL_VARIABLE` — a key IntelliJ UNDERLINES, so every field and constant read as a reassigned local. **Still open:** the load-time flash, the `Variable` fallback on names the body-resolver can't see (needs §1.13d), and locals themselves still taking that underlining key — emitting `readonly` on `::` bindings would fix the last one and turn the underline into a genuine `:=`-detector (designed, not implemented). One more small follow-on: `Mode.Fast` is tagged `Property` rather than `EnumMember` because `body.vader`'s `FieldExpr` arm only recurses into the target and never records anything keyed by `field_span` — recording one when the target resolves to a type-kind symbol would close it (`Prof.CONST` needs cross-module wiring and stays out of reach).
  - **Function / method calls** — grammar tags `ident(` and `.ident(` as `entity.name.function.call` (`vader.tmLanguage.json:369-379`, the blue). The LSP only emits `Function` when the callee resolves to a `Fn` / `BuiltinFn` Symbol ; an unresolved callee — a **sibling-file fn of the same module** (`lower_expr`, `resolve_field_type`, `try_fold_static_intrinsic`) or a **method / UFCS call** — hits the `Variable` fallback (`ast_tokens.vader:130`), so the call loses its function colour after parse.
  - **UpperCamelCase identifiers** — grammar colours **every** `[A-Z]…` word as `entity.name.type` unconditionally (`vader.tmLanguage.json` "Type names" rule). The LSP emits `Type` only when the name resolves to a type-kind Symbol ; an unresolved type name flips to `Variable`.
  - **Locals / params / fields** — grammar leaves them default ; the LSP emits `variable` / `parameter` tokens (+ LSP4IJ underline decoration), so they gain colour + underline after parse.
  Fix direction : make the semantic-token walker mirror the grammar's syntactic fallback instead of `Variable` — emit `Function` for a callee in `ident(` position and `Type` for an UpperCamelCase name even when the Symbol doesn't resolve (sibling-file / cross-module), so the post-parse colour matches the on-open colour. Equivalently, never downgrade to `Variable` a token the grammar already colours as function/type. Touches `ast_tokens.vader` (the `token_type_of_symbol` fallback + the call / UFCS classification), `semantic_tokens.vader`, the legend advertised at `initialize`, and possibly `vader.tmLanguage.json` if any category is better dropped on the grammar side.
- [x] **`!is` / `!in` operators now highlighted** (2026-07-18). Added a `!is` pattern to the TextMate grammar (`editors/common/vader.tmLanguage.json`, synced to `editors/vscode/syntaxes/`; IntelliJ copies from common at build time) — `!in` already had one. LSP side: `semantic_tokens.vader::collect_token_kinds` now paints a `!` (Bang) immediately followed by `is`/`in` as a Keyword instead of an Operator, so the negated operator colours as one unit (the semantic layer overrides TextMate). Test `test_bang_is_in_paint_as_keyword`.
- [ ] **`vader doctor --json`** — environment + toolchain sanity check emitting a structured report : `bun` / `cc` / stdlib paths discoverable, `runtime/c/` present, `vader.json` schema valid, GC env-vars in range, comptime cache writable. Two output modes : human-readable text (default) and `--json` for agent / CI consumption. Lives in `vader/cli/doctor.vader`. Cheap to ship and pays for itself the first time a fresh clone fails opaquely.
- [ ] **Structured `repair.id` field on diagnostics** — every entry in `vader/diagnostics/codes.vader` gains an optional `repair: { id: string, ... }` describing a deterministic fix that an LSP code-action or an LLM can apply. Examples : `R2003 unknown identifier → repair.id = "declare-missing-symbol"`, `T3007 missing field → repair.id = "add-field-default"`, `T3019 wrong arity → repair.id = "insert-trailing-arg"`. Surface in both `--diagnostics=json` output and `textDocument/codeAction` LSP responses. Start with the 5-10 highest-frequency codes ; the repair *implementation* can land later — the *contract* is the value. Cross-ref §1.0.
- [ ] Programmable build API (`build.vader` instead of `vader.json`).
- [ ] **Multi-library namespaces** — `STDLIB_PATH_PREFIX = "std/"` is hard-coded today. Generalise to a registry of `prefix → on-disk root` fed by `vader.json` (e.g. `{ "libraries": { "web": "./vendor/vader-web", "experimental": "./libs/exp" } }`). Use cases : (a) third-party libs via a package manager, (b) compiler-private namespace (`internal/`) with a "stdlib + compiler only" rule, (c) workspace monorepos. Touches `resolveImportPath`, `isStdlibModule`, DCE filter, dump-stage filters. ~150 lines + manifest schema bump.
- [ ] External package manager + central registry (much later).
- [ ] `man` page for `vader`.
- [ ] **GitHub Release on tag push** — attach `dist/vader-*.tar.gz` and `dist/vader-*.zip` to a release on `v*` tag push (`softprops/action-gh-release` or `gh release create`). `permissions: contents: write`. Auto-generate notes from commit log between tags.
- [ ] **GitHub Actions matrix per OS** (post self-host) — fan out to `ubuntu`/`macos`/`windows` runners that each run `bun test` on their native binary and assemble locally.

### 3.8 Language ergonomics
> Shipped: UFCS on union receivers, cross-module type-alias unions, codepoint-first `string` model + non-owning array slice views, literal-value match patterns, `enum`→int cast, implicit `void` return, auto-`.iter()` for-in, trait-object boxing + dynamic dispatch, operator overloading via traits, `Into[Target]` auto-coerce, expression-bodied fns, struct spread / field defaults, tuples + destructuring, comptime tuple/struct/array values, spread destructuring, `std/process.spawn`, inline `@file`, implicit selector expressions, `@assert` / `@partial` / `@deprecated`.
- [~] **`defer` unwinds on panic** (gap surfaced 2026-05-19) — **VM DONE, C target pending.** Defers lower to per-frame `DeferPush` / `DeferPopExec` ops; on a trap the **VM now walks frames bottom-up and drains each frame's pending defers before propagating** (`vader/vm/exec.vader:1008`). Remaining: the **C target** still raises without unwinding (`runtime/c/vader.h` setjmp/longjmp work pending), so native panics skip defers — files left open, locks held. Same fix unlocks a future `recover` / `rescue` primitive. Cross-ref §3.1 Concurrency (panic propagation across spawned tasks).
- [ ] Static-size arrays `[T; N]`.
- [x] Pattern matching extensions — **or-patterns** (`OrPattern` ; `'a' | 'b'` / `.A | .B`, `4d097749`) + **range-patterns** (`RangePattern` ; `'a'..='z'` / `0..<10`, both `..=`/`..<`, char + int, 2026-07-24 ; snippet `match_range_pattern`).
- [ ] **`match <expr> as name { … }` — bind the scrutinee once instead of aliasing every arm** (noted 2026-07-27, user taste item). A `match` over a **slotless scrutinee** — a call, overwhelmingly — forces an `is T as alias` on *every* arm, and the aliases neither share a name nor align, so readability degrades with the arm count (real site: `examples/brainfuck/brainfuck.vader`, `is Ok as ok -> ok.value` / `is Trap as t -> … t.message`). **The gap is the missing slot, not the narrowing**: `infer_match` (`vader/typecheck/match_expr.vader:49-50`) computes a `scrut_sym_id` / `scrut_field_key` and pushes the per-arm narrow onto it, so when the scrutinee already *is* a slot the alias is unnecessary today — `r :: run(5)` then `match r { is Ok -> r.value ; is Trap -> r.message }` compiles and runs (verified 2026-07-27). A call expression has no slot, hence the per-arm ceremony. The proposal is sugar for "give the result a slot":
  ```
  return match exec(prepare(module), []) as result {
      is Ok   -> result.value
      is Trap -> {
          eprintln("brainfuck: vm trap — ${result.message}")
          1
      }
  }
  ```
  semantically the hoisted `result :: exec(…)` + `match result`, without lifting the temporary out of the expression. **Parse is free**: `as` never continues an expression (`vader/parser/parser.vader:2568` `no_infix()`, precedence `-1` at `:2654`), so `match <expr> as name {` is unambiguous. **Implementation surface**: an optional `binding: SimpleBinding | null` on `MatchExpr` (`vader/parser/ast.vader:638`) → resolver mints the Local + binds `name_span` → typecheck points `scrut_sym_id` at that local instead of deriving it from the scrutinee expression (the `push_narrow` / `pop_narrow` arm loop is then unchanged) → lower stores the scrutinee into the local once and matches on it → fmt + LSP (semantic token, hover, rename on the new name). Guards need nothing: the arm narrow is pushed *before* the guard is checked (`match_expr.vader:71-93`), so `match e as r { is T if r.n > 0 -> … }` types.
  **Decision (user, 2026-07-27): the per-arm alias goes away — the two forms do NOT coexist.** `match … as name` *replaces* `is T as x ->`; that settles the coexistence question above (no shadowing rule, no diagnostic needed — the arm-level `as` simply stops parsing). Consequences:
  - **Removal surface**: `IsPattern.bind_as` (`vader/parser/ast.vader:787`) + its parse (`parser.vader:3572-3573`), the binding arms in `bind_pattern_types` (`vader/typecheck/match_expr.vader:377-392` — `local_types` / `narrow_binding_scrutinee` keyed on the binding span), lower, fmt, LSP, the AST dump + every affected snapshot. `IsPattern.inner` stays (the nested-pattern combination is orthogonal). **Out of scope, kept**: the *expression*-level `if x is T as b` (`parser.vader:2806-2808`) — a different surface, and it has no `match` to hang a global binding on.
  - **Sweep size, measured 2026-07-27**: ~**2530 arm-alias sites across 159 files** (`vader/` 2431, `stdlib/` 59, `tests/` 38, `examples/` 4). Well past the hand-fix threshold, so this one *does* want a real compiler-assisted rewriter — and note it is **not** a `sed`: each arm body's uses of the old alias must be renamed to the single global name, which is a per-arm rename, not a line rewrite. (`vader fmt` is not a migration tool.)
  - **Naming trade-off to weigh at scoping**: today's aliases are often per-variant and meaningful (`is StructType as s` / `is ArrayType as a` / `is TupleType as p`); one global name is uniform but flattens that. The big Type-IR matches in the compiler tree are where it cuts both ways — pick the global names deliberately during the sweep rather than mechanically.
  - **The old `_ as e ->` idea is dropped as obsolete** (user, 2026-07-27). It was itself a per-arm binder, and the match-level binding is strictly better: `match x as e { … _ -> e }` needs no arm-level spelling at all. Do not revive it.
  - **Also decided (user, 2026-07-27): the bare-identifier catch-all arm goes with it.** `e ->` (a lone name binding the whole scrutinee) is the last surviving per-arm binder and is redundant with `_ ->` + the global name, so it is removed in the same landing — patterns become purely structural, one way to bind, no exception. Call-site cost is trivial: **5 real arms** (measured 2026-07-27 — 4 in `vader/lsp/analysis/indexer.vader`, 1 in `tests/snippets/match_wildcard_narrow/`; the `true ->` / `false ->` arms are *literal* patterns, not this form). Removal surface: drop **`BindingPattern`** (`vader/parser/ast.vader:816`) from the closed `Pattern` union (`:35`) and its parse; 23 references across 13 files (`fmt/printer`, `parser/{parser,dump,assign_ids}`, `resolver/{body,substitute_body}`, `typecheck/{match_expr,dead_code}`, `lower/{lower_match,closure_analysis}`, `lsp/{reference_index,ast_tokens}`). Removing a variant from a closed union makes the compiler enumerate every site for you (T3013 at each exhaustive `match`), so this half is compiler-guided rather than grep-guided — the opposite of the 2530-site alias sweep above.
  - **Docs**: `SPEC.md` in the same commit, and `.claude/CLAUDE.md` §6 currently *prescribes* `is TypeName as alias` — it has to be rewritten in the same landing. Language surface → review with the user before implementing (§8).
- [x] **Destination-passing in `build_if` generalised, `else_chain_if` retired** (2026-07-25, follow-up to the match-lowering density optim). `build_expr_into(fn_ctx, e, dest)` + `build_block_into` thread a result slot through any nesting of `if` / block / `match` by mutual recursion, so `build_if` coalesces its arms shape-independently (both then and else branches, not just the `{ stmts: [], trailing: LoweredIf }` else-chain the deleted `else_chain_if` matched). Second consumer wired: `LoweredLet` with an `if` / block value builds straight into the let's slot (declare-first), eliding the `if_res` temp + copy (`let g = match … ` → 0 extra locals). `LoweredReturn` is not a consumer — it hands its value to `TermReturn`, no destination slot. Broad but behaviour-preserving IR drift (VM parity + native run oracle green).

- [x] **Destination-passing extended to short-circuit `&&` / `||`** (2026-07-25). `build_short_circuit` (`vader/midir/build.vader`) — the third phi-slot builder — gained a `dest: LocalId | null` param symmetric to `build_if`, is admitted in `build_expr_into` (short-circuit `LoweredBinary` arm) and the `LoweredLet` gate, so `let x = a && b` / an `if` arm `{ a && b }` writes straight into the destination (`and_res` / `or_res` temp + copy elided ; `let ok = a > 0 && b > 0` → one fewer local). The dest-passing shape set `{if, block, short-circuit-binary}` now lives behind one `is_dest_passing_shape` predicate the `LoweredLet` gate consults ; `build_expr_into`'s dispatch mirrors it (a drift there can only miss the optimisation, never miscompile — the generic tail is a correct fallback).

- [ ] **Range / literal pattern bound typing — two unenforced checks** (surfaced 2026-07-24 reviewing range-patterns). Both are *pre-existing* to literal patterns, not introduced by range-patterns, but now doubled : (a) **bound-vs-scrutinee mismatch** — `check_pattern_bound_exprs` (`vader/typecheck/match_expr.vader`) types each literal/range bound with `null` expected, never against `scrut_ty`, so `match n: i32 { 'a'..='z' -> … }` (char range on an int scrutinee) is silently accepted — below Rust parity (E0308). Fix : pass `scrut_ty` as the expected type ; caveat — `scrut_ty` can be a union, so it's not a one-liner. (b) **inverted range** — `'z'..='a'` (lower > upper) lowers to a statically never-true `>= 'z' && <= 'a'` with no warning ; Rust warns. Cheap constant-fold check (both bounds are required literals). Also correct the stale comment in `tests/snippets/match_literal_patterns/_main.vader` claiming the typechecker pins the literal's type to the scrutinee — it does not (passes `null`).
- [ ] `@derive(Eq, Display)` to auto-generate trivial impls.
- [ ] **Function overloading by full signature** (post-MVP elevation of receiver-only overloading) — pick the candidate whose *all* parameter types match. Generalises the resolver's overload table + typechecker's call resolution.
- [~] **Generator functions (`@generator` + `yield`) — lazy element-by-element iteration.** **Phases 0-4 LANDED 2026-07-01** (`.claude/plans/2026-07-01-generator-functions-yield.md`) — the feature is functionally complete for v1 (non-generic / concrete-element generators). Surface (`yield` keyword + `YieldStmt` + `@generator`), typecheck (T3056–T3061), and the state-machine lowering (`vader/lower/lower_generator.vader`: spill params+locals into a synthesized `g$State`, route refs to `self.<field>`, block-split the body into a `loop { if state==k … }` `Iterator::next`) all run correctly on **both backends** for straight-line yields, single + nested loops, break/continue across a yield, yield-in-if/match, and struct element types. Feature snippets `generator_{basic,nested,filter,break,struct_elem}` + LSP `YieldStmt` arms. `verify.sh` green throughout, suite 2493/0. **Remaining (`[~]` → Phase 5, DEFERRED):** dogfood on hot self-compile paths, generic generators (blocked on the pre-existing erased-generic vtable gap), and fusion/caller-monomorphization — all gated on `2026-07-02-stream-fusion-generalization.md` Couche 4 (the erased `next()` is a per-element virtual call). Below is the original design note.
  ```
  @generator
  concat_file_decls :: fn(files: SourceFile[]) -> Iterator<Decl> {
      for f in files {
          for d in f.program.decls { yield d }
      }
  }
  ```
  **Resolved:** the Phase-0 cascade spike chose approach **B** (an AST/lower desugar to a `loop { match state }` state machine, synthesized as a `LoweredLoop` + `i32` if-chain since there's no `LoweredMatch` node) and validated its output shape on both backends before implementation. Perf (per-element virtual dispatch on the erased `Iterator<T>`; fusion + caller-monomorphization) and migration (callers needing `.len()`/indexing break; audit before converting) remain the deferred Phase-5 work.
- [~] **Stream-fusion generalization — lazy iterator chains → the eager loop** (perf; plan `.claude/plans/2026-07-02-stream-fusion-generalization.md`). Both the eager combinators (`arr.map(f).filter(p)` = a throwaway array per stage) and the lazy ones (`MappedIterator`/… = a tower of erased trait-object iterators, virtual `next()` + boxed `Yield<T>` per element under erasure) collapse to one flat loop via fusion. `try_lower_chain_fusion` (`vader/lower/lower_for_in.vader:889`) already does this but ONLY for int-range sources, `map`/`filter`, and `for-in` terminals. Widen it: Couche 1 array/string/map-set sources (+ a concrete `arr.iter()` — none exists today, only erasing `.into()`), Couche 2 `take`/`skip`/`enumerate`/`flat_map`, Couche 3 recognize `.collect()`/`.count()`/`.any()`/`.fold()`/… terminals at the call site (synthesize their accumulation as the fused body), Couche 4 inline `@generator` yield-loops. Independent of generators for Couches 1-3 (bulk of the win); Couche 4 + the combinator-struct→`@generator` rewrite (Tier 1: Mapped/Filter/Take/Skip; Tier 2: Map/Set near-vestigial; Tier 3 keep ArrayIterator/StringChars as primitives) come after generators. Enablers: `arr.iter()`, harden generic-HOF lambda inference (works-but-untested + silent mistype today), explicit concrete chain heads for Map/Set/String (UFCS Into gate is array-only). Measure alloc volume, not RSS (short-lived allocs = profiler blind spot).

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
- [ ] **Memory ops map 1:1 — but pin down endianness and `align`** (noted 2026-07-27). The whole `Load*` / `Store*` / `MemoryCopy` family has a direct WASM counterpart (`i32.load8_u`, `i32.load`, `i64.store`, `f64.load`, `memory.copy`), and WASM permits UNALIGNED access, which matters since a `Buffer` offset carries no alignment guarantee. Two decisions for the emitter: (a) WASM memory is little-endian by spec while the C backend follows the machine — so the two backends only agree as long as no big-endian target exists, which is an argument for naming endianness in the stdlib surface rather than in the opcode (see `std/encoding` under §1.13); (b) what to put in each `memarg`'s `align` — 1 (always safe, possibly slower) or derived from the offset when statically known.

---

## Reference

- `SPEC.md` — language specification (target reference)
- `examples/` — working programs
- `stdlib/` — standard library source (Vader)
- `vader/` — the self-hosted Vader compiler (lexer, parser, typecheck, lower, midir, bytecode, c_emit, vm, lsp, fmt, cli)
- `tests/` — snapshot tests
- `docs/IMPROVEMENT.md` — review-driven improvement plan (2026-05-11)
