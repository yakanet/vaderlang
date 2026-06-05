# Vader — Implementation history

Archive of completed work, moved out of [`TODO.md`](../TODO.md) to keep the live
roadmap focused on open and in-progress items. Everything here is `[x]` done.
The full detail (implementation notes, commit hashes, migration steps) is kept
verbatim as it was tracked; see git history for the commits themselves.

What lives here, in document order:

- **Phase 0** — project bootstrap (complete).
- **Phase 1** — first the fully-completed subsections of the MVP TypeScript
  compiler, then the done items lifted out of Phase 1 subsections that are
  still in progress (their open `[ ]` / `[~]` work + a "Shipped" pointer stay
  in `TODO.md`).
- **Phase 2** — done items lifted out of in-progress self-host subsections.
- **Phase 3** — completed post-MVP items pulled from in-progress subsections.
- **Priority — archived detail** — the long-form write-ups of done "next up"
  items whose one-line summary now lives in `TODO.md`.

The native self-host fixed point was reached 2026-06-05 (the cc-built,
Vader-emitted-C compiler re-emits its own C byte-identically). Phase 1 is the
disposable TS bootstrap; `src/` is slated for removal once the self-host is
frozen (§2.8).

---

## Phase 0 — Project bootstrap

- [x] `bun init` scaffolding, `tsconfig.json` strict mode, `bun test` runner, snapshot driver, CLI entry point, `.gitignore`.

---

## Phase 1 — MVP compiler in TypeScript (completed subsections)

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

**Deferred (most since resolved):**
- Generic monomorphization (now in §1.5).
- Trait dispatch for operator overloading on user types (now done — see §1.13e operator overloading).
- Per-binding type narrowing in `is T as x` patterns (now done — see §1.13e).
- Field-type substitution for generic struct instances.
- Validation of `[T: Trait]` bounds against a concrete substitution at call sites (now done — see §1.18b).
- Struct-level bounds enforcement (now done — see §1.18b).

### 1.7 Bytecode emitter
- [x] Op table (WASM-aligned typed primitives, constants, locals, structured control, calls, GC ops, `type_check`, `ref.cast`), type table (deduped), string pool, function + import + export tables, intrinsic table (stable IDs, append-only), per-op debug info, two-pass emission, short-circuit `and`/`or` lowering, `vader dump --stage=bytecode`, 7 snapshot scenarios.
- [x] Bytecode peephole pass — `local.set N; local.get N → local.tee N`, cmp+not fusion, double-not elimination. Gated `EmitOptions.optimize` (CLI `--no-bytecode-opt`).
- [x] **Slot reuse via live-range coalescing** (landed 2026-05-16, v2). `src/bytecode/slot-coalesce.ts` runs after the peephole pipeline : it computes each slot's `[first_op, last_op]` range from the linearised body, extends ranges through enclosing `loop ... end` ranges to respect back-edge reads, then greedy-colors same-ValType slots that don't overlap. Compacts `fn.locals` and rewrites every `local.get/set/tee` to the new dense slot index. 124 snippet bytecode snapshots regenerated — net **−1682 lines** (−3.6 %) across the corpus. **TS VM, Vader VM, and native** all green ; the previous attempt's Vader-VM mismatch is avoided by running AFTER peephole on the final linear bytecode (no metadata drift). Same-ValType filter prevents bridging a `ref`-typed iter into an `i32` slot ; the loop-range extension fixes the for-in `__iter` / `__step` coalescing bug the first attempt missed.
- [x] First-class function values — `fn.ref`, `call.indirect`, `make_closure` ops + `vader_fn_t` fat pointer runtime.

### 1.13b Self-hosting prerequisites
- [x] Process argv as `main(argv: [string])`.
- [x] Format helpers (`pad_start`, `pad_end`, `is_whitechar`, `to_hex`, `to_bin`).
- [x] `in` / `!in` operators + `Contains($T)` trait.
- [x] `char ↔ u32` and other integer casts (rejects char↔float).
- [x] `std/path` (POSIX `/` only ; Windows deferred).
- [x] `std/regex` ad-hoc helpers + char ordering ops.
- [x] `std/json` — recursive-descent parse + stringify. Returns `JsonValue | JsonError` (trait widening on return now fires, but the union form stays).

### 1.13c Bugs surfaced while building 1.13b — all closed
- [x] u64/i64 literal coercion, `[string]` iteration, char arithmetic, trait widening on return, narrowing-aware unbox inside match arms, multi-file modules dropping all but first, cross-module enum + empty indices, FieldExpr→Enum lowering misdispatch, expression-bodied fns, `null` ValType→C `void`, `parse_int`/`parse_float` C shim mistagging, Range i32-only enforcement (T3001), struct-pattern in union narrowing.

