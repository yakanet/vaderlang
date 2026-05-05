import type { TokenKind } from "./token.ts";

/** Map from raw keyword text to its dedicated token kind. */
export const KEYWORDS: Readonly<Record<string, TokenKind>> = {
  fn:         "kw_fn",
  enum:       "kw_enum",
  struct:     "kw_struct",
  trait:      "kw_trait",
  implements: "kw_implements",
  impl:       "kw_impl",
  if:         "kw_if",
  else:       "kw_else",
  match:      "kw_match",
  is:         "kw_is",
  for:        "kw_for",
  in:         "kw_in",
  return:     "kw_return",
  defer:      "kw_defer",
  break:      "kw_break",
  continue:   "kw_continue",
  import:     "kw_import",
  as:         "kw_as",
  private:    "kw_private",
  true:       "kw_true",
  false:      "kw_false",
  null:       "kw_null",
  type:       "kw_type",
  where:      "kw_where",
  self:       "kw_self",
};

export const INT_SUFFIXES = new Set<string>([
  "i8", "i16", "i32", "i64",
  "u8", "u16", "u32", "u64",
]);

export const FLOAT_SUFFIXES = new Set<string>(["f32", "f64"]);

export function isIntSuffix(s: string): boolean { return INT_SUFFIXES.has(s); }
export function isFloatSuffix(s: string): boolean { return FLOAT_SUFFIXES.has(s); }

export function lookupKeyword(text: string): TokenKind | null {
  return KEYWORDS[text] ?? null;
}
