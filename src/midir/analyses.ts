// Shared CFG analyses and traversal utilities. Used by the structurer
// (`emit.ts`), DCE (`dce.ts`), and any future Mid-IR passes (SSA, escape
// analysis). Pure data — no IO, no diagnostics.

import type { BasicBlock, BlockId, CFGFunction, Instruction, LocalId, Terminator } from "./cfg.ts";

/** Successors of a block, derived from its terminator. */
export function successorsOf(b: BasicBlock): readonly BlockId[] {
  switch (b.terminator.kind) {
    case "Branch":      return [b.terminator.target];
    case "CondBranch":  return [b.terminator.then, b.terminator.else];
    case "Return":
    case "Unreachable": return [];
  }
}

/** Predecessor lists keyed by `BlockId`. The returned arrays are dense
 *  (one entry per block, possibly empty). */
export function predecessorsOf(fn: CFGFunction): readonly (readonly BlockId[])[] {
  const out: BlockId[][] = fn.blocks.map(() => []);
  for (const b of fn.blocks) {
    for (const succ of successorsOf(b)) out[succ]!.push(b.id);
  }
  return out;
}

/** True when an instruction has observable effect outside its `dst` slot.
 *  DCE keeps these alive even when their result local is unread. */
export function instructionHasSideEffect(ins: Instruction): boolean {
  switch (ins.kind) {
    case "Call":
    case "CallIndirect":
    case "VirtualCall":
    case "Intrinsic":
    case "FieldSet":
    case "ArraySet":
    case "ArrayPush":
    case "CellSet":
      return true;
    default:
      return false;
  }
}

/** Apply `visit` to every local read by the instruction (its operands).
 *  Phi sources are NOT visited here — phis read their sources from the
 *  predecessor blocks at runtime, not at the phi's own program point.
 *  Use `forEachPhiSource` separately when phi-aware liveness is needed. */
export function forEachReadLocal(ins: Instruction, visit: (l: LocalId) => void): void {
  switch (ins.kind) {
    case "Const":
    case "FnRef":
    case "Phi":
      return;
    case "Move":         visit(ins.src); return;
    case "BinOp":        visit(ins.lhs); visit(ins.rhs); return;
    case "UnOp":         visit(ins.operand); return;
    case "Call":         for (const a of ins.args) visit(a); return;
    case "CallIndirect": visit(ins.callee); for (const a of ins.args) visit(a); return;
    case "VirtualCall":  visit(ins.receiver); for (const a of ins.args) visit(a); return;
    case "FieldGet":     visit(ins.target); return;
    case "FieldSet":     visit(ins.target); visit(ins.value); return;
    case "ArrayGet":     visit(ins.target); visit(ins.index); return;
    case "ArraySet":     visit(ins.target); visit(ins.index); visit(ins.value); return;
    case "ArrayLen":     visit(ins.target); return;
    case "ArrayPush":    visit(ins.target); visit(ins.value); return;
    case "StructNew":    for (const f of ins.fields) visit(f); return;
    case "ArrayNew":     for (const e of ins.elements) visit(e); return;
    case "TypeCheck":    visit(ins.value); return;
    case "Cast":         visit(ins.value); return;
    case "CellNew":      visit(ins.value); return;
    case "CellGet":      visit(ins.cell); return;
    case "CellSet":      visit(ins.cell); visit(ins.value); return;
    case "MakeClosure":  visit(ins.env); return;
    case "Intrinsic":    for (const a of ins.args) visit(a); return;
  }
}

/** Apply `visit` to every local read by the terminator. */
export function forEachReadInTerminator(t: Terminator, visit: (l: LocalId) => void): void {
  switch (t.kind) {
    case "Branch":
    case "Unreachable": return;
    case "CondBranch":  visit(t.cond); return;
    case "Return":      if (t.value !== null) visit(t.value); return;
  }
}

/** Reverse-postorder of the CFG starting from the entry. Stable across runs.
 *  Used by every dataflow analysis that wants to visit predecessors before
 *  successors (forward flow) or successors before predecessors (backward). */
export function reversePostorder(fn: CFGFunction): BlockId[] {
  const order: BlockId[] = [];
  const visited = new Array<boolean>(fn.blocks.length).fill(false);
  function walk(b: BlockId): void {
    if (visited[b]) return;
    visited[b] = true;
    for (const s of successorsOf(fn.blocks[b]!)) walk(s);
    order.push(b);
  }
  walk(fn.entry);
  order.reverse();
  return order;
}

/** Cooper-Harvey-Kennedy iterative dominator computation. Returns
 *  `idom[b]` = immediate dominator of `b` (entry's idom is itself, unreachable
 *  blocks return -1 — interpreted as "no known idom"). */
export function computeDominators(
  fn: CFGFunction, preds: readonly (readonly BlockId[])[],
): readonly number[] {
  const n = fn.blocks.length;
  const idom = new Array<number>(n).fill(-1);
  idom[fn.entry] = fn.entry;
  const rpo = reversePostorder(fn);
  let changed = true;
  while (changed) {
    changed = false;
    for (const b of rpo) {
      if (b === fn.entry) continue;
      let newIdom = -1;
      for (const p of preds[b]!) {
        if (idom[p] === -1) continue;
        newIdom = newIdom === -1 ? p : intersectDomTree(p, newIdom, idom);
      }
      if (newIdom !== -1 && idom[b] !== newIdom) {
        idom[b] = newIdom;
        changed = true;
      }
    }
  }
  return idom;
}

