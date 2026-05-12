// C emit — per-op data emitters, dispatched from `body.ts`'s `emitOp`.
//
// Each `Op` kind that produces a C statement / expression has its emit
// function here : direct/imported/virtual/indirect calls + closure
// allocation, struct read/write/new, array read/write/new, type-check /
// ref-cast, numeric binops + integer conversion, intrinsic dispatch.
// Vtable forward declarations and per-(trait,method) dispatcher fns also
// live here since they're the C-side counterpart of `virtual.call`.
//
// All these emitters take an `FnState` (defined in `body.ts`) and use the
// value-stack helpers (`newTmp`, `pop`, `peek`, `pushBinop`, …) and the
// C-name helpers (`cTypeFor*`, `sanitise`, …) re-exported there.

import type { BcSignature } from "../bytecode/module.ts";
import type { Op } from "../bytecode/ops.ts";
import { INTRINSIC_TABLE } from "../bytecode/ops.ts";
import type { ValType } from "../bytecode/types.ts";

import type { EmitCtx } from "./emit.ts";
import { cStringLit, cStringLitFromBytes, escapeC, sanitise } from "./emit.ts";
import {
  boxExpr, boxExprUnknown, coerce, coerceExpr, cTypeFor, cTypeForVal,
  cTypeForValBare, decl, isRefVal, line, nameOf, newTmp, peek, pop,
  primitiveMatchesType, pushBinop, pushBinopAny, pushFnCall2, pushLit,
  pushLocalRef, pushUnop, signatureFor, unboxExpr, valTypeOfBcType,
  valTypeOfField, zeroInit,
  type FnState,
} from "./body.ts";

export function emitCall(s: FnState, op: Extract<Op, { kind: "call" }>): void {
  const callee = s.ctx.module.functions[op.fnIndex]!;
  const args: string[] = [];
  for (let i = callee.signature.params.length - 1; i >= 0; i--) {
    const v = pop(s);
    args.unshift(coerce(s, v.name, v.val, callee.signature.params[i]!));
  }
  if (callee.signature.result === "void") {
    line(s, `${s.ctx.fnNames[op.fnIndex]!}(${args.join(", ")});`);
  } else {
    const t = newTmp(s, callee.signature.result);
    line(s, `${decl(s, callee.signature.result, t)} = ${s.ctx.fnNames[op.fnIndex]!}(${args.join(", ")});`);
  }
}

export function emitCallImport(s: FnState, op: Extract<Op, { kind: "call.import" }>): void {
  const imp = s.ctx.module.imports[op.importIndex]!;
  const args: string[] = [];
  for (let i = imp.signature.params.length - 1; i >= 0; i--) {
    const v = pop(s);
    args.unshift(coerce(s, v.name, v.val, imp.signature.params[i]!));
  }
  const callee = `vader_import_${op.importIndex}`;
  if (imp.signature.result === "void") {
    line(s, `${callee}(${args.join(", ")});`);
  } else {
    const t = newTmp(s, imp.signature.result);
    line(s, `${decl(s, imp.signature.result, t)} = ${callee}(${args.join(", ")});`);
  }
}

export function emitFnRef(s: FnState, op: Extract<Op, { kind: "fn.ref" }>): void {
  const tmp = newTmp(s, "ref");
  line(s, `${decl(s, "ref", tmp)} = vader_box_obj(${op.typeIndex}u, &vader_fn_static_${op.fnIndex});`);
}

