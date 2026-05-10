// Trait-satisfaction queries used by typecheck — Display (for `${...}`
// interpolation), Error (for `?` propagation), and a generic by-name lookup
// that also covers `Iterator`, `Display`, etc. across std/core and the local
// module.

import type { Symbol } from "../../resolver/symbol.ts";

import type { ImplRegistry } from "../impls.ts";
import type { Type } from "../types.ts";
import { CORE_TRAITS } from "../types.ts";

import type { MutableTyped } from "../ctx.ts";

export function implementsDisplay(ty: Type, t: MutableTyped, impls: ImplRegistry): boolean {
  // SPEC §9: every primitive impls Display.
  if (ty.kind === "Primitive") return true;
  if (ty.kind === "FreeInt" || ty.kind === "FreeFloat") return true;
  if (ty.kind === "Unresolved") return true;
  const display = findDisplayTrait(t);
  if (display === null) return false;
  if (ty.kind === "Struct") return impls.hasUser(ty.symbol, display);
  // Enums opt in by declaring an explicit `implements Display` (the variant
  // names alone don't carry a textual form — the trait gives the user one).
  if (ty.kind === "Enum") return impls.hasUser(ty.symbol, display);
  if (ty.kind === "Union") return ty.variants.every((v) => implementsDisplay(v, t, impls));
  return false;
}

export function findDisplayTrait(t: MutableTyped): Symbol | null {
  return findGlobalTrait(t, CORE_TRAITS.Display);
}

export function findErrorTrait(t: MutableTyped): Symbol | null {
  return findGlobalTrait(t, CORE_TRAITS.Error);
}

/** Look up a trait by name in std/core (auto-imported) or the local module. */
export function findGlobalTrait(t: MutableTyped, name: string): Symbol | null {
  const local = t.resolved.module.symbols.get(name);
  if (local?.kind === "trait") return local;
  const core = t.globals.coreSymbols?.get(name);
  return core?.kind === "trait" ? core : null;
}
