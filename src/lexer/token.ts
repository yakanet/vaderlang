import type { Span } from "../diagnostics/diagnostic.ts";

/**
 * Every token kind in Vader. Each keyword and each operator gets its own kind
 * for exhaustive pattern matching downstream.
 */
export type TokenKind =
  // Identifiers and literals
  | "ident"
  | "int_literal"
  | "float_literal"
  | "char_literal"

  // String tokens. A single string literal produces a sequence:
  //   STRING_BEGIN  ( STRING_PART | INTERP_OPEN <expr...> INTERP_CLOSE )*  STRING_END
  | "string_begin"
  | "string_part"
  | "string_end"
  | "interp_open"
  | "interp_close"

  // Keywords
  | "kw_fn" | "kw_struct" | "kw_trait" | "kw_implements" | "kw_impl" | "kw_enum"
  | "kw_if" | "kw_else" | "kw_match" | "kw_is" | "kw_for" | "kw_in"
  | "kw_return" | "kw_defer" | "kw_break" | "kw_continue"
  | "kw_import" | "kw_as" | "kw_export"
  | "kw_true" | "kw_false" | "kw_null"
  | "kw_self"
  | "kw_const"

  // Operators
  | "plus" | "minus" | "star" | "slash" | "percent"
  | "amp" | "pipe" | "caret" | "tilde" | "shl" | "shr"
  | "eq" | "neq" | "lt" | "lte" | "gt" | "gte"
  | "and_and" | "or_or" | "bang"
  | "assign"        // =
  | "plus_assign"   // +=
  | "minus_assign"  // -=
  | "star_assign"   // *=
  | "slash_assign"  // /=
  | "percent_assign"// %=
  | "decl_const"    // ::
  | "decl_var"      // :=
  | "range_excl"    // ..<
  | "range_incl"    // ..=
  | "dotdotdot"     // ...   (struct spread)
  | "question"      // ?
  | "arrow"         // ->
  | "fat_arrow"     // =>  (reserved for future use)
  | "at"            // @
  | "dollar"        // $   (reserved at top level for generic parameters)

  // Punctuation
  | "lparen" | "rparen"
  | "lbracket" | "rbracket"
  | "lbrace" | "rbrace"
  | "comma" | "dot" | "colon"

  // Layout
  | "newline"
  | "eof";

/**
 * One token. The `text` field is the raw source slice. Literal tokens carry
 * their parsed value alongside.
 */
export interface Token {
  readonly kind: TokenKind;
  readonly text: string;
  readonly span: Span;
  readonly intValue?: bigint;
  readonly floatValue?: number;
  readonly charValue?: number;
  readonly stringValue?: string;
  readonly numericSuffix?: string;
}
