// Coerces a value flowing into a `Display`-typed slot through a static call
// to `<T>.Display.to_string`. The typechecker records the source type at the
// use site (`displayCoercions`) ; this helper resolves the matching impl
// member and synthesises the call. Pairs with `@intrinsic <T> implements
// Display` declarations in `std/core` and `std/string_builder` so calls like
// `print(42)` lower to `print(<i32_to_string>(42))` without a generic Vader
// wrapper getting monomorphised per-type.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_TRAITS, TY } from "../../typecheck/types.ts";

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
