# 0117: A run-time check runs whether or not its value is read

## Status

Accepted (2026-10-29).

## Context

The dead-code pass of the mid-level IR dropped every instruction without an
effect whose result nothing read. An index, a division, a checked `+`, `-`, `*`
or a negation has no effect, so written as a statement, or read only by a
branch the optimiser removed, it no longer stopped the program: `xs[5]` on a
3-element array and `x / 0` went on, under `vader run` and in a native build
alike. The C walker already evaluated these "so the check runs whether or not
the result is read", and the bytecode peephole never folded them: the
dead-code pass was the one layer that disagreed.

Keeping them costs one thing: the element reads the compiler writes for a `for`
over an array, or for a fused iterator (`for _ in xs`, a fused `count()`,
`chain`), keep their bounds check on every turn when the loop never reads the
element.

## Decision

- An instruction that may stop the program (`instruction_may_trap`) runs even
  when its result goes unread, like one with an effect. The list is exhaustive
  over the instructions, so a new one has to say whether it can stop.
- The SPEC says it: a check runs whether or not its value is used; a `for` over
  an array reads the length once, and a turn past the end of an array the body
  shortened stops the program, whether the loop names its element or not.

Set aside:

- **A flag on a read the compiler introduced**, letting the pass drop it when
  dead. Whether the program stops would then depend on what stays alive after
  inlining, fusion and move folding: `for x in xs { xs.remove_last(); if verbose
  { println(x) } }` would stop or not with `verbose`. The flag would also have
  to cross two passes that copy an instruction's fields one by one.
- **Not reading the element when the loop binds no name.** It settles
  `for _ in xs` and leaves the fused iterators as they are.

## Consequences

- An unused `xs[i]`, `a / b`, `a % b`, checked arithmetic or negation stops the
  program as a used one does.
- Under `vader run`, a loop that ignores its element still reads it, one slot
  load per turn. A native build keeps the comparison; in release, a read the
  range analysis proves in bounds carries no check, and the C compiler removes
  the dead load.
- In release, a checked operation that wraps is still kept when unread; the C
  compiler removes it.
- When this landed, neither the C nor the bytecode of any `bench/` program moved,
  nor the compiler's own C: what pays is a loop that ignores its element, which
  the programs measured there do not write.
