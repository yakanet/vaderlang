import { join, resolve } from "node:path";

import type { GlobalOpts } from "../options.ts";
import { renderAllJson, renderAllTextSingle } from "../../diagnostics/render.ts";
import { pipelineBytecode, type BytecodeResult } from "../../pipeline.ts";
import { writeVir } from "../../bytecode/text.ts";
import { writeBinary } from "../../bytecode/binary.ts";
import { emitC } from "../../c_emit/emit.ts";

type Target = "native" | "wasm" | "ir" | "ir-text" | "c";

const TARGETS: readonly Target[] = ["native", "wasm", "ir", "ir-text", "c"] as const;

function isTarget(s: string): s is Target {
  return (TARGETS as readonly string[]).includes(s);
}

export async function cmdBuild(opts: GlobalOpts, args: string[]): Promise<number> {
  const positional = args.filter((a) => !a.startsWith("--"));
  const flags = args.filter((a) => a.startsWith("--"));

  const file = positional[0];
  const targetRaw =
    flags.find((f) => f.startsWith("--target="))?.slice("--target=".length) ??
    "native";
  const useManifest = flags.includes("--manifest");
  const outFlag = flags.find((f) => f.startsWith("--out="))?.slice("--out=".length);
  const release = flags.includes("--release");

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
    return await buildNative(opts, file, outFlag, release);
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
  opts: GlobalOpts, file: string, outPath: string | undefined, release: boolean,
): Promise<number> {
  const r = await pipelineBytecode(file, { allowEnv: opts.allowEnv, bytecodeOpt: opts.bytecodeOpt });
  if (!flushDiagnostics(r, opts, file)) return 1;

  // Emit the .c next to the binary so it's inspectable. Naming: `<out>.c` so
  // `vader build foo.vader --target=native` produces both `foo` and `foo.c`.
  // On Windows append `.exe` if no extension was provided so MSVC/MinGW link
  // produces a runnable binary; non-Windows platforms keep the bare path.
  let out = outPath ?? file.replace(/\.vader$/, "");
  if (process.platform === "win32" && !/\.[A-Za-z0-9]+$/.test(out)) out += ".exe";
  const cFile = `${out}.c`;
  await Bun.write(cFile, emitC(r.bytecode));

  // Default (debug) builds : `-O0 -ggdb` — cc stays fast, lldb/gdb get full
  // line tables and locals. `--release` flips to `-O3 -DNDEBUG` (no debug
  // info, asserts off) for production binaries.
  const optFlags = release ? ["-O3", "-DNDEBUG"] : ["-O0", "-ggdb"];
  const runtimeRoot = resolve(import.meta.dir, "../../../runtime/c");
  const proc = Bun.spawn([
    "cc", "-std=c11", ...optFlags, "-I", runtimeRoot,
    cFile, join(runtimeRoot, "vader_runtime.c"), "-o", out,
  ], { stderr: "pipe", stdout: "ignore" });
  const code = await proc.exited;
  if (code !== 0) {
    const err = await new Response(proc.stderr).text();
    console.error(`vader build: cc failed (exit ${code})`);
    console.error(err);
    console.error(`(generated C kept at ${cFile})`);
    return 1;
  }

  // Best-effort post-link strip on release : matches Cargo ≥1.77 / Go
  // convention. `strip` is in PATH on every Unix-like system that has `cc`
  // (binutils on Linux, llvm-tools on macOS), and absent on bare Windows.
  // We swallow any failure — spawn-not-found OR non-zero exit — because the
  // binary is already valid ; this is purely a size optimisation.
  if (release) {
    try {
      const stripProc = Bun.spawn(["strip", out], { stderr: "ignore", stdout: "ignore" });
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
