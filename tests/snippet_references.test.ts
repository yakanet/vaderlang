// A comment or a document that names `tests/snippets/<name>` sends its reader to
// a snippet. Merging or renaming that snippet leaves the pointer dangling, and
// nothing else notices: the compiler does not read comments and the snippet
// harness only looks at directories. This scan is what notices.
//
// History keeps the names that were current when it was written, so
// `docs/HISTORY.md` and the ADRs are not scanned. Generated snapshots are
// skipped too: each one names its own snippet, which disappears with it. So is
// the generated C of the bootstrap seed, which cites no snippet.

import { expect, test } from "bun:test";
import { existsSync, readdirSync, readFileSync } from "node:fs";
import { join } from "node:path";

const ROOTS = ["vader", "lib", "runtime", "examples", "bootstrap", "docs", "tests"];
const TOP_LEVEL_FILES = ["TODO.md", "SPEC.md", "README.md"];
const SKIPPED = new Set(["docs/HISTORY.md", "docs/adr", "bootstrap/seed"]);
const SCANNED_EXTENSION = /\.(vader|ts|md|c|h|sh)$/;
const SNIPPET_PATH = /tests\/snippets\/([A-Za-z0-9_]+)/g;

function scannedFiles(dir: string, out: string[]): string[] {
  for (const entry of readdirSync(dir, { withFileTypes: true })) {
    const path = join(dir, entry.name);
    if (SKIPPED.has(path.split("\\").join("/"))) continue;
    if (entry.isDirectory()) {
      scannedFiles(path, out);
    } else if (SCANNED_EXTENSION.test(entry.name) && !entry.name.includes(".snapshot")) {
      out.push(path);
    }
  }
  return out;
}

test("every tests/snippets/<name> a file cites exists", () => {
  const files = [
    ...ROOTS.filter((root) => existsSync(root)).flatMap((root) => scannedFiles(root, [])),
    ...TOP_LEVEL_FILES.filter((file) => existsSync(file)),
  ];
  const dangling: string[] = [];
  for (const file of files) {
    for (const m of readFileSync(file, "utf8").matchAll(SNIPPET_PATH)) {
      if (!existsSync(join("tests", "snippets", m[1]!))) dangling.push(`${file}: tests/snippets/${m[1]}`);
    }
  }
  expect(dangling).toEqual([]);
});
