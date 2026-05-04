// AST-walking interpreter for the @comptime subset.
//
// MVP scope: pure expressions / control flow / fn calls reaching a fixed-point
// without I/O. Calls to user-defined fns are evaluated by recursing into their
// body. Builtins (@file, @env) go through `sandbox.callBuiltin`.
//
// This will be replaced by the bytecode VM when phase 1.7 lands. Both will
// share `ComptimeValue` so the @comptime pass and the const-pool encoder
// don't need rewriting.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type * as A from "../parser/ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";

import { err } from "./diag.ts";
import { callBuiltin, type SandboxOptions } from "./sandbox.ts";
import {
  type ComptimeValue, FALSE, NULL, TRUE, VOID,
  displayValue, intVal, floatVal, stringVal,
} from "./value.ts";

/** Thrown to unwind a comptime call frame. Caught only at fn boundaries. */
class ReturnSignal { constructor(public readonly value: ComptimeValue) {} }

/** Thrown when evaluation can't continue. The evaluator emits a diagnostic and surrenders. */
class CTAbort { constructor(public readonly handled: boolean = true) {} }

const MAX_CALL_DEPTH = 64;

export interface InterpInput {
  readonly project: TypedProject;
  readonly entry: TypedProgram;
  readonly callerFile: string;
  readonly diags: DiagnosticCollector;
  readonly sandbox: SandboxOptions;
}

interface Frame {
  readonly bindings: Map<Symbol, ComptimeValue>;
  readonly callerSpan: Span;
}

export class Interpreter {
  private readonly stack: Frame[] = [];

  constructor(private readonly input: InterpInput) {}

  /** Top-level entry: evaluate an expression with no calling frame. Returns the value, or null on abort. */
  evaluate(expr: A.Expr): ComptimeValue | null {
    this.stack.push({ bindings: new Map(), callerSpan: expr.span });
    try {
      return this.evalExpr(expr);
    } catch (e) {
      if (e instanceof CTAbort) return null;
      // ReturnSignal at top level means a `return` statement escaped its fn —
      // that's a parse-time impossibility (return outside fn body), so re-throw
      // rather than silently treat the signal value as the expression's result.
      throw e;
    } finally {
      this.stack.pop();
    }
  }

  // ---------------------------------------------------------- expressions

  private evalExpr(expr: A.Expr): ComptimeValue {
    switch (expr.kind) {
      case "IntLitExpr":
        return intVal(expr.value, expr.suffix ?? "i32");
      case "FloatLitExpr":
        return floatVal(expr.value, expr.suffix ?? "f64");
      case "BoolLitExpr":   return expr.value ? TRUE : FALSE;
      case "NullLitExpr":   return NULL;
      case "CharLitExpr":   return { kind: "char", value: expr.value };
      case "StringLitExpr": return this.evalStringLit(expr);
      case "IdentExpr":     return this.evalIdent(expr);
      case "CallExpr":      return this.evalCall(expr);
      case "BlockExpr":     return this.evalBlock(expr);
      case "IfExpr":        return this.evalIf(expr);
      case "UnaryExpr":     return this.evalUnary(expr);
      case "BinaryExpr":    return this.evalBinary(expr);
      case "ArrayLitExpr": {
        const elements = expr.elements.map((e) => this.evalExpr(e));
        const elementTypeName = elements.length > 0 ? typeNameOf(elements[0]!) : "?";
        return { kind: "array", elements, elementTypeName };
      }
      case "FieldExpr":     return this.evalField(expr);
      case "IndexExpr":     return this.evalIndex(expr);
      case "StructLitExpr": return this.evalStructLit(expr);
      default:
        return this.unsupported(expr.span, `${expr.kind} not supported in comptime MVP`);
    }
  }

  private evalStringLit(expr: A.StringLitExpr): ComptimeValue {
    let out = "";
    for (const part of expr.parts) {
      if (part.kind === "text") out += part.value;
      else {
        const v = this.evalExpr(part.expr);
        out += this.displayLikeShow(v);
      }
    }
    return stringVal(out);
  }

