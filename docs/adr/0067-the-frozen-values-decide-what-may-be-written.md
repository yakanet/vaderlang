# 0067 — The frozen values decide what may be written

## Status

Accepted (2026-10-16). Carries out the switch of 0053, over the summary of 0059 and
the chains of 0066. The markers still written in the tree are removed next, once
the seed is cut from this compiler.

## Context

Until now the typecheck enforced the rights of every written type, in two rounds
that deduced the `!` of parameters and annotated locals (0051, 0052), while the
effect summary (0059) observed the frozen values beside it. Both refused the same
writes into a constant, at two different positions; only the rights refused a write
through an ordinary parameter, which 0053 stops checking.

Two questions were left for the switch, decided on 2026-10-15:

- A view of a string's bytes cannot be copied behind the program's back: `bytes()`
  exists so that no copy is made. A constant bound to a name is copied (0053), a
  view cannot be.
- The data of an enum's variants is a table every read of the variant shares, as a
  constant's value is. The rights kept it read-only; nothing in the summary did.

Two more surfaced on 2026-10-16, once the rights were gone, each a write the rights
had refused that now lands in `.rodata` natively (`SIGBUS`), and in the table every
read shares on the VM: a field of a variant's data (`Info(v).code = 5`), and a field
of a first element of a marked module constant (`SPECS[0].code = 9`).

## Decision

- **The rights no longer decide.** One typecheck round. A `!` written is accepted and
  grants nothing. It is not warned about yet: the seed enforces the rights on the
  tree it compiles until it is cut from this compiler, and the warning (W0017 and
  W0018 as one) comes back with the removal of the markers. A `!` on a type with no
  interior (T3075) and the marked module constant (T3076) are still checked.
- **The faults are the errors**, reported after the summary by `vader/pipeline/check`,
  which every client goes through: T3070 for a frozen value written through, T3072
  for one lent to a callee that modifies it. The detail names the value, what
  modifies it down the calls it is lent through, and the way out, `.clone()`.
- **A view is never copied.** What holds one may read it, lend it to a reader, and
  return it. Written, or lent to a callee that modifies it, it is T3070 or T3072.
  Kept (in a field, an element, by code the summary cannot see) it is T3071, and so
  in a module constant's value: a fresh read of the constant would run its
  initialiser again, a new view. Only the view itself counts: a byte read out of it
  is a value.
- **A function that returns a view hands views out**, as `bytes()` does. Once the
  facts are settled, the bodies that call one are walked again with those calls as
  views, until no new function returns one. A view adds a root and no constraint on
  a parameter, so the settled facts stay as they are.
- **A read narrowed to a type no byte array is, is a step below the name**, and so
  is the name an `is T as t` binds. The summary ignores `is` tests: without the
  step, `if r is Trap { out.push(r) }`, with `r` of type `u8[] | Trap`, would keep
  the view `r` may hold, and returning the trap would make its function a view
  source. What lies below the step is no part of a view; for a constant, a write
  below it is a write all the same.
- **An enum's variant data holds only values**: scalars, strings, enums (T3096).
- **The data of a variant is frozen as a constant is.** `Info(v)` is a use of it:
  written through, T3070; lent to a callee that modifies it, T3072; bound to a name,
  kept or returned, a copy, field by field (the data holds only values), left out
  where nothing writes a value of its type. A type parameter converted to a struct
  some enum keeps its data in is such a use too, since it may stand for the enum. A
  field of an enum value is a field of the data: `v.code = 5` is T3070 at the
  typecheck.
- **A marked module constant whose elements hold a part a write reaches** (a struct
  or an array, alone or inside a tuple, a union or a distinct) **starts empty**
  (T3076), whatever else its initialiser could be: a literal or a value folded at
  build time lies in read-only data. The program pushes its elements, which are
  then its own. The tree's six marked constants already do, and `@singleton`
  replaces the form. A module variable is no frozen value: what its initialiser
  keeps is copied, or refused for a view, as anywhere a value is kept.
- **A write into a copy nothing reads is W0019** (2026-10-16), at the write: a name
  bound to a constant or to variant data, written, and never read nor kept in its
  body. The walk notes the names a body reads, a name a write lands below
  (`c.n = 0`, `c.n += 1`) being no read. A name that may hold anything else is
  never warned about, since the write may land there: a parameter, or a name bound
  to a slot outside those that hold only frozen values (a use, a step below one, a
  join of them; a branch that holds no slot may be a fresh value). The check asks
  no order: a read anywhere in the body silences it (`c.n = c.n + 1` does). Only a
  write the body makes itself is reported: a copy lent to a callee that writes it
  counts as read, and a write through a user `IndexSet` is a call.
- T3042, T3073, T3074 and T3077 are retired; T3071 is reused for a kept view.
- The way out the detail offers is a copy: a name bound to a constant or to variant
  data holds one, `.clone()` copies a view.

## Consequences

- `vader check` of the compiler: 2.23 s before, 1.46 s after (2026-10-16, M-series,
  three runs each, `--release` builds).
- About 3 300 lines of the rights machinery leave `vader/` (the deduction, its fix
  hints, the borrow tables of the resolver, the deduced `!` of the LSP).
- A fixture of the rights is gone with its check; one that caught a write into a
  constant now catches it as a fault. A `for` over an `if` joining an array field
  and a literal, refused by T3074, compiles.
- Not followed: a view reached through a function value (`f :: bytes_of`, then
  `f(s)[0] = 1`). The call runs code the summary does not name, so its result is no
  view.
- The read-only bit stays in the type IR until the markers are removed, and a type
  printed in a dump or a detail may still show `!`.
