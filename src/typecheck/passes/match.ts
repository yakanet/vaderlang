// Match-expression checking. Validates each arm body against the expected
// type, narrows the scrutinee symbol inside `is T -> body` arms via the
// shared narrowing stack, and reports T3013 when non-wildcard match arms
// don't cover all variants of a Union scrutinee.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { sourceEnumDecl } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Type } from "../types.ts";
import { TY, displayType, isAssignable, unionOf } from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkEnumVariant } from "./enum.ts";
import { checkExpr } from "./expr.ts";
import { lowerTypeExpr } from "./type-expr.ts";

export function inferMatch(
  expr: A.MatchExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const scrut = checkExpr(expr.scrutinee, null, t, impls, diags, fn);
  const scrutSym = scrutineeSymbol(expr.scrutinee, t);
  const armTypes: Type[] = [];
  let hasWildcard = false;
  const coveredVariants = new Set<string>();
  for (const arm of expr.arms) {
    if (arm.pattern.kind === "WildcardPattern") hasWildcard = true;
    // A TuplePattern whose every leaf is a binding/wildcard is exhaustive over
    // its (statically-typed) tuple scrutinee : the pattern matches all tuples
    // of that arity by construction.
    if (arm.pattern.kind === "TuplePattern" && isIrrefutableTuple(arm.pattern)) hasWildcard = true;
    let narrowed: Type | null = null;
    if (arm.pattern.kind === "IsPattern") {
      const variantTy = arm.pattern.type.kind === "NamedType" && arm.pattern.type.implicitDot === true
        ? resolveImplicitDotVariant(arm.pattern.type, scrut, t, diags)
        : lowerTypeExpr(arm.pattern.type, t, diags);
      coveredVariants.add(displayType(variantTy));
      narrowed = variantTy;
    }
    if (arm.pattern.kind === "EnumVariantPattern") {
      coveredVariants.add(arm.pattern.variant);
      if (scrut.kind === "Enum") checkEnumVariant(scrut, arm.pattern.variant, arm.pattern.span, diags);
    }
    const prev: Type | undefined = scrutSym !== null && narrowed !== null
      ? pushNarrowing(t, scrutSym.id, narrowed)
      : undefined;
    // Pattern-binding narrowing: without it, references to `p` in the arm
    // body see `Unresolved` and the lowerer can't resolve fields on it.
    const bind = bindingNarrowing(t, arm.pattern, scrut, narrowed);
    const bindPrev = bind !== null ? pushNarrowing(t, bind.sym.id, bind.type) : undefined;
    if (arm.guard !== null) {
      const g = checkExpr(arm.guard, TY.bool, t, impls, diags, fn);
      if (!isAssignable(g, TY.bool)) err(diags, "T3019", arm.guard.span);
    }
    armTypes.push(checkExpr(arm.body, expected, t, impls, diags, fn));
    if (bind !== null) popNarrowing(t, bind.sym.id, bindPrev);
    if (scrutSym !== null && narrowed !== null) popNarrowing(t, scrutSym.id, prev);
  }

  if (!hasWildcard) {
    if (scrut.kind === "Union") {
      for (const v of scrut.variants) {
        if (!coveredVariants.has(displayType(v))) {
          err(diags, "T3013", expr.span,
            `variant ${displayType(v)} of ${displayType(scrut)} is not covered`);
          break;
        }
      }
    } else if (scrut.kind === "Enum") {
      const decl = sourceEnumDecl(scrut.symbol);
      if (decl !== null) {
        for (const v of decl.variants) {
          if (!coveredVariants.has(v.name)) {
            err(diags, "T3013", expr.span,
              `variant .${v.name} of ${displayType(scrut)} is not covered`);
            break;
          }
        }
      }
    } else if (scrut.kind !== "Unresolved") {
      err(diags, "T3013", expr.span,
        `match on non-union ${displayType(scrut)} requires a wildcard arm`);
    }
  }

  return armTypes.length === 0 ? TY.never : unionOf(armTypes);
}

/** Resolve `is .Foo` against the match scrutinee. Walks the scrutinee's
 *  union variants for a struct/enum/trait whose name matches the dot
 *  reference. Falls back to `Unresolved` (with a T3007 diagnostic) when
 *  the variant isn't found ; downstream coverage checks still run on
 *  whatever was emitted so cascading errors stay minimal. */
function resolveImplicitDotVariant(
  type: A.NamedType, scrut: Type, t: MutableTyped, diags: DiagnosticCollector,
): Type {
  if (scrut.kind === "Union") {
    for (const v of scrut.variants) {
      if (v.kind === "Struct" && v.symbol.name === type.name) {
        t.globals.typeExprTypes.set(type, v);
        return v;
      }
      if (v.kind === "Enum" && v.symbol.name === type.name) {
        t.globals.typeExprTypes.set(type, v);
        return v;
      }
    }
  }
  err(diags, "R2007", type.span,
    `\`.${type.name}\` (no variant named \`${type.name}\` on ${displayType(scrut)})`);
  return TY.unresolved;
}

/** A TuplePattern is irrefutable when every element is itself irrefutable
 *  (a wildcard / plain binding / nested-irrefutable-tuple). Used by
 *  exhaustiveness to skip the wildcard requirement for tuple scrutinees. */
function isIrrefutableTuple(pat: A.TuplePattern): boolean {
  for (const e of pat.elements) {
    if (e.kind === "WildcardPattern" || e.kind === "BindingPattern") continue;
    if (e.kind === "TuplePattern" && isIrrefutableTuple(e)) continue;
    return false;
  }
  return true;
}

/** Resolve the scrutinee to a symbol when it's a plain identifier referring
 *  to a local or parameter — only those flow narrowing usefully. Anything
 *  else (calls, field access, literals) gets no narrowing. */
function scrutineeSymbol(scrut: A.Expr, t: MutableTyped): Symbol | null {
  if (scrut.kind !== "IdentExpr") return null;
  const sym = t.resolved.idents.get(scrut);
  if (sym === undefined) return null;
  if (sym.kind !== "local" && sym.kind !== "param" && sym.kind !== "binding") return null;
  return sym;
}

function pushNarrowing(t: MutableTyped, symId: number, narrow: Type): Type | undefined {
  const prev = t.narrowed.get(symId);
  t.narrowed.set(symId, narrow);
  return prev;
}

function popNarrowing(t: MutableTyped, symId: number, prev: Type | undefined): void {
  if (prev === undefined) t.narrowed.delete(symId);
  else t.narrowed.set(symId, prev);
}

/** Narrowing target for a single arm's binding (`is T as p` ⇒ `T`,
 *  `BindingPattern x` ⇒ scrut). Struct-pattern field bindings stay untyped
 *  pending per-field substitution (see TODO §1.4 deferred). */
function bindingNarrowing(
  t: MutableTyped, pattern: A.Pattern, scrut: Type, isNarrowed: Type | null,
): { sym: Symbol; type: Type } | null {
  if (pattern.kind === "IsPattern" && pattern.bindAs !== null && isNarrowed !== null) {
    const sym = t.resolved.patternBindings.get(pattern);
    return sym !== undefined ? { sym, type: isNarrowed } : null;
  }
  if (pattern.kind === "BindingPattern") {
    const sym = t.resolved.patternBindings.get(pattern);
    return sym !== undefined ? { sym, type: scrut } : null;
  }
  return null;
}
