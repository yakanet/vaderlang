# 0035 — A trait value carries the read-only bit

## Status

Accepted (2026-10-07). Closes the `.rodata` write that 0034 left open, and removes
the storageless-const guard that 0022 suspected was redundant. 0036 closes the two
holes left open below (a bounded `T!` and `await`), and one this change missed: a
read-only value filling the trait variant of a union (`Bump! | null`).

**Superseded by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: a type carries no rights any more.

## Context

`TraitType` had no read-only bit. A `!` written on a trait type counted only on a
parameter, through the fn type's `params_mutable`; anywhere else it was decorative.
So a value widened into a trait came out mutable whatever it had been. Take
`as_bag :: fn(c: Cfg) -> Bag = c` applied to a read-only `Cfg` from a module const:
`.poke()`, a `self!` member, then wrote into `.rodata`.

T3096 (0034) worked around the gap by counting every trait value as a mutable
level. That refused harmless read-only trait consts. And the path guard
`rooted_in_storageless_const` stayed the only thing stopping a write through a
const's own trait-typed path.

## Decision

`TraitType` carries `immutable`, with the same role as `StructType`'s. A raw
`type_from_expr` result is mutable; a written slot takes the read-only default, so
`b: Bump` is read-only and `b: Bump!` is mutable. The bit stays out of type identity
and out of the bytecode, and it is displayed as `Bump!`.

- **Reconstructions keep the bit.** Every rebuild of a trait copies it
  (`TraitType { ...t, .args = … }`): substitution, erasure, and the distinct and
  mutability strips. The field has no default and `mk_trait` takes the bit, as
  `mk_struct` does, so a rebuild that forgets it does not compile. A call to an
  `async` fn builds its `Async<T>` mutable: it starts a fresh coroutine that the
  caller owns and drives.
- **Widening keeps the rights.** A value widening into a trait value keeps its own
  rights: `mutability_widens` compares the bits between two trait values, and from
  a value into a trait value. `try_into` refuses a widening that would gain rights,
  and leaves the wording to the mismatch (T3077).
- **Factories say `!`.** `-> Async<T>!` for the async combinators, and
  `Into<Iterator<T>!>` with `fn(self) -> Iterator<T>!` on the stdlib's four impls
  (arrays, `string`, `MutableMap`, `MutableSet`).
- **A bound takes the read-only default.** It is a written type, so a diagnostic
  names `Display`, not `Display!`.
- **Narrowing to a trait keeps the rights.** Narrowing a union to a trait matches
  no variant by shape, so it is read-only when any variant is. An `as` binding over
  a call or an index carries the bit of that expression's own type.
- **One report per argument.** A read-only argument for a `!` parameter is T3072
  alone: its own top-level bit is cleared before the shape check, on the generic
  path as on the plain one.
- **T3096 counts a trait value like any other level, through its bit.**
  Separately, it now walks the *value's* own type, frozen as the const is. A trait
  annotation hides the concrete value (`BAG: Bump: Cfg { … }`), and an `is Cfg`
  test hands that value back.
- **`rooted_in_storageless_const` is removed.** No const can reach a level that
  grants mutation (T3096), and a trait level now has its bit. So the per-level walk
  always reaches a const's root.

## Consequences

Measured on 2026-10-07, at `135fe2160`:

- **The compiler** reached a fixed point in four rounds, with 12 errors on the first
  round and 13 `!` in all:
  - `std/async`: `sleep`, `join_all`, `try_join_all`, `race`, `join_any`,
    `timeout`, and the three `children: Async<T>![]` fields;
  - `spawn_async`;
  - one local of `cmd_build`.
- **Eight reconstruction sites** had dropped the bit. In the prototype that showed
  up as a false T3020: an impl recorded `Gen<Err>` and the substitution handed back
  `Gen<Err!>`.
- **On 832 programs**, `check` changes on one fixture, and only in a type's display
  (`Sink<Cfg>!`), once these were adapted:
  - three snippets that wrote a read-only trait slot they advanced or stored
    through;
  - one snippet that is fixed by `into` handing back `Iterator<T>!`.
- **Removing the guard** changed only a fixture whose const T3096 already refused.
  It lost its second diagnostic, and the fixture is deleted. No probe faults
  without the guard.

Still open:

- **The implicit array → iterator conversion** still relies on the
  `converts_to_fresh_iterator` exemption, rather than on the return type of `into`.
- **Two holes that predate this change** both write into `.rodata`, as at
  `135fe2160`:
  - a bounded `fn<T: Bump>(x: T!)` accepts a read-only argument, and its body may
    call `x.bump()`;
  - `await` drives `resume(self!)` on a read-only value without T3071, where `for`
    checks `next`.
- **Two older backend bugs** sit next to this change. Both are already wrong at
  `135fe2160`:
  - `b is Cfg` on a trait-typed parameter, followed by a field write, panics in
    `emit/bytecode/emit`;
  - a const array or tuple of trait values panics in `c_emit` ("baked struct …
    not in the module type table").
