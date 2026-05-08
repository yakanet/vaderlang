# Mid-IR (CFG) — Design Document

Sprint 3.10 phase 1 — *foundation only*, no migration of the lowering /
emit pipeline yet.

## Motivation

The current pipeline is `LoweredAST → BytecodeModule`. Both are tree-shaped
(blocks contain stmts + a trailing expr; control flow is `LoweredIf` /
`LoweredLoop`). The bytecode emitter linearises directly to WASM-style
structured ops (`block` / `loop` / `if` / `end` / `br <depth>`).

This shape blocks several optimisations the architect's audit flagged as
"the next investment":

| Analysis              | Why it needs a CFG                                  |
|-----------------------|-----------------------------------------------------|
| Dead-store elimination | Per-store liveness — needs reverse postorder, def-use chains. The current dce/index.ts only prunes whole decls. |
| Escape analysis        | Stack-allocate non-escaping structs (SPEC §"the compiler may"). Requires alias tracking through the def graph. |
| Copy propagation       | Closure-cell `LoweredCellGet`/`Set` patterns hide loads/stores. Needs SSA-style def-tracking. |
| Borrow-style checks    | Future. Same need: SSA + dominators. |

A CFG with explicit basic blocks + terminators is the standard substrate
for these. SSA can be layered on top later (separate phase).

## Position in the pipeline

```
parser → resolver → typecheck → comptime → mono → lower → CFG → bytecode → VM / C-emit
                                                          ↑
                                             new layer (introduced here)
```

The DCE pass currently sits between `lower` and `bytecode`. Once CFG lands,
DCE moves into the CFG layer (richer analyses). The bytecode emitter
becomes a CFG → linear-ops pass; the LoweredAST → CFG pass replaces the
current LoweredAST → bytecode emit.

## CFG data model

### Function shape

```ts
interface CFGFunction {
  readonly mangled: string;              // matches LoweredFnDecl.mangled
  readonly params: readonly CFGParam[];
  readonly returnType: Type;
  readonly locals: readonly CFGLocal[];  // named storage cells, like bytecode locals
  readonly blocks: readonly BasicBlock[];
  readonly entry: BlockId;               // always 0 by convention
  readonly origin: MonoEntry;            // for diagnostics + downstream passes
}

type BlockId = number;                   // index into `blocks`
type LocalId = number;                   // index into `locals`
```

### Basic blocks

```ts
interface BasicBlock {
  readonly id: BlockId;
  readonly instructions: readonly Instruction[];
  readonly terminator: Terminator;
  readonly span: Span;                   // for diagnostics; the block's "main" span
}
```

A block is **single-entry, single-exit**: control enters at `instructions[0]`,
flows linearly through the instructions, and leaves via the terminator.

### Instructions (three-address code)

Pre-SSA: each instruction reads operands and writes its result into a
named local. Locals are mutable, like bytecode locals.

```ts
type Instruction =
  | { kind: "Const"; dst: LocalId; value: ConstValue; type: Type }
  | { kind: "BinOp"; dst: LocalId; op: LoweredBinaryOp; lhs: LocalId; rhs: LocalId; type: Type }
  | { kind: "UnOp"; dst: LocalId; op: LoweredUnaryOp; operand: LocalId; type: Type }
  | { kind: "Call"; dst: LocalId | null; callee: Symbol; args: readonly LocalId[]; type: Type }
  | { kind: "VirtualCall"; dst: LocalId | null; trait: string; method: string; receiver: LocalId; args: readonly LocalId[]; type: Type }
  | { kind: "FieldGet"; dst: LocalId; target: LocalId; field: string; type: Type }
  | { kind: "FieldSet"; target: LocalId; field: string; value: LocalId }
  | { kind: "ArrayGet"; dst: LocalId; target: LocalId; index: LocalId; type: Type }
  | { kind: "ArraySet"; target: LocalId; index: LocalId; value: LocalId }
  | { kind: "ArrayLen"; dst: LocalId; target: LocalId }
  | { kind: "ArrayPush"; target: LocalId; value: LocalId }
  | { kind: "StructNew"; dst: LocalId; type: Type; fields: readonly LocalId[] }
  | { kind: "ArrayNew"; dst: LocalId; type: Type; length: number; elements: readonly LocalId[] }
  | { kind: "TypeCheck"; dst: LocalId; value: LocalId; checkType: Type }
  | { kind: "Cast"; dst: LocalId; value: LocalId; type: Type }
  | { kind: "CellNew"; dst: LocalId; value: LocalId; valueType: Type }
  | { kind: "CellGet"; dst: LocalId; cell: LocalId; valueType: Type }
  | { kind: "CellSet"; cell: LocalId; value: LocalId; valueType: Type }
  | { kind: "MakeClosure"; dst: LocalId; fnSymbol: Symbol; env: LocalId; type: Type }
  | { kind: "Intrinsic"; dst: LocalId | null; name: IntrinsicName; args: readonly LocalId[]; displayFor?: Type };
```

### Terminators

```ts
type Terminator =
  | { kind: "Branch"; target: BlockId }
  | { kind: "CondBranch"; cond: LocalId; then: BlockId; else: BlockId }
  | { kind: "Return"; value: LocalId | null }
  | { kind: "Unreachable"; reason: string };
```

**Decision (phase 1)**: no `Switch` terminator. Match desugaring already
produces a chain of `is` checks → `CondBranch` cascade, like today's
LoweredIf nesting.

### Constants

```ts
type ConstValue =
  | { kind: "int"; value: bigint }
  | { kind: "float"; value: number }
  | { kind: "bool"; value: boolean }
  | { kind: "char"; value: number }
  | { kind: "string"; index: number }   // index into BcModule.strings
  | { kind: "null" };
```

