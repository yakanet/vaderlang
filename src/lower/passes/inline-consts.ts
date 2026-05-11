// Lowered → Lowered pass: substitute every `LoweredIdent` referring to a
// const symbol with the const's value. Replaces the on-the-fly inlining
// that used to live in `midir/build.ts` (and the dead `EmitterCtx.constDecls`
// table in `bytecode/emit.ts`).
//
// Const values themselves may reference other consts; we resolve those
// first with a topological-substitution fixpoint so the substitution map
// holds fully-inlined values. Cycles are caught at evaluation time, so
// here we assume the graph is acyclic.

import type {
  LoweredBlock, LoweredConstDecl, LoweredDecl, LoweredExpr, LoweredFnDecl,
  LoweredModule, LoweredProject, LoweredStmt, LoweredStructLitField,
} from "../lowered-ast.ts";

export function inlineConsts(p: LoweredProject): LoweredProject {
  const constValueBySymId = collectInlinedConsts(p);
  if (constValueBySymId.size === 0) return p;

  const modules = new Map<string, LoweredModule>();
  for (const [id, m] of p.modules) {
    const decls: LoweredDecl[] = m.decls.map((d) => {
      switch (d.kind) {
        case "LoweredFnDecl":   return rewriteFn(d, constValueBySymId);
        case "LoweredConstDecl": return rewriteConst(d, constValueBySymId);
        case "LoweredStructDecl": return d;
      }
    });
    modules.set(id, { moduleId: m.moduleId, displayPath: m.displayPath, decls });
  }
  return { modules, vtableEntries: p.vtableEntries };
}

/** Build the substitution map: for every const symbol, the fully-inlined
 *  value (with nested const refs resolved). */
function collectInlinedConsts(p: LoweredProject): Map<number, LoweredExpr> {
  const raw = new Map<number, LoweredExpr>();
  for (const m of p.modules.values()) {
    for (const d of m.decls) {
      if (d.kind !== "LoweredConstDecl") continue;
      if (d.origin.symbol === null) continue;
      raw.set(d.origin.symbol.id, d.value);
    }
  }

  const resolved = new Map<number, LoweredExpr>();
  const inFlight = new Set<number>();
  // Lookup returns null for non-const symbol ids (locals, params, fns…),
  // so `rewriteExpr` leaves their `LoweredIdent` nodes untouched.
  const lookup = (symId: number): LoweredExpr | null => {
    if (!raw.has(symId)) return null;
    return resolveOne(symId);
  };
  function resolveOne(symId: number): LoweredExpr {
    const cached = resolved.get(symId);
    if (cached !== undefined) return cached;
    const raw0 = raw.get(symId)!;
    if (inFlight.has(symId)) {
      // Cycle (rejected at eval time, defensive here): leave the original.
      return raw0;
    }
    inFlight.add(symId);
    const inlined = rewriteExpr(raw0, lookup, raw);
    inFlight.delete(symId);
    resolved.set(symId, inlined);
    return inlined;
  }
  for (const symId of raw.keys()) resolveOne(symId);
  return resolved;
}

function rewriteFn(
  d: LoweredFnDecl, consts: ReadonlyMap<number, LoweredExpr>,
): LoweredFnDecl {
  if (d.body === null) return d;
  return { ...d, body: rewriteBlock(d.body, (id) => consts.get(id) ?? null, consts) };
}

function rewriteConst(
  d: LoweredConstDecl, consts: ReadonlyMap<number, LoweredExpr>,
): LoweredConstDecl {
  // After the substitution map is fully resolved, every const decl's value
  // should be its inlined form. If the resolution map has an entry for this
  // const's symbol, prefer it ; otherwise fall back to walking the raw
  // value (e.g. for synthetic consts not present in the map).
  if (d.origin.symbol === null) return d;
  const inlined = consts.get(d.origin.symbol.id);
  if (inlined !== undefined) return { ...d, value: inlined };
  return { ...d, value: rewriteExpr(d.value, (id) => consts.get(id) ?? null, consts) };
}

/** Recursive expression rewriter. `lookup` returns the inlined value for a
 *  const symbol id, or null for non-const idents. `consts` is the full map
 *  reused by `rewriteBlock` / `rewriteStmt`. */
