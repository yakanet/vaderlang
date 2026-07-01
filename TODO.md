# Vader — TODO

Implementation roadmap for the Vader compiler and standard library, derived from `SPEC.md`:

- **Phase 1** — MVP compiler in TypeScript, plus stdlib in Vader.
- **Phase 2** — Self-hosting (port the compiler to Vader).
- **Phase 3** — Post-MVP language features and tooling.

Completed items (`[x]`) are kept as one-liners — see git history for implementation notes, commit hashes, migration steps. Open (`[ ]`) and in-progress (`[~]`) items keep the full context needed to act on them.

**Completed work — Phase 0, the done Phase 1 subsections, and the long-form detail of finished "Priority" items — lives in [`docs/HISTORY.md`](./docs/HISTORY.md).** This file tracks open + in-progress work only.

---

## Priority — next up

- [x] **Inline the trivial `infer_*_lit` literal-inference fns — DONE 2026-07-01** (`39c049e1` + seed `3585efa4`). The six wrappers each ignored their `AST.*LitExpr` arg and returned a constant; inlined the constant at all ~9 dispatch sites (1 production `infer_expr`, 8 `*_check_stub` test stubs) and deleted `expr_literals.vader`. `infer_expr` drops the now-unused `as e` bindings. verify.sh green (fixed point, 0 W0005, seed fresh), suite 2442/0, 8 examples pass. The StringLit interpolation-walk lives in `infer_expr`, untouched.

- [x] **Add `TY_STRING` / `TY_NULL` singletons (drop the per-literal alloc) — DONE 2026-07-01** (`2e5fd4e6` + seed `50298547`). Added `TY_STRING`/`TY_NULL` next to `TY_BOOL`/`TY_VOID` (`types.vader:207-208`) and swept ~47 PRODUCTION `mk_primitive("string")`/`("null")` sites across `typecheck/` + `lower/` (per-AST-node hot paths) onto them. Test fixtures + cold modules (lsp/comptime/bytecode) keep `mk_primitive`, mirroring how `mk_primitive("bool")` coexists with `TY_BOOL`. Sound (PrimitiveType compared structurally, never by reference). verify.sh green (fixed point, 0 W0005, seed fresh), suite 2442/0, 8 examples pass. Deeper generic interning of `mk_primitive` stays deferred per the MVP "no hash-consing" stance.

- [x] **Array rest-destructuring `[head, ...rest] = items` — DONE.** `RestBinding` AST node (`vader/parser/ast.vader:329`, member of the `LetBinding` union L39) lowered via `rest_local_type` (`vader/lower/entry_types.vader:98`) + `vader/lower/lower_destructure.vader:120` + handled in `closure_analysis.vader:432`. Landed in `e9ccd332` (§3.8 spread-destructure). The "may not work / investigate" note was stale — it works.

- [x] **Typecheck body-walk reduction (lever A) — DONE 2026-06-23** (`e665d290` P1b + `56b35de8` P2; seeds `ddf52d9b`/`32315703`). The "big multi-session structural restructure" framing was wrong: a new `WalkMode.ReturnsOnly` (skip non-`needs_return_inference` fn bodies, build no `expr_types`) cut the re-walks AND, by flipping settle's both passes to it, collapsed the floor 2→1 — **typecheck −50 %, self-compile −24 %**, suite 2286/0. GATE-B1 stayed covered, the partial-env leak was reseedable (fixed point held). `WalkMode` lives in `vader/typecheck/orchestrate.vader:1464`. See [`.claude/plans/typecheck-walk-reduction.md`](.claude/plans/typecheck-walk-reduction.md).

- [x] **Two vtable-row builders — dead one deleted** (done 2026-06-20, `8ea29d9e`). `translate_vtables` was vestigial: it lived only in the legacy `emit_project` tree-walker, which `main.vader` imported but never called — the active pipeline goes entirely through midir's `emit_bytecode_from_cfg`. Deleted `emit_project` and its exclusively-legacy transitive closure (`assemble_module`, `translate_vtables`, `build_impl_table`, `vtable_fn_index`, `translate_data_pool`, the `reserve_*` pass, `synthesise_intrinsic_wrappers`, `lookup_symbol_id_for_import`, the extern-name helpers); `emit.vader` 1244 → 785 LoC. `vader/midir/emit.vader::build_vtables_from_entries` is now the sole `VtableRow[]` builder (output reaches `emit_vtable_dispatchers` in c_emit). Shared helpers (`emit_decl`, `emit_fn_body`, `build_signature`, `build_intrinsic_wrapper_body`, the peephole/fold passes) stayed — midir reuses them.

- [x] **`get` boxed its `V` return with the array-element type-index, not the canonical V index (FIXED 2026-06-20 via the `Box` op)**. A concrete primitive read from a monomorphised `V[]` (e.g. `MutableMap(string, usize)::get` returning `evals[i] : usize` as `V | null`) was boxed at the erased return with the COARSE ValType tag (`i64`, 99) instead of the SEMANTIC type (`usize`, 29), because the C-emit's implicit return-coercion only has the coarse ValType. Result: `rows_by_key[k] is usize` in `build_vtables_from_entries` failed → 4 duplicate `vader_vt_Error__message` C dispatchers → invalid C, no fixed point. lldb root-caused (`build/vader2dbg`, python watchpoints): get found the key but `vader_box_i64(99u,…)` vs caller `tag == 29u`. Chaining never hit it (its get returns a struct FIELD, interned to 29). **FIX = new bytecode op `Box { type_id }`** emitted at `midir/emit.vader::TermReturn` when a concrete primitive flows into an erased ref/union return; c_emit boxes with the precise tag, VM no-op (coarse `I64Val` matches any I64-width `is`). Built without reseed via a 2-stage bridge (chaining+Box → compact+Box); **fixed point reached** (vaderC.c==vaderD.c byte-identical), suite 2283/0, −14% self-compile RSS. Erasure box-vs-raw / type-table dedup family ([[erasure_audit_dotnet_model]]). **(2026-06-20 correction: the "array-element type-index (99)" wording is a misdiagnosis — there is NO dual primitive index; one `BcType` entry per primitive. The bug is purely the COARSE-ValType return-coercion losing the precise primitive type. The `i64`/`usize` tag numbers were from a transient bridge build. See the RESOLVED follow-up below — Box stays, proven load-bearing.)**
  - **RESOLVED (2026-06-20): `Box` stays RETURN-ONLY — it is load-bearing, and the "dual index → delete Box" plan was based on a false premise.** Investigated this session:
    - **There is NO "array-element vs standalone" dual index.** Dumping the self-compile bytecode type table shows EXACTLY ONE `BcPrimitive` entry per primitive (`usize`=28, `i64`=34, `u64`=36, `isize`=185, all distinct & unique). The earlier "usize has two indices (29 + 99)" framing is wrong; `intern_type` dedups by `type_intern_key` = `p.name`, so a primitive can't get two slots. The real bug is purely that the c_emit return-coercion only has the COARSE `ValType` and loses the precise primitive type.
    - **Box is load-bearing — proven empirically.** Disabled Box emission, rebuilt, self-compiled: the FIRST iteration looked clean (1 `Error__message` def) ONLY because that binary still had Box in its own body. The SECOND iteration (binary built from the no-Box C, so no Box in its body) regenerated the bug — **4 duplicate `vader_vt_Error__message` dispatchers, no fixed point**. So Box is needed in the compiler's OWN body for its `get`→`rows_by_key` dedup to tag correctly.
    - **Box is the only clean midir→c_emit channel** for the semantic return type (the erased signature says "ref" by c_emit time; the concrete primitive type is only known at midir). Any "delete Box" alternative would reinvent it. The one genuine structural fix that would make Box unnecessary is **monomorphising primitive-valued maps** (`MutableMap(K, usize)` → non-erased `V`), i.e. erasure-model P4/P5 ([[erasure_audit_dotnet_model]]) — large, deferred.
    - **The other erasure boundaries are safe** (don't need Box). The `box_expr` call sites and the type-index each passes:
      - `walker.vader:1192` call result → `sig.result_type` (semantic) ✓ ; `:1475` struct-field store → `sf.type_index` ✓ ; `:1765/1802/1823/1835` array store/push → `elem_tag`/`op.type_id` ✓ ; `:1536` `emit_box_op` → `op.type_id` ✓
      - `body.vader:323` `box_expr_unknown` → `primitive_tag_of(types, val)` (coarse, fn-arg widening + dispatcher-result) — SAFE: `primitive_tag_of` canonicalises to the one standalone primitive, and the WHOLE self-compile exercises this boundary heavily (every `map.put(k, primitive)`, `m[k]=v`) while reaching a byte-identical fixed point. Symmetric to the get-return case but correct because it goes through `primitive_tag_of`, not the lossy return-coercion. Residual nit: it falls back to tag 0 if a primitive isn't materialised — unobserved.

- [x] **🐛 Cross-module generic struct field-default boxed-vs-raw mismatch (FIXED 2026-06-20, `62acb352`)**. Symptom: a `MutableMap` built from a DIFFERENT module than `std/collections` lost all but the first key (membership probes failed). Originally mis-framed as "`= []` defaults alias one shared array" — that was wrong (the C emits a distinct `vader_array_new` per field). **Real root cause**: a field default that references the struct's own type-param (`ekeys: K[] = []`) was lowered in the OWNING module's view via `ctx_in_owning_module`, which kept only the caller's `subst` — so `K`/`V` resolved to the owner's ERASED `Any` → the default became a BOXED `Any[]` (`vader_array_new(…, element_kind=0)`). But the construction site monomorphises the instance (`MutableMap<i32,i32>` → `K=i32` raw, `element_kind=7`) and `put`/`get` write/read RAW. The boxed-array-written-raw mismatch scrambled the dense arrays (`ekeys=[2] evals=[2]` after `m[1]=10`) → corruption. In-module worked because the default lowered in the same monomorphised view. **Fix**: thread the instance's type-args into the default-lowering subst — `ctx_in_owning_module` now merges `build_struct_mixed_subst(decl, owner_typed, st.args)` (primitive → concrete so the array lands raw, ref → `Any`, matching the P2 field layout) via a new `merge_subst` helper. This is the TS `extraSubst` the old comment deferred ("none exist in the tree today" — wrong, `MutableMap`'s `K[]` default IS one). **Workaround removed**: `ensure_index`'s `self.ekeys/evals = []` reassignment is gone. Root-caused by emitting the construction C and reading the `element_kind` arg (0=boxed vs 7=raw); validated raw arrays + `has1=has2=has3=true` + suite 2283/0 + verify.sh fixed point. Built via a 2-stage bridge (fix+workaround → fix-only) since the pre-fix lowerer needs the workaround.

