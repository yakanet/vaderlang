# 0029 — The VM reads a string's bytes in place

## Status

Accepted (2026-10-04).

## Context

Natively, `s.bytes()` is a read-only view over the interned bytes: a 40-byte
header, no copy. On the VM it boxed every byte into a fresh `ArrayVal` of
`I32Val`s, about 4-5 ns per byte. Code that takes `s.bytes()` once per call is
then O(|s|) per call under `vader run` and `vader test`, and a loop over such a
call is O(n²): `split` calling a byte search that re-took the view per field ran
`split_join` in 321 s on the VM before the stdlib was rewritten around it.
`char_at_byte`, `codepoint_at_byte` and `index_of` still take the view per call,
and so can any user code.

`vader/lower/bytes_view_elision.vader` already rewrites a view used only for
`.len()` and `[i]` into `byte_len` / `byte_at`, but a view passed on to another
function escapes it.

Measured beforehand: the diffuse cost was nil — `bytes_to_value` drew no sample in
the profiles of `vader test lib/std` or `vader test vader` — so only the
"view per iteration" pattern mattered.

Options weighed:

- **A.** `ArrayVal` reads from the bytes themselves until written.
- **B.** A new `Value` variant for a byte view: every reader of an array would
  have to learn it.
- **C.** Cache the last materialised copy per string: no op changes, but still
  O(n) on each new string.
- **D.** Fix the callers one by one: leaves user code exposed.

## Decision

A. `ArrayVal` (`vader/vm/value.vader`) carries `raw: u8[] | null`, the native
view `s.bytes()` returns. `offset` and `length` index into it as into `elements`.

- Reads go through `element_at`; `get_element`, the register engine's hot path,
  reads `raw` inline.
- Anything that writes or grows the array calls `own_bytes` first, which boxes the
  window into `elements` and drops `raw`. Typing already keeps a `u8[]` from
  `s.bytes()` read-only; the copy-on-write keeps the VM correct even so.
- `array.slice` shares `raw`, and `bytes_to_string` interns a raw window straight
  from the bytes.
- A view lent to an `@extern` crosses as its bytes and nothing is copied back: C
  may not write into the interned bytes natively either. Printing takes this
  path — `println` writes `msg.bytes()` through `sys_write`.

## Consequences

Measured 2026-10-04 against `8fbd2f533`, alternating:

- `char_at_byte` in a loop over a 22 KB string: 1 790 → 28 ms.
- 100 000 `println`s on the VM: 285 ms with the view copied back after each
  `sys_write`, 206 ms without.
- Thirteen VM workloads within noise (−3.9 to +2.0 %; `vm_arr`, which hammers
  `get_element`, +0.2 %); `vader test lib/std` 0.74 → 0.74 s, `vader test vader`
  16.6 → 16.6 s.
- Native code is unchanged: only the VM's own storage moved.

A site that reads `elements` directly on a raw-backed array would see it empty;
every read of an `ArrayVal`'s slots goes through `element_at` or checks `raw`.
