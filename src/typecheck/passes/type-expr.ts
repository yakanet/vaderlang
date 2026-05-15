// Lowers an AST expression occurring in *type position* into the typechecker's
// `Type` domain. Since Layer 1.D the input is `A.Expr` (not the former
// `A.TypeExpr` union, now an alias for `A.Expr`) — the parser's main Pratt
// loop is the single entry point that produces both type-shaped and
// value-shaped expressions, and dispatch happens here on `expr.kind`.
//
// Resolves named types via the resolver's symbol table, instantiates generics,
// and lowers primitives, function types, arrays, unions, and `$T` type-params.
// For expression shapes that have no meaning as a type today (literals, arith,
// etc.), returns `TY.unresolved` and emits a diagnostic — Layer 4-sugar will
// fold in comptime evaluation so any comptime-known `type`-valued expression
// can be accepted here.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import { collectUnionVariants } from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { Type } from "../types.ts";
import { TY, mkArray, mkEnum, mkFn, mkStruct, mkTrait, mkTuple, mkTypeParam, substitute, unionOf } from "../types.ts";

import { buildStructSubst, type MutableTyped } from "../ctx.ts";

export function lowerExprAsType(expr: A.Expr, t: MutableTyped, diags: DiagnosticCollector): Type {
  const result = lowerExprAsTypeInner(expr, t, diags);
  t.globals.typeExprTypes.set(expr, result);
  return result;
}

function lowerExprAsTypeInner(expr: A.Expr, t: MutableTyped, diags: DiagnosticCollector): Type {
  switch (expr.kind) {
    case "IdentExpr": {
      // After the 1.B.2 merge, `IdentExpr` covers both former `NamedType`
      // (regular type names) and former `TypeParamType` (`$T` introductions
      // and subsequent param references). Type-param symbols land in
      // `typeParamTypes` ; everything else lands in `types`. We try the
      // type-param table first since the resolver only stores there for
      // type-param symbols. Layer 4-sugar fallback : when the same node was
      // walked by `resolveExpr` (value-position lookup, e.g. `Mixed :: i32`
      // where `i32` lives in an Expr slot), the symbol lands in `idents`
      // instead — try it last so type-position references still work.
      const tpSym = t.resolved.typeParamTypes.get(expr);
      if (tpSym !== undefined) return mkTypeParam(tpSym);
      const sym = t.resolved.types.get(expr) ?? t.resolved.idents.get(expr);
      if (sym === undefined) return TY.unresolved;     // resolver already reported R2007
      return typeFromSymbol(sym, [], expr, t, diags);
    }
    case "GenericInstExpr": {
      // Type-position GenericInstExpr : the callee is an IdentExpr for
      // bare names (`Foo[i32]`) or a FieldExpr for qualified names
      // (`op.Foo[i32]`). The qualified form pulls the resolved symbol
      // out of `fieldRefs` (populated by `resolveType`'s FieldExpr arm).
      let sym: Symbol | undefined;
      if (expr.callee.kind === "IdentExpr") {
        sym = t.resolved.types.get(expr.callee);
      } else if (expr.callee.kind === "FieldExpr") {
        const ref = t.resolved.fieldRefs.get(expr.callee);
        if (ref?.kind === "namespace") sym = ref.symbol;
      }
      if (sym === undefined) return TY.unresolved;
      const args = expr.typeArgs.map((a) => lowerExprAsType(a, t, diags));
      return typeFromSymbol(sym, args, expr, t, diags);
    }
    case "FieldExpr": {
      // Qualified type reference `module.Type` — the resolver bound the
      // exported symbol into `fieldRefs` with kind "namespace". The typer
      // serves it like a bare type name.
      const ref = t.resolved.fieldRefs.get(expr);
      if (ref?.kind !== "namespace") return TY.unresolved;
      return typeFromSymbol(ref.symbol, [], expr, t, diags);
    }
    case "BinaryExpr": {
      // Type-position `T | U` is a `bitor` chain since 1.B.5.
      // Flatten the chain via the AST helper, then build a Union type
      // from each variant in source order. Other binary ops do not
      // appear in type position today (parser invariant).
      if (expr.op !== "bitor") return TY.unresolved;
      const variants = collectUnionVariants(expr);
      return unionOf(variants.map((v) => lowerExprAsType(v as A.TypeExpr, t, diags)));
    }
    case "FnTypeExpr":
      return mkFn(
        expr.params.map((p) => lowerExprAsType(p, t, diags)),
        expr.returnType === null ? TY.void : lowerExprAsType(expr.returnType, t, diags),
      );
    case "ArrayTypeExpr":
      return mkArray(lowerExprAsType(expr.element, t, diags), expr.immutable === true);
    case "NullLitExpr":
      // `null` in type position : the null primitive. Reached when the
      // body of a type-shaped expression was parsed via `parseExpr` (the
      // Pratt parser produces `NullLitExpr` for the `null` keyword in
      // expression context, vs. `parseTypePrimary` which produces an
      // `IdentExpr` for the same keyword in type context). Both surface
      // the same underlying type.
      return TY.null;
    case "SeqLitExpr":
      // Bracketed `[T1, T2, ...]` in type position lowers to a tuple type.
      // Element nodes are guaranteed type-shaped here ; the cast is safe.
      return mkTuple(expr.elements.map((e) => lowerExprAsType(e as A.TypeExpr, t, diags)));
    default:
      // Layer 1.D — the function accepts any `Expr`, but only the cases above
      // have a current type interpretation. Reaching here means the parser
      // produced a value-shaped expression in a type-demanding slot — by
      // current parser invariants this should not happen, so we surface a
      // `T3002` (« expected an expression of a known type »). Under
      // Layer 4-sugar this branch will attempt comptime evaluation and
      // accept the result if it is a `type` value.
      err(diags, "T3002", expr.span,
        `expected a type expression, got \`${expr.kind}\``);
      return TY.unresolved;
  }
}

