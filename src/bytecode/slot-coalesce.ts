// Slot coalescing — runs AFTER the peephole pipeline so we don't disable
// Rule 6 (single-use constant propagation), which needs a slot with exactly
// one set and one get to fire. Two slots whose linear live ranges don't
// overlap and share a ValType collapse into the same physical slot.
//
// Same-ValType buckets only — coalescing across ValType would corrupt the
// VM's slot-type invariants. The first 2026-05-16 attempt failed by missing
// loop back-edges ; pass 1b below extends ranges through enclosing
// `loop ... end` so a slot used both inside and across iterations stays
// alive over the full loop.

import type { Op } from "./ops.ts";
import type { FnEmitCtx } from "./emit.ts";
import type { BcLocal } from "./module.ts";

interface Range {
  first: number;
  last: number;
}

export function coalesceSlots(fn: FnEmitCtx): void {
  const paramCount = fn.signature.params.length;
  const totalSlots = paramCount + fn.locals.length;
  if (totalSlots <= paramCount) return;

  const ranges: (Range | null)[] = new Array(totalSlots).fill(null);
  for (let i = 0; i < fn.body.length; i++) {
    const op = fn.body[i]!;
    const slot = slotOf(op);
    if (slot === null) continue;
    const r = ranges[slot];
    if (r === null || r === undefined) ranges[slot] = { first: i, last: i };
    else r.last = i;
  }

  // A slot last-used at op N inside a loop body can still feed a read on
  // the next iteration (the back-edge jumps from `end` back to `loop`), so
  // any range touching a loop must cover its entire body. Iterate to
  // fixpoint to widen through nested / sibling loops.
  const loops = findLoopRanges(fn.body);
  if (loops.length === 1) {
    extendIntoLoops(ranges, totalSlots, loops);
  } else if (loops.length > 1) {
    let changed = true;
    while (changed) {
      changed = extendIntoLoops(ranges, totalSlots, loops);
    }
  }

  // Params are live for the whole call frame — pin so they never accept a
  // coalesced peer.
  for (let s = 0; s < paramCount; s++) {
    ranges[s] = { first: 0, last: fn.body.length };
  }

  const newLocals: BcLocal[] = [];
  const remap: number[] = new Array(totalSlots);
  for (let s = 0; s < paramCount; s++) remap[s] = s;

  // Per post-coalesce physical slot : the union of live ranges currently
  // assigned there. Reads ValType inline from `fn.signature.params` (for
  // param-pinned slots) or from `newLocals` (for everything else) — no
  // separate ValType table needed.
  const physRanges: Range[] = new Array(paramCount);
  for (let s = 0; s < paramCount; s++) physRanges[s] = ranges[s]!;

  for (let s = paramCount; s < totalSlots; s++) {
    const range = ranges[s];
    if (range === null || range === undefined) {
      // Slot never referenced — defensive against a slot the peephole's
      // dead-store sweep missed.
      remap[s] = -1;
      continue;
    }
    const want = fn.locals[s - paramCount]!.val;
    let chosen = -1;
    for (let phys = paramCount; phys < physRanges.length; phys++) {
      if (newLocals[phys - paramCount]!.val !== want) continue;
      if (rangesOverlap(physRanges[phys]!, range)) continue;
      chosen = phys;
      break;
    }
    if (chosen === -1) {
      chosen = physRanges.length;
      physRanges.push({ first: range.first, last: range.last });
      newLocals.push(fn.locals[s - paramCount]!);
    } else {
      const cur = physRanges[chosen]!;
      cur.first = Math.min(cur.first, range.first);
      cur.last = Math.max(cur.last, range.last);
    }
    remap[s] = chosen;
  }

  // If every non-param slot was assigned to its original position no body
  // rewrite is needed — implies `newLocals.length === fn.locals.length`
  // too, so the locals swap is also a no-op.
  let identity = true;
  for (let s = paramCount; s < totalSlots; s++) {
    if (remap[s] !== s) { identity = false; break; }
  }
  if (identity) return;

  for (let i = 0; i < fn.body.length; i++) {
    const op = fn.body[i]!;
    if (op.kind === "local.get" || op.kind === "local.set" || op.kind === "local.tee") {
      const newSlot = remap[op.slot];
      if (newSlot === undefined || newSlot === -1) continue;
      fn.body[i] = { kind: op.kind, slot: newSlot };
    } else if (op.kind === "local.field") {
      const newSlot = remap[op.slot];
      if (newSlot === undefined || newSlot === -1) continue;
      fn.body[i] = { kind: "local.field", slot: newSlot,
                     typeIndex: op.typeIndex, fieldIndex: op.fieldIndex };
    }
  }

  fn.locals.length = 0;
  fn.locals.push(...newLocals);
}

function slotOf(op: Op): number | null {
  if (op.kind === "local.get" || op.kind === "local.set" || op.kind === "local.tee") {
    return op.slot;
  }
  // Fused ops carrying a slot reference must extend the slot's live
  // range too — otherwise coalesce could collapse the slot with another
  // and corrupt the read.
  if (op.kind === "local.field") return op.slot;
  return null;
}

function rangesOverlap(a: Range, b: Range): boolean {
  return a.first <= b.last && b.first <= a.last;
}

function extendIntoLoops(
  ranges: (Range | null)[], totalSlots: number, loops: readonly Range[],
): boolean {
  let changed = false;
  for (let s = 0; s < totalSlots; s++) {
    const r = ranges[s];
    if (r === null || r === undefined) continue;
    for (const lp of loops) {
      if (r.first <= lp.last && r.last >= lp.first) {
        if (r.first > lp.first) { r.first = lp.first; changed = true; }
        if (r.last < lp.last)   { r.last  = lp.last;  changed = true; }
      }
    }
  }
  return changed;
}

function findLoopRanges(body: readonly Op[]): readonly Range[] {
  const stack: { kind: "block" | "loop" | "if"; start: number }[] = [];
  const out: Range[] = [];
  for (let i = 0; i < body.length; i++) {
    const op = body[i]!;
    if (op.kind === "block") stack.push({ kind: "block", start: i });
    else if (op.kind === "loop") stack.push({ kind: "loop", start: i });
    else if (op.kind === "if") stack.push({ kind: "if", start: i });
    else if (op.kind === "end") {
      const top = stack.pop();
      if (top !== undefined && top.kind === "loop") {
        out.push({ first: top.start, last: i });
      }
    }
  }
  return out;
}