export function emitVirtualCall(s: FnState, op: Extract<Op, { kind: "virtual.call" }>): void {
  // Stack at entry: …args, receiver. Pop receiver first, then args (reverse
  // order); the dispatch helper takes (receiver, ...args) in source order.
  // Tail args are boxed to `vader_box_t` before the call so impls with
  // divergent monomorphised signatures (e.g. `Contains[K=string]` and
  // `Contains[T=i32]`) can share a single dispatcher — each arm unboxes to
  // its concrete impl signature.
  const recv = pop(s);
  const recvBoxed = coerce(s, recv.name, recv.val, "any");
  const tailCount = op.paramCount - 1;
  const args: { name: string; val: ValType }[] = [];
  for (let i = 0; i < tailCount; i++) args.push(pop(s));
  args.reverse();
  const boxedArgs = args.map((a) => coerce(s, a.name, a.val, "any"));

  const helper = vtableHelperName(op.vtableKey);
  const sig = vtableSignatures(s.ctx).get(op.vtableKey);
  if (sig === undefined) {
    line(s, `vader_unreachable("no vtable for ${escapeC(op.vtableKey)}");`);
    return;
  }
  if (sig.result === "void") {
    line(s, `${helper}(${[recvBoxed, ...boxedArgs].join(", ")});`);
    return;
  }
  const tmp = newTmp(s, sig.result);
  line(s, `${decl(s, sig.result, tmp)} = ${helper}(${[recvBoxed, ...boxedArgs].join(", ")});`);
}

export function vtableHelperName(key: string): string {
  return `vader_vt_${sanitise(key.replace(".", "__"))}`;
}

/** Per-vtable canonical signature, derived from the first impl fn in each
 *  table. All impls of a given trait method share their non-receiver param
 *  types (the receiver is taken as `any`/`vader_box_t` in the dispatcher). */
export function vtableSignatures(ctx: EmitCtx): ReadonlyMap<string, BcSignature> {
  const out = new Map<string, BcSignature>();
  for (const [key, table] of ctx.module.vtables) {
    const firstFnIdx = table.values().next().value;
    if (firstFnIdx === undefined) continue;
    const fn = ctx.module.functions[firstFnIdx];
    if (fn === undefined) continue;
    out.set(key, fn.signature);
  }
  return out;
}

/** Forward-declare every vtable dispatcher up front so user fns that call
 *  them compile before the dispatcher bodies are emitted. */
export function emitVtableForwardDecls(ctx: EmitCtx, out: string[]): void {
  if (ctx.module.vtables.size === 0) return;
  out.push(``);
  out.push(`/* ----------------------------------------------- vtable forwards */`);
  for (const [key, table] of ctx.module.vtables) {
    const firstFnIdx = table.values().next().value;
    if (firstFnIdx === undefined) continue;
    const sig = ctx.module.functions[firstFnIdx]!.signature;
    // Tail params are typed `vader_box_t` so the dispatcher can host arms
    // with divergent monomorphised signatures. Each arm unboxes to its
    // concrete impl signature.
    const tailCount = sig.params.length - 1;
    const tailParamDecls = Array.from({ length: tailCount }, (_, i) => `vader_box_t a${i}`).join(", ");
    const formal = tailCount > 0 ? `vader_box_t recv, ${tailParamDecls}` : `vader_box_t recv`;
    out.push(`static ${cTypeForVal(ctx, sig.result)} ${vtableHelperName(key)}(${formal});`);
  }
}

/** Emit one dispatch helper per (trait, method) entry: `static <ret>
 *  vader_vt_<key>(vader_box_t recv, <args>)` whose body switches on
 *  `recv.tag` and forwards to the matching impl fn. The unbox-and-cast
 *  per case mirrors what the cascade used to do inline at every call site,
 *  but consolidated to one fn per vtable key. */
