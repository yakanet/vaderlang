# 0183: A function has no colour, the editor shows where it waits

## Status

Accepted (2026-11-26). Amends 0127. Not implemented yet: T3132 and the
inference behind it still stand in the code until the redesign of the
concurrency model removes them.

## Context

0127 made every function able to park: a task parks wherever it waits, and
nothing marks a function as one that may. One rule of the cooperative
scheduler survived it: a `Shared`'s `locked` body must not park, because the
body runs under the global monitor, which a parked task lets go of. The rule is
T3132, and keeping it takes an inference over the whole program: "may this call
park?", resolved for a call through a trait by every implementation of the
trait.

That inference is the part of the checker that is not compositional. It is
imprecise in both directions, and every imprecision is an error that blocks a
program: an iterator over a channel makes every `for` on an `Iterator` "may
park", and a library function cannot know which of its callers hold a lock.

Three properties cannot all hold:

1. waiting is allowed everywhere, under a lock included;
2. no function is coloured;
3. no deadlock, by construction.

Go and Java's virtual threads keep 1 and 2 and detect deadlocks at run time.
Verona's behaviour-oriented concurrency keeps 2 and 3 by making a critical
section asynchronous: a body never waits. Haskell's STM keeps 1 and 3 and
colours the transaction. Vader kept 2 and 3 and tried to infer its way to 1.

Two coloured designs were weighed: `suspend` on declarations, as Kotlin does
(a local, exact check, at the price of colour in function types and APIs
written twice, `Sequence` and `Flow`), and `async` / `await` with an event loop
per worker, as Node does (atomic between two `await`, at the price of 0127's
reasons for removing `await`).

## Decision

- **No colour in the language.** No `async`, no `await`, no `suspend`: 0127
  holds. Property 3 gives way: a deadlock is detected at run time, with the
  tasks and the locks that hold it named.
- **Waiting under a lock is allowed.** A `Shared` takes a lock of its own,
  which parks the virtual thread that waits for it instead of blocking the
  worker (decided with the isolation, 0184). T3132 and the "may park" error
  leave.
- **The inference stays, as a hint.** The compiler still infers where a call
  may wait; the language server shows it (wait points), and warns of a wait
  under a lock, which serialises every task that wants the same value. A hint
  is never an error: an imprecise inference misleads at worst, it blocks
  nobody.

## Consequences

- A library function is written once, whoever calls it and under whatever
  lock.
- The checker on the data (the gates of 0127) is untouched: races stay compile
  errors. Only the waiting rule moves from the compiler to the runtime.
- The precision of the "may park" inference becomes optional work: it improves
  a hint, it no longer decides what compiles.
- A deadlock is a run-time failure. Its report has to name both sides, the
  task, the lock it holds and the one it waits for, or the trade is a bad one.
