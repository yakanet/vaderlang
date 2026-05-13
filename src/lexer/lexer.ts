// Position tracking is JS-string code-unit accurate — exact for ASCII source,
// slightly skewed for non-ASCII content inside strings/chars/comments. The LSP
// boundary translates to UTF-16 column counts when needed.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Position, Span } from "../diagnostics/diagnostic.ts";
import { LEXER, type LexerCode } from "../diagnostics/codes.ts";
import { isFloatSuffix, isIntSuffix, lookupKeyword } from "./keywords.ts";
import type { Token, TokenKind } from "./token.ts";

export interface LexResult {
  readonly tokens: readonly Token[];
}

export function tokenize(
  source: string,
  file: string,
  diagnostics: DiagnosticCollector,
): LexResult {
  return { tokens: new Lexer(source, file, diagnostics).run() };
}

interface InterpFrame {
  // Brace depth from the start of THIS interpolation. Closes when it returns
  // to 0 on `}`.
  braceDepth: number;
  // The string mode to resume on closing.
  triple: boolean;
}

const SUPPRESS_AFTER: ReadonlySet<TokenKind> = new Set<TokenKind>([
  "plus", "minus", "star", "slash", "percent",
  "amp", "pipe", "caret", "shl", "shr",
  "eq", "neq", "lt", "lte", "gt", "gte",
  "and_and", "or_or",
  "range_excl", "range_incl", "dotdotdot",
  "assign", "plus_assign", "minus_assign", "star_assign", "slash_assign", "percent_assign",
  "colon", "arrow", "fat_arrow",
  "comma",
  // `T ::\n    A | B | C` — allow the RHS of a `::` / `:=` binding to
  // wrap onto the next line. Mirrors the existing pipe / arrow / colon
  // continuation so multi-line union declarations read cleanly.
  "decl_const", "decl_var",
]);

// Tokens that "eat" a preceding newline — when this token is emitted
// and the previous token is a `newline`, the newline is dropped. Lets
// type-position `|` / `&` (and a few other binary operators) appear as
// leading tokens on a new line :
//   T ::
//       | A
//       | B
//       | C
// without the parser having to thread newline-skipping through every
// continuation. Mirrors how `decl_const` etc. in SUPPRESS_AFTER drop
// the newline immediately after themselves.
const SUPPRESS_BEFORE: ReadonlySet<TokenKind> = new Set<TokenKind>([
  "pipe", "amp",
]);

const TWO_CHAR_OPS: ReadonlyMap<string, TokenKind> = new Map([
  ["==", "eq"], ["!=", "neq"], ["<=", "lte"], [">=", "gte"],
  ["&&", "and_and"], ["||", "or_or"], ["<<", "shl"], [">>", "shr"],
  ["->", "arrow"], ["=>", "fat_arrow"], ["::", "decl_const"], [":=", "decl_var"],
  ["+=", "plus_assign"], ["-=", "minus_assign"], ["*=", "star_assign"],
  ["/=", "slash_assign"], ["%=", "percent_assign"],
]);

const ONE_CHAR_OPS: ReadonlyMap<string, TokenKind> = new Map([
  ["+", "plus"], ["-", "minus"], ["*", "star"], ["/", "slash"], ["%", "percent"],
  ["&", "amp"], ["|", "pipe"], ["^", "caret"], ["~", "tilde"],
  ["<", "lt"], [">", "gt"], ["!", "bang"], ["=", "assign"],
  ["?", "question"], ["@", "at"], ["$", "dollar"],
  [":", "colon"], [",", "comma"], ["."  , "dot"],
]);

const BASE_PREFIXES: ReadonlyMap<string, 2 | 8 | 16> = new Map([
  ["x", 16], ["X", 16],
  ["b", 2], ["B", 2],
  ["o", 8], ["O", 8],
]);

class Lexer {
  private readonly src: string;
  private readonly file: string;
  private readonly diags: DiagnosticCollector;

  private pos = 0;
  private line = 1;
  private col = 1;

