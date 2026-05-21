// .vir text format — serializer and parser for BytecodeModule.
//
// Line-oriented: header sections (module, type, string, import, export) at
// the top, then one fn block per function. Within a fn body, one op per line
// with optional `; file:line:col` debug annotation.
//
// Round-trip invariant: parse(write(m)) === m  (modulo floating-point parse
// precision, which is preserved by going through the same `Number.parseFloat`).

import type { BcExport, BcFunction, BcImport, BcLocal, BcSignature, BytecodeModule, DebugPos } from "./module.ts";
import type { Op } from "./ops.ts";
import { intrinsicIdByName, intrinsicNameById, isConstOp } from "./ops.ts";
import type { ArrayKind, BcDataEntry, BcType, ValType } from "./types.ts";
import { arrayKindElementSize, isValType, readArrayKindLE, writeArrayKindLE } from "./types.ts";
import { bytecodeFail } from "../diagnostics/errors.ts";

// ---------------------------------------------------------------- writer

export interface WriteVirOptions {
  /** Emit `; file:line:col` debug annotations on every op. Defaults to
   *  `true` so build artefacts keep their debug info ; flip to `false`
   *  for test snapshots so line-number churn doesn't dominate diffs. */
  debug?: boolean;
}

export function writeVir(m: BytecodeModule, opts: WriteVirOptions = {}): string {
  const debug = opts.debug ?? true;
  const out: string[] = [];
  out.push(`module ${m.name}`);

  for (let i = 0; i < m.types.length; i++) out.push(`type ${i} ${formatType(m.types[i]!)}`);
  for (let i = 0; i < m.strings.length; i++) out.push(`string ${i} ${formatString(m.strings[i]!)}`);
  for (let i = 0; i < m.dataPool.length; i++) out.push(`data ${i} ${formatDataEntry(m.dataPool[i]!)}`);
  for (let i = 0; i < m.imports.length; i++) out.push(`import ${i} ${formatImport(m.imports[i]!)}`);
  // Trait-impl directives — one `impl TYPE_ID TRAIT_NAME` line per (type, trait)
  // pair that the typechecker registered, so consumers (Vader-VM, C-emit
  // re-parse) can answer `is Trait` patterns without a struct-name heuristic.
  // Sorted by type-id to keep the snapshot stable.
  const implTypeIds = [...m.implTable.keys()].sort((a, b) => a - b);
  for (const typeIdx of implTypeIds) {
    for (const trait of m.implTable.get(typeIdx)!) {
      out.push(`impl ${typeIdx} ${quoteIdent(trait)}`);
    }
  }
  for (const e of m.exports) out.push(`export ${quoteIdent(e.externName)} ${e.fnIndex}`);

  for (let i = 0; i < m.functions.length; i++) {
    out.push("");
    formatFunction(m.functions[i]!, i, out, debug);
  }

  return out.join("\n") + "\n";
}

function formatType(t: BcType): string {
  switch (t.kind) {
    case "primitive": return `primitive ${t.val}`;
    case "struct": {
      const fields = t.fields.map((f) => `${f.name}:${f.typeIndex}`).join(",");
      return `struct ${quoteIdent(t.name)} { ${fields} }`;
    }
    case "array": return `array ${t.element}`;
    case "union": return `union ${t.variants.join(",")}`;
    case "ref":   return `ref ${t.traitName === null ? "_" : quoteIdent(t.traitName)}`;
    case "fn":    return `fn (${t.params.join(",")}) -> ${t.returnType}`;
  }
}

function formatString(s: string): string { return JSON.stringify(s); }

function formatDataEntry(e: BcDataEntry): string {
  const elemSize = arrayKindElementSize(e.kind);
  if (elemSize === 0) {
    throw new Error(`bytecode text: data entry kind "${e.kind}" not allowed (must be primitive)`);
  }
  const bytes = new Uint8Array(elemSize * e.items.length);
  const dv = new DataView(bytes.buffer);
  for (let i = 0; i < e.items.length; i++) writeArrayKindLE(dv, i * elemSize, e.kind, e.items[i]!);
  return `${e.kind} hex"${bytesToHex(bytes)}"`;
}

