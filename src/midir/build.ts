// LoweredAST → CFG converter.
//
// Walks each `LoweredFnDecl` in the project and produces a `CFGFunction` :
// expressions become three-address `Instruction` sequences with named tmp
// locals ; control flow (`LoweredIf`, `LoweredLoop`, `break`, `continue`,
// `return`) becomes basic blocks with explicit terminators. The result is
// reducible (the source has no `goto`), which is what the structurer needs
// in order to recover WASM-style nesting at emit time.
//
// Strings are interned into a project-level pool reused verbatim by the
// CFG → bytecode emitter ; const decls are inlined at every read site,
// matching the existing bytecode emitter's policy.
//
// This file is the canonical seam between the Lowered and CFG IRs. See the
// header comment in `cfg.ts` for the full seam contract — what crosses,
// what's CFG-private, what's Lowered-private — and the conditions under
// which the two-IR split would be revisited.

import type { Span } from "../diagnostics/diagnostic.ts";
import type * as L from "../lower/lowered-ast.ts";
import type { MonoEntry } from "../comptime/specialize.ts";
import { DEC, hasDecorator } from "../parser/decorators.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { Type } from "../typecheck/types.ts";
import { equalsType, isPrimitive } from "../typecheck/types.ts";

import type {
  BasicBlock, BlockId, CFGExternDecl, CFGFunction, CFGLocal, CFGModule,
  CFGParam, CFGProject, CFGStructDecl, ConstValue, Instruction, LocalId,
  Terminator,
} from "./cfg.ts";

// ============================================================================
// Project-level orchestration
// ============================================================================

interface ProjectCtx {
  readonly strings: string[];
  readonly stringIndex: Map<string, number>;
}

export function buildCFGProject(lp: L.LoweredProject): CFGProject {
  const ctx: ProjectCtx = {
    strings: [],
    stringIndex: new Map(),
  };

  // Convert each module's decls. Fn decls with a body become CFGFunctions ;
  // bodyless (extern) fns surface as CFGExternDecls ; struct decls become
  // CFGStructDecls. Const decls are dropped — references to them in fn
  // bodies were already inlined by the `inline-consts` lowering pass, and
  // the bytecode emit has no use for the bare decl.
  const modules = new Map<string, CFGModule>();
  for (const m of lp.modules.values()) {
    const functions: CFGFunction[] = [];
    const externs: CFGExternDecl[] = [];
    const structDecls: CFGStructDecl[] = [];
    for (const d of m.decls) {
      switch (d.kind) {
        case "LoweredFnDecl":
          if (d.body === null) {
            externs.push(makeExternDecl(d));
          } else {
            const cfg = convertFunction(d, ctx);
            if (cfg !== null) functions.push(cfg);
          }
          break;
        case "LoweredStructDecl":
          structDecls.push(makeStructDecl(d));
          break;
        case "LoweredConstDecl":
          // Inlined-out at lowering time; nothing to carry forward.
          break;
      }
    }
    modules.set(m.moduleId, {
      moduleId: m.moduleId,
      displayPath: m.displayPath,
      functions,
      externs,
      structDecls,
    });
  }

  return {
    modules,
    vtableEntries: lp.vtableEntries,
    strings: ctx.strings,
    dataPool: lp.dataPool,
  };
}

function internString(ctx: ProjectCtx, s: string): number {
  const existing = ctx.stringIndex.get(s);
  if (existing !== undefined) return existing;
  const idx = ctx.strings.length;
  ctx.strings.push(s);
  ctx.stringIndex.set(s, idx);
  return idx;
}

// ============================================================================
// Per-function state
// ============================================================================

interface FnCtx {
  readonly project: ProjectCtx;
  readonly mangled: string;
  readonly origin: MonoEntry;
  readonly returnType: Type;
  readonly params: CFGParam[];
  readonly locals: CFGLocal[];
  readonly localBySymId: Map<number, LocalId>;
  /** Mutable block table being built. Each entry's `instructions` and
   *  `terminator` are filled in as building progresses. */
  readonly blocks: MutableBlock[];
  /** Stack of enclosing loop frames — break/continue resolve through this. */
  readonly loopStack: LoopFrame[];
  /** Block currently being filled. `null` means the function has terminated
   *  (e.g. after a Return / Unreachable) ; subsequent statements still need
   *  somewhere to land, so a fresh dead block is allocated lazily. */
  current: BlockId | null;
}

