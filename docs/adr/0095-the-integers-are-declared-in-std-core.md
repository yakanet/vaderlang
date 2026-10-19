# 0095 — The integers are declared in std/core

## Status

Accepted (2026-10-19). Follows 0092, which made a machine integer the range of its
values; this record moves the eight names out of the compiler.

## Context

Since 0092, `u8` is the range `Int in 0..=255` everywhere in the type checker, and
any range of those bounds is a `u8`. The names themselves were still minted by the
compiler as builtin symbols of a synthetic `<builtin>` module, and the type checker
recognised them by their spelling before looking at what the resolver bound. So a
reader could not find where `u8` is declared, the editor's "go to definition" led
nowhere, and the one rule that says what an integer is lived in compiler tables
rather than in source a user can read.

## Decision

- **`lib/std/core/integers.vader` declares the eight integers** as ranges, each with
  its vaderdoc: `export u8 :: Int in 0..=255`, …, `export u64 :: Int in
  0..=18_446_744_073_709_551_615`. They reach every module as the rest of the
  prelude does.
- **The compiler no longer knows them by name.** The builtin scope stops minting
  them and `primitive_from_name` stops recognising them; an integer type is the
  symbol the resolver bound, as a user's named range is. What stays builtin is
  `Int`, the floats, `bool`, `char`, `string`, `void`, `null`, `CPointer`, `Self`
  and `type`.
- The compiler still builds the integer ranges by their bounds where it gives a
  type of its own: the `i32` of a bare literal, a length's `i64`.

## Consequences

- Hover and definition on an integer name lead to its declaration and vaderdoc.
- A program built without the standard library has no integer types.
- A test that type-checks a source without `std/core` declares the integers it
  names (`with_integers` in the type checker's tests).
- Paths that only accepted a builtin symbol as a type learnt the general case, a
  constant that names a type (`names_a_type`): the comptime evaluator
  (`@comptime alias :: i32`, `accept_type(i64)`), a write through a type
  (`i32.zero = 1` is T3082, `i32 = 2` says it names a type), the frozen-value
  walk. The resolver walks a type parameter's default (`<Step = i32>`).
- The editor no longer renames what the library declares: renaming `i32` would
  have rewritten `std/core` and every use of it.
- For the orphan rule, an integer belongs to `std/core` like any type it declares,
  where it used to belong to every module.
- No generated code changes; the compiler compiles itself with 0.4 % fewer
  instructions.
