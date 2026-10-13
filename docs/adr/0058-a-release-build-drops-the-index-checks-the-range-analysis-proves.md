# 0058 — A release build drops the index checks the range analysis proves

## Status

Accepted (2026-10-13). The elision step of the range analysis in midir, whose
observation phases and call summaries ADR 0055 records. It leaves the lowering's
own proof (`bce_prove`) in place for now.

## Context

Every array access the native code makes checks its index, `--release` included,
unless the lowering proved it safe (`bounds_safe`, set by `bce_prove` for a
foreach over the array and a fused iterator). The range analysis proves more: on
the compiler, 1478 of 6104 accesses beyond the 723 the lowering marks, with the
call summaries of ADR 0055 (313 without them).

What that buys was measured by eliding them in a throwaway build, on the
benchmarks in `--release`, outputs unchanged: `shapes` 19.0 → 11.8 ms, whose
`for shape in shapes` calls `area()` through the vtable, a call the lowering's
proof refuses and the call summary clears; `arr_collect` and `closures` about
−16 % and −21 %; the other workloads whose C lost a check, within ±1 %. The pass
costs about 205 ms and 410 MB allocated on a release self-compile (+3.9 %); the
compiler built with the elision is not faster, its hot loops are not array
indexing.

## Decision

- **Only a `--release` native build elides.** The VM ignores `bounds_safe` and
  checks every access, so it would pay for nothing, and a debug build keeps every
  check the lowering did not prove without paying for the analysis. The choice is
  made once for every native entry point (`proves_bounds`, `native_c_options` in
  `vader/pipeline`): `vader build`, `dump --stage=c`, `--seed-targets` and a
  build driven by `build.vader`.
- **The pass runs last in midir** (`mark_proven_accesses`), on the instructions the
  bytecode emitter receives, and marks `bounds_safe` each access proven in bounds,
  judged with checked operations that wrap, as in `--release`. A function with no
  unchecked access to an array whose length it reads is skipped: the analysis has
  nothing to prove there.
- **Calls go through the summary of what may shorten an array**
  (`array_shrink.vader`): the elision trusts it, which is what lets a call keep
  the lengths the caller knows.
- **`$VADER_VERIFY_BOUNDS` is the oracle.** It makes a native build of any mode run
  the analysis and keep each proven access's check under a message of its own
  (`VADER_ARRAY_CHECK_PROVEN`), so a wrong proof stops the run instead of reading
  out of bounds. The C parity tests run under it.

## Consequences

- A release build of the compiler pays about 105 ms more; `vader run`,
  `vader test` and debug builds pay nothing.
- The compiler itself is built in `--release`, so the whole test suite runs on a
  compiler whose own proven accesses are unchecked.
- The seed is emitted with `--release`, so the next regeneration drops proven
  checks too. The call summaries are whole-program: a `@target` body that shortens
  an array on one target only can change a proof in a shared module, and with it
  how many seed units the targets share.
- The analysis does not know the length of a constant table (`InstrDataConst`): the
  507 accesses `bce_prove` marks and it misses are all `$data_const_N[$k]`. With
  that rule it would cover the lowering's proof, which could then go, and with it
  `bce_fn_pure`.
- Turning a proven checked operation into a wrapping one, and a certain fault into
  a compile error (D18 of the type-system work), remain separate decisions.
