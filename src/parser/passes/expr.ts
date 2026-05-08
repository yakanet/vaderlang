// Expression parsing. A Pratt parser drives the precedence ladder; the
// per-form entries (literals, idents/struct-lits, blocks, lambda, if, match,
// patterns, string interpolation, array literals) live as regular helpers
// below. This file also owns the static precedence tables (INFIX_OPS,
// POSTFIX_BP) and the postfix-call/index/field rewriter.

import type { Token, TokenKind } from "../../lexer/token.ts";
import type * as A from "../ast.ts";
import type { Parser } from "../parser.ts";
import { describeToken, looksLikeStructLitBody } from "../parser.ts";

import { parseBlock } from "./stmt.ts";
import { parseFnSignatureParams } from "./decl.ts";
import { parseType } from "./type.ts";

// (leftBP, rightBP) — higher = tighter. Left-assoc: rightBP = leftBP + 1.
// Non-assoc operators have leftBP === rightBP and emit P1010 if chained.
// `op` is omitted for range tokens (`range_excl` / `range_incl`) — they
// build `RangeExpr`, not `BinaryExpr`, so no operator label flows through.
interface InfixOp {
  readonly leftBP: number;
  readonly rightBP: number;
  readonly op?: A.BinaryOp;
  readonly nonAssoc?: boolean;
}

const INFIX_OPS: ReadonlyMap<TokenKind, InfixOp> = new Map([
  // logical
  ["or_or",     { leftBP:  10, rightBP:  11, op: "or"     }],
  ["and_and",   { leftBP:  12, rightBP:  13, op: "and"    }],
  // comparison (non-assoc)
  ["eq",        { leftBP:  20, rightBP:  20, op: "eq",  nonAssoc: true }],
  ["neq",       { leftBP:  20, rightBP:  20, op: "neq", nonAssoc: true }],
  ["lt",        { leftBP:  20, rightBP:  20, op: "lt",  nonAssoc: true }],
  ["lte",       { leftBP:  20, rightBP:  20, op: "lte", nonAssoc: true }],
  ["gt",        { leftBP:  20, rightBP:  20, op: "gt",  nonAssoc: true }],
  ["gte",       { leftBP:  20, rightBP:  20, op: "gte", nonAssoc: true }],
  ["kw_is",     { leftBP:  20, rightBP:  20, op: "is",     nonAssoc: true }],
  ["kw_in",     { leftBP:  20, rightBP:  20, op: "in",     nonAssoc: true }],
  // range (non-assoc) — no `op` because we build `RangeExpr`, not `BinaryExpr`
  ["range_excl",{ leftBP:  30, rightBP:  30, nonAssoc: true }],
  ["range_incl",{ leftBP:  30, rightBP:  30, nonAssoc: true }],
  // bitwise
  ["pipe",      { leftBP:  40, rightBP:  41, op: "bitor"  }],
  ["caret",     { leftBP:  50, rightBP:  51, op: "bitxor" }],
  ["amp",       { leftBP:  60, rightBP:  61, op: "bitand" }],
  ["shl",       { leftBP:  70, rightBP:  71, op: "shl"    }],
  ["shr",       { leftBP:  70, rightBP:  71, op: "shr"    }],
  // arithmetic
  ["plus",      { leftBP:  80, rightBP:  81, op: "add"    }],
  ["minus",     { leftBP:  80, rightBP:  81, op: "sub"    }],
  ["star",      { leftBP:  90, rightBP:  91, op: "mul"    }],
  ["slash",     { leftBP:  90, rightBP:  91, op: "div"    }],
  ["percent",   { leftBP:  90, rightBP:  91, op: "mod"    }],
]);

// Postfix BP — these don't recurse on a right-side operand.
const POSTFIX_BP: ReadonlyMap<TokenKind, number> = new Map([
  ["question",  100],
  ["lparen",    100],
  ["lbracket",  100],
  ["dot",       100],
]);

