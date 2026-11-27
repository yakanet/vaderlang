# 0185: A frozen value is shared without copy or lock

## Status

Accepted (2026-11-26). Not implemented yet.

## Context

A value read by many tasks and written by none has two ways across a gate
today, both costly at scale:

- a `Shared`, whose readers take its lock one after the other, though none of
  them writes;
- a `deep_copy` per task, at about the speed of memory for flat data and about
  25 ns per object for a graph of structs (measured 2026-11-26).

The frozen values of 0067 (module constants, `bytes()` views, variant data)
already pass every gate: nothing may write them, which the effect summary
checks. They are all known at compile time. A value built at run time, such as
an index loaded at start and rebuilt every hour, has no such form.

## Decision

- **`freeze()` turns a value into a frozen one at run time.** It is then read
  by any task, without copy and without lock, and written by none: a write
  through it is a compile error, as on a module constant.
- **Frozen against mutable becomes part of what a user sees.** The compiler
  tracks it on the value, as it tracks the frozen values of 0067; a type still
  says nothing of what may be written (0067 holds).
- **The collector promotes a frozen value to the old generation once**, at the
  `freeze`: it is a publication (0184). Every worker then reads it in place.
- **`AtomicRef<T>` holds a frozen value** and swaps it whole: the way to
  publish a new version while the readers keep the one they loaded.

## Consequences

- A read-mostly structure is built mutable, frozen, then shared; a change is a
  new value published through an `AtomicRef`, never a write.
- The gate check gains a fact, "frozen", which lets a value pass where a
  written one would be refused, and its error messages can propose `freeze()`
  next to `deep_copy`.
- Whether `freeze` copies, or takes the value over when its builder is done
  with it, is decided with the implementation: the gate check already knows
  when a value is given away.