### 1.14 Snapshot test infrastructure
- [x] Single-source-per-test layout in `tests/snippets/{name}/_main.vader` + `{phase}.snapshot` files. Driver runs every pipeline phase. `UPDATE_SNAPSHOTS=1 bun test` for refresh. 80+ snippets covering generics, traits, comptime, error propagation, GC stress, closures, iter combinators.

### 1.17 Enums
Required before self-hosting. All phases wired end-to-end.

- [x] Lexer + parser (`EnumDecl`, `.Variant` dot-shorthand, `EnumVariantPattern` arm, typed-let `name: Type = value`).
- [x] Type-checker (`EnumType`, exhaustiveness, dot-variant bidirectional inference).
- [x] Lowerer + bytecode/VM/C-emit — variants lower to typed integer constants ; no runtime change.
- [x] **Typed enums** — `Day :: enum(u8) { ... }` with optional repr suffix, explicit variant indices `Up = 10` with auto-increment, bounds + dup checks (T3029 / T3030 / T3031).

### 1.18c-bis Function overloading across imports + local fns
- [x] Local fn coexists with same-named import — fn-overloads bucket repopulated after wireImports.

### 1.18c Function overloading by receiver type
- [x] Resolver `fnOverloads` map, typechecker UFCS dispatch rank (`concrete > symMatch > intoMatch > wildcard`), direct-call resolution via `pickDirectCallOverload`, T3032 on ambiguity, stdlib `min`/`max`/`abs` i32+f64 overloads.

### 1.18 Built-in type aliases
- [x] `int → i32`, `long → i64`, `float → f32`, `double → f64`, `byte → u8`. Diagnostics show canonical names.

---

## Phase 1 — completed items from in-progress subsections

Done bullets lifted out of Phase 1 subsections that still carry a few open items (`TODO.md` keeps the open `[ ]` / `[~]` work + a one-line "Shipped" pointer).

### 1.5 Comptime engine + monomorphizer
- [x] Comptime value IR, AST-walking interpreter, sandbox (`@file`, `@env` gated by `--allow-env`), `@comptime` evaluation pass, generic instance registry, minimal monomorphization pass, codes `C4001..C4013`. `vader dump --stage=evaluated-ast`. 5 snapshot scenarios.
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
- [x] **Generic `len(arr)`** (2026-05-16) — `ArrayIterator(T).length` field dropped ; `next()` reads `self.arr.len()` via UFCS. `wrapArrayAsIter` simplified : the `length` slot was the only reason to dedupe the array expression, so the synthetic tmp + hoist are gone too.
- [x] Auto-coerce `T[]` → `Iterator(T)` via blanket `T[] implements[T] Into(Iterator(T))` in `std/core`.

### 1.6 Lowerer
- [x] Dedicated lowered AST. Pattern match → linear if/else chain over `LoweredTypeCheck`. `expr?` → block + try/return. String interpolation → builder intrinsic calls. `defer` → physical duplication at every textual exit. Trait calls → static dispatch via UFCS. No inserted runtime checks. `vader dump --stage=lowered-ast`. 7 snapshot scenarios.
- [x] Lambda lifting / closure conversion via `$Cell_T` heap promotion ; `LoweredMakeClosure` at call sites.
- [x] `RangeExpr` + `T[]` arrays lowered via `Iterator` dispatch ; `for-in` desugars to a pull-loop on `Iterator(T)::next`.

### 1.7b IR text emitter / reader (`--target=ir-text` → `.virt`)
- [x] Line-oriented `.virt` grammar, `writeVir`/`parseVir`, round-trip fixpoint verified by snapshot banner. `vader run program.virt` wired.

### 1.9 C emitter (Iter-ready)
- [x] Runtime C surface in `runtime/c/`, type representation γ (primitives stay primitive, struct/array via typed pointer, union/`any` via `vader_box_t`), full emitter (`src/c_emit/emit.ts`), import shims with `std/io` mapped to runtime fns, `vader build --target=native [--out=<out>]`, parity tests against the VM snapshot.
- [x] `--release` flag — flips `cc` from `-O0 -ggdb` to `-O3 -DNDEBUG` + best-effort `strip`.
- [x] Unbox struct field read after `is StructTy` match.
- [x] `--cc=<path>` flag + `CC` env var ; auto-`.exe` on mingw32 triples.
- [x] Windows cross-compile via mingw-w64 + Wine (POSIX spawn bracketed by `#ifdef _WIN32` ; Windows branch uses `CreateProcess` + pipes). Still deferred : `tests/native.test.ts` `WINE=1` mode, Unicode (`CreateProcessW`), clang/cl autodetection.
- [x] `#line` directives for gdb/lldb (2026-05-16) — debug builds thread `#line N "<file>"` before each op whose `DebugPos` shifts ; `--release` skips them. `cStringLit` handles path escaping ; the per-fn file string is cached across ops.
- [x] Stable ABI for `@extern` user imports (landed 2026-05-16). C-emit now emits real `extern <ret> <name>(<params>);` declarations + forwarding shims that call the foreign symbol ; the previous `vader_trap("unbound import: ...")` default arm is reserved for compiler-internal mismatches. Decorator accepts 0/1/2 string args (last = C symbol, 1st of 2 = future WASM module hint). Signature whitelist : primitives + `string` (marshalled via `vader_string_to_cstr` → `const char*` + `vader_cstr_free`). T3050/T3051 typecheck guards. CLI `--ldflags="..."` passes raw linker flags. Snippet `extern_native_basic` calls a helper.c + libc strlen end-to-end ; VM target skips (no host-fn registry for user externs).

