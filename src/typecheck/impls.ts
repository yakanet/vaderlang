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
}

export class ImplRegistry {
  private readonly userIndex = new Map<string, ImplEntry>();
  private readonly byTrait = new Map<number, ImplEntry[]>();
  private readonly all: ImplEntry[] = [];
  private coreSymbols: ReadonlyMap<string, Symbol> | null = null;

  add(entry: ImplEntry): void {
    if (entry.forSymbol !== null) {
      this.userIndex.set(`${entry.forSymbol.id}::${entry.traitSymbol.id}`, entry);
    }
    const bucket = this.byTrait.get(entry.traitSymbol.id);
    if (bucket === undefined) this.byTrait.set(entry.traitSymbol.id, [entry]);
    else bucket.push(entry);
    this.all.push(entry);
  }

  hasUser(forSymbol: Symbol, traitSymbol: Symbol): boolean {
    return this.userIndex.has(`${forSymbol.id}::${traitSymbol.id}`);
  }

  findUser(forSymbol: Symbol, traitSymbol: Symbol): ImplEntry | null {
    return this.userIndex.get(`${forSymbol.id}::${traitSymbol.id}`) ?? null;
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
   *  or a primitive. Other shapes (Array, Trait, TypeParam, …) have no impl
   *  by construction. */
  findFor(forType: Type, traitSymbol: Symbol): ImplEntry | null {
    if (forType.kind === "Struct") return this.findUser(forType.symbol, traitSymbol);
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
    reg.add({ decl, traitSymbol, forSymbol, module: program.module });
  }
}

function forTypeSymbol(forType: A.TypeExpr, program: ResolvedProgram): Symbol | null {
  if (forType.kind === "IdentExpr") {
    const sym = program.types.get(forType);
    if (sym !== undefined && (sym.kind === "struct" || sym.kind === "type-alias")) return sym;
  }
  if (forType.kind === "GenericInstType") {
    const sym = program.types.get(forType.base);
    if (sym !== undefined && (sym.kind === "struct" || sym.kind === "type-alias")) return sym;
  }
  return null;
}
