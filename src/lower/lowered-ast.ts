// Lowered AST — implements SPEC §2 "Lowered AST".

import type { Symbol } from "../resolver/symbol.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type { Type } from "../typecheck/types.ts";
import type { MonoEntry } from "../comptime/specialize.ts";

export interface LoweredProject {
  readonly modules: ReadonlyMap<string, LoweredModule>;
  /** Pre-flattened virtual-dispatch table source — one entry per
   *  `(trait, method, concrete struct, impl fn)`. The bytecode emitter walks
   *  these to populate `BytecodeModule.vtables`, translating `structType` to
   *  its type-table index and `fnSymbol` to its fn-table index. */
  readonly vtableEntries: readonly VtableEntry[];
}

export interface VtableEntry {
  readonly traitName: string;
  readonly methodName: string;
  readonly structType: Type;
  readonly fnSymbol: Symbol;
}

export interface LoweredModule {
  readonly moduleId: string;
  readonly displayPath: string;
  readonly decls: readonly LoweredDecl[];
}

export type LoweredDecl =
  | LoweredFnDecl
  | LoweredStructDecl
  | LoweredConstDecl;

export interface LoweredFnDecl {
  readonly kind: "LoweredFnDecl";
  readonly mangled: string;
  readonly params: readonly LoweredParam[];
  readonly returnType: Type;
  readonly body: LoweredBlock | null;     // null for @extern / signature-only fns
  readonly origin: MonoEntry;
}

export interface LoweredStructDecl {
  readonly kind: "LoweredStructDecl";
  readonly mangled: string;
  readonly fields: readonly LoweredStructField[];
  readonly origin: MonoEntry;
}

export interface LoweredConstDecl {
  readonly kind: "LoweredConstDecl";
  readonly mangled: string;
  readonly type: Type;
  readonly value: LoweredExpr;
  readonly origin: MonoEntry;
}

export interface LoweredStructField {
  readonly name: string;
  readonly type: Type;
}

export interface LoweredParam {
  readonly name: string;
  readonly symbol: Symbol;
  readonly type: Type;
}

// =========================================================================
// Statements
// =========================================================================

export type LoweredStmt =
  | LoweredLet
  | LoweredAssign
  | LoweredCellSet
  | LoweredExprStmt
  | LoweredReturn
  | LoweredLoop
  | LoweredBreak
  | LoweredContinue;

export interface LoweredLet {
  readonly kind: "LoweredLet";
  readonly span: Span;
  readonly name: string;
  readonly symbol: Symbol;
  readonly type: Type;
  readonly value: LoweredExpr;
}

export interface LoweredAssign {
  readonly kind: "LoweredAssign";
  readonly span: Span;
  readonly target: LoweredExpr;
  readonly value: LoweredExpr;
}

/** Update the slot of a closure cell (a heap-allocated single-slot box used
 *  to give captured locals by-reference closure semantics). `target` resolves
 *  to a cell ref; `value` is the new contents (statically typed `valueType`). */
export interface LoweredCellSet {
  readonly kind: "LoweredCellSet";
  readonly span: Span;
  readonly target: LoweredExpr;
  readonly value: LoweredExpr;
  readonly valueType: Type;
}

export interface LoweredExprStmt {
  readonly kind: "LoweredExprStmt";
  readonly span: Span;
  readonly expr: LoweredExpr;
}

export interface LoweredReturn {
  readonly kind: "LoweredReturn";
  readonly span: Span;
  readonly value: LoweredExpr | null;
}

/** All `for` forms collapse to a Loop after lowering. `for x in iter` lowers
 *  to a Loop body that pulls the next item — but in MVP we keep this as a
 *  no-op placeholder; iteration is wired up alongside generic-fn dispatch. */
export interface LoweredLoop {
  readonly kind: "LoweredLoop";
  readonly span: Span;
  readonly label: string | null;
  readonly cond: LoweredExpr | null;     // null for infinite loops; non-null for `while`-style
  readonly body: LoweredBlock;
}

export interface LoweredBreak {
  readonly kind: "LoweredBreak";
  readonly span: Span;
  readonly label: string | null;
}

export interface LoweredContinue {
  readonly kind: "LoweredContinue";
  readonly span: Span;
  readonly label: string | null;
}

// =========================================================================
// Expressions
// =========================================================================

