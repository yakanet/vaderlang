import { resolve } from "node:path";
import type { Diagnostic } from "./diagnostic.ts";

export function renderText(d: Diagnostic, source: string): string {
  const head = `${d.severity}[${d.code}]: ${d.message}`;
  const loc = `  --> ${d.primary.start.file}:${d.primary.start.line}:${d.primary.start.column}`;
  const snippet = renderSnippet(d.primary, source);
  const notes = (d.notes ?? []).map((n) => `  = note: ${n}`);
  const fixes = (d.fixes ?? []).map((f) => `  = help: ${f.description}`);
  return [head, loc, snippet, ...notes, ...fixes].filter((s) => s.length > 0).join("\n");
}

export function renderAllText(
  diagnostics: readonly Diagnostic[],
  sources: ReadonlyMap<string, string>,
): string {
  const blocks: string[] = [];
  for (const d of diagnostics) {
    blocks.push(renderText(d, sources.get(d.primary.start.file) ?? ""));
  }
  return blocks.join("\n\n");
}

export function renderAllTextSingle(
  diagnostics: readonly Diagnostic[],
  file: string,
  source: string,
): string {
  return renderAllText(diagnostics, new Map([[resolve(file), source]]));
}

export function renderAllJson(diagnostics: readonly Diagnostic[]): string {
  return JSON.stringify(diagnostics, null, 2);
}

/** Render a runtime trap with the same source-context format the diagnostic
 *  renderer uses. Caller supplies the location and the source text ; the
 *  caret points at the column. */
export function renderRuntimeTrap(
  message: string, file: string, line: number, column: number, source: string,
): string {
  const head = `error: ${message}`;
  const loc = `  --> ${file}:${line}:${column}`;
  const span = {
    start: { line, column, offset: 0 },
    end:   { line, column: column + 1, offset: 0 },
  };
  const snippet = renderSnippet(span, source);
  return [head, loc, snippet].filter((s) => s.length > 0).join("\n");
}

const CONTEXT = 2;

function renderSnippet(span: { start: { line: number; column: number; offset: number }; end: { line: number; column: number; offset: number } }, source: string): string {
  if (source.length === 0) return "";
  const lines = source.split("\n");
  const lineIdx = span.start.line - 1;
  if (lineIdx < 0 || lineIdx >= lines.length) return "";

  const startIdx = Math.max(0, lineIdx - CONTEXT);
  const endIdx = Math.min(lines.length - 1, lineIdx + CONTEXT);
  const gutterWidth = String(endIdx + 1).length;
  const gutter = " ".repeat(gutterWidth);

  const startCol = span.start.column;
  const endCol =
    span.end.line === span.start.line ? span.end.column : lines[lineIdx]!.length + 1;
  const underlineLen = Math.max(1, endCol - startCol);

  const out: string[] = [`${gutter} |`];
  for (let i = startIdx; i <= endIdx; i++) {
    const num = String(i + 1).padStart(gutterWidth);
    out.push(`${num} | ${lines[i]}`);
    if (i === lineIdx) {
      out.push(`${gutter} | ${" ".repeat(Math.max(0, startCol - 1))}${"^".repeat(underlineLen)}`);
    }
  }
  return out.join("\n");
}