interface MutableBlock {
  readonly id: BlockId;
  readonly instructions: Instruction[];
  terminator: Terminator | null;
  readonly span: Span;
}

interface LoopFrame {
  readonly label: string | null;
  readonly headerId: BlockId;     // continue target
  readonly exitId: BlockId;       // break target
}

// ============================================================================
// Function conversion
// ============================================================================

/** Extract the source-level metadata bytecode-emit needs to route a fn to
 *  imports/exports. Centralised so both `convertFunction` (body-having) and
 *  `makeExternDecl` (bodyless) compute identical values from the origin. */
function fnMetadata(d: L.LoweredFnDecl): {
  externName: string;
  isExtern: boolean;
  isExported: boolean;
} {
  const decoratorList = d.origin.decl.kind === "FnDecl" ? d.origin.decl.decorators : [];
  return {
    externName: d.origin.decl.kind === "FnDecl" ? d.origin.decl.name : d.mangled,
    isExtern: hasDecorator(decoratorList, DEC.extern),
    isExported: hasDecorator(decoratorList, DEC.export),
  };
}

function makeStructDecl(d: L.LoweredStructDecl): CFGStructDecl {
  return {
    mangled: d.mangled,
    fields: d.fields.map((f) => ({ name: f.name, type: f.type })),
    origin: d.origin,
  };
}

function makeExternDecl(d: L.LoweredFnDecl): CFGExternDecl {
  const meta = fnMetadata(d);
  const params: CFGParam[] = d.params.map((p, i) => ({
    name: p.name, symbol: p.symbol, type: p.type, local: i,
  }));
  return {
    mangled: d.mangled,
    params,
    returnType: d.returnType,
    origin: d.origin,
    externName: meta.externName,
    isExported: meta.isExported,
  };
}

function convertFunction(d: L.LoweredFnDecl, project: ProjectCtx): CFGFunction | null {
  if (d.body === null) return null;       // bodyless fns go through makeExternDecl

  const params: CFGParam[] = [];
  const locals: CFGLocal[] = [];
  const localBySymId = new Map<number, LocalId>();

  // Params occupy local slots 0..N-1 — mirrors the bytecode emit convention.
  for (const p of d.params) {
    const slot = locals.length;
    locals.push({ name: p.name, type: p.type, symbol: p.symbol });
    localBySymId.set(p.symbol.id, slot);
    params.push({ name: p.name, symbol: p.symbol, type: p.type, local: slot });
  }

  const fn: FnCtx = {
    project, mangled: d.mangled, origin: d.origin, returnType: d.returnType,
    params, locals, localBySymId,
    blocks: [],
    loopStack: [],
    current: null,
  };

  const entry = newBlock(fn, d.body.span);
  fn.current = entry;

  const trailing = buildBlockBody(fn, d.body);

  // Implicit return at fn end : if the trailing expr is non-void, return its
  // value ; otherwise emit a void return. Skipped if control already left
  // the current block (Return / Unreachable terminator already in place).
  if (fn.current !== null) {
    const cur = fn.blocks[fn.current]!;
    if (cur.terminator === null) {
      cur.terminator = {
        kind: "Return",
        value: trailing,
        span: d.body.span,
      };
    }
  }

  const meta = fnMetadata(d);
  return {
    mangled: d.mangled,
    params,
    returnType: d.returnType,
    locals,
    blocks: fn.blocks.map(freezeBlock),
    entry,
    origin: d.origin,
    externName: meta.externName,
    isExtern: meta.isExtern,
    isExported: meta.isExported,
  };
}

