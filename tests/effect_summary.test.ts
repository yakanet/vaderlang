// tests/effect_summary — `vader dump --stage=effects`, what each function does
// with what it is lent.
//
// The fixture holds one function per case; each expectation lists that
// function's accesses as the dump writes them, `<effect> <parameter><path>`, or
// `none`. Positions are left out, so that a change of layout in the fixture does
// not read as a change of summary. The paths, the sets and the evaluation of a
// body's constraints have their own `@test`s in `vader/effects/`; this pins what
// the walk and the fixed point conclude on a typed program.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const SUMMARIES = join(import.meta.dir, "effect_fixtures", "summaries", "summaries.vader");
const FROZEN = join(import.meta.dir, "effect_fixtures", "frozen", "frozen.vader");
const VARIANCE = join(import.meta.dir, "effect_fixtures", "variance", "variance.vader");
const IMPORTED = join(import.meta.dir, "effect_fixtures", "imported", "app", "main.vader");
const COMPILER = join(import.meta.dir, "..", "vader", "cli", "main.vader");

/** Each function of the `summaries` module with its accesses, in source order. */
function functionsOf(dump: string): [string, string[]][] {
  const out: [string, string[]][] = [];
  let current: string[] | null = null;
  let inModule = false;
  for (const line of dump.split("\n")) {
    if (line.startsWith("## ")) {
      inModule = line === "## summaries";
      current = null;
      continue;
    }
    if (!inModule) continue;
    const fn = line.match(/^fn (\S+) \d+:\d+$/)?.[1];
    if (fn !== undefined) {
      current = [];
      out.push([fn, current]);
      continue;
    }
    const access = line.match(/^ {2}(.*)$/)?.[1];
    if (access !== undefined && current) current.push(access);
  }
  return out;
}

const EXPECTED: [string, string[]][] = [
  ["origin", ["none"]],
  ["reads_only", ["none"]],
  ["sets_field", ["assigned p.x"]],
  ["sets_nested_field", ["assigned h.inner.x"]],
  ["sets_element", ["assigned xs[]", "stored p"]],
  ["sets_element_field", ["assigned xs[].x"]],
  ["pushes", ["resized xs", "stored p"]],
  ["clears", ["shrunk xs"]],
  ["through_local", ["resized h.items"]],
  ["through_loop", ["assigned xs[].x"]],
  ["through_narrowing", ["assigned s.x"]],
  ["through_alias", ["shrunk s.items"]],
  ["items_of", ["returned s.items"]],
  ["returns_param", ["returned p"]],
  ["returns_field", ["returned h.inner"]],
  ["writes_what_a_callee_returns", ["assigned h.inner.x"]],
  ["stores_in_struct", ["stored p"]],
  ["captures", ["none"]],
  ["hands_out_its_capture", ["stored p"]],
  ["copies_with_spread", ["stored h.items"]],
  ["calls_a_writer", ["assigned p.x"]],
  ["calls_a_function_value", ["stored p…", "unknown p…"]],
  ["writes_then_recurses", ["shrunk xs"]],
  ["recurses_back", ["shrunk xs"]],
  ["bump", ["assigned self.x"]],
  ["bump", ["shrunk self.items"]],
  ["through_a_trait_value", ["assigned b.x", "shrunk b.items"]],
  ["through_a_bound", ["assigned t.x", "shrunk t.items"]],
  [
    "into_a_map",
    [
      "assigned m.ekeys[]",
      "assigned m.evals[]",
      "assigned m.index",
      "assigned m.index[]",
      "assigned m.mask",
      "assigned m.size",
      "assigned m.tombs",
      "resized m.ekeys",
      "resized m.evals",
      "stored p",
    ],
  ],
  ["concatenates", ["stored a[]", "stored b[]"]],
  ["bumps_an_entry", ["assigned m.evals[].x"]],
  ["next", ["assigned self.n"]],
  ["drains", ["assigned it.n"]],
  ["yields_points", ["stored xs[]"]],
  ["fills", ["assigned d…"]],
];

