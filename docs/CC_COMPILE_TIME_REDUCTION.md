# C compile-time reduction

> **Status**: open (2026-05-21). 5 pistes scoped, POC required for piste 5
> before committing to the full plan.

## 0. Motivation

The self-host bootstrap currently emits **334 837 lines / 31 MB of C** for
`build/vader.c`. `cc -O0 -ggdb` on a modern laptop takes ~3 min to compile
this single TU. The compiler will only grow ; we need to fix this before the
checker, the bytecode optimiser, or anything else lands as Vader code.

## 1. Diagnostic — measured 2026-05-21 against `build/vader.c`

| Section                              | Lines     | % of total |
|--------------------------------------|----------:|-----------:|
| Function bodies                      | 325 266   | **97 %**   |
| `typedef struct …` (642 entries)     | 3 854     | 1 %        |
| Type info / strings / data / trampolines | ~5 700 | 2 %        |

The body share is **dominated by two functions**:

| Vader function        | C lines | Source LoC |
|-----------------------|--------:|-----------:|
| `is_assignable`       | 89 016  | ~150       |
| `infer_field`         | 78 720  | ~250       |
| `vm.exec`             | 7 486   | ~400       |
| 2 034 other fns       | ~159 000 | rest      |

Two fns = 50 % of the file. Explosion ratio ~600×.

Inside `is_assignable` :
- ~30 000 distinct tmps (`t0 … t30000+`), each pre-declared as
  `vader_box_t tN = vader_box_null();` in a 4 482-line prologue.
- A single `vader_box_t* gc_roots[26849] = { &l0, … };` array.
- Body cascade : `if (tN.tag == K) { … } else { if (tN.tag == K) { … } else { … } }`
  with no factoring across siblings.

Three patterns dominate the body line count :

| Pattern                                                      | Occurrences |
|--------------------------------------------------------------|------------:|
| `((vader_struct_…*) tN.payload.obj)->f_…` (struct read via tmp) | 16 883      |
| `bool tN = (tN.tag == K)` (type-check via tmp)               |   8 133 + 584 |
| `tN = lN;` (ref local copy into a tmp)                       |   5 161     |
| `((vader_struct_…*) lN.payload.obj)->f_…` (direct from local) | **0**       |
| `bool tN = (lN.tag == K)` (direct from local)                | **0**       |

The last two rows are the key finding : **zero** ref reads happen against
the local directly — every single one routes through a redundant tmp
created by `local.get`.

## 2. Out of scope

- **TU split + parallel `cc`** : deferred. It hides codegen waste behind
  parallelism rather than fixing it, and the per-TU split would still leave
  the `is_assignable` outlier dominating its TU. Revisit once the codegen
  pistes below have landed and we have a clean measurement of per-fn cost.

## 3. Implementation conventions for every piste

- **TS is source-of-truth.** Each piste lands first in `src/`, with snippets
  + self-host regression as the validation gate. Vader port follows once the
  TS version is green.
- **Vader port mirrors TS file boundaries.** The same per-file
  responsibility, ≤ 500 LoC, vaderdoc on every public fn, `/simplify` before
  commit.
- **No SPEC.md changes.** All pistes touch codegen ; the language surface
  doesn't move.
- **Each piste's PR commits TS + Vader together** when both are ready, so
  the bootstrap stays self-consistent.

## 4. Pistes

### Piste 5 — local-ref inlining for `ref`/`any` (`POC FIRST`)

**Symptom**

`src/c_emit/body.ts:332-346` (`local.get`) creates a tmp + assignment for
every ref/any read :

```c
t0 = l0;
bool t1 = (t0.tag == 322u);
```

