// Bytecode VM — executes a `BytecodeModule` produced by §1.7's emitter.
// Stack-based with WASM-style structured control flow. The VM trusts the
// bytecode to be type-correct (the type-checker has already validated it);
// type-assertion accessors trip only on an emitter bug.

import type { BytecodeModule, BcFunction } from "../bytecode/module.ts";
import type { ConstOp, Op } from "../bytecode/ops.ts";
import { INTRINSIC_TABLE } from "../bytecode/ops.ts";
import { isFloatVal, sizeOfBcType } from "../bytecode/types.ts";
import type { BcDataEntry, BcType, ValType } from "../bytecode/types.ts";

import type { HostBindings } from "./host.ts";
import {
  bool, builder, ch, FALSE, fnRef, i64, NULL, num, str as makeStr, VOID,
  asArray, asBig, asBool, asBuilder, asChar, asFn, asIndex, asNum, asString, asStruct, asType, displayValue,
} from "./value.ts";
import type { ArrayValue, NumTag, StringValue, Value } from "./value.ts";

export interface RunOptions {
  readonly host: HostBindings;
  /** Override the entry-point fn name (mangled). Defaults to any fn whose
   *  name ends in `$main`. */
  readonly entry?: string;
  /** Stop after this many ops to guard tests against runaway loops. */
  readonly opLimit?: number;
  /** Process argv to pass to `main(args: [string])`. Empty when main takes
   *  no arguments or when the host doesn't supply them. */
  readonly argv?: readonly string[];
}

export interface RunResult {
  readonly exitCode: number;
}

export class VmError extends Error {
  readonly rawMessage: string;
  constructor(message: string, readonly debug?: string) {
    super(debug !== undefined ? `${message} (at ${debug})` : message);
    this.rawMessage = message;
  }
}

export function runProgram(m: BytecodeModule, opts: RunOptions): RunResult {
  const fnIndex = findEntry(m, opts.entry);
  const fn = m.functions[fnIndex]!;
  const args: Value[] = fn.signature.params.length === 1
    ? [{ tag: "array", typeIndex: 0, elements: (opts.argv ?? []).map((s) => makeStr(s)) }]
    : [];
  const result = runFn(m, opts.entry, args, opts);
  if (result.tag === "void") return { exitCode: 0 };
  return { exitCode: Math.trunc(asNum(result)) | 0 };
}

/** Run an arbitrary fn by name (or the auto-detected main) and return its raw
 *  Value — the comptime path uses this to capture the result without going
 *  through the exit-code coercion. */
export function runFn(
  m: BytecodeModule, entry: string | undefined, args: Value[], opts: RunOptions,
): Value {
  const ctx = newRunCtx(m);
  const fnIndex = findEntry(m, entry);
  return invoke(ctx, fnIndex, args, opts);
}

export function findEntry(m: BytecodeModule, override?: string): number {
  if (override !== undefined) {
    const idx = m.functions.findIndex((f) => f.name === override);
    if (idx < 0) throw new VmError(`vm: entry function "${override}" not found`);
    return idx;
  }
  const idx = m.functions.findIndex((f) => f.isMain && f.body.length > 0);
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
  /** Pre-materialised elements per `dataPool` entry — one shared `Value[]`
   *  per pool index. The `ArrayValue` wrapper itself is cached lazily
   *  on first `data.const` so the call-site `typeIndex` lands on a single
   *  long-lived header (the lowerer pins one type per pool entry, so the
   *  first hit's typeIndex is the only one we'll see). */
  readonly dataPoolElements: readonly Value[][];
  readonly dataPool: ArrayValue[];
}

const JUMP_CACHE = new WeakMap<BcFunction, JumpInfo>();

function newRunCtx(m: BytecodeModule): RunCtx {
  return {
    module: m,
    stringPool: m.strings.map((s) => ({ tag: "string", n: s })),
    dataPoolElements: m.dataPool.map((entry) => materialiseDataEntryElements(entry)),
    dataPool: new Array(m.dataPool.length),
  };
}

