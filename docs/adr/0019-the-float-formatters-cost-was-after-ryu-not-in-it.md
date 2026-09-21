# 0019 — The float formatter's cost was after Ryū, not in it

## Status

Accepted, 2026-09-14.

## Context

`bench/fmt_float` renders 60 000 shortest round-trip doubles. It read 40.4 ms
against Go's 6.0 — 6.7 ×, the widest gap in the corpus, and the only row where
Bun-TS was also ahead.

`bench/parse_float`, added the day before, measures the same subsystem in the
other direction and sits 1.3 × behind Go. That pair said the cost was on the
rendering side rather than in float handling generally. `bench/README.md` then
named a culprit it had not measured: Ryū and the big-integer kernel under it
(`lib/std/core/dtoa.vader`, `f2s.vader`, `bigint.vader`), several hundred lines
of pure Vader no benchmark had ever exercised.

A sampling profile of a 12 M-value run says otherwise:

| symbol | self |
|---|---|
| `vader_atom_intern` | 30.6 % |
| `vader_array_push` | 13.7 % |
| `vader_gc_alloc` | 11.2 % |
| `memmove` + `memcmp` | 12.8 % |
| `concat_2` + `join_range` | 8.6 % |
| `mul_shift_all_64` (the Ryū core) | **3.0 %** |

The arithmetic was 3 %. The presentation layer's own symbols — interning, the
array pushes, the concatenations and the atom table's `memcmp` / `memcpy` — add
up to 68 % before counting its share of `vader_gc_alloc`, which it splits with
Ryū's tuple returns. It is code that predates the `Buffer` primitive and had
never been revisited:

- `digits_of` built a `string[]` of one-char interned atoms, through two
  growable arrays;
- `join_range` concatenated them one at a time, so each digit cost an atom
  intern over a prefix the next concatenation threw away;
- `format_decimal` then concatenated those pieces again.

A 17-digit rendering cost two arrays and roughly one intern per digit, for a
result that is one intern's worth of bytes.

## Decision

Render into one right-sized `Buffer` and intern once — the shape
`primitives.vader::format_unsigned` has used since the Target-ABI work.

The width is known before a byte is written (at most a sign, `0.`, five zeros
and 17 significant digits), so nothing has to grow and std/core still needs no
`StringBuilder`, which it cannot import. `write_decimal` writes the digits
in place and `insert_point` slides the tail one byte right for the decimal
point, so the four `Number::toString` branches share one digit emitter.

## Consequences

40.4 → 10.1 ms, a 4.2 ×. The row moves from 6.7 × behind Go to 1.6 ×, and from
3 × behind Bun-TS to ahead of it.

`f2s.vader` reaches this layer through the same `render`, so f32 inherits the
change; it has no presentation code of its own.

Verified rather than assumed: the old and new code were run against 408 055 f64
renderings and 404 646 f32 ones — random bit patterns plus a structured sweep
across every branch boundary, all four `Number::toString` branches exercised —
and agree byte for byte in both. The widest rendering in that set is 25 bytes,
which is the bound `F64_RENDER_MAX` states. No `vm.snapshot` in the test corpus
moved; the 101 snapshots that did are `#line` shifts and the emitted C of the
changed functions.

What is left is the string model, not the formatter. Holding the rendered length
fixed and dropping only the final `intern_string` takes 600 k values from 91.0 to
31.1 ms: two thirds of the remainder is turning 17 bytes into an interned atom —
FNV-1a-64 over the content, a probe, a `malloc`, a `memcpy` — for a string the
workload never compares to anything. That is the standing cost of `==` being an
integer compare everywhere else, and it is the same tax `wordfreq` and
`split_join` pay. Closing it means a different atom representation (inline
storage for short strings, say), not a different formatter.

One Vader-side item does remain, and it is not in this file's subject either.
`umul128` returns `[u64, u64]` and `mul_shift_all_64` returns `[u64, u64, u64]`;
a tuple return is a heap object, so `d2d` costs three `vader_gc_alloc` calls per
formatted float against the one the `Buffer` costs. Every one of those tuples is
destructured on the line that receives it and never escapes. Removing them is a
compiler question — scalarising a tuple return whose call site immediately
destructures it — not a `dtoa.vader` one, and it would pay out wherever the tree
returns a tuple.

The hypothesis that fell is worth keeping: a pair of opposed benchmark rows
narrows a search to one direction, and that is all it does. It cannot say which
half of that direction is slow. The half this one pointed at was 3 % of the row,
and the big-integer kernel it also named does not run on this path at all — it
builds the power-of-5 tables under `@comptime`.
