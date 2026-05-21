# Midir port to Vader self-host

> **Status** : in progress (2026-05-22). 6 / 10 phases shipped, 4 heavy
> phases remaining (M.4 / M.6 / M.8 / M.10). Cumulative : ~1 850 LoC
> Vader produced for ~1 393 LoC TS ported. Files isolated — nothing
> wired into the pipeline yet (M.10 does the wiring).
>
> Shipped (commits 33498d9e → 73343ae0) :
> - M.1 cfg.vader (476 LoC) — types
> - M.2 lowered_walk.vader (236 LoC) — RefVisitor walks
> - M.3 analyses.vader (373 LoC) — dom / liveness / loops
> - M.5 escape.vader (343 LoC) — escape analysis
> - M.7 scheduler.vader (212 LoC) — stack-pass-through hints
> - M.9 dump.vader (196 LoC) — CFG pretty-printer
>
> Remaining (heavy, ~3 000 LoC) :
> - M.4 build.vader — 865 LoC TS, ~37 fns. LoweredAST → CFG. Largest
>   single file, will need split.
> - M.6 dce.vader — 750 LoC TS. pruneUnreachable + eliminateDeadCFG.
> - M.8 emit.vader — 876 LoC TS. CFG → bytecode. **Contains flatten +
>   fusion 7.f/7.c/7.e/7.d** — the whole point of this port.
> - M.10 wiring — small, replaces shortcut in `vader/bytecode/emit.vader`.
>
> Each remaining phase needs a dedicated session to port correctly
> without subtle bugs (no wiring = no integration validation until
> M.10 lands).

## 0. Why now

`vader/` self-host has `bytecode/`, `c_emit/`, `vm/` ported (with gaps),
but **zero `vader/midir/`**. The current `vader/bytecode/emit.vader`
collapses the TS `midir/emit.ts + bytecode/emit.ts` pair into a single
file that walks the LoweredProject directly — bypassing the CFG /
DCE / escape / stack-scheduler / structurer detour.

That shortcut blocks every compile-time optim that lives in
`src/midir/` :
- `src/midir/emit.ts:317-322` — early-return flattening
- `src/midir/emit.ts:269-289` — piste 7.f `return.lit` fusion
- `src/midir/emit.ts:539-555` — piste 7.c `local.field` fusion
- `src/midir/dce.ts` — pruneUnreachable + eliminateDeadCFG
- `src/midir/escape.ts` — `struct.new_stack` annotation
- `src/midir/scheduler.ts` — `skipFirstGet` / `skipTerminatorGet` hints

Without midir, the self-host compiler would regenerate the
51 k-line `is_assignable` monster + un-flattened cascades the TS
optims eliminated.

## 1. Source map

| TS file | LoC | Role | Vader target |
|---|---:|---|---|
| `src/midir/cfg.ts` | 492 | CFG / Instruction / Terminator types | `vader/midir/cfg.vader` (may split) |
| `src/midir/lowered_walk.ts` | 219 | RefVisitor walks over LoweredProject (for DCE) | `vader/midir/lowered_walk.vader` |
| `src/midir/analyses.ts` | 296 | computeLiveness, dominators, naturalLoopBodies, ... | `vader/midir/analyses.vader` |
| `src/midir/build.ts` | 865 | LoweredAST → CFG construction | `vader/midir/build.vader` (will split) |
| `src/midir/escape.ts` | 326 | Escape analysis annotation | `vader/midir/escape.vader` |
| `src/midir/dce.ts` | 750 | Whole-program + intra-procedural DCE | `vader/midir/dce.vader` (will split) |
| `src/midir/scheduler.ts` | 128 | Stack scheduler hints | `vader/midir/scheduler.vader` |
| `src/midir/emit.ts` | 876 | CFG → Bytecode + flatten + fusion 7.f/7.c | `vader/midir/emit.vader` (will split) |
| `src/midir/dump.ts` | 132 | CFG text dump for `dumpCfg` | `vader/midir/dump.vader` |
| **total** | **4 084** | | |

## 2. Phase breakdown

