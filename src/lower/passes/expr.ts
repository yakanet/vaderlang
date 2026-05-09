// Top-level expression lowerer. Dispatches by AST kind and delegates string
// interp, match, try, range, and for-in to their dedicated passes.

import type * as A from "../../parser/ast.ts";
import { unreachableTypeExprInValuePosition } from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf } from "../../resolver/symbol.ts";
import type { Type } from "../../typecheck/types.ts";
import { CORE_TRAITS, TY, defaultIfFree, displayType, equalsType } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredBlock, LoweredExpr, LoweredIf, LoweredStructLitField } from "../lowered-ast.ts";
import { err } from "../diag.ts";

import { lowerBlock } from "./block.ts";
import { findCoreTrait } from "./core.ts";
import { lookupImplEntry, lookupImplFor, lowerRangeExpr, wrapArrayAsIter } from "./for-in.ts";
import { blockStmtsWithTrailing, freshSyntheticSymbol, loweredEnumVariant, wrapAsBlock } from "./helpers.ts";
import { lowerLambda } from "./lambda.ts";
import { lowerMatch } from "./match.ts";
import { lowerStringLit } from "./string-interp.ts";
import { lowerTry } from "./try.ts";

export function lowerExpr(ctx: FnLowerCtx, expr: A.Expr): LoweredExpr {
  const lowered = lowerExprInner(ctx, expr);
  const coerceElement = ctx.typed.arrayIterCoercions.get(expr);
  if (coerceElement !== undefined) {
    const wrapped = wrapArrayAsIter(ctx, lowered, ctx.types.apply(coerceElement), expr.span);
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
        // as a callable and emit `unreachable`).
        if (calleeSym !== undefined
            && (calleeSym.kind === "builtin-type" || calleeSym.kind === "struct" || calleeSym.kind === "type-alias")
            && expr.args.length === 1) {
          return {
            kind: "LoweredCast", span: expr.span, type: exprType,
            value: lowerExpr(ctx, expr.args[0]!.value),
          };
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
        const exported = ctx.typed.resolved.fields.get(expr.callee);
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
        const arrayOp = ctx.typed.arrayOps.get(expr.callee);
        if (arrayOp === "len") {
          return {
            kind: "LoweredArrayLen", span: expr.span, type: TY.i32,
            target: lowerExpr(ctx, expr.callee.target),
          };
        }
        if (arrayOp === "push") {
          return {
            kind: "LoweredArrayPush", span: expr.span, type: TY.void,
            target: lowerExpr(ctx, expr.callee.target),
            value: lowerExpr(ctx, expr.args[0]!.value),
          };
        }
        const method = ctx.typed.methodResolutions.get(expr.callee);
        if (method !== undefined) {
          const recv = method.receiverType;
          const args = recv.kind === "Struct" ? recv.args : [];
          const entry = lookupImplEntry(ctx, method.member, args);
          if (entry !== null && entry.symbol !== null) {
            return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol);
          }
        }
        // Trait-method dispatch on a generic TypeParam — the typechecker
        // recorded `(trait, method)` ; we apply the call-site substitution
        // to the receiver type-param to get the concrete receiver, then
        // resolve the impl member just like a regular method call.
        const traitMethod = ctx.typed.traitMethodResolutions.get(expr.callee);
        if (traitMethod !== undefined) {
          const concreteRecv = ctx.types.apply(traitMethod.receiverParam);
          const impl = lookupImplFor(ctx.project, concreteRecv, traitMethod.trait);
          if (impl !== null) {
            const member = impl.decl.members.find((m) => m.name === traitMethod.member.name);
            if (member !== undefined) {
              const structArgs = concreteRecv.kind === "Struct" ? concreteRecv.args : [];
              const entry = lookupImplEntry(ctx, member, structArgs);
              if (entry !== null && entry.symbol !== null) {
                return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol);
              }
            }
          }
        }
        // Virtual dispatch on a Trait-typed receiver — chain `is X -> impl_X`
        // checks over every impl of the trait. Lets `err.message()` work when
        // `err: Error` without forcing the user to match on each concrete
        // error type at every call site.
        const virtual = ctx.typed.traitVirtualResolutions.get(expr.callee);
        if (virtual !== undefined) {
          const dispatched = lowerVirtualDispatch(ctx, expr, expr.callee, exprType, virtual.trait, virtual.member.name);
          if (dispatched !== null) return dispatched;
        }
        const freeSym = ctx.typed.ufcsFreeResolutions.get(expr.callee);
        if (freeSym !== undefined) {
          const ufcsTypeArgs = ctx.typed.genericFnCalls.get(expr);
          if (ufcsTypeArgs !== undefined) {
            const fnDecl = declOf(freeSym);
            if (fnDecl !== null && fnDecl.kind === "FnDecl") {
              const entry = lookupFnInstance(ctx, fnDecl, ufcsTypeArgs);
              if (entry !== null) return lowerUfcsCall(ctx, expr, expr.callee, exprType, entry.symbol!);
            }
          }
          return lowerUfcsCall(ctx, expr, expr.callee, exprType, freeSym);
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
      const exported = ctx.typed.resolved.fields.get(expr);
      if (exported !== undefined) {
        return { kind: "LoweredIdent", span: expr.span, type: exprType, symbol: exported };
      }
      // Disambiguate `Enum.Variant` from `b.field_of_enum_type` on the TARGET
      // — both leave `exprType` as the enum.
      const targetType = ctx.types.exprType(expr.target);
      if (targetType.kind === "Enum") return loweredEnumVariant(targetType, expr.field, expr.span);
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
      return {
        kind: "LoweredStructLit", span: expr.span, type: exprType,
        fields: expr.fields.map<LoweredStructLitField>((f) => ({
          name: f.name, value: lowerExpr(ctx, f.value),
        })),
      };
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
    case "UnionType":
    case "FnTypeExpr":
    case "ArrayTypeExpr":
    case "TupleTypeExpr":
    case "GenericInstType":
    case "TypeParamType":
      return unreachableTypeExprInValuePosition(expr);
  }
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
    const checkType = ctx.types.exprType(expr.right);
    return {
      kind: "LoweredTypeCheck", span: expr.span, type: TY.bool,
      value: lowerExpr(ctx, expr.left), checkType,
    };
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
 *  the typechecker. Eq/neq wrap with `bool.not` ; ord wraps with a primitive
 *  comparison against zero against `compare`'s i32 result. */
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

import type { MonoEntry } from "../../monomorphize/mono-ast.ts";
import type {BinaryOpResolution, IndexResolution} from "../../typecheck/typed-ast.ts";

function lookupFnInstance(ctx: FnLowerCtx, fnDecl: A.FnDecl, typeArgs: readonly Type[]): MonoEntry | null {
  const key = typeArgs.map((ta) => displayType(ctx.types.apply(ta))).join(",");
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
