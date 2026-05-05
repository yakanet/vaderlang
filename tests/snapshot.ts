import { existsSync, mkdirSync, readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { join } from "node:path";

import { tokenize } from "../src/lexer/lexer.ts";
import { parseSource } from "../src/parser/pipeline.ts";
import { DiagnosticCollector } from "../src/diagnostics/collector.ts";
import { resolveProject } from "../src/resolver/index.ts";
import { isStdlibModule } from "../src/resolver/module.ts";
import { checkProject, displayType } from "../src/typecheck/index.ts";
import { evaluateProject, displayValue } from "../src/comptime/index.ts";
import { lowerProject } from "../src/lower/index.ts";
import type {
  LoweredBlock, LoweredDecl, LoweredExpr, LoweredStmt,
} from "../src/lower/index.ts";
import { eliminateDeadCode } from "../src/dce/index.ts";
import { emitBytecode } from "../src/bytecode/index.ts";
import { writeVir, parseVir } from "../src/bytecode/text.ts";
import type { Token } from "../src/lexer/token.ts";
import type { Diagnostic } from "../src/diagnostics/diagnostic.ts";

export interface Scenario {
  readonly dir: string;
  readonly name: string;
  readonly inputPath: string;
  readonly inputSource: string;
}

const UPDATE = process.env["UPDATE_SNAPSHOTS"] === "1";

export function listScenarios(rootDir: string): Scenario[] {
  if (!existsSync(rootDir)) return [];
  const out: Scenario[] = [];
  for (const name of readdirSync(rootDir)) {
    const dir = join(rootDir, name);
    if (!statSync(dir).isDirectory()) continue;
    const inputPath = join(dir, "input.vader");
    if (!existsSync(inputPath)) continue;
    out.push({ dir, name, inputPath, inputSource: readFileSync(inputPath, "utf8") });
  }
  out.sort((a, b) => (a.name < b.name ? -1 : 1));
  return out;
}

export interface SnapshotResult {
  readonly ok: boolean;
  readonly expected: string | null;
  readonly snapPath: string;
}

/**
 * Compare an actual dump against a `.snap` file in the scenario dir.
 * Writes the snap if it doesn't exist or if `UPDATE_SNAPSHOTS=1`.
 */
export function snapshotEquals(scenarioDir: string, snapName: string, actual: string): SnapshotResult {
  if (!existsSync(scenarioDir)) mkdirSync(scenarioDir, { recursive: true });
  const snapPath = join(scenarioDir, snapName);

  if (!existsSync(snapPath)) {
    if (UPDATE) {
      writeFileSync(snapPath, actual);
      return { ok: true, expected: actual, snapPath };
    }
    return { ok: false, expected: null, snapPath };
  }

  const expected = readFileSync(snapPath, "utf8");
  if (expected === actual) return { ok: true, expected, snapPath };

  if (UPDATE) {
    writeFileSync(snapPath, actual);
    return { ok: true, expected: actual, snapPath };
  }

  return { ok: false, expected, snapPath };
}

// --------------------------------------------------------------------- dumps

/** Lexer dump: line-per-token, plus a diagnostics section if any. */
export function dumpLexer(source: string, file: string): string {
  const diags = new DiagnosticCollector();
  const { tokens } = tokenize(source, file, diags);
  return formatTokens(tokens) + formatDiagnostics(diags.sorted());
}

/** Parser dump: structured AST (JSON, spans elided), plus a diagnostics section if any. */
export function dumpParser(source: string, file: string): string {
  const { program, diagnostics } = parseSource(source, file);
  return formatProgram(program) + formatDiagnostics(diagnostics.sorted());
}

/** Comptime dump: @comptime / @file values + generic instances + diagnostics. */
export function dumpComptime(_source: string, entryPath: string): string {
  const diags = new DiagnosticCollector();
  const project = resolveProject({ entryPath, diags });
  const typed = checkProject(project, diags);
  const evaled = evaluateProject(typed, { diags, sandbox: { allowEnv: false } });

  const lines: string[] = ["# Comptime"];
  for (const id of [...evaled.modules.keys()].sort()) {
    const m = evaled.modules.get(id)!;
    if (isStdlibModule(m.typed.resolved.module.displayPath)) continue;
    lines.push(`\n## ${m.typed.resolved.module.displayPath}`);
    const entries: string[] = [];
    for (const [decl, value] of m.comptimeDecls) {
      entries.push(`  @comptime  ${decl.name.padEnd(20)} = ${displayValue(value)}`);
    }
    for (const [decl, value] of m.fileDecls) {
      entries.push(`  @file      ${decl.name.padEnd(20)} = ${displayValue(value)}`);
    }
    entries.sort();
    lines.push(...entries);
  }

  if (evaled.instances.length > 0) {
    lines.push("\n## generic instances");
    for (const inst of evaled.instances) {
      lines.push(`  ${inst.symbol.name}(${inst.args.map(displayType).join(", ")})`);
    }
  }

  return lines.join("\n") + "\n" + formatDiagnostics(diags.sorted());
}

/** Bytecode dump: the .vir text emitter's output. The driver also asserts the
 *  parse → re-serialize round-trip is a fixpoint and embeds a marker line if
 *  it isn't, so a regression surfaces in the snapshot diff. */
export function dumpBytecode(_source: string, entryPath: string): string {
  const diags = new DiagnosticCollector();
  const project = resolveProject({ entryPath, diags });
  const typed = checkProject(project, diags);
  const evaled = evaluateProject(typed, { diags, sandbox: { allowEnv: false } });
  const lowered = lowerProject(evaled, diags);
  const dced = eliminateDeadCode(lowered);
  const moduleName = (entryPath.split("/").pop() ?? entryPath).replace(/\.vader$/, "");
  const bc = emitBytecode(dced, moduleName);

  const text1 = writeVir(bc);
  let roundTripBanner = "";
  try {
    const text2 = writeVir(parseVir(text1));
    if (text2 !== text1) roundTripBanner = "\n; round-trip MISMATCH\n";
  } catch (e) {
    roundTripBanner = `\n; round-trip FAILED: ${(e as Error).message}\n`;
  }

  // Strip absolute paths from debug annotations so snapshots are portable.
  const portable = text1.replace(/; [^:\n]*\/(?=[^/]+\.vader:)/g, "; ");
  return portable + roundTripBanner + formatDiagnostics(diags.sorted());
}

/** Lowerer dump: per-module lowered decls in a compact tree form + diagnostics. */
export function dumpLower(_source: string, entryPath: string): string {
  const diags = new DiagnosticCollector();
  const project = resolveProject({ entryPath, diags });
  const typed = checkProject(project, diags);
  const evaled = evaluateProject(typed, { diags, sandbox: { allowEnv: false } });
  const lowered = lowerProject(evaled, diags);

  const lines: string[] = ["# Lower"];
  for (const id of [...lowered.modules.keys()].sort()) {
    const m = lowered.modules.get(id)!;
    if (isStdlibModule(m.displayPath)) continue;
    lines.push(`\n## ${m.displayPath}`);
    for (const d of m.decls) emitDecl(lines, d, "  ");
  }
  return lines.join("\n") + "\n" + formatDiagnostics(diags.sorted());
}

// Expression renderer. Returns a list of lines (the first line is the "head",
// subsequent lines are indented children). Single-line forms (literals, idents,
// flat ops) yield exactly one line; compound forms (blocks, ifs, intrinsics
// with non-trivial args) expand vertically so the structure stays readable.
function emitDecl(lines: string[], d: LoweredDecl, indent: string): void {
  switch (d.kind) {
    case "LoweredFnDecl": {
      const params = d.params.map((p) => `${p.name}: ${displayType(p.type)}`).join(", ");
      lines.push(`${indent}fn ${d.mangled}(${params}) -> ${displayType(d.returnType)}`);
      if (d.body !== null) emitBlock(lines, d.body, indent + "  ");
      else lines.push(`${indent}  <extern / signature only>`);
      return;
    }
    case "LoweredStructDecl": {
      const fields = d.fields.map((f) => `${f.name}: ${displayType(f.type)}`).join(", ");
      lines.push(`${indent}struct ${d.mangled} { ${fields} }`);
      return;
    }
    case "LoweredConstDecl": {
      lines.push(`${indent}const ${d.mangled}: ${displayType(d.type)} =`);
      emitExpr(lines, d.value, indent + "  ");
      return;
    }
  }
}

function emitBlock(lines: string[], b: LoweredBlock, indent: string): void {
  for (const s of b.stmts) emitStmt(lines, s, indent);
  if (b.trailing !== null) {
    lines.push(`${indent}~>`);
    emitExpr(lines, b.trailing, indent + "  ");
  }
}

function emitStmt(lines: string[], s: LoweredStmt, indent: string): void {
  switch (s.kind) {
    case "LoweredLet": {
      const single = exprInline(s.value);
      if (single !== null) lines.push(`${indent}let ${s.name}#${s.symbol.id}: ${displayType(s.type)} = ${single}`);
      else {
        lines.push(`${indent}let ${s.name}#${s.symbol.id}: ${displayType(s.type)} =`);
        emitExpr(lines, s.value, indent + "  ");
      }
      return;
    }
    case "LoweredAssign":
      lines.push(`${indent}assign`);
      lines.push(`${indent}  target:`);
      emitExpr(lines, s.target, indent + "    ");
      lines.push(`${indent}  value:`);
      emitExpr(lines, s.value, indent + "    ");
      return;
    case "LoweredExprStmt":
      emitExpr(lines, s.expr, indent);
      return;
    case "LoweredReturn":
      if (s.value === null) { lines.push(`${indent}return`); return; }
      const single = exprInline(s.value);
      if (single !== null) lines.push(`${indent}return ${single}`);
      else { lines.push(`${indent}return`); emitExpr(lines, s.value, indent + "  "); }
      return;
    case "LoweredLoop":
      lines.push(`${indent}loop${s.cond === null ? "" : ` while (${exprInline(s.cond) ?? "<…>"})`}${s.label === null ? "" : ` :${s.label}`}`);
      emitBlock(lines, s.body, indent + "  ");
      return;
    case "LoweredBreak":
      lines.push(`${indent}break${s.label === null ? "" : ` :${s.label}`}`);
      return;
    case "LoweredContinue":
      lines.push(`${indent}continue${s.label === null ? "" : ` :${s.label}`}`);
      return;
  }
}

function emitExpr(lines: string[], e: LoweredExpr, indent: string): void {
  const inline = exprInline(e);
  if (inline !== null) { lines.push(`${indent}${inline}`); return; }
  switch (e.kind) {
    case "LoweredCall":
      lines.push(`${indent}call :${displayType(e.type)}`);
      lines.push(`${indent}  callee:`);
      emitExpr(lines, e.callee, indent + "    ");
      for (let i = 0; i < e.args.length; i++) {
        lines.push(`${indent}  arg${i}:`);
        emitExpr(lines, e.args[i]!, indent + "    ");
      }
      return;
    case "LoweredFieldAccess":
      lines.push(`${indent}.${e.field} :${displayType(e.type)}`);
      emitExpr(lines, e.target, indent + "  ");
      return;
    case "LoweredIndex":
      lines.push(`${indent}index :${displayType(e.type)}`);
      lines.push(`${indent}  on:`);
      emitExpr(lines, e.target, indent + "    ");
      lines.push(`${indent}  ix:`);
      emitExpr(lines, e.index, indent + "    ");
      return;
    case "LoweredUnary":
      lines.push(`${indent}${e.op} :${displayType(e.type)}`);
      emitExpr(lines, e.operand, indent + "  ");
      return;
    case "LoweredBinary":
      lines.push(`${indent}${e.op} :${displayType(e.type)}`);
      lines.push(`${indent}  l:`);
      emitExpr(lines, e.left, indent + "    ");
      lines.push(`${indent}  r:`);
      emitExpr(lines, e.right, indent + "    ");
      return;
    case "LoweredIf":
      lines.push(`${indent}if :${displayType(e.type)}`);
      lines.push(`${indent}  cond:`);
      emitExpr(lines, e.cond, indent + "    ");
      lines.push(`${indent}  then:`);
      emitBlock(lines, e.then, indent + "    ");
      if (e.else !== null) {
        lines.push(`${indent}  else:`);
        emitBlock(lines, e.else, indent + "    ");
      }
      return;
    case "LoweredBlock":
      lines.push(`${indent}block :${displayType(e.type)}`);
      emitBlock(lines, e, indent + "  ");
      return;
    case "LoweredStructLit":
      lines.push(`${indent}${displayType(e.type)} {`);
      for (const f of e.fields) {
        const inlineField = exprInline(f.value);
        if (inlineField !== null) lines.push(`${indent}  ${f.name}: ${inlineField}`);
        else { lines.push(`${indent}  ${f.name}:`); emitExpr(lines, f.value, indent + "    "); }
      }
      lines.push(`${indent}}`);
      return;
    case "LoweredArrayLit":
      lines.push(`${indent}array :${displayType(e.type)}`);
      for (const elt of e.elements) emitExpr(lines, elt, indent + "  ");
      return;
    case "LoweredCast":
      lines.push(`${indent}cast → ${displayType(e.type)}`);
      emitExpr(lines, e.value, indent + "  ");
      return;
    case "LoweredTypeCheck":
      lines.push(`${indent}is ${displayType(e.checkType)} :bool`);
      emitExpr(lines, e.value, indent + "  ");
      return;
    case "LoweredIntrinsicCall": {
      const tail = e.displayFor !== undefined ? ` <for ${displayType(e.displayFor)}>` : "";
      lines.push(`${indent}@${e.name}${tail} :${displayType(e.type)}`);
      for (const a of e.args) emitExpr(lines, a, indent + "  ");
      return;
    }
    default:
      lines.push(`${indent}${e.kind}`);
      return;
  }
}

/** Render an expr as a single line if compact, otherwise null. */
function exprInline(e: LoweredExpr): string | null {
  switch (e.kind) {
    case "LoweredIntLit":    return `int(${e.value.toString()}) :${displayType(e.type)}`;
    case "LoweredFloatLit":  return `float(${e.value}) :${displayType(e.type)}`;
    case "LoweredBoolLit":   return `${e.value}`;
    case "LoweredNullLit":   return `null`;
    case "LoweredCharLit":   return `char(0x${e.value.toString(16)})`;
    case "LoweredStringLit": return `${JSON.stringify(e.value)} :string`;
    case "LoweredIdent":     return `${e.symbol.name}#${e.symbol.id} :${displayType(e.type)}`;
    case "LoweredUnreachable": return `unreachable("${e.reason}") :${displayType(e.type)}`;
    default:                 return null;
  }
}

/** Type-checker dump: per-module decl + expression types for the entry module + diagnostics. */
export function dumpTypecheck(_source: string, entryPath: string): string {
  const diags = new DiagnosticCollector();
  const project = resolveProject({ entryPath, diags });
  const typed = checkProject(project, diags);

  const lines: string[] = ["# Typecheck"];
  for (const id of [...typed.modules.keys()].sort()) {
    const p = typed.modules.get(id)!;
    if (isStdlibModule(p.resolved.module.displayPath)) continue;
    lines.push(`\n## ${p.resolved.module.displayPath}`);
    const decls = p.resolved.source.decls
      .filter((d) => "name" in d)
      .sort((a, b) => ("name" in a && "name" in b ? a.name.localeCompare(b.name) : 0));
    for (const d of decls) {
      const ty = p.declTypes.get(d);
      const name = "name" in d ? d.name : "?";
      lines.push(`  ${d.kind.padEnd(14)} ${name.padEnd(20)} :: ${ty !== undefined ? displayType(ty) : "?"}`);
    }
    const exprLines: string[] = [];
    for (const [expr, ty] of p.exprTypes) {
      if (expr.kind === "IntLitExpr" || expr.kind === "FloatLitExpr"
          || expr.kind === "BoolLitExpr" || expr.kind === "NullLitExpr"
          || expr.kind === "CharLitExpr" || expr.kind === "BlockExpr") continue;
      const loc = `${expr.span.start.line}:${expr.span.start.column}`;
      exprLines.push(`  expr ${loc.padEnd(8)} ${expr.kind.padEnd(14)} :: ${displayType(ty)}`);
    }
    exprLines.sort();
    lines.push(...exprLines);
  }
  return lines.join("\n") + "\n" + formatDiagnostics(diags.sorted());
}

/** Resolver dump: per-module symbol table + resolution counts + diagnostics. */
export function dumpResolver(_source: string, entryPath: string): string {
  const diags = new DiagnosticCollector();
  const project = resolveProject({ entryPath, diags });

  const lines: string[] = ["# Modules"];
  const sortedIds = [...project.modules.keys()].sort();
  for (const id of sortedIds) {
    const p = project.modules.get(id)!;
    lines.push(`\n## ${p.module.displayPath}`);
    const sortedSyms = [...p.module.symbols.values()].sort((a, b) => a.name.localeCompare(b.name));
    for (const s of sortedSyms) {
      const ix = (s.source.kind === "import" && s.source.importedName !== null) ? `→ ${s.source.importedName}` : "";
      lines.push(`  ${s.kind.padEnd(16)} ${s.visibility.padEnd(8)} ${s.name} ${ix}`);
    }
    const importLines = [...p.module.imports]
      .map((imp) => `  import ${imp.path} → ${imp.resolvedTo === null ? "<unresolved>" : "ok"}`);
    if (importLines.length > 0) {
      lines.push(...importLines);
    }
    lines.push(`  refs: idents=${p.idents.size} types=${p.types.size} params=${p.params.size} locals=${p.locals.size} typeParams=${p.typeParams.size} fields=${p.fields.size}`);
  }
  return lines.join("\n") + "\n" + formatDiagnostics(diags.sorted());
}

const SPAN_KEYS = new Set<string>([
  "span", "fieldSpan", "nameSpan", "bindingSpan", "traitNameSpan", "file",
]);

function formatProgram(program: unknown): string {
  const json = JSON.stringify(program, (key, value) => {
    if (SPAN_KEYS.has(key)) return undefined;
    if (typeof value === "bigint") return `${value.toString()}n`;
    return value;
  }, 2);
  return "# AST\n" + json + "\n";
}

function formatTokens(tokens: readonly Token[]): string {
  const lines: string[] = ["# Tokens"];
  for (const t of tokens) {
    const span = `${t.span.start.line}:${t.span.start.column}-${t.span.end.line}:${t.span.end.column}`;
    lines.push(`[${span.padEnd(11)}] ${t.kind.padEnd(14)} ${JSON.stringify(t.text)}${tokenDetail(t)}`);
  }
  return lines.join("\n") + "\n";
}

function tokenDetail(t: Token): string {
  if (t.intValue !== undefined) {
    const suffix = t.numericSuffix !== undefined ? ` :${t.numericSuffix}` : "";
    return ` =${t.intValue.toString()}n${suffix}`;
  }
  if (t.floatValue !== undefined) {
    const suffix = t.numericSuffix !== undefined ? ` :${t.numericSuffix}` : "";
    return ` =${t.floatValue}${suffix}`;
  }
  if (t.charValue !== undefined) {
    return ` =U+${t.charValue.toString(16).toUpperCase().padStart(4, "0")}`;
  }
  if (t.stringValue !== undefined) {
    return ` =${JSON.stringify(t.stringValue)}`;
  }
  return "";
}

function formatDiagnostics(diagnostics: readonly Diagnostic[]): string {
  if (diagnostics.length === 0) return "";
  const lines: string[] = ["", "# Diagnostics"];
  for (const d of diagnostics) {
    const start = d.primary.start;
    lines.push(`[${start.line}:${start.column}] ${d.severity}[${d.code}] ${d.message}`);
  }
  return lines.join("\n") + "\n";
}
