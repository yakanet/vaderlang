# 0180: A constant the compiler can compute is folded, in every module

## Status

Accepted (2026-11-25). Builds on 0119 for the constants left to the run time.

## Context

`MODE :: Mode.Fast` and `DEBUG :: VADER_OS != .Windows` were read at run time, so
an `if` on them kept its dead branch and every function only that branch called.
`if VADER_OS == .Windows` is how code that depends on the target is left out of a
build, the `#ifdef` of Vader.

The comptime pass already baked the constants written without `@comptime`, in
every module, but it evaluated them without a view of the project: a variant, a
struct literal or a constant of another module, `VADER_OS` included, made it give
up. The lowering made up for part of it by reading the source of a constant whose
value was a literal, a check on the syntax that had to grow one form at a time
(`.Variant`, then `i64(0)`, then `char(0xFFFD)`). The `@comptime` constants and
the `@assert` conditions were evaluated without the project too, so
`@comptime Mode.Fast` ran on the comptime VM and came back as its integer.

## Decision

- Every comptime evaluation reaches the project. The `@comptime` constants of all
  modules are evaluated first, then the others, each on demand in the module that
  declares it, once. The lowering reads the value and no longer looks at the
  source.
- The tree-walk compares variants, converts an integer into a `char`, and
  evaluates an `if` written as a value, the taken branch alone.
- A plain constant whose value holds a struct is still built by the lowering from
  its source: baking it moved the route of 27 snippets' constants.
- A plain constant the tree-walk cannot compute stays a run-time constant,
  silently: it promises nothing. One whose computation overflows or divides by
  zero is an error, as the SPEC already said of a folded constant: every read
  would stop the program, or wrap in a release build. It is reported once, by the
  first evaluation that meets it.
- A cycle met while folding a plain constant is not such a fault: the typecheck
  reports the direct ones, and one found through a function is not certain to
  happen at run time (a valid program broke when it was tried).
- A plain constant that takes more than 100,000 evaluation steps is computed all
  the same, and the compiler warns. Steps are counted, not timed, so every machine
  reports the same.

Set aside:

- **A budget that gives up** past some number of steps: whether a constant is
  quick to compute is the developer's call, and the warning tells them.
- **Folding in the CFG**, after the lowering: function reachability is settled
  before, so the functions a dead branch calls would stay.

## Consequences

- An `if` on `VADER_OS`, `VADER_ARCH`, or a constant computed from them drops its
  dead branch and what only it reaches. The `system/posix` constants written as an
  `if` on the target are literals now.
- `@comptime` no longer buys a fold. It still guarantees the value at build time
  (an error otherwise), runs code the tree-walk cannot (loops, statements), and
  calls the host on the machine that builds.
- The seed grew by 0.1 %: the evaluator gained more than the compiler's own
  constants folded away.