const HEX_DIGITS = "0123456789abcdef";

function bytesToHex(b: Uint8Array): string {
  let s = "";
  for (let i = 0; i < b.length; i++) {
    const v = b[i]!;
    s += HEX_DIGITS[v >>> 4]! + HEX_DIGITS[v & 0xF]!;
  }
  return s;
}

function hexToBytes(s: string): Uint8Array {
  if (s.length % 2 !== 0) throw new Error("bytecode text: data hex blob has odd length");
  const out = new Uint8Array(s.length >>> 1);
  for (let i = 0; i < out.length; i++) {
    const hi = s.charCodeAt(i * 2);
    const lo = s.charCodeAt(i * 2 + 1);
    out[i] = (hexDigit(hi) << 4) | hexDigit(lo);
  }
  return out;
}

function hexDigit(c: number): number {
  if (c >= 48 && c <= 57)  return c - 48;
  if (c >= 97 && c <= 102) return c - 87;
  if (c >= 65 && c <= 70)  return c - 55;
  throw new Error(`bytecode text: invalid hex digit ${String.fromCharCode(c)}`);
}

function formatImport(i: BcImport): string {
  const externMarker = i.isExtern ? "extern " : "";
  return `${externMarker}${quoteIdent(i.externName)} ${quoteIdent(i.mangledName)} ${formatSignature(i.signature)}`;
}

function formatSignature(s: BcSignature): string {
  // `paramTypes` / `resultType` are deliberately not emitted — they're
  // in-memory metadata for c-emit's B1 boundary detection and not part
  // of the on-disk contract. Keeping the textual form minimal also
  // makes the snapshot suites less noisy.
  return `(${s.params.join(",")}) -> ${s.result}`;
}

function formatFunction(fn: BcFunction, idx: number, out: string[], debug: boolean): void {
  out.push(`fn ${idx} ${quoteIdent(fn.name)} ${formatSignature(fn.signature)}`);
  for (const local of fn.locals) out.push(`  local ${quoteIdent(local.name)} ${local.val}`);

  // Structured ops emit named labels (`$L0`, `$L1`, …) instead of numeric
  // depths so `br $L_outer` reads at a glance — no counting backwards.
  // Indentation visualises the nesting (2 spaces per scope on top of the
  // 2-space fn-body base).
  const scopes: { name: string; kind: "block" | "loop" | "if" }[] = [];
  let labelCounter = 0;

  for (let i = 0; i < fn.body.length; i++) {
    const op = fn.body[i]!;
    const dbg = fn.debug[i];

    // `else`/`end` outdent to the parent's level even though they still
    // belong to the open scope (the scope stack tracks them).
    const outdented = op.kind === "else" || op.kind === "end";
    const indent = "  ".repeat(1 + (outdented ? scopes.length - 1 : scopes.length));

    let line: string;
    if (op.kind === "block" || op.kind === "loop" || op.kind === "if") {
      const name = `$L${labelCounter++}`;
      scopes.push({ name, kind: op.kind });
      line = `${op.kind} ${name} ${op.result}`;
    } else if (op.kind === "end") {
      const top = scopes.pop();
      line = top === undefined ? `end` : `end ${top.name}`;
    } else if (op.kind === "br" || op.kind === "br_if") {
      const target = scopes[scopes.length - 1 - op.depth];
      line = target === undefined
        ? `${op.kind} ${op.depth}`         // unreachable in practice — be defensive
        : `${op.kind} ${target.name}`;
    } else {
      line = formatOp(op);
    }

    out.push(`${indent}${line}${debug ? formatDebug(dbg ?? null) : ""}`);
  }
  out.push(`end`);
}

function formatDebug(d: DebugPos | null): string {
  if (d === null) return "";
  return `   ; ${d.file}:${d.line}:${d.column}`;
}

