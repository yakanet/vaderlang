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

export async function cmdDump(args: string[]): Promise<number> {
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

  console.error(
    `vader dump: not yet implemented (stage=${stage}, file=${file})`,
  );
  return 2;
}
