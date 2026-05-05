// Type-check a ResolvedProgram, producing a TypedProgram populated with the
// inferred / declared types of every expression, type-expression, and binding.
//
// Inference is bidirectional, TS/Swift-style:
//   - bottom-up: compute the natural type of an expression
//   - top-down: when an `expected` type is propagated, check assignability and
//     resolve free numeric literals against it
// No global Hindley-Milner; top-level fn signatures must be fully annotated
// (SPEC §4 "Type inference").

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type * as A from "../parser/ast.ts";
import type { ResolvedProgram } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import { declOf } from "../resolver/symbol.ts";

import { err } from "./diag.ts";
import type { ImplRegistry } from "./impls.ts";
import type { TypedProgram } from "./typed-ast.ts";
import type { Type } from "./types.ts";
import {
  CORE_TRAITS, TY, defaultIfFree, displayType, equalsType, isAssignable, isFloat,
  isInteger, isNumeric, isPrimitive, substitute, unionOf,
} from "./types.ts";

/** Tables shared across modules — populated by declareTypes, consumed by check bodies. */
export interface Globals {
  readonly declTypes: Map<A.Decl, Type>;
  readonly paramTypes: Map<A.FnParam, Type>;
  readonly typeExprTypes: Map<A.TypeExpr, Type>;
  /** Auto-imported std/core symbols, looked up for Display / Error / Iterator etc. */
  coreSymbols: ReadonlyMap<string, Symbol> | null;
}

export function newGlobals(): Globals {
  return {
    declTypes: new Map(), paramTypes: new Map(), typeExprTypes: new Map(),
    coreSymbols: null,
  };
}

interface MutableTyped {
  readonly resolved: ResolvedProgram;
  readonly globals: Globals;
  readonly exprTypes: Map<A.Expr, Type>;
  readonly localTypes: Map<A.LetStmt, Type>;
  /** Active narrowings keyed by symbol.id. Push/pop-managed by `inferMatch`
   *  so that references to a scrutinee symbol inside an `is T -> body` arm
   *  see `T` instead of the full union. Nested matches stack naturally. */
  readonly narrowed: Map<number, Type>;
}

interface FnContext {
  readonly returnType: Type;
  /** Self type when type-checking a method body inside an impl block. */
  readonly selfType: Type | null;
  loopDepth: number;
}

/** Declare top-level types into the shared globals — must run for every module first. */
export function declareModule(
  program: ResolvedProgram, globals: Globals, diags: DiagnosticCollector,
): void {
  const t: MutableTyped = {
    resolved: program, globals,
    exprTypes: new Map(), localTypes: new Map(), narrowed: new Map(),
  };
  for (const decl of program.source.decls) declareType(decl, t, diags);
}

export function checkProgram(
  program: ResolvedProgram,
  globals: Globals,
  impls: ImplRegistry,
  diags: DiagnosticCollector,
): TypedProgram {
  const t: MutableTyped = {
    resolved: program, globals,
    exprTypes: new Map(), localTypes: new Map(), narrowed: new Map(),
  };

  for (const decl of program.source.decls) {
    switch (decl.kind) {
      case "FnDecl":
        if (decl.body !== null) checkFnBody(decl, decl.body, null, t, impls, diags);
        break;
      case "ImplDecl":
        for (const member of decl.members) {
          if (member.body !== null) {
            const selfType = t.globals.typeExprTypes.get(decl.forType) ?? TY.unresolved;
            checkFnBody(member, member.body, selfType, t, impls, diags);
          }
        }
        break;
      case "TraitDecl":
        // Trait member bodies are sketches; nothing to check yet.
        break;
      case "ConstDecl": {
        const expected = decl.type !== null ? t.globals.typeExprTypes.get(decl.type) ?? TY.unresolved : null;
        const got = checkExpr(decl.value, expected, t, impls, diags, /*fn*/ null);
        if (expected !== null && !isAssignable(got, expected)) {
          err(diags, "T3001", decl.span,
            `expected ${displayType(expected)}, got ${displayType(got)}`);
        }
        break;
      }
    }
  }

  return {
    resolved: program,
    exprTypes: t.exprTypes,
    localTypes: t.localTypes,
    declTypes: globals.declTypes,
    paramTypes: globals.paramTypes,
    typeExprTypes: globals.typeExprTypes,
  };
}

// ============================================================================
// Decl-level type computation
// ============================================================================

function declareType(decl: A.Decl, t: MutableTyped, diags: DiagnosticCollector): void {
  switch (decl.kind) {
    case "FnDecl":      declareFn(decl, t, diags); return;
    case "StructDecl":  declareStruct(decl, t, diags); return;
    case "TraitDecl":   declareTrait(decl, t, diags); return;
    case "ImplDecl":    declareImpl(decl, t, diags); return;
    case "TypeAliasDecl": {
      const aliased = lowerTypeExpr(decl.aliased, t, diags);
      t.globals.declTypes.set(decl, aliased);
      return;
    }
    case "ConstDecl":
      if (decl.type !== null) t.globals.declTypes.set(decl, lowerTypeExpr(decl.type, t, diags));
      return;
    case "ImportDecl":
      return;
  }
}

