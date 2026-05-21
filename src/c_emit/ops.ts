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
import type { BcType, ValType } from "../bytecode/types.ts";
import { arrayKindIndex, arrayKindOf, inlineVariantPayload, nullableRefVariant } from "../bytecode/types.ts";

import type { EmitCtx } from "./emit.ts";
import { cStringLit, cStringLitFromBytes, escapeC, packedStructName, sanitise } from "./emit.ts";
import {
  aux, b1SlotVariant, boxExpr, boxExprUnknown, coerce, coerceExpr, cTypeFor,
  cTypeForSignatureSlot, cTypeForVal, cTypeForValBare, isRefVal, line,
  nameOf, newTmp, peek, pop, primitiveMatchesType, pushBinop, pushBinopAny,
  pushFnCall2, pushLit, pushLocalRef, pushUnop, signatureFor, unboxExpr,
  valTypeOfBcType, valTypeOfField, zeroInit,
  type FnState,
} from "./body.ts";

export function emitCall(s: FnState, op: Extract<Op, { kind: "call" }>): void {
  const callee = s.ctx.module.functions[op.fnIndex]!;
  emitCallTo(s, s.ctx.fnNames[op.fnIndex]!, callee.signature, op.expectedResultType, op.argTypeIndices);
}

export function emitCallImport(s: FnState, op: Extract<Op, { kind: "call.import" }>): void {
  const imp = s.ctx.module.imports[op.importIndex]!;
  emitCallTo(s, `vader_import_${op.importIndex}`, imp.signature);
}

/** Shared C-emit path for direct calls (own fns + imports). Pops args
 *  off the value stack in reverse, coerces them through B1 boundaries
 *  if the callee expects a `void*`, and re-boxes a B1 return back into
 *  a `vader_box_t` tmp so downstream ops continue to see a normal ref
 *  value on the stack. */
function emitCallTo(
  s: FnState, calleeName: string, sig: BcSignature, expectedResultType?: number,
  argTypeIndices?: readonly number[],
): void {
  const args: string[] = [];
  for (let i = sig.params.length - 1; i >= 0; i--) {
    const v = pop(s);
    let boxed = coerce(s, v.name, v.val, sig.params[i]!);
    // Argument-side erasure reshape : when the caller's static arg type
    // is a struct with an Any-counterpart matching the callee's expected
    // paramType, allocate the Any-version layout, box each field, and
    // pass that instead of the raw concrete struct. Symmetric to the
    // return-side `emitErasureBoundaryConversion` ; without this,
    // calling an erased fn (`swap[T,U]`) with a concrete tuple
    // (`Tuple_24 { i32, string }`) makes the callee read through the
    // Any layout (`Tuple_2 { vader_box_t, vader_box_t }`) → field
    // size/offset mismatch → garbage.
    if (argTypeIndices !== undefined && (v.val === "ref" || v.val === "any")) {
      const callerTypeIdx = argTypeIndices[i];
      const calleeTypeIdx = sig.paramTypes[i];
      if (callerTypeIdx !== undefined && calleeTypeIdx !== undefined
          && callerTypeIdx !== calleeTypeIdx
          && s.ctx.anyCounterpartOf.get(callerTypeIdx) === calleeTypeIdx) {
        boxed = emitArgReshape(s, boxed, callerTypeIdx, calleeTypeIdx);
      }
    }
    args.unshift(coerceForB1Arg(s.ctx, boxed, sig.paramTypes[i]!));
  }
  const callExpr = `${calleeName}(${args.join(", ")})`;
  emitCallResult(s, callExpr, sig.result, sig.resultType, expectedResultType);
}

/** Inverse of `emitHeapStructReshape` : the caller has a vader_box_t
 *  pointing at the concrete-shape struct (`Tuple_24 { i32, string }`),
 *  the callee expects the Any-shape layout (`Tuple_2 { vader_box_t,
 *  vader_box_t }`). Allocate the Any-shape struct, box each concrete
 *  field, return the new vader_box_t. Skips fields whose ValType the
 *  generic boxing path can't bridge (arrays / unions / fns) — caller
 *  passes the unmodified box and accepts whatever runtime fault may
 *  surface ; the dispatch-side fallback is the existing path. */
function emitArgReshape(s: FnState, src: string, concreteIdx: number, anyIdx: number): string {
  const concrete = s.ctx.module.types[concreteIdx];
  const any = s.ctx.module.types[anyIdx];
  if (concrete?.kind !== "struct" || any?.kind !== "struct") return src;
  if (concrete.fields.length !== any.fields.length) return src;
  const anyCName = s.ctx.structNames[anyIdx];
  const concreteCName = s.ctx.structNames[concreteIdx];
  if (!anyCName) return src;
  if (!concreteCName) return src;
  for (const f of concrete.fields) {
    const ft = s.ctx.module.types[f.typeIndex];
    if (ft === undefined) return src;
    if (ft.kind !== "primitive" && ft.kind !== "struct" && ft.kind !== "ref") return src;
  }
  const tmp = newTmp(s, "ref");
  const argObj = aux(s, "arg");
  line(s, `${anyCName}* ${argObj} = (${anyCName}*) vader_gc_alloc(sizeof(${anyCName}));`);
  line(s, `vader_obj_header_init(${argObj}, ${anyIdx}u);`);
  for (let i = 0; i < concrete.fields.length; i++) {
    const cf = concrete.fields[i]!;
    const af = any.fields[i]!;
    const cval = valTypeOfField(s.ctx, cf.typeIndex);
    const fieldName = sanitise(cf.name);
    const concreteFieldExpr = `((${concreteCName}*) ${src}.payload.obj)->f_${fieldName}`;
    let boxedField: string;
    if (cval === "ref" || cval === "any") {
      boxedField = concreteFieldExpr;
    } else {
      boxedField = boxExpr(s.ctx, concreteFieldExpr, cval as ValType, cf.typeIndex);
    }
    line(s, `${argObj}->f_${sanitise(af.name)} = ${boxedField};`);
  }
  line(s, `${tmp} = vader_box_obj(${anyIdx}u, ${argObj});`);
  return tmp;
}

