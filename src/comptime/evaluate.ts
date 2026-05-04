// Walks every typed module, evaluating @comptime / @file decorators and
// recording generic instances. Produces an EvaluatedProject overlay; the
// typed AST is never mutated.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";

import { staticStringValue } from "../parser/ast.ts";
import { DEC } from "../parser/decorators.ts";

import { err } from "./diag.ts";
import type { EvaluatedProgram, EvaluatedProject } from "./evaluated-ast.ts";
import { InstanceRegistry } from "./instances.ts";
import { Interpreter } from "./interp.ts";
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

  const modules = new Map<string, EvaluatedProgram>();
  for (const [id, typed] of project.modules) {
    modules.set(id, evaluateProgram(typed, project, instances, opts));
  }
  return { typed: project, modules, instances: instances.entries() };
}

function evaluateProgram(
  typed: TypedProgram, project: TypedProject,
  _instances: InstanceRegistry, opts: EvaluateOptions,
): EvaluatedProgram {
  const comptimeDecls = new Map<A.ConstDecl, ComptimeValue>();
  const fileDecls = new Map<A.ConstDecl, ComptimeValue>();

  for (const decl of typed.resolved.source.decls) {
    if (decl.kind !== "ConstDecl") continue;
    const callerFile = typed.resolved.source.file;

    for (const dec of decl.decorators) {
      if (dec.name === DEC.comptime) {
        const interp = new Interpreter({
          project, entry: typed, callerFile,
          diags: opts.diags, sandbox: opts.sandbox,
        });
        const value = interp.evaluate(decl.value);
        if (value !== null) comptimeDecls.set(decl, value);
        break;
      }
      if (dec.name === DEC.file) {
        const value = evalFileDecorator(dec, callerFile, opts);
        if (value !== null) fileDecls.set(decl, value);
        break;
      }
    }
  }

  return { typed, comptimeDecls, fileDecls };
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
  if (result === null) return null;     // unreachable: @file is in the whitelist
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
  }
}
