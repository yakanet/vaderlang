// Intra-procedural escape analysis on the flat (non-SSA) CFG.
//
// For each `StructNew` / `ArrayNew` allocation, decide whether the value can
// escape its function. An escape happens when the value (or anything
// transitively reaching it) is:
//   - Returned from the function (Return.value).
//   - Passed as an argument to a Call / CallIndirect / VirtualCall (no
//     inter-procedural analysis — we assume the callee retains a reference).
//   - Stored as a field of another (escaping) value, or pushed into one.
//   - Wrapped in a CellNew / written into a CellSet (closures capture by
//     reference, so the cell outlives any local frame).
//
// Pure read-only uses (FieldGet, ArrayGet, ArrayLen, TypeCheck, Cast, Move,
// CondBranch, ...) keep the value local. Allocations with no escaping
// reachable use are marked with `stack: true` for downstream codegen.

import type {
  BasicBlock, BlockId, CFGFunction, CFGModule, CFGProject, Instruction, LocalId,
} from "./cfg.ts";
import {
  computeDominators, naturalLoopBodies, predecessorsOf,
} from "./analyses.ts";

export interface EscapeStats {
  readonly totalAllocs: number;
  readonly stackPromoted: number;
}

export function annotateEscape(p: CFGProject): { project: CFGProject; stats: EscapeStats } {
  let totalAllocs = 0;
  let stackPromoted = 0;
  const modules = new Map<string, CFGModule>();
  for (const [id, m] of p.modules) {
    const functions = m.functions.map((fn) => {
      const annotated = annotateFunction(fn);
      for (const b of annotated.blocks) {
        for (const ins of b.instructions) {
          if (ins.kind !== "StructNew" && ins.kind !== "ArrayNew") continue;
          totalAllocs++;
          if (ins.stack) stackPromoted++;
        }
      }
      return annotated;
    });
    modules.set(id, {
      moduleId: m.moduleId,
      displayPath: m.displayPath,
      functions,
      externs: m.externs,
      structDecls: m.structDecls,
    });
  }
  return {
    project: { modules, vtableEntries: p.vtableEntries, strings: p.strings },
    stats: { totalAllocs, stackPromoted },
  };
}

function annotateFunction(fn: CFGFunction): CFGFunction {
  // Walk blocks once to collect both `allocLocals` (the union driving the
  // escape analysis) and `structNews` (the subset needed to seed the
  // stack-origin forward pass below). Their block ids are saved so the
  // seeding can gate on `inLoop` without re-walking.
  const allocLocals = new Set<LocalId>();
  const structNews: { dst: LocalId; block: BlockId }[] = [];
  for (const b of fn.blocks) {
    for (const ins of b.instructions) {
      if (ins.kind === "StructNew") {
        allocLocals.add(ins.dst);
        structNews.push({ dst: ins.dst, block: b.id });
      } else if (ins.kind === "ArrayNew") {
        allocLocals.add(ins.dst);
      }
    }
  }
  if (allocLocals.size === 0) return fn;

  const { escaping, aliasOf, aliasFrom } = computeEscaping(fn, allocLocals);
  const inLoop = computeBlocksInLoops(fn);

  // Forward-propagate `barrierless` through Move/Cast. A Move/Cast with
  // any non-stack source stays out — one heap origin requires the barrier.
  const stackOrigin = new Set<LocalId>();
  const worklist: LocalId[] = [];
  for (const sn of structNews) {
    if (escaping.has(sn.dst) || inLoop.has(sn.block)) continue;
    stackOrigin.add(sn.dst);
    worklist.push(sn.dst);
  }
  while (worklist.length > 0) {
    const src = worklist.pop()!;
    const consumers = aliasFrom.get(src);
    if (consumers === undefined) continue;
    for (const dst of consumers) {
      if (stackOrigin.has(dst)) continue;
      const sources = aliasOf.get(dst);
      if (sources !== undefined && sources.every((s) => stackOrigin.has(s))) {
        stackOrigin.add(dst);
        worklist.push(dst);
      }
    }
  }

  let mutated = false;
  const newBlocks = fn.blocks.map((b) => {
    let blockMutated = false;
    const instructions = b.instructions.map((ins) => {
      if (ins.kind === "StructNew" || ins.kind === "ArrayNew") {
        if (!allocLocals.has(ins.dst)) return ins;
        // Stack-allocate iff the value doesn't escape and the alloc isn't
        // in a loop body. The C-emit declares the storage as a block-scoped
        // local, which would alias across iterations of the same back-edge
        // — keep those on the heap so each iteration is a fresh allocation.
        const stack = !escaping.has(ins.dst) && !inLoop.has(b.id);
        if (stack === ins.stack) return ins;
        blockMutated = true;
        return { ...ins, stack };
      }
      if (ins.kind === "FieldSet") {
        const barrierless = stackOrigin.has(ins.target);
        if (barrierless === ins.barrierless) return ins;
        blockMutated = true;
        return { ...ins, barrierless };
      }
      return ins;
    });
    if (!blockMutated) return b;
    mutated = true;
    return { id: b.id, instructions, terminator: b.terminator, span: b.span };
  });
  return mutated ? { ...fn, blocks: newBlocks } : fn;
}

