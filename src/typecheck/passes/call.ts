// CallExpr dispatcher. Three call-forms collapse here :
//   1. `Type(value)` constructor / cast — routed to `./cast.ts`.
//   2. `f(args)` plain fn call (with optional overload pick) — handled here.
//   3. `obj.method(args)` UFCS — the FieldExpr callee is type-checked via
//      `inferField` (`./field.ts`); generic UFCS uses `inferGenericUfcsCall`
//      from the same module to bind the receiver into the typeParam map.
//
// The field-shaped resolution Maps (`fieldResolutions`) and overload helpers
// (`rankOverloadsByFirstParam`, `fnOverloadsForSymbol`) live with their
// primary consumers in `./field.ts`. The pure unification logic
// (`unifyTypeParam`, `typeContainsTypeParam`, `mergeSubst`) lives in
// `./unify.ts`.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { declOf } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { ImplRegistry } from "../impls.ts";
import type { Substitution, Type } from "../types.ts";
import { TY, defaultIfFree, displayType, isAssignable, substitute } from "../types.ts";

import { tryInto } from "./coerce.ts";
import type { FnContext, MutableTyped } from "../ctx.ts";
import { checkExpr } from "./expr.ts";
import { inferTypeConstructorCall } from "./cast.ts";
import { primitiveFromName } from "./type-expr.ts";
import {
  fnOverloadsForSymbol,
  inferGenericUfcsCall,
  pinFreeNumericArg,
  rankOverloadsByFirstParam,
  recordGenericCallSite,
} from "./field.ts";
import { typeContainsTypeParam, unifyTypeParam } from "./unify.ts";

export function inferCall(
  expr: A.CallExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Cast form: `Type(value)` — the callee is an ident resolving to a type symbol.
  if (expr.callee.kind === "IdentExpr") {
    const sym = t.resolved.idents.get(expr.callee);
    if (sym !== undefined && (sym.kind === "builtin-type" || sym.kind === "struct" || sym.kind === "type-alias")) {
      return inferTypeConstructorCall(expr, t, impls, diags, fn);
    }
    // Direct-call overload resolution: a fn name that resolves to multiple
    // sibling overloads needs the right candidate picked by the first arg's
    // type before we infer the callee's fn type. Matches the UFCS dispatch
    // policy (concrete > symbol-match > wildcard).
    if (sym !== undefined && sym.kind === "fn") {
      const overloads = fnOverloadsForSymbol(sym, t);
      if (overloads.length > 1 && expr.args.length > 0) {
        // Default free numeric literals to their canonical type (i32 / f64)
        // before ranking — otherwise `abs(-7)` matches both `abs(i32)` and
        // `abs(f64)` and silently picks the first declared overload.
        const firstArgTy = defaultIfFree(checkExpr(expr.args[0]!.value, null, t, impls, diags, fn));
        const chosen = pickDirectCallOverload(overloads, firstArgTy, t, impls);
        if (chosen !== null && chosen !== sym) {
          t.directCallOverloads.set(expr, chosen);
        } else if (chosen === null) {
          err(diags, "T3032", expr.callee.span,
            `no overload of \`${sym.name}\` matches receiver ${displayType(firstArgTy)}`);
        }
      }
    }
  }

  const calleeType = chooseCalleeType(expr, t, impls, diags, fn);

  if (calleeType.kind !== "Fn") {
    if (calleeType.kind !== "Unresolved") err(diags, "T3007", expr.callee.span, displayType(calleeType));
    for (const a of expr.args) checkExpr(a.value, null, t, impls, diags, fn);
    return TY.unresolved;
  }

  // Generic UFCS free fn call: callee is `receiver.fn(args)` where `fn` is a
  // generic free function. The bound calleeType has the receiver param dropped,
  // so we must use the full fn type (with receiver as params[0]) to infer T.
  if (expr.callee.kind === "FieldExpr") {
    const fr = t.fieldResolutions.get(expr.callee);
    const freeSym = fr?.kind === "ufcs-free" ? fr.symbol : undefined;
    if (freeSym !== undefined) {
      const ufcsDecl = declOf(freeSym);
      const fullFnType = ufcsDecl !== null ? t.globals.declTypes.get(ufcsDecl) : undefined;
      if (fullFnType !== undefined && fullFnType.kind === "Fn" && fullFnType.params.some(typeContainsTypeParam)) {
        return inferGenericUfcsCall(expr, expr.callee, fullFnType, freeSym, t, impls, diags, fn);
      }
    }
  }

  // Generic fn call: at least one param type contains a TypeParam.
  // Infer the substitution from argument types, then re-check under it.
  if (calleeType.params.some(typeContainsTypeParam)) {
    return inferGenericFnCall(expr, calleeType, t, impls, diags, fn);
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
    if (expectedTy !== null && !isAssignable(got, expectedTy, impls)) {
      if (!tryInto(got, expectedTy, arg.value, t, impls)) {
        err(diags, "T3001", arg.value.span,
          `expected ${displayType(expectedTy)}, got ${displayType(got)}`);
      }
    }
  }
  // `arr.push(x)` against an array whose element type wasn't pinned by an
  // annotation or earlier elements: lift the local's type from `[?]` to
  // `[typeof x]` so subsequent reads (`arr[i]`, `${arr[i]}`, …) see a
  // concrete element type instead of falling back to a boxed `any`.
  refineArrayLocalFromPush(expr, t);
  return calleeType.returnType;
}

