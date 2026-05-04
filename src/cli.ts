import { parseGlobalOpts, type GlobalOpts } from "./cli/options.ts";
import { cmdRun } from "./commands/run.ts";
import { cmdBuild } from "./commands/build.ts";
import { cmdFmt } from "./commands/fmt.ts";
import { cmdTest } from "./commands/test.ts";
import { cmdDump } from "./commands/dump.ts";
import { cmdRepl } from "./commands/repl.ts";

const HELP = `vader — the Vader compiler

USAGE:
  vader [global-options] <command> [options] [args]

COMMANDS:
  run [file]                       Interpret a Vader file (no args → REPL)
  build [file] [--target=native|wasm|ir] [--manifest]
                                   Compile to a binary (or .vir IR text for --target=ir)
  fmt [path]                       Format Vader sources in place
  test [path]                      Run @test functions
  dump --stage=<stage> <file>      Dump an IR stage as JSON/text
                                   Stages: ast, resolved-ast, typed-ast, bytecode, c, wasm

GLOBAL OPTIONS:
  --diagnostics=text|json          Output diagnostics in plain text (default) or JSON for tooling
  --allow-env                      Permit @comptime to read process env
  --help, -h                       Show this message
  --version, -v                    Show the compiler version
`;

const VERSION = "0.0.0-pre-mvp";

export async function runCli(argv: string[]): Promise<number> {
  if (argv.length === 0) return cmdRepl();

  const { opts, rest, errors } = parseGlobalOpts(argv);
  if (errors.length > 0) {
    for (const e of errors) console.error(`vader: ${e}`);
    return 1;
  }

  if (rest.length === 0) return cmdRepl();

  const [command, ...commandArgs] = rest;

  switch (command) {
    case "--help":
    case "-h":
    case "help":
      console.log(HELP);
      return 0;

    case "--version":
    case "-v":
    case "version":
      console.log(VERSION);
      return 0;

    case "run":
      return cmdRun(opts, commandArgs);

    case "build":
      return cmdBuild(opts, commandArgs);

    case "fmt":
      return cmdFmt(opts, commandArgs);

    case "test":
      return cmdTest(opts, commandArgs);

    case "dump":
      return cmdDump(opts, commandArgs);

    default:
      console.error(`vader: unknown command "${command}"`);
      console.error(`run "vader --help" for usage`);
      return 1;
  }
}

export type { GlobalOpts };