function rewriteExpr(
  e: LoweredExpr,
  lookup: (symId: number) => LoweredExpr | null,
  consts: ReadonlyMap<number, LoweredExpr>,
): LoweredExpr {
  switch (e.kind) {
    case "LoweredIdent": {
      const subst = lookup(e.symbol.id);
      return subst ?? e;
    }
    case "LoweredCall":
      return {
        ...e,
        callee: rewriteExpr(e.callee, lookup, consts),
        args: e.args.map((a) => rewriteExpr(a, lookup, consts)),
      };
    case "LoweredVirtualCall":
      return {
        ...e,
        receiver: rewriteExpr(e.receiver, lookup, consts),
        args: e.args.map((a) => rewriteExpr(a, lookup, consts)),
      };
    case "LoweredFieldAccess":
      return { ...e, target: rewriteExpr(e.target, lookup, consts) };
    case "LoweredIndex":
      return {
        ...e,
        target: rewriteExpr(e.target, lookup, consts),
        index: rewriteExpr(e.index, lookup, consts),
      };
    case "LoweredUnary":
      return { ...e, operand: rewriteExpr(e.operand, lookup, consts) };
    case "LoweredBinary":
      return {
        ...e,
        left: rewriteExpr(e.left, lookup, consts),
        right: rewriteExpr(e.right, lookup, consts),
      };
    case "LoweredIf":
      return {
        ...e,
        cond: rewriteExpr(e.cond, lookup, consts),
        then: rewriteBlock(e.then, lookup, consts),
        else: e.else === null ? null : rewriteBlock(e.else, lookup, consts),
      };
    case "LoweredBlock":
      return rewriteBlock(e, lookup, consts);
    case "LoweredStructLit":
      return {
        ...e,
        fields: e.fields.map((f): LoweredStructLitField => ({
          name: f.name,
          value: rewriteExpr(f.value, lookup, consts),
        })),
      };
    case "LoweredArrayLit":
      return { ...e, elements: e.elements.map((el) => rewriteExpr(el, lookup, consts)) };
    case "LoweredArrayLen":
      return { ...e, target: rewriteExpr(e.target, lookup, consts) };
    case "LoweredArrayPush":
      return {
        ...e,
        target: rewriteExpr(e.target, lookup, consts),
        value: rewriteExpr(e.value, lookup, consts),
      };
    case "LoweredCast":
      return { ...e, value: rewriteExpr(e.value, lookup, consts) };
    case "LoweredTypeCheck":
      return { ...e, value: rewriteExpr(e.value, lookup, consts) };
    case "LoweredIntrinsicCall":
      return { ...e, args: e.args.map((a) => rewriteExpr(a, lookup, consts)) };
    case "LoweredCellNew":
      return { ...e, value: rewriteExpr(e.value, lookup, consts) };
    case "LoweredCellGet":
      return { ...e, target: rewriteExpr(e.target, lookup, consts) };
    case "LoweredMakeClosure":
      return { ...e, env: rewriteExpr(e.env, lookup, consts) };
    case "LoweredIntLit":
    case "LoweredFloatLit":
    case "LoweredBoolLit":
    case "LoweredNullLit":
    case "LoweredCharLit":
    case "LoweredStringLit":
    case "LoweredUnreachable":
      return e;
    default: {
      const _exhaustive: never = e;
      void _exhaustive;
      return e;
    }
  }
}

function rewriteBlock(
  b: LoweredBlock,
  lookup: (symId: number) => LoweredExpr | null,
  consts: ReadonlyMap<number, LoweredExpr>,
): LoweredBlock {
  return {
    ...b,
    stmts: b.stmts.map((s) => rewriteStmt(s, lookup, consts)),
    trailing: b.trailing === null ? null : rewriteExpr(b.trailing, lookup, consts),
  };
}

function rewriteStmt(
  s: LoweredStmt,
  lookup: (symId: number) => LoweredExpr | null,
  consts: ReadonlyMap<number, LoweredExpr>,
): LoweredStmt {
  switch (s.kind) {
    case "LoweredLet":
      return { ...s, value: rewriteExpr(s.value, lookup, consts) };
    case "LoweredAssign":
      return {
        ...s,
        target: rewriteExpr(s.target, lookup, consts),
        value: rewriteExpr(s.value, lookup, consts),
      };
    case "LoweredCellSet":
      return {
        ...s,
        target: rewriteExpr(s.target, lookup, consts),
        value: rewriteExpr(s.value, lookup, consts),
      };
    case "LoweredExprStmt":
      return { ...s, expr: rewriteExpr(s.expr, lookup, consts) };
    case "LoweredReturn":
      return s.value === null ? s : { ...s, value: rewriteExpr(s.value, lookup, consts) };
    case "LoweredLoop":
      return {
        ...s,
        cond: s.cond === null ? null : rewriteExpr(s.cond, lookup, consts),
        body: rewriteBlock(s.body, lookup, consts),
      };
    case "LoweredBreak":
    case "LoweredContinue":
      return s;
    default: {
      const _exhaustive: never = s;
      void _exhaustive;
      return s;
    }
  }
}
