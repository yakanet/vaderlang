// DCE on the Mid-IR CFG. Two layers :
//
//   * Whole-program — `pruneUnreachable` walks the call graph from a set of
//     roots (user code, `@export` / `@test` / `@extern` / `main` in stdlib,
//     extern imports) and drops fns / structs / consts that nothing transitively
//     references. Filters both the CFG and the surrounding LoweredProject so
//     downstream emit sees a consistent picture.
//
//   * Intra-procedural — `eliminateDeadCFG` runs per fn :
//
//       1. Copy folding (move forwarding) — collapses the converter's
//          `$tmp = expr ; B = move $tmp` chains into `B = expr`.
//
//       2. Dead instruction elimination (DIE) — per-store liveness, then drop
//          pure instructions whose result local is not live afterward.
//          Repeated to a fixed point — eliminating one Move can make the
//          producer of its source dead too.
//
//       3. Dead local elimination (DLE) — after DIE settles, locals never read
//          and never written by a side-effecting instruction get dropped, and
//          surviving locals are renumbered into a compact range. Params keep
//          their leading slots so the bytecode emit's "params at 0..N-1"
//          convention is preserved.
//
// Functional throughout — returns new `CFGProject` / `CFGFunction` /
// `BasicBlock` / `LoweredProject` values without mutating the input.

import type {
  BasicBlock, BlockId, CFGFunction, CFGLocal, CFGModule, CFGParam,
  CFGProject, Instruction, LocalId, Terminator,
} from "./cfg.ts";
import {
  computeLiveness, countUses, dstOf, forEachReadInTerminator, forEachReadLocal,
  instructionHasSideEffect,
} from "./analyses.ts";
import { forEachReference, structInstKey, type RefVisitor, type StructInstVisitor, type VirtualCallVisitor } from "./lowered_walk.ts";

import type { LoweredDecl, LoweredModule, LoweredProject } from "../lower/index.ts";
import { isStdlibModule } from "../resolver/module.ts";
import { DEC, hasDecorator } from "../parser/decorators.ts";
import type { Decorator } from "../parser/ast.ts";
import type { EmitterCtx } from "../bytecode/emit.ts";

const NO_DECORATORS: readonly Decorator[] = [];

// =============================================================================
// Whole-program DCE — drop LoweredDecls (fns, structs, consts) unreachable
// from the program's roots. Runs *before* `buildCFGProject` so the CFG and
// the bytecode emit's per-decl walks both see the same pruned LoweredProject.
// =============================================================================

export interface PruneOpts {
  /** When true, `@test` fns count as roots — they get preserved through DCE
   *  so `vader test` can dispatch to them after compilation. Defaults to
   *  false : regular `vader run` / `vader build` drop tests so the bytecode
   *  (and emitted C) doesn't carry stdlib test code that callers can't
   *  reach. */
  readonly keepTests?: boolean;
}

/** Vtable entry index : per (trait, method) we keep every impl fn plus the
 *  receiver struct's symbol so the virtual-call walker can drop impls whose
 *  receiver isn't reachable on its own. */
interface VtableImpl { readonly fnId: number; readonly structSymId: number | null }

/** Mono variants of a generic struct share their base symbol id but live as
 *  separate `LoweredStructDecl`s with distinct `typeArgs`. The DCE indexes
 *  them on a `(symbol.id, canonicalArgsKey)` key so it can prune unused
 *  variants — `reachable.has(sym.id)` alone would keep every variant alive
 *  as soon as any one of them was reached. */
function isMonoStructInstance(d: LoweredDecl): boolean {
  return d.kind === "LoweredStructDecl" && d.origin.typeArgs.length > 0;
}

