# Vader

> Applicative, simple, portable — the discipline of static typing, the ergonomics of a script.

Vader is a general-purpose, statically-typed language with type inference, targeting native binaries and WebAssembly. The compiler is being bootstrapped in TypeScript and will later self-host in Vader.

**Status:** pre-MVP, hobby project. Frontend (lexer → parser → resolver → type-checker → comptime →
monomorphizer → lowerer) feeds **midir** — a CFG/SSA mid-IR (build → SSA + peephole → DCE → escape
analysis → stack-allocation → scheduler → fromSSA) — which then emits the stack-machine **bytecode**
(round-trippable as `.vir` binary or `.virt` text). The **bytecode VM** (powering `vader run`) and the **C emitter**
(powering `vader build --target=native`, backed by a precise Cheney semi-space GC) both run the
example programs end-to-end, but they are not battle-tested and should not be relied on for anything
beyond experimentation. The legacy `LoweredAST → bytecode` walker was retired on 2026-05-09; midir is
now the single backend backbone. A WASM emitter is on the post-MVP roadmap (Phase 3) — the C
backend already covers native deployment and isn't load-bearing for the upcoming self-host. See
[`TODO.md`](./TODO.md) for the live roadmap and [`SPEC.md`](./SPEC.md) for the language reference.

A self-host port of the compiler in Vader itself is underway: the lexer and parser reach 191/191
byte-for-byte parity with the TS reference across the full snippet corpus, plus a top-level-decl
resolver MVP.

---

## Install

Prebuilt archives ship the `vader` binary alongside its stdlib and C runtime. Extract anywhere, then run `vader` directly (or add the folder to your `PATH`, or symlink `vader-<os>-<arch>/vader` into `~/.local/bin/vader`).

```sh
# macOS arm64 (Apple Silicon — Intel Macs are not supported)
tar -xzf vader-darwin-arm64.tar.gz
./vader-darwin-arm64/vader --version

# Linux x64
tar -xzf vader-linux-x64.tar.gz
./vader-linux-x64/vader --version

# Windows x64 (Explorer-extractable .zip)
# Right-click → Extract All, or from a terminal:
#   tar -xf vader-windows-x64.zip   (Windows 10+ ships tar natively)
#   unzip vader-windows-x64.zip     (macOS/Linux)
vader-windows-x64\vader.exe --version
```

The binary discovers `stdlib/` and `runtime/c/` next to itself, so keep the extracted folder intact (or symlink `vader` only if you preserve the original sidecar tree).

On macOS, Gatekeeper will block the unsigned binary on first launch. Strip the quarantine attribute :

```sh
xattr -d com.apple.quarantine ./vader-darwin-arm64/vader
```

## Build from source

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

Run the compiler directly through Bun :

```sh
# REPL
bun src/index.ts

# Show CLI help
bun src/index.ts --help
```

Build the standalone binary for your host (writes `dist/vader-<os>-<arch>/` and an archive — `.tar.gz` for Unix targets, `.zip` for Windows) :

```sh
bun run dist:current

# Or cross-compile a specific target / all of them:
bun run dist:linux-x64
bun run dist:darwin-arm64
bun run dist:windows-x64
bun run dist:all
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
# From a prebuilt binary
./vader-darwin-arm64/vader run examples/hello.vader

# Or from a source checkout
bun src/index.ts run examples/hello.vader

# → Hello, World!
```

Or compile it to a native binary (requires a C compiler in `PATH`):

```sh
./vader-darwin-arm64/vader build examples/hello.vader --target=native --out=/tmp/hello
# (or: bun src/index.ts build …)
/tmp/hello
# → Hello, World!
```

You can also inspect every compilation stage via the `dump` subcommand or emit the textual `.vir` IR via
`build --target=ir` (see below).

---

## CLI

Invoke as `vader <command>` (prebuilt binary) or `bun src/index.ts <command>` (source checkout — both are equivalent).

| Command                                        | Status  | What it does                                                                                                                                                                                                                                                              |
|------------------------------------------------|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `vader` *(no args)*                            | stub    | Will start a REPL. Not yet implemented.                                                                                                                                                                                                                                   |
| `vader --help` / `--version`                   | ✓       | Print usage / version.                                                                                                                                                                                                                                                    |
| `vader run [file]`                             | ✓       | Interpret a `.vader` source or a parsed `.vir` IR through the bytecode VM. Stdout/stderr go to the host.                                                                                                                                                                  |
| `vader build [file] [--target=…] [--out=path]` | partial | `--target=native` (default) writes a native binary **and** the generated C next to it (`<out>.c`). `--target=c` writes only the generated C. `--target=ir` writes the textual `.vir`. `--target=wasm` is a stub. `--manifest` mode is reserved for multi-module projects. |
| `vader fmt [path]`                             | partial | Opinionated formatter, no config. Written in Vader (under `vader/fmt/`) and dispatched through the bytecode VM. Flags : `--check` (read-only, exits 1 on drift), `--stdout` (write to stdout, single-file). Default rewrites in place. Idempotent and parse-equivalent ; not yet a byte-for-byte no-op on the stdlib (column alignment + multi-line-list grouping are deliberate style differences). |
| `vader test [path]`                            | ✓       | Discover and execute `@test` functions under `[path]` (default cwd). Each test fn is run as a separate VM entry ; failures (assertions, panics, traps) report the message and source span. Optional name override : `@test("readable name") my_test :: fn() -> void { … }`. Exits non-zero if any test fails. |
| `vader dump --stage=<stage> <file>`            | ✓       | Run the frontend up to `<stage>` and print the result (JSON or text, depending on stage).                                                                                                                                                                                 |

