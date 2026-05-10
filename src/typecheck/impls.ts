// Registry of `T implements Trait { ... }` blocks discovered at resolve time.
// The type-checker queries this when validating `where T: Trait` bounds and
// trait dispatch (e.g. operator resolution).

import type * as A from "../parser/ast.ts";
import type { Module } from "../resolver/index.ts";
import type { ResolvedProgram, ResolvedProject } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import { findCoreSymbols } from "./ctx.ts";
import type { Type } from "./types.ts";

export interface ImplEntry {
  readonly decl: A.ImplDecl;
  readonly traitSymbol: Symbol;       // Symbol of kind "trait"
  readonly forSymbol: Symbol | null;  // user-defined target Symbol; null when implementing a primitive (e.g. `u32 implements Display`)
  readonly module: Module;
  /** For struct-targeting impls : a string key matching the for-type's
   *  concrete args (`"i32"`, `"i32,string"`), or `"*"` for generic-arg
   *  impls (`Foo[T] implements Bar`). Lets `findFor` distinguish
   *  `Foo[i32] implements Bar` from `Foo[char] implements Bar` ;
   *  generic-arg impls match any concrete instantiation. */
  readonly forArgsKey: string;
}

export class ImplRegistry {
  /** Key : `${forSymbol.id}::${traitSymbol.id}::${forArgsKey}`. Concrete-arg
   *  impls register under the concrete key ; generic-arg impls register under
   *  `*`. Lookup probes the concrete key first, then the wildcard. */
  private readonly userIndex = new Map<string, ImplEntry>();
  private readonly byTrait = new Map<number, ImplEntry[]>();
  private readonly all: ImplEntry[] = [];
  private coreSymbols: ReadonlyMap<string, Symbol> | null = null;

  add(entry: ImplEntry): void {
    if (entry.forSymbol !== null) {
      this.userIndex.set(`${entry.forSymbol.id}::${entry.traitSymbol.id}::${entry.forArgsKey}`, entry);
    }
    const bucket = this.byTrait.get(entry.traitSymbol.id);
    if (bucket === undefined) this.byTrait.set(entry.traitSymbol.id, [entry]);
    else bucket.push(entry);
    this.all.push(entry);
  }

  hasUser(forSymbol: Symbol, traitSymbol: Symbol): boolean {
    const prefix = `${forSymbol.id}::${traitSymbol.id}::`;
    for (const k of this.userIndex.keys()) if (k.startsWith(prefix)) return true;
    return false;
  }

  findUser(forSymbol: Symbol, traitSymbol: Symbol): ImplEntry | null {
    return this.findUserWithArgs(forSymbol, traitSymbol, "*");
  }

  /** Look up `forSymbol implements traitSymbol` constrained by the for-type's
   *  concrete args. Tries the exact match first, falls back to the generic
   *  `*` impl. */
  private findUserWithArgs(
    forSymbol: Symbol, traitSymbol: Symbol, argsKey: string,
  ): ImplEntry | null {
    const concrete = this.userIndex.get(`${forSymbol.id}::${traitSymbol.id}::${argsKey}`);
    if (concrete !== undefined) return concrete;
    return this.userIndex.get(`${forSymbol.id}::${traitSymbol.id}::*`) ?? null;
  }

  forPrimitive(name: string, traitSymbol: Symbol): ImplEntry | null {
    const bucket = this.byTrait.get(traitSymbol.id);
    if (bucket === undefined) return null;
    for (const e of bucket) {
      if (e.forSymbol !== null) continue;
      if (e.decl.forType.kind === "IdentExpr" && e.decl.forType.name === name) return e;
    }
    return null;
  }

  /** Resolve `(forType, trait)` regardless of whether `forType` is a struct
   *  or a primitive. Struct lookups consider the concrete type-args so
   *  `Range[i32] implements Iterator` and `Range[char] implements Iterator`
   *  coexist without clobbering each other. Other shapes (Array, Trait,
   *  TypeParam, …) have no impl by construction. */
  findFor(forType: Type, traitSymbol: Symbol): ImplEntry | null {
    if (forType.kind === "Struct") {
      const argsKey = forType.args.length === 0 ? "" : forType.args.map(implArgKey).join(",");
      return this.findUserWithArgs(forType.symbol, traitSymbol, argsKey);
    }
    if (forType.kind === "Primitive") return this.forPrimitive(forType.name, traitSymbol);
    return null;
  }

