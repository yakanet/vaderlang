// Type-expression parsing. Handles named types, generic instantiation, the
// `$T` typeParam shorthand, function types, postfix array `T[]` and tuple
// `[T1, T2, ...]` types, the `T!` Error-union shorthand, and pipe-separated
// unions.
//
// Precedence on type postfix : `[]` binds tightest, then `!`, then `|`.
// `int[]!`        → `(int[])!`  (= `int[] | Error`)
// `int!`          → `int | Error`
// `fn() -> int[]` → return type is `int[]` (postfix on the return primary).

import type * as A from "../ast.ts";
import type { Parser } from "../parser.ts";
import { describeToken } from "../parser.ts";

export function parseType(p: Parser): A.TypeExpr {
  let head = parseTypePrimary(p);
  // Postfix `[]` loop : `T[]`, `T[][]`, ... wraps `head` into an ArrayTypeExpr.
  // Two-token lookahead `[ ]` keeps us from accidentally consuming a `[` that
  // belongs to something else (e.g. a future generic-instantiation form).
  while (p.check("lbracket") && p.check("rbracket", 1)) {
    p.advance(); // [
    const rb = p.advance(); // ]
    head = {
      kind: "ArrayTypeExpr",
      span: { start: head.span.start, end: rb.span.end },
      element: head,
    };
  }
  // Postfix `!`: `T!` desugars to `T | Error` (SPEC §10). Special case for
  // `void!` — the runtime has no `void` value to box, it emits `null` for the
  // success branch ; we rewrite to `null | Error` so `match { is null -> ... }`
  // matches cleanly on the success arm.
  if (p.match("bang") !== null) {
    const bangEnd = p.peek(-1).span.end;
    const successVariant: A.TypeExpr = head.kind === "IdentExpr" && head.name === "void"
      ? { kind: "IdentExpr", span: head.span, name: "null" }
      : head;
    head = {
      kind: "UnionType",
      span: { start: head.span.start, end: bangEnd },
      variants: [successVariant, { kind: "IdentExpr", span: { start: bangEnd, end: bangEnd }, name: "Error" }],
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
    return {
      kind: "IdentExpr",
      span: p.spanOf(t, name),
      name: name.text,
      isTypeParamIntro: true,
    };
  }
  if (t.kind === "kw_fn") {
    return parseFnType(p);
  }
  // Parenthesised type — used for grouping when postfix precedence would
  // otherwise bind too tightly. e.g. `(T | U)[]` to mean "array of union".
  if (t.kind === "lparen") {
    p.advance();
    p.skipNewlines();
    const inner = parseType(p);
    p.skipNewlines();
    p.expect("rparen", "`)` to close parenthesised type");
    return inner;
  }
  if (t.kind === "lbracket") {
    // Bracketed type form. Three readings :
    //   `[T1, T2, ...]`  → tuple type (≥ 2 elements)
    //   `[T,]`           → 1-tuple — forbidden (P1011)
    //   `[T]`            → legacy array alias (deprecated ; phases A-C only).
    //                      In phase D this becomes a hard error directing
    //                      users to the postfix `T[]` form.
    // Empty `[]` is a parse error (no zero-tuples).
    const start = p.advance();
    const elements: A.TypeExpr[] = [];
    p.skipNewlines();
    if (p.check("rbracket")) {
      p.error("P1005", t.span, "empty `[]` is not a valid type");
      const end = p.advance();
      return {
        kind: "SeqLitExpr",
        span: p.spanOf(start, end),
        elements: [],
      };
    }
    elements.push(parseType(p));
    p.skipNewlines();
    let hadTrailingComma = false;
    while (p.match("comma") !== null) {
      p.skipNewlines();
      if (p.check("rbracket")) { hadTrailingComma = true; break; }
      elements.push(parseType(p));
      p.skipNewlines();
    }
    const end = p.expect("rbracket", "`]` to close bracketed type");
    if (elements.length === 1 && !hadTrailingComma) {
      // Legacy prefix `[T]` syntax has been retired. Direct users to the
      // new postfix `T[]` form. The bracketed `[T1, T2]` shape is reserved
      // for tuples (≥ 2 elements).
      p.error("P1024", p.spanOf(start, end),
        "use postfix `T[]` for array types ; `[T]` is now reserved for tuples (≥ 2 elements)");
      // Best-effort recovery : keep parsing as if it were an array type so
      // downstream phases get a usable shape and can surface their own errors.
      return {
        kind: "ArrayTypeExpr",
        span: p.spanOf(start, end),
        element: elements[0]!,
      };
    }
    if (elements.length === 1 && hadTrailingComma) {
      // `[T,]` — 1-tuple, forbidden.
      p.error("P1021", p.spanOf(start, end),
        "use a struct or a plain value instead");
    }
    return {
      kind: "SeqLitExpr",
      span: p.spanOf(start, end),
      elements,
    };
  }
  if (t.kind === "kw_null") {
    p.advance();
    return { kind: "IdentExpr", span: t.span, name: "null" };
  }
  if (t.kind === "kw_type") {
    // `type` as a type bound: `(T: type)` — the metatype.
    p.advance();
    return { kind: "IdentExpr", span: t.span, name: "type" };
  }
  if (t.kind === "ident") {
    const name = p.advance();
    const named: A.IdentExpr = { kind: "IdentExpr", span: name.span, name: name.text };
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
  return { kind: "IdentExpr", span: t.span, name: "?" };
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