/** Lower a (callExpr, expected result valType, result BcType idx)
 *  triple into a statement that captures the result on the value stack
 *  — re-boxing void* via `vader_b1_to_box` when the slot is B1.
 *  `expectedResultType` (when provided) names the call site's static
 *  type — different from `retTypeIndex` (the callee's actual return
 *  type) under erasure (callee returns Yield(Any) | null, caller
 *  expects Yield(i32) | null). Trigger boundary conversion when they
 *  diverge and the expected type is an inline-eligible struct. */
function emitCallResult(
  s: FnState, callExpr: string, retVal: ValType, retTypeIndex: number,
  expectedResultType?: number,
): void {
  if (retVal === "void") {
    line(s, `${callExpr};`);
    return;
  }
  const b1 = b1SlotVariant(s.ctx, retTypeIndex);
  if (b1 !== null) {
    const raw = newTmp(s, "ref");
    const b1Raw = aux(s, "b1");
    line(s, `void* ${b1Raw} = ${callExpr};`);
    line(s, `${raw} = vader_b1_to_box(${b1Raw}, ${b1}u);`);
    if (expectedResultType !== undefined && expectedResultType !== retTypeIndex) {
      emitErasureBoundaryConversion(s, raw, expectedResultType);
    }
    return;
  }
  const t = newTmp(s, retVal);
  line(s, `${t} = ${callExpr};`);
  if (retVal === "ref" || retVal === "any") {
    if (expectedResultType !== undefined && expectedResultType !== retTypeIndex) {
      emitErasureBoundaryConversion(s, t, expectedResultType);
    }
  }
}

/** When the callee's slot is B1, downgrade the boxed arg to a raw
 *  `void*`. Otherwise pass the boxed C expression through unchanged. */
function coerceForB1Arg(ctx: EmitCtx, boxed: string, slotTypeIndex: number): string {
  return b1SlotVariant(ctx, slotTypeIndex) !== null ? `vader_box_to_b1(${boxed})` : boxed;
}

export function emitFnRef(s: FnState, op: Extract<Op, { kind: "fn.ref" }>): void {
  const tmp = newTmp(s, "ref");
  line(s, `${tmp} = vader_box_obj(${op.typeIndex}u, &vader_fn_static_${op.fnIndex});`);
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
  line(s, `${tmp} = ${helper}(${[recvBoxed, ...boxedArgs].join(", ")});`);

  // Erasure-aware result conversion : the dispatched impl body was lowered
  // with type-params substituted to Any, so for `@specialize`d structs
  // whose layout is inline-eligible (Yield(T), Box(T), …) the body
  // returns the heap-allocated Any-version (`payload.obj` = heap struct).
  // The call site's static type expects the concrete inline-form
  // (`payload.i` / `payload.s` / … with the variant tag). Re-pack at the
  // boundary so downstream `struct.get` / `local.set` / `coerce` see the
  // expected layout.
  // Boundary conversion fires whenever the dispatcher's actual return type
  // differs from the call site's static expectation — covers both the
  // heterogeneous-impl case (`Add.add` on numerics, dispatcher boxes to
  // any) AND the homogeneous-but-erased case (`Iterator.next` impls all
  // return Yield(Any) | null while walk expects Yield(i32) | null).
  if (op.resultTypeIndex !== undefined && op.resultTypeIndex !== sig.resultType) {
    emitErasureBoundaryConversion(s, tmp, op.resultTypeIndex);
  }
}

/** When the dispatcher returns a heap-form Any-version of a struct but
 *  the call site expects the inline-form, read the heap struct's first
 *  field through a raw pointer offset and re-pack as the inline-tagged
 *  box. Handles the single-primitive-field and single-ref-field cases
 *  directly ; packed multi-field is deferred (Range[T] still goes
 *  through the heap path until a packed-layout reader lands). */
