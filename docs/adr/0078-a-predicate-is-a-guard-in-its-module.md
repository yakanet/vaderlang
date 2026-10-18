# 0078 — A predicate is a guard in its module

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its fifth part (D11, S7):
guards inferred within a module. The declared forms, `@guard` and `@asserts`, come
next. Builds on 0076. Amended by 0082: the declared forms are written `@returns` and
`@ensures`.

## Context

A test written once is often named: `is_weekend :: fn(d: Weekday) -> bool = d >= 5`.
Without help, `if is_weekend(d) { rest(d) }` loses what `d >= 5` proved, and the code
must repeat the test inline to keep the narrowing. The charter makes such a predicate
a guard whose facts the compiler computes itself, not one taken on trust.

## Decision

- **What a guard is.** A top-level function of the module whose body is one expression
  of type `bool` over its parameters, not generic, with a parameter a test can narrow
  (a union, a trait value, an integer or a range): the others are known at
  declaration to prove nothing. A block body is no guard: its facts would have to be
  read at each `return`, which the declared `@guard` will do.
- **What it proves** is what the narrowing machine gives its condition, read for each
  parameter on the true side and on the false side, once its body is checked. Both
  sides hold because the body is the condition: the guard is an equivalence (S7).
- **At a call** in a condition, each argument that is a binding or a field chain takes
  the fact of its parameter, fitted to its own type: the fact itself when the argument
  has the parameter's type, the values both hold for integers, the fact again when it
  refines the argument, nothing otherwise. Every such argument is narrowed. The call
  composes through `!`, `&&` and divergent guards as a test does; inside a `||`
  whose true side narrows one slot, it counts as the test of its first argument.
- **A call ahead of its guard** checks the guard's body then, on its own: at module
  level, the walk's position set aside (`set_walk_aside`, shared with a const read
  before its turn), reporting nothing, the guard's own walk does. A throwaway walk
  over every candidate before the full one was measured and set aside: it cost 2 to
  3 % of a self-check, where checking on demand costs nothing measurable. A guard
  being checked reads nothing of itself, so recursion settles. Nor is a guard checked
  ahead while a const's value is typed: a fn body runs once every const is set, and
  checking it there would put its reads in that const's dependencies.
- **Module-local.** The facts live in the module's typed program; another module calls
  the function as a plain predicate. An exported contract is the declared form's job.

## Consequences

- Predicates of the compiler tree narrow their arguments at their calls; nothing in
  the tree breaks, and the emitted code only gains casts where a union narrows.
- A guard written as a `match` is no condition and proves nothing.
- What a guard proves of a parameter's field (`b.label != null`) is not carried to the
  argument: facts are read for bindings only.
- A call to a guard written ahead of it inside a const's value narrows nothing.