function declareFn(decl: A.FnDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  // SPEC §4: top-level fn signatures must be fully annotated. The exception is
  // an unannotated `self` first-parameter, which carries the implicit `Self` type.
  const params: Type[] = [];
  for (const p of decl.params) {
    if (p.type === null) {
      if (p.name === "self") {
        params.push(TY.unresolved);   // bound to the surrounding impl's forType in checkFnBody
      } else {
        err(diags, "T3024", p.span, `parameter \`${p.name}\` lacks a type`);
        params.push(TY.unresolved);
      }
    } else {
      const pt = lowerTypeExpr(p.type, t, diags);
      params.push(pt);
      t.globals.paramTypes.set(p, pt);
    }
  }
  const returnType = decl.returnType === null ? TY.void : lowerTypeExpr(decl.returnType, t, diags);
  t.globals.declTypes.set(decl, { kind: "Fn", params, returnType });
}

function declareStruct(decl: A.StructDecl, t: MutableTyped, _diags: DiagnosticCollector): void {
  const sym = symbolFor(decl, t);
  if (sym === null) return;
  const args = decl.typeParams.map((tp) => typeParamRef(tp, t));
  t.globals.declTypes.set(decl, { kind: "Struct", symbol: sym, args });
  for (const f of decl.fields) lowerTypeExpr(f.type, t, _diags);
}

function declareTrait(decl: A.TraitDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  const sym = symbolFor(decl, t);
  if (sym === null) return;
  const args = decl.typeParams.map((tp) => typeParamRef(tp, t));
  t.globals.declTypes.set(decl, { kind: "Trait", symbol: sym, args });
  for (const member of decl.members) declareFn(member, t, diags);
}

function declareImpl(decl: A.ImplDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  lowerTypeExpr(decl.forType, t, diags);
  for (const member of decl.members) declareFn(member, t, diags);
}

function symbolFor(decl: A.StructDecl | A.TraitDecl, t: MutableTyped): Symbol | null {
  return t.resolved.module.symbols.get(decl.name) ?? null;
}

function typeParamRef(tp: A.TypeParam, t: MutableTyped): Type {
  const sym = t.resolved.typeParams.get(tp);
  if (sym !== undefined) return { kind: "TypeParam", symbol: sym };
  // Resolver didn't record this typeParam — leave it Unresolved rather than
  // synthesising a fake Symbol that would alias every other unrecorded one.
  return TY.unresolved;
}

// ============================================================================
// Type-expression lowering: A.TypeExpr → Type
// ============================================================================

function lowerTypeExpr(expr: A.TypeExpr, t: MutableTyped, diags: DiagnosticCollector): Type {
  const result = lowerTypeExprInner(expr, t, diags);
  t.globals.typeExprTypes.set(expr, result);
  return result;
}

function lowerTypeExprInner(expr: A.TypeExpr, t: MutableTyped, diags: DiagnosticCollector): Type {
  switch (expr.kind) {
    case "NamedType": {
      const sym = t.resolved.types.get(expr);
      if (sym === undefined) return TY.unresolved;     // resolver already reported R2007
      return typeFromSymbol(sym, [], expr, t, diags);
    }
    case "GenericInstType": {
      const sym = t.resolved.types.get(expr.base);
      if (sym === undefined) return TY.unresolved;
      const args = expr.args.map((a) => lowerTypeExpr(a, t, diags));
      return typeFromSymbol(sym, args, expr, t, diags);
    }
    case "UnionType":
      return unionOf(expr.variants.map((v) => lowerTypeExpr(v, t, diags)));
    case "FnTypeExpr":
      return {
        kind: "Fn",
        params: expr.params.map((p) => lowerTypeExpr(p, t, diags)),
        returnType: expr.returnType === null ? TY.void : lowerTypeExpr(expr.returnType, t, diags),
      };
    case "ArrayTypeExpr":
      return { kind: "Array", element: lowerTypeExpr(expr.element, t, diags) };
    case "TypeParamType": {
      const sym = t.resolved.module.symbols.get(expr.name);
      if (sym !== undefined && sym.kind === "type-param") {
        return { kind: "TypeParam", symbol: sym };
      }
      // Inline-introduced (`$T`): the resolver records nothing for these; we
      // still tolerate them as fresh type-params in fn-signature context.
      return TY.unresolved;
    }
  }
}

