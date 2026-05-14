# Vader benchmarks

Five workloads measured across four implementations of each. The set spans float CPU, integer CPU, iterator chains, GC throughput, and string-runtime throughput so a perf change in any of those subsystems trips a regression.

| workload         | exercises                                       | algorithm                                                       | scale                                  |
|------------------|-------------------------------------------------|-----------------------------------------------------------------|----------------------------------------|
| `mandelbrot`     | f64 arithmetic, tight loop                      | per-pixel iteration of `z := z² + c` until escape or cap        | 240 × 180 grid, max 500 iter per pixel |
| `primes`         | i32 / i64 arithmetic, modulo                    | count primes ≤ N by trial division up to `√n`                   | N = 1 000 000                          |
| `iter_chain`     | lazy iter dispatch, per-iter union allocation   | Σ x² for even x in [0, N) via `MapIterator` ∘ `FilterIterator` ∘ `Range` | N = 1 000 000                  |
| `binary_trees`   | recursive allocation + GC throughput            | build a balanced tree, then count its nodes                     | depth = 17 (262 143 nodes)             |
| `string_builder` | string runtime + GC under in-flight builder     | append a 45-char fragment N times, finalise to a flat string    | N = 50 000                             |

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
| `mandelbrot`     | 16.4 ms      | 25.4 ms | 18.7 ms | 45.5 ms |
| `primes`         | 22.5 ms      | 39.1 ms | 23.7 ms | 57.2 ms |
| `iter_chain`     |  1.9 ms      | 34.8 ms |  4.2 ms | 35.8 ms |
| `binary_trees`   | 14.9 ms      | 12.6 ms |  7.4 ms | 36.9 ms |
| `string_builder` |  3.3 ms      | 10.9 ms |  4.9 ms | 37.9 ms |

Reading the table :

- **`mandelbrot`** — Vader native (16 ms) beats Go (19 ms) and Bun-TS (25 ms). After the for-over-integer-range counter-loop lowering (commit `1e268fd3`), the float kernel hits a state where clang `-O3` is doing essentially the same work as `gc`, with a marginal lead from FMA-free arithmetic on this specific kernel.
- **`primes`** — Vader native (23 ms) ties Go (24 ms) and beats Bun (39 ms). Trial division is mostly integer modulo, which both AOT compilers turn into the same `udiv` / `msub` sequence ; Bun's JIT pays an extra dispatch.
- **`iter_chain`** — Vader native is **2 × faster than Go's direct loop** (1.9 ms vs 4.2 ms) after the iterator-chain fusion landed. The lowerer detects `for x in (MapIterator { source: FilterIterator { source: <RangeExpr>, … }, … }) { … }` and collapses the three-level lazy chain into a single counter loop with inlined `pred` and `f` calls — same pattern Rust's iter combinators rely on. Without that, the chain is 7-8 × slower (one `Yielded(T)` heap box + one vtable dispatch per layer per iteration). Bun-TS's generator chain (35 ms) and Java's Stream API (36 ms) sit on the unfused side, showing what we save.
- **`binary_trees`** — Vader native (15 ms) lands within noise of Bun-TS (13 ms) and 2 × Go (7.4 ms). After the nullable-ref inline representation landed, `Node` dropped from 72 B → 40 B (-44 %) and the GC pressure dropped accordingly. Remaining gap vs Go is in the recursion + match dispatch.
- **`string_builder`** — Vader native (3.3 ms) wins outright. The Vader `StringBuilder` stores fragment refs in a `string[]` and flushes once via the `Display::to_string` intrinsic — no per-iter copy. Go's `strings.Builder` and Bun's `[].join("")` both pay extra copies.
- **`java`** — every Java row sits at 35-57 ms regardless of workload. That floor is JVM startup + class loading + cold JIT — measurable but bounded now that we precompile in the build phase (down from ~230 ms when each invocation also parsed the source). For steady-state Java throughput (long-running JVM, warmed JIT, millions of iterations) Java would catch up to Go ; we're benching cold script invocations on purpose because that's what `java <Class>` looks like in practice.

The `mandelbrot` checksum diverges by ~16 k iterations between the Go peer and the C/Vader/TS peers, because Go fuses `a*b + c` into a single FMA instruction with one rounding step on arm64. Both results are mathematically correct ; only the rounding model differs.

## Known runtime limits surfaced by the bench

These aren't bench bugs ; they're real Vader limits that constrain workload sizing.

- **`bool[]` GC trap on the sieve**. The original `primes` design used Sieve of Eratosthenes (matching `examples/primes.vader`). Vader's `bool[]` stores every element as a 16-byte `vader_box_t`, so a 10 M-element sieve allocates 160 MB and exceeds the 4 MB young semi-space. Trial division sidesteps the array entirely. Follow-up : primitive-array storage + `Array.new(size)` constructor in stdlib.
- **`StringBuilder` `parts` array doubling caps at N ≈ 65 k entries**. Past that the doubling allocates > 4 MB in one shot and trips the young semi-space cap. `string_builder` is sized just under the cap at N = 50 000.
- **`StringBuilder` drops one fragment at N ≈ 65 536**. Pre-existing bug — reproduces under both the for-in-range counter loop and a hand-written `for i < N` ; output is short by exactly one fragment. Tracked separately ; not phase-A regression. Sized below the trigger for now.

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
