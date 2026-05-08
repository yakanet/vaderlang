// Statement and block parsing. Recognises let / return / for (infinite,
// while, in) / break / continue / defer, and falls back to an expression
// statement (with optional `=` assignment trailer) for everything else.
// `parseBlock` promotes a trailing `ExprStmt` into the implicit return value
// of the block — the type-checker then treats the block as having that type.

import type { TokenKind } from "../../lexer/token.ts";
import type * as A from "../ast.ts";
import type { Parser } from "../parser.ts";

import { parseExpr, placeholderExpr } from "./expr.ts";
import { parseType } from "./type.ts";

export function parseStmt(p: Parser): A.Stmt | null {
  if (p.check("kw_return")) return parseReturn(p);
  if (p.check("kw_for")) return parseFor(p, null);
  if (p.check("kw_break")) return parseBreakContinue(p, "break") as A.BreakStmt;
  if (p.check("kw_continue")) return parseBreakContinue(p, "continue") as A.ContinueStmt;
  if (p.check("kw_defer")) return parseDefer(p);

  // Labeled for: `label: for ...`
  if (p.check("ident") && p.check("colon", 1) && p.check("kw_for", 2)) {
    const labelTok = p.advance();
    p.advance(); // colon
    return parseFor(p, labelTok.text);
  }

  // `name :: expr` or `name := expr`
  if (p.check("ident") && (p.check("decl_const", 1) || p.check("decl_var", 1))) {
    return parseLet(p);
  }

  // `name: Type = expr` — typed mutable declaration
  if (p.check("ident") && p.check("colon", 1)) {
    return parseTypedLet(p);
  }

  // Otherwise: expression statement (with possible assignment trailing)
  const start = p.peek();
  const expr = parseExpr(p, 0);
  if (p.match("assign") !== null) {
    const value = parseExpr(p, 0);
    return {
      kind: "AssignStmt",
      span: p.spanOf(start, p.peek(-1)),
      target: expr,
      value,
    };
  }
  // Compound assignment — `lhs += rhs` desugars to `lhs = lhs <op> rhs` so
  // user-type operator-overload dispatch is reused without a parallel path.
  // Note : the parser shares the parsed `expr` AST node between the new
  // BinaryExpr's `left` and the AssignStmt's `target`. For non-idempotent
  // LHS (e.g. `cell["k"] += 1` with Index/IndexSet), the lowerer evaluates
  // the receiver and index twice — matches Python/JS semantics, not C/Rust.
  const compoundOp = COMPOUND_OPS[p.peek().kind];
  if (compoundOp !== undefined) {
    p.advance();
    const rhs = parseExpr(p, 0);
    const span = p.spanOf(start, p.peek(-1));
    const desugared: A.BinaryExpr = {
      kind: "BinaryExpr", span, op: compoundOp, left: expr, right: rhs,
    };
    return { kind: "AssignStmt", span, target: expr, value: desugared };
  }
  return {
    kind: "ExprStmt",
    span: expr.span,
    expr,
  };
}

/** Compound-assignment tokens mapped to their underlying `BinaryExpr.op`. */
const COMPOUND_OPS: Partial<Record<TokenKind, A.BinaryExpr["op"]>> = {
  plus_assign:    "add",
  minus_assign:   "sub",
  star_assign:    "mul",
  slash_assign:   "div",
  percent_assign: "mod",
};

function parseTypedLet(p: Parser): A.LetStmt {
  const nameTok = p.advance(); // ident
  p.advance(); // colon
  const type = parseType(p);
  // `=` → mutable binding ; `:` → immutable binding (echoes the second `:`
  // of the untyped `::` form, with `:=` ↔ `=` on the mutable side).
  const sep = p.peek();
  let mutable: boolean;
  if (sep.kind === "assign") { p.advance(); mutable = true; }
  else if (sep.kind === "colon") { p.advance(); mutable = false; }
  else { p.expect("assign", "`=` or `:` after type annotation"); mutable = true; }
  const value = parseExpr(p, 0);
  return {
    kind: "LetStmt",
    span: p.spanOf(nameTok, p.peek(-1)),
    mutable,
    name: nameTok.text,
    nameSpan: nameTok.span,
    type,
    value,
  };
}

