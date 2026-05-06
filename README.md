# Vader

> Applicative, simple, portable — the discipline of static typing, the ergonomics of a script.

Vader is a general-purpose, statically-typed language with type inference, targeting native binaries and WebAssembly. The compiler is being bootstrapped in TypeScript and will later self-host in Vader.

**Status:** pre-MVP. Frontend (lexer → parser → resolver → type-checker → comptime → monomorphizer → lowerer →
DCE → bytecode emitter → `.vir` text I/O), the **bytecode VM** (powering `vader run`), and the **C emitter**
(powering `vader build --target=native`) are all implemented. WASM emitter is next. See [`TODO.md`](./TODO.md)
for the live roadmap and [`SPEC.md`](./SPEC.md) for the language reference.

---

## Getting started

### Prerequisites

- **[Bun](https://bun.sh)** ≥ 1.3. Bun is the only runtime/build tool the project relies on.
  ```sh
  curl -fsSL https://bun.sh/install | bash
  ```

### Clone & install

```sh
git clone https://github.com/yakanet/vaderlang.git
cd vaderlang
bun install
```

There is no compiled binary yet — invoke the TypeScript entry point directly through Bun.

### Run the compiler

```sh
# REPL
bun src/index.ts

# Show CLI help
bun src/index.ts --help
```

### Hello, Vader

`examples/hello.vader`:

```vader
import "std/io" { println }

main :: fn() -> i32 {
    println("Hello, World!")
    return 0
}
```

Run it via the bytecode VM:

```sh
bun src/index.ts run examples/hello.vader
# → Hello, World!
```

Or compile it to a native binary (requires a C compiler in `PATH`):

```sh
bun src/index.ts build examples/hello.vader --target=native --out=/tmp/hello
/tmp/hello
# → Hello, World!
```

You can also inspect every compilation stage via the `dump` subcommand or emit the textual `.vir` IR via
`build --target=ir` (see below).

---

## CLI

Invoke as `bun src/index.ts <command>` (or via the `vader` wrapper script: `bun vader <command>`).

| Command                                        | Status  | What it does                                                                                                                                                                                                                                                              |
|------------------------------------------------|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `vader` *(no args)*                            | stub    | Will start a REPL. Not yet implemented.                                                                                                                                                                                                                                   |
| `vader --help` / `--version`                   | ✓       | Print usage / version.                                                                                                                                                                                                                                                    |
| `vader run [file]`                             | ✓       | Interpret a `.vader` source or a parsed `.vir` IR through the bytecode VM. Stdout/stderr go to the host.                                                                                                                                                                  |
| `vader build [file] [--target=…] [--out=path]` | partial | `--target=native` (default) writes a native binary **and** the generated C next to it (`<out>.c`). `--target=c` writes only the generated C. `--target=ir` writes the textual `.vir`. `--target=wasm` is a stub. `--manifest` mode is reserved for multi-module projects. |
| `vader fmt [path]`                             | stub    | Will canonicalise source layout. Not yet implemented.                                                                                                                                                                                                                     |
| `vader test [path]`                            | stub    | Will discover and execute `@test` functions. Not yet implemented.                                                                                                                                                                                                         |
| `vader dump --stage=<stage> <file>`            | ✓       | Run the frontend up to `<stage>` and print the result (JSON or text, depending on stage).                                                                                                                                                                                 |

### Global options

- `--diagnostics=text|json` — render diagnostics for terminals (default) or as a stable JSON schema for tooling.
- `--allow-env` — let `@comptime` code read process environment variables (gated to preserve build reproducibility).
- `--no-bytecode-opt` — disable bytecode peephole optimisations. Optimisations are on by default; turn them off when inspecting raw codegen.

### `dump` stages

| Stage           | Output                                                                               | Why look at it                                                   |
|-----------------|--------------------------------------------------------------------------------------|------------------------------------------------------------------|
| `ast`           | parser AST as JSON                                                                   | Verify parse shape; debug grammar issues.                        |
| `resolved-ast`  | per-module symbol table + import resolutions + reference counts                      | See how names bind across modules.                               |
| `typed-ast`     | per-decl types + per-expression type counts                                          | Inspect inference, narrowing, generic instantiation.             |
| `evaluated-ast` | `@comptime` / `@file` decl values + collected generic instances                      | See what the comptime engine baked.                              |
| `lowered-ast`   | desugared tree (match → if/else, `?` → match, interp → builder calls, defer inlined) | Confirm the desugarings match expectations.                      |
| `dced-ast`      | lowered tree after dead-code elimination                                             | See which stdlib decls survive the reachability prune.           |
| `bytecode`      | `.vir` text of the compiled module                                                   | Inspect the final stack-machine ops + type/string/import tables. |
| `c`, `wasm`     | (not yet implemented)                                                                | Reserved for the native / WASM backends.                         |

Examples:

```sh
# Frontend stages
bun src/index.ts dump --stage=ast          examples/hello.vader
bun src/index.ts dump --stage=resolved-ast examples/hello.vader
bun src/index.ts dump --stage=typed-ast    examples/hello.vader

# Comptime + lowering + DCE + bytecode
bun src/index.ts dump --stage=evaluated-ast examples/hello.vader
bun src/index.ts dump --stage=lowered-ast   examples/hello.vader
bun src/index.ts dump --stage=dced-ast      examples/hello.vader
bun src/index.ts dump --stage=bytecode      examples/hello.vader

# Emit the .vir IR alongside the source
bun src/index.ts build --target=ir examples/hello.vader
# → writes examples/hello.vir
```

### Build targets

| Target            | Output                                                                            | Notes                                                                                                                                                                  |
|-------------------|-----------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `--target=native` | A native executable **plus** the intermediate C source (`<out>.c`)                 | Default. Invokes `cc` (auto-detected POSIX). Runtime lives at `runtime/c/`. The `.c` is kept on disk so it can be inspected, profiled, or compiled with custom flags.  |
| `--target=c`      | Just the generated C source                                                        | Useful when you want to drive the C compiler yourself, or to stash the C as a snapshot. Symmetric with `--target=ir`.                                                  |
| `--target=ir`     | Textual `.vir` bytecode                                                            | Round-trippable: `vader run program.vir` re-executes it without re-parsing the source.                                                                                 |
| `--target=wasm`   | (not yet implemented)                                                              | Direct WebAssembly emission with the WASM GC proposal. Coming next.                                                                                                    |

```sh
# Native binary (writes ./hello and ./hello.c)
bun src/index.ts build examples/hello.vader --target=native --out=/tmp/hello

# Just the C, no cc
bun src/index.ts build examples/hello.vader --target=c --out=/tmp/hello.c
```

---

## Development

```sh
bun test                                   # run all tests (lexer + parser + resolver + typecheck snapshots + CLI)
bun run test:update                        # refresh snapshots after intentional output changes
bun run typecheck                          # TypeScript check (no emit)
bun vader dump --stage=ast file.vader      # convenience wrapper around `bun src/index.ts`
```

Snapshot tests live under `tests/snapshots/<phase>/<scenario>/` — each scenario is a folder with an `input.vader` and a `*.snap`. Setting `UPDATE_SNAPSHOTS=1` regenerates the snap files. Spotted a mismatch? Re-run with that env var, then `git diff` to review the change before committing.

---

## Contributing

This is a personal hobby project for now (single-author, exploratory). The codebase follows a few conventions worth knowing if you read or contribute:

- **No mutation of the AST.** Each phase produces side-tables keyed by AST node identity (see `src/resolver/resolved-ast.ts`, `src/typecheck/typed-ast.ts`).
- **All errors are diagnostics.** No compiler phase ever throws on user input — they emit `Diagnostic`s into a shared `DiagnosticCollector`. Diagnostic codes are namespaced per phase: `L0xxx` lexer, `P1xxx` parser, `R2xxx` resolver, `T3xxx` type-checker, etc. Codes are stable once published.
- **Bun-first.** No `node:fs` when `Bun.file` does. No `vitest`/`jest`. No `express`. See [`CLAUDE.md`](./CLAUDE.md) for the full list.

---

## Roadmap

The full roadmap lives in [`TODO.md`](./TODO.md). The high-level milestones are:

| Phase | Goal | Status |
|-------|------|--------|
| **0 — Bootstrap** | Project scaffold, test runner, CLI stub | ✓ done |
| **1 — MVP (TypeScript compiler)** | Lexer → parser → resolver → type-checker → comptime engine → monomorphizer → lowerer → DCE → bytecode emitter → VM (`vader run`) → C emitter (`vader build --target=native`). WASM emitter and mark-sweep GC still pending. | in progress |
| **1.10 — WASM emitter** | Bytecode → binary WASM with GC types, importable in the browser or via wasmtime. | next |
| **1.11–1.15 — Runtime, stdlib, CLI, formatter** | Mark-sweep GC, full `std/` in Vader, `vader test`, `vader fmt`. | pending |
| **2 — Self-hosting** | Port the compiler to Vader; bootstrap check (`compiler_v2 == compiler_v3`). | pending |
| **3 — Post-MVP** | Concurrency, networking, generational GC, LSP, VS Code extension, CI pipeline for linux/macOS/Windows. | pending |

---

## Further reading

- [`SPEC.md`](./SPEC.md) — the language specification (target reference)
- [`TODO.md`](./TODO.md) — the implementation roadmap, item-by-item, with checkboxes
- [`examples/`](./examples/) — working programs to play with
- [`stdlib/`](./stdlib/) — the (in-progress) standard library, written in Vader

---

## License

Not yet decided. The repo is shared for review only at this stage.
