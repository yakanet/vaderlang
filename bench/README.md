# Vader benchmarks

Two CPU-bound workloads measured across four implementations of each:

| workload     | algorithm                                                    | scale                                 |
|--------------|--------------------------------------------------------------|---------------------------------------|
| `mandelbrot` | per-pixel iteration of `z := z² + c` until escape or cap     | 240 × 180 grid, max 500 iter per pixel|
| `primes`     | count primes ≤ N by trial division up to `√n`                | N = 1 000 000                         |

Both programs print a one-line checksum so cross-language equivalence is verifiable. Both are sized so the natively-compiled Vader binary runs in 40-70 ms — long enough for a 10 % regression threshold to clear scheduler / GC noise, short enough that the full bench (4 implementations × 2 workloads × 1 warmup + 3 measured runs) finishes in about three minutes on a 2026 Apple laptop.

## Implementations

| stack             | entry-point                                  | how it runs                                          |
|-------------------|----------------------------------------------|------------------------------------------------------|
| `vader-vm`        | `bench/<name>.vader`                         | `bun src/index.ts run` — parses + lowers + bytecode interpreter |
| `vader-native`    | `bench/<name>.vader` → native binary         | `bun src/index.ts build --target=native --release`, then exec |
| `bun-ts`          | `bench/<name>.ts`                            | direct `bun bench/<name>.ts`                          |
| `go`              | `bench/<name>.go` → native binary            | `go build`, then exec                                 |

The harness times each invocation with `performance.now()` around a `spawnSync`, so what's measured is the **process wall-clock** — startup, runtime initialization, kernel, I/O, teardown. For the VM path that bundles the entire Vader compile pipeline ; the figure is what a user would see typing `vader run`.

## Running the bench

```sh
bun run bench                    # measure + compare to baseline
bun run bench -- --update        # rewrite baseline with current measurements
bun run bench -- --runs=5        # default is 3 (timed) + 1 warmup
bun run bench -- --workload=primes  # narrow to a single workload
```

Exit status is non-zero if any (workload, implementation) `min(samples)` regresses by more than **10 %** against `bench/baseline.json`, or if any implementation's checksum diverges from its committed baseline. Use that in CI to catch perf changes without false positives from scheduler noise.

We compare on `min(samples)` rather than the median because these workloads finish in tens of milliseconds — JIT warm-up and GC pauses routinely push the median 10 %+ above the steady-state cost, but the best sample stays close to the actual CPU path.

## Baseline (committed)

Captured on a 2026 Apple Silicon laptop, `bun bench/run.ts --runs=3 --update`:

| workload     | vader-vm     | vader-native | bun-ts  | go      |
|--------------|--------------|--------------|---------|---------|
| `mandelbrot` | 18 788 ms    | 65.3 ms      | 23.4 ms | 18.1 ms |
| `primes`     | 29 423 ms    | 41.1 ms      | 41.1 ms | 23.9 ms |

Reading the table :

- The VM path is 200-400 × slower than native — expected for a stack-machine bytecode interpreter implemented in TypeScript. Most of that wall-clock is the Vader compile pipeline (parse → typecheck → lower → bytecode), not the VM loop itself.
- Vader native vs Bun-TS : Bun's JIT compiles tight loops to near-native code and wins on `mandelbrot` (2.8 ×), ties on `primes`. The trial-division kernel is mostly integer-modulo, which both backends compile to a `udiv` / `msub` pair ; the float-heavy `mandelbrot` exposes Vader's lack of vectorization and loop-strength reduction.
- Go vs Vader native : Go wins by 3.6 × on mandelbrot and 1.7 × on primes. Expected — `gc` does FMA fusion, escape analysis with inlining, and arm64-specific codegen tuning, none of which Vader currently does.

The `mandelbrot` checksum diverges by ~16 k iterations between the Go peer and the C/Vader/TS peers, because Go fuses `a*b + c` into a single FMA instruction with one rounding step on arm64. Both results are mathematically correct ; only the rounding model differs.

## Adding a workload

1. Write the kernel in `bench/<name>.vader`. Print a one-line checksum to stdout.
2. Port it to `bench/<name>.ts` and `bench/<name>.go`. Keep the algorithm bit-identical.
3. Add an entry to `WORKLOADS` in `bench/run.ts`.
4. Run `bun run bench -- --update` to extend the baseline.

## Caveats

- The natively-compiled Vader path uses `--release`, which strips debug info and enables `cc`'s `-O2`. The C compiler doing the heavy lifting here is the system `cc` (clang on macOS, gcc on Linux).
- Bun's measurement of process wall-clock includes its own startup (~10 ms on macOS). On a workload that takes 25 ms total, that's a third of the run.
- These workloads are CPU-only, no I/O beyond the final `println` of the checksum. They don't exercise allocation, GC, the string runtime, or `MutableMap`. A bench that does is on the roadmap.