function formatOp(op: Op): string {
  // Structured-control + branch ops (`block`/`loop`/`if`/`end`/`br`/`br_if`)
  // are emitted by `formatFunction` directly so it can resolve named labels.
  // Common cases first; the kind-string carries most info, the operands tail.
  switch (op.kind) {
    case "i32.const":    return `i32.const ${op.value}`;
    case "i64.const":    return `i64.const ${op.value.toString()}`;
    case "f32.const":    return `f32.const ${formatFloat(op.value)}`;
    case "f64.const":    return `f64.const ${formatFloat(op.value)}`;
    case "bool.const":   return `bool.const ${op.value}`;
    case "char.const":   return `char.const ${op.value}`;
    case "string.const": return `string.const ${op.index}`;
    case "null.const":   return `null.const`;
    case "local.get":    return `local.get ${op.slot}`;
    case "local.set":    return `local.set ${op.slot}`;
    case "local.tee":    return `local.tee ${op.slot}`;
    case "call":         return `call ${op.fnIndex}`;
    case "call.import":  return `call.import ${op.importIndex}`;
    case "call.indirect": return `call.indirect ${op.typeIndex}`;
    case "virtual.call": return `virtual.call ${op.paramCount} ${op.vtableKey}`;
    case "fn.ref":       return `fn.ref ${op.fnIndex} ${op.typeIndex}`;
    case "make_closure": return `make_closure ${op.fnIndex} ${op.typeIndex}`;
    case "intrinsic":    return `intrinsic ${intrinsicNameById(op.id) ?? op.id}`;
    case "struct.new":   return `struct.new ${op.typeIndex}`;
    case "struct.new_stack": return `struct.new_stack ${op.typeIndex}`;
    case "struct.get":   return `struct.get ${op.typeIndex} ${op.fieldIndex}`;
    case "struct.set":   return `struct.set ${op.typeIndex} ${op.fieldIndex}`;
    case "struct.set_stack": return `struct.set_stack ${op.typeIndex} ${op.fieldIndex}`;
    case "array.new":    return `array.new ${op.typeIndex} ${op.length}`;
    case "array.get":    return `array.get ${op.typeIndex}`;
    case "array.set":    return `array.set ${op.typeIndex}`;
    case "array.push":   return `array.push ${op.typeIndex}`;
    case "array.slice":  return `array.slice ${op.typeIndex}`;
    case "data.const":   return `data.const ${op.poolIndex} ${op.typeIndex}`;
    case "type_check":   return `type_check ${op.typeIndex}`;
    case "type.const":   return `type.const ${op.typeIndex}`;
    case "ref.cast":     return `ref.cast ${op.typeIndex}`;
    case "return.lit":   return `return.lit ${formatOp(op.value)}`;
    default:
      // Operand-less ops: their kind string is the whole encoding.
      return op.kind;
  }
}

function formatFloat(n: number): string {
  if (Number.isInteger(n) && Math.abs(n) < 1e16) return `${n}.0`;
  return Number.isFinite(n) ? n.toString() : `${n}`;     // Infinity / NaN serialised verbatim
}

function quoteIdent(s: string): string {
  // Quote when the identifier contains anything other than [A-Za-z0-9_$.].
  // The lowerer's mangled names use $ so they're safe; user-facing extern
  // names can have arbitrary chars.
  return /^[A-Za-z0-9_$.]+$/.test(s) ? s : JSON.stringify(s);
}

// ---------------------------------------------------------------- parser

export function parseVir(text: string, path: string | null = null): BytecodeModule {
  const ctx: ParseCtx = { lines: text.split("\n"), cur: { i: 0 }, path };
  const m = newMutableModule();

  while (ctx.cur.i < ctx.lines.length) {
    const raw = ctx.lines[ctx.cur.i]!;
    ctx.cur.i++;
    const stripped = stripTrailingComment(raw).trim();
    if (stripped === "") continue;
    parseHeaderLine(stripped, m, ctx);
  }
  return finalizeModule(m);
}

interface ParseCtx {
  readonly lines: readonly string[];
  readonly cur: { i: number };
  readonly path: string | null;
}

function fail(ctx: ParseCtx, message: string): never {
  // `cur.i` is post-increment — points at the line we just consumed.
  bytecodeFail("vir parse", message, {
    path: ctx.path,
    position: { kind: "text", line: ctx.cur.i, column: 1 },
  });
}

interface MutableModule {
  name: string;
  types: BcType[];
  strings: string[];
  dataPool: BcDataEntry[];
  functions: BcFunction[];
  imports: BcImport[];
  exports: BcExport[];
  implTable: Map<number, string[]>;
}

