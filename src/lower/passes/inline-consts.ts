// Lowered → Lowered pass: substitute every `LoweredIdent` referring to a
// const symbol with the const's value. Const values themselves may reference
// other consts ; resolved via a topological fixpoint. Cycles are caught at
// eval time, so this pass assumes the graph is acyclic.
//
// Routing per const decl, checked in order :
//   - data-pool : `const T[]` with primitive element + all-literal payload
//     lands in `LoweredProject.dataPool` ; reads emit `data.const`. One
//     allocation per process (`.rodata` on native, pre-materialised on
//     the VM).
//   - fn-wrap   : array literals above `FN_WRAP_MIN_ELEMENTS` that didn't
//     qualify for the pool (e.g. struct elements) get a synthetic 0-arg
//     fn so each reference becomes one `call N` instead of re-emitting
//     the full literal.
//   - inline    : everything else (small literal lists, scalars, ...).

import { zeroSpan } from "../../diagnostics/diagnostic.ts";
import type { Symbol } from "../../resolver/symbol.ts";
import type { Type } from "../../typecheck/types.ts";
import { mkFn } from "../../typecheck/types.ts";
import type { ArrayKind, BcDataEntry } from "../../bytecode/types.ts";
import type {
  LoweredBlock, LoweredConstDecl, LoweredDecl, LoweredExpr, LoweredFnDecl,
  LoweredModule, LoweredProject, LoweredStmt, LoweredStructLitField,
} from "../lowered-ast.ts";

// Break-even point : the call+array.get sequence at each access site is
// ~2 ops vs `2 * N` ops to re-emit the literal inline. Below 4 elements
// the inlined form is smaller, above it the fn-wrap wins.
const FN_WRAP_MIN_ELEMENTS = 4;

interface ConstRewrite {
  readonly inlineMap: ReadonlyMap<number, LoweredExpr>;
  readonly fnWrapMap: ReadonlyMap<number, FnWrapEntry>;
  readonly dataPoolMap: ReadonlyMap<number, DataPoolEntry>;
}

interface FnWrapEntry {
  readonly fnSymbol: Symbol;
  readonly callType: Type;
}

interface DataPoolEntry {
  readonly poolIndex: number;
  readonly type: Type;
}

export interface InlineConstsResult {
  readonly project: LoweredProject;
  readonly nextSyntheticId: number;
}

export function inlineConsts(p: LoweredProject, nextSyntheticId: number = 1_000_000): InlineConstsResult {
  const collected = collectInlinedConsts(p, nextSyntheticId);
  const rewrite = collected.rewrite;
  if (rewrite.inlineMap.size === 0 && rewrite.fnWrapMap.size === 0 && rewrite.dataPoolMap.size === 0) {
    return { project: { ...p, dataPool: [] }, nextSyntheticId };
  }

  const modules = new Map<string, LoweredModule>();
  for (const [id, m] of p.modules) {
    const decls: LoweredDecl[] = [];
    for (const d of m.decls) {
      switch (d.kind) {
        case "LoweredFnDecl":
          decls.push(rewriteFn(d, rewrite));
          break;
        case "LoweredConstDecl": {
          const symId = d.origin.symbol?.id;
          // Data-pool decls live in the project pool ; references were
          // rewritten to `LoweredDataConst` so the decl itself is dead.
          if (symId !== undefined && rewrite.dataPoolMap.has(symId)) break;
          if (symId !== undefined && rewrite.fnWrapMap.has(symId)) {
            decls.push(synthesizeFnFromConst(d, rewrite));
          } else {
            decls.push(rewriteConst(d, rewrite));
          }
          break;
        }
        case "LoweredStructDecl":
          decls.push(d);
          break;
      }
    }
    modules.set(id, { moduleId: m.moduleId, displayPath: m.displayPath, decls });
  }
  return {
    project: { modules, vtableEntries: p.vtableEntries, dataPool: collected.dataPool },
    nextSyntheticId: collected.nextSyntheticId,
  };
}

interface CollectedConsts {
  readonly rewrite: ConstRewrite;
  readonly nextSyntheticId: number;
  readonly dataPool: BcDataEntry[];
}

