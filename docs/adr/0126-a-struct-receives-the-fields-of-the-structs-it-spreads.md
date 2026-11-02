# 0126: A struct receives the fields of the structs it spreads

## Status

Accepted (2026-11-02).

## Context

Number formatting wants several option structs that share a core: a sign mode,
a separator, a width. Writing the core in each struct repeats its fields, their
defaults and their docs, and they drift apart. Vader has no inheritance and no
subtyping of structs, and does not want either: a struct is a nominal type, and
a trait is the way to accept several of them.

TypeScript composes object types with `&` and spreads values with `...`; Go
embeds a struct, which also promotes its methods and lets the outer value stand
for the inner one; Rust has neither and repeats the fields or nests a struct.

## Decision

`...Base` in a struct declaration copies the fields of `Base` into the struct,
at the place of the spread. It is composition only: the struct is a new nominal
type, a `Base` is not one, and no conversion goes either way.

- A received field keeps its type, its default, its doc and its visibility.
- A field the struct declares under a received name redeclares it: same type,
  same place, its own default and doc. This is how an option struct changes a
  default of its core. Another type is an error, since a reader who knows the
  base would read the field wrong.
- Two spreads giving one field are an error, unless the struct redeclares it:
  neither order can be the obvious winner.
- The scope is complete from the start: a base of another module, a generic
  base (`...Box<T>`), a base that spreads in turn. A cycle is an error.
- A base with an `@internal` field spreads only in its own module: elsewhere,
  the struct would hold a field its own module cannot touch.

The compiler keeps the AST as written: `StructDecl.fields` holds the written
fields, `StructDecl.spreads` the spreads with their place. The typecheck owns a
field table, `TypedProgram.struct_fields`, which every pass after the
declarations reads. Each module fills it with the fields its structs write;
once every module is declared, one project pass adds the received ones, base
first. A received field records the struct that writes it (`owner`), with the
arguments the receiving struct gives that struct, and its type is rewritten in
the receiving struct's parameters. A default is lowered in its owner's module,
the owner's parameters bound.

Copying the base's fields into the AST was set aside. A copy carries node ids,
which are project-wide (0114), spans that belong to another module's parse, and
a default that must be lowered in that other module: every pass that forgot the
origin would be wrong without a sign.

## Consequences

A pass that reads the fields of a struct reads the table, never
`StructDecl.fields`, which only the declaration, the formatter and the editor
tools read as text.

A value of a struct the struct spreads, directly or through its bases, fills a
literal of the struct (`IntFormat { ...common, .base = 16 }` with
`common: BaseFormat`): it gives the fields of its own struct, the literal or the
defaults the others. With several spreads, a field the literal does not name
comes from the last source that holds it, as the last spread already won when
every source had the literal's type. The other way, a value of the struct in a
literal of its base, stays an error: it would let the struct stand for its base.
