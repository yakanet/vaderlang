// Drives compile-time evaluation: resolves @comptime decls in dependency
// order, runs each through the bytecode VM, and bakes @file decorators
// (file reads happen outside the VM since they're decorator-only).

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
import type { Type } from "../typecheck/types.ts";
import { CORE_STRUCTS } from "../typecheck/types.ts";

import { staticStringValue } from "../parser/ast.ts";
import { DEC } from "../parser/decorators.ts";

import { err } from "./diag.ts";
import type { EvaluatedProgram, EvaluatedProject } from "./evaluated-ast.ts";
import { InstanceRegistry } from "./instances.ts";
import { planComptimeOrder } from "./deps.ts";
import { runComptimeDecl } from "./run.ts";
import { COMPTIME_BUILTIN, callBuiltin, type SandboxOptions } from "./sandbox.ts";
import type { ComptimeValue } from "./value.ts";
import { stringVal } from "./value.ts";

export interface EvaluateOptions {
  readonly diags: DiagnosticCollector;
  readonly sandbox: SandboxOptions;
}

export function evaluateProject(project: TypedProject, opts: EvaluateOptions): EvaluatedProject {
  const instances = new InstanceRegistry();
  collectInstances(project, instances);

  // 1. Walk every module to bake @file decorators (synchronous, no deps).
  // 2. Plan @comptime evaluation order (topological sort + cycle detection).
  // 3. Evaluate @comptime decls in that order, accumulating values into a
  //    shared map so later decls can inline earlier ones.
  const fileByDecl = new Map<A.ConstDecl, ComptimeValue>();
  const fileOwner = new Map<A.ConstDecl, TypedProgram>();
  for (const typed of project.modules.values()) {
    for (const decl of typed.resolved.source.decls) {
      if (decl.kind !== "ConstDecl") continue;
      for (const dec of decl.decorators) {
        if (dec.name !== DEC.file) continue;
        const value = evalFileDecorator(dec, typed.resolved.source.file, opts);
        if (value !== null) { fileByDecl.set(decl, value); fileOwner.set(decl, typed); }
        break;
      }
    }
  }

  const comptimeByDecl = new Map<A.ConstDecl, ComptimeValue>();
  const comptimeOwner = new Map<A.ConstDecl, TypedProgram>();
  const order = planComptimeOrder(project, opts.diags);
  for (const { decl, program } of order.entries) {
    const value = runComptimeDecl({
      decl, project, callerProgram: program, evaluated: comptimeByDecl,
      callerFile: program.resolved.source.file, diags: opts.diags, sandbox: opts.sandbox,
    });
    if (value !== null) { comptimeByDecl.set(decl, value); comptimeOwner.set(decl, program); }
  }

  // Group per-module overlays.
  const modules = new Map<string, EvaluatedProgram>();
  for (const [id, typed] of project.modules) {
    const ct = new Map<A.ConstDecl, ComptimeValue>();
    const fl = new Map<A.ConstDecl, ComptimeValue>();
    for (const [decl, value] of comptimeByDecl) {
      if (comptimeOwner.get(decl) === typed) ct.set(decl, value);
    }
    for (const [decl, value] of fileByDecl) {
      if (fileOwner.get(decl) === typed) fl.set(decl, value);
    }
    modules.set(id, { typed, comptimeDecls: ct, fileDecls: fl });
  }
  return { typed: project, modules, instances: instances.entries() };
}

function evalFileDecorator(
  dec: A.Decorator, callerFile: string, opts: EvaluateOptions,
): ComptimeValue | null {
  const arg = dec.args[0];
  const path = dec.args.length === 1 && arg !== undefined && arg.kind === "StringLitExpr"
    ? staticStringValue(arg) : null;
  if (path === null) {
    err(opts.diags, "C4012", dec.span);
    return null;
  }
  const result = callBuiltin(
    { fnName: COMPTIME_BUILTIN.file, args: [stringVal(path)], callerFile },
    opts.sandbox,
  );
  if (result === null) return null;
  if (!result.ok) {
    err(opts.diags, result.code, dec.span, result.message);
    return null;
  }
  return result.value;
}

/** Walk a block for `for x in iter` statements and pass each `iter` expr to
 *  the visitor. Recurses into nested blocks/exprs since for-in can appear
 *  anywhere inside a fn body. */
function forEachForInIter(block: A.BlockExpr, visit: (iter: A.Expr) => void): void {
  for (const stmt of block.stmts) walkStmt(stmt, visit);
  if (block.trailing !== null) walkExpr(block.trailing, visit);
}

