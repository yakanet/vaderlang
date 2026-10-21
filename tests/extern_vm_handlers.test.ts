// tests/extern_vm_handlers.test.ts — every `@extern` in the compiler tree must
// be servable by the VM's host dispatcher.
//
// WHY: `@extern` is EXEMPT from the emit-time wiring check that guarantees a
// host import is servable (`vader/midir/emit.vader`: "@extern imports are
// link-resolved and exempt"). That exemption is right for USER FFI — the C
// linker resolves it. But an `@extern` the COMPILER ITSELF uses is invisible to
// `vader/vm/host.vader`, so it traps as "unbound host import" the moment the
// compiler runs on its own bytecode (the self-host path). The C linker
// binds it natively, so only the VM run shows the gap: the profiler brackets, for
// one, are emitted unconditionally.
//
// `lib/` is deliberately NOT covered. Its `@intrinsic` declarations — still the
// bulk of `lib/std/` — are validated at build time by the manifest
// (`intrinsic_id_for`): an unwired one fails the build rather than reaching the
// VM. Its `@extern` declarations (`lib/std/math`, `lib/std/env`, and all of
// `lib/system/`) need no handler at all: the VM resolves a foreign symbol
// through `dlsym` on the running process, so there is nothing to register.
//
// IF THIS FAILS, add a handler in `vader/vm/host.vader`, keyed on the import's
// mangled name. A no-op return is fine when the VM has no equivalent: that is
// what the profiler brackets get.
//
// This is a guard, not a proof: it checks the mangled name is *mentioned* in
// host.vader. `@extern` is still a draft surface — a real design pass over it is
// tracked separately.

import { expect, test } from "bun:test";
import { readdirSync, readFileSync, statSync } from "node:fs";
import { join } from "node:path";

function vaderFiles(dir: string): string[] {
  const out: string[] = [];
  for (const entry of readdirSync(dir)) {
    const p = join(dir, entry);
    if (statSync(p).isDirectory()) out.push(...vaderFiles(p));
    else if (entry.endsWith(".vader")) out.push(p);
  }
  return out;
}

test("every @extern under vader/ has a VM host handler", () => {
  const host = readFileSync("vader/vm/host.vader", "utf8");
  const missing: string[] = [];

  for (const file of vaderFiles("vader")) {
    const lines = readFileSync(file, "utf8").split("\n");
    // A mangle is the module path with `/` written `_`, then `$`, then the name.
    const module = lines.map((l) => l.match(/^module "([^"]+)"/)?.[1]).find((m) => m !== undefined);
    for (let i = 0; i < lines.length; i++) {
      if (!lines[i]!  .startsWith("@extern")) continue;
      // The decorator sits directly above its bodyless declaration, exported
      // or not.
      const decl = lines[i + 1] ?? "";
      const name = decl.match(/^(?:export\s+)?([A-Za-z_][A-Za-z0-9_]*)\s*::/)?.[1];
      if (!name || !module) continue;
      const mangled = `${module.replaceAll("/", "_")}$${name}`;
      if (!host.includes(mangled)) missing.push(`${file}:${i + 1} -> ${mangled}`);
    }
  }

  expect(missing).toEqual([]);
});
