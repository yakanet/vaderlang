// Control-flow expression parsers — `if`, `match` (+ per-arm), and `fn`
// (lambda + fn-type-expr disambiguation). Lambda is here rather than in the
// general expression file because it's structurally close to `if`/`match` :
// each opens a block-or-block-like body and shares the same `allowStructLit`
// recursion guard.

import type * as A from "../ast.ts";
import { UNASSIGNED_NODE_ID } from "../ast.ts";
import type { Parser } from "../parser.ts";

import { parseExpr } from "./expr.ts";
import { parsePattern } from "./pattern.ts";
import { parseBlock } from "./stmt.ts";
import { parseFnSignatureParams } from "./decl.ts";
import { parseType } from "./type.ts";

export function parseIfExpr(p: Parser): A.IfExpr {
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
    id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: (elseBranch ?? thenBlock).span.end },
    cond,
    then: thenBlock,
    else: elseBranch,
  };
}

export function parseMatchExpr(p: Parser, partial: boolean): A.MatchExpr {
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
    id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: end.span.end },
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
    id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: body.span.end },
    pattern,
    guard,
    body,
  };
}

export function parseLambda(p: Parser): A.LambdaExpr | A.FnTypeExpr {
  const start = p.advance(); // fn
  const { params } = parseFnSignatureParams(p);
  let returnType: A.TypeExpr | null = null;
  if (p.match("arrow") !== null) returnType = parseType(p);
  // Layer 1.C — when no body block follows, this is a function *type*
  // (`fn(T) -> U`), not a lambda. The two share the `fn` keyword and
  // signature ; the parser disambiguates by looking ahead for `{`.
  if (!p.check("lbrace")) {
    return {
      kind: "FnTypeExpr",
      id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: p.peek(-1).span.end },
      params: params.map((par) => par.type ?? { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: par.span, name: "?" }),
      returnType,
    };
  }
  const body = parseBlock(p);
  return {
    kind: "LambdaExpr",
    id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: body.span.end },
    params,
    returnType,
    body,
  };
}
