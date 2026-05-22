// Decl-level type computation. Walks every top-level decl and records its
// declared type into `Globals.declTypes` so later body-checking can resolve
// cross-decl references (calls, struct field types, etc.) before any function
// body is checked.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import { staticStringValue } from "../../parser/ast.ts";
import { DEC, findDecoratorArgs, hasDecorator } from "../../parser/decorators.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { isTypeReferenceSymbol } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { PrimitiveName, Type } from "../types.ts";
import { ALL_INTS, CORE_TRAITS, TY, displayType, equalsType, mkEnum, mkFn, mkStruct, mkTrait, mkTypeParam, substitute } from "../types.ts";

import type { MutableTyped } from "../ctx.ts";
import { buildStructSubst } from "../ctx.ts";
import { lowerExprAsType } from "./type-expr.ts";

/** Syntactic predicate : does `expr` look like a type expression in the
 *  Layer 4-sugar sense ? Used by the implicit-type-alias promotion in the
 *  ConstDecl declarer (and the in-fn let-stmt path in `inferLet`) to decide
 *  whether to lower the RHS as a type before any body has been checked. We
 *  can't call `lowerExprAsType` blindly — it emits diagnostics for non-type
 *  Exprs — so this is the gate. */
export function looksLikeTypeExpression(expr: A.Expr, t: MutableTyped): boolean {
  switch (expr.kind) {
    case "IdentExpr": {
      const sym = t.resolved.idents.get(expr) ?? t.resolved.types.get(expr);
      return sym !== undefined && isTypeReferenceSymbol(sym);
    }
    case "BinaryExpr":
      // Only the type-position operators `|` (union) and `&` (intersection).
      return (expr.op === "bitor" || expr.op === "bitand")
          && looksLikeTypeExpression(expr.left, t)
          && looksLikeTypeExpression(expr.right, t);
    case "ArrayTypeExpr":
    case "FnTypeExpr":
    case "NullLitExpr":
      // `null` in expression context parses as `NullLitExpr` ; in type
      // context it's the null primitive. Both meanings collapse to the
      // same `TY.null` at `lowerExprAsType` time.
      return true;
    case "GenericInstExpr":
      // `Map(K, V)` / `Map[K, V]` shape — type-shape iff the callee is.
      return looksLikeTypeExpression(expr.callee, t);
    case "SeqLitExpr":
      // `[T1, T2]` tuple type — type-shape iff every element is.
      return expr.elements.every((e) => looksLikeTypeExpression(e, t));
    default:
      return false;
  }
}

export function declareType(decl: A.Decl, t: MutableTyped, diags: DiagnosticCollector): void {
  switch (decl.kind) {
    case "FnDecl":      declareFn(decl, t, diags); return;
    case "StructDecl":  declareStruct(decl, t, diags); return;
    case "EnumDecl":    declareEnum(decl, t, diags); return;
    case "TraitDecl":   declareTrait(decl, t, diags); return;
    case "ImplDecl":    declareImpl(decl, t, diags); return;
    case "TypeAliasDecl": {
      const aliased = lowerExprAsType(decl.aliased, t, diags);
      t.globals.declTypes.set(decl, aliased);
      return;
    }
    case "ConstDecl":
      if (decl.type !== null) t.globals.declTypes.set(decl, lowerExprAsType(decl.type, t, diags));
      // Layer 4-sugar — implicit type alias : when the RHS is structurally
      // a type expression (built from type-name references and the type
      // operators `|`, `&`, `[]`, …), pre-resolve it to a Type and stash
      // it so the const name is usable in type-demanding slots from this
      // point on. Detection is purely syntactic so it runs before any
      // body-level typecheck, sidestepping the ordering trap where another
      // decl's signature mentions the alias. We also fix the const's static
      // type to `TY.type` here so the body-check pass doesn't re-infer it
      // from the literal value (which it can't, since the value is a type).
      if (looksLikeTypeExpression(decl.value, t)) {
        t.globals.constTypeAliases.set(decl, lowerExprAsType(decl.value, t, diags));
        if (decl.type === null) t.globals.declTypes.set(decl, TY.type);
      } else if (decl.type === null && decl.value.kind === "StructLitExpr") {
        // Pin the type from the struct-lit's type-name at declare time —
        // without it, a consumer module's fn-body checked before this
        // const's defining module sees `Unresolved`.
        const lit = decl.value;
        if (lit.typeName.kind === "IdentExpr") {
          t.globals.declTypes.set(decl, lowerExprAsType(lit.typeName, t, diags));
        }
      }
      return;
    case "ImportDecl":
      return;
    case "AssertDecl":
      // `@assert` doesn't introduce a type ; the body's type-check happens
      // in `check.ts` alongside the comptime evaluation hook.
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
      const pt = lowerExprAsType(p.type, t, diags);
      params.push(pt);
      t.globals.paramTypes.set(p, pt);
    }
  }
  // Expression-bodied fns (`fn(...) = expr`) without an explicit return
  // type defer to the separate inference pass — leave Unresolved here.
  // An annotated form (`fn(...) -> T = expr`) lets recursive expression
  // bodies reference themselves without needing inference, and the
  // declared type wins. Block-bodied fns without `->` default to `void`.
  const returnType = decl.returnType !== null
    ? lowerExprAsType(decl.returnType, t, diags)
    : decl.isExpressionBodied
      ? TY.unresolved
      : TY.void;
  t.globals.declTypes.set(decl, mkFn(params, returnType));
  if (hasDecorator(decl.decorators, DEC.extern)) {
    validateExtern(decl, params, returnType, t, diags);
  }
}