function collectInlinedConsts(p: LoweredProject, startId: number): CollectedConsts {
  const raw = new Map<number, LoweredExpr>();
  const constDeclBySymId = new Map<number, LoweredConstDecl>();
  for (const m of p.modules.values()) {
    for (const d of m.decls) {
      if (d.kind !== "LoweredConstDecl") continue;
      if (d.origin.symbol === null) continue;
      raw.set(d.origin.symbol.id, d.value);
      constDeclBySymId.set(d.origin.symbol.id, d);
    }
  }

  // Classification — three buckets, checked in priority order :
  //   data-pool : const T[] with primitive element + all-literal payload
  //   fn-wrap   : value too bulky to inline at every read site
  //   inline    : everything else (small literal lists, scalars, ...)
  // The pool decision must run BEFORE fn-wrap so SHA256_K-style tables
  // route to `.rodata` instead of a synth fn.
  const fnWrap = new Map<number, FnWrapEntry>();
  const dataPoolMap = new Map<number, DataPoolEntry>();
  const dataPool: BcDataEntry[] = [];
  let nextSyntheticId = startId;
  for (const [symId, raw0] of raw) {
    const origDecl = constDeclBySymId.get(symId)!;
    const poolEntry = materialiseToPool(raw0, origDecl.type);
    if (poolEntry !== null) {
      const poolIndex = dataPool.length;
      dataPool.push(poolEntry);
      dataPoolMap.set(symId, { poolIndex, type: origDecl.type });
      continue;
    }
    if (!shouldFnWrap(raw0)) continue;
    const origSym = origDecl.origin.symbol!;
    const fnSym: Symbol = {
      id: -nextSyntheticId++,
      kind: "fn",
      name: `__const_${origSym.name}`,
      module: origSym.module,
      visibility: "private",
      definedAt: origSym.definedAt,
      source: { kind: "synthetic", origin: `const-array:${origSym.name}` },
    };
    fnWrap.set(symId, { fnSymbol: fnSym, callType: origDecl.type });
  }

  const resolved = new Map<number, LoweredExpr>();
  const inFlight = new Set<number>();
  // Lookup returns null for non-const ids and fn-wrapped consts ; the
  // former pass through unchanged, the latter get a `LoweredCall` at
  // rewrite time.
  const lookup = (symId: number): LoweredExpr | null => {
    if (fnWrap.has(symId)) return null;
    if (dataPoolMap.has(symId)) return null;
    if (!raw.has(symId)) return null;
    return resolveOne(symId);
  };
  function resolveOne(symId: number): LoweredExpr {
    const cached = resolved.get(symId);
    if (cached !== undefined) return cached;
    const raw0 = raw.get(symId)!;
    if (inFlight.has(symId)) return raw0;     // cycle (caught at eval time)
    inFlight.add(symId);
    const inlined = rewriteExpr(raw0, { inlineLookup: lookup, fnWrap, dataPool: dataPoolMap });
    inFlight.delete(symId);
    resolved.set(symId, inlined);
    return inlined;
  }
  for (const symId of raw.keys()) {
    if (fnWrap.has(symId)) continue;
    if (dataPoolMap.has(symId)) continue;
    resolveOne(symId);
  }
  return {
    rewrite: { inlineMap: resolved, fnWrapMap: fnWrap, dataPoolMap },
    nextSyntheticId,
    dataPool,
  };
}

/** Eligibility + materialisation for the data pool. Returns the entry to
 *  push when the const decl qualifies, or `null` to fall back to inline /
 *  fn-wrap. Eligible : the decl's type is `const T[]` where T is a fixed-
 *  width primitive AND every element of the literal is itself a literal
 *  (so the pool entry's payload is a pure byte sequence). */
function materialiseToPool(value: LoweredExpr, declType: Type): BcDataEntry | null {
  if (declType.kind !== "Array" || !declType.immutable) return null;
  if (value.kind !== "LoweredArrayLit") return null;
  const kind = primitiveArrayKindOf(declType.element);
  if (kind === null) return null;
  const items: bigint[] = new Array(value.elements.length);
  for (let i = 0; i < value.elements.length; i++) {
    const lit = literalToBigInt(value.elements[i]!, kind);
    if (lit === null) return null;
    items[i] = lit;
  }
  return { kind, items };
}

function primitiveArrayKindOf(t: Type): ArrayKind | null {
  if (t.kind !== "Primitive") return null;
  switch (t.name) {
    case "u8":   return "u8";
    case "u16":  return "u16";
    case "u32":  return "u32";
    case "u64":  case "usize":  return "u64";
    case "i8":   return "i8";
    case "i16":  return "i16";
    case "i32":  return "i32";
    case "i64":  case "isize":  return "i64";
    case "f32":  return "f32";
    case "f64":  return "f64";
    case "char": return "char";
    case "bool": return "bool";
    default:     return null;
  }
}

/** Convert a literal LoweredExpr into the pool's bigint payload (IEEE 754
 *  bit pattern for floats). Constant casts unwrap to their inner literal.
 *  Returns null for anything that isn't a pure literal. */
