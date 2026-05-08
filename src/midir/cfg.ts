// Mid-IR (CFG) — data types only. See `docs/MID_IR_DESIGN.md` for the
// design rationale and the multi-phase plan.
//
// Phase 1 (this file) defines the shape; no converter, no emitter, no
// pipeline integration. Subsequent phases:
//   - Phase 2: LoweredAST → CFG converter + CFG → bytecode (structuring).
//   - Phase 3: DCE on the CFG (per-store liveness, dead local elimination).
//   - Phase 4: SSA conversion (rename to value names, insert phis).
//   - Phase 5: Escape analysis on SSA (stack-allocate non-escaping).
//   - Phase 6: Drop the legacy LoweredAST → bytecode path.

import type { Span } from "../diagnostics/diagnostic.ts";
import type * as L from "../lower/lowered-ast.ts";
import type { MonoEntry } from "../monomorphize/index.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { Type } from "../typecheck/types.ts";

/** Index of a basic block within a function's `blocks` table. The entry
 *  block is always at index 0 by convention. */
export type BlockId = number;

/** Index of a local within a function's `locals` table. Locals are mutable
 *  named storage cells, like bytecode locals. SSA conversion (Phase 4)
 *  introduces a separate `ValueId` and renames reads/writes; for now,
 *  every instruction reads from / writes to a local. */
export type LocalId = number;

/** A function's CFG: the entry block, all blocks, all locals/params. */
export interface CFGFunction {
  readonly mangled: string;
  readonly params: readonly CFGParam[];
  readonly returnType: Type;
  readonly locals: readonly CFGLocal[];
  readonly blocks: readonly BasicBlock[];
  readonly entry: BlockId;            // canonically 0
  readonly origin: MonoEntry;         // mirrored from LoweredFnDecl.origin
}

export interface CFGParam {
  readonly name: string;
  readonly symbol: Symbol;
  readonly type: Type;
  /** The local slot the param's initial value is written to. The translator
   *  emits an implicit `Const`/`Param` write at fn entry; from there on,
   *  the param is just another local. */
  readonly local: LocalId;
}

export interface CFGLocal {
  readonly name: string;       // user-facing name when known; "$tmp_<n>" for synthesised
  readonly type: Type;
  /** Source-level symbol when the local corresponds to a user binding;
   *  null for compiler-synthesised tmp slots. */
  readonly symbol: Symbol | null;
}

/** Single-entry single-exit basic block. Control enters at instructions[0],
 *  flows linearly through, and leaves via the terminator. The terminator
 *  is the only point where `BlockId`s are referenced. */
export interface BasicBlock {
  readonly id: BlockId;
  readonly instructions: readonly Instruction[];
  readonly terminator: Terminator;
  readonly span: Span;          // representative span; per-instruction spans live on Instruction
}

// =========================================================================
// Instructions — three-address code, pre-SSA. Each instruction reads
// operand LocalIds and (when applicable) writes its result to `dst`.
// =========================================================================

export type Instruction =
  | InstrConst
  | InstrBinOp
  | InstrUnOp
  | InstrCall
  | InstrVirtualCall
  | InstrFieldGet
  | InstrFieldSet
  | InstrArrayGet
  | InstrArraySet
  | InstrArrayLen
  | InstrArrayPush
  | InstrStructNew
  | InstrArrayNew
  | InstrTypeCheck
  | InstrCast
  | InstrCellNew
  | InstrCellGet
  | InstrCellSet
  | InstrMakeClosure
  | InstrIntrinsic
  | InstrMove;

/** Common header — every instruction has a span for diagnostics. */
interface InstrBase {
  readonly span: Span;
}

export interface InstrConst extends InstrBase {
  readonly kind: "Const";
  readonly dst: LocalId;
  readonly value: ConstValue;
  readonly type: Type;
}

export interface InstrBinOp extends InstrBase {
  readonly kind: "BinOp";
  readonly dst: LocalId;
  readonly op: L.LoweredBinaryOp;
  readonly lhs: LocalId;
  readonly rhs: LocalId;
  readonly type: Type;
}

export interface InstrUnOp extends InstrBase {
  readonly kind: "UnOp";
  readonly dst: LocalId;
  readonly op: L.LoweredUnaryOp;
  readonly operand: LocalId;
  readonly type: Type;
}

/** Direct call — the callee is a known fn symbol. */
export interface InstrCall extends InstrBase {
  readonly kind: "Call";
  readonly dst: LocalId | null;       // null when the call returns void
  readonly callee: Symbol;
  readonly args: readonly LocalId[];
  readonly type: Type;
}

/** Trait-method virtual dispatch. Lowers to bytecode `virtual.call`. */
export interface InstrVirtualCall extends InstrBase {
  readonly kind: "VirtualCall";
  readonly dst: LocalId | null;
  readonly traitName: string;
  readonly method: string;
  readonly receiver: LocalId;
  readonly args: readonly LocalId[];
  readonly type: Type;
}

export interface InstrFieldGet extends InstrBase {
  readonly kind: "FieldGet";
  readonly dst: LocalId;
  readonly target: LocalId;
  readonly field: string;
  readonly type: Type;
}

export interface InstrFieldSet extends InstrBase {
  readonly kind: "FieldSet";
  readonly target: LocalId;
  readonly field: string;
  readonly value: LocalId;
}

