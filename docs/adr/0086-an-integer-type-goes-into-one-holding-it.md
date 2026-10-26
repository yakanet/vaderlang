# 0086: An integer type goes into one holding it

## Status

Accepted (2026-10-19). Step 7 of the type-system charter, its seventh part continued
(D10). Extends to the primitives the widening 0075 gave the ranges.

Amended (2026-10-20) by 0097: the slot is no longer noted on the expression; the
CFG build converts a value where it fills a slot.

## Context

A range went into any integer type holding its values (0075), but a primitive did
not: a `u8` into an `i32` was T3001 and `u8 + i32` T3017, though every `u8` is an
`i32`. Integer types are ranges of `Int`; the integer primitives are the ten whose
bounds the compiler knows. The charter (D10) asks for the same inclusion between
them.

Two hazards came with it. Overloads: `min` has an `i32` and a `usize` form, and a
`u8` now fits both (a range already did, and `min(h, h)` was T3032). Function
types: a value of `fn() -> Hour` went into a `fn() -> i32` slot, and the function
was then called as one returning an `i32` while it returned a byte.

## Decision

- **An integer primitive goes into an integer type holding every value it has**,
  wherever a value goes into a slot: an argument, a return, a field, a local, an
  array or tuple element, a union through such a member. The lowering converts at
  the slot (0085).
- **Inclusion between two primitives is strict.** `u64` and `usize`, `i64` and
  `isize` have one set on every target the compiler has, but C names them apart
  (`uint64_t`, `size_t`), and a `@c_header` check would see the difference; they
  hold neither the other.
- **Mixed operands take the integer holding the other**, for arithmetic, a
  comparison, an equality and a bitwise operation alike; T3017 when neither does
  (`u32` and `i32`, `u64` and `usize`).
- **Where paths join**, an integer primitive goes into another integer type of the
  paths holding it, as a range already did (0085): `if c { b } else { i }` is an
  `i32`, not `u8 | i32`.
- **Among overloads**, after specificity, the parameter holding the argument most
  tightly wins: its own type first, then the narrowest integer holding it, a union's
  variant included. `min(b, b)` on a `u8` calls the `i32` form.
- **A function type takes no widening of an integer it takes or gives back**: both
  sides hold it in the same integer. `fn() -> Hour` is a `fn() -> u8`; it is no
  `fn() -> i32`. A lambda written against an expected type still adopts it.
- **A union keeps its tags**: a value of `u8 | null` carries the `u8` tag it was
  built with, and nothing re-tags it on the way, so it is no `i32 | null`. Only a
  bare integer goes into a union through a wider member. The same held for ranges
  (`Hour | null` into `i32 | null` was accepted and misread natively).
- **The typecheck notes the slot on the expression.** Where a value fills a slot
  holding it in another integer, the check that accepted it records the slot's type
  on the expression (`integer_slots`), and the lowering converts at the node. A
  slot the lowering recomputes is not always the one the typecheck saw: a generic
  `T` before its instance, a member's declared parameter, an operator's impl. The
  conversion at the slot (0085) stays for the paths that know their slot.
- **A primitive beside a range holding it is read as the range of its values**:
  `b + r` with `b: u8` and `r: 0..=300` is `0..=555`, where it was T3017.
- `char`, `bool`, the floats and the distinct types are left as they are: a `char`
  into a `u32` and an `f32` into an `f64` are still written.

## Consequences

- No conversion is written for a widening anymore; the tree's existing casts stay
  valid and are not swept.
- A container still does not widen (`u8[]` is no `i32[]`): a container is shared
  by reference, and no element is converted on the way.
- An argument's closeness ranks above an exact arity, so an overload set that
  differs both in width and in arity resolves by width first. A concrete overload
  taking a wider integer now beats a generic one binding the argument's own type,
  as it already did for a range: specificity comes first.
- Overloads are still ranked on the first argument, and a generic call still binds
  `T` from the first argument that names it: `min(b, u)` with a `u8` and a `u32`
  picks the `i32` form and refuses `u`, where `min(u, b)` compiles.
- `??` does not join: its fallback must fit the left operand's non-null type, so
  `maybe_u8 ?? i` with an `i32` is still T3001.
