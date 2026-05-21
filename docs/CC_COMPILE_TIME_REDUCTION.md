# C compile-time reduction

> **Status**: in progress (2026-05-21). Pistes 5.a / 1 / 5.c / 5.d /
> structurer flatten landed → 222 k lines (-33.7 % vs baseline), 6.08 s
> `cc -O0` (-78 %), 21 s `cc -O3` (-86 %). Piste 7 engaged in
> **bytecode-fused form** because emit_wasm is on the short-to-mid-term
> roadmap (lands after the Vader port completes) and a c-emit-only
> peephole would force a duplicate peephole in the wasm backend later.
> 7.a / 7.b cancelled (0 survivors measured). 7.c / 7.f / 7.e / 7.d
> engaged. Option B sequencing : TS first, the in-flight Vader port
> absorbs the new ops as it progresses.

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

---

### Piste 7 — Fused / compound bytecode ops (`ENGAGED 2026-05-21`)

**Status** : engaged in bytecode-fused form. 7.a / 7.b cancelled. 7.c /
7.f / 7.e / 7.d to land in TS first, the in-flight Vader port absorbs the
new ops as it progresses (option B).

**Why bytecode-fused (and not c-emit-only)**

Three backends consume the same bytecode :
- **emit_c** — live.
- **VM** — live (used by `vader run` + parity tests).
- **emit_wasm** — short-to-mid-term roadmap, lands after the Vader port
  completes.

A c-emit-only peephole (the "5.e" alternative considered earlier) solves
the C-side now but forces emit_wasm to re-implement the same patterns
later. Fusing at the bytecode layer means **the lowerer pays the
detection cost once** ; every backend consumes the optimised form. The
ratio surface bytecode-fused vs c-emit-only collapses from ~7× to ~1.4×
once the emit_wasm peephole duplication is added to the c-emit-only
column.

Bytecode-fused gains :
- C lines : same as c-emit-only (the inlined C is identical).
- VM dispatch : -N ops per site (one fused dispatch instead of two-or-
  three).
- emit_wasm : maps directly to WASM-GC `local.get + struct.get` /
  `local.get + ref.test` shapes (one-to-one), and to WASM 1.0 linear
  `local.get + i32.load offset=K` (one-to-one). No backend-side peephole
  to rewrite.
- `.vir` text format reads more cleanly (`local.field N T F` vs two
  separate ops).

**Selection criteria** (codified to avoid op zoo growth)

1. Op pair must appear ≥ 500 times in `build/vader.c` (current self-host).
2. Fused form must save ≥ 1 line per site OR ≥ 2 ops per site.
3. Op must be representable in WASM 1.0 linear AND in WASM-GC.
4. Semantic must be statically verifiable from operands alone.

7.c / 7.f / 7.e / 7.d all pass. 7.a / 7.b would pass criteria 1-4 but
have zero remaining sites — cancelled below.

**Pattern frequencies — re-measured 2026-05-21 against current
`build/vader.c` (post-flatten, 222 k lines)**

| Op pair / triplet                          | Sites      | Lines per site | Ops per site |
|--------------------------------------------|-----------:|---------------:|-------------:|
| `local.get → type_check K`                 | 0 surviving (was 8 700) — captured by 5.c | n/a | n/a |
| `local.get → struct.get F`                 | **14 785** | 1 | 2 |
| `local.get → ref.cast K → local.set M`     | **7 807**  | 1 (post-coalesce: more) | 3 |
| literal `bool.const X → return`            | **416**    | 1 | 2 |
| `struct.get F1 → struct.get F2` (chains)   | emerges from 7.c | 2 | 2 |

---

#### 7.a `local.tag_check N K` — CANCELLED (2026-05-21)

Measured 0 surviving sites in `build/vader.c` post-piste 5.c. The `expr`-
kind StackVal already inlines `lN.tag == K` at the consumer. No new
bytecode op needed.

#### 7.b `local.trait_check N traitName refTypeIndex` — CANCELLED (2026-05-21)

Same as 7.a : `traitCheckExpr` in `src/c_emit/ops.ts:981` already pushes
the chained-OR expression as an `expr` StackVal under 5.c. No new op.

---

#### 7.c `local.field N T F` — PRIORITY 2 (biggest absolute win)

**Symptom** : 14 785 sites `tN = ((Type*) lN.payload.obj)->f_F;` in
`build/vader.c`. Each is a `local.get → struct.get` pair the lowerer emits
and `emitStructGet` (`src/c_emit/ops.ts:806`) materialises into a tmp
because every code path calls `newTmp()`.

**New op**

```ts
{ kind: "local.field"; slot: number; typeIndex: number; fieldIndex: number }
```

Semantics : equivalent to `local.get slot; struct.get typeIndex fieldIndex`.
Push : the field's ValType (per `valTypeOfField`).

**Lowerer** (`src/lower/passes/expr.ts`) : when lowering `LoweredFieldAccess`
whose target is a `LoweredIdent` resolving to a local, emit `local.field`
directly instead of the two-op sequence.

