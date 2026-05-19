// Per-project registry assigning a stable integer slot to each trait method.
// Drives the per-tag vtable layout in `runtime/c/vader.h` and the indirect-
// dispatch lowering for `Any` method calls (Phase 0 of the erasure plan —
// see `docs/STDLIB_GENERIC_COLLAPSE_PHASE0.md`).
//
// Slot assignment policy:
// - Built-in stdlib trait methods are pinned at fixed slots (see PINNED_SLOTS
//   below) so the C runtime and standalone bench tools can hard-code them.
// - User-defined trait methods are assigned slots alphabetically by
//   `${traitName}.${methodName}`, starting at the slot after the highest
//   pinned slot. The sort runs once so encounter order doesn't affect the
//   assignment — two independent builds of the same project pick the same
//   slots.
//
// Key format: `${traitName}.${methodName}`. Same as `BytecodeModule.vtables`
// so the C emit can iterate the bytecode-level vtable map and look up slots
// without re-deriving trait owners. Known limitation: two traits with the
// same name from different modules collide. Stdlib trait names are unique
// today; revisit if multi-module collisions surface.
//
// Lookups are O(1) via a `Map`. The full snapshot is exposed via `all()` so
// the C emit can iterate to emit the per-tag vtables.

import type * as A from "../parser/ast.ts";
import type { ResolvedProject } from "../resolver/resolved-ast.ts";

/** Composite key `${traitName}.${methodName}` for slot lookup. Matches the
 *  format used by `BytecodeModule.vtables`. */
export type SlotKey = string;

/** Stdlib trait methods pinned at fixed slot indices. Hard-coded so the
 *  runtime helpers and bench tools can reference them without depending on
 *  a built registry. Pin slots 0-7 for future-proofing; user-defined methods
 *  start at slot 8. */
export const PINNED_SLOTS: ReadonlyMap<SlotKey, number> = new Map([
  ["Hash.hash",       0],
  ["Equals.equals",   1],
  ["Ord.compare",     2],
  ["Display.display", 3],
]);

const FIRST_USER_SLOT = 8;

export class TraitSlotRegistry {
  private readonly slots = new Map<SlotKey, number>();
  /** Next slot to assign on `register`. Pinned slots all sit below
   *  `FIRST_USER_SLOT` so a monotonic counter is sufficient — no need
   *  to scan for free slots. */
  private nextUserSlot = FIRST_USER_SLOT;

  constructor() {
    for (const [key, slot] of PINNED_SLOTS) {
      this.slots.set(key, slot);
    }
  }

  /** Look up the slot for `(trait, method)` — used by the typecheck side
   *  where callers carry the components separately. Returns null if not
   *  yet registered. */
  lookup(traitName: string, methodName: string): number | null {
    return this.slots.get(`${traitName}.${methodName}`) ?? null;
  }

  /** Look up the slot for a `${trait}.${method}` key directly — used by
   *  the C emit which iterates `BytecodeModule.vtables.keys()` and so
   *  carries the pre-formatted key. Returns null if not yet registered. */
  lookupByKey(key: SlotKey): number | null {
    return this.slots.get(key) ?? null;
  }

  /** Register a single `(trait, method)` pair. Idempotent — returns the
   *  existing slot if one is already assigned. Eager assignment: caller
   *  must guarantee deterministic call order, OR use `buildSlotRegistry`
   *  which sorts first. */
  register(traitName: string, methodName: string): number {
    const key = `${traitName}.${methodName}`;
    const existing = this.slots.get(key);
    if (existing !== undefined) return existing;
    const slot = this.nextUserSlot++;
    this.slots.set(key, slot);
    return slot;
  }

  /** Snapshot of every assigned slot. Sorted by slot index ascending so the
   *  C emit can iterate in stable order. */
  all(): readonly { readonly key: SlotKey; readonly slot: number }[] {
    const entries = Array.from(this.slots.entries()).map(([key, slot]) => ({ key, slot }));
    entries.sort((a, b) => a.slot - b.slot);
    return entries;
  }

  /** Total number of slots in use, including pinned but not-yet-overridden. */
  size(): number {
    return this.slots.size;
  }
}

/** Build a project-wide registry by walking every `TraitDecl` in every
 *  module and registering one slot per `(trait, method)` pair. Method
 *  order within a trait is preserved by alphabetical sort across all
 *  unpinned `${trait}::${method}` keys, so independent builds match.
 *
 *  Trait keys are derived as `${moduleId}::${traitName}`. The std/core
 *  pinned traits (Hash, Equals, Ord, Display) keep their fixed slots; any
 *  other trait — including user-defined ones in std modules — gets a
 *  user-slot starting at FIRST_USER_SLOT. */
export function buildSlotRegistry(project: ResolvedProject): TraitSlotRegistry {
  const collected: SlotKey[] = [];
  for (const program of project.modules.values()) {
    for (const decl of program.source.decls) {
      if (decl.kind !== "TraitDecl") continue;
      for (const member of decl.members) {
        collected.push(`${decl.name}.${member.name}`);
      }
    }
  }
  return buildSlotRegistryFromKeys(collected);
}

/** Build the registry from a list of `${trait}.${method}` keys directly —
 *  used by the C emit which iterates `BytecodeModule.vtables.keys()` and
 *  doesn't need the typecheck-level project state. Same alphabetical sort
 *  + pinned-slot policy as `buildSlotRegistry`. */
export function buildSlotRegistryFromKeys(keys: readonly SlotKey[]): TraitSlotRegistry {
  const registry = new TraitSlotRegistry();
  const unpinned = keys.filter(k => !PINNED_SLOTS.has(k)).sort();
  for (const fullKey of unpinned) {
    const dotIdx = fullKey.indexOf(".");
    if (dotIdx < 0) continue; // malformed key, skip defensively
    const traitName = fullKey.slice(0, dotIdx);
    const methodName = fullKey.slice(dotIdx + 1);
    registry.register(traitName, methodName);
  }
  return registry;
}
