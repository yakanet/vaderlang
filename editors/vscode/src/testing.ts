// The Test view: the tests of a module, listed by `vader test --list
// --reporter=json` and run by `vader test --reporter=json`. The report
// (`docs/TOOLING.md`, *Tests*) is a JSON text sequence (RFC 7464): an event
// follows a record separator (RS) and ends its line, and everything else on
// stdout is what the tests write.
//
// Listing compiles a module, so it runs for a `.vader` document that is opened
// or saved and holds a test, or held one: never over the whole workspace. A
// module item is a module of a project, a test item a test of a file.

import { type ChildProcess, spawn } from "node:child_process";
import * as fs from "node:fs";
import * as path from "node:path";
import * as vscode from "vscode";

// One event of the report. A field is there for the events that carry it.
interface ReportEvent {
  event: string;
  module?: string;
  path?: string;
  test?: string;
  file?: string;
  line?: number;
  duration_ms?: number;
  message?: string;
}

// What running a module item takes.
interface ModuleData {
  // The folder `vader test` runs from.
  project: string;
  // The file or folder `vader test` was given to reach the module.
  entry: string;
  // The name the module declares, `""` when it declares none.
  name: string;
}

// One `vader test` of a run, and the item it reports on.
interface Job {
  item: vscode.TestItem;
  project: string;
  arguments: string[];
}

const RS = "\u001e";

const TEST_DECORATOR = /^\s*@test\b/m;

const MODULE_HEADER = /^\s*module\s+"([^"]*)"/m;

// What `vader test` exits with once it has listed: tests found, a module that
// does not compile, no test at all. Any other end is a listing that did not
// finish, a missing binary included.
const LISTED_EXIT_CODES = new Set([0, 1, 2]);

// Registers the test controller, and the command of the server's "run test"
// lenses (`vader.runTest`), which runs through it.
export function registerTests(context: vscode.ExtensionContext, binary: () => string): void {
  const tests = new VaderTests(binary);
  context.subscriptions.push(
    tests.controller,
    vscode.commands.registerCommand("vader.runTest", (uri: string, folder: string, name?: string) =>
      tests.runFromLens(uri, folder, name),
    ),
    vscode.workspace.onDidOpenTextDocument((document) => tests.documentChanged(document)),
    vscode.workspace.onDidSaveTextDocument((document) => tests.documentChanged(document)),
  );
  for (const document of vscode.workspace.textDocuments) tests.documentChanged(document);
}

class VaderTests {
  readonly controller = vscode.tests.createTestController("vader", "Vader");
  private readonly profile: vscode.TestRunProfile;
  private readonly modules = new WeakMap<vscode.TestItem, ModuleData>();
  // The listing under way for each file: a newer one supersedes it.
  private readonly listings = new Map<string, ChildProcess>();

  constructor(private readonly binary: () => string) {
    this.profile = this.controller.createRunProfile(
      "Run",
      vscode.TestRunProfileKind.Run,
      (request) => this.run(request),
      true,
    );
    this.controller.refreshHandler = () => this.refresh();
  }

  documentChanged(document: vscode.TextDocument): void {
    if (!this.listsTests(document)) return;
    void this.list(document.uri.fsPath, projectOf(document.uri.fsPath));
  }

  // The command of a lens: runs the test `name` of `uri`, or its module without
  // one, as the Test view would. A file the view does not show yet is listed
  // from `folder` first.
  async runFromLens(uri: string, folder: string, name?: string): Promise<void> {
    const file = vscode.Uri.parse(uri).fsPath;
    const target = this.knownTarget(file, folder, name) ?? (await this.listedTarget(file, folder, name));
    if (target === undefined) {
      void vscode.window.showErrorMessage(`Vader: no test found in ${path.basename(file)}`);
      return;
    }
    await this.run(new vscode.TestRunRequest([target], undefined, this.profile));
  }

  // Whether `document` is a Vader file that holds a test, or held one.
  private listsTests(document: vscode.TextDocument): boolean {
    if (document.uri.scheme !== "file" || document.languageId !== "vader") return false;
    return TEST_DECORATOR.test(document.getText()) || this.modulesHolding(document.uri.fsPath).length > 0;
  }

