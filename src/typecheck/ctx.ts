// Shared context types threaded through every typecheck pass.
//
// `Globals` is built once per project (newGlobals) and accumulates the
// declared types of every top-level decl. `MutableTyped` is built once per
// module and carries the per-expression / per-local maps the pass writes.
// `FnContext` tracks per-fn-body state (return type, self type, loop depth)
// while statements / expressions inside that body are checked.

import type * as A from "../parser/ast.ts";
import type { Module } from "../resolver/module.ts";
import type { ResolvedProgram, ResolvedProject } from "../resolver/resolved-ast.ts";
import type { ModuleId, Symbol } from "../resolver/symbol.ts";
import type {
  BinaryOpResolution,
  IndexResolution,
  MethodResolution,
  TraitMethodResolution,
  TraitVirtualResolution,
  UnionFieldResolution,
} from "./typed-ast.ts";
import type { Substitution, Type } from "./types.ts";

/** Tables shared across modules — populated by declareTypes, consumed by check bodies. */
export interface Globals {
  readonly declTypes: Map<A.Decl, Type>;
  readonly paramTypes: Map<A.FnParam, Type>;
  readonly typeExprTypes: Map<A.TypeExpr, Type>;
  /** ConstDecl whose value is a *type* (statically typed `type` / `TypeMeta`)
   *  is implicitly a type alias (Layer 4-sugar — drops the `type` keyword
   *  in `Foo :: type X`). The resolved underlying type lives here ; the
   *  matching `declTypes` entry still records `TY.type` as the value's
   *  static type so `typeOfSymbol` keeps reporting the right thing.
   *  Read by `typeFromSymbol` when a const symbol is used in a type
   *  position, and by the lower pass to decide whether to skip emitting
   *  a runtime slot. */
  readonly constTypeAliases: Map<A.ConstDecl, Type>;
  readonly letTypeAliases: Map<Symbol, Type>;
  /** Auto-imported std/core symbols, looked up for Display / Error / Iterator etc. */
  coreSymbols: ReadonlyMap<string, Symbol> | null;
  /** Cross-module typeParam table from the resolver — used for O(1) lookup
   *  when user code instantiates a generic stdlib struct and we need its
   *  typeParam symbols. */
  typeParamSymbols: ReadonlyMap<A.TypeParam, Symbol>;
  /** All modules in the project, indexed by ModuleId. Used to look up
   *  `fnOverloads` for a given symbol's defining module — needed by the
   *  UFCS dispatch when picking the right overload by receiver type. */
  modules: ReadonlyMap<ModuleId, Module> | null;
  /** Trait bounds declared on each TypeParam Symbol, populated by the
   *  resolver from `where T: Trait` clauses. Read by the typechecker when a
   *  `t.method()` site has a TypeParam-typed receiver. */
  typeParamBounds: ReadonlyMap<number, readonly Symbol[]>;
  /** Shared symbol id allocator from the resolver — typecheck mints
   *  synthetic locals (e.g. the `for <iter>` discard binding) through this
   *  so ids stay globally unique across phases. */
  factory: import("../resolver/symbol.ts").SymbolFactory;
}

export function newGlobals(
  typeParamSymbols: ReadonlyMap<A.TypeParam, Symbol>,
  typeParamBounds: ReadonlyMap<number, readonly Symbol[]>,
  factory: import("../resolver/symbol.ts").SymbolFactory,
): Globals {
  return {
    declTypes: new Map(), paramTypes: new Map(), typeExprTypes: new Map(),
    constTypeAliases: new Map(),
    letTypeAliases: new Map(),
    coreSymbols: null,
    typeParamSymbols,
    typeParamBounds,
    modules: null,
    factory,
  };
}

