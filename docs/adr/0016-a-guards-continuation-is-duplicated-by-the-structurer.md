# 0016 — A guard's continuation is duplicated, once per guard, by the structurer

## Status

Accepted (2026-09-06). Supersedes in part
[0014](0014-the-interpreters-cost-is-the-buffer-resolve.md) and
[0015](0015-the-interpreters-buffer-resolve-is-worth-thirteen-percent.md), which
both attribute the `exec_entry` doubling to the C emitter. It is not the C
emitter's. One source-shape change landed
(`vader/vm/exec.vader`); the general defect is filed, not fixed.

## Context

0014 and 0015 both found `exec_entry` holding two copies of the VM's whole
dispatch, and both wrote it down as *"the C emitter tail-duplicates the loop body
into both branches of `if is_comptime`"*. 0014 went further and concluded the
duplication was worth keeping — de-duplicating the two emitted copies measured
**+22 %**, so *"the duplication is a specialisation that pays."*

Two things were wrong with that.

**The conclusion generalised one experiment too far.** Merging two copies that
have already been emitted is indeed worse: the merged copy is a join reached from
two predecessors with different live states, spill traffic per copy rises 29 %,
the frame grows. Removing the *cause* is a different operation, and it is nearly
free. The cause was one guard's shape:

```vader
if is_comptime {
    steps += 1
    if steps > COMPTIME_STEP_BUDGET { return Trap { … } }
}
```

The outer body falls through, so the rest of the loop is reachable from two
edges. Giving a normal run a budget it cannot reach collapses that to one guard
whose body returns, and there is no join left to merge:

```vader
steps += 1
if steps > step_budget { return Trap { … } }
```

Measured, three alternating draws each: `vader_vm.c` **46 250 → 32 667 lines
(−29 %)**, its `cc -O3` **4,7 → 2,9 s (−38 %)**, the whole parallel compile of the
compiler **6,04 → 4,77 s (−21 %)**, for **+1,7 %** on the comptime pass — ~3 % of a
real compile, so about **+0,05 %** end to end.

**The attribution was wrong.** `vader/c_emit` renders faithfully what it is
handed; the duplication is already in the bytecode. Minimal repro, on
`dump --stage=bytecode`, counting the continuation's `i32.const 13`:

```vader
run :: fn(flag: bool, n: i32) -> i32 {
    steps := 0
    i := 0
    for i < n {
        if flag {
            steps += 1
            if steps > 100 { return -1 }   // the conditional exit
        }
        i = i + 1
        steps = steps + 13                 // the continuation
    }
    return steps
}
```

| guards of that shape | copies of the continuation |
|---|---|
| 0 | 1 |
| 1 | 2 |
| 2 | 4 |
| 3 | 8 |

Two guards in a **straight-line** function, no loop at all, also give 4. It is
2^N in the number of guards whose body can exit.

The mechanism is in `vader/midir/emit.vader`. `cond_branch_merge` picks the
rejoin point by **immediate post-dominator**:

```vader
post :: ctx.ipostdom[usize(block_id)]
if post < 0 { return until }
```

A then-arm that can `return` destroys post-dominance of the true rejoin, so
`merge` degrades to the enclosing region's `until`, and the two `emit_range`
calls in `emit_block_contents` each independently walk the shared continuation to
the end of the region. What the structurer needs there is the nearest common
successor reachable from both arms — or, failing that, a labelled `block` scope
and a `br`, which the bytecode already has.

## Decision

Keep the source-shape change in `vader/vm/exec.vader`; it is one line and it pays
on every build of the compiler, every CI run and every bootstrap stage.

Do **not** treat it as the fix. The defect is general — the shape it works around
is an ordinary Vader idiom, used throughout the tree — and it belongs in
`cond_branch_merge`, where it would pay out on every compiled program instead of
one function. Filed, unscheduled.

Withdraw *"the duplication is a specialisation that pays"*. It is the kind of
conclusion that survives only until someone asks what produced the two copies.

## Consequences

- The guard in `exec.vader` carries a CONSTRAINT comment pointing here. It names
  `vader/midir`, not the C emitter, and says the constraint is general rather
  than local to that file — otherwise the next reader learns the wrong lesson
  about their own code.
- The non-comptime path now pays `steps += 1` and one compare per op that it did
  not pay before. The +1,7 % quoted above is the comptime pass; the
  `vader run` / self-hosted-VM path was not separately measured.
- Every static count in 0014 and 0015 was taken on the doubled tree. They are
  right for the tree of 2026-09-05 and halve for today's.
- `tests/diag_corpus/comptime/c4002_non_terminating/` pins that a
  non-terminating `@comptime` errors rather than hanging the build — the
  behaviour whose shape this change moves. Nothing pinned it before.