function materialiseDataEntryElements(entry: BcDataEntry): Value[] {
  const elements: Value[] = new Array(entry.items.length);
  for (let i = 0; i < entry.items.length; i++) {
    elements[i] = dataItemToValue(entry.kind, entry.items[i]!);
  }
  return elements;
}

function dataItemToValue(kind: BcDataEntry["kind"], v: bigint): Value {
  switch (kind) {
    case "u8":   return num("u8",  Number(BigInt.asUintN(8, v)));
    case "i8":   return num("i8",  Number(BigInt.asIntN(8, v)));
    case "u16":  return num("u16", Number(BigInt.asUintN(16, v)));
    case "i16":  return num("i16", Number(BigInt.asIntN(16, v)));
    case "u32":  return num("u32", Number(BigInt.asUintN(32, v)));
    case "i32":  return num("i32", Number(BigInt.asIntN(32, v)));
    case "u64":  return i64("u64", BigInt.asUintN(64, v));
    case "i64":  return i64("i64", BigInt.asIntN(64, v));
    case "f32": {
      FLOAT_DV.setUint32(0, Number(BigInt.asUintN(32, v)), true);
      return num("f32", FLOAT_DV.getFloat32(0, true));
    }
    case "f64": {
      FLOAT_DV.setBigUint64(0, BigInt.asUintN(64, v), true);
      return num("f64", FLOAT_DV.getFloat64(0, true));
    }
    case "char": return ch(Number(BigInt.asUintN(32, v)));
    case "bool": return bool(v !== 0n);
    case "boxed":
      throw new Error("vm: data pool kind 'boxed' not allowed");
  }
}

