# Phase 2 — Automatic erasure pass

> **Status**: **PATH γ COMPLETE — 2026-05-20.** Erasure infrastructure
> ships full ; native suite **252/252** AND VM suite **251/251** (4 skip)
> with `erasureDedupe` enabled by default. Baseline parity preserved.
> All cascade patterns identified during the original Phase 2 paused
> exploration and during the path-γ session are documented in §9 Issue
> 10 with their fix paths for the future Vader self-host port.
>
> **Sub-deliverables shipped (path γ progressive) :**
> - **Famille A** — `synthesiseIntrinsicWrappers` (`bytecode/emit.ts`)
>   creates BcFunction wrappers for `@intrinsic` impl members so
>   vtable dispatch on `Hash.hash` / `Equals.equals` / `Add.add` /
>   ... lands on a real `fnIndex` ; `vtableSignatures`
>   (`c_emit/ops.ts`) detects heterogeneous-`resultType` traits and
>   forces uniform `any` return ; the dispatcher per-arm boxes when
>   the impl's return diverges from the uniform.
> - **Famille B** — `synthesiseErasedSpecializedInstances`
>   (`comptime/evaluate.ts`) pre-registers `Self(Any, ...)` for every
>   `@specialize`d generic ; `erasureDedupe` (`comptime/erasure-dedupe.ts`)
>   splits struct vs fn handling : fn entries collapse to one
>   representative + per-shape vtable rows via `redirectInner`
>   preserving `typeArgs` ; struct entries keep per-instance identity
>   with uniform Any-rewritten layout ; an extra `Repeat(Any)`-flavoured
>   struct entry per group lets the shared fn body intern the
>   matching BcType ; runtime `vader_array_buf_t.element_tag` carries
>   the BcType index of primitive-storage arrays so
>   `vader_array_load_slot` returns properly-tagged boxes.
> - **Boundary conversion (β)** — `virtual.call` / `call` ops carry
>   `resultTypeIndex` / `expectedResultType` ; `BcStruct.symbolId` +
>   `computeAnyCounterpartOf` (`c_emit/emit.ts`) maps concrete struct
>   → its all-`Any` counterpart (also covers anonymous tuples by
>   arity-grouping) ; `emitErasureBoundaryConversion` (`c_emit/ops.ts`)
>   inserts an unbox+repack at the boundary in three forms :
>   single-primitive-field inline, single-ref-field inline, heap
>   field-by-field reshape. Triggered whenever the dispatcher's
>   `resultType` differs from the call site's `expectedResultType`.
>
> **Dormant / earlier deliverables :**
> - **Phase 0** vtable runtime + slot registry + `Any` Type kind
> - **Phase 1** packed inline-box (multi-field POD ≤ 16B)
> - **β fix** raw-array for-in skips `ArrayIterator(T)` wrap
> - **η fix** comptime `observeFnCall` registers Any-bearing instances
>
> **Default state** : `evaluate.ts` calls
> `erasureDedupe(monoRaw, project)` ; gate left in place for ease of
> A/B comparison during the Vader port.
>
> **Goal**: rewrite every generic instantiation through a single erased
> form. Every type-parameter position becomes `Any` in the IR; method
> calls on erased parameters route through the vtable dispatch built in
> Phase 0; small POD values box into packed payloads built in Phase 1.
> User-facing API stays unchanged — generics in source, erasure invisible.
>
> **Cross-refs**:
> - `docs/STDLIB_GENERIC_COLLAPSE.md` §1, §2.2, §6 (Phase 2), §8.5 (comptime
>   entanglement)
> - `docs/STDLIB_GENERIC_COLLAPSE_PHASE0.md` (vtable runtime + slot
>   registry, prerequisite)
> - `docs/STDLIB_GENERIC_COLLAPSE_PHASE1.md` (packed-payload inline-box,
>   prerequisite for criterion #1 on multi-field POD)

---

## 0. Why this phase exists

Phase 0 + Phase 1 built the **infrastructure**. Phase 2 is the **producer
of erased IR** — without it, the vtable tables emit but never get
dispatched through, and the packed payloads emit but never get used by
generic value slots. Phase 2 is what turns the work of the prior phases
into the measurable benefits (POC §5.1-5.2 LoC and `cc -O3` gains) on
real Vader code.

---

## 1. Design overview

Two integration paths, decided 2026-05-19 per parent doc §8.5:

- **(a) Replace `monomorphizeProject` entirely.** Walk every generic
  decl once and emit a single erased form per decl, with a side-table
  of original types per call site. Cleanest, but ~180 LoC rewrite in a
  load-bearing area + every dependent registry (lower call graph, DCE,
  hash-cons) gets new keying.
- (b) Let comptime monomorphise as today, then run a post-pass that
  re-deduplicates. Mechanical but wasteful, and re-creates the
  original-type side-table from the already-substituted AST.

**Selected: (a)**. The decision was confirmed in `STDLIB_GENERIC_COLLAPSE.md`
Decision log when Phase 0 started. The rewrite reaches every consumer
exactly once instead of re-running mono twice.

### 1.1 Where the erasure happens

`src/comptime/specialize.ts` (376 LoC, measured 2026-05-19) currently
produces `MonoProject` — one `MonoEntry` per `(generic decl, typeArgs)`
pair. Phase 2 rewrites it to produce one `MonoEntry` per generic decl
(ignoring typeArgs), with the `typeArgs` consumed by Phase 2 to record
boundary type info into a side-table.

The lower (14 files in `src/lower/`) consumes `MonoEntry` and produces
`LoweredDecl`. With one entry per decl, the lower walks N times less.

### 1.2 What gets erased vs kept

Default: erase everything. Carve-outs:

- **Iterators** (`ArrayIterator(T)`, `Yield(T)`, lazy combinators in
  `std/iter.vader`) — the for-in fusion pass (`src/lower/passes/for-in.ts`)
  relies on inlining their bodies. Keeping them specialised preserves
  the 22.6 ms → 9.7 ms gain on `bench/map_iter`. See §2 for the
  decision mechanism.
- **`@intrinsic` impls** — already special-cased ; their bodies map
  to dedicated bytecode ops or runtime helpers, not regular fns. No
  change.
- **Comptime callers** — generic fns called from `@comptime` blocks
  may need specialised versions for the interpreter to walk concrete
  types. See §3 P2-7.

---

## 2. Iterator-skip mechanism — REQUIRES DECISION

Deferred from Phase 0. Two options on the table:

### Option (i) — `@specialize` decorator

Author marks the decl explicitly:

```vader
@specialize
ArrayIterator :: struct[T] { ... }

@specialize
Yield :: struct[T] { ... }
```

- **Pros**: explicit, discoverable (a `grep @specialize` lists every
  excluded type), no magic, easy to debug ("why isn't this erased?
  — it's tagged").
- **Cons**: stdlib author must remember to tag ; forgetting silently
  causes a perf regression on for-in fusion.
- **Scope**: 2-3 types in stdlib today (`ArrayIterator`, `Yield`, lazy
  combinators). Manageable.
- **Effort**: ~0.5 d (decorator + skip rule in the erasure pass).

### Option (ii) — Structural heuristic

The erasure pass detects iterator-like types and skips them
automatically. Candidates:

- **(ii-a)** "Has a method named `next()` returning `Yield(T) | null`."
- **(ii-b)** "Is referenced from `for-in.ts` synthesised code."
- **(ii-c)** "Has only one type param and the param appears in the
  return type of a method named `next` or in an `Iterator` impl."

- **Pros**: no decorator clutter, no stdlib author discipline needed.
- **Cons**: magic. Hard to debug when a refactor in iterator code
  silently changes erase-or-not status. The rule is fragile — adding
  a `next()` method to a non-iterator type would accidentally exclude
  it.
- **Effort**: ~1 d (heuristic + tests).

### Recommendation: option (i) — `@specialize` decorator

Reasons:
1. Pre-MVP, two decorators on two types is not significant surface.
2. Diagnostic clarity outranks decorator hygiene at this stage —
   debugging "why didn't this erase?" via `grep` is faster than
   reverse-engineering a heuristic.
3. The heuristic can be added *later* as an additive optimisation
   (auto-tag types matching iterator shape) without breaking
   `@specialize`-tagged code.
4. The cons of (ii) get worse as iterator combinators grow (more
   shapes to match) ; the cons of (i) stay constant.

**Action needed**: confirm (i) or (ii). Phase 2 cannot start P2-3
without this.

---

## 3. Task breakdown

| # | Task | Files | Effort |
|---|------|-------|-------:|
| P2-1 | Erasure substitution in `specialize.ts` — replace `K`/`V` with `Any` in struct/fn bodies, deduplicate `MonoEntry` instances per decl | `src/comptime/specialize.ts` | 1-1.5 w |
| P2-2 | Boundary side-table — per call site / return site / field load, record the original concrete type so the lower can insert `box`/`checkcast` | `src/typecheck/typed-ast.ts`, `src/comptime/specialize.ts` | 0.5 w |
| P2-3 | `@specialize` decorator + skip rule | `src/parser/decorators.ts`, `src/comptime/specialize.ts`, `stdlib/std/iter.vader`, `stdlib/std/core.vader` (tag iterator types) | 3 d |
| P2-4 | Lower dispatch on `Any` (Phase 0's P0-5 deferred) — when receiver type is `Any`, emit `virtual.call` with the slot from `TraitSlotRegistry` instead of a static call | `src/lower/passes/expr.ts` (extend trait-method case) | 3-4 d |
| P2-5 | Auto-box at generic call sites — args entering an erased slot wrap with `box_to_any` | `src/lower/passes/call.ts` | 3 d |
| P2-6 | Auto-cast at generic returns / field loads — values flowing out into a typed slot insert `checkcast` (distinct IR node on TS side per Decision log) | `src/lower/passes/expr.ts`, `src/lower/passes/block.ts` | 3 d |
| P2-7 | Comptime interaction — verify generic fns called from `@comptime` get the right code path (specialised or erased), fix divergences | `src/comptime/evaluate.ts`, `src/comptime/specialize.ts` | 3-5 d |
| P2-8 | DCE + hash-cons + impl registry rekeying — every map/set keyed on `(decl, typeArgs)` becomes keyed on `decl` alone | grep for `MonoEntry` / `genericFnCalls` / `implMethodEntries` and audit | 2-3 d |
| P2-9 | Snapshot regression audit + bulk update — every snippet whose `mono.snapshot` / `lower.snapshot` / `bytecode.snapshot.virt` / `native.c` changes shape | `tests/snippets/` (large surface), test infrastructure tweaks if needed | 1 w |
| P2-10 | Pivot-test regression check — confirm POC criterion #2 holds on real workload: `get` runtime ≤ 1.15× on `bench/map_iter`, `for_in_into_iter`, `custom_iter_generic` | bench measurement + analysis | 2-3 d |
| P2-11 | Lower.snapshot byte-parity with Vader self-host — re-baseline (the 181/226 number) since erased shapes change | docs + audit | 2 d |

**Total: ~6-9 weeks.** Matches the parent doc §10 estimate (6-8 weeks).

---

## 4. Exit criteria

1. **Functional**: full TS test suite green. Existing snippets produce
   semantically identical output.
2. **Lowered IR shape**: every generic decl has a single
   `MonoEntry`/`LoweredDecl`. The 45× `MutableMap(K, V)` instances
   collapse to 1× `MutableMap__erased`. Verified by emitting the
   self-host build and counting struct decls.
3. **Performance**: pivot-test `get` regression ≤ 15 % (POC criterion #2
   carried forward). Self-host `cc -O3` wall-time ≥ 20 % reduction
   (POC criterion #3 carried forward).
4. **GC stress**: `VADER_GC_STRESS=1` green on the test suite.
5. **Comptime**: every snippet that exercises comptime + generics
   passes.

If (3) fails, decide:
- Add P2-12: implement the optional `checkcast` elision analysis
  (parent doc §4 "Future optimisation").
- Accept the regression as the cost of the trade-off — the cc -O3 gain
  is the primary motivation.
- Roll back Phase 2 (revert the commit, retreat to Phase 0 + Phase 1
  + Core/Shell).

---

## 5. Risks

1. **`specialize.ts` rewrite scope creep.** The file is 376 LoC but
   touches every type substitution path. The rewrite may surface
   latent assumptions (e.g., "two instantiations of the same decl
   produce distinct symbols"). Mitigation: small commits per sub-task,
   keep the existing path runnable in parallel during the transition.
2. **Comptime interaction blocker.** Generic fns called from `@comptime`
   may have walked-tree dependencies on the concrete type that erasure
   removes. Mitigation: P2-7 is allocated 3-5 d ; if it explodes,
   either keep mono on the comptime side and erase on the runtime
   side, or skip-erase any decl reachable from `@comptime`.
3. **Snapshot churn.** Likely hundreds of snippets regenerate. Manual
   audit risks rubber-stamping a real regression. Mitigation: P2-9
   runs after P2-10 so we know the perf signal first ; semantic
   regressions are caught by the functional test pass (criterion #1).
4. **Self-host port re-baseline.** The Vader self-host's 181/226
   parity score is measured against the TS pipeline output. Erasure
   changes that output. The score is going to drop until the Vader
   self-host adopts erasure too (Phase 7). Mitigation: P2-11 documents
   the expected drop ; Phase 7 brings parity back.
5. **`Into` ↔ `checkcast` interaction on TS side.** Per Phase 0
   Decision log, TS-side `Into` doesn't cover return/struct-lit/let
   sites today. `checkcast` lives as a distinct IR node on TS for
   Phase 2 ; unification with `Into` is Phase 7 work during the
   Vader port. No blocker here, just bookkeeping.

---

## 6. Ordering

Strict dependency chain :

```
P2-1 (erasure subst)
  ├── P2-2 (boundary side-table)
  ├── P2-3 (@specialize) — needs decision before starting
  ├── P2-8 (registry rekeying)
  │     └── P2-4 (lower Any dispatch)
  │           └── P2-5 (auto-box)
  │                 └── P2-6 (auto-cast)
  │                       └── P2-7 (comptime validation)
  │                             └── P2-9 (snapshot audit)
  │                                   └── P2-10 (pivot-test perf)
  │                                         └── P2-11 (self-host parity rebaseline)
```

P2-1, P2-2, P2-3, P2-8 can pipeline in parallel during the first week.
P2-4 through P2-7 are serial. P2-9 onwards is serial.

---

## 7. Out of scope for Phase 2

- `Any` user-facing exposure (Phase 6, indefinitely deferred).
- Self-host port of the erasure pass (Phase 7).
- `checkcast` elision analysis — optional optimisation triggered only
  if criterion #3 fails.
- WASM backend updates (the IR shape change ripples there but the
  WASM emitter doesn't exist yet).

---

## 8. Decision points outstanding

1. **Iterator skip mechanism**: ~~confirm (i) `@specialize` decorator or
   (ii) structural heuristic~~ — resolved 2026-05-19 : option (i)
   landed in `0695b459`. Option (ii) future enhancement noted in
   TODO.md §3.5 lever (c).
2. **Comptime + erasure trade-off**: if P2-7 surfaces that comptime
   needs specialised generic fns, decide between:
   - (a) Keep mono for `@comptime`-reachable decls, erase the rest.
   - (b) Comptime walks erased IR with type-info side-table.
   - Decision deferred to during P2-7.
3. **Pivot-test regression threshold**: POC said 15 % ; do we hold that
   line if real-world shows 17-18 %? Decision deferred to P2-10.
4. **Integration path (a) vs (b) from parent doc §8.5**: ~~chosen (a)
   replace `monomorphizeProject` entirely~~ — under reconsideration
   after the 2026-05-19 P2-1.b experiment (see §9 issue 4). Option
   (b) post-process gains relevance because cascading Any types
   through `@specialize`d containers can't be predicted at comptime
   when erasure runs pre-comptime. Decision : revisit before
   resuming P2-1.b.

---

## 9. Issues encountered (2026-05-19 P2-1.b experiment + 2026-05-20 path γ)

Recorded for two reasons : (1) the same issues will resurface during
the Vader self-host port of Phase 2 (per `feedback_vader_port_rules`),
(2) the next attempt on P2-1.b must address these or accept the
fallback to option (b).

### Issue 10 — Path γ exhaustive cascade catalog (2026-05-20)

Final state after path γ : **0 fails** on both native (252/252) and
VM (251/251 ; 4 skip) with `erasureDedupe` enabled. The list below
catalogs every cascade pattern hit during the path-γ exploration
along with the concrete fix, the file/symbol that implements it,
the TS commit that shipped it, and a Vader-port note. The intent is
that when porting this compiler to Vader self-host, each section
becomes a checklist item — no need to re-explore.

**Cascade A — `@intrinsic` impls don't dispatch through vtable**
- Symptom : `vader_unreachable("vtable miss in Hash.hash")` /
  `Equals.equals` / `Add.add` etc. at runtime for any value typed
  `Any` ; affects every common trait on primitives.
- Cause : `@intrinsic` impl members have `body: null` → routed to
  `importIndexBySymId` ; vtable lookup checks `fnIndexBySymId`
  which is empty for these symbols.
- Fix : synthesise BcFunction wrappers per `@intrinsic` impl member
  ; each wrapper body is `local.get 0..N-1` then either the inline
  op (`OP_INTRINSIC_BY_MANGLED` hit) or `call.import` ; registered
  under the impl member's `Symbol.id` in `fnIndexBySymId` so
  `buildVtables` finds it.
- Files : `src/bytecode/emit.ts:synthesiseIntrinsicWrappers`,
  called from `src/midir/emit.ts` after Pass 1 reserve.
- Commit : 1e0ea55d.
- Vader port : same mechanism — emit wrapper BcFunctions in the
  bytecode emit pass after extern reserve.

**Cascade A2 — Vtable dispatcher heterogeneous return types**
- Symptom : C compile error `returning 'vader_string_t' from a
  function with incompatible result type 'int8_t'` when the
  intrinsic wrappers add e.g. `Add.add` to the vtable with multiple
  return ValTypes (i32/string/...).
- Cause : `vtableSignatures` picked the first impl's `result` as
  the dispatcher's return type ; per-arm impl returns of a
  different type → C type mismatch.
- Fix : detect when impls in the same vtable have divergent
  `result` OR `resultType` ; force the dispatcher's sig to
  `result: "any"` (vader_box_t) ; per-arm box via
  `boxExprUnknown` / `vader_b1_to_box`.
- Files : `src/c_emit/ops.ts:vtableSignatures`,
  `src/c_emit/ops.ts:emitVtableDispatchers`.
- Commit : 1e0ea55d.
- Vader port : same logic ; the `result: "any"` discriminator
  flips a single field in the dispatcher emit.

**Cascade A3 — Primitive arrays lose element tag**
- Symptom : `vader_array_get` on `i32[]` / `bool[]` returns
  `vader_box_t` with `tag=0` ; virtual dispatch on the result
  hits the dispatcher's `default` arm (no tag matches).
- Cause : `vader_array_load_slot` reads `payload.i / .f / .b`
  from the primitive-kind storage but leaves `tag = 0` (struct
  init default).
- Fix : runtime add `uint32_t element_tag` to
  `vader_array_buf_t` ; `vader_array_new` takes it as a 4th
  param ; `vader_array_load_slot` stamps `out.tag =
  buf->element_tag` ; C-emit's `array.new` passes the element
  type's BcType index.
- Files : `runtime/c/vader.h`, `runtime/c/vader_runtime.c`,
  `src/c_emit/ops.ts:emitArrayNew`.
- Commit : 1e0ea55d.
- Vader port : runtime change ports as-is ; the C-emit's
  `array.new` emit gets a 4th arg.

**Cascade A4 — `array.set` / `array.new` use wrong box tag**
- Symptom : virtual dispatch on a value read from a BOXED-storage
  array (e.g. `string[]`) sees tag = array's typeIndex instead of
  element's typeIndex → miss.
- Cause : `boxExpr` at array.set called with `op.typeIndex` (array
  type) instead of the element type.
- Fix : extract `elemTag = arrayType.element` before boxing.
- Files : `src/c_emit/ops.ts:emitArrayNew`, `emitArraySet`.
- Commit : 1e0ea55d.
- Vader port : same one-line fix at the bytecode emit site.

**Cascade B1 — Any-bearing instances missing for `@specialize`d
generics**
- Symptom : `B5001 : Iterator impl on ArrayIterator(Entry(Any,
  Any) | null)` at backend ; any erased decl whose field type
  mentions a `@specialize`d generic cascades a query that misses
  the registry.
- Cause : the instance registry was populated during typecheck
  with only concrete-args instances ; post-erasure queries use
  Any-bearing args.
- Fix : `synthesiseErasedSpecializedInstances` walks every
  `@specialize`d generic decl and registers `Self(Any, ...)` ;
  `closeOverGenericImpls` worklist then transitively materialises
  every impl member at the Any-arg substitution.
- Files : `src/comptime/evaluate.ts`.
- Commit : 1e0ea55d.
- Vader port : same — synthesise Any-bearing instances during
  instance collection.

**Cascade B2 — Struct dedupe collapses identity**
- Symptom : if the dedupe replaces every Repeat(i32) / Repeat(string)
  / ... entry with one Repeat(Any) representative, downstream
  `struct.new` / `struct.get` against the original concrete
  `Repeat(i32)` BcType key misses → fallback `ref _` stub →
  `struct.new` against stub emits nothing → garbage runtime.
- Cause : `makeRepresentative` returned a single entry per group ;
  multi-instance generic structs lost per-instance BcType.
- Fix : split struct vs fn dedupe paths. **Fn entries** collapse
  to one representative + per-shape vtable rows via
  `redirectInner` preserving original `typeArgs` (so vtable rows
  for `Range(i32) → fn` vs `Range(char) → fn` both exist and
  point to the same fnIndex). **Struct entries** keep
  per-instance identity (distinct mangled name, distinct
  `typeArgs`) but rewrite `subst` to K→Any so the lowered field
  types are uniform (single shared shape under multiple tags).
- Files : `src/comptime/erasure-dedupe.ts`.
- Commit : 1e0ea55d (initial), b291c7ad (seed selection fix).
- Vader port : critical structural change — implement struct vs
  fn dedupe split from the start.

**Cascade B3 — Pass-1 shadow entries with empty subst win the
group**
- Symptom : `T[] implements Into(Iterator(T))` → Into.into body's
  `struct.new ArrayIterator(T)` emits with `TypeParam(T)` still
  unsubstituted, then internType returns `ref _` → no struct.new
  → corrupted return value.
- Cause : Pass 1 (`monomorphizeProject`) creates a shadow entry
  with `EMPTY_SUBST` for impls whose `forType.kind !== "GenericInstExpr"`
  (e.g. `T[]` is an ArrayTypeExpr). When the dedupe groups it with
  the pass-4 entry (proper subst from Into observation), `group[0]`
  could be the empty-subst entry → `anySubstForEntry(empty) = empty`
  → no substitution.
- Fix : dedupe's seed selection picks the entry with non-empty
  subst : `group.find((e) => e.subst.typeParams?.size > 0)`.
- Files : `src/comptime/erasure-dedupe.ts`.
- Commit : b291c7ad.
- Vader port : same — bias `makeRepresentative` toward an entry
  that actually binds the decl's type-params.

**Cascade B4 — Multi-level any-leaf shapes missing**
- Symptom : `outer :: fn[T](x: T) -> Box(Box(T))` returns 0 bytes
  (just propagates `middle(x)`) ; `struct.new` for
  `Box(Box(Any))` finds only Box(Any) (one extra entry per group)
  and falls back to `ref _` stub.
- Cause : my "extraStructEntries" added ONE Any-flavoured entry
  per group (`Box(Any)`) ; nested erased uses like `Box(Box(Any))`
  need a separate entry with the same group but different
  typeArgs.
- Fix : for each original entry's `typeArgs`, walk the type tree
  and replace each non-Struct leaf with `TY.any` (preserving
  Struct / Trait / Array / Union / Tuple wrappers) ; add one
  extra entry per distinct any-leaves shape, deduplicated by
  mangled name.
- Files : `src/comptime/erasure-dedupe.ts:anyLeavesOf`,
  `displayAnyArg`.
- Commit : f7676446.
- Vader port : same `anyLeavesOf` helper and enumeration.

**Cascade β — Boundary conversion at return**
- Symptom : erased fn returns `Yield(Any) | null` (heap-form)
  but the call site `match it.next() { is Yield(i32) -> ... }`
  expects `Yield(i32)` (inline-eligible single-primitive). The
  match arm reads `payload.i` of a heap pointer → garbage.
- Cause : the erased body returns Any-version layout ; the call
  site's expected layout differs ; no conversion at boundary.
- Fix : `virtual.call` and `call` ops carry `resultTypeIndex` /
  `expectedResultType` (BcType index of the caller's dst local
  type). C-emit's `emitErasureBoundaryConversion` checks
  `expectedResultType !== sig.resultType` then unbox+repack in
  one of three forms (single primitive field inline / single ref
  field inline / heap field-by-field reshape via
  `emitHeapStructReshape`). `BcStruct.symbolId` +
  `computeAnyCounterpartOf` gives the conversion machinery the
  Any-counterpart of each concrete struct.
- Files : `src/bytecode/ops.ts`, `src/midir/emit.ts`,
  `src/midir/dce.ts`, `src/c_emit/emit.ts`,
  `src/c_emit/ops.ts:emitErasureBoundaryConversion`.
- Commit : 1e0ea55d (initial), 6e91fd55 (heap reshape + tuple
  grouping), fe57385c (arg-side reshape + recursive field
  unbox), 8acd9d78 (multi-sibling dispatch).
- Vader port : the new op fields + the C-emit machinery port
  directly. The runtime cost is unbox+repack per call boundary —
  acceptable for correctness.

**Cascade β2 — Argument-side boundary conversion**
- Symptom : `swap[T,U](p: [T,U])` reads `p` through the Any
  layout but main passes a concrete Tuple_24 → swap reads at the
  wrong field offsets.
- Cause : conversion was return-side only ; concrete-shape args
  flow as-is into erased fn bodies.
- Fix : `call` op carries `argTypeIndices: readonly number[]` ;
  C-emit's `emitArgReshape` allocates the Any-layout struct,
  boxes each concrete field, passes the new vader_box_t.
  Symmetric to the return-side reshape.
- Files : `src/bytecode/ops.ts`, `src/midir/emit.ts`,
  `src/midir/dce.ts`, `src/c_emit/ops.ts:emitCallTo`.
- Commit : fe57385c.
- Vader port : same op-field extension + arg reshape helper.

**Cascade γ — Multi-sibling tag-dispatching reshape**
- Symptom : `enumerate` returns `[(usize, T)][]` post-subst
  `[(usize, Any)][]` (Tuple_29 in the IR — mixed layout) ;
  caller's reshape only checked the canonical all-ref Any-
  counterpart (Tuple_27) → no conversion fires → field reads at
  wrong offsets.
- Cause : `anyCounterpartOf` picks one canonical Any-version per
  group ; tuples with mixed concrete + erased fields produce a
  distinct layout that's neither the user's concrete shape nor
  the all-Any version.
- Fix : add `siblingLayoutsOf : Map<concrete, sibling[]>` that
  enumerates every layout in the same group. Reshape emits one
  `if (tag == sibling_X)` branch per sibling ; each branch reads
  fields at the SIBLING's actual struct offsets (cast to the
  sibling's C struct type) with sibling-vs-expected ValType
  dispatch per field (3 cases : same → copy ; ref→primitive →
  unbox ; primitive→ref → box).
- Files : `src/c_emit/emit.ts:computeSiblingLayoutsOf`,
  `src/c_emit/ops.ts:emitHeapStructReshape`,
  `emitHeapStructReshapeForSibling`.
- Commit : 8acd9d78.
- Vader port : multi-sibling enumeration + per-sibling reshape
  port mechanically.

**Cascade γ2 — Union fields in reshape bail too aggressively**
- Symptom : `JsonObject.entries.values()` returns
  `[JsonValue][]` (`JsonValue` is a union of 6 struct
  variants) ; the reshape's `for (const f of expected.fields) if
  (ft.kind !== "primitive" && ...) return;` skipped any tuple
  with a union field → no reshape → `StringChars.next` segfaults
  reading garbage string pointer.
- Cause : the bail check rejected `union` fields conservatively.
- Fix : accept union fields (per-sibling field dispatch already
  handles them via `valTypeOfBcType(union) = "ref"` → both
  sibling and expected slots are vader_box_t → direct copy
  preserves the variant tag). Only `array` / `fn` field types
  still bail (each carries layout invariants the boundary copy
  can't bridge).
- Files : `src/c_emit/ops.ts:emitHeapStructReshape`.
- Commit : f7676446.
- Vader port : same field-kind whitelist relaxation.

**Cascade δ — Array element-kind cascade through erased fns**
- Symptom : erased `map` allocates `out: U[]` (post-subst
  `Any[]`) with BOXED-kind storage ; concrete `sum :: fn(arr:
  i32[])` reads with I32-kind expectation → reads vader_box_t
  bytes as int32_t → garbage.
- Cause : the body's `array.new` is shared and emits BOXED for
  Any element type ; downstream consumers expect primitive-kind
  storage.
- Fix : C-emit's `emitArrayElementKindReshape` (called from the
  return-side boundary conversion) allocates a fresh array with
  the right `element_kind`, copies slot-by-slot with unboxing.
  Handles primitive-element-kind divergence (BOXED → I32 / F64
  / etc.) AND struct-element layout divergence (each slot is the
  wrong concrete struct shape ; recursively reshape via
  `emitHeapStructReshape`).
- Files : `src/c_emit/ops.ts:emitArrayElementKindReshape`.
- Commit : 2f5431ba (primitive branch), 82d96888 (struct
  element branch).
- Vader port : same per-shape reshape ; the runtime cost is
  O(length) per boundary — acceptable for correctness, lossy on
  hot paths. Future optimisation : (10-d3 stdlib API shift to
  Iterator(T)) avoids the array materialisation entirely.

**Cascade δ2 — Lambda fn-pointer calling convention mismatch**
- Symptom : `map(arr, (x: i32) -> x * x)` where the lambda is
  concrete `(i32) -> i32` but map's erased body calls it through
  a fn pointer typed `vader_box_t (*)(void*, vader_box_t)` →
  calling convention reads the box's tag as the i32 arg.
- Cause : `vader_fn_lift_X` wrappers had the lambda's concrete
  param types ; the `call.indirect` cast at the erased call site
  pointed to a sig with vader_box_t args. Cast lied about types.
- Fix : canonical erased fn-pointer sig per arity
  (`vader_fn_erased_sig_N_t`). Lift/tramp wrappers always
  exposing `vader_box_t (*)(void*, vader_box_t, ...)` ; inside,
  each arg is unboxed to the lambda's expected ValType, the
  lambda is called, the result is boxed. `call.indirect` always
  casts to the canonical erased sig and passes boxed args ;
  results tagged `any` and downstream `local.set` / coerce
  unbox to the static expected type.
- Files : `src/c_emit/emit.ts:emitFnTrampolines`,
  `src/c_emit/ops.ts:emitCallIndirect`.
- Commit : 82d96888.
- Vader port : the canonical erased ABI ports as a single
  decision ; the lambda lift wrappers + `call.indirect` cast site
  follow.

**Cascade ε — VM struct match doesn't accept sibling tags**
- Symptom : VM `match x { is Yield(i32) -> ... }` misses when x's
  runtime tag is Yield(Any) ; `vader_unreachable` at the post-
  match fallthrough.
- Cause : VM's `matchTo` did a strict `v.typeIndex === idx`
  comparison for struct types ; no awareness of Any-counterpart
  / sibling layouts that the C-emit's `emitTypeCheck` accepts via
  disjunction.
- Fix : VM caches a `STRUCT_SIBLINGS_CACHE` per module
  (computed lazily, same logic as `computeSiblingLayoutsOf`).
  `matchTo` accepts the requested idx OR any sibling.
- Files : `src/vm/exec.ts:matchTo`, `structSiblingsOf`.
- Commit : f7676446 (this session).
- Vader port : when porting the VM (whenever Vader's self-host
  bytecode VM lands), apply the same sibling-tolerant check at
  the `matchTo` equivalent.

**Cascade ζ — Multi-level inline-box vs erasure (RESOLVED via
multi-level any-leaves)**
- Earlier suspected as a foundational ~1-2 week refactor. Turned
  out to be fixed by Cascade B4 (multi-level any-leaves struct
  entries) : once `Box(Box(Any))` had a real struct entry,
  `outer :: fn[T](x: T) -> Box(Box(T))` body's `struct.new`
  resolved correctly ; main's reshape converted the chain
  back to concrete forms ; `.value.value` accesses worked.
- No separate fix needed beyond f7676446.
- Vader port : implement Cascade B4 (any-leaves enumeration) and
  Cascade ζ falls out for free.

**Vader port summary** : every cascade above ports mechanically.
The infrastructure split is :
  - `comptime/`-side : Famille A wrappers + Famille B dedupe + Any
    instance synthesis + any-leaves enumeration.
  - `bytecode/` IR-side : `call` / `virtual.call` op fields,
    `BcStruct.symbolId`.
  - `midir/` (CFG → bytecode emit)-side : populate the new op fields
    from CFG locals' types ; DCE visits + remaps.
  - `c_emit/`-side : `anyCounterpartOf` + `siblingLayoutsOf` maps,
    `emitErasureBoundaryConversion` family (struct reshape,
    multi-sibling dispatch, array element-kind reshape, arg
    reshape) ; canonical erased fn-pointer ABI + lift / tramp
    wrappers.
  - VM-side : `matchTo` accepts sibling tags.
  - runtime C : `vader_array_buf_t.element_tag` + 4th param to
    `vader_array_new`.

The total LoC budget for the Vader port mirrors the TS commit
diffs (~700 LoC across the layers). No foundational rethink
needed — the path-γ design is the right design.

### Issue 1 — Cascading Any through `@specialize`d containers

**Symptom**: backend error `B5001: \`for x in iter\` requires Iterator
impl on ArrayIterator(Entry(Any, Any) | null)` at
`stdlib/std/collections.vader:200`.

**Cause**: `MutableMap[K, V]` is erased → field
`buckets: (Entry(K, V) | null)[]` becomes
`(Entry(Any, Any) | null)[]`. The for-in fusion then needs
`ArrayIterator(Entry(Any, Any) | null)` which was never registered as
an instance at comptime (the registry only saw concrete shapes like
`ArrayIterator(Entry(string, i32) | null)`).

**Fix candidates**:
- **(a)** Synthesise extra instances during the erasure pass : for
  every `@specialize`d generic container reachable from an erased
  decl's fields, register the Any-bearing instance.
- **(b)** Switch to the parent doc §8.5 option (b) — post-process the
  mono output to dedupe erased entries. The instance registry stays
  as-is (concrete instances only) ; the post-pass collapses what it
  can.
- **(c)** Make the for-in fusion's `ArrayIterator` lookup
  Any-tolerant — if the queried `ArrayIterator(T)` isn't registered,
  fall back to the unparameterised `ArrayIterator` decl's body and
  treat `T` as opaque.

**Vader port note**: the cascade happens any time an erased struct's
field type mentions a `@specialize`d generic. Audit `vader/comptime/`
and `vader/lower/passes/for-in.vader` for the same assumption.

### Issue 2 — Pass 3 (free generic fns) must also erase

**Symptom**: `vader_unreachable` traps inside erased impl methods
that call free generic fns (`self.put(...)` inside
`MutableMap.set_at`).

**Cause**: Pass 3 of `monomorphizeProject` (lines 178-189) emits one
`MonoEntry` per `(FnDecl, typeArgs)` for free generic fns. When the
caller is erased, the call-site typeArgs are post-subst `[Any, Any]`,
which never appears in the registry → `lookupFnInstance` returns
null → bytecode emit emits unreachable.

**Fix**: P2-1.b must include the Pass 3 branch too (experimental fix
worked structurally but uncovered Issue 1 as the next blocker).
Pattern : same `isSpecialized(fnDecl)` ? per-instance : single erased
entry under `ERASED_KEY`. Mirror in `lookupFnInstance`'s lookup with
ERASED_KEY fallback (already shipped as part of the experiment but
reverted with the rest).

**Vader port note**: applies identically. Pass 3 in
`vader/comptime/specialize.vader` (when ported) gets the same branch.

### Issue 3 — Auto-boxing at call sites is partially free

**Symptom (positive)**: in the experimental `/tmp/mm.c`, call sites
like `set_at(t3, vader_box_string(2u, vader_str_0),
vader_box_i32(1u, INT32_C(1)))` showed automatic boxing of
concrete-typed args into the erased Any-typed params. The existing
bytecode emit's val→ref coercion handles this without needing a new
auto-box pass.

**Implication**: P2-5 estimate of 3 days was too generous. The real
work is :
- Verify no edge case where the existing coercion misses (e.g. when
  the param is `Any | null` rather than plain `Any`).
- Handle the box-tag selection : today's boxing uses primitive tags
  (`vader_box_string`, `vader_box_i32`, etc.) which are correct ; for
  struct-typed args flowing into an Any slot, confirm
  `vader_box_obj(structTag, ptr)` is what gets emitted.

**Revised P2-5 effort**: probably 1 day, mostly verification.

**Vader port note**: identical optimisation should apply when
porting. The Vader bytecode emit (in `vader/bytecode/`, currently a
stub) inherits the same val→ref coercion behaviour.

### Issue 4 — Erasure pre-comptime corrupts the instance registry signal

**Symptom**: combining Issues 1 + 2 produces a build that compiles
but traps at runtime on many tests (24/252 native).

**Root cause**: the current order is
```
typecheck → comptime (records instances + monomorphises) → lower → bytecode → emit
```
Phase 2 plugs erasure into the comptime step. But the instance
registry is **populated during typecheck-driven comptime evaluation**
— BEFORE erasure substitutes K→Any. So the registry reflects the
pre-erasure types ; the post-erasure IR queries it with the wrong
types.

**Fix candidates** :
- **(a) Erase later** : keep `monomorphizeProject` as-is, then run a
  separate post-pass between mono and lower that collapses concrete
  entries to their erased equivalents. Lookups happen against the
  post-pass output. This is the §8.5 option (b) the parent doc
  considered "wasteful" but it solves Issue 1 + 2 cleanly because
  the instance registry stays semantically meaningful.
- **(b) Re-register erased instances during the erasure pass** :
  before lowering, synthesise extra registry entries for the
  Any-bearing forms that the erased code paths will need
  (`ArrayIterator(Entry(Any, Any) | null)`, etc.). Doable but
  requires traversing erased field types to discover what to
  synthesise.

**Tentative**: option (a) is now the recommended path. The original
"option (a) replace entirely" from parent doc §8.5 needs revision.

**Vader port note**: when porting, this design choice must be made
the same way in `vader/comptime/`. The TS-side decision sets
precedent.

### Issue 9 — Erased generic body segfaults on Any-typed field access

**Date**: 2026-05-19 (after Issue 8 fix η + investigation).

**Symptom**: with `erasureDedupe` enabled AND η fix applied, the
`mutable_map_string` snippet binary exits with **SIGSEGV (139)** —
not a clean unreachable trap or wrong-output failure. Earlier
hypothesis ("match arms miss tag check") was based on the 28
`vader_unreachable` calls visible in the emitted main body, but the
runtime actually crashes before reaching them.

**Cause** (current hypothesis): the erased MutableMap struct stores
`f_buckets: vader_box_t` for what was `(Entry(K, V) | null)[]`. The
C struct decl :

```c
struct vader_struct_std_collections_MutableMap__Any__Any_t {
    vader_obj_header_t header;
    vader_box_t f_buckets;   // <-- holds an array's box
    size_t f_size;
};
```

When `ensure_buckets` (or first `put`) reads `self.buckets`, it gets
a `vader_box_t`. With erasure, the body's access pattern expects an
array but the box might be in a state incompatible with the access
sequence (NULL payload at unexpected offset, or tag mismatch leading
to a wild pointer deref).

The β fix (`lowerForInRawArray`) only handles `for x in self.buckets`
in user code ; the stdlib's `ensure_buckets` uses `array.push` on the
field directly, which goes through different lowering. After erasure
the type at that site is `Any[]` or `Any` (depending on whether the
substitution flowed through correctly), and the runtime sees a
mismatch.

**Mitigation candidates**:
- **(μ) Trace the segfault** : compile with `-fsanitize=address` and
  run to get the exact failing access. Likely a struct.get or
  array.push on a box whose tag/payload doesn't match the access
  shape. ~1 d.
- **(ν) Inspect the lowered IR for `ensure_buckets`** : `vader dump
  --stage=lowered-ast --filter=ensure_buckets__Any__Any` to see what
  the substituted body shape is. Maybe the array-of-union encoding
  needs additional erasure handling.
- **(ξ) Conservative skip** : flag MutableMap as `@specialize` for
  now to verify the rest of the erasure plumbing works on simpler
  cases (no array-of-union fields). Localises the bug to types with
  this shape.

**Recommended**: (ξ) first to isolate the failure, then (μ) to fix
the root cause. Probably ~2-3 d combined.

**Update (2026-05-19, post-(ξ) experiment)**: (ξ) doesn't isolate
the failure cleanly. Tagging `MutableMap`, `MutableSet`, and
`Entry` with `@specialize` to keep them out of erasure produced a
different B5001 :
`Contains.contains has no monomorphised instance` at
`collections.vader:308`. Reason : `MutableSet.contains` (a generic
free fn) is NOT `@specialize`d, so its body is erased. Inside :
`value in self.inner` where `self.inner: MutableMap(T, bool)` after
subst → `MutableMap(Any, bool)`. The lookup
`lookupImplEntry(Contains.contains, [MutableMap(Any, bool), Any])`
queries against MutableMap's `@specialize`d registry which only
has concrete-key entries (`[MutableMap(string, i32), string]` etc).
Miss → unreachable.

**Confirmed**: the cascade is **fundamental** — locally pinning
any container with `@specialize` just pushes the cascade one step
out. Every erased decl that references a specialized container
creates Any-bearing queries against the container's concrete-key
registry. Local mitigations don't work.

**Path forward (γ revisited)**: synthesise Any-bearing instances
for **every** `@specialize`d generic struct/trait that's reachable
from an erased field. Walk the type graph from each erased decl's
field types ; for every nested `Struct(Any, ...)` reference,
register an instance against the typecheck registry so the impl
materialisation pipeline picks it up. The recursion is bounded by
the project's type graph depth. Estimated 3-5 d.

**Alternative path (Φ)**: step back from full erasure and accept
the cc -O3 cost. The POC measured 177 s baseline. The whole Phase
2 effort targets cutting that by 40-44 % at scale, but each
implementation step has revealed deeper compiler assumptions
about concrete-arg lookups. Practical net gain may be smaller than
projected once all cascade fixes land. Document the achieved
sub-deliverables (Phase 0 vtable infra + Phase 1 inline-box +
β raw-array for-in + Phase 2 plumbing) as the actual ship, defer
full automatic erasure to a future investigation.

**Vader port note**: same struct layout question for
`vader_struct_..._MutableMap__Any__Any_t` when porting. The
`f_buckets: vader_box_t` representation may need a different shape
under erasure — possibly a `vader_array_t*` direct field bypassing
the box wrapper. Also : when porting, prefer (Φ) — the TS-side
investigation here surfaces every structural assumption. Re-doing
the same exploration on Vader side would be wasted effort.

### Issue 8 — Comptime under-registers generic calls inside erased bodies

**Date**: 2026-05-19 (after Issue 8 fix η landed).

**Symptom**: with `erasureDedupe` enabled AND η fix applied,
`set_at__Any__Any` correctly calls `put__Any__Any` (Issue 8 resolved).
But the test snippet `mutable_map_string` still produces no output
and exits 0. The emitted C body of `main` has 28 `vader_unreachable`
calls in match else branches. The user code is :

```vader
v1 :: m["hello"]
match v1 {
    is null -> { println("hello: missing") }
    is i32  -> { println("hello = ${v1}") }
}
```

`v1` is typed as `Any | null` after erasure (V = Any). At runtime the
boxed value has `tag = i32_tag`. The match's `is i32` arm should fire,
but the lowering of `is i32` against an `Any | null` value generates a
type-check that's looking for an exact tag match against a different
value. The `is null` and `is i32` arms both miss, falling into the
synthesised `else { unreachable }`.

**Cause** (hypothesis pending investigation): the match lowering pass
(`src/lower/passes/match.ts`) substitutes the SCRUTINEE type via
`ctx.types.apply`. For `v1: V | null` with V=Any, this gives `Any | null`.
The match arms' `is T` checks compile against the original concrete
typeArg `i32`. The runtime tag check probably uses the wrong tag or
the wrong type identity comparison.

Alternative hypothesis: the match arms see a value boxed with a
HEAP tag (because `get` returns through `Any`), but the `is i32` arm
expected a stack-value primitive tag, so the comparison fails.

**Mitigation candidates**:
- **(κ) Trace match lowering with Any** : instrument
  `src/lower/passes/match.ts` to see what type-check op gets emitted
  for `is i32` when the scrutinee is `Any | null`. Likely a fix in
  the lowering to compare tags structurally rather than by static
  type identity.
- **(λ) Insert checkcast pre-match** : at the lowered IR level, when
  scrutinee is `Any | null`, insert a `checkcast` (or just unbox)
  before each arm's type check so the arm sees the concrete tag.

**Recommended**: (κ) — fix the match lowering. Probably ~1 d in
`src/lower/passes/match.ts` once the failure mode is traced.

**Vader port note**: same investigation must run on
`vader/lower/lower_match.vader` (when ported). The boxed-tag check
against an erased typeArg is the same scenario.

### Issue 8 — Comptime under-registers generic calls inside erased bodies

**Date**: 2026-05-19 (after Issue 7 infrastructure shipped).

**Symptom**: with `erasureDedupe` enabled AND symbol redirects plumbed
through `MonoProject → LoweredProject → CFGProject → bytecode emit`,
the build still produces `unreachable` bodies for ~6 stdlib functions
(`into`, `ensure_buckets`, `put`, `get`, `contains_key`, `assert_eq`).
The redirect log shows `9 redirects produced ; 3/9 applied`. The
6 missed redirects point to representative symbol ids that aren't in
`fnIndexBySymId` because the representatives were DCE-eliminated.

**Cause**: when the lower processes a UFCS-free call like
`self.put(key, v)` inside an erased fn body, it calls
`lookupFnInstance(ctx, putFnDecl, ufcsTypeArgs)`. The lookup queries
`mono.fnInstanceEntries.get(putFnDecl)?.get(...)`. If the comptime
instance registry **never observed `put` as a separate instance**
(e.g. because every observed call site is inside another erased
generic fn that erased its own type-params before observing `put`),
`fnInstanceEntries.get(putFnDecl)` is `undefined`. The lookup
returns null, the caller falls back to `fr.symbol` (the generic decl
symbol, no fnIndex), and the bytecode emit emits `unreachable`.

The symbol redirect map (Issue 7) only carries id→id mappings for
entries that EXIST. If no representative was created, no redirect.

**Mitigation candidates**:
- **(η) Strengthen comptime observation** : when the comptime
  evaluator processes a generic call site that uses TypeParam
  arguments (e.g. `self.put(key, v)` where K, V are typeparams of
  the enclosing impl), it should still register the call as an
  instance — using the FOR-NOW-CONCRETE typeArgs computed from the
  current evaluation context. This way Pass 3 sees at least one
  instance per actually-called generic free fn.
- **(θ) Lazy materialise during dedupe** : if the dedupe sees an
  erased decl referencing a generic free fn with no instances
  registered, synthesise one. Same recursion risk as Issue 6 fix (γ).
- **(ι) Fallback at lookup time** : if `lookupFnInstance` fails AND
  the call site is inside an erased body, fall back to ANY entry in
  `mono.entries` whose decl matches the fnDecl. Hack ; non-
  deterministic ; pickup-the-first-one semantics. Avoid.

**Recommended**: (η) — fix the root cause in comptime. Probably
~1-2 d in `src/comptime/evaluate.ts` + `src/comptime/instances.ts`.

**Vader port note**: same investigation required in
`vader/comptime/` (when porting). The `InstanceRegistry`'s
observation policy for type-param-bearing arguments is the touch
point.

### Issue 7 — Symbol-id → fnIndex routing breaks after dedupe

**Date**: 2026-05-19 (post-β fix).

**Symptom**: with `erasureDedupe` enabled AND the β fix to `for-in`
applied (`lowerForInRawArray`), the build succeeds but 32/252 native
tests fail. The emitted C shows `set_at__i32__bool` (and similar
concrete-named functions) with body `vader_unreachable`.

**Cause**: the dedupe rebuilds the three lookup maps so every concrete
`(member, typeArgs)` query returns the representative entry — that's
correct at the lower's `lookupImplEntry` / `lookupFnInstance` level.
**But** : each concrete entry that got redirected still had its own
synthesised `Symbol` (with a unique `id`). The bytecode emit's
`fnIndexBySymId` map is keyed by `Symbol.id` ; representative gets a
fnIndex, the redirected symbols don't. When the lower stores
`entry.symbol` somewhere (e.g. a LoweredIdent inside an existing
call site that wasn't re-resolved by the new lookup), the bytecode
emit sees an unknown symbol id and emits `unreachable` at the call
site.

**Mitigation candidates**:
- **(δ) Symbol redirection table** : the dedupe maintains
  `symbolReplacements: Map<Symbol.id, Symbol.id>` (old → representative).
  The bytecode emit walks this table when looking up fnIndex by sym
  id and follows redirects. ~0.5 d.
- **(ε) Force-walk lookups during lower** : after dedupe, re-run the
  lower's call-site resolution so every `LoweredIdent` referring to
  a redirected symbol gets re-pointed to the representative. More
  invasive ; touches multiple lower passes.
- **(ζ) Drop redirected entries entirely from `entries[]`** and
  ensure every consumer of `entries[]` (the bytecode emit's
  per-entry walker) only sees the representatives. Dedupe currently
  does this for `newEntries[]` but the per-call-site references in
  the lowered IR still point at old symbols.

**Recommended**: (δ) — minimal touch, keeps the dedupe local.
Implementation : extend `MonoProject` with
`symbolRedirects: ReadonlyMap<number, number>` ; bytecode emit
checks this map before declaring an unknown symbol.

**Vader port note**: when porting, the equivalent map lives in
`vader/bytecode/emit.vader` (when ported). The fnIndexBySymId
construction must handle redirects from the start.

### Issue 6 — Option (b) post-process doesn't solve the cascade either

**Date**: 2026-05-19 (later in the same session).

**Symptom**: with `erasureDedupe` wired in `src/comptime/evaluate.ts`,
the same B5001 errors appear : `for x in iter requires Iterator impl
on ArrayIterator(Entry(Any, Any) | null)`. Plus a new flavour :
`Contains.contains has no monomorphised instance`.

**Cause**: option (b) was meant to keep the instance registry
semantically intact (concrete-typed instances) and let the dedupe
collapse only the non-`@specialize`d entries. But the cascade is
**inside the erased body**. After dedupe, the representative
`MutableMap.put` body has `for bucket in self.buckets` ; the lower
substitutes `self.buckets` to `(Entry(Any, Any) | null)[]`. The
for-in lowering wraps the array into `ArrayIterator((Entry(Any, Any) | null))`,
then queries the registry for the Iterator impl on that exact shape.
The query misses because the registry only saw the concrete shapes
(`ArrayIterator(Entry(string, i32) | null)` etc.).

**Implication**: BOTH options (a) and (b) cascade equally — the
difference is only WHERE the substituted type-shape leaks. The real
problem is the for-in lowering's hard dependency on a registered
Iterator impl entry whose typeArgs exactly match the iter's struct
args. `ArrayIterator` being `@specialize`d means there's no fallback.

**Root mitigation candidates**:
- **(α) De-`@specialize` `ArrayIterator`** : let the dedupe collapse
  it too. Then `ArrayIterator(Entry(Any, Any) | null)` queries find
  the representative and dispatch correctly. **Cost**: lose the
  for-in fusion gain (22.6 → 9.7 ms on `bench/map_iter`) that
  motivated `@specialize` for iterators in the first place.
- **(β) Make raw-array for-in skip `ArrayIterator` entirely** :
  detect `iterType.kind === "Array"` in `lowerForIn` and emit a
  counter loop directly (cursor + indexing), without the
  `wrapArrayAsIter` step. **Cost**: ~1-2 d of careful rewrite of
  the array-iter fast path in `src/lower/passes/for-in.ts` ; once
  done, ArrayIterator's only remaining callers are user code calling
  it explicitly, and the typed-AST-driven fusion still inlines for
  user iterator chains. **Best long-term answer** — for-in on
  arrays should never have gone through ArrayIterator in the first
  place ; the wrap was a syntactic shortcut.
- **(γ) Synthesise Any-bearing instances during dedupe** : walk
  each erased body's typed-AST, find every `@specialize`d container
  use, and pre-register the Any-bearing form in the registry +
  mono. **Cost**: recursive ; non-trivial to bound ; introduces
  synthetic instances the comptime never observed.

**Recommended**: (β) — fix the for-in lowering to handle raw arrays
without ArrayIterator. Unblocks erasure cleanly and improves the
for-in path independently.

**Vader port note**: when porting Phase 2, the equivalent
investigation must run on `vader/lower/lower_for.vader`. The
`wrapArrayAsIter` step there has the same cascade liability.

### Issue 5b — P2-2 boundary side-table is unnecessary

**Symptom**: planning §3 originally proposed a new
`boundaryTypes: Map<Expr, Type>` side-table on `TypedProject`,
recording the original concrete type at each generic boundary so
the lower could emit `checkcast` later.

**Cause for the simplification**: the typed AST already contains the
needed information :
- `ctx.typed.exprTypes.get(expr)` — typecheck's view of the
  expression's type (concrete, computed before erasure).
- `ctx.types.exprType(expr)` — same expression after applying the
  entry's substitution (Any-bearing post-erasure).

When the two diverge AND `ctx.types.exprType(expr).kind === "Any"`,
the lower knows : this is a generic-erasure boundary, insert
`checkcast(concrete_type)` here.

**Implication**: P2-2 collapses into a documentation task (add the
contract comment to `src/lower/entry-types.ts`). The actual
checkcast insertion is P2-6's responsibility — single lower-side
predicate `needsCheckcast(expr)`, no pre-computed map.

**Vader port note**: when porting, the same observation holds for
the Vader self-host — `ctx.typed.expr_types` vs `ctx.types.apply`
divergence is the boundary detector. No additional side-table.

### Issue 5 — Lower-side dispatch on Any (P2-4) works

**Symptom (positive)**: with P2-4 active (commit `1639dbf3`), method
calls on `Any` receivers correctly route to `lowerVirtualDispatch`,
which emits `LoweredVirtualCall` → `virtual.call` bytecode op →
runtime dispatch via the existing `BytecodeModule.vtables` map.

**Implication**: the Phase 0 vtable runtime (`vader_vtable_table`)
is parallel infrastructure ready for direct calls from C-emitted
code, but the lower itself uses the older `virtual.call` op which
already worked for trait-typed receivers. No new IR node needed.

**Confirmation that nothing was broken by P2-4**: 252/252 native
tests still pass with P2-4 active (no Any producers in stable code).

**Vader port note**: when porting P2-4, mirror the
`receiverType.kind === "Any"` branch in `vader/lower/lower_expr.vader`
trait-method handling. The vtable dispatch infrastructure on the
Vader side is whatever the bytecode-level `vtables` map exposes —
should not need new ops.

---

## 10. Path forward (revised after 2026-05-19 experiment)

Three tasks reduced or eliminated by the post-experiment analysis :
- **P2-2** : no new side-table needed (Issue 5b). Becomes a one-line
  contract comment in `entry-types.ts`.
- **P2-5** : auto-boxing already works via existing bytecode val→ref
  coercion (Issue 3). Becomes a verification pass on edge cases.
- **P2-4** : already done dormant (commit `1639dbf3`).

Remaining real work :
1. **Decide integration path (a) vs (b)** — §11 below details the
   trade-offs ; cannot proceed without this.
2. **P2-1.b** under the chosen path — flip the switch.
3. **P2-6** auto-cast — single lower-side predicate as per Issue 5b.
4. **P2-7** comptime interaction validation.
5. **P2-8** registry rekeying (touches DCE + hash-cons + impl).
6. **P2-9** snapshot audit + bulk update.
7. **P2-10** perf check.
8. **P2-11** self-host parity rebaseline.

---

## 11. Integration path decision (BLOCKING P2-1.b)

The 2026-05-19 experiment showed option (a) from parent doc §8.5
("replace `monomorphizeProject` entirely") has problems the original
plan didn't surface. Reconsider :

### Option (a) — Replace `monomorphizeProject` entirely

The erasure happens INSIDE `monomorphizeProject` ; for non-`@specialize`d
generics, the function emits one MonoEntry with `subst = K→Any` instead
of N entries per typeArgs combo.

- **Pro** : single pass, no extra IR layer.
- **Pro** : downstream sees fewer MonoEntries (less work in lower +
  bytecode).
- **Con (NEW, from experiment)** : the comptime instance registry is
  populated BEFORE erasure runs, so it captures concrete instances
  (`ArrayIterator(Entry(string, i32) | null)`). Post-erasure code
  queries the registry with Any-bearing types
  (`ArrayIterator(Entry(Any, Any) | null)`) → lookup fails → backend
  B5001 errors (Issue 1, 4 above).
- **Mitigation**: synthesise extra instances during erasure for each
  Any-bearing form reachable from erased fields. Doable but recursive
  (a struct's field type may reference another generic which
  references another…).

### Option (b) — Post-process the mono output

`monomorphizeProject` runs as-is (concrete N-per-decl entries). A
new pass runs between mono and lower that, for each non-`@specialize`d
generic decl :
- Picks ONE representative entry (the first concrete instance, say).
- Re-substitutes its body with `K → Any` (instead of `K → string`).
- Marks the other (N-1) entries as redirects → the representative.
- Lookups update : `lookupImplEntry` returns the representative for
  any matching `(member, typeArgs)`.

- **Pro** : the instance registry stays semantically intact
  (Issue 1 disappears).
- **Pro** : the post-pass is bounded — it only touches entries the
  registry already produced, no recursive type discovery.
- **Pro** : reverting / debugging is local to the post-pass ; mono
  itself stays unchanged.
- **Con** : two passes instead of one (mono + post-pass). Wasted
  work : N concrete entries computed then discarded. Estimated
  overhead : moderate during typecheck (the cost is at compile-time,
  not runtime, and the entries themselves are cheap structurally).
- **Con** : the redirect map adds a layer of indirection in
  `lookupImplEntry` / `lookupFnInstance`.

### Recommendation

**Option (b)** — the experimental cost of (a) (synthesising recursive
instances) outweighs its single-pass elegance, and (b)'s "wasted
work" is bounded and trivially undoable.

Path forward under (b) :
- Keep `monomorphizeProject` as-is.
- Add a new pass `erasureDedupe(mono: MonoProject) → MonoProject` in
  a new file `src/comptime/erasure-dedupe.ts`.
- The pass walks `mono.entries`, groups by `decl`, and for each
  non-`@specialize`d generic group :
  - Picks the first entry as representative.
  - Re-emits the entry's `subst` with type-params mapped to
    `TY.any`.
  - Replaces all other group members in `mono.entries` with the
    representative.
- Rebuilds `lookupByInstance`, `implMethodEntries`, `fnInstanceEntries`
  so every concrete-typeArgs query resolves to the representative.
- The lower walks the deduped mono and sees the Any-bearing
  representative ; `lookupImplEntry(member, args)` returns it for any
  matching `(member, args)` pair.

Under (b), `ERASED_KEY` from P2-1.a becomes irrelevant (the lookup
maps key by concrete args, but every concrete-args query resolves to
the same representative entry). The ERASED_KEY fallback in
`lookupImplEntry` / `lookupFnInstance` stays harmless dead code (a
miss falls through to the `??` chain returning null) — can be
removed after (b) lands.

**Action**: confirm option (b) before resuming P2-1.b.