  private readonly tokens: Token[] = [];

  // Depth of unclosed `(` and `[` (NOT `{`) — newlines absorbed inside.
  private parenDepth = 0;
  private readonly interpStack: InterpFrame[] = [];
  private lastKind: TokenKind | null = null;

  constructor(src: string, file: string, diags: DiagnosticCollector) {
    this.src = src;
    this.file = file;
    this.diags = diags;
  }

  run(): Token[] {
    if (this.peek() === "﻿") this.advance(1);

    if (this.line === 1 && this.peek() === "#" && this.peekAt(1) === "!") {
      while (this.pos < this.src.length && this.peek() !== "\n") this.advance(1);
    }

    while (this.pos < this.src.length) this.lexOne();

    const here = this.posHere();
    this.tokens.push({ kind: "eof", text: "", span: { start: here, end: here } });
    return this.tokens;
  }

  // ---------------------------------------------------------------- main

  private lexOne(): void {
    const interp = this.interpStack.length > 0
      ? this.interpStack[this.interpStack.length - 1]!
      : null;

    this.skipInsignificantSpace();
    if (this.pos >= this.src.length) return;

    if (interp !== null && this.peek() === "}" && interp.braceDepth === 0) {
      const start = this.posHere();
      this.advance(1);
      this.push("interp_close", "}", start);
      this.interpStack.pop();
      this.lexStringBody(interp.triple, /*raw*/ false);
      return;
    }

    const c = this.peek();

    if (c === "\n" || c === "\r") {
      this.handleNewline();
      return;
    }
    if (c === "/" && this.peekAt(1) === "/") {
      while (this.pos < this.src.length && this.peek() !== "\n") this.advance(1);
      return;
    }
    if (c === "/" && this.peekAt(1) === "*") {
      this.lexBlockComment();
      return;
    }
    if (c === "r" && this.peekAt(1) === '"') {
      this.lexString({ raw: true });
      return;
    }
    if (isIdentStart(c)) {
      this.lexIdent();
      return;
    }
    if (isDigit(c)) {
      this.lexNumber();
      return;
    }
    if (c === "'") {
      this.lexChar();
      return;
    }
    if (c === '"') {
      this.lexString({ raw: false });
      return;
    }
    if (this.tryLexOperator(interp)) return;

    if (c === "\\") {
      const start = this.posHere();
      this.advance(1);
      this.error("L0007", { start, end: this.posHere() });
      return;
    }

    const start = this.posHere();
    this.advance(1);
    this.error("L0001", { start, end: this.posHere() });
  }

  // ------------------------------------------------------------ helpers

  private peek(): string { return this.src[this.pos] ?? ""; }
  private peekAt(n: number): string { return this.src[this.pos + n] ?? ""; }

  private advance(n: number): void {
    for (let i = 0; i < n && this.pos < this.src.length; i++) {
      const code = this.src.charCodeAt(this.pos);
      if (code === 10) {                        // '\n'
        this.line++;
        this.col = 1;
      } else if (code >= 0xDC00 && code <= 0xDFFF) {
        // Trailing surrogate of a non-BMP codepoint — already counted on the
        // leading surrogate. Skip so col tracks codepoints, matching the
        // Vader self-host lexer (which counts UTF-8 leading bytes only).
      } else {
        this.col++;
      }
      this.pos++;
    }
  }

  private posHere(): Position {
    return { file: this.file, offset: this.pos, line: this.line, column: this.col };
  }

  private skipInsignificantSpace(): void {
    while (this.pos < this.src.length) {
      const c = this.peek();
      if (c === " " || c === "\t") { this.advance(1); continue; }
      if ((c === "\n" || c === "\r") && this.interpStack.length > 0) {
        this.advance(1);
        continue;
      }
      break;
    }
  }

