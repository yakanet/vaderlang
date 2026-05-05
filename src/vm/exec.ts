// Bytecode VM — executes a `BytecodeModule` produced by §1.7's emitter.
// Stack-based with WASM-style structured control flow. The VM trusts the
// bytecode to be type-correct (the type-checker has already validated it);
// type-assertion accessors trip only on an emitter bug.

import type { BytecodeModule, BcFunction } from "../bytecode/module.ts";
import type { Op } from "../bytecode/ops.ts";
import { INTRINSIC_TABLE } from "../bytecode/ops.ts";
import { isFloatVal } from "../bytecode/types.ts";
import type { BcType, ValType } from "../bytecode/types.ts";

import type { HostBindings } from "./host.ts";
import {
  bool, builder, ch, FALSE, i64, NULL, num, str as makeStr, VOID,
  asArray, asBig, asBool, asBuilder, asChar, asNum, asString, asStruct, displayValue,
} from "./value.ts";
import type { NumTag, StringValue, Value } from "./value.ts";

export interface RunOptions {
  readonly host: HostBindings;
  /** Override the entry-point fn name (mangled). Defaults to any fn whose
   *  name ends in `$main`. */
  readonly entry?: string;
  /** Stop after this many ops to guard tests against runaway loops. */
  readonly opLimit?: number;
}

export interface RunResult {
  readonly exitCode: number;
}

export class VmError extends Error {
  constructor(message: string, readonly debug?: string) {
    super(debug !== undefined ? `${message} (at ${debug})` : message);
  }
}

export function runProgram(m: BytecodeModule, opts: RunOptions): RunResult {
  const ctx = newRunCtx(m);
  const entry = findEntry(m, opts.entry);
  const result = invoke(ctx, entry, [], opts);
  if (result.tag === "void") return { exitCode: 0 };
  return { exitCode: Math.trunc(asNum(result)) | 0 };
}

export function findEntry(m: BytecodeModule, override?: string): number {
  if (override !== undefined) {
    const idx = m.functions.findIndex((f) => f.name === override);
    if (idx < 0) throw new VmError(`vm: entry function "${override}" not found`);
    return idx;
  }
  const idx = m.functions.findIndex((f) => f.name.endsWith("$main") && f.body.length > 0);
  if (idx < 0) throw new VmError(`vm: no main function found in module ${m.name}`);
  return idx;
}

// ----------------------------------------------------------- module ctx

interface RunCtx {
  readonly module: BytecodeModule;
  /** Pre-built `StringValue` per pool entry — saves an allocation per
   *  `string.const` and gives repeated literals a shared identity that makes
   *  `string.eq` short-circuit on `===`. */
  readonly stringPool: readonly StringValue[];
}

const JUMP_CACHE = new WeakMap<BcFunction, JumpInfo>();

function newRunCtx(m: BytecodeModule): RunCtx {
  return {
    module: m,
    stringPool: m.strings.map((s) => ({ tag: "string", n: s })),
  };
}

// ----------------------------------------------------------- frame model

interface Frame {
  readonly fn: BcFunction;
  readonly slots: Value[];
  readonly labels: Label[];
  readonly stack: Value[];
  ip: number;
  readonly jumps: JumpInfo;
}

type Label =
  | { readonly kind: "loop"; readonly openIp: number; readonly endIp: number; readonly stackBase: number; readonly yieldsValue: false }
  | { readonly kind: "block" | "if"; readonly endIp: number; readonly stackBase: number; readonly yieldsValue: boolean };

interface JumpInfo {
  /** Open ip (`block`/`loop`/`if`) → matching `end` ip. */
  readonly endOf: ReadonlyMap<number, number>;
  /** `if` ip → matching `else` ip. */
  readonly elseOf: ReadonlyMap<number, number>;
  /** `else` ip → enclosing `end` ip (so a fall-through jumps cleanly past it). */
  readonly endOfElse: ReadonlyMap<number, number>;
}

// ----------------------------------------------------------- core invoke

