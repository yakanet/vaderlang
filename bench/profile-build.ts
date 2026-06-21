// Self-compile profiler harness — measures where the compiler spends time,
// CPU, and memory while compiling ITSELF (`vader/cli/main.vader`).
//
// Two complementary layers:
//   1. In-compiler per-pass profiler (VADER_PROFILE=1) — load / typecheck /
//      comptime / lower / cfg / escape / bytecode / c-emit wall + RSS-growth +
//      GC churn, printed by the runtime (see vader/profile + runtime/c).
//   2. This harness — wraps each build STAGE under `/usr/bin/time -l` to add
//      whole-process wall / user+sys CPU / peak RSS, plus an optional
//      per-type GC live-set dump (VADER_GC_PROFILE=1).
//
// Usage :
//   bun bench/profile-build.ts                  # full report (self-emit + cc)
//   bun bench/profile-build.ts --no-cc          # skip the cc step
//   bun bench/profile-build.ts --gc-profile     # extra run for the per-type live set
//   bun bench/profile-build.ts --input=examples/mandelbrot/_main.vader
//   bun bench/profile-build.ts --vader=build/stage0   # profile a specific binary
//
// macOS-first: parses BSD `/usr/bin/time -l`. On Linux use `/usr/bin/time -v`
// (the harness falls back to wall-clock only if neither format is recognised).

