# 0186: No `scope`, a discarded task is a warning

## Status

Accepted (2026-11-26). Confirms the choice of 0127 against structured
concurrency. The warning is W0025.

## Context

0127 set aside a `scope` that joins its tasks: the position of the `join`
already bounds a task for the gate check. Redesigning the concurrency model
for several cores reopened the question, with Kotlin's structured concurrency
as the reference: a scope waits for its children, and the failure of one
cancels the others and goes up.

A probe (2026-11-26) checked what a scope would add to the gates: `join_all`
already ends the tasks whose parts were given away, and joining only one of the
tasks makes every part refused to the reader. Two more facts weigh:

- Vader has no exceptions: a failure is a value. An implicit scope would not
  carry a child's error up; someone still has to read it from the `join`.
- Structure by default asks every function that returns a `Task` to `detach`
  it, or to take a scope as a parameter.

What structure would catch, a task launched and forgotten, is cheaper to point
at.

## Decision

- **No `scope` in the language or in `std/task`.** A task ends where it is
  joined, cancellation cascades by launch (0127), and `main` cancels and names
  the tasks still running when it returns.
- **A `launch` whose `Task` is thrown away is a warning** (W0025). Writing
  `_ :: launch(...)` says it is meant.
- **The shortcuts will be library functions**: `parallel_map` and
  `parallel_each`, not written yet, will launch, join and give the results
  back.

## Consequences

- A function may return a `Task`, and its caller decides when to join it; no
  scope travels through signatures.
- A scope remains a possible library addition, built on `launch` and
  `join_all`, if a program shows the need.
