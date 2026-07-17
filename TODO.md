# Vader — TODO

Implementation roadmap for the Vader compiler and standard library, derived from `SPEC.md`:

- **Phase 1** — MVP compiler in TypeScript, plus stdlib in Vader.
- **Phase 2** — Self-hosting (port the compiler to Vader).
- **Phase 3** — Post-MVP language features and tooling.

Completed items (`[x]`) are kept as one-liners — see git history for implementation notes, commit hashes, migration steps. Open (`[ ]`) and in-progress (`[~]`) items keep the full context needed to act on them.

**Completed work — Phase 0, the done Phase 1 subsections, and the long-form detail of finished "Priority" items — lives in [`docs/HISTORY.md`](./docs/HISTORY.md).** This file tracks open + in-progress work only.

---

## Priority — next up

- [ ] **🐛 Narrow-int arithmetic not width-truncated by the VM (VM ≠ native)** (found 2026-07-16 by differential fuzzing). `u8`/`u16`/`i8`/`i16` arithmetic + narrowing casts keep the wide value in the VM (`u8 200+100` → 300) while native wraps correctly (→ 44) — because the bytecode has no narrow-int arith (`op_select.vader::arith_op` width-aliases everything sub-i64 to the I32 family) and native truncates only as a side-effect of C `uint8_t` storage, which the VM has no equivalent of. Native is the SPEC-correct oracle ("wraps silently"). **Scoping done, NOT coded** (user chose scope-first): [`.claude/plans/narrow-int-width-truncation.md`](.claude/plans/narrow-int-width-truncation.md) — recommended Option 1 (explicit trunc op in the IR, backend-uniform). Repro + KNOWN-RED tracker: `tests/snippets/narrow_int_wrap/` is in the `parity-cemit` allowlist and `c-emit-run: narrow_int_wrap` fails on purpose until the VM wraps to width. Subtlety: the wrap bites only at a narrow-typed STORE; an unstored `${a+b}` stays wide in BOTH backends (both 300) — Option 1 would make every case 44.

- [ ] **`is` on a width-mixed integer union narrows wrong (both backends, divergent) — PARKED** (found 2026-07-16). For `x: i32 | i64 | u8`, the VM matches the first `is <intType>` for any integer (`1 1 1`) and native never matches `is u8` (`3 2 3`); neither is `1 2 3`. Integer analog of the f32-union `is` fix (`e29891685`). Design question: reject width-mixed integer unions at the typer, alias all widths for `is` (as f32≡f64), or carry precise primitive box tags. Repro: `tests/snippets/int_width_union_is/` (documented, not in the parity allowlist — kept green while parked). Deprioritized behind the narrow-int truncation bug above.


- [ ] **Allocation-use analysis → stack-alloc / interning / value-structs** (escape analysis, broadened 2026-06-20). One whole-program dataflow over midir (`vader/midir/`) computes, per allocation site / per type, *how the value is used*: does it **escape** its creating fn (return / store-to-heap / capture), is it **mutated** after construction (a `struct.set` scan — the lowered IR makes this a direct walk), is it **compared by reference identity**. Those facts feed THREE complementary GC-pressure optimisations, each attacking a different slice of the self-compile memory profile (the two halves measured by `bun run bench:profile`: ~986 MB GC-copied / 32 cycles of **churn** + ~512 MB **retained** live-set, ARRAY_BUF/`MutableMap`-dominated):
  - **Stack-allocation** — allocations that provably don't escape go on the stack (or are freed eagerly) instead of the Cheney arena. Attacks the **churn** half (short-lived CFG-node / temp traffic). Caveat: a stack slot must not be a GC root the moving collector tries to relocate.
  - **Interning (hash-consing)** — immutable, duplicated, long-lived values are deduplicated to one shared instance. Attacks the **retained** half (Type IR, `Symbol`, `BcType`, `MutableMap` entries held across passes) — note this is the INVERSE class to stack-alloc: the escaping, long-lived values stack-alloc can't touch are exactly interning's target. **Vader soundness condition**: `==` on a struct without an `Equals` impl is *reference identity* (SPEC §"Memory Model"), so interning is sound only for a type that is immutable AND never identity-compared (has `Equals`, or is never `==`-ed — e.g. `PrimitiveType`, compared via `equals_type`/`canonical_key`, qualifies). Proving "never identity-compared" automatically must bail in erased generic/union contexts, so the realistic form is an opt-in **`@intern` decorator the compiler *verifies*** (immutability + Equals/no-identity-compare → error if violated) then generates the content-keyed construction — the Rust `Ty` / LLVM type-uniquing / GHC model (always annotated, never auto-derived, for exactly this reason). Profitability caveat: intern only bounded-value-set types (few distinct values), else the intern table itself retains everything → a leak.
  - **Value-type structs** — small immutable never-trait-boxed structs passed by register instead of heap-boxed. Shares the same immutability fact; see the §3.5 "Value-type structs" item for its open trade-offs (`@value` vs auto-detect, `is Trait` interaction, multi-register ABI).
  The first concrete interning win — `mk_primitive` singletons (`vader/types/types.vader`, 17 primitive names incl. `null`) — is a safe MANUAL instance (never `==`-compared, 17 bounded values); doing it generically is this chantier. **When generic `@intern` lands, REVERT that manual interning**: replace the hand-rolled `mk_primitive` singleton table with `@intern` on `PrimitiveType`, so there's one mechanism — the manual table would otherwise duplicate (and could conflict with) the generic pass's content-keyed construction. Architecture-level → explore-before-commit + review. Related §3.5 items: escape (stack-alloc), value-structs, self-host typecheck working-set.