function freezeBlock(b: MutableBlock): BasicBlock {
  if (b.terminator === null) {
    // Defensive : a block escaped without a terminator. The structurer would
    // crash on it, so emit Unreachable with a diagnostic-friendly reason.
    return {
      id: b.id, instructions: b.instructions, span: b.span,
      terminator: { kind: "Unreachable", reason: "missing terminator", span: b.span },
    };
  }
  return { id: b.id, instructions: b.instructions, terminator: b.terminator, span: b.span };
}

// ============================================================================
// Block / statement / expression builders
// ============================================================================

/** Build a block body — appends instructions to the current basic block,
 *  may split / branch when control flow is encountered. Returns the local
 *  carrying the trailing expression's value (or `null` for void blocks /
 *  blocks whose flow never reaches the trailing). */
function buildBlockBody(fn: FnCtx, b: L.LoweredBlock): LocalId | null {
  for (const s of b.stmts) {
    if (fn.current === null) return null;       // unreachable code — drop quietly
    buildStmt(fn, s);
  }
  if (fn.current === null) return null;
  if (b.trailing === null) return null;
  return buildExpr(fn, b.trailing);
}

function buildStmt(fn: FnCtx, s: L.LoweredStmt): void {
  switch (s.kind) {
    case "LoweredLet": {
      const valueLocal = buildExpr(fn, s.value);
      const dst = declareLocal(fn, s.name, s.type, s.symbol);
      fn.localBySymId.set(s.symbol.id, dst);
      if (valueLocal !== null && fn.current !== null) {
        emit(fn, { kind: "Move", dst, src: valueLocal, span: s.span });
      }
      return;
    }
    case "LoweredAssign": {
      buildAssign(fn, s);
      return;
    }
    case "LoweredCellSet": {
      const cell = buildExpr(fn, s.target);
      const value = buildExpr(fn, s.value);
      if (cell !== null && value !== null) {
        emit(fn, {
          kind: "CellSet", cell, value, valueType: s.valueType, span: s.span,
        });
      }
      return;
    }
    case "LoweredExprStmt": {
      // Build the expression for its side effects ; the result local goes
      // unused. DCE on the CFG will prune it.
      buildExpr(fn, s.expr);
      return;
    }
    case "LoweredReturn": {
      const value = s.value === null ? null : buildExpr(fn, s.value);
      terminate(fn, { kind: "Return", value, span: s.span });
      return;
    }
    case "LoweredLoop": {
      buildLoop(fn, s);
      return;
    }
    case "LoweredBreak": {
      const frame = resolveLoopFrame(fn, s.label);
      if (frame === null) return;
      terminate(fn, { kind: "Branch", target: frame.exitId, span: s.span });
      return;
    }
    case "LoweredContinue": {
      const frame = resolveLoopFrame(fn, s.label);
      if (frame === null) return;
      terminate(fn, { kind: "Branch", target: frame.headerId, span: s.span });
      return;
    }
  }
}

function buildAssign(fn: FnCtx, s: L.LoweredAssign): void {
  const target = s.target;
  switch (target.kind) {
    case "LoweredIdent": {
      const slot = fn.localBySymId.get(target.symbol.id);
      const value = buildExpr(fn, s.value);
      if (slot === undefined || value === null) return;
      emit(fn, { kind: "Move", dst: slot, src: value, span: s.span });
      return;
    }
    case "LoweredFieldAccess": {
      const tgt = buildExpr(fn, target.target);
      const value = buildExpr(fn, s.value);
      if (tgt === null || value === null) return;
      const fieldName = target.field;
      emit(fn, {
        kind: "FieldSet", target: tgt, field: fieldName, value, barrierless: false, span: s.span,
      });
      return;
    }
    case "LoweredIndex": {
      const tgt = buildExpr(fn, target.target);
      const idx = buildExpr(fn, target.index);
      const value = buildExpr(fn, s.value);
      if (tgt === null || idx === null || value === null) return;
      emit(fn, {
        kind: "ArraySet", target: tgt, index: idx, value, span: s.span,
      });
      return;
    }
    default:
      // Bytecode emit drops the value silently for unsupported targets ;
      // mirror by building (for side effects) and discarding.
      buildExpr(fn, s.value);
      return;
  }
}

