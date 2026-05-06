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
- [x] Type expressions: primitives, named, unions (`A | B`), generic instantiation, function types (`fn(T) -> U`), array `[T]`, nullability via union
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

- [ ] Mono+lower+emit support for **fn instances** observed via `observeFnCall`. The registry now records them, but `monomorphizeProject` (`src/monomorphize/index.ts`) only materialises struct instances. Implies cloning the FnDecl with the substitution, mangling, and routing call sites to the specialised slot. Probably ~150 lines.
- [x] **Generic impls** (`ArrayIter(T) implements Iterator(T)`) — done. Mono materialises one entry per `(impl member, struct args)` via `implMethodEntries: Map<FnDecl, Map<argsKey, MonoEntry>>`. Resolver shares typeParam symbols cross-module (via `typeParamSymbols`) so an impl in std/core can reuse the base struct's typeParam without clobbering. Lowerer's UFCS dispatch + Iterator lookup pick the right specialisation by struct args.
- [ ] **`std/iter` combinators** (`map / filter / take / skip / fold / sum / count / collect`). Per SPEC §15 these are MVP scope. They need (a) generic-fn dispatch so `items.map(f).filter(p)` compiles (currently fn typeParams aren't inferred), (b) `Map<I, T, U>` / `Filter<I, T>` iterator-wrapper structs implementing Iterator (the stack of generic impls already works). Today they're declared as stubs in `stdlib/std/iter.vader`.
- [ ] **Generic `len(arr)`** — needs generic-fn dispatch (deferred). Today `ArrayIter` carries an explicit `length: i32` field set at auto-wrap time via `LoweredArrayLen` (the bytecode `array.len` op). Once generic-fn dispatch lands we can drop that field and call `len(self.arr)` directly.
- [ ] Type-checker support for **inferred** generic-fn type args — without explicit `Foo(T)`, the typecheck doesn't track which call sites instantiate which type params. Today `observeFnCall` only catches the explicit form. Lifting this requires recording `(CallExpr → typeArgs)` from the inference engine.
- [ ] `for x in iter` / `MutableList(u32){}.add(...)` inside @comptime — needs Iterator-trait dispatch + arena allocation for transient collections.

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

- [ ] Lambda lifting (closure conversion). Today an unlowered `LambdaExpr` becomes a `LoweredUnreachable` so the gap is visible in dumps; when generic-fn dispatch and Iterator land, lambdas need to be hoisted to top-level fns with explicit captures.
- [x] **`RangeExpr` + `[T]` arrays lowered via `Iterator` dispatch.** `0..<n` / `0..=n` lower to `Range { .start, .end, .inclusive, .cursor=0 }` struct literals; raw arrays in `for x in arr` auto-wrap into `ArrayIter(T) { .arr, .cursor=0, .length=array.len(arr) }`. `for-in` desugars to a step-loop dispatched through the `Iterator(T)::step` impl on the iter's static type — the range and array fast-paths are gone. `Range`, `Done`, `Yielded(T)`, `Iterator(T)`, and `ArrayIter(T)` live in `std/core` (the trait uses the sum-type variant `Done | Yielded(T)` to avoid the `T | null` sentinel collision for lists whose element type can be `null`). Generic impls (`ArrayIter(T) implements Iterator(T)`) materialise per concrete struct args via the mono pass: pass 1 emits non-generic impl members, pass 2 emits one entry per `(impl member, struct args)`. Snapshots: `tests/snapshots/vm/for_range/` and `tests/snapshots/vm/array_iter/`.
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
- [ ] First-class function values (closures, function pointers) — bare `LoweredIdent` of a fn symbol outside a call's callee position currently emits `unreachable`.
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
- [ ] Optimisation flags (`-O2`, `-flto`) — currently `-O0`.
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

- [ ] Mark-sweep stop-the-world GC (~500–1000 lines of C)
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
- [x] `std/list` — `MutableList(T)` with full ops + `Iterator(T)` impl. Stub `List(T)`.
- [x] `std/map` — `MutableMap(K, V)` linear-search MVP (post-MVP : promote to chaining HashMap once trait dispatch on `$K` lands). Stub `Map(K, V)` + `Bucket(K, V)` for future.
- [x] `std/set` — `MutableSet(T)` linear-search MVP. Stub `Set(T)`.
- [ ] **Promote `MutableMap` / `MutableSet` to chaining HashMap** once trait-method dispatch on bounded type parameters is implemented (so `key.hash()` / `key.equals(other)` work inside generic bodies).
- [ ] **Implement immutable `List`/`Map`/`Set` ops + `to_immutable` conversion** (currently struct stubs only).
- [ ] **Iterator impls for `MutableMap` / `MutableSet`** — yield `Entry(K, V)` / `T`. Skipped at MVP because writing them in a generic body needs the trait-dispatch fix above to be ergonomic.
- [ ] `std/math` — constants and float operations (use `@extern` to libm where useful on native, intrinsics on WASM)
- [ ] `std/builder` — `StringBuilder`
- [ ] `std/iter` — `map`, `filter`, `take`, `skip`, `fold`, `sum`, `count`, `collect`

### 1.14 Snapshot test infrastructure

- [x] Test directory layout: `tests/snippets/{name}/_main.vader` (single source per test, `_main` sorts first in IDEs) + `{phase}.snapshot` files alongside it.
- [x] Driver: runs every pipeline phase (lexer → parser → resolver → typecheck → comptime → lower → bytecode → vm → native) on each snippet; compares dump against snapshot. Lives in `tests/snapshot.ts` + `tests/snapshot.test.ts` + `tests/vm.test.ts` + `tests/native.test.ts`.
- [x] Update mode: `UPDATE_SNAPSHOTS=1 bun test` to refresh snapshots after intentional changes.
- [x] Cover: 45 snippets — simple programs, generics, traits, comptime, error propagation, multi-file modules, fixtures.

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
- [ ] **Generic `Range`** — currently hardcoded `Range(i32)`. Make it `Range($T)` so `for i in 0..<some_usize { }` works without an explicit cast. Touches the parser (range desugaring records target type), the typechecker (`inferRange` accepts any integer), the lowerer/iter wrapping.
- [ ] **Static methods / associated functions** (`List.ofSize(10)` style) — parser + resolver + typechecker support for `Type.method(args)` where `method` is a free function declared alongside `Type` in the same module. Required for Java-like factory APIs.
- [ ] **Trait-method dispatch on bounded type parameters** — inside a generic body, `key.hash()` where `key: $K` and `K: Hash` should resolve to the trait method, monomorphised post-typecheck. Required to promote `MutableMap`/`MutableSet` from O(n) linear-search to chaining HashMap.
- [ ] **First-class function values** — `fn(K) -> u64` as a struct field / local variable / argument. Currently the bytecode emitter falls through to `unreachable` for free-function ident references that aren't the callee of a `CallExpr`.
- [ ] **Decide `usize` width on the WASM target** — WASM64 only (always 64-bit) vs supporting WASM32 (`usize` becomes `i32`). Affects the C-emit side too if we want one binary to share logic.

### 1.18c Function overloading by receiver type (pre-MVP)

Lift `R2004` for free functions whose names collide if their **first parameter** types differ. Required so that `get(MutableList, usize)` and `get(MutableMap, K)` (and similar) coexist in user code without forcing aliasing on every import.

- [ ] **Resolver** (`src/resolver/collect.ts` + symbol table) : a module-level name maps to a *list of overload candidates* instead of a single `Symbol`. R2004 fires only on truly ambiguous declarations (same first-param type).
- [ ] **Typechecker** (`src/typecheck/passes/call.ts` `inferField` + UFCS dispatch) : at call resolution, pick the candidate whose first parameter type matches the receiver. Generic candidates (`fn(self: $T, ...)`) act as wildcards and conflict with concrete-receiver overloads of the same name.
- [ ] **Direct-call resolution** (`inferCall` for `f(x, ...)`) : pick the overload whose first parameter accepts `x`'s type. Same wildcard rule.
- [ ] **Diagnostic** : new code (e.g. `T3024`) for ambiguous overload resolution.
- [ ] **Tests** : `tests/snippets/overload_first_param/` — list `get(MutableList, usize)` and `get(MutableMap, K)` and call both via UFCS in the same module.
- [ ] **Stdlib cleanup** : remove the `len` / `is_empty` / `iter` workaround names in `std/map.vader`, `std/set.vader` once overloading lands. Same for the `MutableMap` `len` (vs `size` field) workaround.

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

### 2.1 Port the parser to Vader

- [ ] Port lexer to Vader
- [ ] Port AST representation to Vader (struct + union types)
- [ ] Port parser to Vader
- [ ] Snapshot-test parity: TS parser and Vader parser must produce identical AST dumps for every sample

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

- [ ] `std/json` — parse and serialise
- [ ] `std/regex` — pattern matching for strings
- [ ] `std/time` — instants, durations, formatting
- [ ] `std/random` — PRNG (deterministic seeds)
- [ ] `std/crypto` — at least hashes (SHA, MD5)

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
- [ ] **`where T: A & B` syntax** for trait intersection bounds (replacing the current `+`). `&` mirrors the future union-of-bounds `|`. Single-token parser change ; small typecheck adjustment in `parseWhereClause`. Cf. SPEC §4 *Generics*.
- [ ] **Operator overloading via trait dispatch** : `+`/`-`/`*`/`/`/`%` route through `Add`/`Sub`/`Mul`/`Div`/`Rem` ; `==` through `Eq` ; `<`/`<=`/`>`/`>=` through `Ord` ; `a[i]` through new `Index($I, $T)` ; `a[i] = v` through new `IndexSet($I, $T)` ; `v in a` through new `Contains($T)`. Compound assignments (`+=` etc.) desugar at parse time. Add `Rem`, `Index`, `IndexSet`, `Contains` to `std/core`. Cf. SPEC §4 *Operator overloading*.
- [ ] **Function overloading by full signature** (post-MVP elevation of the pre-MVP receiver-type-only overloading) : pick the candidate whose all parameter types match the call site, not just the first. Subsumes pre-MVP behaviour ; requires generalising the resolver's overload table and the typechecker's call resolution.
- [ ] **Inline `@file(path)` as a comptime expression** (Zig `@embedFile` style). Today `@file("...")` is decorator-only and attaches to a top-level `ConstDecl`; lifting it to an expression position would let `show(@file("./data.txt"))` work directly. Touches: parser (allow `@`-expressions in expression position; carve out `@file` / `@env` etc. as recognised comptime expression heads), typecheck (`@file` ⇒ `string`, `@env` ⇒ `string \| null`), comptime (route through the existing sandbox path so `@allow-env` still gates `@env`). Path resolution stays source-relative to match decorator semantics. Estimate ~150 lines across phases.

---

## Reference

- `SPEC.md` — language specification (target reference)
- `examples/` — working programs (start here)
- `stdlib/` — standard library source (Vader)
- `src/` — TypeScript compiler (to be created in Phase 0)
- `tests/` — snapshot tests (to be created in Phase 1)