export interface MutableTyped {
  readonly resolved: ResolvedProgram;
  readonly globals: Globals;
  readonly exprTypes: Map<A.Expr, Type>;
  readonly localTypes: Map<A.SimpleBinding | A.RestBinding, Type>;
  /** Active narrowings keyed by symbol.id. Push/pop-managed by `inferMatch`
   *  so that references to a scrutinee symbol inside an `is T -> body` arm
   *  see `T` instead of the full union. Nested matches stack naturally. */
  readonly narrowed: Map<number, Type>;
  /** UFCS-resolved trait method calls. Populated by `inferField`, consumed
   *  by `inferCall` and the lowerer. */
  readonly methodResolutions: Map<A.FieldExpr, MethodResolution>;
  /** Trait-method dispatch on a generic TypeParam receiver. Populated by
   *  `inferField`, consumed by the monomorphizer (which resolves to a
   *  concrete impl member once the call-site substitution is known) and the
   *  lowerer. */
  readonly traitMethodResolutions: Map<A.FieldExpr, TraitMethodResolution>;
  /** Virtual trait-method dispatch on a trait-typed receiver. Populated by
   *  `inferField`, consumed by the lowerer to emit a tag-keyed dispatch. */
  readonly traitVirtualResolutions: Map<A.FieldExpr, TraitVirtualResolution>;
  /** Common-field access on union receivers (§1.18d) — `e.f` over a union
   *  whose every variant carries a field named `f`. Populated by
   *  `inferField`, consumed by the lowerer to synthesise the variant-
   *  dispatch cascade. The variants are recorded in source order so the
   *  cascade is stable. */
  readonly unionFieldResolutions: Map<A.FieldExpr, UnionFieldResolution>;
  /** UFCS-resolved free function calls (`a.f(b)` → `f(a, b)`). Populated by
   *  `inferField` after type-validating the resolver's candidate, consumed by
   *  the lowerer to prepend the receiver as the first argument. */
  readonly ufcsFreeResolutions: Map<A.FieldExpr, Symbol>;
  /** Built-in array method calls (`len`, `push`). Populated by `inferField`,
   *  consumed by the lowerer to emit `LoweredArrayLen`/`LoweredArrayPush`. */
  readonly arrayOps: Map<A.FieldExpr, "len" | "push">;
  /** Generic fn call sites whose type params were successfully inferred.
   *  Key: the CallExpr; value: ordered concrete type-args matching the fn's
   *  `typeParams` list. Populated by `inferCall`, consumed by the lowerer to
   *  route the call to the right monomorphized specialisation. */
  readonly genericFnCalls: Map<A.CallExpr, readonly Type[]>;
  /** Direct `f(args)` calls whose name resolves to multiple fn overloads —
   *  records the chosen overload's symbol so the lowerer dispatches to the
   *  right specialisation. Empty when the resolver's primary already matched
   *  (single overload, or first overload picked unambiguously). */
  readonly directCallOverloads: Map<A.CallExpr, Symbol>;
  /** `[T]` → `Iterator(T)` coercion sites. See `TypedProgram.arrayIterCoercions`. */
  readonly arrayIterCoercions: Map<A.Expr, Type>;
  /** `T` → `Display` coercion sites. See `TypedProgram.displayCoercions`. */
  readonly displayCoercions: Map<A.Expr, Type>;
  /** Operator-overload dispatch sites. See `TypedProgram.binaryOpResolutions`. */
  readonly binaryOpResolutions: Map<A.BinaryExpr, BinaryOpResolution>;
  /** Index trait dispatch sites for `a[i]` reads. */
  readonly indexResolutions: Map<A.IndexExpr, IndexResolution>;
  /** IndexSet trait dispatch sites for `a[i] = v` writes. */
  readonly indexSetResolutions: Map<A.IndexExpr, IndexResolution>;
  /** `for <iter> { body }` (no binding) sites where the cond resolves to an
   *  iterable. The synthesised symbol stands in for the discarded binding
   *  the lowerer would otherwise read from `resolved.forIns`. */
  readonly whileAsForIn: Map<A.ForStmt, Symbol>;
}

/** Find the std/core module's exported symbol map. Used by the impl registry
 *  builder and the project typecheck setup to resolve trait names that come
 *  from the auto-imported core (e.g. `T implements Display` where `Display`
 *  isn't in the local module's symbol table). */
export function findCoreSymbols(project: ResolvedProject): ReadonlyMap<string, Symbol> | null {
  for (const program of project.modules.values()) {
    if (program.module.displayPath === "std/core") return program.module.symbols;
  }
  return null;
}

/** Build a typeParam-id → concrete-arg substitution. Works on any source of
 *  `A.TypeParam → Symbol` resolution — typecheck `Globals.typeParamSymbols`
 *  or the resolver's per-program `typeParams` map both fit. */
export function buildStructSubst(
  typeParams: readonly A.TypeParam[],
  args: readonly Type[],
  typeParamSymbols: ReadonlyMap<A.TypeParam, Symbol>,
): Substitution {
  if (typeParams.length === 0 || args.length === 0) return {};
  const bindings = new Map<number, Type>();
  for (let i = 0; i < typeParams.length && i < args.length; i++) {
    const sym = typeParamSymbols.get(typeParams[i]!);
    if (sym !== undefined) bindings.set(sym.id, args[i]!);
  }
  return { typeParams: bindings };
}

/** Substitution for a generic struct instance, or `null` if the decl's
 *  type-param count doesn't match the args count (so the caller can fall back
 *  to the raw, unsubstituted type). */
export function tryStructSubst(
  decl: { readonly typeParams: readonly A.TypeParam[] },
  args: readonly Type[],
  globals: Globals,
): Substitution | null {
  if (args.length === 0 || decl.typeParams.length !== args.length) return null;
  return buildStructSubst(decl.typeParams, args, globals.typeParamSymbols);
}

export interface FnContext {
  readonly returnType: Type;
  /** Self type when type-checking a method body inside an impl block. */
  readonly selfType: Type | null;
  loopDepth: number;
}