function typeFromSymbol(
  sym: Symbol, args: readonly Type[],
  at: A.TypeExpr, t: MutableTyped, diags: DiagnosticCollector,
): Type {
  switch (sym.kind) {
    case "builtin-type":  return primitiveFromName(sym.name) ?? TY.unresolved;
    case "struct":        return { kind: "Struct", symbol: sym, args };
    case "trait":         return { kind: "Trait",  symbol: sym, args };
    case "type-param":    return { kind: "TypeParam", symbol: sym };
    case "type-alias": {
      if (sym.source.kind !== "type-alias") return TY.unresolved;
      const base = t.globals.declTypes.get(sym.source.decl);
      if (base === undefined) return TY.unresolved;
      const params = sym.source.decl.typeParams;
      if (args.length > 0) {
        if (args.length !== params.length) {
          err(diags, "T3021", at.span, `${sym.name} expects ${params.length} arg(s), got ${args.length}`);
          return base;
        }
        const typeParams = new Map<number, Type>();
        for (let i = 0; i < params.length; i++) {
          const tp = t.resolved.module.symbols.get(params[i]!.name);
          if (tp !== undefined) typeParams.set(tp.id, args[i]!);
        }
        return substitute(base, { typeParams });
      }
      return base;
    }
    default:
      return TY.unresolved;
  }
}

function primitiveFromName(name: string): Type | null {
  switch (name) {
    case "i8": case "i16": case "i32": case "i64":
    case "u8": case "u16": case "u32": case "u64":
    case "f32": case "f64":
    case "bool": case "char": case "string": case "void": case "null":
      return { kind: "Primitive", name };
    case "type":
      return TY.type;
    case "Self":
      // Substituted at body-check time when we know the surrounding impl's target.
      return TY.self;
  }
  return null;
}

// ============================================================================
// Body checking
// ============================================================================

function checkFnBody(
  fn: A.FnDecl, body: A.BlockExpr, selfType: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector,
): void {
  // Substitute `Self` in this fn's declared param/return types now that we know
  // the surrounding impl's target type. Also bind unannotated `self` parameters.
  if (selfType !== null) {
    for (const p of fn.params) {
      if (p.name === "self" && p.type === null) {
        t.globals.paramTypes.set(p, selfType);
      } else {
        const declared = t.globals.paramTypes.get(p);
        if (declared !== undefined) {
          t.globals.paramTypes.set(p, substitute(declared, { self: selfType }));
        }
      }
    }
    const declaredFn = t.globals.declTypes.get(fn);
    if (declaredFn !== undefined) {
      t.globals.declTypes.set(fn, substitute(declaredFn, { self: selfType }));
    }
  }
  const fnType = t.globals.declTypes.get(fn);
  const ctx: FnContext = {
    returnType: fnType?.kind === "Fn" ? fnType.returnType : TY.unresolved,
    selfType,
    loopDepth: 0,
  };
  const got = checkBlock(body, ctx.returnType, t, impls, diags, ctx);
  // Implicit return: if the block has no trailing expr the body type is void
  // (already handled). If the trailing expr is incompatible the diagnostic
  // already fired.
  if (body.trailing !== null && !isAssignable(got, ctx.returnType)) {
    err(diags, "T3020", body.trailing.span,
      `expected ${displayType(ctx.returnType)}, got ${displayType(got)}`);
  }
}

function checkBlock(
  block: A.BlockExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  for (const stmt of block.stmts) checkStmt(stmt, t, impls, diags, fn);
  let result: Type = TY.void;
  if (block.trailing !== null) {
    result = checkExpr(block.trailing, expected, t, impls, diags, fn);
  }
  t.exprTypes.set(block, result);
  return result;
}

function checkStmt(
  stmt: A.Stmt, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): void {
  switch (stmt.kind) {
    case "LetStmt": {
      const expected = stmt.type !== null ? lowerTypeExpr(stmt.type, t, diags) : null;
      const got = checkExpr(stmt.value, expected, t, impls, diags, fn);
      const declared = expected ?? defaultIfFree(got);
      if (expected !== null && !isAssignable(got, expected)) {
        err(diags, "T3001", stmt.span,
          `expected ${displayType(expected)}, got ${displayType(got)}`);
      }
      t.localTypes.set(stmt, declared);
      return;
    }
    case "AssignStmt":
      checkExpr(stmt.target, null, t, impls, diags, fn);
      checkExpr(stmt.value, null, t, impls, diags, fn);
      return;
    case "ExprStmt":
      checkExpr(stmt.expr, null, t, impls, diags, fn);
      return;
    case "ReturnStmt": {
      if (fn === null) return;
      if (stmt.value === null) {
        if (!isAssignable(TY.void, fn.returnType)) {
          err(diags, "T3020", stmt.span,
            `expected ${displayType(fn.returnType)}, got void`);
        }
        return;
      }
      const got = checkExpr(stmt.value, fn.returnType, t, impls, diags, fn);
      if (!isAssignable(got, fn.returnType)) {
        err(diags, "T3020", stmt.span,
          `expected ${displayType(fn.returnType)}, got ${displayType(got)}`);
      }
      return;
    }
    case "ForStmt":
      checkForStmt(stmt, t, impls, diags, fn);
      return;
    case "BreakStmt":
    case "ContinueStmt":
      if (fn === null || fn.loopDepth === 0) err(diags, "T3015", stmt.span);
      return;
    case "DeferStmt":
      if (stmt.body.kind === "BlockExpr") checkBlock(stmt.body, null, t, impls, diags, fn);
      else checkStmt(stmt.body, t, impls, diags, fn);
      return;
  }
}

