// Detect fns that match the `match enum -> StructLit constant` shape
// and emit a static lookup table + indexed return instead of the cascade.
//
// Recognised pattern (post-Rule-6 bytecode):
//
//     local.get 0        ; copy param into a synthetic scrut local
//     local.set 1
//     local.get 1        ; arm 0 cmp
//     <intConst> K0      ; variant tag literal
//     <intConst>.to_<P>  ; optional narrow when scrut type is u8/i16
//     <P>.eq
//     if void
//       <constField0_0>; <constField1_0>; ... ; struct.new TAG ; return
//     else
//       local.get 1      ; arm 1 cmp (same scrut local)
//       <intConst> K1
//       ...
//       if void
//         <body>; struct.new TAG; return
//       else
//         ... recursive ...
//         else
//           unreachable
//         end
//       end
//     end
//
// Constraints :
//   - Exactly one primitive int param (i8/u8/i16/u16/i32/u32).
//   - Returns `ref` (a struct).
//   - Cascade variants are dense 0..N-1.
//   - Every arm body produces a struct of the SAME type via constant fields.
//   - Default (innermost else) is `unreachable`.
//
// When matched, we emit:
//   static const <CType> TABLE[N] = { { /*hdr*/ }, field0, field1 } x N};
//   static <ret> info(<P> l0) {
//     return vader_box_obj(TAG, (void*)(uintptr_t)&TABLE[l0]);
//   }
//
// Pre-requisite : the runtime GC skips pointers outside the from-space arena
// (vader_runtime.c), so the static table never moves and never tries to
// follow its `forward` slot.

import type { BcFunction, BytecodeModule } from "../bytecode/module.ts";
import type { Op } from "../bytecode/ops.ts";
import type { BcType, ValType } from "../bytecode/types.ts";

/** Two flavours of static-table emission, picked by the fn's result type :
 *  - `struct` — fn returns a struct ref. Table holds full struct values
 *    (header + fields), boxed at the call site via `vader_box_obj`.
 *  - `primitive` — fn returns a scalar (string, int, bool, char, float).
 *    Table holds the bare values, returned directly. */
type StaticTableInfo = StaticTableStructInfo | StaticTablePrimitiveInfo;

interface StaticTableStructInfo {
  readonly kind: "struct";
  readonly scrutValType: ValType;        // i8/u8/i16/u16/i32/u32 (param type)
  readonly resultStructIndex: number;     // BcType index of the result struct
  readonly resultStructName: string;      // "Foo" → emitted as vader_struct_Foo_t
  readonly fields: readonly StaticField[];   // one per struct field, in decl order
  readonly entries: readonly (readonly ConstValue[])[];  // [variantIdx][fieldIdx]
}

interface StaticTablePrimitiveInfo {
  readonly kind: "primitive";
  readonly scrutValType: ValType;        // param type
  readonly resultValType: ValType;        // string / i32 / bool / etc.
  readonly resultCType: string;
  readonly entries: readonly ConstValue[];  // one per variant
}

interface StaticField {
  readonly name: string;
  readonly cType: string;                 // "vader_string_t", "int32_t", ...
  readonly val: ValType;
}

type ConstValue =
  | { kind: "int";    valType: ValType; value: bigint }     // covers i32/u8/etc.
  | { kind: "float";  valType: ValType; value: number }
  | { kind: "bool";   value: boolean }
  | { kind: "char";   value: number }
  | { kind: "string"; index: number }
  | { kind: "null" };

/** Try to detect+emit the static-table form. Returns true if emitted (the
 *  caller should skip the default fn body emission). */
