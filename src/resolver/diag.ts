import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { LabeledSpan, Span } from "../diagnostics/diagnostic.ts";
import { RESOLVER, type ResolverCode } from "../diagnostics/codes.ts";

/** Emit a resolver error: prefixes the registry message with an optional detail. */
export function err(
  diags: DiagnosticCollector,
  code: ResolverCode,
  primary: Span,
  detail?: string,
  secondary?: readonly LabeledSpan[],
): void {
  diags.emit({
    severity: "error",
    code,
    message: detail !== undefined ? `${RESOLVER[code]}: ${detail}` : RESOLVER[code],
    primary,
    secondary,
  });
}
