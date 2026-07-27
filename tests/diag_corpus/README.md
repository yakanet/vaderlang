# Negative diagnostic corpus

Mini snippets that each provoke one specific compiler diagnostic, so that
every allocated code has something pinning the code it *actually* emits.
The positive snippets under `tests/snippets/` carry their diagnostics
inside the per-stage snapshots already; this corpus exists for the error
paths those never reach.

Driven by `tests/diagnostics-corpus.test.ts`, which dumps the native
compiler at the `lowered-ast` stage — the point where every front-end
diagnostic has accumulated (lexer → parser → resolver → typecheck →
comptime) — and snapshots the emitted `[span] severity[CODE]` set per
fixture. **The self-hosted compiler is the oracle.** The former TS↔Vader
set-parity was dropped when the TypeScript reference was removed.

## Layout

```
tests/diag_corpus/<bucket>/<code>_<short-label>/_main.vader
                                               /diagnostics.snapshot
```

`listSnippets` from `tests/snapshot.ts` is reused, so the directory shape
matches `tests/snippets/`. Buckets are the emitting phase: `lexer`,
`parser`, `resolver`, `typecheck`, `comptime`, `lower`, `warning`.

A fixture may carry extra files next to `_main.vader` (`lib.vader`,
`helper.vader`) when the diagnostic needs more than one module — import
cycles, duplicate import bindings, cross-module visibility.

Directory names use the lowercased code (`t3001_type_mismatch`,
`l0006_typed_suffix_removed`). Some names are historical labels from the
TS reference; where the native compiler emits a renumbered code, the
committed snapshot records the code actually emitted, which keeps the
divergence visible instead of hidden.

## Adding a fixture

Every newly allocated diagnostic code gets one — see `.claude/CLAUDE.md`
§12. Write the smallest `_main.vader` that trips the code, run
`UPDATE_SNAPSHOTS=1 bun run test`, and **read the generated snapshot**:
if it contains a code you didn't intend, an earlier phase fired first and
the fixture is testing something else.

Pre-MVP, codes may be renumbered or reused. When that happens the fixture
directory, the `<phase>_info` message and the snapshot all move in the
same commit.

## Coverage

74 of the 173 codes defined in `vader/diagnostics/codes.vader` have a
fixture here (2026-07-28). Recompute with:

```sh
python3 - <<'PY'
import re, pathlib
defined = set(re.findall(r'"([A-Z][0-9]{4})"',
    pathlib.Path('vader/diagnostics/codes.vader').read_text()))
seen = set()
for f in pathlib.Path('tests/diag_corpus').rglob('diagnostics.snapshot'):
    seen |= set(re.findall(r'\[([A-Z][0-9]{4})\]', f.read_text()))
print(sorted(defined - seen))
PY
```

The gap is not all missing work. Three kinds of uncovered code live in
there, and they need different answers:

- **Reserved** — the variant exists, no pass emits it yet. Covered when
  the check ships, not before.
- **Shadowed** — an earlier phase always fires first on any input that
  would reach it (a surface form tripping a parse error before the
  resolver sees it). Needs a fixture built around the shadowing, or an
  honest note that it is unreachable today.
- **Genuinely untested** — reachable, emitted, nothing pins it. These are
  the ones worth closing.

Sorting the list into those three buckets is a pass nobody has run end to
end; until then, treat a missing code as "unknown", not as "impossible".