  /** Single point where every token enters the stream — keeps `lastKind` honest. */
  private push(kind: TokenKind, text: string, start: Position, extra: Partial<Token> = {}): void {
    // `SUPPRESS_BEFORE` retroactively drops a just-emitted newline so a
    // leading `|` / `&` on the next line continues the previous
    // expression. The check stays cheap : one `lastKind` test, one
    // array pop in the rare hit.
    if (SUPPRESS_BEFORE.has(kind) && this.lastKind === "newline") {
      this.tokens.pop();
      this.lastKind = this.tokens.length === 0 ? null : this.tokens[this.tokens.length - 1]!.kind;
    }
    this.tokens.push({ kind, text, span: { start, end: this.posHere() }, ...extra });
    this.lastKind = kind;
  }

  private handleNewline(): void {
    if (this.peek() === "\r") this.advance(1);
    if (this.peek() === "\n") this.advance(1);

    if (this.parenDepth > 0) return;
    if (this.lastKind === null || this.lastKind === "newline") return;
    if (SUPPRESS_AFTER.has(this.lastKind)) return;

    // Emit only when actually needed — span starts where the run of newlines
    // started, but for our purposes a zero-width point is enough.
    const here = this.posHere();
    this.tokens.push({
      kind: "newline",
      text: "\n",
      span: { start: here, end: here },
    });
    this.lastKind = "newline";
  }

  // ----------------------------------------------------------- comments

  private lexBlockComment(): void {
    const start = this.posHere();
    this.advance(2);
    let depth = 1;
    while (this.pos < this.src.length && depth > 0) {
      if (this.peek() === "/" && this.peekAt(1) === "*") {
        this.advance(2); depth++; continue;
      }
      if (this.peek() === "*" && this.peekAt(1) === "/") {
        this.advance(2); depth--; continue;
      }
      this.advance(1);
    }
    if (depth > 0) this.error("L0003", { start, end: this.posHere() });
  }

  // --------------------------------------------------------- identifiers

  private lexIdent(): void {
    const start = this.posHere();
    while (this.pos < this.src.length && isIdentContinue(this.peek())) this.advance(1);
    const text = this.src.slice(start.offset, this.pos);
    const kw = lookupKeyword(text);
    this.push(kw ?? "ident", text, start);
  }

  // ------------------------------------------------------------- numbers

  private lexNumber(): void {
    const start = this.posHere();
    let isFloat = false;
    let base: 2 | 8 | 10 | 16 = 10;

    const prefixBase = this.peek() === "0" ? BASE_PREFIXES.get(this.peekAt(1)) : undefined;
    if (prefixBase !== undefined) {
      this.advance(2);
      base = prefixBase;
      this.consumeDigits(base, start);
    } else {
      this.consumeDigits(10, start);
      if (this.peek() === "." && isDigit(this.peekAt(1))) {
        isFloat = true;
        this.advance(1);
        this.consumeDigits(10, start);
      }
      if (this.peek() === "e" || this.peek() === "E") {
        isFloat = true;
        this.advance(1);
        if (this.peek() === "+" || this.peek() === "-") this.advance(1);
        if (!isDigit(this.peek())) {
          this.error("L0006", { start, end: this.posHere() }, "exponent has no digits");
        }
        this.consumeDigits(10, start);
      }
    }

    const { suffix, hasSeparator } = this.readNumericSuffix();
    const suffixLen = suffix !== null ? suffix.length + (hasSeparator ? 1 : 0) : 0;

    if (suffix !== null && !isIntSuffix(suffix) && !isFloatSuffix(suffix)) {
      const suffStart: Position = {
        file: this.file,
        offset: this.pos - suffix.length,
        line: this.line,
        column: this.col - suffix.length,
      };
      this.error("L0006", { start: suffStart, end: this.posHere() }, `unknown numeric suffix "${suffix}"`);
    }

    if (suffix !== null && isFloatSuffix(suffix)) isFloat = true;
    if (suffix !== null && isIntSuffix(suffix) && isFloat) {
      this.error("L0006", { start, end: this.posHere() }, `integer suffix "${suffix}" on a float literal`);
    }

    const text = this.src.slice(start.offset, this.pos);
    const digitsText = (suffix !== null ? text.slice(0, text.length - suffixLen) : text).replaceAll("_", "");

    const kind: TokenKind = isFloat ? "float_literal" : "int_literal";
    let parsedValue: { floatValue?: number; intValue?: bigint };
    if (isFloat) {
      const v = Number.parseFloat(digitsText);
      if (Number.isNaN(v)) this.error("L0006", { start, end: this.posHere() }, "could not parse float literal");
      parsedValue = { floatValue: v };
    } else {
      try {
        // BigInt() handles 0x/0o/0b prefixes natively; digitsText carries the prefix.
        parsedValue = { intValue: BigInt(digitsText) };
      } catch {
        this.error("L0006", { start, end: this.posHere() }, "could not parse integer literal");
        parsedValue = { intValue: 0n };
      }
    }
    this.push(kind, text, start, {
      ...parsedValue,
      ...(suffix !== null ? { numericSuffix: suffix } : {}),
    });
  }