### Global options

- `--diagnostics=text|json` — render diagnostics for terminals (default) or as a stable JSON schema for tooling.
- `--allow-env` — let `@comptime` code read process environment variables (gated to preserve build reproducibility).
- `--no-bytecode-opt` — disable bytecode peephole optimisations. Optimisations are on by default; turn them off when inspecting raw codegen.

### `dump` stages

| Stage           | Output                                                                               | Why look at it                                                            |
|-----------------|--------------------------------------------------------------------------------------|---------------------------------------------------------------------------|
| `ast`           | parser AST as JSON                                                                   | Verify parse shape; debug grammar issues.                                 |
| `resolved-ast`  | per-module symbol table + import resolutions + reference counts                      | See how names bind across modules.                                        |
| `typed-ast`     | per-decl types + per-expression type counts                                          | Inspect inference, narrowing, generic instantiation.                      |
| `evaluated-ast` | `@comptime` / `@file` decl values + collected generic instances                      | See what the comptime engine baked.                                       |
| `lowered-ast`   | desugared tree (match → if/else, `?` → match, interp → builder calls, defer inlined) | Confirm the desugarings match expectations.                               |
| `dced-ast`      | lowered tree after stdlib reachability prune                                         | See which stdlib decls survive the prune.                                 |
| `cfg`           | midir CFG + SSA per fn (post DCE + escape annotation, pre fromSSA)                   | Inspect basic blocks, terminators, SSA values, escape sets, stack slots.  |
| `bytecode`      | `.vir` text of the compiled module                                                   | Inspect the final stack-machine ops + type/string/import tables.          |
| `c`, `wasm`     | (not yet implemented)                                                                | Reserved for the native / WASM backends.                                  |

Examples:

```sh
# Frontend stages
bun src/index.ts dump --stage=ast          examples/hello.vader
bun src/index.ts dump --stage=resolved-ast examples/hello.vader
bun src/index.ts dump --stage=typed-ast    examples/hello.vader

# Comptime + lowering + DCE + midir CFG + bytecode
bun src/index.ts dump --stage=evaluated-ast examples/hello.vader
bun src/index.ts dump --stage=lowered-ast   examples/hello.vader
bun src/index.ts dump --stage=dced-ast      examples/hello.vader
bun src/index.ts dump --stage=cfg           examples/hello.vader
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
| `--target=wasm`   | (not yet implemented)                                                              | Direct WebAssembly emission with the WASM GC proposal. Deferred to post-MVP (Phase 3).                                                                                 |

```sh
# Native binary (writes ./hello and ./hello.c)
vader build examples/hello.vader --target=native --out=/tmp/hello

# Just the C, no cc
vader build examples/hello.vader --target=c --out=/tmp/hello.c
```

#### Picking a different C compiler

`--cc=<path>` overrides the default `cc`. The `CC` env var is a lower-priority fallback. `strip` (on `--release`) follows the same toolchain when the compiler triple matches `*-strip`.

```sh
vader build foo.vader --target=native --cc=clang --out=/tmp/foo
CC=gcc-14 vader build foo.vader --target=native --out=/tmp/foo
```

#### Cross-compile to Windows from macOS/Linux

Install [mingw-w64](https://www.mingw-w64.org/) and [Wine](https://www.winehq.org/) (Wine optional — only needed to *run* the produced `.exe`) :

```sh
# macOS
brew install mingw-w64
brew install --cask wine-stable

