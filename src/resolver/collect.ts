// Collects top-level declarations of a single module into a symbol table.
// Duplicate names produce R2004; imports are recorded as bindings whose target
// modules will be resolved later by the wire pass.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";

import { checkReservedIdent, err } from "./diag.ts";
import type { ModuleIndex } from "./discover.ts";
import type { ImportEntry, SourceFile } from "./module.ts";
import { resolveImportPath } from "./module.ts";
import type { ModuleId, Symbol } from "./symbol.ts";
import type { SymbolFactory } from "./symbol.ts";

export interface CollectInput {
  readonly moduleId: ModuleId;
  /** Module name of the file(s) being collected — used by import
   *  resolution to detect self-imports and the implicit-prelude exemption. */
  readonly moduleName: string;
  readonly files: readonly SourceFile[];
  readonly factory: SymbolFactory;
  readonly diags: DiagnosticCollector;
  /** Project-wide module index for name-lookup-based import resolution. */
  readonly index: ModuleIndex;
}

export interface CollectResult {
  readonly symbols: ReadonlyMap<string, Symbol>;
  readonly fnOverloads: ReadonlyMap<string, readonly Symbol[]>;
  readonly imports: readonly ImportEntry[];
}

export function collectModuleSymbols(input: CollectInput): CollectResult {
  const symbols = new Map<string, Symbol>();
  const fnOverloads = new Map<string, Symbol[]>();
  const imports: ImportEntry[] = [];

  for (const file of input.files) {
    for (const decl of file.program.decls) {
      switch (decl.kind) {
        case "ImportDecl":
          collectImport(decl, file.path, input, imports, symbols);
          break;
        case "FnDecl":
          addFnSymbol(symbols, fnOverloads, input, decl);
          break;
        case "StructDecl":
          addSymbol(symbols, input, decl.name, decl.nameSpan, decl.visibility, "struct", { kind: "struct", decl });
          break;
        case "EnumDecl":
          addSymbol(symbols, input, decl.name, decl.nameSpan, decl.visibility, "enum", { kind: "enum", decl });
          break;
        case "TraitDecl":
          addSymbol(symbols, input, decl.name, decl.nameSpan, decl.visibility, "trait", { kind: "trait", decl });
          break;
        case "TypeAliasDecl":
          addSymbol(symbols, input, decl.name, decl.nameSpan, decl.visibility, "type-alias", { kind: "type-alias", decl });
          break;
        case "ConstDecl":
          addSymbol(symbols, input, decl.name, decl.nameSpan, decl.visibility, "const", { kind: "const", decl });
          break;
        case "ImplDecl":
          // Impl blocks contribute methods to a type, not new top-level names.
          // Their wiring (forType, traitName) is the resolver's wiring pass concern.
          break;
        case "AssertDecl":
          // `@assert` doesn't introduce a name ; it's evaluated standalone
          // at the comptime stage.
          break;
      }
    }
  }

  return { symbols, fnOverloads, imports };
}

/** Allow multiple `fn` decls under the same module name (overloading). The
 *  first wins as the primary entry in `symbols`; subsequent ones append to
 *  the overload set. Truly-conflicting overloads (same first-param type)
 *  are rejected at typecheck time (T3032), since the resolver doesn't yet
 *  know parameter types. */
function addFnSymbol(
  symbols: Map<string, Symbol>,
  fnOverloads: Map<string, Symbol[]>,
  input: CollectInput,
  decl: A.FnDecl,
): void {
  checkReservedIdent(decl.name, decl.nameSpan, input.diags);
  // `main` is the program entry point and is always treated as exported,
  // so consumers (runtime, embedders, cross-module references) can reach it
  // without a redundant `export` keyword.
  const visibility = decl.name === "main" ? "public" : decl.visibility;
  const sym = input.factory.make({
    kind: "fn", name: decl.name, module: input.moduleId,
    visibility, definedAt: decl.nameSpan,
    source: { kind: "fn", decl },
  });
  const bucket = fnOverloads.get(decl.name);
  if (bucket === undefined) {
    fnOverloads.set(decl.name, [sym]);
  } else {
    bucket.push(sym);
  }
  // Keep the FIRST decl as the primary symbol — most callers want one stable
  // entry point. Other overloads are visible only via `fnOverloads`.
  if (!symbols.has(decl.name)) {
    symbols.set(decl.name, sym);
    return;
  }
  const existing = symbols.get(decl.name)!;
  if (existing.kind === "import-binding") {
    // Local fn wins the primary slot for unqualified lookups ; the
    // import-binding joins the overload set so UFCS dispatch can still
    // pick it when the receiver matches the imported fn's first param.
    fnOverloads.get(decl.name)!.push(existing);
    symbols.set(decl.name, sym);
    return;
  }
  if (existing.kind !== "fn") {
    // Name already taken by a non-fn (e.g. a struct/const).
    // Cross-file : silently first-wins.
    //   ⚠ Deviation from docs/MODULE_SYSTEM.md §1.6 / decision #28
    //   which mandates R2026 ("hard error") for non-fn cross-file
    //   duplicates. Today's self-host carries ~7 such latent collisions
    //   (`vader/vm/{ScopeEntry,PendingBranch}`, `vader/typecheck/
    //   {Color,Wrap,Display,Point}`, `vader/lower/CellInit`) that this
    //   branch masks. Removing the branch requires either renaming the
    //   latent collisions or revising decision #28.
    // Intra-file : real conflict, fires R2004.
    if (existing.definedAt !== null && existing.definedAt.start.file !== decl.nameSpan.start.file) return;
    err(input.diags, "R2004", decl.nameSpan, `\`${decl.name}\` already declared in this module`,
      existing.definedAt !== null ? [{ span: existing.definedAt, label: "previous declaration" }] : undefined);
  }
}

