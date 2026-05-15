# Vader — TODO

This document tracks the implementation roadmap for the Vader compiler and standard library, derived from `SPEC.md`. It is organised into three phases:

- **Phase 1** — MVP compiler in TypeScript, plus stdlib in Vader.
- **Phase 2** — Self-hosting (port the compiler to Vader).
- **Phase 3** — Post-MVP language features and tooling.

Each item is sized to be actionable. Cross items off as they're completed. Reorder freely — the listed sequence is a suggestion based on dependency, not a hard requirement.

---

## Priority — next up

Items here jump the queue ahead of the phased roadmap below. They reflect a deliberate shift: stabilise the surface area people can touch (binary, formatter, perf signal) before extending the language further, and pay down two concrete pieces of internal debt (SSA, monoliths) before they harden.

- [x] **Single-binary distribution** (2026-05-10). `bun build --compile` produces a standalone `vader` binary ; the CLI no longer needs `bun src/index.ts`. Shipped as one tarball per OS (`vader-<os>-<arch>.tar.gz`) containing the binary alongside `stdlib/` and `runtime/c/` — the binary locates these sidecars via `dirname(process.execPath)`, with a dev fallback via `import.meta.dir`-relative paths (`src/runtime-resources.ts`). Resolved both `import.meta.dir`-based lookups : `src/resolver/module.ts:resolveStdlibRoot` and `src/cli/commands/build.ts:buildNative`'s `runtimeRoot`. Packaging via `scripts/dist.ts` ; npm scripts `dist:current` / `dist:darwin-arm64` / `dist:darwin-x64` / `dist:linux-x64` / `dist:all`. Acceptance verified : extract `vader-darwin-arm64.tar.gz`, run `./vader-darwin-arm64/vader run hello.vader` ✓ ; `vader build --target=native` produces a working binary ✓ ; orphan binary (sidecars stripped) fails cleanly with R2001 instead of crashing. Cross-compile from macOS-arm64 → linux-x64 (38 MiB) + darwin-x64 (24 MiB) works out of the box. README updated.
- [~] **`vader fmt` MVP.** First working pass landed 2026-05-11. Written in **Vader** (not TS) — lives under `vader/fmt/` and exercises the self-host parser end-to-end. Modules : `style.vader` (constants + op tables), `comments.vader` (independent offset-keyed pre-scan since the lexer drops `//` + `/* */`), `printer.vader` (~1000 lines of per-node emitters, dispatches `Decl`/`Stmt`/`Expr`/`Pattern`), `format.vader` (parse + emit pipeline), `cli.vader` (argv + dir walk + `FileResult` enum). The TS `vader fmt` command (`src/cli/commands/fmt.ts`) is a thin shim that runs `vader/cli/main.vader fmt <args>` through the bytecode VM ; the Vader CLI dispatches to `run_fmt`. The `vader/` tree ships in the dist archive (extended `scripts/dist.ts` + `runtimeRoots().vaderRoot` probe) so the formatter is reachable from both `bun src/index.ts fmt …` and the native `./vader fmt …`.

  Pre-requisites that landed alongside : `std/io.read_dir` / `std/io.is_dir` (runtime C + VM host + C-emit shims), plus surgical `usize`/`i32` casts in `vader/parser/parser.vader` to dodge VM tag-mismatch traps that the compiled-native CLI was tolerating.

  Surface preservation : `T!` shorthand recovered by detecting `BinaryExpr.BitOr` whose source slice ends with `!` ; precedence-grouping parens recovered by ranking child vs parent `BinaryOp` ; integer / float / string / char / `GenericInstExpr` literals emitted verbatim from the source slice (preserves `0x` / underscores / raw / triple-quoted / `[T]` vs `(T)`). Layout choices respect the source : multi-line vs inline structs / imports / blocks, `if-else if` cascade breaks, decorator inline-vs-block, blank lines between comment groups and between commented declarations.

  Acceptance status :
  - **Idempotency `fmt(fmt(src)) == fmt(src)`** ✓ verified on `stdlib/std/{io,path,json}.vader`.
  - **Parse round-trip** ✓ — formatted output reparses to an AST equivalent to the original.
  - **Stdlib byte-for-byte no-op** ✗ not yet. Three known stylistic gaps : (a) decorative column alignment of `::` in declaration groups, (b) per-line item grouping inside multi-line imports (my formatter is one-per-line ; the stdlib has 2-3 per line), (c) cap at 1 blank line between decls vs the stdlib's occasional double-blank section dividers. None of these are correctness bugs ; they're authority-of-the-formatter decisions to make.

  Test rigs (2026-05-11) :
  - `tests/formatter.test.ts` — 40 tests (20 idempotency + 20 parse-round-trip) on a curated subset of the snippet corpus (covers generics, traits, match, closures, tuples, decorators, vaderdoc).
  - `tests/formatter_stdlib.test.ts` — 18 tests across every `stdlib/*.vader` : idempotency on all, plus byte-for-byte no-op on the 4 files already converged (`iter`, `runtime`, `sort`, `string_builder`). Grow `NO_OP_FILES` as more refinements land.
  - Both gated behind `RUN_FMT_TESTS=1` (each invocation pays a ~2-3 s VM-bootstrap, total ~2 min).

  Open items : (a) column-alignment of `::` if we decide the stdlib style is the canonical one ; (b) hand-curated snapshot scenarios under `tests/snapshots/formatter/` for documenting specific canonical output ; (c) Grow the `NO_OP_FILES` set as more stylistic gaps are closed.
- [x] **Reference benchmark** (2026-05-14). `bench/` ships two CPU-bound workloads — `mandelbrot` (240×180×500 iter) and `primes` (trial division up to N = 1 000 000) — each implemented in Vader, Bun-TS, and Go. `bun run bench` drives every implementation through `spawnSync`, takes `min(samples)` over 1 warmup + 3 measured runs, prints a Markdown table, and compares against the committed `bench/baseline.json` ; exits non-zero on regression > 10 % or checksum drift. Baseline captured on a 2026 Apple Silicon laptop : mandelbrot — vader-vm 18 788 ms / vader-native 65.3 ms / bun-ts 23.4 ms / go 18.1 ms ; primes — vader-vm 29 423 ms / vader-native 41.1 ms / bun-ts 41.1 ms / go 23.9 ms. **Note about the workload :** the trial-division `primes` is intentionally not the sieve from `examples/primes.vader`. The sieve allocates a 10 M-element `bool[]` array, which at 16 bytes per boxed element (`vader_box_t`) blows the 4 MB young semi-space — a separate Vader limitation worth fixing (primitive arrays + an `Array.new(size)` constructor in stdlib). Trial division sidesteps that and is allocation-free, so it isolates CPU-path perf cleanly. Detailed methodology, build flags, and notes on Go's FMA-driven mandelbrot checksum drift live in [`bench/README.md`](./bench/README.md).
- [x] **Adopt `s[i]` over `s.char_at(i)`** (2026-05-11). Swept all 6 call sites (5 UFCS in `vader/lsp/*` + `examples/mowitnow.vader`, 1 free fn in `examples/mandelbrot.vader`), then dropped the `char_at` export entirely — `s[i]` is now the only surface for codepoint access. Removed the host binding (`std_string$char_at` in `src/vm/host.ts`) and the C-emit shim ; runtime `vader_string_char_at` stays since `std_core$string$Index$at` (the operator `[]` route) still uses it. `.byte_at(i)` kept verbatim in the hot byte-level scanners (`vader/fmt/comments.vader`, `vader/lexer/lexer.vader`) since `[i]` is char-typed and forces a UTF-8 decode per step. Bonus : the `lower.snapshot` dumper had been tagging every symbol reference with its global `Symbol.id` (`name#N`) — a monotone counter that shifted with every stdlib add/remove, producing massive cosmetic diffs. The tag is now dropped at the source (3 sites in `tests/snapshot.ts`) ; types beside each reference disambiguate overloads, shadowing is rare enough under `::` immutable bindings that the IDs were never load-bearing for diff reading. One-shot rebase of all 154 `lower.snapshot` files.
- [x] **SSA round-trip — removed** (2026-05-14). Measurement on stdlib + examples (24 files, 511 allocs) showed SSA-form escape analysis produces strictly the same `stack:` annotations as flat-CFG escape analysis — zero precision gained. The round-trip itself bled +82 residual `Move` instructions after the post-`fromSSA` DCE (~1% bytecode bloat). Deleted `src/midir/ssa.ts` (335 LoC) + `computeDominanceFrontiers` in `analyses.ts` (sole consumer was the SSA construction). Dropped the `InstrPhi` type from `cfg.ts` and the orphaned `case "Phi":` in `analyses.ts`, `dce.ts`, `dump.ts`, `emit.ts`, `escape.ts`, `scheduler.ts`. `pipelineCfg` and `lowerComptimeDecl` now run one `eliminateDeadCFG` followed by a single `annotateEscape` — the trailing DCE that only cleaned `fromSSA`-introduced moves is gone too. Regenerated all 367 cfg+bytecode snapshots (mechanical : SSA `#NN` versioning suffix gone, LocalIds renumbered to a compact range). Self-host VM (`vader fmt`, `formatter*.test.ts`) green ; mandelbrot still renders identically through both `vader run` and `--target=native`.
- [x] **Replaced the `inLoop` filter with a loop-carried-dependency check** (2026-05-14). The previous filter rejected every alloc inside a natural loop body, citing "block-scoped C storage aliases across iterations". This was over-conservative — the aliasing only matters when the alloc's value flows into a local that's also alive on the next iteration (the `head = Node { .next = head }` pattern). New `computeCarriedAcrossLoopHeaders` in `escape.ts` intersects `liveIn[loop_header]` with locals defined in the loop body to find the loop-carried set, then backward-propagates through the alias graph so allocs that flow into a carried local are also rejected. Allocs inside loops whose value dies before the next iteration (e.g. `for i in 0..<n { p :: Point { .x = i, .y = i+1 }; total += p.x + p.y }`) are now stack-allocated. Compiler self-host measurement (`vader/`) : 0 → 95 stack-promotions across 3 923 allocs (2.4%). Existing GC tests (`gc_chain_survive`, `gc_multi_collect`) green — they exercise the loop-carried-pattern correctly. The `examples/` corpus is unchanged at 0/511 because those allocations escape via Return / Call args regardless of the loop filter — the win is on more idiomatic code.
- [x] **Three monoliths broken up** (no specific commit — incremental progress over many sessions). Current line counts as of 2026-05-14 : `src/c_emit/emit.ts` 720, `src/typecheck/passes/call.ts` 249, `src/resolver/resolve.ts` 785 — none above the 1k-line threshold that originally motivated the entry. The largest file in `src/` is now `lower/passes/expr.ts` at 983 lines, which is a single coherent pass over LoweredExpr cases and not in obvious need of splitting.
- [ ] **LSP semantic classification via the AST.** Today `vader/lsp/semantic_tokens.vader` classifies identifiers from the **lexer stream alone** with a `is-uppercase?` heuristic : `MutableMap` → `Type`, every lowercase ident → `Variable`. Consequences : function names (`double :: fn(...)`) ship as `Variable`, primitive types (`i32`, `usize`, `string`, `bool`) ship as `Variable`, fields and locals are indistinguishable, etc. Replace with a pass that runs the parser + resolver and walks the AST so each `IdentExpr` is tagged with its actual kind (`FnDecl` → `Function`, `TypeRef` → `Type`, `FieldAccess` → `Property`, …). Same trick as `vader/fmt/` does today — call into `vader/parser/parser.vader` and `vader/resolver/`. Adds a real semantic-token pipeline ; throws away the lexer-only shortcut. Acceptance : `vader fmt` regression suite still green, and Inspect Editor Tokens on `double`/`i32`/`self`/struct fields shows the correct token type and color.

---

## Phase 0 — Project bootstrap

- [x] `bun init` to scaffold the TypeScript compiler under `src/`
- [x] Add `tsconfig.json` with strict mode enabled (and stricter flags: `noUncheckedIndexedAccess`, `noFallthroughCasesInSwitch`, `noImplicitOverride`)
- [x] Add a test runner (`bun test`) and wire it to `tests/`
- [x] Snapshot-testing driver (folder-per-scenario, `tests/snapshot.ts`). Refresh with `UPDATE_SNAPSHOTS=1 bun test` or `bun run test:update`. Lexer scenarios live under `tests/snapshots/lexer/<name>/{input.vader,tokens.snap}`
- [x] Wire a minimal CLI entry point: `bun src/index.ts <command>` — all top-level commands stubbed (`run`, `build`, `fmt`, `test`, `dump`, REPL)
- [x] Add `.gitignore` for `dist/`, `node_modules/`, build artifacts

---

## Phase 1 — MVP compiler in TypeScript

### 1.0 Diagnostic infrastructure (cross-cutting, prerequisite)

- [x] Diagnostic data shape (severity, code, message, primary span, secondary spans, notes, fixes) — `src/diagnostics/diagnostic.ts`
- [x] Diagnostic collector (per-compilation-unit): accumulate, sort stable by `(file, offset, code)` — `src/diagnostics/collector.ts`. Dedup deferred (no real source of duplicates yet)
- [x] Code registry (`src/diagnostics/codes.ts`) — `L0001..L0010` for the lexer
- [x] Terminal renderer: source snippet, primary-span caret/underline, notes, help — `src/diagnostics/render.ts`. Optional ANSI color deferred
- [x] JSON renderer: stable schema, `JSON.stringify` of the diagnostic array
- [x] CLI flag `--diagnostics=text|json` parsed and threaded as `GlobalOpts` to every command (`src/cli/options.ts`). Renderer selection happens at the call site once compilation is wired

### 1.1 Lexer

- [x] Token kinds: ident, int, float, char, string_begin/string_part/string_end/interp_open/interp_close, every keyword as its own kind, every operator as its own kind, punctuation, newline, eof — `src/lexer/token.ts`
- [x] Token data: source text slice, span, parsed value (for literals), numeric suffix
- [x] Source-position tracking: file, offset, 1-based line/column (JS code-units; ASCII-accurate, LSP boundary will translate)
- [x] Shebang: skip `#!...` on line 1 only, error otherwise (`L0008` reserved)
- [x] Whitespace: spaces/tabs absorbed; tabs not given a fixed width
- [x] Comments: `//` line, `/* */` block with nested depth tracking
- [x] Identifiers and keyword recognition (table-driven via `KEYWORDS`)
- [x] Numeric literals:
  - [x] Integer in bases 10 / 16 / 2 / 8 with underscore separators
  - [x] Float with leading zeros, exponents, no trailing-point
  - [x] Suffixes (`i8..i64`, `u8..u64`, `f32`, `f64`) with optional underscore separator (`42_i32`)
  - [x] Reject `42_`, `1__0`, unknown suffix, integer suffix on a float literal
- [x] Char literals with escapes (`\n \t \r \\ \' \" \$ \0 \u{...}`), exactly one codepoint
- [x] String literals — three forms:
  - [x] Plain `"..."`: `STRING_BEGIN`, alternating `STRING_PART` and `INTERP_OPEN..INTERP_CLOSE`, then `STRING_END`
  - [x] Raw `r"..."`: single `STRING_PART`, no escape processing, no interpolation
  - [x] Triple-quoted `"""..."""`: spans newlines, swallows the optional initial newline
  - [x] `${expr}` and `$ident` interpolation forms
  - [x] Nested interpolation via mode stack (`"a${"b${c}"}d"` works)
