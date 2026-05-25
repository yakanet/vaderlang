// One-shot migration : rewrites every generic-syntax site from `[T]` /
// `(T)` to `<T>` across the .vader corpus. Runs the existing parser to
// locate type-param lists, generic-arg lists, and trait-arg lists ;
// rewrites only those delimiters, leaving array postfix `T[]`, tuple
// literals `[a, b]`, indexing `arr[i]`, and value calls `foo(x)`
// untouched.
//
// Usage : `bun scripts/migrate-generics-to-angle.ts [path...]`
// Default scope : `stdlib`, `tests/snippets`, `tests/diag_corpus`,
// `vader`, `examples`. Pass paths to restrict.
//
// Discard after running ; the parser drops the legacy `[T]` / `(T)`
// openers in a follow-up commit.

import { readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { join, resolve } from "node:path";

import { DiagnosticCollector } from "../src/diagnostics/collector.ts";
import { tokenize } from "../src/lexer/lexer.ts";
import { parse } from "../src/parser/parser.ts";
import type * as A from "../src/parser/ast.ts";

interface Edit {
  start: number;
  end: number;
  replacement: string;
}

const DEFAULT_ROOTS = ["stdlib", "tests/snippets", "tests/diag_corpus", "vader", "examples"];

function isWs(c: string): boolean { return c === " " || c === "\t" || c === "\n" || c === "\r"; }

/**
 * Find the offset of the opening delimiter ([ or () immediately preceding
 * `firstArgStart`. Skips whitespace and newlines. Returns -1 if the
 * preceding non-ws char isn't `[` or `(`.
 */
function findOpener(src: string, firstArgStart: number): { offset: number; ch: string } | null {
  for (let i = firstArgStart - 1; i >= 0; i--) {
    const c = src[i]!;
    if (isWs(c)) continue;
    if (c === "[" || c === "(") return { offset: i, ch: c };
    return null;
  }
  return null;
}

/**
 * Find the offset of the closing delimiter (] or )) matching `openerCh`,
 * starting at `lastArgEnd`. Skips whitespace, newlines, and trailing
 * commas. Returns -1 if the next non-ws char isn't the expected closer.
 */
function findCloser(src: string, lastArgEnd: number, openerCh: string): number {
  const want = openerCh === "[" ? "]" : ")";
  let seenComma = false;
  for (let i = lastArgEnd; i < src.length; i++) {
    const c = src[i]!;
    if (isWs(c)) continue;
    if (c === "," && !seenComma) { seenComma = true; continue; }
    if (c === want) return i;
    return -1;
  }
  return -1;
}

function rewriteRange(
  src: string, firstArgStart: number, lastArgEnd: number, edits: Edit[],
): void {
  const opener = findOpener(src, firstArgStart);
  if (opener === null) return;
  const closer = findCloser(src, lastArgEnd, opener.ch);
  if (closer < 0) return;
  // Already migrated? Shouldn't happen if opener returned `[` or `(`, but
  // guard anyway in case a previous pass already swapped them.
  if (opener.ch === "<") return;
  edits.push({ start: opener.offset, end: opener.offset + 1, replacement: "<" });
  edits.push({ start: closer, end: closer + 1, replacement: ">" });
}

function walkTypeParams(params: readonly A.TypeParam[], src: string, edits: Edit[]): void {
  if (params.length === 0) return;
  const first = params[0]!.span.start.offset;
  const last = params[params.length - 1]!.span.end.offset;
  rewriteRange(src, first, last, edits);
}

function walkTypeArgs(args: readonly A.TypeExpr[], src: string, edits: Edit[]): void {
  if (args.length === 0) return;
  const first = args[0]!.span.start.offset;
  const last = args[args.length - 1]!.span.end.offset;
  rewriteRange(src, first, last, edits);
}

function walkExpr(expr: A.Expr | null | undefined, src: string, edits: Edit[]): void {
  if (expr == null) return;
  switch (expr.kind) {
    case "GenericInstExpr":
      walkTypeArgs(expr.typeArgs, src, edits);
      walkExpr(expr.callee, src, edits);
      for (const a of expr.typeArgs) walkExpr(a, src, edits);
      return;
    case "CallExpr":
      walkExpr(expr.callee, src, edits);
      for (const a of expr.args) walkExpr(a.value, src, edits);
      return;
    case "StructLitExpr":
      walkExpr(expr.typeName, src, edits);
      for (const it of expr.items) {
        if (it.kind === "field") walkExpr(it.value, src, edits);
        else walkExpr(it.expr, src, edits);
      }
      return;
    case "FieldExpr":
      walkExpr(expr.target, src, edits);
      return;
    case "IndexExpr":
      walkExpr(expr.target, src, edits);
      walkExpr(expr.index, src, edits);
      return;
    case "BinaryExpr":
      walkExpr(expr.left, src, edits);
      walkExpr(expr.right, src, edits);
      return;
    case "UnaryExpr":
      walkExpr(expr.operand, src, edits);
      return;
    case "IfExpr":
      walkExpr(expr.cond, src, edits);
      walkBlock(expr.then, src, edits);
      if (expr.else != null) {
        if (expr.else.kind === "BlockExpr") walkBlock(expr.else, src, edits);
        else walkExpr(expr.else, src, edits);
      }
      return;
    case "MatchExpr":
      walkExpr(expr.scrutinee, src, edits);
      for (const arm of expr.arms) {
        walkPattern(arm.pattern, src, edits);
        walkExpr(arm.body, src, edits);
        if (arm.guard != null) walkExpr(arm.guard, src, edits);
      }
      return;
    case "LambdaExpr":
      if (expr.body !== null) {
        if (expr.body.kind === "BlockExpr") walkBlock(expr.body, src, edits);
        else walkExpr(expr.body, src, edits);
      }
      return;
    case "BlockExpr":
      walkBlock(expr, src, edits);
      return;
    case "RangeExpr":
      walkExpr(expr.lower, src, edits);
      walkExpr(expr.upper, src, edits);
      return;
    case "TryExpr":
      walkExpr(expr.inner, src, edits);
      return;
    case "CastExpr":
      walkExpr(expr.value, src, edits);
      walkExpr(expr.target, src, edits);
      return;
    case "ArrayTypeExpr":
      walkExpr(expr.element, src, edits);
      return;
    case "FnTypeExpr":
      for (const p of expr.params) walkExpr(p, src, edits);
      if (expr.returnType != null) walkExpr(expr.returnType, src, edits);
      return;
    case "SeqLitExpr":
      for (const e of expr.elements) walkExpr(e, src, edits);
      return;
    case "IntrinsicCallExpr":
      for (const a of expr.args) walkExpr(a, src, edits);
      return;
    case "StringLitExpr":
      for (const p of expr.parts) if (p.kind === "interp") walkExpr(p.expr, src, edits);
      return;
    default:
      return;
  }
}

function walkPattern(pat: A.Pattern, src: string, edits: Edit[]): void {
  switch (pat.kind) {
    case "IsPattern":
      walkExpr(pat.type, src, edits);
      if (pat.inner != null) walkPattern(pat.inner, src, edits);
      return;
    case "StructPattern":
      for (const f of pat.fields) {
        if (f.value.kind === "literal") walkExpr(f.value.value, src, edits);
      }
      return;
    case "TuplePattern":
      for (const e of pat.elements) walkPattern(e, src, edits);
      return;
    case "LiteralPattern":
      walkExpr(pat.value, src, edits);
      return;
    case "EnumVariantPattern":
    case "BindingPattern":
    case "WildcardPattern":
      return;
  }
}

function walkBlock(block: A.BlockExpr, src: string, edits: Edit[]): void {
  for (const s of block.stmts) walkStmt(s, src, edits);
  if (block.trailing != null) walkExpr(block.trailing, src, edits);
}

function walkStmt(stmt: A.Stmt, src: string, edits: Edit[]): void {
  switch (stmt.kind) {
    case "LetStmt":
      if (stmt.type != null) walkExpr(stmt.type, src, edits);
      walkExpr(stmt.value, src, edits);
      return;
    case "ReturnStmt":
      if (stmt.value != null) walkExpr(stmt.value, src, edits);
      return;
    case "AssignStmt":
      walkExpr(stmt.target, src, edits);
      walkExpr(stmt.value, src, edits);
      return;
    case "ExprStmt":
      walkExpr(stmt.expr, src, edits);
      return;
    case "ForStmt":
      if (stmt.form.kind === "while") walkExpr(stmt.form.cond, src, edits);
      else if (stmt.form.kind === "in") walkExpr(stmt.form.iter, src, edits);
      walkBlock(stmt.body, src, edits);
      return;
    case "DeferStmt":
      if (stmt.body.kind === "BlockExpr") walkBlock(stmt.body, src, edits);
      else walkStmt(stmt.body, src, edits);
      return;
    case "BreakStmt":
    case "ContinueStmt":
      return;
  }
}

function walkDecl(decl: A.Decl, src: string, edits: Edit[]): void {
  switch (decl.kind) {
    case "FnDecl":
      walkTypeParams(decl.typeParams, src, edits);
      for (const p of decl.params) if (p.type != null) walkExpr(p.type, src, edits);
      if (decl.returnType != null) walkExpr(decl.returnType, src, edits);
      if (decl.body != null) walkBlock(decl.body, src, edits);
      return;
    case "StructDecl":
      walkTypeParams(decl.typeParams, src, edits);
      for (const f of decl.fields) {
        walkExpr(f.type, src, edits);
        if (f.default != null) walkExpr(f.default, src, edits);
      }
      return;
    case "TraitDecl":
      walkTypeParams(decl.typeParams, src, edits);
      if (decl.requires != null) walkExpr(decl.requires, src, edits);
      for (const m of decl.members) walkDecl(m, src, edits);
      return;
    case "ImplDecl":
      walkTypeParams(decl.typeParams, src, edits);
      walkExpr(decl.forType, src, edits);
      walkTypeArgs(decl.traitArgs, src, edits);
      for (const a of decl.traitArgs) walkExpr(a, src, edits);
      for (const m of decl.members) walkDecl(m, src, edits);
      return;
    case "TypeAliasDecl":
      walkTypeParams(decl.typeParams, src, edits);
      walkExpr(decl.aliased, src, edits);
      return;
    case "ConstDecl":
      if (decl.type != null) walkExpr(decl.type, src, edits);
      walkExpr(decl.value, src, edits);
      return;
    case "EnumDecl":
      return;
    case "ImportDecl":
    case "AssertDecl":
      if (decl.kind === "AssertDecl") walkExpr(decl.condition, src, edits);
      return;
  }
}

function applyEdits(src: string, edits: Edit[]): string {
  if (edits.length === 0) return src;
  edits.sort((a, b) => a.start - b.start);
  // Filter duplicates / overlaps (a delimiter may be reached via two walks).
  const deduped: Edit[] = [];
  for (const e of edits) {
    const last = deduped[deduped.length - 1];
    if (last !== undefined && last.start === e.start) continue;
    if (last !== undefined && last.end > e.start) continue;
    deduped.push(e);
  }
  let out = "";
  let cursor = 0;
  for (const e of deduped) {
    out += src.slice(cursor, e.start) + e.replacement;
    cursor = e.end;
  }
  out += src.slice(cursor);
  return out;
}

function migrateFile(path: string): { changed: boolean; edits: number } {
  const src = readFileSync(path, "utf8");
  const diags = new DiagnosticCollector();
  const tokens = tokenize(src, path, diags).tokens;
  if (diags.hasErrors()) {
    console.error(`skip (lex errors): ${path}`);
    return { changed: false, edits: 0 };
  }
  const { program } = parse(tokens, path, diags);
  if (diags.hasErrors()) {
    console.error(`skip (parse errors): ${path}`);
    return { changed: false, edits: 0 };
  }
  const edits: Edit[] = [];
  for (const decl of program.decls) walkDecl(decl, src, edits);
  if (edits.length === 0) return { changed: false, edits: 0 };
  const out = applyEdits(src, edits);
  if (out === src) return { changed: false, edits: 0 };
  writeFileSync(path, out);
  return { changed: true, edits: edits.length };
}

function walkVaderFiles(root: string, out: string[]): void {
  let entries: string[];
  try { entries = readdirSync(root) as unknown as string[]; } catch { return; }
  for (const name of entries) {
    const p = join(root, name);
    const st = statSync(p);
    if (st.isDirectory()) walkVaderFiles(p, out);
    else if (name.endsWith(".vader")) out.push(p);
  }
}

const argv = process.argv.slice(2);
const roots = argv.length > 0 ? argv : DEFAULT_ROOTS;
const files: string[] = [];
for (const r of roots) {
  const abs = resolve(r);
  let st;
  try { st = statSync(abs); } catch { continue; }
  if (st.isDirectory()) walkVaderFiles(abs, files);
  else if (abs.endsWith(".vader")) files.push(abs);
}

let totalChanged = 0;
let totalEdits = 0;
for (const f of files) {
  const { changed, edits } = migrateFile(f);
  if (changed) {
    totalChanged++;
    totalEdits += edits;
  }
}
console.log(`migrated ${totalChanged}/${files.length} files (${totalEdits} edits)`);