export function emitVtableDispatchers(ctx: EmitCtx, out: string[]): void {
  if (ctx.module.vtables.size === 0) return;
  out.push(``);
  out.push(`/* ----------------------------------------------- vtable dispatchers */`);
  for (const [key, table] of ctx.module.vtables) {
    const firstFnIdx = table.values().next().value;
    if (firstFnIdx === undefined) continue;
    const sig = ctx.module.functions[firstFnIdx]!.signature;
    const helper = vtableHelperName(key);
    const tailCount = sig.params.length - 1;
    const tailParamDecls = Array.from({ length: tailCount }, (_, i) => `vader_box_t a${i}`).join(", ");
    const formal = tailCount > 0 ? `vader_box_t recv, ${tailParamDecls}` : `vader_box_t recv`;
    const cret = cTypeForVal(ctx, sig.result);
    out.push(`static ${cret} ${helper}(${formal}) {`);
    out.push(`    switch (recv.tag) {`);
    for (const [tag, fnIdx] of table) {
      const calleeName = ctx.fnNames[fnIdx]!;
      const calleeSig = ctx.module.functions[fnIdx]!.signature;
      const recvParam = calleeSig.params[0]!;
      const recvCArg = coerceExpr(ctx, "recv", "any", recvParam);
      const tailArgs = calleeSig.params.slice(1).map((target, i) => coerceExpr(ctx, `a${i}`, "any", target));
      const allArgs = [recvCArg, ...tailArgs].join(", ");
      if (sig.result === "void") {
        out.push(`        case ${tag}u: ${calleeName}(${allArgs}); return;`);
      } else {
        out.push(`        case ${tag}u: return ${calleeName}(${allArgs});`);
      }
    }
    out.push(`        default: vader_unreachable("vtable miss in ${escapeC(key)}");`);
    out.push(`    }`);
    if (sig.result !== "void") {
      // Defensive: every path in the switch returns or traps, but C wants a
      // post-switch return for non-void. `vader_unreachable` is noreturn.
      out.push(`    vader_unreachable("vtable miss in ${escapeC(key)}");`);
    }
    out.push(`}`);
  }
}

export function emitMakeClosure(s: FnState, op: Extract<Op, { kind: "make_closure" }>): void {
  // Pop env (a vader_box_t whose payload.obj is the env struct), allocate a
  // fresh vader_fn_t, set code = lifted-fn wrapper + env = the env ptr,
  // and box the result with the closure's BcFn type tag.
  const envBox = pop(s);
  const tmp = newTmp(s, "ref");
  const fnObj = `closure_${s.tmpCounter++}`;
  line(s, `vader_fn_t* ${fnObj} = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));`);
  line(s, `vader_obj_header_init(${fnObj}, ${op.typeIndex}u);`);
  line(s, `${fnObj}->code = (void*) &vader_fn_lift_${op.fnIndex};`);
  line(s, `${fnObj}->env = ${envBox.name}.payload.obj;`);
  line(s, `${decl(s, "ref", tmp)} = vader_box_obj(${op.typeIndex}u, ${fnObj});`);
}

export function emitCallIndirect(s: FnState, op: Extract<Op, { kind: "call.indirect" }>): void {
  const t = s.ctx.module.types[op.typeIndex];
  if (t === undefined || t.kind !== "fn") {
    line(s, `vader_unreachable("call.indirect on non-fn type");`);
    return;
  }
  // Stack order (WASM convention): args... then fn ref on top.
  const fnVal = pop(s);
  const args: string[] = [];
  for (let i = t.params.length - 1; i >= 0; i--) {
    const v = pop(s);
    const expectedVal = valTypeOfBcType(s.ctx.module.types[t.params[i]!]!);
    args.unshift(coerce(s, v.name, v.val, expectedVal));
  }
  const retVal = valTypeOfBcType(s.ctx.module.types[t.returnType]!);
  const fnObj = `fnobj_${s.tmpCounter++}`;
  line(s, `vader_fn_t* ${fnObj} = (vader_fn_t*) ${fnVal.name}.payload.obj;`);
  const callArgs = args.length === 0 ? `${fnObj}->env` : `${fnObj}->env, ${args.join(", ")}`;
  const call = `((vader_fn_sig_${op.typeIndex}_t) ${fnObj}->code)(${callArgs})`;
  if (retVal === "void") {
    line(s, `${call};`);
  } else {
    const tmp = newTmp(s, retVal);
    line(s, `${decl(s, retVal, tmp)} = ${call};`);
  }
}

