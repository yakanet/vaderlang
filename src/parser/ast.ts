import type { Span } from "../diagnostics/diagnostic.ts";

// Sentinel id used at parser construction time, before `assignNodeIds`
// (`src/parser/assign-ids.ts`) walks the tree and replaces each node's id
// with a fresh unique value (starting from 1). After `parse()` returns,
// no node carries this value. Matched on the Vader self-host side as
// `UNASSIGNED_NODE_ID :: usize(0)` so the construct/walk pattern ports
// 1:1.
export const UNASSIGNED_NODE_ID = 0;

// Base shape shared by every named AST interface. `id` is the stable key
// for `Map<number, X>` side-tables in the resolver, typechecker, and later
// phases. Construction sites pass `id: UNASSIGNED_NODE_ID`; the post-parse
// walker overwrites with a real id (≥ 1) before any consumer reads it.
// Inline node-shaped objects (a few discriminated-union parts like
// `StringLitPart`) declare `id` directly on each variant since they don't
// extend `AstNode`.
export interface AstNode { readonly id: number; readonly span: Span; }

// ============================================================================
// Top-level
// ============================================================================

export interface Program extends AstNode {
  readonly kind: "Program";
  readonly file: string;
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

export interface ImportDecl extends AstNode {
  readonly kind: "ImportDecl";
  readonly path: string;
  readonly binding: ImportBinding;
  readonly decorators: readonly Decorator[];
}

export type ImportBinding =
  | { readonly kind: "namespace" }
  | { readonly kind: "alias"; readonly alias: string }
  | { readonly kind: "destructure"; readonly names: readonly ImportName[] };

export interface ImportName extends AstNode {
  readonly name: string;
  readonly alias: string | null;
}

export interface FnDecl extends AstNode {
  readonly kind: "FnDecl";
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

export interface StructDecl extends AstNode {
  readonly kind: "StructDecl";
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly typeParams: readonly TypeParam[];
  readonly fields: readonly StructField[];
  readonly decorators: readonly Decorator[];
}

export interface StructField extends AstNode {
  readonly name: string;
  readonly type: TypeExpr;
  readonly visibility: Visibility;
  /** Optional default value used when a struct literal omits this field.
   *  Re-lowered at every literal site (comptime-folding is an optimisation,
   *  not a correctness requirement). */
  readonly default: Expr | null;
}

export interface EnumDecl extends AstNode {
  readonly kind: "EnumDecl";
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  /** Optional backing-type annotation : `enum(u8) { ... }`. `null` means
   *  default `i32`. Resolved to a primitive int by the typechecker. */
  readonly repr: TypeExpr | null;
  readonly variants: readonly EnumVariant[];
  readonly decorators: readonly Decorator[];
}

export interface EnumVariant extends AstNode {
  readonly name: string;
  /** Optional explicit value (`Up = 10`). `null` means "previous + 1" (or 0
   *  for the first variant). Resolved to a concrete index by the typechecker. */
  readonly value: bigint | null;
  readonly valueSpan: Span | null;
}

export interface TraitDecl extends AstNode {
  readonly kind: "TraitDecl";
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly typeParams: readonly TypeParam[];
  /** Trait composition (Layer 7c) — when set, this trait *requires* the
   *  composed traits in addition to (or instead of) declaring its own
   *  methods. Two surface forms produce this :
   *    `trait Foo[T] = A & B & C`        (alias form, members is `[]`)
   *    `trait Foo[T] : A & B { ... }`    (with own methods)
   *  The composition expression is parsed as a type expression, typically
   *  a `BinaryExpr(bitand)` chain over trait names, but a single trait
   *  reference is also valid (`trait Foo[T] : Bar { ... }`).
   *  TODO(layer-7e) : the field is captured here but no downstream pass
   *  consumes it yet — `T: Foo` bound checks don't transitively expand
   *  through `requires`. Wire this in when `where`-clause enforcement
   *  goes through `@satisfies`. */
  readonly requires: TypeExpr | null;
  readonly members: readonly FnDecl[];
  readonly decorators: readonly Decorator[];
}

export interface ImplDecl extends AstNode {
  readonly kind: "ImplDecl";
  /** Optional bracketed type-param prefix for bounded generic impls —
   *  e.g. `[T: Add & Comparable] Range[T] implements Iterator[T] { ... }`.
   *  These are *the impl's own* type-params, with bounds local to this block.
   *  Distinct from type-args appearing inside `forType` / `traitArgs` (which
   *  *use* these names). Empty when the impl is non-generic or inherits its
   *  type-params transparently from the struct (legacy form). */
  readonly typeParams: readonly TypeParam[];
  readonly forType: TypeExpr;
  readonly traitName: string;
  readonly traitNameSpan: Span;
  /** Type arguments to the trait — e.g. `[i32]` for `… implements Iterator(i32)`.
   *  Empty for non-generic trait references like `… implements Display`. */
  readonly traitArgs: readonly TypeExpr[];
  readonly members: readonly FnDecl[];
  readonly decorators: readonly Decorator[];
}

export interface TypeAliasDecl extends AstNode {
  readonly kind: "TypeAliasDecl";
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly typeParams: readonly TypeParam[];
  readonly aliased: TypeExpr;
  readonly decorators: readonly Decorator[];
}

export interface ConstDecl extends AstNode {
  readonly kind: "ConstDecl";
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly type: TypeExpr | null;
  readonly value: Expr;
  readonly decorators: readonly Decorator[];
}

/** `@assert(cond)` or `@assert(cond, "message")` — top-level compile-time
 *  assertion. The condition is evaluated by the comptime VM ; the build
 *  fails with C4015 if the result is `false`. The optional second argument
 *  must be a static string literal (no interpolation) ; when present, it is
 *  appended to the C4015 diagnostic so the failure surfaces meaningful
 *  context to the reader.
 *  No runtime emission ; nothing left after the comptime stage.
 *  `decorators` is always empty (the `@assert` itself is not stored as a
 *  decorator on the resulting decl) but the field is present for uniform
 *  iteration with the rest of the `Decl` variants. */
export interface AssertDecl extends AstNode {
  readonly kind: "AssertDecl";
  readonly condition: Expr;
  readonly message: string | null;
  readonly decorators: readonly Decorator[];
}

export type Visibility = "public" | "private";

export interface FnParam extends AstNode {
  readonly name: string;
  readonly type: TypeExpr | null;     // optional in lambdas
  readonly defaultValue: Expr | null;
  readonly variadic: boolean;
}

// ============================================================================
// Generics
// ============================================================================

export interface TypeParam extends AstNode {
  readonly name: string;
  // For struct heads: `(T: type)` ; for comptime values: `($N: i32)`.
  readonly bound: TypeExpr | null;
  readonly isComptimeValue: boolean;  // true when introduced as `$N: <type>`
}

// ============================================================================
// Decorators
// ============================================================================

export interface Decorator extends AstNode {
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

export interface LetStmt extends AstNode {
  readonly kind: "LetStmt";
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
export type LetBinding = SimpleBinding | TupleBinding | WildcardBinding | RestBinding;

export interface SimpleBinding extends AstNode {
  readonly kind: "SimpleBinding";
  readonly name: string;
  readonly nameSpan: Span;
}

export interface TupleBinding extends AstNode {
  readonly kind: "TupleBinding";
  readonly elements: readonly LetBinding[];
}

export interface WildcardBinding extends AstNode {
  readonly kind: "WildcardBinding";
}

/** `...name` rest-element of a bracketed binding — collects the tail into
 *  a fresh array. Only valid as the last element of an array-typed source. */
export interface RestBinding extends AstNode {
  readonly kind: "RestBinding";
  readonly name: string;
  readonly nameSpan: Span;
}

/** Visit every leaf that introduces a name. Leaves are passed by their
 *  original AST identity so callers can key into `resolved.locals`. */
export function forEachLetBindingLeaf(
  binding: LetBinding, visit: (leaf: SimpleBinding | RestBinding) => void,
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
    case "RestBinding":
      visit(binding);
      return;
  }
}

export interface AssignStmt extends AstNode {
  readonly kind: "AssignStmt";
  readonly target: Expr;
  readonly value: Expr;
}

export interface ExprStmt extends AstNode {
  readonly kind: "ExprStmt";
  readonly expr: Expr;
}

export interface ReturnStmt extends AstNode {
  readonly kind: "ReturnStmt";
  readonly value: Expr | null;
}

export interface ForStmt extends AstNode {
  readonly kind: "ForStmt";
  readonly label: string | null;
  readonly form: ForForm;
  readonly body: BlockExpr;
}

export type ForForm =
  | { readonly kind: "infinite" }
  | { readonly kind: "while"; readonly cond: Expr }
  | { readonly kind: "in"; readonly binding: string; readonly bindingSpan: Span; readonly iter: Expr };

export interface BreakStmt extends AstNode {
  readonly kind: "BreakStmt";
  readonly label: string | null;
}

export interface ContinueStmt extends AstNode {
  readonly kind: "ContinueStmt";
  readonly label: string | null;
}

export interface DeferStmt extends AstNode {
  readonly kind: "DeferStmt";
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
  | IntrinsicCallExpr
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

export interface IntLitExpr extends AstNode {
  readonly kind: "IntLitExpr";
  readonly value: bigint;
  readonly suffix: string | null;
}

export interface FloatLitExpr extends AstNode {
  readonly kind: "FloatLitExpr";
  readonly value: number;
  readonly suffix: string | null;
}

export interface BoolLitExpr extends AstNode {
  readonly kind: "BoolLitExpr";
  readonly value: boolean;
}

export interface NullLitExpr extends AstNode {
  readonly kind: "NullLitExpr";
}

export interface CharLitExpr extends AstNode {
  readonly kind: "CharLitExpr";
  readonly value: number;
}

export interface StringLitExpr extends AstNode {
  readonly kind: "StringLitExpr";
  readonly parts: readonly StringLitPart[];
}

export type StringLitPart =
  | { readonly kind: "text"; readonly value: string; readonly span: Span; readonly id: number }
  | { readonly kind: "interp"; readonly expr: Expr; readonly span: Span; readonly id: number };

/** Returns the static text of a StringLitExpr, or null if it contains interpolation. */
export function staticStringValue(expr: StringLitExpr): string | null {
  let out = "";
  for (const part of expr.parts) {
    if (part.kind !== "text") return null;
    out += part.value;
  }
  return out;
}

export interface IdentExpr extends AstNode {
  readonly kind: "IdentExpr";
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

export interface CallExpr extends AstNode {
  readonly kind: "CallExpr";
  readonly callee: Expr;
  readonly args: readonly CallArg[];
}

export interface CallArg extends AstNode {
  readonly name: string | null;       // null = positional, otherwise named (`name = expr`)
  readonly value: Expr;
  readonly spread: boolean;            // true for `...rest`
}

export interface FieldExpr extends AstNode {
  readonly kind: "FieldExpr";
  readonly target: Expr;
  readonly field: string;
  readonly fieldSpan: Span;
  /** True when the field was written as an integer literal (e.g. `t.0`).
   *  Used by the lowerer to map onto synthetic tuple fields `_0`, `_1`, ... */
  readonly isNumeric?: boolean;
}

export interface IndexExpr extends AstNode {
  readonly kind: "IndexExpr";
  readonly target: Expr;
  readonly index: Expr;
}

export type UnaryOp = "neg" | "not" | "bitnot";

export interface UnaryExpr extends AstNode {
  readonly kind: "UnaryExpr";
  readonly op: UnaryOp;
  readonly operand: Expr;
}

export type BinaryOp =
  | "add" | "sub" | "mul" | "div" | "mod"
  | "shl" | "shr" | "bitand" | "bitor" | "bitxor"
  | "and" | "or"
  | "eq" | "neq" | "lt" | "lte" | "gt" | "gte"
  | "is" | "in" | "not_in";

export interface BinaryExpr extends AstNode {
  readonly kind: "BinaryExpr";
  readonly op: BinaryOp;
  readonly left: Expr;
  readonly right: Expr;
}

export interface IfExpr extends AstNode {
  readonly kind: "IfExpr";
  readonly cond: Expr;
  readonly then: BlockExpr;
  readonly else: IfExpr | BlockExpr | null;
}

export interface MatchExpr extends AstNode {
  readonly kind: "MatchExpr";
  readonly scrutinee: Expr;
  readonly arms: readonly MatchArm[];
  /** `@partial match x { … }` opts out of exhaustiveness checking — no
   *  T3013 fires for missing variants. Optional so the regular form
   *  dumps as before (the field is absent rather than `false`). */
  readonly partial?: true;
}

export interface MatchArm extends AstNode {
  readonly pattern: Pattern;
  readonly guard: Expr | null;
  readonly body: Expr;
}

export interface BlockExpr extends AstNode {
  readonly kind: "BlockExpr";
  readonly stmts: readonly Stmt[];
  readonly trailing: Expr | null;       // implicit return value (Rust-style)
}

export interface LambdaExpr extends AstNode {
  readonly kind: "LambdaExpr";
  readonly params: readonly FnParam[];
  readonly returnType: TypeExpr | null;
  readonly body: BlockExpr;
}

export interface StructLitExpr extends AstNode {
  readonly kind: "StructLitExpr";
  readonly typeName: TypeExpr;
  readonly items: readonly StructLitItem[];
}

export type StructLitItem = StructLitField | StructLitSpread;

export interface StructLitField extends AstNode {
  readonly kind: "field";
  readonly name: string;
  readonly nameSpan: Span;
  readonly value: Expr;
}

/** `...expr` clause in a struct literal — copies every field of `expr` into
 *  the literal, with subsequent named fields overriding the spread. */
export interface StructLitSpread extends AstNode {
  readonly kind: "spread";
  readonly expr: Expr;
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
export interface SeqLitExpr extends AstNode {
  readonly kind: "SeqLitExpr";
  readonly elements: readonly Expr[];
}

export interface RangeExpr extends AstNode {
  readonly kind: "RangeExpr";
  readonly inclusive: boolean;
  readonly lower: Expr;
  readonly upper: Expr;
}

export interface TryExpr extends AstNode {
  readonly kind: "TryExpr";
  readonly inner: Expr;
}

export interface CastExpr extends AstNode {
  readonly kind: "CastExpr";
  readonly target: TypeExpr;
  readonly value: Expr;
}

export interface GenericInstExpr extends AstNode {
  readonly kind: "GenericInstExpr";
  readonly callee: Expr;
  readonly typeArgs: readonly TypeExpr[];
}

/** Compiler-built reflection / introspection call : `@size_of(T)`,
 *  `@type_name(T)`, `@align_of(T)`, etc. (Layer 6 reflection surface,
 *  see DESIGN_TYPE_FIRST.md §12). The `name` is the intrinsic identifier
 *  *without* the leading `@` (`"size_of"`, `"type_name"`, …). The set of
 *  recognised names lives in `parser/intrinsics.ts` ; the parser only
 *  produces this node for known names — unknown `@name(...)` in expression
 *  position still raises P1014. Each intrinsic carries its own typing rules
 *  (input arity, type vs value position of args, return type) and folds to
 *  a constant in the lowering pass. */
export interface IntrinsicCallExpr extends AstNode {
  readonly kind: "IntrinsicCallExpr";
  readonly name: string;
  readonly nameSpan: Span;
  readonly args: readonly Expr[];
}

/** `.Variant` dot-shorthand — target enum type inferred from context by the type-checker. */
export interface DotVariantExpr extends AstNode {
  readonly kind: "DotVariantExpr";
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

export interface IsPattern extends AstNode {
  readonly kind: "IsPattern";
  readonly type: TypeExpr;
  readonly inner: Pattern | null;       // optional: `is Point { ... }`
  readonly bindAs: string | null;       // optional: `is i32 as n`
}

export interface StructPattern extends AstNode {
  readonly kind: "StructPattern";
  readonly fields: readonly StructPatternField[];
}

/** Tuple destructure pattern `[p1, p2, ...]`. Element-wise sub-patterns. */
export interface TuplePattern extends AstNode {
  readonly kind: "TuplePattern";
  readonly elements: readonly Pattern[];
}

export interface StructPatternField extends AstNode {
  readonly name: string;
  readonly nameSpan: Span;
  readonly value: PatternFieldValue;
}

export type PatternFieldValue =
  | { readonly kind: "binding"; readonly name: string; readonly span: Span; readonly id: number }
  | { readonly kind: "literal"; readonly value: Expr };

export interface WildcardPattern extends AstNode {
  readonly kind: "WildcardPattern";
}

export interface BindingPattern extends AstNode {
  readonly kind: "BindingPattern";
  readonly name: string;
}

/** `.Variant` arm in a match on an enum scrutinee. */
export interface EnumVariantPattern extends AstNode {
  readonly kind: "EnumVariantPattern";
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

export interface FnTypeExpr extends AstNode {
  readonly kind: "FnTypeExpr";
  readonly params: readonly TypeExpr[];
  readonly returnType: TypeExpr | null;
}

export interface ArrayTypeExpr extends AstNode {
  readonly kind: "ArrayTypeExpr";
  readonly element: TypeExpr;
}

