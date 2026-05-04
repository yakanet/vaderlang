/**
 * Stable diagnostic code registry.
 *
 * Codes use a single-letter prefix per phase:
 *   L = lexer       (L0xxx)
 *   P = parser      (P1xxx)
 *   R = resolver    (R2xxx)
 *   T = type-check  (T3xxx)
 *   C = comptime    (C4xxx)
 *   B = backend     (B5xxx)
 *
 * Once published, codes are NEVER reused for a different meaning.
 */

export const LEXER = {
  L0001: "unexpected character",
  L0002: "unterminated string literal",
  L0003: "unterminated block comment",
  L0004: "invalid escape sequence",
  L0005: "invalid character literal",
  L0006: "malformed numeric literal",
  L0007: "stray backslash (Vader has no line continuation)",
  L0008: "shebang only allowed on first line",
  L0009: "invalid Unicode codepoint escape",
  L0010: "interpolation expression must follow `${`",
} as const;

export type LexerCode = keyof typeof LEXER;
