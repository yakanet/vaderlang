// Typed-AST → BytecodeModule for one `@comptime` decl, per the §1.5b
// migration plan. Produces a self-contained module with a synthetic
// `__comptime_main` entry; user fns reachable from the decl body are lazily
// compiled into the same module. Builtins (`@file`/`@env`) surface as
// imports, resolved by the host bindings to the existing sandbox path.
//
// Scope mirrors the AST-walking interpreter that this replaces — pure
// expressions, blocks, if/else, fn calls, string interpolation, struct/array
// literals, field/index. Match/try/defer/for stay out of the comptime subset
// for MVP and surface as `C4011`.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type * as A from "../parser/ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
import type { Type } from "../typecheck/types.ts";
import { displayType, TY } from "../typecheck/types.ts";

import type { BytecodeModule, BcFunction, BcImport, BcLocal, BcSignature } from "../bytecode/module.ts";
import type { BcType, ValType } from "../bytecode/types.ts";
import type { Op } from "../bytecode/ops.ts";
import { INTRINSIC_TABLE } from "../bytecode/ops.ts";

import { err } from "./diag.ts";
import type { ComptimeValue } from "./value.ts";

export const COMPTIME_IMPORT = {
  file: "comptime$file",
  env:  "comptime$env",
} as const;

export interface CompileInput {
  readonly decl: A.ConstDecl;
  readonly project: TypedProject;
  readonly callerProgram: TypedProgram;
  readonly evaluated: ReadonlyMap<A.ConstDecl, ComptimeValue>;
  readonly diags: DiagnosticCollector;
}

export interface CompileOutput {
  readonly module: BytecodeModule;
  readonly mainFnIndex: number;
  readonly resultType: Type;
  /** Map from `${fnIndex}:${opIndex}` → Span, used to attach precise spans to
   *  runtime traps thrown by the VM (division by zero, index OOB, …). */
  readonly spanByOp: ReadonlyMap<string, Span>;
}

class CompileAbort extends Error {
  constructor() { super("comptime compile aborted"); }
}

interface FnCompileCtx {
  readonly fn: A.FnDecl;
  readonly program: TypedProgram;
  readonly fnIndex: number;
  readonly slotBySymbolId: Map<number, number>;
  readonly locals: BcLocal[];
  readonly body: Op[];
  readonly debug: ({ readonly file: string; readonly line: number; readonly column: number } | null)[];
}

class Compiler {
  private readonly types: BcType[] = [];
  private readonly typeKey = new Map<string, number>();
  private readonly strings: string[] = [];
  private readonly stringKey = new Map<string, number>();
  private readonly functions: BcFunction[] = [];
  private readonly fnIndexBySymId = new Map<number, number>();
  private readonly fnProgramByIndex = new Map<number, TypedProgram>();
  private readonly imports: BcImport[] = [];
  private readonly importIndexByName = new Map<string, number>();
  private readonly spanByOp = new Map<string, Span>();
  private readonly compiledFns = new Set<number>();    // by symbol id

  constructor(private readonly input: CompileInput) {}

  compile(): CompileOutput | null {
    try {
      const decl = this.input.decl;
      const callerProgram = this.input.callerProgram;
      const resultType = callerProgram.exprTypes.get(decl.value)
        ?? callerProgram.declTypes.get(decl)
        ?? TY.unresolved;
      const mainFnIndex = this.compileSyntheticMain(decl, resultType);
      return {
        module: {
          name: "__comptime__",
          types: this.types,
          strings: this.strings,
          functions: this.functions,
          imports: this.imports,
          exports: [],
          implTable: new Map(),
        },
        mainFnIndex,
        resultType,
        spanByOp: this.spanByOp,
      };
    } catch (e) {
      if (e instanceof CompileAbort) return null;
      throw e;
    }
  }

  // ----------------------------------------------------------- top-level

  private compileSyntheticMain(decl: A.ConstDecl, resultType: Type): number {
    const fnIndex = this.functions.length;
    const fnCtx: FnCompileCtx = {
      fn: this.syntheticFnHeader(decl, resultType),
      program: this.input.callerProgram,
      fnIndex,
      slotBySymbolId: new Map(),
      locals: [],
      body: [],
      debug: [],
    };
    this.functions.push({
      name: "__comptime_main",
      signature: { params: [], result: this.valTypeOf(resultType) },
      locals: fnCtx.locals,
      body: fnCtx.body,
      debug: fnCtx.debug,
    });

    this.emitExpr(fnCtx, decl.value);
    this.pushOp(fnCtx, { kind: "return" }, decl.value.span);
    return fnIndex;
  }