/** Type-position whitelist for `@extern` signatures — the C ABI only
 *  marshals primitives + `string` cleanly. Anything else (struct, array,
 *  union, fn-typed param, …) requires more elaborate marshalling than
 *  the MVP shim supports. */
function isExternAbiType(t: Type, allowVoid: boolean): boolean {
  if (t.kind === "Unresolved") return true;            // upstream error, don't pile on
  if (t.kind === "Primitive") {
    if (t.name === "void") return allowVoid;
    if (t.name === "null") return false;
    return true;
  }
  return false;
}

function validateExtern(
  decl: A.FnDecl, params: readonly Type[], returnType: Type,
  t: MutableTyped, diags: DiagnosticCollector,
): void {
  if (decl.body !== null) {
    err(diags, "T3051", decl.body.span,
      `\`@extern\` fn \`${decl.name}\` cannot have a body — drop the \`= ...\` / \`{ ... }\``);
  }
  const args = findDecoratorArgs(decl.decorators, DEC.extern) ?? [];
  if (args.length > 2) {
    err(diags, "T3050", decl.span,
      `\`@extern\` accepts 0, 1, or 2 string arguments — got ${args.length}`);
    return;       // arg-shape errors gate further per-arg checks
  }
  for (const a of args) {
    if (a.kind !== "StringLitExpr" || staticStringValue(a) === null) {
      err(diags, "T3050", a.span,
        `\`@extern\` arguments must be plain string literals (no interpolation)`);
    }
  }
  for (let i = 0; i < decl.params.length; i++) {
    const pt = params[i]!;
    if (!isExternAbiType(pt, /*allowVoid*/ false)) {
      err(diags, "T3050", decl.params[i]!.span,
        `\`@extern\` parameter type must be a primitive or \`string\`, got \`${displayType(pt)}\``);
    }
  }
  if (!isExternAbiType(returnType, /*allowVoid*/ true)) {
    err(diags, "T3050", decl.returnType?.span ?? decl.span,
      `\`@extern\` return type must be a primitive, \`string\`, or \`void\`, got \`${displayType(returnType)}\``);
  }
  // Same C symbol name produced by two distinct `@extern` decls — the
  // linker would resolve both call sites to the same prototype, which
  // either silently works (matching signatures, intent unclear) or links
  // mismatched ABIs and produces UB at the call site. Stay loud here.
  const symName = externSymbolName(decl);
  const prior = t.externSymbols.get(symName);
  if (prior !== undefined && prior !== decl) {
    err(diags, "T3050", decl.span,
      `duplicate \`@extern\` C symbol \`${symName}\` — already declared on \`${prior.name}\``);
  } else {
    t.externSymbols.set(symName, decl);
  }
}