const FLOAT_BUF = new ArrayBuffer(8);
const FLOAT_DV = new DataView(FLOAT_BUF);

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
      const r = stepWithDebug(ctx, frame, opts);
      if (r !== undefined) return r;
    }
  } else {
    while (frame.ip < fn.body.length) {
      const r = stepWithDebug(ctx, frame, opts);
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
    case "data.const": {
      let arr = ctx.dataPool[op.poolIndex];
      if (arr === undefined) {
        const elements = ctx.dataPoolElements[op.poolIndex];
        if (elements === undefined) throw new VmError(`vm: bad data pool index ${op.poolIndex}`, debugOf(f.fn, f.ip));
        arr = { tag: "array", typeIndex: op.typeIndex, elements };
        ctx.dataPool[op.poolIndex] = arr;
      }
      f.stack.push(arr);
      f.ip++; return;
    }

    case "bool.and": pushBinop(f, asBool, (l, r) => l && r); return;
    case "bool.or":  pushBinop(f, asBool, (l, r) => l || r); return;
    case "bool.not": { const v = asBool(f.stack.pop()!); f.stack.push(bool(!v)); f.ip++; return; }

    case "ref.eq":     f.stack.push(bool(refEq(f.stack.pop()!, f.stack.pop()!))); f.ip++; return;
    case "ref.ne":     f.stack.push(bool(!refEq(f.stack.pop()!, f.stack.pop()!))); f.ip++; return;
    case "string.concat": {
      const r = asString(f.stack.pop()!);
      const l = asString(f.stack.pop()!);
      f.stack.push(makeStr(l + r));
      f.ip++; return;
    }
    case "string.eq":  pushBinop(f, asString, (l, r) => l === r); return;
    case "string.ne":  pushBinop(f, asString, (l, r) => l !== r); return;
    case "char.eq":    pushBinop(f, asChar, (l, r) => l === r); return;
    case "char.ne":    pushBinop(f, asChar, (l, r) => l !== r); return;
    case "char.lt":    pushBinop(f, asChar, (l, r) => l <  r); return;
    case "char.le":    pushBinop(f, asChar, (l, r) => l <= r); return;
    case "char.gt":    pushBinop(f, asChar, (l, r) => l >  r); return;
    case "char.ge":    pushBinop(f, asChar, (l, r) => l >= r); return;
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
    case "return.lit": {
      pushConstLit(f, ctx, op.value);
      return f.fn.signature.result === "void"
        ? VOID : f.stack[f.stack.length - 1]!;
    }
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
      const result = hostFn(args, ctx.module);
      if (imp.signature.result !== "void") f.stack.push(result);
      f.ip++; return;
    }
    case "fn.ref": {
      f.stack.push(fnRef(op.fnIndex));
      f.ip++; return;
    }
    case "make_closure": {
      // Pop the env value (typically a struct), pack with the lifted fn into
      // a closure value. The VM's `invoke` will pass `env` as the lifted
      // fn's first arg when call.indirect fires.
      const env = f.stack.pop()!;
      f.stack.push(fnRef(op.fnIndex, env));
      f.ip++; return;
    }
    case "call.indirect": {
      const fnVal = asFn(f.stack.pop()!);
      const callee = ctx.module.functions[fnVal.fnIndex];
      if (callee === undefined) throw new VmError(`vm: bad fn index ${fnVal.fnIndex}`, debugOf(f.fn, f.ip));
      // Closures with env get env prepended as the first arg (matching the
      // lifted fn's bytecode signature `(ref, ...originalParams) → ret`).
      // Plain fn refs (env === null) leave args unchanged — the global fn's
      // signature has no env slot.
      const explicitArgCount = fnVal.env === null
        ? callee.signature.params.length
        : callee.signature.params.length - 1;
      const explicitArgs = popArgs(f, explicitArgCount);
      const args = fnVal.env === null ? explicitArgs : [fnVal.env, ...explicitArgs];
      const result = invoke(ctx, fnVal.fnIndex, args, opts);
      if (callee.signature.result !== "void") f.stack.push(result);
      f.ip++; return;
    }
    case "virtual.call": {
      // Receiver is on top of the stack; pop it, read its type tag, and look
      // up the impl fn in the per-(trait, method) vtable. Then call as a
      // regular fn with [receiver, ...args].
      const receiver = f.stack.pop()!;
      const tag = receiverTypeIndex(receiver, ctx.module);
      const table = ctx.module.vtables.get(op.vtableKey);
      if (table === undefined) {
        throw new VmError(`vm: no vtable for ${op.vtableKey}`, debugOf(f.fn, f.ip));
      }
      const fnIdx = tag !== null ? table.get(tag) : undefined;
      if (fnIdx === undefined) {
        throw new VmError(
          `vm: no impl in ${op.vtableKey} vtable for receiver tag ${tag}`,
          debugOf(f.fn, f.ip),
        );
      }
      const callee = ctx.module.functions[fnIdx];
      if (callee === undefined) {
        throw new VmError(`vm: bad fn index ${fnIdx} in vtable`, debugOf(f.fn, f.ip));
      }
      const explicitArgs = popArgs(f, op.paramCount - 1);
      const result = invoke(ctx, fnIdx, [receiver, ...explicitArgs], opts);
      if (callee.signature.result !== "void") f.stack.push(result);
      f.ip++; return;
    }
    case "intrinsic":
      runIntrinsic(f, op.id, ctx.module);
      f.ip++; return;

    case "struct.new":
    case "struct.new_stack": {
      const t = ctx.module.types[op.typeIndex];
      if (t?.kind !== "struct") throw new VmError(`vm: ${op.kind} on non-struct type ${op.typeIndex}`, debugOf(f.fn, f.ip));
      const fields = popArgs(f, t.fields.length);
      f.stack.push({ tag: "struct", typeIndex: op.typeIndex, fields });
      f.ip++; return;
    }
    case "struct.get": {
      const v = asStruct(f.stack.pop()!);
      f.stack.push(v.fields[op.fieldIndex] ?? VOID);
      f.ip++; return;
    }
    case "struct.set":
    case "struct.set_stack": {
      // The VM has no write barrier — both ops have identical runtime
      // semantics; only the native C-emit differentiates them.
      const value = f.stack.pop()!;
      const v = asStruct(f.stack.pop()!);
      v.fields[op.fieldIndex] = value;
      f.ip++; return;
    }

    case "array.new": {
      // empty literal must be a fresh array (not the frozen EMPTY_ARGS sentinel) so push works
      const elements: Value[] = op.length === 0 ? [] : popArgs(f, op.length);
      f.stack.push({ tag: "array", typeIndex: op.typeIndex, elements });
      f.ip++; return;
    }
    case "array.get": {
      const idx = asIndex(f.stack.pop()!);
      const v = asArray(f.stack.pop()!);
      const e = v.elements[idx];
      if (e === undefined) throw new VmError(`vm: array index ${idx} out of bounds (len=${v.elements.length})`, debugOf(f.fn, f.ip));
      f.stack.push(e);
      f.ip++; return;
    }
    case "array.set": {
      const value = f.stack.pop()!;
      const idx = asIndex(f.stack.pop()!);
      const v = asArray(f.stack.pop()!);
      v.elements[idx] = value;
      f.ip++; return;
    }
    case "array.len": {
      const v = asArray(f.stack.pop()!);
      f.stack.push(i64("usize", BigInt(v.elements.length)));
      f.ip++; return;
    }
    case "array.push": {
      const value = f.stack.pop()!;
      const v = asArray(f.stack.pop()!);
      v.elements.push(value);
      f.ip++; return;
    }
    case "array.slice": {
      // The VM stores elements as a plain `Value[]` ; `slice` copies the
      // requested range. Shared-buf semantics matter only for the native
      // target's GC heap ; the VM observes the same outward behaviour
      // since arrays are mutated through `array.set` only, not via
      // alias-write-through.
      const hi = asIndex(f.stack.pop()!);
      const lo = asIndex(f.stack.pop()!);
      const v = asArray(f.stack.pop()!);
      let lo2 = lo, hi2 = hi;
      if (lo2 > v.elements.length) lo2 = v.elements.length;
      if (hi2 < lo2)                hi2 = lo2;
      if (hi2 > v.elements.length) hi2 = v.elements.length;
      f.stack.push({ tag: "array", typeIndex: op.typeIndex, elements: v.elements.slice(lo2, hi2) });
      f.ip++; return;
    }

    case "type_check": {
      const v = f.stack.pop()!;
      f.stack.push(bool(typeMatches(ctx.module, v, op.typeIndex)));
      f.ip++; return;
    }
    case "type.const": {
      f.stack.push({ tag: "type", typeIndex: op.typeIndex });
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

/** Mirrors the const-op cases in `step()` so `return.lit` can replay the
 *  fused literal without going through dispatch. Kept duplicated rather
 *  than factored so neither call site goes through an extra fn call. */
function pushConstLit(f: Frame, ctx: RunCtx, op: ConstOp): void {
  switch (op.kind) {
    case "i32.const":    f.stack.push(num("i32", op.value)); return;
    case "i64.const":    f.stack.push(i64("i64", op.value)); return;
    case "f32.const":    f.stack.push(num("f32", op.value)); return;
    case "f64.const":    f.stack.push(num("f64", op.value)); return;
    case "bool.const":   f.stack.push(bool(op.value));       return;
    case "char.const":   f.stack.push(ch(op.value));         return;
    case "null.const":   f.stack.push(NULL);                 return;
    case "string.const": {
      const s = ctx.stringPool[op.index];
      if (s === undefined) throw new VmError(`vm: bad string index ${op.index}`, debugOf(f.fn, f.ip));
      f.stack.push(s);
      return;
    }
  }
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

function isBigTag(t: ValType): t is "i64" | "u64" | "usize" | "isize" {
  return t === "i64" || t === "u64" || t === "usize" || t === "isize";
}

/** Coerce a JS number to the host-tag's integer range. u32 needs Uint32
 *  coercion (`>>> 0`) to preserve the high bit; everything else fits the
 *  Int32 path (`| 0`). u8/u16 values never set bit 31 so the same path is
 *  correct for them too. */
function intCoerce(t: ValType, n: number): number {
  return t === "u32" ? n >>> 0 : n | 0;
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
    else f.stack.push(num(t as NumTag, intCoerce(t, ~Math.trunc(asNum(v)))));
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
    // u32: `>>` would sign-extend and `| 0` would Int32-coerce — both flip
    // the high bit. `intCoerce` picks `>>> 0` for u32 and `| 0` otherwise;
    // `shr` also picks `>>>` over `>>` for u32 to zero-fill.
    case "bitand": f.stack.push(num(tag, intCoerce(t, l & r))); return;
    case "bitor":  f.stack.push(num(tag, intCoerce(t, l | r))); return;
    case "bitxor": f.stack.push(num(tag, intCoerce(t, l ^ r))); return;
    case "shl":    f.stack.push(num(tag, intCoerce(t, l << r))); return;
    case "shr":    f.stack.push(num(tag, t === "u32" ? l >>> r : (l >> r) | 0)); return;
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
  // Char and integers share the wire format (32-bit unsigned). Extract a raw
  // numeric (or bigint) value irrespective of the source tag.
  const numVal = from === "char"
    ? asChar(v)
    : isBigTag(from) ? null : asNum(v);
  const bigVal = isBigTag(from) ? asBig(v) : null;
  if (to === "char") {
    f.stack.push(ch(numVal !== null ? numVal : Number(bigVal!)));
    return;
  }
  if (isBigTag(to)) {
    f.stack.push(i64(to, bigVal !== null ? bigVal : BigInt(Math.trunc(numVal!))));
    return;
  }
  f.stack.push(num(to as NumTag, numVal !== null ? numVal : Number(bigVal!)));
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
  if (a.tag === "struct" || a.tag === "array" || a.tag === "builder" || a.tag === "fn") return a === b;
  if (b.tag === "struct" || b.tag === "array" || b.tag === "builder" || b.tag === "fn") return false;
  if (a.tag !== b.tag) return false;
  if (a.tag === "null" || a.tag === "void") return true;
  if (a.tag === "i64" || a.tag === "u64") return a.n === (b as { n: bigint }).n;
  if (a.tag === "error") return a.message === (b as { message: string }).message;
  if (a.tag === "type") return a.typeIndex === (b as { typeIndex: number }).typeIndex;
  return a.n === (b as { n: typeof a.n }).n;
}

/** Extract the type-table index of a runtime value's static type — keys
 *  vtable lookups for virtual dispatch. Structs / arrays carry their type
 *  index inline. For primitives (and string), scan the module's type table
 *  for a matching `BcPrimitive`. Returns null when no entry matches. */
function receiverTypeIndex(v: Value, m: BytecodeModule): number | null {
  if (v.tag === "struct" || v.tag === "array") return v.typeIndex;
  for (let i = 0; i < m.types.length; i++) {
    const t = m.types[i]!;
    if (t.kind === "primitive" && t.val === v.tag) return i;
  }
  return null;
}

/** Lazy per-module map : concrete struct typeIndex → sibling layouts
 *  (same `symbolId` for user generic structs, same arity for
 *  anonymous tuples). Computed on first `matchTo` against a struct
 *  ; cached to amortise the O(types) scan. Mirrors c_emit's
 *  `computeSiblingLayoutsOf` so VM and native agree on which runtime
 *  shapes satisfy a static struct match. */
const STRUCT_SIBLINGS_CACHE = new WeakMap<BytecodeModule, ReadonlyMap<number, ReadonlySet<number>>>();
function structSiblingsOf(m: BytecodeModule, idx: number): ReadonlySet<number> | null {
  let cache = STRUCT_SIBLINGS_CACHE.get(m);
  if (cache === undefined) {
    const groups = new Map<string | number, number[]>();
    for (let i = 0; i < m.types.length; i++) {
      const t = m.types[i]!;
      if (t.kind !== "struct") continue;
      const key = t.symbolId ?? (t.name.startsWith("__Tuple_") ? `tuple:${t.fields.length}` : undefined);
      if (key === undefined) continue;
      const list = groups.get(key);
      if (list !== undefined) list.push(i);
      else groups.set(key, [i]);
    }
    const built = new Map<number, ReadonlySet<number>>();
    for (const indices of groups.values()) {
      if (indices.length < 2) continue;
      for (const i of indices) {
        built.set(i, new Set(indices.filter((j) => j !== i)));
      }
    }
    cache = built;
    STRUCT_SIBLINGS_CACHE.set(m, cache);
  }
  return cache.get(idx) ?? null;
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
      if (v.tag !== "struct") return false;
      if (v.typeIndex === idx) return true;
      // Erasure-aware sibling check : post-path-γ a value may carry a
      // sibling shape's tag (e.g. `Yield(Any)` runtime flowing into a
      // match arm typed `is Yield(i32)`). Accept any sibling in the
      // same symbolId / tuple-arity group. C-emit does the analogous
      // disjunction inside `emitTypeCheck` for native runs.
      return structSiblingsOf(m, idx)?.has(v.typeIndex) ?? false;
    case "array":
      return v.tag === "array" && v.typeIndex === idx;
    case "union":
      for (const variant of t.variants) {
        if (typeMatches(m, v, variant)) return true;
      }
      return false;
    case "ref":
      if (v.tag === "error") return t.traitName === "Error" || t.traitName === null;
      if (t.traitName === null) return v.tag === "struct" || v.tag === "array";
      if (v.tag === "struct") {
        // Check the impl table first: populated from `T implements Trait { … }`
        // declarations at compile time, covers both non-generic and monomorphised structs.
        const implTraits = m.implTable.get(v.typeIndex);
        if (implTraits !== undefined && implTraits.includes(t.traitName)) return true;
        // Fallback: mangled-name heuristic for legacy / host-produced structs.
        const stype = m.types[v.typeIndex];
        if (stype?.kind === "struct") return stype.name.includes(`$${t.traitName}$`);
      }
      return false;
    case "fn":
      // Signatures are validated by the type-checker pre-emit; runtime check
      // just confirms the value is a fn ref.
      return v.tag === "fn";
  }
}

function zeroFor(val: string): Value {
  switch (val) {
    case "i8": case "i16": case "i32":
    case "u8": case "u16": case "u32":
    case "f32": case "f64": case "char":
      return num(val as NumTag, 0);
    case "i64": case "u64": case "usize": case "isize":
      return i64(val as "i64" | "u64" | "usize" | "isize", 0n);
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

/** Attach the current frame's debug info to any trap that doesn't already
 *  carry one. Without this, plain `Error("vm: expected char, got i32")`
 *  thrown deep in `value.ts` (or a `VmError` thrown without a debug arg,
 *  like the div-by-zero in `binaryOp`) reaches the CLI without a source
 *  location. */
function stepWithDebug(
  ctx: RunCtx, frame: Frame, opts: RunOptions,
): Value | undefined {
  const ip = frame.ip;
  try {
    return step(ctx, frame, frame.fn.body[ip]!, opts);
  } catch (e) {
    if (e instanceof VmError) {
      if (e.debug !== undefined) throw e;
      throw new VmError(e.rawMessage, debugOf(frame.fn, ip));
    }
    const msg = e instanceof Error ? e.message : String(e);
    throw new VmError(msg, debugOf(frame.fn, ip));
  }
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

function runIntrinsic(f: Frame, id: number, module: BytecodeModule): void {
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
    case INTRINSIC_TABLE.sizeOfType.id: {
      const tv = asType(f.stack.pop()!);
      const bt = module.types[tv.typeIndex];
      const size = bt !== undefined ? sizeOfBcType(bt) : 0;
      f.stack.push({ tag: "usize", n: BigInt(size) });
      return;
    }
    default:
      throw new VmError(`vm: intrinsic id ${id} not implemented`, debugOf(f.fn, f.ip));
  }
}
