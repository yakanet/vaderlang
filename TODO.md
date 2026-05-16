# Vader — TODO

Implementation roadmap for the Vader compiler and standard library, derived from `SPEC.md`:

- **Phase 1** — MVP compiler in TypeScript, plus stdlib in Vader.
- **Phase 2** — Self-hosting (port the compiler to Vader).
- **Phase 3** — Post-MVP language features and tooling.

Completed items (`[x]`) are kept as one-liners — see git history for implementation notes, commit hashes, migration steps. Open (`[ ]`) and in-progress (`[~]`) items keep the full context needed to act on them.

---

## Priority — next up

- [x] **Single-binary distribution** (2026-05-10) — `bun build --compile` + per-OS tarballs (`vader-<os>-<arch>.tar.gz`) bundling the binary with `stdlib/` and `runtime/c/` sidecars. `scripts/dist.ts` + `dist:*` npm scripts.
- [~] **`vader fmt` MVP** (first pass 2026-05-11) — written in Vader under `vader/fmt/`, exercises the self-host parser end-to-end. Idempotency + parse round-trip green on the stdlib ; byte-for-byte no-op pending on three stylistic gaps : (a) `::` column alignment in decl groups, (b) per-line grouping inside multi-line imports, (c) cap at 1 blank line between decls vs the stdlib's occasional double-blank. Tests : `tests/formatter*.test.ts` (gated `RUN_FMT_TESTS=1`). Open : column alignment decision, hand-curated snapshot scenarios, growing `NO_OP_FILES`.
- [x] **Reference benchmark** (2026-05-14) — `bench/` with mandelbrot + primes in Vader / TS / Go ; `bun run bench` compares against `bench/baseline.json` (10 % regression budget). See [`bench/README.md`](./bench/README.md).
- [x] **Adopt `s[i]` over `s.char_at(i)`** (2026-05-11) — `char_at` export dropped ; `.byte_at(i)` kept in hot byte-level scanners.
- [x] **SSA round-trip removed** (2026-05-14) — measurement showed zero precision gain over flat-CFG escape analysis ; 335 LoC of SSA + dominance-frontier code deleted.
- [x] **Loop-carried-dependency check** (2026-05-14) — replaced over-conservative `inLoop` escape filter ; +95 stack-promotions on the self-host.
- [x] **Monoliths broken up** — incremental ; largest `src/` file is now `lower/passes/expr.ts` at 983 lines, below the 1k-line threshold.
- [ ] **LSP semantic classification via the AST.** Today `vader/lsp/semantic_tokens.vader` classifies identifiers from the lexer stream alone with a `is-uppercase?` heuristic, so function names ship as `Variable`, primitives (`i32`, `usize`, ...) ship as `Variable`, fields and locals are indistinguishable. Replace with a pass that runs parser + resolver and walks the AST so each `IdentExpr` is tagged with its actual kind (`FnDecl` → `Function`, `TypeRef` → `Type`, `FieldAccess` → `Property`, ...). Same trick as `vader/fmt/` already does — call into `vader/parser/parser.vader` and `vader/resolver/`. Acceptance : `vader fmt` regressions stay green ; Inspect Editor Tokens on `double` / `i32` / `self` / struct fields shows the correct token type.

---

## Phase 0 — Project bootstrap

- [x] `bun init` scaffolding, `tsconfig.json` strict mode, `bun test` runner, snapshot driver, CLI entry point, `.gitignore`.

---

## Phase 1 — MVP compiler in TypeScript

### 1.0 Diagnostic infrastructure
- [x] Diagnostic data shape, collector, code registry, terminal renderer, JSON renderer, `--diagnostics=text|json` CLI flag.

### 1.1 Lexer
- [x] All token kinds, source-position tracking, shebang, whitespace, line + nested block comments, identifiers, keywords, numeric literals (bases 10/16/2/8 + suffixes + underscores), char + string literals (plain / raw / triple-quoted, interpolation with nested stack), operators table-driven, newline emission per SPEC §3, 10 diagnostic codes `L0001..L0010`, recovery, 60+ unit tests, snapshot scenarios.

### 1.2 Parser
- [x] Full AST node types, top-level decls, Pratt expressions, statements, patterns, type expressions (incl. tuples `[T1, T2]` ≥ 2 elements + postfix `T[]`), decorators, generics (`[T: Bound]`), structured error recovery, snapshot scenarios. `vader dump --stage=ast` exposes the pipeline.

### 1.3 Resolver
- [x] Module loader (single-file + folder modules, `vader.json` optional), graph + cycle detection, symbol tables with scoping, stdlib resolution, relative + bare imports, destructuring + `as` rename + namespace, cross-module `private` enforcement, decorator + trait-impl wiring, 8 snapshot scenarios. `vader dump --stage=resolved-ast` exposes the pipeline.

### 1.4 Type-checker
- [x] Type IR (Primitive / Struct / Trait / Union / Fn / Array / TypeParam / TypeMeta / FreeInt / FreeFloat / Never), bidirectional inference, generic typeParam handling (mono deferred to 1.5), `ImplRegistry`, union joins on match arms + if branches, scrutinee narrowing inside `match` arms, exhaustiveness, free-numeric defaulting, interpolation `Display` check, primitive operator resolution, `T(x)` cast validation, `?` operator return-union check, 26 codes `T3001..T3026`, 10 snapshot scenarios. `vader dump --stage=typed-ast` exposes the pipeline.

**Deferred (still relevant):**
- Generic monomorphization (now in §1.5).
- Trait dispatch for operator overloading on user types (now done — see §1.13e operator overloading).
- Per-binding type narrowing in `is T as x` patterns (now done — see §1.13e).
- Field-type substitution for generic struct instances.
- Validation of `[T: Trait]` bounds against a concrete substitution at call sites (now done — see §1.18b).
- Struct-level bounds enforcement (now done — see §1.18b).

### 1.5 Comptime engine + monomorphizer

