# 0102: A match names its scrutinee with a declaration

## Status

Accepted (2026-10-20). Follows 0101, which took the binder out of `is` tests.

## Context

After 0101, `match e as x { … }` was the last place `as` bound a name. It is
worth keeping as a capability: it evaluates `e` once, names it for every arm and
guard, and its scope is the match, so it does not leak the way a `x :: e` written
before the `match` does. The spelling was the problem: the name comes after the
value, unlike every other declaration, and `as` is the keyword an `is` test no
longer accepts, which makes `is T as x ->` in an arm (P1037) look like a near miss.

Kotlin names a `when` subject the same way, with its declaration syntax:
`when (val x = e) { … }`.

## Decision

- **`match x :: e { … }`** names the scrutinee. `x` is visible in every arm and
  guard, holds `e` evaluated once, is narrowed by each arm, and goes out of scope
  with the match.
- **It is one constant name, typed as the scrutinee.** The header is parsed as a
  local declaration, so `match x := e`, `match x: T: e` and `match [a, b] :: e`
  are read, and diagnosed as P1039.
- **`match e as x` goes** once the tree has moved: the seed has to read the new
  form before the tree can be written in it.

## Consequences

- Once `match e as x` is gone, `as` binds a name nowhere in an expression: a
  value is named by a declaration, `::` or `:=`, written name first.
