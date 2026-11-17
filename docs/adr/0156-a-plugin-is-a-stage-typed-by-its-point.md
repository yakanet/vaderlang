# 0156: A plugin is a stage typed by its point, ordered by its description

## Status

Accepted (2026-11-17). Not yet in the tree: a prototype on the branch `proto/etapes`
holds each piece, the consolidation lands it.

## Context

Several decorators of the compiler were read by passes that had nothing to do with
them, and `BuildPlugin` let a project generate code only through rounds of the
whole front end. A prototype turned the checks of `check_project`, the
derivations (`json`, `@displayable`), a late body (the router of the guide), the
rewrites of the bytecode and a stage another program runs into stages of one
build. Four plugins chosen to break the model held: a cascade (a stage generates
what another reads), a body that waits for computed decorator values, an
external rewrite whose claims are checked, and an interceptor.

Each was written against its own trait (`SyntaxStage`, `CheckStage`,
`BytecodeStage`), with three planners of the same logic, decorators matched by
the name a file writes, and the stages of the compiler wired in by hand.

Vite and Rollup reached the same shape: a hook per step of the build, hook
filters so a plugin pays nothing where it has nothing to do (`given` here), a
sourcemap with generated code (anchors here), virtual modules. Two of their
choices are the source of known trouble and are not taken: the order of a
plugin is its position in an array, with `enforce: 'pre' / 'post'` as the only
way out, and a plugin keeps state across a build through `buildStart` /
`buildEnd`, which breaks caching and watch mode.

## Decision

- **One generic trait, one alias per point.**
  `Stage :: trait<In, Out, Spec> { describe, run :: fn(self, input: In) -> Out }`.
  `SourceStage`, `BodyStage`, `CheckStage` and `BytecodeStage` are aliases that fix
  the three arguments: the input type says where a stage runs, so a stage
  registered at the wrong point does not type-check. Each point hands a narrow
  view of its own (`Sources`, `Checked`), never the compiler's structures.
- **A stage describes itself, with a value typed by its point.** `describe` answers,
  without running the stage, what it is given and where it runs, which the engine
  reads to skip it, order it, check it and show it: `given` and `generates` for a
  source stage, `per` for a check, `requires`, `breaks` and `establishes` for the
  bytecode. Every field has a default; most stages write `given` alone, or
  nothing. An external stage prints the same description when asked `--describe`.
- **The order follows from the descriptions.** A stage that generates what another
  is given runs first and is read; a cycle is refused before anything runs. The
  order stages are registered in changes nothing. What a bytecode stage claims to
  establish is checked, and a stage that lies is a diagnostic, not a wrong program.
- **No life cycle for a plugin.** The build has one, run by the engine. A stage
  value lives one build. State across invocations goes through a collection per
  declaration and a merge, never through a field the stage mutates. Only an
  external stage holds a resource, its process, and the engine owns it.
- **The driver owns the registry.** `build.vader` receives it filled with the
  stages of the compiler, which cost nothing when their description finds nothing
  to do, and adds those of the libraries the project uses, each a plain function
  of the library. A project without a driver has the compiler's. A module that needs
  its stages declares it, so an import without them is a clear error.
- **An interceptor is plain Vader.** `@interceptor(around = "f")` on a decorator
  routes every call of the functions it decorates through `f`, which keeps a
  state per function. Whether the function suits the interceptor is the business
  of whoever writes the decorator: nothing proves it pure.
- **Generated code is shown where it comes from.** It is written to the project's
  generated tree, so it has real lines an editor opens, and a diagnostic in it
  carries a note naming the code that asked for it.

## Consequences

The compiler's own stages and a project's take the same door, which keeps the API
sufficient for both. A new point of the build is a new alias and a new input view,
not a new protocol. Running a project's stages in the driver's process puts each
invocation across a process boundary; the views each point hands are kept narrow
for that reason. An alias of an instantiated trait had to become transparent
first (`c3a185742`).
