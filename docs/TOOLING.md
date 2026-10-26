# Tooling

The `vader` command, its test runner, debugger and language server, and the diagnostics they report. The language is described in [`SPEC.md`](../SPEC.md), the compiler in [`ARCHITECTURE.md`](ARCHITECTURE.md).

## Command line

Every invocation is `vader <action> [options] [args]`.

- Options come before the first positional argument. What follows it goes where the action sends it: for `run` and `build --run`, to the program, verbatim, with no `--`.
- A bare `--` ends the options, for a path that starts with a dash.
- An unknown option, long or short, is an error.
- A flag's value follows `=` or a space.

`vader help <action>` or `vader <action> --help` (`-h`) lists an action's options, with their one-letter aliases and values; this guide gives the common ones. After the path of `vader run`, `--help` goes to the program.

### Actions

Each action has a section below, except `test` (*Tests*), `dap` (*Debugging*) and `lsp` (*Language server*); `help` prints the usage and `version` (`--version`, `-v`) the version. A `[path]` left out is the working directory.

### `vader new`

`vader new name` creates the folder `name` with `src/main.vader`, a `.gitignore` and what `--build` picks: a `vader.json` (`manifest`, the default), a `build.vader` (`driver`) or nothing, for a single program (`none`). Without a name, it fills the working directory.

`--git` also runs `git init`. On a terminal, `vader new` asks for what the command line leaves out; `--git=false` declines without a question.

### `vader run`

`vader run <path> [args...]` compiles a program and runs it on the VM, `args` being its argv. The path is:

- a `.vader` file, the entry of its program, with the search roots of the project `--project=<folder>` names;
- a project folder, which runs its entry;
- a `.virt` file, text bytecode, run as it is.

First, the default C compiler (*`vader build`*) compiles the adapters its `@extern` calls need (SPEC §13 *VM behaviour*) into a shared library, kept under `build/ffi/<fingerprint>/` of the project folder, or else the entry's, until one of its inputs changes. When they do not build, the program stops before it starts, naming an `@extern` that needs one. `vader test` and the debugger do the same.

### `vader build`

`vader build [path]` compiles a file or a project folder (*Projects*) to a native binary for this machine. A named file ignores the working directory's `build.vader`, saying so unless given `--no-hooks`, which every action accepts and only `vader build` reads. On a folder its `build.vader` describes, `--no-hooks` is refused.

`--emit` (`-e`) picks the output:

- `executable`, the default: a native binary, through C;
- `c`: the C only;
- `bytecode-text`: a text bytecode module (`.virt`) beside the input, for `vader run`;
- `bytecode`: a binary one (`.vir`) *(planned)*.

Other common options:

- `--out=<path>` (`-o`): the output path; `-` writes the C to standard output.
- `--release` (`-r`): optimises, and an integer overflow wraps instead of stopping the program (SPEC §4 *Integer overflow*); otherwise a build carries debug information.
- `--cc=<path>`: the C compiler, `$CC` by default, else `cc` (`gcc` on Windows).
- `--ldflags=<flags>`: linker flags, split on spaces.
- `--no-split`: one C translation unit instead of one per module.

The C goes to `c/` beside the binary and the object files to `obj/` (none under `--no-split`), named after it; both stay after the link, even a failed one. Each `CLibrary`'s calls (SPEC §13) get their own C file beside the program's, `<out>-_ffi_<name>.c`, except on standard output (`--out=-`, `vader dump --stage=c`).

**`--run`** then runs the binary on this process's standard streams, with what follows `[path]` as its argv, and exits with its code, or with 1 after reporting a signal (an exception, on Windows). It runs nothing after a failed build, and is refused unless the build makes an executable for this machine.

**Another platform.** `--target=<os>-<arch>` (`-t`) builds for the platform it names (SPEC §17), such as `linux-x86_64`.

- An executable needs a C compiler for it, named by `--cc`, `$CC` or `ctx.cc` in a `build.vader`, and taken to target it. Without one, a file or a `vader.json` project stops.
- `--emit=c` needs no C compiler.
- WebAssembly will be `--target=browser-wasm32` or `wasi-wasm32`, with `--emit=executable` *(planned)*.

`VADER_OPT_REPORT=1` prints on stderr where an optimisation fell back to its general path, without changing the program.

### `vader check` and `vader lint`

`vader check <path>` type-checks a file, or each entry of a project folder, emitting nothing. `--target` checks the `@target` bodies of another platform.

