import type * as A from "../parser/ast.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
import type { Type } from "../typecheck/types.ts";
import type { MonoProject } from "./specialize.ts";
import type { GenericInstance } from "./instances.ts";
import type { ComptimeValue } from "./value.ts";

/** One blanket-Into impl member observation : the typer recorded a
 *  coercion site that needs the impl's `into` member specialised with
 *  these typeArgs. The mono pass reads `intoMembersToMaterialise` to
 *  emit one `MonoEntry` per `(member, typeArgs)` pair, indexed in
 *  `implMethodEntries` so `lookupImplEntry` finds it from the lower. */
export interface IntoMemberObservation {
  readonly member: A.FnDecl;
  /** Module where the impl decl lives — needed for the entry's
   *  symbol-resolution context. */
  readonly program: TypedProgram;
  /** Concrete values bound to the impl's own typeParams, in
   *  `entry.decl.typeParams` order. Used both as the entry's `typeArgs`
   *  and as the inner key of `implMethodEntries[member][argsKey]`. */
  readonly typeArgs: readonly Type[];
}

export interface EvaluatedProgram {
  readonly typed: TypedProgram;

  /** `@comptime`-marked decls and their materialized values. */
  readonly comptimeDecls: ReadonlyMap<A.ConstDecl, ComptimeValue>;
}

export interface EvaluatedProject {
  readonly typed: TypedProject;
  readonly modules: ReadonlyMap<string, EvaluatedProgram>;
  readonly instances: readonly GenericInstance[];
  /** Specialised entries (one per non-generic decl plus one per generic
   *  instance from the registry). Computed by `monomorphizeProject` at the
   *  end of comptime evaluation — the comptime engine is the sole driver
   *  of specialisation (Layer 2 of the type-first redesign).
   *  The `liveEvaluated` overlay used during the bake loop carries an
   *  empty `mono` ; the final post-bake EvaluatedProject is the only one
   *  consumers should rely on for specialisation lookups. */
  readonly mono: MonoProject;
  /** `@file("path")` expression-position calls baked at comptime. Lower
   *  reads this to emit a `LoweredStringLit` of the file contents. */
  readonly fileExprs: ReadonlyMap<A.IntrinsicCallExpr, string>;
  /** Blanket-Into impl members observed at typer coercion sites — see
   *  `IntoMemberObservation`. Empty when the project uses no user-
   *  declared `Into` impls. Mono pass consumes this to materialise the
   *  members alongside the struct-indexed generic impls. */
  readonly intoMembers: readonly IntoMemberObservation[];
}
