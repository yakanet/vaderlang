// Mid-IR (CFG) — data types only. See `docs/MID_IR_DESIGN.md` for the
// design rationale.
//
// =========================================================================
// Seam contract — Lowered ↔ CFG ↔ bytecode
// =========================================================================
// The pipeline maintains two distinct IRs side by side. The architectural
// verdict (see `plans/polymorphic-purring-spark.md`) is to KEEP them
// distinct: tree rewrites (match/try/for-in/range desugar) are cleaner
// over expression trees, and `build.ts` is a thin cheap-to-maintain seam.
// Reopen the merge question only when:
//   - midir↔bytecode merge ships (TODO §1.7c), or
//   - a second CFG consumer appears without a corresponding Lowered consumer,
//   - a new desugar pass naturally wants CFG shape (e.g. async yield points).
//
// What crosses the seam (Lowered → CFG, via `build.ts`):
//   - `MonoEntry` origin metadata (decorators, source decl, isMain) — flows
//     into `CFGFunction.origin` and is consumed by bytecode emit.
//   - `Type` instances and `Symbol` references — shared across IRs.
//   - `LoweredBinaryOp` / `LoweredUnaryOp` enums — reused as instruction ops.
//   - `IntrinsicName` enum — reused on `InstrIntrinsic`.
//   - `VtableEntry[]` — carried verbatim into `CFGProject.vtableEntries`.
// Struct decls are reshaped into the CFG-native `CFGStructDecl` (no Lowered
// import). Const decls disappear at lowering time (the `inline-consts` pass
// substitutes every read with the const's value), so the CFG never carries
// them.
//
// What is CFG-private (this file):
//   - `BasicBlock`, `BlockId`, `Instruction`, `Terminator`, `CFGLocal`,
//     `LocalId`, `ConstValue`. Lowered code never references these.
//
// What is Lowered-private (`src/lower/lowered-ast.ts`):
//   - `LoweredBlock`, `LoweredStmt`, `LoweredExpr` and their variants.
//     `build.ts` consumes these; downstream CFG passes never see them.

import type { Span } from "../diagnostics/diagnostic.ts";
import type * as L from "../lower/lowered-ast.ts";
import type { MonoEntry } from "../comptime/specialize.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { Type } from "../typecheck/types.ts";
import type { BcDataEntry } from "../bytecode/types.ts";

/** Index of a basic block within a function's `blocks` table. The entry
 *  block is always at index 0 by convention. */
export type BlockId = number;

/** Index of a local within a function's `locals` table. Locals are mutable
 *  named storage cells, like bytecode locals. SSA conversion (Phase 4)
 *  introduces a separate `ValueId` and renames reads/writes; for now,
 *  every instruction reads from / writes to a local. */
export type LocalId = number;

/** A function's CFG: the entry block, all blocks, all locals/params.
 *  Carries enough metadata for bytecode reservation (export/extern routing)
 *  so the emitter never has to walk back into the LoweredAST. */
export interface CFGFunction {
  readonly mangled: string;
  readonly params: readonly CFGParam[];
  readonly returnType: Type;
  readonly locals: readonly CFGLocal[];
  readonly blocks: readonly BasicBlock[];
  readonly entry: BlockId;            // canonically 0
  readonly origin: MonoEntry;         // mirrored from LoweredFnDecl.origin
  /** Source-level name used when registering an @export entry or when this
   *  fn carries `@extern` (with a body). Falls back to `mangled` when the
   *  origin decl is synthetic (no source-level FnDecl). */
  readonly externName: string;
  /** True when `@extern`-decorated. Bodyless extern stubs live in
   *  `CFGModule.externs` instead, so this flag only fires for the unusual
   *  case of an `@extern`-decorated fn that still happens to have a body. */
  readonly isExtern: boolean;
  /** True when `@export`-decorated. Drives the bytecode export table. */
  readonly isExported: boolean;
}

