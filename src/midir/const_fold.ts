// Constant folding on the Mid-IR CFG.
//
// Walks each basic block in order. Tracks `LocalId → ConstValue` for every
// `Const` instruction seen so far in the block. When a `BinOp` (or `UnOp`)
// reads two (resp. one) tracked operands and the op is foldable, replaces
// the operation with a fresh `Const` carrying the computed value. The
// subsequent DCE pass collects any now-unused producer consts.
//
// Intra-block only : tracking across block boundaries requires CFG-wide
// SSA-style propagation, which is the next bigger step. Most arithmetic
// expressions in source code lower to a single straight-line block, so
// intra-block already catches the common cases (`1 + 2`, `len * 2 + 1`,
// `BUF_SIZE - 1`, etc.).
//
// Folding rules :
//   - Integer arith   : add, sub, mul, div, mod        (skip on div/mod by 0)
//   - Float arith     : add, sub, mul, div, mod        (IEEE, no trap)
//   - Bitwise         : shl, shr, bitand, bitor, bitxor
//   - Comparisons     : eq, neq, lt, lte, gt, gte      (int / float / bool / char)
//   - Logical         : and, or                        (bool)
//   - UnOp negation   : `-x` on int / float            ; `!b` on bool
//
// String concat is NOT folded here — the BinOp signature carries the index
// into `BcModule.strings`, and stitching two indices into a fresh entry
// requires a string-pool API the MidIR doesn't expose at this stage.

import type {
  BasicBlock, CFGFunction, CFGModule, CFGProject, ConstValue, Instruction, LocalId,
} from "./cfg.ts";
import type { LoweredBinaryOp, LoweredUnaryOp } from "../lower/lowered-ast.ts";
import type { Type } from "../typecheck/types.ts";

/** Run constant folding on every block of every function in every module. */
export function constFoldProject(p: CFGProject): CFGProject {
  const out = new Map<string, CFGModule>();
  for (const [id, m] of p.modules) {
    out.set(id, { ...m, functions: m.functions.map(constFoldFunction) });
  }
  return { ...p, modules: out };
}

function constFoldFunction(fn: CFGFunction): CFGFunction {
  let mutated = false;
  const newBlocks = fn.blocks.map((b) => {
    const folded = constFoldBlock(b);
    if (folded === b.instructions) return b;
    mutated = true;
    return { id: b.id, instructions: folded, terminator: b.terminator, span: b.span };
  });
  return mutated ? { ...fn, blocks: newBlocks } : fn;
}

function constFoldBlock(b: BasicBlock): readonly Instruction[] {
  const consts = new Map<LocalId, ConstValue>();
  const out: Instruction[] = [];
  let mutated = false;
  for (const ins of b.instructions) {
    if (ins.kind === "Const") {
      consts.set(ins.dst, ins.value);
      out.push(ins);
      continue;
    }
    if (ins.kind === "BinOp") {
      const l = consts.get(ins.lhs);
      const r = consts.get(ins.rhs);
      if (l !== undefined && r !== undefined) {
        const raw = foldBinOp(ins.op, l, r);
        const folded = raw === undefined ? undefined : truncateToType(raw, ins.type);
        if (folded !== undefined) {
          const replacement: Instruction = {
            kind: "Const", dst: ins.dst, value: folded, type: ins.type, span: ins.span,
          };
          consts.set(ins.dst, folded);
          out.push(replacement);
          mutated = true;
          continue;
        }
      }
      out.push(ins);
      continue;
    }
    if (ins.kind === "UnOp") {
      const v = consts.get(ins.operand);
      if (v !== undefined) {
        const raw = foldUnOp(ins.op, v);
        const folded = raw === undefined ? undefined : truncateToType(raw, ins.type);
        if (folded !== undefined) {
          const replacement: Instruction = {
            kind: "Const", dst: ins.dst, value: folded, type: ins.type, span: ins.span,
          };
          consts.set(ins.dst, folded);
          out.push(replacement);
          mutated = true;
          continue;
        }
      }
      out.push(ins);
      continue;
    }
    out.push(ins);
  }
  return mutated ? out : b.instructions;
}

function foldBinOp(op: LoweredBinaryOp, l: ConstValue, r: ConstValue): ConstValue | undefined {
  // Both operands must share a kind we know how to fold.
  if (l.kind === "int" && r.kind === "int") return foldIntBinOp(op, l.value, r.value);
  if (l.kind === "float" && r.kind === "float") return foldFloatBinOp(op, l.value, r.value);
  if (l.kind === "bool" && r.kind === "bool") return foldBoolBinOp(op, l.value, r.value);
  if (l.kind === "char" && r.kind === "char") return foldCharBinOp(op, l.value, r.value);
  return undefined;
}