function buildLoop(fn: FnCtx, s: L.LoweredLoop): void {
  // Three blocks : header (cond), body, exit.
  const headerId = newBlock(fn, s.span);
  const bodyId = newBlock(fn, s.body.span);
  const exitId = newBlock(fn, s.span);

  // Branch from current block into the header so the loop has a clean entry.
  if (fn.current !== null) {
    terminate(fn, { kind: "Branch", target: headerId, span: s.span });
  }

  // Header : evaluate cond (if any), CondBranch into body or exit.
  fn.current = headerId;
  if (s.cond !== null) {
    const condLocal = buildExpr(fn, s.cond);
    if (condLocal !== null) {
      terminate(fn, {
        kind: "CondBranch", cond: condLocal, then: bodyId, else: exitId, span: s.cond.span,
      });
    } else {
      terminate(fn, { kind: "Branch", target: exitId, span: s.span });
    }
  } else {
    terminate(fn, { kind: "Branch", target: bodyId, span: s.span });
  }

  // Body : process stmts ; loop back to header at the natural fall-through.
  fn.loopStack.push({ label: s.label, headerId, exitId });
  fn.current = bodyId;
  buildBlockBody(fn, s.body);
  if (fn.current !== null) {
    terminate(fn, { kind: "Branch", target: headerId, span: s.span });
  }
  fn.loopStack.pop();

  // Continue building in the exit block.
  fn.current = exitId;
}

function resolveLoopFrame(fn: FnCtx, label: string | null): LoopFrame | null {
  if (label === null) {
    return fn.loopStack.length === 0 ? null : fn.loopStack[fn.loopStack.length - 1]!;
  }
  for (let i = fn.loopStack.length - 1; i >= 0; i--) {
    const frame = fn.loopStack[i]!;
    if (frame.label === label) return frame;
  }
  return null;
}

// ============================================================================
// Expression conversion — every variant returns the LocalId holding its value
// (or null when the build path turned unreachable mid-expression).
// ============================================================================

function buildExpr(fn: FnCtx, e: L.LoweredExpr): LocalId | null {
  if (fn.current === null) return null;
  switch (e.kind) {
    case "LoweredIntLit":   return emitConst(fn, e.type, { kind: "int", value: e.value }, e.span);
    case "LoweredFloatLit": return emitConst(fn, e.type, { kind: "float", value: e.value }, e.span);
    case "LoweredBoolLit":  return emitConst(fn, e.type, { kind: "bool", value: e.value }, e.span);
    case "LoweredNullLit":  return emitConst(fn, e.type, { kind: "null" }, e.span);
    case "LoweredCharLit":  return emitConst(fn, e.type, { kind: "char", value: e.value }, e.span);
    case "LoweredStringLit": {
      const idx = internString(fn.project, e.value);
      return emitConst(fn, e.type, { kind: "string", index: idx }, e.span);
    }
    case "LoweredIdent":         return buildIdent(fn, e);
    case "LoweredCall":          return buildCall(fn, e);
    case "LoweredVirtualCall":   return buildVirtualCall(fn, e);
    case "LoweredFieldAccess":   return buildFieldAccess(fn, e);
    case "LoweredIndex":         return buildIndex(fn, e);
    case "LoweredUnary":         return buildUnary(fn, e);
    case "LoweredBinary":        return buildBinary(fn, e);
    case "LoweredIf":            return buildIf(fn, e);
    case "LoweredBlock":         return buildBlockBody(fn, e);
    case "LoweredStructLit":     return buildStructLit(fn, e);
    case "LoweredArrayLit":      return buildArrayLit(fn, e);
    case "LoweredCast":          return buildCast(fn, e);
    case "LoweredTypeCheck":     return buildTypeCheck(fn, e);
    case "LoweredUnreachable":   return buildUnreachable(fn, e);
    case "LoweredIntrinsicCall": return buildIntrinsicCall(fn, e);
    case "LoweredArrayLen":      return buildArrayLen(fn, e);
    case "LoweredArrayPush":     return buildArrayPush(fn, e);
    case "LoweredArraySlice":    return buildArraySlice(fn, e);
    case "LoweredCellNew":       return buildCellNew(fn, e);
    case "LoweredCellGet":       return buildCellGet(fn, e);
    case "LoweredMakeClosure":   return buildMakeClosure(fn, e);
    case "LoweredDataConst":     return buildDataConst(fn, e);
  }
}

