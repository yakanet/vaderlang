# 0043 — The index forms dispatch and check like the call they are

## Status

Accepted (2026-10-07). Closes two of the items 0041 left open. Its two open
items are closed by 0047.

**Superseded in part by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: its rights half, a type carrying no rights any more.

## Context

0041 judged every index write as the `set_at` it calls, and left the index
forms refused where the equivalent call was accepted:

- **A trait value.** With `store: IndexSet<string, i32>!`, `store.set_at("a", 1)`
  passed and `store["a"] = 1` was T3008. A read through `Index<K, V>` was T3008
  too.
- **A destructuring place.** `[c["a"], c["b"]] = …` typed each place as a READ
  before judging it as a write. Through a `C: IndexSet<…>!`, which has no
  `Index`, that was T3008, while `c["a"] = 1` passed. On a `MutableMap` the
  place took the read's `V | null`. The source was then checked against that, so
  `[m["a"], m["b"]] = [a, 2]` with `a: i32 | null` stored a `null` into a map of
  `i32`.
- **A union of two `IndexSet` receivers.** The third item turned out not to be an
  index problem. `target.set_at(…)` on such a union is T3008 as well: a method
  call on a union receiver is not dispatched at all.

Working on these exposed a wider hole: an index key was never checked against
the trait's key type `K`, on any receiver. A free literal key was pinned to `K`
on an own impl only. So `m["nope"] = 1` on a `MutableMap<i64, i32>` compiled and
ran. Through a bounded `T`, `c[9000000000]` was cut to `i32`.

## Decision

**A receiver that dispatches through the trait itself indexes through it.**
`dispatched_index_args` covers both a type parameter bounded by `Index` /
`IndexSet` and a value of that trait. It records the dispatch on the index
expression, so the lowering emits the virtual `at` / `set_at` it already emitted
for a bounded `T`. Reads and writes share it.

**A key is checked against `K`, for every receiver, read or write.**
`index_key_expected` gives the key type, the dispatched trait's or the own
impl's. It pins a free literal, and `reject_index_key` refuses any other key that
is not assignable to it (T3001). An array or a string still takes an integer.

**A destructuring place is a write.** One check, `index_write_slot`, gives the
slot of every write form: an array's element, else the `IndexSet` value of a
dispatching receiver or of an impl. The slot is recorded on the place, which the
lowering reads to type the element it writes. Before the source is typed, a place
offers that slot as its expected shape (`place_slot`), never the `Index` read.

## Consequences

Measured on 2026-10-07, at `400e8bc4f`:

- Six T3008 in the new snippet `index_through_trait_value` are gone. It runs the
  same in the VM and natively.
- `[m["a"], …] = [a, …]` with `a: i32 | null` into a `MutableMap<string, i32>` is
  now T3063.
- **On 848 programs**, no diagnostic changes; two typed ASTs do (the destructuring
  places above). Typecheck time is unchanged (release builds, minima 490.0
  against 493.3 ms).
- **The key rule in the compiler** found five sites, all from one declaration:
  `binding_scrutinee: MutableMap<i64, …>`, keyed by `span.hash()`, a `u64`, as
  every other span table is.

Still open:

- a method call or an index on a union of receivers that all implement the trait
  (T3008);
- `k in c` on a value of `Contains<K>` (T3043), where `c.contains(k)` passes: the
  operator path only dispatches through a bounded `T`.
