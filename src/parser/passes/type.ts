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
import { UNASSIGNED_NODE_ID } from "../ast.ts";
import type { Parser } from "../parser.ts";
import { describeToken } from "../parser.ts";

export function parseType(p: Parser): A.TypeExpr {
  // Precedence ladder for type expressions :
  //   prefix  `const`      (qualifies an array type as immutable)
  //   postfix `[]` `!`     (tightest — applied to the primary)
  //   infix   `&`          (intersection / trait composition)
  //   infix   `|`          (union — loosest)
  // Mirrors the value-side Pratt precedence (`amp` BP 60, `pipe` BP 40)
  // so `T | U & V` parses as `T | (U & V)` everywhere.
  //
  // Optional leading `|` lets multi-line unions read cleanly in the
  // Haskell / Rust style :
  //   T ::
  //       | A
  //       | B
  //       | C
  // The lexer's `SUPPRESS_BEFORE` on `pipe` drops the newline before
  // each leading `|` so the tokens look identical to `T :: | A | B | C`.
  if (p.match("pipe") !== null) {
    /* leading pipe consumed — first variant follows */
  }
  // `const T[]` — prefix modifier on the array type that follows. The
  // immutable flag is set on the OUTER ArrayTypeExpr ; nested arrays
  // (`const T[][]` = "const 2D array") keep their inner element type
  // intact.
  const constTok = p.match("kw_const");
  let head = parseTypeIntersection(p);
  if (constTok !== null) {
    if (head.kind !== "ArrayTypeExpr") {
      p.error("P1027", { start: constTok.span.start, end: head.span.end },
        "`const` qualifier only applies to array types (`const T[]`)");
    } else {
      head = { ...head, immutable: true, span: { start: constTok.span.start, end: head.span.end } };
    }
  }
  // Union: `T | U | V` — built as a left-associative `bitor` chain.
  if (p.check("pipe")) {
    const start = head.span.start;
    while (p.match("pipe") !== null) {
      const next = parseTypeIntersection(p);
      head = {
        kind: "BinaryExpr",
        id: UNASSIGNED_NODE_ID, span: { start, end: next.span.end },
        op: "bitor",
        left: head,
        right: next,
      };
    }
  }
  return head;
}

/** Intersection-level : `T & U & V` — tighter than `|`, looser than the
 *  postfix `[]`/`!`. Used both for type-position intersection types (the
 *  set-theoretic meet) and for trait-composition bounds (`[T: A & B]`,
 *  meaning T satisfies A *and* B). */
function parseTypeIntersection(p: Parser): A.TypeExpr {
  let head = parseTypePostfix(p);
  if (p.check("amp")) {
    const start = head.span.start;
    while (p.match("amp") !== null) {
      const next = parseTypePostfix(p);
      head = {
        kind: "BinaryExpr",
        id: UNASSIGNED_NODE_ID, span: { start, end: next.span.end },
        op: "bitand",
        left: head,
        right: next,
      };
    }
  }
  return head;
}

/** Primary + the two postfix operators (`T[]`, `T!`). The `!` form
 *  desugars to `T | Error` (SPEC §10) — `void!` rewrites to `null!` so the
 *  success arm matches cleanly on `is null`. */
