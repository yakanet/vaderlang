import { existsSync, readdirSync, statSync } from "node:fs";
import { join } from "node:path";

// tests/snapshot: the list of the snippets, which the Bun tests left walk. The
// snippet corpus itself is checked by the Vader test runner (`tools/testrunner`).

const MAIN_FILE = "_main.vader";

/** A snippet of the corpus, as the tests that walk it read it. */
interface Scenario {
  readonly name: string;
  readonly dir: string;
  readonly mainPath: string;
}

export function listSnippets(snippetsDir: string): Scenario[] {
  const out: Scenario[] = [];
  let entries: string[];
  try { entries = readdirSync(snippetsDir); } catch { return []; }
  for (const name of entries) {
    const dir = join(snippetsDir, name);
    if (!statSync(dir).isDirectory()) continue;
    const mainPath = join(dir, MAIN_FILE);
    if (!existsSync(mainPath)) continue;
    out.push({ name, dir, mainPath });
  }
  out.sort((a, b) => (a.name < b.name ? -1 : 1));
  return out;
}
