# 0042 — An impl on one instance wins over its base's generic impl

## Status

Accepted (2026-10-07). Amended by 0045: an implicit conversion chooses its `into`
by its target, not per trait, and two impls of one trait on one instance name
their members apart. Amended by 0046: an impl on one instance hides only the
generic impls of its own trait instance, and every use site chooses among several
impls of one trait.

## Context

Several impls of one trait could cover one type, and nothing chose between them
the same way twice:

- `Wrapper<T> implements<T: A> Poke` and `Wrapper<T> implements<T: B> Poke` were
  both accepted, and one body ran for both.
- With `Wrapper<MonType> implements Poke` beside `Wrapper<T> implements<T> Poke`,
  the typechecker read the impl declared last and the lowering the one registered
  first. A trait-typed value always reached the generic one, since its run-time
  tag was erased to `Wrapper<Any>`. Which body ran depended on the order of
  declaration and on the route of the call.
- An impl on a concrete array (`i32[] implements Tag`) was refused (T3090): every
  array shared the impls `T[]` writes.

## Decision

**Two generic impls of one trait on one base that may cover a common instance
are R2030.** Bounds do not separate them: a type implementing both can always be
declared. This is Rust's rule.

**An impl on one instance — `Wrapper<MonType>`, `MonType[]` — wins for that
instance.** It is not a second generic impl. Every reader agrees:

- the typechecker's side tables key an instance impl under its own type and a
  generic impl under its base, and a lookup asks the instance key first;
- the registry hands the lowering the instance impls first (`impls_for`,
  `winning_impl`), and no generic member is materialised for an instance that
  has its own impl of the trait;
- the run-time `is Trait` table no longer gives an instance impl's trait to every
  tag of the declaration: the instance's own tag gets its row from the members
  materialised for it.

The rule is per trait. An impl on one instance replaces the generic impls of
that trait for the instance, whatever their trait arguments: the typechecker's
tables hold one member per receiver and name, so `Vec2<f64> implements Add<f64>`
also hides `Vec2<T> implements<T> Add<Vec2<T>>` from `Vec2<f64>`.

**A type an instance impl is built from is kept by the erasure kernel, like a
primitive.** The run-time tag has to tell `Wrapper<MonType>` from
`Wrapper<Other>`, including for an instance built inside a generic body, where its
argument is a type parameter. The lowering already kept primitive arguments
concrete (own body, own tag, own mangle), and a specialization on `i32` worked
through every route once the selection was fixed. `kept_argument` extends this to
any argument that is, or is built from, a type an instance impl names
(`ImplRegistry.specialized_args`, project-wide).

Two alternatives were turned down:

- **Keep the concrete tag only on a literal written out.** An instance built in a
  generic body (`fn<T>(x: T) -> Wrapper<T>`) silently took the generic impl.
- **Force monomorphisation through a call-graph analysis.** This needs a new
  fixed point across modules, over every generic fn and impl member that passes
  its type parameters on.

**Arrays follow the same rule.**

- An impl on a concrete array is an instance impl.
- T3090 is kept for a partly generic element (`T[][]`), which would be a second
  generic impl on arrays.
- Array impls are materialised per element, in the entry module as in any other.
  The entry module used to be skipped.
- For the orphan rule, an array belongs to its element's owner.

## Consequences

Measured on 2026-10-07, at `4ce6d6291`:

- **On 848 programs**, diagnostics and typed ASTs change for the two T3090
  fixtures only.
- **The compiler and `lib/` declare no instance impl**, so the table stays empty
  for them.
- **Three existing faults are gone.**
  - A user array impl in the entry module panicked (GATE B1).
  - An `Into` coercion through an instance impl panicked: it named a member the
    materialiser never emits.
  - `x is Poke` was true for every `Wrapper` when only `Wrapper<MonType>`
    implemented `Poke`, and the call that followed missed the vtable.
- **Self-compile typecheck time** is unchanged (release builds, minima 510.7
  against 507.0 ms). The exact-key lookups are skipped unless the receiver's base
  has an impl on one instance (`TypedProgram.instance_impl_bases`).

Kept conservative on purpose: the readers that ask whether an instance shares
its body with the others (`is_untagged`, T3087, `refuse_shared_instance`) still
use `kept_type_argument`. They treat `Wrapper<MonType>` as shared, so
`x is Wrapper<MonType>` stays refused although its tag is now its own.

Still open, as before this change:

- **An array reaches a trait-typed slot only for the element types a direct call
  materialised.** For any other element type, dispatch misses the vtable.
- **A generic `Into` impl is not seen by a coercion** (T3010).
- **The orphan rule does not see a trait brought in by a wildcard import.**
  R2018 on an array therefore fires only through a named import.

Not checked yet: overlap on a bare type-parameter receiver
(`T implements<T: A> …`).
