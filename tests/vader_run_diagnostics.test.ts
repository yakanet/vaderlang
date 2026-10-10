// `vader run <file>` reports a lowering diagnostic and stops, as `build` does. A
// lowering error puts an `unreachable` where it could not lower, so a run that went
// ahead would cut the function short with nothing said, or, as here, trap on a
// message that names the symptom instead of the diagnostic.

import { test, expect } from "bun:test";
import { join } from "node:path";
import { runCli, MEDIUM_BUILD, LONG_BUILD } from "./cli-bin.ts";

const FIXTURE = join(
  import.meta.dir,
  "diag_corpus/lower/m5001_string_iterator_not_imported/_main.vader",
);

test("run stops on a lowering error and reports it", async () => {
  const r = await runCli(["run", FIXTURE], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("error[M5001]");
  expect(r.stderr).not.toContain("reached unreachable");
}, LONG_BUILD);
