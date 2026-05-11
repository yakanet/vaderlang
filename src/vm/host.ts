// Host-side bindings for `@extern` imports. The VM resolves each `BcImport`
// by its `mangledName` against the table built here; mismatches trap.
//
// Sync I/O is required because the VM's dispatch loop is sync. Bun has no
// synchronous file API, so the on-disk operations go through `node:fs`.

import {
  accessSync,
  readdirSync as fsReadDir,
  readFileSync as fsReadFile,
  statSync as fsStat,
  writeFileSync as fsWriteFile,
} from "node:fs";

import type { BytecodeModule } from "../bytecode/module.ts";
import type { Value } from "./value.ts";
import { NULL, VOID, bool, ch, displayValue, err, num, str, asNum, asIndex, i64 } from "./value.ts";

const UTF8_ENC = new TextEncoder();
const UTF8_DEC = new TextDecoder();

export interface HostIO {
  write(s: string): void;
  writeError(s: string): void;
  /** Read one line from stdin (without the trailing newline), or null on EOF. */
  readLine(): string | null;
  /** Read exactly `n` bytes from stdin. Returns the bytes as a UTF-8
   *  string ; throws on EOF or partial read (the caller boxes into Error
   *  like `readFile`). */
  readStdin(n: number): string;
  /** Read a file as UTF-8. Throws on I/O error; the caller boxes into Error. */
  readFile(path: string): string;
  writeFile(path: string, content: string): void;
  /** True iff the path exists. Errors (e.g. permission denied) → false. */
  exists(path: string): boolean;
  /** True iff the path is a directory. Errors → false (matches `exists`). */
  isDir(path: string): boolean;
  /** Lists the immediate entries of `path` (minus `.` and `..`). Throws on
   *  I/O error ; the caller boxes into Error like `readFile`. */
  readDir(path: string): string[];
}

/** Host fn implementations may consult the running module — needed by bindings
 *  whose return type is a tagged GC object (typed array, struct) where the VM
 *  expects the value's `typeIndex` to match a concrete BcType in the module's
 *  type table. Most bindings ignore the second arg. */
export type HostFn = (args: Value[], module: BytecodeModule) => Value;

export interface HostBindings {
  /** Looks up by `mangledName` first (`std_io$print`), with `externName`
   *  fallback for hand-built tests that bypass the std/ namespace. */
  get(mangledName: string, externName: string): HostFn | null;
}

export function defaultHostIO(): HostIO {
  // Lazily slurped stdin contents. Bun has no sync partial-read API, so
  // we materialise the whole stream on first access and serve subsequent
  // reads from the buffer. `stdinBytes` carries the raw byte view used
  // by `readStdin(n)` ; `stdinLines` keeps the line-split for `readLine`.
  let stdinBytes: Uint8Array | null = null;
  let stdinCursor = 0;
  let stdinLines: string[] | null = null;

  function ensureStdinBytes(): Uint8Array {
    if (stdinBytes !== null) return stdinBytes;
    try {
      const raw = fsReadFile(0);   // returns a Buffer
      stdinBytes = new Uint8Array(raw.buffer, raw.byteOffset, raw.byteLength);
    } catch {
      stdinBytes = new Uint8Array(0);
    }
    return stdinBytes;
  }

  function ensureStdinLines(): string[] {
    if (stdinLines !== null) return stdinLines;
    const bytes = ensureStdinBytes();
    const raw = UTF8_DEC.decode(bytes);
    stdinLines = raw.length === 0 ? [] : raw.split("\n");
    if (stdinLines.length > 0 && stdinLines[stdinLines.length - 1] === "") {
      stdinLines.pop();
    }
    return stdinLines;
  }

  return {
    write(s)            { process.stdout.write(s); },
    writeError(s)       { process.stderr.write(s); },
    readLine()          { return ensureStdinLines().shift() ?? null; },
    readStdin(n) {
      const bytes = ensureStdinBytes();
      if (stdinCursor + n > bytes.length) {
        throw new Error("EOF");
      }
      const slice = bytes.subarray(stdinCursor, stdinCursor + n);
      stdinCursor += n;
      return UTF8_DEC.decode(slice);
    },
    readFile(path)      { return fsReadFile(path, "utf8"); },
    writeFile(p, c)     { fsWriteFile(p, c, "utf8"); },
    exists(p) {
      try { accessSync(p); return true; } catch { return false; }
    },
    isDir(p) {
      try { return fsStat(p).isDirectory(); } catch { return false; }
    },
    readDir(p) {
      return fsReadDir(p);
    },
  };
}

