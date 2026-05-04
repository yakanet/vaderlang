// Builtin types and the synthetic <builtin> module they live in.
//
// Primitive type names are recognised by the resolver and bound to symbols in
// a synthetic module so later phases can reason about them uniformly.

import { PRIMITIVE_NAMES } from "../typecheck/types.ts";
import type { Symbol } from "./symbol.ts";
import { SymbolFactory } from "./symbol.ts";

export const BUILTIN_MODULE_ID = "<builtin>";

/** Names visible at every scope's root. Primitives + the `type` metatype + `Self`. */
export const BUILTIN_TYPE_NAMES: readonly string[] = [
  ...PRIMITIVE_NAMES,
  "type",
  "Self",
];

export interface BuiltinScope {
  readonly types: ReadonlyMap<string, Symbol>;
  readonly all: readonly Symbol[];
}

export function makeBuiltinScope(factory: SymbolFactory): BuiltinScope {
  const types = new Map<string, Symbol>();
  const all: Symbol[] = [];
  for (const name of BUILTIN_TYPE_NAMES) {
    const sym = factory.make({
      kind: "builtin-type",
      name,
      module: BUILTIN_MODULE_ID,
      visibility: "public",
      definedAt: null,
      source: { kind: "builtin-type", typeName: name },
    });
    types.set(name, sym);
    all.push(sym);
  }
  return { types, all };
}

export function isBuiltinTypeName(name: string): boolean {
  return BUILTIN_TYPE_NAMES.includes(name);
}
