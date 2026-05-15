# Vader benchmarks

Five workloads measured across four implementations of each. The set spans float CPU, integer CPU, iterator chains, GC throughput, and string-runtime throughput so a perf change in any of those subsystems trips a regression.

| workload         | exercises                                       | algorithm                                                       | scale                                  |
|------------------|-------------------------------------------------|-----------------------------------------------------------------|----------------------------------------|
| `mandelbrot`     | f64 arithmetic, tight loop                      | per-pixel iteration of `z := z² + c` until escape or cap        | 240 × 180 grid, max 500 iter per pixel |
| `primes`         | i32 / i64 arithmetic, modulo                    | count primes ≤ N by trial division up to `√n`                   | N = 1 000 000                          |
| `iter_chain`     | lazy iter dispatch, per-iter union allocation   | Σ x² for even x in [0, N) via `Range.filter(p).map(f)` chain    | N = 1 000 000                          |
| `binary_trees`   | recursive allocation + GC throughput            | build a balanced tree, then count its nodes                     | depth = 17 (262 143 nodes)             |
| `string_builder` | string runtime + GC under in-flight builder     | append a 45-char fragment N times, finalise to a flat string    | N = 80 000                             |
| `map_iter`       | hash-map entry iteration, per-visit alloc       | 1 000 outer × 1 000 inner `for entry in m` over a 1 000-entry map | 1 M map visits total                 |

Every program prints a one-line checksum so cross-language equivalence is verifiable.

## Implementations

| stack             | entry-point                                  | how it runs                                          |
|-------------------|----------------------------------------------|------------------------------------------------------|
| `vader-native`    | `bench/<name>.vader` → native binary         | `bun src/index.ts build --target=native --release`, then exec |
| `bun-ts`          | `bench/<name>.ts`                            | direct `bun bench/<name>.ts`                          |
| `go`              | `bench/<name>.go` → native binary            | `go build`, then exec                                 |
| `java`            | `bench/<name>.java` → `bench/<name>.class`   | `javac --release 25`, then `java -cp bench <Name>`    |

The harness times each invocation with `performance.now()` around a `spawnSync`, so what's measured is the **process wall-clock** — startup, runtime initialization, kernel, I/O, teardown.

A fifth implementation, `vader-vm` (`bun src/index.ts run bench/<name>.vader`), exists in the codebase but is commented out in `bench/run.ts`'s `IMPLS` list. Reason : each VM invocation pays 2-30 s for the Vader parse + typecheck + lower + bytecode pipeline, which dwarfs the actual VM loop. Including it inflates the total bench wall time from ~6 s to ~5 min without surfacing a regression signal that `vader-native` doesn't already cover. Uncomment the entry when a change targets the VM exec path specifically (e.g. once the bytecode-on-disk cache lands and the compile phase is amortised).

Java is precompiled in the build phase rather than run via the single-source-file launcher (`java bench/<name>.java`). The launcher adds ~200 ms per invocation for in-memory source parsing + class load on top of the JVM cold-start floor ; precompiling drops Java's per-run cost to ~30-50 ms which is the JVM startup + cold JIT alone. For steady-state Java throughput (a long-running JVM that has warmed its JIT), Java would land much closer to Go and Vader native ; the bench measures cold script invocations on purpose.

### Build parallelism

Every implementation that needs a build step (`vader-native` via the Vader compiler + `cc`, `go` via `go build`, `java` via `javac`) is batched up-front in a single `Promise.all` so independent compilers use every available core. Building all 5 workloads × 3 implementations finishes in 1-3 s instead of the 15+ s a serial compile would take.

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

Captured on a 2026 Apple Silicon laptop, `bun bench/run.ts --runs=5 --update`:

| workload         | vader-native | bun-ts  | go      | java    |
|------------------|--------------|---------|---------|---------|
| `mandelbrot`     | 15.0 ms      | 22.1 ms | 17.5 ms | 44.5 ms |
| `primes`         | 23.0 ms      | 37.6 ms | 22.9 ms | 53.9 ms |
| `iter_chain`     |  1.8 ms      | 33.6 ms |  2.7 ms | 35.1 ms |
| `binary_trees`   | 13.6 ms      | 11.3 ms |  7.1 ms | 31.6 ms |
| `string_builder` |  3.4 ms      |  8.6 ms |  5.1 ms | 33.6 ms |
| `map_iter`       | 29.1 ms      | 30.6 ms |  7.9 ms | 39.8 ms |

Reading the table :

