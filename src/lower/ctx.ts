// Shared context types threaded through every pass.
//
// `LowerProjectCtx` is built once per `lowerProject` call and holds the inputs
// every pass reads (mono entries, impl registry, std/core symbols). `FnLowerCtx`
// is pushed per fn body — it carries the active substitution, return type, and
// a stack of `BlockCtx` so defers can be replayed at every block exit.

import type * as A from "../parser/ast.ts";
import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { EvaluatedProject } from "../comptime/evaluated-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProgram } from "../typecheck/typed-ast.ts";
import type { ImplRegistry } from "../typecheck/impls.ts";
import type { Substitution, Type } from "../typecheck/types.ts";
import type { MonoEntry, MonoProject } from "../monomorphize/index.ts";

export interface LowerProjectCtx {
  readonly evaluated: EvaluatedProject;
  readonly mono: MonoProject;
  readonly impls: ImplRegistry;
  readonly coreTraitCache: Map<string, Symbol | null>;
  /** std/core's symbol table — pre-resolved at construction so trait/struct
   *  lookups don't re-walk the module map per call. */
  readonly coreSymbols: ReadonlyMap<string, Symbol> | null;
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
  readonly returnType: Type;
  readonly selfType: Type | null;
  readonly blocks: BlockCtx[];
  uniq: number;
}
