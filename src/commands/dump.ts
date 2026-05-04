import type { GlobalOpts } from "../cli/options.ts";
import { parseSource } from "../parser/pipeline.ts";
import { renderAllJson, renderAllTextSingle } from "../diagnostics/render.ts";

type Stage = "ast" | "typed-ast" | "bytecode" | "c" | "wasm";

const STAGES: readonly Stage[] = [
  "ast",
  "typed-ast",
  "bytecode",
  "c",
  "wasm",
] as const;

function isStage(s: string): s is Stage {
  return (STAGES as readonly string[]).includes(s);
}

export async function cmdDump(opts: GlobalOpts, args: string[]): Promise<number> {
  const stageArg = args.find((a) => a.startsWith("--stage="));
  const positional = args.filter((a) => !a.startsWith("--"));
  const file = positional[0];

  if (!stageArg || !file) {
    console.error("vader dump: expected --stage=<stage> <file>");
    console.error(`stages: ${STAGES.join(", ")}`);
    return 1;
  }

  const stage = stageArg.slice("--stage=".length);
  if (!isStage(stage)) {
    console.error(`vader dump: unknown stage "${stage}"`);
    console.error(`stages: ${STAGES.join(", ")}`);
    return 1;
  }

  if (stage !== "ast") {
    console.error(`vader dump: stage "${stage}" not yet implemented`);
    return 2;
  }

  const source = await Bun.file(file).text();
  const { program, diagnostics } = parseSource(source, file);

  const sorted = diagnostics.sorted();
  if (sorted.length > 0) {
    console.error(opts.diagnostics === "json"
      ? renderAllJson(sorted)
      : renderAllTextSingle(sorted, file, source));
  }

  console.log(JSON.stringify(program, (_k, v) =>
    typeof v === "bigint" ? `${v.toString()}n` : v, 2));

  return sorted.some((d) => d.severity === "error") ? 1 : 0;
}