  private knownTarget(file: string, folder: string, name?: string): vscode.TestItem | undefined {
    const module = this.modulesHolding(file).find((item) => this.modules.get(item)?.project === folder);
    if (module === undefined || name === undefined) return module;
    return module.children.get(testId(file, name));
  }

  // A test the listing does not find, in a module that does not compile, runs
  // as its module, which shows why.
  private async listedTarget(file: string, folder: string, name?: string): Promise<vscode.TestItem | undefined> {
    const [module] = await this.list(file, folder);
    if (module === undefined || name === undefined) return module;
    return module.children.get(testId(file, name)) ?? module;
  }

  // Lists every module the view shows again, and the open documents, each file
  // once: the entry of a module may be open too.
  private async refresh(): Promise<void> {
    const projects = new Map<string, string>();
    for (const module of itemsOf(this.controller.items)) {
      const data = this.modules.get(module);
      if (data !== undefined) projects.set(data.entry, data.project);
    }
    for (const document of vscode.workspace.textDocuments) {
      if (this.listsTests(document)) projects.set(document.uri.fsPath, projectOf(document.uri.fsPath));
    }
    await Promise.all([...projects].map(([file, project]) => this.list(file, project)));
  }

  // Lists the module of `file` into the view: a module that no longer holds a
  // test leaves it, one that does not compile says so. Resolves to the module
  // items listed, none when superseded or when `vader` did not run.
  private list(file: string, project: string): Promise<vscode.TestItem[]> {
    this.listings.get(file)?.kill();
    return new Promise((resolve) => {
      const child = spawn(this.binary(), ["test", "--list", "--reporter=json", file], {
        cwd: project,
        stdio: ["ignore", "pipe", "ignore"],
      });
      this.listings.set(file, child);
      const events: ReportEvent[] = [];
      const reader = new ReportReader(() => {}, (event) => events.push(event));
      child.stdout?.setEncoding("utf8").on("data", (chunk: string) => reader.push(chunk));
      // Unhandled, a spawn that fails throws. It closes after, with a code
      // `vader` never exits with, which `settleListing` ignores.
      child.on("error", () => {});
      child.on("close", (code) => resolve(this.settleListing(file, project, child, code, events)));
    });
  }

  private settleListing(
    file: string,
    project: string,
    child: ChildProcess,
    code: number | null,
    events: ReportEvent[],
  ): vscode.TestItem[] {
    if (this.listings.get(file) !== child) return [];
    this.listings.delete(file);
    if (code === null || !LISTED_EXIT_CODES.has(code)) return [];
    return this.applyListing(file, project, events);
  }

  private applyListing(file: string, project: string, events: ReportEvent[]): vscode.TestItem[] {
    const listed = new Map<vscode.TestItem, vscode.TestItem[]>();
    const failed: vscode.TestItem[] = [];
    let module: vscode.TestItem | undefined;
    for (const event of events) {
      if (event.event === "module") {
        module = this.compiledModule(project, event);
        listed.set(module, []);
      }
      if (event.event === "test" && module !== undefined) {
        listed.get(module)?.push(this.testItem(module, event));
      }
      // Its tests stay as last listed.
      if (event.event === "error") failed.push(this.brokenModule(project, event));
    }
    for (const [item, tests] of listed) item.children.replace(tests);
    if (listed.size === 0 && failed.length === 0) {
      for (const stale of this.modulesHolding(file)) this.controller.items.delete(stale.id);
    }
    return [...listed.keys(), ...failed];
  }

  // Runs `request` one `vader test` at a time.
  private async run(request: vscode.TestRunRequest): Promise<void> {
    const run = this.controller.createTestRun(request);
    const jobs = this.jobsOf(request);
    for (const job of jobs) run.enqueued(job.item);
    for (const job of jobs) {
      if (run.token.isCancellationRequested) break;
      await this.runJob(run, job);
    }
    run.end();
  }

  private jobsOf(request: vscode.TestRunRequest): Job[] {
    const excluded = new Set(request.exclude ?? []);
    const included = request.include ?? itemsOf(this.controller.items);
    return included.filter((item) => !excluded.has(item)).flatMap((item) => this.jobsOfItem(item, excluded));
  }

