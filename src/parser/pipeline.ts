import { tokenize } from "../lexer/lexer.ts";
import { parse } from "./parser.ts";
import { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Token } from "../lexer/token.ts";
import type { Program } from "./ast.ts";

export interface ParsedSource {
  readonly program: Program;
  readonly tokens: readonly Token[];
  readonly diagnostics: DiagnosticCollector;
}

export function parseSource(source: string, file: string): ParsedSource {
  const diagnostics = new DiagnosticCollector();
  const { tokens } = tokenize(source, file, diagnostics);
  const { program } = parse(tokens, file, diagnostics);
  return { program, tokens, diagnostics };
}
