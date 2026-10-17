# 0071 — A call carries its written type arguments

## Status

Accepted (2026-10-17). Step 5 of the type-system charter (F6), after 0070.

## Context

`f<i64>(x)` parsed as a call whose callee was a `GenericInstExpr` wrapping `f`, and
no other callee could write type arguments: `x.f<i64>(y)`, `M.f<i64>(y)` and
`Bag<f64>.make(1)` did not parse, though T3069 advises writing the argument. Wrapping
`x.f` the same way would have made every pass that asks "is the callee a member
access" (UFCS, static members, aliased modules; 18 sites in the typecheck and the
lowering) look through the wrapper first. The lowering also read the written
arguments again (`type_from_expr` on the source) instead of what the typecheck
recorded for the call.

## Decision

- **The written type arguments belong to the call: `CallExpr.type_args`.** The
  callee stays `f`, `x.f` or `M.f`. `GenericInstExpr` remains for a type, a struct
  literal's name, and the owner of a static member (`Bag<f64>.make`).
- After a name, `<…>` opens type arguments when `(`, `{` or `.name` follows the
  matching `>`.
- A call may write fewer type arguments than its callee declares: the first are
  fixed, the rest inferred. More is T3105, as is any on a function that takes none.
  On a static member they fix the member's own parameters; the type's come from the
  type it is called on.
- A generic type written with its arguments writes them all where nothing infers
  the rest (T3105): a struct literal's name, a static member's owner, a
  conversion's target (`Box<i64>(x)`, built from the call's written arguments).
- The lowering reads a call's type arguments, and a static member's owner, from the
  bindings the typecheck recorded for the call.

## Consequences

- Every pass that tests the callee's shape works unchanged on the new forms.
- The parser and typecheck dumps of a call with written type arguments lost their
  `GenericInstExpr` node.
- `f<i64>` as a value (no call) is still not parsed; it comes with generic
  functions as values (charter F4).
- A member called on a receiver still binds the impl's parameters by substituting
  the receiver's arguments, before the call: its instantiation is not recorded, so
  T3104 does not see a growth through a receiver.
