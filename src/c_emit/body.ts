// C emit — per-function body machinery. Driven from `emit.ts`'s top-level
// `emitC` orchestrator: `emitFunctions` walks the bytecode module's fn
// table and `emitFunctionBody` lays out each fn's C body — local decls,
// shadow-stack frame, value-stack tmps, structured-control labels, and
// the per-op emitters that turn each bytecode `Op` into one or more C
// lines. Vtable helpers (`emitVtableForwardDecls`,
// `emitVtableDispatchers`) live here too since they share the C output
// shape and the stack discipline.
//
// Shared C-name and ValType helpers (`cTypeFor`, `signatureFor`,
// `sanitise`, …) and the box/unbox/zero-init utilities live alongside
// because every per-op emitter needs them. `emit.ts` re-imports the ones
// the outer sections (type decls, fn trampolines, import shims, main)
// also use.

import type { BcFunction, BcImport, BcSignature, BytecodeModule } from "../bytecode/module.ts";
import type { Op } from "../bytecode/ops.ts";
import { INTRINSIC_TABLE } from "../bytecode/ops.ts";
import type { BcType, ValType } from "../bytecode/types.ts";

import type { EmitCtx } from "./emit.ts";
import { cStringLit, cStringLitFromBytes, escapeC, floatLit, i32LitC, i64LitC, sanitise } from "./emit.ts";
import { tryEmitStaticTable } from "./static_table.ts";

// =========================================================================
// Function bodies
// =========================================================================

export function emitFunctions(ctx: EmitCtx, out: string[]): void {
  for (let i = 0; i < ctx.module.functions.length; i++) {
    if (tryEmitStaticTable(ctx, ctx.module.functions[i]!, i, out)) {
      out.push(``);
      continue;
    }
    emitFunctionBody(ctx, ctx.module.functions[i]!, i, out);
    out.push(``);
  }
}

function emitFunctionBody(ctx: EmitCtx, fn: BcFunction, _fnIndex: number, out: string[]): void {
  out.push(`static ${signatureFor(ctx, fn)} {`);

  // Provably no-alloc fns skip the entire shadow-stack dance. No allocation
  // means no GC pass while inside this fn (or any of its callees) — so any
  // `&lN` we'd chain into `gc_roots[]` would never be visited. Skipping the
  // address-of also frees the C compiler's DSE pass to drop dead writes to
  // those slots.
  const noFrame = !ctx.mayAlloc.has(_fnIndex);

  // Collect addresses of every ref-typed slot that needs to be a GC root —
  // the C emit takes their `&` to pin them on the C stack and chains the
  // resulting array through the shadow stack frame. Ref-typed *tmps* are
  // gathered during body emission (via `state.refTmpIndices`); locals,
  // params and block-result slots are known up front.
  const rootAddrs: string[] = [];

  if (!noFrame) {
    for (let i = 0; i < fn.signature.params.length; i++) {
      if (isRefVal(fn.signature.params[i]!)) rootAddrs.push(`&l${i}`);
    }
  }

  // Declare local slots (params already declared in the signature). `void`
  // slots are runtime-meaningless placeholders the lowerer uses to thread
  // block-trailing exprs past `defer`s ; we skip emitting a real variable
  // and make local.{get,set,tee} on those slots be no-ops at the op-level.
  // Slots are bucketed by ValType so we can collapse same-typed locals into
  // a single comma-separated declaration — `int32_t l1=0, l2=0, l3=0;` in
  // place of one line per local. ~3-4× compression on the local-decl
  // boilerplate of fns with many primitives.
  emitLocalDecls(out, ctx, fn, noFrame ? null : rootAddrs);

  // Per-op tmp vars: every push allocates a fresh `tN`. The stack tracks
  // `{ name, val }` so we know how to coerce when crossing slot boundaries.
  const state: FnState = {
    fn, ctx,
    stack: [],
    tmpCounter: 0,
    out,
    indent: "    ",
    labels: precomputeLabels(fn),
    scopeStack: [],
    refTmpIndices: [],
    noFrame,
  };

  // Pre-declare every block result tmp so jumps can assign without scope
  // gymnastics. We do this by walking the labels table. Same write-before-
  // read invariant as locals : ref-typed slots get `vader_box_null()` (GC
  // root reachability) ; primitives skip the explicit init.
  for (const l of state.labels.openInfo) {
    if (l === null || l.resultType === "void") continue;
    const ctype = cTypeForVal(ctx, l.resultType);
    if (isRefVal(l.resultType)) {
      out.push(`    ${ctype} blockres_${l.openIp} = vader_box_null();`);
      if (!noFrame) rootAddrs.push(`&blockres_${l.openIp}`);
    } else {
      out.push(`    ${ctype} blockres_${l.openIp};`);
    }
  }

  // Reserve a position for the ref-tmp pre-declarations and the frame setup.
  // We splice these in after the body is emitted (when `refTmpIndices` and
  // `tmpCounter` are final).
  const preludePos = out.length;

  for (let ip = 0; ip < fn.body.length; ip++) {
    const op = fn.body[ip]!;
    emitOp(state, ip, op);
  }

  // Build prelude: ref-tmp declarations + gc_roots + frame push. No-alloc
  // fns (`noFrame` set) skip the gc_roots[] / gc_frame / gc_top lines —
  // they still pre-declare ref tmps for liveness, but those don't need to
  // be GC roots since no GC pass can fire while in this fn.
  const prelude: string[] = [];
  if (state.refTmpIndices.length > 0) {
    const PER_LINE = 6;
    if (!noFrame) {
      for (const idx of state.refTmpIndices) rootAddrs.push(`&t${idx}`);
    }
    for (let i = 0; i < state.refTmpIndices.length; i += PER_LINE) {
      const chunk = state.refTmpIndices.slice(i, i + PER_LINE)
        .map((idx) => `t${idx} = vader_box_null()`).join(", ");
      prelude.push(`    vader_box_t ${chunk};`);
    }
  }
  if (!noFrame) {
    if (rootAddrs.length > 0) {
      prelude.push(`    vader_box_t* gc_roots[${rootAddrs.length}] = { ${rootAddrs.join(", ")} };`);
    }
    const rootsExpr = rootAddrs.length > 0 ? `gc_roots` : `NULL`;
    prelude.push(`    vader_gc_frame_t gc_frame = { vader_gc_top, ${rootAddrs.length}u, 0u, ${rootsExpr} };`);
    prelude.push(`    vader_gc_top = &gc_frame;`);

    // Defensive pop on fall-through: if the body falls past its last op
    // without an explicit return (void fn with implicit end), restore the
    // caller's frame before returning. Explicit returns (`emitReturn`) pop
    // before issuing `return`, so this line is dead in those paths.
    out.push(`    vader_gc_top = gc_frame.prev;`);
  }

  out.splice(preludePos, 0, ...prelude);

  out.push(`}`);
}

