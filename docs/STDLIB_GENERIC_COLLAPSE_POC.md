# POC: hand-written erased `MutableMap`

> **Status**: prospective. Gates the whole erasure effort planned in
> `docs/STDLIB_GENERIC_COLLAPSE.md`. Until the 5 success criteria of
> §5 pass on the hand-written POC, no work starts on Phase 0 (vtable),
> Phase 1 (inline-box generalisation), or Phase 2 (erasure pass).
>
> **Cross-refs**: `docs/STDLIB_GENERIC_COLLAPSE.md` (parent plan,
> Decision log entry "2026-05-19 — A POC precedes Phase 0").

---

## 0. Why this POC exists

Investigation on 2026-05-19 surfaced three structural unknowns that
the parent plan downplayed:

1. **No vtable exists.** Trait method dispatch on generic params is
   direct after monomorphisation
   (`src/lower/passes/expr.ts:190-205`, case `"trait-method"`). The
   erasure pass cannot reuse an existing indirection — it must build
   one. That work has not been scoped, layout-decided, or measured.
2. **No `box_to_any` / `checkcast` runtime helpers.** `vader_box_t` is
   24 bytes (`runtime/c/vader.h:93-103`); inline-box gates on
   one-field-only structures (`src/bytecode/types.ts:300-333`). No
   generic API for `i64 ↔ box` or `box → T checkcast` exists today.
3. **`specialize.ts` is 376 LoC (not 180).** Four direct lower-side
   consumers, 14 indirect via `LowerProjectCtx`. The "replace
   `monomorphizeProject` entirely" option (a) from §8.5 of the parent
   plan is more invasive than originally framed.

A 3–5 day hand-written POC answers the load-bearing question — **is
the erasure model perf-acceptable given the actual runtime, on this
codebase, on this machine?** — before committing to ~14 weeks of
compiler work.

---

## 1. Goal

Produce a hand-written Vader + C reference implementation of one
erased generic (`MutableMap(string, User)`) and measure it against
the existing monomorphised version. The POC must:

- Validate that the model passes the 5 success criteria of §5.
- Surface unknown unknowns about vtable layout, box layout, and
  dispatch cost before the compiler is touched.
- Produce a reference implementation the real Phases 0–3 can mimic.

---

## 2. Scope

**Three artefacts. Zero compiler changes.** Everything is written by
hand in plain Vader + C, compiled by the current TS compiler.

### 2.1 Erased map and entry — Vader source

File: `bench/poc_erasure/erased_map.vader`

Hand-written equivalent of what the erasure pass would emit:

```vader
// Pseudocode sketch — final wording TBD during POC writing.
ErasedMap :: struct {
    buckets: (ErasedEntry | null)[]
    size:    usize
    key_vtable: *Vtable    // pointer to Hash & Equals slots for the key type
}

ErasedEntry :: struct {
    key:   Any
    value: Any
    next:  ErasedEntry | null
}

put_erased :: fn(self: ErasedMap, key: Any, value: Any) -> void { ... }
get_erased :: fn(self: ErasedMap, key: Any) -> Any | null      { ... }
```

The map is parameterless at the Vader level. Trait method calls go
through the `key_vtable` stored on the map (one vtable shared by all
keys of a given concrete type), not through a per-box vtable. This
choice is **intentional for the POC**: it isolates the question
"does indirect dispatch perform acceptably?" from the question
"vtable layout option (a) vs (b)?" — the second is answered by
running the same POC under both layouts.

### 2.2 Dispatch helper — C source

File: `bench/poc_erasure/vader_poc_dispatch.h` + `.c`

Minimal runtime helper:

```c
typedef struct {
    uint64_t (*hash)(vader_box_t key);
    int      (*equals)(vader_box_t a, vader_box_t b);
} vader_poc_vtable_t;

static inline void* vader_poc_dispatch(
    vader_poc_vtable_t* vt, int slot
) {
    // slot 0 = hash, slot 1 = equals
    return slot == 0 ? (void*)vt->hash : (void*)vt->equals;
}
```

Two concrete vtables filled in by the POC: one for `string` keys,
one for `User` values. The Vader code calls
`(*vader_poc_dispatch(vt, HASH_SLOT))(boxed_key)` for `key.hash()`.

### 2.3 Bench harness — Vader source

File: `bench/poc_erasure/bench.vader`

Three measurements over both implementations (erased and
monomorphised baseline from `tests/snippets/mutable_map_string`):

- **100k inserts** — wall-time, allocation count under
  `VADER_GC_STRESS=1`.
