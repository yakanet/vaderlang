// Walker that visits every symbol/type reference inside a LoweredDecl. The DCE
// pass uses it to collect the symbols transitively reachable from a set of
// roots. Kept separate from `index.ts` so it can be unit-tested in isolation.

import { forEachType } from "../typecheck/types.ts";
import type { Type } from "../typecheck/types.ts";
import type {
  LoweredBlock, LoweredDecl, LoweredExpr, LoweredStmt,
} from "../lower/index.ts";

export type RefVisitor = (symbolId: number) => void;
/** Reported once per `LoweredVirtualCall`. DCE wires this to a (trait,
 *  method) → impl-fn-symbols index so every candidate is kept alive — the
 *  static `LoweredVirtualCall` doesn't carry the impl set on its node. */
export type VirtualCallVisitor = (trait: string, method: string) => void;

export function forEachReference(
  decl: LoweredDecl, visit: RefVisitor, visitVirtual?: VirtualCallVisitor,
): void {
  switch (decl.kind) {
    case "LoweredFnDecl":
      for (const p of decl.params) walkType(p.type, visit);
      walkType(decl.returnType, visit);
      if (decl.body !== null) walkBlock(decl.body, visit, visitVirtual);
      return;
    case "LoweredStructDecl":
      for (const f of decl.fields) walkType(f.type, visit);
      return;
    case "LoweredConstDecl":
      walkType(decl.type, visit);
      walkExpr(decl.value, visit, visitVirtual);
      return;
    default: {
      const _exhaustive: never = decl;
      void _exhaustive;
    }
  }
}

function walkBlock(b: LoweredBlock, visit: RefVisitor, visitVirtual?: VirtualCallVisitor): void {
  walkType(b.type, visit);
  for (const s of b.stmts) walkStmt(s, visit, visitVirtual);
  if (b.trailing !== null) walkExpr(b.trailing, visit, visitVirtual);
}

function walkStmt(s: LoweredStmt, visit: RefVisitor, visitVirtual?: VirtualCallVisitor): void {
  switch (s.kind) {
    case "LoweredLet":
      walkType(s.type, visit);
      walkExpr(s.value, visit, visitVirtual);
      return;
    case "LoweredAssign":
      walkExpr(s.target, visit, visitVirtual);
      walkExpr(s.value, visit, visitVirtual);
      return;
    case "LoweredExprStmt":
      walkExpr(s.expr, visit, visitVirtual);
      return;
    case "LoweredReturn":
      if (s.value !== null) walkExpr(s.value, visit, visitVirtual);
      return;
    case "LoweredLoop":
      if (s.cond !== null) walkExpr(s.cond, visit, visitVirtual);
      walkBlock(s.body, visit, visitVirtual);
      return;
    case "LoweredBreak":
    case "LoweredContinue":
      return;
    case "LoweredCellSet":
      walkExpr(s.target, visit, visitVirtual);
      walkExpr(s.value, visit, visitVirtual);
      walkType(s.valueType, visit);
      return;
    default: {
      const _exhaustive: never = s;
      void _exhaustive;
    }
  }
}

function walkExpr(e: LoweredExpr, visit: RefVisitor, visitVirtual?: VirtualCallVisitor): void {
  walkType(e.type, visit);
  switch (e.kind) {
    case "LoweredIdent":
      visit(e.symbol.id);
      return;
    case "LoweredCall":
      walkExpr(e.callee, visit, visitVirtual);
      for (const a of e.args) walkExpr(a, visit, visitVirtual);
      return;
    case "LoweredVirtualCall":
      if (visitVirtual !== undefined) visitVirtual(e.traitName, e.method);
      walkExpr(e.receiver, visit, visitVirtual);
      for (const a of e.args) walkExpr(a, visit, visitVirtual);
      return;
    case "LoweredFieldAccess":
      walkExpr(e.target, visit, visitVirtual);
      return;
    case "LoweredIndex":
      walkExpr(e.target, visit, visitVirtual);
      walkExpr(e.index, visit, visitVirtual);
      return;
    case "LoweredUnary":
      walkExpr(e.operand, visit, visitVirtual);
      return;
    case "LoweredBinary":
      walkExpr(e.left, visit, visitVirtual);
      walkExpr(e.right, visit, visitVirtual);
      return;
    case "LoweredIf":
      walkExpr(e.cond, visit, visitVirtual);
      walkBlock(e.then, visit, visitVirtual);
      if (e.else !== null) walkBlock(e.else, visit, visitVirtual);
      return;
    case "LoweredBlock":
      walkBlock(e, visit, visitVirtual);
      return;
    case "LoweredStructLit":
      for (const f of e.fields) walkExpr(f.value, visit, visitVirtual);
      return;
    case "LoweredArrayLit":
      for (const elt of e.elements) walkExpr(elt, visit, visitVirtual);
      return;
    case "LoweredArrayLen":
      walkExpr(e.target, visit, visitVirtual);
      return;
    case "LoweredArrayPush":
      walkExpr(e.target, visit, visitVirtual);
      walkExpr(e.value, visit, visitVirtual);
      return;
    case "LoweredCast":
      walkExpr(e.value, visit, visitVirtual);
      return;
    case "LoweredTypeCheck":
      walkExpr(e.value, visit, visitVirtual);
      walkType(e.checkType, visit);
      return;
    case "LoweredIntrinsicCall":
      for (const a of e.args) walkExpr(a, visit, visitVirtual);
      if (e.displayFor !== undefined) walkType(e.displayFor, visit);
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
      walkExpr(e.value, visit, visitVirtual);
      walkType(e.valueType, visit);
      return;
    case "LoweredCellGet":
      walkExpr(e.target, visit, visitVirtual);
      walkType(e.valueType, visit);
      return;
    case "LoweredMakeClosure":
      // The lifted fn is reachable iff this make_closure is. Synthesised
      // symbols carry negative ids; we still emit the visit so DCE keeps the
      // lifted decl alive.
      visit(e.fnSymbol.id);
      walkExpr(e.env, visit, visitVirtual);
      return;
    default: {
      const _exhaustive: never = e;
      void _exhaustive;
    }
  }
}

function walkType(t: Type, visit: RefVisitor): void {
  forEachType(t, (sub) => {
    if (sub.kind === "Struct" || sub.kind === "Trait") visit(sub.symbol.id);
  });
}
