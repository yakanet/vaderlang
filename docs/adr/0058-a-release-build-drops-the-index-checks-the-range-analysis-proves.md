# 0058: A release build drops the index checks the range analysis proves

## Status

Accepted (2026-10-13). The elision step of the range analysis in midir, whose
observation phases and call summaries ADR 0055 records. The lowering's own proof
(`bce_prove`), which it covers, is retired.

## Context

Every array access the native code makes checks its index, `--release` included,
unless the lowering proved it safe (`bounds_safe`, set by `bce_prove` for a
foreach over the array and a fused iterator, and by `try_pool_struct` for a
pooled struct constant's `pool[k][0]`). The range analysis proves more: on
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
  checks every access, so it would pay for nothing, and a debug build keeps its
  checks without paying for the analysis. The choice is made once for every
  native entry point (`proves_bounds`, `native_c_options` in `vader/pipeline`):
  `vader build`, `dump --stage=c`, `--seed-targets` and a build driven by
  `build.vader`. The bootstrap's stage0 → stage1 step keeps its own debug
  pipeline: stage1 runs once, to build stage2.
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
- **The lowering no longer proves bounds.** On every benchmark and on the
  compiler, a release build emits the same C without `bce_prove`: the range
  analysis proves every access it did (and on every snippet, example and seed
  target). Its tagging pass, the `bce_recheck` markers and its per-site lines in
  `$VADER_OPT_REPORT` go: the range analysis reports totals there, and each
  site's verdict under `vader dump --stage=ranges`. Its purity memo stays, for the
  push cache.

## Consequences

- A release build pays for the pass: on the compiler, about 150 ms and 330 MB
  allocated once its allocations were cut (`11fa404f1`) and the lowering's proof
  retired, which leaves it more functions to analyse. `vader run`, `vader test`
  and debug builds pay nothing.
- The compiler itself is built in `--release`, so the whole test suite runs on a
  compiler whose own proven accesses are unchecked.
- The seed is emitted with `--release`, so the next regeneration drops proven
  checks too. The call summaries are whole-program: a `@target` body that shortens
  an array on one target only can change a proof in a shared module, and with it
  how many seed units the targets share.
- A debug build checks again the element a foreach or a fused iterator reads (63
  checks across the C snapshots, 219 in the compiler), and so will stage1 once
  the seed carries this change. Nothing that ships or is benchmarked is a debug
  build. The lowering still marks a pooled struct
  constant's `pool[k][0]`, safe by construction; those are the 507 marked accesses
  the range analysis does not prove.
- Turning a proven checked operation into a wrapping one, and a certain fault into
  a compile error (D18 of the type-system work), remain separate decisions.