  private displayLikeShow(v: ComptimeValue): string {
    switch (v.kind) {
      case "string": return v.value;
      case "int":    return v.value.toString();
      case "float":  return v.value.toString();
      case "bool":   return v.value ? "true" : "false";
      case "char":   return String.fromCodePoint(v.value);
      case "null":   return "null";
      case "void":   return "void";
      default:       return displayValue(v);
    }
  }

  private evalIdent(expr: A.IdentExpr): ComptimeValue {
    const sym = this.input.entry.resolved.idents.get(expr);
    if (sym === undefined) {
      // Resolver should have reported R2006 already; surface a comptime-side
      // diagnostic too so failures show up in the comptime stage's snapshot.
      return this.unsupported(expr.span, `\`${expr.name}\` (resolver could not bind it)`);
    }
    for (let i = this.stack.length - 1; i >= 0; i--) {
      const v = this.stack[i]!.bindings.get(sym);
      if (v !== undefined) return v;
    }
    // Cross-decl @comptime evaluation is deferred to 1.5b.
    return this.unsupported(expr.span, `ident \`${expr.name}\` is not bound at comptime (cross-decl evaluation arrives in 1.5b)`);
  }

  private evalBlock(block: A.BlockExpr): ComptimeValue {
    for (const stmt of block.stmts) this.evalStmt(stmt);
    return block.trailing !== null ? this.evalExpr(block.trailing) : VOID;
  }

  private evalStmt(stmt: A.Stmt): void {
    switch (stmt.kind) {
      case "LetStmt": {
        const v = this.evalExpr(stmt.value);
        const sym = this.input.entry.resolved.locals.get(stmt);
        if (sym !== undefined) this.frame().bindings.set(sym, v);
        return;
      }
      case "ExprStmt":
        this.evalExpr(stmt.expr);
        return;
      case "ReturnStmt":
        throw new ReturnSignal(stmt.value !== null ? this.evalExpr(stmt.value) : VOID);
      case "AssignStmt":
        this.unsupported(stmt.span, "assignment not yet supported in comptime");
        return;
      case "ForStmt":
        this.unsupported(stmt.span, "loops not yet supported in comptime");
        return;
      case "BreakStmt":
      case "ContinueStmt":
      case "DeferStmt":
        this.unsupported(stmt.span, `${stmt.kind} not supported in comptime`);
        return;
    }
  }

  private evalIf(expr: A.IfExpr): ComptimeValue {
    const cond = this.evalExpr(expr.cond);
    if (cond.kind !== "bool") return this.unsupported(expr.cond.span, "if-condition must be bool");
    if (cond.value) return this.evalBlock(expr.then);
    if (expr.else === null) return VOID;
    return expr.else.kind === "IfExpr" ? this.evalIf(expr.else) : this.evalBlock(expr.else);
  }

  private evalUnary(expr: A.UnaryExpr): ComptimeValue {
    const v = this.evalExpr(expr.operand);
    switch (expr.op) {
      case "neg":
        if (v.kind === "int") return intVal(-v.value, v.typeName);
        if (v.kind === "float") return floatVal(-v.value, v.typeName);
        return this.unsupported(expr.span, `unary - on ${v.kind}`);
      case "not":
        if (v.kind === "bool") return v.value ? FALSE : TRUE;
        return this.unsupported(expr.span, `unary ! on ${v.kind}`);
      case "bitnot":
        if (v.kind === "int") return intVal(~v.value, v.typeName);
        return this.unsupported(expr.span, `unary ~ on ${v.kind}`);
    }
  }

  private evalBinary(expr: A.BinaryExpr): ComptimeValue {
    if (expr.op === "and" || expr.op === "or") return this.evalShortCircuit(expr);
    const l = this.evalExpr(expr.left);
    const r = this.evalExpr(expr.right);
    return this.applyBinary(expr.op, l, r, expr.span);
  }

