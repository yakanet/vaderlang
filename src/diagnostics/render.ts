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

export function renderAllJson(diagnostics: readonly Diagnostic[]): string {
  return JSON.stringify(diagnostics, null, 2);
}

// Single-line spans render with a caret underline; multi-line falls back to the
// start line only — adequate for MVP, can be enriched once we hit cases that
// span function bodies.
function renderSnippet(span: { start: { line: number; column: number; offset: number }; end: { line: number; column: number; offset: number } }, source: string): string {
  if (source.length === 0) return "";
  const lines = source.split("\n");
  const lineIdx = span.start.line - 1;
  if (lineIdx < 0 || lineIdx >= lines.length) return "";
  const line = lines[lineIdx]!;
  const lineNumStr = String(span.start.line);
  const gutter = " ".repeat(lineNumStr.length);

  const startCol = span.start.column;
  const endCol =
    span.end.line === span.start.line ? span.end.column : line.length + 1;
  const underlineLen = Math.max(1, endCol - startCol);

  return [
    `${gutter} |`,
    `${lineNumStr} | ${line}`,
    `${gutter} | ${" ".repeat(Math.max(0, startCol - 1))}${"^".repeat(underlineLen)}`,
  ].join("\n");
}
