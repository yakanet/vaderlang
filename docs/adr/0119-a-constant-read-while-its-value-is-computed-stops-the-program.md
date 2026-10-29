# 0119: A constant read while its value is computed stops the program

## Status

Accepted (2026-10-29). Completes 0118, which covers `@comptime` constants.

## Context

A module constant has no storage at run time: a value the compiler cannot bake is
rebuilt where it is read. `A :: next()` with `next` reading `A` therefore called
`next` again at each read, until the call stack overflowed: a VM trap naming
`next`, a segmentation fault natively. The dependency graph of constants sees the
names a value writes, not those of the functions it calls, and a walk of those
functions rejects valid programs: `build(false)` with `if use_cache { return A }`
evaluates to 42 (0118).

## Decision

- A constant whose value runs code, a call of any kind, is built by an accessor,
  `__const_<name>`, called at each read. A global slot of the program holds
  whether the value is being computed; a read meanwhile stops the program with
  "constant `A` read while its value is computed", as a `@singleton` called while
  it initialises does.
- The lowering the comptime VM runs guards nothing: that VM refuses global slots.
  A cycle there overflows its call stack, which its driver reports (0118).

Set aside:

- **Guarding only the constants on a cycle of a static call graph**: no program
  without such a cycle would change, but the graph must model every edge (virtual
  calls, function values, a closure a singleton holds) to be sound, and a missed
  one leaves the overflow.
- **Finding the constant at the overflow**, as 0118 does: a native build has no
  handler for a stack overflow, and an inline read leaves no frame naming the
  constant.

## Consequences

- A read of such a constant costs one more call and three accesses to a global
  slot, beside the call its value already makes. No constant of `lib/`, `vader/`
  or `bench/` has such a value: the code of the compiler and of the benchmarks is
  unchanged.
- The stop names the constant read again, not the path between the two reads.
- A string interpolation calls functions, so a constant interpolating a value
  other than a literal takes the accessor too.
