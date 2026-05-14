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

import {DiagnosticCollector} from "../diagnostics/collector.ts";
import type {ResolvedProgram} from "../resolver/resolved-ast.ts";

import type * as A from "../parser/ast.ts";
import {err} from "./diag.ts";
import type {ImplRegistry} from "./impls.ts";
import type {TypedProgram} from "./typed-ast.ts";
import type {Type} from "./types.ts";
import {defaultIfFree, displayType, isAssignable, isPrimitive, TY} from "./types.ts";

import type {Globals, MutableTyped} from "./ctx.ts";
import {checkExpr} from "./passes/expr.ts";
import {bindSelfTypes, checkBlock, checkFnBody} from "./passes/stmt.ts";
import {declareType, looksLikeTypeExpression} from "./passes/decl.ts";

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
  phase: "enums" | "type-aliases" | "rest" | "all" = "all",
): void {
  const t: MutableTyped = {
    resolved: program, globals,
    exprTypes: new Map(), localTypes: new Map(), narrowed: new Map(), narrowedFields: new Map(),
    fieldResolutions: new Map(),
    genericFnCalls: new Map(),
    directCallOverloads: new Map(),
    intoCoercions: new Map(),
    binaryOpResolutions: new Map(),
    binaryIsCheckTypes: new Map(),
    indexResolutions: new Map(),
    whileAsForIn: new Map(),
  };
  for (const decl of program.source.decls) {
    if (phase === "enums" && decl.kind !== "EnumDecl") continue;
    if (phase === "type-aliases" && !isTypeAliasingDecl(decl, t)) continue;
    if (phase === "rest" && (decl.kind === "EnumDecl" || isTypeAliasingDecl(decl, t))) continue;
    declareType(decl, t, diags);
  }
}

/** True if `decl` introduces a name that resolves to a type — either an
 *  explicit `T :: type = …` (TypeAliasDecl) or an implicit `T :: A | B`
 *  (ConstDecl whose RHS syntactically looks like a type expression). These
 *  must be declared before consumer modules' fn signatures so cross-module
 *  uses of the alias in fn-param positions (`fn(x: T[])`) see a populated
 *  `constTypeAliases` entry — otherwise `typeFromSymbol` returns Unresolved
 *  and the param shows up as `?[]` instead of the expanded union. */
function isTypeAliasingDecl(decl: A.Decl, t: MutableTyped): boolean {
  if (decl.kind === "TypeAliasDecl") return true;
  if (decl.kind === "ConstDecl") return looksLikeTypeExpression(decl.value, t);
  return false;
}

