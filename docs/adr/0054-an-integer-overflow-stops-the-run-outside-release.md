# 0054 — An integer overflow stops the run outside a release build

## Status

Accepted (2026-10-11). Replaces the rule of 2026-10-10 that signed arithmetic wraps
in every mode (`docs/HISTORY.md`, "Signed overflow").

## Context

Until 2026-10-10 the SPEC promised a debug panic on a signed overflow while both
backends wrapped. That day the SPEC was aligned on the code: arithmetic wrapped
everywhere, with `-fwrapv` so that C could not assume an overflow away. A wrapped
sum is a wrong value that nothing reports, and the unsigned types wrapped too: a
`usize` index computed as `i - 1` at `i == 0` became 2^64 - 1 in silence.

Stopping the run on every overflow was measured on 2026-10-11 as an upper bound:
the native benches built `--release` with `-fsanitize=signed-integer-overflow` in
trap mode, every signed operation checked, nothing proven, median of 10 runs. Of
the 27 workloads, 18 stayed within noise and 6 slowed by 12 to 31 %; `arr_set`
took ×7.7, `arr_map` ×4.8 and `wordcount` ×2.3, where a check on an accumulator
keeps the loop from vectorising. The self-compile did not move and stopped only in
the comptime evaluator, which wrapped on purpose to fold constants.

## Decision

- An integer `+`, `-`, `*` or unary `-` written in the program stops the run when
  the result leaves its type: on the VM (`vader run`, `vader test`) and in a native
  debug build. A release build wraps. The check is on the exact type: a `u8` stops
  past 255 although it computes on 32 bits.
- `+%`, `-%`, `*%` wrap in every mode. The arithmetic the compiler synthesises
  (loop counters, offsets, sizes) wraps: keeping it in range is the compiler's job.
- A `@comptime` evaluation that overflows is `C4017`.
- Casts truncate and shifts never trap, as before.

`lower_binary_op`, the one place that lowers the arithmetic the program wrote,
turns `+` into `LoweredBinaryOp.AddChecked`; the plain `.Add` keeps wrapping, so
arithmetic a later pass synthesises wraps by default. Negation has one lowered
form, which nothing synthesises. The bytecode op is a `CheckedArith` carrying
the operation and the exact integer type, or a `CheckedNeg`. `vader/support/integer` is the one definition of when an operation
overflows; the VM, the bytecode folder and the comptime evaluator answer through
it.

Natively, the emitter writes `vader_chk_add(<type>, a, b)` (`runtime/c/vader.h`).
Without `NDEBUG` it calls a function that checks through the overflow builtins;
with it, the flag `--release` passes, it expands to the wrapping expression. The
emitted C is the same in both modes, so a split build stays reproducible. The
release form is a macro and not an inline function because clang did not
vectorise `wordcount`'s counting loop through the inline call, even marked
`always_inline`: the bench took ×2.4 until the expression was written out again.

The VM runs every checked op as a register op. Its integer type rides in a column
beside the ops (`RegFunction.kinds`). `i32`, `i64` / `isize` and `u64` / `usize`,
98 % of the checked ops in the compiler's own bytecode, have register ops that
pass their type as a constant: the C compiler then folds the check through
`checked_arith`, and a checked loop runs as fast as a wrapping one. The other
types decode it from the column, about 4 ns an op. A first version sent them
through `apply_boxed`, at about 26 ns an op: the digit loop of integer formatting
and most of float formatting paid it. A leaf
holding checked arithmetic is still inlined; its trap then reports the leaf's pc
without its name.

## Consequences

- Release performance does not change: the 27 benches sit within noise of the
  wrapping compiler, the self-compile too. The VM runs the compiler's tests in the
  same time.
- A debug build of the compiler compiled the whole compiler without stopping once.
- A release build still wraps an overflow the tests never reached. The compile-time
  error where an overflow is certain, and the refusal to store into a narrow range
  without proof, come with value ranges.
- `-fwrapv` stays: the wrapping operators lower to the C operator on a signed type.
