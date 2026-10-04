# 0027 — The structurer places each block once, by dominator tree

## Status

Accepted (2026-10-04). Supersedes the mechanism of
[0016](0016-a-guards-continuation-is-duplicated-by-the-structurer.md) —
`TermCondBranch.join` and `cond_branch_merge` are gone. Its source-shape decision
in `vader/vm/exec.vader` stands.

## Context

`vader/midir/emit.vader` recovered `block` / `loop` / `if` nesting from the CFG
with a recursive walk guided by immediate post-dominators (`emit_range`,
`emit_cond`, `cond_branch_merge`). A block reached along two structured paths was
emitted once per path. Two patches held the known cases back:

- `TermCondBranch.join`, the rejoin point the builder recorded because
  post-dominance loses it as soon as an arm `return`s (0016);
- `CFGFunction.block_regions`, entry → exit of every labelled block, because the
  walk could not see where to open the `block` a `break` leaves.

Neither generalised. The builder could not emit jumping code for a condition: an
`if a && b { … } else { … }` would give the else block one predecessor per
operand, and the walk copied it per predecessor. So `a && b` was computed into a
slot (`and_res`) and branched on afterwards — four extra ops per evaluation on
the VM. The first step around it (`8ad4822c4`) only covered the shapes with no
block to share: an `if` without `else`, and a loop condition.

## Decision

Replace the walk with Ramsey's algorithm (*Beyond Relooper*, ICFP 2022), which
LLVM's WebAssembly `CFGStackify` also implements, in `vader/midir/structure.vader`:

- every block is emitted exactly once, beneath its parent in the dominator tree;
- a loop header opens a `loop`; back edges are `br`s to it;
- a merge (two or more forward predecessors) follows a `block` its placement
  parent opens around the code that reaches it; every edge into it is a `br`;
- any other block is emitted where its single predecessor branches to it;
- a branch to the block control falls through to emits nothing, and an `if`
  whose then-arm always leaves puts its else-arm after the `end`, as before.

The rest is ours. Each rule exists because the C emitter renders the result, and
C has neither multi-level `break` nor a nesting budget past 127 levels.

**The code after a loop follows the loop.** Ramsey leaves a loop exit under its
immediate dominator, inside the loop. For the code after the loop that nests it
one level per successive loop, so that exit is emitted after the loop's `end`,
in a `block` around the loop alone — not around its parent's code, which would
pull the rest of an `if` arm out of the `if` and add a `goto` over its `else`.
The exit the header's test takes is that code. In a loop without a test
(`for { … }`), the code after it is wherever its `break`s lead, so there an exit
also goes after the loop when it holds a loop or several branches reach it.

**Any other exit stays where Ramsey puts it.** It is code the source writes
inside the loop: what precedes a `break`, an `if x is Trap { return x }`, a
nested search that returns. Moved after the loop it adds a `block` and a `br`
over the loop's own exit — `vader_vm_reg_call`'s 22 trap exits took its C from
13 to 34 levels of nesting that way, and a `break` with code before it became a
`goto`. It stays only if every edge into it is emitted beneath its parent: an
edge from another exit, emitted after the loop, would branch to a `block` that
does not enclose it.

**The header's test falls out of the loop.** Inside a loop nothing falls
through — leaving is an explicit `br`, a C `break` — except that test when no
`block` stands between it and the loop's `end`; the edge it takes follows the
`end`. That is the shape the C emitter renders as `while (c)`.

**A merge's `block` opens as late as the operand stack allows**, right before
the terminator that branches to it, not before its parent's instructions:
`n = 0; while (n < len)` instead of `{ n = 0; for (;;) … }`. The C emitter
requires an empty stack at a scope's opening.

**Forwarding blocks are threaded** (`skip_forwarding_blocks`): an edge into a
block holding nothing but a `branch`, and entered by that edge alone, goes
straight to its target. The builder gives each arm of an `if` its block before it
knows the arm is a lone `break` or `continue`; left in place, a `break`'s block
is a second exit beside the loop's own. One that several edges enter stays: it is
a real merge — the `break` after an inner loop whose `&&` condition gives it
three exits — and threaded, each of those edges leaves two loops by a `goto`.

**A loop with no condition starts its body in its header** (`build_loop`). A
header that only forwards has no test of its own, so the C emitter cannot write
the loop as a `while` when its body opens with `if c { break }` — and threading
such a header instead merges it into a loop its body opens on.

`drop_unbranched_blocks` (`vader/bytecode/emit.vader`) then removes every `block`
no `br` leaves through: the structurer opens one per merge before it knows
whether control will branch to the merge or fall into it.

Two checks make a wrong placement loud instead of a silent mis-compile: `shape_of`
panics on an irreducible edge, and `structure_function` panics when a `br` was
never resolved to an enclosing scope. The second found both the `chain().find()`
case — a shared `return` kept inside the first of two loops — and the edge from
an exit after the loop that `emitted_beneath` now guards.

## Consequences

Measured 2026-10-04 against the previous structurer, same machine, alternating:

- Snapshot corpus: `.virt` 385 935 → 372 050 lines over 412 files, emit-C
  164 719 → 159 271 over 131; no `vm.snapshot` moved. In that C, `while` 674 →
  694, `for (;;)` 713 → 692, `goto` 62 → 54.
- The compiler's own C: 356 705 → 343 613 lines; `while` 2 384 → 2 449,
  `for (;;)` 490 → 422, `goto` 9 → 9 (the same nine); deepest nesting 18 → 13.
  Most of the gap is tails the walk copied into each arm.
- VM (11 workloads) and native (27 workloads): every row within noise, outputs
  identical. Self-compile to C: 2.44 → 2.44 s.

Removed: `TermCondBranch.join`, `CFGFunction.block_regions`, the I7012 check that
guarded it, `compute_post_dominators`, `find_loop_exits`, and the walk itself.

The gain is not in this change: it is what the builder may now emit. A condition
can branch on each operand of `&&`, `||` and `!` with an `else` present — the
else block is a merge, emitted once.
