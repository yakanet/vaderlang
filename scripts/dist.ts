#!/usr/bin/env bun
// Build a distributable archive containing the Vader binary, the stdlib, and
// the C runtime. Layout:
//
//   dist/vader-<os>-<arch>/
//     vader                       <- compiled binary
//     stdlib/std/*.vader
//     runtime/c/{vader.h, vader_runtime.c}
//
// then gzipped into dist/vader-<os>-<arch>.tar.gz.

import { existsSync, mkdirSync, rmSync } from "node:fs";
import { dirname, join, resolve } from "node:path";

type Target = "darwin-arm64" | "darwin-x64" | "linux-x64";

const TARGETS: readonly Target[] = ["darwin-arm64", "darwin-x64", "linux-x64"];

function isTarget(s: string): s is Target {
  return (TARGETS as readonly string[]).includes(s);
}

function currentTarget(): Target {
  const os = process.platform === "darwin" ? "darwin" : process.platform === "linux" ? "linux" : null;
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

  console.error(`==> ${archiveName}`);

  if (existsSync(outDir)) rmSync(outDir, { recursive: true, force: true });
  mkdirSync(outDir, { recursive: true });

  // 1. Compile the binary.
  await run([
    "bun", "build",
    "--compile",
    "--minify",
    "--sourcemap",
    `--target=bun-${target}`,
    "src/index.ts",
    `--outfile=${join(outDir, "vader")}`,
  ], { cwd: repoRoot });

  // 2. Copy sidecar resources.
  await run(["cp", "-R", join(repoRoot, "stdlib"), join(outDir, "stdlib")]);
  mkdirSync(join(outDir, "runtime"), { recursive: true });
  await run(["cp", "-R", join(repoRoot, "runtime", "c"), join(outDir, "runtime", "c")]);

  // 3. tar.gz the folder.
  const archivePath = join(repoRoot, "dist", `${archiveName}.tar.gz`);
  if (existsSync(archivePath)) rmSync(archivePath);
  await run(["tar", "-czf", archivePath, "-C", join(repoRoot, "dist"), archiveName]);

  const size = (await Bun.file(archivePath).bytes()).byteLength;
  console.error(`    wrote ${archivePath} (${(size / 1024 / 1024).toFixed(1)} MiB)`);
}

async function main(): Promise<void> {
  const arg = process.argv[2];
  if (arg === undefined) {
    console.error("usage: bun scripts/dist.ts <current|darwin-arm64|darwin-x64|linux-x64|all>");
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
