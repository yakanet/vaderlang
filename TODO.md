# Vader — TODO

This document tracks the implementation roadmap for the Vader compiler and standard library, derived from `SPEC.md`. It is organised into three phases:

- **Phase 1** — MVP compiler in TypeScript, plus stdlib in Vader.
- **Phase 2** — Self-hosting (port the compiler to Vader).
- **Phase 3** — Post-MVP language features and tooling.

Each item is sized to be actionable. Cross items off as they're completed. Reorder freely — the listed sequence is a suggestion based on dependency, not a hard requirement.

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
- [x] Generic syntax: `$T` introduction inline (collected from fn-param types); `(T: type)` and `($N: i32)` heads on struct/trait/type-alias; `where T: Trait` clauses
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
- Validation of `where T: Trait` bounds against a concrete substitution at call sites.

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
- [x] **Generic impls** (`ArrayIter(T) implements Iterator(T)`) — done. Mono materialises one entry per `(impl member, struct args)` via `implMethodEntries: Map<FnDecl, Map<argsKey, MonoEntry>>`. Resolver shares typeParam symbols cross-module (via `typeParamSymbols`) so an impl in std/core can reuse the base struct's typeParam without clobbering. Lowerer's UFCS dispatch + Iterator lookup pick the right specialisation by struct args.
- [x] **`std/iter` combinators** (`map / filter / take / skip / fold / sum / count / collect`). Done in their **eager `T[]`-driven** form (`tests/snippets/iter_combinators/`). The iterator-driven flavours (`map(it: Iterator(T), f) -> Iterator(U)`) are still gated on default-init for generic param (next item) — bridge for now is `collect(it)` to materialise an array and operate on it.
- [x] **Transitive monomorphization** — done. `closeOverGenericImpls` (`src/comptime/evaluate.ts:253`) runs a fixed-point loop (max 64 iters) that, for each registered struct/fn instance, observes (a) the substituted types of every impl member, (b) every nested generic call site inside fn bodies (`observeFnBody` substitutes the outer subst into inner typeArgs before re-feeding the registry). Wrapper-style stdlib (`MutableSet(T) { inner: MutableMap(T, bool) }`) compiles end-to-end (`tests/snippets/mutable_set/`).
- [x] **First-class trait-method dispatch** — done. Three call shapes now resolve through the same ImplRegistry plumbing: (a) bounded type param (`fn foo(x: $T) where T: Hash { x.hash() }` — recorded in `traitMethodResolutions`, `tests/snippets/trait_dispatch_bounded/`); (b) non-generic trait receiver (`e: Error; e.message()` — recorded in `traitVirtualResolutions`, lowered via `lowerVirtualDispatch` into an `is X -> X_method(box)` cascade, `tests/snippets/trait_virtual_dispatch/`); (c) **generic trait receiver** (`it: Iterator(i32); it.step()` — typechecker substitutes the trait's typeParams into the method's return type so `Yielded($T)` becomes `Yielded(i32)`; lowerer enumerates every observed `(generic struct, args)` instance from `mono.implMethodEntries` and emits one arm per concrete struct, `tests/snippets/trait_dispatch_generic_iter/`).
- [ ] **Default-init for generic param** — `acc: T = T()` style, needed by `sum(it)` over an iterator. Either a `Default` trait + auto-impl on numerics, or a `zero<T>()` intrinsic. Currently blocks the iterator-driven flavour of `sum`, `min`, `max`.
- [ ] **Generic `len(arr)`** — today `ArrayIter` carries an explicit `length: i32` field set at auto-wrap time via `LoweredArrayLen` (the bytecode `array.len` op). Now that generic-fn dispatch is in, the field could be dropped in favour of `len(self.arr)` — pure cleanup, low priority.
- [x] **Auto-coerce `T[]` → `Iterator(T)`** — done. Typechecker accepts the assignability (`isAssignable` in `src/typecheck/types.ts` matches `Array(T)` against `Trait{Iterator}(T)`) and records each coercion site in `arrayIterCoercions: Map<A.Expr, Type>` (call args, `let` with explicit type, `return` slots — `src/typecheck/passes/call.ts`, `stmt.ts`). Lowerer reads the side-table at the top of `lowerExpr` (`src/lower/passes/expr.ts`) and wraps via the shared `wrapArrayAsIter` helper extracted from for-in. Comptime engine pre-registers each coerced `ArrayIter(T)` instance so mono materialises the step impl. Test: `tests/snippets/iter_coerce_array/`.
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
- [x] **`RangeExpr` + `T[]` arrays lowered via `Iterator` dispatch.** `0..<n` / `0..=n` lower to `Range { .start, .end, .inclusive, .cursor=0 }` struct literals; raw arrays in `for x in arr` auto-wrap into `ArrayIter(T) { .arr, .cursor=0, .length=array.len(arr) }`. `for-in` desugars to a step-loop dispatched through the `Iterator(T)::step` impl on the iter's static type — the range and array fast-paths are gone. `Range`, `Done`, `Yielded(T)`, `Iterator(T)`, and `ArrayIter(T)` live in `std/core` (the trait uses the sum-type variant `Done | Yielded(T)` to avoid the `T | null` sentinel collision for lists whose element type can be `null`). Generic impls (`ArrayIter(T) implements Iterator(T)`) materialise per concrete struct args via the mono pass: pass 1 emits non-generic impl members, pass 2 emits one entry per `(impl member, struct args)`. Snapshots: `tests/snapshots/vm/for_range/` and `tests/snapshots/vm/array_iter/`.
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
- [ ] Configurable C compiler via `vader.json` (e.g. `{ "build": { "cc": "clang" } }` or per-platform map). Falls back to `cc` (the POSIX default, auto-resolved by the system) when unset. CLI flag `--cc=<path>` should win over the manifest entry.
- [ ] Windows native parity in `tests/native.test.ts`: add a `WINE=1` mode that cross-compiles with `x86_64-w64-mingw32-gcc` (mingw-w64) and runs the `.exe` via Wine, so Windows binary parity can be verified on macOS/Linux without a VM. On native Windows, detect `clang` or `cl` instead of `cc`.

