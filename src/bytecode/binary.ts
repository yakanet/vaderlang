// Binary `.vir` format — section-based encoding of `BytecodeModule`.
//
// Layout: 12-byte header (magic "VADR" + version u32 + flags u32) followed
// by moduleName, types, strings, imports, exports, vtables, implTable,
// debugFiles, functions. All multi-byte integers little-endian; strings are
// u32-prefixed UTF-8; ValType is one byte (`VAL_TYPES`); op kinds are a
// u16 tag against the stable `OP_KINDS` table.
//
// No backwards compatibility pre-1.0 — version mismatch is a hard error.

import type {
  BcExport, BcFunction, BcImport, BcLocal, BcSignature, BytecodeModule, DebugPos,
} from "./module.ts";
import type { Op } from "./ops.ts";
import type { BcType, ValType } from "./types.ts";
import { BYTECODE_VERSION, formatBytecodeVersion } from "../version.ts";
import { bytecodeFail, CompilerBugError } from "../diagnostics/errors.ts";

export const MAGIC = new Uint8Array([0x56, 0x41, 0x44, 0x52]);    // "VADR"

export const FLAG_HAS_DEBUG = 0x0001;

// Named tags for every dispatch byte the encoder/decoder writes — keeps the
// wire format self-documenting at the call sites.

const enum TypeTag {
  Primitive = 0,
  Struct    = 1,
  Array     = 2,
  Union     = 3,
  Ref       = 4,
  Fn        = 5,
}

const enum Nullable {
  Absent  = 0,
  Present = 1,
}

const enum DebugTag {
  None    = 0,
  Present = 1,
}

const VAL_TYPES: readonly ValType[] = [
  "void",   "null",   "bool",   "char",   "string",
  "i8",     "i16",    "i32",    "i64",
  "u8",     "u16",    "u32",    "u64",    "usize",
  "f32",    "f64",
  "ref",    "any",
  "isize",
];

const VAL_TYPE_BY_TAG = new Map<number, ValType>(VAL_TYPES.map((v, i) => [i, v]));
const VAL_TYPE_TAG = new Map<ValType, number>(VAL_TYPES.map((v, i) => [v, i]));

function valTypeTag(v: ValType): number {
  const t = VAL_TYPE_TAG.get(v);
  if (t === undefined) throw new CompilerBugError(`binary: unknown ValType "${v}" at write time`);
  return t;
}

function valTypeFromTag(r: Reader, t: number): ValType {
  const v = VAL_TYPE_BY_TAG.get(t);
  if (v === undefined) r.fail(`unknown ValType tag ${t}`);
  return v;
}

// Op kind → u16 tag. Order is stable: appending is safe across patch bumps,
// removing or reordering requires a version bump.

const INT_WIDTHS: readonly string[] = ["i8", "i16", "i32", "i64", "u8", "u16", "u32", "u64", "usize", "isize"];
const FLOAT_WIDTHS: readonly string[] = ["f32", "f64"];
const NUM_WIDTHS: readonly string[] = [...INT_WIDTHS, ...FLOAT_WIDTHS];
const CONVERT_WIDTHS: readonly string[] = [...NUM_WIDTHS, "char"];

