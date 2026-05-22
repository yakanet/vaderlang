// Top-level driver: parse a token stream into a `A.Program` by repeatedly
// calling `parseDecl` until EOF. Recovery is per-decl: a failed parse advances
// past the failure and resumes at the next top-level start.
//
// Before the first declaration, optionally consume the `module "<name>"`
// header introduced by the module-system redesign (see docs/MODULE_SYSTEM.md).
// In this tolerant phase the header is optional ; Phase 7 flips it to
// mandatory.

import type * as A from "../ast.ts";
import { UNASSIGNED_NODE_ID } from "../ast.ts";
import type { Parser } from "../parser.ts";
import { expectStringLiteral, parseDecl } from "./decl.ts";

// Mirrors SPEC.md §11 "Module name grammar":
//   module-name ::= segment ('/' segment)*
//   segment     ::= [a-z] [a-z0-9_]*
const MODULE_NAME_RE = /^[a-z][a-z0-9_]*(\/[a-z][a-z0-9_]*)*$/;

export function parseProgram(p: Parser): A.Program {
  const startTok = p.peek();
  const decls: A.Decl[] = [];

  p.skipNewlines();
  const module = parseOptionalModuleDecl(p);
  p.skipNewlines();
  while (!p.check("eof")) {
    const d = parseDecl(p);
    if (d !== null) decls.push(d);
    else p.advance(); // safety advance to avoid infinite loop on weird input
    p.skipNewlines();
  }

  const endTok = p.peek();
  return {
    kind: "Program",
    id: UNASSIGNED_NODE_ID, file: p.file,
    span: { start: startTok.span.start, end: endTok.span.end },
    module,
    decls,
  };
}

// `module` is a *soft* keyword (see lexer note). We only recognise it
// here, at the file prologue, when followed by a string literal — any
// other occurrence (e.g. `.module = "t"`, `module: TypedProgram`) keeps
// the regular identifier semantics. The lookahead at `peek(1).kind` is
// the disambiguator : a real `module "..."` decl has `string_begin`
// right after the soft-keyword.
function parseOptionalModuleDecl(p: Parser): A.ModuleDecl | null {
  const t = p.peek();
  if (t.kind !== "ident" || t.text !== "module") return null;
  if (p.peek(1).kind !== "string_begin") return null;
  const start = p.advance(); // consume `module`
  const lit = expectStringLiteral(p, "module name");
  if (!MODULE_NAME_RE.test(lit.text)) {
    p.error("P1028", lit.span);
  }
  return {
    kind: "ModuleDecl",
    id: UNASSIGNED_NODE_ID,
    span: p.spanOf(start, p.peek(-1)),
    name: lit.text,
    nameSpan: lit.span,
  };
}
