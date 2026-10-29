# 0118: A comptime cycle through a function is found at the overflow

## Status

Accepted (2026-10-29).

## Context

The dependency graph of `@comptime` constants (`vader/front/comptime/deps.vader`)
sees the names written in a value. `A :: @comptime next()` with `next` reading `A`
names nothing: the comptime VM ran `next`, whose read of the pending `A` runs
`next` again, until the call stack overflowed (C4002) instead of the cycle error
(C4009).

## Decision

- A run stopped by a call past the VM's frame limit returns `StackOverflow`, its
  trap and the names of the functions on its call stack, read in `reg_run` once
  the run has stopped, outside the dispatch loop. `exec_comptime_value` hands it
  back; the other entries return the trap, as before.
- The comptime driver (`vader/pipeline/comptime_vm`) looks in that stack for the
  function of a pending constant running again below itself: a read of a pending
  constant runs its function, so the constants between the two frames form a
  cycle, reported once as C4009 with its path.
- The tree-walk evaluator, which reaches every constant of the project only for a
  `CLibrary`, keeps the constants it is evaluating as a stack and reports a read of
  one of them the same way.

Set aside:

- **Walking the bodies of the functions a value calls**, statically. It rejects
  valid programs: `build(false)` with `if use_cache { return A }` evaluates to 42.
- **An op the VM translator inserts at the entry of the functions of the pending
  constants**, trapping when one is already on the call stack. It is exact, but
  the new arm in the dispatch loop changed how the C compiler builds that whole
  function: from -1.2 to +1.9 % instructions retired on the VM benchmarks, against
  run-to-run spreads of 0.01 to 0.04 %. Three ways of writing the arm moved the
  cost without removing it, and so did a field added to `Trap`.

## Consequences

- A cycle is found 1024 frames down rather than at the first re-entry: a few
  microseconds, on the error path only. The VM's dispatch loop is unchanged.
- A cycle whose function runs about 100 000 steps per call before reading the
  constant again exhausts the comptime step budget first, and is reported as a
  run past that budget (C4002), not as C4009.
- A function of a pending constant that recurses into itself without reading a
  constant is reported as a cycle. It takes no argument (a value with arguments
  runs a function of its own), so no argument can stop it: it would overflow
  anyway.
