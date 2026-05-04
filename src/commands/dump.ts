import type { GlobalOpts } from "../cli/options.ts";
import { renderAllJson, renderAllTextSingle } from "../diagnostics/render.ts";
import { displayType } from "../typecheck/index.ts";
import { pipelineAst, pipelineResolved, pipelineTyped } from "../pipeline.ts";
import type { DiagnosticCollector } from "../diagnostics/collector.ts";

type Stage = "ast" | "resolved-ast" | "typed-ast" | "bytecode" | "c" | "wasm";

const STAGES: readonly Stage[] = [
  "ast",
  "resolved-ast",
  "typed-ast",
  "bytecode",
  "c",
  "wasm",
] as const;

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
    case "ast":          return runStage(opts, file, runAst);
    case "resolved-ast": return runStage(opts, file, runResolvedAst);
    case "typed-ast":    return runStage(opts, file, runTypedAst);
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
