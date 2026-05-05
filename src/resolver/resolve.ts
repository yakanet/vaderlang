// Name resolution. Walks every expression / type / pattern, looks each
// identifier up against a scope chain, and records the resulting Symbol in
// side-tables that form a ResolvedProgram per module.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type * as A from "../parser/ast.ts";

import type { BuiltinScope } from "./builtins.ts";
import { isKnownDecorator } from "../parser/decorators.ts";
import { err } from "./diag.ts";
import type { Module } from "./module.ts";
import type { ResolvedProgram } from "./resolved-ast.ts";
import type { BindingOrigin, ModuleId, Symbol, SymbolFactory } from "./symbol.ts";
import type { ImportTargetTable } from "./wire.ts";

export interface ResolveModuleInput {
  readonly module: Module;
  readonly modules: ReadonlyMap<ModuleId, Module>;
  readonly importTargets: ImportTargetTable;
  readonly builtins: BuiltinScope;
  readonly coreModule: Module | null;     // std/core, auto-imported except in std/core itself
  readonly factory: SymbolFactory;
  /** Cross-module map from a `TypeParam` AST node to its canonical Symbol.
   *  Populated by `bindTypeParam`; consumed by `resolveImplDecl` so generic
   *  impls reuse the base struct's existing typeParam symbol rather than
   *  minting a fresh one (which would clobber the struct's own field
   *  resolutions). */
  readonly typeParamSymbols: Map<A.TypeParam, Symbol>;
  readonly diags: DiagnosticCollector;
}

interface MutableProgram {
  module: Module;
  source: A.Program;
  idents: Map<A.IdentExpr, Symbol>;
  types: Map<A.NamedType, Symbol>;
  params: Map<A.FnParam, Symbol>;
  locals: Map<A.LetStmt, Symbol>;
  forIns: Map<A.ForStmt, Symbol>;
  typeParams: Map<A.TypeParam, Symbol>;
  typeParamTypes: Map<A.TypeParamType, Symbol>;
  fields: Map<A.FieldExpr, Symbol>;
  ufcsFreeResolutions: Map<A.FieldExpr, Symbol>;
}

interface Scope {
  readonly parent: Scope | null;
  readonly bindings: Map<string, Symbol>;
}

function newScope(parent: Scope | null): Scope {
  return { parent, bindings: new Map() };
}

function lookup(scope: Scope, name: string): Symbol | null {
  for (let s: Scope | null = scope; s !== null; s = s.parent) {
    const v = s.bindings.get(name);
    if (v !== undefined) return v;
  }
  return null;
}

export function resolveModule(input: ResolveModuleInput): ResolvedProgram[] {
  const out: ResolvedProgram[] = [];

  // Root scope: builtins + std/core publics + this module's own symbols.
  const root = newScope(null);
  for (const [name, sym] of input.builtins.types) root.bindings.set(name, sym);
  if (input.coreModule !== null) {
    for (const [name, sym] of input.coreModule.symbols) {
      if (sym.visibility === "public") root.bindings.set(name, sym);
    }
  }
  for (const [name, sym] of input.module.symbols) root.bindings.set(name, sym);

  for (const file of input.module.files) {
    const program: MutableProgram = {
      module: input.module,
      source: file.program,
      idents: new Map(),
      types: new Map(),
      params: new Map(),
      locals: new Map(),
      forIns: new Map(),
      typeParams: new Map(),
      typeParamTypes: new Map(),
      fields: new Map(),
      ufcsFreeResolutions: new Map(),
    };
    for (const decl of file.program.decls) {
      resolveDecl(decl, root, program, input);
    }
    out.push(program);
  }

  return out;
}

function resolveDecl(decl: A.Decl, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  validateDecorators(decl, scope, p, input);
  switch (decl.kind) {
    case "ImportDecl":
      // Already handled at collect+wire time.
      return;
    case "FnDecl":
      resolveFnDecl(decl, scope, p, input);
      return;
    case "StructDecl":
      resolveStructDecl(decl, scope, p, input);
      return;
    case "TraitDecl":
      resolveTraitDecl(decl, scope, p, input);
      return;
    case "ImplDecl":
      resolveImplDecl(decl, scope, p, input);
      return;
    case "TypeAliasDecl":
      resolveTypeAliasDecl(decl, scope, p, input);
      return;
    case "ConstDecl":
      resolveConstDecl(decl, scope, p, input);
      return;
    case "EnumDecl":
      return;
  }
}

function validateDecorators(decl: A.Decl, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  for (const dec of decl.decorators) {
    if (!isKnownDecorator(dec.name)) err(input.diags, "R2010", dec.span, `\`@${dec.name}\``);
    for (const arg of dec.args) resolveExpr(arg, scope, p, input);
  }
}