function emitErasureBoundaryConversion(s: FnState, tmp: string, expectedTypeIndex: number): void {
  // Resolve the struct in the expected type. `Yield(T) | null` unions are
  // common ; pick the non-null variant. For unions with multiple struct
  // variants (e.g. `i64 | ParseError`) the result is ambiguous : skip
  // conversion ; the heap layout will be propagated as-is.
  const expected = s.ctx.module.types[expectedTypeIndex];
  if (expected === undefined) return;
  // Array-typed expected : the erased fn allocated `Array(Any)` with
  // BOXED element storage (vader_box_t[] backing), but the caller's
  // concrete element type expects tightly-packed primitive slots
  // (`int32_t[]` for `i32[]`). Reshape by allocating a fresh array of
  // the right element_kind and copying slot-by-slot with unboxing.
  if (expected.kind === "array") {
    emitArrayElementKindReshape(s, tmp, expectedTypeIndex, expected);
    return;
  }
  let structIdx = -1;
  if (expected.kind === "struct") {
    structIdx = expectedTypeIndex;
  } else if (expected.kind === "union") {
    let structCount = 0;
    for (const variant of expected.variants) {
      const t = s.ctx.module.types[variant];
      if (t?.kind === "struct") { structIdx = variant; structCount++; }
    }
    if (structCount !== 1) return;                       // ambiguous, skip
  }
  if (structIdx < 0) return;
  const structT = s.ctx.module.types[structIdx]!;
  if (structT.kind !== "struct") return;
  if (s.ctx.mutatedStructs.has(structIdx)) return;     // heap-form on both sides, no conversion

  // Only convert when the runtime receiver carries the Any-counterpart's
  // tag — any other tag (e.g. an alternate union variant) means the runtime
  // already matches the call site's expectation.
  const anyIdx = s.ctx.anyCounterpartOf.get(structIdx);
  if (anyIdx === undefined) return;                    // no Any-version exists, nothing to convert

  const inline = inlineVariantPayload(structT, s.ctx.module.types);
  if (inline === "void") return;
  if (inline === "packed") return;                     // TODO : packed-layout repack

  if (inline === null) {
    // Heap-form on the expected side too. Conversion needed only when the
    // field layouts diverge (e.g. tuple `[string, i32]` expected vs the
    // Any-version `[Any, Any]`). Allocate a fresh concrete-shaped struct
    // and copy each field through `boxExpr`/`unboxExpr`.
    emitHeapStructReshape(s, tmp, structIdx, anyIdx);
    return;
  }

  // Inline-eligible expected, heap-form runtime. Read the field from the
  // Any-version heap layout (vader_box_t slot just after the obj header)
  // and re-pack into the inline-form.
  const field = structT.fields[0];
  if (field === undefined) return;
  line(s, `if (${tmp}.tag == ${anyIdx}u) {`);
  line(s, `    vader_box_t __any_field_0 = *(vader_box_t*)((char*)${tmp}.payload.obj + sizeof(vader_obj_header_t));`);
  if (inline === "ref") {
    line(s, `    ${tmp} = vader_box_obj(${structIdx}u, __any_field_0.payload.obj);`);
  } else {
    const unboxed = unboxExpr("__any_field_0", inline as ValType);
    const repack = boxExpr(s.ctx, unboxed, inline as ValType, structIdx);
    line(s, `    ${tmp} = ${repack};`);
  }
  line(s, `}`);
}

/** Array element_kind reshape : an erased fn returned a BOXED-backing
 *  `Array(Any)` but the call site expects a primitive-element-kind
 *  array (e.g. `i32[]` with element_kind = I32). The runtime can't
 *  re-interpret BOXED slots as int32_t in place — sizes differ.
 *  Allocate a fresh array of the right element_kind via
 *  `vader_array_new`, then for each slot pop the box, unbox to the
 *  primitive, and store. The reshape is O(length) allocations and
 *  copies — expensive ; the perf-aware path is the stdlib API shift
 *  to `Iterator(T)`. Bails on arrays whose element type is itself
 *  non-primitive (struct, array, union — would cascade more
 *  conversions). */
function emitArrayElementKindReshape(
  s: FnState, tmp: string, expectedTypeIndex: number,
  expected: { kind: "array"; element: number },
): void {
  const elemBcType = s.ctx.module.types[expected.element];
  if (elemBcType === undefined) return;

  // Two reshape flavours, dispatched on the expected element type :
  //
  //  (a) Primitive non-string element : the source is BOXED-backed
  //      (vader_box_t per slot) but the target expects tightly-packed
  //      primitive storage (`int32_t[]`). Allocate a fresh array with
  //      the right element_kind, unbox+repack per slot.
  //  (b) Struct element with an Any-counterpart : both source and
  //      target use BOXED storage so the array shape matches, but
  //      each slot is the wrong concrete struct shape (`Tuple(Any,
  //      Any)` source, `Tuple(string, i32)` target). Allocate a fresh
  //      array, reshape each slot box through the recursive struct
  //      converter, push.
  //
  // Other shapes (ref, array, union, fn — and primitive `string`
  // already BOXED-backed) bail without conversion.
  if (elemBcType.kind === "primitive" && elemBcType.val !== "string") {
    const elemKind = arrayKindOf(elemBcType);
    if (elemKind === "boxed") return;
    const kindIdx = arrayKindIndex(elemKind);
    line(s, `if (${tmp}.payload.obj != NULL) {`);
    line(s, `    vader_array_t* __src_arr = (vader_array_t*) ${tmp}.payload.obj;`);
    line(s, `    size_t __n = __src_arr->length;`);
    line(s, `    vader_array_t* __dst_arr = vader_array_new(${expectedTypeIndex}u, __n, ${kindIdx}u, ${expected.element}u);`);
    line(s, `    for (size_t __i = 0; __i < __n; __i++) {`);
    line(s, `        vader_box_t __slot = vader_array_get(__src_arr, __i);`);
    line(s, `        vader_array_set(__dst_arr, __i, ${boxExpr(s.ctx, unboxExpr("__slot", elemBcType.val as ValType), elemBcType.val as ValType, expected.element)});`);
    line(s, `    }`);
    line(s, `    ${tmp} = vader_box_obj(${expectedTypeIndex}u, __dst_arr);`);
    line(s, `}`);
    return;
  }

  if (elemBcType.kind === "struct") {
    const elemAnyIdx = s.ctx.anyCounterpartOf.get(expected.element);
    if (elemAnyIdx === undefined) return;          // element layout already uniform
    if (s.ctx.mutatedStructs.has(expected.element)) return;
    line(s, `if (${tmp}.payload.obj != NULL) {`);
    line(s, `    vader_array_t* __src_arr = (vader_array_t*) ${tmp}.payload.obj;`);
    line(s, `    size_t __n = __src_arr->length;`);
    line(s, `    vader_array_t* __dst_arr = vader_array_new(${expectedTypeIndex}u, __n, ${arrayKindIndex("boxed")}u, ${expected.element}u);`);
    line(s, `    for (size_t __i = 0; __i < __n; __i++) {`);
    line(s, `        vader_box_t __slot = vader_array_get(__src_arr, __i);`);
    emitHeapStructReshape(s, "__slot", expected.element, elemAnyIdx);
    line(s, `        vader_array_set(__dst_arr, __i, __slot);`);
    line(s, `    }`);
    line(s, `    ${tmp} = vader_box_obj(${expectedTypeIndex}u, __dst_arr);`);
    line(s, `}`);
    return;
  }
}