export function parseExpr(p: Parser, minBP: number): A.Expr {
  let left = parsePrefix(p);
  let lastNonAssocLevel = -1;

  while (true) {
    const t = p.peek();

    const postfixBP = POSTFIX_BP.get(t.kind);
    if (postfixBP !== undefined && postfixBP >= minBP) {
      left = parsePostfix(p, left, t);
      lastNonAssocLevel = -1;
      continue;
    }

    // `!in` — two tokens, parsed as a single non-assoc infix at comparison level.
    if (t.kind === "bang" && p.peek(1).kind === "kw_in" && 20 >= minBP) {
      if (lastNonAssocLevel === 20) {
        p.error("P1010", t.span, "chained `!in`");
        break;
      }
      p.advance(); p.advance();
      const right = parseExpr(p, 21);
      left = {
        kind: "BinaryExpr",
        span: { start: left.span.start, end: right.span.end },
        op: "not_in",
        left,
        right,
      };
      lastNonAssocLevel = 20;
      continue;
    }

    const infix = INFIX_OPS.get(t.kind);
    if (infix !== undefined && infix.leftBP >= minBP) {
      if (infix.nonAssoc === true && lastNonAssocLevel === infix.leftBP) {
        p.error("P1010", t.span, `chained \`${describeToken(t)}\``);
        break;
      }
      p.advance();
      const right = parseExpr(p, infix.rightBP + (infix.nonAssoc === true ? 1 : 0));
      if (t.kind === "range_excl" || t.kind === "range_incl") {
        left = {
          kind: "RangeExpr",
          span: { start: left.span.start, end: right.span.end },
          inclusive: t.kind === "range_incl",
          lower: left,
          upper: right,
        };
      } else {
        left = {
          kind: "BinaryExpr",
          span: { start: left.span.start, end: right.span.end },
          // `infix.op` is defined for every non-range InfixOp (range tokens
          // are handled in the branch above) — assert and use.
          op: infix.op!,
          left,
          right,
        };
      }
      lastNonAssocLevel = infix.nonAssoc === true ? infix.leftBP : -1;
      continue;
    }

    break;
  }

  return left;
}

function parsePrefix(p: Parser): A.Expr {
  const t = p.peek();

  switch (t.kind) {
    case "int_literal":
      p.advance();
      return {
        kind: "IntLitExpr",
        span: t.span,
        value: t.intValue ?? 0n,
        suffix: t.numericSuffix ?? null,
      };
    case "float_literal":
      p.advance();
      return {
        kind: "FloatLitExpr",
        span: t.span,
        value: t.floatValue ?? 0,
        suffix: t.numericSuffix ?? null,
      };
    case "char_literal":
      p.advance();
      return { kind: "CharLitExpr", span: t.span, value: t.charValue ?? 0 };
    case "kw_true":
      p.advance();
      return { kind: "BoolLitExpr", span: t.span, value: true };
    case "kw_false":
      p.advance();
      return { kind: "BoolLitExpr", span: t.span, value: false };
    case "kw_null":
      p.advance();
      return { kind: "NullLitExpr", span: t.span };
    case "string_begin":
      return parseStringLit(p);
    case "ident":
      return parseIdentOrStructLit(p);
    case "lparen":
      return parseParenOrTuple(p);
    case "lbracket":
      return parseSeqLit(p);
    case "lbrace":
      return parseBlock(p);
    case "minus":
    case "bang":
    case "tilde": {
      p.advance();
      const op: A.UnaryOp = t.kind === "minus" ? "neg" : t.kind === "bang" ? "not" : "bitnot";
      const operand = parseExpr(p, 95); // tighter than * / %, looser than postfix
      return { kind: "UnaryExpr", span: { start: t.span.start, end: operand.span.end }, op, operand };
    }
    case "kw_if":
      return parseIfExpr(p);
    case "kw_match":
      return parseMatchExpr(p, /*partial*/ false);
    case "at": {
      // `@partial match x { ... }` — opt-out of exhaustiveness for one
      // match expression. No other `@`-prefixed expression-position
      // forms today, so reject anything else with P1014.
      const atTok = p.advance();
      const nameTok = p.expect("ident", "decorator name after `@`");
      if (nameTok.text !== "partial") {
        p.error("P1014", { start: atTok.span.start, end: nameTok.span.end },
          `\`@${nameTok.text}\` is not allowed in expression position`);
      }
      if (!p.check("kw_match")) {
        p.error("P1014", nameTok.span, `\`@${nameTok.text}\` must precede a \`match\` expression`);
      }
      return parseMatchExpr(p, /*partial*/ true);
    }
    case "kw_fn":
      return parseLambda(p);
    case "kw_self":
      p.advance();
      return { kind: "IdentExpr", span: t.span, name: "self" };
    case "dot": {
      p.advance(); // consume `.`
      const variantTok = p.expect("ident", "variant name after `.`");
      return {
        kind: "DotVariantExpr",
        span: { start: t.span.start, end: variantTok.span.end },
        variant: variantTok.text,
        variantSpan: variantTok.span,
      };
    }
    default:
      p.error("P1003", t.span, `got ${describeToken(t)}`);
      p.advance();
      return placeholderExpr(t);
  }
}