### 1.10 WASM emitter

- [ ] Bytecode → WASM binary (use a minimal wasm encoder, or vendor binaryen-js)
- [ ] WASM GC types for structs and arrays
- [ ] Imports/exports from `@extern` / `@export` decorators
- [ ] DWARF emission for source-mapped debugging
- [ ] Tests: emit, run with wasmtime `--wasm=gc`, compare stdout

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
- [ ] `vader build --target=wasm`
- [ ] `vader build --target=ir` — emits `.vir`
- [ ] `vader test [path]` — discovers and executes `@test` functions
- [ ] `vader fmt [path]` — opinionated formatter, no config
- [ ] `vader dump --stage=<ast|typed-ast|bytecode|c|wasm> <file>`
- [ ] `--allow-env` flag for comptime sandbox

### 1.13 Stdlib (in Vader)

- [ ] `std/core` — finalise traits and base `Error`
- [ ] `std/io` — implement `print`, `println`, `read_file`, `write_file`, `read_line`, `exists`
- [ ] `std/string` — finalise all listed operations
- [x] `std/collections` — `MutableMap(K, V)` chaining HashMap (string keys via FNV-1a hash, hash-backed via the same map for `MutableSet(T)`). `keys()` / `values()` snapshot helpers. `len` / `is_empty` / `put` / `get` / `contains_key` / `add` / `contains` shared via first-param overloading (§1.18c). Dead `Map` / `Set` immutable struct stubs removed 2026-05-07.
- [ ] **Implement immutable `Map`/`Set` ops + `to_immutable` conversion** when there's a real read-only-view design. Re-add `Map` / `Set` struct decls at that point.
- [ ] **Iterator impls for `MutableMap` / `MutableSet`** — yield `Entry(K, V)` / `T`. Skipped at MVP because writing them in a generic body needs trait-method dispatch on bounded type params (§1.18b deferred).
- [ ] **Restore `MutableList(T)` once immutable `List<T>` lands**. Today raw `T[]` arrays already provide `push`/`len`/indexing/`for x in arr`, so `MutableList` was a wrapper with no extra value and was dropped (was previously `MutableList(T) { data: T[], size: usize }` — `size` field was redundant with `data.len()`). Re-introduce when there's an immutable `List<T>` to pair with.
- [ ] `std/math` — constants and float operations (use `@extern` to libm where useful on native, intrinsics on WASM)
- [x] `std/string_builder` — `StringBuilder` (was `std/builder`, renamed for clarity).
- [x] `std/iter` — `count(it: Iterator($T))` + `collect(it: Iterator($T))` driven by `for x in it`; closure-driven combinators `map`/`filter`/`fold`/`sum`/`take`/`skip` operate on `[T]` directly (eager — return arrays or single values). Snapshot : `tests/snippets/iter_combinators/`.
- [ ] **`std/iter` lazy / iterator-driven combinators** — `map(it: Iterator($T), f: fn(T) -> $U) -> Iterator(U)` and friends require trait-method dispatch on a bounded type parameter (`$T : Iterator`) so combinators can call `inner.step()` directly. Today user code can only iterate via `for x in it` (compiler-internal magic). Bridge for now : `collect(it)` then operate on the array.
- [x] `std/runtime` — `collect()`, `collections()`, `bytes_used()`, `bytes_copied()`. Renamed back from `std/gc` (2026-05-07) — Go-style name signals "runtime introspection" for the small set of users who need GC stats / forced collection cycles, without inventing a new visibility tier (`internal/`) we can't enforce yet.
- [x] `std/sort` — `sort(arr: $T[], less: fn(T, T) -> bool) -> T[]`. Stable, O(n log n), non-mutating ; top-down merge sort with insertion-sort cutoff at 16 (mirrors Java TimSort). Returns a new array — input is never mutated. A `sort_by_ord(arr)` convenience is deferred until trait-method dispatch on bounded type parameters lands (TODO §1.18b). Snapshot : `tests/snippets/std_sort/`. First user : `vader/lexer/dump.vader:dump_diagnostics` swapped its inline insertion-sort + bubble-back hack for `sort(diags, diag_less)`.

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
- [x] **`Range` is i32-only ; non-i32 bounds now error at compile time** (2026-05-07). `inferRange` (`src/typecheck/passes/expr.ts:240-258`) explicitly checks `isAssignable(.., TY.i32)` on each bound and emits `T3001` instead of letting a u64/usize slip through to a VM trap. Regression : `tests/snippets/range_bound_u64/`. **Proper fix (still deferred)** : generalise `Range :: struct($T)` over the integer type with impls for i32/u64/usize, mirroring `Yielded(T)` and `ArrayIter(T)` (cf. SPEC §1442). Bigger lift — touches `std/core`, `inferRange`, `lowerRangeExpr`, and the resolver's `CORE_STRUCTS` registration. Tracked under §1.18b "Generic `Range`".

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

