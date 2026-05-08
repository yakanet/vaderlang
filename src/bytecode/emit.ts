// Bytecode emitter — LoweredProject → BytecodeModule. See SPEC §2 ("Lowered
// AST" → bytecode) and §17 (canonical IR).

import type { Span } from "../diagnostics/diagnostic.ts";
import { DEC, hasDecorator } from "../parser/decorators.ts";
import type * as L from "../lower/lowered-ast.ts";
import type { LoweredProject } from "../lower/index.ts";
import type { PrimitiveName, Type } from "../typecheck/types.ts";
import { displayType } from "../typecheck/types.ts";
import type { ImplRegistry } from "../typecheck/impls.ts";

import {
  intrinsicIdByName,
  type ArithOpKind, type BitNotOpKind, type BitOpKind, type CmpOpKind,
  type ConvertOpKind, type IntrinsicId, type NegOpKind, type Op,
} from "./ops.ts";
import type {
  BcImport, BcLocal, BcSignature, BytecodeModule, DebugPos,
} from "./module.ts";
import { runPeepholes } from "./peephole.ts";
import type { BcType, ValType } from "./types.ts";
import { isIntegerVal, isNumericVal } from "./types.ts";

/** Stdlib `@intrinsic` impl methods that map to a dedicated bytecode op
 *  rather than to a host-provided import. Keyed by the impl-method mangled
 *  name (`<module>$<type>$<trait>$<method>`) so the lookup happens after
 *  name-mangling and skips the `call.import` indirection — `s1 + s2` and
 *  `"a".add("b")` both emit the same `string.concat` op. */
export const OP_INTRINSIC_BY_MANGLED: ReadonlyMap<string, () => Op> = new Map([
  ["std_core$string$Add$add", () => ({ kind: "string.concat" })],
]);

/** Knobs for the bytecode emitter. Today this only toggles the peephole
 *  pass; future codegen-time options (e.g. inline-thresholds, bound checks)
 *  belong here. */
export interface EmitOptions {
  /** Run peephole optimisations on every function body. Default: `true`. */
  readonly optimize?: boolean;
  /** When provided, trait impl information is recorded in the module's
   *  `implTable` so consumers (VM, C emit) can resolve `match val { is Trait -> … }`. */
  readonly implRegistry?: ImplRegistry;
}

export function emitBytecode(
  project: LoweredProject, name: string, options: EmitOptions = {},
): BytecodeModule {
  const ctx = newEmitterCtx(options.optimize ?? true, options.implRegistry ?? null);
  // Pass 1 reserves indices so cross-references resolve regardless of decl order.
  for (const m of project.modules.values()) {
    for (const d of m.decls) reserveDecl(d, ctx);
  }
  // Pass 2 fills in fn bodies.
  for (const m of project.modules.values()) {
    for (const d of m.decls) emitDecl(d, ctx);
  }
  return {
    name,
    types:     ctx.types,
    strings:   ctx.strings,
    functions: ctx.functions,
    imports:   ctx.imports,
    exports:   ctx.exports,
    implTable: ctx.implTable,
    vtables:   buildVtables(ctx, project.vtableEntries),
  };
}

/** Translate the lowerer's pre-flattened vtable entries into per-(trait,
 *  method) tables keyed by the receiver's type index. Shared between the
 *  legacy `LoweredAST → bytecode` path and the CFG-based emitter. */
export function buildVtables(
  ctx: EmitterCtx, entries: readonly L.VtableEntry[],
): Map<string, Map<number, number>> {
  const vtables = new Map<string, Map<number, number>>();
  for (const e of entries) {
    const fnIdx = ctx.fnIndexBySymId.get(e.fnSymbol.id);
    if (fnIdx === undefined) continue;
    const typeIdx = internType(ctx, e.structType);
    const key = `${e.traitName}.${e.methodName}`;
    let table = vtables.get(key);
    if (table === undefined) { table = new Map(); vtables.set(key, table); }
    table.set(typeIdx, fnIdx);
  }
  return vtables;
}

export interface EmitterCtx {
  readonly types: BcType[];
  readonly typeKey: Map<string, number>;          // displayType(t) → index
  readonly strings: string[];
  readonly stringKey: Map<string, number>;
  readonly functions: MutableFn[];
  readonly fnIndexBySymId: Map<number, number>;
  readonly imports: BcImport[];
  readonly importIndexBySymId: Map<number, number>;
  readonly exports: { externName: string; fnIndex: number }[];
  /** Const decls inlined at every use site by `emitIdent`. */
  readonly constDecls: Map<number, L.LoweredConstDecl>;
  readonly optimize: boolean;
  /** Impl table being built: structTypeIndex → set of trait names. */
  readonly implTable: Map<number, string[]>;
  /** Pre-built index: struct symbol id → trait names it implements. Empty when
   *  no `ImplRegistry` was provided. Avoids O(structs × impls) at intern time. */
  readonly traitsBySymbolId: Map<number, string[]>;
}

