// The back end (`midir`, `emit`, the lowered IR) and the layers it stands on
// (`core`, `support`) never import the front end: they work from the lowered IR
// and the shared type and symbol tables alone. Nothing in the compiler would
// notice an import that breaks this, since the whole tree builds either way.
// This scan is what notices.
//
// Each checked tree may import only from the others and from the libraries, so
// a leak through `vader/lower` or `vader/pipeline` fails here too, not only a
// direct `vader/front` import.

import { expect, test } from "bun:test";
import { readFileSync } from "node:fs";
import { join, relative } from "node:path";
import { listVaderFiles } from "./vader-sources.ts";

const ROOT = join(import.meta.dir, "..");
const CHECKED = ["vader/midir", "vader/emit", "vader/lower/ir", "vader/core", "vader/support"];
const LIBRARIES = ["std/", "toolchain/"];
const IMPORT = /^(?:\w+ :: )?import "([^"]+)"/gm;

const isAllowed = (path: string): boolean =>
  LIBRARIES.some((library) => path.startsWith(library)) ||
  CHECKED.some((tree) => path === tree || path.startsWith(`${tree}/`));

test("the back end, core and support import nothing from the front end", () => {
  const leaks: string[] = [];
  for (const tree of CHECKED) {
    for (const file of listVaderFiles(join(ROOT, tree))) {
      for (const m of readFileSync(file, "utf8").matchAll(IMPORT)) {
        if (!isAllowed(m[1]!)) leaks.push(`${relative(ROOT, file)}: ${m[1]}`);
      }
    }
  }
  expect(leaks).toEqual([]);
});
