// Bytecode emitter — LoweredProject → BytecodeModule. See SPEC §2 ("Lowered
// AST" → bytecode) and §17 (canonical IR).

import type { Span } from "../diagnostics/diagnostic.ts";
import { DEC, hasDecorator } from "../parser/decorators.ts";
import type * as L from "../lower/lowered-ast.ts";
import type { LoweredProject } from "../lower/index.ts";
import type { PrimitiveName, Type } from "../typecheck/types.ts";
import { displayType } from "../typecheck/types.ts";

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

/** Knobs for the bytecode emitter. Today this only toggles the peephole
 *  pass; future codegen-time options (e.g. inline-thresholds, bound checks)
 *  belong here. */
export interface EmitOptions {
  /** Run peephole optimisations on every function body. Default: `true`. */
  readonly optimize?: boolean;
}

export function emitBytecode(
  project: LoweredProject, name: string, options: EmitOptions = {},
): BytecodeModule {
  const ctx = newEmitterCtx(options.optimize ?? true);
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
  };
}

interface EmitterCtx {
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

function newEmitterCtx(optimize: boolean): EmitterCtx {
  return {
    types: [], typeKey: new Map(),
    strings: [], stringKey: new Map(),
    functions: [], fnIndexBySymId: new Map(),
    imports: [], importIndexBySymId: new Map(),
    exports: [],
    constDecls: new Map(),
    optimize,
  };
}

// ----------------------------------------------------------- pass 1: reserve

function reserveDecl(d: L.LoweredDecl, ctx: EmitterCtx): void {
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

interface FnEmitCtx {
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

function pushOp(fn: FnEmitCtx, op: Op, span?: Span): void {
  fn.body.push(op);
  fn.debug.push(span === undefined ? null : {
    file: span.start.file, line: span.start.line, column: span.start.column,
  });
}

function declareLocal(fn: FnEmitCtx, name: string, val: ValType): number {
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
    case "LoweredFieldAccess":   emitFieldAccess(fn, e); return;
    case "LoweredIndex": {
      const typeIndex = internType(fn.project, e.target.type);
      emitExpr(fn, e.target);
      emitExpr(fn, e.index);
      pushOp(fn, { kind: "array.get", typeIndex }, e.span);
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
  pushOp(fn, { kind: "unreachable" }, e.span);
}

function emitCall(fn: FnEmitCtx, e: L.LoweredCall): void {
  if (e.callee.kind === "LoweredIdent") {
    const sym = e.callee.symbol;
    const fnIdx = fn.project.fnIndexBySymId.get(sym.id);
    if (fnIdx !== undefined) {
      for (const a of e.args) emitExpr(fn, a);
      pushOp(fn, { kind: "call", fnIndex: fnIdx }, e.span);
      return;
    }
    const importIdx = fn.project.importIndexBySymId.get(sym.id);
    if (importIdx !== undefined) {
      for (const a of e.args) emitExpr(fn, a);
      pushOp(fn, { kind: "call.import", importIndex: importIdx }, e.span);
      return;
    }
  }
  // Indirect / unresolved callee — surface as unreachable for MVP.
  for (const a of e.args) emitExpr(fn, a);
  pushOp(fn, { kind: "unreachable" }, e.span);
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
  const lt = valTypeOf(e.left.type);
  switch (e.op) {
    case "add": case "sub": case "mul": case "div":
      if (lt === "string") { pushOp(fn, { kind: "string.concat" }, e.span); return; }
      pushOp(fn, { kind: `${asNumeric(lt)}.${e.op}` as ArithOpKind }, e.span);
      return;
    case "mod":
      pushOp(fn, { kind: `${asNumeric(lt)}.rem` as ArithOpKind }, e.span);
      return;
    case "shl": case "shr":
    case "bitand": case "bitor": case "bitxor":
      pushOp(fn, { kind: `${asInt(lt)}.${e.op}` as BitOpKind }, e.span);
      return;
    case "eq": case "neq": case "lt": case "lte": case "gt": case "gte":
      pushOp(fn, { kind: cmpKind(lt, normaliseCmp(e.op)) }, e.span);
      return;
  }
}

function normaliseCmp(op: "eq" | "neq" | "lt" | "lte" | "gt" | "gte"): "eq" | "ne" | "lt" | "le" | "gt" | "ge" {
  return op === "neq" ? "ne" : op === "lte" ? "le" : op === "gte" ? "ge" : op;
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
  pushOp(fn, { kind: `${asNumeric(fromType)}.to_${asNumeric(toType)}` as ConvertOpKind }, e.span);
}

// ----------------------------------------------------------- interning

function internType(ctx: EmitterCtx, t: Type): number {
  const key = displayType(t);
  const cached = ctx.typeKey.get(key);
  if (cached !== undefined) return cached;
  // Reserve placeholder so recursive/self types don't loop.
  const idx = ctx.types.length;
  ctx.types.push({ kind: "ref", traitName: null });
  ctx.typeKey.set(key, idx);
  ctx.types[idx] = bcTypeOf(t, ctx);
  return idx;
}

function bcTypeOf(t: Type, ctx: EmitterCtx): BcType {
  switch (t.kind) {
    case "Primitive": return { kind: "primitive", val: primitiveToVal(t.name) };
    case "Struct": {
      // Pass 1 keys interned structs by displayType — same key we'd use here.
      // If it's not present, this is an opaque struct (foreign module / no body).
      return { kind: "ref", traitName: t.symbol.name };
    }
    case "Trait": return { kind: "ref", traitName: t.symbol.name };
    case "Array": return { kind: "array", element: internType(ctx, t.element) };
    case "Union": return { kind: "union", variants: t.variants.map((v) => internType(ctx, v)) };
    default:      return { kind: "ref", traitName: null };
  }
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
  return idx;
}

function primitiveToVal(name: PrimitiveName): ValType {
  // PrimitiveName ⊂ ValType: every primitive is also a stack-machine value type.
  return name;
}

function internString(ctx: EmitterCtx, s: string): number {
  const cached = ctx.stringKey.get(s);
  if (cached !== undefined) return cached;
  const idx = ctx.strings.length;
  ctx.strings.push(s);
  ctx.stringKey.set(s, idx);
  return idx;
}

// ----------------------------------------------------------- Type → ValType

function valTypeOf(t: Type): ValType {
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
function asNumeric(t: ValType): ValType {
  return isNumericVal(t) ? t : "i32";
}

function asInt(t: ValType): ValType {
  return isIntegerVal(t) ? t : "i32";
}

function cmpKind(lt: ValType, op: "eq" | "ne" | "lt" | "le" | "gt" | "ge"): CmpOpKind {
  if (isNumericVal(lt)) return `${lt}.${op}` as CmpOpKind;
  if (op === "eq" || op === "ne") {
    if (lt === "bool")   return `bool.${op}`;
    if (lt === "string") return `string.${op}`;
    if (lt === "char")   return `char.${op}`;
    return `ref.${op}`;       // ref / any / null / void
  }
  return `${asNumeric(lt)}.${op}` as CmpOpKind;
}

function emitIntConst(fn: FnEmitCtx, value: bigint, t: ValType, span: Span): void {
  if (t === "i64" || t === "u64" || t === "usize") {
    pushOp(fn, { kind: "i64.const", value }, span);
  } else {
    pushOp(fn, { kind: "i32.const", value: Number(value) }, span);
  }
}

function emitFloatConst(fn: FnEmitCtx, value: number, t: ValType, span: Span): void {
  pushOp(fn, { kind: t === "f32" ? "f32.const" : "f64.const", value }, span);
}

function signatureOf(d: L.LoweredFnDecl): BcSignature {
  return {
    params: d.params.map((p) => valTypeOf(p.type)),
    result: valTypeOf(d.returnType),
  };
}

