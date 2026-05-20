import { join } from "node:path";

import type { GlobalOpts } from "../options.ts";
import { renderAllJson, renderAllTextSingle } from "../../diagnostics/render.ts";
import { pipelineBytecode, type BytecodeResult } from "../../pipeline.ts";
import { writeVir } from "../../bytecode/text.ts";
import { writeBinary } from "../../bytecode/binary.ts";
import { emitC } from "../../c_emit/emit.ts";
import { runtimeRoots } from "../../runtime-resources.ts";

type Target = "native" | "wasm" | "ir" | "ir-text" | "c";

const TARGETS: readonly Target[] = ["native", "wasm", "ir", "ir-text", "c"] as const;

function isTarget(s: string): s is Target {
  return (TARGETS as readonly string[]).includes(s);
}

export async function cmdBuild(opts: GlobalOpts, args: string[]): Promise<number> {
  // Pre-strip `-o <path>` (POSIX style) so it joins `--out=<path>` semantics.
  // Without this the parser would treat `-o` and its value as positionals
  // and silently drop the override — the binary still lands at the default
  // path while the user thinks they redirected it.
  const stripped: string[] = [];
  let shortOut: string | undefined;
  for (let i = 0; i < args.length; i++) {
    const arg = args[i];
    if (arg === undefined) continue;
    if (arg === "-o" && i + 1 < args.length) {
      shortOut = args[i + 1];
      i++;
      continue;
    }
    stripped.push(arg);
  }
  const positional = stripped.filter((a) => !a.startsWith("--"));
  const flags = stripped.filter((a) => a.startsWith("--"));

  const file = positional[0];
  const targetRaw =
    flags.find((f) => f.startsWith("--target="))?.slice("--target=".length) ??
    "native";
  const useManifest = flags.includes("--manifest");
  const outFlag = flags.find((f) => f.startsWith("--out="))?.slice("--out=".length) ?? shortOut;
  const release = flags.includes("--release");
  // C compiler selection : --cc=<path> wins over the CC env var, both fall back
  // to "cc" (POSIX default). The chosen compiler is used as-is — pass a
  // cross-compiler like `x86_64-w64-mingw32-gcc` to target Windows.
  const ccFlag =
    flags.find((f) => f.startsWith("--cc="))?.slice("--cc=".length) ??
    process.env.CC ??
    "cc";
  // `--ldflags="..."` — raw passthrough to the linker (the cc invocation
  // appends every token before `-o`). Used for `@extern` user imports to
  // pull in helper `.o` files or system libs (`-lcrypto`, `-L/path`, …).
  const ldflagsFlag =
    flags.find((f) => f.startsWith("--ldflags="))?.slice("--ldflags=".length) ?? "";

  if (!isTarget(targetRaw)) {
    console.error(`vader build: unknown target "${targetRaw}"`);
    console.error(`targets: ${TARGETS.join(", ")}`);
    return 1;
  }
  const target: Target = targetRaw;

  if (!file && !useManifest) {
    console.error("vader build: expected either a file or --manifest (vader.json)");
    return 1;
  }

  if (target === "ir" || target === "ir-text") {
    if (!file) {
      console.error(`vader build --target=${target}: --manifest mode not yet implemented`);
      return 2;
    }
    return await buildIr(opts, file, outFlag, target === "ir-text");
  }

  if (target === "native") {
    if (!file) {
      console.error("vader build --target=native: --manifest mode not yet implemented");
      return 2;
    }
    return await buildNative(opts, file, outFlag, release, ccFlag, ldflagsFlag);
  }

  if (target === "c") {
    if (!file) {
      console.error("vader build --target=c: --manifest mode not yet implemented");
      return 2;
    }
    return await buildC(opts, file, outFlag);
  }

  console.error(`vader build: not yet implemented (target=${target}, file=${file ?? "(manifest)"})`);
  return 2;
}

