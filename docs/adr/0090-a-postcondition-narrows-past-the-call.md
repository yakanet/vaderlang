# 0090: A postcondition narrows past the call

## Status

Accepted (2026-10-19). Step 7 of the type-system charter, its fifth part completed
(`@asserts` in the charter, named `@ensures` by 0082). Builds on 0079 (the declared
guard) and 0082.

## Context

A function that validates its argument and stops the program otherwise
(`require_hour(n)`) tells its caller something once it returns: the argument is
valid. Nothing let the caller use it. A `@returns` guard narrows only where its
`bool` is tested, which such a function has no use for, and the caller had to test
the value again or convert it.

## Decision

- **`@ensures(cond)`** on a free function, `cond` one condition over its parameters,
  resolved in their scope: once the function has returned normally, `cond` holds.
  The function may return any type.
- **What it proves** is what the narrowing machine gives `cond` on its true side, for
  each parameter. **A call written as a statement, or as the value a `let` binds**,
  narrows each argument to it, for the rest of the block, as a guard that diverges
  does. A call deeper in an expression narrows nothing: the order of what runs after
  it there is not a block's.
- **Only a binding no lambda rebinds is narrowed.** The contract speaks of the value
  the callee was handed; the narrowing is read after the call. A field may have been
  written in between through another name (the callee holding the struct, a later
  argument), and a local by a lambda the call runs: either would be narrowed to a
  value it no longer holds.
- **Read on demand, in the module declaring it**, as a `@returns` contract is, in its
  own table: a function may carry both.
- **Checked, never asserted.** Each `return`, and the end of a body that gets there,
  must leave each parameter within the true side of `cond`, with the narrowings in
  force there (T3114). A body stopping the program where `cond` fails holds it, and
  so does one returning a call to a function ensuring it, its narrowings pushed as a
  statement's are. An `if` value is held branch by branch, its condition pushed on
  each side, a branch that never ends not at all; an `if` with no `else` whose branch
  diverges, past it, as a statement is.
- **A body that has run once the call returns.** A generator runs its body as its
  stream is read, a coroutine past its first `await`: either is T3112, as is a
  function with no body (`@extern`), which nothing holds. The last applies to
  `@returns` too.
- **The rules of `@returns`**: no write to a parameter (T3113); a generic function or a
  condition proving nothing of the parameters is T3112. A decorator stating other
  than one condition (P1032) declares no contract, so that no T3114 follows from it.
  The branches of an `if` value are walked by one mechanism for both decorators.

## Consequences

- A comparison does not narrow a primitive yet (0076): `@ensures(n in Hour)` is held by
  `if n !in Hour { … }`, not by `if n < 0 || n > 23 { … }`, until primitives narrow.
- What a branch block's own statements narrow is not read when holding an `if` value,
  as for `@returns`: such a body is refused where a written-out one passes.
- A `@returns` guard and an inferred one still narrow a field chain or a local a
  lambda rebinds, on the same reading after the call: that hole is older than this
  decision.
