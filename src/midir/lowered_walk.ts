// Walker that visits every symbol/type reference inside a LoweredDecl. The
// whole-program DCE in `dce.ts` uses it to walk struct/const decls (which the
// CFG passes through unchanged) and to seed externs that aren't in the CFG.

import { canonicalArgsKey, forEachType } from "../typecheck/types.ts";
import type { Type } from "../typecheck/types.ts";
import type {
  LoweredBlock, LoweredDecl, LoweredExpr, LoweredStmt,
} from "../lower/index.ts";

export type RefVisitor = (symbolId: number) => void;
/** Concrete struct-instance visitor. DCE keeps a `(symbol.id, argsKey)` set
 *  alongside the plain `symbolId` set so it can prune mono variants — e.g.
 *  drop `ArrayIterator(string)` while keeping `ArrayIterator(i32)` — that
 *  the symbol-only filter can't distinguish because all instances of a
 *  generic struct share their base symbol. Reported on every concrete
 *  Struct type seen via `walkType`. */
export type StructInstVisitor = (key: string) => void;
/** Reported once per `LoweredVirtualCall`. DCE wires this to a (trait,
 *  method) → impl-fn-symbols index so every candidate is kept alive — the
 *  static `LoweredVirtualCall` doesn't carry the impl set on its node. */
export type VirtualCallVisitor = (trait: string, method: string) => void;

interface WalkCtx {
  readonly visit: RefVisitor;
  readonly visitVirtual?: VirtualCallVisitor;
  readonly visitStructInst?: StructInstVisitor;
}

/** Canonical key for a concrete struct instance, shared between DCE's
 *  reachability set and `LoweredStructDecl.origin` lookup. */
export function structInstKey(symbolId: number, args: readonly Type[]): string {
  return `${symbolId}|${canonicalArgsKey(args)}`;
}

export function forEachReference(
  decl: LoweredDecl, visit: RefVisitor, visitVirtual?: VirtualCallVisitor,
  visitStructInst?: StructInstVisitor,
): void {
  const ctx: WalkCtx = { visit, visitVirtual, visitStructInst };
  switch (decl.kind) {
    case "LoweredFnDecl":
      for (const p of decl.params) walkType(p.type, ctx);
      walkType(decl.returnType, ctx);
      if (decl.body !== null) walkBlock(decl.body, ctx);
      return;
    case "LoweredStructDecl":
      for (const f of decl.fields) walkType(f.type, ctx);
      return;
    case "LoweredConstDecl":
      walkType(decl.type, ctx);
      walkExpr(decl.value, ctx);
      return;
    default: {
      const _exhaustive: never = decl;
      void _exhaustive;
    }
  }
}

function walkBlock(b: LoweredBlock, ctx: WalkCtx): void {
  walkType(b.type, ctx);
  for (const s of b.stmts) walkStmt(s, ctx);
  if (b.trailing !== null) walkExpr(b.trailing, ctx);
}

function walkStmt(s: LoweredStmt, ctx: WalkCtx): void {
  switch (s.kind) {
    case "LoweredLet":
      walkType(s.type, ctx);
      walkExpr(s.value, ctx);
      return;
    case "LoweredAssign":
      walkExpr(s.target, ctx);
      walkExpr(s.value, ctx);
      return;
    case "LoweredExprStmt":
      walkExpr(s.expr, ctx);
      return;
    case "LoweredReturn":
      if (s.value !== null) walkExpr(s.value, ctx);
      return;
    case "LoweredLoop":
      if (s.cond !== null) walkExpr(s.cond, ctx);
      walkBlock(s.body, ctx);
      return;
    case "LoweredBreak":
    case "LoweredContinue":
      return;
    case "LoweredCellSet":
      walkExpr(s.target, ctx);
      walkExpr(s.value, ctx);
      walkType(s.valueType, ctx);
      return;
    default: {
      const _exhaustive: never = s;
      void _exhaustive;
    }
  }
}

function walkExpr(e: LoweredExpr, ctx: WalkCtx): void {
  walkType(e.type, ctx);
  switch (e.kind) {
    case "LoweredIdent":
      ctx.visit(e.symbol.id);
      return;
    case "LoweredCall":
      walkExpr(e.callee, ctx);
      for (const a of e.args) walkExpr(a, ctx);
      return;
    case "LoweredVirtualCall":
      if (ctx.visitVirtual !== undefined) ctx.visitVirtual(e.traitName, e.method);
      walkExpr(e.receiver, ctx);
      for (const a of e.args) walkExpr(a, ctx);
      return;
    case "LoweredFieldAccess":
      walkExpr(e.target, ctx);
      return;
    case "LoweredIndex":
      walkExpr(e.target, ctx);
      walkExpr(e.index, ctx);
      return;
    case "LoweredUnary":
      walkExpr(e.operand, ctx);
      return;
    case "LoweredBinary":
      walkExpr(e.left, ctx);
      walkExpr(e.right, ctx);
      return;
    case "LoweredIf":
      walkExpr(e.cond, ctx);
      walkBlock(e.then, ctx);
      if (e.else !== null) walkBlock(e.else, ctx);
      return;
    case "LoweredBlock":
      walkBlock(e, ctx);
      return;
    case "LoweredStructLit":
      for (const f of e.fields) walkExpr(f.value, ctx);
      return;
    case "LoweredArrayLit":
      for (const elt of e.elements) walkExpr(elt, ctx);
      return;
    case "LoweredArrayLen":
      walkExpr(e.target, ctx);
      return;
    case "LoweredArrayPush":
      walkExpr(e.target, ctx);
      walkExpr(e.value, ctx);
      return;
    case "LoweredCast":
      walkExpr(e.value, ctx);
      return;
    case "LoweredTypeCheck":
      walkExpr(e.value, ctx);
      walkType(e.checkType, ctx);
      return;
    case "LoweredIntrinsicCall":
      for (const a of e.args) walkExpr(a, ctx);
      if (e.displayFor !== undefined) walkType(e.displayFor, ctx);
      return;
    case "LoweredIntLit":
    case "LoweredFloatLit":
    case "LoweredBoolLit":
    case "LoweredNullLit":
    case "LoweredCharLit":
    case "LoweredStringLit":
    case "LoweredUnreachable":
      return;
    case "LoweredCellNew":
      walkExpr(e.value, ctx);
      walkType(e.valueType, ctx);
      return;
    case "LoweredCellGet":
      walkExpr(e.target, ctx);
      walkType(e.valueType, ctx);
      return;
    case "LoweredMakeClosure":
      // The lifted fn is reachable iff this make_closure is. Synthesised
      // symbols carry negative ids; we still emit the visit so DCE keeps the
      // lifted decl alive.
      ctx.visit(e.fnSymbol.id);
      walkExpr(e.env, ctx);
      return;
    default: {
      const _exhaustive: never = e;
      void _exhaustive;
    }
  }
}

function walkType(t: Type, ctx: WalkCtx): void {
  forEachType(t, (sub) => {
    if (sub.kind === "Struct") {
      ctx.visit(sub.symbol.id);
      if (ctx.visitStructInst !== undefined) {
        ctx.visitStructInst(structInstKey(sub.symbol.id, sub.args));
      }
    } else if (sub.kind === "Trait") {
      ctx.visit(sub.symbol.id);
    }
  });
}
