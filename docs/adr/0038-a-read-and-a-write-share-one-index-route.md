# 0038: A read and a write share one index route

## Status

Accepted (2026-10-07). Resolves the index item that 0033 left open.

**Superseded in part by [0056](0056-the-typecheck-records-what-each-call-site-invokes.md) (2026-10-13)**: a bounded `T`'s index
dispatch is the call-site record's member of the bound, no longer
`bounded_dispatch_trait`.

## Context

Four places decided how `x[i]` dispatches: the typecheck and the lowering, each for
a read and for a write. They did not agree.

- **A read** took an array backing first, so a distinct `Offset :: i32[]` that
  implements `Index` read its backing. Its `at` never ran, in the VM or natively.
- **A write** took the type's own `IndexSet` first. So the same `Offset` wrote
  through its `set_at` and read past its `at`.
- **A distinct over a struct** with its own `Index` was refused on read (T3008),
  though the lowering would have called its `at`.

## Decision

**One function, `index_route(target, trait_key, typed)`, decides**, and the typecheck
and both lowerings call it. It answers one of three routes for `Index` (a read) or
`IndexSet` (a write):

- `Impl`: through the type's own impl of the trait;
- `Array`: into an array, or into the array backing a distinct with no impl of
  its own;
- `None`.

Each pass asks the same question and gets the same answer, so nothing new is
recorded between them. A bounded `T` is the exception: the typecheck still records
its dispatch (`bounded_dispatch_trait`) for the lowering of the erased receiver.

- **A type's own impl wins over its backing, trait by trait.**
  - A distinct with `Index` and `IndexSet` reads and writes through them.
  - One with `Index` alone reads through its `at`, and writes into its backing at
    the backing's element type. Its write target is that slot, both when typed
    (`array_write_slot`) and when lowered (`lower_assign_target`). This holds for a
    plain write, `+=`, and a destructuring write.
  - A distinct over a struct indexes only through its own impls.
- **Indexing an array is built in.** An `Index` impl written on `T[]` does not take
  it over, and a bare array is routed without a lookup.
- **A `Range` index on an array-backed distinct slices the backing**, whatever impl
  the distinct has.
- **A write with no `IndexSet` and no array is T3008.** Before, it was accepted and
  lowered to an assignment to the `Index` read, which the backend dropped.

## Consequences

Measured on 2026-10-07, at `3c1007bd9`:

- **On 848 programs and the compiler's tree**, `check` is unchanged.
- **The behaviour changes only for a type with its own index impl.** `Offset` now
  reads `301` through its `at`, where it read its backing's `2`. `Cells` compiles
  and indexes through its `at`. The snippet `distinct_own_index` pins these, and the
  writes into `Log`'s backing, in the VM and natively.

Still open:

- **Destructuring and `for` read a distinct's backing** even when it has its own
  `Index`. They are not `Index` reads, so this ADR leaves them alone.
- **The key-type table is shared by both traits** (`index_key_types`). A distinct
  whose `Index` and `IndexSet` take different keys pins one of them wrong.
- **A write through a concrete `IndexSet`** checks the access path but not the
  receiver's own bit, as before (`m[k] = v` on a read-only `MutableMap`).
