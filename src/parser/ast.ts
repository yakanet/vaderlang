import type { Span } from "../diagnostics/diagnostic.ts";

// ============================================================================
// Top-level
// ============================================================================

export interface Program {
  readonly kind: "Program";
  readonly file: string;
  readonly span: Span;
  readonly decls: readonly Decl[];
}

// ============================================================================
// Declarations
// ============================================================================

export type Decl =
  | ImportDecl
  | FnDecl
  | StructDecl
  | EnumDecl
  | TraitDecl
  | ImplDecl
  | TypeAliasDecl
  | ConstDecl
  | AssertDecl;

export interface ImportDecl {
  readonly kind: "ImportDecl";
  readonly span: Span;
  readonly path: string;
  readonly binding: ImportBinding;
  readonly decorators: readonly Decorator[];
}

export type ImportBinding =
  | { readonly kind: "namespace" }
  | { readonly kind: "alias"; readonly alias: string }
  | { readonly kind: "destructure"; readonly names: readonly ImportName[] };

export interface ImportName {
  readonly name: string;
  readonly alias: string | null;
  readonly span: Span;
}

export interface FnDecl {
  readonly kind: "FnDecl";
  readonly span: Span;
  /** Filled by the parser, but the resolver overwrites it for `samSynthetic`
   *  FnDecls (it copies the unique trait method's name). After resolver, all
   *  FnDecls have their final name. */
  name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly typeParams: readonly TypeParam[];
  /** Same story as `name`/`returnType` — the parser leaves an empty array on
   *  `samSynthetic` FnDecls; the resolver materialises the params from the
   *  trait method's signature before the body is walked. */
  params: readonly FnParam[];
  returnType: TypeExpr | null;
  readonly whereClauses: readonly WhereClause[];
  readonly body: BlockExpr | null;
  readonly decorators: readonly Decorator[];
  /** Marker for parser-fabricated FnDecls produced by the SAM impl sugar
   *  (`Type implements Trait -> expr` or `Type implements Trait { stmts }`).
   *  When set, `name`/`params`/`returnType` are placeholders until the
   *  resolver copies them from the trait's single method. */
  readonly samSynthetic?: true;
  /** True when the source used `name :: fn(params) = expr` (expression body,
   *  return type to be inferred). The body is normalised to a BlockExpr with
   *  `stmts: []` and the expr as `trailing`, but downstream phases need the
   *  flag to know they should infer the return type instead of defaulting to
   *  `void`. */
  readonly isExpressionBodied?: true;
}

export interface StructDecl {
  readonly kind: "StructDecl";
  readonly span: Span;
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly typeParams: readonly TypeParam[];
  readonly fields: readonly StructField[];
  readonly whereClauses: readonly WhereClause[];
  readonly decorators: readonly Decorator[];
}

export interface StructField {
  readonly span: Span;
  readonly name: string;
  readonly type: TypeExpr;
  readonly visibility: Visibility;
}

export interface EnumDecl {
  readonly kind: "EnumDecl";
  readonly span: Span;
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  /** Optional backing-type annotation : `enum(u8) { ... }`. `null` means
   *  default `i32`. Resolved to a primitive int by the typechecker. */
  readonly repr: TypeExpr | null;
  readonly variants: readonly EnumVariant[];
  readonly decorators: readonly Decorator[];
}

export interface EnumVariant {
  readonly span: Span;
  readonly name: string;
  /** Optional explicit value (`Up = 10`). `null` means "previous + 1" (or 0
   *  for the first variant). Resolved to a concrete index by the typechecker. */
  readonly value: bigint | null;
  readonly valueSpan: Span | null;
}

export interface TraitDecl {
  readonly kind: "TraitDecl";
  readonly span: Span;
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly typeParams: readonly TypeParam[];
  readonly members: readonly FnDecl[];
  readonly decorators: readonly Decorator[];
}