export function checkProgram(
  program: ResolvedProgram,
  globals: Globals,
  impls: ImplRegistry,
  diags: DiagnosticCollector,
): TypedProgram {
  const t: MutableTyped = {
    resolved: program, globals,
    exprTypes: new Map(), localTypes: new Map(), narrowed: new Map(), narrowedFields: new Map(),
    fieldResolutions: new Map(),
    genericFnCalls: new Map(),
    directCallOverloads: new Map(),
    intoCoercions: new Map(),
    binaryOpResolutions: new Map(),
    binaryIsCheckTypes: new Map(),
    indexResolutions: new Map(),
    whileAsForIn: new Map(),
  };

  for (const decl of program.source.decls) {
    switch (decl.kind) {
      case "FnDecl":
        if (decl.body !== null) checkFnBody(decl, decl.body, null, t, impls, diags);
        if (decl.name === "main") checkMainSignature(decl, t, diags);
        break;
      case "ImplDecl": {
        const selfType = t.globals.typeExprTypes.get(decl.forType) ?? TY.unresolved;
        for (const member of decl.members) {
          if (member.body !== null) {
            checkFnBody(member, member.body, selfType, t, impls, diags);
          } else {
            // Body-less impl member (e.g. `@intrinsic` impl) — still needs the
            // Self → forType substitution applied so downstream phases see
            // the receiver typed as the concrete impl target.
            bindSelfTypes(member, selfType, t);
          }
        }
        break;
      }
      case "TraitDecl":
        // Trait member bodies are sketches; nothing to check yet.
        break;
      case "StructDecl":
        // Defaults are validated here against the *unsubstituted* field type ;
        // type-param defaults (`acc: T = T()`) need the bounded-type-param
        // dispatch infra, so they fall through with Unresolved.
        for (const f of decl.fields) {
          if (f.default === null) continue;
          const fieldTy = t.globals.typeExprTypes.get(f.type) ?? TY.unresolved;
          const got = checkExpr(f.default, fieldTy, t, impls, diags, /*fn*/ null);
          if (fieldTy.kind !== "Unresolved" && !isAssignable(got, fieldTy, impls)) {
            err(diags, "T3001", f.default.span,
              `field default has type ${displayType(got)}, expected ${displayType(fieldTy)}`);
          }
        }
        break;
      case "ConstDecl": {
        // Layer 4-sugar — implicit type alias : `declareType` already
        // pre-resolved the body via `lowerExprAsType` and stashed it in
        // `constTypeAliases`. Skip the value-position typecheck entirely
        // since the body is type-shaped (running `checkExpr` on it would
        // flag e.g. `i32 | null` as "bitor on type / null").
        if (t.globals.constTypeAliases.has(decl)) break;
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
      case "AssertDecl": {
        // The condition is type-checked here (must be `bool`) ; the
        // comptime evaluation that decides whether the assert holds runs
        // in the comptime stage, where C4015 fires on a `false` result.
        const got = checkExpr(decl.condition, TY.bool, t, impls, diags, /*fn*/ null);
        if (!isAssignable(got, TY.bool, impls)) {
          err(diags, "T3001", decl.condition.span,
            `\`@assert\` condition must be \`bool\`, got ${displayType(got)}`);
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
    constTypeAliases: globals.constTypeAliases,
    letTypeAliases: globals.letTypeAliases,
    fieldResolutions: t.fieldResolutions,
    genericFnCalls: t.genericFnCalls,
    directCallOverloads: t.directCallOverloads,
    intoCoercions: t.intoCoercions,
    binaryOpResolutions: t.binaryOpResolutions,
    binaryIsCheckTypes: t.binaryIsCheckTypes,
    indexResolutions: t.indexResolutions,
    whileAsForIn: t.whileAsForIn,
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
      // An explicit `-> T` annotation already pinned the return type in
      // `declareFn` ; the body is regular-checked in `checkProgram` against
      // the annotated type, no inference needed.
      if (decl.returnType !== null) continue;
      pending.push({ program, decl });
    }
  }

  // Convergence is guaranteed in `pending.length` iterations: each iter either
  // resolves a fn (shrinking `stuck`) or makes no progress and exits. The cap
  // is a defensive guard.
  const MAX_ITERS = pending.length + 8;
  let stuck = pending;
  let iter = 0;
  while (stuck.length > 0 && iter < MAX_ITERS) {
    iter++;
    const next: typeof stuck = [];
    for (const item of stuck) {
      const scratch = new DiagnosticCollector();
      const t: MutableTyped = {
        resolved: item.program, globals,
        exprTypes: new Map(), localTypes: new Map(), narrowed: new Map(), narrowedFields: new Map(),
        fieldResolutions: new Map(),
        genericFnCalls: new Map(),
        directCallOverloads: new Map(),
        intoCoercions: new Map(),
        binaryOpResolutions: new Map(),
        binaryIsCheckTypes: new Map(),
        indexResolutions: new Map(),
        whileAsForIn: new Map(),
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
  if (iter >= MAX_ITERS && stuck.length > 0) {
    err(diags, "T3034", stuck[0]!.decl.span,
        `expression-bodied return-type inference did not converge after ${MAX_ITERS} iterations ` +
        `(${stuck.length} fn(s) still unresolved). This is unexpected — please file a bug.`);
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
