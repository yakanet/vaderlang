# 0023 — A header never points at a moved buffer

## Status

Accepted (2026-09-28).

## Context

An array is two GC objects: the header (`vader_array_t`: length, offset, `buf`)
and the data buffer (`vader_array_buf_t`). Every emitted access opened with
`VADER_ARRAY_RESOLVE_BUF`: "if `buf` carries a forward, follow it and store the
result back". A header could meet a forwarded buffer in two ways:

1. **Inside a collection.** A minor copies the buffer and leaves a forward — but
   the same collection traces every reachable header and rewrites its `buf`.
   Nothing observes the forward once the collection returns.
2. **Outside a collection.** `vader_gc_force_tenure`, reached from an FFI lend
   (`vader_array_bytes`) once a Vader function has escaped into C, moves the
   buffer to the non-moving old generation there and then. It rewrites the one
   header it was handed; any other header of that buffer keeps the old address.

A second header of the same buffer exists only through `vader_array_slice` — the
zero-copy view `arr[lo..<hi]`. Push detaches a view into a fresh buffer; nothing
else copies a `buf` pointer.

So the per-access check existed for one case: a slice whose parent is lent to C
after a callback escaped. It cost a load, a compare and a branch at every array
access of every program, and it kept the loads of `a->buf` from being hoisted.

## What was measured

Counting `vader_array_buf_forward` calls across the test suite, the bootstrap and
the GC stress modes: zero. The case the check covered is real, though: a witness
(slice, then lend the parent through a callback-escaped extern, then read the view
before any collection) reads the abandoned copy without it — `9 1 7 2` instead of
`1002 1003 1004 1005`.

Effect of an empty guard, same toolchain, medians, outputs byte-identical (the
compiler's emitted C included):

| workload | change |
|---|---|
| VM, 7 interpreter benches (fib, loop, arr, field, str, map, shapes) | −17 % to −25 % |
| self-compile, `dump --stage=c vader/cli/main.vader` (4.32 s → 3.48 s) | −19 % |
| native `arr_rw` / `hashmap` / `map_iter` / `sort_by` / `matmul` | −37 % / −28 % / −22 % / −21 % / −13 % |
| the other 21 programs of `bench/` | −5 % to +2 %, within noise |

Tenuring at EVERY slice was measured too, and set aside: a loop slicing short-lived
arrays ran +63 % with twice the RSS (every view promotes its buffer, which then
waits for a major), and the self-compile gave back four points and 67 MB.

## Decision

- **Invariant: a header never points at a forwarded buffer** outside the runtime's
  own GC-coupled sites. The emitted `VADER_ARRAY_RESOLVE_BUF` expands to nothing in
  a `--release` build (NDEBUG), and to a trap in a debug build — so the whole test
  corpus checks it.
- **A shared buffer is never moved by a lend.** `vader_array_slice` marks the
  buffer `VADER_ARRAY_BUF_FLAG_SHARED`; `vader_array_bytes` does not tenure a
  marked buffer.
- **A shared buffer is still before any lend that needs it**, since the callee may
  collect in the middle of the lend:
  - after a callback has escaped, slicing tenures the buffer;
  - before, nothing is lent under a collection, and the first escape
    (`vader_ffi_callback_first_escape`, issued by `fn.addr`, now a GC safepoint)
    runs one minor that promotes every shared buffer, whatever its age; the rest
    of the young generation ages as usual.

  A program that never hands a function to C pays nothing at a slice.
- **With the old generation at its cap**, a buffer that cannot be promoted stays
  young. That is safe for collections, which rewrite every header; a lend of it is
  unsecured, as a lend already was when its own tenure failed.
- **The runtime's own sites** (`vader_array_resolve_buf`, the grow paths of push)
  keep the resolving form: they read `buf` after a collection they may have
  triggered themselves.

Trapping on a failed slice tenure was tried first. It turned a run with a small
`VADER_GC_OLD_MAX` into a crash in code that merely slices, where the collector
itself degrades gracefully by keeping survivors young.

Alternatives set aside: resolving only after a safepoint (a call or an
allocation) keeps the machinery for a case that is not a safepoint question;
having the lend walk every header of the buffer would need a back-pointer set per
buffer; marking only, without the promotion at the first escape, leaves a buffer
sliced before it free to move under C during a callback.

## Consequences

- **Anything that moves a buffer outside a collection must rewrite every header
  of it**, or restore the check. A compacting old generation or a concurrent
  collector would fall under this.
- A new way to make two headers share a buffer must mark it shared and, once a
  callback has escaped, tenure it, as `vader_array_slice` does.
- The first `fn.addr` a program runs costs one minor collection; what it promotes
  beyond a normal minor is the buffers sliced until then.
- `tests/snippets/extern_lend_sliced_array` pins both halves: its `early` view
  reads `9 1 7 2` without the promotion at the first escape, its `view` without
  the tenure at the slice.
- The BCE resolve-hoist (`ArrayLen.resolve_buf`, the pinned resolve in
  `emit_array_len`, and the int-range / named-bound pairing in `bce_prove` that
  existed only to set it) has no job left and is removed. What stays in the C
  emitter is the straight-line reuse of a `_slotarrK` header local: the local is
  not a GC root, so it is still dropped at every safepoint. Bounds-check
  elimination for `for x in a` and fused iterators is unaffected.