function invoke(ctx: RunCtx, fnIndex: number, args: Value[], opts: RunOptions): Value {
  const fn = ctx.module.functions[fnIndex];
  if (fn === undefined) throw new VmError(`vm: invalid fn index ${fnIndex}`);

  const slots = new Array<Value>(fn.signature.params.length + fn.locals.length);
  for (let i = 0; i < fn.signature.params.length; i++) slots[i] = args[i] ?? VOID;
  for (let i = 0; i < fn.locals.length; i++) {
    slots[fn.signature.params.length + i] = zeroFor(fn.locals[i]!.val);
  }

  const frame: Frame = {
    fn, slots, labels: [], stack: [], ip: 0,
    jumps: getJumps(fn),
  };

  const opLimit = opts.opLimit;
  if (opLimit !== undefined) {
    let executed = 0;
    while (frame.ip < fn.body.length) {
      if (++executed > opLimit) {
        throw new VmError(`vm: op limit exceeded (${opLimit})`, debugOf(fn, frame.ip - 1));
      }
      const r = step(ctx, frame, fn.body[frame.ip]!, opts);
      if (r !== undefined) return r;
    }
  } else {
    while (frame.ip < fn.body.length) {
      const r = step(ctx, frame, fn.body[frame.ip]!, opts);
      if (r !== undefined) return r;
    }
  }

  // Fall off the end (defensive — the lowerer always emits explicit `return`).
  if (fn.signature.result === "void") return VOID;
  if (frame.stack.length > 0) return frame.stack[frame.stack.length - 1]!;
  return zeroFor(fn.signature.result);
}

// ----------------------------------------------------------- step dispatch