  private readNumericSuffix(): { suffix: string | null; hasSeparator: boolean } {
    if (this.peek() === "_" && isIdentStart(this.peekAt(1))) {
      this.advance(1);
      const suffStart = this.pos;
      while (isIdentContinue(this.peek())) this.advance(1);
      return { suffix: this.src.slice(suffStart, this.pos), hasSeparator: true };
    }
    if (isIdentStart(this.peek())) {
      const suffStart = this.pos;
      while (isIdentContinue(this.peek())) this.advance(1);
      return { suffix: this.src.slice(suffStart, this.pos), hasSeparator: false };
    }
    return { suffix: null, hasSeparator: false };
  }

  private consumeDigits(base: 2 | 8 | 10 | 16, errAnchor: Position): void {
    let lastWasUnderscore = false;
    let consumedAny = false;
    let firstChar = true;
    while (this.pos < this.src.length) {
      const c = this.peek();
      if (c === "_") {
        // Leave `_<ident>` for readNumericSuffix when the char after `_` is an
        // ident-start but not a digit in the current base (e.g. `100_u32`).
        // If it IS a valid digit (e.g. `0xFF_FF`), treat it as a separator.
        const next = this.peekAt(1);
        if (next !== "_" && isIdentStart(next) && !isDigitInBase(next, base)) break;
        if (firstChar || lastWasUnderscore) {
          this.error("L0006", { start: errAnchor, end: this.posHere() }, "underscore not allowed here");
        }
        lastWasUnderscore = true;
        firstChar = false;
        this.advance(1);
        continue;
      }
      if (isDigitInBase(c, base)) {
        consumedAny = true;
        lastWasUnderscore = false;
        firstChar = false;
        this.advance(1);
        continue;
      }
      break;
    }
    if (lastWasUnderscore) {
      this.error("L0006", { start: errAnchor, end: this.posHere() }, "trailing underscore in numeric literal");
    }
    if (!consumedAny && base !== 10) {
      this.error("L0006", { start: errAnchor, end: this.posHere() }, "expected digits after base prefix");
    }
  }

  // -------------------------------------------------------------- chars

  private lexChar(): void {
    const start = this.posHere();
    this.advance(1);

    if (this.peek() === "'") {
      this.advance(1);
      this.error("L0005", { start, end: this.posHere() }, "character literal cannot be empty");
      this.push("char_literal", this.src.slice(start.offset, this.pos), start, { charValue: 0 });
      return;
    }

    let codepoint = 0;
    if (this.peek() === "\\") {
      codepoint = this.lexEscape();
    } else if (this.peek() === "\n" || this.pos >= this.src.length) {
      this.error("L0005", { start, end: this.posHere() }, "unterminated character literal");
      this.push("char_literal", this.src.slice(start.offset, this.pos), start, { charValue: 0 });
      return;
    } else {
      codepoint = this.peek().codePointAt(0) ?? 0;
      this.advance(codepoint > 0xFFFF ? 2 : 1);
    }

    if (this.peek() !== "'") {
      this.error("L0005", { start, end: this.posHere() }, "character literal must contain exactly one codepoint");
      while (this.pos < this.src.length && this.peek() !== "'" && this.peek() !== "\n") this.advance(1);
      if (this.peek() === "'") this.advance(1);
    } else {
      this.advance(1);
    }

    this.push("char_literal", this.src.slice(start.offset, this.pos), start, { charValue: codepoint });
  }

