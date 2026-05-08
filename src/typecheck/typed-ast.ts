import type * as A from "../parser/ast.ts";
import type { ResolvedProgram, ResolvedProject } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { ImplEntry } from "./impls.ts";
import type { Type } from "./types.ts";

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

/** Index dispatch on `a[i]` (read) and `a[i] = v` (write) when `a` is not a
 *  built-in array. Recorded by the typechecker so the lowerer can rewrite to
 *  `at(self, i)` / `set_at(self, i, v)` of the matched impl. */
export interface IndexResolution {
  readonly trait: Symbol;
  readonly member: A.FnDecl;
  readonly receiverType: Type;
}

export interface TypedProgram {
  readonly resolved: ResolvedProgram;

  /** Type of every value-position expression in this module. */
  readonly exprTypes: ReadonlyMap<A.Expr, Type>;

  /** Type of every `:=` / `::` local in this module. Keyed per leaf
   *  `SimpleBinding`, so destructured-let leaves each carry their own type. */
  readonly localTypes: ReadonlyMap<A.SimpleBinding, Type>;

  /** Globally-shared decl/param/type-expr tables; lookup works cross-module. */
  readonly declTypes: ReadonlyMap<A.Decl, Type>;
  readonly paramTypes: ReadonlyMap<A.FnParam, Type>;
  readonly typeExprTypes: ReadonlyMap<A.TypeExpr, Type>;

  /** `obj.method` field accesses that resolved to a trait-impl method via
   *  UFCS. The lowerer reads this to rewrite `obj.method(args)` into a
   *  direct call of the impl's specialised fn with `obj` as the first arg. */
  readonly methodResolutions: ReadonlyMap<A.FieldExpr, MethodResolution>;
  /** `obj.method` field accesses where `obj` has a TypeParam type and the
   *  surrounding fn / struct's `where` clause binds the parameter to a
   *  trait that owns `method`. Resolved at mono time once the substitution
   *  pins the receiver to a concrete type. */
  readonly traitMethodResolutions: ReadonlyMap<A.FieldExpr, TraitMethodResolution>;
  /** `obj.method` where `obj` itself has a Trait type (existential). The
   *  lowerer emits a chain of `is X -> X_method(box)` dispatches over every
   *  registered impl of the trait. */
  readonly traitVirtualResolutions: ReadonlyMap<A.FieldExpr, TraitVirtualResolution>;
  /** `obj.fn(args)` UFCS on free imported functions — rewritten to `fn(obj, args)`.
   *  Populated by the typechecker after validating first-param compatibility. */
  readonly ufcsFreeResolutions: ReadonlyMap<A.FieldExpr, Symbol>;
  /** Built-in array methods (`len`, `push`). The lowerer emits
   *  `LoweredArrayLen`/`LoweredArrayPush` for these call sites. */
  readonly arrayOps: ReadonlyMap<A.FieldExpr, "len" | "push">;
  /** Generic fn call sites whose type params were successfully inferred.
   *  Ordered by the fn's `typeParams` list. Consumed by the lowerer. */
  readonly genericFnCalls: ReadonlyMap<A.CallExpr, readonly Type[]>;
  /** Direct `f(args)` calls where overload resolution picked a non-primary
   *  fn symbol. Lowerer consults this before falling back to `resolved.idents`. */
  readonly directCallOverloads: ReadonlyMap<A.CallExpr, Symbol>;
  /** Implicit `[T]` → `Iterator(T)` coercion sites. Key: the source-position
   *  expression (raw array) ; value: the array's element type `T`. The
   *  lowerer auto-wraps the lowered expression into an `ArrayIter(T)` struct
   *  literal so the receiving slot sees a proper iterator. Populated by
   *  `inferCall` / `checkLet` / `checkReturn` whenever the typecheck observes
   *  an array flowing into an `Iterator(T)` slot. */
  readonly arrayIterCoercions: ReadonlyMap<A.Expr, Type>;
  /** Operator overload resolutions. See `BinaryOpResolution`. */
  readonly binaryOpResolutions: ReadonlyMap<A.BinaryExpr, BinaryOpResolution>;
  /** `a[i]` read dispatch through `Index($I, $T)::at` when `a` isn't a
   *  built-in array. */
  readonly indexResolutions: ReadonlyMap<A.IndexExpr, IndexResolution>;
  /** `a[i] = v` write dispatch through `IndexSet($I, $T)::set_at`. Keyed by
   *  the LHS `IndexExpr` (which lives inside an `AssignStmt.target`). */
  readonly indexSetResolutions: ReadonlyMap<A.IndexExpr, IndexResolution>;
}

export interface TypedProject {
  readonly resolved: ResolvedProject;
  readonly modules: ReadonlyMap<string, TypedProgram>;
}
