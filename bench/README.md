# Vader benchmarks

Fifteen cross-language workloads spanning float CPU, integer CPU, iterator chains, non-tail recursion / call overhead, GC throughput, hash-map build + probe, string-runtime throughput, byte scanning, sorting, and array accessors — so a perf change in any of those subsystems trips a regression.

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
| `arr_set`        | indexed r-m-w bounded by `a.len()` (BCE)        | same as `arr_rw` but `for i in 0..<a.len()` — BCE hoists the buf resolve | 1024-elt `i32[]`, 100 000 passes  |
| `arr_push`       | array append + grow path + young-arena GC churn | build a fresh `i32[]` by `push`, discard, repeat                | 20 M pushes (200 × 100 000)            |
| `str_concat`     | string `+` concat (Buffer-backed, off-runtime)  | grow a 13-byte string by repeated `s = s + "…"`                 | 300 000 iterations                     |
| `interp`         | `${}` interpolation + integer formatting        | format three ints into one string via `${}`                     | 200 000 iterations                     |
| `hashmap`        | hash-map insert / lookup / delete / grow        | 8 rounds of build + probe over N distinct keys `(i·S) mod K`     | 100 000 keys × 8 rounds                |
| `ackermann`      | non-tail recursion, raw call overhead           | Σ `A(3, n)` for n in [0, 9] via the classic double recursion    | deepest `A(3, 9)`, ~2 k stack depth    |
| `wordcount`      | `u8[]` byte scan + whitespace state machine     | count words / lines in a fixed ASCII buffer, rescanned          | 1.76 MB buffer × 15 passes             |
| `quicksort`      | array get/set, swaps, bounded recursion         | in-place median-of-three quicksort of a scrambled `i32[]`       | 1 000 000 elements                     |

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
bun run bench -- --runs=5         # override the default of 10 timed runs (+ 1 warmup)
bun run bench -- --workload=primes  # narrow to a single workload
```

Exit status is non-zero if any (workload, implementation) `min(samples)` regresses by more than **15 %** against `bench/baseline.json`, or if any implementation's checksum diverges from its committed baseline.

Regression detection skips samples whose baseline is faster than **5 ms** — OS scheduling noise routinely adds ±1 ms, which exceeds 15 % of a 5 ms sample, so flagging those would just create false positives. Those rows still appear in the output table.

We compare on `min(samples)` rather than the median because these workloads finish in tens of milliseconds — JIT warm-up and GC pauses routinely push the median 15 %+ above the steady-state cost, but the best sample stays close to the actual CPU path.

## Baseline (committed)

Captured 2026-07-19 on a 2026 Apple Silicon laptop, `bun run bench -- --update` (10 timed runs), after the BCE resolve-hoist landing — the new `arr_set` workload (`for i in 0..<a.len()`) hoists the per-iteration buffer-forward resolve, landing at 9.3 ms (3.9× faster than Go) vs its un-hoisted `arr_rw` twin's 57.5 ms:

| workload         | vader-native | bun-ts    | go         | java     |
|------------------|--------------|-----------|------------|----------|
| `mandelbrot`     |  16.2 ms ★   |  25.3 ms  |  18.4 ms   | 48.5 ms  |
| `primes`         |  24.2 ms ★   |  40.5 ms  |  24.6 ms   | 59.1 ms  |
| `iter_chain`     |   1.6 ms ★   |  36.8 ms  |   2.6 ms   | 37.2 ms  |
| `binary_trees`   |   5.5 ms ★   |  11.9 ms  |   7.3 ms   | 33.4 ms  |
| `string_builder` |   7.4 ms     |   9.0 ms  |   5.4 ms ★ | 36.9 ms  |
| `map_iter`       |   3.9 ms ★   |  33.3 ms  |   8.2 ms   | 42.9 ms  |
| `arr_rw`         |  57.5 ms     |  81.3 ms  |  35.8 ms ★ | 86.3 ms  |
| `arr_set`        |   9.3 ms ★   |  78.1 ms  |  35.9 ms   | 57.5 ms  |
| `arr_push`       |  44.2 ms     |  46.9 ms  |  31.7 ms ★ | 52.7 ms  |
| `str_concat`     |  22.8 ms     |   8.3 ms ★|  11.0 ms   | 49.1 ms  |
| `interp`         |  36.5 ms     |  41.7 ms  |  20.5 ms ★ | 55.3 ms  |
| `hashmap`        |  26.1 ms ★   | 113.2 ms  |  43.9 ms   | 85.1 ms  |
| `ackermann`      |  37.6 ms ★   |  41.9 ms  |  39.7 ms   | 53.6 ms  |
| `wordcount`      |  39.5 ms     |  42.2 ms  |  24.5 ms ★ | 56.6 ms  |
| `quicksort`      |  49.2 ms     |  73.5 ms  |  34.4 ms ★ | 80.0 ms  |

Plus one Vader-only compile-time workload (no cross-language column):

| workload         | vader-native   | what it times                                    |
|------------------|----------------|--------------------------------------------------|
| `selfcompile_c`  |  4594 ms       | emit C for the whole compiler (self-host C-emit) |

★ = fastest on the workload.
Reading the table :

- **`mandelbrot`** — Vader native (16.2 ms) beats Go (18.4 ms) and Bun-TS (25.3 ms). After the for-over-integer-range counter-loop lowering (commit `1e268fd3`), the float kernel hits a state where clang `-O3` is doing essentially the same work as `gc`, with a marginal lead from FMA-free arithmetic on this specific kernel.
- **`primes`** — Vader native (24.2 ms) and Go (24.6 ms) run neck-and-neck, both well ahead of Bun (40.5 ms). Trial division is mostly integer modulo, which both AOT compilers turn into the same `udiv` / `msub` sequence ; the sub-millisecond gap (whichever way it tips run to run) is startup noise, and Bun's JIT pays an extra dispatch.
- **`iter_chain`** — Vader native (1.6 ms) beats Go's direct loop (2.6 ms) and crushes the unfused generators — Bun-TS (~37 ms) and Java's Stream API (~37 ms) — by ~23 ×. The lowerer detects `for x in (0..<N).filter(is_even).map(square_i64) { … }` — fluent UFCS chain or struct-lit chain, both bottom out at a `RangeExpr` — and collapses the three-level lazy chain into a single counter loop with the `pred` / `f` calls DEVIRTUALIZED to direct calls, so it stays off the 7-23 × slower unfused path (one `Yielded(T)` heap box + one vtable dispatch per layer per iteration). REGRESSION + FIX (2026-07-16): the `map`/`filter` → `@generator` rewrite (`f2c0fb49f`, bisected) kept the loop fusion but bound the callbacks to fn-value locals called INDIRECTLY through the erased `vader_fn_t` (per-iteration arg boxing + a fn-pointer hop), doubling this to ~4.6 ms. The `devirtualize_fn_refs` lower pass (commit `f231b169b`) restores direct calls — `let f = square_i64 ; … f(x)` and `let f = <lambda> ; … f(x)` are rewritten to call the concrete fn directly — bringing it back to its pre-regression, Go-beating ~2 ms position.
- **`binary_trees`** — Vader native (5.5 ms) is ahead of Go (7.3 ms) and ~2.2 × faster than Bun-TS (11.9 ms). After the nullable-ref inline representation landed, `Node` dropped from 72 B → 40 B (-44 %) and GC pressure dropped accordingly, keeping Vader level with — and slightly ahead of — `gc`'s tracing collector on this allocation-heavy workload.
- **`string_builder`** — Go (5.4 ms) leads, then Vader native (7.4 ms) — ahead of Bun-TS (9.0 ms) after the `StringBuilder` 0/1-part `to_string` fast path landed — with Java (36.9 ms) trailing. The Vader `StringBuilder` stores fragment refs in a `string[]` and flushes once via the `Display::to_string` intrinsic — no per-iter copy — but Go's `strings.Builder` writes straight into a `[]byte` and amortises the grow over a single buffer, which still beats the array-of-refs approach when the fragments are short and many. The remaining gap is two final-pass copies and the GC tracing cost of the ref array.
- **`map_iter`** — Vader native (3.9 ms) leads Go (8.2 ms) by ~2.1 ×, and crushes Bun-TS (33.3 ms) and Java (42.9 ms). Earlier baselines had Vader behind Go (~23 ms, ~2.8 × slower) ; GC + dispatch optims (`O(log N)` string-mark, midir vtable pruning, lower-pass O(1) symbol lookups) first erased the gap, then the compact-dict `MutableMap` rewrite (2026-06) roughly halved it again (6.5 → 3.6 ms). Go's `for k, v := range m` allocates nothing per visit ; Vader's `for entry in m` desugars via `Into(Iterator(Entry(K, V)))` (cf. `std/collections.vader`). The `Yield(Entry)` wrapper folds into a 0-byte tag at runtime (`VADER_TYPE_KIND_INLINE_REF`) and the `Yield(T) | null` return slot folds to a raw `void*` via B1, so the dispatch is alloc-free and pointer-sized. Bun's `Map[Symbol.iterator]` and Java's `entrySet()` both box per visit.
- **`java`** — most Java rows sit at ~33-59 ms (heavier workloads like `arr_rw`, ~86 ms, add real compute on top). That floor is JVM startup + class loading + cold JIT — measurable but bounded now that we precompile in the build phase (down from ~230 ms when each invocation also parsed the source). For steady-state Java throughput (long-running JVM, warmed JIT, millions of iterations) Java would catch up to Go ; we're benching cold script invocations on purpose because that's what `java <Class>` looks like in practice.
- **`arr_rw` / `arr_push` / `str_concat` / `interp`** (Target-ABI workloads, added after the original six) — the Target-ABI paths, now mostly closed. `arr_rw` 57.5 ms vs Go 35.8 (1.6 ×, was 3.2 ×), `arr_push` 44.2 vs Go 31.7 (1.4 ×, was 2.0 ×), `str_concat` 22.8 vs Bun 8.3 / Go 11.0 (2.7 ×), `interp` 36.5 vs Go 20.5 (1.8 ×) — Vader now edges out Bun (41.7) on `interp` (the workload gained an emoji + codepoint-count checksum, so it is not comparable to the pre-2026-07 `interp` numbers). They exercise the open-coded array load/store, the push/grow + young-arena GC churn, and the off-runtime Buffer-backed string `+` concat / `${}` interpolation paths. **`arr_rw`** dropped from a midir intra-block array-load-forward pass (drops the redundant re-read in `a[i] = a[i] + 1`, commit `6fc1def1`) plus a native c_emit resolve-CSE that shares the buf-forward walk across accesses in one straight-line region (`0af7deb9`). **`interp`** dropped earlier because a `${int}` now writes its digits straight into one exact-sized byte buffer instead of minting a throwaway interned string per part (`2e294f5c`). `str_concat` closed after the fixed-arity `concatN` `+`-chain lowering. **`arr_push`** dropped 66 → 45 ms (2.0 × → 1.4 ×) once `push` on a statically-primitive array stopped boxing + calling the generic runtime append and started emitting a typed `vader_array_push_<kind>` inline (typed store at the tail, no box / kind dispatch / write barrier) — one helper per primitive width, full parity with the indexed-store path. The residual gap to Go is now the two-level `array_t → buf_t` representation (a double deref plus a separate `buf->length` store per push), not the append itself ; it still keeps the `-falign-functions=64` cache-line fix (commit `7a96cc48`) that undid a layout-only regression. `str_concat` is the remaining open Target-ABI gap — it still trails Bun's JIT'd string ops.
- **`arr_set`** — the same read-modify-write as `arr_rw`, but bounded by `for i in 0..<a.len()` instead of a separate `n`. That lets the lowerer prove `i ∈ [0, len(a))` and — since the body neither allocates nor rebinds `a` — HOIST a's buffer-forward resolve (`while (buf->forward)`) out of the loop into the preheader (BCE resolve-hoist, `vader/lower/lower_for_in.vader`). The per-iteration resolve was a vectorisation barrier — clang couldn't prove `a->buf` loop-invariant — so hoisting it drops the loop from 57.5 ms (`arr_rw`, un-hoisted) to **9.3 ms, 3.9 × faster than Go** (which keeps its own per-access slice bounds checks). Vader's bounds checks *stay* (measured near-free once the resolve is hoisted, and they still catch any residual OOB) ; the whole win is the resolve hoist. `arr_rw`'s `for i in 0..<n` form doesn't qualify — proving `n == a.len()` would need value-range analysis (deferred). A body that allocates or rebinds `a` (a GC could move the buffer) disables the hoist.
- **`hashmap`** — Vader native (26.1 ms) is the *fastest*, ahead of Go's built-in `map` (43.9 ms) and ~4 × faster than Bun (113.2 ms) — a touch quicker since the compact-dict's `i32`/`usize` key + value `push` went typed. The compact-dict `MutableMap` (open-addressed `i32` index over dense entry arrays, cf. `map_iter`'s note) absorbs the insert / lookup / delete / grow churn with no per-op allocation ; this is the build-and-probe counterpart to `map_iter`'s pure iteration, and the shape a compiler's symbol table / interner actually sees. All four maps grow from empty — no port pre-sizes — so the row measures the rehash / grow path it advertises, not just steady-state probing. Keys are `(i·STRIDE) mod KEYSPACE` with STRIDE coprime to the prime KEYSPACE, so all 100 000 keys are distinct and the set is identical across ports.
- **`ackermann`** — pure non-tail recursion, zero allocation, isolating the raw call path (prologue / epilogue, argument passing, direct-call dispatch) the way `binary_trees` (allocation-dominated) can't. Vader native (37.6 ms) lands level with Go (39.7 ms) and Bun (41.9 ms), ahead of Java's JVM-startup floor (53.6 ms). At this size a large share of the wall-clock is process startup (Vader's is ~0), so like `iter_chain` this row stays startup-sensitive ; the *pure* per-call overhead only separates the field at far larger n — `A(3,11)` is ~10 × the calls, and there Vader native is the **slowest** (a real gap), but that would blow the suite's tens-of-ms budget, so we size down to `A(3,9)`.
- **`wordcount`** — byte-scan / tokenize, the inverse of the string-*building* rows. Go (24.5 ms) leads with its `[]byte` range loop, then Vader native (39.5 ms) ahead of Bun (42.2 ms), Java (56.6 ms) trailing. Vader scans the zero-copy `bytes()` view through the open-coded `u8[]` load and runs a branchy whitespace state machine — the lexer's inner loop, which nothing else in the corpus measures. The gap to Go is the branch-heavy state machine, not the load (per the u8-read note, `cc -O3` already erases the per-byte tax).
- **`quicksort`** — array get/set + swaps + bounded recursion, the *same* hand-written median-of-three Lomuto sort in every language (not the stdlib), so it compares codegen rather than library quality. Go (34.4 ms) leads, Vader native (49.2 ms) is second — ahead of Bun (73.5 ms) and Java (80.0 ms). Exercises the swap / reassign lowering (a former miscompile site) and the typed `a[i]` store ; the input is a coprime-stride permutation of [0, N) so the sorted result is exactly [0, N) and the order-sensitive rolling-hash checksum proves the sort ran. Recursing the smaller half bounds the stack to O(log N).
- **`selfcompile_c`** (Vader-only, compile-time) — times the compiler emitting C for the whole compiler. **4.6 s, roughly half the 8.7 s of an earlier baseline** : the 2026-07-16 fix that stopped the single-expression inliner from splicing statement-bearing trait-method bodies (e.g. an enum's `= match self { … }`) removed a pathological inline explosion in the compiler's own code — one diagnostic snippet's bytecode collapsed 13818 → 129 lines — so there is far less C to emit ; the `devirtualize_fn_refs` pass shaves a little more.

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
