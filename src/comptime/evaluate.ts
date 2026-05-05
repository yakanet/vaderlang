// Drives compile-time evaluation: resolves @comptime decls in dependency
// order, runs each through the bytecode VM, and bakes @file decorators
// (file reads happen outside the VM since they're decorator-only).

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
import type { Type } from "../typecheck/types.ts";

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

// ----------------------------------------------------- instance walker

function collectInstances(project: TypedProject, registry: InstanceRegistry): void {
  for (const typed of project.modules.values()) {
    for (const ty of typed.declTypes.values()) registry.observe(ty);
    for (const ty of typed.paramTypes.values()) registry.observe(ty);
    for (const ty of typed.typeExprTypes.values()) registry.observe(ty);
    for (const ty of typed.exprTypes.values()) registry.observe(ty);
    for (const ty of typed.localTypes.values()) registry.observe(ty);
    // Explicit `Foo(T1, T2)(...)` generic-fn call sites surface as
    // `GenericInstExpr` nodes — record them so a future fn-mono pass has
    // the dispatch list ready.
    for (const expr of typed.exprTypes.keys()) {
      if (expr.kind !== "GenericInstExpr") continue;
      if (expr.callee.kind !== "IdentExpr") continue;
      const sym = typed.resolved.idents.get(expr.callee);
      if (sym === undefined) continue;
      const args: Type[] = [];
      let allKnown = true;
      for (const ta of expr.typeArgs) {
        const t = typed.typeExprTypes.get(ta);
        if (t === undefined) { allKnown = false; break; }
        args.push(t);
      }
      if (allKnown) registry.observeFnCall(sym, args);
    }
  }
}
