// Bench harness — drives every Vader / Bun-TS / Go implementation of each
// workload through `spawnSync`, captures wall-clock time, and prints a
// comparison table. Exits non-zero if any (workload, implementation) time
// regresses by more than `THRESHOLD` against the baseline committed at
// `bench/baseline.json` (overridable via `BENCH_BASELINE` env var).
//
// Usage :
//   bun bench/run.ts                  # measure + compare to baseline
//   bun bench/run.ts --update         # write current measurements as baseline
//   bun bench/run.ts --runs=5         # override default 3 timed runs
//   bun bench/run.ts --workload=mandelbrot   # narrow to a single workload

import { spawnSync } from "node:child_process";
import { existsSync, readFileSync, writeFileSync } from "node:fs";
import { join } from "node:path";

const REPO = import.meta.dir.replace(/\/bench$/, "");
const BASELINE_PATH = process.env.BENCH_BASELINE ?? join(REPO, "bench", "baseline.json");
const THRESHOLD = 0.15;       // 15 % regression triggers a non-zero exit
                              // Tight enough to catch real regressions ; loose enough that
                              // a single sample blip on a < 20 ms native workload doesn't
                              // flip CI red.
const MIN_REGRESSION_MS = 5;  // Skip regression detection on measurements faster
                              // than this — OS scheduling noise routinely accounts
                              // for ±1 ms which is > 15 % of a 5 ms sample.

interface Args { runs: number; update: boolean; workloads: string[] | null }

function parseArgs(): Args {
  let runs = 3, update = false;
  let workloads: string[] | null = null;
  for (const a of process.argv.slice(2)) {
    if (a === "--update") update = true;
    else if (a.startsWith("--runs=")) runs = Number(a.slice(7));
    else if (a.startsWith("--workload=")) workloads = a.slice(11).split(",");
    else { console.error(`unknown arg: ${a}`); process.exit(2); }
  }
  return { runs, update, workloads };
}

interface Workload {
  readonly name: string;
  /** Long-form description for README/table headers. */
  readonly description: string;
  /** Substring expected in every implementation's stdout — guards against
   *  silent algorithmic divergence. */
  readonly outputMatch: string;
}

const WORKLOADS: readonly Workload[] = [
  { name: "mandelbrot",     description: "240×180 grid, max 500 iter per pixel",     outputMatch: "mandelbrot" },
  { name: "primes",         description: "trial division up to N = 1 000 000",       outputMatch: "primes" },
  { name: "iter_chain",     description: "Σ x² for even x in [0, 1 000 000)",        outputMatch: "iter_chain" },
  { name: "binary_trees",   description: "balanced tree depth=17 (262 143 nodes)",   outputMatch: "binary_trees" },
  { name: "string_builder", description: "append a 45-char fragment 80 000 times",   outputMatch: "string_builder" },
  { name: "map_iter",       description: "1 000 outer × 1 000 inner map iter (1 M visits)", outputMatch: "map_iter" },
  { name: "arr_rw",         description: "1024-elt i32[] read-modify-write, 100k passes",   outputMatch: "arr_rw" },
  { name: "arr_push",       description: "20 M i32 pushes (200 × 100k), grow + GC churn",    outputMatch: "arr_push" },
  { name: "str_concat",     description: "300k × build a 13-byte string by repeated +",      outputMatch: "str_concat" },
  { name: "interp",         description: "200k × format 3 ints via ${} interpolation",       outputMatch: "interp" },
  // Vader-only : compiler THROUGHPUT, not generated-code runtime. Times a full C
  // emission of the self-hosted compiler (~30 kLoC) — the largest realistic input,
  // and the one thing the runtime-only workloads above can't catch (an O(n²) crept
  // into a typecheck / lower / emit pass). `--target=c --release` stops after the
  // compiler's own passes (no cc / linker time, no `#line` bloat). stdout is empty
  // (the "wrote" line is on stderr) so `checksum` is "" ; the exit-0 guard in
  // `timedRun` already asserts the compile succeeded. NB: this time GROWS as the
  // compiler grows — re-baseline (`--update`) after a large feature lands, the way
  // the bootstrap seed is refreshed.
  { name: "selfcompile_c",  description: "emit C for the whole self-hosted compiler (~30 kLoC)", outputMatch: "" },
];

interface Impl {
  readonly name: string;
  /** Path (relative to the repo root) to this impl's source for a workload.
   *  An impl whose source is absent is silently skipped for that workload —
   *  so a workload that ships only a subset of language ports still works,
   *  its row showing just the columns it has. */
  source: (workload: string) => string;
  /** Optional one-shot build step. Runs once per workload up-front, before
   *  any timed runs ; all `build` invocations are scheduled together via
   *  `Promise.all` so independent compilers (Vader native + Go) can use
   *  every available core. Measurements remain serial — concurrent
   *  CPU-bound timed runs would contend on caches / thermal headroom and
   *  destroy the signal. */
  build?: (workload: string) => Promise<void>;
  /** Command + args to invoke for a single timed run. */
  run: (workload: string) => { cmd: string; args: readonly string[] };
}

