# Vader — TODO

Implementation roadmap for the Vader compiler and standard library, derived from `SPEC.md`:

- **Phase 1** — MVP compiler in TypeScript, plus stdlib in Vader.
- **Phase 2** — Self-hosting (port the compiler to Vader).
- **Phase 3** — Post-MVP language features and tooling.

Completed items (`[x]`) are kept as one-liners — see git history for implementation notes, commit hashes, migration steps. Open (`[ ]`) and in-progress (`[~]`) items keep the full context needed to act on them.

---

## Priority — next up

- [x] **Module system redesign** (landed 2026-05-22, Vader-side strict resolver follow-up 2026-05-23). Explicit `module "..."` keyword on every `.vader` file ; module identity decoupled from filesystem layout. Strict resolver on both sides (TS + Vader self-host) replaces the legacy `promoteToFolderModule` heuristic with an up-front `discoverModules` scan + name-indexed import lookup. Vader-side uses a header-only byte-scanner (`parse_module_header`) so discover memory stays bounded for the ~170 .vader files under stdlib + vader/. Stdlib reorganised into per-module folders ; vader/types + vader/resolver/symbol extracted to break the typecheck↔resolver cycle that surfaced at the strict flip. Design log + 45 decisions in [`docs/MODULE_SYSTEM.md`](./docs/MODULE_SYSTEM.md). **Deferred** : (a) parser `module "..."` strict-presence diagnostic (resolver R2020 already catches missing decls at scan time), (b) TS-vs-Vader byte-diff in `parity-broad.test.ts` (smoke check stays ; remaining divergences trace to the Vader self-host typechecker populating fewer expression types than TS — separate chantier).

- [ ] **Cross-file duplicate-decl silent first-wins** (surfaced 2026-05-23 during a post-Phase-7 cleanup of `src/resolver/collect.ts`). Decision #28 of the module redesign mandates R2026 ("hard error") for non-fn duplicates across files of the same module, but the resolver still silently first-wins — by design, today the self-host carries 7 latent cross-file collisions (`vader/vm/{ScopeEntry,PendingBranch}`, `vader/typecheck/{Color,Wrap,Display,Point}`, `vader/lower/CellInit`) that the silencing branches mask. Two paths : (a) rename the latent collisions + remove the silencing branches in `collect.ts::{addFnSymbol,addSymbol,bindImport}` so R2026 fires from now on ; (b) revise decision #28 + §1.6 to formally document the silent first-wins. Same arbitrage applies to `bindImport` for duplicate import-bindings across sibling files (§1.5 says file-scoped — today's `collectModuleSymbols` lumps them per-module). Details in [`docs/MODULE_SYSTEM.md`](./docs/MODULE_SYSTEM.md) §8 "Cross-file duplicate decls — silent first-wins still active".

