// CFG → bytecode emitter (Phase 2 of the Mid-IR refactor).
//
// Reuses the LoweredAST → bytecode emitter's project context (`EmitterCtx`)
// and helpers (intern type / string / fn index, fn signatures, peephole)
// for everything *outside* the function body. Function bodies come from
// the CFG : we run a recursive structurer that recovers WASM-style
// `block` / `loop` / `if` nesting from basic blocks + terminators.
//
// Reducibility is guaranteed by construction (the converter only ever
// produces patterns derived from structured source — no user-visible
// `goto`). The structurer relies on dominators + immediate post-dominators
// computed once per fn ; both via the simple iterative algorithm
// (Cooper, Harvey, Kennedy : "A Simple, Fast Dominance Algorithm").

import type { Span } from "../diagnostics/diagnostic.ts";
import type * as L from "../lower/lowered-ast.ts";
import type { LoweredProject } from "../lower/index.ts";
import type { Type } from "../typecheck/types.ts";
import { TY } from "../typecheck/types.ts";

import {
  binaryOpFor, buildVtables, declareLocal, emitFloatConst, emitIntConst,
  internCellType, internString, internType, newEmitterCtx,
  OP_INTRINSIC_BY_MANGLED, pushOp, reserveDecl, valTypeOf,
  type EmitOptions, type EmitterCtx, type FnEmitCtx,
} from "../bytecode/emit.ts";
import type {
  BitNotOpKind, ConvertOpKind, IntrinsicId, NegOpKind, Op,
} from "../bytecode/ops.ts";
import { intrinsicIdByName } from "../bytecode/ops.ts";
import type { BytecodeModule, BcLocal, DebugPos } from "../bytecode/module.ts";
import { runPeepholes } from "../bytecode/peephole.ts";
import { isIntegerVal, isNumericVal, type ValType } from "../bytecode/types.ts";

import type {
  BlockId, CFGFunction, CFGProject,
  Instruction, LocalId,
} from "./cfg.ts";
import { predecessorsOf, successorsOf } from "./analyses.ts";

// ============================================================================
// Project-level entry point
// ============================================================================

export function emitBytecodeFromCFG(
  lp: LoweredProject, cfg: CFGProject, name: string, options: EmitOptions = {},
): BytecodeModule {
  const ctx = newEmitterCtx(options.optimize ?? true, options.implRegistry ?? null);

  // Pass 1 : reserve via the lowered decls so signatures, struct types,
  // const decls, fn indices, and @export entries match the canonical path.
  for (const m of lp.modules.values()) {
    for (const d of m.decls) reserveDecl(d, ctx);
  }

  // Index CFG functions by mangled name for lookup during pass 2.
  const cfgByMangled = new Map<string, CFGFunction>();
  for (const m of cfg.modules.values()) {
    for (const f of m.functions) cfgByMangled.set(f.mangled, f);
  }

  // Pre-translate the CFG's string indices into the bytecode pool's indices
  // so per-instr emit is a plain array lookup instead of a hash re-intern.
  const stringIndexMap: number[] = cfg.strings.map((s) => internString(ctx, s));

  // Pass 2 : emit fn bodies from the CFG. Imports and bodyless decls are
  // skipped here — they got their import-table entry in pass 1.
  for (const m of lp.modules.values()) {
    for (const d of m.decls) {
      if (d.kind !== "LoweredFnDecl" || d.body === null) continue;
      if (d.origin.symbol === null) continue;
      const fnIndex = ctx.fnIndexBySymId.get(d.origin.symbol.id);
      if (fnIndex === undefined) continue;       // routed to imports
      const cfgFn = cfgByMangled.get(d.mangled);
      if (cfgFn === undefined) continue;

      const slot = ctx.functions[fnIndex]!;
      const fn: FnEmitCtx = {
        project: ctx,
        signature: slot.signature,
        locals: [],
        body: [],
        debug: [],
        slotBySymbolId: new Map(),
        labelStack: [],
      };

      emitCFGFunctionBody(cfgFn, fn, ctx, stringIndexMap);
      if (ctx.optimize) runPeepholes(fn);
      // Mutate slot via the shared mutable shape the legacy emit also uses.
      (slot as { locals: BcLocal[] }).locals = fn.locals;
      (slot as { body: Op[] }).body = fn.body;
      (slot as { debug: (DebugPos | null)[] }).debug = fn.debug;
    }
  }

  return {
    name,
    types:     ctx.types,
    strings:   ctx.strings,
    functions: ctx.functions,
    imports:   ctx.imports,
    exports:   ctx.exports,
    implTable: ctx.implTable,
    vtables:   buildVtables(ctx, cfg.vtableEntries),
  };
}

