// Statement and block parsing. Recognises let / return / for (infinite,
// while, in) / break / continue / defer, and falls back to an expression
// statement (with optional `=` assignment trailer) for everything else.
// `parseBlock` promotes a trailing `ExprStmt` into the implicit return value
// of the block — the type-checker then treats the block as having that type.

import type { TokenKind } from "../../lexer/token.ts";
import type * as A from "../ast.ts";
import { UNASSIGNED_NODE_ID } from "../ast.ts";
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

  // Tuple-destructure let : `[a, b] := expr`, `[a, b] :: expr`, or
  // `[a, b]: [int, string] = expr`. Detected by looking for a `[` whose
  // matching `]` is followed by `:=`, `::`, or `:` (typed form).
  if (p.check("lbracket") && peekTupleLetStart(p)) {
    return parseTupleLet(p);
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
      id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
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
      kind: "BinaryExpr", id: UNASSIGNED_NODE_ID, span, op: compoundOp, left: expr, right: rhs,
    };
    return { kind: "AssignStmt", id: UNASSIGNED_NODE_ID, span, target: expr, value: desugared };
  }
  return {
    kind: "ExprStmt",
    id: UNASSIGNED_NODE_ID, span: expr.span,
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
  const binding: A.SimpleBinding = {
    kind: "SimpleBinding",
    id: UNASSIGNED_NODE_ID, span: nameTok.span,
    name: nameTok.text,
    nameSpan: nameTok.span,
  };
  return {
    kind: "LetStmt",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, p.peek(-1)),
    mutable,
    binding,
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
  const binding: A.SimpleBinding = {
    kind: "SimpleBinding",
    id: UNASSIGNED_NODE_ID, span: nameTok.span,
    name: nameTok.text,
    nameSpan: nameTok.span,
  };
  return {
    kind: "LetStmt",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, p.peek(-1)),
    mutable,
    binding,
    type,
    value,
  };
}

/** Lookahead : after the `[`, scan past the matched `]` and check whether the
 *  next significant token starts a let-destructure (`::`, `:=`, or `:` for the
 *  typed form). Returns false otherwise — the `[` then belongs to a regular
 *  expression statement (a SeqLit at stmt position). */
function peekTupleLetStart(p: Parser): boolean {
  let depth = 1;
  let j = p.pos + 1;
  while (j < p.tokens.length && depth > 0) {
    const k = p.tokens[j]!.kind;
    if (k === "eof") return false;
    if (k === "lbracket") depth++;
    else if (k === "rbracket") {
      depth--;
      if (depth === 0) break;
    }
    j++;
  }
  if (depth !== 0) return false;
  // Skip newlines after the matching `]`.
  let i = j + 1;
  while (i < p.tokens.length && p.tokens[i]!.kind === "newline") i++;
  const next = p.tokens[i]?.kind;
  return next === "decl_const" || next === "decl_var" || next === "colon";
}

function parseTupleLet(p: Parser): A.LetStmt {
  const start = p.peek();
  const binding = parseLetBinding(p);
  let type: A.TypeExpr | null = null;
  let mutable: boolean;
  if (p.check("colon")) {
    p.advance();
    type = parseType(p);
    const sep = p.peek();
    if (sep.kind === "assign") { p.advance(); mutable = true; }
    else if (sep.kind === "colon") { p.advance(); mutable = false; }
    else { p.expect("assign", "`=` or `:` after type annotation"); mutable = true; }
  } else {
    const declTok = p.peek();
    if (declTok.kind !== "decl_const" && declTok.kind !== "decl_var") {
      p.expect("decl_var", "`:=`, `::`, or `:` after destructure pattern");
      mutable = true;
    } else {
      p.advance();
      mutable = declTok.kind === "decl_var";
    }
  }
  const value = parseExpr(p, 0);
  return {
    kind: "LetStmt",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
    mutable,
    binding,
    type,
    value,
  };
}

function parseLetBinding(p: Parser): A.LetBinding {
  if (p.check("lbracket")) {
    const start = p.advance();
    p.skipNewlines();
    const elements: A.LetBinding[] = [];
    if (!p.check("rbracket")) {
      while (true) {
        p.skipNewlines();
        if (p.check("rbracket")) break;
        const subStart = p.peek();
        if (p.match("dotdotdot") !== null) {
          const nameTok = p.expect("ident", "name after `...` in destructure pattern");
          elements.push({
            kind: "RestBinding",
            id: UNASSIGNED_NODE_ID, span: p.spanOf(subStart, nameTok),
            name: nameTok.text,
            nameSpan: nameTok.span,
          });
        } else {
          elements.push(parseLetBinding(p));
        }
        p.skipNewlines();
        if (p.match("comma") === null) break;
        p.skipNewlines();
      }
    }
    const end = p.expect("rbracket", "`]` to close destructure pattern");
    if (elements.length < 2) {
      p.error("P1023", p.spanOf(start, end));
    }
    return {
      kind: "TupleBinding",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(start, end),
      elements,
    };
  }
  if (p.check("ident") && p.peek().text === "_") {
    const tok = p.advance();
    return { kind: "WildcardBinding", id: UNASSIGNED_NODE_ID, span: tok.span };
  }
  const tok = p.expect("ident", "binding name in destructure pattern");
  return {
    kind: "SimpleBinding",
    id: UNASSIGNED_NODE_ID, span: tok.span,
    name: tok.text,
    nameSpan: tok.span,
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
    id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
    value,
  };
}