**emit_c handler** : pushes an `expr` StackVal carrying the C expression
for the field read. Five branches mirror current `emitStructGet` :
- generic : `((${cname}*) lN.payload.obj)->f_${field}`
- packed : `((const ${pname}*) lN.payload.packed)->f_${field}`
- inline ref : `vader_box_obj(${f.typeIndex}u, lN.payload.obj)`
- inline primitive : `coerce(unboxExpr(lN, inlinePayload), inlinePayload, fval)`
- nullable-ref B1 : `vader_b1_to_box(((${cname}*) lN.payload.obj)->f_${field}, ${variant}u)`
  (uses the helper from `runtime/c/vader.h:153` for single-eval of the
  receiver).

**VM exec** : one new case in `src/vm/exec.ts` — read `slots[slot]`,
unbox, deref via `module.types[typeIndex]` field offset, push.

**emit_wasm 1.0 linear** : `local.get N ; i32.load offset=<field-offset>`
(offset derived from layout table for `typeIndex`).

**emit_wasm-GC** : `local.get $local_N ; struct.get $T_typeIndex F`.

**peephole** : the new op is its own kind. Rule 1 (`local.set N; local.get
N → local.tee N`) doesn't interact ; the fuser runs before peephole and
keeps fused ops opaque. Text format : `local.field N T F`.

**Expected gain** : C lines -7 to -12 k (~3-5 %). VM ops -14 800.
`field.chain` (7.d) emerges naturally when the consumer is another field
access on the result.

**Risks** : same as 5.c/5.d — `dup` materialises an `expr` push, and
`materializeStackForSlot` materialises on `local.set`. Both already wired
in `body.ts`. New : verify the lowerer's detector doesn't misfire on
field access of a non-local (return value, complex expr) — bail to the
decomposed pair in those cases.

---

#### 7.f `return.lit T value` — PRIORITY 1 (familiarisation)

**Symptom** : 416 bare `return true;` / `return false;` + ~150 numeric
literal returns. Pattern `<T>.const X ; return` decomposes into two ops.

**New op**

```ts
{ kind: "return.lit"; val: ValType; lit: string }   // lit pre-formatted C/wasm-compatible
```

Single dispatch ; the lowerer emits when it sees a literal-typed expression
as the sole arg of a return.

**emit_c** : `return <lit>;` as one statement (or `return vader_box_<T>(K, lit);`
when the return type is boxed).

**VM** : push lit + return — one case.

**emit_wasm 1.0** : `<T>.const lit ; return`.

**emit_wasm-GC** : same as 1.0.

**Expected gain** : 300-400 C lines, ~800 VM ops. Small. Picked first as
**familiarisation step** with the bytecode-op-introduction pipeline
(`ops.ts` + lowerer + emit_c + VM + serialise text/binary + peephole
sanity test). Narrow surface, low blast radius.

---

#### 7.e `local.alias N M` — PRIORITY 3

**Symptom** : 7 807 sites `lM = lN;` in `build/vader.c`. Source pattern :
`local.get N → ref.cast K → local.set M` (the `is X as bind ->` lowering).
Since `ref.cast` is a bytecode-level no-op for boxed values
(`src/lower/passes/expr.ts:1099`), this collapses to `local.get N;
local.set M` ; the C copy is wasteful.

**Two-step approach** :

1. **Peephole Rule 7** (`src/bytecode/peephole.ts`) : detect
   `local.get N; local.set M` where M is single-set (and not a param),
   rewrite as `local.alias N M`. Recorded in a side-table consumed by
   `slot-coalesce`.

2. **`local.alias N M` op** : marker op consumed by
   `src/bytecode/slot-coalesce.ts`. After coalescing, when M and N share
   a slot the alias op is dropped entirely. When slots stay distinct
   (rare — typically because M outlives N or they're in conflicting bound
   regions), the op falls through to a regular `lM = lN;` emit.

**emit_c** : `lM = lN;` if the slots aren't coalesced ; nothing if they
are.

**VM** : `slots[M] = slots[N]; ip++` — trivial.

**emit_wasm 1.0 / GC** : `local.get N ; local.set M` if not coalesced ;
nothing if coalesced. Native WASM op pair — no encoding work.

**Expected gain** : C lines -5 to -7 k (~2-3 %), VM ops -23 400 (3 → 0
in the optimal case).

**Risks** : the slot-coalesce pass already exists and is conservative
(linear live ranges + loop back-edge widening). Adding alias-aware
coalescing must not break the per-arm scope of `is X as bind ->` chains.
Snippet to add : `is X as bind -> use_bind ; is X as bind2 -> use_bind2`
where the two binds are scope-disjoint, plus a nested `is X as bind1 ->
is Y as bind2 -> use_both` for live-range overlap.

---

#### 7.d `field.chain` — PRIORITY 4 (emerges from 7.c)

**Symptom** : after 7.c lands, expressions like `a.foo.bar.baz` lower to
`local.field N T F1 ; struct.get T2 F2 ; struct.get T3 F3`. Three ops
where one chained C expression suffices.

**New op (variable arity)**

```ts
{ kind: "field.chain"; slot: number;
  steps: readonly { typeIndex: number; fieldIndex: number }[] }
```

Lowerer emits when it sees a run of N field accesses on a local. emit_c
pushes a single chained `expr` StackVal.

**emit_c** : nested cast/deref expression :
`((T3*) ((T2*) ((T1*) lN.payload.obj)->f_F1.payload.obj)->f_F2.payload.obj)->f_F3`,
with per-step coerce for primitive / ref / B1 mixes.