export function emitIntrinsic(s: FnState, op: Extract<Op, { kind: "intrinsic" }>): void {
  switch (op.id) {
    case INTRINSIC_TABLE.builderNew.id: {
      const t = newTmp(s, "any");
      line(s, `${t}.tag = 0; ${t}._pad = 0; ${t}.payload.obj = vader_builder_new();`);
      return;
    }
    case INTRINSIC_TABLE.builderAppendStr.id: {
      const str = pop(s);
      const sb = pop(s);
      line(s, `vader_builder_append_str((vader_builder_t*) ${sb.name}.payload.obj, ${str.name});`);
      return;
    }
    case INTRINSIC_TABLE.builderAppendDisplay.id: {
      const v = pop(s);
      const sb = pop(s);
      const fn = displayFnFor(v.val);
      const arg = displayCoerce(v.name, v.val);
      line(s, `${fn}((vader_builder_t*) ${sb.name}.payload.obj, ${arg});`);
      return;
    }
    case INTRINSIC_TABLE.builderFinish.id: {
      const sb = pop(s);
      const t = newTmp(s, "string");
      line(s, `vader_string_t ${t} = vader_builder_finish((vader_builder_t*) ${sb.name}.payload.obj);`);
      return;
    }
  }
}

export function displayFnFor(v: ValType): string {
  switch (v) {
    case "i8": case "i16": case "i32":  return "vader_builder_append_display_i32";
    case "u8": case "u16": case "u32":  return "vader_builder_append_display_u32";
    case "i64": case "isize": return "vader_builder_append_display_i64";
    case "u64": case "usize": return "vader_builder_append_display_u64";
    case "f32":   return "vader_builder_append_display_f32";
    case "f64":   return "vader_builder_append_display_f64";
    case "bool":  return "vader_builder_append_display_bool";
    case "char":  return "vader_builder_append_display_char";
    case "string":return "vader_builder_append_display_string";
    default:      return "vader_builder_append_display_string";   // fallback — caller stringifies
  }
}

export function displayCoerce(name: string, v: ValType): string {
  if (v === "i8" || v === "i16") return `(int32_t) ${name}`;
  if (v === "u8" || v === "u16") return `(uint32_t) ${name}`;
  return name;
}

// ------------------------------------------------------------- struct / array

export function emitStructNew(
  s: FnState, op: Extract<Op, { kind: "struct.new" | "struct.new_stack" }>,
  onStack: boolean,
): void {
  const t = s.ctx.module.types[op.typeIndex]!;
  if (t.kind !== "struct") return;
  const cname = s.ctx.structNames[op.typeIndex]!;
  // Pop fields right-to-left.
  const fieldVals: { name: string; val: ValType }[] = [];
  for (let i = t.fields.length - 1; i >= 0; i--) fieldVals.unshift(pop(s));
  const tmp = newTmp(s, "ref");
  if (onStack) {
    // Escape analysis proved the value can't outlive the fn — allocate the
    // storage as a C local, skip the GC. If a GC cycle hits before the box
    // dies, the runtime forwards the payload to the heap (via the standard
    // shadow-stack scan) ; the stale `forward` slot left in the alloca'd
    // header is harmless since the C frame goes away on return and any
    // reuse runs `vader_obj_header_init` again.
    line(s, `${cname} ${tmp}_storage;`);
    line(s, `${cname}* ${tmp}_obj = &${tmp}_storage;`);
  } else {
    line(s, `${cname}* ${tmp}_obj = (${cname}*) vader_gc_alloc(sizeof(${cname}));`);
  }
  line(s, `vader_obj_header_init(${tmp}_obj, ${op.typeIndex}u);`);
  for (let i = 0; i < t.fields.length; i++) {
    const f = t.fields[i]!;
    const fval = valTypeOfField(s.ctx, f.typeIndex);
    const v = fieldVals[i]!;
    line(s, `${tmp}_obj->f_${sanitise(f.name)} = ${coerce(s, v.name, v.val, fval)};`);
  }
  // Always emit struct values as boxed vader_box_t so they flow uniformly
  // through `ref` slots and across fn boundaries. struct.get unboxes via
  // .payload.obj before downcasting.
  line(s, `${decl(s, "ref", tmp)} = vader_box_obj(${op.typeIndex}u, ${tmp}_obj);`);
}

