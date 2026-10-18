# 0079 — A declared guard is a checked contract

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its fifth part continued
(D11, S7): the declared guard, `@guard(cond)`, validated in the charter on
2026-10-11. Builds on 0078.

## Context

An inferred guard (0078) holds in its own module: its facts come from its body, which
another module should not depend on, since the body may change without its signature
changing. A predicate exported as part of an API needs a contract stated in its
signature, checked against its body, and read by every caller.

## Decision

- **The form.** `@guard(cond)` on a free function returning `bool`, `cond` one condition
  over its parameters, resolved in their scope. Any test may appear: `d in Weekend`
  for a range (`in` tests a value's membership, `is` a tag, 0077), `x is Circle`,
  `name != null`. The charter wrote `@guard(d is Weekend)`; with ranges tested by
  `in`, that reads `@guard(d in Weekend)`.
- **What it proves** is what the narrowing machine gives `cond` on each side, for each
  parameter, as for an inferred guard. A declared contract replaces the body's facts,
  in its module as elsewhere: what the body proves beyond it stays private.
- **Read on demand, in the module declaring it.** A contract depends on the signature
  and `cond` alone, never on the body, so it is read the first time a call needs it,
  in the declaring module's typed program, apart from whatever that module's walk is
  in, and kept in one table every module shares. A module walked before the one it
  imports reads the contract all the same, at any depth of imports. A condition that
  reaches its own guard reads nothing of it, and proves nothing.
- **An equivalence, checked at each returned value.** Where the fn returns `v`, the
  narrowings `v` adds to those in force must leave each parameter within the
  contract's true side where `v` is true, and within its false side where `v` is false
  (S7). A literal `true` or `false` is held on its own side; an `if` value branch by
  branch, its condition pushed on the side reaching the branch. The trailing value of
  a block body is held before its guards' narrowings are undone, so a body written
  with early returns is held as written. The contract travels on the body's own
  context: a lambda in it returns for itself. A failure is T3111, naming the side,
  the parameter and what it holds there.
- **No write to a parameter.** The contract speaks of the argument; a body writing the
  parameter would hide it. Refused in the body and in a lambda written in it (T3113).
- **Shape.** A generic fn (`x is U` belongs to the generics over types and integers,
  later), a result other than `bool`, or a condition proving nothing of the
  parameters is T3112. More than one condition is P1032, as for `@assert`; `@guard`
  anywhere but on a free function is P1014, as `@singleton` is.

## Consequences

- An exported predicate narrows its callers only through `@guard`; changing its body
  in a way that breaks the contract fails its own module's build.
- A `match` value, and what a branch block's own statements narrow, are not read when
  holding a returned value: such a body is refused where a written-out one passes.