**Decision:** AST-walking interpreter at first, then ported to the bytecode VM in 1.5b. No separate comptime VM — the engine and the runtime VM share `src/bytecode/ops.ts`.

#### 1.5a MVP — done
- [x] Comptime value IR, AST-walking interpreter, sandbox (`@file`, `@env` gated by `--allow-env`), `@comptime` evaluation pass, generic instance registry, minimal monomorphization pass, codes `C4001..C4013`. `vader dump --stage=evaluated-ast`. 5 snapshot scenarios.

#### 1.5b Bytecode VM as the comptime engine — done
- [x] Typed-AST → bytecode lowering for comptime-eligible subset.
- [x] Stack VM comptime engine via `src/comptime/run.ts`. AST-walker deleted.
- [x] Cycle detection across `@comptime` decls (C4009).
- [x] Recursive `@comptime` evaluation via topological sort.
- [x] Generic-fn instance registry via `observeFnCall` + AST walker.
- [x] Mono+lower+emit for fn instances — `monomorphizeProject` materialises one entry per `(generic FnDecl, concrete typeArgs)` ; UFCS calls route to the specialisation.
- [x] Inferred generic-fn type args via `genericFnCalls` map.
- [x] Generic impls (`ArrayIterator(T) implements Iterator(T)`) materialised via `implMethodEntries`.
- [x] `std/iter` combinators (eager `T[]` + lazy struct-wrapping). Lazy chain via direct struct literal — generic-fn inference on trait-typed params still traps (cf. §3.x trait-object boxing).
- [x] `for x in iter` on trait-typed receiver + UFCS dispatch to a trait-typed first param (2026-05-14). `lowerForIn` recognises trait-typed iters and emits `LoweredVirtualCall` for `next()` ; `rankOverloadsByFirstParam` gained a Trait-first-param branch.
- [x] **`std/iter` short-circuiting combinators** (2026-05-15) — `any` / `all` / `find` / `find_map` each take a single `Iterator(T)` (raw arrays auto-coerce). `find` returns `T | null` ; `find_map` returns `U | null`. Two compiler enablers shipped alongside : (a) `Union ↔ Union` unification in `unifyTypeParam` (binds `U` through `fn(T) -> U | null` against `fn(i32) -> i32 | null`) ; (b) UFCS receiver `Into`-coerce — `inferGenericUfcsCall` now records `tryInto(receiver, expected-first-param)` when the receiver flows via `Into` rather than direct assignability, so `arr.any(p)` boxes the array on the way into the call instead of trapping at runtime with "no impl in Iterator.next vtable".
- [x] Transitive monomorphization via fixed-point `closeOverGenericImpls`.
- [x] First-class trait-method dispatch — bounded typeParam, non-generic trait receiver, generic trait receiver.
- [ ] **Default-init for generic typeParam** — `acc: T = T()` style, needed by `sum(it)` over an iterator. Either a `Default` trait + auto-impl on numerics, or a `zero<T>()` intrinsic. Currently blocks iterator-driven `sum`, `min`, `max`. Requires either (a) explicit type-args at call sites (`default[T]()`) or (b) `T()` constructor syntax for type-params. Recommendation : start with (a). `Default` trait can wait until a dispatch path exists.
- [x] **Generic `len(arr)`** (2026-05-16) — `ArrayIterator(T).length` field dropped ; `next()` reads `self.arr.len()` via UFCS. `wrapArrayAsIter` simplified : the `length` slot was the only reason to dedupe the array expression, so the synthetic tmp + hoist are gone too.
- [x] Auto-coerce `T[]` → `Iterator(T)` via blanket `T[] implements[T] Into(Iterator(T))` in `std/core`.
- [ ] `for x in iter` / `MutableList(u32){}.add(...)` inside `@comptime` — needs arena allocation for transient collections.

### 1.6 Lowerer — done
- [x] Dedicated lowered AST. Pattern match → linear if/else chain over `LoweredTypeCheck`. `expr?` → block + try/return. String interpolation → builder intrinsic calls. `defer` → physical duplication at every textual exit. Trait calls → static dispatch via UFCS. No inserted runtime checks. `vader dump --stage=lowered-ast`. 7 snapshot scenarios.
- [x] Lambda lifting / closure conversion via `$Cell_T` heap promotion ; `LoweredMakeClosure` at call sites.
- [x] `RangeExpr` + `T[]` arrays lowered via `Iterator` dispatch ; `for-in` desugars to a pull-loop on `Iterator(T)::next`.
- [ ] Match decision-tree compilation (Maranget). Naive chain is enough for MVP.

### 1.7 Bytecode emitter — done
- [x] Op table (WASM-aligned typed primitives, constants, locals, structured control, calls, GC ops, `type_check`, `ref.cast`), type table (deduped), string pool, function + import + export tables, intrinsic table (stable IDs, append-only), per-op debug info, two-pass emission, short-circuit `and`/`or` lowering, `vader dump --stage=bytecode`, 7 snapshot scenarios.
- [x] Bytecode peephole pass — `local.set N; local.get N → local.tee N`, cmp+not fusion, double-not elimination. Gated `EmitOptions.optimize` (CLI `--no-bytecode-opt`).
- [x] **Slot reuse via live-range coalescing** (landed 2026-05-16, v2). `src/bytecode/slot-coalesce.ts` runs after the peephole pipeline : it computes each slot's `[first_op, last_op]` range from the linearised body, extends ranges through enclosing `loop ... end` ranges to respect back-edge reads, then greedy-colors same-ValType slots that don't overlap. Compacts `fn.locals` and rewrites every `local.get/set/tee` to the new dense slot index. 124 snippet bytecode snapshots regenerated — net **−1682 lines** (−3.6 %) across the corpus. **TS VM, Vader VM, and native** all green ; the previous attempt's Vader-VM mismatch is avoided by running AFTER peephole on the final linear bytecode (no metadata drift). Same-ValType filter prevents bridging a `ref`-typed iter into an `i32` slot ; the loop-range extension fixes the for-in `__iter` / `__step` coalescing bug the first attempt missed.
- [x] First-class function values — `fn.ref`, `call.indirect`, `make_closure` ops + `vader_fn_t` fat pointer runtime.