- **`mandelbrot`** — Vader native (15 ms) beats Go (17 ms) and Bun-TS (23 ms). After the for-over-integer-range counter-loop lowering (commit `1e268fd3`), the float kernel hits a state where clang `-O3` is doing essentially the same work as `gc`, with a marginal lead from FMA-free arithmetic on this specific kernel.
- **`primes`** — Vader native (23 ms) ties Go (23 ms) and beats Bun (38 ms). Trial division is mostly integer modulo, which both AOT compilers turn into the same `udiv` / `msub` sequence ; Bun's JIT pays an extra dispatch.
- **`iter_chain`** — Vader native is ~1.6 × faster than Go's direct loop (1.8 ms vs 2.9 ms) after the iterator-chain fusion landed. The lowerer detects `for x in (0..<N).filter(is_even).map(square_i64) { … }` — fluent UFCS chain or struct-lit chain, both bottom out at a `RangeExpr` — and collapses the three-level lazy chain into a single counter loop with inlined `pred` and `f` calls. Same pattern Rust's iter combinators rely on. Without that, the chain is 7-8 × slower (one `Yielded(T)` heap box + one vtable dispatch per layer per iteration). Bun-TS's generator chain (34 ms) and Java's Stream API (35 ms) sit on the unfused side, showing what we save.
- **`binary_trees`** — Vader native (14 ms) lands within noise of Bun-TS (11 ms) and ~1.7 × Go (8 ms). After the nullable-ref inline representation landed, `Node` dropped from 72 B → 40 B (-44 %) and the GC pressure dropped accordingly. Remaining gap vs Go is in the recursion + match dispatch.
- **`string_builder`** — Vader native (3.3 ms) wins outright. The Vader `StringBuilder` stores fragment refs in a `string[]` and flushes once via the `Display::to_string` intrinsic — no per-iter copy. Go's `strings.Builder` and Bun's `[].join("")` both pay extra copies.
- **`map_iter`** — Vader native (29 ms) lags Go (8 ms) by ~3.7 × on this workload, ties Bun-TS (31 ms), beats Java (40 ms). Go's `for k, v := range m` allocates nothing per visit ; Vader's `for entry in m` desugars via `Into(Iterator(Entry(K, V)))` (cf. `std/collections.vader`), so every visit heap-allocates a `Yielded(Entry(K, V))` and a fresh `Entry` payload — 1 M boxed allocs through the Cheney semi-space dominates the runtime. Bun's `Map[Symbol.iterator]` allocates the same shape ; Java's `entrySet()` boxes `Integer` keys/values on top of materialising `Map.Entry`. Lifting Vader to Go-class on this path needs either (a) iterator-driven enum-tag dispatch that the C emit recognises as a stack-allocated tag (no heap), or (b) a `MapIterator.next()` inliner that fuses the `Yielded` construction with the consumer's `is Yielded as y -> { … }` arm. Both deferred ; see TODO §3 GC perf.
- **`java`** — every Java row sits at 35-57 ms regardless of workload. That floor is JVM startup + class loading + cold JIT — measurable but bounded now that we precompile in the build phase (down from ~230 ms when each invocation also parsed the source). For steady-state Java throughput (long-running JVM, warmed JIT, millions of iterations) Java would catch up to Go ; we're benching cold script invocations on purpose because that's what `java <Class>` looks like in practice.

The `mandelbrot` checksum diverges by ~16 k iterations between the Go peer and the C/Vader/TS peers, because Go fuses `a*b + c` into a single FMA instruction with one rounding step on arm64. Both results are mathematically correct ; only the rounding model differs.

## Known runtime limits surfaced by the bench

These aren't bench bugs ; they're real Vader limits that constrain workload sizing.

- **`bool[]` GC trap on the sieve**. The original `primes` design used Sieve of Eratosthenes (matching `examples/primes.vader`). Vader's `bool[]` stores every element as a 16-byte `vader_box_t`, so a 10 M-element sieve allocates 160 MB and exceeds the 4 MB young semi-space. Trial division sidesteps the array entirely. Follow-up : primitive-array storage + `Array.new(size)` constructor in stdlib.
- **`StringBuilder` `parts` array doubling caps at N ≈ 131 k entries**. Past that the doubling allocates > 4 MB in one shot and trips the young semi-space cap (the 4 MB single-alloc ceiling). The final `to_string()` is its own 4 MB cap : the joined output must fit in young at once. With a 45-char fragment the bench at N = 80 000 produces a 3.6 MB string — comfortably under both caps.
- **`vader_array_push` lost one entry at the 65 k → 131 k doubling step** (fixed 2026-05-14, commit `aecb9ce2`). The grow path triggered back-to-back minor + major GC, and after the second swap the original `a` address was recycled by the fresh-buf allocation that immediately followed — `vader_array_resolve` then walked zero steps because the forward pointer was overwritten. Fix : box `a` into a local `vader_box_t` rooted on the shadow stack across `vader_array_buf_alloc` ; the GC's `scan_box` re-updates the box's `payload.obj` through every cycle, no forward-chain walk needed. The bench was capped at N = 50 000 to dodge the bug ; now it runs at N = 80 000.

## Adding a workload

1. Write the kernel in `bench/<name>.vader`. Print a one-line checksum to stdout.
2. Port it to `bench/<name>.ts` and `bench/<name>.go`. Keep the algorithm bit-identical (the harness verifies checksum equality against the committed baseline).
3. Add an entry to `WORKLOADS` in `bench/run.ts`.
4. Add the artefacts (`bench/<name>`, `bench/<name>.c`, `bench/<name>_go`) to `.gitignore`.
5. Run `bun run bench -- --update` to extend the baseline.

## Caveats

- The natively-compiled Vader path uses `--release`, which sets `-O3 -DNDEBUG` and post-link `strip`. Compiler is the system `cc` (clang on macOS, gcc on Linux).
- Bun's measurement of process wall-clock includes its own startup (~10 ms on macOS). On a workload that takes 15 ms total, that's a third of the run.
- The VM-path numbers measure `bun src/index.ts run …` end-to-end, including TypeScript parse and stdlib re-typecheck. They'll drop substantially once the bytecode-on-disk cache lands (TODO §3.5).