/** Resolve the C-side symbol name for an `@extern` fn. The decorator
 *  accepts 0, 1, or 2 string arguments ; the **last** string is the
 *  symbol name. With 2 args the 1st is a WASM-module hint (`@extern
 *  ("env", "console_log")` — C-emit ignores the module, WASM-emit will
 *  later consume it). Missing decorator or empty args fall back to the
 *  source fn name — keeps zero-friction the common case where the
 *  Vader-side name already matches the C symbol. */
export function externSymbolName(decl: A.FnDecl): string {
  const args = findDecoratorArgs(decl.decorators, DEC.extern);
  if (args !== null && args.length > 0) {
    const last = args[args.length - 1]!;
    if (last.kind === "StringLitExpr") {
      const s = staticStringValue(last);
      if (s !== null) return s;
    }
  }
  return decl.name;
}

function declareEnum(decl: A.EnumDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  const sym = t.resolved.module.symbols.get(decl.name);
  if (sym === undefined) return;
  const repr = resolveEnumRepr(decl, t, diags);
  const indices = resolveEnumIndices(decl, repr, diags);
  t.globals.declTypes.set(decl, mkEnum(sym, repr, indices));
}

function resolveEnumRepr(decl: A.EnumDecl, t: MutableTyped, diags: DiagnosticCollector): PrimitiveName {
  if (decl.repr === null) return "i32";
  const reprType = lowerExprAsType(decl.repr, t, diags);
  if (reprType.kind !== "Primitive" || !(ALL_INTS as readonly string[]).includes(reprType.name)) {
    err(diags, "T3029", decl.repr.span, `got ${reprType.kind === "Primitive" ? reprType.name : reprType.kind}`);
    return "i32";
  }
  return reprType.name;
}

const REPR_RANGES: Record<PrimitiveName, { min: bigint; max: bigint } | null> = {
  i8:    { min: -128n, max: 127n },
  i16:   { min: -32_768n, max: 32_767n },
  i32:   { min: -2_147_483_648n, max: 2_147_483_647n },
  i64:   { min: -9_223_372_036_854_775_808n, max: 9_223_372_036_854_775_807n },
  isize: { min: -9_223_372_036_854_775_808n, max: 9_223_372_036_854_775_807n },
  u8:    { min: 0n, max: 255n },
  u16:   { min: 0n, max: 65_535n },
  u32:   { min: 0n, max: 4_294_967_295n },
  u64:   { min: 0n, max: 18_446_744_073_709_551_615n },
  usize: { min: 0n, max: 18_446_744_073_709_551_615n },
  f32: null, f64: null, bool: null, char: null, string: null, void: null, null: null,
};

function resolveEnumIndices(
  decl: A.EnumDecl, repr: PrimitiveName, diags: DiagnosticCollector,
): ReadonlyMap<string, bigint> {
  const range = REPR_RANGES[repr];
  const out = new Map<string, bigint>();
  const seen = new Map<string, string>();   // value-as-string → variant name (for dup detection)
  let cursor = 0n;
  for (const variant of decl.variants) {
    const value = variant.value ?? cursor;
    if (range !== null && (value < range.min || value > range.max)) {
      err(diags, "T3030", variant.valueSpan ?? variant.span,
        `${value} not in [${range.min}, ${range.max}] for \`${repr}\``);
    }
    const key = value.toString();
    const prior = seen.get(key);
    if (prior !== undefined) {
      err(diags, "T3031", variant.valueSpan ?? variant.span,
        `value ${value} already used by \`${prior}\``);
    } else {
      seen.set(key, variant.name);
    }
    out.set(variant.name, value);
    cursor = value + 1n;
  }
  return out;
}

function declareStruct(decl: A.StructDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  const sym = symbolFor(decl, t);
  if (sym === null) return;
  const args = decl.typeParams.map((tp) => typeParamRef(tp, t));
  t.globals.declTypes.set(decl, mkStruct(sym, args));
  for (const f of decl.fields) lowerExprAsType(f.type, t, diags);
}

function declareTrait(decl: A.TraitDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  const sym = symbolFor(decl, t);
  if (sym === null) return;
  const args = decl.typeParams.map((tp) => typeParamRef(tp, t));
  t.globals.declTypes.set(decl, mkTrait(sym, args));
  for (const member of decl.members) declareFn(member, t, diags);
}

