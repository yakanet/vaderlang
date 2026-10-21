import { existsSync, mkdirSync, readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { join } from "node:path";

import { runCli } from "./cli-bin.ts";

// The native, self-hosted Vader CLI (`./build/vader dump --stage=…`) is the
// snapshot oracle for every pipeline stage. The legacy TypeScript pipeline that
// once produced these dumps in-process was removed with `src/` (§2.8) — its
// final state is preserved under the `v0.0.0-pre-mvp-final-ts` tag.

export const MAIN_FILE = "_main.vader";
export const CONFIG_FILE = "_config.json";
/** The emitted-C golden. The `.c` extension is what makes an editor open it as C. */
export const C_SNAPSHOT = "emit-c.snapshot.c";

/** A snippet's recorded run, which the VM and the native build are both held to. */
export const VM_SNAPSHOT = "vm.snapshot";

/** What a stage snapshot starts with when the CLI failed to produce that stage. */
export const CLI_FAILED_PREFIX = "# vader CLI failed";

const PHASE_NAMES = [
  "lexer", "parser", "resolver", "typecheck", "comptime", "lower", "cfg", "bytecode", "emit_c",
] as const;
type PhaseName = typeof PHASE_NAMES[number];

/** Where a snippet's run is NOT checked, each case with its reason: everywhere
 *  (`skip`), or on the platforms named (`skip_on`, keyed by `process.platform`). */
export interface RunExclusion {
  readonly skip?: string;
  readonly skip_on?: Readonly<Record<string, string>>;
}

/** A snippet's `_config.json`. Every key is optional ; a snippet without the file
 *  takes every default. */
export interface TestConfig {
  readonly phases?: readonly PhaseName[];
  /** Modules rendered by the module-filtered dumps (typecheck / comptime /
   *  lower), passed through as `--module`. Defaults to the entry module's
   *  subtree when absent — set this only for a snippet whose modules fall
   *  outside the entry module's display-path prefix. */
  readonly modules?: readonly string[];
  /** The native run, compared with `vm.snapshot` (`parity-cemit.test.ts`). On for
   *  every snippet whose `vm.snapshot` records a run. */
  readonly native?: RunExclusion;
  /** The VM run, compared with `vm.snapshot` (`vader_vm.test.ts`). */
  readonly vm?: RunExclusion;
}

/** The snippet at `dir`'s `_config.json`, and what is wrong with it. A config with
 *  problems reads as the defaults, which run every check : only
 *  `snapshot.test.ts`'s "snippet configs are valid" fails on it, so a bad file
 *  cannot empty a listing nor turn a check off in silence. */
function readConfig(dir: string): { config: TestConfig; problems: string[] } {
  const configPath = join(dir, CONFIG_FILE);
  if (!existsSync(configPath)) {
    return { config: {}, problems: fileProblems({}, dir) };
  }
  let raw: unknown;
  try {
    raw = JSON.parse(readFileSync(configPath, "utf8"));
  } catch (e) {
    return { config: {}, problems: [`not JSON (${errMsg(e)})`] };
  }
  const problems = configProblems(raw, dir);
  return { config: problems.length === 0 ? (raw as TestConfig) : {}, problems };
}

// Every key a `_config.json` may hold ; `satisfies` keeps it in step with `TestConfig`.
const CONFIG_KEYS = {
  phases: true, modules: true, native: true, vm: true,
} satisfies Record<keyof TestConfig, true>;

/** What is wrong with the parsed `_config.json` of the snippet at `dir`. */
function configProblems(raw: unknown, dir: string): string[] {
  if (!isRecord(raw)) return ["the config is not an object"];
  const out: string[] = [];
  for (const key of Object.keys(raw)) {
    if (!(key in CONFIG_KEYS)) out.push(`unknown key \`${key}\``);
  }
  const phases = raw["phases"];
  if (phases !== undefined) {
    if (!Array.isArray(phases) || phases.some((p) => !PHASE_NAMES.includes(p as PhaseName))) {
      out.push(`\`phases\` lists the phases among ${PHASE_NAMES.join(", ")}`);
    }
  }
  const modules = raw["modules"];
  if (modules !== undefined && (!Array.isArray(modules) || modules.some((m) => typeof m !== "string"))) {
    out.push("`modules` is a list of module paths");
  }
  for (const side of ["native", "vm"]) {
    if (raw[side] !== undefined) out.push(...exclusionProblems(side, raw[side]));
  }
  out.push(...fileProblems(raw, dir));
  return out;
}

// Where the config `raw` and the snapshot files beside it disagree.
function fileProblems(raw: Record<string, unknown>, dir: string): string[] {
  const out: string[] = [];
  const phases = raw["phases"];
  if (existsSync(join(dir, C_SNAPSHOT)) && Array.isArray(phases) && !phases.includes("emit_c")) {
    out.push(`\`phases\` leaves out \`emit_c\`, so its \`${C_SNAPSHOT}\` pins nothing: delete the file`);
  }
  const runs = existsSync(join(dir, VM_SNAPSHOT));
  for (const side of ["native", "vm"]) {
    if (raw[side] !== undefined && !runs) {
      out.push(`\`${side}\` excludes a run, and no \`${VM_SNAPSHOT}\` records one`);
    }
  }
  return out;
}

// What is wrong with the run exclusion `value` under `side`.
function exclusionProblems(side: string, value: unknown): string[] {
  if (!isRecord(value)) return [`\`${side}\` is an object`];
  const out: string[] = [];
  for (const key of Object.keys(value)) {
    if (key !== "skip" && key !== "skip_on") out.push(`unknown key \`${side}.${key}\``);
  }
  const skip = value["skip"];
  const skipOn = value["skip_on"];
  if (skip === undefined && skipOn === undefined) out.push(`\`${side}\` excludes nothing`);
  if (skip !== undefined && skipOn !== undefined) out.push(`\`${side}.skip\` already excludes every platform`);
  if (skip !== undefined && !isReason(skip)) out.push(`\`${side}.skip\` is its reason, a non-empty string`);
  if (skipOn !== undefined) {
    if (!isRecord(skipOn) || Object.keys(skipOn).length === 0) {
      out.push(`\`${side}.skip_on\` maps a platform to its reason`);
    } else {
      for (const [platform, reason] of Object.entries(skipOn)) {
        if (!KNOWN_PLATFORMS.includes(platform)) out.push(`\`${side}.skip_on\`: unknown platform \`${platform}\``);
        if (!isReason(reason)) out.push(`\`${side}.skip_on.${platform}\` is its reason, a non-empty string`);
      }
    }
  }
  return out;
}

// The `process.platform` values a snippet may be excluded on.
const KNOWN_PLATFORMS = ["darwin", "linux", "win32"];

function isRecord(v: unknown): v is Record<string, unknown> {
  return typeof v === "object" && v !== null && !Array.isArray(v);
}

function isReason(v: unknown): boolean {
  return typeof v === "string" && v.trim().length > 0;
}

/** Why the run `exclusion` describes is not checked on this platform, or null when
 *  it is. */
export function exclusionReason(exclusion: RunExclusion | undefined): string | null {
  if (exclusion === undefined) return null;
  return exclusion.skip ?? exclusion.skip_on?.[process.platform] ?? null;
}

export interface Scenario {
  readonly name: string;
  readonly dir: string;
  readonly mainPath: string;
  readonly source: string;
  /** Adjacent `helper*.c` files that the native runner pre-compiles to `.o`
   *  and passes through to the cc invocation via `--ldflags`. Used by
   *  `@extern` end-to-end snippets that wire a Vader signature to a foreign
   *  symbol. */
  readonly helperCFiles: readonly string[];
  /** Its `_config.json` ; the defaults when it has problems. */
  readonly config: TestConfig;
  /** What is wrong with its `_config.json` (`readConfig`). */
  readonly configProblems: readonly string[];
}

const UPDATE = process.env["UPDATE_SNAPSHOTS"] === "1";

export function errMsg(e: unknown): string {
  return e instanceof Error ? e.message : String(e);
}

export function formatRun(stdout: string, stderr: string, exit: number): string {
  const parts: string[] = [];
  if (stdout.length > 0) parts.push("# stdout\n" + stdout);
  if (stderr.length > 0) parts.push("# stderr\n" + stderr);
  parts.push(`# exit\n${exit}\n`);
  return parts.join("");
}

export function listSnippets(snippetsDir: string): Scenario[] {
  const out: Scenario[] = [];
  let entries: string[];
  try { entries = readdirSync(snippetsDir); } catch { return []; }
  for (const name of entries) {
    const dir = join(snippetsDir, name);
    if (!statSync(dir).isDirectory()) continue;
    const mainPath = join(dir, MAIN_FILE);
    let source: string;
    try { source = readFileSync(mainPath, "utf8"); } catch { continue; }
    // A helper — the C defining an `@extern` test's foreign symbols — is named
    // `helper*.c`. Every other `.c` in a snippet directory is an output: the
    // committed `C_SNAPSHOT` golden, `native.c` from `tests/native.test.ts`, the
    // gitignored `_main*.c` a CLI build leaves behind. Only the name counts: an
    // output taken for a helper turns this snippet's `vader-vm` parity test into
    // a silent skip, while a helper named otherwise fails its link loudly.
    const helperCFiles = readdirSync(dir)
      .filter((f) => f.startsWith("helper") && f.endsWith(".c"))
      .map((f) => join(dir, f))
      .sort();
    const { config, problems } = readConfig(dir);
    out.push({ name, dir, mainPath, source, helperCFiles, config, configProblems: problems });
  }
  out.sort((a, b) => (a.name < b.name ? -1 : 1));
  return out;
}

interface SnapshotResult {
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

// ----------------------------------------------------------- ViaVader dumps

// Each `dump*ViaVader` shells out (via `cli-bin.ts::runCli`) to
// `./build/vader dump --stage=<S> <file>`, the self-hosted compiler being the
// snapshot oracle for every stage.

export async function dumpTypecheckViaVader(_source: string, entryPath: string, modules?: readonly string[]): Promise<string> {
  return runVaderDump("typed-ast", entryPath, modules);
}

export async function dumpComptimeViaVader(_source: string, entryPath: string, modules?: readonly string[]): Promise<string> {
  return runVaderDump("evaluated-ast", entryPath, modules);
}

export async function dumpLexerViaVader(_source: string, entryPath: string, _modules?: readonly string[]): Promise<string> {
  return runVaderDump("lexer", entryPath);
}

export async function dumpParserViaVader(_source: string, entryPath: string, _modules?: readonly string[]): Promise<string> {
  return astDumpAsJson(await runVaderDump("ast", entryPath));
}

// The `ast` dump as one JSON document, `{ "ast": …, "diagnostics": [ "…" ] }`, so the
// snapshot reads as JSON in an editor. The CLI prints `# AST`, the tree, then
// `# Diagnostics` and one line per diagnostic when there are any. The tree is
// spliced in as text, never re-serialised, so a float keeps the compiler's
// rendering rather than JavaScript's. A failed run is kept as it is, so its diff
// says why.
function astDumpAsJson(dump: string): string {
  const head = "# AST\n";
  if (!dump.startsWith(head)) return dump;
  const [tree = "", diagnostics = ""] = dump.slice(head.length).split("\n# Diagnostics\n");
  const lines = diagnostics.split("\n").filter((l) => l !== "");
  const json = `{\n  "ast": ${nested(tree.trim())},\n`
    + `  "diagnostics": ${nested(JSON.stringify(lines, null, 2))}\n}\n`;
  // Throws when the splice breaks the document.
  JSON.parse(json);
  return json;
}

// `text` indented as the value of a field of the document's root object.
function nested(text: string): string {
  return text.replaceAll("\n", "\n  ");
}

export async function dumpLowerViaVader(_source: string, entryPath: string, modules?: readonly string[]): Promise<string> {
  return runVaderDump("lowered-ast", entryPath, modules);
}

// The canonical target every committed snapshot is generated for. Neutral on
// purpose: not the machine any particular contributor uses.
export const SNAPSHOT_TARGET = "linux-x86_64";

/** The emitted C, pinned to `SNAPSHOT_TARGET` as every stage is. */
export async function dumpCViaVader(_source: string, entryPath: string, _modules?: readonly string[]): Promise<string> {
  return runVaderDump("c", entryPath);
}

export async function dumpBytecodeViaVader(_source: string, entryPath: string, _modules?: readonly string[]): Promise<string> {
  // `--annotate` appends `; <mangled name>` after every index-bearing op. The
  // index is a rank of insertion and says nothing on its own; the name is what a
  // reader — and a snapshot diff — actually needs. The reader strips `;`
  // comments, so the dump stays re-readable and `vader-vm-self` still runs it.
  return runVaderDump("bytecode", entryPath, undefined, ["--annotate"]);
}

// Drive `./build/vader dump --stage=<S> <file>` through the shared `runCli`
// spawn wrapper, which drains both pipes concurrently and enforces a SIGKILL
// wall-clock budget (a regressed stage can otherwise pin a CPU for hours —
// see `cli-bin.ts`). A non-zero exit is surfaced inline so snapshot diffs are
// debuggable rather than mysteriously empty.
async function runVaderDump(stage: string, entryPath: string, modules?: readonly string[], extra?: readonly string[]): Promise<string> {
  // PINNED to one target. A `@target` group in the closure (`std/io::write_bytes`
  // since println went through the FFI) makes every stage after target selection
  // differ per platform: Windows picks the Win32 body and the bytecode carries
  // `kernel32:GetStdHandle` where POSIX carries `write`. A snapshot's identity is
  // its target, not the machine that regenerated it.
  // Flags BEFORE the positional path: the CLI reads the first non-flag argument
  // as the entry file, so a flag placed after it is taken as a second positional
  // and silently changes what gets dumped.
  const args = ["dump", `--stage=${stage}`, `--target=${SNAPSHOT_TARGET}`];
  if (modules && modules.length > 0) args.push(`--module=${modules.join(",")}`);
  if (extra) args.push(...extra);
  args.push(entryPath);
  const { stdout, stderr, exit } = await runCli(args);
  if (exit !== 0) return `${CLI_FAILED_PREFIX} (exit ${canonicalExit(exit, stderr)})\n${stderr}${stdout}`;
  return stdout;
}

// A vader panic prints "vader: panic — …" to stderr, then abort()s. The abort's
// OS exit code is NOT portable — POSIX reports 134 (128 + SIGABRT), the Windows
// CI 9 — so a snapshot can't bake a single number. Identify the abort by
// its stderr signature (printed before abort() on every platform), or by a
// POSIX signal-range code, and canonicalise to 134 (what the crash snapshots
// bake) so a snippet that aborts the compiler (e.g. for_in_iter_trait's midir
// ICE) matches on every OS. A clean non-zero exit (a diagnostic failure) keeps
// its real code.
function canonicalExit(exit: number, stderr: string): number {
  if (exit !== 0 && (exit >= 128 || stderr.includes("vader: panic"))) return 134;
  return exit;
}
