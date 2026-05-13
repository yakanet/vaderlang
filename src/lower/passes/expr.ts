// Top-level expression lowerer. Dispatches by AST kind and delegates string
// interp, match, try, range, and for-in to their dedicated passes.

import type * as A from "../../parser/ast.ts";
import { staticStringValue, unreachableTypeExprInValuePosition } from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf, sourceStructDecl } from "../../resolver/symbol.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_TRAITS, TY, alignOfType, canonicalArgsKey, defaultIfFree, displayType, equalsType, fieldCountOfType, kindStringOfType, sizeOfType, variantCountOfType } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredBlock, LoweredExpr, LoweredIf, LoweredStmt, LoweredStructLitField } from "../lowered-ast.ts";
import { err } from "../diag.ts";

import { lowerBlock } from "./block.ts";
import { findCoreTrait } from "./core.ts";
import { wrapAsInto } from "./display-coerce.ts";
import { lookupImplEntry, lookupImplFor, lowerRangeExpr } from "./for-in.ts";
import { blockStmtsWithTrailing, freshSyntheticSymbol, loweredEnumVariant, wrapAsBlock } from "./helpers.ts";
import { lowerLambda } from "./lambda.ts";
import { lowerMatch } from "./match.ts";
import { lowerStringLit } from "./string-interp.ts";
import { lowerTry } from "./try.ts";

export function lowerExpr(ctx: FnLowerCtx, expr: A.Expr): LoweredExpr {
  const lowered = lowerExprInner(ctx, expr);
  const intoCoercion = ctx.typed.intoCoercions.get(expr);
  if (intoCoercion !== undefined) {
    const wrapped = wrapAsInto(ctx, lowered, intoCoercion, expr.span);
    if (wrapped !== null) return wrapped;
  }
  return lowered;
}

