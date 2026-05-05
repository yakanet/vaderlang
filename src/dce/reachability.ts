// Walker that visits every symbol/type reference inside a LoweredDecl. The DCE
// pass uses it to collect the symbols transitively reachable from a set of
// roots. Kept separate from `index.ts` so it can be unit-tested in isolation.

import { forEachType } from "../typecheck/types.ts";
import type { Type } from "../typecheck/types.ts";
import type {
  LoweredBlock, LoweredDecl, LoweredExpr, LoweredStmt,
} from "../lower/index.ts";

export type RefVisitor = (symbolId: number) => void;

export function forEachReference(decl: LoweredDecl, visit: RefVisitor): void {
  switch (decl.kind) {
    case "LoweredFnDecl":
      for (const p of decl.params) walkType(p.type, visit);
      walkType(decl.returnType, visit);
      if (decl.body !== null) walkBlock(decl.body, visit);
      return;
    case "LoweredStructDecl":
      for (const f of decl.fields) walkType(f.type, visit);
      return;
    case "LoweredConstDecl":
      walkType(decl.type, visit);
      walkExpr(decl.value, visit);
      return;
    default: {
      const _exhaustive: never = decl;
      void _exhaustive;
    }
  }
}

function walkBlock(b: LoweredBlock, visit: RefVisitor): void {
  walkType(b.type, visit);
  for (const s of b.stmts) walkStmt(s, visit);
  if (b.trailing !== null) walkExpr(b.trailing, visit);
}

function walkStmt(s: LoweredStmt, visit: RefVisitor): void {
  switch (s.kind) {
    case "LoweredLet":
      walkType(s.type, visit);
      walkExpr(s.value, visit);
      return;
    case "LoweredAssign":
      walkExpr(s.target, visit);
      walkExpr(s.value, visit);
      return;
    case "LoweredExprStmt":
      walkExpr(s.expr, visit);
      return;
    case "LoweredReturn":
      if (s.value !== null) walkExpr(s.value, visit);
      return;
    case "LoweredLoop":
      if (s.cond !== null) walkExpr(s.cond, visit);
      walkBlock(s.body, visit);
      return;
    case "LoweredBreak":
    case "LoweredContinue":
      return;
    default: {
      const _exhaustive: never = s;
      void _exhaustive;
    }
  }
}

function walkExpr(e: LoweredExpr, visit: RefVisitor): void {
  walkType(e.type, visit);
  switch (e.kind) {
    case "LoweredIdent":
      visit(e.symbol.id);
      return;
    case "LoweredCall":
      walkExpr(e.callee, visit);
      for (const a of e.args) walkExpr(a, visit);
      return;
    case "LoweredFieldAccess":
      walkExpr(e.target, visit);
      return;
    case "LoweredIndex":
      walkExpr(e.target, visit);
      walkExpr(e.index, visit);
      return;
    case "LoweredUnary":
      walkExpr(e.operand, visit);
      return;
    case "LoweredBinary":
      walkExpr(e.left, visit);
      walkExpr(e.right, visit);
      return;
    case "LoweredIf":
      walkExpr(e.cond, visit);
      walkBlock(e.then, visit);
      if (e.else !== null) walkBlock(e.else, visit);
      return;
    case "LoweredBlock":
      walkBlock(e, visit);
      return;
    case "LoweredStructLit":
      for (const f of e.fields) walkExpr(f.value, visit);
      return;
    case "LoweredArrayLit":
      for (const elt of e.elements) walkExpr(elt, visit);
      return;
    case "LoweredArrayLen":
      walkExpr(e.target, visit);
      return;
    case "LoweredCast":
      walkExpr(e.value, visit);
      return;
    case "LoweredTypeCheck":
      walkExpr(e.value, visit);
      walkType(e.checkType, visit);
      return;
    case "LoweredIntrinsicCall":
      for (const a of e.args) walkExpr(a, visit);
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
