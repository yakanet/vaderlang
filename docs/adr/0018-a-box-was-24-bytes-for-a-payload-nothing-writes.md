# 0018 — A box was 24 bytes for a payload nothing writes

## Status

Accepted, 2026-09-14.

## Context

`vader_box_t` carries a 4-byte tag, 4 bytes of padding, and a payload union. The
union's width was set by one member, `packed[16]`, a byte view reserved for a
"multi-field POD payload" that the emitter never grew: `vader_packed_<name>_t`,
the mirror struct its comment described, is emitted nowhere in the tree.

That put the box at 24 bytes, past what the arm64 and x86-64 ABIs pass in
registers. Every boxed value was therefore copied to the stack and passed by
pointer. One recursive call in `bench/tree_eval` compiled to three loads, three
stores and a pointer setup, where Go's 16-byte interface is two register moves.

The comment justifying the width said `vader_string_t` already made the union 16
bytes wide. It does not — `vader_string_t` is a `vader_atom_t`, four bytes. The
claim had been false since atom interning landed, and nothing made a reader
doubt it.

## Decision

`packed[8]`, so the union is 8 bytes and the box is 16.

Three facts said the room was reserved for nothing:

- `vader_box_eq` compares the tag and ONE eight-byte slot, so a payload wider
  than eight was already wrong for `ref.eq` before it was slow;
- no emitter writes a packed mirror struct;
- `null` is a tag with a NULL pointer, and needs no payload width.

A `_Static_assert(sizeof(vader_box_t) == 16)` now guards it, the first in
`runtime/c/`. Anything that needs more inline space needs a different mechanism,
not a wider box — a per-mirror assertion at the emission site would be the place
to bound it.

## Consequences

Measured back to back, 40 runs each, on a 2026 Apple Silicon laptop:

| workload | 24-byte box | 16-byte box |
|---|---:|---:|
| `tree_eval` | 35.2 ms | 18.8 ms |
| `closures` | 31.1 ms | 13.5 ms |
| `binary_trees` | 6.2 ms | 4.6 ms |
| `selfcompile_c` | 4 559 ms | 4 365 ms |
| `arr_push` | 14.2 ms | 15.3 ms |

`tree_eval` and `binary_trees` pass Go; `closures` goes from 3.5 × behind it to
1.5 ×. The compiler compiles itself 4 % faster.

`arr_push` looked like the one row that gave ground, at +1.1 ms in that pair. It
did not hold: a later capture of the same build read 13.6 ms, BELOW the 24-byte
figure, and the row has spanned 13.6 to 15.5 ms across captures of one unchanged
build. Its loop pushes `i32` into a packed array and never touches a box, so it
moves with the runtime's code layout rather than with anything semantic —
`-falign-functions=64` is in the tree to damp exactly that. Recorded because the
first reading was published as a real cost before a second one contradicted it.

These figures are of one machine on one day. They are here rather than in a
comment for that reason.