function declareImpl(decl: A.ImplDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  lowerExprAsType(decl.forType, t, diags);
  for (const ta of decl.traitArgs) lowerExprAsType(ta, t, diags);
  for (const member of decl.members) declareFn(member, t, diags);

  // Reject `T implements Into(T)` at the impl site — surfaces the
  // diagnostic where the user wrote the bad impl, not at the first call
  // that fails to find a coercion.
  if (decl.traitName === CORE_TRAITS.Into && decl.traitArgs.length === 1) {
    const forType = t.globals.typeExprTypes.get(decl.forType);
    const targetType = t.globals.typeExprTypes.get(decl.traitArgs[0]!);
    if (forType !== undefined && targetType !== undefined
        && forType.kind !== "Unresolved" && targetType.kind !== "Unresolved"
        && equalsType(forType, targetType)) {
      err(diags, "T3039", decl.span,
        `\`${displayType(forType)} implements Into(${displayType(targetType)})\` — source and target must differ`);
    }
  }

  // Layer 8b — verify the impl block provides every method the trait
  // requires. SAM-synthetic and `@intrinsic` impls already materialise
  // members in the resolver before reaching here, so the check naturally
  // skips them ; only explicit-body impls with a literal hole trip T3036.
  const traitSym = t.resolved.module.symbols.get(decl.traitName)
    ?? lookupImportedTrait(decl.traitName, t);
  if (traitSym === null || traitSym.source.kind !== "trait") return;
  const traitDecl = traitSym.source.decl;
  const provided = new Set(decl.members.map((m) => m.name));
  for (const required of traitDecl.members) {
    if (!provided.has(required.name)) {
      err(diags, "T3036", decl.traitNameSpan,
        `\`${traitDecl.name}\` requires method \`${required.name}\` — not provided in this impl block`);
    }
  }

  // Inherit the trait's return type onto expression-bodied impl members
  // that omit `-> T`. Without this, `fn turn_left(self) = match self { ... }`
  // inside `Direction implements Turnable` (where the trait says
  // `fn turn_left(self) -> Self`) leaves the return type Unresolved, and the
  // dot-shorthand arms `.West` / `.North` ... can't find their enum context.
  // Substitution applies Self → forType plus any trait-typeparam → traitArg.
  const forType = t.globals.typeExprTypes.get(decl.forType) ?? TY.unresolved;
  const traitArgTypes = decl.traitArgs.map(
    (ta) => t.globals.typeExprTypes.get(ta) ?? TY.unresolved,
  );
  const traitParamSubst = buildStructSubst(
    traitDecl.typeParams, traitArgTypes, t.globals.typeParamSymbols,
  );
  for (const member of decl.members) {
    if (member.returnType !== null) continue;
    const traitMember = traitDecl.members.find((m) => m.name === member.name);
    if (traitMember === undefined || traitMember.returnType === null) continue;
    const traitFnType = t.globals.declTypes.get(traitMember);
    if (traitFnType === undefined || traitFnType.kind !== "Fn") continue;
    if (traitFnType.returnType.kind === "Unresolved") continue;
    const inherited = substitute(traitFnType.returnType,
      { self: forType, typeParams: traitParamSubst.typeParams });
    const implFnType = t.globals.declTypes.get(member);
    if (implFnType === undefined || implFnType.kind !== "Fn") continue;
    if (implFnType.returnType.kind !== "Unresolved") continue;
    t.globals.declTypes.set(member, mkFn(implFnType.params, inherited));
  }
}

function lookupImportedTrait(name: string, t: MutableTyped): Symbol | null {
  // Scoped trait name inside an impl decl — the resolver has already wired
  // it through the module's import table. Recover the redirected target
  // for the typecheck-side member-list check.
  for (const sym of t.resolved.module.symbols.values()) {
    if (sym.name === name && sym.source.kind === "trait") return sym;
  }
  return null;
}

function symbolFor(decl: A.StructDecl | A.TraitDecl, t: MutableTyped): Symbol | null {
  return t.resolved.module.symbols.get(decl.name) ?? null;
}

function typeParamRef(tp: A.TypeParam, t: MutableTyped): Type {
  const sym = t.resolved.typeParams.get(tp);
  if (sym !== undefined) return mkTypeParam(sym);
  // Resolver didn't record this typeParam — leave it Unresolved rather than
  // synthesising a fake Symbol that would alias every other unrecorded one.
  return TY.unresolved;
}
