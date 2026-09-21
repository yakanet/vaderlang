// tests/cli_graph — `vader graph`, the module import graph.
//
// The graph is read off the loader, so what it draws is what a build loads. The
// fixture is a three-module chain with one transitive edge (`main` imports both
// `alpha` and `beta`, `alpha` imports `beta`), which separates a renderer that
// drops an edge from one that invents a transitive one.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const CHAIN = join(import.meta.dir, "graph_fixtures", "chain", "main.vader");

test("graph draws every module and every import edge", async () => {
  const r = await runCli(["graph", CHAIN], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  const lines = r.stdout.trim().split("\n").map((l) => l.trim());
  expect(lines[0]).toBe("graph TB");
  expect(lines).toContain('chain["chain"]');
  expect(lines).toContain('chain_alpha["chain/alpha"]');
  expect(lines).toContain('chain_beta["chain/beta"]');
  // All three edges, and nothing else: an invented transitive edge would be a
  // fourth arrow.
  const edges = lines.filter((l) => l.includes("-->")).sort();
  expect(edges).toEqual([
    "chain --> chain_alpha",
    "chain --> chain_beta",
    "chain_alpha --> chain_beta",
  ]);
});

// Modules are keyed by `module_name`, not by the loader's folder key. The two
// diverge for a project loaded from an outer root — which this fixture is, since
// the suite runs it from the repo root — so a regression here drops every edge.
test("graph names modules by their module name, not their folder", async () => {
  const r = await runCli(["graph", CHAIN], undefined, MEDIUM_BUILD);
  expect(r.stdout).not.toContain("graph_fixtures");
});

test("graph emits DOT on request", async () => {
  const r = await runCli(["graph", "--format=dot", CHAIN], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).toContain("digraph modules {");
  expect(r.stdout).toContain('"chain" -> "chain/alpha";');
  expect(r.stdout.trim().endsWith("}")).toBe(true);
});

// `--scope=project` is the default and hides the library; `--scope=all` is what
// makes `std/io` — which the fixture imports — visible.
test("scope=all reaches the library, the default does not", async () => {
  const narrow = await runCli(["graph", CHAIN], undefined, MEDIUM_BUILD);
  expect(narrow.stdout).not.toContain("std/io");
  const wide = await runCli(["graph", "--scope=all", CHAIN], undefined, MEDIUM_BUILD);
  expect(wide.exit).toBe(0);
  expect(wide.stdout).toContain('["std/io"]');
});

// A driven project reaches the compiler's own modules through `--include-paths`,
// so they arrive as `ModuleOrigin.Build` — the same provenance as the user's own
// code. Filtering on provenance alone drew all 18 of them as "the project"; the
// module NAME is what separates them, exactly as `diagnose_import_path` does.
test("scope=project hides the compiler from a driven project", async () => {
  const driven = join(import.meta.dir, "hook_fixtures", "observe_only", "build.vader");
  const r = await runCli(["graph", driven], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).not.toContain("vader/pipeline");
  expect(r.stdout).toContain('build["build"]');
});

// ...but when the entry IS a compiler module, the compiler is the project.
test("scope=project keeps vader/* when the entry is itself a compiler module", async () => {
  const r = await runCli(["graph", "vader/cli/main.vader"], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout).toContain('vader_pipeline["vader/pipeline"]');
  expect(r.stdout).toContain("vader_cli --> vader_pipeline");
});

test("graph rejects an unknown format and names the alternatives", async () => {
  const r = await runCli(["graph", "--format=svg", CHAIN], undefined, MEDIUM_BUILD);
  expect(r.exit).not.toBe(0);
  expect(r.stderr).toContain("mermaid");
  expect(r.stderr).toContain("dot");
});

test("graph asks for a file when given none", async () => {
  const r = await runCli(["graph"], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(1);
  expect(r.stderr).toContain("expected a file argument");
});