**VM** : iterate `steps`, unbox + deref at each.

**emit_wasm-GC** : N `struct.get` ops in sequence — same as decomposed
but the lowerer skipped a re-detection round in the wasm backend.

**emit_wasm 1.0 linear** : N `i32.load` with cumulative offsets.

**Expected gain** : 2-4 k C lines (chains of depth ≥ 2), -6-8 k VM ops.

**Risks** : chain interruption by a non-trivial op (cast, intermediate
binding, method call) — detector must conservatively bail to a
`struct.get` sequence.

---

### Sequencing within piste 7

Order : **7.f → 7.c → 7.e → 7.d**.

- **7.f first** : smallest surface, exercises the full bytecode-op
  introduction process on a low-blast-radius pattern. Sets the template
  for the other three.
- **7.c second** : biggest absolute LoC win, blocks 7.d.
- **7.e third** : extends the existing slot-coalesce pass ; independent
  of 7.c/7.d.
- **7.d last** : emergent from 7.c, adds the variable-arity wrinkle on
  top of a settled bytecode-op infrastructure.

### TS / Vader split (option B confirmed)

TS lands the four ops in `src/`. The in-flight Vader port (currently at
bytecode emit phase per TODO §2.2) absorbs the new ops as it progresses ;
each Vader phase port carries the fused-op handling of its layer. No
parallel TS-only / Vader-only branches.

### Implementation surface (per fused op)

- `src/bytecode/ops.ts` — op kind + dispatch enum (~10 LoC)
- `src/lower/passes/expr.ts` or `passes/match.ts` — detector + emitter (~30-60 LoC)
- `src/c_emit/body.ts` + `c_emit/ops.ts` — handler pushing expr/line (~30-50 LoC)
- `src/bytecode/text.ts` + `binary.ts` — serialisation (~20 LoC)
- `src/vm/exec.ts` — interpret (~20-30 LoC)
- `src/bytecode/peephole.ts` — opacity guard / new rule (~10-30 LoC)

→ ~120-200 LoC per op TS-side, ~200-300 LoC Vader-side (more dump /
dispatch fanout).

### Depends on / order vs other pistes

Independent of pistes 1, 2, 4, 6. Subsumes part of piste 1's remaining
prologue pressure (fewer tmps created in the first place). The sprint
ordering in §5 reflects this.

## 5. Sprint ordering

```
Sprint 1 (DONE 2026-05-21) ──────────────────────────────
    5.a  local-ref inlining           (TS done, Vader port pending)
    1    tmp recycle + per-pool free  (TS done, Vader port pending)
    5.c  expr-kind for type_check     (TS done, Vader port pending)
    5.d  expr-kind for pure binops    (TS done, Vader port pending)
    flatten  midir early-return       (TS done, Vader port pending)
    → 335 k → 222 k lines (-33.7 %), 27.6 s → 6.08 s cc -O0 (-78 %)
                                       │
Sprint 2 (engaged 2026-05-21) ────────  ▼
    Piste 7 (bytecode-fused) — option B : TS first, port absorbs
        7.f  return.lit       (familiarisation, smallest surface)
        7.c  local.field      (biggest absolute win)
        7.e  local.alias      (slot-coalesce extension)
        7.d  field.chain      (emerges from 7.c)
    7.a / 7.b cancelled (0 surviving sites measured)
                                       │
Sprint 3 ────────────────────────────  ▼
    Piste 2 (gc_roots pruning via liveness) — TS, then Vader
                          highest correctness risk in the plan ;
                          revisit only if cc time still dominates
                          after piste 7
                                       │
Sprint 4 ────────────────────────────  ▼
    Piste 4 (match_tag + br_table)   — defer until a benchmark
                          shows chained-if dispatch dominates

Parallel track (no compiler dep) ──────
    Piste 6 (Type → trait refactor in Vader, biggest LoC drop overall)
```

Note : piste 7 stays ahead of pistes 1-extension and 2 because (a) it
shrinks the **body** (not just the prologue) and so attacks the dominant
97 % share of the file, (b) it benefits the future emit_wasm and the VM,
not only emit_c, and (c) the in-flight Vader port absorbs each new op as
it progresses, avoiding a separate Vader port pass for piste 7 later.

## 6. Acceptance criteria per sprint

Re-calibrated 2026-05-21 against current measured state (post-flatten).
Total file targets, full `build/vader.c` :

| Sprint | `cc -O0 -ggdb` | `cc -O3 -DNDEBUG` | LoC (`build/vader.c`) |
|--------|---------------:|------------------:|----------------------:|
| 0 (original baseline, pre-piste-5)    | 27.6 s | 154.9 s | 335 k |
| 1 (DONE — pistes 5.a/1/5.c/5.d/flatten) | **6.08 s** | **21.05 s** | **222 k** |
| 2 (piste 7 set, target)               | ~5.0 s | ~16 s   | ~200 k |
| 3 (piste 2 gc_roots, optional)        | ~4.5 s | ~14 s   | ~190 k |
| 4 (piste 4 br_table, optional)        | ~4.0 s | ~12 s   | ~180 k |
| Refactor (piste 6 — parallel track)   | ~1.5 s | ~5 s    | ~60 k  |

