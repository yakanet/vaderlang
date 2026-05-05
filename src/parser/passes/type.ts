// Type-expression parsing. Handles named types, generic instantiation, the
// `$T` typeParam shorthand, function types, array types, the `T!` Error-union
// shorthand, and pipe-separated unions.

import type * as A from "../ast.ts";
import type { Parser } from "../parser.ts";
import { describeToken } from "../parser.ts";

export function parseType(p: Parser): A.TypeExpr {
  let head = parseTypePrimary(p);
  // Postfix `!`: `T!` desugars to `T | Error` (SPEC §10).
  if (p.match("bang") !== null) {
    const bangEnd = p.peek(-1).span.end;
    head = {
      kind: "UnionType",
      span: { start: head.span.start, end: bangEnd },
      variants: [head, { kind: "NamedType", span: { start: bangEnd, end: bangEnd }, name: "Error" }],
    };
  }
  // Union: `T | U | V`
  if (p.check("pipe")) {
    const variants: A.TypeExpr[] = [head];
    const startTok = head;
    while (p.match("pipe") !== null) {
      variants.push(parseTypePrimary(p));
    }
    const last = variants[variants.length - 1]!;
    head = {
      kind: "UnionType",
      span: { start: startTok.span.start, end: last.span.end },
      variants,
    };
  }
  return head;
}

function parseTypePrimary(p: Parser): A.TypeExpr {
  const t = p.peek();
  if (t.kind === "dollar") {
    p.advance();
    const name = p.expect("ident", "type parameter name after `$`");
    return { kind: "TypeParamType", span: p.spanOf(t, name), name: name.text };
  }
  if (t.kind === "kw_fn") {
    return parseFnType(p);
  }
  if (t.kind === "lbracket") {
    const start = p.advance();
    const inner = parseType(p);
    const end = p.expect("rbracket", "`]` to close array type");
    return {
      kind: "ArrayTypeExpr",
      span: p.spanOf(start, end),
      element: inner,
    };
  }
  if (t.kind === "kw_null") {
    p.advance();
    return { kind: "NamedType", span: t.span, name: "null" };
  }
  if (t.kind === "kw_type") {
    // `type` as a type bound: `(T: type)` — the metatype.
    p.advance();
    return { kind: "NamedType", span: t.span, name: "type" };
  }
  if (t.kind === "ident") {
    const name = p.advance();
    const named: A.NamedType = { kind: "NamedType", span: name.span, name: name.text };
    // Generic instantiation: `Foo(i32, U)`
    if (p.check("lparen")) {
      p.advance();
      const args: A.TypeExpr[] = [];
      p.skipNewlines();
      if (!p.check("rparen")) {
        while (true) {
          p.skipNewlines();
          if (p.check("rparen")) break;
          args.push(parseType(p));
          p.skipNewlines();
          if (p.match("comma") === null) break;
        }
      }
      const end = p.expect("rparen", "`)` to close generic argument list");
      return {
        kind: "GenericInstType",
        span: p.spanOf(name, end),
        base: named,
        args,
      };
    }
    return named;
  }
  p.error("P1005", t.span, `got ${describeToken(t)}`);
  p.advance();
  return { kind: "NamedType", span: t.span, name: "?" };
}

function parseFnType(p: Parser): A.FnTypeExpr {
  const start = p.advance(); // fn
  p.expect("lparen", "`(` after `fn` in function type");
  const params: A.TypeExpr[] = [];
  p.skipNewlines();
  if (!p.check("rparen")) {
    while (true) {
      p.skipNewlines();
      if (p.check("rparen")) break;
      params.push(parseType(p));
      p.skipNewlines();
      if (p.match("comma") === null) break;
    }
  }
  p.expect("rparen", "`)` after function parameter types");
  let returnType: A.TypeExpr | null = null;
  if (p.match("arrow") !== null) returnType = parseType(p);
  return {
    kind: "FnTypeExpr",
    span: p.spanOf(start, p.peek(-1)),
    params,
    returnType,
  };
}
