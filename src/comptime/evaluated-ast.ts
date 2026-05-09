import type * as A from "../parser/ast.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
import type { MonoProject } from "./specialize.ts";
import type { GenericInstance } from "./instances.ts";
import type { ComptimeValue } from "./value.ts";

export interface EvaluatedProgram {
  readonly typed: TypedProgram;

  /** `@comptime`-marked decls and their materialized values. */
  readonly comptimeDecls: ReadonlyMap<A.ConstDecl, ComptimeValue>;

  /** `@file`-driven decls — the value read from disk at compile time. */
  readonly fileDecls: ReadonlyMap<A.ConstDecl, ComptimeValue>;
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
}