export function typeFromSymbol(
  sym: Symbol, args: readonly Type[],
  at: A.TypeExpr, t: MutableTyped, diags: DiagnosticCollector,
): Type {
  switch (sym.kind) {
    case "builtin-type":  return primitiveFromName(sym.name) ?? TY.unresolved;
    case "struct":        return mkStruct(sym, args);
    case "enum": {
      const decl = sym.source.kind === "enum" ? sym.source.decl : null;
      const declared = decl !== null ? t.globals.declTypes.get(decl) : undefined;
      if (declared !== undefined && declared.kind === "Enum") return declared;
      return mkEnum(sym, "i32", new Map());
    }
    case "trait":         return mkTrait(sym, args);
    case "type-param":    return mkTypeParam(sym);
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
        // Resolve type-param symbols via the cross-module `typeParamSymbols`
        // table — `bindTypeParam` registers them there during resolveModule.
        // The previous lookup via `module.symbols.get(name)` failed because
        // type-params live in their decl's local scope, not the module table.
        return substitute(base, buildStructSubst(params, args, t.globals.typeParamSymbols));
      }
      return base;
    }
    case "const":
      // Layer 4-sugar — when a const's value is a type expression (e.g.
      // `Mixed :: i32 | string`), `typeFromSymbol` serves the *underlying*
      // type so the const name is usable in type-demanding slots. Regular
      // value consts (`PI :: 3.14`) reach the default and stay unresolved
      // — they aren't valid type names.
      if (sym.source.kind === "const") {
        const aliased = t.globals.constTypeAliases.get(sym.source.decl);
        if (aliased !== undefined) return aliased;
      }
      return TY.unresolved;
    case "local": {
      // Layer 5b — `t :: <type-expr>` inside a fn body acts as an in-fn
      // type alias. The resolved underlying type is stashed in
      // `letTypeAliases` keyed by the local's symbol.
      const aliased = t.globals.letTypeAliases.get(sym);
      if (aliased !== undefined) return aliased;
      return TY.unresolved;
    }
    default:
      return TY.unresolved;
  }
}

export function primitiveFromName(name: string): Type | null {
  switch (name) {
    case "i8": case "i16": case "i32": case "i64": case "isize":
    case "u8": case "u16": case "u32": case "u64": case "usize":
    case "f32": case "f64":
    case "bool": case "char": case "string": case "void": case "null":
      return { kind: "Primitive", name };
    case "type":
      // Comptime-only metatype. Lowers to the dedicated `TypeMeta` Type
      // variant (TY.type) rather than a `Primitive` — the metatype is
      // structurally distinct from runtime primitives. Layer 2.A registers
      // the name so `: type` annotations resolve uniformly ; full integration
      // (comptime contagion, type-as-value evaluation) lands in Layer 4-sugar.
      return TY.type;
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
