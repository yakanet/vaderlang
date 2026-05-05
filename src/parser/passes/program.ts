// Top-level driver: parse a token stream into a `A.Program` by repeatedly
// calling `parseDecl` until EOF. Recovery is per-decl: a failed parse advances
// past the failure and resumes at the next top-level start.

import type * as A from "../ast.ts";
import type { Parser } from "../parser.ts";
import { parseDecl } from "./decl.ts";

export function parseProgram(p: Parser): A.Program {
  const startTok = p.peek();
  const decls: A.Decl[] = [];

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
    file: p.file,
    span: { start: startTok.span.start, end: endTok.span.end },
    decls,
  };
}
