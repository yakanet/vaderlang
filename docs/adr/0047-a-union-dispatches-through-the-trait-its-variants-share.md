# 0047 — A union dispatches through the trait its variants share

## Status

Accepted (2026-10-08). Closes the two items 0043 left open.

**Superseded in part by [0056](0056-the-typecheck-records-what-each-call-site-invokes.md) (2026-10-13)**: the use site records the
trait's member in the call-site record (`TraitMember`), no longer through
`record_bounded_dispatch`.

## Context

The SPEC says "a union satisfies a trait iff all its members satisfy it". Passing
a union to a `fn(x: Shape)` worked. Calling a member on the union itself did not:

- `u.area()` on `u: Sq | Circle`, both `implements Shape`, was T3008;
- so were `target.set_at("k", 1)` and `target["j"] = 2` on
  `MutableMap<string, i32>! | Log!`;
- `k in u` on a union of `Contains` implementors was T3043.

A value of the trait had a related gap. `c.contains(k)` with
`c: Contains<string>` passed, `k in c` was T3043, and `a + 5` with
`a: Add<i32>` was T3017. The operator path dispatched through a bounded `T` only.

At run time, a union and a trait value are the same thing: a tagged box. Widening
one to the other builds nothing. An interpolated union already rendered through
a virtual `Display.to_string` call on the union box.

## Decision

**A union calls a trait's members through the trait, by the value's tag, as a
value of the trait does.** The typecheck finds the trait declaring the member
that every variant implements, records the dispatch on the use site
(`record_bounded_dispatch`) and types the member with `Self` standing for the
union. The lowering emits a virtual call. It covers a method call, an index read
and write, `in` and the arithmetic operators. A value of the trait reaches `in`
and the operators the same way. Considered and rejected:

- an explicit widening of the receiver to the trait before the call: the same
  dispatch, with one more table and noisier trees;
- a static `is` chain over the variants: inlinable, but it cannot tell an enum
  from its integer or two instances of an erased generic (T3087), and it has to
  join the results of a `Self`-returning member.

**The variants agree on the trait's arguments, one argument at a time**
(`union_trait_instance`). Each argument is either one type for every variant, or
each variant itself, which the union reads as `Self`. `i32 implements Add` is
`Add<i32, i32>` and `Money implements Add<i32>` is `Add<i32, Money>`. They agree
on `Add<i32, Self>`, so `a + 5` on `a: i32 | Money` is an `i32 | Money`.

**`Self` reads as the receiver, read-only.** A member returning `Self` hands back
`A | B` on `u: A! | B!`, read-only unless the member writes `Self!`, as on a
concrete receiver. Taking the union's `!` would let `u.peek().v = 99` write into
a constant.

**A dispatch by the tag alone cannot serve every union, so these are refused:**

- **a variant implementing the trait more than once** (T3097, as in 0046);
- **a variant boxed as its representation** (T3086):
  - an enum, or a distinct implementing the trait itself. The call would reach the
    integer's or the backing's impl;
  - an array of an enum or a distinct. It takes the representation's array type,
    so its member would fill the vtable row of `u8[]` and answer for every `u8[]`.

  T3086 already refused an enum for interpolation. It now covers every trait
  dispatch, and a distinct with a `Display` of its own. A distinct without one
  renders through its backing's anyway, and is accepted;
- **a member that a tag cannot serve** (the new T3098):
  - a member taking another `Self` (`compare`, `Add<Self>`): the other operand may
    hold another variant than the receiver. `Equals` is exempt, because its vtable
    slot already checks the other operand's type (`guard_equals`);
  - a member returning `Self` inside another type (`Self[]`, `[Self, i32]`): one
    impl builds it for its own type, unboxed, unless every variant is a struct;
- **two traits offering the member to every variant** (T3032).

**Some members have no vtable row to name, so a union leaves them to the forms it
had before** (T3008):

- a generic member;
- an `@intrinsic` array member (`ArrayOps.push`), which is an op at its call site;
- a member taken as a value (`f :: u.area`).

**A value of a trait follows the same rules on the operators**, which it reaches
for the first time: `a < b` on two `Comparable` values is T3098. Its method form
(`c.compare(d)`) keeps the typing it had. It is tested as accepted, and it has the
same hazard.

**An array variant gets its impl member built.** An array impl's members are
materialised only for the elements a direct call names (0045). The lowering
resolves the member for every array variant of a union receiver at each virtual
call (`surface_array_variants`, inside `virtual_call`), so its vtable row exists.
Interpolating a union and comparing through `Equals` share that helper.

**The virtual call's result type is the operator's own.** An arithmetic operator
on an erased `T` used to type its virtual call `bool`.

## Consequences

Measured on 2026-10-08, at `a48492bcc`:

- **On 848 programs**, two diagnostics change, both in a fixture or a snippet:
  - `t3086_union_enum_not_interpolable` gets the new message;
  - `ticket_relabel` reports T3098 instead of T3017 on `i32 | string + 1`. It is
    still rejected.
- **The 148 probes are unchanged.**
- **Interpolating a union with an array variant** (`"${u}"` on `Sq | i64[]`) no
  longer misses the vtable.
- **New coverage:**
  - snippet `union_trait_dispatch`, with native parity: method, index, compound
    index, `in`, `!in`, operators, an array variant, a primitive variant;
  - fixtures for T3098 on a union and on an operator over trait values, and for
    T3086 on a call.

Still open:

- **A union holding `null` dispatches only a trait `null` implements.**
  `u.to_string()` on `Sq | null` works; `u.area()` is T3008, and the message does
  not say to narrow.
- **The other readers of "a union implements a trait" disagree with this one.**
  `try_trait_widen`, the T3006 bound check and this dispatch each have their own
  rule:
  - `fn<T: Comparable>` instantiated with `A | B` is not refused (T3098 is never
    consulted), and `a < b` there misbehaves;
  - widening `Sq | Color` to a `Shape` parameter, or passing it to a generic, skips
    T3086;
  - `for x in u` over a union of `Iterator`s is T3088, and `T | Sq` or `Shape | Sq`
    receivers are T3008.
  One predicate, "can a box of this type dispatch this trait instance, and if not
  why", would serve them all.
- **An array as a trait value** still misses the vtable when no direct call
  materialised its element: `has(["a"], "y")` with `c: Contains<string>`. So does a
  union with an array variant widened to a trait parameter. The member would have
  to be built where the vtable is, from every array type boxed anywhere.
- **The method form on a trait value keeps its hazards**: a member taking another
  `Self` (`c.compare(d)`), a `Self` nested in a primitive implementor's result, a
  generic member, a `Self` result keeping the value's rights.