function literalToBigInt(e: LoweredExpr, kind: ArrayKind): bigint | null {
  switch (e.kind) {
    case "LoweredIntLit":   return e.value;
    case "LoweredBoolLit":  return e.value ? 1n : 0n;
    case "LoweredCharLit":  return BigInt(e.value);
    case "LoweredFloatLit": return floatBitsToBigInt(e.value, kind);
    case "LoweredCast":     return literalToBigInt(e.value, kind);
    default:                return null;
  }
}

const FLOAT_BUF = new ArrayBuffer(8);
const FLOAT_DV = new DataView(FLOAT_BUF);

function floatBitsToBigInt(v: number, kind: ArrayKind): bigint | null {
  if (kind === "f32") {
    FLOAT_DV.setFloat32(0, v, true);
    return BigInt(FLOAT_DV.getUint32(0, true));
  }
  if (kind === "f64") {
    FLOAT_DV.setFloat64(0, v, true);
    return FLOAT_DV.getBigUint64(0, true);
  }
  return null;
}

function shouldFnWrap(value: LoweredExpr): boolean {
  return value.kind === "LoweredArrayLit" && value.elements.length >= FN_WRAP_MIN_ELEMENTS;
}

function synthesizeFnFromConst(
  d: LoweredConstDecl, rewrite: ConstRewrite,
): LoweredFnDecl {
  const entry = rewrite.fnWrapMap.get(d.origin.symbol!.id)!;
  const body = rewriteExpr(d.value, mkRewriteCtx(rewrite));
  return {
    kind: "LoweredFnDecl",
    mangled: `__const_${d.mangled}`,
    params: [],
    returnType: d.type,
    body: {
      kind: "LoweredBlock",
      span: zeroSpan("<synthetic>"),
      type: d.type,
      stmts: [],
      trailing: body,
    },
    // Override the symbol so call dispatch resolves to this synth fn ; the
    // ConstDecl-backed `origin.decl` is fine because downstream phases
    // guard on `decl.kind === "FnDecl"` before touching it.
    origin: { ...d.origin, symbol: entry.fnSymbol },
  };
}

interface RewriteCtx {
  readonly inlineLookup: (symId: number) => LoweredExpr | null;
  readonly fnWrap: ReadonlyMap<number, FnWrapEntry>;
  readonly dataPool: ReadonlyMap<number, DataPoolEntry>;
}

function mkRewriteCtx(rewrite: ConstRewrite): RewriteCtx {
  return {
    inlineLookup: (id) => rewrite.inlineMap.get(id) ?? null,
    fnWrap: rewrite.fnWrapMap,
    dataPool: rewrite.dataPoolMap,
  };
}

function rewriteFn(d: LoweredFnDecl, rewrite: ConstRewrite): LoweredFnDecl {
  if (d.body === null) return d;
  return { ...d, body: rewriteBlock(d.body, mkRewriteCtx(rewrite)) };
}

function rewriteConst(d: LoweredConstDecl, rewrite: ConstRewrite): LoweredConstDecl {
  // After the substitution map is fully resolved, every const decl's value
  // should be its inlined form. If the resolution map has an entry for this
  // const's symbol, prefer it ; otherwise fall back to walking the raw
  // value (e.g. for synthetic consts not present in the map).
  if (d.origin.symbol === null) return d;
  const inlined = rewrite.inlineMap.get(d.origin.symbol.id);
  if (inlined !== undefined) return { ...d, value: inlined };
  return { ...d, value: rewriteExpr(d.value, mkRewriteCtx(rewrite)) };
}

/** Recursive expression rewriter. Const idents become either the inlined
 *  value or a `LoweredCall` to a synthesized 0-arg fn, depending on the
 *  fn-wrap classification. */
