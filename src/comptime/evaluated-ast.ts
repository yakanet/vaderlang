import type * as A from "../parser/ast.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
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
}
