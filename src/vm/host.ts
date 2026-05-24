// Host-side bindings for `@extern` imports. The VM resolves each `BcImport`
// by its `mangledName` against the table built here; mismatches trap.
//
// Sync I/O is required because the VM's dispatch loop is sync. Bun has no
// synchronous file API, so the on-disk operations go through `node:fs`.

import {
  accessSync,
  readdirSync as fsReadDir,
  readFileSync as fsReadFile,
  readSync as fsReadSync,
  statSync as fsStat,
  writeFileSync as fsWriteFile,
} from "node:fs";

import type { BytecodeModule } from "../bytecode/module.ts";
import type { Value } from "./value.ts";
import { NULL, VOID, bool, ch, displayValue, err, num, str, asNum, asIndex, i64 } from "./value.ts";
import { VmError } from "./exec.ts";

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
  // Incremental stdin buffer. The previous implementation slurped fd 0
  // up-front via `readFileSync(0)` — convenient for short-lived CLI
  // commands but fatal for long-running protocols like LSP, where the
  // peer keeps the pipe open and slurping blocks until process death.
  // We now refill on demand via `readSync` chunks, draining `pending`
  // before returning to the caller. Consumed bytes are sliced off (copy)
  // so the backing ArrayBuffer doesn't grow unbounded across a session.
  let pending = new Uint8Array(0);
  let stdinEof = false;
  const READ_CHUNK = 8192;

  function fillStdin(minBytes: number): void {
    while (!stdinEof && pending.length < minBytes) {
      const chunk = new Uint8Array(READ_CHUNK);
      let got = 0;
      try {
        got = fsReadSync(0, chunk, 0, chunk.length, null);
      } catch {
        stdinEof = true;
        return;
      }
      if (got === 0) { stdinEof = true; return; }
      const merged = new Uint8Array(pending.length + got);
      merged.set(pending, 0);
      merged.set(chunk.subarray(0, got), pending.length);
      pending = merged;
    }
  }

  return {
    write(s)            { process.stdout.write(s); },
    writeError(s)       { process.stderr.write(s); },
    readLine() {
      // Scan for the next \n, refilling as needed. Returns null on EOF
      // with no buffered data ; returns the buffered tail (without
      // trailing \r) when EOF arrives mid-line.
      while (true) {
        const idx = pending.indexOf(0x0A);
        if (idx >= 0) {
          const line = UTF8_DEC.decode(pending.subarray(0, idx));
          pending = pending.slice(idx + 1);
          return line.endsWith("\r") ? line.slice(0, -1) : line;
        }
        if (stdinEof) {
          if (pending.length === 0) return null;
          const line = UTF8_DEC.decode(pending);
          pending = new Uint8Array(0);
          return line.endsWith("\r") ? line.slice(0, -1) : line;
        }
        fillStdin(pending.length + 1);
      }
    },
    readStdin(n) {
      fillStdin(n);
      if (pending.length < n) throw new Error("EOF");
      const slice = pending.subarray(0, n);
      const out = UTF8_DEC.decode(slice);
      pending = pending.slice(n);
      return out;
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
        const elements = entries.map(p => str(p));
        return { tag: "array" as const, typeIndex: arrTypeIdx, elements, offset: 0, length: elements.length };
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
    std_string$byte_slice:  (args) => {
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
    std_string$byte_at: (args) => {
      const bytes = UTF8_ENC.encode(stringArg(args, 0));
      const i = indexArg(args, 1);
      if (i < 0 || i >= bytes.length) return num("u8", 0);
      return num("u8", bytes[i]!);
    },
    // Decode the UTF-8 codepoint at byte offset `i`. Mirrors C
    // `vader_string_char_at`. Lets parsers keep a byte cursor while
    // comparing against ASCII char literals.
    std_string$byte_decode_at: (args) => {
      const bytes = UTF8_ENC.encode(stringArg(args, 0));
      const i = indexArg(args, 1);
      if (i < 0 || i >= bytes.length) return ch(0);
      return ch(UTF8_DEC.decode(bytes.subarray(i, i + 4)).codePointAt(0) ?? 0);
    },
    // `string implements Index(usize, char)` is `@intrinsic`-impl in std/core,
    // so the host provides the body under the impl-method mangled name.
    // Indexes by codepoint ; for byte access use `byte_at` / `byte_decode_at`.
    "std_core$string$Index$at": (args) => {
      const s = stringArg(args, 0);
      const i = indexArg(args, 1);
      // JS strings index by UTF-16 code units, so walk via `for...of`
      // which yields codepoints. The TS VM is the reference impl ; the
      // native runtime traps on OOB instead of returning 0.
      let cp = 0;
      for (const c of s) {
        if (cp === i) return ch(c.codePointAt(0) ?? 0);
        cp++;
      }
      return ch(0);
    },
    std_string$split: (args) => {
      const s = stringArg(args, 0);
      const sep = stringArg(args, 1);
      const parts = s.split(sep);
      const elements = parts.map(p => str(p));
      return { tag: "array" as const, typeIndex: 0, elements, offset: 0, length: elements.length };
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
      for (let i = 0; i < partsField.length; i++) {
        const el = partsField.elements[partsField.offset + i]!;
        if (el.tag === "string") result += el.n;
      }
      return str(result);
    },
  };
}

export function stdTimeBindings(): Record<string, HostFn> {
  return {
    std_time$now_unix_ms:  () => i64("i64", BigInt(Date.now())),
    std_time$monotonic_ns: () => i64("i64", BigInt(Math.trunc(performance.now() * 1e6))),
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
      const cmd: string[] = [];
      for (let i = 0; i < argv.length; i++) {
        const e = argv.elements[argv.offset + i]!;
        cmd.push(e.tag === "string" ? e.n : "");
      }
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

export function stdTestingBindings(): Record<string, HostFn> {
  return {
    std_testing$panic: (args) => {
      throw new VmError(`vader: panic — ${stringArg(args, 0)}`);
    },
  };
}

export function makeBindings(io: HostIO): HostBindings {
  const all = { ...stdIoBindings(io), ...stdStringBindings(), ...stdTimeBindings(), ...stdMathBindings(), ...stdRuntimeBindings(), ...stdProcessBindings(), ...stdTestingBindings() };
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
