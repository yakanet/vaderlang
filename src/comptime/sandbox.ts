// What's allowed inside @comptime, per SPEC §2 sandbox table.
//
//   ✅ compute (pure functions)
//   ✅ allocate / manipulate structures
//   ✅ read project files (@file)
//   ⚠️ ENV / args — opt-in via --allow-env
//   ❌ network / exec / stdout

import { existsSync, readFileSync } from "node:fs";
import { dirname, isAbsolute, resolve } from "node:path";

import type { ComptimeValue } from "./value.ts";
import { stringVal } from "./value.ts";

export const COMPTIME_BUILTIN = {
  file: "@file",
  env:  "@env",
} as const;

export type ComptimeBuiltinName = typeof COMPTIME_BUILTIN[keyof typeof COMPTIME_BUILTIN];

export interface SandboxOptions {
  readonly allowEnv: boolean;
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
    case COMPTIME_BUILTIN.file: return file(call);
    case COMPTIME_BUILTIN.env:  return env(call, opts);
    default: return null;
  }
}

function file(call: BuiltinCall): BuiltinResult {
  const arg = call.args[0];
  if (call.args.length !== 1 || arg === undefined || arg.kind !== "string") {
    return { ok: false, code: "C4011", message: "@file expects exactly one string argument" };
  }
  const target = isAbsolute(arg.value) ? arg.value : resolve(dirname(call.callerFile), arg.value);
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