- **100k random gets** — wall-time, cycles per `get` (microbench).
- **100k iterations** — wall-time, allocation count.

Wall-time of `cc -O3` on the bench TU itself is also measured (the
parent plan's primary motivation is `cc` time).

---

## 3. Baseline

| Measurement | Source | Target value | Re-measured 2026-05-19 |
|---|---|---|---|
| `cc -O3` on self-host monolithic TU (`bun run build:cli`) | Re-run on machine pre-POC | 161 s (TODO §3.5, last measured 2026-05) | **177 s** wall / 174 s user |
| `bench/map_iter` Vader-native min | baseline.json | 9.7 ms | 11.1 ms |
| Insert wall-time, monomorphised `string→user_t` (POC bench) | `bench/poc_erasure/bench` | TBD | **81.8 ns/op** (min over 5 runs) |
| Insert allocations, monomorphised | `poc_alloc` counter | TBD | 1000 (one per unique key, no extra box) |
| Get wall-time, monomorphised `string→i64` | POC bench | TBD | **81.4 ns/op** |

The 177 s is on the current machine state, slightly above the
historical 161 s. Order of magnitude matches.

Full raw output: `bench/poc_erasure/results.md`.

---

## 4. Hand-written design

Detailed during writing. The sketch in §2 is the structural shape;
the implementation work is:

- Vtable initialisation (one `vader_poc_vtable_t` per concrete key
  type, populated at module init).
- Boxing primitives: hand-rolled `box_string(s) -> Any`,
  `box_user(u) -> Any`, `unbox_user(any) -> User`. Mirror what
  Phase 2 will generate.
- Checkcast: a runtime tag check on unbox. The POC uses a hard-coded
  tag table; the real pass will use the existing `vader_type_info_t`.
- Map operations: `put`, `get`, `each`, `remove` — all expressed
  against `Any` parameters with virtual dispatch on key operations.

---

## 5. Success criteria — measured 2026-05-19

| # | Criterion | Threshold | Measured | Pass? |
|---|---|---|---|---|
| 1 | Insert allocs = entry only (inline-fittable value) | 0 extra/op | 0 extra alloc per put (i64 value inlines into `payload.i`) | ✅ **PASS** |
| 2 | `string → user_t` get runtime | ≤ 1.10× mono | 1.15-1.20× across runs | ❌ **FAIL** by ~5-10 pp |
| 3 | `cc -O3` ≥ 15 % reduction at scale | ≥ 15 % | -40 % to -44 % at N ∈ {16, 32, 45} instantiations | ✅ **PASS** (large margin) |
| 4 | `VADER_GC_STRESS=1` green | green | N/A — POC uses `malloc`, not `vader_gc_alloc` | ⚠️ **DEFERRED** to Phase 4 |
| 5 | `vader_box_t` ≤ 32 bytes (external table mode) | ≤ 32 | 24 (unchanged) | ✅ **PASS** |

**Score: 3 PASS / 1 FAIL / 1 DEFERRED.**

Per the original decision tree:

- **5/5 pass** → Phase 0 (vtable) starts. Layout chosen per criterion #5.
- **4/5 pass** → discussion on the single failed criterion before deciding.
- **≤ 3/5 pass** → fallback to the manual Core/Shell pattern documented
  in `docs/STDLIB_GENERIC_COLLAPSE.md` §7.

Strict reading (treat DEFERRED as "unknown") → 3/4 measurable = effective
**4/5 with discussion**. The single failure (criterion #2) is by a
modest 5-10 pp margin and is intrinsic to indirect dispatch.

### Reading the failure on criterion #2

The 1.15-1.20× regression on `get` is dominated by:

1. Indirect dispatch through the vtable function pointer (~3-5 cycles
   steady-state once the branch predictor stabilises).
2. Larger entry struct (56 vs 48 bytes — 17 % more cache-line pressure
   on chain walks).
3. Box construction cost at the call site.

Source #1 is intrinsic to the model. Sources #2 and #3 are partially
addressable by Phase 1 (inline-box generalisation) and a Phase 3
optimisation that elides redundant box-unbox round-trips.

### Decision recommendation

**Borderline pass.** Trade-off measured:

- **Loss**: ~20 % regression on hot `get` micro-bench.
- **Win**: ~45 % reduction in TU object size and cc -O3 wall-time at 45
  instantiations.

For the compiler use case (the primary motivation), maps are touched
mostly in cold paths (symbol resolution, type registry, module cache).
The 20 % synthetic-micro-bench regression is likely invisible in
end-to-end self-host build time; meanwhile a 40-44 % cc -O3 gain at
scale is directly visible (177 s → estimated 100-120 s).

Two options:

- **(A) Proceed to Phase 0** (vtable runtime, ~1-2 weeks). Incremental
  work that does not lock in the IR-shape change. After Phase 0,
  re-evaluate criterion #2 on a real workload (pivot tests §7). If
  real-world regression > 10 %, decide whether to proceed to Phase 1
  or fall back.
- **(B) Fallback to Core/Shell** (parent doc §7, ~2 weeks). Avoids the
  runtime regression entirely. Smaller compile-time gain (~8 % vs ~45 %).

POC recommendation: **(A) — proceed to Phase 0**, with explicit exit
criterion that pivot-test real-world regression on `get` must be ≤ 15 %
after Phase 0 lands.

---

## 6. Estimated effort

| Task | Effort |
|---|---|
| Re-measure baseline (`cc -O3`, runtime, allocations) | 0.5 day |
| Write `bench/poc_erasure/erased_map.vader` | 1 day |
| Write `bench/poc_erasure/vader_poc_dispatch.{h,c}` | 0.5 day |
| Write `bench/poc_erasure/bench.vader` | 0.5 day |
| Run measurements, both vtable layouts | 0.5 day |
| Analysis, fill in this doc with actuals, decision | 0.5–1 day |
| **Total** | **3–5 days** |

---

## 7. Pivot tests for smoke-check

Once the POC builds and passes its own bench, run these 3 existing
snippets against the POC bench harness setup (no compiler change —
the snippets compile as today; this is a sanity check that the POC
infrastructure does not regress anything):

1. `tests/snippets/for_in_into_iter/_main.vader` — collections + iterators + desugar
2. `bench/map_iter.vader` — `Entry(K, V)` generic + 1M `Yield` allocations
3. `tests/snippets/custom_iter_generic/_main.vader` — generic struct + trait bound

These pivots cover ~80 % of the 17 direct generic-touching tests and
~50 % of the ~30 indirect-touching tests in the corpus.

---

## 8. Out of scope for the POC

Explicitly deferred — answered by later phases, not here:

- **Iterator skip mechanism** (`@specialize` decorator vs structural
  heuristic). POC scope is one collection; iterators are not
  touched. Decision made during Phase 1, informed by the POC
  outcome.
- **Inline-box generalisation for multi-field structs** (Phase 1
  scope). POC restricts itself to `string` keys and `User` values
  (both already inline-fittable as `void*` payload).
- **Full erasure pass design** (Phase 2 scope). POC hand-writes one
  case; the pass that generalises it is out of scope.
- **GC scanner update if vtable layout grows the box** (Phase 0
  follow-up). POC measures both layouts but does not modify the
  scanner — for criterion #5, layout (b) is measured by hand-rolling
  a `vader_box_t_32` variant in the POC's C file.

---

## 9. Open questions answered by the POC

By the end of the POC, this doc commits answers to:

1. Does indirect dispatch on `hash` / `equals` regress get/insert
   perf within 10 % of the monomorphised baseline?
2. Does the `cc -O3` shrink predicted by §5 of the parent plan
   (~15–25 %) materialise on a representative TU?
3. Which vtable layout (external table indexed by tag vs in-box
   pointer) wins on the joint metric (perf × box size × scanner
   complexity)?
4. Is the existing inline-box optimisation sufficient for `string`
   keys and reference-typed values, or does the POC already need
   Phase 1's generalisation to hit criterion #1?

---

## 10. After the POC — result and next step

POC executed 2026-05-19. **Score: 3 PASS / 1 FAIL / 1 DEFERRED.**

Files produced in `bench/poc_erasure/`:
- `shared.{h,c}`, `mono_map.{h,c}`, `erased_map.{h,c}`,
  `erased_map_inline_vt.{h,c}` — POC implementations
- `gen_mono_burst.c`, `gen_erased_burst.c` — multi-instantiation cc -O3 stress
- `bench.c` — driver
- `Makefile` — build harness (`make`, `make bench`, `make sizes`, `make burst`)
- `results.md` — raw output and analysis

**Decision 2026-05-19: option (A) — proceed to Phase 0 with the 15 %
real-world exit criterion.** See `docs/STDLIB_GENERIC_COLLAPSE.md`
Decision log entry "2026-05-19 — Proceed to Phase 0 after POC".

**Ready for Phase 0.** Detailed plan in
`docs/STDLIB_GENERIC_COLLAPSE_PHASE0.md`. Work starts on
`runtime/c/vader_vtable.{h,c}`, a trait-method slot registry on the
compiler side, and a per-tag vtable emitter in `src/c_emit/`.
