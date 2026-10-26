# 0077: The bounds of an integer type

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its fourth part: the static
facts of a range and the test `x in T`. Builds on 0075 and 0076.

**Amended by [0096](0096-a-narrowed-integer-is-a-value-of-its-range.md)
(2026-10-19)**: the open question below, settled by 0083 for the origin, is settled
again: a local takes its first value's range, so `acc := n * 1000` is a `0..=23000`
and `acc * 1_000_000` assigned to it is a compile error.

## Context

The charter gave every integer type three facts (`T.min`, `T.max`, `T.count`), a trait
`Interval` implemented by the compiler for each range, a test `x in T`, and a
conversion `try_from` written in Vader on that trait. Two things changed the picture.
A range borrows every impl of the integer it is held in (0075), so an `Interval` impl
for `Hour` would be `u8`'s: the compiler would have to answer `Hour.min()` itself,
recognising a member by its name. And 0076 made a test narrow, so `x in T` can carry a
value of an integer type into a range with no conversion at all.

## Decision

- **Intrinsics, not members.** `@min(T)` and `@max(T)` are values of `T`, written as
  literals by the lowering, like `@size_of(T)`: the bounds of a type are a question put
  to the compiler, and an `@` says so. No trait carries them; a generic over integers
  (a later part of the step) bounds its parameter by `Int`, which is enough to ask.
  `Range` was not available as a trait name: it is the value of `0..<n`.
- **No `count`.** On a contiguous set it is `@max(T) - @min(T) + 1`; a set with a hole
  (`char`) comes with the primitives as ranges.
- **`x in T` with a type on the right** is a bounds test, not a `Contains` call. Only
  the bounds the type of `x` does not already keep are tested, the code of `Hour(x)`
  reused; a test the type decides is a constant, `x` still evaluated. Where it holds,
  `x` is narrowed within `T`, an integer of a primitive type included: this is the
  bridge from an `i64` to an `Hour` that cannot stop the program. Where it fails, a
  range is narrowed past an end `T` covers; a primitive is not: past most `T` its
  values are two intervals, which a range does not carry.
- **Literal bounds narrow too.** `h in 0..<12` narrows as `h in (0..=11)` would, its
  test still the `Range`'s `contains`. A bound that is not an integer literal leaves
  the value form alone.
- **A comparison with `@min(T)` or `@max(T)`** narrows as the literal it stands for.
- **`try_from` is not provided.** `if n !in Day { return null }` narrows `n` for the rest
  of the block. The expression form (`Day.try_from(n) ?? …`) can return with the
  generics over integers if it is missed.
- **A narrowed read converts.** A slot of one integer read at a range held in another
  (`n: i32` read as an `Hour`, a `u8`) is read at its declared width and converted,
  as a narrowed union is cast, in a plain read, a field (a union's common one
  included), a captured cell and a closure's environment alike: the lowered program
  never reads a slot at another width.

## Consequences

- A type with no integer bounds is T3110, for `in` with a type and for `@min` / `@max`:
  an enum and `char` until they are ranges.
- `@max(u64)` is past `i64`: it is written as its bit pattern, and a comparison with it
  narrows nothing.
- A primitive narrowed by `in` is a range for the arithmetic that follows, as any
  range: after `if n !in Hour { return }` with `n: i64`, `acc := n * 1000` is an
  `i32`, and a later `acc * 1_000_000` overflows it where the unguarded code computed
  in `i64`. Writing `acc: i64` keeps the width. Whether a range narrowed from a
  primitive should keep that primitive as the base a `:=` takes is open. Amended by
  0083: it keeps it, `acc` is an `i64`.
- The charter's `wrap_next` reads `(x - @min(T) + 1) % (@max(T) - @min(T) + 1) + @min(T)`.