function parseFor(p: Parser, label: string | null): A.ForStmt {
  const start = p.advance(); // for

  // Forms:
  //   for { ... }                infinite
  //   for cond { ... }           while-style
  //   for x in iter { ... }      iteration with single binding
  //   for [a, b] in iter { ... } iteration with tuple destructure
  if (p.check("lbrace")) {
    const body = parseBlock(p);
    return {
      kind: "ForStmt",
      id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: body.span.end },
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
      id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: body.span.end },
      label,
      form: { kind: "in", binding: bindTok.text, bindingSpan: bindTok.span, iter },
      body,
    };
  }

  // Tuple destructure : `for [a, b] in iter { body }`. We bracket-match the
  // opening `[` ; if the matching `]` is followed by `in`, we're committed to
  // a destructure for-in. We desugar at parse time by introducing a synthetic
  // binding name and prepending a `let <pattern> := <synth>` to the body —
  // resolver / typechecker / lowerer / self-host parser see a regular
  // single-binding for-in and don't need to learn about destructure forms.
  if (looksLikeForDestructure(p)) {
    const binding = parseLetBinding(p);
    p.expect("kw_in", "`in` after for-loop binding");
    const iter = parseExpr(p, 0);
    p.allowStructLit = savedAllow;
    const body = parseBlock(p);
    // Encoding-invariant synth name: line/column are codepoint-based on
    // both sides (TS skips low surrogates ; Vader skips UTF-8 continuation
    // bytes), whereas `offset` diverges (UTF-16 code units in TS, UTF-8
    // bytes in the self-host) and would break parser parity on snippets
    // with multi-byte source.
    const synth = `__for_${start.span.start.line}_${start.span.start.column}`;
    const synthSpan = binding.span;
    const synthIdent: A.IdentExpr = { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: synthSpan, name: synth };
    const desugared: A.LetStmt = {
      kind: "LetStmt", id: UNASSIGNED_NODE_ID, span: synthSpan, mutable: false,
      binding, type: null, value: synthIdent,
    };
    const wrappedBody: A.BlockExpr = {
      ...body,
      stmts: [desugared, ...body.stmts],
    };
    return {
      kind: "ForStmt",
      id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: body.span.end },
      label,
      form: { kind: "in", binding: synth, bindingSpan: synthSpan, iter },
      body: wrappedBody,
    };
  }

  const cond = parseExpr(p, 0);
  p.allowStructLit = savedAllow;
  const body = parseBlock(p);
  return {
    kind: "ForStmt",
    id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: body.span.end },
    label,
    form: { kind: "while", cond },
    body,
  };
}

/** Lookahead : `[ ... ]` followed by `in`. Bracket-aware so nested `[a, [b, c]]`
 *  patterns are detected correctly. Bounded to keep pathological inputs from
 *  scanning the whole token stream. */
function looksLikeForDestructure(p: Parser): boolean {
  if (!p.check("lbracket")) return false;
  let depth = 0;
  let i = 0;
  for (;;) {
    if (i > 256) return false;
    const t = p.peek(i);
    if (t.kind === "eof") return false;
    if (t.kind === "lbracket") depth++;
    else if (t.kind === "rbracket") {
      depth--;
      if (depth === 0) return p.check("kw_in", i + 1);
    }
    i++;
  }
}

function parseBreakContinue(p: Parser, which: "break" | "continue"): A.BreakStmt | A.ContinueStmt {
  const start = p.advance();
  let label: string | null = null;
  if (p.check("ident")) {
    label = p.advance().text;
  }
  return which === "break"
    ? { kind: "BreakStmt", id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)), label }
    : { kind: "ContinueStmt", id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)), label };
}

function parseDefer(p: Parser): A.DeferStmt {
  const start = p.advance();
  const body: A.Stmt | A.BlockExpr = p.check("lbrace")
    ? parseBlock(p)
    : (parseStmt(p) ?? { kind: "ExprStmt", id: UNASSIGNED_NODE_ID, span: start.span, expr: placeholderExpr(start) });
  return {
    kind: "DeferStmt",
    id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: body.span.end },
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
    id: UNASSIGNED_NODE_ID, span: p.spanOf(lb, rb),
    stmts,
    trailing,
  };
}
