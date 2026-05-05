// VM barrel — public surface for §1.8.

export { runProgram, runFn, VmError } from "./exec.ts";
export type { RunOptions, RunResult } from "./exec.ts";

export { defaultHostIO, makeBindings } from "./host.ts";
export type { HostIO, HostBindings, HostFn } from "./host.ts";

export type { Value } from "./value.ts";
