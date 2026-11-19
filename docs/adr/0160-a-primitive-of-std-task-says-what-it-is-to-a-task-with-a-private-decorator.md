# 0160: A primitive of `std/task` says what it is to a task with a private decorator

## Status

Accepted (2026-11-19). Reads declared decorators as
[0152](0152-a-decorator-is-a-declared-type.md) defines them; the relays lean on the
identity of the members of `Intrinsic` of [0155](0155-what-vader-cannot-write-is-a-member-of-intrinsic.md).

## Context

The task check knew the primitives of `std/task` (launch, join, send, lock, the
atomics) by a table keyed `"std/task.launch"`, and the structs tasks share by a
closed list of names. Renaming or moving a primitive dropped it from the analysis
in silence. What a primitive is to a task is a contract of the runtime, not a
property of its code (`locked` runs its body alone only because the scheduler never
preempts it): it cannot be deduced from the body, it has to be declared.

## Decision

- **`@task_primitive`** sits on each primitive. Its fields name the parameter a task
  runs, the one it gives, the one it joins, the fn run holding a lock, and the fields
  of the struct lent first that the call writes, grows or guards, by name; `parks`
  and `takes` are flags. The check turns the names into positions, reads whether a
  join waits for one task or an array of them from the parameter's type, and checks
  every name. A wrong name is a fault of the library: the compiler stops on it.
- **`@task_shared`** sits on each struct tasks share by design, read from its
  declaration by the check and by the emitter, as `@c_struct` is.
- **Both are declared private in `std/task`.** No other module can write them, so a
  library cannot claim to be a primitive, and the compiler recognises them by their
  module and name, with nothing added to the compiler's own decorators.
- **A function that only forwards to a member of `Intrinsic` that parks parks too**
  (`park`, `sleep_for`, the waits of `std/runtime`), by an exhaustive predicate on
  `IntrinsicId`. Those relays carry nothing.
- The decorators are read before the comptime pass: each value is a literal.

Rejected:

- A decorator of the compiler per property (`@runs`, `@gives`...): eight decorators
  used once each.
- A table beside the primitives, linked by strings: every primitive declared twice.
- A table written by a source stage of the compiler into `std/task`: the relays live
  in other modules, overloads (`load`, `store`) cannot be named by a string, and the
  only gain was visibility in `build/expanded`.
- A marker trait for the shared structs: an empty impl needed a syntax of its own.

## Consequences

- A primitive renamed or moved keeps its meaning; one that loses its decorator is an
  ordinary function to the check, whose body is then read.
- The hover of a primitive shows the decorator, private as it is.