  /** Build a stub A.FnDecl just to satisfy the FnCompileCtx shape — we never
   *  read its `body`/`params` because the compile loop dispatches on the AST
   *  expression directly. */
  private syntheticFnHeader(decl: A.ConstDecl, _resultType: Type): A.FnDecl {
    return {
      kind: "FnDecl", span: decl.span, name: "__comptime_main",
      nameSpan: decl.span, visibility: "public",
      typeParams: [], params: [], returnType: null, whereClauses: [],
      body: null, decorators: [],
    };
  }

  // ----------------------------------------------------------- user fn lazy compile

  private ensureUserFnCompiled(sym: Symbol, callSite: Span): number {
    const existing = this.fnIndexBySymId.get(sym.id);
    if (existing !== undefined) return existing;

    if (sym.source.kind !== "fn") this.abort(callSite, `cannot compile call target \`${sym.name}\``);
    const fnDecl = sym.source.decl;
    if (fnDecl.body === null) this.abort(callSite, `cannot call extern fn \`${sym.name}\` at comptime`);
    const program = this.input.project.modules.get(sym.module);
    if (program === undefined) this.abort(callSite, `module for \`${sym.name}\` not found`);

    const fnIndex = this.functions.length;
    this.fnIndexBySymId.set(sym.id, fnIndex);
    this.fnProgramByIndex.set(fnIndex, program);

    const sig = this.signatureOf(fnDecl, program);
    const fnCtx: FnCompileCtx = {
      fn: fnDecl, program, fnIndex,
      slotBySymbolId: new Map(),
      locals: [],
      body: [],
      debug: [],
    };
    // Reserve params as the first N slots before any locals.
    for (let i = 0; i < fnDecl.params.length; i++) {
      const paramSym = program.resolved.params.get(fnDecl.params[i]!);
      if (paramSym !== undefined) fnCtx.slotBySymbolId.set(paramSym.id, i);
    }
    this.functions.push({
      name: this.mangle(sym, program),
      signature: sig,
      locals: fnCtx.locals,
      body: fnCtx.body,
      debug: fnCtx.debug,
    });

    this.compiledFns.add(sym.id);
    this.emitBlock(fnCtx, fnDecl.body!);
    if (sig.result !== "void" && (fnCtx.body.length === 0 || fnCtx.body[fnCtx.body.length - 1]!.kind !== "return")) {
      this.pushOp(fnCtx, { kind: "return" }, fnDecl.body!.span);
    }
    return fnIndex;
  }

  // ----------------------------------------------------------- builtins / imports

  private importIndexFor(name: typeof COMPTIME_IMPORT[keyof typeof COMPTIME_IMPORT], sig: BcSignature): number {
    const cached = this.importIndexByName.get(name);
    if (cached !== undefined) return cached;
    const idx = this.imports.length;
    this.importIndexByName.set(name, idx);
    this.imports.push({ externName: name, mangledName: name, signature: sig });
    return idx;
  }

  // ----------------------------------------------------------- statements

  private emitBlock(ctx: FnCompileCtx, block: A.BlockExpr): void {
    for (const stmt of block.stmts) this.emitStmt(ctx, stmt);
    if (block.trailing !== null) this.emitExpr(ctx, block.trailing);
  }

