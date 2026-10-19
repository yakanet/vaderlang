# 0083 — A narrowing changes no width

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its seventh part begun
(D15): the base a mutable local takes from a narrowed integer, left open by 0077.

**Superseded by [0096](0096-a-narrowed-integer-is-a-value-of-its-range.md)
(2026-10-19)**: a range has no origin; a narrowed integer is a value of its range, and
a local keeps its first value's range, so the overflow this record guarded against is
a compile error instead.

## Context

A mutable local takes the base of a range computed in place (0075): `n := h + 1` on
an `Hour` is an `i32`, an `i64` past it, so that `n` can take another value. A
primitive narrowed by `in` (0077) is a range for what follows, so the same rule
applied to it: after `if n !in Hour { return }` with `n: i64`, `acc := n * 1000` was
an `i32`, and a later `acc * 1_000_000` overflowed where the code without the test
computed in `i64`. Adding a test changed the width of a variable two lines below it.

## Decision

- **A range narrowed out of an integer type remembers it** (`RangeType.origin`): `n`
  past `n in Hour` is a `0..=23` from an `i64`. The origin is not part of the type;
  two ranges of one bounds are one type.
- **A mutable local takes the origin where it holds the range**: `acc := n * 1000`
  is an `i64`. A narrowing adds a fact; it changes no width. Where the origin does
  not hold the range (`b * 1000` with `b: u8` narrowed into `0..=10`), the rule of
  0075 applies: the narrowest of `i32`, `i64` holding it.
- **The origin travels**: through narrowing again, a guard's included, through an
  operation and the join of two paths (the narrowest integer type holding both
  origins, whatever their order), and through an immutable copy (`k :: n` keeps it).
- **A bitwise operation reads the origin too**, where it holds the range, rather
  than the integer the range is held in: `n << 8` past `n in Hour` stays an `i64`.
  Amended by 0085: the narrowed value is held in its origin as well, so no read of it
  converts.
- **A declared range keeps the rule of 0075**: `h + 1` on an `h: Hour` has no origin,
  and `next := h + 1` is an `i32`.

## Consequences

- `x := n` past `n in Hour` is an `i64`, not an `Hour`, as it would be without the
  test. A narrowed value stored into an `Hour` slot is still an `Hour`.
- A function whose result is inferred from a narrowed value hands its origin to its
  callers' mutable locals.
- When the primitives become ranges (the rest of this part), a primitive's origin is
  its own declaration.
