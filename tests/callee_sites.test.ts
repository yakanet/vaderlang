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
// an impl, a string's index and an array's. Last the conversions: a cast through
// `Into`, an implicit `into` into a typed local, an array handed to an `Iterator`
// parameter, and a distinct converted into its own backing, which runs no `into`.
// And the `for` loops: over an array, an integer range, an `Iterator`, a type that
// only converts into one, a generator, a string, an `Iterator` trait value, a
// `char` range, a type parameter bounded by `Iterator`, and `for xs { }` over an
// array. Each expected line is the dump's, position included.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const SITES = join(import.meta.dir, "callee_fixtures", "sites.vader");

const EXPECTED = [
  "clone call fn area",
  "clone call fn area",
  "sites.vader:12:31 operator builtin",
  "sites.vader:55:62 operator builtin",
  "sites.vader:59:65 operator builtin",
  "sites.vader:69:63 operator builtin",
  "sites.vader:73:51 operator builtin",
  "sites.vader:77:48 operator builtin",
  "sites.vader:85:39 index builtin",
  "sites.vader:90:9 index-write builtin",
  "sites.vader:99:48 operator fn contains",
  "sites.vader:103:46 call fn len",
  "sites.vader:103:46 operator builtin",
  "sites.vader:103:66 call fn len",
  "sites.vader:111:31 call builtin",
  "sites.vader:117:31 call builtin",
  "sites.vader:126:12 operator builtin",
  "sites.vader:129:18 operator builtin",
  "sites.vader:143:14 iter-next builtin",
  "sites.vader:144:15 operator builtin",
  "sites.vader:150:14 iter-next virtual std_core$Iterator.next",
  "sites.vader:151:9 operator builtin",
  "sites.vader:165:31 call fn double",
  "sites.vader:167:39 call fn describe",
  "sites.vader:169:38 call fn tag",
  "sites.vader:171:46 call fn area",
  "sites.vader:173:49 call fn twice",
  "sites.vader:175:47 call bound sites$Shape.area",
  "sites.vader:177:45 call virtual sites$Shape.area",
  "sites.vader:179:58 call virtual sites$Shape.area",
  "sites.vader:181:39 call fn origin",
  "sites.vader:184:10 call bound sites$Origin.origin",
  "sites.vader:187:48 call fn sqrt",
  "sites.vader:189:54 call value",
  "sites.vader:191:46 call value",
  "sites.vader:193:36 call builtin",
  "sites.vader:195:46 call builtin",
  "sites.vader:197:45 call fn len",
  "sites.vader:199:43 call fn same (per instance)",
  "sites.vader:201:34 call fn println",
  "sites.vader:203:55 call fn scaled",
  "sites.vader:203:64 call fn scaled",
  "sites.vader:205:40 call fn make",
  "sites.vader:205:40 call value",
  "sites.vader:207:61 operator fn add",
  "sites.vader:209:60 operator fn compare",
  "sites.vader:211:58 operator bound std_core$Add.add",
  "sites.vader:213:60 operator fn equals",
  "sites.vader:215:73 operator fn equals",
  "sites.vader:217:71 operator fn equals",
  "sites.vader:219:72 operator fn equals",
  "sites.vader:221:75 operator each(fn equals, fn equals)",
  "sites.vader:223:64 operator bound std_core$Equals.equals",
  "sites.vader:225:53 operator builtin",
  "sites.vader:227:59 operator bound std_core$Equals.equals",
  "sites.vader:229:42 operator fn contains",
  "sites.vader:231:43 index fn at",
  "sites.vader:234:5 index-write fn set_at",
  "sites.vader:238:5 index fn at",
  "sites.vader:238:5 index-write fn set_at",
  "sites.vader:238:5 operator builtin",
  "sites.vader:241:48 index fn at",
  "sites.vader:243:46 index builtin",
  "sites.vader:245:52 call builtin",
  "sites.vader:245:56 into fn into",
  "sites.vader:248:13 into fn into",
  "sites.vader:252:47 call fn walk",
  "sites.vader:252:52 into fn into",
  "sites.vader:255:13 into builtin",
  "sites.vader:261:14 iter-next builtin",
  "sites.vader:262:9 operator builtin",
  "sites.vader:269:14 iter-next builtin",
  "sites.vader:270:9 operator builtin",
  "sites.vader:277:14 iter-next fn next",
  "sites.vader:278:9 operator builtin",
  "sites.vader:285:14 iter-into fn into",
  "sites.vader:285:14 iter-next virtual std_core$Iterator.next",
  "sites.vader:286:9 operator builtin",
  "sites.vader:293:14 call fn evens",
  "sites.vader:293:14 iter-next fn evens",
  "sites.vader:294:9 operator builtin",
  "sites.vader:301:14 iter-into fn into",
  "sites.vader:301:14 iter-next virtual std_core$Iterator.next",
  "sites.vader:302:9 operator builtin",
  "sites.vader:309:14 iter-next builtin",
  "sites.vader:310:9 operator builtin",
  "sites.vader:317:14 iter-next bound std_core$Iterator.next",
  "sites.vader:318:9 operator builtin",
  "sites.vader:325:9 iter-next builtin",
  "sites.vader:326:9 operator builtin",
  "sites: 90, unsettled: 0",
];

test("the typecheck settles what each site of the fixture invokes", async () => {
  const r = await runCli(["dump", "--stage=callees", SITES], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("# Diagnostics");
  const lines = r.stdout.split("\n").filter((l) => l.startsWith("  ")).map((l) => l.trim());
  expect(lines).toEqual(EXPECTED);
}, MEDIUM_BUILD);