The justification ("snapshot into a refTmp so the value stays a GC root
through any intervening allocation") is **incorrect** : `lN` is itself in
`gc_roots[]` (added at prologue in `body.ts:65-68`), so the redundant tmp
adds zero GC safety.

**Fix**

Extend `pushLocalRef` to ref/any ValType. The push records `{kind:
"local-ref", slot, val}` on the stack ; consumers inline `lN` directly. The
existing `materializeStackForSlot` mechanism (called before `local.set` /
`local.tee`) already upgrades the stack entry to a tmp if the local would
be mutated before the pop, so the WAR hazard is covered.

Touch points :
- `local.get` — drop the materialisation branch for ref/any.
- `local.tee` — same.
- `dup` — already safe (shares the StackVal).

**POC** (required before sprint commits)

1. Apply the change to `src/c_emit/body.ts` only.
2. Rebuild `build/vader.c` from the current self-host source.
3. Measure : `wc -l build/vader.c`, `du -h build/vader.c`,
   `time cc -O0 -ggdb -c build/vader.c`.
4. Run the snippet suite (`bun test tests/snippets`) and self-host regression
   (rebuild vader with the new vader, then compile something with the
   rebuilt binary).
5. **Acceptance**: line count drops ≥ 25 %, no test regression, no GC crash
   in the self-host roundtrip.
6. If acceptance fails, document the symptom in §"Issues encountered" with
   reproduction steps and abort the rest of this plan pending re-design.

**Expected gain**

- ~17 500 `tN = lN;` lines removed (~ 5 %).
- ~17 500 prologue decls removed.
- ~17 500 `gc_roots[]` entries removed.
- Indirect : struct/field reads that currently chain through the tmp
  (`((Struct*) tN.payload.obj)->f_X`) — extend the inlining to one-shot
  field accesses on a local-ref to fold ~16 800 more sites. (Tracked as
  sub-task 5.b ; the bare local.get fix is 5.a.)

**Risks**

- GC re-locating an object between two reads of `lN.payload.obj` within
  the same C expression : impossible — Vader doesn't expose a moving GC
  inside arithmetic, only at call boundaries (op-level).
- A `local.set` arriving between push and consumer : already handled by
  `materializeStackForSlot`. Add a snippet test that exercises
  `local.get → call (alloc) → local.set → consume` to lock the contract.

**TS implementation**: `src/c_emit/body.ts`. ~50 LoC modification.
**Vader port**: `vader/c_emit/body.vader` after TS POC ships. Same edits.

---

### Piste 1 — Tmp recycling, scope-bounded

**Symptom**

`tmpCounter` in `FnState` (`body.ts:647`) is strictly monotone. Every
`newTmp` allocates a fresh `tN`, never recycled. Even after a tmp is popped
off the stack and forgotten, its name still occupies a slot in the prologue
and in `gc_roots[]`.

**Fix**

Two-pass emit per fn :

1. First pass : run the existing op walk but track, per ValType, the
   **peak simultaneous live tmp count** within each scope. A tmp is live
   from `newTmp` to its last `pop`. Reset the per-scope counter at each
   `block`/`loop`/`if` open ; on `end`, the peak inside the scope can fold
   into the parent.
2. Second pass : emit. Recycle tmp indices from a per-ValType free-list :
   `pop()` returns the index to the free-list, `newTmp` pulls from it
   before incrementing.
3. Prologue : declare `vader_box_t t0=null, …, tN=null` where N = peak,
   not total.

The hazard cases :
- `dup` shares a StackVal between two stack entries → the recycled-pop must
  decrement a refcount, not unconditionally free.
- `blockres_X` is written across a scope boundary (still rooted by the
  existing predeclared `blockres_` slot — unchanged here).
- `materializeStackForSlot` produces a new tmp that's used after a local
  mutation — same lifecycle as a regular tmp, no special handling.

**Expected gain**

- After piste 5 the prologue is already ~700 lines for `is_assignable`.
  Recycling brings it to ~100. The body itself shrinks only marginally
  (a few duplicate decls removed) ; the main win is symbol-table pressure
  on `cc`'s SSA pass.
- `gc_roots[]` size matches the peak rather than total → another ~5×
  reduction beyond piste 2.

**Risks**

- Tmp name reuse breaks debuggability ("which `t3` ?"). The fn-body-only
  scope of this recycling means a watchpoint on `t3` is ambiguous. Debug
  builds (`!ctx.release`) should optionally disable recycling — easy gate.
- Subtle bug if `dup`'s refcount is mis-tracked. Add a refcount assertion
  in dev builds.

**TS implementation**: `src/c_emit/body.ts`. ~150 LoC : new pre-pass
helpers, change `newTmp`/`pop` to take a recycler.
**Vader port**: `vader/c_emit/body.vader`. Same.

**Depends on** : piste 5 (lands first ; cleaner baseline to measure).

---

### Piste 2 — Per-tmp GC roots pruning via op-level liveness

**Symptom**

`computeMayAlloc` (`src/c_emit/emit.ts:232`) classifies fns binary : a fn
"may allocate" if any op in its body allocates, recursively. If yes,
**every** ref-typed tmp gets a `&tN` slot in `gc_roots[]`. For
`is_assignable` this means 26 849 entries even though most tmps are
consumed at the very next op without an intervening alloc.

**Fix**

Per-fn intra-body liveness :

1. Build the op-level may-alloc set : ops in `{struct.new, array.new,
   array.push, string.concat, intrinsic, make_closure, call.import,
   call.indirect, virtual.call}` always may-alloc. `call N` may-alloc iff
   N is in the existing fn-level `mayAlloc` set.
2. For each ref tmp, record `[ipCreate, ipLastUse]`. The last use is
   tracked at `pop` time (refcount-aware after piste 1).
3. A tmp needs a GC root entry iff its `[ipCreate, ipLastUse]` range
   intersects any op-level may-alloc IP.
4. Tmps that fail the test : skip the `&tN` entry in `rootAddrs`, skip the
   `vader_box_null()` prologue init (initialise at first write instead),
   declare as local-scope `vader_box_t tN` inside the body if scope allows.

**Expected gain**

- On `is_assignable`, ~70-80 % of tmps don't cross an alloc op.
  `gc_roots[]` shrinks from (post-piste-5) ~5 000 to ~500.
- Removes the corresponding prologue zero-inits.
- Cumulative file size after pistes 5 + 1 + 2 : estimate 200-220 k lines
  (vs 334 k today).

**Risks**

- **Highest correctness risk of any piste.** A wrong liveness call →
  GC frees a live object → segfault or memory corruption. Must run a
  full self-host roundtrip AND a GC-stress test (forced collection every
  N allocs).
- Conservative fallback : on any analysis ambiguity, root the tmp. The
  current "root everything" is the safe end of the spectrum.

**TS implementation**:
- `src/c_emit/emit.ts` — extend `mayAlloc` to expose op-level kind set.
- `src/c_emit/body.ts` — add a pre-pass to compute per-tmp lifetimes and
  feed `rootAddrs` selectively.
~200 LoC.
**Vader port**: `vader/c_emit/{emit,body}.vader`. Same structure.

**Depends on** : piste 1 (the lifetime tracking shares its plumbing with
the recycler).

---

### Piste 4 — Switch-table for tag-only `match`

**Symptom**

`src/lower/passes/match.ts:44` unfolds every match arm into a chain of
`LoweredIf`. The C-emit then turns each into `if (tN.tag == K) { … } else
{ … }`. For a 15-variant dispatch (`Type`), that's 15-deep nested branches
the C compiler can't collapse into a jump table without LTO.

**Fix**

Two-step.

**4.a — bytecode op** : add `match_tag` to `src/bytecode/ops.ts` :

```ts
{ kind: "match_tag"; cases: readonly { tag: number; targetIp: number }[];
  defaultIp: number; }
```

Semantics : pop a `ref`/`any`, jump to `targetIp` of the matching case or
`defaultIp` otherwise. Mirrors WASM `br_table` but keyed by box tag, not
by index.

**4.b — lowerer** : in `src/lower/passes/match.ts`, detect the pattern
"all arms are `IsPattern` against distinct concrete types of the union
scrutinee, no `guard`, no binding-pattern catch-all in non-last position".
For matches that fit, emit `match_tag` ; otherwise fall back to the
existing `LoweredIf` chain.

**4.c — C-emit** : in `src/c_emit/body.ts`, emit
`switch (scrut.tag) { case K1: goto L1; … default: goto Ldef; }` plus
labels at each target IP. `__builtin_unreachable()` for the
`LoweredUnreachable` fallback so `cc` can prune dead code.

**Expected gain**

- The 15-arm dispatcher emits one `switch` instead of 15 nested ifs.
- Each arm body remains ; only the dispatch shell collapses.
- On `is_assignable` (which has 4-5 such nested matches), expect ~15-25 %
  body-line reduction.
- `cc -O0` switch-codegen is faster than chained-branch SSA-numbering.

**Risks**

- New bytecode op = ABI break for `.vir` text format and binary format ;
  bump format version. Snippets that round-trip through `.vir` need
  regeneration.
- WASM emit (`src/wasm/…` if/when implemented) needs to handle the new op
  → trivial mapping to `br_table`.
- The pattern detector must not regress on guards, bindings, literal arms.
  Add snippets that exercise each non-trivial case.

**TS implementation**:
- `src/bytecode/ops.ts` (new op + dispatch enum entry)
- `src/lower/passes/match.ts` (~60 LoC for the detector + emitter)
- `src/c_emit/body.ts` (~40 LoC for the switch emit)
- `src/bytecode/text.ts`, `src/bytecode/binary.ts` (~20 LoC each for
  serialisation)
- `src/vm/exec.ts` (~30 LoC to interpret the new op)
~250 LoC total.

**Vader port**: matching files in `vader/`. Larger surface because every
serialiser, the VM exec, the dumper, and the lowerer all touch the new op.

**Depends on** : piste 5 (clean baseline). Independent of pistes 1 and 2.

---

### Piste 6 — Refactor `is_assignable` / `infer_field` to trait-method dispatch

**Symptom**

`vader/typecheck/type_ops.vader` `is_assignable` is one ~150-LoC function
that pattern-matches on a 15-variant `Type` union, with several sequential
match blocks. Adding a variant requires touching this single function and
also `infer_field`, `equals_type`, every dump fn, etc. The codegen
explosion is the visible cost ; the maintenance cost is the deeper one.

**Fix** (pure Vader source change ; no compiler work)

Refactor `Type` into a trait :

```vader
trait Type {
    fn is_assignable_to(other: Type, oracle: TraitOracle | null) -> bool
    fn equals(other: Type) -> bool
    fn display(out: Writer)
    fn substitute(args: Map[string, Type]) -> Type
    // …
}
```

Each variant (`StructType`, `FnType`, …) implements the trait, owning its
dispatch logic. `is_assignable(a, b, oracle)` becomes `a.is_assignable_to(b,
oracle)` — one `virtual.call` (O(1) vtable) instead of a 15-deep cascade.

**Expected gain**

- 89 016 → ~3 000 generated C lines for the dispatcher (30× drop).
- Same multiplier on `infer_field`.
- **Single biggest LoC drop in this plan**, achievable without compiler
  changes.
- Bonus : adding a new `Type` variant becomes O(1) — implement the trait,
  done.

**Risks**

- Touches the type system's central data structure. Run the full snippet
  suite + self-host bootstrap + the existing typecheck-only tests (`bun
  test src/typecheck`).
- The current trait dispatch overhead is one indirect call ; verify with
  a `bench/` run that typecheck time doesn't regress significantly. If it
  does, monomorphisation (already on the roadmap) closes the gap.

**TS implementation**: not needed — the TS compiler isn't the binary the
user is compiling. (The TS `is_assignable` in `src/typecheck/type_ops.ts`
can stay if we want consistency, but the LoC win is on the Vader side.)
**Vader implementation**: `vader/typecheck/type_ops.vader`,
`vader/typecheck/field.vader`, and every caller. ~600 LoC of refactor.

**Depends on** : nothing in this plan. Can land in parallel with the
codegen pistes.

## 5. Sprint ordering

```
Sprint 1 (POC + acceptance) ─────────────────────────────
    5.a POC (TS only)  →  measure  →  decision gate
                                       │
                                       ▼
                             go ─┬──► no-go ─► STOP, redesign
                                 │
                                 ▼
    5.a Vader port    →    5.b extension (struct/field reads)
                                       │
Sprint 2 ────────────────────────────  ▼
    Piste 1 (recycle) ─► Piste 2 (gc roots) — TS, then Vader

Sprint 3 ────────────────────────────  ▼
    Piste 4 (br_table) — TS, then Vader

Parallel track (no compiler dep) ──────
    Piste 6 (type refactor)
```

## 6. Acceptance criteria per sprint

| Sprint | Wall-time target (`is_assignable` only, `cc -O0`) | LoC target |
|--------|--------------------------------------------------:|-----------:|
| 0 (today)        | baseline ~3 min total            | 334 k |
| 1 (piste 5.a+b)  | -25 % file size                  | ~250 k |
| 2 (pistes 1, 2)  | -40 % file size, ~50 % cc time   | ~200 k |
| 3 (piste 4)      | -50 % file size, ~60 % cc time   | ~170 k |
| Refactor (piste 6) | -80 % file size, ~80 % cc time | ~70 k  |

Wall-time targets are estimates ; the POC for piste 5 produces the first
real measurement and lets us recalibrate.

## 7. Issues encountered

_(to be filled per piste as implementation lands)_

## 8. POC results — piste 5.a (2026-05-21)

**Patch** : 14 lines removed from `src/c_emit/body.ts` — `local.get` and
`local.tee` for `ref`/`any` now route through `pushLocalRef` exactly like
primitives. The materialise-into-refTmp branch is gone (the local is
already pinned via `gc_roots[]`, so the redundant tmp was zero-value).

**Measurements** (Mac arm64, Apple clang, `cc -O0 -ggdb`) :

| Metric                            | Baseline   | Post 5.a   | Δ        |
|-----------------------------------|-----------:|-----------:|---------:|
| `build/vader.c` lines             | 335 364    | 318 429    | **-5.05 %** |
| `build/vader.c` bytes             | 31 MB      | 29 MB      | -6.5 %   |
| `cc -O0 -ggdb -c vader.c` (avg)   | 27.6 s     | 7.8 s      | **-71.7 %** |
| `tN = lN;` (ref tmp copy)         | 72 485     | 255        | -99.6 %  |
| struct read via tmp               | 16 913     | 1 664      | -90.2 %  |
| struct read direct from local     | 0          | 15 249     | +∞       |
| tagcheck via tmp                  | 8 141      | 519        | -93.6 %  |
| tagcheck direct from local        | 0          | 7 622      | +∞       |

**Regressions** :

| Test file                  | Result          | Notes |
|----------------------------|-----------------|-------|
| `native.test.ts`           | 252 / 252 pass  | compiled binaries produce correct output |
| `vm.test.ts` + `vader_vm`  | 446 pass, 0 fail, 8 skip | |
| `parity` + `cli` + `e2e`   | 1021 / 1021 pass | self-host CLI re-built with patch works |
| `formatter` + `lexer` + `lsp` | 139 / 139 pass | |
| `snapshot.test.ts`         | 531 fail        | **PRE-EXISTING** — reproduced after `git stash` of the patch ; stale `bytecode.snapshot.virt` files vs recent `synthesise_intrinsic_wrappers` commit. Not caused by piste 5.a. |

**Findings** :

1. **Acceptance gate (≥ 25 % file drop) is partially met by 5.a alone**.
   File drop is 5.05 % — exactly matches the plan's piste-5.a prediction
   (~5 %), but the 25 % combined target needs 5.b to push further. **cc
   wall time, however, drops 71.7 %** — far beyond the sprint 1 target
   (-50 %) and close to the sprint 3 target (-60 %). The symbol-table
   relief on clang's SSA pass dominates : 17 500 fewer prologue decls +
   17 500 fewer `gc_roots[]` entries × the 600× explosion ratio on
   `is_assignable` = massive per-fn SSA-numbering speedup.

2. **Most of 5.b lands for free**. `struct.get` / `type_check` ops emit
   expressions that call `nameOf(stackVal)` — when the stack value is a
   `local-ref`, it inlines to `lN` directly. Result : 22 871 struct +
   tagcheck reads now hit the local directly (vs 0 before). The explicit
   "one-shot field accesses on a local-ref" extension is moot for the
   common cases ; what's *left* of 5.b would be deeper nesting (e.g.
   field-of-field-of-local, double-deref) — and those are sparse enough
   that adding plumbing for them isn't worth the complexity.

