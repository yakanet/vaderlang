# POC: hand-written erased `MutableMap` — measurement harness

Gate POC for `docs/STDLIB_GENERIC_COLLAPSE_POC.md`. Three artefacts
compiled side-by-side with `cc -O3` against the existing `runtime/c/`:

| File | Role |
|---|---|
| `mono_map.c` | Monomorphised `MutableMap<string, User>` — representative of what the Vader compiler emits today (one specialised struct + one specialised function set per concrete type). |
| `erased_map.c` | Erased equivalent — one struct, one function set, indirect dispatch on key operations through a vtable. Models what the erasure pass would emit. |
| `bench.c` | Driver. Runs identical workload (100k inserts / 100k gets / 100k iterations) on both implementations, prints timings + allocation counts. |

## Build & run

```sh
make            # builds three binaries: bench_mono, bench_erased, bench_both
./bench_both    # runs both implementations sequentially, prints comparison
make clean
make sizes      # reports per-TU object size and cc -O3 wall-time
```

## What this measures (5 criteria from POC doc §5)

1. Insert allocations per op for a `Pair`-like 16-byte value (modelled by `User { name: string; age: i32 }` ≈ 24 bytes payload).
2. Get runtime: erased vs mono.
3. `cc -O3` wall-time: erased TU vs mono TU.
4. Memory safety under stress (no leaks, no double-frees, no use-after-free) — uses malloc here rather than the GC; the production pass will use `vader_gc_alloc`.
5. Vtable layout cost — two variants tested via `MODE=external|inbox` envvar at compile time.

Results are recorded in `docs/STDLIB_GENERIC_COLLAPSE_POC.md` §3 and §5.