export function stdIoBindings(io: HostIO): Record<string, HostFn> {
  return {
    std_io$print:    (args) => { io.write(stringArg(args, 0));        return VOID; },
    std_io$println:  (args) => { io.write(stringArg(args, 0) + "\n"); return VOID; },
    std_io$eprint:   (args) => { io.writeError(stringArg(args, 0));        return VOID; },
    std_io$eprintln: (args) => { io.writeError(stringArg(args, 0) + "\n"); return VOID; },
    std_io$read_line:  ()     => {
      const line = io.readLine();
      return line === null ? err("EOF") : str(line);
    },
    std_io$read_stdin: (args) => {
      try { return str(io.readStdin(indexArg(args, 0))); }
      catch (e) { return err(messageOf(e)); }
    },
    std_io$read_file:  (args) => {
      try { return str(io.readFile(stringArg(args, 0))); }
      catch (e) { return err(messageOf(e)); }
    },
    std_io$write_file: (args) => {
      try { io.writeFile(stringArg(args, 0), stringArg(args, 1)); return NULL; }
      catch (e) { return err(messageOf(e)); }
    },
    std_io$exists:     (args) => bool(io.exists(stringArg(args, 0))),
    std_io$is_dir:     (args) => bool(io.isDir(stringArg(args, 0))),
    std_io$read_dir:   (args, module) => {
      try {
        const entries = io.readDir(stringArg(args, 0));
        const arrTypeIdx = findStringArrayTypeIndex(module);
        return { tag: "array" as const, typeIndex: arrTypeIdx, elements: entries.map(p => str(p)) };
      } catch (e) {
        return err(messageOf(e));
      }
    },
  };
}

/** Walk the BcType table looking for a `string[]` entry (array whose element
 *  type resolves to the `string` primitive). Returns 0 if none exists ; the
 *  caller's `type_check` will fail loudly and the trap message points at the
 *  host bindings rather than at an opaque "reached unreachable". */
function findStringArrayTypeIndex(module: BytecodeModule): number {
  const stringIdx = module.types.findIndex(t => t.kind === "primitive" && t.val === "string");
  if (stringIdx < 0) return 0;
  const arrIdx = module.types.findIndex(t => t.kind === "array" && t.element === stringIdx);
  return arrIdx < 0 ? 0 : arrIdx;
}

/** FNV-1a 64-bit hash over the raw UTF-8 bytes — mirrors vader_string_hash in C. */
function fnv1a64(s: string): bigint {
  const bytes = UTF8_ENC.encode(s);
  const MASK64 = (1n << 64n) - 1n;
  let h = 14695981039346656037n;
  for (const b of bytes) {
    h = ((h ^ BigInt(b)) * 1099511628211n) & MASK64;
  }
  return h;
}

