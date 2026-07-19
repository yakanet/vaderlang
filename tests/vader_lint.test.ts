// tests/vader_lint — end-to-end coverage for `vader lint` (the unused-export
// lint, W0012). The name-reachability engine (`dead_exports`) is exercised in
// full here through the native CLI: `load_project` → merge non-stdlib module
// decls → `dead_exports`. Colocated `vader/typecheck` @tests cover the W0007
// half of the shared engine; this drives the W0012 half end to end.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";

ensureCliBuilt();

const DEAD = "tests/lint_fixtures/dead_export/_main.vader";
const CLEAN = "tests/lint_fixtures/all_reached/_main.vader";

function countW0012(out: string): number {
  return (out.match(/W0012/g) ?? []).length;
}

test("vader lint flags an export unreachable from the roots", async () => {
  const { stdout, stderr, exit } = await runCli(["lint", DEAD]);
  const out = `${stdout}\n${stderr}`;
  // Exactly the one dead export — `orphan`. `reached` (called by main) and the
  // dead PRIVATE fn (W0007's job) must not surface here.
  expect(countW0012(out)).toBe(1);
  expect(out).toContain("orphan");
  expect(out).not.toContain("private_dead");
  expect(exit).toBe(1);
}, MEDIUM_BUILD);

test("vader lint is silent when every export is reached", async () => {
  const { stdout, stderr, exit } = await runCli(["lint", CLEAN]);
  const out = `${stdout}\n${stderr}`;
  expect(countW0012(out)).toBe(0);
  expect(exit).toBe(0);
}, MEDIUM_BUILD);

test("vader build never runs the unused-export lint (P-lean)", async () => {
  // The default build must not gain the lint : building the dead-export fixture
  // to C emits no W0012 (and succeeds — a dead export is not an error).
  const { stdout, stderr, exit } = await runCli(["build", "--target=c", "--out=-", DEAD]);
  const out = `${stdout}\n${stderr}`;
  expect(countW0012(out)).toBe(0);
  expect(exit).toBe(0);
}, MEDIUM_BUILD);

test("vader lint reports a usage error when no file is given", async () => {
  const { stderr, exit } = await runCli(["lint"]);
  expect(stderr).toContain("expected a file");
  expect(exit).toBe(1);
}, MEDIUM_BUILD);
