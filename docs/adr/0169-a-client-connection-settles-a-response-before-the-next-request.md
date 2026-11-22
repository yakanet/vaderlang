# 0169: A client connection settles a response before the next request

## Status

Accepted (2026-11-22). The client side of 0138. Amended by 0171: the
connection of an `HttpClient` comes back when its response is closed.

## Context

A client reads each response from where the one before it ended. The body of
a response is a reader the caller holds, and the caller may stop reading it at
any point: the rest of that body is still on the connection, ahead of the next
response. The order of the calls is again what tells one message from the
next, which 0138 refused on the server side.

Vader has no destructor. A body the caller neither reads to its end nor closes
keeps its connection: nothing runs when the caller drops it.

Two ways were weighed for a body still open when the next request is sent:

- refuse the request until the body is read or closed: the caller learns the
  rule, but each caller must then settle the exchange itself, which is the
  order of calls 0138 took away from the server;
- read past what is left, as the server reads past the body of a request.

And two for what `HttpClient` returns, the connection going back to its pool
once the body ends:

- the body read whole into memory before returning: no connection is ever
  kept by a body, but a response is bounded by what memory holds, and a large
  download goes through a buffer;
- the body as a stream, which the caller reads or closes.

## Decision

- **A body ends read to its end, or closed.** `close(response)` reads past
  what is left, up to `Limits.unread_body`, and the body fails from then on.
- **`send` closes the body before it, by the same `close`.** A body read after
  the next request was sent fails: its bytes are behind the next response.
- **A body that cannot be read past ends the connection**, as does a response
  that says so (`persists`), a failure once some of the request went out, and
  a final response to a request whose content waited for `100 Continue`.
- **`HttpClient` returns the body as a stream.** The connection goes back to
  the pool when the body ends. A body neither read nor closed keeps its
  connection: the vaderdoc says `defer response.close()`.

## Consequences

- No call order is left to the caller of a `ClientConnection`: a forgotten
  body costs a read past it, never a response read out of another.
- A forgotten body on an `HttpClient` keeps a socket out of the pool until the
  program ends, the failure Go knows as the unclosed `resp.Body`.
- A body read in part, then left, is read past at the next request: up to
  `Limits.unread_body` bytes the caller did not want.
