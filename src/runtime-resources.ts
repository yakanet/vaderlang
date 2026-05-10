// Locate the stdlib, C runtime, and self-host Vader sources regardless of
// whether we run as `bun src/index.ts` (dev) or as a compiled binary shipped
// in an archive (sidecar). The probe order is fixed, the first hit wins, and
// the result is memoized — no need for a "are we packaged?" flag at call sites.
//
// Packaged layout (an archive extracted by the user):
//   vader-<os>-<arch>/
//     vader              <- compiled binary; process.execPath points here
//     stdlib/std/*.vader
//     runtime/c/{vader.h, vader_runtime.c}
//     vader/{cli,fmt,parser,lexer,…}      <- self-host sources loaded by the
//                                            TS host to run `vader fmt` (and
//                                            future tools) through the VM.

import { existsSync } from "node:fs";
import { dirname, resolve } from "node:path";

export interface RuntimeRoots {
  readonly stdlibRoot: string;
  readonly cRuntimeRoot: string;
  readonly vaderRoot: string;
}

let cached: RuntimeRoots | null = null;

export function runtimeRoots(): RuntimeRoots {
  if (cached !== null) return cached;
  cached = probe();
  return cached;
}

function probe(): RuntimeRoots {
  // 1. Sidecar mode: stdlib + runtime/c + vader sit next to the binary.
  const binDir = dirname(process.execPath);
  const sidecarStdlib = resolve(binDir, "stdlib");
  const sidecarCRuntime = resolve(binDir, "runtime", "c");
  const sidecarVader = resolve(binDir, "vader");
  if (
    existsSync(resolve(sidecarStdlib, "std", "io.vader")) &&
    existsSync(resolve(sidecarCRuntime, "vader.h"))
  ) {
    return {
      stdlibRoot: sidecarStdlib,
      cRuntimeRoot: sidecarCRuntime,
      vaderRoot: sidecarVader,
    };
  }

  // 2. Dev mode: this file lives at <repo>/src/runtime-resources.ts, so the
  //    repo root is one level up.
  const repoRoot = resolve(import.meta.dir, "..");
  const devStdlib = resolve(repoRoot, "stdlib");
  const devCRuntime = resolve(repoRoot, "runtime", "c");
  const devVader = resolve(repoRoot, "vader");
  if (existsSync(resolve(devStdlib, "std", "io.vader"))) {
    return {
      stdlibRoot: devStdlib,
      cRuntimeRoot: devCRuntime,
      vaderRoot: devVader,
    };
  }

  // 3. Last resort: cwd-relative. Preserves the historical fallback of
  //    `resolveStdlibRoot` so behavior in surprising setups stays the same.
  const cwd = process.cwd();
  return {
    stdlibRoot: resolve(cwd, "stdlib"),
    cRuntimeRoot: resolve(cwd, "runtime", "c"),
    vaderRoot: resolve(cwd, "vader"),
  };
}
