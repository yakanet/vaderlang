import type { GlobalOpts } from "../cli/options.ts";

export async function cmdTest(_opts: GlobalOpts, args: string[]): Promise<number> {
  const path = args[0] ?? ".";
  console.error(`vader test: not yet implemented (would scan ${path} for @test)`);
  return 2;
}
