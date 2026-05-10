// Validate `struct[T: Trait]` bounds at every instantiation site. Walks
// `globals.typeExprTypes` after the project's check pass and emits T3006
// for any concrete arg that doesn't satisfy its formal type-param's bound.
// Mirrors the per-call enforcement at fn instantiation sites in `call.ts` ;
// the difference is the trigger (a struct type-expr vs a CallExpr) and the
// span we attribute the error to (the offending typeExpr).

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import { sourceStructDecl } from "../../resolver/symbol.ts";

import type { Globals } from "../ctx.ts";
import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import { displayType } from "../types.ts";

export function validateStructBounds(
  globals: Globals, impls: ImplRegistry, diags: DiagnosticCollector,
): void {
  for (const [typeExpr, ty] of globals.typeExprTypes) {
    if (ty.kind !== "Struct") continue;
    if (ty.args.length === 0) continue;
    const decl = sourceStructDecl(ty.symbol);
    if (decl === null) continue;
    for (let i = 0; i < decl.typeParams.length; i++) {
      const concrete = ty.args[i];
      if (concrete === undefined) continue;
      if (concrete.kind === "Unresolved" || concrete.kind === "TypeParam") continue;
      const tpSym = globals.typeParamSymbols.get(decl.typeParams[i]!);
      if (tpSym === undefined) continue;
      const bounds = globals.typeParamBounds.get(tpSym.id);
      if (bounds === undefined) continue;
      for (const traitSym of bounds) {
        if (impls.findFor(concrete, traitSym) !== null) continue;
        err(diags, "T3006", typeExpr.span,
          `\`${displayType(concrete)}\` does not implement \`${traitSym.name}\` (required by type parameter \`${decl.typeParams[i]!.name}\` of \`${decl.name}\`)`);
      }
    }
  }
}
