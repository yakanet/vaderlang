// Lambda lifting (Phase 3.3) — turns each LambdaExpr into:
//   1. A synthesized top-level fn (the "lifted fn") whose first param is the
//      env struct holding the captured cell references.
//   2. A synthesized struct decl describing that env.
//   3. A `LoweredMakeClosure` expression at the original call site that
//      packs the captured cells into a fresh env and bundles it with the
//      lifted fn into a closure value.
//
// The lifted fn's body is lowered with `liftedContext` set so that any
// reference to a captured outer symbol routes through `env.cap_X` instead
// of resolving to a (non-existent) local.

import type * as A from "../../parser/ast.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { Capture } from "./closures.ts";
import type { FnLowerCtx } from "../ctx.ts";
import type { Substitution, Type } from "../../typecheck/types.ts";
import { TY } from "../../typecheck/types.ts";
import { freshSyntheticSymbol } from "./helpers.ts";
import { lowerBlock } from "./block.ts";
import type {
  LoweredExpr, LoweredFnDecl, LoweredParam, LoweredStructDecl,
} from "../lowered-ast.ts";
import type {MonoEntry} from "../../comptime/specialize.ts";

export function lowerLambda(ctx: FnLowerCtx, lambda: A.LambdaExpr): LoweredExpr {
  const captures = ctx.project.closures.lambdaCaptures.get(lambda) ?? [];

  // Mint symbols for the synthesised lifted fn, its env struct, and the env
  // param. These symbols don't go through the resolver — they're internal
  // identifiers used only by the lower → bytecode emit handoff.
  const liftedFnSymbol = freshLiftedFnSymbol(ctx);
  const envStructSymbol = freshLiftedEnvSymbol(ctx);
  const envParamSymbol = freshSyntheticSymbol(ctx, "env");

  // Env type — a pseudo Struct type pointing at the synthesised symbol. The
  // bytecode emit will intern a BcStruct entry for this via `internStructDecl`
  // when it processes the synthesised LoweredStructDecl.
  const envType: Type = { kind: "Struct", symbol: envStructSymbol, args: [] };

  // Capture field names — kept stable so the env's struct lit matches the
  // struct's field declaration order.
  const captureFields = new Map<number, string>();
  captures.forEach((c, i) => captureFields.set(c.symbol.id, `cap_${i}`));

  // 1. Build the LoweredStructDecl for the env.
  const envDecl: LoweredStructDecl = {
    kind: "LoweredStructDecl",
    mangled: envStructSymbol.name,
    fields: captures.map((c, i) => ({
      name: `cap_${i}`,
      // The slot's type is opaque — every captured local has been heap-promoted
      // into a cell; we store the cell ref. Modelling as Unresolved makes the
      // bytecode emit fall back to "ref" / vader_box_t.
      type: TY.unresolved,
    })),
    origin: synthMonoEntry(ctx, envStructSymbol, /*kind*/ "struct"),
  };

  // 2. Build the lifted fn's params: env first, then the original lambda
  //    params. Each lambda param's symbol comes from the resolver.
  const liftedParams: LoweredParam[] = [
    { name: envParamSymbol.name, symbol: envParamSymbol, type: envType },
  ];
  const lambdaParamSyms: Symbol[] = [];
  for (const p of lambda.params) {
    const sym = ctx.typed.resolved.params.get(p);
    if (sym === undefined) continue;
    const t = ctx.types.paramType(p);
    liftedParams.push({ name: p.name, symbol: sym, type: t });
    lambdaParamSyms.push(sym);
  }

  // 3. Lower the lambda body in lifted-context. Captured outer-symbol idents
  //    will route through env.cap_X via the lifted-context lookup.
  const lambdaReturnType = ctx.typed.exprTypes.get(lambda.body)
    ?? ctx.typed.exprTypes.get(lambda)
    ?? TY.void;
  const liftedReturnType = (() => {
    const fnT = ctx.typed.exprTypes.get(lambda);
    if (fnT?.kind === "Fn") return ctx.types.apply(fnT.returnType);
    return ctx.types.apply(lambdaReturnType);
  })();
  const liftedFnCtx: FnLowerCtx = {
    project: ctx.project,
    entry: ctx.entry,             // borrow outer entry for module identity
    typed: ctx.typed,
    subst: ctx.subst,
    types: ctx.types,
    returnType: liftedReturnType,
    selfType: null,
    blocks: [],
    uniq: 0,
    liftedContext: {
      envSymbol: envParamSymbol,
      envType,
      captureFields,
    },
  };
  const liftedBody = lowerBlock(liftedFnCtx, lambda.body, /*isFnRoot*/ true, /*isLoopBody*/ false);

  const liftedFnDecl: LoweredFnDecl = {
    kind: "LoweredFnDecl",
    mangled: liftedFnSymbol.name,
    params: liftedParams,
    returnType: liftedReturnType,
    body: liftedBody,
    origin: synthMonoEntry(ctx, liftedFnSymbol, /*kind*/ "fn"),
  };

  ctx.project.synthDecls.push(envDecl);
  ctx.project.synthDecls.push(liftedFnDecl);

  // 4. Build the env struct literal — fields are the captured cell references
  //    from the OUTER scope (i.e. plain `LoweredIdent`s, NOT wrapped in
  //    CellGet — we want the cell itself, not its contents).
  const envFields = captures.map((c, i) => ({
    name: `cap_${i}`,
    value: outerCellRef(ctx, c, lambda.span),
  }));
  const envExpr: LoweredExpr = {
    kind: "LoweredStructLit", span: lambda.span, type: envType, fields: envFields,
  };

  const closureType = ctx.typed.exprTypes.get(lambda) ?? TY.unresolved;
  return {
    kind: "LoweredMakeClosure", span: lambda.span,
    type: ctx.types.apply(closureType),
    fnSymbol: liftedFnSymbol,
    env: envExpr,
  };
}

