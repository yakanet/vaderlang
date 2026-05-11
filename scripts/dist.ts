#!/usr/bin/env bun
// Build a distributable archive containing the Vader binary, the stdlib, and
// the C runtime. Layout:
//
//   dist/vader-<os>-<arch>/
//     vader (or vader.exe on Windows)    <- compiled binary
//     stdlib/std/*.vader
//     runtime/c/{vader.h, vader_runtime.c}
//     vader-src/                          <- self-host sources (cli, fmt, parser, …)
//                                            shipped because `vader fmt` (and
//                                            future Vader-implemented tools)
//                                            are loaded from disk by the TS host
//                                            until the full self-host lands.
//                                            Renamed from `vader/` to avoid
//                                            colliding with the `vader` binary
//                                            in the same directory.
//
// then gzipped into dist/vader-<os>-<arch>.tar.gz.

import { existsSync, mkdirSync, rmSync } from "node:fs";
import { dirname, join, resolve } from "node:path";

type Target = "darwin-arm64" | "linux-x64" | "windows-x64";

const TARGETS: readonly Target[] = ["darwin-arm64", "linux-x64", "windows-x64"];

function isTarget(s: string): s is Target {
  return (TARGETS as readonly string[]).includes(s);
}

function isWindows(t: Target): boolean {
  return t.startsWith("windows-");
}

function currentTarget(): Target {
  const os = process.platform === "darwin" ? "darwin"
    : process.platform === "linux" ? "linux"
    : process.platform === "win32" ? "windows"
    : null;
  const arch = process.arch === "arm64" ? "arm64" : process.arch === "x64" ? "x64" : null;
  if (os === null || arch === null) {
    throw new Error(`unsupported host platform: ${process.platform}/${process.arch}`);
  }
  const id = `${os}-${arch}` as const;
  if (!isTarget(id)) throw new Error(`current platform ${id} is not in the target list`);
  return id;
}

async function run(cmd: string[], opts: { cwd?: string } = {}): Promise<void> {
  const proc = Bun.spawn(cmd, { cwd: opts.cwd, stderr: "inherit", stdout: "inherit" });
  const code = await proc.exited;
  if (code !== 0) throw new Error(`command failed (exit ${code}): ${cmd.join(" ")}`);
}

async function buildOne(target: Target, repoRoot: string): Promise<void> {
  const archiveName = `vader-${target}`;
  const outDir = join(repoRoot, "dist", archiveName);
  // bun --compile auto-appends `.exe` for windows targets ; matching the file
  // name explicitly keeps the layout predictable and avoids a renaming dance.
  const binName = isWindows(target) ? "vader.exe" : "vader";

  console.error(`==> ${archiveName}`);

  if (existsSync(outDir)) rmSync(outDir, { recursive: true, force: true });
  mkdirSync(outDir, { recursive: true });

  // 1. Compile the binary. The Windows runtime defaults to requiring AVX2,
  // which Wine on Apple Silicon (Rosetta) does not provide and old PCs may
  // lack — pick the `baseline` Bun variant for windows-x64 so the artifact
  // runs on any x86_64 with at least SSE2. Marginal perf cost on modern CPUs
  // since Vader's CLI is not SIMD-bound.
  const bunTarget = target === "windows-x64" ? "bun-windows-x64-baseline" : `bun-${target}`;
  await run([
    "bun", "build",
    "--compile",
    "--minify",
    "--sourcemap",
    `--target=${bunTarget}`,
    "src/index.ts",
    `--outfile=${join(outDir, binName)}`,
  ], { cwd: repoRoot });

  // 2. Copy sidecar resources.
  await run(["cp", "-R", join(repoRoot, "stdlib"), join(outDir, "stdlib")]);
  mkdirSync(join(outDir, "runtime"), { recursive: true });
  await run(["cp", "-R", join(repoRoot, "runtime", "c"), join(outDir, "runtime", "c")]);
  // Self-host Vader sources. The TS host invokes `<vaderRoot>/cli/main.vader
  // fmt …` through the VM for the `fmt` subcommand ; future Vader-implemented
  // tools (`test`, eventually the full compiler) reuse the same tree. The
  // shipped directory is named `vader-src` rather than `vader` because the
  // compiled binary already occupies the `vader` name in the same directory.
  await run(["cp", "-R", join(repoRoot, "vader"), join(outDir, "vader-src")]);

  // 3. Archive : `.zip` for Windows (extractable via Explorer out of the
  // box ; exec bit is irrelevant on NTFS), `.tar.gz` for Unix targets
  // (preserves the executable bit).
  const archiveExt = isWindows(target) ? "zip" : "tar.gz";
  const archivePath = join(repoRoot, "dist", `${archiveName}.${archiveExt}`);
  if (existsSync(archivePath)) rmSync(archivePath);
  if (isWindows(target)) {
    await run(["zip", "-rq", archivePath, archiveName], { cwd: join(repoRoot, "dist") });
  } else {
    await run(["tar", "-czf", archivePath, "-C", join(repoRoot, "dist"), archiveName]);
  }

  const size = (await Bun.file(archivePath).bytes()).byteLength;
  console.error(`    wrote ${archivePath} (${(size / 1024 / 1024).toFixed(1)} MiB)`);
}

async function main(): Promise<void> {
  const arg = process.argv[2];
  if (arg === undefined) {
    console.error("usage: bun scripts/dist.ts <current|darwin-arm64|linux-x64|windows-x64|all>");
    process.exit(1);
  }
  const repoRoot = resolve(dirname(import.meta.dir));

  const targets: Target[] = arg === "current"
    ? [currentTarget()]
    : arg === "all"
      ? [...TARGETS]
      : isTarget(arg)
        ? [arg]
        : (() => { throw new Error(`unknown target: ${arg}`); })();

  for (const t of targets) await buildOne(t, repoRoot);
}

await main();
