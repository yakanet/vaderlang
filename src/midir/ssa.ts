// SSA conversion (`toSSA`) and out-of-SSA lowering (`fromSSA`) for the
// Mid-IR CFG. Standard Cytron et al. construction:
//
//   1. Compute dominators + dominance frontiers (in `analyses.ts`).
//   2. For each variable v defined more than once, insert phi(v) at every
//      block in DF+(defBlocks(v)).
//   3. Rename: DFS the dominator tree, maintaining a per-variable stack of
//      "current version" LocalIds. Each new definition pushes a fresh
//      LocalId; reads pick up the stack-top.
//
// `fromSSA` undoes the construction by inserting `Move dst src=phi-source`
// at the end of each predecessor (right before the terminator) for every
// phi, then dropping the phi nodes.

import type {
  BasicBlock, BlockId, CFGFunction, CFGLocal, CFGModule, CFGProject,
  Instruction, InstrPhi, LocalId, Terminator,
} from "./cfg.ts";
import {
  computeDominanceFrontiers, computeDominators, computeLiveness, dstOf,
  forEachReadInTerminator, forEachReadLocal, predecessorsOf, successorsOf,
} from "./analyses.ts";
import { CompilerBugError } from "../diagnostics/errors.ts";

// =============================================================================
// `toSSA` — Cytron et al. SSA construction
// =============================================================================

export function toSSA(p: CFGProject): CFGProject {
  const modules = new Map<string, CFGModule>();
  for (const [id, m] of p.modules) {
    modules.set(id, {
      moduleId: m.moduleId,
      displayPath: m.displayPath,
      functions: m.functions.map(toSSAFn),
      externs: m.externs,
      structDecls: m.structDecls,
    });
  }
  return { modules, vtableEntries: p.vtableEntries, strings: p.strings };
}

