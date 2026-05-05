// Struct-literal checking. Resolves the struct's type, builds the
// typeParam → arg substitution for generic instances, and validates each
// field's value type against the declared field type after substitution.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import { sourceStructDecl } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Type } from "../types.ts";
import { displayType, isAssignable, substitute } from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkExpr } from "./expr.ts";
import { lowerTypeExpr } from "./type-expr.ts";

export function inferStructLit(
  expr: A.StructLitExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const ty = lowerTypeExpr(expr.typeName, t, diags);
  if (ty.kind !== "Struct") {
    err(diags, "T3001", expr.typeName.span,
      `${displayType(ty)} is not a struct`);
    for (const f of expr.fields) checkExpr(f.value, null, t, impls, diags, fn);
    return ty;
  }
  const decl = sourceStructDecl(ty.symbol);
  // Build the typeParam → concrete-arg substitution for generic instances.
  const subst: { typeParams: Map<number, Type> } = { typeParams: new Map() };
  if (decl !== null && ty.args.length > 0) {
    for (let i = 0; i < decl.typeParams.length && i < ty.args.length; i++) {
      const tp = decl.typeParams[i]!;
      const sym = t.globals.typeParamSymbols.get(tp);
      if (sym !== undefined) subst.typeParams.set(sym.id, ty.args[i]!);
    }
  }
  for (const f of expr.fields) {
    const field = decl?.fields.find((sf) => sf.name === f.name);
    const fieldRaw = field !== undefined ? t.globals.typeExprTypes.get(field.type) ?? null : null;
    const expected = fieldRaw !== null ? substitute(fieldRaw, subst) : null;
    const got = checkExpr(f.value, expected, t, impls, diags, fn);
    if (field === undefined) {
      err(diags, "T3009", f.nameSpan, `\`${f.name}\` on ${displayType(ty)}`);
    } else if (expected !== null && !isAssignable(got, expected)) {
      err(diags, "T3001", f.span,
        `expected ${displayType(expected)}, got ${displayType(got)}`);
    }
  }
  return ty;
}
