// Registry of `T implements Trait { ... }` blocks discovered at resolve time.
// The type-checker queries this when validating `where T: Trait` bounds and
// trait dispatch (e.g. operator resolution).

import type * as A from "../parser/ast.ts";
import type { Module } from "../resolver/index.ts";
import type { ResolvedProgram, ResolvedProject } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";

export interface ImplEntry {
  readonly decl: A.ImplDecl;
  readonly traitSymbol: Symbol;       // Symbol of kind "trait"
  readonly forSymbol: Symbol | null;  // user-defined target Symbol; null when implementing a primitive (e.g. `u32 implements Display`)
  readonly module: Module;
}

export class ImplRegistry {
  private readonly userIndex = new Map<string, ImplEntry>();
  private readonly all: ImplEntry[] = [];

  add(entry: ImplEntry): void {
    if (entry.forSymbol !== null) {
      this.userIndex.set(`${entry.forSymbol.id}::${entry.traitSymbol.id}`, entry);
    }
    this.all.push(entry);
  }

  hasUser(forSymbol: Symbol, traitSymbol: Symbol): boolean {
    return this.userIndex.has(`${forSymbol.id}::${traitSymbol.id}`);
  }

  findUser(forSymbol: Symbol, traitSymbol: Symbol): ImplEntry | null {
    return this.userIndex.get(`${forSymbol.id}::${traitSymbol.id}`) ?? null;
  }

  forPrimitive(name: string, traitSymbol: Symbol): ImplEntry | null {
    for (const e of this.all) {
      if (e.forSymbol !== null) continue;
      if (e.traitSymbol.id !== traitSymbol.id) continue;
      if (e.decl.forType.kind === "NamedType" && e.decl.forType.name === name) return e;
    }
    return null;
  }

  entries(): readonly ImplEntry[] { return this.all; }
}

export function buildImplRegistry(project: ResolvedProject): ImplRegistry {
  const reg = new ImplRegistry();
  for (const program of project.modules.values()) {
    collectImpls(program, reg);
  }
  return reg;
}

function collectImpls(program: ResolvedProgram, reg: ImplRegistry): void {
  for (const decl of program.source.decls) {
    if (decl.kind !== "ImplDecl") continue;
    const traitSymbol = program.module.symbols.get(decl.traitName);
    const trait = traitSymbol?.kind === "trait" ? traitSymbol : null;
    if (trait === null) continue;             // resolver already reported R2007/R2009
    const forSymbol = forTypeSymbol(decl.forType, program);
    reg.add({ decl, traitSymbol: trait, forSymbol, module: program.module });
  }
}

function forTypeSymbol(forType: A.TypeExpr, program: ResolvedProgram): Symbol | null {
  if (forType.kind === "NamedType") {
    const sym = program.types.get(forType);
    if (sym !== undefined && (sym.kind === "struct" || sym.kind === "type-alias")) return sym;
  }
  if (forType.kind === "GenericInstType") {
    const sym = program.types.get(forType.base);
    if (sym !== undefined && (sym.kind === "struct" || sym.kind === "type-alias")) return sym;
  }
  return null;
}
