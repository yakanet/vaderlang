# 0170: A name is resolved by a primitive of the runtime

## Status

Accepted (2026-11-22).

## Context

A client given a host name needs its addresses. The system's resolver
(`getaddrinfo`, and the same function in Winsock) returns a linked list of
`struct addrinfo`, freed by `freeaddrinfo`. Each node points at a `sockaddr` of
its family, and the order of the fields of `addrinfo` differs between Darwin
and Linux (`ai_canonname` and `ai_addr` are swapped).

Vader does not read memory behind a pointer: a `@c_struct` mirror lends a
struct to C, it does not follow `ai_next`. The resolver may also wait on the
network for seconds, so the task must park while it runs (ADR 0165).

The C runtime builds as one translation unit, and does not link Winsock on
Windows: a program that opens no socket does not depend on `ws2_32.dll`.

## Decision

- **The runtime walks the list.** `vader_resolve(host, out, capacity)` calls the
  resolver, copies each IPv4 or IPv6 `sockaddr` into a slot of 28 bytes of a
  buffer the caller lends, frees the list, and returns how many it wrote, 0
  for a name that stands for none, or a negative code when the resolver
  failed. `std/net` reads the slots with the
  decoder it already has for the addresses sockets return.
- **It is declared `@c_blocking`.** A thread of the runtime makes the call while
  the task parks.
- **On Windows it takes the resolver from the loaded `ws2_32.dll`**
  (`GetModuleHandleW`, `GetProcAddress`). `std/net` starts Winsock before the
  call, which loads it, so the runtime itself never links it.
- **An address written out and `localhost` are not asked of the system**
  (RFC 6761): they resolve with no wait and no network.

## Consequences

- The layout of `addrinfo` stays on the C side, where the headers of each
  system describe it.
- A name is given in ASCII: an internationalised name in its `xn--` form. The
  Windows resolver is the ANSI one.
- A resolver that hangs holds a thread of the runtime's pool, not a worker: the
  other tasks run.