/** Heap-form reshape : the runtime carries an all-`Any`-fields heap
 *  struct (e.g. `Tuple_2 { vader_box_t f__0, f__1 }` from an erased fn
 *  body) but the call site reads it through the concrete-fields layout
 *  (`Tuple_25 { string f__0, i32 f__1 }`). Allocate a fresh concrete
 *  struct, read each Any-version field as `vader_box_t` at its sequential
 *  offset, unbox to the concrete field's ValType, write into the new
 *  struct. Fields whose layout already matches (both ref / both same
 *  primitive) skip the unbox. Skips conversion when any concrete field
 *  is a non-primitive non-ref shape we don't know how to bridge (arrays,
 *  unions, fn types). */
function emitHeapStructReshape(s: FnState, tmp: string, expectedIdx: number, anyIdx: number): void {
  const expected = s.ctx.module.types[expectedIdx];
  if (expected?.kind !== "struct") return;
  const cname = s.ctx.structNames[expectedIdx];
  if (!cname) return;

  // Skip when the expected layout already matches the Any-version (all
  // fields stored as `ref`/`any` heap slots). Reshaping into an
  // identical layout adds an unnecessary heap allocation per call and
  // its `__inner_field_0` recursion can hit a non-existent inner
  // inline form, producing broken C. Layouts only diverge when at
  // least one expected field is typed concretely (primitive / array /
  // union variant) ; the all-ref case is the post-erasure shared shape.
  const allFieldsRef = expected.fields.every((f) => {
    const ft = s.ctx.module.types[f.typeIndex];
    return ft?.kind === "ref" || ft?.kind === "union";
  });
  if (allFieldsRef) return;

  // Bail when any expected field has a shape the per-sibling copy
  // can't bridge (array / fn — each carries its own runtime
  // invariants). Union fields are accepted : the per-sibling routine
  // copies them as `vader_box_t` (the runtime carries the variant
  // tag in the slot itself, no per-arm reshape needed). Primitive +
  // struct + ref + union are all handled by the per-sibling field
  // dispatch.
  for (const f of expected.fields) {
    const ft = s.ctx.module.types[f.typeIndex];
    if (ft === undefined) return;
    if (ft.kind === "array" || ft.kind === "fn") return;
  }

  // Enumerate every sibling layout (same logical shape group) so the
  // reshape dispatches on the runtime tag. Always includes the
  // canonical Any-version (`anyIdx`) at the front ; tuples with mixed
  // concrete + erased fields (e.g. `[usize, T]` post-subst `[usize,
  // Any]`) add a distinct sibling that the canonical all-ref version
  // doesn't cover.
  const siblings = s.ctx.siblingLayoutsOf.get(expectedIdx) ?? [anyIdx];
  for (const sibIdx of siblings) {
    if (sibIdx === expectedIdx) continue;
    const sib = s.ctx.module.types[sibIdx];
    if (sib?.kind !== "struct") continue;
    if (sib.fields.length !== expected.fields.length) continue;
    emitHeapStructReshapeForSibling(s, tmp, expectedIdx, expected, sibIdx, sib, cname);
  }
}

function emitHeapStructReshapeForSibling(
  s: FnState, tmp: string, expectedIdx: number,
  expected: { kind: "struct"; fields: readonly { name: string; typeIndex: number }[] },
  sibIdx: number,
  sib: { kind: "struct"; fields: readonly { name: string; typeIndex: number }[] },
  cname: string,
): void {
  const sibCname = s.ctx.structNames[sibIdx];
  if (!sibCname) return;
  line(s, `if (${tmp}.tag == ${sibIdx}u) {`);
  line(s, `    ${cname}* __reshape = (${cname}*) vader_gc_alloc(sizeof(${cname}));`);
  line(s, `    vader_obj_header_init(__reshape, ${expectedIdx}u);`);
  line(s, `    ${sibCname}* __sib = (${sibCname}*) ${tmp}.payload.obj;`);
  for (let i = 0; i < expected.fields.length; i++) {
    const ef = expected.fields[i]!;
    const sf = sib.fields[i]!;
    const efVal = valTypeOfField(s.ctx, ef.typeIndex);
    const sfVal = valTypeOfField(s.ctx, sf.typeIndex);
    const sibFieldExpr = `__sib->f_${sanitise(sf.name)}`;
    let rhs: string;
    if (efVal === sfVal) {
      rhs = sibFieldExpr;
    } else if (efVal === "ref" || efVal === "any") {
      // Sibling field is concrete primitive, expected is ref → box up.
      rhs = boxExpr(s.ctx, sibFieldExpr, sfVal as ValType, sf.typeIndex);
    } else if (sfVal === "ref" || sfVal === "any") {
      // Sibling field is ref/any (vader_box_t), expected is primitive
      // → unbox.
      rhs = unboxExpr(sibFieldExpr, efVal as ValType);
    } else {
      // Both primitive but different — defensive cast through unbox.
      rhs = `(${cTypeForVal(s.ctx, efVal)}) ${sibFieldExpr}`;
    }
    line(s, `    __reshape->f_${sanitise(ef.name)} = ${rhs};`);
  }
  line(s, `    ${tmp} = vader_box_obj(${expectedIdx}u, __reshape);`);
  line(s, `}`);
}

export function vtableHelperName(key: string): string {
  return `vader_vt_${sanitise(key.replace(".", "__"))}`;
}

/** Per-vtable canonical signature. Most traits have homogeneous result
 *  types across all impls (`Hash.hash` always returns u64, `Equals.equals`
 *  always returns bool) — those use the first impl's sig directly. Traits
 *  whose impl results diverge in ValType (`Add.add` returning i32/string/
 *  bool/...) or in BcType (`Iterator.next` returning Yield(i32)|null vs
 *  Yield(Any)|null — both fold to ValType "ref" but the BcTypes differ
 *  in their B1 eligibility and per-tag downstream coercion) get a
 *  synthetic uniform sig with `result: "any"` so the call site uses the
 *  erasure-boundary conversion path. */