function newMutableModule(): MutableModule {
  return { name: "", types: [], strings: [], dataPool: [], functions: [], imports: [], exports: [], implTable: new Map() };
}

function finalizeModule(m: MutableModule): BytecodeModule {
  return {
    name: m.name, types: m.types, strings: m.strings, dataPool: m.dataPool,
    functions: m.functions, imports: m.imports, exports: m.exports,
    implTable: m.implTable,
    vtables: new Map(),
  };
}

/** Strip a `; …` trailing comment from a line, preserving anything inside
 *  double-quoted strings. Used by header-line parsers; op-line parsers split
 *  the comment off via `findCommentStart` so they can preserve debug info. */
function stripTrailingComment(line: string): string {
  const idx = findCommentStart(line);
  return idx < 0 ? line : line.slice(0, idx).replace(/\s+$/, "");
}

function parseHeaderLine(line: string, m: MutableModule, ctx: ParseCtx): void {
  const head = firstWord(line);
  const rest = line.slice(head.length).trim();
  switch (head) {
    case "module":
      m.name = rest;
      return;
    case "type": {
      const [idxStr, ...spec] = rest.split(/\s+/);
      const idx = Number(idxStr);
      m.types[idx] = parseType(spec.join(" "), ctx);
      return;
    }
    case "string": {
      const sp = rest.indexOf(" ");
      const idx = Number(rest.slice(0, sp));
      m.strings[idx] = JSON.parse(rest.slice(sp + 1)) as string;
      return;
    }
    case "data": {
      // "data <idx> <kind> hex\"<bytes>\""
      const sp = rest.indexOf(" ");
      const idx = Number(rest.slice(0, sp));
      m.dataPool[idx] = parseDataEntry(rest.slice(sp + 1).trim(), ctx);
      return;
    }
    case "import": {
      const [idxStr, ...spec] = rest.split(/\s+/);
      const idx = Number(idxStr);
      m.imports[idx] = parseImport(spec.join(" "), ctx);
      return;
    }
    case "export": {
      const [externName, fnIdxStr] = rest.split(/\s+/);
      m.exports.push({
        externName: unquoteIdent(externName ?? ""),
        fnIndex: Number(fnIdxStr),
      });
      return;
    }
    case "impl": {
      const [idxStr, ...rest2] = rest.split(/\s+/);
      const idx = Number(idxStr);
      const trait = unquoteIdent(rest2.join(" "));
      const list = m.implTable.get(idx);
      if (list !== undefined) list.push(trait);
      else m.implTable.set(idx, [trait]);
      return;
    }
    case "fn":
      parseFn(line, m, ctx);
      return;
    default:
      fail(ctx, `unknown header "${head}"`);
  }
}

function parseType(spec: string, ctx: ParseCtx): BcType {
  const head = firstWord(spec);
  const rest = spec.slice(head.length).trim();
  switch (head) {
    case "primitive": return { kind: "primitive", val: expectValType(rest, ctx) };
    case "array":     return { kind: "array", element: Number(rest) };
    case "union":     return { kind: "union", variants: rest.split(",").map(Number) };
    case "ref":       return { kind: "ref", traitName: rest === "_" ? null : unquoteIdent(rest) };
    case "fn": {
      const fm = /^\((.*?)\)\s*->\s*(\d+)$/.exec(rest);
      if (fm === null) fail(ctx, `malformed fn type "${spec}"`);
      const params = fm[1] === "" ? [] : fm[1]!.split(",").map(Number);
      return { kind: "fn", params, returnType: Number(fm[2]) };
    }
    case "struct": {
      // "<name> { f0:t0,f1:t1,... }"
      const braceOpen = rest.indexOf("{");
      const braceClose = rest.lastIndexOf("}");
      const name = unquoteIdent(rest.slice(0, braceOpen).trim());
      const inner = rest.slice(braceOpen + 1, braceClose).trim();
      const fields = inner === "" ? [] : inner.split(",").map((s) => {
        const [n, t] = s.trim().split(":");
        return { name: n!.trim(), typeIndex: Number(t!.trim()) };
      });
      return { kind: "struct", name, fields };
    }
    default: fail(ctx, `unknown type kind "${head}"`);
  }
}