- [ ] `examples/hello.vader` ✓ (already created)
- [ ] `examples/fib.vader` — Fibonacci
- [ ] `examples/rule110.vader` — Rule 110 cellular automaton
- [ ] `examples/aoc_2024_day1.vader` — solve an AOC problem end-to-end (validates I/O + parsing + collections)
- [ ] `examples/wasm_browser/` — minimal HTML + Vader code calling JS via `@extern`

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

#### Deferred — Typed enums (post-MVP)

- [ ] **Typed representation** (`SPEC §Enums / Representation`): `Direction :: enum(u8) { ... }` — an optional `(type)` suffix selects the backing integer type (`i8`, `i16`, `i32`, `i64`, `u8`, `u16`, `u32`, `u64`; default `i32`). Requires: parser update (optional type arg on `EnumDecl`), `EnumType.repr` field in `types.ts`, lowerer emits the correct integer type instead of hard-coded `i32`, bytecode/C emitter updated accordingly.
- [ ] **Explicit variant indices**: variants may carry an explicit integer value (`Up = 10`); unspecified variants auto-increment from the previous (`Up = 10, Down` → Down = 11, `Left = 20, Right` → Right = 21). Requires: `EnumVariant.value?: bigint` in `ast.ts`, index-resolution pass in the type-checker or lowerer.
- [ ] **Bounds checking**: after resolving all variant indices, verify every value fits in the declared backing type. Example: `enum(u8)` max = 255 — emit an error if any variant index exceeds the range. Must also check that no two variants share the same resolved index.

### 1.18b Generics & primitive type ergonomics

Sub-tasks discovered while implementing collections:

