# 0014 — The interpreter's cost is the buffer resolve, and the hoist that would fix it is disabled

## Status

Accepted (2026-09-05). Investigation only — no code changed.

**Amended by [0015](0015-the-interpreters-buffer-resolve-is-worth-thirteen-percent.md)
(2026-09-06)**: the 23 ns/op is one workload's figure rather than the interpreter's
speed, the lever this record files as its main one is measured at ~13 %, and the
`gc_alloc` count below does not reproduce (195, not 786). The write-barrier count
here is CORRECT — 0015 first disputed it and was itself wrong. The fourth
hypothesis below is confirmed and then some: the dispatch is a jump table, ~1 cycle
of a 22-35 cycle op, so the chain is never walked at all.

## Context

`@comptime` folding of `std/core/dtoa_tables` costs ~80 ms on every build of any
program that reaches `std/core`, which is every program. That is ~70 % of the
compile of a trivial one. Asking where it goes leads to the interpreter, and the
answer took four wrong hypotheses to reach — all four recorded below, because
each is a plausible thing to try again.

## What was measured

**The interpreter runs at ~100× native.** The same big-int workload, run both
ways with process startup cancelled by differencing two iteration counts: 11.8 ms
per table build under `vader run`, 120 µs compiled. Roughly 23 ns per VM
operation, ~90 cycles.

**The tables are built about seven times, not once.** `build_pow5_split(326)` and
`build_pow5_inv(342)` each run twice — `DOUBLE_POW5_SPLIT_LO` and `_HI` recompute
the same table and differ only in the `even_words` / `odd_words` they apply — plus
the f32 pair. `dtoa_tables.vader`'s own header says why: an un-baked `@comptime`
const referenced inside another `@comptime` block gets its RHS re-inlined per
loop iteration. So the duplication is deliberate, and the ~7× is a compiler
limitation rather than an authoring mistake.

**Each interpreted instruction performs ~3.3 array accesses.** Static count over
the emitted dispatch region: 963 buffer resolves, 966 bounds checks, 489 write
barriers, across 292 arms. Every access re-resolves the array's buffer — a null
test, a `header.forward` test for a moved object, a bounds test, then a double
indirection through `buf->slots` plus the offset. Around 15-20 machine operations
per interpreted instruction before any useful work, which is the shape of the
~90 cycles.

**The optimisation that would remove this exists and is measured at 9× elsewhere,
and it is switched off here.** `bce_hoist.vader::bh_try_hoist` pins an array's
resolve outside a loop only when the body is "BCE-safe (no alloc / impure call /
yield / rebind)". The interpreter's dispatch loop holds 786 `gc_alloc` calls
spread across its 292 arms; one is enough to disqualify the whole loop, even
though the hot arms allocate nothing. The safety condition is sound — a
collection can move a buffer, so a pinned resolve would go stale — but it is
evaluated per LOOP while the hazard is per PATH.

## Decision

Record and stop. Nothing is changed: the fix is a `vader/lower` change to the
granularity of a safety analysis, which is a cross-pass decision, and it is not
on the path of the work in flight.

Nobody should read the 9 × as a prediction for the interpreter. It is the figure
for array loops whose bodies were nearly all resolve; the dispatch loop does real
work between its accesses, and the share that would be recovered was not measured.

## Consequences

Three shapes are on the table when this is picked up, in rising order of reach:
extract the hot, provably alloc-free arms into an inner loop the existing hoist
already accepts; re-establish the resolve after each allocating arm rather than
refusing the loop; or teach `bce_block_unsafe` to reason per path. Only the first
needs no change to the analysis.

The ~7 × duplicated table builds are a separate and cheaper lever, in the same
place: it needs a `@comptime` const to be referenceable from another `@comptime`
block by its baked value rather than by re-inlining its RHS.

## Four hypotheses that were wrong

Each was plausible, each was measured, each is written here so it is not tried
again from scratch.

**Values are boxed on the hot path.** They are not. The stack is tagged —
`payload: i64[]` beside `tag: StackTag[]` — and `I64Add` adds in place. Locals
are tagged the same way. Deterministic check: a 100 000-iteration scalar loop
allocates **zero bytes**, cast included. `peek_val` does build an `I64Val`, but
the hot arms do not call it.

**Opcodes are decoded per execution.** They are not. `instr :: body.body[frame.pc]`
reads a pre-decoded array; the `vader_gc_alloc` per opcode in the emitted C
belongs to the reader, once per instruction of the PROGRAM.

**The dispatch chain is the cost.** It is not. A prototype over the real 145 arms
with the real tag values and a real opcode frequency mix measured the if-chain
against a `switch`: **1.70 ns versus 1.71 ns, 1.00 ×**. The hot opcodes already
sit at chain positions 0, 1, 2 and 6, so the frequency-weighted mean is 19
comparisons, well predicted; a jump table trades those for a less predictable
indirect branch. An earlier claim of "~146 comparisons, potentially an order of
magnitude" came from an extraction that mixed in nested matches and was wrong.

**A narrow local forces the boxing path for the whole function.** The mechanism
is real — `cur_has_narrow` is read per FUNCTION from `fn_narrow_tbl`, so one
narrow slot puts every `local.set` in that function through `peek_val` — but it
was not what a measurement appeared to show. The +14 % attributed to it came from
adding a `u32` local, and `is_narrow_valtype` covers only `u8` / `i8` / `u16` /
`i16`. Re-measured with an actual `u8`: within the machine's ±8 % run-to-run
drift, so nothing was shown either way. Making the check per slot may still be
right; no measurement supports it today.

## A note on the instrument

Wall-clock on the machine this was measured on drifts ~8 % between runs, which is
wider than most of the effects being chased — one "baseline" moved from 178 ns to
191 ns within ten minutes. Three of the four wrong hypotheses above survived as
long as they did because they were read off timings. What settled each of them in
the end was deterministic: a static count in the emitted C, an allocation counter,
or a prototype run to a stable 1.00 ×. Prefer those here.
