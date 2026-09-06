# 0017 — The read-only default had a second rule that contradicted it

## Status

Accepted (2026-09-06).

## Context

The `!` marker is a per-level property of a **type** (SPEC §"Read-only by default").
The compiler decided "may this be mutated?" two different ways, and they did not
agree.

- A **write** asked the container's TYPE, level by level. `container_is_immutable`.
- An **argument** or a `self!` **receiver** walked the ACCESS PATH back to its root
  and stopped there, never looking at the types crossed on the way.
  `expr_is_immutable`.

Two answers for one expression:

```vader
fn(xs: Box![]) { xs[0].n = 1 }    // passes  — the element type says mutable
fn(xs: Box![]) { bump(xs[0]) }    // T3072   — the path says `xs` is a borrow
```

SPEC §"The marker is per LEVEL" had already ruled on this, in as many words: *"A
root-based check would get two of them wrong in opposite directions: `Cfg![]`
over-strictly … and `Cfg[]!` over-permissively."* The path check was the
root-based one the spec warns against. `Cfg![]` — a row of the spec's own table —
was unusable for anything but a direct field write.

The entry point was elsewhere. `if w is Wrap as x { bump(x.b) }` compiled where
the alias-free `if w is Wrap { bump(w.b) }` was correctly T3072: the narrowing
binding was treated as an owned local rather than a borrow of its scrutinee, so
the path walk started at `x` and found a mutable root. SPEC §"An `is` test
compares the shape" says the opposite — *"what the narrowed binding carries is the
scrutinee's own mutability"*.

## What was measured

Closing the alias hole made the compiler's own tree fail to build, in eight
places. All eight were the second rule biting: `for decl in decls { …
check_const_value(decl, …) }`, where the loop variable was stamped read-only
whatever its element type said. `orchestrate.vader` carried a comment saying so —
*"The alias is load-bearing here, not decoration … Until a mutable loop variable
is expressible, this is the only way to say it."* The hole was being used as a
feature, because the honest form could not be written.

Three further defects surfaced while measuring, each verified against `HEAD`
before the change, each independent of it:

1. **A read-only element could be widened to a mutable one.** `equals_type`
   deliberately keeps a struct's read-only bit out of type identity (so caches,
   union dedup and monomorphisation keys stay stable), which makes `Box[]` and
   `Box![]` *one type*. `is_assignable` short-circuits on equality, so it never
   reached the array rule. Two guards already ran ahead of that short-circuit —
   fn parameters, and struct/tuple at their OWN level — but the bit is outside
   identity at EVERY level, so a guard built one shape at a time can never catch
   up. `struct_mutability_widens` became `mutability_widens`, a lockstep walk over
   the positions `strip_mutability` enumerates: array element, tuple element,
   nominal type argument, union variant. End to end: `lender(xs: Box[]) {
   mutate(xs) }` where `mutate(xs: Box![]) { xs[0].n = 999 }` printed 999, and so
   did its tuple, `Holder<Box>` and `Box | null` siblings — at a SLOT. At a call
   ARGUMENT the nominal position is still open; see below.

2. **`| null` reopened every level below the top.** `apply_readonly_default`'s
   union branch set each variant's own bit and never descended into its children,
   where every other branch calls `readonly_children`. So `Box[] | null` meant
   `Box![] | null`, and `xs[0].n = 999` went through. SPEC says the default is
   recursive; the implementation was not, inside a union.

3. **A written fn type skipped the default entirely.** `readonly_children`
   descended into an array element and a tuple element, never into a fn type's
   params or return — so `fn(f: fn() -> Cfg)` handed out a MUTABLE `Cfg` where the
   same `-> Cfg` on an ordinary declaration is frozen. Same family as (2), one
   shape over. Fixing it moved two snippets in the right direction: `flat_map`
   declares `f: fn(T) -> U[]` and its type now prints `U[]`, not the `U[]!` the
   compiler used to invent. No `vm`, `bytecode` or `c` snapshot moved.

4. **The advice named the wrong lever.** `annotate `xs!`` on a `xs: Box[]`
   produces `Box[]!` — the spine — which does not move the diagnostic. The reader
   loops. Same for `annotate `x!`` on a loop variable, which is not syntax.

## Decision

The type decides, in the PERMISSIVE direction: the path walk stops at the first
level whose type carries `!`, the loop variable takes the same answer asked of
the element, and the `is T as x` binding inherits its scrutinee's.

**Only the permissive direction, and that is a real limit.** The path walk reads
the type to grant rights, never to withhold them, so the two rules still disagree
the other way round — and the opening example reproduces with the sides swapped:

```vader
Wrap :: struct { b: Box }              // the field takes the read-only default
w :: Wrap { .b = Box { .n = 1 } }      // an inferred local : owned, mutable
w.b.n = 999      // T3070   — the TYPE says the field is read-only
w.b.bump()       // passes  — the PATH walks past it to an owned root
```

