// Declaration parsing — the top-level dispatcher and every per-decl rule.
// Decls are: `import`, `name :: <fn|struct|trait|type|expr>`, `name :=
// <expr>` (forbidden at top level), and `Type implements Trait { … }`. Each
// rule consumes its own keyword run-on and produces a fully-formed AST node.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Token } from "../../lexer/token.ts";
import type * as A from "../ast.ts";
import { staticStringValue, UNASSIGNED_NODE_ID } from "../ast.ts";
import type { Parser } from "../parser.ts";
import { collectTypeParams, describeToken } from "../parser.ts";

import { parseExpr } from "./expr.ts";
import { parseBlock } from "./stmt.ts";
import { parseGenericArgList, parseType } from "./type.ts";

export function parseDecl(p: Parser): A.Decl | null {
  const decorators = parseDecorators(p);
  const visibility: A.Visibility = p.match("kw_export") !== null ? "public" : "private";

  // `@assert(condition)` is a "decorator-statement" — it stands on its own
  // at the top level rather than annotating a following decl. Detect it
  // before we look for the usual named-decl forms ; only emit the special
  // form when no other decorator co-occurs (a stack like `@comptime
  // @assert(...)` would be ambiguous).
  if (decorators.length === 1 && decorators[0]!.name === "assert") {
    const dec = decorators[0]!;
    if (dec.args.length < 1 || dec.args.length > 2) {
      p.error("P1014", dec.span,
        "`@assert` expects 1 or 2 arguments : `@assert(cond)` or `@assert(cond, \"message\")`");
      return null;
    }
    let message: string | null = null;
    if (dec.args.length === 2) {
      const msgArg = dec.args[1]!;
      const literal = msgArg.kind === "StringLitExpr" ? staticStringValue(msgArg) : null;
      if (literal === null) {
        p.error("P1014", msgArg.span,
          "`@assert` message must be a static string literal (no interpolation)");
        return null;
      }
      message = literal;
    }
    return {
      kind: "AssertDecl",
      id: UNASSIGNED_NODE_ID, span: dec.span,
      condition: dec.args[0]!,
      message,
      decorators: [],
    };
  }

  if (p.check("kw_import")) {
    return parseImportDecl(p, decorators);
  }

  if (isImplDecl(p)) {
    return parseImplDecl(p, decorators);
  }

  // `name<T> :: <type-expr>` (canonical) or `name[T] :: <type-expr>` (legacy)
  // — generic type alias with LHS-bracketed type-params. Detected before
  // the regular `name ::` path since the `<...>` / `[...]` between name
  // and `::` is unambiguous in this position (no other decl form puts
  // angles or brackets there). Body is parsed as a regular expression
  // and typechecked as a type at use time, matching the non-generic
  // implicit-alias path.
  if (
    p.check("ident") && (p.check("lt", 1) || p.check("lbracket", 1))
    && peekLhsGenericAliasHead(p)
  ) {
    return parseLhsGenericAliasDecl(p, decorators, visibility);
  }

  // `name :: <fn|struct|trait|expr>` or `name := expr` (top-level forbidden) etc.
  if (p.check("ident") && p.check("decl_const", 1)) {
    return parseNamedDecl(p, decorators, visibility);
  }
  // Odin-style typed top-level const : `name : Type : value`. The local
  // form (`name : Type : value` immutable / `name : Type = value` mutable)
  // is parsed in `stmt.ts::parseTypedLet` ; this is the top-level analogue,
  // restricted to const-only since mutables aren't allowed at top level.
  if (p.check("ident") && p.check("colon", 1)) {
    return parseTypedConstDecl(p, decorators, visibility);
  }

  const t = p.peek();
  p.error("P1006", t.span, `got ${describeToken(t)}`);
  p.syncToTopLevel();
  return null;
}

function parseDecorators(p: Parser): A.Decorator[] {
  const out: A.Decorator[] = [];
  while (p.check("at")) {
    const at = p.advance();
    const nameTok = p.expect("ident", "decorator name after `@`");
    const args: A.Expr[] = [];
    if (p.match("lparen") !== null) {
      if (!p.check("rparen")) {
        do {
          args.push(parseExpr(p, 0));
        } while (p.match("comma") !== null && !p.check("rparen"));
      }
      p.expect("rparen", "`)` after decorator arguments");
    }
    out.push({
      id: UNASSIGNED_NODE_ID, span: p.spanOf(at, p.peek(-1)),
      name: nameTok.text,
      args,
    });
    p.skipNewlines();
  }
  return out;
}