## Translation: LoweredAST → CFG

Each `LoweredFnDecl` becomes a `CFGFunction`. The translator is a
visitor that:

1. Allocates `LocalId`s for each `LoweredLet` (mirroring today's bytecode
   slot allocation).
2. Builds blocks as it walks: every `LoweredIf` produces (cond block →
   then block → join block) and a `CondBranch` terminator. Every `LoweredLoop`
   produces (cond block → body block → next-iter or break edge).
3. Flattens `LoweredBlock`'s stmts in-line, allocating fresh tmp locals for
   intermediate values that today live on the bytecode stack.

Sub-expressions become `Instruction` sequences with named results (the tmp
locals). Example: `(a + b) * c` becomes
```
%t0 = BinOp add a b
%t1 = BinOp mul %t0 c
```

Loop lowering is the most invasive case — see Open Questions §1.

## Translation: CFG → bytecode

The bytecode emitter consumes the CFG and produces the existing structured
op set. **The hard problem**: bytecode uses WASM-style `block`/`loop`/`if`/
`end`/`br <depth>` (single-entry single-exit regions), which require the
CFG to be *reducible* (no irreducible loops). Two paths:

- **Restrict CFG to reducible** — every translation from LoweredAST naturally
  produces reducible CFGs (no `goto`s in source language). Run a structuring
  algorithm (relooper / Stackifier) to recover the WASM-style nesting.
- **Extend bytecode with `goto label`** — adds a non-structured op, breaks
  WASM portability story, but trivialises the emit.

**Decision (phase 1)**: defer. The data structures support both. Phase 2
picks. The architect's notes mention WASM 1:1 emit as a goal, which favours
the structuring approach.

## Phase plan

| Phase | Scope | Effort | Status |
|-------|-------|--------|--------|
| **1** | Design doc + data types in `src/midir/cfg.ts`. No converter. No emitter. No tests. | 2 h | ✅ done |
| **2** | LoweredAST → CFG converter (`src/midir/build.ts`) + structurer + CFG → bytecode emitter (`src/midir/emit.ts`) behind `--midir`. Behavioural parity (`tests/midir_parity.test.ts`) on every snippet. | 3-5 d | ✅ done |
| **3** | DCE on the CFG (`src/midir/dce.ts`) : copy folding, per-store liveness + dead instruction elim, dead local elim. -11% to -36% instructions on representative snippets. | 1-2 d | ✅ done |
| **4** | Pruned SSA conversion (`src/midir/ssa.ts`) : Cytron et al. with liveness-pruned phi placement, dom-tree-walk renaming. Out-of-SSA materialises phis as `Move` in predecessors. Wired as `toSSA → fromSSA` round-trip in the pipeline ; behaviour-preserving (145/145 parity). Sets up SSA infrastructure for phase 5. | 2-3 d | ✅ done |
| **5** | Escape analysis on SSA: stack-allocate non-escaping structs. | 2-3 d | |
| **6** | Drop the legacy LoweredAST → bytecode path. CFG becomes the single substrate. | 1 d | |

Total: ~2 weeks of focused work after this commit. Each phase is shippable
on its own (behind the flag from phase 2).

## Open questions

1. **Loops.** WASM-style `loop` is single-entry; the loop body branches back
   to the entry. Our CFG should encode this naturally (a block with a back-edge
   to itself or to the loop header). The structuring pass needs a back-edge
   detector. **Decision: defer to phase 2.**

2. **Defers.** `LoweredLoop` carries `defer` semantics implicitly via the
   block-exit dance in the current lowerer. In the CFG, defers become
   explicit instructions inserted at every exit edge. **Resolution: emit
   defers at translation time; the CFG carries the duplicated cleanup
   sequences as plain instructions.**

3. **Closure cells.** `CellGet`/`CellSet` instructions stay opaque to the
   CFG — they're just memory ops. SSA conversion (phase 4) must NOT promote
   cells to value-numbered registers; their whole point is shared mutable
   state across closures.

4. **Pre-SSA mutability.** The pre-SSA model has named, mutable locals.
   Liveness analysis (phase 3) is fine on this — standard algorithm. SSA
   conversion (phase 4) is the standard textbook one (Cytron et al.).

5. **Synthetic locals for tmps.** Every sub-expression result becomes a
   tmp local. For a typical fn, this multiplies the local count by ~5×.
   Bytecode locals are cheap (just slot indices) but C emit allocates a
   variable per local — could blow up the C source. **Resolution: phase 2
   bytecode emit pass *can* coalesce tmps based on liveness; or the SSA
   pass (phase 4) does it as part of register allocation.**

6. **Span propagation.** Each instruction needs a span for diagnostics.
   Today the LoweredAST nodes carry spans on each expr/stmt. The CFG
   carries spans per instruction. The translator copies through.

7. **Bytecode op coverage.** The current bytecode op set has some idioms
   (`local.tee`, `dup`, structured `block`/`loop`/`if`/`end`/`br`) that the
   CFG doesn't need. Phase 6 may shrink the op set.

## Non-goals (phase 1)

- Implementing the converter (LoweredAST → CFG) — phase 2.
- Implementing CFG → bytecode emit — phase 2.
- SSA — phase 4.
- Loop structure recovery / relooper — phase 2.
- Replacing the existing bytecode emit path — phase 6.

## Files added in phase 1

- `docs/MID_IR_DESIGN.md` (this document)
- `src/midir/cfg.ts` (data types only — no functions)

That's the entire phase-1 footprint. Subsequent phases plug into the
existing pipeline behind a feature flag.
