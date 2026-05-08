// What's allowed inside @comptime, per SPEC §2 sandbox table.
//
//   ✅ compute (pure functions)
//   ✅ allocate / manipulate structures
//   ✅ read project files (@file) — confined to `projectRoot`
//   ⚠️ ENV / args — opt-in via --allow-env
//   ❌ network / exec / stdout

import { existsSync, readFileSync } from "node:fs";
import { dirname, isAbsolute, resolve, sep } from "node:path";

import type { ComptimeValue } from "./value.ts";
import { stringVal } from "./value.ts";

export const COMPTIME_BUILTIN = {
  file: "@file",
  env:  "@env",
} as const;

export type ComptimeBuiltinName = typeof COMPTIME_BUILTIN[keyof typeof COMPTIME_BUILTIN];

/** Mangled names of the comptime VM imports the host bindings resolve. The
 *  lowerer emits calls under these names; `run.ts` maps them to `callBuiltin`
 *  routes for `@file` / `@env`. */
export const COMPTIME_IMPORT = {
  file: "comptime$file",
  env:  "comptime$env",
} as const;

export interface SandboxOptions {
  readonly allowEnv: boolean;
  /** Absolute path. `@file` is rejected for any target outside this root.
   *  Required — callers without a meaningful project root must opt out
   *  explicitly by passing the root they intend to expose (e.g.
   *  `process.cwd()`). */
  readonly projectRoot: string;
}

export interface BuiltinCall {
  readonly fnName: string;
  readonly args: readonly ComptimeValue[];
  readonly callerFile: string;
}

export type BuiltinResult =
  | { readonly ok: true; readonly value: ComptimeValue }
  | { readonly ok: false; readonly code: "C4006" | "C4008" | "C4011"; readonly message: string };

/**
 * Look up a comptime-callable builtin by name. Returns null when the name
 * isn't in the comptime whitelist (`println`, `read_line`, etc.). The caller
 * then either falls back to walking a user-defined fn body or emits C4003.
 */
export function callBuiltin(call: BuiltinCall, opts: SandboxOptions): BuiltinResult | null {
  switch (call.fnName) {
    case COMPTIME_BUILTIN.file: return file(call, opts);
    case COMPTIME_BUILTIN.env:  return env(call, opts);
    default: return null;
  }
}

function file(call: BuiltinCall, opts: SandboxOptions): BuiltinResult {
  const arg = call.args[0];
  if (call.args.length !== 1 || arg === undefined || arg.kind !== "string") {
    return { ok: false, code: "C4011", message: "@file expects exactly one string argument" };
  }
  const target = isAbsolute(arg.value) ? arg.value : resolve(dirname(call.callerFile), arg.value);
  // Containment: a malicious or careless `@file "../../etc/passwd"` (or an
  // absolute path) reads outside the project. Targets must live under
  // `projectRoot` (the dir containing `vader.json`, or whatever the caller
  // declared as the trust boundary).
  const root = opts.projectRoot.endsWith(sep) ? opts.projectRoot : opts.projectRoot + sep;
  const isInside = target === opts.projectRoot || target.startsWith(root);
  if (!isInside) {
    return {
      ok: false, code: "C4011",
      message: `@file path escapes project root: \`${arg.value}\` (resolved to \`${target}\`, root \`${opts.projectRoot}\`)`,
    };
  }
  if (!existsSync(target)) {
    return { ok: false, code: "C4006", message: `\`${arg.value}\` (resolved to \`${target}\`)` };
  }
  return { ok: true, value: stringVal(readFileSync(target, "utf8")) };
}

function env(call: BuiltinCall, opts: SandboxOptions): BuiltinResult {
  if (!opts.allowEnv) {
    return { ok: false, code: "C4008", message: "pass `--allow-env` to enable @env in comptime" };
  }
  const arg = call.args[0];
  if (call.args.length !== 1 || arg === undefined || arg.kind !== "string") {
    return { ok: false, code: "C4011", message: "@env expects exactly one string argument" };
  }
  return { ok: true, value: stringVal(process.env[arg.value] ?? "") };
}
