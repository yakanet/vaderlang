<div align="center">

# Vader

[![CI](https://github.com/yakanet/vaderlang/actions/workflows/build.yml/badge.svg)](https://github.com/yakanet/vaderlang/actions/workflows/build.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE)
![Status](https://img.shields.io/badge/status-pre--MVP-orange)
![Self-hosted](https://img.shields.io/badge/compiler-self--hosted-brightgreen)

**The discipline of static typing, the ergonomics of a script.**

A general-purpose, statically-typed language with type inference — compiled to
fast native binaries through a compiler that is written in Vader and compiles itself.

</div>

```vader
module "main"

import "std/io"
import "std/math"

// A sum type — `match` must cover every variant (the compiler checks).
Shape :: Circle | Rect

Circle :: struct { radius: f64 }
Rect   :: struct { w: f64, h: f64 }

area :: fn(s: Shape) -> f64 = match s {
    is Circle as c -> pi * c.radius * c.radius
    is Rect   as r -> r.w * r.h
}

main :: fn() -> i32 {
    shapes: Shape[] = [
        Circle { .radius = 2.0 },
        Rect { .w = 3.0, .h = 4.0 },
    ]
    defer println("done.")

    total := 0.0                    // `:=` declares a mutable local; `::` is a constant
    for s in shapes {
        total += s.area()
    }
    println("total area of ${shapes.len()} shapes: ${total}")
    return 0
}
```

```sh
vader run shapes.vader
# → total area of 2 shapes: 24.566370614359172
# → done.
```

---

## Why Vader

- **Static typing that gets out of the way.** Bidirectional inference means you rarely write a type. `::` binds a constant, `:=` a mutable local — the distinction is the whole ceremony.
- **Explicit nullability, no exceptions.** There is no implicit `null`: a value is nullable only as an explicit `T | null` union. Errors are values too, returned in a union with the success type. Both are checked — and narrowed — at compile time.
- **No OOP, no boilerplate.** No classes, no inheritance. UFCS (`a.f(b)` ≡ `f(a, b)`) gives you method-call ergonomics over plain functions and structs.
- **Metaprogramming without macros.** `@comptime` runs real Vader at compile time — no text substitution, no runtime reflection. The same machinery drives generic monomorphization.
- **Compiles to fast native code.** A C backend (`vader build`) produces native binaries backed by a precise generational GC; a bytecode VM (`vader run`) executes without a build step. WASM is on the roadmap.
- **Self-hosted, reproducibly.** The compiler is written in Vader and compiles itself to a *byte-for-byte* fixed point. A committed C seed lets any machine with a C compiler rebuild the whole toolchain from source.

> **Status: pre-MVP, hobby project.** The backends run the examples end-to-end but are not battle-tested — treat Vader as an experiment, not a tool to build on yet. The compiler internals (frontend → midir CFG/SSA → bytecode → C) are documented in [`SPEC.md` §2](./SPEC.md).

## Quick start

Grab a [prebuilt release](#install) (or [build from the C seed](#build-from-source)), then:

```vader
// examples/hello/hello.vader
import "std/io"

main :: fn() -> i32 {
    println("Hello, World!")
    return 0
}
```

```sh
vader run examples/hello/hello.vader              # run via the bytecode VM
vader build examples/hello/hello.vader --out=hello && ./hello   # or compile to native
```

Inspect any compilation stage with [`vader dump`](#dump-stages), or emit textual IR with `vader build --target=ir`.

---

## Install

**Coming soon**: prebuilt binaries for macOS arm64 (Apple Silicon), Linux x64, and Windows x64 (Explorer-extractable .zip; Windows 10+ ships tar natively).
<!---
Prebuilt archives ship the `vader` binary alongside the stdlib, the C runtime, and the Vader sources it loads at runtime. Extract anywhere, then run `vader` directly (or add the folder to your `PATH`).

```sh
# macOS arm64 (Apple Silicon — Intel Macs are not supported)
tar -xzf vader-darwin-arm64.tar.gz && ./vader-darwin-arm64/vader --version

# Linux x64
tar -xzf vader-linux-x64.tar.gz && ./vader-linux-x64/vader --version

# Windows x64 (Explorer-extractable .zip; Windows 10+ ships tar natively)
tar -xf vader-windows-x64.zip && vader-windows-x64\vader.exe --version
```

The prebuilt `vader` is the native self-hosted compiler, built from the committed C seed (see [Build from source](#build-from-source)) and packaged as a self-contained bundle — it loads `stdlib/` and `runtime/c/` from next to itself, so keep the extracted folder intact.

On macOS, Gatekeeper blocks the unsigned binary on first launch — strip the quarantine attribute:

```sh
xattr -d com.apple.quarantine ./vader-darwin-arm64/vader
```
-->

## Build from source

Vader is self-hosted, so building from a checkout needs only a **C compiler** and **gzip**. It bootstraps in three stages from a small, committed C **seed** (`bootstrap/bootstrap.c.gz`) — the exact chain CI replays on every push:

- **seed → stage0.** The seed is frozen C, once emitted by a Vader compiler for the build-only entrypoint `vader/bootstrap/bootstrap.vader`. `cc` turns it into `build/stage0`. This trusted starting point needs no pre-existing Vader toolchain — that's what breaks the chicken-and-egg.
- **stage0 → stage1 → stage2.** stage0 builds the full compiler (`build/stage1`), which builds itself once more into `build/vader` (stage2). A fixed-point check confirms stage1 and stage2 emit identical C.

```sh
git clone https://github.com/yakanet/vaderlang.git
cd vaderlang
bash bootstrap/build.sh --dist        # seed → stage0 → stage1 → vader (stage2), + dist/vader-<os>-<arch>/
dist/vader-*/vader --version          # the bundle is self-contained — run it from anywhere
```

The `dist/vader-<os>-<arch>/` bundle (binary + stdlib + C runtime) resolves `stdlib/` and `runtime/c/` next to its own executable, so it runs from any directory. Omit `--dist` to stop at `build/vader`. Override the compiler with `CC=clang bootstrap/build.sh`; the GC arenas auto-grow, so self-compiling needs no environment tuning. See [`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md) for the seed lifecycle, regeneration (`bootstrap/regenerate.sh`), and fixed-point verification (`bootstrap/verify.sh`).

### On Windows

The runtime relies on GCC/Clang extensions (`__attribute__((weak))`), so build with **mingw-w64** (gcc or clang) — **not** MSVC. Install a toolchain with [winget](https://winstall.app/apps/BrechtSanders.WinLibs.MCF.UCRT), then run the PowerShell wrapper:

```powershell
winget install BrechtSanders.WinLibs.MCF.UCRT                       # mingw-w64 on PATH (once; reopen the terminal)
powershell -ExecutionPolicy Bypass -File bootstrap\build.ps1 -Dist  # → dist\vader-windows-<arch>\ (self-contained)
dist\vader-windows-*\vader.exe --version
```

`build.ps1` decompresses the seed via .NET's `GZipStream` (no `gzip` needed); pass `-CC clang` to pick a different compiler, or drop `-Dist` to just build `build\vader.exe`. Alternatively, the MSYS2 *MINGW64* shell bundles `bash`, `gcc`, and `gzip` (`pacman -S mingw-w64-x86_64-gcc gzip`), so the Unix commands run unchanged. (WSL builds a *Linux* binary, not a Windows `.exe`.)

---

## CLI

Invoke as `vader <command>`. The examples assume `vader` is on your `PATH`; otherwise call it by path (`./build/vader <command>`).

| Command                                        | Status  | What it does                                                                                                                                                                                                                                                              |
|------------------------------------------------|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `vader` *(no args)*                            | stub    | Will start a REPL. Not yet implemented.                                                                                                                                                                                                                                   |
| `vader --help` / `--version`                   | ✓       | Print usage / version.                                                                                                                                                                                                                                                    |
| `vader run [file]`                             | ✓       | Interpret a `.vader` source or a parsed `.vir` IR through the bytecode VM. Stdout/stderr go to the host.                                                                                                                                                                  |
| `vader build [file] [--target=…] [--out=path]` | partial | `--target=native` (default) writes a native binary **and** the generated C (`<out>.c`). `--target=c` writes only the C. `--target=ir` writes textual `.vir`. `--target=wasm` is a stub. `--manifest` is reserved for multi-module projects.                                |
| `vader fmt [path]`                             | partial | Opinionated formatter, no config. Written in Vader (`vader/fmt/`), dispatched through the VM. Flags: `--check` (read-only, exits 1 on drift), `--stdout` (single-file). Default rewrites in place. Idempotent and parse-equivalent; not yet a byte-for-byte no-op on the stdlib. |
| `vader test [path]`                            | ✓       | Discover and run `@test` functions under `[path]` (default cwd). Each runs as a separate VM entry; failures report message + source span. Name override: `@test("readable name") my_test :: fn() -> void { … }`. Exits non-zero on any failure.                            |
| `vader dump --stage=<stage> <file>`            | ✓       | Run the frontend up to `<stage>` and print the result (JSON or text).                                                                                                                                                                                                     |

### Global options

- `--diagnostics=text|json` — render diagnostics for terminals (default) or as a stable JSON schema for tooling.
- `--allow-env` — let `@comptime` code read process environment variables (gated to preserve build reproducibility).
- `--no-bytecode-opt` — disable bytecode peephole optimisations (on by default).

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

```sh
vader dump --stage=typed-ast examples/hello/hello.vader   # any stage above
vader build --target=ir      examples/hello/hello.vader   # → emits hello.vir alongside the source
```

### Build targets

| Target            | Output                                                              | Notes                                                                                                                |
|-------------------|---------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------|
| `--target=native` | A native executable **plus** the intermediate C source (`<out>.c`)  | Default. Invokes `cc` (auto-detected). Runtime lives at `runtime/c/`. The `.c` is kept so it can be inspected/profiled. |
| `--target=c`      | Just the generated C source                                         | Drive the C compiler yourself, or stash the C as a snapshot.                                                         |
| `--target=ir`     | Textual `.vir` bytecode                                             | Round-trippable: `vader run program.vir` re-executes without re-parsing.                                             |
| `--target=wasm`   | *(not yet implemented)*                                             | Direct WebAssembly emission with the WASM GC proposal. Deferred to post-MVP.                                         |

```sh
vader build foo.vader --target=native --out=/tmp/foo            # native binary + foo.c
vader build foo.vader --target=native --cc=clang --out=/tmp/foo # pick the C compiler (CC env var is a fallback)
```

**Cross-compile to Windows from macOS/Linux** — install [mingw-w64](https://www.mingw-w64.org/) (`brew install mingw-w64` / `apt install mingw-w64`), then point `vader build` at the cross-compiler. The `.exe` extension is added automatically when the triplet ends in `mingw32-gcc`:

```sh
vader build examples/hello/hello.vader --target=native --cc=x86_64-w64-mingw32-gcc --out=/tmp/hello-win
file /tmp/hello-win.exe          # → PE32+ executable (console) x86-64, for MS Windows
```

`std/process.spawn` works on Windows via `CreateProcess` + `CreatePipe` (ANSI argv via `CreateProcessA`; `CreateProcessW` / Unicode paths not yet wired).

---

## Editor support

A minimal VS Code extension lives under [`editors/vscode/`](./editors/vscode/) — syntax highlighting, comment toggling, bracket matching.

```sh
# Symlink into VS Code's extensions folder, then reload the window
ln -s "$PWD/editors/vscode" ~/.vscode/extensions/vader-0.1.0

# …or package it as a .vsix
npm install -g @vscode/vsce && cd editors/vscode && vsce package && code --install-extension vader-0.1.0.vsix
```

## Development

```sh
bun run test                               # full test suite (snapshots + CLI; wires up --parallel)
bun run test:update                        # refresh snapshots after intentional output changes
bun run bench                              # measure + compare to bench/baseline.json (exits non-zero on >15% regression)
RUN_FMT_TESTS=1 bun run test               # also exercise the Vader formatter end-to-end (slow, ~2 min)
```

Snapshot tests live under `tests/snapshots/<phase>/<scenario>/` (an `input.vader` + a `*.snap`); set `UPDATE_SNAPSHOTS=1` to regenerate, then `git diff` to review. Contributor conventions: the AST is never mutated (each phase produces side-tables keyed by node identity), every phase emits `Diagnostic`s rather than throwing (codes namespaced `L0`/`P1`/`R2`/`T3`/`C4`/`W0`), and a single midir backbone feeds the VM, the C emitter, and the future WASM emitter. The architecture is documented in [`SPEC.md` §2](./SPEC.md); house rules are in [`CLAUDE.md`](./CLAUDE.md).

---

## Roadmap

The live, item-by-item roadmap is in [`TODO.md`](./TODO.md). High-level milestones:

| Phase | Goal | Status |
|-------|------|--------|
| **0 — Bootstrap** | Project scaffold, test runner, CLI stub | ✓ done |
| **1 — MVP** | Full TypeScript pipeline: lexer → … → midir CFG/SSA → bytecode VM (`vader run`) + C emitter with a precise Cheney GC (`vader build`). Traits, tuples, typed enums, `@comptime`, `vader test`, `vader fmt`, and `std/` (io / string / math / collections / iter / sort / json / path / process / runtime / testing) all landed. | shipped |
| **2 — Self-hosting** | Port the compiler to Vader and reach the fixed point (the Vader-built compiler reproduces its own generated C byte-for-byte). The full pipeline is self-hosted, a committed C seed rebuilds the toolchain from a stock C compiler, and the legacy TypeScript `src/` has been retired. | ✓ done |
| **3 — Post-MVP** | WASM emitter (bytecode → WASM with GC types), concurrency, networking, richer editor support, multi-platform CI. | pending |

## Further reading

- [`SPEC.md`](./SPEC.md) — the language specification and compiler architecture
- [`TODO.md`](./TODO.md) — the implementation roadmap, item by item
- [`examples/`](./examples/) — working programs to play with
- [`stdlib/`](./stdlib/) — the (in-progress) standard library, written in Vader
- [`bench/`](./bench/README.md) — cross-language micro-benchmarks and methodology

## License

MIT — see [`LICENSE`](./LICENSE).
