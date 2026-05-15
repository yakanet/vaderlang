// Name resolution. Walks every expression / type / pattern, looks each
// identifier up against a scope chain, and records the resulting Symbol in
// side-tables that form a ResolvedProgram per module.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type * as A from "../parser/ast.ts";
import { isIfIsBinding, unreachableTypeExprInValuePosition, UNASSIGNED_NODE_ID } from "../parser/ast.ts";
import {
  materializeDefaultMembers, materializeIntrinsicMembers, materializeSamMembers,
  substituteTypeExpr,
} from "./materialize.ts";

import type { BuiltinScope } from "./builtins.ts";
import { isKnownDecorator } from "../parser/decorators.ts";
import { intrinsicSpec } from "../parser/intrinsics.ts";
import { checkReservedIdent, err } from "./diag.ts";
import type { Module } from "./module.ts";
import type { FieldRef, ResolvedProgram } from "./resolved-ast.ts";
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
  /** Cross-module trait-bound table populated by `bindTypeParam` from each
   *  type-param's bracketed bound (`[T: A & B]`). Keyed by
   *  `typeParam.symbol.id`, valued by the trait symbols the param must
   *  satisfy. Consumed by the typechecker for trait-method dispatch on
   *  bounded params and for call-site bound enforcement. */
  readonly typeParamBounds: Map<number, Symbol[]>;
  readonly diags: DiagnosticCollector;
}

interface MutableProgram {
  module: Module;
  source: A.Program;
  idents: Map<A.IdentExpr, Symbol>;
  /** Resolution table for `IdentExpr` nodes that appear in *type* position
   *  (struct field types, fn return types, bracketed bounds, etc.). Keyed
   *  by node identity, so it does not collide with `idents` despite both
   *  using the same `IdentExpr` shape : the parser creates distinct objects
   *  for expr-position vs type-position references. */
  types: Map<A.IdentExpr, Symbol>;
  params: Map<A.FnParam, Symbol>;
  /** Symbol per leaf SimpleBinding (or RestBinding for `...name`). For a
   *  simple `x := expr` the LetStmt's `binding` IS the SimpleBinding key ;
   *  for tuple destructure each leaf is keyed individually. */
  locals: Map<A.SimpleBinding | A.RestBinding, Symbol>;
  forIns: Map<A.ForStmt, Symbol>;
  typeParams: Map<A.TypeParam, Symbol>;
  typeParamTypes: Map<A.IdentExpr, Symbol>;
  fieldRefs: Map<A.FieldExpr, FieldRef>;
  patternBindings: Map<A.IsPattern | A.BindingPattern | A.StructPatternField, Symbol>;
  /** Binding introduced by `if x is T as <name>` — keyed by the `is`
   *  BinaryExpr that carried the `as`. The symbol is only in scope
   *  inside the matching IfExpr's then-block. */
  ifIsBindings: Map<A.BinaryExpr, Symbol>;
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
      fieldRefs: new Map(),
      patternBindings: new Map(),
      ifIsBindings: new Map(),
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
      if (decl.repr !== null) resolveType(decl.repr, scope, p, input);
      return;
    case "AssertDecl":
      // `@assert(cond)` only needs the condition expression resolved ;
      // there's no name to bind.
      resolveExpr(decl.condition, scope, p, input);
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
  if (decl.body !== null) resolveBlock(decl.body, scope, p, input);
}

function resolveStructDecl(decl: A.StructDecl, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  for (const tp of decl.typeParams) bindTypeParam(tp, scope, p, input);
  for (const field of decl.fields) {
    resolveType(field.type, scope, p, input);
    if (field.default !== null) resolveExpr(field.default, scope, p, input);
  }
}

function resolveTraitDecl(decl: A.TraitDecl, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  const scope = newScope(parent);
  for (const tp of decl.typeParams) bindTypeParam(tp, scope, p, input);
  for (const member of decl.members) resolveFnDecl(member, scope, p, input);
}

