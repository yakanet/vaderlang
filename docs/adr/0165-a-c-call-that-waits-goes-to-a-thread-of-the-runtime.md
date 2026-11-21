# 0165: A C call that waits goes to a thread of the runtime

## Status

Accepted (2026-11-21), on the branch that spreads tasks over several cores.

## Context

A task waits for a socket, a channel or a timer by parking: its worker runs the
other tasks meanwhile. A C function that waits (`waitpid`, `flock`,
`getaddrinfo`) does not park: its worker runs nothing else until C returns. With
tasks pinned to their worker (ADR 0163), the tasks of that worker stop, and no
other worker takes them.

Measured on an Apple M-series laptop, one call to a C function that computes
nothing:

| Call | Cost |
|---|---|
| direct | about 1 ns |
| inside a region where the worker counts as stopped for the collector | about 10 ns |
| handed to a helper thread and back, with a condition variable | about 4 us |
| relayed by the runtime, the task parked on a pipe | about 6 to 7 us |

## Decision

`@c_blocking` on an `@extern` hands its calls to a pool of helper threads:

- the shim roots the objects it lends to C and, when it lends one, empties the
  worker's young generation, so that nothing C reads moves while other tasks
  allocate; then it converts the arguments into a frame on the task's stack;
- a helper takes the frame, makes the call, keeps `errno` (`GetLastError` on
  Windows) and rings a bell, a pipe the task waits on as on a socket;
- a cancel waits for the next park, since the helper writes into the task's
  stack;
- with no scheduler, or no other thread, the task makes the call itself;
- the type checker counts the call as a park (refused under `locked`), refuses a
  callback parameter, which C would call from a thread with no task, and refuses
  the decorator on a function with a Vader body;
- the VM makes every call on the task's thread.

The marker is the programmer's word. To make it findable, every other call to C
stores its name and a call count in the worker, and a watch thread warns once
per function when a call holds its worker past a threshold (100 ms,
`VADER_WARN_BLOCKING_MS`, 0 for never) while a thread of that worker is ready or
waits for the clock or the OS. It warns on one worker too: the tasks of that
worker wait the same.

Rejected:

- relaying every call to C: about 6 us on each `strlen`;
- a region where the worker counts as stopped, so that a major does not wait
  for it: the major goes on, but the tasks of the worker still wait for C;
- a second worker started while one is held, the way Go hands off its P: tasks
  are pinned to their worker, so the new worker could not take them;
- a list of known blocking functions in the compiler: a name in the compiler for
  what a library declares, and nothing for the libraries the program brings.

## Consequences

- A blocking call costs microseconds; a call that computes stays direct.
- The call is cancelled only once C returns.
- Every direct call to C writes three words in its worker, for the watch.
- A warning can come from a call that computes for long: it names the function,
  and the program decides.
