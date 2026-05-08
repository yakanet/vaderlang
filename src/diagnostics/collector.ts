import type { Diagnostic, Severity } from "./diagnostic.ts";

/**
 * Accumulates diagnostics across a compilation. Each phase pushes into a
 * collector; the runner renders them at the end (or after each phase, for
 * fail-fast modes).
 */
export class DiagnosticCollector {
  private readonly items: Diagnostic[] = [];
  /** Dedup by `(code, primary.start.offset, primary.end.offset, message)`.
   *  Cascading checks frequently produce the exact same diagnostic at the
   *  same span — e.g. when an unresolved type re-trips T3007 at every use.
   *  Drop the duplicates so users see each problem once. */
  private readonly seen = new Set<string>();

  emit(d: Diagnostic): void {
    const key = `${d.code}|${d.primary.start.file}|${d.primary.start.offset}|${d.primary.end.offset}|${d.message}`;
    if (this.seen.has(key)) return;
    this.seen.add(key);
    this.items.push(d);
  }

  all(): readonly Diagnostic[] {
    return this.items;
  }

  count(severity?: Severity): number {
    if (severity === undefined) return this.items.length;
    let n = 0;
    for (const d of this.items) if (d.severity === severity) n++;
    return n;
  }

  hasErrors(): boolean {
    return this.count("error") > 0;
  }

  /** Stable ordering by (file, offset, code). */
  sorted(): readonly Diagnostic[] {
    const copy = [...this.items];
    copy.sort((a, b) => {
      const fa = a.primary.start.file;
      const fb = b.primary.start.file;
      if (fa !== fb) return fa < fb ? -1 : 1;
      const oa = a.primary.start.offset;
      const ob = b.primary.start.offset;
      if (oa !== ob) return oa - ob;
      return a.code < b.code ? -1 : a.code > b.code ? 1 : 0;
    });
    return copy;
  }
}
