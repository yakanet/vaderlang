type Target = "native" | "wasm" | "ir";

const TARGETS: readonly Target[] = ["native", "wasm", "ir"] as const;

function isTarget(s: string): s is Target {
  return (TARGETS as readonly string[]).includes(s);
}

export async function cmdBuild(args: string[]): Promise<number> {
  const positional = args.filter((a) => !a.startsWith("--"));
  const flags = args.filter((a) => a.startsWith("--"));

  const file = positional[0];
  const targetRaw =
    flags.find((f) => f.startsWith("--target="))?.slice("--target=".length) ??
    "native";
  const useManifest = flags.includes("--manifest");

  if (!isTarget(targetRaw)) {
    console.error(`vader build: unknown target "${targetRaw}"`);
    console.error(`targets: ${TARGETS.join(", ")}`);
    return 1;
  }
  const target: Target = targetRaw;

  if (!file && !useManifest) {
    console.error(
      "vader build: expected either a file or --manifest (vader.json)",
    );
    return 1;
  }

  console.error(
    `vader build: not yet implemented (target=${target}, file=${file ?? "(manifest)"})`,
  );
  return 2;
}