  // A module asked for whole runs in one `vader test`; a test asked for alone,
  // or one of a module some of whose tests are left out, runs in one of its own.
  private jobsOfItem(item: vscode.TestItem, excluded: Set<vscode.TestItem>): Job[] {
    if (item.parent !== undefined) return this.testJobs(item.parent, [item]);
    const tests = itemsOf(item.children);
    if (tests.some((test) => excluded.has(test))) {
      return this.testJobs(item, tests.filter((test) => !excluded.has(test)));
    }
    const data = this.modules.get(item);
    if (data === undefined) return [];
    return [{ item, project: data.project, arguments: [data.entry] }];
  }

  // A `vader test` per test of `tests`, filtered to its coordinates.
  private testJobs(module: vscode.TestItem, tests: vscode.TestItem[]): Job[] {
    const data = this.modules.get(module);
    if (data === undefined) return [];
    // A module that declares no name is matched by any.
    const moduleGlob = data.name || "*";
    return tests.flatMap((test) => {
      const file = test.uri?.fsPath;
      if (file === undefined) return [];
      const filter = `${moduleGlob}:${path.basename(file)}:${test.label}`;
      return [{ item: test, project: data.project, arguments: ["--filter", filter, file] }];
    });
  }

  // Runs one `vader test`, reporting its report on `run`.
  private runJob(run: vscode.TestRun, job: Job): Promise<void> {
    return new Promise((resolve) => {
      const child = spawn(this.binary(), ["test", "--reporter=json", ...job.arguments], { cwd: job.project });
      const report = new JobReport(this, run, job.project);
      const reader = new ReportReader(
        (text) => report.output(text),
        (event) => report.event(event),
      );
      child.stdout?.setEncoding("utf8").on("data", (chunk: string) => reader.push(chunk));
      child.stderr?.setEncoding("utf8").on("data", (chunk: string) => run.appendOutput(terminalText(chunk)));
      const cancel = run.token.onCancellationRequested(() => child.kill());
      // A spawn that fails closes too.
      child.on("error", (error) => run.appendOutput(terminalText(`${error.message}\n`)));
      child.on("close", () => {
        cancel.dispose();
        reader.end();
        report.end();
        resolve();
      });
    });
  }

  moduleItem(project: string, event: ReportEvent): vscode.TestItem {
    const name = event.module ?? "";
    const entry = event.path ?? "";
    const label = name || path.basename(entry);
    const id = `${project}:${label}`;
    const existing = this.controller.items.get(id);
    if (existing !== undefined) return existing;
    const item = this.controller.createTestItem(id, label, vscode.Uri.file(entry));
    this.controller.items.add(item);
    this.modules.set(item, { project, entry, name });
    return item;
  }

  // The item of a module the report shows compiled: an error it showed is gone.
  compiledModule(project: string, event: ReportEvent): vscode.TestItem {
    const module = this.moduleItem(project, event);
    module.error = undefined;
    return module;
  }

  // The item of a module the report shows did not compile, saying so.
  brokenModule(project: string, event: ReportEvent): vscode.TestItem {
    const module = this.moduleItem(project, event);
    module.error = event.message;
    return module;
  }

  // The item of the test `event` locates, from the children of `module` when
  // it is one of them; the caller adds it.
  testItem(module: vscode.TestItem, event: ReportEvent): vscode.TestItem {
    const file = event.file ?? "";
    const name = event.test ?? "";
    const item = module.children.get(testId(file, name)) ?? this.controller.createTestItem(
      testId(file, name),
      name,
      vscode.Uri.file(file),
    );
    const line = Math.max(0, (event.line ?? 1) - 1);
    item.range = new vscode.Range(line, 0, line, 0);
    return item;
  }

  // The module items `file` is the entry of or holds a test of.
  private modulesHolding(file: string): vscode.TestItem[] {
    return itemsOf(this.controller.items).filter((module) =>
      module.uri?.fsPath === file || itemsOf(module.children).some((test) => test.uri?.fsPath === file),
    );
  }
}

// What one `vader test` of a run reports, as it reads it.
class JobReport {
  private module: vscode.TestItem | undefined;
  // The test that runs: what is written now is its output.
  private running: vscode.TestItem | undefined;

  constructor(
    private readonly tests: VaderTests,
    private readonly run: vscode.TestRun,
    private readonly project: string,
  ) {}

  output(text: string): void {
    this.run.appendOutput(terminalText(text), undefined, this.running);
  }

