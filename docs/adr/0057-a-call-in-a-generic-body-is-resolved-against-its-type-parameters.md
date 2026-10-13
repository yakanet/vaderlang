# 0057 — A call in a generic body is resolved against its type parameters

## Status

Accepted (2026-10-13).

## Context

A generic body is type-checked once, against its type parameters. For a UFCS call
on a receiver typed by `T`, the typecheck chose the free function that accepts
`T`, but the lowering dropped that choice and searched again against each
instance's concrete receiver. With `describe :: fn<T: Display>(self: T)` and
`describe :: fn(self: i32)`, `show :: fn<T: Display>(v: T) = v.describe()` ran
the `i32` overload for `show(1)` and the generic one for `show("s")`.

That second choice was never checked: what a generic body ran depended on the
overloads visible at each instance, and declaring one more overload anywhere
could change it in silence. It also left the call-site record (ADR 0056) with
sites whose callee was only known per instance. Direct overloaded calls already
held to the typecheck's choice; only the UFCS path searched again. Across the
snippets, the benchmarks and the compiler itself, one site depended on it: the
snippet written to pin it.

## Decision

- A call in a generic body is resolved against the type parameters, once, by the
  typecheck, and every instance runs that choice. An overload on a concrete type is
  not a candidate for a receiver typed by `T`.
- Behaviour that differs by type goes through a trait bound: each instance reaches
  the impl of its own type, an impl on the instance itself included (impl
  specialization). That route is unchanged, so the call-site record still marks an
  impl member chosen against a type parameter as settled per instance.
- The enclosing function's instances stay concrete when such a call's receiver
  mentions a type parameter: the chosen function is instantiated at the receiver's
  own type, which an erased instance does not have.

## Consequences

- `show(1)` runs the generic `describe`. Outside a generic body nothing changes:
  `1.describe()` still runs the more specific `i32` overload.
- The lowering no longer chooses a free function on its own: it runs the one the
  typecheck chose, an array operation of the same name (`clear`, `push`) included,
  and a call the typecheck dispatched to no free function (a field holding a
  function value) is never redirected to one found by name. The record has one
  callee per such site.
- Code that relied on the per-instance choice must declare a trait and bound the
  type parameter on it.
