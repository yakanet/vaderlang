# 0132: An import is used by a name, or by an impl its file runs

## Status

Accepted (2026-11-12).

## Context

Nothing reported an import that no longer served. A first attempt (2026-06-17)
looked each import up in the resolver's table of identifiers and reported false
positives across the tree: a name a wildcard brings points straight at the
exported symbol, so nothing says which import provided it.

Two things make an import serve without its file naming anything of it:

- **Impls are not imported.** Every impl of every loaded module goes in one
  table, so `x in c`, a `for` over a string, an operator or a conversion run an
  impl of a module the file may not import at all. A module is loaded because
  some file imports it.
- **A file may be the only one to load a module** another file relies on that
  way.

## Decision

- **By names first**, as the dead-code warning reads them: an import serves when
  its file writes a name it brings. A name written counts whoever provides it,
  so an unused import that shares a name with another goes unreported, and one
  that serves is never reported.
- **Then by the impls the file runs.** The typecheck files what each site
  invokes (calls, operators, indexing, conversions, the steps of a `for`,
  interpolation). An import serves when a site of its file runs a function its
  module declares. A member reached through a bound or a trait value is settled
  later: every impl of that trait counts.
- **Then by what it loads.** An import that serves its file nothing is reported
  only when the project keeps every module without it, or when none of the
  modules it would lose declares an impl.
- A body another platform selects is source of its file: its names count.
- `@allow_unused` above an import keeps it.
- A module loaded without its tests is not read: an import only its tests used
  is not unused in its source.

Set aside:

- **Reporting whenever another import keeps the module loaded**, impls or not.
  It reported `import "std/string"` above a `for c in text` in any file that
  also imports `std/console`: the program then walks its string only because
  another module happens to load the impl. The first sweep under that rule
  removed 184 imports; under the rule kept, 111.
- **Never reporting an import of a module that declares an impl**: 23 of the 44
  modules of the library do, the most imported among them.

## Consequences

- An import written to say which impls a file relies on is not reported.
- The warning needs the typed project: it runs after the typecheck, on every
  command that runs it.