function buildOpKinds(): readonly string[] {
  const out: string[] = [];
  out.push("drop", "dup");
  out.push("local.get", "local.set", "local.tee");
  out.push("i32.const", "i64.const", "f32.const", "f64.const",
           "bool.const", "char.const", "null.const", "string.const");
  for (const w of NUM_WIDTHS) for (const op of ["add", "sub", "mul", "div", "rem"]) out.push(`${w}.${op}`);
  for (const w of INT_WIDTHS) for (const op of ["bitand", "bitor", "bitxor", "shl", "shr"]) out.push(`${w}.${op}`);
  for (const w of NUM_WIDTHS) for (const op of ["eq", "ne", "lt", "le", "gt", "ge"]) out.push(`${w}.${op}`);
  out.push("bool.eq", "bool.ne",
           "string.eq", "string.ne",
           "char.eq", "char.ne", "char.lt", "char.le", "char.gt", "char.ge",
           "ref.eq", "ref.ne");
  out.push("bool.and", "bool.or", "bool.not");
  for (const w of NUM_WIDTHS) out.push(`${w}.neg`);
  for (const w of INT_WIDTHS) out.push(`${w}.bitnot`);
  for (const f of CONVERT_WIDTHS) for (const t of CONVERT_WIDTHS) out.push(`${f}.to_${t}`);
  out.push("ref.cast");
  out.push("block", "loop", "if", "else", "end");
  out.push("br", "br_if", "return", "unreachable");
  out.push("call", "call.import", "call.indirect", "fn.ref", "make_closure",
           "intrinsic", "virtual.call");
  out.push("struct.new", "struct.new_stack", "struct.get", "struct.set", "struct.set_stack");
  out.push("array.new", "array.get", "array.set", "array.len", "array.push", "array.slice");
  out.push("string.concat");
  out.push("type_check");
  return out;
}

const OP_KINDS = buildOpKinds();
const OP_TAG = new Map<string, number>(OP_KINDS.map((k, i) => [k, i]));
const OP_KIND_BY_TAG = new Map<number, string>(OP_KINDS.map((k, i) => [i, k]));

if (OP_KINDS.length > 0xFFFF) throw new CompilerBugError("binary: op-kind table exceeds u16");

class Writer {
  private buf: Uint8Array = new Uint8Array(1024);
  private pos = 0;

  bytes(): Uint8Array { return this.buf.slice(0, this.pos); }

  private grow(extra: number): void {
    const need = this.pos + extra;
    if (need <= this.buf.length) return;
    let cap = this.buf.length;
    while (cap < need) cap *= 2;
    const next = new Uint8Array(cap);
    next.set(this.buf);
    this.buf = next;
  }

  u8(v: number): void {
    this.grow(1);
    this.buf[this.pos++] = v & 0xFF;
  }
  u16(v: number): void {
    this.grow(2);
    this.buf[this.pos++] = v & 0xFF;
    this.buf[this.pos++] = (v >>> 8) & 0xFF;
  }
  u32(v: number): void {
    this.grow(4);
    this.buf[this.pos++] = v & 0xFF;
    this.buf[this.pos++] = (v >>> 8) & 0xFF;
    this.buf[this.pos++] = (v >>> 16) & 0xFF;
    this.buf[this.pos++] = (v >>> 24) & 0xFF;
  }
  i32(v: number): void { this.u32(v | 0); }
  i64(v: bigint): void {
    this.grow(8);
    const lo = Number(v & 0xFFFFFFFFn);
    const hi = Number((v >> 32n) & 0xFFFFFFFFn);
    this.buf[this.pos++] = lo & 0xFF;
    this.buf[this.pos++] = (lo >>> 8) & 0xFF;
    this.buf[this.pos++] = (lo >>> 16) & 0xFF;
    this.buf[this.pos++] = (lo >>> 24) & 0xFF;
    this.buf[this.pos++] = hi & 0xFF;
    this.buf[this.pos++] = (hi >>> 8) & 0xFF;
    this.buf[this.pos++] = (hi >>> 16) & 0xFF;
    this.buf[this.pos++] = (hi >>> 24) & 0xFF;
  }
  f32(v: number): void {
    this.grow(4);
    const dv = new DataView(this.buf.buffer, this.buf.byteOffset + this.pos, 4);
    dv.setFloat32(0, v, true);
    this.pos += 4;
  }
  f64(v: number): void {
    this.grow(8);
    const dv = new DataView(this.buf.buffer, this.buf.byteOffset + this.pos, 8);
    dv.setFloat64(0, v, true);
    this.pos += 8;
  }
  bool(v: boolean): void { this.u8(v ? 1 : 0); }
  raw(b: Uint8Array): void {
    this.grow(b.length);
    this.buf.set(b, this.pos);
    this.pos += b.length;
  }
  string(s: string): void {
    const bytes = TEXT_ENCODER.encode(s);
    this.u32(bytes.length);
    this.raw(bytes);
  }
}

