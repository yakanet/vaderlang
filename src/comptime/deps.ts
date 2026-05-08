// Dependency graph for `@comptime`-decorated decls. Drives evaluation order
// so that `@comptime A :: f(B)` where `B :: @comptime g()` evaluates B first
// (extension §1.5b-e), and surfaces cycles as C4009 (extension §1.5b-d).

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";
import type { TypedProject, TypedProgram } from "../typecheck/index.ts";

import { err } from "./diag.ts";
import { DEC } from "../parser/decorators.ts";

interface Node {
  readonly decl: A.ConstDecl;
  readonly program: TypedProgram;
  readonly deps: Set<A.ConstDecl>;
}

export interface ComptimeOrder {
  /** Decls in evaluation order. Each entry knows its owning typed program so
   *  the caller can route the right `evaluated` overlay back to the module. */
  readonly entries: readonly { decl: A.ConstDecl; program: TypedProgram }[];
}

export function planComptimeOrder(project: TypedProject, diags: DiagnosticCollector): ComptimeOrder {
  const nodes = new Map<A.ConstDecl, Node>();

  for (const program of project.modules.values()) {
    for (const decl of program.resolved.source.decls) {
      if (decl.kind !== "ConstDecl") continue;
      if (!hasComptimeDecorator(decl)) continue;
      nodes.set(decl, { decl, program, deps: new Set() });
    }
  }

  for (const node of nodes.values()) {
    collectComptimeDeps(node.decl.value, node.program, nodes, node.deps);
  }

  return topoSort(nodes, diags);
}

function hasComptimeDecorator(decl: A.ConstDecl): boolean {
  for (const d of decl.decorators) if (d.name === DEC.comptime) return true;
  return false;
}

function collectComptimeDeps(
  expr: A.Expr, program: TypedProgram, nodes: Map<A.ConstDecl, Node>, out: Set<A.ConstDecl>,
): void {
  walkExpr(expr, (e) => {
    if (e.kind !== "IdentExpr") return;
    const sym = program.resolved.idents.get(e);
    if (sym === undefined) return;
    if (sym.kind === "const" && sym.source.kind === "const") {
      const dep = sym.source.decl;
      if (nodes.has(dep)) out.add(dep);
    }
  });
}

function topoSort(nodes: Map<A.ConstDecl, Node>, diags: DiagnosticCollector): ComptimeOrder {
  const order: { decl: A.ConstDecl; program: TypedProgram }[] = [];
  const color = new Map<A.ConstDecl, "white" | "grey" | "black">();
  const cyclic = new Set<A.ConstDecl>();

  for (const decl of nodes.keys()) color.set(decl, "white");

  function visit(decl: A.ConstDecl, stack: A.ConstDecl[]): void {
    const c = color.get(decl);
    if (c === "black") return;
    if (c === "grey") {
      const start = stack.indexOf(decl);
      const cycle = (start >= 0 ? stack.slice(start) : stack).concat(decl);
      err(diags, "C4009", decl.span, cycle.map((d) => d.name).join(" → "));
      for (const d of cycle) cyclic.add(d);
      return;
    }
    color.set(decl, "grey");
    stack.push(decl);
    for (const dep of nodes.get(decl)!.deps) visit(dep, stack);
    stack.pop();
    color.set(decl, "black");
    order.push({ decl, program: nodes.get(decl)!.program });
  }

  for (const decl of nodes.keys()) visit(decl, []);
  return { entries: order.filter((e) => !cyclic.has(e.decl)) };
}

// ----------------------------------------------------------- expression walker

function walkExpr(expr: A.Expr, visit: (e: A.Expr) => void): void {
  visit(expr);
  switch (expr.kind) {
    case "CallExpr":
      walkExpr(expr.callee, visit);
      for (const a of expr.args) walkExpr(a.value, visit);
      return;
    case "FieldExpr":  walkExpr(expr.target, visit); return;
    case "IndexExpr":  walkExpr(expr.target, visit); walkExpr(expr.index, visit); return;
    case "UnaryExpr":  walkExpr(expr.operand, visit); return;
    case "BinaryExpr": walkExpr(expr.left, visit); walkExpr(expr.right, visit); return;
    case "IfExpr":
      walkExpr(expr.cond, visit);
      walkExpr(expr.then, visit);
      if (expr.else !== null) walkExpr(expr.else, visit);
      return;
    case "MatchExpr":
      walkExpr(expr.scrutinee, visit);
      for (const arm of expr.arms) {
        if (arm.guard !== null) walkExpr(arm.guard, visit);
        walkExpr(arm.body, visit);
      }
      return;
    case "BlockExpr":
      for (const stmt of expr.stmts) walkStmt(stmt, visit);
      if (expr.trailing !== null) walkExpr(expr.trailing, visit);
      return;
    case "StructLitExpr": for (const f of expr.fields) walkExpr(f.value, visit); return;
    case "SeqLitExpr":    for (const e of expr.elements) walkExpr(e, visit); return;
    case "StringLitExpr": for (const p of expr.parts) if (p.kind === "interp") walkExpr(p.expr, visit); return;
    case "RangeExpr":  walkExpr(expr.lower, visit); walkExpr(expr.upper, visit); return;
    case "TryExpr":    walkExpr(expr.inner, visit); return;
    case "CastExpr":   walkExpr(expr.value, visit); return;
    case "LambdaExpr": walkExpr(expr.body, visit); return;
    default: return;
  }
}

function walkStmt(stmt: A.Stmt, visit: (e: A.Expr) => void): void {
  switch (stmt.kind) {
    case "LetStmt":    walkExpr(stmt.value, visit); return;
    case "ExprStmt":   walkExpr(stmt.expr, visit); return;
    case "ReturnStmt": if (stmt.value !== null) walkExpr(stmt.value, visit); return;
    case "AssignStmt": walkExpr(stmt.target, visit); walkExpr(stmt.value, visit); return;
    case "ForStmt":
      if (stmt.form.kind === "while") walkExpr(stmt.form.cond, visit);
      if (stmt.form.kind === "in") walkExpr(stmt.form.iter, visit);
      walkExpr(stmt.body, visit);
      return;
    case "DeferStmt":
      if ("kind" in stmt.body && stmt.body.kind === "BlockExpr") walkExpr(stmt.body, visit);
      else walkStmt(stmt.body as A.Stmt, visit);
      return;
    default: return;
  }
}
