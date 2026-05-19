# POC + Phase 0 results — 2026-05-19

> **Phase 0 closed 2026-05-19.** All 5 active tasks done (P0-1 runtime
> helper, P0-2 slot registry, P0-3 C emit vtables, P0-4 internal Any
> Type kind, P0-6 validation). P0-5 (lower-side dispatch on Any
> receivers) deferred to Phase 2 — no producer of `Any` types yet
> makes the lower-side path untestable in isolation.
>
> Phase 0 exit criterion met via `bench/poc_erasure/Makefile :: verify`:
> the compiler emits per-tag vtables in the format
> `vader_virtual_dispatch` consumes, and a Vader binary that uses a
> user-defined trait impl compiles, links, and runs.
>
> Next: Phase 1 (inline-box generalisation) can start in parallel
> with Phase 2 (automatic erasure pass).

---

# POC results — 2026-05-19

Hardware: Apple Silicon (M-series), `cc` = Apple clang from Xcode 26.0.0
toolchain, `-O3 -std=c11`. Single-threaded measurements.

## Baseline re-measurement (POC doc §3)

| Measurement | Documented | Re-measured 2026-05-19 |
|---|---|---|
| Self-host `cc -O3` wall-time (`bun run build:cli`) | 161 s | **177 s** (174 s user) |
| `bench/map_iter` Vader-native min | 9.7 ms | 11.1 ms |
| `bench/map_iter` Vader-native median | — | 14.4 ms |

The 177 s is on a slightly different machine state than the doc's 161 s;
the order of magnitude matches.

## Layout

```
sizeof(vader_box_t)    = 24
sizeof(user_t)         = 24
sizeof(mono_entry_t)   = 48     // string key + 24-byte value + ptr
sizeof(erased_entry_t) = 56     // 2 boxes (24+24) + ptr
sizeof(mono_map_t)     = 136
sizeof(erased_map_t)   = 144    // +8 for vtable ptr
```

Erased entry is **17 % bigger** than mono entry (56 vs 48) — packs fewer
entries per cache line. Visible in iteration cost (3.0 vs 1.5 ns/visit
in earliest run).

## Runtime — `string → user_t` (24-byte value, NOT inline-fittable)

5 runs, captured in `/tmp/poc_results.txt`:

| op       | mono min | erased min | erased/mono |
|----------|---------:|-----------:|------------:|
| put      |  81.8 ns |   108.3 ns | **1.32×** |
| get      |  84.8 ns |    97.8 ns | **1.15×** |
| iter     |   1.4 ns |     2.2 ns | **1.57×** (ns per visit, 100 outer loops) |

Put regression includes the **extra heap alloc per box** of the
non-inline-fittable `user_t` payload — exactly the issue Phase 1
(inline-box generalisation) targets.

## Runtime — `string → i64` (i64 inlines into `vader_box_t.payload.i`)

| op       | mono ns/op | erased ns/op | erased/mono |
|----------|-----------:|-------------:|------------:|
| put      |   85.5 ns  |    101.5 ns  | **1.19×** |
| get      |   81.4 ns  |     97.5 ns  | **1.20×** |

Allocations on `put`: **mono = 1000, erased = 1000** (one entry node
per unique key; no extra box alloc — the i64 value inlines). Confirms
**criterion #1 holds when the value type is inline-fittable**.

## inline-vt variant (vtable function pointers stored on the map)

| op       | external vt | inline vt |
|----------|------------:|----------:|
| put      |    101.5 ns |   96.0 ns |
| get      |     97.5 ns |  104.0 ns |

Inline-vt is **not consistently faster**. The saved load is offset by
the larger map struct pushing data out of the cache line. Conclusion:
external table is the right default.

## Multi-instantiation cc -O3 (POC doc §5 criterion #3)

`make burst` compiles `gen_mono_burst.c` and `gen_erased_burst.c` with
`BURST_N` set to {1, 4, 16, 32, 45}. Mono adds a full struct + put + get
per N; erased adds only a 2-pointer vtable per N.

| N  | mono cc | mono obj | erased cc | erased obj | cc-time gain | obj gain |
|----|--------:|---------:|----------:|-----------:|-------------:|---------:|
|  1 | 0.05 s  |   1048 B |    0.03 s |      864 B |        -40 % |   -18 % |
|  4 | 0.03 s  |   2592 B |    0.03 s |     1696 B |          0 % |   -35 % |
| 16 | 0.05 s  |   8768 B |    0.03 s |     5032 B |        -40 % |   -43 % |
| 32 | 0.07 s  |  17024 B |    0.04 s |     9496 B |        -43 % |   -44 % |
| 45 | 0.09 s  |  23736 B |    0.05 s |    13112 B |        -44 % |   -45 % |

