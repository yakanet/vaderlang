# 0015 — The interpreter's buffer resolve is worth 13 %

## Status

Accepted (2026-09-06). Amends [0014](0014-the-interpreters-cost-is-the-buffer-resolve.md) —
its measurements, not its decision. Investigation only ; no code changed.

**Superseded in part by
[0016](0016-a-guards-continuation-is-duplicated-by-the-structurer.md) (2026-09-06)**: the
doubling described below is real but is NOT the C emitter's — it is already in the
bytecode. The counts stand ; the attribution does not.

⚠️ **Corrected the same day, in place, twice.** The write-barrier count below was WRONG
and 0014's was right — see "The correction, and how the instrument lied" at the end. And
**every static count over `exec_entry`, in this record and in 0014, is DOUBLE**: the C
emitter tail-duplicates the whole loop body into both branches of `if is_comptime`
(`exec.vader:1062`), so the region holds two copies of the dispatch. Counted per copy
rather than halved — copy 1 is C lines 5880-16927, copy 2 is 16929-27987, and they are
symmetric: **469 forward tests, 469 bounds checks, 244 barriers, ~96 `gc_alloc`, 28
`stack_ensure`, 58 `peek_val`, 147 arms**. The 147 is the same 147 source tests this
record quotes for the jump table.

**Neither copy is dead.** A counter in copy 1 alone reports 2 666 041 ops on a `build` and
the same on a `run`; a counter in both reports 80 666 883 on that run. Copy 1 is the
comptime path, copy 2 the normal one — phase-separated hot code, not dead code, and
`exec_entry` is 39 266 lines of assembly. Measured ratios are unaffected (they compare two
builds of the same shape); only the counts are.

The measured 13 % ceiling stands — it was obtained by deleting code and rebuilding, not by
counting. Full audit, with the levers this record's own lever now ranks behind:
[`.claude/plans/2026-09-06-vm-runtime-audit.md`].

## Context

0014 named the buffer resolve as the interpreter's cost and parked the fix as a
cross-pass change to `bce_block_unsafe`'s granularity. Before spending that, the
question worth asking is what the fix would actually buy — a figure 0014 does not
give, having deliberately refused to extrapolate its 9 × from array loops.

Re-measuring produced the ceiling, and along the way one of 0014's static counts
turned out not to reproduce.

## What was measured

**One static count does not reproduce.** Same instrument 0014 used — a count over
the emitted `--release` C, region `vader_vm_exec_entry`, 23 257 lines:

| | 0014 | measured |
|---|---|---|
| buffer resolves | 963 | 945 |
| bounds checks | 966 | 945 |
| write barriers | 489 | **488** ✅ 0014 was right |
| `gc_alloc` | 786 | **195** |

The first three are 0014's, confirmed — the resolve and bounds figures differ by a
region boundary drawn differently, and the barrier count is exact. Only `gc_alloc`
does not reproduce, and it was not recoverable: not over the whole `vader_vm` TU
(1253 / 1267 / 1227), and not under any neighbouring pattern tried
(`vader_ref_box`, `vader_obj_header_init`, `vader_box_obj`, ref loads), nor under
any uppercase or macro spelling.

So 0014's "15-20 machine operations per interpreted instruction" stands: with 488
barriers over 945 accesses, roughly every second access carries one, and the
barrier is a real third of the preamble.

**23 ns per VM operation is one workload's figure, not the interpreter's speed.**
Exact op counts, from a temporary counter in the dispatch (20.0 ops per iteration,
to the unit), and wall time differenced between two iteration counts so process
startup and the compile cancel:

- scalar loop: **7.8 ns/op**
- loop with array reads: **9.5 ns/op**

0014's 23 ns/op came from a big-int workload dense in allocation and array
traffic. Per-op cost moves by 3 × with the op mix.

**The whole preamble is worth ~13 %.** Measured as a ceiling: the compiler's C was
emitted, the 945 forward tests deleted from `exec_entry`, and the result rebuilt
through the same chain. A third variant additionally deleted the 945 bounds
checks. Medians of 9:

| | scalar | array |
|---|---|---|
| reference | 7.83 ns/op | 10.00 ns/op |
| no forward test | 6.83 (**−12.8 %**) | 9.09 (**−9.1 %**) |
| no preamble at all | 6.83 (−12.8 %) | 9.09 (−9.1 %) |