/** Lowest-common-ancestor in a (post-)dominator tree. Walks `a`'s ancestor
 *  chain into a set, then walks `b`'s chain until hitting a known ancestor.
 *  Cooper et al.'s tighter "walk up the lower-numbered side" trick assumes a
 *  consistent block-ID order matching the dom-tree depth ; we don't have
 *  that invariant after CFG construction (block IDs reflect creation order
 *  in the converter, not RPO), so we fall back to the LCA walk. */
export function intersectDomTree(a: BlockId, b: BlockId, idom: readonly number[]): BlockId {
  const seen = new Set<number>();
  let x = a;
  while (x !== -1 && !seen.has(x)) {
    seen.add(x);
    const next = idom[x]!;
    if (next === x) break;
    x = next;
  }
  let y = b;
  while (y !== -1) {
    if (seen.has(y)) return y;
    const next = idom[y]!;
    if (next === y) break;
    y = next;
  }
  return -1;
}

/** True iff `a` dominates `b` (every path from entry to `b` passes through
 *  `a`). Walks `b`'s idom chain. */
export function dominates(idom: readonly number[], a: BlockId, b: BlockId): boolean {
  let cur = b;
  while (cur !== -1) {
    if (cur === a) return true;
    const next = idom[cur]!;
    if (next === cur) return cur === a;
    cur = next;
  }
  return false;
}

/** Dominance frontier per block, computed via the Cytron et al. algorithm :
 *  for each block B with multiple predecessors, walk each predecessor's idom
 *  chain up to (but not including) idom(B), adding B to each visited block's
 *  DF. Used by SSA construction to place phi nodes. */
export function computeDominanceFrontiers(
  fn: CFGFunction, preds: readonly (readonly BlockId[])[], idom: readonly number[],
): readonly (readonly BlockId[])[] {
  const df: BlockId[][] = fn.blocks.map(() => []);
  for (const b of fn.blocks) {
    const ps = preds[b.id]!;
    if (ps.length < 2) continue;
    const idomB = idom[b.id]!;
    for (const p of ps) {
      let runner = p;
      while (runner !== -1 && runner !== idomB) {
        if (!df[runner]!.includes(b.id)) df[runner]!.push(b.id);
        const next = idom[runner]!;
        if (next === runner) break;
        runner = next;
      }
    }
  }
  return df;
}

/** Per-block live-in / live-out sets. Standard backward dataflow on the
 *  use/def of each block. Phi sources are NOT counted as reads at the phi
 *  block — they participate via the predecessors' liveness when the phi
 *  becomes a Move at out-of-SSA. Used by both DCE (kill-dead-stores) and
 *  pruned SSA construction (skip phis where the variable isn't live-in). */
export interface Liveness {
  readonly liveIn: readonly ReadonlySet<LocalId>[];
  readonly liveOut: readonly ReadonlySet<LocalId>[];
}
export function computeLiveness(fn: CFGFunction): Liveness {
  const n = fn.blocks.length;
  const use: Set<LocalId>[] = new Array(n);
  const def: Set<LocalId>[] = new Array(n);
  for (let i = 0; i < n; i++) {
    const b = fn.blocks[i]!;
    const u = new Set<LocalId>();
    const d = new Set<LocalId>();
    for (const ins of b.instructions) {
      forEachReadLocal(ins, (l) => { if (!d.has(l)) u.add(l); });
      const dst = dstOf(ins);
      if (dst !== null) d.add(dst);
    }
    forEachReadInTerminator(b.terminator, (l) => { if (!d.has(l)) u.add(l); });
    use[i] = u;
    def[i] = d;
  }

  const succs = fn.blocks.map((b) => successorsOf(b));
  const liveIn: Set<LocalId>[] = fn.blocks.map(() => new Set());
  const liveOut: Set<LocalId>[] = fn.blocks.map(() => new Set());

  let changed = true;
  while (changed) {
    changed = false;
    for (let i = n - 1; i >= 0; i--) {
      const out = new Set<LocalId>();
      for (const s of succs[i]!) for (const l of liveIn[s]!) out.add(l);

      const inSet = new Set(use[i]);
      for (const l of out) if (!def[i]!.has(l)) inSet.add(l);

      if (!setsEqual(out, liveOut[i]!)) { liveOut[i] = out; changed = true; }
      if (!setsEqual(inSet, liveIn[i]!)) { liveIn[i] = inSet; changed = true; }
    }
  }
  return { liveIn, liveOut };
}

function setsEqual(a: ReadonlySet<LocalId>, b: ReadonlySet<LocalId>): boolean {
  if (a.size !== b.size) return false;
  for (const x of a) if (!b.has(x)) return false;
  return true;
}

/** The local an instruction writes to, or `null` for pure side-effecting ops
 *  (FieldSet, ArraySet, …) and zero-result calls. */
export function dstOf(ins: Instruction): LocalId | null {
  switch (ins.kind) {
    case "Const":
    case "Move":
    case "BinOp":
    case "UnOp":
    case "Phi":
    case "FieldGet":
    case "ArrayGet":
    case "ArrayLen":
    case "StructNew":
    case "ArrayNew":
    case "TypeCheck":
    case "Cast":
    case "CellNew":
    case "CellGet":
    case "MakeClosure":
    case "FnRef":
      return ins.dst;
    case "Call":
    case "CallIndirect":
    case "VirtualCall":
    case "Intrinsic":
      return ins.dst;
    case "FieldSet":
    case "ArraySet":
    case "ArrayPush":
    case "CellSet":
      return null;
  }
}
