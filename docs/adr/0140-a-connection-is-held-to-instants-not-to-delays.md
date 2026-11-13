# 0140: A connection is held to instants, not to delays

## Status

Accepted (2026-11-13).

## Context

A server of 0139 waits for its clients without end. A client that connects
and sends nothing holds a task and a socket for as long as it stays; one that
sends a byte of a request now and then is never done; one that asks for a
large response and stops reading holds whatever writes it. Each is a way to
take a server down with few connections and no traffic.

Two shapes bound a wait. A delay per call (`read` within five seconds) does
not bound a request read in ten calls: each is in time. An instant on the
stream does: every call still parked at that instant fails, however many
there were before it. It is what Go's `SetDeadline` is.

A `TcpStream` is held by two tasks at once: the one that serves the
connection, and `serve`, which closes it (0139). A field one task writes while
another holds the value is refused by the check of tasks.

The loop of a connection (0138) sees a `Reader` and a `Writer`, and must stay
so: TLS will stand between it and the socket.

## Decision

- **A stream of `std/net` carries an instant for its reads and one for its
  writes**: `read_by(instant)`, `write_by(instant)`, null for none. A call
  parked at the instant fails as `.TimedOut`, and so does every call made
  after it, until the instant is moved. Both are kept in atomic cells, which
  two tasks may share.
- **The runtime is not changed.** A wait on a descriptor already took a limit
  of time (0128); the wait on the system thread, when no other task runs,
  takes the same limit.
- **The loop moves the instants through a trait of `lib/http`**, private to
  it, which `serve` implements on the stream. `serve_connection` on a bare
  `Reader` and `Writer` has no limit of time.
- **Four timeouts**, in `Timeouts`, each null for none:

  | Step | Counted | Default |
  |---|---|---|
  | the head of a request | in all | 60 s |
  | between two requests | in all | 75 s |
  | the body of a request | from each read of it | 60 s |
  | the response | from each write of it | 60 s |

  They are the defaults of nginx. Go's server has none unless its caller
  sets them: a server is then open to all of the above until someone reads
  the documentation.
- **What is left of a body nobody read is read past within one wait of a
  body, in all**: a client is not given a wait per byte.
- **A client is told what can be told.** A head begun and not finished in
  time is answered `408` (RFC 9110, section 15.5.9), and the connection ends.
  A connection with nothing asked on it ends with no answer: there is no
  request to answer. A body or a response that stalls ends the connection
  where it is. `EndReason.TimedOut` names them all.
- **Only the client is held to them.** A response whose body waits on a
  source of the handler's own that runs out of time, an upstream say, is a
  response that failed: the client is not told it was too slow.
- **`serve` takes `ServeOptions`**, its limits and its timeouts, where it
  took `Limits`.

## Consequences

A handler is given no limit of time: one that computes for an hour holds its
connection for an hour. `timeout` of `std/task` bounds a piece of work.

The time of a body is counted from each read, and that of a response from
each write: a client that sends a byte every fifty seconds, or takes a few
kilobytes in as long, keeps its connection for as long as there is a body to
carry. The length of a body is the handler's to bound.

Nothing bounds how many requests a connection carries, nor how long it lives:
a client that asks once a minute keeps it.

A client that sends an empty line after a request, as some did after a
`POST`, and then nothing, is answered `408` after the time of a head: the
line is the first byte of a request that never came.

A call already parked keeps the instant it parked with: moving the instant
of a stream from another task does not wake it.

Each connection is handed a copy of its options. The check of tasks takes a
value a task keeps for one it may write, and options kept by every connection
would be shared by them all.
