# 0144: A failure falls back through `else`

## Status

Accepted (2026-11-14). Amends the Decision of 0011.

## Context

0011 split the handling of errors and null in two: control flow through `if`
and `match`, "the only mechanism that can early-return the bad case", and
values through the combinators of `std/option`. `??` sat between the two: an
operator whose fallback could be `return`, `break` or `continue`, but which
saw `null` alone. An error had to be bound, tested, and returned in three
lines:

```vader
listener :: listen(address)
if listener is IOError {
    return listener
}
```

and a caller that wanted only the null wrote `f().or_null() ?? x`, two
mechanisms for one fallback.

## Decision

- **One operator, `else`, replaces `??`.** `left else fallback` evaluates
  `left` once and gives the fallback when `left` is a failure: `null`, or a
  value whose type is known to implement `Error`. The fallback is a value, a
  block, or `return` / `break` / `continue`. `??` leaves the language.
- **`else is T { ... }` handles one type**, and clauses chain on the same
  value: `f() else is NotFound { d } else { return null }`. A clause with
  nothing left to handle is an error, so is a bare `else` that leaves no
  value.
- **On a declaration, the clauses see the failure under the declared
  name**, `x :: f() else return x`, as a `match` header name does (0102).
- **It binds between the ranges and the comparisons**, as Swift's `??`
  does: `a else b + c` is `a else (b + c)`, `m[k] else false && ready` is
  `(m[k] else false) && ready`.
- **What sets it apart from the `?` 0011 removed: nothing is implicit.** The
  `return` and what it returns are written; nothing goes up to the caller
  that the line does not say.

## Consequences

The control-flow half of 0011 now has an expression form: a fallback can
leave the function. `if` and `match` stay for what a fallback does not say,
a case that does more than one thing per variant.

`else null` widens the result to `T | null` in one word, which 0011 called a
defect when an error value was at hand. It stays legal because the `null` is
written, a choice the reader sees.

A type parameter, a trait value or `any` may hold an error or not: a bare
`else` never handles them, `else is Error` does.

`std/option` loses its reason to exist: `or_null` is `else null`, `unwrap`
is `else panic(...)`, `or` is `else value`.