// ============================================================================
// Per-fn emission
// ============================================================================

interface FnEmitCfg {
  readonly fn: CFGFunction;
  readonly emit: FnEmitCtx;
  readonly project: EmitterCtx;
  /** CFG string-index → bytecode pool index. Built once at the project
   *  emit's entry, then read per `Const string` instruction. */
  readonly stringIndexMap: readonly number[];
  /** CFG locals → bytecode slot indices (params live at 0..N-1, additional
   *  locals are appended via declareLocal). */
  readonly localToSlot: number[];
  /** Per-block predecessor lists (precomputed once). */
  readonly preds: readonly (readonly BlockId[])[];
  /** idom[b] = immediate dominator of `b` (b for the entry). */
  readonly idom: readonly number[];
  /** ipostdom[b] = immediate post-dominator of `b` (-1 when none — i.e. block
   *  terminates via Return / Unreachable with no successor in the dominance
   *  sense). */
  readonly ipostdom: readonly number[];
  /** For each loop header H, the unique exit block (the block following the
   *  loop). null when the loop has no natural exit (infinite loop). */
  readonly loopExit: ReadonlyMap<BlockId, BlockId | null>;
  /** Stack of structuring scopes, in nesting order. The top is the innermost. */
  readonly scopes: ScopeFrame[];
  /** Loop headers already wrapped in `block`+`loop`. When a recursive
   *  emitRange revisits an already-wrapped header (e.g. emitting the loop
   *  body), we skip re-wrapping and emit the header as a regular block. */
  readonly wrappedLoopHeaders: Set<BlockId>;
}

/** Active structured scope. `target` is the BlockId that `br <depth-of-this-frame>`
 *  jumps to in source-CFG terms. `kind` distinguishes how the bytecode `br`
 *  semantics map (`block`/`if` jump past `end` ; `loop` jumps back to start). */
interface ScopeFrame {
  readonly kind: "block" | "loop" | "if";
  readonly target: BlockId;
}

function emitCFGFunctionBody(
  cfgFn: CFGFunction, fn: FnEmitCtx, project: EmitterCtx, stringIndexMap: readonly number[],
): void {
  // Map CFG locals to bytecode slots. Params reuse slots 0..N-1 (same shape
  // as the legacy emitter). Additional locals get fresh bytecode slots.
  const localToSlot: number[] = new Array(cfgFn.locals.length);
  for (let i = 0; i < cfgFn.params.length; i++) {
    localToSlot[i] = i;
    // Register the param's user symbol so identifiers resolve through the
    // legacy emit helpers if we ever fall back through them.
    fn.slotBySymbolId.set(cfgFn.params[i]!.symbol.id, i);
  }
  for (let i = cfgFn.params.length; i < cfgFn.locals.length; i++) {
    const local = cfgFn.locals[i]!;
    const slot = declareLocal(fn, local.name, valTypeOf(local.type));
    localToSlot[i] = slot;
    if (local.symbol !== null) fn.slotBySymbolId.set(local.symbol.id, slot);
  }

  // Run the structuring analysis once per fn.
  const preds = predecessorsOf(cfgFn);
  const idom = computeDominators(cfgFn, preds);
  const ipostdom = computePostDominators(cfgFn);
  const loopExit = findLoopExits(cfgFn, preds, idom);

  const ctx: FnEmitCfg = {
    fn: cfgFn, emit: fn, project, stringIndexMap,
    localToSlot, preds, idom, ipostdom, loopExit,
    scopes: [],
    wrappedLoopHeaders: new Set(),
  };

  // Single-shot emit from the entry block. `until=null` because the function
  // body must always terminate via Return / Unreachable on every path.
  emitRange(ctx, cfgFn.entry, null);
}

