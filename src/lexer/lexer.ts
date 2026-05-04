// Phase 1.1 — Lexer.
//
// Will produce a stream of tokens from a Vader source file.
// Currently a stub. See TODO.md §1.1 for the full task list.

import type { Span } from "../diagnostics/diagnostic.ts";

export type TokenKind =
  | "EOF"
  | "IDENT"
  | "INT"
  | "FLOAT"
  | "STRING_PART"
  | "INTERP_OPEN"
  | "INTERP_CLOSE"
  | "CHAR"
  | "KEYWORD"
  | "OP"
  | "NEWLINE";

export interface Token {
  readonly kind: TokenKind;
  readonly value: string;
  readonly span: Span;
}

export function tokenize(_source: string, _file: string): Token[] {
  throw new Error("lexer: not yet implemented");
}
