# Phase 2 — Automatic erasure pass

> **Status**: planning, after Phase 1 (committed `0d9ebc80`). The main
> event of the erasure plan.
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

## 9. Issues encountered (2026-05-19 P2-1.b experiment)

Recorded for two reasons : (1) the same issues will resurface during
the Vader self-host port of Phase 2 (per `feedback_vader_port_rules`),
(2) the next attempt on P2-1.b must address these or accept the
fallback to option (b).

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

Sequencing change : do P2-2 (boundary side-table) and P2-5 (auto-box
verification) BEFORE attempting P2-1.b again. Also decide §8 issue #4
(integration path option a vs b) — current lean : **option (b) post-
process**.

Revised order :
1. ~~P2-3 `@specialize`~~ ✅ done
2. ~~P2-1.a foundation~~ ✅ done
3. ~~P2-4 lower dispatch on Any~~ ✅ done (dormant)
4. **P2-2 boundary side-table** — next session start
5. **P2-5 auto-box verification** (now 1 d, not 3) — confirm existing
   coercion handles the common cases
6. **Decision: option (a) vs (b) in §8 issue #4** — this is the pivot
   point ; commit to a direction before P2-1.b
7. P2-1.b switch flip (under the chosen integration path)
8. P2-6 auto-cast — depends on P2-2 side-table
9. P2-7 comptime interaction
10. P2-8 registry rekeying
11. P2-9 snapshot audit
12. P2-10 perf check
13. P2-11 self-host parity rebaseline
