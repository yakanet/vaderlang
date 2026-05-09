// Stack scheduler — recognises CFG patterns where an instruction's result
// is consumed immediately by its single successor's first operand, and
// hints the bytecode emitter to leave the value on the operand stack
// instead of round-tripping through a named local. Closes most of the
// 3-address overhead the converter introduces compared to the legacy
// stack-based emitter.
//
// Conditions for elision (per block, intra-block only) :
//   - `cur.dst` is single-use in the whole function (use-count = 1).
//   - `cur` is the immediately-preceding instruction of `next`.
//   - `cur.dst` matches `next`'s first stack-pushed operand.
//
// In that case :
//   - `skipSet` records `cur` (no `local.set` after computing the result).
//   - `skipFirstGet` records `next` (no `local.get` for the first operand).
//
// Same shape applies to the last-instruction → terminator transition for
// `Return.value` and `CondBranch.cond`.

import type { BasicBlock, BlockId, CFGFunction, Instruction, LocalId, Terminator } from "./cfg.ts";
import { countUses, dstOf } from "./analyses.ts";

export interface ScheduleHints {
  /** Instructions whose result should be left on the stack (no `local.set`). */
  readonly skipSet: ReadonlySet<Instruction>;
  /** Instructions whose first stack-pushed operand should be read from the
   *  stack (no `local.get`). */
  readonly skipFirstGet: ReadonlySet<Instruction>;
  /** Block IDs whose terminator's first read should come from the stack. */
  readonly skipTerminatorGet: ReadonlySet<BlockId>;
}

export const NO_HINTS: ScheduleHints = {
  skipSet: new Set(),
  skipFirstGet: new Set(),
  skipTerminatorGet: new Set(),
};

export function scheduleStack(fn: CFGFunction): ScheduleHints {
  const useCount = countUses(fn);
  const skipSet = new Set<Instruction>();
  const skipFirstGet = new Set<Instruction>();
  const skipTerminatorGet = new Set<BlockId>();

  for (const b of fn.blocks) {
    for (let i = 0; i + 1 < b.instructions.length; i++) {
      const cur = b.instructions[i]!;
      const next = b.instructions[i + 1]!;
      if (!canPassThroughStack(cur, next, useCount)) continue;
      skipSet.add(cur);
      skipFirstGet.add(next);
    }
    // Last instruction → terminator. Same single-use condition, but the
    // consumer is whatever the terminator reads first.
    const last = b.instructions[b.instructions.length - 1];
    if (last === undefined) continue;
    if (!canPassThroughTerminator(last, b.terminator, useCount)) continue;
    skipSet.add(last);
    skipTerminatorGet.add(b.id);
  }

  return { skipSet, skipFirstGet, skipTerminatorGet };
}

function canPassThroughStack(
  cur: Instruction, next: Instruction, useCount: ReadonlyMap<LocalId, number>,
): boolean {
  const dst = dstOf(cur);
  if (dst === null) return false;
  if ((useCount.get(dst) ?? 0) !== 1) return false;
  const firstOp = firstStackOperand(next);
  return firstOp !== null && firstOp === dst;
}

function canPassThroughTerminator(
  cur: Instruction, t: Terminator, useCount: ReadonlyMap<LocalId, number>,
): boolean {
  const dst = dstOf(cur);
  if (dst === null) return false;
  if ((useCount.get(dst) ?? 0) !== 1) return false;
  const firstOp = firstTerminatorOperand(t);
  return firstOp !== null && firstOp === dst;
}

/** First operand pushed onto the stack by the instruction's emit sequence.
 *  Mirrors the per-instr emit order in `src/midir/emit.ts`. Returns null
 *  for instructions that take no operands. */
function firstStackOperand(ins: Instruction): LocalId | null {
  switch (ins.kind) {
    case "Const":
    case "FnRef":
    case "Phi":
      return null;
    case "Move":         return ins.src;
    case "BinOp":        return ins.lhs;
    case "UnOp":         return ins.operand;
    case "Call":         return ins.args.length > 0 ? ins.args[0]! : null;
    case "CallIndirect": return ins.args.length > 0 ? ins.args[0]! : ins.callee;
    case "VirtualCall":  return ins.args.length > 0 ? ins.args[0]! : ins.receiver;
    case "FieldGet":     return ins.target;
    case "FieldSet":     return ins.target;
    case "ArrayGet":     return ins.target;
    case "ArraySet":     return ins.target;
    case "ArrayLen":     return ins.target;
    case "ArrayPush":    return ins.target;
    case "StructNew":    return ins.fields.length > 0 ? ins.fields[0]! : null;
    case "ArrayNew":     return ins.elements.length > 0 ? ins.elements[0]! : null;
    case "TypeCheck":    return ins.value;
    case "Cast":         return ins.value;
    case "CellNew":      return ins.value;
    case "CellGet":      return ins.cell;
    case "CellSet":      return ins.cell;
    case "MakeClosure":  return ins.env;
    case "Intrinsic":    return ins.args.length > 0 ? ins.args[0]! : null;
  }
}

function firstTerminatorOperand(t: Terminator): LocalId | null {
  switch (t.kind) {
    case "Branch":
    case "Unreachable": return null;
    case "CondBranch":  return t.cond;
    case "Return":      return t.value;
  }
}