function parseLet(p: Parser): A.LetStmt {
  const nameTok = p.advance();
  const declTok = p.advance(); // :: or :=
  const mutable = declTok.kind === "decl_var";

  // Type annotations only appear on top-level constants today;
  // `x := T(value)` plays the role of an explicit cast at let-binding sites.
  const type: A.TypeExpr | null = null;

  const value = parseExpr(p, 0);
  return {
    kind: "LetStmt",
    span: p.spanOf(nameTok, p.peek(-1)),
    mutable,
    name: nameTok.text,
    nameSpan: nameTok.span,
    type,
    value,
  };
}

function parseReturn(p: Parser): A.ReturnStmt {
  const start = p.advance(); // return
  let value: A.Expr | null = null;
  if (!p.check("newline") && !p.check("rbrace") && !p.check("eof")) {
    value = parseExpr(p, 0);
  }
  return {
    kind: "ReturnStmt",
    span: p.spanOf(start, p.peek(-1)),
    value,
  };
}

function parseFor(p: Parser, label: string | null): A.ForStmt {
  const start = p.advance(); // for

  // Forms:
  //   for { ... }              infinite
  //   for cond { ... }         while-style
  //   for x in iter { ... }    iteration
  if (p.check("lbrace")) {
    const body = parseBlock(p);
    return {
      kind: "ForStmt",
      span: { start: start.span.start, end: body.span.end },
      label,
      form: { kind: "infinite" },
      body,
    };
  }

  const savedAllow = p.allowStructLit;
  p.allowStructLit = false;

  // `x in iter` requires a 2-token lookahead: ident followed by `in`.
  if (p.check("ident") && p.check("kw_in", 1)) {
    const bindTok = p.advance();
    p.advance(); // in
    const iter = parseExpr(p, 0);
    p.allowStructLit = savedAllow;
    const body = parseBlock(p);
    return {
      kind: "ForStmt",
      span: { start: start.span.start, end: body.span.end },
      label,
      form: { kind: "in", binding: bindTok.text, bindingSpan: bindTok.span, iter },
      body,
    };
  }

  const cond = parseExpr(p, 0);
  p.allowStructLit = savedAllow;
  const body = parseBlock(p);
  return {
    kind: "ForStmt",
    span: { start: start.span.start, end: body.span.end },
    label,
    form: { kind: "while", cond },
    body,
  };
}

function parseBreakContinue(p: Parser, which: "break" | "continue"): A.BreakStmt | A.ContinueStmt {
  const start = p.advance();
  let label: string | null = null;
  if (p.check("ident")) {
    label = p.advance().text;
  }
  return which === "break"
    ? { kind: "BreakStmt", span: p.spanOf(start, p.peek(-1)), label }
    : { kind: "ContinueStmt", span: p.spanOf(start, p.peek(-1)), label };
}

function parseDefer(p: Parser): A.DeferStmt {
  const start = p.advance();
  const body: A.Stmt | A.BlockExpr = p.check("lbrace")
    ? parseBlock(p)
    : (parseStmt(p) ?? { kind: "ExprStmt", span: start.span, expr: placeholderExpr(start) });
  return {
    kind: "DeferStmt",
    span: { start: start.span.start, end: body.span.end },
    body,
  };
}

export function parseBlock(p: Parser): A.BlockExpr {
  const lb = p.expect("lbrace", "`{` to open block");
  p.skipNewlines();
  const stmts: A.Stmt[] = [];
  let trailing: A.Expr | null = null;

  while (!p.check("rbrace") && !p.check("eof")) {
    const stmt = parseStmt(p);
    if (stmt !== null) stmts.push(stmt);
    p.skipNewlines();
  }

  // Promote a trailing ExprStmt to the implicit return value.
  if (stmts.length > 0 && stmts[stmts.length - 1]!.kind === "ExprStmt") {
    const last = stmts.pop() as A.ExprStmt;
    trailing = last.expr;
  }

  const rb = p.expect("rbrace", "`}` to close block");
  return {
    kind: "BlockExpr",
    span: p.spanOf(lb, rb),
    stmts,
    trailing,
  };
}
