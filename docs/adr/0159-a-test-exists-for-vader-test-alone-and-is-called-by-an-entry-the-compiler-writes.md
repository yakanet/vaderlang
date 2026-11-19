# 0159: A test exists for `vader test` alone, and is called by an entry the compiler writes

## Status

Accepted (2026-11-19). Applies [0156](0156-a-plugin-is-a-stage-typed-by-its-point.md);
the entry is named after [0157](0157-a-declaration-the-compiler-writes-is-named-with-a-double-dollar.md).

## Context

Nothing calls a `@test` function, so every pass that drops what nothing reaches
needed a rule of its own to keep it: the roots of the reach walk and of W0007
(`wires_a_root`), the DCE of the lowering (`keep_tests`), the one of the bytecode
(`keep_mangles`, one per test), and the harness found the tests again on the
lowered IR by their decorator (`find_tests`). The tests of a module were also
type-checked and lowered by every build, though no build runs them: the
dependencies already lost theirs at load (`without_tests`), the program's own
modules did not.

## Decision

- **A test exists for `vader test` alone.** Every other command loads a module
  without its tests and the private declarations only they reach, by
  reachability, never by a comment such as the `// ---- tests ----` banner. What
  went is kept on the loaded module, so that trimming keeps the symbols its
  imports serve and W0006 reads its names. The language server loads as `vader
  test` does.
- **The module under test gains an entry, `tests$$run(rank: i64)`,** which a
  source stage of the compiler writes (`TestsStage`, given `@test`): a `match` that
  calls the test of each rank. A test is then a private function reached from its
  caller, and the reach walk, W0007 and both DCEs keep it with no rule of their
  own. What the compiler writes counts as reached for W0007.
- **The harness reads the tests from `tests_declared`,** the very reading the
  stage writes the entry from, on the files of the loaded module: the rank of a
  test in the report is the rank the entry calls it by. The VM calls the entry
  once per test (`exec_fn` passes the rank), each call isolated as before.

Rejected:

- Keeping the tests checked by every build, with the generated entry as a lint
  root and the DCE pruning it from a binary: a test is not part of what a build
  delivers.
- The stage handing its table to the harness through a registry: a hidden channel
  where a shared function says the same.

## Consequences

- `@test` is read in three places: the loader, which leaves the tests out; the
  stage, through `tests_declared`; the code lens of the editor.
- `vader test --filter` compiles every test of the module, and calls only those
  the filter keeps.
- A build no longer reports an error inside a test; `vader test` and the editor
  do.