function buildIdent(fn: FnCtx, e: L.LoweredIdent): LocalId | null {
  // Local symbol — return its slot directly. Assignments mutate this slot
  // in place, so reads stay live.
  const slot = fn.localBySymId.get(e.symbol.id);
  if (slot !== undefined) {
    // For binding-kind symbols (for-in, match arms), the lowerer stamps
    // the narrowed variant on the LoweredIdent's type but doesn't wrap in
    // a LoweredCast — declaredTypeOfSymbol returns null for bindings. The
    // FieldGet/Call emit reads the local's declared (Union) type, not the
    // expr's, so without an explicit Cast it errors out as `unreachable`.
    const slotType = fn.locals[slot]?.type;
    if (slotType !== undefined && slotType.kind === "Union" && !equalsType(slotType, e.type)) {
      const dst = freshTmp(fn, "narrow", e.type);
      emit(fn, { kind: "Cast", dst, value: slot, type: e.type, span: e.span });
      return dst;
    }
    return slot;
  }

  // Fn name in a non-call position — materialise a fn ref into a fresh local.
  if (e.symbol.kind === "fn") {
    const dst = freshTmp(fn, "fn_ref", e.type);
    emit(fn, { kind: "FnRef", dst, fnSymbol: e.symbol, type: e.type, span: e.span });
    return dst;
  }

  // Unresolved — match the bytecode emit's `unreachable` fall-through.
  return buildUnreachableType(fn, e.type, e.span, `unresolved ident ${e.symbol.name}`);
}

function buildCall(fn: FnCtx, e: L.LoweredCall): LocalId | null {
  // Direct call : the callee is an ident referencing a known fn (or import
  // — both share the same InstrCall variant ; the emitter picks the right
  // call-table at lowering time). Anything else routes through CallIndirect.
  if (e.callee.kind === "LoweredIdent" && e.callee.symbol.kind === "fn") {
    const args = buildArgs(fn, e.args);
    if (args === null) return null;
    const dst = isVoid(e.type) ? null : freshTmp(fn, "call", e.type);
    emit(fn, {
      kind: "Call", dst, callee: e.callee.symbol, args, type: e.type, span: e.span,
    });
    return dst;
  }
  const callee = buildExpr(fn, e.callee);
  if (callee === null) return null;
  const args = buildArgs(fn, e.args);
  if (args === null) return null;
  const dst = isVoid(e.type) ? null : freshTmp(fn, "call_ind", e.type);
  emit(fn, {
    kind: "CallIndirect", dst, callee, args, fnType: e.callee.type, type: e.type, span: e.span,
  });
  return dst;
}

function buildArgs(fn: FnCtx, args: readonly L.LoweredExpr[]): LocalId[] | null {
  const out: LocalId[] = [];
  for (const a of args) {
    const local = buildExpr(fn, a);
    if (local === null) return null;
    out.push(local);
  }
  return out;
}

function buildVirtualCall(fn: FnCtx, e: L.LoweredVirtualCall): LocalId | null {
  const receiver = buildExpr(fn, e.receiver);
  if (receiver === null) return null;
  const args = buildArgs(fn, e.args);
  if (args === null) return null;
  const dst = isVoid(e.type) ? null : freshTmp(fn, "vcall", e.type);
  emit(fn, {
    kind: "VirtualCall", dst, traitName: e.traitName, method: e.method,
    receiver, args, type: e.type, span: e.span,
  });
  return dst;
}

function buildFieldAccess(fn: FnCtx, e: L.LoweredFieldAccess): LocalId | null {
  const target = buildExpr(fn, e.target);
  if (target === null) return null;
  const dst = freshTmp(fn, "field", e.type);
  emit(fn, { kind: "FieldGet", dst, target, field: e.field, type: e.type, span: e.span });
  return dst;
}

