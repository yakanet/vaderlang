# 0085: A match arm narrows to its values

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its seventh part continued.
Follows 0084; amends 0083.

**Superseded in part by [0096](0096-a-narrowed-integer-is-a-value-of-its-range.md)
(2026-10-19)**: a narrowed range is no longer held in its origin; a read of it
converts to the range's storage.

## Context

0084 made a `match` over an integer type exhaustive by its values, but an arm did not
narrow its body: `match h { 1..=11 -> am(h) }` refused `am(h: Morning)` where
`if h in 1..=11 { am(h) }` accepted it. A `match` is a chain of such tests.

Narrowing the arms brought out three gaps, each older than the feature:

- A narrowed value was read at its range's narrowest width: a `u32` code point past
  `'A'..='Z'` was masked to a byte and added as one, in the stdlib's case mappings.
- A value of one integer width going into a slot of another (an `Hour` into an `i64`
  local, a `u8` branch beside an `i64` branch) was never converted. The C backend
  converts implicitly; the VM computes on 32 or 64 bits and stopped.
- A `char` literal beside a range kept its `char` type, where in any other integer
  context it stands for its code point: `b - '0'` past `'0'..='9'` was T3017.

## Decision

- **A literal, range or or-pattern arm narrows** the scrutinee to its values (the hull
  of an or-pattern's), through the same narrowing as `in`. The wildcard narrows to
  the values left when they are one interval. `char` and a distinct are not narrowed.
- **A narrowed range is held in its origin** where that holds it (0083): narrowing
  changes no width, of a local nor of the value's storage. A read converts nothing;
  the value converts when it goes into a slot of another integer. The origin belongs
  to the value, not to a type built from it: a range inside a container (`[n, n]`) or
  bound to a type parameter (`first([n, n])`) is held in its narrowest integer, so
  that every instance at one range shares one layout.
- **Every integer reaches its slot at the slot's width**: a `let`, a `return`, an
  argument, a field, an assignment, an array or tuple element, and each branch of a
  value `if` or `match`. The lowering converts where the widths differ; a literal
  the slot's integer holds becomes that integer's literal.
- **A `char` literal beside a range stands for its code point.**
- **Where paths join, a range goes into an integer path holding it** (`0..=9` beside
  an `i32` is an `i32`), rather than making a union of the two.

## Consequences

- A scrutinee read in its arms at another width is spilled once into a temporary
  (`__scrut`), which a plain local read did not need.
- The slot conversion removes casts of literals the earlier lowering kept (`u64(usize(4))`
  is `u64(4)`), and adds explicit widenings the C code had implicitly.