function resolveImplDecl(decl: A.ImplDecl, parent: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  // Two impl shapes :
  //   (1) Legacy : `Foo[T] implements Trait[T] { ... }` — `T` is borrowed
  //       transparently from the base struct's typeParams ; the impl has no
  //       typeParams of its own (`decl.typeParams.length === 0`).
  //   (2) Bounded generic (Option (a) of TODO §1.18b) : `[T: Bound] Foo[T]
  //       implements Trait[T] { ... }` — `T` is declared *here* with a
  //       local bound. Used to dedupe per-primitive impl families like
  //       `Range[T]`'s `Iterator` and `Contains` impls in std/core.
  //
  // For (1), we look up the base struct's existing typeParam symbols and
  // expose them under their names in the impl scope. For (2), we bind the
  // impl's own typeParams via `bindTypeParam` (same machinery as fn/struct
  // heads) so bounds flow into `typeParamBounds` for downstream dispatch.
  const scope = newScope(parent);
  if (decl.typeParams.length > 0) {
    for (const tp of decl.typeParams) bindTypeParam(tp, scope, p, input);
  } else if (decl.forType.kind === "GenericInstExpr" && decl.forType.callee.kind === "IdentExpr") {
    const baseSym = lookup(parent, decl.forType.callee.name);
    if (baseSym !== null && baseSym.source.kind === "struct") {
      for (const tp of baseSym.source.decl.typeParams) {
        const existing = input.typeParamSymbols.get(tp);
        if (existing !== undefined) scope.bindings.set(tp.name, existing);
      }
    }
  }
  resolveType(decl.forType, scope, p, input);
  const rawTraitSym = lookup(parent, decl.traitName);
  // Import-bindings : `import "..." { Bar }` brings `Bar` into scope as
  // a binding whose actual trait Symbol lives in the exporting module.
  // The orphan rule needs the *real* trait symbol's module, so follow
  // the redirect now and use that for both kind- and module-checks.
  const traitSym = rawTraitSym !== null ? resolveImportRedirect(rawTraitSym, input) : null;
  if (traitSym === null) {
    err(input.diags, "R2007", decl.traitNameSpan, `\`${decl.traitName}\``);
  } else if (traitSym.kind !== "trait") {
    err(input.diags, "R2009", decl.traitNameSpan, `\`${decl.traitName}\` is a ${traitSym.kind}`);
  }
  for (const ta of decl.traitArgs) resolveType(ta, scope, p, input);

  // Orphan rule (Layer 8e) : `Type implements Trait[Args]` is legal only
  // when the current module owns `Type` *or* `Trait`. Primitives are an
  // exception — any module can implement traits on them (Vader's
  // pragmatic deviation from Rust's stricter rule, since we lack the
  // newtype-pattern infrastructure to recover the use case otherwise).
  // The check is a straight `module === current` comparison.
  if (traitSym !== null && traitSym.kind === "trait") {
    const forSym = forTypeOwnerSymbol(decl.forType, p);
    const forIsPrimitive = forSym !== null && isPrimitiveOwner(forSym);
    const forIsLocal = forSym !== null && forSym.module === input.module.id;
    const traitIsLocal = traitSym.module === input.module.id;
    if (!forIsPrimitive && !forIsLocal && !traitIsLocal) {
      err(input.diags, "R2018", decl.span,
        `${decl.traitName} for ${forTypeDisplayName(decl.forType)} — neither type nor trait is owned by this module`);
    }
  }

  // Materialise SAM-synthetic members from the trait's single method before
  // walking bodies — `bindParam` needs the params to exist for `self`/`other`
  // references in the body to resolve.
  if (traitSym !== null && traitSym.source.kind === "trait") {
    materializeSamMembers(decl, traitSym.source.decl, input);
    materializeIntrinsicMembers(decl, traitSym.source.decl);
    // Layer 8d — fill in trait-default methods the impl didn't override.
    // Runs after the SAM / intrinsic materialisations so user-supplied
    // members and host-provided ones are already in `decl.members` and
    // `provided` (inside the helper) sees them.
    materializeDefaultMembers(decl, traitSym.source.decl);
  }

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
  checkReservedIdent(param.name, param.span, input.diags);
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
  checkReservedIdent(tp.name, tp.span, input.diags);
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
  // Layer 7e — bracketed bounds `[T: A & B & ...]` populate the
  // `typeParamBounds` table that downstream phases (trait-method dispatch,
  // call-site bound enforcement) consult.
  if (tp.bound !== null) {
    for (const traitSym of resolveTraitBoundExpr(tp.bound, scope)) {
      let bucket = input.typeParamBounds.get(sym.id);
      if (bucket === undefined) {
        bucket = [];
        input.typeParamBounds.set(sym.id, bucket);
      }
      if (!bucket.some((s) => s.id === traitSym.id)) bucket.push(traitSym);
    }
  }
}