### 1.7b IR text emitter / reader (`--target=ir-text` → `.virt`) — done
- [x] Line-oriented `.virt` grammar, `writeVir`/`parseVir`, round-trip fixpoint verified by snapshot banner. `vader run program.virt` wired.
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

### 1.9 C emitter (Iter-ready) — done
- [x] Runtime C surface in `runtime/c/`, type representation γ (primitives stay primitive, struct/array via typed pointer, union/`any` via `vader_box_t`), full emitter (`src/c_emit/emit.ts`), import shims with `std/io` mapped to runtime fns, `vader build --target=native [--out=<out>]`, parity tests against the VM snapshot.
- [x] `--release` flag — flips `cc` from `-O0 -ggdb` to `-O3 -DNDEBUG` + best-effort `strip`.
- [x] Unbox struct field read after `is StructTy` match.
- [x] `--cc=<path>` flag + `CC` env var ; auto-`.exe` on mingw32 triples.
- [x] Windows cross-compile via mingw-w64 + Wine (POSIX spawn bracketed by `#ifdef _WIN32` ; Windows branch uses `CreateProcess` + pipes). Still deferred : `tests/native.test.ts` `WINE=1` mode, Unicode (`CreateProcessW`), clang/cl autodetection.
- [x] `#line` directives for gdb/lldb (2026-05-16) — debug builds thread `#line N "<file>"` before each op whose `DebugPos` shifts ; `--release` skips them. `cStringLit` handles path escaping ; the per-fn file string is cached across ops.
- [ ] Manifest mode (`vader build --target=native --manifest`).
- [ ] Stable ABI for `@extern` user imports (today : stubs trap).
- [ ] i32/i64 overflow handling per SPEC §4 (panic in debug). Wraps silently today.

### 1.10 WASM emitter — moved to Phase 3 (§3.10)

### 1.11 C runtime — partial
- [x] **GC** : Cheney semi-space copying GC (`runtime/c/vader_runtime.c`). Precise roots via shadow stack + emitted `vader_gc_frame_t`s ; per-type pointer maps from C-emit. Knobs : `VADER_GC_ARENA_BYTES`. Stress tests under `tests/snippets/gc_*`.
- [x] **Arrays GC-tracked** — `vader_array_t` carries a header with single ref to a separately-allocated `vader_array_buf_t` ; Cheney scan dispatches on sentinel `0xFFFFFFFE`.
- [x] **Strings off the GC arena** — string buffers `malloc`'d outside the arena. Strings leak for the program's lifetime ; fine for MVP.
- [ ] String runtime polish, array runtime polish, StringBuilder support consolidation, panic handler.
- [ ] libc-backed I/O glue for `std/io`.

### 1.12 CLI — partial
- [ ] `vader run`, `vader build` single-file + manifest-driven (`vader.json`).
- [ ] `vader build --target=wasm` — see §3.10.
- [ ] `vader build --target=ir` — emits `.vir`.
- [x] **`vader test [path]`** (2026-05-12) — recursive `.vader` discovery, runs `@test` fns via VM, per-file group output, exit 0/1/2 on pass/fail/no-tests.
- [~] **`vader fmt [path]`** — see top "Priority — next up".
- [ ] `vader dump --stage=<ast|typed-ast|bytecode|c>`.
- [ ] `--allow-env` flag for comptime sandbox.

### 1.13 Stdlib (in Vader) — partial
- [ ] `std/core` finalisation, `std/io`, `std/string`, `std/math`.
- [x] `std/collections` — `MutableMap(K, V)` + `MutableSet(T)` chaining HashMap with FNV-1a string hash. Shared `len` / `is_empty` / `put` / `get` / `contains_key` / `add` / `contains` via first-param overloading.
- [ ] **Immutable `Map`/`Set` ops + `to_immutable`** — re-add the struct decls when there's a real read-only-view design.
- [x] Iterator impls for `MutableMap` / `MutableSet`.
- [ ] **Restore `MutableList(T)` once immutable `List<T>` lands** — raw `T[]` already covers push/len/indexing.
- [x] `std/string_builder` — `StringBuilder`.
- [x] `std/iter` — eager `T[]` combinators (`map`, `filter`, `fold`, `sum`, `take`, `skip`, `collect`, `count`, `zip`, `chain`, `enumerate`, `flat_map`).
- [x] `std/iter` lazy combinators — `MapIterator`, `FilterIterator`, `TakeIterator`, `SkipIterator` (struct-literal construction).
- [x] `std/runtime` — `collect()`, `collections()`, `bytes_used()`, `bytes_copied()`.
- [x] `std/sort` — `sort(arr, less)` stable merge-sort with insertion-sort cutoff. Returns a new array.
- [~] **`std/cli`** (initial 2026-05-11) — minimal declarative `FlagSpec` + `parse(args, specs) -> ParsedArgs` + accessors. Supports `--name`, `--name=value`, `--`. Open : subcommands, `--help`/`--version`, short flags `-v`, `--name value` form, rewriting `vader/cli/main.vader` on top once subcommands land.

### 1.13b Self-hosting prerequisites — done
- [x] Process argv as `main(argv: [string])`.
- [x] Format helpers (`pad_start`, `pad_end`, `is_whitechar`, `to_hex`, `to_bin`).
- [x] `in` / `!in` operators + `Contains($T)` trait.
- [x] `char ↔ u32` and other integer casts (rejects char↔float).
- [x] `std/path` (POSIX `/` only ; Windows deferred).
- [x] `std/regex` ad-hoc helpers + char ordering ops.
- [x] `std/json` — recursive-descent parse + stringify. Returns `JsonValue | JsonError` (trait widening on return now fires, but the union form stays).