  private evalShortCircuit(expr: A.BinaryExpr): ComptimeValue {
    const l = this.evalExpr(expr.left);
    if (l.kind !== "bool") return this.unsupported(expr.left.span, "logical operand must be bool");
    if (expr.op === "and") {
      if (!l.value) return FALSE;
      const r = this.evalExpr(expr.right);
      return r.kind === "bool" ? r : this.unsupported(expr.right.span, "logical operand must be bool");
    }
    if (l.value) return TRUE;
    const r = this.evalExpr(expr.right);
    return r.kind === "bool" ? r : this.unsupported(expr.right.span, "logical operand must be bool");
  }

  private applyBinary(op: A.BinaryOp, l: ComptimeValue, r: ComptimeValue, at: Span): ComptimeValue {
    if (l.kind === "int" && r.kind === "int") return this.intOp(op, l.value, r.value, l.typeName, at);
    if (l.kind === "float" && r.kind === "float") return this.floatOp(op, l.value, r.value, l.typeName, at);
    if (l.kind === "string" && r.kind === "string") return this.stringOp(op, l.value, r.value, at);
    if (l.kind === "bool" && r.kind === "bool" && (op === "eq" || op === "neq")) {
      const eq = l.value === r.value;
      return op === "eq" ? (eq ? TRUE : FALSE) : (eq ? FALSE : TRUE);
    }
    return this.unsupported(at, `${op} between ${l.kind} and ${r.kind}`);
  }

  private intOp(op: A.BinaryOp, l: bigint, r: bigint, t: string, at: Span): ComptimeValue {
    switch (op) {
      case "add": return intVal(l + r, t);
      case "sub": return intVal(l - r, t);
      case "mul": return intVal(l * r, t);
      case "div":
        if (r === 0n) { err(this.input.diags, "C4005", at); throw new CTAbort(); }
        return intVal(l / r, t);
      case "mod":
        if (r === 0n) { err(this.input.diags, "C4005", at); throw new CTAbort(); }
        return intVal(l % r, t);
      case "shl": return intVal(l << r, t);
      case "shr": return intVal(l >> r, t);
      case "bitand": return intVal(l & r, t);
      case "bitor":  return intVal(l | r, t);
      case "bitxor": return intVal(l ^ r, t);
      case "eq":  return l === r ? TRUE : FALSE;
      case "neq": return l !== r ? TRUE : FALSE;
      case "lt":  return l <  r ? TRUE : FALSE;
      case "lte": return l <= r ? TRUE : FALSE;
      case "gt":  return l >  r ? TRUE : FALSE;
      case "gte": return l >= r ? TRUE : FALSE;
      default: return this.unsupported(at, `${op} on int`);
    }
  }

  private floatOp(op: A.BinaryOp, l: number, r: number, t: string, at: Span): ComptimeValue {
    switch (op) {
      case "add": return floatVal(l + r, t);
      case "sub": return floatVal(l - r, t);
      case "mul": return floatVal(l * r, t);
      case "div": return floatVal(l / r, t);
      case "mod": return floatVal(l % r, t);
      case "eq":  return l === r ? TRUE : FALSE;
      case "neq": return l !== r ? TRUE : FALSE;
      case "lt":  return l <  r ? TRUE : FALSE;
      case "lte": return l <= r ? TRUE : FALSE;
      case "gt":  return l >  r ? TRUE : FALSE;
      case "gte": return l >= r ? TRUE : FALSE;
      default: return this.unsupported(at, `${op} on float`);
    }
  }

  private stringOp(op: A.BinaryOp, l: string, r: string, at: Span): ComptimeValue {
    switch (op) {
      case "add": return stringVal(l + r);
      case "eq":  return l === r ? TRUE : FALSE;
      case "neq": return l !== r ? TRUE : FALSE;
      case "lt":  return l <  r ? TRUE : FALSE;
      case "lte": return l <= r ? TRUE : FALSE;
      case "gt":  return l >  r ? TRUE : FALSE;
      case "gte": return l >= r ? TRUE : FALSE;
      default: return this.unsupported(at, `${op} on string`);
    }
  }

  // -------------------------------------------------------------- calls