/** Statement-position `import "..." { a, b }`. Rejects the legacy bare
 *  `import "..."` (implicit-last-segment binding) and `import "..." as
 *  name` forms — both are now spelled `name :: import "..."` at the
 *  named-decl dispatcher. */
function parseImportDecl(p: Parser, decorators: readonly A.Decorator[]): A.ImportDecl {
  const start = p.advance(); // consume `import`
  const pathTok = expectStringLiteral(p, "import path");
  const path = pathTok.text;

  if (p.check("kw_as")) {
    const as = p.peek();
    p.error("P1006", as.span,
      "the `import \"...\" as name` form was removed ; write `name :: import \"...\"` instead");
    p.advance();                                // consume `as`
    if (p.check("ident")) p.advance();          // and the would-be alias, to keep parsing going
  }

  if (p.match("lbrace") === null) {
    p.error("P1006", p.peek().span,
      "the bare `import \"...\"` form was removed ; use either `name :: import \"...\"` for a namespace binding or `import \"...\" { a, b }` to destructure");
    return {
      kind: "ImportDecl",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
      path,
      binding: { kind: "destructure", names: [] },
      decorators,
    };
  }

  const names = parseImportNameListRest(p);
  return {
    kind: "ImportDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
    path,
    binding: { kind: "destructure", names },
    decorators,
  };
}

/** Named-decl-position `name :: import "..."` or `name :: import "..." { a, b }`.
 *  The named-decl dispatcher routes here when it sees `kw_import` as the
 *  RHS keyword. */
function parseNamedImportDecl(
  p: Parser, decorators: readonly A.Decorator[], nameTok: Token,
): A.ImportDecl {
  p.advance(); // consume `import`
  const pathTok = expectStringLiteral(p, "import path");
  const path = pathTok.text;

  let restricted: readonly A.ImportName[] | null = null;
  if (p.match("lbrace") !== null) restricted = parseImportNameListRest(p);

  return {
    kind: "ImportDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, p.peek(-1)),
    path,
    binding: { kind: "named-namespace", name: nameTok.text, restricted },
    decorators,
  };
}

/** Parse `a, b as c, …}` (with the leading `{` already consumed).
 *  Shared by the statement-position destructure form and the named-decl
 *  scoped-namespace form. */
function parseImportNameListRest(p: Parser): A.ImportName[] {
  const names: A.ImportName[] = [];
  p.skipNewlines();
  if (!p.check("rbrace")) {
    do {
      p.skipNewlines();
      if (p.check("rbrace")) break;
      const name = p.expect("ident", "imported name");
      let alias: string | null = null;
      if (p.match("kw_as") !== null) {
        alias = p.expect("ident", "alias after `as`").text;
      }
      names.push({
        id: UNASSIGNED_NODE_ID,
        name: name.text,
        alias,
        span: p.spanOf(name, p.peek(-1)),
      });
      p.skipNewlines();
    } while (p.match("comma") !== null);
  }
  p.skipNewlines();
  p.expect("rbrace", "`}` to close import list");
  return names;
}

export function expectStringLiteral(p: Parser, what: string): { text: string; span: Span } {
  if (!p.check("string_begin")) {
    const t = p.peek();
    p.error("P1002", t.span, `expected ${what} (got ${describeToken(t)})`);
    return { text: "", span: t.span };
  }
  const begin = p.advance();
  let text = "";
  while (!p.check("string_end") && !p.check("eof")) {
    const t = p.advance();
    if (t.kind === "string_part" && t.stringValue !== undefined) text += t.stringValue;
    // No interpolation expected here — error if seen.
    if (t.kind === "interp_open") {
      p.error("P1003", t.span, "interpolation not allowed in import path");
      // skip to interp_close
      while (!p.check("interp_close") && !p.check("eof")) p.advance();
    }
  }
  const end = p.match("string_end") ?? p.peek();
  return { text, span: p.spanOf(begin, end) };
}