/** Returns a `Value` when the frame returns, `undefined` to continue. */
function step(ctx: RunCtx, f: Frame, op: Op, opts: RunOptions): Value | undefined {
  switch (op.kind) {
    case "drop":   f.stack.pop(); f.ip++; return;
    case "dup":    f.stack.push(f.stack[f.stack.length - 1]!); f.ip++; return;

    case "local.get":  f.stack.push(f.slots[op.slot]!); f.ip++; return;
    case "local.set":  f.slots[op.slot] = f.stack.pop()!; f.ip++; return;
    case "local.tee":  f.slots[op.slot] = f.stack[f.stack.length - 1]!; f.ip++; return;

    case "i32.const":    f.stack.push(num("i32", op.value)); f.ip++; return;
    case "i64.const":    f.stack.push(i64("i64", op.value)); f.ip++; return;
    case "f32.const":    f.stack.push(num("f32", op.value)); f.ip++; return;
    case "f64.const":    f.stack.push(num("f64", op.value)); f.ip++; return;
    case "bool.const":   f.stack.push(bool(op.value));       f.ip++; return;
    case "char.const":   f.stack.push(ch(op.value));         f.ip++; return;
    case "null.const":   f.stack.push(NULL);                 f.ip++; return;
    case "string.const": {
      const s = ctx.stringPool[op.index];
      if (s === undefined) throw new VmError(`vm: bad string index ${op.index}`, debugOf(f.fn, f.ip));
      f.stack.push(s);
      f.ip++; return;
    }

    case "bool.and": pushBinop(f, asBool, (l, r) => l && r); return;
    case "bool.or":  pushBinop(f, asBool, (l, r) => l || r); return;
    case "bool.not": { const v = asBool(f.stack.pop()!); f.stack.push(bool(!v)); f.ip++; return; }

    case "ref.eq":     f.stack.push(bool(refEq(f.stack.pop()!, f.stack.pop()!))); f.ip++; return;
    case "ref.ne":     f.stack.push(bool(!refEq(f.stack.pop()!, f.stack.pop()!))); f.ip++; return;
    case "string.eq":  pushBinop(f, asString, (l, r) => l === r); return;
    case "string.ne":  pushBinop(f, asString, (l, r) => l !== r); return;
    case "char.eq":    pushBinop(f, asChar, (l, r) => l === r); return;
    case "char.ne":    pushBinop(f, asChar, (l, r) => l !== r); return;
    case "bool.eq":    pushBinop(f, asBool, (l, r) => l === r); return;
    case "bool.ne":    pushBinop(f, asBool, (l, r) => l !== r); return;

    case "block": {
      const endIp = f.jumps.endOf.get(f.ip)!;
      f.labels.push({ kind: "block", endIp, stackBase: f.stack.length, yieldsValue: op.result !== "void" });
      f.ip++; return;
    }
    case "loop": {
      const endIp = f.jumps.endOf.get(f.ip)!;
      f.labels.push({ kind: "loop", openIp: f.ip, endIp, stackBase: f.stack.length, yieldsValue: false });
      f.ip++; return;
    }
    case "if": {
      const endIp = f.jumps.endOf.get(f.ip)!;
      const elseIp = f.jumps.elseOf.get(f.ip);
      const cond = asBool(f.stack.pop()!);
      f.labels.push({ kind: "if", endIp, stackBase: f.stack.length, yieldsValue: op.result !== "void" });
      if (cond) {
        f.ip++;
      } else if (elseIp !== undefined) {
        f.ip = elseIp + 1;
      } else {
        f.labels.pop();
        f.ip = endIp + 1;
      }
      return;
    }
    case "else": {
      // Fall-through after the then-branch: jump to the matching `end`.
      f.ip = f.jumps.endOfElse.get(f.ip)!;
      return;
    }
    case "end":
      f.labels.pop();
      f.ip++;
      return;
    case "br":
      branchTo(f, op.depth);
      return;
    case "br_if": {
      if (asBool(f.stack.pop()!)) branchTo(f, op.depth);
      else f.ip++;
      return;
    }
    case "return":
      return f.fn.signature.result === "void"
        ? VOID
        : (f.stack.length === 0 ? zeroFor(f.fn.signature.result) : f.stack[f.stack.length - 1]!);
    case "unreachable":
      throw new VmError("vm: reached unreachable", debugOf(f.fn, f.ip));

    case "call": {
      const callee = ctx.module.functions[op.fnIndex];
      if (callee === undefined) throw new VmError(`vm: bad fn index ${op.fnIndex}`, debugOf(f.fn, f.ip));
      const args = popArgs(f, callee.signature.params.length);
      const result = invoke(ctx, op.fnIndex, args, opts);
      if (callee.signature.result !== "void") f.stack.push(result);
      f.ip++; return;
    }
    case "call.import": {
      const imp = ctx.module.imports[op.importIndex];
      if (imp === undefined) throw new VmError(`vm: bad import index ${op.importIndex}`, debugOf(f.fn, f.ip));
      const hostFn = opts.host.get(imp.mangledName, imp.externName);
      if (hostFn === null) {
        throw new VmError(`vm: unbound host import "${imp.externName}" (${imp.mangledName})`, debugOf(f.fn, f.ip));
      }
      const args = popArgs(f, imp.signature.params.length);
      const result = hostFn(args);
      if (imp.signature.result !== "void") f.stack.push(result);
      f.ip++; return;
    }
    case "intrinsic":
      runIntrinsic(f, op.id);
      f.ip++; return;

    case "struct.new": {
      const t = ctx.module.types[op.typeIndex];
      if (t?.kind !== "struct") throw new VmError(`vm: struct.new on non-struct type ${op.typeIndex}`, debugOf(f.fn, f.ip));
      const fields = popArgs(f, t.fields.length);
      f.stack.push({ tag: "struct", typeIndex: op.typeIndex, fields });
      f.ip++; return;
    }
    case "struct.get": {
      const v = asStruct(f.stack.pop()!);
      f.stack.push(v.fields[op.fieldIndex] ?? VOID);
      f.ip++; return;
    }
    case "struct.set": {
      const value = f.stack.pop()!;
      const v = asStruct(f.stack.pop()!);
      v.fields[op.fieldIndex] = value;
      f.ip++; return;
    }

    case "array.new": {
      const elements = popArgs(f, op.length);
      f.stack.push({ tag: "array", typeIndex: op.typeIndex, elements });
      f.ip++; return;
    }
    case "array.get": {
      const idx = Number(asNum(f.stack.pop()!));
      const v = asArray(f.stack.pop()!);
      const e = v.elements[idx];
      if (e === undefined) throw new VmError(`vm: array index ${idx} out of bounds (len=${v.elements.length})`, debugOf(f.fn, f.ip));
      f.stack.push(e);
      f.ip++; return;
    }
    case "array.set": {
      const value = f.stack.pop()!;
      const idx = Number(asNum(f.stack.pop()!));
      const v = asArray(f.stack.pop()!);
      v.elements[idx] = value;
      f.ip++; return;
    }
    case "array.len": {
      const v = asArray(f.stack.pop()!);
      f.stack.push(num("i32", v.elements.length));
      f.ip++; return;
    }

    case "type_check": {
      const v = f.stack.pop()!;
      f.stack.push(bool(typeMatches(ctx.module, v, op.typeIndex)));
      f.ip++; return;
    }
    case "ref.cast":
      // No-op at runtime; the value's tag already carries the type.
      f.ip++; return;
  }

  // Templated kinds: arith / bitwise / compare / unary numeric / convert.
  applyParsedOp(f, op.kind);
  f.ip++;
  return;
}

