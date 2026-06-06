# Vader

> Applicative, simple, portable — the discipline of static typing, the ergonomics of a script.

Vader is a general-purpose, statically-typed language with type inference, targeting native binaries and WebAssembly. The compiler is **self-hosted** — written in Vader and able to compile itself. A committed, gzip-compressed C seed (`bootstrap/bootstrap.c.gz`) lets any machine with a C compiler rebuild the toolchain from source — see [`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md). (A legacy TypeScript implementation under `src/` predates the self-host and is being retired — see TODO §2.8.)

**Status:** pre-MVP, hobby project. Frontend (lexer → parser → resolver → type-checker → comptime →
monomorphizer → lowerer) feeds **midir** — a CFG/SSA mid-IR (build → SSA + peephole → DCE → escape
analysis → stack-allocation → scheduler → fromSSA) — which then emits the stack-machine **bytecode**
(round-trippable as `.vir` binary or `.virt` text). The **bytecode VM** (powering `vader run`) and the **C emitter**
(powering `vader build --target=native`, backed by a precise generational Cheney GC) both run the
example programs end-to-end, but they are not battle-tested and should not be relied on for anything
beyond experimentation. The legacy `LoweredAST → bytecode` walker was retired on 2026-05-09; midir is
now the single backend backbone. A WASM emitter is on the post-MVP roadmap (Phase 3) — the C
backend already covers native deployment and is the backbone of the self-host bootstrap (the
committed seed is its C output). See [`TODO.md`](./TODO.md) for the live roadmap and
[`SPEC.md`](./SPEC.md) for the language reference.

The self-host port now spans the full pipeline (lexer → parser → resolver → type-checker → comptime
→ monomorphizer → lowerer → midir → bytecode → C emitter). The Vader-built compiler reproduces its
own generated C byte-for-byte — a verified fixed point — and CI rebuilds the entire toolchain from
the committed C seed (`bootstrap/`) on every push. What remains is retiring the legacy TypeScript
implementation under `src/` (TODO §2.8) and the post-MVP backends.

---

## Install

Prebuilt archives ship the `vader` binary alongside the stdlib, the C runtime, and the Vader sources it loads at runtime. Extract anywhere, then run `vader` directly (or add the folder to your `PATH`, or symlink `vader-<os>-<arch>/vader` into `~/.local/bin/vader`).

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

The prebuilt `vader` is, for now, the TypeScript compiler compiled into a standalone Bun executable — it bundles its own runtime (no Bun install needed) but loads `stdlib/`, `runtime/c/`, and the Vader sources (`vader-src/`) from next to itself, so keep the extracted folder intact (or symlink `vader` only if you preserve the original sidecar tree). Once the self-host is sealed (TODO §2.8), releases will ship the native self-hosted binary instead.

On macOS, Gatekeeper will block the unsigned binary on first launch. Strip the quarantine attribute :

```sh
xattr -d com.apple.quarantine ./vader-darwin-arm64/vader
```

## Build from source

Vader is self-hosted — the compiler is written in Vader and compiles itself — so building from a checkout needs only a C compiler and `gzip`. It bootstraps in three stages from a small, committed C **seed** (`bootstrap/bootstrap.c.gz`), which is exactly the chain CI replays on every push :

- **seed → stage0.** The seed is gzip-compressed C — the output a Vader compiler once emitted for the build-only entrypoint `vader/bootstrap/bootstrap.vader`, then committed and frozen. `cc` turns it into `build/stage0`, the bootstrap compiler. This trusted starting point needs no pre-existing Vader toolchain — that's what breaks the chicken-and-egg of compiling the Vader compiler.
- **stage0 → stage1 → stage2.** stage0 emits the C for `vader/cli/main.vader`, the script links it into `build/stage1` (the full compiler), and stage1 builds itself once more into `build/vader` (= stage2, the shipped compiler). A fixed-point check confirms stage1 and stage2 emit identical C.

```sh
git clone https://github.com/yakanet/vaderlang.git
cd vaderlang
```

### From the C seed

One command runs the whole 3-stage bootstrap — `cc` the seed into **stage0**, stage0 builds the intermediate **stage1**, stage1 builds the shipped compiler **stage2** (`build/vader`) — and, with `--dist`, bundles a distributable folder :

```sh
bash bootstrap/build.sh --dist     # seed → stage0 → stage1 → vader (stage2), + dist/vader-<os>-<arch>/
dist/vader-*/vader --version        # the bundle is self-contained — run it from anywhere
```

The `dist/vader-<os>-<arch>/` bundle (binary + stdlib + C runtime) is self-contained: the binary resolves `stdlib/` and `runtime/c/` **next to its own executable**, so it runs from any directory — no `cd` needed. Omit `--dist` to stop at `build/vader`.

`build.sh` prints a step-by-step log and defaults to `cc` ; override it with `CC=clang bootstrap/build.sh`. The runtime is linked externally from `runtime/c/` (no bundling), and the GC arenas auto-grow, so self-compiling the compiler needs no special environment tuning. See [`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md) for the seed lifecycle, the regeneration flow (`bootstrap/regenerate.sh`), and the fixed-point verification (`bootstrap/verify.sh`).

#### On Windows

