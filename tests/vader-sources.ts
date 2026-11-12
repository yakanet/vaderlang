// tests/vader-sources: the `.vader` files under a folder.

import { readdirSync, statSync } from "node:fs";
import { join } from "node:path";

/** Every `.vader` file under `dir`, recursively, in `readdir` order. `dir` may
 *  also BE a `.vader` file, in which case the answer is just that file, which is
 *  what an import path resolving to a file-form module needs.
 *
 *  The one recursion. Three hand-written copies of it lived in as many test files
 *  before this, and two of them were edited past each other. */
export function listVaderFiles(dir: string): string[] {
  let st;
  try {
    st = statSync(dir);
  } catch {
    return [];
  }
  if (st.isFile()) return dir.endsWith(".vader") ? [dir] : [];
  const out: string[] = [];
  for (const ent of readdirSync(dir, { withFileTypes: true })) {
    const p = join(dir, ent.name);
    if (ent.isDirectory()) out.push(...listVaderFiles(p));
    else if (ent.name.endsWith(".vader")) out.push(p);
  }
  return out;
}