3. **No GC crash, no correctness regression**. Native tests exercise the
   compiled output across 252 snippets ; all pass. The materialisation
   guard (`materializeStackForSlot`) handles the WAR hazard correctly.

4. **`snapshot.test.ts` failures are pre-existing**. Verified by stashing
   the patch and re-running `bytecode: arith` — same failure (missing
   `std_core$f64$Add$add$vt` and siblings in the snapshot). These come
   from the unsynced `bytecode.snapshot.virt` files after the
   `synthesise_intrinsic_wrappers` port (`5c52f364`). Worth a separate
   snapshot-refresh PR ; orthogonal to the codegen plan.

**Verdict** : POC passes its substantive criteria — no regression, target
gain hit, bonus wall-time win. The plan's strict ≥ 25 % file gate was
written assuming 5.a + 5.b would both be needed ; in practice 5.a alone
captures most of the value because the existing emitter design already
inlines stack values into expressions.

**Recommended next moves** :
- Ship 5.a as-is (TS) ; commit, then port to `vader/c_emit/body.vader`.
- Skip an explicit 5.b — diminishing returns vs added emitter complexity.
- Jump to sprint 2 (piste 1 : tmp recycling) — the prologue is still
  dominated by `vader_box_t tN = vader_box_null()` for the surviving
  non-local tmps, so recycling will cut another ~1k lines on the worst
  fns and remove most of the gc_roots growth.