/** Writable shadow of `BcFunction` — populated during pass 2, returned as the
 *  readonly external shape via covariant assignment. */
interface MutableFn {
  readonly name: string;
  readonly signature: BcSignature;
  locals: BcLocal[];
  body: Op[];
  debug: (DebugPos | null)[];
}

export function newEmitterCtx(optimize: boolean, implRegistry: ImplRegistry | null): EmitterCtx {
  const traitsBySymbolId = new Map<number, string[]>();
  if (implRegistry !== null) {
    for (const entry of implRegistry.entries()) {
      if (entry.forSymbol === null) continue;
      const list = traitsBySymbolId.get(entry.forSymbol.id);
      if (list !== undefined) list.push(entry.traitSymbol.name);
      else traitsBySymbolId.set(entry.forSymbol.id, [entry.traitSymbol.name]);
    }
  }
  return {
    types: [], typeKey: new Map(),
    strings: [], stringKey: new Map(),
    functions: [], fnIndexBySymId: new Map(),
    imports: [], importIndexBySymId: new Map(),
    exports: [],
    constDecls: new Map(),
    optimize,
    implTable: new Map(),
    traitsBySymbolId,
  };
}

// ----------------------------------------------------------- pass 1: reserve

export function reserveDecl(d: L.LoweredDecl, ctx: EmitterCtx): void {
  switch (d.kind) {
    case "LoweredFnDecl":   reserveFn(d, ctx); return;
    case "LoweredStructDecl": internStructDecl(d, ctx); return;
    case "LoweredConstDecl":
      if (d.origin.symbol !== null) ctx.constDecls.set(d.origin.symbol.id, d);
      return;
  }
}

function reserveFn(d: L.LoweredFnDecl, ctx: EmitterCtx): void {
  const sig = signatureOf(d);
  const decoratorList = d.origin.decl.kind === "FnDecl" ? d.origin.decl.decorators : [];
  const externName = d.origin.decl.kind === "FnDecl" ? d.origin.decl.name : d.mangled;
  const isExtern = d.body === null || hasDecorator(decoratorList, DEC.extern);

  if (isExtern) {
    if (d.origin.symbol !== null) ctx.importIndexBySymId.set(d.origin.symbol.id, ctx.imports.length);
    ctx.imports.push({ externName, mangledName: d.mangled, signature: sig });
    return;
  }

  const fnIndex = ctx.functions.length;
  if (d.origin.symbol !== null) ctx.fnIndexBySymId.set(d.origin.symbol.id, fnIndex);
  ctx.functions.push({
    name: d.mangled, signature: sig, locals: [], body: [], debug: [],
  });
  if (hasDecorator(decoratorList, DEC.export)) {
    ctx.exports.push({ externName, fnIndex });
  }
}

// ------------------------------------------------------- pass 2: emit bodies

function emitDecl(d: L.LoweredDecl, ctx: EmitterCtx): void {
  if (d.kind !== "LoweredFnDecl" || d.body === null) return;
  if (d.origin.symbol === null) return;
  const fnIndex = ctx.fnIndexBySymId.get(d.origin.symbol.id);
  if (fnIndex === undefined) return;     // routed to imports

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

  for (let i = 0; i < d.params.length; i++) {
    fn.slotBySymbolId.set(d.params[i]!.symbol.id, i);
  }

  emitBlockBody(fn, d.body);

  if (slot.signature.result !== "void" && d.body.trailing !== null) {
    pushOp(fn, { kind: "return" }, d.body.trailing.span);
  }

  if (ctx.optimize) runPeepholes(fn);

  slot.locals = fn.locals;
  slot.body = fn.body;
  slot.debug = fn.debug;
}

// ----------------------------------------------------------- per-fn state

export interface FnEmitCtx {
  readonly project: EmitterCtx;
  readonly signature: BcSignature;
  readonly locals: BcLocal[];
  readonly body: Op[];
  readonly debug: (DebugPos | null)[];
  readonly slotBySymbolId: Map<number, number>;
  readonly labelStack: Label[];
}

interface Label {
  readonly kind: "block" | "loop" | "if";
  readonly isBreakTarget?: boolean;
  readonly isContinueTarget?: boolean;
}

