import { existsSync, mkdirSync, readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { join } from "node:path";

// tests/snapshot: the run format and the snapshot comparison the Bun tests left
// share. The snippet corpus itself is checked by the Vader test runner
// (`tools/testrunner`).

const MAIN_FILE = "_main.vader";

/** A snippet of the corpus, as the tests that walk it read it. */
interface Scenario {
  readonly name: string;
  readonly dir: string;
  readonly mainPath: string;
}

const UPDATE = process.env["UPDATE_SNAPSHOTS"] === "1";

/** A run's output as a snapshot records it. A run stopped by a trap or a panic
 *  reads the same on both backends: the VM's `vader vm: <message>`, a trap's with
 *  ` at pc=N`, takes native's wording (`asNativeStop`), and the exit is 134, where
 *  the VM exits 1 and native aborts (134, 9 on Windows). */
export function formatRun(stdout: string, stderr: string, exit: number): string {
  const shared = asNativeStop(stderr);
  const parts: string[] = [];
  if (stdout.length > 0) parts.push("# stdout\n" + stdout);
  if (shared.length > 0) parts.push("# stderr\n" + shared);
  parts.push(`# exit\n${STOP_LINE.test(shared) ? STOPPED_EXIT : exit}\n`);
  return parts.join("");
}

// The line a run stopped by a trap or a panic ends on, as native prints it.
const STOP_LINE = /^vader: (?:trap|panic): /m;

// The exit such a run records : SIGABRT's, on POSIX.
const STOPPED_EXIT = 134;

// `stderr` with the VM's stop line in native's wording: `vader vm: panic: m` is
// `vader: panic: m`, any other `vader vm: m[ at pc=N]` a trap, `vader: trap: m`.
function asNativeStop(stderr: string): string {
  return stderr.replace(/^vader vm: (.*?)(?: at pc=\d+)?$/gm, (_line, message: string) =>
    message.startsWith("panic: ") ? `vader: ${message}` : `vader: trap: ${message}`);
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
