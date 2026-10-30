# 0121: A struct with no field is shared unless compared by identity

## Status

Accepted (2026-10-30).

## Context

A struct with no field carries nothing but its type, yet every `Foo {}` allocated
an object. The allocation itself is noise: 0.42 % of the allocations of the
self-compilation. The cost is elsewhere: a native function whose only allocation
is such a literal, even on a cold path, takes a GC frame on every call. An
`Iterator<i64>.next` written by hand and ending with `return Stop {}` ran 50 M
elements in 77 ms, against 4 ms when it returned a constant, which is why 0120
added `STOP`.

Two literals are two objects (SPEC *Identity*), and `===` is the only thing that
can tell: an FFI mirror copies by field name, no intrinsic exposes an address,
and a struct displays as its fields. `===` already refuses an operand typed by a
trait, `any`, a type parameter or `Self`, so the structs it may compare are known
at compile time.

## Decision

- The typecheck notes, per module, the structs with no field that both operands
  of a `===` or `!==` may hold, through unions, aliases and distinct types, and
  warns there: `is` tests the type. `lower_project` gathers the sets.
- At the construction of the CFG, a literal of a non-generic struct with no field
  outside that set reads one data-pool entry per type. The compiler's own
  literals go through the same construction.
- An identity comparison whose operands may hold a shared struct stops the build:
  a struct the set misses would otherwise turn a `false` into a `true` with
  nothing to show for it.

Set aside:

- **A rule of the language**, every literal of such a struct being one value,
  with `===` an error or always `true`: it changes SPEC for every program, for a
  cost that matters only on a hot path.
- **A decoration on the declaration** (`@singleton`): explicit and local, but the
  trap stays whole on a type nobody decorated.
- **A value with no payload**, the type tag alone as `null` is: the shape value
  types would take, at the price of the C emitter, the VM values, the GC, arrays
  and erased generics.
- **Sharing in the lowering**, where a literal is built: the data pool does not
  exist there yet.

## Consequences

- The compiler's C has 43 GC frames fewer out of 5386, among them the VM's
  `peek_val` and `peek_owned`. The self-compilation time does not move; the VM
  benchmark `vm_str` runs 4 % fewer instructions.
- A `===` added anywhere on such a struct makes every literal of it allocate
  again, in every module. The warning names the place.
- A generic struct with no field still allocates: the data pool keys a baked
  struct by its declaration, not by its instance.