function resolveFnDecl(decl: A.FnDecl, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  for (const tp of decl.typeParams) bindTypeParam(tp, scope, p, input);
  for (const param of decl.params) bindParam(param, decl, scope, p, input);
  if (decl.returnType !== null) resolveType(decl.returnType, scope, p, input);
  for (const w of decl.whereClauses) resolveWhereClause(w, scope, p, input);
  if (decl.body !== null) resolveBlock(decl.body, scope, p, input);
}

function resolveStructDecl(decl: A.StructDecl, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  for (const tp of decl.typeParams) bindTypeParam(tp, scope, p, input);
  for (const w of decl.whereClauses) resolveWhereClause(w, scope, p, input);
  for (const field of decl.fields) resolveType(field.type, scope, p, input);
}

function resolveTraitDecl(decl: A.TraitDecl, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  for (const tp of decl.typeParams) bindTypeParam(tp, scope, p, input);
  for (const member of decl.members) resolveFnDecl(member, scope, p, input);
}

function resolveImplDecl(decl: A.ImplDecl, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  // Generic impls (`Foo(T) implements Trait(T) { ... }`) reuse the base
  // struct's type parameters. Look up the EXISTING typeParam symbols (don't
  // re-bind, which would clobber `p.typeParams[tp]` and break the struct's
  // own field references) and expose them under their names in the impl
  // scope so references in forType / trait args / member bodies resolve.
  const scope = newScope(parent);
  if (decl.forType.kind === "GenericInstType") {
    const baseSym = lookup(parent, decl.forType.base.name);
    if (baseSym !== null && baseSym.source.kind === "struct") {
      for (const tp of baseSym.source.decl.typeParams) {
        const existing = input.typeParamSymbols.get(tp);
        if (existing !== undefined) scope.bindings.set(tp.name, existing);
      }
    }
  }
  resolveType(decl.forType, scope, p, input);
  const traitSym = lookup(parent, decl.traitName);
  if (traitSym === null) {
    err(input.diags, "R2007", decl.traitNameSpan, `\`${decl.traitName}\``);
  } else if (traitSym.kind !== "trait") {
    err(input.diags, "R2009", decl.traitNameSpan, `\`${decl.traitName}\` is a ${traitSym.kind}`);
  }
  for (const ta of decl.traitArgs) resolveType(ta, scope, p, input);
  for (const member of decl.members) resolveFnDecl(member, scope, p, input);
}

function resolveTypeAliasDecl(decl: A.TypeAliasDecl, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  for (const tp of decl.typeParams) bindTypeParam(tp, scope, p, input);
  resolveType(decl.aliased, scope, p, input);
}

function resolveConstDecl(decl: A.ConstDecl, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  if (decl.type !== null) resolveType(decl.type, scope, p, input);
  resolveExpr(decl.value, scope, p, input);
}

// ============================================================================
// Bindings
// ============================================================================

function bindParam(
  param: A.FnParam, fn: A.FnDecl | A.LambdaExpr, scope: Scope, p: MutableProgram, input: ResolveModuleInput,
): void {
  if (param.type !== null) resolveType(param.type, scope, p, input);
  if (param.defaultValue !== null) resolveExpr(param.defaultValue, scope, p, input);
  const sym = input.factory.make({
    kind: "param",
    name: param.name,
    module: input.module.id,
    visibility: "private",
    definedAt: param.span,
    source: { kind: "param", param, fn },
  });
  scope.bindings.set(param.name, sym);
  p.params.set(param, sym);
}

function bindTypeParam(tp: A.TypeParam, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  if (tp.bound !== null) resolveType(tp.bound, scope, p, input);
  const sym = input.factory.make({
    kind: "type-param",
    name: tp.name,
    module: input.module.id,
    visibility: "private",
    definedAt: tp.span,
    source: { kind: "type-param", param: tp },
  });
  scope.bindings.set(tp.name, sym);
  p.typeParams.set(tp, sym);
  input.typeParamSymbols.set(tp, sym);
}

function bindLocal(stmt: A.LetStmt, scope: Scope, p: MutableProgram, input: ResolveModuleInput): Symbol {
  const sym = input.factory.make({
    kind: "local",
    name: stmt.name,
    module: input.module.id,
    visibility: "private",
    definedAt: stmt.nameSpan,
    source: { kind: "local", stmt },
  });
  scope.bindings.set(stmt.name, sym);
  p.locals.set(stmt, sym);
  return sym;
}

function bindBinding(
  name: string, span: Span, origin: BindingOrigin,
  scope: Scope, input: ResolveModuleInput,
): Symbol {
  const sym = input.factory.make({
    kind: "binding",
    name,
    module: input.module.id,
    visibility: "private",
    definedAt: span,
    source: { kind: "binding", origin },
  });
  scope.bindings.set(name, sym);
  return sym;
}