export function placeholderExpr(t: Token): A.Expr {
  return { kind: "NullLitExpr", span: t.span };
}

function parsePostfix(p: Parser, left: A.Expr, t: Token): A.Expr {
  if (t.kind === "question") {
    p.advance();
    return {
      kind: "TryExpr",
      span: { start: left.span.start, end: t.span.end },
      inner: left,
    };
  }
  if (t.kind === "dot") {
    p.advance();
    // `t.0`, `t.1`, ... — numeric tuple index access. The lowerer rewrites
    // these to synthetic field names `_0`, `_1`, ... at desugar time.
    if (p.check("int_literal")) {
      const numTok = p.advance();
      return {
        kind: "FieldExpr",
        span: { start: left.span.start, end: numTok.span.end },
        target: left,
        field: numTok.text,
        fieldSpan: numTok.span,
        isNumeric: true,
      };
    }
    const name = p.expect("ident", "field name after `.`");
    return {
      kind: "FieldExpr",
      span: { start: left.span.start, end: name.span.end },
      target: left,
      field: name.text,
      fieldSpan: name.span,
    };
  }
  if (t.kind === "lparen") {
    // Call OR cast (cast: callee is a NamedType reference, but at parse time we represent both as CallExpr;
    // the type-checker disambiguates.) Generic instantiation `Foo(T)` is also a CallExpr at parse time when
    // followed by `{`.
    p.advance();
    const args = parseCallArgs(p);
    p.expect("rparen", "`)` to close argument list");
    const callExpr: A.CallExpr = {
      kind: "CallExpr",
      span: { start: left.span.start, end: p.peek(-1).span.end },
      callee: left,
      args,
    };
    // If immediately followed by `{` AND struct literals are allowed, treat as struct literal.
    // Disabled for now — the explicit struct literal path `parseIdentOrStructLit` handles `Name { ... }`.
    return callExpr;
  }
  if (t.kind === "lbracket") {
    p.advance();
    const index = parseExpr(p, 0);
    p.expect("rbracket", "`]` to close index");
    return {
      kind: "IndexExpr",
      span: { start: left.span.start, end: p.peek(-1).span.end },
      target: left,
      index,
    };
  }
  return left;
}

function parseCallArgs(p: Parser): A.CallArg[] {
  const out: A.CallArg[] = [];
  p.skipNewlines();
  if (p.check("rparen")) return out;

  while (true) {
    p.skipNewlines();
    if (p.check("rparen")) break;
    const start = p.peek();
    // Spread `...expr` not supported as a call arg in MVP — but reserved syntactically.
    // Named arg detection: `ident = expr`
    if (p.check("ident") && p.check("assign", 1)) {
      const nameTok = p.advance();
      p.advance(); // =
      const value = parseExpr(p, 0);
      out.push({
        span: p.spanOf(start, p.peek(-1)),
        name: nameTok.text,
        value,
        spread: false,
      });
    } else {
      const value = parseExpr(p, 0);
      out.push({
        span: value.span,
        name: null,
        value,
        spread: false,
      });
    }
    p.skipNewlines();
    if (p.match("comma") === null) break;
  }
  return out;
}

function parseIdentOrStructLit(p: Parser): A.Expr {
  const t = p.advance();

  // Generic struct literal: `Ident(typeArgs) { .field = … }`. Detect by
  // scanning past balanced parens to confirm a `{` struct-lit body follows
  // before committing to the parse. Otherwise let postfix handle `(args)`
  // as a regular call expression.
  if (p.allowStructLit && peekGenericStructLit(p)) {
    p.advance();        // consume `(`
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
    const rp = p.expect("rparen", "`)` to close generic argument list");
    p.expect("lbrace", "`{` to open generic struct literal");
    const fields = parseStructLitFields(p);
    const rb = p.expect("rbrace", "`}` to close struct literal");
    return {
      kind: "StructLitExpr",
      span: p.spanOf(t, rb),
      typeName: {
        kind: "GenericInstType",
        span: p.spanOf(t, rp),
        base: { kind: "NamedType", span: t.span, name: t.text },
        args,
      },
      fields,
    };
  }

  if (p.allowStructLit && p.check("lbrace") && looksLikeStructLitBody(p.tokens, p.pos)) {
    p.advance();
    const fields = parseStructLitFields(p);
    const rb = p.expect("rbrace", "`}` to close struct literal");
    return {
      kind: "StructLitExpr",
      span: p.spanOf(t, rb),
      typeName: { kind: "NamedType", span: t.span, name: t.text },
      fields,
    };
  }
  return { kind: "IdentExpr", span: t.span, name: t.text };
}

