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

import { buildStructSubst } from "../ctx.ts";
import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkExpr } from "./expr.ts";
import { tryInto } from "./coerce.ts";
import { lowerExprAsType } from "./type-expr.ts";

export function inferStructLit(
  expr: A.StructLitExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const ty = lowerExprAsType(expr.typeName, t, diags);
  if (ty.kind !== "Struct") {
    err(diags, "T3001", expr.typeName.span,
      `${displayType(ty)} is not a struct`);
    for (const item of expr.items) {
      if (item.kind === "field") checkExpr(item.value, null, t, impls, diags, fn);
      else checkExpr(item.expr, null, t, impls, diags, fn);
    }
    return ty;
  }
  const decl = sourceStructDecl(ty.symbol);
  const subst = buildStructSubst(decl?.typeParams ?? [], ty.args, t.globals.typeParamSymbols);
  const hasSpread = expr.items.some((i) => i.kind === "spread");
  const provided = new Set<string>();
  for (const item of expr.items) {
    if (item.kind === "spread") {
      const got = checkExpr(item.expr, ty, t, impls, diags, fn);
      if (!isAssignable(got, ty, impls)) {
        err(diags, "T3001", item.span,
          `spread source must be assignable to ${displayType(ty)}, got ${displayType(got)}`);
      }
      continue;
    }
    const field = decl?.fields.find((sf) => sf.name === item.name);
    const fieldRaw = field !== undefined ? t.globals.typeExprTypes.get(field.type) ?? null : null;
    const expected = fieldRaw !== null ? substitute(fieldRaw, subst) : null;
    const got = checkExpr(item.value, expected, t, impls, diags, fn);
    if (field === undefined) {
      err(diags, "T3009", item.nameSpan, `\`${item.name}\` on ${displayType(ty)}`);
    } else {
      if (provided.has(item.name)) {
        err(diags, "T3038", item.nameSpan,
          `field \`${item.name}\` already provided in this struct literal`);
      }
      provided.add(item.name);
      if (expected !== null && !isAssignable(got, expected, impls)) {
        if (!tryInto(got, expected, item.value, t, impls)) {
          err(diags, "T3001", item.span,
            `expected ${displayType(expected)}, got ${displayType(got)}`);
        }
      }
    }
  }
  if (decl !== null && !hasSpread) {
    const missing = decl.fields.filter((sf) => !provided.has(sf.name) && sf.default === null);
    if (missing.length > 0) {
      err(diags, "T3037", expr.span,
        `missing required field${missing.length === 1 ? "" : "s"} on ${displayType(ty)}: ${missing.map((sf) => `\`${sf.name}\``).join(", ")}`);
    }
  }
  return ty;
}