`vader lint <path>` runs the lints a build leaves out: the unused-export lint warns about an exported function no root of the project reaches.

### `vader fmt`

`vader fmt [path...]` formats in place the given files and, recursively, the `.vader` files under the given folders (`.` by default), in one style with no configuration.

- `--check` changes nothing, and exits with 1 when a file would change.
- `--stdout` writes one file's formatted text to standard output.

An empty modifier list is dropped: `import "p" {}` becomes `import "p"`.

### `vader graph`

`vader graph <path>` prints the module import graph in Mermaid (`--format=mermaid`, the default) or Graphviz (`--format=dot`). It draws the project's own modules, plus the library and toolchain ones under `--scope=all`.

### `vader doc`

`vader doc [path]` writes the data of an API reference for the modules under `path`, a folder or the file of a module: each export with its head and its vaderdoc, split by its tags. The data goes to the `build/doc/` of the project.

The modules are read as the project's build reads them, from its entry: the project is the working directory, or the folder `--project` names, which `path` defaults to, and its entry the only one of its `vader.json`, or the one `--entry` names. A project its `build.vader` describes is not supported yet. Without a project, only the toolchain's search roots are read, and the data goes to the working directory. A module these roots do not reach, or that another folder of the same name shadows, is named and left out, and a file that does not parse loses only what the parser could not recover.

The data is JSON, at `version` 1, a draft that may still change:

- `index.json` lists the `modules` (`path`, `files`) and every export in `entries`, with what a list shows of it: `id`, `module`, `name`, `kind`, `signature` and `summary`, the first sentence of its vaderdoc.
- `modules/<path>.json` holds one module whole. Each of its `decls` adds `file`, `line` and `doc`, null without a vaderdoc:

```json
{
  "id": "shapes/geometry/distance",
  "name": "distance",
  "kind": "fn",
  "signature": "export distance :: fn(a: Point, b: Point) -> f64",
  "file": "shapes/geometry/geometry.vader",
  "line": 22,
  "doc": {
    "summary": "The distance between `a` and `b`.",
    "prose": "The distance between `a` and `b`. Always positive or zero.",
    "params": [{ "name": "a", "text": "the first point." }, { "name": "b", "text": "the second point." }],
    "returns": ["the distance, in the unit of the points."],
    "errors": [],
    "example": "distance(o, Point { .x = 3.0, .y = 4.0 })   // 5.0"
  }
}
```

`kind` is `fn`, `struct`, `enum`, `trait`, `type` or `const`; an alias without type parameters (`Label :: string`) is still a `const`. `prose` is CommonMark, and `example` is shown as a reader sees it, its hidden `# ` lines left out.

### `vader dump`

`vader dump --stage=<stage> <path>` prints one stage of the pipeline ([`ARCHITECTURE.md`](ARCHITECTURE.md)). The stages, in order, are `lexer`, `ast`, `resolved-ast`, `typed-ast`, `callees`, `effects`, `evaluated-ast`, `lowered-ast`, `dced-ast`, `targets`, `cfg`, `ranges`, `bytecode`, `c` and `wasm` *(planned)*. `ast` prints JSON and `evaluated-ast` Markdown; `vader dump --help` says what each prints.

`--target`, `--entry`, `--project` and `--include-paths` work as for `run` and `build`.

### `vader eject`, `vader info` and `vader doctor`

`vader eject [path]` replaces a project folder's `vader.json` with the `build.vader` it stands for: the same search roots, entries and assets, in code, without its `name` and `version`.

- `--preserve-manifest` keeps the `vader.json`, to remove before the next build: a folder holding both is refused.
- A folder with `.vader` sources at its root is refused: move them into a folder such as `src/` first.

`vader info [path]` describes a project folder without building: its entries, search roots and assets, and which of `vader.json` and `build.vader` declares them. `--json` prints them in the shape of a `vader.json`, plus `kind` (`manifest` or `driver`) and `root`. Under `--no-driver-build`, a driven project whose driver is not compiled exits with 3.

`vader doctor` checks the toolchain (*Toolchain*), the C compiler `--cc` names, the working directory's `vader.json` and the environment (`$CC`, the collector's `VADER_GC_*` of [`RUNTIME.md`](RUNTIME.md) *Memory*), saying where it looked. It exits with 1 on a failed check, 0 on a warning. `--json` prints `{ "ok": ..., "checks": [...] }`, each check with its `name`, `status`, `summary` and `detail`.

