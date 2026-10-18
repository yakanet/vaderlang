# 0081 — A generic over integers computes in `i64`

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its sixth part completed
(D14): the body of `fn<T: Int>`. Builds on 0077 and 0080.

## Context

`Int` was accepted as a bound and meant nothing: `fn<T: Int>` took a `string`, and in
its body `@min(T)` and `x in T` were T3110, `a + b` T3017. The charter's examples,
`clamp_to` and `wrap_next`, need the bounds of `T` and arithmetic on its values.

Two ways to type the body were weighed. Checking it again for each `T` would apply
the expression rule (0075) exactly and prove `wrap_next` instance by instance, with
errors at the instantiation, as C++ reports them; it would make the typecheck
monomorphising for these bodies. Keeping `T` opaque and asking the body to prove
what it hands back keeps one typing, as every other generic has.

## Decision

- **`T` is opaque, and proves by writing.** A value of `T` is an integer of
  `@min(T)..=@max(T)`. `@min(T)` and `@max(T)` are values of `T`, folded per
  instance; `x in T` tests an integer against the bounds and narrows it to `T` where
  it holds; `T(x)` converts an integer, stopping the program outside as `Hour(x)`
  does. The instance knows its range (0080), or the primitive it stands for.
- **Computed in `i64`.** An operation on a value of `T` takes it as an `i64` and gives
  an `i64`; a comparison compares `i64` values. A `T` widens where an `i64` goes
  (`i64`, `i64 | null`), as a type parameter widens into the traits its bound
  names, and into no narrower slot. Getting a `T` back from a computation takes `in` or `T(…)`.
- **Within `i64`.** `T: Int` takes an integer type whose values are all `i64` values:
  a range or a primitive up to `i64`. `u64` and `usize` are T3006 with the rest: a
  value of them past `i64` would wrap silently where the body computes.
- **`Int` beside traits.** `T: Int & Display` reads both; `Int` names no trait, so a
  member of an integer's impl is reached through a trait the bound names.

## Consequences

- `clamp_to` is written with `in`, `wrap_next` with `T(…)`, as the charter has them.
- A `usize` length reaches a `fn<T: Int>` converted (`i64(n)`). Refusing it is the
  restrictive side of the choice: a check at the widening, stopping past `i64`, would
  admit it.
- A comparison on a value of `T` narrows nothing: its bounds are unknown to the body.
- `T(x)` and `x in T` cost one test per bound the source type does not keep, per
  instance, as for a named range.