- [~] **`vader fmt` MVP** (first pass 2026-05-11) — written in Vader under `vader/fmt/`, exercises the self-host parser end-to-end. Idempotency + parse round-trip green on the stdlib ; byte-for-byte no-op pending on three stylistic gaps : (a) `::` column alignment in decl groups, (b) per-line grouping inside multi-line imports, (c) cap at 1 blank line between decls vs the stdlib's occasional double-blank. Tests : `tests/formatter*.test.ts` (gated `RUN_FMT_TESTS=1`). Open : column alignment decision, hand-curated snapshot scenarios, growing `NO_OP_FILES`.

- [~] **Reject private types in a public signature — return types DONE (T3052), extensions open** (`e12cde15`). `first_unexported_type` (`vader/typecheck/decl.vader:227`) fires **T3052** when an `export`ed fn's **return type** names a non-`export`ed type (code at `vader/diagnostics/codes.vader:79`/`:363`). Remaining (the item's planned extensions): **parameter types, exported struct fields, type-alias RHS** — `first_unexported_type` is only called on `return_type` today (`decl.vader:213`). Mirrors Rust's `private_interfaces` (E0446).


- [ ] **LSP semantic tokens override TextMate for strings — escapes lose their colour** (added 2026-06-17). When the LSP loads, escape sequences inside string literals (`\t`, `\n` in `"\t\nhi"`) switch from TextMate's distinct escape colour to a uniform `string` colour. Cause : `classify_token` (`vader/lsp/semantic_tokens.vader`) emits one `string` semantic token over the **whole** literal content (`StringBegin` / `StringPart` / `StringEnd`), which overrides the editor's TextMate grammar — confirmed via a token dump (`"\t\nhi"` → a single `string` token spanning `\t\nhi`). This is the same call already made for **identifiers** (the existing `classify_token` comment : *"The shared TextMate grammar already paints idents correctly ; letting it own that surface keeps the editor clean."*) ; TextMate paints strings **and** their escapes well, so the semantic override only degrades. The related multi-byte **length** bug (`"héllo"` token running one column long) is already fixed — token lengths are codepoint-based (`span_token_length`). **Options :** (B, recommended) stop emitting `string` tokens for `string` / `char` literals — return `-1` for `StringBegin` / `StringPart` / `StringEnd` / `CharLit` in `classify_token`, letting TextMate own them like identifiers ; (A, broader) also drop `number` / `operator` / `keyword` / base-comment tokens so the semantic layer is purely **additive** — resolution-based identifier roles + vaderdoc tags + `@`-intrinsics only — eliminating all load-time highlighting diffs ; (C) emit separate escape-sequence tokens within strings (keeps `string` tokens, more work). Lives in `vader/lsp/semantic_tokens.vader::classify_token`.


