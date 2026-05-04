export async function cmdFmt(args: string[]): Promise<number> {
  const path = args[0] ?? ".";
  console.error(`vader fmt: not yet implemented (would format ${path})`);
  return 2;
}