export interface InstrArrayGet extends InstrBase {
  readonly kind: "ArrayGet";
  readonly dst: LocalId;
  readonly target: LocalId;
  readonly index: LocalId;
  readonly type: Type;
}

export interface InstrArraySet extends InstrBase {
  readonly kind: "ArraySet";
  readonly target: LocalId;
  readonly index: LocalId;
  readonly value: LocalId;
}

export interface InstrArrayLen extends InstrBase {
  readonly kind: "ArrayLen";
  readonly dst: LocalId;
  readonly target: LocalId;
}

export interface InstrArrayPush extends InstrBase {
  readonly kind: "ArrayPush";
  readonly target: LocalId;
  readonly value: LocalId;
}

export interface InstrStructNew extends InstrBase {
  readonly kind: "StructNew";
  readonly dst: LocalId;
  readonly type: Type;
  /** Per-field initialiser locals, in declaration order. */
  readonly fields: readonly LocalId[];
}

export interface InstrArrayNew extends InstrBase {
  readonly kind: "ArrayNew";
  readonly dst: LocalId;
  readonly type: Type;
  readonly length: number;
  readonly elements: readonly LocalId[];
}

/** Runtime tag check — `is X`. */
export interface InstrTypeCheck extends InstrBase {
  readonly kind: "TypeCheck";
  readonly dst: LocalId;
  readonly value: LocalId;
  readonly checkType: Type;
}

/** Static type cast — same as today's `LoweredCast`; emits a tag re-stamp
 *  or no-op depending on the source/target representation. */
export interface InstrCast extends InstrBase {
  readonly kind: "Cast";
  readonly dst: LocalId;
  readonly value: LocalId;
  readonly type: Type;
}

/** Allocate a heap closure cell holding `value`. */
export interface InstrCellNew extends InstrBase {
  readonly kind: "CellNew";
  readonly dst: LocalId;
  readonly value: LocalId;
  readonly valueType: Type;
}

export interface InstrCellGet extends InstrBase {
  readonly kind: "CellGet";
  readonly dst: LocalId;
  readonly cell: LocalId;
  readonly valueType: Type;
}

export interface InstrCellSet extends InstrBase {
  readonly kind: "CellSet";
  readonly cell: LocalId;
  readonly value: LocalId;
  readonly valueType: Type;
}

/** Allocate a closure value `{ fn, env }`. */
export interface InstrMakeClosure extends InstrBase {
  readonly kind: "MakeClosure";
  readonly dst: LocalId;
  readonly fnSymbol: Symbol;
  readonly env: LocalId;
  readonly type: Type;
}

/** Compiler/runtime intrinsic call (builder.new, builder.append_*, …). */
export interface InstrIntrinsic extends InstrBase {
  readonly kind: "Intrinsic";
  readonly dst: LocalId | null;
  readonly name: L.IntrinsicName;
  readonly args: readonly LocalId[];
  readonly displayFor?: Type;
}

/** Local-to-local copy. Surfaces in lowered constructs like
 *  `let x = y` where the RHS is already in a local — the converter
 *  emits a `Move` rather than synthesising a fresh tmp. SSA conversion
 *  (Phase 4) elides moves entirely (rename instead). */
export interface InstrMove extends InstrBase {
  readonly kind: "Move";
  readonly dst: LocalId;
  readonly src: LocalId;
}

// =========================================================================
// Constants — payload of `InstrConst`.
// =========================================================================

export type ConstValue =
  | { readonly kind: "int"; readonly value: bigint }
  | { readonly kind: "float"; readonly value: number }
  | { readonly kind: "bool"; readonly value: boolean }
  | { readonly kind: "char"; readonly value: number }
  | { readonly kind: "string"; readonly index: number }     // index into BcModule.strings
  | { readonly kind: "null" };

// =========================================================================
// Terminators — exactly one per block, control transfer at block exit.
// =========================================================================

export type Terminator =
  | TermBranch
  | TermCondBranch
  | TermReturn
  | TermUnreachable;

interface TermBase {
  readonly span: Span;
}

export interface TermBranch extends TermBase {
  readonly kind: "Branch";
  readonly target: BlockId;
}

export interface TermCondBranch extends TermBase {
  readonly kind: "CondBranch";
  readonly cond: LocalId;
  readonly then: BlockId;
  readonly else: BlockId;
}

export interface TermReturn extends TermBase {
  readonly kind: "Return";
  /** null for void returns. */
  readonly value: LocalId | null;
}

/** Trap at runtime; `reason` is shown in the diagnostic. Used for
 *  unreachable paths (e.g. exhaustive-match fall-through) and for the
 *  bytecode `unreachable` op. */
export interface TermUnreachable extends TermBase {
  readonly kind: "Unreachable";
  readonly reason: string;
}

// =========================================================================
// Project — collection of CFGFunctions, mirrors LoweredProject's shape.
// =========================================================================

export interface CFGProject {
  readonly modules: ReadonlyMap<string, CFGModule>;
  /** Same vtable entries the LoweredProject carries — Phase 2's bytecode
   *  emit reuses them as-is. */
  readonly vtableEntries: readonly L.VtableEntry[];
}

export interface CFGModule {
  readonly moduleId: string;
  readonly displayPath: string;
  readonly functions: readonly CFGFunction[];
  /** Struct + const decls pass through unchanged from the LoweredProject —
   *  the CFG is fn-only. */
  readonly otherDecls: readonly (L.LoweredStructDecl | L.LoweredConstDecl)[];
}
