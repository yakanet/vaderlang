// Expression parsing. A Pratt parser drives the precedence ladder; the
// per-form entries (literals, idents/struct-lits, blocks, lambda, if, match,
// patterns, string interpolation, array literals) live as regular helpers
// below. This file also owns the static precedence tables (INFIX_OPS,
// POSTFIX_BP) and the postfix-call/index/field rewriter.

import type { Token, TokenKind } from "../../lexer/token.ts";
import type * as A from "../ast.ts";
import { UNASSIGNED_NODE_ID } from "../ast.ts";
import type { Parser } from "../parser.ts";
import { describeToken, looksLikeStructLitBody } from "../parser.ts";

import { parseBlock } from "./stmt.ts";
import { parseIfExpr, parseLambda, parseMatchExpr } from "./control.ts";
import { parseFnSignatureParams } from "./decl.ts";
import { parseGenericArgList, parseType } from "./type.ts";
import { intrinsicSpec } from "../intrinsics.ts";

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

  // Single-param lambda sugar: `x -> expr`. Only fires when the prefix
  // parse returned a bare IdentExpr (no postfix / struct-lit consumed) and
  // an `arrow` follows immediately. Higher-arity / typed-params lambdas
  // go through the `(params) -> body` path in parsePrefix.
  if (left.kind === "IdentExpr" && p.check("arrow")) {
    left = parseSingleParamLambdaTail(p, left);
  }

  let lastNonAssocLevel = -1;

  while (true) {
    const t = p.peek();

    const postfixBP = POSTFIX_BP.get(t.kind);
    if (postfixBP !== undefined && postfixBP >= minBP) {
      // Block-tail expressions (`if { … }`, `match { … }`, bare `{ … }`)
      // don't auto-chain `[ … ]` index or `( … )` call postfix : the
      // next statement could legitimately start with `[` (tuple-let
      // destructure) or `(`, and Vader's free-form whitespace can't
      // tell the two cases apart. Force parens for inline chaining —
      // `(if c { x } else { y })[0]`. Field access (`.f`) stays
      // unambiguous since a stmt-leading `.` is rare and parsed via a
      // separate prefix path.
      if ((t.kind === "lbracket" || t.kind === "lparen")
          && (left.kind === "IfExpr" || left.kind === "MatchExpr" || left.kind === "BlockExpr")) {
        break;
      }
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
        id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: right.span.end },
        op: "not_in",
        left,
        right,
      };
      lastNonAssocLevel = 20;
      continue;
    }

    // `!is` desugars to `Not(BinaryExpr.Is)` ; the narrower already flips
    // then/else on `Not`, and the formatter restores the spelling. `as`
    // is rejected because the binding has no live then-branch when the
    // check is negated.
    if (t.kind === "bang" && p.peek(1).kind === "kw_is" && 20 >= minBP) {
      if (lastNonAssocLevel === 20) {
        p.error("P1010", t.span, "chained `!is`");
        break;
      }
      const bangTok = p.advance();
      p.advance(); // kw_is
      const right = parseExpr(p, 21);
      if (p.peek().kind === "kw_as") {
        const asTok = p.advance();
        const ident = p.match("ident");
        const endSpan = ident !== null ? ident.span : asTok.span;
        p.error("P1001", asTok.span,
          "`as` binding not allowed after `!is`: the binding would have no live then-branch since the type-check is negated");
        // Span still ends at `right` ; the consumed `as <ident>` is recovery
        // glue and shouldn't widen the `!is` expression.
        void endSpan;
      }
      const isExpr: A.BinaryExpr = {
        kind: "BinaryExpr",
        id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: right.span.end },
        op: "is",
        left,
        right,
      };
      left = {
        kind: "UnaryExpr",
        id: UNASSIGNED_NODE_ID, span: { start: bangTok.span.start, end: right.span.end },
        op: "not",
        operand: isExpr,
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
          id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: right.span.end },
          inclusive: t.kind === "range_incl",
          lower: left,
          upper: right,
        };
      } else {
        // `is T as <ident>` — binds the narrowed RHS in the enclosing
        // if's then-branch (mirrors match-arm `is T as x ->` semantics).
        // Only meaningful for `is` ; other ops carry no `bindAs`.
        let bindAs: string | undefined;
        if (infix.op === "is" && p.peek().kind === "kw_as") {
          p.advance();
          bindAs = p.expect("ident", "binding name after `as`").text;
        }
        left = {
          kind: "BinaryExpr",
          id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: p.peek(-1).span.end },
          // `infix.op` is defined for every non-range InfixOp (range tokens
          // are handled in the branch above) — assert and use.
          op: infix.op!,
          left,
          right,
          ...(bindAs !== undefined ? { bindAs } : {}),
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
        id: UNASSIGNED_NODE_ID, span: t.span,
        value: t.intValue ?? 0n,
        suffix: t.numericSuffix ?? null,
      };
    case "float_literal":
      p.advance();
      return {
        kind: "FloatLitExpr",
        id: UNASSIGNED_NODE_ID, span: t.span,
        value: t.floatValue ?? 0,
        suffix: t.numericSuffix ?? null,
      };
    case "char_literal":
      p.advance();
      return { kind: "CharLitExpr", id: UNASSIGNED_NODE_ID, span: t.span, value: t.charValue ?? 0 };
    case "kw_true":
      p.advance();
      return { kind: "BoolLitExpr", id: UNASSIGNED_NODE_ID, span: t.span, value: true };
    case "kw_false":
      p.advance();
      return { kind: "BoolLitExpr", id: UNASSIGNED_NODE_ID, span: t.span, value: false };
    case "kw_null":
      p.advance();
      return { kind: "NullLitExpr", id: UNASSIGNED_NODE_ID, span: t.span };
    case "string_begin":
      return parseStringLit(p);
    case "ident":
      return parseIdentOrStructLit(p);
    case "lparen":
      if (peekLambdaWithoutFn(p)) return parseLambdaWithoutFn(p);
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
      return { kind: "UnaryExpr", id: UNASSIGNED_NODE_ID, span: { start: t.span.start, end: operand.span.end }, op, operand };
    }
    case "kw_if":
      return parseIfExpr(p);
    case "kw_match":
      return parseMatchExpr(p, /*partial*/ false);
    case "at": {
      // Two expression-position `@` forms today :
      //   `@partial match x { ... }` — opt-out of exhaustiveness for a match.
      //   `@<intrinsic>(args)` — compiler reflection / introspection call
      //                          (`@size_of`, `@type_name`, …). The set of
      //                          recognised names lives in `parser/intrinsics.ts`.
      // Anything else is P1014.
      const atTok = p.advance();
      const nameTok = p.expect("ident", "decorator name after `@`");
      if (nameTok.text === "partial") {
        if (!p.check("kw_match")) {
          p.error("P1014", nameTok.span, `\`@${nameTok.text}\` must precede a \`match\` expression`);
        }
        return parseMatchExpr(p, /*partial*/ true);
      }
      const spec = intrinsicSpec(nameTok.text);
      if (spec !== null) {
        p.expect("lparen", `\`(\` after \`@${spec.name}\``);
        const args: A.Expr[] = [];
        p.skipNewlines();
        if (!p.check("rparen")) {
          while (true) {
            p.skipNewlines();
            if (p.check("rparen")) break;
            // Type-shape args go through parseType so postfix `[]`, `|` and
            // friends parse with type semantics ; value-shape args go through
            // the regular expression parser.
            const argSpec = spec.args[args.length];
            args.push(argSpec === "type" ? parseType(p) : parseExpr(p, 0));
            p.skipNewlines();
            if (p.match("comma") === null) break;
          }
        }
        const end = p.expect("rparen", `\`)\` to close \`@${spec.name}(...)\``);
        return {
          kind: "IntrinsicCallExpr",
          id: UNASSIGNED_NODE_ID, span: { start: atTok.span.start, end: end.span.end },
          name: spec.name,
          nameSpan: nameTok.span,
          args,
        };
      }
      p.error("P1014", { start: atTok.span.start, end: nameTok.span.end },
        `\`@${nameTok.text}\` is not allowed in expression position`);
      return placeholderExpr(atTok);
    }
    case "kw_fn":
      return parseLambda(p);
    case "kw_self":
      p.advance();
      return { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: t.span, name: "self" };
    case "dollar": {
      // `$T` — type-param introduction prefix absorbed into the main Pratt
      // parser since 1.C. Produces an `IdentExpr` carrying `isTypeParamIntro`,
      // exactly as the type-mode parser did. In value position the resulting
      // node is an unresolved name reference that the typechecker will flag.
      const dollarTok = p.advance();
      const name = p.expect("ident", "type parameter name after `$`");
      return {
        kind: "IdentExpr",
        id: UNASSIGNED_NODE_ID, span: { start: dollarTok.span.start, end: name.span.end },
        name: name.text,
        isTypeParamIntro: true,
      };
    }
    case "dot": {
      p.advance(); // consume `.`
      const variantTok = p.expect("ident", "variant name after `.`");
      return {
        kind: "DotVariantExpr",
        id: UNASSIGNED_NODE_ID, span: { start: t.span.start, end: variantTok.span.end },
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
  return { kind: "NullLitExpr", id: UNASSIGNED_NODE_ID, span: t.span };
}

function parsePostfix(p: Parser, left: A.Expr, t: Token): A.Expr {
  if (t.kind === "question") {
    p.advance();
    return {
      kind: "TryExpr",
      id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: t.span.end },
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
        id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: numTok.span.end },
        target: left,
        field: numTok.text,
        fieldSpan: numTok.span,
        isNumeric: true,
      };
    }
    const name = p.expect("ident", "field name after `.`");
    const fieldExpr: A.FieldExpr = {
      kind: "FieldExpr",
      id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: name.span.end },
      target: left,
      field: name.text,
      fieldSpan: name.span,
    };
    // Qualified struct literal : `module.Type { .field = …, … }`. The
    // bare-ident path goes through `parseIdentOrStructLit` at prefix
    // time ; the qualified form lands here because `module` was already
    // consumed as the prefix expression and `.Type` is a postfix `dot`.
    // Same struct-lit gate as the bare path.
    if (p.allowStructLit && p.check("lbrace") && looksLikeStructLitBody(p.tokens, p.pos)) {
      p.advance(); // {
      const items = parseStructLitFields(p);
      const rb = p.expect("rbrace", "`}` to close struct literal");
      return {
        kind: "StructLitExpr",
        id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: rb.span.end },
        typeName: fieldExpr,
        items,
      };
    }
    return fieldExpr;
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
      id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: p.peek(-1).span.end },
      callee: left,
      args,
    };
    // If immediately followed by `{` AND struct literals are allowed, treat as struct literal.
    // Disabled for now — the explicit struct literal path `parseIdentOrStructLit` handles `Name { ... }`.
    return callExpr;
  }
  if (t.kind === "lbracket") {
    // Two readings (Layer 1.C — type-mode operator absorbed into the main
    // Pratt parser):
    //   `T[]`   (empty brackets)  → ArrayTypeExpr ; type-only construct,
    //                               typechecker rejects it in value position.
    //   `T[i]`  (with index)      → IndexExpr (ordinary value-level indexing).
    if (p.peek(1).kind === "rbracket") {
      p.advance(); // [
      const rb = p.advance(); // ]
      return {
        kind: "ArrayTypeExpr",
        id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: rb.span.end },
        element: left,
        immutable: false,
      };
    }
    p.advance();
    const index = parseExpr(p, 0);
    p.expect("rbracket", "`]` to close index");
    return {
      kind: "IndexExpr",
      id: UNASSIGNED_NODE_ID, span: { start: left.span.start, end: p.peek(-1).span.end },
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
        id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
        name: nameTok.text,
        value,
        spread: false,
      });
    } else {
      const value = parseExpr(p, 0);
      out.push({
        id: UNASSIGNED_NODE_ID, span: value.span,
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

  // Angle-bracket generic in expression position. Two shapes :
  //   `Ident<T, ...>(args)`        → generic call ; build a CallExpr whose
  //                                  callee is GenericInstExpr.
  //   `Ident<T, ...> { .f = ... }` → generic struct literal.
  //
  // Hard precedence rule (SPEC §3) : commit to the generic interpretation
  // iff the speculative scan finds a matching `>` whose IMMEDIATELY-NEXT
  // token is `(` or `{`. Otherwise leave the `<` for Pratt as a `lt`
  // comparison operator. The scan handles nested `<...>` and the lexer's
  // single `shr` token (counts as two closes).
  const angleScan = p.check("lt") ? scanAngleGeneric(p, p.pos) : null;
  if (angleScan !== null && angleScan.ok) {
    const argList = parseGenericArgList(p, "generic argument list");
    const genericInst: A.GenericInstExpr = {
      kind: "GenericInstExpr",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(t, p.peek(-1)),
      callee: { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: t.span, name: t.text },
      typeArgs: argList?.items ?? [],
    };
    if (p.allowStructLit && p.check("lbrace")) {
      p.advance(); // {
      const items = parseStructLitFields(p);
      const rb = p.expect("rbrace", "`}` to close struct literal");
      return {
        kind: "StructLitExpr",
        id: UNASSIGNED_NODE_ID, span: p.spanOf(t, rb),
        typeName: genericInst,
        items,
      };
    }
    // Must be a call — the speculative scan only commits on `(` or `{`.
    p.expect("lparen", "`(` after generic argument list");
    const callArgs = parseCallArgs(p);
    const rp = p.expect("rparen", "`)` to close argument list");
    return {
      kind: "CallExpr",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(t, rp),
      callee: genericInst,
      args: callArgs,
    };
  }

  if (p.allowStructLit && p.check("lbrace") && looksLikeStructLitBody(p.tokens, p.pos)) {
    p.advance();
    const items = parseStructLitFields(p);
    const rb = p.expect("rbrace", "`}` to close struct literal");
    return {
      kind: "StructLitExpr",
      id: UNASSIGNED_NODE_ID, span: p.spanOf(t, rb),
      typeName: { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: t.span, name: t.text },
      items,
    };
  }
  return { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: t.span, name: t.text };
}

/** Tokens that cannot appear inside a type expression at the OUTERMOST level
 *  of a generic argument list ; seeing one of these aborts the speculative
 *  scan early, before it walks into an enclosing block. Without this guard,
 *  `if x < y { stmt }` would scan past the `{ stmt }` body before bailing
 *  on EOF — quadratic in pathological cases. */
const SCAN_GENERIC_BAILOUT: ReadonlySet<TokenKind> = new Set<TokenKind>([
  "lbrace",
  "decl_const", "decl_var", "assign",
  "plus_assign", "minus_assign", "star_assign", "slash_assign", "percent_assign",
  "gte", "lte", "eq", "neq",
  "kw_if", "kw_else", "kw_match", "kw_is", "kw_for", "kw_in",
  "kw_return", "kw_defer", "kw_break", "kw_continue",
  "kw_struct", "kw_trait", "kw_implements", "kw_enum",
  "kw_import", "kw_export", "kw_self",
]);

/** Speculative scan for `Ident < args > ( | {` in expression position.
 *  Starts at the `<` token. Commits to the generic interpretation only
 *  when a matching `>` (or the first half of a `shr`) is found at angle
 *  depth zero AND the immediately-following token is `lparen` or `lbrace`.
 *  Any other follower leaves the `<` to Pratt as a comparison. */
function scanAngleGeneric(p: Parser, ltPos: number): { ok: boolean } {
  if (p.tokens[ltPos]?.kind !== "lt") return { ok: false };
  let angleDepth = 1;
  let parenDepth = 0;
  let bracketDepth = 0;
  let i = ltPos + 1;
  while (i < p.tokens.length) {
    const t = p.tokens[i]!;
    if (t.kind === "eof") return { ok: false };
    const atOuter = parenDepth === 0 && bracketDepth === 0;
    if (t.kind === "newline" && atOuter) return { ok: false };
    if (atOuter && SCAN_GENERIC_BAILOUT.has(t.kind)) return { ok: false };
    if (atOuter) {
      if (t.kind === "lt") {
        angleDepth++;
      } else if (t.kind === "gt") {
        angleDepth--;
        if (angleDepth === 0) {
          const next = p.tokens[i + 1];
          return { ok: next !== undefined && (next.kind === "lparen" || next.kind === "lbrace") };
        }
      } else if (t.kind === "shr") {
        angleDepth -= 2;
        if (angleDepth === 0) {
          const next = p.tokens[i + 1];
          return { ok: next !== undefined && (next.kind === "lparen" || next.kind === "lbrace") };
        }
        if (angleDepth < 0) return { ok: false };
      }
    }
    if (t.kind === "lparen") parenDepth++;
    else if (t.kind === "rparen") {
      if (parenDepth === 0) return { ok: false };
      parenDepth--;
    } else if (t.kind === "lbracket") bracketDepth++;
    else if (t.kind === "rbracket") {
      if (bracketDepth === 0) return { ok: false };
      bracketDepth--;
    }
    i++;
  }
  return { ok: false };
}

/** Scan past a balanced `open ... close` group starting at the current
 *  token position, then skip newlines, and return the index of the next
 *  significant token (or -1 if the group isn't balanced before EOF).
 *  Used by lambda lookahead (`(params) ->`) and the generic-struct-lit
 *  heuristic above. */
function peekTokenIdxAfterBalanced(p: Parser, open: TokenKind, close: TokenKind): number {
  if (p.tokens[p.pos]?.kind !== open) return -1;
  let depth = 1, j = p.pos + 1;
  while (j < p.tokens.length && depth > 0) {
    const t = p.tokens[j]!;
    if (t.kind === "eof") return -1;
    if (t.kind === open) depth++;
    else if (t.kind === close) {
      depth--;
      if (depth === 0) break;
    }
    j++;
  }
  if (depth !== 0) return -1;
  // Skip newlines after the matching close.
  let k = j + 1;
  while (k < p.tokens.length && p.tokens[k]!.kind === "newline") k++;
  return k;
}

/** True when the upcoming `( <stuff> )` is followed by `->`, i.e. the
 *  shape opens a lambda without the `fn` keyword. Same balanced-scan as
 *  `peekGenericStructLit`, different sentinel. */
function peekLambdaWithoutFn(p: Parser): boolean {
  const k = peekTokenIdxAfterBalanced(p, "lparen", "rparen");
  return k >= 0 && p.tokens[k]?.kind === "arrow";
}

/** Wrap a body expression in a synthetic BlockExpr if it is not already
 *  one. Used by the new lambda forms (`x -> expr`, `(x) -> expr`) so the
 *  AST shape `LambdaExpr.body: BlockExpr` stays stable for downstream
 *  consumers (typecheck `checkBlock`, lowerer `lowerBlock`). A block-expr
 *  with empty `stmts` and `trailing = expr` is semantically identical to
 *  an expression-bodied lambda. */
function wrapAsBlock(body: A.Expr): A.BlockExpr {
  if (body.kind === "BlockExpr") return body;
  return {
    kind: "BlockExpr",
    id: UNASSIGNED_NODE_ID, span: body.span,
    stmts: [],
    trailing: body,
  };
}

function parseStructLitFields(p: Parser): A.StructLitItem[] {
  const out: A.StructLitItem[] = [];
  p.skipNewlines();
  while (!p.check("rbrace") && !p.check("eof")) {
    const start = p.peek();
    if (p.match("dotdotdot") !== null) {
      const expr = parseExpr(p, 0);
      out.push({
        kind: "spread",
        id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
        expr,
      });
    } else {
      p.expect("dot", "`.` before struct literal field name");
      const name = p.expect("ident", "struct literal field name");
      p.expect("assign", "`=` after struct literal field name");
      const value = parseExpr(p, 0);
      out.push({
        kind: "field",
        id: UNASSIGNED_NODE_ID, span: p.spanOf(start, p.peek(-1)),
        name: name.text,
        nameSpan: name.span,
        value,
      });
    }
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

/** Parse `(params) -> body` as a lambda (no `fn` keyword). The opening
 *  `(` is still on the parser ; `parseFnSignatureParams` consumes the
 *  full param list. No explicit return-type slot — always inferred. */
function parseLambdaWithoutFn(p: Parser): A.LambdaExpr {
  const start = p.peek();
  const { params } = parseFnSignatureParams(p);
  p.expect("arrow", "`->` between lambda params and body");
  const bodyExpr = parseExpr(p, 0);
  const body = wrapAsBlock(bodyExpr);
  return {
    kind: "LambdaExpr",
    id: UNASSIGNED_NODE_ID, span: { start: start.span.start, end: body.span.end },
    params,
    returnType: null,
    body,
  };
}

/** Tail-parse `-> body` after a bare `IdentExpr` consumed by parsePrefix.
 *  Builds the single-param lambda with the ident as a typeless `FnParam`.
 *  Called from `parseExpr` immediately after `parsePrefix` returns. */
function parseSingleParamLambdaTail(p: Parser, paramIdent: A.IdentExpr): A.LambdaExpr {
  p.advance(); // ->
  const param: A.FnParam = {
    id: UNASSIGNED_NODE_ID, span: paramIdent.span,
    name: paramIdent.name,
    type: null,
    defaultValue: null,
    variadic: false,
  };
  const bodyExpr = parseExpr(p, 0);
  const body = wrapAsBlock(bodyExpr);
  return {
    kind: "LambdaExpr",
    id: UNASSIGNED_NODE_ID, span: { start: paramIdent.span.start, end: body.span.end },
    params: [param],
    returnType: null,
    body,
  };
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
    id: UNASSIGNED_NODE_ID, span: p.spanOf(lb, rb),
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
      parts.push({ kind: "text", id: UNASSIGNED_NODE_ID, value: t.stringValue ?? t.text, span: t.span });
      continue;
    }
    if (t.kind === "interp_open") {
      const interpStart = p.advance();
      const expr = parseExpr(p, 0);
      const closeTok = p.match("interp_close");
      const closeSpan = closeTok !== null ? closeTok.span : expr.span;
      parts.push({
        kind: "interp",
        id: UNASSIGNED_NODE_ID, expr,
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
    id: UNASSIGNED_NODE_ID, span: p.spanOf(begin, end),
    parts,
  };
}

