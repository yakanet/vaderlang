# 0084: A match covers an integer type by its values

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its seventh part continued
(D10: "`match` exhaustive without `_` on a known range").

## Context

A `match` over an integer required a wildcard whatever its arms: `0..=11` and
`12..=23` over an `Hour` were T3013, "requires a wildcard arm". With ranges, the
values of the scrutinee are known, and a wildcard there only hides the next gap.

## Decision

- **The values of an integer type** are a list of intervals: one for a range or a
  primitive, two for `char` (the surrogates `0xD800..=0xDFFF` are no scalar value),
  through a distinct as through its backing.
- **Each unguarded literal or range arm takes its values**; a match is exhaustive
  once none is left. T3013 names the first values missing.
- **The integer variant of a union counts the same**, when it is the only one
  (`Hour | null`): once its values are taken, the variant is, as an `is Hour` would
  take it. With two integer variants a literal would not say which it covers, and
  each needs an `is`. A `null ->` arm takes `null`, as `is null` does.
- **An arm whose values are all taken already, or a wildcard after arms covering the
  type, is W0014.** Values out of the type are T3066's, not W0014's.
- **`u64` and `usize` keep needing `_`**: their values reach past `i64`, where no
  literal is written.

## Consequences

- The lowering already ends a `match` without a wildcard with a trap no value reaches.
- A guarded arm covers nothing, as for unions.
- A range or literal arm does not yet narrow its body to its values; `if h in 0..=11`
  does.
- Enums keep their own coverage by variant.
