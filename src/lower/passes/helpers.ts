// Small AST construction helpers used by multiple passes — substitution,
// synthetic symbol minting, block wrapping, and OR-chain assembly.

import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Symbol } from "../../resolver/symbol.ts";
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

/** Flatten a block's trailing expression into its stmts list. Useful when a
 *  block needs to be re-typed to `void` (no-else `if`, for-in body) and any
 *  trailing value should be evaluated then discarded. */
export function blockStmtsWithTrailing(block: LoweredBlock): readonly LoweredStmt[] {
  if (block.trailing === null) return block.stmts;
  return [...block.stmts, { kind: "LoweredExprStmt", span: block.trailing.span, expr: block.trailing }];
}

/** `.Variant` / `Enum.Variant` / arm pattern → integer literal of the variant's
 *  resolved index, typed as the enum's backing repr. The type-checker has
 *  already validated `name` against `enumType` (T3027) and populated `indices`
 *  in `declareEnum`, so a missing variant here is a compiler invariant
 *  violation. */
export function loweredEnumVariant(enumType: Type, name: string, span: Span): LoweredExpr {
  if (enumType.kind !== "Enum") {
    throw new Error(`loweredEnumVariant: expected Enum type, got ${enumType.kind}`);
  }
  const value = enumType.indices.get(name);
  if (value === undefined) {
    throw new Error(`loweredEnumVariant: variant ${name} not found on ${enumType.symbol.name} (indices not populated — declareEnum did not run?)`);
  }
  return {
    kind: "LoweredIntLit", span,
    type: { kind: "Primitive", name: enumType.repr },
    value,
  };
}

export function orAll(span: Span, parts: readonly LoweredExpr[]): LoweredExpr {
  if (parts.length === 0) return { kind: "LoweredBoolLit", span, type: TY.bool, value: false };
  let acc = parts[0]!;
  for (let i = 1; i < parts.length; i++) {
    acc = { kind: "LoweredBinary", span, type: TY.bool, op: "or", left: acc, right: parts[i]! };
  }
  return acc;
}