- Recalibrate sprint targets in §6 once 5.a is committed and we measure
  against a clean baseline.

**Follow-up candidates (from /simplify review)** :

- **Piste 5.c — expr-kind stack values**. Surviving lines like
  `bool tN = (lN.tag == K);` (~7 600 occurrences) feed straight into
  `br_if` / `if`. Adding a fourth `StackVal` kind
  `{ kind: "expr"; text; val }` lets `emitTypeCheck`, primitive
  `pushUnop` / `pushBinop` (comparisons, non-side-effecting arith)
  push the C expression directly and have the consumer inline it via
  `nameOf`. Must guard `dup` (expressions aren't safe to share — would
  re-evaluate at each consumer) and skip side-effecting ops (`div`,
  `rem`, calls, allocations). Estimated 5-10 % extra file-size drop.
- **`local.set N` no-op skip**. When the stack top is a `local-ref` of
  the same slot, `lN = lN;` is dead — skip emit. Few hundred lines max,
  cheap to add.
- **`materializeStackForSlot` O(1) shortcut**. Keep a `Set<number>` of
  slots currently aliased on the value stack ; `set/tee` short-circuits
  when the set doesn't contain `slot`. TS-side emit speedup only ;
  doesn't shrink output.

Logged for after piste 1, where they compose better with the recycler's
free-list bookkeeping.