export interface ImplDecl {
  readonly kind: "ImplDecl";
  readonly span: Span;
  readonly forType: TypeExpr;
  readonly traitName: string;
  readonly traitNameSpan: Span;
  /** Type arguments to the trait — e.g. `[i32]` for `… implements Iterator(i32)`.
   *  Empty for non-generic trait references like `… implements Display`. */
  readonly traitArgs: readonly TypeExpr[];
  readonly members: readonly FnDecl[];
  readonly decorators: readonly Decorator[];
}

export interface TypeAliasDecl {
  readonly kind: "TypeAliasDecl";
  readonly span: Span;
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly typeParams: readonly TypeParam[];
  readonly aliased: TypeExpr;
  readonly decorators: readonly Decorator[];
}

export interface ConstDecl {
  readonly kind: "ConstDecl";
  readonly span: Span;
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly type: TypeExpr | null;
  readonly value: Expr;
  readonly decorators: readonly Decorator[];
}

/** `@assert(cond)` — top-level compile-time assertion. The condition is
 *  evaluated by the comptime VM ; the build fails with C4015 if the result
 *  is `false`. No runtime emission ; nothing left after the comptime stage.
 *  `decorators` is always empty (the `@assert` itself is not stored as a
 *  decorator on the resulting decl) but the field is present for uniform
 *  iteration with the rest of the `Decl` variants. */
export interface AssertDecl {
  readonly kind: "AssertDecl";
  readonly span: Span;
  readonly condition: Expr;
  readonly decorators: readonly Decorator[];
}

export type Visibility = "public" | "private";

export interface FnParam {
  readonly span: Span;
  readonly name: string;
  readonly type: TypeExpr | null;     // optional in lambdas
  readonly defaultValue: Expr | null;
  readonly variadic: boolean;
}

// ============================================================================
// Generics
// ============================================================================

export interface TypeParam {
  readonly span: Span;
  readonly name: string;
  // For struct heads: `(T: type)` ; for comptime values: `($N: i32)`.
  readonly bound: TypeExpr | null;
  readonly isComptimeValue: boolean;  // true when introduced as `$N: <type>`
}

export interface WhereClause {
  readonly span: Span;
  readonly typeName: string;
  readonly traitName: string;
}

// ============================================================================
// Decorators
// ============================================================================

export interface Decorator {
  readonly span: Span;
  readonly name: string;
  readonly args: readonly Expr[];
}

// ============================================================================
// Statements
// ============================================================================

export type Stmt =
  | LetStmt
  | AssignStmt
  | ExprStmt
  | ReturnStmt
  | ForStmt
  | BreakStmt
  | ContinueStmt
  | DeferStmt;

export interface LetStmt {
  readonly kind: "LetStmt";
  readonly span: Span;
  readonly mutable: boolean;
  /** Binding pattern. For the simple case (`x := expr`) this is a single
   *  `SimpleBinding`; for tuple destructuring (`[a, b] := expr`) this is a
   *  `TupleBinding` whose leaves are `SimpleBinding`/`WildcardBinding`. */
  readonly binding: LetBinding;
  readonly type: TypeExpr | null;
  readonly value: Expr;
}

/** Recursive let-binding tree. Leaves are `SimpleBinding` (introduces a name)
 *  or `WildcardBinding` (ignores the slot). `TupleBinding` matches tuple-typed
 *  values element-wise. */
export type LetBinding = SimpleBinding | TupleBinding | WildcardBinding;

export interface SimpleBinding {
  readonly kind: "SimpleBinding";
  readonly span: Span;
  readonly name: string;
  readonly nameSpan: Span;
}

export interface TupleBinding {
  readonly kind: "TupleBinding";
  readonly span: Span;
  readonly elements: readonly LetBinding[];
}

export interface WildcardBinding {
  readonly kind: "WildcardBinding";
  readonly span: Span;
}

/** Walk a let-binding and visit every leaf that introduces a name. Mirrors
 *  `forEachPatternBindingKey` for `match` patterns. */