function checkForStmt(
  stmt: A.ForStmt, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): void {
  switch (stmt.form.kind) {
    case "infinite":
      break;
    case "while": {
      const got = checkExpr(stmt.form.cond, TY.bool, t, impls, diags, fn);
      if (!isAssignable(got, TY.bool)) err(diags, "T3019", stmt.form.cond.span);
      break;
    }
    case "in":
      checkExpr(stmt.form.iter, null, t, impls, diags, fn);
      // For-in's binding type would require Iterable resolution. MVP: leave Unresolved,
      // typecheck of references against it will succeed via Unresolved compatibility.
      break;
  }
  const newFn = fn !== null ? { ...fn, loopDepth: fn.loopDepth + 1 } : null;
  checkBlock(stmt.body, null, t, impls, diags, newFn);
}

// ============================================================================
// Expressions
// ============================================================================

export function checkExpr(
  expr: A.Expr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const got = inferExpr(expr, expected, t, impls, diags, fn);
  // If the caller wanted a specific type and we produced a free numeric, default
  // it now (so `let x: i64 = 5` works without a synthetic node).
  let final = got;
  if (expected !== null) {
    if (got.kind === "FreeInt" && isAssignable(TY.i32, expected)) final = expected;
    else if (got.kind === "FreeFloat" && isAssignable(TY.f64, expected)) final = expected;
  }
  t.exprTypes.set(expr, final);
  return final;
}

function inferExpr(
  expr: A.Expr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  switch (expr.kind) {
    case "IntLitExpr":
      return expr.suffix !== null ? primitiveFromName(expr.suffix) ?? TY.unresolved : TY.freeInt;
    case "FloatLitExpr":
      return expr.suffix !== null ? primitiveFromName(expr.suffix) ?? TY.unresolved : TY.freeFloat;
    case "BoolLitExpr":   return TY.bool;
    case "NullLitExpr":   return TY.null;
    case "CharLitExpr":   return TY.char;
    case "StringLitExpr": return inferStringLit(expr, t, impls, diags, fn);
    case "IdentExpr":     return inferIdent(expr, t);
    case "CallExpr":      return inferCall(expr, t, impls, diags, fn);
    case "FieldExpr":     return inferField(expr, t, impls, diags, fn);
    case "IndexExpr":     return inferIndex(expr, t, impls, diags, fn);
    case "UnaryExpr":     return inferUnary(expr, t, impls, diags, fn);
    case "BinaryExpr":    return inferBinary(expr, t, impls, diags, fn);
    case "IfExpr":        return inferIf(expr, expected, t, impls, diags, fn);
    case "MatchExpr":     return inferMatch(expr, expected, t, impls, diags, fn);
    case "BlockExpr":     return checkBlock(expr, expected, t, impls, diags, fn);
    case "LambdaExpr":    return inferLambda(expr, expected, t, impls, diags, fn);
    case "StructLitExpr": return inferStructLit(expr, t, impls, diags, fn);
    case "ArrayLitExpr":  return inferArrayLit(expr, expected, t, impls, diags, fn);
    case "RangeExpr":     return inferRange(expr, t, impls, diags, fn);
    case "TryExpr":       return inferTry(expr, t, impls, diags, fn);
    case "CastExpr":      return inferCast(expr, t, impls, diags, fn);
    case "GenericInstExpr": {
      checkExpr(expr.callee, null, t, impls, diags, fn);
      for (const a of expr.typeArgs) lowerTypeExpr(a, t, diags);
      return TY.unresolved;
    }
  }
}

function inferStringLit(
  expr: A.StringLitExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  for (const part of expr.parts) {
    if (part.kind !== "interp") continue;
    const inner = checkExpr(part.expr, null, t, impls, diags, fn);
    if (!implementsDisplay(inner, t, impls)) {
      err(diags, "T3018", part.expr.span, displayType(inner));
    }
  }
  return TY.string;
}

function inferIdent(expr: A.IdentExpr, t: MutableTyped): Type {
  const sym = t.resolved.idents.get(expr);
  if (sym === undefined) return TY.unresolved;
  return typeOfSymbol(sym, t);
}

function typeOfSymbol(sym: Symbol, t: MutableTyped): Type {
  const narrow = t.narrowed.get(sym.id);
  if (narrow !== undefined) return narrow;
  switch (sym.kind) {
    case "fn":
    case "const":
    case "type-alias":
    case "struct":
    case "trait": {
      const decl = declOf(sym);
      return decl !== null ? t.globals.declTypes.get(decl) ?? TY.unresolved : TY.unresolved;
    }
    case "param":
      return sym.source.kind === "param"
        ? t.globals.paramTypes.get(sym.source.param) ?? TY.unresolved
        : TY.unresolved;
    case "local":
      return sym.source.kind === "local"
        ? t.localTypes.get(sym.source.stmt) ?? TY.unresolved
        : TY.unresolved;
    case "type-param":
      return { kind: "TypeParam", symbol: sym };
    case "builtin-type":
      return primitiveFromName(sym.name) ?? TY.unresolved;
    case "import-binding":
      // Resolver redirects most uses through `resolveImportRedirect` to the
      // concrete export; if we still see the binding here it's the namespace
      // form (`import "std/io"` → `io.println()`) — typing it requires the
      // module-as-value notion that we don't model in MVP. Leave Unresolved,
      // and tolerate it in field-resolution callers.
      return TY.unresolved;
    case "binding":
    case "builtin-fn":
      // Pattern bindings, for-in vars: type narrows from context (not yet tracked).
      // builtin-fn: reserved for future intrinsics.
      return TY.unresolved;
  }
}