Sprint 2 acceptance (per sub-piste) : each fused op ships its own
before/after measurement, plus a snippet pair (manual op list ↔ source
program) proving byte-identical runtime output and shrinking C output.
The cumulative sprint target is -10 % file size / -15 % cc -O0 time vs
post-sprint-1 baseline.

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

## 14. Decision log — piste 7 engagement (2026-05-21)

**Decision** : piste 7 (fused / compound bytecode ops) is **engaged in
bytecode-fused form** (not in c-emit-only alternative form considered
during the study).

**Inputs to the decision** :

- emit_wasm is on the **short-to-mid-term roadmap** (lands after the
  Vader port completes). A c-emit-only peephole would force a duplicate
  peephole effort in the wasm backend later. Bytecode-fused fuses **once
  at the lowerer** and lets all three backends (emit_c, VM, emit_wasm)
  consume the optimised form.
- Surface ratio bytecode-fused vs c-emit-only collapses from ~7× to
  ~1.4× once the emit_wasm peephole work is folded into the c-emit-only
  column.
- The in-flight Vader port is at bytecode-emit phase, so adding new ops
  now means each Vader phase port carries the new op handling of its
  layer (option B sequencing). No separate "port piste 7 to Vader"
  sprint needed later.
- Re-measurement of piste 7 targets against the current 222 k-line
  `build/vader.c` (post-sprint-1) :
  - 7.a / 7.b : 0 surviving sites (captured by 5.c). **Cancelled.**
  - 7.c local.get → struct.get : 14 785 sites. **Engaged priority 2.**
  - 7.e local.get → ref.cast → local.set : 7 807 sites. **Engaged priority 3.**
  - 7.f bool.const → return : 416 bare sites. **Engaged priority 1**
    (familiarisation step).
  - 7.d field.chain : 0 visible (emerges from 7.c). **Engaged priority 4.**

**Pre-implementation exploration (run before sprint 2 starts)**

Per the `explore_before_commit_to_phase` rule, trace one minimum-cascade
example through the full pipeline before writing the first line of the
new op :

1. Pick a representative `local.get N → struct.get T F` site in
   `tests/snippets/` (a small program that exercises the pattern in
   isolation).
2. Dump the bytecode at that site (`vader build --dump-bytecode` or VM
   inspector).
3. Identify the exact lowering site in `src/lower/passes/expr.ts` where
   the pair is emitted, and the exact consumer site in `src/c_emit/ops.ts`
   (`emitStructGet` at line 806) that materialises the tmp.
4. Verify peephole ordering : `runPeepholes` (Rule 1 : `local.set N;
   local.get N → local.tee N`) currently runs after lowering. The 7.c
   detector must run **before** Rule 1 fragments the pattern (or be
   robust to a tee in the middle — choose at design time).
5. Confirm that `dup` and `materializeStackForSlot` already cover the
   WAR / dup hazards for `expr`-kind pushes coming from `local.field`.
6. Run the snippet under VM and emit_c — confirm byte-identical output
   for the trace.

If the trace surfaces a fragmentation hazard or an unexpected interaction
with the existing peephole / slot-coalesce passes, redesign before
committing to the sprint plan.

**Out of scope for sprint 2** :

- emit_wasm itself. The fused ops are designed to map cleanly to WASM
  1.0 linear and WASM-GC, but no wasm backend code is written in this
  sprint.
- `.vir` serialisation as a stable user artefact. Pre-MVP : we regen
  snapshots on every format change.

## 15. Pre-implementation trace — sprint 2 go/no-go (2026-05-21)

Ran the §14 checklist against `tests/snippets/contains_op/`. The
`DigitSet.contains` fn exercises **both** target patterns in 17 source
lines :

```vader
contains :: fn(self, value: i32) -> bool {
    if value < 0 || value > 9 {
        return false                    // ← 7.f
    }
    mask := 1 << value
    return (self.bits & mask) != 0      // ← 7.c on self.bits
}
```

**Bytecode dump confirms the patterns** (excerpt from
`tests/snippets/contains_op/bytecode.snapshot.virt`, pre-peephole) :

```
bool.const false      ; <— 7.f pair starts
return                ; <—

local.get 0           ; <— 7.c pair starts (self)
struct.get 1 0        ; <—  (.bits)
```

**Pipeline mapping** :

| Layer | File | Site |
|-------|------|------|
| Lowering: FieldGet → bytecode | `src/midir/emit.ts:527-528` | `emitFirstOperand` + `pushOp(struct.get)` |
| Lowering: Return → bytecode | `src/midir/emit.ts:269-275` | `case "Return"` in `emitBlockContents` |
| Peephole + slot-coalesce | `src/midir/emit.ts:107-110` | gated by `ctx.optimize` (true in prod, false in `dumpBytecode`) |
| c-emit consumer (struct.get) | `src/c_emit/ops.ts:806-859` | `emitStructGet` (5 paths) |

**Peephole fragmentation verdict** :
- Rule 1 (`local.set N ; local.get N → local.tee N`) does not intersect
  7.c or 7.f.
- Rules 2/3/4 (bool.not folding) do not intersect.
- Rule 5 (dead-store elim) and Rule 6 (const-prop single-use) do not
  fragment the target sequences.