function refineArrayLocalFromPush(expr: A.CallExpr, t: MutableTyped): void {
  if (expr.callee.kind !== "FieldExpr") return;
  const fr = t.fieldResolutions.get(expr.callee);
  if (fr?.kind !== "array-op" || fr.op !== "push") return;
  if (expr.args.length === 0) return;
  const target = expr.callee.target;
  if (target.kind !== "IdentExpr") return;
  const sym = t.resolved.idents.get(target);
  if (sym === undefined || sym.source.kind !== "local") return;
  const binding = sym.source.binding;
  const current = t.localTypes.get(binding);
  if (current?.kind !== "Array" || current.element.kind !== "Unresolved") return;
  const inferred = pushArgConcreteType(expr.args[0]!.value, t);
  if (inferred === null) return;
  // Safe to mutate mid-fn-check: every `IdentExpr` typecheck re-reads
  // `localTypes` (no per-fn cache), so later reads see the refined element.
  t.localTypes.set(binding, { kind: "Array", element: inferred });
}

/** Best-effort element-type inference for `arr.push(x)` against an `arr` whose
 *  static type hasn't been pinned yet. The arg's `exprTypes` entry may have
 *  already been defaulted to `Unresolved` (FreeInt + Unresolved expected →
 *  Unresolved by `checkExpr`); for literal shapes, derive the concrete type
 *  from the AST so the common `arr.push(1)` lands on `i32` rather than
 *  disappearing into a boxed slot. */
function pushArgConcreteType(arg: A.Expr, t: MutableTyped): Type | null {
  switch (arg.kind) {
    case "IntLitExpr":
      return arg.suffix !== null ? primitiveFromName(arg.suffix) ?? TY.unresolved : TY.i32;
    case "FloatLitExpr":
      return arg.suffix !== null ? primitiveFromName(arg.suffix) ?? TY.unresolved : TY.f64;
    case "BoolLitExpr":   return TY.bool;
    case "NullLitExpr":   return TY.null;
    case "CharLitExpr":   return TY.char;
    case "StringLitExpr": return TY.string;
    default: {
      const argTy = t.exprTypes.get(arg);
      if (argTy === undefined) return null;
      const def = defaultIfFree(argTy);
      return def.kind === "Unresolved" ? null : def;
    }
  }
}

function inferGenericFnCall(
  expr: A.CallExpr,
  calleeType: Extract<Type, { kind: "Fn" }>,
  t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  // Step 1: collect arg types without type-param expected context.
  const argTypes: Type[] = expr.args.map((a) => checkExpr(a.value, null, t, impls, diags, fn));

  // Step 2: unify param types with (defaulted) arg types to build the substitution.
  const bindings = new Map<number, Type>();
  for (let i = 0; i < calleeType.params.length && i < argTypes.length; i++) {
    unifyTypeParam(calleeType.params[i]!, defaultIfFree(argTypes[i]!), bindings, impls, t);
  }
  const subst: Substitution = { typeParams: bindings };

  // Step 3: arity check.
  if (expr.args.length !== calleeType.params.length) {
    err(diags, "T3003", expr.span,
      `expected ${calleeType.params.length}, got ${expr.args.length}`);
  }

  // Step 4: assignability check against the substituted param types.
  for (let i = 0; i < calleeType.params.length && i < argTypes.length; i++) {
    const expectedTy = substitute(calleeType.params[i]!, subst);
    if (!typeContainsTypeParam(expectedTy) && !isAssignable(argTypes[i]!, expectedTy, impls)) {
      if (!tryInto(argTypes[i]!, expectedTy, expr.args[i]!.value, t, impls)) {
        err(diags, "T3001", expr.args[i]!.value.span,
          `expected ${displayType(expectedTy)}, got ${displayType(argTypes[i]!)}`);
      }
    }
    if (!typeContainsTypeParam(expectedTy)) {
      pinFreeNumericArg(argTypes[i]!, expectedTy, expr.args[i]!.value, t, impls);
    }
  }

  if (expr.callee.kind === "IdentExpr") {
    const sym = t.resolved.idents.get(expr.callee);
    if (sym !== undefined) recordGenericCallSite(expr, declOf(sym), bindings, t, impls, diags);
  }

  return substitute(calleeType.returnType, subst);
}

/** Pick the best overload for a direct `f(arg, …)` call by matching the
 *  first argument's type. Mirrors UFCS dispatch policy. Returns null when no
 *  candidate matches. */
function pickDirectCallOverload(
  overloads: readonly Symbol[], firstArgTy: Type, t: MutableTyped,
  impls?: ImplRegistry,
): Symbol | null {
  const ranked = rankOverloadsByFirstParam(overloads, firstArgTy, t, impls);
  return ranked.concrete ?? ranked.symMatch ?? ranked.wildcard ?? ranked.intoMatch;
}

/** Build the fn-typed `calleeType` for an inferCall, honoring the chosen
 *  overload when overload resolution picked a non-primary symbol. Falls back to
 *  the resolver's primary by running `checkExpr(expr.callee, …)` as before. */
function chooseCalleeType(
  expr: A.CallExpr, t: MutableTyped, impls: ImplRegistry,
  diags: DiagnosticCollector, fn: FnContext | null,
): Type {
  const chosen = t.directCallOverloads.get(expr);
  if (chosen !== undefined) {
    const decl = declOf(chosen);
    const fnType = decl !== null ? t.globals.declTypes.get(decl) : undefined;
    if (fnType !== undefined && fnType.kind === "Fn") {
      // Record the chosen fn type on the callee so downstream consumers
      // (lower's emit-by-type heuristics, dump tooling) see the picked overload.
      t.exprTypes.set(expr.callee, fnType);
      return fnType;
    }
  }
  return checkExpr(expr.callee, null, t, impls, diags, fn);
}

// Re-export inferField so `passes/expr.ts` (and other historical consumers)
// keep their `from "./call.ts"` import working unchanged.
export { inferField } from "./field.ts";
