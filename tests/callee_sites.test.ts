// tests/callee_sites: `vader dump --stage=callees`, what the typecheck settled
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
// array. And the interpolations: an integer, a string, a float, a struct with its
// own `Display`, a distinct over `string`, a bounded type parameter and a trait
// value. Last, an implicit `into` at an assignment and at the fallback of a `??`.
// Each expected line is the dump's, position included.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const SITES = join(import.meta.dir, "fixtures", "callee", "sites.vader");

const EXPECTED = [
  "sites.vader:12:31 operator builtin",
  "sites.vader:23:32 call bound sites$Shape.area",
  "sites.vader:55:62 operator builtin",
  "sites.vader:59:65 operator builtin",
  "sites.vader:69:63 operator builtin",
  "sites.vader:73:51 operator builtin",
  "sites.vader:77:42 display builtin",
  "sites.vader:81:48 operator builtin",
  "sites.vader:89:37 index builtin",
  "sites.vader:94:9 index-write builtin",
  "sites.vader:103:48 operator fn contains",
  "sites.vader:107:46 call fn len",
  "sites.vader:107:46 operator builtin",
  "sites.vader:107:66 call fn len",
  "sites.vader:115:31 call builtin",
  "sites.vader:121:31 call builtin",
  "sites.vader:130:12 operator builtin",
  "sites.vader:133:18 operator builtin",
  "sites.vader:147:14 iter-next builtin",
  "sites.vader:148:15 operator builtin",
  "sites.vader:154:14 iter-next virtual std_core$Iterator.next",
  "sites.vader:155:9 operator builtin",
  "sites.vader:169:31 call fn double",
  "sites.vader:171:39 call fn describe",
  "sites.vader:173:38 call fn tag",
  "sites.vader:175:46 call fn area",
  "sites.vader:177:49 call fn twice",
  "sites.vader:179:47 call bound sites$Shape.area",
  "sites.vader:181:45 call virtual sites$Shape.area",
  "sites.vader:183:58 call virtual sites$Shape.area",
  "sites.vader:185:39 call fn origin",
  "sites.vader:188:10 call bound sites$Origin.origin",
  "sites.vader:191:48 call fn sqrt",
  "sites.vader:193:54 call value",
  "sites.vader:195:46 call value",
  "sites.vader:197:36 call builtin",
  "sites.vader:199:46 call builtin",
  "sites.vader:201:43 call fn len",
  "sites.vader:203:43 call fn same",
  "sites.vader:205:34 call fn println",
  "sites.vader:207:55 call fn scaled",
  "sites.vader:207:64 call fn scaled",
  "sites.vader:209:40 call fn make",
  "sites.vader:209:40 call value",
  "sites.vader:211:61 operator fn add",
  "sites.vader:213:60 operator fn compare",
  "sites.vader:215:58 operator bound std_core$Add.add",
  "sites.vader:217:60 operator fn equals",
  "sites.vader:219:73 operator each(fn equals)",
  "sites.vader:221:71 operator each(fn equals)",
  "sites.vader:223:72 operator each(fn equals)",
  "sites.vader:225:75 operator each(fn equals, fn equals)",
  "sites.vader:227:64 operator bound std_core$Equals.equals",
  "sites.vader:229:53 operator builtin",
  "sites.vader:231:59 operator bound std_core$Equals.equals",
  "sites.vader:233:42 operator fn contains",
  "sites.vader:235:43 index fn at",
  "sites.vader:238:5 index-write fn set_at",
  "sites.vader:242:5 index fn at",
  "sites.vader:242:5 index-write fn set_at",
  "sites.vader:242:5 operator builtin",
  "sites.vader:245:48 index fn at",
  "sites.vader:247:46 index builtin",
  "sites.vader:249:52 call builtin",
  "sites.vader:249:56 into fn into",
  "sites.vader:252:13 into fn into",
  "sites.vader:256:45 call fn walk",
  "sites.vader:256:50 into fn into",
  "sites.vader:259:13 into builtin",
  "sites.vader:265:14 iter-next builtin",
  "sites.vader:266:9 operator builtin",
  "sites.vader:273:14 iter-next builtin",
  "sites.vader:274:9 operator builtin",
  "sites.vader:281:14 iter-next fn next",
  "sites.vader:282:9 operator builtin",
  "sites.vader:289:14 iter-into fn into",
  "sites.vader:289:14 iter-next virtual std_core$Iterator.next",
  "sites.vader:290:9 operator builtin",
  "sites.vader:297:14 call fn evens",
  "sites.vader:297:14 iter-next fn evens",
  "sites.vader:298:9 operator builtin",
  "sites.vader:305:14 iter-into fn into",
  "sites.vader:305:14 iter-next virtual std_core$Iterator.next",
  "sites.vader:306:9 operator builtin",
  "sites.vader:313:14 iter-next builtin",
  "sites.vader:314:9 operator builtin",
  "sites.vader:321:14 iter-next bound std_core$Iterator.next",
  "sites.vader:322:9 operator builtin",
  "sites.vader:329:9 iter-next builtin",
  "sites.vader:330:9 operator builtin",
  "sites.vader:338:8 display builtin",
  "sites.vader:338:13 display builtin",
  "sites.vader:338:18 display fn to_string",
  "sites.vader:338:23 display fn to_string",
  "sites.vader:338:28 display builtin",
  "sites.vader:340:69 display bound std_core$Display.to_string",
  "sites.vader:342:67 display virtual std_core$Display.to_string",
  "sites.vader:346:9 into fn into",
  "sites.vader:350:77 into fn into",
  "sites: 99, unsettled: 0",
];

test("the typecheck settles what each site of the fixture invokes", async () => {
  const r = await runCli(["dump", "--stage=callees", SITES], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("# Diagnostics");
  const lines = r.stdout.split("\n").filter((l) => l.startsWith("  ")).map((l) => l.trim());
  expect(lines).toEqual(EXPECTED);
}, MEDIUM_BUILD);
