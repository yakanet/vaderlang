// Typed exception classes for failure modes that don't fit DiagnosticCollector
// (which is reserved for source-level errors with a Vader span). Both extend
// `Error` so existing `instanceof Error` catch-alls keep working.

export class CompilerBugError extends Error {
  constructor(message: string) {
    super(message);
    this.name = "CompilerBugError";
  }
}

/** Position of an error inside a `.vir` (binary) or `.virt` (text) artifact. */
export type BytecodeFormatPosition =
  | { readonly kind: "binary"; readonly byteOffset: number }
  | { readonly kind: "text"; readonly line: number; readonly column: number };

export class BytecodeFormatError extends Error {
  readonly path: string | null;
  readonly position: BytecodeFormatPosition | null;

  constructor(
    message: string,
    opts?: { path?: string | null; position?: BytecodeFormatPosition | null },
  ) {
    super(message);
    this.name = "BytecodeFormatError";
    this.path = opts?.path ?? null;
    this.position = opts?.position ?? null;
  }
}

/** Throw a `BytecodeFormatError` with the given prefix, message, and position.
 *  Returns `never` so callers can use it as a statement or expression. */
export function bytecodeFail(
  prefix: string, message: string,
  opts: { path: string | null; position: BytecodeFormatPosition | null },
): never {
  throw new BytecodeFormatError(`${prefix}: ${message}`, opts);
}

/** Render a `BytecodeFormatError` location as `<path>:<line>` (text) or
 *  `<path>@byte <offset>` (binary). Falls back to just `<path>` when no
 *  position is known, or `<unknown>` when neither is. */
export function formatBytecodeWhere(err: BytecodeFormatError): string {
  const path = err.path ?? "<unknown>";
  if (err.position === null) return path;
  if (err.position.kind === "text") return `${path}:${err.position.line}`;
  return `${path}@byte ${err.position.byteOffset}`;
}
