// Host-side bindings for `@extern` imports. The VM resolves each `BcImport`
// by its `mangledName` against the table built here; mismatches trap.
//
// Sync I/O is required because the VM's dispatch loop is sync. Bun has no
// synchronous file API, so the on-disk operations go through `node:fs`.

import { accessSync, readFileSync as fsReadFile, writeFileSync as fsWriteFile } from "node:fs";

import type { Value } from "./value.ts";
import { NULL, VOID, bool, err, str } from "./value.ts";

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

export function makeBindings(io: HostIO): HostBindings {
  const stdio = stdIoBindings(io);
  return {
    get(mangledName, externName) {
      return stdio[mangledName] ?? stdio[externName] ?? null;
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

function messageOf(e: unknown): string {
  return e instanceof Error ? e.message : String(e);
}
