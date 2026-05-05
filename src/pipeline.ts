// Compiler frontend pipeline. Each stage builds on the previous one and
// produces additional structured output, accumulating into the same
// DiagnosticCollector. Use this from CLI commands so they all see the same
// staged outputs without re-implementing the wiring.

import { basename } from "node:path";

import { DiagnosticCollector } from "./diagnostics/collector.ts";
import { parseSource } from "./parser/pipeline.ts";
import type { Program } from "./parser/ast.ts";
import { resolveProject } from "./resolver/index.ts";
import type { ResolvedProject } from "./resolver/resolved-ast.ts";
import { checkProject } from "./typecheck/index.ts";
import type { TypedProject } from "./typecheck/index.ts";
import { evaluateProject } from "./comptime/index.ts";
import type { EvaluatedProject } from "./comptime/index.ts";
import { lowerProject } from "./lower/index.ts";
import type { LoweredProject } from "./lower/index.ts";
import { eliminateDeadCode } from "./dce/index.ts";
import { emitBytecode } from "./bytecode/index.ts";
import type { BytecodeModule } from "./bytecode/index.ts";

export type PipelineStage =
  | "ast" | "resolved-ast" | "typed-ast" | "evaluated-ast"
  | "lowered-ast" | "dced-ast" | "bytecode";

export interface AstResult {
  readonly file: string;
  readonly source: string;
  readonly program: Program;
  readonly diagnostics: DiagnosticCollector;
}

export interface ResolvedResult extends AstResult {
  readonly project: ResolvedProject;
}

export interface TypedResult extends ResolvedResult {
  readonly typed: TypedProject;
}

export interface EvaluatedResult extends TypedResult {
  readonly evaluated: EvaluatedProject;
}

export interface LoweredResult extends EvaluatedResult {
  readonly lowered: LoweredProject;
}

export interface DcedResult extends LoweredResult {
  readonly dced: LoweredProject;
}

export interface BytecodeResult extends DcedResult {
  readonly bytecode: BytecodeModule;
}

export async function pipelineAst(file: string): Promise<AstResult> {
  const source = await Bun.file(file).text();
  const { program, diagnostics: parseDiags } = parseSource(source, file);
  const diagnostics = new DiagnosticCollector();
  for (const d of parseDiags.sorted()) diagnostics.emit(d);
  return { file, source, program, diagnostics };
}

export async function pipelineResolved(file: string): Promise<ResolvedResult> {
  const source = await Bun.file(file).text();
  const diagnostics = new DiagnosticCollector();
  const project = resolveProject({ entryPath: file, diags: diagnostics });
  // The entry file's parsed Program lives inside project.modules; surface it
  // directly so callers don't need to walk the modules map.
  let program: Program | undefined;
  for (const p of project.modules.values()) {
    if (p.module.files.some((f) => f.path === file)) {
      program = p.source;
      break;
    }
  }
  return { file, source, program: program ?? p404(file), project, diagnostics };
}

export async function pipelineTyped(file: string): Promise<TypedResult> {
  const r = await pipelineResolved(file);
  const typed = checkProject(r.project, r.diagnostics);
  return { ...r, typed };
}

export async function pipelineEvaluated(
  file: string, opts?: { allowEnv?: boolean },
): Promise<EvaluatedResult> {
  const r = await pipelineTyped(file);
  const evaluated = evaluateProject(r.typed, {
    diags: r.diagnostics,
    sandbox: { allowEnv: opts?.allowEnv ?? false },
  });
  return { ...r, evaluated };
}

export async function pipelineLowered(
  file: string, opts?: { allowEnv?: boolean },
): Promise<LoweredResult> {
  const r = await pipelineEvaluated(file, opts);
  const lowered = lowerProject(r.evaluated, r.diagnostics);
  return { ...r, lowered };
}

export async function pipelineDced(
  file: string, opts?: { allowEnv?: boolean },
): Promise<DcedResult> {
  const r = await pipelineLowered(file, opts);
  const dced = eliminateDeadCode(r.lowered);
  return { ...r, dced };
}

export async function pipelineBytecode(
  file: string, opts?: { allowEnv?: boolean },
): Promise<BytecodeResult> {
  const r = await pipelineDced(file, opts);
  const bytecode = emitBytecode(r.dced, moduleNameFromFile(file));
  return { ...r, bytecode };
}

function moduleNameFromFile(file: string): string {
  return basename(file, ".vader");
}

function p404(file: string): Program {
  return {
    kind: "Program",
    file,
    span: { start: { file, offset: 0, line: 1, column: 1 }, end: { file, offset: 0, line: 1, column: 1 } },
    decls: [],
  };
}