function toSSAFn(fn: CFGFunction): CFGFunction {
  const preds = predecessorsOf(fn);
  const idom = computeDominators(fn, preds);
  const df = computeDominanceFrontiers(fn, preds, idom);
  // Pruned SSA : compute liveness up front so we only insert phi(v) at a
  // join Y when v ∈ live-in(Y). Without this we materialise phis for
  // dead-at-the-join variables, which fromSSA then expands into useless
  // moves at every predecessor — DCE only catches half of them.
  const { liveIn } = computeLiveness(fn);

  // Mutable shadow of the function — instructions and locals are rewritten
  // throughout the pass, then frozen back into a `CFGFunction` at the end.
  const locals: CFGLocal[] = [...fn.locals];
  const blocks: { id: BlockId; phis: InstrPhi[]; instructions: Instruction[]; terminator: Terminator; span: BasicBlock["span"] }[] =
    fn.blocks.map((b) => ({
      id: b.id, phis: [], instructions: [...b.instructions],
      terminator: b.terminator, span: b.span,
    }));

  // 1. Collect def blocks per original variable.
  const defBlocks = new Map<LocalId, Set<BlockId>>();
  for (const b of blocks) {
    for (const ins of b.instructions) {
      const d = dstOf(ins);
      if (d === null) continue;
      let s = defBlocks.get(d);
      if (s === undefined) { s = new Set(); defBlocks.set(d, s); }
      s.add(b.id);
    }
  }

  // 2. Insert phi nodes at each block in DF+(defBlocks(v)) — pruned by
  //    liveness : skip joins where v isn't live-in.
  for (const [v, defs] of defBlocks) {
    const phiBlocks = new Set<BlockId>();
    const work: BlockId[] = [...defs];
    while (work.length > 0) {
      const x = work.pop()!;
      for (const y of df[x]!) {
        if (phiBlocks.has(y)) continue;
        if (!liveIn[y]!.has(v)) continue;
        phiBlocks.add(y);
        const phi: InstrPhi = {
          kind: "Phi", dst: v,                        // renamed in pass 3
          sources: [],                                // filled in pass 3
          type: locals[v]!.type, span: blocks[y]!.span,
        };
        blocks[y]!.phis.push(phi);
        if (!defs.has(y)) work.push(y);
      }
    }
  }

  // 3. Rename : DFS the dominator tree with per-variable stacks.
  const stacks = new Map<LocalId, LocalId[]>();
  for (let i = 0; i < locals.length; i++) stacks.set(i, [i]);   // every original local gets its own stack
  // Reverse map from a renamed-LocalId back to the original it descends from.
  // Phi-source resolution (in the rename pass below) needs this lookup ; the
  // lazy `<name>#<id>` parsing it replaced was O(locals) per phi-source visit.
  const originBy = new Map<LocalId, LocalId>();

  const allocFresh = (origin: LocalId): LocalId => {
    const id = locals.length;
    const orig = locals[origin];
    if (orig === undefined) {
      throw new CompilerBugError(`ssa.allocFresh: origin=${origin} out of range (locals.length=${locals.length}) in fn ${fn.mangled}`);
    }
    locals.push({ name: `${orig.name}#${id}`, type: orig.type, symbol: orig.symbol });
    stacks.get(origin)!.push(id);
    stacks.set(id, [id]);
    originBy.set(id, origin);
    return id;
  };

  const top = (l: LocalId): LocalId => {
    const s = stacks.get(l);
    if (s === undefined || s.length === 0) return l;
    return s[s.length - 1]!;
  };

  // Build dominator-tree children for the DFS.
  const domChildren: BlockId[][] = blocks.map(() => []);
  for (let b = 0; b < blocks.length; b++) {
    const parent = idom[b]!;
    if (parent !== b && parent !== -1) domChildren[parent]!.push(b);
  }

  const renameBlock = (b: BlockId): void => {
    const block = blocks[b]!;
    const pushed: LocalId[] = [];

    // Phi destinations get fresh versions so subsequent reads in the block
    // pick them up via the stack.
    for (const phi of block.phis) {
      const orig = phi.dst;
      const fresh = allocFresh(orig);
      pushed.push(orig);
      (phi as { dst: LocalId }).dst = fresh;
    }

    // Non-phi instructions : rewrite reads first, then dst.
    for (let i = 0; i < block.instructions.length; i++) {
      block.instructions[i] = renameInstr(block.instructions[i]!, top, allocFresh, pushed);
    }
    block.terminator = renameTerminator(block.terminator, top);

    // Successors' phis pick up our top-of-stack value for the slots indexed
    // by us (B is the predecessor).
    const succs = successorsOf(block);
    for (const s of succs) {
      for (const phi of blocks[s]!.phis) {
        const original = originBy.get(phi.dst) ?? phi.dst;
        const value = top(original);
        const newSources = [...phi.sources, { block: b, value }];
        (phi as { sources: readonly { block: BlockId; value: LocalId }[] }).sources = newSources;
      }
    }

    // Recurse on dom-tree children.
    for (const child of domChildren[b]!) renameBlock(child);

    // Pop versions pushed by this block.
    for (let i = pushed.length - 1; i >= 0; i--) stacks.get(pushed[i]!)!.pop();
  };
  renameBlock(fn.entry);

  // Freeze : merge phis at the head of each block, drop the scratch shape.
  const newBlocks: BasicBlock[] = blocks.map((b) => ({
    id: b.id,
    instructions: [...b.phis, ...b.instructions],
    terminator: b.terminator,
    span: b.span,
  }));

  return {
    mangled: fn.mangled,
    params: fn.params,
    returnType: fn.returnType,
    locals,
    blocks: newBlocks,
    entry: fn.entry,
    origin: fn.origin,
    externName: fn.externName,
    isExtern: fn.isExtern,
    isExported: fn.isExported,
  };
}

function renameInstr(
  ins: Instruction, top: (l: LocalId) => LocalId,
  allocFresh: (orig: LocalId) => LocalId, pushed: LocalId[],
): Instruction {
  if (ins.kind === "Phi") return ins;       // phi dsts handled by caller

  const renamed = renameReads(ins, top);
  const dst = dstOf(renamed);
  if (dst === null) return renamed;
  const fresh = allocFresh(dst);
  pushed.push(dst);
  return rewriteDst(renamed, fresh);
}

function renameReads(ins: Instruction, top: (l: LocalId) => LocalId): Instruction {
  switch (ins.kind) {
    case "Const":
    case "FnRef":
      return ins;
    case "Move":         return { ...ins, src: top(ins.src) };
    case "BinOp":        return { ...ins, lhs: top(ins.lhs), rhs: top(ins.rhs) };
    case "UnOp":         return { ...ins, operand: top(ins.operand) };
    case "Phi":          return ins;
    case "Call":         return { ...ins, args: ins.args.map(top) };
    case "CallIndirect": return { ...ins, callee: top(ins.callee), args: ins.args.map(top) };
    case "VirtualCall":  return { ...ins, receiver: top(ins.receiver), args: ins.args.map(top) };
    case "FieldGet":     return { ...ins, target: top(ins.target) };
    case "FieldSet":     return { ...ins, target: top(ins.target), value: top(ins.value) };
    case "ArrayGet":     return { ...ins, target: top(ins.target), index: top(ins.index) };
    case "ArraySet":     return { ...ins, target: top(ins.target), index: top(ins.index), value: top(ins.value) };
    case "ArrayLen":     return { ...ins, target: top(ins.target) };
    case "ArrayPush":    return { ...ins, target: top(ins.target), value: top(ins.value) };
    case "StructNew":    return { ...ins, fields: ins.fields.map(top) };
    case "ArrayNew":     return { ...ins, elements: ins.elements.map(top) };
    case "TypeCheck":    return { ...ins, value: top(ins.value) };
    case "Cast":         return { ...ins, value: top(ins.value) };
    case "CellNew":      return { ...ins, value: top(ins.value) };
    case "CellGet":      return { ...ins, cell: top(ins.cell) };
    case "CellSet":      return { ...ins, cell: top(ins.cell), value: top(ins.value) };
    case "MakeClosure":  return { ...ins, env: top(ins.env) };
    case "Intrinsic":    return { ...ins, args: ins.args.map(top) };
  }
}