export function vtableSignatures(ctx: EmitCtx): ReadonlyMap<string, BcSignature> {
  const out = new Map<string, BcSignature>();
  for (const [key, table] of ctx.module.vtables) {
    const firstFnIdx = table.values().next().value;
    if (firstFnIdx === undefined) continue;
    const firstFn = ctx.module.functions[firstFnIdx];
    if (firstFn === undefined) continue;
    let uniform = true;
    const firstResult = firstFn.signature.result;
    const firstResultType = firstFn.signature.resultType;
    for (const fnIdx of table.values()) {
      const fn = ctx.module.functions[fnIdx];
      if (fn === undefined) continue;
      if (fn.signature.result !== firstResult
          || fn.signature.resultType !== firstResultType) {
        uniform = false; break;
      }
    }
    if (uniform) {
      out.set(key, firstFn.signature);
    } else {
      // Synthetic uniform sig — params are taken from the first impl (their
      // boxed-`any` projection happens in `emitVtableForwardDecls`), result
      // is forced to `any` so all arms can box-and-return uniformly.
      out.set(key, {
        params: firstFn.signature.params,
        paramTypes: firstFn.signature.paramTypes,
        result: "any",
        resultType: firstFn.signature.resultType,
      });
    }
  }
  return out;
}

/** Forward-declare every vtable dispatcher up front so user fns that call
 *  them compile before the dispatcher bodies are emitted. */
