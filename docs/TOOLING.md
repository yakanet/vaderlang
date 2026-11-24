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

`vader new name` creates the folder `name` with `src/main.vader`, a `.gitignore` and what `--build` picks: a `vader.json` (`manifest`, the default), a `build.vader` (`driver`) or nothing, for a single program (`none`). Without a name, it fills the working directory. The project and its program take the folder's name, so a folder whose name cannot name a binary (SPEC §11 *Configuration: `vader.json`*) is refused.

`--git` also runs `git init`. On a terminal, `vader new` asks for what the command line leaves out: the folder (Enter takes this one), the build, `git init`. `--git=false` declines without a question.

### `vader run`

`vader run [path] [args...]` compiles a program and runs it on the VM, `args` being its argv. The path, the working directory by default, is:

- a `.vader` file, the entry of its program, within the project above it (*The project of a command*);
- a project folder, which runs its entry;
- a `.virt` file, text bytecode, run as it is.

First, the default C compiler (*`vader build`*) compiles the adapters its `@extern` calls need (SPEC §13 *VM behaviour*) into a shared library, kept under `build/ffi/<fingerprint>/` of the project folder, or else the entry's, until one of its inputs changes. When they do not build, the program stops before it starts, naming an `@extern` that needs one. `vader test` and the debugger do the same.

### `vader build`

`vader build [path]` compiles a file or a project folder (*Projects*) to a native binary for this machine. A named file is built within the project above it (*The project of a command*). A build ends with the programs it wrote, its profile and how long it took (`vader build: built `app` (debug) in 805 ms`). `--verbose` (`-v`) also prints each step of each program as it ends, with how long it took: the front end and its passes, the stages of the driver (what each took for its sources and its bodies), the lowering, the C and its units, `cc` and its objects, the link.

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

**`--run`** then runs the binary on this process's standard streams, with what follows `[path]` as its argv, and exits with its code, or with 1 after reporting a signal (an exception, on Windows). It runs nothing after a failed build, and is refused unless the build makes an executable for this machine. A `--target=wasi-wasm32` build runs under `wasmtime run` (51 or later, on `PATH`), the current folder lent to it as `.` and the environment inherited; a failed run exits with the host's code, 1 under wasmtime.

**Another platform.** `--target=<os>-<arch>` (`-t`) builds for the platform it names (SPEC §17), such as `linux-x86_64`.

- An executable needs a C compiler for it, named by `--cc`, `$CC` or `ctx.cc` in a `build.vader`, and taken to target it. Without one, a file or a `vader.json` project stops.
- `--emit=c` needs no C compiler.
- `--target=wasi-wasm32` writes a WebAssembly component, `main.wasm`, which `wasmtime run main.wasm` or `--run` runs, and needs no C compiler. The emitter translates part of the language so far, and names what stops a build. `browser-wasm32` is planned.

`VADER_OPT_REPORT=1` prints on stderr where an optimisation fell back to its general path, without changing the program.

### `vader check` and `vader lint`

`vader check [path]` type-checks a file, or each entry of a project folder, emitting nothing. `--target` checks the `@target` bodies of another platform.

`vader lint [path]` runs the lints a build leaves out: the unused-export lint warns about an exported function no root of the project reaches.

### `vader fmt`

`vader fmt [path...]` formats in place the given files and, recursively, the `.vader` files under the given folders (`.` by default), in one style with no configuration.

- `--check` changes nothing, and exits with 1 when a file would change.
- `--stdout` writes one file's formatted text to standard output.

An empty modifier list is dropped: `import "p" {}` becomes `import "p"`.

### `vader graph`

`vader graph [path]` prints the module import graph in Mermaid (`--format=mermaid`, the default) or Graphviz (`--format=dot`). It draws the project's own modules, plus the library and toolchain ones under `--scope=all`.

### `vader expand`

`vader expand [path]` prints the code the compiler writes for a file or a project, which no file holds: the wrappers of its interceptors, what a decorator such as `@displayable` adds. Each file opens with a line naming where `vader build` writes it (`// build/expanded/intercept/main.vader`). It only loads the project, so it prints that code even when it does not type-check, and leaves out the bodies body stages give once the comptime has run; the toolchain's own modules are left out too, except the modules of the WIT interfaces it ships that the load reads. `--entry` and `--include-paths` are `vader build`'s.

