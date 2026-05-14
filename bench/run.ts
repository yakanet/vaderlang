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
  { name: "string_builder", description: "append a 45-char fragment 50 000 times",   outputMatch: "string_builder" },
];

interface Impl {
  readonly name: string;
  /** Optional one-shot build step. Runs once before any timed run. */
  build?: (workload: string) => void;
  /** Command + args to invoke for a single timed run. */
  run: (workload: string) => { cmd: string; args: readonly string[] };
}

const IMPLS: readonly Impl[] = [
  {
    name: "vader-vm",
    run: (w) => ({ cmd: "bun", args: ["src/index.ts", "run", `bench/${w}.vader`] }),
  },
  {
    name: "vader-native",
    build: (w) => {
      const r = spawnSync("bun", ["src/index.ts", "build", "--target=native", "--release", `bench/${w}.vader`], { cwd: REPO, stdio: "inherit" });
      if (r.status !== 0) throw new Error(`vader build for ${w} failed`);
    },
    run: (w) => ({ cmd: `./bench/${w}`, args: [] }),
  },
  {
    name: "bun-ts",
    run: (w) => ({ cmd: "bun", args: [`bench/${w}.ts`] }),
  },
  {
    name: "go",
    build: (w) => {
      const r = spawnSync("go", ["build", "-o", `bench/${w}_go`, `bench/${w}.go`], { cwd: REPO, stdio: "inherit" });
      if (r.status !== 0) throw new Error(`go build for ${w} failed`);
    },
    run: (w) => ({ cmd: `./bench/${w}_go`, args: [] }),
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
  if (impl.build) impl.build(workload.name);
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

async function main(): Promise<void> {
  const args = parseArgs();
  const workloads = args.workloads === null
    ? WORKLOADS
    : WORKLOADS.filter((w) => args.workloads!.includes(w.name));
  const results: SampleResult[] = [];
  for (const w of workloads) {
    for (const impl of IMPLS) {
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
