export type Severity = "error" | "warning" | "info";

export interface Position {
  readonly file: string;
  readonly line: number;   // 1-based
  readonly column: number; // 1-based, in UTF-8 bytes
  readonly offset: number; // 0-based byte offset from start of file
}

export interface Span {
  readonly start: Position;
  readonly end: Position;
}

export interface Diagnostic {
  readonly severity: Severity;
  readonly message: string;
  readonly span: Span;
  readonly notes?: readonly string[];
}

export function formatDiagnostic(d: Diagnostic): string {
  const { severity, message, span, notes } = d;
  const head = `${severity}: ${message}`;
  const loc = `  --> ${span.start.file}:${span.start.line}:${span.start.column}`;
  const tail = notes && notes.length > 0
    ? notes.map((n) => `  note: ${n}`).join("\n")
    : "";
  return [head, loc, tail].filter((l) => l.length > 0).join("\n");
}