function lowerExprInner(ctx: FnLowerCtx, expr: A.Expr): LoweredExpr {
  const exprType = ctx.types.exprType(expr);
  switch (expr.kind) {
    case "IntLitExpr":
      return { kind: "LoweredIntLit", span: expr.span, type: defaultIfFree(exprType), value: expr.value };
    case "FloatLitExpr":
      return { kind: "LoweredFloatLit", span: expr.span, type: defaultIfFree(exprType), value: expr.value };
    case "BoolLitExpr":
      return { kind: "LoweredBoolLit", span: expr.span, type: TY.bool, value: expr.value };
    case "NullLitExpr":
      return { kind: "LoweredNullLit", span: expr.span, type: TY.null };
    case "CharLitExpr":
      return { kind: "LoweredCharLit", span: expr.span, type: TY.char, value: expr.value };
    case "StringLitExpr":
      return lowerStringLit(ctx, expr);
    case "IdentExpr":
      return lowerIdent(ctx, expr, exprType);
    case "CallExpr": {
      if (expr.callee.kind === "IdentExpr") {
        const resolverSym = ctx.typed.resolved.idents.get(expr.callee);
        // Direct-call overload override: typecheck recorded a non-primary
        // sibling overload as the matched candidate. Use that symbol for the
        // rest of the lowering (generic instance lookup + plain call emit).
        const calleeSym = ctx.typed.directCallOverloads.get(expr) ?? resolverSym;
        // Cast call `Type(value)` — lower to a `LoweredCast` so the bytecode
        // emitter inserts a convert op (otherwise it'd treat the type symbol
        // as a callable and emit `unreachable`). For non-numeric targets
        // (`UserId(value)`, `MyEnum(value)`), the typer already routed the
        // arg through `tryInto` so `lowerExpr(arg)` returns the wrapped
        // value at the target type — emit it directly without a cast op.
        if (calleeSym !== undefined
            && (calleeSym.kind === "builtin-type" || calleeSym.kind === "struct" || calleeSym.kind === "type-alias")
            && expr.args.length === 1) {
          const loweredArg = lowerExpr(ctx, expr.args[0]!.value);
          const isNumericCast = exprType.kind === "Primitive"
            && (exprType.name !== "string" && exprType.name !== "bool"
                && exprType.name !== "void" && exprType.name !== "null");
          if (!isNumericCast) return loweredArg;
          return { kind: "LoweredCast", span: expr.span, type: exprType, value: loweredArg };
        }
        const typeArgs = ctx.typed.genericFnCalls.get(expr);
        if (typeArgs !== undefined && calleeSym !== undefined) {
          const fnDecl = declOf(calleeSym);
          if (fnDecl !== null && fnDecl.kind === "FnDecl") {
            const entry = lookupFnInstance(ctx, fnDecl, typeArgs);
            if (entry !== null) {
              return {
                kind: "LoweredCall", span: expr.span, type: exprType,
                callee: { kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: entry.symbol! },
                args: expr.args.map((a) => lowerExpr(ctx, a.value)),
              };
            }
          }
        }
        // Non-generic direct call to a chosen overload: synthesise a
        // LoweredCall whose callee is the chosen symbol (the resolver's
        // primary would route to the wrong fn entry otherwise).
        if (calleeSym !== resolverSym && calleeSym !== undefined) {
          return {
            kind: "LoweredCall", span: expr.span, type: exprType,
            callee: { kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: calleeSym },
            args: expr.args.map((a) => lowerExpr(ctx, a.value)),
          };
        }
      }
      // GenericInstExpr callee (explicit `foo(T)(args)` form, if the parser ever produces it).
      if (expr.callee.kind === "GenericInstExpr" && expr.callee.callee.kind === "IdentExpr") {
        const innerSym = ctx.typed.resolved.idents.get(expr.callee.callee);
        if (innerSym !== undefined) {
          const fnDecl = declOf(innerSym);
          if (fnDecl !== null && fnDecl.kind === "FnDecl" && fnDecl.typeParams.length > 0) {
            const typeArgs = expr.callee.typeArgs.map((ta) => ctx.types.typeExprType(ta));
            const entry = lookupFnInstance(ctx, fnDecl, typeArgs);
            if (entry !== null) {
              return {
                kind: "LoweredCall", span: expr.span, type: exprType,
                callee: { kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: entry.symbol! },
                args: expr.args.map((a) => lowerExpr(ctx, a.value)),
              };
            }
          }
        }
      }
      // Trait method via UFCS: typecheck recorded a MethodResolution on the
      // FieldExpr callee. Rewrite into a direct call of the impl's specialised
      // fn with the receiver as the first argument. For generic impls, the
      // right specialisation is keyed by the receiver's struct args.
      if (expr.callee.kind === "FieldExpr") {
        // Module-namespace call — `fs.println(...)` after `import "..." as fs`.
        // The resolver wired the FieldExpr to the exported symbol ; we lower
        // straight to a direct call against that symbol, same as a regular
        // top-level call. Without this the FieldExpr falls through to the
        // generic LoweredFieldAccess path and the bytecode emit crashes
        // looking for a struct.
        const calleeRef = ctx.typed.resolved.fieldRefs.get(expr.callee);
        const exported = calleeRef?.kind === "namespace" ? calleeRef.symbol : undefined;
        if (exported !== undefined && exported.kind === "fn") {
          const typeArgs = ctx.typed.genericFnCalls.get(expr);
          const fnDecl = declOf(exported);
          if (typeArgs !== undefined && fnDecl !== null && fnDecl.kind === "FnDecl") {
            const entry = lookupFnInstance(ctx, fnDecl, typeArgs);
            if (entry !== null) {
              return {
                kind: "LoweredCall", span: expr.span, type: exprType,
                callee: { kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: entry.symbol! },
                args: expr.args.map((a) => lowerExpr(ctx, a.value)),
              };
            }
          }
          return {
            kind: "LoweredCall", span: expr.span, type: exprType,
            callee: { kind: "LoweredIdent", span: expr.callee.span, type: exprType, symbol: exported },
            args: expr.args.map((a) => lowerExpr(ctx, a.value)),
          };
        }
        // Single lookup into the discriminated FieldResolution; the six
        // call-shaped cases are mutually exclusive by construction
        // (typechecker invariant).
        const fr = ctx.typed.fieldResolutions.get(expr.callee);
        switch (fr?.kind) {
          case "array-op":
            if (fr.op === "len") {
              return {
                kind: "LoweredArrayLen", span: expr.span, type: TY.usize,
                target: lowerExpr(ctx, expr.callee.target),
              };
            }
            return {
              kind: "LoweredArrayPush", span: expr.span, type: TY.void,
              target: lowerExpr(ctx, expr.callee.target),
              value: lowerExpr(ctx, expr.args[0]!.value),
            };
          case "method": {
            // Apply the current entry's substitution to the receiver so that
            // when this call lives inside a generic impl member (e.g. a default
            // `count` cloned into `Range[T]`), the lookup sees concrete args
            // like `[i32]` rather than `[TypeParam($T)]`.
            const recv = ctx.types.apply(fr.resolution.receiverType);
            const args = recv.kind === "Struct" ? recv.args : [];
            const entry = lookupImplEntry(ctx, fr.resolution.member, args);
            if (entry !== null && entry.symbol !== null) {
              return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol);
            }
            break;
          }
          case "trait-method": {
            // Apply call-site substitution to the receiver TypeParam, then
            // look up the impl member just like a regular method call.
            const concreteRecv = ctx.types.apply(fr.resolution.receiverParam);
            const impl = lookupImplFor(ctx.project, concreteRecv, fr.resolution.trait);
            if (impl !== null) {
              const member = impl.decl.members.find((m) => m.name === fr.resolution.member.name);
              if (member !== undefined) {
                const structArgs = concreteRecv.kind === "Struct" ? concreteRecv.args : [];
                const entry = lookupImplEntry(ctx, member, structArgs);
                if (entry !== null && entry.symbol !== null) {
                  return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol);
                }
              }
            }
            break;
          }
          case "trait-virtual": {
            const dispatched = lowerVirtualDispatch(
              ctx, expr, expr.callee, exprType, fr.resolution.trait, fr.resolution.member.name,
            );
            if (dispatched !== null) return dispatched;
            break;
          }
          case "ufcs-free": {
            const ufcsTypeArgs = ctx.typed.genericFnCalls.get(expr);
            if (ufcsTypeArgs !== undefined) {
              const fnDecl = declOf(fr.symbol);
              if (fnDecl !== null && fnDecl.kind === "FnDecl") {
                const entry = lookupFnInstance(ctx, fnDecl, ufcsTypeArgs);
                if (entry !== null) return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol!);
              }
            }
            return lowerUfcsCall(ctx, expr, expr.callee, exprType, fr.symbol);
          }
          case "union-field":
          case undefined:
            // union-field never appears in a call callee position; undefined
            // means no resolution was recorded — fall through to the generic
            // CallExpr emit below.
            break;
        }
      }
      return {
        kind: "LoweredCall", span: expr.span, type: exprType,
        callee: lowerExpr(ctx, expr.callee),
        args: expr.args.map((a) => lowerExpr(ctx, a.value)),
      };
    }
    case "FieldExpr": {
      // Module-namespace member used as a value (rare — most are calls,
      // which the CallExpr branch above intercepts). Lower to the exported
      // symbol's identifier directly.
      const fieldRef = ctx.typed.resolved.fieldRefs.get(expr);
      if (fieldRef?.kind === "namespace") {
        return { kind: "LoweredIdent", span: expr.span, type: exprType, symbol: fieldRef.symbol };
      }
      // Common-field access on a union receiver (§1.18d) — typecheck
      // recorded the per-variant `(type, fieldType)` pairs ; emit the
      // variant-dispatch cascade.
      const fr = ctx.typed.fieldResolutions.get(expr);
      if (fr?.kind === "union-field") return lowerUnionFieldAccess(ctx, expr, exprType, fr.resolution);
      // Both `Enum.Variant` and `e.method` leave targetType as the enum ;
      // only the variant form has a name that's actually in `indices`.
      const targetType = ctx.types.exprType(expr.target);
      if (targetType.kind === "Enum" && targetType.indices.has(expr.field)) {
        return loweredEnumVariant(targetType, expr.field, expr.span);
      }
      // Numeric tuple field access `t.0` → `_0` synthetic field on the
      // anonymous struct that backs the tuple type.
      const fieldName = expr.isNumeric === true ? `_${expr.field}` : expr.field;
      return {
        kind: "LoweredFieldAccess", span: expr.span, type: exprType,
        target: lowerExpr(ctx, expr.target), field: fieldName,
      };
    }
    case "IndexExpr": {
      const indexRes = ctx.typed.indexResolutions.get(expr);
      if (indexRes !== undefined) {
        return lowerIndexTraitCall(ctx, expr, exprType, indexRes, /*extraArgs*/ []);
      }
      return {
        kind: "LoweredIndex", span: expr.span, type: exprType,
        target: lowerExpr(ctx, expr.target),
        index: lowerExpr(ctx, expr.index),
      };
    }
    case "UnaryExpr":
      return {
        kind: "LoweredUnary", span: expr.span, type: exprType,
        op: expr.op, operand: lowerExpr(ctx, expr.operand),
      };
    case "BinaryExpr":
      return lowerBinary(ctx, expr, exprType);
    case "IfExpr":
      return lowerIf(ctx, expr, exprType);
    case "MatchExpr":
      return lowerMatch(ctx, expr, exprType);
    case "BlockExpr":
      return lowerBlock(ctx, expr, /*isFnRoot*/ false, /*isLoopBody*/ false);
    case "LambdaExpr":
      return lowerLambda(ctx, expr);
    case "StructLitExpr":
      return lowerStructLit(ctx, expr, exprType);
    case "SeqLitExpr":
      // Branch on the typecheck'd type :
      //   - Array(T) → LoweredArrayLit (existing path)
      //   - Tuple([T0..Tn-1]) → LoweredStructLit with synthetic fields _0,_1...
      // Tuples are lowered as anonymous structs ; the BC type table emits a
      // `BcStruct{name="__Tuple_n", fields:_0/_1/...}` entry on first use.
      if (exprType.kind === "Tuple") {
        return {
          kind: "LoweredStructLit", span: expr.span, type: exprType,
          fields: expr.elements.map<LoweredStructLitField>((e, i) => ({
            name: `_${i}`,
            value: lowerExpr(ctx, e),
          })),
        };
      }
      return {
        kind: "LoweredArrayLit", span: expr.span, type: exprType,
        elements: expr.elements.map((e) => lowerExpr(ctx, e)),
      };
    case "RangeExpr":
      return lowerRangeExpr(ctx, expr, exprType);
    case "TryExpr":
      return lowerTry(ctx, expr, exprType);
    case "DotVariantExpr":
      return loweredEnumVariant(exprType, expr.variant, expr.span);
    case "CastExpr":
      return {
        kind: "LoweredCast", span: expr.span, type: exprType,
        value: lowerExpr(ctx, expr.value),
      };
    case "GenericInstExpr":
      return lowerExpr(ctx, expr.callee);     // type-args baked in post-mono
    case "IntrinsicCallExpr":
      return lowerIntrinsic(ctx, expr, exprType);
    case "FnTypeExpr":
    case "ArrayTypeExpr":
      // Type-shaped value expressions only ever reach the lower phase as
      // the body of a type alias (`t :: i32[]` or top-level
      // `Foo :: fn(i32) -> i32`). The let / const-decl lowering skips
      // emission for those via `letTypeAliases` / `constTypeAliases`, so
      // reaching here is an internal-bug : the alias detection or the
      // skip path drifted.
      return unreachableTypeExprInValuePosition(expr);
  }
}

