# 0045 — A converted value takes the rights of its `into`

## Status

Accepted (2026-10-08). Closes M3, which 0035 left open. Amends 0042.

## Context

An array passed where an `Iterator<T>!` is expected converts through
`T[] implements<T> Into<Iterator<T>!>`, and the callee advances the iterator, not
the array. A provisional predicate, `converts_to_fresh_iterator`, said so at four
sites: the T3071 receiver check, the T3072 argument check, the receiver re-check
of a method-syntax call, and the borrow a `let` records. It answered "array into
an `Iterator`" without asking what the conversion returns.

0035 put a read-only bit on `TraitType`, so the `into` now says it in its type:
`-> Iterator<T>!` is owned and mutable.

Which `into` a conversion goes through was not settled either. The lowering
looked it up by name on the source type, the impl on its own instance first:

- With `MonType[] implements Into<Label>` in scope, an array reaching an
  `Iterator<MonType>!` slot called the `into` toward `Label`. The run trapped on
  `Iterator.next`.
- With `MonType[] implements Into<Iterator<Label>!>`, it called that one and
  iterated labels as `MonType`s, with no error.

The impls on one instance had a related fault: two impls of one trait on
`Wrapper<MonType>` gave their members one mangled name. A conversion toward
`Tag` ran the body converting toward `Label`.

## Decision

**A value reaching a slot through an implicit conversion takes the rights of the
`into` it goes through.** `converts_to_owned` asks whether that `into`'s return
grants mutation. The four sites ask that instead.

**The `into` of an implicit conversion is chosen by its target.**
`into_method_toward` takes the impl of the exact pair (source, target) first.
Failing that, it takes the generic impl of the source's base toward the target's
base. Only a generic impl is recorded under that second key: its pair names a
type parameter no conversion carries. The rights checks read this member, and the
lowering calls it. Acceptance still goes by shape (`try_array_to_iter`).

For a conversion, this amends 0042's per-trait rule. An impl on one instance
toward `Label` does not hide the generic impl toward `Iterator<T>`, because their
targets differ.

**Two impls of one trait on one instance name their members apart.** The second
one declared in a module takes `$1`, the next `$2`
(`instance_overload_suffix`), at the call site and in both materialisers. An
impl on a whole type already did this, with `_1`. No type name carries a `$`, so
on the VM `Wrapper<Mon>`'s second impl cannot take the name of `Wrapper<Mon_1>`'s
first. The C backend writes every byte outside an identifier as `_`, so there the
two names still meet. The build then fails with a C redefinition error instead of
running the wrong body. That C naming scheme is lossy for every mangle.

**An array impl member is materialised for the member the call chose.** A call
records the element together with the member (`ArrayMemberUse`). The array
materialiser no longer picks a winner per trait.

## Consequences

Measured on 2026-10-08, at `ae38edcf7`:

- **On 848 programs**, diagnostics and typed ASTs are unchanged.
- **Four faults of implicit conversions are gone**, VM and native alike. Two
  snippets pin them (`array_into_by_target`, `into_impls_on_one_instance`).
  - The trap above.
  - The `Iterator<Label>` conversion taken for an `Iterator<MonType>` one.
  - A conversion through either of two `Into` impls on one struct instance ran
    one body.
  - A conversion through an impl of `Into` on a concrete array panicked at build
    (GATE B1), unless the program also converted that array to an `Iterator`.
- **The first impl of a trait on an instance keeps its mangle**, so no existing
  snapshot moved.
- **The rights rule changes nothing observable today.** `core`'s impl returns
  `Iterator<T>!`. A probe with a read-only `-> Iterator<T>` instead was refused
  where expected: T3072 on a const array passed to a `!` parameter, T3071 on its
  method-syntax call.

Still open:

- **The rights rule covers an array reaching an `Iterator` slot only.**
  - A read-only `MutableMap` reaching an `Iterator<[K, V]>!` slot is T3077, though
    its conversion also returns a fresh iterator.
  - An array converted through a user `Into` toward a `!` slot
    (`Into<Label!>`) is T3072.
- **A conversion into a declared slot** (`buf: Iterator<i32>!: LIST`) is judged
  only on the borrow it records. Its rights against the slot are not checked
  through the `into`. No conversion reaches it with a read-only result today.
- **A generic `Iterator<T>` slot ignores an array's own `into`.** The target
  recorded for it is the unbound `Iterator<T>`, which no exact pair matches. So
  `xs.map(f)` converts through core's `into` even when `MonType[]` implements
  `Into<Iterator<MonType>!>`. The free call `map(xs, f)` is T3001: the exact pair
  is found, then its `Iterator<MonType>` is compared with `Iterator<MonType!>`.

- **Two impls of one trait on one instance are told apart on conversions only.**
  A method call (`w.into()`), a trait value (`v: Into<Tag>: w`) and a `for` over
  two `Iterator` impls run the first impl's body, as they do for two impls on a
  whole type.
- **A generic `Into` impl on a struct** is still refused by a coercion (T3010).
  Even if accepted, the lowering would call the bare `into`.

Iterator fusion used to take an array heading a chain for its own elements,
skipping such an `into`: silently with `Into<Iterator<MonType>!>`, with a build
panic toward `Iterator<Label>`. It now declines that array, and the call that is
not fused converts through the chosen `into` (snippet `array_own_into_not_fused`).
