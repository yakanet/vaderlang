# 0065: An ASCII string is indexed by its bytes

## Status

Accepted (2026-10-15). Amends 0061: an ASCII string is not walked.

## Context

Since 0061, `len`, `s[i]` and `s[lo..<hi]` are Vader functions of `std/core` that
walk the codepoints from the start of the string: `len` is O(n), `s[i]` O(i). Most
strings a program handles are ASCII, where a codepoint index is a byte offset, but
nothing told the walk so. Finding it out costs a pass over the bytes, the very
walk it would spare.

The runtime already reads every byte of a string once: when it interns the string,
to hash it.

## Decision

- An atom carries `VADER_ATOM_FLAG_ASCII` in its existing `flags` field when all its
  bytes are below 0x80. The flag is set where an atom is created (an owner intern, a
  slice, the comptime table at startup, the empty atom) and never on a lookup that
  finds an existing atom. A slice of an ASCII parent is ASCII without a scan.
- `std/core` exposes it as `is_ascii(s) -> bool`, an `@intrinsic`: natively
  `vader_string_is_ascii`, on the VM the register op `StringIsAscii`, which asks the
  host string.
- On an ASCII string, `len` returns the byte length, `s[i]` the byte at `i` and
  `s[lo..<hi]` the bytes of the range. Each tests the flag once, at its entry; the
  walks behind them do not test it.
- Rejected:
  - Storing the codepoint count on the atom. Each atom would grow from 32 to 40
    bytes, and either the runtime would carry a second UTF-8 decoder that has to
    agree with 0063, or Vader code would fill a cache lazily. It is the only option
    that helps a string that is not ASCII.
  - Computing the flag inside the hash loop. That loop runs on every intern,
    including the lookups that find an atom; a separate pass at creation leaves
    those untouched.
  - Writing the flag into the comptime table at codegen. A table emitted by an
    older compiler, the seed's among them, would lack it; the runtime derives the
    flag there as it derives the hash.
- The contract of `is_ascii` is its answer, not its cost. A backend whose strings
  carry no such flag implements it as a scan: correct, and slower on ASCII text.

## Consequences

- Measured on 2026-10-15, `--release`, 64 KB texts, alternated runs, against
  `bf648c56f` (native ×4000; the VM ×40, about 70 ms of which is compiling the
  program and building the text):

  | ASCII text | native | VM |
  |---|---|---|
  | `len` | 5.3 → 2.5 ms | 130 → 75 ms |
  | `s[i]` | 38.8 → 2.4 ms | 108 → 76 ms |
  | `s[lo..<hi]` | 38.6 → 2.6 ms | 103 → 77 ms |

  The native floor, about 2.4 ms, is building the text. Accented Latin and CJK text
  do not move: 0.97 to 1.02 natively, 0.98 to 0.99 on the VM over 80 rounds.
- `interp`, `split_join`, `wordfreq`, `wordcount`, `str_concat`, `string_builder`,
  `hashmap`, `map_iter`, `fmt_float`, `parse_float`, `shapes`, `binary_trees` and
  `sort_by`: 0.93 to 1.02, same output (`closures` swings from 21 to 45 ms between
  runs of either binary, whose C is the same). The VM benchmarks: 0.99 to 1.02.
  Self-compilation: 1.00 to 1.006, and both compilers emit the same C.
- `interp` gains nothing: its string opens with an emoji. A string that is not
  ASCII still walks; storing the count is the lever left if a benchmark calls for
  it.
- The flag costs one pass over the bytes of each new atom, and no memory.