  // ------------------------------------------------------------ strings

  private lexString(opts: { raw: boolean }): void {
    const start = this.posHere();
    if (opts.raw) this.advance(1);
    this.advance(1);

    let triple = false;
    if (this.peek() === '"' && this.peekAt(1) === '"') {
      triple = true;
      this.advance(2);
      if (this.peek() === "\r" && this.peekAt(1) === "\n") this.advance(2);
      else if (this.peek() === "\n") this.advance(1);
    }

    this.push("string_begin", this.src.slice(start.offset, this.pos), start);
    this.lexStringBody(triple, opts.raw);
  }

  /** Drive the body of a string literal. Handles raw/escape/interpolation in one place. */
  private lexStringBody(triple: boolean, raw: boolean): void {
    let partStart = this.posHere();
    const buf: string[] = [];
    const flush = (): void => {
      if (buf.length === 0) return;
      const text = buf.join("");
      this.tokens.push({
        kind: "string_part",
        text,
        span: { start: partStart, end: this.posHere() },
        stringValue: text,
      });
      this.lastKind = "string_part";
      buf.length = 0;
    };

    while (this.pos < this.src.length) {
      const c = this.peek();

      if (triple
        ? (c === '"' && this.peekAt(1) === '"' && this.peekAt(2) === '"')
        : c === '"'
      ) {
        flush();
        const closeStart = this.posHere();
        this.advance(triple ? 3 : 1);
        this.push("string_end", triple ? '"""' : '"', closeStart);
        return;
      }

      if (!triple && c === "\n") {
        this.error("L0002", { start: partStart, end: this.posHere() });
        flush();
        this.push("string_end", "", this.posHere());
        return;
      }

      if (!raw && c === "$" && this.peekAt(1) === "{") {
        flush();
        const opStart = this.posHere();
        this.advance(2);
        this.push("interp_open", "${", opStart);
        this.interpStack.push({ braceDepth: 0, triple });
        return;
      }
      if (!raw && c === "$" && isIdentStart(this.peekAt(1))) {
        flush();
        const opStart = this.posHere();
        this.advance(1);
        this.push("interp_open", "$", opStart);
        this.lexIdent();
        const here = this.posHere();
        this.push("interp_close", "", here);
        partStart = here;
        continue;
      }

      if (!raw && c === "\\") {
        buf.push(String.fromCodePoint(this.lexEscape()));
        continue;
      }

      buf.push(c);
      this.advance(1);
    }

    this.error("L0002", { start: partStart, end: this.posHere() });
    flush();
    this.push("string_end", "", this.posHere());
  }

  /** Decode `\X` escape; returns the codepoint. */
  private lexEscape(): number {
    const escStart = this.posHere();
    this.advance(1);
    const c = this.peek();
    if (c === "") {
      this.error("L0004", { start: escStart, end: this.posHere() }, "incomplete escape sequence");
      return 0;
    }
    this.advance(1);
    switch (c) {
      case "n": return 0x0A;
      case "t": return 0x09;
      case "r": return 0x0D;
      case "\\": return 0x5C;
      case "'": return 0x27;
      case '"': return 0x22;
      case "$": return 0x24;
      case "0": return 0x00;
      case "u": return this.lexUnicodeEscape(escStart);
      default:
        this.error("L0004", { start: escStart, end: this.posHere() }, `unknown escape \\${c}`);
        return c.codePointAt(0) ?? 0;
    }
  }

