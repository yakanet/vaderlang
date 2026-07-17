// tests/extern_vm_handlers.test.ts — every `@extern` in the compiler tree must
// be servable by the VM's host dispatcher.
//
// WHY: `@extern` is EXEMPT from the emit-time wiring check that guarantees a
// host import is servable (`vader/midir/emit.vader`: "@extern imports are
// link-resolved and exempt"). That exemption is right for USER FFI — the C
// linker resolves it. But an `@extern` the COMPILER ITSELF uses is invisible to
// `vader/vm/host.vader`, so it traps as "unbound host import" the moment the
// compiler runs on its own bytecode (B0-in-VM, the self-host path). That is
// exactly how `vader_profile$vader_prof_begin` killed the self-host run at pc=1:
// the profiler brackets are emitted unconditionally, the C linker bound them
// natively, and the VM had no handler.
//
// `stdlib/` is deliberately NOT covered: it uses `@intrinsic`, which the manifest
// (`intrinsic_id_for`) already validates at build time — an unwired one fails the
// build rather than reaching the VM.
//
// IF THIS FAILS, pick one:
//   - add a handler in `vader/vm/host.vader` (a no-op return is fine when the VM
//     has no equivalent — that is what the profiler brackets get), or
//   - gate the call out at compile time (see `PROFILE_ENABLED` in
//     `vader/profile/profile.vader`), so the import is never emitted.
//
// This is a guard, not a proof: it checks the symbol is *mentioned* in
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
    for (let i = 0; i < lines.length; i++) {
      if (!lines[i].startsWith("@extern")) continue;
      // The decorator sits directly above its bodyless declaration.
      const decl = lines[i + 1] ?? "";
      const name = decl.match(/^([A-Za-z_][A-Za-z0-9_]*)\s*::/)?.[1];
      if (!name) continue;
      if (!host.includes(name)) missing.push(`${file}:${i + 1} -> ${name}`);
    }
  }

  expect(missing).toEqual([]);
});