function inferCall(
  expr: A.CallExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Cast form: `Type(value)` — the callee is an ident resolving to a type symbol.
  if (expr.callee.kind === "IdentExpr") {
    const sym = t.resolved.idents.get(expr.callee);
    if (sym !== undefined && (sym.kind === "builtin-type" || sym.kind === "struct" || sym.kind === "type-alias")) {
      return inferTypeConstructorCall(expr, t, impls, diags, fn);
    }
  }

  const calleeType = checkExpr(expr.callee, null, t, impls, diags, fn);

  if (calleeType.kind !== "Fn") {
    if (calleeType.kind !== "Unresolved") err(diags, "T3007", expr.callee.span, displayType(calleeType));
    for (const a of expr.args) checkExpr(a.value, null, t, impls, diags, fn);
    return TY.unresolved;
  }

  // Arity check.
  const positionals = expr.args.filter((a) => a.name === null);
  if (positionals.length !== calleeType.params.length) {
    // Allow named args: total count must match for now (named-only resolution deferred to MVP+).
    if (expr.args.length !== calleeType.params.length) {
      err(diags, "T3003", expr.span,
        `expected ${calleeType.params.length}, got ${expr.args.length}`);
    }
  }
  for (let i = 0; i < expr.args.length; i++) {
    const arg = expr.args[i]!;
    const expectedTy = i < calleeType.params.length ? calleeType.params[i]! : null;
    const got = checkExpr(arg.value, expectedTy, t, impls, diags, fn);
    if (expectedTy !== null && !isAssignable(got, expectedTy)) {
      err(diags, "T3001", arg.value.span,
        `expected ${displayType(expectedTy)}, got ${displayType(got)}`);
    }
  }
  return calleeType.returnType;
}

function inferTypeConstructorCall(
  expr: A.CallExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Record the callee's type-meta nature in the side-table for later tooling.
  t.exprTypes.set(expr.callee, TY.type);
  const target = identTargetType(expr.callee, t);
  if (target === null) {
    err(diags, "T3010", expr.callee.span, "cannot determine target type");
    return TY.unresolved;
  }

  // Generic instantiation `Foo(T1, T2)` — record but keep MVP-simple: produce the
  // base type unchanged. Real generics flow through the comptime engine in 1.5.
  if (target.kind === "Struct" && expr.args.length > 0) {
    for (const a of expr.args) checkExpr(a.value, null, t, impls, diags, fn);
    return target;
  }

  // Numeric cast `i32(x)` etc. — primitive numeric source + target only in MVP.
  if (expr.args.length !== 1) {
    err(diags, "T3010", expr.span, "cast takes exactly one argument");
    for (const a of expr.args) checkExpr(a.value, null, t, impls, diags, fn);
    return TY.unresolved;
  }
  const arg = expr.args[0]!.value;
  const argType = checkExpr(arg, null, t, impls, diags, fn);
  if (!isNumeric(target)) {
    err(diags, "T3010", expr.callee.span,
      `cast target must be a primitive numeric type, got ${displayType(target)}`);
    return target;
  }
  if (!isNumeric(argType) && argType.kind !== "Unresolved" && argType.kind !== "FreeInt" && argType.kind !== "FreeFloat") {
    err(diags, "T3010", arg.span,
      `cast source must be numeric, got ${displayType(argType)}`);
  }
  return target;
}

function identTargetType(callee: A.Expr, t: MutableTyped): Type | null {
  if (callee.kind !== "IdentExpr") return null;
  const sym = t.resolved.idents.get(callee);
  if (sym === undefined) return null;
  if (sym.kind === "builtin-type") return primitiveFromName(sym.name);
  if (sym.kind === "struct") {
    return sym.source.kind === "struct" ? t.globals.declTypes.get(sym.source.decl) ?? null : null;
  }
  if (sym.kind === "type-alias") {
    return sym.source.kind === "type-alias" ? t.globals.declTypes.get(sym.source.decl) ?? null : null;
  }
  return null;
}

function inferField(
  expr: A.FieldExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Module-namespace field: resolver already wired the export.
  const exported = t.resolved.fields.get(expr);
  if (exported !== undefined) return typeOfSymbol(exported, t);

  const targetType = checkExpr(expr.target, null, t, impls, diags, fn);
  if (targetType.kind === "Struct") {
    const decl = sourceStructDecl(targetType.symbol);
    if (decl !== null) {
      const field = decl.fields.find((f) => f.name === expr.field);
      if (field !== undefined) return t.globals.typeExprTypes.get(field.type) ?? TY.unresolved;
    }
  }
  if (targetType.kind !== "Unresolved") {
    err(diags, "T3009", expr.fieldSpan, `\`${expr.field}\` on ${displayType(targetType)}`);
  }
  return TY.unresolved;
}

