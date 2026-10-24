# 0075 — An integer range is a type

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its first part: range types
(D10, D16) and the rule that types an operation on them (D15). The static facts of a
range (`T.min`, `x in T`, `Interval`), narrowing by a guard (D11) and the integer
primitives as ranges come later in the same step.

**Amended by [0096](0096-a-narrowed-integer-is-a-value-of-its-range.md)
(2026-10-19)**: a bitwise operation on a range of no machine integer's bounds is
refused rather than reading its integer, and a mutable local keeps the range of its
first value rather than taking a base.

## Context

The charter makes the integer types ranges of an abstract `Int`: `Hour :: Int in
0..=23` holds 24 values, is stored in a byte, widens into any integer holding it, and
an operation on it has the range of what it computes, so that `(h + 1) % 24` is
proven an `Hour` while `h + 1` is not. Before this, an integer was a name
(`PrimitiveType { name }`), no two widths mixed, and nothing in the types carried a
bound.

## Decision

- **A type of its own.** `RangeType { bounds, name }` is a new variant of `Type`.
  Two ranges are one type when their bounds are (a transparent refinement); `name`
  only shows the alias it was declared as. Bounds on `PrimitiveType` were weighed and
  set aside: a reader that ignores them takes `Hour` for a `u8` and accepts
  `h += 30` in silence, where a reader that does not know the new variant refuses it.
- **One interval domain.** The bounds are the interval domain the range analysis of
  midir already computed with (0058), moved to `vader/support/integer` so the typecheck shares
  it: `i64` ends, an end past them open. A declared bound is a literal within `i64`;
  the open end serves `u64`'s values and a result past 64 bits.
- **Held in the narrowest integer.** A range is stored in the narrowest of `u8`,
  `u16`, `u32`, `u64`, or of `i8`, `i16`, `i32`, `i64` when it has a negative value.
  The lowering reads every type through one accessor (`EntryTypes`), a struct's
  declared field types included, which replaces each range by that integer
  (`erase_ranges`): the lowering, midir and both backends see integers only. The integer types an operation involves then differ where a
  range took part (`a + b` on two `0..=200` is a `u16` sum of two `u8`), and the
  lowering computes it in an integer holding every one of them before holding the
  result as its own type: the bytecode reads an operation's width off its left
  operand.
- **Widening, one way.** A range goes into any range or integer holding it, a union
  through such a member included; never through a container or a function type, whose
  representation would differ; an integer never into a range without a conversion.
  The implicit conversion is value-preserving, so the lowering adds none at a slot.
- **The rule of an operation.** Between ranges and literals, `+ - * / %` and `-` are
  computed over the integers, a literal standing for its own value (`n..=n`), and the
  result is the range of every value they can take. A primitive operand absorbs the
  range, which must fit it, and the operation is the primitive's, checked as any
  (0054). A result past 64 bits is an `i64`. A bitwise operation reads a range as its
  integer. A mutable local takes the base of a range computed in place (`i32`, else
  `i64`), so it can take other values; a declared range is kept.
- **A checked conversion.** `Hour(x)` tests the bounds the source's type does not
  already keep and stops the program outside them, in every build: a value of a range
  is what its type promises, and the lowering after it trusts that. The stop is a
  `LoweredUnreachable` on the failing branch; a helper in `std/core` was set aside
  because the prelude cannot reach `panic`.

## Consequences

- `Int` is a builtin name that is no type of a value (T3108); a malformed range is
  T3109. A literal outside a range is T3066, a result outside its slot T3001.
- A range is its integer to every impl: its `Display`, `Equals` and `Hash` are its
  representation's, and a member returning `Self` through such an impl returns that
  integer.
- A free value that is not a literal or arithmetic on literals (an `if` of literals)
  takes its default width in a range slot, and is refused there.
- The range analysis of midir does not read a range's bounds yet; it reads the
  integer the range is held in.
- A literal into a union of several integers and ranges (`u8 | Hour`) is ambiguous
  (T3089).
