// Looks up `std/core` symbols (Iterator, Yield, Error, …) via the
// pre-resolved `ctx.coreSymbols` cache. Used by for-in and try.

import type { Symbol } from "../../resolver/symbol.ts";
import type { Type } from "../../typecheck/types.ts";
import { TY, mkStruct, mkUnion } from "../../typecheck/types.ts";

import type { FnLowerCtx, LowerProjectCtx } from "../ctx.ts";

export function lookupCoreSymbol(ctx: FnLowerCtx, name: string): Symbol | null {
  return ctx.project.coreSymbols?.get(name) ?? null;
}

/** Find a struct type from std/core by name, optionally with type arguments
 *  for generic structs (e.g. `Yield(i32)`). */
export function findCoreType(ctx: FnLowerCtx, name: string, args: readonly Type[]): Type | null {
  const sym = lookupCoreSymbol(ctx, name);
  if (sym === null) return null;
  if (sym.kind !== "struct") return null;
  return mkStruct(sym, args);
}

export function findCoreTrait(ctx: LowerProjectCtx, name: string): Symbol | null {
  const cached = ctx.coreTraitCache.get(name);
  if (cached !== undefined) return cached;
  const sym = ctx.coreSymbols?.get(name) ?? null;
  const found = sym !== null && sym.kind === "trait" ? sym : null;
  ctx.coreTraitCache.set(name, found);
  return found;
}

export function unionOfYieldNull(yielded: Type): Type {
  return mkUnion([yielded, TY.null]);
}
