# 0146: A `for` walks the variants of an enum with variant data

## Status

Accepted (2026-11-14). Amends the Decision of 0087.

## Context

0087 left an enum with variant data out of every form that reads an enum as a
set of integers: `@min`, `@max`, `x in E`, `E(x)`, and `for x in E`. Such an
enum stores its variant's rank, not the value written after it, so those
forms would read something the program never wrote.

A walk reads no value. It visits the variants in declaration order, and the
ranks are exactly that order. Leaving it out meant a table built from the
data, such as the keyword texts the lexer's token kinds carry, had to list the
variants again by hand.

## Decision

- **`for x in E` walks an enum with variant data**, its variants in
  declaration order, as it does for any enum. The loop counts over the ranks.
- `@min`, `@max`, `x in E` and `E(x)` stay errors on such an enum.

## Consequences

A table derived from an enum's data can be folded with `@comptime` from a
walk. This lets `toolchain/lexer` derive `KEYWORDS` and the kinds
`lookup_keyword` searches from the `keyword` each keyword kind carries, the one
place it is written.

Measured on 2026-11-14 over the 416 507 identifiers of `lib/` and `vader/`,
on that derivation: searching the derived array costs the same as the `match`
it replaces in a native release build (6 ms for 20 passes), twice as much in
the VM (17.4 s against 8.1 s, a tenth of the time the VM takes to lex the
tree). A `Map` derived the same way costs 45 times more natively, from the
hashing.