function resolveWhereClause(w: A.WhereClause, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  if (lookup(scope, w.typeName) === null) {
    err(input.diags, "R2006", w.span, `\`${w.typeName}\` (in \`where\`)`);
  }
  if (lookup(scope, w.traitName) === null) {
    err(input.diags, "R2007", w.span, `\`${w.traitName}\` (trait bound)`);
  }
}

// ============================================================================
// Types
// ============================================================================

function resolveType(t: A.TypeExpr, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  switch (t.kind) {
    case "NamedType": {
      const sym = lookup(scope, t.name);
      if (sym === null) err(input.diags, "R2007", t.span, `\`${t.name}\``);
      else p.types.set(t, resolveImportRedirect(sym, input));
      return;
    }
    case "TypeParamType": {
      const sym = lookup(scope, t.name);
      if (sym !== null && sym.kind === "type-param") p.typeParamTypes.set(t, sym);
      return;
    }
    case "UnionType":
      for (const v of t.variants) resolveType(v, scope, p, input);
      return;
    case "FnTypeExpr":
      for (const param of t.params) resolveType(param, scope, p, input);
      if (t.returnType !== null) resolveType(t.returnType, scope, p, input);
      return;
    case "ArrayTypeExpr":
      resolveType(t.element, scope, p, input);
      return;
    case "GenericInstType":
      resolveType(t.base, scope, p, input);
      for (const arg of t.args) resolveType(arg, scope, p, input);
      return;
  }
}

// ============================================================================
// Statements / expressions
// ============================================================================

function resolveBlock(block: A.BlockExpr, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  for (const stmt of block.stmts) resolveStmt(stmt, scope, p, input);
  if (block.trailing !== null) resolveExpr(block.trailing, scope, p, input);
}

function resolveStmt(stmt: A.Stmt, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  switch (stmt.kind) {
    case "LetStmt":
      resolveExpr(stmt.value, scope, p, input);
      if (stmt.type !== null) resolveType(stmt.type, scope, p, input);
      bindLocal(stmt, scope, p, input);
      return;
    case "AssignStmt":
      resolveExpr(stmt.target, scope, p, input);
      resolveExpr(stmt.value, scope, p, input);
      return;
    case "ExprStmt":
      resolveExpr(stmt.expr, scope, p, input);
      return;
    case "ReturnStmt":
      if (stmt.value !== null) resolveExpr(stmt.value, scope, p, input);
      return;
    case "ForStmt":
      resolveForStmt(stmt, scope, p, input);
      return;
    case "BreakStmt":
    case "ContinueStmt":
      return;
    case "DeferStmt":
      if (stmt.body.kind === "BlockExpr") resolveBlock(stmt.body, scope, p, input);
      else resolveStmt(stmt.body, scope, p, input);
      return;
  }
}

function resolveForStmt(stmt: A.ForStmt, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  switch (stmt.form.kind) {
    case "infinite":
      break;
    case "while":
      resolveExpr(stmt.form.cond, scope, p, input);
      break;
    case "in": {
      resolveExpr(stmt.form.iter, scope, p, input);
      const sym = bindBinding(stmt.form.binding, stmt.form.bindingSpan, { kind: "for-in", stmt }, scope, input);
      p.forIns.set(stmt, sym);
      break;
    }
  }
  resolveBlock(stmt.body, scope, p, input);
}

function resolveExpr(expr: A.Expr, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  switch (expr.kind) {
    case "IntLitExpr":
    case "FloatLitExpr":
    case "BoolLitExpr":
    case "NullLitExpr":
    case "CharLitExpr":
      return;
    case "StringLitExpr":
      for (const part of expr.parts) {
        if (part.kind === "interp") resolveExpr(part.expr, scope, p, input);
      }
      return;
    case "IdentExpr": {
      const sym = lookup(scope, expr.name);
      if (sym === null) err(input.diags, "R2006", expr.span, `\`${expr.name}\``);
      else p.idents.set(expr, resolveImportRedirect(sym, input));
      return;
    }
    case "CallExpr":
      resolveExpr(expr.callee, scope, p, input);
      for (const arg of expr.args) resolveExpr(arg.value, scope, p, input);
      return;
    case "FieldExpr":
      resolveFieldExpr(expr, scope, p, input);
      return;
    case "IndexExpr":
      resolveExpr(expr.target, scope, p, input);
      resolveExpr(expr.index, scope, p, input);
      return;
    case "UnaryExpr":
      resolveExpr(expr.operand, scope, p, input);
      return;
    case "BinaryExpr":
      resolveExpr(expr.left, scope, p, input);
      resolveExpr(expr.right, scope, p, input);
      return;
    case "IfExpr":
      resolveExpr(expr.cond, scope, p, input);
      resolveBlock(expr.then, scope, p, input);
      if (expr.else !== null) {
        if (expr.else.kind === "IfExpr") resolveExpr(expr.else, scope, p, input);
        else resolveBlock(expr.else, scope, p, input);
      }
      return;
    case "MatchExpr":
      resolveMatchExpr(expr, scope, p, input);
      return;
    case "BlockExpr":
      resolveBlock(expr, scope, p, input);
      return;
    case "LambdaExpr":
      resolveLambda(expr, scope, p, input);
      return;
    case "StructLitExpr":
      resolveType(expr.typeName, scope, p, input);
      for (const f of expr.fields) resolveExpr(f.value, scope, p, input);
      return;
    case "ArrayLitExpr":
      for (const el of expr.elements) resolveExpr(el, scope, p, input);
      return;
    case "RangeExpr":
      resolveExpr(expr.lower, scope, p, input);
      resolveExpr(expr.upper, scope, p, input);
      return;
    case "TryExpr":
      resolveExpr(expr.inner, scope, p, input);
      return;
    case "CastExpr":
      resolveType(expr.target, scope, p, input);
      resolveExpr(expr.value, scope, p, input);
      return;
    case "GenericInstExpr":
      resolveExpr(expr.callee, scope, p, input);
      for (const arg of expr.typeArgs) resolveType(arg, scope, p, input);
      return;
    case "DotVariantExpr":
      return;
  }
}