- [x] **`usize` primitive** — first-class type for sizes/indexes. Maps to `size_t` in C, 64-bit in bytecode/VM bootstrap.
- [ ] **`isize` primitive** — symmetric to `usize` (signed pointer-size). Probably maps to `ptrdiff_t` in C.
- [ ] **Migrate `arr.len()`, `ArrayIter.length/cursor`, `iter.vader` signatures from `i32`/`u32` to `usize`** — currently mixed (e.g. `ArrayIter` uses `i32`, `iter.vader` uses `u32`). Single canonical width is `usize`. Cascading change : also touch the `len`/`get` intrinsic types and the array-index ops.
- [ ] **Generic `Range`** — currently hardcoded `Range(i32)`. Make it `Range($T)` so `for i in 0..<some_usize { }` works without an explicit cast. Touches the parser (range desugaring records target type), the typechecker (`inferRange` accepts any integer), the lowerer/iter wrapping. **Should also accept `char`** (`for c in 'a'..='z'` / `if c in 'a'..='z'`) so the self-host lexer can drop the `c >= 'a' && c <= 'z'` chains. Today `'a'..='z'` typechecks but the VM traps with `expected numeric, got char` because `step()` and `Contains` only specialise on `i32`. Requires `char` to implement `Ord` (or special-cased like primitives) so Range / Contains can compare.
- [ ] **Static methods / associated functions** (`List.ofSize(10)` style) — parser + resolver + typechecker support for `Type.method(args)` where `method` is a free function declared alongside `Type` in the same module. Required for Java-like factory APIs.
- [ ] **Trait-method dispatch on bounded type parameters** — inside a generic body, `key.hash()` where `key: $K` and `K: Hash` should resolve to the trait method, monomorphised post-typecheck. Required to promote `MutableMap`/`MutableSet` from O(n) linear-search to chaining HashMap. Sketch of the chain : (1) typecheck records `traitMethodResolutions: Map<FieldExpr, {trait, method, typeParam}>` whenever the receiver is a `TypeParam` whose surrounding fn/struct has a matching `where` clause ; (2) typecheck validates at call sites that each generic-fn substitution satisfies the declared bounds (T3033) ; (3) mono walks `traitMethodResolutions`, applies the call-site substitution, and forces a `MonoEntry` for the impl-member of the concrete receiver type ; (4) lower rewrites the `FieldExpr` callee into a direct `LoweredCall` of the specialised impl fn with the receiver as the first arg. Where-clauses are already parsed + resolved (parser/resolver) but currently semantically inert. Unblocks lazy iter combinators (1.13), HashMap, generic `len(arr)`, and `sum<T : Add + Default>`.
- [x] **First-class function values** — `fn(K) -> u64` as a struct field / local variable / argument. Done. See §1.7 "First-class function values" for the full implementation note.
- [ ] **Decide `usize` width on the WASM target** — WASM64 only (always 64-bit) vs supporting WASM32 (`usize` becomes `i32`). Affects the C-emit side too if we want one binary to share logic.
- [x] **`void!` runtime/type mismatch** — fixed 2026-05-07 in the parser (`src/parser/passes/type.ts`) : when the postfix `!` desugar sees `void` as the success type, it rewrites to `null | Error` instead of `void | Error` so the union variant matches what the runtime actually emits (`vader_box_null()`). `match { is null -> ... is Error -> ... }` now matches cleanly on success ; `?` propagation continues to work since both forms keep the `Error` variant.
- [ ] **Enforce struct-level `where` clauses** — `MutableSet :: struct($T) where T: Hash + Eq { ... }` parses today (`StructDecl.whereClauses` is populated) but is semantically inert : the typechecker accepts `MutableSet(Bad)` even when `Bad` doesn't impl the listed traits. Fix : (a) carry the bounds onto the struct's symbol in the resolver, (b) at every struct-type-expr / struct-literal site validate that the type-args satisfy the declared bounds (new diagnostic, e.g. T3034), (c) optional ergonomics — let fns operating on the struct omit the same `where` clause and inherit it implicitly. Saves the boilerplate that today repeats `where K: Hash + Eq` on every method of `MutableMap`/`MutableSet`.

### 1.18c Function overloading by receiver type (pre-MVP)

Lift `R2004` for free functions whose names collide if their **first parameter** types differ. Required so that `get(MutableList, usize)` and `get(MutableMap, K)` (and similar) coexist in user code without forcing aliasing on every import.