export function forEachLetBindingLeaf(
  binding: LetBinding, visit: (leaf: SimpleBinding) => void,
): void {
  switch (binding.kind) {
    case "SimpleBinding":
      visit(binding);
      return;
    case "TupleBinding":
      for (const e of binding.elements) forEachLetBindingLeaf(e, visit);
      return;
    case "WildcardBinding":
      return;
  }
}

export interface AssignStmt {
  readonly kind: "AssignStmt";
  readonly span: Span;
  readonly target: Expr;
  readonly value: Expr;
}

export interface ExprStmt {
  readonly kind: "ExprStmt";
  readonly span: Span;
  readonly expr: Expr;
}

export interface ReturnStmt {
  readonly kind: "ReturnStmt";
  readonly span: Span;
  readonly value: Expr | null;
}

export interface ForStmt {
  readonly kind: "ForStmt";
  readonly span: Span;
  readonly label: string | null;
  readonly form: ForForm;
  readonly body: BlockExpr;
}

export type ForForm =
  | { readonly kind: "infinite" }
  | { readonly kind: "while"; readonly cond: Expr }
  | { readonly kind: "in"; readonly binding: string; readonly bindingSpan: Span; readonly iter: Expr };

export interface BreakStmt {
  readonly kind: "BreakStmt";
  readonly span: Span;
  readonly label: string | null;
}

export interface ContinueStmt {
  readonly kind: "ContinueStmt";
  readonly span: Span;
  readonly label: string | null;
}

export interface DeferStmt {
  readonly kind: "DeferStmt";
  readonly span: Span;
  readonly body: Stmt | BlockExpr;
}

// ============================================================================
// Expressions
// ============================================================================

export type Expr =
  | IntLitExpr
  | FloatLitExpr
  | BoolLitExpr
  | NullLitExpr
  | CharLitExpr
  | StringLitExpr
  | IdentExpr
  | CallExpr
  | FieldExpr
  | IndexExpr
  | UnaryExpr
  | BinaryExpr
  | IfExpr
  | MatchExpr
  | BlockExpr
  | LambdaExpr
  | StructLitExpr
  | SeqLitExpr
  | RangeExpr
  | TryExpr
  | CastExpr
  | GenericInstExpr
  | DotVariantExpr
  // Two type-only-meaningful shapes that have no value-level interpretation.
  // The parser produces them in value position too since 1.C (postfix `T[]`
  // and `fn(T) -> U` without body), so they appear as cases in the
  // value-expression switches — they're rejected by the typechecker.
  | ArrayTypeExpr
  | FnTypeExpr;

/** Guard for exhaustive switches on `Expr.kind` : the two type-only
 *  expression variants (`FnTypeExpr`, `ArrayTypeExpr`) carry a syntactic
 *  shape that has no meaning in value position. The parser may now produce
 *  them in value-position contexts (Layer 1.C absorbed `T[]` and `fn(T)->U`
 *  into the main Pratt parser), but the typechecker rejects them — so any
 *  pass running after typecheck (closures analysis, lower) treats reaching
 *  them here as an internal bug. */
export function unreachableTypeExprInValuePosition(
  e: ArrayTypeExpr | FnTypeExpr,
): never {
  throw new Error(
    `internal: TypeExpr variant '${e.kind}' encountered in value-expression position; ` +
    `the parser should not produce this here (Layer 3 fusion is type-level only for now)`,
  );
}

export interface IntLitExpr {
  readonly kind: "IntLitExpr";
  readonly span: Span;
  readonly value: bigint;
  readonly suffix: string | null;
}

export interface FloatLitExpr {
  readonly kind: "FloatLitExpr";
  readonly span: Span;
  readonly value: number;
  readonly suffix: string | null;
}

export interface BoolLitExpr {
  readonly kind: "BoolLitExpr";
  readonly span: Span;
  readonly value: boolean;
}

