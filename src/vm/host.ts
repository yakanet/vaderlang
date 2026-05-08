// Host-side bindings for `@extern` imports. The VM resolves each `BcImport`
// by its `mangledName` against the table built here; mismatches trap.
//
// Sync I/O is required because the VM's dispatch loop is sync. Bun has no
// synchronous file API, so the on-disk operations go through `node:fs`.

import { accessSync, readFileSync as fsReadFile, writeFileSync as fsWriteFile } from "node:fs";

import type { Value } from "./value.ts";
import { NULL, VOID, bool, ch, err, num, str, asNum, i64 } from "./value.ts";

const UTF8_ENC = new TextEncoder();
const UTF8_DEC = new TextDecoder();

export interface HostIO {
  write(s: string): void;
  writeError(s: string): void;
  /** Read one line from stdin (without the trailing newline), or null on EOF. */
  readLine(): string | null;
  /** Read a file as UTF-8. Throws on I/O error; the caller boxes into Error. */
  readFile(path: string): string;
  writeFile(path: string, content: string): void;
  /** True iff the path exists. Errors (e.g. permission denied) → false. */
  exists(path: string): boolean;
}

export type HostFn = (args: Value[]) => Value;

export interface HostBindings {
  /** Looks up by `mangledName` first (`std_io$print`), with `externName`
   *  fallback for hand-built tests that bypass the std/ namespace. */
  get(mangledName: string, externName: string): HostFn | null;
}

export function defaultHostIO(): HostIO {
  let stdinBuffer: string[] | null = null;

  function ensureStdin(): string[] {
    if (stdinBuffer !== null) return stdinBuffer;
    // Bun has no sync stdin API; slurp once at first read. Interactive use
    // shows a blank prompt — acceptable for MVP.
    let raw = "";
    try { raw = fsReadFile(0, "utf8"); } catch { raw = ""; }
    stdinBuffer = raw.length === 0 ? [] : raw.split("\n");
    if (stdinBuffer.length > 0 && stdinBuffer[stdinBuffer.length - 1] === "") {
      stdinBuffer.pop();
    }
    return stdinBuffer;
  }

  return {
    write(s)            { process.stdout.write(s); },
    writeError(s)       { process.stderr.write(s); },
    readLine()          { return ensureStdin().shift() ?? null; },
    readFile(path)      { return fsReadFile(path, "utf8"); },
    writeFile(p, c)     { fsWriteFile(p, c, "utf8"); },
    exists(p) {
      try { accessSync(p); return true; } catch { return false; }
    },
  };
}

export function stdIoBindings(io: HostIO): Record<string, HostFn> {
  return {
    std_io$print:      (args) => { io.write(stringArg(args, 0));        return VOID; },
    std_io$println:    (args) => { io.write(stringArg(args, 0) + "\n"); return VOID; },
    std_io$eprint:     (args) => { io.writeError(stringArg(args, 0));        return VOID; },
    std_io$eprintln:   (args) => { io.writeError(stringArg(args, 0) + "\n"); return VOID; },
    std_io$read_line:  ()     => {
      const line = io.readLine();
      return line === null ? err("EOF") : str(line);
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
  };
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
    std_string$len:         (args) => num("i32", UTF8_ENC.encode(stringArg(args, 0)).length),
    std_string$slice:       (args) => {
      const s = stringArg(args, 0);
      const bytes = UTF8_ENC.encode(s);
      const start = Math.max(0, numArg(args, 1));
      const end   = Math.min(bytes.length, numArg(args, 2));
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
      const i = numArg(args, 1);
      if (i < 0 || i >= bytes.length) return ch(0);
      return ch(UTF8_DEC.decode(bytes.subarray(i, i + 4)).codePointAt(0) ?? 0);
    },
    // `string implements Index(i32, char)` is `@intrinsic`-impl in std/core,
    // so the host provides the body under the impl-method mangled name.
    "std_core$string$Index$at": (args) => {
      const bytes = UTF8_ENC.encode(stringArg(args, 0));
      const i = numArg(args, 1);
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
    std_string_builder$concat_all: (args) => {
      const arr = args[0];
      if (arr === undefined || arr.tag !== "array") {
        throw new Error(`vm: expected array at host arg 0, got ${arr?.tag ?? "<missing>"}`);
      }
      let result = "";
      for (const el of arr.elements) {
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

function messageOf(e: unknown): string {
  return e instanceof Error ? e.message : String(e);
}
