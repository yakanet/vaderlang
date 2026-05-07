import { join, resolve } from "node:path";

import type { GlobalOpts } from "../cli/options.ts";
import { renderAllJson, renderAllTextSingle } from "../diagnostics/render.ts";
import { pipelineBytecode, type BytecodeResult } from "../pipeline.ts";
import { writeVir } from "../bytecode/text.ts";
import { emitC } from "../c_emit/emit.ts";

type Target = "native" | "wasm" | "ir" | "c";

const TARGETS: readonly Target[] = ["native", "wasm", "ir", "c"] as const;

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

  if (target === "ir") {
    if (!file) {
      console.error("vader build --target=ir: --manifest mode not yet implemented");
      return 2;
    }
    return await buildIr(opts, file, outFlag);
  }

  if (target === "native") {
    if (!file) {
      console.error("vader build --target=native: --manifest mode not yet implemented");
      return 2;
    }
    return await buildNative(opts, file, outFlag);
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

async function buildNative(opts: GlobalOpts, file: string, outPath: string | undefined): Promise<number> {
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

  const runtimeRoot = resolve(import.meta.dir, "../../runtime/c");
  const proc = Bun.spawn([
    "cc", "-std=c11", "-O0", "-I", runtimeRoot,
    cFile, join(runtimeRoot, "vader_runtime.c"), "-o", out,
  ], { stderr: "pipe", stdout: "pipe" });
  const code = await proc.exited;
  if (code !== 0) {
    const err = await new Response(proc.stderr).text();
    console.error(`vader build: cc failed (exit ${code})`);
    console.error(err);
    console.error(`(generated C kept at ${cFile})`);
    return 1;
  }
  console.error(`vader build: wrote ${out} (and ${cFile})`);
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

async function buildIr(opts: GlobalOpts, file: string, outPath: string | undefined): Promise<number> {
  const r = await pipelineBytecode(file, { allowEnv: opts.allowEnv, bytecodeOpt: opts.bytecodeOpt });
  const sorted = r.diagnostics.sorted();
  if (sorted.length > 0) {
    console.error(opts.diagnostics === "json"
      ? renderAllJson(sorted)
      : renderAllTextSingle(sorted, file, r.source));
  }
  if (sorted.some((d) => d.severity === "error")) return 1;

  const out = outPath ?? file.replace(/\.vader$/, ".vir");
  await Bun.write(out, writeVir(r.bytecode));
  return 0;
}