export function emitStructGet(s: FnState, op: Extract<Op, { kind: "struct.get" }>): void {
  const t = s.ctx.module.types[op.typeIndex]!;
  if (t.kind !== "struct") return;
  const cname = s.ctx.structNames[op.typeIndex]!;
  const obj = pop(s);
  const f = t.fields[op.fieldIndex]!;
  const fval = valTypeOfField(s.ctx, f.typeIndex);
  const tmp = newTmp(s, fval);
  line(s, `${decl(s, fval, tmp)} = ((${cname}*) ${asObjPtr(obj)})->f_${sanitise(f.name)};`);
}

export function emitStructSet(s: FnState, op: Extract<Op, { kind: "struct.set" }>): void {
  const t = s.ctx.module.types[op.typeIndex]!;
  if (t.kind !== "struct") return;
  const cname = s.ctx.structNames[op.typeIndex]!;
  const value = pop(s);
  const obj = pop(s);
  const f = t.fields[op.fieldIndex]!;
  const fval = valTypeOfField(s.ctx, f.typeIndex);
  line(s, `((${cname}*) ${asObjPtr(obj)})->f_${sanitise(f.name)} = ${coerce(s, value.name, value.val, fval)};`);
  // Emitted unconditionally — the macro filters at runtime against the old
  // generation's address range. A future pass could elide it for tmps known
  // to come from `struct.new_stack`.
  line(s, `VADER_WRITE_BARRIER((${cname}*) ${asObjPtr(obj)});`);
}

/** Coerce a stack value holding a heap reference to a `void*`. Boxed values
 *  (vader_box_t) need `.payload.obj`; typed pointer slots (struct/array C
 *  variables) are usable directly. */
export function asObjPtr(v: { name: string; val: ValType }): string {
  if (v.val === "ref" || v.val === "any") return `${v.name}.payload.obj`;
  return v.name;
}

export function emitArrayNew(s: FnState, op: Extract<Op, { kind: "array.new" }>): void {
  const elements: { name: string; val: ValType }[] = [];
  for (let i = op.length - 1; i >= 0; i--) elements.unshift(pop(s));
  const tmp = newTmp(s, "ref");
  line(s, `vader_array_t* ${tmp}_arr = vader_array_new(${op.typeIndex}u, ${op.length}u);`);
  for (let i = 0; i < op.length; i++) {
    const v = elements[i]!;
    line(s, `${tmp}_arr->buf->slots[${i}] = ${boxExpr(s.ctx, v.name, v.val, op.typeIndex)};`);
  }
  line(s, `${decl(s, "ref", tmp)} = vader_box_obj(${op.typeIndex}u, ${tmp}_arr);`);
}

export function emitArrayGet(s: FnState, _op: Extract<Op, { kind: "array.get" }>): void {
  const idx = pop(s);
  const arr = pop(s);
  const tmp = newTmp(s, "any");
  line(s, `${decl(s, "any", tmp)} = vader_array_get((vader_array_t*) ${asObjPtr(arr)}, (size_t) ${idx.name});`);
}

export function emitArraySet(s: FnState, op: Extract<Op, { kind: "array.set" }>): void {
  const value = pop(s);
  const idx = pop(s);
  const arr = pop(s);
  line(s, `vader_array_set((vader_array_t*) ${asObjPtr(arr)}, (size_t) ${idx.name}, ${boxExpr(s.ctx, value.name, value.val, op.typeIndex)});`);
}

export function emitTypeCheck(s: FnState, op: Extract<Op, { kind: "type_check" }>): void {
  const v = pop(s);
  const tmp = newTmp(s, "bool");
  // The value's static `val` tells us whether we're testing a boxed slot or
  // a primitively-typed one. For boxed values we compare tags; for primitives
  // we compare the slot's static type against the target tag.
  if (v.val === "ref" || v.val === "any") {
    const targetType = s.ctx.module.types[op.typeIndex];
    // For trait references, check whether the value's tag corresponds to any
    // struct that implements the trait (using the module's impl table).
    // Also always include a direct tag comparison against op.typeIndex itself:
    // built-in ref types like Error are tagged with their own type index.
    if (targetType?.kind === "ref" && targetType.traitName !== null) {
      const cond = traitCheckExpr(s.ctx, v.name, targetType.traitName, op.typeIndex);
      line(s, `bool ${tmp} = ${cond};`);
    } else {
      line(s, `bool ${tmp} = (${v.name}.tag == ${op.typeIndex}u);`);
    }
  } else {
    // Primitive slot can only match if its static ValType corresponds to the
    // target type's primitive (or struct/array typeIndex matches).
    line(s, `bool ${tmp} = ${primitiveMatchesType(s.ctx, v.val, op.typeIndex) ? "true" : "false"};`);
  }
}

