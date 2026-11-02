// tests/cli_test_report: `vader test --reporter=json` and `--list`.
//
// The JSON report is a JSON text sequence (RFC 7464): each event is led by RS
// and ends its line. A test writes to the same stream, so the fixture holds one
// that prints without a newline: a reader cutting on newlines would glue that
// output to the next event.

import { test, expect } from "bun:test";
import { ensureCliBuilt, runCli, MEDIUM_BUILD } from "./cli-bin.ts";
import { join } from "node:path";

ensureCliBuilt();

const REPORT = join(import.meta.dir, "fixtures", "test_cmd", "report", "report.vader");
// The report spells a path with `/`, on Windows too.
const REPORT_PATH = REPORT.split("\\").join("/");
const RS = "\u001e";

type Event = Record<string, unknown>;

// The events of `stdout`, and the test output around them: what follows an RS
// up to the newline is an event, everything else is output.
function readSequence(stdout: string): { events: Event[]; output: string } {
  const chunks = stdout.split(RS);
  const events: Event[] = [];
  let output = chunks.shift() ?? "";
  for (const chunk of chunks) {
    const end = chunk.indexOf("\n");
    events.push(JSON.parse(chunk.slice(0, end)));
    output += chunk.slice(end + 1);
  }
  return { events, output };
}

test("the JSON report gives each step of a run as an event", async () => {
  const r = await runCli(["test", "--reporter=json", REPORT], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(1);
  const { events, output } = readSequence(r.stdout);
  expect(events.map((e) => e.event)).toEqual(["module", "start", "pass", "start", "fail", "summary"]);
  expect(output).toBe("no newline");
  expect(events[0]).toEqual({ event: "module", module: "test_cmd_report", path: REPORT_PATH });
  expect(events[1]).toEqual({
    event: "start",
    module: "test_cmd_report",
    test: "test_prints",
    file: REPORT_PATH,
    line: 10,
  });
  expect(events[4]).toMatchObject({ event: "fail", test: "test_fails" });
  expect(String(events[4]?.message)).toContain("boom");
  expect(typeof events[4]?.duration_ms).toBe("number");
  expect(events[5]).toMatchObject({ event: "summary", total: 2, pass: 1, fail: 1 });
}, MEDIUM_BUILD);

test("--list names the tests in the form --filter reads, and runs none", async () => {
  const r = await runCli(["test", "--list", REPORT], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  expect(r.stdout.trim().split("\n")).toEqual([
    "test_cmd_report:report.vader:test_prints",
    "test_cmd_report:report.vader:test_fails",
  ]);
}, MEDIUM_BUILD);

test("--list with the JSON report gives the module and its tests", async () => {
  const r = await runCli(["test", "--list", "--reporter=json", REPORT], undefined, MEDIUM_BUILD);
  expect(r.exit).toBe(0);
  const { events, output } = readSequence(r.stdout);
  expect(output).toBe("");
  expect(events.map((e) => [e.event, e.test, e.line])).toEqual([
    ["module", undefined, undefined],
    ["test", "test_prints", 10],
    ["test", "test_fails", 15],
  ]);
}, MEDIUM_BUILD);
