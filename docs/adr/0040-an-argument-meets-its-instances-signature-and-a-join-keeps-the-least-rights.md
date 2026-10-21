# 0040 — An argument meets its instance's signature, and a join keeps the least rights

## Status

Accepted (2026-10-07). Closes the three leaks that 0039 left open, and the ones
found while closing them. The UFCS order remains, as a false refusal.

**Superseded by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: a type carries no rights any more.

## Context

0039 left three ways to write into `.rodata`. Each one passed `check`, and each
one wrote the const in the VM and was SIGBUS natively:

- **`pick<Cfg!>(local, CFG)`** with `pick :: fn<T>(a: T, b: T) -> T`. The written
  `Cfg!` binds `T`, and `CFG` came back mutable.
- **`local.pick(CFG)`.** UFCS binds `T` from the receiver alone, here `Cfg!`. It
  then checks the other arguments against the substituted signature, outside the
  generic path.
- **A join of `Box<Cfg>` and `Box<Cfg!>`**, from `if c { b1 } else { b2 }` or
  `[b1, b2]`, where `b1` holds `CFG`. The result was a `Box<Cfg!>`.

The first two share a cause. The shape check sets a struct, tuple or trait
argument's own top-level bit aside and leaves it to T3072. T3072 reads only the
parameter's marker, and `b: T` carries none. The tree already knew better:
`mk_fn_like` marks a parameter written as a bare `T` once `T` is bound to a type
granting mutation. That is how a `fn(T)` value bound to `Cfg!` is judged. But
the generic call asked the unsubstituted signature, and the UFCS curry rebuilt its
parameters one by one, without the relay.

The third is `collect_variant`. Two variants that are `equals_type` (a struct's
bit is not part of its type, at any level) collapsed into one. That variant kept
the less permissive top level, but the more permissive levels below it.

Reviewing the fix found more of the same families:

- **`b: T | null`** was not relayed, and neither was a `T` bound to `Cfg! | Other`,
  whose `Other` withholds mutation as a whole.
- **A join of fn types** kept its first arm, since `equals_type` ignores a fn's
  marks. `if c { read } else { write }` typed as `fn(Cfg)`, and calling it with
  `CFG` wrote the const.
- **A join of mutable containers** whose contents differ, `Cfg![]!` and
  `Cfg[]!`, kept a mutable container: a push through the join put `CFG` into the
  other array. Lowering only the contents made both orders leak.
- **`idt<Cfg>(CFG)`** bound `T` to `Cfg!`: an explicit type argument skipped the
  read-only default every written type takes.

## Decision

- **An argument meets the signature of the instance the call makes.**
  - The generic path hands T3072 the substituted callee (`substitute_fn_map`).
  - The UFCS curry substitutes the whole signature before it drops the receiver.
  - Either way, `mk_fn_like` marks a parameter written with a `T` at its top
    level, bare or as a union variant, once the call binds it in full to a type
    some variant of which grants mutation. A written `x: Cfg! | Other` is marked
    the same way.
  - The rule is the one a fn type already followed: `pick<Cfg!>` is a
    `fn(Cfg!, Cfg!) -> Cfg!`.
- **An argument filling one variant of a union is held to that variant.** `OTHER`
  passes to `x: Cfg! | Other`, a written parameter or a relayed one.
- **An explicit type argument takes the read-only default**, as any written type
  does.
- **T3072 names the class**: "this argument is immutable, but its parameter grants
  mutation". The detail says why: the parameter is declared `!`, or "`b` takes
  `Cfg!` : this call binds its type parameter to a type granting mutation".
- **A join keeps the least rights at every level.** `collect_variant` merges two
  equal variants with `least_permissive`, the helper 0039 introduced, now beside
  `union_of`.
  - A mutable container holds its contents at the rights written. Contents whose
    rights differ therefore leave the container read-only: `Cfg![]!` and `Cfg[]!`
    join to `Cfg[]`.
  - A fn type takes the bound with its parameters reversed. Its return and its
    `!` marks keep the least rights, so a mark either fn carries stays. Its
    parameters' types keep what either demands. A join of `fn(Cfg)` and
    `fn(Cfg!)` is a `fn(Cfg!)`.
  - Under that reversed bound, a mutable container whose contents differ fits
    neither side. The parameter becomes `never`, which no argument fills.
  - The same bound serves a type parameter bound by two arguments: two fn types,
    which 0039 left at their first binding, now share one, and
    `pick(make_mutable, get_const)` is accepted in either order.

## Consequences

Measured on 2026-10-07, at `cacc4f798`:

- **On 848 programs**, every diagnostic keeps its code and position. Nine T3072
  messages change wording. The typed AST is otherwise identical.
- **The compiler and `lib/`** needed no change. One snippet wrote `<Cell>` for a
  type parameter bound by `IndexSet<…>!`, and now says `<Cell!>`.
- **About 140 probes** pass `check` where they should and refuse every write into a
  const. Three programs refused before are now accepted: `idt<i32[]>(LIST)`,
  `poke(OTHER)` with `x: Cfg! | Other`, and `pick(make_mutable, get_const)`.
- **An array argument** to such a parameter reports T3001 and T3072, as it
  already did for a parameter declared `!` (`poke(LIST)` with `xs: i32[]!`).
- **Typecheck time** is unchanged (release builds, minima 509.9 against
  510.1 ms).

Still open:

- **The UFCS order.** `local.pick(CFG)` is now refused, while `CFG.pick(local)` is
  accepted and hands back a read-only `Cfg`. This is a false refusal, not a leak.
  Making it symmetric would route a generic UFCS call through the generic path:
  the receiver would enter the least-rights binding, and would then have to be
  judged against the final binding, or `rows.put(LIST)` would leak through
  `dst: T[]!`.
