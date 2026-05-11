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
  /** Maps struct type-index → trait names the struct implements. Built from
   *  `T implements Trait { … }` declarations; consumed by `match val { is Trait }`
   *  in the VM and the C emitter. */
  readonly implTable: ReadonlyMap<number, readonly string[]>;
  /** Per-`(traitName, methodName)` virtual-dispatch table. Each entry maps a
   *  receiver type-index to the fn-index of the impl method. The `virtual.call`
   *  op indexes this in O(1) — no cascade. Key format: `${traitName}.${methodName}`. */
  readonly vtables: ReadonlyMap<string, ReadonlyMap<number, number>>;
}

export interface BcFunction {
  readonly name: string;
  /** True iff this fn is the program's entry point (`fn main` in the
   *  source). Propagated from `MonoEntry.isMain` through the IR layers
   *  so the VM and the C emitter can locate `main` without re-parsing
   *  the mangled name. */
  readonly isMain: boolean;
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