export function pushOp(fn: FnEmitCtx, op: Op, span?: Span): void {
  fn.body.push(op);
  fn.debug.push(span === undefined ? null : {
    file: span.start.file, line: span.start.line, column: span.start.column,
  });
}

export function declareLocal(fn: FnEmitCtx, name: string, val: ValType): number {
  const slot = fn.signature.params.length + fn.locals.length;
  fn.locals.push({ name, val });
  return slot;
}

// ----------------------------------------------------------- blocks & stmts

function emitBlockBody(fn: FnEmitCtx, b: L.LoweredBlock): void {
  for (const s of b.stmts) emitStmt(fn, s);
  if (b.trailing !== null) emitExpr(fn, b.trailing);
}

function emitStmt(fn: FnEmitCtx, s: L.LoweredStmt): void {
  switch (s.kind) {
    case "LoweredLet": {
      emitExpr(fn, s.value);
      const slot = declareLocal(fn, s.name, valTypeOf(s.type));
      fn.slotBySymbolId.set(s.symbol.id, slot);
      pushOp(fn, { kind: "local.set", slot }, s.span);
      return;
    }
    case "LoweredAssign":
      emitAssign(fn, s);
      return;
    case "LoweredCellSet": {
      // Cell update: pop cell ref, pop value, struct.set on the synthesized
      // single-slot struct. We emit target first so the value lands on top —
      // matching struct.set's stack convention (struct, value).
      const cellTypeIdx = internCellType(fn.project, s.valueType);
      emitExpr(fn, s.target);
      emitExpr(fn, s.value);
      pushOp(fn, { kind: "struct.set", typeIndex: cellTypeIdx, fieldIndex: 0 }, s.span);
      return;
    }
    case "LoweredExprStmt": {
      emitExpr(fn, s.expr);
      if (valTypeOf(s.expr.type) !== "void") pushOp(fn, { kind: "drop" }, s.span);
      return;
    }
    case "LoweredReturn":
      if (s.value !== null) emitExpr(fn, s.value);
      pushOp(fn, { kind: "return" }, s.span);
      return;
    case "LoweredLoop":
      emitLoop(fn, s);
      return;
    case "LoweredBreak":
      pushOp(fn, { kind: "br", depth: depthOfLabel(fn, "break") }, s.span);
      return;
    case "LoweredContinue":
      pushOp(fn, { kind: "br", depth: depthOfLabel(fn, "continue") }, s.span);
      return;
  }
}

function emitAssign(fn: FnEmitCtx, s: L.LoweredAssign): void {
  const target = s.target;
  switch (target.kind) {
    case "LoweredIdent": {
      const slot = fn.slotBySymbolId.get(target.symbol.id);
      if (slot === undefined) { dropResult(fn, s.value, s.span); return; }
      emitExpr(fn, s.value);
      pushOp(fn, { kind: "local.set", slot }, s.span);
      return;
    }
    case "LoweredFieldAccess": {
      const typeIndex = internType(fn.project, target.target.type);
      const struct = fn.project.types[typeIndex];
      if (struct?.kind !== "struct") { dropResult(fn, s.value, s.span); return; }
      const fieldIndex = struct.fields.findIndex((f) => f.name === target.field);
      if (fieldIndex < 0) { dropResult(fn, s.value, s.span); return; }
      emitExpr(fn, target.target);
      emitExpr(fn, s.value);
      pushOp(fn, { kind: "struct.set", typeIndex, fieldIndex }, s.span);
      return;
    }
    case "LoweredIndex": {
      const typeIndex = internType(fn.project, target.target.type);
      emitExpr(fn, target.target);
      emitExpr(fn, target.index);
      emitExpr(fn, s.value);
      pushOp(fn, { kind: "array.set", typeIndex }, s.span);
      return;
    }
    default:
      dropResult(fn, s.value, s.span);
      return;
  }
}

function dropResult(fn: FnEmitCtx, value: L.LoweredExpr, span: Span): void {
  emitExpr(fn, value);
  if (valTypeOf(value.type) !== "void") pushOp(fn, { kind: "drop" }, span);
}

function emitLoop(fn: FnEmitCtx, s: L.LoweredLoop): void {
  // outer block = break-target; inner loop = continue-target.
  pushOp(fn, { kind: "block", result: "void" }, s.span);
  fn.labelStack.push({ kind: "block", isBreakTarget: true });
  pushOp(fn, { kind: "loop", result: "void" }, s.span);
  fn.labelStack.push({ kind: "loop", isContinueTarget: true });

  if (s.cond !== null) {
    emitExpr(fn, s.cond);
    pushOp(fn, { kind: "bool.not" }, s.cond.span);
    pushOp(fn, { kind: "br_if", depth: 1 }, s.cond.span);
  }
  emitBlockBody(fn, s.body);
  pushOp(fn, { kind: "br", depth: 0 }, s.span);

  fn.labelStack.pop();
  pushOp(fn, { kind: "end" }, s.span);
  fn.labelStack.pop();
  pushOp(fn, { kind: "end" }, s.span);
}