test("the effect summary gives each fixture function its accesses", async () => {
  const r = await runCli(["dump", "--stage=effects", SUMMARIES], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("# Diagnostics");
  expect(functionsOf(r.stdout)).toEqual(EXPECTED);
}, MEDIUM_BUILD);

/**
 * A site section of the dump (`# frozen`, `# variance`): each site without its
 * module and position, in source order, then the line of totals that closes it.
 * The chain the dump writes under a fault is left out (`faultChainsOf`).
 */
function sectionSitesOf(dump: string, header: string): string[] {
  const section = dump.slice(dump.indexOf(`\n${header}\n`) + 1);
  const out: string[] = [];
  for (const line of section.split("\n").slice(1)) {
    if (line.startsWith("    ")) continue;
    const site = line.match(/^ {2}\S+ \d+:\d+ (.*)$/)?.[1];
    if (site !== undefined) {
      out.push(site);
      continue;
    }
    out.push(line);
    break;
  }
  return out;
}

// A view only read comes to nothing: it is neither copied nor shared. A read
// narrowed to a type no byte array is does nothing to the view (`keeps_a_failure`).
test("the frozen checks give each use of a frozen value its outcome", async () => {
  const r = await runCli(["dump", "--stage=effects", FROZEN], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(sectionSitesOf(r.stdout, "# frozen")).toEqual([
    "write fault CFG",
    "call fault TABLE",
    "call fault CFG",
    "unknown call CFG",
    "binding shared CFG",
    "binding shared UNTOUCHED",
    "copy CFG",
    "copy CFG",
    "binding shared TABLE",
    "copy elided UNTOUCHED",
    "copy CFG",
    "call fault CFG",
    "call fault CFG",
    "call fault TREE",
    "write fault bytes()",
    "view kept bytes()",
    "view returned bytes()",
    "call fault hands_a_view()",
    "view returned bytes()",
    "write fault: 2, call fault: 6, unknown call: 1, copy: 3, copy elided: 1, binding shared: 3, " +
      "copy unread: 0, view kept: 1, view returned: 2",
  ]);
}, MEDIUM_BUILD);

// Each fault is an error, and so is a kept view, the detail naming what modifies
// the value. A copy of a view is the program's own.
test("the faults and the kept views are errors", async () => {
  const r = await runCli(["check", FROZEN], undefined, MEDIUM_BUILD);
  expect(r.exit).not.toBe(0);
  const codes = [...r.stderr.matchAll(/error\[(T30\d\d)\]/g)].map((m) => m[1]);
  expect(codes).toEqual([
    "T3070", "T3072", "T3072", "T3072", "T3072", "T3072", "T3070", "T3071", "T3072",
  ]);
  expect(r.stderr).toContain(
    "`CFG` is a module constant, and `fill` modifies it through `set` (`c.n` is assigned)",
  );
  expect(r.stderr).toContain(
    "`bytes()` returns a view of a string's bytes, and `bs[]` is assigned",
  );
}, MEDIUM_BUILD);

/**
 * Each fault of the `# frozen` section with the chain the dump writes under it,
 * the positions left out: `[site, [via …, write]]`.
 */
function faultChainsOf(dump: string): [string, string[]][] {
  const section = dump.slice(dump.indexOf("\n# frozen\n") + 1);
  const out: [string, string[]][] = [];
  for (const line of section.split("\n").slice(1)) {
    const step = line.match(/^ {4}(.*) \S+ \d+:\d+$/)?.[1];
    const last = out[out.length - 1];
    if (step !== undefined && last !== undefined) {
      last[1].push(step);
      continue;
    }
    const site = line.match(/^ {2}\S+ \d+:\d+ (.*fault.*)$/)?.[1];
    if (site !== undefined) out.push([site, []]);
    else if (!line.startsWith("  ")) break;
  }
  return out;
}

// A fault names what modifies the frozen value: the calls it is lent down, each
// with the parameter that takes it, and the write at the end, through a recursive
// call too, at the parameter (`fill`) or below it (`clear`, whose cut path stands
// for the tree).
test("each frozen fault leads down its calls to the write", async () => {
  const r = await runCli(["dump", "--stage=effects", FROZEN], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(faultChainsOf(r.stdout)).toEqual([
    ["write fault CFG", ["assigned CFG.n"]],
    ["call fault TABLE", ["resized TABLE by `push`"]],
    ["call fault CFG", ["via `bump` (`c`)", "assigned c.n"]],
    ["call fault CFG", ["via `bump` (`c`)", "assigned c.n"]],
    ["call fault CFG", ["via `fill` (`c`)", "via `set` (`c`)", "assigned c.n"]],
    ["call fault TREE", ["via `clear` (`n`)", "assigned n.kids[]…"]],
    ["write fault bytes()", ["assigned bs[]"]],
    ["call fault hands_a_view()", ["resized hands_a_view() by `push`"]],
  ]);
}, MEDIUM_BUILD);

// A constant reached through a namespace alias or renamed by its import is a use
// like a bare one. A singleton's instance is no constant: a name bound to it
// shares the instance, which the run shows.
test("the frozen checks see constants and singletons of another module", async () => {
  const r = await runCli(["dump", "--stage=effects", IMPORTED], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("# Diagnostics");
  expect(sectionSitesOf(r.stdout, "# frozen")).toEqual([
    "copy CFG",
    "copy CAPS",
    "write fault: 0, call fault: 0, unknown call: 0, copy: 2, copy elided: 0, binding shared: 0, " +
      "copy unread: 0, view kept: 0, view returned: 0",
  ]);
  const run = await runCli(["run", IMPORTED], undefined, MEDIUM_BUILD);
  expect(run.exit).toBe(0);
  expect(run.stdout).toBe("1\n2\n3\n2\n");
}, MEDIUM_BUILD);

test("each widened array argument gets the verdict of its callee", async () => {
  const r = await runCli(["dump", "--stage=effects", VARIANCE], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(sectionSitesOf(r.stdout, "# variance")).toEqual([
    "depth 1 covariant",
    "depth 1 breaks: stored argument",
    "depth 1 breaks: returned argument",
    "depth 1 covariant",
    "depth 1 breaks: unknown argument…",
    "depth 1 covariant",
    "depth 2 covariant",
    "depth 2 breaks: stored argument[]",
    "depth 1 breaks: resized argument",
    "depth 1 covariant",
    "covariant: 5, breaks: 5, unknown callee: 0",
  ]);
}, MEDIUM_BUILD);

// The compiler loads every module of the tree that declares an intrinsic, so its
// summary meets each of them.
test("every intrinsic of the tree has an entry in the effect table", async () => {
  const r = await runCli(
    ["dump", "--stage=effects", "--module=vader/effects", COMPILER],
    undefined,
    MEDIUM_BUILD,
  );
  expect(r.exit).toBe(0);
  expect(r.stdout).toContain("unsettled: 0");
  expect(r.stdout).not.toContain("unknown intrinsic:");
}, MEDIUM_BUILD);
