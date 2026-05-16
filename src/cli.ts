import { parseGlobalOpts, type GlobalOpts } from "./cli/options.ts";
import { cmdRun } from "./cli/commands/run.ts";
import { cmdBuild } from "./cli/commands/build.ts";
import { cmdFmt } from "./cli/commands/fmt.ts";
import { cmdLsp } from "./cli/commands/lsp.ts";
import { cmdTest } from "./cli/commands/test.ts";
import { cmdDump } from "./cli/commands/dump.ts";
import { cmdRepl } from "./cli/commands/repl.ts";
import { CLI_VERSION } from "./version.ts";

const HELP = `vader ${CLI_VERSION} — the Vader compiler

USAGE:
  vader [global-options] <command> [options] [args]

COMMANDS:
  run [file]                       Interpret a Vader file (no args → REPL)
                                   Accepts .vader source, .vir (binary IR), or .virt (text IR)
  build [file] [options]           Compile a Vader source file
                                     --target=native    Native binary (default ; via the C emitter)
                                     --target=ir        Binary bytecode module (.vir)
                                     --target=ir-text   Textual bytecode dump   (.virt)
                                     --target=c         Emit the generated C source only
                                     --target=wasm      WebAssembly module (not yet implemented)
                                     --release          Optimise ; default builds carry debug info
                                     --manifest         Read vader.json instead of a single file
                                     --out=<path>       Override the default output path
                                     --ldflags="..."    Native only: raw linker flags appended to the cc invocation
                                                        (e.g. helper.o, -lcrypto, -L/usr/local/lib). Resolves user @extern symbols.
  fmt [path] [options]             Format Vader sources (single file or recursive directory walk)
                                     --check          Read-only ; exit 1 if any file would change
                                     --stdout         Write formatted output to stdout (single file)
                                   Default rewrites every .vader under <path> in place ; <path> defaults to the cwd.
  test [path]                      Run @test functions
  lsp                              Run the Language Server (JSON-RPC over stdin/stdout)
                                   Spawned by VSCode and IntelliJ via their LSP clients ;
                                   provides semantic-tokens highlighting for .vader files.
  dump --stage=<stage> <file>      Dump an IR stage as JSON/text
                                     ast            Parser AST (JSON, spans elided)
                                     resolved-ast   Per-module symbol table + import wiring
                                     typed-ast      Per-decl + per-expression types
                                     evaluated-ast  @comptime / @file values + generic instances
                                     lowered-ast    Desugared tree (match/?/interp/defer expanded)
                                     dced-ast       Lowered tree post stdlib reachability prune
                                     cfg            Mid-IR CFG (post DCE + escape annotation)
                                     bytecode       Stack-machine ops + type/string/import tables
                                     c              Generated C source
                                     wasm           WebAssembly module (not yet implemented)

GLOBAL OPTIONS:
  --diagnostics=text|json          Output diagnostics in plain text (default) or JSON for tooling
  --allow-env                      Permit @comptime to read process env
  --no-bytecode-opt                Disable bytecode peephole optimisations (debug)
  --help, -h                       Show this message
  --version, -v                    Show the compiler version
`;


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
      console.log(CLI_VERSION);
      return 0;

    case "run":
      return cmdRun(opts, commandArgs);

    case "build":
      return cmdBuild(opts, commandArgs);

    case "fmt":
      return cmdFmt(opts, commandArgs);

    case "lsp":
      return cmdLsp(opts, commandArgs);

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
