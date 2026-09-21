# 0020 — What a dispatch arm costs to move out

## Status

Accepted, 2026-09-21.

## Context

`exec_entry` (`vader/vm/exec.vader`) is the bytecode VM's dispatch: one `match`
over 145 opcodes, 1927 lines. Its own comments record that the size is load
bearing — per-frame state (`cur_ops`, `cur_jump`, `cur_top`, the narrow mask) is
hoisted into its locals precisely so the per-op path never re-reads it, and an
`INVARIANT` paragraph says no arm may replace `frames[top]` while `top` is
unchanged. A third comment records that inlining one more helper once pushed the
function past the bytecode emitter's per-function buffer limit, "a latent emit
bug (array-index-OOB in emit at scale)".

So the file both asks to be split and documents why splitting is not free.

## What was tried

The first criterion was **"the arm touches only `frame`"** — no `cur_ops`, no
frame stack, no narrow mask. Eight arms qualified and were moved to
`vader/vm/exec_bulk.vader` behind a `fn(frame: Frame!) -> Trap | null` contract.

That criterion is wrong. Measured across the dispatch afterwards, **~113 of the
145 arms that stayed satisfy it too** — `I32Add`, `I32Eq`, `StructGet`,
`ArrayPush` among them. It is a precondition, not a rule: it says which arms
*may* move, never which *should*.

## What the move actually costs

Not one call. `compute_may_alloc` is a fixpoint over the OP STREAM, not over
signatures — what pulls a fn in is CONSTRUCTING a `Trap` (a heap `StructNew`
plus the message interpolation's buffer), not declaring `-> Trap | null`.
`emit_function_body` then gives it the full GC shadow-stack prologue: up to four
root-address arrays, a 64-byte `vader_gc_frame_t`, a global store on entry and
another on exit — ~15 stores on a probe. `frame` is address-taken as a raw GC
root, so it is forced to memory and cannot stay in a register.

That is the operative cause for exactly the two arms that came back: their O(1)
bodies allocate only through their own Traps. The six that stayed out allocate
in the body anyway (`ArrayNew`, `ArrayPush`, `ArraySlice` and
`StringSliceCodepoints` are all `op_allocates`), so they carry the prologue
wherever they live.

There is an offsetting win. The ~30 ref locals those bodies contributed to
`exec_entry`'s own root arrays are gone, and that frame is scanned at *every*
collection for the whole run.

Measured (2026-09-21, M-series Mac, `--split` + LTO), the two binaries run
**alternately** within one pass and compared on medians. That matters: run
back-to-back in blocks, the same pair read +2.2 % and once even came out ahead,
because absolute times drift upward across a session as the machine heats. The
ratio is stable under alternation where the raw numbers are not — n=12 and n=25
both land on +3 %.

| workload | before | after |
|---|---|---|
| bench hammering these opcodes ×400 000 | 505 ms | 521 ms (+3 %) |
| `vader test vader/lexer` (realistic VM load) | 134 ms | 135 ms |

The second row is within resolution: no measurable difference, not a win.

## Decision

The criterion is **bulky and cold**: an O(N) body, or one that already
allocates, against which the prologue disappears. `array.copy`, `slice`,
`push_all`, `repeat`, `string.slice_codepoints` and `buffer.write_string` meet
it.

`array.clear` and `array.remove_last` were moved and put back. Both are O(1) and
allocate only through their own Traps (plus one `ArrayNew` on `clear`'s
non-owning branch), so the prologue is the same order as the entire body, and
`remove_last` is `pop()` — it runs in loops, not at the edges.

`array.slice` is O(1) too — it builds a view, copying nothing — and qualifies
only through the second clause. "Bulky and cold" is a proxy for what the emitter
actually computes, which is `may_alloc`.

`exec_entry` lands at ~1770 lines. That is not §7 compliance and does not pretend
to be; a family-based cut of the whole dispatch is the change that would get
there, and it needs the same cost question answered per family.

## Consequences

- A future arm moves out only if it is bulky and cold. "Touches only `frame`"
  gates the move; it does not motivate it.
- The emitter's per-function buffer limit is still unfixed. If it is ever what
  forces a split of this function, that limit is the thing to fix.