export function stdStringBindings(): Record<string, HostFn> {
  return {
    std_string$byte_len:    (args) => i64("usize", BigInt(UTF8_ENC.encode(stringArg(args, 0)).length)),
    std_string$slice:       (args) => {
      const s = stringArg(args, 0);
      const bytes = UTF8_ENC.encode(s);
      const start = Math.max(0, indexArg(args, 1));
      const end   = Math.min(bytes.length, indexArg(args, 2));
      return str(UTF8_DEC.decode(bytes.slice(start, end)));
    },
    std_string$contains:    (args) => bool(stringArg(args, 0).includes(stringArg(args, 1))),
    std_string$starts_with: (args) => bool(stringArg(args, 0).startsWith(stringArg(args, 1))),
    std_string$ends_with:   (args) => bool(stringArg(args, 0).endsWith(stringArg(args, 1))),
    std_string$trim:        (args) => str(stringArg(args, 0).trim()),
    std_string$to_upper:    (args) => str(stringArg(args, 0).toUpperCase()),
    std_string$to_lower:    (args) => str(stringArg(args, 0).toLowerCase()),
    std_string$char_at: (args) => {
      const bytes = UTF8_ENC.encode(stringArg(args, 0));
      const i = indexArg(args, 1);
      if (i < 0 || i >= bytes.length) return ch(0);
      return ch(UTF8_DEC.decode(bytes.subarray(i, i + 4)).codePointAt(0) ?? 0);
    },
    std_string$byte_at: (args) => {
      const bytes = UTF8_ENC.encode(stringArg(args, 0));
      const i = indexArg(args, 1);
      if (i < 0 || i >= bytes.length) return num("u8", 0);
      return num("u8", bytes[i]!);
    },
    // `string implements Index(usize, char)` is `@intrinsic`-impl in std/core,
    // so the host provides the body under the impl-method mangled name.
    "std_core$string$Index$at": (args) => {
      const bytes = UTF8_ENC.encode(stringArg(args, 0));
      const i = indexArg(args, 1);
      if (i < 0 || i >= bytes.length) return ch(0);
      return ch(UTF8_DEC.decode(bytes.subarray(i, i + 4)).codePointAt(0) ?? 0);
    },
    std_string$split: (args) => {
      const s = stringArg(args, 0);
      const sep = stringArg(args, 1);
      const parts = s.split(sep);
      return { tag: "array" as const, typeIndex: 0, elements: parts.map(p => str(p)) };
    },
    std_string$parse_int:   (args) => {
      const s = stringArg(args, 0);
      const n = Number(s);
      if (s.trim() === "" || !Number.isInteger(n)) return err(`invalid integer: "${s}"`);
      return num("i32", n | 0);
    },
    std_string$parse_float: (args) => {
      const s = stringArg(args, 0);
      const n = Number(s);
      if (s.trim() === "" || isNaN(n)) return err(`invalid float: "${s}"`);
      return num("f64", n);
    },
    "std_core$string$Hash$hash": (args) => i64("u64", fnv1a64(stringArg(args, 0))),
    // `@intrinsic <T> implements Display` for every primitive — `displayValue`
    // already produces the SPEC §9 canonical form (decimal numerics, `true` /
    // `false`, codepoint-as-string for char, `null` for null).
    "std_core$i8$Display$to_string":     (args) => str(displayValue(args[0]!)),
    "std_core$i16$Display$to_string":    (args) => str(displayValue(args[0]!)),
    "std_core$i32$Display$to_string":    (args) => str(displayValue(args[0]!)),
    "std_core$i64$Display$to_string":    (args) => str(displayValue(args[0]!)),
    "std_core$isize$Display$to_string":  (args) => str(displayValue(args[0]!)),
    "std_core$u8$Display$to_string":     (args) => str(displayValue(args[0]!)),
    "std_core$u16$Display$to_string":    (args) => str(displayValue(args[0]!)),
    "std_core$u32$Display$to_string":    (args) => str(displayValue(args[0]!)),
    "std_core$u64$Display$to_string":    (args) => str(displayValue(args[0]!)),
    "std_core$usize$Display$to_string":  (args) => str(displayValue(args[0]!)),
    "std_core$f32$Display$to_string":    (args) => str(displayValue(args[0]!)),
    "std_core$f64$Display$to_string":    (args) => str(displayValue(args[0]!)),
    "std_core$bool$Display$to_string":   (args) => str(displayValue(args[0]!)),
    "std_core$char$Display$to_string":   (args) => str(displayValue(args[0]!)),
    "std_core$string$Display$to_string": (args) => str(stringArg(args, 0)),
    // `@intrinsic StringBuilder implements Display` — flushes the buffer in
    // one allocation. Receiver is the boxed StringBuilder struct ; field 0
    // is its `parts: string[]`.
    "std_string_builder$StringBuilder$Display$to_string": (args) => {
      const sb = args[0];
      if (sb === undefined || sb.tag !== "struct") {
        throw new Error(`vm: expected struct receiver, got ${sb?.tag ?? "<missing>"}`);
      }
      const partsField = sb.fields[0];
      if (partsField === undefined || partsField.tag !== "array") {
        throw new Error(`vm: StringBuilder.parts is not an array (got ${partsField?.tag ?? "<missing>"})`);
      }
      let result = "";
      for (const el of partsField.elements) {
        if (el.tag === "string") result += el.n;
      }
      return str(result);
    },
  };
}