function buildIndex(fn: FnCtx, e: L.LoweredIndex): LocalId | null {
  const target = buildExpr(fn, e.target);
  const index = buildExpr(fn, e.index);
  if (target === null || index === null) return null;
  const dst = freshTmp(fn, "idx", e.type);
  emit(fn, { kind: "ArrayGet", dst, target, index, type: e.type, span: e.span });
  return dst;
}

function buildUnary(fn: FnCtx, e: L.LoweredUnary): LocalId | null {
  const operand = buildExpr(fn, e.operand);
  if (operand === null) return null;
  const dst = freshTmp(fn, e.op, e.type);
  emit(fn, { kind: "UnOp", dst, op: e.op, operand, type: e.type, span: e.span });
  return dst;
}

function buildBinary(fn: FnCtx, e: L.LoweredBinary): LocalId | null {
  // Short-circuit `&&` / `||` lower to control flow so the RHS doesn't run
  // when the result is already determined by the LHS. Mirrors the bytecode
  // emit's `emitShortCircuit` ; without this, the CFG-path would evaluate
  // both sides eagerly and crash on RHS expressions guarded by the LHS
  // (`j > 0 && arr[j-1]` etc.).
  if (e.op === "and" || e.op === "or") return buildShortCircuit(fn, e);

  const lhs = buildExpr(fn, e.left);
  if (lhs === null) return null;
  const rhs = buildExpr(fn, e.right);
  if (rhs === null) return null;
  const dst = freshTmp(fn, e.op, e.type);
  emit(fn, { kind: "BinOp", dst, op: e.op, lhs, rhs, type: e.type, span: e.span });
  return dst;
}

/** Lower `a && b` to `if a { b } else { false }` ; `a || b` to
 *  `if a { true } else { b }`. The result lives in a fresh boolean local
 *  written by both arms of the if. */
function buildShortCircuit(fn: FnCtx, e: L.LoweredBinary): LocalId | null {
  const lhs = buildExpr(fn, e.left);
  if (lhs === null) return null;

  const result = declareLocal(fn, e.op === "and" ? "and_res" : "or_res", e.type, null);
  const thenId = newBlock(fn, e.right.span);
  const elseId = newBlock(fn, e.right.span);
  const joinId = newBlock(fn, e.span);

  terminate(fn, {
    kind: "CondBranch", cond: lhs,
    then: thenId, else: elseId, span: e.span,
  });

  // `and` : then = rhs ; else = false. `or` : then = true ; else = rhs.
  fn.current = thenId;
  if (e.op === "and") {
    const rhs = buildExpr(fn, e.right);
    if (rhs !== null && fn.current !== null) {
      emit(fn, { kind: "Move", dst: result, src: rhs, span: e.right.span });
    }
  } else {
    const trueLocal = freshTmp(fn, "k", e.type);
    emit(fn, {
      kind: "Const", dst: trueLocal,
      value: { kind: "bool", value: true },
      type: e.type, span: e.span,
    });
    emit(fn, { kind: "Move", dst: result, src: trueLocal, span: e.span });
  }
  if (fn.current !== null) {
    terminate(fn, { kind: "Branch", target: joinId, span: e.span });
  }

  fn.current = elseId;
  if (e.op === "and") {
    const falseLocal = freshTmp(fn, "k", e.type);
    emit(fn, {
      kind: "Const", dst: falseLocal,
      value: { kind: "bool", value: false },
      type: e.type, span: e.span,
    });
    emit(fn, { kind: "Move", dst: result, src: falseLocal, span: e.span });
  } else {
    const rhs = buildExpr(fn, e.right);
    if (rhs !== null && fn.current !== null) {
      emit(fn, { kind: "Move", dst: result, src: rhs, span: e.right.span });
    }
  }
  if (fn.current !== null) {
    terminate(fn, { kind: "Branch", target: joinId, span: e.span });
  }

  fn.current = joinId;
  return result;
}