import { existsSync, mkdtempSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

const REPO = import.meta.dir.replace(/\/bench$/, "");

interface Args {
  input: string;
  vader: string;
  cc: boolean;
  gcProfile: boolean;
}

function parseArgs(): Args {
  let input = "vader/cli/main.vader";
  let vader = "build/vader";
  let cc = true;
  let gcProfile = false;
  for (const a of process.argv.slice(2)) {
    if (a === "--no-cc") cc = false;
    else if (a === "--gc-profile") gcProfile = true;
    else if (a.startsWith("--input=")) input = a.slice(8);
    else if (a.startsWith("--vader=")) vader = a.slice(8);
    else { console.error(`unknown arg: ${a}`); process.exit(2); }
  }
  return { input, vader, cc, gcProfile };
}

// Arena sizing is RAM-proportional (runtime/c/vader_runtime.c::vader_gc_init),
// matching bootstrap/build.sh — no manual pin, so the profile reflects the real
// shipped default. A VADER_GC_* value already in the environment still wins.
const GC_ENV: Record<string, string> = {};
if (process.env.VADER_GC_YOUNG_BYTES) GC_ENV.VADER_GC_YOUNG_BYTES = process.env.VADER_GC_YOUNG_BYTES;
if (process.env.VADER_GC_OLD_BYTES) GC_ENV.VADER_GC_OLD_BYTES = process.env.VADER_GC_OLD_BYTES;

interface TimeStats {
  realSec: number | null;
  userSec: number | null;
  sysSec: number | null;
  maxRssBytes: number | null;
}

// Parse BSD (`/usr/bin/time -l`) or GNU (`-v`) time output from a stderr blob.
function parseTime(stderr: string): TimeStats {
  const out: TimeStats = { realSec: null, userSec: null, sysSec: null, maxRssBytes: null };
  // Locale may use a comma decimal separator (e.g. fr_FR: "0,00 real").
  const num = (s: string | undefined): number => Number((s ?? "").replace(",", "."));
  // BSD: "        2.45 real         2.20 user         0.18 sys"
  const bsd = stderr.match(/([\d.,]+)\s+real\s+([\d.,]+)\s+user\s+([\d.,]+)\s+sys/);
  if (bsd) {
    out.realSec = num(bsd[1]);
    out.userSec = num(bsd[2]);
    out.sysSec = num(bsd[3]);
  }
  // BSD: "           987654321  maximum resident set size" (bytes)
  const bsdRss = stderr.match(/(\d+)\s+maximum resident set size/);
  if (bsdRss) out.maxRssBytes = Number(bsdRss[1]);
  // GNU: "Maximum resident set size (kbytes): 987654" + "Elapsed (wall clock) time ..."
  const gnuRss = stderr.match(/Maximum resident set size \(kbytes\):\s*(\d+)/);
  if (gnuRss && out.maxRssBytes === null) out.maxRssBytes = Number(gnuRss[1]) * 1024;
  const gnuUser = stderr.match(/User time \(seconds\):\s*([\d.]+)/);
  if (gnuUser && out.userSec === null) out.userSec = Number(gnuUser[1]);
  const gnuSys = stderr.match(/System time \(seconds\):\s*([\d.]+)/);
  if (gnuSys && out.sysSec === null) out.sysSec = Number(gnuSys[1]);
  return out;
}

// Extract the runtime's [VADER_PROFILE] per-pass block, if present.
function extractProfBlock(stderr: string): string | null {
  const idx = stderr.indexOf("[VADER_PROFILE]");
  if (idx < 0) return null;
  // The block runs to the line after "peak-RSS ... live-set ...".
  const tail = stderr.slice(idx);
  const end = tail.indexOf("live-set");
  if (end < 0) return tail.trimEnd();
  const lineEnd = tail.indexOf("\n", end);
  return tail.slice(0, lineEnd < 0 ? undefined : lineEnd).trimEnd();
}

// Extract the per-type GC live-set dump (VADER_GC_PROFILE), if present.
function extractGcBlock(stderr: string): string | null {
  const m = stderr.match(/=== vader_gc_profile[\s\S]*/);
  return m ? m[0].trimEnd() : null;
}

function fmtSec(s: number | null): string {
  return s === null ? "   —  " : `${s.toFixed(2)}s`;
}
function fmtMB(b: number | null): string {
  return b === null ? "   —  " : `${(b / (1024 * 1024)).toFixed(0)} MB`;
}

// Run a command under `/usr/bin/time -l`, capturing its stderr (which holds
// both the timing block and any VADER_* profiler output). Returns the raw
// stderr plus parsed stats. `outPath` receives the child's stdout if set.
function runTimed(
  argv: string[],
  env: Record<string, string | undefined>,
  outPath: string | null,
): { stderr: string; stats: TimeStats; code: number } {
  const haveBsdTime = existsSync("/usr/bin/time");
  const cmd = haveBsdTime ? ["/usr/bin/time", "-l", ...argv] : argv;
  const proc = Bun.spawnSync({
    cmd,
    cwd: REPO,
    env: { ...process.env, ...env },
    stdout: outPath ? "pipe" : "ignore",
    stderr: "pipe",
  });
  const stderr = proc.stderr.toString();
  if (outPath && proc.stdout) Bun.write(outPath, proc.stdout);
  return { stderr, stats: parseTime(stderr), code: proc.exitCode ?? -1 };
}

function reportStage(label: string, stats: TimeStats): void {
  const cpu = stats.userSec !== null && stats.sysSec !== null
    ? `${fmtSec(stats.userSec)} user + ${fmtSec(stats.sysSec)} sys`
    : "   —  ";
  console.log(
    `  ${label.padEnd(22)} ${fmtSec(stats.realSec).padStart(7)} wall   ` +
    `${cpu.padEnd(28)} ${fmtMB(stats.maxRssBytes).padStart(7)} peak-RSS`,
  );
}

function main(): void {
  const args = parseArgs();
  const vaderAbs = join(REPO, args.vader);
  if (!existsSync(vaderAbs)) {
    console.error(`profile-build: ${args.vader} not found — run \`bun run build:cli\` first.`);
    process.exit(1);
  }

  const tmp = mkdtempSync(join(tmpdir(), "vader-prof-"));
  const cPath = join(tmp, "selfcompile.c");

  console.log(`\n=== Vader self-compile profile ===`);
  console.log(`  binary : ${args.vader}`);
  console.log(`  input  : ${args.input}`);
  console.log(`  GC     : ${GC_ENV.VADER_GC_OLD_BYTES ? `old=${(+GC_ENV.VADER_GC_OLD_BYTES / 1048576) | 0}MB (override)` : "RAM-proportional (auto)"}\n`);

  // --- Stage 1: front-end → C, with the in-compiler per-pass profiler on. ----
  // `build --target=c --out=-` routes through the fully-instrumented
  // emit_c_source (so the c-emit pass + the prof dump fire) and emits the
  // real, linkable native C — the same path bootstrap/build.sh takes.
  const emit = runTimed(
    [args.vader, "build", "--target=c", "--out=-", args.input],
    { ...GC_ENV, VADER_PROFILE: "1" },
    cPath,
  );

  console.log("Stage timings (whole process):");
  reportStage("emit C (self-compile)", emit.stats);

  // --- Stage 2: cc the emitted C (the other big chunk of a native build). ----
  if (args.cc && emit.code === 0 && existsSync(cPath)) {
    const out = join(tmp, "selfcompile.bin");
    const ccBin = process.env.CC ?? "cc";
    const cc = runTimed(
      [ccBin, "-O0", "-std=c11", "-I", join(REPO, "runtime/c"), cPath,
       join(REPO, "runtime/c/vader_runtime.c"), "-o", out, "-lm"],
      {},
      null,
    );
    reportStage(`cc -O0 (${ccBin})`, cc.stats);
    if (cc.code !== 0) console.log(`  (cc exited ${cc.code})`);
  }

  // --- The in-compiler per-pass breakdown. -----------------------------------
  const prof = extractProfBlock(emit.stderr);
  console.log("");
  if (prof) {
    console.log(prof);
  } else {
    console.log("[VADER_PROFILE] no per-pass block — is this binary built with the profiler?");
    if (emit.code !== 0) {
      console.log(`  (self-compile exited ${emit.code}; stderr tail:)`);
      console.log(emit.stderr.split("\n").slice(-12).join("\n"));
    }
  }

  // --- Optional: per-type GC live-set. ---------------------------------------
  if (args.gcProfile) {
    console.log("\n=== GC live-set by type (VADER_GC_PROFILE) ===");
    const gc = runTimed(
      [args.vader, "build", "--target=c", "--out=-", args.input],
      { ...GC_ENV, VADER_GC_PROFILE: "1" },
      join(tmp, "selfcompile2.c"),
    );
    const gcBlock = extractGcBlock(gc.stderr);
    console.log(gcBlock ?? "  (no GC profile block — VADER_GC_PROFILE unsupported in this build?)");
  }

  rmSync(tmp, { recursive: true, force: true });
  console.log("");
}

main();
