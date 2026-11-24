# 0178: The WIT type of an import is derived by the front end

## Status

Accepted (2026-11-23). Amends 0176 on where the WIT type comes from.

**Superseded by
[0179](0179-a-wit-interface-is-imported-as-a-module.md) (2026-11-24)**: the WIT
type of an import is its interface's, and an `@extern` written by hand cannot
name a `WasmInterface`; the derivation is gone.

## Context

Until now the WASM emitter derived the WIT type of an import from its bytecode
signature. That signature holds WASM value types only: an `i32` may be a `bool`,
a `char`, an enum or a string atom, and a reference says nothing of what it
points to. The first call to stdout needs more than scalars:

```
write-via-stream: func(data: stream<u8>) -> future<result<_, error-code>>
```

`stream<T>` and `future<T>` have no counterpart among the Vader types, and
`error-code` is an enum that the component must name as the interface names it.

## Decision

- **The WIT type is derived where the Vader types are whole**, when the CFG of an
  `@extern` naming a `WasmInterface` is built (`vader/midir/wit.vader`). The
  bytecode carries it (`BcImport.wit`), and the `.virt` text writes it as one
  attribute token. The emitter reads it and derives nothing.
- **Two generic structs of `std/core` spell the async types**: `WasmStream<T>
  { items: T[] }` for `stream<T>` and `WasmFuture<T> { value: T }` for
  `future<T>`. The call opens the stream, writes every item, closes it, then
  waits for the future: it is synchronous on the Vader side.
- **A type is named in WIT as in Vader, in kebab case**: `ErrorCode` is
  `error-code`, its variant `IllegalByteSequence` is `illegal-byte-sequence`. An
  enum maps when it has no variant data, its values are its ranks and it is
  stored in the unsigned integer the canonical ABI stores a case in, the
  narrowest that holds them: the bytecode keeps an enum as that integer and
  erases `void | E` to a reference, so the emitter boxes a case it reads back by
  that width alone; `void | E`
  is `result<_, E>`.
- **A type with no WIT form is kept as unsupported**, with its reason. The native
  build ignores it; a WASM build stops on it, naming the reason.

## Consequences

- A new module, `vader/core/wit`, holds the WIT types, their text and its reader,
  shared by the CFG builder, the bytecode, the `.virt` dump and reader, and the
  emitter.
- The WIT type is computed for every `@extern` naming an interface, on every
  target: a handful of declarations per program.
- Binding an interface's enum to a Vader enum is by name: a renamed variant breaks
  the import, as a renamed C symbol does.

## Set aside

- **The emitter recovering the Vader types** from the bytecode type table. The
  table erases what WIT needs (an enum's case names), and every later WIT type
  would add to it.
- **Decorators naming the WIT type** (`@wit("stream<u8>")`) on each parameter:
  text the compiler checks against nothing.
- **Dedicated types per interface** (`StdoutStream`): one per call shape, where
  two generic structs cover every interface.
