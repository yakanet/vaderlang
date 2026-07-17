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

---

## Archived from TODO.md — 2026-07-17 sweep

Done (`[x]`) items lifted verbatim out of `TODO.md` to keep the live
roadmap to open/in-progress work only. Grouped by their original
`TODO.md` section; see git history for the commits themselves.

### Priority — next up

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
- [x] **Generic arithmetic operator traits (`Add` / `Sub` / `Mul` / `Div` / `Rem`) — DONE 2026-06-24.** Generalised to `Add :: trait<Rhs = Self, Out = Self>` (+ Sub/Mul/Div/Rem) in `std/core` (`core.vader:100-108`) — heterogeneous operators are now sound and first-class (operator RHS type-check → T3017); the `= Self` defaults keep `i32 implements Add` and bounds `<T: Add>` working verbatim. P1 default type params (`4b11a0d1`); P2 generalise the traits (`c4b03d33`); P3 RHS check (`8000ee60`); P4 migrate std/time + std/path to operators (`85019384`). See [`.claude/plans/generic-arith-operator-traits.md`](.claude/plans/generic-arith-operator-traits.md).
- [x] **W0004 ambiguous-loop-jump — RESOLVED 2026-07-13 by retiring W0004.** The nudge is gone: a bare `break`/`continue` targets the innermost loop (blessed), non-innermost jumps name their target with `break <var>` / `continue <var>` (by iteration variable) or a label (varless loops), and reader clarity is served by the LSP go-to-loop rather than a lint. This also dissolved the "two loop-nesting counters" cleanup: the walk-global `TypedProgram.loop_depth` (W0004's only reader) was deleted; `FnContext.loop_depth` (T3015) stays, and the walk-global need is now `TypedProgram.loop_stack` (which also resolves the var/label jump targets). See [`.claude/plans/loop-jump-by-variable.md`](.claude/plans/loop-jump-by-variable.md).
- [x] **Resolver lazy index — DONE** (`a1935811`). Implemented in `vader/resolver/lazy.vader` (`resolve_lazy` / `include_paths` / `seed_entry` / `misplaced_module_at`) — on-demand, import-driven module resolution + include-paths, replacing the up-front full scan. The 2026-05-26 "attempted + reverted" blocker (spurious R2001 because `diagnose_import_path` fired before lazy expansion) was solved by the lazy-resolve rework.
- [x] **LSP : `@no_return` divergence doesn't narrow a union after a guard** (added 2026-06-16). The LSP reports a false **T3001** on code like `if op_opt == null { panic(...) } ; push_emit(ctx, op_opt, …)` (seen in `vader/midir/emit.vader`'s `InstrIntrinsic` arm) — at the use site it still types `op_opt` as `Op | null` instead of narrowing to `Op`. The **native full-project build narrows correctly** (the file compiles clean), so this is LSP-only. Likely cause : the LSP analyses the file without full cross-module info, so `panic`'s `@no_return` decorator (declared in `std/abort`) isn't resolved → the guard branch isn't seen as diverging (→ `never`) → no flow-narrowing of the union's complement. Fix : make the LSP resolve cross-module `@no_return` (or eagerly load `std/abort`'s decorator metadata) so divergence-narrowing matches the compiler. Related shipped work : "divergence → `never`" + `T | null` flow-narrowing (§1.13e).
- [x] **LSP : member completion missed free-fn UFCS methods** (fixed 2026-06-20). On `f.mint()` where `f: NodeIdFactory`, completion offered only the field `next`, not the method `mint` — because `mint :: fn(self: NodeIdFactory)` is a **free function** (UFCS), not an `impl`-block method, and `member_completion` only collected struct fields + `impls.all` members. Fix: new `vader/typecheck::ufcs_methods_for(target_ty, typed)` enumerates every free fn whose first param fits the receiver (reusing `try_curry_receiver`, the same match `try_free_fn_ufcs_with_first` uses for a single call), and `member_completion` now appends those. Test: `lsp.test.ts` member-completion fixture gained a free-fn `magnitude :: fn(self: Point)` asserted present.
- [x] **Typer : `lookup_fn_symbol_by_span` matched spans file-blind** (found + fixed 2026-06-20 while landing T3053). `vader/typecheck/decl.vader` matched a decl to its overload Symbol by `(line, column)` only, ignoring `file` — two fns at the same `(line, col)` in different sibling files of one module collided → the second's `decl_types` entry was never written (left `?`), so a *legitimate* cross-file overload set sharing `(line, col)` mistyped one member and resolved calls to the wrong overload. Fix: also compare `sp.start.file == decl.name_span.start.file`. Repro that errored before / runs after: two `take` overloads (`fn(i32)` / `fn(string)`) at the same line:col in sibling files → `take(2)` now picks the i32 version. Suite 2281/0.
- [x] **Type-ascribed const bindings (const arrays) — DONE** (`b93f094f`, Odin-style typed const). The form ships and is in active use: `NAME: Type: value` — `MASK_U32: u32: 0xFFFF_FFFF`, `SHA256_K: u32[]: [...]` (`std/crypto`), the `DOUBLE_POW5_*` tables (`std/core/dtoa_tables.vader`). NB: the spelling is `: Type:` (a single colon before the value), not the `: Type ::` this item originally wrote — same capability (declare + pin the element type of a const array in one statement).
- [x] **Target ABI — shrink the per-target runtime** (done + squash-merged to `main` `1536a2a3`, 2026-06-16). Whole chantier S0–S7 + .NET-erasure CORE landed : memory opcodes, StringBuilder/Array/String/hash flipped onto them, the `Builder*` op family + `vader_builder_*` runtime retired (S4), Array accessors open-coded in c-emit (S5 Solution A), string-hash atom cache (phase 4). Verified on-tree 2026-06-19 : no `Builder*` variants, no `vader_builder_*`, seed clean. See git history + `docs/TARGET_ABI.md`.
- [x] **Typer accepts an enum literal from the wrong enum** (not reproducible / effectively closed ; re-verified 2026-06-19). The current self-hosted typer rejects a wrong-enum literal with **T3027** in both call-argument and typed-slot position — including the exact reported shape (`.OrphanImplForbidden` ∈ `ResolverCode` passed where `TypecheckCode` is expected). The original 2026-06-17 report (no diagnostic, silent trap) could not be reproduced on HEAD then or now ; a regression guard (`tests/diag_corpus/typecheck/t3027_wrong_enum_variant`) locks the behavior. The only remaining silent-accept path is the legitimate `UnionType` case in `infer_dot_variant` (first member enum carrying the variant). Reopen only with a concrete repro that emits no diagnostic.
- [x] **`string.len()` c-emit codegen bug** (fixed via the core-string-utf8 reorg, verified 2026-06-19). Root cause was the hardcoded `primitive_method_type` typer table promising string methods the lowerer couldn't honor (free-fn UFCS missed the unloaded `std/string`), so `s.len()` fell through to a degenerate `field_get`/`call_indirect` → invalid `(vader_fn_t*) 0.payload.obj` C. The reorg removed `primitive_method_type` and moved `len` into `std/core` ; `total + s.len()` + `"${s.len()}"` now compile & run (`8 and 5`). See git history (`core-string-utf8-reorg`).
- [x] **Comma-separated enum-literal match patterns** — RESOLVED 2026-06-25 (`4d097749`) by landing **pipe** or-patterns instead. `.A | .B | .C -> …` (new `OrPattern` AST node) is the canonical multi-variant form; the broken comma form (which never actually parsed on stage2) is gone and CLAUDE.md §6 / SPEC now show the pipe form. Also covers `1 | 2` literals and `is A | B` type tests, and fixed the latent `is <union>` native-vs-VM backend divergence (c_emit `emit_type_check` was not union-aware). Snippet `tests/snippets/or_pattern`. Original report below.
  - **Comma-separated enum-literal match patterns miscompile** (added 2026-06-17, found while landing T3052). A match arm with comma-separated enum literals — `match k { .A, .B, .C -> true ; _ -> false }` — panics at codegen : `midir/emit: no field `B` on `null` … a method reference on a primitive isn't a first-class value`. Only the **first** literal in the comma group (`.A`) gets the scrutinee's enum-type context ; the rest (`.B`, `.C`) are left context-free, resolve to a null-typed enum-literal, and the emitter then treats `.B` as a field/method reference on `null`. Reproduces on the current self-hosted compiler (stage2), both expression-bodied (`fn(k) = match k {…}`) and statement-bodied, with and without a `-> bool` annotation. Workaround in use everywhere : one literal per arm (`.A -> true` / `.B -> true` / …) — a tree-wide grep finds **zero** comma-separated enum patterns, i.e. the codebase already avoids this. **`CLAUDE.md` §6 documents the comma form as canonical** (`suppresses_newline_after :: fn(k) = match k { .Plus, .Minus, .Star -> true ; _ -> false }`), so either the bug is fixed or the style guide is corrected. `Pattern` has no or-pattern variant and `MatchArm.pattern` is singular (`vader/parser/ast.vader:562`), so the comma form is parser-desugared or mis-parsed — start the investigation there + in the typer's pattern-vs-scrutinee type propagation (`vader/typecheck/match_expr.vader`). Same "method reference on a primitive" family as the `s.chars` / `string.len()` errors (a lost-type-context enum/method literal reaching the emitter). Add a `tests/snippets/_diag_*` repro once fixed.
- [x] **Leading `&&` / `||` line-continuation now parsed** (fixed 2026-06-22). A boolean condition broken across lines with the operator at the **start** of the continuation line (`if a == 1\n    && b == 2\n    && c == 3 {`) used to fail — P1002 `expected {` + P1003 `expected an expression: got &&` (and on old binaries the malformed AST error-recovered into the `midir/emit: method reference on a primitive` codegen panic family). Root: the bug was in the **lexer**, not the parser — `vader/lexer/lexer.vader::peeks_leading_continuation` deliberately excluded the multi-char `&&` / `||`, so only a leading single `|` / `&` (type union / intersection) suppressed the preceding newline; a leading `&&` got a statement-terminating newline and the `if`-condition ended early. **Fix**: `&&` / `||` / `&` / `|` have no prefix/unary form (`parse_prefix` only knows `-` / `!` / `~`), so a line *opening* with one is unambiguously a continuation — `peeks_leading_continuation` now suppresses the newline for `&&` / `||` too (only `&=` / `|=` stay excluded). Scope kept to these four infix-only operators; generalising to `+` / `==` / etc. would need a Go-ASI-style "is the previous line complete?" heuristic to disambiguate a leading unary `-` (deferred — see the reverted broad-scope option). SPEC §"Newline-significant" gained a 5th newline-absorption case (+ example). Regression: 4 colocated `@test`s in `lexer.vader` (`test_leading_andand_continues`, `test_leading_oror_continues`, `test_leading_pipe_still_continues`, `test_complete_lines_keep_newline`). Seed re-bumped.
- [x] **Cross-module stdlib `const` reference miscompiled** (fixed 2026-06-19). Referencing a `const` imported from a **stdlib** module — e.g. `import "std/math" { pi }` then using `pi` — silently produced no output (native) / `local.set on empty stack` (VM). **Real root cause** (the earlier `LoweredConstDecl`-accessor / `emit.vader:556` hypothesis was wrong) : the lowerer skips imported stdlib module decls (`is_stdlib_path`), so the stdlib const was never lowered into `project.modules` → `inline_consts` had no entry → `midir/build.vader::build_ident` fell through to `build_unreachable_type`, truncating the caller (DCE then stripped the dead chain). User-module cross-module consts always worked (`lower_module` lowers them eagerly). **Fix** : lazy on-demand harvest mirroring `materialize_nongeneric_stdlib_fns` — `register_nongeneric_stdlib_const` (in `lower_ident`) records a referenced stdlib const, `materialize_nongeneric_stdlib_consts` lowers its decl into the owning module so `inline_consts` routes it (scalar → inline, bulky array → fn-wrap). Byte-identical fixed point preserved (the compiler tree references no stdlib value-const → empty harvest during self-compile). Regression guard : `tests/snippets/_diag_const_cross_module/` (+ in `VADER_SELF_EMIT`). The harvest is the exact compensation for the `is_stdlib_path` skip and becomes dead code once `is_stdlib_path` is removed (separate planned chantier). **README follow-up :** the hero snippet's local `pi :: 3.141592653589793` workaround can now be restored to `import "std/math" { pi }`.
- [x] **`vader run <file>` runs the named file's `main`, not an arbitrary directory entry** (fixed 2026-06-20, `6e133274`). Folder = module, so `vader run dir/b.vader` loaded `dir`'s whole module and the VM picked the first `is_main` fn — silently running `dir/a.vader`'s `main`. T3053 only caught same-signature duplicate `main`s; the gap was two `main`s of *different* signatures (`fn()` vs `fn(argv)`). Fix (`vader/cli/main.vader::entry_index_for_file`, CLI-only — no pipeline/seed change): `run_source` resolves the entry by matching the named file's `main` (lowered fn's `origin.decl` span file, basename-matched), falling back to the first `is_main`. Regression `tests/vader_run_entry.test.ts`. Follow-up if wanted: `vader build` / `dump --stage=c|bytecode` still use the conventional first-`main`.
- [x] **`StringBuilder.to_string` read-back regression** (found + fixed 2026-06-15 via ABI benches). The Buffer-fill model copied bytes per-`append` (a boxed per-byte `u8[]` read into the buffer) **and** read them back per-byte at `to_string` — measured 3.1-3.3× slower than `main`. Rather than patch the read-back, StringBuilder was returned to the **parts model** (`string[]` of references) : `append` is now an O(1) ref push, and `to_string` assembles all parts in one bulk pass — `total.new_buffer()` + per-part `write_string` (the new `BufferWriteString` memory opcode, a lean `memcpy` replacing `vader_string_concat_all`) + `intern_string` (`BufferToString`). Lands StringBuilder ≈ `main` with no fat runtime symbol. See `bench/string_builder`.

### Phase 1 — MVP compiler in TypeScript › 1.7c Bytecode format refresh — partial

- [x] Renamed textual format to `.virt` (CLI `--target=ir-text`).
- [x] Binary `.vir` format (`src/bytecode/binary.ts`) — magic `"VADR"`, version `BYTECODE_VERSION = 0.1.1` (hard error on mismatch), `FLAG_HAS_DEBUG`, 9 length-prefixed sections, both formats round-trip the same `BytecodeModule`. `vader run` extension-sniffs `.vader` / `.vir` / `.virt`.

### Phase 1 — MVP compiler in TypeScript › 1.8 VM — done

- [x] Tagged value model, stack-based interpreter (structured control + jump tables + intrinsics + `type_check` + `ref.cast` no-op), host bindings for `std/io`, `vader run file.{vader,vir,virt}`, 7 snapshot scenarios.
- [x] **Real impl table for trait `type_check`.** Today's heuristic covers host-driven I/O ; a user struct `Foo implements MyTrait` won't match `type_check MyTrait` in the VM until the bytecode emitter materialises an impl-table side-section. Picked up alongside generic-fn dispatch.

### Phase 1 — MVP compiler in TypeScript › 1.11 C runtime — partial

- [x] **GC** : Cheney semi-space copying GC (`runtime/c/vader_runtime.c`). Precise roots via shadow stack + emitted `vader_gc_frame_t`s ; per-type pointer maps from C-emit. Knobs : `VADER_GC_ARENA_BYTES`. Stress tests under `tests/snippets/gc_*`.
- [x] **Arrays GC-tracked** — `vader_array_t` carries a header with single ref to a separately-allocated `vader_array_buf_t` ; Cheney scan dispatches on sentinel `0xFFFFFFFE`.
- [x] **Strings off the GC arena** — string buffers `malloc`'d outside the arena. Strings leak for the program's lifetime ; fine for MVP.
- [x] **Array `pop` — covered by `remove_last`** (Array API chantier). `arr.remove_last()` IS O(1) pop-and-return : it shrinks `length` (`vader_array_remove_last`, capacity preserved) and returns the removed element as `T | null`. A separate `pop` intrinsic would be a pure alias — not added. (Original ask predated `remove_last`.)

### Phase 1 — MVP compiler in TypeScript › 1.13 Stdlib (in Vader) — partial

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
- [x] Iterator impls for `MutableMap` / `MutableSet`.
- [x] **Audit `std/iter` and `std/string` surfaces** — surfaced 2026-05-20 during SPEC vs stdlib sweep. Two threads to follow up : (a) `std/iter` is missing an explicit `into_iter()` helper (SPEC previously referenced one) — decide between adding `arr.into_iter()` as an explicit form or relying solely on the `T[] implements Into(Iterator(T))` coercion ; (b) `std/string` exports drifted from SPEC (added `index_of`, `compare_ascending`, `compare_ascending_ci`, `decode_escapes` ; missing `is_hex_digit` / `is_digit_in_base` — now placed under `std/numbers`). Pass to settle on one canonical surface per module and align SPEC + stdlib + ports.
- [x] `std/string_builder` — `StringBuilder`.
- [x] `std/iter` — eager `T[]` combinators (`map`, `filter`, `fold`, `sum`, `take`, `skip`, `collect`, `count`, `zip`, `chain`, `enumerate`, `flat_map`).
- [x] `std/iter` lazy combinators — `MapIterator`, `FilterIterator`, `TakeIterator`, `SkipIterator` (struct-literal construction).
- [x] `std/runtime` — `collect()`, `collections()`, `bytes_used()`, `bytes_copied()`.
- [x] `std/sort` — `sort(arr, less)` stable merge-sort with insertion-sort cutoff. Returns a new array.

### Phase 1 — MVP compiler in TypeScript › 1.13d Stdlib consolidation — partial

- [x] **Audit consistency across `std/core` / `std/string` / `std/utf8`** (noted 2026-06-15) — these three modules feel incoherent : overlapping / unclear ownership of the byte ↔ codepoint ↔ string surface (`bytes_to_string`/`as_string`, `bytes()`, codepoint vs byte cursors, UTF-8 encode/decode). Map which module owns what, dedup the overlap, and settle a clear layering (core = byte primitives + intern ; utf8 = encode/decode ; string = the codepoint-string API). Cross-ref the `bytes_to_string` reconciliation item below.
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

### Phase 1 — MVP compiler in TypeScript › 1.19 Type-first design — remaining layers

- [x] **Mono pass unified — DONE 2026-06-30 (Direction B).** The investigation (`.claude/plans/mono-pass-unification.md`) inverted the premise: the comptime `monomorphize_project` pass was **dormant** (its output unconsumed) and the **lowerer** was the authoritative monomorphizer — reading the comptime side only as a redundant struct-instance filter the lowerer's own gating already covered. Rather than route everything through the comptime engine (Direction A — no perf payoff, comptime is 0.7 % of the build, high-risk), the dormant comptime mono pass + the unwired erasure-dedupe + the dead IR fields were deleted, leaving the lowerer as the sole monomorphizer. **−1661 LoC Vader / −2268 LoC C, byte-identical** (suite 2426/0, fixed point holds). Commits `d3921224` / `3c8b54f4` (+ seeds `ea55d85f` / `7be8ddbd`). Kept `MonoEntry` (the lowerer's "decl to emit" unit) + `symbol_for_decl` (extracted to `symbol_lookup.vader`). NB: T3033 is `InvalidMainSignature`, not a bound check — the real bound diagnostic is T3006, which lives in the typechecker and was never part of the mono pass.
- [x] Short-circuit `@comptime t :: i32` via `constTypeAliases` lookup ; synthesises a `ComptimeValue.type` directly. `comptimeToValue` traps for now.
- [x] VM `TypeValue { tag: "type", typeIndex: i32 }` (`src/vm/value.ts`) keyed into the module type table.
- [x] Bytecode op `type.const` — `src/bytecode/ops.ts` + `.virt` round-trip (`src/bytecode/text.ts`) + `.vir` binary round-trip (`src/bytecode/binary.ts`).
- [x] Reuses existing `BytecodeModule.types` interning via `internType` — no new table.
- [x] `LoweredTypeConst` in `src/lower/lowered-ast.ts` + lowered by `lowerIdent` when an ident's type is `TypeMeta` (`src/lower/passes/expr.ts`).
- [x] CFG `InstrTypeConst` + bytecode emit (`src/midir/{cfg,build,emit}.ts`).
- [x] VM op handler (`src/vm/exec.ts`).
- [x] `ComptimeValue.type` ↔ VM `TypeValue` round-trip (`src/comptime/run.ts`) — comptime→VM uses `-1` placeholder since the comptime carrier already holds the static `Type` ; VM→comptime errors with C4011 until B.2 brings a static-`Type` source through `@type_of`.
- [x] Test snippet `tests/snippets/comptime_type_value/` — exercises a TypeMeta ident in an arg of `fn accept_type(t: type)`. The c-emit emits a tagged-null placeholder + a `uintptr_t`-encoded `typeIndex` to keep the C stack consistent ; the Vader VM lacks the op and is in `KNOWN_DIVERGENT` until `vader/vm/exec.vader` ports it.
- [x] `@type_of(x)` — reifies the static type of `x` as a `type` value ; lowers to `LoweredTypeConst` (no arg evaluation, Zig-style).
- [x] `@size_of(t)` runtime path — when `t` is a TypeMeta-typed value, lowers to a new `size_of.type` intrinsic that pops a TypeValue and pushes its size as usize. Wired in TS VM, c-emit (via a generated `vader_type_size[]` table), and Vader VM. Static path (`@size_of(i32)`) continues to fold to an IntLit at compile time.
- [x] Test snippet `tests/snippets/comptime_type_value/` exercises both intrinsics.
- [x] `type.const` op + `TypeVal` variant in `vader/vm/op.vader`, `parser.vader`, `exec.vader`, `value.vader`, `builder.vader`.
- [x] `SizeOfType` intrinsic op in the Vader VM ; `size_of_bc_type` helper in `vader/vm/value.vader`.
- [x] `comptime_type_value` removed from `KNOWN_DIVERGENT` in `tests/vader_vm.test.ts`.
- [x] `Maybe :: type[T] T | null` and `Pair :: type[A, B] A | B` verified.
- [x] Verify call-site override `sum[i64](arr)`.
- [x] Accept `t :: <structural-type-expr>` as in-fn type alias.
- [x] Reject other `type`-valued locals at typecheck (T3035).
- [x] `i32[]` in let-stmt value position. Caveat : `fn(i32) -> i32` in value position still fails (parser's `parseFnSignatureParams` expects `name: type`). Tracked separately.
- [x] `@type_of(x)` — value's static type as `type` (shipped with Layer 4 B.2).
- [x] `@fields(T) -> Field[]` (landed 2026-05-16). `Field` lives in `std/core` (auto-imported), exposes `name: string` and `type: type`. Static `T` only — lowers to a `LoweredArrayLit` of `Field { .name = …, .type = … }` literals at lower time ; field types flow through the call-site's substitution so `@fields(Pair(string, i64))` reports `value` as `i64`. Snippet `intrinsic_fields` covers Map(K, V)-style generic and non-generic structs across VM / native / Vader VM. Runtime `T` (when `t: type` is a fn param) deferred — needs a runtime struct-field table.
- [x] `@type_args(T)` — generic args of a generic instance (landed 2026-05-16). Returns `type[]` ; non-generic types yield `[]`. Sibling of `@fields(T)`, same lowering pattern (LoweredArrayLit of LoweredTypeConst per arg). Snippet `intrinsic_type_args` covers Struct + non-generic + cross-module via std/collections.
- [x] `@field(x, "name")` (landed 2026-05-16). Dynamic field access keyed by comptime string. Two typecheck paths : (1) bare string literal at call site → resolves field type immediately + T3009 on unknown ; (2) deferred path → returns Unresolved, lower-pass re-validates after `@comptime for` substitution turns `f.name` into a `LoweredStringLit`. Lowers to `LoweredFieldAccess`. Closes Layer 6 reflection : `@comptime for f in @fields(T) { … @field(self, f.name) … }` works end-to-end for derive macros.
- [x] `@comptime for f in @fields(T) { ... }` (landed 2026-05-16). Unrolls at lower time : the iter expression must lower to a `LoweredArrayLit` of compile-time-known elements, and the body is emitted N times with the loop-var substituted by each element's literal. `lowerIdent` checks a per-fn `comptimeBindings` map ; field access on a `LoweredStructLit` target folds to the field's value, so `f.name` / `f.type` become straight string / type literals — `@size_of(t)` folds to a constant per iter. Snippet `comptime_for` covers `@type_args` + `@fields` over a generic struct. Forbids `LoweredIdent` / non-array iters with B5001. Follow-ups : (a) reject `break` / `continue` in the body (today they bind to the nearest real outer loop), (b) reject `@comptime for` on `while` / infinite forms at parse time.
- [x] 8b — `implements` verifies inherent methods (T3036).
- [x] 8c — explicit conformance, no structural inference (T3006).
- [x] 8d — default-method injection at `implements` site.
- [x] 8e — orphan rule (light, R2018, primitives exempt).
- [x] 8f — ambiguous trait-method dispatch (T3032).

### Phase 2 — Self-hosting › 2.2 Port the C emitter — NATIVE FIXED POINT REACHED (2026-06-05)

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

### Phase 2 — Self-hosting › 2.5b Port the comptime engine — partial (tree-walk MVP, 2026-05-18)

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

### Phase 2 — Self-hosting › 2.5c Port the lowerer — partial (basic + match + interp + range, 2026-05-18)

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

### Phase 2 — Self-hosting › 2.6 Port the type-checker (last)

- [x] Port to Vader.
- [x] **`if cond { i32_expr } else { 0 }` doesn't collapse `i32 | {integer}` to `i32`** (surfaced 2026-05-26 by the LSP on `stdlib/std/semver/semver.vader::caret_upper`). When one branch of an `if`-expression has a concrete numeric type (`p.major: i32`) and the other branch is a free-integer literal (`0`), the Vader self-host typer joins them as a union `i32 | {integer}` instead of promoting the free int to the concrete width. The LSP then flags downstream uses with T3017 (`operator not defined for these operand types: i32 | {integer} and {integer}`) on `maj + 1`. The TS reference impl reported zero errors on the same source, so it's a Vader-only gap — likely a missing case in `join_types` / `merge_branches` where one operand is `FreeInt` and the other is a concrete primitive width. Workaround at user level : explicit cast (`{ i32(0) }`) in the partial-default branch, but that defeats the point of free-numeric defaulting. Fix probably one-liner in `vader/typecheck/{join,merge}.vader` (mirror what `is_assignable` does for FreeInt → concrete).
- [x] **`is Type` antipattern in union-typed values** — `match expected { is Type | null }` etc. `expected is Type` against the closed `Type` union always returns false (the runtime tag is the variant tag, not the union tag). Bit me twice : `seq_lit.vader::infer_seq_lit` ignored every union-shaped expected slot ; `infer_seq_lit`'s "`picked is Type`" branch never fired. Fix is `match { is null -> {} _ -> ... }`. Search the codebase for other `is <UnionAlias>` checks (none found via grep on the typecheck dir, but worth a pass over `vader/resolver/` and `vader/lower/`). Either lint this at the compiler level or rename the patterns to avoid the trap.
- [x] **`vader build -o <path>` honored** (2026-05-17) — `cmdBuild` now pre-strips `-o <path>` POSIX-style and treats it as `--out=<path>`. Earlier the `--`-prefix filter dropped both `-o` and its value into positionals ; `outFlag` stayed undefined and the binary landed at the default location.
- [x] **Code-size explosion when adding a small branch to `is_assignable`** (mitigated 2026-05-21 via Phase B of `CC_COMPILE_TIME_REDUCTION.md`, verified 2026-05-26). `is_assignable` moved from `vader/typecheck/type_ops.vader` to its own file `vader/typecheck/type_assign.vader` and was split into one helper per source variant (`is_assignable_struct`, `is_assignable_array`, `is_assignable_fn`, `is_assignable_union`, `is_assignable_tuple`, `is_assignable_trait_from`, `is_assignable_freeint`, `is_assignable_freefloat`) plus a shared `check_common` for primitive / enum / never / type-meta / type-param fast paths. The dispatcher (`is_assignable` itself) is now ~25 LoC of `match from { ... }`. Measured 2026-05-26 on `vader/cli/main.c` : `is_assignable` C body is **80 lines** (down from 51 536 pre-split, -99.85 %). Adding a new arm goes into one of the per-variant helpers ; the old monolithic explosion can't recur because there's no monolith to inline-clone. Cause-root (c) from the mitigations list — c-emit's match-arm cloning behaviour — turned out to be irrelevant once the monolith was broken up.
- [x] **`build/vader` background processes don't get killed when typechecker / VM regresses** (2026-05-17). Found 3 `build/vader run tests/snippets/custom_iter/bytecode.snapshot.virt` + 1 `bun src/index.ts run bench/map_iter.vader` processes pinning 100% CPU for **33+ hours**, residue of sessions where custom_iter's bytecode VM execution actually did loop forever (since fixed). `parity.test.ts` has a 30s per-test timeout but the native runner spawned from it doesn't inherit that — once Bun's test driver bails on timeout, the spawned VM keeps running. Add a `kill` step to the native test driver's cleanup, OR run each child under a hard wall-clock budget (`timeout 30s build/vader run ...`).
- [x] **Self-host closure capturing two free vars segfaults at runtime — NOT REPRODUCIBLE / FIXED (verified 2026-07-16).** A faithful repro (a closure passed to a higher-order walker, capturing a struct AND a map, calling a free fn with both) runs clean on both VM and native (`total=3006`). Closed; reopen only with a concrete repro on HEAD. Original report below.
- [x] **`!is` (negated type-test) operator** — landed via commit `03525c1f` ("feat(parser): add `!is` operator and `for <range>` shorthand"). Both Vader self-host parser (`vader/parser/parser.vader:2392-2418`) and TS parser (`src/parser/passes/expr.ts:122`) desugar `x !is Y` to `Not(BinaryOp.Is(x, Y))`. Formatter restores the spelling (`vader/fmt/printer.vader:1276-1284`). SPEC.md §"operator precedence" documents the form (lines 299, 330, 335).
- [x] **`if a is X { a.field }` doesn't narrow `a` across statements** — single-expression guards work but `if a is X { for v in a.variants { … } }` requires a `match a { is X as ax -> { for v in ax.variants { … } } _ -> {} }` rewrite. Bit me in `vader/typecheck/binary.vader::types_overlap` ; eventually settled on a tiny `union_variants :: fn(t) -> Type[] | null` helper to dodge the narrow. Either tighten the flow analysis so `a.variants` inside the if-then sees the narrowed type, or document the rewrite + add it to the formatter's lint pass.
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
- [x] **Codegen: narrowed scrutinee miscompiles when an arm writes through it
      AND reassigns it — NOT REPRODUCIBLE / FIXED (verified 2026-07-16).** A faithful
      repro (`match cur { is Entry<i32,i32> -> { total += cur.key; cur.next = null;
      cur = nxt } }` over a generic linked list) runs clean on both VM and native
      (`sum=6`, no null deref). Closed; reopen only with a concrete repro on HEAD.
      Original report below.
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

### Phase 2 — Self-hosting › 2.6b Self-host perf — pistes restantes (post-2026-05-22)

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
- [x] **Reprofile after these land** — the d467d5b1 lookup_local_symbol
      fix cut 49 % off `orchestrate.vader` lowered-ast on its own.
      Each fix shifts the next hot path, so the order matters less
      than re-sampling between rounds.
- [x] **Scope-down `settle_external_expr_bodied_returns`** — already
      listed in §2.6 follow-ups but quoted here for cross-reference :
      `vader/typecheck/orchestrate.vader:695-707` walks every non-entry
      module's bodies even when none have expr-bodied fns. Limit to
      modules where `has_expr_bodied_fn` returns true. Profile-side
      this hasn't shown up as dominant (the lowered-ast path was way
      lower-bound), but the savings stack with the lower perf chantier.
- [x] **String interning for hot identifiers** — names like
      `"self"`, `"Iterator"`, `"next"`, `"to_string"` are repeatedly
      compared / allocated. An interning table would replace string
      equality with identity comparison and drop the per-mention
      alloc. Surface : `vader/resolver/symbol.vader` for the canonical
      home ; consumers in lower / typecheck switch to comparing
      interned ids.

### Phase 2 — Self-hosting › 2.7 Bootstrap success check — done (C-seed fixed point)

- [x] C seed → compiler (`stage1`) ; `stage1` → compiler (`stage2`) ; `stage1` == `stage2` byte-identical (identical outputs + idempotence in one check).
- [x] Enforced by `bootstrap/verify.sh` (`stage1` == `stage2` byte-for-byte + seed freshness).

### Phase 2 — Self-hosting › 2.8 Freeze the TS compiler — done

- [x] Final TS compiler tagged (`v0.0.0-pre-mvp-final-ts`) then deleted (`81053f16`, §2.8) ; bootstrap documented in `docs/BOOTSTRAP.md`. Vader self-hosts from the C seed.

### Phase 3 — Post-MVP › 3.5 Performance

- [x] **Open-addressed hash table for `MutableMap` — DONE via compact-dict** (`6c50d7a2`). An earlier Robin-Hood attempt was disqualified by bench (`map_iter` +59 % — boxed `vader_box_t` struct elements defeat inline-storage locality) and reverted ; a later **compact-dict** open-addressed design (dense entry array + slot index) shipped without the iteration regression — `std/collections` now documents the compact hash map. (The "disqualified, chaining is the right call" verdict below was the Robin-Hood result, since superseded.)

### Phase 3 — Post-MVP › 3.7 Tooling

- [x] **LSP : revisit hover signatures once the typechecker is self-host.** Today the indexer is AST-only ; hover on local bindings falls back to source slice + literal-suffix heuristics. When the typechecker lands in Vader (§2.6), consult its inferred-type table directly for proper `name: T` rendering. Same upgrade fixes param hover under generics + match-arm pattern bindings.
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
- [x] **LSP code actions framework** — general refactoring infrastructure on top of the LSP. Components : `codeActionProvider` capability in `vader/lsp/lifecycle.vader` ; new `vader/lsp/expr_at.vader` position → `Expr` walker ; `vader/lsp/code_actions.vader` registry of `{ kind, title, is_applicable, apply }` records ; expose `emit_expr(e: Expr) -> string` out of `vader/fmt/printer.vader`. First actions : `match → if` (≤ 2 arms reducible to booleans), `if-chain → match` (≥ 3 branches on same scrutinee), null-narrow rewrite, and **UFCS conversion** (`f(x)` ↔ `x.f()`, both directions, offered when the receiver type resolves the method). Reuses the same scaffolding for future refactorings (extract-fn, inline-let, rename). Design + open architectural questions captured in [`docs/LSP_COMPLETENESS.md`](./docs/LSP_COMPLETENESS.md) (§ Code actions framework). Deferred until self-host MVP closes ; cross-ref the `repair.id` entry above for the diagnostic-driven companion.
