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
- [ ] Add a basic snapshot-testing utility (read `tests/**/*.vader`, snapshot each pipeline stage's dump) — helper `tests/_helpers.ts` started, full snapshot driver to follow once the lexer exists
- [x] Wire a minimal CLI entry point: `bun src/index.ts <command>` — all top-level commands stubbed (`run`, `build`, `fmt`, `test`, `dump`, REPL)
- [x] Add `.gitignore` for `dist/`, `node_modules/`, build artifacts

---

## Phase 1 — MVP compiler in TypeScript

### 1.1 Lexer

- [ ] Token types enum (keywords, identifiers, operators, literals, layout)
- [ ] Source position tracking (file, line, column)
- [ ] Number literal parsing: int (with suffix), float (with suffix), hex/oct/bin, separators `_`
- [ ] String literal parsing:
  - [ ] Plain `"..."` with escapes
  - [ ] Interpolation tokens: split into `STRING_PART`, `INTERP_OPEN`, `INTERP_CLOSE` so the parser can re-enter expression mode inside `${...}`
  - [ ] Raw `r"..."`
  - [ ] Multiline `"""..."""` with interpolation
- [ ] Char literal `'a'` with escapes and Unicode codepoints
- [ ] Comments: `//` line, `/* */` block (nested? — decide and document)
- [ ] Newline-significance rules (treat newline as statement terminator unless line ends in operator / open bracket)
- [ ] Lexer error recovery: report and skip to next line
- [ ] Snapshot tests: feed sample sources, snapshot the token stream

### 1.2 Parser

- [ ] AST node types (declarations, statements, expressions, patterns, types)
- [ ] Top-level: `import`, `type`, `:: fn`, `:: struct`, `:: trait`, `T implements Trait`, decorators
- [ ] Expressions: literals, identifiers, calls, field access, indexing, unary, binary (with precedence table), if-expression, match-expression, lambdas, blocks, casts, generic instantiation `Foo(T)`, `expr?` postfix
- [ ] Statements: `:=` / `::`, assignments, `for`, `break`/`continue` (with labels), `defer`, `return`, expression-statements
- [ ] Patterns: `is Type`, struct destructuring with bindings and constraints, wildcard `_`, guards
- [ ] Type expressions: primitives, named, unions (`A | B`), generic instantiation, function types (`fn(T) -> U`), array `[T]`, nullability via union
- [ ] Decorator parsing: `@name`, `@name(args)`
- [ ] Generic syntax: `$T` introduction inline; `(T: type)` for struct headers; `where T: Trait` clauses
- [ ] Error recovery: synchronize on `}`, `;`, top-level keywords
- [ ] Snapshot tests: parse samples, snapshot the AST as JSON

### 1.3 Resolver

- [ ] Module loader: walk `vader.json`, find `.vader` files in each module folder
- [ ] Build a module graph; detect import cycles (error)
- [ ] Symbol tables per module, with scoping (file → module → import → builtins)
- [ ] Resolve `import "std/io"` against embedded stdlib
- [ ] Resolve `./relative` and `project-relative` paths
- [ ] Resolve `import ... { a, b }` destructuring and `as alias`
- [ ] Reject `private` access across module boundaries
- [ ] Wire decorators and trait impls to their target symbols
- [ ] Snapshot tests: parse + resolve, snapshot the resolved-AST + symbol table

### 1.4 Type-checker

- [ ] Type representation: primitives, structs, unions, generics, function types, nullable types
- [ ] Bidirectional inference engine
- [ ] Generic type parameter handling (`$T` ↔ deferred until comptime resolves it)
- [ ] Trait satisfaction check (with the union rule: union satisfies trait iff every member does)
- [ ] Type unification for `match` arms, `if`/`else` branches
- [ ] Narrowing in `match` arms (value's type is the matched variant inside the arm body)
- [ ] Match exhaustiveness checking for unions
- [ ] Default integer/float resolution (`i32` / `f64`)
- [ ] String interpolation type check: every `${expr}` must satisfy `Display`
- [ ] Operator resolution via traits (`+` → `Add.add`, `==` → `Eq.equals` for non-default types)
- [ ] Cast validity check
- [ ] `?` operator validation: callee must return a union; current function must return a compatible error union
- [ ] Diagnostics with source positions, multi-line context
- [ ] Snapshot tests: type-check samples, snapshot the typed AST + diagnostics

### 1.5 Comptime engine + monomorphizer

- [ ] Bytecode design (op table, operand encoding)
- [ ] AST → bytecode lowering for the comptime-eligible subset
- [ ] Stack-based VM with: locals, frames, calls, branches, allocations
- [ ] Sandbox: file read enabled, ENV gated by `--allow-env`, network/exec rejected
- [ ] Generic instantiation: when the type-checker encounters `List(i32)`, the engine specialises and registers the instance
- [ ] `@comptime` evaluation pass: walk the typed AST, evaluate marked nodes, replace with their values
- [ ] `@file "path"` reads contents at compile time
- [ ] Cycle detection: comptime depending on something not yet compiled triggers incremental compile
- [ ] Snapshot tests: small comptime programs whose results are baked into the AST

### 1.6 Lowerer

- [ ] Pattern match → if/else chains and jumps
- [ ] Trait calls → vtable lookup or static dispatch (depending on monomorphization status)
- [ ] `expr?` → `match expr { is Error e -> return e; is T t -> t }`
- [ ] String interpolation → `StringBuilder` calls + `Display.show`
- [ ] `defer` → block-exit code injection
- [ ] Null checks where required (TS-style narrowing should already handle most)
- [ ] Snapshot tests: snapshot the lowered AST

### 1.7 Bytecode emitter

- [ ] Lowered AST → final bytecode (same op table as comptime VM, possibly extended)
- [ ] String literal pool, generic instance table, function table
- [ ] Debug info: file/line per op (for the C `#line` directives, the WASM DWARF, and the IR text emitter)
- [ ] Snapshot tests: dump the bytecode in textual form

### 1.7b IR text emitter / reader (target `--target=ir`)

- [ ] Define the textual `.vir` grammar (line-oriented, one op per line, source position annotations, header for module / function / generic-instance tables)
- [ ] Bytecode → `.vir` serializer
- [ ] `.vir` → bytecode parser (so `vader run program.vir` works)
- [ ] Round-trip tests: serialize → parse → re-serialize must be a fixed point
- [ ] Tests: snapshot the `.vir` of every example program

### 1.8 VM (interpreter mode for `vader run`)

- [ ] Reuse the comptime VM
- [ ] Add I/O ops backed by Node/bun (so `vader run` works without a C runtime)
- [ ] REPL: read line → parse → typecheck → exec, persisting the symbol table between lines
- [ ] Tests: run sample programs end-to-end, compare stdout against expected

### 1.9 C emitter

- [ ] Bytecode → C source generation (text)
- [ ] Map Vader types to C types (`i32` → `int32_t`, `string` → `vader_string_t` struct, etc.)
- [ ] Emit function declarations, definitions, struct definitions
- [ ] `#line` directives for debugging
- [ ] Invoke `cc` with the emitted C + the runtime library
- [ ] Tests: emit, compile with `cc`, run, compare stdout

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
- [ ] `std/collections` — `List`, `MutableList`, `Map`, `MutableMap`, `Set`, `MutableSet`
- [ ] `std/math` — constants and float operations (use `@extern` to libm where useful on native, intrinsics on WASM)
- [ ] `std/builder` — `StringBuilder`
- [ ] `std/iter` — `map`, `filter`, `take`, `skip`, `fold`, `sum`, `count`, `collect`

### 1.14 Snapshot test infrastructure

- [ ] Test directory layout: each scenario is a folder with `input.vader` and a `snapshots/` subfolder
- [ ] Driver: run every stage, compare its dump against the snapshot
- [ ] Update mode: `bun test --update` to refresh snapshots after intentional changes
- [ ] Cover: simple programs, generics, traits, comptime, `@extern`, error propagation

### 1.15 Formatter

- [ ] Define formatting rules (one canonical layout — no options)
- [ ] AST → formatted source
- [ ] Idempotency check: `fmt(fmt(src)) == fmt(src)`

### 1.16 Examples

- [ ] `examples/hello.vader` ✓ (already created)
- [ ] `examples/fib.vader` — Fibonacci
- [ ] `examples/aoc_2024_day1.vader` — solve an AOC problem end-to-end (validates I/O + parsing + collections)
- [ ] `examples/wasm_browser/` — minimal HTML + Vader code calling JS via `@extern`

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

### 3.6 Memory model extensions

- [ ] Explicit allocator API (arenas, pools) for perf-critical paths
- [ ] `unsafe { }` blocks for low-level FFI

### 3.7 Tooling

- [ ] LSP server (in Vader): diagnostics, hover, go-to-definition, completion
- [ ] VS Code extension
- [ ] Programmable build API (`build.vader` instead of `vader.json`)
- [ ] External package manager + central registry (much later)

### 3.8 Language ergonomics

- [ ] Full array slicing: `arr[start..<end]`
- [ ] Static-size arrays: `[T; N]`
- [ ] Pattern matching extensions (or-patterns, range-patterns)
- [ ] `@derive(Eq, Display)` to auto-generate trivial impls
- [ ] Operator overloading polish (`Index`, `Iter`, ...)

---

## Reference

- `SPEC.md` — language specification (target reference)
- `examples/` — working programs (start here)
- `stdlib/` — standard library source (Vader)
- `src/` — TypeScript compiler (to be created in Phase 0)
- `tests/` — snapshot tests (to be created in Phase 1)
