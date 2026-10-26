# 0080: A generic instance at a range checks what it gets back

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its sixth part begun (D14):
the hole a range's borrowed impls open in generic code. Builds on 0075 and 0077.

## Context

A range borrows every impl of the integer it is held in (0075): `Hour` adds as `u8`
adds. Outside generic code that is harmless, since the member's `Self` is the impl's,
so `h.add(k)` is a `u8`. In a generic body it is not: `T` stands for the range, so
`bump :: fn<T: Add>(a: T, b: T) -> T = a + b` at two `Hour` 20 and 10 hands back
30, typed `Hour`. Every member that returns `Self` through such an impl can leave the
range: `Add` and the other operators, `Zero.zero` and `One.one` (0 is no `Month`),
`Step.step`.

The instance could not see it. Its substitution read every range as its integer, so
`bump` at `Hour` and at `u8` were one instance, and nothing in it knew the bounds.

## Decision

- **An instance at a range is its own.** A type argument that is a range, written
  (`Hour`) or bound to one by the enclosing instance (`T` in `bump<Hour>` calling
  `g<T>`), keeps the range: `bump<Hour>` and `bump<u8>` are two instances. The
  substitution still binds `T` to the integer, which is how the instance's types are
  read, and keeps the range beside it for its bounds. A range nested in an argument
  (`Hour[]`, `Box<Hour>`) is read as its integer, as before.
- **What a call or an operator hands back as a `T` bound to a range is checked**
  against it, as `Hour(x)` checks: the program stops outside. This covers an
  operator, a compound assignment, a static member (`T.zero()`), a method, and a
  consumer inlined at its call (`sum`). It does not tell a borrowed member from a
  generic fn of the same instance family; the second checks a value its own instance
  already checked, a test of one or two comparisons.

## Consequences

- A generic fn used at a range costs a body per range. Ranges are declared by the
  program, not by the stdlib; the duplication is bounded by what a program declares.
- An instance is named by the range's bounds (`bump__Int_in_0___23`), not its name:
  two ranges of one name and other bounds are two instances, two of the same bounds,
  named or not, one.
- A member returning `Self` inside another type (`Self | null`, `Self[]`) is not
  checked.
- The lowering keeps a range as a type argument as it keeps a primitive: the members
  of a generic struct at one (`Range<Hour>.contains`) are an instance of their own
  over the integer, not the body the erased instances share. The typecheck's view is
  unchanged: `x is Box<Hour>` still cannot be told from `Box<u8>` at run time.
- The body of `fn<T: Int>` (the bounds of `T`, arithmetic on it) is the next part.
