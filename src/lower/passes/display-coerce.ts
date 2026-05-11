// Static calls to a type's `Display.to_string` impl member, used by the
// string-interpolation lowering for non-primitive `${value}` parts
// (`"hello ${user}"` lowers to a builder chain whose middle segments call
// `<User>.Display.to_string(user)` and feed the result into
// `builder.append_str`). Primitives keep the dedicated
// `builder.append_display` op (no allocation needed).
//
// Sibling helper `wrapAsInto` covers user-defined `Into(Target)` coercions
// — same pattern (find the impl member, emit a direct call) but the impl
// is recorded explicitly at typecheck rather than discovered from the
// trait. The legacy `print(value: Display)` → string conversion that
// `wrapAsDisplay` originally handled has migrated to `Into` via the
// blanket `T implements[T: Display] Into(string)` in `std/core` ; only
// the string-interp use site remains here.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_TRAITS, TY, substitute } from "../../typecheck/types.ts";
import type { IntoCoercion } from "../../typecheck/typed-ast.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredExpr } from "../lowered-ast.ts";

import { findCoreTrait } from "./core.ts";
import { lookupImplEntry, lookupImplFor } from "./for-in.ts";

/** Wrap `value` (lowered, type matches `sourceType`) in a static call to the
 *  `<sourceType>.Display.to_string` impl member. Returns `null` when the
 *  impl can't be located — caller falls back to the bare lowered expression
 *  so the typecheck-time error stays the only diagnostic surface. */
export function wrapAsDisplay(
  ctx: FnLowerCtx, value: LoweredExpr, sourceType: Type, span: Span,
): LoweredExpr | null {
  const display = findCoreTrait(ctx.project, CORE_TRAITS.Display);
  if (display === null) return null;
  const impl = lookupImplFor(ctx.project, sourceType, display);
  if (impl === null) return null;
  const member = impl.decl.members.find((m) => m.name === "to_string");
  if (member === undefined) return null;
  // Generic struct receivers (e.g. `Foo($T) implements Display { … }`) need
  // the concrete type-args used at the use site to pick the right
  // monomorphised impl entry. Primitives / non-generic structs feed in an
  // empty arg list and resolve to the single instance.
  const structArgs = sourceType.kind === "Struct" ? sourceType.args : [];
  const entry = lookupImplEntry(ctx, member, structArgs);
  if (entry === null || entry.symbol === null) return null;
  return {
    kind: "LoweredCall", span, type: TY.string,
    callee: { kind: "LoweredIdent", span, type: TY.string, symbol: entry.symbol },
    args: [value],
  };
}

/** Wrap `value` (lowered, type matches `coercion.sourceType`) in a static
 *  call to the `into` member of `coercion.entry`. The trait arg recorded on
 *  the impl gives the target type ; we substitute the source's struct args
 *  through `lookupImplEntry` to land on the right monomorphised member.
 *  Returns null when the entry can't be reached (defensive — typecheck
 *  already validated the impl exists). */
export function wrapAsInto(
  ctx: FnLowerCtx, value: LoweredExpr, coercion: IntoCoercion, span: Span,
): LoweredExpr | null {
  const member = coercion.entry.decl.members.find((m) => m.name === "into");
  if (member === undefined) return null;
  // Two impl shapes :
  //   - Concrete-source impls (`UserId implements Into(i32)`) — no impl
  //     typeParams ; the mono entry is keyed under `""` (the same path
  //     that non-generic struct impls take). For generic-struct sources
  //     (`Foo($T) implements Into(...)`), `source.args` carries the
  //     receiver's concrete type-args.
  //   - Blanket impls (`T[] implements[T] Into(Iterator(T))`) — the
  //     impl's own typeParams are bound by `coercion.implSubst`. We
  //     re-order them into `decl.typeParams` order so the lookup
  //     matches the key the mono pass wrote (see `collectIntoMembers`
  //     in `comptime/evaluate.ts`).
  const implDecl = coercion.entry.decl;
  const typeParamSymbols = ctx.project.evaluated.typed.resolved.typeParamSymbols;
  let args: readonly Type[];
  if (implDecl.typeParams.length > 0) {
    const ordered: Type[] = [];
    for (const tp of implDecl.typeParams) {
      const sym = typeParamSymbols.get(tp);
      if (sym === undefined) return null;
      const ty = coercion.implSubst.typeParams?.get(sym.id);
      if (ty === undefined) return null;
      ordered.push(ctx.types.apply(ty));
    }
    args = ordered;
  } else {
    const source = ctx.types.apply(coercion.sourceType);
    args = source.kind === "Struct" ? source.args : [];
  }
  const entry = lookupImplEntry(ctx, member, args);
  if (entry === null || entry.symbol === null) return null;
  // Recover the target type from the impl's first trait-arg, then apply
  // the impl substitution so e.g. `Iterator(T)` becomes `Iterator(i32)`.
  const targetExpr = implDecl.traitArgs[0];
  const targetRaw = targetExpr !== undefined
    ? ctx.typed.typeExprTypes.get(targetExpr) ?? TY.unresolved
    : TY.unresolved;
  const targetSubstituted = implDecl.typeParams.length > 0
    ? substitute(targetRaw, coercion.implSubst)
    : targetRaw;
  const targetType = ctx.types.apply(targetSubstituted);
  return {
    kind: "LoweredCall", span, type: targetType,
    callee: { kind: "LoweredIdent", span, type: targetType, symbol: entry.symbol },
    args: [value],
  };
}