/** Build the C boolean expression that checks whether `vName` (a `vader_box_t`)
 *  has a tag corresponding to any struct implementing `traitName`, or is
 *  directly tagged as the trait ref type itself (e.g. built-in Error). */
export function traitCheckExpr(ctx: EmitCtx, vName: string, traitName: string, refTypeIndex: number): string {
  const structIdxs = ctx.structIdxsByTrait.get(traitName) ?? [];
  const tags = [refTypeIndex, ...structIdxs];
  return tags.map((idx) => `(${vName}.tag == ${idx}u)`).join(" || ");
}

export function emitRefCast(s: FnState, op: Extract<Op, { kind: "ref.cast" }>): void {
  const v = pop(s);
  // Determine target ValType from the type table.
  const target = s.ctx.module.types[op.typeIndex]!;
  const targetVal = valTypeOfBcType(target);
  const tmp = newTmp(s, targetVal);
  if (v.val === "ref" || v.val === "any") {
    line(s, `${decl(s, targetVal, tmp)} = ${unboxExpr(v.name, targetVal)};`);
  } else {
    line(s, `${decl(s, targetVal, tmp)} = (${cTypeForVal(s.ctx, targetVal)}) ${v.name};`);
  }
}

// ------------------------------------------------------------- numeric

export function emitNumericOp(s: FnState, kind: string): void {
  // <type>.to_<type> or <type>.<verb>
  const dot = kind.indexOf(".");
  const t = kind.slice(0, dot);
  const verb = kind.slice(dot + 1);
  if (verb.startsWith("to_")) return emitConvert(s, t as ValType, verb.slice(3) as ValType);
  emitTypedBinop(s, t as ValType, verb);
}

export function emitConvert(s: FnState, from: ValType, to: ValType): void {
  const v = pop(s);
  const tmp = newTmp(s, to);
  if (from === to) {
    line(s, `${decl(s, to, tmp)} = ${v.name};`);
  } else {
    line(s, `${decl(s, to, tmp)} = (${cTypeForVal(s.ctx, to)}) ${v.name};`);
  }
}

export function emitTypedBinop(s: FnState, t: ValType, verb: string): void {
  if (verb === "neg" || verb === "bitnot") {
    const v = pop(s);
    const tmp = newTmp(s, t);
    const op = verb === "neg" ? "-" : "~";
    line(s, `${decl(s, t, tmp)} = ${op}${v.name};`);
    return;
  }
  const r = pop(s);
  const l = pop(s);
  const arith: Record<string, string> = {
    add: "+", sub: "-", mul: "*", div: "/", rem: "%",
    bitand: "&", bitor: "|", bitxor: "^", shl: "<<", shr: ">>",
  };
  const cmp: Record<string, string> = {
    eq: "==", ne: "!=", lt: "<", le: "<=", gt: ">", ge: ">=",
  };
  if (arith[verb]) {
    const tmp = newTmp(s, t);
    line(s, `${decl(s, t, tmp)} = ${l.name} ${arith[verb]} ${r.name};`);
    return;
  }
  if (cmp[verb]) {
    const tmp = newTmp(s, "bool");
    line(s, `${decl(s, "bool", tmp)} = ${l.name} ${cmp[verb]} ${r.name};`);
    return;
  }
  // Unhandled — emit a trap so the failure surfaces at runtime.
  line(s, `vader_unreachable("unhandled op ${kind(t, verb)}");`);
}

export function kind(t: ValType, verb: string): string { return `${t}.${verb}`; }

