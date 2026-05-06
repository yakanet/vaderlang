// Declaration parsing — the top-level dispatcher and every per-decl rule.
// Decls are: `import`, `name :: <fn|struct|trait|type|expr>`, `name :=
// <expr>` (forbidden at top level), and `Type implements Trait { … }`. Each
// rule consumes its own keyword run-on and produces a fully-formed AST node.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Token } from "../../lexer/token.ts";
import type * as A from "../ast.ts";
import type { Parser } from "../parser.ts";
import { collectTypeParams, describeToken } from "../parser.ts";

import { parseExpr } from "./expr.ts";
import { parseBlock } from "./stmt.ts";
import { parseType } from "./type.ts";

export function parseDecl(p: Parser): A.Decl | null {
  const decorators = parseDecorators(p);
  const visibility: A.Visibility = p.match("kw_private") !== null ? "private" : "public";

  if (p.check("kw_import")) {
    return parseImportDecl(p, decorators);
  }

  if (isImplDecl(p)) {
    return parseImplDecl(p, decorators);
  }

  // `name :: <fn|struct|trait|type|expr>` or `name := expr` (top-level forbidden) etc.
  if (p.check("ident") && p.check("decl_const", 1)) {
    return parseNamedDecl(p, decorators, visibility);
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
      span: p.spanOf(at, p.peek(-1)),
      name: nameTok.text,
      args,
    });
    p.skipNewlines();
  }
  return out;
}

function parseImportDecl(p: Parser, decorators: readonly A.Decorator[]): A.ImportDecl {
  const start = p.advance(); // consume `import`
  const pathTok = expectStringLiteral(p, "import path");
  const path = pathTok.text;

  let binding: A.ImportBinding = { kind: "namespace" };
  if (p.match("kw_as") !== null) {
    const alias = p.expect("ident", "alias name after `as`");
    binding = { kind: "alias", alias: alias.text };
  } else if (p.match("lbrace") !== null) {
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
          name: name.text,
          alias,
          span: p.spanOf(name, p.peek(-1)),
        });
        p.skipNewlines();
      } while (p.match("comma") !== null);
    }
    p.skipNewlines();
    p.expect("rbrace", "`}` to close import list");
    binding = { kind: "destructure", names };
  }

  return {
    kind: "ImportDecl",
    span: p.spanOf(start, p.peek(-1)),
    path,
    binding,
    decorators,
  };
}

function expectStringLiteral(p: Parser, what: string): { text: string; span: Span } {
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
  const traitTok = p.expect("ident", "trait name");

  // Optional generic args on the trait reference: `… implements Iterator(i32)`.
  const traitArgs: A.TypeExpr[] = [];
  if (p.match("lparen") !== null) {
    p.skipNewlines();
    if (!p.check("rparen")) {
      while (true) {
        p.skipNewlines();
        if (p.check("rparen")) break;
        traitArgs.push(parseType(p));
        p.skipNewlines();
        if (p.match("comma") === null) break;
      }
    }
    p.expect("rparen", "`)` to close trait argument list");
  }

  p.expect("lbrace", "`{` to open impl body");
  p.skipNewlines();
  const members: A.FnDecl[] = [];
  while (!p.check("rbrace") && !p.check("eof")) {
    const fn = parseFnDeclInsideTrait(p);
    if (fn !== null) members.push(fn);
    p.skipNewlines();
  }
  const endTok = p.expect("rbrace", "`}` to close impl body");
  return {
    kind: "ImplDecl",
    span: p.spanOf(startTok, endTok),
    forType,
    traitName: traitTok.text,
    traitNameSpan: traitTok.span,
    traitArgs,
    members,
    decorators,
  };
}

function parseNamedDecl(p: Parser, decorators: readonly A.Decorator[], visibility: A.Visibility): A.Decl {
  const nameTok = p.advance(); // ident
  p.advance(); // ::

  if (p.check("kw_fn")) return parseFnDecl(p, decorators, visibility, nameTok);
  if (p.check("kw_struct")) return parseStructDecl(p, decorators, visibility, nameTok);
  if (p.check("kw_enum")) return parseEnumDecl(p, decorators, visibility, nameTok);
  if (p.check("kw_trait")) return parseTraitDecl(p, decorators, visibility, nameTok);
  if (p.check("kw_type")) return parseTypeAliasDecl(p, decorators, visibility, nameTok);

  return parseConstDecl(p, decorators, visibility, nameTok);
}

function parseFnDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.FnDecl {
  p.advance(); // fn
  const { params, typeParams } = parseFnSignatureParams(p);
  let returnType: A.TypeExpr | null = null;
  if (p.match("arrow") !== null) returnType = parseType(p);
  const whereClauses = parseWhereClauses(p);

  let body: A.BlockExpr | null = null;
  if (p.check("lbrace")) body = parseBlock(p);
  // No-body fns are allowed for @extern declarations and trait method signatures.

  return {
    kind: "FnDecl",
    span: p.spanOf(nameTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    params,
    returnType,
    whereClauses,
    body,
    decorators,
  };
}

/** Same fn syntax used in trait member lists and impl bodies — body optional. */
function parseFnDeclInsideTrait(p: Parser): A.FnDecl | null {
  const decorators = parseDecorators(p);
  const visibility: A.Visibility = p.match("kw_private") !== null ? "private" : "public";
  if (!p.check("kw_fn")) {
    const t = p.peek();
    p.error("P1006", t.span, `expected a function inside trait/impl (got ${describeToken(t)})`);
    // recover
    while (!p.check("rbrace") && !p.check("eof") && !p.check("kw_fn")) p.advance();
    return null;
  }
  const fnTok = p.advance(); // fn
  const nameTok = p.expect("ident", "function name");
  const { params, typeParams } = parseFnSignatureParams(p);
  let returnType: A.TypeExpr | null = null;
  if (p.match("arrow") !== null) returnType = parseType(p);
  const whereClauses = parseWhereClauses(p);
  let body: A.BlockExpr | null = null;
  if (p.check("lbrace")) body = parseBlock(p);
  return {
    kind: "FnDecl",
    span: p.spanOf(fnTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    params,
    returnType,
    whereClauses,
    body,
    decorators,
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
        span: p.spanOf(startTok, p.peek(-1)),
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

function parseWhereClauses(p: Parser): A.WhereClause[] {
  if (p.match("kw_where") === null) return [];
  const out: A.WhereClause[] = [];
  do {
    const start = p.peek();
    const typeName = p.expect("ident", "type parameter name in `where`");
    p.expect("colon", "`:` between type param and trait bound");
    // Multi-trait bound: `T: A + B + C` flattens into one clause per trait.
    do {
      const traitName = p.expect("ident", "trait name in `where` clause");
      out.push({
        span: p.spanOf(start, traitName),
        typeName: typeName.text,
        traitName: traitName.text,
      });
    } while (p.match("plus") !== null);
  } while (p.match("comma") !== null);
  return out;
}

function parseStructDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.StructDecl {
  p.advance(); // struct
  const typeParams: A.TypeParam[] = parseStructTypeParamList(p);
  const whereClauses = parseWhereClauses(p);
  p.expect("lbrace", "`{` to open struct body");
  p.skipNewlines();
  const fields: A.StructField[] = [];
  while (!p.check("rbrace") && !p.check("eof")) {
    const fieldVisibility: A.Visibility = p.match("kw_private") !== null ? "private" : "public";
    const start = p.peek();
    const fname = p.expect("ident", "field name");
    p.expect("colon", "`:` after field name");
    const ftype = parseType(p);
    fields.push({
      span: p.spanOf(start, p.peek(-1)),
      name: fname.text,
      type: ftype,
      visibility: fieldVisibility,
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
    span: p.spanOf(nameTok, endTok),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    fields,
    whereClauses,
    decorators,
  };
}

/** Parse the optional `($T, $U, $N: i32)` head on a struct/trait declaration. */
function parseStructTypeParamList(p: Parser): A.TypeParam[] {
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
      } else if (bound?.kind === "NamedType" && bound.name === "type") {
        p.error("P1019", p.spanOf(start, p.peek(-1)),
          `\`: type\` bound is redundant; write \`$${name.text}\``);
        bound = null;
      }
      const isComptimeValue = bound !== null;
      out.push({
        span: p.spanOf(start, p.peek(-1)),
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
  p.expect("lbrace", "`{` to open trait body");
  p.skipNewlines();
  const members: A.FnDecl[] = [];
  while (!p.check("rbrace") && !p.check("eof")) {
    const fn = parseFnDeclInsideTrait(p);
    if (fn !== null) members.push(fn);
    p.skipNewlines();
  }
  const endTok = p.expect("rbrace", "`}` to close trait body");
  return {
    kind: "TraitDecl",
    span: p.spanOf(nameTok, endTok),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
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
    variants.push({ span: vTok.span, name: vTok.text, value, valueSpan });
    p.match("comma");
    p.skipNewlines();
  }
  const endTok = p.expect("rbrace", "`}` to close enum body");
  return {
    kind: "EnumDecl",
    span: p.spanOf(nameTok, endTok),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    repr,
    variants,
    decorators,
  };
}

function parseTypeAliasDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.TypeAliasDecl {
  p.advance(); // type
  const typeParams = parseStructTypeParamList(p);
  const aliased = parseType(p);
  return {
    kind: "TypeAliasDecl",
    span: p.spanOf(nameTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    typeParams,
    aliased,
    decorators,
  };
}

function parseConstDecl(
  p: Parser,
  decorators: readonly A.Decorator[],
  visibility: A.Visibility,
  nameTok: Token,
): A.ConstDecl {
  let type: A.TypeExpr | null = null;
  if (p.match("colon") !== null) type = parseType(p);
  const value = parseExpr(p, 0);
  return {
    kind: "ConstDecl",
    span: p.spanOf(nameTok, p.peek(-1)),
    name: nameTok.text,
    nameSpan: nameTok.span,
    visibility,
    type,
    value,
    decorators,
  };
}
