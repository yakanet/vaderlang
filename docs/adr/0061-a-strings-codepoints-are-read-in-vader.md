# 0061 — A string's codepoints are read in Vader

## Status

Accepted (2026-10-14). Amends 0046: `lib/` now implements one trait twice on one
receiver, `Index` on `string`.

**Amended by [0063](0063-one-decoding-of-malformed-utf8.md) (2026-10-14)**: the
walk steps by the bytes `codepoint_at_byte` decodes, not by the width the lead byte
announces: "the walk is unchanged" below no longer holds on malformed bytes.

## Context

A backend had to provide two codepoint walks besides the bytes of a string: `s[i]`
(the `@intrinsic` member of `string implements Index<usize, char>`) and
`s[lo..<hi]` (a dedicated IR node, `LoweredStringSlice` down to the bytecode op
`string.slice_codepoints`). The typecheck and the lowering each had a `string`
case to reach them. The C runtime walked the UTF-8 itself, and the VM delegated
to the compiler's own native slice so that both engines walked malformed UTF-8
alike. A third backend would have had to write both walks again, and the
contract for malformed UTF-8 lived in three places.

## Decision

- **A target provides three string primitives**: `byte_len`, `byte_at` and
  `byte_slice` (a zero-copy slice of the atom, bounds clamped as an array slice
  clamps them). Everything else about a string's codepoints is Vader.
- **`s[i]` and `s[lo..<hi]` are two impls in `std/core`**:
  `string implements Index<usize, char>` and
  `string implements Index<Range<usize>, string>`, reached through the general
  index resolution, which picks an impl by the key (ADR 0046). The typecheck and
  the lowering lose their `string` case, and the IR node, the bytecode op, the
  host `StringIndexAt` and their arms in every pass are gone.
- **The UTF-8 decoder moves to `std/core`** (`std/core/utf8.vader`), since `s[i]`
  decodes and the prelude imports nothing. The split of 2026-06-16 (encoder in
  the core, decoder in `std/string`) no longer holds.
- **The walk is unchanged**: a codepoint spans the width its lead byte announces,
  a stray continuation byte counts as one, and the walk stops at the end.
- **The key is the impl's**: `usize`, or a free literal. The `string` case used
  to accept an integer of any width; `s[idx]` with an `i32` index is now T3001,
  as on any receiver whose impl takes a `usize` key.

## Consequences

- `"abc"[10]` traps in `byte_at`, on both engines, with `byte index out of
  bounds` instead of `string codepoint index out of bounds`. `std/core` has no
  way to raise a message of its own.
- Measured on 2026-10-14, 12 000 `s[i]` repeated 200 times over a string of 600
  mixed codepoints, same output: natively (`--release`) 0.086 s with the C walk,
  0.066 s with the Vader one; on the VM 0.162 s and 1.373 s, each `s[i]` now an
  interpreted loop. `s[i]` walks from the start on every engine; `for c in s` is
  the walk meant for a loop.
- **`string` is an overloaded base** (ADR 0046): an erased instance would
  dispatch `Index` by the trait alone and could not tell the two impls apart, so
  `is_specialized_arg` keeps concrete every type argument built from `string`.
  `string` alone was kept already; `f64 | string`, `string[]` or
  `MutableMap<string, string[]>` now are too. On the compiler, at `f72283404`
  plus this change: 78 more instances (the `MutableMap`s whose value holds a
  `string`, two sorts), bytecode +0.6 %, binary +21 KB, and the behaviour of
  every snippet unchanged. The rule is broader than this case needs: it ignores
  which trait is implemented twice, and it looks inside nested arguments, which
  their own instances already decide for. Narrowing it is left open.
- A `Range` index on a string allocates the `Range` it passes, at each of the
  compiler's cold slicing sites.
