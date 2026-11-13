# 0138: The library owns the loop of a connection

## Status

Accepted (2026-11-13). Closes the class 0137 left open.

## Context

`lib/http` first exported what reads and writes one message: `read_request`,
`write_response` and their mirrors, then `persists` and `drain` for what comes
between two messages. None of them remembers its connection. A caller that
loops on `read_request` holds two handles on one stream of bytes, the body of
the request and the reader of the connection, and the order in which it uses
them is what tells one message from the next.

That order can go wrong five ways, each a desynchronisation:

- the next message is read before the body of the last was (CVE-2026-34441,
  CVE-2022-21826): the body is taken for a request;
- a body is kept and read later: it takes bytes of the request after it;
- a response is written for another request than the one it answers
  (CVE-2026-100666): a body is written where none is read, or the reverse;
- reading or writing goes on after a failure (CVE-2022-22720,
  CVE-2026-55612): what follows a body cut short is read as a message;
- a connection that ended is used again (CVE-2026-94439).

Functions that are safe only when called in the right order are the flaw
itself: the published cases are servers that forgot one call.

## Decision

- **A connection moves on only on proof, held by the library, that the last
  message ended.** The proof is the state of the reader of the body.
- **The library owns the loop.** `serve_connection(reader, writer, handler)`
  reads a request, calls the handler, writes its response, settles the
  exchange and reads the next. A handler is given a request and returns a
  response; it never asks for the next request, and never sees the connection.
- **Settling an exchange** is, in this order: end the connection if either
  message says so or the response left HTTP; read past the body of the request,
  up to `Limits.unread_body`; end the connection if that fails.
- **The body of a request is read while the request is served.** The loop
  revokes it as it moves on: a read after that fails, and gives no byte.
- **Any failure ends the connection.** A request that cannot be read is
  answered with its status and is the last. A response that cannot be written
  is replaced by a `500` when no byte of it went out, and followed by nothing
  either way. Once a write failed, no other is tried: what it left on the
  connection is not known.
- **A handler answers with a final response.** An interim one would leave its
  request unanswered, and the next response would be read as this request's.
- **The loop frames on what it read and on what it was returned, not on what
  a handler holds.** The handler is given a copy of the request, and its
  response is copied before a byte of it is written. A handler that rewrites
  the method of its request, or a body that changes its own response while it
  is read, changes nothing of what is written and settled.
- **A body that failed once is at no end.** A handler may pass over the
  failure of a read; what reads past the body then finds it broken, and the
  connection ends.
- **A reader is not believed over its word.** The body of a response that says
  it read nothing, or more than it had room for, fails the response: a message
  is never framed around bytes that are not there.
- **No body is held whole to be counted.** A response of no declared length
  goes in chunks; to a client that reads none it is written as it is read and
  ends with its connection. A handler that streams costs no memory, whoever
  asks. A request has no such end: one of no declared length, to a peer that
  reads no chunks, is refused before a byte goes out.
- **Nothing exported reads or writes a message outside the loop.** The
  functions of the first design are private to the module.

Vader has no type that can be used only once: the guarantee holds at run time,
and holds because no exported path goes around it.

## Consequences

A handler that ignores a small body costs nothing; one that ignores a large
body costs its connection. The response to such a request was written before
the body was found too long, so it does not say `Connection: close`: the
client learns it from the connection ending. Reading past the body before the
response is not an option, since a response may be built on the body it
answers.

A handler cannot send an interim response of its own, nor take a connection
over after `101` or a successful `CONNECT`: the first is written for it when a
client waits for `100 Continue`, the second ends the service.

The client is not written yet. Until it is, nothing exported reads a response,
and the same rule will hold of it: a connection is used again only once the
body of the response reached its end.

`test_whatever_a_handler_does_a_body_is_never_a_request` holds the property:
nine ways a handler may behave, eleven shapes of request, every cut of the
stream, and bodies that read as requests. What the handler sees is the
requests that were sent, in order, or the connection ends.

The last four decisions came from two reviews that set out to break the first
ones, by reading the code for what the loop took on trust: that a body which
failed stays failed, that a reader returns what it was asked for, that a
response is the same after its body ran as before, that a writer which failed
is not written again, that a body is short enough to hold.
