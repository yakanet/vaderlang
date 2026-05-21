// Centralised slot-touching predicate for bytecode passes. Every fused
// op that reads or writes a local slot funnels through here so the
// peephole / slot-coalesce passes don't have to grow a new arm per op.

import type { Op } from "./ops.ts";

/** Slot read by `op`, or null if `op` doesn't read a local slot. Covers
 *  `local.get` and fused slot-reads (`local.field`, …). */
export function slotRead(op: Op): number | null {
  switch (op.kind) {
    case "local.get":
    case "local.field":
      return op.slot;
    default:
      return null;
  }
}

/** Slot written by `op`, or null. Covers `local.set` and `local.tee`
 *  (which both write and leave on stack). */
export function slotWrite(op: Op): number | null {
  switch (op.kind) {
    case "local.set":
    case "local.tee":
      return op.slot;
    default:
      return null;
  }
}

/** Any slot the op touches — read OR write. Used by slot-coalesce to
 *  extend per-slot live ranges. */
export function slotTouched(op: Op): number | null {
  const r = slotRead(op);
  if (r !== null) return r;
  return slotWrite(op);
}

/** Return `op` with its slot reference rewritten to `newSlot`. Returns
 *  `op` unchanged when it has no slot to rewrite. */
export function withRemappedSlot(op: Op, newSlot: number): Op {
  switch (op.kind) {
    case "local.get":
    case "local.set":
    case "local.tee":
      return { kind: op.kind, slot: newSlot };
    case "local.field":
      return { kind: "local.field", slot: newSlot,
               typeIndex: op.typeIndex, fieldIndex: op.fieldIndex };
    default:
      return op;
  }
}
