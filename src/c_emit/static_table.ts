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
import { cStringLit } from "./emit.ts";

/** Three emission flavours :
 *  - `struct` — fn returns a struct ref, dense 0..N-1 cases, no wildcard.
 *    Table holds full struct values, boxed at the call site.
 *  - `primitive` — fn returns a scalar, dense 0..N-1 cases, no wildcard.
 *    Table holds the bare values, returned directly.
 *  - `switch` — fn returns a primitive, but cases are sparse (variant
 *    tags non-contiguous) or a wildcard `_` arm exists. Emit a C
 *    `switch (l0)` with one `case K:` per arm + a `default:` for the
 *    wildcard (or `vader_unreachable` if exhaustive). The C compiler
 *    folds dense switches into a jump table on its own. */
type StaticTableInfo = StaticTableStructInfo | StaticTablePrimitiveInfo | StaticSwitchInfo;

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

interface StaticSwitchInfo {
  readonly kind: "switch";
  readonly scrutValType: ValType;
  readonly resultValType: ValType;
  readonly resultCType: string;
  /** Per-case head ip — its `fn.debug[headIp]` pins the source line for
   *  the `#line` directive that precedes the `case K: return V;` row. */
  readonly cases: ReadonlyArray<{ k: bigint; value: ConstValue; headIp: number }>;
  readonly defaultValue: ConstValue | null;   // null → exhaustive (emit unreachable)
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
 *  caller should skip the default fn body emission). When `ctx.release` is
 *  false, threads per-arm `#line` directives so debuggers / coverage tools
 *  map each `case K:` back to its source line — matches the per-op `#line`
 *  emission in `body.ts:140-159` so the table form isn't a debug-info hole. */