const TEXT_ENCODER = new TextEncoder();
// `ignoreBOM: true` keeps a leading U+FEFF in the decoded string instead of
// silently consuming it — required so a string literal that legitimately
// starts with a BOM (e.g. an embedded UTF-8 fixture) round-trips intact.
const TEXT_DECODER = new TextDecoder("utf-8", { ignoreBOM: true });

export function writeBinary(m: BytecodeModule): Uint8Array {
  const w = new Writer();
  // Header
  w.raw(MAGIC);
  w.u32(BYTECODE_VERSION);
  const hasDebug = m.functions.some((fn) => fn.debug.some((d) => d !== null));
  w.u32(hasDebug ? FLAG_HAS_DEBUG : 0);

  // Body
  w.string(m.name);
  writeTypes(w, m.types);
  writeStrings(w, m.strings);
  writeImports(w, m.imports);
  writeExports(w, m.exports);
  writeVtables(w, m.vtables);
  writeImpls(w, m.implTable);

  // Debug files pool — collected up front so per-op debug entries can index
  // it. The pool order is independent from the textual format and is purely
  // a binary-encoding optimisation.
  const debugFiles = collectDebugFiles(m.functions);
  w.u32(debugFiles.length);
  for (const f of debugFiles) w.string(f);
  const debugFileIndex = new Map(debugFiles.map((f, i) => [f, i] as const));

  writeFunctions(w, m.functions, debugFileIndex);

  return w.bytes();
}

function collectDebugFiles(fns: readonly BcFunction[]): string[] {
  const seen = new Set<string>();
  const out: string[] = [];
  for (const fn of fns) {
    for (const d of fn.debug) {
      if (d === null) continue;
      if (seen.has(d.file)) continue;
      seen.add(d.file);
      out.push(d.file);
    }
  }
  return out;
}

function writeTypes(w: Writer, types: readonly BcType[]): void {
  w.u32(types.length);
  for (const t of types) {
    switch (t.kind) {
      case "primitive":
        w.u8(TypeTag.Primitive);
        w.u8(valTypeTag(t.val));
        break;
      case "struct":
        w.u8(TypeTag.Struct);
        w.string(t.name);
        w.u32(t.fields.length);
        for (const f of t.fields) {
          w.string(f.name);
          w.u32(f.typeIndex);
        }
        break;
      case "array":
        w.u8(TypeTag.Array);
        w.u32(t.element);
        break;
      case "union":
        w.u8(TypeTag.Union);
        w.u32(t.variants.length);
        for (const v of t.variants) w.u32(v);
        break;
      case "ref":
        w.u8(TypeTag.Ref);
        if (t.traitName === null) {
          w.u8(Nullable.Absent);
        } else {
          w.u8(Nullable.Present);
          w.string(t.traitName);
        }
        break;
      case "fn":
        w.u8(TypeTag.Fn);
        w.u32(t.params.length);
        for (const p of t.params) w.u32(p);
        w.u32(t.returnType);
        break;
    }
  }
}

function writeStrings(w: Writer, strings: readonly string[]): void {
  w.u32(strings.length);
  for (const s of strings) w.string(s);
}

function writeImports(w: Writer, imports: readonly BcImport[]): void {
  w.u32(imports.length);
  for (const i of imports) {
    w.string(i.externName);
    w.string(i.mangledName);
    writeSignature(w, i.signature);
  }
}

function writeExports(w: Writer, exports: readonly BcExport[]): void {
  w.u32(exports.length);
  for (const e of exports) {
    w.string(e.externName);
    w.u32(e.fnIndex);
  }
}