function walkStmt(stmt: A.Stmt, visit: (iter: A.Expr) => void): void {
  switch (stmt.kind) {
    case "ForStmt":
      if (stmt.form.kind === "in") visit(stmt.form.iter);
      forEachForInIter(stmt.body, visit);
      return;
    case "LetStmt":     walkExpr(stmt.value, visit); return;
    case "ExprStmt":    walkExpr(stmt.expr, visit); return;
    case "ReturnStmt":  if (stmt.value !== null) walkExpr(stmt.value, visit); return;
    case "AssignStmt":  walkExpr(stmt.target, visit); walkExpr(stmt.value, visit); return;
    case "DeferStmt":
      if ("kind" in stmt.body && stmt.body.kind === "BlockExpr") forEachForInIter(stmt.body, visit);
      else walkStmt(stmt.body as A.Stmt, visit);
      return;
    default: return;
  }
}

function walkExpr(expr: A.Expr, visit: (iter: A.Expr) => void): void {
  switch (expr.kind) {
    case "BlockExpr":  forEachForInIter(expr, visit); return;
    case "IfExpr":
      walkExpr(expr.cond, visit);
      forEachForInIter(expr.then, visit);
      if (expr.else !== null) walkExpr(expr.else, visit);
      return;
    case "MatchExpr":
      walkExpr(expr.scrutinee, visit);
      for (const arm of expr.arms) walkExpr(arm.body, visit);
      return;
    case "CallExpr":
      walkExpr(expr.callee, visit);
      for (const a of expr.args) walkExpr(a.value, visit);
      return;
    case "BinaryExpr": walkExpr(expr.left, visit); walkExpr(expr.right, visit); return;
    case "UnaryExpr":  walkExpr(expr.operand, visit); return;
    case "FieldExpr":  walkExpr(expr.target, visit); return;
    case "IndexExpr":  walkExpr(expr.target, visit); walkExpr(expr.index, visit); return;
    default: return;
  }
}

// ----------------------------------------------------- instance walker

function collectInstances(project: TypedProject, registry: InstanceRegistry): void {
  // Locate `std/core::ArrayIter` once so the for-in walker below can register
  // an `ArrayIter(T)` instance whenever user code iterates a `[T]` array.
  let arrayIterSymbol: Symbol | null = null;
  for (const m of project.modules.values()) {
    if (m.resolved.module.displayPath === "std/core") {
      const s = m.resolved.module.symbols.get(CORE_STRUCTS.ArrayIter);
      if (s !== undefined) arrayIterSymbol = s;
      break;
    }
  }

  for (const typed of project.modules.values()) {
    for (const ty of typed.declTypes.values()) registry.observe(ty);
    for (const ty of typed.paramTypes.values()) registry.observe(ty);
    for (const ty of typed.typeExprTypes.values()) registry.observe(ty);
    for (const ty of typed.exprTypes.values()) registry.observe(ty);
    for (const ty of typed.localTypes.values()) registry.observe(ty);

    // `for x in arr` over a `[T]` triggers an auto-wrap into `ArrayIter(T)`
    // at lower time. Register that instance here so mono materialises the
    // specialised impl members; the lowerer can't add to the registry
    // because it runs after mono.
    if (arrayIterSymbol !== null) {
      for (const decl of typed.resolved.source.decls) {
        if (decl.kind !== "FnDecl" || decl.body === null) continue;
        forEachForInIter(decl.body, (iter) => {
          const iterType = typed.exprTypes.get(iter);
          if (iterType !== undefined && iterType.kind === "Array") {
            registry.add(arrayIterSymbol!, [iterType.element]);
          }
        });
      }
    }
    // Inferred generic-fn call sites: the typechecker records (CallExpr → typeArgs)
    // for each call site where it successfully unified the fn's type params.
    for (const [callExpr, typeArgs] of typed.genericFnCalls) {
      if (callExpr.callee.kind === "IdentExpr") {
        const sym = typed.resolved.idents.get(callExpr.callee);
        if (sym !== undefined) registry.observeFnCall(sym, typeArgs);
      } else if (callExpr.callee.kind === "FieldExpr") {
        // UFCS generic call: sym is in ufcsFreeResolutions
        const sym = typed.ufcsFreeResolutions.get(callExpr.callee);
        if (sym !== undefined) registry.observeFnCall(sym, typeArgs);
      }
    }
  }
}
