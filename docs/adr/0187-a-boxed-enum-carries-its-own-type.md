# 0187: A boxed enum carries its own type

## Status

Accepted (2026-11-27). Amends 0098: the tag of a boxed enum names the enum, no
longer the integer that stores it. Range types and distinct types keep their
representation's tag.

## Context

Under 0098 a scalar entering a boxed slot took the type-table row of its
representation. For an enum that row was its integer's, so a box could not
tell `Color.Green` from the `u8` 1, nor from `Fruit.Pear`. Three consequences
followed: `Color | u8` and `Fruit | Color` had to be refused (T3151); the
generic `Equals` of two enums of one width answered `true` across types; a
trait call on a boxed enum reached the impl of its integer before its own, and
a union holding an enum could not dispatch through a trait at all (T3086).

## Decision

- **A boxed enum is tagged with a row of its own**, one per enum, that names
  the enum and records its storage integer. Every engine reads the row as a
  type: natively the box's tag, on the VM a value that wraps the integer with
  the row, in WASM a box type of its own, a subtype of the integer's box.
- **Tests, dispatch and equality read that row as the enum.** `is u8` is false
  on a boxed `Color`; a trait call reaches the impl the enum declares; `Equals`
  across two enums answers `false`.
- **An enum's built-in `Equals` and `Hash` get impls.** Lowering synthesises
  `self == other` for each enum, guarded like a written `Equals`; the hash is
  the integer's, which the enum's row points at. The dead ones are dropped by
  the bytecode, not by lowering.
- **A constant holding a boxed enum records the enum.** A data-pool leaf can
  carry a row, so a table of enums read as `any` keeps their type.
- **The VM unwraps at the boundary.** A call that takes the integer bare
  through a function value or a trait unwraps its arguments on entry, as the
  cast back to the integer does.

## Consequences

- `Color | u8` and `Fruit | Color` are ordinary unions. T3151 keeps the range
  types and the distincts; T3086 keeps the distincts and the arrays of enums,
  whose elements are stored unboxed.
- A WIT result whose ok side shares a tag with the error no longer needs a
  wrapper struct when that side is an enum.
- Every program carries the synthesised `Equals` of its enums through
  lowering; the bytecode keeps only those whose row a box carries.
- Range types and distincts are the next step: a distinct needs its own row in
  the same way, after deciding whether a generic instance keeps the distinct.
