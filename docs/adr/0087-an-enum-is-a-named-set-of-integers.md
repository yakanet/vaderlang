# 0087 — An enum is a named set of integers

## Status

Accepted (2026-10-19). Step 7 of the type-system charter, its seventh part continued
(D10: enums as named ranges). Builds on 0077 (`@min`, `@max`, `x in T`) and 0075
(checked conversion).

## Context

An enum without variant data stores the value of each variant, written or counted
from zero: it is a set of integers with names. Nothing in the language said so. A
value read from a file or a wire had no way into an enum but a `match` listing every
variant; `@max(Weekday)` and `4 in Weekday` were T3110; `for d in Weekday` was T3088,
as was `for h in Hour` over a range.

## Decision

- **`@min(E)`, `@max(E)`** are the variants of the least and the greatest value.
- **`x in E`** tests an integer against the values. It narrows `x` as `x in lo..=hi`
  does where the values follow one another. An enum with a gap narrows nothing: on the
  false side a value may still lie between two values, and the narrowing would claim
  it lies outside them.
- **`E(x)`** converts an integer, checked as `Hour(x)` is: the program stops on any
  other value, in every build. A literal is checked where it is written (T3066). An
  integer type none of whose values is one of the enum's (`u64` into an enum of
  negative values) is T3010, as for a range; so is any other source, another enum
  included.
- **`for x in T`** walks a type: a range, an integer type within `i64` or a type
  parameter bounded by `Int`, its values upward; an enum, its variants in declaration
  order. A counter of the loop's own runs where the values follow one another upward,
  copied into the variable each turn, so that assigning the variable does not move
  the walk; an array of the values otherwise. The typecheck notes that the loop walks
  a type, and the lowering follows that note rather than the iterable's type: a value
  of an enum that implements `Into<Iterator<…>>` is iterated, not walked.
- **One mechanism tests a value against an integer type's values**: they are runs of
  consecutive integers, one for a range, one per stretch for an enum. Only the runs
  the value's own type reaches are tested, each cut to it, so the comparison happens
  in an integer holding the value: a `u64` against an enum of negative values compares
  nothing it cannot hold. A source inside one run, or outside all, decides the test
  at compile time.
- **An enum of no variant has no value**: `@min` and `@max` of it are T3110, `x in E`
  is `false`, `for` takes no turn, `E(x)` is T3010.
- **The enum stays nominal**: no arithmetic, no widening into an integer. It is a set
  of integers one names, not a range one computes in.
- **An enum with variant data is left out**: it stores its variant's rank, not the
  value, so none of the above reads what the program wrote.

## Consequences

- The forms reach an enum through a namespace (`M.Weekday(n)`) and a renamed import
  (`{ Weekday as Day }`), which `is_type_expr` now follows.
- `u64` and `usize` are not walked: their values reach past `i64`, where the
  compiler's bounds are not exact yet.
- `for b in u8` takes 256 turns; its last value is the counter's maximum, which the
  loop tests by a flag rather than `b <= 255`.
- A sparse enum's `E(x)` and `x in E` test one interval per run of values.
