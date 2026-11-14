# 0145: A build driver is a thin client that re-reads the sources

## Status

Accepted (2026-11-14). Its first step, the parser moving to `lib/toolchain`,
is in place; the protocol and the thin driver come next. What a driver is
handed, the AST as written or as the front end elaborated it, is still open.

## Context

A project's `build.vader` is compiled into a driver that runs the pipeline
itself: the driver imports `toolchain/build`, which imports `vader/pipeline`,
so every driver carries the whole compiler. That choice came from a dylib or
VM-hosted hook reading the AST under the numbering of another compilation
unit (type indices, atom ids, GC roots), with no error.

Measured on 2026-11-14, release `vader`, a quiet machine:

| What | Time |
|---|---|
| Debug driver from cold, "hello" project | 3.8 to 3.9 s |
| of which the front end over the compiler's sources | 1.3 s |
| of which `cc -O0 -g`, 71 units, 8 jobs | 1.5 s (10.4 to 11 s CPU) |
| Driver from its cache | 0.27 s |
| Release driver from cold | 10.3 s (52.8 s CPU) |
| Front end of the same project, debug driver against release `vader` | 3.28 s against 0.74 s |

A driver's cache key holds the hash of `vader`, so every new compiler rebuilds
every driver, and a debug build compiles the project with a `-O0` copy of the
compiler, 4.4 times slower than `vader` for the same work.

What drivers do in practice (the hook fixtures and `json/derive`): configure
entries, roots and assets; read the top-level declarations of a module;
report; emit generated modules. None modifies the AST, none calls the compiler
outside the pipeline.

## Decision

- **`vader` keeps the pipeline; a driver becomes a thin client** that talks to
  it over its standard input and output, in lock-step, one message at a time.
- **No AST crosses the process boundary.** The server sends the text of the
  files a driver has not read yet; the driver parses them with the same parser
  the compiler uses. Re-reading costs 0.03 s for a 3 700-line project and
  0.08 s for `lib/std` at `-O0`, less than a codec for the AST would.
- **The lexer, the parser and the diagnostics live in `lib/toolchain`**
  (`toolchain/lexer`, `toolchain/parser`, `toolchain/diagnostics`), next to
  `toolchain/ast` and `toolchain/span`, and import nothing from `vader/`. The
  diagnostics module keeps its renderer: a driver reports in the compiler's
  words. The dumps of tokens and syntax trees stay with `vader dump`, the only
  reader of their output.
- **Frames carry a length prefix.** A substitute driver with the parser builds
  from cold in 0.40 s (1.4 MB of C, 20 units). A round trip over a pipe costs
  30 microseconds either way, but a line-framed channel reads one byte per
  system call: 1 MB takes 280 ms against 0.47 ms with a length prefix.

## Consequences

A driver no longer depends on the compiler's binary: its cache key becomes the
hash of the project's build module and a fingerprint of `lib/toolchain`, and a
new `vader` rebuilds nothing.

The identity problem that ruled out a hook in another unit does not arise:
what crosses is source text, which has no numbering.

A plugin that needed the compiler's own data (types, symbols) has no access to
it. None does today; a typed view would be a message of the protocol.

The AST a driver reads today is not the one a re-read produces: the front end
fills in default and named arguments in place, completes `implements`
shorthands and copies members into empty impls, and drops the `@test` and
unreachable declarations of `lib/`. Which of the two a driver is handed is the
open question of the Status.