The runtime relies on GCC/Clang extensions (`__attribute__((weak))`), so build with **mingw-w64** (gcc or clang) — **not** MSVC. Install a mingw-w64 toolchain with [winget](https://winstall.app/apps/BrechtSanders.WinLibs.MCF.UCRT), then run the PowerShell wrapper :

```powershell
winget install BrechtSanders.WinLibs.MCF.UCRT                       # mingw-w64 gcc/clang on PATH (once; reopen the terminal afterwards)
powershell -ExecutionPolicy Bypass -File bootstrap\build.ps1 -Dist  # → dist\vader-windows-<arch>\ (self-contained)
dist\vader-windows-*\vader.exe --version                            # runs from anywhere
```

`build.ps1` decompresses the seed through .NET's `GZipStream`, so no `gzip` install is needed ; pass `-CC clang` (or set `$env:CC`) to pick a different compiler, and drop `-Dist` to just build `build\vader.exe`.

Alternatively, the MSYS2 *MINGW64* shell bundles `bash`, mingw-w64 `gcc`, and `gzip` (`pacman -S mingw-w64-x86_64-gcc gzip`), so the Unix commands above run unchanged — the outputs just gain a `.exe` suffix.

(WSL builds a *Linux* binary, not a Windows `.exe` — use the Unix instructions inside it, or cross-compile from macOS/Linux per *Cross-compile to Windows* below.)

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
# The vader binary you built from the seed (or a prebuilt release)
./build/vader run examples/hello.vader

# → Hello, World!
```

Or compile it to a native binary (requires a C compiler in `PATH`):

```sh
./build/vader build examples/hello.vader --target=native --out=/tmp/hello
/tmp/hello
# → Hello, World!
```

You can also inspect every compilation stage via the `dump` subcommand or emit the textual `.vir` IR via
`build --target=ir` (see below).

---

## CLI

Invoke as `vader <command>`. The examples below assume a `vader` on your `PATH` ; otherwise call it by path, e.g. `./build/vader <command>`.

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
vader dump --stage=ast          examples/hello.vader
vader dump --stage=resolved-ast examples/hello.vader
vader dump --stage=typed-ast    examples/hello.vader

# Comptime + lowering + DCE + midir CFG + bytecode
vader dump --stage=evaluated-ast examples/hello.vader
vader dump --stage=lowered-ast   examples/hello.vader
vader dump --stage=dced-ast      examples/hello.vader
vader dump --stage=cfg           examples/hello.vader
vader dump --stage=bytecode      examples/hello.vader

# Emit the .vir IR alongside the source
vader build --target=ir examples/hello.vader
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

### Benchmarks

```sh
bun run bench                              # measure + compare to bench/baseline.json
bun run bench -- --update                  # rewrite baseline with current measurements
bun run bench -- --runs=5 --workload=primes  # custom run count, single workload
```

Five workloads measured across four implementations of each — Vader native (`--target=native --release`), the same kernel in Bun-TS, in Go, and in Java 25 (precompiled with `javac --release 25`, run via `java -cp bench <Name>`). Current baseline on a 2026 Apple Silicon laptop, full bench wall-time ~6 s :

| workload         | vader-native | bun-ts  | go      | java    |
|------------------|--------------|---------|---------|---------|
| `mandelbrot`     | 15.2 ms      | 22.3 ms | 16.8 ms | 44.0 ms |
| `primes`         | 22.2 ms      | 38.3 ms | 23.7 ms | 55.8 ms |
| `iter_chain`     |  2.1 ms      | 34.3 ms |  2.4 ms | 35.1 ms |
| `binary_trees`   | 14.3 ms      | 11.7 ms |  7.3 ms | 34.1 ms |
| `string_builder` |  3.6 ms      |  8.8 ms |  5.4 ms | 34.0 ms |
| `map_iter`       | 22.6 ms      | 31.3 ms |  8.2 ms | 40.1 ms |

The `vader-vm` column is disabled by default — each invocation pays 2-30 s for the parse + typecheck + lower + bytecode pipeline (dwarfing the actual VM loop), which inflates the total bench wall time to ~5 min without telling us anything `vader-native` doesn't. Uncomment the entry in `bench/run.ts` to opt back in when a change targets the VM exec path specifically.

`bun run bench` exits non-zero if any measurement regresses by more than 15 % vs the committed baseline (10 % was too tight for the < 20 ms native workloads — OS noise alone clears that), or if any implementation's checksum diverges. See [`bench/README.md`](./bench/README.md) for the workload sources, the comparison methodology, and notes on Go's FMA-driven checksum drift on `mandelbrot`.

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
| **2 — Self-hosting** | Port the compiler to Vader; bootstrap check (fixed point — the Vader-built compiler reproduces its own generated C byte-for-byte). The full pipeline (lexer → … → C emitter) is self-hosted, and a committed C seed under `bootstrap/` rebuilds the toolchain from a stock C compiler. Remaining: retire the legacy TypeScript implementation (`src/`, TODO §2.8) and finish the AST-based LSP semantic classification. | mostly done |
| **3 — Post-MVP** | WASM emitter (bytecode → binary WASM with GC types, importable in the browser / wasmtime), concurrency, networking, VS Code extension, CI pipeline for linux/macOS/Windows. | pending |

---

## Further reading

- [`SPEC.md`](./SPEC.md) — the language specification (target reference)
- [`TODO.md`](./TODO.md) — the implementation roadmap, item-by-item, with checkboxes
- [`examples/`](./examples/) — working programs to play with
- [`stdlib/`](./stdlib/) — the (in-progress) standard library, written in Vader

---

## License

MIT — see [`LICENSE`](./LICENSE).