function sourceStructDecl(sym: Symbol): A.StructDecl | null {
  return sym.source.kind === "struct" ? sym.source.decl : null;
}

function inferIndex(
  expr: A.IndexExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const target = checkExpr(expr.target, null, t, impls, diags, fn);
  checkExpr(expr.index, null, t, impls, diags, fn);
  if (target.kind === "Array") return target.element;
  if (target.kind !== "Unresolved") err(diags, "T3008", expr.target.span, displayType(target));
  return TY.unresolved;
}

function inferUnary(
  expr: A.UnaryExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const operand = checkExpr(expr.operand, null, t, impls, diags, fn);
  switch (expr.op) {
    case "neg":
      if (operand.kind === "FreeInt" || operand.kind === "FreeFloat") return operand;
      if (isNumeric(operand) || operand.kind === "Unresolved") return operand;
      err(diags, "T3017", expr.span, `unary - on ${displayType(operand)}`);
      return TY.unresolved;
    case "not":
      if (isPrimitive(operand, "bool") || operand.kind === "Unresolved") return TY.bool;
      err(diags, "T3017", expr.span, `! on ${displayType(operand)}`);
      return TY.unresolved;
    case "bitnot":
      if (isInteger(operand) || operand.kind === "FreeInt" || operand.kind === "Unresolved") return operand;
      err(diags, "T3017", expr.span, `~ on ${displayType(operand)}`);
      return TY.unresolved;
  }
}

function inferBinary(
  expr: A.BinaryExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const left = checkExpr(expr.left, null, t, impls, diags, fn);
  const right = checkExpr(expr.right, null, t, impls, diags, fn);
  switch (expr.op) {
    case "add": case "sub": case "mul": case "div": case "mod":
      return binaryNumeric(expr, left, right, diags);
    case "shl": case "shr": case "bitand": case "bitor": case "bitxor":
      return binaryInteger(expr, left, right, diags);
    case "eq": case "neq":
      return binaryEquality(expr, left, right, diags);
    case "lt": case "lte": case "gt": case "gte":
      return binaryComparison(expr, left, right, diags);
    case "and": case "or":
      if (!isPrimitive(left, "bool") && left.kind !== "Unresolved") err(diags, "T3017", expr.left.span);
      if (!isPrimitive(right, "bool") && right.kind !== "Unresolved") err(diags, "T3017", expr.right.span);
      return TY.bool;
    case "is":
      // `lhs is RHS`: lhs is a value, rhs would be a type ident; MVP accepts.
      return TY.bool;
  }
}

function binaryNumeric(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  // Special case: `string + string` is concatenation.
  if (expr.op === "add" && isPrimitive(left, "string") && isPrimitive(right, "string")) return TY.string;
  return numericResult(expr, left, right, diags);
}

function binaryInteger(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.unresolved;
  if ((isInteger(left) || left.kind === "FreeInt") && (isInteger(right) || right.kind === "FreeInt")) {
    return left.kind === "FreeInt" ? right : left;
  }
  err(diags, "T3017", expr.span, `bitwise op on ${displayType(left)} / ${displayType(right)}`);
  return TY.unresolved;
}

function binaryEquality(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.bool;
  if (equalsType(defaultIfFree(left), defaultIfFree(right))) return TY.bool;
  if (left.kind === "FreeInt" && isNumeric(right)) return TY.bool;
  if (right.kind === "FreeInt" && isNumeric(left)) return TY.bool;
  if (left.kind === "FreeFloat" && isFloat(right)) return TY.bool;
  if (right.kind === "FreeFloat" && isFloat(left)) return TY.bool;
  err(diags, "T3017", expr.span,
    `${expr.op} between ${displayType(left)} and ${displayType(right)}`);
  return TY.bool;
}

function binaryComparison(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.bool;
  const okPair =
    (isNumeric(left) || left.kind === "FreeInt" || left.kind === "FreeFloat") &&
    (isNumeric(right) || right.kind === "FreeInt" || right.kind === "FreeFloat");
  if (okPair) return TY.bool;
  if (isPrimitive(left, "string") && isPrimitive(right, "string")) return TY.bool;
  err(diags, "T3017", expr.span, `comparison ${displayType(left)} vs ${displayType(right)}`);
  return TY.bool;
}

function numericResult(expr: A.BinaryExpr, left: Type, right: Type, diags: DiagnosticCollector): Type {
  if (left.kind === "Unresolved" || right.kind === "Unresolved") return TY.unresolved;
  const lf = left.kind === "FreeInt" || left.kind === "FreeFloat";
  const rf = right.kind === "FreeInt" || right.kind === "FreeFloat";
  if (lf && rf) return left.kind === "FreeFloat" || right.kind === "FreeFloat" ? TY.freeFloat : TY.freeInt;
  if (lf && isNumeric(right)) return right;
  if (rf && isNumeric(left)) return left;
  if (isNumeric(left) && isNumeric(right) && equalsType(left, right)) return left;
  err(diags, "T3017", expr.span,
    `${expr.op} between ${displayType(left)} and ${displayType(right)}`);
  return TY.unresolved;
}