function rewriteExpr(e: LoweredExpr, ctx: RewriteCtx): LoweredExpr {
  switch (e.kind) {
    case "LoweredIdent": {
      const pooled = ctx.dataPool.get(e.symbol.id);
      if (pooled !== undefined) {
        return {
          kind: "LoweredDataConst", span: e.span,
          type: pooled.type, poolIndex: pooled.poolIndex,
        };
      }
      const wrap = ctx.fnWrap.get(e.symbol.id);
      if (wrap !== undefined) {
        const calleeIdent: LoweredExpr = {
          kind: "LoweredIdent", span: e.span,
          type: mkFn([], wrap.callType),
          symbol: wrap.fnSymbol,
        };
        return {
          kind: "LoweredCall", span: e.span, type: wrap.callType,
          callee: calleeIdent, args: [],
        };
      }
      const subst = ctx.inlineLookup(e.symbol.id);
      return subst ?? e;
    }
    case "LoweredCall":
      return {
        ...e,
        callee: rewriteExpr(e.callee, ctx),
        args: e.args.map((a) => rewriteExpr(a, ctx)),
      };
    case "LoweredVirtualCall":
      return {
        ...e,
        receiver: rewriteExpr(e.receiver, ctx),
        args: e.args.map((a) => rewriteExpr(a, ctx)),
      };
    case "LoweredFieldAccess":
      return { ...e, target: rewriteExpr(e.target, ctx) };
    case "LoweredIndex":
      return {
        ...e,
        target: rewriteExpr(e.target, ctx),
        index: rewriteExpr(e.index, ctx),
      };
    case "LoweredUnary":
      return { ...e, operand: rewriteExpr(e.operand, ctx) };
    case "LoweredBinary":
      return {
        ...e,
        left: rewriteExpr(e.left, ctx),
        right: rewriteExpr(e.right, ctx),
      };
    case "LoweredIf":
      return {
        ...e,
        cond: rewriteExpr(e.cond, ctx),
        then: rewriteBlock(e.then, ctx),
        else: e.else === null ? null : rewriteBlock(e.else, ctx),
      };
    case "LoweredBlock":
      return rewriteBlock(e, ctx);
    case "LoweredStructLit":
      return {
        ...e,
        fields: e.fields.map((f): LoweredStructLitField => ({
          name: f.name,
          value: rewriteExpr(f.value, ctx),
        })),
      };
    case "LoweredArrayLit":
      return { ...e, elements: e.elements.map((el) => rewriteExpr(el, ctx)) };
    case "LoweredArrayLen":
      return { ...e, target: rewriteExpr(e.target, ctx) };
    case "LoweredArrayPush":
      return {
        ...e,
        target: rewriteExpr(e.target, ctx),
        value: rewriteExpr(e.value, ctx),
      };
    case "LoweredArraySlice":
      return {
        ...e,
        target: rewriteExpr(e.target, ctx),
        lo: rewriteExpr(e.lo, ctx),
        hi: rewriteExpr(e.hi, ctx),
      };
    case "LoweredCast":
      return { ...e, value: rewriteExpr(e.value, ctx) };
    case "LoweredTypeCheck":
      return { ...e, value: rewriteExpr(e.value, ctx) };
    case "LoweredIntrinsicCall":
      return { ...e, args: e.args.map((a) => rewriteExpr(a, ctx)) };
    case "LoweredCellNew":
      return { ...e, value: rewriteExpr(e.value, ctx) };
    case "LoweredCellGet":
      return { ...e, target: rewriteExpr(e.target, ctx) };
    case "LoweredMakeClosure":
      return { ...e, env: rewriteExpr(e.env, ctx) };
    case "LoweredIntLit":
    case "LoweredFloatLit":
    case "LoweredBoolLit":
    case "LoweredNullLit":
    case "LoweredCharLit":
    case "LoweredStringLit":
    case "LoweredUnreachable":
    case "LoweredDataConst":
    case "LoweredTypeConst":
      return e;
    default: {
      const _exhaustive: never = e;
      void _exhaustive;
      return e;
    }
  }
}

function rewriteBlock(b: LoweredBlock, ctx: RewriteCtx): LoweredBlock {
  return {
    ...b,
    stmts: b.stmts.map((s) => rewriteStmt(s, ctx)),
    trailing: b.trailing === null ? null : rewriteExpr(b.trailing, ctx),
  };
}

function rewriteStmt(s: LoweredStmt, ctx: RewriteCtx): LoweredStmt {
  switch (s.kind) {
    case "LoweredLet":
      return { ...s, value: rewriteExpr(s.value, ctx) };
    case "LoweredAssign":
      return {
        ...s,
        target: rewriteExpr(s.target, ctx),
        value: rewriteExpr(s.value, ctx),
      };
    case "LoweredCellSet":
      return {
        ...s,
        target: rewriteExpr(s.target, ctx),
        value: rewriteExpr(s.value, ctx),
      };
    case "LoweredExprStmt":
      return { ...s, expr: rewriteExpr(s.expr, ctx) };
    case "LoweredReturn":
      return s.value === null ? s : { ...s, value: rewriteExpr(s.value, ctx) };
    case "LoweredLoop":
      return {
        ...s,
        cond: s.cond === null ? null : rewriteExpr(s.cond, ctx),
        body: rewriteBlock(s.body, ctx),
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