export interface NullLitExpr {
  readonly kind: "NullLitExpr";
  readonly span: Span;
}

export interface CharLitExpr {
  readonly kind: "CharLitExpr";
  readonly span: Span;
  readonly value: number;
}

export interface StringLitExpr {
  readonly kind: "StringLitExpr";
  readonly span: Span;
  readonly parts: readonly StringLitPart[];
}

export type StringLitPart =
  | { readonly kind: "text"; readonly value: string; readonly span: Span }
  | { readonly kind: "interp"; readonly expr: Expr; readonly span: Span };

/** Returns the static text of a StringLitExpr, or null if it contains interpolation. */
export function staticStringValue(expr: StringLitExpr): string | null {
  let out = "";
  for (const part of expr.parts) {
    if (part.kind !== "text") return null;
    out += part.value;
  }
  return out;
}

export interface IdentExpr {
  readonly kind: "IdentExpr";
  readonly span: Span;
  readonly name: string;
  /** Set when the source spelling was a leading-dot reference (`.Foo`)
   *  rather than a fully-qualified name. Resolution of such names defers
   *  to the surrounding context (typically the scrutinee of a `match`
   *  arm or the expected type of an expression). Plain global symbol
   *  lookup is skipped — the resolver leaves the type unresolved and
   *  the typechecker walks the contextual variant set instead.
   *  Prior to Layer 1.B, this field lived on the dedicated `NamedType`
   *  variant ; absorbing it into `IdentExpr` is the first concrete
   *  step of the AST fusion. */
  readonly implicitDot?: boolean;
  /** Set when the source spelling was `$Name` — a type-param introduction
   *  in a generic signature. Used by `collectTypeParams` to gather the
   *  type-param list at parse time, and by the resolver to permit silent
   *  unresolved-name behaviour (a `$T` whose `T` isn't yet declared as a
   *  type-param does not emit R2007 ; a regular `T` does). Subsequent
   *  references to the same param within the signature drop the flag —
   *  they're plain `IdentExpr` lookups against the introduced symbol.
   *  Prior to Layer 1.B.2, this distinction lived on the dedicated
   *  `TypeParamType` variant. */
  readonly isTypeParamIntro?: boolean;
}

export interface CallExpr {
  readonly kind: "CallExpr";
  readonly span: Span;
  readonly callee: Expr;
  readonly args: readonly CallArg[];
}

export interface CallArg {
  readonly span: Span;
  readonly name: string | null;       // null = positional, otherwise named (`name = expr`)
  readonly value: Expr;
  readonly spread: boolean;            // true for `...rest`
}

export interface FieldExpr {
  readonly kind: "FieldExpr";
  readonly span: Span;
  readonly target: Expr;
  readonly field: string;
  readonly fieldSpan: Span;
  /** True when the field was written as an integer literal (e.g. `t.0`).
   *  Used by the lowerer to map onto synthetic tuple fields `_0`, `_1`, ... */
  readonly isNumeric?: boolean;
}

export interface IndexExpr {
  readonly kind: "IndexExpr";
  readonly span: Span;
  readonly target: Expr;
  readonly index: Expr;
}

export type UnaryOp = "neg" | "not" | "bitnot";

export interface UnaryExpr {
  readonly kind: "UnaryExpr";
  readonly span: Span;
  readonly op: UnaryOp;
  readonly operand: Expr;
}

export type BinaryOp =
  | "add" | "sub" | "mul" | "div" | "mod"
  | "shl" | "shr" | "bitand" | "bitor" | "bitxor"
  | "and" | "or"
  | "eq" | "neq" | "lt" | "lte" | "gt" | "gte"
  | "is" | "in" | "not_in";

export interface BinaryExpr {
  readonly kind: "BinaryExpr";
  readonly span: Span;
  readonly op: BinaryOp;
  readonly left: Expr;
  readonly right: Expr;
}

