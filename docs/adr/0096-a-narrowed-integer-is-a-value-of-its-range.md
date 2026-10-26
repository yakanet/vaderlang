# 0096: A narrowed integer is a value of its range

## Status

Accepted (2026-10-19). Supersedes 0083 ("a narrowing changes no width") and the part
of 0085 that holds a narrowed range in its origin; amends 0075 on bitwise operations
and on the type of a mutable local, and 0077 on the type `acc := n * 1000` takes.

Amended (2026-10-20) by 0097: a narrowed read is taken as it is stored and converted
once, to where it goes, rather than to the range's storage where it is read; an
index and a conversion to anything but an integer still convert it where it is read.

## Context

Past `if n in Hour`, an `n: i64` was typed as `Hour` with a note of the integer it
was declared as (`RangeType.origin`): the value stayed an eight-byte one, a mutable
copy (`a := n`) was an `i64`, and a bitwise operation read it at that width, so
`~n` gave the same result inside the test as outside it.

The note was storage riding on a type whose equality ignores it, and it only held
at the top level: inside another type the range is laid out as a declared one, so
`[n, n]` is a byte array. Erasing the ranges before the lowering applied that rule
by position. Keeping the ranges in the lowering, the next step of moving storage
out of the types, would have meant applying it again, either by cleaning every type
as it enters the lowering or by keeping the note out of every type the checker
builds.

A declared range showed the same leak the other way: `~h` on an `Hour` gave 250
because an `Hour` is stored in a byte. The result of the operation depended on the
storage, which the language does not otherwise expose.

0083 had added the note for a reason: a mutable local copied from a range computed in
place took the narrowest of `i32`, `i64` holding it (0075), so past
`if n !in Hour { return }`, `micros := n * 3_600_000` was an `i32` and a later
`micros = micros * 1000` stopped the program, where the same code without the test
computed in `i64`. Dropping the note brings that back, for a declared range as it
already was.

## Decision

- **A narrowed integer is a value of the range, as a value declared of it is.**
  Past `n in Hour`, `n` is an `Hour` and `i64(n)` gives the declared integer back. A
  read of `n` there converts it to the range's storage.
- **A local takes the type of its first value, a range included, mutable or not.**
  `next := h + 1` is a `1..=24`, `a := n` an `Hour`, `micros := n * 3_600_000` a
  `0..=82_800_000`. Assigning a value outside it is **T3063**, whose detail says to
  write the type the local may hold (`micros: i64 = n * 3_600_000`). What 0083
  guarded against is now a compile error. The rule of 0075, the base `i32` or `i64`
  of a range computed in place, is gone.
- **A bitwise operation needs an integer of a fixed width.** `&`, `|`, `^`, the
  shifts, `~` and the wrapping operators are **T3115** on a range of no machine
  integer's bounds, declared or narrowed. Converting the operand names the width:
  `~i64(n)`, `u8(h) & 1`. A machine integer, a range of its bounds, keeps them. A
  shift's count, whose width changes no result, may be a range.
- `RangeType` has no origin any more: a range is its bounds and, for display, its
  name.

## Consequences

- Programs that relied on the old rules on a refinement now fail to compile:
  - a bitwise operation on a narrowed or declared refinement is T3115;
  - a mutable local started from a range and given a value outside it is T3063
    (`count := b` then `count += 1`); writing its type fixes it (`count: i32 = b`).
- A value narrowed to the bounds of a machine integer is that integer: past
  `n in u8`, `acc := n` is a `u8` (it was the `i64` `n` was declared as), and
  `acc = acc * 2` stops the program once `acc` passes 127, as on any `u8`. That one
  change is not a compile error.
- The compiler and the parts of the library it builds needed no change.
- The ranges can stay in the lowering with no rule of position: a range is laid out
  the same wherever it sits.
- The compiler loses the code that carried the note: the origin of a join or an
  operation, the base a mutable local took, the reading of a range at its origin.
