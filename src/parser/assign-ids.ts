// Post-parse pass that assigns a unique `id: number` to every AST node in a
// freshly-parsed `Program`. Side-tables in the resolver and typechecker key
// on this id rather than on JS object identity, which keeps them portable
// to the Vader self-host (where the key becomes `node.id: usize`).
//
// Detection is structural: a value is treated as an AST node iff it carries
// both a `kind: string` and a `span: { start, end }`. Spans, Symbols, and
// primitive payloads are filtered out cleanly. The walker runs before the
// resolver, so there are no Symbol back-references in the AST yet — no
// cycle risk.

import type * as A from "./ast.ts";

let nextId = 1;

export function assignNodeIds(program: A.Program): void {
  nextId = 1;
  walk(program);
}

function walk(value: unknown): void {
  if (value === null || typeof value !== "object") return;
  if (Array.isArray(value)) {
    for (const item of value) walk(item);
    return;
  }
  if (isAstNode(value)) {
    (value as { id: number }).id = nextId++;
  }
  for (const key in value) {
    if (key === "span" || key === "nameSpan") continue;
    walk((value as Record<string, unknown>)[key]);
  }
}

function isAstNode(value: object): boolean {
  const o = value as { kind?: unknown; span?: unknown };
  if (typeof o.kind !== "string") return false;
  const span = o.span;
  if (span === undefined || span === null || typeof span !== "object") return false;
  return "start" in (span as object) && "end" in (span as object);
}
