// Phase 1.2 — Parser.
//
// Recursive descent for declarations / statements / types / patterns.
// Pratt parser for expressions with the precedence table from SPEC §3.
//
// All errors are emitted as structured diagnostics through the
// DiagnosticCollector — the parser never throws on user input. After an error
// it synchronizes on `}` / top-level keywords / NEWLINE so it can keep parsing.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import { PARSER, type ParserCode } from "../diagnostics/codes.ts";
import type { Token, TokenKind } from "../lexer/token.ts";
import type * as A from "./ast.ts";

export interface ParseResult {
  readonly program: A.Program;
}

export function parse(
  tokens: readonly Token[],
  file: string,
  diagnostics: DiagnosticCollector,
): ParseResult {
  return { program: new Parser(tokens, file, diagnostics).parseProgram() };
}

// ============================================================================
// Pratt precedence table
// ============================================================================
//
// (leftBP, rightBP) — higher = tighter. Left-assoc: rightBP = leftBP + 1.
// Non-assoc operators have leftBP === rightBP and emit P1010 if chained.

interface InfixOp {
  readonly leftBP: number;
  readonly rightBP: number;
  readonly op: A.BinaryOp;
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
  ["kw_is",     { leftBP:  20, rightBP:  20, op: "is",  nonAssoc: true }],
  // range (non-assoc)
  ["range_excl",{ leftBP:  30, rightBP:  30, op: "lt",  nonAssoc: true }],
  ["range_incl",{ leftBP:  30, rightBP:  30, op: "lte", nonAssoc: true }],
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

// ============================================================================
// Parser class
// ============================================================================

class Parser {
  private readonly tokens: readonly Token[];
  private readonly file: string;
  private readonly diags: DiagnosticCollector;
  private pos = 0;

  // True except inside the immediate condition expression of if/for/match/while
  private allowStructLit = true;

  constructor(tokens: readonly Token[], file: string, diags: DiagnosticCollector) {
    this.tokens = tokens;
    this.file = file;
    this.diags = diags;
  }

  // ----------------------------------------------------------- token helpers

  private peek(offset = 0): Token {
    return this.tokens[this.pos + offset] ?? this.tokens[this.tokens.length - 1]!;
  }

  private check(kind: TokenKind, offset = 0): boolean {
    return this.peek(offset).kind === kind;
  }

  /** Consume if the next token matches; return the token or null. */
  private match(kind: TokenKind): Token | null {
    if (this.check(kind)) {
      const t = this.peek();
      this.pos++;
      return t;
    }
    return null;
  }

  private advance(): Token {
    const t = this.peek();
    if (this.pos < this.tokens.length - 1) this.pos++;
    return t;
  }

  /** Expect a token; if missing emit a diagnostic but do NOT advance. */
  private expect(kind: TokenKind, what: string): Token {
    if (this.check(kind)) return this.advance();
    const t = this.peek();
    this.error("P1002", t.span, `expected ${what} (got ${describeToken(t)})`);
    return t; // synthetic — caller may use the span
  }

  private skipNewlines(): void {
    while (this.check("newline")) this.pos++;
  }

  /** Tokens that mark the boundary of a top-level item — used for recovery. */
  private atTopLevelStart(): boolean {
    const t = this.peek();
    if (t.kind === "kw_import" || t.kind === "kw_private") return true;
    // `name ::` or `Type implements …` patterns: detect by checking later tokens.
    if (t.kind === "ident") {
      const next = this.peek(1);
      if (next.kind === "decl_const" || next.kind === "kw_implements") return true;
    }
    if (t.kind === "at") return true; // decorator
    return false;
  }

  /** Skip until we reach a likely synchronization point. */
  private syncToTopLevel(): void {
    while (this.peek().kind !== "eof" && !this.atTopLevelStart()) this.advance();
  }

  // -------------------------------------------------------- error reporting

  private error(code: ParserCode, span: Span, message?: string): void {
    this.diags.emit({
      severity: "error",
      code,
      message: message !== undefined ? `${PARSER[code]}: ${message}` : PARSER[code],
      primary: span,
    });
  }

  private spanOf(start: Token, end?: Token): Span {
    const last = end ?? this.peek(-1) ?? start;
    return { start: start.span.start, end: last.span.end };
  }

  // ============================================================================
  // Top-level
  // ============================================================================

  parseProgram(): A.Program {
    const startTok = this.peek();
    const decls: A.Decl[] = [];

    this.skipNewlines();
    while (!this.check("eof")) {
      const d = this.parseDecl();
      if (d !== null) decls.push(d);
      else this.advance(); // safety advance to avoid infinite loop on weird input
      this.skipNewlines();
    }

    const endTok = this.peek();
    return {
      kind: "Program",
      file: this.file,
      span: { start: startTok.span.start, end: endTok.span.end },
      decls,
    };
  }

  // ============================================================================
  // Declarations
  // ============================================================================

  private parseDecl(): A.Decl | null {
    const decorators = this.parseDecorators();
    const visibility: A.Visibility = this.match("kw_private") !== null ? "private" : "public";

    if (this.check("kw_import")) {
      return this.parseImportDecl(decorators);
    }

    if (this.isImplDecl()) {
      return this.parseImplDecl(decorators);
    }

    // `name :: <fn|struct|trait|type|expr>` or `name := expr` (top-level forbidden) etc.
    if (this.check("ident") && this.check("decl_const", 1)) {
      return this.parseNamedDecl(decorators, visibility);
    }

    const t = this.peek();
    this.error("P1006", t.span, `got ${describeToken(t)}`);
    this.syncToTopLevel();
    return null;
  }