  private emitStmt(ctx: FnCompileCtx, stmt: A.Stmt): void {
    switch (stmt.kind) {
      case "LetStmt": {
        this.emitExpr(ctx, stmt.value);
        const sym = ctx.program.resolved.locals.get(stmt);
        const valTy = this.valTypeOf(ctx.program.localTypes.get(stmt) ?? TY.unresolved);
        const slot = ctx.fn.params.length + ctx.locals.length;
        ctx.locals.push({ name: stmt.name, val: valTy });
        if (sym !== undefined) ctx.slotBySymbolId.set(sym.id, slot);
        this.pushOp(ctx, { kind: "local.set", slot }, stmt.span);
        return;
      }
      case "ExprStmt": {
        this.emitExpr(ctx, stmt.expr);
        const ty = ctx.program.exprTypes.get(stmt.expr);
        if (ty !== undefined && this.valTypeOf(ty) !== "void") {
          this.pushOp(ctx, { kind: "drop" }, stmt.span);
        }
        return;
      }
      case "ReturnStmt":
        if (stmt.value !== null) this.emitExpr(ctx, stmt.value);
        this.pushOp(ctx, { kind: "return" }, stmt.span);
        return;
      case "AssignStmt":
      case "ForStmt":
      case "BreakStmt":
      case "ContinueStmt":
      case "DeferStmt":
        this.abort(stmt.span, `${stmt.kind} not supported in comptime`);
    }
  }

  // ----------------------------------------------------------- expressions

  private emitExpr(ctx: FnCompileCtx, expr: A.Expr): void {
    switch (expr.kind) {
      case "IntLitExpr":   return this.emitIntLit(ctx, expr);
      case "FloatLitExpr": return this.emitFloatLit(ctx, expr);
      case "BoolLitExpr":  return this.pushOp(ctx, { kind: "bool.const", value: expr.value }, expr.span);
      case "NullLitExpr":  return this.pushOp(ctx, { kind: "null.const" }, expr.span);
      case "CharLitExpr":  return this.pushOp(ctx, { kind: "char.const", value: expr.value }, expr.span);
      case "StringLitExpr": return this.emitStringLit(ctx, expr);
      case "IdentExpr":    return this.emitIdent(ctx, expr);
      case "CallExpr":     return this.emitCall(ctx, expr);
      case "BlockExpr":    return this.emitBlock(ctx, expr);
      case "IfExpr":       return this.emitIf(ctx, expr);
      case "UnaryExpr":    return this.emitUnary(ctx, expr);
      case "BinaryExpr":   return this.emitBinary(ctx, expr);
      case "FieldExpr":    return this.emitField(ctx, expr);
      case "IndexExpr":    return this.emitIndex(ctx, expr);
      case "StructLitExpr":return this.emitStructLit(ctx, expr);
      case "ArrayLitExpr": return this.emitArrayLit(ctx, expr);
      default:
        this.abort(expr.span, `${expr.kind} not supported in comptime MVP`);
    }
  }

  private emitIntLit(ctx: FnCompileCtx, expr: A.IntLitExpr): void {
    const ty = ctx.program.exprTypes.get(expr);
    const valTy = this.valTypeOf(ty ?? TY.unresolved);
    if (valTy === "i64" || valTy === "u64") {
      this.pushOp(ctx, { kind: "i64.const", value: expr.value }, expr.span);
    } else {
      this.pushOp(ctx, { kind: "i32.const", value: Number(expr.value) }, expr.span);
    }
  }

  private emitFloatLit(ctx: FnCompileCtx, expr: A.FloatLitExpr): void {
    const ty = ctx.program.exprTypes.get(expr);
    const valTy = this.valTypeOf(ty ?? TY.unresolved);
    this.pushOp(ctx, { kind: valTy === "f32" ? "f32.const" : "f64.const", value: expr.value }, expr.span);
  }

  private emitStringLit(ctx: FnCompileCtx, expr: A.StringLitExpr): void {
    if (expr.parts.length === 1 && expr.parts[0]!.kind === "text") {
      const idx = this.internString(expr.parts[0]!.value);
      this.pushOp(ctx, { kind: "string.const", index: idx }, expr.span);
      return;
    }
    // Interpolation → builder intrinsics, mirroring the runtime lowerer.
    const builderSlot = ctx.fn.params.length + ctx.locals.length;
    ctx.locals.push({ name: `__sb_${builderSlot}`, val: "any" });
    this.pushOp(ctx, { kind: "intrinsic", id: INTRINSIC_TABLE.builderNew.id }, expr.span);
    this.pushOp(ctx, { kind: "local.set", slot: builderSlot }, expr.span);
    for (const part of expr.parts) {
      this.pushOp(ctx, { kind: "local.get", slot: builderSlot }, part.span);
      if (part.kind === "text") {
        const idx = this.internString(part.value);
        this.pushOp(ctx, { kind: "string.const", index: idx }, part.span);
        this.pushOp(ctx, { kind: "intrinsic", id: INTRINSIC_TABLE.builderAppendStr.id }, part.span);
      } else {
        this.emitExpr(ctx, part.expr);
        this.pushOp(ctx, { kind: "intrinsic", id: INTRINSIC_TABLE.builderAppendDisplay.id }, part.span);
      }
    }
    this.pushOp(ctx, { kind: "local.get", slot: builderSlot }, expr.span);
    this.pushOp(ctx, { kind: "intrinsic", id: INTRINSIC_TABLE.builderFinish.id }, expr.span);
  }

