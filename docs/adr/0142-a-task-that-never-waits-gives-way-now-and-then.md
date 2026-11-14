# 0142: A task that never waits gives way now and then

## Status

Accepted (2026-11-14).

## Context

The tasks of a program share one thread, and give way to one another only
where they park (0127). A read of a socket parks only when the socket has
nothing to give, and a write only when it has no room.

A connection whose client sends its requests back to back, and reads the
responses as they come, therefore never parks: its task keeps the thread for
as long as the client goes on, and every other connection waits, `accept`
too, and so do the timeouts of 0140, which a parked task is woken for. On the
loopback address, a request on another connection got no answer in 4 s while
one connection did so; with no such client it got one in 0.6 ms.

The runtime already asks the system, at the end of each turn of the ready
tasks and at most once a millisecond, which watched descriptors are ready: a
task that never parks starves the others only because it never ends its turn.
A task that wakes itself and then parks ends it: the runtime needs no
change.

tokio counts the operations of a task and has its I/O answer "not yet" once
it has done 128 since it last yielded. Go preempts.

## Decision

- **`give_way_now_and_then` of `std/task` counts its calls**, and at every
  128th the calling task wakes itself and parks: the ready tasks run, and the
  runtime asks the system for those it can wake. 128 is tokio's.
- **`accept`, `read` and `write` of a TCP stream call it**, every call, so
  every protocol on a socket is covered, not HTTP alone. They call it before
  they look at the stream: closed, or its deadline past, while the others
  ran, it is seen as such, and no system call reaches a descriptor that may
  name another socket by then.
- **The count is one for all the tasks**, an atomic one: the runtime keeps no
  per-task value the library could reach. A task that waits often gives way a
  little sooner than it has to.

## Consequences

A connection that never waits still has as many turns as the others, and the
others are answered within a few turns of 128 steps: on the loopback address,
2 ms while one connection flooded the server.

What does not go through a socket is not counted: a task that computes, or
reads a file, without parking still keeps the thread. Reaching for
`give_way_now_and_then` in such a loop is the caller's.

A task alone still parks at every 128th call, and is switched back to at
once.

A callback that C calls cannot park: one that reads or writes a socket now
stops the program at some 128th call, where it stopped before only when the
socket made it wait.