  private parseDecorators(): A.Decorator[] {
    const out: A.Decorator[] = [];
    while (this.check("at")) {
      const at = this.advance();
      const nameTok = this.expect("ident", "decorator name after `@`");
      const args: A.Expr[] = [];
      if (this.match("lparen") !== null) {
        if (!this.check("rparen")) {
          do {
            args.push(this.parseExpr(0));
          } while (this.match("comma") !== null && !this.check("rparen"));
        }
        this.expect("rparen", "`)` after decorator arguments");
      }
      out.push({
        span: this.spanOf(at, this.peek(-1)),
        name: nameTok.text,
        args,
      });
      this.skipNewlines();
    }
    return out;
  }

  // -------------------------------------------------- import

  private parseImportDecl(decorators: readonly A.Decorator[]): A.ImportDecl {
    const start = this.advance(); // consume `import`
    const pathTok = this.expectStringLiteral("import path");
    const path = pathTok.text;

    let binding: A.ImportBinding = { kind: "namespace" };
    if (this.match("kw_as") !== null) {
      const alias = this.expect("ident", "alias name after `as`");
      binding = { kind: "alias", alias: alias.text };
    } else if (this.match("lbrace") !== null) {
      const names: A.ImportName[] = [];
      this.skipNewlines();
      if (!this.check("rbrace")) {
        do {
          this.skipNewlines();
          if (this.check("rbrace")) break;
          const name = this.expect("ident", "imported name");
          let alias: string | null = null;
          if (this.match("kw_as") !== null) {
            alias = this.expect("ident", "alias after `as`").text;
          }
          names.push({
            name: name.text,
            alias,
            span: this.spanOf(name, this.peek(-1)),
          });
          this.skipNewlines();
        } while (this.match("comma") !== null);
      }
      this.skipNewlines();
      this.expect("rbrace", "`}` to close import list");
      binding = { kind: "destructure", names };
    }

    return {
      kind: "ImportDecl",
      span: this.spanOf(start, this.peek(-1)),
      path,
      binding,
      decorators,
    };
  }

  private expectStringLiteral(what: string): { text: string; span: Span } {
    if (!this.check("string_begin")) {
      const t = this.peek();
      this.error("P1002", t.span, `expected ${what} (got ${describeToken(t)})`);
      return { text: "", span: t.span };
    }
    const begin = this.advance();
    let text = "";
    while (!this.check("string_end") && !this.check("eof")) {
      const t = this.advance();
      if (t.kind === "string_part" && t.stringValue !== undefined) text += t.stringValue;
      // No interpolation expected here — error if seen.
      if (t.kind === "interp_open") {
        this.error("P1003", t.span, "interpolation not allowed in import path");
        // skip to interp_close
        while (!this.check("interp_close") && !this.check("eof")) this.advance();
      }
    }
    const end = this.match("string_end") ?? this.peek();
    return { text, span: this.spanOf(begin, end) };
  }

  // -------------------------------------------------- impl

  private isImplDecl(): boolean {
    let i = this.pos;
    let depth = 0;
    while (i < this.tokens.length) {
      const t = this.tokens[i]!;
      if (t.kind === "eof" || t.kind === "newline") return false;
      if (t.kind === "kw_implements" && depth === 0) return true;
      if (t.kind === "lparen" || t.kind === "lbracket" || t.kind === "lbrace") depth++;
      if (t.kind === "rparen" || t.kind === "rbracket" || t.kind === "rbrace") depth--;
      if (depth < 0) return false;
      i++;
    }
    return false;
  }

  private parseImplDecl(decorators: readonly A.Decorator[]): A.ImplDecl {
    const startTok = this.peek();
    const forType = this.parseType();
    this.expect("kw_implements", "`implements` keyword");
    const traitTok = this.expect("ident", "trait name");
    this.expect("lbrace", "`{` to open impl body");
    this.skipNewlines();
    const members: A.FnDecl[] = [];
    while (!this.check("rbrace") && !this.check("eof")) {
      const fn = this.parseFnDeclInsideTrait();
      if (fn !== null) members.push(fn);
      this.skipNewlines();
    }
    const endTok = this.expect("rbrace", "`}` to close impl body");
    return {
      kind: "ImplDecl",
      span: this.spanOf(startTok, endTok),
      forType,
      traitName: traitTok.text,
      traitNameSpan: traitTok.span,
      members,
      decorators,
    };
  }

  // -------------------------------------------------- name :: <kw|expr>

  private parseNamedDecl(decorators: readonly A.Decorator[], visibility: A.Visibility): A.Decl {
    const nameTok = this.advance(); // ident
    this.advance(); // ::

    if (this.check("kw_fn")) return this.parseFnDecl(decorators, visibility, nameTok);
    if (this.check("kw_struct")) return this.parseStructDecl(decorators, visibility, nameTok);
    if (this.check("kw_trait")) return this.parseTraitDecl(decorators, visibility, nameTok);
    if (this.check("kw_type")) return this.parseTypeAliasDecl(decorators, visibility, nameTok);

    return this.parseConstDecl(decorators, visibility, nameTok);
  }

  // -------------------------------------------------- fn