### 1.13c Bugs surfaced while building 1.13b — all closed
- [x] u64/i64 literal coercion, `[string]` iteration, char arithmetic, trait widening on return, narrowing-aware unbox inside match arms, multi-file modules dropping all but first, cross-module enum + empty indices, FieldExpr→Enum lowering misdispatch, expression-bodied fns, `null` ValType→C `void`, `parse_int`/`parse_float` C shim mistagging, Range i32-only enforcement (T3001), struct-pattern in union narrowing.

### 1.13d Stdlib consolidation — partial
- [x] hex/base helpers centralised in `std/numbers`.
- [x] char-predicate duplicates in `std/json` removed.
- [ ] **Future audits** — revisit when new stdlib modules land. A shared `Cursor(T)` trait could unify `std/json` and `vader/lexer`'s hand-rolled cursors when a real need arises.

### 1.13e Language ergonomics surfaced by self-host port — mostly done

Patterns counted on the existing Vader code that paid an outsized boilerplate cost. Each item is additive, back-compat by construction.

- [x] Numeric literal context-sensitivity for `usize` (and other primitives) — repins `FreeInt` arg literals in generic UFCS calls + flows expected type into unary `neg`/`bitnot`.
- [x] Flow-narrowing on `T | null` inside `if x != null { ... }` — pushes complementary narrowing past divergent then-branches.
- [x] Common-field access on `:: type` union aliases — already worked ; false alarm.
- [x] Enum-to-repr direct cast (`Repr(EnumValue)`) — one-step rule, no implicit widening.
- [x] Reject mutation of constant binding `x ::` (T3041 at assignment site, primary span on `x = ...`, secondary "declared here").
- [x] `match expr.field { _ -> use expr.field }` narrows on a field-expr scrutinee — parallel `narrowedFields` map keyed by `${targetSym.id}#${fieldName}`. Scope : single-level field access on plain idents.
- [x] `if v is T { v.field }` narrows `v` for field access — bug already healed via field-narrowing chain + typeInternKey dedupe.
- [x] Tuple destructure after `[T, U] | null` narrow — fixed parser ambiguity (block-tail exprs now reject postfix `[ ... ]` / `( ... )` chaining ; parens force the form).
- [ ] **AST node id boilerplate** — re-audited 2026-05-15 ; deferred. ~11 self-host fields + ~117 TS construction sites with `id: UNASSIGNED_NODE_ID`. All three resolution shapes (decorator, mixin, marker) need new compiler infrastructure that's bigger than the 128 lines it would save. Revisit if decorator infra lands for other reasons.
- [x] Transitive monomorphisation through nested generic calls — verified working.
- [x] **Byte literal syntax `b'X'`** (commit `dc457047`) — Rust-style `b'X'` evaluating to `u8` at parse time, both lexers + escape support. Triple-cast `b == u8(u32('{'))` swept from self-host call sites ; `vader/fmt/comments.vader` is the primary user.
- [x] Type-alias declaration order relaxed — verified free order.
- [x] Namespace-imported aliases unify with direct imports — `equalsType` falls back to comparing `definedAt` source position when symbol ids diverge. Deeper loader consolidation still tracked as a follow-up.
- [x] `MatchResult` workaround cleanup — `match_kind` returns `Token | null` directly ; ~60 call sites simplified.
- [x] Self-host lexer u64 overflow — promoted unsigned magnitude carrier to `u64` ; new `parse_uint_in_base`.
- [x] Flow-narrowing on `if x is T` (Phase A, ident scrutinee) — recognises `x is T`, `x == null`, `x != null` + leading `!`. Phase B (FieldExpr LHS receiver narrowing) deferred — needs path-based keying + immutability check.
- [x] `if x is T as binding { ... }` — mirrors match-arm shape ; binding scoped to then-block.
- [x] Drop `fn` keyword on lambda expressions — new form `(params) -> body` or `x -> body`. Decls still use `name :: fn(...) -> R { ... }`.

### 1.14 Snapshot test infrastructure — done
- [x] Single-source-per-test layout in `tests/snippets/{name}/_main.vader` + `{phase}.snapshot` files. Driver runs every pipeline phase. `UPDATE_SNAPSHOTS=1 bun test` for refresh. 80+ snippets covering generics, traits, comptime, error propagation, GC stress, closures, iter combinators.

### 1.15 Formatter
- [ ] Define formatting rules (one canonical layout — no options).
- [ ] AST → formatted source.
- [ ] Idempotency check.

(Status update : a first cut already shipped in Vader ; see top "Priority — next up" `vader fmt` MVP. This section tracks the design freeze separately.)

### 1.16 Examples
- [x] `hello`, `fibonacci`, `fizzbuzz`, `rule110`, `primes`.
- [ ] `aoc_2024_day1.vader` — validate I/O + parsing + collections.
- [ ] `wasm_browser/` — moved to Phase 3 (§3.10).

### 1.17 Enums — done

Required before self-hosting. All phases wired end-to-end.

- [x] Lexer + parser (`EnumDecl`, `.Variant` dot-shorthand, `EnumVariantPattern` arm, typed-let `name: Type = value`).
- [x] Type-checker (`EnumType`, exhaustiveness, dot-variant bidirectional inference).
- [x] Lowerer + bytecode/VM/C-emit — variants lower to typed integer constants ; no runtime change.
- [x] **Typed enums** — `Day :: enum(u8) { ... }` with optional repr suffix, explicit variant indices `Up = 10` with auto-increment, bounds + dup checks (T3029 / T3030 / T3031).

### 1.18b Generics & primitive type ergonomics — done
- [x] `usize` + `isize` first-class.
- [x] Migrated `arr.len()`, `ArrayIterator.length/cursor`, `std/iter` signatures to `usize`.
- [x] `Range[T]` impl deduplication via bounded `[T: Comparable & Step] Range[T] implements Iterator[T]` ; `Step` trait carries per-primitive successor.
- [x] Migrated `std/string` to `usize` indices/lengths.
- [x] Generic `Range :: struct[T]` — every integer width + `char` ships `Contains` + `Iterator` impls.
- [x] First-class function values.
- [ ] **Decide `usize` width on the WASM target** — moved to §3.10.
- [x] `void!` runtime/type mismatch — parser desugars to `null | Error`.
- [x] Enforce struct-level bounds at instantiation site (T3006).
- [x] Auto-inherit struct bounds onto methods.