### `vader doc`

`vader doc [path]` writes the data of an API reference for the modules under `path`, a folder or the file of a module: each export with its head and its vaderdoc, split by its tags. The data goes to the `build/doc/` of the project.

The modules are read and type-checked as the project's build reads them, from its entry, without evaluating anything at compile time: the project is the one of `path` (*The project of a command*), which defaults to the project of the working directory, and its entry the only one it declares, or the one `--entry` names. A project its `build.vader` describes is prepared first, as for `vader run`. Without a project, only the toolchain's search roots are read, and the data goes to the working directory. A module these roots do not reach, or that another folder of the same name shadows, is named and left out, and a file that does not parse loses only what the parser could not recover.

Nothing is rewritten while the data is what the command would write: `build/doc/stamp` holds a key over the files the load read and their folders, the roots it searched, the entry, the path documented, the project's `vader.json` and the compiler. A file no load reaches changes nothing. A run that reports an error writes no stamp, so the next one reports it again; the modules a run leaves out follow from what the key covers, so the stamp keeps them and a run on data still up to date names them again. Deleting `build/doc/` forces a new run.

The data is JSON, at `version` 2, a draft that may still change:

- `index.json` lists the `modules` (`path`, `summary`, `files`) and, in `entries`, every export, impl and member with what a list shows of it: `id`, `module`, `name`, `kind`, the text of its `signature` and `summary`, the first sentence of its vaderdoc, and its `owner`: the id of the declaration a member belongs to, of the type an impl is for (empty for a type no declaration stands for, `T[]` or `string`), empty otherwise.
- `modules/<path>.json` holds one module whole: its `summary`, the `header` of its main file, its `files` and its `decls`. Each declaration adds `inferred_type`, `function`, `file`, `line` and `column` (of its name, of its first line for an impl, from 1, the column in codepoints), `doc` (null without a vaderdoc), `targets` and `members`:

```json
{
  "id": "shapes/text/Tag: Named",
  "name": "Tag: Named",
  "kind": "impl",
  "signature": [
    { "text": "Tag", "module": "shapes/text", "name": "Tag" },
    { "text": " implements " },
    { "text": "Named", "module": "shapes/text", "name": "Named" }
  ],
  "inferred_type": [],
  "function": null,
  "file": "shapes/text/text.vader",
  "line": 20,
  "column": 1,
  "doc": {
    "summary": "A tag is named by its text.",
    "prose": "A tag is named by its text.",
    "params": [],
    "returns": [],
    "errors": [],
    "example": []
  },
  "trait": "Named",
  "for": "Tag",
  "targets": [],
  "members": [
    {
      "id": "shapes/text/Tag: Named.name",
      "name": "name",
      "kind": "method",
      "signature": [{ "text": "name :: fn(self) -> string" }],
      "function": {
        "parameters": [{ "name": "self", "type": [] }],
        "return_type": [{ "text": "string" }],
        "return_inferred": true
      },
      "line": 22,
      "column": 5,
      "doc": {
        "summary": "The text of the tag, its return type left to inference.",
        "prose": "The text of the tag, its return type left to inference.",
        "params": [],
        "returns": [],
        "errors": [],
        "example": []
      }
    }
  ]
}
```

- `id` is `<module>/<name>`, `<module>/<name>~<n>` for the n-th declaration of an overloaded name, `<module>/<type>: <trait>` for an impl, and `<declaration>.<name>` for a member.
- `kind` is `fn`, `struct`, `enum`, `trait`, `type` (an alias, or a constant whose value is a type), `const` or `impl`; a member's is `field`, `variant` or `method`. A field restricted to its module (`@internal`) is left out.
- `signature` is the head as segments, whose texts, put end to end, give the head: each is `{ "text" }`, with the `module` and the `name` of the declaration it names when it is a name a reader can follow, a public function, type, trait or constant, a scalar type such as `i32` or `string` aside. A name reached through a namespace alias is one segment, `Geo.Point`.
- `inferred_type` is the type typing gave a constant without a written type, as segments too, empty otherwise. Only a struct, a trait, an enum or a distinct type links there: typing keeps no declaration for an alias, so an integer range such as `i32` shows its name without a link.
- `function` holds the `parameters` and the `return_type` of a function or a method, `null` for another declaration. Each parameter is `{ "name", "type" }`, its `type` as segments, empty when the head writes none (`self`), with its `default` as segments and `"variadic": true` when it has them. `return_type` is what it returns, written or inferred, empty when it is neither; `return_inferred` says typing gave it, the `signature` then ending with ` -> ` and that type.
- `targets` lists the platforms an `@target` group exists on, and is empty for a function that exists on every platform: one whose bare declaration has a body.
- `prose` is CommonMark, and `example` lists the lines of the example, each `{ "text" }` without the indentation the shown lines share; a line that sets the example up, written behind `# `, comes without it and with `"hidden": true`.

