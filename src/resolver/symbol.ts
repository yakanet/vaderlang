// Symbol table primitives. Symbols are produced by the resolver and consumed
// by every subsequent phase (type-checker, comptime, lowerer, emitters).

import type { Span } from "../diagnostics/diagnostic.ts";
import type * as A from "../parser/ast.ts";

export type ModuleId = string;

export type SymbolKind =
  | "fn"
  | "struct"
  | "enum"
  | "trait"
  | "type-alias"
  | "const"
  | "import-binding"     // imported under a local name (alias, destructured, or namespace)
  | "param"
  | "type-param"
  | "local"
  | "binding"            // for-loop var, match-arm binding, struct-pattern field, is-pattern alias
  | "builtin-type"
  | "builtin-fn"
  | "synthetic";         // compiler-introduced binding (lowerer temps: __scrut, __try, __sb, …)

/** Where a "binding" symbol came from. */
export type BindingOrigin =
  | { readonly kind: "for-in"; readonly stmt: A.ForStmt }
  | { readonly kind: "is-pattern"; readonly pattern: A.IsPattern }
  | { readonly kind: "struct-pattern"; readonly field: A.StructPatternField }
  | { readonly kind: "binding-pattern"; readonly pattern: A.BindingPattern };

export type SymbolId = number;

export interface Symbol {
  readonly id: SymbolId;
  readonly kind: SymbolKind;
  readonly name: string;
  readonly module: ModuleId;
  readonly visibility: "public" | "private";
  readonly definedAt: Span | null;       // null for builtins
  readonly source: SymbolSource;
}

export type SymbolSource =
  | { readonly kind: "fn"; readonly decl: A.FnDecl }
  | { readonly kind: "struct"; readonly decl: A.StructDecl }
  | { readonly kind: "enum"; readonly decl: A.EnumDecl }
  | { readonly kind: "trait"; readonly decl: A.TraitDecl }
  | { readonly kind: "type-alias"; readonly decl: A.TypeAliasDecl }
  | { readonly kind: "const"; readonly decl: A.ConstDecl }
  | { readonly kind: "import"; readonly decl: A.ImportDecl; readonly target: Symbol | null; readonly importedName: string | null }
  | { readonly kind: "param"; readonly param: A.FnParam; readonly fn: A.FnDecl | A.LambdaExpr }
  | { readonly kind: "type-param"; readonly param: A.TypeParam }
  | { readonly kind: "local"; readonly stmt: A.LetStmt; readonly binding: A.SimpleBinding }
  | { readonly kind: "binding"; readonly origin: BindingOrigin }
  | { readonly kind: "builtin-type"; readonly typeName: string }
  | { readonly kind: "builtin-fn"; readonly fnName: string }
  | { readonly kind: "synthetic"; readonly origin: string };

export class SymbolFactory {
  private next: SymbolId = 1;
  make(spec: Omit<Symbol, "id">): Symbol {
    return { id: this.next++, ...spec };
  }
}

/** The AST decl backing a symbol, when there is one. */
export function declOf(sym: Symbol): A.Decl | null {
  switch (sym.source.kind) {
    case "fn":         return sym.source.decl;
    case "struct":     return sym.source.decl;
    case "enum":       return sym.source.decl;
    case "trait":      return sym.source.decl;
    case "type-alias": return sym.source.decl;
    case "const":      return sym.source.decl;
    case "import":     return sym.source.decl;
    default:           return null;
  }
}

/** The struct decl backing a struct symbol; null otherwise. */
export function sourceStructDecl(sym: Symbol): A.StructDecl | null {
  return sym.source.kind === "struct" ? sym.source.decl : null;
}

/** True iff `sym` names a *type* — used by typecheck (call-vs-cast dispatch),
 *  lower (constructor recognition), and the implicit-type-alias detection.
 *  Covers : primitives, user structs/enums/traits, type aliases, type params.
 *  Excludes value-kind symbols (`fn`, `const`, `local`, `param`, …). */
export function isTypeReferenceSymbol(sym: Symbol): boolean {
  switch (sym.kind) {
    case "builtin-type":
    case "struct":
    case "enum":
    case "trait":
    case "type-alias":
    case "type-param":
      return true;
    default:
      return false;
  }
}

/** The enum decl backing an enum symbol; null otherwise. */
export function sourceEnumDecl(sym: Symbol): A.EnumDecl | null {
  return sym.source.kind === "enum" ? sym.source.decl : null;
}

/** The trait decl backing a trait symbol; null otherwise. */
export function sourceTraitDecl(sym: Symbol): A.TraitDecl | null {
  return sym.source.kind === "trait" ? sym.source.decl : null;
}

/** Index of `variant` within `sym`'s enum decl, or -1 if not an enum / not found. */
export function enumVariantIndex(sym: Symbol, variant: string): number {
  const decl = sourceEnumDecl(sym);
  return decl === null ? -1 : decl.variants.findIndex((v) => v.name === variant);
}