- [x] **Resolver** (`src/resolver/collect.ts:addFnSymbol`) — `fnOverloads: Map<string, Symbol[]>` collects all sibling fns under the same name ; `Module.symbols` keeps the first decl as the primary entry. True conflicts (same first-param type) are caught downstream by the typechecker.
- [x] **Typechecker UFCS dispatch** (`src/typecheck/passes/call.ts:rankOverloadsByFirstParam` + `inferUfcsFreeBound`) — buckets candidates as `concrete > symMatch > wildcard` and picks the best match. Ambiguous concrete pairs surface as `T3032`.
- [x] **Direct-call resolution** (`inferCall` for `f(x, ...)`) — `pickDirectCallOverload` runs the same ranking. Free numeric literals default to their canonical type (i32 / f64) before ranking, so `abs(-7)` picks `abs(i32)` instead of silently choosing the first declared overload (fixed 2026-05-07 in `inferCall`).
- [x] **Diagnostic** : `T3032` ("ambiguous overload resolution") covers both UFCS and direct-call sites.
- [x] **Tests** : `tests/snippets/overload_first_param/` covers user-defined direct + UFCS dispatch and the stdlib `min`/`max`/`abs` i32+f64 overloads.
- [x] **Stdlib `min`/`max`/`abs` i32+f64 overloads** added in `std/math.vader` (2026-05-07). `std/string.compare_ascending` now uses `min(la, lb)` instead of an inline `if`.
- [x] **Stdlib cleanup** done 2026-05-07 : `len` / `is_empty` / `put` / `get` / `add` / `contains` are shared between `MutableMap` and `MutableSet` via first-param overloading. Dead immutable `Map` / `Set` struct stubs deleted from `std/collections.vader`. No `len_map` / `len_set` workaround names remain.

### 1.18 Built-in type aliases

Per SPEC §4 ("Built-in type aliases"), the compiler should recognise `int`, `long`, `float`, `double`, `byte` as transparent synonyms for their primitive counterparts.

Implementation is small and self-contained — no new IR nodes, no new passes:

- [x] **Resolver** (`src/resolver/builtins.ts`): add `int`, `long`, `float`, `double`, `byte` to `BUILTIN_TYPE_NAMES` so the resolver creates `builtin-type` symbols for them.
- [x] **Type-checker** (`src/typecheck/passes/type-expr.ts`): extend `primitiveFromName` to map `int → i32`, `long → i64`, `float → f32`, `double → f64`, `byte → u8`.
- [x] **Diagnostics**: error messages and snapshot dumps continue to show the *canonical* name (`i32`, not `int`) so the output is stable regardless of which alias the user typed.
- [x] **Tests**: add a snippet `tests/snippets/type_aliases/` that exercises each alias in a variable declaration, a function parameter, and a cast; verify the VM output matches.

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

- [ ] Port to Vader
- [ ] Verify it runs `examples/` against the TS VM

### 2.5 Port the WASM emitter

- [ ] Port to Vader
- [ ] Snapshot-test parity

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
- [ ] **`std/regex` — full pattern engine** (NFA or DFA). Today's `std/string` ad-hoc helpers (§1.13b) cover the few patterns the compiler needs ; a real engine handles arbitrary user regex with `+`/`*`/`?`/char-classes/anchors/groups. ~800-1200 LoC in Vader, no host dependency.
- [ ] `std/time` — instants, durations, formatting
- [ ] `std/random` — PRNG (deterministic seeds)
- [ ] `std/crypto` — at least hashes (SHA, MD5)
- [ ] **`std/bignum` — `BigInteger` / `BigDecimal`** — arbitrary-precision integer and decimal arithmetic. Pure-Vader implementations (digit array + carry/borrow loops, Newton-Raphson for division) so the WASM target stays viable. Use cases : (a) JSON parsing without precision loss past 2^53 — currently `JsonNumber` stores f64 (cf. `std/json` v2 in §3.4) ; (b) money / financial DSLs where binary float rounding is unacceptable ; (c) crypto bignums (RSA, ECC) before `std/crypto` lands. Estimate ~600-1000 LoC each. `BigInteger` first since `BigDecimal` reuses its arithmetic.

### 3.5 Performance