export function tryEmitStaticTable(
  ctx: { module: BytecodeModule; structNames: readonly (string | null)[]; fnNames: readonly string[] },
  fn: BcFunction, fnIdx: number, out: string[],
): boolean {
  const info = detectStaticTable(ctx.module, fn);
  if (info === null) return false;

  const fnName = ctx.fnNames[fnIdx]!;
  const tableName = `vader_static_table_${fnName}`;
  const paramCType = cTypeForPrim(info.scrutValType);

  if (info.kind === "struct") {
    const tag = info.resultStructIndex;
    out.push(`static const ${info.resultStructName} ${tableName}[${info.entries.length}] = {`);
    for (const entry of info.entries) {
      const fieldInits = entry.map((cv, i) => renderConstValue(cv, info.fields[i]!.val, info.fields[i]!.cType)).join(", ");
      out.push(`    { { ${tag}u, 0u, NULL }, ${fieldInits} },`);
    }
    out.push(`};`);
    out.push(`static vader_box_t ${fnName}(${paramCType} l0) {`);
    out.push(`    return vader_box_obj(${tag}u, (void*)(uintptr_t)&${tableName}[l0]);`);
    out.push(`}`);
  } else {
    const inits = info.entries.map((cv) => renderConstValue(cv, info.resultValType, info.resultCType)).join(", ");
    out.push(`static const ${info.resultCType} ${tableName}[${info.entries.length}] = { ${inits} };`);
    out.push(`static ${info.resultCType} ${fnName}(${paramCType} l0) {`);
    out.push(`    return ${tableName}[l0];`);
    out.push(`}`);
  }
  return true;
}

