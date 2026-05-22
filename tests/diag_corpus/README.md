# Diagnostic-parity negative corpus

Mini single-file snippets that each trigger one specific diagnostic code,
used by `tests/parity-diagnostics.test.ts` to surface TS↔Vader code
divergences the broader `tests/snippets/` corpus doesn't naturally hit.

Layout : `tests/diag_corpus/<bucket>/<r-code>_<short-label>/_main.vader`.
`listSnippets` from `tests/snapshot.ts` is reused, so the directory shape
matches `tests/snippets/`. No `.snapshot` files — the suite extracts the
`error[XXXX]` set from each compiler's stdout and compares as a set.

## Buckets

- `resolver/` — R2xxx codes. Vader currently ports R2006 / R2019 only ;
  every other snippet here flips to `TS-only`.
- `comptime/` — C4xxx codes. Vader's `codes.vader` defines C4001-C4007
  with **different meanings** than TS, so several snippets surface as
  `same code, different sense` ; codes Vader hasn't allocated yet
  (C4008+) flip to `TS-only`.
- `warning/` — W0xxx warnings. Vader has W0001 only, so W0002 stays
  `TS-only` until the port catches up.

## Codes intentionally not covered

These codes are defined in `src/diagnostics/codes.ts` but **never
emitted** by the TS pipeline today — no call-site references them. They
behave like reserved-but-unused identifiers : a snippet targeting them
would produce no TS diagnostic, so diag-parity couldn't compare
anything. Tracked here so we know to either add an emit site or retire
the code on the next pass.

- `R2013` (self only valid as the first parameter of a method)
- `C4001` (expression cannot be evaluated at compile time)
- `C4003` (function is not callable in comptime context) — referenced
  only by a comment in `src/comptime/sandbox.ts`.
- `C4004` (comptime call stack overflow)
- `C4007` (comptime value has incompatible type)
- `C4011` (comptime feature not yet supported) — emitted only via the
  sandbox `BuiltinResult` for malformed builtin args, hard to hit
  cleanly from a single-file snippet.
- `C4012` (`@file` expects a single string-literal argument)
- `C4013` (decorator arguments must be string literals at comptime)
- `C4014` (generic instance discovery did not converge)

## Codes emitted by TS but no clean single-file trigger

- `C4002` (comptime evaluation panicked) — only reached via VM error
  fallback in `src/comptime/run.ts` ; div-by-zero / OOB / cycles peel
  off into C4005 / C4010 / C4009 first, and other VM faults (e.g.
  arithmetic overflow) get constant-folded before the VM sees them.
  Existing snippets like `square_call` exercise Vader-emits-C4002 (its
  unported CallExpr path) without needing a TS-side trigger.
- `C4008` (ENV access requires `--allow-env`) — `@env` is wired in the
  sandbox (`src/comptime/sandbox.ts:88`) but not exposed as an
  intrinsic in `src/parser/intrinsics.ts`, so the surface call
  `@env("X")` trips P1014 first.

## Codes that need infra to trigger (multi-file / setup)

These codes can't be triggered with a lone `_main.vader` ; they need
harness changes or extra fixture files.

- `R2005` (import cycle detected) — needs two files importing each
  other.
- `R2011` (duplicate import binding) — needs two `import "..." { x }`
  lines from different modules colliding ; single-file `_main.vader`
  hits R2004 first.
- `R2012` (imported symbol shadows a builtin) — every import of a name
  matching a builtin (e.g. `i32`) trips R2003 (not exported) first,
  because no stdlib module exports a builtin-named symbol. Would need
  a fixture module that re-exports a builtin name.
- `R2014` (vader.json malformed or unreadable) — needs the snippet to
  carry a broken `vader.json` and the harness to invoke the
  `--manifest` path.
- `R2015` (module folder is empty) — needs an empty subdirectory.
- `R2017` (feature not yet implemented) — catch-all in the resolver,
  no stable single-file trigger.
