import type { GlobalOpts } from "../cli/options.ts";
import { renderAllJson, renderAllTextSingle } from "../diagnostics/render.ts";
import { pipelineBytecode } from "../pipeline.ts";
import { writeVir } from "../bytecode/text.ts";

type Target = "native" | "wasm" | "ir";

const TARGETS: readonly Target[] = ["native", "wasm", "ir"] as const;

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

  console.error(`vader build: not yet implemented (target=${target}, file=${file ?? "(manifest)"})`);
  return 2;
}

async function buildIr(opts: GlobalOpts, file: string, outPath: string | undefined): Promise<number> {
  const r = await pipelineBytecode(file, { allowEnv: opts.allowEnv });
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