/** Lookahead: are the upcoming tokens shaped like a generic struct lit
 *  head — `( <stuff> ) {` followed by a `.<field>` struct-lit body? Used to
 *  disambiguate `Foo(T) { … }` (struct lit) from `Foo(T)` (call expr).  */
function peekGenericStructLit(p: Parser): boolean {
  if (p.tokens[p.pos]?.kind !== "lparen") return false;
  let depth = 1, j = p.pos + 1;
  while (j < p.tokens.length && depth > 0) {
    const t = p.tokens[j]!;
    if (t.kind === "eof") return false;
    if (t.kind === "lparen") depth++;
    else if (t.kind === "rparen") {
      depth--;
      if (depth === 0) break;
    }
    j++;
  }
  if (depth !== 0) return false;
  const closing = j;     // index of the matching `)`
  // Skip newlines after `)` since the formatter may break the line.
  let k = closing + 1;
  while (k < p.tokens.length && p.tokens[k]!.kind === "newline") k++;
  if (p.tokens[k]?.kind !== "lbrace") return false;
  return looksLikeStructLitBody(p.tokens, k);
}

function parseStructLitFields(p: Parser): A.StructLitField[] {
  const out: A.StructLitField[] = [];
  p.skipNewlines();
  while (!p.check("rbrace") && !p.check("eof")) {
    p.expect("dot", "`.` before struct literal field name");
    const start = p.peek(-1);
    const name = p.expect("ident", "struct literal field name");
    p.expect("assign", "`=` after struct literal field name");
    const value = parseExpr(p, 0);
    out.push({
      span: p.spanOf(start, p.peek(-1)),
      name: name.text,
      nameSpan: name.span,
      value,
    });
    p.skipNewlines();
    if (p.match("comma") === null) break;
    p.skipNewlines();
  }
  p.skipNewlines();
  return out;
}

function parseParenOrTuple(p: Parser): A.Expr {
  p.advance(); // (
  p.skipNewlines();
  const savedAllow = p.allowStructLit;
  p.allowStructLit = true;
  const expr = parseExpr(p, 0);
  p.allowStructLit = savedAllow;
  p.skipNewlines();
  p.expect("rparen", "`)` to close parenthesised expression");
  return expr;
}

function parseSeqLit(p: Parser): A.SeqLitExpr {
  const lb = p.advance();
  const elements: A.Expr[] = [];
  p.skipNewlines();
  if (!p.check("rbracket")) {
    while (true) {
      p.skipNewlines();
      if (p.check("rbracket")) break;
      elements.push(parseExpr(p, 0));
      p.skipNewlines();
      if (p.match("comma") === null) break;
      p.skipNewlines();
    }
  }
  const rb = p.expect("rbracket", "`]` to close seq literal");
  return {
    kind: "SeqLitExpr",
    span: p.spanOf(lb, rb),
    elements,
  };
}

function parseStringLit(p: Parser): A.StringLitExpr {
  const begin = p.advance(); // string_begin
  const parts: A.StringLitPart[] = [];
  while (!p.check("string_end") && !p.check("eof")) {
    const t = p.peek();
    if (t.kind === "string_part") {
      p.advance();
      parts.push({ kind: "text", value: t.stringValue ?? t.text, span: t.span });
      continue;
    }
    if (t.kind === "interp_open") {
      const interpStart = p.advance();
      const expr = parseExpr(p, 0);
      const closeTok = p.match("interp_close");
      const closeSpan = closeTok !== null ? closeTok.span : expr.span;
      parts.push({
        kind: "interp",
        expr,
        span: { start: interpStart.span.start, end: closeSpan.end },
      });
      continue;
    }
    // Unexpected token: bail to end.
    p.error("P1001", t.span, `inside string literal`);
    p.advance();
  }
  const end = p.match("string_end") ?? p.peek();
  return {
    kind: "StringLitExpr",
    span: p.spanOf(begin, end),
    parts,
  };
}