export function pruneUnreachable(lp: LoweredProject, opts: PruneOpts = {}): LoweredProject {
  // Two indexes : the symbol-keyed map covers fns, consts, and the generic
  // struct shape (typeArgs.length === 0). The instance-keyed map covers
  // mono struct variants so the walker can push the *correct* mono decl
  // for a given concrete type — without the split, every `MutableMap.put`
  // call site (sym-id-based) would push whichever Entry mono `bySymId`
  // happened to store last, and that variant's self-reference would mark
  // its own key reachable even when nothing else points at it.
  const bySymId = new Map<number, LoweredDecl>();
  const byStructInstance = new Map<string, LoweredDecl>();
  const reachable = new Set<number>();
  const reachableStructs = new Set<string>();
  const worklist: LoweredDecl[] = [];
  const keepTests = opts.keepTests ?? false;

  // Whole-program reachability is gated on the project actually exposing a
  // `main`. When it does, we treat user code uniformly with stdlib (root from
  // main + every @export/@extern + optionally @test, prune the rest). When
  // it doesn't — library target, snapshot fixture, single-file `vader run`
  // of a non-main file — every user decl stays a root, matching the prior
  // behavior so those workflows don't lose their decls.
  const hasMain = projectHasMain(lp);

  for (const m of lp.modules.values()) {
    const fromStdlib = isStdlibModule(m.displayPath);
    for (const d of m.decls) {
      const sym = d.origin.symbol;
      if (sym !== null) {
        if (isMonoStructInstance(d)) {
          byStructInstance.set(structInstKey(sym.id, d.origin.typeArgs), d);
        } else {
          bySymId.set(sym.id, d);
        }
      }
      if (!isRoot(d, fromStdlib, hasMain, keepTests)) continue;
      if (sym !== null) {
        reachable.add(sym.id);
        if (isMonoStructInstance(d)) {
          reachableStructs.add(structInstKey(sym.id, d.origin.typeArgs));
        }
      }
      worklist.push(d);
    }
  }

  const implsByVtableKey = new Map<string, VtableImpl[]>();
  for (const e of lp.vtableEntries) {
    const key = `${e.traitName}|${e.methodName}`;
    let bucket = implsByVtableKey.get(key);
    if (bucket === undefined) { bucket = []; implsByVtableKey.set(key, bucket); }
    const structSymId = e.structType.kind === "Struct" ? e.structType.symbol.id : null;
    bucket.push({ fnId: e.fnSymbol.id, structSymId });
  }

  const visit: RefVisitor = (id) => {
    if (reachable.has(id)) return;
    reachable.add(id);
    const decl = bySymId.get(id);
    if (decl !== undefined) worklist.push(decl);
  };
  const visitStructInst: StructInstVisitor = (key) => {
    if (reachableStructs.has(key)) return;
    reachableStructs.add(key);
    const decl = byStructInstance.get(key);
    if (decl !== undefined) worklist.push(decl);
  };
  // Defer virtual visits until the main walk stabilises — at the moment a
  // virtual call is first encountered, its receiver struct may not yet be
  // marked reachable. We collect (trait, method) pairs and re-process them
  // to fixpoint after the worklist drains.
  const pendingVirtual: Array<[string, string]> = [];
  const visitVirtual: VirtualCallVisitor = (trait, method) => {
    pendingVirtual.push([trait, method]);
  };
  const drainPending = (): boolean => {
    let changed = false;
    for (const [trait, method] of pendingVirtual) {
      const entries = implsByVtableKey.get(`${trait}|${method}`);
      if (entries === undefined) continue;
      for (const e of entries) {
        // Non-struct impls (primitive receivers) have no concrete struct to
        // gate on — keep them ; concrete-struct impls only count when the
        // receiver type has been reached through some other path.
        if (e.structSymId !== null && !reachable.has(e.structSymId)) continue;
        if (!reachable.has(e.fnId)) {
          visit(e.fnId);
          changed = true;
        }
      }
    }
    return changed;
  };
  for (;;) {
    while (worklist.length > 0) forEachReference(worklist.pop()!, visit, visitVirtual, visitStructInst);
    if (!drainPending()) break;
  }

  const modules = new Map<string, LoweredModule>();
  for (const [id, m] of lp.modules) {
    const kept = m.decls.filter((d) => declSurvives(d, reachable, reachableStructs));
    modules.set(id, kept.length === m.decls.length ? m : {
      moduleId: m.moduleId, displayPath: m.displayPath, decls: kept,
    });
  }
  // vtableEntries are filtered transitively by the emit's lookup of fn symbol
  // ids — no need to mirror the filter here.
  return { modules, vtableEntries: lp.vtableEntries };
}

