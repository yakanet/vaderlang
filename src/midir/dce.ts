// Intra-procedural DCE on the Mid-IR CFG. Two passes :
//
//   1. Dead instruction elimination (DIE) : per-store liveness, then drop
//      pure instructions whose result local is not live afterward. Repeated
//      to a fixed point — eliminating one Move can make the producer of its
//      source dead too.
//
//   2. Dead local elimination (DLE) : after DIE settles, locals never read
//      and never written by a side-effecting instruction get dropped, and
//      surviving locals are renumbered into a compact range. Params keep
//      their leading slots so the bytecode emit's "params at 0..N-1"
//      convention is preserved.
//
// Functional throughout — returns new `CFGProject` / `CFGFunction` /
// `BasicBlock` values without mutating the input. The pass runs after
// `buildCFGProject` and before the structurer.

import type {
  BasicBlock, BlockId, CFGFunction, CFGLocal, CFGModule, CFGParam,
  CFGProject, Instruction, LocalId, Terminator,
} from "./cfg.ts";
import {
  computeLiveness, dstOf, forEachReadInTerminator, forEachReadLocal,
  instructionHasSideEffect,
} from "./analyses.ts";

export function eliminateDeadCFG(p: CFGProject): CFGProject {
  const modules = new Map<string, CFGModule>();
  for (const [id, m] of p.modules) {
    modules.set(id, {
      moduleId: m.moduleId,
      displayPath: m.displayPath,
      functions: m.functions.map(optimiseFunction),
      otherDecls: m.otherDecls,
    });
  }
  return { modules, vtableEntries: p.vtableEntries, strings: p.strings };
}

function optimiseFunction(fn: CFGFunction): CFGFunction {
  // Copy-folding first : collapses the converter's `$tmp = expr ; B = move
  // $tmp` chains into `B = expr`. This unlocks DIE on the resulting Move-
  // free body and is intra-block, so cheap.
  let cur = foldMoves(fn);
  for (let iter = 0; iter < 8; iter++) {        // safety cap ; converges in 1-3
    const next = dieOnce(cur);
    if (next === cur) break;
    cur = next;
  }
  return compactLocals(cur);
}

// =============================================================================
// Pass 0 — Move forwarding (a.k.a. copy folding)
//
// For each pattern `producer.dst = X ; Move dst=Y src=X` where X is a tmp
// local read only by the Move, rewrite the producer to write into Y and drop
// the Move. Restricted to intra-block to keep the analysis trivial — that
// catches every converter-emitted `let x = expr` chain since the converter
// always emits the `Move` immediately after the producer.
// =============================================================================

function foldMoves(fn: CFGFunction): CFGFunction {
  const useCount = countUses(fn);
  const paramLocals = new Set<LocalId>();
  for (const p of fn.params) paramLocals.add(p.local);

  let mutated = false;
  const newBlocks = fn.blocks.map((b) => {
    const folded = foldMovesInBlock(b, useCount, paramLocals);
    if (folded === b.instructions) return b;
    mutated = true;
    return { id: b.id, instructions: folded, terminator: b.terminator, span: b.span };
  });
  return mutated ? { ...fn, blocks: newBlocks } : fn;
}

function countUses(fn: CFGFunction): ReadonlyMap<LocalId, number> {
  const counts = new Map<LocalId, number>();
  const bump = (l: LocalId): void => { counts.set(l, (counts.get(l) ?? 0) + 1); };
  for (const b of fn.blocks) {
    for (const ins of b.instructions) forEachReadLocal(ins, bump);
    forEachReadInTerminator(b.terminator, bump);
  }
  return counts;
}

function foldMovesInBlock(
  b: BasicBlock, useCount: ReadonlyMap<LocalId, number>, paramLocals: ReadonlySet<LocalId>,
): readonly Instruction[] {
  const folded: Instruction[] = [];
  let mutated = false;
  for (let i = 0; i < b.instructions.length; i++) {
    const ins = b.instructions[i]!;
    if (ins.kind !== "Move") { folded.push(ins); continue; }
    if (paramLocals.has(ins.src)) { folded.push(ins); continue; }
    if ((useCount.get(ins.src) ?? 0) !== 1) { folded.push(ins); continue; }

    // Walk back through the locals already emitted in this block ; the
    // producer is the most recent instruction whose `dst === ins.src`. Bail
    // if any intervening instruction also wrote to `ins.dst` (we'd be
    // resurrecting a stale value otherwise).
    let producerIdx = -1;
    for (let j = folded.length - 1; j >= 0; j--) {
      const cand = folded[j]!;
      const cdst = dstOf(cand);
      if (cdst === ins.dst && cdst !== ins.src) break;
      if (cdst === ins.src) { producerIdx = j; break; }
    }
    if (producerIdx < 0) { folded.push(ins); continue; }

    // Side-effecting instr's `dst` is observable (e.g. a Call's return value
    // could be read by the surrounding source-level code at any point) — only
    // fold pure producers.
    const producer = folded[producerIdx]!;
    if (instructionHasSideEffect(producer)) { folded.push(ins); continue; }

    folded[producerIdx] = withDst(producer, ins.dst);
    mutated = true;
  }
  return mutated ? folded : b.instructions;
}