function depthOfLabel(fn: FnEmitCtx, kind: "break" | "continue"): number {
  for (let i = fn.labelStack.length - 1; i >= 0; i--) {
    const l = fn.labelStack[i]!;
    if (kind === "break"   && l.isBreakTarget)    return fn.labelStack.length - 1 - i;
    if (kind === "continue" && l.isContinueTarget) return fn.labelStack.length - 1 - i;
  }
  return 0;
}

// ----------------------------------------------------------- expressions

function emitExpr(fn: FnEmitCtx, e: L.LoweredExpr): void {
  switch (e.kind) {
    case "LoweredIntLit":   emitIntConst(fn, e.value, valTypeOf(e.type), e.span); return;
    case "LoweredFloatLit": emitFloatConst(fn, e.value, valTypeOf(e.type), e.span); return;
    case "LoweredBoolLit":  pushOp(fn, { kind: "bool.const",  value: e.value }, e.span); return;
    case "LoweredNullLit":  pushOp(fn, { kind: "null.const" }, e.span); return;
    case "LoweredCharLit":  pushOp(fn, { kind: "char.const",  value: e.value }, e.span); return;
    case "LoweredStringLit":
      pushOp(fn, { kind: "string.const", index: internString(fn.project, e.value) }, e.span);
      return;
    case "LoweredIdent":         emitIdent(fn, e); return;
    case "LoweredCall":          emitCall(fn, e); return;
    case "LoweredVirtualCall":   emitVirtualCall(fn, e); return;
    case "LoweredFieldAccess":   emitFieldAccess(fn, e); return;
    case "LoweredIndex": {
      const typeIndex = internType(fn.project, e.target.type);
      emitExpr(fn, e.target);
      emitExpr(fn, e.index);
      pushOp(fn, { kind: "array.get", typeIndex }, e.span);
      // `array.get` always yields a boxed value (`any`/`ref`), but the lowered
      // expression's static type is the element type. Insert a `ref.cast`
      // when the element is a primitive so downstream typed ops see the
      // unboxed value (matches the policy used for match-arm narrowing).
      const elemVal = valTypeOf(e.type);
      if (elemVal !== "ref" && elemVal !== "any" && elemVal !== "void") {
        pushOp(fn, { kind: "ref.cast", typeIndex: internType(fn.project, e.type) }, e.span);
      }
      return;
    }
    case "LoweredUnary":         emitUnary(fn, e); return;
    case "LoweredBinary":        emitBinary(fn, e); return;
    case "LoweredIf":            emitIf(fn, e); return;
    case "LoweredBlock":         emitBlockBody(fn, e); return;
    case "LoweredStructLit":     emitStructLit(fn, e); return;
    case "LoweredArrayLit": {
      const typeIndex = internType(fn.project, e.type);
      for (const elt of e.elements) emitExpr(fn, elt);
      pushOp(fn, { kind: "array.new", typeIndex, length: e.elements.length }, e.span);
      return;
    }
    case "LoweredCast":          emitCast(fn, e); return;
    case "LoweredTypeCheck": {
      emitExpr(fn, e.value);
      const typeIndex = internType(fn.project, e.checkType);
      pushOp(fn, { kind: "type_check", typeIndex }, e.span);
      return;
    }
    case "LoweredUnreachable":   pushOp(fn, { kind: "unreachable" }, e.span); return;
    case "LoweredIntrinsicCall": {
      for (const a of e.args) emitExpr(fn, a);
      const id = intrinsicIdByName(e.name);
      if (id === null) { pushOp(fn, { kind: "unreachable" }, e.span); return; }
      pushOp(fn, { kind: "intrinsic", id: id as IntrinsicId }, e.span);
      return;
    }
    case "LoweredArrayLen": {
      emitExpr(fn, e.target);
      pushOp(fn, { kind: "array.len" }, e.span);
      return;
    }
    case "LoweredArrayPush": {
      emitExpr(fn, e.target);
      emitExpr(fn, e.value);
      pushOp(fn, { kind: "array.push", typeIndex: internType(fn.project, e.value.type) }, e.span);
      return;
    }
    case "LoweredCellNew": {
      // Synthesised one-field struct; struct.new pops the value, allocates,
      // and pushes the cell ref.
      const cellTypeIdx = internCellType(fn.project, e.valueType);
      emitExpr(fn, e.value);
      pushOp(fn, { kind: "struct.new", typeIndex: cellTypeIdx }, e.span);
      return;
    }
    case "LoweredCellGet": {
      const cellTypeIdx = internCellType(fn.project, e.valueType);
      emitExpr(fn, e.target);
      pushOp(fn, { kind: "struct.get", typeIndex: cellTypeIdx, fieldIndex: 0 }, e.span);
      return;
    }
    case "LoweredMakeClosure": {
      // Emit env (a struct value) then make_closure with the lifted fn's
      // bytecode index + the closure's BcFn type index.
      emitExpr(fn, e.env);
      const fnIdx = fn.project.fnIndexBySymId.get(e.fnSymbol.id);
      if (fnIdx === undefined) {
        // Should never happen — synth lifted fns are added to the project
        // before bytecode emit walks function bodies.
        pushOp(fn, { kind: "unreachable" }, e.span);
        return;
      }
      const typeIndex = internType(fn.project, e.type);
      pushOp(fn, { kind: "make_closure", fnIndex: fnIdx, typeIndex }, e.span);
      return;
    }
  }
}