// ============================================================================
// Structurer — recursive recovery of WASM-style nesting
// ============================================================================

function emitRange(ctx: FnEmitCfg, start: BlockId, until: BlockId | null): void {
  let cur: BlockId | null = start;
  while (cur !== null && cur !== until) {
    const block = ctx.fn.blocks[cur]!;

    // First visit to a loop header → wrap in `block` (break-target) +
    // `loop` (continue-target), then recurse on the body until the exit.
    // Subsequent visits (back-edges, nested control flow inside the body)
    // see this header as already wrapped and emit it as a plain block.
    if (ctx.loopExit.has(cur) && !ctx.wrappedLoopHeaders.has(cur)) {
      const exit: BlockId | null = ctx.loopExit.get(cur) ?? null;
      const exitTarget: BlockId = exit ?? -1;
      pushOp(ctx.emit, { kind: "block", result: "void" }, block.span);
      ctx.scopes.push({ kind: "block", target: exitTarget });
      pushOp(ctx.emit, { kind: "loop", result: "void" }, block.span);
      ctx.scopes.push({ kind: "loop", target: cur });
      ctx.wrappedLoopHeaders.add(cur);
      emitRange(ctx, cur, exit);
      ctx.wrappedLoopHeaders.delete(cur);
      ctx.scopes.pop();
      pushOp(ctx.emit, { kind: "end" }, block.span);
      ctx.scopes.pop();
      pushOp(ctx.emit, { kind: "end" }, block.span);
      cur = exit;
      continue;
    }

    cur = emitBlockContents(ctx, cur, until);
  }
}

/** Emit one block's instructions and dispatch on its terminator. Returns
 *  the `BlockId` to continue from (linear fall-through), or `null` when
 *  the terminator already left the current scope (Return / Unreachable /
 *  `br` jump). */
function emitBlockContents(
  ctx: FnEmitCfg, blockId: BlockId, until: BlockId | null,
): BlockId | null {
  const block = ctx.fn.blocks[blockId]!;
  for (const ins of block.instructions) emitInstr(ctx, ins);

  const t = block.terminator;
  switch (t.kind) {
    case "Return": {
      if (t.value !== null) emitGet(ctx, t.value, t.span);
      pushOp(ctx.emit, { kind: "return" }, t.span);
      return null;
    }
    case "Unreachable": {
      pushOp(ctx.emit, { kind: "unreachable" }, t.span);
      return null;
    }
    case "Branch": {
      if (t.target === until) return null;       // fall through to caller's `until`
      const depth = depthOfTarget(ctx, t.target);
      if (depth !== null) {
        pushOp(ctx.emit, { kind: "br", depth }, t.span);
        return null;
      }
      return t.target;       // continue linearly
    }
    case "CondBranch": {
      const merge = condBranchMerge(ctx, blockId, until);
      emitGet(ctx, t.cond, t.span);
      pushOp(ctx.emit, { kind: "if", result: "void" }, t.span);
      ctx.scopes.push({ kind: "if", target: merge ?? -1 });
      if (merge === null || t.then !== merge) emitRange(ctx, t.then, merge);
      pushOp(ctx.emit, { kind: "else" }, t.span);
      if (merge === null || t.else !== merge) emitRange(ctx, t.else, merge);
      ctx.scopes.pop();
      pushOp(ctx.emit, { kind: "end" }, t.span);
      return merge;
    }
  }
}