/** Walk a bracketed bound expression and yield every trait symbol it
 *  references. Handles single-trait (`T: Foo`) and `&`-chain composition
 *  (`T: A & B & C`) ; non-trait references are silently skipped — the
 *  typechecker's bound-check pass surfaces a diagnostic at the call site
 *  if the resolved Type doesn't satisfy a trait that wasn't recorded here. */
function* resolveTraitBoundExpr(expr: A.TypeExpr, scope: Scope): Generator<Symbol> {
  if (expr.kind === "IdentExpr") {
    const sym = lookup(scope, expr.name);
    if (sym !== null && sym.kind === "trait") yield sym;
    return;
  }
  if (expr.kind === "BinaryExpr" && expr.op === "bitand") {
    yield* resolveTraitBoundExpr(expr.left as A.TypeExpr, scope);
    yield* resolveTraitBoundExpr(expr.right as A.TypeExpr, scope);
  }
}

function bindLocal(stmt: A.LetStmt, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  bindLetBinding(stmt, stmt.binding, scope, p, input);
}

function bindLetBinding(
  stmt: A.LetStmt, b: A.LetBinding, scope: Scope,
  p: MutableProgram, input: ResolveModuleInput,
): void {
  switch (b.kind) {
    case "SimpleBinding": {
      checkReservedIdent(b.name, b.nameSpan, input.diags);
      const sym = input.factory.make({
        kind: "local",
        name: b.name,
        module: input.module.id,
        visibility: "private",
        definedAt: b.nameSpan,
        source: { kind: "local", stmt, binding: b },
      });
      scope.bindings.set(b.name, sym);
      p.locals.set(b, sym);
      return;
    }
    case "TupleBinding":
      for (const e of b.elements) bindLetBinding(stmt, e, scope, p, input);
      return;
    case "WildcardBinding":
      return;
    case "RestBinding": {
      checkReservedIdent(b.name, b.nameSpan, input.diags);
      const sym = input.factory.make({
        kind: "local", name: b.name, module: input.module.id,
        visibility: "private", definedAt: b.nameSpan,
        source: { kind: "local", stmt, binding: b },
      });
      scope.bindings.set(b.name, sym);
      p.locals.set(b, sym);
      return;
    }
  }
}

/** For-type owner lookup used by the orphan rule. Returns the leaf symbol
 *  of the for-type expression — for `Foo` it's `Foo`'s symbol, for
 *  `Foo[T]` it's the callee's. Returns null when the for-type isn't a
 *  named-or-generic-instance head (e.g. `(T | U) implements …` doesn't
 *  parse today, but stays defensive). */
function forTypeOwnerSymbol(t: A.TypeExpr, p: MutableProgram): Symbol | null {
  if (t.kind === "IdentExpr") return p.types.get(t) ?? null;
  if (t.kind === "GenericInstExpr" && t.callee.kind === "IdentExpr") {
    return p.types.get(t.callee) ?? null;
  }
  return null;
}

function forTypeDisplayName(t: A.TypeExpr): string {
  if (t.kind === "IdentExpr") return t.name;
  if (t.kind === "GenericInstExpr" && t.callee.kind === "IdentExpr") return t.callee.name;
  return "?";
}

function isPrimitiveOwner(sym: Symbol): boolean {
  return sym.kind === "builtin-type";
}