export function isRefVal(v: ValType): boolean {
  return v === "ref" || v === "any";
}

/** Bucket the fn's locals by ValType and emit one comma-separated decl
 *  per type. Each entry pushes its `&lN` onto `rootAddrs` when ref-typed
 *  so the GC frame pins the slot. Ref/any locals carry `= vader_box_null()`
 *  because the GC scan reaches them before the user body runs ; primitives
 *  drop the explicit zero-init — the lowerer guarantees write-before-read,
 *  so an uninitialised primitive slot is never observed. Skipping the
 *  init also lets each line carry more entries (PER_LINE bumps from 6 to
 *  10) since the names are shorter. */
function emitLocalDecls(
  out: string[], ctx: EmitCtx, fn: BcFunction, rootAddrs: string[] | null,
): void {
  const buckets = new Map<ValType, number[]>();
  for (let i = 0; i < fn.locals.length; i++) {
    const local = fn.locals[i]!;
    if (local.val === "void") continue;
    const slot = fn.signature.params.length + i;
    let bucket = buckets.get(local.val);
    if (bucket === undefined) { bucket = []; buckets.set(local.val, bucket); }
    bucket.push(slot);
    if (isRefVal(local.val) && rootAddrs !== null) rootAddrs.push(`&l${slot}`);
  }
  for (const [val, slots] of buckets) {
    const ctype = cTypeForVal(ctx, val);
    if (isRefVal(val)) {
      const PER_LINE = 6;
      for (let i = 0; i < slots.length; i += PER_LINE) {
        const chunk = slots.slice(i, i + PER_LINE)
          .map((s) => `l${s} = vader_box_null()`).join(", ");
        out.push(`    ${ctype} ${chunk};`);
      }
    } else {
      const PER_LINE = 10;
      for (let i = 0; i < slots.length; i += PER_LINE) {
        const chunk = slots.slice(i, i + PER_LINE).map((s) => `l${s}`).join(", ");
        out.push(`    ${ctype} ${chunk};`);
      }
    }
  }
}

// ------------------------------------------------------------- per-fn state

/** A value sitting on the C-side stack. Three flavours :
 *
 *  - `tmp` — already materialised into a fresh `tN`. The eager case ; used
 *    for any expression with side effects, ref/any types (GC-rooted), or
 *    once a `local-ref` has been forced by an intervening write.
 *  - `literal` — a pure literal text (`"42"`, `"true"`, …). Always safe to
 *    inline at the consumer ; never invalidated.
 *  - `local-ref` — a snapshot of `lN` taken at push time. Inlined as `lN`
 *    when popped UNLESS a later `local.set/tee N` happens before the pop,
 *    in which case `materializeStackForSlot` upgrades it to a `tmp` first.
 *
 *  Lazy materialisation halves the line count on the Vader self-host
 *  output by skipping the constant-then-immediately-used boilerplate
 *  (`int32_t t6 = INT32_C(1); l4 = t6;` → `l4 = 1;`). */
type StackVal =
  | { kind: "tmp";       name: string; val: ValType }
  | { kind: "literal";   text: string; val: ValType }
  | { kind: "local-ref"; slot:  number; val: ValType };

interface FnState {
  readonly fn: BcFunction;
  readonly ctx: EmitCtx;
  readonly stack: StackVal[];
  tmpCounter: number;
  readonly out: string[];
  indent: string;
  readonly labels: LabelTable;
  readonly scopeStack: ActiveScope[];
  /** tmp indices that hold ref-typed values — pre-declared in the function
   *  prelude and registered as GC roots via the shadow stack frame. */
  readonly refTmpIndices: number[];
  /** True when the fn is provably no-alloc (per `EmitCtx.mayAlloc`). Tells
   *  `emitReturn` to skip the `vader_gc_top = gc_frame.prev` restore. */
  readonly noFrame: boolean;
}