// ----------------------------------------------------------- typed numeric ops

type ArithVerb = "add" | "sub" | "mul" | "div" | "rem"
               | "bitand" | "bitor" | "bitxor" | "shl" | "shr"
               | "eq" | "ne" | "lt" | "le" | "gt" | "ge"
               | "neg" | "bitnot";

function applyParsedOp(f: Frame, kind: string): void {
  // Op kinds are `<type>.<verb>` or `<type>.to_<type>` — both are split on a
  // single `.`. This avoids per-op regex on the dispatch hot path.
  const dot = kind.indexOf(".");
  if (dot < 0) throw new VmError(`vm: malformed op kind ${kind}`, debugOf(f.fn, f.ip));
  const t = kind.slice(0, dot) as ValType;
  const verb = kind.slice(dot + 1);
  if (verb.startsWith("to_")) {
    convert(f, t, verb.slice(3) as ValType);
    return;
  }
  applyTyped(f, t, verb as ArithVerb);
}

function isBigTag(t: ValType): t is "i64" | "u64" {
  return t === "i64" || t === "u64";
}

function applyTyped(f: Frame, t: ValType, verb: ArithVerb): void {
  if (verb === "neg") {
    const v = f.stack.pop()!;
    if (isBigTag(t)) f.stack.push(i64(t, -asBig(v)));
    else f.stack.push(num(t as NumTag, -asNum(v)));
    return;
  }
  if (verb === "bitnot") {
    const v = f.stack.pop()!;
    if (isBigTag(t)) f.stack.push(i64(t, ~asBig(v)));
    else f.stack.push(num(t as NumTag, (~Math.trunc(asNum(v))) | 0));
    return;
  }

  const rb = f.stack.pop()!;
  const lb = f.stack.pop()!;

  if (isBigTag(t)) {
    const l = asBig(lb), r = asBig(rb);
    switch (verb) {
      case "add": f.stack.push(i64(t, l + r)); return;
      case "sub": f.stack.push(i64(t, l - r)); return;
      case "mul": f.stack.push(i64(t, l * r)); return;
      case "div": if (r === 0n) throw new VmError("vm: division by zero"); f.stack.push(i64(t, l / r)); return;
      case "rem": if (r === 0n) throw new VmError("vm: modulo by zero");   f.stack.push(i64(t, l % r)); return;
      case "bitand": f.stack.push(i64(t, l & r)); return;
      case "bitor":  f.stack.push(i64(t, l | r)); return;
      case "bitxor": f.stack.push(i64(t, l ^ r)); return;
      case "shl":    f.stack.push(i64(t, l << r)); return;
      case "shr":    f.stack.push(i64(t, l >> r)); return;
      case "eq": f.stack.push(bool(l === r)); return;
      case "ne": f.stack.push(bool(l !== r)); return;
      case "lt": f.stack.push(bool(l <  r)); return;
      case "le": f.stack.push(bool(l <= r)); return;
      case "gt": f.stack.push(bool(l >  r)); return;
      case "ge": f.stack.push(bool(l >= r)); return;
    }
    throw new VmError(`vm: unhandled bigint op ${t}.${verb}`);
  }

  const tag = t as NumTag;
  const isFloat = isFloatVal(t);
  const l = asNum(lb), r = asNum(rb);
  switch (verb) {
    case "add": f.stack.push(num(tag, l + r)); return;
    case "sub": f.stack.push(num(tag, l - r)); return;
    case "mul": f.stack.push(num(tag, l * r)); return;
    case "div": {
      if (!isFloat && r === 0) throw new VmError("vm: division by zero");
      f.stack.push(num(tag, isFloat ? l / r : Math.trunc(l / r)));
      return;
    }
    case "rem": {
      if (!isFloat && r === 0) throw new VmError("vm: modulo by zero");
      const m = isFloat ? l % r : (Math.trunc(l) - Math.trunc(l / r) * Math.trunc(r));
      f.stack.push(num(tag, m));
      return;
    }
    case "bitand": f.stack.push(num(tag, (l & r) | 0)); return;
    case "bitor":  f.stack.push(num(tag, (l | r) | 0)); return;
    case "bitxor": f.stack.push(num(tag, (l ^ r) | 0)); return;
    case "shl":    f.stack.push(num(tag, (l << r) | 0)); return;
    case "shr":    f.stack.push(num(tag, (l >> r) | 0)); return;
    case "eq": f.stack.push(bool(l === r)); return;
    case "ne": f.stack.push(bool(l !== r)); return;
    case "lt": f.stack.push(bool(l <  r)); return;
    case "le": f.stack.push(bool(l <= r)); return;
    case "gt": f.stack.push(bool(l >  r)); return;
    case "ge": f.stack.push(bool(l >= r)); return;
  }
  throw new VmError(`vm: unhandled numeric op ${t}.${verb}`);
}

