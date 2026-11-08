// An `@extern` with no header compiles beside another whose header declares the
// same function otherwise: the prototype written from its Vader signature goes to
// a C unit that includes no such header. The split build (the default) and the
// single-unit one assemble their units separately, so both are checked.
import { expect, test } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { EXE_SUFFIX, LONG_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const SOURCE = `module "main"

import "std/console"

// \`int posix_spawnattr_getflags(const posix_spawnattr_t *, short *)\`, which
// only \`<spawn.h>\` declares.
@extern("posix_spawnattr_getflags")
get_flags :: fn(attributes: u8[], @c_out flags: i16[]) -> i32

@c_header("<spawn.h>")
@extern("posix_spawnattr_init")
init_attributes :: fn(@c_out attributes: u8[]) -> i32

main :: fn() -> i32 {
    attributes: u8[]: [0] * 512
    flags: i16[]: [7]
    initialised :: init_attributes(attributes)
    read :: get_flags(attributes, flags)
    println("\${initialised} \${read} \${flags[0]}")
    return 0
}
`;

// `<spawn.h>` does not exist under Windows.
for (const [label, flags] of [["split", []], ["single-unit", ["--no-split"]]] as const) {
  test.skipIf(process.platform === "win32")(
    `an @extern with no header compiles beside a header declaring it otherwise (${label})`,
    async () => {
      if (!(await haveCc())) return;
      const root = mkdtempSync(join(tmpdir(), "vader-extern-without-header-"));
      try {
        const entry = join(root, "main.vader");
        writeFileSync(entry, SOURCE);
        const bin = join(root, `app${EXE_SUFFIX}`);
        const build = await runCli(["build", ...flags, `--out=${bin}`, entry], undefined, LONG_BUILD);
        expect(build.stderr).not.toContain("conflicting types");
        expect(build.exit).toBe(0);
        const run = await spawnCapture([], { bin, timeoutMs: 10_000 });
        expect(run.stdout).toBe("0 0 0\n");
      } finally {
        rmSync(root, { recursive: true, force: true });
      }
    },
    LONG_BUILD,
  );
}
