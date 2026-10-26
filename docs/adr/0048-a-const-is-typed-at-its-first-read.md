# 0048: A const is typed at its first read

## Status

Accepted (2026-10-08).

## Context

The typechecker infers an unannotated module const's type when it checks the
const's value (`check_const_value` writes `decl_types`). A walk checked the
consts in file order, in two passes:

- the consts whose value needs no fn body, before the fn bodies;
- the other consts, in the main loop, interleaved with the fns.

A read that came before the const's turn found no type and read `?`:

- `INNERS :: [ONE]` above `ONE :: Inner { .n = 7 }` was an `?[]`;
- a fn reading `MADE :: make(4)` declared below it saw `MADE` as `?`.

`check` accepted both programs, and `build` panicked in the emitter (`no field
`n` on `?``). A cycle (`A :: B + 1`, `B :: A + 1`) was not reported at all. Its
program compiled and printed nothing.

## Decision

**A const read before its turn is typed at that read** (`settle_const_read`, in
`vader/front/typecheck/const_walk.vader`).

- Each walk tracks every const of its module (`TypedProgram.const_walk`). It is
  typed once per walk: at its turn, or at the first read before it, whichever
  comes first. Checking a const twice in one walk is not idempotent. The second
  check reads the type the first one wrote as its expected type, and drops an
  array literal's `!`.
- **The two passes are gone.** Typing at the read makes the early pass over
  body-independent values unnecessary: every const is typed in the main loop or
  at a read.
- **A const is typed after the consts its value reads** (`settle_with_reads`).
  The order comes from a depth-first walk over the reads the value names directly
  (`const_reads`), kept on an explicit stack. Typing each read on demand would
  nest one typing per link: a chain of 2 000 consts (`C0 :: C1 + 1`,
  `C1 :: C2 + 1`, …) overflowed the compiler's stack.
- The value is typed as at module level. The reading fn's state is set aside
  during the check, then restored: its `FnContext`, the callee being typed, the
  enclosing impl, the overloaded-argument depth, its loops and its narrowings.
  Otherwise a const first read inside `if U is Inner { B.n }` was typed `Inner`
  for good, and a `break` in a const's value broke the reader's loop.
- Its diagnostics go to the walk's own list, not to the one the read was handed. An
  argument checked twice reads into a scratch sink, and a const first read there
  would have lost its errors.
- **A read inside the const's own value is a cycle: T3099**, reported once per
  const. Three exceptions:
  - a read inside a fn body needs only the type, and an annotation writes it. An
    annotated const read there is not typed at all, so
    `fact: fn(i32) -> i32 : (n: i32) -> … fact(n - 1)` is accepted;
  - a cycle that runs through a fn body back to an annotated const is accepted.
    `HANDLERS: (fn() -> i32)[] : [() -> CONFIG.n * 2]` with
    `CONFIG :: Holder { .fs = HANDLERS }` is a dispatch table, not a cycle;
  - a cycle through a `@comptime` const is left to its evaluator, which reports
    it (C4009, or C4001 when the other const cannot be evaluated).

Rejected alternatives:

- **A topological order of the consts alone.** A const that calls a fn also
  depends on that fn's inferred return type, which a sort over the consts does not
  see. The order above only arranges the reads it does see; the typing at a read
  covers the rest.
- **A fixpoint over the const pass.** It needs `check_const_value` to be
  idempotent first.

## Consequences

Measured on 2026-10-08, at `e007309a1`:

- **On 848 programs**, diagnostics are unchanged. The `@comptime` cycle fixture
  keeps its single C4009.
- **Self-compile** typecheck time is unchanged: 502 → 504 ms (minimum of 5
  alternated runs).
- **A chain of 20 000 consts** checks in 1.10 s, against 1.05 s at `e007309a1`
  (which typed most of it `?`).
- **Programs fixed:** forward reads from a callee, a receiver, a `for`, `in`, an
  index, a generic body, an impl member, an overloaded argument, a default value
  and a trait default body. Several gave a false T3032 or T3068. Direct cycles
  (`A :: A + 1`, `L :: [L[0]]`) crashed the compiler and are now T3099.
- **Coverage:** snippet `const_read_before_its_declaration` (native parity), and a
  fixture for T3099.

Still open:

- **A cycle through a fn with a written return type is not seen.** In
  `A :: f()` with `f :: fn() -> i32 = A + 1`, typing `A` does not type `f`'s
  body. The program overflows its stack at run time.
- **A const's value may `return`.** The value is inlined at its reads, so the
  `return` leaves the reading fn.