function parseDataEntry(spec: string, ctx: ParseCtx): BcDataEntry {
  // "<kind> hex\"<bytes>\""
  const sp = spec.indexOf(" ");
  if (sp < 0) fail(ctx, `malformed data entry "${spec}"`);
  const kindStr = spec.slice(0, sp);
  const kind = (kindStr as ArrayKind);
  const elemSize = arrayKindElementSize(kind);
  if (elemSize === 0) fail(ctx, `data entry kind "${kindStr}" not allowed (must be primitive)`);
  const tail = spec.slice(sp + 1).trim();
  const m = /^hex"([0-9a-fA-F]*)"$/.exec(tail);
  if (m === null) fail(ctx, `data entry expects hex"<bytes>"`);
  const bytes = hexToBytes(m[1]!);
  if (bytes.length % elemSize !== 0) fail(ctx, `data entry byte length ${bytes.length} not a multiple of element size ${elemSize}`);
  const count = bytes.length / elemSize;
  const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  const items: bigint[] = new Array(count);
  for (let i = 0; i < count; i++) items[i] = readArrayKindLE(dv, i * elemSize, kind);
  return { kind, items };
}

function parseImport(spec: string, ctx: ParseCtx): BcImport {
  // "[extern ]<extern> <mangled> (T,T,...) -> R" — the optional `extern`
  // marker flags user-supplied foreign symbols (c-emit emits a real
  // `extern …(…)` declaration) vs. stdlib `@intrinsic` host fns.
  const m = /^(extern\s+)?(\S+)\s+(\S+)\s+\((.*?)\)\s*->\s*(\S+)$/.exec(spec);
  if (m === null) fail(ctx, `malformed import "${spec}"`);
  return {
    externName: unquoteIdent(m[2]!),
    mangledName: unquoteIdent(m[3]!),
    signature: parseSignatureBody(m[4]!, m[5]!, ctx),
    isExtern: m[1] !== undefined,
  };
}

function parseSignatureBody(params: string, result: string, ctx: ParseCtx): BcSignature {
  const paramVals = params === ""
    ? []
    : params.split(",").map((s) => expectValType(s.trim(), ctx));
  // `paramTypes` / `resultType` aren't emitted in the text form — see
  // `formatSignature`. Fill with zero placeholders so the in-memory
  // shape stays uniform ; c-emit on a parsed module would fall back
  // to the non-B1 ABI.
  return {
    params: paramVals,
    result: expectValType(result.trim(), ctx),
    paramTypes: new Array(paramVals.length).fill(0),
    resultType: 0,
  };
}

function parseFn(headerLine: string, m: MutableModule, ctx: ParseCtx): void {
  // "fn <idx> <name> (params) -> result"
  const match = /^fn\s+(\d+)\s+(\S+)\s+\((.*?)\)\s*->\s*(\S+)$/.exec(headerLine);
  if (match === null) fail(ctx, `malformed fn header "${headerLine}"`);
  const idx = Number(match[1]!);
  const name = unquoteIdent(match[2]!);
  const sig = parseSignatureBody(match[3]!, match[4]!, ctx);

  const locals: BcLocal[] = [];
  const body: Op[] = [];
  const debug: (DebugPos | null)[] = [];
  // Named-label scope stack — `block`/`loop`/`if` push, `end <name>` pops.
  // The fn terminator is a bare `end` (no name) reached when the stack is
  // empty.
  const scopes: { name: string }[] = [];

  while (ctx.cur.i < ctx.lines.length) {
    const raw = ctx.lines[ctx.cur.i]!;
    ctx.cur.i++;
    const stripped = stripTrailingComment(raw).trim();
    if (stripped === "") continue;
    if (stripped === "end" && scopes.length === 0) break;
    if (stripped.startsWith("local ")) {
      const lm = /^local\s+(\S+)\s+(\S+)$/.exec(stripped);
      if (lm === null) fail(ctx, `malformed local "${stripped}"`);
      locals.push({ name: unquoteIdent(lm[1]!), val: expectValType(lm[2]!, ctx) });
      continue;
    }
    const { op, dbg } = parseOpLine(raw, scopes, ctx);
    body.push(op);
    debug.push(dbg);
  }

  // Text format predates the `isMain` flag — recover from the name suffix.
  // Convention matches the bytecode emitter (`$main` or bare `main`).
  const isMain = name === "main" || name.endsWith("$main");
  m.functions[idx] = { name, isMain, signature: sig, locals, body, debug };
}

