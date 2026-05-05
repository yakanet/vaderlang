// Decl-level type computation. Walks every top-level decl and records its
// declared type into `Globals.declTypes` so later body-checking can resolve
// cross-decl references (calls, struct field types, etc.) before any function
// body is checked.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { Type } from "../types.ts";
import { TY } from "../types.ts";

import type { MutableTyped } from "../ctx.ts";
import { lowerTypeExpr } from "./type-expr.ts";

export function declareType(decl: A.Decl, t: MutableTyped, diags: DiagnosticCollector): void {
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

function declareStruct(decl: A.StructDecl, t: MutableTyped, diags: DiagnosticCollector): void {
  const sym = symbolFor(decl, t);
  if (sym === null) return;
  const args = decl.typeParams.map((tp) => typeParamRef(tp, t));
  t.globals.declTypes.set(decl, { kind: "Struct", symbol: sym, args });
  for (const f of decl.fields) lowerTypeExpr(f.type, t, diags);
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
  for (const ta of decl.traitArgs) lowerTypeExpr(ta, t, diags);
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
