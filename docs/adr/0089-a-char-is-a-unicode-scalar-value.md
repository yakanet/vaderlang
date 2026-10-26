# 0089: A char is a Unicode scalar value

## Status

Accepted (2026-10-19). Step 7 of the type-system charter, its seventh part continued
(`char` and its two runs). Builds on 0077 (`@min`, `@max`, `x in T`) and 0087 (a test
against runs of values).

## Context

A `char` literal is a Unicode scalar value: the lexer refuses a surrogate and a value
past U+10FFFF (L0009). Nothing else did. `char(0xD800)` made a surrogate, `char(-1)`
a value past every code point, and the code that met one had to guard against it:
`utf8_encode` wrote such a `char` as U+FFFD. The standard library built surrogates
on purpose, as `char` values, to classify and recombine UTF-16 code units. A walk of
`'\u{D7FE}'..='\u{E001}'` went through the surrogates. `x in char`, `@min(char)` and
`@max(char)` were T3110.

## Decision

- **The values of `char` are the Unicode scalar values**: two runs, `0..=0xD7FF` and
  `0xE000..=0x10FFFF`.
- **`char(x)` converts an integer, checked** as `Hour(x)` and `Weekday(x)` are: the
  program stops on any other value, in every build. A literal is checked where it is
  written (T3066). A type none of whose values is one is T3010, and so is a float or
  an enum. A value whose type decides it is not tested: `char(b)` with `b: u8`, and
  `char(u32(b))`, the cast widening with no loss. A distinct over an integer converts
  as its backing, a distinct over `char` (`Glyph(n)`) is checked as `char`, and a type
  implementing `Into<char>` converts through it.
- **Arithmetic on `char` literals gives an integer**, computed on the code points:
  `'a' - 'A'` is `32`, and `'\u{D7FF}' + 1` is no `char` until `char(…)` checks it.
- **`x in char`** tests an integer against the two runs. It narrows nothing, as an
  enum with a gap does not.
- **`@min(char)` and `@max(char)`** are U+0000 and U+10FFFF.
- **A range of `char` steps over the surrogates.** A walk written in place keeps its
  counter: where a bound does not keep it on one side of them, each turn begins by
  moving a counter on U+D800 to U+E000, and an exclusive walk ending there stops. A
  `Range` value steps through `char`'s `Step`, which jumps from U+D7FF to U+E000.
- **A UTF-16 surrogate is a code unit**, an integer: `is_surrogate`,
  `is_high_surrogate`, `is_low_surrogate` and `combine_surrogates` take `u32`.
- **Arithmetic on a `char` value stays undefined** (T3017), and `for c in char` stays
  T3088.

## Consequences

- No `char` holds a surrogate or a value past U+10FFFF, so `utf8_encode` no longer
  replaces one.
- A test against two runs, `char`'s, tests the second only past the first: a value
  of the first, U+0000 to U+D7FF, makes one comparison. Over more runs the test stays
  one condition, its size linear in them: nesting one test per run grew the C of an
  enum of 300 scattered values to 767 KB.
- A walk that hops the surrogates gives no trip count to the reservation of a `push`
  in its body: 2048 of the values it counts are skipped.
- The UTF-8 decoder hands back a code point as a `u32`, and the walks that want the
  `char` convert it, though the bytes it validated already rule a surrogate out: a
  primitive is not narrowed by a comparison yet (0076), so nothing tells the
  conversion. A walk counting widths (`len`) checks nothing. On text decoded and
  summed in a loop, the check costs 8 % natively on CJK, nothing measurable on Latin
  text nor on the VM; the benchmark suite does not move. Once primitives narrow, the
  decoder states what it validated as comparisons the conversion reads.
- The VM's `to_char` writes the code point the program's own conversion checked,
  with no second check.
