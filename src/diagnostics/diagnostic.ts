export type Severity = "error" | "warning" | "info" | "hint";

/**
 * A single point in source. Offset/line/column are JS-string code-unit
 * accurate, which matches UTF-8 bytes for ASCII source. The LSP boundary
 * translates to UTF-16 column counts when needed.
 */
export interface Position {
  readonly file: string;
  readonly offset: number;
  readonly line: number;
  readonly column: number;
}

/** Half-open span [start, end) in source. */
export interface Span {
  readonly start: Position;
  readonly end: Position;
}

/** Zero-length span at the start of `file` — placeholder for synthetic
 *  decls / diagnostics that aren't tied to a source location. */
export function zeroSpan(file: string): Span {
  const p: Position = { file, offset: 0, line: 1, column: 1 };
  return { start: p, end: p };
}

/** A secondary span attached to a diagnostic, with its own label. */
export interface LabeledSpan {
  readonly span: Span;
  readonly label: string;
}

/** A suggested edit. */
export interface Fix {
  readonly description: string;
  readonly edits: readonly { span: Span; replacement: string }[];
}

/**
 * Structured diagnostic emitted by any compiler phase. Designed to render well
 * both as terminal text and as JSON consumed by an LSP.
 */
export interface Diagnostic {
  readonly severity: Severity;
  readonly code: string;             // e.g. "L0001"
  readonly message: string;
  readonly primary: Span;
  readonly secondary?: readonly LabeledSpan[];
  readonly notes?: readonly string[];
  readonly fixes?: readonly Fix[];
}

/** Convenience constructor with sensible defaults. */
export function makeDiagnostic(args: {
  severity: Severity;
  code: string;
  message: string;
  primary: Span;
  secondary?: readonly LabeledSpan[];
  notes?: readonly string[];
  fixes?: readonly Fix[];
}): Diagnostic {
  return { ...args };
}
