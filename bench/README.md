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
| `vader-vm`        | `bench/<name>.vader`                         | `bun src/index.ts run` — parses + lowers + bytecode interpreter |
| `vader-native`    | `bench/<name>.vader` → native binary         | `bun src/index.ts build --target=native --release`, then exec |
| `bun-ts`          | `bench/<name>.ts`                            | direct `bun bench/<name>.ts`                          |
| `go`              | `bench/<name>.go` → native binary            | `go build`, then exec                                 |
| `java`            | `bench/<name>.java`                          | `java bench/<name>.java` — single-source-file launcher (Java 11+), no separate `javac` step |

The harness times each invocation with `performance.now()` around a `spawnSync`, so what's measured is the **process wall-clock** — startup, runtime initialization, kernel, I/O, teardown. For the VM path that bundles the entire Vader compile pipeline ; the figure is what a user would see typing `vader run`. For Java the figure includes ~200 ms of JVM startup + class loading + JIT warmup that fires fresh on every invocation ; that's the cost of `java MyFile.java`-style scripting, not steady-state Java throughput.

### Build parallelism

The two implementations that need a build step (`vader-native` via the Vader compiler + `cc`, and `go` via `go build`) are batched up-front in a single `Promise.all` so they use every available core. Compiling all 5 workloads × 2 implementations finishes in 1-3 s instead of the 15+ s a serial compile would take.

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

| workload         | vader-vm     | vader-native | bun-ts  | go      | java     |
|------------------|--------------|--------------|---------|---------|----------|
| `mandelbrot`     | 12 685 ms    | 15.2 ms      | 22.5 ms | 17.5 ms | 241.8 ms |
| `primes`         | 27 058 ms    | 23.4 ms      | 40.2 ms | 24.0 ms | 246.8 ms |
| `iter_chain`     |  2 475 ms    | 29.8 ms      | 35.3 ms |  3.7 ms | 235.1 ms |
| `binary_trees`   |    514 ms    | 21.2 ms      | 11.9 ms |  7.4 ms | 236.0 ms |
| `string_builder` |     95 ms    |  4.1 ms      |  9.8 ms |  4.9 ms | 226.8 ms |

Reading the table :

- **VM vs native** — the VM path is 100-1000 × slower than native. Most of that wall-clock is the Vader compile pipeline (parse → typecheck → lower → bytecode), not the VM loop itself. The smaller workloads (`string_builder` 95 ms) make this visible : even with N=50 000 the compile dominates the VM run.
- **`mandelbrot`** — after the for-over-integer-range counter-loop lowering landed (commit `1e268fd3`), Vader native beats Bun-TS (1.5 ×) and is at parity with Go (within noise). The float kernel reaches a state where clang `-O3` is doing essentially the same work as `gc`.
- **`primes`** — Vader native ties Go (within noise). Trial division is mostly integer modulo, which both compilers turn into the same `udiv` / `msub` sequence.
- **`iter_chain`** — Vader native is **8 × slower than Go's direct loop**. Each chain step allocates a `Yielded(T)` union per yielded item — the workload that justifies the deferred "inline small tagged unions" perf piste in `TODO.md §3.5`. Bun-TS's generator chain (35 ms) lands in the same zone as Vader, confirming the cost is the lazy-chain pattern, not Vader specifically.
- **`binary_trees`** — Vader native is **3 × slower than Go**. The gap is GC overhead : Cheney semi-space copying + write barriers + per-fn `gc_frame` push/pop. Reducing this is the target of any future generational tuning.
- **`string_builder`** — Vader native (4.1 ms) wins outright. The Vader `StringBuilder` stores fragment refs in a `string[]` and flushes once via the `Display::to_string` intrinsic — no per-iter copy. Go's `strings.Builder` and Bun's `[].join("")` both pay extra copies.
- **`java`** — every Java row sits at 225-247 ms, regardless of workload. That floor is JVM startup + class loading + cold JIT for the single-source-file launcher. For a one-shot run it dominates the actual computation ; for steady-state throughput (a long-running JVM warming its JIT over millions of iterations) Java would land much closer to Go and Vader native. We're benching cold script invocations on purpose — that's what a user types `java foo.java` to do.

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
