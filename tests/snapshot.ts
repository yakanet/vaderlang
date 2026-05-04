import { existsSync, mkdirSync, readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { join } from "node:path";

import { tokenize } from "../src/lexer/lexer.ts";
import { parseSource } from "../src/parser/pipeline.ts";
import { DiagnosticCollector } from "../src/diagnostics/collector.ts";
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