### 1.18c-bis Function overloading across imports + local fns — done
- [x] Local fn coexists with same-named import — fn-overloads bucket repopulated after wireImports.

### 1.18c Function overloading by receiver type — done
- [x] Resolver `fnOverloads` map, typechecker UFCS dispatch rank (`concrete > symMatch > intoMatch > wildcard`), direct-call resolution via `pickDirectCallOverload`, T3032 on ambiguity, stdlib `min`/`max`/`abs` i32+f64 overloads.

### 1.18d Common-field access on discriminated unions — done
- [x] Typecheck + lowerer + same-offset shortcut (single struct.get when every variant stores the field at the same index with the same type). Self-host `expr_span` / `stmt_span` collapsed from 25-arm matches to one-liners.
- [x] Peephole spread bug — replaced `body.push(...out)` with explicit loop to avoid RangeError on > 16k spread args.
- [ ] **Methods (deferred)** — extend to UFCS calls (`e.method()` valid when every variant has a callable `method`). Invasive : overload resolution × variant set.
- [ ] **Nullable receivers** — `(T | null).f` follows the gate today (`null` lacks the field → T3009). Decide later whether to special-case optional-chaining.
- [x] **Divergent-type policy** — variants with differently-typed same-named field return `unionOf(...)` ; caller narrows.

### 1.18 Built-in type aliases — done
- [x] `int → i32`, `long → i64`, `float → f32`, `double → f64`, `byte → u8`. Diagnostics show canonical names.

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
- [ ] `@field(x, name) -> ?` — dynamic field access by comptime string.
- [ ] `@comptime for f in @fields(T) { ... }` — iteration syntax. Parser change + lowerer unroll.

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
- [x] `vader/cli/main.vader` argv parsing + stage dispatch — `lexer` / `ast` / `resolved-ast` wired ; further stages return "not yet implemented".
- [x] **Snapshot parity rig under `tests/parity/`** (2026-05-16) — `tests/parity.test.ts` + `tests/cli-bin.ts` compile the Vader CLI to `build/vader` and diff `lexer` + `ast` stages against the TS-generated snapshots for every snippet that ships one (~240/245). Skip set empty ; previous CJK outliers (`for_in_into_iter`, `string_bytes`) now pass byte-for-byte.
- [x] **Build the CLI native** (2026-05-16) — `tests/cli-bin.ts:ensureCliBuilt()` invokes `bun src/index.ts build vader/cli/main.vader --target=native --release` once per session and caches `build/vader`.
- [ ] Future stages plug in as parser / typechecker / lowerer get ported.

### 2.1 Port the parser to Vader

#### Lexer (`vader/lexer/`) — done
- [x] Token kinds + keyword/suffix tables + driver state + whitespace + nested block comments + identifiers + numeric literals (bases + suffixes + `_` separators) + char + string literals (plain/raw/triple + interpolation) + operators + newline emission + shebang + UTF-8 BOM + structured diagnostics.

#### Diagnostics (`vader/diagnostics/`)
- [x] `codes.vader` + `diagnostic.vader`.
- [ ] **Folder-module migration** — today `vader/diagnostics/{codes,diagnostic}.vader` resolve as separate single-file modules, so `private` doesn't survive cross-file. Migrate to folder-module to hide internals.

#### Lexer parity validation
- [x] **Snapshot parity with the TS lexer** (2026-05-16) — covered by the parity rig (§2.0). Native CLI built once via `tests/cli-bin.ts`, then `tests/parity.test.ts` diffs `--stage=lexer` against `lexer.snapshot` for every snippet.

#### Parser (`vader/parser/`) — done
- [x] AST representation (every node ported ; `type` keyword conflict → field renamed `ty`, dumper still emits `"type"` JSON key for parity).
- [x] `ParserCode` enum + `parser_info()` lookup (P1001..P1020).
- [x] Parser body (~2200 lines) — recursive-descent + Pratt.
- [x] AST → JSON dumper — byte-for-byte parity with `tests/snapshot.ts:formatProgram`.
- [x] CLI integration — `vader dump --stage=ast`.
- [x] **Parity** : byte-for-byte over every snippet that ships a `parser.snapshot` (~240/245). Validated by `tests/parity.test.ts` — see §2.0.

#### Bugs uncovered while porting — all closed
- [x] `as <name>` match-arm binding, primitive-only union dispatch, union-of-enums match, `match X.field { is Y as t -> ... }`, `if !bool_var`, enum_basic family, trait/impl-heavy snippets, dump diff cleanups.

### 2.2 Port the C emitter
- [ ] Port to Vader.
- [ ] Snapshot-test parity.

### 2.3 Port the bytecode emitter
- [ ] Port to Vader.
- [ ] Snapshot-test parity.

### 2.4 Port the VM

Sprint plan : [`docs/SELFHOST_VM.md`](./docs/SELFHOST_VM.md). The Vader VM reads `.virt` so each sprint validates against the live TS pipeline.

- [ ] Sprint 1 — `i32.const` + `return` ; `vader run return_42.virt` exits 42.
- [ ] Sprints 2-5 — locals, binops, control flow, strings, structs, arrays, calls, type checks.
- [ ] Sprint 6 — binary `.vir` loader (optional).
- [ ] Verify `examples/` runs against the TS VM.

### 2.5 Port the WASM emitter — gated on §3.10
(Empty until the TS WASM emitter lands.)

