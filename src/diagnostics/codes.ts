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

export const TYPECHECK = {
  T3001: "type mismatch",
  T3002: "expected an expression of a known type",
  T3003: "wrong number of arguments",
  T3004: "unknown named argument",
  T3005: "missing required argument",
  T3006: "trait not satisfied",
  T3007: "expression is not callable",
  T3008: "expression is not indexable",
  T3009: "field does not exist on this type",
  T3010: "invalid cast",
  T3011: "`?` requires a union with an `Error` variant",
  T3012: "`?` cannot propagate this error from the enclosing function",
  T3013: "non-exhaustive match",
  T3014: "unreachable match arm",
  T3015: "`break` / `continue` only allowed inside a loop",
  T3016: "`self` only valid inside a method body",
  T3017: "operator not defined for these operand types",
  T3018: "string interpolation expression must implement `Display`",
  T3019: "condition must be `bool`",
  T3020: "function body returns a value incompatible with its declared return type",
  T3021: "generic argument count mismatch",
  T3022: "cyclic type alias",
  T3023: "use of `Self` outside a trait or impl context",
  T3024: "function signature must be fully annotated",
  T3025: "named argument duplicates a positional one",
  T3026: "type does not have generic parameters",
} as const;

export type TypecheckCode = keyof typeof TYPECHECK;

export const COMPTIME = {
  C4001: "expression cannot be evaluated at compile time",
  C4002: "comptime evaluation panicked",
  C4003: "function is not callable in comptime context",
  C4004: "comptime call stack overflow",
  C4005: "comptime division by zero",
  C4006: "@file path could not be read",
  C4007: "comptime value has incompatible type",
  C4008: "ENV access requires `--allow-env`",
  C4009: "comptime evaluation depends on itself",
  C4010: "comptime index out of bounds",
  C4011: "comptime feature not yet supported",
  C4012: "@file expects a single string-literal argument",
  C4013: "decorator arguments must be string literals at comptime",
} as const;

export type ComptimeCode = keyof typeof COMPTIME;

export const BACKEND = {
  B5001: "language feature not yet supported by the backend",
} as const;

export type BackendCode = keyof typeof BACKEND;