function convert(f: Frame, from: ValType, to: ValType): void {
  const v = f.stack.pop()!;
  if (from === to) { f.stack.push(v); return; }
  const fromBig = isBigTag(from);
  const toBig = isBigTag(to);
  if (fromBig && toBig)        f.stack.push(i64(to, asBig(v)));
  else if (fromBig && !toBig)  f.stack.push(num(to as NumTag, Number(asBig(v))));
  else if (!fromBig && toBig)  f.stack.push(i64(to, BigInt(Math.trunc(asNum(v)))));
  else                          f.stack.push(num(to as NumTag, asNum(v)));
}

// ----------------------------------------------------------- helpers

function pushBinop<T>(f: Frame, unwrap: (v: Value) => T, op: (l: T, r: T) => boolean): void {
  const r = unwrap(f.stack.pop()!);
  const l = unwrap(f.stack.pop()!);
  f.stack.push(bool(op(l, r)));
  f.ip++;
}

function branchTo(f: Frame, depth: number): void {
  const targetIdx = f.labels.length - 1 - depth;
  if (targetIdx < 0) throw new VmError(`vm: br depth ${depth} exceeds label stack`);
  const target = f.labels[targetIdx]!;

  if (target.kind === "loop") {
    f.labels.length = targetIdx + 1;
    f.stack.length = target.stackBase;
    f.ip = target.openIp + 1;
    return;
  }

  const yielded = target.yieldsValue && f.stack.length > target.stackBase
    ? f.stack[f.stack.length - 1]!
    : null;
  f.labels.length = targetIdx;
  f.stack.length = target.stackBase;
  if (yielded !== null) f.stack.push(yielded);
  f.ip = target.endIp + 1;
}

const EMPTY_ARGS: readonly Value[] = Object.freeze([]);

function popArgs(f: Frame, n: number): Value[] {
  if (n === 0) return EMPTY_ARGS as Value[];
  const base = f.stack.length - n;
  const out = f.stack.slice(base);
  f.stack.length = base;
  return out;
}

function refEq(a: Value, b: Value): boolean {
  if (a.tag === "struct" || a.tag === "array" || a.tag === "builder") return a === b;
  if (b.tag === "struct" || b.tag === "array" || b.tag === "builder") return false;
  if (a.tag !== b.tag) return false;
  if (a.tag === "null" || a.tag === "void") return true;
  if (a.tag === "i64" || a.tag === "u64") return a.n === (b as { n: bigint }).n;
  if (a.tag === "error") return a.message === (b as { message: string }).message;
  return a.n === (b as { n: typeof a.n }).n;
}

function typeMatches(m: BytecodeModule, v: Value, typeIndex: number): boolean {
  const t = m.types[typeIndex];
  if (t === undefined) return false;
  return matchTo(m, v, t, typeIndex);
}