/** Lookahead : starting at `p.pos` (currently on the leading ident), is the
 *  shape `ident <...> ::` (canonical) or `ident [ ... ] ::` (legacy) ?
 *  Walks a balanced delimiter pair and checks the next token is
 *  `decl_const`. Lets us dispatch to the generic-alias path without
 *  committing — the regular const-decl path handles everything else.
 *
 *  Angle tracking : `<` and `>` adjust an `angleDepth` counter ; `shr`
 *  (the lexer's `>>`) closes TWO levels at once because the user wrote
 *  two `>` characters that were merged into one token. The outer paren
 *  / bracket / brace depth is tracked separately to bail out cleanly. */
function peekLhsGenericAliasHead(p: Parser): boolean {
  // `p.pos` is on the ident ; ident + opener already verified by caller.
  const opener = p.tokens[p.pos + 1]?.kind;
  const isAngle = opener === "lt";
  let i = p.pos + 2;     // skip ident, skip opener
  let depth = 1;           // depth of the SAME-kind delimiter we opened
  let otherDepth = 0;      // any other paren/bracket/brace nesting
  while (i < p.tokens.length) {
    const t = p.tokens[i]!;
    if (t.kind === "eof" || t.kind === "newline") return false;
    if (isAngle) {
      if (t.kind === "lt" && otherDepth === 0) depth++;
      else if (t.kind === "gt" && otherDepth === 0) {
        depth--;
        if (depth === 0) return p.tokens[i + 1]?.kind === "decl_const";
      } else if (t.kind === "shr" && otherDepth === 0) {
        depth -= 2;
        if (depth === 0) return p.tokens[i + 1]?.kind === "decl_const";
        if (depth < 0) return false;
      } else if (t.kind === "lparen" || t.kind === "lbracket" || t.kind === "lbrace") otherDepth++;
      else if (t.kind === "rparen" || t.kind === "rbracket" || t.kind === "rbrace") {
        otherDepth--;
        if (otherDepth < 0) return false;
      }
    } else {
      if (t.kind === "lbracket") depth++;
      else if (t.kind === "rbracket") {
        depth--;
        if (depth === 0) return p.tokens[i + 1]?.kind === "decl_const";
        if (depth < 0) return false;
      } else if (t.kind === "lparen" || t.kind === "lbrace") otherDepth++;
      else if (t.kind === "rparen" || t.kind === "rbrace") {
        otherDepth--;
        if (otherDepth < 0) return false;
      }
    }
    i++;
  }
  return false;
}

function parseLhsGenericAliasDecl(
  p: Parser, decorators: readonly A.Decorator[], visibility: A.Visibility,
): A.TypeAliasDecl {
  const nameTok = p.advance(); // ident
  const typeParams = parseBracketedTypeParams(p);
  p.advance(); // ::
  const aliased = parseExpr(p, 0);
  return {
    kind: "TypeAliasDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    aliased,
    decorators,
  };
}

function isImplDecl(p: Parser): boolean {
  let i = p.pos;
  let depth = 0;
  while (i < p.tokens.length) {
    const t = p.tokens[i]!;
    if (t.kind === "eof" || t.kind === "newline") return false;
    if (t.kind === "kw_implements" && depth === 0) return true;
    if (t.kind === "lparen" || t.kind === "lbracket" || t.kind === "lbrace") depth++;
    if (t.kind === "rparen" || t.kind === "rbracket" || t.kind === "rbrace") depth--;
    if (depth < 0) return false;
    i++;
  }
  return false;
}

