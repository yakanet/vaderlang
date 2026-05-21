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
import type { Type } from "../typecheck/types.ts";
import { TY } from "../typecheck/types.ts";

import {
  binaryOpFor, buildVtables, declareLocal, emitFloatConst, emitIntConst,
  internCellType, internString, internType, newEmitterCtx,
  OP_INTRINSIC_BY_MANGLED, pushOp, reserveCFGExtern, reserveCFGFunction,
  reserveCFGStruct, synthesiseIntrinsicWrappers, valTypeOf,
  type EmitOptions, type EmitterCtx, type FnEmitCtx,
} from "../bytecode/emit.ts";
import type {
  BitNotOpKind, ConvertOpKind, IntrinsicId, NegOpKind, Op,
} from "../bytecode/ops.ts";
import { intrinsicIdByName } from "../bytecode/ops.ts";
import type { BytecodeModule, BcLocal, DebugPos } from "../bytecode/module.ts";
import { runPeepholes } from "../bytecode/peephole.ts";
import { coalesceSlots } from "../bytecode/slot-coalesce.ts";
import { isIntegerVal, isNumericVal, type ValType } from "../bytecode/types.ts";

import type {
  BlockId, CFGFunction, CFGProject,
  Instruction, LocalId,
} from "./cfg.ts";
import {
  computeDominators, dominates, intersectDomTree, naturalLoopBodies,
  predecessorsOf, reversePostorder, successorsOf,
} from "./analyses.ts";
import { NO_HINTS, scheduleStack, type ScheduleHints } from "./scheduler.ts";
import { pruneUnusedImports, pruneUnusedTypes } from "./dce.ts";

// ============================================================================
// Project-level entry point
// ============================================================================

