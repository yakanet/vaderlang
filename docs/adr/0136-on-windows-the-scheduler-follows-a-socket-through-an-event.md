# 0136: On Windows, the scheduler follows a socket through an event

## Status

Accepted (2026-11-13). Amends 0129 and 0135.

## Context

kqueue and epoll say that a descriptor is ready; a completion port says that an
operation has ended. `std/net` is written on the first: a call that finds
nothing fails, the task waits, and calls again (0135). On Windows a socket was
no descriptor the scheduler could watch, and a watch for a write was refused.

A socket and a pipe are both handles there: a number alone does not tell the
runtime which it is watching.

## Decision

- **The library tells the runtime which handles are sockets.**
  `vader_socket_event(socket)` makes an event and has the runtime follow the
  socket; the library hands the event to `WSAEventSelect`. From then on
  `wait_readable`, `wait_writable` and `stop_waiting` serve the socket as they
  serve a descriptor elsewhere. `vader_socket_forget(socket)` ends it, before
  the socket is closed.
- **Two functions of the runtime bound with `@extern`, not intrinsics.**
  Neither parks: the waits remain the intrinsics the task check knows. The
  compiler and the seed do not move.
- **The runtime does not call Winsock.** It waits on an event; the library
  asks the system to signal it. A program with no socket links no socket
  library.
- **One wait of the thread pool per socket, for as long as it is followed.**
  The event resets itself when the pool takes its signal, and the pool posts a
  report to the completion port. Nothing is armed at each park.
- **A signal ends the wait of each side.** The system does not say which side
  an event is for; the reader and the writer both ask the socket again. One
  thread a side still (0135).
- **A signal with no wait is kept**, one mark a side, and ends the next wait
  of that side at once. The library waits only after a call that found
  nothing, which is also what makes the system signal that kind of event
  again: a mark left over costs one more call, and no signal is lost.
- **A `connect` asks the socket how the attempt went** once a wait ends
  (`WSAEnumNetworkEvents`): a signal alone does not say that it is over.
- **A wait on a followed socket parks even when no other thread runs.** The
  runtime has no way to ask whether such a socket is ready, so the caller has
  nothing to wait on by itself, unlike a descriptor (0128).
- **`SocketHandle` is a number, and a member of `Descriptor`** (0129):
  a `SOCKET` is an integer, not a pointer, and `std/io` waits on one.
- **No `SO_REUSEADDR` on Windows**: a listener restarts at once without it,
  and with it two listeners take one address.

Set aside:

- **Overlapped operations** (`WSARecv`, `WSASend`, `AcceptEx`), the native use
  of a completion port: the buffer of a read is then held by the system while
  the task is parked, and `std/net` would have two shapes, one per system.
- **A read of no byte**, as for a pipe: it says nothing of a write, an
  `accept` or a `connect`.
- **The runtime finding out by itself that a handle is a socket**: every
  program would link Winsock, and each first watch would ask the system.
- **An event the library keeps and resets**: a task that reads and a task that
  writes one connection would clear each other's signal.

## Consequences

- `std/net` runs on Windows with the bodies of the other systems' shape; its
  tests and the `echo_server` example run on the three.
- A record of a followed socket is never freed, only used again: a report
  already posted may still name it.
- A `connect` to a port nothing listens on takes about two seconds to fail:
  Windows asks again before it gives up.