function parseImplDecl(p: Parser, decorators: readonly A.Decorator[]): A.ImplDecl {
  const startTok = p.peek();
  const forType = parseType(p);
  p.expect("kw_implements", "`implements` keyword");
  // Optional bounded-generic typeParam list immediately after `implements` :
  // `Foo<T> implements<T: Bound> Trait<T> { … }`. Mirrors the `fn<T>` /
  // `struct<T>` / `trait<T>` pattern — the angle list follows the
  // keyword that introduces a typeParam scope. References inside
  // `forType` / `traitArgs` / member bodies resolve against the bound
  // symbols. Legacy `[T]` form still accepted during the migration.
  const typeParams: readonly A.TypeParam[] = (p.check("lt") || p.check("lbracket"))
    ? parseBracketedTypeParams(p)
    : [];
  const traitTok = p.expect("ident", "trait name");

  // Optional generic args on the trait reference. Two forms during the
  // Layer 4-sugar migration : `… implements Iterator(i32)` (legacy paren form)
  // and `… implements Iterator[i32]` (Layer 4-sugar bracketed form).
  const traitArgList = parseGenericArgList(p, "trait argument list");
  const traitArgs: A.TypeExpr[] = traitArgList !== null ? traitArgList.items : [];

  // Four impl shapes after the trait reference:
  //   `... -> expr`             → SAM arrow: synthesise a single FnDecl whose
  //                               body returns `expr`.
  //   `... { name :: fn ... }`  → classic: one or more explicit fn members,
  //                               written with the same `name :: fn(...)`
  //                               form as top-level functions.
  //   `... { stmts }`           → SAM block: synthesise a single FnDecl whose
  //                               body is the parsed block.
  //   `@intrinsic ...`          → host-provided impl with no source body.
  //                               Members are synthesised by the resolver from
  //                               the trait's methods (body = null).
  // Detection for the brace forms peeks past `{` and any newlines/decorators
  // /`export` to see whether the first significant tokens spell out
  // `ident :: fn`; if so, classic, otherwise SAM block.
  const members: A.FnDecl[] = [];
  const isIntrinsic = decorators.some((d) => d.name === "intrinsic");
  let endTok: Token;
  if (p.check("arrow")) {
    members.push(parseSamArrowMember(p));
    endTok = p.peek(-1);
  } else if (p.check("lbrace") && peekIsClassicImplBody(p)) {
    p.advance(); // {
    p.skipNewlines();
    while (!p.check("rbrace") && !p.check("eof")) {
      const fn = parseFnDeclInsideTrait(p);
      if (fn !== null) members.push(fn);
      p.skipNewlines();
    }
    endTok = p.expect("rbrace", "`}` to close impl body");
  } else if (p.check("lbrace")) {
    members.push(parseSamBlockMember(p));
    endTok = p.peek(-1);
  } else if (isIntrinsic) {
    // `@intrinsic Type implements Trait` (no body) — resolver will fill in
    // body-less members from the trait's method list.
    endTok = p.peek(-1);
  } else {
    const t = p.peek();
    p.error("P1006", t.span, `expected \`->\` or \`{\` after trait reference (got ${describeToken(t)})`);
    endTok = t;
  }
  return {
    kind: "ImplDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(startTok, endTok),
    typeParams,
    forType,
    traitName: traitTok.text,
    traitNameSpan: traitTok.span,
    traitArgs,
    members,
    decorators,
  };
}

/** True when the impl body is the classic `{ name :: fn ... }` shape. The
 *  parser is positioned at `lbrace`; we peek past it, any newlines, any
 *  leading decorators (`@foo` / `@foo(...)`) and an optional `export`
 *  keyword, and check that the first three significant tokens spell out
 *  `ident :: fn`. Anything else (including a bare `fn ...` survivor of the
 *  pre-unification syntax) is treated as a SAM block — that path will then
 *  surface a clean parse error from `parseStmt`. */
function peekIsClassicImplBody(p: Parser): boolean {
  let i = 1; // past the `{`
  const skipWs = () => {
    while (p.peek(i).kind === "newline") i++;
  };
  skipWs();
  // Drift past any number of decorators and an optional `export`.
  while (true) {
    const tk = p.peek(i).kind;
    if (tk === "at") {
      i++; // `@`
      if (p.peek(i).kind === "ident") i++;
      if (p.peek(i).kind === "lparen") {
        let depth = 1;
        i++;
        while (depth > 0 && p.peek(i).kind !== "eof") {
          const k = p.peek(i).kind;
          if (k === "lparen") depth++;
          else if (k === "rparen") depth--;
          i++;
        }
      }
      skipWs();
      continue;
    }
    if (tk === "kw_export") { i++; skipWs(); continue; }
    break;
  }
  return p.peek(i).kind === "ident"
      && p.peek(i + 1).kind === "decl_const"
      && p.peek(i + 2).kind === "kw_fn";
}

/** SAM arrow form: `… implements Trait -> expr`. Build a synthetic FnDecl
 *  whose body is a one-statement block that returns the expression. The
 *  resolver fills in `name`, `params`, and `returnType` from the trait. */