function writeVtables(w: Writer, vtables: ReadonlyMap<string, ReadonlyMap<number, number>>): void {
  w.u32(vtables.size);
  for (const [key, entries] of vtables) {
    w.string(key);
    w.u32(entries.size);
    for (const [typeIndex, fnIndex] of entries) {
      w.u32(typeIndex);
      w.u32(fnIndex);
    }
  }
}

function writeImpls(w: Writer, impls: ReadonlyMap<number, readonly string[]>): void {
  w.u32(impls.size);
  for (const [typeIndex, traits] of impls) {
    w.u32(typeIndex);
    w.u32(traits.length);
    for (const t of traits) w.string(t);
  }
}

function writeSignature(w: Writer, s: BcSignature): void {
  w.u32(s.params.length);
  for (const p of s.params) w.u8(valTypeTag(p));
  w.u8(valTypeTag(s.result));
  // `paramTypes` / `resultType` are deliberately omitted — they're
  // consumed only by c-emit in-memory (for B1 detection at the fn
  // boundary) and no `.vir → c-emit` workflow exists today. Re-add a
  // pair of u32-arrays here if that path is ever introduced.
}

function writeFunctions(
  w: Writer, fns: readonly BcFunction[], debugFileIndex: ReadonlyMap<string, number>,
): void {
  w.u32(fns.length);
  for (const fn of fns) {
    w.string(fn.name);
    writeSignature(w, fn.signature);
    w.u32(fn.locals.length);
    for (const l of fn.locals) {
      w.string(l.name);
      w.u8(valTypeTag(l.val));
    }
    w.u32(fn.body.length);
    for (let i = 0; i < fn.body.length; i++) {
      writeOp(w, fn.body[i]!);
      const d = fn.debug[i];
      if (d === undefined || d === null) {
        w.u8(DebugTag.None);
      } else {
        w.u8(DebugTag.Present);
        const fi = debugFileIndex.get(d.file);
        if (fi === undefined) throw new CompilerBugError(`binary: debug file "${d.file}" missing from pool at write time`);
        w.u32(fi);
        w.u32(d.line);
        w.u32(d.column);
      }
    }
  }
}

function writeOp(w: Writer, op: Op): void {
  const tag = OP_TAG.get(op.kind);
  if (tag === undefined) throw new CompilerBugError(`binary: unknown op kind "${op.kind}" at write time`);
  w.u16(tag);
  // Operand encoding per kind (only the kinds that carry operands need a
  // case; pure-kind ops emit nothing past the tag).
  switch (op.kind) {
    case "local.get": case "local.set": case "local.tee":
      w.u32(op.slot); return;
    case "i32.const":
      w.i32(op.value); return;
    case "i64.const":
      w.i64(op.value); return;
    case "f32.const":
      w.f32(op.value); return;
    case "f64.const":
      w.f64(op.value); return;
    case "bool.const":
      w.bool(op.value); return;
    case "char.const":
      w.u32(op.value); return;
    case "string.const":
      w.u32(op.index); return;
    case "block": case "loop": case "if":
      w.u8(valTypeTag(op.result)); return;
    case "br": case "br_if":
      w.u32(op.depth); return;
    case "call":
      w.u32(op.fnIndex); return;
    case "call.import":
      w.u32(op.importIndex); return;
    case "call.indirect":
      w.u32(op.typeIndex); return;
    case "fn.ref": case "make_closure":
      w.u32(op.fnIndex); w.u32(op.typeIndex); return;
    case "intrinsic":
      w.u32(op.id); return;
    case "virtual.call":
      w.u32(op.paramCount); w.string(op.vtableKey); return;
    case "struct.new": case "struct.new_stack":
      w.u32(op.typeIndex); return;
    case "struct.get": case "struct.set": case "struct.set_stack":
      w.u32(op.typeIndex); w.u32(op.fieldIndex); return;
    case "array.new":
      w.u32(op.typeIndex); w.u32(op.length); return;
    case "array.get": case "array.set": case "array.push": case "array.slice":
      w.u32(op.typeIndex); return;
    case "ref.cast": case "type_check":
      w.u32(op.typeIndex); return;
    default:
      // Pure-kind ops (drop, dup, return, end, ..., all arithmetic / cmp /
      // convert) carry no operands beyond the tag.
      return;
  }
}