function inferIf(
  expr: A.IfExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const cond = checkExpr(expr.cond, TY.bool, t, impls, diags, fn);
  if (!isAssignable(cond, TY.bool)) err(diags, "T3019", expr.cond.span);
  const thenT = checkBlock(expr.then, expected, t, impls, diags, fn);
  if (expr.else === null) return thenT.kind === "Never" ? TY.void : unionOf([thenT, TY.void]);
  const elseT = expr.else.kind === "IfExpr"
    ? checkExpr(expr.else, expected, t, impls, diags, fn)
    : checkBlock(expr.else, expected, t, impls, diags, fn);
  return unionOf([thenT, elseT]);
}

function inferMatch(
  expr: A.MatchExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const scrut = checkExpr(expr.scrutinee, null, t, impls, diags, fn);
  const scrutSym = scrutineeSymbol(expr.scrutinee, t);
  const armTypes: Type[] = [];
  let hasWildcard = false;
  const coveredVariants = new Set<string>();
  for (const arm of expr.arms) {
    if (arm.pattern.kind === "WildcardPattern") hasWildcard = true;
    let narrowed: Type | null = null;
    if (arm.pattern.kind === "IsPattern") {
      const variantTy = lowerTypeExpr(arm.pattern.type, t, diags);
      coveredVariants.add(displayType(variantTy));
      narrowed = variantTy;
    }
    const prev: Type | undefined = scrutSym !== null && narrowed !== null
      ? pushNarrowing(t, scrutSym.id, narrowed)
      : undefined;
    if (arm.guard !== null) {
      const g = checkExpr(arm.guard, TY.bool, t, impls, diags, fn);
      if (!isAssignable(g, TY.bool)) err(diags, "T3019", arm.guard.span);
    }
    armTypes.push(checkExpr(arm.body, expected, t, impls, diags, fn));
    if (scrutSym !== null && narrowed !== null) popNarrowing(t, scrutSym.id, prev);
  }

  if (!hasWildcard) {
    if (scrut.kind === "Union") {
      for (const v of scrut.variants) {
        if (!coveredVariants.has(displayType(v))) {
          err(diags, "T3013", expr.span,
            `variant ${displayType(v)} of ${displayType(scrut)} is not covered`);
          break;
        }
      }
    } else if (scrut.kind !== "Unresolved") {
      err(diags, "T3013", expr.span,
        `match on non-union ${displayType(scrut)} requires a wildcard arm`);
    }
  }

  return armTypes.length === 0 ? TY.never : unionOf(armTypes);
}

/** Resolve the scrutinee to a symbol when it's a plain identifier referring
 *  to a local or parameter — only those flow narrowing usefully. Anything
 *  else (calls, field access, literals) gets no narrowing. */
function scrutineeSymbol(scrut: A.Expr, t: MutableTyped): Symbol | null {
  if (scrut.kind !== "IdentExpr") return null;
  const sym = t.resolved.idents.get(scrut);
  if (sym === undefined) return null;
  if (sym.kind !== "local" && sym.kind !== "param" && sym.kind !== "binding") return null;
  return sym;
}

function pushNarrowing(t: MutableTyped, symId: number, narrow: Type): Type | undefined {
  const prev = t.narrowed.get(symId);
  t.narrowed.set(symId, narrow);
  return prev;
}

function popNarrowing(t: MutableTyped, symId: number, prev: Type | undefined): void {
  if (prev === undefined) t.narrowed.delete(symId);
  else t.narrowed.set(symId, prev);
}

function inferLambda(
  expr: A.LambdaExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const expectedFn = expected?.kind === "Fn" ? expected : null;
  const paramTypes: Type[] = [];
  for (let i = 0; i < expr.params.length; i++) {
    const p = expr.params[i]!;
    let pt: Type;
    if (p.type !== null) {
      pt = lowerTypeExpr(p.type, t, diags);
    } else if (expectedFn !== null && i < expectedFn.params.length) {
      pt = expectedFn.params[i]!;
    } else {
      err(diags, "T3024", p.span, `lambda parameter \`${p.name}\` cannot be inferred`);
      pt = TY.unresolved;
    }
    paramTypes.push(pt);
    t.globals.paramTypes.set(p, pt);
  }
  const expectedRet = expr.returnType !== null
    ? lowerTypeExpr(expr.returnType, t, diags)
    : expectedFn?.returnType ?? null;
  const innerFn: FnContext = { returnType: expectedRet ?? TY.unresolved, selfType: fn?.selfType ?? null, loopDepth: 0 };
  const bodyType = checkBlock(expr.body, expectedRet, t, impls, diags, innerFn);
  return { kind: "Fn", params: paramTypes, returnType: expectedRet ?? bodyType };
}

