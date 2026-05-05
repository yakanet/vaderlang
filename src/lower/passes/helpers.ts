// Small AST construction helpers used by multiple passes — substitution,
// synthetic symbol minting, block wrapping, and OR-chain assembly.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import { enumVariantIndex } from "../../resolver/symbol.ts";
import type { Substitution, Type } from "../../typecheck/types.ts";
import { TY, substitute } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredBlock, LoweredExpr, LoweredStmt } from "../lowered-ast.ts";

export function applySubst(t: Type, subst: Substitution): Type {
  // Skip the recursive Type walk when the subst is empty — common for non-generic decls.
  if ((subst.typeParams === undefined || subst.typeParams.size === 0) && subst.self === undefined) {
    return t;
  }
  return substitute(t, subst);
}

export function freshSyntheticSymbol(ctx: FnLowerCtx, hint: string): Symbol {
  const n = ctx.uniq++;
  const name = `__${hint}_${n}`;
  return {
    id: -ctx.project.nextSyntheticId++,
    kind: "synthetic",
    name,
    module: ctx.entry.module.module.id,
    visibility: "private",
    definedAt: null,
    source: { kind: "synthetic", origin: hint },
  };
}

/** Pack a sequence of statements into a single statement, transparent to control flow. */
export function wrapStmts(span: Span, stmts: readonly LoweredStmt[]): LoweredStmt {
  if (stmts.length === 1) return stmts[0]!;
  return {
    kind: "LoweredExprStmt", span,
    expr: { kind: "LoweredBlock", span, type: TY.void, stmts, trailing: null },
  };
}

export function wrapAsBlock(e: LoweredExpr, span: Span): LoweredBlock {
  return { kind: "LoweredBlock", span, type: e.type, stmts: [], trailing: e };
}

/** `.Variant` / `Enum.Variant` / arm pattern → `i32` literal of the variant's index.
 *  The type-checker has already validated `name` against `enumType` (T3027) — we
 *  treat a missing variant as a compiler invariant violation rather than silently
 *  emitting `0`, which would mask bugs as a successful match on the first variant. */
export function loweredEnumVariant(enumType: Type, name: string, span: Span): LoweredExpr {
  if (enumType.kind !== "Enum") {
    throw new Error(`loweredEnumVariant: expected Enum type, got ${enumType.kind}`);
  }
  const index = enumVariantIndex(enumType.symbol, name);
  if (index < 0) {
    throw new Error(`loweredEnumVariant: variant ${name} not found on ${enumType.symbol.name}`);
  }
  return { kind: "LoweredIntLit", span, type: TY.i32, value: BigInt(index) };
}

export function orAll(span: Span, parts: readonly LoweredExpr[]): LoweredExpr {
  if (parts.length === 0) return { kind: "LoweredBoolLit", span, type: TY.bool, value: false };
  let acc = parts[0]!;
  for (let i = 1; i < parts.length; i++) {
    acc = { kind: "LoweredBinary", span, type: TY.bool, op: "or", left: acc, right: parts[i]! };
  }
  return acc;
}