class Reader {
  constructor(
    private readonly buf: Uint8Array,
    private readonly path: string | null = null,
    private pos: number = 0,
  ) {}

  remaining(): number { return this.buf.length - this.pos; }
  position(): number { return this.pos; }

  fail(message: string): never {
    bytecodeFail("binary", message, {
      path: this.path,
      position: { kind: "binary", byteOffset: this.pos },
    });
  }

  u8(): number {
    if (this.pos >= this.buf.length) this.fail("unexpected EOF (u8)");
    return this.buf[this.pos++]!;
  }
  u16(): number {
    if (this.pos + 2 > this.buf.length) this.fail("unexpected EOF (u16)");
    const v = this.buf[this.pos]! | (this.buf[this.pos + 1]! << 8);
    this.pos += 2;
    return v;
  }
  u32(): number {
    if (this.pos + 4 > this.buf.length) this.fail("unexpected EOF (u32)");
    const v = (this.buf[this.pos]!
            | (this.buf[this.pos + 1]! << 8)
            | (this.buf[this.pos + 2]! << 16)
            | (this.buf[this.pos + 3]! << 24)) >>> 0;
    this.pos += 4;
    return v;
  }
  i32(): number { return this.u32() | 0; }
  i64(): bigint {
    if (this.pos + 8 > this.buf.length) this.fail("unexpected EOF (i64)");
    const lo = BigInt(this.u32());
    const hi = BigInt(this.u32() | 0);     // sign-extend high word
    return (hi << 32n) | lo;
  }
  f32(): number {
    if (this.pos + 4 > this.buf.length) this.fail("unexpected EOF (f32)");
    const dv = new DataView(this.buf.buffer, this.buf.byteOffset + this.pos, 4);
    const v = dv.getFloat32(0, true);
    this.pos += 4;
    return v;
  }
  f64(): number {
    if (this.pos + 8 > this.buf.length) this.fail("unexpected EOF (f64)");
    const dv = new DataView(this.buf.buffer, this.buf.byteOffset + this.pos, 8);
    const v = dv.getFloat64(0, true);
    this.pos += 8;
    return v;
  }
  bool(): boolean { return this.u8() !== 0; }
  raw(n: number): Uint8Array {
    if (this.pos + n > this.buf.length) this.fail(`unexpected EOF (raw ${n})`);
    const out = this.buf.subarray(this.pos, this.pos + n);
    this.pos += n;
    return out;
  }
  string(): string {
    const len = this.u32();
    return TEXT_DECODER.decode(this.raw(len));
  }
}

export function parseBinary(bytes: Uint8Array, path: string | null = null): BytecodeModule {
  const r = new Reader(bytes, path);
  // Header
  const m = r.raw(4);
  if (m[0] !== MAGIC[0] || m[1] !== MAGIC[1] || m[2] !== MAGIC[2] || m[3] !== MAGIC[3]) {
    r.fail("bad magic — not a Vader IR module");
  }
  const version = r.u32();
  if (version !== BYTECODE_VERSION) {
    const want = formatBytecodeVersion(BYTECODE_VERSION);
    const got = formatBytecodeVersion(version);
    r.fail(`version mismatch (file is ${got}, runtime expects ${want})`);
  }
  r.u32();                                  // flags — reserved for future use
  const name = r.string();

  const types = readTypes(r);
  const strings = readStrings(r);
  const imports = readImports(r);
  const exports = readExports(r);
  const vtables = readVtables(r);
  const implTable = readImpls(r);
  const debugFiles = readDebugFiles(r);
  const functions = readFunctions(r, debugFiles);

  return { name, types, strings, functions, imports, exports, implTable, vtables };
}

