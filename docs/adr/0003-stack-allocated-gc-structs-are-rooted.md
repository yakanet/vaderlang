# 0003 — A fn that builds a GC struct on the C stack raises a shadow-stack frame

## Status

Accepted (2026-08-30), implemented in `8e0de8499`.

## Context

The escape analysis builds some GC structs on the C stack. For a `no_frame` fn —
one the `may_alloc` closure proved cannot collect — that storage was left neither
zero-initialised nor registered in `gc_stack_objs[]`, on the grounds that nothing
can move under a fn with no safepoint.

The collector therefore never traced those objects' fields, and the heap refs they
captured went stale at the first collection that happened around them. The
observable result was silently corrupt output: emitting the seed produced seven
identical units and one holding 18 NUL bytes where an 18-character expression
belonged — a string freed under a live handle, length kept, content zeroed. The
compiler could emit C that does not parse.

Measured on that reproduction: 8 diverging per-target units and 18 NUL bytes
before, 0 and 0 after. The stronger signal is not that the symptom stopped
appearing but that the eight per-target emissions of a single run became
byte-identical — determinism, not luck.

`compute_may_alloc` itself was audited and is sound: the transitive closure is
correct, the opcode match is exhaustive, indirect calls are treated
conservatively. The analysis was never the defect; the use the stack storage made
of it was.

## Decision

`no_frame :: !(fn_index in ctx.may_alloc) && !fn_builds_stack_object(function)`.

`fn_builds_stack_object` stays **separate from `op_allocates`**: a stack
`struct.new` does not allocate, and folding it in would wrongly mark every caller
as a collector.

The decision is taken **before the body walk**, and that is load-bearing. A first
attempt raised the frame afterwards, from what the walk had discovered. The build
driver then died on a signal: `FnState.no_frame` is read *during* the walk by the
`return` emitter, which pops the frame only when it believes one exists. The
prologue pushed what no return ever popped, and `vader_gc_top` was left on a dead
frame.

## Consequences

8 extra frames out of 3041 (0.26 %). Benchmarked A/B, 20 runs each side, same
build chain, same session: worst delta +0.6 %, and `selfcompile_c` — compiler
throughput, the most sensitive witness — flat at +0.2 %.

⚠️ A first benchmark at 10 runs, taken while Docker and QEMU were competing for
the machine, reported three regressions over 15 % including `iter_chain/java` —
a workload this change cannot touch. Never read a benchmark taken under
contention.