- [ ] **Resolver port follow-ups** (port wave 2026-05-23). The Vader resolver now emits R2001/R2002/R2003/R2004/R2008/R2010/R2011/R2016/R2019/R2020/R2022/R2023/R2024/R2025/R2026/R2028, parser errors are surfaced via `load_project.diags`, and `tests/parity-diagnostics.test.ts` is enabled (1095 pass / 46 known divergences). Remaining gaps :
  - **R2006 at resolver-stage** : Vader still emits `R2006 unresolved identifier` from `vader/typecheck/expr.vader`, not from the body walker. TS emits it during `src/resolver/resolve.ts::resolveExprNode`. To close, seed `core_symbols` into the body-walker scope (today only available post-resolve) and move emission to `body.vader::walk_expr` IdentExpr arm. Affects 8 KNOWN_DIVERGENCES entries (`errors_parser`, `interpolation_tokens`, `unknown_ident`, `lexer/l0001_unexpected_character`, `lexer/l0007_stray_backslash`, `parser/p1014_unknown_decorator_placement`).
  - **R2018 orphan rule** : the resolver doesn't yet check that `Type implements Trait` keeps at least one of `forType` or `traitName` in the current module (with the primitives-exempt carve-out). Mirrors `src/resolver/resolve.ts:230-244`. Needs the `wire_imports` redirect table threaded into a project-level pre-resolve pass (the body walker only sees the local scope). 4 KNOWN_DIVERGENCES entries.
  - **R2009 (trait_name resolves to non-trait)** + **R2007 on impl trait name** : my first attempt over-fired on `Into` / `Display` / `Iterator` (auto-loaded `std/core` traits not in the body-walker's scope). The R2007 sibling now lives in `materialize_all_sams_pre_resolve` (project view, `find_trait_decl_in_project`). R2009 is harder — needs `core_symbols` access AND a way to discriminate Trait from Struct/Enum/Alias on imported symbols. Currently emitted by the typechecker.
  - **T3013 / T3015 / T3050 / T3051** : Vader's typechecker doesn't yet emit these diags for the simple-snippet shapes (non-exhaustive match in return position, top-level break, invalid `@extern` decl, `@extern` with body). 11 KNOWN_DIVERGENCES entries.
  - **C-codes renumbering** : `vader/diagnostics/codes.vader::ComptimeCode` defines C4001..C4007 with *different semantics* than `src/diagnostics/codes.ts` (C4001 = DependencyCycle vs "cannot be evaluated", etc.). TS also defines C4008..C4015. Realignment is a separate chantier — touches `tests/diag_corpus/comptime/` snippets and `tests/vader_vm.test.ts::KNOWN_DIVERGENT`. 8 KNOWN_DIVERGENCES entries.
  - **Parser P1029 / P1030** : TS emits these for missing/malformed `module "..."` decls ; Vader's parser delegates to the resolver (R2020/R2022). Either port to Vader parser too or keep the divergence documented.
  - **W0002 unreachable-code** : warning defined on TS side but absent from `vader/diagnostics/codes.vader::WarningCode`. Same chantier as the unreachable-code analysis port to the Vader typechecker.
  - **Vader-only LowerCode L5xxx** : 6 codes defined in `vader/diagnostics/codes.vader::LowerCode` (`IteratorImplMissing`, `LambdaCaptureUnsupported`, `UnreachableMatchPath`, `IntoCoercionFailed`, `IntrinsicUnsupported`, `SelfReceiverMissing`) without TS counterparts and without emit sites. Decide : align with TS (drop them, route through existing T-codes) or formalise them as Vader-specific lower-stage diagnostics.

- [ ] **Resolver lazy index** — the strict resolver's `discoverModules` currently scans every `.vader` file under the scoped roots up-front (stdlib + `vader.json::modules` + entry's folder via CLI fallback). For a tiny snippet like `arith` that only imports `std/io`, the Vader CLI walks ~170 file headers per invocation — ~660 ms per `dump` call vs. ~100 ms under the legacy depth-1 BFS. The full scan only earns its keep on cross-module entries (`namespace_alias_dedupe`, broad-parity). **Idea** : lazy discovery — start with an empty index, populate stdlib + the entry's folder eagerly, then on `index.get(name)` miss, expand the search by walking the next scoped root. Same final state, but small snippets pay only for what they actually import. ~2-3 h of carefully-staged rewrite of `vader/resolver/loader.vader` + `vader/resolver/discover.vader` ; the TS counterpart in `src/resolver/loader.ts` likely benefits too. Affects every `bun test` that touches the snapshot pipeline (which spawns the Vader CLI ~250 × per stage).