/** Union of every natural-loop body in the CFG — blocks where stack-allocation
 *  is unsafe because the C-emit's block-scoped storage would alias across
 *  iterations. */
function computeBlocksInLoops(fn: CFGFunction): ReadonlySet<BlockId> {
  const preds = predecessorsOf(fn);
  const idom = computeDominators(fn, preds);
  const inLoop = new Set<BlockId>();
  for (const body of naturalLoopBodies(fn, preds, idom).values()) {
    for (const b of body) inLoop.add(b);
  }
  return inLoop;
}

/** Worklist: start with all locals known to escape (returned values, call
 *  args, cell-stored values, struct fields of escaping values, ...) and
 *  propagate backward via Move sources. Allocs whose dst isn't in the
 *  resulting set are stack-allocatable. Returns both directions of the
 *  aliasing relation so callers can drive forward or backward worklists
 *  off the same data. */
function computeEscaping(
  fn: CFGFunction, allocLocals: ReadonlySet<LocalId>,
): {
  escaping: Set<LocalId>;
  aliasOf: Map<LocalId, LocalId[]>;
  aliasFrom: Map<LocalId, LocalId[]>;
} {
  const escaping = new Set<LocalId>();
  const aliasOf = new Map<LocalId, LocalId[]>();      // dst → producers (Move src)
  const aliasFrom = new Map<LocalId, LocalId[]>();    // src → consumers (reverse of aliasOf)

  const see = (l: LocalId): void => { escaping.add(l); };

  for (const b of fn.blocks) {
    for (const ins of b.instructions) {
      switch (ins.kind) {
        case "Move":
          recordAlias(aliasOf, aliasFrom, ins.dst, ins.src);
          break;
        case "Cast":
          // Type casts don't change identity ; treat the cast result as an
          // alias of its source.
          recordAlias(aliasOf, aliasFrom, ins.dst, ins.value);
          break;
        case "FieldSet":
          // The value escapes (stored where the GC can reach it). The target
          // does NOT escape via this op alone — mutating a field doesn't
          // hand a reference to the target out. If the target later flows
          // into a Call/Return/etc., that op marks it independently.
          see(ins.value);
          break;
        case "ArraySet":
        case "ArrayPush":
          // Arrays always heap-allocate today (no `array.new_stack`), so
          // `see(target)` is free; revisit if array-buf stack-allocation
          // ever lands.
          see(ins.value);
          see(ins.target);
          break;
        case "CellNew":
          see(ins.value);
          break;
        case "CellSet":
          see(ins.value);
          see(ins.cell);
          break;
        case "Call":
        case "CallIndirect":
        case "VirtualCall":
        case "Intrinsic":
          if (ins.kind === "VirtualCall") see(ins.receiver);
          if (ins.kind === "CallIndirect") see(ins.callee);
          for (const a of ins.args) see(a);
          break;
        case "MakeClosure":
          see(ins.env);
          break;
        case "StructNew":
          // Field initialisers become reachable through the struct ; if dst
          // escapes later, every field escapes too. Forward-only — `dst` is
          // a stack-origin seed, never propagates *from* a field, so we
          // bypass `recordAlias` (which would pollute `aliasFrom`).
          for (const f of ins.fields) appendAlias(aliasOf, ins.dst, f);
          break;
        case "ArrayNew":
          // Same forward-only rationale as StructNew above.
          for (const e of ins.elements) appendAlias(aliasOf, ins.dst, e);
          break;
        case "Const":
        case "BinOp":
        case "UnOp":
        case "FieldGet":
        case "ArrayGet":
        case "ArrayLen":
        case "TypeCheck":
        case "CellGet":
        case "FnRef":
          break;       // pure / read-only ops don't escape their operands
      }
    }
    switch (b.terminator.kind) {
      case "Return":
        if (b.terminator.value !== null) see(b.terminator.value);
        break;
      case "Branch":
      case "CondBranch":
      case "Unreachable":
        break;
    }
  }

  // Backward propagation : if `dst` escapes and it aliases `src` (Move /
  // Cast), then `src` escapes too. Iterate to a fixed point.
  const work: LocalId[] = [...escaping];
  while (work.length > 0) {
    const cur = work.pop()!;
    const sources = aliasOf.get(cur);
    if (sources === undefined) continue;
    for (const s of sources) {
      if (escaping.has(s)) continue;
      escaping.add(s);
      work.push(s);
    }
  }

  // We only care about alloc locals — the rest of the set is incidental.
  const allocEscaping = new Set<LocalId>();
  for (const a of allocLocals) if (escaping.has(a)) allocEscaping.add(a);
  return { escaping: allocEscaping, aliasOf, aliasFrom };
}

function appendAlias(map: Map<LocalId, LocalId[]>, dst: LocalId, src: LocalId): void {
  let arr = map.get(dst);
  if (arr === undefined) { arr = []; map.set(dst, arr); }
  arr.push(src);
}

/** Record `dst aliases src` in both the forward and reverse alias maps so
 *  callers can drive worklists in either direction off the same edge. */
function recordAlias(
  aliasOf: Map<LocalId, LocalId[]>, aliasFrom: Map<LocalId, LocalId[]>,
  dst: LocalId, src: LocalId,
): void {
  appendAlias(aliasOf, dst, src);
  appendAlias(aliasFrom, src, dst);
}