function parseOpLine(raw: string, scopes: { name: string }[], ctx: ParseCtx): { op: Op; dbg: DebugPos | null } {
  // Split off the `; file:line:col` annotation if present.
  const trimmed = raw.trim();
  const semi = findCommentStart(trimmed);
  const opText = (semi < 0 ? trimmed : trimmed.slice(0, semi)).trim();
  const dbgText = semi < 0 ? "" : trimmed.slice(semi + 1).trim();
  return { op: parseOp(opText, scopes, ctx), dbg: parseDebug(dbgText) };
}

function findCommentStart(line: string): number {
  let inStr = false;
  for (let i = 0; i < line.length; i++) {
    const c = line[i]!;
    if (c === '"' && (i === 0 || line[i - 1] !== "\\")) inStr = !inStr;
    if (!inStr && c === ";") return i;
  }
  return -1;
}

function parseDebug(text: string): DebugPos | null {
  if (text === "") return null;
  // Matches `<file>:<line>:<column>`. File can contain `/` and `.`. We split on
  // the LAST two `:` so file paths with colons are at least mostly preserved.
  const lastColon  = text.lastIndexOf(":");
  if (lastColon < 0) return null;
  const prevColon  = text.lastIndexOf(":", lastColon - 1);
  if (prevColon < 0) return null;
  const file = text.slice(0, prevColon);
  const line = Number(text.slice(prevColon + 1, lastColon));
  const column = Number(text.slice(lastColon + 1));
  if (Number.isNaN(line) || Number.isNaN(column)) return null;
  return { file, line, column };
}