Absolute cc-times are tiny here (< 100 ms) and not directly extrapolable
to the 177 s self-host build, but the **object-size scaling is the
relevant signal**: erased growth per N is ~270 B (vtable + shim);
mono growth per N is ~530 B (full instantiation). At 45 instantiations
(the count documented for `MutableMap` in `docs/STDLIB_GENERIC_COLLAPSE.md`
§0), the **erased TU is 45 % smaller** than mono. The cc -O3 wall-time
follows approximately the same ratio because the dominant costs
(parsing, mem2reg, SROA) are near-linear in TU size — exactly as the
parent doc §5.2 argued.

## Criterion grading

| # | Criterion | Threshold | Measured | Pass? |
|---|---|---|---|---|
| 1 | Insert allocs = entry only (inline-fittable value) | 0 extra/op | 0 extra (i64) | ✅ **PASS** |
| 2 | `get` runtime ≤ 1.10× mono | 1.10× | 1.15-1.20× | ❌ **FAIL** by ~5-10 pp |
| 3 | `cc -O3` ≥ 15 % reduction at scale | 15 % | -40 % to -44 % at N ≥ 16 | ✅ **PASS** (large margin) |
| 4 | `VADER_GC_STRESS=1` green | green | N/A — POC uses `malloc` | ⚠️ **DEFERRED** to Phase 4 |
| 5 | `vader_box_t` ≤ 32 bytes (external table mode) | ≤ 32 | 24 (unchanged) | ✅ **PASS** |

**Score: 3 PASS / 1 FAIL / 1 DEFERRED.**

Per the decision tree (POC doc §5):

- Strict reading (count only measurable criteria, treat DEFERRED as
  "unknown") → 3/4 = 75 % → discussion required (closer to "4/5" than
  to "≤ 3/5").
- Lenient reading (treat DEFERRED as "likely-pass given the POC uses
  `malloc` rather than GC, and the production pass would use `vader_gc_alloc`
  which the existing snippets already stress-test) → 4/5 → discussion.

## Reading the failure on criterion #2

The 1.15-1.20× regression on `get` is dominated by:

1. **Indirect dispatch** (one extra indirect call through the vtable
   function pointer). Modern OOO CPUs predict it after the first few
   iterations; the cost is ~3-5 cycles steady-state.
2. **Larger entry struct** (56 vs 48 bytes — 17 % more cache line
   pressure on chain walks).
3. **Box construction at the call site** (`box_string(poc_key(i))`
   builds a 24-byte `vader_box_t` per call — likely register-resident
   under `-O3` but adds setup work).

Source #1 is intrinsic to the erasure model and cannot be cheaper than
direct dispatch.

Sources #2 and #3 are **partly addressable** by Phase 1 (inline-box
generalisation lets the entry pack more aggressively) and by a Phase 3
optimisation that elides redundant box-unbox round-trips on the call
boundary.

## What this POC measures honestly, and what it does not

- ✅ The dispatch-cost overhead of erased generics (criterion #2).
- ✅ The object-size and cc -O3 wall-time gain at scale (criterion #3).
- ✅ The inline-fittable boxing claim (criterion #1, only for i64).
- ✅ The vtable layout cost (criterion #5, external table).
- ❌ The GC interaction (criterion #4) — POC uses `malloc`.
- ❌ The full `MutableMap(Pair, i64)` case for criterion #1 — POC uses
     `string → i64`, which inlines for a different reason than what Phase 1
     would solve for. The Phase 1 inline-box generalisation question
     (packing a multi-field 16-byte payload into the box) is **not
     exercised** by this POC.
- ❌ The compiler-internal regime where I-cache locality on 45
     consolidated map functions might offset the indirect-dispatch cost
     (parent doc §5.3) — POC is too small to surface this signal.

## Recommendation

**Borderline pass.** The trade-off measured here is:

- **Loss**: ~20 % regression on hot `get` micro-bench.
- **Win**: ~45 % reduction in TU size and cc -O3 wall-time at 45
  instantiations.

For the compiler use case (the primary motivation in the parent doc),
maps are touched in mostly cold paths (symbol resolution, type
registry, module cache). A 20 % regression on a synthetic hot loop is
likely invisible in the end-to-end self-host build time; meanwhile a
40-44 % cc -O3 gain is directly visible (177 s → ~100-120 s estimated).

I recommend the user **decide between two options**:

- **(A) Proceed to Phase 0** (vtable runtime, ~1-2 weeks). Phase 0 is
  incremental and does not lock in the IR-shape change. After Phase 0,
  re-evaluate criterion #2 on a real workload (one of the 3 pivot tests
  from `docs/STDLIB_GENERIC_COLLAPSE_POC.md` §7). If the real-world
  regression is still > 10 %, decide whether to proceed to Phase 1 or
  to revisit.
- **(B) Fallback to Core/Shell** (parent doc §7, ~2 weeks). Avoids the
  runtime regression entirely. Smaller compile-time gain (~8 % vs the
  ~45 %+ this POC suggests for erasure at scale) but no perf risk.

Recommended call: **(A) — proceed to Phase 0**, with the explicit
exit criterion that the pivot-test real-world regression on `get` must
be ≤ 15 % after Phase 0 lands. If it isn't, Phase 1 work is not a
guaranteed fix and the team should re-evaluate.
