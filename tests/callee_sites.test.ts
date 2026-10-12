// tests/callee_sites — `vader dump --stage=callees`, what the typecheck settled
// each call of a fixture to invoke.
//
// The fixture holds one call per shape: a plain fn, an overload, a free fn by
// UFCS, an impl member and a materialised default one, a bounded `T`'s member, a
// trait value's and a union's, a static member, a namespace member, a call through
// a parameter, through a field and through a call's result, a cast, an enum's
// built-in equality, an array operation, a generic free fn on a `T` receiver, a
// library fn, and a member several impls offer whose argument holds a call of its
// own. Each expected line is the dump's, position included.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const SITES = join(import.meta.dir, "callee_fixtures", "sites.vader");

const EXPECTED = [
  "clone fn area",
  "clone fn area",
  "sites.vader:72:31 fn double",
  "sites.vader:74:39 fn describe",
  "sites.vader:76:38 fn tag",
  "sites.vader:78:46 fn area",
  "sites.vader:80:49 fn twice",
  "sites.vader:82:47 bound sites$Shape.area",
  "sites.vader:84:45 virtual sites$Shape.area",
  "sites.vader:86:58 virtual sites$Shape.area",
  "sites.vader:88:39 fn origin",
  "sites.vader:91:10 bound sites$Origin.origin",
  "sites.vader:94:48 fn sqrt",
  "sites.vader:96:54 value",
  "sites.vader:98:46 value",
  "sites.vader:100:36 builtin",
  "sites.vader:102:46 builtin",
  "sites.vader:104:45 fn len",
  "sites.vader:106:43 fn same (per instance)",
  "sites.vader:108:34 fn println",
  "sites.vader:110:55 fn scaled",
  "sites.vader:110:64 fn scaled",
  "sites.vader:112:40 fn make",
  "sites.vader:112:40 value",
  "calls: 24, unsettled: 0",
];

test("the typecheck settles what each call of the fixture invokes", async () => {
  const r = await runCli(["dump", "--stage=callees", SITES], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("# Diagnostics");
  const lines = r.stdout.split("\n").filter((l) => l.startsWith("  ")).map((l) => l.trim());
  expect(lines).toEqual(EXPECTED);
}, MEDIUM_BUILD);
