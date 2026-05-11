import type * as A from "../parser/ast.ts";
import type { ResolvedProgram, ResolvedProject } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { ImplEntry } from "./impls.ts";
import type { Substitution, Type } from "./types.ts";

export interface MethodResolution {
  /** The impl block that owns this method. */
  readonly impl: ImplEntry;
  /** The fn decl inside the impl block. */
  readonly member: A.FnDecl;
  /** Receiver type — what `self` was bound to when the method was looked up.
   *  Used by the lowerer to materialise the right impl specialisation. */
  readonly receiverType: Type;
  /** Trait args at the use site (e.g. `[i32]` for `iter` of `Iterator(i32)`). */
  readonly traitArgs: readonly Type[];
}

/** Trait-method dispatch on a generic type parameter — recorded by the
 *  type-checker at every `t.method(args)` call where `t` has a `TypeParam`
 *  type whose surrounding fn / struct declares a `where T: Trait` clause and
 *  the matching trait carries that method.
 *
 *  The lowerer cannot resolve to a concrete impl until monomorphization has
 *  applied the substitution at the call site — at typecheck time we only
 *  know "K satisfies Hash" abstractly, not "K = i32". The mono pass uses
 *  this resolution + the call-site substitution to look up the concrete
 *  impl-member's `MonoEntry`, then hands the lowerer a direct fn symbol. */
export interface TraitMethodResolution {
  /** Symbol of the trait whose method matched. */
  readonly trait: Symbol;
  /** The fn decl on the trait whose name matched the call. */
  readonly member: A.FnDecl;
  /** TypeParam type of the receiver — the substitution applied at mono time
   *  resolves this to a concrete type. */
  readonly receiverParam: Type;
}

/** Virtual trait method dispatch on a trait-typed receiver. Recorded by the
 *  type-checker when `obj.method()` and `obj : Some Trait`; the lowerer reads
 *  it to synthesise an `is X -> X_method(box)` cascade over each impl in the
 *  registry. */
export interface TraitVirtualResolution {
  readonly trait: Symbol;
  readonly member: A.FnDecl;
}

/** Common-field access on a discriminated union (§1.18d). Recorded by the
 *  typechecker when `e.f` is valid because every variant of the union has
 *  a field named `f`. The lowerer reads the per-variant `(type, fieldType)`
 *  pairs to synthesise the variant-dispatch cascade. */
export interface UnionFieldResolution {
  readonly variants: readonly { readonly type: Type; readonly fieldType: Type }[];
}

/** Operator overloading resolution. Recorded by the typechecker on every
 *  `BinaryExpr` whose operands aren't handled by the primitive built-in
 *  paths (numeric arith, primitive equality, primitive comparison, string
 *  concat). The lowerer rewrites the binary into a call against the impl's
 *  specialised method.
 *
 *  - `kind: "direct"` — `+ - * / %` ; the result type is the method's
 *    return type (`Self`).
 *  - `kind: "eq"` — `==` / `!=` ; the lowerer wraps with `bool.not` for `!=`.
 *  - `kind: "ord"` — `< <= > >=` ; the lowerer rewrites to
 *    `compare(a, b) <op> 0` against the recorded primitive op.
 */
export type BinaryOpResolution =
  | { readonly kind: "direct"; readonly trait: Symbol; readonly member: A.FnDecl; readonly receiverType: Type }
  | { readonly kind: "eq"; readonly negate: boolean;     readonly trait: Symbol; readonly member: A.FnDecl; readonly receiverType: Type }
  | { readonly kind: "ord"; readonly cmp: "lt" | "lte" | "gt" | "gte"; readonly trait: Symbol; readonly member: A.FnDecl; readonly receiverType: Type };

/** Index dispatch on `a[i]` (read via `Index`) and `a[i] = v` (write via
 *  `IndexSet`) when `a` is not a built-in array. Recorded by the typechecker
 *  so the lowerer can rewrite to `at(self, i)` / `set_at(self, i, v)` of the
 *  matched impl. `mode` distinguishes the two contexts; a given IndexExpr
 *  node appears in exactly one of them (read or write), never both. */
export interface IndexResolution {
  readonly mode: "read" | "write";
  readonly trait: Symbol;
  readonly member: A.FnDecl;
  readonly receiverType: Type;
}

/** Resolution of a `FieldExpr` (`obj.field` or `obj.method`). The typechecker
 *  records exactly one of these per node; the variants are mutually exclusive
 *  by construction (see `inferField` in `passes/call.ts`). The lowerer
 *  switches on `kind` once instead of cascading through six separate Maps. */
export type FieldResolution =
  | { readonly kind: "method";        readonly resolution: MethodResolution }
  | { readonly kind: "trait-method";  readonly resolution: TraitMethodResolution }
  | { readonly kind: "trait-virtual"; readonly resolution: TraitVirtualResolution }
  | { readonly kind: "union-field";   readonly resolution: UnionFieldResolution }
  | { readonly kind: "ufcs-free";     readonly symbol: Symbol }
  | { readonly kind: "array-op";      readonly op: "len" | "push" };

