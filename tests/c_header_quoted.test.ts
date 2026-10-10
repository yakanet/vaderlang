// A quoted `@c_header` resolves against the entry file's directory, wherever
// `--out` writes the generated C (SPEC §FFI, `@c_header`). The build hands that
// directory to `cc` as `-iquote`; without it, a binary written elsewhere fails to
// compile with "'my.h' file not found". Both the split build (the default) and the
// single-unit one are checked, since they assemble their `cc` lines separately.
import { expect, test } from "bun:test";
import { mkdirSync, mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { EXE_SUFFIX, LONG_BUILD, haveCc, runCli, spawnCapture } from "./cli-bin.ts";

const SOURCE = `module "main"

import "std/io"

@c_header("\\"my.h\\"")
@extern("abs")
c_abs :: fn(x: i32) -> i32

main :: fn() -> i32 {
    println("\${c_abs(-7)}")
    return 0
}
`;

// An entry with `my.h` beside it, and an empty output directory elsewhere. A
// `vader.h` beside the entry must not stand in for the runtime's: the generated C
// includes it quoted, and `-iquote <runtime>` comes first.
function stageProject(): { root: string; entry: string; outDir: string } {
  const root = mkdtempSync(join(tmpdir(), "vader-c-header-"));
  const src = join(root, "src");
  const outDir = join(root, "out");
  mkdirSync(src);
  mkdirSync(outDir);
  writeFileSync(join(src, "my.h"), "#include <stdlib.h>\n");
  writeFileSync(join(src, "vader.h"), "#error the runtime's vader.h was shadowed\n");
  const entry = join(src, "main.vader");
  writeFileSync(entry, SOURCE);
  return { root, entry, outDir };
}

for (const [label, flags] of [["split", []], ["single-unit", ["--no-split"]]] as const) {
  test(`a quoted @c_header beside the entry compiles with --out elsewhere (${label})`, async () => {
    if (!(await haveCc())) return;
    const { root, entry, outDir } = stageProject();
    try {
      const bin = join(outDir, `app${EXE_SUFFIX}`);
      const build = await runCli(["build", ...flags, `--out=${bin}`, entry], undefined, LONG_BUILD);
      expect(build.stderr).not.toContain("file not found");
      expect(build.exit).toBe(0);
      const run = await spawnCapture([], { bin, timeoutMs: 10_000 });
      expect(run.stdout).toBe("7\n");
    } finally {
      rmSync(root, { recursive: true, force: true });
    }
  }, LONG_BUILD);
}