/** Fold a reflection intrinsic to a constant. The typechecker already
 *  recorded the type of each type-shape arg in `typeExprTypes` ; we look
 *  it up and emit the corresponding scalar literal. Layer 6 — see
 *  DESIGN_TYPE_FIRST.md §12. */
function lowerIntrinsic(
  ctx: FnLowerCtx, expr: A.IntrinsicCallExpr, type: Type,
): LoweredExpr {
  // Helpers : the four `usize` and the two `string` intrinsics share the
  // same shape — read `args[0]`'s resolved Type, run a Type→scalar helper,
  // wrap as a literal. The two outliers (`field_index`, `satisfies`) need
  // extra inputs so they stay inline.
  const intLit = (value: number): LoweredExpr =>
    ({ kind: "LoweredIntLit", span: expr.span, type, value: BigInt(value) });
  const strLit = (value: string): LoweredExpr =>
    ({ kind: "LoweredStringLit", span: expr.span, type, value });
  const targetTy = ctx.typed.typeExprTypes.get(expr.args[0]!);

  switch (expr.name) {
    case "size_of":       return intLit(targetTy !== undefined ? sizeOfType(targetTy) : 0);
    case "align_of":      return intLit(targetTy !== undefined ? alignOfType(targetTy) : 0);
    case "field_count":   return intLit(targetTy !== undefined ? fieldCountOfType(targetTy) : 0);
    case "variant_count": return intLit(targetTy !== undefined ? variantCountOfType(targetTy) : 0);
    case "type_name":     return strLit(targetTy !== undefined ? displayType(targetTy) : "?");
    case "type_kind":     return strLit(targetTy !== undefined ? kindStringOfType(targetTy) : "unknown");
    case "field_index": {
      // Typechecker validated : args[0] is a Struct, args[1] is a static
      // string literal naming an existing field.
      const nameArg = expr.args[1]!;
      const fieldName = nameArg.kind === "StringLitExpr" ? staticStringValue(nameArg) : null;
      let idx = 0;
      if (targetTy !== undefined && targetTy.kind === "Struct" && fieldName !== null
          && targetTy.symbol.source.kind === "struct") {
        const found = targetTy.symbol.source.decl.fields.findIndex((f) => f.name === fieldName);
        if (found >= 0) idx = found;
      }
      return intLit(idx);
    }
    case "satisfies": {
      // True iff `T` has an explicit impl of `Trait` — foundation for the
      // future automatic bound enforcement (Layer 7e).
      const traitTy = ctx.typed.typeExprTypes.get(expr.args[1]!);
      const value = targetTy !== undefined && traitTy !== undefined && traitTy.kind === "Trait"
        && ctx.project.impls.findFor(targetTy, traitTy.symbol) !== null;
      return { kind: "LoweredBoolLit", span: expr.span, type, value };
    }
    case "file": {
      // Comptime pre-pass already read the file ; lookup is the bake.
      const baked = ctx.project.evaluated.fileExprs.get(expr);
      return baked !== undefined
        ? strLit(baked)
        : { kind: "LoweredUnreachable", span: expr.span, type, reason: "@file failed to bake" };
    }
  }
  return { kind: "LoweredUnreachable", span: expr.span, type, reason: `unhandled intrinsic @${expr.name}` };
}