/** True when `impl` has a source file for `workload` under the repo. */
function implHasSource(impl: Impl, workload: string): boolean {
  return existsSync(join(REPO, impl.source(workload)));
}

async function runBuild(cmd: string, args: readonly string[], label: string): Promise<void> {
  // Pipe stdio so a build's chatter doesn't interleave line-by-line with
  // a sibling build's. We swallow the output on success ; on failure we
  // surface it together with the failure marker.
  const proc = Bun.spawn([cmd, ...args], {
    cwd: REPO, stdout: "pipe", stderr: "pipe",
  });
  const [stdout, stderr, code] = await Promise.all([
    new Response(proc.stdout).text(),
    new Response(proc.stderr).text(),
    proc.exited,
  ]);
  if (code !== 0) {
    process.stderr.write(stdout);
    process.stderr.write(stderr);
    throw new Error(`${label} failed (exit ${code})`);
  }
}

const IMPLS: readonly Impl[] = [
  // vader-vm is intentionally disabled by default — each invocation pays
  // 2-30 s for the parse + typecheck + lower + bytecode-emit pipeline
  // (dwarfing the actual VM loop), which inflates the total bench wall
  // time to ~5 min without telling us anything that the native column
  // doesn't. Uncomment to opt back in when a change targets the VM exec
  // path specifically (e.g. once the bytecode-on-disk cache lands).
  //
  // {
  //   name: "vader-vm",
  //   run: (w) => ({ cmd: "./build/vader", args: ["run", `bench/${w}/${w}.vader`] }),
  // },
  {
    name: "vader-native",
    // `selfcompile_c` is special : its source IS the compiler entry, and the
    // TIMED run is the emit itself (no separate build step, no per-workload
    // binary). Every other impl lacks a `bench/selfcompile_c/*` source, so they
    // are silently skipped and the row shows only this column.
    source: (w) => w === "selfcompile_c" ? "vader/cli/main.vader" : `bench/${w}/${w}.vader`,
    build: (w) => w === "selfcompile_c"
      ? Promise.resolve()
      : runBuild("./build/vader", ["build", "--target=native", "--release", `bench/${w}/${w}.vader`], `vader build for ${w}`),
    run: (w) => w === "selfcompile_c"
      ? { cmd: "./build/vader", args: ["build", "vader/cli/main.vader", "--target=c", "--release", "--out=build/_bench_selfcompile.c"] }
      : { cmd: `./bench/${w}/${w}`, args: [] },
  },
  {
    name: "bun-ts",
    source: (w) => `bench/${w}/${w}.ts`,
    run: (w) => ({ cmd: "bun", args: [`bench/${w}/${w}.ts`] }),
  },
  {
    name: "go",
    source: (w) => `bench/${w}/${w}.go`,
    build: (w) => runBuild("go", ["build", "-o", `bench/${w}/${w}_go`, `bench/${w}/${w}.go`], `go build for ${w}`),
    run: (w) => ({ cmd: `./bench/${w}/${w}_go`, args: [] }),
  },
  {
    name: "java",
    source: (w) => `bench/${w}/${w}.java`,
    build: (w) => runBuild("javac", ["--release", "25", "-d", `bench/${w}`, `bench/${w}/${w}.java`], `javac for ${w}`),
    run: (w) => ({ cmd: "java", args: ["-cp", `bench/${w}`, w] }),
  },
];

interface SampleResult {
  readonly workload: string;
  readonly impl: string;
  readonly medianMs: number;
  readonly minMs: number;
  readonly samplesMs: readonly number[];
  readonly checksum: string;
}

function timedRun(impl: Impl, workload: string): { ms: number; stdout: string } {
  const { cmd, args } = impl.run(workload);
  const start = performance.now();
  const r = spawnSync(cmd, args, { cwd: REPO, encoding: "utf8" });
  const ms = performance.now() - start;
  if (r.status !== 0) {
    throw new Error(`${impl.name} ${workload} exited ${r.status}: ${r.stderr ?? ""}`);
  }
  return { ms, stdout: r.stdout ?? "" };
}

function median(xs: readonly number[]): number {
  const sorted = [...xs].sort((a, b) => a - b);
  const m = sorted.length;
  return m % 2 === 1 ? sorted[(m - 1) >>> 1]! : 0.5 * (sorted[m / 2 - 1]! + sorted[m / 2]!);
}

function measure(impl: Impl, workload: Workload, runs: number): SampleResult {
  // Build steps already ran upfront in parallel — see `buildAll` below.
  // One warmup invocation so JIT-ish runtimes (Bun) and OS caches are warm,
  // then `runs` measured samples.
  timedRun(impl, workload.name);
  const samples: number[] = [];
  let lastStdout = "";
  for (let i = 0; i < runs; i++) {
    const { ms, stdout } = timedRun(impl, workload.name);
    samples.push(ms);
    lastStdout = stdout;
  }
  const line = lastStdout.split("\n").find((l) => l.includes(workload.outputMatch.split(" ")[0]!)) ?? "";
  return {
    workload: workload.name,
    impl: impl.name,
    medianMs: median(samples),
    minMs: Math.min(...samples),
    samplesMs: samples,
    checksum: line.trim(),
  };
}

