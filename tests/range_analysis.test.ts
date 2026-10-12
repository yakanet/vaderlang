// tests/range_analysis — `vader dump --stage=ranges`, the range analysis's
// verdict on each array access and checked operation.
//
// The fixture holds one function per case; each expectation lists that
// function's sites in source order as `<operation> -> <verdict>`, positions left
// out so that a change of layout in the fixture does not read as a change of
// verdict. The domain and the transfer steps have their own `@test`s in
// `vader/midir/ranges*.vader`; this pins what the whole analysis concludes on
// the CFG the bytecode emitter receives.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const VERDICTS = join(import.meta.dir, "range_fixtures", "verdicts.vader");

/** Each function's sites, `<operation> -> <verdict>` in source order. */
function sitesByFunction(dump: string): Map<string, string[]> {
  const out = new Map<string, string[]>();
  let current: string[] | null = null;
  for (const line of dump.split("\n")) {
    const fn = line.match(/^fn \S+\$(\S+)$/)?.[1];
    if (fn !== undefined) {
      current = [];
      out.set(fn, current);
      continue;
    }
    const site = line.match(/^ {2}\d+:\d+ (.*)$/)?.[1];
    if (site !== undefined && current) current.push(site);
  }
  return out;
}

const EXPECTED: Record<string, string[]> = {
  indexed_loop: ["total + $idx_8 -> unproven", "xs[i] -> proven"],
  early_exit: ["xs[$k_5] -> proven", "$idx_6 + $idx_8 -> unproven", "xs[$k_7] -> proven"],
  counter_below_bound: ["i + $k_4 -> proven"],
  push_keeps_length: ["total + $idx_9 -> unproven", "xs[i] -> proven"],
  call_drops_length: ["total + $idx_9 -> unproven", "xs[i] -> unproven"],
  guarded_decrement: ["n - $k_3 -> proven"],
  unguarded_decrement: ["n - $k_1 -> unproven"],
  always_overflows: ["x + $k_3 -> certain fault"],
  impossible_branch: ["xs[n] -> unreachable"],
  negative_index: ["xs[i] -> certain fault"],
  last_element: ["xs[$sub_checked_3] -> unproven", "$len_1 - $k_2 -> unproven"],
  guarded_last: ["xs[$sub_checked_6] -> proven", "$len_4 - $k_5 -> proven"],
};

test("the range analysis gives each fixture site its verdict", async () => {
  const r = await runCli(["dump", "--stage=ranges", VERDICTS], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("# Diagnostics");
  expect(Object.fromEntries(sitesByFunction(r.stdout))).toEqual(EXPECTED);
}, MEDIUM_BUILD);