  private evalCall(expr: A.CallExpr): ComptimeValue {
    const args = expr.args.map((a) => this.evalExpr(a.value));
    const sym = expr.callee.kind === "IdentExpr" ? this.input.entry.resolved.idents.get(expr.callee) : undefined;

    // Sandbox builtins live under names parsed as `@file` / `@env` (decorators
    // turned into builtin calls by the @comptime pass).
    if (sym !== undefined && sym.kind === "builtin-fn" && sym.source.kind === "builtin-fn") {
      return this.callBuiltin(sym.source.fnName, args, expr.span);
    }

    if (sym === undefined || sym.kind !== "fn" || sym.source.kind !== "fn") {
      return this.unsupported(expr.span, `comptime call target is not a fn`);
    }
    const fnDecl = sym.source.decl;
    if (fnDecl.body === null) {
      return this.unsupported(expr.span, `cannot call extern fn \`${fnDecl.name}\` at comptime`);
    }
    if (this.stack.length >= MAX_CALL_DEPTH) {
      err(this.input.diags, "C4004", expr.span);
      throw new CTAbort();
    }
    const bindings = new Map<Symbol, ComptimeValue>();
    for (let i = 0; i < fnDecl.params.length; i++) {
      const paramSym = this.input.entry.resolved.params.get(fnDecl.params[i]!);
      if (paramSym !== undefined && i < args.length) bindings.set(paramSym, args[i]!);
    }
    this.stack.push({ bindings, callerSpan: expr.span });
    try {
      return this.evalBlock(fnDecl.body);
    } catch (e) {
      if (e instanceof ReturnSignal) return e.value;
      throw e;
    } finally {
      this.stack.pop();
    }
  }

  private callBuiltin(name: string, args: readonly ComptimeValue[], at: Span): ComptimeValue {
    const result = callBuiltin(
      { fnName: name, args, callerFile: this.input.callerFile },
      this.input.sandbox,
    );
    if (result === null) {
      err(this.input.diags, "C4003", at, name);
      throw new CTAbort();
    }
    if (!result.ok) {
      err(this.input.diags, result.code, at, result.message);
      throw new CTAbort();
    }
    return result.value;
  }

  // ----------------------------------------------------- struct / array

  private evalField(expr: A.FieldExpr): ComptimeValue {
    const target = this.evalExpr(expr.target);
    if (target.kind !== "struct") return this.unsupported(expr.span, "field access on non-struct");
    const v = target.fields.get(expr.field);
    if (v === undefined) return this.unsupported(expr.fieldSpan, `no field \`${expr.field}\``);
    return v;
  }

  private evalIndex(expr: A.IndexExpr): ComptimeValue {
    const target = this.evalExpr(expr.target);
    const index = this.evalExpr(expr.index);
    if (target.kind !== "array") return this.unsupported(expr.span, "index on non-array");
    if (index.kind !== "int") return this.unsupported(expr.index.span, "index must be an integer");
    const i = Number(index.value);
    if (i < 0 || i >= target.elements.length) {
      err(this.input.diags, "C4010", expr.span, `index ${i}, length ${target.elements.length}`);
      throw new CTAbort();
    }
    return target.elements[i]!;
  }

  private evalStructLit(expr: A.StructLitExpr): ComptimeValue {
    const fields = new Map<string, ComptimeValue>();
    for (const f of expr.fields) fields.set(f.name, this.evalExpr(f.value));
    const typeName = expr.typeName.kind === "NamedType" ? expr.typeName.name : "?";
    return { kind: "struct", typeName, fields };
  }

  // --------------------------------------------------------------- aux

  private frame(): Frame {
    return this.stack[this.stack.length - 1]!;
  }

  private unsupported(at: Span, detail: string): never {
    err(this.input.diags, "C4011", at, detail);
    throw new CTAbort();
  }
}

function typeNameOf(v: ComptimeValue): string {
  switch (v.kind) {
    case "int": case "float": return v.typeName;
    case "bool":   return "bool";
    case "char":   return "char";
    case "string": return "string";
    case "null":   return "null";
    case "void":   return "void";
    case "array":  return `[${v.elementTypeName}]`;
    case "struct": return v.typeName;
  }
}