/** Walk the scope stack to find the structured-bytecode `br` depth that
 *  reaches `target`. Returns null when no scope frame matches — caller falls
 *  back to a linear branch. */
function depthOfTarget(ctx: FnEmitCfg, target: BlockId): number | null {
  for (let i = ctx.scopes.length - 1; i >= 0; i--) {
    if (ctx.scopes[i]!.target === target) return ctx.scopes.length - 1 - i;
  }
  return null;
}

/** Pick the merge block for a CondBranch. Uses the immediate post-dominator
 *  when one exists ; falls back to `until` when both arms terminate
 *  (Return / Unreachable / `br` out) ; returns `null` when the post-dominator
 *  points back inside a loop we've already wrapped — in that case both arms
 *  necessarily emit `br <continue>` and the if has no fall-through. */
function condBranchMerge(
  ctx: FnEmitCfg, blockId: BlockId, until: BlockId | null,
): BlockId | null {
  const post = ctx.ipostdom[blockId]!;
  if (post < 0) return until;
  if (ctx.wrappedLoopHeaders.has(post)) return null;
  return post;
}

function dominates(idom: readonly number[], a: BlockId, b: BlockId): boolean {
  let cur = b;
  while (cur !== -1) {
    if (cur === a) return true;
    const next = idom[cur]!;
    if (next === cur) return cur === a;       // entry's idom is itself
    cur = next;
  }
  return false;
}

// ============================================================================
// Instruction emission — mirrors `src/bytecode/emit.ts`'s `emitExpr`/`emitStmt`
// but reads operands from CFG locals instead of recursing on AST nodes.
// ============================================================================

function emitInstr(ctx: FnEmitCfg, ins: Instruction): void {
  switch (ins.kind) {
    case "Const":           return emitConstInstr(ctx, ins);
    case "Move":            return emitMove(ctx, ins);
    case "BinOp":           return emitBinOp(ctx, ins);
    case "UnOp":            return emitUnOp(ctx, ins);
    case "Call":            return emitCallInstr(ctx, ins);
    case "CallIndirect":    return emitCallIndirect(ctx, ins);
    case "FnRef":           return emitFnRef(ctx, ins);
    case "VirtualCall":     return emitVirtualCall(ctx, ins);
    case "FieldGet":        return emitFieldGet(ctx, ins);
    case "FieldSet":        return emitFieldSet(ctx, ins);
    case "ArrayGet":        return emitArrayGet(ctx, ins);
    case "ArraySet":        return emitArraySet(ctx, ins);
    case "ArrayLen":        return emitArrayLen(ctx, ins);
    case "ArrayPush":       return emitArrayPush(ctx, ins);
    case "StructNew":       return emitStructNew(ctx, ins);
    case "ArrayNew":        return emitArrayNew(ctx, ins);
    case "TypeCheck":       return emitTypeCheck(ctx, ins);
    case "Cast":            return emitCast(ctx, ins);
    case "CellNew":         return emitCellNew(ctx, ins);
    case "CellGet":         return emitCellGet(ctx, ins);
    case "CellSet":         return emitCellSet(ctx, ins);
    case "MakeClosure":     return emitMakeClosureInstr(ctx, ins);
    case "Intrinsic":       return emitIntrinsicInstr(ctx, ins);
  }
}

function emitConstInstr(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Const" }>): void {
  const v = ins.value;
  switch (v.kind) {
    case "int":    emitIntConst(ctx.emit, v.value, valTypeOf(ins.type), ins.span); break;
    case "float":  emitFloatConst(ctx.emit, v.value, valTypeOf(ins.type), ins.span); break;
    case "bool":   pushOp(ctx.emit, { kind: "bool.const",  value: v.value }, ins.span); break;
    case "char":   pushOp(ctx.emit, { kind: "char.const",  value: v.value }, ins.span); break;
    case "string": pushOp(ctx.emit, { kind: "string.const", index: stringIndex(ctx, v) }, ins.span); break;
    case "null":   pushOp(ctx.emit, { kind: "null.const" }, ins.span); break;
  }
  emitSet(ctx, ins.dst, ins.span);
}

