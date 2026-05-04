import type { GlobalOpts } from "../cli/options.ts";
import { renderAllJson, renderAllTextSingle } from "../diagnostics/render.ts";
import { displayType } from "../typecheck/index.ts";
import { displayValue } from "../comptime/index.ts";
import { pipelineAst, pipelineBytecode, pipelineEvaluated, pipelineLowered, pipelineResolved, pipelineTyped } from "../pipeline.ts";
import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { LoweredDecl } from "../lower/index.ts";
import { writeVir } from "../bytecode/text.ts";

/** Stages the frontend pipeline can produce today. Mirrors `PipelineStage`. */
const IMPLEMENTED_STAGES = ["ast", "resolved-ast", "typed-ast", "evaluated-ast", "lowered-ast", "bytecode"] as const;
/** Stages reserved for future codegen work — accepted by the CLI for help-text honesty. */
const FUTURE_STAGES = ["c", "wasm"] as const;
const STAGES = [...IMPLEMENTED_STAGES, ...FUTURE_STAGES];
type Stage = typeof STAGES[number];

function isStage(s: string): s is Stage {
  return (STAGES as readonly string[]).includes(s);
}

export async function cmdDump(opts: GlobalOpts, args: string[]): Promise<number> {
  const stageArg = args.find((a) => a.startsWith("--stage="));
  const positional = args.filter((a) => !a.startsWith("--"));
  const file = positional[0];

  if (!stageArg || !file) {
    console.error("vader dump: expected --stage=<stage> <file>");
    console.error(`stages: ${STAGES.join(", ")}`);
    return 1;
  }

  const stage = stageArg.slice("--stage=".length);
  if (!isStage(stage)) {
    console.error(`vader dump: unknown stage "${stage}"`);
    console.error(`stages: ${STAGES.join(", ")}`);
    return 1;
  }

  switch (stage) {
    case "ast":           return runStage(opts, file, runAst);
    case "resolved-ast":  return runStage(opts, file, runResolvedAst);
    case "typed-ast":     return runStage(opts, file, runTypedAst);
    case "evaluated-ast": return runStage(opts, file, (f) => runEvaluatedAst(f, opts));
    case "lowered-ast":   return runStage(opts, file, (f) => runLoweredAst(f, opts));
    case "bytecode":      return runBytecodeStage(opts, file);
    default:
      console.error(`vader dump: stage "${stage}" not yet implemented`);
      return 2;
  }
}

type StageRunner = (file: string) => Promise<{ output: unknown; diagnostics: DiagnosticCollector; source: string }>;

async function runStage(opts: GlobalOpts, file: string, run: StageRunner): Promise<number> {
  const { output, diagnostics, source } = await run(file);
  const sorted = diagnostics.sorted();
  if (sorted.length > 0) {
    console.error(opts.diagnostics === "json"
      ? renderAllJson(sorted)
      : renderAllTextSingle(sorted, file, source));
  }
  console.log(JSON.stringify(output, bigintReplacer, 2));
  return sorted.some((d) => d.severity === "error") ? 1 : 0;
}

function bigintReplacer(_k: string, v: unknown): unknown {
  return typeof v === "bigint" ? `${v.toString()}n` : v;
}

async function runAst(file: string) {
  const r = await pipelineAst(file);
  return { output: r.program, diagnostics: r.diagnostics, source: r.source };
}

async function runResolvedAst(file: string) {
  const r = await pipelineResolved(file);
  const output = {
    modules: [...r.project.modules.values()].map((p) => ({
      module: p.module.displayPath,
      symbols: [...p.module.symbols.values()].map((s) => ({
        name: s.name, kind: s.kind, visibility: s.visibility,
      })),
      imports: p.module.imports.map((i) => ({ path: i.path, resolved: i.resolvedTo !== null })),
      counts: {
        idents: p.idents.size, types: p.types.size, params: p.params.size,
        locals: p.locals.size, typeParams: p.typeParams.size, fields: p.fields.size,
      },
    })),
  };
  return { output, diagnostics: r.diagnostics, source: r.source };
}

async function runEvaluatedAst(file: string, opts: GlobalOpts) {
  const r = await pipelineEvaluated(file, { allowEnv: opts.allowEnv });
  const output = {
    modules: [...r.evaluated.modules.values()].map((m) => ({
      module: m.typed.resolved.module.displayPath,
      comptime: [...m.comptimeDecls].map(([d, v]) => ({ name: d.name, value: displayValue(v) })),
      file:     [...m.fileDecls].map(([d, v]) => ({ name: d.name, value: displayValue(v) })),
    })),
    instances: r.evaluated.instances.map((i) => i.displayKey),
  };
  return { output, diagnostics: r.diagnostics, source: r.source };
}

async function runBytecodeStage(opts: GlobalOpts, file: string): Promise<number> {
  const r = await pipelineBytecode(file, { allowEnv: opts.allowEnv });
  const sorted = r.diagnostics.sorted();
  if (sorted.length > 0) {
    console.error(opts.diagnostics === "json"
      ? renderAllJson(sorted)
      : renderAllTextSingle(sorted, file, r.source));
  }
  process.stdout.write(writeVir(r.bytecode));
  return sorted.some((d) => d.severity === "error") ? 1 : 0;
}

async function runLoweredAst(file: string, opts: GlobalOpts) {
  const r = await pipelineLowered(file, { allowEnv: opts.allowEnv });
  const output = {
    modules: [...r.lowered.modules.values()].map((m) => ({
      module: m.displayPath,
      decls: m.decls.map(summariseDecl),
    })),
  };
  return { output, diagnostics: r.diagnostics, source: r.source };
}

function summariseDecl(d: LoweredDecl) {
  switch (d.kind) {
    case "LoweredFnDecl":
      return {
        kind: d.kind, mangled: d.mangled, name: declName(d.origin.decl),
        params: d.params.map((p) => ({ name: p.name, type: displayType(p.type) })),
        returnType: displayType(d.returnType),
        body: d.body === null ? null : "<lowered>",
      };
    case "LoweredStructDecl":
      return {
        kind: d.kind, mangled: d.mangled, name: declName(d.origin.decl),
        fields: d.fields.map((f) => ({ name: f.name, type: displayType(f.type) })),
      };
    case "LoweredConstDecl":
      return {
        kind: d.kind, mangled: d.mangled, name: declName(d.origin.decl),
        type: displayType(d.type),
      };
  }
}

function declName(d: LoweredDecl["origin"]["decl"]): string {
  return d.kind === "ImplDecl" ? `<${d.traitName} for ?>` : d.name;
}

async function runTypedAst(file: string) {
  const r = await pipelineTyped(file);
  const output = {
    modules: [...r.typed.modules.values()].map((p) => ({
      module: p.resolved.module.displayPath,
      decls: p.resolved.source.decls
        .filter((d) => "name" in d)
        .map((d) => {
          const ty = p.declTypes.get(d);
          return {
            kind: d.kind,
            name: "name" in d ? d.name : null,
            type: ty !== undefined ? displayType(ty) : null,
          };
        }),
      counts: { exprs: p.exprTypes.size, locals: p.localTypes.size },
    })),
  };
  return { output, diagnostics: r.diagnostics, source: r.source };
}