interface OpenLabel {
  readonly openIp: number;
  readonly endIp: number;
  readonly elseIp: number;     // -1 if none
  readonly kind: "block" | "loop" | "if";
  readonly resultType: ValType;
}

/** Mutable runtime view of an `OpenLabel` while emit walks its body. The
 *  `unreachable` flag flips on after a `(br|return|unreachable)` op — tells
 *  `else`/`end` to skip the result-pop since the stack past that point is
 *  polymorphic per WASM semantics. Reset by `else` (the else branch starts
 *  reachable again). */
interface ActiveScope extends OpenLabel {
  unreachable: boolean;
}

interface LabelTable {
  readonly openInfo: readonly (OpenLabel | null)[];   // one entry per ip
  readonly endOf:    ReadonlyMap<number, number>;
  readonly elseOf:   ReadonlyMap<number, number>;
  readonly endOfElse: ReadonlyMap<number, number>;
}

function precomputeLabels(fn: BcFunction): LabelTable {
  const openInfo: (OpenLabel | null)[] = new Array(fn.body.length).fill(null);
  const endOf = new Map<number, number>();
  const elseOf = new Map<number, number>();
  const endOfElse = new Map<number, number>();
  type Stk = { openIp: number; kind: "block" | "loop" | "if"; resultType: ValType; elseIp: number };
  const stk: Stk[] = [];
  for (let i = 0; i < fn.body.length; i++) {
    const op = fn.body[i]!;
    if (op.kind === "block" || op.kind === "loop" || op.kind === "if") {
      stk.push({ openIp: i, kind: op.kind, resultType: op.result, elseIp: -1 });
    } else if (op.kind === "else") {
      const top = stk[stk.length - 1];
      if (top !== undefined) { top.elseIp = i; elseOf.set(top.openIp, i); }
    } else if (op.kind === "end") {
      const top = stk.pop();
      if (top !== undefined) {
        endOf.set(top.openIp, i);
        if (top.elseIp >= 0) endOfElse.set(top.elseIp, i);
        openInfo[top.openIp] = { openIp: top.openIp, endIp: i, elseIp: top.elseIp,
                                  kind: top.kind, resultType: top.resultType };
      }
    }
  }
  return { openInfo, endOf, elseOf, endOfElse };
}

// ------------------------------------------------------------- op dispatch