- [ ] Generational GC (if mark-sweep proves limiting)
- [ ] Direct-ASM backend for one native target (validate the design)
- [ ] Escape analysis enabled (lower allocations on stack when proven safe)
- [ ] **Whole-program DCE.** Today the DCE pass (`src/dce/`) only prunes stdlib decls — user modules are kept verbatim so library targets and snapshot fixtures without `main` survive. Lift the `displayPath.startsWith("std/")` short-circuit and treat reachability uniformly across all `.vader` files, starting from `main`. Open questions to resolve before flipping the switch: (a) decide whether the absence of `main` is a hard error for native binaries, and how that interacts with `--target=wasm` (a wasm module typically has no `main` — it exposes `@export` fns to a JS host); (b) decide root semantics for `vader test` runs (every `@test` fn becomes a root); (c) ensure incremental rebuild stays sound once user code is also pruned.

### 3.6 Memory model extensions

- [ ] Explicit allocator API (arenas, pools) for perf-critical paths
- [ ] `unsafe { }` blocks for low-level FFI

### 3.7 Tooling

- [ ] LSP server (in Vader): diagnostics, hover, go-to-definition, completion
- [ ] VS Code extension
- [ ] Programmable build API (`build.vader` instead of `vader.json`)
- [ ] **Multi-library namespaces** — today `STDLIB_PATH_PREFIX = "std/"` is hard-coded in `src/resolver/module.ts` ; only one library prefix is recognised. Generalise to a registry mapping prefix → on-disk root, fed by `vader.json` (e.g. `{ "libraries": { "web": "./vendor/vader-web", "experimental": "./libs/exp" } }`). Use cases : (a) third-party libs once a package manager exists, (b) compiler-private namespace (`internal/` for `unsafe`, `atomic`, low-level GC hooks) with a visibility rule "`internal/` only importable by stdlib + compiler", (c) workspace-style monorepos. Touches `resolveImportPath`, `isStdlibModule`, the DCE filter, and dump-stage filters that currently short-circuit on `std/`. Estimate ~150 lines + a manifest schema bump.
- [ ] External package manager + central registry (much later)
- [ ] `man` page for the `vader` CLI
- [ ] GitHub Actions pipeline: build linux / macOS / Windows binaries and run the full test suite on all three targets. Requires self-hosting (§2) first so the pipeline compiles the Vader compiler with itself.

### 3.8 Language ergonomics

