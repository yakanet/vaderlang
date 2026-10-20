# 0100: Every enum is a kept type argument

## Status

Accepted (2026-10-20). Amends 0098: an enum argument no longer erases, so a map's
enum key no longer reaches an erased slot; a trait value, a union and a call's
arguments still box it.

## Context

A generic instance keeps a type argument concrete or erases it to `Any`
(`kept_type_argument`). A primitive, a distinct over one and an integer range were
kept; an enum only when it carries variant data, since it stores its variant's
rank. A plain enum was erased, and the instances over it shared one body with every
reference type.

That body read the enum as a box, though an enum is always stored in its integer
(`u8` for almost every one). An array crossing into it broke natively:
`content_equals` on a `Color[]` read 16-byte boxes out of a buffer of bytes and
stopped on a vtable miss, and `first<T>(colors) == .Red` was false natively and
refused by the VM's checker. A generic impl reached the integer's impls instead of
the enum's: `Box<Direction>` rendered `Box 1` where `Direction` has its own
`Display`.

Three fixes were weighed:

- **Keep an enum as itself**: one instance per enum.
- **Keep an enum as its integer**: the instances over enums of one width share a
  body with that integer's. It fixes the storage, but a body shared with `u8`
  reaches `u8`'s impls, so `Box<Direction>` stays wrong unless an impl member
  observing its `T` gets a concrete instance of its own, a path that does not
  exist and whose rule the call site and the materialiser would both have to
  apply.
- **Read the buffer's kind at run time** in an erased body: narrow, but it fixes
  neither the VM nor `Display`, and adds a branch to every erased array access,
  the map internals included.

Measured on the compiler, the only enums it passes to generics are three map
values: keeping each as itself adds 23 functions (0.35 % of its C), keeping them
as their integer 16 (0.23 %). No benchmark's C changed either way.

Keeping an enum gives `Box<Direction>`, `Box<Color>` and `Box<u8>` instances of
their own, while the bytecode type table still keyed an enum by its integer: the
three shared one row, so one tag and one vtable row. A `Box<Color>` in a
`Display[]` rendered through `Direction`'s impl, and `is Box<Color>` held of a
`Box<Direction>`, a test T3087 used to refuse.

## Decision

- **An enum is kept as itself**, with or without variant data, and so is a
  distinct over one, as that enum.
- **The type table keys an enum type argument by its declaration**: a struct or
  trait instance over an enum has a row of its own, its tag and vtable rows apart
  from the integer's (`argument_keys`, `argument_hash`, `same_argument_class`).
  A bare enum value keeps its integer's row, so a union still boxes it as its
  integer.

## Consequences

- An instance over an enum reads its arrays in their integer and compares with
  integer operations, with no box and no virtual call.
- A generic impl reaches the enum's own impls, statically and through a trait
  value: `Box<Direction>` renders through `Direction`'s `Display`, and
  `is Box<Color>` tells a `Box<Color>` from a `Box<Direction>` and a `Box<u8>`.
  Two same-named enums of two modules no longer share a map instance's row.
- Code grows by an instance per enum and generic it reaches. The compiler's own
  build allocates alike, and with fixed GC arenas runs within 0.2 % of before.
  With the default sizing it ran 2.5 % longer: its three maps hold bytes instead
  of boxes, which moved the old generation's major collection later, and the
  minors of `c-emit` then rescanned a larger old generation. The sign flips with
  the young generation's ratio; the sizing is an open item of its own.
- Folding instances whose bodies compile to the same code would recover the size
  the integer variant saved, without its dispatch.
- A distinct is still read as its backing in a shared instance, so `Box<Meters>`
  renders through `i64`'s `Display`.
- `tests/snippets/generic_enum_argument` runs natively `content_equals` on a plain
  enum's array and `Box<Direction>`.
