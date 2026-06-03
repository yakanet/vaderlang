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
  // Struct literals are disabled at condition top-level so `if Foo { … }`
  // reads `Foo` as the condition (not `Foo { … }` as a struct lit). A leading
  // `(` is NOT special-cased here: it parses as an ordinary parenthesised
  // primary via `parseParenOrTuple`, which re-enables struct literals inside
  // the parens AND keeps the infix chain going — so `if (i + 1) % 4 == 0` and
  // `if (Point { .x = 1 }).ok` both parse as the full expression. (A bespoke
  // `if (...)` grabber used to eat just the first paren group and leave the
  // rest dangling — that was the bug.)
  p.allowStructLit = false;
  const cond = parseExpr(p, 0);
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

/** Parse `fn(...) -> R` as a function *type* (value-position type-meta,
 *  e.g. `Handler :: fn(i32) -> i32`). The legacy lambda form
 *  `fn(params) { body }` has been removed in favor of `(params) -> body`;
 *  see `parseParenOrTuple` + `parseLambdaWithoutFn` for the new path. */
export function parseLambda(p: Parser): A.LambdaExpr | A.FnTypeExpr {
  return parseLambdaOrFnType(p, /*allowFnLambda*/ false);
}

/** Same as `parseLambda` but accepts the `fn(...) { body }` legacy shape
 *  silently — used by `parseLet` for the `name :: fn(...) { body }` Vader
 *  idiom (a local fn-decl-as-let, not a value-position lambda). */
export function parseLambdaAsLetValue(p: Parser): A.LambdaExpr | A.FnTypeExpr {
  return parseLambdaOrFnType(p, /*allowFnLambda*/ true);
}

function parseLambdaOrFnType(p: Parser, allowFnLambda: boolean): A.LambdaExpr | A.FnTypeExpr {
  const start = p.advance(); // fn
  const { params } = parseFnSignatureParams(p);
  let returnType: A.TypeExpr | null = null;
  if (p.match("arrow") !== null) returnType = parseType(p);
  if (!p.check("lbrace")) {
    return {
      kind: "FnTypeExpr",
      id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: p.peek(-1).span.end },
      params: params.map((par) => par.type ?? { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: par.span, name: "?" }),
      returnType,
    };
  }
  if (!allowFnLambda) {
    // `fn(...) { body }` outside a `name ::` binding is no longer a lambda.
    // Let the generic parser surface its own diagnostic — the caller flow
    // (typecheck on a FnTypeExpr followed by an orphan block) reports a
    // clearer downstream error than a dedicated P1024.
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