### 1.12 CLI
- [x] `vader run` + `vader build` single-file (`src/cli/commands/{run,build}.ts` ; self-host `vader/cli/main.vader`).
- [x] `vader build --target=ir` — emits binary `.vir` (`VADR`) / text `.virt`.
- [x] **`vader test [path]`** (2026-05-12) — recursive `.vader` discovery, runs `@test` fns via VM, per-file group output, exit 0/1/2 on pass/fail/no-tests.
- [x] `vader dump --stage=<ast|typed-ast|bytecode|c>` (+ resolved-ast / evaluated-ast / lowered-ast / dced-ast / cfg).
- [x] `--allow-env` flag for comptime sandbox (`src/cli/options.ts`).

### 1.13d Stdlib consolidation
- [x] hex/base helpers centralised in `std/numbers`.
- [x] char-predicate duplicates in `std/json` removed.

### 1.13e Language ergonomics surfaced by self-host port
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
- [x] Transitive monomorphisation through nested generic calls — verified working.
- [x] **Byte literal syntax `b'X'`** (commit `dc457047`) — Rust-style `b'X'` evaluating to `u8` at parse time, both lexers + escape support. Triple-cast `b == u8(u32('{'))` swept from self-host call sites ; `vader/fmt/comments.vader` is the primary user.
- [x] Type-alias declaration order relaxed — verified free order.
- [x] Namespace-imported aliases unify with direct imports — `equalsType` falls back to comparing `definedAt` source position when symbol ids diverge. Deeper loader consolidation still tracked as a follow-up.
- [x] `MatchResult` workaround cleanup — `match_kind` returns `Token | null` directly ; ~60 call sites simplified.
- [x] Self-host lexer u64 overflow — promoted unsigned magnitude carrier to `u64` ; new `parse_uint_in_base`.
- [x] Flow-narrowing on `if x is T` (Phase A, ident scrutinee) — recognises `x is T`, `x == null`, `x != null` + leading `!`. Phase B (FieldExpr LHS receiver narrowing) deferred — needs path-based keying + immutability check.
- [x] `if x is T as binding { ... }` — mirrors match-arm shape ; binding scoped to then-block.
- [x] Drop `fn` keyword on lambda expressions — new form `(params) -> body` or `x -> body`. Decls still use `name :: fn(...) -> R { ... }`.
- [x] **`for <range> { ... }` shorthand** — `for <expr> { body }` where `<expr>` is a `RangeExpr` desugars to `for _ in <expr> { body }` on both parsers (`src/parser/passes/stmt.ts:358`, mirrored in `vader/parser/parser.vader`), synthetic zero-width span so the formatter still distinguishes user-written `_ in`.

### 1.16 Examples
- [x] `hello`, `fibonacci`, `fizzbuzz`, `rule110`, `primes` (+ `brainfuck` — see §3.9 — `mandelbrot`, `mowitnow`).

### 1.18b Generics & primitive type ergonomics
- [x] `usize` + `isize` first-class.
- [x] Migrated `arr.len()`, `ArrayIterator.length/cursor`, `std/iter` signatures to `usize`.
- [x] `Range[T]` impl deduplication via bounded `[T: Comparable & Step] Range[T] implements Iterator[T]` ; `Step` trait carries per-primitive successor.
- [x] Migrated `std/string` to `usize` indices/lengths.
- [x] Generic `Range :: struct[T]` — every integer width + `char` ships `Contains` + `Iterator` impls.
- [x] First-class function values.
- [x] `void!` runtime/type mismatch — parser desugars to `null | Error`.
- [x] Enforce struct-level bounds at instantiation site (T3006).
- [x] Auto-inherit struct bounds onto methods.

### 1.18d Common-field access on discriminated unions
- [x] Typecheck + lowerer + same-offset shortcut (single struct.get when every variant stores the field at the same index with the same type). Self-host `expr_span` / `stmt_span` collapsed from 25-arm matches to one-liners.
- [x] Peephole spread bug — replaced `body.push(...out)` with explicit loop to avoid RangeError on > 16k spread args.
- [x] **Divergent-type policy** — variants with differently-typed same-named field return `unionOf(...)` ; caller narrows.