### 2.6 Port the type-checker (last)
- [ ] Port to Vader.
- [ ] Snapshot-test parity on every sample.

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
- [ ] **`std/json` v2 — compile-time-generated parsers** (kotlinx-serialization style) via `@derive(Json)`. Requires `@derive` machinery (§3.8).
- [x] `std/regex` — Thompson NFA via Cox's VM ; literals + char classes + shorthand `\d`/`\w`/`\s` + quantifiers `* + ? {n,m}` + alternation + capture groups + anchors `^$`. Pure Vader. ~750 LoC. Hors-scope : non-greedy, named groups, backrefs, lookahead/lookbehind, Unicode classes.
- [x] `std/time` — `Instant` / `Monotonic` / `Duration` with ns precision ; ISO 8601 round-trip. 2 host intrinsics (wired to `clock_gettime` natively, JS clocks on TS VM, WASI-ready).
- [x] `std/random` — xoroshiro128++, deterministic seeds, full range/shuffle surface. Pure Vader.
- [x] `std/crypto` — SHA-256 (RFC 6234), MD5 (RFC 1321). Hex output. Pure Vader.
- [x] `std/base64` — RFC 4648 standard alphabet. URL-safe variant deferred (drop-in alphabet swap).
- [ ] **`std/bignum` — `BigInteger` / `BigDecimal`** — arbitrary precision. Use cases : JSON parsing without precision loss past 2^53, money/financial DSLs, crypto bignums. Pure Vader ~600-1000 LoC each. BigInteger first.