**The bounds check costs nothing** beyond the forward test — the branch is
predicted and never taken. Only the forward test pays.

## Decision

Still record and stop. What changes is that the trade is now explicit: the lever
0014 files as its main one buys **~13 % of VM run time**, for a cross-pass change
to a safety analysis — which must additionally learn the constraint below.

**A second staleness source, which 0014 does not name.** It frames the hazard as
GC alone ("a collection can move a buffer"). But `stack_grow` does
`frame.payload.push(0)`: the frame's own columns REALLOCATE. A pinned resolve
goes stale from growth, not only from a move. It is amortised — the stack grows
to the deepest frame and then never again — so it is cheap to detect, but any
hoist has to.

Where a hoist would apply: 97 % of the dispatch's frame-array accesses are two
fields, `frame.payload` (210 sites) and `frame.tag` (202). Those two are the
whole target.

## Consequences

An implementation would land inside the measurement's own noise band. The first
attempt at the ceiling had the fully-stripped variant running SLOWER than the
partly-stripped one (430 ms against 400) — code layout, dissolved by moving to
medians of 9, but it sets the bar: distinguishing a real 13 % from layout luck
needs the differenced-iteration instrument, not a wall-clock reading.

The remaining 87 % is not in the dispatch — it is in boxing (15 % of a real compile's
allocations, 53 % of a trivial one, from `peek_val`/`push_val` on `ArrayGet` / `ArraySet` /
`Convert` / `Return`), in a GC shadow frame built for `stack_ensure` on every push
(−11/−13 %), and in calls (13 to 25 ops each). The audit ranks this record's own lever
FIFTH of seven. 0014's fourth hypothesis was measured
in a standalone prototype rather than in situ, which left the question open; it is
now closed the same way, twice independently. `cc -O3` canonicalises the 147
source-level `if` tests into switches and lowers them to a **three-level
jump-table cascade** — `sub` / `cmp` / `ldrh` / `br`, six indirect branches in
`exec_entry`, the 145 `Op` tags being dense over 707-851 with no gaps. Dispatch
costs roughly **1 cycle of a 22-35 cycle op**, and degrading it deliberately
(`-fno-jump-tables`, a 7-deep binary search) costs only +2.0 c/op. The chain is
never walked, so 0014's "19 comparisons" and its rebuttal are both moot.

The one lever there is arm ORDER: LLVM cuts the cascade at 64 comparisons, so arms
1-64 pay one indirect branch and 129-147 pay three. A frequency-sorted order
measures **−1.8 %**, two-sided (an anti-optimal order is +2 to +5 %) and monotone
across three workloads. Pure source reordering, no semantic risk — and the 20
hottest ops fit in the first 64.

Where the 87 % actually is: the arms' own work, and CALLS. A call+return costs
**~80 ns at its cheapest and ~165 ns for an 8-local callee — 13 to 25 ops'
worth** — which every measurement in this record missed by using call-free loops.

## The correction, and how the instrument lied

This record first claimed **12** write barriers and that **no write barrier exists
anywhere in the tree's emitted C**. Both are false. The real count in `exec_entry`
is **488**, and **1302** across the emitted tree.

The cause is worth more than the number. The barrier is a MACRO,
`VADER_WRITE_BARRIER` (`runtime/c/vader.h:1025`), and the search that produced the
12 was `vader_[a-z_]*barrier[a-z_]*` — **lower-case only**. It matched nothing, and
"matched nothing" was read as "there are none" rather than as "the pattern is
wrong". The 12 came from a different construct entirely (`vader_array_ref_store`,
the guarded ref stores), which is a real thing but not the barrier.

That is the same failure this project has recorded twice before: an absent trace
taken as evidence of absence. 0014's own closing note says the deterministic
instruments are what settled its four wrong hypotheses — a static count is only
deterministic once the pattern is known to match SOMETHING. A count of zero is a
result that has to be earned, by finding the construct first and counting second.

**What survives unchanged:** the 13 % ceiling, the 7.8 / 9.5 ns/op figures, the
`stack_grow` reallocation hazard, and the two-field concentration. None of them
was derived from the barrier count — the ceiling in particular was measured by
deleting 945 forward tests and rebuilding, which does not care how many barriers
sit beside them.
