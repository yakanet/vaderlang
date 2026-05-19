// Per-tag vtable emit — Phase 0 of the erasure plan
// (`docs/STDLIB_GENERIC_COLLAPSE_PHASE0.md` task P0-3).
//
// Iterates `BytecodeModule.vtables` (already populated by the bytecode
// emit from impl-method routing) and projects it onto the per-tag layout
// the runtime helper `vader_virtual_dispatch` consumes:
//
//   const vader_vtable_t  vt_<typeIdx> = { .slots = { [SLOT_HASH] = (void*)fn_<i>, ... } };
//   const vader_vtable_t* const vader_vtable_table[N] = { ... };
//   const size_t                vader_vtable_count    = N;
//
// Slot indices are derived deterministically from the trait/method names
// already in the bytecode (no typecheck-side side-table threading needed —
// `buildSlotRegistryFromKeys` re-derives slots from the bytecode keys).
//
// Output goes through `lines.push(...)` like the rest of the C emit; the
// function is called once per module from `emit.ts`.

import type { BytecodeModule } from "../bytecode/module.ts";
import {
  buildSlotRegistryFromKeys,
  PINNED_SLOTS,
  type TraitSlotRegistry,
} from "../typecheck/trait-slots.ts";

interface VtableSlotEntry {
  /** Slot index in `vader_vtable_t.slots[]`. */
  readonly slot: number;
  /** Bytecode fn-index of the impl method. C name is `fnNames[fnIndex]`. */
  readonly fnIndex: number;
  /** `${trait}.${method}` — for emitted comments only. */
  readonly key: string;
}

/** Project the bytecode-level vtables onto the per-tag layout. Returns a
 *  `Map<typeIndex, slot entries>` plus the inferred max tag (so the
 *  emitted table can size itself correctly). */
function projectVtables(
  bcVtables: ReadonlyMap<string, ReadonlyMap<number, number>>,
  slots: TraitSlotRegistry,
): { perType: Map<number, VtableSlotEntry[]>; maxTag: number } {
  const perType = new Map<number, VtableSlotEntry[]>();
  let maxTag = -1;

  for (const [key, typeToFn] of bcVtables) {
    const slot = slots.lookupByKey(key);
    if (slot === null) continue; // unknown trait method — shouldn't happen
    for (const [typeIndex, fnIndex] of typeToFn) {
      if (typeIndex > maxTag) maxTag = typeIndex;
      const list = perType.get(typeIndex);
      const entry: VtableSlotEntry = { slot, fnIndex, key };
      if (list !== undefined) list.push(entry);
      else perType.set(typeIndex, [entry]);
    }
  }

  return { perType, maxTag };
}

/** Emit the per-tag vtable section. Called from `emit.ts` after the type
 *  info table. The output appends a `vader_vtable_table[]` entry per
 *  typeIndex that has impl methods, plus the `vader_vtable_count` global.
 *  Tags with no impl get a NULL pointer in the table. */
export function emitVtables(
  module: BytecodeModule,
  fnNames: readonly string[],
  lines: string[],
): void {
  const keys = Array.from(module.vtables.keys());
  const slots = buildSlotRegistryFromKeys(keys);
  const { perType, maxTag } = projectVtables(module.vtables, slots);

  lines.push(``);
  lines.push(`/* ----------------------------------------------------------- vtables`);
  lines.push(` * Per-tag method dispatch tables consumed by`);
  lines.push(` * \`vader_virtual_dispatch(tag, slot)\`. Built from the bytecode's`);
  lines.push(` * \`(trait.method)\` → \`(typeIndex → fnIndex)\` map; slot indices are`);
  lines.push(` * derived deterministically by sorting the trait-method keys`);
  lines.push(` * alphabetically. Pinned stdlib slots: ${[...PINNED_SLOTS.entries()].map(([k, v]) => `${k}=${v}`).join(", ")}.`);
  lines.push(` */`);

  if (perType.size === 0) {
    // No impls in this module — emit empty table so the weak fallback in
    // `vader_runtime.c` is overridden with our (still empty) data. Keeps
    // the link-time strong-symbol takeover deterministic.
    lines.push(`const vader_vtable_t* const vader_vtable_table[1] = { NULL };`);
    lines.push(`const size_t                vader_vtable_count    = 0;`);
    return;
  }

  // Emit one vtable per typeIndex with at least one populated slot. Sort by
  // typeIndex for stable output regardless of map iteration order.
  const sortedTypes = Array.from(perType.keys()).sort((a, b) => a - b);
  for (const typeIndex of sortedTypes) {
    const entries = perType.get(typeIndex)!;
    entries.sort((a, b) => a.slot - b.slot);
    lines.push(`static const vader_vtable_t vt_${typeIndex} = { .slots = {`);
    for (const e of entries) {
      const fname = fnNames[e.fnIndex] ?? `/* missing fn ${e.fnIndex} */`;
      lines.push(`    [${e.slot}] = (void*)${fname}, /* ${e.key} */`);
    }
    lines.push(`}};`);
  }

  // Table indexed by typeIndex. Sized to `maxTag + 1` so every reachable
  // tag has a slot — NULL for types without impls.
  const tableSize = maxTag + 1;
  lines.push(``);
  lines.push(`const vader_vtable_t* const vader_vtable_table[${tableSize}] = {`);
  for (let i = 0; i < tableSize; i++) {
    if (perType.has(i)) {
      lines.push(`    [${i}] = &vt_${i},`);
    }
  }
  lines.push(`};`);
  lines.push(`const size_t vader_vtable_count = ${tableSize};`);
}
