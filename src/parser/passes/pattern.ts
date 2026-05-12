// Pattern parsers — for `match` arms and `is X` checks. The grammar covers
//   - `.Variant` (enum-variant pattern)
//   - `is T` / `is T { …struct fields… } as binder` (type-tag + optional
//     destructure + optional rebind)
//   - `_` (wildcard)
//   - `name` (binding)
//   - `[a, b, …]` (tuple destructure)
// Struct-pattern fields accept either a literal value match or a rebinding
// (`{ field: rebound }` or shorthand `{ field }` ⇒ binding to same-name local).

import type { Token } from "../../lexer/token.ts";
import type * as A from "../ast.ts";
import { UNASSIGNED_NODE_ID } from "../ast.ts";
import type { Parser } from "../parser.ts";
import { describeToken } from "../parser.ts";

import { parseExpr } from "./expr.ts";
import { parseType } from "./type.ts";

export function parsePattern(p: Parser): A.Pattern {
  const t = p.peek();
  if (t.kind === "dot") {
    p.advance(); // consume `.`
    const variantTok = p.expect("ident", "variant name after `.`");
    return {
      kind: "EnumVariantPattern",
      id: UNASSIGNED_NODE_ID, span: { start: t.span.start, end: variantTok.span.end },
      variant: variantTok.text,
    };
  }
  if (t.kind === "kw_is") {
    p.advance();
    let type: A.TypeExpr;
    if (p.check("dot")) {
      // `is .Foo` — implicit-dot variant, resolved against the match
      // scrutinee at typecheck time. Plain `parseType` would reject the
      // leading dot, so we synthesise a flagged `NamedType` directly.
      const dotTok = p.advance();
      const variantTok = p.expect("ident", "variant name after `.`");
      type = {
        kind: "IdentExpr",
        id: UNASSIGNED_NODE_ID, span: { start: dotTok.span.start, end: variantTok.span.end },
        name: variantTok.text,
        implicitDot: true,
      };
    } else {
      type = parseType(p);
    }
    let inner: A.Pattern | null = null;
    if (p.check("lbrace")) {
      inner = parseStructPattern(p);
    }
    let bindAs: string | null = null;
    if (p.match("kw_as") !== null) {
      bindAs = p.expect("ident", "binding name after `as`").text;
    }
    return {
      kind: "IsPattern",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(t, p.peek(-1)),
      type,
      inner,
      bindAs,
    };
  }
  if (t.kind === "ident" && t.text === "_") {
    p.advance();
    return { kind: "WildcardPattern", id: UNASSIGNED_NODE_ID, span: t.span };
  }
  if (t.kind === "ident") {
    p.advance();
    return { kind: "BindingPattern", id: UNASSIGNED_NODE_ID, span: t.span, name: t.text };
  }
  if (t.kind === "lbracket") {
    return parseTuplePattern(p);
  }
  p.error("P1007", t.span, `got ${describeToken(t)}`);
  p.advance();
  return { kind: "WildcardPattern", id: UNASSIGNED_NODE_ID, span: t.span };
}

function parseTuplePattern(p: Parser): A.TuplePattern {
  const start = p.advance(); // [
  p.skipNewlines();
  const elements: A.Pattern[] = [];
  if (!p.check("rbracket")) {
    while (true) {
      p.skipNewlines();
      if (p.check("rbracket")) break;
      elements.push(parsePattern(p));
      p.skipNewlines();
      if (p.match("comma") === null) break;
      p.skipNewlines();
    }
  }
  const end = p.expect("rbracket", "`]` to close tuple pattern");
  if (elements.length < 2) {
    p.error("P1022", p.spanOf(start, end));
  }
  return {
    kind: "TuplePattern",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(start, end),
    elements,
  };
}

function parseStructPattern(p: Parser): A.StructPattern {
  const start = p.expect("lbrace", "`{` to open struct pattern");
  p.skipNewlines();
  const fields: A.StructPatternField[] = [];
  while (!p.check("rbrace") && !p.check("eof")) {
    const fStart = p.peek();
    const name = p.expect("ident", "field name in struct pattern");
    let value: A.PatternFieldValue;
    if (p.match("colon") !== null) {
      // either literal value match or rebinding
      if (p.check("ident") && !isLiteralStart(p.peek(1))) {
        const bindTok = p.advance();
        value = { kind: "binding", id: UNASSIGNED_NODE_ID, name: bindTok.text, span: bindTok.span };
      } else {
        const v = parseExpr(p, 0);
        value = { kind: "literal", value: v };
      }
    } else {
      // shorthand: `{ x, y }` ⇒ binding to fields with same name
      value = { kind: "binding", id: UNASSIGNED_NODE_ID, name: name.text, span: name.span };
    }
    fields.push({
      id: UNASSIGNED_NODE_ID, span: p.spanOf(fStart, p.peek(-1)),
      name: name.text,
      nameSpan: name.span,
      value,
    });
    p.skipNewlines();
    if (p.match("comma") === null) break;
    p.skipNewlines();
  }
  const end = p.expect("rbrace", "`}` to close struct pattern");
  return {
    kind: "StructPattern",
    id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: end.span.end },
    fields,
  };
}

function isLiteralStart(t: Token): boolean {
  return t.kind === "int_literal"
    || t.kind === "float_literal"
    || t.kind === "char_literal"
    || t.kind === "string_begin"
    || t.kind === "kw_true"
    || t.kind === "kw_false"
    || t.kind === "kw_null"
    || t.kind === "minus";
}