`vader doc --search=<query> [path]` shows what a query names, read the way `go doc` reads one. The data of the path, when there is a project or a path argument, and of the toolchain's library, in `build/doc-lib/` beside `build/doc/` with a stamp of its own, are brought up to date first; the path's modules hide the library's of the same name.

- A query is a module by the end of its path (`fs` for `std/fs`), an export, a member, joined by dots: `read_file_bytes`, `fs.read_file_bytes`, `IOError.kind`, `io.IOError.kind`. A lower-case letter matches either case.
- A lone name is a module, then an export, then a member. Before a dot, a name is a module, then a type.
- A module shows its header and the head of each export. An export or a member is shown whole, under the place it is declared at, `<file>:<line>:<column>`, named from the working directory when it lies under it and in full otherwise, which the terminal of an editor opens; an overloaded name shows each overload, and a method of an impl comes inside the impl's head.
- When nothing is named, the modules and the names that contain the query's last part are listed.
- On a terminal the text is coloured, unless `NO_COLOR` is set; a pipe or a file gets it plain.
- The exit code is 0 when something is shown or listed, 1 when nothing matches, 2 for an empty query or data that cannot be written. A project that cannot be read leaves the library to search alone.

```text
$ vader doc --search=point.x
module shapes/geometry  shapes/geometry/geometry.vader:12:5

x: f64
    The abscissa.
```

`vader doc -o <folder> [path]` brings the data up to date, then builds its site into the folder: a page per module, its declarations grouped by kind with their vaderdoc, links between them, and a search over all of them. The folder must be new, empty, or a site built before, which is replaced.

