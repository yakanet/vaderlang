# 0092 — A machine integer is a range

## Status

Accepted (2026-10-19). Second phase of declaring the integers in `std/core` (P2): the
typecheck holds `i32` as a range, as decided by the user ("RangeType partout", against
keeping the primitive as its canonical form). Builds on 0075 and 0091.

**Completed (2026-10-19)**: no type holds an integer as a primitive any more, in the
typecheck or after it. The equality bridge of the last decision is gone; a machine
integer still keys by its name (`canonical_key`, the impl tables), as the primitive
did. What a value of an integer type is stored in is a machine integer of
`vader/support/integer` (`integer_representation`), not a type.

## Context

Since 0075 an integer is a range of `Int`, and `i8`, `i16`, `i32`, `i64`, `u8`,
`u16`, `u32`, `u64` were said to be the ranges of their values, but the typecheck
held them as primitives, apart from ranges: `Int in 0..=255` was no `u8`, and its
arithmetic was exact where a `u8`'s is closed. Declaring
`u8 :: Int in 0..=255` in `std/core` needs a range of those bounds to be a `u8`.

## Decision

- **A machine integer is the range of its values.** The type a name `i32` gives is
  the range `Int in -2_147_483_648..=2_147_483_647`, under its name. A range of those
  bounds is that integer whatever its name: `Octet :: Int in 0..=255` is a `u8`.
- **Its rules are told by its bounds, not by its name.** A machine integer's
  arithmetic is closed and checked; a comparison does not narrow it; `T(x)` into it
  is a width conversion. Any other range keeps the exact arithmetic, the narrowing
  and the checked conversion of 0075 and 0076. `x in T` narrows both.
- **An integer type written alone is a distinct type** (`Meters :: i64`), as a
  primitive was; under `@comptime` a transparent alias.
- **`usize` and `isize` stay primitives**: their width is the target's.
- **The typecheck tells the two forms apart nowhere.** A range of machine bounds and
  the primitive of that name are equal, show alike, key alike (`canonical_key`, the
  impl tables) and are held in the same width, so a primitive the typecheck still
  builds (the integer a range is held in, an enum's width) mixes with a range. The
  lowering reads every range as the primitive it is held in (`erase_ranges`), a
  free literal's default and a signature it reads from the typecheck's tables
  included.

## Consequences

- A range written over a machine integer's values changes meaning: `o + 1` on an
  `Octet` is checked at `u8` rather than computed as `1..=256`, and so does a range
  an operation computes when its bounds happen to be a machine integer's.
- `u64` and `Int in 0..=u64.max` are one type, which `usize` is not.
- The compiler's own C and typecheck are unchanged by it.
- Compiling the compiler takes about 2 % longer (2.575 s to 2.63 s for
  `dump --stage=c` on the compiler, 1.241 s to 1.261 s for `check`, measured on
  2026-10-19). The passes run level under the profiler: the cost is the
  collector's. The typecheck's share is that of a range, larger than a primitive;
  the lowering's, that `erase_ranges` rebuilds every composite type holding a
  machine integer (`i32[]`, `fn(i32) -> i32`) at each read, a copy the lowered tree
  keeps.
- Neither share was bought back here. Memoizing the erasure on a type node is
  carried by every spread that rebuilds one (`FnType { ...t, .params = … }`), onto a
  type it no longer describes. Letting a nested machine integer through the
  erasure gives the lowering two forms of one integer. Holding a nested one as a
  primitive in the typecheck goes back on the decision above. The way out is for the
  lowering to keep the typecheck's types and ask a width only where it stores a
  value: a type is not its storage.
- The typecheck still builds primitives for the eight in places; a later phase of
  the work removes them and the equality bridge with them.
