// Collects top-level declarations of a single module into a symbol table.
// Duplicate names produce R2004; imports are recorded as bindings whose target
// modules will be resolved later by the wire pass.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";

import { err } from "./diag.ts";
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
  readonly imports: readonly ImportEntry[];
}

export function collectModuleSymbols(input: CollectInput): CollectResult {
  const symbols = new Map<string, Symbol>();
  const imports: ImportEntry[] = [];

  for (const file of input.files) {
    for (const decl of file.program.decls) {
      switch (decl.kind) {
        case "ImportDecl":
          collectImport(decl, file.path, input, imports, symbols);
          break;
        case "FnDecl":
          addSymbol(symbols, input, decl.name, decl.nameSpan, decl.visibility, "fn", { kind: "fn", decl });
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
      }
    }
  }

  return { symbols, imports };
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
    case "namespace": {
      // SPEC §11: bare `import "std/io"` exposes the path's last segment.
      const segments = decl.path.split("/");
      const local = segments[segments.length - 1] ?? decl.path;
      bindImport(symbols, input, local, decl, null, decl.span);
      break;
    }
    case "alias":
      bindImport(symbols, input, decl.binding.alias, decl, null, decl.span);
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
