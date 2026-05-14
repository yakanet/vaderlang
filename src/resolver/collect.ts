// Collects top-level declarations of a single module into a symbol table.
// Duplicate names produce R2004; imports are recorded as bindings whose target
// modules will be resolved later by the wire pass.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";

import { checkReservedIdent, err } from "./diag.ts";
import type { ImportEntry, SourceFile } from "./module.ts";
import { resolveImportPath } from "./module.ts";
import type { ModuleId, Symbol } from "./symbol.ts";
import type { SymbolFactory } from "./symbol.ts";

export interface CollectInput {
  readonly moduleId: ModuleId;
  readonly files: readonly SourceFile[];
  readonly factory: SymbolFactory;
  readonly diags: DiagnosticCollector;
  readonly projectRoot: string | null;
  readonly stdlibRoot: string;
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
    // Local fn coexists with a same-named import : the local takes the
    // primary slot in `symbols` so unqualified references resolve to it,
    // and the import-binding joins `fnOverloads` so UFCS dispatch can pick
    // it when the receiver matches the imported fn's first param. The
    // import-binding's target is wired up only later (in `wireImports`) ;
    // a post-collect pass in `resolveLoadedProject` follows the redirect
    // and replaces each entry with its concrete fn before typecheck runs.
    fnOverloads.get(decl.name)!.push(existing);
    symbols.set(decl.name, sym);
    return;
  }
  if (existing.kind !== "fn") {
    // Name already taken by a non-fn (e.g. a struct/const). Real conflict.
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
    fromFile,
    projectRoot: input.projectRoot,
    stdlibRoot: input.stdlibRoot,
  });
  if (resolvedTo === null) err(input.diags, "R2001", decl.span, `\`${decl.path}\``);
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
