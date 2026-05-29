// In-memory bytecode module — the lingua franca shared by the VM (§1.8), the
// C emitter (§1.9), the WASM emitter (§1.10), and the .vir text format (§1.7b).

import type { Op } from "./ops.ts";
import type { BcDataEntry, BcType, ValType } from "./types.ts";

export interface BytecodeModule {
  readonly name: string;
  /** Type table. Indices referenced by `struct.*`, `array.*`, `type_check`,
   *  `ref.cast`, and function signatures. */
  readonly types: readonly BcType[];
  readonly strings: readonly string[];
  /** Pre-materialised primitive arrays — see `BcDataEntry`. Index space is
   *  module-local ; the `data.const N` op references entries here. */
  readonly dataPool: readonly BcDataEntry[];
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
  /** True when the source declaration carried `@test`. Roots this fn
   *  during the test-runner build's `pruneUnusedFunctions` pass so the
   *  test runner can still resolve it by mangled name even though no
   *  static call site references it. */
  readonly isTest: boolean;
  /** True when `synthesiseIntrinsicWrappers` minted this `$vt` wrapper to
   *  bridge vtable dispatch to a stdlib `@intrinsic`. Used by
   *  `pruneUnusedFunctions`'s library-emit fallback to distinguish
   *  user-authored decls (kept as roots when no `main` / `@export`) from
   *  synthesised glue (DCE-eligible whenever no real dispatch reaches it). */
  readonly isSynthesised: boolean;
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
  /** Per-param `BcType` indices into `BytecodeModule.types`. Parallel to
   *  `params` and matches its length. The VM only consults `params` /
   *  `result` (which carry the stack-erased `ValType`s) ; the C-emit
   *  reads these indices to apply B1 (nullable-ref inline rep) at the
   *  call boundary. Computed by `paramsToSignature` in `bytecode/emit.ts`. */
  readonly paramTypes: readonly number[];
  /** `BcType` index for the return slot. Same purpose as `paramTypes`. */
  readonly resultType: number;
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
  /** True when the source decl was `@extern` (user-supplied foreign
   *  symbol resolved by the host linker). False for the stdlib
   *  `@intrinsic` family that c-emit's shim switch routes to runtime
   *  helpers. */
  readonly isExtern: boolean;
}

export interface BcExport {
  readonly externName: string;
  readonly fnIndex: number;
}