function formatTable(results: readonly SampleResult[]): string {
  const workloads = [...new Set(results.map((r) => r.workload))];
  const impls = [...new Set(results.map((r) => r.impl))];
  const lines: string[] = [];
  lines.push(`| workload | ${impls.join(" | ")} |`);
  lines.push(`|---|${impls.map(() => "---").join("|")}|`);
  for (const w of workloads) {
    const row = impls.map((i) => {
      const r = results.find((x) => x.workload === w && x.impl === i);
      return r ? `${r.minMs.toFixed(1)} ms` : "—";
    });
    lines.push(`| **${w}** | ${row.join(" | ")} |`);
  }
  return lines.join("\n");
}

/** We baseline on `min(samples)` rather than the median : these workloads
 *  finish in 20-100 ms on JIT'd / natively-compiled peers, so run-to-run
 *  variance from GC pauses and OS scheduling routinely exceeds the 10 %
 *  regression threshold. `min` reflects the best-case CPU path, which is
 *  what we actually care about when checking for perf changes. */
interface BaselineEntry { minMs: number; checksum: string }
type Baseline = Record<string, Record<string, BaselineEntry>>;

function loadBaseline(): Baseline | null {
  if (!existsSync(BASELINE_PATH)) return null;
  return JSON.parse(readFileSync(BASELINE_PATH, "utf8")) as Baseline;
}

function writeBaseline(results: readonly SampleResult[]): void {
  const out: Baseline = {};
  for (const r of results) {
    out[r.workload] ??= {};
    out[r.workload]![r.impl] = { minMs: r.minMs, checksum: r.checksum };
  }
  writeFileSync(BASELINE_PATH, JSON.stringify(out, null, 2) + "\n");
}

function compareWithBaseline(results: readonly SampleResult[], baseline: Baseline): { regressions: string[]; checksumDrift: string[] } {
  const regressions: string[] = [];
  const checksumDrift: string[] = [];
  for (const r of results) {
    const ref = baseline[r.workload]?.[r.impl];
    if (ref === undefined) continue;
    if (ref.checksum !== r.checksum) {
      checksumDrift.push(`${r.workload}/${r.impl}: baseline "${ref.checksum}" vs current "${r.checksum}"`);
    }
    if (ref.minMs < MIN_REGRESSION_MS) continue;
    const ratio = r.minMs / ref.minMs - 1;
    if (ratio > THRESHOLD) {
      regressions.push(`${r.workload}/${r.impl}: ${r.minMs.toFixed(1)} ms vs ${ref.minMs.toFixed(1)} ms baseline (+${(ratio * 100).toFixed(1)} %)`);
    }
  }
  return { regressions, checksumDrift };
}

async function buildAll(workloads: readonly Workload[]): Promise<void> {
  const tasks: Promise<void>[] = [];
  for (const w of workloads) {
    for (const impl of IMPLS) {
      if (!impl.build) continue;
      if (!implHasSource(impl, w.name)) continue;
      tasks.push(impl.build(w.name));
    }
  }
  if (tasks.length === 0) return;
  console.log(`# building ${tasks.length} artefacts in parallel ...`);
  const start = performance.now();
  await Promise.all(tasks);
  console.log(`# build done in ${((performance.now() - start) / 1000).toFixed(1)} s`);
}

async function main(): Promise<void> {
  const args = parseArgs();
  const workloads = args.workloads === null
    ? WORKLOADS
    : WORKLOADS.filter((w) => args.workloads!.includes(w.name));
  await buildAll(workloads);
  const results: SampleResult[] = [];
  for (const w of workloads) {
    for (const impl of IMPLS) {
      if (!implHasSource(impl, w.name)) continue;
      console.log(`# ${w.name}/${impl.name} ...`);
      const r = measure(impl, w, args.runs);
      results.push(r);
      console.log(`  median ${r.medianMs.toFixed(1)} ms  min ${r.minMs.toFixed(1)} ms  ${r.checksum}`);
    }
  }
  console.log("");
  console.log(formatTable(results));
  console.log("");

  if (args.update) {
    writeBaseline(results);
    console.log(`wrote baseline to ${BASELINE_PATH}`);
    return;
  }

  const baseline = loadBaseline();
  if (baseline === null) {
    console.log(`no baseline at ${BASELINE_PATH} (run with --update to create one)`);
    return;
  }
  const { regressions, checksumDrift } = compareWithBaseline(results, baseline);
  if (checksumDrift.length > 0) {
    console.error("\nchecksum drift (algorithmic divergence vs baseline):");
    for (const d of checksumDrift) console.error(`  ${d}`);
    process.exit(1);
  }
  if (regressions.length > 0) {
    console.error(`\nperf regression > ${(THRESHOLD * 100).toFixed(0)} %:`);
    for (const r of regressions) console.error(`  ${r}`);
    process.exit(1);
  }
  console.log(`ok — no regression beyond ${(THRESHOLD * 100).toFixed(0)} % vs baseline.`);
}

await main();