  /** Every impl whose trait matches — used by the lowerer to synthesise
   *  virtual dispatch over a trait-typed receiver. */
  forTrait(traitSymbol: Symbol): readonly ImplEntry[] {
    return this.byTrait.get(traitSymbol.id) ?? [];
  }

  /** Resolves a `std/core` trait by name. Returns `null` outside std-aware
   *  pipelines (e.g. snapshot dumps). Used by `isAssignable` to gate trait
   *  coercions on canonical-symbol identity. */
  coreTrait(name: string): Symbol | null {
    const sym = this.coreSymbols?.get(name);
    return sym?.kind === "trait" ? sym : null;
  }

  entries(): readonly ImplEntry[] { return this.all; }

  /** @internal — set by `buildImplRegistry` after resolving std/core. */
  setCoreSymbols(coreSymbols: ReadonlyMap<string, Symbol> | null): void {
    this.coreSymbols = coreSymbols;
  }
}

export function buildImplRegistry(project: ResolvedProject): ImplRegistry {
  const reg = new ImplRegistry();
  const coreSymbols = findCoreSymbols(project);
  reg.setCoreSymbols(coreSymbols);
  for (const program of project.modules.values()) {
    collectImpls(program, reg, coreSymbols);
  }
  return reg;
}

function collectImpls(
  program: ResolvedProgram,
  reg: ImplRegistry,
  coreSymbols: ReadonlyMap<string, Symbol> | null,
): void {
  for (const decl of program.source.decls) {
    if (decl.kind !== "ImplDecl") continue;
    const local = program.module.symbols.get(decl.traitName);
    const fallback = coreSymbols?.get(decl.traitName);
    const traitSymbol = local?.kind === "trait" ? local
                      : fallback?.kind === "trait" ? fallback
                      : null;
    if (traitSymbol === null) continue;       // resolver already reported R2007/R2009
    const forSymbol = forTypeSymbol(decl.forType, program);
    const forArgsKey = computeForArgsKey(decl.forType, program);
    reg.add({ decl, traitSymbol, forSymbol, module: program.module, forArgsKey });
  }
}

function forTypeSymbol(forType: A.TypeExpr, program: ResolvedProgram): Symbol | null {
  if (forType.kind === "IdentExpr") {
    const sym = program.types.get(forType);
    if (sym !== undefined && (sym.kind === "struct" || sym.kind === "type-alias")) return sym;
  }
  if (forType.kind === "GenericInstExpr" && forType.callee.kind === "IdentExpr") {
    const sym = program.types.get(forType.callee);
    if (sym !== undefined && (sym.kind === "struct" || sym.kind === "type-alias")) return sym;
  }
  return null;
}

/** AST-side counterpart to `findFor`'s structural match. Returns `""` for
 *  bare `Foo implements ...` (no type-args), `"*"` if any arg is a generic
 *  type-param, otherwise the comma-joined ident names of the concrete args
 *  (`"i32"`, `"i32,string"`). The names match the format `implArgKey`
 *  builds from a runtime `Type`. */
function computeForArgsKey(forType: A.TypeExpr, program: ResolvedProgram): string {
  if (forType.kind !== "GenericInstExpr") return "";
  const parts: string[] = [];
  for (const arg of forType.typeArgs) {
    if (arg.kind === "IdentExpr") {
      // Type-param refs (`Foo[T]`) land in `typeParamTypes`, not `types`.
      // Either side carrying a type-param symbol means the impl matches any
      // concrete instantiation.
      if (program.typeParamTypes.get(arg) !== undefined) return "*";
      const sym = program.types.get(arg);
      if (sym?.kind === "type-param") return "*";
      parts.push(arg.name);
      continue;
    }
    return "*";
  }
  return parts.join(",");
}

/** Runtime-side key matching `computeForArgsKey`'s AST format. Primitive
 *  args read off their `name` ; struct args render as the bare struct name
 *  (e.g. `Range[i32]` ⇒ `"Range"`) — the impl side uses the same shape. */
function implArgKey(t: Type): string {
  if (t.kind === "Primitive") return t.name;
  if (t.kind === "Struct") return t.symbol.name;
  return "*";
}
