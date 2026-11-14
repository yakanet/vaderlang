# 0141: A server stops between two requests

## Status

Accepted (2026-11-14).

## Context

A server of 0139 stops at once: when no further connection is accepted, every
exchange under way is cut where it is, a response half written included.

And it closes a connection in one step. A socket closed with bytes of the
client still unread is reset rather than closed, and the reset may reach the
client before the response it was about to read, which is then lost (RFC
9112, section 9.6). It happens whenever the server ends a connection the
client still writes to: a request refused before its body was read, a
response that says `close` to a request whose body nobody read, a `408`. On
the loopback address of macOS and of Linux, a response of a few bytes to a
request of 32 KiB whose body was not read was lost every time.

Go closes the sending side, waits 500 ms, and closes; nginx closes the
sending side, then reads and drops what comes, 5 s at most between two reads
and 30 s in all. To stop, Go's `Shutdown` closes the listeners, closes the
connections that wait for a request, and lets those that serve one finish,
for as long as its caller allows.

## Decision

- **Closing the listener stops the server; cancelling the task that runs
  `serve` cuts it.** No other handle is needed. Any `accept` that fails for
  good stops it the same way.
- **A connection waiting for a request is closed at once**, a new one that
  has sent nothing yet included.
- **A connection serving a request ends after it**: its response says
  `Connection: close` when its head goes out after the stop, and the
  connection takes no further request either way.
- **The exchanges under way are given `ServeOptions.grace`, 30 s by default**,
  in all; then they are cut. Null waits for as long as they take.
- **Which of the two a connection is, `serve` and the connection settle on a
  state they both move**: the connection moves from waiting to serving when
  the first byte of a request comes, and back after the response; `serve`
  moves it to stopped, and cancels it if it was waiting. Of two moves made
  at once, one fails and is made again: a connection is never cancelled in
  the middle of an exchange.
- **A connection the server ends after writing to it is closed in two
  steps**: its sending side, then the whole of it once the client has closed
  its own, or once `Timeouts.linger` has passed, 5 s by default. What comes
  meanwhile is read and dropped. A connection the client ended, or that
  failed, is closed at once.
- **Only `serve` does either.** `serve_connection` on a `Reader` and a
  `Writer` closes nothing: closing is its caller's.

## Consequences

A request that reaches a connection as it is stopped gets no answer: its
client sees the connection close, as when a server ends a connection kept
idle, and asks again on another, if it can.

A connection the server ends holds its task and its socket up to 5 s more.

A server stops on no signal: the standard library cannot handle one yet.
Whoever closes the listener stops it.

A flag that `serve` raises for all its connections at once is refused by the
check of tasks, which takes a value kept in a struct for one a task may
write, atomics included: each connection holds its own state, which `serve`
reaches through its list of connections.