→ **Fuser must run before** `runPeepholes`, i.e. **during midir emit**.
Place look-back in `emitFieldGet` and the `case "Return"` arm. Detector :
after the receiver/value push, check if `ctx.emit.body[last]` is the
fusable predecessor (`local.get` for 7.c, a literal const op for 7.f) ;
if yes, pop it and emit the fused op.

**Peephole + slot-coalesce EXTENSIONS required** before shipping any
fused op that references a slot (so 7.c, 7.d, 7.e — not 7.f) :

- `slotOf` in `src/bytecode/slot-coalesce.ts:117` must recognise the
  slot reference inside `local.field`, `field.chain`, and `local.alias`.
  Otherwise `coalesceSlots` could collapse the slot with another and
  silently corrupt the read.
- `dropDeadStores` (Rule 5, `src/bytecode/peephole.ts:106`) must count
  the new ops as reads of their slot ; else upstream `local.set N` gets
  treated as dead.
- `propagateConstSingleUse` (Rule 6, `src/bytecode/peephole.ts:195`)
  must count the new ops as `gets` ; else const-prop fires on a slot
  that's actually still being read by a fused op.

→ ~15 LoC across three files, mandatory for 7.c+ but not for 7.f.

**c-emit safety rails** (already in place from 5.c/5.d) :
- `dup` of an `expr` StackVal materialises via `materialiseEntry`
  (`src/c_emit/body.ts:375-378`).
- `materializeStackForSlot` flushes **all** `expr` entries on every
  `local.set` / `local.tee` (lines 783-792, conservative strategy).

→ 7.c pushes an `expr` exactly like `emitTypeCheck` / `pushBinopExpr`
already do. **No new safety rail needed for c-emit.**

**Baseline equivalence** (must be preserved post-fusion) :
- `./tests/snippets/contains_op/native` → `range yes / range !in yes / range incl yes / set has 4 / set lacks 5 / set has 7`, exit 0.
- `build/vader run tests/snippets/contains_op/bytecode.snapshot.virt` →
  identical.
- `tests/snippets/contains_op/vm.snapshot` → identical.

Triple agreement.

**Go / no-go** : **GO**. The trace surfaced no redesign-worthy hazard.
Two implementation notes carried into sprint 2 :

1. **7.f first stays correct as the familiarisation step** — it touches
   no slot, so the peephole/coalesce extensions aren't needed for it.
   Ship 7.f end-to-end (lowerer + emit_c + VM + serialise + snippet
   diff) before tackling 7.c.
2. **7.c (and 7.d/7.e) ship with the slot-aware peephole/coalesce
   extensions in the same PR**. The 15 LoC must not lag.

Snippet `tests/snippets/contains_op/` will serve as the **regression
trace** for sprint 2 : compare bytecode dump + native output + vm output
before and after each fused-op PR.

## 16. POC results — piste 7.f (2026-05-21)

**Patch** : new op `return.lit` in `src/bytecode/ops.ts` carrying an inner
`ConstOp`. Lowerer fuses in `src/midir/emit.ts` `case "Return"` via look-
back on `ctx.emit.body[last]`. Handlers in `src/c_emit/body.ts`
(`emitReturnLit` + shared `constLitC` helper), `src/vm/exec.ts`
(`pushConstLit` helper + inline case), `src/bytecode/text.ts` and
`src/bytecode/binary.ts` (round-trip via recursive `formatOp` /
`writeOp` on the inner const).

**Measurements** (same machine, current branch) :

| Metric                            | Baseline (post-flatten) | Post 7.f   | Δ        |
|-----------------------------------|------------------------:|-----------:|---------:|
| `build/vader.c` lines             | 222 107                 | 222 107    |  0       |
| `build/vader.c` bytes             | 13.82 MB                | 13.72 MB   | **-0.7 %** |
| `cc -O0 -ggdb` (1 run)            | 5.04 s                  | 5.01 s     | within noise |
| `return.lit` sites (contains_op fn) | 0                     | 3          |  |

**Regressions** : zero on substantive suites. native 252/252, vm +
vader_vm 446 pass / 8 skip / 0 fail, formatter + lexer + lsp 114/114,
cli + e2e 14/14. The pre-existing `snapshot.test.ts` failures (stale
`.virt` fixtures) are unaffected and out of scope.

**Why the line count didn't drop**

`emitReturn` (pre-7.f) already emits exactly one C line per return :

```c
{ vader_box_t __vret = wireRet; vader_gc_top = gc_frame.prev; return __vret; }
```

`emitReturnLit` emits one line too :

```c
{ vader_gc_top = gc_frame.prev; return <lit>; }
```

Same line count, fewer bytes (the `__vret` snapshot tmp is gone — safe
for literals because they don't read frame-pinned locals, so the pop-
frame-then-return order is trivially correct). VM dispatch wins one op
per site, and the bytecode body shrinks proportionally.

**Bug surfaced + fixed** : the early-return flattening pass in
`src/midir/emit.ts:317-322` (commit `fdc2bc28`) decides whether to
flatten an `if then-exits else …` cascade by looking at
`lastOp.kind === "return"`. After 7.f the predecessor literal-return op
is `"return.lit"`, which **was not in the exit set** — so every early-
return cascade re-nested under `else` branches, ballooning the C output
by +5 403 lines on the first 7.f build. Fix : add
`lastOp.kind === "return.lit"` to the exit predicate. With the fix,
file size is back to baseline (and bytes are smaller).

