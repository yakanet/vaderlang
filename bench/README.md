# Vader benchmarks

Ten cross-language workloads spanning float CPU, integer CPU, iterator chains, GC throughput, string-runtime throughput, and array accessors — so a perf change in any of those subsystems trips a regression.

Every workload lives in its own directory `bench/<name>/` with all four language implementations colocated — `<name>.vader`, `<name>.ts`, `<name>.go`, `<name>.java` — alongside the compiled artefacts the harness produces.

| workload         | exercises                                       | algorithm                                                       | scale                                  |
|------------------|-------------------------------------------------|-----------------------------------------------------------------|----------------------------------------|
| `mandelbrot`     | f64 arithmetic, tight loop                      | per-pixel iteration of `z := z² + c` until escape or cap        | 240 × 180 grid, max 500 iter per pixel |
| `primes`         | i32 / i64 arithmetic, modulo                    | count primes ≤ N by trial division up to `√n`                   | N = 1 000 000                          |
| `iter_chain`     | lazy iter dispatch, per-iter union allocation   | Σ x² for even x in [0, N) via `Range.filter(p).map(f)` chain    | N = 1 000 000                          |
| `binary_trees`   | recursive allocation + GC throughput            | build a balanced tree, then count its nodes                     | depth = 17 (262 143 nodes)             |
| `string_builder` | string runtime + GC under in-flight builder     | append a 45-char fragment N times, finalise to a flat string    | N = 80 000                             |
| `map_iter`       | hash-map entry iteration, per-visit alloc       | 1 000 outer × 1 000 inner `for entry in m` over a 1 000-entry map | 1 M map visits total                 |
| `arr_rw`         | array element get/set, no allocation            | `a[i] = a[i] + 1` over a fixed buffer (open-coded typed load/store) | 1024-elt `i32[]`, 100 000 passes     |
| `arr_push`       | array append + grow path + young-arena GC churn | build a fresh `i32[]` by `push`, discard, repeat                | 20 M pushes (200 × 100 000)            |
| `str_concat`     | string `+` concat (Buffer-backed, off-runtime)  | grow a 13-byte string by repeated `s = s + "…"`                 | 300 000 iterations                     |
| `interp`         | `${}` interpolation + integer formatting        | format three ints into one string via `${}`                     | 200 000 iterations                     |

Every program prints a one-line checksum so cross-language equivalence is verifiable.

## Implementations

| stack             | entry-point                                       | how it runs                                                |
|-------------------|---------------------------------------------------|------------------------------------------------------------|
| `vader-native`    | `bench/<name>/<name>.vader` → native binary       | `./build/vader build --target=native --release`, then exec |
| `bun-ts`          | `bench/<name>/<name>.ts`                          | direct `bun bench/<name>/<name>.ts`                        |
| `go`              | `bench/<name>/<name>.go` → native binary          | `go build`, then exec                                      |
| `java`            | `bench/<name>/<name>.java` → `<name>.class`       | `javac --release 25 -d bench/<name>`, then `java -cp bench/<name> <Name>` |

The harness times each invocation with `performance.now()` around a `spawnSync`, so what's measured is the **process wall-clock** — startup, runtime initialization, kernel, I/O, teardown.

A fifth implementation, `vader-vm` (`./build/vader run bench/<name>/<name>.vader`), exists in the codebase but is commented out in `bench/run.ts`'s `IMPLS` list. Reason : each VM invocation pays 2-30 s for the Vader parse + typecheck + lower + bytecode pipeline, which dwarfs the actual VM loop. Including it inflates the total bench wall time from ~6 s to ~5 min without surfacing a regression signal that `vader-native` doesn't already cover. Uncomment the entry when a change targets the VM exec path specifically (e.g. once the bytecode-on-disk cache lands and the compile phase is amortised).

Java is precompiled in the build phase rather than run via the single-source-file launcher (`java bench/<name>/<name>.java`). The launcher adds ~200 ms per invocation for in-memory source parsing + class load on top of the JVM cold-start floor ; precompiling drops Java's per-run cost to ~30-50 ms which is the JVM startup + cold JIT alone. For steady-state Java throughput (a long-running JVM that has warmed its JIT), Java would land much closer to Go and Vader native ; the bench measures cold script invocations on purpose.

### Build parallelism

Every implementation that needs a build step (`vader-native` via the Vader compiler + `cc`, `go` via `go build`, `java` via `javac`) is batched up-front in a single `Promise.all` so independent compilers use every available core — an implementation with no source for a given workload is dropped before this step. Building every workload's compiled implementations finishes in 1-3 s instead of the 15+ s a serial compile would take.

