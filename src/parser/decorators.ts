// Single source of truth for the recognized decorator names — mirrors SPEC §12.
// Update both this file and the SPEC together.

export type DecoratorName =
  | "comptime"
  | "extern"
  | "export"
  | "file"
  | "test";

export const DEC = {
  comptime: "comptime",
  extern:   "extern",
  export:   "export",
  file:     "file",
  test:     "test",
} as const satisfies Record<DecoratorName, DecoratorName>;

export const KNOWN_DECORATORS: ReadonlySet<DecoratorName> = new Set([
  DEC.comptime, DEC.extern, DEC.export, DEC.file, DEC.test,
]);

export function isKnownDecorator(name: string): name is DecoratorName {
  return (KNOWN_DECORATORS as ReadonlySet<string>).has(name);
}

export function hasDecorator(decs: ReadonlyArray<{ name: string }>, name: string): boolean {
  for (const d of decs) if (d.name === name) return true;
  return false;
}
