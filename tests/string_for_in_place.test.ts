// `for c in s` walks the string in place: `string`'s `into` is a generator, and a
// `for` fuses a generator `into` into its loop. No `StringChars` is stepped, so
// its `next` is not even emitted: the lowering decides it, whatever the build mode.
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

test.skipIf(process.platform === "win32")(
  "a for over a string steps no iterator",
  async () => {
    if (!(await haveCc())) return;
    const dir = mkdtempSync(join(tmpdir(), "vader-string-for-"));
    const src = join(dir, "main.vader");
    writeFileSync(src, SOURCE);
    const bin = join(dir, "main");
    const built = await runCli(["build", `--out=${bin}`, src], undefined, LONG_BUILD);
    expect(built.exit).toBe(0);

    expect((await spawnCapture([], { bin })).stdout).toBe(CODEPOINT_SUM);
    const symbols = await spawnCapture([bin], { bin: "/usr/bin/nm" });
    expect(symbols.exit).toBe(0);
    expect(symbols.stdout).not.toContain(NEXT_SYMBOL);
  },
  LONG_BUILD,
);