- The site is a SvelteKit project the toolchain ships as a template (`tools/doc-site/` in a checkout, `doc-template/` in a bundle), built with Node.js, which must be on the `PATH` at a version the `engines` of the template's `package.json` accepts.
- Its packages are installed once per version of the template in the user's cache (`~/Library/Caches/vader/` on macOS, `$XDG_CACHE_HOME/vader/` or `~/.cache/vader/` on Linux, `%LOCALAPPDATA%\vader\cache\` on Windows), with `npm`, which needs the network the first time. The template itself is never written to.
- `VADER_DOC_TITLE` names the site, `VADER_DOC_SOURCE_URL` is the prefix a file of the data is appended to for reading it online, `VADER_DOC_HOME_URL` the page its logo leads to when the reference is part of a larger site, and `BASE_PATH` the path it is served under (`/repo` for a project's GitHub Pages).
- The same data gives the same site, byte for byte, and a site already built from the same data and settings is not built again.
- The exit code is 0 once the site is written, 1 when its build fails, 2 when the folder holds other files or Node.js is missing.

`vader doc --open [path]` does the same into the user's cache, or into the folder `-o` names, then serves the site on `localhost` with `vite preview` and opens it in the browser (`BROWSER=none` keeps it closed, over SSH for one), until stopped with Ctrl-C.

### `vader dump`

`vader dump --stage=<stage> [path]` prints one stage of the pipeline ([`ARCHITECTURE.md`](ARCHITECTURE.md)). The stages, in order, are `lexer`, `ast`, `resolved-ast`, `typed-ast`, `callees`, `effects`, `evaluated-ast`, `lowered-ast`, `dced-ast`, `targets`, `cfg`, `ranges`, `bytecode`, `c`, `externs` and `wasm` *(planned)*. `ast` prints JSON and `evaluated-ast` Markdown; `vader dump --help` says what each prints. `externs` lists each `@extern` of the modules in scope, called or not, as the C prototype the compiler calls it through, to compare with the header of its library.

`--target`, `--entry` and `--include-paths` work as for `run` and `build`.

### `vader eject`, `vader info` and `vader doctor`

`vader eject [path]` replaces a project folder's `vader.json` with the `build.vader` it stands for: the same search roots, entries and assets, in code, without its `name` and `version`.

- `--preserve-manifest` keeps the `vader.json`, to remove before the next build: a folder holding both is refused.
- A folder with `.vader` sources at its root is refused: move them into a folder such as `src/` first.

`vader info [path]` describes a project folder without building: its entries, search roots and assets, and which of `vader.json` and `build.vader` declares them. Each path is shown absolute, marked `missing` when nothing is there, and a search root says whose modules its folder holds, `toolchain` or `project`; the output folder of each profile follows, then the source stages its `build.vader` plugs, in the order a load runs them, the compiler's own left out: each with the decorators it reads and writes, and `gives bodies` for one with a body stage of its name. `--json` prints them in the shape of a `vader.json`, with the `name` and `version` a `vader.json` gives, plus `kind` (`manifest` or `driver`), `root`, and `resolved`: each entry, search root and asset with its absolute `path` and `status` (`found` or `missing`), a found root with its `origin`, and the `output` folder of each profile; and `stages`, each with its `name`, the decorators it reads (`given`) and writes (`generates`), each a `decorator` and the `module` that declares it, none for the compiler's, and `bodies`, true for a stage with a body stage of its name. Under `--no-driver-build`, a driven project whose driver is not compiled exits with 3.

`vader doctor` checks the toolchain (*Toolchain*), the C compiler `--cc` names and the environment (`$CC`, the runtime's variables of [`RUNTIME.md`](RUNTIME.md)), saying where it looked; the project is `vader info`'s. It exits with 1 on a failed check, 0 on a warning. `--json` prints `{ "ok": ..., "checks": [...] }`, each check with its `name`, `status`, `summary` and `detail`.

### REPL *(planned)*

A bare `vader` will start an interactive mode on the VM; today it says it is not implemented and exits with 2.

## Projects

A project is a folder described by its `vader.json` or by its `build.vader` (SPEC §11 *Configuration: `vader.json`* and *Programmable build API*).

### The project of a command

A command works on the project its argument names, as an editor does. Without an argument, it is the working directory:

- a folder handed to `build`, `run`, `check`, `dump`, `lint`, `graph`, `expand`, `info` or `eject` is the project;
- a file, or the folder `test` and `doc` walk, belongs to the nearest project above it (*The project of a file*): the file is the entry and the project gives its search roots. A driven project is prepared first (*Build drivers*). The `build.vader` of a project is its driver, which belongs to no project.

Every command that compiles the path it is given takes `--include-paths=a,b`, search roots before every other.

A file with no project above it is compiled on its own. A folder holding both a `build.vader` and a `vader.json`, or neither, is refused, as is a malformed `vader.json` or one that declares no entry. The language server and the debugger refuse a project holding both alike.

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

A `vader.json` project is built by a driver compiled into `vader`: nothing is compiled before the project. A `build.vader` is compiled, then run as a process of its own, which `vader` serves the builds it configures:

- compiled with `lib/` alone and the command's `--cc` and `--ldflags`, for this machine whatever `--target` says, always without optimisation: the project is compiled by `vader`;
- kept as `build/driver/driver`, and compiled again when `build.vader` or `lib/toolchain/` changes or `build/driver/` is deleted; a new `vader` with the same `lib/toolchain/` reuses it;
- talks to `vader` over its standard input and output, so it does not run on its own;
- killed when it leaves `vader` waiting ten minutes for an answer;
- under `info`, `run`, `dump`, `lint` and `graph`, its output goes to stderr, leaving stdout to the command.
- the source stages it plugs run in it, during each load of a build, and so do its body stages; what they wrote is kept under `build/stages/`, which the commands that read the project once the driver is done (`run`, `test`, the language server) use, with a warning (H6016) for a stage whose files, or a body whose declarations, changed since the last build.

`ctx.mode()` tells the driver which command runs it:

- `.Build`: `vader build`;
- `.Check`: `vader check`, up to the lowering;
- `.Prepare`: `run`, `dump`, `lint` and `graph`, up to the last generation round, after which the command works on the entry the driver chose;
- `.Describe`: `vader info`, which reads what the driver declares and writes no generated module.

## Toolchain

A toolchain is the `vader` binary and two folders, each looked for under `$VADER_HOME`, then beside the binary:

- `lib/`, the library root (SPEC §11 *Library root*), recognised by its `std/io/io.vader`;
- `runtime/c/`, the C runtime of native builds, recognised by its `vader.h`.

Failing both, they are looked for in the working directory. A bundle, `dist/vader-<os>-<arch>/`, holds the binary, the two folders and `third_party/`, and works from any directory.

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
- A test exists for `vader test` alone: every other command reads a module without its tests and what only they use, so a build neither checks nor compiles them. The language server checks them, as `vader test` does.
- `std/testing`, not in the prelude, provides `assert`, `assert_eq`, `assert_ne`, `assert_close` and other assertions.
- Each module is compiled with its own imports, in the project above the path: a test can fail where the program builds, when an impl it needs comes from a module only another module imports.
- A project its `build.vader` describes is prepared first: the search roots its driver adds (`ctx.include_paths`) are searched, and the modules it generates read.
- Each test reports how long it ran, and the summary how long the command took.
- It exits with 0 when every test passes, 1 when one fails or the filter is not a glob, 2 when the path holds no `.vader` file, no test, or none the filter keeps.

`--filter` keeps the tests a glob matches (`std/glob`, POSIX notation, where `*` also matches `/`). The number of `:` decides what it is matched against:

```sh
vader test --filter 'test_min*' lib                       # no `:`: the module, the file or the name
vader test --filter 'std/iter:*' lib                      # one: <module>:<file>
vader test --filter '*:window.vader' lib                  # any module, this file
vader test --filter 'std/*:*:test_*_empty' lib            # two: <module>:<file>:<name>
vader test --filter 'test_min*' --filter 'test_max*' lib  # repeated: the tests one keeps
vader test --filter - lib < failed.txt                    # `-`: one filter per line of stdin
```

The module is the name its `module "..."` line declares, the file is its name without its folder. A glob with no wildcard is exact, and `\` quotes the character after it, a `:` included. A module that cannot hold a kept test is not compiled: discovery reads the name of each test from its declaration, without compiling, and compiles a module whose tests it cannot all name.

`--filter -` is how a tool passes many filters: a command line is limited in length (to 32,767 characters on Windows), stdin is not. A blank line holds no filter.

`--list` names the tests without running them, one per line, as the `--filter` that keeps it alone: `<module>:<file>:<name>`, each part quoted. It reads them from the source and compiles nothing: a module that does not type-check is listed all the same, only one that does not parse is reported.

`--reporter=json` reports for a tool, an editor's test view or a CI. The report is a JSON text sequence (RFC 7464, `jq --seq`): each event is an object on one line, after a record separator (RS, `0x1E`, written `<RS>` here).

```
<RS>{"event":"module","module":"main","path":"/home/me/app/main.vader"}
<RS>{"event":"start","module":"main","test":"test_addition","file":"/home/me/app/main.vader","line":6,"filter":"main:main.vader:test_addition"}
<RS>{"event":"pass","module":"main","test":"test_addition","duration_ms":0.021}
<RS>{"event":"summary","total":1,"pass":1,"fail":0,"duration_ms":31.2}
```

- `module` opens the tests of a module, compiled from `path`.
- `start` and, with `--list`, `test` say where a test is declared, and how to run it again: `file` is absolute, `line` is that of its name, `filter` is the `--filter` that keeps it alone.
- `pass` and `fail` give how long the test ran; `fail` adds the trap's `message`.
- `error` reports a module that did not run: it does not compile, or the VM refuses it. Its diagnostics stay on stderr.
- `summary` closes a run, not a list.
- Each event about a test names its `module` and its `test`: two modules may hold a test of one name.
- What a test writes arrives between its `start` and its result. A reader cuts on RS, so output without a final newline stays apart from the next event.

## Debugging

`vader dap` runs a Debug Adapter Protocol server on the VM, over standard input and output. It launches a `.vader` file, stops at breakpoints, steps in, over and out, shows the stack, scopes and variables with Vader names and values, evaluates hover expressions, and forwards the program's output as `output` events. VS Code starts it directly, IntelliJ through LSP4IJ.

Each task is a thread of the session, named `task #N` after `main`. Everything stops together, each thread shows its stack, and stepping moves only the thread that stopped: another one mid-step stops at its next line when it runs again. A trap in a task stops on the exception, then ends the session.

The debugger finds and reads a file's project as the language server does (*The project of a file*), and prepares a driven one as `vader run` does.

A native binary is debugged in C (lldb, gdb), where locals are compiler slots (`l0`, `t0`). A debug build's `#line` directives map the C back to the `.vader` lines; a `--release` build has none. WebAssembly debugging (DWARF, Chrome DevTools, wasmtime) is planned with its backend.

## Language server

`vader lsp` runs the language server, JSON-RPC over standard input and output, on the compiler's own front end. It publishes its diagnostics and serves:

- navigation: definition, type definition, implementation, references, highlights, call and type hierarchies, symbols, links on import paths;
- editing: completion, signature help, rename, formatting (as `vader fmt`), selection and folding ranges, code actions (`match` / `if` conversion, UFCS rewrites, organize imports);
- display: hover, semantic tokens, inlay hints;
- tests: a code lens above each `@test` runs it, and one on the `module` line runs every test of the module.
- interceptors: above an interceptor written on a function, one code lens leads to the declaration of its decorator and one to its `around` function.

`--library-root=<path>` adds a library root, searched before the project's.

The VS Code and IntelliJ extensions (`editors/vscode/`, `editors/intellij/`) start `vader lsp` from the configured `vader` binary or the one on `PATH`, and validate and complete a `vader.json` against `editors/common/vader.schema.json`. An interceptor's lens carries the command `vader.goTo`, which the server runs (`workspace/executeCommand`) by asking the client to show the declaration (`window/showDocument`): it needs no code in the editor. A test lens carries the command `vader.runTest`, which the editor runs, not the server: each extension runs `vader test --reporter=json <file>`, filtered to the lens's test, from the file's project (its folder, outside any). IntelliJ runs it as a temporary *Vader Test* run configuration, whose test console shows the tree of tests, their durations and output, goes to a test's line, and reruns the failed tests. VS Code runs it in its Test view, which lists the tests of a module when a file that holds one is opened or saved (`vader test --list --reporter=json <file>`), shows a failure on the test's line and keeps each test's output. Both rerun chosen tests with the `filter` of their events, written to `vader test --filter -`: one process per module, whatever the number of tests.

### The project of a file

A file's project is the nearest folder above it holding a `vader.json` or a build driver (a `build.vader` declaring `module "build"`). A project holding both decides no build: the server says so once and shows no diagnostic in it until one of the two goes. A malformed `vader.json` is read as far as possible.

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

A diagnostic in code the compiler wrote also leads to the code that asked for it: the function an interceptor wraps, the declaration a decorator such as `@displayable` writes for. There are no other secondary spans, notes or suggested fixes yet; some details say how to fix the problem:

- Modifying a frozen value (`T3070`), or lending one to a function that modifies it (`T3072`), names the value, what modifies it down the calls, and the copy to modify instead (a name bound to it, or a `bytes()` view's `.clone()`).
- `x.f()`, whose `f` is in scope only through a namespace alias and accepts `x`, reports `T3078` instead of the generic member error, with the qualified call in its detail.

No phase stops at its first diagnostic.

### Output

The command line prints one line per diagnostic:

```
[file:line:col] severity[code] message: detail
```

- The file is relative to the working directory when under it.
- A diagnostic in code the compiler wrote is followed by an indented line, `[file:line:col] the code ... writes for ...`, naming the code that asked for it. The language server shows it there, the detail saying where it was found.
- Code the compiler writes as source (an interceptor's wrappers, what a decorator such as `@displayable` adds) has no file of its own. `vader build` and `vader run` write it under `build/expanded/<writer>/` of the project folder, or else the entry's, named after the file or module it was written for, and a diagnostic in it names that file. The body a body stage gives goes beside the code of its module, one file per function: `build/expanded/<stage>/<module>.bodies/<Type>.<name>@<line>.vader`, the line being the one of its declaration in the stage's file. The module of an imported WIT interface goes to `build/expanded/wit/`; of the interfaces the toolchain ships, only those whose functions the program calls are written. Each such file opens with a line `// Generated by vader (<writer>) for ...: do not edit`. A build removes, under `build/expanded/`, the files that open so, were written for a file or a module it loaded, and that it no longer writes; a file it did not write, or written for another entry, stays. `vader check` writes nothing, and names the code `<generated>:<writer>:<origin>`.
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