function lowerIdent(ctx: FnLowerCtx, expr: A.IdentExpr, type: Type): LoweredExpr {
  const sym = ctx.typed.resolved.idents.get(expr);
  if (sym === undefined) {
    return { kind: "LoweredUnreachable", span: expr.span, type, reason: `unresolved ident ${expr.name}` };
  }
  // Lifted-fn context: an outer-captured symbol referenced inside the body
  // is reached through `env.cap_X` (yielding the cell), then CellGet for the
  // value. We never resolve to the bare outer symbol here — the lifted fn
  // has no access to it.
  if (ctx.liftedContext !== null) {
    const fieldName = ctx.liftedContext.captureFields.get(sym.id);
    if (fieldName !== undefined) {
      const envIdent: LoweredExpr = {
        kind: "LoweredIdent", span: expr.span, type: ctx.liftedContext.envType,
        symbol: ctx.liftedContext.envSymbol,
      };
      // FieldAccess yields the cell ref, not the value — env fields are Unresolved.
      const cellRef: LoweredExpr = {
        kind: "LoweredFieldAccess", span: expr.span, type: TY.unresolved,
        target: envIdent, field: fieldName,
      };
      return { kind: "LoweredCellGet", span: expr.span, type, target: cellRef, valueType: type };
    }
  }
  // Captured local in the current scope — read through the cell.
  if (ctx.project.closures.capturedSymbols.has(sym.id)) {
    const cellRef: LoweredExpr = { kind: "LoweredIdent", span: expr.span, type, symbol: sym };
    return { kind: "LoweredCellGet", span: expr.span, type, target: cellRef, valueType: type };
  }
  // Match-arm narrowing: the slot stores the declared union type but the
  // typed-AST has narrowed this access to a concrete variant (e.g. inside
  // `is f64 -> ...`). Insert a LoweredCast so the C emit unboxes via
  // `.payload.f` instead of feeding `vader_box_t` into a primitive op.
  const declared = declaredTypeOfSymbol(ctx, sym);
  if (declared !== null && declared.kind === "Union" && !equalsType(declared, type)) {
    return {
      kind: "LoweredCast", span: expr.span, type,
      value: { kind: "LoweredIdent", span: expr.span, type: declared, symbol: sym },
    };
  }
  return { kind: "LoweredIdent", span: expr.span, type, symbol: sym };
}

