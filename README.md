# Vader

> Applicative, simple, portable — the discipline of static typing, the ergonomics of a script.

Vader is a general-purpose, statically-typed language with type inference, targeting native binaries and WebAssembly. The compiler is being bootstrapped in TypeScript and will later self-host in Vader.

**Status:** pre-MVP. The frontend (lexer → parser → resolver → type-checker → comptime → monomorphizer → lowerer →
bytecode emitter → `.vir` text I/O) is implemented; runtime backends (VM, C, WASM) are next. See [`TODO.md`](./TODO.md)
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

Once the VM lands you'll be able to run it with `vader run examples/hello.vader`. For now, you can inspect every
compilation stage via the `dump` subcommand or emit the textual `.vir` IR via `build --target=ir` (see below).

---

## CLI

Invoke as `bun src/index.ts <command>` (or via the `vader` wrapper script: `bun vader <command>`).

| Command                                        | Status  | What it does                                                                                                                                                                                                          |
|------------------------------------------------|---------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `vader` *(no args)*                            | stub    | Starts the REPL — placeholder until the VM lands.                                                                                                                                                                     |
| `vader --help` / `--version`                   | ✓       | Print usage / version.                                                                                                                                                                                                |
| `vader run [file]`                             | stub    | Will interpret a `.vader` (or `.vir`) file via the VM. Not yet wired.                                                                                                                                                 |
| `vader build [file] [--target=…] [--out=path]` | partial | `--target=ir` writes the textual `.vir` next to the source (or to `--out=`). `--target=native` and `--target=wasm` are stubs awaiting the C / WASM emitters. `--manifest` mode is reserved for multi-module projects. |
| `vader fmt [path]`                             | stub    | Will canonicalise source layout. Not yet implemented.                                                                                                                                                                 |
| `vader test [path]`                            | stub    | Will discover and execute `@test` functions. Not yet implemented.                                                                                                                                                     |
| `vader dump --stage=<stage> <file>`            | ✓       | Run the frontend up to `<stage>` and print the result (JSON or text, depending on stage).                                                                                                                             |

### Global options

- `--diagnostics=text|json` — render diagnostics for terminals (default) or as a stable JSON schema for tooling.
- `--allow-env` — let `@comptime` code read process environment variables (gated to preserve build reproducibility).

### `dump` stages

| Stage           | Output                                                                               | Why look at it                                                   |
|-----------------|--------------------------------------------------------------------------------------|------------------------------------------------------------------|
| `ast`           | parser AST as JSON                                                                   | Verify parse shape; debug grammar issues.                        |
| `resolved-ast`  | per-module symbol table + import resolutions + reference counts                      | See how names bind across modules.                               |
| `typed-ast`     | per-decl types + per-expression type counts                                          | Inspect inference, narrowing, generic instantiation.             |
| `evaluated-ast` | `@comptime` / `@file` decl values + collected generic instances                      | See what the comptime engine baked.                              |
| `lowered-ast`   | desugared tree (match → if/else, `?` → match, interp → builder calls, defer inlined) | Confirm the desugarings match expectations.                      |
| `bytecode`      | `.vir` text of the compiled module                                                   | Inspect the final stack-machine ops + type/string/import tables. |
| `c`, `wasm`     | (not yet implemented)                                                                | Reserved for the native / WASM backends.                         |

Examples:

```sh
# Frontend stages
bun src/index.ts dump --stage=ast          examples/hello.vader
bun src/index.ts dump --stage=resolved-ast examples/hello.vader
bun src/index.ts dump --stage=typed-ast    examples/hello.vader

# Comptime + lowering + bytecode
bun src/index.ts dump --stage=evaluated-ast examples/hello.vader
bun src/index.ts dump --stage=lowered-ast   examples/hello.vader
bun src/index.ts dump --stage=bytecode      examples/hello.vader

# Emit the .vir IR alongside the source
bun src/index.ts build --target=ir examples/hello.vader
# → writes examples/hello.vir
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

## Further reading

- [`SPEC.md`](./SPEC.md) — the language specification (target reference)
- [`TODO.md`](./TODO.md) — the implementation roadmap, item-by-item, with checkboxes
- [`examples/`](./examples/) — working programs to play with
- [`stdlib/`](./stdlib/) — the (in-progress) standard library, written in Vader

---

## License

Not yet decided. The repo is shared for review only at this stage.