/** Replace an instruction's destination local. Pure-producer-only — callers
 *  must check `instructionHasSideEffect` first. */
function withDst(ins: Instruction, dst: LocalId): Instruction {
  switch (ins.kind) {
    case "Const":       return { ...ins, dst };
    case "Move":        return { ...ins, dst };
    case "BinOp":       return { ...ins, dst };
    case "UnOp":        return { ...ins, dst };
    case "FieldGet":    return { ...ins, dst };
    case "ArrayGet":    return { ...ins, dst };
    case "ArrayLen":    return { ...ins, dst };
    case "StructNew":   return { ...ins, dst };
    case "ArrayNew":    return { ...ins, dst };
    case "TypeCheck":   return { ...ins, dst };
    case "Cast":        return { ...ins, dst };
    case "CellNew":     return { ...ins, dst };
    case "CellGet":     return { ...ins, dst };
    case "MakeClosure": return { ...ins, dst };
    case "FnRef":       return { ...ins, dst };
    default: return ins;     // side-effecting instrs filtered upstream
  }
}

// =============================================================================
// Pass 1 — Dead Instruction Elimination via per-store liveness
// =============================================================================

function dieOnce(fn: CFGFunction): CFGFunction {
  const { liveOut } = computeLiveness(fn);
  let mutated = false;
  const newBlocks: BasicBlock[] = fn.blocks.map((b) => {
    const kept = pruneBlock(b, liveOut[b.id]!);
    if (kept === b.instructions) return b;
    mutated = true;
    return { id: b.id, instructions: kept, terminator: b.terminator, span: b.span };
  });
  if (!mutated) return fn;
  return { ...fn, blocks: newBlocks };
}

/** Walk a block backward, dropping pure instructions whose `dst` is not in
 *  the live set at that point. Returns the original `instructions` array
 *  reference when nothing changed (so the caller can detect the no-op fast
 *  path with a single `===`). */
function pruneBlock(
  b: BasicBlock, liveOut: ReadonlySet<LocalId>,
): readonly Instruction[] {
  const live = new Set<LocalId>(liveOut);
  forEachReadInTerminator(b.terminator, (l) => live.add(l));
  const keep = new Array<boolean>(b.instructions.length);
  for (let i = b.instructions.length - 1; i >= 0; i--) {
    const ins = b.instructions[i]!;
    const dst = dstOf(ins);
    const dstLive = dst === null || live.has(dst);
    const isDead = !instructionHasSideEffect(ins) && !dstLive;
    keep[i] = !isDead;
    if (isDead) continue;
    if (dst !== null) live.delete(dst);
    forEachReadLocal(ins, (l) => live.add(l));
  }
  if (keep.every((k) => k)) return b.instructions;
  const out: Instruction[] = [];
  for (let i = 0; i < b.instructions.length; i++) {
    if (keep[i]) out.push(b.instructions[i]!);
  }
  return out;
}

// =============================================================================
// Pass 2 — Dead Local Elimination + slot compaction
// =============================================================================

function compactLocals(fn: CFGFunction): CFGFunction {
  const n = fn.locals.length;
  const referenced = new Array<boolean>(n).fill(false);
  for (let i = 0; i < fn.params.length; i++) referenced[i] = true;     // params keep their slots

  const see = (l: LocalId): void => { referenced[l] = true; };
  for (const b of fn.blocks) {
    for (const ins of b.instructions) {
      forEachReadLocal(ins, see);
      // Side-effecting instr's dst (e.g. a Call's return value) may go
      // unread — keep its local so the emit can still `local.set` into it.
      if (instructionHasSideEffect(ins)) {
        const d = dstOf(ins);
        if (d !== null) see(d);
      }
    }
    forEachReadInTerminator(b.terminator, see);
  }

  // No drops ? short-circuit so callers can detect the no-op identity.
  let droppedAny = false;
  for (let i = fn.params.length; i < n; i++) if (!referenced[i]) { droppedAny = true; break; }
  if (!droppedAny) return fn;

  const remap = new Array<LocalId>(n);
  const newLocals: CFGLocal[] = [];
  for (let i = 0; i < n; i++) {
    if (!referenced[i]) { remap[i] = -1; continue; }
    remap[i] = newLocals.length;
    newLocals.push(fn.locals[i]!);
  }

  const newParams: CFGParam[] = fn.params.map((p) => ({
    name: p.name, symbol: p.symbol, type: p.type, local: remap[p.local]!,
  }));

  // Drop instructions remapped to dst=-1: liveness over-approximates around
  // back-edges through dead-end blocks; SSA's allocFresh would crash on these.
  const newBlocks: BasicBlock[] = fn.blocks.map((b) => {
    const out: Instruction[] = [];
    for (const ins of b.instructions) {
      const d = dstOf(ins);
      if (d !== null && remap[d] === -1 && !instructionHasSideEffect(ins)) continue;
      out.push(remapInstr(ins, remap));
    }
    return { id: b.id, instructions: out, terminator: remapTerminator(b.terminator, remap), span: b.span };
  });

  return {
    mangled: fn.mangled,
    params: newParams,
    returnType: fn.returnType,
    locals: newLocals,
    blocks: newBlocks,
    entry: fn.entry,
    origin: fn.origin,
  };
}

