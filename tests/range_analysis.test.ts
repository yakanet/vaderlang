// tests/range_analysis — `vader dump --stage=ranges`, the range analysis's
// verdict on each array access and checked operation.
//
// The fixture holds one function per case; each expectation lists that
// function's sites in source order as `<operation> -> <verdict>`, positions left
// out so that a change of layout in the fixture does not read as a change of
// verdict. The domain and the transfer steps have their own `@test`s in
// `vader/midir/ranges*.vader`; this pins what the whole analysis concludes on
// the CFG the bytecode emitter receives, and which index checks the emitted C
// keeps once a release build drops the proven ones.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const VERDICTS = join(import.meta.dir, "range_fixtures", "verdicts.vader");
const ELISION = join(import.meta.dir, "range_fixtures", "elision", "elision.vader");

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
  println_keeps_length: ["total + $idx_9 -> unproven", "xs[i] -> proven"],
  call_keeps_length: ["total + $idx_9 -> unproven", "xs[i] -> proven"],
  callee_shortens: ["total + $idx_9 -> unproven", "xs[i] -> unproven"],
  recursive_callee_keeps_length: ["total + $idx_9 -> unproven", "xs[i] -> proven"],
  virtual_call_keeps_length: ["total + $idx_10 -> unproven", "xs[i] -> proven"],
  indirect_call_drops_length: ["total + $idx_10 -> unproven", "xs[i] -> unproven"],
  guarded_decrement: ["n - $k_3 -> proven"],
  unguarded_decrement: ["n - $k_1 -> unproven"],
  always_overflows: ["x + $k_3 -> certain fault"],
  impossible_branch: ["xs[n] -> unreachable"],
  negative_index: ["xs[i] -> certain fault"],
  last_element: ["xs[$sub_checked_3] -> unproven", "$len_1 - $k_2 -> unproven"],
  guarded_last: ["xs[$sub_checked_6] -> proven", "$len_4 - $k_5 -> proven"],
  foreach_element: ["__for_arr_0[__for_i_2] -> proven", "total + x -> unproven"],
  fused_map_element: ["__fuse_arr_0[__fuse_i_2] -> proven", "total + y -> unproven"],
  double: ["x + x -> unproven"],
  fused_chain_elements: [
    "__fuse_arr_0[__fuse_i_3] -> proven",
    "__fuse_arr_1[__fuse_i_5] -> proven",
    "total + z -> unproven",
    "total + z -> unproven",
  ],
};

test("the range analysis gives each fixture site its verdict", async () => {
  const r = await runCli(["dump", "--stage=ranges", VERDICTS], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("# Diagnostics");
  expect(Object.fromEntries(sitesByFunction(r.stdout))).toEqual(EXPECTED);
}, MEDIUM_BUILD);

test("VADER_OPT_REPORT totals the verdicts and lists each certain fault", async () => {
  const r = await runCli(["dump", "--stage=ranges", VERDICTS], { VADER_OPT_REPORT: "1" }, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stderr).toContain("[VADER_OPT_REPORT] range analysis");
  expect(r.stderr).toContain("x + $k_3 in verdicts$always_overflows");
  expect(r.stderr).toContain("xs[i] in verdicts$negative_index");
  expect(r.stderr).toContain("without call summaries:");
  expect(r.stderr).toContain("functions may shorten an array");
}, MEDIUM_BUILD);

/** The index-check macros in the C definition of `elision$<name>`, in order. */
function checksIn(c: string, name: string): string[] {
  const start = c.search(new RegExp(`^static \\S.* elision_${name}\\(.*\\) \\{$`, "m"));
  expect(start).toBeGreaterThanOrEqual(0);
  const body = c.slice(start, c.indexOf("\n}\n", start));
  return body.match(/VADER_ARRAY_CHECK_[A-Z]+/g) ?? [];
}

/** The C a native build of the elision fixture emits, `--out=-` streaming it. */
async function nativeC(flags: string[], env?: Record<string, string>): Promise<string> {
  const r = await runCli(["build", ...flags, "--emit=c", "--out=-", ELISION], env, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  return r.stdout;
}

test("a release build drops the index check of a proven access only", async () => {
  const c = await nativeC(["--release"]);
  expect(checksIn(c, "proven_access")).toEqual([]);
  expect(checksIn(c, "unproven_access")).toEqual(["VADER_ARRAY_CHECK_INDEX"]);
}, MEDIUM_BUILD);

test("a debug build keeps the check of an access the range analysis proves", async () => {
  const c = await nativeC([]);
  expect(checksIn(c, "proven_access")).toEqual(["VADER_ARRAY_CHECK_INDEX"]);
  expect(checksIn(c, "unproven_access")).toEqual(["VADER_ARRAY_CHECK_INDEX"]);
}, MEDIUM_BUILD);

test("VADER_VERIFY_BOUNDS keeps a proven access's check under a message of its own", async () => {
  for (const flags of [[], ["--release"]]) {
    const c = await nativeC(flags, { VADER_VERIFY_BOUNDS: "1" });
    expect(checksIn(c, "proven_access")).toEqual(["VADER_ARRAY_CHECK_PROVEN"]);
    expect(checksIn(c, "unproven_access")).toEqual(["VADER_ARRAY_CHECK_INDEX"]);
  }
  // The parity tests' path: `dump --stage=c`.
  const dump = await runCli(["dump", "--stage=c", ELISION], { VADER_VERIFY_BOUNDS: "1" }, MEDIUM_BUILD);
  expect(dump.exit).toBe(0);
  expect(checksIn(dump.stdout, "proven_access")).toEqual(["VADER_ARRAY_CHECK_PROVEN"]);
}, MEDIUM_BUILD);