function buildIf(fn: FnCtx, e: L.LoweredIf): LocalId | null {
  const condLocal = buildExpr(fn, e.cond);
  if (condLocal === null) return null;

  const result = isVoid(e.type) ? null : declareLocal(fn, "if_res", e.type, null);

  const elseExpr = e.else;
  const thenId = newBlock(fn, e.then.span);
  const elseId = elseExpr !== null ? newBlock(fn, elseExpr.span) : null;
  const joinId = newBlock(fn, e.span);

  terminate(fn, {
    kind: "CondBranch", cond: condLocal,
    then: thenId, else: elseId ?? joinId, span: e.span,
  });

  fn.current = thenId;
  const thenVal = buildBlockBody(fn, e.then);
  if (fn.current !== null) {
    if (result !== null && thenVal !== null) {
      emit(fn, { kind: "Move", dst: result, src: thenVal, span: e.then.span });
    }
    terminate(fn, { kind: "Branch", target: joinId, span: e.then.span });
  }

  // No-else if : the CondBranch targets join directly, nothing extra to build.
  if (elseId !== null && elseExpr !== null) {
    fn.current = elseId;
    const elseVal = buildBlockBody(fn, elseExpr);
    if (fn.current !== null) {
      if (result !== null && elseVal !== null) {
        emit(fn, { kind: "Move", dst: result, src: elseVal, span: elseExpr.span });
      }
      terminate(fn, { kind: "Branch", target: joinId, span: elseExpr.span });
    }
  }

  fn.current = joinId;
  return result;
}

function buildStructLit(fn: FnCtx, e: L.LoweredStructLit): LocalId | null {
  const fieldLocals: LocalId[] = [];
  for (const f of e.fields) {
    const local = buildExpr(fn, f.value);
    if (local === null) return null;
    fieldLocals.push(local);
  }
  const dst = freshTmp(fn, "struct", e.type);
  emit(fn, {
    kind: "StructNew", dst, type: e.type, fields: fieldLocals,
    stack: false, span: e.span,
  });
  return dst;
}

function buildArrayLit(fn: FnCtx, e: L.LoweredArrayLit): LocalId | null {
  const elems: LocalId[] = [];
  for (const el of e.elements) {
    const local = buildExpr(fn, el);
    if (local === null) return null;
    elems.push(local);
  }
  const dst = freshTmp(fn, "arr", e.type);
  emit(fn, {
    kind: "ArrayNew", dst, type: e.type, length: e.elements.length,
    elements: elems, stack: false, span: e.span,
  });
  return dst;
}

function buildCast(fn: FnCtx, e: L.LoweredCast): LocalId | null {
  const value = buildExpr(fn, e.value);
  if (value === null) return null;
  const dst = freshTmp(fn, "cast", e.type);
  emit(fn, { kind: "Cast", dst, value, type: e.type, span: e.span });
  return dst;
}

function buildTypeCheck(fn: FnCtx, e: L.LoweredTypeCheck): LocalId | null {
  const value = buildExpr(fn, e.value);
  if (value === null) return null;
  const dst = freshTmp(fn, "type_check", e.type);
  emit(fn, {
    kind: "TypeCheck", dst, value, checkType: e.checkType, span: e.span,
  });
  return dst;
}

function buildUnreachable(fn: FnCtx, e: L.LoweredUnreachable): LocalId | null {
  return buildUnreachableType(fn, e.type, e.span, e.reason);
}

/** Shared helper : terminate the current block with `Unreachable`, then
 *  allocate a synthetic dead-block to absorb anything that follows in the
 *  source-level expression (the value is never observed). The returned
 *  local is uninitialised and only needed so the surrounding context can
 *  thread a LocalId through ; the dead block's terminator stays as the
 *  Unreachable emitted here. */
function buildUnreachableType(fn: FnCtx, type: Type, span: Span, reason: string): LocalId | null {
  if (fn.current === null) return null;
  const placeholder = isVoid(type) ? null : declareLocal(fn, "unreachable", type, null);
  terminate(fn, { kind: "Unreachable", reason, span });
  return placeholder;
}

function buildIntrinsicCall(fn: FnCtx, e: L.LoweredIntrinsicCall): LocalId | null {
  const args = buildArgs(fn, e.args);
  if (args === null) return null;
  const dst = isVoid(e.type) ? null : freshTmp(fn, "intrinsic", e.type);
  emit(fn, {
    kind: "Intrinsic", dst, name: e.name, args,
    displayFor: e.displayFor, span: e.span,
  });
  return dst;
}