function readTypes(r: Reader): BcType[] {
  const n = r.u32();
  const out: BcType[] = [];
  for (let i = 0; i < n; i++) {
    const tag = r.u8();
    switch (tag) {
      case TypeTag.Primitive:
        out.push({ kind: "primitive", val: valTypeFromTag(r, r.u8()) });
        break;
      case TypeTag.Struct: {
        const name = r.string();
        const fc = r.u32();
        const fields = [];
        for (let j = 0; j < fc; j++) fields.push({ name: r.string(), typeIndex: r.u32() });
        out.push({ kind: "struct", name, fields });
        break;
      }
      case TypeTag.Array:
        out.push({ kind: "array", element: r.u32() });
        break;
      case TypeTag.Union: {
        const vc = r.u32();
        const variants: number[] = [];
        for (let j = 0; j < vc; j++) variants.push(r.u32());
        out.push({ kind: "union", variants });
        break;
      }
      case TypeTag.Ref: {
        const marker = r.u8();
        out.push({ kind: "ref", traitName: marker === Nullable.Absent ? null : r.string() });
        break;
      }
      case TypeTag.Fn: {
        const pc = r.u32();
        const params: number[] = [];
        for (let j = 0; j < pc; j++) params.push(r.u32());
        const returnType = r.u32();
        out.push({ kind: "fn", params, returnType });
        break;
      }
      default:
        r.fail(`unknown type tag ${tag}`);
    }
  }
  return out;
}

function readStrings(r: Reader): string[] {
  const n = r.u32();
  const out: string[] = [];
  for (let i = 0; i < n; i++) out.push(r.string());
  return out;
}

function readImports(r: Reader): BcImport[] {
  const n = r.u32();
  const out: BcImport[] = [];
  for (let i = 0; i < n; i++) {
    const externName = r.string();
    const mangledName = r.string();
    const signature = readSignature(r);
    out.push({ externName, mangledName, signature });
  }
  return out;
}

function readExports(r: Reader): BcExport[] {
  const n = r.u32();
  const out: BcExport[] = [];
  for (let i = 0; i < n; i++) out.push({ externName: r.string(), fnIndex: r.u32() });
  return out;
}

function readVtables(r: Reader): Map<string, Map<number, number>> {
  const n = r.u32();
  const out = new Map<string, Map<number, number>>();
  for (let i = 0; i < n; i++) {
    const key = r.string();
    const ec = r.u32();
    const entries = new Map<number, number>();
    for (let j = 0; j < ec; j++) {
      const ti = r.u32();
      const fi = r.u32();
      entries.set(ti, fi);
    }
    out.set(key, entries);
  }
  return out;
}

function readImpls(r: Reader): Map<number, string[]> {
  const n = r.u32();
  const out = new Map<number, string[]>();
  for (let i = 0; i < n; i++) {
    const ti = r.u32();
    const tc = r.u32();
    const traits: string[] = [];
    for (let j = 0; j < tc; j++) traits.push(r.string());
    out.set(ti, traits);
  }
  return out;
}

function readSignature(r: Reader): BcSignature {
  const pc = r.u32();
  const params: ValType[] = [];
  for (let i = 0; i < pc; i++) params.push(valTypeFromTag(r, r.u8()));
  const result = valTypeFromTag(r, r.u8());
  // Fabricate `paramTypes` / `resultType` placeholders — the writer
  // doesn't emit them and the VM doesn't read them. A c-emit pass over
  // a deserialised module would see all zeros here and fall back to
  // the non-B1 ABI ; that workflow doesn't exist today.
  return { params, result, paramTypes: new Array(pc).fill(0), resultType: 0 };
}

function readDebugFiles(r: Reader): string[] {
  const n = r.u32();
  const out: string[] = [];
  for (let i = 0; i < n; i++) out.push(r.string());
  return out;
}