function addSymbol(
  symbols: Map<string, Symbol>,
  input: CollectInput,
  name: string,
  span: A.FnDecl["nameSpan"],
  visibility: A.Visibility,
  kind: "fn" | "struct" | "enum" | "trait" | "type-alias" | "const",
  source: Symbol["source"],
): void {
  checkReservedIdent(name, span, input.diags);
  const existing = symbols.get(name);
  if (existing !== undefined) {
    // A real decl wins over an import-binding of the same name. Files are
    // collected in alphabetical order, so a sibling file's self-import
    // binding (already flagged R2024 by the resolver) can land first and
    // would otherwise shadow the local export.
    if (existing.kind === "import-binding") {
      symbols.set(name, input.factory.make({
        kind, name, module: input.moduleId, visibility, definedAt: span, source,
      }));
      return;
    }
    // Cross-file silent first-wins — see `addFnSymbol` for the §1.6
    // deviation rationale. Intra-file : R2004.
    if (existing.definedAt !== null && existing.definedAt.start.file !== span.start.file) return;
    err(input.diags, "R2004", span, `\`${name}\` already declared in this module`,
      existing.definedAt !== null ? [{ span: existing.definedAt, label: "previous declaration" }] : undefined);
    return;
  }
  symbols.set(name, input.factory.make({
    kind, name, module: input.moduleId, visibility, definedAt: span, source,
  }));
}

function collectImport(
  decl: A.ImportDecl,
  fromFile: string,
  input: CollectInput,
  imports: ImportEntry[],
  symbols: Map<string, Symbol>,
): void {
  if (decl.path.length === 0) {
    err(input.diags, "R2002", decl.span);
    return;
  }
  const resolvedTo = resolveImportPath(decl.path, {
    index: input.index,
    fromModuleName: input.moduleName,
    span: decl.span,
    diags: input.diags,
  });
  imports.push({ span: decl.span, fromFile, path: decl.path, resolvedTo });

  switch (decl.binding.kind) {
    case "named-namespace":
      // `name :: import "..."` (with optional `{ a, b, c }` scope list).
      // Binds `name` as a namespace ; the `restricted` list, when set,
      // is consulted at field-lookup time to limit reachable members.
      bindImport(symbols, input, decl.binding.name, decl, null, decl.span);
      break;
    case "destructure":
      for (const n of decl.binding.names) {
        const local = n.alias ?? n.name;
        bindImport(symbols, input, local, decl, n.name, n.span);
      }
      break;
  }
}

function bindImport(
  symbols: Map<string, Symbol>,
  input: CollectInput,
  localName: string,
  decl: A.ImportDecl,
  importedName: string | null,
  span: A.ImportDecl["span"],
): void {
  checkReservedIdent(localName, span, input.diags);
  const existing = symbols.get(localName);
  if (existing !== undefined) {
    // Duplicate import-binding silent first-wins — same §1.5 deviation
    // as the non-fn branches in `addFnSymbol`. Shadowing a non-import
    // binding (local fn vs import) still trips R2011.
    if (existing.kind === "import-binding") return;
    err(input.diags, "R2011", span, `\`${localName}\``,
      existing.definedAt !== null ? [{ span: existing.definedAt, label: "previous binding" }] : undefined);
    return;
  }
  symbols.set(localName, input.factory.make({
    kind: "import-binding",
    name: localName,
    module: input.moduleId,
    visibility: "private",
    definedAt: span,
    source: { kind: "import", decl, target: null, importedName },
  }));
}