function buildArrayLen(fn: FnCtx, e: L.LoweredArrayLen): LocalId | null {
  const target = buildExpr(fn, e.target);
  if (target === null) return null;
  const dst = freshTmp(fn, "len", e.type);
  emit(fn, { kind: "ArrayLen", dst, target, span: e.span });
  return dst;
}

function buildArrayPush(fn: FnCtx, e: L.LoweredArrayPush): LocalId | null {
  const target = buildExpr(fn, e.target);
  const value = buildExpr(fn, e.value);
  if (target === null || value === null) return null;
  emit(fn, { kind: "ArrayPush", target, value, span: e.span });
  return null;       // push returns void
}

function buildArraySlice(fn: FnCtx, e: L.LoweredArraySlice): LocalId | null {
  const target = buildExpr(fn, e.target);
  const lo = buildExpr(fn, e.lo);
  const hi = buildExpr(fn, e.hi);
  if (target === null || lo === null || hi === null) return null;
  const dst = freshTmp(fn, "slice", e.type);
  emit(fn, { kind: "ArraySlice", dst, type: e.type, target, lo, hi, span: e.span });
  return dst;
}

function buildDataConst(fn: FnCtx, e: L.LoweredDataConst): LocalId | null {
  const dst = freshTmp(fn, "data_const", e.type);
  emit(fn, { kind: "DataConst", dst, type: e.type, poolIndex: e.poolIndex, span: e.span });
  return dst;
}

function buildCellNew(fn: FnCtx, e: L.LoweredCellNew): LocalId | null {
  const value = buildExpr(fn, e.value);
  if (value === null) return null;
  const dst = freshTmp(fn, "cell", e.type);
  emit(fn, {
    kind: "CellNew", dst, value, valueType: e.valueType, span: e.span,
  });
  return dst;
}

function buildCellGet(fn: FnCtx, e: L.LoweredCellGet): LocalId | null {
  const target = buildExpr(fn, e.target);
  if (target === null) return null;
  const dst = freshTmp(fn, "cell_get", e.type);
  emit(fn, {
    kind: "CellGet", dst, cell: target, valueType: e.valueType, span: e.span,
  });
  return dst;
}

function buildMakeClosure(fn: FnCtx, e: L.LoweredMakeClosure): LocalId | null {
  const env = buildExpr(fn, e.env);
  if (env === null) return null;
  const dst = freshTmp(fn, "closure", e.type);
  emit(fn, {
    kind: "MakeClosure", dst, fnSymbol: e.fnSymbol, env, type: e.type, span: e.span,
  });
  return dst;
}

// ============================================================================
// Builders' bookkeeping helpers
// ============================================================================

function emit(fn: FnCtx, instr: Instruction): void {
  if (fn.current === null) return;
  fn.blocks[fn.current]!.instructions.push(instr);
}

function emitConst(fn: FnCtx, type: Type, value: ConstValue, span: Span): LocalId {
  const dst = freshTmp(fn, "k", type);
  emit(fn, { kind: "Const", dst, value, type, span });
  return dst;
}

function terminate(fn: FnCtx, t: Terminator): void {
  if (fn.current === null) return;
  const cur = fn.blocks[fn.current]!;
  if (cur.terminator === null) cur.terminator = t;
  fn.current = null;
}

function newBlock(fn: FnCtx, span: Span): BlockId {
  const id = fn.blocks.length;
  fn.blocks.push({ id, instructions: [], terminator: null, span });
  return id;
}

function declareLocal(fn: FnCtx, name: string, type: Type, symbol: Symbol | null): LocalId {
  const id = fn.locals.length;
  fn.locals.push({ name, type, symbol });
  return id;
}

function freshTmp(fn: FnCtx, hint: string, type: Type): LocalId {
  return declareLocal(fn, `$${hint}_${fn.locals.length}`, type, null);
}

function isVoid(t: Type): boolean {
  return isPrimitive(t, "void");
}