**Measurements stay strictly serial.** Running two CPU-bound benchmarks concurrently on the same machine corrupts the signal — they steal cycles from each other, contend on L3 + memory bandwidth, and on Apple Silicon shuffle between P/E cores. Wall-clock numbers from parallel measurements aren't comparable across runs, which is exactly the opposite of what a regression-detection bench needs.

## Running the bench

```sh
bun run bench                    # measure + compare to baseline
bun run bench -- --update        # rewrite baseline with current measurements
bun run bench -- --runs=5        # default is 3 (timed) + 1 warmup
bun run bench -- --workload=primes  # narrow to a single workload
```

Exit status is non-zero if any (workload, implementation) `min(samples)` regresses by more than **15 %** against `bench/baseline.json`, or if any implementation's checksum diverges from its committed baseline.

Regression detection skips samples whose baseline is faster than **5 ms** — OS scheduling noise routinely adds ±1 ms, which exceeds 15 % of a 5 ms sample, so flagging those would just create false positives. Those rows still appear in the output table.

We compare on `min(samples)` rather than the median because these workloads finish in tens of milliseconds — JIT warm-up and GC pauses routinely push the median 15 %+ above the steady-state cost, but the best sample stays close to the actual CPU path.

## Baseline (committed)

Captured 2026-06-20 on a 2026 Apple Silicon laptop, `bun run bench -- --runs=7 --update`:

| workload         | vader-native | bun-ts    | go         | java     |
|------------------|--------------|-----------|------------|----------|
| `mandelbrot`     |  15.8 ms ★   |  24.8 ms  |  18.8 ms   | 49.3 ms  |
| `primes`         |  24.5 ms ★   |  41.5 ms  |  25.1 ms   | 59.0 ms  |
| `iter_chain`     |   1.6 ms ★   |  36.6 ms  |   2.6 ms   | 38.8 ms  |
| `binary_trees`   |   5.9 ms ★   |  13.1 ms  |   7.5 ms   | 39.3 ms  |
| `string_builder` |   9.1 ms     |   8.9 ms  |   5.4 ms ★ | 36.6 ms  |
| `map_iter`       |   3.2 ms ★   |  34.6 ms  |   9.1 ms   | 43.2 ms  |
| `arr_rw`         | 121.6 ms     |  84.1 ms  |  37.2 ms ★ | 89.4 ms  |
| `arr_push`       |  67.7 ms     |  50.2 ms  |  32.6 ms ★ | 56.4 ms  |
| `str_concat`     |  62.1 ms     |   9.1 ms ★|  12.3 ms   | 51.9 ms  |
| `interp`         | 128.0 ms     |  19.9 ms  |  19.2 ms ★ | 49.0 ms  |

★ = fastest on the workload.
Reading the table :