function readFunctions(r: Reader, debugFiles: readonly string[]): BcFunction[] {
  const n = r.u32();
  const out: BcFunction[] = [];
  for (let i = 0; i < n; i++) {
    const name = r.string();
    const signature = readSignature(r);
    const lc = r.u32();
    const locals: BcLocal[] = [];
    for (let j = 0; j < lc; j++) locals.push({ name: r.string(), val: valTypeFromTag(r, r.u8()) });
    const oc = r.u32();
    const body: Op[] = [];
    const debug: (DebugPos | null)[] = [];
    for (let j = 0; j < oc; j++) {
      body.push(readOp(r));
      const marker = r.u8();
      if (marker === DebugTag.None) {
        debug.push(null);
      } else {
        const fi = r.u32();
        const line = r.u32();
        const column = r.u32();
        const file = debugFiles[fi];
        if (file === undefined) r.fail(`debug file index ${fi} out of range`);
        debug.push({ file, line, column });
      }
    }
    // Binary format predates the `isMain` flag — recover it from the name
    // suffix until the format gains a per-fn flags byte. The convention
    // matches what the bytecode emitter writes (`$main` suffix for the
    // user's main fn, plus the unsuffixed `main` produced by single-
    // module mode).
    const isMain = name === "main" || name.endsWith("$main");
    out.push({ name, isMain, signature, locals, body, debug });
  }
  return out;
}

function readOp(r: Reader): Op {
  const tag = r.u16();
  const kind = OP_KIND_BY_TAG.get(tag);
  if (kind === undefined) r.fail(`unknown op tag ${tag}`);
  switch (kind) {
    case "local.get": case "local.set": case "local.tee":
      return { kind, slot: r.u32() } as Op;
    case "i32.const":
      // The emitter normalises `i32.const` payloads to the unsigned u32
      // range (e.g. `Number(0xFFFFFFFFn) = 4294967295`, not -1) so the textual
      // dump matches the source-level constant. Read as u32 to preserve that.
      return { kind: "i32.const", value: r.u32() };
    case "i64.const":
      return { kind: "i64.const", value: r.i64() };
    case "f32.const":
      return { kind: "f32.const", value: r.f32() };
    case "f64.const":
      return { kind: "f64.const", value: r.f64() };
    case "bool.const":
      return { kind: "bool.const", value: r.bool() };
    case "char.const":
      return { kind: "char.const", value: r.u32() };
    case "string.const":
      return { kind: "string.const", index: r.u32() };
    case "block": case "loop": case "if":
      return { kind, result: valTypeFromTag(r, r.u8()) } as Op;
    case "br": case "br_if":
      return { kind, depth: r.u32() } as Op;
    case "call":
      return { kind: "call", fnIndex: r.u32() };
    case "call.import":
      return { kind: "call.import", importIndex: r.u32() };
    case "call.indirect":
      return { kind: "call.indirect", typeIndex: r.u32() };
    case "fn.ref":
      return { kind: "fn.ref", fnIndex: r.u32(), typeIndex: r.u32() };
    case "make_closure":
      return { kind: "make_closure", fnIndex: r.u32(), typeIndex: r.u32() };
    case "intrinsic":
      return { kind: "intrinsic", id: r.u32() } as Op;
    case "virtual.call":
      return { kind: "virtual.call", paramCount: r.u32(), vtableKey: r.string() };
    case "struct.new": case "struct.new_stack":
      return { kind, typeIndex: r.u32() } as Op;
    case "struct.get": case "struct.set": case "struct.set_stack":
      return { kind, typeIndex: r.u32(), fieldIndex: r.u32() } as Op;
    case "array.new":
      return { kind: "array.new", typeIndex: r.u32(), length: r.u32() };
    case "array.get": case "array.set": case "array.push": case "array.slice":
      return { kind, typeIndex: r.u32() } as Op;
    case "ref.cast":
      return { kind: "ref.cast", typeIndex: r.u32() };
    case "type_check":
      return { kind: "type_check", typeIndex: r.u32() };
    default:
      // Pure-kind op (no operands beyond the tag).
      return { kind } as Op;
  }
}