function emitOp(s: FnState, ip: number, op: Op): void {
  const k = op.kind;
  switch (k) {
    case "drop":     s.stack.pop(); return;
    case "dup": {
      // Push the same StackVal — literals + local-refs are safe to share ;
      // tmps just reference the same name. Each consumer reads consistently.
      const top = s.stack[s.stack.length - 1];
      if (top !== undefined) s.stack.push(top);
      return;
    }

    case "local.get": {
      const val = slotValType(s, op.slot);
      if (val === "void") return;       // void slots: no real storage, no push
      // Inline `lN` for primitives (no GC concern) ; for ref/any, snapshot
      // into a refTmp so the value stays a GC root through any intervening
      // allocation. C may otherwise evaluate `l0.payload.obj` *before* a
      // sibling alloc arg, leaving a stale pointer post-collection.
      if (val === "ref" || val === "any") {
        const t = newTmp(s, val);
        line(s, `${decl(s, val, t)} = l${op.slot};`);
      } else {
        pushLocalRef(s, op.slot, val);
      }
      return;
    }
    case "local.set": {
      const slotVal = slotValType(s, op.slot);
      if (slotVal === "void") return;   // void slots: nothing on the stack to consume
      materializeStackForSlot(s, op.slot);
      const v = pop(s);
      line(s, `l${op.slot} = ${coerce(s, v.name, v.val, slotVal)};`);
      return;
    }
    case "local.tee": {
      const slotVal = slotValType(s, op.slot);
      if (slotVal === "void") return;
      materializeStackForSlot(s, op.slot);
      const v = pop(s);
      line(s, `l${op.slot} = ${coerce(s, v.name, v.val, slotVal)};`);
      // Push a fresh snapshot — primitives inline as `lN`, refs/any need
      // a refTmp for GC-precision (see local.get).
      if (slotVal === "ref" || slotVal === "any") {
        const t = newTmp(s, slotVal);
        line(s, `${decl(s, slotVal, t)} = l${op.slot};`);
      } else {
        pushLocalRef(s, op.slot, slotVal);
      }
      return;
    }

    case "i32.const":    return pushLit(s, "i32", i32LitC(op.value));
    case "i64.const":    return pushLit(s, "i64", i64LitC(op.value));
    case "f32.const":    return pushLit(s, "f32", floatLit(op.value, "f"));
    case "f64.const":    return pushLit(s, "f64", floatLit(op.value, ""));
    case "bool.const":   return pushLit(s, "bool", op.value ? "true" : "false");
    case "char.const":   return pushLit(s, "char", `${op.value}u`);
    case "null.const": {
      // Tag the null literal with the `null` primitive's BcType index when
      // it's available — keeps `type_check` semantics consistent across
      // boxed and unboxed paths.
      const tag = s.ctx.primitiveTagOf.get("null") ?? 0;
      return pushLit(s, "any", `vader_box_obj(${tag}u, NULL)`);
    }
    case "string.const":
      // Pool entry is already a `vader_string_t` static — push by name
      // and let the consumer copy it inline. No allocation, no temp.
      pushLit(s, "string", `vader_str_${op.index}`);
      return;

    case "bool.and":   return pushBinop(s, "bool", "&&", "bool");
    case "bool.or":    return pushBinop(s, "bool", "||", "bool");
    case "bool.not":   return pushUnop(s, "bool", "!", "bool");

    case "string.concat": return pushFnCall2(s, "string", "vader_string_concat");
    case "string.eq":  return pushFnCall2(s, "bool", "vader_string_eq");
    case "string.ne": {
      const r = pop(s); const l = pop(s);
      const t = newTmp(s, "bool");
      line(s, `bool ${t} = !vader_string_eq(${l.name}, ${r.name});`);
      return;
    }
    case "char.eq":    return pushBinop(s, "char", "==", "bool");
    case "char.ne":    return pushBinop(s, "char", "!=", "bool");
    case "char.lt":    return pushBinop(s, "char", "<",  "bool");
    case "char.le":    return pushBinop(s, "char", "<=", "bool");
    case "char.gt":    return pushBinop(s, "char", ">",  "bool");
    case "char.ge":    return pushBinop(s, "char", ">=", "bool");
    case "bool.eq":    return pushBinop(s, "bool", "==", "bool");
    case "bool.ne":    return pushBinop(s, "bool", "!=", "bool");
    case "ref.eq":     return pushBinopAny(s, "==", "bool");
    case "ref.ne":     return pushBinopAny(s, "!=", "bool");

    case "block":
    case "loop":
    case "if":         return emitOpenScope(s, ip, op);
    case "else":       return emitElse(s, ip);
    case "end":        return emitEnd(s, ip);
    case "br":         return emitBr(s, ip, op.depth, /*conditional*/ false);
    case "br_if":      return emitBr(s, ip, op.depth, /*conditional*/ true);
    case "return":     return emitReturn(s);
    case "unreachable":
      line(s, `vader_unreachable("${escapeC(s.fn.name)}+${ip}");`);
      markUnreachable(s);
      return;

    case "call":         return emitCall(s, op);
    case "call.import":  return emitCallImport(s, op);
    case "call.indirect":return emitCallIndirect(s, op);
    case "virtual.call": return emitVirtualCall(s, op);
    case "fn.ref":       return emitFnRef(s, op);
    case "make_closure": return emitMakeClosure(s, op);
    case "intrinsic":    return emitIntrinsic(s, op);

    case "struct.new":   return emitStructNew(s, op, /*onStack*/ false);
    case "struct.new_stack": return emitStructNew(s, op, /*onStack*/ true);
    case "struct.get":   return emitStructGet(s, op);
    case "struct.set":   return emitStructSet(s, op);

    case "array.new":    return emitArrayNew(s, op);
    case "array.get":    return emitArrayGet(s, op);
    case "array.set":    return emitArraySet(s, op);
    case "array.len": {
      const arr = pop(s);
      const t = newTmp(s, "usize");
      line(s, `size_t ${t} = vader_array_len((vader_array_t*) ${asObjPtr(arr)});`);
      return;
    }
    case "array.push": {
      const value = pop(s);
      const arr = pop(s);
      line(s, `vader_array_push((vader_array_t*) ${asObjPtr(arr)}, ${boxExpr(s.ctx, value.name, value.val, op.typeIndex)});`);
      return;
    }

    case "type_check":   return emitTypeCheck(s, op);
    case "ref.cast":     return emitRefCast(s, op);
  }

  // Templated typed numeric ops: <type>.<verb> or <type>.to_<type>
  emitNumericOp(s, k);
}

// ------------------------------------------------------------- structured control

function emitOpenScope(s: FnState, ip: number, op: Op): void {
  const info = labelOf(s, ip);
  if (info !== null) s.scopeStack.push({ ...info, unreachable: false });
  if (op.kind === "if") {
    const cond = pop(s);
    line(s, `if (${cond.name}) {`);
    s.indent += "    ";
    return;
  }
  if (op.kind === "loop") {
    line(s, `loop_${ip}: {`);
    s.indent += "    ";
    return;
  }
  if (op.kind === "block") {
    line(s, `{`);
    s.indent += "    ";
    return;
  }
}

function emitElse(s: FnState, ip: number): void {
  // Close the then-branch's resultPush, then open else. If the then-branch
  // ended unreachable, `blockres_X` keeps its zeroInit value — control never
  // reaches it (polymorphic-stack invariant).
  const info = scopeForElseEnd(s, ip);
  const top = s.scopeStack.at(-1);
  const wasUnreachable = top?.unreachable ?? false;
  if (info !== null && info.resultType !== "void" && !wasUnreachable && s.stack.length > 0) {
    const v = pop(s);
    line(s, `blockres_${info.openIp} = ${coerce(s, v.name, v.val, info.resultType)};`);
  }
  if (top !== undefined) top.unreachable = false;     // else branch is reachable
  popIndent(s);
  line(s, `} else { /* else */`);
  s.indent += "    ";
}

