// Memory-leak audit for native snippets — Vader-emitted C variant.
//
// For each snippet under tests/snippets/, emit C with the Vader self-compiled
// compiler (`./build/vader dump --stage=c`), build a native binary the same
// way tests/native.test.ts does, then run it under macOS `leaks --atExit` and
// collect a per-snippet leak summary. Unlike the historical flow, the C source
// now comes from the Vader `c_emit` pass + runtime — NOT the TS pipeline — so
// this audit exercises the self-compiled compiler's own output.
// Run with: bun tests/leaks_check.ts

import { existsSync, readFileSync, rmSync, writeFileSync } from "node:fs";
import { join, resolve } from "node:path";

import { VM_ERROR_PREFIXES, listSnippets } from "./snapshot.ts";

const RUNTIME_ROOT = resolve(import.meta.dir, "../runtime/c");
const VADER_BIN = resolve(import.meta.dir, "../build/vader");
const EXE_EXT = process.platform === "win32" ? ".exe" : "";

interface Result {
  name: string;
  status: "clean" | "leak" | "skipped" | "emit_fail" | "build_fail" | "run_fail" | "leaks_fail" | "mismatch";
  nodes?: number;
  bytes?: number;
  leakedNodes?: number;
  leakedBytes?: number;
  detail?: string;
}

const sizeToBytes = (n: number, unit: string | undefined): number => {
  switch (unit ?? "B") {
    case "B": return Math.round(n);
    case "KB": return Math.round(n * 1024);
    case "MB": return Math.round(n * 1024 * 1024);
    case "GB": return Math.round(n * 1024 * 1024 * 1024);
    default: return Math.round(n);
  }
};

function parseLeaksOutput(text: string): { nodes: number; bytes: number; leakedNodes: number; leakedBytes: number } | null {
  // Looks like:
  //   Process N: 187 nodes malloced for 11 KB
  //   Process N: 0 leaks for 0 total leaked bytes.
  // Fragmented allocations report the leaked side with a unit (`1.2 KB`); we
  // sizeToBytes both sides so a `1.2` doesn't get truncated to `1`.
  const malloced = text.match(/(\d+)\s+nodes\s+malloced\s+for\s+([\d.]+)\s*(B|KB|MB|GB)?/);
  const leaked = text.match(/(\d+)\s+leaks?\s+for\s+([\d.]+)\s*(B|KB|MB|GB)?\s+total\s+leaked\s+bytes/);
  if (!malloced || !leaked) return null;
  return {
    nodes: parseInt(malloced[1]!, 10),
    bytes: sizeToBytes(parseFloat(malloced[2]!), malloced[3]),
    leakedNodes: parseInt(leaked[1]!, 10),
    leakedBytes: sizeToBytes(parseFloat(leaked[2]!), leaked[3]),
  };
}

