import type { GlobalOpts } from "../cli/options.ts";
import { parseSource } from "../parser/pipeline.ts";
import { renderAllJson, renderAllTextSingle } from "../diagnostics/render.ts";
import { resolveProject } from "../resolver/index.ts";
import { DiagnosticCollector } from "../diagnostics/collector.ts";

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
    default:
      console.error(`vader dump: stage "${stage}" not yet implemented`);
      return 2;
  }
}

interface StagePayload {
  readonly diagnostics: DiagnosticCollector;
  readonly output: unknown;
  /** JSON.stringify replacer; defaults to identity (with BigInt→`Nn`). */
  readonly replacer?: (key: string, value: unknown) => unknown;
}

async function runStage(
  opts: GlobalOpts, file: string,
  run: (file: string, source: string) => StagePayload,
): Promise<number> {
  const source = await Bun.file(file).text();
  const { diagnostics, output, replacer } = run(file, source);

  const sorted = diagnostics.sorted();
  if (sorted.length > 0) {
    console.error(opts.diagnostics === "json"
      ? renderAllJson(sorted)
      : renderAllTextSingle(sorted, file, source));
  }

  console.log(JSON.stringify(output, replacer ?? bigintReplacer, 2));
  return sorted.some((d) => d.severity === "error") ? 1 : 0;
}

function bigintReplacer(_k: string, v: unknown): unknown {
  return typeof v === "bigint" ? `${v.toString()}n` : v;
}

function runAst(file: string, source: string): StagePayload {
  const { program, diagnostics } = parseSource(source, file);
  const collector = new DiagnosticCollector();
  for (const d of diagnostics.sorted()) collector.emit(d);
  return { diagnostics: collector, output: program };
}

function runResolvedAst(file: string, _source: string): StagePayload {
  const diagnostics = new DiagnosticCollector();
  const project = resolveProject({ entryPath: file, diags: diagnostics });
  const output = {
    modules: [...project.modules.values()].map((p) => ({
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
  return { diagnostics, output };
}
