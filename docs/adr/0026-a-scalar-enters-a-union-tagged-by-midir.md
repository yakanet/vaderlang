# 0026 — A scalar entering a union is tagged by midir

## Status

Accepted (2026-09-29).

## Context

A union value is a 16-byte box, a type tag beside the payload; `is u8` compares
the tag. The native backend wrote that tag from the value's storage class on the
bytecode stack, and the class does not name the type: the bytecode has no `u8`
constant, so `6 : u8`, a conversion `u8(n)` and an enum variant `.Blue` all
arrive as an `i32.const` or an `i32`-class result. Such a value entering
`u8 | string` was tagged `i32`, and `is u8` never held natively. The VM's tags
are coarse — an `I32Val` matches any integer of 32 bits or fewer — so it printed
the right answer and nothing noticed.

Two more gaps fed it. The typechecker left a free literal entering a union at
its `i32` default even when `i32` was not a member (`5` into `u8 | string`), and
the lowering then retyped the literal as the whole union, so the member type was
gone before midir.

## Decision

- A free literal entering a union takes the union's member of its family: the
  default (`i32`, `f64`, `char`) when present, else the only candidate; several
  candidates with no default is T3089 (SPEC §Default integer). A literal UFCS
  receiver follows the same rule.
- The lowering no longer retypes a value as the union it enters: the member type
  stays on the value, where midir can read it.
- midir tags the union value at every place a value is stored into a slot:
  a move into a local (which covers `let`, assignment and the join of a
  value-position `if` / `match`), the arguments of a direct, indirect and
  virtual call, a struct field, an array element, a cell. It compares the
  value's type with the slot's declared type and, when a scalar enters a union,
  emits `retag <type>` — the op formerly named `box`. It allocates nothing; the
  native backend writes the tag it names, and the VM drops it. `fold_moves`
  keeps such a move, so the producer cannot write the union slot directly.
  A return follows the same rule.
- Every primitive's `Equals` lowers to its class's comparison op (a `u8` to
  `I32Eq`), in a vtable wrapper as at a direct call. A union value carries its
  member's exact tag, so a set of `u8 | string` compares through `u8`'s impl —
  which, natively, had no binding: only `i32` and `i64` had an op.

The first version of this fix made each entry an explicit cast in the lowering,
site by site. Every lowering path that builds its nodes itself bypassed it — calls
through a namespace alias, virtual calls, value-position `if` / `match`,
`yield` — and each needed its own patch. midir is downstream of all of them.

A second alternative — constants and conversions carrying their exact width in
the bytecode (`u8.const`) — would have let the class name the type, at the cost
of a bytecode format change across the reader, the VM and every snapshot.

## Consequences

- Only a slot whose declared type is a union is tagged. An erased generic slot
  (`MutableMap<Color, i32>`'s `K`) keeps the class tag, as before: the shared
  instance dispatches its trait calls on the tag, so tagging there would change
  which impl it reaches. The union / erased distinction is read from the `Type`
  or the `BcType` row, since both have the `Any` value class.
- A virtual call's slots come from the method's declared parameter types, which
  the lowering records on the call (`param_types`). A synthesised virtual call
  states none — its parameters are erased — and its arguments keep the class tag.
- A generic instantiated on a union (`id<Byte>(u8(6))`) passes it through an
  erased slot, where the member keeps its class tag: `is u8` still misses there
  natively.
- The compiler itself was affected: the lexer stores `u64(0)` into a token value
  typed `i64 | u64 | f64 | u32 | string | null`, which the native compiler tagged
  `i64`, so its token dump printed `?` for an overflowing literal's value.
