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
  | TraitDecl
  | ImplDecl
  | TypeAliasDecl
  | ConstDecl;

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
  readonly name: string;
  readonly nameSpan: Span;
  readonly visibility: Visibility;
  readonly typeParams: readonly TypeParam[];
  readonly params: readonly FnParam[];
  readonly returnType: TypeExpr | null;
  readonly whereClauses: readonly WhereClause[];
  readonly body: BlockExpr | null;
  readonly decorators: readonly Decorator[];
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
  readonly name: string;
  readonly nameSpan: Span;
  readonly type: TypeExpr | null;
  readonly value: Expr;
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
  | ArrayLitExpr
  | RangeExpr
  | TryExpr
  | CastExpr
  | GenericInstExpr;

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
  | "is";

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

export interface ArrayLitExpr {
  readonly kind: "ArrayLitExpr";
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

// ============================================================================
// Patterns (for `match`)
// ============================================================================

export type Pattern =
  | IsPattern
  | StructPattern
  | WildcardPattern
  | BindingPattern;

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

// ============================================================================
// Type expressions
// ============================================================================

export type TypeExpr =
  | NamedType
  | UnionType
  | FnTypeExpr
  | ArrayTypeExpr
  | GenericInstType
  | TypeParamType;

export interface NamedType {
  readonly kind: "NamedType";
  readonly span: Span;
  readonly name: string;
}

export interface UnionType {
  readonly kind: "UnionType";
  readonly span: Span;
  readonly variants: readonly TypeExpr[];
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

export interface GenericInstType {
  readonly kind: "GenericInstType";
  readonly span: Span;
  readonly base: NamedType;
  readonly args: readonly TypeExpr[];
}

export interface TypeParamType {
  // `$T` introduced inline in a function signature
  readonly kind: "TypeParamType";
  readonly span: Span;
  readonly name: string;
}