function stringIndex(ctx: FnEmitCfg, v: { kind: "string"; index: number }): number {
  return ctx.stringIndexMap[v.index] ?? 0;
}

function emitMove(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Move" }>): void {
  emitGet(ctx, ins.src, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitBinOp(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "BinOp" }>): void {
  emitGet(ctx, ins.lhs, ins.span);
  emitGet(ctx, ins.rhs, ins.span);
  pushOp(ctx.emit, binaryOpFor(ins.op, valTypeOf(typeOfLocal(ctx, ins.lhs))), ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitUnOp(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "UnOp" }>): void {
  emitGet(ctx, ins.operand, ins.span);
  const opVal = valTypeOf(typeOfLocal(ctx, ins.operand));
  switch (ins.op) {
    case "neg":
      if (isNumericVal(opVal)) pushOp(ctx.emit, { kind: `${opVal}.neg` as NegOpKind }, ins.span);
      else pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
      break;
    case "not":   pushOp(ctx.emit, { kind: "bool.not" }, ins.span); break;
    case "bitnot":
      if (isIntegerVal(opVal)) pushOp(ctx.emit, { kind: `${opVal}.bitnot` as BitNotOpKind }, ins.span);
      else pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
      break;
  }
  emitSet(ctx, ins.dst, ins.span);
}

function emitCallInstr(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Call" }>): void {
  const importIdx = ctx.project.importIndexBySymId.get(ins.callee.id);
  if (importIdx !== undefined) {
    const imp = ctx.project.imports[importIdx]!;
    const opIntrinsic = OP_INTRINSIC_BY_MANGLED.get(imp.mangledName);
    if (opIntrinsic !== undefined) {
      for (const a of ins.args) emitGet(ctx, a, ins.span);
      pushOp(ctx.emit, opIntrinsic(), ins.span);
      if (ins.dst !== null) emitSet(ctx, ins.dst, ins.span);
      return;
    }
  }
  const fnIdx = ctx.project.fnIndexBySymId.get(ins.callee.id);
  if (fnIdx !== undefined) {
    for (const a of ins.args) emitGet(ctx, a, ins.span);
    pushOp(ctx.emit, { kind: "call", fnIndex: fnIdx }, ins.span);
    if (ins.dst !== null) emitSet(ctx, ins.dst, ins.span);
    return;
  }
  if (importIdx !== undefined) {
    for (const a of ins.args) emitGet(ctx, a, ins.span);
    pushOp(ctx.emit, { kind: "call.import", importIndex: importIdx }, ins.span);
    if (ins.dst !== null) emitSet(ctx, ins.dst, ins.span);
    return;
  }
  // Fall-through : same `unreachable` policy as the legacy emit.
  for (const a of ins.args) emitGet(ctx, a, ins.span);
  pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
}

function emitCallIndirect(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "CallIndirect" }>): void {
  for (const a of ins.args) emitGet(ctx, a, ins.span);
  emitGet(ctx, ins.callee, ins.span);
  const typeIndex = internType(ctx.project, ins.fnType);
  pushOp(ctx.emit, { kind: "call.indirect", typeIndex }, ins.span);
  if (ins.dst !== null) emitSet(ctx, ins.dst, ins.span);
}

function emitFnRef(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "FnRef" }>): void {
  const fnIdx = ctx.project.fnIndexBySymId.get(ins.fnSymbol.id);
  if (fnIdx === undefined) {
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  const typeIndex = internType(ctx.project, ins.type);
  pushOp(ctx.emit, { kind: "fn.ref", fnIndex: fnIdx, typeIndex }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitVirtualCall(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "VirtualCall" }>): void {
  for (const a of ins.args) emitGet(ctx, a, ins.span);
  emitGet(ctx, ins.receiver, ins.span);
  pushOp(ctx.emit, {
    kind: "virtual.call",
    vtableKey: `${ins.traitName}.${ins.method}`,
    paramCount: ins.args.length + 1,
  }, ins.span);
  if (ins.dst !== null) emitSet(ctx, ins.dst, ins.span);
}

function emitFieldGet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "FieldGet" }>): void {
  const targetType = typeOfLocal(ctx, ins.target);
  const typeIndex = internType(ctx.project, targetType);
  const struct = ctx.project.types[typeIndex];
  if (struct?.kind !== "struct") {
    emitGet(ctx, ins.target, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  const fieldIndex = struct.fields.findIndex((f) => f.name === ins.field);
  if (fieldIndex < 0) {
    emitGet(ctx, ins.target, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  emitGet(ctx, ins.target, ins.span);
  pushOp(ctx.emit, { kind: "struct.get", typeIndex, fieldIndex }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitFieldSet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "FieldSet" }>): void {
  const targetType = typeOfLocal(ctx, ins.target);
  const typeIndex = internType(ctx.project, targetType);
  const struct = ctx.project.types[typeIndex];
  if (struct?.kind !== "struct") {
    emitGet(ctx, ins.value, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    return;
  }
  const fieldIndex = struct.fields.findIndex((f) => f.name === ins.field);
  if (fieldIndex < 0) {
    emitGet(ctx, ins.value, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    return;
  }
  emitGet(ctx, ins.target, ins.span);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "struct.set", typeIndex, fieldIndex }, ins.span);
}

function emitArrayGet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArrayGet" }>): void {
  const targetType = typeOfLocal(ctx, ins.target);
  const typeIndex = internType(ctx.project, targetType);
  emitGet(ctx, ins.target, ins.span);
  emitGet(ctx, ins.index, ins.span);
  pushOp(ctx.emit, { kind: "array.get", typeIndex }, ins.span);
  // Mirror the legacy emit's element-type cast for primitives.
  const elemVal = valTypeOf(ins.type);
  if (elemVal !== "ref" && elemVal !== "any" && elemVal !== "void") {
    pushOp(ctx.emit, { kind: "ref.cast", typeIndex: internType(ctx.project, ins.type) }, ins.span);
  }
  emitSet(ctx, ins.dst, ins.span);
}

function emitArraySet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArraySet" }>): void {
  const targetType = typeOfLocal(ctx, ins.target);
  const typeIndex = internType(ctx.project, targetType);
  emitGet(ctx, ins.target, ins.span);
  emitGet(ctx, ins.index, ins.span);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "array.set", typeIndex }, ins.span);
}