export function tryEmitStaticTable(
  ctx: {
    module: BytecodeModule;
    structNames: readonly (string | null)[];
    fnNames: readonly string[];
    atomIds: readonly number[];
    release: boolean;
  },
  fn: BcFunction, fnIdx: number, out: string[],
): boolean {
  const info = detectStaticTable(ctx.module, fn);
  if (info === null) return false;

  const fnName = ctx.fnNames[fnIdx]!;
  const tableName = `vader_static_table_${fnName}`;
  const paramCType = cTypeForPrim(info.scrutValType);
  const debug = ctx.release ? null : fn.debug;

  if (info.kind === "struct") {
    const tag = info.resultStructIndex;
    out.push(`static const ${info.resultStructName} ${tableName}[${info.entries.length}] = {`);
    for (const entry of info.entries) {
      const fieldInits = entry.map((cv, i) => renderConstValue(cv, info.fields[i]!.val, info.fields[i]!.cType, ctx.atomIds)).join(", ");
      out.push(`    { { ${tag}u, 0u, 0u, 0u, NULL }, ${fieldInits} },`);
    }
    out.push(`};`);
    out.push(`static vader_box_t ${fnName}(${paramCType} l0) {`);
    out.push(`    return vader_box_obj(${tag}u, (void*)(uintptr_t)&${tableName}[l0]);`);
    out.push(`}`);
  } else if (info.kind === "primitive") {
    const inits = info.entries.map((cv) => renderConstValue(cv, info.resultValType, info.resultCType, ctx.atomIds)).join(", ");
    out.push(`static const ${info.resultCType} ${tableName}[${info.entries.length}] = { ${inits} };`);
    out.push(`static ${info.resultCType} ${fnName}(${paramCType} l0) {`);
    out.push(`    return ${tableName}[l0];`);
    out.push(`}`);
  } else {
    // switch form — sparse cases or wildcard. C compiler folds dense
    // switches into jump tables on its own ; for sparse cases the tradeoff
    // depends on density and -O3 picks the best dispatch.
    out.push(`static ${info.resultCType} ${fnName}(${paramCType} l0) {`);
    out.push(`    switch (l0) {`);
    // Mirror of `body.ts:142-156` : raw `file` compare so `cStringLit`
    // only runs on file change, and `dbg.file` truthiness guard for
    // synthetic spans (where `file` may be empty / undefined past the
    // static type).
    let lastLine = -1;
    let lastFile = "";
    let lastFileLit = "";
    for (const c of info.cases) {
      if (debug !== null) {
        const dbg = debug[c.headIp];
        const file = dbg?.file;
        if (file && (dbg!.line !== lastLine || file !== lastFile)) {
          if (file !== lastFile) { lastFile = file; lastFileLit = cStringLit(file); }
          out.push(`#line ${dbg!.line} ${lastFileLit}`);
          lastLine = dbg!.line;
        }
      }
      const v = renderConstValue(c.value, info.resultValType, info.resultCType, ctx.atomIds);
      out.push(`        case ${c.k.toString()}u: return ${v};`);
    }
    if (info.defaultValue !== null) {
      const v = renderConstValue(info.defaultValue, info.resultValType, info.resultCType, ctx.atomIds);
      out.push(`        default: return ${v};`);
    } else {
      out.push(`        default: vader_unreachable("${fnName}");`);
    }
    out.push(`    }`);
    // Belt-and-suspenders : Clang occasionally complains about the
    // missing return path even when every case returns. Re-emit the
    // unreachable here to silence it.
    out.push(`    vader_unreachable("${fnName}");`);
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

  // 2. Locate the scrutinee local. Two shapes :
  //   - `local.get 0 ; local.set N` — match introduces a synthetic scrut
  //     copy ; scrut lives in slot N (where N > 0).
  //   - `local.get 0 ; <const> ...` — `propagateLocalAlias` (peephole
  //     Rule 7) elided the synthetic copy ; the param itself is the
  //     scrutinee, so scrut lives in slot 0. Without this branch the
  //     detector silently skipped every `match` over a param scrutinee
  //     and the C emit fell back to the deeply-nested if/else cascade.
  const body = fn.body;
  if (body.length < 4) return null;
  if (body[0]!.kind !== "local.get" || body[0]!.slot !== 0) return null;
  let scrutSlot: number;
  let ip: number;
  if (body[1]!.kind === "local.set") {
    scrutSlot = body[1]!.slot;
    ip = 2;
  } else {
    scrutSlot = 0;
    ip = 0;
  }

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
  const cases: Array<{ k: bigint; bodyOps: Op[]; headIp: number }> = [];
  let defaultBodyOps: Op[] | null = null;
  let armShape: "return" | "set" | null = null;
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
    cases.push({ k: armStart.k, bodyOps: armParse.bodyOps, headIp: armStart.headIp });
    ip = armParse.nextIp;

    // Separator between arms depends on the arm shape :
    //  - "return" arms : either `else` (un-flattened nested form) or `end`
    //    (midir's early-return flattening — `src/midir/emit.ts:300-324` —
    //    drops the `else` op when the then-branch ends with `return`).
    //  - "set" arms : always `else` (no early exit so the nesting survives).
    const sep = body[ip];
    if (sep === undefined) return null;
    const sepIsEnd = armShape === "return" && sep.kind === "end";
    if (!sepIsEnd && sep.kind !== "else") return null;
    ip++;

    if (armShape === "return") {
      // expression-bodied : innermost separator must precede `unreachable`
      // + closing ends (nested) or `unreachable` alone (flat), OR a
      // wildcard arm body (consts + return) followed by ends.
      if (body[ip]?.kind === "unreachable") {
        ip++;
        while (ip < body.length && body[ip]!.kind === "end") ip++;
        if (ip !== body.length) return null;
        break;
      }
      if (body[ip]?.kind !== "local.get" ||
          (body[ip] as Extract<Op, { kind: "local.get" }>).slot !== scrutSlot) {
        // Try the wildcard form : the next ops are an arm body that ends
        // in `return` (no preceding cmp head).
        const wildParse = parseArmBody(body, ip, isStructResult, "return");
        if (wildParse === null) return null;
        if (isStructResult) return null;   // sparse/wildcard struct unsupported
        defaultBodyOps = wildParse.bodyOps;
        ip = wildParse.nextIp;
        while (ip < body.length && body[ip]!.kind === "end") ip++;
        if (ip !== body.length) return null;
        break;
      }
      continue;
    }

    // armShape === "set" : block-form. Three terminators :
    //  (a) another cascade arm (chain continues — `local.get scrutSlot` next).
    //  (b) `unreachable` — exhaustive match, cascade terminates ; closing
    //      `end`s + propagation chain + `local.get; return` follow.
    //  (c) wildcard `_ -> ...` body — same shape as a real arm but no cmp
    //      head. We accept this for primitive results (emits `switch` with
    //      `default:`) but reject for struct results (would need a sparse
    //      struct table — future work).
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
    // Wildcard arm body (set form).
    if (isStructResult) return null;
    const wildParse = parseArmBody(body, ip, isStructResult, "set");
    if (wildParse === null) return null;
    defaultBodyOps = wildParse.bodyOps;
    ip = wildParse.nextIp;
    while (ip < body.length && body[ip]!.kind === "end") ip++;
    if (!walkPropagationChainAndReturn(body, ip)) return null;
    break;
  }

  // 4. Decide table vs switch :
  //    - Cases dense 0..N-1 AND no wildcard → table mode.
  //    - Otherwise (sparse cases or wildcard) → switch mode (primitive only).
  let dense = defaultBodyOps === null;
  if (dense) {
    for (let i = 0; i < cases.length; i++) {
      if (cases[i]!.k !== BigInt(i)) { dense = false; break; }
    }
  }

  if (!dense) {
    // Sparse/wildcard switch mode. Currently primitive-result only — sparse
    // struct returns would need a per-case `static const T VAL_K = ...;`
    // and a switch returning boxed refs ; tracked as Prop 2 follow-up.
    if (isStructResult) return null;
    const switchCases: Array<{ k: bigint; value: ConstValue; headIp: number }> = [];
    for (const c of cases) {
      const cv = constValueFromOp(c.bodyOps[0]!);
      if (cv === null) return null;
      if (!constMatchesField(cv, resultVal)) return null;
      switchCases.push({ k: c.k, value: cv, headIp: c.headIp });
    }
    let defaultValue: ConstValue | null = null;
    if (defaultBodyOps !== null) {
      const cv = constValueFromOp(defaultBodyOps[0]!);
      if (cv === null) return null;
      if (!constMatchesField(cv, resultVal)) return null;
      defaultValue = cv;
    }
    return {
      kind: "switch",
      scrutValType: paramVal,
      resultValType: resultVal,
      resultCType: cTypeForPrim(resultVal),
      cases: switchCases,
      defaultValue,
    };
  }

  // Dense + no wildcard : table mode.
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
  "i8", "i16", "i32", "i64", "isize", "u8", "u16", "u32", "u64", "usize",
  "f32", "f64", "bool", "char",
]);