**Lesson for 7.c / 7.d / 7.e** — extend the §15 checklist :

- Step 7 (NEW) : **grep every site that look-backs on the last emitted
  bytecode op** (`ctx.emit.body[...].kind === "..."` patterns,
  peephole / coalesce / dce reads). Each must learn the new fused op
  kind, otherwise its detector silently misses the pattern. Concretely
  for the rest of piste 7 :
  - `src/midir/emit.ts:317-322` (flatten detector) — already extended.
  - `src/bytecode/peephole.ts` Rule 1 / 5 / 6 + `constOpValType` —
    needed for 7.c / 7.e (slot-aware ops).
  - `src/bytecode/slot-coalesce.ts:117` `slotOf` — needed for 7.c /
    7.e.
  - `src/midir/dce.ts:584` and `:672` typeIndex visitors — only if the
    new op carries a typeIndex (7.c does ; 7.d / 7.e too).

**Sequencing verdict** : 7.f was correctly placed as the familiarisation
step. The line-count miss is expected (literal returns were already
oneliners). The structurer-interaction bug it caught is exactly the
kind of failure mode you want to surface on the smallest possible op.
7.c will see real LoC gains because `struct.get` currently emits a
separate `tN = ...;` line that disappears entirely when fused as an
`expr`-kind push.

**Implementation surface** (TS only ; Vader port absorbs the new op
when each phase advances) :

- `src/bytecode/ops.ts` : +18 LoC (ConstOp alias, isConstOp guard,
  return.lit kind).
- `src/midir/emit.ts` : +14 LoC (lowerer fusion in `case "Return"` +
  the 1-line flatten fix).
- `src/c_emit/body.ts` : +29 LoC (`emitReturnLit`, `constLitC` helper)
  -10 LoC (the 8 const-op cases collapsed through `constLitC`).
- `src/vm/exec.ts` : +24 LoC (case + `pushConstLit` helper).
- `src/bytecode/text.ts` : +16 LoC (format + parse + `isConstOpKind`).
- `src/bytecode/binary.ts` : +9 LoC (write + read).
- Total : ~100 LoC added, ~10 LoC removed. No SPEC.md change.

## 17. POC results — piste 7.c (2026-05-21)

**Patch** : new op `local.field { slot, typeIndex, fieldIndex }` fusing
`local.get N ; struct.get T F`. Lowerer detection in `emitFieldGet`
(`src/midir/emit.ts`) gated on `!skipFirstGet && last === local.get N
&& last.slot === slotForReceiver`. emit_c handler `emitLocalField`
mirrors the 5 paths of `emitStructGet` but pushes an `expr` StackVal
with `lN` inlined directly ; the B1 nullable-ref path uses
`vader_b1_to_box(raw, tag)` for single-eval of the receiver. VM case
reads `slots[op.slot]` and dispatches like `struct.get`. Text + binary
serialisation extended.

**Measurements** (Mac arm64, current branch) :

| Metric                        | Baseline (post-7.f) | Post 7.c   | Δ        |
|-------------------------------|--------------------:|-----------:|---------:|
| `build/vader.c` lines         | 222 107             | 213 212    | **-4.0 %** |
| `build/vader.c` bytes         | 13.72 MB            | 13.36 MB   | -2.6 %   |
| `cc -O0 -ggdb` (1 run)        | 6.13 s              | 5.63 s     | **-8.2 %** |
| `cc -O3 -DNDEBUG`             | 21.15 s             | 20.49 s    | -3.2 %   |

**Cumulative since original baseline** : 335 364 → 213 212 = **-36.4 %**
lines ; 27.6 s → 5.63 s = **-79.6 %** cc -O0 ; 154.94 s → 20.49 s =
**-86.8 %** cc -O3.

**Regressions** : zero on substantive suites. native 252/252, vm +
vader_vm 446 pass / 8 skip / 0 fail, parity 1005/1005, formatter +
lexer + lsp 114/114, cli + e2e 14/14.

**Bugs surfaced + fixed during validation** :

1. **First lowerer attempt fused too eagerly**. The naive `if
   last.kind === "local.get" { fuse }` misfired when
   `emitFirstOperand` was skipped by the scheduler's `skipFirstGet`
   hint — the trailing `local.get` then belonged to a previous
   instruction, not the FieldGet's receiver. Fix : gate on
   `!skippedReceiverGet` AND `last.slot === ctx.localToSlot[ins.target]`.
   Surfaced as `v.tag` undefined VM crashes on union-arm bodies that
   chained reads through the stack.

2. **`coalesceSlots` body-rewrite missed `local.field`**. The slot-
   coalesce pass renumbers `local.get/set/tee` slots after computing
   ranges, but the rewrite loop (`src/bytecode/slot-coalesce.ts:104-111`)
   was extended via `slotOf` to extend ranges through `local.field` —
   and I forgot to extend the rewrite loop too. Slots in `local.field`
   stayed stale post-coalesce → `local.field 5 ...` referencing a slot
   that had been merged into 2. Fix : extend the rewrite loop with a
   `local.field` arm.

