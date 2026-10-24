# 0107: The young halves swap only when to-space receives survivors

## Status

Accepted (2026-10-22). Amends
[0104](0104-a-young-survivor-is-promoted-at-its-first-collection.md): its last
consequence, the swap at every minor.

## Context

Since 0104 a minor promotes every survivor into the old slab. Young to-space
receives an object only when the old reservation cannot take it, or when
`VADER_TENURE_AGE` is built above 1. The minor still swapped the two halves every
time, so allocation alternated between them and both stayed resident: up to the
adaptive young cap per half (`VADER_GC_YOUNG_CAP_DEFAULT`, 192 MB) for a half that
held nothing but dead objects and forwarding headers.

Keeping the same half changes how long a forwarding header lives. With the swap,
the evacuated half stayed intact until the next minor, so a pointer held across a
collection read a stale but complete copy. Without it, the allocation that
triggered the minor lands on what the minor abandoned.

An audit of every reader of a forward found none that reads one after the
collection it triggered. Each runtime helper that allocates roots its arrays in a
box and reloads them after the allocation; the `vader_array_resolve` calls sit at
the entry of their helpers, before anything can collect; the emitted code passes
headers read from rooted locals and frame temps. Two places depended on the swap:

- The C emitter's header cache (the `_slotarrK` locals, `is_cache_safe` in
  `vader/emit/c/walker.vader`) let a header bound before a `fn.addr` be reused
  after it, although the first `fn.addr` a program runs collects
  (`vader_ffi_callback_first_escape`). The reused header pointed at the abandoned
  copy and read the right bytes by chance. This was a latent bug under the swap
  already.
- `vader_young_grow_to` pointed to-space at the new block and counted on the
  minor's swap to make it from-space before freeing the old block. With every
  survivor promoted there is no swap, and from-space would have stayed on the
  freed block.

Options set aside:

- **A counter that keeps the swap** while some runtime code needs a forward after
  a collection it can trigger. No site needs it, and it covers neither a stale
  pointer passed by a caller nor the emitter's header cache.
- **Keeping the swap and giving the idle half back to the system**
  (`MADV_DONTNEED`, `MADV_FREE`, `DiscardVirtualMemory`). Right after the minor it
  has the same danger as not swapping, worse under macOS where `MADV_FREE` leaves
  the content indeterminate, so a stale read fails only sometimes. At the start of
  the next minor it is safe but does not lower the peak, and every minor faults a
  whole half back in.

## Decision

- `vader_minor_collect` swaps the young halves only when to-space received
  survivors. Otherwise it resets from-space to its base, and the other half is
  never written.
- `vader_young_grow_to` carves both halves out of the new block itself, from-space
  holding the survivors the minor copied, or nothing.
- `fn.addr` no longer keeps the header cache: `vm.FnAddr` leaves `is_cache_safe`.
  `tests/snippets/fn_address_between_array_reads` pins it.
- **Poison mode**, `VADER_GC_POISON=1`: at the end of every minor the young bytes
  it abandons are filled with `0xA5`. A read of an abandoned object, its forward or
  its data, meets a non-NULL absurd `forward` and an out-of-table `type_index`, and
  fails at once instead of reading a stale copy or whatever was allocated at the
  same address. It is a variable of its own, not implied by `VADER_GC_STRESS`, so
  it combines with each stress mode and also runs without one.

The poison was checked against two deliberately broken variants, never committed:
`vader_array_push_slow` re-reading its header through `vader_array_resolve` after
the allocation instead of from its rooted box, and the header cache keeping
`fn.addr`. Both ran correctly without poison (under `VADER_GC_STRESS=1` for the
first) and crashed with it.

## Consequences

- A pointer held across a collection without being rooted now reads recycled
  memory: a silent corruption in a release build, where it used to be a stale
  read. `vader_array_resolve` cannot repair it. A runtime helper that can collect
  roots its objects and reloads them from the roots, as every one does today.
- The resolving form that 0023 keeps in the runtime's own sites no longer reads a
  forward left by a collection: a site that collects reads `buf` through a header
  reloaded from a root. The only forward alive outside a collection is the one
  `vader_gc_force_tenure` leaves, until the next minor.
- The debug guard `VADER_ARRAY_RESOLVE_BUF` catches a stale header less often: a
  recycled header usually carries a NULL `forward`. The poison mode is the net:
  run the snippet corpus under the stress modes with `VADER_GC_POISON=1` when
  changing the collector, a runtime helper that allocates, or the emitter's header
  cache.
- With every survivor promoted, allocation reuses a single young half. The other
  is touched only when survivors overflow the old reservation. The RAM budget
  still reserves both halves (`young_reserve`), since to-space remains the
  fallback.

Measured on 2026-10-22 (Mac M-series, release builds, alternated runs, against the
build before this change):

| Workload | Before | After |
|---|---|---|
| Self-compile, peak RSS | 1525 MB | 1032 MB |
| Self-compile, wall time | 2.57 s | 2.48 s (−3.7 %) |
| `vader test vader`, peak RSS | 1287 MB | 974 MB |
| `arr_push` benchmark, wall time | 15.2 ms | 13.2 ms |

The other native benchmarks stay within noise. The compiler compiling itself under
`VADER_GC_POISON=1` emits the same C as without it.