- **`mandelbrot`** — Vader native (15.8 ms) beats Go (18.8 ms) and Bun-TS (24.8 ms). After the for-over-integer-range counter-loop lowering (commit `1e268fd3`), the float kernel hits a state where clang `-O3` is doing essentially the same work as `gc`, with a marginal lead from FMA-free arithmetic on this specific kernel.
- **`primes`** — Vader native (24.5 ms) edges ahead of Go (25.1 ms) and beats Bun (41.5 ms). Trial division is mostly integer modulo, which both AOT compilers turn into the same `udiv` / `msub` sequence ; the small lead is startup, and Bun's JIT pays an extra dispatch.
- **`iter_chain`** — Vader native is ~1.6 × faster than Go's direct loop (1.6 ms vs 2.6 ms) after the iterator-chain fusion landed. The lowerer detects `for x in (0..<N).filter(is_even).map(square_i64) { … }` — fluent UFCS chain or struct-lit chain, both bottom out at a `RangeExpr` — and collapses the three-level lazy chain into a single counter loop with inlined `pred` and `f` calls. Same pattern Rust's iter combinators rely on. Without that, the chain is 7-8 × slower (one `Yielded(T)` heap box + one vtable dispatch per layer per iteration). Bun-TS's generator chain (~40 ms) and Java's Stream API (~44 ms) sit on the unfused side, showing what we save.
- **`binary_trees`** — Vader native (5.9 ms) is ahead of Go (7.5 ms) and ~2.2 × faster than Bun-TS (13.1 ms). After the nullable-ref inline representation landed, `Node` dropped from 72 B → 40 B (-44 %) and GC pressure dropped accordingly, keeping Vader level with — and slightly ahead of — `gc`'s tracing collector on this allocation-heavy workload.
- **`string_builder`** — Go (5.4 ms) leads, with Bun-TS (8.9 ms) now edging Vader native (9.1 ms) and Java (36.6 ms) trailing. The Vader `StringBuilder` stores fragment refs in a `string[]` and flushes once via the `Display::to_string` intrinsic — no per-iter copy — but Go's `strings.Builder` writes straight into a `[]byte` and amortises the grow over a single buffer, which beats the array-of-refs approach when the fragments are short and many. The gap is two final-pass copies and the GC tracing cost of the ref array.
- **`map_iter`** — Vader native (3.2 ms) now leads Go (9.1 ms) by ~2.8 ×, and crushes Bun-TS (34.6 ms) and Java (43.2 ms). Earlier baselines had Vader behind Go (~23 ms, ~2.8 × slower) ; GC + dispatch optims (`O(log N)` string-mark, midir vtable pruning, lower-pass O(1) symbol lookups) first erased the gap, then the compact-dict `MutableMap` rewrite (2026-06) roughly halved it again (6.5 → 3.2 ms). Go's `for k, v := range m` allocates nothing per visit ; Vader's `for entry in m` desugars via `Into(Iterator(Entry(K, V)))` (cf. `std/collections.vader`). The `Yield(Entry)` wrapper folds into a 0-byte tag at runtime (`VADER_TYPE_KIND_INLINE_REF`) and the `Yield(T) | null` return slot folds to a raw `void*` via B1, so the dispatch is alloc-free and pointer-sized. Bun's `Map[Symbol.iterator]` and Java's `entrySet()` both box per visit.
- **`java`** — most Java rows sit at ~37-60 ms (heavier workloads like `arr_rw` add real compute on top). That floor is JVM startup + class loading + cold JIT — measurable but bounded now that we precompile in the build phase (down from ~230 ms when each invocation also parsed the source). For steady-state Java throughput (long-running JVM, warmed JIT, millions of iterations) Java would catch up to Go ; we're benching cold script invocations on purpose because that's what `java <Class>` looks like in practice.
- **`arr_rw` / `arr_push` / `str_concat` / `interp`** (Target-ABI workloads, added after the original six) — the current Vader weak spots. `arr_rw` 121.6 ms vs Go 37.2 ms, `arr_push` 67.7 vs Go 32.6, `str_concat` 62.1 vs Bun 9.1 / Go 12.3, `interp` 128.0 vs Bun 19.9 / Go 19.2. They exercise the open-coded array load/store, the push/grow + young-arena GC churn, and the off-runtime Buffer-backed string `+` concat / `${}` interpolation paths — where Go's native slices and Bun's JIT'd string ops still pull ahead. Tracked for follow-up profiling.

The `mandelbrot` checksum splits three ways : Bun-TS / Java agree at 5 705 453, Vader-native lands at 5 705 449 (a 4-iteration drift, ~7 boundary pixels where clang's reassociation under `-O3` reorders a `z² + c` term and flips the escape test one iteration earlier), and Go lands at 5 689 008 because `gc` fuses `a*b + c` into a single FMA instruction with one rounding step on arm64. All three are mathematically correct ; only the rounding model differs.

## Adding a workload

1. Write the kernel in `bench/<name>/<name>.vader`. Print a one-line checksum to stdout.
2. Port it to `bench/<name>/<name>.ts`, `bench/<name>/<name>.go`, `bench/<name>/<name>.java` — all colocated in the same directory. Keep the algorithm bit-identical (the harness verifies checksum equality against the committed baseline). A port may be omitted : the harness silently drops any implementation whose source file is absent, so a Vader-only workload still works (its row just shows only the `vader-native` column).
3. Add an entry to `WORKLOADS` in `bench/run.ts`.
4. Add the Vader binary line `bench/<name>/<name>` to `.gitignore` ; the `.c`, Go binary and `.class` artefacts are already covered by the `bench/*/*.c`, `bench/*/*_go`, `bench/*/*.class` globs.
5. Run `bun run bench -- --update` to extend the baseline (baselines are machine-specific — a new workload simply isn't regression-gated until someone records it on the canonical machine).

## Caveats

- The natively-compiled Vader path uses `--release`, which sets `-O3 -DNDEBUG` and post-link `strip`. Compiler is the system `cc` (clang on macOS, gcc on Linux).
- Bun's measurement of process wall-clock includes its own startup (~10 ms on macOS). On a workload that takes 15 ms total, that's a third of the run.
- The VM-path numbers measure `./build/vader run …` end-to-end, including the Vader parse + typecheck + lower + bytecode pipeline. They'll drop substantially once the bytecode-on-disk cache lands (TODO §3.5).
