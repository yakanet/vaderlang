# 0143: A server bounds its connections and their life

## Status

Accepted (2026-11-14).

## Context

The review of 0140 left two ways to exhaust a server built on `serve`:

- Nothing capped the connections served at a time. Each slow client holds a
  task and a descriptor until its time runs out, and enough of them exhaust
  the process. Out of descriptors, `serve` waits (0139), and every other
  client with it.
- Nothing bounded how long a connection lives, nor how many requests it
  carries: a client that asks once within each wait between two requests
  keeps its connection, and its task, for good.

nginx bounds both: `worker_connections` (512), `keepalive_requests` (1000)
and `keepalive_time` (1 h), the connection being closed after the request
that reaches either of the last two.

## Decision

- **`ServeOptions.connections`, 512 by default**: `serve` accepts no further
  connection while that many are served. It looks every 10 ms whether one
  ended, or whether its listener was closed, in which case the next `accept`
  fails and `serve` stops as 0141 says. `std/net` gains `is_closed(listener)`
  for it: a task parked in `accept` is woken by the close, one that waits for
  room is not.
- **`ServeOptions.requests`, 1000 by default, and `Timeouts.lifetime`, 1 h**:
  the request that reaches either is the last of its connection, and its
  response says `Connection: close`.
- **The connection makes itself last through the state of 0141.** As its
  request begins it moves from `SERVING` to `STOPPED`, as `serve` does when
  it stops: `persists` answers `close` for both, and no second flag has to be
  read where the response is written. `serve`, stopping, leaves a connection
  already `STOPPED` to finish its exchange, as it does one it stopped itself.
- **Null lifts each limit**, as it does a timeout. A limit of 0 counts as 1:
  a server that took no connection, or a connection that carried no request,
  would serve nothing.

## Consequences

A slow client still holds its connection until its time runs out (0140), but
at most 512 of them are served at once, and the next connection waits in the
listen queue of the system instead of taking a descriptor.

A full server wakes every 10 ms and may leave a connection that ended unseen
for as long. A count of free places that parks `serve` until a connection
gives its place back would do without, but closing the listener would still
have to wake it, which nothing in `std/task` does today.

The state of a connection no longer says who stopped it: `serve`, or its own
limits. Nothing reads that difference.

The test of 0142 lifts the cap on requests: a connection that never waits
would otherwise end at its 1000th request, and let the others be served
whether it gave way or not.

Still open from 0140: the time of a body is counted from each read, and that
of a response from each write.