### 3.5 Performance
- [x] **Generational GC** — two-gen Cheney with card table (`VADER_CARD_BYTES = 512`), age tenuring (`VADER_TENURE_AGE`), knobs `VADER_GC_YOUNG_BYTES` / `VADER_GC_OLD_BYTES`.
- [x] **`vader_array_push` array-doubling under double-GC pressure** — fixed by rooting `a` + `v` in a `vader_box_t` across `vader_array_buf_alloc`.
- [x] **GC robustness under high parse-time string-allocation pressure** — fixed missing write barriers in Cheney scan (old → young edges), card-table preserving across major collects, raw string fields enumerated in `vader_type_info_t`, `vader_array_push`'s arg precise-rooted, `vader_builder_t` chained through `g_builder_head`. Multi-hop forward resolution in `vader_array_resolve`. `VADER_GC_STRESS=1` env var turns intermittent rooting bugs into deterministic failures.
- [ ] Direct-ASM backend for one native target (validate the design).
- [ ] Escape analysis enabled (lower allocations on stack when proven safe).
- [ ] **Bytecode cache on disk** — to discuss / dimension. Today every `vader run` / `vader fmt` / `vader-lsp` re-parses + typechecks + lowers the full stdlib (~30 modules) before the VM executes a single instruction (~2-3 s for the formatter). Proposal : serialise per-module `LoweredModule` to a `.vbc` sidecar keyed by `(source_hash, compiler_version)`. Open questions : (a) serialisation format (binary vs MessagePack vs IR text), (b) cache invalidation across transitive deps (changing `std/core` busts every consumer), (c) interaction with `--target=native` C-emit, (d) interaction with comptime values (memoise too?). Stay VM-only for now — AOT is deliberately out of scope.
- [x] Whole-program DCE — user fns reachable from `main` + `@export` + `@test` + `@extern` ; libraries (no `main`) keep every user decl.
- [ ] **Lazy-materialise stack values in C-emit** (companion to DCE). Today's wins target primitives ; `local.get`/`local.tee` of ref/any still snapshot eagerly into a refTmp for GC-precision. Future : (1) detect call-arg pairs with no allocation, (2) skip explicit zero-init for primitives, (3) pre-declare blockres slots on first use. Each ~½ day.
- [x] `match enum` cascade → `switch` C (delivered via the static lookup table family).
- [x] Static lookup table for `match enum -> StructLit constant` — recognises 4 arm-body shapes (struct table, primitive table, block-form with propagation chain, sparse + wildcard cases). Self-host snippet: 7202 → 6353 lines.
- [x] Eliminate single-use primitive temp locals via bytecode peephole Rule 6.
- [x] **Hash-cons `Type` values + re-key registries by reference identity** (Phase A + B step 1 landed 2026-05-11 ; B step 2 landed 2026-05-15). All 37 inline `{ kind: "Struct" | "Trait" | "Fn" | … }` Type literals across `src/typecheck/passes/*.ts`, `src/lower/passes/*.ts`, `src/bytecode/emit.ts`, `src/lower/lower.ts`, `src/typecheck/check.ts` flipped to `mkStruct` / `mkTrait` / `mkFn` / `mkTuple` / `mkUnion` / `mkTypeParam` / `mkEnum`. Symbol-anchored caches (`structCache` / `traitCache` / `typeParamCache` / `enumCache`) switched to `WeakMap<Symbol, …>` along the way — `Map<sym.id, …>` was aliasing entries across compile invocations because resolver-instance Symbol ids restart at 1.
- [ ] **Value-type structs (`CodeInfo`-style)** — open discussion. Today every struct is heap-allocated + boxed. For small immutable structs never trait-boxed (e.g. `CodeInfo { id: string, message: string }`), a register-by-value pass would be free. Trade-offs : (a) syntactic distinction (`value struct` keyword? `@value` decorator? auto-detect?) ; (b) interaction with `is Trait` (value-types can't downcast — compile error?) ; (c) match patterns binding by reference ; (d) multi-register return ABI ; (e) escape analysis as a downgrade path. Decision needed before implementation.
- [x] Iterator-chain fusion at the lowerer — `for x in (MapIterator { source: FilterIterator { source: Range, pred: F }, f: G }) { body }` emits a single counter loop with inlined predicates. Chain must be inline at the `for` site ; variable-bound chains still hit the slow path.
- [x] Inline representation for small tagged unions (c-emit only) — empty payload or single-primitive-field structs fit in `vader_box_t` ; pre-scan of `struct.set` op type indices gates against MUTABLE struct corruption.
- [ ] **Inline trivial trait-method impls before bytecode emit** (deferred 2026-05-14). Methods like `i32.gt :: fn(a, b) -> bool { return a > b }` and one-arm vtable dispatchers emit a `Call` op each ; clang `-O3` inlines them in native, the VM doesn't. Plan : classify inlinable `LoweredFnDecl`s (single `LoweredReturn` of a pure expression, ≤ N midir ops, no recursion) + midir pass that replaces `Call(callee=inlinable)` with the substituted body + `pruneUnreachable` drops dead callees. **Why deferred** : current bench workloads (mandelbrot, primes) have no fn calls in hot paths ; VM bottleneck is parse + typecheck + lower (3.5+ s per invocation), not exec. Revisit when (a) bytecode-cache lands and (b) a bench workload shows fn-call density as a hot spot. ~1 day.
- [x] **Inline `MutableMap` / `MutableSet` iter at the for-in site** (landed 2026-05-16). `for entry in m` / `for v in s` over a `MutableMap(K, V)` / `MutableSet(T)` now lowers to a flat bucket-walk + chain-traversal loop instead of going through `into()` + `MapIterator.next()`. Skips the `MapIterator(K, V)` allocation, the per-iter call, and the per-iter `Yield(...)` boxing — the body branch directly casts the chain cursor and runs user code. Implementation : new `tryLowerForInMapSetIterInline` fast path in `src/lower/passes/for-in.ts` keyed on the into-coercion's source struct matching `std/collections::MutableMap` / `MutableSet`. **Bench : map_iter vader-native 22.6 ms → 9.7 ms (-57 %)** ; Vader-vs-Go gap closed from 2.8 × down to 1.12 ×. Snippets `map_set_iter` and `for_in_into_iter` saw their bytecode/lower/cfg snapshots regenerated (smaller — `MapIterator.into` / `SetIterator.into` are now dead-code-eliminated). Open : generalise to user-defined `Iterator` impls (today the inline only fires for the two known stdlib structs).
- [ ] **Open-addressed hash table for `MutableMap`** — **disqualified by bench, 2026-05-16**. 4 attempts, 5 compiler bugs surfaced + all fixed (commits `12a8de68`, `9489305d`, `4d43ecb2`, `52164253`, `28947e27`) : dedup struct/trait types by source position, cross-module ident resolution, cross-module typed-program swap for foreign sub-trees, FreeInt source pinning to cast target width, struct-instance subst threaded through foreign defaults. Robin Hood impl works end-to-end (VM + native, all tests green). **Bench result : map_iter regressed +59 % (36 ms vs 22.6 ms baseline)** — Vader's array runtime stores struct elements as heap-allocated `vader_box_t` pointers, so Robin Hood's main perf advantage (cache-friendly inline storage) is not realised. Iteration cost dominates : scan 2048-slot flat array (~25 % empty) vs walk 16 chained buckets that touch only filled entries. Reverted. **To make this worth shipping** : (a) inline-stored struct arrays at the runtime level (large c-emit + GC scan change), OR (b) the workload mix shifts toward lookup-heavy. Filed under "design constraint" rather than "follow-up" — the chaining design is the right call for the current runtime.

### 3.6 Memory model extensions
- [ ] Explicit allocator API (arenas, pools) for perf-critical paths.
- [ ] `unsafe { }` blocks for low-level FFI.

### 3.7 Tooling
- [ ] LSP server (in Vader) — diagnostics, hover, go-to-def, completion.
- [ ] **LSP : revisit hover signatures once the typechecker is self-host.** Today the indexer is AST-only ; hover on local bindings falls back to source slice + literal-suffix heuristics. When the typechecker lands in Vader (§2.6), consult its inferred-type table directly for proper `name: T` rendering. Same upgrade fixes param hover under generics + match-arm pattern bindings.
- [ ] **LSP : inlay hints for inferred types** (LSP 3.17 `textDocument/inlayHint`). (1) Declare `inlayHintProvider: true` in `vader/lsp/lifecycle.vader`. (2) Route `textDocument/inlayHint` ; walk AST nodes overlapping the range, emit one hint per `ConstDecl` / `LetDecl` lacking a type annotation. Skip parameter + return-type hints in v1. (3) Resolve `T` via the typechecker's inferred-type table — gated on the self-host typechecker.
- [ ] VS Code extension.
- [ ] Programmable build API (`build.vader` instead of `vader.json`).
- [ ] **Multi-library namespaces** — `STDLIB_PATH_PREFIX = "std/"` is hard-coded today. Generalise to a registry of `prefix → on-disk root` fed by `vader.json` (e.g. `{ "libraries": { "web": "./vendor/vader-web", "experimental": "./libs/exp" } }`). Use cases : (a) third-party libs via a package manager, (b) compiler-private namespace (`internal/`) with a "stdlib + compiler only" rule, (c) workspace monorepos. Touches `resolveImportPath`, `isStdlibModule`, DCE filter, dump-stage filters. ~150 lines + manifest schema bump.
- [ ] External package manager + central registry (much later).
- [ ] `man` page for `vader`.
- [x] GitHub Actions pipeline — `bun run typecheck` + `bun test` + cross-compile four archives via `bun run dist:all` ; uploaded as workflow artifact.
- [ ] **GitHub Release on tag push** — attach `dist/vader-*.tar.gz` and `dist/vader-*.zip` to a release on `v*` tag push (`softprops/action-gh-release` or `gh release create`). `permissions: contents: write`. Auto-generate notes from commit log between tags.
- [ ] **GitHub Actions matrix per OS** (post self-host) — fan out to `ubuntu`/`macos`/`windows` runners that each run `bun test` on their native binary and assemble locally.

### 3.8 Language ergonomics
- [x] UFCS on union receivers.
- [x] Type-alias unions in cross-module `Alias[]` array slots — added type-aliases phase in `checkProject`.
- [ ] **Reconsider the `string` model : codepoint-first vs byte-first.** Today `string` is a `(ptr, len)` UTF-8 byte slice ; `byte_len` / `byte_at` / `s[i]` (decodes from byte `i`) / `index_of` / `last_index_of` all leak the representation. A codepoint-first model (Python 3, Swift) — fat `string` view carrying both byte and codepoint lengths + a separate `bytes` view — would close the sharp edges. Big lift : runtime (`vader_string_alloc`, GC string-arena scan), C emit, bytecode pool, formatter, every stdlib string fn. Track to avoid accumulating more byte-first surface in the meantime.
- [x] Array slicing `arr[r]` — `arr[lo..<hi]` / `arr[lo..=hi]` / any `arr[Range[<int>]]` returns a fresh `T[]`. Dispatch on index type, not RangeExpr AST kind.
- [ ] Static-size arrays `[T; N]`.
- [x] Literal-value patterns in `match` — `'a'`, `42`, `true`, `"ok"`, `null` ; lowers as `LoweredBinary { op: "eq" }`. `examples/brainfuck.vader` first user. Known parser quirk : `-N` literal pattern on a fresh line is consumed as `prev - N` (workaround : indent the body). Or-patterns + range-patterns still deferred.
- [ ] Pattern matching extensions — or-patterns (`'a' | 'b'`), range-patterns (`'a'..='z'`).
- [ ] `@derive(Eq, Display)` to auto-generate trivial impls.
- [x] Allow `int_type(enum_value)` cast for `enum(IntT)` types (2026-05-15) — `inferTypeConstructorCall` accepts any numeric / char target against an enum source ; lowers as `repr → target` cast op (same machinery as `i32(u8_value)`). Mirrors Rust `as` / Zig `@intFromEnum`. C-emit `emitConvert` / `coerceExpr` now double-cast `(to)(from) v` so widening a u32-on-the-stack to u64 zero-extends correctly.
- [x] Implicit `void` return — already worked ; added `void` as reserved ident (R2019).
- [x] **Auto-`.iter()` in `for-in` via `Into(Iterator(T))`** (2026-05-15) — no new trait, `Iterable(T)` would be structurally identical to `Into(Iterator(T))` which already exists. `checkForStmt` now calls `tryInto(iter, Iterator(elementVar))` when the iter is neither `Iterator`/`Array`/`Range` nor has a direct `Iterator` impl ; the existing intoCoercions side-table flows through `lowerExpr` → `wrapAsInto`, producing an `Iterator(T)`-typed value that `lowerForIn`'s existing trait-typed branch dispatches via vtable. `MutableMap`, `MutableSet`, and `string` got the matching `Into(Iterator(...))` impls in stdlib (string → codepoint default ; `bytes()` stays opt-in). Snippet : `tests/snippets/for_in_into_iter/` covers array / map / set / UTF-8 string.
- [x] **Trait-object boxing + dynamic dispatch for `Iterator(T)` (and other traits)** (initial 2026-05-08, finalised 2026-05-15). Vtable IR wired through bytecode/VM/C-emit. UFCS receiver `Into`-coerce was the missing piece : `arr.fn()` against `fn[T](it: Iterator(T), ...)` typechecked via the trait-widening rank but lowered without recording the `T[] → Iterator(T)` coerce, so the runtime saw a raw array tag in the vtable. `inferGenericUfcsCall` now records `tryInto(receiver, expected-first-param)` post-unification. `tests/snippets/trait_box_range_iter/` covers `count(0..<5)` + `count([10, 20, 30])` + `invoke(Hello {})` + `twice(7)` — all green.
- [x] Operator overloading via trait dispatch — `+`/`-`/`*`/`/`/`%` via `Add`/`Sub`/`Mul`/`Div`/`Rem`, `==`/`!=` via `Eq`, `<`/`<=`/`>`/`>=` via `Ord` (compare ≷ 0), `a[i]` via `Index`, `a[i] = v` via `IndexSet`, `in`/`!in` via `Contains`. Compound assigns desugar at parse time.
- [ ] **Function overloading by full signature** (post-MVP elevation of receiver-only overloading) — pick the candidate whose *all* parameter types match. Generalises the resolver's overload table + typechecker's call resolution.
- [x] **`Into[Target]` auto-coerce mechanism** — 4 implicit sites (call arg, return, let typed, struct field) + explicit `Target(value)`, blanket impl support with `[T: Bound]`, comptime materialisation via Pass 4 in `monomorphizeProject`, built-in coercions folded in (`T[] → Iterator(T)`, `T → string`). Open : ambiguity diagnostic, `@cheap_coercion` / `@allocating_coercion` markers, LSP "find coercion usages", strict-mode `@explicit_coerce` opt-out.
- [x] Expression-bodied functions with explicit return type.
- [x] Struct spread / functional update `MyStruct { ...other, .field = v }`.
- [x] Struct field default values `field: T = expr`.
- [x] Tuple types + destructuring `[T1, T2, ...]` (≥ 2 elements) ; postfix `T[]` for arrays. TS-style contextual disambiguation. Field access `t.0` / `t.1`. Destructure in `let` + match arms. Lowers to anonymous structs (no new BC ops).
- [x] Comptime tuple / struct / array values + Odin-style `name : Type : value` top-level typed const.
- [x] Spread destructuring `let [first, ...rest] = arr`.
- [x] Process spawn intrinsic — `std/process.spawn(argv) -> ProcessResult!` ; WASM unbound.
- [x] Inline `@file(path)` as a comptime expression (legacy decorator form removed).
- [x] Implicit selector expressions — `f = .Variant`, `match d { .Variant -> ... }`, `is .Foo` patterns against tagged unions.
- [x] `@assert(condition)` compile-time assertion (C4015).
- [x] `@partial` on `match` — opt-out of exhaustiveness for a single match.
- [x] `@deprecated("reason")` decorator (W0001) — first warning-severity diagnostic.

### 3.9 Companion projects
- [x] Brainfuck compiler in Vader, targeting the Vader VM — single-file `examples/brainfuck.vader` + `examples/hello.bf`. Constructs an `op.Module` programmatically through `vader/vm/builder` (no `.virt` text intermediate), runs through `vader/vm/exec.exec` and via `--target=native`. BF `,` not wired.

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
