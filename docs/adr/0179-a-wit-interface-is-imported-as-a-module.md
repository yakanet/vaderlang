# 0179: A WIT interface is imported as a module

## Status

Accepted (2026-11-23). Amends 0178 on where the WIT type of an import comes from,
and on `WasmStream` / `WasmFuture`. Adds a point to the stages of 0156. Amended the
same day, before it landed: the WIT type of a function is the interface's, which the
build keeps, and no text on the declaration carries it. Amended 2026-11-24: a stream
or a future returned in a tuple has a form, an `async func` is lowered async, and
`system/wasi` comes back to read the handles.

## Context

A WASM build reaches its host through the interfaces of WASI 0.3 (0176). Until now
each function of an interface was declared by hand in `system/wasi`, an `@extern`
whose WIT type the front end derived from the Vader signature (0178). That held for
stdout and the clocks. `wasi:filesystem`, which `std/fs` needs, does not fit it:

- About 40 functions, a `variant error-code` of 37 cases, `flags`, `record`s with
  `option<instant>` fields, a `resource descriptor` whose methods take it as
  `borrow`, and `async func`s.
- The Vader signature does not say all of it: a struct of `bool` may be a `record`
  or `flags`, nothing tells `own` from `borrow`, and `async` is part of the type the
  host checks. Probed on 2026-11-23 under wasmtime 51: an import of `wait-for` typed
  `func` where the host has `async func` is refused at instantiation ("has the wrong
  type"); typed `async func` and lowered synchronously, the call blocks and returns.
- The interfaces `use` each other's types: `wasi:filesystem/types` takes `instant`
  from `wasi:clocks/system-clock`, `preopens` takes `descriptor` from `types`. WIT
  forbids cycles among packages and among interfaces.
- The component's import is typed per interface, and its named types are nominal.
  Probed by an adversarial review: an instance type that declares `descriptor` afresh
  in `preopens` instead of aliasing it from `types` validates but is refused by
  wasmtime ("resource implementation is missing"); one that leaves a variant
  unexported fails validation.
- `read-via-stream` returns `tuple<stream<u8>, future<result<_, error-code>>>`: the
  future resolves once the stream is read, so a call that waits for its future
  before returning, as `WasmFuture` does, never returns.
- A Vader union is flattened, deduplicated and sorted, and a union holding an enum
  carries the enum's integer as its tag. `result<string, string>` collapses to
  `string`, and two enums of one width cannot be told apart: `Fruit | Color` answers
  `is` true for both. SPEC.md makes such a union an error, which no check enforces
  yet.

WIT is an interface language meant for generating bindings: no preprocessor, no
platform-dependent layout. A C header is neither, which is why `@extern` stays
written by hand for C.

## Decision

### The WIT is the entry point

- `import "wasi:filesystem/types@0.3.0"` names an interface; the `:` sets it apart
  from a Vader module path. The version may be left out when one version of the
  package is reachable; every spelling resolves to the canonical name
  `ns:package/interface@version`, which is the module's name. Imports in `lib/` always
  write the version.
- WIT packages live under a `wit/` folder next to each root of modules (the
  library's, the project's, each include path), laid out by path:
  `wit/<namespace>/<package>@<version>/*.wit`, so that finding a package reads one
  folder and never walks. A name is one module, whoever imports it: a package the
  toolchain ships resolves there first, and another root holding the same name and
  version is an error naming both folders, so a project's own copy of a WASI package
  cannot change what `std` binds.
  The toolchain ships the WIT of the WASI release the target follows, `v0.3.0`, the one
  wasmtime 51 serves, in `runtime/wasi/<package>@<version>/` of `$VADER_HOME` with the
  licence of the WASI repository: an input of the WASM target, as `runtime/c/` is of the
  native one. That folder stands for the `wit/wasi/` of the library's root. The WIT reader follows `WIT.md` of the component model;
  `wasm-tools component wit --json` is the oracle of its tests, never a dependency.

### A stage of the compiler writes the module

- A new point joins the stages of 0156, the **module stage**: it says which import
  paths it serves (here every `ns:package/interface` form) and which files it reads,
  and returns the source of a module the build finds nowhere on disk. The engine
  reads the declared files for it, which makes them inputs of the build. The loader
  runs it while it resolves imports, before the source stages. The compiler
  registers its WIT stage as it registers `DisplayableStage`; a stage a driver plugs
  at this point is left for later.
- The module has a folder of its own that no disk holds, as the baked target does,
  and a mangling escape for `:` distinct from `/`: `:`, `@`, `.` and `-` become `_`
  and a digit, which no module path writes after a separator. Its source is written under
  `build/expanded/`, the library's interfaces included, under a file name every
  operating system accepts. Its spans stay in that file; a diagnostic in it names the
  `.wit` line it comes from as a related location, through a map from the generated
  ranges to the WIT spans.
- A `use` of another interface becomes an aliased import of that interface's module,
  so a WIT type has one Vader type, two interfaces can each have their
  `error-code`, and no wildcard import lets the prelude hide a generated name.

### What the module holds

- **One declaration per function**: an `@extern` naming the interface and the
  function, `@extern(WIT_INTERFACE, "[method]descriptor.stat")`, its parameters and
  result in the Vader types below. No wrapper: the emitter converts from the declared
  type. The module stays Vader as a person would write it, which the language server
  shows and `build/expanded/` holds.
- **The WIT type of an import is the interface's**: the module stage keeps the
  interfaces it read, the build hands them to the backend, and an `@extern` of a
  generated module takes the type of the function it names. Nothing checks the
  signature against the WIT: the compiler writes both from the same `.wit`, and the
  generator's tests pin what it writes.
- **The correspondence is known by construction**: the generator and the emitter
  name the Vader type of a WIT type, and tell whether an `ok` side is wrapped, with the
  same functions of `vader/core/wit`. The bytecode carries, per interface, the
  bytecode type of each named type its module declares; the emitter walks the WIT
  type and the bytecode type together, as it does for a list or a result, and takes a
  named type from that table. The same table gives the instance types their named
  types.
- **Binding a component goes through its WIT, and only through it.** The derivation
  of 0178 is retired with `system/wasi`, the last declarations written by hand; an
  `@extern` of a `WasmInterface` outside a generated module is then an error.
- **How a WIT type is held in Vader:**

  | WIT | Vader |
  |---|---|
  | scalars, `string` | as in 0178 |
  | `type t = T` | `@alias T :: ...` |
  | `list<T>` | `T[]` |
  | `option<T>` | `T \| null` |
  | `result<T, E>`, `result<_, E>` | `T \| E`, `void \| E` |
  | `result<T>`, `result` | `T \| WitFailure`, `void \| WitFailure` (`std/core`) |
  | `tuple<A, B>` | `(A, B)` |
  | `record` | struct, fields in snake case |
  | `enum` | enum, its width pinned to the case bytes of the canonical ABI |
  | `flags` | struct of `bool` |
  | `variant` without payloads | enum |
  | `variant` | `V :: VCase \| VName...`: an enum `VCase` of the cases without payload and one struct per case with one, holding it as `value` (`ErrorCodeOther { value: string \| null }`); the discriminant is the case's position in the WIT, mapped to the enum's rank or the struct |
  | `resource` | struct `{ handle: i32 }`; a method is a function taking it first, `[constructor]r` is `new_r`, `[static]r.f` is `r_f` |
  | `own`, `borrow` | the resource's struct |
  | `stream<T>` as a parameter of a `func` | `T[]`, written whole by the call |
  | `stream<T>` in a result | `WasmReadable<T>`, read by chunks, then dropped |
  | `future<T>` in a result | `WasmFuture<T>`, a handle the caller waits on |
  | `async func` | lowered async and waited for: the call blocks |

  `WasmStream` is retired; `WasmFuture` becomes a handle. A tuple of a result holds
  them as its elements (`read-via-stream` returns `[WasmReadable<u8>, WasmFuture<...>]`).
  `read` and `wait` of `system/wasi` read and wait for them, through two members of
  `Intrinsic` that only a WASM build serves.
- **Tags never collide.** Where the two sides of a `result` or an `option` would carry
  one run-time tag (`result<string, string>`, `result<descriptor-type, error-code>`,
  two enums of one width, `option<option<T>>`), the ok side is wrapped in a struct of
  its own, named after the function and `Ok`, so the error side keeps one type
  everywhere. The check is the one the front end applies to every union.
  Inside a named type, where no function names the struct, such a union has no
  Vader form yet.
- **Names.** Kebab case becomes snake case for functions and fields, Pascal case for
  types and cases. A name that is a Vader keyword takes a trailing `_` (`for_`), the
  implicit `self` of a method included. A type whose name the prelude holds is
  prefixed with its interface's name (`error` in `acme:kv/store` is `StoreError`).
  Two generated names that meet in one module are an error at the `.wit`. Methods
  follow the rules of the language: `d.stat()` under a wildcard import,
  `Fs.stat(d)` under an alias (T3078).
- A type a `result` of its package holds as its error implements `Error`, in the
  module that declares it (the orphan rule leaves no other), its message the WIT name
  of the case. WIT has no type of error of its own: an error is what a `result` holds
  on its error side.
- Items marked `@unstable` are left out.
- A function with no Vader form yet is left out of the module, a comment there naming
  it and why, so a call to it is an unknown name: `future<T>` as a parameter, a stream
  or a future inside another type than the tuple of a result,
  `stream<T>` as a parameter of an `async func` (the blocked caller could not write
  it), `error-context`. A named type with no Vader form yet is an error at the `.wit`
  line when a program imports the interface.

### Resources

- A resource's struct holds the index the host gave it. `drop` and passing it as
  `own` set the index to 0, which no handle has, and a call on 0 fails instead of
  reaching whatever resource the host gave that index next. Aliases share the struct,
  so all of them see it. Nothing finalizes: `std` closes explicitly. Copying a
  resource to another task is left to the tasks on WASM.

### The emitter

- **It implements the canonical ABI as its specification does**: the flat types,
  sizes and alignments, then a load and a store per WIT type constructor, each a
  helper made once per type and composed, guided by the correspondence table. A call
  passes its parameters flat up to 16 values, else through memory; its result flat
  when one value, else at a return address. No Vader code reads the linear memory:
  as for C, converting at the boundary is the compiler's work, done from the declared
  type.
- **It types the component's imports per interface**: each interface's instance type
  exports every named type it defines under its WIT name, a resource as
  `(sub resource)`; an interface that `use`s a type aliases it from the instance
  that defines it, which is imported first even when the program calls none of its
  functions; `resource.drop` and the built-ins of a stream or a future name those
  types. The bytecode module carries, per interface, the named types it defines.
- **One adapter is live at a time**: every lowering is synchronous and `run` holds
  the instance. The arena is taken back to the mark the call started from, and a call
  that leaves memory to the host passes the memory option. Tasks on WASM, which need
  asynchronous lowering, revisit this and the synchronous lowering of `async func`,
  which blocks the whole instance.
- A string lowered to the host is checked as UTF-8 first: an invalid one stops the
  run with a message naming the function, where the host would trap. `std/fs` checks
  a path before the call to return an `IOError` instead.
- **What it writes for itself is built as an expression tree**, flattened into
  instructions, as the C emitter builds a C tree (`vader/emit/c/ast`): one node per
  operation of the algorithm, not one line per instruction.

### Targets and running

- A WIT import is allowed on every target, so a library imports it without condition.
  A WIT function still reached in a build for another target, after the backend
  prunes what nothing calls, is an error naming the function and its caller. `std`
  keeps those calls in its `@target(.Wasi)` bodies.
- `vader build --run` runs a `wasi-wasm32` build under wasmtime (`-S p3`), the current
  folder preopened, the environment inherited, the exit code passed on. A component
  importing other interfaces than WASI's needs them supplied (`wasm-tools compose`),
  which `--run` does not do.

## Consequences

- `system/wasi` loses its declarations; `std/io`, `std/time`, `std/env` and `std/fs`
  import WASI interfaces like any module, and the wiring of `get-arguments` in the emitter goes.
- The language gains a form of import, which SPEC.md describes.
- Every build reads and generates the WIT interfaces `std` imports, a native one
  included, and the language server on each analysis. Measured before `std` switches
  to them; a cache by content follows if it shows.
- A function of an interface is no root of the dead-code prune: a build imports
  only the ones the program calls, and writes under `build/expanded/wit/` the
  module of a shipped interface only when it calls one of its functions. The
  interfaces `std` imports for WASI leave nothing in a native build.
- The language server watches `**/*.wit`. Before a first build, go-to-definition into
  an interface has no file to open.
- The generator joins the contract of the seed: a rule `std` relies on (a name, a
  shape) is frozen until the next seed. `docs/BOOTSTRAP.md` lists it among the
  changes that take a new seed, and the generator lands before `std` uses it.
- Every string the host hands back becomes an atom that is never freed (0175):
  listings and environments add up over a long run.
- A project or a library binds a component of its own with nothing but its WIT.

## Set aside

- **A WIT text on each `@extern`, checked by the front end against the signature,
  with a table per WIT node in the bytecode** (this ADR as first accepted): the
  compiler writes the text and the signature from the same `.wit`, so the check
  compares the generator with itself, the qualified text runs past 300 columns on a
  method of `descriptor`, and the table per node repeats what the names already say.

- **Deriving the WIT type from the Vader signature (0178) with marker types**
  (`WasmFlags`, `WasmBorrow<T>`, an `async` field): each ambiguity resolved by a type
  that exists only for it, and nothing compared with the real interface. 0178 set
  aside a WIT text on the declaration as "text the compiler checks against nothing";
  generated from the interface and checked against the signature, it is neither.
- **A source stage given a `@wit` constant in a module written per interface**: one
  hand-written file per interface, a path convention and a table of exceptions to map
  a `use` to a module, all of which the WIT name of the import makes useless. A source
  stage writes into a module that exists; an interface has none.
- **The loader writing the module itself**: the same work outside the stages, with
  its inputs unknown to the build.
- **Indexing packages by their `package` line**: a walk of every root on every
  import, which lazy resolution exists to avoid.
- **Generated bindings committed to the tree**: a second copy of the WIT that can
  drift, and a step to remember.
- **The canonical ABI written in Vader**, in a runtime module and in glue the
  generator writes: it needs intrinsics reading and writing the linear memory, which
  no Vader code needs for C either.
- **A wrapper per function** over a raw import: twice the declarations, and nothing
  for it to do that the adapter does not do for every function.
- **One struct per case of a `variant`**, payloads or not: an allocation per value
  and an `is` per case, where an enum serves the cases without payload.
- **The handle in a shared cell**: aliases share the struct already, and a deep copy
  would copy the cell too.
- **An exception to T3078 for WIT modules**, letting an alias feed UFCS: a rule of
  the language bent for one kind of module.
- **The `component-model-gc` option of wasmtime**, under which strings, lists and
  records cross as GC objects and the linear memory goes: experimental, behind a flag
  a plain `wasmtime run` does not pass. To reconsider when it is standard.
