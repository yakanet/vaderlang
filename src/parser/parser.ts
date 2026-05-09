// Phase 1.2 — Parser.
//
// Recursive descent for declarations / statements / types / patterns.
// Pratt parser for expressions with the precedence table from SPEC §3.
//
// All errors are emitted as structured diagnostics through the
// DiagnosticCollector — the parser never throws on user input. After an error
// it synchronizes on `}` / top-level keywords / NEWLINE so it can keep parsing.
//
// This file is the entry point + shared state. The recursive-descent rules
// for each concern live under `./passes/*.ts`. Token-stream helpers
// (peek/check/match/advance/expect/skipNewlines/error/spanOf) stay on the
// `Parser` class because every pass calls them.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import { PARSER, type ParserCode } from "../diagnostics/codes.ts";
import type { Token, TokenKind } from "../lexer/token.ts";
import type * as A from "./ast.ts";

import { parseProgram } from "./passes/program.ts";

export interface ParseResult {
  readonly program: A.Program;
}

export function parse(
  tokens: readonly Token[],
  file: string,
  diagnostics: DiagnosticCollector,
): ParseResult {
  return { program: parseProgram(new Parser(tokens, file, diagnostics)) };
}

// ============================================================================
// Parser state
// ============================================================================

export class Parser {
  readonly tokens: readonly Token[];
  readonly file: string;
  readonly diags: DiagnosticCollector;
  pos = 0;

  // True except inside the immediate condition expression of if/for/match/while
  allowStructLit = true;

  constructor(tokens: readonly Token[], file: string, diags: DiagnosticCollector) {
    this.tokens = tokens;
    this.file = file;
    this.diags = diags;
  }

  // ----------------------------------------------------------- token helpers

  peek(offset = 0): Token {
    return this.tokens[this.pos + offset] ?? this.tokens[this.tokens.length - 1]!;
  }

  check(kind: TokenKind, offset = 0): boolean {
    return this.peek(offset).kind === kind;
  }

  /** Consume if the next token matches; return the token or null. */
  match(kind: TokenKind): Token | null {
    if (this.check(kind)) {
      const t = this.peek();
      this.pos++;
      return t;
    }
    return null;
  }

  advance(): Token {
    const t = this.peek();
    if (this.pos < this.tokens.length - 1) this.pos++;
    return t;
  }

  /** Expect a token; if missing emit a diagnostic but do NOT advance. */
  expect(kind: TokenKind, what: string): Token {
    if (this.check(kind)) return this.advance();
    const t = this.peek();
    this.error("P1002", t.span, `expected ${what} (got ${describeToken(t)})`);
    return t; // synthetic — caller may use the span
  }

  skipNewlines(): void {
    while (this.check("newline")) this.pos++;
  }

  /** Tokens that mark the boundary of a top-level item — used for recovery. */
  atTopLevelStart(): boolean {
    const t = this.peek();
    if (t.kind === "kw_import" || t.kind === "kw_export") return true;
    // `name ::` or `Type implements …` patterns: detect by checking later tokens.
    if (t.kind === "ident") {
      const next = this.peek(1);
      if (next.kind === "decl_const" || next.kind === "kw_implements") return true;
    }
    if (t.kind === "at") return true; // decorator
    return false;
  }

  /** Skip until we reach a likely synchronization point. */
  syncToTopLevel(): void {
    while (this.peek().kind !== "eof" && !this.atTopLevelStart()) this.advance();
  }

  // -------------------------------------------------------- error reporting

  error(code: ParserCode, span: Span, message?: string): void {
    this.diags.emit({
      severity: "error",
      code,
      message: message !== undefined ? `${PARSER[code]}: ${message}` : PARSER[code],
      primary: span,
    });
  }

  spanOf(start: Token, end?: Token): Span {
    const last = end ?? this.peek(-1) ?? start;
    return { start: start.span.start, end: last.span.end };
  }
}

// ============================================================================
// Helpers
// ============================================================================

export function describeToken(t: Token): string {
  if (t.kind === "ident") return `\`${t.text}\``;
  if (t.kind === "int_literal" || t.kind === "float_literal") return t.text;
  if (t.kind === "newline") return "newline";
  if (t.kind === "eof") return "end of file";
  return t.text !== "" ? `\`${t.text}\`` : t.kind;
}

/**
 * Walk a type expression and collect any inline `$T` introductions that should
 * become typeParams of the surrounding function. Each unique name is added once.
 */
export function collectTypeParams(t: A.TypeExpr, out: A.TypeParam[]): void {
  switch (t.kind) {
    case "IdentExpr":
      // `$T` introductions carry the `isTypeParamIntro` flag (Layer 1.B.2).
      // Plain references (`T` after introduction, or unrelated names like `Foo`)
      // are skipped here ; the resolver looks them up in scope.
      if (t.isTypeParamIntro === true && !out.some((p) => p.name === t.name)) {
        out.push({ span: t.span, name: t.name, bound: null, isComptimeValue: false });
      }
      return;
    case "UnionType":
      for (const v of t.variants) collectTypeParams(v, out);
      return;
    case "FnTypeExpr":
      for (const p of t.params) collectTypeParams(p, out);
      if (t.returnType !== null) collectTypeParams(t.returnType, out);
      return;
    case "ArrayTypeExpr":
      collectTypeParams(t.element, out);
      return;
    case "SeqLitExpr":
      for (const e of t.elements) collectTypeParams(e as A.TypeExpr, out);
      return;
    case "GenericInstExpr":
      for (const a of t.typeArgs) collectTypeParams(a, out);
      return;
  }
}

/**
 * After consuming an ident, decide whether the following `{` opens a struct
 * literal. The shape we accept: `{ .field = ... }` — the very first significant
 * token inside the braces must be `.`.
 */
export function looksLikeStructLitBody(tokens: readonly Token[], posAfterLbrace: number): boolean {
  // posAfterLbrace points at the `{` itself (we haven't consumed it). The
  // body looks like a struct lit if the first non-whitespace token is `.`
  // (a field key) or `}` (an empty struct literal).
  let i = posAfterLbrace + 1;
  while (i < tokens.length) {
    const t = tokens[i]!;
    if (t.kind === "newline") { i++; continue; }
    return t.kind === "dot" || t.kind === "rbrace";
  }
  return false;
}