export function emitVtableForwardDecls(ctx: EmitCtx, out: string[]): void {
  if (ctx.module.vtables.size === 0) return;
  out.push(``);
  out.push(`/* ----------------------------------------------- vtable forwards */`);
  const sigs = vtableSignatures(ctx);
  for (const [key, table] of ctx.module.vtables) {
    if (table.size === 0) continue;
    const sig = sigs.get(key);
    if (sig === undefined) continue;
    // Tail params are typed `vader_box_t` so the dispatcher can host arms
    // with divergent monomorphised signatures. Each arm unboxes to its
    // concrete impl signature.
    const tailCount = sig.params.length - 1;
    const tailParamDecls = Array.from({ length: tailCount }, (_, i) => `vader_box_t a${i}`).join(", ");
    const formal = tailCount > 0 ? `vader_box_t recv, ${tailParamDecls}` : `vader_box_t recv`;
    // Result type comes from `vtableSignatures` — uniform across impls when
    // all agree, falls back to `vader_box_t` (sig.result = "any") when impls
    // diverge (e.g. `Add.add` returning i32/string/bool/...).
    const cret = cTypeForVal(ctx, sig.result);
    out.push(`static ${cret} ${vtableHelperName(key)}(${formal});`);
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
  const sigs = vtableSignatures(ctx);
  for (const [key, table] of ctx.module.vtables) {
    if (table.size === 0) continue;
    const sig = sigs.get(key);
    if (sig === undefined) continue;
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
        const callExpr = `${calleeName}(${allArgs})`;
        // Box per-arm when the dispatcher's expected result type doesn't
        // match the impl's. Three flavours :
        //  - impl returns ref/any AND dispatcher returns any → pass through
        //  - impl returns B1 (nullable ref) → `vader_b1_to_box`
        //  - impl returns primitive AND dispatcher returns any → `coerceExpr`
        //    boxes via `boxExprUnknown`
        //  - impl/result types already match → bare callExpr
        const implResult = calleeSig.result;
        let wrapped: string;
        if (sig.result === "any" && implResult !== "any" && implResult !== "ref" && implResult !== "void") {
          wrapped = coerceExpr(ctx, callExpr, implResult, "any");
        } else {
          const b1Variant = b1SlotVariant(ctx, calleeSig.resultType);
          wrapped = b1Variant !== null
            ? `vader_b1_to_box(${callExpr}, ${b1Variant}u)`
            : callExpr;
        }
        out.push(`        case ${tag}u: return ${wrapped};`);
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
  line(s, `${tmp} = vader_box_obj(${op.typeIndex}u, ${fnObj});`);
}

export function emitCallIndirect(s: FnState, op: Extract<Op, { kind: "call.indirect" }>): void {
  const t = s.ctx.module.types[op.typeIndex];
  if (t === undefined || t.kind !== "fn") {
    line(s, `vader_unreachable("call.indirect on non-fn type");`);
    return;
  }
  // Universal erased ABI : box every arg to vader_box_t, cast through
  // `vader_fn_erased_sig_N_t`. Lets a concrete-typed closure flow
  // through an erased call site (e.g. erased `map` calling its `f`
  // callback) without a calling-convention mismatch. The wrapper
  // emitted in `emitFnTrampolines` unboxes per the underlying fn's
  // concrete sig.
  const fnVal = pop(s);
  const args: string[] = [];
  for (let i = t.params.length - 1; i >= 0; i--) {
    const v = pop(s);
    args.unshift(coerce(s, v.name, v.val, "any"));
  }
  const fnObj = `fnobj_${s.tmpCounter++}`;
  line(s, `vader_fn_t* ${fnObj} = (vader_fn_t*) ${fnVal.name}.payload.obj;`);
  const callArgs = args.length === 0 ? `${fnObj}->env` : `${fnObj}->env, ${args.join(", ")}`;
  const callExpr = `((vader_fn_erased_sig_${t.params.length}_t) ${fnObj}->code)(${callArgs})`;
  // Wrapper returns vader_box_t ; coerce on the stack to the static
  // return ValType so direct readers (`if cond`, primitive-slot
  // `local.set`) see the expected C type.
  const retVal = valTypeOfBcType(s.ctx.module.types[t.returnType]!);
  if (retVal === "void") {
    line(s, `${callExpr};`);
    return;
  }
  const anyTmp = newTmp(s, "any");
  line(s, `${anyTmp} = ${callExpr};`);
  // Pop the "any" tmp ; coerce back to the static return type by
  // re-pushing through `coerce`. For ref/any returns this is a
  // pass-through ; for primitives it unboxes via `unboxExpr`.
  if (retVal === "ref" || retVal === "any") return;
  pop(s);
  const t2 = newTmp(s, retVal);
  line(s, `${t2} = ${coerce(s, anyTmp, "any", retVal)};`);
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
      line(s, `${t} = vader_builder_finish((vader_builder_t*) ${sb.name}.payload.obj);`);
      return;
    }
    case INTRINSIC_TABLE.sizeOfType.id: {
      // Decoder for the `type.const` boxing (see `c_emit/body.ts`) : the
      // payload pointer carries `typeIndex` cast through `uintptr_t`.
      // `vader_type_size[]` is emitted in `c_emit/emit.ts`.
      const tv = pop(s);
      const out = newTmp(s, "usize");
      line(s, `${out} = vader_type_size[(int32_t)(uintptr_t)${tv.name}.payload.obj];`);
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
): void {
  const t = s.ctx.module.types[op.typeIndex]!;
  if (t.kind !== "struct") return;
  const cname = s.ctx.structNames[op.typeIndex]!;
  const onStack = op.kind === "struct.new_stack";
  // Pop fields right-to-left.
  const fieldVals: { name: string; val: ValType }[] = [];
  for (let i = t.fields.length - 1; i >= 0; i--) fieldVals.unshift(pop(s));

  // Inline-variant fast path : an empty struct, a single-primitive-field
  // struct, or a single-ref-field struct can ride entirely inside
  // `vader_box_t.payload`. Skip the GC allocation, encode the value
  // directly. Saves an alloc + header init + box wrap per instance.
  // Common on iter combinators (`Yield(T) | null`), Result/Option-style
  // unions, any user enum-with-payload. Excluded : structs that any
  // `struct.set` writes to anywhere in the module — the mutation needs
  // a heap body so every alias observes the new value.
  const inlinePayload = !s.ctx.mutatedStructs.has(op.typeIndex)
    ? inlineVariantPayload(t, s.ctx.module.types)
    : null;
  if (inlinePayload !== null) {
    const tmp = newTmp(s, "ref");
    if (inlinePayload === "void") {
      // Empty-body — tag identifies, no payload to carry.
      line(s, `${tmp} = vader_box_obj(${op.typeIndex}u, NULL);`);
    } else if (inlinePayload === "ref") {
      // Single-ref-field — the wrapper itself never allocates ; we just
      // re-tag the field's heap pointer with our struct's tag. The GC
      // scans via `VADER_TYPE_KIND_INLINE_REF`'s scan_raw path, which
      // reads the referent's own header tag rather than ours.
      const v = fieldVals[0]!;
      line(s, `${tmp} = vader_box_obj(${op.typeIndex}u, ${v.name}.payload.obj);`);
    } else if (inlinePayload === "packed") {
      // Multi-field POD packed into `payload.packed[16]`. Cast the byte
      // array to the header-less mirror struct (emitted next to the
      // regular typedef in `emitTypeDecls`) and assign each field
      // directly ; the C compiler resolves the layout.
      const pname = packedStructName(cname);
      line(s, `${tmp} = (vader_box_t){ .tag = ${op.typeIndex}u, ._pad = 0 };`);
      line(s, `{`);
      line(s, `    ${pname}* __packed = (${pname}*)${tmp}.payload.packed;`);
      for (let i = 0; i < t.fields.length; i++) {
        const f = t.fields[i]!;
        const v = fieldVals[i]!;
        const fval = valTypeOfField(s.ctx, f.typeIndex);
        const coerced = coerce(s, v.name, v.val, fval);
        line(s, `    __packed->f_${sanitise(f.name)} = ${coerced};`);
      }
      line(s, `}`);
    } else {
      // Single primitive field — coerce the incoming value into the matching
      // payload slot, then box with the variant's tag. `boxExpr` knows how
      // to widen / sign-zero-extend each integer width.
      const v = fieldVals[0]!;
      const coerced = coerce(s, v.name, v.val, inlinePayload);
      line(s, `${tmp} = ${boxExpr(s.ctx, coerced, inlinePayload, op.typeIndex)};`);
    }
    return;
  }

  const tmp = newTmp(s, "ref");
  const auxObj = aux(s, "obj");
  if (onStack) {
    // Escape analysis proved the value can't outlive the fn — allocate the
    // storage as a C local, skip the GC. If a GC cycle hits before the box
    // dies, the runtime forwards the payload to the heap (via the standard
    // shadow-stack scan) ; the stale `forward` slot left in the alloca'd
    // header is harmless since the C frame goes away on return and any
    // reuse runs `vader_obj_header_init` again.
    const auxStorage = aux(s, "storage");
    line(s, `${cname} ${auxStorage};`);
    line(s, `${cname}* ${auxObj} = &${auxStorage};`);
  } else {
    line(s, `${cname}* ${auxObj} = (${cname}*) vader_gc_alloc(sizeof(${cname}));`);
  }
  line(s, `vader_obj_header_init(${auxObj}, ${op.typeIndex}u);`);
  for (let i = 0; i < t.fields.length; i++) {
    const f = t.fields[i]!;
    const v = fieldVals[i]!;
    // Nullable-ref field stored as raw `void*` — extract payload from the
    // incoming box. `vader_box_t.payload.obj` is NULL for the null variant
    // and the heap pointer for the ref variant, which is exactly what the
    // raw slot wants.
    if (isNullableRefField(s.ctx, f.typeIndex)) {
      line(s, `${auxObj}->f_${sanitise(f.name)} = ${v.name}.payload.obj;`);
      continue;
    }
    const fval = valTypeOfField(s.ctx, f.typeIndex);
    line(s, `${auxObj}->f_${sanitise(f.name)} = ${coerce(s, v.name, v.val, fval)};`);
  }
  // Always emit struct values as boxed vader_box_t so they flow uniformly
  // through `ref` slots and across fn boundaries. struct.get unboxes via
  // .payload.obj before downcasting.
  line(s, `${tmp} = vader_box_obj(${op.typeIndex}u, ${auxObj});`);
}

export function emitStructGet(s: FnState, op: Extract<Op, { kind: "struct.get" }>): void {
  const t = s.ctx.module.types[op.typeIndex]!;
  if (t.kind !== "struct") return;
  const cname = s.ctx.structNames[op.typeIndex]!;
  const obj = pop(s);
  const f = t.fields[op.fieldIndex]!;
  const fval = valTypeOfField(s.ctx, f.typeIndex);

  // Inline-variant struct : the field's value is encoded directly in the
  // receiver box's payload. Read it via `unboxExpr` instead of dereferencing
  // through a heap struct that doesn't exist. Same exclusion as struct.new :
  // structs the module mutates anywhere keep the heap rep.
  const inlinePayload = !s.ctx.mutatedStructs.has(op.typeIndex)
    ? inlineVariantPayload(t, s.ctx.module.types)
    : null;
  if (inlinePayload === "ref") {
    // Single-ref-field : the wrapper's `payload.obj` IS the referent's
    // heap pointer. Rebox with the field's own type tag so consumers see
    // the referent (not the wrapper). `f.typeIndex` already names the
    // concrete referent struct (Entry, MapIterator, …).
    const tmp = newTmp(s, fval);
    line(s, `${tmp} = vader_box_obj(${f.typeIndex}u, ${obj.name}.payload.obj);`);
    return;
  }
  if (inlinePayload === "packed") {
    // Multi-field POD stored inline in `payload.packed[16]`. Read the
    // field through the header-less mirror struct ; the C compiler
    // resolves the offset.
    const pname = packedStructName(cname);
    const tmp = newTmp(s, fval);
    line(s, `${tmp} = ((const ${pname}*)${obj.name}.payload.packed)->f_${sanitise(f.name)};`);
    return;
  }
  if (inlinePayload !== null && inlinePayload !== "void") {
    const tmp = newTmp(s, fval);
    line(s, `${tmp} = ${coerce(s, unboxExpr(obj.name, inlinePayload), inlinePayload, fval)};`);
    return;
  }

  // Nullable-ref field stored as `void*` — read the raw pointer and box it
  // back to a `vader_box_t` so downstream ops see a uniform value rep.
  // NULL → null-tagged box ; non-null → ref-tagged box with the variant's
  // type index.
  const refVariant = b1SlotVariant(s.ctx, f.typeIndex);
  if (refVariant !== null) {
    const nullTag = s.ctx.primitiveTagOf.get("null") ?? 0;
    const tmp = newTmp(s, fval);
    const raw = `((${cname}*) ${asObjPtr(obj)})->f_${sanitise(f.name)}`;
    line(s, `${tmp} = (${raw} == NULL) ? vader_box_obj(${nullTag}u, NULL) : vader_box_obj(${refVariant}u, ${raw});`);
    return;
  }
  const tmp = newTmp(s, fval);
  line(s, `${tmp} = ((${cname}*) ${asObjPtr(obj)})->f_${sanitise(f.name)};`);
}

export function emitStructSet(
  s: FnState, op: Extract<Op, { kind: "struct.set" | "struct.set_stack" }>,
): void {
  const t = s.ctx.module.types[op.typeIndex]!;
  if (t.kind !== "struct") return;
  const cname = s.ctx.structNames[op.typeIndex]!;
  const value = pop(s);
  const obj = pop(s);
  const f = t.fields[op.fieldIndex]!;
  // Nullable-ref field — strip the value to its `.payload.obj` (NULL for the
  // null variant, the heap pointer for the ref variant) and write into the
  // raw `void*` slot.
  if (isNullableRefField(s.ctx, f.typeIndex)) {
    line(s, `((${cname}*) ${asObjPtr(obj)})->f_${sanitise(f.name)} = ${value.name}.payload.obj;`);
  } else {
    const fval = valTypeOfField(s.ctx, f.typeIndex);
    line(s, `((${cname}*) ${asObjPtr(obj)})->f_${sanitise(f.name)} = ${coerce(s, value.name, value.val, fval)};`);
  }
  // `struct.set_stack` opts out — midir's escape analysis proved the
  // target is stack-allocated, so the runtime check inside the macro would
  // be a no-op anyway.
  if (op.kind === "struct.set") {
    line(s, `VADER_WRITE_BARRIER((${cname}*) ${asObjPtr(obj)});`);
  }
}

/** True when the type at index `typeIndex` is a `T | null` union with T a
 *  single heap-type — the c-emit then stores the slot as a raw `void*`. */
function isNullableRefField(ctx: EmitCtx, typeIndex: number): boolean {
  return b1SlotVariant(ctx, typeIndex) !== null;
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
  const arrType = s.ctx.module.types[op.typeIndex];
  const elemKind = arrType !== undefined && arrType.kind === "array"
    ? arrayKindOf(s.ctx.module.types[arrType.element]!)
    : "boxed";
  const kindIdx = arrayKindIndex(elemKind);
  const elemTag = arrType !== undefined && arrType.kind === "array"
    ? arrType.element : 0;
  const arrBuf = aux(s, "arr");
  line(s, `vader_array_t* ${arrBuf} = vader_array_new(${op.typeIndex}u, ${op.length}u, ${kindIdx}u, ${elemTag}u);`);
  if (op.length > 0) {
    for (let i = 0; i < op.length; i++) {
      const v = elements[i]!;
      // Box with the element type's tag, not the array's. Without this,
      // virtual dispatch on a value read back from the array would see
      // recv.tag = array_index instead of element_index → vtable miss.
      line(s, `vader_array_set(${arrBuf}, ${i}u, ${boxExpr(s.ctx, v.name, v.val, elemTag)});`);
    }
  }
  line(s, `${tmp} = vader_box_obj(${op.typeIndex}u, ${arrBuf});`);
}

export function emitArrayGet(s: FnState, _op: Extract<Op, { kind: "array.get" }>): void {
  const idx = pop(s);
  const arr = pop(s);
  const tmp = newTmp(s, "any");
  // Tag is stamped in `vader_array_load_slot` from the buf's recorded
  // `element_tag` (set at `vader_array_new` time), so virtual dispatch on
  // a receiver coming from a primitive-storage array sees a properly-tagged
  // box even when the static type at the call site is erased to `Any[]`.
  line(s, `${tmp} = vader_array_get((vader_array_t*) ${asObjPtr(arr)}, (size_t) ${idx.name});`);
}

export function emitArraySet(s: FnState, op: Extract<Op, { kind: "array.set" }>): void {
  const value = pop(s);
  const idx = pop(s);
  const arr = pop(s);
  // Box with the element type's tag (same reasoning as `emitArrayNew`).
  const arrType = s.ctx.module.types[op.typeIndex];
  const elemTag = arrType !== undefined && arrType.kind === "array"
    ? arrType.element : op.typeIndex;
  line(s, `vader_array_set((vader_array_t*) ${asObjPtr(arr)}, (size_t) ${idx.name}, ${boxExpr(s.ctx, value.name, value.val, elemTag)});`);
}

export function emitArraySlice(s: FnState, op: Extract<Op, { kind: "array.slice" }>): void {
  const hi = pop(s);
  const lo = pop(s);
  const arr = pop(s);
  const tmp = newTmp(s, "ref");
  const arrBuf = aux(s, "arr");
  line(s, `vader_array_t* ${arrBuf} = vader_array_slice((vader_array_t*) ${asObjPtr(arr)}, (size_t) ${lo.name}, (size_t) ${hi.name});`);
  line(s, `${tmp} = vader_box_obj(${op.typeIndex}u, ${arrBuf});`);
}

export function emitDataConst(s: FnState, op: Extract<Op, { kind: "data.const" }>): void {
  // Cast-away-const : the array header in `.rodata` is logically immutable,
  // but the runtime's array.get / array.slice helpers take a non-const
  // pointer. Writers would trip `array.set` which the typechecker has
  // already forbidden (T3042) ; the cast is sound at this point.
  const tmp = newTmp(s, "ref");
  line(s, `${tmp} = vader_box_obj(${op.typeIndex}u, (void*) &__vader_data_${op.poolIndex});`);
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
      line(s, `${tmp} = ${cond};`);
    } else {
      line(s, `${tmp} = (${v.name}.tag == ${op.typeIndex}u);`);
    }
  } else {
    // Primitive slot can only match if its static ValType corresponds to the
    // target type's primitive (or struct/array typeIndex matches).
    line(s, `${tmp} = ${primitiveMatchesType(s.ctx, v.val, op.typeIndex) ? "true" : "false"};`);
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
    line(s, `${tmp} = ${unboxExpr(v.name, targetVal)};`);
  } else {
    line(s, `${tmp} = (${cTypeForVal(s.ctx, targetVal)}) ${v.name};`);
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
    line(s, `${tmp} = ${v.name};`);
  } else {
    // Cast through `from` first so signedness drives any width-change
    // extension. The stack value's C type can mismatch `from` because
    // small unsigned constants ride on `i32.const` (the bytecode has no
    // dedicated `uN.const`), so a literal like `(int32_t)UINT32_C(N)` for
    // a u32-repr enum would sign-extend on `(uint64_t) v` if we skipped
    // the inner cast.
    line(s, `${tmp} = (${cTypeForVal(s.ctx, to)}) (${cTypeForVal(s.ctx, from)}) ${v.name};`);
  }
}