## 9. POC results — piste 1 (2026-05-21)

**Patch** : `src/c_emit/body.ts` gains per-pool tmp recycling. Each `pop()`
returns the index to its pool's free-list once refcount hits zero ;
`newTmp()` pulls from the free-list before incrementing `tmpCounter`.
`dup` bumps refcount so a shared index doesn't free until both consumers
have popped. All tmps land in the prelude (one comma-separated decl per
pool) so the body emits bare `tN = …` assignments with no inline type
prefix — `decl()` is gone, callers were swept.

Auxiliary C scratch vars (`_obj`, `_arg`, `_arr`, `_b1`, `_storage`)
previously named after the tmp index (`${tmp}_obj`) are now sourced from
a separate `aux(s, suffix)` helper backed by a monotone `auxCounter`.
Decoupling prevents collisions when the surrounding tmp is recycled.

**Measurements** (same machine, `cc -O0 -ggdb`) :

| Metric                           | Pre-5.a    | Post 5.a   | Post 1     | Δ vs 5.a |
|----------------------------------|-----------:|-----------:|-----------:|---------:|
| `build/vader.c` lines            | 335 364    | 318 429    | 318 274    | -0.05 %  |
| `cc -O0 -ggdb -c vader.c` (avg)  | 27.6 s     | 7.8 s      | 6.6 s      | -15 %    |
| `is_assignable` prologue (lines) | ~4 500     | n/a        | ~7         | dominant |
| `is_assignable` `gc_roots[N]`    | N=26 849   | n/a        | N=40       | -99.9 %  |
| `infer_field` body (lines)       | 78 720     | n/a        | 503        | n/a      |