function emitArrayLen(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArrayLen" }>): void {
  emitGet(ctx, ins.target, ins.span);
  pushOp(ctx.emit, { kind: "array.len" }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitArrayPush(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArrayPush" }>): void {
  const valueType = typeOfLocal(ctx, ins.value);
  emitGet(ctx, ins.target, ins.span);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "array.push", typeIndex: internType(ctx.project, valueType) }, ins.span);
}

function emitStructNew(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "StructNew" }>): void {
  const typeIndex = internType(ctx.project, ins.type);
  for (const f of ins.fields) emitGet(ctx, f, ins.span);
  pushOp(ctx.emit, { kind: "struct.new", typeIndex }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitArrayNew(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArrayNew" }>): void {
  const typeIndex = internType(ctx.project, ins.type);
  for (const elt of ins.elements) emitGet(ctx, elt, ins.span);
  pushOp(ctx.emit, { kind: "array.new", typeIndex, length: ins.length }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitTypeCheck(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "TypeCheck" }>): void {
  emitGet(ctx, ins.value, ins.span);
  const typeIndex = internType(ctx.project, ins.checkType);
  pushOp(ctx.emit, { kind: "type_check", typeIndex }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitCast(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Cast" }>): void {
  const fromType = typeOfLocal(ctx, ins.value);
  const fromVal = valTypeOf(fromType);
  const toVal = valTypeOf(ins.type);
  emitGet(ctx, ins.value, ins.span);
  if (fromVal !== toVal) {
    const op = convertOp(fromVal, toVal);
    if (op !== null) pushOp(ctx.emit, op, ins.span);
  }
  emitSet(ctx, ins.dst, ins.span);
}

function emitCellNew(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "CellNew" }>): void {
  const cellTypeIdx = internCellType(ctx.project, ins.valueType);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "struct.new", typeIndex: cellTypeIdx }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitCellGet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "CellGet" }>): void {
  const cellTypeIdx = internCellType(ctx.project, ins.valueType);
  emitGet(ctx, ins.cell, ins.span);
  pushOp(ctx.emit, { kind: "struct.get", typeIndex: cellTypeIdx, fieldIndex: 0 }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitCellSet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "CellSet" }>): void {
  const cellTypeIdx = internCellType(ctx.project, ins.valueType);
  emitGet(ctx, ins.cell, ins.span);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "struct.set", typeIndex: cellTypeIdx, fieldIndex: 0 }, ins.span);
}

