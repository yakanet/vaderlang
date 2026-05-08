// Dead-code elimination: prunes stdlib declarations not transitively reachable
// from the user program. Runs between `lowerProject` and the bytecode/native
// emitters so unused parts of std/core (Range, ArrayIter, …) and other stdlib
// modules disappear from the final artifact.
//
// Restricting the scope to stdlib is conservative on purpose: it matches the
// motivating use case (std/core's iterator machinery is auto-imported but not
// always used) without surprising deletions in user code that lacks `main`
// (e.g. library targets, snapshot fixtures that compile-but-don't-execute).
//
// `@comptime` / `@file` constants are *not* automatic roots: their value is
// inlined at each use site by the bytecode emitter, so an unreferenced one is
// genuinely dead. They are still preserved when the surrounding module is
// non-stdlib, by the user-code rule below.
//
// Decls without a stable `origin.symbol` (rare — e.g. some impl-decl shells
// from monomorphization) are kept by default to avoid surprising deletions.

import type { Decorator } from "../parser/ast.ts";
import { DEC, hasDecorator } from "../parser/decorators.ts";
import type { LoweredDecl, LoweredModule, LoweredProject } from "../lower/index.ts";
import { isMainMangled } from "../monomorphize/mono-ast.ts";
import { isStdlibModule } from "../resolver/module.ts";

import { forEachReference } from "./reachability.ts";

const NO_DECORATORS: readonly Decorator[] = [];

export function eliminateDeadCode(project: LoweredProject): LoweredProject {
  const bySymbolId = new Map<number, LoweredDecl>();
  const reachable = new Set<number>();
  const worklist: LoweredDecl[] = [];

  // Single pass over modules: build the symbol-id index and seed the worklist
  // with every root so we don't traverse the project twice.
  for (const m of project.modules.values()) {
    const fromStdlib = isStdlibModule(m.displayPath);
    for (const d of m.decls) {
      const sym = d.origin.symbol;
      if (sym !== null) bySymbolId.set(sym.id, d);
      if (!isRoot(d, fromStdlib)) continue;
      if (sym !== null) reachable.add(sym.id);
      worklist.push(d);
    }
  }

  // Group vtable entries by `(trait, method)` so a `LoweredVirtualCall`
  // resolves to the full impl set in one lookup. Without this, DCE would
  // delete the impl methods (call sites only carry the trait/method
  // strings, not the impl symbols).
  const implsByVtableKey = new Map<string, number[]>();
  for (const e of project.vtableEntries) {
    const key = `${e.traitName}|${e.methodName}`;
    let bucket = implsByVtableKey.get(key);
    if (bucket === undefined) { bucket = []; implsByVtableKey.set(key, bucket); }
    bucket.push(e.fnSymbol.id);
  }

  const visit = (id: number) => {
    if (reachable.has(id)) return;
    reachable.add(id);
    const decl = bySymbolId.get(id);
    if (decl !== undefined) worklist.push(decl);
  };
  const visitVirtual = (trait: string, method: string) => {
    const ids = implsByVtableKey.get(`${trait}|${method}`);
    if (ids !== undefined) for (const id of ids) visit(id);
  };
  while (worklist.length > 0) forEachReference(worklist.pop()!, visit, visitVirtual);

  const modules = new Map<string, LoweredModule>();
  for (const [id, m] of project.modules) {
    modules.set(id, filterModule(m, reachable));
  }
  // Vtable entries reference impl fns by Symbol id — DCE only filters decls
  // by reachability, so we keep them all here; the bytecode emit's vtable
  // builder will skip entries whose fn symbol didn't make it into the
  // (DCE'd) project naturally.
  return { modules, vtableEntries: project.vtableEntries };
}

function filterModule(m: LoweredModule, reachable: ReadonlySet<number>): LoweredModule {
  const kept: LoweredDecl[] = [];
  let dropped = false;
  for (const d of m.decls) {
    const sym = d.origin.symbol;
    if (sym === null || reachable.has(sym.id)) kept.push(d);
    else dropped = true;
  }
  if (!dropped) return m;
  return { moduleId: m.moduleId, displayPath: m.displayPath, decls: kept };
}

function isRoot(d: LoweredDecl, fromStdlib: boolean): boolean {
  // User code is never DCE'd — keeps library targets and snapshot fixtures
  // intact when there's no `main`.
  if (!fromStdlib) return true;
  if (d.kind === "LoweredFnDecl") {
    if (d.body === null) return true;                    // @extern import
    if (isMainMangled(d.mangled)) return true;
  }
  const decs = d.origin.decl.kind === "ImplDecl" ? NO_DECORATORS : d.origin.decl.decorators;
  return hasDecorator(decs, DEC.export)
      || hasDecorator(decs, DEC.test)
      || hasDecorator(decs, DEC.extern);
}
