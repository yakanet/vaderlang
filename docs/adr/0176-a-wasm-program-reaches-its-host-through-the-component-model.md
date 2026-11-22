# 0176: A WASM program reaches its host through the component model

## Status

Accepted (2026-11-22). Follows 0175.

## Context

WASI has had three generations. Preview 1 is a set of plain core imports, the
simplest to emit and the only form Node runs, but frozen. 0.2 (2024) is built on
the component model: a core module wrapped in a component typed by WIT, its values
crossing through the canonical ABI. 0.3, ratified on 2026-06-11, adds native async
to that ABI (`async func`, `stream<T>`, `future<T>`).

Probed on 2026-11-22 with hand-written WAT, wasmtime 51.0.0 and wasm-tools
1.263.0, against the WIT of the WASI `v0.3.0` release:

- A core module using Wasm GC (0175) wrapped in a component runs under wasmtime.
- A hello whose core module is written by hand (817 bytes, 2 929 once wrapped by
  `wasm-tools component new`) runs under `wasmtime run` with no flag. It writes to
  stdout through `stream<u8>`. `run`, an `async func` in the WIT, may be lifted
  synchronously and still wait on a waitable set. A synchronous `stream.write`
  needs an optional feature ("more async builtins"); the standard form is
  `async`, which returns `BLOCKED` and signals completion through the set.
- `wit-component` breaks a circle there with two extra modules and a table of
  `funcref`: a built-in that names the memory cannot exist before the instance
  that exports the memory, and that instance imports the built-in.

## Decision

- **The component model, WASI 0.3**, for `wasi-wasm32`. The encoder writes the
  component around the core module, and an `@extern` becomes an import of it.
- **For `browser-wasm32`**, which neither browsers nor Node run as a component,
  the choice between a component translated by `jco` and a core module with JS
  imports is left to that target. The core module is the same in both.
- **`wasm-opt` runs on the core module before it is wrapped**: it does not read
  components. Closed-world holds, since values cross the component boundary
  through linear memory only.

Set aside: **WASI preview 1**, frozen.

## Consequences

- The canonical ABI passes values through linear memory, so a module under Wasm
  GC still keeps a small linear memory and a real `cabi_realloc`, and copies a
  `string` or a `list<string>` from the host into GC strings. wasmtime has an
  experimental `component-model-gc` option that may remove the transit later.
- The encoder writes instance types, imports, aliases, `canon lift` and `canon
  lower`, and the canonical built-ins. Defining the memory in a small core module
  instantiated first breaks the circle above without the extra modules.
