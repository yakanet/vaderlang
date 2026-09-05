# 0015 — The interpreter's buffer resolve is worth 13 %, and three of 0014's counts do not reproduce

## Status

Accepted (2026-09-06). Amends [0014](0014-the-interpreters-cost-is-the-buffer-resolve.md) —
its measurements, not its decision. Investigation only ; no code changed.

## Context

0014 named the buffer resolve as the interpreter's cost and parked the fix as a
cross-pass change to `bce_block_unsafe`'s granularity. Before spending that, the
question worth asking is what the fix would actually buy — a figure 0014 does not
give, having deliberately refused to extrapolate its 9 × from array loops.

Re-measuring produced the ceiling, and along the way three of 0014's static
counts turned out not to reproduce.

## What was measured

**Three of the static counts are wrong.** Same instrument 0014 used — a count over
the emitted `--release` C, region `vader_vm_exec_entry`, 23 257 lines:

| | 0014 | measured |
|---|---|---|
| buffer resolves | 963 | 945 |
| bounds checks | 966 | 945 |
| write barriers | 489 | **12** |
| `gc_alloc` | 786 | **195** |

The first two are close enough to be a region boundary drawn differently. The
other two are not, and neither figure was recoverable: not over the whole
`vader_vm` TU (1253 / 1267 / 1227 / 28), and not under any neighbouring pattern
tried (`vader_ref_box`, `vader_obj_header_init`, `vader_box_obj`, ref loads).
**No write barrier exists anywhere in the tree's emitted C** — the only guarded
stores are 12 `vader_array_ref_store`. This matters because 0014's "15-20 machine
operations per interpreted instruction" counted a barrier as a third of the
preamble.

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

Not verified in situ: 0014's fourth hypothesis, the if-chain against a `switch`,
measured 1.00 × in a standalone prototype over the real arms. That prototype was
not the emitted dispatch. If the resolve is 13 %, the remaining 87 % is still
unaccounted for, and the chain is where the next look belongs.
