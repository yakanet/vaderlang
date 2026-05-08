// Compiler frontend pipeline. Each stage builds on the previous one and
// produces additional structured output, accumulating into the same
// DiagnosticCollector. Use this from CLI commands so they all see the same
// staged outputs without re-implementing the wiring.

import { basename } from "node:path";

import { DiagnosticCollector } from "./diagnostics/collector.ts";
import { parseSource } from "./parser/pipeline.ts";
import type { Program } from "./parser/ast.ts";
import { defaultProjectRoot } from "./resolver/module.ts";
import { resolveProject } from "./resolver/index.ts";
import type { ResolvedProject } from "./resolver/resolved-ast.ts";
import { checkProject } from "./typecheck/index.ts";
import type { TypedProject } from "./typecheck/index.ts";
import { analyzeClosures } from "./closures/analyze.ts";
import type { ClosureAnalysis } from "./closures/analyze.ts";
import { evaluateProject } from "./comptime/index.ts";
import type { EvaluatedProject } from "./comptime/index.ts";
import { lowerProject } from "./lower/index.ts";
import type { LoweredProject } from "./lower/index.ts";
import { eliminateDeadCode } from "./dce/index.ts";
import { emitBytecode } from "./bytecode/index.ts";
import type { BytecodeModule } from "./bytecode/index.ts";
import { buildImplRegistry } from "./typecheck/impls.ts";
import { buildCFGProject } from "./midir/build.ts";
import type { CFGProject } from "./midir/cfg.ts";
import { eliminateDeadCFG } from "./midir/dce.ts";
import { emitBytecodeFromCFG } from "./midir/emit.ts";
import { annotateEscape } from "./midir/escape.ts";
import { fromSSA, toSSA } from "./midir/ssa.ts";

export type PipelineStage =
  | "ast" | "resolved-ast" | "typed-ast" | "evaluated-ast"
  | "lowered-ast" | "dced-ast" | "cfg" | "bytecode";

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
  readonly closures: ClosureAnalysis;
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

export interface CfgResult extends DcedResult {
  readonly cfg: CFGProject;
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
  const closures = analyzeClosures(typed);
  return { ...r, typed, closures };
}

export async function pipelineEvaluated(
  file: string, opts?: { allowEnv?: boolean },
): Promise<EvaluatedResult> {
  const r = await pipelineTyped(file);
  const evaluated = evaluateProject(r.typed, {
    diags: r.diagnostics,
    sandbox: {
      allowEnv: opts?.allowEnv ?? false,
      projectRoot: defaultProjectRoot(file),
    },
  });
  return { ...r, evaluated };
}

export async function pipelineLowered(
  file: string, opts?: { allowEnv?: boolean },
): Promise<LoweredResult> {
  const r = await pipelineEvaluated(file, opts);
  const lowered = lowerProject(r.evaluated, r.diagnostics, r.closures);
  return { ...r, lowered };
}

export async function pipelineDced(
  file: string, opts?: { allowEnv?: boolean },
): Promise<DcedResult> {
  const r = await pipelineLowered(file, opts);
  const dced = eliminateDeadCode(r.lowered);
  return { ...r, dced };
}

export async function pipelineCfg(
  file: string, opts?: { allowEnv?: boolean },
): Promise<CfgResult> {
  const r = await pipelineDced(file, opts);
  // Build → DCE → SSA → escape analysis → fromSSA → DCE. The SSA round-trip
  // is behaviour-neutral ; escape analysis runs on the SSA form to
  // exploit single-def value tracking, and annotates StructNew/ArrayNew
  // with `stack: true` when the value cannot be observed past the fn's
  // return. Phase 5 ships the analysis only ; codegen for stack-allocated
  // structs lands in a follow-up.
  const ssa = toSSA(eliminateDeadCFG(buildCFGProject(r.dced)));
  const annotated = annotateEscape(ssa).project;
  const cfg = eliminateDeadCFG(fromSSA(annotated));
  return { ...r, cfg };
}

export async function pipelineBytecode(
  file: string, opts?: { allowEnv?: boolean; bytecodeOpt?: boolean; midIr?: boolean },
): Promise<BytecodeResult> {
  const r = await pipelineDced(file, opts);
  const implRegistry = buildImplRegistry(r.evaluated.typed.resolved);
  const emitOpts = { optimize: opts?.bytecodeOpt ?? true, implRegistry };
  let bytecode: BytecodeModule;
  if (opts?.midIr) {
    const ssa = toSSA(eliminateDeadCFG(buildCFGProject(r.dced)));
    const cfg = eliminateDeadCFG(fromSSA(annotateEscape(ssa).project));
    bytecode = emitBytecodeFromCFG(r.dced, cfg, moduleNameFromFile(file), emitOpts);
  } else {
    bytecode = emitBytecode(r.dced, moduleNameFromFile(file), emitOpts);
  }
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
