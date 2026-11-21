# 0168: A trait run by several tasks is checked at its implementations

## Status

Accepted (2026-11-22).

## Context

The task check compares what a task does with what runs beside it, from the
summary of each call. A call through a trait value runs one implementation of
the trait, but the code that makes the call cannot tell which: the summary of
`handler.handle(request)` is what every implementation of `Handler` may do.

When a door launches its tasks again while one runs, as `serve` does for each
connection, a write through that value is a write every task makes. Checked at
the door, one implementation anywhere in the program that writes a plain field
made `serve` itself an error, in the library, far from the write. It did even
when that implementation never reached `serve`, as in a unit test of a
middleware.

Three other ways were weighed:

- Copy the value for each task, as `serve` already copies its options: a copy
  the source does not write, which the concurrency model refuses, and a counter
  would silently count per connection.
- Mark the trait with a decorator, as `Sync` in Rust: the same check, with a
  surface to learn and to forget. The model infers what crosses tasks, it marks
  nothing.
- Let the caller of the door decide, as for a function value: the caller holds
  no more than a trait value either (`with_middlewares` returns a `Handler`),
  and the error would land at the call, not at the write.

## Decision

A write a task makes through a trait value, at a door launched again while one
of its tasks runs, is not that door's fault. It makes the trait one whose values
several tasks run at once. Every implementation of such a trait answers for its
own members: what a member writes below its `self` reaches a `Shared`, an
`AtomicInt` or an `AtomicBool`, or goes through a field of another trait, which
then answers in turn. Any other write is a T3129 at the write, naming the door.

A union of one trait and functions counts as the trait: a function value has no
part a write could reach, and its body is checked where it is written.

## Consequences

- The error lands on the line that writes, in the code that can change it, and
  does not depend on what else the program holds.
- Every implementation of such a trait is held to it, whichever value reaches
  the door: a middleware that writes a plain field is refused even if only a
  test runs it. Telling which values reach which door is a flow analysis the
  check does not do.
- A door whose single task runs beside the code that launched it still compares
  the two sides path by path, through the implementations of the trait.