  private parseFnDecl(
    decorators: readonly A.Decorator[],
    visibility: A.Visibility,
    nameTok: Token,
  ): A.FnDecl {
    this.advance(); // fn
    const { params, typeParams } = this.parseFnSignatureParams();
    let returnType: A.TypeExpr | null = null;
    if (this.match("arrow") !== null) returnType = this.parseType();
    const whereClauses = this.parseWhereClauses();

    let body: A.BlockExpr | null = null;
    if (this.check("lbrace")) body = this.parseBlock();
    // No-body fns are allowed for @extern declarations and trait method signatures.

    return {
      kind: "FnDecl",
      span: this.spanOf(nameTok, this.peek(-1)),
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
  private parseFnDeclInsideTrait(): A.FnDecl | null {
    const decorators = this.parseDecorators();
    const visibility: A.Visibility = this.match("kw_private") !== null ? "private" : "public";
    if (!this.check("kw_fn")) {
      const t = this.peek();
      this.error("P1006", t.span, `expected a function inside trait/impl (got ${describeToken(t)})`);
      // recover
      while (!this.check("rbrace") && !this.check("eof") && !this.check("kw_fn")) this.advance();
      return null;
    }
    const fnTok = this.advance(); // fn
    const nameTok = this.expect("ident", "function name");
    const { params, typeParams } = this.parseFnSignatureParams();
    let returnType: A.TypeExpr | null = null;
    if (this.match("arrow") !== null) returnType = this.parseType();
    const whereClauses = this.parseWhereClauses();
    let body: A.BlockExpr | null = null;
    if (this.check("lbrace")) body = this.parseBlock();
    return {
      kind: "FnDecl",
      span: this.spanOf(fnTok, this.peek(-1)),
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

  private parseFnSignatureParams(): { params: A.FnParam[]; typeParams: A.TypeParam[] } {
    const typeParams: A.TypeParam[] = [];
    const params: A.FnParam[] = [];

    this.expect("lparen", "`(` after function name");
    this.skipNewlines();
    if (!this.check("rparen")) {
      let first = true;
      while (true) {
        this.skipNewlines();
        if (this.check("rparen") || this.check("eof")) break;
        if (!first) {
          if (this.match("comma") === null) break;
          this.skipNewlines();
          if (this.check("rparen")) break; // trailing comma
        }
        first = false;

        const startTok = this.peek();
        // `...rest: T` variadic is encoded as three consecutive `.` tokens by the lexer.
        let isVariadic = false;
        if (this.check("dot") && this.check("dot", 1) && this.check("dot", 2)) {
          this.advance(); this.advance(); this.advance();
          isVariadic = true;
        }

        let paramNameTok: Token;
        if (this.check("kw_self") || this.check("ident")) {
          paramNameTok = this.advance();
        } else {
          const t = this.peek();
          this.error("P1002", t.span, `expected parameter name (got ${describeToken(t)})`);
          while (!this.check("comma") && !this.check("rparen") && !this.check("eof")) this.advance();
          continue;
        }

        let type: A.TypeExpr | null = null;
        if (this.match("colon") !== null) {
          this.skipNewlines();
          type = this.parseType();
        }
        let defaultValue: A.Expr | null = null;
        if (this.match("assign") !== null) {
          defaultValue = this.parseExpr(0);
        }

        // Collect any inline `$T` introduced in this param's type.
        if (type !== null) collectTypeParams(type, typeParams);

        params.push({
          span: this.spanOf(startTok, this.peek(-1)),
          name: paramNameTok.text,
          type,
          defaultValue,
          variadic: isVariadic,
        });
      }
    }
    this.expect("rparen", "`)` to close parameter list");

    return { params, typeParams };
  }

  private parseWhereClauses(): A.WhereClause[] {
    if (this.match("kw_where") === null) return [];
    const out: A.WhereClause[] = [];
    do {
      const start = this.peek();
      const typeName = this.expect("ident", "type parameter name in `where`");
      this.expect("colon", "`:` between type param and trait bound");
      // Multi-trait bound: `T: A + B + C` flattens into one clause per trait.
      do {
        const traitName = this.expect("ident", "trait name in `where` clause");
        out.push({
          span: this.spanOf(start, traitName),
          typeName: typeName.text,
          traitName: traitName.text,
        });
      } while (this.match("plus") !== null);
    } while (this.match("comma") !== null);
    return out;
  }

  // -------------------------------------------------- struct

  private parseStructDecl(
    decorators: readonly A.Decorator[],
    visibility: A.Visibility,
    nameTok: Token,
  ): A.StructDecl {
    this.advance(); // struct
    const typeParams: A.TypeParam[] = this.parseStructTypeParamList();
    const whereClauses = this.parseWhereClauses();
    this.expect("lbrace", "`{` to open struct body");
    this.skipNewlines();
    const fields: A.StructField[] = [];
    while (!this.check("rbrace") && !this.check("eof")) {
      const fieldVisibility: A.Visibility = this.match("kw_private") !== null ? "private" : "public";
      const start = this.peek();
      const fname = this.expect("ident", "field name");
      this.expect("colon", "`:` after field name");
      const ftype = this.parseType();
      fields.push({
        span: this.spanOf(start, this.peek(-1)),
        name: fname.text,
        type: ftype,
        visibility: fieldVisibility,
      });
      // Field separator: newline or comma.
      if (!this.check("rbrace")) {
        if (!this.match("comma")) this.skipNewlines();
        else this.skipNewlines();
      }
    }
    const endTok = this.expect("rbrace", "`}` to close struct body");
    return {
      kind: "StructDecl",
      span: this.spanOf(nameTok, endTok),
      name: nameTok.text,
      nameSpan: nameTok.span,
      visibility,
      typeParams,
      fields,
      whereClauses,
      decorators,
    };
  }

  /** Parse the optional `(T: type, U: type, $N: i32)` head on a struct/trait declaration. */
  private parseStructTypeParamList(): A.TypeParam[] {
    if (!this.match("lparen")) return [];
    const out: A.TypeParam[] = [];
    if (!this.check("rparen")) {
      let first = true;
      while (true) {
        this.skipNewlines();
        if (this.check("rparen")) break;
        if (!first) this.expect("comma", "`,` between type parameters");
        if (this.check("rparen")) break;
        first = false;

        const isComptime = this.match("dollar") !== null;
        const start = this.peek();
        const name = this.expect("ident", "type parameter name");
        this.expect("colon", "`:` between name and bound");
        const bound = this.parseType();
        out.push({
          span: this.spanOf(start, this.peek(-1)),
          name: name.text,
          bound,
          isComptimeValue: isComptime,
        });
      }
    }
    this.expect("rparen", "`)` to close type parameter list");
    return out;
  }

  // -------------------------------------------------- trait

  private parseTraitDecl(
    decorators: readonly A.Decorator[],
    visibility: A.Visibility,
    nameTok: Token,
  ): A.TraitDecl {
    this.advance(); // trait
    const typeParams = this.parseStructTypeParamList();
    this.expect("lbrace", "`{` to open trait body");
    this.skipNewlines();
    const members: A.FnDecl[] = [];
    while (!this.check("rbrace") && !this.check("eof")) {
      const fn = this.parseFnDeclInsideTrait();
      if (fn !== null) members.push(fn);
      this.skipNewlines();
    }
    const endTok = this.expect("rbrace", "`}` to close trait body");
    return {
      kind: "TraitDecl",
      span: this.spanOf(nameTok, endTok),
      name: nameTok.text,
      nameSpan: nameTok.span,
      visibility,
      typeParams,
      members,
      decorators,
    };
  }

  // -------------------------------------------------- type alias

  private parseTypeAliasDecl(
    decorators: readonly A.Decorator[],
    visibility: A.Visibility,
    nameTok: Token,
  ): A.TypeAliasDecl {
    this.advance(); // type
    const typeParams = this.parseStructTypeParamList();
    const aliased = this.parseType();
    return {
      kind: "TypeAliasDecl",
      span: this.spanOf(nameTok, this.peek(-1)),
      name: nameTok.text,
      nameSpan: nameTok.span,
      visibility,
      typeParams,
      aliased,
      decorators,
    };
  }

  // -------------------------------------------------- constant

  private parseConstDecl(
    decorators: readonly A.Decorator[],
    visibility: A.Visibility,
    nameTok: Token,
  ): A.ConstDecl {
    let type: A.TypeExpr | null = null;
    if (this.match("colon") !== null) type = this.parseType();
    const value = this.parseExpr(0);
    return {
      kind: "ConstDecl",
      span: this.spanOf(nameTok, this.peek(-1)),
      name: nameTok.text,
      nameSpan: nameTok.span,
      visibility,
      type,
      value,
      decorators,
    };
  }

  // ============================================================================
  // Statements
  // ============================================================================

  private parseStmt(): A.Stmt | null {
    if (this.check("kw_return")) return this.parseReturn();
    if (this.check("kw_for")) return this.parseFor(null);
    if (this.check("kw_break")) return this.parseBreakContinue("break") as A.BreakStmt;
    if (this.check("kw_continue")) return this.parseBreakContinue("continue") as A.ContinueStmt;
    if (this.check("kw_defer")) return this.parseDefer();

    // Labeled for: `label: for ...`
    if (this.check("ident") && this.check("colon", 1) && this.check("kw_for", 2)) {
      const labelTok = this.advance();
      this.advance(); // colon
      return this.parseFor(labelTok.text);
    }

    // `name :: expr` or `name := expr`
    if (this.check("ident") && (this.check("decl_const", 1) || this.check("decl_var", 1))) {
      return this.parseLet();
    }

    // Otherwise: expression statement (with possible assignment trailing)
    const start = this.peek();
    const expr = this.parseExpr(0);
    if (this.match("assign") !== null) {
      const value = this.parseExpr(0);
      return {
        kind: "AssignStmt",
        span: this.spanOf(start, this.peek(-1)),
        target: expr,
        value,
      };
    }
    return {
      kind: "ExprStmt",
      span: expr.span,
      expr,
    };
  }

  private parseLet(): A.LetStmt {
    const nameTok = this.advance();
    const declTok = this.advance(); // :: or :=
    const mutable = declTok.kind === "decl_var";

    let type: A.TypeExpr | null = null;
    // No explicit `: T` after `::`/`:=` — type annotations only occur on top-level constants.
    // Spec uses `x: i64 = 42` form for explicit annotation:
    // BUT: `:=` already establishes mutability; user might want `x: T := value`.
    // For MVP we don't support that — `x := T(value)` works as a cast workaround.

    const value = this.parseExpr(0);
    return {
      kind: "LetStmt",
      span: this.spanOf(nameTok, this.peek(-1)),
      mutable,
      name: nameTok.text,
      nameSpan: nameTok.span,
      type,
      value,
    };
  }

  private parseReturn(): A.ReturnStmt {
    const start = this.advance(); // return
    let value: A.Expr | null = null;
    if (!this.check("newline") && !this.check("rbrace") && !this.check("eof")) {
      value = this.parseExpr(0);
    }
    return {
      kind: "ReturnStmt",
      span: this.spanOf(start, this.peek(-1)),
      value,
    };
  }

  private parseFor(label: string | null): A.ForStmt {
    const start = this.advance(); // for

    // Forms:
    //   for { ... }              infinite
    //   for cond { ... }         while-style
    //   for x in iter { ... }    iteration
    if (this.check("lbrace")) {
      const body = this.parseBlock();
      return {
        kind: "ForStmt",
        span: { start: start.span.start, end: body.span.end },
        label,
        form: { kind: "infinite" },
        body,
      };
    }

    const savedAllow = this.allowStructLit;
    this.allowStructLit = false;

    // `x in iter` requires a 2-token lookahead: ident followed by `in`.
    if (this.check("ident") && this.check("kw_in", 1)) {
      const bindTok = this.advance();
      this.advance(); // in
      const iter = this.parseExpr(0);
      this.allowStructLit = savedAllow;
      const body = this.parseBlock();
      return {
        kind: "ForStmt",
        span: { start: start.span.start, end: body.span.end },
        label,
        form: { kind: "in", binding: bindTok.text, bindingSpan: bindTok.span, iter },
        body,
      };
    }

    const cond = this.parseExpr(0);
    this.allowStructLit = savedAllow;
    const body = this.parseBlock();
    return {
      kind: "ForStmt",
      span: { start: start.span.start, end: body.span.end },
      label,
      form: { kind: "while", cond },
      body,
    };
  }

  private parseBreakContinue(which: "break" | "continue"): A.BreakStmt | A.ContinueStmt {
    const start = this.advance();
    let label: string | null = null;
    if (this.check("ident")) {
      label = this.advance().text;
    }
    return which === "break"
      ? { kind: "BreakStmt", span: this.spanOf(start, this.peek(-1)), label }
      : { kind: "ContinueStmt", span: this.spanOf(start, this.peek(-1)), label };
  }

  private parseDefer(): A.DeferStmt {
    const start = this.advance();
    const body: A.Stmt | A.BlockExpr = this.check("lbrace")
      ? this.parseBlock()
      : (this.parseStmt() ?? { kind: "ExprStmt", span: start.span, expr: this.placeholderExpr(start) });
    return {
      kind: "DeferStmt",
      span: { start: start.span.start, end: body.span.end },
      body,
    };
  }

  // ============================================================================
  // Block expression
  // ============================================================================

  private parseBlock(): A.BlockExpr {
    const lb = this.expect("lbrace", "`{` to open block");
    this.skipNewlines();
    const stmts: A.Stmt[] = [];
    let trailing: A.Expr | null = null;

    while (!this.check("rbrace") && !this.check("eof")) {
      const stmt = this.parseStmt();
      if (stmt !== null) stmts.push(stmt);
      this.skipNewlines();
    }

    // Promote a trailing ExprStmt to the implicit return value.
    if (stmts.length > 0 && stmts[stmts.length - 1]!.kind === "ExprStmt") {
      const last = stmts.pop() as A.ExprStmt;
      trailing = last.expr;
    }

    const rb = this.expect("rbrace", "`}` to close block");
    return {
      kind: "BlockExpr",
      span: this.spanOf(lb, rb),
      stmts,
      trailing,
    };
  }

  // ============================================================================
  // Expressions (Pratt)
  // ============================================================================

  parseExpr(minBP: number): A.Expr {
    let left = this.parsePrefix();
    let lastNonAssocLevel = -1;

    while (true) {
      const t = this.peek();

      const postfixBP = POSTFIX_BP.get(t.kind);
      if (postfixBP !== undefined && postfixBP >= minBP) {
        left = this.parsePostfix(left, t);
        lastNonAssocLevel = -1;
        continue;
      }

      const infix = INFIX_OPS.get(t.kind);
      if (infix !== undefined && infix.leftBP >= minBP) {
        if (infix.nonAssoc === true && lastNonAssocLevel === infix.leftBP) {
          this.error("P1010", t.span, `chained \`${describeToken(t)}\``);
          break;
        }
        this.advance();
        const right = this.parseExpr(infix.rightBP + (infix.nonAssoc === true ? 1 : 0));
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
            op: infix.op,
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

  private parsePrefix(): A.Expr {
    const t = this.peek();

    switch (t.kind) {
      case "int_literal":
        this.advance();
        return {
          kind: "IntLitExpr",
          span: t.span,
          value: t.intValue ?? 0n,
          suffix: t.numericSuffix ?? null,
        };
      case "float_literal":
        this.advance();
        return {
          kind: "FloatLitExpr",
          span: t.span,
          value: t.floatValue ?? 0,
          suffix: t.numericSuffix ?? null,
        };
      case "char_literal":
        this.advance();
        return { kind: "CharLitExpr", span: t.span, value: t.charValue ?? 0 };
      case "kw_true":
        this.advance();
        return { kind: "BoolLitExpr", span: t.span, value: true };
      case "kw_false":
        this.advance();
        return { kind: "BoolLitExpr", span: t.span, value: false };
      case "kw_null":
        this.advance();
        return { kind: "NullLitExpr", span: t.span };
      case "string_begin":
        return this.parseStringLit();
      case "ident":
        return this.parseIdentOrStructLit();
      case "lparen":
        return this.parseParenOrTuple();
      case "lbracket":
        return this.parseArrayLit();
      case "lbrace":
        return this.parseBlock();
      case "minus":
      case "bang":
      case "tilde": {
        this.advance();
        const op: A.UnaryOp = t.kind === "minus" ? "neg" : t.kind === "bang" ? "not" : "bitnot";
        const operand = this.parseExpr(95); // tighter than * / %, looser than postfix
        return { kind: "UnaryExpr", span: { start: t.span.start, end: operand.span.end }, op, operand };
      }
      case "kw_if":
        return this.parseIfExpr();
      case "kw_match":
        return this.parseMatchExpr();
      case "kw_fn":
        return this.parseLambda();
      case "kw_self":
        this.advance();
        return { kind: "IdentExpr", span: t.span, name: "self" };
      default:
        this.error("P1003", t.span, `got ${describeToken(t)}`);
        this.advance();
        return this.placeholderExpr(t);
    }
  }

  private placeholderExpr(t: Token): A.Expr {
    return { kind: "NullLitExpr", span: t.span };
  }

  private parsePostfix(left: A.Expr, t: Token): A.Expr {
    if (t.kind === "question") {
      this.advance();
      return {
        kind: "TryExpr",
        span: { start: left.span.start, end: t.span.end },
        inner: left,
      };
    }
    if (t.kind === "dot") {
      this.advance();
      const name = this.expect("ident", "field name after `.`");
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
      this.advance();
      const args = this.parseCallArgs();
      this.expect("rparen", "`)` to close argument list");
      const callExpr: A.CallExpr = {
        kind: "CallExpr",
        span: { start: left.span.start, end: this.peek(-1).span.end },
        callee: left,
        args,
      };
      // If immediately followed by `{` AND struct literals are allowed, treat as struct literal.
      // Disabled for now — the explicit struct literal path `parseIdentOrStructLit` handles `Name { ... }`.
      return callExpr;
    }
    if (t.kind === "lbracket") {
      this.advance();
      const index = this.parseExpr(0);
      this.expect("rbracket", "`]` to close index");
      return {
        kind: "IndexExpr",
        span: { start: left.span.start, end: this.peek(-1).span.end },
        target: left,
        index,
      };
    }
    return left;
  }

  private parseCallArgs(): A.CallArg[] {
    const out: A.CallArg[] = [];
    this.skipNewlines();
    if (this.check("rparen")) return out;

    while (true) {
      this.skipNewlines();
      if (this.check("rparen")) break;
      const start = this.peek();
      // Spread `...expr` not supported as a call arg in MVP — but reserved syntactically.
      // Named arg detection: `ident = expr`
      if (this.check("ident") && this.check("assign", 1)) {
        const nameTok = this.advance();
        this.advance(); // =
        const value = this.parseExpr(0);
        out.push({
          span: this.spanOf(start, this.peek(-1)),
          name: nameTok.text,
          value,
          spread: false,
        });
      } else {
        const value = this.parseExpr(0);
        out.push({
          span: value.span,
          name: null,
          value,
          spread: false,
        });
      }
      this.skipNewlines();
      if (this.match("comma") === null) break;
    }
    return out;
  }

  // -------------------------------------------------- ident / struct literal

  private parseIdentOrStructLit(): A.Expr {
    const t = this.advance();
    if (this.allowStructLit && this.check("lbrace") && looksLikeStructLitBody(this.tokens, this.pos)) {
      const lb = this.advance();
      const fields = this.parseStructLitFields();
      const rb = this.expect("rbrace", "`}` to close struct literal");
      return {
        kind: "StructLitExpr",
        span: this.spanOf(t, rb),
        typeName: { kind: "NamedType", span: t.span, name: t.text },
        fields,
      };
    }
    return { kind: "IdentExpr", span: t.span, name: t.text };
  }

  private parseStructLitFields(): A.StructLitField[] {
    const out: A.StructLitField[] = [];
    this.skipNewlines();
    while (!this.check("rbrace") && !this.check("eof")) {
      this.expect("dot", "`.` before struct literal field name");
      const start = this.peek(-1);
      const name = this.expect("ident", "struct literal field name");
      this.expect("assign", "`=` after struct literal field name");
      const value = this.parseExpr(0);
      out.push({
        span: this.spanOf(start, this.peek(-1)),
        name: name.text,
        nameSpan: name.span,
        value,
      });
      this.skipNewlines();
      if (this.match("comma") === null) break;
      this.skipNewlines();
    }
    this.skipNewlines();
    return out;
  }

  // -------------------------------------------------- paren

  private parseParenOrTuple(): A.Expr {
    this.advance(); // (
    this.skipNewlines();
    const savedAllow = this.allowStructLit;
    this.allowStructLit = true;
    const expr = this.parseExpr(0);
    this.allowStructLit = savedAllow;
    this.skipNewlines();
    this.expect("rparen", "`)` to close parenthesised expression");
    return expr;
  }

  // -------------------------------------------------- array literal

  private parseArrayLit(): A.ArrayLitExpr {
    const lb = this.advance();
    const elements: A.Expr[] = [];
    this.skipNewlines();
    if (!this.check("rbracket")) {
      while (true) {
        this.skipNewlines();
        if (this.check("rbracket")) break;
        elements.push(this.parseExpr(0));
        this.skipNewlines();
        if (this.match("comma") === null) break;
        this.skipNewlines();
      }
    }
    const rb = this.expect("rbracket", "`]` to close array literal");
    return {
      kind: "ArrayLitExpr",
      span: this.spanOf(lb, rb),
      elements,
    };
  }

  // -------------------------------------------------- string literal

  private parseStringLit(): A.StringLitExpr {
    const begin = this.advance(); // string_begin
    const parts: A.StringLitPart[] = [];
    while (!this.check("string_end") && !this.check("eof")) {
      const t = this.peek();
      if (t.kind === "string_part") {
        this.advance();
        parts.push({ kind: "text", value: t.stringValue ?? t.text, span: t.span });
        continue;
      }
      if (t.kind === "interp_open") {
        const interpStart = this.advance();
        const expr = this.parseExpr(0);
        const closeTok = this.match("interp_close");
        const closeSpan = closeTok !== null ? closeTok.span : expr.span;
        parts.push({
          kind: "interp",
          expr,
          span: { start: interpStart.span.start, end: closeSpan.end },
        });
        continue;
      }
      // Unexpected token: bail to end.
      this.error("P1001", t.span, `inside string literal`);
      this.advance();
    }
    const end = this.match("string_end") ?? this.peek();
    return {
      kind: "StringLitExpr",
      span: this.spanOf(begin, end),
      parts,
    };
  }

  // -------------------------------------------------- if

  private parseIfExpr(): A.IfExpr {
    const start = this.advance(); // if
    const savedAllow = this.allowStructLit;
    this.allowStructLit = false;

    let cond: A.Expr;
    if (this.match("lparen") !== null) {
      // Parenthesised condition: struct literals allowed inside.
      this.allowStructLit = true;
      cond = this.parseExpr(0);
      this.expect("rparen", "`)` to close `if` condition");
    } else {
      cond = this.parseExpr(0);
    }
    this.allowStructLit = savedAllow;

    const thenBlock = this.parseBlock();
    let elseBranch: A.IfExpr | A.BlockExpr | null = null;
    this.skipNewlines();
    if (this.match("kw_else") !== null) {
      this.skipNewlines();
      if (this.check("kw_if")) elseBranch = this.parseIfExpr();
      else elseBranch = this.parseBlock();
    }

    return {
      kind: "IfExpr",
      span: { start: start.span.start, end: (elseBranch ?? thenBlock).span.end },
      cond,
      then: thenBlock,
      else: elseBranch,
    };
  }

  // -------------------------------------------------- match

  private parseMatchExpr(): A.MatchExpr {
    const start = this.advance(); // match
    const savedAllow = this.allowStructLit;
    this.allowStructLit = false;
    const scrutinee = this.parseExpr(0);
    this.allowStructLit = savedAllow;

    this.expect("lbrace", "`{` to open match arms");
    this.skipNewlines();
    const arms: A.MatchArm[] = [];
    while (!this.check("rbrace") && !this.check("eof")) {
      arms.push(this.parseMatchArm());
      this.skipNewlines();
      if (this.match("comma") !== null) this.skipNewlines();
    }
    const end = this.expect("rbrace", "`}` to close match");
    return {
      kind: "MatchExpr",
      span: { start: start.span.start, end: end.span.end },
      scrutinee,
      arms,
    };
  }

  private parseMatchArm(): A.MatchArm {
    const start = this.peek();
    const pattern = this.parsePattern();
    let guard: A.Expr | null = null;
    if (this.match("kw_if") !== null) {
      const savedAllow = this.allowStructLit;
      this.allowStructLit = false;
      guard = this.parseExpr(0);
      this.allowStructLit = savedAllow;
    }
    this.expect("arrow", "`->` between pattern and arm body");
    const body = this.parseExpr(0);
    return {
      span: { start: start.span.start, end: body.span.end },
      pattern,
      guard,
      body,
    };
  }

  // -------------------------------------------------- lambda

  private parseLambda(): A.LambdaExpr {
    const start = this.advance(); // fn
    const { params } = this.parseFnSignatureParams();
    let returnType: A.TypeExpr | null = null;
    if (this.match("arrow") !== null) returnType = this.parseType();
    const body = this.parseBlock();
    return {
      kind: "LambdaExpr",
      span: { start: start.span.start, end: body.span.end },
      params,
      returnType,
      body,
    };
  }

  // ============================================================================
  // Patterns
  // ============================================================================

  private parsePattern(): A.Pattern {
    const t = this.peek();
    if (t.kind === "kw_is") {
      this.advance();
      const type = this.parseType();
      let inner: A.Pattern | null = null;
      if (this.check("lbrace")) {
        inner = this.parseStructPattern();
      }
      let bindAs: string | null = null;
      if (this.match("kw_as") !== null) {
        bindAs = this.expect("ident", "binding name after `as`").text;
      }
      return {
        kind: "IsPattern",
        span: this.spanOf(t, this.peek(-1)),
        type,
        inner,
        bindAs,
      };
    }
    if (t.kind === "ident" && t.text === "_") {
      this.advance();
      return { kind: "WildcardPattern", span: t.span };
    }
    if (t.kind === "ident") {
      this.advance();
      return { kind: "BindingPattern", span: t.span, name: t.text };
    }
    this.error("P1007", t.span, `got ${describeToken(t)}`);
    this.advance();
    return { kind: "WildcardPattern", span: t.span };
  }

  private parseStructPattern(): A.StructPattern {
    const start = this.expect("lbrace", "`{` to open struct pattern");
    this.skipNewlines();
    const fields: A.StructPatternField[] = [];
    while (!this.check("rbrace") && !this.check("eof")) {
      const fStart = this.peek();
      const name = this.expect("ident", "field name in struct pattern");
      let value: A.PatternFieldValue;
      if (this.match("colon") !== null) {
        // either literal value match or rebinding
        if (this.check("ident") && !this.isLiteralStart(this.peek(1))) {
          const bindTok = this.advance();
          value = { kind: "binding", name: bindTok.text, span: bindTok.span };
        } else {
          const v = this.parseExpr(0);
          value = { kind: "literal", value: v };
        }
      } else {
        // shorthand: `{ x, y }` ⇒ binding to fields with same name
        value = { kind: "binding", name: name.text, span: name.span };
      }
      fields.push({
        span: this.spanOf(fStart, this.peek(-1)),
        name: name.text,
        nameSpan: name.span,
        value,
      });
      this.skipNewlines();
      if (this.match("comma") === null) break;
      this.skipNewlines();
    }
    const end = this.expect("rbrace", "`}` to close struct pattern");
    return {
      kind: "StructPattern",
      span: { start: start.span.start, end: end.span.end },
      fields,
    };
  }

  private isLiteralStart(t: Token): boolean {
    return t.kind === "int_literal"
      || t.kind === "float_literal"
      || t.kind === "char_literal"
      || t.kind === "string_begin"
      || t.kind === "kw_true"
      || t.kind === "kw_false"
      || t.kind === "kw_null"
      || t.kind === "minus";
  }

  // ============================================================================
  // Types
  // ============================================================================

  private parseType(): A.TypeExpr {
    let head = this.parseTypePrimary();
    // Postfix `!`: `T!` desugars to `T | Error` (SPEC §10).
    if (this.match("bang") !== null) {
      const bangEnd = this.peek(-1).span.end;
      head = {
        kind: "UnionType",
        span: { start: head.span.start, end: bangEnd },
        variants: [head, { kind: "NamedType", span: { start: bangEnd, end: bangEnd }, name: "Error" }],
      };
    }
    // Union: `T | U | V`
    if (this.check("pipe")) {
      const variants: A.TypeExpr[] = [head];
      const startTok = head;
      while (this.match("pipe") !== null) {
        variants.push(this.parseTypePrimary());
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

  private parseTypePrimary(): A.TypeExpr {
    const t = this.peek();
    if (t.kind === "dollar") {
      this.advance();
      const name = this.expect("ident", "type parameter name after `$`");
      return { kind: "TypeParamType", span: this.spanOf(t, name), name: name.text };
    }
    if (t.kind === "kw_fn") {
      return this.parseFnType();
    }
    if (t.kind === "lbracket") {
      const start = this.advance();
      const inner = this.parseType();
      const end = this.expect("rbracket", "`]` to close array type");
      return {
        kind: "ArrayTypeExpr",
        span: this.spanOf(start, end),
        element: inner,
      };
    }
    if (t.kind === "kw_null") {
      this.advance();
      return { kind: "NamedType", span: t.span, name: "null" };
    }
    if (t.kind === "kw_type") {
      // `type` as a type bound: `(T: type)` — the metatype.
      this.advance();
      return { kind: "NamedType", span: t.span, name: "type" };
    }
    if (t.kind === "ident") {
      const name = this.advance();
      const named: A.NamedType = { kind: "NamedType", span: name.span, name: name.text };
      // Generic instantiation: `Foo(i32, U)`
      if (this.check("lparen")) {
        this.advance();
        const args: A.TypeExpr[] = [];
        this.skipNewlines();
        if (!this.check("rparen")) {
          while (true) {
            this.skipNewlines();
            if (this.check("rparen")) break;
            args.push(this.parseType());
            this.skipNewlines();
            if (this.match("comma") === null) break;
          }
        }
        const end = this.expect("rparen", "`)` to close generic argument list");
        return {
          kind: "GenericInstType",
          span: this.spanOf(name, end),
          base: named,
          args,
        };
      }
      return named;
    }
    this.error("P1005", t.span, `got ${describeToken(t)}`);
    this.advance();
    return { kind: "NamedType", span: t.span, name: "?" };
  }

  private parseFnType(): A.FnTypeExpr {
    const start = this.advance(); // fn
    this.expect("lparen", "`(` after `fn` in function type");
    const params: A.TypeExpr[] = [];
    this.skipNewlines();
    if (!this.check("rparen")) {
      while (true) {
        this.skipNewlines();
        if (this.check("rparen")) break;
        params.push(this.parseType());
        this.skipNewlines();
        if (this.match("comma") === null) break;
      }
    }
    this.expect("rparen", "`)` after function parameter types");
    let returnType: A.TypeExpr | null = null;
    if (this.match("arrow") !== null) returnType = this.parseType();
    return {
      kind: "FnTypeExpr",
      span: this.spanOf(start, this.peek(-1)),
      params,
      returnType,
    };
  }
}

// ============================================================================
// Helpers
// ============================================================================

function describeToken(t: Token): string {
  if (t.kind === "ident") return `\`${t.text}\``;
  if (t.kind === "int_literal" || t.kind === "float_literal") return t.text;
  if (t.kind === "newline") return "newline";
  if (t.kind === "eof") return "end of file";
  return t.text !== "" ? `\`${t.text}\`` : t.kind;
}

/**
 * Walk a type expression and collect any inline `$T` introductions that should
 * become typeParams of the surrounding function. Each unique name is added once.
 */
function collectTypeParams(t: A.TypeExpr, out: A.TypeParam[]): void {
  switch (t.kind) {
    case "TypeParamType": {
      if (!out.some((p) => p.name === t.name)) {
        out.push({ span: t.span, name: t.name, bound: null, isComptimeValue: false });
      }
      return;
    }
    case "UnionType":
      for (const v of t.variants) collectTypeParams(v, out);
      return;
    case "FnTypeExpr":
      for (const p of t.params) collectTypeParams(p, out);
      if (t.returnType !== null) collectTypeParams(t.returnType, out);
      return;
    case "ArrayTypeExpr":
      collectTypeParams(t.element, out);
      return;
    case "GenericInstType":
      for (const a of t.args) collectTypeParams(a, out);
      return;
    case "NamedType":
      return;
  }
}

/**
 * After consuming an ident, decide whether the following `{` opens a struct
 * literal. The shape we accept: `{ .field = ... }` — the very first significant
 * token inside the braces must be `.`.
 */
function looksLikeStructLitBody(tokens: readonly Token[], posAfterLbrace: number): boolean {
  // posAfterLbrace points at the `{` itself (we haven't consumed it).
  let i = posAfterLbrace + 1;
  while (i < tokens.length) {
    const t = tokens[i]!;
    if (t.kind === "newline") { i++; continue; }
    return t.kind === "dot";
  }
  return false;
}
