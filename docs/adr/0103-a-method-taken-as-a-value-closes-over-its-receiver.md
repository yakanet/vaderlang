# 0103: A method taken as a value closes over its receiver

## Status

Accepted (2026-10-21). Builds on 0056 (the call-site record) and 0072 (a generic
function as a value is instantiated where it is used).

## Context

`a.f(b)` is `f(a, b)`, so `a.f` written outside a call reads as `f` with `a`
bound: `g :: p.label`, `twice(p.label)`, `xs.map(p.scale)`. The typecheck already
typed it so, as `f`'s signature without its receiver, for every route a call takes
(a free fn by UFCS, an impl member, a trait value's member, a bounded `T`'s).
Nothing made the value: the lowering read `p.label` as a struct field, and the
build stopped in the backend on a field `Point` does not have.

Three questions had to be settled:

- **When the receiver is evaluated.** At each call of the value, or once, where the
  value is taken.
- **Which overload.** At a call the arguments pick among the members several
  impls of one trait offer (`Add<i32>` beside `Add<f64>`). A value has no
  arguments.
- **Where the decision lives.** The lowering could choose the callee again, or
  read it from the typecheck's record, as every call does since 0056.

## Decision

- **The receiver is evaluated once, where the value is taken.** `g :: p.label`
  then `p = q` leaves `g` rendering the first `p`. A conversion toward a free fn's
  first parameter (an array reaching an `Iterator`) is not the receiver's value:
  it runs at each call, so each call of `xs.sum` iterates afresh.
- **The slot picks the overload.** Taken as a value, a member several impls offer
  is the one whose signature fits the function type of the slot it fills. With no
  such slot, or with several members fitting, it is T3032.
- **A generic free fn is instantiated where it is taken**: the receiver binds what
  its first parameter names, the slot the others, as in 0072. One the slot leaves
  unbound is T3069. A taken value is no alias: it holds a receiver.
- **The typecheck records it** under its own role, `CallRole.MethodValue`, at the
  field access, with what a call would record there. The lowering builds a closure
  from it: an env holding the receiver, and a lifted fn taking the member's other
  parameters that makes the recorded call (a direct call, an instance, a vtable
  dispatch, an array operation, an enum comparison).
- **The effects analysis counts the call where the value is taken.** That is where
  the receiver is lent: `W.push` on a module constant is T3072 there, whether or
  not the value is ever called.

## Consequences

- The record grows a role every reader of `all_roles()` sees: the LSP indexes a
  method value as a reference at the member's name, and the growing-recursion
  check (T3104) follows a generic one like a call.
- A static member is still called, never taken (T3093): it has no receiver to
  close over.
- A union's member is not taken as a value yet: the union's common fields keep the
  name outside a call.
