# 0076 — A comparison narrows a range

## Status

Accepted (2026-10-18). Step 7 of the type-system charter, its third part (D11):
narrowing a range by a written test. Builds on 0075.

## Context

0075 makes `h + 1` on an `Hour` a `1..=24`, refused in an `Hour` slot, and asks for
`(h + 1) % 24`. A program often knows more than the type: under `if h < 23` the sum
fits. Without narrowing, the only way to say so is a checked conversion, which stops
at run time for a case the test already excluded.

## Decision

- **The `is` narrowing, reused.** A comparison yields the same record an `is` test
  does (`IsNarrow`, `BlockNarrow`), detected first in `detect_is_narrow` and its block
  form. It therefore composes through `!`, `&&`, `||` and a divergent guard, and lasts
  as long as an `is` narrowing: a write, a call, a loop retire it by the same rules.
  A second mechanism with its own lifetime was set aside.
- **What narrows.** The narrowed side is a binding or a field chain whose current type
  is a range; the value compared with is a literal or a value of a range, read by its
  bounds (`h < k` with `k: 1..=5` narrows `h` below 5). Either side may hold the
  subject (`12 > h`).
- **No hole.** A range is one interval. `==` narrows to the compared values; `!=`
  removes a value at an end of the range and leaves it whole otherwise. A side no
  value reaches is `never`.
- **Ranges join where paths meet.** A true `||`, the branches of an `if` or a
  `match` and the `return`s of an inferred result join their ranges into the one
  holding them all (`union_of_paths`), rather than a union of ranges, on which no
  arithmetic is defined: `if h < 12 { h } else { h }` is an `Hour` again. A free
  literal among such branches stands for its own value. A union written in the
  source keeps its ranges apart: joining them there is a decision on written types,
  not made here.
- **Primitives untouched.** An `i32` is not narrowed: it is no range until the
  primitives become ranges later in the step.
- **A write targets the declaration.** The value of an assignment, a destructuring
  one included, is checked against the slot's declared type, as SPEC already stated,
  and no longer against its narrowed view: a literal written where `x == 23` holds
  would otherwise have been read as a `23..=23`. A destructuring write also retires
  the narrowings it makes stale, as a plain one did.
- **A negated conjunction as a guard.** `if !(a && b) { return }` leaves both `a` and
  `b` true past it, for an `is` test as for a comparison.

## Consequences

- Under `if h != 23`, `h + 1` fits an `Hour`, and a test written once types both of
  its branches.
- A value excluded from the middle of a range is not tracked: `h != 12` proves
  nothing to the type.
- A narrowed or joined range is shown by its bounds (`0..=11`, never `Morning`),
  unless it is one of the ranges it came from.
