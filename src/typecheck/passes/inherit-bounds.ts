// Auto-inherit struct-level type-param bounds onto methods declared as free
// fns whose first parameter is the struct itself. Saves repeating the bound
// on every method signature when the struct already declares it.
//
// Trigger pattern (recognised on every fn decl) :
//   - the fn has at least one type-param,
//   - its first value-param's resolved type is a `Struct` instance,
//   - each struct type-arg is a `TypeParam` whose symbol matches one of the
//     fn's type-params (positional alignment).
// For every such match the corresponding struct type-param's bounds are
// copied onto the fn's type-param entry in `Globals.typeParamBounds`. Bounds
// already present on the fn type-param are preserved ; duplicates are
// skipped.
//
// Example : `MutableMap[K: Hash & Equals, V]` — methods previously had to
// repeat `[K: Hash & Equals, V]`. Now `put :: fn[K, V](self: MutableMap(K, V),
// key: K, value: V) -> void` is sufficient ; `key.hash()` inside the body
// sees the inherited bound at typecheck.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { ResolvedProject } from "../../resolver/resolved-ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";

import type { Globals } from "../ctx.ts";

export function inheritStructBounds(
  project: ResolvedProject,
  globals: Globals,
  _diags: DiagnosticCollector,
): void {
  // The underlying allocation is mutable ; the public type is `ReadonlyMap`
  // for safety against cross-cutting writes elsewhere. Cast once here so the
  // append fits in three lines below.
  const bounds = globals.typeParamBounds as Map<number, Symbol[]>;
  for (const program of project.modules.values()) {
    for (const decl of program.source.decls) {
      if (decl.kind === "FnDecl") inheritForFn(decl, globals, bounds);
      else if (decl.kind === "ImplDecl") {
        for (const member of decl.members) inheritForFn(member, globals, bounds);
      }
    }
  }
}

function inheritForFn(
  fn: A.FnDecl,
  globals: Globals,
  bounds: Map<number, Symbol[]>,
): void {
  if (fn.typeParams.length === 0) return;
  if (fn.params.length === 0) return;
  const first = fn.params[0]!;
  if (first.type === null) return;
  const ty = globals.paramTypes.get(first);
  if (ty === undefined || ty.kind !== "Struct") return;
  const structSym = ty.symbol;
  if (structSym.source.kind !== "struct") return;
  const structDecl = structSym.source.decl;
  if (structDecl.typeParams.length === 0) return;

  // Collect the fn's type-param symbol ids so we can recognise positional
  // references in the struct's args.
  const fnTpIds = new Set<number>();
  for (const tp of fn.typeParams) {
    const sym = globals.typeParamSymbols.get(tp);
    if (sym !== undefined) fnTpIds.add(sym.id);
  }

  for (let i = 0; i < ty.args.length && i < structDecl.typeParams.length; i++) {
    const arg = ty.args[i]!;
    if (arg.kind !== "TypeParam") continue;
    if (!fnTpIds.has(arg.symbol.id)) continue;
    const structTpSym = globals.typeParamSymbols.get(structDecl.typeParams[i]!);
    if (structTpSym === undefined) continue;
    const structBounds = bounds.get(structTpSym.id);
    if (structBounds === undefined || structBounds.length === 0) continue;

    const existing = bounds.get(arg.symbol.id);
    const merged: Symbol[] = existing === undefined ? [] : [...existing];
    let added = false;
    for (const b of structBounds) {
      if (!merged.some((m) => m.id === b.id)) {
        merged.push(b);
        added = true;
      }
    }
    if (added) bounds.set(arg.symbol.id, merged);
  }
}