function bindBinding(
  name: string, span: Span, origin: BindingOrigin,
  scope: Scope, input: ResolveModuleInput,
): Symbol {
  checkReservedIdent(name, span, input.diags);
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

// ============================================================================
// Types
// ============================================================================

function resolveType(t: A.TypeExpr, scope: Scope, p: MutableProgram, input: ResolveModuleInput): void {
  switch (t.kind) {
    case "IdentExpr": {
      // Implicit-dot named references (`is .Foo`) skip global lookup ; the
      // typecheck pass resolves them against the surrounding context
      // (scrutinee union variant, expected type, …).
      if (t.implicitDot === true) return;
      const sym = lookup(scope, t.name);
      if (sym === null) {
        // `$T` introductions whose name isn't in scope yet are silent : the
        // typecheck phase reports the unresolved type. Only a *plain* name
        // reference (`Foo`, no `$`) raises R2007 at the resolver stage.
        if (t.isTypeParamIntro !== true) {
          err(input.diags, "R2007", t.span, `\`${t.name}\``);
        }
        return;
      }
      // Type-param symbols land in their own side-table (preserved across
      // the 1.B.2 merge so the typechecker can keep its existing dispatch
      // shape — it can be unified into `types` in a later pass).
      if (sym.kind === "type-param") p.typeParamTypes.set(t, sym);
      else p.types.set(t, resolveImportRedirect(sym, input));
      return;
    }
    case "BinaryExpr":
      // Type-position `bitor` chain : walk operands as types.
      resolveType(t.left as A.TypeExpr, scope, p, input);
      resolveType(t.right as A.TypeExpr, scope, p, input);
      return;
    case "FnTypeExpr":
      for (const param of t.params) resolveType(param, scope, p, input);
      if (t.returnType !== null) resolveType(t.returnType, scope, p, input);
      return;
    case "ArrayTypeExpr":
      resolveType(t.element, scope, p, input);
      return;
    case "SeqLitExpr":
      for (const e of t.elements) resolveType(e as A.TypeExpr, scope, p, input);
      return;
    case "GenericInstExpr":
      // Type-position GenericInstExpr : the callee is either a bare ident
      // (`Foo[i32]`) or a qualified name (`op.Foo[i32]`) — both are
      // re-routed through `resolveType` so the same namespace-lookup path
      // handles them.
      if (t.callee.kind === "IdentExpr" || t.callee.kind === "FieldExpr") {
        resolveType(t.callee, scope, p, input);
      }
      for (const arg of t.typeArgs) resolveType(arg, scope, p, input);
      return;
    case "FieldExpr": {
      // Qualified type reference : `module.Type` where the leading ident
      // is a namespace import-binding. Mirrors `resolveFieldExpr`'s
      // value-side namespace path, but binds the resolved symbol into
      // `fieldRefs` so `lowerExprAsType` can consult it the same way the
      // value typer consults it for `module.value` access.
      if (t.target.kind !== "IdentExpr") {
        err(input.diags, "R2007", t.span, "qualified type names must start with an imported module name");
        return;
      }
      const targetSym = lookup(scope, t.target.name);
      if (targetSym === null) {
        err(input.diags, "R2007", t.target.span, `\`${t.target.name}\``);
        return;
      }
      // Record the leading ident's binding so downstream passes (incl.
      // the typer) can chase the namespace alias.
      p.idents.set(t.target, targetSym);
      if (targetSym.kind !== "import-binding") {
        err(input.diags, "R2007", t.target.span,
          `\`${t.target.name}\` is not an imported namespace`);
        return;
      }
      const importTarget = input.importTargets.get(targetSym.id);
      if (importTarget === undefined || importTarget.kind !== "module") {
        err(input.diags, "R2007", t.target.span,
          `\`${t.target.name}\` is not a module namespace`);
        return;
      }
      if (!isReachableInRestriction(targetSym, t.field)) {
        err(input.diags, "R2003", t.fieldSpan,
          `\`${t.field}\` is not in the scoped import list of \`${t.target.name}\``);
        return;
      }
      const exported = importTarget.module.symbols.get(t.field);
      if (exported === undefined) {
        err(input.diags, "R2003", t.fieldSpan,
          `\`${t.field}\` from module \`${importTarget.module.displayPath}\``);
        return;
      }
      if (exported.visibility === "private") {
        err(input.diags, "R2008", t.fieldSpan, `\`${t.field}\``);
        return;
      }
      p.fieldRefs.set(t, { kind: "namespace", symbol: exported });
      return;
    }
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
    case "IfExpr": {
      resolveExpr(expr.cond, scope, p, input);
      // `if x is T as a { ... }` — bind `a` only inside the then-block.
      // The else / else-if chain doesn't see the binding (mirrors
      // match-arm scoping).
      let thenScope = scope;
      if (isIfIsBinding(expr.cond)) {
        thenScope = newScope(scope);
        const sym = bindBinding(
          expr.cond.bindAs, expr.cond.span,
          { kind: "if-is-bind", cond: expr.cond },
          thenScope, input,
        );
        p.ifIsBindings.set(expr.cond, sym);
      }
      resolveBlock(expr.then, thenScope, p, input);
      if (expr.else !== null) {
        if (expr.else.kind === "IfExpr") resolveExpr(expr.else, scope, p, input);
        else resolveBlock(expr.else, scope, p, input);
      }
      return;
    }
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
      for (const item of expr.items) {
        if (item.kind === "field") resolveExpr(item.value, scope, p, input);
        else resolveExpr(item.expr, scope, p, input);
      }
      return;
    case "SeqLitExpr":
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
    case "IntrinsicCallExpr": {
      // Walk each arg in its declared shape : type-shape args go through
      // `resolveType` so the IdentExpr / chain references land in the
      // `types` side-table, value-shape args through `resolveExpr`.
      const spec = intrinsicSpec(expr.name);
      for (let i = 0; i < expr.args.length; i++) {
        const arg = expr.args[i]!;
        const kind = spec?.args[i] ?? "type";
        if (kind === "type") resolveType(arg, scope, p, input);
        else resolveExpr(arg, scope, p, input);
      }
      return;
    }
    case "FnTypeExpr":
      // Type-shaped expressions can legitimately appear in value
      // position as the body of a type alias (`t :: fn(i32) -> i32`).
      // Walk the inner type-position expressions through `resolveType`
      // so any type-name references resolve.
      for (const param of expr.params) resolveType(param, scope, p, input);
      if (expr.returnType !== null) resolveType(expr.returnType, scope, p, input);
      return;
    case "ArrayTypeExpr":
      resolveType(expr.element, scope, p, input);
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
        if (!isReachableInRestriction(targetSym, expr.field)) {
          err(input.diags, "R2003", expr.fieldSpan,
            `\`${expr.field}\` is not in the scoped import list of \`${(expr.target as A.IdentExpr).name}\``);
          return;
        }
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
        p.fieldRefs.set(expr, { kind: "namespace", symbol: exported });
        return;
      }
    }
  }
  // UFCS: `target.fn(args)` as sugar for `fn(target, args)`. Only record fn-like
  // names to avoid spurious entries on every struct-field or enum-variant access.
  // Type validation (first-param compatibility) is deferred to the typechecker.
  const freeSym = lookup(scope, expr.field);
  if (freeSym !== null && (freeSym.kind === "fn" || freeSym.kind === "import-binding")) {
    p.fieldRefs.set(expr, { kind: "ufcs-free", symbol: resolveImportRedirect(freeSym, input) });
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
        const sym = bindBinding(pat.bindAs, pat.span, { kind: "is-pattern", pattern: pat }, scope, input);
        p.patternBindings.set(pat, sym);
      }
      if (pat.inner !== null) bindPattern(pat.inner, scope, p, input);
      return;
    case "StructPattern":
      for (const f of pat.fields) {
        if (f.value.kind === "binding") {
          const sym = bindBinding(f.value.name, f.value.span, { kind: "struct-pattern", field: f }, scope, input);
          p.patternBindings.set(f, sym);
        } else {
          resolveExpr(f.value.value, scope, p, input);
        }
      }
      return;
    case "BindingPattern": {
      const sym = bindBinding(pat.name, pat.span, { kind: "binding-pattern", pattern: pat }, scope, input);
      p.patternBindings.set(pat, sym);
      return;
    }
    case "TuplePattern":
      for (const e of pat.elements) bindPattern(e, scope, p, input);
      return;
    case "WildcardPattern":
      return;
    case "EnumVariantPattern":
      return;
    case "LiteralPattern":
      // Literal value patterns carry an Expr — walk it so any identifier
      // inside (e.g. `const MAX :: 100 ; match x { MAX -> … }` once
      // constant-as-pattern lands) gets resolved. Today this is a no-op
      // for pure literal tokens, but the recursion costs nothing.
      resolveExpr(pat.value, scope, p, input);
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

/** For `name :: import "..." { a, b, c }` the namespace `name` only
 *  reveals `a`/`b`/`c` via `name.X`. Returns true when `field` is
 *  reachable through the namespace binding `sym` (always true for the
 *  unrestricted `name :: import "..."` form). */
function isReachableInRestriction(sym: Symbol, field: string): boolean {
  if (sym.source.kind !== "import") return true;
  const binding = sym.source.decl.binding;
  if (binding.kind !== "named-namespace" || binding.restricted === null) return true;
  for (const n of binding.restricted) {
    if ((n.alias ?? n.name) === field) return true;
  }
  return false;
}