- [ ] Full array slicing: `arr[start..<end]`
- [ ] Static-size arrays: `[T; N]`
- [ ] Pattern matching extensions (or-patterns, range-patterns)
- [ ] `@derive(Eq, Display)` to auto-generate trivial impls
- [ ] **Implicit `void` return** (no `-> void` needed; `void` not user-visible). Touches : parser (FnDecl / FnType allow missing `->`), typechecker (treat absent return type as `TY.void`), formatter (drop trailing `-> void`). Forbid `void` as identifier in user code (R2010 or similar). Cf. SPEC §6 *Declaration*.
- [ ] **`Iterable($T)` trait + auto-`.iter()` in `for-in`** — collections implement `Iterable(T)` once and the for-loop desugars `for x in iter_target` into `for x in iter_target.iter()` whenever the target's type implements `Iterable(T)` (otherwise falls through to the existing array / `Iterator` paths). Required to drop the `iter :: fn(self: MutableList) -> ...` boilerplate. Cf. SPEC §7 *for*.
- [ ] **Trait-object boxing + dynamic dispatch for `Iterator(T)` (and other traits)** — today fns parameters typed `Iterator($T)` aren't usable in practice : passing a concrete `Range` or `T[]` as an `Iterator(i32)` argument boxes through a path the lowerer doesn't implement and emits `unreachable`. Same goes for any trait-typed argument — `for x in iter` works only because the lowerer special-cases it with a static `step` impl lookup on the concrete static type. To make `count(it: Iterator($T))`, `collect(it)`, and a future lazy `map`/`filter`/`fold` chain work : (a) reify each trait-implementing concrete type as a fat-pointer `(vtable_ptr, data_ptr)` ; (b) emit a vtable per `<concrete impl, trait>` pair (foundations already laid — see commit `d076263 feat(bytecode): vtable IR for virtual trait dispatch`) ; (c) auto-box concrete values into the trait fat pointer at call boundaries when the param type is a trait ; (d) route trait-method calls in fn bodies through the vtable. `std/iter`'s eager array-only API stays usable in the meantime ; the `Iterator(T)`-parameter forms come back once this lands. Cross-references : SPEC §7 *for-in dispatch*, SPEC §11 *Traits*.
- [ ] **`where T: A & B` syntax** for trait intersection bounds (replacing the current `+`). `&` mirrors the future union-of-bounds `|`. Single-token parser change ; small typecheck adjustment in `parseWhereClause`. Cf. SPEC §4 *Generics*.
- [ ] **Operator overloading via trait dispatch** : `+`/`-`/`*`/`/`/`%` route through `Add`/`Sub`/`Mul`/`Div`/`Rem` ; `==` through `Eq` ; `<`/`<=`/`>`/`>=` through `Ord` ; `a[i]` through new `Index($I, $T)` ; `a[i] = v` through new `IndexSet($I, $T)` ; `v in a` through new `Contains($T)`. Compound assignments (`+=` etc.) desugar at parse time. Add `Rem`, `Index`, `IndexSet`, `Contains` to `std/core`. Cf. SPEC §4 *Operator overloading*.
- [ ] **Function overloading by full signature** (post-MVP elevation of the pre-MVP receiver-type-only overloading) : pick the candidate whose all parameter types match the call site, not just the first. Subsumes pre-MVP behaviour ; requires generalising the resolver's overload table and the typechecker's call resolution.
- [x] **Expression-bodied functions with explicit return type** (2026-05-08). The earlier P1020 restriction (`fn(...) -> T = expr` was rejected) is lifted on both the TS parser and the Vader self-host parser ; `declareFn` honours the annotation and `inferExprBodiedReturns` skips already-typed expression bodies. The double-`->` SAM-style alternative (`fn double(x: i32) -> i32 -> x * 2`) is not introduced — visual overload outweighs the savings. Snippet : `tests/snippets/expr_bodied_recursive_typed/`.
- [ ] **Struct spread / functional update** : `MyStruct { ...other, .field = v }` — copy every field of `other`, override `.field`. The TS compiler relies massively on `{ ...r, typed }` style updates ; without this, the Vader port of the pipeline drivers (`src/pipeline.ts`) explodes from ~5 lines to ~80 lines per stage. Touches : parser (struct-literal grammar), typecheck (validate `other`'s type matches the struct), lowerer (expand to per-field copies).
- [x] **Tuple types and destructuring** (2026-05-08). Bracketed type form `[T1, T2, ...]` (≥ 2 elements) introduces heterogeneous tuples ; the array form moved to postfix `T[]`. Disambiguation of seq literals is contextual (TS-style) : `[1, 2]` is an array, `[1, "x"]` is a tuple, annotations win. Field access via `t.0`, `t.1`. Destructuring works in `let` (`[a, b] := pair()` ; nested + wildcards supported) and in match arms (`[a, b] -> ...`). Tuples lower to anonymous structs with synthetic fields `_0`, `_1`, ... keyed by BC type slot index (`__Tuple_${slotIdx}`) so distinct shapes don't collide in C-emit — no new BC ops or runtime types. Hard cut on the legacy `[T]` form (P1024). Vader self-host parser synced (`vader/parser/{ast,parser,dump}.vader` + `vader/diagnostics/codes.vader`) so `parser_parity` runs at 128/130 again.
- [ ] **Comptime tuple (and struct, array) values** — `@comptime DIM :: [10, 20]` typed as a tuple still fails with `C4011: comptime <kind> value not yet convertible`. The comptime `valueToComptime` (`src/comptime/run.ts:137-143`) bails on `struct`/`array`/`builder`/`fn` VM values without reading their fields. To unblock tuples specifically : (a) extend `ComptimeValue` (`src/comptime/value.ts`) with a `tuple` variant (or repurpose `struct` since tuples lower to anonymous structs and the back-emit can synthesise a struct lit), (b) read VM struct fields `_0`, `_1`, ... and recursively convert each, (c) re-emit the comptime tuple as a `LoweredStructLit` in `src/comptime/lower-decl.ts` so the inlined value compiles back. Scope estimate ~150 lines + tests. Also unblocks comptime structs / arrays since the same conversion path is shared. Today's workaround : keep comptime values primitive ; pass tuples via runtime-evaluated `:=`.
- [ ] **Spread destructuring** : `let [first, ...rest] = arr`. TS uses this in CLI parsing and pipeline glue. Workaround : index manually (`arr[0]`, `arr.slice(1)`). Low-priority but ergonomic.
- [ ] **Process spawn intrinsic** (`std/process.spawn(argv: [string]) -> ProcessResult`) — invoke external programs (notably `cc` for `vader build --target=native`). Currently the TS driver uses `Bun.spawn`. Required to self-host the native build pipeline. Native-only ; on WASM the import is unbound and triggers a comptime error.
- [ ] **Inline `@file(path)` as a comptime expression** (Zig `@embedFile` style). Today `@file("...")` is decorator-only and attaches to a top-level `ConstDecl`; lifting it to an expression position would let `show(@file("./data.txt"))` work directly. Touches: parser (allow `@`-expressions in expression position; carve out `@file` / `@env` etc. as recognised comptime expression heads), typecheck (`@file` ⇒ `string`, `@env` ⇒ `string \| null`), comptime (route through the existing sandbox path so `@allow-env` still gates `@env`). Path resolution stays source-relative to match decorator semantics. Estimate ~150 lines across phases.
- [x] **Implicit selector expressions** (2026-05-08, Odin-inspired). Enums : `f = .Variant`, `match d { .Variant -> … }`, array elements `[Day.Mon, .Tue]` work end-to-end via `DotVariantExpr` in expression position. Tagged unions of structs now also resolve `is .Foo` patterns against the scrutinee — extended `IsPattern` parsing with a leading-`.` form, added `implicitDot` flag to `NamedType`, suppressed global lookup in the resolver, and routed resolution through the match scrutinee in `typecheck/passes/match.ts::resolveImplicitDotVariant`. Snippet : `tests/snippets/implicit_dot_variant/`. Self-host parser port deferred (listed in `parser_parity.test.ts::KNOWN_FAILURES`).
- [ ] **Arbitrary `where` clauses on generics** (Odin-inspired) : extend the current `where T: Trait` form to accept any boolean comptime expression — `where N > 2`, `where size_of(T) <= 16`, `where is_numeric(T)`, possibly combined with trait bounds. Evaluated by the comptime VM at monomorphisation ; failure produces a localised diagnostic at the call site, not deep in the body. Touches : parser (where-clause grammar accepts expressions, not just bound lists), typecheck (run comptime predicate per instantiation), error reporter (point both at the caller and the failing predicate). Cf. SPEC §4 *Generics*.
- [x] **`@assert(condition)` — compile-time assertion** (2026-05-08). New `AssertDecl` AST node ; `@assert` recognised at top-level as a standalone decl (when no other decorators co-occur). Resolver walks the condition expression, typecheck enforces `bool`, comptime stage wraps each condition in a synthetic `__assert_<id>` ConstDecl and runs it through the existing comptime VM. A `false` result emits C4015. Snippet : `tests/snippets/decorator_assert/`. Self-host parser port deferred — `decorator_assert` is currently in `parser_parity.test.ts::KNOWN_FAILURES` until `vader/parser/parser.vader` learns the form.
- [x] **`@partial` on `match`** (2026-05-08). Opt-out of exhaustiveness for a single match expression. Parser recognises `@partial` in expression position (rejects any other `@`-prefix there with P1014) and flips a `partial: true` flag on `MatchExpr` ; typecheck skips the T3013 exhaustiveness check when the flag is set. Default stays exhaustive — the flag has to be opted into per match. Snippet : `tests/snippets/match_partial/`. Self-host parser port deferred (listed in `parser_parity.test.ts::KNOWN_FAILURES`).
- [x] **`@deprecated("reason")` decorator** (2026-05-08). Recognised on any decl ; every IdentExpr that resolves to it emits warning W0001 with the reason. Adds the `WARNING` registry + `makeWarn` factory + `warn` helper in typecheck — first warning-severity diagnostic, paving the way for future lints. Optional `since: "1.2"` arg deferred (named decorator args don't yet exist). Snippet : `tests/snippets/decorator_deprecated/`.

---

## Reference

- `SPEC.md` — language specification (target reference)
- `examples/` — working programs (start here)
- `stdlib/` — standard library source (Vader)
- `src/` — TypeScript compiler (to be created in Phase 0)
- `tests/` — snapshot tests (to be created in Phase 1)
