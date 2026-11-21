# 0164: A trap leaves its task alone until the program aborts

## Status

Accepted (2026-11-21), on the branch that spreads tasks over several cores.

## Context

A trap (a `panic`, a failed run-time check, `unreachable`) prints its message,
runs the pending defers of the thread that trapped, then aborts. `launch` wraps
every task in a `defer end(task)`, which wakes the task that joins it.

With one worker, nothing woken runs before the abort, unless a defer parks. With
several, another worker takes the woken thread at once: `main` printed
`cancelled` after the message of a task's trap, and could have returned 0, so
that a program whose task trapped exited with success.

## Decision

Once a thread traps, it is the only one left to run, on any number of workers:

- the trap first stops every other worker, with the stop of a major, and they
  never resume; then it prints, runs its defers, and aborts;
- its own worker runs no other thread, started or not;
- its defers may sleep or wait for the OS, which the worker still serves; a park
  with no timer and no watch waits for a thread that will never run, and aborts
  at once, as does a monitor or a mutex it cannot take, which a stopped worker
  holds;
- a trap on another worker after the first stops there and prints nothing.

Rejected:

- a flag that keeps the other workers from taking work: a task already running
  elsewhere would go on, and print, until its next park;
- leaving the runtime as it was and loosening the test that showed it: the exit
  status of a program whose task trapped would depend on a race.

## Consequences

- What a program prints after the message of a trap comes from the defers of the
  thread that trapped, and from nothing else.
- With one worker too, a defer that yields or parks during a trap no longer lets
  the other threads run: one that waits for another task aborts, where it used to
  finish once that task had run.
- A trap under the scheduler's lock lets it go before it stops the others, which
  wait for that lock without stopping.
- A loop that computes without allocating or parking delays a trap, as it delays
  a major.
