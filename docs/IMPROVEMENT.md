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

### 2. Constant folding — ⬜ to do

A `1 + 2` expression currently emits `i32.const 1; i32.const 2; i32.add`.
The peephole pass (`src/bytecode/peephole.ts`) handles dead-store and
jump threading but not constant arithmetic. Two options:

- Fold at the mid-IR level (`src/midir/`) on `Instruction.kind === "BinOp"`
  where both operands trace back to `Const` instructions.
- Fold in the bytecode peephole as a new rule, fusing
  `const ; const ; <op>` into a single `const`.

The mid-IR option is preferred: it composes with copy propagation and
DCE, and covers branches the bytecode emitter has already linearised
beyond recognition.

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

### 5. Refactor `src/typecheck/passes/call.ts` — ⬜ to do

886 lines, mixing direct-call resolution, UFCS, generic instantiation,
overload resolution, and method dispatch. Suggested split:

- `call-direct.ts` — direct fn calls + overload tie-break
- `call-ufcs.ts` — receiver-style dispatch + free-fn lookup
- `call-method.ts` — trait method resolution + impl table lookup
- `call-generic.ts` — monomorphisation registry + bound checking

To be done before the file accumulates more passes; the longer it stays
monolithic, the harder the bisection of overload bugs becomes.

### 6. Unit tests for resolver / typecheck — ⬜ to do (suggestion)

Today resolver and typecheck regressions surface as snapshot drift in
later stages (bytecode, native output) — debug-by-bisection. Direct unit
tests on symbol resolution, narrowing, and overload resolution would
catch them at the source. Not yet committed by the user.

### 7. Drop the legacy `LoweredAST` path — ⬜ to do

`src/pipeline.ts` still routes through both `LoweredAST → bytecode` and
`LoweredAST → CFG → bytecode`. Phase 6 of the mid-IR migration was
declared complete (commit history), but the legacy emitter is still
reachable. Removing it deletes a non-trivial amount of duplicated code
and removes one source of VM ↔ C semantic divergence.

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

### 10. Non-trivial generic example — ⬜ to do

The `examples/` directory leans on `mowitnow.vader` for breadth.
Missing: a program that exercises generic functions, generic structs,
and trait bounds in one piece. Five candidates were considered (see
*Out-of-scope ideas* below); the retained one is **Iterator pipeline**.

**Sketch** — `examples/iterator_pipeline.vader`:

- A user-defined `Iterator(T)` source (e.g. `Range`).
- Generic combinators built on the `Iterator` trait:
  `map(it: Iterator(A), f: fn(A) -> B) -> Iterator(B)`,
  `filter(it: Iterator(T), pred: fn(T) -> bool) -> Iterator(T)`,
  `fold(it: Iterator(T), seed: U, f: fn(U, T) -> U) -> U`.
- A composed pipeline: e.g. `Range(1, 100) |> filter(is_prime) |> map(square) |> fold(0, add)`.
- Output a small summary to demonstrate the result.

Side benefit: this is a forcing function for completing the deferred
`Iterable($T)` trait + auto-`.iter()` in `for-in` (TODO §3.8) and gives
a real consumer for the existing `Iterator(T)` virtual dispatch already
landed (TODO §3.8, 2026-05-08 entry).

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
