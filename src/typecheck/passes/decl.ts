// Decl-level type computation. Walks every top-level decl and records its
// declared type into `Globals.declTypes` so later body-checking can resolve
// cross-decl references (calls, struct field types, etc.) before any function
// body is checked.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { isTypeReferenceSymbol } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { PrimitiveName, Type } from "../types.ts";
import { ALL_INTS, TY } from "../types.ts";

import type { MutableTyped } from "../ctx.ts";
import { lowerExprAsType } from "./type-expr.ts";

/** Syntactic predicate : does `expr` look like a type expression in the
 *  Layer 4-sugar sense ? Used by the implicit-type-alias promotion in the
 *  ConstDecl declarer to decide whether to lower the RHS as a type before
 *  any body has been checked. We can't call `lowerExprAsType` blindly —
 *  it emits diagnostics for non-type Exprs — so this is the gate. */
function looksLikeTypeExpression(expr: A.Expr, t: MutableTyped): boolean {
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
  t.globals.declTypes.set(decl, { kind: "Fn", params, returnType });
}

function declareEnum(decl: A.EnumDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  const sym = t.resolved.module.symbols.get(decl.name);
  if (sym === undefined) return;
  const repr = resolveEnumRepr(decl, t, diags);
  const indices = resolveEnumIndices(decl, repr, diags);
  t.globals.declTypes.set(decl, { kind: "Enum", symbol: sym, repr, indices });
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
  t.globals.declTypes.set(decl, { kind: "Struct", symbol: sym, args });
  for (const f of decl.fields) lowerExprAsType(f.type, t, diags);
}

function declareTrait(decl: A.TraitDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  const sym = symbolFor(decl, t);
  if (sym === null) return;
  const args = decl.typeParams.map((tp) => typeParamRef(tp, t));
  t.globals.declTypes.set(decl, { kind: "Trait", symbol: sym, args });
  for (const member of decl.members) declareFn(member, t, diags);
}

function declareImpl(decl: A.ImplDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  lowerExprAsType(decl.forType, t, diags);
  for (const ta of decl.traitArgs) lowerExprAsType(ta, t, diags);
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
