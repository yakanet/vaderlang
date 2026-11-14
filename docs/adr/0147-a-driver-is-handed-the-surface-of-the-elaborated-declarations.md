# 0147: A driver is handed the surface of the elaborated declarations

## Status

Accepted (2026-11-14). Supersedes in part
[0145](0145-a-build-driver-is-a-thin-client-that-re-reads-the-sources.md): its
decision that no AST crosses, and that the driver re-reads the text. The
surface opens a little at a time; what crosses today is listed in
`lib/toolchain/protocol/declarations.vader`.

**Superseded in part by
[0150](0150-a-driver-is-handed-everything-but-the-bodies-of-functions.md) (2026-11-14)**:
every declaration crosses with what it writes outside the body of a function,
values included; only the bodies of functions stay behind.

## Context

0145 left one question open: does a driver read the AST as written, by parsing
the text again, or the AST as the front end elaborated it? The two differ. The
front end fills in default and named arguments in place, completes `implements`
shorthands and copies members into empty impls, and drops the `@test` and
unreachable declarations of `lib/`. Drivers have read the elaborated tree since
the build API existed, and the fixtures pin what they see.

An inventory of the plugins worth supporting (deriving code from declarations,
generating from external data, project rules, collecting declarations to
generate a registry) found that every one of them reads declarations, never
bodies. The plugins and fixtures of the tree read the kind of a declaration,
its name and spans, the fields of a struct and their types. A rule that reads
bodies, such as forbidding a call, needs to know which function a call names,
which neither tree says: the AST carries no types.

## Decision

- **A driver is handed the elaborated declarations, serialised.** What drivers
  read does not change, and no text is parsed again on their side.
- **Only their surface crosses, never a body**: names, spans, visibility,
  fields, signatures, types as written. Kotlin's KSP draws the same line.
  The codec is some 700 lines; the whole tree, bodies included, would take
  several times that, and a rule that needs bodies needs the typed view anyway.
- **It opens a little at a time.** The first cut carries what the fixtures
  read and what costs nothing more once types cross: every declaration but
  constants and build-time assertions, struct fields, function signatures,
  impl heads, imports, and every form a type is written in. A node read back
  holds nothing of what has not crossed yet.
- **The layout is the frames' own**: fields after their length, decimal
  integers, a tag per form, a flag before a value that may be absent. Every
  node carries a span, so spans name their file by an index into a table
  written once per frame.
- **The in-process path crosses too.** Until the driver leaves `vader`'s
  process, `messages()` encodes each event's frame and decodes it back, so a
  driver sees today exactly what it will see over a pipe.

## Consequences

The SPEC promises drivers the surface of each declaration and names what does
not cross. A plugin that needs a body, a constant's value or a decorator waits
for the surface to open that far.

The parser stays in `lib/toolchain` (0145): a driver no longer needs it to read
what it is sent, but plugins that generate code still build AST nodes, and the
tools share it.

Node ids do not cross, so the identity problem 0145 avoided by sending text is
still absent.
