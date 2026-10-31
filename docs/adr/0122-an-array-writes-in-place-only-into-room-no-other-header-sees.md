# 0122: An array writes in place only into room no other header sees

## Status

Accepted (2026-10-31). Extends [0108](0108-a-slice-shares-its-parents-buffer-and-a-push-detaches-it.md).

## Context

0108 lets a slice share its parent's buffer. The data buffer's `buf->length` then
held three roles at once:

- the bound of the slots a collection scans;
- the test that told a view from an owner (`offset + length < buf->length`), on
  every push, inlined or not, and in the push cache's capacity gate;
- the owner's tail, which `clear()` and `remove_last()` lowered so that a
  collection frees what the dropped slots held.

The third role broke the first. A view taken before its owner cleared or popped
kept reading slots past the new `buf->length`, which no collection scanned: a
use-after-free once the memory was reused natively, an out-of-bounds trap under
`vader run`, whose `ArrayVal.elements.len()` carried the same three roles. And an
owner that popped and then pushed wrote in place over a slot a view still read.

Set aside:

- **Scanning to the capacity**: the dropped slots stay alive as long as the
  buffer, the leak the shrinking was there to stop.
- **Dropping the shrink**: the same leak, on every stack that pops.
- **A counter of headers per buffer**: nothing decrements it when a view dies.

## Decision

- A header writes in place only the slots `[length, capacity)`, and no other
  header sees them. A header with room left has `offset` 0 and
  `buf->length == length`, so a push tests `length < capacity` and nothing else.
- A view is born with `capacity == length`, as before.
- `vader_array_slice` marks the buffer `SHARED`, young or old. An immortal buffer
  stays unmarked: it may sit in read-only memory, and its headers have no room.
- After `clear()` or `remove_last()`, a buffer that is not shared lowers
  `buf->length` to the owner's end; a shared one keeps it, and the owner sets
  `capacity = length`: its next push copies into a buffer of its own.
- `buf->length` is only the scan bound, at least `offset + length` of every
  header over the buffer.
- The VM keeps no view of its own: `ArrayVal.elements` is an array of the host,
  and `array.slice` slices it, so the VM follows the native rule by construction.
  The bytes of a string read as a `u8[]` stay a window on the string, since a
  string's bytes cannot be kept in a field; a write or a push copies them first.

## Consequences

- An owner that pops and pushes again no longer overwrites what a view reads; the
  push after the pop copies the buffer once.
- The view test leaves every push path and the push cache's preheader.
- Measured on one machine (instructions retired, outputs identical): the native
  `bench/` programs move from -3.8 % to +0.3 %, the self-compilation by -0.6 %;
  the `bench/vm` rows from -3 % to +0.9 %. A VM program made of slices alone
  (binary search by slicing, short windows) runs 4 % more instructions: a slice
  is now a header of the host, allocated and marked.
- A buffer stays `SHARED` once marked, so an owner that sliced it once copies on
  its first push after a shrink, even if the view is long dead.