function emitIdent(fn: FnEmitCtx, e: L.LoweredIdent): void {
  const slot = fn.slotBySymbolId.get(e.symbol.id);
  if (slot !== undefined) {
    pushOp(fn, { kind: "local.get", slot }, e.span);
    return;
  }
  const constDecl = fn.project.constDecls.get(e.symbol.id);
  if (constDecl !== undefined) {
    emitExpr(fn, constDecl.value);
    return;
  }
  // Fn name used as a value: push a fn ref. The runtime representation is a
  // fat pointer `{ code, env }` with `env = null` for non-capturing globals.
  // typeIndex resolves to a BcFn entry — used by the C emit to set the runtime
  // tag and pick the right function-pointer cast.
  const fnIdx = fn.project.fnIndexBySymId.get(e.symbol.id);
  if (fnIdx !== undefined) {
    const typeIndex = internType(fn.project, e.type);
    pushOp(fn, { kind: "fn.ref", fnIndex: fnIdx, typeIndex }, e.span);
    return;
  }
  pushOp(fn, { kind: "unreachable" }, e.span);
}

function emitCall(fn: FnEmitCtx, e: L.LoweredCall): void {
  if (e.callee.kind === "LoweredIdent") {
    const sym = e.callee.symbol;
    // Op-level intrinsics — short-circuit before fn / import dispatch so
    // `string_concat(a, b)` reaches the dedicated `string.concat` op without
    // an import indirection. Same fast-path as the `+` operator.
    const importIdx = fn.project.importIndexBySymId.get(sym.id);
    if (importIdx !== undefined) {
      const mangled = fn.project.imports[importIdx]!.mangledName;
      const opIntrinsic = OP_INTRINSIC_BY_MANGLED.get(mangled);
      if (opIntrinsic !== undefined) {
        for (const a of e.args) emitExpr(fn, a);
        pushOp(fn, opIntrinsic(), e.span);
        return;
      }
    }
    const fnIdx = fn.project.fnIndexBySymId.get(sym.id);
    if (fnIdx !== undefined) {
      for (const a of e.args) emitExpr(fn, a);
      pushOp(fn, { kind: "call", fnIndex: fnIdx }, e.span);
      return;
    }
    if (importIdx !== undefined) {
      for (const a of e.args) emitExpr(fn, a);
      pushOp(fn, { kind: "call.import", importIndex: importIdx }, e.span);
      return;
    }
  }
  // Indirect call: callee is fn-typed (a local, a struct field, an array
  // element, etc.). WASM convention — args first, callee on top, sig index
  // encoded in the op for verification and so the C emitter can pick the
  // right function-pointer cast.
  if (e.callee.type.kind === "Fn") {
    for (const a of e.args) emitExpr(fn, a);
    emitExpr(fn, e.callee);
    const typeIndex = internType(fn.project, e.callee.type);
    pushOp(fn, { kind: "call.indirect", typeIndex }, e.span);
    return;
  }
  // Truly unresolved callee (non-Fn type) — surface as unreachable.
  for (const a of e.args) emitExpr(fn, a);
  pushOp(fn, { kind: "unreachable" }, e.span);
}

