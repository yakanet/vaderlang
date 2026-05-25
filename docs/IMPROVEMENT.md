# Improvement Plan — Post-Review Action Items

Source: expert review of the compiler on 2026-05-11. Scope: full pipeline
(`src/` TS compiler, `vader/` self-host port, tests, tooling, docs).

This document captures the ten axes raised by the review, the user's
decision on each, and the agreed follow-up. Items still open are picked up
into the relevant section of `TODO.md` when scheduled.

## Status legend

| Symbol | Meaning |
|--------|---------|
| ✅ | done |
| 🟡 | in progress |
| ⬜ | to do |
| ❌ | rejected (deliberate non-action) |
| ℹ️ | already in place — no work needed |

## Action items

### 1. Formatter (`vader fmt`) — 🟡 in progress

The CLI scaffold and the printer skeleton already exist under
`vader/fmt/`. Completing the formatter is the next deliverable; no new
work was committed in this review.

### 2. Constant folding — ✅ done (2026-05-24)

Mid-IR pass in `src/midir/const_fold.ts`. Walks each block, tracks
`LocalId → ConstValue` from `Const` instructions, replaces `BinOp`
/ `UnOp` whose operands are all known constants with a fresh
`Const`. Truncation / sign-extension by result-type width via
`BigInt.asIntN` / `BigInt.asUintN` so folded values match runtime
semantics across i8..i64, u8..u64, isize, usize.

Folded ops : int / float arith (`add`, `sub`, `mul`, `div`, `mod`
— div/mod by 0 deliberately left for runtime trap), bitwise (`shl`,
`shr` skipped when shift count ≥ 64, `bitand`, `bitor`, `bitxor`),
comparisons (`eq`, `neq`, `lt`, `lte`, `gt`, `gte`) on
int / float / bool / char, logical (`and`, `or`) on bool, unary
(`neg`, `not`, `bitnot`).

Wired in `src/pipeline.ts:148` and `src/comptime/lower-decl.ts:103`
before `eliminateDeadCFG` so its DIE pass collects the
now-unused producer Consts. Intra-block scope ; SSA-style
cross-block propagation is a future pass.

Surfaced a latent VM bug in `tests/snippets/u32_bitops` — `~0_u32`
was returning the wrong runtime value but the snapshot baked in
the bug. With folding, the comparison resolves correctly ;
snapshot refreshed.

Follow-ups (not blocking) :
- Shared `evalBinop(op, ConstValue, ConstValue)` between this pass,
  `src/vm/exec.ts`, and `src/bytecode/peephole.ts::constFoldArith`.
- Re-run after `foldMoves` to catch newly-unlocked opportunities.

### 3. `switch` terminator + jump table for `match` — ⬜ to do

`match` arms currently desugar to a cascade of `if` / `else if`. For an
N-variant enum that produces N branches and N comparisons. Adding a
`Terminator.kind === "Switch"` to the CFG (and a matching bytecode op
that the C emitter lowers to a `switch`) gives O(1) dispatch.

Captured in `TODO.md` (under §3.5 / control-flow once filed) — this
document is the canonical pointer until then.

### 4. Type values in the comptime VM (milestone B.1) — ⬜ to do

`src/comptime/run.ts` currently notes "comptime type values cannot flow
through the VM yet (Layer 4 milestone B.1)". The VM `Value` type has no
`type` tag, so any comptime expression that tries to construct, store or
return a type value falls back to a synthetic alias path
(`evaluate.ts:62`).

Unblocking this is required before the comptime layer can be used for
real meta-programming on generics.

### 5. Refactor `src/typecheck/passes/call.ts` — ❌ rejected

886 lines, mixing direct-call resolution, UFCS, generic instantiation,
overload resolution, and method dispatch. Originally a candidate for a
4-file split (`call-direct` / `call-ufcs` / `call-method` /
`call-generic`).

Decision (2026-05-25): not worth the churn. The TS compiler is
scheduled for deletion once the Vader self-host port ships
(`docs/BOOTSTRAP.md`) ; the file-organisation cost is paid on the
Vader side from day one. The Vader port will split call resolution
along the same axes natively — see `vader/typecheck/expr.vader` and
siblings, which already follow the 1-file-1-responsibility rule.

