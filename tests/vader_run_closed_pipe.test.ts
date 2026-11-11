// tests/vader_run_closed_pipe: `vader run` of a program printing into a pipe
// whose reader has gone.
//
// A write to stdout whose reader is gone ends the program as SIGPIPE would, so
// `vader run p.vader | head -c 1` ends once `head` has, rather than printing
// forever. POSIX only: the pipeline is a `sh` one.

import { expect, test } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join, resolve } from "node:path";
import { CLI_BIN, LONG_BUILD, spawnCapture } from "./cli-bin.ts";

const PRINTS_FOREVER =
  'module "probe"\n\nimport "std/console"\n\nmain :: fn() -> i32 {\n    for {\n        println("x")\n    }\n}\n';

test.skipIf(process.platform === "win32")(
  "a program printing past its reader stops once `head` has gone",
  async () => {
    // A folder of its own: the program's module is every `.vader` file beside it.
    const dir = mkdtempSync(join(tmpdir(), "vader-run-closed-pipe-"));
    try {
      const source = join(dir, "main.vader");
      writeFileSync(source, PRINTS_FOREVER);
      const pipeline = ["-c", '"$0" run "$1" | head -c 1', resolve(CLI_BIN), source];
      const { stdout, exit } = await spawnCapture(pipeline, { bin: "/bin/sh", timeoutMs: 60_000 });
      expect(stdout).toBe("x");
      expect(exit).toBe(0);
    } finally {
      rmSync(dir, { recursive: true, force: true });
    }
  },
  LONG_BUILD,
);
