export async function cmdTest(args: string[]): Promise<number> {
  const path = args[0] ?? ".";
  console.error(`vader test: not yet implemented (would scan ${path} for @test)`);
  return 2;
}