# Debian/Ubuntu
sudo apt install mingw-w64 wine
```

Then point `vader build` at the cross-compiler — the `.exe` extension is added automatically when the triplet ends in `mingw32-gcc` :

```sh
vader build examples/hello.vader --target=native --cc=x86_64-w64-mingw32-gcc --out=/tmp/hello-win
file /tmp/hello-win.exe          # → PE32+ executable (console) x86-64, for MS Windows
wine /tmp/hello-win.exe          # → Hello, World!
```

`std/process.spawn` is implemented on Windows via `CreateProcess` + `CreatePipe` ; it accepts a Windows-style argv (`spawn(["cmd", "/c", "echo", "hi"])`). Unicode paths and `CreateProcessW` are not yet wired — argv strings flow through `CreateProcessA` (ANSI).

---

## Development

```sh
bun test                                   # run all tests (lexer + parser + resolver + typecheck snapshots + CLI)
bun run test:update                        # refresh snapshots after intentional output changes
bun run typecheck                          # TypeScript check (no emit)
bun vader dump --stage=ast file.vader      # convenience wrapper around `bun src/index.ts`
RUN_FMT_TESTS=1 bun test                   # also exercise the Vader-implemented formatter end-to-end (slow, ~2 min)
```

Snapshot tests live under `tests/snapshots/<phase>/<scenario>/` — each scenario is a folder with an `input.vader` and a `*.snap`. Setting `UPDATE_SNAPSHOTS=1` regenerates the snap files. Spotted a mismatch? Re-run with that env var, then `git diff` to review the change before committing.

The formatter tests (`tests/formatter*.test.ts`) invoke `vader fmt` through the bytecode VM ; each invocation pays a ~2-3 s VM-bootstrap cost. They're gated behind `RUN_FMT_TESTS=1` so the default `bun test` stays fast. The stdlib suite includes a byte-for-byte no-op probe on the subset already converged on the canonical style.

---

## Editor support

A minimal VS Code extension lives under [`editors/vscode/`](./editors/vscode/) — syntax highlighting for `.vader`, comment toggling, bracket matching. Install it locally from the repo:

```sh
# Symlink into VS Code's extensions folder, then reload the window
ln -s "$PWD/editors/vscode" ~/.vscode/extensions/vader-0.1.0
```

Or package it as a `.vsix` with [`vsce`](https://github.com/microsoft/vscode-vsce):

```sh
npm install -g @vscode/vsce
cd editors/vscode && vsce package
code --install-extension vader-0.1.0.vsix
```

After install, reload the window (`Cmd+Shift+P` → *Developer: Reload Window*). See [`editors/vscode/README.md`](./editors/vscode/README.md) for details.

---

## Contributing

This is a personal hobby project for now (single-author, exploratory). The codebase follows a few conventions worth knowing if you read or contribute:

- **No mutation of the AST.** Each phase produces side-tables keyed by AST node identity (see `src/resolver/resolved-ast.ts`, `src/typecheck/typed-ast.ts`).
- **All errors are diagnostics.** No compiler phase ever throws on user input — they emit `Diagnostic`s into a shared `DiagnosticCollector`. Diagnostic codes are namespaced per phase: `L0xxx` lexer, `P1xxx` parser, `R2xxx` resolver, `T3xxx` type-checker, `C4xxx` comptime, `W0xxx` warnings. Codes are stable once published.
- **Single backend backbone.** The bytecode is no longer emitted directly from the lowered AST: it descends from `midir` (a CFG/SSA mid-IR under `src/midir/`) where DCE, escape analysis, stack-allocation, and instruction scheduling all live. The VM, the C emitter, and the upcoming WASM emitter all consume the same downstream `BytecodeModule`.
- **Bun-first.** No `node:fs` when `Bun.file` does. No `vitest`/`jest`. No `express`. See [`CLAUDE.md`](./CLAUDE.md) for the full list.

---

## Roadmap

The full roadmap lives in [`TODO.md`](./TODO.md). The high-level milestones are:

| Phase | Goal | Status |
|-------|------|--------|
| **0 — Bootstrap** | Project scaffold, test runner, CLI stub | ✓ done |
| **1 — MVP (TypeScript compiler)** | Lexer → parser → resolver → type-checker → comptime engine → monomorphizer → lowerer → midir CFG/SSA (DCE + escape + stack-alloc + scheduler) → bytecode emitter → VM (`vader run`) → C emitter with precise Cheney GC (`vader build --target=native`). Trait-object boxing, tuples, `@assert`/`@deprecated`/`@partial`, implicit selector exprs, typed enums, `vader test` + `std/testing` runtime assertions all landed (May 2026). Polish items (slot reuse, C-emit `#line` directives, REPL, manifest mode, static methods, type-first reflection layers) tracked under §1.5 / §1.9 / §1.12 / §1.18b / §1.19 in [`TODO.md`](./TODO.md). | MVP cut shipped |
| **1.11–1.15 — Runtime, stdlib, CLI, formatter** | `std/` covers io / string / math / collections / iter / sort / json / path / process / runtime / testing. `vader fmt` MVP landed (written in Vader, idempotent + parse round-trip on the stdlib). `vader test` runs `@test` fns through the VM with per-file pass/fail reporting. Manifest-mode build and REPL deferred. | MVP cut shipped |
| **2 — Self-hosting** | Port the compiler to Vader; bootstrap check (`compiler_v2 == compiler_v3`). Lexer + parser + diagnostics + CLI + resolver MVP + formatter + LSP already ported (191/191 lex + parse parity); LSP semantic classification is currently lexer-based and being upgraded to an AST-based pipeline. | in progress |
| **3 — Post-MVP** | WASM emitter (bytecode → binary WASM with GC types, importable in the browser / wasmtime), concurrency, networking, generational GC, VS Code extension, CI pipeline for linux/macOS/Windows. | pending |

---

## Further reading

- [`SPEC.md`](./SPEC.md) — the language specification (target reference)
- [`TODO.md`](./TODO.md) — the implementation roadmap, item-by-item, with checkboxes
- [`examples/`](./examples/) — working programs to play with
- [`stdlib/`](./stdlib/) — the (in-progress) standard library, written in Vader

---

## License

MIT — see [`LICENSE`](./LICENSE).