export type LoweredExpr =
  | LoweredIntLit
  | LoweredFloatLit
  | LoweredBoolLit
  | LoweredNullLit
  | LoweredCharLit
  | LoweredStringLit
  | LoweredIdent
  | LoweredCall
  | LoweredVirtualCall
  | LoweredFieldAccess
  | LoweredIndex
  | LoweredUnary
  | LoweredBinary
  | LoweredIf
  | LoweredBlock
  | LoweredStructLit
  | LoweredArrayLit
  | LoweredCast
  | LoweredTypeCheck
  | LoweredUnreachable
  | LoweredIntrinsicCall
  | LoweredArrayLen
  | LoweredArrayPush
  | LoweredCellNew
  | LoweredCellGet
  | LoweredMakeClosure;

export interface LoweredIntLit {
  readonly kind: "LoweredIntLit";
  readonly span: Span;
  readonly type: Type;
  readonly value: bigint;
}
export interface LoweredFloatLit {
  readonly kind: "LoweredFloatLit";
  readonly span: Span;
  readonly type: Type;
  readonly value: number;
}
export interface LoweredBoolLit {
  readonly kind: "LoweredBoolLit";
  readonly span: Span;
  readonly type: Type;
  readonly value: boolean;
}
export interface LoweredNullLit {
  readonly kind: "LoweredNullLit";
  readonly span: Span;
  readonly type: Type;
}
export interface LoweredCharLit {
  readonly kind: "LoweredCharLit";
  readonly span: Span;
  readonly type: Type;
  readonly value: number;
}
/** Pure-text string literal — no interpolation parts after lowering. */
export interface LoweredStringLit {
  readonly kind: "LoweredStringLit";
  readonly span: Span;
  readonly type: Type;
  readonly value: string;
}

export interface LoweredIdent {
  readonly kind: "LoweredIdent";
  readonly span: Span;
  readonly type: Type;
  readonly symbol: Symbol;
}

export interface LoweredCall {
  readonly kind: "LoweredCall";
  readonly span: Span;
  readonly type: Type;
  readonly callee: LoweredExpr;
  readonly args: readonly LoweredExpr[];
}

/** Virtual dispatch on a trait-typed receiver — the runtime indexes a
 *  per-(trait, method) vtable by the receiver's type tag to pick the impl
 *  fn. The bytecode emitter materialises the vtable from the impl registry
 *  + monomorphisation entries; the cascade-of-`is` pre-Sprint-3.12 form is
 *  gone. `traitName` and `method` together key the vtable. */
export interface LoweredVirtualCall {
  readonly kind: "LoweredVirtualCall";
  readonly span: Span;
  readonly type: Type;
  readonly traitName: string;
  readonly method: string;
  readonly receiver: LoweredExpr;
  readonly args: readonly LoweredExpr[];
}

export interface LoweredFieldAccess {
  readonly kind: "LoweredFieldAccess";
  readonly span: Span;
  readonly type: Type;
  readonly target: LoweredExpr;
  readonly field: string;
}

export interface LoweredIndex {
  readonly kind: "LoweredIndex";
  readonly span: Span;
  readonly type: Type;
  readonly target: LoweredExpr;
  readonly index: LoweredExpr;
}

export type LoweredUnaryOp = "neg" | "not" | "bitnot";
export interface LoweredUnary {
  readonly kind: "LoweredUnary";
  readonly span: Span;
  readonly type: Type;
  readonly op: LoweredUnaryOp;
  readonly operand: LoweredExpr;
}

export type LoweredBinaryOp =
  | "add" | "sub" | "mul" | "div" | "mod"
  | "shl" | "shr" | "bitand" | "bitor" | "bitxor"
  | "and" | "or"
  | "eq" | "neq" | "lt" | "lte" | "gt" | "gte";
export interface LoweredBinary {
  readonly kind: "LoweredBinary";
  readonly span: Span;
  readonly type: Type;
  readonly op: LoweredBinaryOp;
  readonly left: LoweredExpr;
  readonly right: LoweredExpr;
}

export interface LoweredIf {
  readonly kind: "LoweredIf";
  readonly span: Span;
  readonly type: Type;
  readonly cond: LoweredExpr;
  readonly then: LoweredBlock;
  readonly else: LoweredBlock | null;
}

/** Block — both a statement-position and an expression-position citizen. The
 *  trailing expr (if any) is the block's value; otherwise `void`. */
export interface LoweredBlock {
  readonly kind: "LoweredBlock";
  readonly span: Span;
  readonly type: Type;
  readonly stmts: readonly LoweredStmt[];
  readonly trailing: LoweredExpr | null;
}

export interface LoweredStructLit {
  readonly kind: "LoweredStructLit";
  readonly span: Span;
  readonly type: Type;
  readonly fields: readonly LoweredStructLitField[];
}
export interface LoweredStructLitField {
  readonly name: string;
  readonly value: LoweredExpr;
}

