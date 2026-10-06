# 0033 — Rights hold through a distinct and a nominal argument

## Status

Accepted (2026-10-07). Resolves the nominal-argument item that 0017 and 0032 left
open, and the first item of 0022's "Left open" with 0032.

## Context

After 0032 the read-only bit still leaked at three nominal boundaries.

- **A distinct type carried no bit.** `with_immutable` left it alone, so
  `Color(ORIGIN)` — a conversion of a module const — was a mutable `Color`, and
  `c.r = 5` wrote into `.rodata`; `Ids(TABLE)` the same through an index. Its
  backing's children never took the read-only default either, so `Grid :: Cfg[]`
  held mutable `Cfg`s. And an index write into an array-backed distinct was not
  checked at all, neither for rights nor for the element type:
  `t[0] = "x"` into an `Ids :: i32[]` compiled.
- **A struct's type arguments compared one way.** `Box<Cfg!>` filled a
  `Box<Cfg>!` slot, whose holder may store a read-only `Cfg` that the owner then
  writes through. At a call argument, `arg_mutability_cleared` cleared the bits
  inside the argument, so even that one direction was skipped.
- **A trait's arguments were taken raw.** An impl clause stored its arguments
  without the default (`Sink<Cfg>` read as `Sink<Cfg!>`) and compared them in one
  direction. The member signature check (T3095) also skipped every position the
  trait wrote as `T` or `Self`. So `Holder implements Sink<Cfg>` could take
  `v: Cfg!` and store a module const.

`check` accepted 22 reproductions of these. In native builds, 21 died of SIGBUS
writing into `.rodata`, and one stored a string into an `i32` array.

## Decision

- **A distinct's bit is its backing's.**
  - `type_is_immutable`, `type_grants_mutation` and `carries_mutability_bit`
    answer through the backing.
  - `with_immutable` rebuilds the distinct over a re-marked backing.
  - Display shows `Name!`.
  - Below its own level the backing takes the default a written slot's children
    take (`alias_for`), so `Grid :: Cfg[]` holds read-only `Cfg`s.
  - An index write into an array-backed distinct is checked against the backing,
    unless the distinct implements `IndexSet` itself, whose value type then holds
    it. That is the order in which the lowering dispatches.
- **Through a mutable struct its type arguments are invariant**, as an array's
  element is through a mutable array. `mutability_widens` compares them both ways
  under `strict`, and a call argument no longer clears them. A UFCS receiver is the
  call's first argument: the function is picked by shape, then the receiver is held
  to the first parameter's rights below its own level, the top level staying
  T3071's.
- **A trait's arguments are always invariant.** A trait value has no bit of its
  own, and its methods may store what they receive. A trait value, an impl
  (`implements_trait_instance`) and a bound (`bound_widens_into`) all compare
  arguments with `trait_args_match`.
- **An impl clause's arguments take the read-only default**, through the helper a
  generic instance's arguments go through (`written_type_args`).
- **`Self` is substituted before the read-only default**, since a `SelfType`
  carries no marker of its own: the marker written on it decides, so `Self` is the
  impl's type read-only and `Self!` the mutable one (`self_slot_type`). That holds
  for the trait's signature as T3095 reads it, and for an impl member's parameters
  and return. The default of an argument the impl leaves out (`Out = Self`) is the
  impl's type read-only. With these rules T3095 compares every position, and its
  mask for positions written `T` or `Self` (`borrows_its_rights`) is gone.

## Consequences

Measured on 2026-10-07:

- **The compiler tree** needed:
  - five `BigInt!` accumulators in `std/core/bigint`;
  - `JoinAll<T> implements Async<T[]!>`, with `resume` returning
    `T[]! | Suspended`, since the join hands its awaiter a results array the
    awaiter owns.

  Nothing else, removing the mask included.
- **On 825 programs**, `check` disagrees with HEAD's on four:
  - three fixtures whose T3001 detail is reworded;
  - the conversion fixture, which now also reports T3077 for the distinct's
    spine, as a plain array argument does.
- **Snapshots:** 13 `typecheck` or `lower` snapshots moved, across seven
  snippets. Every changed line is identical except for its `!` markers: a
  distinct now shows its rights, and an impl's written `-> Self` is read-only
  (`trait_static_member`). `histogram_newtype` also marks its three accumulators
  in its source, so its `lexer` and `parser` snapshots follow. No `vm`, `bytecode`
  or C snapshot moved.
- **The reproductions** are refused, with T3001, T3042, T3063, T3070, T3072,
  T3077 or T3095 as each case calls for: the 22 above, and four that a second
  review found in the first version of this change — a `-> Self!` the impl did
  not keep, a UFCS receiver, and a distinct with its own `IndexSet` (rights and
  value type).
- `fn(self) -> Self = self` in an impl, refused before (T3077: the written return
  took the raw rights of the impl's type), is accepted.

Still open:

- **`Grid :: Cfg![]` does not parse** (P1006): a type alias cannot start with a
  marked name. So an array-backed distinct cannot hold mutable struct elements.
  Nothing in the tree wants one.
- **A read-only array argument into a mutable array parameter reports twice**
  (T3001 and T3072), as before; a distinct over an array does the same.
- **An index READ ignores a distinct's own `Index`.** A distinct over an array
  reads its backing even when it implements `Index` (at runtime too), and a
  struct-backed one with an `Index` is T3008. Reads and writes should share one
  dispatch decision, recorded once and used by both lowerings.
- **A UFCS receiver whose trait first parameter wants other rights** is refused
  as T3009 ("field does not exist"): dispatch through a trait still compares
  rights, where `f(h)` says T3001.
- **A field declared `!` reached through a read-only root** stays writable
  (`w.items.push(3)` with `w: Holder`, `items: i32[]!`), through a distinct as
  through the struct itself — the transitive read-only question, open at HEAD
  too.
