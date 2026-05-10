import type { DiagnosticCollector } from "../diagnostics/collector.ts";
import type { Span } from "../diagnostics/diagnostic.ts";
import { RESOLVER } from "../diagnostics/codes.ts";
import { makeErr } from "../diagnostics/emit.ts";

export const err = makeErr(RESOLVER);

/** `void` is the type of expressions that yield no value — binding it as a
 *  user identifier shadows the primitive in confusing ways. */
const RESERVED_IDENTS: ReadonlySet<string> = new Set(["void"]);

/** Returns true when a diagnostic was emitted ; callers can still mint the
 *  symbol to avoid cascading "undefined identifier" errors. */
export function checkReservedIdent(
  name: string, span: Span, diags: DiagnosticCollector,
): boolean {
  if (!RESERVED_IDENTS.has(name)) return false;
  err(diags, "R2019", span, `\`${name}\``);
  return true;
}
