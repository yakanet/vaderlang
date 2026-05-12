// Compiler frontend pipeline. Each stage builds on the previous one and
// produces additional structured output, accumulating into the same
// DiagnosticCollector. Use this from CLI commands so they all see the same
// staged outputs without re-implementing the wiring.

import { basename } from "node:path";

import { DiagnosticCollector } from "./diagnostics/collector.ts";
import { parseSource } from "./parser/pipeline.ts";
import type { Program } from "./parser/ast.ts";
import { UNASSIGNED_NODE_ID } from "./parser/ast.ts";
import { defaultProjectRoot } from "./resolver/module.ts";
import { resolveProject } from "./resolver/index.ts";
import type { ResolvedProject } from "./resolver/resolved-ast.ts";
import { checkProject } from "./typecheck/index.ts";
import type { TypedProject } from "./typecheck/index.ts";
import { analyzeClosures } from "./lower/passes/closures.ts";
import type { ClosureAnalysis } from "./lower/passes/closures.ts";
import { evaluateProject } from "./comptime/index.ts";
import type { EvaluatedProject } from "./comptime/index.ts";
import { lowerProject } from "./lower/index.ts";
import type { LoweredProject } from "./lower/index.ts";
import type { BytecodeModule } from "./bytecode/index.ts";
import { buildImplRegistry } from "./typecheck/impls.ts";
import { buildCFGProject } from "./midir/build.ts";
import type { CFGProject } from "./midir/cfg.ts";
import { eliminateDeadCFG, pruneUnreachable } from "./midir/dce.ts";
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
  // Entry can be either a single file or a folder module (e.g. `vader/lexer/`,
  // which `vader test` hands in to compile the whole sibling set as one unit).
  // Single-file entries pre-read `source` so diagnostic rendering has it ;
  // folder entries leave it empty — the renderer falls back to re-reading
  // each individual file when surfacing per-diagnostic context.
  const entryIsDir = await isDirectory(file);
  const source = entryIsDir ? "" : await Bun.file(file).text();
  const diagnostics = new DiagnosticCollector();
  const project = resolveProject({ entryPath: file, diags: diagnostics });
  // The entry file's parsed Program lives inside project.modules; surface it
  // directly so callers don't need to walk the modules map. For folder
  // entries, pick any of the module's files — downstream consumers (lower,
  // emit) iterate `project.modules` themselves and don't depend on the
  // `program` field being the "entry" module.
  let program: Program | undefined;
  for (const p of project.modules.values()) {
    if (entryIsDir ? p.module.rootDir === file : p.module.files.some((f) => f.path === file)) {
      program = p.source;
      break;
    }
  }
  return { file, source, program: program ?? p404(file), project, diagnostics };
}

async function isDirectory(path: string): Promise<boolean> {
  try {
    const { statSync } = await import("node:fs");
    return statSync(path).isDirectory();
  } catch {
    return false;
  }
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
  file: string, opts?: { allowEnv?: boolean; keepTests?: boolean },
): Promise<DcedResult> {
  const r = await pipelineLowered(file, opts);
  const dced = pruneUnreachable(r.lowered, { keepTests: opts?.keepTests });
  return { ...r, dced };
}

export async function pipelineCfg(
  file: string, opts?: { allowEnv?: boolean; keepTests?: boolean },
): Promise<CfgResult> {
  const r = await pipelineDced(file, opts);
  // SSA round-trip is behaviour-neutral; escape analysis runs on SSA to
  // exploit single-def value tracking and annotates StructNew/ArrayNew with
  // `stack: true` when the value can't be observed past the fn's return.
  const ssa = toSSA(eliminateDeadCFG(buildCFGProject(r.dced)));
  const cfg = eliminateDeadCFG(fromSSA(annotateEscape(ssa).project));
  return { ...r, cfg };
}

export async function pipelineBytecode(
  file: string, opts?: { allowEnv?: boolean; bytecodeOpt?: boolean; keepTests?: boolean },
): Promise<BytecodeResult> {
  const r = await pipelineCfg(file, opts);
  const implRegistry = buildImplRegistry(r.evaluated.typed.resolved);
  const emitOpts = { optimize: opts?.bytecodeOpt ?? true, implRegistry };
  const bytecode = emitBytecodeFromCFG(r.cfg, moduleNameFromFile(file), emitOpts);
  return { ...r, bytecode };
}

function moduleNameFromFile(file: string): string {
  return basename(file, ".vader");
}

function p404(file: string): Program {
  return {
    kind: "Program",
    id: UNASSIGNED_NODE_ID, file,
    span: { start: { file, offset: 0, line: 1, column: 1 }, end: { file, offset: 0, line: 1, column: 1 } },
    decls: [],
  };
}
