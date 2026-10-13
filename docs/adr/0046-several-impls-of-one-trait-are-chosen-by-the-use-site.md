# 0046 — Several impls of one trait are chosen by the use site

## Status

Accepted (2026-10-08). Amends 0042.

**Superseded in part by [0056](0056-the-typecheck-records-what-each-call-site-invokes.md) (2026-10-13)**: the choice is the callee the
call-site record names at the use site, which the lowering calls ; the per-node
tables below (`picked_impl_members`, `picked_index_writes`,
`bounded_dispatch_args`) are gone, and so is the lookup by name.

## Context

A receiver may implement one trait several times at different arguments:
`Vec2 implements Mul<f64>` beside `Mul<Vec2>`, `Mon implements Into<Label>` beside
`Into<Tag>`. The SPEC's operator rule already spoke of "the matching impl" whose
`Rhs` takes the right operand. Nothing chose it.

- The typechecker's tables held one member per receiver and name. The impl
  declared last won, so `v * 2.0` with both `Mul` impls was T3017, and so was
  `v.mul(2.0)`.
- The lowering resolved members by name and took the impl registered first. A
  method call, a trait value and a `for` could run the other impl's body,
  silently.
- Three mangle builders disagreed:
  - Two generic impls of one trait on one base (`Pile<T> implements<T> Add<f64>`
    beside `Add<Pile<T>>`) both named their member `…$add__Any`.
  - A call site did not add the `_1` the materialiser gave a plain type's second
    impl.
  - A default method cloned into two impls took one name, because the counter
    found members by the name span the clones share.
- Implicit conversions already chose by their target (0045).

Also found on the way: `v * 2.0` never reached an impl, even a single one. A
struct operand beside a numeric one took the built-in numeric path.

## Decision

**The use site chooses, the typechecker records the choice, the lowering calls
it.**

- **What each site chooses by:**
  - an operator, by its right operand;
  - a method call, by its first argument, or, for a member without one, by the
    shape of the result its slot expects (`t: Tag: m.into()`);
  - `x in c`, by the element;
  - `c[k]` and `c[k] = v`, by the key, each against its own trait's keys;
  - `[a, b] :: r`, by the arity of the tuple an `Into<[…]>` builds;
  - a static member, by its argument;
  - a call, a static member or an operator on a bounded `T`, by the bound's
    arguments, in each concrete instance;
  - inside one of the impls, a member reached on its own type is its own: a
    default method's `self.tag()` calls the `tag` of the impl it was cloned into.
- **The ranking** is the free-function overloads' (`overload_rank`).
- **Ambiguity:**
  - a tie, a member without an argument whose result is untyped, or a member
    taken as a value, is T3032;
  - a use that reaches the trait without its arguments, a `for` or a trait value,
    is the new T3097: a trait value dispatches by the trait alone. A `for` over a
    struct converting into two `Iterator`s is T3097 too, unless it is an
    `Iterator` itself: its own `next` then gives the element, as it gives the
    loop.

**Every impl keeps its entry.** `impl_methods` maps a receiver and a member name to
a list. The type of the table makes every reader face the several impls. Each
member carries its trait, the trait's arguments and its impl
(`ImplMethod.trait_key`, `trait_args`, `impl_key`). `struct_trait_args` keeps one
argument list per impl in the same way. A reader that binds a type parameter from
it gets the list only when it is alone.

**The choices are recorded per node.**

- `picked_impl_members` holds the call, the operator, `in` and the index read.
- `picked_index_writes` holds the index write, because `m[k] += v` reads and
  writes through one node.
- `bounded_dispatch_args` holds the bound's arguments.
- The lowering reads these before falling back to a lookup by name, which a
  single impl still takes.

**An impl hides only its own trait instance.** This amends 0042's per-trait rule.
An impl on one instance masks the generic impls of the same trait at arguments
that can coincide with its own, and leaves the others, in the typechecker
(`impl_candidates`) and in the lowering (`covering_first`,
`impl_applies_to_instance`). `MonType[] implements Into<Label>` no longer hides
`T[] implements<T> Into<Iterator<T>!>`, so an explicit `xs.into()` reaches either,
as the implicit conversion does.

**One numbering names every impl's members.** The registry numbers the impls of
one trait on one base declared in one module as it collects them
(`ImplEntry.overload_suffix`, `$1`, `$2`, …). The call sites and all three
materialisers append it, generic impls and cloned defaults included. The first
impl keeps its old name.

**A generic instance keeps concrete a type two impls of one trait cover.** An
instance erased to `Any` dispatches by the trait alone, so a generic impl's member
calling `self.inner * 2.0` under `T: Mul<f64>` would reach whichever `Mul` the
vtable lists first. `is_specialized_arg` keeps such a type, as it keeps one an
impl on one instance names, so the instance's bounded calls choose by the bound's
arguments.

**The left operand dispatches.** A struct operand beside a numeric one reaches its
impls.

## Consequences

Measured on 2026-10-08, at `112a612c1`:

- **The tree and `lib/` declare no trait twice on one receiver**, so their code is
  unchanged. Lowering a program got faster: the lookups without a trait read a
  per-base index instead of every impl of the project.
- **A trait value of a type with an instance impl beside a generic impl of the same
  trait at other arguments is now T3097.** `Wrap<Mon> implements Conv<string>`
  used to hide `Wrap<T> implements<T> Conv<T>` entirely, so `c: Conv<string>: w`
  was accepted; `Wrap<Mon>` now implements `Conv` twice.
- **The key of a write through a type with no `IndexSet` of its own** (an
  array-backed distinct implementing `Index` only) is the backing array's integer,
  no longer the `Index` key.
- **Snippets with a second impl of a trait on one base change name** (`$1`), with
  the same output. One snippet changed name for a different reason:
  `trait_method_ambig` keeps its single T3032.
- **New coverage:** snippet `several_impls_of_one_trait` (native parity) covers
  every use site above. Two fixtures cover T3097.

Not done, and refused rather than miscompiled:

- **A trait value or a `for` over a trait implemented twice** (T3097). Choosing
  among the impls would need a vtable per trait instance.
- **An erased instance of a bounded generic.** It dispatches virtually by the
  trait alone, so it cannot tell two impls apart either. A bounded call keeps its
  instances concrete (`keep_instances_concrete`), which is what makes the
  per-instance choice above hold.

Still open, as before this change:

- **The result of an operator on a generic impl keeps the impl's own parameter**
  (`p + q` on `Pile<i32>` is typed `Pile<T>`). The method form is substituted.
- **An explicit `xs.into()` on an owned array** returns `Iterator<Mon!>!`, which
  does not fill an `Iterator<Mon>!` slot.
- **`m[k] += v` through a bounded `T`** records one trait for its read and its
  write.
