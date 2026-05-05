// Shared enum-variant validation. Used by `expr.ts` (`.Variant` shorthand),
// `call.ts` (`Enum.Variant` access), and `match.ts` (`.Variant` arm patterns)
// so the unknown-variant diagnostic stays consistent across all three sites.

import type { DiagnosticCollector } from "../../diagnostics/collector.ts";
import type { Span } from "../../diagnostics/diagnostic.ts";
import { enumVariantIndex } from "../../resolver/symbol.ts";

import { err } from "../diag.ts";
import type { EnumType } from "../types.ts";

export function checkEnumVariant(
  enumType: EnumType, variant: string, span: Span, diags: DiagnosticCollector,
): void {
  if (enumVariantIndex(enumType.symbol, variant) < 0) {
    err(diags, "T3027", span, `\`${variant}\` is not a variant of \`${enumType.symbol.name}\``);
  }
}