function rewriteDst(ins: Instruction, dst: LocalId): Instruction {
  switch (ins.kind) {
    case "Const":         return { ...ins, dst };
    case "Move":          return { ...ins, dst };
    case "BinOp":         return { ...ins, dst };
    case "UnOp":          return { ...ins, dst };
    case "Phi":           return { ...ins, dst };
    case "Call":          return { ...ins, dst };
    case "CallIndirect":  return { ...ins, dst };
    case "VirtualCall":   return { ...ins, dst };
    case "FnRef":         return { ...ins, dst };
    case "FieldGet":      return { ...ins, dst };
    case "ArrayGet":      return { ...ins, dst };
    case "ArrayLen":      return { ...ins, dst };
    case "StructNew":     return { ...ins, dst };
    case "ArrayNew":      return { ...ins, dst };
    case "TypeCheck":     return { ...ins, dst };
    case "Cast":          return { ...ins, dst };
    case "CellNew":       return { ...ins, dst };
    case "CellGet":       return { ...ins, dst };
    case "MakeClosure":   return { ...ins, dst };
    case "Intrinsic":     return { ...ins, dst };
    default:              return ins;
  }
}

function renameTerminator(t: Terminator, top: (l: LocalId) => LocalId): Terminator {
  switch (t.kind) {
    case "Branch":
    case "Unreachable": return t;
    case "CondBranch":  return { ...t, cond: top(t.cond) };
    case "Return":      return { ...t, value: t.value === null ? null : top(t.value) };
  }
}

// =============================================================================
// `fromSSA` — drop phis, materialise them as `Move`s in predecessors
// =============================================================================

export function fromSSA(p: CFGProject): CFGProject {
  const modules = new Map<string, CFGModule>();
  for (const [id, m] of p.modules) {
    modules.set(id, {
      moduleId: m.moduleId,
      displayPath: m.displayPath,
      functions: m.functions.map(fromSSAFn),
      externs: m.externs,
      structDecls: m.structDecls,
    });
  }
  return { modules, vtableEntries: p.vtableEntries, strings: p.strings };
}

function fromSSAFn(fn: CFGFunction): CFGFunction {
  // Per-predecessor moves to insert just before the predecessor's terminator.
  // Phi swap problem (cyclic moves between phis) is rare in CFGs derived
  // from structured source — we don't handle it specially today.
  type PhiMove = { dst: LocalId; src: LocalId; span: Instruction["span"] };
  const moves = new Map<BlockId, PhiMove[]>();
  for (const b of fn.blocks) {
    for (const ins of b.instructions) {
      if (ins.kind !== "Phi") break;
      for (const s of ins.sources) {
        let arr = moves.get(s.block);
        if (arr === undefined) { arr = []; moves.set(s.block, arr); }
        arr.push({ dst: ins.dst, src: s.value, span: ins.span });
      }
    }
  }

  const newBlocks: BasicBlock[] = fn.blocks.map((b) => {
    const phisDropped = b.instructions.filter((ins) => ins.kind !== "Phi");
    const tail = moves.get(b.id);
    if (tail !== undefined) {
      for (const m of tail) {
        if (m.dst === m.src) continue;       // identity moves are no-ops
        phisDropped.push({
          kind: "Move", dst: m.dst, src: m.src, span: m.span,
        });
      }
    }
    return { id: b.id, instructions: phisDropped, terminator: b.terminator, span: b.span };
  });

  return {
    mangled: fn.mangled,
    params: fn.params,
    returnType: fn.returnType,
    locals: fn.locals,
    blocks: newBlocks,
    entry: fn.entry,
    origin: fn.origin,
    externName: fn.externName,
    isExtern: fn.isExtern,
    isExported: fn.isExported,
  };
}

// `forEachReadLocal` and friends are re-exported to satisfy any caller that
// imports through this module. The actual implementations live in analyses.
export { forEachReadLocal, forEachReadInTerminator };