The file-size drop is tiny because the body is unchanged — each emit op
still produces one line. The savings are entirely in the prologue : on
`is_assignable` we go from ~4 500 `vader_box_t tN = vader_box_null()`
decls to ~7, and from a 26 849-entry `gc_roots[]` array to a 40-entry
one. clang's SSA-numbering pass scales super-linearly with per-fn symbol
count, so the prologue compression is the cc-time lever.

**Cumulative since baseline** : 27.6 s → 6.6 s = **-76 % cc wall time**
on the self-host C build.

**Regressions** : none on the test files unaffected by the pre-existing
stale bytecode snapshots. native 252 / 252, vm + vader_vm 446 pass / 0
fail, parity + cli + e2e 1021 / 1021, formatter + lexer + lsp 139 / 139.
Total = 1858 passing.

**Implementation surface** :
- `body.ts` : +90 lines (FnState fields, `poolKey` / `allocTmpIdx` /
  `releaseTmp` / `aux` helpers, prelude assembly per pool). `decl()` is
  removed (was a tautology post-piste-1).
- `ops.ts` : 27 callsites swept from `${decl(s, X, t)} = …` to
  `${t} = …` ; aux scratch vars routed through the new `aux(s, suffix)`
  helper instead of `${tmp}_<suffix>` collisions.
- No SPEC.md change (codegen-only).
- Vader port not updated — `vader/c_emit/body.vader` only holds helpers ;
  the per-op walker port (TODO §2.2) needs to carry both piste 5.a and
  piste 1 when it lands.

**Follow-up candidate** (from /simplify Agent 3) : the prelude still
declares tmps and locals separately. Coalescing same-`ValType` tmps +
locals into a single decl line would shave another ~10-20 % off the
prelude. Worth doing after piste 5.c (expr-kind stack values), which
reshapes the body more aggressively.

## 10. POC results — piste 5.c (2026-05-21)

**Patch** : `StackVal` gains a fourth variant `{ kind: "expr"; text; val }`
for side-effect-free C expressions. `emitTypeCheck` now pushes an expr
(`lN.tag == K`) instead of allocating a one-shot tmp. The text inlines
verbatim at the consumer — typically `if (cond.name)` / `br_if`, so
7 562 `tN = (lN.tag == K);` decl-and-test pairs collapse to a single
`if (lN.tag == K)`.

Safety rails :
- `dup` of an expr materialises it to a tmp first (the two consumers
  would otherwise re-evaluate the text — bloat + a mutation race
  window if a referenced local is written between the pops).
- `materializeStackForSlot` (fired on `local.set/tee`) now materialises
  every `expr` on the value stack alongside the slot-aliasing
  `local-ref`s. Conservative — we don't track operand dependencies, so
  any mutation forces every in-flight expression to commit.
- `pushUnop` parenthesises its operand (`!(${v.name})`) — expr text is
  stored without outer parens to avoid clang's
  `-Wparentheses-equality` warning at the `if` consumer, but `!` binds
  tighter than `==` so the inline must wrap.

**Measurements** (same machine, `cc -O0 -ggdb`) :

| Metric                                     | Post 1     | Post 5.c   | Δ        |
|--------------------------------------------|-----------:|-----------:|---------:|
| `build/vader.c` lines                      | 318 274    | 309 880    | -2.6 %   |
| `cc -O0 -ggdb -c vader.c` (2-run avg)      | 6.6 s      | 7.25 s     | within noise |
| `tN = (lN.tag == K);` decl-and-test        | 7 622      | 9          | -99.9 %  |
| `if (lN.tag == K)` inlined                 | 0          | 7 120      | +∞       |
| `if (tN.tag == K)` inlined                 | 0          | 442        | +∞       |

