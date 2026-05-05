// Output of the monomorphization pass: a flat list of concrete decls (one per
// non-generic decl plus one per `(generic decl, concrete args)` instance).
// Each entry carries the substitution to apply when lowering bodies and looking
// up types — the original decl AST is never mutated.

import type * as A from "../parser/ast.ts";
import type { ResolvedProgram } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { Substitution, Type } from "../typecheck/types.ts";

/** Mangled-name suffix produced for any fn named `main`. The DCE root finder,
 *  the VM's entry-point lookup, and the C emitter's `main()` shim all key off
 *  this. Centralised so they stay in sync. */
export const MAIN_MANGLED_SUFFIX = "$main";

export function isMainMangled(mangled: string): boolean {
  return mangled.endsWith(MAIN_MANGLED_SUFFIX);
}

export interface MonoEntry {
  /** Stable mangled name, e.g. `main` or `List$i32`. Used as the lowered decl's identity. */
  readonly mangled: string;
  /** Origin decl in the source AST. Multiple MonoEntry can share the same origin (different specialisations). */
  readonly decl: A.FnDecl | A.StructDecl | A.ImplDecl | A.ConstDecl;
  /** The decl's symbol, when applicable. ImplDecl has none — its members are emitted as separate entries. */
  readonly symbol: Symbol | null;
  /** Substitution mapping `TypeParam` symbol IDs to the concrete type-args. Empty for non-generic decls. */
  readonly subst: Substitution;
  /** When this entry comes from a generic instantiation, the concrete type-args (in source order). */
  readonly typeArgs: readonly Type[];
  /** Module the origin decl lives in — needed for resolver-table lookups. */
  readonly module: ResolvedProgram;
}

export interface MonoProject {
  readonly entries: readonly MonoEntry[];
  /** Lookup by `(declIdentity, typeArgsKey)` returning the entry's mangled name. */
  readonly lookupByInstance: ReadonlyMap<string, MonoEntry>;
  /** Lookup by impl member FnDecl, then by the struct args' display key. The
   *  inner key is `""` for non-generic impls; for generic impls it's
   *  `displayType(arg).join(",")` so each `(member, struct args)` pair
   *  resolves to its specialised entry. */
  readonly implMethodEntries: ReadonlyMap<A.FnDecl, ReadonlyMap<string, MonoEntry>>;
  /** Lookup by generic FnDecl, then by the concrete type-args key (`displayType`
   *  joined by `,`). Populated by the fn-instance pass for call sites of the
   *  form `foo(T)(args)`. */
  readonly fnInstanceEntries: ReadonlyMap<A.FnDecl, ReadonlyMap<string, MonoEntry>>;
}
