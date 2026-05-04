// Single source of truth for the recognized decorator names — mirrors SPEC §12.
// Update both this file and the SPEC together.

export type DecoratorName =
  | "comptime"
  | "extern"
  | "export"
  | "file"
  | "test";

export const KNOWN_DECORATORS: ReadonlySet<DecoratorName> = new Set([
  "comptime", "extern", "export", "file", "test",
]);

export function isKnownDecorator(name: string): name is DecoratorName {
  return (KNOWN_DECORATORS as ReadonlySet<string>).has(name);
}
