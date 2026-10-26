# 0049: A callback's `Self` parameter takes its own marker

## Status

Accepted (2026-10-08). The type-parameter hole it left open is closed by 0050.

**Superseded by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: a type carries no rights any more.

## Context

A trait member taking a callback over `Self` reads `Self` as the receiver:

```
Visit :: trait {
    visit :: fn(self, f: fn(Self) -> void) -> void
}
```

`substitute_self` replaced the `Self` with the receiver type at the receiver's
own rights. On a mutable receiver, the callback became `fn(Cfg!)` with an
unmarked parameter: the type lent a mutable `Cfg`, while the marker lent a
read-only one. The two readers disagreed:

- the call site judged by the marker, and refused a mutating lambda with a
  contradictory message: "`fn(Cfg!) -> void` mutates a parameter that
  `fn(Cfg!) -> void` lends out read-only";
- the impl conformance check judged by the type, and refused an impl writing
  `fn(Cfg)` (T3095: "the trait lends `fn(Cfg!) -> void`").

## Decision

**A fn type's parameter that is `Self` itself takes that parameter's marker.**
`fn(Self)` lends a read-only `Self`, and `fn(Self!)` a mutable one. An impl
writes `fn(Cfg)`, and the call site shows the slot `fn(Cfg)`.

**A `Self` nested deeper in a parameter keeps the receiver's rights**, as
before. `fn(Self![])` reads its `Self` as a leaf: `SelfType` carries no marker,
so the `!` on the element is already lost. Giving the nested `Self` the
parameter's marker would read `fn(Self![])` as `fn(Cfg[])` and let an impl hand
a frozen const to a callback that writes it.

## Consequences

- An impl writing `fn(Cfg)` is accepted. A call site passing a mutating lambda
  reports T3001 (`expected fn(Cfg) -> void, got fn(Cfg!) -> void`).
- **On 848 programs** and the 149 probes, nothing changes.

Still open:

- **A nested `Self` keeps its marker only once `SelfType` carries one**, as
  `Self!` written on the element.