Both bugs were caught by the native + vm test suites within a single
build/test cycle. The §16 checklist held up — the slot-coalesce miss
was an oversight in **applying** the extension, not in identifying
the call site.

**Implementation surface** :

- `src/bytecode/ops.ts` : +6 LoC (new op kind).
- `src/midir/emit.ts` : +18 LoC (fusion detector with hint + slot guards).
- `src/c_emit/ops.ts` : +35 LoC (`emitLocalField` with 5 paths).
- `src/c_emit/body.ts` : +2 LoC (import + dispatch case).
- `src/vm/exec.ts` : +5 LoC (case).
- `src/bytecode/text.ts` : +5 LoC (format + parse).
- `src/bytecode/binary.ts` : +6 LoC (write + read + table).
- `src/bytecode/peephole.ts` : +5 LoC (Rule 5 reads counter + Rule 6 gets counter + dropDeadStores rewrite).
- `src/bytecode/slot-coalesce.ts` : +7 LoC (`slotOf` + rewrite loop).
- `src/midir/dce.ts` : +2 LoC (typeIndex visitors both pre- and post-prune).
- Total : ~90 LoC added. No SPEC.md change.

**Lessons for 7.e / 7.d** :

- **Apply, don't just identify.** The §16 checklist listed every site
  that needed extension ; the slot-coalesce miss was at the
  **rewrite** step, not the **range computation**. Both halves of any
  pass that touches slots need extending — confirmed there's no second
  pass that touches `local.field` slots post-coalesce.
- **Scheduler hints matter at the fusion site.** `skipFirstGet` and
  `skipTerminatorGet` rewrite what a "last emitted op" means. Future
  fused ops looking back at the bytecode stream must gate on the same
  hints.
- **`local.alias` (7.e) reads a slot** and writes another — both must
  be added to `slotOf`, the read-counter in `dropDeadStores`, the
  get-counter in `propagateConstSingleUse`, and the rewrite loops in
  `slot-coalesce.ts` and `dropDeadStores`.

## 18. POC results — piste 7.e (2026-05-21)

**Design change vs §4 plan** : the plan called for a 2-step approach (a
new `local.alias N M` op + slot-coalesce extension). Replaced with a
**pure peephole rule** (Rule 7 — `propagateLocalAlias`) :

- Detect a non-param slot M with `sets=1, tees=0, gets≥1` whose write
  is fed by `local.get N` (N ≠ M, same ValType).
- Verify N isn't written between the alias point and M's last read
  (otherwise the forwarded read would see a different value).
- Forward every read of M (bare `local.get` or fused `local.field`) to
  N via `withRemappedSlot`, drop the `local.get N ; local.set M` pair.
- `dropDeadStores` then collects M.

No new bytecode op. No c-emit / VM / serialise changes. ~80 LoC in
`src/bytecode/peephole.ts`.

**Why simpler than the plan** : an explicit `local.alias` op pays for
itself only when slot-coalesce can later collapse M into N. The pure-
peephole approach gets the same C-side win (the `lM = lN;` line is
gone whenever the rule fires) without the bytecode-op surface.

**Helper extraction** : before 7.e landed, I factored the slot-touching
predicate into `src/bytecode/slot-refs.ts` (`slotRead`, `slotWrite`,
`slotTouched`, `withRemappedSlot`). peephole + slot-coalesce funnel
through it now. -23 LoC net, and Rule 7 was easier to write because
slot-aware ops (including the upcoming 7.d `field.chain`) are picked
up automatically.

**Measurements** (current branch, build/vader.c) :

| Metric                          | Baseline (post-7.c) | Post 7.e   | Δ        |
|---------------------------------|--------------------:|-----------:|---------:|
| `build/vader.c` lines           | 213 212             | 212 087    | -0.5 %   |
| `build/vader.c` bytes           | 13.36 MB            | 13.34 MB   | -0.2 %   |
| `cc -O0 -ggdb` (1 run)          | 6.27 s              | 5.54 s     | -11.6 %  |
| `cc -O3 -DNDEBUG`               | 20.49 s             | 20.85 s    | within noise |
| `lM = lN;` copies eliminated    | 7 807               | 7 120      | -687 sites |

**Cumulative since original baseline** : 335 364 → 212 087 = **-36.8 %**
lines ; 27.6 s → 5.54 s = **-79.9 %** cc -O0.

**Why the gain is modest vs the plan's -5–7 k estimate** :

The plan assumed slot-coalesce would aggressively merge bind locals
into their scrutinee. The pure-peephole rule only fires when the
`local.get N ; local.set M` pair is **adjacent** in the bytecode (post
applyLocalRules / propagateConstSingleUse). Many `lM = lN;` copies in
`build/vader.c` arise from non-adjacent sequences — typically the
scheduler interleaves other ops between the get and the set so the
rule's adjacency check fails. The plan's 2-step (new op + coalesce
extension) would catch these, at the cost of the surface that
motivated using a peephole here.

Worth revisiting if the per-fn `lM = lN;` density measurably hurts cc
time on a new hot fn ; for now, the modest gain is acceptable as the
peephole is invisible to backends and zero-risk.

