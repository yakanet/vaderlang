# 0062 — The lowering no longer rewrites `bytes()` by name

## Status

Accepted (2026-10-14). Removes the `bytes_view_elision` pass mentioned by 0029.

**Completed by [0064](0064-a-for-inlines-the-generator-its-into-is.md)
(2026-10-15)**: the two name-keyed fast paths named below are gone.

## Context

`s.bytes()` returns a read-only `u8[]` view over a string's interned bytes. Natively
it allocates a 40-byte array header, and since `bytes` may collect, the function
calling it keeps a GC frame; on the VM it builds an `ArrayVal` that reads the bytes
in place (0029). Two lowering steps saved that cost for the shapes the tree used:

- `fold_bytes_len` (`lower/call.vader`) turned `s.bytes().len()` into
  `byte_len(s)`;
- `bytes_view_elision.vader` turned a local view used only for `.len()`
  and `[i]` into `byte_len` / `byte_at` reads of its string. That local was often
  one the lowering makes itself: `for b in s.bytes()` becomes a counter loop over a
  synthetic `for_arr :: s.bytes()`.

Both found `bytes`, `byte_len` and `byte_at` by looking their names up in
`std/core`. An optimisation must not know a standard-library function by name: it
belongs to a shape of code. Expanding syntax into library calls is another matter:
interpolation and string `+` name the functions they become. Two name-keyed fast
paths remain to remove: the `for` walk over a `MutableMap` / `MutableSet`, and
`for c in s` stepping through `chars`. Both passes also covered only some shapes:
a view sliced, or passed to another function, kept its header.

Since 0061 the tree reads a string's bytes in place: `byte_len`, `byte_at`,
`byte_slice`, `std/string::matches_at`, and `for i in 0..<s.byte_len()` for a byte
loop. The `s.bytes()` calls left hand a real `u8[]` to code that takes one
(`push_all`, a file write, base64, crypto, tests).

## Decision

- Delete `bytes_view_elision.vader` and `fold_bytes_len`. `s.bytes()` is an
  ordinary call everywhere.
- A string's bytes are read from the string. The byte loop is
  `for i in 0..<s.byte_len() { b :: s.byte_at(i) }`. `bytes()` hands
  the bytes to code that takes a `u8[]`.

## Consequences

- Measured on 2026-10-14, `vader dump --stage=bytecode vader/tools/cli/main.vader`, six
  alternated runs, median: 3.583 s with the passes (`a98dfc8f1`, runs 3.41 to
  3.74 s), 3.459 s without (3.39 to 3.64 s).
- User code that still writes `for b in s.bytes()`, or indexes a held view, pays
  the header and the GC frame once per `bytes()` call, and reads each byte through
  the array path. On 4M calls over 10-byte strings, natively: 32 ms against 11 ms
  for the `byte_at` loop.
- The general way to win that back is `midir/escape.vader`, which already keeps a
  non-escaping `ArrayNew` off the heap: it would need to see a host call that the
  intrinsic manifest marks as returning a fresh header. The collector marks the
  string a heap view reads; a view kept on the stack would leave the string to be
  rooted by its own local.
