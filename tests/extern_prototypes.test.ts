// tests/extern_prototypes: `vader dump --stage=externs`, each `@extern` of the
// fixture as the C prototype the compiler calls it through.
//
// The fixture calls one `@extern` of seven: the listing holds the six it never
// calls too, which a native build drops. One line per shape: a scalar lent by
// address (`const`), a lent array C writes (`void*`), a mirror lent and written,
// a `@c_type` on a parameter and on the result, a string with no header, and a
// variadic, whose variadic argument the comment names after the mangle.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const PROGRAM = join(import.meta.dir, "fixtures", "externs", "main.vader");

const EXPECTED = [
  "# Externs",
  "",
  "## demo: <demo.h>",
  "",
  "void demo_count(const uint32_t* n);  // main$demo_count",
  "int64_t demo_fill(void* buf, uint64_t size);  // main$demo_fill",
  "int32_t demo_now(struct timespec* t);  // main$demo_now",
  "size_t demo_size(size_t n);  // main$demo_size",
  "",
  "## the process, no header: the compiler writes the prototype",
  "",
  "int32_t puts(const char* s);  // main$c_puts",
  "",
  "## the process: <fcntl.h>",
  "",
  "int32_t fcntl(int32_t fd, int32_t command, ...);  // main$set_flags, variadic: int32_t flags",
  "",
].join("\n");

test("every @extern is listed as the C prototype it is called through, called or not", async () => {
  const r = await runCli(["dump", "--stage=externs", PROGRAM], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).toBe(EXPECTED);
}, MEDIUM_BUILD);
