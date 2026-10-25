# 0108: A slice shares its parent's buffer, and a push detaches it

## Status

Accepted (2026-05-24). Records a design the runtime already implements; written
2026-10-25 from the design plan the decision was taken in, which this record
replaces.

## Context

The two backends disagreed on `arr[r]`. The native runtime returned a second
header over the parent's data buffer and wrote through it; both VMs (the
TypeScript one of the time, and the Vader one) copied the range into a fresh
array. A write through a slice reached the parent in a native build and not
under `vader run`, and on the VM every slice cost a copy of its range.

The native array header already had what a view needs: an `offset` into its data
buffer next to its `length`, and the buffer is a separate GC object. A second
type for views (a `Slice<T>`, a `StringView`) was rejected: one type means
nothing to learn and no conversion at a call.

What a write through a view does was the question to settle. Two models were
weighed:

- **Aliasing**, as in Go, Rust's mutable slices, or a C pointer and a length: a
  write through the view writes the parent's element.
- **Copy on write**: the first write to a view copies the range into a buffer of
  its own, so the parent never changes.

Copy on write was rejected:

- the first write to any view allocates, which a reader of the code cannot see;
- `arr[r][i] = v` would change nothing visible through `arr`, a surprise of its
  own for anyone who expects either an alias or a compile error;
- it adds a detach path to every write, on top of the offset and length the view
  needs anyway.

Aliasing leaves one hazard that Go's `append` has: growing a view in place writes
the slots just past its end, which belong to the parent or to a sibling view.

## Decision

- `arr[r]` returns a `T[]` that shares its parent's buffer, with its own `offset`
  and `length`. Its bounds are clamped to the parent's length.
- A write through a view writes the shared buffer, so the parent sees it.
- A push to a view never grows the shared buffer: it first copies the view's
  elements into a buffer of its own. Natively a view is created with a capacity
  equal to its length, so its first push takes the growing path, which
  reallocates. On the VM, `detach_array_view` copies the window out before an op
  grows the array.
- `arr[r].clone()` is how a program gets a copy it owns.

## Consequences

- A slice costs one array header, whatever its length.
- Aliasing is visible. A function that writes an array it was lent writes its
  caller's elements, slice or not.
- A young buffer that a slice shares is marked `VADER_ARRAY_BUF_FLAG_SHARED`, and
  the FFI lend path has to leave it in place: moving it would leave the other
  header pointing at the old copy ([0023](0023-a-header-never-points-at-a-moved-buffer.md)).
  Once a Vader function's address has been handed to C, slicing a young buffer
  moves it to the old generation first, which copies it once.
- `s.bytes()` returns the same `u8[]` shape, borrowed from the string's interned
  bytes, which no write may reach: SPEC §5, *Frozen values*, rejects writing it
  at compile time.
