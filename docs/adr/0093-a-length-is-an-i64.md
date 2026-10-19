# 0093 — A length is an i64

## Status

Accepted (2026-10-19). Replaces the portable `usize` / `isize` rule planned for the
integers declared in `std/core` (0092): the user chose `i64` over `i32` and over a
target-width `usize`. First of two steps; the second removes `usize` and `isize`.

## Context

`usize` was the type of every length, index and size: `len()`, `byte_len()`,
`@size_of(T)`, the index of `Index`, the counters of the standard library. Its width
is the target's, so a program checked on a 64-bit host could fail on a 32-bit one,
and a portable rule for it would have to hold two sets of values per type (what it
takes on every target, what it may hold on one). It also cost conversions: the tree
wrote 763 `usize(…)`, 109 `i32(xs.len())` and 41 `i64(xs.len())`, since an `i32`,
signed, never goes into a `usize`. Nothing in the language needs an integer whose
width varies: only C does, at the foreign boundary (`size_t`, `ssize_t`).

## Decision

- **A length, an index and a size are an `i64`, on every target.** `len()`,
  `byte_len()`, `@size_of`, `@align_of`, `@field_count`, `@variant_count`,
  `@field_index`, `Field.offset`, and the counts and offsets of the standard
  library. Array indexing takes any integer type; an index outside the array stops
  the run, a negative one included.
- **`usize` and `isize` stay, for now, the pointer-width words of the foreign
  boundary**: an `@extern` without a header whose C prototype has `size_t`, the
  integer a `CPointer` is read as, a word lent where C wants a `char**` or a
  `HANDLE*`. The next step gives each of these another form and removes both.

## Consequences

- The compiler compiles itself in the same time (`dump --stage=c` on the compiler,
  2.820 s against 2.820 s, instructions +0.35 %; `check` 1.405 s against 1.410 s,
  instructions equal; 12 alternated runs each, 2026-10-19).
- Generated code: 13 of 14 index-heavy benchmarks are level or faster (`arr_set`
  −6.5 %, `str_concat` −5 %). `quicksort` is 8 % slower (39.8 ms against 42.9 ms):
  its partition loop indexes with signed integers, and the C compiler drops the
  bounds check of `j` from `j < hh` and the check of `hh` before the loop only when
  `j` cannot be negative. The same program with `u64` indexes runs as before. What
  gives that knowledge back is a type that says a value is not negative: an unsigned
  integer, or a range (0075) held in one.
- `xs.len() - 1` on an empty array is `-1` rather than a trap; it traps when it
  indexes.
- A count, an offset or a slice bound can now be negative without a conversion
  written. It counts as 0, on the VM as in a native build: `[x] * n` is empty,
  `xs[lo..<hi]` starts at the first element, `copy_to` copies nothing. The VM read
  it so already; the C runtime took it as a `size_t` and read a huge value, so it
  now takes an `int64_t` and clamps it.
- `x in lo..<hi` over a literal range is two comparisons whatever `x` is, a value
  that is no name being read once into a local: the bounds tests the change wrote
  (`i64(x) in 0..<n`) allocated a `Range` and called `contains` otherwise.
- `usize(x) < n` was a one-comparison test of `0 <= x < n`, the conversion wrapping a
  negative `x` past `n`. With `i64` it is written `x in 0..<n`.
- A foreign function declared without its header synthesises its prototype from the
  Vader signature, so an `i64` where C has `size_t` conflicts with the system
  header (`strlen`). Such a declaration keeps `usize` until the next step decides
  how a foreign word is spelled.