---

## Phase 2 — completed items from in-progress subsections

### 2.0 Vader CLI minimal
- [x] `vader/cli/main.vader` argv parsing + stage dispatch — `lexer` / `ast` / `resolved-ast` wired ; further stages return "not yet implemented".
- [x] **Snapshot parity rig under `tests/parity/`** (2026-05-16) — `tests/parity.test.ts` + `tests/cli-bin.ts` compile the Vader CLI to `build/vader` and diff `lexer` + `ast` stages against the TS-generated snapshots for every snippet that ships one (~240/245). Skip set empty ; previous CJK outliers (`for_in_into_iter`, `string_bytes`) now pass byte-for-byte.
- [x] **Build the CLI native** (2026-05-16) — `tests/cli-bin.ts:ensureCliBuilt()` invokes `bun src/index.ts build vader/cli/main.vader --target=native --release` once per session and caches `build/vader`.

### 2.1 Port the parser to Vader
- [x] **Lexer** (`vader/lexer/`) — Token kinds + keyword/suffix tables + driver state + whitespace + nested block comments + identifiers + numeric literals (bases + suffixes + `_` separators) + char + string literals (plain/raw/triple + interpolation) + operators + newline emission + shebang + UTF-8 BOM + structured diagnostics.
- [x] **Diagnostics** — `codes.vader` + `diagnostic.vader`.
- [x] **Lexer parity** (2026-05-16) — covered by the parity rig (§2.0). Native CLI built once via `tests/cli-bin.ts`, then `tests/parity.test.ts` diffs `--stage=lexer` against `lexer.snapshot` for every snippet.
- [x] **Parser** (`vader/parser/`) — AST representation (every node ported ; `type` keyword conflict → field renamed `ty`, dumper still emits `"type"` JSON key for parity) ; `ParserCode` enum + `parser_info()` lookup (P1001..P1020) ; ~2200-line recursive-descent + Pratt body ; AST → JSON dumper byte-for-byte with `tests/snapshot.ts:formatProgram` ; CLI `vader dump --stage=ast` ; byte-for-byte parity over every snippet shipping a `parser.snapshot` (~240/245).
- [x] **Bugs uncovered while porting — all closed** : `as <name>` match-arm binding, primitive-only union dispatch, union-of-enums match, `match X.field { is Y as t -> ... }`, `if !bool_var`, enum_basic family, trait/impl-heavy snippets, dump diff cleanups.

---

## Phase 3 — completed items

Done items lifted out of otherwise-in-progress Phase 3 subsections (`TODO.md` keeps the open `[ ]` / `[~]` work), plus the completed §3.9.

### 3.4 Stdlib expansion
- [x] `std/regex` — Thompson NFA via Cox's VM ; literals + char classes + shorthand `\d`/`\w`/`\s` + quantifiers `* + ? {n,m}` + alternation + capture groups + anchors `^$`. Pure Vader. ~750 LoC. Hors-scope : non-greedy, named groups, backrefs, lookahead/lookbehind, Unicode classes.
- [x] `std/time` — `Instant` / `Monotonic` / `Duration` with ns precision ; ISO 8601 round-trip. 2 host intrinsics (wired to `clock_gettime` natively, JS clocks on TS VM, WASI-ready).
- [x] `std/random` — xoroshiro128++, deterministic seeds, full range/shuffle surface. Pure Vader.
- [x] `std/crypto` — SHA-256 (RFC 6234), MD5 (RFC 1321). Hex output. Pure Vader.
- [x] `std/base64` — RFC 4648 standard alphabet. URL-safe variant deferred (drop-in alphabet swap).