export interface LoweredArrayLit {
  readonly kind: "LoweredArrayLit";
  readonly span: Span;
  readonly type: Type;
  readonly elements: readonly LoweredExpr[];
}

/** Length of an array, exposed by the bytecode op `array.len`. The lowerer
 *  emits this when auto-wrapping `for x in arr` into an `ArrayIter(T)`
 *  literal — the `length` field needs the runtime length but Vader doesn't
 *  yet have a generic `len(arr)` fn. */
export interface LoweredArrayLen {
  readonly kind: "LoweredArrayLen";
  readonly span: Span;
  readonly type: Type;
  readonly target: LoweredExpr;
}

/** Push an element onto a mutable array. Type is always void. */
export interface LoweredArrayPush {
  readonly kind: "LoweredArrayPush";
  readonly span: Span;
  readonly type: Type;
  readonly target: LoweredExpr;
  readonly value: LoweredExpr;
}

export interface LoweredCast {
  readonly kind: "LoweredCast";
  readonly span: Span;
  readonly type: Type;
  readonly value: LoweredExpr;
}

/** Runtime tag check — tests whether a value of a union type is currently the
 *  given variant. Lowered from `match` arm patterns (`is T`). */
export interface LoweredTypeCheck {
  readonly kind: "LoweredTypeCheck";
  readonly span: Span;
  readonly type: Type;            // always `bool`
  readonly value: LoweredExpr;
  readonly checkType: Type;       // the variant being tested
}

/** Marker for code paths that can't actually be reached (e.g. the trailing
 *  else of an exhaustive match). The bytecode emitter lowers this to a panic
 *  if reached at runtime. The `type` field carries the surrounding context's
 *  expected type so the IR stays well-typed. */
export interface LoweredUnreachable {
  readonly kind: "LoweredUnreachable";
  readonly span: Span;
  readonly type: Type;
  readonly reason: string;
}

/**
 * Static-named compiler/runtime intrinsic. Used for the desugared forms that
 * don't have a user-visible call form — currently:
 *
 *   - `builder.new`            : ()                 -> StringBuilder
 *   - `builder.append_str`     : (StringBuilder, string)              -> void
 *   - `builder.append_display` : (StringBuilder, T) -> void  (for each T : Display)
 *   - `builder.finish`         : (StringBuilder)    -> string
 *
 * The trailing `display_for` field on `append_display` records which impl's
 * `.to_string` to call so the bytecode emitter can hook it up to the right
 * symbol at codegen time.
 */
export interface LoweredIntrinsicCall {
  readonly kind: "LoweredIntrinsicCall";
  readonly span: Span;
  readonly type: Type;
  readonly name: IntrinsicName;
  readonly args: readonly LoweredExpr[];
  /** When `name === "builder.append_display"`, the static type of the value being shown. */
  readonly displayFor?: Type;
}

/** Allocate a new closure cell holding `value`. Cells are 1-slot heap objects
 *  used to give captured locals by-reference closure semantics — multiple
 *  closures referencing the same captured local share the same cell.
 *  `type` is the cell's "outer" type (an opaque ref); `valueType` is the
 *  statically-known type of the slot contents (used by the bytecode emit to
 *  pick the right box/unbox path). */
export interface LoweredCellNew {
  readonly kind: "LoweredCellNew";
  readonly span: Span;
  readonly type: Type;
  readonly value: LoweredExpr;
  readonly valueType: Type;
}

/** Read the slot of a closure cell. `target` resolves to a cell ref; the
 *  result has type `valueType`. */
export interface LoweredCellGet {
  readonly kind: "LoweredCellGet";
  readonly span: Span;
  readonly type: Type;
  readonly target: LoweredExpr;
  readonly valueType: Type;
}

/** Pack an env struct + a lifted top-level fn into a closure value. The env
 *  expression (typically a `LoweredStructLit` for the synthesized env type)
 *  carries the cell references the closure body needs. The bytecode emit
 *  resolves `fnSymbol` to a function index and emits `make_closure`. */
export interface LoweredMakeClosure {
  readonly kind: "LoweredMakeClosure";
  readonly span: Span;
  readonly type: Type;            // the closure's fn type
  readonly fnSymbol: Symbol;      // synthesised symbol for the lifted fn
  readonly env: LoweredExpr;      // produces the env struct (boxed)
}

export const INTRINSICS = {
  builderNew:            "builder.new",
  builderAppendStr:      "builder.append_str",
  builderAppendDisplay:  "builder.append_display",
  builderFinish:         "builder.finish",
} as const;

export type IntrinsicName = typeof INTRINSICS[keyof typeof INTRINSICS];