function inferStructLit(
  expr: A.StructLitExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const ty = lowerTypeExpr(expr.typeName, t, diags);
  if (ty.kind !== "Struct") {
    err(diags, "T3001", expr.typeName.span,
      `${displayType(ty)} is not a struct`);
    for (const f of expr.fields) checkExpr(f.value, null, t, impls, diags, fn);
    return ty;
  }
  const decl = sourceStructDecl(ty.symbol);
  for (const f of expr.fields) {
    const field = decl?.fields.find((sf) => sf.name === f.name);
    const expected = field !== undefined ? t.globals.typeExprTypes.get(field.type) ?? null : null;
    const got = checkExpr(f.value, expected, t, impls, diags, fn);
    if (field === undefined) {
      err(diags, "T3009", f.nameSpan, `\`${f.name}\` on ${displayType(ty)}`);
    } else if (expected !== null && !isAssignable(got, expected)) {
      err(diags, "T3001", f.span,
        `expected ${displayType(expected)}, got ${displayType(got)}`);
    }
  }
  return ty;
}

function inferArrayLit(
  expr: A.ArrayLitExpr, expected: Type | null,
  t: MutableTyped, impls: ImplRegistry, diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const elemExpected = expected?.kind === "Array" ? expected.element : null;
  const elemTypes: Type[] = expr.elements.map((e) => checkExpr(e, elemExpected, t, impls, diags, fn));
  if (elemTypes.length === 0) return { kind: "Array", element: elemExpected ?? TY.unresolved };
  return { kind: "Array", element: unionOf(elemTypes.map(defaultIfFree)) };
}

function inferRange(
  expr: A.RangeExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  checkExpr(expr.lower, null, t, impls, diags, fn);
  checkExpr(expr.upper, null, t, impls, diags, fn);
  // SPEC mentions `Range` in stdlib; not yet ported. MVP: leave Unresolved.
  return TY.unresolved;
}

function inferTry(
  expr: A.TryExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const inner = checkExpr(expr.inner, null, t, impls, diags, fn);
  if (inner.kind !== "Union") {
    if (inner.kind !== "Unresolved") err(diags, "T3011", expr.span, displayType(inner));
    return TY.unresolved;
  }

  const errorVariants: Type[] = [];
  const successVariants: Type[] = [];
  for (const v of inner.variants) {
    if (variantImplementsError(v, t, impls)) errorVariants.push(v);
    else successVariants.push(v);
  }
  if (errorVariants.length === 0) {
    err(diags, "T3011", expr.span, displayType(inner));
    return inner;
  }

  // Validate fn return type can absorb the propagated errors.
  if (fn !== null) {
    for (const e of errorVariants) {
      if (!isAssignable(e, fn.returnType)) {
        err(diags, "T3012", expr.span,
          `${displayType(e)} not in ${displayType(fn.returnType)}`);
        break;
      }
    }
  }

  return successVariants.length === 1 ? successVariants[0]! : unionOf(successVariants);
}

function variantImplementsError(v: Type, t: MutableTyped, impls: ImplRegistry): boolean {
  // The Error trait lives in std/core. Find its symbol via the resolved program's
  // module symbols (std/core auto-imported into every module as builtin scope).
  const errorSym = findErrorTrait(t);
  if (errorSym === null) return false;
  if (v.kind === "Trait" && v.symbol.id === errorSym.id) return true;
  if (v.kind === "Struct") {
    return impls.hasUser(v.symbol, errorSym);
  }
  return false;
}

function findErrorTrait(t: MutableTyped): Symbol | null {
  return findGlobalTrait(t, CORE_TRAITS.Error);
}

function inferCast(
  expr: A.CastExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Parser doesn't currently emit CastExpr (Type(value) → CallExpr); branch unused.
  const target = lowerTypeExpr(expr.target, t, diags);
  checkExpr(expr.value, null, t, impls, diags, fn);
  return target;
}

// ============================================================================
// Trait satisfaction
// ============================================================================

function implementsDisplay(ty: Type, t: MutableTyped, impls: ImplRegistry): boolean {
  // SPEC §9: every primitive impls Display.
  if (ty.kind === "Primitive") return true;
  if (ty.kind === "FreeInt" || ty.kind === "FreeFloat") return true;
  if (ty.kind === "Unresolved") return true;
  const display = findDisplayTrait(t);
  if (display === null) return false;
  if (ty.kind === "Struct") return impls.hasUser(ty.symbol, display);
  if (ty.kind === "Union") return ty.variants.every((v) => implementsDisplay(v, t, impls));
  return false;
}

function findDisplayTrait(t: MutableTyped): Symbol | null {
  return findGlobalTrait(t, CORE_TRAITS.Display);
}

/** Look up a trait by name in std/core (auto-imported) or the local module. */
function findGlobalTrait(t: MutableTyped, name: string): Symbol | null {
  const local = t.resolved.module.symbols.get(name);
  if (local?.kind === "trait") return local;
  const core = t.globals.coreSymbols?.get(name);
  return core?.kind === "trait" ? core : null;
}