export interface TypedProgram {
  readonly resolved: ResolvedProgram;

  /** Type of every value-position expression in this module. */
  readonly exprTypes: ReadonlyMap<A.Expr, Type>;

  /** Type of every `:=` / `::` local in this module. Keyed per leaf
   *  `SimpleBinding` or `RestBinding`, so destructured-let leaves each
   *  carry their own type. */
  readonly localTypes: ReadonlyMap<A.SimpleBinding | A.RestBinding, Type>;

  /** Globally-shared decl/param/type-expr tables; lookup works cross-module. */
  readonly declTypes: ReadonlyMap<A.Decl, Type>;
  readonly paramTypes: ReadonlyMap<A.FnParam, Type>;
  readonly typeExprTypes: ReadonlyMap<A.TypeExpr, Type>;
  /** ConstDecl whose value is a type expression — Layer 4-sugar implicit
   *  type alias. The lower pass reads this to skip emitting a runtime slot
   *  ; `typeFromSymbol` reads it to serve the alias when the const name
   *  appears in a type-demanding slot. */
  readonly constTypeAliases: ReadonlyMap<A.ConstDecl, Type>;
  /** In-fn `t :: <type-expr>` let-stmts (Layer 5b — type-as-comptime-binding
   *  inside fn bodies). Same shape as `constTypeAliases` but keyed by the
   *  binding's local symbol since let-stmts have no decl AST node. */
  readonly letTypeAliases: ReadonlyMap<Symbol, Type>;

  /** Resolution of every `FieldExpr` node — the six cases (UFCS method,
   *  trait method on a TypeParam receiver, trait-virtual dispatch, common
   *  union-field access, free-fn UFCS, built-in array op) are mutually
   *  exclusive per node and live in this discriminated union. Replaces the
   *  former six parallel Maps. */
  readonly fieldResolutions: ReadonlyMap<A.FieldExpr, FieldResolution>;
  /** Generic fn call sites whose type params were successfully inferred.
   *  Ordered by the fn's `typeParams` list. Consumed by the lowerer. */
  readonly genericFnCalls: ReadonlyMap<A.CallExpr, readonly Type[]>;
  /** Direct `f(args)` calls where overload resolution picked a non-primary
   *  fn symbol. Lowerer consults this before falling back to `resolved.idents`. */
  readonly directCallOverloads: ReadonlyMap<A.CallExpr, Symbol>;
  /** User-defined `Into(Target)` coercion sites. Key: the source-position
   *  expression ; value: the impl entry whose `into` method must be inserted
   *  by the lowerer + the source type so the lowerer can route through the
   *  right monomorphised entry for generic-struct sources. Populated by the
   *  typechecker when a value of type `S` flows into a slot expecting `T`,
   *  `S != T`, and `S implements Into(T)` is found in the impl registry. */
  readonly intoCoercions: ReadonlyMap<A.Expr, IntoCoercion>;
  /** Operator overload resolutions. See `BinaryOpResolution`. */
  readonly binaryOpResolutions: ReadonlyMap<A.BinaryExpr, BinaryOpResolution>;
  /** Per-`IndexExpr` dispatch — `mode: "read"` for `a[i]` and `mode: "write"`
   *  for `a[i] = v`. A node appears in exactly one context, so the previous
   *  twin Maps (`indexResolutions` + `indexSetResolutions`) collapse here. */
  readonly indexResolutions: ReadonlyMap<A.IndexExpr, IndexResolution>;
  /** `for <iter> { body }` — same shape as `for _ in <iter> { body }` but
   *  spelled without the binding. Populated by `checkForStmt` when the
   *  while-form's condition resolves to an iterable type ; the lowerer
   *  reads this to route through the for-in path with the synthesised
   *  discard symbol. */
  readonly whileAsForIn: ReadonlyMap<A.ForStmt, Symbol>;
}

export interface TypedProject {
  readonly resolved: ResolvedProject;
  readonly modules: ReadonlyMap<string, TypedProgram>;
}

/** Recorded `S implements Into(T)` coercion site — see `TypedProgram.intoCoercions`. */
export interface IntoCoercion {
  readonly entry: ImplEntry;
  readonly sourceType: Type;
  /** Substitution mapping the impl's own typeParam ids to concrete
   *  pieces of `sourceType`. Empty for concrete-source impls (`UserId
   *  implements Into(i32)`) ; populated for blanket impls (`T[]
   *  implements[T] Into(Iterator(T))` binds T → element). The lowerer
   *  feeds this into `lookupImplEntry` to land on the right
   *  monomorphised member. */
  readonly implSubst: Substitution;
}