function foldIntBinOp(op: LoweredBinaryOp, l: bigint, r: bigint): ConstValue | undefined {
  switch (op) {
    case "add":    return { kind: "int", value: l + r };
    case "sub":    return { kind: "int", value: l - r };
    case "mul":    return { kind: "int", value: l * r };
    case "div":    return r === 0n ? undefined : { kind: "int", value: l / r };
    case "mod":    return r === 0n ? undefined : { kind: "int", value: l % r };
    // Shift counts ≥ bit-width are runtime-defined. We don't have the
    // result type here, so we let the post-fold `truncateToType` clamp
    // the result. For narrow ints the VM's JS `<<` masks the count mod
    // 32 ; the only path that would diverge is a literal `1 << 100` on
    // i32, where VM gives 16 but BigInt + truncate gives 0. We skip
    // those huge counts so the runtime (which knows the type width)
    // handles them consistently — folding would just bake in our
    // possibly-wrong width assumption.
    case "shl":    return r < 0n || r >= 64n ? undefined : { kind: "int", value: l << r };
    case "shr":    return r < 0n || r >= 64n ? undefined : { kind: "int", value: l >> r };
    case "bitand": return { kind: "int", value: l & r };
    case "bitor":  return { kind: "int", value: l | r };
    case "bitxor": return { kind: "int", value: l ^ r };
    case "eq":     return { kind: "bool", value: l === r };
    case "neq":    return { kind: "bool", value: l !== r };
    case "lt":     return { kind: "bool", value: l < r };
    case "lte":    return { kind: "bool", value: l <= r };
    case "gt":     return { kind: "bool", value: l > r };
    case "gte":    return { kind: "bool", value: l >= r };
    default:       return undefined;
  }
}

function foldFloatBinOp(op: LoweredBinaryOp, l: number, r: number): ConstValue | undefined {
  switch (op) {
    case "add": return { kind: "float", value: l + r };
    case "sub": return { kind: "float", value: l - r };
    case "mul": return { kind: "float", value: l * r };
    case "div": return { kind: "float", value: l / r };
    case "mod": return { kind: "float", value: l % r };
    case "eq":  return { kind: "bool", value: l === r };
    case "neq": return { kind: "bool", value: l !== r };
    case "lt":  return { kind: "bool", value: l <  r };
    case "lte": return { kind: "bool", value: l <= r };
    case "gt":  return { kind: "bool", value: l >  r };
    case "gte": return { kind: "bool", value: l >= r };
    default:    return undefined;
  }
}

function foldBoolBinOp(op: LoweredBinaryOp, l: boolean, r: boolean): ConstValue | undefined {
  switch (op) {
    case "and": return { kind: "bool", value: l && r };
    case "or":  return { kind: "bool", value: l || r };
    case "eq":  return { kind: "bool", value: l === r };
    case "neq": return { kind: "bool", value: l !== r };
    default:    return undefined;
  }
}

function foldCharBinOp(op: LoweredBinaryOp, l: number, r: number): ConstValue | undefined {
  switch (op) {
    case "eq":  return { kind: "bool", value: l === r };
    case "neq": return { kind: "bool", value: l !== r };
    case "lt":  return { kind: "bool", value: l <  r };
    case "lte": return { kind: "bool", value: l <= r };
    case "gt":  return { kind: "bool", value: l >  r };
    case "gte": return { kind: "bool", value: l >= r };
    default:    return undefined;
  }
}

// Truncate / sign-extend an integer ConstValue to its declared type's
// bit width so the folded value matches what the bytecode interpreter
// (and the native runtime) would produce after the arithmetic actually
// ran. Non-int kinds pass through unchanged.
function truncateToType(v: ConstValue, t: Type): ConstValue {
  if (v.kind !== "int") return v;
  if (t.kind !== "Primitive") return v;
  switch (t.name) {
    case "i8":    return { kind: "int", value: BigInt.asIntN(8,  v.value) };
    case "i16":   return { kind: "int", value: BigInt.asIntN(16, v.value) };
    case "i32":   return { kind: "int", value: BigInt.asIntN(32, v.value) };
    case "i64":   return { kind: "int", value: BigInt.asIntN(64, v.value) };
    case "isize": return { kind: "int", value: BigInt.asIntN(64, v.value) };
    case "u8":    return { kind: "int", value: BigInt.asUintN(8,  v.value) };
    case "u16":   return { kind: "int", value: BigInt.asUintN(16, v.value) };
    case "u32":   return { kind: "int", value: BigInt.asUintN(32, v.value) };
    case "u64":   return { kind: "int", value: BigInt.asUintN(64, v.value) };
    case "usize": return { kind: "int", value: BigInt.asUintN(64, v.value) };
    default:      return v;
  }
}

function foldUnOp(op: LoweredUnaryOp, v: ConstValue): ConstValue | undefined {
  switch (op) {
    case "neg":
      if (v.kind === "int")   return { kind: "int", value: -v.value };
      if (v.kind === "float") return { kind: "float", value: -v.value };
      return undefined;
    case "not":
      if (v.kind === "bool")  return { kind: "bool", value: !v.value };
      return undefined;
    case "bitnot":
      if (v.kind === "int")   return { kind: "int", value: ~v.value };
      return undefined;
    default:
      return undefined;
  }
}