function declaredTypeOfSymbol(ctx: FnLowerCtx, sym: Symbol): Type | null {
  if (sym.kind === "param" && sym.source.kind === "param") {
    return ctx.typed.paramTypes.has(sym.source.param) ? ctx.types.paramType(sym.source.param) : null;
  }
  if (sym.kind === "local" && sym.source.kind === "local") {
    return ctx.typed.localTypes.has(sym.source.binding) ? ctx.types.localType(sym.source.binding) : null;
  }
  return null;
}

function lowerBinary(ctx: FnLowerCtx, expr: A.BinaryExpr, exprType: Type): LoweredExpr {
  if (expr.op === "is") {
    const checkType = ctx.typed.binaryIsCheckTypes.get(expr) ?? ctx.types.exprType(expr.right);
    return {
      kind: "LoweredTypeCheck", span: expr.span, type: TY.bool,
      value: lowerExpr(ctx, expr.left), checkType,
    };
  }
  // `(Union) == null` / `(Union) != null` : reduce to a `type_check null`.
  // C-emit can't compare two `vader_box_t` directly — the tag-only check is
  // what we want anyway. Symmetric for `null == X` / `null != X`.
  if (expr.op === "eq" || expr.op === "neq") {
    const left = expr.left;
    const right = expr.right;
    const nullSide = isNullLit(left) && isUnionWithNull(ctx.types.exprType(right)) ? right
                   : isNullLit(right) && isUnionWithNull(ctx.types.exprType(left)) ? left
                   : null;
    if (nullSide !== null) {
      const check: LoweredExpr = {
        kind: "LoweredTypeCheck", span: expr.span, type: TY.bool,
        value: lowerExpr(ctx, nullSide), checkType: TY.null,
      };
      if (expr.op === "eq") return check;
      return { kind: "LoweredUnary", span: expr.span, type: TY.bool, op: "not", operand: check };
    }
  }
  if (expr.op === "in" || expr.op === "not_in") {
    return lowerInOp(ctx, expr);
  }
  const opRes = ctx.typed.binaryOpResolutions.get(expr);
  if (opRes !== undefined) {
    return lowerOverloadedBinary(ctx, expr, exprType, opRes);
  }
  return {
    kind: "LoweredBinary", span: expr.span, type: exprType,
    op: expr.op,
    left: lowerExpr(ctx, expr.left),
    right: lowerExpr(ctx, expr.right),
  };
}

function isNullLit(e: A.Expr): boolean {
  return e.kind === "NullLitExpr";
}

function isUnionWithNull(t: Type): boolean {
  return t.kind === "Union" && t.variants.some((v) => equalsType(v, TY.null));
}

/** Rewrite `a[i]` (or `a[i] = v`) into a direct call against the matched
 *  `Index($I, $T)::at` (or `IndexSet::set_at`) impl member. `extraArgs` is
 *  empty for reads ; for writes it carries the lowered RHS value. */
export function lowerIndexTraitCall(
  ctx: FnLowerCtx, expr: A.IndexExpr, exprType: Type,
  res: IndexResolution,
  extraArgs: readonly LoweredExpr[],
): LoweredExpr {
  const recv = ctx.types.apply(res.receiverType);
  const structArgs = recv.kind === "Struct" ? recv.args : [];
  const entry = lookupImplEntry(ctx, res.member, structArgs);
  if (entry === null || entry.symbol === null) {
    return { kind: "LoweredUnreachable", span: expr.span, type: exprType,
             reason: "unmaterialised Index/IndexSet impl member" };
  }
  return {
    kind: "LoweredCall", span: expr.span, type: exprType,
    callee: { kind: "LoweredIdent", span: expr.span, type: exprType, symbol: entry.symbol },
    args: [lowerExpr(ctx, expr.target), lowerExpr(ctx, expr.index), ...extraArgs],
  };
}

/** Rewrite `a <op> b` into a direct call against the impl member resolved by
 *  the typechecker. Equality/inequality wrap with `bool.not` ; ordering
 *  wraps with a primitive comparison against zero against `compare`'s i32
 *  result. */
