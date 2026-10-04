# 0028 — A condition branches on each operand where the C needs no `goto`

## Status

Accepted (2026-10-04). Builds on
[0027](0027-the-structurer-places-each-block-once-by-dominator-tree.md), which
made it possible.

## Context

A condition built from `&&`, `||` and `!` was computed into a slot and tested
afterwards: `or_res = a ? true : b; if (or_res) { … }`. On the VM that is about
four ops per evaluation more than testing each operand and jumping. `8ad4822c4`
branched on each operand only for an `if` without `else` and a loop condition,
because the old structurer copied any block two branches reached; 0027 removed
that limit.

Branching on each operand makes some blocks shared targets. In `if a || b { X }`
both tests jump to `X`; in `if a && b { X } else { Y }` both jump to `Y`. In
structured bytecode a shared target follows a `block`, and every edge into it is a
`br` — one fused compare-and-jump on the VM. C has no statement that leaves an
enclosing brace block, only `break` and `continue` for loops, so the C emitter
writes those `br`s as `goto end_N`.

Two policies were built and measured against `dd5d2a697`:

| | branch on every operand | only where C needs no `goto` |
|---|---|---|
| VM `vm_fib` | −11 % | −11 % |
| VM `split_join` | −8 % | −2 % |
| VM `parse_float` | −2.5 % | −0.5 % |
| other VM workloads | noise | noise |
| native, self-compile | noise | noise |
| `goto` in the compiler's C | 9 → 1 969 | 9 → 22 |
| deepest nesting | 13 → 20 | 13 → 13 |

The `vm_fib` gain owes nothing to the operators: it is the copied `return` below.

## Decision

The second policy. `build_if` (`vader/midir/build.vader`) counts the edges the
tests of a condition send to each target (`operand_edges`, swapping under `!`),
and branches on each operand (`branch_on_cond`) when no target two of them share
needs a `br` that is not a fall-through, `break` or `continue`:

- a then-target shared by several tests (`||`) only when the then-arm leaves at
  once — a lone `break`, `continue`, or `return` of a literal or a name;
- an else-target shared by several tests (`&&`) when there is no `else`, or the
  then-arm leaves at once.

Anything else keeps the slot form for its `&&` / `||`. A `!` always swaps the two
targets instead of computing a `not`. A loop condition branches on each operand
unless its body would be a shared target.

The structurer keeps the shapes the source wrote:

- **A then-arm that only jumps forward to a merge is a `br_if`**, the else-arm at
  the same depth. Not a jump back to a loop header: the VM charges its loop
  budget on a backward jump, and a `br_if` would pay it whether taken or not.
- **An else-arm that leaves at once goes first**, under the test the other way
  round: `if !f(x) { return false }` stays a guard, and a loop body around it still
  ends on its `continue`, so the loop stays a `while`.
- **A merge that returns or traps in at most two instructions is copied** to each
  edge into it, unless a loop's own test leaves for it (copied into the loop, it
  would cost the loop its `while`). `if a || b { return -1 }` becomes two
  `return -1`s; each arm of `fn(n) = if n < 2 { n } else { … }` returns directly —
  the `vm_fib` gain.
- **A shared `break` or `continue` is threaded** to the header or the test exit of
  the innermost loop around its sources (`vader/midir/forwarding.vader`), so
  `if a || b { break }` is two `break`s rather than a `block` in the loop.

Both backends normalise the empty then-arm a swapped `!` leaves: `reg_translate`
turns `if c {} else { … }` into one jump-if-true, and the C emitter writes
`if (!(c)) { … }`.

## Consequences

The compiler's own C: `goto` 9 → 22, `while` 2 449 → 2 475, deepest nesting
unchanged at 13. Outputs identical everywhere; native and self-compile within
noise.

Branching on every operand stays one condition away (`split` in `build_if`). It
would pay off without the `goto`s if the C emitter rebuilt `if (a || b)` from a
run of `br_if`s to one target — or if `If` / `BranchIf` carried their polarity, so
the structurer could say "if not" instead of leaving an empty then-arm for each
backend to recognise.
