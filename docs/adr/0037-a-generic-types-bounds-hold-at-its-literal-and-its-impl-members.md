# 0037 — A generic type's bounds hold at its literal and at its impl's members

## Status

Accepted (2026-10-07). Closes the struct type-parameter item that 0036 left open,
and the `.rodata` writes reached through a bounded impl.

## Context

0036 made a bound marked `!` (`T: Bump!`) the thing that lets a generic body mutate
through a `T`. A generic call was held to its bounds (T3006). Two other places bind a
`T` and were held to nothing:

- **A struct's own bounds.** `Wrapper :: struct<T: Bump>` accepted
  `Wrapper<Plain> { … }`, though `Plain` has no `Bump`. The resolver recorded the
  bound, and nothing read it.
- **A bounded impl's members.** `Wrapper<T> implements<T: Bump> Poke` gave
  `Wrapper<Plain>` its `poke`, its `+`, its `for` and its `w[i]`. Trait widening and
  `==` checked the impl's bounds through `struct_implements_trait`; every form that
  dispatches through the impl's base key did not.

The impl bounds kept trait keys, which drop the `!`, and the bound's own arguments
were never compared. So `Wrapper<Cfg> { .inner = CFG }` reached a `self!` member
through `implements<T: Bump!>` and wrote into the module const, and an impl bounded by
`Source<i32>` ran on a `Source<string>`: the VM verifier rejected it, and the native
build printed a wrong value.

## Decision

**One rule decides whether an argument meets a bound trait:** `unmet_bound_reason`.
The argument must implement the trait at the bound's own arguments, and grant
mutation when the bound is marked `!`. It answers why not, or null. Three checks
read it, and word T3006 with `unmet_bound_detail`:

- a generic call (`check_typeparam_bounds`);
- a struct literal (`reject_unmet_struct_bounds`);
- a bounded impl's member (`first_unmet_bound`, hence `struct_implements_trait`).

`ArgBound` keeps the bound's `TraitType`s with their bit. A bound argument naming
another type parameter is left undecided, as at a call.

- **A struct's bounds hold at its literal.** A literal is where a value of
  `Wrapper<X>` comes to exist, so `X` is checked there. A written type
  (`w: Wrapper<Plain>`) is not, since no value can inhabit it. The bounds are a
  project-wide table, `struct_bounds`, built from each module's own declarations.
  The resolver now records a struct's type-parameter declaration sites, as it does a
  fn's.
- **A bounded impl's member** is reached only through an instance its bounds admit.
  `reject_unmet_impl_bounds` is asked by every form that dispatches through an
  impl's base key:
  - a method (T3006);
  - an operator and `in` (T3043);
  - `for`, an index read and an index write (T3006).
- **An impl that borrows its struct's parameters** (`Wrapper<T> implements Poke`)
  holds only for what the struct admits, so its `T` carries the struct's bound in
  the project table. `satisfies_bound` reads a `T`'s bound from that table rather
  than from its module's AST, so the shape and the rights questions read one
  source.
- **A generic fn states the bounds it relies on**, as the T3006 change chose before:
  `fn<K>(m: MutableMap<K, V>)` indexing `m` writes `K: Hash & Equals`.
- **Every enum implements `Hash`**, as it does `Equals`, with no impl. A boxed enum
  carries its integer, which hashes; enum keys already worked at run time. Checking
  `MutableMap<K: Hash & Equals, V>` at its literal made that implicit fact a
  requirement.

## Consequences

Measured on 2026-10-07, at `0f09170df`:

- **The compiler** needed one bound: `add_trait_unique :: fn<K: Hash & Equals>`.
  `lib/` and `tools/` needed nothing.
- **On 848 programs**, `check` reports the same codes as before, once one
  `_diag_` snippet wrote the same bound. Only fixture details change wording.
- **The reproductions are refused** (probes on every dispatch form, in shape and
  in rights). Each passed `check` before. The rights cases wrote into `.rodata`, and
  the trait-argument case miscompiled. A borrowing impl that passes its `T` to a
  bounded fn, refused before, is accepted.
- **Typecheck time** is unchanged (release builds, minima 520 against 521 ms).

Still open:

- **Two bounded impls of one trait for one base** (`implements<T: A> Poke` and
  `implements<T: B> Poke`): dispatch keeps one body, the last recorded, whichever
  bound the instance meets. Coherence would refuse the overlap.
- **A literal written without type arguments** (`Box { .value = p }`) is typed
  `Box`, so its bounds are not checked, as before.
- **A call with explicit type arguments and no value argument** (`get<Plain>()`)
  skips its bounds, as before.
