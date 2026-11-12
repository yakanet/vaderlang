# 0133: An object header is eight bytes, and a forward is written in the object it replaces

## Status

Accepted (2026-11-12).

## Context

Every heap object opened with a 16-byte header: a type index, an age, a mark,
flags, and a pointer to the copy a collection made of the object. That pointer
is null for as long as the object lives, and it doubled the header of every
struct, of every array and of every array buffer.

A collection copies an object before it forwards it, and nothing reads a
forwarded object after the collection that wrote the forward, except the forward
`vader_gc_force_tenure` leaves until the next minor
([0107](0107-the-young-halves-swap-only-when-to-space-receives-survivors.md)).
What a forwarded object held is in its copy.

## Decision

- **The header is the type index, the age, the mark and the flags**: eight
  bytes.
- **A forwarded object carries a flag**, `VADER_OBJ_FLAG_FORWARDED`, and the
  word after its header holds the address of its copy, over what the object held
  there. `vader_obj_forwarded_to` and `vader_obj_forward_to` are the only code
  that knows where.
- **An object is at least sixteen bytes**, so that the word exists: an
  allocation and the size the collector gives a struct are rounded up to it.
- **The size of a forwarded object is read on its copy**: a buffer keeps its
  capacity in the word the forward takes.
- **A free slot of the old generation** threads the free list of its size class
  through the same word.
- **The C emitter names the header of a static object by a macro of the
  runtime** and writes no member of it, so the layout lives in `vader.h` alone.

Set aside:

- **The forward over the header itself**, as HotSpot has it: a reader then tells
  a header from a pointer by the shape of an address, which each target would
  have to guarantee, and the mark of a free slot would no longer be readable.
- **A four-byte header**: it saves a struct four more bytes only when a field of
  four bytes or less fills the gap behind it, which asks the compiler to reorder
  fields.

## Consequences

- A struct is 8 bytes smaller, an array buffer 16 (its header goes from 48 to 32
  bytes). An array header stays at 48: its buffer follows it in one block and
  must start on the slot alignment.
- A reader of a stale pointer no longer finds the fields of the object a
  collection moved: it finds an address where the first one was. The forward of
  `vader_gc_force_tenure` is the one such pointer a running program can hold,
  and its readers resolve it before they read.
- The bootstrap seed is regenerated before a layout changes: a seed that writes
  a header member by member does not compile against the new one.