- [ ] **Warn on unused imports** (added 2026-06-07). An imported name that's never referenced in the file earns a compilation warning (new W-code). Covers both import forms : `import "path" { Name1, Name2 }` — each destructured name must be used at least once — and the namespace form `xx :: import "path"` — the binding `xx` must be referenced at least once (e.g. `xx.Member`), else the whole import is dead. Emit one warning per unused name, pointing at its import-list span. Update `SPEC.md` (imports section) in the same commit.
  - **Attempted 2026-06-17, reverted — blocked on reference-tracking.** First cut scanned `resolved.idents` (span→Symbol) for `ImportBinding`-kind values to build the "used" set, emitting W0006 for every unreferenced import binding in `resolved.symbols`. Minimal snippets passed (an unused `eprintln` flagged, a used `println` not — across value position, let-binding RHS, and type position). But on the real tree it **systematically false-positives** : `vader/lexer/keywords.vader` (40 LoC, **zero own imports**) reported 16 W0006 — they were `vader/lexer`'s **sibling-file** imports, whose uses the resolver never recorded because **its body walker is structurally `files[0]`-only** (TODO §1.13d, `resolver/resolve.vader:153`). Worse, single-file `vader/cli/main.vader` reported 24 W0006 for top-of-file imports that are obviously used (`keys`, `values`, `resolve_module`, …) — so `resolved.idents` is **not a reliable record of every use** even within one file (some expr/type positions never land there ; root not fully pinned). **Conclusion :** a sound W0006 needs comprehensive, **symbol-id-keyed** (not span-hashed) reference tracking that covers *every* file of a (folder) module and *every* reference position. That is the same gap as **"Harden multi-file module support" (§1.13d, the `files[0]`-only body walker)**. Do this **after** §1.13d lands, or as a dedicated full-AST name-collection walk (params/return/fields/alias-RHS/const-types/all bodies, across all files) — not by scanning `resolved.idents`. Reverted cleanly (no W0006 in the tree).


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

### 1.11 C runtime — partial
- [ ] String runtime polish, array runtime polish, StringBuilder support consolidation, panic handler.
- [ ] libc-backed I/O glue for `std/io`.

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

  - **Promoted to a dedicated plan (2026-06-16): [`.claude/plans/core-string-utf8-reorg.md`](.claude/plans/core-string-utf8-reorg.md).** It folds in the `string.len()` miscompile (UFCS to a non-imported, non-`core` free fn → invalid C), the **frozen import policy** (using a non-imported fn — except `std/core` the prelude — is a compilation error), the prelude/layering rule, and the emitter ICE backstop. The `bytes_to_string` reconciliation item below is folded into that plan's Phase 3.
- [ ] **Future audits** — revisit when new stdlib modules land. A shared `Cursor(T)` trait could unify `std/json` and `vader/lexer`'s hand-rolled cursors when a real need arises.

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

### 2.0 Vader CLI minimal — partial
> Shipped: argv parsing + stage dispatch, snapshot parity rig (`tests/parity/`), native CLI build via `tests/cli-bin.ts`.
- [ ] Future stages plug in as parser / typechecker / lowerer get ported.

### 2.1 Port the parser to Vader — partial
> Shipped: lexer (`vader/lexer/`), diagnostics (`codes`/`diagnostic`), parser (`vader/parser/`, ~2200 LoC recursive-descent + Pratt), AST→JSON dumper, `vader dump --stage=ast`, byte-for-byte lexer + parser parity (~240/245), porting bugs all closed.
- [~] **Diagnostics folder-module migration** — today `vader/diagnostics/{codes,diagnostic}.vader` resolve as separate single-file modules, so `private` doesn't survive cross-file. Migrate to folder-module to hide internals.

### 2.2 Port the C emitter — NATIVE FIXED POINT REACHED (2026-06-05)
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


#### Closed by 5g + downstream chantiers


#### Still open

- [ ] **Inline-consts pass** — post-lowering const substitution +
      data-pool routing. No upstream blocker, but lands alongside the
      bytecode-emit chantier where the data pool actually matters.

#### Divergences from the reference impl (Vader is correct)

(none recorded yet)

### 2.6 Port the type-checker (last)
- [ ] Snapshot-test parity on every sample.

