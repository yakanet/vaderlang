# 0098: A scalar entering any boxed slot is tagged by its type

## Status

Accepted (2026-10-20). Amends 0026: an erased generic slot, a trait value and
every argument of an indirect or a virtual call no longer keep the class tag.

## Context

0026 tagged a scalar entering a union with its own type (`retag`), because its
class on the bytecode stack does not name it: an integer constant of 32 bits or
fewer is an `i32.const` whatever its type. An erased generic slot (the `K` of
`MutableMap<Color, i32>`) and a trait value kept the class tag, so that a shared
instance would keep reaching the impls it reached before. An argument of an
indirect or a virtual call was tagged only where the parameter of the static type
is a union, though the native code boxes every one; a synthesised virtual call
(an index, `in`, an operator) states no parameter at all.

The class of a value depends on how it reached the stack, not on its type. An
enum, a range and a distinct name the type-table row of the integer they are
stored in, so a `Color` read from a variable has the class `u8`; the same variant
written as a literal is a constant, class `i32`, and so is a constant the bytecode
propagates into its single use. Natively the box takes its tag from that class,
and a primitive's `Equals` tests the other operand's tag. After
`for d in Color { m[d] = 1 }`, `m[.Blue]` missed, `s.add(.Green)` then
`s.add(Color(1))` left two elements, and so did `.Blue in c` through a
`Contains<Color>` and a constant passed to a closure built in a generic. The VM,
whose integers all ride in one value kind, was right.

## Decision

- **A scalar entering a slot of the `Any` value class is tagged with its type**:
  a union, as before, and now an erased generic slot and a trait value, at the
  places 0026 tags a union.
- **Every scalar argument of an indirect or a virtual call is tagged**, the
  receiver included, whatever its parameter declares: the function or the impl
  reached may be a shared instance that erases the parameter and reads its tag.
- A boxed scalar holds no pointer, so the native code builds it where it is
  consumed, with no GC-rooted temporary.

## Consequences

- A constant takes the tag a variable of its type already had, so a shared
  instance reaches the same impl for both. An enum with its own `Display` still
  dispatches as its integer once boxed.
- An indirect or a virtual call carries a `retag` per scalar argument in the
  bytecode. The VM drops the op, and the native code boxed the argument anyway.
- The compiler's own C changed its tag at eight sites, all `u8` constants (enum
  variants) boxed into a map's values, from `i32`'s to `u8`'s, and lost 119 of
  its 1570 rooted box temporaries. The benchmarks' C changed only by such
  temporaries and the order of one type table; neither their run time nor the
  compiler's own build time regressed.
- `tests/snippets/enum_key_equality` runs natively a map filled by a loop
  variable and read by literals, a key set by a literal and found by a
  conversion, `in` through a trait value, and a closure built in a generic.