- [x] Operators table-driven — `..<`, `..=`, `==`, `!=`, `<=`, `>=`, `&&`, `||`, `<<`, `>>`, `->`, `=>`, `::`, `:=`, plus single-char ops and brackets
- [x] Newline emission rules per SPEC §3:
  1. [x] Suppressed inside unclosed `(`, `[` (NOT `{`, since blocks separate statements with newlines)
  2. [x] Suppressed after a pending binary/unary operator
  3. [x] Suppressed after `,`
  4. [x] Suppressed after `=`, `:`, `->`, `=>`
  5. [x] No backslash-continuation (stray `\` is `L0007`)
- [x] Diagnostic emission for: malformed numeric (`L0006`), unterminated string (`L0002`), unterminated block comment (`L0003`), invalid escape (`L0004`), invalid char literal (`L0005`), stray `\` (`L0007`), unexpected character (`L0001`), bad `\u{...}` (`L0009`), bad `${` (`L0010`)
- [x] Recovery: skip the offending byte / scan to next quote boundary, continue tokenizing
- [x] Tests: 60+ unit tests in `tests/lexer.test.ts`, covering each token family, every newline rule, every error path
- [x] Snapshot tests under `tests/snapshots/lexer/<scenario>/{input.vader,tokens.snap}` — driver in `tests/snapshot.ts`, scenarios: `hello`, `numerics`, `strings`, `interpolation`, `errors`

### 1.2 Parser

- [x] AST node types (declarations, statements, expressions, patterns, types) — `src/parser/ast.ts`
- [x] Top-level: `import`, `type`, `:: fn`, `:: struct`, `:: trait`, `T implements Trait`, decorators
- [x] Expressions: literals, identifiers, calls, field access, indexing, unary, binary (Pratt precedence table), if-expression, match-expression, lambdas, blocks, generic instantiation `Foo(T)` (as `CallExpr` at parse time), `expr?` postfix. Cast nodes are reserved in the AST but never emitted by the parser — `Type(value)` is parsed as a call and disambiguated later.
- [x] Statements: `:=` / `::`, assignments, `for` (infinite/while/in), `break`/`continue` (with labels), `defer`, `return`, expression-statements
- [x] Patterns: `is Type`, struct destructuring with bindings and literal constraints, wildcard `_`, guards (`if`)
- [x] Type expressions: primitives, named, unions (`A | B`), generic instantiation, function types (`fn(T) -> U`), postfix array `T[]`, tuple types `[T1, T2, ...]` (≥ 2 elements ; 1-tuples forbidden), parenthesised grouping `(T | U)[]`, nullability via union
- [x] Decorator parsing: `@name`, `@name(args)`
- [x] Generic syntax: bracketed type-params `fn[T, U: Bound](...)` / `struct[T: Hash + Eq]` ; `&` for trait composition (Layer 7e replaced the original `(T: type)` / `($N: i32)` / `where`-clause forms).
- [x] Error recovery: structured diagnostics via collector, never throws on user input; `syncToTopLevel` on bad decl; per-list progress guards prevent infinite loops on malformed input
- [x] Snapshot tests under `tests/snapshots/parser/<scenario>/{input.vader,ast.snap}` — scenarios: `hello`, `expressions`, `fn_decl`, `struct_decl`, `trait_impl`, `match_expr`, `errors`. Driver shared with the lexer (`tests/snapshot.ts`); `vader dump --stage=ast <file>` exposes the same pipeline through the CLI.

### 1.3 Resolver

- [x] Module loader: reads optional `vader.json`, discovers `.vader` files per module folder, supports both single-file modules (stdlib + `vader run foo.vader`) and folder modules (`src/resolver/{loader,module}.ts`)
- [x] Build a module graph; detect import cycles via DFS coloring (`R2005`)
- [x] Symbol tables per module, with scoping (builtins → std/core → module-level → fn type-params → fn params → block locals) — `src/resolver/{collect,resolve}.ts`
- [x] Resolve `import "std/io"` against the on-disk stdlib (filesystem-loaded for now via `vader.json.stdlib` or compiler-relative fallback). True embedding is a packaging step, deferred.
- [x] Resolve `./relative` (relative to the importing file) and bare `foo/bar` (project-rel via `vader.json` location)
- [x] Resolve `import ... { a, b }` destructuring (with `as` rename) and `import ... as fs` alias and bare-namespace `import "std/io"` (last segment as the local namespace name)
- [x] Reject `private` access across module boundaries: both the destructured form (`R2008` at wire-time) and the namespace form `mod.private_member` (`R2008` at field-resolution time)
- [x] Wire decorators (`@comptime`, `@extern`, `@export`, `@file`, `@test` recognized; unknown ⇒ `R2010`) and trait impls (`forType` resolved as a type, `traitName` resolved + checked to actually be a trait — `R2007`/`R2009`)
- [x] Snapshot tests: 8 scenarios under `tests/snapshots/resolver/<scenario>/{input.vader[, lib/...],resolved.snap}` — `hello`, `unknown_ident`, `namespace_import`, `alias_import`, `unknown_import`, `private_violation` (multi-module), `decorators_ok`, `unknown_decorator`. Driver dumps per-module symbol table + import resolutions + reference counts + diagnostics.
- [x] CLI integration: `vader dump --stage=resolved-ast <file>` exposes the same pipeline through JSON.

### 1.4 Type-checker

- [x] Type IR (`src/typecheck/types.ts`): `Primitive`, `Struct`, `Trait`, `Union`, `Fn`, `Array`, `TypeParam`, `TypeMeta`, `Unresolved`, `FreeInt`/`FreeFloat` (untyped numeric literals), `Never`. Structural equality, canonical `unionOf` (flatten + dedupe + sort), substitution.
- [x] Bidirectional inference engine — `inferExpr` (bottom-up) + `checkExpr` (with `expected`). No global Hindley-Milner. Top-level fn signatures must be fully annotated (`T3024`); lambda params/return inferred from call-site context. Free numeric literals adapt to their typed context (`let x: i64 = 42` works without a cast).
- [x] Generic type parameter handling: `$T` collected by parser, made visible as `TypeParam` symbols by the resolver, recognized in type expressions. Generic instances `Foo(T)` parse as type constructor calls; **monomorphization is deferred to phase 1.5** (comptime engine).
- [x] Trait satisfaction (`src/typecheck/impls.ts`): `ImplRegistry` indexes every `T implements Trait` block; queries used for `Display` (interpolation) and `Error` (`?` operator). Primitive impls resolved by name match. Union rule: a union satisfies a trait iff all variants do.
- [x] Type unification for `match` arms / `if`/`else` branches: arm types are joined via `unionOf` (so `if (c) "a" else 1` → `i32 | string`).
- [x] Narrowing in `match` arms: when the scrutinee is a plain identifier (param/local/binding), references to it inside an `is T -> body` arm see `T` instead of the original union — wired via a per-checker `narrowed: Map<symbolId, Type>` that `typeOfSymbol` consults first. `inferMatch` push/pops the narrowing per arm so nested matches stack naturally. Guards are checked under the narrowing too.
- [x] Match exhaustiveness: union scrutinees require every variant covered or a wildcard arm; non-union scrutinees require an explicit `_` wildcard (`T3013`).
- [x] Default integer/float: unsuffixed integer literals default to `i32` and floats to `f64` per SPEC §4. Both are `FreeInt`/`FreeFloat` until used in a typed context.
- [x] String interpolation type check: every `${expr}` is validated to satisfy `Display`. Primitives all impl Display per SPEC §9.
- [x] Operator resolution: native dispatch for primitive numeric arithmetic, comparisons, equality on primitives + string, logical ops on bool, bitwise ops on integers. **Trait-based operator dispatch (Add, Sub, Eq…) on user types is deferred** — `T3017` is emitted when a user type tries to use an arith/comparison operator without a native fallback.
- [x] Cast validity: `T(x)` parses as a CallExpr; if `T` resolves to a builtin numeric type, validated as a numeric → numeric cast (`T3010` otherwise). Struct constructors (`Foo(args)`) are accepted but not yet differentiated from generic instantiation — that gets resolved in 1.5.
- [x] `?` operator: scrutinee must be a union containing at least one Error-implementing variant; the enclosing function's return type must be able to absorb every Error variant (`T3011`/`T3012`).
- [x] Diagnostics: 26 codes `T3001..T3026` registered, all using the resolver-style `err()` helper for consistency (`src/typecheck/diag.ts`).
- [x] Snapshot tests: 10 scenarios under `tests/snapshots/typecheck/` — `hello`, `arith`, `if_branches`, `match_union`, `non_exhaustive_match`, `exhaustive_union`, `interp_display`, `try_op`, `unknown_field`, `bad_call_arity`, `bad_assignment`. Driver dumps decl types + per-expression types + diagnostics.
- [x] CLI integration: `vader dump --stage=typed-ast <file>` exposes the same pipeline as JSON.

**Deferred to later phases (tracked here for visibility):**
- Generic monomorphization (1.5 — comptime engine).
- Trait dispatch for operator overloading on user types.
- Per-binding type narrowing in `is T as x` patterns (the *binding* `x` currently has `Unresolved` type — scrutinee-symbol narrowing already works, but `as x` would need a resolver side-table from `IsPattern` to its binding symbol to apply the same `narrowed` map).
- Field-type substitution for generic struct instances (e.g. `List(i32).items` should be `[i32]`).
- Validation of `[T: Trait]` bounds against a concrete substitution at call sites.
- **Struct-level bounds enforcement** — `struct[K: Hash + Eq, V] { ... }` parses today but the typechecker doesn't enforce the bounds. Two follow-ups :
  (a) **Auto-inject the struct's bounds into every method whose receiver is that struct**, so `MutableMap`'s 8 methods don't have to repeat `[K: Hash + Eq]`. The bound enables trait-method dispatch (`.hash()`, `==`) inside the bodies — same machinery as the per-method bound today, just sourced from the struct decl.
  (b) **Validate the bound at the instantiation site** so `MutableMap[NoHash, i32]` errors immediately with a clear message instead of crashing later at the first `.put()` call. Hooks into the same "validate bounds at call sites" item above — same algorithm, applied at type construction.
  Effort: ~1–2 days of typechecker. Big DRY win on `std/collections.vader` (and any future generic-struct-with-bounds in user code).

### 1.5 Comptime engine + monomorphizer (split into MVP / deferred)

**Decision**: the TS implementation runs an **AST-walking interpreter**, not a bytecode VM. The bytecode VM (with its op table, encoding, stack-machine semantics) is built later in §1.7 alongside the C/WASM emitters; both backends and the comptime VM will share that final IR. Doing a custom VM now would force two rewrites — once when the op table changes in 1.7, and again at self-host time. The MVP covers what's actually needed to bake constants and register generic instances.

#### MVP (1.5a) — done

- [x] Comptime value IR (`src/comptime/value.ts`): tagged JS objects (`int`/`float`/`bool`/`char`/`string`/`null`/`void`/`array`/`struct`/`fn-ref`). Pretty-printer for diagnostics.
- [x] AST-walking interpreter (`src/comptime/interp.ts`): pure expressions (arith, comparisons, logic, bitwise), blocks, `if`/`else`, `let`, fn calls (with frame stack, `MAX_CALL_DEPTH = 64`), string interpolation (recursive eval), struct/array literals, field & index access. `return` is a `ReturnSignal` exception unwound at fn boundaries.
- [x] Sandbox (`src/comptime/sandbox.ts`): `@file(path)` reads project files relative to the calling .vader source; `@env(name)` gated by `--allow-env`; everything else is implicitly forbidden (the `callBuiltin` whitelist is the only path to host-side I/O at comptime).
- [x] `@comptime` evaluation pass (`src/comptime/evaluate.ts`): walks every module's top-level `ConstDecl`s, evaluates the ones bearing `@comptime`, records values in a side-table. The typed AST is never mutated; downstream phases consume the `EvaluatedProject` overlay.
- [x] `@file "path"` decorator: parses `@file("…")`, resolves the path relative to the source file, reads as UTF-8, replaces the const value.
- [x] Generic instance registry (`src/comptime/instances.ts`): walks every `Type` in `declTypes`/`paramTypes`/`typeExprTypes`/`exprTypes`/`localTypes` and records concrete instantiations (only when **every** arg is concrete — `Iterator($T)` inside the trait's own decl is excluded). Passive: 1.6 monomorphization reads this list to know which specialisations to materialise.
- [x] Minimal monomorphization pass (`src/monomorphize/`): produces a flat `MonoProject` where every non-generic top-level decl gets one entry and every concrete struct instance gets one entry with a `(typeParam → concrete-type)` substitution. Mangles names. Generic-fn dispatch isn't tracked yet (registry only observes struct/trait); when needed, this pass extends the same way.
- [x] Diagnostic codes `C4001..C4013` (registered in `src/diagnostics/codes.ts`); helper via the shared `makeErr` factory.
- [x] CLI: `vader dump --stage=evaluated-ast <file>` exposes the same pipeline as JSON.
- [x] Snapshot tests: 5 scenarios under `tests/snapshots/comptime/<scenario>/{input.vader,evaluated.snap}` — `simple_arith`, `square_call`, `interp_string`, `file_decorator` (with a sibling `data.txt`), `bad_div_zero`.

#### 1.5b — done (core + extensions)

- [x] Bytecode design — shared with §1.7 (no parallel op set; `src/bytecode/ops.ts` is the single source of truth).
- [x] Typed-AST → bytecode lowering for the comptime-eligible subset (`src/comptime/compile.ts`). Per-decl mini-pipeline: synthetic `__comptime_main` + lazily-compiled callees + `@file`/`@env` as VM imports. Scope mirrors the former AST-walker: arith / cmp / blocks / if / let / fn calls / interpolation (via builder intrinsics) / struct & array lit / field & index. Match/try/defer surface as `C4011`.
- [x] Stack-based VM as the comptime engine (`src/comptime/run.ts`). Reuses `src/vm/exec.ts`; `runFn` exposed so callers can capture the raw `Value` rather than the exit-code coercion. AST-walking interpreter (`src/comptime/interp.ts`) deleted.
- [x] Cycle detection across @comptime decls — DFS coloring in `src/comptime/deps.ts`; cyclic decls are excluded from the evaluation order and surface as `C4009` with the cycle path (`A → B → A`). Snapshot `tests/snapshots/comptime/cycle/`.
- [x] Recursive @comptime evaluation — topological sort in `planComptimeOrder` so `@comptime A :: 10`, `@comptime B :: A * 2`, `@comptime C :: A + B` evaluate in order. Snapshot `tests/snapshots/comptime/cross_decl/`.
- [x] Generic-fn instance registry surface — `InstanceRegistry.observeFnCall(sym, typeArgs)` plus a typed-AST walker over `GenericInstExpr` that records explicit `Foo(T1, T2)(...)` call sites. Mono+lower+emit for fn-instances stay deferred (see below).

**Deferred to later phases:**

- [x] **Mono+lower+emit for fn instances** — done. `monomorphizeProject` (`src/monomorphize/index.ts:104`) materialises one `MonoEntry` per `(generic FnDecl, concrete typeArgs)` observed via `observeFnCall`, indexed in `fnInstanceEntries`. The lowerer (`src/lower/passes/expr.ts:345 lookupFnInstance`) routes both direct calls (`identity(42)`) and UFCS calls (`42.identity()`) to the specialised symbol. Tests: `tests/snippets/generic_fn/`, `generic_eq/`. Open sub-item: explicit `foo(T)(args)` syntax — `GenericInstExpr` is declared in the AST but never produced by the parser; inference covers the common case.
- [x] **Inferred generic-fn type args** — done. `genericFnCalls: Map<CallExpr, typeArgs>` is populated by the typechecker for both direct and UFCS calls; `observeFnCall` reads it in `evaluate.ts:220-232`. Lowerer reuses the same map.
- [x] **Generic impls** (`ArrayIterator(T) implements Iterator(T)`) — done. Mono materialises one entry per `(impl member, struct args)` via `implMethodEntries: Map<FnDecl, Map<argsKey, MonoEntry>>`. Resolver shares typeParam symbols cross-module (via `typeParamSymbols`) so an impl in std/core can reuse the base struct's typeParam without clobbering. Lowerer's UFCS dispatch + Iterator lookup pick the right specialisation by struct args.
- [x] **`std/iter` combinators** (`map / filter / take / skip / fold / sum / count / collect`). Both flavours now ship: the **eager `T[]`-driven** form (`tests/snippets/iter_combinators/`) and the **lazy struct-wrapping** form (`MapIterator` / `FilterIterator` / `TakeIterator` / `SkipIterator`, snippet `tests/snippets/iter_lazy/` — 2026-05-11). Iterator-fn-helper flavour `map(it: Iterator(T), f) -> Iterator(U)` deferred : generic-fn inference on a trait-typed parameter still traps (see §3.x trait-object boxing entry) ; users construct the lazy struct directly via struct literal in the meantime. The unrelated default-init gate (next item) still blocks the `sum(it)` / `min(it)` iterator-driven *single-value* variants.
- [x] **`for x in iter` on a trait-typed receiver + UFCS dispatch to a trait-typed first param** (2026-05-14). Two wins land together :
    - `lowerForIn` (`src/lower/passes/for-in.ts:62`) recognises when `iter` has trait type `Iterator(T)` (rather than a concrete `Range[T]` / `ArrayIterator[T]` / user struct) and emits a `LoweredVirtualCall` for `next()` instead of looking up a static impl. The static-impl path stays for concrete receivers ; both share the rest of the step-loop scaffold.
    - `rankOverloadsByFirstParam` (`src/typecheck/passes/field.ts:265`) gained a Trait-first-param branch : when the receiver implements the trait (via `impls.findFor` for struct/primitive/enum, or the built-in `T[]` → `Iterator(T)` widening), the candidate is classified as a `symMatch`, weaker than concrete `isAssignable` but stronger than `intoMatch` / wildcard. Unification of the trait's type-params against the concrete receiver was already handled by `unifyTraitParamWithConcrete` ; this just stops `rankOverloadsByFirstParam` from skipping the candidate up front.
    - Together they unlock `source.chars().filter(is_bf_char)` and similar `recv.method(...)` chains where the method takes `Iterator(T)`. Eager iterator-fn overload added to `std/iter` : `filter(it: Iterator(T), pred) -> T[]`. Snippet `tests/snippets/for_in_iter_trait/`. `tests/snippets/trait_box_range_iter/` still uses the manual `match it.next()` shape — equivalent semantics, narrower scope. Lazy chain returning another `Iterator(U)` still deferred (needs the dispatch to flow through struct-wrapped lazy iterators with type-param inference closing over the inner element type).
- [ ] **`std/iter` short-circuiting combinators** (`any` / `all` / `find` / `find_map`). Today's `stdlib/std/iter.vader` ships only the non-short-circuiting family (`map` / `filter` / `fold` / `take` / `skip` / `sum` / `count` / `collect` / `zip` / `chain` / `enumerate` / `flat_map`). Predicate-search shapes like `arr.any(p)` / `arr.all(p)` / `arr.find(p) -> T | null` recur every time a loop "stop on first match" is what the caller wants ; today the only options are a hand-rolled `for ... if return true` loop (cf. `vader/vm/exec.vader:union_matches`, every `arr.contains(x)`-style call site) or `fold` (loses early-exit). Surface area is small : 4 fns, each ~5 lines of body, both eager (`T[]`) and lazy (`Iterator(T)`) flavours. `arr.find(p)` now returns a `T | null` that consumers can narrow naturally via the flow-narrowing landed in §1.13e.
- [x] **Transitive monomorphization** — done. `closeOverGenericImpls` (`src/comptime/evaluate.ts:253`) runs a fixed-point loop (max 64 iters) that, for each registered struct/fn instance, observes (a) the substituted types of every impl member, (b) every nested generic call site inside fn bodies (`observeFnBody` substitutes the outer subst into inner typeArgs before re-feeding the registry). Wrapper-style stdlib (`MutableSet(T) { inner: MutableMap(T, bool) }`) compiles end-to-end (`tests/snippets/mutable_set/`).
- [x] **First-class trait-method dispatch** — done. Three call shapes now resolve through the same ImplRegistry plumbing: (a) bounded type param (`fn count_matching[T: Hash & Eq](items: T[], target: T)` — recorded in `traitMethodResolutions`, `tests/snippets/trait_dispatch_bounded/`); (b) non-generic trait receiver (`e: Error; e.message()` — recorded in `traitVirtualResolutions`, lowered via `lowerVirtualDispatch` into an `is X -> X_method(box)` cascade, `tests/snippets/trait_virtual_dispatch/`); (c) **generic trait receiver** (`it: Iterator(i32); it.next()` — typechecker substitutes the trait's typeParams into the method's return type so `Yielded($T)` becomes `Yielded(i32)`; lowerer enumerates every observed `(generic struct, args)` instance from `mono.implMethodEntries` and emits one arm per concrete struct, `tests/snippets/trait_dispatch_generic_iter/`).
- [ ] **Default-init for generic param** — `acc: T = T()` style, needed by `sum(it)` over an iterator. Either a `Default` trait + auto-impl on numerics, or a `zero<T>()` intrinsic. Currently blocks the iterator-driven flavour of `sum`, `min`, `max`.

  Investigation 2026-05-09 (re-checked post-`where`-removal) : Vader requires every type-param to appear at least once in the parameter list (it's the declaration site) — `fn make_default[T: Default]() -> T` errors out because `T` doesn't appear in any value-arg position. So a parameter-less generic constructor isn't expressible today. Two viable resolutions, in increasing scope :

    (a) **Explicit type-args at call sites** — `default[T]()` / `foo[T1, T2](args)`. The AST node `GenericInstExpr` is already declared but never produced by the parser. Adding the syntax + typecheck + lower routing is ~2-3 days.

    (b) **`T()` constructor syntax for type-params** — sugar for `Default::default()` instantiated with T. Most user-facing but most invasive : parser learns to recognise `<TypeParam>()` ; typecheck dispatches via the bounded-trait-param infrastructure ; lowerer routes to the right impl based on the call-site monomorphisation. ~3 days.

  Recommendation : start with (a) — it's a useful follow-up regardless and unblocks `default[T]()`. (b) is sugar that can come last.

  The `Default` trait itself can be added now as a placeholder (no-op until one of the above lands) but doing so without a dispatch path adds complexity for no immediate user benefit — defer until (a) is implemented.
- [ ] **Generic `len(arr)`** — today `ArrayIterator` carries an explicit `length: i32` field set at auto-wrap time via `LoweredArrayLen` (the bytecode `array.len` op). Now that generic-fn dispatch is in, the field could be dropped in favour of `len(self.arr)` — pure cleanup, low priority.
- [x] **Auto-coerce `T[]` → `Iterator(T)`** — done. Now goes through the blanket `T[] implements[T] Into(Iterator(T))` declared in `std/core` ; the original `arrayIterCoercions` side-table + `wrapArrayAsIter` lower helper (for the coerce path) were retired in commit `801f423`. `wrapArrayAsIter` survives only for the native `for x in arr` syntax. The Into mono pipeline materialises the `into` member per element-type, the lowerer wraps coercion sites via `wrapAsInto`. Test: `tests/snippets/iter_coerce_array/`.
- [ ] `for x in iter` / `MutableList(u32){}.add(...)` inside @comptime — needs arena allocation for transient collections (Iterator dispatch is now solved).

### 1.6 Lowerer — done

Per SPEC §2 ("Lowered AST"), the lowerer consumes the post-mono typed AST and emits a separate, smaller IR (the *Lowered AST*) where high-level constructs are desugared into a fixed core. Lives under `src/lower/`. Runs `monomorphize` first, then walks each `MonoEntry`'s body.

- [x] Dedicated lowered AST (`src/lower/lowered-ast.ts`) — separate node tree, every value-bearing node carries its concrete `Type`. No `MatchExpr`, no `TryExpr`, no `DeferStmt`, no string-interpolation parts; adds `LoweredTypeCheck`, `LoweredIntrinsicCall`, `LoweredUnreachable`.
- [x] Pattern match → naive if/else chain over `LoweredTypeCheck` and equality predicates (no decision-tree compilation in MVP). Bindings introduced by `is T as x` and struct destructuring become plain `let`s at the head of the arm body. A trailing unreachable arm guards against non-exhaustive scrutinees that slipped past the typechecker.
- [x] `expr?` → `let __try = inner; if (__try is <error variants>) return __try else cast(__try)`. Error variants are taken from the inner type's union, filtered by `ImplRegistry.hasUser` / `forPrimitive` against the core `Error` trait. The trait type itself counts as an error variant (so `string!` ⇒ `Error | string` works without an explicit struct impl).
- [x] String interpolation → block of `@builder.new` / `@builder.append_str` / `@builder.append_display` / `@builder.finish` intrinsic calls. Each `append_display` carries the static type of the interpolated value so the bytecode emitter can later route to the right `Display::show` impl.
- [x] `defer` → physical duplication at every textual exit of the declaring block. Per-block defer stack, LIFO. Exits handled: implicit fallthrough (with trailing-expr saved to a `__block_<n>` temp), `return` (defers from current block up through the fn root), `break`/`continue` (defers from current block up through the innermost loop body). Stmts after a `return`/`break`/`continue` are dropped as unreachable. Panics do not unwind.
- [x] Trait calls → static dispatch via UFCS. `obj.method(args)` parses as `FieldExpr(obj, method)` then `CallExpr`; when the field name doesn't match a struct field, the typecheck queries `ImplRegistry` for a matching method on `obj`'s type, records a `MethodResolution` side-table entry, and types the call against the method's bound fn type (self dropped). The lowerer reads the side-table and rewrites the call into a direct `LoweredCall` of the impl's specialised fn with `obj` as the first arg. The mono pass synthesises a `fn` Symbol per impl member so existing `LoweredIdent → fnIndexBySymId` plumbing works uniformly. Generic impls (`Foo(T) implements Trait(U)`) stay deferred — see §1.5b iterators below.
- [x] No inserted runtime checks (no bounds checks, null checks, division/overflow guards) — left to the runtime / out of MVP scope.
- [x] Pipeline integration: `pipelineLowered` in `src/pipeline.ts`; `vader dump --stage=lowered-ast <file>` exposes the same pipeline as JSON.
- [x] Snapshot tests: 7 scenarios under `tests/snapshots/lower/<scenario>/{input.vader,lowered.snap}` — `hello`, `arith`, `if_branches`, `match_union`, `interp_string`, `try_op`, `defer_block`.

**Deferred to later phases:**

- [x] **Lambda lifting (closure conversion).** Done — implemented in `src/lower/passes/lambda.ts` + `src/closures/analyze.ts`. Free-variable analysis runs between typecheck and lower; each `LambdaExpr` is lifted to a synthesised top-level fn that takes the env as its first parameter, captured locals are heap-promoted into `$Cell_T` single-slot structs (so capture-by-reference semantics hold across closures), and the original site lowers to `LoweredMakeClosure(env_struct_lit, lifted_fn)`. Snapshots : `tests/snippets/closure_simple/`, `closure_counter/`, `closure_shared/`, `closure_callback/`.
- [x] **`RangeExpr` + `T[]` arrays lowered via `Iterator` dispatch.** `0..<n` / `0..=n` lower to `Range { .start, .end, .inclusive, .cursor=0 }` struct literals; raw arrays in `for x in arr` auto-wrap into `ArrayIterator(T) { .arr, .cursor=0, .length=array.len(arr) }`. `for-in` desugars to a pull-loop dispatched through the `Iterator(T)::next` impl on the iter's static type — the range and array fast-paths are gone. `Range`, `Done`, `Yielded(T)`, `Iterator(T)`, and `ArrayIterator(T)` live in `std/core` (the trait uses the sum-type variant `Done | Yielded(T)` to avoid the `T | null` sentinel collision for lists whose element type can be `null`). Generic impls (`ArrayIterator(T) implements Iterator(T)`) materialise per concrete struct args via the mono pass: pass 1 emits non-generic impl members, pass 2 emits one entry per `(impl member, struct args)`. Snapshots: `tests/snapshots/vm/for_range/` and `tests/snapshots/vm/array_iter/`.
- [ ] Per-binding type narrowing: `is T as x` patterns currently rely on `LoweredCast` because the typechecker leaves the binding's symbol type at `Unresolved`. Once finer-grained narrowing lands (typecheck deferred item), the lowerer can drop the cast.
- [ ] Match decision-tree compilation (Maranget-style). Naive linear chains are good enough for MVP; revisit if perf or code size become an issue.

### 1.7 Bytecode emitter — done

Stack-based, WASM-aligned op table; structured control flow (`block`/`loop`/`if`/`else`/`end` + relative `br`/`br_if`); per-fn locals model. Lives under `src/bytecode/`.

- [x] Op table (`src/bytecode/ops.ts`) — typed primitives (`i32.add` … `f64.div`, `eq`/`ne`/`lt`/`le`/`gt`/`ge` per width, `bitand`/`bitor`/`bitxor`/`shl`/`shr`/`bitnot` for ints, `*.neg`, `*.to_*` numeric conversions), constants (`i32.const`, `i64.const`, `f32.const`, `f64.const`, `bool.const`, `char.const`, `null.const`, `string.const <pool-idx>`), locals (`local.get`/`local.set`/`local.tee`), structured control (`block`/`loop`/`if`/`else`/`end`, `br`/`br_if`/`return`/`unreachable`), calls (`call <fn>`/`call.import <imp>`/`intrinsic <id>`), GC ops (`struct.new`/`struct.get`/`struct.set`, `array.new`/`array.get`/`array.set`/`array.len`), and Vader-specific `type_check <T>` and `ref.cast <T>`.
- [x] Type table (`src/bytecode/types.ts`) — primitives, structs (with field types), arrays, unions (variant indices), open refs (for opaque traits). Indexed; deduped on insertion via `displayType` keying.
- [x] String literal pool — interned during emission, indexed.
- [x] Function table + import table + export table. Function indices are resolved through symbol IDs so `call`/`call.import` see the right slot regardless of declaration order. `@extern` and signature-only fns route to imports; `@export` populates the exports section.
- [x] Intrinsic table (`INTRINSIC_TABLE` in `ops.ts`) — stable IDs for `builder.{new,append_str,append_display,finish}`. Append-only; never reuse.
- [x] Debug info — per-op `(file, line, column)` side-table on each `BcFunction`. Survives the round-trip via `; file:line:col` annotations in `.vir`.
- [x] Two-pass emission (`src/bytecode/emit.ts`): pass 1 reserves indices for fns/imports/consts and interns struct decls eagerly; pass 2 emits each fn body with WASM-style label-stack tracking for `br`/`br_if` depth.
- [x] Short-circuit `and`/`or` lowered to structured if/else (so user-side `&&`/`||` semantics are preserved even though the lowerer keeps them as plain Binary).
- [x] CLI: `vader dump --stage=bytecode <file>` prints the `.vir` text of the lowered project.
- [x] Snapshot tests: 7 scenarios under `tests/snapshots/bytecode/` reusing the lowerer's `input.vader`s. Each snapshot is the `.vir` text plus a `; round-trip OK/MISMATCH` banner asserting `parse(write(m))` is a fixpoint.
- [x] Bytecode peephole pass (`src/bytecode/peephole.ts`) — single linear scan, gated on `EmitOptions.optimize` (default `true`, CLI flag `--no-bytecode-opt`) :
  - `local.set N; local.get N` → `local.tee N` (129 hits / 60 % of `local.set` on the test corpus)
  - `<num>.<cmp>; bool.not` → `<num>.<inverse cmp>` (uses inverse-verb table)
  - `bool.const X; bool.not` → `bool.const !X`
  - `bool.not; bool.not` → ε
  - Aligns the IR with WASM-idiomatic shapes for the future WASM backend.

**Deferred to later phases:**

- [ ] Slot reuse (live-range analysis) — every let currently gets a fresh slot. Acceptable for MVP; revisit if the C/WASM emitters need tighter footprints.
- [x] **First-class function values (closures, function pointers).** Done — `fn(T1, ...) -> R` is a primitive type usable in any type position. New bytecode ops `fn.ref { fnIndex, typeIndex }`, `call.indirect { typeIndex }`, `make_closure { fnIndex, typeIndex }`. Runtime representation : `vader_fn_t { header, code, env }` fat pointer; non-capturing globals carry `env=NULL` and route through a small generated trampoline so the same indirect-call path handles both globals and closures uniformly. Snapshots : `tests/snippets/fn_value_local/`, `fn_value_arg/`, `fn_value_struct/`, `fn_value_array/`.
- [ ] `@comptime` evaluation via the bytecode VM — comptime still uses the AST-walking interpreter; sharing the op table is now possible (1.5b).

### 1.7b IR text emitter / reader (`--target=ir`) — done

Line-oriented, one op per line, header sections for `module` / `type` / `string` / `import` / `export`. Round-trip is a fixpoint by construction.

- [x] `.vir` grammar (`src/bytecode/text.ts`):
  ```
  module <name>
  type <i> <kind> <args…>            ; primitive | struct | array | union | ref
  string <i> "<json-quoted>"
  import <i> <extern> <mangled> (<params…>) -> <result>
  export <extern> <fnIndex>

  fn <i> <name> (<params…>) -> <result>
    local <name> <valType>
    <op> [<operands…>]   ; <file>:<line>:<column>
    …
  end
  ```
- [x] `BytecodeModule → .vir` serializer (`writeVir`).
- [x] `.vir → BytecodeModule` parser (`parseVir`). Tolerates inline `; …` comments on every line; preserves debug annotations.
- [x] Round-trip fixpoint: serialize → parse → re-serialize is byte-identical for all 7 snapshot scenarios. The snapshot driver embeds the round-trip status as a banner so a regression surfaces in the diff.
- [x] CLI: `vader build --target=ir <file>` writes the `.vir` next to the source (or to `--out=<path>`).

**Deferred to later phases:**

- [x] `vader run program.vir` — wired in §1.8: the run command detects `.vir` and calls `parseVir` → `runProgram` directly, no re-parsing of the source.
- [ ] Manifest mode (`vader build --target=ir --manifest`) — single-file mode is wired today; multi-module projects come when the build pipeline learns to merge bytecode modules.

### 1.7c Bytecode format refresh

Today's `.vir` is textual-only despite the name and lacks any header — the first
line is just `module <name>`, no magic number, no version. The format predates
the midir refactor and mimics WASM's structured control flow (`block`/`loop`/
`if`/`else`/`end` + `br <depth>`) even though the VM and C-emit don't need that
shape.

**Two-format split (#1 — done)**

- [x] Renamed the textual format to `.virt`. CLI : `vader build --target=ir-text` writes `.virt`, `vader run` sniffs by extension. Snapshot tests follow.
- [x] Binary `.vir` format alongside (`src/bytecode/binary.ts`, ~720 lines). Header layout :
      ```
      magic     "VADR"  (4 bytes : 0x56 0x41 0x44 0x52)
      version   u32     (BYTECODE_VERSION = major<<16 | minor<<8 | patch ; today 0.1.1, hard error on mismatch)
      flags     u32     (FLAG_HAS_DEBUG = 0x0001 ; rest reserved)
      ```
      Followed by 9 length-prefixed sections : moduleName, types, strings, imports, exports, vtables, implTable, debugFiles, functions. Multi-byte ints little-endian ; strings u32-prefixed UTF-8 ; ValType is a 1-byte tag against `VAL_TYPES` ; op kinds are a u16 tag against `OP_KINDS`.
- [x] Both formats round-trip the same `BytecodeModule`. Verified : `vader build hello.vader --target=ir --out=hello.vir && vader run hello.vir` ✓ ; same with `--target=ir-text` → `.virt`.
- [x] CLI : `--target=ir` defaults to binary `.vir` ; `--target=ir-text` writes `.virt`. `vader run` accepts `.vader` / `.vir` / `.virt` (extension-sniffing in `src/cli/commands/run.ts:16-17`).
- [~] Header flags worth carrying : `has_debug_info` (`FLAG_HAS_DEBUG`) ✓. `target = native | wasm | vm-only` and `module_id` (content hash for incremental cache later) deferred — picked up when the WASM emitter / cache work lands.

**"Plus IR-like" — open architecture question (#2 — discuss before coding)**

The current bytecode is stack-machine WASM-style. Midir is CFG/SSA. Three
variants on the table, in increasing ambition :

  (a) **Drop the WASM mimicry, keep stack-machine.** Replace `block`/`loop`/
      `if`/`else`/`end` + `br <depth>` with `goto label` + `branch_if cond
      label`. The current structurizer in `midir/emit.ts` becomes redundant
      for VM/C-emit ; only the future WASM emitter would re-structure. ~3-4
      days. Saves ~200 lines, makes VM/C-emit more direct.

  (b) **Bytecode adopts midir's CFG shape.** Op set keeps arithmetic ops, but
      control flow is `BasicBlock { instrs, terminator }`. VM consumes a CFG
      ("step until next terminator"). C-emit emits one C label per block.
      ~1-2 weeks. Cleaner than (a), touches the VM.

  (c) **Promote midir directly — bytecode and midir merge.** `BytecodeModule`
      becomes `IRModule` (CFG/SSA-ready). The `.vir` serialises the CFG. No
      separate bytecode layer. ~2-3 weeks. Most radical, eliminates the dual-
      maintenance burden.

Bias before discussion : (a) is a fast win that keeps options open ; (c) is
the right long-term destination. (b) is an awkward intermediate. **Do not
implement until we've discussed the trade-offs at the architecture level.**

**Related verdict — LoweredAST ↔ CFG seam (decided)**

Companion question : should `LoweredAST` remain a distinct IR, or should
lowering emit `BasicBlock`/`Instruction`/`Terminator` directly ? Decision
captured in `plans/polymorphic-purring-spark.md` — **keep LoweredAST
distinct**. Rationale : tree rewrites (match/try/for-in/range desugar) are
cleaner over expression trees ; `midir/build.ts` is a thin, cheap-to-maintain
seam ; realistic line savings from a merge are ~250-400 (not the 1500
headline). The cheap seam-tightenings *were* done in May 2026 :
hoisted reserveDecl metadata onto `CFGFunction`, dropped const decls at
lowering time via `inline-consts` pass, replaced `LoweredStructDecl`
pass-through with `CFGStructDecl` so the CFG is self-contained on its
decl side. Reopen the merge question only when : §1.7c (above) ships, a
second CFG consumer appears without a corresponding Lowered consumer, or
a new desugar pass naturally wants CFG shape (e.g. async/yield).

### 1.8 VM (interpreter mode for `vader run`) — done

Stack-based bytecode VM consuming the `BytecodeModule` produced by §1.7. Lives under `src/vm/`. The TODO line "reuse the comptime VM" is superseded by the §1.5a decision (the comptime engine stays AST-walking until self-host; the bytecode VM is the new shared moteur, and migrating comptime onto it is tracked separately under 1.5b).

- [x] Tagged value model (`src/vm/value.ts`) — every value carries its runtime tag (`i32`/`i64`/`bool`/`string`/`struct`/`array`/`null`/`error`/…). Avoids needing explicit box/unbox ops in the bytecode for primitives flowing through `ref` slots (union variants).
- [x] Stack-based interpreter (`src/vm/exec.ts`): structured control flow (`block`/`loop`/`if`/`else`/`end` + relative `br`/`br_if`) with per-frame label stack and pre-computed `open → end` / `if → else` / `else → end` jump tables. Calls push fresh frames; `return` collapses them; intrinsics dispatch inline. `type_check` matches by primitive tag, struct typeIndex, union variants (recursive), and a heuristic for trait refs (`Error` matches `error` sentinels + struct names containing `$Trait$`). `ref.cast` is a runtime no-op (the tag carries the type).
- [x] Host bindings (`src/vm/host.ts`) — I/O imports backed by `HostIO` (process.stdout/stdin + Node fs by default; injectable for tests). `std/io` resolutions: `print`/`println`/`read_line`/`read_file`/`write_file`/`exists`. Imports keyed by `mangledName` (`std_io$println`, etc.) for unambiguous resolution.
- [x] CLI integration (`src/commands/run.ts`): `vader run file.vader` (full pipeline → VM) and `vader run file.vir` (parse → VM). Compile diagnostics flushed to stderr; error-severity diagnostics gate execution. Friendly error on missing file / `VmError` traps.
- [x] Snapshot tests: 7 scenarios under `tests/snapshots/vm/<scenario>/{input.vader[, fixtures...], stdout.snap}` — `hello`, `arith`, `interpolation`, `loop`, `match_union`, `defer`, `try_op`. Driver uses an in-memory `HostIO` that captures stdout/stderr but routes file ops to disk so fixture files (e.g. `try_op/data.txt`) work.

**Deferred to later phases (tracked here for visibility):**

- [ ] **REPL.** Persisting the symbol table between lines requires incremental compilation across resolve/typecheck/comptime/lower/emit. Substantial chantier on its own; punt until after the C/WASM emitters land.
- [ ] **Real impl table for trait `type_check`.** Today's heuristic (`Error` matches struct names containing `$Trait$`) covers the host-driven I/O scenarios. A user-defined struct `Foo implements MyTrait` won't match `type_check MyTrait` in the VM until the bytecode emitter materialises an impl-table side-section. Picked up alongside generic-fn dispatch (1.5b).
- [x] **Comptime migration.** Done in §1.5b — `@comptime` decls now run on the bytecode VM via `src/comptime/{compile,run}.ts`.
- [ ] **Slot-typed numeric promotion.** `local.tee` followed by use through differently-sized typed ops works because the VM tag carries the canonical type, but the bytecode emitter can produce ops whose op-type disagrees with the value tag (e.g. an `i32.add` on values that flowed in as `i64`); we currently trust the emitter. Add a debug-only verifier when the WASM target lands (it'll need exactly this validation).

### 1.9 C emitter (Iter-ready cut) — done

`BytecodeModule → C source → cc → native binary`. Lives under `src/c_emit/` + `runtime/c/`.

- [x] Runtime C surface (`runtime/c/vader.h` + `vader_runtime.c`) — fat-value strings, tagged `vader_box_t` for unions/refs, `vader_array_t` (uniformly boxed elements), `vader_obj_header_t` for structs, builder intrinsics (per-type `append_display_*`), I/O (`print/println/read_file/write_file/read_line/exists`). Allocator is `malloc` (leak — 1.11 will swap in mark-sweep behind the same surface).
- [x] Type representation (γ): primitives stay primitive (`int32_t`, `vader_string_t`, etc.); struct/array via `void*`/typed pointer; union and `any` slots use `vader_box_t`. Box/unbox happens at slot-crossing boundaries via the emitter's `coerce` helper. Primitive-tag-of map maps each `ValType` to its BcType index in the module so boxed values carry the right tag for `type_check` round-trips.
- [x] C emitter (`src/c_emit/emit.ts`) — bytecode → C: forward decls, struct decls, string pool literals, import shims (with `std/io` mapped to runtime fns), function bodies. Stack-based bytecode lowered via tmp-var-per-push (`tN = ...`) with a parallel TS-side stack tracking `(name, ValType)` for coercion. Structured control (`block`/`loop`/`if`/`else`/`end`) uses C labels + `goto` (`loop_<n>` / `end_<n>`) with per-scope result tmp (`blockres_<openIp>`). The active-scope stack lives on `FnState`.
- [x] Imports — `std/io` routes to `vader_*` runtime fns. Tag-aware fns (`read_file`, `write_file`, `read_line`) receive the `string` and `Error` BcType indices as parameters so the runtime stays tag-agnostic. Foreign `@extern` imports get a stub that traps; user-supplied object linkage is post-MVP.
- [x] CLI (`vader build <file> --target=native [--out=<out>]`) — emits the .c into a temp dir, invokes `cc -std=c11 -O0 -I runtime/c <prog.c> runtime/c/vader_runtime.c -o <out>`. Compile errors surface verbatim with the temp .c path so the user can inspect.
- [x] Tests — `tests/native.test.ts` builds every `tests/snapshots/vm/<scenario>/input.vader` to a binary, runs it, compares stdout/stderr/exit against the VM snapshot. 8 scenarios in parity (hello, arith, loop, interpolation, match_union, defer, for_range, try_op). Test silently skips when `cc` is unavailable.

**Deferred (1.9b):**

- [ ] `#line` directives for gdb/lldb debugging.
- [ ] Manifest mode (`vader build --target=native --manifest`).
- [x] Optimisation flags — `--release` flag (2026-05-07) flips `cc` from `-O0 -ggdb` (debug default : full DWARF, asserts on, fast iterative builds) to `-O3 -DNDEBUG` (production : no debug info, asserts off) + best-effort post-link `strip`. `strip` failure is swallowed silently so Windows hosts without binutils still produce a valid (just larger) binary. `-flto` deferred until profiling shows it matters.
- [ ] Stable ABI for `@extern` user imports (today: stubs trap).
- [ ] i32/i64 overflow handling per SPEC §4 (panic in debug). Currently wraps silently (matches "release" semantics).
- [x] **Unbox struct field read after `is StructTy` pattern match.** Closed — `tests/snippets/map_set_iter/_main.vader` builds and runs natively today : `map_sum=6` / `set_sum=60` match the VM snapshot, and the generated C unboxes `Entry.value` to `int32_t` before the `total + entry.value` add (`int32_t t15 = ((vader_struct_…_Entry__string__i32_t*) t14.payload.obj)->f_value;`). `tests/native.test.ts` now actually exercises the snippet (`tests/snippets/map_set_iter/native` binary present and re-runnable).
- [x] **`--cc=<path>` flag** (2026-05-10). `vader build --target=native --cc=<path>` overrides the C compiler ; `CC` env var is a lower-priority fallback ; `"cc"` remains the default. Output picks up `.exe` automatically when the compiler triple ends in `mingw32-(gcc|cc|g++)`. Post-link `strip` follows the same toolchain (e.g. `x86_64-w64-mingw32-strip`). Manifest-side option (`vader.json` `build.cc`) deferred — surface need first.
- [x] **Windows cross-compile via mingw-w64 + Wine** (2026-05-10). `runtime/c/vader_runtime.c` now compiles cleanly under `x86_64-w64-mingw32-gcc` — POSIX-only spawn block (`<spawn.h>`, `<sys/wait.h>`, `<unistd.h>`, `posix_spawnp`, `waitpid`) bracketed by `#ifdef _WIN32` ; the Windows branch implements `vader_spawn_run` via `CreateProcess` + `CreatePipe` + two `CreateThread` drainers + `WaitForSingleObject` + `GetExitCodeProcess`. Argv quoted per `CommandLineToArgvW` round-trip rules (backslash-doubling before quotes). NTSTATUS abnormal-termination codes (`0xC0000000+`) map to `VADER_SPAWN_SIGNALED`. Verified end-to-end : `hello.vader`, `fizzbuzz.vader`, `primes.vader`, and a `std/process.spawn(["cmd", "/c", "echo", ...])` snippet all run correctly under Wine. Still deferred : (a) `tests/native.test.ts` `WINE=1` mode for automated parity ; (b) Unicode (`CreateProcessW` + UTF-16 conversion) — ASCII paths only today ; (c) `clang`/`cl` autodetection on native Windows hosts.

### 1.10 WASM emitter — moved to Phase 3 (§3.10)

WASM emission is no longer part of the MVP cut. See §3.10 for the deferred plan.

### 1.11 C runtime

- [x] **GC**: hand-written **Cheney semi-space copying GC** (`runtime/c/vader_runtime.c`). Two arenas (16 MB default, configurable via `VADER_GC_ARENA_BYTES`); allocation is bump-pointer (`vader_gc_alloc`); collection copies live objects via the standard Cheney scan + forwarding-pointer pattern; arenas swap on cycle end. Roots are enumerated **precisely** via a shadow stack — every emitted C function declares a `vader_gc_frame_t` chained through `vader_gc_top` whose `ptrs[]` array holds the addresses of the function's ref-typed locals (forced onto the C stack by the address-take). Per-type pointer maps (`vader_type_info_table`) emitted by the C-emit tell the scanner where the heap pointers live inside each object. The mark-sweep stop-the-world plan was abandoned in favour of Cheney on 2026-05-06 — same complexity (~500 LoC) but bump-allocation is far faster and the precise-roots discipline opens the door to a generational GC later. Stress tests : `tests/snippets/gc_chain_survive/`, `gc_multi_collect/`.
- [x] **Arrays GC-tracked** (Phase 2.6b/c). `vader_array_t` carries a `vader_obj_header_t` with `kind=ARRAY` and a single ref to a separately-allocated `vader_array_buf_t` (kind=ARRAY_BUF, sentinel type-index `0xFFFFFFFE`). The Cheney scan loop dispatches on the sentinel to walk `length` slots dynamically; the buf's size is read from its own `capacity` field at copy time. `vader_array_new` allocates struct + initial buf in a single block (no orphan window mid-construction); `vader_array_push` resolves `a` against its forwarding pointer if a collection fired during the fresh-buf alloc. Stress test : `tests/snippets/gc_array_survive/`.
- [x] **Strings off the GC arena** (Phase 2.6a). String char buffers (`concat`, `to_upper/lower`, `parse_int/float`, `read_line`, `read_file`, builder buf) now `malloc` outside the GC arena via `vader_string_alloc`. Strings stay value types `{ptr,len}` passed by copy; tracking those copies through the moving GC would require a header lookup per char-ptr scan and isn't worth it for immutable values. Trade-off : strings leak for the program's lifetime — fine for the MVP; revisit when long-running self-hosted compilation needs reclamation.
- [ ] String runtime: allocation, concat, length, char iteration
- [ ] Array runtime: allocation, indexing with bounds check, clone
- [ ] StringBuilder support
- [ ] libc-backed I/O glue for `std/io`
- [ ] Panic handler: prints diagnostic, aborts

### 1.12 CLI

- [ ] `vader run <file>` (and bare `vader` for REPL)
- [ ] `vader build <file>` (single-file mode if `main` is present)
- [ ] `vader build` (manifest-driven mode, reads `vader.json`)
- [ ] `vader build --target=wasm` — moved to Phase 3 (§3.10).
- [ ] `vader build --target=ir` — emits `.vir`
- [x] `vader test [path]` — discovers and executes `@test` functions (2026-05-12). Walks `[path]` (default cwd) recursively, skipping `node_modules` / `dist` / `build` / `.git` / `target`. Builds each `.vader` through `pipelineBytecode`, then walks the lowered project for `LoweredFnDecl`s whose `origin.decl.decorators` contains `test` ; each such fn is launched as a VM entry via `runFn(bc, mangled, [], { host })`. Any `VmError` (panic from `std/testing`, division-by-zero, unreachable, etc.) → test fails with the raw message. Output groups per-file with `ok`/`FAIL` per test + ms timing ; summary line `N tests | P pass | F fail`. Exit 0 on all-pass, 1 on any fail, 2 on no tests / no files / bad path. Optional name override : `@test("readable name") fn_name :: fn() -> void { ... }` — extracts `args[0]` if it's a static `StringLitExpr`. Tests : `tests/cli.test.ts` exercises passing / failing / empty / nonexistent-path cases against `tests/fixtures/test_cmd/`.
- [~] `vader fmt [path]` — opinionated formatter, no config. See top "Priority — next up" entry for status ; first pass landed 2026-05-11.
- [ ] `vader dump --stage=<ast|typed-ast|bytecode|c> <file>` (the `wasm` stage moves to Phase 3 alongside §3.10).
- [ ] `--allow-env` flag for comptime sandbox

### 1.13 Stdlib (in Vader)

- [ ] `std/core` — finalise traits and base `Error`
- [ ] `std/io` — implement `print`, `println`, `read_file`, `write_file`, `read_line`, `exists`
- [ ] `std/string` — finalise all listed operations
- [x] `std/collections` — `MutableMap(K, V)` chaining HashMap (string keys via FNV-1a hash, hash-backed via the same map for `MutableSet(T)`). `keys()` / `values()` snapshot helpers. `len` / `is_empty` / `put` / `get` / `contains_key` / `add` / `contains` shared via first-param overloading (§1.18c). Dead `Map` / `Set` immutable struct stubs removed 2026-05-07.
- [ ] **Implement immutable `Map`/`Set` ops + `to_immutable` conversion** when there's a real read-only-view design. Re-add `Map` / `Set` struct decls at that point.
- [x] **Iterator impls for `MutableMap` / `MutableSet`** (2026-05-11). `MapIterator(K, V)` walks buckets + chains lazily, yields `Entry(K, V)`. `SetIterator(T)` reimplements the walk directly on the backing `MutableMap(T, bool)` rather than wrapping `MapIterator` — wrapping forced a runtime `match` on the nested generic `Yielded(Entry(T, bool))` payload that the VM's variant tag check doesn't drill into. Both expose a factory `iter()` so `for entry in m.iter()` / `for v in s.iter()` work. Snippet : `tests/snippets/map_set_iter/` (native parity green ; the earlier "Unbox struct field" C-emit gap noted under §1.9 is closed).
- [ ] **Restore `MutableList(T)` once immutable `List<T>` lands**. Today raw `T[]` arrays already provide `push`/`len`/indexing/`for x in arr`, so `MutableList` was a wrapper with no extra value and was dropped (was previously `MutableList(T) { data: T[], size: usize }` — `size` field was redundant with `data.len()`). Re-introduce when there's an immutable `List<T>` to pair with.
- [ ] `std/math` — constants and float operations (use `@extern` to libm where useful on native, intrinsics on WASM)
- [x] `std/string_builder` — `StringBuilder` (was `std/builder`, renamed for clarity).
- [x] `std/iter` — `count(it: Iterator($T))` + `collect(it: Iterator($T))` driven by `for x in it`; closure-driven combinators `map`/`filter`/`fold`/`sum`/`take`/`skip` operate on `[T]` directly (eager — return arrays or single values). Snapshot : `tests/snippets/iter_combinators/`.
- [x] **`std/iter` lazy / iterator-driven combinators** (2026-05-11). Four lazy wrappers shipped : `MapIterator[T, U]`, `FilterIterator[T]`, `TakeIterator[T]`, `SkipIterator[T]`. Each holds a `source: Iterator(T)` trait-typed field and implements `Iterator(U)` itself, so chains (`filter → map → take`) compose without intermediate arrays. Construction is via struct literal (`MapIterator(i32, i32) { .source = …, .f = … }`) — no `lazy_map(it, f)` helper because generic-fn inference on a trait-typed parameter still traps at runtime (cf. §3.x trait-object boxing entry below). Snippet : `tests/snippets/iter_lazy/`. The earlier `inner.step()` plan is moot — Iterator's pull method was renamed to `next` alongside the new `Step` trait that handles per-primitive successor logic for `Range[T]` (cf. §1.18b Range dedup).
- [x] `std/runtime` — `collect()`, `collections()`, `bytes_used()`, `bytes_copied()`. Renamed back from `std/gc` (2026-05-07) — Go-style name signals "runtime introspection" for the small set of users who need GC stats / forced collection cycles, without inventing a new visibility tier (`internal/`) we can't enforce yet.
- [x] `std/sort` — `sort(arr: $T[], less: fn(T, T) -> bool) -> T[]`. Stable, O(n log n), non-mutating ; top-down merge sort with insertion-sort cutoff at 16 (mirrors Java TimSort). Returns a new array — input is never mutated. A `sort_by_ord(arr)` convenience is deferred until trait-method dispatch on bounded type parameters lands (TODO §1.18b). Snapshot : `tests/snippets/std_sort/`. First user : `vader/lexer/dump.vader:dump_diagnostics` swapped its inline insertion-sort + bubble-back hack for `sort(diags, diag_less)`.
- [~] **`std/cli` — command-line argument parsing library** (initial cut 2026-05-11). Minimal declarative parser shipped : `FlagKind` enum (`Bool` / `Str`), `FlagSpec`, `parse(args, specs) -> ParsedArgs`, plus `bool_flag` / `string_flag` accessors. Supports `--name`, `--name=value`, and `--` end-of-flags. Unknown flags accumulate in `ParsedArgs.errors` (non-fatal — caller decides whether to bail). Snippet : `tests/snippets/std_cli_basic/` (VM + native + snapshots green). Open follow-ups : (a) subcommand machinery (the lib has flags + positionals but no `App.subcommand(name)` builder yet) ; (b) `--help` / `--version` rendering ; (c) short-flag forms (`-v`) ; (d) `--name value` space-separated form ; (e) rewrite `vader/cli/main.vader` on top once subcommands land.

### 1.13b Self-hosting prerequisites (pre-bootstrap stdlib additions)

These items unblock porting the TS compiler to Vader.

- [x] **Process argv as a `main` parameter**. Two valid signatures (mutually exclusive) : `main :: fn() -> i32` or `main :: fn(argv: [string]) -> i32`. The typechecker enforces the shape (T3033). Native main wraps argc/argv into a `[string]` via `vader_runtime_argv` ; VM passes through `RunOptions.argv`. `argv[0]` is implementation-defined (script path in VM, binary path in native). No `std/gc.argv()` global — strictly parameter-passed. Tested by `tests/snippets/runtime_argv`.
- [x] **Format helpers** — pure Vader.
  - `std/string` : `pad_start`, `pad_end`, `is_whitechar` (uses `StringBuilder`).
  - `std/numbers` : `to_hex(self: u64) -> string`, `to_bin(self: u64) -> string` (UFCS-callable as `n.to_hex()` after `import "std/numbers"`). Uses StringBuilder + char arithmetic via `char(u32(...) + ...)` casts. Lives outside `std/core` so it can `import std/string_builder`.
  - Tested by `tests/snippets/format_helpers`.
- [x] **`in` / `!in` operators + `Contains($T)` trait** — `x in coll` desugars to `coll.contains(x)` ; `x !in coll` desugars to `!coll.contains(x)`. Trait lives in `std/core`. `Range implements Contains(i32)` shipped. Tested by `tests/snippets/contains_op` (covers both Range and a user struct).
- [x] **`char ↔ u32` casts** (and `char ↔ i64/u64/usize/i32` etc., minus floats) — `u32(c)` and `char(code)` work in both VM and native. Convert op extended in bytecode (`char.to_X`, `X.to_char`). Char ↔ float casts intentionally rejected.
- [x] **`std/path`** — `Path` struct + `to_path/empty_path/as_string/is_empty/is_absolute/parent/filename/extension/stem/join/starts_with/ends_with/normalize`. POSIX `/` only (Windows deferred). Pure Vader. Tested by `tests/snippets/path_basics`. Found and fixed a `local.tee` bug along the way: when fusing `local.set N; local.get N → local.tee N`, the C emit kept the original (possibly boxed) value on the stack instead of re-fetching the typed slot, breaking `[string]` element access into a primitive-typed local.
- [x] **`std/regex` ad-hoc helpers** — `replace_chars_where`, `trim_suffix`, `trim_prefix`, `split_whitespace` in `std/string`. Char ordering ops (`char.lt`/`le`/`gt`/`ge`) added across the pipeline so predicates like `c >= '0' && c <= '9'` work. Tested by `tests/snippets/regex_helpers`.
- [x] **`std/json`** — recursive-descent parse + stringify, pure Vader.
  - `JsonValue :: type JsonString | JsonNumber | JsonBool | JsonNull | JsonArray | JsonObject`
  - `parse(s: string) -> JsonValue | JsonError`, `stringify(v) -> string`, `stringify_pretty(v, indent) -> string`
  - `MutableMap.keys()` / `values()` added in `std/collections` to support stringification.
  - Tested by `tests/snippets/json_basics`.
  - Returns `JsonValue | JsonError` rather than `JsonValue!` because trait widening (struct-implementing-Error to `Error`) doesn't fire on `return` statements — see TODO §1.13c.
- [x] **`std/path`** (already done above, listed here for grouping)

### 1.13c Bugs uncovered while building 1.13b (fix before self-host)

- [x] **Integer-literal coercion to `u64`/`i64` in assignments / comparisons** — verified fixed (2026-05-07). `i64.const` is now emitted when the operand's ValType is i64/u64/usize ; `if v == 0` and `v = 5` for `v: u64` both work in the VM. Repro left in TODO if it ever regresses : `v: u64 = 5; if v == 0 { ... }`.
- [x] **Iterating `[string]` via `for x in arr` in the VM** — verified fixed (2026-05-07). `step__string` monomorphisation works ; the `runtime_argv` workaround can be revisited.
- [x] **`char` arithmetic / casts** — `i32(c)` and `u32(c)` work today (2026-05-07). The reverse (`char(n)`) was already supported.
- [x] **Trait widening on `return`** — verified fixed (2026-05-07). `fn() -> T | Error` accepts `return some_struct_implementing_Error` for any number of error structs implementing the `Error` trait.
- [x] **C-emit narrowing-aware unbox on local reads inside match arms** — verified fixed (2026-05-07). `match r { is f64 -> println("got float ${r}") }` works on both VM and native backends ; the C emitter handles the boxed-to-f64 unbox at use sites.
- [x] **Multi-file modules silently dropped every file but the first** — fixed 2026-05-06 in `src/resolver/index.ts` via `mergeFilePrograms`. Pre-fix : `resolveLoadedProject` kept only `programs[0]!` from `resolveModule`'s `ResolvedProgram[]`, so any module folder with > 1 `.vader` file lost everything but the first. Required for `vader/lexer/{token,keywords,lexer}.vader`.
- [x] **Cross-module enum referenced from a struct field had empty `indices`** — fixed 2026-05-06 in `src/typecheck/{check,index}.ts`. Pre-fix : a struct/fn declared *before* its referenced enum (or in another module typechecked first) saw `indices: new Map()` at lower-time, tripping `loweredEnumVariant`. Fix : two-pass `declareModule` — every module's enums declared first across the whole project, then everything else.
- [x] **FieldExpr→Enum lowering misdispatch** — fixed 2026-05-06 in `src/lower/passes/expr.ts`. Pre-fix : `b.color` (struct field whose type happens to be an enum) was treated as variant access because the lowerer dispatched on the *expression* type. Fix : dispatch on the *target's* type. Typecheck side : `inferField` now also falls through to UFCS on enum *values* so `e.method()` can call free fns whose first param is the enum.
- [x] **Expression-bodied functions** (Kotlin-style `name :: fn(...) = expr`) added 2026-05-07 ; explicit return-type form `name :: fn(...) -> T = expr` lifted from P1020-restriction on 2026-05-08. Return type is inferred from the body via a fixpoint pass between `declareModule` and `checkProgram` when omitted, or pinned eagerly when annotated (required for recursive expression bodies — otherwise the inference loop stalls and surfaces `T3034`). Tests : `tests/snippets/expr_bodied_{fn,recursive_fn,mixed_form,recursive_typed}/`.
- [x] **`null` ValType maps to `void` in C**. `cTypeForValBare("null")` returned `"void"`, producing invalid `void blockres_X = ...;` declarations. Fixed (now `vader_box_t`); regression covered by `tests/snippets/null_blockres/` (2026-05-07).
- [x] **`parse_int` / `parse_float` C shim tagged success boxes with the string type's index**. Found while building `std/json` — `match r { is i32 -> ... }` would never fire on the native target. Fixed by adding `primTagOrTrap` to look up the right primitive type's BcType index. Audit complete (2026-05-07) : the only other result-bearing shims (`read_file`, `write_file`, `read_line`, `split`) box their success with the correct type tag. Regression : `tests/snippets/parse_int_match/`.
- [x] **`Range` is i32-only ; non-i32 bounds now error at compile time** (2026-05-07). `inferRange` (`src/typecheck/passes/expr.ts:240-258`) explicitly checks `isAssignable(.., TY.i32)` on each bound and emits `T3001` instead of letting a u64/usize slip through to a VM trap. Regression : `tests/snippets/range_bound_u64/`. **Proper fix (still deferred)** : generalise `Range :: struct($T)` over the integer type with impls for i32/u64/usize, mirroring `Yielded(T)` and `ArrayIterator(T)` (cf. SPEC §1442). Bigger lift — touches `std/core`, `inferRange`, `lowerRangeExpr`, and the resolver's `CORE_STRUCTS` registration. Tracked under §1.18b "Generic `Range`".
- [x] **`is Struct { field, … }` (struct field destructure) trapped at runtime when the scrutinee is a union** — fixed 2026-05-12. Two bugs : (1) the lowerer recursed into `IsPattern.inner` with the union-typed target — `walkPatternBindings` now casts the target to the inner type first. (2) `bindingNarrowing` left field bindings `Unresolved`, breaking `Display` dispatch — generalised to `bindingNarrowings` returning N entries typed via the exported `fieldTypeOnType`. Regression : `tests/snippets/match_struct_pattern_in_union/`.

### 1.13d Stdlib consolidation passes

Audits across the stdlib modules to eliminate duplicate helpers and pull
helpers into the right module. Each pass is small but cumulative — the
goal is one canonical home per concern so any future port of the stdlib
(self-host, alternate target) inherits a clean shape.

- [x] **hex/base helpers centralised in `std/numbers`** (2026-05-10). `is_hex_digit` and `is_digit_in_base` moved from `std/string` to `std/numbers` (where `hex_digit_value` / `parse_int_in_base` / `to_hex` / `to_bin` already live). `parse_hex_digit` private fn in `std/json` was a byte-for-byte copy of `numbers.hex_digit_value` — dropped, json now imports the canonical helper. Dead alias imports (`contains as str_contains`, `starts_with as str_starts_with`) removed from `std/json`.
- [x] **char-predicate duplicates in `std/json` removed** (2026-05-10). The private `is_digit :: fn(c: char) -> bool { c in '0'..='9' }` declared in `std/json` was a copy of `std/string.is_digit` — dropped, import added. `skip_ws`'s inline `c == ' ' || c == '\t' || c == '\n' || c == '\r'` replaced with `is_white_char`. `parse_value`'s leading-digit check (`c in '0'..='9'`) replaced with `is_digit(c)`.
- [ ] **Future audits** : revisit when new stdlib modules land, especially any module that hand-rolls its own cursor / parser scaffolding (today `std/json` and `vader/lexer` both carry one ; not duplicates of each other since they're per-struct, but a future shared `Cursor(T)` trait could unify both).

### 1.13e Language ergonomics surfaced by the self-host port (fix before scaling Phase 2)

Patterns counted on the existing Vader code (`vader/` ≈ 11.7k lines) that pay an outsized boilerplate cost today. Each item below is a language-level relaxation (additive, back-compat by construction) ; cumulatively they should divide the size of the upcoming typecheck / lower / mid-IR ports by ~1.3 and erase confessed limitations. Listed by pervasiveness (ROI first). All are *prerequisites* — scaling Phase 2 without them means propagating these costs across ~22k more lines of Vader.

- [x] **Numeric literal context-sensitivity for `usize` (and other primitives)** (2026-05-12). Option (a) — Zig-style comptime-int defaulting — was already mostly in place for `FreeInt → i32/i64/u64` via `checkExpr`'s repinning ; the remaining hold-outs were two callee-side gaps. (i) `inferGenericUfcsCall` (`src/typecheck/passes/field.ts`) didn't repin `FreeInt` arg literals after substitution like `inferGenericFnCall` does, so `arr.slice_array(0, n - 1)` (where `slice_array = std/iter.slice` aliased on import) traps the VM with i32-vs-usize. (ii) `inferUnary` (`src/typecheck/passes/expr.ts`) ignored `expected`, so `g: i64 = -50` lowered as `i32.const 50; i32.neg; local.set` (i32 into i64 slot). Fixed both ; the operand's expected type now flows into `checkExpr` for `neg`/`bitnot`. Snippet : `tests/snippets/numeric_context_sensitivity/` (all integer widths + arithmetic + negative literal + struct field default + generic UFCS through alias). Migration : sweep `sed -E 's/usize\(([0-9])\)/\1/g'` on all `vader/` ; ~180 sites cleaned (217 lines net). Snapshot `path_basics/bytecode` refresh : `return -1` in `last_index_of(... -> isize)` is now `i64.const 1; isize.neg` (was `i32.const 1; i32.neg` — silently buggy in C-emit, VM tolerated). Bonus fix : cross-branch numeric pinning in `inferIf` (else-branch of `if c { 0 } else { width }` where `width: usize` now produces `usize` instead of `{integer} | usize`).

- [x] **Flow-narrowing on `T | null` inside `if x != null { ... }`** (2026-05-12). New module `src/typecheck/passes/narrow.ts` centralises `pushNarrowing`/`popNarrowing` (extracted from `match.ts`), `detectNullCheck`, `blockDiverges`, `postStmtNullNarrowing`. `inferIf` (`expr.ts`) push the narrowing in the matching branch (truthy for `!= null`, falsy for `== null`). `checkBlock` (`stmt.ts`) propagates the complementary narrowing past an `ExprStmt(IfExpr)` whose then-branch diverges (return / break / continue), so `if x == null { return } x.f` works without an outer match. Fix collatéral : `binaryEquality` (`binary.ts`) accepts `(T | U) == T` (union-vs-variant) — otherwise `Cat | Dog | null == null` raises T3017. Lower-side : `(Union) == null` reduces to a `LoweredTypeCheck null` (the C-emit's `ref.eq` over two `vader_box_t` doesn't compile cleanly, and the tag-only check is what we actually want). Snippet : `tests/snippets/if_null_narrow/` covers 5 cases (truthy narrow, eq+early-return propag, symmetric `null != x`, divergent else, chain of guards). Limit : only `T | null` for now ; richer flow narrowing on arbitrary unions is tracked separately.

- [x] **Common-field access on union-aliases (`UnionFieldResolution` for `:: type` unions)** (2026-05-12). False alarm — the TS typechecker already supports common-field on `:: type` aliases (Layer-4-sugar dereferences the alias to its underlying `Union` in `typeFromSymbol`, then `inferField`'s Union-receiver arm fires as designed). Confirmed via probe : `Animal :: Cat | Dog | Pig` + `fn(a: Animal) -> string { return a.name }` lowers correctly. The 25-arm `expr_span` / `stmt_span` dispatches in `vader/fmt/printer.vader` and `vader/lsp/indexer.vader` were a workaround for a *different* issue : the wildcard `_` arm in `match opt { is null -> ... _ -> use opt.field }` doesn't narrow. Now obsolete with the flow-narrowing item above ; existing helpers can be collapsed call-site-by-call-site as the formatter / LSP get touched. Divergent-type policy confirmed via probe : `Cat.age: i32` + `Pig.age: i64` makes `Animal.age` resolve to `i32 | i64` (the caller narrows with `match`).

- [x] **Enum-to-repr direct cast (`Repr(EnumValue)`)** (2026-05-13). Cast an enum value to *its declared repr* only — `Day :: enum(u8)` accepts `u8(Day.Tue)`, but `i32(Day.Tue)` is rejected with a hint to chain explicitly (`i32(u8(Day.Tue))`). One-step rule, uniform with every other primitive cast ; sidesteps the signedness/width ambiguity of an implicit widening. Touched `src/typecheck/passes/cast.ts` (~10 lines : `Enum` source branch tested before the numeric branch, equality-not-assignability against `argType.repr`). Lowering / bytecode / C-emit untouched : `valTypeOf(Enum) === primitiveToVal(repr)` already, so `LoweredCast` → `Cast` → `emitCast` sees `fromVal === toVal` and emits no convert op. Snippets : `tests/snippets/enum_to_repr_cast/` (u8 + u32 + i32 default + chained widening) and `enum_to_repr_cast_bad/` (T3010 on every wrong target). Migration : `vader/lsp/log.vader` drops the 10-line `level_code` workaround and inlines `i32(level)` at the call site.

- [x] **Reject mutation of constant binding (`x :: ...; x += ...`)** (2026-05-15). New T3041 emitted at the mutation site when `AssignStmt`'s target is an `IdentExpr` resolving to a `local` whose source `LetStmt.mutable === false` (`src/typecheck/passes/stmt.ts:149-170`). The diagnostic points at the assignment with the `::` decl as a secondary "declared here" span. Compound assigns (`+=` / `-=` / `*=` / etc.) desugar to plain `x = x op v` at parse time so the single check covers every form. Field / index writes through a const binding (`p.x = 10` where `p :: Point{...}`) stay allowed — `::` pins the slot identity, not interior mutability. Regression snippet : `tests/snippets/const_binding_no_mutate/`. Self-host + full suite green ; the two historical mutations cited above (`stdlib/std/string.vader:210`, `vader/vm/parser.vader:254`) were already cleaned up — the codebase had healed in the interim. Out of scope : same check on `param` / `binding` (for-in / match-arm) symbols — those are also semantically immutable but the lexical `::` contract was the only documented bug.

- [x] **`match expr.field { _ -> use expr.field }` doesn't narrow on a field-expr scrutinee** (2026-05-15). Added a parallel `narrowedFields: Map<string, Type>` to `MutableTyped`, keyed by `${targetSym.id}#${fieldName}` (`fieldNarrowKey` in `src/typecheck/passes/narrow.ts`). `inferMatch` pushes a per-arm field narrowing when the scrutinee shape is `IdentExpr.field` on a narrowable local/param/binding (`scrutineeFieldPath` in `src/typecheck/passes/match.ts`). `inferField` consults the map immediately after typing the target ident and short-circuits to the narrowed type when present (`src/typecheck/passes/field.ts:38-49`). Removes the `r :: nn.restricted` workarounds previously planted in `vader/fmt/printer.vader` and `vader/parser/dump.vader`. Regression snippet : `tests/snippets/match_field_narrow/`. Scope is single-level field access on plain idents ; nested paths (`a.b.c`) and the sibling `if v.field is T { ... }` flow-narrowing on a field-expr condition stay deferred — same key shape would work, untouched call sites in `narrow.ts:detectVariantNarrowing` track the remaining surface.

- [x] **`if v is T { v.field }` doesn't narrow `v` for field access** (audited 2026-05-15). Verified the bug is gone : `tests/snippets/if_is_field_after_narrow/` exercises `if v is StructVal { return v.type_id }` on a multi-field heap struct (not inline-variant) and an `is ArrayVal` chain reading an array field — the c-emit generates the typed cast `((StructVal*) v.payload.obj)->f_type_id` and the binary runs as expected. `vader/vm/value.vader:read_truthy` collapsed back from the `match v { is BoolVal as b -> b.value }` workaround to the natural `if v is BoolVal { return v.value }` chain ; vader-cli rebuilds + the full vader_vm parity suite (185 tests) stays green. The other historical workarounds in `value.vader` (`type_matches`, `receiver_type_id_of`, `value_ref_eq`) are kept as-is — they use the match-as-expression form which is idiomatic for non-divergent dispatch and offers no reason to convert. Probable healing commit : the field-narrowing chain (`6977eecb` + `32dca18c` from this session) or the §1.4 typeInternKey dedupe (`9d40556e`).

- [x] **Tuple destructure after `[T, U] | null` narrow** (2026-05-15). Two interlocking bugs ; both fixed.

  1. **Parser ambiguity** — `if pair is null { return -1 }` followed by `[a, b] :: pair` glued together as `(if … { … })[a, b]` because postfix `[` had no statement-boundary guard. Block-tail expressions (`IfExpr`, `MatchExpr`, `BlockExpr`) now reject postfix `[ … ]` and `( … )` chaining (`src/parser/passes/expr.ts:84-97`, mirrored in `vader/parser/parser.vader:2057-2070`). Parens force the form when really wanted : `(if c { x } else { y })[0]`. Field access (`.f`) stays unambiguous since stmt-leading `.` is rare and parsed via a separate prefix path.

  2. **Narrowing reaches the destructure** — the typecheck-side per-symbol narrowing map was already keyed by binding id ; the destructure-pattern bindings consult it via the regular `inferLet` path. After the parser fix, the natural `[a, b] :: pair` form types correctly without any narrowing-flow change.

  Workaround retired : `vader/vm/parser.vader` dropped the `IntPair :: struct { first, second }` named-struct + 3 call-site `pair.first` / `pair.second` accesses (`parse_struct_get`, `parse_struct_set_after`, `parse_array_new`, plus the `parse_fn_ref` / `parse_make_closure` consumers). `parse_int_pair_after_prefix` returns `[i32, i32] | null` directly ; callers narrow with `if pair is null { return null } ; [tid, fi] :: pair`. Regression snippet : `tests/snippets/tuple_destructure_after_narrow/`.

- [ ] **AST node id boilerplate — auto-assign or derive** — re-audited 2026-05-15 ; deferred. Real cost is small : `vader/parser/ast.vader` has 11 `id: usize = UNASSIGNED_NODE_ID` field declarations (not the 30+ originally estimated), and construction sites already omit `.id` thanks to the field default. The TS side (`src/parser/ast.ts`) carries ~117 `id: UNASSIGNED_NODE_ID` props at construction because TypeScript struct literals don't honour interface defaults. Three resolution shapes (decorator-based, mixin composition, auto-id marker) all need new compiler infrastructure — decorator semantics + field synthesis at parse time — that's a much bigger lift than the 128 lines it would save. Revisit if the decorator infra lands for other reasons or if AST struct count grows materially.

- [x] **Transitive monomorphisation through nested generic calls** (2026-05-13). Verified working — the §1.13e claim was stale. `closeOverGenericImpls` (§1.5b, `src/comptime/evaluate.ts:460`) drains a worklist that walks every generic fn instance's body and re-feeds `observeFnCall` with substituted type-args under each `(fn, type-args)` instantiation. Extracted `ensure_buckets[K, V]` from `MutableMap.put` and confirmed it materialises at all three K/V instances (`(i32, bool)`, `(i32, i32)`, `(string, i32)`) ; the inline bucket-init was a historical workaround. Stronger tests : 3-level chain (`outer → middle → inner` over `T` and `Box(Box(T))`) all materialise correctly. Unblocks the typechecker port — extracting helpers from generic fns is now uniformly free.

- [ ] **Byte literal syntax `b'{'`** — every byte-level comparison in `vader/lexer/lexer.vader` and `vader/lsp/indexer.vader` writes `b == u8(u32('{'))` (triple cast : char codepoint → u32 → u8). Concentrated in the hot byte-scanner paths of the lexer / comment scanner. Two routes : (a) **Rust-style** `b'{' :: u8 = 0x7B` literal syntax in the parser, (b) **direct `char` to `u8` cast** when the char's codepoint is < 128 (the cast traps at runtime for non-ASCII chars). (a) is local to the lexer / parser ; (b) is a typechecker rule. (a) is cleaner — it makes the intent explicit and avoids hiding a fallible cast. Visible cost line : `vader/lsp/indexer.vader:626-633`.

- [x] **Type-alias declaration order relaxed** (audited 2026-05-15). Verified the bug is gone : the resolver already collects every decl name in pass 1 before walking types in pass 2, so a `Foo :: Bar | Baz` alias can sit before or after the variant structs it lists. Probed by moving `Stmt :: LetStmt | …` and `DeferBody :: …` in `vader/parser/ast.vader` from the top of the file to AFTER their variant struct decls — vader-cli rebuilds and the full test suite stays green. File header comment updated to reflect free order.

- [x] **Namespace-imported aliases don't unify with direct imports** (2026-05-14). Root cause was upstream of `equalsType` : when the same source file is loaded under two different module IDs — a file module `vader/parser/ast` *and* the folder module `vader/parser` that aggregates it — `collectModuleSymbols` ran independently for each and allocated fresh `Symbol` ids for the same source declarations. The two `Decl` symbols therefore had distinct `Symbol.id`s, and `equalsType` rejected them, manifesting as T3001 with the union spelled-for-spelled on both sides. Fix : `equalsType` falls back to comparing `definedAt` source position when ids diverge (`src/typecheck/types.ts:545-595`), so two symbols pointing to the same `(file, offset)` are treated as equivalent. Repro : `tests/snippets/namespace_alias_dedupe/`. `vader/lsp/ast_tokens.vader` was reverted from the verbose explicit-imports workaround to a single namespace import. Deeper loader consolidation — have the folder module re-export from the file module instead of re-declaring — is still tracked as a follow-up : `equalsType` papers over the typecheck symptom but downstream phases (bytecode, c-emit) still see two distinct struct type indices for the same source declaration. No existing code mixes the two paths in a way that triggers tag-dispatch mismatch at runtime.

- [x] **`MatchResult` workaround cleanup** (2026-05-15). `vader/parser/parser.vader` retired the `MatchResult :: struct { matched: bool, token: Token }` wrapper. `match_kind` returns `Token | null` directly. ~60 call sites converted : the boolean-only majority (`if p.match_kind(.X).matched { ... }`) becomes `if p.match_kind(.X) != null { ... }` ; the 3 sites that consumed the token (`end_match.token`, `close_match.token.span`) bind to a local and consume after a null-narrow (`end_match :: p.match_kind(.X) ; if end_match != null { end_match.span }`). Self-host rebuilds, full test suite (2814) + vader_vm parity (188) green. `if let x := opt { ... }` deferred : the bind-then-check shape collapses naturally to two lines thanks to flow-narrowing, and the 3 affected sites don't justify a new syntactic form.

- [x] **Self-host lexer u64 overflow** (2026-05-12). Promoted the unsigned magnitude carrier through the self-host : `IntLitExpr.value: i64 → u64` (`vader/parser/ast.vader`), `Token.value` union gains `u64` (`vader/lexer/token.vader`), new `parse_uint_in_base :: fn(s, base) -> u64!` in `stdlib/std/numbers.vader` (sibling of `parse_int_in_base` which stays `i64!` for signed-int parsing in user code), `decode_int_literal` returns `u64`. Dumps adapted : `write_bigint(u64)` for IntLit ; `write_signed_bigint(i64)` kept for `EnumVariant.value` (signed repr — variants can be negative). Skip-list entries removed from `parity.test.ts:UTF8_KNOWN_DIVERGENT` + `parser_parity.test.ts:KNOWN_FAILURES`. `tests/snippets/numeric_context_sensitivity/` now parity-passes : `18446744073700000000` round-trips as `"18446744073700000000n"`. The two `bytecode` snapshot refreshes (`format_helpers`, `json_basics`) are cosmetic — line-number shift from the new `parse_uint_in_base` decl in `std/numbers.vader`. Tests : 2150 pass.

- [x] **Flow-narrowing on `if x is T` (ident scrutinee, Phase A)** (2026-05-13). `src/typecheck/passes/narrow.ts:detectNullCheck` is renamed `detectVariantNarrowing` and now recognises three condition shapes against an ident scrutinee : `x is T`, `x == null`, `x != null` — plus a leading `!` flipping then/else. New side-table `binaryIsCheckTypes: Map<BinaryExpr, Type>` populated by `inferBinary`'s `case "is"` via `lowerExprAsType` so primitive RHSs (`i32`, `string`, ...) resolve to the actual primitive type instead of `TypeMeta` (latent bug : the lowerer was reading `exprType(rhs)` which returned `TypeMeta` for builtin-type names, making `if x is i32 { ... }` always-false at runtime). Lowerer's `LoweredTypeCheck` reads from the new map with a fallback. `inferIf` + `postStmtNarrowing` (renamed from `postStmtNullNarrowing`) consume the unified split shape, so a divergent guard (`if x is T { return }`) propagates the complement narrowing forward. Snippet : `tests/snippets/if_is_narrow/` covers direct / negated / cascaded / primitive. Bonus migration : `vader/parser/parser.vader:wrap_as_block` collapsed from a 5-line `match` to `if body is BlockExpr { return body }`. **Phase B — FieldExpr LHS (receiver narrowing `if s.f != null { s.f.x }`) deferred** : the narrowing map is symbol-id-keyed today ; path-based keying + immutability check needed first. The dominant idiom (`c :: state.cache ; if c != null { ... }` rebind) remains.

- [x] **Drop `fn` keyword on lambda expressions** (2026-05-12). New form : `(params) -> body` (or `x -> body` for single-param sugar). The `fn` keyword is retained for declarations (`name :: fn(...) -> R { ... }`) and function types (`cb: fn(i32) -> i32`) — only lambda values lose it. **No explicit return-type slot on lambdas** (always inferred from the call-site signature, the surrounding fn-type slot, a typed `let`, or the body itself). `LambdaExpr.body: BlockExpr` invariant kept downstream — the parser wraps a non-block body expression in a synthetic `BlockExpr { stmts: [], trailing: expr }`, so typecheck / lower stay unchanged. Touched `src/parser/passes/expr.ts` (`parseParenOrTuple` reroutes to `parseLambdaWithoutFn` via balanced-scan lookahead ; single-param tail picked up after `parsePrefix` returns a bare `IdentExpr`), `src/parser/passes/control.ts` (`parseLambda` no longer accepts `fn(...) { body }` in expression position — emits a `FnTypeExpr` instead and leaves the orphan block for downstream diagnostics ; the `name :: fn(...) { body }` Vader idiom for fn-decl-as-let is preserved via a new `parseLambdaAsLetValue` that `parseLet` dispatches to), `src/parser/passes/stmt.ts` (the `parseLet` dispatch). Also migrated the self-host parser (`vader/parser/parser.vader`) — new `peek_lambda_without_fn`, `parse_lambda_without_fn`, `parse_single_param_lambda_tail`, `wrap_as_block`. Migration : 5 lambda sites rewritten (1 in `vader/resolver/resolve.vader`, 3 in `tests/snippets/iter_combinators/`, 1 in `tests/snippets/iter_zip_chain/`) ; the dominant `name :: fn(...) { body }` form (~70 sites in stdlib + vader) unchanged. New snippet `tests/snippets/lambda_no_fn/` covers the 6 forms. `LEXER_PARSER_CORPUS` extended with `lambda_no_fn` so the parser-parity test exercises the self-host migration. SPEC §6 Closures/lambdas + Function values rewritten. Tests : 1510 pass.

### 1.14 Snapshot test infrastructure

- [x] Test directory layout: `tests/snippets/{name}/_main.vader` (single source per test, `_main` sorts first in IDEs) + `{phase}.snapshot` files alongside it.
- [x] Driver: runs every pipeline phase (lexer → parser → resolver → typecheck → comptime → lower → bytecode → vm → native) on each snippet; compares dump against snapshot. Lives in `tests/snapshot.ts` + `tests/snapshot.test.ts` + `tests/vm.test.ts` + `tests/native.test.ts`.
- [x] Update mode: `UPDATE_SNAPSHOTS=1 bun test` to refresh snapshots after intentional changes.
- [x] Cover: 80+ snippets — simple programs, generics, traits, comptime, error propagation, multi-file modules, fixtures, fn values (`fn_value_*`), GC stress (`gc_chain_survive`, `gc_multi_collect`), closures (`closure_simple/counter/shared/callback`), iter combinators.

### 1.15 Formatter

- [ ] Define formatting rules (one canonical layout — no options)
- [ ] AST → formatted source
- [ ] Idempotency check: `fmt(fmt(src)) == fmt(src)`

### 1.16 Examples

- [x] `examples/hello.vader`
- [x] `examples/fibonacci.vader` — Fibonacci
- [x] `examples/fizzbuzz.vader` — FizzBuzz, classic loop / branching exercise
- [x] `examples/rule110.vader` — Rule 110 cellular automaton (Turing-complete CA)
- [x] `examples/primes.vader` — Sieve of Eratosthenes
- [ ] `examples/aoc_2024_day1.vader` — solve an AOC problem end-to-end (validates I/O + parsing + collections)
- [ ] `examples/wasm_browser/` — moved to Phase 3 alongside the WASM emitter (§3.10).

### 1.17 Enums (required before self-hosting)

The self-hosting compiler will use enums to represent token kinds, opcode tags, diagnostic severity, and similar closed sets. These must land before Phase 2 begins.

- [x] Lexer: add `enum` to the keyword table; emit `kw_enum` token (`src/lexer/token.ts`, `src/lexer/keywords.ts`).
- [x] Parser: add `EnumDecl` AST node (`src/parser/ast.ts`); parse `Name :: enum { A, B, C }` (trailing comma allowed).
- [x] Parser: add `.Variant` dot-shorthand as `DotVariantExpr`; type inferred from context by the type-checker.
- [x] Parser: allow `.Variant -> expr` as a match arm form (`EnumVariantPattern`).
- [x] Parser: add `name: Type = value` typed-let statement form (`parseTypedLet` in `src/parser/passes/stmt.ts`).
- [x] Type-checker: add `EnumType` to `src/typecheck/types.ts`; `declareEnum` in `decl.ts`; `"enum"` in `typeFromSymbol`.
- [x] Type-checker: resolve `DotVariantExpr` via bidirectional inference (`expected` context) in `expr.ts` and `binary.ts`.
- [x] Type-checker: exhaustiveness for enum match; all variants covered or `_` wildcard (`match.ts`).
- [x] Lowerer: enum variants → `i32` constants (0-indexed); `DotVariantExpr` / `FieldExpr` on enum → `LoweredIntLit`; `EnumVariantPattern` → `eq` predicate.
- [x] Bytecode emitter / VM: no changes needed — enums are plain `i32` after lowering.
- [x] C emitter: enum variants lower to `i32` before emit; C output uses `int32_t` constants transparently. Verified via `tests/snippets/enum_basic/` and `enum_match/` native tests.
- [x] Snapshot tests: `tests/snippets/enum_basic/` covers lexer → bytecode → vm; `tests/snippets/enum_match/` covers ==, !=, return type, dot-shorthand, multi-enum programs.

#### Typed enums — done

- [x] **Typed representation** (`SPEC §Enums / Representation`): `Direction :: enum(u8) { ... }` — optional `(type)` suffix selects the backing integer type (`i8`/`i16`/`i32`/`i64`/`isize`/`u8`/`u16`/`u32`/`u64`/`usize`; default `i32`). Parser : optional `(repr)` after `enum` (`EnumDecl.repr: TypeExpr | null`). Typecheck : `resolveEnumRepr` validates the type is a primitive integer (`T3029` otherwise) and stores it on `EnumType.repr`. Lowerer : `loweredEnumVariant` reads `enumType.repr` to type each `LoweredIntLit`. Snippet : `tests/snippets/enum_typed/` covers `enum(u8)` + `enum(u16)` end-to-end (lex → bytecode → VM → native).
- [x] **Explicit variant indices**: `Up = 10`, with auto-increment for unspecified variants. AST : `EnumVariant.value: bigint | null` + `valueSpan`. Typecheck : `resolveEnumIndices` runs a cursor (starts at 0, `value + 1` after each variant) ; explicit values reset the cursor. Result stored on `EnumType.indices: ReadonlyMap<string, bigint>` and consumed by the lowerer.
- [x] **Bounds checking**: `REPR_RANGES` table per primitive ; out-of-range values emit `T3030` ("enum variant value out of range for backing type"). Duplicate values across the same enum emit `T3031` ("duplicate enum variant value"). Snippet : `tests/snippets/enum_bad_repr/` exercises all three diagnostics (`T3029` non-int repr, `T3030` u8 overflow, `T3031` dup).

### 1.18b Generics & primitive type ergonomics

Sub-tasks discovered while implementing collections:

- [x] **`usize` primitive** — first-class type for sizes/indexes. Maps to `size_t` in C, 64-bit in bytecode/VM bootstrap.
- [x] **`isize` primitive** — symmetric to `usize` (signed pointer-size). Maps to `ptrdiff_t` in C, 64-bit `i64.const` const-emit, `int64_t` boxing. Added to `PRIMITIVE_NAMES` / `SIGNED_INTS`, threaded through bytecode (`ops.ts`, `binary.ts`, `peephole.ts`, `emit.ts`), VM (`value.ts`, `exec.ts`, `host.ts`), C-emit (`emit.ts`, `static_table.ts`), and stdlib (`std/core` Display/Equals/Hash/Add/Sub/Mul/Div impls). Bytecode patch bumped 0.1.0 → 0.1.1 (additive VAL_TYPES + op-kinds).
- [x] **Migrate `arr.len()`, `ArrayIterator.length/cursor`, `iter.vader` signatures from `i32`/`u32` to `usize`** (2026-05-10). `arr.len()` returns `usize` (typecheck `inferField` + lower `LoweredArrayLen` + VM `array.len` push `i64("usize", ...)` + C-emit `size_t`). `ArrayIterator.cursor`/`length` are now `usize` ; `for-in`'s `wrapArrayAsIter` lowers `0`/`array.len` as `usize`. `std/iter.vader` :  `count` returns `usize`, `take(n: usize)`, `skip(n: usize)`, `slice(start: usize, end: usize)`, `enumerate(arr) -> [usize, T][]`, inner counters typed `usize`. Callers updated : `std/sort` (lo/hi/INSERTION_CUTOFF), `std/path` (count/j cursors), `std/json` (write_array/write_object cursors), `std/collections` (keys/values bi cursor + `BUCKET_COUNT :: usize(16)`), `std/numbers` (to_hex/to_bin reverse walk rewritten as `for k < n { rev[n-1-k] }` to avoid usize underflow), test snippets `regex_helpers` / `selfhost_lexer_basic`. Bidirectional typing fix in `inferGenericFnCall` (`src/typecheck/passes/call.ts:140-150`) — after building the type-param substitution, FreeInt/FreeFloat arg literals are repinned via `t.exprTypes.set` so the lowerer emits `i64.const` (not `i32.const`) for `take(arr, 3)` and similar generic call sites.
- [x] **Range[T] impl deduplication** (2026-05-11). Option (a) landed : new bounded-impl syntax `[T: Comparable & Step] Range[T] implements Iterator[T] { ... }` (parser + resolver + mono + typer + lower). Two new traits in `std/core` : `Step :: trait { step :: fn(self) -> Self }` carries the per-primitive successor logic (11 arrow-form impls — `i8`..`u64`/`isize`/`usize`/`char`) ; `Comparable` got the 11 missing primitive impls (arrow-form, body is `if self < other { -1 } else if self > other { 1 } else { 0 }`). The 22 hand-rolled `Range[Tx] implements Contains/Iterator` pairs collapse into 2 generic bounded impls + the unchanged `Range[char]` pair (char's advance via `u32` round-trip stays special). Iterator's pull method renamed `step` → `next` to free `step` for the new trait. Side wins : `.compare()` / `.lt()` / `.lte()` / `.gt()` / `.gte()` are now UFCS-callable on every primitive integer + `char`. `std/core.vader` shrinks 541 → 417 lines (−124 LOC). Snippet : the existing `range_widths` / `char_range_contains` / `for_range` suites cover the dedup. **Option (a) prerequisites that landed alongside** : (i) bounds on `ImplDecl` (parser + AST `ImplDecl.typeParams` + `resolveImplDecl` binding) ; (ii) mono substitution propagates impl-level typeParams to member-body subst (`fix(mono): substitute impl-level type-params on bounded generic impls`) ; (iii) typer `methodBoundFnType` merges impl-level + struct-level subst so default trait methods (`count` / `last` / `is_empty`) substitute correctly on bounded impls ; (iv) lower `methodResolutions` applies the entry subst before `lookupImplEntry` so the right specialised member is reached. The `T(1)` literal coercion (originally listed under option (a)) was sidestepped : the `Step` trait absorbs the "+ 1" obligation into per-primitive `step` impls. (b) / (c) abandoned.
- [x] **Migrate `std/string` to usize indices/lengths** (2026-05-10). `byte_len(s) -> usize`, `slice(s, start: usize, end: usize)`, `char_at(s, i: usize)`, `byte_at(s, i: usize)`, `decode_codepoint(s, i: usize) -> [char, usize]`, `count_chars(s) -> usize`, `pad_start/pad_end(width: usize)` ; `StringBytes`/`StringChars` cursor+length typed `usize` ; `string implements Index(usize, char)` updated in `std/core`. `last_index_of(s, c, min_index: isize) -> isize` keeps the `-1`-on-miss sentinel via `isize` (signed pointer-size — preserves the negative-result idiom without forcing a `usize | null`). C runtime updated (`vader_string_byte_len/slice/char_at/byte_at` now take/return `size_t`) ; VM host bindings push `i64("usize", …)` and parse args via tag-agnostic `asIndex`. `codepoint_byte_len(c) -> usize` (was `i32`). Stdlib callers adjusted : `std/numbers` (parse_int_in_base cursor), `std/json` (Parser.pos/eof/JsonError.pos, write_string + escape cursor, hex-escape `cp`/`k`), `std/path` (cast `last_index_of` result to usize after the `< 0` guard, normalize cursor `i: usize`), `std/math` (added `min`/`max`/`clamp` `usize` overloads). Self-host adjusted : `vader/lexer` (Lexer.pos, advance(n: usize), peek_at(n: usize), strip_numeric_text/lex_unicode_escape cursors, vader/lexer/dump.write_string), `vader/parser/dump.write_string`, `vader/diagnostics.Position.offset: usize`. Examples : `mandelbrot.vader` casts its palette index. Tests : 1335 pass.
- [x] **Generic `Range`** — `Range :: struct[T] { start: T, end: T, inclusive: bool, cursor: T }`. Every integer width (`i8`/`i16`/`i32`/`i64`/`isize`/`u8`/`u16`/`u32`/`u64`/`usize`) plus `char` ships `Contains` + `Iterator` impls in std/core. `inferRange` (`src/typecheck/passes/expr.ts:474`) picks the bound type from the first concrete operand (probes the upper bound when the lower is a free literal) and repins FreeInt bounds via `t.exprTypes.set` so the lowerer emits the right width ; `pickRangeBound` accepts any `ALL_INTS` member or `char`. `forInElementType` (`src/typecheck/passes/stmt.ts:247`) reads the resolved `Range[T]` struct args instead of hardcoding `i32`, so `for i in 0..<arr.len()` binds `i: usize` correctly. char arithmetic for the iterator advance uses an explicit `char(u32(self.cursor) + u32(1))` round-trip since `char` has no native `+ i32`. Stdlib char-class predicates (`is_digit`, `is_alpha`, …) migrated to `c in '0'..='9'`. Snippets : `tests/snippets/char_range_contains/`, `tests/snippets/range_widths/` (covers u64/i64/isize/u8/i16 end-to-end), `examples/rule110.vader` (drives Range[usize]).
- [x] **First-class function values** — `fn(K) -> u64` as a struct field / local variable / argument. Done. See §1.7 "First-class function values" for the full implementation note.
- [ ] **Decide `usize` width on the WASM target** — moved to Phase 3 (§3.10) alongside the WASM emitter.
- [x] **`void!` runtime/type mismatch** — fixed 2026-05-07 in the parser (`src/parser/passes/type.ts`) : when the postfix `!` desugar sees `void` as the success type, it rewrites to `null | Error` instead of `void | Error` so the union variant matches what the runtime actually emits (`vader_box_null()`). `match { is null -> ... is Error -> ... }` now matches cleanly on success ; `?` propagation continues to work since both forms keep the `Error` variant.
- [x] **Enforce struct-level bounds at instantiation site** (2026-05-10). New typecheck pass `validateStructBounds` (`src/typecheck/passes/struct-bounds.ts`) walks `globals.typeExprTypes` after `checkProgram` and emits T3006 for any concrete type-arg that doesn't satisfy its formal type-param's bound. Mirrors the per-call enforcement in `call.ts` ; the diagnostic points at the offending type-expr. Adopted in stdlib : `MutableMap :: struct[K: Hash & Eq, V]` and `MutableSet :: struct[T: Hash & Eq]` now declare their bounds at the struct level (was previously only on each method). `MutableMap(NoHash, i32)` now errors at the construction site instead of crashing downstream with `loweredEnumVariant: expected Enum type, got Unresolved`.
- [x] **Auto-inherit struct bounds onto methods** (2026-05-10). New typecheck pass `inheritStructBounds` (`src/typecheck/passes/inherit-bounds.ts`) runs between `inferExprBodiedReturns` and `checkProgram` — for every fn (free or impl member) whose first param's resolved type is a `Struct` instance with at least one `TypeParam`-typed arg matching one of the fn's own type-params positionally, it copies the struct's typeParam bounds onto the fn's matching typeParam. The fn body's `key.hash()` then sees the inherited bound and trait-method dispatch resolves statically. Adopted in `std/collections.vader` : `put`/`get`/`contains_key` on `MutableMap(K, V)` and `add`/`contains` on `MutableSet(T)` declare just `[K, V]` / `[T]` ; the `Hash & Equals` bounds on the struct decls flow through automatically. Walks both `FnDecl` and `ImplDecl` members so future generic struct + impl combinations also benefit.

### 1.18c-bis Function overloading across imports + local fns

- [x] **Local fn coexists with same-named import** (2026-05-10). Before this fix, `std/path` (which both imports `is_empty` from `std/string` and exports its own `is_empty(self: Path) -> bool`) failed to compile with R2004 ; the `path_basics` snippet had been baked as `# compile errors` for several commits. Touched : (a) `collect.ts:addFnSymbol` — when an existing `import-binding` of the same name is found, no error ; the local fn becomes the primary in `module.symbols`, and the import-binding is pushed into the `fnOverloads` bucket so UFCS dispatch can pick it up. (b) `wire.ts:wireImports` — also walks `fnOverloads` to find import-bindings the local-fn override displaced from `module.symbols`, so they get wired to their concrete export targets. (c) `index.ts:resolveImportOverloads` — runs after `wireImports`, follows each import-binding entry in `fnOverloads` to its resolved fn target, leaving each bucket as a flat list of fn-kind Symbols (some local, some from other modules). The typechecker's existing `rankOverloadsByFirstParam` then ranks them by receiver type without modification. `path_basics` now actually runs, producing 26 lines of stdout — `path.is_empty(p)` picks the local impl, `self.repr.is_empty()` picks the imported string version.

### 1.18c Function overloading by receiver type (pre-MVP)

Lift `R2004` for free functions whose names collide if their **first parameter** types differ. Required so that `get(MutableList, usize)` and `get(MutableMap, K)` (and similar) coexist in user code without forcing aliasing on every import.

- [x] **Resolver** (`src/resolver/collect.ts:addFnSymbol`) — `fnOverloads: Map<string, Symbol[]>` collects all sibling fns under the same name ; `Module.symbols` keeps the first decl as the primary entry. True conflicts (same first-param type) are caught downstream by the typechecker.
- [x] **Typechecker UFCS dispatch** (`src/typecheck/passes/call.ts:rankOverloadsByFirstParam` + `inferUfcsFreeBound`) — buckets candidates as `concrete > symMatch > wildcard` and picks the best match. Ambiguous concrete pairs surface as `T3032`.
- [x] **Direct-call resolution** (`inferCall` for `f(x, ...)`) — `pickDirectCallOverload` runs the same ranking. Free numeric literals default to their canonical type (i32 / f64) before ranking, so `abs(-7)` picks `abs(i32)` instead of silently choosing the first declared overload (fixed 2026-05-07 in `inferCall`).
- [x] **Diagnostic** : `T3032` ("ambiguous overload resolution") covers both UFCS and direct-call sites.
- [x] **Tests** : `tests/snippets/overload_first_param/` covers user-defined direct + UFCS dispatch and the stdlib `min`/`max`/`abs` i32+f64 overloads.
- [x] **Stdlib `min`/`max`/`abs` i32+f64 overloads** added in `std/math.vader` (2026-05-07). `std/string.compare_ascending` now uses `min(la, lb)` instead of an inline `if`.
- [x] **Stdlib cleanup** done 2026-05-07 : `len` / `is_empty` / `put` / `get` / `add` / `contains` are shared between `MutableMap` and `MutableSet` via first-param overloading. Dead immutable `Map` / `Set` struct stubs deleted from `std/collections.vader`. No `len_map` / `len_set` workaround names remain.

### 1.18d Common-field access on discriminated unions

TypeScript-style structural narrowing — when every variant of a union shares a field with the same name, allow direct access without an outer `match`. Removes a class of boilerplate in AST-style code (the self-host parser had 25-arm `expr_span` and `stmt_span` matches whose only purpose was to expose a field every variant carries).

- [x] **Typecheck** (`src/typecheck/passes/call.ts:inferField`) — Union-receiver arm walks every variant via the new `fieldTypeOnType` helper (handles Struct + Tuple variants today). If all variants have the field, returns `unionOf(field_types)` — `unionOf` collapses identical types so a uniform `Span` field gives `Span`. Otherwise emits T3009 listing the missing variants.
- [x] **`UnionFieldResolution` resolution table** — populated by the typechecker, consumed by the lowerer. Records per-variant `(type, fieldType)` pairs in source order so the cascade is stable.
- [x] **Lowering** (`src/lower/passes/expr.ts:lowerUnionFieldAccess`) — synthesises the variant-dispatch cascade (`let __scrut = e ; if __scrut is V1 { (V1) __scrut.f } else if __scrut is V2 { (V2) __scrut.f } else ...`). The cast in each arm narrows the runtime payload to the concrete variant ; the existing `LoweredFieldAccess` op then reads from the right layout.
- [x] **Self-host** : `expr_span` / `stmt_span` collapsed from 25-arm / 8-arm matches to one-liners (`fn(e: Expr) = e.span`, `fn(s: Stmt) = s.span`).
- [x] **Snippet** : `tests/snippets/union_common_field/` covers uniform-field access on a `Cat | Dog` union.
- [ ] **Variants beyond Struct/Tuple** — `fieldTypeOnType` returns null for Enum/Trait/Primitive/Array/Fn variants. Extend if a real-world union needs e.g. `(SomeStruct | OtherStruct | i32).field` to fail more loudly than T3009 today (currently the `i32` variant is just listed as "missing").
- [x] **Code-size : same-offset shortcut** — `lowerUnionFieldAccess` now detects the case where every variant is a Struct that stores the field at the same declaration index *and* with the same resolved type, and emits a single `(<first-variant>) target.f` instead of the per-variant cascade. The cast is a no-op at the bytecode level (boxed values share the `ref` ValType, so `Cast` skips emitting `ref.cast`), and `struct.get` reads the field at its struct-relative offset regardless of the runtime variant tag. Allowed dropping the `expr_span` / `stmt_span` / `let_binding_span` helpers in `vader/parser/parser.vader` and inlining `e.span` at every call site without bloating the bytecode.
- [x] **Peephole spread bug fixed** — `applyLocalRules` in `src/bytecode/peephole.ts` used `body.push(...out)` which tripped a RangeError when `out` exceeded the engine's spread-arg limit (~16k). Replaced with explicit `for … push` loops. The same-offset shortcut above made the cascade explosion non-issue, but the fix stays — other large-body fns benefit from the same robustness.
- [ ] **Methods (deferred)** — extending the rule to UFCS calls (`e.method()` valid when every variant has a callable `method`) is more invasive (overload resolution × variant set) ; leave as a follow-up after the field-access path is stable.
- [ ] **Nullable receivers** — `(T | null).f` follows the same gate today : `null` is a primitive variant lacking the field, so T3009 fires. Decide later whether to special-case nullable-receiver fields (TypeScript-style optional-chaining) — for now the user writes `match` explicitly.
- [ ] **Divergent-type policy** — when variants carry the same-named field with *different* types (`f: i32` vs `f: string`), the typechecker returns `unionOf` of both ; `unionOf` keeps them as a union (`i32 | string`) which the caller narrows. Verified working through the existing `unionOf` canonicalisation ; no extra wiring needed.

### 1.18 Built-in type aliases

Per SPEC §4 ("Built-in type aliases"), the compiler should recognise `int`, `long`, `float`, `double`, `byte` as transparent synonyms for their primitive counterparts.

Implementation is small and self-contained — no new IR nodes, no new passes:

- [x] **Resolver** (`src/resolver/builtins.ts`): add `int`, `long`, `float`, `double`, `byte` to `BUILTIN_TYPE_NAMES` so the resolver creates `builtin-type` symbols for them.
- [x] **Type-checker** (`src/typecheck/passes/type-expr.ts`): extend `primitiveFromName` to map `int → i32`, `long → i64`, `float → f32`, `double → f64`, `byte → u8`.
- [x] **Diagnostics**: error messages and snapshot dumps continue to show the *canonical* name (`i32`, not `int`) so the output is stable regardless of which alias the user typed.
- [x] **Tests**: add a snippet `tests/snippets/type_aliases/` that exercises each alias in a variable declaration, a function parameter, and a cast; verify the VM output matches.

### 1.19 Type-first design — remaining layers

Per `docs/DESIGN_TYPE_FIRST.md` §11–§14, the type-first redesign has 8 layers split across surface ergonomics (mostly landed) and architectural depth (mostly outstanding). Surface — bracketed `[T]`, `&` composition, trait composition, call-site bound enforcement, removed `$T` and `where` — landed via Layers 1.A–1.D, 2.A, 2.B (reflection primitives), 3.A–3.F, 7b/7c/7e, 8a. The remaining work below targets the architectural depth.

#### Layer 2 (full) — monomorphisation as comptime evaluation

Today the mono pass is a separate pipeline stage that walks call sites and produces specialised entries before lowering. Path 2 dissolves it into the comptime engine : `fn[T](...)` called at a site is *partially evaluated* with `T` bound, producing a specialised version. The cache key `(fn, args)` matches the current mono dedup ; the architectural shift is that the engine is the sole source of specialisation.

- [ ] **Identify the mono surface** — `src/monomorphize/index.ts` enumerates `MonoEntry` per concrete instance ; downstream phases (lower, bytecode, C-emit) consume the flat list. Catalog every consumer of `MonoProject` to know what the comptime engine must produce in its place.
- [ ] **Mono-as-comptime — interpreter path** — extend the AST-walking comptime interpreter (`src/comptime/`) so `call_generic_fn(fn, type_args, value_args)` either (a) returns a memoised previously-specialised entry from the cache, or (b) clones the fn body, substitutes the type-params, type-checks the clone, and registers the result. The registered entry is keyed by `(fn-id, hash(type-args))`.
- [ ] **Cache shape** — `Map<string, MonoEntry>` keyed by mangled name (already what mono produces). Reuse the existing `mangleName(fn, type-args)` so emitted symbols are stable. The cache must outlive a single comptime call and be consultable from the lower phase.
- [ ] **Replace the standalone mono pass** — once every generic instantiation flows through the comptime engine, delete `src/monomorphize/` and route the lowerer's "give me all entries" query to the comptime cache.
- [ ] **Test plan** — every snippet under `tests/snippets/generic_*` plus `tests/snippets/iter_combinators` exercises mono. Snapshot the bytecode for a representative subset before/after the migration ; bytecode bytes should be identical post-rewire (specialisation is structural, the engine just relocates *where* it happens).
- [ ] **Diagnostic preservation** — bound-violation diagnostics (T3033) currently fire from the mono pass via the `typeParamBounds` registry. They need to fire from the comptime engine post-rewire. Same span, same code, same message.

#### Layer 4 — `type` as a first-class comptime value

The architectural prerequisite for Phase 3 of the mono → comptime migration. Today the typechecker recognises `i32` in expression position as `TY.type` (TypeMeta) but the lower / bytecode / VM stack has no representation for a *value of type `type`* — historically `@comptime t :: i32` trapped with `reached unreachable`. Building this stack from the bottom up unblocks fn-form type aliases, computed type aliases, memoisation, and ultimately per-call-site partial evaluation.

##### Milestone B.0 — short-circuit `@comptime` type-alias decls (DONE)

- [x] **Short-circuit type-alias bake** — when `@comptime` is applied to a const whose RHS is structurally a type expression (e.g. `@comptime t :: i32`), the typechecker has already pre-resolved the underlying Type into `constTypeAliases`. `evaluateProject` now checks that table before queuing the VM bake and synthesises a `ComptimeValue.type` directly. Unblocks the common type-alias-as-comptime-decl case without introducing TypeValue plumbing through the VM. Snippet : `tests/snippets/comptime_type_alias/`.
- [x] **`ComptimeValue.type`** added to the comptime value union with a `displayValue` case and a `typeVal()` builder. Conversion `comptimeToValue` traps for now — type values that flow through dependency wiring read the ComptimeValue directly without VM round-trip.

##### Milestone B.1 — `Type` as a VM Value

End-to-end : a Type value flows through the bytecode VM, observable as a runtime value at comptime.

- [ ] **VM Value variant** — add `TypeValue { tag: "type", typeIndex: i32 }` (or carry the `Type` IR by ref) to `src/vm/value.ts`. The `typeIndex` keys into a project-wide type table interned at bytecode-emit time.
- [ ] **Bytecode op `type.const`** — push a Type value referencing the type-table entry. Add to `src/bytecode/ops.ts`, `src/bytecode/text.ts` (textual `.virt` round-trip), and `src/bytecode/binary.ts` (binary `.vir` round-trip).
- [ ] **Type table on `BytecodeModule`** — `typeTable: BcType[]` already exists for struct/array layout. Extend so `Type` values can index into it ; emit the canonical interning of any type referenced by `type.const`.
- [ ] **Lower IdentExpr → LoweredTypeConst** — when an IdentExpr has type `TypeMeta` (i.e. resolves to a builtin-type / struct / type-alias symbol read in expression position), lower to a new `LoweredTypeConst { type: Type }` instead of treating it as a value reference. Also covers `null`, `type`, primitive names.
- [ ] **Bytecode emit `LoweredTypeConst` → `type.const`** — intern the `Type` in the type table, emit the indexed op.
- [ ] **VM op handler** — `type.const` pushes `{ tag: "type", typeIndex }` ; the `typeIndex` resolves to a `Type` via the module's type table when consumed by the comptime engine.
- [ ] **ComptimeValue gains a `type` case** — `{ kind: "type", t: Type }` in `src/comptime/value.ts`. Conversion `valueToComptime` / `comptimeToValue` in `src/comptime/run.ts` round-trips Type values.
- [ ] **Test snippet** — `tests/snippets/comptime_type_value/` with `@comptime t :: i32` and a downstream `@assert(@size_of(t) == 4)` once we have type-value-typed args (deferred to B.2).

##### Milestone B.2 — Type values flow through intrinsics

`@size_of`, `@type_name`, `@type_kind`, etc. accept a *Type value* in addition to the existing type-expression syntactic form. Same for `@type_of(x)` returning a Type value usable downstream.

- [ ] **`@type_of(x)`** new intrinsic returning the static type of a value as a Type value.
- [ ] **Reflection intrinsics accept comptime Type values** — `@size_of(t)` where `t: type` is a comptime-evaluable expression. Currently the parser's `IntrinsicCallExpr` arg with `kind: "type"` calls `lowerExprAsType(arg, ...)` which only handles syntactic forms ; extend to fold a Type-value argument into its underlying `Type` for the intrinsic's static result.
- [ ] **Test snippet** — `@comptime t :: i32 ; @comptime sz :: @size_of(t) ; @assert(sz == 4)`.

##### Milestone B.3 — Type-typed bindings in comptime context

`let T: type = i32` works inside `@comptime` decls and in fn bodies where the resulting `T` flows to other type-demanding slots (Layer 5b — comptime contagion enforcement comes for free here).

- [ ] **Resolver** — type-typed bindings introduce a Symbol carrying a Type value at comptime evaluation time.
- [ ] **Typechecker** — when a binding is `: type`, the value expression must produce `TY.type` (already enforced via expected-type propagation) ; the binding's downstream uses are typechecked against the *resolved* underlying Type, not the static `TypeMeta`.
- [ ] **Lower** — the binding stores a Type value at runtime ; at use sites in type position, the lowerer resolves the binding's value to the underlying Type.
- [ ] **Diagnostic T3035 "type expression must be comptime-evaluable"** — closes Layer 5b (rejects `let t: type = if user_input { i32 } else { i64 }` via the comptime-only static-type rule).

##### Milestone B.4 — Type-yielding operations

Generic application (`MutableMap[i32, string]`), unions (`T | U`), intersections (`T & U`) all evaluate to Type values at comptime. Today they're parsed as `GenericInstExpr` / `BinaryExpr(.BitOr)` / `BinaryExpr(.BitAnd)` ; in expression position with comptime evaluation, they should produce a Type value.

- [ ] **`GenericInstExpr` in value position** — when typechecker sees `MutableMap[i32, string]` and the result is `TY.type`, lower to a `LoweredTypeConst` of the resolved `Struct(MutableMap, [i32, string])`.
- [ ] **`BinaryExpr(.BitOr/.BitAnd)` in value position with `TY.type`-typed operands** — produces a union/intersection Type value. Lower to `LoweredTypeConst` after canonicalisation via `unionOf`.
- [ ] **Memoisation** — `MutableMap[i32, string]` evaluated from two call sites yields the *same* Type identity. Cache by `(generator-symbol, type-args)` in the comptime engine. Structural identity for unions/tuples already canonicalised by `unionOf`.

##### Milestone B.5 — fn-form type aliases

The crowning piece — `boxed :: fn[T]() = if @size_of(T) > 16 { Heap[T] } else { Stack[T] }` evaluated at the call site to produce a Type. This is the Layer 4 sugar of the design doc.

- [ ] **Comptime engine drives evaluation** — when a generic fn whose body returns `TY.type` is called with concrete type args, the comptime VM evaluates the body and the result is the call site's resolved type.
- [ ] **Type-yielding fn signature** — typechecker recognises a fn whose return type is `type` (or whose body's static type is `type`) and routes its calls through the comptime engine.
- [ ] **Phase 3 of the mono migration unblocked** — once a fn body can produce a Type at comptime, partial evaluation per call site (the original Phase 3) is just the natural composition of B.4 + B.5.

##### Milestone B.6 — Computed type aliases via `type` keyword

`Maybe :: type[T] T | null` (Vader's TypeAliasDecl surface ; the design doc spells it `type Maybe[T] = T | null`) and `Pair :: type[A, B] struct { first: A, second: B }`. The TypeAliasDecl path handles the union-returning form ; the struct-literal-as-type-expression form needs the comptime engine to fold the struct literal into a Type value.

- [x] **Verified** `Maybe :: type[T] T | null` and `Pair :: type[A, B] A | B` work end-to-end via TypeAliasDecl with bracketed type-params. Snippet : `tests/snippets/generic_type_alias/`. Required a typecheck fix in `typeFromSymbol`'s `type-alias` arm — type-param symbols live in their decl's local scope (registered by `bindTypeParam`), not in `module.symbols` ; switched to `buildStructSubst` which already had the right plumbing.
- [ ] **Add struct-literal-as-type** — `Pair :: type[A, B] struct { first: A, second: B }`. The body is a struct literal *expression* whose static type is `TypeMeta` ; the comptime engine evaluates it into a (synthesised, anonymous) `Struct` Type.

#### Layer 5a — uniform `[]` for type-args at call sites

- [ ] **Verify call-site override** — `sum[i64](arr)` form. Confirm it parses and typechecks ; if not, wire it through `parseCall` / `inferCall`.
- [ ] **Reject the legacy `()` call-site form for type-args** — once `[]` is universal, decide whether `MutableMap(K, V)` at the call site (currently still accepted) emits a deprecation warning. Track separately to avoid breaking stdlib.

#### Layer 5b — comptime contagion

- [x] **Accept `t :: <structural-type-expr>` as in-fn type alias** — when a `::` (immutable) let-stmt's RHS is structurally a type expression (gated by the same `looksLikeTypeExpression` predicate the top-level const-decl path uses), the typechecker pre-resolves it into `letTypeAliases` keyed by the local's symbol. Lower skips emitting a runtime slot ; downstream type-position references resolve via `typeFromSymbol`'s "local" arm. Mirrors the top-level `Maybe :: i32 | string` Layer 4-sugar implicit alias. Snippet : `tests/snippets/let_type_alias/`.
- [x] **Reject other `type`-valued locals at typecheck (T3035)** — `t: type = ...` (with explicit `: type` annotation, including the conditional `t: type = if ... {} else {}`) and `t :: <non-structural-type-expr>` (conditional types like `t :: if ... { i32 } else { i64 }`) all emit T3035 with a hint pointing to the working `t :: <type-expr>` form or a top-level alias. Snippet : `tests/snippets/type_valued_local_rejected/`.
- [ ] **Accept conditional type expressions** — `t :: if @size_of(i32) > 16 { i64 } else { i32 }` : requires the comptime VM to be able to evaluate `if`/`match` over Type values. Blocked by Layer 4 milestone B.1 (TypeValue end-to-end). Once B.1 lands, extend `looksLikeTypeExpression` to recognise `if`/`match` exprs whose branches are all type-shaped, and have the typechecker invoke the comptime engine to fold them.
- [x] **`i32[]` in let-stmt value position** — `t :: i32[]` (and top-level `ArrayInt :: i32[]`) now works. `inferExpr` returns `TY.type` for `ArrayTypeExpr`/`FnTypeExpr` instead of trapping ; `looksLikeTypeExpression` already accepted them, so the alias path picks them up. The resolver's value-position arm walks the inner type-position expressions through `resolveType`. **Caveat — `fn(i32) -> i32` in value position still fails** : the Pratt parser's `parseLambda` reuses `parseFnSignatureParams` (which expects named params `name: type`), so for `fn(i32)` the `i32` is treated as the param NAME and the missing type yields the placeholder `?`. Tracked separately ; needs a fn-type re-interpretation pass when the body is missing.

#### Layer 6 — reflection iteration

- [ ] **`@type_of(x)`** — returns the static type of a value as a `type`-typed comptime value. Useful inside `@derive` style generic code.
- [ ] **`@fields(T) -> Field[]`** — returns the comptime-known list of fields, where `Field :: struct { name: string, type: type, offset: usize }` lives in `std/reflect`. Replaces `@field_count` + `@field_index` by carrying all metadata together. Keep both old intrinsics as low-level primitives ; `@fields` is the ergonomic surface.
- [ ] **`@type_args(T)`** — generic args of a generic instance. `@type_args(MutableMap[i32, string])` returns `[i32, string]` as a `type[]`.
- [ ] **`@field(x, name) -> ?`** — dynamic field access by comptime string. Return type depends on `name` (resolved at comptime). Lowers to a tag-dispatch over `T`'s field set.
- [ ] **`@comptime for f in @fields(T) { ... }`** — iteration syntax. The `@comptime` prefix forces comptime evaluation ; the loop unrolls. Requires a parser change (recognise `@comptime for`) plus the lowerer expanding the loop into a sequence of substituted bodies. Touches : parser, typechecker, lowerer.

#### Layer 7d — non-trait predicates on generics (open question)

`where` was removed entirely (commit `f367aee`) and the bracketed form `[T: Bound]` is now the only bound syntax. The DESIGN_TYPE_FIRST.md plan was to re-introduce `where` later for predicates that don't fit the `T: Bound` shape (`where @size_of(T) <= 64`, `where @type_kind(T) == "struct"`). Status today : not committed — first decide whether to bring `where` back as a keyword, expose the predicate via a different syntax (`[T satisfies @size_of(T) <= 64]` ?), or simply forgo non-trait predicates until a real use case shows up. Layer 7e's bracketed-bound enforcement covers the trait-bound subset already.

#### Layer 7a/7e — bounds as comptime predicates (architectural)

Currently bounds are enforced via the impl registry walk (`src/typecheck/passes/call.ts`). Path 2's vision is that they desugar to `@satisfies` comptime calls. Net effect today is identical ; the rewrite is for architectural uniformity once the comptime engine handles all type-level work :

- [ ] **Rewrite `[T: Trait]` enforcement** to lower to `@satisfies(T, Trait)` evaluated by the comptime engine, replacing the current direct registry walk.
- [ ] **Trait method dispatch on bounded type-param** — currently uses `traitMethodResolutions`. Once bounds are comptime predicates, the trait obligation becomes a comptime fact and dispatch is monomorphised at the generic call site. Same end result, cleaner mechanism.

#### Layer 8 — impl & coherence

Mostly done by virtue of Vader's existing `Type implements Trait[Args]` form, but several rules need explicit verification or implementation :

- [x] **8b — implements verifies inherent methods** — `declareImpl` now walks the trait's required methods and fires T3036 ("impl block missing required trait method") for any that aren't provided in the impl block. SAM-synthetic and `@intrinsic` materialisations already populate members in the resolver before the check runs, so they pass naturally. Snippet : `tests/snippets/impl_missing_method/`.
- [x] **8c — explicit conformance, no structural inference** — verified working today : a struct with a matching method but no `implements` line emits T3006 ("trait not satisfied") at the generic call site. Snippet : `tests/snippets/conformance_explicit/` covers `Vec3` with a free `add` fn that fails to satisfy `[T: Add]`.
- [x] **8d — default-method injection at `implements` site** (2026-05-10). New `materializeDefaultMembers` in `src/resolver/resolve.ts` runs after `materializeSamMembers` / `materializeIntrinsicMembers` ; for every trait method with a body that the impl didn't override, push a fresh FnDecl whose body is `structuredClone`'d from the trait's. Cloning keeps each impl's per-node side-tables distinct from the trait's own. Self/trait-arg substitution flows through `substituteTypeExpr` for the signature ; the body is re-resolved against the impl scope so references to other trait methods (`self.equals(other)`) UFCS-resolve to the impl's own member. SAM-form gate (`R2016`) updated to count only *required* (body-less) methods so single-required traits with extra defaults still accept the arrow form. Adopted in stdlib : `Equals.not_equals` (derived from `equals`), `Comparable.lt`/`lte`/`gt`/`gte` (derived from `compare`). Snippet : both `op_overload_eq_ord` (SAM-arrow Equals + classic Comparable) and the existing trait tests pass without overriding the defaults.
- [x] **8e — orphan rule (light)** — `resolveImplDecl` now rejects `Type implements Trait[Args]` when neither `Type`'s nor `Trait`'s owning module is the current module. Diagnostic R2018 ("orphan impl forbidden"). Primitives (`i32`, `string`, …) are exempt — any module can implement traits on them, since Vader has no newtype-pattern infrastructure to recover the use case otherwise. Snippet : `tests/snippets/orphan_impl_forbidden/` exercises module A defining `Foo`, module B defining `Bar`, main module trying `Foo implements Bar` — R2018 fires.
- [x] **8f — ambiguous trait-method dispatch diagnostic** (2026-05-10). `findImplMethod` (`src/typecheck/passes/call.ts`) now collects every impl that matches the receiver type *and* declares a member of the requested name. When ≥ 2 of those impls belong to *different* traits, T3032 fires at the field span listing the traits. The first match still wins for the resolution (kept resolvable so downstream phases don't cascade), but the user is now told there's an ambiguity to resolve. Multiple impls of the *same* trait on the same type are NOT flagged — that's a separate coherence issue ; user-overrides like `i32 implements Display` in `tests/snippets/primitive_impl/` already rely on the take-first-impl-wins behaviour. Snippet : `tests/snippets/trait_method_ambig/`.

#### Open questions deferred

- **Q8** — comptime evaluation budget (Zig has one ; Vader doesn't). Decide once Layer 2 lands and we can measure typical evaluation depth on the stdlib.
- **Q10** — hygienic macros vs `@comptime for`-only. `@comptime for` covers ~95% of macro use cases ; revisit only if real demand surfaces.
- **Q11** — migration phasing. Path 2 is the chosen path ; the layer-by-layer landing is the migration plan.

---

## Phase 2 — Self-hosting

Begin as soon as the TS compiler can compile a non-trivial subset (functions, structs, arrays, strings, control flow, generics, traits). The goal is to validate the design *as we go*, not to wait for a finished MVP.

### 2.0 Vader CLI minimal (parity-check harness)

Stand up a `vader` binary written in Vader so each ported phase can compare its dump against the TS reference output side-by-side. Drives the snapshot-parity workflow for §2.1+ and surfaces the next compiler bug to fix as soon as we hit it.

- [x] `vader/cli/main.vader` — argv parsing (`--stage=<name> <file>`), file read via `std/io.read_file`, dispatch on stage name.
- [x] `vader dump --stage=lexer` — emits the `# Tokens` block in the same format `tests/snapshot.ts:formatTokens` produces (line:col span, kind name, JSON-quoted text, optional `=value` for literals, `# Diagnostics` block for errors). Lexer parity sweep on the snippet corpus : 102/104 (2026-05-07). The 2 outliers are UTF-8 multi-byte fixtures hitting the byte-indexed `std/string.char_at` limitation, not a CLI bug.
- [ ] Snapshot parity rig under `tests/parity/` — script that runs both `bun src/index.ts run vader/cli/main.vader dump --stage=lexer <file>` and `bun src/index.ts dump --stage=lexer <file>` over every snippet under `tests/snippets/` and diffs the outputs. Today this is an inline shell loop ; promote to a real test once the CLI is built native.
- [ ] **Build the CLI native** so `vader-cli` is a real binary and the parity rig doesn't pay the bun-startup cost per snippet.
- [ ] Future stages plug into the same dispatch as the parser / typechecker / lowerer get ported (§2.1+).

### 2.1 Port the parser to Vader

#### Lexer (`vader/lexer/`) — substantial progress

- [x] Token kinds (`vader/lexer/token.vader`) — `TokenKind :: enum(u8)` mirroring `src/lexer/token.ts`.
- [x] Keywords + numeric-suffix tables (`vader/lexer/keywords.vader`) — `lookup_keyword`, `is_int_suffix`, `is_float_suffix`.
- [x] Driver state + cursor helpers (`vader/lexer/lexer.vader`) — `Lexer` struct, `peek`/`peek_at`/`advance`/`position_here`/`at_end`.
- [x] Whitespace, line comments (`//`), nested block comments (`/* /* */ */`).
- [x] Identifiers + keyword recognition.
- [x] Numeric literals : decimal + hex (`0x`/`0X`) + binary (`0b`/`0B`) + octal (`0o`/`0O`), `_` separators, integer suffixes (`i8..i64`/`u8..u64`), float (`.<digits>`, exponent), float suffixes (`f32`/`f64`).
- [x] Char literals + escapes : `\n \t \r \\ \' \" \$ \0`, `\u{HEX}` (1–6 digits, ≤ U+10FFFF). Recovery on bad escape / multi-codepoint.
- [x] String literals : plain `"..."`, raw `r"..."`, triple `"""..."""`. Token sequence `StringBegin / StringPart / InterpOpen / InterpClose / StringEnd` per SPEC.
- [x] Interpolation : `${expr}` + `$ident`, nested via `interp_stack: [InterpFrame]` with brace-depth tracking. Newlines absorbed inside `${...}`.
- [x] One- / two- / three-char operators, range ops `..<` / `..=`, brackets, punctuation.
- [x] Newline emission with SPEC §3 SUPPRESS_AFTER set ; `paren_depth` for `(`/`[` (not `{`).
- [x] Shebang on line 1, UTF-8 BOM at file start.
- [x] Structured diagnostics : `errors: [Diagnostic]`, typed `LexerCode` enum, `error_span(start)` helper, `render(d) -> string` for terminal output.

#### Diagnostics (`vader/diagnostics/`)

- [x] `codes.vader` — `LexerCode :: enum(u8)` (10 variants), `CodeInfo :: struct { id: string, message: string }`, `info(c) = match c { ... }` returns canonical `(L0001, "unexpected character")` pairs. `DiagCode :: type LexerCode` (alias, will widen to a union once parser/resolver/typecheck land their codes).
- [x] `diagnostic.vader` — `Severity` enum, canonical `Position` / `Span` (used by both tokens and diagnostics), `Diagnostic { severity, code, detail, primary }`, `make`/`error` constructors, `render` (single interpolated string).
- [ ] **Folder-module migration** (deferred) — `vader/diagnostics/{codes,diagnostic}.vader` resolve as two separate single-file modules today, so the `private` modifier on `CodeInfo` / `info` doesn't survive cross-file. Migrating to a folder-module would let us hide internals.

#### Lexer parity validation

- [ ] **Snapshot parity with the TS lexer** — once the Vader CLI lands (§2.0), run both lexers over `tests/snippets/*` and compare the `# Tokens` blocks. Any mismatch is either a Vader-lexer port bug or a missing feature ; fix and re-snapshot.

#### Parser (`vader/parser/`) — substantial progress (2026-05-07)

- [x] **AST representation** (`vader/parser/ast.vader`) — every node ported as a Vader struct, every TS sum-type as a `:: type` discriminated union. Field-name caveat : `type` is a Vader keyword, so `StructField.type` / `FnParam.type` / `ConstDecl.type` etc. are renamed `ty` (the dumper still emits `"type"` as the JSON key for snapshot parity).
- [x] **`ParserCode` enum + `parser_info()` lookup** added to `vader/diagnostics/codes.vader` (P1001..P1020 mirroring `src/diagnostics/codes.ts:PARSER`). `Diagnostic.code` was simplified from `LexerCode | ParserCode` to a resolved `CodeInfo` because the runtime can't dispatch `match { is EnumA -> ... is EnumB -> ... }` over a union of two enum-types — each phase now stamps the wire `(id, message)` at construction via typed `error(LexerCode, ...)` / `parser_error(ParserCode, ...)` shortcuts.
- [x] **Parser body** (`vader/parser/parser.vader`, ~2200 lines) — recursive-descent for declarations / statements / types, Pratt for expressions (binding-power table mirroring `src/parser/passes/expr.ts:25-53`). Token-stream helpers (`peek`, `peek_at`, `check`, `match_kind`, `advance`, `expect`, `skip_newlines`) on a `Parser` struct.
- [x] **AST → JSON dumper** (`vader/parser/dump.vader`) — byte-for-byte parity with `tests/snapshot.ts:formatProgram`. 2-space indent, span-stripping, BigInts as `"<n>n"`, JSON-escaped strings.
- [x] **CLI integration** — `vader dump --stage=ast <file>` runs the Vader parser through the same dispatcher as `--stage=lexer`.
- [x] **Parity test rig** : `tests/parser_parity.test.ts` runs `./build/vader dump --stage=ast` over every `tests/snippets/*` and diffs against the existing `parser.snapshot`. **128 / 130 snippets pass byte-for-byte today** ; the 2 remaining skips are CJK/multi-byte (see §1.13).

##### Open Vader-language / runtime issues uncovered while porting (fix to unlock the remaining 40 snippets)

- [x] **`as <name>` binding in match arms traps at runtime — fixed 2026-05-07.** Two compounding bugs in the lowerer + typechecker. (1) The lowerer's `introducePatternBindings` minted a fresh synthetic Symbol for the binding, unrelated to the resolver-side Symbol that the body's `IdentExpr` resolves to via `idents` — so the `LoweredLet`'s slot was unreachable from the body and `p.x` lowered to `unreachable`. Fix : new `patternBindings: Map<IsPattern | BindingPattern | StructPatternField, Symbol>` side-table on `ResolvedProgram`; `bindPattern` populates it; the lowerer reuses the recorded Symbol. (2) The typechecker only narrowed the *scrutinee* symbol — bindings stayed at `Unresolved`, so field access on them tripped `kind !== "struct"` in the bytecode emit. Fix : `pushBindingNarrowings` extends the narrowing stack to cover `is T as p` (binding ↦ `T`) and `BindingPattern x` (binding ↦ scrutinee type). (3) `IsPattern` lowering didn't recurse into `pattern.inner` (StructPattern), so nested field bindings produced no `LoweredLet`. Fix : recurse on the same scrutinee. Regressions : `tests/snippets/match_is_as_binding/` (P/Q/null with bound aliases), `match_struct_pattern_binding/` (`is P { x: 10, name }`). Parser-parity rig went from 70/110 to 82/110 (12 KNOWN_FAILURES cleared).
- [x] **Match dispatch on primitive-only union — also fixed by the `as <name>` chain (2026-05-07).** The original repro turned out to be the same root cause as `is X as p` ; once the binding/narrowing flow was repaired, `match t.value { is i64 -> ... is f64 -> ... }` over a `i64 | f64 | u32 | string | null` scrutinee dispatched correctly. No separate runtime/primitive-tag-table bug.
- [x] **Match on union of enums — also fixed by the `as <name>` chain (2026-05-07).** Once the binding/narrowing repair landed, `match d.code { is LexerCode -> ... is ParserCode -> ... }` dispatches correctly. The earlier `Diagnostic.code → CodeInfo` flattening can be reverted whenever the rewrite is convenient.
- [x] **`match X.field { is Y as t -> ... }` — fixed 2026-05-07.** Same chain : the lowerer's `LoweredCast` on the binding's narrowing now emits a real `local.set` for the bound symbol, and the C/VM emit reads the right struct slot. The ~25 hand-rolled rebinds in the Vader parser/dumper can be cleaned up at any time (cosmetic, no longer required).
- [x] **`if !bool_var { ... }` — fixed 2026-05-07** as a side effect of the `if` no-else fix below. The repro in `parse_struct_type_param_list` was a *false negative* : the body's trailing expression made the if widen to `T | void`, and the bytecode emitter inserted `else; unreachable`, which crashed when the condition was *false* (which happened to be the `if !first { ... }` case in the loop). The `lowerIf` no-else fix made this go away.
- [x] **`enum_basic` family (4 snippets) — fixed 2026-05-07.** The trap wasn't actually in `parse_enum_decl` per se : it was in the bytecode-emit's handling of `if cond { body }` without an `else` branch, and `parse_enum_decl` happens to use that exact shape (`if parens.matched { repr = p.parse_type(); p.expect(.RParen, ...) }`). The block's trailing `p.expect()` returns a `Token`, so the typechecker widened the if to `Token | void`. The bytecode emitter then synthesised `else; unreachable` to satisfy the `if ref` arm-shape, crashing whenever the condition was false. Fix : `lowerIf` (`src/lower/passes/expr.ts:447`) detects the no-else case, discards the then-block's trailing value (re-wraps it as a final `LoweredExprStmt`), and forces the if's type to `void` — matching Rust/Kotlin/Swift semantics. Bonus cleanup : added `variantSpan` and `valueSpan` to `SPAN_KEYS` in `tests/snapshot.ts` so the TS dumper strips them like the Vader dumper does, removing a parity blocker on the same enum snippets. Regression : `tests/snippets/if_without_else_stmt/`. Parser-parity rig went 82/110 → 86/110 (4 enum snippets cleared).
- [x] **Trait/impl-heavy snippets — cleared 2026-05-07** by the cumulative is-as-binding + if-no-else fixes. No standalone trait-specific bug ; the 6 snippets all transit through one of those two code paths.
- [x] **Other diverging snippets — bulk-cleared 2026-05-07.** Most issues fell out of the same two fixes. Two small follow-ups landed alongside : (a) `tests/snapshot.ts:SPAN_KEYS` now strips `variantSpan` and `valueSpan` so the TS dump matches the Vader dump (which never emitted them) ; (b) `vader/lexer/dump.vader:dump_diagnostics` now sorts by `(offset, code)` to mirror `DiagnosticCollector.sorted()` so ties at the same `line:col` come out in a stable order ; (c) `write_f64` drops a trailing `.0` to match `JSON.stringify(10)` → `"10"`.

- [x] Snapshot-test parity : **128 / 130** today (2026-05-08, post-tuple-migration). Remaining two skips (`std_string`, `std_string_builder`) hit a CJK/multi-byte UTF-8 limitation in `std/string.char_at` (byte-indexed instead of codepoint-indexed) — stdlib bug, not a parser-port bug. Tracked as a separate item in §1.13.

### 2.2 Port the C emitter

- [ ] Port to Vader
- [ ] Snapshot-test parity

### 2.3 Port the bytecode emitter

- [ ] Port to Vader
- [ ] Snapshot-test parity

### 2.4 Port the VM

Incremental strategy + sprint breakdown: [`docs/SELFHOST_VM.md`](./docs/SELFHOST_VM.md).
The Vader VM reads the same `.virt` text dump the TS toolchain produces,
so each sprint validates against the live TS pipeline without waiting on
the typer/lower/bytecode emit port (§2.6 / §2.3).

- [ ] **Sprint 1** — `i32.const` + `return` only ; `vader run return_42.virt` exits 42
- [ ] Sprints 2-5 — locals, binops, control flow, strings, structs, arrays, calls, type checks
- [ ] Sprint 6 — binary `.vir` loader (optional ; the text loader keeps parity through 2-5)
- [ ] Verify it runs `examples/` against the TS VM

### 2.5 Port the WASM emitter — gated on Phase 3 (§3.10)

The TS WASM emitter doesn't exist yet (moved to §3.10). When it lands,
port it to Vader at that point. Until then this slot is empty.

### 2.6 Port the type-checker (last)

- [ ] Port to Vader
- [ ] Snapshot-test parity on every sample

### 2.7 Bootstrap success check

- [ ] Compile the Vader compiler with the TS compiler → `compiler_v1`
- [ ] Compile the Vader compiler with `compiler_v1` → `compiler_v2`
- [ ] Verify `compiler_v1` and `compiler_v2` produce identical outputs on every sample
- [ ] Verify two generations are idempotent: `compiler_v2 == compiler_v3`

### 2.8 Freeze the TS compiler

- [ ] Tag a final TS compiler release
- [ ] Move it to `archive/` (read-only)
- [ ] Document the bootstrap procedure in `BOOTSTRAP.md`

---

## Phase 3 — Post-MVP

Items not gated by the MVP. Pull in roughly the order shown, but feel free to reprioritise.

### 3.1 Concurrency

- [ ] `async` / `await` keywords
- [ ] Lower `async fn` to state machines
- [ ] Cooperative scheduler in the runtime (single-threaded)
- [ ] (Stretch) Kotlin-style coroutines

### 3.2 Native threads

- [ ] `std/thread` module — `spawn`, `join`, atomics, channels
- [ ] Compile-time error if imported on the WASM target

### 3.3 Networking & web

- [ ] `std/net` — TCP, UDP, HTTP client
- [ ] WASI target support
- [ ] Auto string marshalling between Vader and JS
- [ ] Browser-side runtime helpers (publish a small JS package)

### 3.4 Stdlib expansion

- [ ] **`std/json` v2 — compile-time-generated parsers** (kotlinx-serialization style). Today's `std/json` (§1.13b) is a runtime recursive-descent parser working on `JsonValue` unions. Post-MVP, generate per-struct parsers at compile time : `@derive(Json) MyStruct :: struct { ... }` produces a typed `MyStruct.from_json(s) -> MyStruct!` via a comptime decorator that walks the struct's fields and emits the parsing code. Faster (no `JsonValue` boxing) and gives type errors at compile time. Requires the `@derive` machinery (§3.8).
- [x] **`std/regex` — full pattern engine** (2026-05-15). Thompson NFA via Cox's VM (Inst array of `InstChar` / `InstAny` / `InstClass` / `InstMatch` / `InstJump` / `InstSplit` / `InstSave` / `InstAnchorStart` / `InstAnchorEnd`). Supported : literals + escapes (`\n` / `\t` / `\r` / `\\`), char classes `[abc]` / `[^abc]` / `[a-z]`, shorthand `\d` / `\D` / `\w` / `\W` / `\s` / `\S`, `.`, quantifiers `*` / `+` / `?` / `{n}` / `{n,}` / `{n,m}` (all greedy), alternation `a|b|c` (N-ary chained Split), capture groups `(…)` (Cox shift-based threading, group 0 = whole match), anchors `^` / `$` (input boundaries, not multiline). API : `compile(pattern) -> Pattern | RegexError`, `matches` / `find` / `find_all` / `replace_all` (with `$0`..`$9` backrefs). Pure Vader, zero host imports — WASM-ready as-is. ~750 LoC. 11 `@test`s + snippet `tests/snippets/std_regex/` covering every supported construct including the compile-error path. Hors-scope (post-MVP) : non-greedy `*?`, named groups, backrefs `\1`, lookahead/lookbehind, Unicode classes. Bonus fix : `SLOT_UNSET :: usize(0xFFFF_FFFF_FFFF_FFFF_u64)` — without the `_u64` suffix the literal defaults to `i32` / `i64` and rounds through f64 on the cast, so the sentinel collided with valid offsets on native (group 0 surfaced as empty string). Documented in the module.
- [x] **`std/time` — instants, durations, formatting** (2026-05-15). `Instant` (wall-clock ns since Unix epoch), `Monotonic` (process-stable ns since opaque epoch), `Duration` (signed i64 ns). Constructors `nanos` / `micros` / `millis` / `seconds`. Clocks `now()` / `monotonic()` route through two `@intrinsic` host imports (`now_unix_ms`, `monotonic_ns`) wired to `clock_gettime(CLOCK_REALTIME|MONOTONIC)` natively and `Date.now()` / `performance.now()` on the TS VM. Arithmetic : `since` / `elapsed` / `add` / `sub` / `plus` / `minus`. Pure-Vader ISO 8601 round-trip (`format_iso8601` / `parse_iso8601`) via Hinnant's `days_from_civil` / `civil_from_days`. Snippet `tests/snippets/std_time/` + 9 colocated `@test`s. WASM-ready : the 2 host imports map to `wasi_snapshot_preview1.clock_time_get` when the emitter lands.
- [x] **`std/random` — PRNG (deterministic seeds)** (2026-05-15). xoroshiro128++ (Blackman & Vigna 2021), 2^128 period, u64 output. Constructors `new_seeded(u64)` and `new_from_clock()` (uses `std/time.monotonic_ns`) ; seed=0 still produces a non-degenerate state via splitmix64 fan-out. Surface : `next_u64` / `next_u32` / `next_bool` / `range_i32` / `range_u32` / `unit_f64` (52-bit mantissa to avoid `(2^53 - 1) / 2^53` rounding to 1.0) / Fisher-Yates `shuffle[T]`. Pure Vader, zero host imports. Self-host VM divergent (`Convert` op no-op limitation, tracked separately) ; native + TS VM identical. 7 `@test`s + snippet `tests/snippets/std_random/`.
- [x] **`std/crypto` — at least hashes (SHA, MD5)** (2026-05-15). SHA-256 (RFC 6234) and MD5 (RFC 1321), both in pure Vader. Hex-string output (lowercase, matches `shasum -a 256` / `md5sum`). Zero host imports — WASM-ready as-is. Explicit `mask32` after every u32 op (the TS VM stores u32 as a JS number and won't wrap on overflow). 7 `@test`s against the published vectors (`""`, `"abc"`, the quick-brown-fox phrase, plus a multi-block 56-byte input) + snippet `tests/snippets/std_crypto/`. Self-host VM divergent (same `Convert` no-op u8 → u32 issue as std/random) ; native + TS VM identical. Bonus : `runtime/c/vader.h` time intrinsics now gate `_WIN32` to `GetSystemTimePreciseAsFileTime` + `QueryPerformanceCounter` so the Windows cross-compile build keeps working.
- [x] **`std/base64` — RFC 4648 encode + decode** (2026-05-15). Standard alphabet (`A-Z a-z 0-9 + /`), strict `=` padding. `encode(string) -> string`, `decode(string) -> string!` (raw bytes returned as a byte-indexed string). Decode rejects non-multiple-of-4 lengths and any non-alphabet byte ; whitespace is the caller's problem. Pure Vader, zero host imports. 7 `@test`s including the RFC 4648 §10 reference vectors + a roundtrip set + two error paths + snippet `tests/snippets/std_base64/`. URL-safe variant (`- _`, optional padding) deferred — drop-in alphabet swap when needed.
- [ ] **`std/bignum` — `BigInteger` / `BigDecimal`** — arbitrary-precision integer and decimal arithmetic. Pure-Vader implementations (digit array + carry/borrow loops, Newton-Raphson for division) so the WASM target stays viable. Use cases : (a) JSON parsing without precision loss past 2^53 — currently `JsonNumber` stores f64 (cf. `std/json` v2 in §3.4) ; (b) money / financial DSLs where binary float rounding is unacceptable ; (c) crypto bignums (RSA, ECC) before `std/crypto` lands. Estimate ~600-1000 LoC each. `BigInteger` first since `BigDecimal` reuses its arithmetic.

### 3.5 Performance

- [x] Generational GC — generational Cheney copying GC lives in `runtime/c/vader_runtime.c` : two generations (young 4 MB Eden + Survivor, old 16 MB), age-tag tenuring (`VADER_TENURE_AGE`), card table for cross-gen pointer tracking (`VADER_CARD_BYTES = 512`). Allocation bump-points into young from-space ; minor GC forwards survivors to young to-space or promotes to old once `age >= VADER_TENURE_AGE` ; major GC drains young first then Cheney-collects old. Knobs : `VADER_GC_YOUNG_BYTES`, `VADER_GC_OLD_BYTES`. Acceptance covered by `tests/snippets/gc_*` (chain_survive, multi_collect, array_survive) + the full leak baseline.
- [x] **`vader_array_push` loses one entry at the array-doubling step under double-GC pressure** (fixed 2026-05-14). Surfaced by `bench/string_builder.vader` : a builder pushing ~80 000 fragments produced output exactly one fragment short of expected. Root cause traced via runtime instrumentation : `vader_array_buf_alloc` inside the grow path can run **both** a minor and a major collect when one cycle doesn't free enough space. After the minor, the young from/to halves swap ; the major's internal drain swaps again, so the *original* `a` address ends up in young to-space and gets recycled by the fresh-buf allocation that follows. The fresh buf's header overwrites `a`'s forwarding pointer (logged as `type=0xFFFFFFFE` (ARRAY_BUF) `fwd=0x0`), so `vader_array_resolve` walks no chain and we end up writing fresh-buf fields as if they were the array struct's. Net : one push silently drops, the next push re-triggers the grow with the *correct* `a` (caller's `t1` root tracks it via `scan_box`) and recovers — but the previously-pushed value is lost. Fix lands in `runtime/c/vader_runtime.c:vader_array_push` : box `a` into a local `vader_box_t` rooted on the shadow stack across `vader_array_buf_alloc`. The GC's `scan_box` re-updates `a_box.payload.obj` on every cycle (no forward-chain walk needed), so we reload `a` from the box afterwards. Same trick for `v` whose payload may also need forwarding. The doc'd 4 MB-young allocation cap (single alloc > 4 MB still traps) remains a separate concern.
- [x] **GC robustness under high parse-time string-allocation pressure** (closed 2026-05-14).
  - **Root cause #1 — missing write barriers in Cheney scan**. `vader_gc_scan_box` and `vader_gc_scan_raw` wrote forwarded pointers into slots without invoking the card-table write barrier. When the slot lives in an old-gen object and the new ref ends up in young, the card stayed clean — so the next minor's `scan_old_dirty_cards` skipped that object, and the buf pointer became stale after the next swap. Compounding this, `vader_major_collect` cleared the whole card table at end-of-cycle, wiping any pre-existing dirty bits for genuine user mutations that hadn't fired yet. Fix (`6a62da13`) : (i) add the barrier in both scan helpers (only when the slot is in old and the target is in young), (ii) replace major's `memset(table, 0)` with `memset(table, 1)` so we lose no edges. Drive-by : `vader_array_get` / `vader_array_set` now resolve forward pointers before slot access, matching `vader_array_push`'s discipline.
  - **Root cause #2 — raw string fields un-traced + un-rooted push arg / builder buffers**. `json_basics` (3800+ lines, the full self-host workload) segfaulted under `VADER_GC_STRESS=1` even after RC#1's fix. Three orthogonal missing roots, all closed by `273d98b7` + `5b9d39a0` : (a) `vader_string_t` fields stored inline in structs (primitive type) weren't enumerated in `vader_type_X_ptrs`, so the string mark-sweep collected runtime-allocated strings held only by a struct field — fixed by adding `string_offsets` to `vader_type_info_t` and walking them in `vader_string_gc_collect` ; (b) `vader_array_push`'s by-value `vader_box_t v` parameter wasn't a precise root across the resize-branch's `vader_array_buf_alloc` — fixed with `VADER_GC_PUSH1(v)` ; (c) `vader_builder_t`'s growing buffer had no anchor, so a Vader-side allocation between two `append_*` calls swept the partial buf — fixed by chaining builders through `g_builder_head` and walking the chain in the string mark-sweep. Drive-by : multi-hop forward resolution in `vader_array_resolve` (a single `vader_gc_alloc` can chain minor + major), `vader_string_concat` traps on `size_t` overflow + skips zero-length `memcpy` UB, conservative stack scan annotated `no_sanitize(address,memory)`.

  Tooling landed (2026-05-14) : `VADER_GC_STRESS=1` env var — turns intermittent rooting bugs into deterministic failures. Off by default (100×–10000× slowdown). Verified : the stress run on `json_basics.virt` produces stdout byte-identical to the no-stress run.
- [ ] Direct-ASM backend for one native target (validate the design)
- [ ] Escape analysis enabled (lower allocations on stack when proven safe)
- [ ] **Bytecode cache on disk** — to discuss / dimension later. Today every `vader run`, `vader fmt`, `vader-lsp` invocation re-parses + typechecks + lowers the full stdlib (~30 modules) plus the user code before the VM executes a single instruction. TODO line 32 measures this at ~2-3s for the formatter ; same hit on every LSP cold-start and every `vader run script.vader`. Proposal : serialise the lowered bytecode (per-module `LoweredModule` + the cross-module bytecode tables) to a `.vbc` sidecar keyed by `(source_hash, compiler_version)`. On invocation, walk the import graph ; for any module whose hash matches its `.vbc`, skip parse + typecheck + lower and load the cached bytecode straight into the VM. Cache location : `~/.cache/vader/<version>/<source_hash>.vbc` (per-user) or `./.vader-cache/` (per-project — easier to wipe). Open questions to settle before implementing : (a) serialisation format — binary (compact, fast read) vs MessagePack (debuggable) vs the existing IR text emitter (slow but free), (b) cache invalidation across module *transitive* deps (changing `std/core` must bust every consumer's `.vbc`), (c) interaction with `--target=native` C-emit (separate cache layer ?), (d) interaction with comptime evaluation (memoise comptime values too, or recompute ?). Stay on VM-only for now — AOT is deliberately out of scope (user prefers VM flexibility during pre-self-host development).
- [x] **Whole-program DCE** (2026-05-10). `pruneUnreachable` (`src/midir/dce.ts`) now treats user modules uniformly with stdlib whenever the project exposes a `main` — every user fn / struct / const must be reachable from `main` + `@export` / `@test` / `@extern` roots, otherwise it's pruned. When no `main` is present (library target, `vader run` of a script without main, snapshot fixture), the prior behaviour holds : every user decl stays a root. Decided defaults : (a) absence of `main` for native is NOT a hard error, the `vader build` flow already yields a meaningful diagnostic when entry-detection fails downstream ; (b) `vader test` reaches @test fns via the existing decorator root ; (c) incremental rebuild — same hash invariants, since the DCE input is the LoweredProject not the source. Net : −485 lines on the Vader self-host build (45984 → 45499) ; rare in pure-self-host because almost every user fn is transitively reachable, but should pay off more on apps that import a fat stdlib.
- [ ] **Lazy-materialise stack values in C-emit** (companion to the DCE win above). Followup to `feat(c-emit): lazy-materialise stack values + fix type-info OOB`. Today's compactness wins target *primitives* — `local.get`/`local.tee` of ref/any types still snapshot eagerly into a refTmp because of GC-precision (a stale heap-pointer in a call-arg evaluated before a sibling alloc would survive collection). Future opportunities : (1) detect call-arg pairs with no allocation and inline the deref ; (2) skip the explicit zero-init for primitives (the lowerer guarantees write-before-read except for params) ; (3) pre-declare blockres slots on first use rather than at the top of the fn. Each is bounded but the combined source-size and compile-time wins should be substantial. Estimate ~½ day each.
- [x] **`match enum` cascade → `switch` C** (Prop 1, 2026-05-10). Effectively delivered via Prop 2's switch-mode extension (commit 1491947) : `match enum { ... }` cascades whose arm bodies are constant returns/sets compile to a C `switch (l0) { case K: return CONST; ... default: ... }`. Covers both dense+exhaustive and sparse+wildcard shapes. The general case (arbitrary arm bodies + per-level result-propagation chain rewritten across nested ifs) is left open — mostly relevant for arms that compute non-trivial expressions, which the static-table family doesn't try to recognise.
- [x] **Static lookup table for `match enum -> StructLit constant`** (Prop 2, 2026-05-10). Landed across commits f5c8966 / aa5b095 / 4363a00 / 1491947. Detection at C-emit (no new bytecode op) — recognises four arm-body shapes : (a) expression-bodied returns of `<consts>; struct.new TAG` (struct table), (b) expression-bodied returns of a single primitive const (primitive table), (c) block-form `<consts>; (struct.new)?; local.set INNER` followed by the per-level propagation chain + final read+return, (d) sparse cases or wildcard `_` arms — emitted as a C `switch (l0) { case K: return CONST; ... default: ... }`. Pre-requisite landed in 0705452 : `vader_gc_forward` + `vader_gc_scan_raw` short-circuit on pointers outside the from-space arena. Selfhost_lexer_basic snippet : 7202 → 6353 lines (-12%); `info` (CodeInfo, 10 variants) drops from a 140-line cascade with 10 vader_gc_alloc/call to a 14-line table + 2-line lookup with zero alloc; `kind_name` (TokenKind, 30 explicit + wildcard, sparse tags) drops to a 32-line switch. Open follow-ups : sparse-tag struct returns (each arm needs a `static const T VAL_K`, switch returns boxed refs) ; wildcard variant-set inference for dense-table-with-bounds-check ; const-folding of nested struct literals (e.g. `Foo { .span = Span { .start = ..., .end = ... } }`).
- [x] **Eliminate single-use primitive temp locals introduced by struct-literal lowering** (Prop 3, 2026-05-10). Landed as bytecode peephole Rule 6 (commit c5829ef) + numeric-coercion extension (commit 85cea3a). For each non-param slot with exactly 1 set + 1 get + 0 tees AND a constant-op preceding the set, propagate the const to the get site (delete set+const, replace get with the const, optionally inserting a numeric convert op when the set was implicitly narrowing). Rule 5 (dropDeadStores) then collects the orphaned slot. Net : -360 lines on selfhost_lexer_basic; bytecode of `match enum` cascades simplifies to a clean `local.get S; const K; (narrow); cmp; if void` pattern, which then unblocks Prop 2's detection.
- [~] **Hash-cons `Type` values + re-key `implMethodEntries` by reference identity** (Phase A + B-step-1 landed 2026-05-11, commits `6b6905c` and `79de7ef`). Done : `MonoEntry.id` / `isMain` split off the `mangled` string ; the four mono / registry lookups (`implMethodEntries`, `fnInstanceEntries`, `InstanceRegistry.byKey`, `lookupImplEntry`, `lookupFnInstance`) now key on `canonicalArgsKey` (structurally stable, symbol-id-anchored, independent of `displayType`). Foundation for full hash-consing is in place — `mkStruct` / `mkTrait` / `mkArray` / `mkTuple` / `mkFn` / `mkUnion` / `mkTypeParam` / `mkEnum` constructors with per-kind cache + global `internId` WeakMap.

    **B-step-2 remaining** : migrate the ~53 inline `{ kind: "Struct", ... }` Type literals across `src/typecheck/passes/*.ts` and `src/lower/passes/*.ts` to use the constructors. Mechanical edit (~½ day). Once landed :
    - `equalsType` short-circuits on `a === b` for every interned type (today fires only when two passes happen to share a ref).
    - `canonicalArgsKey` can collapse to `args.map(internId).join(",")` — a few-bytes integer concat per key instead of a recursive walk.
    - Map keys over `Type` (e.g. `Substitution.typeParams`) become safer — no risk of duplicate entries from structurally-equal-but-distinct refs.

- [ ] **Discussion : value-type structs (`CodeInfo`-style)** (Prop 4). Today every Vader struct is heap-allocated and passed as a `vader_box_t`. For small immutable structs that are never trait-boxed (e.g. `CodeInfo { id: string, message: string }` — 32 bytes, two strings), this costs a heap alloc + tag + box per value, where a register-by-value pass (4 ARM64 regs) would be free. Trade-offs to discuss : (a) syntactic distinction (`struct` vs `value struct` keyword? `@value` decorator? auto-detect "no `any`/trait usage"?) — auto-detect risks brittle behaviour on innocent edits ; (b) interaction with `is Trait` checks (value-types can't be downcast — should be a compile error) ; (c) interaction with `match` patterns that bind by reference (today binds work because everything is boxed) ; (d) ABI : multi-register return on different platforms ; (e) escape analysis as a downgrade path (value-types that escape into a `ref` slot get auto-boxed at the boundary). Decision needed before implementation. No estimate — depends on chosen scope.
- [x] **Iterator-chain fusion at the lowerer** (2026-05-14). `src/lower/passes/for-in.ts:tryLowerForInIterChainFusion` recognises `for x in (MapIterator { source: FilterIterator { source: <RangeExpr>, pred: F }, f: G }) { body }` and emits a single counter loop with inlined `pred` and `f` — zero `Yielded` allocations, zero `next()` dispatch. The lowerer descends the AST tree recursively, bottoming out at a Phase-A-eligible literal range ; each layer must have its `source` given inline (struct lit, not a variable) so the shape is statically known. Bench result on `iter_chain` : 32.1 ms → **1.9 ms (-94 %)**, Vader native now **2 × faster than Go's direct loop**. The chain has to be inlined at the `for` site (`for x in (…) { … }`, parens required by the Rust-style ban on struct lits in `for`/`if`/`while`/`match` conditions) ; chains built up via local variables still fall back to the slow per-iter dispatch — a follow-up could chain a use-def lookup to inline the variable's RHS when it's a single assignment.
- [x] **Inline representation for small tagged unions** (2026-05-14, c-emit only). `src/bytecode/types.ts:inlineVariantPayload` recognises structs whose shape fits entirely in `vader_box_t` : empty (`Done {}` → tag alone) or single-primitive-field (`Yielded(i32)` → payload.i). The c-emit's `emitStructNew` / `emitStructGet` skip `vader_gc_alloc` for these — instances are encoded directly as `vader_box_<X>(tag, value)`. The type info entry stays `KIND_NONE`, so the GC scanner correctly skips them when scanning boxes. **Mutation gate** : a pre-scan of all `struct.set` op type indices builds `EmitCtx.mutatedStructs` ; structs in that set keep the heap rep so mutation through any alias is observable (closure envs, `Counter { value: i32 }`, …). Without the gate, single-field MUTABLE structs corrupt — closures and `c.value = 100` patterns crash. The VM keeps the slow path ; only native benefits. Bench impact zero on the fully-fused iter_chain (no Yielded allocations remain after I1), but variable-bound chains (`chain := MapIterator { … } ; for x in chain { … }`) drop from 3 `vader_gc_alloc` per iter to 3 alloc total (just the wrapper structs), measurable ~17 % win on that pattern.
- [ ] **Inline trivial trait-method impls before bytecode emit** (deferred 2026-05-14, scoped out of the bench-driven perf push). Today methods like `i32.gt :: fn(a, b) -> bool { return a > b }` and the one-arm vtable dispatchers post-mono each emit a `Call` op. Clang `-O3` inlines them in the native path (static fns in the same translation unit) ; the VM doesn't, so every iter-chain `.gt` / `.compare` / `.next` costs a `call` + frame push + return. Plan : (a) classify `LoweredFnDecl` as "inlinable" — single `LoweredReturn` of a pure expression with no recursion, ≤ N midir ops ; (b) midir pass that replaces every `Call(callee=inlinable)` with the callee's body, substituting params for args ; (c) `pruneUnreachable` drops the now-dead callees. Acceptance : VM bytecode `call` count drops on iter-chain workloads ; native binary size shrinks marginally (DCE removes inlined fns). **Why deferred** : the current `bench/` workloads have **no fn calls in their hot paths** after phase A (mandelbrot's inner loop is pure float math, primes' is integer modulo/comparison). VM perf bottleneck is the parse + typecheck + lower pipeline (3.5+ s per invocation), not the VM exec loop ; this opt would shave maybe 20-30 % off the VM exec slice but leave the dominant compile slice untouched. Revisit when (a) a bytecode-cache lands (then VM exec dominates) and (b) a bench workload shows fn-call density as a hot spot. Estimated effort : 1 day.

### 3.6 Memory model extensions

- [ ] Explicit allocator API (arenas, pools) for perf-critical paths
- [ ] `unsafe { }` blocks for low-level FFI

### 3.7 Tooling

- [ ] LSP server (in Vader): diagnostics, hover, go-to-definition, completion
- [ ] **LSP : revisit hover signatures once the typechecker is self-host.** Today the indexer is AST-only — it has no access to inferred types, so hover on a local binding falls back to a source slice. Best-effort heuristics extract the type from explicit annotations (`let a: u64 = …`) or literal suffixes (`a := 1_u64` → `a: u64`), but anything else (`c :: a + b`, `n :: 50`, struct-lit values, fn returns) shows the verbatim RHS source rather than a real type. When the typechecker lands in Vader (cf. §2.6 in Phase 2), the LSP can consult its inferred-type table directly and replace the heuristics with a proper `name: T` rendering for every binding shape. Same upgrade unlocks: param hover showing concrete types post-substitution for generics, match-arm pattern bindings (currently skipped because `IsPattern.bind_as` has no span and no inferred type), and resolving the namespace-import + alias-redirect paths cleanly.
- [ ] **LSP : inlay hints for inferred types** (LSP 3.17 `textDocument/inlayHint`). Render the inferred type as ghost text after each binding that has no explicit annotation — `n :: 50` → `n` `: i32` ` :: 50`. Three steps : (1) declare `inlayHintProvider: true` in `vader/lsp/lifecycle.vader` `server_capabilities()`. (2) Route `textDocument/inlayHint` in `main_entry.vader` ; the request carries a `range`, so walk only the AST nodes overlapping it and emit one `InlayHint { position, label: ": T", kind: 1 }` per `ConstDecl` / `LetDecl` lacking a type annotation. Skip parameter and return-type hints in v1. (3) Resolve `T` from the typechecker's inferred-type table — gated on the same self-host typechecker as the hover task above ; until then a heuristic-based version (mirroring the hover fallback) could ship as a stepping stone but will be wrong on `c :: a + b` etc. Optional follow-ups : parameter-name hints at call sites (`kind: 2`), `InlayHintLabelPart` with `location` to make the type token goto-definition-clickable, and a `resolveProvider` pass to defer tooltip computation.
- [ ] VS Code extension
- [ ] Programmable build API (`build.vader` instead of `vader.json`)
- [ ] **Multi-library namespaces** — today `STDLIB_PATH_PREFIX = "std/"` is hard-coded in `src/resolver/module.ts` ; only one library prefix is recognised. Generalise to a registry mapping prefix → on-disk root, fed by `vader.json` (e.g. `{ "libraries": { "web": "./vendor/vader-web", "experimental": "./libs/exp" } }`). Use cases : (a) third-party libs once a package manager exists, (b) compiler-private namespace (`internal/` for `unsafe`, `atomic`, low-level GC hooks) with a visibility rule "`internal/` only importable by stdlib + compiler", (c) workspace-style monorepos. Touches `resolveImportPath`, `isStdlibModule`, the DCE filter, and dump-stage filters that currently short-circuit on `std/`. Estimate ~150 lines + a manifest schema bump.
- [ ] External package manager + central registry (much later)
- [ ] `man` page for the `vader` CLI
- [x] **GitHub Actions pipeline — bootstrap** (2026-05-11). `.github/workflows/build.yml` runs `bun run typecheck` + `bun test` then cross-compiles the four target archives from a single `ubuntu-latest` runner via `bun run dist:all`. Triggered on push to `main`, pull requests, tags `v*`, and manual `workflow_dispatch`. Archives uploaded as a workflow artifact (`vader-archives-<run_id>`, 30-day retention).
- [ ] **GitHub Release publication on tag push.** Extend `.github/workflows/build.yml` so that when the trigger is a `v*` tag push, after `dist:all` succeeds the produced `dist/vader-*.tar.gz` and `dist/vader-*.zip` are attached to a new GitHub Release named after the tag (e.g. via `softprops/action-gh-release` or `gh release create`). Requires `permissions: contents: write` and the default `GITHUB_TOKEN`. Auto-generate release notes from the commit log between tags.
- [ ] **GitHub Actions matrix per OS** (post self-host). The bootstrap pipeline above cross-compiles from one Linux runner — fast but each binary is only smoke-tested by virtue of being produced. Once self-hosting (§2) lands, fan out to `ubuntu-latest` / `macos-latest` / `windows-latest` matrix jobs that each run the full `bun test` suite on their native binary, then assemble the per-OS archive locally instead of cross-compiling.

### 3.8 Language ergonomics

- [x] **UFCS on union receivers** (2026-05-13). `value.method()` on a union-typed receiver now falls through to free-fn UFCS dispatch when no variant carries a struct field of that name. `inferField`'s union common-field branch returns immediately only when at least one (but not every) variant has the field — that's the "partial-match / probable typo" case. When *no* variant has the field, control falls through to the existing impl-method / trait-method / `ufcs-free` chain, so a free fn `name(v: Union, …)` reachable in scope wins via dot-notation. Snippet : `tests/snippets/ufcs_union_receiver`. Touched : `src/typecheck/passes/field.ts` (union branch fall-through). The exec.vader workaround using call-form `read_i32(v, ...)` stays valid ; the dot-notation form `v.read_i32(...)` now also works for new code.
- [x] **Type-alias unions in cross-module `Alias[]` array slots** (2026-05-13). Cross-module use of `Value[]` (where `Value :: A | B | C` is exported as an implicit-type-alias `ConstDecl`) was failing with `T3001: expected ?[], got A | B | C[]`. Root cause was **decl-order across the typecheck phase 1** : consumer modules' `declareFn` ran in the same `"rest"` phase as the producer module's `ConstDecl`, so when a fn signature in module A referenced `Value` from module B, `typeFromSymbol` looked up `constTypeAliases.get(B.Value's decl)` and got `undefined` because B hadn't been declared yet. Fix : added a `"type-aliases"` phase between `"enums"` and `"rest"` in `checkProject`, scoped to `TypeAliasDecl` + `ConstDecl-as-type-alias` (detected via `looksLikeTypeExpression`). Every alias is now declared project-wide before any fn signature lowers. Snippet : `tests/snippets/alias_union_in_array`. Touched : `src/typecheck/index.ts` (third phase call), `src/typecheck/check.ts` (extended phase enum + `isTypeAliasingDecl` filter). `vader/vm/exec.vader` reverted to `Value[]` everywhere (workaround removed, ~40 lines).
- [ ] **Reconsider the `string` model: codepoint-first instead of byte-first.** Today `string` is a `(ptr, len)` UTF-8 byte slice ; `byte_len`, `byte_at`, indexing via `s[i]` (which *decodes* the codepoint starting at byte `i`), and the new `index_of`/`last_index_of` all leak that representation. The stdlib has to spell out "byte offset" everywhere, callers have to thread `byte_len()` for slice bounds, and any non-ASCII manipulation is sharp-edged. A codepoint-first model (Python 3, Swift) would index by codepoint and reserve a separate `bytes` view for byte-level work — closer to user intent and easier to teach. Doing it well likely means a fat `string` view carrying both byte and codepoint lengths, plus a backing-buffer ABI change that touches the runtime (`vader_string_alloc`, GC string-arena scan), the C emit (`vader_string_*` calls), the bytecode pool, the formatter, and every stdlib string fn. Big lift ; track here so we don't accumulate more byte-first API surface than necessary in the meantime.
- [x] **Array slicing `arr[r]`** (2026-05-13). `arr[lo..<hi]`, `arr[lo..=hi]`, and any `arr[r]` where `r : Range[<integer>]` return a fresh `T[]` over the requested half-open / closed range. The typechecker dispatches on the *index type* (`isRangeType` against `std/core.Range`), not on `RangeExpr` AST kind, so let-bound range values work the same as literals. Any integer-bounded range is accepted ; the lowerer casts bounds to `usize` since the runtime array index is usize-typed. Lowering desugars to a synthetic block — `let __src = arr ; let __lo = ... ; let __hi = ... ; let __inc = ... ; let __out: T[] = [] ; loop while (__inc ? i <= hi : i < hi) { __out.push(__src[i]) ; i += 1 } ; __out` — no new bytecode op, no backend changes. Snippet : `tests/snippets/array_slice` (half-open literal, inclusive, let-bound range, usize bounds, empty slice). Touched : `src/typecheck/passes/expr.ts` (`inferIndex` slice branch + `isRangeType` helper), `src/lower/passes/expr.ts` (`lowerArraySlice` + `castToUsize`).
- [ ] Static-size arrays: `[T; N]`
- [x] **Literal-value patterns in `match`** (2026-05-14). `'a' -> …` / `42 -> …` / `true -> …` / `"ok" -> …` / `null -> …` now parse as `LiteralPattern` arms. Touches : `src/parser/ast.ts` (new variant + `forEachPatternBindingKey` no-op arm), `src/parser/passes/pattern.ts` (literal-token branch, delegates to `parseExpr` for the literal flavour). Resolver walks the inner expr so const-as-pattern stays a future extension ; materialize substitutes idents inside the literal expr. Typecheck pins the literal's type against the scrutinee (T3001 on mismatch). Lowerer emits `LoweredBinary { op: "eq" }` as the arm predicate, no new lowered nodes. Exhaustiveness rule unchanged — literal patterns require a `_` arm on primitive scrutinees (T3013). `examples/brainfuck.vader::emit_bf_char` is the first user — replaces an 8-branch `if/else if` chain with a clean `match c { '>' -> … ; '<' -> … }`. Known parser quirk : a `-N` literal pattern on a fresh line is consumed as `prev - N` because `-` is also infix ; workaround is to indent the body or wrap arms in braces. Or-patterns (`'a' | 'b' -> …`) and range-patterns (`'a'..='z' -> …`) still deferred.
- [ ] Pattern matching extensions (or-patterns, range-patterns)
- [ ] `@derive(Eq, Display)` to auto-generate trivial impls
- [ ] **Allow `int_type(enum_value)` cast for `enum(IntT)` types.** Today `inferTypeConstructorCall` (`src/typecheck/passes/call.ts:199-207`) rejects an enum value as a cast source : `sourceOk` only accepts `numeric | char | Unresolved | FreeInt | FreeFloat`. The redundant `level_code` helper in `vader/lsp/log.vader:25-34` exists purely to work around this — its commented rationale (lines 14-16) flags it as a typechecker limitation, not a design choice. Allow `i32(MyEnum.Variant)` (and `i64(...)` widening, `u8(...)` narrowing) when the target type is assignment-compatible with the enum's declared `repr`. Mirrors Go's `int(MyEnum)`, Rust's `MyEnum as i32`, Zig's `@intFromEnum`. Once landed, drop `level_code` from `log.vader` and inline `i32(level)` at the call site. Touches : (a) `inferTypeConstructorCall` — extend the `sourceOk` predicate for `Enum` sources with a numeric repr ; gate the cast on `isAssignable(enum.repr, target)`. (b) Lowering : a no-op at runtime (enum values are already stored as their repr in bytecode/C). (c) Snippet : `tests/snippets/enum_to_int_cast/` covering the four numeric directions (same width, widening, narrowing-with-fit, narrowing-overflow → static error if all variant values are known).
- [x] **Implicit `void` return** (2026-05-10). Already supported by parser (`returnType: null`) and typechecker (`FnTypeExpr.returnType === null ⇒ TY.void`, fn body trailing-expr widened against `void`). Added the missing piece : `void` is now reserved as a user identifier (new diagnostic R2019, gate via `checkReservedIdent` at every binding site — fn-name / struct-name / param / type-param / local / pattern binding / import). Snippet : `tests/snippets/void_ident_rejected`. Formatter dropping trailing `-> void` deferred until §1.15 lands.
- [ ] **`Iterable($T)` trait + auto-`.iter()` in `for-in`** — collections implement `Iterable(T)` once and the for-loop desugars `for x in iter_target` into `for x in iter_target.iter()` whenever the target's type implements `Iterable(T)` (otherwise falls through to the existing array / `Iterator` paths). Required to drop the `iter :: fn(self: MutableList) -> ...` boilerplate. Cf. SPEC §7 *for*.
- [~] **Trait-object boxing + dynamic dispatch for `Iterator(T)` (and other traits)** (initial work 2026-05-08, partial regression observed 2026-05-11). Generic fns whose params are trait-typed (`count(it: Iterator($T))`, `invoke(g: Greeter($T))`, …) were supposed to work end-to-end. The vtable IR from `d076263` is wired through bytecode/VM/C-emit ; type inference tweaks landed in `unifyTypeParam` / `isAssignable` / `lowerVirtualDispatch` / `collectVtableEntries` (Trait param ← concrete arg unification, `FreeInt/Float` → trait defaulting, primitive impls registered in vtables). **However :** the `tests/snippets/trait_box_range_iter/vm.snapshot` currently documents a compile error `T3009 step on Iterator($T)` (now `next` post-rename), and a fresh run still traps at `count(0..<5)` with `vm: reached unreachable`. So the inference path that worked at the time of the original entry has regressed (or never fully covered the call site). Storing a trait-typed value in a struct field works (verified via `Box(i32) { .it = 0..<3 }`), which is why `std/iter`'s lazy combinators ship with the *struct-literal-direct* construction pattern instead of fn helpers. Reopen and investigate before relying on `fn[T](it: Iterator(T))` shapes. Snippet `tests/snippets/iter_lazy/` shows what works today (struct-literal route) ; `trait_box_range_iter` is the historical reference for what should work once inference is repaired.
- [x] **Operator overloading via trait dispatch** (already in place ; verified 2026-05-10). All routes work end-to-end on user types : `+ - * / %` via `Add/Sub/Mul/Div/Rem` (snippet `op_overload_arith`), `== !=` via `Eq` with negation (snippet `op_overload_eq_ord`), `< <= > >=` via `Ord` rewritten to `compare(a, b) <op> 0` (same snippet), `a[i]` via `Index(I, T)` (snippet `op_overload_index`), `a[i] = v` via `IndexSet(I, T)`, `v in a` / `v !in a` via `Contains(T)` (snippet `contains_op`). Compound assignments (`+= -= *= /= %=`) desugar at parse time to `lhs = lhs <op> rhs` so they reuse the same dispatch (snippet `op_overload_compound`). Typecheck records the resolution in `binaryOpResolutions` ; `lowerOverloadedBinary` consumes it and emits a direct call against the impl member. `Rem`, `Index`, `IndexSet`, `Contains` already in `std/core`. The whole system is live for primitive numerics (built-in path), strings (`+` → `string.concat` op), and any user struct that declares the matching impl.
- [ ] **Function overloading by full signature** (post-MVP elevation of the pre-MVP receiver-type-only overloading) : pick the candidate whose all parameter types match the call site, not just the first. Subsumes pre-MVP behaviour ; requires generalising the resolver's overload table and the typechecker's call resolution.
- [x] **Generalise the auto-coerce mechanism — `Into[Target]` trait** (Phase 1+1.1+2 landed 2026-05-11). Final shape :
    - Trait `Into[Target]` + 4 implicit sites (call arg, return, let typed, struct field).
    - Explicit `Target(value)` syntax routes to `tryInto` for non-numeric targets and for numeric targets fed a non-numeric source ; primitive casts keep the dedicated path.
    - Overload resolution second-pass : `rankOverloadsByFirstParam` adds an `intoMatch` rank strictly weaker than every direct rank.
    - Blanket-impl support : impl-side `[T: Bound]` syntax (uniform with `fn[T]`/`struct[T]`/`trait[T]`), `findIntoImpl` with `unifyTypeParam` + bound check, `IntoCoercion.implSubst` plumbed through mono and lower.
    - Comptime materialisation : `collectIntoMembers` + Pass 4 in `monomorphizeProject` emit one `MonoEntry` per `(member, typeArgs)` for blanket impls ; body walk feeds the registry so transitive instances land.
    - Lower routing : `wrapAsInto` derives the lookup args from `coercion.implSubst` for blanket impls, falls back to `source.args` for concrete-source impls.
    - Built-in coercions folded into Into : `T[] implements[T] Into(Iterator(T))` and `T implements[T: Display] Into(string)` (declared in `std/core`). `arrayIterCoercions` / `displayCoercions` / `wrapAsDisplay`'s coerce role / the `Array → Trait(Iterator)` hack in `isAssignable` / the intrinsic `Display → string` param rewrite : all retired.
    - `SPEC.md` §11 *Type coercion* + diagnostic R2020/T3039 (identity-impl) + snippets `coerce_into_basic`, `coerce_into_explicit`, `coerce_into_overload`, `coerce_into_chain_no`, `coerce_into_union_target_no`, `coerce_into_identity_rejected`.

    Commits : `2fbe9ec`, `72510d5`, `0f4b790`, `53e0776`, `1a02450`, `801f423`.

    **Follow-ups (not Phase 2)** :
    - Diagnostic on ambiguous coercion when two distinct `Into(Target)` impls (or a coercion chain through two traits) reach the same slot. Today `findIntoImpl` returns the first match silently.
    - `@cheap_coercion` / `@allocating_coercion` markers so allocation classes surface in review.
    - LSP "find coercion usages" for silent-insertion debugging.
    - Opt-out via `@explicit_coerce` decorator on a trait for strict-mode libraries.
- [x] **Expression-bodied functions with explicit return type** (2026-05-08). The earlier P1020 restriction (`fn(...) -> T = expr` was rejected) is lifted on both the TS parser and the Vader self-host parser ; `declareFn` honours the annotation and `inferExprBodiedReturns` skips already-typed expression bodies. The double-`->` SAM-style alternative (`fn double(x: i32) -> i32 -> x * 2`) is not introduced — visual overload outweighs the savings. Snippet : `tests/snippets/expr_bodied_recursive_typed/`.
- [x] **Struct spread / functional update** (2026-05-10). `MyStruct { ...other, .field = v }` — copy every field of `other`, override per-field. Source bound once to a synthetic local so it's evaluated exactly once even when multiple fields inherit from it. Multi-spread supported (last spread wins per field). Snippet : `tests/snippets/struct_spread`. Touched : parser (new `dotdotdot` token + `StructLitItem = StructLitField | StructLitSpread`), typecheck (validate `other` is assignable to the struct ; T3038 on duplicate-field-name), lowerer (per-field cascade keyed off the spread temp). Two pre-existing bugs surfaced and fixed alongside : (a) field ordering — `{ .c=3, .a=1, .b=2 }` was passed positionally to `struct.new`, producing wrong layout ; lowerer now emits in declaration order regardless of source order (regression : `tests/snippets/struct_lit_field_order`) ; (b) missing-field check — omitting a non-defaulted field crashed at runtime with "Invalid array length" ; now T3037 at typecheck.
- [x] **Struct field default values** (2026-05-10). `field: T = expr`. Defaults are typechecked once at the decl site (`check.ts:StructDecl` arm) against the field's declared type ; re-lowered at every literal site (comptime-folding is an optimisation opportunity, not a correctness requirement — tracked as a follow-up). Composes with struct spread above. Snippet : `tests/snippets/struct_defaults`.

  ```vader
  export NamedType :: struct {
      span:         Span
      name:         string
      implicit_dot: bool = false
  }

  // call sites
  v1 :: NamedType { .name = "x", .span = sp }                    // implicit_dot defaults to false
  v2 :: NamedType { .name = "x", .span = sp, .implicit_dot = true }
  ```

  Required for new fields to land without a global rewrite of every existing literal — the port of `@partial`, `is .Foo`, etc. into the self-host parser had to update every `NamedType { … }` and `MatchExpr { … }` literal in `vader/parser/parser.vader` to set the new flag explicitly. With defaults, future struct evolution is back to a one-line change.

  Touches : parser (struct-decl grammar accepts `field: T = expr`), resolver (resolve the default expression in the struct's scope, treat it as a comptime expression so it composes with `@comptime`), typecheck (validate the default's type matches the field, fold it in as the missing-field source for struct literals), lowerer (emit the default at struct-lit-emission time when a field is unset). Defaults must be comptime-evaluable to keep the literal allocation-free at runtime.

  Estimate ~250 lines + tests. Compose nicely with the future struct-spread (`...other`) — both are about "fill in the unset fields", just with different sources.
- [x] **Tuple types and destructuring** (2026-05-08). Bracketed type form `[T1, T2, ...]` (≥ 2 elements) introduces heterogeneous tuples ; the array form moved to postfix `T[]`. Disambiguation of seq literals is contextual (TS-style) : `[1, 2]` is an array, `[1, "x"]` is a tuple, annotations win. Field access via `t.0`, `t.1`. Destructuring works in `let` (`[a, b] := pair()` ; nested + wildcards supported) and in match arms (`[a, b] -> ...`). Tuples lower to anonymous structs with synthetic fields `_0`, `_1`, ... keyed by BC type slot index (`__Tuple_${slotIdx}`) so distinct shapes don't collide in C-emit — no new BC ops or runtime types. Hard cut on the legacy `[T]` form (P1024). Vader self-host parser synced (`vader/parser/{ast,parser,dump}.vader` + `vader/diagnostics/codes.vader`) so `parser_parity` runs at 128/130 again.
- [x] **Comptime tuple / struct / array values** (2026-05-08). `valueToComptime` now reads VM struct/array fields recursively and routes them to the existing `ComptimeValue.struct` / `ComptimeValue.array` shapes ; the `lower-decl.ts::comptimeValueToLowered` back-emission already handled both. Tuples re-use the struct path with synthetic `_0`, `_1`, … field names since they lower to anonymous structs. Snippet : `tests/snippets/tuple_comptime/`. Top-level typed const form changed from the awkward `name :: : Type value` to the Odin-style `name : Type : value` (matches the SPEC `MAX: u64 : 1_000_000` example and the local immutable-let surface) ; the old form is now a parse error.
- [x] **Spread destructuring** (2026-05-10). `let [first, ...rest] = arr` (array source only ; tuples use the existing exact-arity TupleBinding). New `RestBinding` AST node. Typecheck enforces at most one rest, last position only ; rest binds `T[]`, fixed leaves bind `T`. Lower desugars to `let __t = arr ; let first = __t[0] ; let rest: T[] = [] ; loop while __i < array.len(__t) { rest.push(__t[__i]) ; __i = __i + 1 }`. `rest` routes through `lowerCellInit` so capture by an inner closure correctly promotes the slot to a heap cell. Pre-sizing the rest array (avoiding amortised reallocs on long tails) deferred until a slice intrinsic exists. Snippet : `tests/snippets/spread_destructure`.
- [x] **Process spawn intrinsic** (already implemented, marked 2026-05-10). `std/process.spawn(argv: [string]) -> ProcessResult!` lives in `stdlib/std/process.vader` ; native side wires `posix_spawnp` + pipes via `vader_spawn_run` / `vader_spawn_last_stdout` / `vader_spawn_last_stderr` ; VM side bridges to `Bun.spawnSync`. Returns `ProcessResult | Error` (ProcessError implements Error so `?` propagation works). WASM unbound ; intentional.
- [x] **Inline `@file(path)` as a comptime expression** (2026-05-10). `@file("...")` is now a regular `IntrinsicCallExpr` returning `string`. Three call shapes work : `A :: @file("data.txt")` (literal), `A :: @file(IDENT)` (const-ident chain — fast path via AST walk), and `A :: @file(IDENT + ".txt")` (arbitrary comptime-evaluable expression — runs through the comptime VM by wrapping the arg in a synthetic `ConstDecl`). Sandbox containment (path stays under projectRoot) is unchanged. The legacy decorator form (`@file("...")` above a `ConstDecl`) is removed — `file` is no longer a recognised decorator name. Snippet : `tests/snippets/file_decorator` migrated to the new form.
- [x] **Implicit selector expressions** (2026-05-08, Odin-inspired). Enums : `f = .Variant`, `match d { .Variant -> … }`, array elements `[Day.Mon, .Tue]` work end-to-end via `DotVariantExpr` in expression position. Tagged unions of structs now also resolve `is .Foo` patterns against the scrutinee — extended `IsPattern` parsing with a leading-`.` form, added `implicitDot` flag to `NamedType`, suppressed global lookup in the resolver, and routed resolution through the match scrutinee in `typecheck/passes/match.ts::resolveImplicitDotVariant`. Snippet : `tests/snippets/implicit_dot_variant/`. Self-host parser ported same day — `KNOWN_FAILURES` is back to empty.
- [x] **`@assert(condition)` — compile-time assertion** (2026-05-08). New `AssertDecl` AST node ; `@assert` recognised at top-level as a standalone decl (when no other decorators co-occur). Resolver walks the condition expression, typecheck enforces `bool`, comptime stage wraps each condition in a synthetic `__assert_<id>` ConstDecl and runs it through the existing comptime VM. A `false` result emits C4015. Snippet : `tests/snippets/decorator_assert/`. Self-host parser ported same day — `KNOWN_FAILURES` is back to empty.
- [x] **`@partial` on `match`** (2026-05-08). Opt-out of exhaustiveness for a single match expression. Parser recognises `@partial` in expression position (rejects any other `@`-prefix there with P1014) and flips a `partial: true` flag on `MatchExpr` ; typecheck skips the T3013 exhaustiveness check when the flag is set. Default stays exhaustive — the flag has to be opted into per match. Snippet : `tests/snippets/match_partial/`. Self-host parser ported same day — `KNOWN_FAILURES` is back to empty.
- [x] **`@deprecated("reason")` decorator** (2026-05-08). Recognised on any decl ; every IdentExpr that resolves to it emits warning W0001 with the reason. Adds the `WARNING` registry + `makeWarn` factory + `warn` helper in typecheck — first warning-severity diagnostic, paving the way for future lints. Optional `since: "1.2"` arg deferred (named decorator args don't yet exist). Snippet : `tests/snippets/decorator_deprecated/`.

### 3.9 Companion projects

- [x] **Brainfuck compiler in Vader, targeting the Vader VM** (2026-05-14). Single-file example `examples/brainfuck.vader` (~225 lines) + companion `examples/hello.bf`. Tokenises BF, matches brackets, emits `.virt` text via `std/string_builder.StringBuilder`, hydrates via `vader/vm/parser.parse_virt`, and executes through `vader/vm/exec.exec` — no subprocess, no intermediate file. Helper fn `print_byte(b: i32) -> void` baked into the produced `.virt` handles `.` output via `i32.to_char` + builder + `std_io.print`. The compilation API (`parse_virt`, `exec` + `Module` / `VmResult`) is now publicly consumable from user code, which validates one of the original design goals. **Known limitation** : `--target=native` traps with `vader_gc: scanned object with unknown type_index` because the native GC's statically-built type-index table can't see types `parse_virt` materialises at runtime ; documented in the file header, interpreted path (`vader run`) is the supported runtime today. BF input `,` not wired (no `read_byte` host) — stubbed to "store 0".

### 3.10 WASM target

Moved out of MVP (was §1.10). The C backend already covers native deployment ;
WASM is for browser / wasmtime hosting and isn't load-bearing for the
self-hosted compiler. Re-attack once Phase 2 is well underway and there's a
concrete use case driving the design (e.g. an interactive playground).

- [ ] Bytecode → WASM binary (use a minimal wasm encoder, or vendor binaryen-js).
- [ ] WASM GC types for structs and arrays.
- [ ] Imports/exports wired through `@extern` / `@export` decorators.
- [ ] DWARF emission for source-mapped debugging.
- [ ] Tests : emit, run with wasmtime `--wasm=gc`, compare stdout to the VM snapshot.
- [ ] CLI : `vader build --target=wasm` + `vader dump --stage=wasm`.
- [ ] **Decide `usize` width** : WASM64 only (always 64-bit) vs supporting WASM32 (`usize` becomes `i32`). Affects the C-emit side too if we want one binary to share logic.
- [ ] **`examples/wasm_browser/`** — minimal HTML + Vader code calling JS via `@extern`. Doubles as the end-to-end smoke test.
- [ ] **Slot-typed numeric promotion verifier** — `local.tee` then read through a different-width typed op currently relies on the slot tag carrying the canonical type ; the WASM target needs a debug-only verifier to enforce op/slot agreement before emission (cf. §1.8 note).

---

## Reference

- `SPEC.md` — language specification (target reference)
- `examples/` — working programs (start here)
- `stdlib/` — standard library source (Vader)
- `src/` — TypeScript compiler (to be created in Phase 0)
- `tests/` — snapshot tests (to be created in Phase 1)
- `docs/IMPROVEMENT.md` — review-driven improvement plan (2026-05-11)