function emitVirtualCall(fn: FnEmitCtx, e: L.LoweredVirtualCall): void {
  // Stack at entry to `virtual.call`: …args, receiver. The runtime pops the
  // receiver, reads its type tag, looks up the (vtableKey, tag) entry, then
  // calls the impl fn with [receiver-cast-to-impl-type, ...args].
  for (const a of e.args) emitExpr(fn, a);
  emitExpr(fn, e.receiver);
  pushOp(fn, {
    kind: "virtual.call",
    vtableKey: `${e.traitName}.${e.method}`,
    paramCount: e.args.length + 1,
  }, e.span);
}

function emitFieldAccess(fn: FnEmitCtx, e: L.LoweredFieldAccess): void {
  const typeIndex = internType(fn.project, e.target.type);
  const struct = fn.project.types[typeIndex];
  if (struct?.kind !== "struct") {
    emitExpr(fn, e.target);
    pushOp(fn, { kind: "drop" }, e.span);
    pushOp(fn, { kind: "unreachable" }, e.span);
    return;
  }
  const fieldIndex = struct.fields.findIndex((f) => f.name === e.field);
  if (fieldIndex < 0) {
    emitExpr(fn, e.target);
    pushOp(fn, { kind: "drop" }, e.span);
    pushOp(fn, { kind: "unreachable" }, e.span);
    return;
  }
  emitExpr(fn, e.target);
  pushOp(fn, { kind: "struct.get", typeIndex, fieldIndex }, e.span);
}

function emitStructLit(fn: FnEmitCtx, e: L.LoweredStructLit): void {
  const typeIndex = internType(fn.project, e.type);
  const struct = fn.project.types[typeIndex];
  if (struct?.kind !== "struct") {
    pushOp(fn, { kind: "unreachable" }, e.span);
    return;
  }
  for (const f of struct.fields) {
    const lit = e.fields.find((lf) => lf.name === f.name);
    if (lit !== undefined) emitExpr(fn, lit.value);
    else pushOp(fn, { kind: "null.const" }, e.span);
  }
  pushOp(fn, { kind: "struct.new", typeIndex }, e.span);
}

function emitUnary(fn: FnEmitCtx, e: L.LoweredUnary): void {
  emitExpr(fn, e.operand);
  const t = valTypeOf(e.type);
  switch (e.op) {
    case "neg":    pushOp(fn, { kind: `${asNumeric(t)}.neg`    as NegOpKind   }, e.span); return;
    case "not":    pushOp(fn, { kind: "bool.not" },                              e.span); return;
    case "bitnot": pushOp(fn, { kind: `${asInt(t)}.bitnot`     as BitNotOpKind }, e.span); return;
  }
}

function emitBinary(fn: FnEmitCtx, e: L.LoweredBinary): void {
  if (e.op === "and" || e.op === "or") { emitShortCircuit(fn, e); return; }
  emitExpr(fn, e.left);
  emitExpr(fn, e.right);
  pushOp(fn, binaryOpFor(e.op, valTypeOf(e.left.type)), e.span);
}

function emitShortCircuit(fn: FnEmitCtx, e: L.LoweredBinary): void {
  // and: a ? b : false
  // or:  a ? true : b
  emitExpr(fn, e.left);
  pushOp(fn, { kind: "if", result: "bool" }, e.span);
  fn.labelStack.push({ kind: "if" });
  if (e.op === "and") {
    emitExpr(fn, e.right);
    pushOp(fn, { kind: "else" }, e.span);
    pushOp(fn, { kind: "bool.const", value: false }, e.span);
  } else {
    pushOp(fn, { kind: "bool.const", value: true }, e.span);
    pushOp(fn, { kind: "else" }, e.span);
    emitExpr(fn, e.right);
  }
  pushOp(fn, { kind: "end" }, e.span);
  fn.labelStack.pop();
}

function emitIf(fn: FnEmitCtx, e: L.LoweredIf): void {
  emitExpr(fn, e.cond);
  const result = valTypeOf(e.type);
  pushOp(fn, { kind: "if", result }, e.span);
  fn.labelStack.push({ kind: "if" });
  emitBlockBody(fn, e.then);
  if (e.else !== null) {
    pushOp(fn, { kind: "else" }, e.span);
    emitBlockBody(fn, e.else);
  } else if (result !== "void") {
    pushOp(fn, { kind: "else" }, e.span);
    pushOp(fn, { kind: "unreachable" }, e.span);
  }
  pushOp(fn, { kind: "end" }, e.span);
  fn.labelStack.pop();
}