function parseTypePostfix(p: Parser): A.TypeExpr {
  let head = parseTypePrimary(p);
  // Postfix `[]` loop : `T[]`, `T[][]`, ... wraps `head` into an ArrayTypeExpr.
  // Two-token lookahead `[ ]` keeps us from accidentally consuming a `[` that
  // belongs to something else (e.g. a future generic-instantiation form).
  while (p.check("lbracket") && p.check("rbracket", 1)) {
    p.advance(); // [
    const rb = p.advance(); // ]
    head = {
      kind: "ArrayTypeExpr",
      id: UNASSIGNED_NODE_ID, span: { start: head.span.start, end: rb.span.end },
      element: head,
      immutable: false,
    };
  }
  // Postfix `!` — error-union shorthand.
  if (p.match("bang") !== null) {
    const bangEnd = p.peek(-1).span.end;
    const successVariant: A.TypeExpr = head.kind === "IdentExpr" && head.name === "void"
      ? { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: head.span, name: "null" }
      : head;
    const errorVariant: A.IdentExpr = {
      kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: { start: bangEnd, end: bangEnd }, name: "Error",
    };
    head = {
      kind: "BinaryExpr",
      id: UNASSIGNED_NODE_ID, span: { start: head.span.start, end: bangEnd },
      op: "bitor",
      left: successVariant,
      right: errorVariant,
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
      id: UNASSIGNED_NODE_ID, span: p.spanOf(t, name),
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
    // Bracketed type form :
    //   `[T1, T2, ...]`  → tuple type (≥ 2 elements)
    //   `[T,]` / `[T]`   → 1-tuple shape : forbidden (P1021) ; recovered
    //                      as `T[]` to keep downstream phases moving.
    // Empty `[]` is a parse error (no zero-tuples).
    const start = p.advance();
    const elements: A.TypeExpr[] = [];
    p.skipNewlines();
    if (p.check("rbracket")) {
      p.error("P1005", t.span, "empty `[]` is not a valid type");
      const end = p.advance();
      return {
        kind: "SeqLitExpr",
        id: UNASSIGNED_NODE_ID, span: p.spanOf(start, end),
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
    if (elements.length === 1) {
      // 1-tuple : `[T]` and `[T,]` both reach here. `T[]` is the array
      // form ; a single-element tuple has no use case (just write `T`).
      // Best-effort recovery as `ArrayTypeExpr` keeps downstream phases
      // working when the user clearly meant an array.
      p.error("P1021", p.spanOf(start, end),
        "use postfix `T[]` for an array, or a plain value if you meant the element");
      return {
        kind: "ArrayTypeExpr",
        id: UNASSIGNED_NODE_ID, span: p.spanOf(start, end),
        element: elements[0]!,
        immutable: false,
      };
    }
    return {
      kind: "SeqLitExpr",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(start, end),
      elements,
    };
  }
  if (t.kind === "kw_null") {
    p.advance();
    return { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: t.span, name: "null" };
  }
  if (t.kind === "ident") {
    const name = p.advance();
    let head: A.Expr = { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: name.span, name: name.text };
    // Qualified namespace : `module.Type` — applies when the leading ident
    // is an `import "X" as alias` (or destructured-namespace) binding. The
    // resolver follows the chain to the exported type in the target module.
    // Built as a `FieldExpr` so the existing field-resolution machinery
    // (which already handles `module.value` for call expressions) can
    // serve type-position lookups too.
    while (p.check("dot")) {
      const dot = p.advance();
      const field = p.expect("ident", "field name after `.` in qualified type");
      head = {
        kind: "FieldExpr",
        id: UNASSIGNED_NODE_ID, span: { start: head.span.start, end: field.span.end },
        target: head,
        field: field.text,
        fieldSpan: field.span,
      };
    }
    // Generic instantiation : `Foo<i32, U>`. Returns the bare ident
    // when no `<` follows ; the outer postfix loop then picks up `T[]`
    // arrays / `T!` error-unions.
    const args = parseGenericArgList(p, "generic argument list");
    if (args === null) return head;
    return {
      kind: "GenericInstExpr",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(name, p.peek(-1)),
      callee: head,
      typeArgs: args.items,
    };
  }
  p.error("P1005", t.span, `got ${describeToken(t)}`);
  p.advance();
  return { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: t.span, name: "?" };
}

/** Parse a comma-separated angle-bracket generic-argument list — used
 *  for `Foo<args>` instantiation and for trait-arg lists like `...
 *  implements Trait<args>`. Returns null when no `<` opens the list
 *  (caller treats the reference as un-instantiated). `consumeClosingAngle`
 *  handles the `shr` split so `Vec<V>>` closes cleanly across the lexer's
 *  fused `>>` token. */
export function parseGenericArgList(
  p: Parser, what: string,
): { items: A.TypeExpr[] } | null {
  if (!p.check("lt")) return null;
  p.advance();
  const items: A.TypeExpr[] = [];
  p.skipNewlines();
  if (!p.checkClosingAngle()) {
    while (true) {
      p.skipNewlines();
      if (p.checkClosingAngle()) break;
      items.push(parseType(p));
      p.skipNewlines();
      if (p.match("comma") === null) break;
    }
  }
  if (p.checkClosingAngle()) p.consumeClosingAngle();
  else p.expect("gt", `\`>\` to close ${what}`);
  return { items };
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
    id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
    params,
    returnType,
  };
}
