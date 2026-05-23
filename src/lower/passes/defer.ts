// Defer-thunk lifting. Mirrors `lambda.ts` but operates on `A.DeferStmt`
// instead of `A.LambdaExpr`. The defer body is wrapped in a synthetic
// top-level fn whose first param is an env struct carrying the captured
// locals (heap-promoted cells, same machinery as lambdas). The site of
// the `defer` lowers to a `LoweredDeferPush` whose `thunk` is a
// `LoweredMakeClosure` packing the env + the lifted fn.

import type * as A from "../../parser/ast.ts";
import { UNASSIGNED_NODE_ID } from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { Capture } from "./closures.ts";
import type { FnLowerCtx } from "../ctx.ts";
import type { Substitution, Type } from "../../typecheck/types.ts";
import { TY, mkStruct } from "../../typecheck/types.ts";
import { freshSyntheticSymbol } from "./helpers.ts";
import { lowerBlock } from "./block.ts";
import type {
  LoweredBlock, LoweredDeferPush, LoweredExpr, LoweredFnDecl,
  LoweredParam, LoweredStructDecl, LoweredStructLitField,
} from "../lowered-ast.ts";
import type { MonoEntry } from "../../comptime/specialize.ts";
import type { Span } from "../../diagnostics/diagnostic.ts";

export function lowerDeferStmt(ctx: FnLowerCtx, stmt: A.DeferStmt): LoweredDeferPush {
  const captures = ctx.project.closures.deferCaptures.get(stmt) ?? [];

  const liftedFnSymbol = freshLiftedDeferSymbol(ctx);
  const envStructSymbol = freshLiftedDeferEnvSymbol(ctx);
  const envParamSymbol = freshSyntheticSymbol(ctx, "env");

  const envType: Type = mkStruct(envStructSymbol, []);

  // Capture field names — kept stable so the env's struct lit matches the
  // struct's field declaration order.
  const captureFields = new Map<number, string>();
  captures.forEach((c, i) => captureFields.set(c.symbol.id, `cap_${i}`));

  // 1. Env struct decl. Field types are opaque (cells carry any local kind).
  const envDecl: LoweredStructDecl = {
    kind: "LoweredStructDecl",
    mangled: envStructSymbol.name,
    fields: captures.map((_, i) => ({ name: `cap_${i}`, type: TY.unresolved })),
    origin: synthMonoEntry(ctx, envStructSymbol, "struct"),
  };

  // 2. Lifted fn params : env only. Defer bodies take no source-level params.
  const liftedParams: LoweredParam[] = [
    { name: envParamSymbol.name, symbol: envParamSymbol, type: envType },
  ];

  // 3. Lower the defer body in lifted-context so captured outer-symbol idents
  //    route through env.cap_N. The body is an `A.Stmt` ; wrap in a synthetic
  //    BlockExpr so `lowerBlock` can drive it. Defer body returns void.
  const bodyBlock: A.BlockExpr = stmt.body.kind === "BlockExpr"
    ? stmt.body
    : {
      kind: "BlockExpr",
      id: UNASSIGNED_NODE_ID,
      span: stmt.body.span,
      stmts: [stmt.body],
      trailing: null,
    };

  const liftedFnCtx: FnLowerCtx = {
    project: ctx.project,
    entry: ctx.entry,
    typed: ctx.typed,
    subst: ctx.subst,
    types: ctx.types,
    returnType: TY.void,
    selfType: null,
    blocks: [],
    uniq: 0,
    liftedContext: {
      envSymbol: envParamSymbol,
      envType,
      captureFields,
    },
    comptimeBindings: new Map(),
  };
  const liftedBody: LoweredBlock = lowerBlock(liftedFnCtx, bodyBlock, /*isFnRoot*/ true, /*isLoopBody*/ false);

  const liftedFnDecl: LoweredFnDecl = {
    kind: "LoweredFnDecl",
    mangled: liftedFnSymbol.name,
    params: liftedParams,
    returnType: TY.void,
    body: liftedBody,
    origin: synthMonoEntry(ctx, liftedFnSymbol, "fn"),
  };

  ctx.project.synthDecls.push(envDecl);
  ctx.project.synthDecls.push(liftedFnDecl);

  // 4. Env struct lit — captures the outer cells (LoweredIdent or env-routed
  //    field access, depending on whether we're already inside a lifted fn).
  const envFields: LoweredStructLitField[] = captures.map((c, i) => ({
    name: `cap_${i}`,
    value: outerCellRef(ctx, c, stmt.span),
  }));
  const envExpr: LoweredExpr = {
    kind: "LoweredStructLit", span: stmt.span, type: envType, fields: envFields,
  };

  const thunk: LoweredExpr = {
    kind: "LoweredMakeClosure",
    span: stmt.span,
    // The defer thunk is a void-returning, env-only-arg fn. We don't have
    // a source-level type carrier ; an unresolved Fn type is fine since the
    // emit only consumes `fnSymbol` and `env`.
    type: TY.unresolved,
    fnSymbol: liftedFnSymbol,
    env: envExpr,
  };

  return { kind: "LoweredDeferPush", span: stmt.span, thunk };
}