function resolveFieldExpr(expr: A.FieldExpr, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  resolveExpr(expr.target, scope, p, input);
  // Module-namespace lookup: `module.symbol` form.
  if (expr.target.kind === "IdentExpr") {
    const targetSym = p.idents.get(expr.target);
    if (targetSym !== undefined && targetSym.kind === "import-binding") {
      const importTarget = input.importTargets.get(targetSym.id);
      if (importTarget !== undefined && importTarget.kind === "module") {
        const exported = importTarget.module.symbols.get(expr.field);
        if (exported === undefined) {
          err(input.diags, "R2003", expr.fieldSpan,
            `\`${expr.field}\` from module \`${importTarget.module.displayPath}\``);
          return;
        }
        if (exported.visibility === "private") {
          err(input.diags, "R2008", expr.fieldSpan, `\`${expr.field}\``);
          return;
        }
        p.fields.set(expr, exported);
        return;
      }
    }
  }
  // UFCS: `target.fn(args)` as sugar for `fn(target, args)`. Only record fn-like
  // names to avoid spurious entries on every struct-field or enum-variant access.
  // Type validation (first-param compatibility) is deferred to the typechecker.
  const freeSym = lookup(scope, expr.field);
  if (freeSym !== null && (freeSym.kind === "fn" || freeSym.kind === "import-binding")) {
    p.ufcsFreeResolutions.set(expr, resolveImportRedirect(freeSym, input));
  }
}

function resolveLambda(expr: A.LambdaExpr, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  for (const param of expr.params) bindParam(param, expr, scope, p, input);
  if (expr.returnType !== null) resolveType(expr.returnType, scope, p, input);
  resolveBlock(expr.body, scope, p, input);
}

function resolveMatchExpr(expr: A.MatchExpr, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  resolveExpr(expr.scrutinee, parent, p, input);
  for (const arm of expr.arms) {
    const armScope = newScope(parent);
    bindPattern(arm.pattern, armScope, p, input);
    if (arm.guard !== null) resolveExpr(arm.guard, armScope, p, input);
    resolveExpr(arm.body, armScope, p, input);
  }
}

function bindPattern(pat: A.Pattern, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  switch (pat.kind) {
    case "IsPattern":
      resolveType(pat.type, scope, p, input);
      if (pat.bindAs !== null) {
        bindBinding(pat.bindAs, pat.span, { kind: "is-pattern", pattern: pat }, scope, input);
      }
      if (pat.inner !== null) bindPattern(pat.inner, scope, p, input);
      return;
    case "StructPattern":
      for (const f of pat.fields) {
        if (f.value.kind === "binding") {
          bindBinding(f.value.name, f.value.span, { kind: "struct-pattern", field: f }, scope, input);
        } else {
          resolveExpr(f.value.value, scope, p, input);
        }
      }
      return;
    case "BindingPattern":
      bindBinding(pat.name, pat.span, { kind: "binding-pattern", pattern: pat }, scope, input);
      return;
    case "WildcardPattern":
      return;
    case "EnumVariantPattern":
      return;
  }
}

// ============================================================================
// Helpers
// ============================================================================

/** Follow an import-binding to its concrete export target, when known. */
function resolveImportRedirect(sym: Symbol, input: ResolveModuleInput): Symbol {
  if (sym.kind !== "import-binding") return sym;
  const target = input.importTargets.get(sym.id);
  if (target === undefined || target.kind !== "symbol") return sym;
  return target.symbol;
}