function lowerOverloadedBinary(
  ctx: FnLowerCtx, expr: A.BinaryExpr, exprType: Type,
  res: BinaryOpResolution,
): LoweredExpr {
  const recv = ctx.types.apply(res.receiverType);
  const structArgs = recv.kind === "Struct" ? recv.args : [];
  const entry = lookupImplEntry(ctx, res.member, structArgs);
  if (entry === null || entry.symbol === null) {
    return { kind: "LoweredUnreachable", span: expr.span, type: exprType,
             reason: `unmaterialised ${res.kind} impl member` };
  }
  const left = lowerExpr(ctx, expr.left);
  const right = lowerExpr(ctx, expr.right);
  const callType = res.kind === "ord" ? TY.i32 : res.kind === "eq" ? TY.bool : exprType;
  const call: LoweredExpr = {
    kind: "LoweredCall", span: expr.span, type: callType,
    callee: { kind: "LoweredIdent", span: expr.span, type: callType, symbol: entry.symbol },
    args: [left, right],
  };
  if (res.kind === "direct") return call;
  if (res.kind === "eq") {
    if (!res.negate) return call;
    return { kind: "LoweredUnary", span: expr.span, type: TY.bool, op: "not", operand: call };
  }
  // ord : `compare(a, b) <op> 0`
  return {
    kind: "LoweredBinary", span: expr.span, type: TY.bool, op: res.cmp,
    left: call,
    right: { kind: "LoweredIntLit", span: expr.span, type: TY.i32, value: 0n },
  };
}

/** Desugar `x in coll` to `coll.contains(x)`, or `x !in coll` to `!coll.contains(x)`.
 *  Resolves the `Contains($T)::contains` impl on `coll`'s static type and emits a
 *  direct call to the monomorphised symbol. */
function lowerInOp(ctx: FnLowerCtx, expr: A.BinaryExpr): LoweredExpr {
  const collType = ctx.types.exprType(expr.right);
  const fail = (msg: string): LoweredExpr => {
    err(ctx.project.diags, "B5001", expr.span, msg);
    return { kind: "LoweredBoolLit", span: expr.span, type: TY.bool, value: false };
  };
  const containsTrait = findCoreTrait(ctx.project, CORE_TRAITS.Contains);
  if (containsTrait === null) return fail("Contains trait not found in std/core");
  const entry = lookupImplFor(ctx.project, collType, containsTrait);
  if (entry === null) {
    return fail(`\`${expr.op === "in" ? "in" : "!in"}\` requires Contains impl on ${displayType(collType)}`);
  }
  const containsDecl = entry.decl.members.find((m) => m.name === "contains");
  if (containsDecl === undefined) return fail("Contains impl missing `contains` member");
  const structArgs = collType.kind === "Struct" ? collType.args : [];
  const monoEntry = lookupImplEntry(ctx, containsDecl, structArgs);
  if (monoEntry === null || monoEntry.symbol === null) {
    return fail("Contains.contains has no monomorphised instance");
  }
  const call: LoweredExpr = {
    kind: "LoweredCall", span: expr.span, type: TY.bool,
    callee: { kind: "LoweredIdent", span: expr.span, type: TY.bool, symbol: monoEntry.symbol },
    args: [lowerExpr(ctx, expr.right), lowerExpr(ctx, expr.left)],
  };
  if (expr.op === "not_in") {
    return { kind: "LoweredUnary", span: expr.span, type: TY.bool, op: "not", operand: call };
  }
  return call;
}

import type { MonoEntry } from "../../comptime/specialize.ts";
import type {BinaryOpResolution, IndexResolution, UnionFieldResolution} from "../../typecheck/typed-ast.ts";

function lookupFnInstance(ctx: FnLowerCtx, fnDecl: A.FnDecl, typeArgs: readonly Type[]): MonoEntry | null {
  const key = canonicalArgsKey(typeArgs.map((ta) => ctx.types.apply(ta)));
  const entry = ctx.project.mono.fnInstanceEntries.get(fnDecl)?.get(key) ?? null;
  return entry !== null && entry.symbol !== null ? entry : null;
}

function lowerUfcsCall(
  ctx: FnLowerCtx, expr: A.CallExpr, callee: A.FieldExpr, exprType: Type, sym: Symbol,
): LoweredExpr {
  return {
    kind: "LoweredCall", span: expr.span, type: exprType,
    callee: { kind: "LoweredIdent", span: callee.span, type: exprType, symbol: sym },
    args: [
      lowerExpr(ctx, callee.target),
      ...expr.args.map((a) => lowerExpr(ctx, a.value)),
    ],
  };
}

/** Lower `recv.method(args)` where `recv` has a trait type into a single
 *  `LoweredVirtualCall`. The bytecode emit walks `impls.forTrait` + the mono
 *  registry to populate the per-(trait, method) vtable; the VM and C emit
 *  dispatch in O(1) via tag lookup. Returns null when no impl in scope
 *  could ever satisfy the call (caller falls back to the error path). */