function declSurvives(
  d: LoweredDecl, reachable: ReadonlySet<number>, reachableStructs: ReadonlySet<string>,
): boolean {
  const sym = d.origin.symbol;
  if (sym === null) return true;
  if (!reachable.has(sym.id)) return false;
  if (isMonoStructInstance(d)) {
    return reachableStructs.has(structInstKey(sym.id, d.origin.typeArgs));
  }
  return true;
}

function isRoot(d: LoweredDecl, fromStdlib: boolean, hasMain: boolean, keepTests: boolean): boolean {
  // No `main` anywhere — every user decl stays a root so library targets,
  // snapshot fixtures, and `vader run` of a script without `main` keep
  // their decls intact. Stdlib is always reachability-only.
  if (!fromStdlib && !hasMain) return true;
  if (d.kind === "LoweredFnDecl") {
    if (d.body === null) return true;                    // @extern import
    if (d.origin.isMain) return true;
  }
  const decs = d.origin.decl.kind === "ImplDecl" ? NO_DECORATORS : d.origin.decl.decorators;
  if (hasDecorator(decs, DEC.export) || hasDecorator(decs, DEC.extern)) return true;
  // @test fns only count as roots in test-runner builds. Regular run/build
  // drops them so the bytecode doesn't carry stdlib test code that nothing
  // can dispatch to.
  return keepTests && hasDecorator(decs, DEC.test);
}

function projectHasMain(lp: LoweredProject): boolean {
  for (const m of lp.modules.values()) {
    for (const d of m.decls) {
      if (d.kind === "LoweredFnDecl" && d.body !== null && d.origin.isMain) {
        return true;
      }
    }
  }
  return false;
}

// =============================================================================
// Intra-procedural DCE — copy folding + DIE + DLE.
// =============================================================================

export function eliminateDeadCFG(p: CFGProject): CFGProject {
  const modules = new Map<string, CFGModule>();
  for (const [id, m] of p.modules) {
    modules.set(id, {
      moduleId: m.moduleId,
      displayPath: m.displayPath,
      functions: m.functions.map(optimiseFunction),
      externs: m.externs,
      structDecls: m.structDecls,
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
    externName: fn.externName,
    isExtern: fn.isExtern,
    isExported: fn.isExported,
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

// =============================================================================
// Bytecode-level DCE — drop imports no `call.import` op references and
// renumber survivors. Runs after `OP_INTRINSIC_BY_MANGLED` has routed the
// primitive trait intrinsics (`std_core$i32$Add$add`, `std_core$bool$Equals$equals`,
// …) to dedicated bytecode ops, leaving the reserved import slots dead.
// Without this, every backend (VM unbound-import stub, C-emit shim, future
// WASM import section) propagates ~60 trap stubs for primitive ops the
// runtime never actually invokes.
// =============================================================================

export function pruneUnusedImports(ctx: EmitterCtx): void {
  const used = new Set<number>();
  for (const fn of ctx.functions) {
    for (const op of fn.body) {
      if (op.kind === "call.import") used.add(op.importIndex);
    }
  }
  if (used.size === ctx.imports.length) return;

  const remap = new Int32Array(ctx.imports.length);
  const kept: typeof ctx.imports = [];
  for (let i = 0; i < ctx.imports.length; i++) {
    if (used.has(i)) {
      remap[i] = kept.length;
      kept.push(ctx.imports[i]!);
    } else {
      remap[i] = -1;
    }
  }
  for (const fn of ctx.functions) {
    for (let i = 0; i < fn.body.length; i++) {
      const op = fn.body[i]!;
      if (op.kind !== "call.import") continue;
      fn.body[i] = { kind: "call.import", importIndex: remap[op.importIndex]! };
    }
  }
  // `importIndexBySymId` stays untouched — it's owned by the EmitterCtx and
  // post-emit consumers don't read it. Mutating `ctx.imports` length keeps
  // the Object identity the BytecodeModule will close over.
  ctx.imports.length = 0;
  for (const e of kept) ctx.imports.push(e);
}

