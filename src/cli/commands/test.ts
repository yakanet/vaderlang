import { readFileSync, readdirSync, statSync } from "node:fs";
import { basename, dirname, join, relative, resolve } from "node:path";

import type { GlobalOpts } from "../options.ts";
import { pipelineBytecode } from "../../pipeline.ts";
import type { LoweredProject } from "../../lower/lowered-ast.ts";
import { staticStringValue } from "../../parser/ast.ts";
import { renderAllJson, renderAllTextSingle } from "../../diagnostics/render.ts";
import { defaultHostIO, makeBindings, runFn, VmError } from "../../vm/index.ts";

const SKIP_DIRS = new Set(["node_modules", "dist", "build", ".git", "target"]);

interface DiscoveredTest {
  readonly mangled: string;
  readonly displayName: string;
}

export async function cmdTest(opts: GlobalOpts, args: string[]): Promise<number> {
  const target = resolve(args[0] ?? ".");
  const files = discoverFiles(target);
  if (files.length === 0) {
    console.error(`vader test: no .vader files found under ${displayPath(process.cwd(), target)}`);
    return 2;
  }

  // Group by parent directory : folder modules (vader/lexer/, etc.) hold
  // siblings that reference each other, so building one file in isolation
  // misses cross-file symbols. The resolver auto-loads sibling .vader files
  // when given any single file in the folder, so we pick one representative
  // per dir and let it pull the rest in.
  const reps = pickModuleRepresentatives(files);

  const cwd = process.cwd();
  const ranTests = new Set<string>();
  let totalPass = 0;
  let totalFail = 0;
  let filesWithTests = 0;

  for (const file of reps) {
    const r = await pipelineBytecode(file, {
      allowEnv: opts.allowEnv,
      bytecodeOpt: opts.bytecodeOpt,
      keepTests: true,
    });
    const diags = r.diagnostics.sorted();
    if (diags.some((d) => d.severity === "error")) {
      if (opts.diagnostics === "json") {
        process.stderr.write(renderAllJson(diags) + "\n");
      } else {
        process.stderr.write(renderAllTextSingle(diags, r.file, r.source) + "\n");
      }
      totalFail += 1;
      continue;
    }

    // Filter out tests we already ran from an earlier representative — the
    // stdlib modules show up under nearly every build because they're imported
    // transitively. Each unique @test fn runs once per `vader test` invocation.
    const tests = findTests(r.dced).filter((t) => !ranTests.has(t.mangled));
    if (tests.length === 0) continue;
    filesWithTests += 1;

    console.log(displayPath(cwd, file));
    const host = makeBindings(defaultHostIO());
    for (const t of tests) {
      ranTests.add(t.mangled);
      const start = performance.now();
      try {
        runFn(r.bytecode, t.mangled, [], { host });
        const ms = (performance.now() - start).toFixed(1);
        console.log(`  ok ${t.displayName}  (${ms}ms)`);
        totalPass += 1;
      } catch (e) {
        const ms = (performance.now() - start).toFixed(1);
        const msg = e instanceof VmError ? e.rawMessage : (e instanceof Error ? e.message : String(e));
        console.log(`  FAIL ${t.displayName}  (${ms}ms)`);
        console.log(`    ${msg}`);
        totalFail += 1;
      }
    }
  }

  const total = totalPass + totalFail;
  if (total === 0 && filesWithTests === 0) {
    console.error(`vader test: no @test functions found under ${displayPath(cwd, target)}`);
    return 2;
  }

  console.log("");
  console.log(`${total} test${total === 1 ? "" : "s"} | ${totalPass} pass | ${totalFail} fail`);
  return totalFail === 0 ? 0 : 1;
}