export function stdMathBindings(): Record<string, HostFn> {
  return {
    std_math$sqrt:  (args) => num("f64", Math.sqrt(numArg(args, 0))),
    std_math$pow:   (args) => num("f64", Math.pow(numArg(args, 0), numArg(args, 1))),
    std_math$floor: (args) => num("f64", Math.floor(numArg(args, 0))),
    std_math$ceil:  (args) => num("f64", Math.ceil(numArg(args, 0))),
    std_math$round: (args) => num("f64", Math.round(numArg(args, 0))),
    std_math$sin:   (args) => num("f64", Math.sin(numArg(args, 0))),
    std_math$cos:   (args) => num("f64", Math.cos(numArg(args, 0))),
    std_math$tan:   (args) => num("f64", Math.tan(numArg(args, 0))),
  };
}

export function stdRuntimeBindings(): Record<string, HostFn> {
  // The TS VM has no real GC arena — collections are conceptually free, but
  // we still expose stable counters so test programs can drive deterministic
  // assertions across both the VM and the native backend.
  let collections = 0;
  return {
    std_runtime$collect:      ()     => { collections++; return VOID; },
    std_runtime$collections:  ()     => num("i32", collections),
    std_runtime$bytes_used:   ()     => num("i32", 0),
    std_runtime$bytes_copied: ()     => num("i32", 0),
  };
}

export function stdProcessBindings(): Record<string, HostFn> {
  // Last-call wins, single-threaded — matches the native runtime's behaviour
  // (`vader_spawn_run` stashes stdout/stderr into static buffers fetched by
  // `_last_stdout` / `_last_stderr`).
  let lastStdout = "";
  let lastStderr = "";
  return {
    std_process$spawn_run: (args) => {
      const argv = args[0];
      if (argv === undefined || argv.tag !== "array") {
        throw new Error(`vm: spawn_run: expected array at arg 0, got ${argv?.tag ?? "<missing>"}`);
      }
      const cmd = argv.elements.map((e) => e.tag === "string" ? e.n : "");
      if (cmd.length === 0 || cmd[0] === "") return num("i32", -1);
      try {
        const proc = Bun.spawnSync({ cmd, stdout: "pipe", stderr: "pipe" });
        lastStdout = new TextDecoder().decode(proc.stdout);
        lastStderr = new TextDecoder().decode(proc.stderr);
        return num("i32", proc.exitCode ?? -1);
      } catch (e) {
        lastStdout = "";
        lastStderr = messageOf(e);
        return num("i32", -1);
      }
    },
    std_process$spawn_last_stdout: () => str(lastStdout),
    std_process$spawn_last_stderr: () => str(lastStderr),
  };
}

export function makeBindings(io: HostIO): HostBindings {
  const all = { ...stdIoBindings(io), ...stdStringBindings(), ...stdMathBindings(), ...stdRuntimeBindings(), ...stdProcessBindings() };
  return {
    get(mangledName, externName) {
      return all[mangledName] ?? all[externName] ?? null;
    },
  };
}

function stringArg(args: Value[], i: number): string {
  const v = args[i];
  if (v === undefined || v.tag !== "string") {
    throw new Error(`vm: expected string at host arg ${i}, got ${v?.tag ?? "<missing>"}`);
  }
  return v.n;
}

function numArg(args: Value[], i: number): number {
  const v = args[i];
  if (v === undefined) throw new Error(`vm: missing host arg ${i}`);
  try { return asNum(v); }
  catch { throw new Error(`vm: expected numeric at host arg ${i}, got ${v.tag}`); }
}

/** Tag-agnostic integer projection — accepts i32/i64/u64/usize/isize and
 *  narrows to a JS number. Use for indices/lengths flowing in from the VM
 *  where the source type may be `i32` (legacy) or `usize` (post-migration). */
function indexArg(args: Value[], i: number): number {
  const v = args[i];
  if (v === undefined) throw new Error(`vm: missing host arg ${i}`);
  try { return asIndex(v); }
  catch { throw new Error(`vm: expected integer at host arg ${i}, got ${v.tag}`); }
}

function messageOf(e: unknown): string {
  return e instanceof Error ? e.message : String(e);
}