async function check(s: { name: string; dir: string; mainPath: string }): Promise<Result> {
  const cFile = join(s.dir, "native.c");
  const binFile = join(s.dir, `native${EXE_EXT}`);

  // Error snapshots never produce a clean native run — classify them up front
  // so a non-zero `dump` exit on them counts as a skip, not an emit failure.
  let expected: string | undefined;
  try { expected = await Bun.file(join(s.dir, "vm.snapshot")).text(); } catch {}
  const isErrorSnap = expected !== undefined && VM_ERROR_PREFIXES.some((p) => expected!.startsWith(p));

  // Emit C with the Vader self-compiled compiler (./build/vader), NOT the TS
  // pipeline. `dump --stage=c` writes the generated C source to stdout.
  const emitProc = Bun.spawn(
    [VADER_BIN, "dump", "--stage=c", s.mainPath],
    { stdout: "pipe", stderr: "pipe" },
  );
  const cText = await new Response(emitProc.stdout).text();
  const emitErr = await new Response(emitProc.stderr).text();
  if ((await emitProc.exited) !== 0) {
    // Error snapshots are meant not to compile — skip them quietly. Everything
    // else is a genuine gap in the Vader c_emit pass, so surface it.
    if (isErrorSnap) return { name: s.name, status: "skipped", detail: "error snapshot (vader dump failed as expected)" };
    return { name: s.name, status: "emit_fail", detail: `vader dump --stage=c: ${emitErr.slice(0, 200)}` };
  }
  if (isErrorSnap) return { name: s.name, status: "skipped", detail: "vm.snapshot is an error snapshot" };

  // On snippets that emit warnings, `dump --stage=c` appends a trailing
  // `# Diagnostics` block to stdout after the C source. That marker can never
  // appear in valid generated C, so truncate there before handing it to cc.
  const diagIdx = cText.indexOf("\n# Diagnostics");
  const cSource = diagIdx >= 0 ? cText.slice(0, diagIdx + 1) : cText;
  await Bun.write(cFile, cSource);

  const buildProc = Bun.spawn([
    "cc", "-std=c11", "-O0", "-g", "-I", RUNTIME_ROOT,
    cFile, join(RUNTIME_ROOT, "vader_runtime.c"), "-o", binFile, "-lm",
  ], { stderr: "pipe", stdout: "pipe" });
  const buildErr = await new Response(buildProc.stderr).text();
  if ((await buildProc.exited) !== 0) {
    rmSync(cFile, { force: true });
    return { name: s.name, status: "build_fail", detail: buildErr.slice(0, 200) };
  }

  // `--quiet` is intentionally NOT passed — it suppresses the
  // `Process N: X nodes malloced` summary line our parser depends on.
  const env = { ...process.env, MallocStackLogging: "1" };
  try {
    const proc = Bun.spawn(
      ["leaks", "--atExit", "--", binFile],
      { cwd: process.cwd(), env, stdout: "pipe", stderr: "pipe" },
    );
    const stdout = await new Response(proc.stdout).text();
    const stderr = await new Response(proc.stderr).text();
    const exit = await proc.exited;

    // leaks exit codes: 0 = no leaks, 1 = leaks found, other = error.
    if (exit !== 0 && exit !== 1) {
      return { name: s.name, status: "leaks_fail", detail: `exit=${exit} ${stderr.slice(0, 200)}` };
    }

    const parsed = parseLeaksOutput(stdout);
    if (!parsed) {
      return { name: s.name, status: "leaks_fail", detail: `unparseable output: ${stdout.slice(0, 200)}` };
    }

    const baseRes: Result = {
      name: s.name, status: "clean",
      nodes: parsed.nodes, bytes: parsed.bytes,
      leakedNodes: parsed.leakedNodes, leakedBytes: parsed.leakedBytes,
    };
    if (parsed.leakedNodes > 0) baseRes.status = "leak";
    return baseRes;
  } finally {
    // The native binary, its source, and dsymutil's debug bundle are pure
    // build artefacts of this audit run — remove them so they don't pile up
    // in the working tree (the test suite generates and cleans the same
    // files separately for parity tests).
    rmSync(binFile, { force: true });
    rmSync(cFile, { force: true });
    rmSync(`${binFile}.dSYM`, { force: true, recursive: true });
  }
}

const UPDATE_BASELINE = process.argv.includes("--update");
const BASELINE_PATH = resolve(import.meta.dir, "leaks.snapshot.json");

interface BaselineEntry { leakedNodes: number; leakedBytes: number }
type Baseline = Record<string, BaselineEntry>;

function loadBaseline(): Baseline | null {
  if (!existsSync(BASELINE_PATH)) return null;
  try { return JSON.parse(readFileSync(BASELINE_PATH, "utf8")) as Baseline; }
  catch { return null; }
}

const CC_AVAILABLE = await (async () => {
  try {
    const proc = Bun.spawn(["cc", "--version"], { stdout: "ignore", stderr: "ignore" });
    return (await proc.exited) === 0;
  } catch { return false; }
})();

const LEAKS_AVAILABLE = await (async () => {
  try {
    const proc = Bun.spawn(["leaks", "--help"], { stdout: "ignore", stderr: "ignore" });
    await proc.exited;
    return true;
  } catch { return false; }
})();

// Linux / Windows: `leaks` only ships with macOS. Skip gracefully so the
// `test:leak` script in package.json doesn't break cross-platform CI.
if (process.platform !== "darwin") {
  console.log("leaks_check: skipped (macOS only — `leaks(1)` not available on this platform)");
  process.exit(0);
}
if (!CC_AVAILABLE) { console.error("cc not available — aborting"); process.exit(1); }
if (!LEAKS_AVAILABLE) { console.error("leaks not available — aborting (macOS only)"); process.exit(1); }
if (!existsSync(VADER_BIN)) {
  console.error(`vader binary not found at ${VADER_BIN} — run \`bun run build:cli\` first`);
  process.exit(1);
}