### 3.5 Performance
- [x] **Generational GC** — two-gen Cheney with card table (`VADER_CARD_BYTES = 512`), age tenuring (`VADER_TENURE_AGE`), knobs `VADER_GC_YOUNG_BYTES` / `VADER_GC_OLD_BYTES`.
- [x] **`vader_array_push` array-doubling under double-GC pressure** — fixed by rooting `a` + `v` in a `vader_box_t` across `vader_array_buf_alloc`.
- [x] **GC robustness under high parse-time string-allocation pressure** — fixed missing write barriers in Cheney scan (old → young edges), card-table preserving across major collects, raw string fields enumerated in `vader_type_info_t`, `vader_array_push`'s arg precise-rooted, `vader_builder_t` chained through `g_builder_head`. Multi-hop forward resolution in `vader_array_resolve`. `VADER_GC_STRESS=1` env var turns intermittent rooting bugs into deterministic failures.
- [x] Whole-program DCE — user fns reachable from `main` + `@export` + `@test` + `@extern` ; libraries (no `main`) keep every user decl.
- [x] `match enum` cascade → `switch` C (delivered via the static lookup table family).
- [x] Static lookup table for `match enum -> StructLit constant` — recognises 4 arm-body shapes (struct table, primitive table, block-form with propagation chain, sparse + wildcard cases). Self-host snippet: 7202 → 6353 lines.
- [x] Eliminate single-use primitive temp locals via bytecode peephole Rule 6.
- [x] **Hash-cons `Type` values + re-key registries by reference identity** (Phase A + B step 1 landed 2026-05-11 ; B step 2 landed 2026-05-15). All 37 inline `{ kind: "Struct" | "Trait" | "Fn" | … }` Type literals across `src/typecheck/passes/*.ts`, `src/lower/passes/*.ts`, `src/bytecode/emit.ts`, `src/lower/lower.ts`, `src/typecheck/check.ts` flipped to `mkStruct` / `mkTrait` / `mkFn` / `mkTuple` / `mkUnion` / `mkTypeParam` / `mkEnum`. Symbol-anchored caches (`structCache` / `traitCache` / `typeParamCache` / `enumCache`) switched to `WeakMap<Symbol, …>` along the way — `Map<sym.id, …>` was aliasing entries across compile invocations because resolver-instance Symbol ids restart at 1.
- [x] Iterator-chain fusion at the lowerer — `for x in (MapIterator { source: FilterIterator { source: Range, pred: F }, f: G }) { body }` emits a single counter loop with inlined predicates. Chain must be inline at the `for` site ; variable-bound chains still hit the slow path.
- [x] Inline representation for small tagged unions (c-emit only) — empty payload or single-primitive-field structs fit in `vader_box_t` ; pre-scan of `struct.set` op type indices gates against MUTABLE struct corruption.
- [x] **Inline `MutableMap` / `MutableSet` iter at the for-in site** (landed 2026-05-16). `for entry in m` / `for v in s` over a `MutableMap(K, V)` / `MutableSet(T)` now lowers to a flat bucket-walk + chain-traversal loop instead of going through `into()` + `MapIterator.next()`. Skips the `MapIterator(K, V)` allocation, the per-iter call, and the per-iter `Yield(...)` boxing — the body branch directly casts the chain cursor and runs user code. Implementation : new `tryLowerForInMapSetIterInline` fast path in `src/lower/passes/for-in.ts` keyed on the into-coercion's source struct matching `std/collections::MutableMap` / `MutableSet`. **Bench : map_iter vader-native 22.6 ms → 9.7 ms (-57 %)** ; Vader-vs-Go gap closed from 2.8 × down to 1.12 ×. Snippets `map_set_iter` and `for_in_into_iter` saw their bytecode/lower/cfg snapshots regenerated (smaller — `MapIterator.into` / `SetIterator.into` are now dead-code-eliminated). Open : generalise to user-defined `Iterator` impls (today the inline only fires for the two known stdlib structs).

### 3.7 Tooling
- [x] GitHub Actions pipeline — `bun run typecheck` + `bun test` + cross-compile four archives via `bun run dist:all` ; uploaded as workflow artifact.

