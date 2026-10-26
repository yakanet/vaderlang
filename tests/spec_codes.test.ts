// SPEC.md describes the language for a reader and names no diagnostic code:
// which code a rule fires is recorded in `vader/support/diagnostics/codes.vader`
// and pinned by the fixtures and snapshots. This scan keeps codes out of SPEC, and
// holds each registry enum to its own family letter.

import { expect, test } from "bun:test";
import { readFileSync } from "node:fs";
import { join } from "node:path";

const ROOT = join(import.meta.dir, "..");
const FAMILY_OF_ENUM: Record<string, string> = {
  LexerCode: "L",
  ParserCode: "P",
  ResolverCode: "R",
  TypecheckCode: "T",
  ComptimeCode: "C",
  LowerCode: "M",
  HookCode: "H",
  WarningCode: "W",
  InternalCode: "I",
};
const CITED_CODE = new RegExp(`\\b[${Object.values(FAMILY_OF_ENUM).join("")}]\\d{4}\\b`, "g");
const ENUM_HEADER = /^export (\w+) :: enum\(CodeInfo\) \{$/;
const CODE_ID = /\.id = "([A-Z]\d{4})"/;

// Every id of the registry, keyed by the enum that declares it.
function registryIds(): Map<string, string> {
  const enumOf = new Map<string, string>();
  let current: string | null = null;
  for (const line of readFileSync(join(ROOT, "vader", "support", "diagnostics", "codes.vader"), "utf8").split("\n")) {
    const header = ENUM_HEADER.exec(line);
    if (header) {
      current = header[1]!;
      continue;
    }
    if (line === "}") {
      current = null;
      continue;
    }
    const id = CODE_ID.exec(line);
    if (current !== null && id) enumOf.set(id[1]!, current);
  }
  return enumOf;
}

const REGISTRY = registryIds();

test("every registry enum holds only codes of its own family", () => {
  const misfiled: string[] = [];
  for (const [id, enumName] of REGISTRY) {
    const family = FAMILY_OF_ENUM[enumName];
    if (family === undefined || !id.startsWith(family)) misfiled.push(`${id} in ${enumName}`);
  }
  expect(misfiled).toEqual([]);
});

test("SPEC.md names no diagnostic code", () => {
  expect(readFileSync(join(ROOT, "SPEC.md"), "utf8").match(CITED_CODE) ?? []).toEqual([]);
});