function detectStaticTable(m: BytecodeModule, fn: BcFunction): StaticTableInfo | null {
  // 1. Signature gate.
  if (fn.signature.params.length !== 1) return null;
  const paramVal = fn.signature.params[0]!;
  if (!INT_VALS.has(paramVal)) return null;
  const resultVal = fn.signature.result;
  if (resultVal === "void" || resultVal === "any") return null;
  // Result must be either a ref (struct) or a primitive we can table.
  const isStructResult = resultVal === "ref";
  const isPrimResult = !isStructResult && (PRIMITIVE_VALS.has(resultVal) || resultVal === "string");
  if (!isStructResult && !isPrimResult) return null;

  // 2. Locate the synthetic scrut local.
  const body = fn.body;
  if (body.length < 4) return null;
  if (body[0]!.kind !== "local.get" || body[0]!.slot !== 0) return null;
  if (body[1]!.kind !== "local.set") return null;
  const scrutSlot = body[1]!.slot;

  // 3. Walk the cascade. Two arm-body shapes are accepted :
  //  - "return" form : arm = `<consts>; (struct.new)?; return` — the fn is
  //    expression-bodied (`fn(c) = match c { ... }`), each arm returns
  //    directly. Innermost else must be `unreachable` for exhaustiveness.
  //  - "set" form : arm = `<consts>; (struct.new)?; local.set INNER` — the
  //    fn is block-bodied, the match's value flows through a per-level
  //    result-propagation chain (`end; local.get N; local.set N+1`) up to
  //    a final slot the fn reads-and-returns. Innermost else terminates
  //    the cascade with another `<consts>; (struct.new)?; local.set INNER`
  //    (the `_` wildcard arm) and the propagation chain handles the rest.
  const cases: Array<{ k: bigint; bodyOps: Op[] }> = [];
  let defaultBodyOps: Op[] | null = null;
  let armShape: "return" | "set" | null = null;
  let ip = 2;
  let resultStructIdx: number | null = null;

  while (true) {
    const armStart = parseArmHead(body, ip, scrutSlot);
    if (armStart === null) return null;
    ip = armStart.bodyStartIp;

    const armParse = parseArmBody(body, ip, isStructResult, armShape);
    if (armParse === null) return null;
    if (armShape === null) armShape = armParse.shape;
    if (isStructResult) {
      if (resultStructIdx === null) resultStructIdx = armParse.structIdx!;
      else if (resultStructIdx !== armParse.structIdx) return null;
    }
    cases.push({ k: armStart.k, bodyOps: armParse.bodyOps });
    ip = armParse.nextIp;

    if (body[ip]?.kind !== "else") return null;
    ip++;

    if (armShape === "return") {
      // expression-bodied : innermost else must be `unreachable` + closing ends.
      if (body[ip]?.kind === "unreachable") {
        ip++;
        while (ip < body.length && body[ip]!.kind === "end") ip++;
        if (ip !== body.length) return null;
        break;
      }
      // Otherwise, recurse into the next arm.
      continue;
    }

    // armShape === "set" : block-form. Three terminators :
    //  (a) another cascade arm (chain continues — `local.get scrutSlot` next).
    //  (b) `unreachable` — exhaustive match, cascade terminates ; closing
    //      `end`s + propagation chain + `local.get; return` follow.
    //  (c) wildcard `_ -> ...` body — detected by an arm-body shape. We bail
    //      here because the wildcard requires knowing the enum's full
    //      domain to safely emit a bounded table.
    const nextOp = body[ip];
    if (nextOp === undefined) return null;
    if (nextOp.kind === "local.get" && nextOp.slot === scrutSlot) {
      continue;
    }
    if (nextOp.kind === "unreachable") {
      ip++;
      while (ip < body.length && body[ip]!.kind === "end") ip++;
      if (!walkPropagationChainAndReturn(body, ip)) return null;
      break;
    }
    return null;
  }
  void defaultBodyOps;

  // 4. Variants must be dense 0..N-1.
  for (let i = 0; i < cases.length; i++) {
    if (cases[i]!.k !== BigInt(i)) return null;
  }

  // 5. If we collected a wildcard default (block-form), append it as the
  //    sentinel entry. Callers must guarantee scrut is in [0, cases.length]
  //    via the enum's tag invariant ; the wildcard slot is index N (only
  //    reachable for non-enum scrutinees, currently unreachable for true
  //    enums but kept for future i32-scrutinee support).
  //    For now, simply use the wildcard as a fallback for any unmapped tag.
  //    Since the table is dense and indexed by scrut directly, we rely on
  //    the enum's tag domain matching exactly [0, N-1] — the wildcard is
  //    therefore unreachable from in-domain scruts and its data wouldn't
  //    be consulted. We *could* add a runtime-bounds-check + fallback, but
  //    that defeats the zero-overhead point ; so reject when defaultBodyOps
  //    is non-null AND the cases don't already cover every variant.
  //    Simpler conservative gate : only accept block-form when there's no
  //    default OR the cases are exhaustive on the enum's tag domain (we
  //    can't see the enum decl here, so accept defaults but waste their
  //    constants — they go in the table but are never read). That's safe.
  const allEntries = defaultBodyOps !== null
    ? [...cases.map(c => c.bodyOps), defaultBodyOps]
    : cases.map(c => c.bodyOps);

  if (isStructResult) {
    if (resultStructIdx === null) return null;
    const structType = m.types[resultStructIdx]!;
    if (structType.kind !== "struct") return null;
    const fields: StaticField[] = structType.fields.map((f) => ({
      name: f.name,
      cType: cTypeOfFieldType(m, f.typeIndex),
      val: bcTypeToVal(m.types[f.typeIndex]!),
    }));
    const entries: ConstValue[][] = [];
    for (const c of cases) {
      const fieldOps = c.bodyOps.slice(0, c.bodyOps.length - 1);
      if (fieldOps.length !== fields.length) return null;
      const row: ConstValue[] = [];
      for (let i = 0; i < fields.length; i++) {
        const cv = constValueFromOp(fieldOps[i]!);
        if (cv === null) return null;
        if (!constMatchesField(cv, fields[i]!.val)) return null;
        row.push(cv);
      }
      entries.push(row);
    }
    return {
      kind: "struct",
      scrutValType: paramVal,
      resultStructIndex: resultStructIdx,
      resultStructName: `vader_struct_${sanitiseStructName(structType.name)}_t`,
      fields, entries,
    };
  } else {
    const entries: ConstValue[] = [];
    for (const c of cases) {
      const cv = constValueFromOp(c.bodyOps[0]!);
      if (cv === null) return null;
      if (!constMatchesField(cv, resultVal)) return null;
      entries.push(cv);
    }
    return {
      kind: "primitive",
      scrutValType: paramVal,
      resultValType: resultVal,
      resultCType: cTypeForPrim(resultVal),
      entries,
    };
  }
}

