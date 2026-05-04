export type DiagnosticFormat = "text" | "json";

export interface GlobalOpts {
  readonly diagnostics: DiagnosticFormat;
  readonly allowEnv: boolean;
}

const FORMATS: readonly DiagnosticFormat[] = ["text", "json"] as const;

export const DEFAULT_OPTS: GlobalOpts = {
  diagnostics: "text",
  allowEnv: false,
};

export interface ParseResult {
  readonly opts: GlobalOpts;
  readonly rest: string[];
  readonly errors: string[];
}

export function parseGlobalOpts(args: readonly string[]): ParseResult {
  let diagnostics: DiagnosticFormat = DEFAULT_OPTS.diagnostics;
  let allowEnv = DEFAULT_OPTS.allowEnv;
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
    rest.push(a);
  }

  return { opts: { diagnostics, allowEnv }, rest, errors };
}