- [x] **Authoritative resolution (symbol-id tracking) — LARGELY DONE 2026-07-01.** Plan [`.claude/plans/symbol-id-tracking.md`](.claude/plans/symbol-id-tracking.md). Driver = fiabilité + simplification. **Le cadrage initial était FAUX** — 4 sondes successives l'ont renversé : le miss `idents` (fallback **1458×**, 100% `Span`/`Type`) n'était NI les « clones post-walk » (materialize est pré-resolve, 0 span-`<clone>`), NI `decl.vader:133`/owner (0 raté), NI le prélude, NI la clé span-hash — mais la **re-résolution cross-module des types de champ** à l'accès `.f` sur une valeur **union** (`union_common_field` + struct-pattern) qui **court-circuitaient** le cache `struct_field_types` (les 2 autres appelants de `find_struct_field_type` le consultaient, eux). **Livré (10 commits) :** (1) router ces 2 sites par le cache `19d8df45` ; (2) retrait `symbols_by_name` + branches fallback `type_expr` → `idents` autoritatif pour les type-refs `db1e0f0b` ; (3) trait-dispatch via registre `trait_decls` (`find_trait_id_by_name`) `4f69a379` ; (4) unification `concat_file_decls` (3 accesseurs `module_decls`) `1eaf4c74` ; (5) **dé-duplication `core_symbols`** — slots well-known Range/Field + seed threadé à `build_impl_registry` + lower re-sourcé via `build_core_seed`, retrait des copies par-module (`preload`/`populate`×2) `4924ad73`. **Audits perf :** cœur = self-compile **−27 %** ; dé-dup `core_symbols` = **−25 %** de plus (interleaved min-de-3), RSS neutre, C byte-quasi-identique, suite **2437/0**, point-fixe vert à chaque pas + reseed. **Trou #3** (collision `span.hash`) audité = **non-problème** (injectif intra-fichier). **Nettoyages finaux :** consolidation `resolved_field_type` (1 helper cache-first, 4 sites, doublon supprimé) `339969eb` ; `find_trait_id_by_name` **gardé en scan** (évalué : une map indexée devrait mirrorer les 2 sites de population de `trait_decls` → risque désync + table per-module, pour un gain perf nul). Le `core_symbols` du **lower est irréductible** (table nom→trait-core **dynamique** pour la collecte d'impls + le dispatch) → gardé, mais dé-dupliqué en une seule. **Phase 6 (LSP) superseded** : la vraie nav membres (`.field`/`.method`) est orthogonale (le resolver n'enregistre pas les spans `FieldExpr`) → chantier dédié [`lsp-member-navigation.md`](.claude/plans/lsp-member-navigation.md), différé. **Chantier clos sur son cœur.**

- [ ] **Allocation-use analysis → stack-alloc / interning / value-structs** (escape analysis, broadened 2026-06-20). One whole-program dataflow over midir (`vader/midir/`) computes, per allocation site / per type, *how the value is used*: does it **escape** its creating fn (return / store-to-heap / capture), is it **mutated** after construction (a `struct.set` scan — the lowered IR makes this a direct walk), is it **compared by reference identity**. Those facts feed THREE complementary GC-pressure optimisations, each attacking a different slice of the self-compile memory profile (the two halves measured by `bun run bench:profile`: ~986 MB GC-copied / 32 cycles of **churn** + ~512 MB **retained** live-set, ARRAY_BUF/`MutableMap`-dominated):
  - **Stack-allocation** — allocations that provably don't escape go on the stack (or are freed eagerly) instead of the Cheney arena. Attacks the **churn** half (short-lived CFG-node / temp traffic). Caveat: a stack slot must not be a GC root the moving collector tries to relocate.
  - **Interning (hash-consing)** — immutable, duplicated, long-lived values are deduplicated to one shared instance. Attacks the **retained** half (Type IR, `Symbol`, `BcType`, `MutableMap` entries held across passes) — note this is the INVERSE class to stack-alloc: the escaping, long-lived values stack-alloc can't touch are exactly interning's target. **Vader soundness condition**: `==` on a struct without an `Equals` impl is *reference identity* (SPEC §"Memory Model"), so interning is sound only for a type that is immutable AND never identity-compared (has `Equals`, or is never `==`-ed — e.g. `PrimitiveType`, compared via `equals_type`/`canonical_key`, qualifies). Proving "never identity-compared" automatically must bail in erased generic/union contexts, so the realistic form is an opt-in **`@intern` decorator the compiler *verifies*** (immutability + Equals/no-identity-compare → error if violated) then generates the content-keyed construction — the Rust `Ty` / LLVM type-uniquing / GHC model (always annotated, never auto-derived, for exactly this reason). Profitability caveat: intern only bounded-value-set types (few distinct values), else the intern table itself retains everything → a leak.
  - **Value-type structs** — small immutable never-trait-boxed structs passed by register instead of heap-boxed. Shares the same immutability fact; see the §3.5 "Value-type structs" item for its open trade-offs (`@value` vs auto-detect, `is Trait` interaction, multi-register ABI).
  The first concrete interning win — `mk_primitive` singletons (`vader/types/types.vader`, 17 primitive names incl. `null`) — is a safe MANUAL instance (never `==`-compared, 17 bounded values); doing it generically is this chantier. **When generic `@intern` lands, REVERT that manual interning**: replace the hand-rolled `mk_primitive` singleton table with `@intern` on `PrimitiveType`, so there's one mechanism — the manual table would otherwise duplicate (and could conflict with) the generic pass's content-keyed construction. Architecture-level → explore-before-commit + review. Related §3.5 items: escape (stack-alloc), value-structs, self-host typecheck working-set.

- [x] **Generic arithmetic operator traits (`Add` / `Sub` / `Mul` / `Div` / `Rem`) — DONE 2026-06-24.** Generalised to `Add :: trait<Rhs = Self, Out = Self>` (+ Sub/Mul/Div/Rem) in `std/core` (`core.vader:100-108`) — heterogeneous operators are now sound and first-class (operator RHS type-check → T3017); the `= Self` defaults keep `i32 implements Add` and bounds `<T: Add>` working verbatim. P1 default type params (`4b11a0d1`); P2 generalise the traits (`c4b03d33`); P3 RHS check (`8000ee60`); P4 migrate std/time + std/path to operators (`85019384`). See [`.claude/plans/generic-arith-operator-traits.md`](.claude/plans/generic-arith-operator-traits.md).

- [ ] **W0004 ambiguous-loop-jump : drop the entry-module scope** (added 2026-05-30). W0004 (unlabeled `break`/`continue` inside 2+ nested loops) currently fires only for the **entry module** — gated by the entry-module check in `vader/typecheck/stmt.vader` ; Vader gets it for free since `check_project_with_bodies` only body-checks the entry. The scope was added so importing the stdlib / the `vader/` compiler tree (which have unlabeled nested-loop jumps, e.g. `std/regex`'s matcher, `vader/lower/closure_analysis::walk_stmt`) doesn't surface W0004 from library internals (Vader doesn't body-check imports, so their nested-loop jumps never reach the check). Eventually W0004 should fire on **any** module : (1) make the stdlib + `vader/` tree W0004-clean (label the nested-loop jumps), (2) decide whether imports should be body-checked at all (today they aren't), (3) remove the entry-module gate. Threading lives in `LoadedProject.entryModuleId` → `ResolvedProject.entryModuleId` → `checkProgram(…, isEntryModule)` → `MutableTyped.isEntryModule`. Related cleanup : Vader now carries **two** loop-nesting counters — `FnContext.loop_depth` (T3015 break-outside-loop) and the walk-global `TypedProgram.loop_depth` (W0004), because `FnContext` isn't threaded through the expression checker (so its depth is lost inside `if`/`match` blocks — T3015 has the same blind spot). Unify on the walk-global once that's reconciled (would also close T3015's if-nested gap).

- [x] **Resolver lazy index — DONE** (`a1935811`). Implemented in `vader/resolver/lazy.vader` (`resolve_lazy` / `include_paths` / `seed_entry` / `misplaced_module_at`) — on-demand, import-driven module resolution + include-paths, replacing the up-front full scan. The 2026-05-26 "attempted + reverted" blocker (spurious R2001 because `diagnose_import_path` fired before lazy expansion) was solved by the lazy-resolve rework.

- [~] **`vader fmt` MVP** (first pass 2026-05-11) — written in Vader under `vader/fmt/`, exercises the self-host parser end-to-end. Idempotency + parse round-trip green on the stdlib ; byte-for-byte no-op pending on three stylistic gaps : (a) `::` column alignment in decl groups, (b) per-line grouping inside multi-line imports, (c) cap at 1 blank line between decls vs the stdlib's occasional double-blank. Tests : `tests/formatter*.test.ts` (gated `RUN_FMT_TESTS=1`). Open : column alignment decision, hand-curated snapshot scenarios, growing `NO_OP_FILES`.

- [~] **Reject private types in a public signature — return types DONE (T3052), extensions open** (`e12cde15`). `first_unexported_type` (`vader/typecheck/decl.vader:227`) fires **T3052** when an `export`ed fn's **return type** names a non-`export`ed type (code at `vader/diagnostics/codes.vader:79`/`:363`). Remaining (the item's planned extensions): **parameter types, exported struct fields, type-alias RHS** — `first_unexported_type` is only called on `return_type` today (`decl.vader:213`). Mirrors Rust's `private_interfaces` (E0446).

- [x] **LSP : `@no_return` divergence doesn't narrow a union after a guard** (added 2026-06-16). The LSP reports a false **T3001** on code like `if op_opt == null { panic(...) } ; push_emit(ctx, op_opt, …)` (seen in `vader/midir/emit.vader`'s `InstrIntrinsic` arm) — at the use site it still types `op_opt` as `Op | null` instead of narrowing to `Op`. The **native full-project build narrows correctly** (the file compiles clean), so this is LSP-only. Likely cause : the LSP analyses the file without full cross-module info, so `panic`'s `@no_return` decorator (declared in `std/abort`) isn't resolved → the guard branch isn't seen as diverging (→ `never`) → no flow-narrowing of the union's complement. Fix : make the LSP resolve cross-module `@no_return` (or eagerly load `std/abort`'s decorator metadata) so divergence-narrowing matches the compiler. Related shipped work : "divergence → `never`" + `T | null` flow-narrowing (§1.13e).

- [ ] **LSP semantic tokens override TextMate for strings — escapes lose their colour** (added 2026-06-17). When the LSP loads, escape sequences inside string literals (`\t`, `\n` in `"\t\nhi"`) switch from TextMate's distinct escape colour to a uniform `string` colour. Cause : `classify_token` (`vader/lsp/semantic_tokens.vader`) emits one `string` semantic token over the **whole** literal content (`StringBegin` / `StringPart` / `StringEnd`), which overrides the editor's TextMate grammar — confirmed via a token dump (`"\t\nhi"` → a single `string` token spanning `\t\nhi`). This is the same call already made for **identifiers** (the existing `classify_token` comment : *"The shared TextMate grammar already paints idents correctly ; letting it own that surface keeps the editor clean."*) ; TextMate paints strings **and** their escapes well, so the semantic override only degrades. The related multi-byte **length** bug (`"héllo"` token running one column long) is already fixed — token lengths are codepoint-based (`span_token_length`). **Options :** (B, recommended) stop emitting `string` tokens for `string` / `char` literals — return `-1` for `StringBegin` / `StringPart` / `StringEnd` / `CharLit` in `classify_token`, letting TextMate own them like identifiers ; (A, broader) also drop `number` / `operator` / `keyword` / base-comment tokens so the semantic layer is purely **additive** — resolution-based identifier roles + vaderdoc tags + `@`-intrinsics only — eliminating all load-time highlighting diffs ; (C) emit separate escape-sequence tokens within strings (keeps `string` tokens, more work). Lives in `vader/lsp/semantic_tokens.vader::classify_token`.

- [x] **LSP : member completion missed free-fn UFCS methods** (fixed 2026-06-20). On `f.mint()` where `f: NodeIdFactory`, completion offered only the field `next`, not the method `mint` — because `mint :: fn(self: NodeIdFactory)` is a **free function** (UFCS), not an `impl`-block method, and `member_completion` only collected struct fields + `impls.all` members. Fix: new `vader/typecheck::ufcs_methods_for(target_ty, typed)` enumerates every free fn whose first param fits the receiver (reusing `try_curry_receiver`, the same match `try_free_fn_ufcs_with_first` uses for a single call), and `member_completion` now appends those. Test: `lsp.test.ts` member-completion fixture gained a free-fn `magnitude :: fn(self: Point)` asserted present.

- [x] **Typer : `lookup_fn_symbol_by_span` matched spans file-blind** (found + fixed 2026-06-20 while landing T3053). `vader/typecheck/decl.vader` matched a decl to its overload Symbol by `(line, column)` only, ignoring `file` — two fns at the same `(line, col)` in different sibling files of one module collided → the second's `decl_types` entry was never written (left `?`), so a *legitimate* cross-file overload set sharing `(line, col)` mistyped one member and resolved calls to the wrong overload. Fix: also compare `sp.start.file == decl.name_span.start.file`. Repro that errored before / runs after: two `take` overloads (`fn(i32)` / `fn(string)`) at the same line:col in sibling files → `take(2)` now picks the i32 version. Suite 2281/0.

- [x] **Type-ascribed const bindings (const arrays) — DONE** (`b93f094f`, Odin-style typed const). The form ships and is in active use: `NAME: Type: value` — `MASK_U32: u32: 0xFFFF_FFFF`, `SHA256_K: u32[]: [...]` (`std/crypto`), the `DOUBLE_POW5_*` tables (`std/core/dtoa_tables.vader`). NB: the spelling is `: Type:` (a single colon before the value), not the `: Type ::` this item originally wrote — same capability (declare + pin the element type of a const array in one statement).

- [x] **Target ABI — shrink the per-target runtime** (done + squash-merged to `main` `1536a2a3`, 2026-06-16). Whole chantier S0–S7 + .NET-erasure CORE landed : memory opcodes, StringBuilder/Array/String/hash flipped onto them, the `Builder*` op family + `vader_builder_*` runtime retired (S4), Array accessors open-coded in c-emit (S5 Solution A), string-hash atom cache (phase 4). Verified on-tree 2026-06-19 : no `Builder*` variants, no `vader_builder_*`, seed clean. See git history + `docs/TARGET_ABI.md`.

- [ ] **Warn on unused imports** (added 2026-06-07). An imported name that's never referenced in the file earns a compilation warning (new W-code). Covers both import forms : `import "path" { Name1, Name2 }` — each destructured name must be used at least once — and the namespace form `xx :: import "path"` — the binding `xx` must be referenced at least once (e.g. `xx.Member`), else the whole import is dead. Emit one warning per unused name, pointing at its import-list span. Update `SPEC.md` (imports section) in the same commit.
  - **Attempted 2026-06-17, reverted — blocked on reference-tracking.** First cut scanned `resolved.idents` (span→Symbol) for `ImportBinding`-kind values to build the "used" set, emitting W0006 for every unreferenced import binding in `resolved.symbols`. Minimal snippets passed (an unused `eprintln` flagged, a used `println` not — across value position, let-binding RHS, and type position). But on the real tree it **systematically false-positives** : `vader/lexer/keywords.vader` (40 LoC, **zero own imports**) reported 16 W0006 — they were `vader/lexer`'s **sibling-file** imports, whose uses the resolver never recorded because **its body walker is structurally `files[0]`-only** (TODO §1.13d, `resolver/resolve.vader:153`). Worse, single-file `vader/cli/main.vader` reported 24 W0006 for top-of-file imports that are obviously used (`keys`, `values`, `resolve_module`, …) — so `resolved.idents` is **not a reliable record of every use** even within one file (some expr/type positions never land there ; root not fully pinned). **Conclusion :** a sound W0006 needs comprehensive, **symbol-id-keyed** (not span-hashed) reference tracking that covers *every* file of a (folder) module and *every* reference position. That is the same gap as **"Harden multi-file module support" (§1.13d, the `files[0]`-only body walker)**. Do this **after** §1.13d lands, or as a dedicated full-AST name-collection walk (params/return/fields/alias-RHS/const-types/all bodies, across all files) — not by scanning `resolved.idents`. Reverted cleanly (no W0006 in the tree).

- [x] **Typer accepts an enum literal from the wrong enum** (not reproducible / effectively closed ; re-verified 2026-06-19). The current self-hosted typer rejects a wrong-enum literal with **T3027** in both call-argument and typed-slot position — including the exact reported shape (`.OrphanImplForbidden` ∈ `ResolverCode` passed where `TypecheckCode` is expected). The original 2026-06-17 report (no diagnostic, silent trap) could not be reproduced on HEAD then or now ; a regression guard (`tests/diag_corpus/typecheck/t3027_wrong_enum_variant`) locks the behavior. The only remaining silent-accept path is the legitimate `UnionType` case in `infer_dot_variant` (first member enum carrying the variant). Reopen only with a concrete repro that emits no diagnostic.

- [x] **`string.len()` c-emit codegen bug** (fixed via the core-string-utf8 reorg, verified 2026-06-19). Root cause was the hardcoded `primitive_method_type` typer table promising string methods the lowerer couldn't honor (free-fn UFCS missed the unloaded `std/string`), so `s.len()` fell through to a degenerate `field_get`/`call_indirect` → invalid `(vader_fn_t*) 0.payload.obj` C. The reorg removed `primitive_method_type` and moved `len` into `std/core` ; `total + s.len()` + `"${s.len()}"` now compile & run (`8 and 5`). See git history (`core-string-utf8-reorg`).

- [x] **Comma-separated enum-literal match patterns** — RESOLVED 2026-06-25 (`4d097749`) by landing **pipe** or-patterns instead. `.A | .B | .C -> …` (new `OrPattern` AST node) is the canonical multi-variant form; the broken comma form (which never actually parsed on stage2) is gone and CLAUDE.md §6 / SPEC now show the pipe form. Also covers `1 | 2` literals and `is A | B` type tests, and fixed the latent `is <union>` native-vs-VM backend divergence (c_emit `emit_type_check` was not union-aware). Snippet `tests/snippets/or_pattern`. Original report below.
  - **Comma-separated enum-literal match patterns miscompile** (added 2026-06-17, found while landing T3052). A match arm with comma-separated enum literals — `match k { .A, .B, .C -> true ; _ -> false }` — panics at codegen : `midir/emit: no field `B` on `null` … a method reference on a primitive isn't a first-class value`. Only the **first** literal in the comma group (`.A`) gets the scrutinee's enum-type context ; the rest (`.B`, `.C`) are left context-free, resolve to a null-typed enum-literal, and the emitter then treats `.B` as a field/method reference on `null`. Reproduces on the current self-hosted compiler (stage2), both expression-bodied (`fn(k) = match k {…}`) and statement-bodied, with and without a `-> bool` annotation. Workaround in use everywhere : one literal per arm (`.A -> true` / `.B -> true` / …) — a tree-wide grep finds **zero** comma-separated enum patterns, i.e. the codebase already avoids this. **`CLAUDE.md` §6 documents the comma form as canonical** (`suppresses_newline_after :: fn(k) = match k { .Plus, .Minus, .Star -> true ; _ -> false }`), so either the bug is fixed or the style guide is corrected. `Pattern` has no or-pattern variant and `MatchArm.pattern` is singular (`vader/parser/ast.vader:562`), so the comma form is parser-desugared or mis-parsed — start the investigation there + in the typer's pattern-vs-scrutinee type propagation (`vader/typecheck/match_expr.vader`). Same "method reference on a primitive" family as the `s.chars` / `string.len()` errors (a lost-type-context enum/method literal reaching the emitter). Add a `tests/snippets/_diag_*` repro once fixed.

- [x] **Leading `&&` / `||` line-continuation now parsed** (fixed 2026-06-22). A boolean condition broken across lines with the operator at the **start** of the continuation line (`if a == 1\n    && b == 2\n    && c == 3 {`) used to fail — P1002 `expected {` + P1003 `expected an expression: got &&` (and on old binaries the malformed AST error-recovered into the `midir/emit: method reference on a primitive` codegen panic family). Root: the bug was in the **lexer**, not the parser — `vader/lexer/lexer.vader::peeks_leading_continuation` deliberately excluded the multi-char `&&` / `||`, so only a leading single `|` / `&` (type union / intersection) suppressed the preceding newline; a leading `&&` got a statement-terminating newline and the `if`-condition ended early. **Fix**: `&&` / `||` / `&` / `|` have no prefix/unary form (`parse_prefix` only knows `-` / `!` / `~`), so a line *opening* with one is unambiguously a continuation — `peeks_leading_continuation` now suppresses the newline for `&&` / `||` too (only `&=` / `|=` stay excluded). Scope kept to these four infix-only operators; generalising to `+` / `==` / etc. would need a Go-ASI-style "is the previous line complete?" heuristic to disambiguate a leading unary `-` (deferred — see the reverted broad-scope option). SPEC §"Newline-significant" gained a 5th newline-absorption case (+ example). Regression: 4 colocated `@test`s in `lexer.vader` (`test_leading_andand_continues`, `test_leading_oror_continues`, `test_leading_pipe_still_continues`, `test_complete_lines_keep_newline`). Seed re-bumped.

- [x] **Cross-module stdlib `const` reference miscompiled** (fixed 2026-06-19). Referencing a `const` imported from a **stdlib** module — e.g. `import "std/math" { pi }` then using `pi` — silently produced no output (native) / `local.set on empty stack` (VM). **Real root cause** (the earlier `LoweredConstDecl`-accessor / `emit.vader:556` hypothesis was wrong) : the lowerer skips imported stdlib module decls (`is_stdlib_path`), so the stdlib const was never lowered into `project.modules` → `inline_consts` had no entry → `midir/build.vader::build_ident` fell through to `build_unreachable_type`, truncating the caller (DCE then stripped the dead chain). User-module cross-module consts always worked (`lower_module` lowers them eagerly). **Fix** : lazy on-demand harvest mirroring `materialize_nongeneric_stdlib_fns` — `register_nongeneric_stdlib_const` (in `lower_ident`) records a referenced stdlib const, `materialize_nongeneric_stdlib_consts` lowers its decl into the owning module so `inline_consts` routes it (scalar → inline, bulky array → fn-wrap). Byte-identical fixed point preserved (the compiler tree references no stdlib value-const → empty harvest during self-compile). Regression guard : `tests/snippets/_diag_const_cross_module/` (+ in `VADER_SELF_EMIT`). The harvest is the exact compensation for the `is_stdlib_path` skip and becomes dead code once `is_stdlib_path` is removed (separate planned chantier). **README follow-up :** the hero snippet's local `pi :: 3.141592653589793` workaround can now be restored to `import "std/math" { pi }`.

- [x] **`vader run <file>` runs the named file's `main`, not an arbitrary directory entry** (fixed 2026-06-20, `6e133274`). Folder = module, so `vader run dir/b.vader` loaded `dir`'s whole module and the VM picked the first `is_main` fn — silently running `dir/a.vader`'s `main`. T3053 only caught same-signature duplicate `main`s; the gap was two `main`s of *different* signatures (`fn()` vs `fn(argv)`). Fix (`vader/cli/main.vader::entry_index_for_file`, CLI-only — no pipeline/seed change): `run_source` resolves the entry by matching the named file's `main` (lowered fn's `origin.decl` span file, basename-matched), falling back to the first `is_main`. Regression `tests/vader_run_entry.test.ts`. Follow-up if wanted: `vader build` / `dump --stage=c|bytecode` still use the conventional first-`main`.

- [x] **`StringBuilder.to_string` read-back regression** (found + fixed 2026-06-15 via ABI benches). The Buffer-fill model copied bytes per-`append` (a boxed per-byte `u8[]` read into the buffer) **and** read them back per-byte at `to_string` — measured 3.1-3.3× slower than `main`. Rather than patch the read-back, StringBuilder was returned to the **parts model** (`string[]` of references) : `append` is now an O(1) ref push, and `to_string` assembles all parts in one bulk pass — `total.new_buffer()` + per-part `write_string` (the new `BufferWriteString` memory opcode, a lean `memcpy` replacing `vader_string_concat_all`) + `intern_string` (`BufferToString`). Lands StringBuilder ≈ `main` with no fat runtime symbol. See `bench/string_builder`.

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
- [x] **Real impl table for trait `type_check`.** Today's heuristic covers host-driven I/O ; a user struct `Foo implements MyTrait` won't match `type_check MyTrait` in the VM until the bytecode emitter materialises an impl-table side-section. Picked up alongside generic-fn dispatch.
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
- [x] **Array `pop` — covered by `remove_last`** (Array API chantier). `arr.remove_last()` IS O(1) pop-and-return : it shrinks `length` (`vader_array_remove_last`, capacity preserved) and returns the removed element as `T | null`. A separate `pop` intrinsic would be a pure alias — not added. (Original ask predated `remove_last`.)
- [ ] String runtime polish, array runtime polish, StringBuilder support consolidation, panic handler.
- [ ] libc-backed I/O glue for `std/io`.

### 1.12 CLI — partial
> Shipped: `vader run` + `vader build` single-file, `--target=ir` (`.vir`/`.virt`), `vader test`, `vader dump --stage=<ast|typed-ast|bytecode|c|…>`, `--allow-env`.
- [~] **`vader fmt [path]`** — see top "Priority — next up".
- [ ] Manifest-driven build (`vader.json`) — single-file works ; manifest mode still gated "not yet implemented".
- [ ] `vader build --target=wasm` — see §3.10.

### 1.13 Stdlib (in Vader) — partial
- [~] `std/core` finalisation, `std/io`, `std/string`, `std/math`.
- [x] **Float formatting → stdlib (Target ABI follow-up chantier).** `f32`/`f64`
  `Display.to_string` stays host (libm `snprintf("%.*g")` + `strtod` shortest
  round-trip) through Target-ABI Stage S1 — only `i*`/`u*`/`bool`/`char`/`string`
  move to pure Vader there. A separate chantier should port float formatting to
  pure Vader (Ryū / Grisu / Dragon4-class shortest-round-trip) to retire the last
  two `vader_builder_append_display_f32/f64` and make float output bit-identical
  across targets (a real plus for a compiler). Hard + float-rounding-risky — kept
  out of S1 on purpose. See `.claude/plans/target-abi-migration.md` + the S1
  decision (2026-06-07).
- [x] `std/collections` — `MutableMap(K, V)` + `MutableSet(T)` chaining HashMap with FNV-1a string hash. Shared `len` / `is_empty` / `put` / `get` / `contains_key` / `add` / `contains` via first-param overloading.
- [ ] **Immutable `Map`/`Set` ops + `to_immutable`** — re-add the struct decls when there's a real read-only-view design.
- [x] Iterator impls for `MutableMap` / `MutableSet`.
- [ ] **Restore `MutableList(T)` once immutable `List<T>` lands** — raw `T[]` already covers push/len/indexing.
- [x] **Audit `std/iter` and `std/string` surfaces** — surfaced 2026-05-20 during SPEC vs stdlib sweep. Two threads to follow up : (a) `std/iter` is missing an explicit `into_iter()` helper (SPEC previously referenced one) — decide between adding `arr.into_iter()` as an explicit form or relying solely on the `T[] implements Into(Iterator(T))` coercion ; (b) `std/string` exports drifted from SPEC (added `index_of`, `compare_ascending`, `compare_ascending_ci`, `decode_escapes` ; missing `is_hex_digit` / `is_digit_in_base` — now placed under `std/numbers`). Pass to settle on one canonical surface per module and align SPEC + stdlib + ports.
- [x] `std/string_builder` — `StringBuilder`.
- [x] `std/iter` — eager `T[]` combinators (`map`, `filter`, `fold`, `sum`, `take`, `skip`, `collect`, `count`, `zip`, `chain`, `enumerate`, `flat_map`).
- [x] `std/iter` lazy combinators — `MapIterator`, `FilterIterator`, `TakeIterator`, `SkipIterator` (struct-literal construction).
- [x] `std/runtime` — `collect()`, `collections()`, `bytes_used()`, `bytes_copied()`.
- [x] `std/sort` — `sort(arr, less)` stable merge-sort with insertion-sort cutoff. Returns a new array.
- [~] **`std/cli`** (initial 2026-05-11) — minimal declarative `FlagSpec` + `parse(args, specs) -> ParsedArgs` + accessors. Supports `--name`, `--name=value`, `--`. Open : subcommands, `--help`/`--version`, short flags `-v`, `--name value` form, rewriting `vader/cli/main.vader` on top once subcommands land.

### 1.13d Stdlib consolidation — partial
> Shipped: hex/base helpers centralised in `std/numbers`, `std/json` char-predicate duplicates removed.
- [x] **Audit consistency across `std/core` / `std/string` / `std/utf8`** (noted 2026-06-15) — these three modules feel incoherent : overlapping / unclear ownership of the byte ↔ codepoint ↔ string surface (`bytes_to_string`/`as_string`, `bytes()`, codepoint vs byte cursors, UTF-8 encode/decode). Map which module owns what, dedup the overlap, and settle a clear layering (core = byte primitives + intern ; utf8 = encode/decode ; string = the codepoint-string API). Cross-ref the `bytes_to_string` reconciliation item below.

  - **Promoted to a dedicated plan (2026-06-16): [`.claude/plans/core-string-utf8-reorg.md`](.claude/plans/core-string-utf8-reorg.md).** It folds in the `string.len()` miscompile (UFCS to a non-imported, non-`core` free fn → invalid C), the **frozen import policy** (using a non-imported fn — except `std/core` the prelude — is a compilation error), the prelude/layering rule, and the emitter ICE backstop. The `bytes_to_string` reconciliation item below is folded into that plan's Phase 3.
- [ ] **Future audits** — revisit when new stdlib modules land. A shared `Cursor(T)` trait could unify `std/json` and `vader/lexer`'s hand-rolled cursors when a real need arises.
- [x] **Harden multi-file module support (compiler) — DONE (the correctness gap; verified 2026-07-01).** Surfaced 2026-06-08 splitting
  `std/core` into `core.vader` + `primitives.vader` (same `module "std/core"`). **Gap (b)
  — "the resolver body-walker is structurally `files[0]`-only" — is resolved**, and the
  earlier framing was wrong: the typecheck/compile path body-walks EVERY file
  (`typecheck/orchestrate::merge_module_program` concatenates all files' decls into one
  `Program` before `resolve_program`). Empirically confirmed: a probe in the
  `symbols_by_name` fallback fired ONLY for `Span`/`Type` (1458×) — pervasively-imported
  types. **NB (2026-07-01): the "clone spans" framing was later DISPROVEN.** The real
  cause was cross-module field-type re-resolution — `union_common_field` / struct-pattern
  bypassing the `struct_field_types` cache (0 clone spans). `symbols_by_name` has since
  been **removed entirely** (idents authoritative for type-refs) — see the
  authoritative-resolution item above. The only `files[0]`-only resolve left is
  `cli/main.vader::resolve_loaded_project`, used solely by the `dump --stage=resolved-ast`
  path (`run_resolver_stage`) which never runs the typer — a dump-fidelity limit, not a
  compile bug. Residual hygiene (not correctness, deferred): (a) FRAGMENTATION — "a module's
  decls" still has 4 separate accessors (`lower::module_decls`,
  `comptime/check::lookup_module_decls`, `comptime/specialize::module_decls_for`,
  `merge_module_program`); one shared accessor would make "a pass reads files[0] only"
  unrepresentable. Stale comment still to fix if touched: `lower/lower_mono_fn.vader`
  ("flattened at load time").
- [x] **Reconcile `u8[] → string` to `bytes_to_string`.** Target-ABI S1 adds the
  canonical `bytes_to_string` (host intrinsic) in `std/core`. The tree still has
  the legacy `as_string` (`std/string`) and a `bytes_as_string` import alias
  (`as_string as bytes_as_string`, used in `std/path` / `vader/fmt` /
  `vader/resolver` to dodge the `std/path::as_string` name collision) for the
  same op — ~313 sites across 83 files. Migrate all to `bytes_to_string` and drop
  the legacy names (pre-MVP, no back-compat).
  Separate cleanup chantier, not S1.
  - [ ] **Idea: `string(bytes)` cast form** — once `bytes_to_string` is canonical,
    consider letting `string(xxx)` (where `xxx : u8[]`) be the surface for the
    bytes→string conversion (cast syntax instead of / in addition to the
    `.bytes_to_string()` method). Language-surface change → SPEC.md update if
    pursued. Decide whether a `u8[] → string` cast reads clearly vs. being too
    implicit (same byte-reinterpretation-vs-render concern that ruled out
    `u8[] implements Into<string>`).

### 1.13e Language ergonomics surfaced by self-host port — partial

Patterns counted on the existing Vader code that paid an outsized boilerplate cost. Each item is additive, back-compat by construction.

> Shipped: `usize` literal context-sensitivity, `T | null` flow-narrowing, divergence → `never` (blocks / infinite loops), W0002 unreachable-code, enum-to-repr cast, const-binding mutation reject (T3041), field-expr + `is T` narrowing, tuple-destructure-after-narrow, byte literals `b'X'`, free type-alias order, namespace-alias unification, `MatchResult` cleanup, self-host lexer u64, `if x is T as binding`, lambda `fn`-keyword drop, `for <range>` shorthand.
- [ ] **AST node id boilerplate** — re-audited 2026-05-15 ; deferred. ~11 self-host fields carrying `id: UNASSIGNED_NODE_ID`. All three resolution shapes (decorator, mixin, marker) need new compiler infrastructure that's bigger than the 128 lines it would save. Revisit if decorator infra lands for other reasons.
- [~] **Normalise generic syntax to `<T>` across stdlib + self-host** —
  the parser now accepts `<T>` (canonical), `[T]` (legacy bracket) and
  `(T)` (legacy paren) ; SPEC §10 leads with `<T>`. **Parser support
  done** (`vader/parser/parser.vader` `parse_angle_type_params`, incl.
  `shr` split-on-demand). Remaining :
  - **Migration** : rewrite every `[T]` / `(T)` generic site under
    `stdlib/`, `vader/`, `tests/`, `examples/` to `<T>` (~515 legacy
    sites remain vs ~84 `<T>`). Best done with a parser-aware AST walker.
    The `vader fmt` rewrite is a separate chantier — fmt still emits
    `[T]`, so a fmt pass post-migration would revert it unless fmt is
    updated first (or in parallel).
  - **Drop legacy parser paths** : once everything is migrated, remove
    the `[T]` and `(T)` openers from `parse_bracketed_type_params` /
    `parse_struct_type_param_list` / `parse_generic_arg_list` in the
    parser. Pre-MVP, no back-compat (CLAUDE.md).

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

- [x] **Mono pass unified — DONE 2026-06-30 (Direction B).** The investigation (`.claude/plans/mono-pass-unification.md`) inverted the premise: the comptime `monomorphize_project` pass was **dormant** (its output unconsumed) and the **lowerer** was the authoritative monomorphizer — reading the comptime side only as a redundant struct-instance filter the lowerer's own gating already covered. Rather than route everything through the comptime engine (Direction A — no perf payoff, comptime is 0.7 % of the build, high-risk), the dormant comptime mono pass + the unwired erasure-dedupe + the dead IR fields were deleted, leaving the lowerer as the sole monomorphizer. **−1661 LoC Vader / −2268 LoC C, byte-identical** (suite 2426/0, fixed point holds). Commits `d3921224` / `3c8b54f4` (+ seeds `ea55d85f` / `7be8ddbd`). Kept `MonoEntry` (the lowerer's "decl to emit" unit) + `symbol_for_decl` (extracted to `symbol_lookup.vader`). NB: T3033 is `InvalidMainSignature`, not a bound check — the real bound diagnostic is T3006, which lives in the typechecker and was never part of the mono pass.
- [ ] **Direction A — mono dissolves into the comptime engine** (deferred). `fn[T](...)` partially evaluated with `T` bound, comptime engine owns instantiation. Only worth it if the type-first milestone (Layer 4/5) needs it. The old dormant scaffolding is gone, so this is now a from-scratch build ; Direction B closed no doors (the harvest + lower-side erasure stay).

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
- [x] Verify call-site override `sum[i64](arr)`.
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
- [~] Rewrite `[T: Trait]` enforcement to `@satisfies(T, Trait)` via the comptime engine.
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

Began once the TS compiler could compile a non-trivial subset. Goal : validate the design as we go.

### 2.0 Vader CLI minimal — partial
> Shipped: argv parsing + stage dispatch, snapshot parity rig (`tests/parity/`), native CLI build via `tests/cli-bin.ts`.
- [ ] Future stages plug in as parser / typechecker / lowerer get ported.

### 2.1 Port the parser to Vader — partial
> Shipped: lexer (`vader/lexer/`), diagnostics (`codes`/`diagnostic`), parser (`vader/parser/`, ~2200 LoC recursive-descent + Pratt), AST→JSON dumper, `vader dump --stage=ast`, byte-for-byte lexer + parser parity (~240/245), porting bugs all closed.
- [~] **Diagnostics folder-module migration** — today `vader/diagnostics/{codes,diagnostic}.vader` resolve as separate single-file modules, so `private` doesn't survive cross-file. Migrate to folder-module to hide internals.

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
      Cumulative gain measured on the TS reference impl : -10.5 % file size, -77.4 % cc
      time (-O0), -86.6 % cc time (-O3).

### 2.3 Port the bytecode emitter — DONE, the active self-host path (fixed point 2026-06-05)

The Vader-side bytecode emitter is the **only** active path and
self-hosts : midir lowers the CFG and calls `emit_bytecode_from_cfg`
(`vader/midir/emit.vader`), which reuses the shared emit walker under
`vader/bytecode/` — every per-shape `emit_<X>` for all `LoweredExpr` /
`LoweredStmt` variants, static + intrinsic + import + indirect-call
dispatch (`emit_call_to_symbol`), `FnRef`, vtable rows, `$Cell<T>`
closure cells — then the peephole / fold / DCE / slot-coalesce passes.
It compiles the whole compiler to a byte-identical native fixed point
(see §2.2). The legacy standalone `emit_project` tree-walker was deleted
2026-06-20 (`8ea29d9e`).

Files (`vader/bytecode/`) :
- `emit.vader` (785 LoC) — peephole / fold passes (`run_bc_peephole`,
  `run_bc_return_lit_fold`, `run_bc_const_fold_arith`,
  `propagate_const_single_use`, `drop_dead_stores`) + the shared emit
  helpers midir reuses (`emit_decl`, `emit_fn_body`, `build_signature`,
  `build_intrinsic_wrapper_body`).
- `emit_body.vader` (773 LoC, near the 800 cap) — every per-shape
  `emit_<X>` for stmts + exprs ; call dispatch via `emit_call_to_symbol`.
  Single file by Vader's mutual-import constraint (`emit_block ↔
  emit_stmt ↔ emit_expr ↔ emit_if / emit_loop` form a cycle).
- `emit_ctx.vader` (255) — `EmitterCtx`, `intern_type`, `intern_string`,
  `intern_cell_type` ($Cell\<T\> synth struct).
- `emit_state.vader` (277) — per-fn `FnEmitState` + scope stack + jump
  table.
- `op_select.vader` (464) — `binary_op_for` / `unary_op_for` selectors
  over the I32X / I64X / U32X / U64X / F64X / Bool / Char / String op
  families with width-aliasing rules.
- `dce.vader` (484) — late EmitterCtx-level prunes (unused imports /
  functions / types) ; `slot_coalesce.vader` (265) — coalesce
  non-overlapping same-ValType slot live-ranges. Both run inside
  `emit_bytecode_from_cfg` after body emit.
- `dump.vader` (791) — `dump_bytecode : BytecodeModule → string`, the
  `.virt` text writer (now the snapshot oracle, see below).
- `intrinsics.vader` (99) — `intrinsic_op_for_mangled` table.

Snapshot model : the native Vader CLI is the snapshot **oracle** for
every stage — `tests/snapshot.test.ts` dumps bytecode via
`dumpBytecodeViaVader` into `bytecode.snapshot.virt`. The old
"Vader-emit vs TS-emit byte-diff" parity gap is obsolete (the model
inverted ; the TS bytecode parity dimension + `BYTECODE_DIVERGENT_SNIPPETS`
were deleted).

Open (low priority) :
- [ ] **`emit_body.vader` file split** — at 773 / 800 LoC. Blocked by
      Vader's mutual-import limitation (the `emit_*` cycle above ; same
      constraint that keeps `lower_expr.vader` a single file). When more
      `emit_*` helpers pile on, either add Vader forward-decls or bump
      the per-file cap for this file specifically.
- [ ] **Dispatch-cascade perf** — `emit_call_to_symbol` walks a 4-way
      cascade (slot → intrinsic → fn-table → import) and
      `intern_cell_type` allocates a string per call. Refactor candidate :
      a single `MutableMap(symbol_id, CallTarget)` keyed at registration
      time. Deferred until bytecode emit shows on a profiler.

### 2.4 Port the VM

Sprint plan : [`docs/SELFHOST_VM.md`](./docs/SELFHOST_VM.md). The Vader VM reads `.virt` so each sprint validates against the native pipeline.

- [ ] Sprint 1 — `i32.const` + `return` ; `vader run return_42.virt` exits 42.
- [ ] Sprints 2-5 — locals, binops, control flow, strings, structs, arrays, calls, type checks.
- [ ] Sprint 6 — binary `.vir` loader (optional).
- [ ] Verify `examples/` run on the Vader VM.

### 2.5 Port the WASM emitter — gated on §3.10
(Empty until a WASM emitter lands — see §3.10.)

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

- [ ] **Generic fn-instance harvest** — the TS reference impl used
      `typed.genericFnCalls` to detect every `identity(i32)` /
      `map(i32, i32)` call site at comptime. Vader's typechecker
      doesn't maintain this side-table yet ; without it the
      `## generic instances` section omits fn instances. Closing the
      gap requires adding `generic_fn_calls: MutableMap(usize,
      Type[])` to `TypedProgram` and populating it at every
      generic-fn call resolution in `call.vader`.
- [ ] **for-in ArrayIterator detection** — `for x in arr` auto-wraps
      into `ArrayIterator(T)`. The TS reference impl scanned every fn / impl body for `for
      x in <Array>` and registered the wrap. Mirrors TODO above ; same
      walker shape applies.
- [ ] **Into-coercion materialisation** — blanket `T[] implements[T]
      Into(Iterator(T))` impls contribute their member specialisations
      to the registry. The TS reference impl's `walkImplBodyForCalls` drove this.
- [ ] **Transitive closure** — `closeOverGenericImpls` worklist that
      re-observes the substituted return types of every newly-added
      impl member instance.
- [ ] **Bytecode-driven comptime evaluation** — `@comptime fn` bodies
      with loops, function calls, mutation. The TS reference impl routed this
      through lower → bytecode emit → VM. Vader now has all three
      (`vader/lower/`, `vader/bytecode/`, `vader/vm/`), but the comptime engine
      doesn't yet drive `@comptime fn` bodies through them — `vader run
      main.vader` still reports "not yet implemented (only .virt for now)".
- [ ] **`@field` / `@fields` / `@file` / `@env` intrinsics** — Phase
      5 ships only the four type-reflection intrinsics. The richer
      coverage lands when downstream consumers (lower-time field
      access, `@file` content baking) need them.

#### Divergences from the reference impl (Vader is correct)

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
- [x] **Snapshot flip** — `tests/snapshot.test.ts:22` still compares
      against the frozen TS-generated `lower.snapshot` fixtures. Current byte-match is 148 / 226 ; the
      remaining diffs cluster around comptime VM execution
      (`square_call`, `interp_string_comptime`, `file_decorator`),
      `let t :: i32` in-fn type aliases (no `let_type_aliases` table
      ported yet), defer in nested blocks, and a handful of
      direct-call-overload retypings. Flip when this rate climbs into
      the 200+ range, regenerate the ~226 `lower.snapshot` fixtures
      from `dumpLowerViaVader`, and document any reference-correct
      divergences in the section below.

#### Divergences from the reference impl (Vader is correct)

(none recorded yet)

### 2.6 Port the type-checker (last)
- [x] Port to Vader.
- [ ] Snapshot-test parity on every sample.

#### Bugs surfaced while porting the typechecker — open
- [x] **`if cond { i32_expr } else { 0 }` doesn't collapse `i32 | {integer}` to `i32`** (surfaced 2026-05-26 by the LSP on `stdlib/std/semver/semver.vader::caret_upper`). When one branch of an `if`-expression has a concrete numeric type (`p.major: i32`) and the other branch is a free-integer literal (`0`), the Vader self-host typer joins them as a union `i32 | {integer}` instead of promoting the free int to the concrete width. The LSP then flags downstream uses with T3017 (`operator not defined for these operand types: i32 | {integer} and {integer}`) on `maj + 1`. The TS reference impl reported zero errors on the same source, so it's a Vader-only gap — likely a missing case in `join_types` / `merge_branches` where one operand is `FreeInt` and the other is a concrete primitive width. Workaround at user level : explicit cast (`{ i32(0) }`) in the partial-default branch, but that defeats the point of free-numeric defaulting. Fix probably one-liner in `vader/typecheck/{join,merge}.vader` (mirror what `is_assignable` does for FreeInt → concrete).
- [x] **`is Type` antipattern in union-typed values** — `match expected { is Type | null }` etc. `expected is Type` against the closed `Type` union always returns false (the runtime tag is the variant tag, not the union tag). Bit me twice : `seq_lit.vader::infer_seq_lit` ignored every union-shaped expected slot ; `infer_seq_lit`'s "`picked is Type`" branch never fired. Fix is `match { is null -> {} _ -> ... }`. Search the codebase for other `is <UnionAlias>` checks (none found via grep on the typecheck dir, but worth a pass over `vader/resolver/` and `vader/lower/`). Either lint this at the compiler level or rename the patterns to avoid the trap.
- [x] **`vader build -o <path>` honored** (2026-05-17) — `cmdBuild` now pre-strips `-o <path>` POSIX-style and treats it as `--out=<path>`. Earlier the `--`-prefix filter dropped both `-o` and its value into positionals ; `outFlag` stayed undefined and the binary landed at the default location.
- [~] **`settle_external_expr_bodied_returns` walks every non-entry module's body** (added 2026-05-17, `vader/typecheck/orchestrate.vader`). Runs the full `walk_bodies` pass (FnDecl + ImplDecl + ConstDecl + AssertDecl) instead of just the expression-bodied fns whose returns need patching. Triggers on any module that has *one* expr-bodied fn ; for std/iter etc this can multiply typecheck time. Scope it down to expr-bodied FnDecls + impl methods only.
- [x] **Code-size explosion when adding a small branch to `is_assignable`** (mitigated 2026-05-21 via Phase B of `CC_COMPILE_TIME_REDUCTION.md`, verified 2026-05-26). `is_assignable` moved from `vader/typecheck/type_ops.vader` to its own file `vader/typecheck/type_assign.vader` and was split into one helper per source variant (`is_assignable_struct`, `is_assignable_array`, `is_assignable_fn`, `is_assignable_union`, `is_assignable_tuple`, `is_assignable_trait_from`, `is_assignable_freeint`, `is_assignable_freefloat`) plus a shared `check_common` for primitive / enum / never / type-meta / type-param fast paths. The dispatcher (`is_assignable` itself) is now ~25 LoC of `match from { ... }`. Measured 2026-05-26 on `vader/cli/main.c` : `is_assignable` C body is **80 lines** (down from 51 536 pre-split, -99.85 %). Adding a new arm goes into one of the per-variant helpers ; the old monolithic explosion can't recur because there's no monolith to inline-clone. Cause-root (c) from the mitigations list — c-emit's match-arm cloning behaviour — turned out to be irrelevant once the monolith was broken up.
- [x] **`build/vader` background processes don't get killed when typechecker / VM regresses** (2026-05-17). Found 3 `build/vader run tests/snippets/custom_iter/bytecode.snapshot.virt` + 1 `bun src/index.ts run bench/map_iter.vader` processes pinning 100% CPU for **33+ hours**, residue of sessions where custom_iter's bytecode VM execution actually did loop forever (since fixed). `parity.test.ts` has a 30s per-test timeout but the native runner spawned from it doesn't inherit that — once Bun's test driver bails on timeout, the spawned VM keeps running. Add a `kill` step to the native test driver's cleanup, OR run each child under a hard wall-clock budget (`timeout 30s build/vader run ...`).

- [ ] **DCE primitive trait-impl entries via "primitive-as-value" usage tracking** (2026-05-25). `vader/midir/emit.vader::build_vtables_from_entries` (the live vtable-reachability gate ; TS's whole-program `drainPending` DCE was never ported) punts on primitive receivers — a `struct_sym_id != null && !reachable` skip — every primitive impl skips the gating, so the full `Display` / `Equals` / `Add` / `Sub` / `Mul` / `Div` vtable survives as soon as any `virtual.call` against the trait survives. Concrete cost on a generic `[T: Display]` fn lowered via erasure : 15 `to_string` imports + 15 `_vt` trampolines + 15 vtable rows for *one* `println(some_i32)` call. Stop-gap landed 2026-05-25 : `@specialize` on the four `std/io` wrappers (sidesteps virtual.call entirely for the common case). Proper fix : track which primitives are actually materialised in reachable code (literal consts, casts, fn signatures' param/return types, struct field types) and gate primitive-receiver impls on that set. Implementation surface : (a) add a `usedPrimitives: Set<PrimitiveName>` populated during the worklist walk in `pruneUnreachable` (visit `LoweredIntLit` / `LoweredFloatLit` / `LoweredCast` / `LoweredFieldAccess` / fn-decl param-types) ; (b) extend the `pendingVirtual` drain with a primitive-aware gate analogous to the existing struct gate ; (c) verify the change doesn't break tag-aware paths in trait_box_range_iter / json_basics. Earns the win for *every* generic `[T: Display]`-shaped user code, not just the stdlib wrappers — `@specialize` is the local opt-in, this is the global default.

- [ ] **Self-host closure capturing two free vars segfaults at runtime** (2026-05-25). While simplifying `vader/typecheck/orchestrate.vader::pull_referenced_external_types` to route through the canonical `for_each_type` walker, replacing the explicit recursion with `for_each_type(t, (sub: Type) -> register_named_external(sub, entry, per_module))` made the self-host binary SIGSEGV (exit 139) at the first call. The only prior closure-with-capture in the tree (`vader/midir/lowered_walk.vader:222`) captures a single `ctx` struct ; my version captures two free vars (`entry: TypedProgram` and `per_module: MutableMap(string, TypedProgram)`). Reverted to explicit per-variant recursion with a code comment pointing at this entry. Probable root cause : `vader/lower/closure_analysis.vader` + `LoweredMakeClosure` emit doesn't handle the second captured slot correctly, or the `$Cell_T` synthesis miscomputes the layout. Repro path : restore the `for_each_type` form at `orchestrate.vader:758` (see git history of the 2026-05-25 fix commit), rebuild, run `./build/vader dump --stage=typed-ast vader/cli/main.vader`. Until fixed, prefer the explicit walker shape OR bundle captured state into a single struct (the lowered_walk.vader pattern).

#### Language ergonomics surfaced while porting the typechecker — open
- [x] **`!is` (negated type-test) operator** — landed via commit `03525c1f` ("feat(parser): add `!is` operator and `for <range>` shorthand"). Both Vader self-host parser (`vader/parser/parser.vader:2392-2418`) and TS parser (`src/parser/passes/expr.ts:122`) desugar `x !is Y` to `Not(BinaryOp.Is(x, Y))`. Formatter restores the spelling (`vader/fmt/printer.vader:1276-1284`). SPEC.md §"operator precedence" documents the form (lines 299, 330, 335).
- [x] **`if a is X { a.field }` doesn't narrow `a` across statements** — single-expression guards work but `if a is X { for v in a.variants { … } }` requires a `match a { is X as ax -> { for v in ax.variants { … } } _ -> {} }` rewrite. Bit me in `vader/typecheck/binary.vader::types_overlap` ; eventually settled on a tiny `union_variants :: fn(t) -> Type[] | null` helper to dodge the narrow. Either tighten the flow analysis so `a.variants` inside the if-then sees the narrowed type, or document the rewrite + add it to the formatter's lint pass.

#### Typechecker port follow-ups — open
- [x] **Typecheck misses missing-argument errors (T3003 under-reporting)** (2026-06-05).
      Vader's typechecker does NOT flag a call with too few arguments where the
      TS reference impl did. Surfaced via `builder_roundtrip` diag-parity : `exec(module_a)`
      (1 arg) against `exec(module: Module, host_argv: string[])` (2 required
      params) — the TS reference impl emitted T3003 "wrong number of arguments" at the call site,
      Vader emits nothing. Both *normally* missed it (the divergence was masked) ;
      adding two fns (`grow` / `maybe_grow`) to `stdlib/std/collections/collections.vader`
      during the MutableMap-resize chantier shifted symbol ordering enough that
      TS's signature resolution fired in time and caught it while Vader still
      didn't → the divergence surfaced. Worked around by fixing the stale
      snippet (`exec(module_a, [])`), but the real bug is the Vader gap : the
      arity check in `vader/typecheck/call.vader::infer_call` should reject
      under-application of a non-defaulted, non-variadic fn. Tied to the
      `pick_overload` / symbol-id-ordering fragility (see §2.6 re-audit #6).
- [ ] **Codegen: narrowed scrutinee miscompiles when an arm writes through it
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
- [x] **Native-emitter gaps surfaced by the oracle flip — 11 fixed, 0 open**
      (2026-06-05). With `bytecode.snapshot.virt` now native-emitted,
      `vader_vm.test.ts` runs native bytecode for the whole corpus and exposed
      11 mis-compiles. FIXED this session:
      - `enum_to_repr_cast` — VM `convert_value` sign-extended an unsigned
        source widening to i64 ; now zero-extends (`vader/vm/value.vader`).
      - `numeric_context_sensitivity` — the `.virt` parser collapsed a 64-bit
        const that fits signed-i32 to `I32Const`, losing the high bits for the
        unsigned-display path ; 64-bit widths now keep `I64Const`
        (`vader/vm/parser.vader`).
      - `null_blockres` — `i32.eq` over a `null` operand trapped ; `==`/`!=`
        now compare by null-identity (`vader/vm/exec.vader::apply_eq_binop`).
      - `enum_implements_trait` — `EnumName.Variant.method()` dispatched on the
        lowered repr (i32) not the surface enum type ; UFCS now looks up the
        impl on the typed type for enum receivers (`vader/lower/lower_expr.vader`).
      - `sam_impl` — a user `i32 implements Display` lost to the builtin in
        `find_impl_member_for` (first-match wins) ; a user (non-`@intrinsic`)
        impl now shadows the intrinsic builtin (`vader/lower/lower_expr.vader`).
      - `defer_block` — `defer` was dropped : the MIDIR CFG had no
        `InstrDeferPush`/`InstrDeferPopExec`, so `LoweredDeferPush`/`PopExec`
        vanished at CFG-build. Added the two Instr kinds + build + emit arms
        (cfg/build/emit/analyses/scheduler/dump in `vader/midir/`). `defer` now
        runs on normal exits.
      - `_diag_iter_collect` — `(0..<5).filter(keep).collect()` trapped
        `virtual.call Iterator.next : no impl for type N`. `filter`'s ERASED body
        (T→Any) constructs a fully-erased `FilterIterator<Any>`, but the comptime
        harvest only sees the CONCRETE call-site `FilterIterator<i32>`, so the
        erased struct's `Iterator.next__Any` impl was never materialised → no
        vtable row for the tag the runtime value actually carries. `lower_struct_lit`
        now queues a fully-erased generic-struct instance (`args_all_any_leaves`)
        via `queue_generic_impl_receiver`, so the joint fixpoint materialises its
        impl members (self = the erased struct type). Gate restricted to FULLY
        erased instances : queuing a mixed one (`MapIterator<string, Any>`) forces
        a default-method body whose mixed-suffix sibling `next__string__Any` the
        materialiser never produces (GATE-B1 emit panic, surfaced on `json_basics`).
      - `for_in_iter_trait` — `s.chars().filter(is_l).count()`. The
        `FilterIterator<Any>` erased leg is the fix above ; the residual was a
        DISTINCT class : `StringChars` (the NON-generic stdlib char iterator from
        `chars()`) reached via `FilterIterator.next`'s trait-typed
        `self.source.next()` vcall never got its `Iterator.next` surfaced —
        `surface_stdlib_impl_externs` only surfaced directly-referenced or
        PRIMITIVE-receiver members (the F3 gate). Extended the gate to non-generic
        STRUCT receivers of a virtually-dispatched trait, but GATED on a new
        `constructed_struct_symbols` set (populated from `lower_struct_lit`, joined
        into the drain-fixpoint `cur_total`) so only ACTUALLY-CONSTRUCTED structs
        surface : StringChars (built by `chars()`) yes, an unconstructed stdlib
        implementor (`std_io$IOError`) no — the broad gate pulled IOError into
        `trait_virtual_dispatch`, bloating its table ; the constructed gate is
        drift-free. StringChars is the sole non-generic Iterator implementor.
      - `alias_import` / `namespace_import` — `io.println("hi")` (`println<T:
        Display>` is generic) panicked at emit `unresolved callee 'println'`.
        `lower_call` runs `try_lower_namespace_call` BEFORE `try_lower_generic_fn_call`
        and short-circuits, calling `register_nongeneric_stdlib_fn` (no-op for a
        generic fn) and emitting a bare-symbol callee → the generic instance
        `println__string` is never harvested/mangled → unresolved at emit (GATE-B1).
        Extracted the generic-call core into `emit_generic_fn_call(ctx, call, type,
        fn_sym, ft, callee_span)` ; the namespace path now fetches the member's
        generic `FnType` cross-module (`evaluated.modules[sym.module].typed.decl_types`
        — the namespace member-type table holds only type-kind members, not fns) and
        delegates to it for generic members, exactly as the direct-ident path does.
        Both `_config.json` bytecode-exclusions deleted ; snapshots regenerated.
      - `std_time` — `seconds(i64(3)).format()` printed `3000000000 ns` not `3 s`.
        ROOT (the memory's "transitive import" note was WRONG — `abs` is DIRECTLY
        imported): `abs(i64)`'s expression-bodied return type stayed `?` in std/time's
        view, so `a :: abs(n)` typed `any` → the i64-literal threshold compares emit
        `i32.lt`, truncating `3e9` past i32. `populate_imported_fn_overloads` runs
        TWICE for a non-entry module — once BEFORE `settle_external_expr_bodied_returns`
        (so settle's own UFCS sees cross-module overloads) capturing the still-`?`
        return, once after — and `push_overload` APPENDS, so the stale `fn(i64) -> ?`
        sat before the settled `fn(i64) -> i64` and `pick_overload` picked it. FIX:
        clear `other_typed.imported_fn_overloads` before the post-settle re-populate
        (orchestrate.vader) so the bucket is rebuilt from settled `decl_types`. The
        entry module already populated once (post-settle) so it was unaffected — the
        bug was non-entry-module-only. Drift = IMPROVEMENT (4 snippets : more
        cross-module expr-bodied returns now resolve concrete instead of `?`).
      ALL 11 fixed. Separately tracked (NOT among the 11) : `defer_on_panic` needs
      the VM to drain the defer-stack on a TRAPPED exit (a substantial `exec`-loop
      control-flow change — `frames` is local to `exec`, so the drain must happen
      inside it, intercepting the inline-dispatch Trap) ; `defer_in_lambda` — a
      defer thunk *inside a lambda* capturing an outer-lambda-captured var fails to
      resolve it, truncating the lambda body (`unreachable ; unresolved ident x`),
      a nested-capture chain through the defer thunk.
- [x] **Cross-module folder modules** — landed 2026-05-17. Root cause was a runtime UAF : `vader_read_dir` stored `ent->d_name` (DIR-owned, reused on next readdir) without copying. `mod_a` was the first user-folder ; by the time its name was read back, the buffer pointed at garbage so `load_module_files` saw an empty entry and skipped the module. `vader_string_alloc` + memcpy in `vader_runtime.c`. Also `join_path` now strips leading `./`, `dump_program_with_others` writes one section per loaded module (sorted), and `settle_external_expr_bodied_returns` walks every non-entry module's bodies so per-module `expr_types` populate for the dump.
- [x] **Generic trait method substitution** (2026-05-17) — landed via `trait_decl_owners` side-table + `substitute_by_name` over `Yield(T)` etc. `try_default_trait_method` for inherited Iterator defaults landed too. Unblocked iter_coerce_array (with `try_array_to_iter` in coerce.vader), iter_combinators, iter_zip_chain, trait_box_range_iter, string_codepoints. Still blocked on default-method *materialize-into-impl-with-original-line:col* (separate item below).
- [x] **Generic fn-call argument inference back-propagation** (2026-05-17) — `call.vader::infer_call` now substitutes bindings into each param BEFORE typing it (so lambda's expected fn-type reflects already-bound type-params), and `unify_type_param` tightens Free* bindings when a later arg pins the same TypeParam to a concrete numeric. `expr_lambda.vader::pick_final_return` falls back to body's defaulted type when expected is TypeParam-bearing.

- [x] **Default-method materialize into impls with original line:col** (verified 2026-05-26). Landed via commit `5e4c1b84` (`feat(resolver): default-method body materialization`) with follow-ups `2b8ddab4` (substitute_by_name walks TraitType args), `cded9837` (skip walk_fn_body for materialized clones), `d9303880` (chain struct→trait→receiver substitution). The full expression walker lives in `vader/resolver/substitute_body.vader::substitute_expr_full` (291 LoC), called from `vader/resolver/materialize.vader::materialize_default_members`. All 5 previously blocked snippets pass parity : `custom_iter`, `custom_iter_generic`, `iter_defaults`, `trait_dispatch_generic_iter`, `for_in_iter_trait`.
- [x] **T3006 (trait bound not satisfied) at call sites** (2026-05-17) — landed via `fn_decls: i32 → FnDecl` side-table (cross-published across modules), idents-write on type-param decl sites in the resolver, and `check_typeparam_bounds` post-pass in `call.vader::infer_call`. Closed `conformance_explicit`.
- [ ] **`a == b` on user structs → `a.equals(b)` lowering at typecheck** — the expected lowering records the synthesised CallExpr / FieldExpr in `expr_types` at the BinaryExpr's span so the dump shows `bool` / `fn(Money) -> bool` / `Money` entries even though the source is just `a == b` (the TS reference impl did this). Self-host returns plain `bool` without the synth entries. Blocks `op_overload_eq_ord` lower-parity.
  - **Investigation 2026-05-26** : the visible divergence is downstream of a deeper issue. Vader's `materialize_default_members` runs at typecheck time (`vader/typecheck/orchestrate.vader:513`) AFTER the resolver, so cloned `self` / `other` IdentExprs in the materialised body keep trait-source spans that aren't bound in the impl module's `resolved.idents`. The fix shape : run materialization at resolver time, INSIDE impl resolution (a `resolve_impl_decl`-time hook in `vader/resolver/resolve.vader`), so the cloned body gets walked + bound there. Effect : Vader's `lower_ident` hits `unresolved ident self` on every cloned receiver, the materialised fn dumps as `:?` everywhere, and the `a == b` → `a.equals(b)` rewrite degrades to a `.equals` FieldExpr call against an unreachable `self`. **Same root cause also blocks `custom_iter` / `custom_iter_generic` / `iter_defaults` / `trait_dispatch_generic_iter` / `for_in_iter_trait` lower-parity** (those pass typecheck-snapshot parity per the row above, but their lower.snapshot still diverges on the materialised-body `:?` entries). Proper fix : move `materialize_default_members` to a project-level resolver post-pass that knows the trait_decl (cross-module lookup) and walks the cloned bodies through the resolver to mint Local symbols + bind their cloned spans. Add a `find_foreign_ident_sym` in `vader/lower/lower_expr.vader` so lower can fall back to the trait module's `idents` when the impl's map misses. Multi-day chantier. A local fix attempt (walk materialised body silently at typecheck) regressed 5 tests with bogus `:?` entries — reverted.
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

#### Reprofile 2026-06-17 (`dump --stage=c vader/cli/main.vader`, `-O2 -g` + `sample`, 256/512 MB)

Wall ~8 s, peak RSS 1.12 GB. Self-time is **~74 % substrate, not pass logic**: **GC+alloc
~34 %** (`vader_minor_collect` 14.7 %), **string Hash + atoms ~27 %** (`string_Hash_hash`
11.8 %, `atom_intern` 8.3 %), **MutableMap ~13.5 %** (keys()/values() materialize). Live-set:
**ARRAY_BUF 266 MB / 937k = 42 %** (MutableMap backing), 72-B structs ~120 MB, atom table
249k / 39 MB. Four optimization tracks (ideas 1-4):

- [x] **(idea 1) String Hash reads a content-hash cached on the atom** — DONE 2026-06-17.
      `string_hash_fnv1a64` walked `s.bytes()` (allocating a view per call → fed the 14.7 %
      `minor_collect`) and recomputed FNV every lookup (11.8 % CPU). Now the FNV-1a-64 of the
      bytes is computed once at intern and cached on `vader_atom_entry_t.hash`; the trait is
      `@intrinsic` → `vader_string_hash` reads it O(1). **Measured: −25.6 % instructions,
      −12 % wall**; `string_Hash_hash` leaves the profile. **Content-based** (NOT id-based):
      an earlier id-hash attempt (Approach 3) was reverted — atom ids are reused across GC, so
      `mix(id)` made map iteration order (and thus emitted output) **GC/arena-dependent**;
      FNV(content) keeps it deterministic. Fixed-point byte-identical; GC-stress small-vs-big
      byte-identical; 30 snapshots regen (pure .virt representation drift — no map-order change,
      C + VM runs unchanged). Plan `.claude/plans/atom-hash-cache.md`. Follow-up: **Flavor B** —
      unify the atom-table bucket hash onto the cached FNV-64 (drop `vader_atom_hash`).

- [x] **(idea 2) Non-allocating MutableMap key/value/entry iteration** — `values()`/`keys()`
      materialize a fresh array just to iterate (CPU + ARRAY_BUF alloc). Add a non-allocating
      entry iterator; flip the hot self-host `for k in m.keys()` sites. Pairs with `for [k, v]
      in m` (`.claude/plans/destructure-via-into.md`). **User-flagged: do.**

- [ ] **(idea 3) Int-keyed side-tables → flat array / `IntMap`** (**to discuss**). Dense
      `Symbol.id`-keyed maps want a flat `T[]` (or `IntMap` for sparse) — cheaper CPU + RAM.
      Crux from `project_compiler_intmap_b`: does the value de-erase. Overlaps the "shrink
      live-set" lever (b).

- [~] **(idea 4 — umbrella) Cut allocation volume → shrink the GC ~34 %** — ~37M objects/build;
      `minor_collect` 14.7 % even at big arenas. Driven by ideas 1/2/3 + `span_key` minting +
      per-block `out.push`. No single fix; landing 1/2/3 reduces it. Reprofile between rounds.

#### Runtime GC

- [x] **Adaptive young-arena sizing (`young ∝ old_live`)** — DONE 2026-06-20.
      Root cause of the self-compile being GC-bound: every minor collect
      conservatively re-scans the *whole* old card table (`vader_runtime.c:1484`,
      `memset(card_table, 1, …)` after each collect), so a minor costs O(old).
      The young arena stayed pinned at 32 MB (it only grew when survivors didn't
      fit, which high-churn workloads never trigger) → a collect every 32 MB of
      churn → total card-scan work `(churn / 32MB) × old` = **quadratic in the
      old live set**. **Measured at default arenas: `dump --stage=bytecode
      vader/cli/main.vader` was 38 s, ~89 % GC** (huge arenas → 4 s, isolating the
      GC overhead). Fix: after a standalone minor, grow young toward
      `old_live / VADER_GC_YOUNG_RATIO` (default 2), hysteresis ≥1.5×, capped at
      `VADER_GC_YOUNG_MAX`; `0` disables it. Sizing young ∝ old makes the total
      scan linear in churn. The old-proportional growth overshoots a roughly
      workload-independent working-set cliff (~128-160 MB for the self-compile),
      so the target is **capped** at `VADER_GC_YOUNG_CAP` (default 192 MB) — growing
      past the cliff trades RSS for no speed. **Result: self-compile 38.6 s → 8.4 s
      (4.6×, stable); peak RSS unchanged vs baseline (~1.2 GB both — the cap avoids
      the uncapped version's ~+200 MB overshoot)**. NB self-compile RSS is noisy
      run-to-run (±~200 MB, from the young-growth realloc transients) — the speed is
      the solid win, RSS is neutral. Small programs unaffected (hello-world 48 MB —
      old stays small → young stays at the 32 MB floor). **Runtime-only → no reseed**: emitted bytecode
      byte-identical across ratios/caps; `verify.sh` fixed-point green; suite 2280/0.
      Knobs: `VADER_GC_YOUNG_RATIO` (default 2, 0 disables) + `VADER_GC_YOUNG_CAP`
      (default 192 MB, 0 uncapped). `runtime/c/vader_runtime.c::vader_young_maybe_grow_adaptive`.

- [x] **Specialized pointer sort in `vader_string_prepare_marks` — obsolete.**
      The whole string mark-sweep (`vader_string_prepare_marks` + its `qsort`)
      was removed when strings became u32 atoms (`7eb041a8`) ; no string-mark
      sort exists anymore.
- [x] **Tune `VADER_STRING_SWEEP_MINOR_INTERVAL` — obsolete.** The knob + the
      string-sweep throttle were removed in the atoms migration (`7eb041a8`) ;
      the symbol no longer exists.
- [x] **GC arenas auto-grow — OOM ceiling removed** (DONE 2026-06-06).
      The fixed-semi-space → minor → major → trap path was replaced by
      flip-with-resize auto-grow (`27eff0fb`), then RAM-proportional sizing
      (`f2acfb5c`, single `VADER_GC_RAM_PERCENT` knob) + adaptive young arena
      (`d41e21ef`) + a non-moving mark-sweep old generation (`fcfd1148`). The
      self-compile now runs with zero env knobs on any platform ; the env vars
      remain an advanced escape hatch. (Original ask dated 2026-06-04.)
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
      the emitter's own tables at the peak. Candidate levers (none committed) :
      (a) release `typed` / `evaluated` before the CFG→emit tail (extract a
      helper returning `(lowered, entry_name)` so `pipeline` leaves scope) ;
      (b) shrink the maps — span-key→i64, flat `Type[]` for dense `Symbol.id`-
      keyed maps, `IntMap(V)`, small-map specialisation (detailed under the §3.5
      working-set-reduction item). Orthogonal to the GC-arena-growth item above
      (that fixes the OOM trap, this shrinks what's retained).

#### Lower

- [x] **Replace `span_key`'s string interpolation with an i64 key**
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
- [x] **Reprofile after these land** — the d467d5b1 lookup_local_symbol
      fix cut 49 % off `orchestrate.vader` lowered-ast on its own.
      Each fix shifts the next hot path, so the order matters less
      than re-sampling between rounds.

#### Typecheck

- [x] **Scope-down `settle_external_expr_bodied_returns`** — already
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
- [x] **String interning for hot identifiers** — names like
      `"self"`, `"Iterator"`, `"next"`, `"to_string"` are repeatedly
      compared / allocated. An interning table would replace string
      equality with identity comparison and drop the per-mention
      alloc. Surface : `vader/resolver/symbol.vader` for the canonical
      home ; consumers in lower / typecheck switch to comparing
      interned ids.

### 2.7 Bootstrap success check — done (C-seed fixed point)
The original TS-compiler bootstrap path was superseded by the C seed.
- [x] C seed → compiler (`stage1`) ; `stage1` → compiler (`stage2`) ; `stage1` == `stage2` byte-identical (identical outputs + idempotence in one check).
- [x] Enforced by `bootstrap/verify.sh` (`stage1` == `stage2` byte-for-byte + seed freshness).

### 2.8 Freeze the TS compiler — done
- [x] Final TS compiler tagged (`v0.0.0-pre-mvp-final-ts`) then deleted (`81053f16`, §2.8) ; bootstrap documented in `docs/BOOTSTRAP.md`. Vader self-hosts from the C seed.

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
- [~] **Lazy-materialise stack values in C-emit** (companion to DCE). Today's wins target primitives ; `local.get`/`local.tee` of ref/any still snapshot eagerly into a refTmp for GC-precision. Future : (1) detect call-arg pairs with no allocation, (2) skip explicit zero-init for primitives, (3) pre-declare blockres slots on first use. Each ~½ day.
- [ ] **Value-type structs (`CodeInfo`-style)** — open discussion. Today every struct is heap-allocated + boxed. For small immutable structs never trait-boxed (e.g. `CodeInfo { id: string, message: string }`), a register-by-value pass would be free. Trade-offs : (a) syntactic distinction (`value struct` keyword? `@value` decorator? auto-detect?) ; (b) interaction with `is Trait` (value-types can't downcast — compile error?) ; (c) match patterns binding by reference ; (d) multi-register return ABI ; (e) escape analysis as a downgrade path. Decision needed before implementation.
- [ ] **Inline trivial trait-method impls before bytecode emit** (deferred 2026-05-14). Methods like `i32.gt :: fn(a, b) -> bool { return a > b }` and one-arm vtable dispatchers emit a `Call` op each ; clang `-O3` inlines them in native, the VM doesn't. Plan : classify inlinable `LoweredFnDecl`s (single `LoweredReturn` of a pure expression, ≤ N midir ops, no recursion) + midir pass that replaces `Call(callee=inlinable)` with the substituted body + `pruneUnreachable` drops dead callees. **Why deferred** : current bench workloads (mandelbrot, primes) have no fn calls in hot paths ; VM bottleneck is parse + typecheck + lower (3.5+ s per invocation), not exec. Revisit when (a) bytecode-cache lands and (b) a bench workload shows fn-call density as a hot spot. ~1 day.
- [x] **Open-addressed hash table for `MutableMap` — DONE via compact-dict** (`6c50d7a2`). An earlier Robin-Hood attempt was disqualified by bench (`map_iter` +59 % — boxed `vader_box_t` struct elements defeat inline-storage locality) and reverted ; a later **compact-dict** open-addressed design (dense entry array + slot index) shipped without the iteration regression — `std/collections` now documents the compact hash map. (The "disqualified, chaining is the right call" verdict below was the Robin-Hood result, since superseded.)
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
  - **(a) Split C emission per Vader module + drive `cc -j`** — unlocks parallelism and `ccache` for iterative rebuilds. Biggest expected win. Touches `vader/c_emit/emit.vader` + `vader/cli/main.vader` (`cmd_build` — N `cc` calls + final link).
  - **(b) Pre-compile stdlib monomorphisations to `.o`** — once-per-toolchain artefact cached on disk ; user-CLI rebuilds only re-cc user TUs. Depends on (a) for the TU split.
  - **(c) Type-erase non-perf-critical generic containers** — **paused 2026-05-19 via option (Φ)**, see `docs/STDLIB_GENERIC_COLLAPSE.md` Decision log. Shipped sub-deliverables : Phase 0 (`4f639e99`) vtable runtime + slot registry + internal `Any` Type kind ; Phase 1 (`0d9ebc80`) packed inline-box multi-field POD ≤ 16 B ; β raw-array for-in fix (`aa2dc5ce`) ; Phase 2 plumbing (`9b38e860`, `ef76fe6f`) committed but gated off. Phase 2 §9 documents 9 cascade issues encountered ; the cascade is fundamental (Any-bearing queries against `@specialize`d types' concrete-arg registries), so full automatic erasure deferred to a future investigation with a different design (option (γ) "synthesise Any-bearing instances for every `@specialize`d reachable type" estimated 3-5 d, worth pursuing only when cc -O3 baseline becomes a workflow blocker). Iterator-skip `@specialize` decorator landed in the same arc.
  - **(d) `__attribute__((cold))` on rarely-hit generated fns** — calms the inliner / frees IPSCCP budget. Candidates : error paths, diagnostic builders, init-only helpers. Touches `vader/c_emit/emit.vader`. Smallest expected win — measure on a smaller TU first since the structural-pass dominance pattern caps the ceiling.

### 3.6 Memory model extensions
- [ ] Explicit allocator API (arenas, pools) for perf-critical paths.
- [ ] `unsafe { }` blocks for low-level FFI.

### 3.7 Tooling
- [ ] LSP server (in Vader) — diagnostics, hover, go-to-def, completion.
- [~] **LSP completeness roadmap** (added 2026-06-07) — plan in [`docs/LSP_COMPLETENESS.md`](./docs/LSP_COMPLETENESS.md). Takes the server from core navigation to feature-complete : shared infra (project-wide reference index, workspace-symbol index, cross-file diagnostics, file-watch, incremental analysis) then the feature tiers — quick wins (`documentSymbol`, `formatting` via the existing `vader/fmt`, `documentHighlight`, `foldingRange`, `documentLink`), navigation (`references`, `workspace/symbol`, `typeDefinition`, `implementation`, `callHierarchy`), productivity (`codeLens` run-test, completion docs, `linkedEditingRange`), and protocol modernization (pull diagnostics, incremental sync). Sequencing + per-feature code hooks in the doc. Cross-ref the `LSP code actions framework`, completion, rename, and find-references items.
- [x] **LSP : revisit hover signatures once the typechecker is self-host.** Today the indexer is AST-only ; hover on local bindings falls back to source slice + literal-suffix heuristics. When the typechecker lands in Vader (§2.6), consult its inferred-type table directly for proper `name: T` rendering. Same upgrade fixes param hover under generics + match-arm pattern bindings.
- [i] **LSP : spurious L0005 "character literal must contain exactly one codepoint" on `'é'`** (investigated 2026-06-17, *not a current-compiler bug*). Reported on `stdlib/std/string/string.vader:907` (`assert_eq(byte_decode_at("héllo", usize(1)), 'é')`). The on-disk literal is precomposed é — bytes `27 c3 a9 27` = `'` + U+00E9 + `'`, a single codepoint — and the current compiler accepts it : `dump --stage=ast` reports **zero** `error[L0005]` on the file, the isolated literal lexes clean, and the full suite (which runs `test_byte_decode_at`) is green. `lex_char` advances by `codepoint_byte_len` (since 2026-05-15, `dc457047`), so multi-byte single-codepoint literals have always been valid. The live editor error is therefore either (a) a **stale LSP server** running an older in-memory binary — reload the window so it picks up the freshly-built dist binary, or (b) the unsaved buffer holds a **decomposed** é (NFD : `65 cc 81` = `e` + combining U+0301 = *two* codepoints), which the lexer correctly rejects even though it renders as one grapheme. **Optional UX follow-up** : when a char literal is a base char + ≥1 combining mark, emit a clearer L0005 hint ("looks like one character but is N codepoints (NFD); use the precomposed form or a string") instead of the bare codepoint-count message.
- [~] **LSP : inconsistent semantic highlighting** (noted 2026-06-15) — the syntax/semantic colouring isn't always consistent ; observed on `self` in `stdlib/std/core/primitives.vader`'s `Hash` impl block (`i8 implements Hash -> u64(self)` etc.) — `self` is highlighted/underlined inconsistently across otherwise-identical lines, and `isize` picks up a spurious squiggle. Revisit when reworking the LSP (likely the semantic-tokens classifier mis-scoping `self` / a stale diagnostic on `isize`).
- [x] **LSP : inlay hints for inferred types** (LSP 3.17 `textDocument/inlayHint`). Landed in `vader/lsp/inlay_hint.vader` (capability advertised, request routed, types pulled from `typed.local_types[sb.name_span.hash()]` and `typed.decl_types[sym.id]`, defaulting + UnresolvedType / FreeInt / FreeFloat / TypeMeta filters). **Placement fixed (2026-06-17).** Root cause of the misalignment / single-column cluster was the column anchor : `sb.name_span.end.column + 1` keyed off the *name* side, whose gap to the operator is padded under vertical alignment (`a   :: 1` / `bb  :: 2`), so hints crowded onto one column. Fix : anchor on the **value** span instead — the operator→value gap is canonically one space and the operator is two chars, so the second operator char is at `value.span.start.column - 3` (0-based). The hint now nests *between* the operator's two chars (`name :u8: value` / `name :u8= value`) at each binding's own line, regardless of name-side alignment. Both emit paths share `emit_operator_hint`. The `name_span.end + 1` hypothesis (a) was the actual bug — parser spans were fine. Visual layout confirmation needs a live editor session (the native `vader lsp` can't be driven by piped JSON-RPC, `tests/lsp.test.ts:16-19`).
- [x] **LSP : R2023/R2001 when opening a stdlib source file** (fixed 2026-06-17). Opening a file under the repo's `stdlib/` (e.g. `stdlib/std/core/buffer.vader`) reported `R2023 module 'std/core' already declared by another folder` + `R2001 entry file's containing folder is not in any scanned root`. Root cause : `load_project_with_overlay` always set `stdlib_root = default_stdlib_root()` (the binary-relative `"stdlib"`), while the editor passes an absolute `file://` entry → `find_manifest_root` yields an absolute `project_root`. `is_under_any_root` then compared the absolute entry folder against the relative `"stdlib"`, failed to see the open stdlib file was already rooted, and pushed its folder as a *separate* root → `discover_modules` scanned `std/core` under two path-string spellings of the same dir → R2023. Fix : resolve the stdlib root from the project manifest (`vader.json::stdlib`) joined onto `project_root`, so it shares the entry's path-form (relative `""`→`"stdlib"` for cwd-relative builds — byte-identical to before ; absolute for `file://` entries). `display_path_for` strips this prefix, so std display paths stay `std/...` either way and self-host output is unchanged. The manifest is now read once (`read_manifest` → both `stdlib` + `modules`) instead of parsing `vader.json` twice. Reproduced + verified via a pre-fix vs post-fix native binary on an absolute stdlib path. Guards : `vader/resolver/module.vader` colocated tests.
- [x] **LSP : documentLink** (`textDocument/documentLink`, shipped 2026-06-17, `vader/lsp/document_link.vader`). `import "path"` strings are clickable and jump to the imported module's source. The path-string range is recovered without an AST change — re-parse the doc and scan each `ImportDecl`'s span for the opening quote (module paths are ASCII, so byte offset from the decl start maps to a column). Targets resolve via `resolver.vader::module_path_to_absolute` (same std/ vader/ ./ logic as goto-def) ; folder modules link to their first `.vader` file ; unresolvable prefixes (project-root / third-party) get no link. Capability advertised in `lifecycle.vader` (`documentLinkProvider`, `resolveProvider = false`), routed in `main.vader`. Follow-up : link a folder module's main file (`<name>.vader`) over the first-by-sort ; resolve project-root-relative imports once the workspace root is plumbed.
- [x] **LSP : typeDefinition** (`textDocument/typeDefinition`, shipped 2026-06-17, `vader/lsp/type_definition.vader`). Cursor over a value → jumps to the declaration of its *type* (vs goto-def which jumps to the binding). Reuses the typed-project cache + hover's expr-finder : inferred `Type` → declaring `Symbol` (struct / enum / trait / type-param) → `Symbol.defined_at` → `Location`. A `T | null` nullable unwraps to `T`. No new infra (first Tier-2 item that needs none). Types with no single decl site (primitives, tuples/arrays, fn types, genuine multi-member unions) yield no result. Capability `typeDefinitionProvider` in `lifecycle.vader`, routed in `main.vader`. Colocated tests guard the type→symbol extraction. Limitation : a named union alias collapses to a structural `UnionType` (no symbol) in the type IR, so the alias itself isn't targetable — would need the typer to retain the alias symbol.
- [x] **LSP : project-wide reference index (infra A) + find-references** (`textDocument/references`, shipped 2026-06-17, `vader/lsp/references.vader`). Builds a `Symbol-id → use-spans` table by walking every module's AST (via `CheckResult.all_modules` per-module resolution) and binding each identifier span — `IdentExpr` uses AND local / for / match binding declaration name-spans (which the body-walker indexes into `idents`) — to its resolved Symbol ; import bindings are followed to their export target (`wire_imports` + `resolve_import_redirect`) so uses unify cross-file (Symbols are globally unique → `Symbol.id` is the key). Top-level decl/import sites from `Symbol.defined_at`. Deduped by span hash so rename never double-edits a range. Collecting local decl names (not just uses) is what lets rename/prepareRename work from a declaration and rewrite it — fixed 2026-06-17 after the first cut only indexed uses (prepareRename failed on `i :=` / `out ::`). Query : cursor → the use-site span containing it → its symbol id → all sites as `Location[]`, honouring `context.includeDeclaration`. Capability `referencesProvider`, routed in `main.vader`. No seed bump (LSP outside seed). Tests guard the walker coverage + half-open span containment. This index is the keystone for rename / call-hierarchy / the "N references" code-lens. **Follow-ups** : (1) cache the index on `ProjectCache` (today rebuilt per request — fine for references, rename/code-lens will want it cached) ; (2) index fn-param + type-param *declarations* (their AST span covers the whole `name: Type` slot — need a name-only span ; uses are already indexed) ; (3) index `.field` / method accesses ; (4) factor the identifier walk into a shared `for_each_ident` visitor (duplicated with `ast_tokens.vader` + `inlay_hint.vader`).
- [x] **LSP : autocompletion** (`textDocument/completion`, added 2026-06-07). Advertise the `completionProvider` capability and route the request. Contexts to cover :
  - **Imports** — inside `import "…"` complete the module path (walk stdlib + `vader.json::modules` + the project tree) ; inside `import "path" { … }` complete the exported names of that resolved module.
  - **UFCS methods on a value** — after `expr.`, suggest every fn whose first parameter type matches `expr`'s inferred type (UFCS-callable), alongside the type's own struct fields. Needs the typechecker's inferred-type table (§2.6) + an index of `fn(receiver_ty, …)` candidates keyed by receiver type.
  - **Scope identifiers** — locals, params, top-level decls, and imported names visible at the cursor.
  - **Enum / variant dot-completion** — after a leading `.` in a position with a known enum / union target, list its variants.
  Lives in a new `vader/lsp/completion.vader` ; reuses the per-document index + the typed-project cache already built for hover / inlay. Cross-ref the `LSP server` umbrella item above.
- [x] **LSP : rename refactoring** (`textDocument/rename` + `textDocument/prepareRename`, shipped 2026-06-17, `vader/lsp/rename.vader`). Renames a symbol — fn, local, param, type, import — and rewrites every reference across the project as one `WorkspaceEdit { changes: { uri: TextEdit[] } }`. Reuses the project-wide reference index (`references.vader::build_reference_index`), which keys on the resolved Symbol id (import bindings followed to their export target), so a rename touches only the same binding — never a shadowed / unrelated identifier of the same spelling, and importers are rewritten too. `prepareRename` validates the cursor sits on a resolved reference and returns its range. **Safety** : a `TextEdit` overwrites a range regardless of its current text, so we rewrite ONLY sites whose current source text equals the old name (the identifier under the cursor) — this skips the cases the index can't disambiguate (the `foo` in an aliased import `{ foo as f }`, whose binding span may point at `f`) rather than mangling them, at the cost of leaving them untouched. Capability `renameProvider { prepareProvider }`, routed in `main.vader`. No seed bump. Tests cover `span_text` slicing + `sites_to_rename` symbol/text filtering + `newName` parsing. **Follow-ups** : (1) rewrite the `foo` in aliased imports (needs the import binding's original-name span, not the local-name span) ; (2) field/method rename once `.field` accesses are indexed ; (3) validate `newName` is a legal identifier server-side. Cross-ref the `LSP code actions framework` item below.
- [ ] **LSP : index fn-param + type-param *declarations* for rename / references** (noted 2026-06-17). The reference index (`vader/lsp/references.vader::build_reference_index`) collects fn-param and type-param **uses** but not their **declarations** : `FnParam.span` / `TypeParam.span` cover the whole `name: Type` slot, too wide to use as a precise rename target or reference range (collecting them would make prepareRename select `a: i32` and rename's text-guard skip them anyway). Consequence : renaming from a parameter (or type param) rewrites its uses but leaves the `name` in the declaration untouched ; references on a param decl name finds nothing. Locals / for-/match-bindings already work (their `SimpleBinding.name_span` is name-only). Fix : derive a name-only span for the param/type-param (the name sits at `span.start`, length `len(name)`) — but the body-walker keys `idents` by the wide `p.span` (`vader/resolver/body.vader:152` param, `:136` type-param), so either re-key that `idents` entry by the name-only span, or record the name-only span and reconcile at lookup. Until then, param/type-param rename is uses-only. Cross-ref the reference-index + rename items above.
- [~] **LSP : reconcile semantic tokens with the TextMate grammar** (added 2026-06-07). Opening a `.vader` file shows a visible color flash : the editor first paints from the static TextMate grammar (`editors/common/vader.tmLanguage.json`), then the LSP's semantic tokens (`vader/lsp/semantic_tokens.vader` / `ast_tokens.vader`) arrive a beat later and recolor. Root cause : the grammar classifies by **syntactic shape** (everything gets a colour on open), while the LSP classifies by the **resolved Symbol kind** (`ast_tokens.vader::token_type_of_symbol`) and falls back to `Variable` whenever a name doesn't resolve — so anything the resolver misses degrades to the variable colour (and LSP4IJ underlines it). Concrete divergences observed on `vader/lower/lower_intrinsic.vader` :
  - **Function / method calls** — grammar tags `ident(` and `.ident(` as `entity.name.function.call` (`vader.tmLanguage.json:369-379`, the blue). The LSP only emits `Function` when the callee resolves to a `Fn` / `BuiltinFn` Symbol ; an unresolved callee — a **sibling-file fn of the same module** (`lower_expr`, `resolve_field_type`, `try_fold_static_intrinsic`) or a **method / UFCS call** — hits the `Variable` fallback (`ast_tokens.vader:130`), so the call loses its function colour after parse.
  - **UpperCamelCase identifiers** — grammar colours **every** `[A-Z]…` word as `entity.name.type` unconditionally (`vader.tmLanguage.json` "Type names" rule). The LSP emits `Type` only when the name resolves to a type-kind Symbol ; an unresolved type name flips to `Variable`.
  - **Locals / params / fields** — grammar leaves them default ; the LSP emits `variable` / `parameter` tokens (+ LSP4IJ underline decoration), so they gain colour + underline after parse.
  Fix direction : make the semantic-token walker mirror the grammar's syntactic fallback instead of `Variable` — emit `Function` for a callee in `ident(` position and `Type` for an UpperCamelCase name even when the Symbol doesn't resolve (sibling-file / cross-module), so the post-parse colour matches the on-open colour. Equivalently, never downgrade to `Variable` a token the grammar already colours as function/type. Touches `ast_tokens.vader` (the `token_type_of_symbol` fallback + the call / UFCS classification), `semantic_tokens.vader`, the legend advertised at `initialize`, and possibly `vader.tmLanguage.json` if any category is better dropped on the grammar side.
- [ ] VS Code extension.
- [ ] **`vader doctor --json`** — environment + toolchain sanity check emitting a structured report : `bun` / `cc` / stdlib paths discoverable, `runtime/c/` present, `vader.json` schema valid, GC env-vars in range, comptime cache writable. Two output modes : human-readable text (default) and `--json` for agent / CI consumption. Lives in `vader/cli/doctor.vader`. Cheap to ship and pays for itself the first time a fresh clone fails opaquely.
- [ ] **Structured `repair.id` field on diagnostics** — every entry in `vader/diagnostics/codes.vader` gains an optional `repair: { id: string, ... }` describing a deterministic fix that an LSP code-action or an LLM can apply. Examples : `R2003 unknown identifier → repair.id = "declare-missing-symbol"`, `T3007 missing field → repair.id = "add-field-default"`, `T3019 wrong arity → repair.id = "insert-trailing-arg"`. Surface in both `--diagnostics=json` output and `textDocument/codeAction` LSP responses. Start with the 5-10 highest-frequency codes ; the repair *implementation* can land later — the *contract* is the value. Cross-ref §1.0.
- [x] **LSP code actions framework** — general refactoring infrastructure on top of the LSP. Components : `codeActionProvider` capability in `vader/lsp/lifecycle.vader` ; new `vader/lsp/expr_at.vader` position → `Expr` walker ; `vader/lsp/code_actions.vader` registry of `{ kind, title, is_applicable, apply }` records ; expose `emit_expr(e: Expr) -> string` out of `vader/fmt/printer.vader`. First actions : `match → if` (≤ 2 arms reducible to booleans), `if-chain → match` (≥ 3 branches on same scrutinee), null-narrow rewrite, and **UFCS conversion** (`f(x)` ↔ `x.f()`, both directions, offered when the receiver type resolves the method). Reuses the same scaffolding for future refactorings (extract-fn, inline-let, rename). Design + open architectural questions captured in [`docs/LSP_COMPLETENESS.md`](./docs/LSP_COMPLETENESS.md) (§ Code actions framework). Deferred until self-host MVP closes ; cross-ref the `repair.id` entry above for the diagnostic-driven companion.
- [ ] Programmable build API (`build.vader` instead of `vader.json`).
- [ ] **Multi-library namespaces** — `STDLIB_PATH_PREFIX = "std/"` is hard-coded today. Generalise to a registry of `prefix → on-disk root` fed by `vader.json` (e.g. `{ "libraries": { "web": "./vendor/vader-web", "experimental": "./libs/exp" } }`). Use cases : (a) third-party libs via a package manager, (b) compiler-private namespace (`internal/`) with a "stdlib + compiler only" rule, (c) workspace monorepos. Touches `resolveImportPath`, `isStdlibModule`, DCE filter, dump-stage filters. ~150 lines + manifest schema bump.
- [ ] External package manager + central registry (much later).
- [ ] `man` page for `vader`.
- [ ] **GitHub Release on tag push** — attach `dist/vader-*.tar.gz` and `dist/vader-*.zip` to a release on `v*` tag push (`softprops/action-gh-release` or `gh release create`). `permissions: contents: write`. Auto-generate notes from commit log between tags.
- [ ] **GitHub Actions matrix per OS** (post self-host) — fan out to `ubuntu`/`macos`/`windows` runners that each run `bun test` on their native binary and assemble locally.

### 3.8 Language ergonomics
> Shipped: UFCS on union receivers, cross-module type-alias unions, codepoint-first `string` model + non-owning array slice views, literal-value match patterns, `enum`→int cast, implicit `void` return, auto-`.iter()` for-in, trait-object boxing + dynamic dispatch, operator overloading via traits, `Into[Target]` auto-coerce, expression-bodied fns, struct spread / field defaults, tuples + destructuring, comptime tuple/struct/array values, spread destructuring, `std/process.spawn`, inline `@file`, implicit selector expressions, `@assert` / `@partial` / `@deprecated`.
- [~] **`defer` unwinds on panic** (gap surfaced 2026-05-19) — **infra landed, unwind not wired.** Defers now lower to per-frame `DeferPush` / `DeferPopExec` ops (`bytecode/op.vader`, `vm/exec.vader`), not inlined statements ; but a runtime panic (uncaught error, OOB, null deref) still raises a VM trap directly and **skips every pending defer in the current frame and frames above** (the panic-unwind walker is unimplemented ; C target `runtime/c/vader.h` notes setjmp/longjmp work pending). Files left open, locks held, transactions dangling. Fix : (a) emit defers into a per-frame defer-list opcode (`DEFER_PUSH` / `DEFER_POP`) instead of inlining them, OR keep the inline form but maintain a parallel runtime stack tracked at frame entry ; (b) on panic, walk frames bottom-up and run each frame's pending defers before propagating ; (c) mirror in the C-emit (longjmp-based unwind or sentinel-checked epilogue). Same fix unlocks a future `recover` / `rescue` primitive. Cross-ref §3.1 Concurrency (panic propagation across spawned tasks).
- [ ] Static-size arrays `[T; N]`.
- [~] Pattern matching extensions — **or-patterns DONE** (`OrPattern` ; `'a' | 'b'` / `.A | .B`, `4d097749`), **range-patterns open** (`'a'..='z'` as a match arm — no `RangePattern` node yet).
- [ ] `@derive(Eq, Display)` to auto-generate trivial impls.
- [ ] **Function overloading by full signature** (post-MVP elevation of receiver-only overloading) — pick the candidate whose *all* parameter types match. Generalises the resolver's overload table + typechecker's call resolution.
- [~] **Generator functions (`@generator` + `yield`) — lazy element-by-element iteration.** **Phases 0-4 LANDED 2026-07-01** (`.claude/plans/generator-functions-yield.md`) — the feature is functionally complete for v1 (non-generic / concrete-element generators). Surface (`yield` keyword + `YieldStmt` + `@generator`), typecheck (T3056–T3061), and the state-machine lowering (`vader/lower/lower_generator.vader`: spill params+locals into a synthesized `g$State`, route refs to `self.<field>`, block-split the body into a `loop { if state==k … }` `Iterator::next`) all run correctly on **both backends** for straight-line yields, single + nested loops, break/continue across a yield, yield-in-if/match, and struct element types. Feature snippets `generator_{basic,nested,filter,break,struct_elem}` + LSP `YieldStmt` arms. `verify.sh` green throughout, suite 2493/0. **Remaining (`[~]` → Phase 5, DEFERRED):** dogfood on hot self-compile paths, generic generators (blocked on the pre-existing erased-generic vtable gap), and fusion/caller-monomorphization — all gated on `stream-fusion-generalization.md` Couche 4 (the erased `next()` is a per-element virtual call). Below is the original design note.
  ```
  @generator
  concat_file_decls :: fn(files: SourceFile[]) -> Iterator<Decl> {
      for f in files {
          for d in f.program.decls { yield d }
      }
  }
  ```
  **Resolved:** the Phase-0 cascade spike chose approach **B** (an AST/lower desugar to a `loop { match state }` state machine, synthesized as a `LoweredLoop` + `i32` if-chain since there's no `LoweredMatch` node) and validated its output shape on both backends before implementation. Perf (per-element virtual dispatch on the erased `Iterator<T>`; fusion + caller-monomorphization) and migration (callers needing `.len()`/indexing break; audit before converting) remain the deferred Phase-5 work.
- [~] **Stream-fusion generalization — lazy iterator chains → the eager loop** (perf; plan `.claude/plans/stream-fusion-generalization.md`). Both the eager combinators (`arr.map(f).filter(p)` = a throwaway array per stage) and the lazy ones (`MappedIterator`/… = a tower of erased trait-object iterators, virtual `next()` + boxed `Yield<T>` per element under erasure) collapse to one flat loop via fusion. `try_lower_chain_fusion` (`vader/lower/lower_for_in.vader:889`) already does this but ONLY for int-range sources, `map`/`filter`, and `for-in` terminals. Widen it: Couche 1 array/string/map-set sources (+ a concrete `arr.iter()` — none exists today, only erasing `.into()`), Couche 2 `take`/`skip`/`enumerate`/`flat_map`, Couche 3 recognize `.collect()`/`.count()`/`.any()`/`.fold()`/… terminals at the call site (synthesize their accumulation as the fused body), Couche 4 inline `@generator` yield-loops. Independent of generators for Couches 1-3 (bulk of the win); Couche 4 + the combinator-struct→`@generator` rewrite (Tier 1: Mapped/Filter/Take/Skip; Tier 2: Map/Set near-vestigial; Tier 3 keep ArrayIterator/StringChars as primitives) come after generators. Enablers: `arr.iter()`, harden generic-HOF lambda inference (works-but-untested + silent mistype today), explicit concrete chain heads for Map/Set/String (UFCS Into gate is array-only). Measure alloc volume, not RSS (short-lived allocs = profiler blind spot).

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
- `vader/` — the self-hosted Vader compiler (lexer, parser, typecheck, lower, midir, bytecode, c_emit, vm, lsp, fmt, cli)
- `tests/` — snapshot tests
- `docs/IMPROVEMENT.md` — review-driven improvement plan (2026-05-11)