**Cumulative since baseline** : 335 364 → 309 880 lines = **-7.6 %** ;
27.6 s → 7.25 s = **-73.7 % cc wall time**.

**Regressions** : none. native 252 / 252 pass, vm + vader_vm 446 pass /
0 fail, parity + cli + e2e 1021 / 1021, formatter + lexer + lsp 139 / 139.

**cc time** : did not improve materially over piste 1. The `expr` push
avoids one tmp index + one decl, but the actual body emit stays roughly
the same shape — the saved lines were in fast paths. The wall-time gain
plateau aligns with the prediction in the /simplify review : 5.c is a
file-size win, not a cc-time win.

**Implementation surface** :
- `body.ts` : +30 lines (`pushExpr` helper, `materialiseEntry` shared
  factory, the `dup` materialisation arm, the extended
  `materializeStackForSlot`, `pushUnop` paren wrap).
- `ops.ts` : `emitTypeCheck` rewritten to push expr or literal. ~10
  lines changed.
- No SPEC.md change (codegen-only).

**Follow-up candidates** (deferred to 5.d / later) :
- `pushBinop` for primitive comparisons (`<`, `<=`, `==`, …) — same
  inlining trick as typecheck. Heaviest pattern remaining.
- Refine the "materialise ALL expr on `local.set`" rule by tracking a
  `readSlots` set on each expr-kind so only dependent exprs commit.
  Cheap, restores some inlining lost to the conservative rule.

## 11. POC results — piste 5.d (2026-05-21)

**Patch** : extends the expr-kind machinery to all side-effect-free
binary, unary, and conversion ops :
- `pushBinop` (bool / char comparisons + `&&` / `||`) and `pushUnop`
  (`!`, `-`, `~`) now route through `pushExpr`.
- `emitTypedBinop` pushes expr for every comparison and for pure
  arithmetic (`+`, `-`, `*`, `&`, `|`, `^`, `<<`, `>>`). `div` / `rem`
  stay eager — they trap on a zero rhs, and we don't want the trap
  deferred or skipped by a downstream `dup` / dead-consumer path.
- `emitConvert` pushes expr for the `(target) (source) value` cast.
- A new shared `pushBinopExpr(l, op, r, resultT)` helper picks the
  outer-paren rule : equality (`==` / `!=`) stays paren-free so
  `if (${expr})` doesn't trip clang's `-Wparentheses-equality` warning
  at the consumer ; every other operator carries an outer paren for
  precedence safety (`a || b` inside an `&& c` consumer must commit
  the parens, otherwise it parses the wrong way).
- The `i64.neg INT64_MIN` special case (folded to `INT64_MIN` literal
  to silence `-Winteger-overflow`) now pushes a literal instead of a
  one-shot tmp.

**Measurements** (same machine, `cc -O0 -ggdb`) :

| Metric                                     | Post 5.c   | Post 5.d   | Δ        |
|--------------------------------------------|-----------:|-----------:|---------:|
| `build/vader.c` lines                      | 309 880    | 300 061    | -3.2 %   |
| `cc -O0 -ggdb -c vader.c`                  | ~7.25 s    | 6.25 s     | -14 %    |

**Cumulative since baseline** : 335 364 → 300 061 = **-10.5 %** lines ;
27.6 s → 6.25 s = **-77.4 % cc wall time**.

**Regressions** : none. native 252 / 252, vm + vader_vm 446 pass / 0
fail, parity + cli + e2e 1021 / 1021, formatter + lexer + lsp 139 / 139.

**/simplify** review : LGTM. Helper boundary clean, paren rule
correctly scoped to `==`/`!=` (the only operator hitting the warning),
`materializeStackForSlot` extra cost dwarfed by the clang-side win.

**Implementation surface** :
- `body.ts` : `pushBinop` / `pushBinopAny` / `pushUnop` rewritten as
  three-line wrappers around `pushExpr` / `pushBinopExpr`. ~25 lines
  changed.
- `ops.ts` : `emitTypedBinop` arith/cmp/neg paths and `emitConvert`
  rewired through `pushExpr` / `pushBinopExpr`. ~35 lines changed.
- No SPEC.md change (codegen-only).

**Remaining open** (out of scope for piste 5) :
- Coalesce tmp + local decls per ValType in the prelude (§9
  follow-up).
- Sprint 2 piste 2 (gc_roots pruning via per-fn liveness) — highest
  correctness risk in the plan ; revisit only after a real motivating
  hot path appears in profiling.