/** Pick the smallest set of entry paths that, when compiled by the test
 *  runner, transitively cover every `.vader` file under the target. Three
 *  dir shapes are handled :
 *   1. **Single-file dir** — only one `.vader`, pass it through.
 *   2. **Folder module** — multiple files that share scope (no sibling-by-
 *      name imports). E.g. `vader/lexer/`. Pass the *dir* so the resolver
 *      loads every sibling as one module.
 *   3. **Per-file modules** — siblings import each other by name (E.g.
 *      `vader/fmt/cli` imports `vader/fmt/format`). Pass only the files
 *      that no sibling imports — those are the entry points. Their
 *      transitive imports drag the rest of the dir into the build, so
 *      every test fn is reachable without trying to standalone-compile
 *      library files whose types only resolve via the entry's context. */
function pickModuleRepresentatives(files: readonly string[]): string[] {
  const byDir = new Map<string, string[]>();
  for (const f of files) {
    const d = dirname(f);
    const bucket = byDir.get(d) ?? [];
    bucket.push(f);
    byDir.set(d, bucket);
  }
  const out: string[] = [];
  for (const [dir, group] of byDir) {
    if (group.length <= 1) {
      out.push(group[0]!);
      continue;
    }
    if (isFolderModule(group)) {
      out.push(dir);
      continue;
    }
    // Per-file dir : only files no sibling imports become entries. Files
    // imported by a sibling are reached transitively from those entries.
    const importedSiblings = collectSiblingImports(group);
    for (const f of group) {
      const name = basename(f, ".vader");
      if (!importedSiblings.has(name)) out.push(f);
    }
  }
  return out.sort();
}

function isFolderModule(files: readonly string[]): boolean {
  return collectSiblingImports(files).size === 0;
}

function collectSiblingImports(files: readonly string[]): Set<string> {
  const siblings = new Set(files.map((f) => basename(f, ".vader")));
  const out: Set<string> = new Set();
  for (const f of files) {
    let text;
    try { text = readFileSync(f, "utf8"); } catch { continue; }
    const re = /import\s+"([^"\n]+)"/g;
    let m: RegExpExecArray | null;
    while ((m = re.exec(text)) !== null) {
      const last = m[1]!.split("/").pop() ?? "";
      if (siblings.has(last)) out.add(last);
    }
  }
  return out;
}

function discoverFiles(target: string): string[] {
  let stat;
  try { stat = statSync(target); } catch { return []; }
  if (stat.isFile()) return target.endsWith(".vader") ? [target] : [];
  if (!stat.isDirectory()) return [];

  const out: string[] = [];
  const stack: string[] = [target];
  while (stack.length > 0) {
    const dir = stack.pop()!;
    let entries;
    try { entries = readdirSync(dir, { withFileTypes: true }); } catch { continue; }
    for (const e of entries) {
      if (e.name.startsWith(".") && e.name !== "." && e.name !== "..") continue;
      if (SKIP_DIRS.has(e.name)) continue;
      const full = join(dir, e.name);
      if (e.isDirectory()) stack.push(full);
      else if (e.isFile() && e.name.endsWith(".vader")) out.push(full);
    }
  }
  out.sort();
  return out;
}

function findTests(project: LoweredProject): DiscoveredTest[] {
  const out: DiscoveredTest[] = [];
  for (const mod of project.modules.values()) {
    for (const decl of mod.decls) {
      if (decl.kind !== "LoweredFnDecl") continue;
      if (decl.body === null) continue;
      const ast = decl.origin.decl;
      if (ast.kind !== "FnDecl") continue;
      const testDec = ast.decorators.find((d) => d.name === "test");
      if (testDec === undefined) continue;
      out.push({
        mangled: decl.mangled,
        displayName: extractTestName(testDec.args) ?? ast.name,
      });
    }
  }
  return out;
}

function extractTestName(args: readonly { kind: string }[]): string | null {
  if (args.length === 0) return null;
  const first = args[0];
  if (first?.kind !== "StringLitExpr") return null;
  return staticStringValue(first as never);
}

/** Show `file` as a cwd-relative path when it lives under cwd ; fall back to
 *  the absolute path otherwise (avoids hairy `../../../tmp/…` strings when
 *  the user runs `vader test` against a path outside the project root). */
function displayPath(cwd: string, file: string): string {
  const rel = relative(cwd, file);
  if (rel.startsWith("..")) return file;
  return rel || file;
}
