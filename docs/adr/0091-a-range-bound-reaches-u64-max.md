# 0091: A range bound reaches `u64.max`

## Status

Accepted (2026-10-19). First phase of declaring the integers in `std/core` (P1): the
bounds exact on `i64.min..=u64.max`, decided by the user ("pour u64, il faut définir
le maximum représentable en vader dans les bornes"). Builds on 0075.

## Context

The compiler's intervals carry `i64` ends, and an end past `i64` was open: "past
every `i64`". A `u64` was `0..=i64.max` with an open upper end, which every reader
took for "no end": its greatest value was known only by name, a range could not be
written up to it (T3109), and none could reach past `i64.max` at all. Declaring
`u64 :: Int in 0..=18_446_744_073_709_551_615` needs that bound written and kept.

## Decision

- **An open upper end may be exact.** `Interval` keeps `i64` ends and an open flag
  for each; an open upper end now says how far past `i64.max` it lies (`hi_past`, 1
  to 2^63), or that it has no end (0, as every open end was). `u64` is
  `0..=u64.max` exactly.
- **Only the upper end reaches past `i64`.** A range reaching past `i64.max` holds no
  negative value, since no integer holds both; its least bound lies within `i64`. A
  least bound past `i64`, or a negative one beside a greatest past `i64`, is T3109. A
  range wholly past `i64.max` is left to the day it is needed.
- **Such a range computes in the integer it is held in.** The exact arithmetic of
  ranges stands on `i64`, which holds none of its values past `i64.max`: `r + 1`,
  `r / 2`, `-r` and a mutable local taking `r` are those of its `u64`, checked as
  any. A literal past `i64` beside a range is a `u64` too.
- **Readers that must be exact read it**: the inclusion, the join, the meet and the
  equality of intervals, a bound shown (`0..=18446744073709551615`), `@max`, a literal
  tested against a range, and the tests a conversion and `x in T` make. A test
  against an end past `i64` compares the `u64` it stands for, written as the bit
  pattern a `u64` constant carries.
- **Arithmetic still opens an end it pushes past `i64`**, with no end: an exact result
  past `i64` is no better known than before.
- **A narrowing keeps an exact end or does not narrow.** A test against a range
  reaching past `i64` narrows within its exact upper end (`x < r`, `x <= r`); what
  would be left past such an end, from a least value no `i64` carries, is not
  narrowed to (`x !in R` keeps `x`), and above `i64.max` a value is narrowed from
  `i64.max` itself. A comparison with a literal past `i64` narrows nothing.
- **Readers that only ask "past `i64`?" keep reading the open flag**: walking a type,
  a `match` covering one, `fn<T: Int>`, the range analysis of the IR.

## Consequences

- `Int in 0..=18_446_744_073_709_551_615` and `Int in 9_223_372_036_854_775_800..=
  9_223_372_036_854_775_810` are written, shown, tested and converted exactly.
- A conversion into such a range, and `x in` it, test the upper end past `i64`; an
  open end with no bound still holds every value past it.