export interface IfExpr {
  readonly kind: "IfExpr";
  readonly span: Span;
  readonly cond: Expr;
  readonly then: BlockExpr;
  readonly else: IfExpr | BlockExpr | null;
}

export interface MatchExpr {
  readonly kind: "MatchExpr";
  readonly span: Span;
  readonly scrutinee: Expr;
  readonly arms: readonly MatchArm[];
  /** `@partial match x { … }` opts out of exhaustiveness checking — no
   *  T3013 fires for missing variants. Optional so the regular form
   *  dumps as before (the field is absent rather than `false`). */
  readonly partial?: true;
}

export interface MatchArm {
  readonly span: Span;
  readonly pattern: Pattern;
  readonly guard: Expr | null;
  readonly body: Expr;
}

export interface BlockExpr {
  readonly kind: "BlockExpr";
  readonly span: Span;
  readonly stmts: readonly Stmt[];
  readonly trailing: Expr | null;       // implicit return value (Rust-style)
}

export interface LambdaExpr {
  readonly kind: "LambdaExpr";
  readonly span: Span;
  readonly params: readonly FnParam[];
  readonly returnType: TypeExpr | null;
  readonly body: BlockExpr;
}

export interface StructLitExpr {
  readonly kind: "StructLitExpr";
  readonly span: Span;
  readonly typeName: TypeExpr;
  readonly fields: readonly StructLitField[];
}

export interface StructLitField {
  readonly span: Span;
  readonly name: string;
  readonly nameSpan: Span;
  readonly value: Expr;
}

/** Bracketed literal `[e1, e2, ...]`. The parser does not commit to "array"
 *  vs "tuple" — the typechecker decides via contextual disambiguation:
 *  when an annotation expects a tuple, it's a tuple ; when an annotation
 *  expects an array, it's an array ; without annotation, all-same-type
 *  unifies to an array, otherwise it's a tuple.
 *  Since Layer 1.B.3 the same shape carries the *type-level* tuple
 *  `[T1, T2, ...]` too (formerly the dedicated `TupleTypeExpr` variant).
 *  The dispatch is positional — `SeqLitExpr` in a value slot is a tuple
 *  literal ; in a type slot it lowers to a tuple type. */
export interface SeqLitExpr {
  readonly kind: "SeqLitExpr";
  readonly span: Span;
  readonly elements: readonly Expr[];
}

export interface RangeExpr {
  readonly kind: "RangeExpr";
  readonly span: Span;
  readonly inclusive: boolean;
  readonly lower: Expr;
  readonly upper: Expr;
}

export interface TryExpr {
  readonly kind: "TryExpr";
  readonly span: Span;
  readonly inner: Expr;
}

export interface CastExpr {
  readonly kind: "CastExpr";
  readonly span: Span;
  readonly target: TypeExpr;
  readonly value: Expr;
}

export interface GenericInstExpr {
  readonly kind: "GenericInstExpr";
  readonly span: Span;
  readonly callee: Expr;
  readonly typeArgs: readonly TypeExpr[];
}

/** `.Variant` dot-shorthand — target enum type inferred from context by the type-checker. */
export interface DotVariantExpr {
  readonly kind: "DotVariantExpr";
  readonly span: Span;
  readonly variant: string;
  readonly variantSpan: Span;
}

// ============================================================================
// Patterns (for `match`)
// ============================================================================

export type Pattern =
  | IsPattern
  | StructPattern
  | TuplePattern
  | WildcardPattern
  | BindingPattern
  | EnumVariantPattern;

export interface IsPattern {
  readonly kind: "IsPattern";
  readonly span: Span;
  readonly type: TypeExpr;
  readonly inner: Pattern | null;       // optional: `is Point { ... }`
  readonly bindAs: string | null;       // optional: `is i32 as n`
}

export interface StructPattern {
  readonly kind: "StructPattern";
  readonly span: Span;
  readonly fields: readonly StructPatternField[];
}

