# 0158: A trait value dispatches by its instance when one type implements the trait at several

## Status

Accepted (2026-11-18). Amends [0046](0046-several-impls-of-one-trait-are-chosen-by-the-use-site.md).

## Context

`Stage<In, Out, Spec>` is generic so that the input says where a stage runs
([0156](0156-a-plugin-is-a-stage-typed-by-its-point.md)): `SourceStage` and
`BodyStage` are two of its instances. A plugin that writes a function without a
body at one point and gives the body at the other implements both, and could fill
neither: 0046 made a trait value dispatch by the trait alone, so a type
implementing a trait twice was T3097 there.

The cause lies past the type checker. A vtable row was keyed `<trait>.<method>`:
of two impls of one trait on one receiver, the row kept the first and dropped the
other in silence. The run-time `is` test read the impls by (type, trait), so
`x is Writer` held for a value implementing any instance of the trait. A union
parameter (`p: BuildPlugin | SourceStage | BodyStage`) never even reached T3097:
the first variant the value entered was enough.

## Decision

**An instance of a trait that some type implements beside another instance of
it is dispatched by instance.** The set is a property of the project's impls
(`instances_dispatched_apart`), read once every impl is recorded, so every unit
of a split build agrees on it. Only those instances: `string` implements `Index`
at two instances, and a `Map` value read as `Index<string, i32 | null>` keeps the
trait's row.

- **Its key** is the trait's key with the instance suffix of its arguments
  (`trait_instance_key`, `std_core$Mul__f64`), when they are concrete.
- **An impl member fills both rows**: its trait's, as before, which keeps the
  first impl of a receiver, and its instance's (`VtableSlot.instance_key`). A
  generic receiver reads its instance through its own arguments:
  `Wrapper<T> implements Stage<T, i64>` fills `Stage<string, i64>` for
  `Wrapper<string>`. An entry whose instance is not dispatched apart fills the
  trait's row alone (`LoweredVtableEntry.row_traits`).
- **A virtual call on a trait value** whose arguments are concrete goes through the
  instance's row (`dispatched_trait`). A call that names no instance (a union of
  implementors, an erased bound, the compiler's own `Display` or `Equals` calls)
  keeps the trait's row, as before.
- **A run-time `is` test** of a trait value names the instance
  (`trait_ref_name`), and the impl table holds a row per instance a declaration
  implements (`trait_membership_of`). It reads the same rows as the vtable.
- **T3097** now fires when the arguments a trait value names do not single out
  one impl (`dispatch_is_ambiguous`): none, or a type parameter, or two impls that
  coincide. It still fires on a `for` and on a call on a union, which name no
  instance.

Rejected: keying every generic trait by instance. It is uniform, but it splits
every shared dispatcher (`Iterator.next` for each element type) and moves every
C golden, for no program that needs it. Here a trait not implemented twice keeps
its one dispatcher, unchanged.

## Consequences

- Adding a second impl of a trait at another instance anywhere in a project
  gives that instance's dispatchers their own row; the trait's row is unchanged.
- **New coverage:** snippet `trait_value_by_instance` (a type implementing a
  generic trait at two instances, a value of each, a generic receiver, `is` on a
  union of both); fixture `t3097_trait_value_of_a_type_parameter`.