const PRIMITIVE_VALS: ReadonlySet<ValType> = new Set<ValType>([
  "i8", "i16", "i32", "i64", "u8", "u16", "u32", "u64", "usize",
  "f32", "f64", "bool", "char",
]);

interface ArmHead {
  readonly k: bigint;             // variant tag value
  readonly bodyStartIp: number;   // ip just after the `if void`
}

interface ArmBody {
  readonly bodyOps: Op[];         // const ops + (struct.new)? — drives table init
  readonly nextIp: number;        // ip just after the terminator (return / local.set)
  readonly shape: "return" | "set";
  readonly structIdx: number | null;  // populated when isStructResult
}

/** Walk an arm's body. Two terminators :
 *    - `return` : expression-bodied form, body is `<consts>; (struct.new)?; return`.
 *    - `local.set INNER` : block-form, body is `<consts>; (struct.new)?; local.set N`.
 *  `expectedShape` (if non-null) pins the form across arms — once we see one
 *  shape, every subsequent arm must use the same. */
function parseArmBody(
  body: readonly Op[], ip: number, isStructResult: boolean,
  expectedShape: "return" | "set" | null,
): ArmBody | null {
  const bodyOps: Op[] = [];
  while (ip < body.length) {
    const op = body[ip]!;
    if (op.kind === "return" || op.kind === "local.set") break;
    bodyOps.push(op);
    ip++;
  }
  if (ip >= body.length) return null;
  const term = body[ip]!;
  const shape = term.kind === "return" ? "return" : "set";
  if (expectedShape !== null && expectedShape !== shape) return null;
  if (bodyOps.length === 0) return null;

  let structIdx: number | null = null;
  if (isStructResult) {
    const last = bodyOps[bodyOps.length - 1]!;
    if (last.kind !== "struct.new") return null;
    structIdx = last.typeIndex;
  } else {
    if (bodyOps.length !== 1) return null;
  }
  return { bodyOps, nextIp: ip + 1, shape, structIdx };
}

/** Walk the post-cascade propagation chain : zero or more `local.get N;
 *  local.set N+1` pairs, followed by `local.get FINAL; return`. We don't
 *  actually need to thread the slot numbers because the static-table
 *  rewrite skips the entire body — we only need to confirm the shape so
 *  the rewrite is safe (no side-effecting ops between the cascade and the
 *  return). Returns true on a clean walk, false otherwise. */
function walkPropagationChainAndReturn(body: readonly Op[], ip: number): boolean {
  while (ip < body.length - 1) {
    const get = body[ip];
    const set = body[ip + 1];
    if (get?.kind !== "local.get") break;
    if (set?.kind !== "local.set") break;
    ip += 2;
  }
  if (ip >= body.length) return false;
  if (body[ip]?.kind !== "local.get") return false;
  if (body[ip + 1]?.kind !== "return") return false;
  return ip + 2 === body.length;
}

/** Parse one arm head: `local.get scrut; <intConst K>; (<intConst>.to_<P>)?;
 *  <P>.eq; if void`. Returns the (k, bodyStartIp) on success. */
