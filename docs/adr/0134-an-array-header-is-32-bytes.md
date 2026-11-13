# 0134: An array header is 32 bytes, and the tag of an element belongs to the array type

## Status

Accepted (2026-11-13).

## Context

An array header held its length, its capacity and its offset in 64 bits each,
and a word of padding: 48 bytes, for the object a program creates most.

A borrowed view of a string's bytes has no buffer, so it kept the tag of its
elements in the high half of `capacity`, beside the atom that owns the bytes.
That tag is not a property of the view: the emitter derives it from the array
type, for a view and for every other array alike.

Two properties of the 48-byte header were load-bearing without being written
anywhere:

- **No field of the header has the type of an element.** A C compiler assumes a
  store through an `int32_t*` may change any 32-bit integer it can reach. With
  the length in a `uint32_t`, it reloaded the length after every store to an
  `i32` element to check the next bound: 9 % more instructions on an in-place
  quicksort.
- **`offset` and `buf` are two 64-bit fields side by side.** An element read
  loads both, as one pair. With the offset in 32 bits, or in half a shared
  word, they are two loads: 3.5 % more instructions on a program that reads
  arrays through the VM's register loop.

## Decision

- **The length and the capacity share one 64-bit word**, the length in its low
  half. The runtime reads and writes them through accessors
  (`vader_array_length`, `vader_array_set_extent` and their kin), and so does
  the emitted C.
- **An array holds at most 2^32 - 1 elements.** A larger one traps where its
  buffer would be sized, the one place every creation and every growth goes
  through. A string already says its length in 32 bits.
- **`offset` stays a 64-bit field beside `buf`.**
- **The header has no padding**: 32 bytes is a multiple of the slot alignment,
  which the one block of a new array needs
  ([0123](0123-an-array-buffers-slots-start-on-a-16-byte-boundary.md)).
- **The type table gives the tag of an element** for each array type
  (`vader_type_info_t.element_tag`). A borrowed view reads it there, and its
  capacity holds the owner atom alone.

Set aside:

- **`length` and `capacity` as two `uint32_t`**: the reload above.
- **The capacity and the offset in one word**, the length alone: the compiler
  narrows the read of the offset to 32 bits, and the pair is lost.
- **A word more on a borrowed view alone**, for its tag: the collector would
  size an array header by a flag of the object.

## Consequences

- An array header is 16 bytes smaller.
- An append adds one to the shared word: under the capacity, the low half takes
  it without a carry.
- The runtime relies on one type table for the whole process, as the collector
  does to size an object. Two programs compiled apart and loaded in one process
  would need one table between them before they could share an array.
- A buffer still carries the tag of its elements; it could take it from the type
  of the array that reads it.
