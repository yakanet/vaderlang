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

export const PARSER = {
  P1001: "unexpected token",
  P1002: "expected token",
  P1003: "expected an expression",
  P1004: "expected a statement",
  P1005: "expected a type",
  P1006: "expected a declaration",
  P1007: "expected a pattern",
  P1008: "expected an identifier",
  P1009: "trailing comma allowed but list ended unexpectedly",
  P1010: "non-associative operator chained",
  P1011: "struct literal not allowed at the top level of a control-flow condition",
  P1012: "missing function body",
  P1013: "executable statement at top level (only declarations allowed)",
  P1014: "unknown decorator placement",
  P1015: "duplicate field name in struct literal",
  P1016: "expected a generic argument list",
  P1017: "missing newline between top-level declarations",
} as const;

export type ParserCode = keyof typeof PARSER;

export const RESOLVER = {
  R2001: "module not found",
  R2002: "import path is empty",
  R2003: "imported name not exported by module",
  R2004: "duplicate top-level symbol in module",
  R2005: "import cycle detected",
  R2006: "unresolved identifier",
  R2007: "unresolved type name",
  R2008: "private symbol cannot be accessed across module boundaries",
  R2009: "trait name does not refer to a trait",
  R2010: "decorator unknown to the compiler",
  R2011: "duplicate import binding",
  R2012: "imported symbol shadows a builtin",
  R2013: "self only valid as the first parameter of a method",
  R2014: "vader.json malformed or unreadable",
  R2015: "module folder is empty (no .vader files)",
} as const;

export type ResolverCode = keyof typeof RESOLVER;