/** Tuple destructure pattern `[p1, p2, ...]`. Element-wise sub-patterns. */
export interface TuplePattern {
  readonly kind: "TuplePattern";
  readonly span: Span;
  readonly elements: readonly Pattern[];
}

export interface StructPatternField {
  readonly span: Span;
  readonly name: string;
  readonly nameSpan: Span;
  readonly value: PatternFieldValue;
}

export type PatternFieldValue =
  | { readonly kind: "binding"; readonly name: string; readonly span: Span }
  | { readonly kind: "literal"; readonly value: Expr };

export interface WildcardPattern {
  readonly kind: "WildcardPattern";
  readonly span: Span;
}

export interface BindingPattern {
  readonly kind: "BindingPattern";
  readonly span: Span;
  readonly name: string;
}

/** `.Variant` arm in a match on an enum scrutinee. */
export interface EnumVariantPattern {
  readonly kind: "EnumVariantPattern";
  readonly span: Span;
  readonly variant: string;
}

/** AST nodes that carry a pattern binding — the resolver maps each to a
 *  `Symbol` in `ResolvedProgram.patternBindings`, and downstream passes
 *  iterate the same set via `forEachPatternBindingKey`. */
export type PatternBindingKey = IsPattern | BindingPattern | StructPatternField;

/** Visit every binding-introducing site in a pattern, in source order.
 *  `IsPattern` participates only when its `bindAs` is set; `StructPattern`
 *  participates per-field (only for `binding` field shapes); nested
 *  `IsPattern.inner` recurses. Wildcard / EnumVariant patterns introduce no
 *  bindings and are skipped. */
export function forEachPatternBindingKey(
  pat: Pattern, visit: (key: PatternBindingKey) => void,
): void {
  switch (pat.kind) {
    case "IsPattern":
      if (pat.bindAs !== null) visit(pat);
      if (pat.inner !== null) forEachPatternBindingKey(pat.inner, visit);
      return;
    case "StructPattern":
      for (const f of pat.fields) {
        if (f.value.kind === "binding") visit(f);
      }
      return;
    case "TuplePattern":
      for (const e of pat.elements) forEachPatternBindingKey(e, visit);
      return;
    case "BindingPattern":
      visit(pat);
      return;
    case "WildcardPattern":
    case "EnumVariantPattern":
      return;
  }
}

// ============================================================================
// Type expressions
// ============================================================================

/** Since Layer 1.D, `TypeExpr` is an alias for `Expr` — the AST has a
 *  single expression family, and what counts as a « type expression »
 *  is determined by *position* (the typechecker demanding a value of
 *  static type `type`) rather than by AST shape. The alias is kept to
 *  preserve the documentary intent at slot declarations (e.g. a
 *  `StructField.type: TypeExpr` reads as « type-shaped expression »
 *  even though the type system no longer enforces it). The typechecker
 *  rejects non-type-shaped expressions in type-demanding positions. */
export type TypeExpr = Expr;

/** Walk a left-associative `bitor` chain and return its leaves in source order.
 *  Used by Layer 1.B.5 consumers (resolver, typechecker, parser walker) that
 *  need the flat list of union variants from a `T | U | V` expression now
 *  parsed as `BinaryExpr(bitor, BinaryExpr(bitor, T, U), V)`. Non-bitor
 *  expressions are returned as a single-element list. */
export function collectUnionVariants(e: Expr): readonly Expr[] {
  if (e.kind === "BinaryExpr" && e.op === "bitor") {
    return [...collectUnionVariants(e.left), ...collectUnionVariants(e.right)];
  }
  return [e];
}

export interface FnTypeExpr {
  readonly kind: "FnTypeExpr";
  readonly span: Span;
  readonly params: readonly TypeExpr[];
  readonly returnType: TypeExpr | null;
}

export interface ArrayTypeExpr {
  readonly kind: "ArrayTypeExpr";
  readonly span: Span;
  readonly element: TypeExpr;
}

