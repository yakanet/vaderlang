# 0153: A driver reads a decorator as written; its value stays in the compiler

## Status

Accepted (2026-11-16). Supersedes the part of
[0152](0152-a-decorator-is-a-declared-type.md) that has a plugin decode a
decorator as a typed value.

## Context

A decorator has two readers: a build driver, which runs in a process of its own
and receives the declarations over the protocol
([0148](0148-vader-serves-a-driver-process-one-build-at-a-time.md)), and reflection at compile time
(`@decorator(f, T)`, `@decorated(T)`), which runs in the compiler.

Handing a driver the value as a typed `Route` means carrying a value of a type
the protocol does not know across a process boundary. Generic decoding cannot do
it today: a generic body is checked once, with `T` opaque, so `T {}` is
rejected, `@field(x, f.name) = v` is no assignment target, and a field without
a default cannot be filled at all. Doing it anyway takes a trait every
decorator type implements by a compiler-made impl, a conversion primitive, a
model of constant values and its codec: a second road to a value reflection has
at hand, typed, where it is computed.

## Decision

- **A driver receives the structure.** Every decorator written above a
  declaration, a field or a parameter crosses with it, as written: its alias,
  its name and its arguments as expressions, spans included. A `@comptime`
  argument crosses as the expression it is written with.
- **The build names its module.** `Decorator.module_name` holds the module that
  declares it, as the type checker resolved it, so a driver tells `http`'s
  `Route` from another without resolving the imports itself. It is empty for a
  decorator of the compiler.
- **The value stays in the compiler.** Code a driver generates reads it through
  reflection, where its type is concrete and its evaluation already done.

Rejected: a typed value in the driver (above); an untyped value, a model of
constants like `JsonValue`, which can still be added if a driver must decide on
a computed value at build time; asking for decorators as a vaderdoc is asked
([0149](0149-a-driver-asks-its-build-for-what-does-not-cross.md)), since they are
small, belong to the head of a declaration, and a filter by decorator needs them
on the build's side anyway.

## Consequences

A literal argument (`@json_name("user_id")`) is read as written. A check on a
computed value (two routes on one path) goes into the generated code, as an
`@assert`, or waits for reflection. The protocol grows by the decorators of the
delivered modules only, and the codec it already has carries their arguments.
