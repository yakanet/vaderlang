// tests/lib-probe — stage a throwaway LIBRARY ROOT in a temp directory.
//
// Two properties can only be observed from a module that really came from a
// library root, because both are decided by PROVENANCE rather than by a module's
// name: R2034 (a shipped library must not import the compiler) and W0012's lint
// scope (the toolchain's own exports are out of a project's scope). And a fixture
// using `std/` would pass against the old name-prefix code too, pinning nothing —
// so the probe has to be a namespace that is NOT `std/`.
//
// ⚠️ It stages a root in `/tmp` and runs the CLI with `cwd` there, rather than
// writing into the checkout's own `lib/`. The first attempt did the latter and
// broke the suite in a way worth remembering: `cli-bin.ts::newestSourceMtime()`
// walks `vader/` and `lib/` to decide whether `build/vader` is stale, and a file
// created under `lib/` is indistinguishable from an edited source. So the probe
// declared the binary stale for every other test FILE — and under `--parallel`
// that is 14 workers, one of which was loading `snapshot.test.ts`. The run went
// from 3402 tests to 909, with one unnamed failure and no hint of the cause.
//
// Staging in /tmp works because the cwd-relative `lib` is one of the roots the
// loader assembles, and it holds the library marker there, so it is tagged
// `.Toolchain` exactly as a bundled root would be — the same policy path is
// exercised, while the checkout is left untouched and the tests stay
// parallel-safe.

import { cpSync, mkdirSync, mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { dirname, join, resolve } from "node:path";

const REPO = resolve(".");

/** Run `fn(dir)` with `<dir>/lib/` holding `std/` (symlinked from the checkout,
 *  so `std/*` imports resolve) plus each named namespace built from its files
 *  (path relative to the namespace directory → content). The caller must pass
 *  `cwd: dir` to the CLI: that is what makes `<dir>/lib` the library root. */
export async function withStagedLibraryRoot<T>(
  namespaces: Record<string, Record<string, string>>,
  fn: (dir: string) => Promise<T>,
): Promise<T> {
  const dir = mkdtempSync(join(tmpdir(), "vlibroot-"));
  try {
    mkdirSync(join(dir, "lib"), { recursive: true });
    // The root is SYNTHETIC — real namespaces beside fabricated ones — so
    // `$VADER_HOME` cannot supply it the way it does for a staged project: it
    // would hand over the checkout's `lib/` and lose the fabrications. The real
    // halves are therefore COPIED, not symlinked, which Windows refuses to a plain
    // user. `std/` is there because every probe needs `std/io` to write a runnable
    // entry, and `system/` comes with it — `std/io` imports it for the write
    // syscall, and a root missing it fails to resolve before any probe runs.
    // Together they are 400 KB, well under what a probe's own compile costs.
    cpSync(join(REPO, "lib", "std"), join(dir, "lib", "std"), { recursive: true });
    cpSync(join(REPO, "lib", "system"), join(dir, "lib", "system"), { recursive: true });
    for (const [ns, files] of Object.entries(namespaces)) {
      for (const [rel, content] of Object.entries(files)) {
        const p = join(dir, "lib", ns, rel);
        mkdirSync(dirname(p), { recursive: true });
        writeFileSync(p, content);
      }
    }
    return await fn(dir);
  } finally {
    rmSync(dir, { recursive: true, force: true });
  }
}