function emitMakeClosureInstr(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "MakeClosure" }>): void {
  emitGet(ctx, ins.env, ins.span);
  const fnIdx = ctx.project.fnIndexBySymId.get(ins.fnSymbol.id);
  if (fnIdx === undefined) {
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  const typeIndex = internType(ctx.project, ins.type);
  pushOp(ctx.emit, { kind: "make_closure", fnIndex: fnIdx, typeIndex }, ins.span);
  emitSet(ctx, ins.dst, ins.span);
}

function emitIntrinsicInstr(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Intrinsic" }>): void {
  for (const a of ins.args) emitGet(ctx, a, ins.span);
  const id = intrinsicIdByName(ins.name);
  if (id === null) {
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  pushOp(ctx.emit, { kind: "intrinsic", id: id as IntrinsicId }, ins.span);
  if (ins.dst !== null) emitSet(ctx, ins.dst, ins.span);
}

// ============================================================================
// Local-slot helpers — bridge CFG locals to bytecode slots
// ============================================================================

function emitGet(ctx: FnEmitCfg, local: LocalId, span: Span): void {
  pushOp(ctx.emit, { kind: "local.get", slot: ctx.localToSlot[local]! }, span);
}

function emitSet(ctx: FnEmitCfg, local: LocalId, span: Span): void {
  pushOp(ctx.emit, { kind: "local.set", slot: ctx.localToSlot[local]! }, span);
}

function typeOfLocal(ctx: FnEmitCfg, local: LocalId): Type {
  return ctx.fn.locals[local]?.type ?? TY.unresolved;
}

// ============================================================================
// Op-table helpers (minimal copies of legacy emitter logic)
// ============================================================================

function convertOp(from: ValType, to: ValType): Op | null {
  if (!isNumericVal(from) && from !== "char") return null;
  if (!isNumericVal(to) && to !== "char") return null;
  return { kind: `${from}.to_${to}` as ConvertOpKind };
}

// ============================================================================
// CFG analyses — dominators, post-dominators, loop exits
// (predecessors / successors live in `analyses.ts`)
// ============================================================================

/** Dominator computation (Cooper, Harvey, Kennedy). Returns idom[b] = the
 *  immediate dominator of `b` ; `entry`'s idom is itself, unreachable
 *  blocks get -1 (interpreted as "no known idom"). */
function computeDominators(fn: CFGFunction, preds: readonly (readonly BlockId[])[]): readonly number[] {
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
        newIdom = newIdom === -1 ? p : intersect(p, newIdom, idom);
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
function intersect(a: BlockId, b: BlockId, idom: readonly number[]): BlockId {
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

/** Post-dominator computation : same algorithm, but on the reverse CFG.
 *  We build a synthetic exit predecessor (any block with `Return` /
 *  `Unreachable` / no successors becomes an exit). The result maps each
 *  block to its immediate post-dominator within the same fn ; -1 means
 *  no proper post-dominator (e.g. a block whose every path returns). */
function computePostDominators(fn: CFGFunction): readonly number[] {
  const n = fn.blocks.length;
  // Build successors and reverse RPO (from each exit block).
  const succs: BlockId[][] = fn.blocks.map((b) => [...successorsOf(b)]);
  const exits: BlockId[] = [];
  for (let i = 0; i < n; i++) {
    if (succs[i]!.length === 0) exits.push(i);
  }
  // Synthetic exit node = n. Add edge exit_block → n for every exit.
  const SE = n;
  const fakeSuccs: BlockId[][] = [...succs, []];
  const fakePreds: BlockId[][] = fakeSuccs.map(() => []);
  for (let b = 0; b < n; b++) {
    for (const s of fakeSuccs[b]!) fakePreds[s]!.push(b);
  }
  for (const e of exits) {
    fakeSuccs[e]!.push(SE);
    fakePreds[SE]!.push(e);
  }
  // RPO on the reverse graph from SE.
  const order: BlockId[] = [];
  const visited = new Array<boolean>(n + 1).fill(false);
  function walk(b: BlockId): void {
    if (visited[b]) return;
    visited[b] = true;
    for (const p of fakePreds[b]!) walk(p);
    order.push(b);
  }
  walk(SE);
  // Iterative post-dominator solve.
  const ipdom = new Array<number>(n + 1).fill(-1);
  ipdom[SE] = SE;
  let changed = true;
  while (changed) {
    changed = false;
    for (let i = order.length - 1; i >= 0; i--) {
      const b = order[i]!;
      if (b === SE) continue;
      let newPdom = -1;
      for (const s of fakeSuccs[b]!) {
        if (ipdom[s] === -1) continue;
        newPdom = newPdom === -1 ? s : intersect(s, newPdom, ipdom);
      }
      if (newPdom !== -1 && ipdom[b] !== newPdom) {
        ipdom[b] = newPdom;
        changed = true;
      }
    }
  }
  // Strip the synthetic SE — translate "ipdom = SE" to -1 for caller.
  const out = new Array<number>(n);
  for (let i = 0; i < n; i++) out[i] = ipdom[i] === SE ? -1 : ipdom[i]!;
  return out;
}

function reversePostorder(fn: CFGFunction): BlockId[] {
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

/** For each loop header H, the unique exit block — the first block reachable
 *  from the natural-loop body but outside it. The body is built classically :
 *  start from each back-edge source and walk predecessors backward until we
 *  hit H ; everything visited (plus H itself) is the body. */
function findLoopExits(
  fn: CFGFunction, preds: readonly (readonly BlockId[])[], idom: readonly number[],
): ReadonlyMap<BlockId, BlockId | null> {
  const out = new Map<BlockId, BlockId | null>();
  for (let h = 0; h < fn.blocks.length; h++) {
    const backEdgeSources = preds[h]!.filter((p) => dominates(idom, h, p));
    if (backEdgeSources.length === 0) continue;

    const body = new Set<BlockId>([h]);
    const stack: BlockId[] = [...backEdgeSources];
    while (stack.length > 0) {
      const cur = stack.pop()!;
      if (body.has(cur)) continue;
      body.add(cur);
      for (const p of preds[cur]!) {
        if (p !== h) stack.push(p);
      }
    }

    let exit: BlockId | null = null;
    for (const b of body) {
      for (const s of successorsOf(fn.blocks[b]!)) {
        if (!body.has(s)) { exit = s; break; }
      }
      if (exit !== null) break;
    }
    out.set(h, exit);
  }
  return out;
}
