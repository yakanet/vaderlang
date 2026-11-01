# 0123: An array buffer's slots start on a 16-byte boundary

## Status

Accepted (2026-10-31).

## Context

A buffer's slots started 40 bytes into it, and the collector places objects on
8 bytes. Whether the slots sat on a 16-byte boundary therefore depended on where
the buffer landed: on the young cursor, and in the old generation on the sizes of
the large regions carved before it. A vectorised loop over an `i32[]` ran about
30 % slower over misaligned slots, and a change to an unrelated allocation could
move a benchmark by as much.

Placing every object on 16 bytes (`VADER_GC_ALIGN` 16) gave the same gain, but
programs made of small objects took 8 to 18 % more memory.

## Decision

- `_pad` puts the slots 48 bytes into the buffer. `VADER_ARRAY_SLOT_ALIGN` (16) is
  asserted against the slot offset, and against the size of an array header, which
  a new array's block puts ahead of its buffer.
- A new young buffer, or a new array's block, starts on 16 bytes. When the
  cursor is 8 bytes off, the allocator leaves a filler there: an 8-byte gap
  stamped with its own type index, which the walk over young from-space steps
  over.
- A copy within young space gets no filler. A collection reorders the objects it
  copies, so padded copies could need more room than the from-space held, and the
  to-space is sized on that bound. An object promotes at its first minor, so a
  buffer stays young, 8 bytes off half the time, only while the old generation is
  full.
- The old generation's size classes are multiples of 16, and a large region's
  size is rounded up to 16, so every region and every slot in it starts on 16.
- A static buffer aligns its slots with `_Alignas`.
- Every other object keeps its 8-byte placement, and `vader_array_buf_t` does not
  declare a 16-byte alignment: no C compiler draws an assumption from the type.

## Consequences

- Measured on one arm64 machine (cycles, outputs identical): the native `bench/`
  programs `arr_set` (a vectorised loop over an `i32[]`) -30 % and `matmul` -7 %,
  the others within noise; peak memory unchanged but for `plb2_sudoku`, +6 %,
  which allocates 40 000 small arrays. Under `vader run` the same programs move
  by 2 % at most, either way. x86-64 is not measured.
- A buffer carries 8 more bytes of header, and an 8-byte filler whenever it is
  allocated young off the boundary.
- The self-compilation runs within 2 % of its cycles. Its peak memory does not
  move with a fixed young size, but grows by 18 to 25 % under the default
  settings: the slightly larger old live set crosses a step of the adaptive young
  sizing sooner. The initial young size alone moves the previous runtime's peak
  by 20 %.