function emitEnd(s: FnState, ip: number): void {
  const info = scopeForEnd(s, ip);
  const top = s.scopeStack.at(-1);
  const wasUnreachable = top?.unreachable ?? false;
  if (info !== null && info.resultType !== "void" && !wasUnreachable && s.stack.length > 0) {
    const v = pop(s);
    line(s, `blockres_${info.openIp} = ${coerce(s, v.name, v.val, info.resultType)};`);
  }
  popIndent(s);
  if (info !== null) {
    line(s, `} end_${info.openIp}: ;`);
    s.scopeStack.pop();
    if (info.resultType !== "void") {
      const t = newTmp(s, info.resultType);
      line(s, `${decl(s, info.resultType, t)} = blockres_${info.openIp};`);
    }
  } else {
    line(s, `}`);
  }
}

function markUnreachable(s: FnState): void {
  const top = s.scopeStack.at(-1);
  if (top !== undefined) top.unreachable = true;
}

function emitBr(s: FnState, _ip: number, depth: number, conditional: boolean): void {
  // Walk the open scopes via the label table — at any point, the active label
  // stack consists of all `OpenLabel`s whose [openIp, endIp) range contains
  // the current ip. We can rebuild it by counting active scopes.
  const active = activeScopes(s);
  const idx = active.length - 1 - depth;
  if (idx < 0) { line(s, `/* br depth ${depth} out of range */`); return; }
  const target = active[idx]!;
  // Loop targets jump back to the loop start (continue); block/if jump past end.
  const dest = target.kind === "loop" ? `loop_${target.openIp}` : `end_${target.openIp}`;

  const condGuard = (body: string) => conditional
    ? `if (${pop(s).name}) { ${body} }`
    : body;

  // Block/if branch with a result: hoist top-of-stack into the block's result
  // before jumping. WASM verifier guarantees the type matches.
  if (target.kind !== "loop" && target.resultType !== "void" && s.stack.length > 0) {
    const v = peek(s);
    line(s, condGuard(`blockres_${target.openIp} = ${coerce(s, v.name, v.val, target.resultType)}; goto ${dest};`));
  } else {
    line(s, condGuard(`goto ${dest};`));
  }
  // Unconditional `br` makes the rest of the enclosing scope unreachable —
  // tells `else`/`end` not to pop a stale top-of-stack as the result.
  if (!conditional) markUnreachable(s);
}

function activeScopes(s: FnState): OpenLabel[] {
  return s.scopeStack;
}

function emitReturn(s: FnState): void {
  // Pop the shadow-stack frame first, then return. For non-void returns we
  // capture the value into a tmp before popping (the expression may read from
  // frame-pinned locals — capturing a snapshot makes the order safe).
  // No-frame fns skip the `gc_top` restore — there's no frame to pop.
  if (s.fn.signature.result === "void") {
    line(s, s.noFrame ? `return;` : `{ vader_gc_top = gc_frame.prev; return; }`);
  } else {
    const v = pop(s);
    const ret = coerce(s, v.name, v.val, s.fn.signature.result);
    if (s.noFrame) {
      line(s, `return ${ret};`);
    } else {
      const cret = cTypeForVal(s.ctx, s.fn.signature.result);
      line(s, `{ ${cret} __vret = ${ret}; vader_gc_top = gc_frame.prev; return __vret; }`);
    }
  }
  markUnreachable(s);
}

// ------------------------------------------------------------- calls

