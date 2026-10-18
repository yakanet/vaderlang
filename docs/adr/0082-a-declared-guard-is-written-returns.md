# 0082 — A declared guard is written `@returns`

## Status

Accepted (2026-10-18). Renames the form of 0079; its contract is unchanged.

## Context

`@guard(cond)`, the form TypeScript's type guards suggested, reads as a condition
guarding the call: a function the caller may not reach unless `cond` holds. What it
states is the opposite direction. The function computes a `bool` and narrows nothing
itself; the caller's `if` narrows, from what the result means. The decorator states
that meaning: a postcondition on the result, true if and only if `cond`.

Naming the narrowing (`@narrows`) would name the caller's use rather than what is
written. `@recast` and `@convert` suggest a value converted, where narrowing changes
no bit. `@implies` states one direction where both are checked; `@tests` sits beside
`@test`.

## Decision

- **`@returns(cond)`**: the function returns the value of `cond`. It says the contract
  is about the result, and that it is an equality, both ways.
- **The postcondition of a function that returns only when `cond` holds**, the
  charter's `@asserts`, is written `@ensures(cond)`: nothing is asserted at run
  time, `cond` is what holds after a normal return.
- The diagnostics keep their codes (T3111 to T3113, P1014, P1032); their messages name
  `@returns`. The compiler's own notion of a guard (a predicate whose call narrows,
  inferred or declared) keeps its name.

## Consequences

- `@returns` sits beside the vaderdoc tag `@return`; one is a decorator on the
  declaration, the other a tag in a `///` comment.
- `@returns` and `@ensures` form one vocabulary of contract programming: what the
  result is, and what holds after it.
