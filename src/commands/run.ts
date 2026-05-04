import type { GlobalOpts } from "../cli/options.ts";

export async function cmdRun(_opts: GlobalOpts, args: string[]): Promise<number> {
  const file = args[0];
  if (!file) {
    console.error("vader run: expected a file argument");
    return 1;
  }

  const isIr = file.endsWith(".vir");
  console.error(
    `vader run: not yet implemented (would ${isIr ? "load IR from" : "interpret"} ${file})`,
  );
  return 2;
}