function lowerVirtualDispatch(
  ctx: FnLowerCtx, expr: A.CallExpr, callee: A.FieldExpr, exprType: Type,
  traitSym: Symbol, methodName: string,
): LoweredExpr | null {
  // Probe: is there at least one struct impl of this method in scope? If not,
  // signal null so the caller can fall through to the regular call lowering
  // (which will error informatively or compile to `unreachable`).
  let hasAny = false;
  for (const impl of ctx.project.impls.forTrait(traitSym)) {
    // Accept struct impls (forSymbol of source kind "struct") and primitive
    // impls (forSymbol === null with NamedType forType — `i32 implements …`).
    // Type-aliases and other shapes don't dispatch through the vtable.
    if (impl.forSymbol !== null && impl.forSymbol.source.kind !== "struct") continue;
    if (impl.forSymbol === null && impl.decl.forType.kind !== "IdentExpr") continue;
    const member = impl.decl.members.find((m) => m.name === methodName);
    if (member === undefined) continue;
    const perArgs = ctx.project.mono.implMethodEntries.get(member);
    if (perArgs === undefined || perArgs.size === 0) continue;
    hasAny = true;
    break;
  }
  if (!hasAny) return null;

  return {
    kind: "LoweredVirtualCall",
    span: expr.span,
    type: exprType,
    traitName: traitSym.name,
    method: methodName,
    receiver: lowerExpr(ctx, callee.target),
    args: expr.args.map((a) => lowerExpr(ctx, a.value)),
  };
}

export function lowerIf(ctx: FnLowerCtx, expr: A.IfExpr, exprType: Type): LoweredIf {
  const cond = lowerExpr(ctx, expr.cond);
  const then = lowerBlock(ctx, expr.then, false, false);
  let elseBlock: LoweredBlock | null = null;
  if (expr.else !== null) {
    elseBlock = expr.else.kind === "BlockExpr"
      ? lowerBlock(ctx, expr.else, false, false)
      : wrapAsBlock(lowerIf(ctx, expr.else, exprType), expr.else.span);
  }
  // No-else `if` : the body's value is unobservable (the typechecker widens
  // to `T | void`, but `void` has no representation), so force the if to
  // type `void` and discard the then-block's trailing. Without this, the
  // bytecode emitter would synthesise `else; unreachable` and crash on
  // every false branch.
  if (expr.else === null) {
    const thenVoid: LoweredBlock = {
      ...then, stmts: blockStmtsWithTrailing(then), trailing: null, type: TY.void,
    };
    return { kind: "LoweredIf", span: expr.span, type: TY.void, cond, then: thenVoid, else: null };
  }
  return { kind: "LoweredIf", span: expr.span, type: exprType, cond, then, else: elseBlock };
}

/** Lower `e.f` when `e` is a discriminated union and every variant carries
 *  a field named `f` (§1.18d). Synthesises a variant-dispatch cascade:
 *
 *    let __scrut = <e>
 *    if __scrut is V1 { (V1) __scrut.f }
 *    else if __scrut is V2 { (V2) __scrut.f }
 *    else ...
 *
 *  The cast in each arm narrows the runtime payload to the concrete
 *  variant so the existing `LoweredFieldAccess` op reads from the right
 *  layout. The bytecode/C-emit `match`-style `is X` machinery picks up
 *  the type-check predicate. */
function lowerUnionFieldAccess(
  ctx: FnLowerCtx, expr: A.FieldExpr, exprType: Type, res: UnionFieldResolution,
): LoweredExpr {
  const span = expr.span;
  const targetType = ctx.types.exprType(expr.target);
  const fieldName = expr.isNumeric === true ? `_${expr.field}` : expr.field;

  // Same-offset shortcut : when every variant is a Struct that stores
  // the field at the same index AND with the same resolved type, the
  // runtime layouts match — emit a single `(<first-variant>) target` cast
  // followed by a regular field access. The cast is a no-op at the
  // bytecode level (boxed values share the `ref` ValType, no `ref.cast`
  // emitted), and `struct.get` reads the field at its struct-relative
  // offset regardless of the variant tag.
  if (sameOffsetShortcutApplies(res, expr.field)) {
    const first = res.variants[0]!;
    const value = lowerExpr(ctx, expr.target);
    return {
      kind: "LoweredFieldAccess", span, type: first.fieldType,
      target: { kind: "LoweredCast", span, type: first.type, value },
      field: fieldName,
    };
  }

  // General case : per-variant `if is V { (V) e.f } else if is W { ... }`
  // cascade. O(N) bytecode size, used when offsets or field types diverge
  // across variants.
  const scrutSym = freshSyntheticSymbol(ctx, "ufa");
  const scrutValue = lowerExpr(ctx, expr.target);

  let chain: LoweredExpr = {
    kind: "LoweredUnreachable", span, type: exprType,
    reason: "non-exhaustive union field access (T3009 should have caught this)",
  };
  for (let i = res.variants.length - 1; i >= 0; i--) {
    const v = res.variants[i]!;
    const ident: LoweredExpr = { kind: "LoweredIdent", span, type: targetType, symbol: scrutSym };
    const cast: LoweredExpr = { kind: "LoweredCast", span, type: v.type, value: ident };
    const access: LoweredExpr = {
      kind: "LoweredFieldAccess", span, type: v.fieldType, target: cast, field: fieldName,
    };
    const check: LoweredExpr = {
      kind: "LoweredTypeCheck", span, type: TY.bool,
      value: { kind: "LoweredIdent", span, type: targetType, symbol: scrutSym },
      checkType: v.type,
    };
    chain = {
      kind: "LoweredIf", span, type: exprType,
      cond: check,
      then: wrapAsBlock(access, span),
      else: wrapAsBlock(chain, span),
    };
  }

  return {
    kind: "LoweredBlock", span, type: exprType,
    stmts: [{
      kind: "LoweredLet", span, name: scrutSym.name, symbol: scrutSym,
      type: targetType, value: scrutValue,
    }],
    trailing: chain,
  };
}