  private emitIdent(ctx: FnCompileCtx, expr: A.IdentExpr): void {
    const sym = ctx.program.resolved.idents.get(expr);
    if (sym === undefined) this.abort(expr.span, `unresolved ident \`${expr.name}\``);

    const slot = ctx.slotBySymbolId.get(sym.id);
    if (slot !== undefined) {
      this.pushOp(ctx, { kind: "local.get", slot }, expr.span);
      return;
    }

    if (sym.kind === "const" && sym.source.kind === "const") {
      const constDecl = sym.source.decl;
      const baked = this.input.evaluated.get(constDecl);
      if (baked !== undefined) { this.emitConstantValue(ctx, baked, expr.span); return; }
      // Cross-decl reference to a const we don't have a value for. Either
      // (a) it's involved in a cycle and was filtered out, or (b) it's a
      // non-`@comptime`-decorated const that depends on runtime state. In
      // both cases we can fall back to inlining the RHS only when it's a
      // direct literal; anything richer is genuinely undecidable here.
      const literal = isStaticLiteral(constDecl.value);
      if (literal) { this.emitExpr(ctx, constDecl.value); return; }
      this.abort(expr.span, `const \`${expr.name}\` not bound at comptime (cycle or unevaluable RHS)`);
    }

    this.abort(expr.span, `ident \`${expr.name}\` (${sym.kind}) not bindable at comptime`);
  }

  private emitConstantValue(ctx: FnCompileCtx, v: ComptimeValue, span: Span): void {
    switch (v.kind) {
      case "int":
        if (v.typeName === "i64" || v.typeName === "u64") {
          this.pushOp(ctx, { kind: "i64.const", value: v.value }, span);
        } else {
          this.pushOp(ctx, { kind: "i32.const", value: Number(v.value) }, span);
        }
        return;
      case "float":
        this.pushOp(ctx, { kind: v.typeName === "f32" ? "f32.const" : "f64.const", value: v.value }, span);
        return;
      case "bool":   this.pushOp(ctx, { kind: "bool.const", value: v.value }, span); return;
      case "char":   this.pushOp(ctx, { kind: "char.const", value: v.value }, span); return;
      case "null":   this.pushOp(ctx, { kind: "null.const" }, span); return;
      case "string": {
        const idx = this.internString(v.value);
        this.pushOp(ctx, { kind: "string.const", index: idx }, span);
        return;
      }
      case "void":
      case "array":
      case "struct":
        this.abort(span, `cannot inline a ${v.kind} comptime constant yet`);
    }
  }

  private emitCall(ctx: FnCompileCtx, expr: A.CallExpr): void {
    const sym = expr.callee.kind === "IdentExpr" ? ctx.program.resolved.idents.get(expr.callee) : undefined;
    if (sym === undefined) this.abort(expr.span, "indirect calls not supported in comptime");

    if (sym.kind === "builtin-fn" && sym.source.kind === "builtin-fn") {
      this.emitBuiltinCall(ctx, expr, sym.source.fnName);
      return;
    }

    if (sym.kind !== "fn") this.abort(expr.span, `call target \`${sym.name}\` (${sym.kind}) not supported`);

    const fnIdx = this.ensureUserFnCompiled(sym, expr.span);
    for (const a of expr.args) this.emitExpr(ctx, a.value);
    this.pushOp(ctx, { kind: "call", fnIndex: fnIdx }, expr.span);
  }