interface ArmHead {
  readonly k: bigint;             // variant tag value
  readonly bodyStartIp: number;   // ip just after the `if void`
  readonly headIp: number;        // ip of the arm's `local.get scrut` — its
                                  // dbg pins the arm body's source line for
                                  // `#line` directives in non-release builds.
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

/** Walk the post-cascade propagation chain. The lower interleaves `end`
 *  ops (closing the nested if/else scopes) with `local.get N; local.set
 *  N+1` propagation pairs, finishing with a single `local.get FINAL;
 *  return`. We don't thread the slot numbers — the static-table rewrite
 *  drops the entire body — but we DO confirm no side-effecting op slips
 *  in between cascade end and return. Returns true on a clean walk. */
function walkPropagationChainAndReturn(body: readonly Op[], ip: number): boolean {
  while (ip < body.length - 1) {
    if (body[ip]!.kind === "end") { ip++; continue; }
    const get = body[ip];
    const set = body[ip + 1];
    if (get?.kind === "local.get" && set?.kind === "local.set") { ip += 2; continue; }
    break;
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
  const headIp = ip;
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
  return { k, bodyStartIp: ip + 1, headIp };
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

function renderConstValue(cv: ConstValue, targetVal: ValType, targetCType: string, atomIds: readonly number[]): string {
  switch (cv.kind) {
    case "int": {
      const v = cv.value.toString();
      if (targetVal === "i64" || targetVal === "isize") return `INT64_C(${v})`;
      if (targetVal === "u64" || targetVal === "usize") return `UINT64_C(${v})`;
      return `(${targetCType})${v}`;
    }
    case "float": {
      const v = Object.is(cv.value, -0) ? "-0.0" : `${cv.value}`;
      return targetVal === "f32" ? `${v}f` : v;
    }
    case "bool":   return cv.value ? "true" : "false";
    case "char":   return `${cv.value}u`;
    case "string": return `${atomIds[cv.index]!}u`;
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
    case "isize": return "ptrdiff_t";
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
  "i8", "i16", "i32", "i64", "isize", "u8", "u16", "u32", "u64", "usize",
]);