export function emitBytecodeFromCFG(
  cfg: CFGProject, name: string, options: EmitOptions = {},
): BytecodeModule {
  const ctx = newEmitterCtx(options.optimize ?? true, options.implRegistry ?? null);

  // Pass 1 : reserve CFG fns/externs/structs. Allocates fn-table slots,
  // import entries, struct type indices, and @export entries.
  for (const m of cfg.modules.values()) {
    for (const fn of m.functions) reserveCFGFunction(fn, ctx);
    for (const ext of m.externs) reserveCFGExtern(ext, ctx);
    for (const s of m.structDecls) reserveCFGStruct(s, ctx);
  }

  // Synthesise wrapper BcFunctions for `@intrinsic` impl members. The
  // wrappers register the impl member's symbol in `fnIndexBySymId` so
  // `buildVtables` (called below) finds a fnIndex for trait dispatch on
  // primitive receivers (e.g. `Hash.hash` on `i32`/`string`,
  // `Equals.equals` on every primitive, `Add.add` on numerics, ...).
  // Static call sites are unaffected — `emitCallInstr` still hits the
  // `importIndexBySymId` → `OP_INTRINSIC_BY_MANGLED` / `call.import`
  // path first.
  synthesiseIntrinsicWrappers(ctx, cfg);

  // Erasure-dedupe symbol redirects : when the erasure pass collapsed N
  // concrete MonoEntries into one representative, the (N-1) abandoned
  // symbols still appear in the lowered IR (left over from when those
  // entries had their own bodies). Forward each abandoned symbol id to
  // the representative's fnIndex so call sites resolve correctly.
  for (const [oldSymId, newSymId] of cfg.symbolRedirects) {
    const newIdx = ctx.fnIndexBySymId.get(newSymId);
    if (newIdx !== undefined) ctx.fnIndexBySymId.set(oldSymId, newIdx);
  }

  // Pre-translate the CFG's string indices into the bytecode pool's indices
  // so per-instr emit is a plain array lookup instead of a hash re-intern.
  const stringIndexMap: number[] = cfg.strings.map((s) => internString(ctx, s));

  // Pass 2 : emit fn bodies from the CFG.
  for (const m of cfg.modules.values()) {
    for (const cfgFn of m.functions) {
      if (cfgFn.isExtern) continue;             // routed to imports in pass 1
      if (cfgFn.origin.symbol === null) continue;
      const fnIndex = ctx.fnIndexBySymId.get(cfgFn.origin.symbol.id);
      if (fnIndex === undefined) continue;

      const slot = ctx.functions[fnIndex]!;
      const fn: FnEmitCtx = {
        project: ctx,
        signature: slot.signature,
        locals: [],
        body: [],
        debug: [],
        slotBySymbolId: new Map(),
      };

      emitCFGFunctionBody(cfgFn, fn, ctx, stringIndexMap);
      if (ctx.optimize) {
        runPeepholes(fn);
        coalesceSlots(fn);
      }
      // Mutate slot via the shared mutable shape the legacy emit also uses.
      (slot as { locals: BcLocal[] }).locals = fn.locals;
      (slot as { body: Op[] }).body = fn.body;
      (slot as { debug: (DebugPos | null)[] }).debug = fn.debug;
    }
  }

  pruneUnusedImports(ctx);
  // Vtables must be built BEFORE type-table DCE so their struct type
  // indices are visible to the prune pass — otherwise the impl entries
  // would point at slots we'd just dropped.
  const vtables = buildVtables(ctx, cfg.vtableEntries);
  pruneUnusedTypes(ctx, vtables);

  return {
    name,
    types:     ctx.types,
    strings:   ctx.strings,
    dataPool:  cfg.dataPool,
    functions: ctx.functions,
    imports:   ctx.imports,
    exports:   ctx.exports,
    implTable: ctx.implTable,
    vtables,
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
  readonly localToSlot: readonly number[];
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
  /** Hints from the stack scheduler — which instructions can leave their
   *  result on the operand stack instead of materialising it via local.set,
   *  and which can read their first operand from the stack instead of
   *  local.get. Cuts the C-emit bloat the 3-address form introduces. */
  readonly hints: ScheduleHints;
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
  // as the legacy emitter). Additional locals get fresh bytecode slots ;
  // slot coalescing runs later as a bytecode-level pass so it can fold the
  // peephole's output too.
  const localToSlot: number[] = new Array(cfgFn.locals.length);
  for (let i = 0; i < cfgFn.params.length; i++) {
    localToSlot[i] = i;
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
    hints: scheduleStack(cfgFn),
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
      if (t.value !== null && !ctx.hints.skipTerminatorGet.has(blockId)) {
        emitGet(ctx, t.value, t.span);
      }
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
      if (!ctx.hints.skipTerminatorGet.has(blockId)) emitGet(ctx, t.cond, t.span);
      pushOp(ctx.emit, { kind: "if", result: "void" }, t.span);
      ctx.scopes.push({ kind: "if", target: merge ?? -1 });
      if (merge === null || t.then !== merge) emitRange(ctx, t.then, merge);
      // Early-return flattening : when the then-branch ends with a true
      // exit op (Return / Unreachable / `br` jumping out), the else-body
      // can be emitted as siblings at the parent scope instead of nested
      // under an `else` op. This collapses cascades like
      //   `if a { return X } else { if b { return Y } else { ... } }`
      // into a flat sequence of guarded `if … return … end` blocks. A
      // silent fall-through (Branch to `until`) emits no op and therefore
      // does NOT trigger flattening — semantically the if's else-body is
      // the post-merge code, which must still execute.
      const lastOp = ctx.emit.body[ctx.emit.body.length - 1];
      const thenExits = lastOp !== undefined
        && (lastOp.kind === "return" || lastOp.kind === "unreachable" || lastOp.kind === "br");
      if (thenExits && t.else !== merge) {
        ctx.scopes.pop();
        pushOp(ctx.emit, { kind: "end" }, t.span);
        return t.else;
      }
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
    case "ArraySlice":      return emitArraySlice(ctx, ins);
    case "StructNew":       return emitStructNew(ctx, ins);
    case "ArrayNew":        return emitArrayNew(ctx, ins);
    case "DataConst":       return emitDataConst(ctx, ins);
    case "TypeCheck":       return emitTypeCheck(ctx, ins);
    case "TypeConst":       return emitTypeConst(ctx, ins);
    case "Cast":            return emitCast(ctx, ins);
    case "CellNew":         return emitCellNew(ctx, ins);
    case "CellGet":         return emitCellGet(ctx, ins);
    case "CellSet":         return emitCellSet(ctx, ins);
    case "MakeClosure":     return emitMakeClosureInstr(ctx, ins);
    case "Intrinsic":       return emitIntrinsicInstr(ctx, ins);
  }
}

function emitConstInstr(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Const" }>): void {
  // No operands : `Const` always pushes onto the stack ; only the result
  // emit needs to consult the scheduler.
  const v = ins.value;
  switch (v.kind) {
    case "int":    emitIntConst(ctx.emit, v.value, valTypeOf(ins.type), ins.span); break;
    case "float":  emitFloatConst(ctx.emit, v.value, valTypeOf(ins.type), ins.span); break;
    case "bool":   pushOp(ctx.emit, { kind: "bool.const",  value: v.value }, ins.span); break;
    case "char":   pushOp(ctx.emit, { kind: "char.const",  value: v.value }, ins.span); break;
    case "string": pushOp(ctx.emit, { kind: "string.const", index: stringIndex(ctx, v) }, ins.span); break;
    case "null":   pushOp(ctx.emit, { kind: "null.const" }, ins.span); break;
  }
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function stringIndex(ctx: FnEmitCfg, v: { kind: "string"; index: number }): number {
  return ctx.stringIndexMap[v.index] ?? 0;
}

function emitMove(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Move" }>): void {
  emitFirstOperand(ctx, ins, ins.src, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitBinOp(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "BinOp" }>): void {
  emitFirstOperand(ctx, ins, ins.lhs, ins.span);
  emitGet(ctx, ins.rhs, ins.span);
  pushOp(ctx.emit, binaryOpFor(ins.op, valTypeOf(typeOfLocal(ctx, ins.lhs))), ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitUnOp(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "UnOp" }>): void {
  emitFirstOperand(ctx, ins, ins.operand, ins.span);
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
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitCallInstr(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Call" }>): void {
  const importIdx = ctx.project.importIndexBySymId.get(ins.callee.id);
  if (importIdx !== undefined) {
    const imp = ctx.project.imports[importIdx]!;
    const opIntrinsic = OP_INTRINSIC_BY_MANGLED.get(imp.mangledName);
    if (opIntrinsic !== undefined) {
      emitArgs(ctx, ins, ins.args);
      pushOp(ctx.emit, opIntrinsic(), ins.span);
      emitInstrResultIfAny(ctx, ins, ins.dst, ins.span);
      return;
    }
  }
  const fnIdx = ctx.project.fnIndexBySymId.get(ins.callee.id);
  if (fnIdx !== undefined) {
    emitArgs(ctx, ins, ins.args);
    // Pass the destination local's static type so the C-emit can recognise
    // erasure boundary cases (callee body returns Any-form heap struct,
    // caller expects concrete inline form — see `emitErasureBoundaryConversion`).
    const expectedResultType = ins.dst !== null
      ? internType(ctx.project, ctx.fn.locals[ins.dst]!.type)
      : undefined;
    // Per-arg static BcType so the C-emit can reshape a concrete-shape arg
    // (e.g. `Tuple_24 { i32, string }`) into the callee's expected Any
    // layout (`Tuple_2 { vader_box_t, vader_box_t }`) before the call.
    const argTypeIndices = ins.args.map((a) => internType(ctx.project, ctx.fn.locals[a]!.type));
    pushOp(ctx.emit, { kind: "call", fnIndex: fnIdx, expectedResultType, argTypeIndices }, ins.span);
    emitInstrResultIfAny(ctx, ins, ins.dst, ins.span);
    return;
  }
  if (importIdx !== undefined) {
    emitArgs(ctx, ins, ins.args);
    pushOp(ctx.emit, { kind: "call.import", importIndex: importIdx }, ins.span);
    emitInstrResultIfAny(ctx, ins, ins.dst, ins.span);
    return;
  }
  // Fall-through : same `unreachable` policy as the legacy emit.
  for (const a of ins.args) emitGet(ctx, a, ins.span);
  pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
}

function emitCallIndirect(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "CallIndirect" }>): void {
  if (ins.args.length > 0) emitArgs(ctx, ins, ins.args);
  if (ins.args.length > 0) emitGet(ctx, ins.callee, ins.span);
  else emitFirstOperand(ctx, ins, ins.callee, ins.span);
  const typeIndex = internType(ctx.project, ins.fnType);
  pushOp(ctx.emit, { kind: "call.indirect", typeIndex }, ins.span);
  emitInstrResultIfAny(ctx, ins, ins.dst, ins.span);
}

function emitFnRef(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "FnRef" }>): void {
  const fnIdx = ctx.project.fnIndexBySymId.get(ins.fnSymbol.id);
  if (fnIdx === undefined) {
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  const typeIndex = internType(ctx.project, ins.type);
  pushOp(ctx.emit, { kind: "fn.ref", fnIndex: fnIdx, typeIndex }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitVirtualCall(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "VirtualCall" }>): void {
  if (ins.args.length > 0) emitArgs(ctx, ins, ins.args);
  if (ins.args.length > 0) emitGet(ctx, ins.receiver, ins.span);
  else emitFirstOperand(ctx, ins, ins.receiver, ins.span);
  // Pass the destination local's static BcType index so the C-emit can
  // recognise an erasure-induced layout mismatch (impl body returns the
  // Any-substituted heap form ; caller expects the inline form) and
  // insert an unbox+repack conversion. Undefined when there is no dst
  // (void result) ; the C-emit treats it as "no conversion needed".
  const resultTypeIndex = ins.dst !== null
    ? internType(ctx.project, ctx.fn.locals[ins.dst]!.type)
    : undefined;
  pushOp(ctx.emit, {
    kind: "virtual.call",
    vtableKey: `${ins.traitName}.${ins.method}`,
    paramCount: ins.args.length + 1,
    resultTypeIndex,
  }, ins.span);
  emitInstrResultIfAny(ctx, ins, ins.dst, ins.span);
}

function emitFieldGet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "FieldGet" }>): void {
  const targetType = typeOfLocal(ctx, ins.target);
  const typeIndex = internType(ctx.project, targetType);
  const struct = ctx.project.types[typeIndex];
  if (struct?.kind !== "struct") {
    emitFirstOperand(ctx, ins, ins.target, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  const fieldIndex = struct.fields.findIndex((f) => f.name === ins.field);
  if (fieldIndex < 0) {
    emitFirstOperand(ctx, ins, ins.target, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  emitFirstOperand(ctx, ins, ins.target, ins.span);
  pushOp(ctx.emit, { kind: "struct.get", typeIndex, fieldIndex }, ins.span);
  // Under erasure the BcType's field is `ref` (vader_box_t) even when the
  // CFG's static field type is a primitive ; struct.get pushes the BcType
  // ValType, so a `i32.to_i64` (or similar typed op) reading downstream
  // would see a vader_box_t and produce broken C. Insert a `ref.cast` to
  // unbox to the expected primitive, mirroring `emitArrayGet`'s pattern.
  const elemVal = valTypeOf(ins.type);
  if (elemVal !== "ref" && elemVal !== "any" && elemVal !== "void") {
    pushOp(ctx.emit, { kind: "ref.cast", typeIndex: internType(ctx.project, ins.type) }, ins.span);
  }
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitFieldSet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "FieldSet" }>): void {
  const targetType = typeOfLocal(ctx, ins.target);
  const typeIndex = internType(ctx.project, targetType);
  const struct = ctx.project.types[typeIndex];
  if (struct?.kind !== "struct") {
    emitFirstOperand(ctx, ins, ins.target, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    emitGet(ctx, ins.value, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    return;
  }
  const fieldIndex = struct.fields.findIndex((f) => f.name === ins.field);
  if (fieldIndex < 0) {
    emitFirstOperand(ctx, ins, ins.target, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    emitGet(ctx, ins.value, ins.span);
    pushOp(ctx.emit, { kind: "drop" }, ins.span);
    return;
  }
  emitFirstOperand(ctx, ins, ins.target, ins.span);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit,
    ins.barrierless
      ? { kind: "struct.set_stack", typeIndex, fieldIndex }
      : { kind: "struct.set", typeIndex, fieldIndex },
    ins.span);
}

function emitArrayGet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArrayGet" }>): void {
  const targetType = typeOfLocal(ctx, ins.target);
  const typeIndex = internType(ctx.project, targetType);
  emitFirstOperand(ctx, ins, ins.target, ins.span);
  emitGet(ctx, ins.index, ins.span);
  pushOp(ctx.emit, { kind: "array.get", typeIndex }, ins.span);
  // Mirror the legacy emit's element-type cast for primitives.
  const elemVal = valTypeOf(ins.type);
  if (elemVal !== "ref" && elemVal !== "any" && elemVal !== "void") {
    pushOp(ctx.emit, { kind: "ref.cast", typeIndex: internType(ctx.project, ins.type) }, ins.span);
  }
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitArraySet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArraySet" }>): void {
  const targetType = typeOfLocal(ctx, ins.target);
  const typeIndex = internType(ctx.project, targetType);
  emitFirstOperand(ctx, ins, ins.target, ins.span);
  emitGet(ctx, ins.index, ins.span);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "array.set", typeIndex }, ins.span);
}

function emitArrayLen(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArrayLen" }>): void {
  emitFirstOperand(ctx, ins, ins.target, ins.span);
  pushOp(ctx.emit, { kind: "array.len" }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitArrayPush(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArrayPush" }>): void {
  const valueType = typeOfLocal(ctx, ins.value);
  emitFirstOperand(ctx, ins, ins.target, ins.span);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "array.push", typeIndex: internType(ctx.project, valueType) }, ins.span);
}

function emitArraySlice(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArraySlice" }>): void {
  const typeIndex = internType(ctx.project, ins.type);
  emitFirstOperand(ctx, ins, ins.target, ins.span);
  emitGet(ctx, ins.lo, ins.span);
  emitGet(ctx, ins.hi, ins.span);
  pushOp(ctx.emit, { kind: "array.slice", typeIndex }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitStructNew(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "StructNew" }>): void {
  const typeIndex = internType(ctx.project, ins.type);
  emitArgs(ctx, ins, ins.fields);
  pushOp(ctx.emit, ins.stack
    ? { kind: "struct.new_stack", typeIndex }
    : { kind: "struct.new", typeIndex }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitArrayNew(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "ArrayNew" }>): void {
  const typeIndex = internType(ctx.project, ins.type);
  emitArgs(ctx, ins, ins.elements);
  pushOp(ctx.emit, { kind: "array.new", typeIndex, length: ins.length }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitDataConst(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "DataConst" }>): void {
  const typeIndex = internType(ctx.project, ins.type);
  pushOp(ctx.emit, { kind: "data.const", poolIndex: ins.poolIndex, typeIndex }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitTypeCheck(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "TypeCheck" }>): void {
  emitFirstOperand(ctx, ins, ins.value, ins.span);
  const typeIndex = internType(ctx.project, ins.checkType);
  pushOp(ctx.emit, { kind: "type_check", typeIndex }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitTypeConst(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "TypeConst" }>): void {
  const typeIndex = internType(ctx.project, ins.valueType);
  pushOp(ctx.emit, { kind: "type.const", typeIndex }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitCast(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Cast" }>): void {
  const fromType = typeOfLocal(ctx, ins.value);
  const fromVal = valTypeOf(fromType);
  const toVal = valTypeOf(ins.type);
  emitFirstOperand(ctx, ins, ins.value, ins.span);
  if (fromVal !== toVal) {
    if (fromVal === "ref" || fromVal === "any" || toVal === "ref" || toVal === "any") {
      pushOp(ctx.emit, { kind: "ref.cast", typeIndex: internType(ctx.project, ins.type) }, ins.span);
    } else {
      const op = convertOp(fromVal, toVal);
      if (op !== null) pushOp(ctx.emit, op, ins.span);
    }
  }
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitCellNew(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "CellNew" }>): void {
  const cellTypeIdx = internCellType(ctx.project, ins.valueType);
  emitFirstOperand(ctx, ins, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "struct.new", typeIndex: cellTypeIdx }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitCellGet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "CellGet" }>): void {
  const cellTypeIdx = internCellType(ctx.project, ins.valueType);
  emitFirstOperand(ctx, ins, ins.cell, ins.span);
  pushOp(ctx.emit, { kind: "struct.get", typeIndex: cellTypeIdx, fieldIndex: 0 }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitCellSet(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "CellSet" }>): void {
  const cellTypeIdx = internCellType(ctx.project, ins.valueType);
  emitFirstOperand(ctx, ins, ins.cell, ins.span);
  emitGet(ctx, ins.value, ins.span);
  pushOp(ctx.emit, { kind: "struct.set", typeIndex: cellTypeIdx, fieldIndex: 0 }, ins.span);
}

function emitMakeClosureInstr(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "MakeClosure" }>): void {
  emitFirstOperand(ctx, ins, ins.env, ins.span);
  const fnIdx = ctx.project.fnIndexBySymId.get(ins.fnSymbol.id);
  if (fnIdx === undefined) {
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  const typeIndex = internType(ctx.project, ins.type);
  pushOp(ctx.emit, { kind: "make_closure", fnIndex: fnIdx, typeIndex }, ins.span);
  emitInstrResult(ctx, ins, ins.dst, ins.span);
}

function emitIntrinsicInstr(ctx: FnEmitCfg, ins: Extract<Instruction, { kind: "Intrinsic" }>): void {
  emitArgs(ctx, ins, ins.args);
  const id = intrinsicIdByName(ins.name);
  if (id === null) {
    pushOp(ctx.emit, { kind: "unreachable" }, ins.span);
    return;
  }
  pushOp(ctx.emit, { kind: "intrinsic", id: id as IntrinsicId }, ins.span);
  emitInstrResultIfAny(ctx, ins, ins.dst, ins.span);
}

/** Emit a positional arg list, treating the very first arg (if any) as the
 *  candidate for stack-pass-through. Used by Call / VirtualCall / Intrinsic /
 *  StructNew / ArrayNew. */
function emitArgs(ctx: FnEmitCfg, ins: Instruction, args: readonly LocalId[]): void {
  for (let i = 0; i < args.length; i++) {
    const a = args[i]!;
    if (i === 0) emitFirstOperand(ctx, ins, a, ins.span);
    else emitGet(ctx, a, ins.span);
  }
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

/** Read the first stack-pushed operand of `ins`. When the stack scheduler
 *  decided this read can come straight from the stack (the previous
 *  instruction's result is sitting there), we emit nothing. */
function emitFirstOperand(ctx: FnEmitCfg, ins: Instruction, local: LocalId, span: Span): void {
  if (ctx.hints.skipFirstGet.has(ins)) return;
  emitGet(ctx, local, span);
}

/** Write the result of `ins` to its `dst` slot. When the scheduler hinted
 *  the value should pass through the stack to the next op, leave the value
 *  on the stack instead of materialising it. */
function emitInstrResult(ctx: FnEmitCfg, ins: Instruction, dst: LocalId, span: Span): void {
  if (ctx.hints.skipSet.has(ins)) return;
  emitSet(ctx, dst, span);
}

/** Same as `emitInstrResult` but for instructions whose `dst` may be null
 *  (Call/CallIndirect/VirtualCall/Intrinsic with void return). */
function emitInstrResultIfAny(ctx: FnEmitCfg, ins: Instruction, dst: LocalId | null, span: Span): void {
  if (dst === null) return;
  emitInstrResult(ctx, ins, dst, span);
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
        newPdom = newPdom === -1 ? s : intersectDomTree(s, newPdom, ipdom);
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

/** For each loop header H, the unique exit block — the first block reachable
 *  from the natural-loop body but outside it. The body is built classically :
 *  start from each back-edge source and walk predecessors backward until we
 *  hit H ; everything visited (plus H itself) is the body. */
function findLoopExits(
  fn: CFGFunction, preds: readonly (readonly BlockId[])[], idom: readonly number[],
): ReadonlyMap<BlockId, BlockId | null> {
  const out = new Map<BlockId, BlockId | null>();
  for (const [header, body] of naturalLoopBodies(fn, preds, idom)) {
    let exit: BlockId | null = null;
    for (const b of body) {
      for (const s of successorsOf(fn.blocks[b]!)) {
        if (!body.has(s)) { exit = s; break; }
      }
      if (exit !== null) break;
    }
    out.set(header, exit);
  }
  return out;
}