  private emitBuiltinCall(ctx: FnCompileCtx, expr: A.CallExpr, fnName: string): void {
    if (fnName !== "@file" && fnName !== "@env") {
      this.abort(expr.span, `unknown comptime builtin \`${fnName}\``);
    }
    const sig: BcSignature = { params: ["string"], result: "string" };
    const importIdx = this.importIndexFor(
      fnName === "@file" ? COMPTIME_IMPORT.file : COMPTIME_IMPORT.env,
      sig,
    );
    for (const a of expr.args) this.emitExpr(ctx, a.value);
    this.pushOp(ctx, { kind: "call.import", importIndex: importIdx }, expr.span);
  }

  private emitIf(ctx: FnCompileCtx, expr: A.IfExpr): void {
    this.emitExpr(ctx, expr.cond);
    const ty = ctx.program.exprTypes.get(expr) ?? TY.unresolved;
    const result = this.valTypeOf(ty);
    this.pushOp(ctx, { kind: "if", result }, expr.span);
    this.emitBlock(ctx, expr.then);
    this.pushOp(ctx, { kind: "else" }, expr.span);
    if (expr.else === null) {
      if (result !== "void") this.pushOp(ctx, { kind: "unreachable" }, expr.span);
    } else if (expr.else.kind === "IfExpr") {
      this.emitIf(ctx, expr.else);
    } else {
      this.emitBlock(ctx, expr.else);
    }
    this.pushOp(ctx, { kind: "end" }, expr.span);
  }

  private emitUnary(ctx: FnCompileCtx, expr: A.UnaryExpr): void {
    this.emitExpr(ctx, expr.operand);
    const ty = ctx.program.exprTypes.get(expr) ?? TY.unresolved;
    const t = this.valTypeOf(ty);
    switch (expr.op) {
      case "neg":    this.pushOp(ctx, { kind: `${asNumeric(t)}.neg`    as Op["kind"] } as Op, expr.span); return;
      case "not":    this.pushOp(ctx, { kind: "bool.not" }, expr.span); return;
      case "bitnot": this.pushOp(ctx, { kind: `${asInt(t)}.bitnot`     as Op["kind"] } as Op, expr.span); return;
    }
  }

  private emitBinary(ctx: FnCompileCtx, expr: A.BinaryExpr): void {
    if (expr.op === "and" || expr.op === "or") return this.emitShortCircuit(ctx, expr);
    const lt = this.valTypeOf(ctx.program.exprTypes.get(expr.left) ?? TY.unresolved);
    if (expr.op === "add" && lt === "string") return this.emitStringConcat(ctx, expr);
    this.emitExpr(ctx, expr.left);
    this.emitExpr(ctx, expr.right);
    switch (expr.op) {
      case "add": case "sub": case "mul": case "div":
        this.pushOp(ctx, { kind: `${asNumeric(lt)}.${expr.op}` as Op["kind"] } as Op, expr.span);
        return;
      case "mod":
        this.pushOp(ctx, { kind: `${asNumeric(lt)}.rem` as Op["kind"] } as Op, expr.span);
        return;
      case "shl": case "shr":
      case "bitand": case "bitor": case "bitxor":
        this.pushOp(ctx, { kind: `${asInt(lt)}.${expr.op}` as Op["kind"] } as Op, expr.span);
        return;
      case "eq": case "neq": case "lt": case "lte": case "gt": case "gte":
        this.pushOp(ctx, { kind: cmpKind(lt, normaliseCmp(expr.op)) as Op["kind"] } as Op, expr.span);
        return;
      case "is":
        this.abort(expr.span, "`is` not supported as binop at comptime");
    }
  }

  private emitStringConcat(ctx: FnCompileCtx, expr: A.BinaryExpr): void {
    const slot = ctx.fn.params.length + ctx.locals.length;
    ctx.locals.push({ name: `__sb_${slot}`, val: "any" });
    this.pushOp(ctx, { kind: "intrinsic", id: INTRINSIC_TABLE.builderNew.id }, expr.span);
    this.pushOp(ctx, { kind: "local.set", slot }, expr.span);
    for (const operand of [expr.left, expr.right]) {
      this.pushOp(ctx, { kind: "local.get", slot }, operand.span);
      this.emitExpr(ctx, operand);
      this.pushOp(ctx, { kind: "intrinsic", id: INTRINSIC_TABLE.builderAppendStr.id }, operand.span);
    }
    this.pushOp(ctx, { kind: "local.get", slot }, expr.span);
    this.pushOp(ctx, { kind: "intrinsic", id: INTRINSIC_TABLE.builderFinish.id }, expr.span);
  }