function parseArmHead(body: readonly Op[], ip: number, scrutSlot: number): ArmHead | null {
  if (body[ip]?.kind !== "local.get" || (body[ip] as Extract<Op, { kind: "local.get" }>).slot !== scrutSlot) {
    return null;
  }
  ip++;
  // Expect a const op.
  const constOp = body[ip];
  if (!constOp) return null;
  let k: bigint | null = null;
  if (constOp.kind === "i32.const") k = BigInt(constOp.value);
  else if (constOp.kind === "i64.const") k = constOp.value;
  // u8/i8/etc. don't have their own const ops — the lower always emits i32/i64.
  else return null;
  ip++;
  // Optional narrow.
  if (body[ip] && /^(i32|i64)\.to_(i8|u8|i16|u16|u32|u64)$/.test(body[ip]!.kind)) {
    ip++;
  }
  // Comparison.
  const cmp = body[ip];
  if (!cmp || !/^(i8|u8|i16|u16|i32|u32|i64|u64)\.eq$/.test(cmp.kind)) return null;
  ip++;
  // if void.
  const ifOp = body[ip];
  if (!ifOp || ifOp.kind !== "if" || ifOp.result !== "void") return null;
  return { k, bodyStartIp: ip + 1 };
}

function constValueFromOp(op: Op): ConstValue | null {
  switch (op.kind) {
    case "i32.const":    return { kind: "int", valType: "i32", value: BigInt(op.value) };
    case "i64.const":    return { kind: "int", valType: "i64", value: op.value };
    case "f32.const":    return { kind: "float", valType: "f32", value: op.value };
    case "f64.const":    return { kind: "float", valType: "f64", value: op.value };
    case "bool.const":   return { kind: "bool", value: op.value };
    case "char.const":   return { kind: "char", value: op.value };
    case "string.const": return { kind: "string", index: op.index };
    case "null.const":   return { kind: "null" };
    default:             return null;
  }
}

function constMatchesField(cv: ConstValue, fieldVal: ValType): boolean {
  switch (cv.kind) {
    case "int":
      // i32.const can land in any int slot via implicit narrowing.
      return INT_VALS.has(fieldVal);
    case "float":
      return fieldVal === "f32" || fieldVal === "f64";
    case "bool":   return fieldVal === "bool";
    case "char":   return fieldVal === "char";
    case "string": return fieldVal === "string";
    case "null":   return fieldVal === "any" || fieldVal === "ref";   // null lives in boxed slots
  }
}

function renderConstValue(cv: ConstValue, targetVal: ValType, targetCType: string): string {
  switch (cv.kind) {
    case "int": {
      const v = cv.value.toString();
      if (targetVal === "i64") return `INT64_C(${v})`;
      if (targetVal === "u64" || targetVal === "usize") return `UINT64_C(${v})`;
      return `(${targetCType})${v}`;
    }
    case "float": {
      const v = Object.is(cv.value, -0) ? "-0.0" : `${cv.value}`;
      return targetVal === "f32" ? `${v}f` : v;
    }
    case "bool":   return cv.value ? "true" : "false";
    case "char":   return `${cv.value}u`;
    case "string": return `vader_str_${cv.index}`;
    case "null":   return `vader_box_null()`;
  }
}

function cTypeForPrim(v: ValType): string {
  switch (v) {
    case "i8":    return "int8_t";
    case "i16":   return "int16_t";
    case "i32":   return "int32_t";
    case "i64":   return "int64_t";
    case "u8":    return "uint8_t";
    case "u16":   return "uint16_t";
    case "u32":   return "uint32_t";
    case "u64":   return "uint64_t";
    case "usize": return "size_t";
    case "f32":   return "float";
    case "f64":   return "double";
    case "bool":  return "bool";
    case "char":  return "uint32_t";
    case "string":return "vader_string_t";
    default:      return "vader_box_t";
  }
}

function cTypeOfFieldType(m: BytecodeModule, typeIdx: number): string {
  const t = m.types[typeIdx]!;
  if (t.kind === "primitive") return cTypeForPrim(t.val);
  // ref/struct/array fields → vader_box_t
  return "vader_box_t";
}

function bcTypeToVal(t: BcType): ValType {
  if (t.kind === "primitive") return t.val;
  return "ref";
}

function sanitiseStructName(name: string): string {
  return name.replace(/[^A-Za-z0-9_]/g, "_");
}

const INT_VALS: ReadonlySet<ValType> = new Set<ValType>([
  "i8", "i16", "i32", "i64", "u8", "u16", "u32", "u64", "usize",
]);