#### Bugs surfaced while porting the typechecker — open
- [~] **`settle_external_expr_bodied_returns` walks every non-entry module's body** (added 2026-05-17, `vader/typecheck/orchestrate.vader`). Runs the full `walk_bodies` pass (FnDecl + ImplDecl + ConstDecl + AssertDecl) instead of just the expression-bodied fns whose returns need patching. Triggers on any module that has *one* expr-bodied fn ; for std/iter etc this can multiply typecheck time. Scope it down to expr-bodied FnDecls + impl methods only.

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
      the emitter's own tables at the peak. Candidate levers (none committed) :
      (a) release `typed` / `evaluated` before the CFG→emit tail (extract a
      helper returning `(lowered, entry_name)` so `pipeline` leaves scope) ;
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
- [i] **LSP : spurious L0005 "character literal must contain exactly one codepoint" on `'é'`** (investigated 2026-06-17, *not a current-compiler bug*). Reported on `stdlib/std/string/string.vader:907` (`assert_eq(byte_decode_at("héllo", usize(1)), 'é')`). The on-disk literal is precomposed é — bytes `27 c3 a9 27` = `'` + U+00E9 + `'`, a single codepoint — and the current compiler accepts it : `dump --stage=ast` reports **zero** `error[L0005]` on the file, the isolated literal lexes clean, and the full suite (which runs `test_byte_decode_at`) is green. `lex_char` advances by `codepoint_byte_len` (since 2026-05-15, `dc457047`), so multi-byte single-codepoint literals have always been valid. The live editor error is therefore either (a) a **stale LSP server** running an older in-memory binary — reload the window so it picks up the freshly-built dist binary, or (b) the unsaved buffer holds a **decomposed** é (NFD : `65 cc 81` = `e` + combining U+0301 = *two* codepoints), which the lexer correctly rejects even though it renders as one grapheme. **Optional UX follow-up** : when a char literal is a base char + ≥1 combining mark, emit a clearer L0005 hint ("looks like one character but is N codepoints (NFD); use the precomposed form or a string") instead of the bare codepoint-count message.
- [~] **LSP : inconsistent semantic highlighting** (noted 2026-06-15) — the syntax/semantic colouring isn't always consistent ; observed on `self` in `stdlib/std/core/primitives.vader`'s `Hash` impl block (`i8 implements Hash -> u64(self)` etc.) — `self` is highlighted/underlined inconsistently across otherwise-identical lines, and `isize` picks up a spurious squiggle. Revisit when reworking the LSP (likely the semantic-tokens classifier mis-scoping `self` / a stale diagnostic on `isize`).
- [ ] **LSP : index fn-param + type-param *declarations* for rename / references** (noted 2026-06-17). The reference index (`vader/lsp/references.vader::build_reference_index`) collects fn-param and type-param **uses** but not their **declarations** : `FnParam.span` / `TypeParam.span` cover the whole `name: Type` slot, too wide to use as a precise rename target or reference range (collecting them would make prepareRename select `a: i32` and rename's text-guard skip them anyway). Consequence : renaming from a parameter (or type param) rewrites its uses but leaves the `name` in the declaration untouched ; references on a param decl name finds nothing. Locals / for-/match-bindings already work (their `SimpleBinding.name_span` is name-only). Fix : derive a name-only span for the param/type-param (the name sits at `span.start`, length `len(name)`) — but the body-walker keys `idents` by the wide `p.span` (`vader/resolver/body.vader:152` param, `:136` type-param), so either re-key that `idents` entry by the name-only span, or record the name-only span and reconcile at lookup. Until then, param/type-param rename is uses-only. Cross-ref the reference-index + rename items above.
- [~] **LSP : reconcile semantic tokens with the TextMate grammar** (added 2026-06-07). Opening a `.vader` file shows a visible color flash : the editor first paints from the static TextMate grammar (`editors/common/vader.tmLanguage.json`), then the LSP's semantic tokens (`vader/lsp/semantic_tokens.vader` / `ast_tokens.vader`) arrive a beat later and recolor. Root cause : the grammar classifies by **syntactic shape** (everything gets a colour on open), while the LSP classifies by the **resolved Symbol kind** (`ast_tokens.vader::token_type_of_symbol`) and falls back to `Variable` whenever a name doesn't resolve — so anything the resolver misses degrades to the variable colour (and LSP4IJ underlines it). Concrete divergences observed on `vader/lower/lower_intrinsic.vader` :
  - **Function / method calls** — grammar tags `ident(` and `.ident(` as `entity.name.function.call` (`vader.tmLanguage.json:369-379`, the blue). The LSP only emits `Function` when the callee resolves to a `Fn` / `BuiltinFn` Symbol ; an unresolved callee — a **sibling-file fn of the same module** (`lower_expr`, `resolve_field_type`, `try_fold_static_intrinsic`) or a **method / UFCS call** — hits the `Variable` fallback (`ast_tokens.vader:130`), so the call loses its function colour after parse.
  - **UpperCamelCase identifiers** — grammar colours **every** `[A-Z]…` word as `entity.name.type` unconditionally (`vader.tmLanguage.json` "Type names" rule). The LSP emits `Type` only when the name resolves to a type-kind Symbol ; an unresolved type name flips to `Variable`.
  - **Locals / params / fields** — grammar leaves them default ; the LSP emits `variable` / `parameter` tokens (+ LSP4IJ underline decoration), so they gain colour + underline after parse.
  Fix direction : make the semantic-token walker mirror the grammar's syntactic fallback instead of `Variable` — emit `Function` for a callee in `ident(` position and `Type` for an UpperCamelCase name even when the Symbol doesn't resolve (sibling-file / cross-module), so the post-parse colour matches the on-open colour. Equivalently, never downgrade to `Variable` a token the grammar already colours as function/type. Touches `ast_tokens.vader` (the `token_type_of_symbol` fallback + the call / UFCS classification), `semantic_tokens.vader`, the legend advertised at `initialize`, and possibly `vader.tmLanguage.json` if any category is better dropped on the grammar side.
- [ ] VS Code extension.
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
