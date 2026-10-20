# 0097: The CFG decides the integer a value is held in

## Status

Accepted (2026-10-20). Closes the work that declared the integers in `std/core`
(0091 to 0096). Amends 0086 on where a slot is read, and 0096 on how a narrowed
read is converted.

## Context

Once an integer type was a set of values (0092, 0095), the integer a value is
stored in was still chosen in four places: the typecheck noted the slot a value
filled (`integer_slots`), the lowering picked the width of an operation
(`integer_width.vader`) and of a checked conversion (`cast_to_width`, by name), an
enum carried its width as a string, and a narrowed read was converted where it was
read. Each place reached the same answer from its own copy of the rule, and a value
of type `Hour` could leave the lowering typed as a `u8`.

## Decision

- **The typecheck reads values only**: an index, an equality, an overload
  ranking and the comptime bridge read bounds, never a stored width.
- **A lowered value of type `R` lies in `R`**: the lowering types a node by
  what the typecheck says it is, a conversion included (`Hour(x)` is an `Hour`, a
  variant literal is its enum, not their integers).
- **The CFG build decides storage** (`vader/midir/storage.vader`), as it turns the
  lowered tree into locals that have one:
  - where a value fills a slot (a local, a field, an element, a parameter, a
    result, a cell, a global, a slice's bounds), it is converted to the slot's
    integer, a literal built there instead;
  - an operation is computed in an integer holding its operands and its result;
  - a narrowed read is taken as it is stored and converted once, to where it goes
    (an index, and a conversion to anything but an integer, still convert it where
    it is read); a test of a narrowed local against a constant compares in the
    integer the local is stored in;
  - a checked conversion holds the value as the range of the values it can take,
    and compares it there against the target's bounds.
- **An enum's width is a `MachineInteger`**, decided once with its declaration: it
  is part of the enum (a written width is what crosses C), not of a value.
- **`--verify` holds it** (I7013): every value goes into a slot that holds it in its
  own integer, an operation's operands and integer result share one, and no local
  keeps a free type.
- **The bytecode's type table names storage**: its scalar entry is `BcScalar`
  (`type 1 scalar i32`), since no integer is a primitive of the language anymore.

## Rejected

- **A separate MIDIR pass** to insert the conversions: it would infer again, per
  instruction kind, the slot the build already knows, and renumber every local.
- **Eliding every conversion between two types held in one integer**: it changed
  1 362 lines of the compiler's C, nearly all a distinct unwrapped (`i32(id)`),
  whose type the local must keep.
- **Folding conversion chains by intervals, and computing at the consumer's
  width**: the compiler has 235 chains, nearly all unions and distincts unwrapped,
  which are real conversions; the benchmarks 2; and `cc` folds the rest natively.
  Only the three cases that code with ranges pays for were kept, measured on the
  VM.

## Consequences

- The compiler's emitted C stayed identical through these steps, up to local
  numbering, but for five literals built wider, one constant expression and one
  copy.
- On the VM, a loop summing and matching a narrowed `Hour` ran in 0.78 s instead of
  1.23 s (one machine, 2026-10-20); natively nothing moved. The `hours_tally`
  snippet's bytecode pins the three forms.
- A narrowed index is still converted to its range where it is read: the converted
  local carries the interval that proves the access in bounds.
- A comptime `@min(E)` of an enum is still named by its integer's spelling, the
  comptime value vocabulary naming types by string; the enum and its integer share
  one type-table entry, so nothing differs.
- A `RangeType` finds the integer it is stored in by scanning the eight machine
  integers each time; keeping it on the type would save that, at the cost of one
  more field to carry.