  private emitShortCircuit(ctx: FnCompileCtx, expr: A.BinaryExpr): void {
    this.emitExpr(ctx, expr.left);
    this.pushOp(ctx, { kind: "if", result: "bool" }, expr.span);
    if (expr.op === "and") {
      this.emitExpr(ctx, expr.right);
      this.pushOp(ctx, { kind: "else" }, expr.span);
      this.pushOp(ctx, { kind: "bool.const", value: false }, expr.span);
    } else {
      this.pushOp(ctx, { kind: "bool.const", value: true }, expr.span);
      this.pushOp(ctx, { kind: "else" }, expr.span);
      this.emitExpr(ctx, expr.right);
    }
    this.pushOp(ctx, { kind: "end" }, expr.span);
  }

  private emitField(ctx: FnCompileCtx, expr: A.FieldExpr): void {
    const ty = ctx.program.exprTypes.get(expr.target) ?? TY.unresolved;
    const typeIndex = this.internType(ty);
    const struct = this.types[typeIndex];
    if (struct?.kind !== "struct") this.abort(expr.span, `field access on non-struct ${displayType(ty)}`);
    const fieldIndex = struct.fields.findIndex((f) => f.name === expr.field);
    if (fieldIndex < 0) this.abort(expr.fieldSpan, `no field \`${expr.field}\``);
    this.emitExpr(ctx, expr.target);
    this.pushOp(ctx, { kind: "struct.get", typeIndex, fieldIndex }, expr.span);
  }

  private emitIndex(ctx: FnCompileCtx, expr: A.IndexExpr): void {
    const ty = ctx.program.exprTypes.get(expr.target) ?? TY.unresolved;
    const typeIndex = this.internType(ty);
    this.emitExpr(ctx, expr.target);
    this.emitExpr(ctx, expr.index);
    this.pushOp(ctx, { kind: "array.get", typeIndex }, expr.span);
  }

  private emitStructLit(ctx: FnCompileCtx, expr: A.StructLitExpr): void {
    const ty = ctx.program.exprTypes.get(expr) ?? TY.unresolved;
    const typeIndex = this.internType(ty);
    const struct = this.types[typeIndex];
    if (struct?.kind !== "struct") this.abort(expr.span, `struct lit for non-struct ${displayType(ty)}`);
    for (const f of struct.fields) {
      const lit = expr.fields.find((lf) => lf.name === f.name);
      if (lit !== undefined) this.emitExpr(ctx, lit.value);
      else this.pushOp(ctx, { kind: "null.const" }, expr.span);
    }
    this.pushOp(ctx, { kind: "struct.new", typeIndex }, expr.span);
  }

  private emitArrayLit(ctx: FnCompileCtx, expr: A.ArrayLitExpr): void {
    const ty = ctx.program.exprTypes.get(expr) ?? TY.unresolved;
    const typeIndex = this.internType(ty);
    for (const e of expr.elements) this.emitExpr(ctx, e);
    this.pushOp(ctx, { kind: "array.new", typeIndex, length: expr.elements.length }, expr.span);
  }

  // ----------------------------------------------------------- helpers

  private pushOp(ctx: FnCompileCtx, op: Op, span: Span): void {
    const idx = ctx.body.length;
    ctx.body.push(op);
    ctx.debug.push({ file: span.start.file, line: span.start.line, column: span.start.column });
    this.spanByOp.set(`${ctx.fnIndex}:${idx}`, span);
  }

  private internString(s: string): number {
    const cached = this.stringKey.get(s);
    if (cached !== undefined) return cached;
    const idx = this.strings.length;
    this.strings.push(s);
    this.stringKey.set(s, idx);
    return idx;
  }

  private internType(t: Type): number {
    const key = displayType(t);
    const cached = this.typeKey.get(key);
    if (cached !== undefined) return cached;
    const idx = this.types.length;
    this.types.push({ kind: "ref", traitName: null });    // placeholder
    this.typeKey.set(key, idx);
    this.types[idx] = bcTypeOf(t, this);
    return idx;
  }

  internSubtype(t: Type): number { return this.internType(t); }

