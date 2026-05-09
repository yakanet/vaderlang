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
import { intrinsicIdByName, intrinsicNameById } from "./ops.ts";
import type { BcType, ValType } from "./types.ts";
import { isValType } from "./types.ts";

// ---------------------------------------------------------------- writer

export function writeVir(m: BytecodeModule): string {
  const out: string[] = [];
  out.push(`module ${m.name}`);

  for (let i = 0; i < m.types.length; i++) out.push(`type ${i} ${formatType(m.types[i]!)}`);
  for (let i = 0; i < m.strings.length; i++) out.push(`string ${i} ${formatString(m.strings[i]!)}`);
  for (let i = 0; i < m.imports.length; i++) out.push(`import ${i} ${formatImport(m.imports[i]!)}`);
  for (const e of m.exports) out.push(`export ${quoteIdent(e.externName)} ${e.fnIndex}`);

  for (let i = 0; i < m.functions.length; i++) {
    out.push("");
    formatFunction(m.functions[i]!, i, out);
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

function formatImport(i: BcImport): string {
  return `${quoteIdent(i.externName)} ${quoteIdent(i.mangledName)} ${formatSignature(i.signature)}`;
}

function formatSignature(s: BcSignature): string {
  return `(${s.params.join(",")}) -> ${s.result}`;
}

function formatFunction(fn: BcFunction, idx: number, out: string[]): void {
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

    out.push(`${indent}${line}${formatDebug(dbg ?? null)}`);
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
    case "array.new":    return `array.new ${op.typeIndex} ${op.length}`;
    case "array.get":    return `array.get ${op.typeIndex}`;
    case "array.set":    return `array.set ${op.typeIndex}`;
    case "array.push":   return `array.push ${op.typeIndex}`;
    case "type_check":   return `type_check ${op.typeIndex}`;
    case "ref.cast":     return `ref.cast ${op.typeIndex}`;
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

export function parseVir(text: string): BytecodeModule {
  const lines = text.split("\n");
  const cur = { i: 0 };
  const m = newMutableModule();

  while (cur.i < lines.length) {
    const raw = lines[cur.i]!;
    cur.i++;
    const stripped = stripTrailingComment(raw).trim();
    if (stripped === "") continue;
    parseHeaderLine(stripped, m, lines, cur);
  }
  return finalizeModule(m);
}

interface MutableModule {
  name: string;
  types: BcType[];
  strings: string[];
  functions: BcFunction[];
  imports: BcImport[];
  exports: BcExport[];
}

function newMutableModule(): MutableModule {
  return { name: "", types: [], strings: [], functions: [], imports: [], exports: [] };
}

function finalizeModule(m: MutableModule): BytecodeModule {
  return {
    name: m.name, types: m.types, strings: m.strings,
    functions: m.functions, imports: m.imports, exports: m.exports,
    implTable: new Map(),
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

function parseHeaderLine(line: string, m: MutableModule, lines: string[], cur: { i: number }): void {
  const head = firstWord(line);
  const rest = line.slice(head.length).trim();
  switch (head) {
    case "module":
      m.name = rest;
      return;
    case "type": {
      const [idxStr, ...spec] = rest.split(/\s+/);
      const idx = Number(idxStr);
      m.types[idx] = parseType(spec.join(" "));
      return;
    }
    case "string": {
      const sp = rest.indexOf(" ");
      const idx = Number(rest.slice(0, sp));
      m.strings[idx] = JSON.parse(rest.slice(sp + 1)) as string;
      return;
    }
    case "import": {
      const [idxStr, ...spec] = rest.split(/\s+/);
      const idx = Number(idxStr);
      m.imports[idx] = parseImport(spec.join(" "));
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
    case "fn":
      parseFn(line, lines, cur, m);
      return;
    default:
      throw new Error(`vir parse: unknown header "${head}"`);
  }
}

function parseType(spec: string): BcType {
  const head = firstWord(spec);
  const rest = spec.slice(head.length).trim();
  switch (head) {
    case "primitive": return { kind: "primitive", val: expectValType(rest) };
    case "array":     return { kind: "array", element: Number(rest) };
    case "union":     return { kind: "union", variants: rest.split(",").map(Number) };
    case "ref":       return { kind: "ref", traitName: rest === "_" ? null : unquoteIdent(rest) };
    case "fn": {
      const fm = /^\((.*?)\)\s*->\s*(\d+)$/.exec(rest);
      if (fm === null) throw new Error(`vir parse: malformed fn type "${spec}"`);
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
    default: throw new Error(`vir parse: unknown type kind "${head}"`);
  }
}

function parseImport(spec: string): BcImport {
  // "<extern> <mangled> (T,T,...) -> R"
  const m = /^(\S+)\s+(\S+)\s+\((.*?)\)\s*->\s*(\S+)$/.exec(spec);
  if (m === null) throw new Error(`vir parse: malformed import "${spec}"`);
  return {
    externName: unquoteIdent(m[1]!),
    mangledName: unquoteIdent(m[2]!),
    signature: parseSignatureBody(m[3]!, m[4]!),
  };
}

function parseSignatureBody(params: string, result: string): BcSignature {
  return {
    params: params === "" ? [] : params.split(",").map((s) => expectValType(s.trim())),
    result: expectValType(result.trim()),
  };
}

function parseFn(headerLine: string, lines: string[], cur: { i: number }, m: MutableModule): void {
  // "fn <idx> <name> (params) -> result"
  const match = /^fn\s+(\d+)\s+(\S+)\s+\((.*?)\)\s*->\s*(\S+)$/.exec(headerLine);
  if (match === null) throw new Error(`vir parse: malformed fn header "${headerLine}"`);
  const idx = Number(match[1]!);
  const name = unquoteIdent(match[2]!);
  const sig = parseSignatureBody(match[3]!, match[4]!);

  const locals: BcLocal[] = [];
  const body: Op[] = [];
  const debug: (DebugPos | null)[] = [];
  // Named-label scope stack — `block`/`loop`/`if` push, `end <name>` pops.
  // The fn terminator is a bare `end` (no name) reached when the stack is
  // empty.
  const scopes: { name: string }[] = [];

  while (cur.i < lines.length) {
    const raw = lines[cur.i]!;
    cur.i++;
    const stripped = stripTrailingComment(raw).trim();
    if (stripped === "") continue;
    if (stripped === "end" && scopes.length === 0) break;
    if (stripped.startsWith("local ")) {
      const lm = /^local\s+(\S+)\s+(\S+)$/.exec(stripped);
      if (lm === null) throw new Error(`vir parse: malformed local "${stripped}"`);
      locals.push({ name: unquoteIdent(lm[1]!), val: expectValType(lm[2]!) });
      continue;
    }
    const { op, dbg } = parseOpLine(raw, scopes);
    body.push(op);
    debug.push(dbg);
  }

  m.functions[idx] = { name, signature: sig, locals, body, debug };
}

function parseOpLine(raw: string, scopes: { name: string }[]): { op: Op; dbg: DebugPos | null } {
  // Split off the `; file:line:col` annotation if present.
  const trimmed = raw.trim();
  const semi = findCommentStart(trimmed);
  const opText = (semi < 0 ? trimmed : trimmed.slice(0, semi)).trim();
  const dbgText = semi < 0 ? "" : trimmed.slice(semi + 1).trim();
  return { op: parseOp(opText, scopes), dbg: parseDebug(dbgText) };
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

function parseOp(text: string, scopes: { name: string }[]): Op {
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
      if (sp < 0) throw new Error(`vir parse: ${head} expects "<name> <result>"`);
      scopes.push({ name: tail.slice(0, sp) });
      return { kind: head, result: expectValType(tail.slice(sp + 1).trim()) };
    }
    case "end": {
      // `end $name` pops the named scope ; bare `end` is a defensive fallback.
      const top = scopes.pop();
      if (tail !== "" && top !== undefined && tail !== top.name) {
        throw new Error(`vir parse: end mismatch — expected ${top.name}, got ${tail}`);
      }
      return { kind: "end" };
    }
    case "br":
    case "br_if":       return { kind: head as "br" | "br_if", depth: resolveScope(tail, scopes) };
    case "call":         return { kind: "call",  fnIndex: Number(tail) };
    case "call.import":  return { kind: "call.import", importIndex: Number(tail) };
    case "call.indirect": return { kind: "call.indirect", typeIndex: Number(tail) };
    case "virtual.call": {
      const sp = tail.indexOf(" ");
      if (sp < 0) throw new Error(`vir parse: virtual.call needs paramCount and key`);
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
      if (id === null) throw new Error(`vir parse: unknown intrinsic "${tail}"`);
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
    case "array.new": {
      const [t, l] = tail.split(/\s+/);
      return { kind: "array.new", typeIndex: Number(t), length: Number(l) };
    }
    case "array.get":    return { kind: "array.get", typeIndex: Number(tail) };
    case "array.set":    return { kind: "array.set", typeIndex: Number(tail) };
    case "array.push":   return { kind: "array.push", typeIndex: Number(tail) };
    case "type_check":   return { kind: "type_check", typeIndex: Number(tail) };
    case "ref.cast":     return { kind: "ref.cast", typeIndex: Number(tail) };
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

function expectValType(s: string): ValType {
  if (!isValType(s)) throw new Error(`vir parse: unknown ValType "${s}"`);
  return s;
}

/** Resolve a `br <target>` operand. Accepts a named label (`$L0`) — looked up
 *  in the active scope stack — or a bare numeric depth (kept for round-trip
 *  with payloads that bypass the writer). */
function resolveScope(spec: string, scopes: readonly { name: string }[]): number {
  if (/^-?\d+$/.test(spec)) return Number(spec);
  for (let i = scopes.length - 1; i >= 0; i--) {
    if (scopes[i]!.name === spec) return scopes.length - 1 - i;
  }
  throw new Error(`vir parse: unknown branch label "${spec}"`);
}