/** Declaration of a bodyless fn (typically `@extern`). Bytecode emit
 *  registers these in the import table and never tries to emit a body. */
export interface CFGExternDecl {
  readonly mangled: string;
  readonly params: readonly CFGParam[];
  readonly returnType: Type;
  readonly origin: MonoEntry;
  readonly externName: string;
  readonly isExported: boolean;
  /** True when the originating decl carried `@extern` (user-supplied
   *  foreign symbol — c-emit emits a real `extern …(…)` declaration that
   *  the linker resolves). False for `@intrinsic`-style bodyless fns
   *  (stdlib host bindings handled by the c-emit shim switch). */
  readonly isExtern: boolean;
}

/** A struct declaration carrying only what the bytecode emitter needs to
 *  intern its layout into the type table. CFG-native (no Lowered import). */
export interface CFGStructDecl {
  readonly mangled: string;
  readonly fields: readonly CFGStructField[];
  readonly origin: MonoEntry;
}

export interface CFGStructField {
  readonly name: string;
  readonly type: Type;
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
  | InstrCallIndirect
  | InstrFnRef
  | InstrVirtualCall
  | InstrFieldGet
  | InstrFieldSet
  | InstrArrayGet
  | InstrArraySet
  | InstrArrayLen
  | InstrArrayPush
  | InstrArraySlice
  | InstrStructNew
  | InstrArrayNew
  | InstrDataConst
  | InstrTypeCheck
  | InstrTypeConst
  | InstrCast
  | InstrCellNew
  | InstrCellGet
  | InstrCellSet
  | InstrMakeClosure
  | InstrIntrinsic
  | InstrMove
  | InstrDeferPush
  | InstrDeferPopExec;

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

/** Direct call — the callee is a known fn symbol. The bytecode emit decides
 *  whether to route as `call <fn>` or `call.import <imp>` (and whether to
 *  apply the OP_INTRINSIC fast path for stdlib hot calls like
 *  `string.concat`) based on which side-table the symbol lives in. */
export interface InstrCall extends InstrBase {
  readonly kind: "Call";
  readonly dst: LocalId | null;       // null when the call returns void
  readonly callee: Symbol;
  readonly args: readonly LocalId[];
  readonly type: Type;
}

/** Indirect call — the callee is a fn-typed local (e.g. a closure or a
 *  fn-ref read out of a struct field). Emits `call.indirect <typeIdx>`. */
export interface InstrCallIndirect extends InstrBase {
  readonly kind: "CallIndirect";
  readonly dst: LocalId | null;
  readonly callee: LocalId;
  readonly args: readonly LocalId[];
  readonly fnType: Type;              // for type-table interning at emit time
  readonly type: Type;                // result type
}

/** Materialise a fn value (a fat pointer `{ code, env }` with `env = null`
 *  for non-capturing globals). The CFG uses this when a fn name is read in
 *  a non-call position. */
export interface InstrFnRef extends InstrBase {
  readonly kind: "FnRef";
  readonly dst: LocalId;
  readonly fnSymbol: Symbol;
  readonly type: Type;                // the fn type
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
  /** When true, the target is provably stack-allocated and the C emit can
   *  skip the write-barrier macro. Set by the escape-analysis pass after
   *  forward-propagating stack-alloc origin through Move/Cast aliasing ;
   *  defaults to false (barrier emitted) when unset. */
  readonly barrierless: boolean;
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

export interface InstrArraySlice extends InstrBase {
  readonly kind: "ArraySlice";
  readonly dst: LocalId;
  /** BcType index of the result — the slice view inherits the parent
   *  array's element type, mangled the same way. */
  readonly type: Type;
  readonly target: LocalId;
  readonly lo: LocalId;
  readonly hi: LocalId;
}

export interface InstrStructNew extends InstrBase {
  readonly kind: "StructNew";
  readonly dst: LocalId;
  readonly type: Type;
  /** Per-field initialiser locals, in declaration order. */
  readonly fields: readonly LocalId[];
  /** When true, the struct value never escapes its function and can be
   *  stack-allocated. Set by the escape-analysis pass (`escape.ts`) ;
   *  defaults to false (heap alloc) when the analysis hasn't run or the
   *  result is unknown. The actual stack-alloc codegen lives in a later
   *  phase ; for now the flag is informational and shows up in the dump. */
  readonly stack: boolean;
}

export interface InstrArrayNew extends InstrBase {
  readonly kind: "ArrayNew";
  readonly dst: LocalId;
  readonly type: Type;
  readonly length: number;
  readonly elements: readonly LocalId[];
  /** Same `stack` semantics as `InstrStructNew`. */
  readonly stack: boolean;
}

/** Pre-materialised module-level `const T[]` literal. The pool entry is built
 *  by the `inline-consts` pass ; emit lowers this to the bytecode `data.const`
 *  op. No operands — the value is the static pool entry's runtime ref. */
export interface InstrDataConst extends InstrBase {
  readonly kind: "DataConst";
  readonly dst: LocalId;
  readonly type: Type;             // `const T[]` array type
  readonly poolIndex: number;
}

/** Runtime tag check — `is X`. */
export interface InstrTypeCheck extends InstrBase {
  readonly kind: "TypeCheck";
  readonly dst: LocalId;
  readonly value: LocalId;
  readonly checkType: Type;
}

/** Reify a type as a runtime value. `valueType` is the concrete `Type` the
 *  alias resolves to ; the bytecode emit interns it via the module's type
 *  table and emits `type.const N`. `type` is `TypeMeta`. */
export interface InstrTypeConst extends InstrBase {
  readonly kind: "TypeConst";
  readonly dst: LocalId;
  readonly type: Type;
  readonly valueType: Type;
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

/** Push a closure onto the current frame's defer-stack. `closure` is the
 *  fn-ref produced by `MakeClosure` capturing the defer body's free
 *  variables. Backends emit `defer.push` ; the runtime appends `closure`
 *  to a per-frame list executed on normal `defer.pop_exec` or when a
 *  panic unwinds the frame. */
export interface InstrDeferPush extends InstrBase {
  readonly kind: "DeferPush";
  readonly closure: LocalId;
}

/** Pop and execute `count` entries from the current frame's defer-stack
 *  (LIFO). Emitted at every normal exit (block fall-through, `return`,
 *  `break`, `continue`) ; `count` matches the number of defers introduced
 *  in the scopes the exit transcends. */
export interface InstrDeferPopExec extends InstrBase {
  readonly kind: "DeferPopExec";
  readonly count: number;
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
  /** Project-level string pool. The converter interns each `LoweredStringLit`
   *  here ; `InstrConst` of kind "string" stores the index. The emitter
   *  reuses this pool verbatim as `BcModule.strings`. */
  readonly strings: readonly string[];
  /** Mirrors `LoweredProject.dataPool` — carried verbatim into
   *  `BytecodeModule.dataPool`. `InstrDataConst` references entries by index. */
  readonly dataPool: readonly BcDataEntry[];
  /** Forwarded from `LoweredProject.symbolRedirects` ; consumed by the
   *  bytecode emit (`fnIndexBySymId` builder). */
  readonly symbolRedirects: ReadonlyMap<number, number>;
}

export interface CFGModule {
  readonly moduleId: string;
  readonly displayPath: string;
  readonly functions: readonly CFGFunction[];
  /** Bodyless fn declarations (`@extern` stubs). Bytecode emit routes these
   *  to the import table; no CFG body exists for them. */
  readonly externs: readonly CFGExternDecl[];
  /** Struct declarations the bytecode emit needs to intern into the type
   *  table. Const decls don't appear here — they're inlined into every read
   *  site by the `inline-consts` lowering pass. */
  readonly structDecls: readonly CFGStructDecl[];
}
