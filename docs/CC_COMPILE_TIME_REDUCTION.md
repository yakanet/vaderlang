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
