# 0139: A server is a task per connection, and none outlives it

## Status

Accepted (2026-11-13).

## Context

0138 serves one connection from a `Reader` and a `Writer`. A server needs the
step before: accept the connections of a listener and serve several at a time.
A task parks where it waits (0127), and a socket call parks its task (0135),
so the loop of one connection can be run as it is, once per connection.

Three things had to be settled.

**What becomes of the connections when the server stops.** A function that
returns while tasks it launched still run leaves them to whoever called it,
who holds no handle on them; the combinators of `std/task` never do. And a
task cancelled before it started runs nothing, the `defer` of its entry
included: a connection accepted a moment before the stop would stay open if
only its task could close it.

**What a response costs on the wire.** A response written in two calls, its
head then its body, is two packets. With Nagle's algorithm the second waits
for the acknowledgement of the first, which the other end delays: on Linux
every exchange after the first of a kept connection took 41 ms on the
loopback address, against 0.35 ms once either cause was removed.

**What a handler may keep.** Several connections run the handler at a time.

## Decision

- **`serve(listener, handler, limits)` gives each connection a task** that
  runs `serve_connection` on its stream, then closes it. No type of the
  connection appears in what a handler sees.
- **No connection outlives the call.** When no further connection is
  accepted, those still served are cancelled, waited for, and closed. `serve`
  keeps each stream beside its task and closes it itself after the wait: a
  task that never started closed nothing.
- **`serve` returns why it accepts no more**, an `IOError`: the listener was
  closed, or the system refused. Closing the listener is how a server is
  stopped; cancelling the task that runs `serve` does the same.
- **A failure that says nothing of the next connection does not stop the
  server.** `accept` of `std/net` passes over a connection dropped before it
  was taken. A process with no descriptor left (`IOErrorKind.NoDescriptor`)
  is waited out by `serve`: it asks again after 5 ms, then twice as long each
  time, a second at most, while the connections it serves go on.
- **The head of a message goes out with the first bytes read of its body**,
  in one write. What the body gives later goes as it is read: nothing is held
  back for a buffer to fill, since a client may wait for it.
- **A stream of `std/net` sends each write as it is made** (`TCP_NODELAY`),
  the end that connected as the end that accepted. The one write above makes
  a short response one packet; this covers what follows it.
- **What a handler keeps from one request to the next goes in a `Shared` or
  an `AtomicInt`.** The documentation says so; the check of tasks does not
  yet refuse a handler passed as a parameter that writes a plain value.

## Consequences

The stop is abrupt: an exchange under way is cut where it is. Letting the
exchanges under way finish, within a delay, comes with the deadlines of a
connection, which nothing bounds yet: a connection that sends nothing is
served for as long as it stays open.

A server kept out of descriptors by clients that hold their connections and
send nothing waits for as long as they stay: the same deadlines end that.

Linux reports through `accept` the failures of the network a new connection
met (`ENETDOWN`, `EPROTO` and six more): they still end the server.

The connections still served are looked over at each `accept`, to forget
those that ended: a cost that grows with how many are open.