function matchTo(m: BytecodeModule, v: Value, t: BcType, idx: number): boolean {
  switch (t.kind) {
    case "primitive":
      return v.tag === t.val;
    case "struct":
      return v.tag === "struct" && v.typeIndex === idx;
    case "array":
      return v.tag === "array" && v.typeIndex === idx;
    case "union":
      for (const variant of t.variants) {
        if (typeMatches(m, v, variant)) return true;
      }
      return false;
    case "ref":
      // TODO(impl-table): user structs implementing a trait should match here
      // via the impl-table. Today only host-produced `error` sentinels and a
      // mangled-name heuristic resolve against `Error` / unnamed refs.
      if (v.tag === "error") return t.traitName === "Error" || t.traitName === null;
      if (t.traitName === null) return v.tag === "struct" || v.tag === "array";
      if (v.tag === "struct") {
        const stype = m.types[v.typeIndex];
        if (stype?.kind === "struct") return stype.name.includes(`$${t.traitName}$`);
      }
      return false;
  }
}

function zeroFor(val: string): Value {
  switch (val) {
    case "i8": case "i16": case "i32":
    case "u8": case "u16": case "u32":
    case "f32": case "f64": case "char":
      return num(val as NumTag, 0);
    case "i64": case "u64": return i64(val as "i64" | "u64", 0n);
    case "bool":   return FALSE;
    case "string": return makeStr("");
    case "void":   return VOID;
    default:       return NULL;
  }
}

function debugOf(fn: BcFunction, ip: number): string {
  const dbg = fn.debug[ip];
  if (dbg === undefined || dbg === null) return `${fn.name}+${ip}`;
  return `${fn.name}+${ip} @ ${dbg.file}:${dbg.line}:${dbg.column}`;
}

function getJumps(fn: BcFunction): JumpInfo {
  const cached = JUMP_CACHE.get(fn);
  if (cached !== undefined) return cached;
  const fresh = precomputeJumps(fn);
  JUMP_CACHE.set(fn, fresh);
  return fresh;
}

function precomputeJumps(fn: BcFunction): JumpInfo {
  const endOf = new Map<number, number>();
  const elseOf = new Map<number, number>();
  const endOfElse = new Map<number, number>();
  type Open = { openIp: number; kind: "block" | "loop" | "if"; elseIp: number };
  const stack: Open[] = [];

  for (let i = 0; i < fn.body.length; i++) {
    const op = fn.body[i]!;
    switch (op.kind) {
      case "block": stack.push({ openIp: i, kind: "block", elseIp: -1 }); break;
      case "loop":  stack.push({ openIp: i, kind: "loop",  elseIp: -1 }); break;
      case "if":    stack.push({ openIp: i, kind: "if",    elseIp: -1 }); break;
      case "else": {
        const top = stack[stack.length - 1];
        if (top === undefined || top.kind !== "if") {
          throw new VmError(`vm: stray else at op ${i} in ${fn.name}`);
        }
        top.elseIp = i;
        elseOf.set(top.openIp, i);
        break;
      }
      case "end": {
        const top = stack.pop();
        if (top === undefined) throw new VmError(`vm: stray end at op ${i} in ${fn.name}`);
        endOf.set(top.openIp, i);
        if (top.elseIp >= 0) endOfElse.set(top.elseIp, i);
        break;
      }
      default: break;
    }
  }
  return { endOf, elseOf, endOfElse };
}

// ----------------------------------------------------------- intrinsics

function runIntrinsic(f: Frame, id: number): void {
  switch (id) {
    case INTRINSIC_TABLE.builderNew.id:
      f.stack.push(builder());
      return;
    case INTRINSIC_TABLE.builderAppendStr.id: {
      const s = asString(f.stack.pop()!);
      asBuilder(f.stack.pop()!).parts.push(s);
      return;
    }
    case INTRINSIC_TABLE.builderAppendDisplay.id: {
      const v = f.stack.pop()!;
      asBuilder(f.stack.pop()!).parts.push(displayValue(v));
      return;
    }
    case INTRINSIC_TABLE.builderFinish.id: {
      f.stack.push(makeStr(asBuilder(f.stack.pop()!).parts.join("")));
      return;
    }
    default:
      throw new VmError(`vm: intrinsic id ${id} not implemented`, debugOf(f.fn, f.ip));
  }
}