function emitCast(fn: FnEmitCtx, e: L.LoweredCast): void {
  const fromType = valTypeOf(e.value.type);
  const toType   = valTypeOf(e.type);
  emitExpr(fn, e.value);
  if (fromType === toType) return;
  if (fromType === "ref" || fromType === "any" || toType === "ref" || toType === "any") {
    pushOp(fn, { kind: "ref.cast", typeIndex: internType(fn.project, e.type) }, e.span);
    return;
  }
  // Preserve `char` on either side so the VM/C emitter can retag (char is
  // wire-compatible with u32 but needs a distinct tag).
  const fromWire = fromType === "char" ? "char" : asNumeric(fromType);
  const toWire   = toType   === "char" ? "char" : asNumeric(toType);
  pushOp(fn, { kind: `${fromWire}.to_${toWire}` as ConvertOpKind }, e.span);
}

// ----------------------------------------------------------- interning

export function internType(ctx: EmitterCtx, t: Type): number {
  const key = displayType(t);
  const cached = ctx.typeKey.get(key);
  if (cached !== undefined) return cached;
  // Reserve placeholder so recursive/self types don't loop.
  const idx = ctx.types.length;
  ctx.types.push({ kind: "ref", traitName: null });
  ctx.typeKey.set(key, idx);
  ctx.types[idx] = bcTypeOf(t, ctx, idx);
  return idx;
}

function bcTypeOf(t: Type, ctx: EmitterCtx, slotIdx: number): BcType {
  switch (t.kind) {
    case "Primitive": return { kind: "primitive", val: primitiveToVal(t.name) };
    case "Enum":      return { kind: "primitive", val: primitiveToVal(t.repr) };
    case "Struct": {
      // Pass 1 keys interned structs by displayType — same key we'd use here.
      // If it's not present, this is an opaque struct (foreign module / no body).
      return { kind: "ref", traitName: t.symbol.name };
    }
    case "Trait": return { kind: "ref", traitName: t.symbol.name };
    case "Array": return { kind: "array", element: internType(ctx, t.element) };
    case "Tuple": {
      // Synthesise an anonymous struct with fields `_0`, `_1`, ... in element
      // order. The C-emit treats it like any other struct ; the GC scan walks
      // ref-typed slots via the per-type pointer map. The mangled name uses
      // the slot index so two distinct tuple shapes never share a C struct
      // (`[i32, string]` and `[bool, string]` both have arity 2 but emit
      // different `__Tuple_<idx>` types).
      const fields = t.elements.map((e, i) => ({
        name: `_${i}`,
        typeIndex: internType(ctx, e),
      }));
      return { kind: "struct", name: `__Tuple_${slotIdx}`, fields };
    }
    case "Union": return { kind: "union", variants: t.variants.map((v) => internType(ctx, v)) };
    case "Fn":    return {
      kind: "fn",
      params: t.params.map((p) => internType(ctx, p)),
      returnType: internType(ctx, t.returnType),
    };
    default:      return { kind: "ref", traitName: null };
  }
}

/** Synthesise (or look up) a single-slot struct type used by closure cells.
 *  Each cell holds a slot of `slotType`, so we materialise one struct per
 *  distinct slot type — kept distinct from user structs by the `$Cell_…`
 *  name prefix. The C emit treats it like any other struct (it gets a
 *  type-info entry, the GC scans the slot if it's a ref). */
export function internCellType(ctx: EmitterCtx, slotType: Type): number {
  const slotIdx = internType(ctx, slotType);
  const key = `$Cell<${displayType(slotType)}>`;
  const cached = ctx.typeKey.get(key);
  if (cached !== undefined) return cached;
  const idx = ctx.types.length;
  ctx.typeKey.set(key, idx);
  ctx.types.push({
    kind: "struct",
    name: `$Cell_${idx}`,
    fields: [{ name: "value", typeIndex: slotIdx }],
  });
  return idx;
}

function internStructDecl(d: L.LoweredStructDecl, ctx: EmitterCtx): number {
  // Key by the same displayType form `internType` uses for Struct types so a
  // generic instantiation `List(i32)` doesn't collide with `List(i64)`.
  if (d.origin.symbol === null) return -1;
  const structType: Type = { kind: "Struct", symbol: d.origin.symbol, args: d.origin.typeArgs };
  const key = displayType(structType);
  const cached = ctx.typeKey.get(key);
  if (cached !== undefined && ctx.types[cached]?.kind === "struct") return cached;

  const idx = ctx.types.length;
  ctx.typeKey.set(key, idx);
  // Reserve before recursing into field types so self-referential structs
  // (linked-list nodes etc.) terminate.
  ctx.types.push({ kind: "ref", traitName: d.mangled });

  const fields = d.fields.map((f) => ({
    name: f.name, typeIndex: internType(ctx, f.type),
  }));
  ctx.types[idx] = { kind: "struct", name: d.mangled, fields };

  const traits = ctx.traitsBySymbolId.get(d.origin.symbol.id);
  if (traits !== undefined && traits.length > 0) ctx.implTable.set(idx, traits);

  return idx;
}