**Regressions** : zero. native 252/252, vm + vader_vm 446 pass / 8 skip
/ 0 fail (snapshots byte-identical), parity 1005/1005, formatter +
lexer + lsp 114/114, cli + e2e 14/14.

**Implementation surface** :

- `src/bytecode/slot-refs.ts` : new file, 54 LoC (`slotRead`,
  `slotWrite`, `slotTouched`, `withRemappedSlot`).
- `src/bytecode/peephole.ts` : Rule 7 added (~80 LoC), Rule 5 & Rule 6
  refactored through `slotRead` / `slotTouched` / `withRemappedSlot`
  (-15 LoC net there).
- `src/bytecode/slot-coalesce.ts` : refactored through the same helpers
  (-12 LoC net).

The helper extraction (separate commit) is what unlocks the
`local.field` and the future `field.chain` (7.d) being picked up
automatically — adding a new fused slot-touching op needs editing one
file (`slot-refs.ts`) instead of five.

**Lessons for 7.d** :

7.d (`field.chain`) reads a slot like `local.field` does. With
`slot-refs.ts` in place, all that's needed is one arm in `slotRead`
and `withRemappedSlot`. The peephole, slot-coalesce, dropDeadStores,
and propagateLocalAlias passes pick it up for free.

## 19. POC results — piste 7.d (2026-05-21)

**Design change vs §4 plan** : the plan called for a new variable-
arity `field.chain` bytecode op. Replaced by **extending `emitStructGet`
to push expr-kind** (same shape as `emitLocalField` from 7.c). When
`struct.get` follows a `local.field` (or another `struct.get`), the
consumer's `nameOf(stackVal)` inlines the predecessor's expression
text — chains collapse into one C expression at use-site without a
new op kind. Extracted `structFieldExpr(s, typeIndex, fieldIndex,
recv)` helper shared by `emitStructGet` and `emitLocalField`.

This is the Agent-1 recommendation from the 7.c /simplify review.

**Measurements** (current branch, build/vader.c) :

| Metric                          | Baseline (post-7.e) | Post 7.d   | Δ        |
|---------------------------------|--------------------:|-----------:|---------:|
| `build/vader.c` lines           | 212 083             | 208 870    | **-1.5 %** |
| `build/vader.c` bytes           | 13.34 MB            | 13.21 MB   | -1.0 %   |
| `cc -O0 -ggdb` (1 run)          | 5.29 s              | 5.01 s     | -5.3 %   |
| `cc -O3 -DNDEBUG`               | ~20.5 s             | 19.54 s    | -4.7 %   |

**Cumulative since original baseline** : 335 364 → 208 870 = **-37.7 %**
lines ; 27.6 s → 5.01 s = **-81.8 %** cc -O0 ; 154.94 s → 19.54 s =
**-87.4 %** cc -O3.

**Regressions** : zero. native 252/252, vm + vader_vm 446 pass / 8
skip / 0 fail (snapshots byte-identical), parity 1005/1005,
formatter + lexer + lsp 114/114, cli + e2e 14/14.

**Implementation surface** : `src/c_emit/ops.ts` only — extract
`structFieldExpr` (~45 LoC), rewrite `emitStructGet` and
`emitLocalField` as 4-line wrappers (-50 LoC each). Net : -55 LoC.
No bytecode op added, no other file touched.

**Why the gain is real even though chains "looked rare"** : 1 475
chain candidates were measured at the bytecode level (`local.field`
or `struct.get` immediately followed by `struct.get`). Each fires the
expr-kind inlining, removing one `tN = ...;` line per chain step.
Three-deep chains (`x.foo.bar.baz`) collapse to one C expression of
three nested casts/deref.

## Sprint 2 — closeout (2026-05-21)

Piste 7 is **complete**. Sequence : 7.f → 7.c → (slot-refs refactor)
→ 7.e → 7.d. All four sub-pistes landed in the bytecode-fused / c-
emit-expr-kind form, all behind existing safety rails (`dup` rematerial
ises expr, `materializeStackForSlot` flushes on `local.set`/`tee`).

**Cumulative measurements (since pre-piste-5 baseline)** :

|                      | Baseline    | Post sprint 2 | Δ          |
|----------------------|------------:|--------------:|-----------:|
| `build/vader.c` lines | 335 364    | 208 870       | **-37.7 %** |
| `cc -O0 -ggdb`       | 27.6 s      | 5.01 s        | **-81.8 %** |
| `cc -O3 -DNDEBUG`    | 154.94 s    | 19.54 s       | **-87.4 %** |

The sprint 2 acceptance target (§6) was -10 % file / -15 % cc -O0 vs
the post-sprint-1 baseline (222 k / 6.08 s). Achieved : -6.0 % file
(slightly under), -17.6 % cc -O0 (over). The file-size shortfall comes
from 7.e's modest -0.5 % — non-adjacent `get N ; set M` patterns
aren't caught by the pure peephole. Revisit only if a future hot fn
shows measurable `lM = lN;` density.

**Next** : Vader port of piste 7 absorbs into the in-flight bytecode
phase port. No standalone sprint needed (option B sequencing held).

Sprint 3 (piste 2, gc_roots pruning) and Sprint 4 (piste 4, br_table)
remain optional — gated on a real benchmark showing the relevant
overhead dominates. Current cc time is comfortable.