- [x] **Single-binary distribution** (2026-05-10) — `bun build --compile` + per-OS tarballs (`vader-<os>-<arch>.tar.gz`) bundling the binary with `stdlib/` and `runtime/c/` sidecars. `scripts/dist.ts` + `dist:*` npm scripts.
- [~] **`vader fmt` MVP** (first pass 2026-05-11) — written in Vader under `vader/fmt/`, exercises the self-host parser end-to-end. Idempotency + parse round-trip green on the stdlib ; byte-for-byte no-op pending on three stylistic gaps : (a) `::` column alignment in decl groups, (b) per-line grouping inside multi-line imports, (c) cap at 1 blank line between decls vs the stdlib's occasional double-blank. Tests : `tests/formatter*.test.ts` (gated `RUN_FMT_TESTS=1`). Open : column alignment decision, hand-curated snapshot scenarios, growing `NO_OP_FILES`.
- [x] **Reference benchmark** (2026-05-14) — `bench/` with mandelbrot + primes in Vader / TS / Go ; `bun run bench` compares against `bench/baseline.json` (10 % regression budget). See [`bench/README.md`](./bench/README.md).
- [x] **Adopt `s[i]` over `s.char_at(i)`** (2026-05-11) — `char_at` export dropped ; `.byte_at(i)` kept in hot byte-level scanners.
- [x] **SSA round-trip removed** (2026-05-14) — measurement showed zero precision gain over flat-CFG escape analysis ; 335 LoC of SSA + dominance-frontier code deleted.
- [x] **Loop-carried-dependency check** (2026-05-14) — replaced over-conservative `inLoop` escape filter ; +95 stack-promotions on the self-host.
- [x] **Monoliths broken up** — incremental ; largest `src/` file is now `lower/passes/expr.ts` at 983 lines, below the 1k-line threshold.
- [x] **LSP semantic classification via the AST + body-walking resolver** (landed 2026-05-16). `vader/resolver/body.vader` walks fn bodies / blocks / lambdas / for-loops / if-is-as bindings / match patterns with a scope stack, producing a span-keyed `IdentExpr → Symbol` map (`ResolvedFile.idents`). Symbols carry their kind (`Fn`, `Struct`, `Param`, `Local`, `Binding`, `TypeParam`, …). `vader/lsp/ast_tokens.vader` runs the positional Phase 1 walker, then a Phase 2 `refine_via_resolver` pass overrides every Phase-1 token whose span matches a resolved ident with the symbol-kind-derived `TokenType`. In-body `x` (param) now paints `Parameter`, `val` (local) paints `Variable`, type names paint `Type`. The resolver lives in `vader/resolver/` so the eventual self-host typechecker (§2.6) reuses the same walker — no duplication between LSP and compiler.

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
- [x] Stable ABI for `@extern` user imports (landed 2026-05-16). C-emit now emits real `extern <ret> <name>(<params>);` declarations + forwarding shims that call the foreign symbol ; the previous `vader_trap("unbound import: ...")` default arm is reserved for compiler-internal mismatches. Decorator accepts 0/1/2 string args (last = C symbol, 1st of 2 = future WASM module hint). Signature whitelist : primitives + `string` (marshalled via `vader_string_to_cstr` → `const char*` + `vader_cstr_free`). T3050/T3051 typecheck guards. CLI `--ldflags="..."` passes raw linker flags. Snippet `extern_native_basic` calls a helper.c + libc strlen end-to-end ; VM target skips (no host-fn registry for user externs).
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
- [ ] **Audit `std/iter` and `std/string` surfaces** — surfaced 2026-05-20 during SPEC vs stdlib sweep. Two threads to follow up : (a) `std/iter` is missing an explicit `into_iter()` helper (SPEC previously referenced one) — decide between adding `arr.into_iter()` as an explicit form or relying solely on the `T[] implements Into(Iterator(T))` coercion ; (b) `std/string` exports drifted from SPEC (added `index_of`, `compare_ascending`, `compare_ascending_ci`, `decode_escapes` ; missing `is_hex_digit` / `is_digit_in_base` — now placed under `std/numbers`). Pass to settle on one canonical surface per module and align SPEC + stdlib + ports.
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
- [x] Block / match / if diverges → type `never` (landed 2026-05-16). A trailing-less block whose statements all diverge (`return` / `break` / `continue`, or a nested exhaustive match / both-branch if) types as `never` instead of `void`. Lets `fn(v: A | B) -> T { match v { is A → return … is B → return … } }` type-check without the dead-code `return …` after the match. `unionOf` absorbs `Never` so `if c { x } else { return }` widens to the type of `x`. New `divergesExpr` / `divergesBlock` / `divergesStmt` helpers in `src/typecheck/passes/stmt.ts`.
- [x] Infinite `for {}` / `for true {}` loops diverge (landed 2026-05-16). `divergesForStmt` recognises the infinite shape and walks the body for a `break` that targets this exact loop (label-aware ; unlabeled break inside a nested loop binds to that nested loop, not the outer). Drops the last `return 0 // unreachable, see fmt.vader pattern` in `vader/lsp/main.vader` + one similar pattern in `vader/parser/parser.vader`.
- [x] **W0002 unreachable-code warning** (landed 2026-05-16). Fires when a statement (or trailing expr) appears after a divergent statement in the same block — same `divergesStmt` analysis as above. Emitted once per block on the first dead stmt. Surfaced 4 dead-return patterns in stdlib (`std/iter`, `std/json`, `std/cli`) + 1 in `vader/fmt/cli.vader` — all cleaned.
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
- [ ] **`for <range> { ... }` shorthand** — desugar `for <expr> { body }` where `<expr>` types as `Range(T)` into `for _ in <expr> { body }` at parse or typecheck time. Neither parser supports it today, both go down the `while-cond` path and the typechecker emits T3019 (`Range(i32)` is not `bool`). Surfaced 2026-05-18 in `stdlib/std/string_builder.vader::append_repeated` and `stdlib/std/collections.vader:69` — both currently fixed by hand-adding `_ in`. Once the sugar lands, those `_ in` can go away.
- [ ] **Normalise generic syntax to `<T>` across stdlib + self-host** — superseded
  2026-05-25 by the Java/C#-style migration. TS parser now accepts `<T>`
  (canonical), `[T]` (legacy bracket), and `(T)` (legacy paren) in all
  three positions ; SPEC §10 leads with `<T>`. Remaining work :
  - **Phase B** : port the Vader self-host parser (`vader/parser/parser.vader`,
    `vader/lexer/lexer.vader`) to mirror the TS changes — `<T>` opener,
    `shr` split-on-demand for nested generics, hard-precedence scan in
    expression position.
  - **Migration** : rewrite every `[T]` / `(T)` generic site under
    `stdlib/`, `vader/`, `tests/`, `examples/` to `<T>`. Best done with a
    parser-aware AST walker that locates the exact `[/]` / `(/)`
    delimiters around each typeParam list and generic-inst args. The
    `vader fmt` rewrite is a separate chantier — fmt today still emits
    `[T]`, so a fmt pass post-migration would revert the change unless
    fmt is updated first (or in parallel).
  - **Drop legacy parser paths** : once everything is migrated, remove
    the `[T]` and `(T)` openers from `parse_bracketed_type_params` /
    `parse_struct_type_param_list` / `parse_generic_arg_list` in both
    parsers. Pre-MVP, no back-compat (CLAUDE.md).

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
- [ ] **Carry the C-emit codegen pistes into the Vader walker port**.
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

