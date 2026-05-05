// Type-checks the `?` operator. The operand must be a Union; we split it into
// success / error variants (using Error trait satisfaction) and validate that
// the surrounding fn's return type can absorb the propagated error variants.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Type } from "../types.ts";
import { TY, displayType, isAssignable, unionOf } from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkExpr } from "./expr.ts";
import { findErrorTrait } from "./traits.ts";

export function inferTry(
  expr: A.TryExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const inner = checkExpr(expr.inner, null, t, impls, diags, fn);
  if (inner.kind !== "Union") {
    if (inner.kind !== "Unresolved") err(diags, "T3011", expr.span, displayType(inner));
    return TY.unresolved;
  }

  const errorVariants: Type[] = [];
  const successVariants: Type[] = [];
  for (const v of inner.variants) {
    if (variantImplementsError(v, t, impls)) errorVariants.push(v);
    else successVariants.push(v);
  }
  if (errorVariants.length === 0) {
    err(diags, "T3011", expr.span, displayType(inner));
    return inner;
  }

  // Validate fn return type can absorb the propagated errors.
  if (fn !== null) {
    for (const e of errorVariants) {
      if (!isAssignable(e, fn.returnType)) {
        err(diags, "T3012", expr.span,
          `${displayType(e)} not in ${displayType(fn.returnType)}`);
        break;
      }
    }
  }

  return successVariants.length === 1 ? successVariants[0]! : unionOf(successVariants);
}

function variantImplementsError(v: Type, t: MutableTyped, impls: ImplRegistry): boolean {
  const errorSym: Symbol | null = findErrorTrait(t);
  if (errorSym === null) return false;
  if (v.kind === "Trait" && v.symbol.id === errorSym.id) return true;
  if (v.kind === "Struct") return impls.hasUser(v.symbol, errorSym);
  return false;
}