async function buildNative(
  opts: GlobalOpts, file: string, outPath: string | undefined, release: boolean, cc: string,
  ldflags: string,
): Promise<number> {
  const r = await pipelineBytecode(file, { allowEnv: opts.allowEnv, bytecodeOpt: opts.bytecodeOpt });
  if (!flushDiagnostics(r, opts, file)) return 1;

  // Emit the .c next to the binary so it's inspectable. Naming: `<out>.c` so
  // `vader build foo.vader --target=native` produces both `foo` and `foo.c`.
  // We append `.exe` when (a) the host is Windows, or (b) the user pointed at
  // a mingw cross-compiler — its triplet ends in `mingw32-gcc` /
  // `mingw32-cc` so the output is a Windows binary regardless of host.
  let out = outPath ?? file.replace(/\.vader$/, "");
  const isWindowsOut = process.platform === "win32" || /mingw32-(gcc|cc|g\+\+)?$/.test(cc);
  if (isWindowsOut && !/\.[A-Za-z0-9]+$/.test(out)) out += ".exe";
  const cFile = `${out}.c`;
  await Bun.write(cFile, emitC(r.bytecode, { release }));

  // Default (debug) builds : `-O0 -ggdb` — cc stays fast, lldb/gdb get full
  // line tables and locals. `--release` flips to `-O3 -DNDEBUG` (no debug
  // info, asserts off) for production binaries.
  const optFlags = release ? ["-O3", "-DNDEBUG"] : ["-O0", "-ggdb"];
  const runtimeRoot = runtimeRoots().cRuntimeRoot;
  // `-lm` is needed on Linux/glibc to satisfy the `floor` / `fmod` references
  // in the runtime's float-formatting helpers ; macOS clang and Windows
  // MinGW fold libm into libc so the flag is a no-op there.
  // Whitespace-split user --ldflags into argv tokens. Keep it boring : no
  // shell quoting / escaping — if a path contains spaces, the user files
  // a bug. Tokens are appended before `-o` so they can refer to the .c
  // unit (e.g. unresolved-symbol references back to `vader_…` helpers).
  const userLdflags = ldflags.trim().length > 0 ? ldflags.trim().split(/\s+/) : [];
  const proc = Bun.spawn([
    cc, "-std=c11", ...optFlags, "-I", runtimeRoot,
    cFile, join(runtimeRoot, "vader_runtime.c"),
    ...userLdflags,
    "-o", out, "-lm",
  ], { stderr: "pipe", stdout: "ignore" });
  // Drain stderr concurrently with the exit await — gcc on Ubuntu can emit
  // a verbose warning burst (the codegen produces a handful of -Winteger-
  // overflow lines per i64-min literal, and gcc tends to be louder than
  // clang) that saturates the 64 KB pipe buffer and deadlocks the child
  // when nothing reads from the pipe.
  const [err, code] = await Promise.all([
    new Response(proc.stderr).text(),
    proc.exited,
  ]);
  if (code !== 0) {
    console.error(`vader build: ${cc} failed (exit ${code})`);
    console.error(err);
    console.error(`(generated C kept at ${cFile})`);
    return 1;
  }

  // Best-effort post-link strip on release : matches Cargo ≥1.77 / Go
  // convention. We pick `strip` from the same toolchain as `cc` when the user
  // pointed at a cross-compiler (e.g. `x86_64-w64-mingw32-gcc` →
  // `x86_64-w64-mingw32-strip`) ; fall back to plain `strip` otherwise. The
  // call is best-effort — failure means the binary is just larger, never
  // broken.
  if (release) {
    const stripCmd = cc.replace(/-(gcc|cc|g\+\+)$/, "-strip");
    const stripExe = stripCmd === cc ? "strip" : stripCmd;
    try {
      const stripProc = Bun.spawn([stripExe, out], { stderr: "ignore", stdout: "ignore" });
      await stripProc.exited;
    } catch {}
  }
  console.error(`vader build: wrote ${out} (and ${cFile})${release ? " [release]" : ""}`);
  return 0;
}

async function buildC(opts: GlobalOpts, file: string, outPath: string | undefined): Promise<number> {
  const r = await pipelineBytecode(file, { allowEnv: opts.allowEnv, bytecodeOpt: opts.bytecodeOpt });
  if (!flushDiagnostics(r, opts, file)) return 1;
  const out = outPath ?? file.replace(/\.vader$/, ".c");
  await Bun.write(out, emitC(r.bytecode));
  return 0;
}

function flushDiagnostics(r: BytecodeResult, opts: GlobalOpts, file: string): boolean {
  const sorted = r.diagnostics.sorted();
  if (sorted.length > 0) {
    console.error(opts.diagnostics === "json"
      ? renderAllJson(sorted)
      : renderAllTextSingle(sorted, file, r.source));
  }
  return !sorted.some((d) => d.severity === "error");
}

async function buildIr(
  opts: GlobalOpts, file: string, outPath: string | undefined, asText: boolean,
): Promise<number> {
  const r = await pipelineBytecode(file, { allowEnv: opts.allowEnv, bytecodeOpt: opts.bytecodeOpt });
  const sorted = r.diagnostics.sorted();
  if (sorted.length > 0) {
    console.error(opts.diagnostics === "json"
      ? renderAllJson(sorted)
      : renderAllTextSingle(sorted, file, r.source));
  }
  if (sorted.some((d) => d.severity === "error")) return 1;

  const ext = asText ? ".virt" : ".vir";
  const out = outPath ?? file.replace(/\.vader$/, ext);
  if (asText) {
    await Bun.write(out, writeVir(r.bytecode));
  } else {
    await Bun.write(out, writeBinary(r.bytecode));
  }
  return 0;
}