function parseSamArrowMember(p: Parser): A.FnDecl {
  const arrowTok = p.expect("arrow", "`->` to introduce a SAM impl body");
  const expr = parseExpr(p, 0);
  const span = p.spanOf(arrowTok, p.peek(-1));
  const body: A.BlockExpr = {
    kind: "BlockExpr", id: UNASSIGNED_NODE_ID, span, stmts: [], trailing: expr,
  };
  return {
    kind: "FnDecl", id: UNASSIGNED_NODE_ID, span,
    name: "",                          // filled by resolver
    nameSpan: arrowTok.span,
    visibility: "public",
    typeParams: [],
    params: [],                        // filled by resolver
    returnType: null,                  // filled by resolver
    body,
    decorators: [],
    samSynthetic: true,
  };
}

/** SAM block form: `… implements Trait { stmts }`. Same idea as the arrow
 *  form, but the body is the parsed block (may have multiple statements and
 *  a trailing expression). */
function parseSamBlockMember(p: Parser): A.FnDecl {
  const block = parseBlock(p);
  return {
    kind: "FnDecl", id: UNASSIGNED_NODE_ID, span: block.span,
    name: "",
    nameSpan: block.span,
    visibility: "public",
    typeParams: [],
    params: [],
    returnType: null,
    body: block,
    decorators: [],
    samSynthetic: true,
  };
}

function parseNamedDecl(p: Parser, decorators: readonly A.Decorator[], visibility: A.Visibility): A.Decl {
  const nameTok = p.advance(); // ident
  p.advance(); // ::

  if (p.check("kw_fn")) return parseFnDecl(p, decorators, visibility, nameTok);
  if (p.check("kw_struct")) return parseStructDecl(p, decorators, visibility, nameTok);
  if (p.check("kw_enum")) return parseEnumDecl(p, decorators, visibility, nameTok);
  if (p.check("kw_trait")) return parseTraitDecl(p, decorators, visibility, nameTok);
  if (p.check("kw_import")) return parseNamedImportDecl(p, decorators, nameTok);

  return parseConstDecl(p, decorators, visibility, nameTok);
}

function parseFnDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.FnDecl {
  p.advance(); // fn
  // Bracketed type-params `fn[T: Bound](...)` (Layer 4-sugar). Inline `$T`
  // introductions in the value-arg types are still collected ; both lists
  // are merged so the two forms compose during the migration.
  const bracketed = parseBracketedTypeParams(p);
  const { params, typeParams: dollarParams } = parseFnSignatureParams(p);
  const typeParams = mergeTypeParams(bracketed, dollarParams);
  let returnType: A.TypeExpr | null = null;
  if (p.match("arrow") !== null) returnType = parseType(p);

  const { body, isExpressionBodied } = parseFnBodyTail(p, returnType !== null);

  return {
    kind: "FnDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    params,
    returnType,
    body,
    decorators,
    isExpressionBodied: isExpressionBodied ? true : undefined,
  };
}

/** After the optional `-> T` and `where ...`, a fn decl's tail is one of :
 *    - `{ block }`     — explicit block body
 *    - `= expr`        — Kotlin-style expression body ; the return type is
 *                        inferred when omitted, and an explicit `-> T` is
 *                        allowed so callers can pin the signature for
 *                        recursion / generics
 *    - <nothing>       — signature-only (extern / trait method shape)
 */
function parseFnBodyTail(
  p: Parser, _hasReturnType: boolean,
): { body: A.BlockExpr | null; isExpressionBodied: boolean } {
  if (p.check("assign")) {
    p.advance(); // `=`
    const expr = parseExpr(p, 0);
    const body: A.BlockExpr = {
      kind: "BlockExpr", id: UNASSIGNED_NODE_ID, span: expr.span, stmts: [], trailing: expr,
    };
    return { body, isExpressionBodied: true };
  }
  if (p.check("lbrace")) {
    return { body: parseBlock(p), isExpressionBodied: false };
  }
  // No-body fns are allowed for @extern declarations and trait method signatures.
  return { body: null, isExpressionBodied: false };
}

/** Member declaration inside a trait body or a classic impl body. Uses the
 *  same `name :: fn(...)` form as top-level fns so the surface syntax stays
 *  uniform across the language ; the body is optional (signature-only for
 *  trait method declarations and `@extern` impls). */
