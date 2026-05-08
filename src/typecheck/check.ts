// Type-check a ResolvedProgram, producing a TypedProgram populated with the
// inferred / declared types of every expression, type-expression, and binding.
//
// Inference is bidirectional, TS/Swift-style:
//   - bottom-up: compute the natural type of an expression
//   - top-down: when an `expected` type is propagated, check assignability and
//     resolve free numeric literals against it
// No global Hindley-Milner; top-level fn signatures must be fully annotated
// (SPEC §4 "Type inference").
//
// Per-concern logic lives in `./passes/*.ts`; this file is the orchestrator
// + entry points consumed by `./index.ts`.

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { ResolvedProgram } from "../resolver/resolved-ast.ts";

import type * as A from "../parser/ast.ts";

import { DiagnosticCollector } from "../diagnostics/collector.ts";
import { err } from "./diag.ts";
import type { ImplRegistry } from "./impls.ts";
import type { TypedProgram } from "./typed-ast.ts";
import type { Type } from "./types.ts";
import { TY, defaultIfFree, displayType, isAssignable, isPrimitive } from "./types.ts";

import type { Globals, MutableTyped } from "./ctx.ts";
import { checkExpr } from "./passes/expr.ts";
import { checkBlock, checkFnBody } from "./passes/stmt.ts";
import { declareType } from "./passes/decl.ts";

export type { Globals } from "./ctx.ts";
export { newGlobals } from "./ctx.ts";

/** Declare top-level types into the shared globals — must run for every module first.
 *  `phase` controls which decls participate so callers can split the work into
 *  sub-passes (enums first, then everything else) — required because struct
 *  fields and fn signatures may reference enums declared later in source order
 *  (or even in a later module), and they need the populated `indices` map at
 *  lowering time. Enums never reference other user types, so the split is safe. */
