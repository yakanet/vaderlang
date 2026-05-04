// Symbol table primitives. Symbols are produced by the resolver and consumed
// by every subsequent phase (type-checker, comptime, lowerer, emitters).

import type { Span } from "../diagnostics/diagnostic.ts";
import type * as A from "../parser/ast.ts";

export type ModuleId = string;

export type SymbolKind =
  | "fn"
  | "struct"
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
  | { readonly kind: "trait"; readonly decl: A.TraitDecl }
  | { readonly kind: "type-alias"; readonly decl: A.TypeAliasDecl }
  | { readonly kind: "const"; readonly decl: A.ConstDecl }
  | { readonly kind: "import"; readonly decl: A.ImportDecl; readonly target: Symbol | null; readonly importedName: string | null }
  | { readonly kind: "param"; readonly param: A.FnParam; readonly fn: A.FnDecl | A.LambdaExpr }
  | { readonly kind: "type-param"; readonly param: A.TypeParam }
  | { readonly kind: "local"; readonly stmt: A.LetStmt }
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
    case "trait":      return sym.source.decl;
    case "type-alias": return sym.source.decl;
    case "const":      return sym.source.decl;
    case "import":     return sym.source.decl;
    default:           return null;
  }
}
