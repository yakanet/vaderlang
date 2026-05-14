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
import { TY, displayType, equalsType, isAssignable, unionOf } from "../types.ts";

import type { FnContext, MutableTyped } from "../ctx.ts";
import { popNarrowing, pushNarrowing } from "./narrow.ts";
import { checkEnumVariant } from "./enum.ts";
import { checkExpr } from "./expr.ts";
import { fieldTypeOnType } from "./field.ts";
import { lowerExprAsType } from "./type-expr.ts";

export function inferMatch(
  expr: A.MatchExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const scrut = checkExpr(expr.scrutinee, null, t, impls, diags, fn);
  const scrutSym = scrutineeSymbol(expr.scrutinee, t);
  const armTypes: Type[] = [];
  let hasWildcard = false;
  const coveredVariants = new Set<string>();
  // Track types fully matched by *prior* `is X` arms (without an inner-
  // struct refinement, which doesn't fully match X). Used to narrow the
  // scrutinee in a subsequent wildcard / binding arm — e.g. after
  // `is null -> {}` the `_ -> body` arm sees the scrutinee minus `null`.
  const matchedTypes: Type[] = [];
  for (const arm of expr.arms) {
    // Both `_` and a plain `name` arm match every remaining value, so
    // either silences the exhaustiveness check.
    if (arm.pattern.kind === "WildcardPattern") hasWildcard = true;
    if (arm.pattern.kind === "BindingPattern") hasWildcard = true;
    // A TuplePattern whose every leaf is a binding/wildcard is exhaustive over
    // its (statically-typed) tuple scrutinee : the pattern matches all tuples
    // of that arity by construction.
    if (arm.pattern.kind === "TuplePattern" && isIrrefutableTuple(arm.pattern)) hasWildcard = true;
    let narrowed: Type | null = null;
    if (arm.pattern.kind === "IsPattern") {
      const variantTy = arm.pattern.type.kind === "IdentExpr" && arm.pattern.type.implicitDot === true
        ? resolveImplicitDotVariant(arm.pattern.type, scrut, t, diags)
        : lowerExprAsType(arm.pattern.type, t, diags);
      coveredVariants.add(displayType(variantTy));
      narrowed = variantTy;
    }
    if (arm.pattern.kind === "EnumVariantPattern") {
      coveredVariants.add(arm.pattern.variant);
      if (scrut.kind === "Enum") checkEnumVariant(scrut, arm.pattern.variant, arm.pattern.span, diags);
    }
    if (arm.pattern.kind === "LiteralPattern") {
      // Type-check the literal against the scrutinee : `'>' -> …` is only
      // valid when scrut is `char`, `42 -> …` against integers, etc. The
      // expected-type hint also pins free numeric literals to the scrutinee
      // width so `match (n: i64) { 0 -> … }` doesn't drift to i32.
      const litTy = checkExpr(arm.pattern.value, scrut, t, impls, diags, fn);
      if (scrut.kind !== "Unresolved" && !isAssignable(litTy, scrut, impls)) {
        err(diags, "T3001", arm.pattern.span,
          `pattern literal of type ${displayType(litTy)} doesn't match scrutinee ${displayType(scrut)}`);
      }
    }
    // Flow narrowing through wildcard / binding arms : when the scrutinee is
    // a union and prior `is X` arms have fully matched some variants, the
    // remaining arms see the scrutinee minus those variants. Lets
    // `match v { is null -> … ; _ -> use(v) }` see `v` as the non-null
    // variant in the wildcard body.
    if (narrowed === null
        && (arm.pattern.kind === "WildcardPattern" || arm.pattern.kind === "BindingPattern")
        && matchedTypes.length > 0) {
      const remainder = subtractMatched(scrut, matchedTypes);
      if (remainder !== null) narrowed = remainder;
    }
    const prev: Type | undefined = scrutSym !== null && narrowed !== null
      ? pushNarrowing(t, scrutSym.id, narrowed)
      : undefined;
    // Pattern-binding narrowing: without it, references to `p` in the arm
    // body see `Unresolved` and the lowerer can't resolve fields on it.
    const binds = bindingNarrowings(t, arm.pattern, narrowed ?? scrut, narrowed);
    const bindPrev: (Type | undefined)[] = binds.map((b) => pushNarrowing(t, b.sym.id, b.type));
    if (arm.guard !== null) {
      const g = checkExpr(arm.guard, TY.bool, t, impls, diags, fn);
      if (!isAssignable(g, TY.bool)) err(diags, "T3019", arm.guard.span);
    }
    armTypes.push(checkExpr(arm.body, expected, t, impls, diags, fn));
    for (let i = 0; i < binds.length; i++) popNarrowing(t, binds[i]!.sym.id, bindPrev[i]);
    if (scrutSym !== null && narrowed !== null) popNarrowing(t, scrutSym.id, prev);
    // After the arm body is checked, register that this arm fully matches
    // its variant — feeds the wildcard flow-narrowing of later arms. Only
    // `is X` without an inner refinement counts ; `is X { field: v }` only
    // matches a subset of X-instances, so X stays partially live.
    // Reuse the resolved `variantTy` captured in `narrowed` (set above for
    // every IsPattern) — a fresh `lowerExprAsType` would re-resolve and
    // miss the implicit-dot path that `resolveImplicitDotVariant` handles.
    if (arm.pattern.kind === "IsPattern" && arm.pattern.inner === null && narrowed !== null) {
      matchedTypes.push(narrowed);
    }
  }

  // `@partial match` opts out of exhaustiveness — the user has explicitly
  // declared they only care about a subset of variants. No T3013 fires.
  if (!hasWildcard && !expr.partial) {
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
  type: A.IdentExpr, scrut: Type, t: MutableTyped, diags: DiagnosticCollector,
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
  err(diags, "T3027", type.span,
    `\`.${type.name}\` (no variant named \`${type.name}\` on ${displayType(scrut)})`);
  return TY.unresolved;
}

/** Return `scrut` with every variant covered by a `matched` type removed.
 *  Returns `null` when nothing was eliminated (caller skips the narrow).
 *  Operates only on union scrutinees ; non-union scrutinees stay as-is
 *  since a prior `is X` arm on a non-union type either fully matches (no
 *  remaining variants) or is a typecheck error elsewhere. */
function subtractMatched(scrut: Type, matched: readonly Type[]): Type | null {
  if (scrut.kind !== "Union") return null;
  const kept: Type[] = [];
  let dropped = false;
  for (const variant of scrut.variants) {
    if (matched.some((m) => equalsType(m, variant))) {
      dropped = true;
      continue;
    }
    kept.push(variant);
  }
  if (!dropped) return null;
  if (kept.length === 0) return TY.never;
  return unionOf(kept);
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


/** Narrowing targets for an arm's bindings :
 *   `is T as p`       ⇒ `p: T`
 *   `is T { f, g }`   ⇒ one entry per field-binding, typed from T's layout
 *   `[n, s]`          ⇒ one entry per tuple-element binding, typed from the
 *                       (possibly union-narrowed) tuple variant
 *   `BindingPattern x` ⇒ `x: scrut`
 *  Returns multiple entries because struct/tuple destructuring binds several
 *  identifiers simultaneously. (Bare `T { … }` at the arm top-level is not
 *  in the grammar — `parsePattern` only produces `StructPattern` via
 *  `IsPattern.inner`.) */
function bindingNarrowings(
  t: MutableTyped, pattern: A.Pattern, scrut: Type, isNarrowed: Type | null,
): { sym: Symbol; type: Type }[] {
  const out: { sym: Symbol; type: Type }[] = [];
  if (pattern.kind === "IsPattern") {
    if (pattern.bindAs !== null && isNarrowed !== null) {
      const sym = t.resolved.patternBindings.get(pattern);
      if (sym !== undefined) out.push({ sym, type: isNarrowed });
    }
    if (pattern.inner !== null && pattern.inner.kind === "StructPattern" && isNarrowed !== null) {
      collectStructFieldBindings(t, pattern.inner, isNarrowed, out);
    }
    return out;
  }
  if (pattern.kind === "BindingPattern") {
    const sym = t.resolved.patternBindings.get(pattern);
    if (sym !== undefined) out.push({ sym, type: scrut });
    return out;
  }
  if (pattern.kind === "TuplePattern") {
    // Find the matching-arity tuple variant in the scrutinee. Without this
    // narrowing the inner bindings ride with the scrutinee's static type
    // (often `Unresolved` after Union widening), and downstream interp like
    // `"${n}"` falls back to `builder.append_str(int32_t)` instead of
    // `append_display_i32`.
    const tupleTy: Type =
      scrut.kind === "Tuple" && scrut.elements.length === pattern.elements.length
        ? scrut
        : scrut.kind === "Union"
          ? (scrut.variants.find(
              (v) => v.kind === "Tuple" && v.elements.length === pattern.elements.length,
            ) ?? TY.unresolved)
          : TY.unresolved;
    if (tupleTy.kind === "Tuple") {
      for (let i = 0; i < pattern.elements.length; i++) {
        const elem = pattern.elements[i]!;
        const elemTy = tupleTy.elements[i] ?? TY.unresolved;
        out.push(...bindingNarrowings(t, elem, elemTy, null));
      }
    }
    return out;
  }
  return out;
}

function collectStructFieldBindings(
  t: MutableTyped, pattern: A.StructPattern, sourceType: Type,
  out: { sym: Symbol; type: Type }[],
): void {
  for (const f of pattern.fields) {
    if (f.value.kind !== "binding") continue;
    const sym = t.resolved.patternBindings.get(f);
    if (sym === undefined) continue;
    const ft = fieldTypeOnType(sourceType, f.name, t) ?? TY.unresolved;
    out.push({ sym, type: ft });
  }
}
