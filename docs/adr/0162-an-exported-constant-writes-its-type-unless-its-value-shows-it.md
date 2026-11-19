# 0162: An exported constant writes its type, unless its value shows it

## Status

Accepted (2026-11-19). Extends ADR 0161 from functions to constants.

## Context

ADR 0161 made an exported function write its return type, so that no module reads
a return another module infers. Constants were left out, and another module still
read the inferred type of one: the passes that settled returns typed every
constant of the imported modules before anyone read them, in the order of the
modules. Removing those passes left such a read with no type.

## Decision

- **An exported constant writes its type**: other modules read it from the
  declarations alone, before any value is typed. One that leaves it out is an
  error, which names the type to write.
- **Unless its value shows it**: a string, a character, a boolean, a struct literal,
  or a conversion `T(x)` to a scalar, an enum or a distinct type. Its type is read
  from the declaration, before any value is typed. A number does not count: a free
  literal takes the type its context asks for, which the reader of a contract
  should not have to guess.
- Private constants keep their inference.

Rejected:

- typing the constants of every module first, in the order of the imports: it
  keeps an order between modules and a phase of its own, for a type the
  declaration can carry;
- requiring the type on every exported constant: `export TY_VOID: PrimitiveType:
  PrimitiveType { ... }` says the type twice.

## Consequences

- The interface of a module is known from its declarations: typing a module needs
  no walk of another.
- About forty constants of the tree write their type, most of them names of core types
  read with `@type_name`, which a value does not show.