### 3.8 Language ergonomics
- [x] UFCS on union receivers.
- [x] Type-alias unions in cross-module `Alias[]` array slots — added type-aliases phase in `checkProject`.
- [x] **Reconsider the `string` model : codepoint-first vs byte-first** (2026-05-24) — A7 landed the user-facing flip. `s[i]` and `s[r]` index by codepoint ; the byte-cursor family is namespaced (`byte_at`, `byte_decode_at`, `byte_slice`, `byte_len`). `bytes()` returns a `u8[]` (random-access + iterable). `count_chars` renamed to `len`. The fat `(byte_len, codepoint_len)` representation is deliberately NOT shipped — codepoint count is computed on demand via `len()` ; the model stays `(ptr, byte_len)` with codepoint semantics on the index surface. See `docs/ARRAY_STRING_VIEW_DESIGN.md`.
- [x] Array slicing `arr[r]` — `arr[lo..<hi]` / `arr[lo..=hi]` / any `arr[Range[<int>]]` returns a fresh `T[]`. Dispatch on index type, not RangeExpr AST kind.
- [x] **Non-owning slice / span views** (2026-05-24) — A7 landed array view aliasing : `arr[r]` returns a zero-copy view `(elements, offset, length)` sharing the parent buffer, with detach-on-push for mutation safety. `string[r]` (codepoint-indexed) currently still allocates a fresh string via `vader_string_slice_codepoints` ; a zero-copy substring view is a planned follow-up (UTF-8 bookkeeping makes it less trivial than the array case). `s.bytes()` is also still O(n) copy ; a `u8[]` view sharing the UTF-8 buffer is the natural next step. See `docs/ARRAY_STRING_VIEW_DESIGN.md`.
- [x] Literal-value patterns in `match` — `'a'`, `42`, `true`, `"ok"`, `null` ; lowers as `LoweredBinary { op: "eq" }`. `examples/brainfuck.vader` first user. Known parser quirk : `-N` literal pattern on a fresh line is consumed as `prev - N` (workaround : indent the body). Or-patterns + range-patterns still deferred.
- [x] Allow `int_type(enum_value)` cast for `enum(IntT)` types (2026-05-15) — `inferTypeConstructorCall` accepts any numeric / char target against an enum source ; lowers as `repr → target` cast op (same machinery as `i32(u8_value)`). Mirrors Rust `as` / Zig `@intFromEnum`. C-emit `emitConvert` / `coerceExpr` now double-cast `(to)(from) v` so widening a u32-on-the-stack to u64 zero-extends correctly.
- [x] Implicit `void` return — already worked ; added `void` as reserved ident (R2019).
- [x] **Auto-`.iter()` in `for-in` via `Into(Iterator(T))`** (2026-05-15) — no new trait, `Iterable(T)` would be structurally identical to `Into(Iterator(T))` which already exists. `checkForStmt` now calls `tryInto(iter, Iterator(elementVar))` when the iter is neither `Iterator`/`Array`/`Range` nor has a direct `Iterator` impl ; the existing intoCoercions side-table flows through `lowerExpr` → `wrapAsInto`, producing an `Iterator(T)`-typed value that `lowerForIn`'s existing trait-typed branch dispatches via vtable. `MutableMap`, `MutableSet`, and `string` got the matching `Into(Iterator(...))` impls in stdlib (string → codepoint default ; `bytes()` stays opt-in). Snippet : `tests/snippets/for_in_into_iter/` covers array / map / set / UTF-8 string.
- [x] **Trait-object boxing + dynamic dispatch for `Iterator(T)` (and other traits)** (initial 2026-05-08, finalised 2026-05-15). Vtable IR wired through bytecode/VM/C-emit. UFCS receiver `Into`-coerce was the missing piece : `arr.fn()` against `fn[T](it: Iterator(T), ...)` typechecked via the trait-widening rank but lowered without recording the `T[] → Iterator(T)` coerce, so the runtime saw a raw array tag in the vtable. `inferGenericUfcsCall` now records `tryInto(receiver, expected-first-param)` post-unification. `tests/snippets/trait_box_range_iter/` covers `count(0..<5)` + `count([10, 20, 30])` + `invoke(Hello {})` + `twice(7)` — all green.
- [x] Operator overloading via trait dispatch — `+`/`-`/`*`/`/`/`%` via `Add`/`Sub`/`Mul`/`Div`/`Rem`, `==`/`!=` via `Eq`, `<`/`<=`/`>`/`>=` via `Ord` (compare ≷ 0), `a[i]` via `Index`, `a[i] = v` via `IndexSet`, `in`/`!in` via `Contains`. Compound assigns desugar at parse time.
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

---

## Priority — archived detail

Long-form write-ups of completed "next up" items. Their one-line summary stays in
`TODO.md`.

### Remove the `T!` error-union sugar (done 2026-06-01)
Dropped the postfix-`!` shorthand from both parsers (`src/parser/passes/{type,expr}.ts` + `vader/parser/parser.vader`) — a stray `T!` is now a parse error on both frontends (identical P1003); removed the formatter's `T!` recovery. Consolidated the three duplicate `ParseError` structs into one in `std/string` (numbers + semver import it). Pure-Vader fallible fns → concrete error unions (`T | <ConcreteError>`) with `is <ConcreteError>` matches, so the self-host VM dispatches by struct type. Host intrinsics (`std/io` ×5, `std/string.parse_float`) keep the existential `T | Error` — their failure is a generic host error value the VM already matches via `is Error`. SPEC §"Error unions" replaces the `!T` section.

### `string.bytes()` zero-copy `const u8[]` view + byte-API collapse (done 2026-06-01)
See git history `2318161f..6fc94052`. `bytes()` returns a native zero-copy borrowed view (owner atom id packed in `capacity` + a header flag, GC marks the atom ; VM copies), `byte_at`/`byte_slice` removed, `byte_len` internal, `bytes()` / `as_string()` is the whole byte surface ; all stdlib + compiler + lexer/parser/json/regex/base64 consumers migrated.

