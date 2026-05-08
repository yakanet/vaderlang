// Intra-procedural escape analysis on the SSA-form CFG.
//
// For each `StructNew` / `ArrayNew` allocation, decide whether the value
// can escape its function. An escape happens when the value (or anything
// transitively reaching it) is :
//   - Returned from the function (Return.value).
//   - Passed as an argument to a Call / CallIndirect / VirtualCall — without
//     inter-procedural analysis we conservatively assume the callee retains
//     a reference past the call.
//   - Stored as a field of another (escaping) value, or pushed into one.
//   - Wrapped in a CellNew / written into a CellSet — closures capture-by-
//     reference, so the cell outlives any local frame.
//   - Used as the sources of a Phi whose dst escapes (transitive propagation).
//
// All other uses (FieldGet, ArrayGet, ArrayLen, TypeCheck, Cast, Move,
// CondBranch, ...) keep the value local to the function. When an
// allocation has no escaping reachable use, we mark the producing
// instruction with `stack: true`.
//
// Output is a side-table : `Set<LocalId>` of *escaping* allocations. The
// pipeline applies this by setting `stack = !escaping` on every
// StructNew / ArrayNew before fromSSA runs. Phase 5 ships the analysis
// only ; the codegen path that turns `stack: true` into actual
// stack-allocated C structs lands in a follow-up phase.

import type {
  CFGFunction, CFGModule, CFGProject, Instruction, LocalId,
} from "./cfg.ts";

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
      otherDecls: m.otherDecls,
    });
  }
  return {
    project: { modules, vtableEntries: p.vtableEntries, strings: p.strings },
    stats: { totalAllocs, stackPromoted },
  };
}

function annotateFunction(fn: CFGFunction): CFGFunction {
  const allocLocals = new Set<LocalId>();
  for (const b of fn.blocks) {
    for (const ins of b.instructions) {
      if (ins.kind === "StructNew" || ins.kind === "ArrayNew") allocLocals.add(ins.dst);
    }
  }
  if (allocLocals.size === 0) return fn;

  const escaping = computeEscaping(fn, allocLocals);

  let mutated = false;
  const newBlocks = fn.blocks.map((b) => {
    let blockMutated = false;
    const instructions = b.instructions.map((ins) => {
      if (ins.kind !== "StructNew" && ins.kind !== "ArrayNew") return ins;
      if (!allocLocals.has(ins.dst)) return ins;
      const stack = !escaping.has(ins.dst);
      if (stack === ins.stack) return ins;
      blockMutated = true;
      return { ...ins, stack };
    });
    if (!blockMutated) return b;
    mutated = true;
    return { id: b.id, instructions, terminator: b.terminator, span: b.span };
  });
  return mutated ? { ...fn, blocks: newBlocks } : fn;
}

/** Worklist : start with all locals known to escape (returned values, call
 *  args, cell-stored values, struct fields of values that already escape,
 *  ...) and propagate backward via Move and Phi sources. The result is the
 *  set of locals that escape ; allocs whose dst isn't in that set can be
 *  stack-allocated. */
function computeEscaping(fn: CFGFunction, allocLocals: ReadonlySet<LocalId>): Set<LocalId> {
  const escaping = new Set<LocalId>();
  const aliasOf = new Map<LocalId, LocalId[]>();      // dst → producers (Move src or Phi sources)

  const see = (l: LocalId): void => { escaping.add(l); };

  for (const b of fn.blocks) {
    for (const ins of b.instructions) {
      switch (ins.kind) {
        case "Move":
          appendAlias(aliasOf, ins.dst, ins.src);
          break;
        case "Phi":
          for (const s of ins.sources) appendAlias(aliasOf, ins.dst, s.value);
          break;
        case "Cast":
          // Type casts don't change identity ; treat the cast result as an
          // alias of its source.
          appendAlias(aliasOf, ins.dst, ins.value);
          break;
        case "FieldSet":
          // Storing into a struct field is an escape for the value being
          // stored *and* for the target (which may now hold heap pointers).
          // Conservative : both escape.
          see(ins.value);
          see(ins.target);
          break;
        case "ArraySet":
          see(ins.value);
          see(ins.target);
          break;
        case "ArrayPush":
          see(ins.value);
          see(ins.target);
          break;
        case "CellNew":
          // Cells are heap-allocated single-slot boxes shared across
          // closures — anything written into one outlives the current
          // frame. The contents escape ; the cell ref itself is just a
          // local until it gets captured in a closure (handled by
          // MakeClosure below).
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
          // Callees may retain refs past the call — treat every passed
          // local as escaping. Also covers the receiver of VirtualCall.
          if (ins.kind === "VirtualCall") see(ins.receiver);
          if (ins.kind === "CallIndirect") see(ins.callee);
          for (const a of ins.args) see(a);
          break;
        case "MakeClosure":
          // Closure captures its env struct ; env outlives the current
          // frame. We don't yet inspect env's contents — it'll be
          // recursively flagged via the StructNew/FieldSet that built it.
          see(ins.env);
          break;
        case "StructNew":
        case "ArrayNew":
        case "Const":
        case "BinOp":
        case "UnOp":
        case "FieldGet":
        case "ArrayGet":
        case "ArrayLen":
        case "TypeCheck":
        case "CellGet":
        case "FnRef":
          // Pure / read-only ops don't escape their operands.
          break;
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
  // Phi / Cast), then `src` escapes too. Iterate to a fixed point.
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
  return allocEscaping;
}

function appendAlias(map: Map<LocalId, LocalId[]>, dst: LocalId, src: LocalId): void {
  let arr = map.get(dst);
  if (arr === undefined) { arr = []; map.set(dst, arr); }
  arr.push(src);
}
