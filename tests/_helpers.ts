import { readdirSync, readFileSync, statSync } from "node:fs";
import { join } from "node:path";

/**
 * Walk a directory recursively and yield every file matching the given suffix.
 * Used by snapshot tests to discover sample programs under tests/samples or
 * examples/.
 */
export function* walkFiles(root: string, suffix: string): IterableIterator<string> {
  for (const entry of readdirSync(root)) {
    const full = join(root, entry);
    const stat = statSync(full);
    if (stat.isDirectory()) {
      yield* walkFiles(full, suffix);
    } else if (entry.endsWith(suffix)) {
      yield full;
    }
  }
}

/**
 * Read a file as UTF-8 text. Throws with a clear error if the file is missing.
 */
export function readText(path: string): string {
  return readFileSync(path, "utf8");
}