/** Mirrors `lambda.ts::outerCellRef` — when the outer fn is itself a
 *  lifted lambda / defer, a captured "outer local" is reached via the
 *  outer's own env.cap_X rather than as a bare symbol. */
function outerCellRef(ctx: FnLowerCtx, cap: Capture, span: Span): LoweredExpr {
  const lifted = ctx.liftedContext;
  if (lifted !== null) {
    const fieldName = lifted.captureFields.get(cap.symbol.id);
    if (fieldName !== undefined) {
      const envIdent: LoweredExpr = {
        kind: "LoweredIdent", span, type: lifted.envType, symbol: lifted.envSymbol,
      };
      return {
        kind: "LoweredFieldAccess", span, type: TY.unresolved,
        target: envIdent, field: fieldName,
      };
    }
  }
  return { kind: "LoweredIdent", span, type: cap.type, symbol: cap.symbol };
}

// ---------------------------------------------------------------- symbol helpers

function freshLiftedDeferSymbol(ctx: FnLowerCtx): Symbol {
  const id = ctx.project.nextSyntheticId++;
  return {
    id: -id,
    kind: "fn",
    name: `__defer_${id}`,
    module: ctx.entry.module.module.id,
    visibility: "private",
    definedAt: null,
    source: { kind: "synthetic", origin: "lifted-defer" },
  };
}

function freshLiftedDeferEnvSymbol(ctx: FnLowerCtx): Symbol {
  const id = ctx.project.nextSyntheticId++;
  return {
    id: -id,
    kind: "struct",
    name: `__defer_env_${id}`,
    module: ctx.entry.module.module.id,
    visibility: "private",
    definedAt: null,
    source: { kind: "synthetic", origin: "lifted-defer-env" },
  };
}

let synthDeferEntryId = 3_000_000_000;

function synthMonoEntry(ctx: FnLowerCtx, symbol: Symbol, kind: "fn" | "struct"): MonoEntry {
  const decl: A.FnDecl | A.StructDecl = kind === "fn"
    ? makeStubFnDecl(symbol)
    : makeStubStructDecl(symbol);
  const subst: Substitution = { typeParams: new Map() };
  return {
    id: synthDeferEntryId++,
    isMain: false,
    mangled: symbol.name,
    decl,
    symbol,
    subst,
    typeArgs: [],
    module: ctx.entry.module,
  };
}

function nullSpan(): Span {
  const file = "<synth>";
  return {
    start: { file, offset: 0, line: 1, column: 1 },
    end:   { file, offset: 0, line: 1, column: 1 },
  };
}

function makeStubFnDecl(sym: Symbol): A.FnDecl {
  const span = nullSpan();
  return {
    kind: "FnDecl",
    id: UNASSIGNED_NODE_ID, span,
    name: sym.name,
    nameSpan: span,
    visibility: "private",
    typeParams: [],
    params: [],
    returnType: null,
    body: null,
    decorators: [],
  };
}

function makeStubStructDecl(sym: Symbol): A.StructDecl {
  const span = nullSpan();
  return {
    kind: "StructDecl",
    id: UNASSIGNED_NODE_ID, span,
    name: sym.name,
    nameSpan: span,
    visibility: "private",
    typeParams: [],
    fields: [],
    decorators: [],
  };
}
