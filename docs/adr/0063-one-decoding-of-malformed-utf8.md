# 0063 — One decoding of malformed UTF-8

## Status

Accepted (2026-10-14). Amends 0061.

## Context

Nothing validates the bytes a string is made from: `bytes_to_string`,
`read_file_string`, stdin, and a `byte_slice` that cuts a codepoint all hand on
whatever they got. The walks over a string read malformed bytes three ways:

- `len` counted the bytes that are not continuation bytes, so a stray `80`
  counted zero;
- `s[i]` and `s[lo..<hi]`, the LSP line index, `cli/keys` and the lexer's L0001
  recovery stepped by the width the lead byte announces, whatever followed it;
- `for c in s`, `codepoint_at_byte`, regex and the lexer's literals decoded a
  codepoint, then stepped by the width that codepoint takes once re-encoded: three
  bytes for a U+FFFD, two for the `ø` that `C3 78` decoded to, swallowing the `x`.

Measured on 2026-10-14, the same on the VM and natively: `for i in 0..<s.len() {
s[i] }` trapped on `café!` written in Latin-1, and `"x<80>y"` in a source file lost
its `y` and its closing quote (L0002).

## Decision

- One decoder, `codepoint_at_byte(s, i) -> [char, usize]` in
  `std/core/utf8.vader`, returns the codepoint and the bytes it spans. A malformed
  run decodes as one U+FFFD spanning the longest prefix of a well-formed sequence,
  and at least one byte: the substitution of maximal subparts that Unicode
  recommends (chapter 3, U+FFFD substitution) and the WHATWG Encoding standard
  applies. Overlong forms, surrogates and codepoints past U+10FFFF are malformed.
- Every walk steps by it: `len`, `s[i]`, `s[lo..<hi]`, `chars`, `index_of`,
  regex, `cli/keys`, the LSP line index, and the lexer, whose columns count
  one per decoded codepoint, so a `Span` column and an LSP UTF-32 column agree on
  any bytes.
- It is the one public decoder. `char_at_byte` and `utf8_lead_len` go: a width
  read from the lead byte alone was one of the three readings, and two calls
  decode twice. The lexer's `advance` steps whole codepoints.
- Strings are still not validated when they are made.

## Consequences

- `s.len()` is the number of codepoints `for c in s` yields and the number of
  valid `s[i]`, on any bytes.
- A source file with malformed bytes is one L0012, at its first malformed run, with
  the count: a file saved in Latin-1 would otherwise give one error per accented
  letter. The lexer reads each run as a U+FFFD and goes on, so the rest of the
  file is still checked.
- Measured on 2026-10-14, `--release` natively and on the VM, 64 KB texts,
  alternated runs (native ×4000, VM ×40), before → after:

  | | native `len` | native `for c in s` | VM `len` | VM `for c in s` |
  |---|---|---|---|---|
  | ASCII | 36 → 3.4 ms | 85 → 80 ms | 47 → 49 ms | 247 → 240 ms |
  | accented Latin | 36 → 120 ms | 102 → 94 ms | 49 → 97 ms | 273 → 267 ms |
  | CJK | 36 → 189 ms | 293 → 142 ms | 44 → 190 ms | 246 → 262 ms |

  `len` tests the ASCII prefix a 64-byte block at a time, with no branch per byte,
  which the C compiler vectorises. From the first block holding a non-ASCII byte it
  decodes, where the old count only classified bytes; an exact count cannot do
  less without knowing the bytes are valid. `for c in s` got faster: the width now
  falls out of the validation instead of being recomputed from the codepoint.
  Returning the pair costs nothing natively; on the VM, `len` and `s[i]` step
  through `decode_tail` without building it, and `decode_tail` calls nothing the VM
  would not inline. Self-compilation is unchanged (3.51 s → 3.55 s, within noise).
- `bun run bench`, then each string workload A/B against the previous commit,
  alternated: `selfcompile_c`, `string_builder`, `str_concat`, `split_join`,
  `wordfreq`, `fmt_float` and `wordcount` do not move. `interp` takes 5 to 6 %
  more (26.5 → 28 ms): its checksum is `s.len()` on a 28-byte string that opens
  with an emoji, too short for a whole ASCII block, so every byte is walked.
- `utf8_encode` writes U+FFFD for a `char` that holds no scalar value, and the
  lexer rejects a `\u{…}` escape naming a surrogate (L0009), as it rejects one past
  U+10FFFF: what the encoder writes, the decoder reads back.
- What would make `len` cheap on any text is knowing it when the string is
  interned: the atom table reads every byte to hash it, and could record whether
  they are ASCII, or valid UTF-8 with their codepoint count.
