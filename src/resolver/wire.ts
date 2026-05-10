// Wires each import-binding symbol to its concrete target in the referenced
// module. Produces a side-table keyed by SymbolId so the symbol graph itself
// stays immutable.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";

import { err } from "./diag.ts";
import type { Module } from "./module.ts";
import type { ModuleId, Symbol, SymbolId } from "./symbol.ts";

export type ImportTarget =
  | { readonly kind: "module"; readonly module: Module }
  | { readonly kind: "symbol"; readonly symbol: Symbol; readonly module: Module }
  | { readonly kind: "missing" };

export type ImportTargetTable = ReadonlyMap<SymbolId, ImportTarget>;

export function wireImports(
  modules: ReadonlyMap<ModuleId, Module>,
  diags: DiagnosticCollector,
): ImportTargetTable {
  const out = new Map<SymbolId, ImportTarget>();

  for (const mod of modules.values()) {
    const pathToModule = buildImportIndex(mod, modules);

    // Collect every import-binding to wire — `symbols` covers the common
    // case, but a same-named local fn pushes the import-binding into the
    // `fnOverloads` bucket instead (Layer 8h overload-with-imports). Walk
    // both ; dedupe by symbol id so we don't wire the same binding twice
    // when it lives in both places.
    const seen = new Set<SymbolId>();
    const imports: Symbol[] = [];
    for (const sym of mod.symbols.values()) {
      if (sym.source.kind === "import" && !seen.has(sym.id)) {
        seen.add(sym.id);
        imports.push(sym);
      }
    }
    for (const bucket of mod.fnOverloads.values()) {
      for (const sym of bucket) {
        if (sym.source.kind === "import" && !seen.has(sym.id)) {
          seen.add(sym.id);
          imports.push(sym);
        }
      }
    }

    for (const sym of imports) {
      if (sym.source.kind !== "import") continue;
      const decl = sym.source.decl;
      const targetModule = pathToModule.get(decl.path) ?? null;

      if (targetModule === null) {
        // Loader already emitted R2001 for unresolved imports.
        out.set(sym.id, { kind: "missing" });
        continue;
      }

      if (sym.source.importedName === null) {
        out.set(sym.id, { kind: "module", module: targetModule });
        continue;
      }

      const named = sym.source.importedName;
      const exported = targetModule.symbols.get(named);
      if (exported === undefined) {
        err(diags, "R2003", sym.definedAt ?? decl.span, `\`${named}\` from \`${decl.path}\``);
        out.set(sym.id, { kind: "missing" });
        continue;
      }
      if (exported.visibility === "private") {
        err(diags, "R2008", sym.definedAt ?? decl.span,
          `\`${named}\` is not exported from \`${decl.path}\``,
          exported.definedAt !== null ? [{ span: exported.definedAt, label: "declared here without `export`" }] : undefined);
        out.set(sym.id, { kind: "missing" });
        continue;
      }
      out.set(sym.id, { kind: "symbol", symbol: exported, module: targetModule });
    }
  }

  return out;
}

function buildImportIndex(
  fromModule: Module,
  modules: ReadonlyMap<ModuleId, Module>,
): Map<string, Module> {
  const index = new Map<string, Module>();
  for (const imp of fromModule.imports) {
    if (imp.resolvedTo === null) continue;
    const m = modules.get(imp.resolvedTo);
    if (m !== undefined) index.set(imp.path, m);
  }
  return index;
}