### Module system redesign (landed 2026-05-22, Vader-side strict resolver follow-up 2026-05-23)
Explicit `module "..."` keyword on every `.vader` file ; module identity decoupled from filesystem layout. Strict resolver on both sides (TS + Vader self-host) replaces the legacy `promoteToFolderModule` heuristic with an up-front `discoverModules` scan + name-indexed import lookup. Vader-side uses a header-only byte-scanner (`parse_module_header`) so discover memory stays bounded for the ~170 .vader files under stdlib + vader/. Stdlib reorganised into per-module folders ; vader/types + vader/resolver/symbol extracted to break the typecheck↔resolver cycle that surfaced at the strict flip. Design log + 45 decisions in [`docs/MODULE_SYSTEM.md`](./MODULE_SYSTEM.md). **Deferred** : (a) parser `module "..."` strict-presence diagnostic (resolver R2020 already catches missing decls at scan time), (b) TS-vs-Vader byte-diff in `parity-broad.test.ts` (smoke check stays ; remaining divergences trace to the Vader self-host typechecker populating fewer expression types than TS — separate chantier).

### Cross-file duplicate-decl R2026 activated (closed 2026-05-26, path (a) chosen)
`vader/resolver/loader.vader::merge_collected` now fires R2026 on cross-file non-fn duplicates ; fn-vs-fn collisions go through `fn_overloads` as before, and import-binding pairs are exempt (importing the same name in sibling files is normal usage — file-scoped imports per §1.5 stays a separate chantier). The 3 actual latent collisions surfaced (the 7 names in the original entry included 4 test-fixture matches that were inside `"""..."""` string blocks, not real top-level decls) were consolidated by removing the duplicate definition rather than renaming — same-module sibling files now share the canonical decl :
- `vader/vm/{ScopeEntry, PendingBranch}` → kept in `builder.vader`, parser.vader uses them through cross-file visibility (`parser.vader:25-37` replaced by a comment).
- `vader/lower/CellInit` + `cell_wrap_init` → kept in `helpers.vader` (exported), `lower_expr.vader:2282` switched to call `lower_cell_init`.
- **Still open** : import-binding scoping (§1.5 says file-scoped, today's `merge_collected` lumps them per-module). Deferred — current behaviour matches what every caller relies on, and `bind_import` already enforces per-file no-dup.

### Resolver port follow-ups (closed 2026-05-26, parity-diagnostics 1181 pass / 0 skip / 0 fail)
Closed items :
- **R2006 at resolver-stage** [x] : moved from `vader/typecheck/expr.vader` to `body.vader::walk_expr`. Core symbols seeded into the root scope via `resolve_module_with_collected_dp_seeded` + `build_core_seed` (new `vader/resolver/core_seed.vader`). Decorator-position recovery now uses `NullLitExpr` placeholder so misplaced `@foo` in expression context doesn't cascade R2006 on the synthetic ident.
- **R2018 orphan rule** [x] : new project-level pre-resolve pass (`vader/resolver/prescan.vader::run_orphan_rule_check_for_module`) runs after `wire_imports`, mirrors `src/resolver/resolve.ts:230-244`. Wired in both CLI's `resolve_loaded_project` and typecheck `orchestrate.vader`.
- **R2009 (trait_name resolves to non-trait)** [x] : `materialize_all_sams_pre_resolve` now discriminates "truly unresolved" (R2007) from "found but wrong kind" (R2009) via the new `find_non_trait_decl_kind` helper. Pragmatic — didn't require exposing `kind` on `ImportedSymbol`.
- **T3050 / T3051** [x] : `validate_extern` ported to `vader/typecheck/decl.vader`. Validates body-absence + decorator arg shape + ABI types + duplicate C symbol. `extern_symbols` table added to `TypedProgram`.
- **T3015 break-outside-loop** [x] : already correctly emitted at the typechecker. Parity was held back by missing W0002 ; now in sync.
- **C-codes renumbering** [x] : `vader/diagnostics/codes.vader::ComptimeCode` renamed + reordered to match TS exactly (C4001 CannotEvaluate, C4002 EvaluationPanic, …, C4015 AssertFailed). All 5 emit sites in `vader/comptime/` migrated to the new variant names.
- **W0002 unreachable-code** [x] : `check_block` (stmt.vader) now tracks `first_unreachable_span` and warns once per block ; mirrors TS's surface. `stmt_span` helper added.
- **L5xxx → M5xxx renaming** [x] : `LowerCode` renamed (M-prefix avoids ambiguity with L0xxx lexer). Mirror added to TS `src/diagnostics/codes.ts::MIR_LOWER` so the registries stay aligned ; emit sites in `src/lower/passes/` + `vader/lower/` to be filled as the lowerer surfaces actual diagnostics.
- **Parser P1029 / P1030** [x] : redirected — TS already defines them but currently emits the lookalike R2020 / R2022 at resolver-stage. Vader follows the same convention ; no separate parser-stage check needed for now.
- **`string[r]` codepoint slice** [x] : `expr_index.vader` now accepts `Range` indices on `string` and returns `string` (slice).

Lot 4c closed items (2026-05-26) :
- **T3013 Enum + non-Union scrutinee** [x] : `match_expr.vader::infer_match` now tracks `has_wildcard` + `covered_enum_variants`, lifts placeholder enums via `lift_enum_placeholder`, and emits T3013 for Union (missing variant), Enum (missing variant by name), and non-Union/non-Enum/non-Unresolved (wildcard arm required). Irrefutable tuple patterns (`[n, s]`) count as wildcards. Snippet rewritten.
- **L0001 single emit** [x] : lexer now consumes the full UTF-8 codepoint (1..4 bytes via `utf8_lead_byte_len`) before emitting L0001, so `§` fires once instead of twice.
- **M5001 lower emit-site** [x] : `vader/lower/lower_for_in.vader` emits M5001 (`IteratorImplMissing`) when the receiver is a primitive without a wrapping Iterator path ; TS side switched from B5001 to M5001 in `src/lower/passes/for-in.ts`. `lower_project` now drains `project_ctx.diags` into the caller's sink.
- **non_exported_violation** [x] : aligned (TS and Vader both emit R2008 + R2006 at matching spans).
- **sam_impl_bad cascade** [x] : `i32 implements TwoFns -> 0` on a multi-method trait emits R2016 + T3036 only. `check_short_impl_arity` returns whether the check passed AND marks failed sam_synthetic members `materialized=true` ; `materialize_sam_members` keeps the SAM rename even on multi-method traits so the T3036 loop credits the named slot ; `walk_impl_decl` skips members already marked materialized so their body never resolves `self`.
- **Comptime fn-body interpreter** [x] : `vader/comptime/eval_call.vader` evaluates `simple_fn(args)` patterns. The resolver body-walker now persists param Symbols in `idents[span_key(p.span)] = sym` so eval_call can recover the Symbol.id for binding without re-walking the body. String interpolation segments (`"foo ${expr}"`) also recurse through the dispatcher via a new `interp_value` Display-style renderer.

Closed in the final pass :
- **Comptime SeqLitExpr eval** [x] : new `vader/comptime/eval_seq_lit.vader` discriminates tuple vs array via `typed.expr_types[expr.id]` and materialises `StructValue` with synthetic `_0`, `_1`, … fields for tuples (mirrors the TS VM shape). Resolves tuple_comptime.
- **Two-pass expr-bodied settle** [x] : `settle_external_expr_bodied_returns` now runs two passes so `lexer_error(...) = new_diagnostic(...)` chains settle to the concrete return type at the second pass. Resolves selfhost_lexer_basic / iter_defaults parity divergences.

`KNOWN_DIVERGENCES` is now empty. Full suite : 5006 pass / 6 skip / 0 fail. Parity-diagnostics : 1181 pass / 0 skip / 0 fail.

### LSP semantic classification via the AST + body-walking resolver (landed 2026-05-16)
`vader/resolver/body.vader` walks fn bodies / blocks / lambdas / for-loops / if-is-as bindings / match patterns with a scope stack, producing a span-keyed `IdentExpr → Symbol` map (`ResolvedFile.idents`). Symbols carry their kind (`Fn`, `Struct`, `Param`, `Local`, `Binding`, `TypeParam`, …). `vader/lsp/ast_tokens.vader` runs the positional Phase 1 walker, then a Phase 2 `refine_via_resolver` pass overrides every Phase-1 token whose span matches a resolved ident with the symbol-kind-derived `TokenType`. In-body `x` (param) now paints `Parameter`, `val` (local) paints `Variable`, type names paint `Type`. The resolver lives in `vader/resolver/` so the eventual self-host typechecker (§2.6) reuses the same walker — no duplication between LSP and compiler.

### Other completed "Priority" one-liners
- [x] **Single-binary distribution** (2026-05-10) — `bun build --compile` + per-OS tarballs (`vader-<os>-<arch>.tar.gz`) bundling the binary with `stdlib/` and `runtime/c/` sidecars. `scripts/dist.ts` + `dist:*` npm scripts.
- [x] **Reference benchmark** (2026-05-14) — `bench/` with mandelbrot + primes in Vader / TS / Go ; `bun run bench` compares against `bench/baseline.json` (10 % regression budget). See [`bench/README.md`](../bench/README.md).
- [x] **Adopt `s[i]` over `s.char_at(i)`** (2026-05-11) — `char_at` export dropped ; `.byte_at(i)` kept in hot byte-level scanners.
- [x] **SSA round-trip removed** (2026-05-14) — measurement showed zero precision gain over flat-CFG escape analysis ; 335 LoC of SSA + dominance-frontier code deleted.
- [x] **Loop-carried-dependency check** (2026-05-14) — replaced over-conservative `inLoop` escape filter ; +95 stack-promotions on the self-host.
- [x] **Monoliths broken up** — incremental ; largest `src/` file is now `lower/passes/expr.ts` at 983 lines, below the 1k-line threshold.
