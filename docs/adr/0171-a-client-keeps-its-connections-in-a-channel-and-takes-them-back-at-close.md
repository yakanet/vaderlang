# 0171: A client keeps its connections in a channel, and takes them back at close

## Status

Accepted (2026-11-22). Amends 0169: a connection comes back to its
`HttpClient` when its response is closed, not when its body ends.

## Context

An `HttpClient` serves several tasks, and keeps the connections of one task
for the requests of another. A connection belongs to one task at a time: the
task that sent its request, until the response is done.

A `Shared` cannot hold them: a value does not leave a `locked` block, even
taken out of the collection the `Shared` holds, so no task could take a
connection away to use it.

A connection on loan is reached from the response its task holds, through
the body. The analysis of tasks sees a value handed to a channel as given
away with everything it reaches, and two places were weighed for the
hand-back:

- the end of the body, in its `read`: a call of `Reader.read` stands for every
  implementation of `Reader`, so every read in the program would then be seen
  as giving away part of its reader, a `BytesReader` too;
- `close(response)`: a body is a `Reader` to the analysis, which cannot tell
  the body of a `ClientConnection` from that of an `HttpClient`, so closing a
  response of a `ClientConnection`, then sending the next request on that
  connection, would be refused.

## Decision

- **The idle connections wait in a `Channel`**, which hands each to one task.
  `poll` and `offer` (`std/task`) take and give without parking: a client
  takes the first idle connection to its server, puts back those to other
  servers, and closes one it has no room for. One channel holds those of
  every server, sixteen at most.
- **`HttpClient` returns a `ClientResponse`**: the fields of a `Response`, and
  the connection. Its own `close` reads past the rest of the body, as
  `close(response)` does, then hands the connection back. `close(Response)`
  stays as it was.
- **A connection comes back at `close` only.** A body read to its end and not
  closed keeps its connection until the program ends.
- **A connection whose request failed is closed**, never handed back: the
  error returned and the connection would reach each other, to the analysis.

## Consequences

- `defer response.close()` is what a caller writes, as Go's callers close
  `resp.Body`. Forgetting it costs a socket, not a wrong response.
- A request refused before any of it went out closes a connection that could
  have served the next one.
- A body that gives back what it holds when it ends needs the analysis to see
  a value moved out of its holder as no longer held by it.
