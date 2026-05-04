# Vader

> Applicative, simple, portable — the discipline of static typing, the ergonomics of a script.

Vader is a general-purpose, statically-typed language with type inference, targeting native binaries and WebAssembly. The compiler is being bootstrapped in TypeScript and will later self-host in Vader.

**Status:** pre-MVP. The frontend (lexer → parser → resolver → type-checker) is implemented; backends (interpreter, C, WASM) are next. See [`TODO.md`](./TODO.md) for the live roadmap and [`SPEC.md`](./SPEC.md) for the language reference.

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

# Inspect a Vader source at any compilation stage
bun src/index.ts dump --stage=ast          examples/hello.vader
bun src/index.ts dump --stage=resolved-ast examples/hello.vader
bun src/index.ts dump --stage=typed-ast    examples/hello.vader
```

The `run` / `build` / `test` / `fmt` subcommands are stubbed today (the type-checker just landed; codegen is the next milestone). The `dump` subcommand is the most useful exercise of the current frontend.

### Hello, Vader

`examples/hello.vader`:

```vader
import "std/io" { println }

main :: fn() -> i32 {
    println("Hello, World!")
    return 0
}
```

Once the interpreter lands you'll be able to run it with `vader run examples/hello.vader`. For now, dumping the typed AST will show that `main` is `fn() -> i32` and `println` resolves to `std/io::println : fn(string) -> void`.

---

## Project layout

```
src/
├── lexer/         Token stream, number/string/comment handling, newline rules
├── parser/        Pratt expression parser + recursive-descent decls
├── resolver/      Module loading, symbol tables, import resolution, name lookup
├── typecheck/     Type IR, bidirectional inference, trait satisfaction, ?
├── diagnostics/   Structured Diagnostic, Span, Position, terminal/JSON renderers
├── commands/      CLI subcommands (run, build, fmt, test, dump, repl)
├── cli/           Global option parsing
├── pipeline.ts    Frontend pipeline helpers (parse → resolve → typecheck)
└── index.ts       Entry point

stdlib/std/        Vader source for the standard library (parsed by the resolver)
examples/          Sample programs
tests/             Bun test suites + folder-per-scenario snapshot tests
SPEC.md            Language specification
TODO.md            Implementation roadmap
```

---

## Development

```sh
bun test                                   # run all tests (lexer + parser + resolver + typecheck snapshots + CLI)
bun run test:update                        # refresh snapshots after intentional output changes
bun run typecheck                          # TypeScript check (no emit)
bun run vader -- dump --stage=ast file.vader  # convenience wrapper around `bun src/index.ts`
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