  event(event: ReportEvent): void {
    switch (event.event) {
      case "module":
        this.module = this.tests.compiledModule(this.project, event);
        break;
      case "start":
        if (this.module === undefined) break;
        this.running = this.tests.testItem(this.module, event);
        this.module.children.add(this.running);
        this.run.started(this.running);
        break;
      case "pass":
        if (this.running !== undefined) this.run.passed(this.running, event.duration_ms);
        this.running = undefined;
        break;
      case "fail":
        if (this.running !== undefined) {
          this.run.failed(this.running, failure(this.running, event.message), event.duration_ms);
        }
        this.running = undefined;
        break;
      case "error":
        this.run.errored(this.tests.brokenModule(this.project, event), new vscode.TestMessage(event.message ?? ""));
        break;
    }
  }

  // A test the process left without a result, a crash of the runner.
  end(): void {
    if (this.running === undefined) return;
    this.run.errored(this.running, new vscode.TestMessage("the test process ended before the test did"));
    this.running = undefined;
  }
}

// Cuts the stdout of `vader test --reporter=json` into what the tests write and
// the events, wherever the reads cut it.
class ReportReader {
  // Stdout not handed on yet: an event a read cut stays here until its newline.
  private pending = "";

  constructor(
    private readonly onOutput: (text: string) => void,
    private readonly onEvent: (event: ReportEvent) => void,
  ) {}

  push(chunk: string): void {
    this.pending += chunk;
    let start = 0;
    for (;;) {
      const separator = this.pending.indexOf(RS, start);
      if (separator < 0) {
        this.handOutput(this.pending.slice(start));
        start = this.pending.length;
        break;
      }
      this.handOutput(this.pending.slice(start, separator));
      const end = this.pending.indexOf("\n", separator);
      if (end < 0) {
        start = separator;
        break;
      }
      this.handEvent(this.pending.slice(separator + 1, end));
      start = end + 1;
    }
    this.pending = this.pending.slice(start);
  }

  // An event the process did not finish is output, without its RS.
  end(): void {
    this.handOutput(this.pending.replace(RS, ""));
    this.pending = "";
  }

  private handOutput(text: string): void {
    if (text !== "") this.onOutput(text);
  }

  // A line that does not read as an event is shown as it is.
  private handEvent(text: string): void {
    const event = parseEvent(text);
    if (event === undefined) {
      this.onOutput(`${text}\n`);
      return;
    }
    this.onEvent(event);
  }
}

function parseEvent(text: string): ReportEvent | undefined {
  try {
    const value: unknown = JSON.parse(text);
    if (typeof value === "object" && value !== null && typeof (value as { event?: unknown }).event === "string") {
      return value as ReportEvent;
    }
  } catch {
    // Not JSON: the caller shows it as output.
  }
  return undefined;
}

function testId(file: string, name: string): string {
  return `${file}:${name}`;
}

// The failure of `test`, shown on its declaration.
function failure(test: vscode.TestItem, text: string | undefined): vscode.TestMessage {
  const message = new vscode.TestMessage(text ?? "");
  if (test.uri !== undefined && test.range !== undefined) {
    message.location = new vscode.Location(test.uri, test.range);
  }
  return message;
}

// The test output panel is a terminal: a line ends with CRLF there.
function terminalText(text: string): string {
  return text.replace(/\r?\n/g, "\r\n");
}

function itemsOf(collection: vscode.TestItemCollection): vscode.TestItem[] {
  const items: vscode.TestItem[] = [];
  collection.forEach((item) => items.push(item));
  return items;
}

// The folder `vader test` runs from for `file`: its project, the nearest folder
// above it with a `vader.json` or a build driver, else its own folder. The
// language server's lenses carry the same one.
function projectOf(file: string): string {
  for (let dir = path.dirname(file); ; dir = path.dirname(dir)) {
    if (fs.existsSync(path.join(dir, "vader.json")) || holdsBuildDriver(dir)) return dir;
    if (path.dirname(dir) === dir) return path.dirname(file);
  }
}

// Whether `dir` holds a build driver: a `build.vader` declaring `module "build"`.
// A file of that name in another module is an ordinary source of its folder.
function holdsBuildDriver(dir: string): boolean {
  const driver = path.join(dir, "build.vader");
  if (!fs.existsSync(driver)) return false;
  return MODULE_HEADER.exec(fs.readFileSync(driver, "utf8"))?.[1] === "build";
}