function parseOp(text: string, scopes: { name: string }[], ctx: ParseCtx): Op {
  const head = firstWord(text);
  const tail = text.slice(head.length).trim();
  switch (head) {
    case "i32.const":    return { kind: "i32.const", value: Number(tail) };
    case "i64.const":    return { kind: "i64.const", value: BigInt(tail) };
    case "f32.const":    return { kind: "f32.const", value: parseFloatLit(tail) };
    case "f64.const":    return { kind: "f64.const", value: parseFloatLit(tail) };
    case "bool.const":   return { kind: "bool.const", value: tail === "true" };
    case "char.const":   return { kind: "char.const", value: Number(tail) };
    case "string.const": return { kind: "string.const", index: Number(tail) };
    case "null.const":   return { kind: "null.const" };
    case "local.get":    return { kind: "local.get", slot: Number(tail) };
    case "local.set":    return { kind: "local.set", slot: Number(tail) };
    case "local.tee":    return { kind: "local.tee", slot: Number(tail) };
    case "block": case "loop": case "if": {
      // `block $name <result>` / `loop $name <result>` / `if $name <result>`.
      const sp = tail.indexOf(" ");
      if (sp < 0) fail(ctx, `${head} expects "<name> <result>"`);
      scopes.push({ name: tail.slice(0, sp) });
      return { kind: head, result: expectValType(tail.slice(sp + 1).trim(), ctx) };
    }
    case "end": {
      const top = scopes.pop();
      if (tail !== "" && top !== undefined && tail !== top.name) {
        fail(ctx, `end mismatch — expected ${top.name}, got ${tail}`);
      }
      return { kind: "end" };
    }
    case "br":
    case "br_if":       return { kind: head as "br" | "br_if", depth: resolveScope(tail, scopes, ctx) };
    case "call":         return { kind: "call",  fnIndex: Number(tail) };
    case "call.import":  return { kind: "call.import", importIndex: Number(tail) };
    case "call.indirect": return { kind: "call.indirect", typeIndex: Number(tail) };
    case "virtual.call": {
      const sp = tail.indexOf(" ");
      if (sp < 0) fail(ctx, `virtual.call needs paramCount and key`);
      return { kind: "virtual.call",
               paramCount: Number(tail.slice(0, sp)),
               vtableKey: tail.slice(sp + 1) };
    }
    case "fn.ref": {
      const [fnIdxStr, typeIdxStr] = tail.split(/\s+/);
      return { kind: "fn.ref", fnIndex: Number(fnIdxStr), typeIndex: Number(typeIdxStr) };
    }
    case "make_closure": {
      const [fnIdxStr, typeIdxStr] = tail.split(/\s+/);
      return { kind: "make_closure", fnIndex: Number(fnIdxStr), typeIndex: Number(typeIdxStr) };
    }
    case "intrinsic": {
      const id = intrinsicIdByName(tail);
      if (id === null) fail(ctx, `unknown intrinsic "${tail}"`);
      return { kind: "intrinsic", id };
    }
    case "struct.new":   return { kind: "struct.new", typeIndex: Number(tail) };
    case "struct.new_stack": return { kind: "struct.new_stack", typeIndex: Number(tail) };
    case "struct.get": {
      const [t, f] = tail.split(/\s+/);
      return { kind: "struct.get", typeIndex: Number(t), fieldIndex: Number(f) };
    }
    case "struct.set": {
      const [t, f] = tail.split(/\s+/);
      return { kind: "struct.set", typeIndex: Number(t), fieldIndex: Number(f) };
    }
    case "struct.set_stack": {
      const [t, f] = tail.split(/\s+/);
      return { kind: "struct.set_stack", typeIndex: Number(t), fieldIndex: Number(f) };
    }
    case "array.new": {
      const [t, l] = tail.split(/\s+/);
      return { kind: "array.new", typeIndex: Number(t), length: Number(l) };
    }
    case "array.get":    return { kind: "array.get", typeIndex: Number(tail) };
    case "array.set":    return { kind: "array.set", typeIndex: Number(tail) };
    case "array.push":   return { kind: "array.push", typeIndex: Number(tail) };
    case "array.slice":  return { kind: "array.slice", typeIndex: Number(tail) };
    case "data.const": {
      const [p, t] = tail.split(/\s+/);
      return { kind: "data.const", poolIndex: Number(p), typeIndex: Number(t) };
    }
    case "type_check":   return { kind: "type_check", typeIndex: Number(tail) };
    case "type.const":   return { kind: "type.const", typeIndex: Number(tail) };
    case "ref.cast":     return { kind: "ref.cast", typeIndex: Number(tail) };
    case "return.lit": {
      // Tail is the inner const op verbatim (e.g. `bool.const true`).
      const inner = parseOp(tail, scopes, ctx);
      if (!isConstOp(inner)) {
        fail(ctx, `return.lit expects a const operand, got ${inner.kind}`);
      }
      return { kind: "return.lit", value: inner };
    }
    default:
      // Operand-less / typed-arith ops keep their kind verbatim.
      return { kind: head as Op["kind"] } as Op;
  }
}

function parseFloatLit(s: string): number {
  if (s === "Infinity")  return Infinity;
  if (s === "-Infinity") return -Infinity;
  if (s === "NaN")       return NaN;
  return Number(s);
}

// ---------------------------------------------------------------- helpers

function firstWord(line: string): string {
  const m = /^\S+/.exec(line);
  return m === null ? "" : m[0];
}

function unquoteIdent(s: string): string {
  if (s.startsWith('"') && s.endsWith('"')) return JSON.parse(s) as string;
  return s;
}

function expectValType(s: string, ctx: ParseCtx): ValType {
  if (!isValType(s)) fail(ctx, `unknown ValType "${s}"`);
  return s;
}

/** Resolve a `br <target>` operand. Accepts a named label (`$L0`) — looked up
 *  in the active scope stack — or a bare numeric depth (kept for round-trip
 *  with payloads that bypass the writer). */
function resolveScope(spec: string, scopes: readonly { name: string }[], ctx: ParseCtx): number {
  if (/^-?\d+$/.test(spec)) return Number(spec);
  for (let i = scopes.length - 1; i >= 0; i--) {
    if (scopes[i]!.name === spec) return scopes.length - 1 - i;
  }
  fail(ctx, `unknown branch label "${spec}"`);
}