function parseFnDeclInsideTrait(p: Parser): A.FnDecl | null {
  const decorators = parseDecorators(p);
  const visibility: A.Visibility = p.match("kw_export") !== null ? "public" : "private";
  if (!(p.check("ident") && p.check("decl_const", 1) && p.check("kw_fn", 2))) {
    const t = p.peek();
    if (t.kind === "kw_fn") {
      p.error("P1006", t.span,
        "trait/impl members must use the `name :: fn(...)` form (the bare `fn name(...)` form was retired)");
    } else {
      p.error("P1006", t.span,
        `expected member declaration \`name :: fn(...)\` (got ${describeToken(t)})`);
    }
    // Recover: skip to the next `}` or to a token that looks like a member start.
    while (!p.check("rbrace") && !p.check("eof")) {
      if (p.check("ident") && p.check("decl_const", 1) && p.check("kw_fn", 2)) break;
      p.advance();
    }
    return null;
  }
  const nameTok = p.advance(); // ident
  p.advance();                 // ::
  p.advance();                 // fn
  const bracketed = parseBracketedTypeParams(p);
  const { params, typeParams: dollarParams } = parseFnSignatureParams(p);
  const typeParams = mergeTypeParams(bracketed, dollarParams);
  let returnType: A.TypeExpr | null = null;
  if (p.match("arrow") !== null) returnType = parseType(p);
  const { body, isExpressionBodied } = parseFnBodyTail(p, returnType !== null);
  return {
    kind: "FnDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    params,
    returnType,
    body,
    decorators,
    isExpressionBodied: isExpressionBodied ? true : undefined,
  };
}

export function parseFnSignatureParams(p: Parser): { params: A.FnParam[]; typeParams: A.TypeParam[] } {
  const typeParams: A.TypeParam[] = [];
  const params: A.FnParam[] = [];

  p.expect("lparen", "`(` after function name");
  p.skipNewlines();
  if (!p.check("rparen")) {
    let first = true;
    while (true) {
      p.skipNewlines();
      if (p.check("rparen") || p.check("eof")) break;
      if (!first) {
        if (p.match("comma") === null) break;
        p.skipNewlines();
        if (p.check("rparen")) break; // trailing comma
      }
      first = false;

      const startTok = p.peek();
      // `...rest: T` variadic is encoded as three consecutive `.` tokens by the lexer.
      let isVariadic = false;
      if (p.check("dot") && p.check("dot", 1) && p.check("dot", 2)) {
        p.advance(); p.advance(); p.advance();
        isVariadic = true;
      }

      let paramNameTok: Token;
      if (p.check("kw_self") || p.check("ident")) {
        paramNameTok = p.advance();
      } else {
        const t = p.peek();
        p.error("P1002", t.span, `expected parameter name (got ${describeToken(t)})`);
        while (!p.check("comma") && !p.check("rparen") && !p.check("eof")) p.advance();
        continue;
      }

      let type: A.TypeExpr | null = null;
      if (p.match("colon") !== null) {
        p.skipNewlines();
        type = parseType(p);
      }
      let defaultValue: A.Expr | null = null;
      if (p.match("assign") !== null) {
        defaultValue = parseExpr(p, 0);
      }

      // Collect any inline `$T` introduced in this param's type.
      if (type !== null) collectTypeParams(type, typeParams);

      params.push({
        id: UNASSIGNED_NODE_ID, span: p.spanOf(startTok, p.peek(-1)),
        name: paramNameTok.text,
        type,
        defaultValue,
        variadic: isVariadic,
      });
    }
  }
  p.expect("rparen", "`)` to close parameter list");

  return { params, typeParams };
}

function parseStructDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.StructDecl {
  p.advance(); // struct
  const typeParams: A.TypeParam[] = parseStructTypeParamList(p);
  p.expect("lbrace", "`{` to open struct body");
  p.skipNewlines();
  const fields: A.StructField[] = [];
  while (!p.check("rbrace") && !p.check("eof")) {
    const fieldVisibility: A.Visibility = p.match("kw_export") !== null ? "public" : "private";
    const start = p.peek();
    const fname = p.expect("ident", "field name");
    p.expect("colon", "`:` after field name");
    const ftype = parseType(p);
    let fdefault: A.Expr | null = null;
    if (p.match("assign") !== null) {
      p.skipNewlines();
      fdefault = parseExpr(p, 0);
    }
    fields.push({
      id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
      name: fname.text,
      type: ftype,
      visibility: fieldVisibility,
      default: fdefault,
    });
    // Field separator: newline or comma.
    if (!p.check("rbrace")) {
      if (!p.match("comma")) p.skipNewlines();
      else p.skipNewlines();
    }
  }
  const endTok = p.expect("rbrace", "`}` to close struct body");
  return {
    kind: "StructDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, endTok),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    fields,
    decorators,
  };
}

