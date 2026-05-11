// Passive registry of generic instantiations. The type-checker already
// represents `List(i32)` as `Struct { symbol, args }`; the comptime pass
// scans typed-AST type-expressions, normalises each instance, and adds an
// entry. The bytecode emitter (1.7) will read this registry to know which
// concrete specializations to materialize.

import type { Type, StructType, TraitType } from "../typecheck/types.ts";
import { canonicalArgsKey, forEachType } from "../typecheck/types.ts";
import type { Symbol } from "../resolver/symbol.ts";

export interface GenericInstance {
  readonly symbol: Symbol;
  readonly args: readonly Type[];
  readonly displayKey: string;
}

export class InstanceRegistry {
  private readonly byKey = new Map<string, GenericInstance>();
  private readonly listeners: ((inst: GenericInstance) => void)[] = [];

  /** Subscribe a callback that fires once per newly-added (deduplicated)
   *  instance. Used by `closeOverGenericImpls` to drive a worklist instead
   *  of a fixpoint. Returns an unsubscribe function. */
  onNewInstance(cb: (inst: GenericInstance) => void): () => void {
    this.listeners.push(cb);
    return () => {
      const idx = this.listeners.indexOf(cb);
      if (idx >= 0) this.listeners.splice(idx, 1);
    };
  }

  add(symbol: Symbol, args: readonly Type[]): GenericInstance {
    const displayKey = `${symbol.id}(${canonicalArgsKey(args)})`;
    const existing = this.byKey.get(displayKey);
    if (existing !== undefined) return existing;
    const inst: GenericInstance = { symbol, args, displayKey };
    this.byKey.set(displayKey, inst);
    for (const cb of this.listeners) cb(inst);
    return inst;
  }

  /** Walk a Type, registering every concrete generic Struct/Trait instance it mentions. */
  observe(t: Type): void {
    forEachType(t, (sub) => {
      if ((sub.kind === "Struct" || sub.kind === "Trait")
          && sub.args.length > 0
          && sub.args.every(isConcrete)) {
        this.add(sub.symbol, sub.args);
      }
    });
  }

  /** Register a generic-fn call site whose explicit type args are concrete.
   *  The downstream monomorphizer doesn't yet materialise fn instances (still
   *  deferred — see TODO §1.5b), but the registry already accepts them so the
   *  surface is in place when that work lands. */
  observeFnCall(sym: Symbol, typeArgs: readonly Type[]): void {
    if (sym.kind !== "fn") return;
    if (typeArgs.length === 0 || !typeArgs.every(isConcrete)) return;
    this.add(sym, typeArgs);
  }

  entries(): readonly GenericInstance[] {
    return [...this.byKey.values()].sort((a, b) => a.displayKey.localeCompare(b.displayKey));
  }

  size(): number { return this.byKey.size; }
}

function isConcrete(t: Type): boolean {
  let ok = true;
  forEachType(t, (sub) => {
    switch (sub.kind) {
      case "TypeParam":
      case "Unresolved":
      case "FreeInt":
      case "FreeFloat":
      case "Self":
        ok = false;
    }
  });
  return ok;
}

export type { Type, StructType, TraitType };