const scenarios = listSnippets("tests/snippets");
console.log(`scanning ${scenarios.length} snippets…`);

const results: Result[] = [];
const concurrency = 4;
let idx = 0;

async function worker() {
  while (true) {
    const i = idx++;
    if (i >= scenarios.length) return;
    const s = scenarios[i]!;
    const res = await check(s);
    results.push(res);
    const tag = res.status === "leak" ? "LEAK"
      : res.status === "clean" ? "ok"
      : res.status;
    process.stdout.write(`[${(i + 1).toString().padStart(3)}/${scenarios.length}] ${tag.padEnd(11)} ${s.name}${res.status === "leak" ? `  (${res.leakedNodes} leaks, ${res.leakedBytes} B)` : ""}\n`);
  }
}

await Promise.all(Array.from({ length: concurrency }, worker));

results.sort((a, b) => a.name.localeCompare(b.name));

const leaks = results.filter((r) => r.status === "leak");
const clean = results.filter((r) => r.status === "clean");
const skipped = results.filter((r) => r.status === "skipped");
const emitFailed = results.filter((r) => r.status === "emit_fail");
const failed = results.filter((r) => r.status === "emit_fail" || r.status === "build_fail" || r.status === "run_fail" || r.status === "leaks_fail");

console.log("\n===== SUMMARY =====");
console.log(`total:     ${results.length}`);
console.log(`clean:     ${clean.length}`);
console.log(`leaking:   ${leaks.length}`);
console.log(`skipped:   ${skipped.length}`);
console.log(`emit_fail: ${emitFailed.length}  (Vader c_emit could not produce C)`);
console.log(`failed:    ${failed.length}`);

if (leaks.length > 0) {
  console.log("\n--- leaks ---");
  for (const r of leaks) {
    console.log(`  ${r.name}: ${r.leakedNodes} leaks, ${r.leakedBytes} B  (alloc ${r.nodes} nodes, ${r.bytes} B)`);
  }
}
if (failed.length > 0) {
  console.log("\n--- failed ---");
  for (const r of failed) {
    console.log(`  ${r.name} [${r.status}]: ${r.detail}`);
  }
}

// Baseline mode: by-design string-buffer leaks are part of the budget, so a
// raw "any leak fails CI" rule fires forever. Compare against
// `tests/leaks.snapshot.json` — exit non-zero only on regressions.
if (UPDATE_BASELINE) {
  const baseline: Baseline = {};
  for (const r of [...clean, ...leaks]) {
    if (r.leakedNodes !== undefined && r.leakedBytes !== undefined) {
      baseline[r.name] = { leakedNodes: r.leakedNodes, leakedBytes: r.leakedBytes };
    }
  }
  writeFileSync(BASELINE_PATH, JSON.stringify(baseline, null, 2) + "\n");
  console.log(`\nbaseline written: ${BASELINE_PATH} (${Object.keys(baseline).length} entries)`);
  process.exit(0);
}

const baseline = loadBaseline();
if (baseline === null) {
  console.log("\nno baseline at tests/leaks.snapshot.json — run with --update to write one");
  process.exit(leaks.length > 0 ? 2 : 0);
}

const regressions: string[] = [];
for (const r of leaks) {
  const prev = baseline[r.name];
  if (prev === undefined) {
    regressions.push(`  NEW LEAK ${r.name}: ${r.leakedNodes} leaks, ${r.leakedBytes} B`);
    continue;
  }
  if (r.leakedBytes! > prev.leakedBytes || r.leakedNodes! > prev.leakedNodes) {
    regressions.push(
      `  REGRESS  ${r.name}: ${r.leakedNodes}/${r.leakedBytes}B (was ${prev.leakedNodes}/${prev.leakedBytes}B)`,
    );
  }
}
if (regressions.length > 0) {
  console.log("\n--- regressions vs baseline ---");
  for (const line of regressions) console.log(line);
  process.exit(2);
}
console.log("\nleaks within baseline budget");
process.exit(0);