/** Parse the optional `($T, $U, $N: i32)` head on a struct/trait declaration. */
/** Combine bracketed type-params (declared explicitly via `fn[T, U]`) with
 *  inline `$T` introductions collected from the value-arg types. The
 *  bracketed list takes precedence — an inline `$T` whose name already
 *  appears in the bracketed list is skipped (the bracketed entry wins,
 *  carrying any bound that was declared). */
function mergeTypeParams(
  bracketed: readonly A.TypeParam[], inline: readonly A.TypeParam[],
): A.TypeParam[] {
  if (bracketed.length === 0) return [...inline];
  const seen = new Set(bracketed.map((tp) => tp.name));
  const out: A.TypeParam[] = [...bracketed];
  for (const tp of inline) {
    if (!seen.has(tp.name)) {
      out.push(tp);
      seen.add(tp.name);
    }
  }
  return out;
}

/** Type-param list head — `<T, U: Bound, ...>` (canonical) or `[T, U, ...]`
 *  (legacy bracketed form, kept during the migration to `<T>`). Each entry
 *  is `name` or `name: bound`. The bound is parsed as a type expression
 *  (so `<T: Numeric>` works) ; trait composition via `&` and arbitrary
 *  comptime predicates compose naturally. Returns an empty list and
 *  consumes nothing if neither `<` nor `[` opens the head. */
function parseBracketedTypeParams(p: Parser): A.TypeParam[] {
  const openIsAngle = p.check("lt");
  const openIsBracket = !openIsAngle && p.check("lbracket");
  if (!openIsAngle && !openIsBracket) return [];
  p.advance(); // < or [
  const out: A.TypeParam[] = [];
  p.skipNewlines();
  const atClose = (): boolean => openIsAngle ? p.checkClosingAngle() : p.check("rbracket");
  if (!atClose()) {
    let first = true;
    while (true) {
      p.skipNewlines();
      if (atClose() || p.check("eof")) break;
      if (!first) {
        if (p.match("comma") === null) break;
        p.skipNewlines();
        if (atClose()) break;
      }
      first = false;
      const start = p.peek();
      const nameTok = p.expect("ident", "type-param name");
      let bound: A.TypeExpr | null = null;
      if (p.match("colon") !== null) {
        p.skipNewlines();
        bound = parseType(p);
      }
      out.push({
        id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
        name: nameTok.text,
        bound,
        // Layer 4-sugar type-params are always type-params, never comptime
        // *value* params. Comptime values keep the legacy `($N: i32)` form
        // for now ; a future round may unify the two.
        isComptimeValue: false,
      });
    }
  }
  if (openIsAngle) {
    if (p.checkClosingAngle()) p.consumeClosingAngle();
    else p.expect("gt", "`>` to close type-param list");
  } else {
    p.expect("rbracket", "`]` to close type-param list");
  }
  return out;
}

function parseStructTypeParamList(p: Parser): A.TypeParam[] {
  // Canonical `<T>` form first ; legacy bracketed `[T]` form next ; the
  // older paren `($T)` form last. All three coexist through the
  // migration to `<T>`-only.
  if (p.check("lt") || p.check("lbracket")) return parseBracketedTypeParams(p);
  if (!p.match("lparen")) return [];
  const out: A.TypeParam[] = [];
  if (!p.check("rparen")) {
    let first = true;
    while (true) {
      p.skipNewlines();
      if (p.check("rparen")) break;
      if (!first) p.expect("comma", "`,` between type parameters");
      if (p.check("rparen")) break;
      first = false;

      const hasDollar = p.match("dollar") !== null;
      const start = p.peek();
      const name = p.expect("ident", "type parameter name");
      let bound: A.TypeExpr | null = null;
      if (p.match("colon") !== null) bound = parseType(p);
      if (!hasDollar) {
        const hint = bound === null
          ? `\`${name.text}\` must be written \`$${name.text}\``
          : `\`${name.text}\` must be prefixed with \`$\``;
        p.error("P1018", p.spanOf(start, p.peek(-1)), hint);
      } else if (bound?.kind === "IdentExpr" && bound.name === "type") {
        p.error("P1019", p.spanOf(start, p.peek(-1)),
          `\`: type\` bound is redundant; write \`$${name.text}\``);
        bound = null;
      }
      const isComptimeValue = bound !== null;
      out.push({
        id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
        name: name.text,
        bound,
        isComptimeValue,
      });
    }
  }
  p.expect("rparen", "`)` to close type parameter list");
  return out;
}

function parseTraitDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.TraitDecl {
  p.advance(); // trait
  const typeParams = parseStructTypeParamList(p);
  // Layer 7c — trait composition. Two shapes :
  //   `trait Foo[T] = A & B`         pure alias, no own body
  //   `trait Foo[T] : A & B { ... }` requires + own methods
  let requires: A.TypeExpr | null = null;
  let endTok: Token;
  let members: A.FnDecl[] = [];
  if (p.match("assign") !== null) {
    // Alias form — parse the composed trait expression, no body.
    requires = parseType(p);
    endTok = p.peek(-1);
    return {
      kind: "TraitDecl",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, endTok),
      name: nameTok.text,
      nameSpan: nameTok.span,
      visibility,
      typeParams,
      requires,
      members,
      decorators,
    };
  }
  if (p.match("colon") !== null) {
    requires = parseType(p);
  }
  p.expect("lbrace", "`{` to open trait body");
  p.skipNewlines();
  while (!p.check("rbrace") && !p.check("eof")) {
    const fn = parseFnDeclInsideTrait(p);
    if (fn !== null) members.push(fn);
    p.skipNewlines();
  }
  endTok = p.expect("rbrace", "`}` to close trait body");
  return {
    kind: "TraitDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, endTok),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    requires,
    members,
    decorators,
  };
}

function parseEnumDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.EnumDecl {
  p.advance(); // enum
  let repr: A.TypeExpr | null = null;
  if (p.match("lparen") !== null) {
    repr = parseType(p);
    p.expect("rparen", "`)` after enum backing type");
  }
  p.expect("lbrace", "`{` to open enum body");
  p.skipNewlines();
  const variants: A.EnumVariant[] = [];
  while (!p.check("rbrace") && !p.check("eof")) {
    const vTok = p.expect("ident", "variant name");
    let value: bigint | null = null;
    let valueSpan: Span | null = null;
    if (p.match("assign") !== null) {
      const litTok = p.expect("int_literal", "integer literal after `=`");
      value = litTok.intValue ?? 0n;
      valueSpan = litTok.span;
    }
    variants.push({ id: UNASSIGNED_NODE_ID, span: vTok.span, name: vTok.text, value, valueSpan });
    p.match("comma");
    p.skipNewlines();
  }
  const endTok = p.expect("rbrace", "`}` to close enum body");
  return {
    kind: "EnumDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, endTok),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    repr,
    variants,
    decorators,
  };
}


/** `name :: value` — untyped top-level const. Type annotations live in the
 *  separate `name : type : value` form parsed by `parseTypedConstDecl` ;
 *  the old inline `name :: : type value` shape is rejected by `parseExpr`. */
function parseConstDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.ConstDecl {
  // Multi-line union with a leading pipe :
  //   T ::
  //       | A
  //       | B
  //       | C
  // The lexer's `SUPPRESS_BEFORE` drops the newlines before each `|`, so
  // the token stream looks like `T :: | A | B | C`. Consume the optional
  // leading `|` so the normal infix-Pratt path picks up the rest as a
  // left-associative `bitor` chain — same shape `A | B | C` produces.
  p.match("pipe");
  const value = parseExpr(p, 0);
  return {
    kind: "ConstDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    type: null,
    value,
    decorators,
  };
}

/** `name : type : value` — Odin-style typed top-level const. Mirrors the
 *  `name : type : value` form for local immutable lets so the typed-const
 *  surface is uniform between top-level and statement scopes. */
function parseTypedConstDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
): A.ConstDecl {
  const nameTok = p.advance(); // name
  p.advance(); // first `:`
  const type = parseType(p);
  p.expect("colon", "`:` between type annotation and value");
  const value = parseExpr(p, 0);
  return {
    kind: "ConstDecl",
    id: UNASSIGNED_NODE_ID, span: p.spanOf(nameTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    type,
    value,
    decorators,
  };
}
