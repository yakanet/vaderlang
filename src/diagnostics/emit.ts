import type { DiagnosticCollector } from "./collector.ts";
import type { LabeledSpan, Span } from "./diagnostic.ts";

/**
 * Build a phase-specific `err()` helper bound to a code → message registry.
 *
 *   const err = makeErr(RESOLVER);
 *   err(diags, "R2007", span, `\`${name}\``);
 */
export function makeErr<C extends string>(registry: Readonly<Record<C, string>>) {
  return (
    diags: DiagnosticCollector,
    code: C,
    primary: Span,
    detail?: string,
    secondary?: readonly LabeledSpan[],
  ): void => {
    diags.emit({
      severity: "error",
      code,
      message: detail !== undefined ? `${registry[code]}: ${detail}` : registry[code],
      primary,
      secondary,
    });
  };
}