export function declareModule(
  program: ResolvedProgram, globals: Globals, diags: DiagnosticCollector,
  phase: "enums" | "rest" | "all" = "all",
): void {
  const t: MutableTyped = {
    resolved: program, globals,
    exprTypes: new Map(), localTypes: new Map(), narrowed: new Map(),
    methodResolutions: new Map(), ufcsFreeResolutions: new Map(), arrayOps: new Map(),
    genericFnCalls: new Map(), traitMethodResolutions: new Map(),
    traitVirtualResolutions: new Map(),
    directCallOverloads: new Map(),
    arrayIterCoercions: new Map(),
  };
  for (const decl of program.source.decls) {
    if (phase === "enums" && decl.kind !== "EnumDecl") continue;
    if (phase === "rest" && decl.kind === "EnumDecl") continue;
    declareType(decl, t, diags);
  }
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
    methodResolutions: new Map(), ufcsFreeResolutions: new Map(), arrayOps: new Map(),
    genericFnCalls: new Map(), traitMethodResolutions: new Map(),
    traitVirtualResolutions: new Map(),
    directCallOverloads: new Map(),
    arrayIterCoercions: new Map(),
  };

  for (const decl of program.source.decls) {
    switch (decl.kind) {
      case "FnDecl":
        if (decl.body !== null) checkFnBody(decl, decl.body, null, t, impls, diags);
        if (decl.name === "main") checkMainSignature(decl, t, diags);
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
        if (expected !== null && !isAssignable(got, expected, impls)) {
          err(diags, "T3001", decl.span,
            `expected ${displayType(expected)}, got ${displayType(got)}`);
        }
        // Record the inferred type for unannotated consts so identifier lookups
        // see a concrete type (e.g. i32 for `BUCKET_COUNT :: 16`) instead of
        // Unresolved — otherwise downstream casts emit ref.cast on numerics.
        if (expected === null) {
          t.globals.declTypes.set(decl, defaultIfFree(got));
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
    methodResolutions: t.methodResolutions,
    ufcsFreeResolutions: t.ufcsFreeResolutions,
    arrayOps: t.arrayOps,
    genericFnCalls: t.genericFnCalls,
    traitMethodResolutions: t.traitMethodResolutions,
    traitVirtualResolutions: t.traitVirtualResolutions,
    directCallOverloads: t.directCallOverloads,
    arrayIterCoercions: t.arrayIterCoercions,
  };
}

/** Resolve return types of expression-bodied fns (`fn(...) = expr`).
 *
 *  Runs between `declareModule` and `checkProgram`. Each iteration tries to
 *  type-check every still-unresolved expression-bodied fn's body ; success
 *  writes the inferred return type into `globals.declTypes` and unblocks any
 *  fn that called this one. The loop stops when an iteration makes no
 *  progress — survivors are diagnosed as `T3034` (recursion needs an
 *  explicit `-> Type`).
 *
 *  Per-iteration body checks run against a *scratch* `DiagnosticCollector`
 *  so we don't pollute the real one with cascade errors from "this caller
 *  saw `Unresolved` because the callee is still pending"; the final
 *  `checkProgram` pass re-runs every body and emits the canonical
 *  diagnostics from a clean slate. */
export function inferExprBodiedReturns(
  programs: ReadonlyMap<string, ResolvedProgram>,
  globals: Globals, impls: ImplRegistry, diags: DiagnosticCollector,
): void {
  const pending: Array<{ program: ResolvedProgram; decl: A.FnDecl }> = [];
  for (const program of programs.values()) {
    for (const decl of program.source.decls) {
      if (decl.kind !== "FnDecl") continue;
      if (decl.isExpressionBodied !== true || decl.body === null) continue;
      pending.push({ program, decl });
    }
  }

  let stuck = pending;
  while (stuck.length > 0) {
    const next: typeof stuck = [];
    for (const item of stuck) {
      const scratch = new DiagnosticCollector();
      const t: MutableTyped = {
        resolved: item.program, globals,
        exprTypes: new Map(), localTypes: new Map(), narrowed: new Map(),
        methodResolutions: new Map(), ufcsFreeResolutions: new Map(), arrayOps: new Map(),
        genericFnCalls: new Map(), traitMethodResolutions: new Map(),
        traitVirtualResolutions: new Map(),
        directCallOverloads: new Map(),
      };
      const inferred = checkBlock(item.decl.body!, null, t, impls, scratch,
        { returnType: TY.unresolved, selfType: null, loopDepth: 0 });
      if (containsUnresolved(inferred)) {
        next.push(item);
        continue;
      }
      const current = globals.declTypes.get(item.decl);
      if (current !== undefined && current.kind === "Fn") {
        globals.declTypes.set(item.decl, {
          kind: "Fn", params: current.params, returnType: defaultIfFree(inferred),
        });
      }
    }
    if (next.length === stuck.length) {
      stuck = next;
      break;
    }
    stuck = next;
  }

  // Whatever's left is part of a recursion cycle — typed-ast would otherwise
  // emit cascading `T3009`/`T3007` once `checkProgram` sees the Unresolved
  // return. Replace with the actionable diagnostic.
  for (const { decl } of stuck) {
    err(diags, "T3034", decl.nameSpan, `\`${decl.name}\``);
  }
}

/** True when `t` is `Unresolved` or any of its sub-types (union variants,
 *  fn params/return, array element, struct/trait args) is. Used by the
 *  expression-bodied inference loop to detect "this fn body still depends
 *  on something we haven't typed yet" without committing a partial type. */
function containsUnresolved(t: Type): boolean {
  switch (t.kind) {
    case "Unresolved": return true;
    case "Union": return t.variants.some(containsUnresolved);
    case "Fn": return t.params.some(containsUnresolved) || containsUnresolved(t.returnType);
    case "Array": return containsUnresolved(t.element);
    case "Struct":
    case "Trait":
      return t.args.some(containsUnresolved);
    default: return false;
  }
}

/** `main` accepts exactly one of two shapes : `fn() -> i32` or
 *  `fn(args: [string]) -> i32`. Anything else is a hard error so emitters
 *  can rely on the signature when wiring the entry point. */
function checkMainSignature(
  decl: A.FnDecl, t: MutableTyped, diags: DiagnosticCollector,
): void {
  const ret = decl.returnType !== null ? t.globals.typeExprTypes.get(decl.returnType) : null;
  if (ret === null || ret === undefined || !isPrimitive(ret, "i32")) {
    err(diags, "T3033", decl.span, "main must return i32");
    return;
  }
  if (decl.params.length === 0) return;
  if (decl.params.length === 1 && decl.params[0]!.type !== null) {
    const paramType = t.globals.typeExprTypes.get(decl.params[0]!.type!);
    if (paramType !== undefined
        && paramType.kind === "Array"
        && isPrimitive(paramType.element, "string")) {
      return;
    }
  }
  err(diags, "T3033", decl.span,
    "main takes either no parameters or a single `[string]` argument");
}
