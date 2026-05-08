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

/** Apply `visit` to every local read by the instruction (its operands). */
export function forEachReadLocal(ins: Instruction, visit: (l: LocalId) => void): void {
  switch (ins.kind) {
    case "Const":
    case "FnRef":
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

/** The local an instruction writes to, or `null` for pure side-effecting ops
 *  (FieldSet, ArraySet, …) and zero-result calls. */
export function dstOf(ins: Instruction): LocalId | null {
  switch (ins.kind) {
    case "Const":
    case "Move":
    case "BinOp":
    case "UnOp":
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
