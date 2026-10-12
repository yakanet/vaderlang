// tests/callee_sites — `vader dump --stage=callees`, what the typecheck settled
// each call of a fixture to invoke.
//
// The fixture holds one call per shape: a plain fn, an overload, a free fn by
// UFCS, an impl member and a materialised default one, a bounded `T`'s member, a
// trait value's and a union's, a static member, a namespace member, a call through
// a parameter, through a field and through a call's result, a cast, an enum's
// built-in equality, an array operation, a generic free fn on a `T` receiver, a
// library fn, and a member several impls offer whose argument holds a call of its
// own. Then the sites with no call expression: a struct's operator, ordering and
// `==`, a bounded operator and `==`, a structural `==` on a tuple and on a union
// (against a union and against one of its variants), `== null` on a nullable and
// on a bare type parameter, a custom `in`, an index read, write and update through
// an impl, a string's index and an array's. Each expected line is the dump's,
// position included.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const SITES = join(import.meta.dir, "callee_fixtures", "sites.vader");

const EXPECTED = [
  "clone call fn area",
  "clone call fn area",
  "sites.vader:11:31 operator builtin",
  "sites.vader:54:62 operator builtin",
  "sites.vader:58:65 operator builtin",
  "sites.vader:68:63 operator builtin",
  "sites.vader:72:51 operator builtin",
  "sites.vader:76:48 operator builtin",
  "sites.vader:84:39 index builtin",
  "sites.vader:89:9 index-write builtin",
  "sites.vader:98:48 operator fn contains",
  "sites.vader:102:46 call fn len",
  "sites.vader:102:46 operator builtin",
  "sites.vader:102:66 call fn len",
  "sites.vader:114:31 call fn double",
  "sites.vader:116:39 call fn describe",
  "sites.vader:118:38 call fn tag",
  "sites.vader:120:46 call fn area",
  "sites.vader:122:49 call fn twice",
  "sites.vader:124:47 call bound sites$Shape.area",
  "sites.vader:126:45 call virtual sites$Shape.area",
  "sites.vader:128:58 call virtual sites$Shape.area",
  "sites.vader:130:39 call fn origin",
  "sites.vader:133:10 call bound sites$Origin.origin",
  "sites.vader:136:48 call fn sqrt",
  "sites.vader:138:54 call value",
  "sites.vader:140:46 call value",
  "sites.vader:142:36 call builtin",
  "sites.vader:144:46 call builtin",
  "sites.vader:146:45 call fn len",
  "sites.vader:148:43 call fn same (per instance)",
  "sites.vader:150:34 call fn println",
  "sites.vader:152:55 call fn scaled",
  "sites.vader:152:64 call fn scaled",
  "sites.vader:154:40 call fn make",
  "sites.vader:154:40 call value",
  "sites.vader:156:61 operator fn add",
  "sites.vader:158:60 operator fn compare",
  "sites.vader:160:58 operator bound std_core$Add.add",
  "sites.vader:162:60 operator fn equals",
  "sites.vader:164:73 operator fn equals",
  "sites.vader:166:71 operator fn equals",
  "sites.vader:168:72 operator fn equals",
  "sites.vader:170:75 operator each(fn equals, fn equals)",
  "sites.vader:172:64 operator bound std_core$Equals.equals",
  "sites.vader:174:53 operator builtin",
  "sites.vader:176:59 operator bound std_core$Equals.equals",
  "sites.vader:178:42 operator fn contains",
  "sites.vader:180:43 index fn at",
  "sites.vader:183:5 index-write fn set_at",
  "sites.vader:187:5 index fn at",
  "sites.vader:187:5 index-write fn set_at",
  "sites.vader:187:5 operator builtin",
  "sites.vader:190:48 index fn at",
  "sites.vader:192:46 index builtin",
  "sites: 55, unsettled: 0",
];

test("the typecheck settles what each site of the fixture invokes", async () => {
  const r = await runCli(["dump", "--stage=callees", SITES], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("# Diagnostics");
  const lines = r.stdout.split("\n").filter((l) => l.startsWith("  ")).map((l) => l.trim());
  expect(lines).toEqual(EXPECTED);
}, MEDIUM_BUILD);