function primitiveToVal(name: PrimitiveName): ValType {
  // PrimitiveName ⊂ ValType: every primitive is also a stack-machine value type.
  return name;
}

export function internString(ctx: EmitterCtx, s: string): number {
  const cached = ctx.stringKey.get(s);
  if (cached !== undefined) return cached;
  const idx = ctx.strings.length;
  ctx.strings.push(s);
  ctx.stringKey.set(s, idx);
  return idx;
}

// ----------------------------------------------------------- Type → ValType

export function valTypeOf(t: Type): ValType {
  switch (t.kind) {
    case "Primitive": return primitiveToVal(t.name);
    case "Never":     return "void";
    case "FreeInt":   return "i32";
    case "FreeFloat": return "f64";
    case "Unresolved": return "any";
    case "Union":     return "ref";
    case "Enum":    return primitiveToVal(t.repr);
    case "Struct":
    case "Trait":
    case "Array":
    case "Tuple":
    case "Fn":
    case "TypeParam":
    case "TypeMeta":
    case "Self":
      return "ref";
  }
}

/** Coerce to a numeric ValType, defaulting to i32 when the input isn't typed
 *  numerically (e.g. `Unresolved` after recovered errors). Lets the emitter
 *  produce a balanced op stream even when typecheck didn't fully resolve. */
export function asNumeric(t: ValType): ValType {
  return isNumericVal(t) ? t : "i32";
}

export function asInt(t: ValType): ValType {
  return isIntegerVal(t) ? t : "i32";
}

/** Pick the bytecode op for a `LoweredBinaryOp` over operands of `lhsVal`.
 *  Excludes `and` / `or` (those need short-circuit control flow, not a single
 *  op). Shared between the legacy LoweredAST → bytecode emit and the CFG
 *  emit ; the converter lowers `and`/`or` into if/else explicitly so this fn
 *  never sees them. */
export function binaryOpFor(op: L.LoweredBinaryOp, lhsVal: ValType): Op {
  switch (op) {
    case "add": case "sub": case "mul": case "div":
      if (op === "add" && lhsVal === "string") return { kind: "string.concat" };
      return { kind: `${asNumeric(lhsVal)}.${op}` as ArithOpKind };
    case "mod":    return { kind: `${asNumeric(lhsVal)}.rem` as ArithOpKind };
    case "shl":
    case "shr":    return { kind: `${asInt(lhsVal)}.${op}` as BitOpKind };
    case "bitand":
    case "bitor":
    case "bitxor": return { kind: `${asInt(lhsVal)}.${op}` as BitOpKind };
    case "and":    return { kind: "bool.and" };
    case "or":     return { kind: "bool.or" };
    case "eq":     return { kind: cmpKind(lhsVal, "eq") };
    case "neq":    return { kind: cmpKind(lhsVal, "ne") };
    case "lt":     return { kind: cmpKind(lhsVal, "lt") };
    case "lte":    return { kind: cmpKind(lhsVal, "le") };
    case "gt":     return { kind: cmpKind(lhsVal, "gt") };
    case "gte":    return { kind: cmpKind(lhsVal, "ge") };
  }
}

export function cmpKind(lt: ValType, op: "eq" | "ne" | "lt" | "le" | "gt" | "ge"): CmpOpKind {
  if (isNumericVal(lt)) return `${lt}.${op}` as CmpOpKind;
  if (op === "eq" || op === "ne") {
    if (lt === "bool")   return `bool.${op}`;
    if (lt === "string") return `string.${op}`;
    if (lt === "char")   return `char.${op}`;
    return `ref.${op}`;       // ref / any / null / void
  }
  if (lt === "char")   return `char.${op}` as CmpOpKind;
  return `${asNumeric(lt)}.${op}` as CmpOpKind;
}

export function emitIntConst(fn: FnEmitCtx, value: bigint, t: ValType, span: Span): void {
  if (t === "i64" || t === "u64" || t === "usize") {
    pushOp(fn, { kind: "i64.const", value }, span);
  } else {
    pushOp(fn, { kind: "i32.const", value: Number(value) }, span);
  }
}

export function emitFloatConst(fn: FnEmitCtx, value: number, t: ValType, span: Span): void {
  pushOp(fn, { kind: t === "f32" ? "f32.const" : "f64.const", value }, span);
}

function signatureOf(d: L.LoweredFnDecl): BcSignature {
  return {
    params: d.params.map((p) => valTypeOf(p.type)),
    result: valTypeOf(d.returnType),
  };
}

