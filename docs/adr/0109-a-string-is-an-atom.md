# 0109: A string is an atom

## Status

Accepted (2026-05-25). Records a design the runtime already implements; written
2026-10-25 from the migration plan the decision was taken in, which this record
replaces.

## Context

`vader_string_t` was a fat pointer, `{ptr, len}`, 16 bytes. Each string allocated
at run time carried a header and lived in an arena of its own, beside the GC
heap, with its own mark and sweep. `==` compared bytes, and the hash walked them
at every lookup.

The compiler's own working set showed the cost. Profiling the type check of the
self-hosted compiler on 2026-05-25 gave 81 MB live, among which:

- 345 000 `Position` values, each holding a 16-byte `file: string` for about 200
  distinct paths;
- 510 000 `Token.text` strings for about 1 000 distinct identifiers.

For the carrier, two options were weighed:

- **An `Atom` type** for the fields that repeat (`Position.file`, `Token.text`,
  the names in the AST and the symbols): the gain where it is measured, but two
  string types in the language, and a conversion at every boundary.
- **Every `string` an atom**: one table for the program, and the carrier shrinks
  everywhere.

For freeing atoms, two schemes were rejected:

- reference counting: an increment and a decrement on every copy cost more than
  the smaller carrier saves;
- compacting the indices after a collection: every string in the heap would have
  to be rewritten.

A first version of the atom table returned the index itself as the hash. Indices
are handed out in sequence, so the hash clustered in the low bits, and the
iteration order of every map changed.

## Decision

- Every `string` is an atom: `vader_string_t` is a 32-bit index into one global
  table. Every string is looked up when it is created, so two strings with the
  same bytes have the same index.
- An atom either owns its bytes, in a buffer of its own followed by a NUL byte so
  that C reads them without a copy, or is a slice of an owner and copies nothing.
  Every slice has an atom for owner: nothing slices a buffer the table does not
  know.
- The compiler writes the program's string literals into a table in the binary,
  which the runtime loads at start-up. Those atoms are never collected.
- Atoms made at run time are collected with the heap, by its major collection. A
  freed index is reused by the next atom; indices are never compacted.
- The hash is computed from the bytes when the atom is created, and kept in the
  table, so the order in which a map iterates does not depend on which indices
  the table hands out, after a collection reuses some, or between the VM and a
  native build.
- The table has no lock: the runtime is single-threaded.

## Consequences

- A string is 4 bytes in a field or a local (an array of strings holds boxes).
  `==` compares two integers, and so does a `match` arm on a string literal.
- The string arena, its headers and its sweep were deleted from the runtime.
- Every string built at run time pays a lookup in the table. A miss copies the
  bytes of a new owner into a buffer; a slice copies nothing.
- An atom's bytes live outside the GC heap, and only a major collection frees
  them: a program that never runs a major keeps every atom it made.
- A slice keeps its whole owner alive: a token of the lexer keeps the bytes of
  its source file.
- No payload of a box needed 16 bytes any more. The box stayed at 24 bytes until
  [0018](0018-a-box-was-24-bytes-for-a-payload-nothing-writes.md) found it.
- The VM is a Vader program: its own strings are atoms of its process, with the
  same equality and the same hash as a native build.
