// Lowers `A.TypeExpr` nodes into the type-checker's `Type` domain. Resolves
// named types via the resolver's symbol table, instantiates generics, and
// rewrites primitives, function types, arrays, unions, and `$T` typeParams.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { Type } from "../types.ts";
import { TY, substitute, unionOf } from "../types.ts";

import type { MutableTyped } from "../ctx.ts";

export function lowerTypeExpr(expr: A.TypeExpr, t: MutableTyped, diags: DiagnosticCollector): Type {
  const result = lowerTypeExprInner(expr, t, diags);
  t.globals.typeExprTypes.set(expr, result);
  return result;
}

function lowerTypeExprInner(expr: A.TypeExpr, t: MutableTyped, diags: DiagnosticCollector): Type {
  switch (expr.kind) {
    case "IdentExpr": {
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
    case "TupleTypeExpr":
      return { kind: "Tuple", elements: expr.elements.map((e) => lowerTypeExpr(e, t, diags)) };
    case "TypeParamType": {
      const sym = t.resolved.typeParamTypes.get(expr);
      if (sym !== undefined) return { kind: "TypeParam", symbol: sym };
      return TY.unresolved;
    }
  }
}

export function typeFromSymbol(
  sym: Symbol, args: readonly Type[],
  at: A.TypeExpr, t: MutableTyped, diags: DiagnosticCollector,
): Type {
  switch (sym.kind) {
    case "builtin-type":  return primitiveFromName(sym.name) ?? TY.unresolved;
    case "struct":        return { kind: "Struct", symbol: sym, args };
    case "enum": {
      const decl = sym.source.kind === "enum" ? sym.source.decl : null;
      const declared = decl !== null ? t.globals.declTypes.get(decl) : undefined;
      if (declared !== undefined && declared.kind === "Enum") return declared;
      return { kind: "Enum", symbol: sym, repr: "i32", indices: new Map() };
    }
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

export function primitiveFromName(name: string): Type | null {
  switch (name) {
    case "i8": case "i16": case "i32": case "i64":
    case "u8": case "u16": case "u32": case "u64": case "usize":
    case "f32": case "f64":
    case "bool": case "char": case "string": case "void": case "null":
      return { kind: "Primitive", name };
    case "int":    return { kind: "Primitive", name: "i32" };
    case "long":   return { kind: "Primitive", name: "i64" };
    case "float":  return { kind: "Primitive", name: "f32" };
    case "double": return { kind: "Primitive", name: "f64" };
    case "byte":   return { kind: "Primitive", name: "u8" };
    case "Self":
      // Substituted at body-check time when we know the surrounding impl's target.
      return TY.self;
  }
  return null;
}
