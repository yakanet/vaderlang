// Per-module content fingerprint — Sprint 3.11 phase 1.
//
// Each module's fingerprint is a hex SHA-256 of:
//   1. The module's `displayPath` (so two modules with identical source
//      but different paths don't collide).
//   2. The sorted (file path, file content) pairs.
//   3. The sorted (dep moduleId, dep fingerprint) pairs.
//
// Same inputs → same hash. Future caching layers (parser memo, typecheck
// memo, LSP incremental) consume this to decide whether downstream stages
// can be skipped.
//
// Phase 1 here exposes only the hash — no cache wiring. Subsequent phases:
//   - Phase 2: parse-result cache keyed by file fingerprint.
//   - Phase 3: typecheck cache keyed by module fingerprint.
//   - Phase 4: lower / bytecode caches.

import { CryptoHasher } from "bun";

import type { Module } from "./module.ts";
import type { ModuleId } from "./symbol.ts";

/** Topologically order modules by import dependency, then walk and assign
 *  each its fingerprint. Replaces every `Module` in the map with one
 *  carrying the computed `fingerprint` (the structural fields stay
 *  identity-shared). Cycles already short-circuited by the loader's
 *  `detectCycles`; for any leftover, we treat the missing dep fingerprints
 *  as `""` so the hash is still well-defined. */
export function computeModuleFingerprints(modules: Map<ModuleId, Module>): void {
  const order = topoOrder(modules);
  const fingerprints = new Map<ModuleId, string>();

  for (const id of order) {
    const m = modules.get(id);
    if (m === undefined) continue;
    const fp = hashModule(m, fingerprints);
    fingerprints.set(id, fp);
    modules.set(id, { ...m, fingerprint: fp });
  }
}

/** Kahn-style topological sort over the import graph. Modules with
 *  unresolved imports keep an empty dep list; cycle nodes (already
 *  diagnosed by `detectCycles`) appear in arbitrary post-cycle order. */
function topoOrder(modules: ReadonlyMap<ModuleId, Module>): ModuleId[] {
  const inDegree = new Map<ModuleId, number>();
  const reverse = new Map<ModuleId, ModuleId[]>();        // dep → modules depending on dep
  for (const id of modules.keys()) {
    inDegree.set(id, 0);
    reverse.set(id, []);
  }
  for (const m of modules.values()) {
    for (const imp of m.imports) {
      if (imp.resolvedTo === null || !modules.has(imp.resolvedTo)) continue;
      if (imp.resolvedTo === m.id) continue;              // self-import (rare)
      inDegree.set(m.id, (inDegree.get(m.id) ?? 0) + 1);
      reverse.get(imp.resolvedTo)!.push(m.id);
    }
  }

  const queue: ModuleId[] = [];
  for (const [id, deg] of inDegree) if (deg === 0) queue.push(id);

  const out: ModuleId[] = [];
  while (queue.length > 0) {
    const id = queue.shift()!;
    out.push(id);
    for (const dependent of reverse.get(id) ?? []) {
      const next = (inDegree.get(dependent) ?? 0) - 1;
      inDegree.set(dependent, next);
      if (next === 0) queue.push(dependent);
    }
  }

  // Cycle survivors — append in deterministic order so subsequent runs
  // produce identical fingerprints even when the cycle structure changes.
  if (out.length < modules.size) {
    const seen = new Set(out);
    const leftover = [...modules.keys()].filter((id) => !seen.has(id)).sort();
    out.push(...leftover);
  }
  return out;
}

function hashModule(m: Module, deps: ReadonlyMap<ModuleId, string>): string {
  const h = new CryptoHasher("sha256");
  h.update(`displayPath:${m.displayPath}\n`);

  // Sorted (path, content) pairs — sort by path so "files added in different
  // order" produces the same hash.
  const files = [...m.files].sort((a, b) => a.path.localeCompare(b.path));
  for (const f of files) {
    h.update(`file:${f.path}\n`);
    h.update(`size:${f.content.length}\n`);
    h.update(f.content);
    h.update("\n");
  }

  // Sorted (depId, depFingerprint) pairs — sort by id for determinism.
  const depIds = [...new Set(
    m.imports
      .map((imp) => imp.resolvedTo)
      .filter((id): id is ModuleId => id !== null && id !== m.id),
  )].sort();
  for (const id of depIds) {
    h.update(`dep:${id}=${deps.get(id) ?? ""}\n`);
  }

  return h.digest("hex");
}