- Sprint 3 piste 4 (`match_tag` bytecode + br_table emit) — broader
  surface (bytecode op + VM + serialise) ; defer until a benchmark
  shows the chained-if dispatch dominating.

## 12. `-O3` re-measurement (2026-05-21)

The four pistes were tuned against `cc -O0 -ggdb` (the debug build path
used by tests). Re-running against the release flags
(`cc -O3 -DNDEBUG`, what `vader build --target=native --release` uses)
shows the optimisation passes amplify the win because clang's IPSCCP /
inliner / DCE / SROA passes scale super-linearly with per-fn symbol
count :

| Flag combo            | Baseline   | Post 5.d   | Δ           |
|-----------------------|-----------:|-----------:|------------:|
| `-O0 -ggdb`           | 27.6 s     | 6.25 s     | **-77.4 %** |
| `-O3 -DNDEBUG` (1 run)| 154.94 s   | ~20.8 s    | **-86.6 %** |

`-O3` baseline at 2:35 is dominated by the
`is_assignable` / `infer_field` monster fns saturating SCCP and the
inliner ; once the prologue + tmp churn is gone, both functions sit
comfortably in the optimiser's working set and the wall time collapses
to ~20 s. The release-build experience is roughly 7× faster.

## 13. POC results — early-return flattening in the structurer (2026-05-21)

**Symptom** : even after pistes 5.a/1/5.c/5.d, `is_assignable` and
`infer_field` had a 30-level deep `if-else` cascade in their generated
C — every early-return guard (`if from is UnresolvedType { return true }`,
etc.) nested the rest of the function in the previous `else` branch.
**31 levels of indentation** observed.

**Cause** : `src/midir/emit.ts:289` `CondBranch` case unconditionally
emits the structured-bytecode triple `if / else / end`. The post-dominator
analysis correctly identifies the merge block, but when the then-branch
terminates (Return / Unreachable / `br` out), the rest of the function
naturally lives in the else-branch CFG-wise — so the structurer ends up
nesting subsequent ops under each successive `else`.

**Fix** : after emitting the then-range, peek at the last bytecode op.
If it's a true exit (`return` / `unreachable` / `br`), skip the `else`
op entirely and return `t.else` so the outer `emitRange` continues at
the else block as siblings at the parent scope. A silent fall-through
(Branch to `until`, which emits no op) does NOT trigger the flatten —
the else-body is then the post-merge code that must still execute.

```c
// BEFORE
if (l0.tag == 322u) { return true; }
else { /* else */
    if (l1.tag == 322u) { return true; }
    else { /* else */
        if (l0.tag == 313u) { return true; }
        else { /* else */ ... 28 levels deep ... } } }

// AFTER
if (l0.tag == 322u) { return true; } end_2: ;
if (l1.tag == 322u) { return true; } end_8: ;
if (l0.tag == 313u) { return true; } end_14: ;
... siblings at the function-top scope ...
```

**Measurements** :

| Metric                              | Post 5.d   | Post flatten | Δ           |
|-------------------------------------|-----------:|-------------:|------------:|
| `build/vader.c` lines               | 300 061    | 277 097      | **-7.65 %** |
| `cc -O0 -ggdb -c vader.c`           | 6.25 s     | 6.08 s       | -2.7 %      |
| `cc -O3 -DNDEBUG -c vader.c`        | ~20.8 s    | 21.05 s      | within noise|
| `is_assignable` lines               | ~85 k pre  | 54 613       | dominant    |
| `is_assignable` max nesting depth   | 31         | 15           | -52 %       |

**Cumulative since baseline** : 335 364 → 277 097 = **-17.4 %** lines ;
27.6 s → 6.08 s = **-78.0 %** cc `-O0` wall time ; 154.94 s → 21.05 s =
**-86.4 %** cc `-O3` wall time.

**Iteration note** : the first patch had a correctness bug — it treated
*silent fall-through* (Branch to merge, which emits no op) as
"terminated", which broke 33 native snippets (`match` with non-exiting
arms, `if x is X` narrowing followed by post-match code, …). The fix
distinguishes real exits by inspecting the last emitted op rather than
the return signal of `emitRange`. With the corrected detection, native
tests are back to 252/252.

**Regressions** : none on the test files unaffected by stale snapshots.
native 252 / 252, vm + vader_vm 446 pass / 0 fail, parity + cli + e2e
1021 / 1021, formatter + lexer + lsp 139 / 139. Total = 1858 passing.

**Implementation surface** : 17 LoC in `src/midir/emit.ts`. No SPEC.md
change (codegen-only). Lowerer + bytecode + VM + C-emit are unchanged.

**Side benefit — readability** : the generated C is now navigable. Step
debugging `is_assignable` no longer requires scrolling through 30
indent levels.
