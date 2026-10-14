// `for c in s` steps `StringChars`, whose `next` reads the string in place. In a
// release build it must be inlined into the caller's loop across the module
// boundary, or the loop pays one call per character: `next` has to stay under
// clang's ThinLTO inlining limits. A debug build of the same program keeps the
// symbol, which shows the name looked for is the one the emitter writes. The limits
// are clang's, so the check runs where the host compiler is Apple's.
import { expect, test } from "bun:test";
import { mkdtempSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { LONG_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const SOURCE = `module "snippet"

import "std/io"
import "std/string"

main :: fn() -> i32 {
    n: u32 = 0
    for c in "héllo" {
        n += u32(c)
    }
    println(n)
    return 0
}
`;

// 104 + 233 + 108 + 108 + 111, the codepoints of "héllo".
const CODEPOINT_SUM = "664\n";

const NEXT_SYMBOL = "std_string_StringChars_Iterator_next";

async function build(src: string, bin: string, flags: string[]): Promise<void> {
  const result = await runCli(["build", ...flags, `--out=${bin}`, src], undefined, LONG_BUILD);
  expect(result.exit).toBe(0);
}

async function symbolsOf(bin: string): Promise<string> {
  const symbols = await spawnCapture([bin], { bin: "/usr/bin/nm" });
  expect(symbols.exit).toBe(0);
  return symbols.stdout;
}

test.skipIf(process.platform !== "darwin")(
  "a release build inlines the string iterator's next into the loop",
  async () => {
    if (!(await haveCc())) return;
    const dir = mkdtempSync(join(tmpdir(), "vader-chars-inlined-"));
    const src = join(dir, "main.vader");
    writeFileSync(src, SOURCE);

    const debug = join(dir, "debug");
    await build(src, debug, []);
    expect(await symbolsOf(debug)).toContain(NEXT_SYMBOL);

    const release = join(dir, "release");
    await build(src, release, ["--release"]);
    const run = await spawnCapture([], { bin: release });
    expect(run.stdout).toBe(CODEPOINT_SUM);
    expect(await symbolsOf(release)).not.toContain(NEXT_SYMBOL);
  },
  LONG_BUILD,
);
