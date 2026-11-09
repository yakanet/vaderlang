// tests/extern_prototypes: `vader dump --stage=externs`, each `@extern` as the C
// prototype the compiler calls it through.
//
// The shapes fixture calls one `@extern` of nine: the listing holds the eight it
// never calls too, which a native build drops. One line per shape: a scalar lent
// by address (`const`), a lent array C writes (`void*`), a mirror lent and
// written, a lent array whose elements `@c_type` names, a `@c_type` on a
// parameter and on the result, a string with no header, a `string | null` result
// with no header (`const char*`), and a variadic, whose variadic argument the
// comment names after the mangle.
//
// The stdlib listing is a snapshot, pinned to one target so that it does not
// depend on the host.

import { test, expect } from "bun:test";
import { readdirSync, readFileSync } from "node:fs";
import { dirname, join } from "node:path";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { snapshotDiff } from "./diff.ts";
import { snapshotEquals, SNAPSHOT_TARGET } from "./snapshot.ts";

ensureCliBuilt();

const FIXTURES = join(import.meta.dir, "fixtures", "externs");
const STDLIB = join(FIXTURES, "stdlib");
const LIB = join(import.meta.dir, "..", "lib");

const EXPECTED = [
  "/* DEMO (main), library demo: <demo.h> */",
  "void demo_count(const uint32_t* n);  // main$demo_count",
  "int64_t demo_fill(void* buf, uint64_t size);  // main$demo_fill",
  "int32_t demo_now(struct timespec* t);  // main$demo_now",
  "void demo_read(const unsigned int* cells);  // main$demo_read",
  "size_t demo_size(size_t n);  // main$demo_size",
  "",
  "/* no CLibrary, no header: the compiler writes the prototype */",
  "int32_t puts(const char* s);  // main$c_puts",
  "const char* ttyname(int32_t fd);  // main$terminal_name",
  "",
  "/* no CLibrary: <fcntl.h> */",
  "int32_t fcntl(int32_t fd, int32_t command, ...);  // main$set_flags, variadic: int32_t flags",
  "",
].join("\n");

test("every @extern is listed as the C prototype it is called through, called or not", async () => {
  const r = await runCli(["dump", "--stage=externs", join(FIXTURES, "main.vader")], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).toBe(EXPECTED);
}, MEDIUM_BUILD);

test("the C prototypes of the stdlib @extern match their snapshot", async () => {
  const r = await runCli(
    ["dump", "--stage=externs", "--module=std,system", `--target=${SNAPSHOT_TARGET}`, join(STDLIB, "main.vader")],
    undefined,
    MEDIUM_BUILD,
  );
  expect(r.exit).toBe(0);
  const snap = snapshotEquals(STDLIB, "externs.snapshot.c", r.stdout);
  if (!snap.ok) {
    throw new Error(
      `Snapshot mismatch (${snap.snapPath})\n` +
      `Run with UPDATE_SNAPSHOTS=1 to refresh, and READ the diff: each line is a C prototype.\n\n` +
      snapshotDiff(snap.snapPath, snap.expected, r.stdout),
    );
  }
}, MEDIUM_BUILD);

// A module of `lib/` the fixture does not import drops out of the snapshot
// without failing it.
test("the stdlib fixture imports every module of lib/ that declares an @extern", () => {
  const fixture = readFileSync(join(STDLIB, "main.vader"), "utf8");
  for (const file of readdirSync(LIB, { recursive: true }) as string[]) {
    if (file.endsWith(".vader") && /^\s*@extern\(/m.test(readFileSync(join(LIB, file), "utf8"))) {
      expect(fixture).toContain(`import "${dirname(file).split("\\").join("/")}"`);
    }
  }
});