export function emitTypedBinop(s: FnState, t: ValType, verb: string): void {
  if (verb === "neg" || verb === "bitnot") {
    const v = pop(s);
    const tmp = newTmp(s, t);
    const op = verb === "neg" ? "-" : "~";
    // Source `-9223372036854775808` reaches the codegen as
    // `i64.const 2^63` + `i64.neg`. The literal renders as
    // `(int64_t)UINT64_C(9223372036854775808)`, and `-INT64_MIN`
    // overflows — gcc / clang both emit a -Winteger-overflow line per
    // occurrence, and the verbose burst is noisy enough to deadlock the
    // build pipe on busy CI runners. Fold the pair into `INT64_MIN`
    // directly here.
    if (verb === "neg" && t === "i64"
        && v.name === "(int64_t)UINT64_C(9223372036854775808)") {
      line(s, `${tmp} = INT64_MIN;`);
      return;
    }
    line(s, `${tmp} = ${op}${v.name};`);
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
    line(s, `${tmp} = ${l.name} ${arith[verb]} ${r.name};`);
    return;
  }
  if (cmp[verb]) {
    const tmp = newTmp(s, "bool");
    line(s, `${tmp} = ${l.name} ${cmp[verb]} ${r.name};`);
    return;
  }
  // Unhandled — emit a trap so the failure surfaces at runtime.
  line(s, `vader_unreachable("unhandled op ${kind(t, verb)}");`);
}

export function kind(t: ValType, verb: string): string { return `${t}.${verb}`; }

