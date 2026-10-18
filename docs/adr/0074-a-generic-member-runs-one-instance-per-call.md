# 0074 — A generic member runs one instance per call

## Status

Accepted (2026-10-18). Step 5 of the type-system charter (D1). Builds on 0070 (a
generic call instantiates its callee afresh).

## Context

A member of a trait or an impl may declare type parameters of its own
(`conv :: fn<U>(self, x: U) -> string`). The typecheck instantiated them at each
call, like any generic function's, but the lowering never did: an impl member with
type parameters was skipped where the impl's members are lowered, and the call named
a member that did not exist, which stopped the build. On a generic impl the member
ran erased, `@type_name(U)` printing `U`.

Three ways to compile it were weighed:

- one instance per call, as a generic function, refused on a value whose impl is
  picked at run time;
- one erased body shared by every call, usable by a vtable too, but wrong wherever
  the body observes `U` (`@type_name`, `@size_of`, `is`) until the representation
  analysis (D3) exists;
- both, two paths to keep.

## Decision

- **One instance per call.** A call to such a member names the instance after the
  receiver's type arguments and its own (`Box$Conv$conv__i32`), and queues it once;
  the instance is lowered at the types the call gives the member's parameters and,
  on a generic impl, those the receiver gives the impl's. A call through a bound
  (`t.conv(1.5)` in `f<T: Conv>`) records the member's own arguments in order
  (`BoundMember.own_args`), since the impl that serves the instance declares its
  own symbols for them.
- **Not where the impl is picked at run time** (T3107): on a trait value, and
  through a bound of a generic impl's parameter in that impl's members, whose body
  the impl's instances share. A vtable holds one body per member, and such a
  member has one per instance; such a member files no vtable row. Through a bound
  elsewhere, the caller observes its type parameters, as with `x is U`: its
  instances, and those of the functions handing it theirs, stay concrete.
- **An impl's member may test its own type parameters** (`x is U`): it runs one
  instance per call. Handing the impl's parameters to a function that observes
  them is refused (T3087), since the impl's instances share the member's body.

## Consequences

- `Bag.make(1)` on `Bag<f64>` is an instance of its own (`make__f64__i64`) rather
  than the shared body of the struct's instance.
- A trait with a generic member can still be used as a bound and as a trait value
  for its other members.
- On a union, a member with type parameters of its own is not found (T3008).
- On an array impl (`T[] implements<T> Conv`), the element binds the impl's
  parameter only: the member's own stay quantified for each call.
