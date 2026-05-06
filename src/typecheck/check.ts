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

import { err } from "./diag.ts";
import type { ImplRegistry } from "./impls.ts";
import type { TypedProgram } from "./typed-ast.ts";
import { TY, defaultIfFree, displayType, isAssignable, isPrimitive } from "./types.ts";

import type { Globals, MutableTyped } from "./ctx.ts";
import { checkExpr } from "./passes/expr.ts";
import { checkFnBody } from "./passes/stmt.ts";
import { declareType } from "./passes/decl.ts";

export type { Globals } from "./ctx.ts";
export { newGlobals } from "./ctx.ts";

/** Declare top-level types into the shared globals — must run for every module first. */
export function declareModule(
  program: ResolvedProgram, globals: Globals, diags: DiagnosticCollector,
): void {
  const t: MutableTyped = {
    resolved: program, globals,
    exprTypes: new Map(), localTypes: new Map(), narrowed: new Map(),
    methodResolutions: new Map(), ufcsFreeResolutions: new Map(), arrayOps: new Map(),
    genericFnCalls: new Map(), traitMethodResolutions: new Map(),
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
    methodResolutions: new Map(), ufcsFreeResolutions: new Map(), arrayOps: new Map(),
    genericFnCalls: new Map(), traitMethodResolutions: new Map(),
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
        if (expected !== null && !isAssignable(got, expected)) {
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
  };
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
