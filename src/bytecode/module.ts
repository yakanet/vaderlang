// In-memory bytecode module — the lingua franca shared by the VM (§1.8), the
// C emitter (§1.9), the WASM emitter (§1.10), and the .vir text format (§1.7b).

import type { Op } from "./ops.ts";
import type { BcType, ValType } from "./types.ts";

export interface BytecodeModule {
  readonly name: string;
  /** Type table. Indices referenced by `struct.*`, `array.*`, `type_check`,
   *  `ref.cast`, and function signatures. */
  readonly types: readonly BcType[];
  readonly strings: readonly string[];
  readonly functions: readonly BcFunction[];
  /** External symbols expected from the host (`@extern` decls + signature-only fns). */
  readonly imports: readonly BcImport[];
  /** Symbols exposed to the host (`@export` fns). */
  readonly exports: readonly BcExport[];
}

export interface BcFunction {
  readonly name: string;
  readonly signature: BcSignature;
  /** Locals declared in addition to the params. Slot index = `params.length + i`. */
  readonly locals: readonly BcLocal[];
  readonly body: readonly Op[];
  /** Per-op source mapping; `debug[i]` corresponds to `body[i]` (or null). */
  readonly debug: readonly (DebugPos | null)[];
}

export interface BcSignature {
  readonly params: readonly ValType[];
  readonly result: ValType;            // `void` = leaves nothing on the stack
}

export interface BcLocal {
  readonly name: string;
  readonly val: ValType;
}

export interface DebugPos {
  readonly file: string;
  readonly line: number;
  readonly column: number;
}

export interface BcImport {
  readonly externName: string;         // user-facing name in source
  readonly mangledName: string;
  readonly signature: BcSignature;
}

export interface BcExport {
  readonly externName: string;
  readonly fnIndex: number;
}