### REPL *(planned)*

A bare `vader` will start an interactive mode on the VM; today it says it is not implemented and exits with 2.

## Projects

A project is a folder described by its `vader.json` or by its `build.vader` (SPEC §11 *Configuration: `vader.json`* and *Programmable build API*).

### The project of a command

A command works on a project only when given one:

- a folder handed to `build`, `run`, `check`, `dump`, `lint`, `graph`, `info` or `eject`;
- for `test` and `doctor`, the working directory, when it holds a `vader.json`;
- for `run`, `dump`, `lint` and `graph` given a file, the folder `--project=<folder>` names: the file is the entry and the project gives its search roots. A driven project is prepared first (*Build drivers*).

A file given without `--project` has no project, even inside a project folder. A folder holding both a `build.vader` and a `vader.json`, or neither, is refused, as is a malformed `vader.json` or one that declares no entry. The debugger and the language server find a file's project themselves (*The project of a file*).

### Entries and outputs

- `build` and `check` take every entry, or the one `--entry=<name>` names. A build stops at the first entry that fails; a check reports on all.
- `run`, `build --run`, `dump`, `lint` and `graph` take the only entry; with several, `--entry` names one.
- A build writes an entry's binary to `<folder>/build/<profile>-<target>/<name>`, as in `build/debug-darwin-arm64/myapp`: the profile is `debug`, or `release` under `--release`, and the target is the `--target` pair or the host's. `--out` places the binary elsewhere when one entry is built, and is an error with several.
- An executable build then copies each asset into the binary's folder, under its path relative to the project.

What a command writes for a project goes under `build/`, which the `.gitignore` of `vader new` covers:

- `<profile>-<target>/`: the binaries, their assets, `c/` and `obj/`;
- `generated/`: the modules a driver generates (SPEC §11 *Generated modules*);
- `driver/`: the compiled driver;
- `ffi/`: the VM's adapter libraries.

No compiled module is kept between invocations.

### Search roots

An import is searched in these roots, in order (SPEC §11 *Include paths*):

1. the entry's namespace;
2. the `--include-paths` roots;
3. the library root (*Toolchain*);
4. the project folder, then its `includePaths` or `ctx.include_paths`;
5. `lib/` in the working directory, when step 3 found none;
6. `build/generated/`, under the project folder or, without a project, the working directory.

A root of step 4 that starts with `$VADER_HOME` lies in the toolchain's folder, whether or not the variable is set.

### Build drivers

A `vader.json` project is built by a driver compiled into `vader`: nothing is compiled before the project. A `build.vader` is compiled, then run:

- compiled with the compiler's sources (*Toolchain*) and the command's `--cc` and `--ldflags`, for this machine whatever `--target` says;
- kept as `build/driver/driver`, and compiled again when `build.vader` or the `vader` binary changes or `build/driver/` is deleted;
- run as a child process, told where the toolchain is, and killed after ten minutes;
- under `info`, `run`, `dump`, `lint` and `graph`, its output goes to stderr, leaving stdout to the command.

`ctx.mode()` tells the driver which command runs it:

- `.Build`: `vader build`;
- `.Check`: `vader check`, up to the lowering;
- `.Prepare`: `run`, `dump`, `lint` and `graph`, up to the last generation round, after which the command works on the entry the driver chose;
- `.Describe`: `vader info`, which reads what the driver declares and writes no generated module.

## Toolchain

A toolchain is the `vader` binary and three folders, each looked for under `$VADER_HOME`, then beside the binary:

- `lib/`, the library root (SPEC §11 *Library root*), recognised by its `std/io/io.vader`;
- `runtime/c/`, the C runtime of native builds, recognised by its `vader.h`;
- the compiler's sources, which drivers are compiled with: `vader/` in a checkout of the compiler, `src/vader/` in a bundle.

Failing both, `lib/` and `runtime/c/` are looked for in the working directory, and the compiler's sources in the project folder. A bundle, `dist/vader-<os>-<arch>/`, holds the binary, the three folders and `third_party/`, and works from any directory.

## Tests

`vader test [path]` runs on the VM every `@test` function (SPEC §12) under the path, `.` by default.

```vader
module "main"

import "std/testing"

@test
test_addition :: fn() {
    assert_eq(1 + 1, 2)
}
```