Closing it is one line (`if type_is_immutable(ty) { return true }` in
`walk_levels`) and **584 sites in the tree**, measured. That is its own change,
not a rider on this one. Until it lands, "one rule" is true of the argument and
receiver gates reading a `!`, and not of them reading its absence.

The **storageless module const keeps priority** over all of it, and that is the
one place a path still decides: an unannotated struct const takes its type from a
fresh literal, which is mutable, so the type lies — only the path knows the write
would land on a value `inline_consts` rebuilds at every read.

The **generic parameter is exempted** from the element check. `unify_type_param`
erases mutability when it binds `T`, on purpose — keeping it would fork every
generic instantiated from both a borrow and a local — so a substituted `T[]`
claims mutable elements whatever the argument said. Judging that fiction rejects
the very argument that produced the binding. The exemption costs nothing: inside
a generic body the element is a `T`, which grants no mutation, so the callee
cannot write through a claim it never made.

## Consequences

The compiler tree needed **declarations widened** — 25 in the first round, ~35 more
once the union arm landed, across parser, resolver, lower, vm and `lib/toolchain`.
The second wave is worth understanding, because its size was mis-predicted at "30,
all in the lowerer": the union arm did not create a new rule, it made **per-variant
`!` markers that AST and IR fields already carried**, dormant because nothing
compared them, into a tree-wide constraint. All of one shape —
`X[]!` → `X![]!` on a local, a return, or a chain of them. Every one was
an under-declaration: the code already mutated those elements. Three signatures
took a plain `!` (`walk_bodies`, `walk_fn_body`, `check_defer`). Not one existing
snapshot moved.

Two of those widenings are not honest, and are marked as such:
`dump_typed_program` and `dump_program_with_others` take `typed: TypedProgram!`
though neither mutates anything. The marker is there to satisfy the COMMITTED
SEED's generic check, which demands mutable elements where the new rule does not.
It comes off at the next reseed.

Two constraints shaped the fixes and are worth remembering:

- **The tree must satisfy the old seed too.** `bootstrap/build.sh` builds stage0
  from the committed seed, and stage0 compiles the tree — so a commit may change
  the rules but may not yet *depend* on them. `dump.vader` is where the two met:
  the new rule wanted `sections: TypedProgram[]!`, the seed's generic check
  demanded mutable elements. Widening the `others` chain satisfied both, and it
  was the honest declaration anyway (`per_module` holds `TypedProgram!`).

- **A `!` inside a type argument is how a generic hands out mutable elements.**
  `CommaList<CallArg!>` — the tree already had one at
  `parse_import_name_list_rest`. Nothing else can express it, since the read-only
  default deliberately does not descend into a nominal argument.

### Left open, with numbers

- **The restrictive direction**, above: 584 sites.
- **At a call ARGUMENT, a nominal type argument is still erased.**
  `arg_mutability_cleared` clears the bit inside `Holder<Box>` on the argument path
  deliberately — T3072 owns the top level there, and clearing was how the two
  stopped double-reporting. So `gen_mut(h)` widens where `a: Holder<Box!> = h` is
  T3077, and `h.v.n = 999` writes through. The erasure predates this change and
  interacts with `apply_readonly_default` stopping at nominal boundaries; it wants
  its own look, not a wider clear.
- **`unify_type_param` canonicalises to the MAXIMAL rights**
  (`with_immutable(arg, false)`), which is the unsound direction, and
  `substituted_element_fiction` exists to undo it at every gate that judges a
  substituted parameter. Normalising to read-only instead was MEASURED, and it is
  not free: the tree stays at the same site count, and `filled(3, () -> [])` stops
  handing back mutable rows — a factory's product silently loses its rights. Both
  directions are wrong because erasing at all is; keeping the bit without forking
  every generic is the real question, and it is a large one.
- **A module const's inferred type is the one type source that never passes
  through `apply_readonly_default`**, which is why `rooted_in_storageless_const`
  has to exist and is consulted at three sites. Freezing it at `declare_const`
  collapses all three, but `decl_types` feeds `inline_consts` and lowering, and
  array identity does carry the bit — snapshots would move.
- **`mutation_fix_hint` still names the root** for a write through a field of an
  indexed element (two hops); the level-name advice covers one.
- **`any_widens` pairs tuple elements on ARITY alone**, where the struct and trait
  arms guard on `symbol.id`. Union variants reach it already sorted, so today the
  pairing is exact — but `strip_distinct` rebuilds a union with bare `mk_union`
  after changing display keys, and that result is unsorted. No path feeds it to
  `is_assignable` yet. Guarding each pair with `equals_type` closes it whenever it
  matters: the predicate ignores precisely the bit under test.