/** Build a `LoweredIdent` referring to the cell of an outer captured local —
 *  but if we're inside a lifted fn ourselves, the outer "local" is actually
 *  also reached via OUR env, so we must read env.cap_X (which yields the
 *  cell ref) rather than reference the bare symbol. */
function outerCellRef(ctx: FnLowerCtx, cap: Capture, span: A.LambdaExpr["span"]): LoweredExpr {
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

function freshLiftedFnSymbol(ctx: FnLowerCtx): Symbol {
  const id = ctx.project.nextSyntheticId++;
  return {
    id: -id,
    kind: "fn",
    name: `__lambda_${id}`,
    module: ctx.entry.module.module.id,
    visibility: "private",
    definedAt: null,
    source: { kind: "synthetic", origin: "lifted-lambda" },
  };
}

function freshLiftedEnvSymbol(ctx: FnLowerCtx): Symbol {
  const id = ctx.project.nextSyntheticId++;
  return {
    id: -id,
    kind: "struct",
    name: `__lambda_env_${id}`,
    module: ctx.entry.module.module.id,
    visibility: "private",
    definedAt: null,
    source: { kind: "synthetic", origin: "lifted-lambda-env" },
  };
}

let synthLambdaEntryId = 2_000_000_000;

function synthMonoEntry(
  ctx: FnLowerCtx, symbol: Symbol, kind: "fn" | "struct",
): MonoEntry {
  // Synth entries borrow the outer entry's module for identity but supply a
  // stub AST decl with no decorators so the bytecode emit's reserve passes
  // skip the @extern / @export branches cleanly.
  const decl: A.FnDecl | A.StructDecl = kind === "fn"
    ? makeStubFnDecl(symbol)
    : makeStubStructDecl(symbol);
  const subst: Substitution = { typeParams: new Map() };
  return {
    id: synthLambdaEntryId++,
    isMain: false,
    mangled: symbol.name,
    decl,
    symbol,
    subst,
    typeArgs: [],
    module: ctx.entry.module,
  };
}

function nullSpan(): A.LambdaExpr["span"] {
  // Synthesised AST nodes have no source span — we route to a 0/0 placeholder
  // file. Diagnostics from these nodes shouldn't fire (they're never the
  // subject of a user error), but supplying real Span shape keeps callers
  // that read .span happy.
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
    span,
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
    span,
    name: sym.name,
    nameSpan: span,
    visibility: "private",
    typeParams: [],
    fields: [],
    decorators: [],
  };
}