  private lexUnicodeEscape(escStart: Position): number {
    if (this.peek() !== "{") {
      this.error("L0009", { start: escStart, end: this.posHere() }, "expected '{' after \\u");
      return 0;
    }
    this.advance(1);

    const hexStart = this.pos;
    while (this.pos < this.src.length && this.peek() !== "}") {
      if (!isHexDigit(this.peek())) {
        this.error("L0009", { start: escStart, end: this.posHere() }, "invalid hex digit in codepoint escape");
        while (this.pos < this.src.length && this.peek() !== "}") this.advance(1);
        break;
      }
      this.advance(1);
    }

    const hexLen = this.pos - hexStart;
    if (this.peek() === "}") this.advance(1);

    if (hexLen === 0 || hexLen > 6) {
      this.error("L0009", { start: escStart, end: this.posHere() }, "codepoint escape must have 1–6 hex digits");
      return 0;
    }

    const value = Number.parseInt(this.src.slice(hexStart, hexStart + hexLen), 16);
    if (value > 0x10FFFF) {
      this.error("L0009", { start: escStart, end: this.posHere() }, "codepoint exceeds U+10FFFF");
      return 0;
    }
    return value;
  }

  // ---------------------------------------------------------------- ops

  private tryLexOperator(interp: InterpFrame | null): boolean {
    const c = this.peek();
    const c2 = this.peekAt(1);

    if (c === "." && c2 === ".") {
      const c3 = this.peekAt(2);
      if (c3 === "<" || c3 === "=") {
        const start = this.posHere();
        this.advance(3);
        this.push(c3 === "<" ? "range_excl" : "range_incl", c + c2 + c3, start);
        return true;
      }
      if (c3 === ".") {
        const start = this.posHere();
        this.advance(3);
        this.push("dotdotdot", c + c2 + c3, start);
        return true;
      }
    }

    const two = TWO_CHAR_OPS.get(c + c2);
    if (two !== undefined) {
      const start = this.posHere();
      this.advance(2);
      this.push(two, c + c2, start);
      return true;
    }

    const one = ONE_CHAR_OPS.get(c);
    if (one !== undefined) {
      const start = this.posHere();
      this.advance(1);
      this.push(one, c, start);
      return true;
    }

    if (c === "(" || c === "[") {
      const start = this.posHere();
      this.advance(1);
      this.parenDepth++;
      this.push(c === "(" ? "lparen" : "lbracket", c, start);
      return true;
    }
    if (c === ")" || c === "]") {
      const start = this.posHere();
      this.advance(1);
      if (this.parenDepth > 0) this.parenDepth--;
      this.push(c === ")" ? "rparen" : "rbracket", c, start);
      return true;
    }
    if (c === "{") {
      const start = this.posHere();
      this.advance(1);
      this.push("lbrace", "{", start);
      if (interp !== null) interp.braceDepth++;
      return true;
    }
    if (c === "}") {
      // The interp-close case is dispatched in lexOne before reaching here.
      const start = this.posHere();
      this.advance(1);
      this.push("rbrace", "}", start);
      if (interp !== null && interp.braceDepth > 0) interp.braceDepth--;
      return true;
    }

    return false;
  }

  // --------------------------------------------------------- diagnostics

  private error(code: LexerCode, span: Span, extra?: string): void {
    const message = extra !== undefined ? `${LEXER[code]}: ${extra}` : LEXER[code];
    this.diags.emit({ severity: "error", code, message, primary: span });
  }
}

// -------------------------------------------------------------------- helpers

function isIdentStart(c: string): boolean {
  return (c >= "a" && c <= "z") || (c >= "A" && c <= "Z") || c === "_";
}

function isIdentContinue(c: string): boolean {
  return isIdentStart(c) || isDigit(c);
}

function isDigit(c: string): boolean {
  return c >= "0" && c <= "9";
}

function isHexDigit(c: string): boolean {
  return isDigit(c) || (c >= "a" && c <= "f") || (c >= "A" && c <= "F");
}

function isDigitInBase(c: string, base: 2 | 8 | 10 | 16): boolean {
  if (base === 2) return c === "0" || c === "1";
  if (base === 8) return c >= "0" && c <= "7";
  if (base === 10) return isDigit(c);
  return isHexDigit(c);
}

