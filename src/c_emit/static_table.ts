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

interface StaticTableInfo {
  readonly scrutValType: ValType;        // i8/u8/i16/u16/i32/u32 (param type)
  readonly resultStructIndex: number;     // BcType index of the result struct
  readonly resultStructName: string;      // "Foo" → emitted as vader_struct_Foo_t
  readonly fields: readonly StaticField[];   // one per struct field, in decl order
  readonly entries: readonly (readonly ConstValue[])[];  // [variantIdx][fieldIdx]
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
  const cStructName = info.resultStructName;
  const tag = info.resultStructIndex;

  // Emit the static table just before the fn definition.
  out.push(`static const ${cStructName} ${tableName}[${info.entries.length}] = {`);
  for (const entry of info.entries) {
    const fieldInits = entry.map((cv, i) => renderConstValue(cv, info.fields[i]!)).join(", ");
    out.push(`    { { ${tag}u, 0u, NULL }, ${fieldInits} },`);
  }
  out.push(`};`);

  // Replace the fn body with a one-liner indexed lookup.
  const cret = "vader_box_t";
  const paramCType = ctx.module.types.find((t, idx) => idx === 0)
    ? cTypeForPrim(info.scrutValType)
    : cTypeForPrim(info.scrutValType);   // primitive — no need to look up
  out.push(`static ${cret} ${fnName}(${paramCType} l0) {`);
  out.push(`    return vader_box_obj(${tag}u, (void*)(uintptr_t)&${tableName}[l0]);`);
  out.push(`}`);
  return true;
}

function detectStaticTable(m: BytecodeModule, fn: BcFunction): StaticTableInfo | null {
  // 1. Signature gate.
  if (fn.signature.params.length !== 1) return null;
  const paramVal = fn.signature.params[0]!;
  if (!INT_VALS.has(paramVal)) return null;
  if (fn.signature.result !== "ref") return null;

  // 2. Locate the synthetic scrut local. The lower's `match` always copies the
  //    param into a fresh local before testing arms ; we expect the first two
  //    ops to be `local.get 0; local.set 1`.
  const body = fn.body;
  if (body.length < 4) return null;
  if (body[0]!.kind !== "local.get" || body[0]!.slot !== 0) return null;
  if (body[1]!.kind !== "local.set") return null;
  const scrutSlot = body[1]!.slot;

  // 3. Walk the cascade, collecting one (variantTag, arm body op range) per
  //    nesting level. The walker advances `ip` through the chain until the
  //    innermost `unreachable` is reached.
  const cases: Array<{ k: bigint; bodyOps: Op[] }> = [];
  let ip = 2;
  // Track the result struct type (must be uniform across arms).
  let resultStructIdx: number | null = null;

  while (true) {
    const armStart = parseArmHead(body, ip, scrutSlot);
    if (armStart === null) return null;
    ip = armStart.bodyStartIp;

    // Walk the arm body until we hit `return`. Allowed ops in the body:
    // const ops + struct.new + return.
    const bodyOps: Op[] = [];
    while (ip < body.length) {
      const op = body[ip]!;
      if (op.kind === "return") break;
      bodyOps.push(op);
      ip++;
    }
    if (ip >= body.length) return null;
    if (body[ip]!.kind !== "return") return null;
    ip++;   // past `return`

    // The arm body must be `<consts...>; struct.new TAG`.
    if (bodyOps.length === 0) return null;
    const last = bodyOps[bodyOps.length - 1]!;
    if (last.kind !== "struct.new") return null;
    const armStructIdx = last.typeIndex;
    if (resultStructIdx === null) resultStructIdx = armStructIdx;
    else if (resultStructIdx !== armStructIdx) return null;

    cases.push({ k: armStart.k, bodyOps });

    // After `return`, expect `else` opening the next arm. If the next op is
    // `unreachable` followed by `end`s, the cascade is exhaustive — break.
    if (body[ip]?.kind !== "else") return null;
    ip++;   // past `else`

    // Peek: is this the innermost-else (unreachable terminator)?
    if (body[ip]?.kind === "unreachable") {
      // Walk past `unreachable` and all closing `end` ops.
      ip++;
      while (ip < body.length && body[ip]!.kind === "end") ip++;
      if (ip !== body.length) return null;
      break;
    }
    // Otherwise, loop : the next iteration parses the next arm-head from `ip`.
  }

  // 4. Variants must be dense 0..N-1.
  for (let i = 0; i < cases.length; i++) {
    if (cases[i]!.k !== BigInt(i)) return null;
  }

  if (resultStructIdx === null) return null;
  const structType = m.types[resultStructIdx]!;
  if (structType.kind !== "struct") return null;

  // 5. Each arm body's const ops must produce one ConstValue per struct field
  //    in field order, with matching types.
  const fields: StaticField[] = structType.fields.map((f) => {
    const ftype = m.types[f.typeIndex]!;
    return {
      name: f.name,
      cType: cTypeOfFieldType(m, f.typeIndex),
      val: bcTypeToVal(ftype),
    };
  });

  const entries: ConstValue[][] = [];
  for (const c of cases) {
    const fieldOps = c.bodyOps.slice(0, c.bodyOps.length - 1);   // drop struct.new
    if (fieldOps.length !== fields.length) return null;
    const row: ConstValue[] = [];
    for (let i = 0; i < fields.length; i++) {
      const cv = constValueFromOp(fieldOps[i]!);
      if (cv === null) return null;
      // Type-match: const's val must be assignable to field val.
      if (!constMatchesField(cv, fields[i]!.val)) return null;
      row.push(cv);
    }
    entries.push(row);
  }

  return {
    scrutValType: paramVal,
    resultStructIndex: resultStructIdx,
    resultStructName: `vader_struct_${sanitiseStructName(structType.name)}_t`,
    fields,
    entries,
  };
}

interface ArmHead {
  readonly k: bigint;             // variant tag value
  readonly bodyStartIp: number;   // ip just after the `if void`
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

function renderConstValue(cv: ConstValue, field: StaticField): string {
  switch (cv.kind) {
    case "int": {
      const v = cv.value.toString();
      if (field.val === "i64") return `INT64_C(${v})`;
      if (field.val === "u64" || field.val === "usize") return `UINT64_C(${v})`;
      // narrower ints → int32 cast at static init time, OK for any small int.
      return `(${field.cType})${v}`;
    }
    case "float": {
      const v = Object.is(cv.value, -0) ? "-0.0" : `${cv.value}`;
      return field.val === "f32" ? `${v}f` : v;
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