### 6. Unit tests for resolver / typecheck — ⬜ to do (suggestion)

Today resolver and typecheck regressions surface as snapshot drift in
later stages (bytecode, native output) — debug-by-bisection. Direct unit
tests on symbol resolution, narrowing, and overload resolution would
catch them at the source. Not yet committed by the user.

### 7. Drop the legacy `LoweredAST` path — ✅ done

Verified 2026-05-23 : `src/pipeline.ts` only routes through
`LoweredAST → CFG → bytecode` (`pipelineBytecode` → `pipelineCfg` →
`emitBytecodeFromCFG`). `src/bytecode/emit.ts` survives as a helper
library (`EmitterCtx`, `internType`, `pushOp`, …) consumed by
`src/midir/emit.ts` only — no `LoweredAST → bytecode` walker remains.
See [`MID_IR_DESIGN.md`](./MID_IR_DESIGN.md) Phase 6.

### 8. Bytecode binary header — ℹ️ already in place

Verified during the review: `src/bytecode/binary.ts` already writes a
12-byte header (`MAGIC = "VADR"` at lines 19 + 192, `version u32` at
193, `flags u32` reserved-for-future-use at line 496 on the read side).
Reader rejects mismatched magic and mismatched version with explicit
diagnostics. No work needed.

### 9. VM stack-depth limit — ❌ rejected

The review suggested capping recursion depth in `src/vm/exec.ts` to
avoid uncaught JS stack overflows. The user does not see a need for
this in current usage. Filed here for the record; can be revisited if a
real case appears.

### 10. Non-trivial generic example — ✅ done

Covered by the `bench/` corpus rather than `examples/`. The Iterator
pipeline showcase landed as `bench/iter_chain/iter_chain.vader` —
`Range.filter(is_even).map(square_i64)` driven by a `for-in` accumulator
over N=1 000 000, dispatching through `std/iter`'s `filter` / `map`
free fns via UFCS. `bench/map_iter/` exercises the simpler
single-stage `Range.map(...)` chain on the same N. Both compile
through the lowerer's iter-chain fusion path (no `Yielded(T)` heap
allocs, no `Iterator.next()` vtable hops), validating end-to-end the
`Iterator(T)` virtual dispatch landed 2026-05-08 (TODO §3.8) and
the auto-`.iter()` `for-in` integration.

A dedicated `examples/iterator_pipeline.vader` is no longer planned —
the benches already serve the demonstration role, and adding a third
copy of the same chain would just be churn.

## Out-of-scope ideas

Examples considered for item 10 but not retained at this round, kept
here for future reference:

- **`Vec<T>`** with `push` / `pop` / `resize` / `iter` — exercises generics
  + heap cells + GC of a dynamic buffer. Good but overlaps with stdlib's
  existing `MutableList`.
- **JSON parser → user `struct` via comptime** — would showcase
  `@file(...)` baking + generic decode. Blocked by the maturity of
  string utilities in `stdlib/`.
- **Mini Dijkstra on a generic `Graph<Node, Cost>`** — stresses generic
  bounds (`Cost: Add + Ord`), narrowing, collections. Heavier scope.
- **Mini expression interpreter with generic numeric `T`** — recursive
  ADT, exhaustive `match`, arithmetic traits. Strong "compiler-in-the-
  language" showcase. Candidate for a follow-up round.

## Notes

### On the bytecode header (item 8)

The current header layout (`src/bytecode/binary.ts:3-5`):

```
+0  magic   "VADR"     (4 bytes)
+4  version u32        (BYTECODE_VERSION; bumped on incompatible change)
+8  flags   u32        (reserved for future use)
+12 payload …
```

Read-side validation lives in `binary.ts:487-496`. Pre-1.0 policy is
hard-fail on version mismatch; no migration is attempted.

### On the Iterator example (item 10)

The point of the example is to be a *demonstration*, not a benchmark or
a stdlib replacement. Aim for ~80–120 lines, include comments only when
they explain a deliberate language choice (e.g. why a particular bound
is needed), and keep the final pipeline expression short enough to read
in one breath.

## Changelog

- 2026-05-11 — initial document, captures the review of the same date.
