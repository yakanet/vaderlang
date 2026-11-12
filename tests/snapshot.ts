import { existsSync, mkdirSync, readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { join } from "node:path";

// tests/snapshot: the snapshot comparison the Bun tests left share, and the
// list of the snippets. The snippet corpus itself is checked by the Vader test
// runner (`tools/testrunner`).

const MAIN_FILE = "_main.vader";

/** A snippet of the corpus, as the tests that walk it read it. */
interface Scenario {
  readonly name: string;
  readonly dir: string;
  readonly mainPath: string;
}

const UPDATE = process.env["UPDATE_SNAPSHOTS"] === "1";

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

interface SnapshotResult {
  readonly ok: boolean;
  readonly expected: string | null;
  readonly snapPath: string;
}

/**
 * Compare an actual dump against a `.snap` file in the scenario dir.
 * Writes the snap if it doesn't exist or if `UPDATE_SNAPSHOTS=1`.
 */
export function snapshotEquals(scenarioDir: string, snapName: string, actual: string): SnapshotResult {
  if (!existsSync(scenarioDir)) mkdirSync(scenarioDir, { recursive: true });
  const snapPath = join(scenarioDir, snapName);

  if (!existsSync(snapPath)) {
    if (UPDATE) {
      writeFileSync(snapPath, actual);
      return { ok: true, expected: actual, snapPath };
    }
    return { ok: false, expected: null, snapPath };
  }

  const expected = readFileSync(snapPath, "utf8");
  if (expected === actual) return { ok: true, expected, snapPath };

  if (UPDATE) {
    writeFileSync(snapPath, actual);
    return { ok: true, expected: actual, snapPath };
  }

  return { ok: false, expected, snapPath };
}