/** Same-offset shortcut predicate : every variant is a Struct, the field
 *  sits at the same declaration index in each variant's struct decl, and
 *  the resolved field types are identical. Mirrors the runtime memory
 *  layout — declaration order = struct layout order in Vader. */
function sameOffsetShortcutApplies(
  res: UnionFieldResolution, fieldName: string,
): boolean {
  if (res.variants.length === 0) return false;
  let firstIdx = -1;
  let firstFieldType: Type | null = null;
  for (const v of res.variants) {
    if (v.type.kind !== "Struct") return false;
    const decl = sourceStructDecl(v.type.symbol);
    if (decl === null) return false;
    const idx = decl.fields.findIndex((f) => f.name === fieldName);
    if (idx < 0) return false;
    if (firstIdx < 0) {
      firstIdx = idx;
      firstFieldType = v.fieldType;
    } else if (idx !== firstIdx || !equalsType(v.fieldType, firstFieldType!)) {
      return false;
    }
  }
  return true;
}

/** Reorder fields to declaration order (struct.new is positional),
 *  materialise defaults for omitted fields, and bind each `...spread`
 *  source to a synthetic local so it's evaluated exactly once even if
 *  multiple fields inherit from it. T3037 in the typechecker guarantees
 *  every required field has a source ; the LoweredUnreachable fallback
 *  is reached only when prior errors let lowering continue. */
function lowerStructLit(ctx: FnLowerCtx, expr: A.StructLitExpr, exprType: Type): LoweredExpr {
  const decl = exprType.kind === "Struct" ? sourceStructDecl(exprType.symbol) : null;
  if (decl === null) return passthroughStructLit(ctx, expr, exprType);

  const namedItems = new Map<string, A.StructLitField>();
  const spreadItems: A.StructLitSpread[] = [];
  for (const item of expr.items) {
    if (item.kind === "field") namedItems.set(item.name, item);
    else spreadItems.push(item);
  }

  const stmts: LoweredStmt[] = [];
  let spreadSym: Symbol | null = null;
  for (const sp of spreadItems) {
    const value = lowerExpr(ctx, sp.expr);
    spreadSym = freshSyntheticSymbol(ctx, "spread");
    stmts.push({
      kind: "LoweredLet", span: sp.span,
      name: spreadSym.name, symbol: spreadSym, type: exprType, value,
    });
  }

  const loweredFields: LoweredStructLitField[] = decl.fields.map((sf) => {
    const provided = namedItems.get(sf.name);
    if (provided !== undefined) return { name: sf.name, value: lowerExpr(ctx, provided.value) };
    if (spreadSym !== null) {
      const fieldType = ctx.types.typeExprType(sf.type);
      return {
        name: sf.name,
        value: {
          kind: "LoweredFieldAccess", span: expr.span, type: fieldType,
          target: { kind: "LoweredIdent", span: expr.span, type: exprType, symbol: spreadSym },
          field: sf.name,
        },
      };
    }
    if (sf.default !== null) return { name: sf.name, value: lowerExpr(ctx, sf.default) };
    return {
      name: sf.name,
      value: {
        kind: "LoweredUnreachable", span: expr.span, type: ctx.types.typeExprType(sf.type),
        reason: `missing required field \`${sf.name}\``,
      },
    };
  });

  const lit: LoweredExpr = {
    kind: "LoweredStructLit", span: expr.span, type: exprType, fields: loweredFields,
  };
  if (stmts.length === 0) return lit;
  return { kind: "LoweredBlock", span: expr.span, type: exprType, stmts, trailing: lit };
}

/** Fallback for literals whose type didn't resolve to a known struct decl —
 *  emit fields in source order without reordering or default injection.
 *  Spread items are silently dropped (the typechecker already errored). */
function passthroughStructLit(
  ctx: FnLowerCtx, expr: A.StructLitExpr, exprType: Type,
): LoweredExpr {
  return {
    kind: "LoweredStructLit", span: expr.span, type: exprType,
    fields: expr.items.flatMap<LoweredStructLitField>((item) =>
      item.kind === "field"
        ? [{ name: item.name, value: lowerExpr(ctx, item.value) }]
        : []),
  };
}
