// Pretty-printer for the Mid-IR CFG. Produces a stable, human-readable text
// rendering used by `vader dump --stage=cfg <file>` and by snapshot tests.
//
// Format goal : every fn shown as a header (params + return type), the local
// table, then each basic block with its instructions and terminator. Locals
// are referenced as `%<index>` ; blocks as `bb<index>`. Spans are omitted to
// keep the output focused on the structure.

import { displayType } from "../typecheck/index.ts";

import type {
  BasicBlock, CFGFunction, CFGProject, ConstValue, Instruction, LocalId,
  Terminator,
} from "./cfg.ts";

export interface DumpCFGOptions {
  /** When provided, modules whose `displayPath` returns false are skipped.
   *  Snapshot tests use this to elide stdlib so the captured output stays
   *  focused on the user snippet. */
  readonly includeModule?: (displayPath: string) => boolean;
  /** When false, the project-level string pool is not appended. Snapshots
   *  for user code typically don't care about which stdlib strings got
   *  interned — set to false to keep the snapshot diff signal-rich. */
  readonly includeStrings?: boolean;
}

export function dumpCFGProject(p: CFGProject, opts: DumpCFGOptions = {}): string {
  const includeModule = opts.includeModule ?? (() => true);
  const lines: string[] = [];
  lines.push("# CFG");
  for (const m of p.modules.values()) {
    if (!includeModule(m.displayPath)) continue;
    if (m.functions.length === 0 && m.otherDecls.length === 0) continue;
    lines.push("");
    lines.push(`## ${m.displayPath}`);
    for (const fn of m.functions) {
      lines.push("");
      dumpFunction(fn, lines);
    }
  }
  if (opts.includeStrings !== false && p.strings.length > 0) {
    lines.push("");
    lines.push("## strings");
    for (let i = 0; i < p.strings.length; i++) {
      lines.push(`  ${i}: ${JSON.stringify(p.strings[i])}`);
    }
  }
  return lines.join("\n") + "\n";
}

function dumpFunction(fn: CFGFunction, out: string[]): void {
  const params = fn.params
    .map((p) => `%${p.local}: ${displayType(p.type)}`)
    .join(", ");
  out.push(`fn ${fn.mangled}(${params}) -> ${displayType(fn.returnType)}`);
  out.push(`  locals:`);
  for (let i = 0; i < fn.locals.length; i++) {
    const l = fn.locals[i]!;
    const tag = l.symbol !== null ? ` (${l.symbol.kind} ${l.symbol.name})` : "";
    out.push(`    %${i} ${l.name}: ${displayType(l.type)}${tag}`);
  }
  for (const b of fn.blocks) {
    dumpBlock(b, out);
  }
}

function dumpBlock(b: BasicBlock, out: string[]): void {
  out.push(`  bb${b.id}:`);
  for (const ins of b.instructions) {
    out.push(`    ${dumpInstr(ins)}`);
  }
  out.push(`    ${dumpTerminator(b.terminator)}`);
}

function dumpInstr(ins: Instruction): string {
  switch (ins.kind) {
    case "Const":     return `%${ins.dst} = const ${dumpConst(ins.value)} :${displayType(ins.type)}`;
    case "BinOp":     return `%${ins.dst} = binop ${ins.op} %${ins.lhs} %${ins.rhs} :${displayType(ins.type)}`;
    case "UnOp":      return `%${ins.dst} = unop ${ins.op} %${ins.operand} :${displayType(ins.type)}`;
    case "Phi":       return `%${ins.dst} = phi ${ins.sources.map((s) => `bb${s.block}:%${s.value}`).join(", ")} :${displayType(ins.type)}`;
    case "Call":      return `${dst(ins.dst)}call ${ins.callee.name}(${args(ins.args)}) :${displayType(ins.type)}`;
    case "CallIndirect": return `${dst(ins.dst)}call_indirect %${ins.callee}(${args(ins.args)}) :${displayType(ins.type)}`;
    case "FnRef":     return `%${ins.dst} = fn_ref ${ins.fnSymbol.name} :${displayType(ins.type)}`;
    case "VirtualCall": return `${dst(ins.dst)}vcall ${ins.traitName}.${ins.method}(recv=%${ins.receiver}${ins.args.length > 0 ? `, ${args(ins.args)}` : ""}) :${displayType(ins.type)}`;
    case "FieldGet":  return `%${ins.dst} = field_get %${ins.target}.${ins.field} :${displayType(ins.type)}`;
    case "FieldSet":  return `field_set %${ins.target}.${ins.field} = %${ins.value}`;
    case "ArrayGet":  return `%${ins.dst} = array_get %${ins.target}[%${ins.index}] :${displayType(ins.type)}`;
    case "ArraySet":  return `array_set %${ins.target}[%${ins.index}] = %${ins.value}`;
    case "ArrayLen":  return `%${ins.dst} = array_len %${ins.target}`;
    case "ArrayPush": return `array_push %${ins.target}, %${ins.value}`;
    case "StructNew": return `%${ins.dst} = struct_new ${displayType(ins.type)}(${args(ins.fields)})`;
    case "ArrayNew":  return `%${ins.dst} = array_new ${displayType(ins.type)}[${ins.length}](${args(ins.elements)})`;
    case "TypeCheck": return `%${ins.dst} = type_check %${ins.value} is ${displayType(ins.checkType)}`;
    case "Cast":      return `%${ins.dst} = cast %${ins.value} :${displayType(ins.type)}`;
    case "CellNew":   return `%${ins.dst} = cell_new %${ins.value} :${displayType(ins.valueType)}`;
    case "CellGet":   return `%${ins.dst} = cell_get %${ins.cell} :${displayType(ins.valueType)}`;
    case "CellSet":   return `cell_set %${ins.cell} = %${ins.value} :${displayType(ins.valueType)}`;
    case "MakeClosure": return `%${ins.dst} = make_closure ${ins.fnSymbol.name} env=%${ins.env} :${displayType(ins.type)}`;
    case "Intrinsic": return `${dst(ins.dst)}intrinsic ${ins.name}(${args(ins.args)})`;
    case "Move":      return `%${ins.dst} = move %${ins.src}`;
  }
}

function dumpTerminator(t: Terminator): string {
  switch (t.kind) {
    case "Branch":      return `branch -> bb${t.target}`;
    case "CondBranch":  return `cond_branch %${t.cond} ? bb${t.then} : bb${t.else}`;
    case "Return":      return t.value === null ? `return` : `return %${t.value}`;
    case "Unreachable": return `unreachable ; ${t.reason}`;
  }
}

function dumpConst(v: ConstValue): string {
  switch (v.kind) {
    case "int":    return `int(${v.value.toString()})`;
    case "float":  return `float(${v.value})`;
    case "bool":   return `bool(${v.value})`;
    case "char":   return `char(${v.value})`;
    case "string": return `string(#${v.index})`;
    case "null":   return `null`;
  }
}

function dst(d: LocalId | null): string {
  return d === null ? "" : `%${d} = `;
}

function args(a: readonly LocalId[]): string {
  return a.map((x) => `%${x}`).join(", ");
}