- [ ] **`Cell(T)` heap promotion** — closure analysis identifies the
      capture set (`ClosureAnalysis.captured_symbols`) but
      `lower_let` / `lower_ident` don't yet emit `LoweredCellNew` /
      `LoweredCellGet` ; mutable closure variables observe stale
      copies until this lands. Stub `helpers.vader::lower_cell_init`
      is in place.
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
- [ ] **`is Type` antipattern in union-typed values** — `match expected { is Type | null }` etc. `expected is Type` against the closed `Type` union always returns false (the runtime tag is the variant tag, not the union tag). Bit me twice : `seq_lit.vader::infer_seq_lit` ignored every union-shaped expected slot ; `infer_seq_lit`'s "`picked is Type`" branch never fired. Fix is `match { is null -> {} _ -> ... }`. Search the codebase for other `is <UnionAlias>` checks (none found via grep on the typecheck dir, but worth a pass over `vader/resolver/` and `vader/lower/`). Either lint this at the compiler level or rename the patterns to avoid the trap.
- [x] **`vader build -o <path>` honored** (2026-05-17) — `cmdBuild` now pre-strips `-o <path>` POSIX-style and treats it as `--out=<path>`. Earlier the `--`-prefix filter dropped both `-o` and its value into positionals ; `outFlag` stayed undefined and the binary landed at the default location.
- [ ] **`settle_external_expr_bodied_returns` walks every non-entry module's body** (added 2026-05-17, `vader/typecheck/orchestrate.vader`). Runs the full `walk_bodies` pass (FnDecl + ImplDecl + ConstDecl + AssertDecl) instead of just the expression-bodied fns whose returns need patching. Triggers on any module that has *one* expr-bodied fn ; for std/iter etc this can multiply typecheck time. Scope it down to expr-bodied FnDecls + impl methods only.
- [ ] **Code-size explosion when adding a small branch to `is_assignable`** (2026-05-17). Adding a 15-line `ArrayType → TraitType(Iterator)` arm to `vader/typecheck/type_ops.vader::is_assignable` made the emitted `vader/cli/main.c` jump from 27 MB to 90 MB (3.3×) — and that bloated clang compile time from ~1 min to ~10 min. The branch itself is trivial ; the explosion is in the C emitter inlining or monomorphising `is_assignable` (or its caller cascade) more aggressively per added arm. Worth investigating before adding more branches to this function — without that, each typecheck change pays a 10-minute clang tax. Possible mitigations : (a) hoist the arm into a separate `fn try_array_to_iter_coerce(...)` helper, (b) split `is_assignable` itself into one helper per type-pair class, (c) verify the c-emit isn't full-clone-inlining `match` arms.
- [ ] **`build/vader` background processes don't get killed when typechecker / VM regresses** (2026-05-17). Found 3 `build/vader run tests/snippets/custom_iter/bytecode.snapshot.virt` + 1 `bun src/index.ts run bench/map_iter.vader` processes pinning 100% CPU for **33+ hours**, residue of sessions where custom_iter's bytecode VM execution actually did loop forever (since fixed). `parity.test.ts` has a 30s per-test timeout but the native runner spawned from it doesn't inherit that — once Bun's test driver bails on timeout, the spawned VM keeps running. Add a `kill` step to the native test driver's cleanup, OR run each child under a hard wall-clock budget (`timeout 30s build/vader run ...`).

