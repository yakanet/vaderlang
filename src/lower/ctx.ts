// Shared context types threaded through every pass.
//
// `LowerProjectCtx` is built once per `lowerProject` call and holds the inputs
// every pass reads (mono entries, impl registry, std/core symbols). `FnLowerCtx`
// is pushed per fn body — it carries the active substitution, return type, and
// a stack of `BlockCtx` so defers can be replayed at every block exit.

import type * as A from "../parser/ast.ts";
import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { EvaluatedProject } from "../comptime/evaluated-ast.ts";
import type { ClosureAnalysis } from "./passes/closures.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProgram } from "../typecheck/typed-ast.ts";
import type { ImplRegistry } from "../typecheck/impls.ts";
import type { Substitution, Type } from "../typecheck/types.ts";
import type { MonoEntry, MonoProject } from "../comptime/specialize.ts";
import type { EntryTypes } from "./entry-types.ts";
import type {LoweredDecl} from "./lowered-ast.ts";

export interface LowerProjectCtx {
  readonly evaluated: EvaluatedProject;
  readonly mono: MonoProject;
  readonly impls: ImplRegistry;
  readonly coreTraitCache: Map<string, Symbol | null>;
  /** std/core's symbol table — pre-resolved at construction so trait/struct
   *  lookups don't re-walk the module map per call. */
  readonly coreSymbols: ReadonlyMap<string, Symbol> | null;
  /** std/iter's symbol table — needed by the for-in chain-fusion fast path
   *  to recognise `MapIterator` / `FilterIterator` / `TakeIterator` /
   *  `SkipIterator` struct lits as a fuseable chain. Null when the project
   *  doesn't import std/iter (in which case fusion never fires). */
  readonly iterSymbols: ReadonlyMap<string, Symbol> | null;
  /** Free-variable analysis output. Lets the lowerer detect captured locals
   *  and rewrite their declarations / reads / writes through closure cells. */
  readonly closures: ClosureAnalysis;
  /** Synthetic decls produced during lowering — chiefly the lifted top-level
   *  fns and their env structs spawned by lambda lifting. Appended to the
   *  result project under `synthModuleId` so the bytecode emit picks them up
   *  alongside user decls. */
  readonly synthDecls: LoweredDecl[];
  nextSyntheticId: number;
  readonly diags: DiagnosticCollector;
}

export interface BlockCtx {
  /** Defers registered in this block, in encounter order. Re-emitted in reverse at every exit. */
  readonly defers: A.Stmt[];
  readonly isFnRoot: boolean;
  readonly isLoopBody: boolean;
}

export interface FnLowerCtx {
  readonly project: LowerProjectCtx;
  readonly entry: MonoEntry;
  readonly typed: TypedProgram;
  readonly subst: Substitution;
  /** Typed-AST view with `subst` already applied at every read. Lower passes
   *  consume this instead of reaching into `typed`/`subst` directly. */
  readonly types: EntryTypes;
  readonly returnType: Type;
  readonly selfType: Type | null;
  readonly blocks: BlockCtx[];
  uniq: number;
  /** When non-null, we're lowering the body of a lifted lambda. Captured
   *  symbols defined OUTSIDE the lambda are accessed via env-struct fields
   *  rather than as direct locals. The map is keyed by the captured outer
   *  symbol's id and yields the env field name. */
  readonly liftedContext: LiftedFnContext | null;
}

export interface LiftedFnContext {
  /** The synthetic env-param symbol — referenced by env field accesses inside the body. */
  readonly envSymbol: Symbol;
  /** Type of the env param (the synthesized struct's type). */
  readonly envType: Type;
  /** Captured-outer-symbol-id → env field name. */
  readonly captureFields: ReadonlyMap<number, string>;
}