function r(remap: readonly LocalId[], l: LocalId): LocalId {
  return remap[l]!;
}

function remapInstr(ins: Instruction, m: readonly LocalId[]): Instruction {
  switch (ins.kind) {
    case "Const":         return { ...ins, dst: r(m, ins.dst) };
    case "Move":          return { ...ins, dst: r(m, ins.dst), src: r(m, ins.src) };
    case "BinOp":         return { ...ins, dst: r(m, ins.dst), lhs: r(m, ins.lhs), rhs: r(m, ins.rhs) };
    case "UnOp":          return { ...ins, dst: r(m, ins.dst), operand: r(m, ins.operand) };
    case "Phi":           return {
      ...ins, dst: r(m, ins.dst),
      sources: ins.sources.map((s) => ({ block: s.block, value: r(m, s.value) })),
    };
    case "Call":          return {
      ...ins, dst: ins.dst === null ? null : r(m, ins.dst), args: ins.args.map((a) => r(m, a)),
    };
    case "CallIndirect":  return {
      ...ins, dst: ins.dst === null ? null : r(m, ins.dst),
      callee: r(m, ins.callee), args: ins.args.map((a) => r(m, a)),
    };
    case "VirtualCall":   return {
      ...ins, dst: ins.dst === null ? null : r(m, ins.dst),
      receiver: r(m, ins.receiver), args: ins.args.map((a) => r(m, a)),
    };
    case "FnRef":         return { ...ins, dst: r(m, ins.dst) };
    case "FieldGet":      return { ...ins, dst: r(m, ins.dst), target: r(m, ins.target) };
    case "FieldSet":      return { ...ins, target: r(m, ins.target), value: r(m, ins.value) };
    case "ArrayGet":      return { ...ins, dst: r(m, ins.dst), target: r(m, ins.target), index: r(m, ins.index) };
    case "ArraySet":      return {
      ...ins, target: r(m, ins.target), index: r(m, ins.index), value: r(m, ins.value),
    };
    case "ArrayLen":      return { ...ins, dst: r(m, ins.dst), target: r(m, ins.target) };
    case "ArrayPush":     return { ...ins, target: r(m, ins.target), value: r(m, ins.value) };
    case "StructNew":     return { ...ins, dst: r(m, ins.dst), fields: ins.fields.map((f) => r(m, f)) };
    case "ArrayNew":      return { ...ins, dst: r(m, ins.dst), elements: ins.elements.map((e) => r(m, e)) };
    case "TypeCheck":     return { ...ins, dst: r(m, ins.dst), value: r(m, ins.value) };
    case "Cast":          return { ...ins, dst: r(m, ins.dst), value: r(m, ins.value) };
    case "CellNew":       return { ...ins, dst: r(m, ins.dst), value: r(m, ins.value) };
    case "CellGet":       return { ...ins, dst: r(m, ins.dst), cell: r(m, ins.cell) };
    case "CellSet":       return { ...ins, cell: r(m, ins.cell), value: r(m, ins.value) };
    case "MakeClosure":   return { ...ins, dst: r(m, ins.dst), env: r(m, ins.env) };
    case "Intrinsic":     return {
      ...ins, dst: ins.dst === null ? null : r(m, ins.dst), args: ins.args.map((a) => r(m, a)),
    };
  }
}

function remapTerminator(t: Terminator, m: readonly LocalId[]): Terminator {
  switch (t.kind) {
    case "Branch":
    case "Unreachable": return t;
    case "CondBranch":  return { ...t, cond: r(m, t.cond) };
    case "Return":      return { ...t, value: t.value === null ? null : r(m, t.value) };
  }
}