- A test passes when it returns, and fails when it stops the program: a failed assertion, a `panic`, a run-time check (SPEC §2 *Run-time checks*).
- `std/testing`, not in the prelude, provides `assert`, `assert_eq`, `assert_ne`, `assert_close` and other assertions.
- Each module is compiled with its own imports, in the working directory's project: a test can fail where the program builds, when an impl it needs comes from a module only another module imports.
- It exits with 0 when every test passes, 1 when one fails, 2 when the path holds no `.vader` file or no test.

## Debugging

`vader dap` runs a Debug Adapter Protocol server on the VM, over standard input and output. It launches a `.vader` file, stops at breakpoints, steps in, over and out, shows the stack, scopes and variables with Vader names and values, evaluates hover expressions, and forwards the program's output as `output` events. VS Code starts it directly, IntelliJ through LSP4IJ.

The debugger finds and reads a file's project as the language server does (*The project of a file*), and prepares a driven one as `--project` does.

A native binary is debugged in C (lldb, gdb), where locals are compiler slots (`l0`, `t0`). A debug build's `#line` directives map the C back to the `.vader` lines; a `--release` build has none. WebAssembly debugging (DWARF, Chrome DevTools, wasmtime) is planned with its backend.

## Language server

`vader lsp` runs the language server, JSON-RPC over standard input and output, on the compiler's own front end. It publishes its diagnostics and serves:

- navigation: definition, type definition, implementation, references, highlights, call and type hierarchies, symbols, links on import paths;
- editing: completion, signature help, rename, formatting (as `vader fmt`), selection and folding ranges, code actions (`match` / `if` conversion, UFCS rewrites, organize imports);
- display: hover, semantic tokens, inlay hints.

`--library-root=<path>` adds a library root, searched before the project's.

The VS Code and IntelliJ extensions (`editors/vscode/`, `editors/intellij/`) start `vader lsp` from the configured `vader` binary or the one on `PATH`, and validate and complete a `vader.json` against `editors/common/vader.schema.json`.

### The project of a file

A file's project is the nearest folder above it holding a `vader.json` or a build driver (a `build.vader` declaring `module "build"`); the `vader.json` wins when there are both. A malformed `vader.json` is read as far as possible.

Only running a driver tells its search roots. For a driven project, the server:

- asks `vader info --json --no-driver-build` in the background, holding the project's diagnostics back until the first answer;
- never compiles the driver: one not compiled as it stands keeps the known roots (none at first), and the server says once that `vader build` compiles it;
- asks again when `build.vader` changes or a build compiles the driver, keeping the known roots until the answer.

The server reads open documents from the editor's buffer, also to list a module's files. A file never saved belongs to its folder's module, under the `module` line it declares. The server watches the workspace's `.vader` and `vader.json` files, and rereads one changed outside the editor once the editor reports it.

## Diagnostics

Every compiler phase reports its problems as diagnostics (*Output*). A diagnostic carries:

- a **severity**: `error`, `warning`, `info` or `hint`;
- a **code**, such as `T3001`, and its **message**, the same text wherever the code is reported;
- a **detail**, what this occurrence adds: types, names, counts;
- a **span**, the source range it points at.

There are no secondary spans, notes or suggested fixes yet; some details say how to fix the problem:

- Modifying a frozen value (`T3070`), or lending one to a function that modifies it (`T3072`), names the value, what modifies it down the calls, and the copy to modify instead (a name bound to it, or a `bytes()` view's `.clone()`).
- `x.f()`, whose `f` is in scope only through a namespace alias and accepts `x`, reports `T3078` instead of the generic member error, with the qualified call in its detail.

No phase stops at its first diagnostic.

### Output

The command line prints one line per diagnostic:

```
[file:line:col] severity[code] message: detail
```

- The file is relative to the working directory when under it.
- Lines and columns count from 1, columns in code points.
- Lines are sorted by file and position, duplicates printed once. Past 100 lines, a last line counts the others.
- On a terminal, the severity is coloured.

The language server sends the same diagnostics as JSON, with the protocol's UTF-16 columns.

### Code families

A code is the letter of the phase that reports it, then four digits:

- `L0xxx`: the lexer;
- `P1xxx`: the parser;
- `R2xxx`: the resolver;
- `T3xxx`: the type checker;
- `C4xxx`: compile-time evaluation;
- `M5xxx`: the lowering;
- `H6xxx`: the build driver, `build.vader` (SPEC §11);
- `I7xxx`: the IR self-checks that `vader build --verify` runs between passes: a malformed IR, always a compiler bug;
- `W0xxx`: a warning, from any phase, which does not fail the build.
