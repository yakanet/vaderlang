// Glue between the typed-AST → bytecode compiler and the runtime VM.
// Wraps a single `@comptime` decl evaluation: compile, run, convert the
// resulting Value back to a ComptimeValue, and translate VM traps into
// structured comptime diagnostics (C4002, C4005, C4010, …).

import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import type * as A from "../parser/ast.ts";
import type { TypedProgram, TypedProject } from "../typecheck/index.ts";
import type { Type } from "../typecheck/types.ts";

import { runFn, VmError, type HostBindings, type HostFn, type Value } from "../vm/index.ts";

import { err } from "./diag.ts";
import { compileComptime, COMPTIME_IMPORT } from "./compile.ts";
import { callBuiltin, type SandboxOptions } from "./sandbox.ts";
import {
  FALSE, NULL, TRUE, VOID, intVal, floatVal, stringVal, type ComptimeValue,
} from "./value.ts";

export interface RunComptimeInput {
  readonly decl: A.ConstDecl;
  readonly project: TypedProject;
  readonly callerProgram: TypedProgram;
  readonly evaluated: ReadonlyMap<A.ConstDecl, ComptimeValue>;
  readonly callerFile: string;
  readonly diags: DiagnosticCollector;
  readonly sandbox: SandboxOptions;
}

export function runComptimeDecl(input: RunComptimeInput): ComptimeValue | null {
  const compiled = compileComptime({
    decl: input.decl, project: input.project, callerProgram: input.callerProgram,
    evaluated: input.evaluated, diags: input.diags,
  });
  if (compiled === null) return null;

  let value: Value;
  try {
    value = runFn(compiled.module, compiled.module.functions[compiled.mainFnIndex]!.name,
      [], { host: comptimeHost(input) });
  } catch (e) {
    if (e instanceof VmError) {
      reportVmError(e, compiled.spanByOp, input);
      return null;
    }
    throw e;
  }
  return valueToComptime(value, compiled.resultType, input);
}

// ----------------------------------------------------------- host

function comptimeHost(input: RunComptimeInput): HostBindings {
  const bindings: Record<string, HostFn> = {
    [COMPTIME_IMPORT.file]: (args) => routeBuiltin("@file", args, input),
    [COMPTIME_IMPORT.env]:  (args) => routeBuiltin("@env",  args, input),
  };
  return {
    get(mangledName, externName) {
      return bindings[mangledName] ?? bindings[externName] ?? null;
    },
  };
}

function routeBuiltin(name: "@file" | "@env", args: Value[], input: RunComptimeInput): Value {
  const arg = args[0];
  const argStr = arg !== undefined && arg.tag === "string" ? arg.n : "";
  const result = callBuiltin(
    { fnName: name, args: [stringVal(argStr)], callerFile: input.callerFile },
    input.sandbox,
  );
  if (result === null || !result.ok) {
    if (result !== null) err(input.diags, result.code, input.decl.value.span, result.message);
    throw new VmError(`vm: comptime ${name} failed`);
  }
  return comptimeToValue(result.value);
}

// ----------------------------------------------------------- diagnostics

function reportVmError(
  e: VmError, spanByOp: ReadonlyMap<string, Span>, input: RunComptimeInput,
): void {
  const span = spanFromVmError(e, spanByOp) ?? input.decl.value.span;
  const msg = e.message;
  if (msg.includes("division by zero") || msg.includes("modulo by zero")) {
    err(input.diags, "C4005", span);
  } else if (msg.includes("array index") && msg.includes("out of bounds")) {
    err(input.diags, "C4010", span, msg.replace(/^vm:\s*/, ""));
  } else {
    err(input.diags, "C4002", span, msg.replace(/^vm:\s*/, ""));
  }
}

function spanFromVmError(e: VmError, spanByOp: ReadonlyMap<string, Span>): Span | null {
  // The VmError debug string carries `<fnName>+<ip>`. We don't keep fn names
  // in the spanByOp keys (they're `${fnIndex}:${opIndex}`), so we scan for any
  // entry matching the op index — adequate when the trap is in main, and
  // best-effort otherwise. (A precise mapping arrives once DebugPos carries
  // the fnIndex too.)
  const dbg = e.debug ?? "";
  const m = /\+(\d+)/.exec(dbg);
  if (m === null) return null;
  const opIndex = Number(m[1]);
  for (const [key, span] of spanByOp) {
    const colon = key.indexOf(":");
    if (colon > 0 && Number(key.slice(colon + 1)) === opIndex) return span;
  }
  return null;
}

// ----------------------------------------------------------- conversion

function valueToComptime(v: Value, expected: Type, input: RunComptimeInput): ComptimeValue | null {
  switch (v.tag) {
    case "i8": case "i16": case "i32":
    case "u8": case "u16": case "u32":
      return intVal(BigInt(Math.trunc(v.n)), v.tag);
    case "i64": case "u64": case "usize": return intVal(v.n, v.tag);
    case "f32": case "f64": return floatVal(v.n, v.tag);
    case "bool":   return v.n ? TRUE : FALSE;
    case "char":   return { kind: "char", value: v.n };
    case "string": return stringVal(v.n);
    case "null":   return NULL;
    case "void":   return VOID;
    case "error":
      err(input.diags, "C4002", input.decl.value.span, v.message);
      return null;
    case "struct":
    case "array":
    case "builder":
      err(input.diags, "C4011", input.decl.value.span,
        `comptime ${v.tag} value not yet convertible (return type ${expected.kind})`);
      return null;
  }
}

function comptimeToValue(v: ComptimeValue): Value {
  switch (v.kind) {
    case "int":
      if (v.typeName === "i64" || v.typeName === "u64")
        return { tag: v.typeName, n: v.value };
      return { tag: v.typeName as "i32", n: Number(v.value) };
    case "float":
      return { tag: v.typeName as "f64", n: v.value };
    case "bool":   return v.value ? { tag: "bool", n: true } : { tag: "bool", n: false };
    case "char":   return { tag: "char", n: v.value };
    case "string": return { tag: "string", n: v.value };
    case "null":   return { tag: "null" };
    case "void":   return { tag: "void" };
    case "array":  return { tag: "array", typeIndex: -1, elements: v.elements.map(comptimeToValue) };
    case "struct": return { tag: "struct", typeIndex: -1, fields: [...v.fields.values()].map(comptimeToValue) };
  }
}
