# 0088: A loop variable is a constant binding

## Status

Accepted (2026-10-19). Assigning the variable of a `for … in` is refused, while the
condition form `for i > 0 { i -= 1 }` keeps rebinding an ordinary local.

## Context

The variable of a `for x in …` could be assigned in the body. What that did depended
on how the loop was lowered: over a range written in place, the counter is the
variable, so `for i in 0..=3 { i = 0 }` never ended; over an array, a chain or a type,
the walk went on as if nothing happened. A closure capturing such a variable needed a
fresh cell each turn, which the lowering built on a synthetic counter. Nothing in the
compiler or the stdlib assigned a loop variable; one snippet did, to test the cell.

A loop variable is a new binding each turn, and a `for` evaluates what it walks once,
before the first element. Assigning it reads as skipping elements, which it never
does.

## Decision

- The variable of a `for x in …`, and each name of `for [k, v] in …`, is a constant
  binding: assigning it is T3041, with a detail that says it is a loop variable and
  how to get a mutable copy (`y := x`).
- Changing what it designates (`x.f = 1`, `x.push(y)`) is allowed, as for any `::`
  binding.
- The condition form binds nothing: in `for i > 0 { i -= 1 }`, `i` is an ordinary
  local, assigned as any.

## Consequences

- No loop variable lives in a cell: a closure copies its value when it is made. The
  range counter runs on the variable itself, with no per-turn rebinding.
- The resolver records the loop variables among the immutable locals, with the
  reason (`ConstLocal.LoopVariable`), so that T3041 names them.
- A name an `as` or a pattern binds (`if e is T as v`, `match … as w`, a struct
  pattern's field) is left assignable: this decision covers the `for … in`
  variable alone.
