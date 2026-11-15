# 0151: A wait on the system holds the virtual clock

## Status

Accepted (2026-11-15).

## Context

`VADER_VIRTUAL_CLOCK` makes the scheduler count the sleeps alone: with no
thread ready, it jumps to the end of the nearest sleep, so that what a program
prints depends on the order of its deadlines and not on the load of the
machine. It was meant for programs that do no real I/O.

A thread waiting on the system did not stop the jump: with nothing ready, the
scheduler asked the system without waiting and, when it had nothing yet, jumped
anyway. A timeout around a real wait then expired at once. `vader` met it
first: under the variable, the 600 s it gives its build driver to answer ended
before the driver could, and `vader run .` killed every driver. A program
does the same with `launch(() -> child.read_output()).timeout(1.seconds())`.
A watch the system refuses was worse still: its 2 ms poll was a sleep, which
the clock jumped, so the thread spun and the clock raced to the timeout.

The program `vader run` runs shares the scheduler of `vader` (the VM's threads
are threads of the host), so the variable cannot be turned off for `vader`
alone.

Three answers were weighed:

- **Turn off the guard of `vader` under the variable.** It mends one caller;
  every program keeps the trap.
- **Give the threads of the program a clock of their own**, as Go's
  `testing/synctest` scopes its fake clock to a bubble and Kotlin's `runTest`
  to its test scheduler. The most exact scope, but two clocks in one scheduler,
  and a program's own timeout around a child stays wrong.
- **Change what the virtual clock does while a thread waits on the system.**
  Go stops the clock: a goroutine blocked on I/O is not "durably blocked", so
  the bubble's time does not advance. Tokio jumps, as Vader did, and documents
  `spawn_blocking` as the way to hold its paused clock. Letting the clock run
  at the system's pace meanwhile has no precedent found, and loses the promise
  that the time work takes does not count.

## Decision

- **A thread that waits on the system holds the virtual clock.** The scheduler
  jumps only when nothing but a sleep can wake a thread; while a thread
  watches a descriptor or a child, it waits on the system, bounded only by what
  bounds such waits (below), and the clock stands still. What the system takes
  counts as work.
- **What bounds a wait on the system runs on the system's clock**, whatever the
  program's: the deadline given to the wait itself (`poll_stdin(d)`, the
  deadline of a socket read or write) and the 2 ms after which a thread whose
  watch was refused checks again. Such a bound is part of the wait, not a sleep
  of the program: under the variable, `poll_stdin(16.millis())` in a loop still
  gives up after 16 ms. The sleeps and the bounds are two heaps of timers, one
  per clock; under the real clock both read the same clock, and nothing
  changes.
- **The sleep of another task stays the program's**: a `timeout` around a wait
  is a task that sleeps, and it does not end while the wait holds the clock.

## Consequences

Under the variable, a timeout around a real wait lasts until the wait ends:
`vader` drives a build, and a program waits for its child. A wait given its own
deadline ends at it, in real time. The output of a program stays a function of
the order of its deadlines, real I/O included, as long as no wait is given a
deadline of its own.

A program that needs a sleep to end while it waits on the system waits for
ever under the variable: a client that connects to a real server after a sleep,
a timeout around a child that never answers. Such a program is not one the
virtual clock can make deterministic; Go asks the same of its bubbles, and
recommends in-memory fakes.

A scope of its own for the program's clock remains the exact answer if virtual
time becomes an API of `std/testing`, where a test opens and closes it.