function parseIfExpr(p: Parser): A.IfExpr {
  const start = p.advance(); // if
  const savedAllow = p.allowStructLit;
  p.allowStructLit = false;

  let cond: A.Expr;
  if (p.match("lparen") !== null) {
    // Parenthesised condition: struct literals allowed inside.
    p.allowStructLit = true;
    cond = parseExpr(p, 0);
    p.expect("rparen", "`)` to close `if` condition");
  } else {
    cond = parseExpr(p, 0);
  }
  p.allowStructLit = savedAllow;

  const thenBlock = parseBlock(p);
  let elseBranch: A.IfExpr | A.BlockExpr | null = null;
  p.skipNewlines();
  if (p.match("kw_else") !== null) {
    p.skipNewlines();
    if (p.check("kw_if")) elseBranch = parseIfExpr(p);
    else elseBranch = parseBlock(p);
  }

  return {
    kind: "IfExpr",
    span: { start: start.span.start, end: (elseBranch ?? thenBlock).span.end },
    cond,
    then: thenBlock,
    else: elseBranch,
  };
}

function parseMatchExpr(p: Parser, partial: boolean): A.MatchExpr {
  const start = p.advance(); // match
  const savedAllow = p.allowStructLit;
  p.allowStructLit = false;
  const scrutinee = parseExpr(p, 0);
  p.allowStructLit = savedAllow;

  p.expect("lbrace", "`{` to open match arms");
  p.skipNewlines();
  const arms: A.MatchArm[] = [];
  while (!p.check("rbrace") && !p.check("eof")) {
    arms.push(parseMatchArm(p));
    p.skipNewlines();
    if (p.match("comma") !== null) p.skipNewlines();
  }
  const end = p.expect("rbrace", "`}` to close match");
  return {
    kind: "MatchExpr",
    span: { start: start.span.start, end: end.span.end },
    scrutinee,
    arms,
    partial: partial ? true : undefined,
  };
}

function parseMatchArm(p: Parser): A.MatchArm {
  const start = p.peek();
  const pattern = parsePattern(p);
  let guard: A.Expr | null = null;
  if (p.match("kw_if") !== null) {
    const savedAllow = p.allowStructLit;
    p.allowStructLit = false;
    guard = parseExpr(p, 0);
    p.allowStructLit = savedAllow;
  }
  p.expect("arrow", "`->` between pattern and arm body");
  const body = parseExpr(p, 0);
  return {
    span: { start: start.span.start, end: body.span.end },
    pattern,
    guard,
    body,
  };
}

function parseLambda(p: Parser): A.LambdaExpr {
  const start = p.advance(); // fn
  const { params } = parseFnSignatureParams(p);
  let returnType: A.TypeExpr | null = null;
  if (p.match("arrow") !== null) returnType = parseType(p);
  const body = parseBlock(p);
  return {
    kind: "LambdaExpr",
    span: { start: start.span.start, end: body.span.end },
    params,
    returnType,
    body,
  };
}

function parsePattern(p: Parser): A.Pattern {
  const t = p.peek();
  if (t.kind === "dot") {
    p.advance(); // consume `.`
    const variantTok = p.expect("ident", "variant name after `.`");
    return {
      kind: "EnumVariantPattern",
      span: { start: t.span.start, end: variantTok.span.end },
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
        kind: "NamedType",
        span: { start: dotTok.span.start, end: variantTok.span.end },
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
      span: p.spanOf(t, p.peek(-1)),
      type,
      inner,
      bindAs,
    };
  }
  if (t.kind === "ident" && t.text === "_") {
    p.advance();
    return { kind: "WildcardPattern", span: t.span };
  }
  if (t.kind === "ident") {
    p.advance();
    return { kind: "BindingPattern", span: t.span, name: t.text };
  }
  if (t.kind === "lbracket") {
    return parseTuplePattern(p);
  }
  p.error("P1007", t.span, `got ${describeToken(t)}`);
  p.advance();
  return { kind: "WildcardPattern", span: t.span };
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
    span: p.spanOf(start, end),
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
        value = { kind: "binding", name: bindTok.text, span: bindTok.span };
      } else {
        const v = parseExpr(p, 0);
        value = { kind: "literal", value: v };
      }
    } else {
      // shorthand: `{ x, y }` ⇒ binding to fields with same name
      value = { kind: "binding", name: name.text, span: name.span };
    }
    fields.push({
      span: p.spanOf(fStart, p.peek(-1)),
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
    span: { start: start.span.start, end: end.span.end },
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
