export type DiagnosticFormat = "text" | "json";

export interface GlobalOpts {
  readonly diagnostics: DiagnosticFormat;
  readonly allowEnv: boolean;
  /** Apply bytecode-level peephole optimisations (`local.tee` fusion, cmp+not
   *  inversion, bool-const folding, double-not elision, dead-store
   *  elimination). Default `true`; `--no-bytecode-opt` flips it off for
   *  debugging / inspecting raw output. */
  readonly bytecodeOpt: boolean;
}

const FORMATS: readonly DiagnosticFormat[] = ["text", "json"] as const;

export const DEFAULT_OPTS: GlobalOpts = {
  diagnostics: "text",
  allowEnv: false,
  bytecodeOpt: true,
};

export interface ParseResult {
  readonly opts: GlobalOpts;
  readonly rest: string[];
  readonly errors: string[];
}

export function parseGlobalOpts(args: readonly string[]): ParseResult {
  let diagnostics: DiagnosticFormat = DEFAULT_OPTS.diagnostics;
  let allowEnv = DEFAULT_OPTS.allowEnv;
  let bytecodeOpt = DEFAULT_OPTS.bytecodeOpt;
  const rest: string[] = [];
  const errors: string[] = [];

  for (const a of args) {
    if (a.startsWith("--diagnostics=")) {
      const v = a.slice("--diagnostics=".length);
      if (v === "text" || v === "json") {
        diagnostics = v;
      } else {
        errors.push(`unknown --diagnostics format "${v}" (expected: ${FORMATS.join(", ")})`);
      }
      continue;
    }
    if (a === "--allow-env") {
      allowEnv = true;
      continue;
    }
    if (a === "--no-bytecode-opt") {
      bytecodeOpt = false;
      continue;
    }
    rest.push(a);
  }

  return { opts: { diagnostics, allowEnv, bytecodeOpt }, rest, errors };
}