- [ ] **DCE primitive trait-impl entries via "primitive-as-value" usage tracking** (2026-05-25). `src/midir/dce.ts::drainPending` at line 156 explicitly punts on primitive receivers : `if (e.structSymId !== null && !reachable.has(e.structSymId)) continue` — every primitive impl skips the gating, so the full `Display` / `Equals` / `Add` / `Sub` / `Mul` / `Div` vtable survives as soon as any `virtual.call` against the trait survives. Concrete cost on a generic `[T: Display]` fn lowered via erasure : 15 `to_string` imports + 15 `_vt` trampolines + 15 vtable rows for *one* `println(some_i32)` call. Stop-gap landed 2026-05-25 : `@specialize` on the four `std/io` wrappers (sidesteps virtual.call entirely for the common case). Proper fix : track which primitives are actually materialised in reachable code (literal consts, casts, fn signatures' param/return types, struct field types) and gate primitive-receiver impls on that set. Implementation surface : (a) add a `usedPrimitives: Set<PrimitiveName>` populated during the worklist walk in `pruneUnreachable` (visit `LoweredIntLit` / `LoweredFloatLit` / `LoweredCast` / `LoweredFieldAccess` / fn-decl param-types) ; (b) extend the `pendingVirtual` drain with a primitive-aware gate analogous to the existing struct gate ; (c) verify the change doesn't break tag-aware paths in trait_box_range_iter / json_basics. Earns the win for *every* generic `[T: Display]`-shaped user code, not just the stdlib wrappers — `@specialize` is the local opt-in, this is the global default.

- [ ] **Self-host closure capturing two free vars segfaults at runtime** (2026-05-25). While simplifying `vader/typecheck/orchestrate.vader::pull_referenced_external_types` to route through the canonical `for_each_type` walker, replacing the explicit recursion with `for_each_type(t, (sub: Type) -> register_named_external(sub, entry, per_module))` made the self-host binary SIGSEGV (exit 139) at the first call. The only prior closure-with-capture in the tree (`vader/midir/lowered_walk.vader:222`) captures a single `ctx` struct ; my version captures two free vars (`entry: TypedProgram` and `per_module: MutableMap(string, TypedProgram)`). Reverted to explicit per-variant recursion with a code comment pointing at this entry. Probable root cause : `vader/lower/closure_analysis.vader` + `LoweredMakeClosure` emit doesn't handle the second captured slot correctly, or the `$Cell_T` synthesis miscomputes the layout. Repro path : restore the `for_each_type` form at `orchestrate.vader:758` (see git history of the 2026-05-25 fix commit), rebuild, run `./build/vader dump --stage=typed-ast vader/cli/main.vader`. Until fixed, prefer the explicit walker shape OR bundle captured state into a single struct (the lowered_walk.vader pattern).

#### Language ergonomics surfaced while porting the typechecker — open
- [ ] **`!is` (negated type-test) operator** — `if !(sp is null) { … }` reads worse than `if sp !is null { … }`. The self-host typecheck port writes `!(x is Y)` a lot in narrowing / dispatch helpers (`expr_if.vader`, `stmt.vader`, `narrow.vader`). Adding `!is` as a parser sugar that lowers to `Not(BinaryOp.Is(...))` would clean those sites up — same surface as Swift's `!is`. No type-system change required, just lexer + parser + formatter.
- [ ] **`if a is X { a.field }` doesn't narrow `a` across statements** — single-expression guards work but `if a is X { for v in a.variants { … } }` requires a `match a { is X as ax -> { for v in ax.variants { … } } _ -> {} }` rewrite. Bit me in `vader/typecheck/binary.vader::types_overlap` ; eventually settled on a tiny `union_variants :: fn(t) -> Type[] | null` helper to dodge the narrow. Either tighten the flow analysis so `a.variants` inside the if-then sees the narrowed type, or document the rewrite + add it to the formatter's lint pass.

#### Typechecker port follow-ups — open
- [x] **Cross-module folder modules** — landed 2026-05-17. Root cause was a runtime UAF : `vader_read_dir` stored `ent->d_name` (DIR-owned, reused on next readdir) without copying. `mod_a` was the first user-folder ; by the time its name was read back, the buffer pointed at garbage so `load_module_files` saw an empty entry and skipped the module. `vader_string_alloc` + memcpy in `vader_runtime.c`. Also `join_path` now strips leading `./`, `dump_program_with_others` writes one section per loaded module (sorted), and `settle_external_expr_bodied_returns` walks every non-entry module's bodies so per-module `expr_types` populate for the dump.
- [x] **Generic trait method substitution** (2026-05-17) — landed via `trait_decl_owners` side-table + `substitute_by_name` over `Yield(T)` etc. `try_default_trait_method` for inherited Iterator defaults landed too. Unblocked iter_coerce_array (with `try_array_to_iter` in coerce.vader), iter_combinators, iter_zip_chain, trait_box_range_iter, string_codepoints. Still blocked on default-method *materialize-into-impl-with-original-line:col* (separate item below).
- [x] **Generic fn-call argument inference back-propagation** (2026-05-17) — `call.vader::infer_call` now substitutes bindings into each param BEFORE typing it (so lambda's expected fn-type reflects already-bound type-params), and `unify_type_param` tightens Free* bindings when a later arg pins the same TypeParam to a concrete numeric. `expr_lambda.vader::pick_final_return` falls back to body's defaulted type when expected is TypeParam-bearing.

- [ ] **Default-method materialize into impls with original line:col** — TS materialises trait default-bodied methods (`Iterator.is_empty`, `Iterator.count`, …) INTO each implementing struct's impl, preserving the std/core line:col in the dump but with `Self → struct_ty` + `T → trait_arg` substituted. Blocks `custom_iter`, `custom_iter_generic`, `iter_defaults`, `trait_dispatch_generic_iter`, `for_in_iter_trait`. Heavy : needs a body-walk pass that types the trait method's AST under a substituting context AND writes to entry's typed program at the trait method's original spans. Blocker for the substitution part : no `substitute_expr` walker exists in `vader/resolver/substitute.vader` — only `substitute_type_expr` for type-position exprs. Adding the full expression walker is the big lift.
- [x] **T3006 (trait bound not satisfied) at call sites** (2026-05-17) — landed via `fn_decls: i32 → FnDecl` side-table (cross-published across modules), idents-write on type-param decl sites in the resolver, and `check_typeparam_bounds` post-pass in `call.vader::infer_call`. Closed `conformance_explicit`.
- [ ] **`a == b` on user structs → `a.equals(b)` lowering at typecheck** — TS records the synthesised CallExpr / FieldExpr in `expr_types` at the BinaryExpr's span so the dump shows `bool` / `fn(Money) -> bool` / `Money` entries even though the source is just `a == b`. Self-host returns plain `bool` without the synth entries. Blocks `op_overload_eq_ord` parity.
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
- [ ] **LSP : inlay hints for inferred types** (LSP 3.17 `textDocument/inlayHint`). (1) Declare `inlayHintProvider: true` in `vader/lsp/lifecycle.vader`. (2) Route `textDocument/inlayHint` ; walk AST nodes overlapping the range, emit one hint per `ConstDecl` / `LetDecl` lacking a type annotation. Skip parameter + return-type hints in v1. (3) Resolve `T` via the typechecker's inferred-type table — gated on the self-host typechecker.
- [ ] VS Code extension.
- [ ] **`vader doctor --json`** — environment + toolchain sanity check emitting a structured report : `bun` / `cc` / stdlib paths discoverable, `runtime/c/` present, `vader.json` schema valid, GC env-vars in range, comptime cache writable. Two output modes : human-readable text (default) and `--json` for agent / CI consumption. Lives in `vader/cli/doctor.vader`. Cheap to ship and pays for itself the first time a fresh clone fails opaquely.
- [ ] **Structured `repair.id` field on diagnostics** — every entry in `vader/diagnostics/codes.vader` gains an optional `repair: { id: string, ... }` describing a deterministic fix that an LSP code-action or an LLM can apply. Examples : `R2003 unknown identifier → repair.id = "declare-missing-symbol"`, `T3007 missing field → repair.id = "add-field-default"`, `T3019 wrong arity → repair.id = "insert-trailing-arg"`. Surface in both `--diagnostics=json` output and `textDocument/codeAction` LSP responses. Start with the 5-10 highest-frequency codes ; the repair *implementation* can land later — the *contract* is the value. Cross-ref §1.0.
- [ ] **LSP code actions framework** — general refactoring infrastructure on top of the LSP. Components : `codeActionProvider` capability in `vader/lsp/lifecycle.vader` ; new `vader/lsp/expr_at.vader` position → `Expr` walker ; `vader/lsp/code_actions.vader` registry of `{ kind, title, is_applicable, apply }` records ; expose `emit_expr(e: Expr) -> string` out of `vader/fmt/printer.vader`. First three actions : `match → if` (≤ 2 arms reducible to booleans), `if-chain → match` (≥ 3 branches on same scrutinee), null-narrow rewrite. Reuses the same scaffolding for future refactorings (extract-fn, inline-let, rename). Design + open architectural questions captured in [`docs/LSP_CODE_ACTIONS.md`](./docs/LSP_CODE_ACTIONS.md). Deferred until self-host MVP closes ; cross-ref the `repair.id` entry above for the diagnostic-driven companion.
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
- [x] **Reconsider the `string` model : codepoint-first vs byte-first** (2026-05-24) — A7 landed the user-facing flip. `s[i]` and `s[r]` index by codepoint ; the byte-cursor family is namespaced (`byte_at`, `byte_decode_at`, `byte_slice`, `byte_len`). `bytes()` returns a `u8[]` (random-access + iterable). `count_chars` renamed to `len`. The fat `(byte_len, codepoint_len)` representation is deliberately NOT shipped — codepoint count is computed on demand via `len()` ; the model stays `(ptr, byte_len)` with codepoint semantics on the index surface. See `docs/ARRAY_STRING_VIEW_DESIGN.md`.
- [x] Array slicing `arr[r]` — `arr[lo..<hi]` / `arr[lo..=hi]` / any `arr[Range[<int>]]` returns a fresh `T[]`. Dispatch on index type, not RangeExpr AST kind.
- [x] **Non-owning slice / span views** (2026-05-24) — A7 landed array view aliasing : `arr[r]` returns a zero-copy view `(elements, offset, length)` sharing the parent buffer, with detach-on-push for mutation safety. `string[r]` (codepoint-indexed) currently still allocates a fresh string via `vader_string_slice_codepoints` ; a zero-copy substring view is a planned follow-up (UTF-8 bookkeeping makes it less trivial than the array case). `s.bytes()` is also still O(n) copy ; a `u8[]` view sharing the UTF-8 buffer is the natural next step. See `docs/ARRAY_STRING_VIEW_DESIGN.md`.
- [ ] **`defer` unwinds on panic** (gap surfaced 2026-05-19) — today defers are lowered as straight-line statements at `return` / `break` / `continue` exits (`src/lower/passes/block.ts:188-202`) ; a runtime panic (uncaught error, OOB, null deref) throws `VmError` directly (`src/vm/exec.ts:35`) and **skips every pending defer in the current frame and frames above**. Files left open, locks held, transactions dangling. Fix : (a) emit defers into a per-frame defer-list opcode (`DEFER_PUSH` / `DEFER_POP`) instead of inlining them, OR keep the inline form but maintain a parallel runtime stack tracked at frame entry ; (b) on panic, walk frames bottom-up and run each frame's pending defers before propagating ; (c) mirror in the C-emit (longjmp-based unwind or sentinel-checked epilogue). Same fix unlocks a future `recover` / `rescue` primitive. Cross-ref §3.1 Concurrency (panic propagation across spawned tasks).
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
