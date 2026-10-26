# 0064: A `for` inlines the generator its `into` is

## Status

Accepted (2026-10-15). Completes 0062: the two name-keyed fast paths it lists are
gone.

## Context

`lower_for_in` had two fast paths that knew a standard-library type by name:

- `try_lower_for_in_map_set` looked `MutableMap` and `MutableSet` up in
  `std/collections` and walked their compact-dict fields inline;
- `chars_of` made `for c in s` call `std/string::chars` and step the
  `StringChars` it returns.

The first duplicated what `MutableMap`'s and `MutableSet`'s `into` already say:
both are generators walking the dense entry arrays. The fusion already inlined a
generator's body when the `for` called it (`for x in gen(args)`); it did not when
the generator was reached through the `into` the typecheck recorded for the
iterable. A user type whose `into` is a generator stepped its state machine.

## Decision

- A `for` iterable whose recorded `into` (`IterInto`) is a generator fuses as the
  call `into(iterable)`: its body becomes the loop, `self` bound to the iterable.
  `try_descend_into_gen_source` reads the impl the typecheck recorded (the serving
  one for a member chosen against a type parameter), its signature under the
  receiver's type arguments, and the element from the substituted `Iterator<E>`.
  Nothing is looked up by name.
- Only the `for` role. An `into` recorded for a slot (`Into`, a combinator source
  or an inlined consumer's argument) is applied again when the operand is bound,
  so fusing it would convert twice.
- An impl member has no resolver symbol; its inlined instances are keyed on an id
  minted once per declaration (`impl_member_ids`).
- `try_lower_for_in_map_set`, `lower_map_set_compact` and `chars_of` are deleted.
- `string implements Into<Iterator<char>!>` becomes a generator over `byte_at`,
  stepping ASCII bytes in place and the rest through `decode_tail`. `chars` and
  `StringChars` stay, for an iterator held as a value.

## Consequences

- Writing the string walk as a generator exposed two defects of
  `runtime/c/vader.h` that every byte loop paid for:
  - `vader_trap` carried `noreturn` on its canonical declaration only. The inline
    helpers defined above it, `vader_string_byte_at` among them, called a function
    that may return, so clang reloaded from memory, in every loop holding a
    bounds check, whatever that call might have changed.
  - `vader_string_byte_at` read the length through `vader_atom_entry(s)->len`
    and `vader_string_byte_len` through `vader_atom_entries[a].len`. Clang did not
    merge the two loads before rotating the loop, so in a loop whose step is not a
    constant the bounds check of `byte_at` survived under an `i < s.byte_len()`
    condition, with a branch to the trap on every byte.
  Both are fixed in the header. The three traps are declared once, `noreturn`
  (`VADER_NORETURN`), above every inline helper. `byte_at` and `string_compare`
  read through `vader_atom_len` / `vader_atom_data`, and `vader_atom_entry`, the
  other address form, is gone.
- The generator's shape is measured. Read into a local before the loop, the length
  no longer matches the one `byte_at` checks in a split build, where the decoder is
  still a call when clang rotates the loop. Behind one shared `yield` the ASCII path
  takes two taken branches per codepoint (145 ms against 78 ms below).
- Measured on 2026-10-15, `--release`, 64 KB texts, alternated runs (native ×4000,
  VM ×40), `for c in s`, before (`d43ce70a3`) → after:

  | | native | VM |
  |---|---|---|
  | ASCII | 79 → 78 ms | 241 → 77 ms |
  | accented Latin | 95 → 103 ms | 264 → 120 ms |
  | CJK | 142 → 142 ms | 262 → 197 ms |

  Accented Latin alternates one- and two-byte codepoints; natively it stays 5 to
  10 % slower, which no layout of the branches tried changed.
- `map_iter`, `wordfreq`, `hashmap`, `split_join`, `interp`, `string_builder`,
  `str_concat`, `wordcount` and `fmt_float` A/B against `d43ce70a3`: ratios 0.96
  to 1.003, same output. Self-compilation 0.998. The lexer benchmark (6.3 MB of the
  tree, and CJK text) does not move. The compiler binary keeps its size.
- Each `yield` of an inlined generator inlines the loop body: a `for c in s` body
  appears twice in the emitted code.
- The `for c in x.chars()` loops of `lib/` and `vader/front/parser/dump.vader` are
  written `for c in x` and fuse. The one in `vader/front/parser/parser.vader` stays: a
  method call on the loop variable of `for c in s` panics at emit, before this
  change as after it (`TODO.md`).
- `string`'s `into` is the first generator member of a non-generic impl in
  `lib/`, and it showed that only the generic-impl path desugared such a member:
  the non-generic, stdlib and array impl paths lowered it as a plain body, so
  `it: Iterator<char> = s.into()` returned no value. Every site that materialises
  a body now goes through `lower_body_of`, which picks the state machine for a
  generator.
- `for c in s.into()` and `for [k, v] in m.into()` still step the state machine:
  `call_target` resolves free functions only.