  private valTypeOf(t: Type): ValType { return valTypeOf(t); }

  private signatureOf(fn: A.FnDecl, program: TypedProgram): BcSignature {
    const fnType = program.declTypes.get(fn);
    const params = fn.params.map((p) => valTypeOf(program.paramTypes.get(p) ?? TY.unresolved));
    const result = valTypeOf(fnType?.kind === "Fn" ? fnType.returnType : TY.unresolved);
    return { params, result };
  }

  private mangle(sym: Symbol, program: TypedProgram): string {
    const stem = program.resolved.module.displayPath.replace(/[^A-Za-z0-9_]/g, "_");
    return stem === "" || stem === sym.name ? sym.name : `${stem}$${sym.name}`;
  }

  private abort(span: Span, msg: string): never {
    err(this.input.diags, "C4011", span, msg);
    throw new CompileAbort();
  }
}

// ----------------------------------------------------------- type helpers

function valTypeOf(t: Type): ValType {
  switch (t.kind) {
    case "Primitive": return t.name;
    case "Never":     return "void";
    case "FreeInt":   return "i32";
    case "FreeFloat": return "f64";
    case "Unresolved":return "any";
    case "Union":     return "ref";
    case "Enum":    return "i32";
    case "Struct": case "Trait": case "Array": case "Fn":
    case "TypeParam": case "TypeMeta": case "Self":
      return "ref";
  }
}

function bcTypeOf(t: Type, c: Compiler): BcType {
  switch (t.kind) {
    case "Primitive": return { kind: "primitive", val: t.name };
    case "Struct": {
      const fields = sourceStructFields(t);
      return {
        kind: "struct",
        name: t.symbol.name,
        fields: fields.map((f) => ({ name: f.name, typeIndex: c.internSubtype(f.type) })),
      };
    }
    case "Array": return { kind: "array", element: c.internSubtype(t.element) };
    case "Union": return { kind: "union", variants: t.variants.map((v) => c.internSubtype(v)) };
    default:      return { kind: "ref", traitName: null };
  }
}

function sourceStructFields(t: Extract<Type, { kind: "Struct" }>): { name: string; type: Type }[] {
  if (t.symbol.source.kind !== "struct") return [];
  return t.symbol.source.decl.fields.map((f) => ({ name: f.name, type: TY.unresolved }));
}

function isStaticLiteral(e: A.Expr): boolean {
  switch (e.kind) {
    case "IntLitExpr": case "FloatLitExpr": case "BoolLitExpr":
    case "NullLitExpr": case "CharLitExpr":
      return true;
    case "StringLitExpr":
      return e.parts.every((p) => p.kind === "text");
    default:
      return false;
  }
}

function asNumeric(t: ValType): ValType {
  return t === "i8" || t === "i16" || t === "i32" || t === "i64"
      || t === "u8" || t === "u16" || t === "u32" || t === "u64"
      || t === "f32" || t === "f64" ? t : "i32";
}

function asInt(t: ValType): ValType {
  return t === "i8" || t === "i16" || t === "i32" || t === "i64"
      || t === "u8" || t === "u16" || t === "u32" || t === "u64" ? t : "i32";
}

function normaliseCmp(op: "eq" | "neq" | "lt" | "lte" | "gt" | "gte"): "eq" | "ne" | "lt" | "le" | "gt" | "ge" {
  return op === "neq" ? "ne" : op === "lte" ? "le" : op === "gte" ? "ge" : op;
}

function cmpKind(lt: ValType, op: "eq" | "ne" | "lt" | "le" | "gt" | "ge"): string {
  if (lt === "i8" || lt === "i16" || lt === "i32" || lt === "i64"
   || lt === "u8" || lt === "u16" || lt === "u32" || lt === "u64"
   || lt === "f32" || lt === "f64") return `${lt}.${op}`;
  if (op === "eq" || op === "ne") {
    if (lt === "bool")   return `bool.${op}`;
    if (lt === "string") return `string.${op}`;
    if (lt === "char")   return `char.${op}`;
    return `ref.${op}`;
  }
  return `${asNumeric(lt)}.${op}`;
}

// ----------------------------------------------------------- public entry

export function compileComptime(input: CompileInput): CompileOutput | null {
  return new Compiler(input).compile();
}