**Sequencing rationale** : types first (cfg) so every downstream
file has the shapes ; then walkers + analyses ; then build (the
constructor) ; then escape + dce + scheduler ; finally the
emit + dump.

| Phase | File(s) | LoC est. | Depends on | Why this order |
|---|---|---:|---|---|
| **M.1** | `cfg.vader` | 492 | — | Foundational types ; everything downstream imports from here. |
| **M.2** | `lowered_walk.vader` | 219 | M.1 (only `Type` from typecheck) | Pure RefVisitor walks ; used by M.6 (dce). |
| **M.3** | `analyses.vader` | 296 | M.1 | Dom / liveness / loop detection used by M.6 + M.8. |
| **M.4** | `build.vader` | 865 (may split) | M.1, M.3 | The big constructor : LoweredAST → CFGProject. |
| **M.5** | `escape.vader` | 326 | M.1, M.3 | Annotates `stack_alloc` on InstrStructNew ; affects M.8. |
| **M.6** | `dce.vader` | 750 (may split) | M.1, M.2, M.3 | pruneUnreachable + eliminateDeadCFG. |
| **M.7** | `scheduler.vader` | 128 | M.1 | Trivial scheduler ; emit uses its hints. |
| **M.8** | `emit.vader` | 876 (split into emit + structurer) | M.1, M.3, M.7 + bytecode/* | CFG → Bytecode. **Contains** flatten + 7.f/7.c fusion. |
| **M.9** | `dump.vader` | 132 | M.1 | CFG dump for snapshot tests. |
| **M.10** | wiring | small | all above | Replace shortcut in `vader/bytecode/emit.vader` ; pipe LoweredProject → buildCFG → annotateEscape → eliminateDeadCFG → emitBytecodeFromCFG. Plumb into the CLI. |

## 3. Per-file rules

Per `feedback_vader_port_rules` :
- **1 file = 1 responsibility, ≤ 500 LoC.** Files > 500 split by
  concern (`build.vader` will split per LoweredExpr kind ;
  `emit.vader` will split structurer + emit per terminator kind ;
  `dce.vader` will split whole-program vs intra-procedural).
- **vaderdoc on every export** with `@param` / `@return` / `@error`.
- **Side-tables separated by concern.**
- **No SPEC.md change** — port doesn't change language surface.
- **`/simplify` before each commit.**

## 4. Per-phase validation

Each phase :
1. Port the file(s).
2. `bunx tsc --noEmit` (TS unchanged, sanity only).
3. **Don't wire into the pipeline yet** — port phases run isolated
   first, only M.10 plugs them in. Tests stay green on the TS path
   throughout.
4. `/simplify` review, fix, commit.

At M.10 :
1. Plumb the new pipeline through `vader/bytecode/emit.vader` or via
   a fresh entry point.
2. Build `build/vader` with the new path, compare output to the TS
   path (byte-diff `build/vader.c`).
3. Full test suite (native + vm + parity + format + cli + e2e).

## 5. Risks

| Risk | Mitigation |
|---|---|
| Vader compiler hits a port-blocking feature (generics, unique helpers) | Track in §6 "Issues encountered" per `feedback_record_issues_in_plan`. |
| 4 k LoC port creates regression surface | Each phase is independent until M.10. Wiring is gated on full-suite green. |
| Bytecode output drifts from TS path (different op order, slot numbering) | M.10 acceptance is byte-identical `vader.c` vs TS path. Drift = bug. |
| Vader vs TS LoC scaling — Vader may need more LoC for same logic | Accept ≤ 1.5× ratio (typecheck port runs at 1.6× — same regime). |

## 6. Issues encountered

_(to be filled per phase)_

## 7. Acceptance

Sprint complete when :
- All 9 `vader/midir/*.vader` files exist, each ≤ 500 LoC.
- `vader/bytecode/emit.vader` reroutes through `vader/midir/emit.vader`
  (no more LoweredProject-direct walk).
- `build/vader.c` produced by the Vader-compiled pipeline byte-matches
  the one produced by the TS pipeline (post-piste-7 + post-piste-6
  state, ~116 k lines).
- All test suites pass.