function emitCall(s: FnState, op: Extract<Op, { kind: "call" }>): void {
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

function emitCallImport(s: FnState, op: Extract<Op, { kind: "call.import" }>): void {
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

function emitFnRef(s: FnState, op: Extract<Op, { kind: "fn.ref" }>): void {
  const tmp = newTmp(s, "ref");
  line(s, `${decl(s, "ref", tmp)} = vader_box_obj(${op.typeIndex}u, &vader_fn_static_${op.fnIndex});`);
}

function emitVirtualCall(s: FnState, op: Extract<Op, { kind: "virtual.call" }>): void {
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

function vtableHelperName(key: string): string {
  return `vader_vt_${sanitise(key.replace(".", "__"))}`;
}

/** Per-vtable canonical signature, derived from the first impl fn in each
 *  table. All impls of a given trait method share their non-receiver param
 *  types (the receiver is taken as `any`/`vader_box_t` in the dispatcher). */
function vtableSignatures(ctx: EmitCtx): ReadonlyMap<string, BcSignature> {
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

function emitMakeClosure(s: FnState, op: Extract<Op, { kind: "make_closure" }>): void {
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

function emitCallIndirect(s: FnState, op: Extract<Op, { kind: "call.indirect" }>): void {
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

function emitIntrinsic(s: FnState, op: Extract<Op, { kind: "intrinsic" }>): void {
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

function displayFnFor(v: ValType): string {
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

function displayCoerce(name: string, v: ValType): string {
  if (v === "i8" || v === "i16") return `(int32_t) ${name}`;
  if (v === "u8" || v === "u16") return `(uint32_t) ${name}`;
  return name;
}

// ------------------------------------------------------------- struct / array

function emitStructNew(
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

function emitStructGet(s: FnState, op: Extract<Op, { kind: "struct.get" }>): void {
  const t = s.ctx.module.types[op.typeIndex]!;
  if (t.kind !== "struct") return;
  const cname = s.ctx.structNames[op.typeIndex]!;
  const obj = pop(s);
  const f = t.fields[op.fieldIndex]!;
  const fval = valTypeOfField(s.ctx, f.typeIndex);
  const tmp = newTmp(s, fval);
  line(s, `${decl(s, fval, tmp)} = ((${cname}*) ${asObjPtr(obj)})->f_${sanitise(f.name)};`);
}

function emitStructSet(s: FnState, op: Extract<Op, { kind: "struct.set" }>): void {
  const t = s.ctx.module.types[op.typeIndex]!;
  if (t.kind !== "struct") return;
  const cname = s.ctx.structNames[op.typeIndex]!;
  const value = pop(s);
  const obj = pop(s);
  const f = t.fields[op.fieldIndex]!;
  const fval = valTypeOfField(s.ctx, f.typeIndex);
  line(s, `((${cname}*) ${asObjPtr(obj)})->f_${sanitise(f.name)} = ${coerce(s, value.name, value.val, fval)};`);
}

/** Coerce a stack value holding a heap reference to a `void*`. Boxed values
 *  (vader_box_t) need `.payload.obj`; typed pointer slots (struct/array C
 *  variables) are usable directly. */
function asObjPtr(v: { name: string; val: ValType }): string {
  if (v.val === "ref" || v.val === "any") return `${v.name}.payload.obj`;
  return v.name;
}

function emitArrayNew(s: FnState, op: Extract<Op, { kind: "array.new" }>): void {
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

function emitArrayGet(s: FnState, _op: Extract<Op, { kind: "array.get" }>): void {
  const idx = pop(s);
  const arr = pop(s);
  const tmp = newTmp(s, "any");
  line(s, `${decl(s, "any", tmp)} = vader_array_get((vader_array_t*) ${asObjPtr(arr)}, (size_t) ${idx.name});`);
}

function emitArraySet(s: FnState, op: Extract<Op, { kind: "array.set" }>): void {
  const value = pop(s);
  const idx = pop(s);
  const arr = pop(s);
  line(s, `vader_array_set((vader_array_t*) ${asObjPtr(arr)}, (size_t) ${idx.name}, ${boxExpr(s.ctx, value.name, value.val, op.typeIndex)});`);
}

function emitTypeCheck(s: FnState, op: Extract<Op, { kind: "type_check" }>): void {
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
function traitCheckExpr(ctx: EmitCtx, vName: string, traitName: string, refTypeIndex: number): string {
  const structIdxs = ctx.structIdxsByTrait.get(traitName) ?? [];
  const tags = [refTypeIndex, ...structIdxs];
  return tags.map((idx) => `(${vName}.tag == ${idx}u)`).join(" || ");
}

function emitRefCast(s: FnState, op: Extract<Op, { kind: "ref.cast" }>): void {
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

function emitNumericOp(s: FnState, kind: string): void {
  // <type>.to_<type> or <type>.<verb>
  const dot = kind.indexOf(".");
  const t = kind.slice(0, dot);
  const verb = kind.slice(dot + 1);
  if (verb.startsWith("to_")) return emitConvert(s, t as ValType, verb.slice(3) as ValType);
  emitTypedBinop(s, t as ValType, verb);
}

function emitConvert(s: FnState, from: ValType, to: ValType): void {
  const v = pop(s);
  const tmp = newTmp(s, to);
  if (from === to) {
    line(s, `${decl(s, to, tmp)} = ${v.name};`);
  } else {
    line(s, `${decl(s, to, tmp)} = (${cTypeForVal(s.ctx, to)}) ${v.name};`);
  }
}

function emitTypedBinop(s: FnState, t: ValType, verb: string): void {
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

function kind(t: ValType, verb: string): string { return `${t}.${verb}`; }

// ------------------------------------------------------------- helpers

function pushBinop(s: FnState, _t: ValType, op: string, resultT: ValType): void {
  const r = pop(s); const l = pop(s);
  const tmp = newTmp(s, resultT);
  line(s, `${decl(s, resultT, tmp)} = ${l.name} ${op} ${r.name};`);
}

function pushBinopAny(s: FnState, op: string, resultT: ValType): void {
  const r = pop(s); const l = pop(s);
  const tmp = newTmp(s, resultT);
  // Box/ref equality: compare object identity for heap kinds. With γ
  // representation, both sides are `void*` if they're refs, so direct compare.
  line(s, `${decl(s, resultT, tmp)} = (${l.name} ${op} ${r.name});`);
}

function pushUnop(s: FnState, _t: ValType, op: string, resultT: ValType): void {
  const v = pop(s);
  const tmp = newTmp(s, resultT);
  line(s, `${decl(s, resultT, tmp)} = ${op}${v.name};`);
}

function pushFnCall2(s: FnState, resultT: ValType, fn: string): void {
  const r = pop(s); const l = pop(s);
  const tmp = newTmp(s, resultT);
  line(s, `${decl(s, resultT, tmp)} = ${fn}(${l.name}, ${r.name});`);
}

/** Push a pure literal — the text is stashed on the stack and inlined at
 *  the consumer site. No `Type tN = lit;` line is emitted. */
function pushLit(s: FnState, t: ValType, lit: string): void {
  s.stack.push({ kind: "literal", text: lit, val: t });
}

/** Push a snapshot of `lN` taken at this point. The pop site reads back
 *  `lN` directly UNLESS an intervening `local.set/tee` on the same slot
 *  forces a materialisation (see `materializeStackForSlot`). */
function pushLocalRef(s: FnState, slot: number, val: ValType): void {
  s.stack.push({ kind: "local-ref", slot, val });
}

/** Materialise a fresh `tN` on the stack and emit its declaration. Used
 *  by every push that produces a value with side effects (calls, allocs,
 *  ops between non-literals, ref/any results). */
function newTmp(s: FnState, val: ValType): string {
  const idx = s.tmpCounter++;
  const name = `t${idx}`;
  s.stack.push({ kind: "tmp", name, val });
  if (val === "ref" || val === "any") s.refTmpIndices.push(idx);
  return name;
}

/** Tmp declaration prefix. Ref-typed tmps are pre-declared in the prelude
 *  (see `emitFunctionBody`) so they can be `&`-taken into the GC root array;
 *  body emission produces a bare assignment for them. Primitives still get a
 *  fresh `<ctype> name` declaration on first use. */
function decl(s: FnState, val: ValType, name: string): string {
  if (val === "ref" || val === "any") return name;
  return `${cTypeForVal(s.ctx, val)} ${name}`;
}

/** Inline-able C text for a stack value. Literals expand to their text,
 *  tmps to the tmp name, local-refs to `lN`. */
function nameOf(v: StackVal): string {
  switch (v.kind) {
    case "tmp":       return v.name;
    case "literal":   return v.text;
    case "local-ref": return `l${v.slot}`;
  }
}

function pop(s: FnState): { name: string; val: ValType } {
  const v = s.stack.pop();
  if (v === undefined) return { name: "0", val: "i32" };  // defensive — emitter bug
  return { name: nameOf(v), val: v.val };
}

function peek(s: FnState): { name: string; val: ValType } {
  const v = s.stack[s.stack.length - 1];
  if (v === undefined) return { name: "0", val: "i32" };
  return { name: nameOf(v), val: v.val };
}

/** Before a `local.set/tee N` mutates `lN`, force every stack entry that
 *  references `lN` to snapshot its current value into a fresh tmp.
 *  Without this, popping a `local-ref{slot:N}` after the set would read
 *  the *new* value of `lN` instead of the old one. */
function materializeStackForSlot(s: FnState, slot: number): void {
  for (let i = 0; i < s.stack.length; i++) {
    const v = s.stack[i]!;
    if (v.kind !== "local-ref" || v.slot !== slot) continue;
    const idx = s.tmpCounter++;
    const name = `t${idx}`;
    line(s, `${decl(s, v.val, name)} = l${v.slot};`);
    if (v.val === "ref" || v.val === "any") s.refTmpIndices.push(idx);
    s.stack[i] = { kind: "tmp", name, val: v.val };
  }
}

function line(s: FnState, code: string): void { s.out.push(`${s.indent}${code}`); }

function popIndent(s: FnState): void { s.indent = s.indent.slice(4); }

function slotValType(s: FnState, slot: number): ValType {
  if (slot < s.fn.signature.params.length) return s.fn.signature.params[slot]!;
  return s.fn.locals[slot - s.fn.signature.params.length]!.val;
}

function labelOf(s: FnState, ip: number): OpenLabel | null {
  return s.labels.openInfo[ip] ?? null;
}

function scopeForElseEnd(s: FnState, elseIp: number): OpenLabel | null {
  // Find the open scope whose elseIp matches.
  for (const info of s.labels.openInfo) {
    if (info !== null && info.elseIp === elseIp) return info;
  }
  return null;
}

function scopeForEnd(s: FnState, endIp: number): OpenLabel | null {
  for (const info of s.labels.openInfo) {
    if (info !== null && info.endIp === endIp) return info;
  }
  return null;
}

// ------------------------------------------------------------- coercions

function coerce(s: FnState, name: string, from: ValType, to: ValType): string {
  return coerceExpr(s.ctx, name, from, to);
}

/** Pure-expression coerce — no FnState, no `line(s, ...)` side effects.
 *  Used by the per-vtable dispatchers emitted at module scope where there
 *  is no enclosing fn state. */
function coerceExpr(ctx: EmitCtx, name: string, from: ValType, to: ValType): string {
  if (from === to) return name;
  if ((to === "ref" || to === "any") && (from === "ref" || from === "any")) return name;
  if (to === "ref" || to === "any") {
    return boxExprUnknown(ctx, name, from);
  }
  if (from === "ref" || from === "any") {
    return unboxExpr(name, to);
  }
  return `(${cTypeForVal(ctx, to)}) ${name}`;
}

export function boxExpr(_ctx: EmitCtx, name: string, val: ValType, typeIndex: number): string {
  switch (val) {
    case "i8": case "i16": case "i32": return `vader_box_i32(${typeIndex}u, ${name})`;
    case "u8": case "u16": case "u32": return `vader_box_i32(${typeIndex}u, (int32_t)(uint32_t) ${name})`;
    case "i64":  return `vader_box_i64(${typeIndex}u, ${name})`;
    case "isize": return `vader_box_i64(${typeIndex}u, (int64_t) ${name})`;
    case "u64": case "usize": return `vader_box_i64(${typeIndex}u, (int64_t)(uint64_t) ${name})`;
    case "f32":  return `vader_box_f64(${typeIndex}u, (double) ${name})`;
    case "f64":  return `vader_box_f64(${typeIndex}u, ${name})`;
    case "bool": return `vader_box_bool(${typeIndex}u, ${name})`;
    case "char": return `vader_box_i32(${typeIndex}u, (int32_t) ${name})`;
    case "string": return `vader_box_string(${typeIndex}u, ${name})`;
    case "null":   return name;     // keep source tag — vader_box_null() has tag=0, collides with type-table[0]
    case "void":   return `vader_box_null()`;
    case "ref": case "any": return name;
  }
}

export function boxExprUnknown(ctx: EmitCtx, name: string, val: ValType): string {
  // Used when boxing without an explicit target type-index (e.g. passing a
  // primitive-typed value into a `ref` slot via a fn call). The right tag is
  // the BcType index of this primitive in the module's type table; if the
  // type isn't materialised (no use site referenced it), we fall back to 0
  // and the receiver's `type_check` will simply miss.
  const tag = ctx.primitiveTagOf.get(val) ?? 0;
  return boxExpr(ctx, name, val, tag);
}

export function unboxExpr(name: string, target: ValType): string {
  switch (target) {
    case "i8": case "i16": case "i32": case "u8": case "u16": case "u32":
    case "i64": case "isize": case "u64": case "usize": case "char":
      return `((${cTypeForValBare(target)}) ${name}.payload.i)`;
    case "f32": case "f64":
      return `((${cTypeForValBare(target)}) ${name}.payload.f)`;
    case "bool":   return `${name}.payload.b`;
    case "string": return `${name}.payload.s`;
    case "null":   return name;     // see boxExpr
    case "void":   return `((void) 0)`;
    case "ref": case "any": return name;
  }
}

export function cTypeForValBare(v: ValType): string {
  switch (v) {
    case "i8":  return "int8_t";
    case "i16": return "int16_t";
    case "i32": return "int32_t";
    case "i64": return "int64_t";
    case "u8":  return "uint8_t";
    case "u16": return "uint16_t";
    case "u32": return "uint32_t";
    case "u64": return "uint64_t";
    case "usize": return "size_t";
    case "isize": return "ptrdiff_t";
    case "f32": return "float";
    case "f64": return "double";
    case "bool":return "bool";
    case "char":return "uint32_t";
    case "string": return "vader_string_t";
    case "null": return "vader_box_t";    // null is a tagged box at runtime
    case "void": return "void";
    case "ref": case "any": return "vader_box_t";
  }
}

export function cTypeForVal(_ctx: EmitCtx, v: ValType): string {
  return cTypeForValBare(v);
}

export function valTypeOfField(_ctx: EmitCtx, _typeIndex: number): ValType {
  const t = _ctx.module.types[_typeIndex]!;
  return valTypeOfBcType(t);
}

export function valTypeOfBcType(t: BcType): ValType {
  switch (t.kind) {
    case "primitive": return t.val;
    case "struct":
    case "array":
    case "ref":
    case "fn":
      return "ref";
    case "union":
      return "ref";
  }
}

export function cTypeFor(_ctx: EmitCtx, t: BcType): string {
  switch (t.kind) {
    case "primitive": return cTypeForValBare(t.val);
    // All heap types are stored as `vader_box_t` everywhere (locals, struct
    // fields, array elements). This keeps boxing/unboxing localised to the
    // value coercion helper and avoids type mismatches between the value
    // stack and struct field storage.
    case "struct":
    case "array":
    case "union":
    case "ref":
    case "fn":
      return `vader_box_t`;
  }
}

export function primitiveMatchesType(ctx: EmitCtx, slotVal: ValType, typeIndex: number): boolean {
  const t = ctx.module.types[typeIndex]!;
  if (t.kind === "primitive") return t.val === slotVal;
  return false;
}

export function zeroInit(_ctx: EmitCtx, v: ValType): string {
  switch (v) {
    case "i8": case "i16": case "i32": case "u8": case "u16": case "u32":
    case "i64": case "isize": case "u64": case "usize": case "char":
      return "0";
    case "f32": case "f64": return "0.0";
    case "bool": return "false";
    case "string": return "(vader_string_t){0}";
    case "null":   return "vader_box_null()";
    case "void":   return "0";
    case "ref": case "any":  return "vader_box_null()";
  }
}

export function signatureFor(ctx: EmitCtx, fn: BcFunction): string {
  const params = fn.signature.params.map((p, i) => `${cTypeForVal(ctx, p)} l${i}`).join(", ");
  const ret = cTypeForVal(ctx, fn.signature.result);
  const cret = ret === "void" ? "void" : ret;
  return `${cret} ${sanitise(fn.name)}(${params || "void"})`;
}

